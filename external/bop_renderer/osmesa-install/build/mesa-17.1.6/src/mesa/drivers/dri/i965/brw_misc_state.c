/*
 Copyright (C) Intel Corp.  2006.  All Rights Reserved.
 Intel funded Tungsten Graphics to
 develop this 3D driver.

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:

 The above copyright notice and this permission notice (including the
 next paragraph) shall be included in all copies or substantial
 portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 **********************************************************************/
 /*
  * Authors:
  *   Keith Whitwell <keithw@vmware.com>
  */



#include "intel_batchbuffer.h"
#include "intel_fbo.h"
#include "intel_mipmap_tree.h"

#include "brw_context.h"
#include "brw_state.h"
#include "brw_defines.h"
#include "compiler/brw_eu_defines.h"

#include "main/framebuffer.h"
#include "main/fbobject.h"
#include "main/glformats.h"

/* Constant single cliprect for framebuffer object or DRI2 drawing */
static void
upload_drawing_rect(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->ctx;
   const struct gl_framebuffer *fb = ctx->DrawBuffer;
   const unsigned int fb_width = _mesa_geometric_width(fb);
   const unsigned int fb_height = _mesa_geometric_height(fb);

   BEGIN_BATCH(4);
   OUT_BATCH(_3DSTATE_DRAWING_RECTANGLE << 16 | (4 - 2));
   OUT_BATCH(0); /* xmin, ymin */
   OUT_BATCH(((fb_width - 1) & 0xffff) | ((fb_height - 1) << 16));
   OUT_BATCH(0);
   ADVANCE_BATCH();
}

const struct brw_tracked_state brw_drawing_rect = {
   .dirty = {
      .mesa = _NEW_BUFFERS,
      .brw = BRW_NEW_BLORP |
             BRW_NEW_CONTEXT,
   },
   .emit = upload_drawing_rect
};

/**
 * Upload pointers to the per-stage state.
 *
 * The state pointers in this packet are all relative to the general state
 * base address set by CMD_STATE_BASE_ADDRESS, which is 0.
 */
static void
upload_pipelined_state_pointers(struct brw_context *brw)
{
   if (brw->gen == 5) {
      /* Need to flush before changing clip max threads for errata. */
      BEGIN_BATCH(1);
      OUT_BATCH(MI_FLUSH);
      ADVANCE_BATCH();
   }

   BEGIN_BATCH(7);
   OUT_BATCH(_3DSTATE_PIPELINED_POINTERS << 16 | (7 - 2));
   OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
	     brw->vs.base.state_offset);
   if (brw->ff_gs.prog_active)
      OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
		brw->ff_gs.state_offset | 1);
   else
      OUT_BATCH(0);
   OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
	     brw->clip.state_offset | 1);
   OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
	     brw->sf.state_offset);
   OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
	     brw->wm.base.state_offset);
   OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
	     brw->cc.state_offset);
   ADVANCE_BATCH();

   brw->ctx.NewDriverState |= BRW_NEW_PSP;
}

static void
upload_psp_urb_cbs(struct brw_context *brw)
{
   upload_pipelined_state_pointers(brw);
   brw_upload_urb_fence(brw);
   brw_upload_cs_urb_state(brw);
}

const struct brw_tracked_state brw_psp_urb_cbs = {
   .dirty = {
      .mesa = 0,
      .brw = BRW_NEW_BATCH |
             BRW_NEW_BLORP |
             BRW_NEW_FF_GS_PROG_DATA |
             BRW_NEW_GEN4_UNIT_STATE |
             BRW_NEW_STATE_BASE_ADDRESS |
             BRW_NEW_URB_FENCE,
   },
   .emit = upload_psp_urb_cbs,
};

uint32_t
brw_depthbuffer_format(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->ctx;
   struct gl_framebuffer *fb = ctx->DrawBuffer;
   struct intel_renderbuffer *drb = intel_get_renderbuffer(fb, BUFFER_DEPTH);
   struct intel_renderbuffer *srb;

   if (!drb &&
       (srb = intel_get_renderbuffer(fb, BUFFER_STENCIL)) &&
       !srb->mt->stencil_mt &&
       (intel_rb_format(srb) == MESA_FORMAT_Z24_UNORM_S8_UINT ||
	intel_rb_format(srb) == MESA_FORMAT_Z32_FLOAT_S8X24_UINT)) {
      drb = srb;
   }

   if (!drb)
      return BRW_DEPTHFORMAT_D32_FLOAT;

   return brw_depth_format(brw, drb->mt->format);
}

/**
 * Returns the mask of how many bits of x and y must be handled through the
 * depthbuffer's draw offset x and y fields.
 *
 * The draw offset x/y field of the depthbuffer packet is unfortunately shared
 * between the depth, hiz, and stencil buffers.  Because it can be hard to get
 * all 3 to agree on this value, we want to do as much drawing offset
 * adjustment as possible by moving the base offset of the 3 buffers, which is
 * restricted to tile boundaries.
 *
 * For each buffer, the remainder must be applied through the x/y draw offset.
 * This returns the worst-case mask of the low bits that have to go into the
 * packet.  If the 3 buffers don't agree on the drawing offset ANDed with this
 * mask, then we're in trouble.
 */
static void
brw_get_depthstencil_tile_masks(struct intel_mipmap_tree *depth_mt,
                                uint32_t depth_level,
                                uint32_t depth_layer,
                                struct intel_mipmap_tree *stencil_mt,
                                uint32_t *out_tile_mask_x,
                                uint32_t *out_tile_mask_y)
{
   uint32_t tile_mask_x = 0, tile_mask_y = 0;

   if (depth_mt) {
      intel_get_tile_masks(depth_mt->tiling,
                           depth_mt->cpp,
                           &tile_mask_x, &tile_mask_y);
      assert(!intel_miptree_level_has_hiz(depth_mt, depth_level));
   }

   if (stencil_mt) {
      if (stencil_mt->stencil_mt)
	 stencil_mt = stencil_mt->stencil_mt;

      if (stencil_mt->format == MESA_FORMAT_S_UINT8) {
         /* Separate stencil buffer uses 64x64 tiles. */
         tile_mask_x |= 63;
         tile_mask_y |= 63;
      } else {
         uint32_t stencil_tile_mask_x, stencil_tile_mask_y;
         intel_get_tile_masks(stencil_mt->tiling,
                              stencil_mt->cpp,
                              &stencil_tile_mask_x,
                              &stencil_tile_mask_y);

         tile_mask_x |= stencil_tile_mask_x;
         tile_mask_y |= stencil_tile_mask_y;
      }
   }

   *out_tile_mask_x = tile_mask_x;
   *out_tile_mask_y = tile_mask_y;
}

static struct intel_mipmap_tree *
get_stencil_miptree(struct intel_renderbuffer *irb)
{
   if (!irb)
      return NULL;
   if (irb->mt->stencil_mt)
      return irb->mt->stencil_mt;
   return irb->mt;
}

void
brw_workaround_depthstencil_alignment(struct brw_context *brw,
                                      GLbitfield clear_mask)
{
   struct gl_context *ctx = &brw->ctx;
   struct gl_framebuffer *fb = ctx->DrawBuffer;
   bool rebase_depth = false;
   bool rebase_stencil = false;
   struct intel_renderbuffer *depth_irb = intel_get_renderbuffer(fb, BUFFER_DEPTH);
   struct intel_renderbuffer *stencil_irb = intel_get_renderbuffer(fb, BUFFER_STENCIL);
   struct intel_mipmap_tree *depth_mt = NULL;
   struct intel_mipmap_tree *stencil_mt = get_stencil_miptree(stencil_irb);
   uint32_t tile_x = 0, tile_y = 0, stencil_tile_x = 0, stencil_tile_y = 0;
   uint32_t stencil_draw_x = 0, stencil_draw_y = 0;
   bool invalidate_depth = clear_mask & BUFFER_BIT_DEPTH;
   bool invalidate_stencil = clear_mask & BUFFER_BIT_STENCIL;

   if (depth_irb)
      depth_mt = depth_irb->mt;

   /* Initialize brw->depthstencil to 'nop' workaround state.
    */
   brw->depthstencil.tile_x = 0;
   brw->depthstencil.tile_y = 0;
   brw->depthstencil.depth_offset = 0;
   brw->depthstencil.stencil_offset = 0;
   brw->depthstencil.hiz_offset = 0;
   brw->depthstencil.depth_mt = NULL;
   brw->depthstencil.stencil_mt = NULL;
   if (depth_irb)
      brw->depthstencil.depth_mt = depth_mt;
   if (stencil_irb)
      brw->depthstencil.stencil_mt = get_stencil_miptree(stencil_irb);

   /* Gen6+ doesn't require the workarounds, since we always program the
    * surface state at the start of the whole surface.
    */
   if (brw->gen >= 6)
      return;

   /* Check if depth buffer is in depth/stencil format.  If so, then it's only
    * safe to invalidate it if we're also clearing stencil, and both depth_irb
    * and stencil_irb point to the same miptree.
    *
    * Note: it's not sufficient to check for the case where
    * _mesa_get_format_base_format(depth_mt->format) == GL_DEPTH_STENCIL,
    * because this fails to catch depth/stencil buffers on hardware that uses
    * separate stencil.  To catch that case, we check whether
    * depth_mt->stencil_mt is non-NULL.
    */
   if (depth_irb && invalidate_depth &&
       (_mesa_get_format_base_format(depth_mt->format) == GL_DEPTH_STENCIL ||
        depth_mt->stencil_mt)) {
      invalidate_depth = invalidate_stencil && depth_irb && stencil_irb
         && depth_irb->mt == stencil_irb->mt;
   }

   uint32_t tile_mask_x, tile_mask_y;
   brw_get_depthstencil_tile_masks(depth_mt,
                                   depth_mt ? depth_irb->mt_level : 0,
                                   depth_mt ? depth_irb->mt_layer : 0,
                                   stencil_mt,
                                   &tile_mask_x, &tile_mask_y);

   if (depth_irb) {
      tile_x = depth_irb->draw_x & tile_mask_x;
      tile_y = depth_irb->draw_y & tile_mask_y;

      /* According to the Sandy Bridge PRM, volume 2 part 1, pp326-327
       * (3DSTATE_DEPTH_BUFFER dw5), in the documentation for "Depth
       * Coordinate Offset X/Y":
       *
       *   "The 3 LSBs of both offsets must be zero to ensure correct
       *   alignment"
       */
      if (tile_x & 7 || tile_y & 7)
         rebase_depth = true;

      /* We didn't even have intra-tile offsets before g45. */
      if (!brw->has_surface_tile_offset) {
         if (tile_x || tile_y)
            rebase_depth = true;
      }

      if (rebase_depth) {
         perf_debug("HW workaround: blitting depth level %d to a temporary "
                    "to fix alignment (depth tile offset %d,%d)\n",
                    depth_irb->mt_level, tile_x, tile_y);
         intel_renderbuffer_move_to_temp(brw, depth_irb, invalidate_depth);
         /* In the case of stencil_irb being the same packed depth/stencil
          * texture but not the same rb, make it point at our rebased mt, too.
          */
         if (stencil_irb &&
             stencil_irb != depth_irb &&
             stencil_irb->mt == depth_mt) {
            intel_miptree_reference(&stencil_irb->mt, depth_irb->mt);
            intel_renderbuffer_set_draw_offset(stencil_irb);
         }

         stencil_mt = get_stencil_miptree(stencil_irb);

         tile_x = depth_irb->draw_x & tile_mask_x;
         tile_y = depth_irb->draw_y & tile_mask_y;
      }

      if (stencil_irb) {
         stencil_mt = get_stencil_miptree(stencil_irb);
         intel_miptree_get_image_offset(stencil_mt,
                                        stencil_irb->mt_level,
                                        stencil_irb->mt_layer,
                                        &stencil_draw_x, &stencil_draw_y);
         int stencil_tile_x = stencil_draw_x & tile_mask_x;
         int stencil_tile_y = stencil_draw_y & tile_mask_y;

         /* If stencil doesn't match depth, then we'll need to rebase stencil
          * as well.  (if we hadn't decided to rebase stencil before, the
          * post-stencil depth test will also rebase depth to try to match it
          * up).
          */
         if (tile_x != stencil_tile_x ||
             tile_y != stencil_tile_y) {
            rebase_stencil = true;
         }
      }
   }

   /* If we have (just) stencil, check it for ignored low bits as well */
   if (stencil_irb) {
      intel_miptree_get_image_offset(stencil_mt,
                                     stencil_irb->mt_level,
                                     stencil_irb->mt_layer,
                                     &stencil_draw_x, &stencil_draw_y);
      stencil_tile_x = stencil_draw_x & tile_mask_x;
      stencil_tile_y = stencil_draw_y & tile_mask_y;

      if (stencil_tile_x & 7 || stencil_tile_y & 7)
         rebase_stencil = true;

      if (!brw->has_surface_tile_offset) {
         if (stencil_tile_x || stencil_tile_y)
            rebase_stencil = true;
      }
   }

   if (rebase_stencil) {
      perf_debug("HW workaround: blitting stencil level %d to a temporary "
                 "to fix alignment (stencil tile offset %d,%d)\n",
                 stencil_irb->mt_level, stencil_tile_x, stencil_tile_y);

      intel_renderbuffer_move_to_temp(brw, stencil_irb, invalidate_stencil);
      stencil_mt = get_stencil_miptree(stencil_irb);

      intel_miptree_get_image_offset(stencil_mt,
                                     stencil_irb->mt_level,
                                     stencil_irb->mt_layer,
                                     &stencil_draw_x, &stencil_draw_y);
      stencil_tile_x = stencil_draw_x & tile_mask_x;
      stencil_tile_y = stencil_draw_y & tile_mask_y;

      if (depth_irb && depth_irb->mt == stencil_irb->mt) {
         intel_miptree_reference(&depth_irb->mt, stencil_irb->mt);
         intel_renderbuffer_set_draw_offset(depth_irb);
      } else if (depth_irb && !rebase_depth) {
         if (tile_x != stencil_tile_x ||
             tile_y != stencil_tile_y) {
            perf_debug("HW workaround: blitting depth level %d to a temporary "
                       "to match stencil level %d alignment (depth tile offset "
                       "%d,%d, stencil offset %d,%d)\n",
                       depth_irb->mt_level,
                       stencil_irb->mt_level,
                       tile_x, tile_y,
                       stencil_tile_x, stencil_tile_y);

            intel_renderbuffer_move_to_temp(brw, depth_irb, invalidate_depth);

            tile_x = depth_irb->draw_x & tile_mask_x;
            tile_y = depth_irb->draw_y & tile_mask_y;

            if (stencil_irb && stencil_irb->mt == depth_mt) {
               intel_miptree_reference(&stencil_irb->mt, depth_irb->mt);
               intel_renderbuffer_set_draw_offset(stencil_irb);
            }

            WARN_ONCE(stencil_tile_x != tile_x ||
                      stencil_tile_y != tile_y,
                      "Rebased stencil tile offset (%d,%d) doesn't match depth "
                      "tile offset (%d,%d).\n",
                      stencil_tile_x, stencil_tile_y,
                      tile_x, tile_y);
         }
      }
   }

   if (!depth_irb) {
      tile_x = stencil_tile_x;
      tile_y = stencil_tile_y;
   }

   /* While we just tried to get everything aligned, we may have failed to do
    * so in the case of rendering to array or 3D textures, where nonzero faces
    * will still have an offset post-rebase.  At least give an informative
    * warning.
    */
   WARN_ONCE((tile_x & 7) || (tile_y & 7),
             "Depth/stencil buffer needs alignment to 8-pixel boundaries.\n"
             "Truncating offset, bad rendering may occur.\n");
   tile_x &= ~7;
   tile_y &= ~7;

   /* Now, after rebasing, save off the new dephtstencil state so the hardware
    * packets can just dereference that without re-calculating tile offsets.
    */
   brw->depthstencil.tile_x = tile_x;
   brw->depthstencil.tile_y = tile_y;
   if (depth_irb) {
      depth_mt = depth_irb->mt;
      brw->depthstencil.depth_mt = depth_mt;
      brw->depthstencil.depth_offset =
         intel_miptree_get_aligned_offset(depth_mt,
                                          depth_irb->draw_x & ~tile_mask_x,
                                          depth_irb->draw_y & ~tile_mask_y);
      if (intel_renderbuffer_has_hiz(depth_irb)) {
         brw->depthstencil.hiz_offset =
            intel_miptree_get_aligned_offset(depth_mt,
                                             depth_irb->draw_x & ~tile_mask_x,
                                             (depth_irb->draw_y & ~tile_mask_y) / 2);
      }
   }
   if (stencil_irb) {
      stencil_mt = get_stencil_miptree(stencil_irb);

      brw->depthstencil.stencil_mt = stencil_mt;
      if (stencil_mt->format == MESA_FORMAT_S_UINT8) {
         /* Note: we can't compute the stencil offset using
          * intel_region_get_aligned_offset(), because stencil_region claims
          * that the region is untiled even though it's W tiled.
          */
         brw->depthstencil.stencil_offset =
            (stencil_draw_y & ~tile_mask_y) * stencil_mt->pitch +
            (stencil_draw_x & ~tile_mask_x) * 64;
      } else if (!depth_irb) {
         brw->depthstencil.depth_offset =
            intel_miptree_get_aligned_offset(
               stencil_mt,
               stencil_irb->draw_x & ~tile_mask_x,
               stencil_irb->draw_y & ~tile_mask_y);
      }
   }
}

void
brw_emit_depthbuffer(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->ctx;
   struct gl_framebuffer *fb = ctx->DrawBuffer;
   /* _NEW_BUFFERS */
   struct intel_renderbuffer *depth_irb = intel_get_renderbuffer(fb, BUFFER_DEPTH);
   struct intel_renderbuffer *stencil_irb = intel_get_renderbuffer(fb, BUFFER_STENCIL);
   struct intel_mipmap_tree *depth_mt = brw->depthstencil.depth_mt;
   struct intel_mipmap_tree *stencil_mt = brw->depthstencil.stencil_mt;
   uint32_t tile_x = brw->depthstencil.tile_x;
   uint32_t tile_y = brw->depthstencil.tile_y;
   bool hiz = depth_irb && intel_renderbuffer_has_hiz(depth_irb);
   bool separate_stencil = false;
   uint32_t depth_surface_type = BRW_SURFACE_NULL;
   uint32_t depthbuffer_format = BRW_DEPTHFORMAT_D32_FLOAT;
   uint32_t depth_offset = 0;
   uint32_t width = 1, height = 1;

   if (stencil_mt) {
      separate_stencil = stencil_mt->format == MESA_FORMAT_S_UINT8;

      /* Gen7 supports only separate stencil */
      assert(separate_stencil || brw->gen < 7);
   }

   /* If there's a packed depth/stencil bound to stencil only, we need to
    * emit the packed depth/stencil buffer packet.
    */
   if (!depth_irb && stencil_irb && !separate_stencil) {
      depth_irb = stencil_irb;
      depth_mt = stencil_mt;
   }

   if (depth_irb && depth_mt) {
      /* When 3DSTATE_DEPTH_BUFFER.Separate_Stencil_Enable is set, then
       * 3DSTATE_DEPTH_BUFFER.Surface_Format is not permitted to be a packed
       * depthstencil format.
       *
       * Gens prior to 7 require that HiZ_Enable and Separate_Stencil_Enable be
       * set to the same value. Gens after 7 implicitly always set
       * Separate_Stencil_Enable; software cannot disable it.
       */
      if ((brw->gen < 7 && hiz) || brw->gen >= 7) {
         assert(!_mesa_is_format_packed_depth_stencil(depth_mt->format));
      }

      /* Prior to Gen7, if using separate stencil, hiz must be enabled. */
      assert(brw->gen >= 7 || !separate_stencil || hiz);

      assert(brw->gen < 6 || depth_mt->tiling == I915_TILING_Y);
      assert(!hiz || depth_mt->tiling == I915_TILING_Y);

      depthbuffer_format = brw_depthbuffer_format(brw);
      depth_surface_type = BRW_SURFACE_2D;
      depth_offset = brw->depthstencil.depth_offset;
      width = depth_irb->Base.Base.Width;
      height = depth_irb->Base.Base.Height;
   } else if (separate_stencil) {
      /*
       * There exists a separate stencil buffer but no depth buffer.
       *
       * The stencil buffer inherits most of its fields from
       * 3DSTATE_DEPTH_BUFFER: namely the tile walk, surface type, width, and
       * height.
       *
       * The tiled bit must be set. From the Sandybridge PRM, Volume 2, Part 1,
       * Section 7.5.5.1.1 3DSTATE_DEPTH_BUFFER, Bit 1.27 Tiled Surface:
       *     [DevGT+]: This field must be set to TRUE.
       */
      assert(brw->has_separate_stencil);

      depth_surface_type = BRW_SURFACE_2D;
      width = stencil_irb->Base.Base.Width;
      height = stencil_irb->Base.Base.Height;
   }

   if (depth_mt)
      brw_render_cache_set_check_flush(brw, depth_mt->bo);
   if (stencil_mt)
      brw_render_cache_set_check_flush(brw, stencil_mt->bo);

   brw->vtbl.emit_depth_stencil_hiz(brw, depth_mt, depth_offset,
                                    depthbuffer_format, depth_surface_type,
                                    stencil_mt, hiz, separate_stencil,
                                    width, height, tile_x, tile_y);
}

void
brw_emit_depth_stencil_hiz(struct brw_context *brw,
                           struct intel_mipmap_tree *depth_mt,
                           uint32_t depth_offset, uint32_t depthbuffer_format,
                           uint32_t depth_surface_type,
                           struct intel_mipmap_tree *stencil_mt,
                           bool hiz, bool separate_stencil,
                           uint32_t width, uint32_t height,
                           uint32_t tile_x, uint32_t tile_y)
{
   /* Enable the hiz bit if we're doing separate stencil, because it and the
    * separate stencil bit must have the same value. From Section 2.11.5.6.1.1
    * 3DSTATE_DEPTH_BUFFER, Bit 1.21 "Separate Stencil Enable":
    *     [DevIL]: If this field is enabled, Hierarchical Depth Buffer
    *     Enable must also be enabled.
    *
    *     [DevGT]: This field must be set to the same value (enabled or
    *     disabled) as Hierarchical Depth Buffer Enable
    */
   bool enable_hiz_ss = hiz || separate_stencil;


   /* 3DSTATE_DEPTH_BUFFER, 3DSTATE_STENCIL_BUFFER are both
    * non-pipelined state that will need the PIPE_CONTROL workaround.
    */
   if (brw->gen == 6) {
      brw_emit_depth_stall_flushes(brw);
   }

   unsigned int len;
   if (brw->gen >= 6)
      len = 7;
   else if (brw->is_g4x || brw->gen == 5)
      len = 6;
   else
      len = 5;

   BEGIN_BATCH(len);
   OUT_BATCH(_3DSTATE_DEPTH_BUFFER << 16 | (len - 2));
   OUT_BATCH((depth_mt ? depth_mt->pitch - 1 : 0) |
             (depthbuffer_format << 18) |
             ((enable_hiz_ss ? 1 : 0) << 21) | /* separate stencil enable */
             ((enable_hiz_ss ? 1 : 0) << 22) | /* hiz enable */
             (BRW_TILEWALK_YMAJOR << 26) |
             ((depth_mt ? depth_mt->tiling != I915_TILING_NONE : 1)
              << 27) |
             (depth_surface_type << 29));

   if (depth_mt) {
      OUT_RELOC(depth_mt->bo,
		I915_GEM_DOMAIN_RENDER, I915_GEM_DOMAIN_RENDER,
		depth_offset);
   } else {
      OUT_BATCH(0);
   }

   OUT_BATCH(((width + tile_x - 1) << 6) |
             ((height + tile_y - 1) << 19));
   OUT_BATCH(0);

   if (brw->is_g4x || brw->gen >= 5)
      OUT_BATCH(tile_x | (tile_y << 16));
   else
      assert(tile_x == 0 && tile_y == 0);

   if (brw->gen >= 6)
      OUT_BATCH(0);

   ADVANCE_BATCH();

   if (hiz || separate_stencil) {
      /*
       * In the 3DSTATE_DEPTH_BUFFER batch emitted above, the 'separate
       * stencil enable' and 'hiz enable' bits were set. Therefore we must
       * emit 3DSTATE_HIER_DEPTH_BUFFER and 3DSTATE_STENCIL_BUFFER. Even if
       * there is no stencil buffer, 3DSTATE_STENCIL_BUFFER must be emitted;
       * failure to do so causes hangs on gen5 and a stall on gen6.
       */

      /* Emit hiz buffer. */
      if (hiz) {
         assert(depth_mt);
	 BEGIN_BATCH(3);
	 OUT_BATCH((_3DSTATE_HIER_DEPTH_BUFFER << 16) | (3 - 2));
	 OUT_BATCH(depth_mt->hiz_buf->aux_base.pitch - 1);
	 OUT_RELOC(depth_mt->hiz_buf->aux_base.bo,
		   I915_GEM_DOMAIN_RENDER, I915_GEM_DOMAIN_RENDER,
		   brw->depthstencil.hiz_offset);
	 ADVANCE_BATCH();
      } else {
	 BEGIN_BATCH(3);
	 OUT_BATCH((_3DSTATE_HIER_DEPTH_BUFFER << 16) | (3 - 2));
	 OUT_BATCH(0);
	 OUT_BATCH(0);
	 ADVANCE_BATCH();
      }

      /* Emit stencil buffer. */
      if (separate_stencil) {
	 BEGIN_BATCH(3);
	 OUT_BATCH((_3DSTATE_STENCIL_BUFFER << 16) | (3 - 2));
         /* The stencil buffer has quirky pitch requirements.  From Vol 2a,
          * 11.5.6.2.1 3DSTATE_STENCIL_BUFFER, field "Surface Pitch":
          *    The pitch must be set to 2x the value computed based on width, as
          *    the stencil buffer is stored with two rows interleaved.
          */
	 OUT_BATCH(2 * stencil_mt->pitch - 1);
	 OUT_RELOC(stencil_mt->bo,
		   I915_GEM_DOMAIN_RENDER, I915_GEM_DOMAIN_RENDER,
		   brw->depthstencil.stencil_offset);
	 ADVANCE_BATCH();
      } else {
	 BEGIN_BATCH(3);
	 OUT_BATCH((_3DSTATE_STENCIL_BUFFER << 16) | (3 - 2));
	 OUT_BATCH(0);
	 OUT_BATCH(0);
	 ADVANCE_BATCH();
      }
   }

   /*
    * On Gen >= 6, emit clear params for safety. If using hiz, then clear
    * params must be emitted.
    *
    * From Section 2.11.5.6.4.1 3DSTATE_CLEAR_PARAMS:
    *     3DSTATE_CLEAR_PARAMS packet must follow the DEPTH_BUFFER_STATE packet
    *     when HiZ is enabled and the DEPTH_BUFFER_STATE changes.
    */
   if (brw->gen >= 6 || hiz) {
      BEGIN_BATCH(2);
      OUT_BATCH(_3DSTATE_CLEAR_PARAMS << 16 |
		GEN5_DEPTH_CLEAR_VALID |
		(2 - 2));
      OUT_BATCH(depth_mt ? depth_mt->depth_clear_value : 0);
      ADVANCE_BATCH();
   }
}

const struct brw_tracked_state brw_depthbuffer = {
   .dirty = {
      .mesa = _NEW_BUFFERS,
      .brw = BRW_NEW_BATCH |
             BRW_NEW_BLORP,
   },
   .emit = brw_emit_depthbuffer,
};

/**
 * Polygon stipple packet
 */
static void
upload_polygon_stipple(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->ctx;
   GLuint i;

   /* _NEW_POLYGON */
   if (!ctx->Polygon.StippleFlag)
      return;

   BEGIN_BATCH(33);
   OUT_BATCH(_3DSTATE_POLY_STIPPLE_PATTERN << 16 | (33 - 2));

   /* Polygon stipple is provided in OpenGL order, i.e. bottom
    * row first.  If we're rendering to a window (i.e. the
    * default frame buffer object, 0), then we need to invert
    * it to match our pixel layout.  But if we're rendering
    * to a FBO (i.e. any named frame buffer object), we *don't*
    * need to invert - we already match the layout.
    */
   if (_mesa_is_winsys_fbo(ctx->DrawBuffer)) {
      for (i = 0; i < 32; i++)
	  OUT_BATCH(ctx->PolygonStipple[31 - i]); /* invert */
   } else {
      for (i = 0; i < 32; i++)
	 OUT_BATCH(ctx->PolygonStipple[i]);
   }
   ADVANCE_BATCH();
}

const struct brw_tracked_state brw_polygon_stipple = {
   .dirty = {
      .mesa = _NEW_POLYGON |
              _NEW_POLYGONSTIPPLE,
      .brw = BRW_NEW_CONTEXT,
   },
   .emit = upload_polygon_stipple
};

/**
 * Polygon stipple offset packet
 */
static void
upload_polygon_stipple_offset(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->ctx;

   /* _NEW_POLYGON */
   if (!ctx->Polygon.StippleFlag)
      return;

   BEGIN_BATCH(2);
   OUT_BATCH(_3DSTATE_POLY_STIPPLE_OFFSET << 16 | (2-2));

   /* _NEW_BUFFERS
    *
    * If we're drawing to a system window we have to invert the Y axis
    * in order to match the OpenGL pixel coordinate system, and our
    * offset must be matched to the window position.  If we're drawing
    * to a user-created FBO then our native pixel coordinate system
    * works just fine, and there's no window system to worry about.
    */
   if (_mesa_is_winsys_fbo(ctx->DrawBuffer))
      OUT_BATCH((32 - (_mesa_geometric_height(ctx->DrawBuffer) & 31)) & 31);
   else
      OUT_BATCH(0);
   ADVANCE_BATCH();
}

const struct brw_tracked_state brw_polygon_stipple_offset = {
   .dirty = {
      .mesa = _NEW_BUFFERS |
              _NEW_POLYGON,
      .brw = BRW_NEW_CONTEXT,
   },
   .emit = upload_polygon_stipple_offset
};

/**
 * Line stipple packet
 */
static void
upload_line_stipple(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->ctx;
   GLfloat tmp;
   GLint tmpi;

   if (!ctx->Line.StippleFlag)
      return;

   BEGIN_BATCH(3);
   OUT_BATCH(_3DSTATE_LINE_STIPPLE_PATTERN << 16 | (3 - 2));
   OUT_BATCH(ctx->Line.StipplePattern);

   if (brw->gen >= 7) {
      /* in U1.16 */
      tmp = 1.0f / ctx->Line.StippleFactor;
      tmpi = tmp * (1<<16);
      OUT_BATCH(tmpi << 15 | ctx->Line.StippleFactor);
   } else {
      /* in U1.13 */
      tmp = 1.0f / ctx->Line.StippleFactor;
      tmpi = tmp * (1<<13);
      OUT_BATCH(tmpi << 16 | ctx->Line.StippleFactor);
   }

   ADVANCE_BATCH();
}

const struct brw_tracked_state brw_line_stipple = {
   .dirty = {
      .mesa = _NEW_LINE,
      .brw = BRW_NEW_CONTEXT,
   },
   .emit = upload_line_stipple
};

void
brw_emit_select_pipeline(struct brw_context *brw, enum brw_pipeline pipeline)
{
   const bool is_965 = brw->gen == 4 && !brw->is_g4x;
   const uint32_t _3DSTATE_PIPELINE_SELECT =
      is_965 ? CMD_PIPELINE_SELECT_965 : CMD_PIPELINE_SELECT_GM45;

   if (brw->gen >= 8 && brw->gen < 10) {
      /* From the Broadwell PRM, Volume 2a: Instructions, PIPELINE_SELECT:
       *
       *   Software must clear the COLOR_CALC_STATE Valid field in
       *   3DSTATE_CC_STATE_POINTERS command prior to send a PIPELINE_SELECT
       *   with Pipeline Select set to GPGPU.
       *
       * The internal hardware docs recommend the same workaround for Gen9
       * hardware too.
       */
      if (pipeline == BRW_COMPUTE_PIPELINE) {
         BEGIN_BATCH(2);
         OUT_BATCH(_3DSTATE_CC_STATE_POINTERS << 16 | (2 - 2));
         OUT_BATCH(0);
         ADVANCE_BATCH();

         brw->ctx.NewDriverState |= BRW_NEW_CC_STATE;
      }
   }

   if (brw->gen >= 6) {
      /* From "BXML ?? GT ?? MI ?? vol1a GPU Overview ?? [Instruction]
       * PIPELINE_SELECT [DevBWR+]":
       *
       *   Project: DEVSNB+
       *
       *   Software must ensure all the write caches are flushed through a
       *   stalling PIPE_CONTROL command followed by another PIPE_CONTROL
       *   command to invalidate read only caches prior to programming
       *   MI_PIPELINE_SELECT command to change the Pipeline Select Mode.
       */
      const unsigned dc_flush =
         brw->gen >= 7 ? PIPE_CONTROL_DATA_CACHE_FLUSH : 0;

      brw_emit_pipe_control_flush(brw,
                                  PIPE_CONTROL_RENDER_TARGET_FLUSH |
                                  PIPE_CONTROL_DEPTH_CACHE_FLUSH |
                                  dc_flush |
                                  PIPE_CONTROL_NO_WRITE |
                                  PIPE_CONTROL_CS_STALL);

      brw_emit_pipe_control_flush(brw,
                                  PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE |
                                  PIPE_CONTROL_CONST_CACHE_INVALIDATE |
                                  PIPE_CONTROL_STATE_CACHE_INVALIDATE |
                                  PIPE_CONTROL_INSTRUCTION_INVALIDATE |
                                  PIPE_CONTROL_NO_WRITE);

   } else {
      /* From "BXML ?? GT ?? MI ?? vol1a GPU Overview ?? [Instruction]
       * PIPELINE_SELECT [DevBWR+]":
       *
       *   Project: PRE-DEVSNB
       *
       *   Software must ensure the current pipeline is flushed via an
       *   MI_FLUSH or PIPE_CONTROL prior to the execution of PIPELINE_SELECT.
       */
      BEGIN_BATCH(1);
      OUT_BATCH(MI_FLUSH);
      ADVANCE_BATCH();
   }

   /* Select the pipeline */
   BEGIN_BATCH(1);
   OUT_BATCH(_3DSTATE_PIPELINE_SELECT << 16 |
             (brw->gen >= 9 ? (3 << 8) : 0) |
             (pipeline == BRW_COMPUTE_PIPELINE ? 2 : 0));
   ADVANCE_BATCH();

   if (brw->gen == 7 && !brw->is_haswell &&
       pipeline == BRW_RENDER_PIPELINE) {
      /* From "BXML ?? GT ?? MI ?? vol1a GPU Overview ?? [Instruction]
       * PIPELINE_SELECT [DevBWR+]":
       *
       *   Project: DEVIVB, DEVHSW:GT3:A0
       *
       *   Software must send a pipe_control with a CS stall and a post sync
       *   operation and then a dummy DRAW after every MI_SET_CONTEXT and
       *   after any PIPELINE_SELECT that is enabling 3D mode.
       */
      gen7_emit_cs_stall_flush(brw);

      BEGIN_BATCH(7);
      OUT_BATCH(CMD_3D_PRIM << 16 | (7 - 2));
      OUT_BATCH(_3DPRIM_POINTLIST);
      OUT_BATCH(0);
      OUT_BATCH(0);
      OUT_BATCH(0);
      OUT_BATCH(0);
      OUT_BATCH(0);
      ADVANCE_BATCH();
   }
}

/**
 * Misc invariant state packets
 */
void
brw_upload_invariant_state(struct brw_context *brw)
{
   const bool is_965 = brw->gen == 4 && !brw->is_g4x;

   brw_emit_select_pipeline(brw, BRW_RENDER_PIPELINE);
   brw->last_pipeline = BRW_RENDER_PIPELINE;

   if (brw->gen >= 8) {
      BEGIN_BATCH(3);
      OUT_BATCH(CMD_STATE_SIP << 16 | (3 - 2));
      OUT_BATCH(0);
      OUT_BATCH(0);
      ADVANCE_BATCH();
   } else {
      BEGIN_BATCH(2);
      OUT_BATCH(CMD_STATE_SIP << 16 | (2 - 2));
      OUT_BATCH(0);
      ADVANCE_BATCH();
   }

   /* Original Gen4 doesn't have 3DSTATE_AA_LINE_PARAMETERS. */
   if (!is_965) {
      BEGIN_BATCH(3);
      OUT_BATCH(_3DSTATE_AA_LINE_PARAMETERS << 16 | (3 - 2));
      /* use legacy aa line coverage computation */
      OUT_BATCH(0);
      OUT_BATCH(0);
      ADVANCE_BATCH();
   }

   const uint32_t _3DSTATE_VF_STATISTICS =
      is_965 ? GEN4_3DSTATE_VF_STATISTICS : GM45_3DSTATE_VF_STATISTICS;
   BEGIN_BATCH(1);
   OUT_BATCH(_3DSTATE_VF_STATISTICS << 16 | 1);
   ADVANCE_BATCH();
}

const struct brw_tracked_state brw_invariant_state = {
   .dirty = {
      .mesa = 0,
      .brw = BRW_NEW_BLORP |
             BRW_NEW_CONTEXT,
   },
   .emit = brw_upload_invariant_state
};

/**
 * Define the base addresses which some state is referenced from.
 *
 * This allows us to avoid having to emit relocations for the objects,
 * and is actually required for binding table pointers on gen6.
 *
 * Surface state base address covers binding table pointers and
 * surface state objects, but not the surfaces that the surface state
 * objects point to.
 */
void
brw_upload_state_base_address(struct brw_context *brw)
{
   if (brw->batch.state_base_address_emitted)
      return;

   /* FINISHME: According to section 3.6.1 "STATE_BASE_ADDRESS" of
    * vol1a of the G45 PRM, MI_FLUSH with the ISC invalidate should be
    * programmed prior to STATE_BASE_ADDRESS.
    *
    * However, given that the instruction SBA (general state base
    * address) on this chipset is always set to 0 across X and GL,
    * maybe this isn't required for us in particular.
    */

   if (brw->gen >= 6) {
      const unsigned dc_flush =
         brw->gen >= 7 ? PIPE_CONTROL_DATA_CACHE_FLUSH : 0;

      /* Emit a render target cache flush.
       *
       * This isn't documented anywhere in the PRM.  However, it seems to be
       * necessary prior to changing the surface state base adress.  We've
       * seen issues in Vulkan where we get GPU hangs when using multi-level
       * command buffers which clear depth, reset state base address, and then
       * go render stuff.
       *
       * Normally, in GL, we would trust the kernel to do sufficient stalls
       * and flushes prior to executing our batch.  However, it doesn't seem
       * as if the kernel's flushing is always sufficient and we don't want to
       * rely on it.
       *
       * We make this an end-of-pipe sync instead of a normal flush because we
       * do not know the current status of the GPU.  On Haswell at least,
       * having a fast-clear operation in flight at the same time as a normal
       * rendering operation can cause hangs.  Since the kernel's flushing is
       * insufficient, we need to ensure that any rendering operations from
       * other processes are definitely complete before we try to do our own
       * rendering.  It's a bit of a big hammer but it appears to work.
       */
      brw_emit_end_of_pipe_sync(brw,
                                PIPE_CONTROL_RENDER_TARGET_FLUSH |
                                PIPE_CONTROL_DEPTH_CACHE_FLUSH |
                                dc_flush);
   }

   if (brw->gen >= 8) {
      uint32_t mocs_wb = brw->gen >= 9 ? SKL_MOCS_WB : BDW_MOCS_WB;
      int pkt_len = brw->gen >= 9 ? 19 : 16;

      BEGIN_BATCH(pkt_len);
      OUT_BATCH(CMD_STATE_BASE_ADDRESS << 16 | (pkt_len - 2));
      /* General state base address: stateless DP read/write requests */
      OUT_BATCH(mocs_wb << 4 | 1);
      OUT_BATCH(0);
      OUT_BATCH(mocs_wb << 16);
      /* Surface state base address: */
      OUT_RELOC64(brw->batch.bo, I915_GEM_DOMAIN_SAMPLER, 0,
                  mocs_wb << 4 | 1);
      /* Dynamic state base address: */
      OUT_RELOC64(brw->batch.bo,
                  I915_GEM_DOMAIN_RENDER | I915_GEM_DOMAIN_INSTRUCTION, 0,
                  mocs_wb << 4 | 1);
      /* Indirect object base address: MEDIA_OBJECT data */
      OUT_BATCH(mocs_wb << 4 | 1);
      OUT_BATCH(0);
      /* Instruction base address: shader kernels (incl. SIP) */
      OUT_RELOC64(brw->cache.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
                  mocs_wb << 4 | 1);

      /* General state buffer size */
      OUT_BATCH(0xfffff001);
      /* Dynamic state buffer size */
      OUT_BATCH(ALIGN(brw->batch.bo->size, 4096) | 1);
      /* Indirect object upper bound */
      OUT_BATCH(0xfffff001);
      /* Instruction access upper bound */
      OUT_BATCH(ALIGN(brw->cache.bo->size, 4096) | 1);
      if (brw->gen >= 9) {
         OUT_BATCH(1);
         OUT_BATCH(0);
         OUT_BATCH(0);
      }
      ADVANCE_BATCH();
   } else if (brw->gen >= 6) {
      uint8_t mocs = brw->gen == 7 ? GEN7_MOCS_L3 : 0;

       BEGIN_BATCH(10);
       OUT_BATCH(CMD_STATE_BASE_ADDRESS << 16 | (10 - 2));
       OUT_BATCH(mocs << 8 | /* General State Memory Object Control State */
                 mocs << 4 | /* Stateless Data Port Access Memory Object Control State */
                 1); /* General State Base Address Modify Enable */
       /* Surface state base address:
	* BINDING_TABLE_STATE
	* SURFACE_STATE
	*/
       OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_SAMPLER, 0, 1);
        /* Dynamic state base address:
	 * SAMPLER_STATE
	 * SAMPLER_BORDER_COLOR_STATE
	 * CLIP, SF, WM/CC viewport state
	 * COLOR_CALC_STATE
	 * DEPTH_STENCIL_STATE
	 * BLEND_STATE
	 * Push constants (when INSTPM: CONSTANT_BUFFER Address Offset
	 * Disable is clear, which we rely on)
	 */
       OUT_RELOC(brw->batch.bo, (I915_GEM_DOMAIN_RENDER |
				   I915_GEM_DOMAIN_INSTRUCTION), 0, 1);

       OUT_BATCH(1); /* Indirect object base address: MEDIA_OBJECT data */
       OUT_RELOC(brw->cache.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
		 1); /* Instruction base address: shader kernels (incl. SIP) */

       OUT_BATCH(1); /* General state upper bound */
       /* Dynamic state upper bound.  Although the documentation says that
	* programming it to zero will cause it to be ignored, that is a lie.
	* If this isn't programmed to a real bound, the sampler border color
	* pointer is rejected, causing border color to mysteriously fail.
	*/
       OUT_BATCH(0xfffff001);
       OUT_BATCH(1); /* Indirect object upper bound */
       OUT_BATCH(1); /* Instruction access upper bound */
       ADVANCE_BATCH();
   } else if (brw->gen == 5) {
       BEGIN_BATCH(8);
       OUT_BATCH(CMD_STATE_BASE_ADDRESS << 16 | (8 - 2));
       OUT_BATCH(1); /* General state base address */
       OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_SAMPLER, 0,
		 1); /* Surface state base address */
       OUT_BATCH(1); /* Indirect object base address */
       OUT_RELOC(brw->cache.bo, I915_GEM_DOMAIN_INSTRUCTION, 0,
		 1); /* Instruction base address */
       OUT_BATCH(0xfffff001); /* General state upper bound */
       OUT_BATCH(1); /* Indirect object upper bound */
       OUT_BATCH(1); /* Instruction access upper bound */
       ADVANCE_BATCH();
   } else {
       BEGIN_BATCH(6);
       OUT_BATCH(CMD_STATE_BASE_ADDRESS << 16 | (6 - 2));
       OUT_BATCH(1); /* General state base address */
       OUT_RELOC(brw->batch.bo, I915_GEM_DOMAIN_SAMPLER, 0,
		 1); /* Surface state base address */
       OUT_BATCH(1); /* Indirect object base address */
       OUT_BATCH(1); /* General state upper bound */
       OUT_BATCH(1); /* Indirect object upper bound */
       ADVANCE_BATCH();
   }

   if (brw->gen >= 6) {
      brw_emit_pipe_control_flush(brw,
                                  PIPE_CONTROL_INSTRUCTION_INVALIDATE |
                                  PIPE_CONTROL_STATE_CACHE_INVALIDATE |
                                  PIPE_CONTROL_TEXTURE_CACHE_INVALIDATE);
   }

   /* According to section 3.6.1 of VOL1 of the 965 PRM,
    * STATE_BASE_ADDRESS updates require a reissue of:
    *
    * 3DSTATE_PIPELINE_POINTERS
    * 3DSTATE_BINDING_TABLE_POINTERS
    * MEDIA_STATE_POINTERS
    *
    * and this continues through Ironlake.  The Sandy Bridge PRM, vol
    * 1 part 1 says that the folowing packets must be reissued:
    *
    * 3DSTATE_CC_POINTERS
    * 3DSTATE_BINDING_TABLE_POINTERS
    * 3DSTATE_SAMPLER_STATE_POINTERS
    * 3DSTATE_VIEWPORT_STATE_POINTERS
    * MEDIA_STATE_POINTERS
    *
    * Those are always reissued following SBA updates anyway (new
    * batch time), except in the case of the program cache BO
    * changing.  Having a separate state flag makes the sequence more
    * obvious.
    */

   brw->ctx.NewDriverState |= BRW_NEW_STATE_BASE_ADDRESS;
   brw->batch.state_base_address_emitted = true;
}

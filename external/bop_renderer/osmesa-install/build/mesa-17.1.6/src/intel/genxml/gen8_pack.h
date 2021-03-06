/*
 * Copyright (C) 2016 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */


/* Instructions, enums and structures for BDW.
 *
 * This file has been generated, do not hand edit.
 */

#ifndef GEN8_PACK_H
#define GEN8_PACK_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#ifndef __gen_validate_value
#define __gen_validate_value(x)
#endif

#ifndef __gen_field_functions
#define __gen_field_functions

union __gen_value {
   float f;
   uint32_t dw;
};

static inline uint64_t
__gen_mbo(uint32_t start, uint32_t end)
{
   return (~0ull >> (64 - (end - start + 1))) << start;
}

static inline uint64_t
__gen_uint(uint64_t v, uint32_t start, uint32_t end)
{
   __gen_validate_value(v);

#if DEBUG
   const int width = end - start + 1;
   if (width < 64) {
      const uint64_t max = (1ull << width) - 1;
      assert(v <= max);
   }
#endif

   return v << start;
}

static inline uint64_t
__gen_sint(int64_t v, uint32_t start, uint32_t end)
{
   const int width = end - start + 1;

   __gen_validate_value(v);

#if DEBUG
   if (width < 64) {
      const int64_t max = (1ll << (width - 1)) - 1;
      const int64_t min = -(1ll << (width - 1));
      assert(min <= v && v <= max);
   }
#endif

   const uint64_t mask = ~0ull >> (64 - width);

   return (v & mask) << start;
}

static inline uint64_t
__gen_offset(uint64_t v, uint32_t start, uint32_t end)
{
   __gen_validate_value(v);
#if DEBUG
   uint64_t mask = (~0ull >> (64 - (end - start + 1))) << start;

   assert((v & ~mask) == 0);
#endif

   return v;
}

static inline uint32_t
__gen_float(float v)
{
   __gen_validate_value(v);
   return ((union __gen_value) { .f = (v) }).dw;
}

static inline uint64_t
__gen_sfixed(float v, uint32_t start, uint32_t end, uint32_t fract_bits)
{
   __gen_validate_value(v);

   const float factor = (1 << fract_bits);

#if DEBUG
   const float max = ((1 << (end - start)) - 1) / factor;
   const float min = -(1 << (end - start)) / factor;
   assert(min <= v && v <= max);
#endif

   const int64_t int_val = llroundf(v * factor);
   const uint64_t mask = ~0ull >> (64 - (end - start + 1));

   return (int_val & mask) << start;
}

static inline uint64_t
__gen_ufixed(float v, uint32_t start, uint32_t end, uint32_t fract_bits)
{
   __gen_validate_value(v);

   const float factor = (1 << fract_bits);

#if DEBUG
   const float max = ((1 << (end - start + 1)) - 1) / factor;
   const float min = 0.0f;
   assert(min <= v && v <= max);
#endif

   const uint64_t uint_val = llroundf(v * factor);

   return uint_val << start;
}

#ifndef __gen_address_type
#error #define __gen_address_type before including this file
#endif

#ifndef __gen_user_data
#error #define __gen_combine_address before including this file
#endif

#endif


enum GEN8_3D_Prim_Topo_Type {
   _3DPRIM_POINTLIST                    =      1,
   _3DPRIM_LINELIST                     =      2,
   _3DPRIM_LINESTRIP                    =      3,
   _3DPRIM_TRILIST                      =      4,
   _3DPRIM_TRISTRIP                     =      5,
   _3DPRIM_TRIFAN                       =      6,
   _3DPRIM_QUADLIST                     =      7,
   _3DPRIM_QUADSTRIP                    =      8,
   _3DPRIM_LINELIST_ADJ                 =      9,
   _3DPRIM_LINESTRIP_ADJ                =     10,
   _3DPRIM_TRILIST_ADJ                  =     11,
   _3DPRIM_TRISTRIP_ADJ                 =     12,
   _3DPRIM_TRISTRIP_REVERSE             =     13,
   _3DPRIM_POLYGON                      =     14,
   _3DPRIM_RECTLIST                     =     15,
   _3DPRIM_LINELOOP                     =     16,
   _3DPRIM_POINTLIST_BF                 =     17,
   _3DPRIM_LINESTRIP_CONT               =     18,
   _3DPRIM_LINESTRIP_BF                 =     19,
   _3DPRIM_LINESTRIP_CONT_BF            =     20,
   _3DPRIM_TRIFAN_NOSTIPPLE             =     22,
   _3DPRIM_PATCHLIST_1                  =     32,
   _3DPRIM_PATCHLIST_2                  =     33,
   _3DPRIM_PATCHLIST_3                  =     34,
   _3DPRIM_PATCHLIST_4                  =     35,
   _3DPRIM_PATCHLIST_5                  =     36,
   _3DPRIM_PATCHLIST_6                  =     37,
   _3DPRIM_PATCHLIST_7                  =     38,
   _3DPRIM_PATCHLIST_8                  =     39,
   _3DPRIM_PATCHLIST_9                  =     40,
   _3DPRIM_PATCHLIST_10                 =     41,
   _3DPRIM_PATCHLIST_11                 =     42,
   _3DPRIM_PATCHLIST_12                 =     43,
   _3DPRIM_PATCHLIST_13                 =     44,
   _3DPRIM_PATCHLIST_14                 =     45,
   _3DPRIM_PATCHLIST_15                 =     46,
   _3DPRIM_PATCHLIST_16                 =     47,
   _3DPRIM_PATCHLIST_17                 =     48,
   _3DPRIM_PATCHLIST_18                 =     49,
   _3DPRIM_PATCHLIST_19                 =     50,
   _3DPRIM_PATCHLIST_20                 =     51,
   _3DPRIM_PATCHLIST_21                 =     52,
   _3DPRIM_PATCHLIST_22                 =     53,
   _3DPRIM_PATCHLIST_23                 =     54,
   _3DPRIM_PATCHLIST_24                 =     55,
   _3DPRIM_PATCHLIST_25                 =     56,
   _3DPRIM_PATCHLIST_26                 =     57,
   _3DPRIM_PATCHLIST_27                 =     58,
   _3DPRIM_PATCHLIST_28                 =     59,
   _3DPRIM_PATCHLIST_29                 =     60,
   _3DPRIM_PATCHLIST_30                 =     61,
   _3DPRIM_PATCHLIST_31                 =     62,
   _3DPRIM_PATCHLIST_32                 =     63,
};

enum GEN8_3D_Vertex_Component_Control {
   VFCOMP_NOSTORE                       =      0,
   VFCOMP_STORE_SRC                     =      1,
   VFCOMP_STORE_0                       =      2,
   VFCOMP_STORE_1_FP                    =      3,
   VFCOMP_STORE_1_INT                   =      4,
   VFCOMP_STORE_PID                     =      7,
};

enum GEN8_WRAP_SHORTEST_ENABLE {
   WSE_X                                =      1,
   WSE_Y                                =      2,
   WSE_XY                               =      3,
   WSE_Z                                =      4,
   WSE_XZ                               =      5,
   WSE_YZ                               =      6,
   WSE_XYZ                              =      7,
   WSE_W                                =      8,
   WSE_XW                               =      9,
   WSE_YW                               =     10,
   WSE_XYW                              =     11,
   WSE_ZW                               =     12,
   WSE_XZW                              =     13,
   WSE_YZW                              =     14,
   WSE_XYZW                             =     15,
};

enum GEN8_3D_Stencil_Operation {
   STENCILOP_KEEP                       =      0,
   STENCILOP_ZERO                       =      1,
   STENCILOP_REPLACE                    =      2,
   STENCILOP_INCRSAT                    =      3,
   STENCILOP_DECRSAT                    =      4,
   STENCILOP_INCR                       =      5,
   STENCILOP_DECR                       =      6,
   STENCILOP_INVERT                     =      7,
};

enum GEN8_3D_Color_Buffer_Blend_Factor {
   BLENDFACTOR_ONE                      =      1,
   BLENDFACTOR_SRC_COLOR                =      2,
   BLENDFACTOR_SRC_ALPHA                =      3,
   BLENDFACTOR_DST_ALPHA                =      4,
   BLENDFACTOR_DST_COLOR                =      5,
   BLENDFACTOR_SRC_ALPHA_SATURATE       =      6,
   BLENDFACTOR_CONST_COLOR              =      7,
   BLENDFACTOR_CONST_ALPHA              =      8,
   BLENDFACTOR_SRC1_COLOR               =      9,
   BLENDFACTOR_SRC1_ALPHA               =     10,
   BLENDFACTOR_ZERO                     =     17,
   BLENDFACTOR_INV_SRC_COLOR            =     18,
   BLENDFACTOR_INV_SRC_ALPHA            =     19,
   BLENDFACTOR_INV_DST_ALPHA            =     20,
   BLENDFACTOR_INV_DST_COLOR            =     21,
   BLENDFACTOR_INV_CONST_COLOR          =     23,
   BLENDFACTOR_INV_CONST_ALPHA          =     24,
   BLENDFACTOR_INV_SRC1_COLOR           =     25,
   BLENDFACTOR_INV_SRC1_ALPHA           =     26,
};

enum GEN8_3D_Color_Buffer_Blend_Function {
   BLENDFUNCTION_ADD                    =      0,
   BLENDFUNCTION_SUBTRACT               =      1,
   BLENDFUNCTION_REVERSE_SUBTRACT       =      2,
   BLENDFUNCTION_MIN                    =      3,
   BLENDFUNCTION_MAX                    =      4,
};

enum GEN8_3D_Compare_Function {
   COMPAREFUNCTION_ALWAYS               =      0,
   COMPAREFUNCTION_NEVER                =      1,
   COMPAREFUNCTION_LESS                 =      2,
   COMPAREFUNCTION_EQUAL                =      3,
   COMPAREFUNCTION_LEQUAL               =      4,
   COMPAREFUNCTION_GREATER              =      5,
   COMPAREFUNCTION_NOTEQUAL             =      6,
   COMPAREFUNCTION_GEQUAL               =      7,
};

enum GEN8_3D_Logic_Op_Function {
   LOGICOP_CLEAR                        =      0,
   LOGICOP_NOR                          =      1,
   LOGICOP_AND_INVERTED                 =      2,
   LOGICOP_COPY_INVERTED                =      3,
   LOGICOP_AND_REVERSE                  =      4,
   LOGICOP_INVERT                       =      5,
   LOGICOP_XOR                          =      6,
   LOGICOP_NAND                         =      7,
   LOGICOP_AND                          =      8,
   LOGICOP_EQUIV                        =      9,
   LOGICOP_NOOP                         =     10,
   LOGICOP_OR_INVERTED                  =     11,
   LOGICOP_COPY                         =     12,
   LOGICOP_OR_REVERSE                   =     13,
   LOGICOP_OR                           =     14,
   LOGICOP_SET                          =     15,
};

enum GEN8_SURFACE_FORMAT {
   SF_R32G32B32A32_FLOAT                =      0,
   SF_R32G32B32A32_SINT                 =      1,
   SF_R32G32B32A32_UINT                 =      2,
   SF_R32G32B32A32_UNORM                =      3,
   SF_R32G32B32A32_SNORM                =      4,
   SF_R64G64_FLOAT                      =      5,
   SF_R32G32B32X32_FLOAT                =      6,
   SF_R32G32B32A32_SSCALED              =      7,
   SF_R32G32B32A32_USCALED              =      8,
   SF_R32G32B32A32_SFIXED               =     32,
   SF_R64G64_PASSTHRU                   =     33,
   SF_R32G32B32_FLOAT                   =     64,
   SF_R32G32B32_SINT                    =     65,
   SF_R32G32B32_UINT                    =     66,
   SF_R32G32B32_UNORM                   =     67,
   SF_R32G32B32_SNORM                   =     68,
   SF_R32G32B32_SSCALED                 =     69,
   SF_R32G32B32_USCALED                 =     70,
   SF_R32G32B32_SFIXED                  =     80,
   SF_R16G16B16A16_UNORM                =    128,
   SF_R16G16B16A16_SNORM                =    129,
   SF_R16G16B16A16_SINT                 =    130,
   SF_R16G16B16A16_UINT                 =    131,
   SF_R16G16B16A16_FLOAT                =    132,
   SF_R32G32_FLOAT                      =    133,
   SF_R32G32_SINT                       =    134,
   SF_R32G32_UINT                       =    135,
   SF_R32_FLOAT_X8X24_TYPELESS          =    136,
   SF_X32_TYPELESS_G8X24_UINT           =    137,
   SF_L32A32_FLOAT                      =    138,
   SF_R32G32_UNORM                      =    139,
   SF_R32G32_SNORM                      =    140,
   SF_R64_FLOAT                         =    141,
   SF_R16G16B16X16_UNORM                =    142,
   SF_R16G16B16X16_FLOAT                =    143,
   SF_A32X32_FLOAT                      =    144,
   SF_L32X32_FLOAT                      =    145,
   SF_I32X32_FLOAT                      =    146,
   SF_R16G16B16A16_SSCALED              =    147,
   SF_R16G16B16A16_USCALED              =    148,
   SF_R32G32_SSCALED                    =    149,
   SF_R32G32_USCALED                    =    150,
   SF_R32G32_SFIXED                     =    160,
   SF_R64_PASSTHRU                      =    161,
   SF_B8G8R8A8_UNORM                    =    192,
   SF_B8G8R8A8_UNORM_SRGB               =    193,
   SF_R10G10B10A2_UNORM                 =    194,
   SF_R10G10B10A2_UNORM_SRGB            =    195,
   SF_R10G10B10A2_UINT                  =    196,
   SF_R10G10B10_SNORM_A2_UNORM          =    197,
   SF_R8G8B8A8_UNORM                    =    199,
   SF_R8G8B8A8_UNORM_SRGB               =    200,
   SF_R8G8B8A8_SNORM                    =    201,
   SF_R8G8B8A8_SINT                     =    202,
   SF_R8G8B8A8_UINT                     =    203,
   SF_R16G16_UNORM                      =    204,
   SF_R16G16_SNORM                      =    205,
   SF_R16G16_SINT                       =    206,
   SF_R16G16_UINT                       =    207,
   SF_R16G16_FLOAT                      =    208,
   SF_B10G10R10A2_UNORM                 =    209,
   SF_B10G10R10A2_UNORM_SRGB            =    210,
   SF_R11G11B10_FLOAT                   =    211,
   SF_R32_SINT                          =    214,
   SF_R32_UINT                          =    215,
   SF_R32_FLOAT                         =    216,
   SF_R24_UNORM_X8_TYPELESS             =    217,
   SF_X24_TYPELESS_G8_UINT              =    218,
   SF_L32_UNORM                         =    221,
   SF_A32_UNORM                         =    222,
   SF_L16A16_UNORM                      =    223,
   SF_I24X8_UNORM                       =    224,
   SF_L24X8_UNORM                       =    225,
   SF_A24X8_UNORM                       =    226,
   SF_I32_FLOAT                         =    227,
   SF_L32_FLOAT                         =    228,
   SF_A32_FLOAT                         =    229,
   SF_X8B8_UNORM_G8R8_SNORM             =    230,
   SF_A8X8_UNORM_G8R8_SNORM             =    231,
   SF_B8X8_UNORM_G8R8_SNORM             =    232,
   SF_B8G8R8X8_UNORM                    =    233,
   SF_B8G8R8X8_UNORM_SRGB               =    234,
   SF_R8G8B8X8_UNORM                    =    235,
   SF_R8G8B8X8_UNORM_SRGB               =    236,
   SF_R9G9B9E5_SHAREDEXP                =    237,
   SF_B10G10R10X2_UNORM                 =    238,
   SF_L16A16_FLOAT                      =    240,
   SF_R32_UNORM                         =    241,
   SF_R32_SNORM                         =    242,
   SF_R10G10B10X2_USCALED               =    243,
   SF_R8G8B8A8_SSCALED                  =    244,
   SF_R8G8B8A8_USCALED                  =    245,
   SF_R16G16_SSCALED                    =    246,
   SF_R16G16_USCALED                    =    247,
   SF_R32_SSCALED                       =    248,
   SF_R32_USCALED                       =    249,
   SF_B5G6R5_UNORM                      =    256,
   SF_B5G6R5_UNORM_SRGB                 =    257,
   SF_B5G5R5A1_UNORM                    =    258,
   SF_B5G5R5A1_UNORM_SRGB               =    259,
   SF_B4G4R4A4_UNORM                    =    260,
   SF_B4G4R4A4_UNORM_SRGB               =    261,
   SF_R8G8_UNORM                        =    262,
   SF_R8G8_SNORM                        =    263,
   SF_R8G8_SINT                         =    264,
   SF_R8G8_UINT                         =    265,
   SF_R16_UNORM                         =    266,
   SF_R16_SNORM                         =    267,
   SF_R16_SINT                          =    268,
   SF_R16_UINT                          =    269,
   SF_R16_FLOAT                         =    270,
   SF_A8P8_UNORM_PALETTE0               =    271,
   SF_A8P8_UNORM_PALETTE1               =    272,
   SF_I16_UNORM                         =    273,
   SF_L16_UNORM                         =    274,
   SF_A16_UNORM                         =    275,
   SF_L8A8_UNORM                        =    276,
   SF_I16_FLOAT                         =    277,
   SF_L16_FLOAT                         =    278,
   SF_A16_FLOAT                         =    279,
   SF_L8A8_UNORM_SRGB                   =    280,
   SF_R5G5_SNORM_B6_UNORM               =    281,
   SF_B5G5R5X1_UNORM                    =    282,
   SF_B5G5R5X1_UNORM_SRGB               =    283,
   SF_R8G8_SSCALED                      =    284,
   SF_R8G8_USCALED                      =    285,
   SF_R16_SSCALED                       =    286,
   SF_R16_USCALED                       =    287,
   SF_P8A8_UNORM_PALETTE0               =    290,
   SF_P8A8_UNORM_PALETTE1               =    291,
   SF_A1B5G5R5_UNORM                    =    292,
   SF_A4B4G4R4_UNORM                    =    293,
   SF_L8A8_UINT                         =    294,
   SF_L8A8_SINT                         =    295,
   SF_R8_UNORM                          =    320,
   SF_R8_SNORM                          =    321,
   SF_R8_SINT                           =    322,
   SF_R8_UINT                           =    323,
   SF_A8_UNORM                          =    324,
   SF_I8_UNORM                          =    325,
   SF_L8_UNORM                          =    326,
   SF_P4A4_UNORM_PALETTE0               =    327,
   SF_A4P4_UNORM_PALETTE0               =    328,
   SF_R8_SSCALED                        =    329,
   SF_R8_USCALED                        =    330,
   SF_P8_UNORM_PALETTE0                 =    331,
   SF_L8_UNORM_SRGB                     =    332,
   SF_P8_UNORM_PALETTE1                 =    333,
   SF_P4A4_UNORM_PALETTE1               =    334,
   SF_A4P4_UNORM_PALETTE1               =    335,
   SF_Y8_UNORM                          =    336,
   SF_L8_UINT                           =    338,
   SF_L8_SINT                           =    339,
   SF_I8_UINT                           =    340,
   SF_I8_SINT                           =    341,
   SF_DXT1_RGB_SRGB                     =    384,
   SF_R1_UNORM                          =    385,
   SF_YCRCB_NORMAL                      =    386,
   SF_YCRCB_SWAPUVY                     =    387,
   SF_P2_UNORM_PALETTE0                 =    388,
   SF_P2_UNORM_PALETTE1                 =    389,
   SF_BC1_UNORM                         =    390,
   SF_BC2_UNORM                         =    391,
   SF_BC3_UNORM                         =    392,
   SF_BC4_UNORM                         =    393,
   SF_BC5_UNORM                         =    394,
   SF_BC1_UNORM_SRGB                    =    395,
   SF_BC2_UNORM_SRGB                    =    396,
   SF_BC3_UNORM_SRGB                    =    397,
   SF_MONO8                             =    398,
   SF_YCRCB_SWAPUV                      =    399,
   SF_YCRCB_SWAPY                       =    400,
   SF_DXT1_RGB                          =    401,
   SF_FXT1                              =    402,
   SF_R8G8B8_UNORM                      =    403,
   SF_R8G8B8_SNORM                      =    404,
   SF_R8G8B8_SSCALED                    =    405,
   SF_R8G8B8_USCALED                    =    406,
   SF_R64G64B64A64_FLOAT                =    407,
   SF_R64G64B64_FLOAT                   =    408,
   SF_BC4_SNORM                         =    409,
   SF_BC5_SNORM                         =    410,
   SF_R16G16B16_FLOAT                   =    411,
   SF_R16G16B16_UNORM                   =    412,
   SF_R16G16B16_SNORM                   =    413,
   SF_R16G16B16_SSCALED                 =    414,
   SF_R16G16B16_USCALED                 =    415,
   SF_BC6H_SF16                         =    417,
   SF_BC7_UNORM                         =    418,
   SF_BC7_UNORM_SRGB                    =    419,
   SF_BC6H_UF16                         =    420,
   SF_PLANAR_420_8                      =    421,
   SF_R8G8B8_UNORM_SRGB                 =    424,
   SF_ETC1_RGB8                         =    425,
   SF_ETC2_RGB8                         =    426,
   SF_EAC_R11                           =    427,
   SF_EAC_RG11                          =    428,
   SF_EAC_SIGNED_R11                    =    429,
   SF_EAC_SIGNED_RG11                   =    430,
   SF_ETC2_SRGB8                        =    431,
   SF_R16G16B16_UINT                    =    432,
   SF_R16G16B16_SINT                    =    433,
   SF_R32_SFIXED                        =    434,
   SF_R10G10B10A2_SNORM                 =    435,
   SF_R10G10B10A2_USCALED               =    436,
   SF_R10G10B10A2_SSCALED               =    437,
   SF_R10G10B10A2_SINT                  =    438,
   SF_B10G10R10A2_SNORM                 =    439,
   SF_B10G10R10A2_USCALED               =    440,
   SF_B10G10R10A2_SSCALED               =    441,
   SF_B10G10R10A2_UINT                  =    442,
   SF_B10G10R10A2_SINT                  =    443,
   SF_R64G64B64A64_PASSTHRU             =    444,
   SF_R64G64B64_PASSTHRU                =    445,
   SF_ETC2_RGB8_PTA                     =    448,
   SF_ETC2_SRGB8_PTA                    =    449,
   SF_ETC2_EAC_RGBA8                    =    450,
   SF_ETC2_EAC_SRGB8_A8                 =    451,
   SF_R8G8B8_UINT                       =    456,
   SF_R8G8B8_SINT                       =    457,
   SF_RAW                               =    511,
};

enum GEN8_ShaderChannelSelect {
   SCS_ZERO                             =      0,
   SCS_ONE                              =      1,
   SCS_RED                              =      4,
   SCS_GREEN                            =      5,
   SCS_BLUE                             =      6,
   SCS_ALPHA                            =      7,
};

enum GEN8_ClearColor {
   CC_ZERO                              =      0,
   CC_ONE                               =      1,
};

enum GEN8_TextureCoordinateMode {
   TCM_WRAP                             =      0,
   TCM_MIRROR                           =      1,
   TCM_CLAMP                            =      2,
   TCM_CUBE                             =      3,
   TCM_CLAMP_BORDER                     =      4,
   TCM_MIRROR_ONCE                      =      5,
   TCM_HALF_BORDER                      =      6,
};

#define GEN8_3DSTATE_CONSTANT_BODY_length     10
struct GEN8_3DSTATE_CONSTANT_BODY {
   uint32_t                             ConstantBuffer1ReadLength;
   uint32_t                             ConstantBuffer0ReadLength;
   uint32_t                             ConstantBuffer3ReadLength;
   uint32_t                             ConstantBuffer2ReadLength;
   __gen_address_type                   PointerToConstantBuffer0;
   __gen_address_type                   PointerToConstantBuffer1;
   __gen_address_type                   PointerToConstantBuffer2;
   __gen_address_type                   PointerToConstantBuffer3;
};

static inline void
GEN8_3DSTATE_CONSTANT_BODY_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN8_3DSTATE_CONSTANT_BODY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->ConstantBuffer1ReadLength, 16, 31) |
      __gen_uint(values->ConstantBuffer0ReadLength, 0, 15);

   dw[1] =
      __gen_uint(values->ConstantBuffer3ReadLength, 16, 31) |
      __gen_uint(values->ConstantBuffer2ReadLength, 0, 15);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->PointerToConstantBuffer0, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   const uint64_t v4_address =
      __gen_combine_address(data, &dw[4], values->PointerToConstantBuffer1, 0);
   dw[4] = v4_address;
   dw[5] = v4_address >> 32;

   const uint64_t v6_address =
      __gen_combine_address(data, &dw[6], values->PointerToConstantBuffer2, 0);
   dw[6] = v6_address;
   dw[7] = v6_address >> 32;

   const uint64_t v8_address =
      __gen_combine_address(data, &dw[8], values->PointerToConstantBuffer3, 0);
   dw[8] = v8_address;
   dw[9] = v8_address >> 32;
}

#define GEN8_BINDING_TABLE_EDIT_ENTRY_length      1
struct GEN8_BINDING_TABLE_EDIT_ENTRY {
   uint32_t                             BindingTableIndex;
   uint64_t                             SurfaceStatePointer;
};

static inline void
GEN8_BINDING_TABLE_EDIT_ENTRY_pack(__gen_user_data *data, void * restrict dst,
                                   const struct GEN8_BINDING_TABLE_EDIT_ENTRY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->BindingTableIndex, 16, 23) |
      __gen_offset(values->SurfaceStatePointer, 0, 15);
}

#define GEN8_GATHER_CONSTANT_ENTRY_length      1
struct GEN8_GATHER_CONSTANT_ENTRY {
   uint64_t                             ConstantBufferOffset;
   uint32_t                             ChannelMask;
   uint32_t                             BindingTableIndexOffset;
};

static inline void
GEN8_GATHER_CONSTANT_ENTRY_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN8_GATHER_CONSTANT_ENTRY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_offset(values->ConstantBufferOffset, 8, 15) |
      __gen_uint(values->ChannelMask, 4, 7) |
      __gen_uint(values->BindingTableIndexOffset, 0, 3);
}

#define GEN8_MEMORY_OBJECT_CONTROL_STATE_length      1
struct GEN8_MEMORY_OBJECT_CONTROL_STATE {
   uint32_t                             MemoryTypeLLCeLLCCacheabilityControl;
#define UCwithFenceifcoherentcycle               0
#define UCUncacheable                            1
#define WT                                       2
#define WB                                       3
   uint32_t                             TargetCache;
#define eLLCOnlywheneDRAMispresentelsegetsallocatedinLLC 0
#define LLCOnly                                  1
#define LLCeLLCAllowed                           2
#define L3DefertoPATforLLCeLLCselection          3
   uint32_t                             AgeforQUADLRU;
};

static inline void
GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(__gen_user_data *data, void * restrict dst,
                                      const struct GEN8_MEMORY_OBJECT_CONTROL_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->MemoryTypeLLCeLLCCacheabilityControl, 5, 6) |
      __gen_uint(values->TargetCache, 3, 4) |
      __gen_uint(values->AgeforQUADLRU, 0, 1);
}

#define GEN8_VERTEX_BUFFER_STATE_length        4
struct GEN8_VERTEX_BUFFER_STATE {
   uint32_t                             VertexBufferIndex;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE MemoryObjectControlState;
   uint32_t                             VertexBufferMOCS;
   bool                                 AddressModifyEnable;
   bool                                 NullVertexBuffer;
   uint32_t                             BufferPitch;
   __gen_address_type                   BufferStartingAddress;
   uint32_t                             BufferSize;
};

static inline void
GEN8_VERTEX_BUFFER_STATE_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_VERTEX_BUFFER_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v0_0, &values->MemoryObjectControlState);

   dw[0] =
      __gen_uint(values->VertexBufferIndex, 26, 31) |
      __gen_uint(v0_0, 16, 22) |
      __gen_uint(values->VertexBufferMOCS, 16, 22) |
      __gen_uint(values->AddressModifyEnable, 14, 14) |
      __gen_uint(values->NullVertexBuffer, 13, 13) |
      __gen_uint(values->BufferPitch, 0, 11);

   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->BufferStartingAddress, 0);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   dw[3] =
      __gen_uint(values->BufferSize, 0, 31);
}

#define GEN8_VERTEX_ELEMENT_STATE_length       2
struct GEN8_VERTEX_ELEMENT_STATE {
   uint32_t                             VertexBufferIndex;
   bool                                 Valid;
   enum GEN8_SURFACE_FORMAT             SourceElementFormat;
   bool                                 EdgeFlagEnable;
   uint32_t                             SourceElementOffset;
   enum GEN8_3D_Vertex_Component_Control Component0Control;
   enum GEN8_3D_Vertex_Component_Control Component1Control;
   enum GEN8_3D_Vertex_Component_Control Component2Control;
   enum GEN8_3D_Vertex_Component_Control Component3Control;
};

static inline void
GEN8_VERTEX_ELEMENT_STATE_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_VERTEX_ELEMENT_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->VertexBufferIndex, 26, 31) |
      __gen_uint(values->Valid, 25, 25) |
      __gen_uint(values->SourceElementFormat, 16, 24) |
      __gen_uint(values->EdgeFlagEnable, 15, 15) |
      __gen_uint(values->SourceElementOffset, 0, 11);

   dw[1] =
      __gen_uint(values->Component0Control, 28, 30) |
      __gen_uint(values->Component1Control, 24, 26) |
      __gen_uint(values->Component2Control, 20, 22) |
      __gen_uint(values->Component3Control, 16, 18);
}

#define GEN8_SO_DECL_length                    1
struct GEN8_SO_DECL {
   uint32_t                             OutputBufferSlot;
   uint32_t                             HoleFlag;
   uint32_t                             RegisterIndex;
   uint32_t                             ComponentMask;
};

static inline void
GEN8_SO_DECL_pack(__gen_user_data *data, void * restrict dst,
                  const struct GEN8_SO_DECL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->OutputBufferSlot, 12, 13) |
      __gen_uint(values->HoleFlag, 11, 11) |
      __gen_uint(values->RegisterIndex, 4, 9) |
      __gen_uint(values->ComponentMask, 0, 3);
}

#define GEN8_SO_DECL_ENTRY_length              2
struct GEN8_SO_DECL_ENTRY {
   struct GEN8_SO_DECL                  Stream3Decl;
   struct GEN8_SO_DECL                  Stream2Decl;
   struct GEN8_SO_DECL                  Stream1Decl;
   struct GEN8_SO_DECL                  Stream0Decl;
};

static inline void
GEN8_SO_DECL_ENTRY_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_SO_DECL_ENTRY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_SO_DECL_pack(data, &v0_0, &values->Stream1Decl);

   uint32_t v0_1;
   GEN8_SO_DECL_pack(data, &v0_1, &values->Stream0Decl);

   dw[0] =
      __gen_uint(v0_0, 16, 31) |
      __gen_uint(v0_1, 0, 15);

   uint32_t v1_0;
   GEN8_SO_DECL_pack(data, &v1_0, &values->Stream3Decl);

   uint32_t v1_1;
   GEN8_SO_DECL_pack(data, &v1_1, &values->Stream2Decl);

   dw[1] =
      __gen_uint(v1_0, 16, 31) |
      __gen_uint(v1_1, 0, 15);
}

#define GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_length      1
struct GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL {
   bool                                 ComponentOverrideW;
   bool                                 ComponentOverrideZ;
   bool                                 ComponentOverrideY;
   bool                                 ComponentOverrideX;
   uint32_t                             SwizzleControlMode;
   uint32_t                             ConstantSource;
#define CONST_0000                               0
#define CONST_0001_FLOAT                         1
#define CONST_1111_FLOAT                         2
#define PRIM_ID                                  3
   uint32_t                             SwizzleSelect;
#define INPUTATTR                                0
#define INPUTATTR_FACING                         1
#define INPUTATTR_W                              2
#define INPUTATTR_FACING_W                       3
   uint32_t                             SourceAttribute;
};

static inline void
GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->ComponentOverrideW, 15, 15) |
      __gen_uint(values->ComponentOverrideZ, 14, 14) |
      __gen_uint(values->ComponentOverrideY, 13, 13) |
      __gen_uint(values->ComponentOverrideX, 12, 12) |
      __gen_uint(values->SwizzleControlMode, 11, 11) |
      __gen_uint(values->ConstantSource, 9, 10) |
      __gen_uint(values->SwizzleSelect, 6, 7) |
      __gen_uint(values->SourceAttribute, 0, 4);
}

#define GEN8_SCISSOR_RECT_length               2
struct GEN8_SCISSOR_RECT {
   uint32_t                             ScissorRectangleYMin;
   uint32_t                             ScissorRectangleXMin;
   uint32_t                             ScissorRectangleYMax;
   uint32_t                             ScissorRectangleXMax;
};

static inline void
GEN8_SCISSOR_RECT_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_SCISSOR_RECT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->ScissorRectangleYMin, 16, 31) |
      __gen_uint(values->ScissorRectangleXMin, 0, 15);

   dw[1] =
      __gen_uint(values->ScissorRectangleYMax, 16, 31) |
      __gen_uint(values->ScissorRectangleXMax, 0, 15);
}

#define GEN8_SF_CLIP_VIEWPORT_length          16
struct GEN8_SF_CLIP_VIEWPORT {
   float                                ViewportMatrixElementm00;
   float                                ViewportMatrixElementm11;
   float                                ViewportMatrixElementm22;
   float                                ViewportMatrixElementm30;
   float                                ViewportMatrixElementm31;
   float                                ViewportMatrixElementm32;
   float                                XMinClipGuardband;
   float                                XMaxClipGuardband;
   float                                YMinClipGuardband;
   float                                YMaxClipGuardband;
   float                                XMinViewPort;
   float                                XMaxViewPort;
   float                                YMinViewPort;
   float                                YMaxViewPort;
};

static inline void
GEN8_SF_CLIP_VIEWPORT_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_SF_CLIP_VIEWPORT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_float(values->ViewportMatrixElementm00);

   dw[1] =
      __gen_float(values->ViewportMatrixElementm11);

   dw[2] =
      __gen_float(values->ViewportMatrixElementm22);

   dw[3] =
      __gen_float(values->ViewportMatrixElementm30);

   dw[4] =
      __gen_float(values->ViewportMatrixElementm31);

   dw[5] =
      __gen_float(values->ViewportMatrixElementm32);

   dw[6] = 0;

   dw[7] = 0;

   dw[8] =
      __gen_float(values->XMinClipGuardband);

   dw[9] =
      __gen_float(values->XMaxClipGuardband);

   dw[10] =
      __gen_float(values->YMinClipGuardband);

   dw[11] =
      __gen_float(values->YMaxClipGuardband);

   dw[12] =
      __gen_float(values->XMinViewPort);

   dw[13] =
      __gen_float(values->XMaxViewPort);

   dw[14] =
      __gen_float(values->YMinViewPort);

   dw[15] =
      __gen_float(values->YMaxViewPort);
}

#define GEN8_BLEND_STATE_ENTRY_length          2
struct GEN8_BLEND_STATE_ENTRY {
   bool                                 LogicOpEnable;
   enum GEN8_3D_Logic_Op_Function       LogicOpFunction;
   bool                                 PreBlendSourceOnlyClampEnable;
   uint32_t                             ColorClampRange;
#define COLORCLAMP_UNORM                         0
#define COLORCLAMP_SNORM                         1
#define COLORCLAMP_RTFORMAT                      2
   bool                                 PreBlendColorClampEnable;
   bool                                 PostBlendColorClampEnable;
   bool                                 ColorBufferBlendEnable;
   enum GEN8_3D_Color_Buffer_Blend_Factor SourceBlendFactor;
   enum GEN8_3D_Color_Buffer_Blend_Factor DestinationBlendFactor;
   enum GEN8_3D_Color_Buffer_Blend_Function ColorBlendFunction;
   enum GEN8_3D_Color_Buffer_Blend_Factor SourceAlphaBlendFactor;
   enum GEN8_3D_Color_Buffer_Blend_Factor DestinationAlphaBlendFactor;
   enum GEN8_3D_Color_Buffer_Blend_Function AlphaBlendFunction;
   bool                                 WriteDisableAlpha;
   bool                                 WriteDisableRed;
   bool                                 WriteDisableGreen;
   bool                                 WriteDisableBlue;
};

static inline void
GEN8_BLEND_STATE_ENTRY_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_BLEND_STATE_ENTRY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->ColorBufferBlendEnable, 31, 31) |
      __gen_uint(values->SourceBlendFactor, 26, 30) |
      __gen_uint(values->DestinationBlendFactor, 21, 25) |
      __gen_uint(values->ColorBlendFunction, 18, 20) |
      __gen_uint(values->SourceAlphaBlendFactor, 13, 17) |
      __gen_uint(values->DestinationAlphaBlendFactor, 8, 12) |
      __gen_uint(values->AlphaBlendFunction, 5, 7) |
      __gen_uint(values->WriteDisableAlpha, 3, 3) |
      __gen_uint(values->WriteDisableRed, 2, 2) |
      __gen_uint(values->WriteDisableGreen, 1, 1) |
      __gen_uint(values->WriteDisableBlue, 0, 0);

   dw[1] =
      __gen_uint(values->LogicOpEnable, 31, 31) |
      __gen_uint(values->LogicOpFunction, 27, 30) |
      __gen_uint(values->PreBlendSourceOnlyClampEnable, 4, 4) |
      __gen_uint(values->ColorClampRange, 2, 3) |
      __gen_uint(values->PreBlendColorClampEnable, 1, 1) |
      __gen_uint(values->PostBlendColorClampEnable, 0, 0);
}

#define GEN8_BLEND_STATE_length               17
struct GEN8_BLEND_STATE {
   bool                                 AlphaToCoverageEnable;
   bool                                 IndependentAlphaBlendEnable;
   bool                                 AlphaToOneEnable;
   bool                                 AlphaToCoverageDitherEnable;
   bool                                 AlphaTestEnable;
   enum GEN8_3D_Compare_Function        AlphaTestFunction;
   bool                                 ColorDitherEnable;
   uint32_t                             XDitherOffset;
   uint32_t                             YDitherOffset;
   struct GEN8_BLEND_STATE_ENTRY        Entry[8];
};

static inline void
GEN8_BLEND_STATE_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN8_BLEND_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->AlphaToCoverageEnable, 31, 31) |
      __gen_uint(values->IndependentAlphaBlendEnable, 30, 30) |
      __gen_uint(values->AlphaToOneEnable, 29, 29) |
      __gen_uint(values->AlphaToCoverageDitherEnable, 28, 28) |
      __gen_uint(values->AlphaTestEnable, 27, 27) |
      __gen_uint(values->AlphaTestFunction, 24, 26) |
      __gen_uint(values->ColorDitherEnable, 23, 23) |
      __gen_uint(values->XDitherOffset, 21, 22) |
      __gen_uint(values->YDitherOffset, 19, 20);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[1], &values->Entry[0]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[3], &values->Entry[1]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[5], &values->Entry[2]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[7], &values->Entry[3]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[9], &values->Entry[4]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[11], &values->Entry[5]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[13], &values->Entry[6]);

   GEN8_BLEND_STATE_ENTRY_pack(data, &dw[15], &values->Entry[7]);
}

#define GEN8_CC_VIEWPORT_length                2
struct GEN8_CC_VIEWPORT {
   float                                MinimumDepth;
   float                                MaximumDepth;
};

static inline void
GEN8_CC_VIEWPORT_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN8_CC_VIEWPORT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_float(values->MinimumDepth);

   dw[1] =
      __gen_float(values->MaximumDepth);
}

#define GEN8_COLOR_CALC_STATE_length           6
struct GEN8_COLOR_CALC_STATE {
   uint32_t                             StencilReferenceValue;
   uint32_t                             BackFaceStencilReferenceValue;
   bool                                 RoundDisableFunctionDisable;
   uint32_t                             AlphaTestFormat;
#define ALPHATEST_UNORM8                         0
#define ALPHATEST_FLOAT32                        1
   uint32_t                             AlphaReferenceValueAsUNORM8;
   float                                AlphaReferenceValueAsFLOAT32;
   float                                BlendConstantColorRed;
   float                                BlendConstantColorGreen;
   float                                BlendConstantColorBlue;
   float                                BlendConstantColorAlpha;
};

static inline void
GEN8_COLOR_CALC_STATE_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_COLOR_CALC_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->StencilReferenceValue, 24, 31) |
      __gen_uint(values->BackFaceStencilReferenceValue, 16, 23) |
      __gen_uint(values->RoundDisableFunctionDisable, 15, 15) |
      __gen_uint(values->AlphaTestFormat, 0, 0);

   dw[1] =
      __gen_uint(values->AlphaReferenceValueAsUNORM8, 0, 31) |
      __gen_float(values->AlphaReferenceValueAsFLOAT32);

   dw[2] =
      __gen_float(values->BlendConstantColorRed);

   dw[3] =
      __gen_float(values->BlendConstantColorGreen);

   dw[4] =
      __gen_float(values->BlendConstantColorBlue);

   dw[5] =
      __gen_float(values->BlendConstantColorAlpha);
}

#define GEN8_INTERFACE_DESCRIPTOR_DATA_length      8
struct GEN8_INTERFACE_DESCRIPTOR_DATA {
   uint64_t                             KernelStartPointer;
   uint32_t                             DenormMode;
#define Ftz                                      0
#define SetByKernel                              1
   bool                                 SingleProgramFlow;
   uint32_t                             ThreadPriority;
#define NormalPriority                           0
#define HighPriority                             1
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint64_t                             SamplerStatePointer;
   uint32_t                             SamplerCount;
#define Nosamplersused                           0
#define Between1and4samplersused                 1
#define Between5and8samplersused                 2
#define Between9and12samplersused                3
#define Between13and16samplersused               4
   uint64_t                             BindingTablePointer;
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ConstantURBEntryReadLength;
   uint32_t                             ConstantURBEntryReadOffset;
   uint32_t                             RoundingMode;
#define RTNE                                     0
#define RU                                       1
#define RD                                       2
#define RTZ                                      3
   bool                                 BarrierEnable;
   uint32_t                             SharedLocalMemorySize;
#define Encodes0k                                0
#define Encodes4k                                1
#define Encodes8k                                2
#define Encodes16k                               4
#define Encodes32k                               8
#define Encodes64k                               16
   uint32_t                             NumberofThreadsinGPGPUThreadGroup;
   uint32_t                             CrossThreadConstantDataReadLength;
};

static inline void
GEN8_INTERFACE_DESCRIPTOR_DATA_pack(__gen_user_data *data, void * restrict dst,
                                    const struct GEN8_INTERFACE_DESCRIPTOR_DATA * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_offset(values->KernelStartPointer, 6, 47);
   dw[0] = v0;
   dw[1] = v0 >> 32;

   dw[2] =
      __gen_uint(values->DenormMode, 19, 19) |
      __gen_uint(values->SingleProgramFlow, 18, 18) |
      __gen_uint(values->ThreadPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   dw[3] =
      __gen_offset(values->SamplerStatePointer, 5, 31) |
      __gen_uint(values->SamplerCount, 2, 4);

   dw[4] =
      __gen_offset(values->BindingTablePointer, 5, 15) |
      __gen_uint(values->BindingTableEntryCount, 0, 4);

   dw[5] =
      __gen_uint(values->ConstantURBEntryReadLength, 16, 31) |
      __gen_uint(values->ConstantURBEntryReadOffset, 0, 15);

   dw[6] =
      __gen_uint(values->RoundingMode, 22, 23) |
      __gen_uint(values->BarrierEnable, 21, 21) |
      __gen_uint(values->SharedLocalMemorySize, 16, 20) |
      __gen_uint(values->NumberofThreadsinGPGPUThreadGroup, 0, 9);

   dw[7] =
      __gen_uint(values->CrossThreadConstantDataReadLength, 0, 7);
}

#define GEN8_PALETTE_ENTRY_length              1
struct GEN8_PALETTE_ENTRY {
   uint32_t                             Alpha;
   uint32_t                             Red;
   uint32_t                             Green;
   uint32_t                             Blue;
};

static inline void
GEN8_PALETTE_ENTRY_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_PALETTE_ENTRY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->Alpha, 24, 31) |
      __gen_uint(values->Red, 16, 23) |
      __gen_uint(values->Green, 8, 15) |
      __gen_uint(values->Blue, 0, 7);
}

#define GEN8_BINDING_TABLE_STATE_length        1
struct GEN8_BINDING_TABLE_STATE {
   uint64_t                             SurfaceStatePointer;
};

static inline void
GEN8_BINDING_TABLE_STATE_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_BINDING_TABLE_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_offset(values->SurfaceStatePointer, 6, 31);
}

#define GEN8_RENDER_SURFACE_STATE_length      16
struct GEN8_RENDER_SURFACE_STATE {
   uint32_t                             SurfaceType;
#define SURFTYPE_1D                              0
#define SURFTYPE_2D                              1
#define SURFTYPE_3D                              2
#define SURFTYPE_CUBE                            3
#define SURFTYPE_BUFFER                          4
#define SURFTYPE_STRBUF                          5
#define SURFTYPE_NULL                            7
   bool                                 SurfaceArray;
   enum GEN8_SURFACE_FORMAT             SurfaceFormat;
   uint32_t                             SurfaceVerticalAlignment;
#define VALIGN4                                  1
#define VALIGN8                                  2
#define VALIGN16                                 3
   uint32_t                             SurfaceHorizontalAlignment;
#define HALIGN4                                  1
#define HALIGN8                                  2
#define HALIGN16                                 3
   uint32_t                             TileMode;
#define LINEAR                                   0
#define WMAJOR                                   1
#define XMAJOR                                   2
#define YMAJOR                                   3
   uint32_t                             VerticalLineStride;
   uint32_t                             VerticalLineStrideOffset;
   bool                                 SamplerL2BypassModeDisable;
   uint32_t                             RenderCacheReadWriteMode;
#define WriteOnlyCache                           0
#define ReadWriteCache                           1
   uint32_t                             MediaBoundaryPixelMode;
#define NORMAL_MODE                              0
#define PROGRESSIVE_FRAME                        2
#define INTERLACED_FRAME                         3
   bool                                 CubeFaceEnablePositiveZ;
   bool                                 CubeFaceEnableNegativeZ;
   bool                                 CubeFaceEnablePositiveY;
   bool                                 CubeFaceEnableNegativeY;
   bool                                 CubeFaceEnablePositiveX;
   bool                                 CubeFaceEnableNegativeX;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE MemoryObjectControlState;
   uint32_t                             MOCS;
   float                                BaseMipLevel;
   uint32_t                             SurfaceQPitch;
   uint32_t                             Height;
   uint32_t                             Width;
   uint32_t                             Depth;
   uint32_t                             SurfacePitch;
   uint32_t                             RenderTargetAndSampleUnormRotation;
#define _0DEG                                    0
#define _90DEG                                   1
#define _270DEG                                  3
   uint32_t                             MinimumArrayElement;
   uint32_t                             RenderTargetViewExtent;
   uint32_t                             MultisampledSurfaceStorageFormat;
#define MSFMT_MSS                                0
#define MSFMT_DEPTH_STENCIL                      1
   uint32_t                             NumberofMultisamples;
#define MULTISAMPLECOUNT_1                       0
#define MULTISAMPLECOUNT_2                       1
#define MULTISAMPLECOUNT_4                       2
#define MULTISAMPLECOUNT_8                       3
   uint32_t                             MultisamplePositionPaletteIndex;
   uint32_t                             XOffset;
   uint32_t                             YOffset;
   bool                                 EWADisableForCube;
   uint32_t                             CoherencyType;
#define GPUcoherent                              0
#define IAcoherent                               1
   uint32_t                             SurfaceMinLOD;
   uint32_t                             MIPCountLOD;
   uint32_t                             AuxiliarySurfaceQPitch;
   uint32_t                             AuxiliarySurfacePitch;
   uint32_t                             AuxiliarySurfaceMode;
#define AUX_NONE                                 0
#define AUX_MCS                                  1
#define AUX_APPEND                               2
#define AUX_HIZ                                  3
   bool                                 SeparateUVPlaneEnable;
   uint32_t                             XOffsetforUorUVPlane;
   uint32_t                             YOffsetforUorUVPlane;
   uint32_t                             RedClearColor;
   uint32_t                             GreenClearColor;
   uint32_t                             BlueClearColor;
   uint32_t                             AlphaClearColor;
   uint32_t                             ShaderChannelSelectRed;
   uint32_t                             ShaderChannelSelectGreen;
   uint32_t                             ShaderChannelSelectBlue;
   uint32_t                             ShaderChannelSelectAlpha;
   float                                ResourceMinLOD;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             XOffsetforVPlane;
   uint32_t                             YOffsetforVPlane;
   uint32_t                             AuxiliaryTableIndexforMediaCompressedSurface;
   __gen_address_type                   AuxiliarySurfaceBaseAddress;
};

static inline void
GEN8_RENDER_SURFACE_STATE_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_RENDER_SURFACE_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->SurfaceType, 29, 31) |
      __gen_uint(values->SurfaceArray, 28, 28) |
      __gen_uint(values->SurfaceFormat, 18, 26) |
      __gen_uint(values->SurfaceVerticalAlignment, 16, 17) |
      __gen_uint(values->SurfaceHorizontalAlignment, 14, 15) |
      __gen_uint(values->TileMode, 12, 13) |
      __gen_uint(values->VerticalLineStride, 11, 11) |
      __gen_uint(values->VerticalLineStrideOffset, 10, 10) |
      __gen_uint(values->SamplerL2BypassModeDisable, 9, 9) |
      __gen_uint(values->RenderCacheReadWriteMode, 8, 8) |
      __gen_uint(values->MediaBoundaryPixelMode, 6, 7) |
      __gen_uint(values->CubeFaceEnablePositiveZ, 0, 0) |
      __gen_uint(values->CubeFaceEnableNegativeZ, 1, 1) |
      __gen_uint(values->CubeFaceEnablePositiveY, 2, 2) |
      __gen_uint(values->CubeFaceEnableNegativeY, 3, 3) |
      __gen_uint(values->CubeFaceEnablePositiveX, 4, 4) |
      __gen_uint(values->CubeFaceEnableNegativeX, 5, 5);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->MemoryObjectControlState);

   dw[1] =
      __gen_uint(v1_0, 24, 30) |
      __gen_uint(values->MOCS, 24, 30) |
      __gen_ufixed(values->BaseMipLevel, 19, 23, 1) |
      __gen_uint(values->SurfaceQPitch, 0, 14);

   dw[2] =
      __gen_uint(values->Height, 16, 29) |
      __gen_uint(values->Width, 0, 13);

   dw[3] =
      __gen_uint(values->Depth, 21, 31) |
      __gen_uint(values->SurfacePitch, 0, 17);

   dw[4] =
      __gen_uint(values->RenderTargetAndSampleUnormRotation, 29, 30) |
      __gen_uint(values->MinimumArrayElement, 18, 28) |
      __gen_uint(values->RenderTargetViewExtent, 7, 17) |
      __gen_uint(values->MultisampledSurfaceStorageFormat, 6, 6) |
      __gen_uint(values->NumberofMultisamples, 3, 5) |
      __gen_uint(values->MultisamplePositionPaletteIndex, 0, 2);

   dw[5] =
      __gen_uint(values->XOffset, 25, 31) |
      __gen_uint(values->YOffset, 21, 23) |
      __gen_uint(values->EWADisableForCube, 20, 20) |
      __gen_uint(values->CoherencyType, 14, 14) |
      __gen_uint(values->SurfaceMinLOD, 4, 7) |
      __gen_uint(values->MIPCountLOD, 0, 3);

   dw[6] =
      __gen_uint(values->AuxiliarySurfaceQPitch, 16, 30) |
      __gen_uint(values->AuxiliarySurfacePitch, 3, 11) |
      __gen_uint(values->AuxiliarySurfaceMode, 0, 2) |
      __gen_uint(values->SeparateUVPlaneEnable, 31, 31) |
      __gen_uint(values->XOffsetforUorUVPlane, 16, 29) |
      __gen_uint(values->YOffsetforUorUVPlane, 0, 13);

   dw[7] =
      __gen_uint(values->RedClearColor, 31, 31) |
      __gen_uint(values->GreenClearColor, 30, 30) |
      __gen_uint(values->BlueClearColor, 29, 29) |
      __gen_uint(values->AlphaClearColor, 28, 28) |
      __gen_uint(values->ShaderChannelSelectRed, 25, 27) |
      __gen_uint(values->ShaderChannelSelectGreen, 22, 24) |
      __gen_uint(values->ShaderChannelSelectBlue, 19, 21) |
      __gen_uint(values->ShaderChannelSelectAlpha, 16, 18) |
      __gen_ufixed(values->ResourceMinLOD, 0, 11, 8);

   const uint64_t v8_address =
      __gen_combine_address(data, &dw[8], values->SurfaceBaseAddress, 0);
   dw[8] = v8_address;
   dw[9] = v8_address >> 32;

   const uint64_t v10 =
      __gen_uint(values->AuxiliaryTableIndexforMediaCompressedSurface, 21, 31) |
      __gen_uint(values->XOffsetforVPlane, 48, 61) |
      __gen_uint(values->YOffsetforVPlane, 32, 45);
   const uint64_t v10_address =
      __gen_combine_address(data, &dw[10], values->AuxiliarySurfaceBaseAddress, v10);
   dw[10] = v10_address;
   dw[11] = v10_address >> 32;

   dw[12] = 0;

   dw[13] = 0;

   dw[14] = 0;

   dw[15] = 0;
}

#define GEN8_FILTER_COEFFICIENT_length         1
struct GEN8_FILTER_COEFFICIENT {
   float                                FilterCoefficient;
};

static inline void
GEN8_FILTER_COEFFICIENT_pack(__gen_user_data *data, void * restrict dst,
                             const struct GEN8_FILTER_COEFFICIENT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_sfixed(values->FilterCoefficient, 0, 7, 6);
}

#define GEN8_SAMPLER_BORDER_COLOR_STATE_length      4
struct GEN8_SAMPLER_BORDER_COLOR_STATE {
   float                                BorderColorFloatRed;
   float                                BorderColorFloatGreen;
   float                                BorderColorFloatBlue;
   float                                BorderColorFloatAlpha;
   uint32_t                             BorderColor32bitRed;
   uint32_t                             BorderColor32bitGreen;
   uint32_t                             BorderColor32bitBlue;
   uint32_t                             BorderColor32bitAlpha;
};

static inline void
GEN8_SAMPLER_BORDER_COLOR_STATE_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_SAMPLER_BORDER_COLOR_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_float(values->BorderColorFloatRed) |
      __gen_uint(values->BorderColor32bitRed, 0, 31);

   dw[1] =
      __gen_float(values->BorderColorFloatGreen) |
      __gen_uint(values->BorderColor32bitGreen, 0, 31);

   dw[2] =
      __gen_float(values->BorderColorFloatBlue) |
      __gen_uint(values->BorderColor32bitBlue, 0, 31);

   dw[3] =
      __gen_float(values->BorderColorFloatAlpha) |
      __gen_uint(values->BorderColor32bitAlpha, 0, 31);
}

#define GEN8_SAMPLER_STATE_length              4
struct GEN8_SAMPLER_STATE {
   bool                                 SamplerDisable;
   uint32_t                             TextureBorderColorMode;
#define DX10OGL                                  0
#define DX9                                      1
   uint32_t                             LODPreClampMode;
#define CLAMP_MODE_NONE                          0
#define CLAMP_MODE_OGL                           2
   float                                BaseMipLevel;
   uint32_t                             MipModeFilter;
#define MIPFILTER_NONE                           0
#define MIPFILTER_NEAREST                        1
#define MIPFILTER_LINEAR                         3
   uint32_t                             MagModeFilter;
#define MAPFILTER_NEAREST                        0
#define MAPFILTER_LINEAR                         1
#define MAPFILTER_ANISOTROPIC                    2
#define MAPFILTER_MONO                           6
   uint32_t                             MinModeFilter;
#define MAPFILTER_NEAREST                        0
#define MAPFILTER_LINEAR                         1
#define MAPFILTER_ANISOTROPIC                    2
#define MAPFILTER_MONO                           6
   float                                TextureLODBias;
   uint32_t                             AnisotropicAlgorithm;
#define LEGACY                                   0
#define EWAApproximation                         1
   float                                MinLOD;
   float                                MaxLOD;
   bool                                 ChromaKeyEnable;
   uint32_t                             ChromaKeyIndex;
   uint32_t                             ChromaKeyMode;
#define KEYFILTER_KILL_ON_ANY_MATCH              0
#define KEYFILTER_REPLACE_BLACK                  1
   uint32_t                             ShadowFunction;
#define PREFILTEROPALWAYS                        0
#define PREFILTEROPNEVER                         1
#define PREFILTEROPLESS                          2
#define PREFILTEROPEQUAL                         3
#define PREFILTEROPLEQUAL                        4
#define PREFILTEROPGREATER                       5
#define PREFILTEROPNOTEQUAL                      6
#define PREFILTEROPGEQUAL                        7
   uint32_t                             CubeSurfaceControlMode;
#define PROGRAMMED                               0
#define OVERRIDE                                 1
   uint64_t                             BorderColorPointer;
   uint32_t                             LODClampMagnificationMode;
#define MIPNONE                                  0
#define MIPFILTER                                1
   uint32_t                             MaximumAnisotropy;
#define RATIO21                                  0
#define RATIO41                                  1
#define RATIO61                                  2
#define RATIO81                                  3
#define RATIO101                                 4
#define RATIO121                                 5
#define RATIO141                                 6
#define RATIO161                                 7
   bool                                 RAddressMinFilterRoundingEnable;
   bool                                 RAddressMagFilterRoundingEnable;
   bool                                 VAddressMinFilterRoundingEnable;
   bool                                 VAddressMagFilterRoundingEnable;
   bool                                 UAddressMinFilterRoundingEnable;
   bool                                 UAddressMagFilterRoundingEnable;
   uint32_t                             TrilinearFilterQuality;
#define FULL                                     0
#define HIGH                                     1
#define MED                                      2
#define LOW                                      3
   bool                                 NonnormalizedCoordinateEnable;
   uint32_t                             TCXAddressControlMode;
   uint32_t                             TCYAddressControlMode;
   uint32_t                             TCZAddressControlMode;
};

static inline void
GEN8_SAMPLER_STATE_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_SAMPLER_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->SamplerDisable, 31, 31) |
      __gen_uint(values->TextureBorderColorMode, 29, 29) |
      __gen_uint(values->LODPreClampMode, 27, 28) |
      __gen_ufixed(values->BaseMipLevel, 22, 26, 1) |
      __gen_uint(values->MipModeFilter, 20, 21) |
      __gen_uint(values->MagModeFilter, 17, 19) |
      __gen_uint(values->MinModeFilter, 14, 16) |
      __gen_sfixed(values->TextureLODBias, 1, 13, 8) |
      __gen_uint(values->AnisotropicAlgorithm, 0, 0);

   dw[1] =
      __gen_ufixed(values->MinLOD, 20, 31, 8) |
      __gen_ufixed(values->MaxLOD, 8, 19, 8) |
      __gen_uint(values->ChromaKeyEnable, 7, 7) |
      __gen_uint(values->ChromaKeyIndex, 5, 6) |
      __gen_uint(values->ChromaKeyMode, 4, 4) |
      __gen_uint(values->ShadowFunction, 1, 3) |
      __gen_uint(values->CubeSurfaceControlMode, 0, 0);

   dw[2] =
      __gen_offset(values->BorderColorPointer, 6, 23) |
      __gen_uint(values->LODClampMagnificationMode, 0, 0);

   dw[3] =
      __gen_uint(values->MaximumAnisotropy, 19, 21) |
      __gen_uint(values->RAddressMinFilterRoundingEnable, 13, 13) |
      __gen_uint(values->RAddressMagFilterRoundingEnable, 14, 14) |
      __gen_uint(values->VAddressMinFilterRoundingEnable, 15, 15) |
      __gen_uint(values->VAddressMagFilterRoundingEnable, 16, 16) |
      __gen_uint(values->UAddressMinFilterRoundingEnable, 17, 17) |
      __gen_uint(values->UAddressMagFilterRoundingEnable, 18, 18) |
      __gen_uint(values->TrilinearFilterQuality, 11, 12) |
      __gen_uint(values->NonnormalizedCoordinateEnable, 10, 10) |
      __gen_uint(values->TCXAddressControlMode, 6, 8) |
      __gen_uint(values->TCYAddressControlMode, 3, 5) |
      __gen_uint(values->TCZAddressControlMode, 0, 2);
}

#define GEN8_SAMPLER_STATE_8X8_AVS_COEFFICIENTS_length      8
struct GEN8_SAMPLER_STATE_8X8_AVS_COEFFICIENTS {
   float                                Table0YFilterCoefficientn1;
   float                                Table0XFilterCoefficientn1;
   float                                Table0YFilterCoefficientn0;
   float                                Table0XFilterCoefficientn0;
   float                                Table0YFilterCoefficientn3;
   float                                Table0XFilterCoefficientn3;
   float                                Table0YFilterCoefficientn2;
   float                                Table0XFilterCoefficientn2;
   float                                Table0YFilterCoefficientn5;
   float                                Table0XFilterCoefficientn5;
   float                                Table0YFilterCoefficientn4;
   float                                Table0XFilterCoefficientn4;
   float                                Table0YFilterCoefficientn7;
   float                                Table0XFilterCoefficientn7;
   float                                Table0YFilterCoefficientn6;
   float                                Table0XFilterCoefficientn6;
   float                                Table1XFilterCoefficientn3;
   float                                Table1XFilterCoefficientn2;
   float                                Table1XFilterCoefficientn5;
   float                                Table1XFilterCoefficientn4;
   float                                Table1YFilterCoefficientn3;
   float                                Table1YFilterCoefficientn2;
   float                                Table1YFilterCoefficientn5;
   float                                Table1YFilterCoefficientn4;
};

static inline void
GEN8_SAMPLER_STATE_8X8_AVS_COEFFICIENTS_pack(__gen_user_data *data, void * restrict dst,
                                             const struct GEN8_SAMPLER_STATE_8X8_AVS_COEFFICIENTS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_sfixed(values->Table0YFilterCoefficientn1, 24, 31, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn1, 16, 23, 6) |
      __gen_sfixed(values->Table0YFilterCoefficientn0, 8, 15, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn0, 0, 7, 6);

   dw[1] =
      __gen_sfixed(values->Table0YFilterCoefficientn3, 24, 31, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn3, 16, 23, 6) |
      __gen_sfixed(values->Table0YFilterCoefficientn2, 8, 15, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn2, 0, 7, 6);

   dw[2] =
      __gen_sfixed(values->Table0YFilterCoefficientn5, 24, 31, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn5, 16, 23, 6) |
      __gen_sfixed(values->Table0YFilterCoefficientn4, 8, 15, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn4, 0, 7, 6);

   dw[3] =
      __gen_sfixed(values->Table0YFilterCoefficientn7, 24, 31, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn7, 16, 23, 6) |
      __gen_sfixed(values->Table0YFilterCoefficientn6, 8, 15, 6) |
      __gen_sfixed(values->Table0XFilterCoefficientn6, 0, 7, 6);

   dw[4] =
      __gen_sfixed(values->Table1XFilterCoefficientn3, 24, 31, 6) |
      __gen_sfixed(values->Table1XFilterCoefficientn2, 16, 23, 6);

   dw[5] =
      __gen_sfixed(values->Table1XFilterCoefficientn5, 8, 15, 6) |
      __gen_sfixed(values->Table1XFilterCoefficientn4, 0, 7, 6);

   dw[6] =
      __gen_sfixed(values->Table1YFilterCoefficientn3, 24, 31, 6) |
      __gen_sfixed(values->Table1YFilterCoefficientn2, 16, 23, 6);

   dw[7] =
      __gen_sfixed(values->Table1YFilterCoefficientn5, 8, 15, 6) |
      __gen_sfixed(values->Table1YFilterCoefficientn4, 0, 7, 6);
}

#define GEN8_3DPRIMITIVE_length                7
#define GEN8_3DPRIMITIVE_length_bias           2
#define GEN8_3DPRIMITIVE_header                 \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      3,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      5

struct GEN8_3DPRIMITIVE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   bool                                 IndirectParameterEnable;
   bool                                 UAVCoherencyRequired;
   bool                                 PredicateEnable;
   uint32_t                             DWordLength;
   bool                                 EndOffsetEnable;
   uint32_t                             VertexAccessType;
#define SEQUENTIAL                               0
#define RANDOM                                   1
   enum GEN8_3D_Prim_Topo_Type          PrimitiveTopologyType;
   uint32_t                             VertexCountPerInstance;
   uint32_t                             StartVertexLocation;
   uint32_t                             InstanceCount;
   uint32_t                             StartInstanceLocation;
   int32_t                              BaseVertexLocation;
};

static inline void
GEN8_3DPRIMITIVE_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN8_3DPRIMITIVE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->IndirectParameterEnable, 10, 10) |
      __gen_uint(values->UAVCoherencyRequired, 9, 9) |
      __gen_uint(values->PredicateEnable, 8, 8) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->EndOffsetEnable, 9, 9) |
      __gen_uint(values->VertexAccessType, 8, 8) |
      __gen_uint(values->PrimitiveTopologyType, 0, 5);

   dw[2] =
      __gen_uint(values->VertexCountPerInstance, 0, 31);

   dw[3] =
      __gen_uint(values->StartVertexLocation, 0, 31);

   dw[4] =
      __gen_uint(values->InstanceCount, 0, 31);

   dw[5] =
      __gen_uint(values->StartInstanceLocation, 0, 31);

   dw[6] =
      __gen_sint(values->BaseVertexLocation, 0, 31);
}

#define GEN8_3DSTATE_AA_LINE_PARAMETERS_length      3
#define GEN8_3DSTATE_AA_LINE_PARAMETERS_length_bias      2
#define GEN8_3DSTATE_AA_LINE_PARAMETERS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     10,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_AA_LINE_PARAMETERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   float                                AAPointCoverageBias;
   float                                AACoverageBias;
   float                                AAPointCoverageSlope;
   float                                AACoverageSlope;
   float                                AAPointCoverageEndCapBias;
   float                                AACoverageEndCapBias;
   float                                AAPointCoverageEndCapSlope;
   float                                AACoverageEndCapSlope;
};

static inline void
GEN8_3DSTATE_AA_LINE_PARAMETERS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_3DSTATE_AA_LINE_PARAMETERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_ufixed(values->AAPointCoverageBias, 24, 31, 8) |
      __gen_ufixed(values->AACoverageBias, 16, 23, 8) |
      __gen_ufixed(values->AAPointCoverageSlope, 8, 15, 8) |
      __gen_ufixed(values->AACoverageSlope, 0, 7, 8);

   dw[2] =
      __gen_ufixed(values->AAPointCoverageEndCapBias, 24, 31, 8) |
      __gen_ufixed(values->AACoverageEndCapBias, 16, 23, 8) |
      __gen_ufixed(values->AAPointCoverageEndCapSlope, 8, 15, 8) |
      __gen_ufixed(values->AACoverageEndCapSlope, 0, 7, 8);
}

#define GEN8_3DSTATE_BINDING_TABLE_EDIT_DS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_EDIT_DS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     70,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_EDIT_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             BindingTableBlockClear;
   uint32_t                             BindingTableEditTarget;
#define AllCores                                 3
#define Core1                                    2
#define Core0                                    1
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_EDIT_DS_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_BINDING_TABLE_EDIT_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 8);

   dw[1] =
      __gen_uint(values->BindingTableBlockClear, 16, 31) |
      __gen_uint(values->BindingTableEditTarget, 0, 1);
}

#define GEN8_3DSTATE_BINDING_TABLE_EDIT_GS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_EDIT_GS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     68,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_EDIT_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             BindingTableBlockClear;
   uint32_t                             BindingTableEditTarget;
#define AllCores                                 3
#define Core1                                    2
#define Core0                                    1
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_EDIT_GS_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_BINDING_TABLE_EDIT_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 8);

   dw[1] =
      __gen_uint(values->BindingTableBlockClear, 16, 31) |
      __gen_uint(values->BindingTableEditTarget, 0, 1);
}

#define GEN8_3DSTATE_BINDING_TABLE_EDIT_HS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_EDIT_HS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     69,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_EDIT_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             BindingTableBlockClear;
   uint32_t                             BindingTableEditTarget;
#define AllCores                                 3
#define Core1                                    2
#define Core0                                    1
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_EDIT_HS_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_BINDING_TABLE_EDIT_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 8);

   dw[1] =
      __gen_uint(values->BindingTableBlockClear, 16, 31) |
      __gen_uint(values->BindingTableEditTarget, 0, 1);
}

#define GEN8_3DSTATE_BINDING_TABLE_EDIT_PS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_EDIT_PS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     71,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_EDIT_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             BindingTableBlockClear;
   uint32_t                             BindingTableEditTarget;
#define AllCores                                 3
#define Core1                                    2
#define Core0                                    1
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_EDIT_PS_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_BINDING_TABLE_EDIT_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 8);

   dw[1] =
      __gen_uint(values->BindingTableBlockClear, 16, 31) |
      __gen_uint(values->BindingTableEditTarget, 0, 1);
}

#define GEN8_3DSTATE_BINDING_TABLE_EDIT_VS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_EDIT_VS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     67,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_EDIT_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             BindingTableBlockClear;
   uint32_t                             BindingTableEditTarget;
#define AllCores                                 3
#define Core1                                    2
#define Core0                                    1
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_EDIT_VS_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_BINDING_TABLE_EDIT_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 8);

   dw[1] =
      __gen_uint(values->BindingTableBlockClear, 16, 31) |
      __gen_uint(values->BindingTableEditTarget, 0, 1);
}

#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_DS_length      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_DS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_DS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     40,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoDSBindingTable;
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_POINTERS_DS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoDSBindingTable, 5, 15);
}

#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_GS_length      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_GS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_GS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     41,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoGSBindingTable;
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_POINTERS_GS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoGSBindingTable, 5, 15);
}

#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_HS_length      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_HS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_HS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     39,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoHSBindingTable;
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_POINTERS_HS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoHSBindingTable, 5, 15);
}

#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_PS_length      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_PS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_PS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     42,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoPSBindingTable;
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_POINTERS_PS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoPSBindingTable, 5, 15);
}

#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_VS_length      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_VS_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_POINTERS_VS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     38,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoVSBindingTable;
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_POINTERS_VS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_BINDING_TABLE_POINTERS_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoVSBindingTable, 5, 15);
}

#define GEN8_3DSTATE_BINDING_TABLE_POOL_ALLOC_length      4
#define GEN8_3DSTATE_BINDING_TABLE_POOL_ALLOC_length_bias      2
#define GEN8_3DSTATE_BINDING_TABLE_POOL_ALLOC_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     25,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_BINDING_TABLE_POOL_ALLOC {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   BindingTablePoolBaseAddress;
   uint32_t                             BindingTablePoolEnable;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE SurfaceObjectControlState;
   uint32_t                             BindingTablePoolBufferSize;
#define NoValidData                              0
};

static inline void
GEN8_3DSTATE_BINDING_TABLE_POOL_ALLOC_pack(__gen_user_data *data, void * restrict dst,
                                           const struct GEN8_3DSTATE_BINDING_TABLE_POOL_ALLOC * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->SurfaceObjectControlState);

   const uint64_t v1 =
      __gen_uint(values->BindingTablePoolEnable, 11, 11) |
      __gen_uint(v1_0, 0, 6);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->BindingTablePoolBaseAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   dw[3] =
      __gen_uint(values->BindingTablePoolBufferSize, 12, 31);
}

#define GEN8_3DSTATE_BLEND_STATE_POINTERS_length      2
#define GEN8_3DSTATE_BLEND_STATE_POINTERS_length_bias      2
#define GEN8_3DSTATE_BLEND_STATE_POINTERS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     36,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_BLEND_STATE_POINTERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             BlendStatePointer;
   bool                                 BlendStatePointerValid;
};

static inline void
GEN8_3DSTATE_BLEND_STATE_POINTERS_pack(__gen_user_data *data, void * restrict dst,
                                       const struct GEN8_3DSTATE_BLEND_STATE_POINTERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->BlendStatePointer, 6, 31) |
      __gen_uint(values->BlendStatePointerValid, 0, 0);
}

#define GEN8_3DSTATE_CC_STATE_POINTERS_length      2
#define GEN8_3DSTATE_CC_STATE_POINTERS_length_bias      2
#define GEN8_3DSTATE_CC_STATE_POINTERS_header   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     14,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_CC_STATE_POINTERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             ColorCalcStatePointer;
   bool                                 ColorCalcStatePointerValid;
};

static inline void
GEN8_3DSTATE_CC_STATE_POINTERS_pack(__gen_user_data *data, void * restrict dst,
                                    const struct GEN8_3DSTATE_CC_STATE_POINTERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->ColorCalcStatePointer, 6, 31) |
      __gen_uint(values->ColorCalcStatePointerValid, 0, 0);
}

#define GEN8_3DSTATE_CHROMA_KEY_length         4
#define GEN8_3DSTATE_CHROMA_KEY_length_bias      2
#define GEN8_3DSTATE_CHROMA_KEY_header          \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      4,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_CHROMA_KEY {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ChromaKeyTableIndex;
   uint32_t                             ChromaKeyLowValue;
   uint32_t                             ChromaKeyHighValue;
};

static inline void
GEN8_3DSTATE_CHROMA_KEY_pack(__gen_user_data *data, void * restrict dst,
                             const struct GEN8_3DSTATE_CHROMA_KEY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ChromaKeyTableIndex, 30, 31);

   dw[2] =
      __gen_uint(values->ChromaKeyLowValue, 0, 31);

   dw[3] =
      __gen_uint(values->ChromaKeyHighValue, 0, 31);
}

#define GEN8_3DSTATE_CLEAR_PARAMS_length       3
#define GEN8_3DSTATE_CLEAR_PARAMS_length_bias      2
#define GEN8_3DSTATE_CLEAR_PARAMS_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      4,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_CLEAR_PARAMS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   float                                DepthClearValue;
   bool                                 DepthClearValueValid;
};

static inline void
GEN8_3DSTATE_CLEAR_PARAMS_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_3DSTATE_CLEAR_PARAMS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_float(values->DepthClearValue);

   dw[2] =
      __gen_uint(values->DepthClearValueValid, 0, 0);
}

#define GEN8_3DSTATE_CLIP_length               4
#define GEN8_3DSTATE_CLIP_length_bias          2
#define GEN8_3DSTATE_CLIP_header                \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     18,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_CLIP {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 ForceUserClipDistanceCullTestEnableBitmask;
   uint32_t                             VertexSubPixelPrecisionSelect;
#define _8Bit                                    0
#define _4Bit                                    1
   bool                                 EarlyCullEnable;
   bool                                 ForceUserClipDistanceClipTestEnableBitmask;
   bool                                 ForceClipMode;
   bool                                 StatisticsEnable;
   uint32_t                             UserClipDistanceCullTestEnableBitmask;
   bool                                 ClipEnable;
   uint32_t                             APIMode;
#define APIMODE_OGL                              0
#define APIMODE_D3D                              1
   bool                                 ViewportXYClipTestEnable;
   bool                                 GuardbandClipTestEnable;
   uint32_t                             UserClipDistanceClipTestEnableBitmask;
   uint32_t                             ClipMode;
#define CLIPMODE_NORMAL                          0
#define CLIPMODE_REJECT_ALL                      3
#define CLIPMODE_ACCEPT_ALL                      4
   bool                                 PerspectiveDivideDisable;
   bool                                 NonPerspectiveBarycentricEnable;
   uint32_t                             TriangleStripListProvokingVertexSelect;
   uint32_t                             LineStripListProvokingVertexSelect;
   uint32_t                             TriangleFanProvokingVertexSelect;
   float                                MinimumPointWidth;
   float                                MaximumPointWidth;
   bool                                 ForceZeroRTAIndexEnable;
   uint32_t                             MaximumVPIndex;
};

static inline void
GEN8_3DSTATE_CLIP_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_3DSTATE_CLIP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ForceUserClipDistanceCullTestEnableBitmask, 20, 20) |
      __gen_uint(values->VertexSubPixelPrecisionSelect, 19, 19) |
      __gen_uint(values->EarlyCullEnable, 18, 18) |
      __gen_uint(values->ForceUserClipDistanceClipTestEnableBitmask, 17, 17) |
      __gen_uint(values->ForceClipMode, 16, 16) |
      __gen_uint(values->StatisticsEnable, 10, 10) |
      __gen_uint(values->UserClipDistanceCullTestEnableBitmask, 0, 7);

   dw[2] =
      __gen_uint(values->ClipEnable, 31, 31) |
      __gen_uint(values->APIMode, 30, 30) |
      __gen_uint(values->ViewportXYClipTestEnable, 28, 28) |
      __gen_uint(values->GuardbandClipTestEnable, 26, 26) |
      __gen_uint(values->UserClipDistanceClipTestEnableBitmask, 16, 23) |
      __gen_uint(values->ClipMode, 13, 15) |
      __gen_uint(values->PerspectiveDivideDisable, 9, 9) |
      __gen_uint(values->NonPerspectiveBarycentricEnable, 8, 8) |
      __gen_uint(values->TriangleStripListProvokingVertexSelect, 4, 5) |
      __gen_uint(values->LineStripListProvokingVertexSelect, 2, 3) |
      __gen_uint(values->TriangleFanProvokingVertexSelect, 0, 1);

   dw[3] =
      __gen_ufixed(values->MinimumPointWidth, 17, 27, 3) |
      __gen_ufixed(values->MaximumPointWidth, 6, 16, 3) |
      __gen_uint(values->ForceZeroRTAIndexEnable, 5, 5) |
      __gen_uint(values->MaximumVPIndex, 0, 3);
}

#define GEN8_3DSTATE_CONSTANT_DS_length       11
#define GEN8_3DSTATE_CONSTANT_DS_length_bias      2
#define GEN8_3DSTATE_CONSTANT_DS_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     26,  \
   .DWordLength                         =      9

struct GEN8_3DSTATE_CONSTANT_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE ConstantBufferObjectControlState;
   uint32_t                             DWordLength;
   struct GEN8_3DSTATE_CONSTANT_BODY    ConstantBody;
};

static inline void
GEN8_3DSTATE_CONSTANT_DS_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_CONSTANT_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v0_0, &values->ConstantBufferObjectControlState);

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(v0_0, 8, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   GEN8_3DSTATE_CONSTANT_BODY_pack(data, &dw[1], &values->ConstantBody);
}

#define GEN8_3DSTATE_CONSTANT_GS_length       11
#define GEN8_3DSTATE_CONSTANT_GS_length_bias      2
#define GEN8_3DSTATE_CONSTANT_GS_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     22,  \
   .DWordLength                         =      9

struct GEN8_3DSTATE_CONSTANT_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE ConstantBufferObjectControlState;
   uint32_t                             DWordLength;
   struct GEN8_3DSTATE_CONSTANT_BODY    ConstantBody;
};

static inline void
GEN8_3DSTATE_CONSTANT_GS_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_CONSTANT_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v0_0, &values->ConstantBufferObjectControlState);

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(v0_0, 8, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   GEN8_3DSTATE_CONSTANT_BODY_pack(data, &dw[1], &values->ConstantBody);
}

#define GEN8_3DSTATE_CONSTANT_HS_length       11
#define GEN8_3DSTATE_CONSTANT_HS_length_bias      2
#define GEN8_3DSTATE_CONSTANT_HS_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     25,  \
   .DWordLength                         =      9

struct GEN8_3DSTATE_CONSTANT_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE ConstantBufferObjectControlState;
   uint32_t                             DWordLength;
   struct GEN8_3DSTATE_CONSTANT_BODY    ConstantBody;
};

static inline void
GEN8_3DSTATE_CONSTANT_HS_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_CONSTANT_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v0_0, &values->ConstantBufferObjectControlState);

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(v0_0, 8, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   GEN8_3DSTATE_CONSTANT_BODY_pack(data, &dw[1], &values->ConstantBody);
}

#define GEN8_3DSTATE_CONSTANT_PS_length       11
#define GEN8_3DSTATE_CONSTANT_PS_length_bias      2
#define GEN8_3DSTATE_CONSTANT_PS_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     23,  \
   .DWordLength                         =      9

struct GEN8_3DSTATE_CONSTANT_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE ConstantBufferObjectControlState;
   uint32_t                             DWordLength;
   struct GEN8_3DSTATE_CONSTANT_BODY    ConstantBody;
};

static inline void
GEN8_3DSTATE_CONSTANT_PS_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_CONSTANT_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v0_0, &values->ConstantBufferObjectControlState);

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(v0_0, 8, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   GEN8_3DSTATE_CONSTANT_BODY_pack(data, &dw[1], &values->ConstantBody);
}

#define GEN8_3DSTATE_CONSTANT_VS_length       11
#define GEN8_3DSTATE_CONSTANT_VS_length_bias      2
#define GEN8_3DSTATE_CONSTANT_VS_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     21,  \
   .DWordLength                         =      9

struct GEN8_3DSTATE_CONSTANT_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE ConstantBufferObjectControlState;
   uint32_t                             DWordLength;
   struct GEN8_3DSTATE_CONSTANT_BODY    ConstantBody;
};

static inline void
GEN8_3DSTATE_CONSTANT_VS_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_CONSTANT_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   uint32_t v0_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v0_0, &values->ConstantBufferObjectControlState);

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(v0_0, 8, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   GEN8_3DSTATE_CONSTANT_BODY_pack(data, &dw[1], &values->ConstantBody);
}

#define GEN8_3DSTATE_DEPTH_BUFFER_length       8
#define GEN8_3DSTATE_DEPTH_BUFFER_length_bias      2
#define GEN8_3DSTATE_DEPTH_BUFFER_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      5,  \
   .DWordLength                         =      6

struct GEN8_3DSTATE_DEPTH_BUFFER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             SurfaceType;
#define SURFTYPE_1D                              0
#define SURFTYPE_2D                              1
#define SURFTYPE_3D                              2
#define SURFTYPE_CUBE                            3
#define SURFTYPE_NULL                            7
   bool                                 DepthWriteEnable;
   bool                                 StencilWriteEnable;
   bool                                 HierarchicalDepthBufferEnable;
   uint32_t                             SurfaceFormat;
#define D32_FLOAT                                1
#define D24_UNORM_X8_UINT                        3
#define D16_UNORM                                5
   uint32_t                             SurfacePitch;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             Height;
   uint32_t                             Width;
   uint32_t                             LOD;
   uint32_t                             Depth;
   uint32_t                             MinimumArrayElement;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE DepthBufferObjectControlState;
   uint32_t                             DepthBufferMOCS;
   uint32_t                             RenderTargetViewExtent;
   uint32_t                             SurfaceQPitch;
};

static inline void
GEN8_3DSTATE_DEPTH_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_3DSTATE_DEPTH_BUFFER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->SurfaceType, 29, 31) |
      __gen_uint(values->DepthWriteEnable, 28, 28) |
      __gen_uint(values->StencilWriteEnable, 27, 27) |
      __gen_uint(values->HierarchicalDepthBufferEnable, 22, 22) |
      __gen_uint(values->SurfaceFormat, 18, 20) |
      __gen_uint(values->SurfacePitch, 0, 17);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->SurfaceBaseAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   dw[4] =
      __gen_uint(values->Height, 18, 31) |
      __gen_uint(values->Width, 4, 17) |
      __gen_uint(values->LOD, 0, 3);

   uint32_t v5_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v5_0, &values->DepthBufferObjectControlState);

   dw[5] =
      __gen_uint(values->Depth, 21, 31) |
      __gen_uint(values->MinimumArrayElement, 10, 20) |
      __gen_uint(v5_0, 0, 6) |
      __gen_uint(values->DepthBufferMOCS, 0, 6);

   dw[6] = 0;

   dw[7] =
      __gen_uint(values->RenderTargetViewExtent, 21, 31) |
      __gen_uint(values->SurfaceQPitch, 0, 14);
}

#define GEN8_3DSTATE_DRAWING_RECTANGLE_length      4
#define GEN8_3DSTATE_DRAWING_RECTANGLE_length_bias      2
#define GEN8_3DSTATE_DRAWING_RECTANGLE_header   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_DRAWING_RECTANGLE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             CoreModeSelect;
#define Legacy                                   0
#define Core0Enabled                             1
#define Core1Enabled                             2
   uint32_t                             DWordLength;
   uint32_t                             ClippedDrawingRectangleYMin;
   uint32_t                             ClippedDrawingRectangleXMin;
   uint32_t                             ClippedDrawingRectangleYMax;
   uint32_t                             ClippedDrawingRectangleXMax;
   int32_t                              DrawingRectangleOriginY;
   int32_t                              DrawingRectangleOriginX;
};

static inline void
GEN8_3DSTATE_DRAWING_RECTANGLE_pack(__gen_user_data *data, void * restrict dst,
                                    const struct GEN8_3DSTATE_DRAWING_RECTANGLE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->CoreModeSelect, 14, 15) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ClippedDrawingRectangleYMin, 16, 31) |
      __gen_uint(values->ClippedDrawingRectangleXMin, 0, 15);

   dw[2] =
      __gen_uint(values->ClippedDrawingRectangleYMax, 16, 31) |
      __gen_uint(values->ClippedDrawingRectangleXMax, 0, 15);

   dw[3] =
      __gen_sint(values->DrawingRectangleOriginY, 16, 31) |
      __gen_sint(values->DrawingRectangleOriginX, 0, 15);
}

#define GEN8_3DSTATE_DS_length                 9
#define GEN8_3DSTATE_DS_length_bias            2
#define GEN8_3DSTATE_DS_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     29,  \
   .DWordLength                         =      7

struct GEN8_3DSTATE_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             KernelStartPointer;
   uint32_t                             SingleDomainPointDispatch;
   bool                                 VectorMaskEnable;
   uint32_t                             SamplerCount;
#define NoSamplers                               0
#define _14Samplers                              1
#define _58Samplers                              2
#define _912Samplers                             3
#define _1316Samplers                            4
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadDispatchPriority;
#define High                                     1
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 AccessesUAV;
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   __gen_address_type                   ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             DispatchGRFStartRegisterForURBData;
   uint32_t                             PatchURBEntryReadLength;
   uint32_t                             PatchURBEntryReadOffset;
   uint32_t                             MaximumNumberofThreads;
   bool                                 StatisticsEnable;
   uint32_t                             DispatchMode;
#define DISPATCH_MODE_SIMD4X2                    0
#define DISPATCH_MODE_SIMD8_SINGLE_PATCH         1
   bool                                 ComputeWCoordinateEnable;
   bool                                 CacheDisable;
   bool                                 FunctionEnable;
   uint32_t                             VertexURBEntryOutputReadOffset;
   uint32_t                             VertexURBEntryOutputLength;
   uint32_t                             UserClipDistanceClipTestEnableBitmask;
   uint32_t                             UserClipDistanceCullTestEnableBitmask;
};

static inline void
GEN8_3DSTATE_DS_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1 =
      __gen_offset(values->KernelStartPointer, 6, 63);
   dw[1] = v1;
   dw[2] = v1 >> 32;

   dw[3] =
      __gen_uint(values->SingleDomainPointDispatch, 31, 31) |
      __gen_uint(values->VectorMaskEnable, 30, 30) |
      __gen_uint(values->SamplerCount, 27, 29) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadDispatchPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->AccessesUAV, 14, 14) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   const uint64_t v4 =
      __gen_uint(values->PerThreadScratchSpace, 0, 3);
   const uint64_t v4_address =
      __gen_combine_address(data, &dw[4], values->ScratchSpaceBasePointer, v4);
   dw[4] = v4_address;
   dw[5] = v4_address >> 32;

   dw[6] =
      __gen_uint(values->DispatchGRFStartRegisterForURBData, 20, 24) |
      __gen_uint(values->PatchURBEntryReadLength, 11, 17) |
      __gen_uint(values->PatchURBEntryReadOffset, 4, 9);

   dw[7] =
      __gen_uint(values->MaximumNumberofThreads, 21, 29) |
      __gen_uint(values->StatisticsEnable, 10, 10) |
      __gen_uint(values->DispatchMode, 3, 3) |
      __gen_uint(values->ComputeWCoordinateEnable, 2, 2) |
      __gen_uint(values->CacheDisable, 1, 1) |
      __gen_uint(values->FunctionEnable, 0, 0);

   dw[8] =
      __gen_uint(values->VertexURBEntryOutputReadOffset, 21, 26) |
      __gen_uint(values->VertexURBEntryOutputLength, 16, 20) |
      __gen_uint(values->UserClipDistanceClipTestEnableBitmask, 8, 15) |
      __gen_uint(values->UserClipDistanceCullTestEnableBitmask, 0, 7);
}

#define GEN8_3DSTATE_GATHER_CONSTANT_DS_length_bias      2
#define GEN8_3DSTATE_GATHER_CONSTANT_DS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     55,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_GATHER_CONSTANT_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferValid;
   uint32_t                             ConstantBufferBindingTableBlock;
   uint64_t                             GatherBufferOffset;
   bool                                 ConstantBufferDx9GenerateStall;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_GATHER_CONSTANT_DS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_3DSTATE_GATHER_CONSTANT_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferValid, 16, 31) |
      __gen_uint(values->ConstantBufferBindingTableBlock, 12, 15);

   dw[2] =
      __gen_offset(values->GatherBufferOffset, 6, 22) |
      __gen_uint(values->ConstantBufferDx9GenerateStall, 5, 5);
}

#define GEN8_3DSTATE_GATHER_CONSTANT_GS_length_bias      2
#define GEN8_3DSTATE_GATHER_CONSTANT_GS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     53,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_GATHER_CONSTANT_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferValid;
   uint32_t                             ConstantBufferBindingTableBlock;
   uint64_t                             GatherBufferOffset;
   bool                                 ConstantBufferDx9GenerateStall;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_GATHER_CONSTANT_GS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_3DSTATE_GATHER_CONSTANT_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferValid, 16, 31) |
      __gen_uint(values->ConstantBufferBindingTableBlock, 12, 15);

   dw[2] =
      __gen_offset(values->GatherBufferOffset, 6, 22) |
      __gen_uint(values->ConstantBufferDx9GenerateStall, 5, 5);
}

#define GEN8_3DSTATE_GATHER_CONSTANT_HS_length_bias      2
#define GEN8_3DSTATE_GATHER_CONSTANT_HS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     54,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_GATHER_CONSTANT_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferValid;
   uint32_t                             ConstantBufferBindingTableBlock;
   uint64_t                             GatherBufferOffset;
   bool                                 ConstantBufferDx9GenerateStall;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_GATHER_CONSTANT_HS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_3DSTATE_GATHER_CONSTANT_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferValid, 16, 31) |
      __gen_uint(values->ConstantBufferBindingTableBlock, 12, 15);

   dw[2] =
      __gen_offset(values->GatherBufferOffset, 6, 22) |
      __gen_uint(values->ConstantBufferDx9GenerateStall, 5, 5);
}

#define GEN8_3DSTATE_GATHER_CONSTANT_PS_length_bias      2
#define GEN8_3DSTATE_GATHER_CONSTANT_PS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     56,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_GATHER_CONSTANT_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferValid;
   uint32_t                             ConstantBufferBindingTableBlock;
   uint64_t                             GatherBufferOffset;
   bool                                 ConstantBufferDx9GenerateStall;
   bool                                 ConstantBufferDx9Enable;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_GATHER_CONSTANT_PS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_3DSTATE_GATHER_CONSTANT_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferValid, 16, 31) |
      __gen_uint(values->ConstantBufferBindingTableBlock, 12, 15);

   dw[2] =
      __gen_offset(values->GatherBufferOffset, 6, 22) |
      __gen_uint(values->ConstantBufferDx9GenerateStall, 5, 5) |
      __gen_uint(values->ConstantBufferDx9Enable, 4, 4);
}

#define GEN8_3DSTATE_GATHER_CONSTANT_VS_length_bias      2
#define GEN8_3DSTATE_GATHER_CONSTANT_VS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     52,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_GATHER_CONSTANT_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferValid;
   uint32_t                             ConstantBufferBindingTableBlock;
   uint64_t                             GatherBufferOffset;
   bool                                 ConstantBufferDx9GenerateStall;
   bool                                 ConstantBufferDx9Enable;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_GATHER_CONSTANT_VS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN8_3DSTATE_GATHER_CONSTANT_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferValid, 16, 31) |
      __gen_uint(values->ConstantBufferBindingTableBlock, 12, 15);

   dw[2] =
      __gen_offset(values->GatherBufferOffset, 6, 22) |
      __gen_uint(values->ConstantBufferDx9GenerateStall, 5, 5) |
      __gen_uint(values->ConstantBufferDx9Enable, 4, 4);
}

#define GEN8_3DSTATE_GATHER_POOL_ALLOC_length      4
#define GEN8_3DSTATE_GATHER_POOL_ALLOC_length_bias      2
#define GEN8_3DSTATE_GATHER_POOL_ALLOC_header   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     26,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_GATHER_POOL_ALLOC {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   GatherPoolBaseAddress;
   bool                                 GatherPoolEnable;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE MemoryObjectControlState;
   uint32_t                             GatherPoolBufferSize;
};

static inline void
GEN8_3DSTATE_GATHER_POOL_ALLOC_pack(__gen_user_data *data, void * restrict dst,
                                    const struct GEN8_3DSTATE_GATHER_POOL_ALLOC * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->MemoryObjectControlState);

   const uint64_t v1 =
      __gen_uint(values->GatherPoolEnable, 11, 11) |
      __gen_uint(v1_0, 0, 6);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->GatherPoolBaseAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   dw[3] =
      __gen_uint(values->GatherPoolBufferSize, 12, 31);
}

#define GEN8_3DSTATE_GS_length                10
#define GEN8_3DSTATE_GS_length_bias            2
#define GEN8_3DSTATE_GS_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     17,  \
   .DWordLength                         =      8

struct GEN8_3DSTATE_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             KernelStartPointer;
   bool                                 SingleProgramFlow;
   bool                                 VectorMaskEnable;
   uint32_t                             SamplerCount;
#define NoSamplers                               0
#define _14Samplers                              1
#define _58Samplers                              2
#define _912Samplers                             3
#define _1316Samplers                            4
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadDispatchPriority;
#define High                                     1
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 AccessesUAV;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint32_t                             ExpectedVertexCount;
   __gen_address_type                   ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             OutputVertexSize;
   enum GEN8_3D_Prim_Topo_Type          OutputTopology;
   uint32_t                             VertexURBEntryReadLength;
   bool                                 IncludeVertexHandles;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             DispatchGRFStartRegisterForURBData;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             ControlDataHeaderSize;
   uint32_t                             InstanceControl;
   uint32_t                             DefaultStreamId;
   uint32_t                             DispatchMode;
#define DISPATCH_MODE_DualInstance               1
#define DISPATCH_MODE_DualObject                 2
#define DISPATCH_MODE_SIMD8                      3
   bool                                 StatisticsEnable;
   uint32_t                             InvocationsIncrementValue;
   bool                                 IncludePrimitiveID;
   uint32_t                             Hint;
   uint32_t                             ReorderMode;
#define LEADING                                  0
#define TRAILING                                 1
   bool                                 DiscardAdjacency;
   bool                                 FunctionEnable;
   uint32_t                             ControlDataFormat;
#define CUT                                      0
#define SID                                      1
   bool                                 StaticOutput;
   uint32_t                             StaticOutputVertexCount;
   uint32_t                             VertexURBEntryOutputReadOffset;
   uint32_t                             VertexURBEntryOutputLength;
   uint32_t                             UserClipDistanceClipTestEnableBitmask;
   uint32_t                             UserClipDistanceCullTestEnableBitmask;
};

static inline void
GEN8_3DSTATE_GS_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1 =
      __gen_offset(values->KernelStartPointer, 6, 63);
   dw[1] = v1;
   dw[2] = v1 >> 32;

   dw[3] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->VectorMaskEnable, 30, 30) |
      __gen_uint(values->SamplerCount, 27, 29) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadDispatchPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->AccessesUAV, 12, 12) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7) |
      __gen_uint(values->ExpectedVertexCount, 0, 5);

   const uint64_t v4 =
      __gen_uint(values->PerThreadScratchSpace, 0, 3);
   const uint64_t v4_address =
      __gen_combine_address(data, &dw[4], values->ScratchSpaceBasePointer, v4);
   dw[4] = v4_address;
   dw[5] = v4_address >> 32;

   dw[6] =
      __gen_uint(values->OutputVertexSize, 23, 28) |
      __gen_uint(values->OutputTopology, 17, 22) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->IncludeVertexHandles, 10, 10) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9) |
      __gen_uint(values->DispatchGRFStartRegisterForURBData, 0, 3);

   dw[7] =
      __gen_uint(values->MaximumNumberofThreads, 24, 31) |
      __gen_uint(values->ControlDataHeaderSize, 20, 23) |
      __gen_uint(values->InstanceControl, 15, 19) |
      __gen_uint(values->DefaultStreamId, 13, 14) |
      __gen_uint(values->DispatchMode, 11, 12) |
      __gen_uint(values->StatisticsEnable, 10, 10) |
      __gen_uint(values->InvocationsIncrementValue, 5, 9) |
      __gen_uint(values->IncludePrimitiveID, 4, 4) |
      __gen_uint(values->Hint, 3, 3) |
      __gen_uint(values->ReorderMode, 2, 2) |
      __gen_uint(values->DiscardAdjacency, 1, 1) |
      __gen_uint(values->FunctionEnable, 0, 0);

   dw[8] =
      __gen_uint(values->ControlDataFormat, 31, 31) |
      __gen_uint(values->StaticOutput, 30, 30) |
      __gen_uint(values->StaticOutputVertexCount, 16, 26);

   dw[9] =
      __gen_uint(values->VertexURBEntryOutputReadOffset, 21, 26) |
      __gen_uint(values->VertexURBEntryOutputLength, 16, 20) |
      __gen_uint(values->UserClipDistanceClipTestEnableBitmask, 8, 15) |
      __gen_uint(values->UserClipDistanceCullTestEnableBitmask, 0, 7);
}

#define GEN8_3DSTATE_HIER_DEPTH_BUFFER_length      5
#define GEN8_3DSTATE_HIER_DEPTH_BUFFER_length_bias      2
#define GEN8_3DSTATE_HIER_DEPTH_BUFFER_header   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      7,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_HIER_DEPTH_BUFFER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE HierarchicalDepthBufferObjectControlState;
   uint32_t                             HierarchicalDepthBufferMOCS;
   uint32_t                             SurfacePitch;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             SurfaceQPitch;
};

static inline void
GEN8_3DSTATE_HIER_DEPTH_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                                    const struct GEN8_3DSTATE_HIER_DEPTH_BUFFER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->HierarchicalDepthBufferObjectControlState);

   dw[1] =
      __gen_uint(v1_0, 25, 31) |
      __gen_uint(values->HierarchicalDepthBufferMOCS, 25, 31) |
      __gen_uint(values->SurfacePitch, 0, 16);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->SurfaceBaseAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   dw[4] =
      __gen_uint(values->SurfaceQPitch, 0, 14);
}

#define GEN8_3DSTATE_HS_length                 9
#define GEN8_3DSTATE_HS_length_bias            2
#define GEN8_3DSTATE_HS_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     27,  \
   .DWordLength                         =      7

struct GEN8_3DSTATE_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             SamplerCount;
#define NoSamplers                               0
#define _14Samplers                              1
#define _58Samplers                              2
#define _912Samplers                             3
#define _1316Samplers                            4
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadDispatchPriority;
#define High                                     1
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   bool                                 FunctionEnable;
   bool                                 StatisticsEnable;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             InstanceCount;
   uint64_t                             KernelStartPointer;
   __gen_address_type                   ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   bool                                 SingleProgramFlow;
   bool                                 VectorMaskEnable;
   bool                                 AccessesUAV;
   bool                                 IncludeVertexHandles;
   uint32_t                             DispatchGRFStartRegisterForURBData;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
};

static inline void
GEN8_3DSTATE_HS_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->SamplerCount, 27, 29) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadDispatchPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->SoftwareExceptionEnable, 12, 12);

   dw[2] =
      __gen_uint(values->FunctionEnable, 31, 31) |
      __gen_uint(values->StatisticsEnable, 29, 29) |
      __gen_uint(values->MaximumNumberofThreads, 8, 16) |
      __gen_uint(values->InstanceCount, 0, 3);

   const uint64_t v3 =
      __gen_offset(values->KernelStartPointer, 6, 63);
   dw[3] = v3;
   dw[4] = v3 >> 32;

   const uint64_t v5 =
      __gen_uint(values->PerThreadScratchSpace, 0, 3);
   const uint64_t v5_address =
      __gen_combine_address(data, &dw[5], values->ScratchSpaceBasePointer, v5);
   dw[5] = v5_address;
   dw[6] = v5_address >> 32;

   dw[7] =
      __gen_uint(values->SingleProgramFlow, 27, 27) |
      __gen_uint(values->VectorMaskEnable, 26, 26) |
      __gen_uint(values->AccessesUAV, 25, 25) |
      __gen_uint(values->IncludeVertexHandles, 24, 24) |
      __gen_uint(values->DispatchGRFStartRegisterForURBData, 19, 23) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9);

   dw[8] = 0;
}

#define GEN8_3DSTATE_INDEX_BUFFER_length       5
#define GEN8_3DSTATE_INDEX_BUFFER_length_bias      2
#define GEN8_3DSTATE_INDEX_BUFFER_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     10,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_INDEX_BUFFER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             IndexFormat;
#define INDEX_BYTE                               0
#define INDEX_WORD                               1
#define INDEX_DWORD                              2
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE MemoryObjectControlState;
   __gen_address_type                   BufferStartingAddress;
   uint32_t                             BufferSize;
};

static inline void
GEN8_3DSTATE_INDEX_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_3DSTATE_INDEX_BUFFER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->MemoryObjectControlState);

   dw[1] =
      __gen_uint(values->IndexFormat, 8, 9) |
      __gen_uint(v1_0, 0, 6);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->BufferStartingAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   dw[4] =
      __gen_uint(values->BufferSize, 0, 31);
}

#define GEN8_3DSTATE_LINE_STIPPLE_length       3
#define GEN8_3DSTATE_LINE_STIPPLE_length_bias      2
#define GEN8_3DSTATE_LINE_STIPPLE_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      8,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_LINE_STIPPLE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 ModifyEnableCurrentRepeatCounterCurrentStippleIndex;
   uint32_t                             CurrentRepeatCounter;
   uint32_t                             CurrentStippleIndex;
   uint32_t                             LineStipplePattern;
   float                                LineStippleInverseRepeatCount;
   uint32_t                             LineStippleRepeatCount;
};

static inline void
GEN8_3DSTATE_LINE_STIPPLE_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_3DSTATE_LINE_STIPPLE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ModifyEnableCurrentRepeatCounterCurrentStippleIndex, 31, 31) |
      __gen_uint(values->CurrentRepeatCounter, 21, 29) |
      __gen_uint(values->CurrentStippleIndex, 16, 19) |
      __gen_uint(values->LineStipplePattern, 0, 15);

   dw[2] =
      __gen_ufixed(values->LineStippleInverseRepeatCount, 15, 31, 16) |
      __gen_uint(values->LineStippleRepeatCount, 0, 8);
}

#define GEN8_3DSTATE_MONOFILTER_SIZE_length      2
#define GEN8_3DSTATE_MONOFILTER_SIZE_length_bias      2
#define GEN8_3DSTATE_MONOFILTER_SIZE_header     \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     17,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_MONOFILTER_SIZE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             MonochromeFilterWidth;
   uint32_t                             MonochromeFilterHeight;
};

static inline void
GEN8_3DSTATE_MONOFILTER_SIZE_pack(__gen_user_data *data, void * restrict dst,
                                  const struct GEN8_3DSTATE_MONOFILTER_SIZE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->MonochromeFilterWidth, 3, 5) |
      __gen_uint(values->MonochromeFilterHeight, 0, 2);
}

#define GEN8_3DSTATE_MULTISAMPLE_length        2
#define GEN8_3DSTATE_MULTISAMPLE_length_bias      2
#define GEN8_3DSTATE_MULTISAMPLE_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     13,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_MULTISAMPLE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 PixelPositionOffsetEnable;
   uint32_t                             PixelLocation;
#define CENTER                                   0
#define UL_CORNER                                1
   uint32_t                             NumberofMultisamples;
};

static inline void
GEN8_3DSTATE_MULTISAMPLE_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_MULTISAMPLE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->PixelPositionOffsetEnable, 5, 5) |
      __gen_uint(values->PixelLocation, 4, 4) |
      __gen_uint(values->NumberofMultisamples, 1, 3);
}

#define GEN8_3DSTATE_POLY_STIPPLE_OFFSET_length      2
#define GEN8_3DSTATE_POLY_STIPPLE_OFFSET_length_bias      2
#define GEN8_3DSTATE_POLY_STIPPLE_OFFSET_header \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      6,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_POLY_STIPPLE_OFFSET {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             PolygonStippleXOffset;
   uint32_t                             PolygonStippleYOffset;
};

static inline void
GEN8_3DSTATE_POLY_STIPPLE_OFFSET_pack(__gen_user_data *data, void * restrict dst,
                                      const struct GEN8_3DSTATE_POLY_STIPPLE_OFFSET * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->PolygonStippleXOffset, 8, 12) |
      __gen_uint(values->PolygonStippleYOffset, 0, 4);
}

#define GEN8_3DSTATE_POLY_STIPPLE_PATTERN_length     33
#define GEN8_3DSTATE_POLY_STIPPLE_PATTERN_length_bias      2
#define GEN8_3DSTATE_POLY_STIPPLE_PATTERN_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      7,  \
   .DWordLength                         =     31

struct GEN8_3DSTATE_POLY_STIPPLE_PATTERN {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             PatternRow[32];
};

static inline void
GEN8_3DSTATE_POLY_STIPPLE_PATTERN_pack(__gen_user_data *data, void * restrict dst,
                                       const struct GEN8_3DSTATE_POLY_STIPPLE_PATTERN * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->PatternRow[0], 0, 31);

   dw[2] =
      __gen_uint(values->PatternRow[1], 0, 31);

   dw[3] =
      __gen_uint(values->PatternRow[2], 0, 31);

   dw[4] =
      __gen_uint(values->PatternRow[3], 0, 31);

   dw[5] =
      __gen_uint(values->PatternRow[4], 0, 31);

   dw[6] =
      __gen_uint(values->PatternRow[5], 0, 31);

   dw[7] =
      __gen_uint(values->PatternRow[6], 0, 31);

   dw[8] =
      __gen_uint(values->PatternRow[7], 0, 31);

   dw[9] =
      __gen_uint(values->PatternRow[8], 0, 31);

   dw[10] =
      __gen_uint(values->PatternRow[9], 0, 31);

   dw[11] =
      __gen_uint(values->PatternRow[10], 0, 31);

   dw[12] =
      __gen_uint(values->PatternRow[11], 0, 31);

   dw[13] =
      __gen_uint(values->PatternRow[12], 0, 31);

   dw[14] =
      __gen_uint(values->PatternRow[13], 0, 31);

   dw[15] =
      __gen_uint(values->PatternRow[14], 0, 31);

   dw[16] =
      __gen_uint(values->PatternRow[15], 0, 31);

   dw[17] =
      __gen_uint(values->PatternRow[16], 0, 31);

   dw[18] =
      __gen_uint(values->PatternRow[17], 0, 31);

   dw[19] =
      __gen_uint(values->PatternRow[18], 0, 31);

   dw[20] =
      __gen_uint(values->PatternRow[19], 0, 31);

   dw[21] =
      __gen_uint(values->PatternRow[20], 0, 31);

   dw[22] =
      __gen_uint(values->PatternRow[21], 0, 31);

   dw[23] =
      __gen_uint(values->PatternRow[22], 0, 31);

   dw[24] =
      __gen_uint(values->PatternRow[23], 0, 31);

   dw[25] =
      __gen_uint(values->PatternRow[24], 0, 31);

   dw[26] =
      __gen_uint(values->PatternRow[25], 0, 31);

   dw[27] =
      __gen_uint(values->PatternRow[26], 0, 31);

   dw[28] =
      __gen_uint(values->PatternRow[27], 0, 31);

   dw[29] =
      __gen_uint(values->PatternRow[28], 0, 31);

   dw[30] =
      __gen_uint(values->PatternRow[29], 0, 31);

   dw[31] =
      __gen_uint(values->PatternRow[30], 0, 31);

   dw[32] =
      __gen_uint(values->PatternRow[31], 0, 31);
}

#define GEN8_3DSTATE_PS_length                12
#define GEN8_3DSTATE_PS_length_bias            2
#define GEN8_3DSTATE_PS_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     32,  \
   .DWordLength                         =     10

struct GEN8_3DSTATE_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             KernelStartPointer0;
   bool                                 SingleProgramFlow;
   bool                                 VectorMaskEnable;
   uint32_t                             SamplerCount;
#define NoSamplers                               0
#define _14Samplers                              1
#define _58Samplers                              2
#define _912Samplers                             3
#define _1316Samplers                            4
   uint32_t                             SinglePrecisionDenormalMode;
#define FlushedtoZero                            0
#define Retained                                 1
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadDispatchPriority;
#define High                                     1
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   uint32_t                             RoundingMode;
#define RTNE                                     0
#define RU                                       1
#define RD                                       2
#define RTZ                                      3
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   __gen_address_type                   ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             MaximumNumberofThreadsPerPSD;
   bool                                 PushConstantEnable;
   bool                                 RenderTargetFastClearEnable;
   bool                                 RenderTargetResolveEnable;
   uint32_t                             PositionXYOffsetSelect;
#define POSOFFSET_NONE                           0
#define POSOFFSET_CENTROID                       2
#define POSOFFSET_SAMPLE                         3
   bool                                 _32PixelDispatchEnable;
   bool                                 _16PixelDispatchEnable;
   bool                                 _8PixelDispatchEnable;
   uint32_t                             DispatchGRFStartRegisterForConstantSetupData0;
   uint32_t                             DispatchGRFStartRegisterForConstantSetupData1;
   uint32_t                             DispatchGRFStartRegisterForConstantSetupData2;
   uint64_t                             KernelStartPointer1;
   uint64_t                             KernelStartPointer2;
};

static inline void
GEN8_3DSTATE_PS_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1 =
      __gen_offset(values->KernelStartPointer0, 6, 63);
   dw[1] = v1;
   dw[2] = v1 >> 32;

   dw[3] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->VectorMaskEnable, 30, 30) |
      __gen_uint(values->SamplerCount, 27, 29) |
      __gen_uint(values->SinglePrecisionDenormalMode, 26, 26) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadDispatchPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->RoundingMode, 14, 15) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   const uint64_t v4 =
      __gen_uint(values->PerThreadScratchSpace, 0, 3);
   const uint64_t v4_address =
      __gen_combine_address(data, &dw[4], values->ScratchSpaceBasePointer, v4);
   dw[4] = v4_address;
   dw[5] = v4_address >> 32;

   dw[6] =
      __gen_uint(values->MaximumNumberofThreadsPerPSD, 23, 31) |
      __gen_uint(values->PushConstantEnable, 11, 11) |
      __gen_uint(values->RenderTargetFastClearEnable, 8, 8) |
      __gen_uint(values->RenderTargetResolveEnable, 6, 6) |
      __gen_uint(values->PositionXYOffsetSelect, 3, 4) |
      __gen_uint(values->_32PixelDispatchEnable, 2, 2) |
      __gen_uint(values->_16PixelDispatchEnable, 1, 1) |
      __gen_uint(values->_8PixelDispatchEnable, 0, 0);

   dw[7] =
      __gen_uint(values->DispatchGRFStartRegisterForConstantSetupData0, 16, 22) |
      __gen_uint(values->DispatchGRFStartRegisterForConstantSetupData1, 8, 14) |
      __gen_uint(values->DispatchGRFStartRegisterForConstantSetupData2, 0, 6);

   const uint64_t v8 =
      __gen_offset(values->KernelStartPointer1, 6, 63);
   dw[8] = v8;
   dw[9] = v8 >> 32;

   const uint64_t v10 =
      __gen_offset(values->KernelStartPointer2, 6, 63);
   dw[10] = v10;
   dw[11] = v10 >> 32;
}

#define GEN8_3DSTATE_PS_BLEND_length           2
#define GEN8_3DSTATE_PS_BLEND_length_bias      2
#define GEN8_3DSTATE_PS_BLEND_header            \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     77,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PS_BLEND {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 AlphaToCoverageEnable;
   bool                                 HasWriteableRT;
   bool                                 ColorBufferBlendEnable;
   uint32_t                             SourceAlphaBlendFactor;
   uint32_t                             DestinationAlphaBlendFactor;
   uint32_t                             SourceBlendFactor;
   uint32_t                             DestinationBlendFactor;
   bool                                 AlphaTestEnable;
   bool                                 IndependentAlphaBlendEnable;
};

static inline void
GEN8_3DSTATE_PS_BLEND_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_3DSTATE_PS_BLEND * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->AlphaToCoverageEnable, 31, 31) |
      __gen_uint(values->HasWriteableRT, 30, 30) |
      __gen_uint(values->ColorBufferBlendEnable, 29, 29) |
      __gen_uint(values->SourceAlphaBlendFactor, 24, 28) |
      __gen_uint(values->DestinationAlphaBlendFactor, 19, 23) |
      __gen_uint(values->SourceBlendFactor, 14, 18) |
      __gen_uint(values->DestinationBlendFactor, 9, 13) |
      __gen_uint(values->AlphaTestEnable, 8, 8) |
      __gen_uint(values->IndependentAlphaBlendEnable, 7, 7);
}

#define GEN8_3DSTATE_PS_EXTRA_length           2
#define GEN8_3DSTATE_PS_EXTRA_length_bias      2
#define GEN8_3DSTATE_PS_EXTRA_header            \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     79,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PS_EXTRA {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 PixelShaderValid;
   bool                                 PixelShaderDoesnotwritetoRT;
   bool                                 oMaskPresenttoRenderTarget;
   bool                                 PixelShaderKillsPixel;
   uint32_t                             PixelShaderComputedDepthMode;
#define PSCDEPTH_OFF                             0
#define PSCDEPTH_ON                              1
#define PSCDEPTH_ON_GE                           2
#define PSCDEPTH_ON_LE                           3
   bool                                 ForceComputedDepth;
   bool                                 PixelShaderUsesSourceDepth;
   bool                                 PixelShaderUsesSourceW;
   bool                                 AttributeEnable;
   bool                                 PixelShaderDisablesAlphaToCoverage;
   bool                                 PixelShaderIsPerSample;
   bool                                 PixelShaderHasUAV;
   bool                                 PixelShaderUsesInputCoverageMask;
};

static inline void
GEN8_3DSTATE_PS_EXTRA_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_3DSTATE_PS_EXTRA * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->PixelShaderValid, 31, 31) |
      __gen_uint(values->PixelShaderDoesnotwritetoRT, 30, 30) |
      __gen_uint(values->oMaskPresenttoRenderTarget, 29, 29) |
      __gen_uint(values->PixelShaderKillsPixel, 28, 28) |
      __gen_uint(values->PixelShaderComputedDepthMode, 26, 27) |
      __gen_uint(values->ForceComputedDepth, 25, 25) |
      __gen_uint(values->PixelShaderUsesSourceDepth, 24, 24) |
      __gen_uint(values->PixelShaderUsesSourceW, 23, 23) |
      __gen_uint(values->AttributeEnable, 8, 8) |
      __gen_uint(values->PixelShaderDisablesAlphaToCoverage, 7, 7) |
      __gen_uint(values->PixelShaderIsPerSample, 6, 6) |
      __gen_uint(values->PixelShaderHasUAV, 2, 2) |
      __gen_uint(values->PixelShaderUsesInputCoverageMask, 1, 1);
}

#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_DS_length      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_DS_length_bias      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_DS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     20,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferOffset;
   uint32_t                             ConstantBufferSize;
};

static inline void
GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_DS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferOffset, 16, 20) |
      __gen_uint(values->ConstantBufferSize, 0, 5);
}

#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_GS_length      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_GS_length_bias      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_GS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     21,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferOffset;
   uint32_t                             ConstantBufferSize;
};

static inline void
GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_GS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferOffset, 16, 20) |
      __gen_uint(values->ConstantBufferSize, 0, 5);
}

#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_HS_length      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_HS_length_bias      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_HS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     19,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferOffset;
   uint32_t                             ConstantBufferSize;
};

static inline void
GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_HS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferOffset, 16, 20) |
      __gen_uint(values->ConstantBufferSize, 0, 5);
}

#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_PS_length      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_PS_length_bias      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_PS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     22,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferOffset;
   uint32_t                             ConstantBufferSize;
};

static inline void
GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_PS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferOffset, 16, 20) |
      __gen_uint(values->ConstantBufferSize, 0, 5);
}

#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_VS_length      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_VS_length_bias      2
#define GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_VS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     18,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ConstantBufferOffset;
   uint32_t                             ConstantBufferSize;
};

static inline void
GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_VS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN8_3DSTATE_PUSH_CONSTANT_ALLOC_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ConstantBufferOffset, 16, 20) |
      __gen_uint(values->ConstantBufferSize, 0, 5);
}

#define GEN8_3DSTATE_RASTER_length             5
#define GEN8_3DSTATE_RASTER_length_bias        2
#define GEN8_3DSTATE_RASTER_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     80,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_RASTER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             APIMode;
#define DX9OGL                                   0
#define DX100                                    1
#define DX101                                    2
   uint32_t                             FrontWinding;
#define Clockwise                                0
#define CounterClockwise                         1
   uint32_t                             ForcedSampleCount;
#define FSC_NUMRASTSAMPLES_0                     0
#define FSC_NUMRASTSAMPLES_1                     1
#define FSC_NUMRASTSAMPLES_2                     2
#define FSC_NUMRASTSAMPLES_4                     3
#define FSC_NUMRASTSAMPLES_8                     4
#define FSC_NUMRASTSAMPLES_16                    5
   uint32_t                             CullMode;
#define CULLMODE_BOTH                            0
#define CULLMODE_NONE                            1
#define CULLMODE_FRONT                           2
#define CULLMODE_BACK                            3
   uint32_t                             ForceMultisampling;
   bool                                 SmoothPointEnable;
   bool                                 DXMultisampleRasterizationEnable;
   uint32_t                             DXMultisampleRasterizationMode;
#define MSRASTMODE_OFF_PIXEL                     0
#define MSRASTMODE_OFF_PATTERN                   1
#define MSRASTMODE_ON_PIXEL                      2
#define MSRASTMODE_ON_PATTERN                    3
   bool                                 GlobalDepthOffsetEnableSolid;
   bool                                 GlobalDepthOffsetEnableWireframe;
   bool                                 GlobalDepthOffsetEnablePoint;
   uint32_t                             FrontFaceFillMode;
#define FILL_MODE_SOLID                          0
#define FILL_MODE_WIREFRAME                      1
#define FILL_MODE_POINT                          2
   uint32_t                             BackFaceFillMode;
#define FILL_MODE_SOLID                          0
#define FILL_MODE_WIREFRAME                      1
#define FILL_MODE_POINT                          2
   bool                                 AntialiasingEnable;
   bool                                 ScissorRectangleEnable;
   bool                                 ViewportZClipTestEnable;
   float                                GlobalDepthOffsetConstant;
   float                                GlobalDepthOffsetScale;
   float                                GlobalDepthOffsetClamp;
};

static inline void
GEN8_3DSTATE_RASTER_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_3DSTATE_RASTER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->APIMode, 22, 23) |
      __gen_uint(values->FrontWinding, 21, 21) |
      __gen_uint(values->ForcedSampleCount, 18, 20) |
      __gen_uint(values->CullMode, 16, 17) |
      __gen_uint(values->ForceMultisampling, 14, 14) |
      __gen_uint(values->SmoothPointEnable, 13, 13) |
      __gen_uint(values->DXMultisampleRasterizationEnable, 12, 12) |
      __gen_uint(values->DXMultisampleRasterizationMode, 10, 11) |
      __gen_uint(values->GlobalDepthOffsetEnableSolid, 9, 9) |
      __gen_uint(values->GlobalDepthOffsetEnableWireframe, 8, 8) |
      __gen_uint(values->GlobalDepthOffsetEnablePoint, 7, 7) |
      __gen_uint(values->FrontFaceFillMode, 5, 6) |
      __gen_uint(values->BackFaceFillMode, 3, 4) |
      __gen_uint(values->AntialiasingEnable, 2, 2) |
      __gen_uint(values->ScissorRectangleEnable, 1, 1) |
      __gen_uint(values->ViewportZClipTestEnable, 0, 0);

   dw[2] =
      __gen_float(values->GlobalDepthOffsetConstant);

   dw[3] =
      __gen_float(values->GlobalDepthOffsetScale);

   dw[4] =
      __gen_float(values->GlobalDepthOffsetClamp);
}

#define GEN8_3DSTATE_SAMPLER_PALETTE_LOAD0_length_bias      2
#define GEN8_3DSTATE_SAMPLER_PALETTE_LOAD0_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      2

struct GEN8_3DSTATE_SAMPLER_PALETTE_LOAD0 {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_SAMPLER_PALETTE_LOAD0_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_SAMPLER_PALETTE_LOAD0 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);
}

#define GEN8_3DSTATE_SAMPLER_PALETTE_LOAD1_length_bias      2
#define GEN8_3DSTATE_SAMPLER_PALETTE_LOAD1_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     12,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLER_PALETTE_LOAD1 {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_SAMPLER_PALETTE_LOAD1_pack(__gen_user_data *data, void * restrict dst,
                                        const struct GEN8_3DSTATE_SAMPLER_PALETTE_LOAD1 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);
}

#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_DS_length      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_DS_length_bias      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_DS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     45,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoDSSamplerState;
};

static inline void
GEN8_3DSTATE_SAMPLER_STATE_POINTERS_DS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoDSSamplerState, 5, 31);
}

#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_GS_length      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_GS_length_bias      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_GS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     46,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoGSSamplerState;
};

static inline void
GEN8_3DSTATE_SAMPLER_STATE_POINTERS_GS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoGSSamplerState, 5, 31);
}

#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_HS_length      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_HS_length_bias      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_HS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     44,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoHSSamplerState;
};

static inline void
GEN8_3DSTATE_SAMPLER_STATE_POINTERS_HS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoHSSamplerState, 5, 31);
}

#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_PS_length      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_PS_length_bias      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_PS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     47,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_PS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoPSSamplerState;
};

static inline void
GEN8_3DSTATE_SAMPLER_STATE_POINTERS_PS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_PS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoPSSamplerState, 5, 31);
}

#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_VS_length      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_VS_length_bias      2
#define GEN8_3DSTATE_SAMPLER_STATE_POINTERS_VS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     43,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoVSSamplerState;
};

static inline void
GEN8_3DSTATE_SAMPLER_STATE_POINTERS_VS_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN8_3DSTATE_SAMPLER_STATE_POINTERS_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoVSSamplerState, 5, 31);
}

#define GEN8_3DSTATE_SAMPLE_MASK_length        2
#define GEN8_3DSTATE_SAMPLE_MASK_length_bias      2
#define GEN8_3DSTATE_SAMPLE_MASK_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     24,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SAMPLE_MASK {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             SampleMask;
};

static inline void
GEN8_3DSTATE_SAMPLE_MASK_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_SAMPLE_MASK * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->SampleMask, 0, 15);
}

#define GEN8_3DSTATE_SAMPLE_PATTERN_length      9
#define GEN8_3DSTATE_SAMPLE_PATTERN_length_bias      2
#define GEN8_3DSTATE_SAMPLE_PATTERN_header      \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     28,  \
   .DWordLength                         =      7

struct GEN8_3DSTATE_SAMPLE_PATTERN {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   float                                _8xSample7XOffset;
   float                                _8xSample7YOffset;
   float                                _8xSample6XOffset;
   float                                _8xSample6YOffset;
   float                                _8xSample5XOffset;
   float                                _8xSample5YOffset;
   float                                _8xSample4XOffset;
   float                                _8xSample4YOffset;
   float                                _8xSample3XOffset;
   float                                _8xSample3YOffset;
   float                                _8xSample2XOffset;
   float                                _8xSample2YOffset;
   float                                _8xSample1XOffset;
   float                                _8xSample1YOffset;
   float                                _8xSample0XOffset;
   float                                _8xSample0YOffset;
   float                                _4xSample3XOffset;
   float                                _4xSample3YOffset;
   float                                _4xSample2XOffset;
   float                                _4xSample2YOffset;
   float                                _4xSample1XOffset;
   float                                _4xSample1YOffset;
   float                                _4xSample0XOffset;
   float                                _4xSample0YOffset;
   float                                _1xSample0XOffset;
   float                                _1xSample0YOffset;
   float                                _2xSample1XOffset;
   float                                _2xSample1YOffset;
   float                                _2xSample0XOffset;
   float                                _2xSample0YOffset;
};

static inline void
GEN8_3DSTATE_SAMPLE_PATTERN_pack(__gen_user_data *data, void * restrict dst,
                                 const struct GEN8_3DSTATE_SAMPLE_PATTERN * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] = 0;

   dw[2] = 0;

   dw[3] = 0;

   dw[4] = 0;

   dw[5] =
      __gen_ufixed(values->_8xSample7XOffset, 28, 31, 4) |
      __gen_ufixed(values->_8xSample7YOffset, 24, 27, 4) |
      __gen_ufixed(values->_8xSample6XOffset, 20, 23, 4) |
      __gen_ufixed(values->_8xSample6YOffset, 16, 19, 4) |
      __gen_ufixed(values->_8xSample5XOffset, 12, 15, 4) |
      __gen_ufixed(values->_8xSample5YOffset, 8, 11, 4) |
      __gen_ufixed(values->_8xSample4XOffset, 4, 7, 4) |
      __gen_ufixed(values->_8xSample4YOffset, 0, 3, 4);

   dw[6] =
      __gen_ufixed(values->_8xSample3XOffset, 28, 31, 4) |
      __gen_ufixed(values->_8xSample3YOffset, 24, 27, 4) |
      __gen_ufixed(values->_8xSample2XOffset, 20, 23, 4) |
      __gen_ufixed(values->_8xSample2YOffset, 16, 19, 4) |
      __gen_ufixed(values->_8xSample1XOffset, 12, 15, 4) |
      __gen_ufixed(values->_8xSample1YOffset, 8, 11, 4) |
      __gen_ufixed(values->_8xSample0XOffset, 4, 7, 4) |
      __gen_ufixed(values->_8xSample0YOffset, 0, 3, 4);

   dw[7] =
      __gen_ufixed(values->_4xSample3XOffset, 28, 31, 4) |
      __gen_ufixed(values->_4xSample3YOffset, 24, 27, 4) |
      __gen_ufixed(values->_4xSample2XOffset, 20, 23, 4) |
      __gen_ufixed(values->_4xSample2YOffset, 16, 19, 4) |
      __gen_ufixed(values->_4xSample1XOffset, 12, 15, 4) |
      __gen_ufixed(values->_4xSample1YOffset, 8, 11, 4) |
      __gen_ufixed(values->_4xSample0XOffset, 4, 7, 4) |
      __gen_ufixed(values->_4xSample0YOffset, 0, 3, 4);

   dw[8] =
      __gen_ufixed(values->_1xSample0XOffset, 20, 23, 4) |
      __gen_ufixed(values->_1xSample0YOffset, 16, 19, 4) |
      __gen_ufixed(values->_2xSample1XOffset, 12, 15, 4) |
      __gen_ufixed(values->_2xSample1YOffset, 8, 11, 4) |
      __gen_ufixed(values->_2xSample0XOffset, 4, 7, 4) |
      __gen_ufixed(values->_2xSample0YOffset, 0, 3, 4);
}

#define GEN8_3DSTATE_SBE_length                4
#define GEN8_3DSTATE_SBE_length_bias           2
#define GEN8_3DSTATE_SBE_header                 \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     31,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_SBE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 ForceVertexURBEntryReadLength;
   bool                                 ForceVertexURBEntryReadOffset;
   uint32_t                             NumberofSFOutputAttributes;
   bool                                 AttributeSwizzleEnable;
   uint32_t                             PointSpriteTextureCoordinateOrigin;
#define UPPERLEFT                                0
#define LOWERLEFT                                1
   bool                                 PrimitiveIDOverrideComponentW;
   bool                                 PrimitiveIDOverrideComponentZ;
   bool                                 PrimitiveIDOverrideComponentY;
   bool                                 PrimitiveIDOverrideComponentX;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             PrimitiveIDOverrideAttributeSelect;
   uint32_t                             PointSpriteTextureCoordinateEnable;
   uint32_t                             ConstantInterpolationEnable;
};

static inline void
GEN8_3DSTATE_SBE_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN8_3DSTATE_SBE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ForceVertexURBEntryReadLength, 29, 29) |
      __gen_uint(values->ForceVertexURBEntryReadOffset, 28, 28) |
      __gen_uint(values->NumberofSFOutputAttributes, 22, 27) |
      __gen_uint(values->AttributeSwizzleEnable, 21, 21) |
      __gen_uint(values->PointSpriteTextureCoordinateOrigin, 20, 20) |
      __gen_uint(values->PrimitiveIDOverrideComponentW, 19, 19) |
      __gen_uint(values->PrimitiveIDOverrideComponentZ, 18, 18) |
      __gen_uint(values->PrimitiveIDOverrideComponentY, 17, 17) |
      __gen_uint(values->PrimitiveIDOverrideComponentX, 16, 16) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 15) |
      __gen_uint(values->VertexURBEntryReadOffset, 5, 10) |
      __gen_uint(values->PrimitiveIDOverrideAttributeSelect, 0, 4);

   dw[2] =
      __gen_uint(values->PointSpriteTextureCoordinateEnable, 0, 31);

   dw[3] =
      __gen_uint(values->ConstantInterpolationEnable, 0, 31);
}

#define GEN8_3DSTATE_SBE_SWIZ_length          11
#define GEN8_3DSTATE_SBE_SWIZ_length_bias      2
#define GEN8_3DSTATE_SBE_SWIZ_header            \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     81,  \
   .DWordLength                         =      9

struct GEN8_3DSTATE_SBE_SWIZ {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   struct GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL Attribute[16];
   uint32_t                             AttributeWrapShortestEnables[16];
};

static inline void
GEN8_3DSTATE_SBE_SWIZ_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_3DSTATE_SBE_SWIZ * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v1_0, &values->Attribute[0]);

   uint32_t v1_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v1_1, &values->Attribute[1]);

   dw[1] =
      __gen_uint(v1_0, 0, 15) |
      __gen_uint(v1_1, 16, 31);

   uint32_t v2_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v2_0, &values->Attribute[2]);

   uint32_t v2_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v2_1, &values->Attribute[3]);

   dw[2] =
      __gen_uint(v2_0, 0, 15) |
      __gen_uint(v2_1, 16, 31);

   uint32_t v3_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v3_0, &values->Attribute[4]);

   uint32_t v3_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v3_1, &values->Attribute[5]);

   dw[3] =
      __gen_uint(v3_0, 0, 15) |
      __gen_uint(v3_1, 16, 31);

   uint32_t v4_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v4_0, &values->Attribute[6]);

   uint32_t v4_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v4_1, &values->Attribute[7]);

   dw[4] =
      __gen_uint(v4_0, 0, 15) |
      __gen_uint(v4_1, 16, 31);

   uint32_t v5_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v5_0, &values->Attribute[8]);

   uint32_t v5_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v5_1, &values->Attribute[9]);

   dw[5] =
      __gen_uint(v5_0, 0, 15) |
      __gen_uint(v5_1, 16, 31);

   uint32_t v6_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v6_0, &values->Attribute[10]);

   uint32_t v6_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v6_1, &values->Attribute[11]);

   dw[6] =
      __gen_uint(v6_0, 0, 15) |
      __gen_uint(v6_1, 16, 31);

   uint32_t v7_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v7_0, &values->Attribute[12]);

   uint32_t v7_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v7_1, &values->Attribute[13]);

   dw[7] =
      __gen_uint(v7_0, 0, 15) |
      __gen_uint(v7_1, 16, 31);

   uint32_t v8_0;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v8_0, &values->Attribute[14]);

   uint32_t v8_1;
   GEN8_SF_OUTPUT_ATTRIBUTE_DETAIL_pack(data, &v8_1, &values->Attribute[15]);

   dw[8] =
      __gen_uint(v8_0, 0, 15) |
      __gen_uint(v8_1, 16, 31);

   dw[9] =
      __gen_uint(values->AttributeWrapShortestEnables[0], 0, 3) |
      __gen_uint(values->AttributeWrapShortestEnables[1], 4, 7) |
      __gen_uint(values->AttributeWrapShortestEnables[2], 8, 11) |
      __gen_uint(values->AttributeWrapShortestEnables[3], 12, 15) |
      __gen_uint(values->AttributeWrapShortestEnables[4], 16, 19) |
      __gen_uint(values->AttributeWrapShortestEnables[5], 20, 23) |
      __gen_uint(values->AttributeWrapShortestEnables[6], 24, 27) |
      __gen_uint(values->AttributeWrapShortestEnables[7], 28, 31);

   dw[10] =
      __gen_uint(values->AttributeWrapShortestEnables[8], 0, 3) |
      __gen_uint(values->AttributeWrapShortestEnables[9], 4, 7) |
      __gen_uint(values->AttributeWrapShortestEnables[10], 8, 11) |
      __gen_uint(values->AttributeWrapShortestEnables[11], 12, 15) |
      __gen_uint(values->AttributeWrapShortestEnables[12], 16, 19) |
      __gen_uint(values->AttributeWrapShortestEnables[13], 20, 23) |
      __gen_uint(values->AttributeWrapShortestEnables[14], 24, 27) |
      __gen_uint(values->AttributeWrapShortestEnables[15], 28, 31);
}

#define GEN8_3DSTATE_SCISSOR_STATE_POINTERS_length      2
#define GEN8_3DSTATE_SCISSOR_STATE_POINTERS_length_bias      2
#define GEN8_3DSTATE_SCISSOR_STATE_POINTERS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     15,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_SCISSOR_STATE_POINTERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             ScissorRectPointer;
};

static inline void
GEN8_3DSTATE_SCISSOR_STATE_POINTERS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN8_3DSTATE_SCISSOR_STATE_POINTERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->ScissorRectPointer, 5, 31);
}

#define GEN8_3DSTATE_SF_length                 4
#define GEN8_3DSTATE_SF_length_bias            2
#define GEN8_3DSTATE_SF_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     19,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_SF {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 LegacyGlobalDepthBiasEnable;
   bool                                 StatisticsEnable;
   bool                                 ViewportTransformEnable;
   float                                LineWidth;
   uint32_t                             LineEndCapAntialiasingRegionWidth;
#define _05pixels                                0
#define _10pixels                                1
#define _20pixels                                2
#define _40pixels                                3
   bool                                 LastPixelEnable;
   uint32_t                             TriangleStripListProvokingVertexSelect;
   uint32_t                             LineStripListProvokingVertexSelect;
   uint32_t                             TriangleFanProvokingVertexSelect;
   uint32_t                             AALineDistanceMode;
#define AALINEDISTANCE_TRUE                      1
   bool                                 SmoothPointEnable;
   uint32_t                             VertexSubPixelPrecisionSelect;
   uint32_t                             PointWidthSource;
#define Vertex                                   0
#define State                                    1
   float                                PointWidth;
};

static inline void
GEN8_3DSTATE_SF_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_SF * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->LegacyGlobalDepthBiasEnable, 11, 11) |
      __gen_uint(values->StatisticsEnable, 10, 10) |
      __gen_uint(values->ViewportTransformEnable, 1, 1);

   dw[2] =
      __gen_ufixed(values->LineWidth, 18, 27, 7) |
      __gen_uint(values->LineEndCapAntialiasingRegionWidth, 16, 17);

   dw[3] =
      __gen_uint(values->LastPixelEnable, 31, 31) |
      __gen_uint(values->TriangleStripListProvokingVertexSelect, 29, 30) |
      __gen_uint(values->LineStripListProvokingVertexSelect, 27, 28) |
      __gen_uint(values->TriangleFanProvokingVertexSelect, 25, 26) |
      __gen_uint(values->AALineDistanceMode, 14, 14) |
      __gen_uint(values->SmoothPointEnable, 13, 13) |
      __gen_uint(values->VertexSubPixelPrecisionSelect, 12, 12) |
      __gen_uint(values->PointWidthSource, 11, 11) |
      __gen_ufixed(values->PointWidth, 0, 10, 3);
}

#define GEN8_3DSTATE_SO_BUFFER_length          8
#define GEN8_3DSTATE_SO_BUFFER_length_bias      2
#define GEN8_3DSTATE_SO_BUFFER_header           \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     24,  \
   .DWordLength                         =      6

struct GEN8_3DSTATE_SO_BUFFER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 SOBufferEnable;
   uint32_t                             SOBufferIndex;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE SOBufferObjectControlState;
   bool                                 StreamOffsetWriteEnable;
   bool                                 StreamOutputBufferOffsetAddressEnable;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             SurfaceSize;
   __gen_address_type                   StreamOutputBufferOffsetAddress;
   uint32_t                             StreamOffset;
};

static inline void
GEN8_3DSTATE_SO_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_3DSTATE_SO_BUFFER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->SOBufferObjectControlState);

   dw[1] =
      __gen_uint(values->SOBufferEnable, 31, 31) |
      __gen_uint(values->SOBufferIndex, 29, 30) |
      __gen_uint(v1_0, 22, 28) |
      __gen_uint(values->StreamOffsetWriteEnable, 21, 21) |
      __gen_uint(values->StreamOutputBufferOffsetAddressEnable, 20, 20);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->SurfaceBaseAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   dw[4] =
      __gen_uint(values->SurfaceSize, 0, 29);

   const uint64_t v5_address =
      __gen_combine_address(data, &dw[5], values->StreamOutputBufferOffsetAddress, 0);
   dw[5] = v5_address;
   dw[6] = v5_address >> 32;

   dw[7] =
      __gen_uint(values->StreamOffset, 0, 31);
}

#define GEN8_3DSTATE_SO_DECL_LIST_length_bias      2
#define GEN8_3DSTATE_SO_DECL_LIST_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     23

struct GEN8_3DSTATE_SO_DECL_LIST {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             StreamtoBufferSelects3;
   uint32_t                             StreamtoBufferSelects2;
   uint32_t                             StreamtoBufferSelects1;
   uint32_t                             StreamtoBufferSelects0;
   uint32_t                             NumEntries3;
   uint32_t                             NumEntries2;
   uint32_t                             NumEntries1;
   uint32_t                             NumEntries0;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_SO_DECL_LIST_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_3DSTATE_SO_DECL_LIST * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 8);

   dw[1] =
      __gen_uint(values->StreamtoBufferSelects3, 12, 15) |
      __gen_uint(values->StreamtoBufferSelects2, 8, 11) |
      __gen_uint(values->StreamtoBufferSelects1, 4, 7) |
      __gen_uint(values->StreamtoBufferSelects0, 0, 3);

   dw[2] =
      __gen_uint(values->NumEntries3, 24, 31) |
      __gen_uint(values->NumEntries2, 16, 23) |
      __gen_uint(values->NumEntries1, 8, 15) |
      __gen_uint(values->NumEntries0, 0, 7);
}

#define GEN8_3DSTATE_STENCIL_BUFFER_length      5
#define GEN8_3DSTATE_STENCIL_BUFFER_length_bias      2
#define GEN8_3DSTATE_STENCIL_BUFFER_header      \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      6,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_STENCIL_BUFFER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 StencilBufferEnable;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE StencilBufferObjectControlState;
   uint32_t                             StencilBufferMOCS;
   uint32_t                             SurfacePitch;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             SurfaceQPitch;
};

static inline void
GEN8_3DSTATE_STENCIL_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                                 const struct GEN8_3DSTATE_STENCIL_BUFFER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->StencilBufferObjectControlState);

   dw[1] =
      __gen_uint(values->StencilBufferEnable, 31, 31) |
      __gen_uint(v1_0, 22, 28) |
      __gen_uint(values->StencilBufferMOCS, 22, 28) |
      __gen_uint(values->SurfacePitch, 0, 16);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->SurfaceBaseAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   dw[4] =
      __gen_uint(values->SurfaceQPitch, 0, 14);
}

#define GEN8_3DSTATE_STREAMOUT_length          5
#define GEN8_3DSTATE_STREAMOUT_length_bias      2
#define GEN8_3DSTATE_STREAMOUT_header           \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     30,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_STREAMOUT {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 SOFunctionEnable;
   bool                                 RenderingDisable;
   uint32_t                             RenderStreamSelect;
   uint32_t                             ReorderMode;
#define LEADING                                  0
#define TRAILING                                 1
   bool                                 SOStatisticsEnable;
   uint32_t                             ForceRendering;
#define Resreved                                 1
#define Force_Off                                2
#define Force_on                                 3
   uint32_t                             Stream3VertexReadOffset;
   uint32_t                             Stream3VertexReadLength;
   uint32_t                             Stream2VertexReadOffset;
   uint32_t                             Stream2VertexReadLength;
   uint32_t                             Stream1VertexReadOffset;
   uint32_t                             Stream1VertexReadLength;
   uint32_t                             Stream0VertexReadOffset;
   uint32_t                             Stream0VertexReadLength;
   uint32_t                             Buffer1SurfacePitch;
   uint32_t                             Buffer0SurfacePitch;
   uint32_t                             Buffer3SurfacePitch;
   uint32_t                             Buffer2SurfacePitch;
};

static inline void
GEN8_3DSTATE_STREAMOUT_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_3DSTATE_STREAMOUT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->SOFunctionEnable, 31, 31) |
      __gen_uint(values->RenderingDisable, 30, 30) |
      __gen_uint(values->RenderStreamSelect, 27, 28) |
      __gen_uint(values->ReorderMode, 26, 26) |
      __gen_uint(values->SOStatisticsEnable, 25, 25) |
      __gen_uint(values->ForceRendering, 23, 24);

   dw[2] =
      __gen_uint(values->Stream3VertexReadOffset, 29, 29) |
      __gen_uint(values->Stream3VertexReadLength, 24, 28) |
      __gen_uint(values->Stream2VertexReadOffset, 21, 21) |
      __gen_uint(values->Stream2VertexReadLength, 16, 20) |
      __gen_uint(values->Stream1VertexReadOffset, 13, 13) |
      __gen_uint(values->Stream1VertexReadLength, 8, 12) |
      __gen_uint(values->Stream0VertexReadOffset, 5, 5) |
      __gen_uint(values->Stream0VertexReadLength, 0, 4);

   dw[3] =
      __gen_uint(values->Buffer1SurfacePitch, 16, 27) |
      __gen_uint(values->Buffer0SurfacePitch, 0, 11);

   dw[4] =
      __gen_uint(values->Buffer3SurfacePitch, 16, 27) |
      __gen_uint(values->Buffer2SurfacePitch, 0, 11);
}

#define GEN8_3DSTATE_TE_length                 4
#define GEN8_3DSTATE_TE_length_bias            2
#define GEN8_3DSTATE_TE_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     28,  \
   .DWordLength                         =      2

struct GEN8_3DSTATE_TE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             Partitioning;
#define INTEGER                                  0
#define ODD_FRACTIONAL                           1
#define EVEN_FRACTIONAL                          2
   uint32_t                             OutputTopology;
#define OUTPUT_POINT                             0
#define OUTPUT_LINE                              1
#define OUTPUT_TRI_CW                            2
#define OUTPUT_TRI_CCW                           3
   uint32_t                             TEDomain;
#define QUAD                                     0
#define TRI                                      1
#define ISOLINE                                  2
   uint32_t                             TEMode;
#define HW_TESS                                  0
#define SW_TESS                                  1
   bool                                 TEEnable;
   float                                MaximumTessellationFactorOdd;
   float                                MaximumTessellationFactorNotOdd;
};

static inline void
GEN8_3DSTATE_TE_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_TE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->Partitioning, 12, 13) |
      __gen_uint(values->OutputTopology, 8, 9) |
      __gen_uint(values->TEDomain, 4, 5) |
      __gen_uint(values->TEMode, 1, 2) |
      __gen_uint(values->TEEnable, 0, 0);

   dw[2] =
      __gen_float(values->MaximumTessellationFactorOdd);

   dw[3] =
      __gen_float(values->MaximumTessellationFactorNotOdd);
}

#define GEN8_3DSTATE_URB_DS_length             2
#define GEN8_3DSTATE_URB_DS_length_bias        2
#define GEN8_3DSTATE_URB_DS_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     50,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_URB_DS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             DSURBStartingAddress;
   uint32_t                             DSURBEntryAllocationSize;
   uint32_t                             DSNumberofURBEntries;
};

static inline void
GEN8_3DSTATE_URB_DS_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_3DSTATE_URB_DS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->DSURBStartingAddress, 25, 31) |
      __gen_uint(values->DSURBEntryAllocationSize, 16, 24) |
      __gen_uint(values->DSNumberofURBEntries, 0, 15);
}

#define GEN8_3DSTATE_URB_GS_length             2
#define GEN8_3DSTATE_URB_GS_length_bias        2
#define GEN8_3DSTATE_URB_GS_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     51,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_URB_GS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             GSURBStartingAddress;
   uint32_t                             GSURBEntryAllocationSize;
   uint32_t                             GSNumberofURBEntries;
};

static inline void
GEN8_3DSTATE_URB_GS_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_3DSTATE_URB_GS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->GSURBStartingAddress, 25, 31) |
      __gen_uint(values->GSURBEntryAllocationSize, 16, 24) |
      __gen_uint(values->GSNumberofURBEntries, 0, 15);
}

#define GEN8_3DSTATE_URB_HS_length             2
#define GEN8_3DSTATE_URB_HS_length_bias        2
#define GEN8_3DSTATE_URB_HS_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     49,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_URB_HS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             HSURBStartingAddress;
   uint32_t                             HSURBEntryAllocationSize;
   uint32_t                             HSNumberofURBEntries;
};

static inline void
GEN8_3DSTATE_URB_HS_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_3DSTATE_URB_HS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->HSURBStartingAddress, 25, 31) |
      __gen_uint(values->HSURBEntryAllocationSize, 16, 24) |
      __gen_uint(values->HSNumberofURBEntries, 0, 15);
}

#define GEN8_3DSTATE_URB_VS_length             2
#define GEN8_3DSTATE_URB_VS_length_bias        2
#define GEN8_3DSTATE_URB_VS_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     48,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_URB_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             VSURBStartingAddress;
   uint32_t                             VSURBEntryAllocationSize;
   uint32_t                             VSNumberofURBEntries;
};

static inline void
GEN8_3DSTATE_URB_VS_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_3DSTATE_URB_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->VSURBStartingAddress, 25, 31) |
      __gen_uint(values->VSURBEntryAllocationSize, 16, 24) |
      __gen_uint(values->VSNumberofURBEntries, 0, 15);
}

#define GEN8_3DSTATE_VERTEX_BUFFERS_length_bias      2
#define GEN8_3DSTATE_VERTEX_BUFFERS_header      \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      8,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_VERTEX_BUFFERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_VERTEX_BUFFERS_pack(__gen_user_data *data, void * restrict dst,
                                 const struct GEN8_3DSTATE_VERTEX_BUFFERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);
}

#define GEN8_3DSTATE_VERTEX_ELEMENTS_length_bias      2
#define GEN8_3DSTATE_VERTEX_ELEMENTS_header     \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      9,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_VERTEX_ELEMENTS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   /* variable length fields follow */
};

static inline void
GEN8_3DSTATE_VERTEX_ELEMENTS_pack(__gen_user_data *data, void * restrict dst,
                                  const struct GEN8_3DSTATE_VERTEX_ELEMENTS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);
}

#define GEN8_3DSTATE_VF_length                 2
#define GEN8_3DSTATE_VF_length_bias            2
#define GEN8_3DSTATE_VF_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     12,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_VF {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   bool                                 IndexedDrawCutIndexEnable;
   uint32_t                             DWordLength;
   uint32_t                             CutIndex;
};

static inline void
GEN8_3DSTATE_VF_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_VF * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->IndexedDrawCutIndexEnable, 8, 8) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->CutIndex, 0, 31);
}

#define GEN8_3DSTATE_VF_INSTANCING_length      3
#define GEN8_3DSTATE_VF_INSTANCING_length_bias      2
#define GEN8_3DSTATE_VF_INSTANCING_header       \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     73,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_VF_INSTANCING {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 InstancingEnable;
   uint32_t                             VertexElementIndex;
   uint32_t                             InstanceDataStepRate;
};

static inline void
GEN8_3DSTATE_VF_INSTANCING_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN8_3DSTATE_VF_INSTANCING * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->InstancingEnable, 8, 8) |
      __gen_uint(values->VertexElementIndex, 0, 5);

   dw[2] =
      __gen_uint(values->InstanceDataStepRate, 0, 31);
}

#define GEN8_3DSTATE_VF_SGVS_length            2
#define GEN8_3DSTATE_VF_SGVS_length_bias       2
#define GEN8_3DSTATE_VF_SGVS_header             \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     74,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_VF_SGVS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 InstanceIDEnable;
   uint32_t                             InstanceIDComponentNumber;
#define COMP_0                                   0
#define COMP_1                                   1
#define COMP_2                                   2
#define COMP_3                                   3
   uint32_t                             InstanceIDElementOffset;
   bool                                 VertexIDEnable;
   uint32_t                             VertexIDComponentNumber;
#define COMP_0                                   0
#define COMP_1                                   1
#define COMP_2                                   2
#define COMP_3                                   3
   uint32_t                             VertexIDElementOffset;
};

static inline void
GEN8_3DSTATE_VF_SGVS_pack(__gen_user_data *data, void * restrict dst,
                          const struct GEN8_3DSTATE_VF_SGVS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->InstanceIDEnable, 31, 31) |
      __gen_uint(values->InstanceIDComponentNumber, 29, 30) |
      __gen_uint(values->InstanceIDElementOffset, 16, 21) |
      __gen_uint(values->VertexIDEnable, 15, 15) |
      __gen_uint(values->VertexIDComponentNumber, 13, 14) |
      __gen_uint(values->VertexIDElementOffset, 0, 5);
}

#define GEN8_3DSTATE_VF_STATISTICS_length      1
#define GEN8_3DSTATE_VF_STATISTICS_length_bias      1
#define GEN8_3DSTATE_VF_STATISTICS_header       \
   .CommandType                         =      3,  \
   .CommandSubType                      =      1,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     11

struct GEN8_3DSTATE_VF_STATISTICS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   bool                                 StatisticsEnable;
};

static inline void
GEN8_3DSTATE_VF_STATISTICS_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN8_3DSTATE_VF_STATISTICS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->StatisticsEnable, 0, 0);
}

#define GEN8_3DSTATE_VF_TOPOLOGY_length        2
#define GEN8_3DSTATE_VF_TOPOLOGY_length_bias      2
#define GEN8_3DSTATE_VF_TOPOLOGY_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     75,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_VF_TOPOLOGY {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   enum GEN8_3D_Prim_Topo_Type          PrimitiveTopologyType;
};

static inline void
GEN8_3DSTATE_VF_TOPOLOGY_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_3DSTATE_VF_TOPOLOGY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->PrimitiveTopologyType, 0, 5);
}

#define GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_CC_length      2
#define GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_CC_length_bias      2
#define GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_CC_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     35,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_CC {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             CCViewportPointer;
};

static inline void
GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_CC_pack(__gen_user_data *data, void * restrict dst,
                                             const struct GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_CC * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->CCViewportPointer, 5, 31);
}

#define GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CLIP_length      2
#define GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CLIP_length_bias      2
#define GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CLIP_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     33,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CLIP {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             SFClipViewportPointer;
};

static inline void
GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CLIP_pack(__gen_user_data *data, void * restrict dst,
                                                  const struct GEN8_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CLIP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->SFClipViewportPointer, 6, 31);
}

#define GEN8_3DSTATE_VS_length                 9
#define GEN8_3DSTATE_VS_length_bias            2
#define GEN8_3DSTATE_VS_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     16,  \
   .DWordLength                         =      7

struct GEN8_3DSTATE_VS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             KernelStartPointer;
   bool                                 SingleVertexDispatch;
   bool                                 VectorMaskEnable;
   uint32_t                             SamplerCount;
#define NoSamplers                               0
#define _14Samplers                              1
#define _58Samplers                              2
#define _912Samplers                             3
#define _1316Samplers                            4
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadDispatchPriority;
#define High                                     1
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 AccessesUAV;
   bool                                 SoftwareExceptionEnable;
   __gen_address_type                   ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             DispatchGRFStartRegisterForURBData;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             MaximumNumberofThreads;
   bool                                 StatisticsEnable;
   bool                                 SIMD8DispatchEnable;
   bool                                 VertexCacheDisable;
   bool                                 FunctionEnable;
   uint32_t                             VertexURBEntryOutputReadOffset;
   uint32_t                             VertexURBEntryOutputLength;
   uint32_t                             UserClipDistanceClipTestEnableBitmask;
   uint32_t                             UserClipDistanceCullTestEnableBitmask;
};

static inline void
GEN8_3DSTATE_VS_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_VS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1 =
      __gen_offset(values->KernelStartPointer, 6, 63);
   dw[1] = v1;
   dw[2] = v1 >> 32;

   dw[3] =
      __gen_uint(values->SingleVertexDispatch, 31, 31) |
      __gen_uint(values->VectorMaskEnable, 30, 30) |
      __gen_uint(values->SamplerCount, 27, 29) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadDispatchPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->AccessesUAV, 12, 12) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   const uint64_t v4 =
      __gen_uint(values->PerThreadScratchSpace, 0, 3);
   const uint64_t v4_address =
      __gen_combine_address(data, &dw[4], values->ScratchSpaceBasePointer, v4);
   dw[4] = v4_address;
   dw[5] = v4_address >> 32;

   dw[6] =
      __gen_uint(values->DispatchGRFStartRegisterForURBData, 20, 24) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9);

   dw[7] =
      __gen_uint(values->MaximumNumberofThreads, 23, 31) |
      __gen_uint(values->StatisticsEnable, 10, 10) |
      __gen_uint(values->SIMD8DispatchEnable, 2, 2) |
      __gen_uint(values->VertexCacheDisable, 1, 1) |
      __gen_uint(values->FunctionEnable, 0, 0);

   dw[8] =
      __gen_uint(values->VertexURBEntryOutputReadOffset, 21, 26) |
      __gen_uint(values->VertexURBEntryOutputLength, 16, 20) |
      __gen_uint(values->UserClipDistanceClipTestEnableBitmask, 8, 15) |
      __gen_uint(values->UserClipDistanceCullTestEnableBitmask, 0, 7);
}

#define GEN8_3DSTATE_WM_length                 2
#define GEN8_3DSTATE_WM_length_bias            2
#define GEN8_3DSTATE_WM_header                  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     20,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_WM {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 StatisticsEnable;
   bool                                 LegacyDepthBufferClearEnable;
   bool                                 LegacyDepthBufferResolveEnable;
   bool                                 LegacyHierarchicalDepthBufferResolveEnable;
   bool                                 LegacyDiamondLineRasterization;
   uint32_t                             EarlyDepthStencilControl;
#define EDSC_NORMAL                              0
#define EDSC_PSEXEC                              1
#define EDSC_PREPS                               2
   uint32_t                             ForceThreadDispatchEnable;
#define ForceOff                                 1
#define ForceON                                  2
   uint32_t                             PositionZWInterpolationMode;
#define INTERP_PIXEL                             0
#define INTERP_CENTROID                          2
#define INTERP_SAMPLE                            3
   uint32_t                             BarycentricInterpolationMode;
#define BIM_PERSPECTIVE_PIXEL                    1
#define BIM_PERSPECTIVE_CENTROID                 2
#define BIM_PERSPECTIVE_SAMPLE                   4
#define BIM_LINEAR_PIXEL                         8
#define BIM_LINEAR_CENTROID                      16
#define BIM_LINEAR_SAMPLE                        32
   uint32_t                             LineEndCapAntialiasingRegionWidth;
#define _05pixels                                0
#define _10pixels                                1
#define _20pixels                                2
#define _40pixels                                3
   uint32_t                             LineAntialiasingRegionWidth;
#define _05pixels                                0
#define _10pixels                                1
#define _20pixels                                2
#define _40pixels                                3
   bool                                 PolygonStippleEnable;
   bool                                 LineStippleEnable;
   uint32_t                             PointRasterizationRule;
#define RASTRULE_UPPER_LEFT                      0
#define RASTRULE_UPPER_RIGHT                     1
   uint32_t                             ForceKillPixelEnable;
#define ForceOff                                 1
#define ForceON                                  2
};

static inline void
GEN8_3DSTATE_WM_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_3DSTATE_WM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->StatisticsEnable, 31, 31) |
      __gen_uint(values->LegacyDepthBufferClearEnable, 30, 30) |
      __gen_uint(values->LegacyDepthBufferResolveEnable, 28, 28) |
      __gen_uint(values->LegacyHierarchicalDepthBufferResolveEnable, 27, 27) |
      __gen_uint(values->LegacyDiamondLineRasterization, 26, 26) |
      __gen_uint(values->EarlyDepthStencilControl, 21, 22) |
      __gen_uint(values->ForceThreadDispatchEnable, 19, 20) |
      __gen_uint(values->PositionZWInterpolationMode, 17, 18) |
      __gen_uint(values->BarycentricInterpolationMode, 11, 16) |
      __gen_uint(values->LineEndCapAntialiasingRegionWidth, 8, 9) |
      __gen_uint(values->LineAntialiasingRegionWidth, 6, 7) |
      __gen_uint(values->PolygonStippleEnable, 4, 4) |
      __gen_uint(values->LineStippleEnable, 3, 3) |
      __gen_uint(values->PointRasterizationRule, 2, 2) |
      __gen_uint(values->ForceKillPixelEnable, 0, 1);
}

#define GEN8_3DSTATE_WM_CHROMAKEY_length       2
#define GEN8_3DSTATE_WM_CHROMAKEY_length_bias      2
#define GEN8_3DSTATE_WM_CHROMAKEY_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     76,  \
   .DWordLength                         =      0

struct GEN8_3DSTATE_WM_CHROMAKEY {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 ChromaKeyKillEnable;
};

static inline void
GEN8_3DSTATE_WM_CHROMAKEY_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_3DSTATE_WM_CHROMAKEY * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->ChromaKeyKillEnable, 31, 31);
}

#define GEN8_3DSTATE_WM_DEPTH_STENCIL_length      3
#define GEN8_3DSTATE_WM_DEPTH_STENCIL_length_bias      2
#define GEN8_3DSTATE_WM_DEPTH_STENCIL_header    \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     78,  \
   .DWordLength                         =      1

struct GEN8_3DSTATE_WM_DEPTH_STENCIL {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   enum GEN8_3D_Stencil_Operation       StencilFailOp;
   enum GEN8_3D_Stencil_Operation       StencilPassDepthFailOp;
   enum GEN8_3D_Stencil_Operation       StencilPassDepthPassOp;
   enum GEN8_3D_Compare_Function        BackfaceStencilTestFunction;
   enum GEN8_3D_Stencil_Operation       BackfaceStencilFailOp;
   enum GEN8_3D_Stencil_Operation       BackfaceStencilPassDepthFailOp;
   enum GEN8_3D_Stencil_Operation       BackfaceStencilPassDepthPassOp;
   enum GEN8_3D_Compare_Function        StencilTestFunction;
   enum GEN8_3D_Compare_Function        DepthTestFunction;
   bool                                 DoubleSidedStencilEnable;
   bool                                 StencilTestEnable;
   bool                                 StencilBufferWriteEnable;
   bool                                 DepthTestEnable;
   bool                                 DepthBufferWriteEnable;
   uint32_t                             StencilTestMask;
   uint32_t                             StencilWriteMask;
   uint32_t                             BackfaceStencilTestMask;
   uint32_t                             BackfaceStencilWriteMask;
};

static inline void
GEN8_3DSTATE_WM_DEPTH_STENCIL_pack(__gen_user_data *data, void * restrict dst,
                                   const struct GEN8_3DSTATE_WM_DEPTH_STENCIL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->StencilFailOp, 29, 31) |
      __gen_uint(values->StencilPassDepthFailOp, 26, 28) |
      __gen_uint(values->StencilPassDepthPassOp, 23, 25) |
      __gen_uint(values->BackfaceStencilTestFunction, 20, 22) |
      __gen_uint(values->BackfaceStencilFailOp, 17, 19) |
      __gen_uint(values->BackfaceStencilPassDepthFailOp, 14, 16) |
      __gen_uint(values->BackfaceStencilPassDepthPassOp, 11, 13) |
      __gen_uint(values->StencilTestFunction, 8, 10) |
      __gen_uint(values->DepthTestFunction, 5, 7) |
      __gen_uint(values->DoubleSidedStencilEnable, 4, 4) |
      __gen_uint(values->StencilTestEnable, 3, 3) |
      __gen_uint(values->StencilBufferWriteEnable, 2, 2) |
      __gen_uint(values->DepthTestEnable, 1, 1) |
      __gen_uint(values->DepthBufferWriteEnable, 0, 0);

   dw[2] =
      __gen_uint(values->StencilTestMask, 24, 31) |
      __gen_uint(values->StencilWriteMask, 16, 23) |
      __gen_uint(values->BackfaceStencilTestMask, 8, 15) |
      __gen_uint(values->BackfaceStencilWriteMask, 0, 7);
}

#define GEN8_3DSTATE_WM_HZ_OP_length           5
#define GEN8_3DSTATE_WM_HZ_OP_length_bias      2
#define GEN8_3DSTATE_WM_HZ_OP_header            \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     82,  \
   .DWordLength                         =      3

struct GEN8_3DSTATE_WM_HZ_OP {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   bool                                 StencilBufferClearEnable;
   bool                                 DepthBufferClearEnable;
   bool                                 ScissorRectangleEnable;
   bool                                 DepthBufferResolveEnable;
   bool                                 HierarchicalDepthBufferResolveEnable;
   bool                                 PixelPositionOffsetEnable;
   bool                                 FullSurfaceDepthandStencilClear;
   uint32_t                             StencilClearValue;
   uint32_t                             NumberofMultisamples;
   uint32_t                             ClearRectangleYMin;
   uint32_t                             ClearRectangleXMin;
   uint32_t                             ClearRectangleYMax;
   uint32_t                             ClearRectangleXMax;
   uint32_t                             SampleMask;
};

static inline void
GEN8_3DSTATE_WM_HZ_OP_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_3DSTATE_WM_HZ_OP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->StencilBufferClearEnable, 31, 31) |
      __gen_uint(values->DepthBufferClearEnable, 30, 30) |
      __gen_uint(values->ScissorRectangleEnable, 29, 29) |
      __gen_uint(values->DepthBufferResolveEnable, 28, 28) |
      __gen_uint(values->HierarchicalDepthBufferResolveEnable, 27, 27) |
      __gen_uint(values->PixelPositionOffsetEnable, 26, 26) |
      __gen_uint(values->FullSurfaceDepthandStencilClear, 25, 25) |
      __gen_uint(values->StencilClearValue, 16, 23) |
      __gen_uint(values->NumberofMultisamples, 13, 15);

   dw[2] =
      __gen_uint(values->ClearRectangleYMin, 16, 31) |
      __gen_uint(values->ClearRectangleXMin, 0, 15);

   dw[3] =
      __gen_uint(values->ClearRectangleYMax, 16, 31) |
      __gen_uint(values->ClearRectangleXMax, 0, 15);

   dw[4] =
      __gen_uint(values->SampleMask, 0, 15);
}

#define GEN8_GPGPU_CSR_BASE_ADDRESS_length      3
#define GEN8_GPGPU_CSR_BASE_ADDRESS_length_bias      2
#define GEN8_GPGPU_CSR_BASE_ADDRESS_header      \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      4,  \
   .DWordLength                         =      1

struct GEN8_GPGPU_CSR_BASE_ADDRESS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   GPGPUCSRBaseAddress;
};

static inline void
GEN8_GPGPU_CSR_BASE_ADDRESS_pack(__gen_user_data *data, void * restrict dst,
                                 const struct GEN8_GPGPU_CSR_BASE_ADDRESS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->GPGPUCSRBaseAddress, 0);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;
}

#define GEN8_GPGPU_WALKER_length              15
#define GEN8_GPGPU_WALKER_length_bias          2
#define GEN8_GPGPU_WALKER_header                \
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      1,  \
   .SubOpcode                           =      5,  \
   .DWordLength                         =     13

struct GEN8_GPGPU_WALKER {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   bool                                 IndirectParameterEnable;
   bool                                 PredicateEnable;
   uint32_t                             DWordLength;
   uint32_t                             InterfaceDescriptorOffset;
   uint32_t                             IndirectDataLength;
   uint64_t                             IndirectDataStartAddress;
   uint32_t                             SIMDSize;
#define SIMD8                                    0
#define SIMD16                                   1
#define SIMD32                                   2
   uint32_t                             ThreadDepthCounterMaximum;
   uint32_t                             ThreadHeightCounterMaximum;
   uint32_t                             ThreadWidthCounterMaximum;
   uint32_t                             ThreadGroupIDStartingX;
   uint32_t                             ThreadGroupIDXDimension;
   uint32_t                             ThreadGroupIDStartingY;
   uint32_t                             ThreadGroupIDYDimension;
   uint32_t                             ThreadGroupIDStartingResumeZ;
   uint32_t                             ThreadGroupIDZDimension;
   uint32_t                             RightExecutionMask;
   uint32_t                             BottomExecutionMask;
};

static inline void
GEN8_GPGPU_WALKER_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_GPGPU_WALKER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->IndirectParameterEnable, 10, 10) |
      __gen_uint(values->PredicateEnable, 8, 8) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->InterfaceDescriptorOffset, 0, 5);

   dw[2] =
      __gen_uint(values->IndirectDataLength, 0, 16);

   dw[3] =
      __gen_offset(values->IndirectDataStartAddress, 6, 31);

   dw[4] =
      __gen_uint(values->SIMDSize, 30, 31) |
      __gen_uint(values->ThreadDepthCounterMaximum, 16, 21) |
      __gen_uint(values->ThreadHeightCounterMaximum, 8, 13) |
      __gen_uint(values->ThreadWidthCounterMaximum, 0, 5);

   dw[5] =
      __gen_uint(values->ThreadGroupIDStartingX, 0, 31);

   dw[6] = 0;

   dw[7] =
      __gen_uint(values->ThreadGroupIDXDimension, 0, 31);

   dw[8] =
      __gen_uint(values->ThreadGroupIDStartingY, 0, 31);

   dw[9] = 0;

   dw[10] =
      __gen_uint(values->ThreadGroupIDYDimension, 0, 31);

   dw[11] =
      __gen_uint(values->ThreadGroupIDStartingResumeZ, 0, 31);

   dw[12] =
      __gen_uint(values->ThreadGroupIDZDimension, 0, 31);

   dw[13] =
      __gen_uint(values->RightExecutionMask, 0, 31);

   dw[14] =
      __gen_uint(values->BottomExecutionMask, 0, 31);
}

#define GEN8_MEDIA_CURBE_LOAD_length           4
#define GEN8_MEDIA_CURBE_LOAD_length_bias      2
#define GEN8_MEDIA_CURBE_LOAD_header            \
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      0,  \
   .SubOpcode                           =      1,  \
   .DWordLength                         =      2

struct GEN8_MEDIA_CURBE_LOAD {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             CURBETotalDataLength;
   uint32_t                             CURBEDataStartAddress;
};

static inline void
GEN8_MEDIA_CURBE_LOAD_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_MEDIA_CURBE_LOAD * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] = 0;

   dw[2] =
      __gen_uint(values->CURBETotalDataLength, 0, 16);

   dw[3] =
      __gen_uint(values->CURBEDataStartAddress, 0, 31);
}

#define GEN8_MEDIA_INTERFACE_DESCRIPTOR_LOAD_length      4
#define GEN8_MEDIA_INTERFACE_DESCRIPTOR_LOAD_length_bias      2
#define GEN8_MEDIA_INTERFACE_DESCRIPTOR_LOAD_header\
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      0,  \
   .SubOpcode                           =      2,  \
   .DWordLength                         =      2

struct GEN8_MEDIA_INTERFACE_DESCRIPTOR_LOAD {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             InterfaceDescriptorTotalLength;
   uint64_t                             InterfaceDescriptorDataStartAddress;
};

static inline void
GEN8_MEDIA_INTERFACE_DESCRIPTOR_LOAD_pack(__gen_user_data *data, void * restrict dst,
                                          const struct GEN8_MEDIA_INTERFACE_DESCRIPTOR_LOAD * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] = 0;

   dw[2] =
      __gen_uint(values->InterfaceDescriptorTotalLength, 0, 16);

   dw[3] =
      __gen_offset(values->InterfaceDescriptorDataStartAddress, 0, 31);
}

#define GEN8_MEDIA_OBJECT_length_bias          2
#define GEN8_MEDIA_OBJECT_header                \
   .CommandType                         =      3,  \
   .MediaCommandPipeline                =      2,  \
   .MediaCommandOpcode                  =      1,  \
   .MediaCommandSubOpcode               =      0,  \
   .DWordLength                         =      4

struct GEN8_MEDIA_OBJECT {
   uint32_t                             CommandType;
   uint32_t                             MediaCommandPipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             MediaCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             InterfaceDescriptorOffset;
   bool                                 ChildrenPresent;
   uint32_t                             ThreadSynchronization;
#define Nothreadsynchronization                  0
#define Threaddispatchissynchronizedbythespawnrootthreadmessage 1
   uint32_t                             ForceDestination;
   uint32_t                             UseScoreboard;
#define Notusingscoreboard                       0
#define Usingscoreboard                          1
   uint32_t                             SliceDestinationSelect;
#define Slice0                                   0
#define Slice1                                   1
#define Slice2                                   2
   uint32_t                             SubSliceDestinationSelect;
#define SubSlice2                                2
#define SubSlice1                                1
#define SubSlice0                                0
   uint32_t                             IndirectDataLength;
   __gen_address_type                   IndirectDataStartAddress;
   uint32_t                             ScoredboardY;
   uint32_t                             ScoreboardX;
   uint32_t                             ScoreboardColor;
   uint32_t                             ScoreboardMask;
   /* variable length fields follow */
};

static inline void
GEN8_MEDIA_OBJECT_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_MEDIA_OBJECT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MediaCommandPipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->MediaCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] =
      __gen_uint(values->InterfaceDescriptorOffset, 0, 5);

   dw[2] =
      __gen_uint(values->ChildrenPresent, 31, 31) |
      __gen_uint(values->ThreadSynchronization, 24, 24) |
      __gen_uint(values->ForceDestination, 22, 22) |
      __gen_uint(values->UseScoreboard, 21, 21) |
      __gen_uint(values->SliceDestinationSelect, 19, 20) |
      __gen_uint(values->SubSliceDestinationSelect, 17, 18) |
      __gen_uint(values->IndirectDataLength, 0, 16);

   dw[3] = __gen_combine_address(data, &dw[3], values->IndirectDataStartAddress, 0);

   dw[4] =
      __gen_uint(values->ScoredboardY, 16, 24) |
      __gen_uint(values->ScoreboardX, 0, 8);

   dw[5] =
      __gen_uint(values->ScoreboardColor, 16, 19) |
      __gen_uint(values->ScoreboardMask, 0, 7);
}

#define GEN8_MEDIA_OBJECT_GRPID_length_bias      2
#define GEN8_MEDIA_OBJECT_GRPID_header          \
   .CommandType                         =      3,  \
   .MediaCommandPipeline                =      2,  \
   .MediaCommandOpcode                  =      1,  \
   .MediaCommandSubOpcode               =      6,  \
   .DWordLength                         =      5

struct GEN8_MEDIA_OBJECT_GRPID {
   uint32_t                             CommandType;
   uint32_t                             MediaCommandPipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             MediaCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             InterfaceDescriptorOffset;
   uint32_t                             EndofThreadGroup;
   uint32_t                             ForceDestination;
   uint32_t                             UseScoreboard;
#define Notusingscoreboard                       0
#define Usingscoreboard                          1
   uint32_t                             SliceDestinationSelect;
#define Slice0                                   0
#define Slice1                                   1
#define Slice2                                   2
   uint32_t                             SubSliceDestinationSelect;
#define SubSlice2                                2
#define SubSlice1                                1
#define SubSlice0                                0
   uint32_t                             IndirectDataLength;
   __gen_address_type                   IndirectDataStartAddress;
   uint32_t                             ScoreboardY;
   uint32_t                             ScoreboardX;
   uint32_t                             ScoreboardColor;
   uint32_t                             ScoreboardMask;
   uint32_t                             GroupID;
   /* variable length fields follow */
};

static inline void
GEN8_MEDIA_OBJECT_GRPID_pack(__gen_user_data *data, void * restrict dst,
                             const struct GEN8_MEDIA_OBJECT_GRPID * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MediaCommandPipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->MediaCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] =
      __gen_uint(values->InterfaceDescriptorOffset, 0, 5);

   dw[2] =
      __gen_uint(values->EndofThreadGroup, 23, 23) |
      __gen_uint(values->ForceDestination, 22, 22) |
      __gen_uint(values->UseScoreboard, 21, 21) |
      __gen_uint(values->SliceDestinationSelect, 19, 20) |
      __gen_uint(values->SubSliceDestinationSelect, 17, 18) |
      __gen_uint(values->IndirectDataLength, 0, 16);

   dw[3] = __gen_combine_address(data, &dw[3], values->IndirectDataStartAddress, 0);

   dw[4] =
      __gen_uint(values->ScoreboardY, 16, 24) |
      __gen_uint(values->ScoreboardX, 0, 8);

   dw[5] =
      __gen_uint(values->ScoreboardColor, 16, 19) |
      __gen_uint(values->ScoreboardMask, 0, 7);

   dw[6] =
      __gen_uint(values->GroupID, 0, 31);
}

#define GEN8_MEDIA_OBJECT_PRT_length          16
#define GEN8_MEDIA_OBJECT_PRT_length_bias      2
#define GEN8_MEDIA_OBJECT_PRT_header            \
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      1,  \
   .SubOpcode                           =      2,  \
   .DWordLength                         =     14

struct GEN8_MEDIA_OBJECT_PRT {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             InterfaceDescriptorOffset;
   bool                                 ChildrenPresent;
   bool                                 PRT_FenceNeeded;
   uint32_t                             PRT_FenceType;
#define Rootthreadqueue                          0
#define VFEstateflush                            1
   uint32_t                             InlineData[12];
};

static inline void
GEN8_MEDIA_OBJECT_PRT_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_MEDIA_OBJECT_PRT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] =
      __gen_uint(values->InterfaceDescriptorOffset, 0, 5);

   dw[2] =
      __gen_uint(values->ChildrenPresent, 31, 31) |
      __gen_uint(values->PRT_FenceNeeded, 23, 23) |
      __gen_uint(values->PRT_FenceType, 22, 22);

   dw[3] = 0;

   dw[4] =
      __gen_uint(values->InlineData[0], 0, 31);

   dw[5] =
      __gen_uint(values->InlineData[1], 0, 31);

   dw[6] =
      __gen_uint(values->InlineData[2], 0, 31);

   dw[7] =
      __gen_uint(values->InlineData[3], 0, 31);

   dw[8] =
      __gen_uint(values->InlineData[4], 0, 31);

   dw[9] =
      __gen_uint(values->InlineData[5], 0, 31);

   dw[10] =
      __gen_uint(values->InlineData[6], 0, 31);

   dw[11] =
      __gen_uint(values->InlineData[7], 0, 31);

   dw[12] =
      __gen_uint(values->InlineData[8], 0, 31);

   dw[13] =
      __gen_uint(values->InlineData[9], 0, 31);

   dw[14] =
      __gen_uint(values->InlineData[10], 0, 31);

   dw[15] =
      __gen_uint(values->InlineData[11], 0, 31);
}

#define GEN8_MEDIA_OBJECT_WALKER_length_bias      2
#define GEN8_MEDIA_OBJECT_WALKER_header         \
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      1,  \
   .SubOpcode                           =      3,  \
   .DWordLength                         =     15

struct GEN8_MEDIA_OBJECT_WALKER {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             InterfaceDescriptorOffset;
   uint32_t                             ChildrenPresent;
   uint32_t                             ThreadSynchronization;
#define Nothreadsynchronization                  0
#define Threaddispatchissynchronizedbythespawnrootthreadmessage 1
   uint32_t                             UseScoreboard;
#define Notusingscoreboard                       0
#define Usingscoreboard                          1
   uint32_t                             IndirectDataLength;
   uint64_t                             IndirectDataStartAddress;
   uint32_t                             GroupIDLoopSelect;
   uint32_t                             ScoreboardMask;
   uint32_t                             ColorCountMinusOne;
   uint32_t                             MiddleLoopExtraSteps;
   int32_t                              LocalMidLoopUnitY;
   int32_t                              MidLoopUnitX;
   uint32_t                             GlobalLoopExecCount;
   uint32_t                             LocalLoopExecCount;
   uint32_t                             BlockResolutionY;
   uint32_t                             BlockResolutionX;
   uint32_t                             LocalStartY;
   uint32_t                             LocalStartX;
   int32_t                              LocalOuterLoopStrideY;
   int32_t                              LocalOuterLoopStrideX;
   int32_t                              LocalInnerLoopUnitY;
   int32_t                              LocalInnerLoopUnitX;
   uint32_t                             GlobalResolutionY;
   uint32_t                             GlobalResolutionX;
   int32_t                              GlobalStartY;
   int32_t                              GlobalStartX;
   int32_t                              GlobalOuterLoopStrideY;
   int32_t                              GlobalOuterLoopStrideX;
   int32_t                              GlobalInnerLoopUnitY;
   int32_t                              GlobalInnerLoopUnitX;
   /* variable length fields follow */
};

static inline void
GEN8_MEDIA_OBJECT_WALKER_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_MEDIA_OBJECT_WALKER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] =
      __gen_uint(values->InterfaceDescriptorOffset, 0, 5);

   dw[2] =
      __gen_uint(values->ChildrenPresent, 31, 31) |
      __gen_uint(values->ThreadSynchronization, 24, 24) |
      __gen_uint(values->UseScoreboard, 21, 21) |
      __gen_uint(values->IndirectDataLength, 0, 16);

   dw[3] =
      __gen_offset(values->IndirectDataStartAddress, 0, 31);

   dw[4] = 0;

   dw[5] =
      __gen_uint(values->GroupIDLoopSelect, 8, 31) |
      __gen_uint(values->ScoreboardMask, 0, 7);

   dw[6] =
      __gen_uint(values->ColorCountMinusOne, 24, 27) |
      __gen_uint(values->MiddleLoopExtraSteps, 16, 20) |
      __gen_sint(values->LocalMidLoopUnitY, 12, 13) |
      __gen_sint(values->MidLoopUnitX, 8, 9);

   dw[7] =
      __gen_uint(values->GlobalLoopExecCount, 16, 25) |
      __gen_uint(values->LocalLoopExecCount, 0, 9);

   dw[8] =
      __gen_uint(values->BlockResolutionY, 16, 24) |
      __gen_uint(values->BlockResolutionX, 0, 8);

   dw[9] =
      __gen_uint(values->LocalStartY, 16, 24) |
      __gen_uint(values->LocalStartX, 0, 8);

   dw[10] = 0;

   dw[11] =
      __gen_sint(values->LocalOuterLoopStrideY, 16, 25) |
      __gen_sint(values->LocalOuterLoopStrideX, 0, 9);

   dw[12] =
      __gen_sint(values->LocalInnerLoopUnitY, 16, 25) |
      __gen_sint(values->LocalInnerLoopUnitX, 0, 9);

   dw[13] =
      __gen_uint(values->GlobalResolutionY, 16, 24) |
      __gen_uint(values->GlobalResolutionX, 0, 8);

   dw[14] =
      __gen_sint(values->GlobalStartY, 16, 25) |
      __gen_sint(values->GlobalStartX, 0, 9);

   dw[15] =
      __gen_sint(values->GlobalOuterLoopStrideY, 16, 25) |
      __gen_sint(values->GlobalOuterLoopStrideX, 0, 9);

   dw[16] =
      __gen_sint(values->GlobalInnerLoopUnitY, 16, 25) |
      __gen_sint(values->GlobalInnerLoopUnitX, 0, 9);
}

#define GEN8_MEDIA_STATE_FLUSH_length          2
#define GEN8_MEDIA_STATE_FLUSH_length_bias      2
#define GEN8_MEDIA_STATE_FLUSH_header           \
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      0,  \
   .SubOpcode                           =      4,  \
   .DWordLength                         =      0

struct GEN8_MEDIA_STATE_FLUSH {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   uint32_t                             DWordLength;
   bool                                 FlushtoGO;
   uint32_t                             WatermarkRequired;
   uint32_t                             InterfaceDescriptorOffset;
};

static inline void
GEN8_MEDIA_STATE_FLUSH_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_MEDIA_STATE_FLUSH * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   dw[1] =
      __gen_uint(values->FlushtoGO, 7, 7) |
      __gen_uint(values->WatermarkRequired, 6, 6) |
      __gen_uint(values->InterfaceDescriptorOffset, 0, 5);
}

#define GEN8_MEDIA_VFE_STATE_length            9
#define GEN8_MEDIA_VFE_STATE_length_bias       2
#define GEN8_MEDIA_VFE_STATE_header             \
   .CommandType                         =      3,  \
   .Pipeline                            =      2,  \
   .MediaCommandOpcode                  =      0,  \
   .SubOpcode                           =      0,  \
   .DWordLength                         =      7

struct GEN8_MEDIA_VFE_STATE {
   uint32_t                             CommandType;
   uint32_t                             Pipeline;
   uint32_t                             MediaCommandOpcode;
   uint32_t                             SubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   ScratchSpaceBasePointer;
   uint32_t                             StackSize;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             NumberofURBEntries;
   uint32_t                             ResetGatewayTimer;
#define Maintainingtheexistingtimestampstate     0
#define Resettingrelativetimerandlatchingtheglobaltimestamp 1
   uint32_t                             BypassGatewayControl;
#define MaintainingOpenGatewayForwardMsgCloseGatewayprotocollegacymode 0
#define BypassingOpenGatewayCloseGatewayprotocol 1
   uint32_t                             SliceDisable;
#define AllSubslicesEnabled                      0
#define OnlySlice0Enabled                        1
#define OnlySlice0Subslice0Enabled               3
   uint32_t                             URBEntryAllocationSize;
   uint32_t                             CURBEAllocationSize;
   bool                                 ScoreboardEnable;
   uint32_t                             ScoreboardType;
#define StallingScoreboard                       0
#define NonStallingScoreboard                    1
   uint32_t                             ScoreboardMask;
   int32_t                              Scoreboard3DeltaY;
   int32_t                              Scoreboard3DeltaX;
   int32_t                              Scoreboard2DeltaY;
   int32_t                              Scoreboard2DeltaX;
   int32_t                              Scoreboard1DeltaY;
   int32_t                              Scoreboard1DeltaX;
   int32_t                              Scoreboard0DeltaY;
   int32_t                              Scoreboard0DeltaX;
   int32_t                              Scoreboard7DeltaY;
   int32_t                              Scoreboard7DeltaX;
   int32_t                              Scoreboard6DeltaY;
   int32_t                              Scoreboard6DeltaX;
   int32_t                              Scoreboard5DeltaY;
   int32_t                              Scoreboard5DeltaX;
   int32_t                              Scoreboard4DeltaY;
   int32_t                              Scoreboard4DeltaX;
};

static inline void
GEN8_MEDIA_VFE_STATE_pack(__gen_user_data *data, void * restrict dst,
                          const struct GEN8_MEDIA_VFE_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->Pipeline, 27, 28) |
      __gen_uint(values->MediaCommandOpcode, 24, 26) |
      __gen_uint(values->SubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 15);

   const uint64_t v1 =
      __gen_uint(values->StackSize, 4, 7) |
      __gen_uint(values->PerThreadScratchSpace, 0, 3);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->ScratchSpaceBasePointer, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   dw[3] =
      __gen_uint(values->MaximumNumberofThreads, 16, 31) |
      __gen_uint(values->NumberofURBEntries, 8, 15) |
      __gen_uint(values->ResetGatewayTimer, 7, 7) |
      __gen_uint(values->BypassGatewayControl, 6, 6);

   dw[4] =
      __gen_uint(values->SliceDisable, 0, 1);

   dw[5] =
      __gen_uint(values->URBEntryAllocationSize, 16, 31) |
      __gen_uint(values->CURBEAllocationSize, 0, 15);

   dw[6] =
      __gen_uint(values->ScoreboardEnable, 31, 31) |
      __gen_uint(values->ScoreboardType, 30, 30) |
      __gen_uint(values->ScoreboardMask, 0, 7);

   dw[7] =
      __gen_sint(values->Scoreboard3DeltaY, 28, 31) |
      __gen_sint(values->Scoreboard3DeltaX, 24, 27) |
      __gen_sint(values->Scoreboard2DeltaY, 20, 23) |
      __gen_sint(values->Scoreboard2DeltaX, 16, 19) |
      __gen_sint(values->Scoreboard1DeltaY, 12, 15) |
      __gen_sint(values->Scoreboard1DeltaX, 8, 11) |
      __gen_sint(values->Scoreboard0DeltaY, 4, 7) |
      __gen_sint(values->Scoreboard0DeltaX, 0, 3);

   dw[8] =
      __gen_sint(values->Scoreboard7DeltaY, 28, 31) |
      __gen_sint(values->Scoreboard7DeltaX, 24, 27) |
      __gen_sint(values->Scoreboard6DeltaY, 20, 23) |
      __gen_sint(values->Scoreboard6DeltaX, 16, 19) |
      __gen_sint(values->Scoreboard5DeltaY, 12, 15) |
      __gen_sint(values->Scoreboard5DeltaX, 8, 11) |
      __gen_sint(values->Scoreboard4DeltaY, 4, 7) |
      __gen_sint(values->Scoreboard4DeltaX, 0, 3);
}

#define GEN8_MI_ARB_CHECK_length               1
#define GEN8_MI_ARB_CHECK_length_bias          1
#define GEN8_MI_ARB_CHECK_header                \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      5

struct GEN8_MI_ARB_CHECK {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
};

static inline void
GEN8_MI_ARB_CHECK_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_MI_ARB_CHECK * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28);
}

#define GEN8_MI_ATOMIC_length                  3
#define GEN8_MI_ATOMIC_length_bias             2
#define GEN8_MI_ATOMIC_header                   \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     47,  \
   .DWordLength                         =      1

struct GEN8_MI_ATOMIC {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             MemoryType;
#define PerProcessGraphicsAddress                0
#define GlobalGraphicsAddress                    1
   bool                                 PostSyncOperation;
   uint32_t                             DataSize;
#define DWORD                                    0
#define QWORD                                    1
#define OCTWORD                                  2
#define RESERVED                                 3
   uint32_t                             InlineData;
   uint32_t                             CSSTALL;
   uint32_t                             ReturnDataControl;
   uint32_t                             ATOMICOPCODE;
   uint32_t                             DWordLength;
   __gen_address_type                   MemoryAddress;
   uint32_t                             Operand1DataDword0;
   uint32_t                             Operand2DataDword0;
   uint32_t                             Operand1DataDword1;
   uint32_t                             Operand2DataDword1;
   uint32_t                             Operand1DataDword2;
   uint32_t                             Operand2DataDword2;
   uint32_t                             Operand1DataDword3;
   uint32_t                             Operand2DataDword3;
};

static inline void
GEN8_MI_ATOMIC_pack(__gen_user_data *data, void * restrict dst,
                    const struct GEN8_MI_ATOMIC * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->MemoryType, 22, 22) |
      __gen_uint(values->PostSyncOperation, 21, 21) |
      __gen_uint(values->DataSize, 19, 20) |
      __gen_uint(values->InlineData, 18, 18) |
      __gen_uint(values->CSSTALL, 17, 17) |
      __gen_uint(values->ReturnDataControl, 16, 16) |
      __gen_uint(values->ATOMICOPCODE, 8, 15) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->MemoryAddress, 0);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;
}

#define GEN8_MI_BATCH_BUFFER_END_length        1
#define GEN8_MI_BATCH_BUFFER_END_length_bias      1
#define GEN8_MI_BATCH_BUFFER_END_header         \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     10

struct GEN8_MI_BATCH_BUFFER_END {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
};

static inline void
GEN8_MI_BATCH_BUFFER_END_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_MI_BATCH_BUFFER_END * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28);
}

#define GEN8_MI_BATCH_BUFFER_START_length      3
#define GEN8_MI_BATCH_BUFFER_START_length_bias      2
#define GEN8_MI_BATCH_BUFFER_START_header       \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     49,  \
   .DWordLength                         =      1

struct GEN8_MI_BATCH_BUFFER_START {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             _2ndLevelBatchBuffer;
#define _1stlevelbatch                           0
#define _2ndlevelbatch                           1
   bool                                 AddOffsetEnable;
   bool                                 PredicationEnable;
   bool                                 ResourceStreamerEnable;
   uint32_t                             AddressSpaceIndicator;
#define ASI_GGTT                                 0
#define ASI_PPGTT                                1
   uint32_t                             DWordLength;
   __gen_address_type                   BatchBufferStartAddress;
};

static inline void
GEN8_MI_BATCH_BUFFER_START_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN8_MI_BATCH_BUFFER_START * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->_2ndLevelBatchBuffer, 22, 22) |
      __gen_uint(values->AddOffsetEnable, 16, 16) |
      __gen_uint(values->PredicationEnable, 15, 15) |
      __gen_uint(values->ResourceStreamerEnable, 10, 10) |
      __gen_uint(values->AddressSpaceIndicator, 8, 8) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->BatchBufferStartAddress, 0);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;
}

#define GEN8_MI_CLFLUSH_length_bias            2
#define GEN8_MI_CLFLUSH_header                  \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     39,  \
   .DWordLength                         =      1

struct GEN8_MI_CLFLUSH {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 UseGlobalGTT;
   uint32_t                             DWordLength;
   __gen_address_type                   PageBaseAddress;
   uint32_t                             StartingCachelineOffset;
   /* variable length fields follow */
};

static inline void
GEN8_MI_CLFLUSH_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_MI_CLFLUSH * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UseGlobalGTT, 22, 22) |
      __gen_uint(values->DWordLength, 0, 9);

   const uint64_t v1 =
      __gen_uint(values->StartingCachelineOffset, 6, 11);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->PageBaseAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;
}

#define GEN8_MI_CONDITIONAL_BATCH_BUFFER_END_length      3
#define GEN8_MI_CONDITIONAL_BATCH_BUFFER_END_length_bias      2
#define GEN8_MI_CONDITIONAL_BATCH_BUFFER_END_header\
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     54,  \
   .CompareSemaphore                    =      0,  \
   .DWordLength                         =      1

struct GEN8_MI_CONDITIONAL_BATCH_BUFFER_END {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 UseGlobalGTT;
   uint32_t                             CompareSemaphore;
   uint32_t                             DWordLength;
   uint32_t                             CompareDataDword;
   __gen_address_type                   CompareAddress;
};

static inline void
GEN8_MI_CONDITIONAL_BATCH_BUFFER_END_pack(__gen_user_data *data, void * restrict dst,
                                          const struct GEN8_MI_CONDITIONAL_BATCH_BUFFER_END * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UseGlobalGTT, 22, 22) |
      __gen_uint(values->CompareSemaphore, 21, 21) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->CompareDataDword, 0, 31);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->CompareAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;
}

#define GEN8_MI_COPY_MEM_MEM_length            5
#define GEN8_MI_COPY_MEM_MEM_length_bias       2
#define GEN8_MI_COPY_MEM_MEM_header             \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     46,  \
   .DWordLength                         =      3

struct GEN8_MI_COPY_MEM_MEM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 UseGlobalGTTSource;
   bool                                 UseGlobalGTTDestination;
   uint32_t                             DWordLength;
   __gen_address_type                   DestinationMemoryAddress;
   __gen_address_type                   SourceMemoryAddress;
};

static inline void
GEN8_MI_COPY_MEM_MEM_pack(__gen_user_data *data, void * restrict dst,
                          const struct GEN8_MI_COPY_MEM_MEM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UseGlobalGTTSource, 22, 22) |
      __gen_uint(values->UseGlobalGTTDestination, 21, 21) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->DestinationMemoryAddress, 0);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   const uint64_t v3_address =
      __gen_combine_address(data, &dw[3], values->SourceMemoryAddress, 0);
   dw[3] = v3_address;
   dw[4] = v3_address >> 32;
}

#define GEN8_MI_LOAD_REGISTER_IMM_length       3
#define GEN8_MI_LOAD_REGISTER_IMM_length_bias      2
#define GEN8_MI_LOAD_REGISTER_IMM_header        \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     34,  \
   .DWordLength                         =      1

struct GEN8_MI_LOAD_REGISTER_IMM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             ByteWriteDisables;
   uint32_t                             DWordLength;
   uint64_t                             RegisterOffset;
   uint32_t                             DataDWord;
};

static inline void
GEN8_MI_LOAD_REGISTER_IMM_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_MI_LOAD_REGISTER_IMM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->ByteWriteDisables, 8, 11) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->RegisterOffset, 2, 22);

   dw[2] =
      __gen_uint(values->DataDWord, 0, 31);
}

#define GEN8_MI_LOAD_REGISTER_MEM_length       4
#define GEN8_MI_LOAD_REGISTER_MEM_length_bias      2
#define GEN8_MI_LOAD_REGISTER_MEM_header        \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     41,  \
   .DWordLength                         =      2

struct GEN8_MI_LOAD_REGISTER_MEM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 UseGlobalGTT;
   bool                                 AsyncModeEnable;
   uint32_t                             DWordLength;
   uint64_t                             RegisterAddress;
   __gen_address_type                   MemoryAddress;
};

static inline void
GEN8_MI_LOAD_REGISTER_MEM_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_MI_LOAD_REGISTER_MEM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UseGlobalGTT, 22, 22) |
      __gen_uint(values->AsyncModeEnable, 21, 21) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->RegisterAddress, 2, 22);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->MemoryAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;
}

#define GEN8_MI_LOAD_REGISTER_REG_length       3
#define GEN8_MI_LOAD_REGISTER_REG_length_bias      2
#define GEN8_MI_LOAD_REGISTER_REG_header        \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     42,  \
   .DWordLength                         =      1

struct GEN8_MI_LOAD_REGISTER_REG {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   uint64_t                             SourceRegisterAddress;
   uint64_t                             DestinationRegisterAddress;
};

static inline void
GEN8_MI_LOAD_REGISTER_REG_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_MI_LOAD_REGISTER_REG * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->SourceRegisterAddress, 2, 22);

   dw[2] =
      __gen_offset(values->DestinationRegisterAddress, 2, 22);
}

#define GEN8_MI_LOAD_SCAN_LINES_EXCL_length      2
#define GEN8_MI_LOAD_SCAN_LINES_EXCL_length_bias      2
#define GEN8_MI_LOAD_SCAN_LINES_EXCL_header     \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     19,  \
   .DWordLength                         =      0

struct GEN8_MI_LOAD_SCAN_LINES_EXCL {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DisplayPlaneSelect;
#define DisplayPlaneA                            0
#define DisplayPlaneB                            1
#define DisplayPlaneC                            4
   uint32_t                             DWordLength;
   uint32_t                             StartScanLineNumber;
   uint32_t                             EndScanLineNumber;
};

static inline void
GEN8_MI_LOAD_SCAN_LINES_EXCL_pack(__gen_user_data *data, void * restrict dst,
                                  const struct GEN8_MI_LOAD_SCAN_LINES_EXCL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DisplayPlaneSelect, 19, 21) |
      __gen_uint(values->DWordLength, 0, 5);

   dw[1] =
      __gen_uint(values->StartScanLineNumber, 16, 28) |
      __gen_uint(values->EndScanLineNumber, 0, 12);
}

#define GEN8_MI_LOAD_SCAN_LINES_INCL_length      2
#define GEN8_MI_LOAD_SCAN_LINES_INCL_length_bias      2
#define GEN8_MI_LOAD_SCAN_LINES_INCL_header     \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     18,  \
   .DWordLength                         =      0

struct GEN8_MI_LOAD_SCAN_LINES_INCL {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DisplayPlaneSelect;
#define DisplayPlaneA                            0
#define DisplayPlaneB                            1
#define DisplayPlaneC                            4
   bool                                 ScanLineEventDoneForward;
   uint32_t                             DWordLength;
   uint32_t                             StartScanLineNumber;
   uint32_t                             EndScanLineNumber;
};

static inline void
GEN8_MI_LOAD_SCAN_LINES_INCL_pack(__gen_user_data *data, void * restrict dst,
                                  const struct GEN8_MI_LOAD_SCAN_LINES_INCL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DisplayPlaneSelect, 19, 21) |
      __gen_uint(values->ScanLineEventDoneForward, 17, 18) |
      __gen_uint(values->DWordLength, 0, 5);

   dw[1] =
      __gen_uint(values->StartScanLineNumber, 16, 28) |
      __gen_uint(values->EndScanLineNumber, 0, 12);
}

#define GEN8_MI_LOAD_URB_MEM_length            4
#define GEN8_MI_LOAD_URB_MEM_length_bias       2
#define GEN8_MI_LOAD_URB_MEM_header             \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     44,  \
   .DWordLength                         =      2

struct GEN8_MI_LOAD_URB_MEM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   uint32_t                             URBAddress;
   __gen_address_type                   MemoryAddress;
};

static inline void
GEN8_MI_LOAD_URB_MEM_pack(__gen_user_data *data, void * restrict dst,
                          const struct GEN8_MI_LOAD_URB_MEM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->URBAddress, 2, 14);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->MemoryAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;
}

#define GEN8_MI_MATH_length_bias               2
#define GEN8_MI_MATH_header                     \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     26,  \
   .DWordLength                         =      0

struct GEN8_MI_MATH {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ALUINSTRUCTION1;
   uint32_t                             ALUINSTRUCTION2;
   /* variable length fields follow */
};

static inline void
GEN8_MI_MATH_pack(__gen_user_data *data, void * restrict dst,
                  const struct GEN8_MI_MATH * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 5);

   dw[1] =
      __gen_uint(values->ALUINSTRUCTION1, 0, 31);

   dw[2] =
      __gen_uint(values->ALUINSTRUCTION2, 0, 31);
}

#define GEN8_MI_NOOP_length                    1
#define GEN8_MI_NOOP_length_bias               1
#define GEN8_MI_NOOP_header                     \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      0

struct GEN8_MI_NOOP {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 IdentificationNumberRegisterWriteEnable;
   uint32_t                             IdentificationNumber;
};

static inline void
GEN8_MI_NOOP_pack(__gen_user_data *data, void * restrict dst,
                  const struct GEN8_MI_NOOP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->IdentificationNumberRegisterWriteEnable, 22, 22) |
      __gen_uint(values->IdentificationNumber, 0, 21);
}

#define GEN8_MI_PREDICATE_length               1
#define GEN8_MI_PREDICATE_length_bias          1
#define GEN8_MI_PREDICATE_header                \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     12

struct GEN8_MI_PREDICATE {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             LoadOperation;
#define LOAD_KEEP                                0
#define LOAD_LOAD                                2
#define LOAD_LOADINV                             3
   uint32_t                             CombineOperation;
#define COMBINE_SET                              0
#define COMBINE_AND                              1
#define COMBINE_OR                               2
#define COMBINE_XOR                              3
   uint32_t                             CompareOperation;
#define COMPARE_SRCS_EQUAL                       2
#define COMPARE_DELTAS_EQUAL                     3
};

static inline void
GEN8_MI_PREDICATE_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_MI_PREDICATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->LoadOperation, 6, 7) |
      __gen_uint(values->CombineOperation, 3, 4) |
      __gen_uint(values->CompareOperation, 0, 1);
}

#define GEN8_MI_REPORT_HEAD_length             1
#define GEN8_MI_REPORT_HEAD_length_bias        1
#define GEN8_MI_REPORT_HEAD_header              \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      7

struct GEN8_MI_REPORT_HEAD {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
};

static inline void
GEN8_MI_REPORT_HEAD_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_MI_REPORT_HEAD * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28);
}

#define GEN8_MI_REPORT_PERF_COUNT_length       4
#define GEN8_MI_REPORT_PERF_COUNT_length_bias      2
#define GEN8_MI_REPORT_PERF_COUNT_header        \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     40,  \
   .DWordLength                         =      2

struct GEN8_MI_REPORT_PERF_COUNT {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   MemoryAddress;
   uint32_t                             CoreModeEnable;
   bool                                 UseGlobalGTT;
   uint32_t                             ReportID;
};

static inline void
GEN8_MI_REPORT_PERF_COUNT_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_MI_REPORT_PERF_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 5);

   const uint64_t v1 =
      __gen_uint(values->CoreModeEnable, 4, 4) |
      __gen_uint(values->UseGlobalGTT, 0, 0);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->MemoryAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   dw[3] =
      __gen_uint(values->ReportID, 0, 31);
}

#define GEN8_MI_RS_CONTEXT_length              1
#define GEN8_MI_RS_CONTEXT_length_bias         1
#define GEN8_MI_RS_CONTEXT_header               \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     15

struct GEN8_MI_RS_CONTEXT {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             ResourceStreamerSave;
#define RS_Restore                               0
#define RS_Save                                  1
};

static inline void
GEN8_MI_RS_CONTEXT_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_MI_RS_CONTEXT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->ResourceStreamerSave, 0, 0);
}

#define GEN8_MI_RS_CONTROL_length              1
#define GEN8_MI_RS_CONTROL_length_bias         1
#define GEN8_MI_RS_CONTROL_header               \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      6

struct GEN8_MI_RS_CONTROL {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             ResourceStreamerControl;
#define RS_Stop                                  0
#define RS_Start                                 1
};

static inline void
GEN8_MI_RS_CONTROL_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_MI_RS_CONTROL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->ResourceStreamerControl, 0, 0);
}

#define GEN8_MI_RS_STORE_DATA_IMM_length       4
#define GEN8_MI_RS_STORE_DATA_IMM_length_bias      2
#define GEN8_MI_RS_STORE_DATA_IMM_header        \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     43,  \
   .DWordLength                         =      2

struct GEN8_MI_RS_STORE_DATA_IMM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   DestinationAddress;
   uint32_t                             CoreModeEnable;
   uint32_t                             DataDWord0;
};

static inline void
GEN8_MI_RS_STORE_DATA_IMM_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_MI_RS_STORE_DATA_IMM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1 =
      __gen_uint(values->CoreModeEnable, 0, 0);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->DestinationAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   dw[3] =
      __gen_uint(values->DataDWord0, 0, 31);
}

#define GEN8_MI_SEMAPHORE_SIGNAL_length        2
#define GEN8_MI_SEMAPHORE_SIGNAL_length_bias      2
#define GEN8_MI_SEMAPHORE_SIGNAL_header         \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     27,  \
   .DWordLength                         =      0

struct GEN8_MI_SEMAPHORE_SIGNAL {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 PostSyncOperation;
   uint32_t                             TargetEngineSelect;
#define RCS                                      0
#define VCS0                                     1
#define BCS                                      2
#define VECS                                     3
#define VCS1                                     4
   uint32_t                             DWordLength;
   uint32_t                             TargetContextID;
};

static inline void
GEN8_MI_SEMAPHORE_SIGNAL_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_MI_SEMAPHORE_SIGNAL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->PostSyncOperation, 21, 21) |
      __gen_uint(values->TargetEngineSelect, 15, 17) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->TargetContextID, 0, 31);
}

#define GEN8_MI_SEMAPHORE_WAIT_length          4
#define GEN8_MI_SEMAPHORE_WAIT_length_bias      2
#define GEN8_MI_SEMAPHORE_WAIT_header           \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     28,  \
   .DWordLength                         =      2

struct GEN8_MI_SEMAPHORE_WAIT {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             MemoryType;
#define PerProcessGraphicsAddress                0
#define GlobalGraphicsAddress                    1
   uint32_t                             WaitMode;
#define PollingMode                              1
#define SignalMode                               0
   uint32_t                             CompareOperation;
#define COMPARE_SAD_GREATER_THAN_SDD             0
#define COMPARE_SAD_GREATER_THAN_OR_EQUAL_SDD    1
#define COMPARE_SAD_LESS_THAN_SDD                2
#define COMPARE_SAD_LESS_THAN_OR_EQUAL_SDD       3
#define COMPARE_SAD_EQUAL_SDD                    4
#define COMPARE_SAD_NOT_EQUAL_SDD                5
   uint32_t                             DWordLength;
   uint32_t                             SemaphoreDataDword;
   __gen_address_type                   SemaphoreAddress;
   __gen_address_type                   SemaphoreAddressHigh;
};

static inline void
GEN8_MI_SEMAPHORE_WAIT_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_MI_SEMAPHORE_WAIT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->MemoryType, 22, 22) |
      __gen_uint(values->WaitMode, 15, 15) |
      __gen_uint(values->CompareOperation, 12, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->SemaphoreDataDword, 0, 31);

   dw[2] = __gen_combine_address(data, &dw[2], values->SemaphoreAddress, 0);

   dw[3] = __gen_combine_address(data, &dw[3], values->SemaphoreAddressHigh, 0);
}

#define GEN8_MI_SET_CONTEXT_length             2
#define GEN8_MI_SET_CONTEXT_length_bias        2
#define GEN8_MI_SET_CONTEXT_header              \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     24,  \
   .DWordLength                         =      0

struct GEN8_MI_SET_CONTEXT {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   LogicalContextAddress;
   uint32_t                             ReservedMustbe1;
   bool                                 CoreModeEnable;
   bool                                 ResourceStreamerStateSaveEnable;
   bool                                 ResourceStreamerStateRestoreEnable;
   uint32_t                             ForceRestore;
   uint32_t                             RestoreInhibit;
};

static inline void
GEN8_MI_SET_CONTEXT_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_MI_SET_CONTEXT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint32_t v1 =
      __gen_uint(values->ReservedMustbe1, 8, 8) |
      __gen_uint(values->CoreModeEnable, 4, 4) |
      __gen_uint(values->ResourceStreamerStateSaveEnable, 3, 3) |
      __gen_uint(values->ResourceStreamerStateRestoreEnable, 2, 2) |
      __gen_uint(values->ForceRestore, 1, 1) |
      __gen_uint(values->RestoreInhibit, 0, 0);
   dw[1] = __gen_combine_address(data, &dw[1], values->LogicalContextAddress, v1);
}

#define GEN8_MI_SET_PREDICATE_length           1
#define GEN8_MI_SET_PREDICATE_length_bias      1
#define GEN8_MI_SET_PREDICATE_header            \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      1

struct GEN8_MI_SET_PREDICATE {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             PREDICATEENABLE;
#define NOOPNever                                0
#define NOOPonResult2clear                       1
#define NOOPonResult2set                         2
#define NOOPonResultclear                        3
#define NOOPonResultset                          4
#define Executewhenonesliceenabled               5
#define Executewhentwoslicesareenabled           6
#define Executewhenthreeslicesareenabled         7
#define NOOPAlways                               15
};

static inline void
GEN8_MI_SET_PREDICATE_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_MI_SET_PREDICATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->PREDICATEENABLE, 0, 3);
}

#define GEN8_MI_STORE_DATA_IMM_length          4
#define GEN8_MI_STORE_DATA_IMM_length_bias      2
#define GEN8_MI_STORE_DATA_IMM_header           \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     32,  \
   .DWordLength                         =      2

struct GEN8_MI_STORE_DATA_IMM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 UseGlobalGTT;
   uint32_t                             StoreQword;
   uint32_t                             DWordLength;
   __gen_address_type                   Address;
   uint32_t                             CoreModeEnable;
   uint64_t                             ImmediateData;
};

static inline void
GEN8_MI_STORE_DATA_IMM_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_MI_STORE_DATA_IMM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UseGlobalGTT, 22, 22) |
      __gen_uint(values->StoreQword, 21, 21) |
      __gen_uint(values->DWordLength, 0, 9);

   const uint64_t v1 =
      __gen_uint(values->CoreModeEnable, 0, 0);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->Address, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   const uint64_t v3 =
      __gen_uint(values->ImmediateData, 0, 63);
   dw[3] = v3;
   dw[4] = v3 >> 32;
}

#define GEN8_MI_STORE_DATA_INDEX_length        3
#define GEN8_MI_STORE_DATA_INDEX_length_bias      2
#define GEN8_MI_STORE_DATA_INDEX_header         \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     33,  \
   .DWordLength                         =      1

struct GEN8_MI_STORE_DATA_INDEX {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             UsePerProcessHardwareStatusPage;
   uint32_t                             DWordLength;
   uint32_t                             Offset;
   uint32_t                             DataDWord0;
   uint32_t                             DataDWord1;
};

static inline void
GEN8_MI_STORE_DATA_INDEX_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_MI_STORE_DATA_INDEX * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UsePerProcessHardwareStatusPage, 21, 21) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->Offset, 2, 11);

   dw[2] =
      __gen_uint(values->DataDWord0, 0, 31);
}

#define GEN8_MI_STORE_REGISTER_MEM_length      4
#define GEN8_MI_STORE_REGISTER_MEM_length_bias      2
#define GEN8_MI_STORE_REGISTER_MEM_header       \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     36,  \
   .DWordLength                         =      2

struct GEN8_MI_STORE_REGISTER_MEM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 UseGlobalGTT;
   bool                                 PredicateEnable;
   uint32_t                             DWordLength;
   uint64_t                             RegisterAddress;
   __gen_address_type                   MemoryAddress;
};

static inline void
GEN8_MI_STORE_REGISTER_MEM_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN8_MI_STORE_REGISTER_MEM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->UseGlobalGTT, 22, 22) |
      __gen_uint(values->PredicateEnable, 21, 21) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->RegisterAddress, 2, 22);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->MemoryAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;
}

#define GEN8_MI_STORE_URB_MEM_length           4
#define GEN8_MI_STORE_URB_MEM_length_bias      2
#define GEN8_MI_STORE_URB_MEM_header            \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     45,  \
   .DWordLength                         =      2

struct GEN8_MI_STORE_URB_MEM {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   uint32_t                             URBAddress;
   __gen_address_type                   MemoryAddress;
};

static inline void
GEN8_MI_STORE_URB_MEM_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_MI_STORE_URB_MEM * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->URBAddress, 2, 14);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->MemoryAddress, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;
}

#define GEN8_MI_SUSPEND_FLUSH_length           1
#define GEN8_MI_SUSPEND_FLUSH_length_bias      1
#define GEN8_MI_SUSPEND_FLUSH_header            \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     11

struct GEN8_MI_SUSPEND_FLUSH {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 SuspendFlush;
};

static inline void
GEN8_MI_SUSPEND_FLUSH_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_MI_SUSPEND_FLUSH * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->SuspendFlush, 0, 0);
}

#define GEN8_MI_TOPOLOGY_FILTER_length         1
#define GEN8_MI_TOPOLOGY_FILTER_length_bias      1
#define GEN8_MI_TOPOLOGY_FILTER_header          \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     13

struct GEN8_MI_TOPOLOGY_FILTER {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   enum GEN8_3D_Prim_Topo_Type          TopologyFilterValue;
};

static inline void
GEN8_MI_TOPOLOGY_FILTER_pack(__gen_user_data *data, void * restrict dst,
                             const struct GEN8_MI_TOPOLOGY_FILTER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->TopologyFilterValue, 0, 5);
}

#define GEN8_MI_URB_ATOMIC_ALLOC_length        1
#define GEN8_MI_URB_ATOMIC_ALLOC_length_bias      1
#define GEN8_MI_URB_ATOMIC_ALLOC_header         \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      9

struct GEN8_MI_URB_ATOMIC_ALLOC {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             URBAtomicStorageOffset;
   uint32_t                             URBAtomicStorageSize;
};

static inline void
GEN8_MI_URB_ATOMIC_ALLOC_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_MI_URB_ATOMIC_ALLOC * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->URBAtomicStorageOffset, 12, 19) |
      __gen_uint(values->URBAtomicStorageSize, 0, 8);
}

#define GEN8_MI_URB_CLEAR_length               2
#define GEN8_MI_URB_CLEAR_length_bias          2
#define GEN8_MI_URB_CLEAR_header                \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =     25,  \
   .DWordLength                         =      0

struct GEN8_MI_URB_CLEAR {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   uint32_t                             DWordLength;
   uint32_t                             URBClearLength;
   uint64_t                             URBAddress;
};

static inline void
GEN8_MI_URB_CLEAR_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_MI_URB_CLEAR * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->URBClearLength, 16, 29) |
      __gen_offset(values->URBAddress, 0, 14);
}

#define GEN8_MI_USER_INTERRUPT_length          1
#define GEN8_MI_USER_INTERRUPT_length_bias      1
#define GEN8_MI_USER_INTERRUPT_header           \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      2

struct GEN8_MI_USER_INTERRUPT {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
};

static inline void
GEN8_MI_USER_INTERRUPT_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_MI_USER_INTERRUPT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28);
}

#define GEN8_MI_WAIT_FOR_EVENT_length          1
#define GEN8_MI_WAIT_FOR_EVENT_length_bias      1
#define GEN8_MI_WAIT_FOR_EVENT_header           \
   .CommandType                         =      0,  \
   .MICommandOpcode                     =      3

struct GEN8_MI_WAIT_FOR_EVENT {
   uint32_t                             CommandType;
   uint32_t                             MICommandOpcode;
   bool                                 DisplayPipeCVerticalBlankWaitEnable;
   bool                                 DisplaySpriteCFlipPendingWaitEnable;
   bool                                 DisplayPlaneCFlipPendingWaitEnable;
   bool                                 DisplayPipeCScanLineWaitEnable;
   bool                                 DisplayPipeBVerticalBlankWaitEnable;
   bool                                 DisplaySpriteBFlipPendingWaitEnable;
   bool                                 DisplayPlaneBFlipPendingWaitEnable;
   bool                                 DisplayPipeBScanLineWaitEnable;
   bool                                 DisplayPipeAVerticalBlankWaitEnable;
   bool                                 DisplaySpriteAFlipPendingWaitEnable;
   bool                                 DisplayPlaneAFlipPendingWaitEnable;
   bool                                 DisplayPipeAScanLineWaitEnable;
};

static inline void
GEN8_MI_WAIT_FOR_EVENT_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_MI_WAIT_FOR_EVENT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->MICommandOpcode, 23, 28) |
      __gen_uint(values->DisplayPipeCVerticalBlankWaitEnable, 21, 21) |
      __gen_uint(values->DisplaySpriteCFlipPendingWaitEnable, 20, 20) |
      __gen_uint(values->DisplayPlaneCFlipPendingWaitEnable, 15, 15) |
      __gen_uint(values->DisplayPipeCScanLineWaitEnable, 14, 14) |
      __gen_uint(values->DisplayPipeBVerticalBlankWaitEnable, 11, 11) |
      __gen_uint(values->DisplaySpriteBFlipPendingWaitEnable, 10, 10) |
      __gen_uint(values->DisplayPlaneBFlipPendingWaitEnable, 9, 9) |
      __gen_uint(values->DisplayPipeBScanLineWaitEnable, 8, 8) |
      __gen_uint(values->DisplayPipeAVerticalBlankWaitEnable, 3, 3) |
      __gen_uint(values->DisplaySpriteAFlipPendingWaitEnable, 2, 2) |
      __gen_uint(values->DisplayPlaneAFlipPendingWaitEnable, 1, 1) |
      __gen_uint(values->DisplayPipeAScanLineWaitEnable, 0, 0);
}

#define GEN8_PIPELINE_SELECT_length            1
#define GEN8_PIPELINE_SELECT_length_bias       1
#define GEN8_PIPELINE_SELECT_header             \
   .CommandType                         =      3,  \
   .CommandSubType                      =      1,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      4

struct GEN8_PIPELINE_SELECT {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             PipelineSelection;
#define _3D                                      0
#define Media                                    1
#define GPGPU                                    2
};

static inline void
GEN8_PIPELINE_SELECT_pack(__gen_user_data *data, void * restrict dst,
                          const struct GEN8_PIPELINE_SELECT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->PipelineSelection, 0, 1);
}

#define GEN8_PIPE_CONTROL_length               6
#define GEN8_PIPE_CONTROL_length_bias          2
#define GEN8_PIPE_CONTROL_header                \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      2,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      4

struct GEN8_PIPE_CONTROL {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             DestinationAddressType;
#define DAT_PPGTT                                0
#define DAT_GGTT                                 1
   uint32_t                             LRIPostSyncOperation;
#define NoLRIOperation                           0
#define MMIOWriteImmediateData                   1
   uint32_t                             StoreDataIndex;
   bool                                 CommandStreamerStallEnable;
   bool                                 GlobalSnapshotCountReset;
   bool                                 TLBInvalidate;
   bool                                 GenericMediaStateClear;
   uint32_t                             PostSyncOperation;
#define NoWrite                                  0
#define WriteImmediateData                       1
#define WritePSDepthCount                        2
#define WriteTimestamp                           3
   bool                                 DepthStallEnable;
   bool                                 RenderTargetCacheFlushEnable;
   bool                                 InstructionCacheInvalidateEnable;
   bool                                 TextureCacheInvalidationEnable;
   bool                                 IndirectStatePointersDisable;
   bool                                 NotifyEnable;
   bool                                 PipeControlFlushEnable;
   bool                                 DCFlushEnable;
   bool                                 VFCacheInvalidationEnable;
   bool                                 ConstantCacheInvalidationEnable;
   bool                                 StateCacheInvalidationEnable;
   bool                                 StallAtPixelScoreboard;
   bool                                 DepthCacheFlushEnable;
   __gen_address_type                   Address;
   uint64_t                             ImmediateData;
};

static inline void
GEN8_PIPE_CONTROL_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_PIPE_CONTROL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->DestinationAddressType, 24, 24) |
      __gen_uint(values->LRIPostSyncOperation, 23, 23) |
      __gen_uint(values->StoreDataIndex, 21, 21) |
      __gen_uint(values->CommandStreamerStallEnable, 20, 20) |
      __gen_uint(values->GlobalSnapshotCountReset, 19, 19) |
      __gen_uint(values->TLBInvalidate, 18, 18) |
      __gen_uint(values->GenericMediaStateClear, 16, 16) |
      __gen_uint(values->PostSyncOperation, 14, 15) |
      __gen_uint(values->DepthStallEnable, 13, 13) |
      __gen_uint(values->RenderTargetCacheFlushEnable, 12, 12) |
      __gen_uint(values->InstructionCacheInvalidateEnable, 11, 11) |
      __gen_uint(values->TextureCacheInvalidationEnable, 10, 10) |
      __gen_uint(values->IndirectStatePointersDisable, 9, 9) |
      __gen_uint(values->NotifyEnable, 8, 8) |
      __gen_uint(values->PipeControlFlushEnable, 7, 7) |
      __gen_uint(values->DCFlushEnable, 5, 5) |
      __gen_uint(values->VFCacheInvalidationEnable, 4, 4) |
      __gen_uint(values->ConstantCacheInvalidationEnable, 3, 3) |
      __gen_uint(values->StateCacheInvalidationEnable, 2, 2) |
      __gen_uint(values->StallAtPixelScoreboard, 1, 1) |
      __gen_uint(values->DepthCacheFlushEnable, 0, 0);

   const uint64_t v2_address =
      __gen_combine_address(data, &dw[2], values->Address, 0);
   dw[2] = v2_address;
   dw[3] = v2_address >> 32;

   const uint64_t v4 =
      __gen_uint(values->ImmediateData, 0, 63);
   dw[4] = v4;
   dw[5] = v4 >> 32;
}

#define GEN8_STATE_BASE_ADDRESS_length        16
#define GEN8_STATE_BASE_ADDRESS_length_bias      2
#define GEN8_STATE_BASE_ADDRESS_header          \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      1,  \
   .DWordLength                         =     14

struct GEN8_STATE_BASE_ADDRESS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   GeneralStateBaseAddress;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE GeneralStateMemoryObjectControlState;
   bool                                 GeneralStateBaseAddressModifyEnable;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE StatelessDataPortAccessMemoryObjectControlState;
   __gen_address_type                   SurfaceStateBaseAddress;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE SurfaceStateMemoryObjectControlState;
   bool                                 SurfaceStateBaseAddressModifyEnable;
   __gen_address_type                   DynamicStateBaseAddress;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE DynamicStateMemoryObjectControlState;
   bool                                 DynamicStateBaseAddressModifyEnable;
   __gen_address_type                   IndirectObjectBaseAddress;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE IndirectObjectMemoryObjectControlState;
   bool                                 IndirectObjectBaseAddressModifyEnable;
   __gen_address_type                   InstructionBaseAddress;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE InstructionMemoryObjectControlState;
   bool                                 InstructionBaseAddressModifyEnable;
   uint32_t                             GeneralStateBufferSize;
   bool                                 GeneralStateBufferSizeModifyEnable;
   uint32_t                             DynamicStateBufferSize;
   bool                                 DynamicStateBufferSizeModifyEnable;
   uint32_t                             IndirectObjectBufferSize;
   bool                                 IndirectObjectBufferSizeModifyEnable;
   uint32_t                             InstructionBufferSize;
   bool                                 InstructionBuffersizeModifyEnable;
};

static inline void
GEN8_STATE_BASE_ADDRESS_pack(__gen_user_data *data, void * restrict dst,
                             const struct GEN8_STATE_BASE_ADDRESS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->GeneralStateMemoryObjectControlState);

   const uint64_t v1 =
      __gen_uint(v1_0, 4, 10) |
      __gen_uint(values->GeneralStateBaseAddressModifyEnable, 0, 0);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->GeneralStateBaseAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;

   uint32_t v3_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v3_0, &values->StatelessDataPortAccessMemoryObjectControlState);

   dw[3] =
      __gen_uint(v3_0, 16, 22);

   uint32_t v4_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v4_0, &values->SurfaceStateMemoryObjectControlState);

   const uint64_t v4 =
      __gen_uint(v4_0, 4, 10) |
      __gen_uint(values->SurfaceStateBaseAddressModifyEnable, 0, 0);
   const uint64_t v4_address =
      __gen_combine_address(data, &dw[4], values->SurfaceStateBaseAddress, v4);
   dw[4] = v4_address;
   dw[5] = v4_address >> 32;

   uint32_t v6_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v6_0, &values->DynamicStateMemoryObjectControlState);

   const uint64_t v6 =
      __gen_uint(v6_0, 4, 10) |
      __gen_uint(values->DynamicStateBaseAddressModifyEnable, 0, 0);
   const uint64_t v6_address =
      __gen_combine_address(data, &dw[6], values->DynamicStateBaseAddress, v6);
   dw[6] = v6_address;
   dw[7] = v6_address >> 32;

   uint32_t v8_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v8_0, &values->IndirectObjectMemoryObjectControlState);

   const uint64_t v8 =
      __gen_uint(v8_0, 4, 10) |
      __gen_uint(values->IndirectObjectBaseAddressModifyEnable, 0, 0);
   const uint64_t v8_address =
      __gen_combine_address(data, &dw[8], values->IndirectObjectBaseAddress, v8);
   dw[8] = v8_address;
   dw[9] = v8_address >> 32;

   uint32_t v10_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v10_0, &values->InstructionMemoryObjectControlState);

   const uint64_t v10 =
      __gen_uint(v10_0, 4, 10) |
      __gen_uint(values->InstructionBaseAddressModifyEnable, 0, 0);
   const uint64_t v10_address =
      __gen_combine_address(data, &dw[10], values->InstructionBaseAddress, v10);
   dw[10] = v10_address;
   dw[11] = v10_address >> 32;

   dw[12] =
      __gen_uint(values->GeneralStateBufferSize, 12, 31) |
      __gen_uint(values->GeneralStateBufferSizeModifyEnable, 0, 0);

   dw[13] =
      __gen_uint(values->DynamicStateBufferSize, 12, 31) |
      __gen_uint(values->DynamicStateBufferSizeModifyEnable, 0, 0);

   dw[14] =
      __gen_uint(values->IndirectObjectBufferSize, 12, 31) |
      __gen_uint(values->IndirectObjectBufferSizeModifyEnable, 0, 0);

   dw[15] =
      __gen_uint(values->InstructionBufferSize, 12, 31) |
      __gen_uint(values->InstructionBuffersizeModifyEnable, 0, 0);
}

#define GEN8_STATE_PREFETCH_length             2
#define GEN8_STATE_PREFETCH_length_bias        2
#define GEN8_STATE_PREFETCH_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      3,  \
   .DWordLength                         =      0

struct GEN8_STATE_PREFETCH {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   PrefetchPointer;
   uint32_t                             PrefetchCount;
};

static inline void
GEN8_STATE_PREFETCH_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_STATE_PREFETCH * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint32_t v1 =
      __gen_uint(values->PrefetchCount, 0, 2);
   dw[1] = __gen_combine_address(data, &dw[1], values->PrefetchPointer, v1);
}

#define GEN8_STATE_SIP_length                  3
#define GEN8_STATE_SIP_length_bias             2
#define GEN8_STATE_SIP_header                   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      2,  \
   .DWordLength                         =      1

struct GEN8_STATE_SIP {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             SystemInstructionPointer;
};

static inline void
GEN8_STATE_SIP_pack(__gen_user_data *data, void * restrict dst,
                    const struct GEN8_STATE_SIP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint64_t v1 =
      __gen_offset(values->SystemInstructionPointer, 4, 63);
   dw[1] = v1;
   dw[2] = v1 >> 32;
}

#define GEN8_SWTESS_BASE_ADDRESS_length        2
#define GEN8_SWTESS_BASE_ADDRESS_length_bias      2
#define GEN8_SWTESS_BASE_ADDRESS_header         \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      3,  \
   .DWordLength                         =      0

struct GEN8_SWTESS_BASE_ADDRESS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   SWTessellationBaseAddress;
   struct GEN8_MEMORY_OBJECT_CONTROL_STATE SWTessellationMemoryObjectControlState;
};

static inline void
GEN8_SWTESS_BASE_ADDRESS_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_SWTESS_BASE_ADDRESS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   uint32_t v1_0;
   GEN8_MEMORY_OBJECT_CONTROL_STATE_pack(data, &v1_0, &values->SWTessellationMemoryObjectControlState);

   const uint64_t v1 =
      __gen_uint(v1_0, 8, 11);
   const uint64_t v1_address =
      __gen_combine_address(data, &dw[1], values->SWTessellationBaseAddress, v1);
   dw[1] = v1_address;
   dw[2] = v1_address >> 32;
}

#define GEN8_IA_VERTICES_COUNT_num        0x2310
#define GEN8_IA_VERTICES_COUNT_length          2
struct GEN8_IA_VERTICES_COUNT {
   uint64_t                             IAVerticesCountReport;
};

static inline void
GEN8_IA_VERTICES_COUNT_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_IA_VERTICES_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->IAVerticesCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_IA_PRIMITIVES_COUNT_num      0x2318
#define GEN8_IA_PRIMITIVES_COUNT_length        2
struct GEN8_IA_PRIMITIVES_COUNT {
   uint64_t                             IAPrimitivesCountReport;
};

static inline void
GEN8_IA_PRIMITIVES_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_IA_PRIMITIVES_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->IAPrimitivesCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_VS_INVOCATION_COUNT_num      0x2320
#define GEN8_VS_INVOCATION_COUNT_length        2
struct GEN8_VS_INVOCATION_COUNT {
   uint64_t                             VSInvocationCountReport;
};

static inline void
GEN8_VS_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_VS_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->VSInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_HS_INVOCATION_COUNT_num      0x2300
#define GEN8_HS_INVOCATION_COUNT_length        2
struct GEN8_HS_INVOCATION_COUNT {
   uint64_t                             HSInvocationCountReport;
};

static inline void
GEN8_HS_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_HS_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->HSInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_DS_INVOCATION_COUNT_num      0x2308
#define GEN8_DS_INVOCATION_COUNT_length        2
struct GEN8_DS_INVOCATION_COUNT {
   uint64_t                             DSInvocationCountReport;
};

static inline void
GEN8_DS_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_DS_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->DSInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_GS_INVOCATION_COUNT_num      0x2328
#define GEN8_GS_INVOCATION_COUNT_length        2
struct GEN8_GS_INVOCATION_COUNT {
   uint64_t                             GSInvocationCountReport;
};

static inline void
GEN8_GS_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_GS_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->GSInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_GS_PRIMITIVES_COUNT_num      0x2330
#define GEN8_GS_PRIMITIVES_COUNT_length        2
struct GEN8_GS_PRIMITIVES_COUNT {
   uint64_t                             GSPrimitivesCountReport;
};

static inline void
GEN8_GS_PRIMITIVES_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_GS_PRIMITIVES_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->GSPrimitivesCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_CL_INVOCATION_COUNT_num      0x2338
#define GEN8_CL_INVOCATION_COUNT_length        2
struct GEN8_CL_INVOCATION_COUNT {
   uint64_t                             CLInvocationCountReport;
};

static inline void
GEN8_CL_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_CL_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->CLInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_CL_PRIMITIVES_COUNT_num      0x2340
#define GEN8_CL_PRIMITIVES_COUNT_length        2
struct GEN8_CL_PRIMITIVES_COUNT {
   uint64_t                             CLPrimitivesCountReport;
};

static inline void
GEN8_CL_PRIMITIVES_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_CL_PRIMITIVES_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->CLPrimitivesCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_PS_INVOCATION_COUNT_num      0x2348
#define GEN8_PS_INVOCATION_COUNT_length        2
struct GEN8_PS_INVOCATION_COUNT {
   uint64_t                             PSInvocationCountReport;
};

static inline void
GEN8_PS_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_PS_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->PSInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_CS_INVOCATION_COUNT_num      0x2290
#define GEN8_CS_INVOCATION_COUNT_length        2
struct GEN8_CS_INVOCATION_COUNT {
   uint64_t                             CSInvocationCountReport;
};

static inline void
GEN8_CS_INVOCATION_COUNT_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_CS_INVOCATION_COUNT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint64_t v0 =
      __gen_uint(values->CSInvocationCountReport, 0, 63);
   dw[0] = v0;
   dw[1] = v0 >> 32;
}

#define GEN8_BCS_INSTDONE_num             0x2206c
#define GEN8_BCS_INSTDONE_length               1
struct GEN8_BCS_INSTDONE {
   bool                                 RingEnable;
   bool                                 BlitterIDLE;
   bool                                 GABIDLE;
   bool                                 BCSDone;
};

static inline void
GEN8_BCS_INSTDONE_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_BCS_INSTDONE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingEnable, 0, 0) |
      __gen_uint(values->BlitterIDLE, 1, 1) |
      __gen_uint(values->GABIDLE, 2, 2) |
      __gen_uint(values->BCSDone, 3, 3);
}

#define GEN8_INSTDONE_1_num               0x206c
#define GEN8_INSTDONE_1_length                 1
struct GEN8_INSTDONE_1 {
   bool                                 PRB0RingEnable;
   bool                                 VFGDone;
   bool                                 VSDone;
   bool                                 HSDone;
   bool                                 TEDone;
   bool                                 DSDone;
   bool                                 GSDone;
   bool                                 SOLDone;
   bool                                 CLDone;
   bool                                 SFDone;
   bool                                 TDGDone;
   bool                                 URBMDone;
   bool                                 SVGDone;
   bool                                 GAFSDone;
   bool                                 VFEDone;
   bool                                 TSGDone;
   bool                                 GAFMDone;
   bool                                 GAMDone;
   bool                                 SDEDone;
   bool                                 RCCFBCCSDone;
};

static inline void
GEN8_INSTDONE_1_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN8_INSTDONE_1 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->PRB0RingEnable, 0, 0) |
      __gen_uint(values->VFGDone, 1, 1) |
      __gen_uint(values->VSDone, 2, 2) |
      __gen_uint(values->HSDone, 3, 3) |
      __gen_uint(values->TEDone, 4, 4) |
      __gen_uint(values->DSDone, 5, 5) |
      __gen_uint(values->GSDone, 6, 6) |
      __gen_uint(values->SOLDone, 7, 7) |
      __gen_uint(values->CLDone, 8, 8) |
      __gen_uint(values->SFDone, 9, 9) |
      __gen_uint(values->TDGDone, 12, 12) |
      __gen_uint(values->URBMDone, 13, 13) |
      __gen_uint(values->SVGDone, 14, 14) |
      __gen_uint(values->GAFSDone, 15, 15) |
      __gen_uint(values->VFEDone, 16, 16) |
      __gen_uint(values->TSGDone, 17, 17) |
      __gen_uint(values->GAFMDone, 18, 18) |
      __gen_uint(values->GAMDone, 19, 19) |
      __gen_uint(values->SDEDone, 22, 22) |
      __gen_uint(values->RCCFBCCSDone, 23, 23);
}

#define GEN8_VCS_INSTDONE_num             0x1206c
#define GEN8_VCS_INSTDONE_length               1
struct GEN8_VCS_INSTDONE {
   bool                                 RingEnable;
   bool                                 USBDone;
   bool                                 QRCDone;
   bool                                 SECDone;
   bool                                 MPCDone;
   bool                                 VFTDone;
   bool                                 BSPDone;
   bool                                 VLFDone;
   bool                                 VOPDone;
   bool                                 VMCDone;
   bool                                 VIPDone;
   bool                                 VITDone;
   bool                                 VDSDone;
   bool                                 VMXDone;
   bool                                 VCPDone;
   bool                                 VCDDone;
   bool                                 VADDone;
   bool                                 VMDDone;
   bool                                 VISDone;
   bool                                 VACDone;
   bool                                 VAMDone;
   bool                                 JPGDone;
   bool                                 VBPDone;
   bool                                 VHRDone;
   bool                                 VCIDone;
   bool                                 VCRDone;
   bool                                 VINDone;
   bool                                 VPRDone;
   bool                                 VTQDone;
   bool                                 Reserved;
   bool                                 VCSDone;
   bool                                 GACDone;
};

static inline void
GEN8_VCS_INSTDONE_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_VCS_INSTDONE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingEnable, 0, 0) |
      __gen_uint(values->USBDone, 1, 1) |
      __gen_uint(values->QRCDone, 2, 2) |
      __gen_uint(values->SECDone, 3, 3) |
      __gen_uint(values->MPCDone, 4, 4) |
      __gen_uint(values->VFTDone, 5, 5) |
      __gen_uint(values->BSPDone, 6, 6) |
      __gen_uint(values->VLFDone, 7, 7) |
      __gen_uint(values->VOPDone, 8, 8) |
      __gen_uint(values->VMCDone, 9, 9) |
      __gen_uint(values->VIPDone, 10, 10) |
      __gen_uint(values->VITDone, 11, 11) |
      __gen_uint(values->VDSDone, 12, 12) |
      __gen_uint(values->VMXDone, 13, 13) |
      __gen_uint(values->VCPDone, 14, 14) |
      __gen_uint(values->VCDDone, 15, 15) |
      __gen_uint(values->VADDone, 16, 16) |
      __gen_uint(values->VMDDone, 17, 17) |
      __gen_uint(values->VISDone, 18, 18) |
      __gen_uint(values->VACDone, 19, 19) |
      __gen_uint(values->VAMDone, 20, 20) |
      __gen_uint(values->JPGDone, 21, 21) |
      __gen_uint(values->VBPDone, 22, 22) |
      __gen_uint(values->VHRDone, 23, 23) |
      __gen_uint(values->VCIDone, 24, 24) |
      __gen_uint(values->VCRDone, 25, 25) |
      __gen_uint(values->VINDone, 26, 26) |
      __gen_uint(values->VPRDone, 27, 27) |
      __gen_uint(values->VTQDone, 28, 28) |
      __gen_uint(values->Reserved, 29, 29) |
      __gen_uint(values->VCSDone, 30, 30) |
      __gen_uint(values->GACDone, 31, 31);
}

#define GEN8_VECS_INSTDONE_num            0x1a06c
#define GEN8_VECS_INSTDONE_length              1
struct GEN8_VECS_INSTDONE {
   bool                                 RingEnable;
   bool                                 VECSDone;
   bool                                 GAMDone;
};

static inline void
GEN8_VECS_INSTDONE_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_VECS_INSTDONE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingEnable, 0, 0) |
      __gen_uint(values->VECSDone, 30, 30) |
      __gen_uint(values->GAMDone, 31, 31);
}

#define GEN8_L3CNTLREG_num                0x7034
#define GEN8_L3CNTLREG_length                  1
struct GEN8_L3CNTLREG {
   uint32_t                             SLMEnable;
   uint32_t                             URBAllocation;
   uint32_t                             ROAllocation;
   uint32_t                             DCAllocation;
   uint32_t                             AllAllocation;
};

static inline void
GEN8_L3CNTLREG_pack(__gen_user_data *data, void * restrict dst,
                    const struct GEN8_L3CNTLREG * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->SLMEnable, 0, 0) |
      __gen_uint(values->URBAllocation, 1, 7) |
      __gen_uint(values->ROAllocation, 11, 17) |
      __gen_uint(values->DCAllocation, 18, 24) |
      __gen_uint(values->AllAllocation, 25, 31);
}

#define GEN8_SO_WRITE_OFFSET0_num         0x5280
#define GEN8_SO_WRITE_OFFSET0_length           1
struct GEN8_SO_WRITE_OFFSET0 {
   uint64_t                             WriteOffset;
};

static inline void
GEN8_SO_WRITE_OFFSET0_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_SO_WRITE_OFFSET0 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_offset(values->WriteOffset, 2, 31);
}

#define GEN8_SO_WRITE_OFFSET1_num         0x5284
#define GEN8_SO_WRITE_OFFSET1_length           1
struct GEN8_SO_WRITE_OFFSET1 {
   uint64_t                             WriteOffset;
};

static inline void
GEN8_SO_WRITE_OFFSET1_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_SO_WRITE_OFFSET1 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_offset(values->WriteOffset, 2, 31);
}

#define GEN8_SO_WRITE_OFFSET2_num         0x5288
#define GEN8_SO_WRITE_OFFSET2_length           1
struct GEN8_SO_WRITE_OFFSET2 {
   uint64_t                             WriteOffset;
};

static inline void
GEN8_SO_WRITE_OFFSET2_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_SO_WRITE_OFFSET2 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_offset(values->WriteOffset, 2, 31);
}

#define GEN8_SO_WRITE_OFFSET3_num         0x528c
#define GEN8_SO_WRITE_OFFSET3_length           1
struct GEN8_SO_WRITE_OFFSET3 {
   uint64_t                             WriteOffset;
};

static inline void
GEN8_SO_WRITE_OFFSET3_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN8_SO_WRITE_OFFSET3 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_offset(values->WriteOffset, 2, 31);
}

#define GEN8_CACHE_MODE_1_num             0x7004
#define GEN8_CACHE_MODE_1_length               1
struct GEN8_CACHE_MODE_1 {
   bool                                 RCZReadafterexpansioncontrolfix2;
   bool                                 DepthReadHitWriteOnlyOptimizationDisable;
   bool                                 MCSCacheDisable;
   bool                                 _4X4RCPFESTCOptimizationDisable;
   uint32_t                             SamplerCacheSetXORselection;
   uint32_t                             NPPMAFixEnable;
   uint32_t                             HIZEvictionPolicy;
   uint32_t                             NPEarlyZFailsDisable;
   uint32_t                             MSCResolveOptimizationDisable;
   bool                                 RCZReadafterexpansioncontrolfix2Mask;
   bool                                 DepthReadHitWriteOnlyOptimizationDisableMask;
   bool                                 MCSCacheDisableMask;
   bool                                 _4X4RCPFESTCOptimizationDisableMask;
   uint32_t                             SamplerCacheSetXORselectionMask;
   uint32_t                             NPPMAFixEnableMask;
   uint32_t                             HIZEvictionPolicyMask;
   uint32_t                             NPEarlyZFailsDisableMask;
   uint32_t                             MSCResolveOptimizationDisableMask;
};

static inline void
GEN8_CACHE_MODE_1_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN8_CACHE_MODE_1 * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RCZReadafterexpansioncontrolfix2, 2, 2) |
      __gen_uint(values->DepthReadHitWriteOnlyOptimizationDisable, 3, 3) |
      __gen_uint(values->MCSCacheDisable, 5, 5) |
      __gen_uint(values->_4X4RCPFESTCOptimizationDisable, 6, 6) |
      __gen_uint(values->SamplerCacheSetXORselection, 7, 8) |
      __gen_uint(values->NPPMAFixEnable, 11, 11) |
      __gen_uint(values->HIZEvictionPolicy, 12, 12) |
      __gen_uint(values->NPEarlyZFailsDisable, 13, 13) |
      __gen_uint(values->MSCResolveOptimizationDisable, 14, 14) |
      __gen_uint(values->RCZReadafterexpansioncontrolfix2Mask, 18, 18) |
      __gen_uint(values->DepthReadHitWriteOnlyOptimizationDisableMask, 19, 19) |
      __gen_uint(values->MCSCacheDisableMask, 21, 21) |
      __gen_uint(values->_4X4RCPFESTCOptimizationDisableMask, 22, 22) |
      __gen_uint(values->SamplerCacheSetXORselectionMask, 23, 24) |
      __gen_uint(values->NPPMAFixEnableMask, 27, 27) |
      __gen_uint(values->HIZEvictionPolicyMask, 28, 28) |
      __gen_uint(values->NPEarlyZFailsDisableMask, 29, 29) |
      __gen_uint(values->MSCResolveOptimizationDisableMask, 30, 30);
}

#define GEN8_GFX_ARB_ERROR_RPT_num        0x40a0
#define GEN8_GFX_ARB_ERROR_RPT_length          1
struct GEN8_GFX_ARB_ERROR_RPT {
   bool                                 TLBPageFaultError;
   bool                                 RSTRMPAVPReadInvalid;
   bool                                 InvalidPageDirectoryEntryError;
   bool                                 ROSTRMPAVPInvalidPhysicalAddress;
   bool                                 TLBPageVTDTranslationError;
   bool                                 WRDPPAVPInvalid;
   bool                                 PageDirectoryEntryVTDTranslationError;
   bool                                 UnloadedPDError;
   bool                                 GuCVTdtranslationPageFault2ndlevelUndefineddoorbell;
   bool                                 NonWBmemorytypeforAdvancedContext;
   bool                                 PASIDNotEnabled;
   bool                                 PASIDBoundaryViolation;
   bool                                 PASIDNotValid;
   bool                                 PASIDWasZeroForUntranslatedRequest;
   bool                                 ContextWasNotMarkedAsPresentWhenDoingDMA;
};

static inline void
GEN8_GFX_ARB_ERROR_RPT_pack(__gen_user_data *data, void * restrict dst,
                            const struct GEN8_GFX_ARB_ERROR_RPT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->TLBPageFaultError, 0, 0) |
      __gen_uint(values->RSTRMPAVPReadInvalid, 1, 1) |
      __gen_uint(values->InvalidPageDirectoryEntryError, 2, 2) |
      __gen_uint(values->ROSTRMPAVPInvalidPhysicalAddress, 3, 3) |
      __gen_uint(values->TLBPageVTDTranslationError, 4, 4) |
      __gen_uint(values->WRDPPAVPInvalid, 5, 5) |
      __gen_uint(values->PageDirectoryEntryVTDTranslationError, 6, 6) |
      __gen_uint(values->UnloadedPDError, 8, 8) |
      __gen_uint(values->GuCVTdtranslationPageFault2ndlevelUndefineddoorbell, 9, 9) |
      __gen_uint(values->NonWBmemorytypeforAdvancedContext, 10, 10) |
      __gen_uint(values->PASIDNotEnabled, 11, 11) |
      __gen_uint(values->PASIDBoundaryViolation, 12, 12) |
      __gen_uint(values->PASIDNotValid, 13, 13) |
      __gen_uint(values->PASIDWasZeroForUntranslatedRequest, 14, 14) |
      __gen_uint(values->ContextWasNotMarkedAsPresentWhenDoingDMA, 15, 15);
}

#define GEN8_ACTHD_UDW_num                0x205c
#define GEN8_ACTHD_UDW_length                  1
struct GEN8_ACTHD_UDW {
   uint32_t                             HeadPointerUpperDWORD;
};

static inline void
GEN8_ACTHD_UDW_pack(__gen_user_data *data, void * restrict dst,
                    const struct GEN8_ACTHD_UDW * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->HeadPointerUpperDWORD, 0, 15);
}

#define GEN8_BCS_ACTHD_UDW_num            0x2205c
#define GEN8_BCS_ACTHD_UDW_length              1
struct GEN8_BCS_ACTHD_UDW {
   uint32_t                             HeadPointerUpperDWORD;
};

static inline void
GEN8_BCS_ACTHD_UDW_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_BCS_ACTHD_UDW * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->HeadPointerUpperDWORD, 0, 15);
}

#define GEN8_VCS_ACTHD_UDW_num            0x1205c
#define GEN8_VCS_ACTHD_UDW_length              1
struct GEN8_VCS_ACTHD_UDW {
   uint32_t                             HeadPointerUpperDWORD;
};

static inline void
GEN8_VCS_ACTHD_UDW_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN8_VCS_ACTHD_UDW * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->HeadPointerUpperDWORD, 0, 15);
}

#define GEN8_VECS_ACTHD_UDW_num           0x1a05c
#define GEN8_VECS_ACTHD_UDW_length             1
struct GEN8_VECS_ACTHD_UDW {
   uint32_t                             HeadPointerUpperDWORD;
};

static inline void
GEN8_VECS_ACTHD_UDW_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN8_VECS_ACTHD_UDW * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->HeadPointerUpperDWORD, 0, 15);
}

#define GEN8_FAULT_REG_num                0x4094
#define GEN8_FAULT_REG_length                  1
struct GEN8_FAULT_REG {
   bool                                 ValidBit;
   uint32_t                             FaultType;
#define InvalidPTEFault                          0
#define InvalidPDEFault                          1
#define InvalidPDPEFault                         2
#define InvalidPML4EFault                        3
   uint32_t                             SRCIDofFault;
   uint32_t                             GTTSEL;
#define PPGTT                                    0
#define GGTT                                     1
   uint32_t                             EngineID;
#define GFX                                      0
#define MFX0                                     1
#define MFX1                                     2
#define VEBX                                     3
#define BLT                                      4
#define GUC                                      5
};

static inline void
GEN8_FAULT_REG_pack(__gen_user_data *data, void * restrict dst,
                    const struct GEN8_FAULT_REG * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->ValidBit, 0, 0) |
      __gen_uint(values->FaultType, 1, 2) |
      __gen_uint(values->SRCIDofFault, 3, 10) |
      __gen_uint(values->GTTSEL, 11, 11) |
      __gen_uint(values->EngineID, 12, 14);
}

#define GEN8_BCS_RING_BUFFER_CTL_num      0x2203c
#define GEN8_BCS_RING_BUFFER_CTL_length        1
struct GEN8_BCS_RING_BUFFER_CTL {
   bool                                 RingBufferEnable;
   uint32_t                             AutomaticReportHeadPointer;
#define MI_AUTOREPORT_OFF                        0
#define MI_AUTOREPORT_64KB                       1
#define MI_AUTOREPORT_4KB                        2
#define MI_AUTOREPORT_128KB                      3
   bool                                 DisableRegisterAccesses;
   bool                                 SemaphoreWait;
   bool                                 RBWait;
   uint32_t                             BufferLengthinpages1;
};

static inline void
GEN8_BCS_RING_BUFFER_CTL_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_BCS_RING_BUFFER_CTL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingBufferEnable, 0, 0) |
      __gen_uint(values->AutomaticReportHeadPointer, 1, 2) |
      __gen_uint(values->DisableRegisterAccesses, 8, 8) |
      __gen_uint(values->SemaphoreWait, 10, 10) |
      __gen_uint(values->RBWait, 11, 11) |
      __gen_uint(values->BufferLengthinpages1, 12, 20);
}

#define GEN8_RCS_RING_BUFFER_CTL_num      0x203c
#define GEN8_RCS_RING_BUFFER_CTL_length        1
struct GEN8_RCS_RING_BUFFER_CTL {
   bool                                 RingBufferEnable;
   uint32_t                             AutomaticReportHeadPointer;
#define MI_AUTOREPORT_OFF                        0
#define MI_AUTOREPORT_64KB                       1
#define MI_AUTOREPORT_4KB                        2
#define MI_AUTOREPORT_128KB                      3
   bool                                 SemaphoreWait;
   bool                                 RBWait;
   uint32_t                             BufferLengthinpages1;
};

static inline void
GEN8_RCS_RING_BUFFER_CTL_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_RCS_RING_BUFFER_CTL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingBufferEnable, 0, 0) |
      __gen_uint(values->AutomaticReportHeadPointer, 1, 2) |
      __gen_uint(values->SemaphoreWait, 10, 10) |
      __gen_uint(values->RBWait, 11, 11) |
      __gen_uint(values->BufferLengthinpages1, 12, 20);
}

#define GEN8_VECS_RING_BUFFER_CTL_num     0x1a03c
#define GEN8_VECS_RING_BUFFER_CTL_length       1
struct GEN8_VECS_RING_BUFFER_CTL {
   bool                                 RingBufferEnable;
   uint32_t                             AutomaticReportHeadPointer;
#define MI_AUTOREPORT_OFF                        0
#define MI_AUTOREPORT_64KB                       1
#define MI_AUTOREPORT_4KB                        2
#define MI_AUTOREPORT_128KB                      3
   bool                                 DisableRegisterAccesses;
   bool                                 SemaphoreWait;
   bool                                 RBWait;
   uint32_t                             BufferLengthinpages1;
};

static inline void
GEN8_VECS_RING_BUFFER_CTL_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_VECS_RING_BUFFER_CTL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingBufferEnable, 0, 0) |
      __gen_uint(values->AutomaticReportHeadPointer, 1, 2) |
      __gen_uint(values->DisableRegisterAccesses, 8, 8) |
      __gen_uint(values->SemaphoreWait, 10, 10) |
      __gen_uint(values->RBWait, 11, 11) |
      __gen_uint(values->BufferLengthinpages1, 12, 20);
}

#define GEN8_VCS_RING_BUFFER_CTL_num      0x1203c
#define GEN8_VCS_RING_BUFFER_CTL_length        1
struct GEN8_VCS_RING_BUFFER_CTL {
   bool                                 RingBufferEnable;
   uint32_t                             AutomaticReportHeadPointer;
#define MI_AUTOREPORT_OFF                        0
#define MI_AUTOREPORT_64KB                       1
#define MI_AUTOREPORT_4KB                        2
#define MI_AUTOREPORT_128KB                      3
   bool                                 DisableRegisterAccesses;
   bool                                 SemaphoreWait;
   bool                                 RBWait;
   uint32_t                             BufferLengthinpages1;
};

static inline void
GEN8_VCS_RING_BUFFER_CTL_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN8_VCS_RING_BUFFER_CTL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingBufferEnable, 0, 0) |
      __gen_uint(values->AutomaticReportHeadPointer, 1, 2) |
      __gen_uint(values->DisableRegisterAccesses, 8, 8) |
      __gen_uint(values->SemaphoreWait, 10, 10) |
      __gen_uint(values->RBWait, 11, 11) |
      __gen_uint(values->BufferLengthinpages1, 12, 20);
}

#define GEN8_VCS2_RING_BUFFER_CTL_num     0x1203c
#define GEN8_VCS2_RING_BUFFER_CTL_length       1
struct GEN8_VCS2_RING_BUFFER_CTL {
   bool                                 RingBufferEnable;
   uint32_t                             AutomaticReportHeadPointer;
#define MI_AUTOREPORT_OFF                        0
#define MI_AUTOREPORT_64KB                       1
#define MI_AUTOREPORT_4KB                        2
#define MI_AUTOREPORT_128KB                      3
   bool                                 DisableRegisterAccesses;
   bool                                 SemaphoreWait;
   bool                                 RBWait;
   uint32_t                             BufferLengthinpages1;
};

static inline void
GEN8_VCS2_RING_BUFFER_CTL_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN8_VCS2_RING_BUFFER_CTL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->RingBufferEnable, 0, 0) |
      __gen_uint(values->AutomaticReportHeadPointer, 1, 2) |
      __gen_uint(values->DisableRegisterAccesses, 8, 8) |
      __gen_uint(values->SemaphoreWait, 10, 10) |
      __gen_uint(values->RBWait, 11, 11) |
      __gen_uint(values->BufferLengthinpages1, 12, 20);
}

#endif /* GEN8_PACK_H */

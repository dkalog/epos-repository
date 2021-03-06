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


/* Instructions, enums and structures for BRW.
 *
 * This file has been generated, do not hand edit.
 */

#ifndef GEN4_PACK_H
#define GEN4_PACK_H

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


enum GEN4_3D_Prim_Topo_Type {
   _3DPRIM_POINTLIST                    =      1,
   _3DPRIM_LINELIST                     =      2,
   _3DPRIM_LINESTRIP                    =      3,
   _3DPRIM_TRILIST                      =      4,
   _3DPRIM_TRISTRIP                     =      5,
   _3DPRIM_TRIFAN                       =      6,
   _3DPRIM_QUADLIST                     =      7,
   _3DPRIM_QUADSTRIP                    =      8,
   _3DPRIM_TRISTRIP_REVERSE             =     13,
   _3DPRIM_POLYGON                      =     14,
   _3DPRIM_RECTLIST                     =     15,
   _3DPRIM_LINELOOP                     =     16,
   _3DPRIM_POINTLIST_BF                 =     17,
   _3DPRIM_LINESTRIP_CONT               =     18,
   _3DPRIM_LINESTRIP_BF                 =     19,
   _3DPRIM_LINESTRIP_CONT_BF            =     20,
   _3DPRIM_TRIFAN_NOSTIPPLE             =     22,
};

enum GEN4_3D_Vertex_Component_Control {
   VFCOMP_NOSTORE                       =      0,
   VFCOMP_STORE_SRC                     =      1,
   VFCOMP_STORE_0                       =      2,
   VFCOMP_STORE_1_FP                    =      3,
   VFCOMP_STORE_1_INT                   =      4,
   VFCOMP_STORE_VID                     =      5,
};

enum GEN4_3D_Compare_Function {
   COMPAREFUNCTION_ALWAYS               =      0,
   COMPAREFUNCTION_NEVER                =      1,
   COMPAREFUNCTION_LESS                 =      2,
   COMPAREFUNCTION_EQUAL                =      3,
   COMPAREFUNCTION_LEQUAL               =      4,
   COMPAREFUNCTION_GREATER              =      5,
   COMPAREFUNCTION_NOTEQUAL             =      6,
   COMPAREFUNCTION_GEQUAL               =      7,
};

enum GEN4_SURFACE_FORMAT {
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

enum GEN4_TextureCoordinateMode {
   TCM_WRAP                             =      0,
   TCM_MIRROR                           =      1,
   TCM_CLAMP                            =      2,
   TCM_CUBE                             =      3,
   TCM_CLAMP_BORDER                     =      4,
   TCM_MIRROR_ONCE                      =      5,
};

#define GEN4_VS_STATE_length                   7
struct GEN4_VS_STATE {
   __gen_address_type                   KernelStartPointer;
   uint32_t                             GRFRegisterCount;
   bool                                 SingleProgramFlow;
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadPriority;
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint64_t                             ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             ConstantURBEntryReadLength;
   uint32_t                             ConstantURBEntryReadOffset;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             DispatchGRFStartRegisterforURBData;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             URBEntryAllocationSize;
   uint32_t                             NumberofURBEntries;
   bool                                 StatisticsEnable;
   __gen_address_type                   SamplerStatePointer;
   uint32_t                             SamplerCount;
   bool                                 VertexCacheDisable;
   bool                                 VSFunctionEnable;
};

static inline void
GEN4_VS_STATE_pack(__gen_user_data *data, void * restrict dst,
                   const struct GEN4_VS_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint32_t v0 =
      __gen_uint(values->GRFRegisterCount, 1, 3);
   dw[0] = __gen_combine_address(data, &dw[0], values->KernelStartPointer, v0);

   dw[1] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   dw[2] =
      __gen_offset(values->ScratchSpaceBasePointer, 10, 31) |
      __gen_uint(values->PerThreadScratchSpace, 0, 3);

   dw[3] =
      __gen_uint(values->ConstantURBEntryReadLength, 25, 30) |
      __gen_uint(values->ConstantURBEntryReadOffset, 18, 23) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9) |
      __gen_uint(values->DispatchGRFStartRegisterforURBData, 0, 3);

   dw[4] =
      __gen_uint(values->MaximumNumberofThreads, 25, 30) |
      __gen_uint(values->URBEntryAllocationSize, 19, 23) |
      __gen_uint(values->NumberofURBEntries, 11, 17) |
      __gen_uint(values->StatisticsEnable, 10, 10);

   const uint32_t v5 =
      __gen_uint(values->SamplerCount, 0, 2);
   dw[5] = __gen_combine_address(data, &dw[5], values->SamplerStatePointer, v5);

   dw[6] =
      __gen_uint(values->VertexCacheDisable, 1, 1) |
      __gen_uint(values->VSFunctionEnable, 0, 0);
}

#define GEN4_GS_STATE_length                   7
struct GEN4_GS_STATE {
   __gen_address_type                   KernelStartPointer;
   uint32_t                             GRFRegisterCount;
   bool                                 SingleProgramFlow;
   uint32_t                             BindingTableEntryCount;
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint64_t                             ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             ConstantURBEntryReadLength;
   uint32_t                             ConstantURBEntryReadOffset;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             DispatchGRFStartRegisterforURBData;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             URBEntryAllocationSize;
   uint32_t                             NumberofURBEntries;
   __gen_address_type                   SamplerStatePointer;
   uint32_t                             SamplerCount;
   bool                                 ReorderEnable;
   uint32_t                             MaximumVPIndex;
};

static inline void
GEN4_GS_STATE_pack(__gen_user_data *data, void * restrict dst,
                   const struct GEN4_GS_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint32_t v0 =
      __gen_uint(values->GRFRegisterCount, 1, 3);
   dw[0] = __gen_combine_address(data, &dw[0], values->KernelStartPointer, v0);

   dw[1] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   dw[2] =
      __gen_offset(values->ScratchSpaceBasePointer, 10, 31) |
      __gen_uint(values->PerThreadScratchSpace, 0, 3);

   dw[3] =
      __gen_uint(values->ConstantURBEntryReadLength, 25, 30) |
      __gen_uint(values->ConstantURBEntryReadOffset, 18, 23) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9) |
      __gen_uint(values->DispatchGRFStartRegisterforURBData, 0, 3);

   dw[4] =
      __gen_uint(values->MaximumNumberofThreads, 25, 29) |
      __gen_uint(values->URBEntryAllocationSize, 19, 23) |
      __gen_uint(values->NumberofURBEntries, 11, 17);

   const uint32_t v5 =
      __gen_uint(values->SamplerCount, 0, 2);
   dw[5] = __gen_combine_address(data, &dw[5], values->SamplerStatePointer, v5);

   dw[6] =
      __gen_uint(values->ReorderEnable, 30, 30) |
      __gen_uint(values->MaximumVPIndex, 0, 3);
}

#define GEN4_CLIP_STATE_length                11
struct GEN4_CLIP_STATE {
   __gen_address_type                   KernelStartPointer;
   uint32_t                             GRFRegisterCount;
   bool                                 SingleProgramFlow;
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadPriority;
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint64_t                             ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             ConstantURBEntryReadLength;
   uint32_t                             ConstantURBEntryReadOffset;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             DispatchGRFStartRegisterforURBData;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             URBEntryAllocationSize;
   uint32_t                             NumberofURBEntries;
   uint32_t                             VertexPositionSpace;
   bool                                 ViewportXYClipTestEnable;
   bool                                 ViewportZClipTestEnable;
   bool                                 GuardbandClipTestEnable;
   bool                                 UserClipFlagsMustClipEnable;
   uint32_t                             UserClipFlagsClipTestEnableBitmask;
   uint32_t                             ClipMode;
#define CLIPMODE_NORMAL                          0
#define CLIPMODE_ALL                             1
#define CLIPMODE_CLIP_NON_REJECTED               2
#define CLIPMODE_REJECT_ALL                      3
#define CLIPMODE_ACCEPT_ALL                      4
#define CLIPMODE_NORMAL_FFCLIP                   5
   uint64_t                             ClipperViewportStatePointer;
   uint32_t                             ScreenSpaceViewportXMin;
   uint32_t                             ScreenSpaceViewportXMax;
   uint32_t                             ScreenSpaceViewportYMin;
   uint32_t                             ScreenSpaceViewportYMax;
};

static inline void
GEN4_CLIP_STATE_pack(__gen_user_data *data, void * restrict dst,
                     const struct GEN4_CLIP_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint32_t v0 =
      __gen_uint(values->GRFRegisterCount, 1, 3);
   dw[0] = __gen_combine_address(data, &dw[0], values->KernelStartPointer, v0);

   dw[1] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   dw[2] =
      __gen_offset(values->ScratchSpaceBasePointer, 10, 31) |
      __gen_uint(values->PerThreadScratchSpace, 0, 3);

   dw[3] =
      __gen_uint(values->ConstantURBEntryReadLength, 25, 30) |
      __gen_uint(values->ConstantURBEntryReadOffset, 18, 23) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9) |
      __gen_uint(values->DispatchGRFStartRegisterforURBData, 0, 3);

   dw[4] =
      __gen_uint(values->MaximumNumberofThreads, 25, 29) |
      __gen_uint(values->URBEntryAllocationSize, 19, 23) |
      __gen_uint(values->NumberofURBEntries, 11, 17);

   dw[5] =
      __gen_uint(values->VertexPositionSpace, 29, 29) |
      __gen_uint(values->ViewportXYClipTestEnable, 28, 28) |
      __gen_uint(values->ViewportZClipTestEnable, 27, 27) |
      __gen_uint(values->GuardbandClipTestEnable, 26, 26) |
      __gen_uint(values->UserClipFlagsMustClipEnable, 24, 24) |
      __gen_uint(values->UserClipFlagsClipTestEnableBitmask, 16, 23) |
      __gen_uint(values->ClipMode, 13, 15);

   dw[6] =
      __gen_offset(values->ClipperViewportStatePointer, 5, 31);

   dw[7] =
      __gen_uint(values->ScreenSpaceViewportXMin, 0, 31);

   dw[8] =
      __gen_uint(values->ScreenSpaceViewportXMax, 0, 31);

   dw[9] =
      __gen_uint(values->ScreenSpaceViewportYMin, 0, 31);

   dw[10] =
      __gen_uint(values->ScreenSpaceViewportYMax, 0, 31);
}

#define GEN4_SF_STATE_length                   8
struct GEN4_SF_STATE {
   __gen_address_type                   KernelStartPointer;
   uint32_t                             GRFRegisterCount;
   bool                                 SingleProgramFlow;
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadPriority;
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint64_t                             ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             ConstantURBEntryReadLength;
   uint32_t                             ConstantURBEntryReadOffset;
   uint32_t                             VertexURBEntryReadLength;
   uint32_t                             VertexURBEntryReadOffset;
   uint32_t                             DispatchGRFStartRegisterforURBData;
   uint32_t                             MaximumNumberofThreads;
   uint32_t                             URBEntryAllocationSize;
   uint32_t                             NumberofURBEntries;
   uint64_t                             SetupViewportStatePointer;
   uint32_t                             ViewportTransformEnable;
   uint32_t                             FrontWinding;
#define FRONTWINDING_CW                          0
#define FRONTWINDING_CCW                         1
   bool                                 AntialiasingEnable;
   uint32_t                             CullMode;
#define CULLMODE_BOTH                            0
#define CULLMODE_NONE                            1
#define CULLMODE_FRONT                           2
#define CULLMODE_BACK                            3
   bool                                 FastScissorClipDisable;
   uint32_t                             LineWidth;
   uint32_t                             LineEndCapAntialiasingRegionWidth;
   uint32_t                             PointRasterizationRule;
#define RASTRULE_UPPER_LEFT                      0
#define RASTRULE_UPPER_RIGHT                     1
   bool                                 ZeroPixelTriangleFilterDisable;
   bool                                 _2x2PixelTriangleFilterDisable;
   bool                                 ScissorRectangleEnable;
   uint32_t                             DestinationOriginHorizontalBias;
   uint32_t                             DestinationOriginVerticalBias;
   bool                                 LastPixelEnable;
   uint32_t                             TriangleStripListProvokingVertexSelect;
   uint32_t                             LineStripListProvokingVertexSelect;
   uint32_t                             TriangleFanProvokingVertexSelect;
   uint32_t                             AALineDistanceMode;
#define AALINEDISTANCE_MANHATTAN                 0
#define AALINEDISTANCE_TRUE                      1
   bool                                 SpritePointEnable;
   uint32_t                             VertexSubPixelPrecisionSelect;
   uint32_t                             UsePointWidthState;
   uint32_t                             PointWidth;
};

static inline void
GEN4_SF_STATE_pack(__gen_user_data *data, void * restrict dst,
                   const struct GEN4_SF_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint32_t v0 =
      __gen_uint(values->GRFRegisterCount, 1, 3);
   dw[0] = __gen_combine_address(data, &dw[0], values->KernelStartPointer, v0);

   dw[1] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 13, 13) |
      __gen_uint(values->MaskStackExceptionEnable, 11, 11) |
      __gen_uint(values->SoftwareExceptionEnable, 7, 7);

   dw[2] =
      __gen_offset(values->ScratchSpaceBasePointer, 10, 31) |
      __gen_uint(values->PerThreadScratchSpace, 0, 3);

   dw[3] =
      __gen_uint(values->ConstantURBEntryReadLength, 25, 30) |
      __gen_uint(values->ConstantURBEntryReadOffset, 18, 23) |
      __gen_uint(values->VertexURBEntryReadLength, 11, 16) |
      __gen_uint(values->VertexURBEntryReadOffset, 4, 9) |
      __gen_uint(values->DispatchGRFStartRegisterforURBData, 0, 3);

   dw[4] =
      __gen_uint(values->MaximumNumberofThreads, 25, 30) |
      __gen_uint(values->URBEntryAllocationSize, 19, 23) |
      __gen_uint(values->NumberofURBEntries, 11, 18);

   const uint64_t v5 =
      __gen_offset(values->SetupViewportStatePointer, 5, 35) |
      __gen_uint(values->ViewportTransformEnable, 1, 1) |
      __gen_uint(values->FrontWinding, 0, 0) |
      __gen_uint(values->AntialiasingEnable, 63, 63) |
      __gen_uint(values->CullMode, 61, 62) |
      __gen_uint(values->FastScissorClipDisable, 60, 60) |
      __gen_uint(values->LineWidth, 56, 59) |
      __gen_uint(values->LineEndCapAntialiasingRegionWidth, 54, 55) |
      __gen_uint(values->PointRasterizationRule, 52, 53) |
      __gen_uint(values->ZeroPixelTriangleFilterDisable, 51, 51) |
      __gen_uint(values->_2x2PixelTriangleFilterDisable, 50, 50) |
      __gen_uint(values->ScissorRectangleEnable, 49, 49) |
      __gen_uint(values->DestinationOriginHorizontalBias, 45, 48) |
      __gen_uint(values->DestinationOriginVerticalBias, 41, 44);
   dw[5] = v5;
   dw[6] = v5 >> 32;

   dw[7] =
      __gen_uint(values->LastPixelEnable, 31, 31) |
      __gen_uint(values->TriangleStripListProvokingVertexSelect, 29, 30) |
      __gen_uint(values->LineStripListProvokingVertexSelect, 27, 28) |
      __gen_uint(values->TriangleFanProvokingVertexSelect, 25, 26) |
      __gen_uint(values->AALineDistanceMode, 14, 14) |
      __gen_uint(values->SpritePointEnable, 13, 13) |
      __gen_uint(values->VertexSubPixelPrecisionSelect, 12, 12) |
      __gen_uint(values->UsePointWidthState, 11, 11) |
      __gen_uint(values->PointWidth, 0, 10);
}

#define GEN4_WM_STATE_length                   7
struct GEN4_WM_STATE {
   __gen_address_type                   KernelStartPointer0;
   uint32_t                             GRFRegisterCount;
   bool                                 SingleProgramFlow;
   uint32_t                             BindingTableEntryCount;
   uint32_t                             ThreadPriority;
   uint32_t                             FloatingPointMode;
#define IEEE754                                  0
#define Alternate                                1
   uint32_t                             DepthCoefficientURBReadOffset;
   bool                                 IllegalOpcodeExceptionEnable;
   bool                                 MaskStackExceptionEnable;
   bool                                 SoftwareExceptionEnable;
   uint64_t                             ScratchSpaceBasePointer;
   uint32_t                             PerThreadScratchSpace;
   uint32_t                             ConstantURBEntryReadLength;
   uint32_t                             ConstantURBEntryReadOffset;
   uint32_t                             SetupURBEntryReadLength;
   uint32_t                             SetupURBEntryReadOffset;
   uint32_t                             DispatchGRFStartRegisterforURBData;
   __gen_address_type                   SamplerStatePointer;
   uint32_t                             SamplerCount;
   bool                                 StatisticsEnable;
   uint32_t                             MaximumNumberofThreads;
   bool                                 LegacyDiamondLineRasterization;
   bool                                 PixelShaderKillPixel;
   bool                                 PixelShaderComputedDepth;
   bool                                 PixelShaderUsesSourceDepth;
   bool                                 ThreadDispatchEnable;
   bool                                 EarlyDepthTestEnable;
   uint32_t                             LineEndCapAntialiasingRegionWidth;
   uint32_t                             LineAntialiasingRegionWidth;
   bool                                 PolygonStippleEnable;
   bool                                 GlobalDepthOffsetEnable;
   bool                                 LineStippleEnable;
   bool                                 LegacyGlobalDepthBiasEnable;
   bool                                 _32PixelDispatchEnable;
   bool                                 _16PixelDispatchEnable;
   bool                                 _8PixelDispatchEnable;
   float                                GlobalDepthOffsetConstant;
   float                                GlobalDepthOffsetScale;
};

static inline void
GEN4_WM_STATE_pack(__gen_user_data *data, void * restrict dst,
                   const struct GEN4_WM_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   const uint32_t v0 =
      __gen_uint(values->GRFRegisterCount, 1, 3);
   dw[0] = __gen_combine_address(data, &dw[0], values->KernelStartPointer0, v0);

   dw[1] =
      __gen_uint(values->SingleProgramFlow, 31, 31) |
      __gen_uint(values->BindingTableEntryCount, 18, 25) |
      __gen_uint(values->ThreadPriority, 17, 17) |
      __gen_uint(values->FloatingPointMode, 16, 16) |
      __gen_uint(values->DepthCoefficientURBReadOffset, 8, 13) |
      __gen_uint(values->IllegalOpcodeExceptionEnable, 4, 4) |
      __gen_uint(values->MaskStackExceptionEnable, 2, 2) |
      __gen_uint(values->SoftwareExceptionEnable, 1, 1);

   dw[2] =
      __gen_offset(values->ScratchSpaceBasePointer, 10, 31) |
      __gen_uint(values->PerThreadScratchSpace, 0, 3);

   dw[3] =
      __gen_uint(values->ConstantURBEntryReadLength, 25, 30) |
      __gen_uint(values->ConstantURBEntryReadOffset, 18, 23) |
      __gen_uint(values->SetupURBEntryReadLength, 11, 17) |
      __gen_uint(values->SetupURBEntryReadOffset, 4, 9) |
      __gen_uint(values->DispatchGRFStartRegisterforURBData, 0, 3);

   const uint32_t v4 =
      __gen_uint(values->SamplerCount, 2, 4) |
      __gen_uint(values->StatisticsEnable, 0, 0);
   dw[4] = __gen_combine_address(data, &dw[4], values->SamplerStatePointer, v4);

   dw[5] =
      __gen_uint(values->MaximumNumberofThreads, 25, 31) |
      __gen_uint(values->LegacyDiamondLineRasterization, 23, 23) |
      __gen_uint(values->PixelShaderKillPixel, 22, 22) |
      __gen_uint(values->PixelShaderComputedDepth, 21, 21) |
      __gen_uint(values->PixelShaderUsesSourceDepth, 20, 20) |
      __gen_uint(values->ThreadDispatchEnable, 19, 19) |
      __gen_uint(values->EarlyDepthTestEnable, 18, 18) |
      __gen_uint(values->LineEndCapAntialiasingRegionWidth, 16, 17) |
      __gen_uint(values->LineAntialiasingRegionWidth, 14, 15) |
      __gen_uint(values->PolygonStippleEnable, 13, 13) |
      __gen_uint(values->GlobalDepthOffsetEnable, 12, 12) |
      __gen_uint(values->LineStippleEnable, 11, 11) |
      __gen_uint(values->LegacyGlobalDepthBiasEnable, 10, 10) |
      __gen_uint(values->_32PixelDispatchEnable, 2, 2) |
      __gen_uint(values->_16PixelDispatchEnable, 1, 1) |
      __gen_uint(values->_8PixelDispatchEnable, 0, 0);

   dw[6] =
      __gen_float(values->GlobalDepthOffsetConstant);
}

#define GEN4_VERTEX_BUFFER_STATE_length        4
struct GEN4_VERTEX_BUFFER_STATE {
   uint32_t                             VertexBufferIndex;
   uint32_t                             BufferAccessType;
#define VERTEXDATA                               0
#define INSTANCEDATA                             1
   uint32_t                             BufferPitch;
   __gen_address_type                   BufferStartingAddress;
   uint32_t                             MaxIndex;
};

static inline void
GEN4_VERTEX_BUFFER_STATE_pack(__gen_user_data *data, void * restrict dst,
                              const struct GEN4_VERTEX_BUFFER_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->VertexBufferIndex, 27, 31) |
      __gen_uint(values->BufferAccessType, 26, 26) |
      __gen_uint(values->BufferPitch, 0, 10);

   dw[1] = __gen_combine_address(data, &dw[1], values->BufferStartingAddress, 0);

   dw[2] =
      __gen_uint(values->MaxIndex, 0, 31);

   dw[3] = 0;
}

#define GEN4_VERTEX_ELEMENT_STATE_length       2
struct GEN4_VERTEX_ELEMENT_STATE {
   uint32_t                             VertexBufferIndex;
   uint32_t                             Valid;
   uint32_t                             SourceElementFormat;
   uint32_t                             SourceElementOffset;
   uint32_t                             Component0Control;
   uint32_t                             Component1Control;
   uint32_t                             Component2Control;
   uint32_t                             Component3Control;
   uint32_t                             DestinationElementOffset;
};

static inline void
GEN4_VERTEX_ELEMENT_STATE_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN4_VERTEX_ELEMENT_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->VertexBufferIndex, 27, 31) |
      __gen_uint(values->Valid, 26, 26) |
      __gen_uint(values->SourceElementFormat, 16, 24) |
      __gen_uint(values->SourceElementOffset, 0, 10);

   dw[1] =
      __gen_uint(values->Component0Control, 28, 30) |
      __gen_uint(values->Component1Control, 24, 26) |
      __gen_uint(values->Component2Control, 20, 22) |
      __gen_uint(values->Component3Control, 16, 18) |
      __gen_uint(values->DestinationElementOffset, 0, 7);
}

#define GEN4_CLIP_VIEWPORT_length              4
struct GEN4_CLIP_VIEWPORT {
   uint32_t                             XMinClipGuardband;
   uint32_t                             XMaxClipGuardband;
   uint32_t                             YMinClipGuardband;
   uint32_t                             YMaxClipGuardband;
};

static inline void
GEN4_CLIP_VIEWPORT_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN4_CLIP_VIEWPORT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->XMinClipGuardband, 0, 31);

   dw[1] =
      __gen_uint(values->XMaxClipGuardband, 0, 31);

   dw[2] =
      __gen_uint(values->YMinClipGuardband, 0, 31);

   dw[3] =
      __gen_uint(values->YMaxClipGuardband, 0, 31);
}

#define GEN4_SF_VIEWPORT_length                8
struct GEN4_SF_VIEWPORT {
   float                                ViewportMatrixElementm00;
   float                                ViewportMatrixElementm11;
   float                                ViewportMatrixElementm22;
   float                                ViewportMatrixElementm30;
   float                                ViewportMatrixElementm31;
   float                                ViewportMatrixElementm32;
   uint32_t                             ScissorRectangleYMin;
   uint32_t                             ScissorRectangleXMin;
   uint32_t                             ScissorRectangleYMax;
   uint32_t                             ScissorRectangleXMax;
};

static inline void
GEN4_SF_VIEWPORT_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN4_SF_VIEWPORT * restrict values)
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

   dw[6] =
      __gen_uint(values->ScissorRectangleYMin, 16, 31) |
      __gen_uint(values->ScissorRectangleXMin, 0, 15);

   dw[7] =
      __gen_uint(values->ScissorRectangleYMax, 0, 15) |
      __gen_uint(values->ScissorRectangleXMax, 16, 31);
}

#define GEN4_CC_VIEWPORT_length                2
struct GEN4_CC_VIEWPORT {
   float                                MinimumDepth;
   float                                MaximumDepth;
};

static inline void
GEN4_CC_VIEWPORT_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN4_CC_VIEWPORT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_float(values->MinimumDepth);

   dw[1] =
      __gen_float(values->MaximumDepth);
}

#define GEN4_COLOR_CALC_STATE_length           6
struct GEN4_COLOR_CALC_STATE {
   bool                                 StencilTestEnable;
   enum GEN4_3D_Compare_Function        StencilTestFunction;
   uint32_t                             StencilFailOp;
#define STENCILOP_KEEP                           0
#define STENCILOP_ZERO                           1
#define STENCILOP_REPLACE                        2
#define STENCILOP_INCRSAT                        3
#define STENCILOP_DECRSAT                        4
#define STENCILOP_INCR                           5
#define STENCILOP_DECR                           6
#define STENCILOP_INVERT                         7
   uint32_t                             StencilPassDepthFailOp;
   uint32_t                             StencilPassDepthPassOp;
   bool                                 StencilBufferWriteEnable;
   bool                                 DoubleSidedStencilEnable;
   enum GEN4_3D_Compare_Function        BackFaceStencilTestFunction;
   uint32_t                             BackfaceStencilFailOp;
#define STENCILOP_KEEP                           0
#define STENCILOP_ZERO                           1
#define STENCILOP_REPLACE                        2
#define STENCILOP_INCRSAT                        3
#define STENCILOP_DECRSAT                        4
#define STENCILOP_INCR                           5
#define STENCILOP_DECR                           6
#define STENCILOP_INVERT                         7
   uint32_t                             BackfaceStencilPassDepthFailOp;
   uint32_t                             BackfaceStencilPassDepthPassOp;
   uint32_t                             StencilReferenceValue;
   uint32_t                             StencilTestMask;
   uint32_t                             StencilWriteMask;
   uint32_t                             BackFaceStencilReferenceValue;
   uint32_t                             BackfaceStencilTestMask;
   uint32_t                             BackfaceStencilWriteMask;
   bool                                 DepthTestEnable;
   enum GEN4_3D_Compare_Function        DepthTestFunction;
   bool                                 DepthBufferWriteEnable;
   bool                                 LogicOpEnable;
   uint32_t                             AlphaTestFormat;
#define ALPHATEST_UNORM8                         0
#define ALPHATEST_FLOAT32                        1
   bool                                 IndependentAlphaBlendEnable;
   bool                                 ColorBufferBlendEnable;
   bool                                 AlphaTestEnable;
   enum GEN4_3D_Compare_Function        AlphaTestFunction;
   __gen_address_type                   ColorCalculatorViewportStatePointer;
   bool                                 ColorDitherEnable;
   bool                                 RoundDisableFunctionDisable;
   uint32_t                             LogicOpFunction;
#define LOGICOP_CLEAR                            0
#define LOGICOP_NOR                              1
#define LOGICOP_AND_INVERTED                     2
#define LOGICOP_COPY_INVERTED                    3
#define LOGICOP_AND_REVERSE                      4
#define LOGICOP_INVERT                           5
#define LOGICOP_XOR                              6
#define LOGICOP_NAND                             7
#define LOGICOP_AND                              8
#define LOGICOP_EQUIV                            9
#define LOGICOP_NOOP                             10
#define LOGICOP_OR_INVERTED                      11
#define LOGICOP_COPY                             12
#define LOGICOP_OR_REVERSE                       13
#define LOGICOP_OR                               14
#define LOGICOP_SET                              15
   bool                                 StatisticsEnable;
   uint32_t                             AlphaBlendFunction;
#define BLENDFUNCTION_ADD                        0
#define BLENDFUNCTION_SUBTRACT                   1
#define BLENDFUNCTION_REVERSE_SUBTRACT           2
#define BLENDFUNCTION_MIN                        3
#define BLENDFUNCTION_MAX                        4
   uint32_t                             SourceAlphaBlendFactor;
#define BLENDFACTOR_ONE                          1
#define BLENDFACTOR_SRC_COLOR                    2
#define BLENDFACTOR_SRC_ALPHA                    3
#define BLENDFACTOR_DST_ALPHA                    4
#define BLENDFACTOR_DST_COLOR                    5
#define BLENDFACTOR_SRC_ALPHA_SATURATE           6
#define BLENDFACTOR_CONST_COLOR                  7
#define BLENDFACTOR_CONST_ALPHA                  8
#define BLENDFACTOR_SRC1_COLOR                   9
#define BLENDFACTOR_SRC1_ALPHA                   10
#define BLENDFACTOR_ZERO                         17
#define BLENDFACTOR_INV_SRC_COLOR                18
#define BLENDFACTOR_INV_SRC_ALPHA                19
#define BLENDFACTOR_INV_DST_ALPHA                20
#define BLENDFACTOR_INV_DST_COLOR                21
#define BLENDFACTOR_INV_CONST_COLOR              23
#define BLENDFACTOR_INV_CONST_ALPHA              24
#define BLENDFACTOR_INV_SRC1_COLOR               25
#define BLENDFACTOR_INV_SRC1_ALPHA               26
   uint32_t                             DestinationAlphaBlendFactor;
   uint32_t                             ColorBlendFunction;
#define BLENDFUNCTION_ADD                        0
#define BLENDFUNCTION_SUBTRACT                   1
#define BLENDFUNCTION_REVERSE_SUBTRACT           2
#define BLENDFUNCTION_MIN                        3
#define BLENDFUNCTION_MAX                        4
   uint32_t                             SourceBlendFactor;
   uint32_t                             DestinationBlendFactor;
   uint32_t                             XDitherOffset;
   uint32_t                             YDitherOffset;
   uint32_t                             ColorClampRange;
#define COLORCLAMP_UNORM                         0
#define COLORCLAMP_SNORM                         1
#define COLORCLAMP_RTFORMAT                      2
   bool                                 PreBlendColorClampEnable;
   bool                                 PostBlendColorClampEnable;
   float                                AlphaReferenceValue;
};

static inline void
GEN4_COLOR_CALC_STATE_pack(__gen_user_data *data, void * restrict dst,
                           const struct GEN4_COLOR_CALC_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->StencilTestEnable, 31, 31) |
      __gen_uint(values->StencilTestFunction, 28, 30) |
      __gen_uint(values->StencilFailOp, 25, 27) |
      __gen_uint(values->StencilPassDepthFailOp, 22, 24) |
      __gen_uint(values->StencilPassDepthPassOp, 19, 21) |
      __gen_uint(values->StencilBufferWriteEnable, 18, 18) |
      __gen_uint(values->DoubleSidedStencilEnable, 15, 15) |
      __gen_uint(values->BackFaceStencilTestFunction, 12, 14) |
      __gen_uint(values->BackfaceStencilFailOp, 9, 11) |
      __gen_uint(values->BackfaceStencilPassDepthFailOp, 6, 8) |
      __gen_uint(values->BackfaceStencilPassDepthPassOp, 3, 5);

   dw[1] =
      __gen_uint(values->StencilReferenceValue, 24, 31) |
      __gen_uint(values->StencilTestMask, 16, 23) |
      __gen_uint(values->StencilWriteMask, 8, 15) |
      __gen_uint(values->BackFaceStencilReferenceValue, 0, 7);

   dw[2] =
      __gen_uint(values->BackfaceStencilTestMask, 24, 31) |
      __gen_uint(values->BackfaceStencilWriteMask, 16, 23) |
      __gen_uint(values->DepthTestEnable, 15, 15) |
      __gen_uint(values->DepthTestFunction, 12, 14) |
      __gen_uint(values->DepthBufferWriteEnable, 11, 11) |
      __gen_uint(values->LogicOpEnable, 0, 0);

   dw[3] =
      __gen_uint(values->AlphaTestFormat, 15, 15) |
      __gen_uint(values->IndependentAlphaBlendEnable, 13, 13) |
      __gen_uint(values->ColorBufferBlendEnable, 12, 12) |
      __gen_uint(values->AlphaTestEnable, 11, 11) |
      __gen_uint(values->AlphaTestFunction, 8, 10);

   dw[4] = __gen_combine_address(data, &dw[4], values->ColorCalculatorViewportStatePointer, 0);

   dw[5] =
      __gen_uint(values->ColorDitherEnable, 31, 31) |
      __gen_uint(values->RoundDisableFunctionDisable, 30, 30) |
      __gen_uint(values->LogicOpFunction, 16, 19) |
      __gen_uint(values->StatisticsEnable, 15, 15) |
      __gen_uint(values->AlphaBlendFunction, 12, 14) |
      __gen_uint(values->SourceAlphaBlendFactor, 7, 11) |
      __gen_uint(values->DestinationAlphaBlendFactor, 2, 6);
}

#define GEN4_RENDER_SURFACE_STATE_length       6
struct GEN4_RENDER_SURFACE_STATE {
   uint32_t                             SurfaceType;
#define SURFTYPE_1D                              0
#define SURFTYPE_2D                              1
#define SURFTYPE_3D                              2
#define SURFTYPE_CUBE                            3
#define SURFTYPE_BUFFER                          4
#define SURFTYPE_NULL                            7
   uint32_t                             DataReturnFormat;
#define DATA_RETURN_FLOAT32                      0
#define DATA_RETURN_S114                         1
   uint32_t                             SurfaceFormat;
   uint32_t                             ColorBufferComponentWriteDisables;
#define WRITEDISABLE_ALPHA                       8
#define WRITEDISABLE_RED                         4
#define WRITEDISABLE_GREEN                       2
#define WRITEDISABLE_BLUE                        1
   bool                                 ColorBlendEnable;
   uint32_t                             VerticalLineStride;
   uint32_t                             VerticalLineStrideOffset;
   uint32_t                             MIPMapLayoutMode;
#define MIPLAYOUT_BELOW                          0
#define MIPLAYOUT_RIGHT                          1
   uint32_t                             RenderCacheReadWriteMode;
#define WRITE_ONLY                               0
#define READ_WRITE                               1
   uint32_t                             MediaBoundaryPixelMode;
#define NORMAL_MODE                              0
   uint32_t                             CubeFaceEnables;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             Height;
   uint32_t                             Width;
   uint32_t                             MIPCountLOD;
   uint32_t                             Depth;
   uint32_t                             SurfacePitch;
   uint32_t                             TiledSurface;
   uint32_t                             TileWalk;
#define TILEWALK_XMAJOR                          0
#define TILEWALK_YMAJOR                          1
   uint32_t                             SurfaceMinLOD;
   uint32_t                             MinimumArrayElement;
   uint32_t                             RenderTargetViewExtent;
};

static inline void
GEN4_RENDER_SURFACE_STATE_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN4_RENDER_SURFACE_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->SurfaceType, 29, 31) |
      __gen_uint(values->DataReturnFormat, 27, 27) |
      __gen_uint(values->SurfaceFormat, 18, 26) |
      __gen_uint(values->ColorBufferComponentWriteDisables, 14, 17) |
      __gen_uint(values->ColorBlendEnable, 13, 13) |
      __gen_uint(values->VerticalLineStride, 12, 12) |
      __gen_uint(values->VerticalLineStrideOffset, 11, 11) |
      __gen_uint(values->MIPMapLayoutMode, 10, 10) |
      __gen_uint(values->RenderCacheReadWriteMode, 8, 8) |
      __gen_uint(values->MediaBoundaryPixelMode, 6, 7) |
      __gen_uint(values->CubeFaceEnables, 0, 5);

   dw[1] = __gen_combine_address(data, &dw[1], values->SurfaceBaseAddress, 0);

   dw[2] =
      __gen_uint(values->Height, 19, 31) |
      __gen_uint(values->Width, 6, 18) |
      __gen_uint(values->MIPCountLOD, 2, 5);

   dw[3] =
      __gen_uint(values->Depth, 21, 31) |
      __gen_uint(values->SurfacePitch, 3, 19) |
      __gen_uint(values->TiledSurface, 1, 1) |
      __gen_uint(values->TileWalk, 0, 0);

   dw[4] =
      __gen_uint(values->SurfaceMinLOD, 28, 31) |
      __gen_uint(values->MinimumArrayElement, 17, 27) |
      __gen_uint(values->RenderTargetViewExtent, 8, 16);

   dw[5] = 0;
}

#define GEN4_SAMPLER_STATE_length              4
struct GEN4_SAMPLER_STATE {
   bool                                 SamplerDisable;
   uint32_t                             LODPreClampEnable;
#define CLAMP_ENABLE_D3D                         0
#define CLAMP_ENABLE_OGL                         1
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
   float                                TextureLODBias;
   uint32_t                             ShadowFunction;
#define PREFILTEROP_ALWAYS                       0
#define PREFILTEROP_NEVER                        1
#define PREFILTEROP_LESS                         2
#define PREFILTEROP_EQUAL                        3
#define PREFILTEROP_LEQUAL                       4
#define PREFILTEROP_GREATER                      5
#define PREFILTEROP_NOTEQUAL                     6
#define PREFILTEROP_GEQUAL                       7
   float                                MinLOD;
   float                                MaxLOD;
   uint32_t                             CubeSurfaceControlMode;
#define CUBECTRLMODE_PROGRAMMED                  0
#define CUBECTRLMODE_OVERRIDE                    1
   uint32_t                             TCXAddressControlMode;
   uint32_t                             TCYAddressControlMode;
   uint32_t                             TCZAddressControlMode;
   uint64_t                             BorderColorPointer;
   uint32_t                             MonochromeFilterHeightReserved;
   uint32_t                             MonochromeFilterWidth;
   bool                                 ChromaKeyEnable;
   uint32_t                             ChromaKeyIndex;
   uint32_t                             ChromaKeyMode;
#define KEYFILTER_KILL_ON_ANY_MATCH              0
#define KEYFILTER_REPLACE_BLACK                  1
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
};

static inline void
GEN4_SAMPLER_STATE_pack(__gen_user_data *data, void * restrict dst,
                        const struct GEN4_SAMPLER_STATE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->SamplerDisable, 31, 31) |
      __gen_uint(values->LODPreClampEnable, 28, 28) |
      __gen_ufixed(values->BaseMipLevel, 22, 26, 1) |
      __gen_uint(values->MipModeFilter, 20, 21) |
      __gen_uint(values->MagModeFilter, 17, 19) |
      __gen_uint(values->MinModeFilter, 14, 16) |
      __gen_sfixed(values->TextureLODBias, 3, 13, 6) |
      __gen_uint(values->ShadowFunction, 0, 2);

   dw[1] =
      __gen_ufixed(values->MinLOD, 22, 31, 6) |
      __gen_ufixed(values->MaxLOD, 12, 21, 6) |
      __gen_uint(values->CubeSurfaceControlMode, 9, 9) |
      __gen_uint(values->TCXAddressControlMode, 6, 8) |
      __gen_uint(values->TCYAddressControlMode, 3, 5) |
      __gen_uint(values->TCZAddressControlMode, 0, 2);

   dw[2] =
      __gen_offset(values->BorderColorPointer, 5, 31);

   dw[3] =
      __gen_uint(values->MonochromeFilterHeightReserved, 29, 31) |
      __gen_uint(values->MonochromeFilterWidth, 26, 28) |
      __gen_uint(values->ChromaKeyEnable, 25, 25) |
      __gen_uint(values->ChromaKeyIndex, 23, 24) |
      __gen_uint(values->ChromaKeyMode, 22, 22) |
      __gen_uint(values->MaximumAnisotropy, 19, 21) |
      __gen_uint(values->RAddressMinFilterRoundingEnable, 13, 13) |
      __gen_uint(values->RAddressMagFilterRoundingEnable, 14, 14) |
      __gen_uint(values->VAddressMinFilterRoundingEnable, 15, 15) |
      __gen_uint(values->VAddressMagFilterRoundingEnable, 16, 16) |
      __gen_uint(values->UAddressMinFilterRoundingEnable, 17, 17) |
      __gen_uint(values->UAddressMagFilterRoundingEnable, 18, 18);
}

#define GEN4_3DPRIMITIVE_length                6
#define GEN4_3DPRIMITIVE_length_bias           2
#define GEN4_3DPRIMITIVE_header                 \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      3,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      4

struct GEN4_3DPRIMITIVE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             VertexAccessType;
#define SEQUENTIAL                               0
#define RANDOM                                   1
   uint32_t                             PrimitiveTopologyType;
   uint32_t                             DWordLength;
   uint32_t                             VertexCount;
   uint32_t                             StartVertexLocation;
   int32_t                              BaseVertexLocation;
};

static inline void
GEN4_3DPRIMITIVE_pack(__gen_user_data *data, void * restrict dst,
                      const struct GEN4_3DPRIMITIVE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->VertexAccessType, 15, 15) |
      __gen_uint(values->PrimitiveTopologyType, 10, 14) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_uint(values->VertexCount, 0, 31);

   dw[2] =
      __gen_uint(values->StartVertexLocation, 0, 31);

   dw[3] =
      __gen_mbo(0, 31);

   dw[4] = 0;

   dw[5] =
      __gen_sint(values->BaseVertexLocation, 0, 31);
}

#define GEN4_3DSTATE_PIPELINED_POINTERS_length      7
#define GEN4_3DSTATE_PIPELINED_POINTERS_length_bias      2
#define GEN4_3DSTATE_PIPELINED_POINTERS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      5

struct GEN4_3DSTATE_PIPELINED_POINTERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   PointertoVS_STATE;
   __gen_address_type                   PointertoGS_STATE;
   bool                                 GSEnable;
   __gen_address_type                   PointertoCLIP_STATE;
   bool                                 CLIPEnable;
   __gen_address_type                   PointertoSF_STATE;
   __gen_address_type                   PointertoWM_STATE;
   __gen_address_type                   PointertoCOLOR_CALC_STATE;
};

static inline void
GEN4_3DSTATE_PIPELINED_POINTERS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN4_3DSTATE_PIPELINED_POINTERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] = __gen_combine_address(data, &dw[1], values->PointertoVS_STATE, 0);

   const uint32_t v2 =
      __gen_uint(values->GSEnable, 0, 0);
   dw[2] = __gen_combine_address(data, &dw[2], values->PointertoGS_STATE, v2);

   const uint32_t v3 =
      __gen_uint(values->CLIPEnable, 0, 0);
   dw[3] = __gen_combine_address(data, &dw[3], values->PointertoCLIP_STATE, v3);

   dw[4] = __gen_combine_address(data, &dw[4], values->PointertoSF_STATE, 0);

   dw[5] = __gen_combine_address(data, &dw[5], values->PointertoWM_STATE, 0);

   dw[6] = __gen_combine_address(data, &dw[6], values->PointertoCOLOR_CALC_STATE, 0);
}

#define GEN4_3DSTATE_AA_LINE_PARAMETERS_length      3
#define GEN4_3DSTATE_AA_LINE_PARAMETERS_length_bias      2
#define GEN4_3DSTATE_AA_LINE_PARAMETERS_header  \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =     10,  \
   .DWordLength                         =      1

struct GEN4_3DSTATE_AA_LINE_PARAMETERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   float                                AACoverageBias;
   float                                AACoverageSlope;
   float                                AACoverageEndCapBias;
   float                                AACoverageEndCapSlope;
};

static inline void
GEN4_3DSTATE_AA_LINE_PARAMETERS_pack(__gen_user_data *data, void * restrict dst,
                                     const struct GEN4_3DSTATE_AA_LINE_PARAMETERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_ufixed(values->AACoverageBias, 16, 23, 8) |
      __gen_ufixed(values->AACoverageSlope, 0, 7, 8);

   dw[2] =
      __gen_ufixed(values->AACoverageEndCapBias, 16, 23, 8) |
      __gen_ufixed(values->AACoverageEndCapSlope, 0, 7, 8);
}

#define GEN4_3DSTATE_BINDING_TABLE_POINTERS_length      6
#define GEN4_3DSTATE_BINDING_TABLE_POINTERS_length_bias      2
#define GEN4_3DSTATE_BINDING_TABLE_POINTERS_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      1,  \
   .DWordLength                         =      4

struct GEN4_3DSTATE_BINDING_TABLE_POINTERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             PointertoVSBindingTable;
   uint64_t                             PointertoGSBindingTable;
   uint64_t                             PointertoCLIPBindingTable;
   uint64_t                             PointertoSFBindingTable;
   uint64_t                             PointertoPSBindingTable;
};

static inline void
GEN4_3DSTATE_BINDING_TABLE_POINTERS_pack(__gen_user_data *data, void * restrict dst,
                                         const struct GEN4_3DSTATE_BINDING_TABLE_POINTERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->PointertoVSBindingTable, 5, 31);

   dw[2] =
      __gen_offset(values->PointertoGSBindingTable, 5, 31);

   dw[3] =
      __gen_offset(values->PointertoCLIPBindingTable, 5, 31);

   dw[4] =
      __gen_offset(values->PointertoSFBindingTable, 5, 31);

   dw[5] =
      __gen_offset(values->PointertoPSBindingTable, 5, 31);
}

#define GEN4_3DSTATE_CONSTANT_COLOR_length      5
#define GEN4_3DSTATE_CONSTANT_COLOR_length_bias      2
#define GEN4_3DSTATE_CONSTANT_COLOR_header      \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      1,  \
   .DWordLength                         =      3

struct GEN4_3DSTATE_CONSTANT_COLOR {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   float                                BlendConstantColorRed;
   float                                BlendConstantColorGreen;
   float                                BlendConstantColorBlue;
   float                                BlendConstantColorAlpha;
};

static inline void
GEN4_3DSTATE_CONSTANT_COLOR_pack(__gen_user_data *data, void * restrict dst,
                                 const struct GEN4_3DSTATE_CONSTANT_COLOR * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_float(values->BlendConstantColorRed);

   dw[2] =
      __gen_float(values->BlendConstantColorGreen);

   dw[3] =
      __gen_float(values->BlendConstantColorBlue);

   const uint64_t v4 =
      __gen_float(values->BlendConstantColorAlpha);
   dw[4] = v4;
   dw[5] = v4 >> 32;
}

#define GEN4_3DSTATE_DEPTH_BUFFER_length       5
#define GEN4_3DSTATE_DEPTH_BUFFER_length_bias      2
#define GEN4_3DSTATE_DEPTH_BUFFER_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      5,  \
   .DWordLength                         =      5

struct GEN4_3DSTATE_DEPTH_BUFFER {
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
   bool                                 TiledSurface;
   uint32_t                             TileWalk;
#define TILEWALK_YMAJOR                          1
   bool                                 DepthBufferCoordinateOffsetDisable;
   uint32_t                             SoftwareTiledRenderingMode;
#define NORMAL                                   0
#define STR1                                     1
#define STR2                                     3
   uint32_t                             SurfaceFormat;
#define D32_FLOAT_S8X24_UINT                     0
#define D32_FLOAT                                1
#define D24_UNORM_S8_UINT                        2
#define D24_UNORM_X8_UINT                        3
#define D16_UNORM                                5
   uint32_t                             SurfacePitch;
   __gen_address_type                   SurfaceBaseAddress;
   uint32_t                             Height;
#define SURFTYPE_1Dmustbezero                    0
   uint32_t                             Width;
   uint32_t                             LOD;
   uint32_t                             MIPMapLayoutMode;
#define MIPLAYOUT_BELOW                          0
#define MIPLAYOUT_RIGHT                          1
   uint32_t                             Depth;
#define SURFTYPE_CUBEmustbezero                  0
   uint32_t                             MinimumArrayElement;
   uint32_t                             RenderTargetViewExtent;
};

static inline void
GEN4_3DSTATE_DEPTH_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN4_3DSTATE_DEPTH_BUFFER * restrict values)
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
      __gen_uint(values->TiledSurface, 27, 27) |
      __gen_uint(values->TileWalk, 26, 26) |
      __gen_uint(values->DepthBufferCoordinateOffsetDisable, 25, 25) |
      __gen_uint(values->SoftwareTiledRenderingMode, 23, 24) |
      __gen_uint(values->SurfaceFormat, 18, 20) |
      __gen_uint(values->SurfacePitch, 0, 16);

   dw[2] = __gen_combine_address(data, &dw[2], values->SurfaceBaseAddress, 0);

   dw[3] =
      __gen_uint(values->Height, 19, 31) |
      __gen_uint(values->Width, 6, 18) |
      __gen_uint(values->LOD, 2, 5) |
      __gen_uint(values->MIPMapLayoutMode, 1, 1);

   dw[4] =
      __gen_uint(values->Depth, 21, 31) |
      __gen_uint(values->MinimumArrayElement, 10, 20) |
      __gen_uint(values->RenderTargetViewExtent, 1, 9);
}

#define GEN4_3DSTATE_DRAWING_RECTANGLE_length      4
#define GEN4_3DSTATE_DRAWING_RECTANGLE_length_bias      2
#define GEN4_3DSTATE_DRAWING_RECTANGLE_header   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      2

struct GEN4_3DSTATE_DRAWING_RECTANGLE {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             ClippedDrawingRectangleYMin;
   uint32_t                             ClippedDrawingRectangleXMin;
   uint32_t                             ClippedDrawingRectangleYMax;
   uint32_t                             ClippedDrawingRectangleXMax;
   int32_t                              DrawingRectangleOriginY;
   int32_t                              DrawingRectangleOriginX;
};

static inline void
GEN4_3DSTATE_DRAWING_RECTANGLE_pack(__gen_user_data *data, void * restrict dst,
                                    const struct GEN4_3DSTATE_DRAWING_RECTANGLE * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
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

#define GEN4_3DSTATE_INDEX_BUFFER_length       3
#define GEN4_3DSTATE_INDEX_BUFFER_length_bias      2
#define GEN4_3DSTATE_INDEX_BUFFER_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     10,  \
   .DWordLength                         =      1

struct GEN4_3DSTATE_INDEX_BUFFER {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   bool                                 CutIndexEnable;
   uint32_t                             IndexFormat;
#define INDEX_BYTE                               0
#define INDEX_WORD                               1
#define INDEX_DWORD                              2
   uint32_t                             DWordLength;
   __gen_address_type                   BufferStartingAddress;
   __gen_address_type                   BufferEndingAddress;
};

static inline void
GEN4_3DSTATE_INDEX_BUFFER_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN4_3DSTATE_INDEX_BUFFER * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->CutIndexEnable, 10, 10) |
      __gen_uint(values->IndexFormat, 8, 9) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] = __gen_combine_address(data, &dw[1], values->BufferStartingAddress, 0);

   dw[2] = __gen_combine_address(data, &dw[2], values->BufferEndingAddress, 0);
}

#define GEN4_3DSTATE_LINE_STIPPLE_length       3
#define GEN4_3DSTATE_LINE_STIPPLE_length_bias      2
#define GEN4_3DSTATE_LINE_STIPPLE_header        \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      8,  \
   .DWordLength                         =      1

struct GEN4_3DSTATE_LINE_STIPPLE {
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
GEN4_3DSTATE_LINE_STIPPLE_pack(__gen_user_data *data, void * restrict dst,
                               const struct GEN4_3DSTATE_LINE_STIPPLE * restrict values)
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

#define GEN4_3DSTATE_POLY_STIPPLE_OFFSET_length      2
#define GEN4_3DSTATE_POLY_STIPPLE_OFFSET_length_bias      2
#define GEN4_3DSTATE_POLY_STIPPLE_OFFSET_header \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      6,  \
   .DWordLength                         =      0

struct GEN4_3DSTATE_POLY_STIPPLE_OFFSET {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             PolygonStippleXOffset;
   uint32_t                             PolygonStippleYOffset;
};

static inline void
GEN4_3DSTATE_POLY_STIPPLE_OFFSET_pack(__gen_user_data *data, void * restrict dst,
                                      const struct GEN4_3DSTATE_POLY_STIPPLE_OFFSET * restrict values)
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

#define GEN4_3DSTATE_POLY_STIPPLE_PATTERN_length     33
#define GEN4_3DSTATE_POLY_STIPPLE_PATTERN_length_bias      2
#define GEN4_3DSTATE_POLY_STIPPLE_PATTERN_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      7,  \
   .DWordLength                         =     31

struct GEN4_3DSTATE_POLY_STIPPLE_PATTERN {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint32_t                             PatternRow[32];
};

static inline void
GEN4_3DSTATE_POLY_STIPPLE_PATTERN_pack(__gen_user_data *data, void * restrict dst,
                                       const struct GEN4_3DSTATE_POLY_STIPPLE_PATTERN * restrict values)
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

#define GEN4_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP_length      2
#define GEN4_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP_length_bias      2
#define GEN4_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP_header\
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      9

struct GEN4_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   float                                GlobalDepthOffsetClamp;
};

static inline void
GEN4_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP_pack(__gen_user_data *data, void * restrict dst,
                                            const struct GEN4_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_float(values->GlobalDepthOffsetClamp);
}

#define GEN4_3DSTATE_VERTEX_BUFFERS_length_bias      2
#define GEN4_3DSTATE_VERTEX_BUFFERS_header      \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      8,  \
   .DWordLength                         =      3

struct GEN4_3DSTATE_VERTEX_BUFFERS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   /* variable length fields follow */
};

static inline void
GEN4_3DSTATE_VERTEX_BUFFERS_pack(__gen_user_data *data, void * restrict dst,
                                 const struct GEN4_3DSTATE_VERTEX_BUFFERS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);
}

#define GEN4_3DSTATE_VERTEX_ELEMENTS_length_bias      2
#define GEN4_3DSTATE_VERTEX_ELEMENTS_header     \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      9,  \
   .DWordLength                         =      1

struct GEN4_3DSTATE_VERTEX_ELEMENTS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   /* variable length fields follow */
};

static inline void
GEN4_3DSTATE_VERTEX_ELEMENTS_pack(__gen_user_data *data, void * restrict dst,
                                  const struct GEN4_3DSTATE_VERTEX_ELEMENTS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);
}

#define GEN4_3DSTATE_VF_STATISTICS_length      1
#define GEN4_3DSTATE_VF_STATISTICS_length_bias      1
#define GEN4_3DSTATE_VF_STATISTICS_header       \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =     11

struct GEN4_3DSTATE_VF_STATISTICS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   bool                                 StatisticsEnable;
};

static inline void
GEN4_3DSTATE_VF_STATISTICS_pack(__gen_user_data *data, void * restrict dst,
                                const struct GEN4_3DSTATE_VF_STATISTICS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->StatisticsEnable, 0, 0);
}

#define GEN4_PIPELINE_SELECT_length            1
#define GEN4_PIPELINE_SELECT_length_bias       1
#define GEN4_PIPELINE_SELECT_header             \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      4

struct GEN4_PIPELINE_SELECT {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             PipelineSelection;
#define _3D                                      0
#define Media                                    1
};

static inline void
GEN4_PIPELINE_SELECT_pack(__gen_user_data *data, void * restrict dst,
                          const struct GEN4_PIPELINE_SELECT * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->PipelineSelection, 0, 1);
}

#define GEN4_PIPE_CONTROL_length               5
#define GEN4_PIPE_CONTROL_length_bias          2
#define GEN4_PIPE_CONTROL_header                \
   .CommandType                         =      3,  \
   .CommandSubType                      =      3,  \
   ._3DCommandOpcode                    =      2,  \
   ._3DCommandSubOpcode                 =      0,  \
   .DWordLength                         =      3

struct GEN4_PIPE_CONTROL {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             PostSyncOperation;
#define NoWrite                                  0
#define WriteImmediateData                       1
#define WritePSDepthCount                        2
#define WriteTimestamp                           3
   bool                                 DepthStallEnable;
   bool                                 WriteCacheFlushEnable;
   bool                                 InstructionStateCacheFlushEnable;
   bool                                 NotifyEnable;
   uint32_t                             DWordLength;
   __gen_address_type                   DestinationAddress;
   uint32_t                             DestinationAddressType;
#define DAT_PPGTT                                0
#define DAT_GGTT                                 1
   uint64_t                             ImmediateData;
};

static inline void
GEN4_PIPE_CONTROL_pack(__gen_user_data *data, void * restrict dst,
                       const struct GEN4_PIPE_CONTROL * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->PostSyncOperation, 14, 15) |
      __gen_uint(values->DepthStallEnable, 13, 13) |
      __gen_uint(values->WriteCacheFlushEnable, 12, 12) |
      __gen_uint(values->InstructionStateCacheFlushEnable, 11, 11) |
      __gen_uint(values->NotifyEnable, 8, 8) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint32_t v1 =
      __gen_uint(values->DestinationAddressType, 2, 2);
   dw[1] = __gen_combine_address(data, &dw[1], values->DestinationAddress, v1);

   const uint64_t v2 =
      __gen_uint(values->ImmediateData, 0, 63);
   dw[2] = v2;
   dw[3] = v2 >> 32;

   dw[4] = 0;
}

#define GEN4_STATE_BASE_ADDRESS_length        10
#define GEN4_STATE_BASE_ADDRESS_length_bias      2
#define GEN4_STATE_BASE_ADDRESS_header          \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      1,  \
   .DWordLength                         =      4

struct GEN4_STATE_BASE_ADDRESS {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   GeneralStateBaseAddress;
   bool                                 GeneralStateBaseAddressModifyEnable;
   __gen_address_type                   SurfaceStateBaseAddress;
   bool                                 SurfaceStateBaseAddressModifyEnable;
   __gen_address_type                   IndirectObjectBaseAddress;
   bool                                 IndirectObjectBaseAddressModifyEnable;
   __gen_address_type                   GeneralStateAccessUpperBound;
   bool                                 GeneralStateAccessUpperBoundModifyEnable;
   __gen_address_type                   IndirectObjectAccessUpperBound;
   bool                                 IndirectObjectAccessUpperBoundModifyEnable;
};

static inline void
GEN4_STATE_BASE_ADDRESS_pack(__gen_user_data *data, void * restrict dst,
                             const struct GEN4_STATE_BASE_ADDRESS * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   const uint32_t v1 =
      __gen_uint(values->GeneralStateBaseAddressModifyEnable, 0, 0);
   dw[1] = __gen_combine_address(data, &dw[1], values->GeneralStateBaseAddress, v1);

   const uint32_t v2 =
      __gen_uint(values->SurfaceStateBaseAddressModifyEnable, 0, 0);
   dw[2] = __gen_combine_address(data, &dw[2], values->SurfaceStateBaseAddress, v2);

   const uint32_t v3 =
      __gen_uint(values->IndirectObjectBaseAddressModifyEnable, 0, 0);
   dw[3] = __gen_combine_address(data, &dw[3], values->IndirectObjectBaseAddress, v3);

   const uint32_t v4 =
      __gen_uint(values->GeneralStateAccessUpperBoundModifyEnable, 0, 0);
   dw[4] = __gen_combine_address(data, &dw[4], values->GeneralStateAccessUpperBound, v4);

   const uint32_t v5 =
      __gen_uint(values->IndirectObjectAccessUpperBoundModifyEnable, 0, 0);
   dw[5] = __gen_combine_address(data, &dw[5], values->IndirectObjectAccessUpperBound, v5);

   dw[6] = 0;

   dw[7] = 0;

   dw[8] = 0;

   dw[9] = 0;
}

#define GEN4_STATE_PREFETCH_length             2
#define GEN4_STATE_PREFETCH_length_bias        2
#define GEN4_STATE_PREFETCH_header              \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      0,  \
   ._3DCommandSubOpcode                 =      3,  \
   .DWordLength                         =      0

struct GEN4_STATE_PREFETCH {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   __gen_address_type                   PrefetchPointer;
   uint32_t                             PrefetchCount;
};

static inline void
GEN4_STATE_PREFETCH_pack(__gen_user_data *data, void * restrict dst,
                         const struct GEN4_STATE_PREFETCH * restrict values)
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

#define GEN4_STATE_SIP_length                  2
#define GEN4_STATE_SIP_length_bias             2
#define GEN4_STATE_SIP_header                   \
   .CommandType                         =      3,  \
   .CommandSubType                      =      0,  \
   ._3DCommandOpcode                    =      1,  \
   ._3DCommandSubOpcode                 =      2,  \
   .DWordLength                         =      0

struct GEN4_STATE_SIP {
   uint32_t                             CommandType;
   uint32_t                             CommandSubType;
   uint32_t                             _3DCommandOpcode;
   uint32_t                             _3DCommandSubOpcode;
   uint32_t                             DWordLength;
   uint64_t                             SystemInstructionPointer;
};

static inline void
GEN4_STATE_SIP_pack(__gen_user_data *data, void * restrict dst,
                    const struct GEN4_STATE_SIP * restrict values)
{
   uint32_t * restrict dw = (uint32_t * restrict) dst;

   dw[0] =
      __gen_uint(values->CommandType, 29, 31) |
      __gen_uint(values->CommandSubType, 27, 28) |
      __gen_uint(values->_3DCommandOpcode, 24, 26) |
      __gen_uint(values->_3DCommandSubOpcode, 16, 23) |
      __gen_uint(values->DWordLength, 0, 7);

   dw[1] =
      __gen_offset(values->SystemInstructionPointer, 4, 31);
}

#endif /* GEN4_PACK_H */

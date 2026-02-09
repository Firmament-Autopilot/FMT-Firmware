/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2014 - 2023 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/


#ifndef _VIV_DC_TYPE_H_
#define _VIV_DC_TYPE_H_
#include "viv_dc_options.h"
#ifndef __linux__
#include <math.h>
#endif

#if vivENABLE_DISPLAY_NEWGMMA
#define GAMMA_TABLE_SIZE 300
#else
#define GAMMA_TABLE_SIZE 256
#endif

#define DEGAMMA_TABLE_SIZE 260

/*
 * Common parameter types
 */
typedef int                     gctBOOL;
typedef char                    gctCHAR;
typedef float                   gctFLOAT;
typedef int                     gctINT;
typedef signed char             gctINT8;
typedef signed short            gctINT16;
typedef signed int              gctINT32;
typedef signed long long        gctINT64;
typedef unsigned long           gctSIZE_T;
typedef unsigned int            gctUINT;
typedef unsigned char           gctUINT8;
typedef unsigned short          gctUINT16;
typedef unsigned int            gctUINT32;
typedef unsigned long long      gctUINT64;
typedef void                    gctVOID;
typedef double                  gctDOUBLE;

#define vivFALSE                0
#define vivTRUE                 1

#ifdef __cplusplus
#   define vivNULL              0
#else
#   define vivNULL              ((void *) 0)
#endif

#ifdef __cplusplus
#   define gcvNULL              0
#else
#   define gcvNULL              ((void *) 0)
#endif

/*
 * Common parameter pointer types
 */
typedef gctBOOL *               gctBOOL_PTR;
typedef void *                  gctFILE;
typedef float *                 gctFLOAT_PTR;
typedef void *                  gctHANDLE;
typedef gctINT *                gctINT_PTR;
typedef gctINT8 *               gctINT8_PTR;
typedef gctINT16 *              gctINT16_PTR;
typedef gctINT32 *              gctINT32_PTR;
typedef gctINT64 *              gctINT64_PTR;
typedef void *                  gctPHYS_ADDR;
typedef void *                  gctPOINTER;
typedef gctSIZE_T *             gctSIZE_T_PTR;
typedef void *                  gctSTRING;
typedef gctUINT *               gctUINT_PTR;
typedef gctUINT8 *              gctUINT8_PTR;
typedef gctUINT16 *             gctUINT16_PTR;
typedef gctUINT32 *             gctUINT32_PTR;
typedef gctUINT64 *             gctUINT64_PTR;

typedef gctUINT32               gctADDRESS;

/***********************************/
/*           Enumeration           */
/***********************************/

typedef enum _viv_layer_status{
    vivLATER_IDLE,
    vivLATER_OCCUPIED_BY_SELF,
    vivLATER_OCCUPIED_BY_OTHERS,
}
viv_layer_status;

typedef enum _viv_display{
    vivDISPLAY_0,
    vivDISPLAY_1,
    vivDISPLAY_COUNT,
}
viv_display;

/*
 * Error status enumeration
 */
typedef enum _viv_status_type {
    vivSTATUS_HEAP_CORRUPTED = -7,
    vivSTATUS_OUT_OF_RESOURCES = -6,
    vivSTATUS_TIMEOUT = -5,
    vivSTATUS_NOT_SUPPORT = -4,
    vivSTATUS_OOM = -3,
    vivSTATUS_FAILED = -2,
    vivSTATUS_INVALID_ARGUMENTS = -1,

    vivSTATUS_OK = 0,
}
viv_status_type, vivSTATUS;

 /*
  * Input format type.
  */
typedef enum _viv_input_format_type {
    /* RGB format */
    vivARGB4444,
    vivABGR4444,
    vivRGBA4444,
    vivBGRA4444,
    vivXRGB4444,
    vivXBGR4444,
    vivRGBX4444,
    vivBGRX4444,
    vivARGB1555,
    vivABGR1555,
    vivRGBA1555,
    vivBGRA1555,
    vivXRGB1555,
    vivXBGR1555,
    vivRGBX1555,
    vivBGRX1555,
    vivRGB565,
    vivBGR565,
    vivARGB8888,
    vivABGR8888,
    vivRGBA8888,
    vivBGRA8888,
    vivXRGB8888,
    vivXBGR8888,
    vivRGBX8888,
    vivBGRX8888,
    vivARGB2101010,

    /* YUV formt */
    vivYUY2 = 0x100,
    vivUYVY,
    vivYV12,
    vivNV12,
    vivNV16,
    vivP010,
    vivNV12_10BIT,
    vivYUV444,
    vivYUV444_10BIT,
    vivYU12,
    vivNV21,

    /* Cursor format */
    vivCURSOR_ARGB = 0x200,
}
viv_input_format_type;

/* Color sapce change mode */
typedef enum _viv_csc_mode {
    vivCSC_BT601,
    vivCSC_BT709,
    vivCSC_BT2020,
    vivCSC_USER_DEF,
}
viv_csc_mode;

 /*
  * Display type.
  */
typedef enum _viv_display_type {
    vivDPI,
    vivDP,
    vivEDP,
    vivDBI,
}
viv_display_type;

 /*
  * Display format type.
  */
typedef enum _viv_display_format_type {
    /* DPI */
    vivD24,
    vivD30,
    vivD16CFG1,
    vivD16CFG2,
    vivD16CFG3,
    vivD18CFG1,
    vivD18CFG2,

    /* DP */
    vivDPRGB565 = 0x100,
    vivDPRGB666,
    vivDPRGB888,
    vivDPRGB101010,
    vivDPYUV420B8CFG1,
    vivDPYUV420B8CFG2,
    vivDPYUV422B8CFG1,
    vivDPYUV422B8CFG2,
    vivDPYUV444B8CFG1,
    vivDPYUV444B8CFG2,
    vivDPYUV420B10CFG1,
    vivDPYUV420B10CFG2,
    vivDPYUV422B10CFG1,
    vivDPYUV422B10CFG2,
    vivDPYUV444B10CFG1,
    vivDPYUV444B10CFG2,
    vivDPYUV420B8CFG3,
    vivDPYUV420B10CFG3,
    vivDPYUV444B8CFG3,
    vivDPYUV444B10CFG3,

    /* DBI */
    vivD8R3G3B2,
    vivD8R4G4B4,
    vivD8R5G6B5,
    vivD8R6G6B6,
    vivD8R8G8B8,
    vivD9R6G6B6,
    vivD16R3G3B2,
    vivD16R4G4B4,
    vivD16R5G6B5,
    vivD16R6G6B6OP1,
    vivD16R6G6B6OP2,
    vivD16R8G8B8OP1,
    vivD16R8G8B8OP2,
    vivD1R5G6B5OP1,
    vivD1R5G6B5OP2,
    vivD1R5G6B5OP3,
    vivD1R8G8B8OP1,
    vivD1R8G8B8OP2,
    vivD1R8G8B8OP3,
}
viv_display_format_type;

 /*
  *witeback type
  */
typedef enum _viv_write_back_type {
    vivWB_DEFAULT,
    vivWB_AFTER_BLENDING,
    vivWB_AFTER_DITHER,
}
viv_write_back_type;

 /*
  * Tilling format type.
  */
typedef enum _viv_tiling_type {
    vivLINEAR,
    vivTILED4X4,
    vivTILED8X8,
    vivSUPER_TILED_X,
    vivSUPER_TILED_Y,
}
viv_tiling_type;

 /*
  * Dec tile mode.
  */
typedef enum _viv_dec_tile_mode {
    vivDEC_TILE_MODE_8X8_XMAJOR,
    vivDEC_TILE_MODE_8X4,
    vivDEC_TILE_MODE_4X8,
    vivDEC_TILE_MODE_256X1,
    vivDEC_TILE_MODE_128X1,
    vivDEC_TILE_MODE_64X1,
    vivDEC_TILE_MODE_32X1,
    vivDEC_TILE_MODE_64X4,
    vivDEC_TILE_MODE_32X4,
    vivDEC_TILE_MODE_16X4,
    vivDEC_TILE_MODE_128X4,
}
viv_dec_tile_mode;

 /*
  * Filter tap type.
  */
typedef enum _viv_filter_tap_type {
    vivFILTER_H3_V3,
    vivFILTER_H5_V3,
}
viv_filter_tap_type;

 /*
  * Cursoe size type.
  */
typedef enum _viv_cursor_size_type {
    vivCURSOR_32x32,
    vivCURSOR_64x64,
}
viv_cursor_size_type;

 /*
  * Alpha mode.
  */
typedef enum _viv_alpha_mode {
    vivALPHA_NORMAL,
    vivALPHA_INVERSED,
}
viv_alpha_mode;

 /*
  * Global alpha mode.
  */
typedef enum _viv_global_alpha_mode {
    vivGALPHA_NORMAL,
    vivGALPHA_GLOBAL,
    vivGALPHA_SCALED,
}
viv_global_alpha_mode;

 /*
  * Porter duff mode.
  */
typedef enum _viv_porter_duff_mode {
    vivPD_CLEAR,
    vivPD_SRC,
    vivPD_DST,
    vivPD_SRC_OVER,
    vivPD_DST_OVER,
    vivPD_SRC_IN,
    vivPD_DST_IN,
    vivPD_SRC_OUT,
    vivPD_DST_OUT,
    vivPD_SRC_ATOP,
    vivPD_DST_ATOP,
    vivPD_XOR,
}
viv_porter_duff_mode;

 /*
  * Src/dst blend mode.
  */
typedef enum _viv_blend_mode {
    vivBLENDING_ZERO,
    vivBLENDING_ONE,
    vivBLENDING_NORMAL,
    vivBLENDING_INVERSED,
    vivBLENDING_COLOR,
    vivBLENDING_COLOR_INVERSED,
    vivBLENDING_SATURATED_ALPHA,
    vivBLENDING_SATURATED_DEST_ALPHA,
}
viv_blend_mode;

 /*
  * Pool type.
  */
typedef enum _viv_pool_type {
    gcvPOOL_CONTIGUOUS,
    gcvPOOL_DEFAULT,
    gcvPOOL_USER,
}
viv_pool_type;

#if ALLOC_RESERVED_MEM_IN_KERNEL
typedef enum _viv_resemem_type{
    viv_mem_type_ddr,
    viv_mem_count,
}
viv_resmem_type;
#endif
 /*
  * Rotation type.
  */
typedef enum _viv_rotation_type {
    vivROTANGLE_0,
    vivROTANGLE_90,
    vivROTANGLE_180,
    vivROTANGLE_270,
    vivROTANGLE_FLIPX,
    vivROTANGLE_FLIPY,
    vivROTANGLE_FLIPXY,
}
viv_rotation_type;

 /*
  * Display size type.
  */
typedef enum _viv_display_size_type {
    vivDISPLAY_320_480_60,
    vivDISPLAY_480_800_60,
    vivDISPLAY_480_864_60,
    vivDISPLAY_640_480_60,
    vivDISPLAY_720_480_60,
    vivDISPLAY_800_480_60,
    vivDISPLAY_1024_600_60,
    vivDISPLAY_1024_768_60,
    vivDISPLAY_1280_720_60,
    vivDISPLAY_1920_1080_60,
    vivDISPLAY_3840_2160_30,
    vivDISPLAY_3840_2160_60,
    vivDISPLAY_4096_2160_60,
    vivDISPLAY_5760_756_60,
    vivDISPLAY_CUSTOMIZED,
}
viv_display_size_type;

 /*
  * Chip feature enumeration.
  */
typedef enum _viv_dc_features {
    vivFEATURE_DISPLAY_COUNT,
    vivFEATURE_LAYER_COUNT,
    vivFEATURE_CURSOR_COUNT,
    vivFEATURE_GAMMA_BIT_OUT,
    vivFEATURE_SECURITY,
    vivFEATURE_MMU,
    vivFEATURE_CURSOR_VERSION,
    vivFEATURE_CSC_MOUDLE,
    vivFEATURE_3D_LUT,
    vivFEATURE_DE_GAMMA,
    vivFEATURE_DP,
    vivFEATURE_DP_YUV,
    vivFEATURE_DPI,
    vivFEATURE_DBI,
    vivFEATURE_NEW_GAMMA,
    vivFEATURE_COLOR_BAR,
    vivFEATURE_CRC,
    vivFEATURE_40BIT_ADDRESS,
    vivFEATURE_WRITEBACK,
    vivFEATURE_PROGRAM_WB,
    vivFEATURE_CUSTOMER_TILE4X4,
    vivFEATURE_DUAL_OS,
    /* Insert features above this comment only. */
    vivFEATURE_COUNT,    /* Not a feature. */
}
viv_dc_features;

/*
  * Layer feature enumeration.
  */
typedef enum _viv_dc_layer_cap {
    vivLAYER_CAP_DEC400_COMPRESSION,
    vivLAYER_CAP_SCALE,
    vivLAYER_CAP_TILED,
    vivLAYER_CAP_ROTATION,
    vivLAYER_CAP_ROI,
    /* Insert features above this comment only. */
    vivLAYER_CAP_COUNT,    /* Not a feature. */
}
viv_dc_layer_cap;


/***********************************/
/*          Data Structure         */
/***********************************/

typedef struct _viv_dc_buffer
{
    /* Allocated memory. */
    gctPOINTER   handle[3];
    gctPOINTER   logical[3];
    gctADDRESS    phyAddress[3];
    gctADDRESS    gpuAddress[3];

    /* property */
    viv_input_format_type format;
    gctBOOL               security;
    viv_pool_type         pool;
    viv_tiling_type       tiling;

    /* Size */
    gctUINT32 width;
    gctUINT32 height;
    gctUINT32 stride[3];
}
viv_dc_buffer;

typedef struct _viv_tilestatus_buffer
{
    /* Allocated memory. */
    gctPOINTER  tileStatusHandle[3];
    gctPOINTER  tileStatusLogical[3];
    gctADDRESS   tileStatusHWAddress[3];
    gctADDRESS   tileStatusGPUAddress[3];

    /* property */
    viv_input_format_type format;
    gctBOOL            security;
    viv_pool_type      pool;
    viv_tiling_type    tiling;

    /* Size */
    gctUINT32 width;
    gctUINT32 height;
}
viv_tilestatus_buffer;

typedef enum _viv_cache_mode
{
    vivCACHE_NONE,
    vivCACHE_128,
    vivCACHE_256,
}
viv_cache_mode;

typedef struct _viv_cursor
{
    /* hotspot */
    gctUINT32  hsx;
    gctUINT32  hsy;

    /* location */
    gctUINT32 x;
    gctUINT32 y;

    /* size */
    viv_cursor_size_type  size;

    /* background */
    gctUINT bg_color;

    /* foreground */
    gctUINT fg_color;

    /* format */
    viv_input_format_type format;
}
viv_cursor;

typedef struct _viv_output
{
    viv_display_type type;
    viv_display_format_type format;
}
viv_output;

typedef struct _viv_layer_alpha_mode
{
    /* source global alpha */
    viv_global_alpha_mode  srcGlobalAlphaMode;
    gctUINT32              srcGlobalAlphaValue;

    /* source alpha */
    viv_alpha_mode    srcAlphaMode;
    gctUINT32         srcAlphaValue;

     /* dest global alpha */
    viv_global_alpha_mode  dstGlobalAlphaMode;
    gctUINT32              dstGlobalAlphaValue;

    /* dest alpha */
    viv_alpha_mode    dstAlphaMode;
    gctUINT32         dstAlphaValue;

}
viv_layer_alpha_mode;

typedef struct _viv_dc_rect
{
    gctUINT32   x;         /* Rectangle start point X coordinate */
    gctUINT32   y;         /* Rectangle start point Y coordinate */
    gctUINT32   w;         /* Rectangle width*/
    gctUINT32   h;         /* Rectangle height */
}
viv_dc_rect ;

typedef struct _viv_dc_color
{
    gctUINT8  a;
    gctUINT8  r;
    gctUINT8  g;
    gctUINT8  b;
}
viv_dc_color ;

typedef struct _viv_dc_gamma
{
    gctUINT16 gammaTable[GAMMA_TABLE_SIZE][3];
}
viv_dc_gamma;

typedef struct _viv_dc_degamma
{
    gctUINT16 degammaTable[DEGAMMA_TABLE_SIZE][3];
}
viv_dc_degamma;

#define MAX_CSC_COEF_NUM 16
#define MAX_CRC_NUM 17
/* CSC YUV to RGB limmite range coeffient num */
#define YUV2RGB_LR_COEF_NUM 16
#define YUV2RGB_FR_COEF_NUM 12
#define RGB2YUV_COEF_NUM 12
#define RGB2RGB_COEF_NUM 9

/***********************************/
/*        Ori Enum & Struct        */
/***********************************/
/* Chip models. */
typedef enum _dcCHIPMODEL
{
    dc0000  = 0x0000,
    dc8000  = 0x0000,
    dculta_l  = 0x0000,
}
dcCHIPMODEL;

 /*
  * Chip feature.
  */
typedef enum _gceFEATURE
{
    gcvFEATURE_DC_SOURCE_ROTATION,
    gcvFEATURE_DC_TILED,
    gcvFEATURE_DC_YUV_L1,
    gcvFEATURE_DC_OVERLAY_SCALING,
    gcvFEATURE_DC_D30_OUTPUT,
    gcvFEATURE_DC_MMU,
    gcvFEATURE_DC_COMPRESSION,
    gcvFEATURE_DC_QOS,
    gcvFEATURE_DC_HORFILTER_5,
    gcvFEATURE_DC_10BIT,    /*Fix 10-bit NV12/ NV16 format cross 4K byte issue. */
    gcvFEATURE_DC_FIX_HWCURSOR,   /* Fix HW cursor issue, cursor can cross original framebuffer boundary. */
    gcvFEATURE_DC_ROI, /* Support ROI feature */
    gcvFEATURE_DC_DP, /* Support DP output type */
    gcvFEATURE_DC_DP_YUV, /* Support DP YUV output format */
    gcvFEATURE_DC_NEW_GAMMA, /* Support new gamma, expand channel bits */
    gcvFEATURE_DC_CURSOR_SIZE_CONFIG, /* Support configurable cursor size */
    gcvFEATURE_DC_CSC_MOUDLE, /* Support programmable csc moudle */
    gcvFEATURE_DC_TSC_PREFETCH, /* Support TSC prefetch */
    gcvFEATURE_DC_MMU_PREFETCH, /* Support MMU prefetch */
    gcvFEATURE_DC_FORMAT_OPT, /* remove NV12_10bit/NV16_10bit/YV12/Index/TileY */
    /* Insert features above this comment only. */
    gcvFEATURE_COUNT    /* Not a feature. */
}
gceFEATURE;

 /*
  * DBI type.
  * Used in viv_conf_output_dbi_set_config()
  */
typedef enum _viv_dbi_type {
    vivDBI_AFIXED,
    vivDBI_ACLOCK,
    vivDBI_B,
    vivDBI_C,
}
viv_dbi_type;

 /*
  * DBI command flag
  * Used in viv_conf_output_dbi_set_command()
  */
typedef enum _viv_dbi_command_type {
    vivDBI_COMMAND_ADDRESS,
    vivDBI_COMMAND_MEM,
    vivDBI_COMMAND_DATA,
}
viv_dbi_command_type;

/*
  * csc moulde switch type.
  */
typedef enum _viv_csc_moudle {
    /* Unsupport programmable csc moudle */
    vivCSC_NONE,
    vivCSC_RGB2RGB,
    vivCSC_YUV2RGB,
    vivCSC_RGB2YUV,
}
viv_csc_moudle;

/*
 * The enlarge value for 3D LUT.
 */
typedef enum _viv_lut_enlarge {
    vivLUT_ENLARGE0,
    vivLUT_ENLARGE9,
    vivLUT_ENLARGE10,
}
viv_lut_enlarge;

/*
 * Core type
 */
typedef enum _viv_core_type {
    HW_VC8000D = 0,
    HW_VC8000DJ,
    HW_BIGOCEAN,
    HW_VCMD,
    HW_MMU,
    HW_DEC400,
    HW_L2CACHE,
    HW_SHAPER,
    HW_NOC,
    HW_AXIFE,
    HW_DC8000,
    HW_CORE_MAX    /* max number of cores supported */
}
viv_core_type;

typedef enum _viv_file_type {
    vivFILE_BINARY = 0x001,

    vivFILE_READ   = 0x010,
    vivFILE_WRITE  = 0x100,

    vivFILE_READB  = vivFILE_READ  | vivFILE_BINARY,
    vivFILE_WRITEB = vivFILE_WRITE | vivFILE_BINARY,
}
viv_file_type;

typedef enum _viv_test_type {
    vivTEST_NORMAL          = 0x0,
    vivTEST_MULTIFRAME      = 0x1,
    vivTEST_VIDEOSTRESS     = 0x2,
    vivTEST_OVERLAYSTRESS   = 0x3,
}
viv_test_type;

typedef enum _viv_mmu_mode {
    vivMMU_1KMODE_4KPAGE,
    vivMMU_1KMODE_64KPAGE,
    vivMMU_1KMODE_1MPAGE,
    vivMMU_1KMODE_16MPAGE,
    vivMMU_4KMODE_4KPAGE,
    vivMMU_4KMODE_64KPAGE
}
viv_mmu_mode;

typedef struct _viv_interface_query_chip_identity * viv_interface_query_chip_identity_ptr;
typedef struct _viv_interface_query_chip_identity {
    /* Chip model. */
    dcCHIPMODEL chipModel;
    /* Revision value.*/
    gctUINT32 chipRevision;
    /* Revision value.*/
    gctUINT32 chipPatchRevision;
    /* Chip date. */
    gctUINT32 chipInfo;
    /* Product ID */
    gctUINT32 productID;
    /* ECO ID. */
    gctUINT32 ecoID;
    /* Customer ID. */
    gctUINT32 customerID;
    /* Product Data */
    gctUINT32 productDate;
    /* Product time */
    gctUINT32 productTime;

}
viv_interface_query_chip_identity;

typedef enum _vivFLATMAP_FLAG
{
    vivFLATMAP_DIRECT,
    vivFLATMAP_SHIFT,
}
vivFLATMAP_FLAG;

typedef struct _vivFLAT_MAPPING_RANGE
{
    gctADDRESS start;
    gctADDRESS end;
    gctUINT32 size;
    vivFLATMAP_FLAG flag;
}
vivFLAT_MAPPING_RANGE;

#if ALLOC_RESERVED_MEM_IN_KERNEL

#define MEM_NODE_NUM      32
#define MEM_NODE_LIST_NUM 4
#define RESERVED_MEM_TYPE 1

#define MAX_NODE_NUM_BIT_MASK ((0xFFFFFFFFU << (32 - MEM_NODE_NUM)) >> (32 - MEM_NODE_NUM))

typedef struct _viv_mem_node
{
    /* Size of the memory node (in bytes)*/
    gctUINT32 size;

    /* Offset in the reserved memory area (in bytes) */
    gctADDRESS offset;

    /* User pointer address of the memory node */
    gctPOINTER user_logical;

    /* Physical address of the memory node */
    gctADDRESS physical;

    /* Kernel pointer address of the memory node */
    gctPOINTER kernel_logical;

    /* Index(num) of the memory node */
    gctUINT32 handle;

    struct _viv_mem_node * next;
    struct _viv_mem_node * prev;
    struct _viv_mem_node * next_free;
    struct _viv_mem_node * prev_free;

}
viv_mem_node;


/* struct _vivMEM_NODE_LIST will store the address of the mem_node(vivMEM_NODE)
   as array. Num of the nodes is MEM_NODE_NUM in one _vivMEM_NODE_LIST;
 */

typedef struct _viv_mem_node_list
{
    gctUINT32 bitmap;

    viv_mem_node* mem_node[MEM_NODE_NUM];
}
viv_mem_node_list;


typedef struct _viv_mem_node_list_table
{
    gctUINT32 locked_list_length;

    gctUINT32 total_size;
    gctUINT32 free_size;
    gctADDRESS physical_base;

    viv_mem_node_list *locked_node_lists;

    viv_mem_node sentinal[RESERVED_MEM_TYPE];

    gctPOINTER resmem_mutex;
}
viv_mem_node_list_table;


#endif

/* For function enable/disable parameter */
#define SET_ENABLE                                  1
#define SET_DISABLE                                 0

/* For polarity parameter */
#define SET_POSITIVE                                1
#define SET_NEGATIVE                                0


#define vivMAX(a, b) ((a) > (b) ? (a) : (b))
#define vivMIN(a, b) ((a) < (b) ? (a) : (b))

#define vivPOW     pow
#define vivABS     abs
#define vivATOI    atoi
#define vivSIZEOF  sizeof

#define vivINFINITE ((gctUINT32)(~0U))

#define vivINVALID_PHYSICAL_ADDRESS ~0ULL
#define vivINVALID_ADDRESS ~0U

#define dcONERROR(func) \
    do \
    { \
        status = func; \
        if (status < 0) \
        { \
            goto OnError; \
        } \
    } \
    while (0)

#endif

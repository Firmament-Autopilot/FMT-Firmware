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


#ifndef _VIV_DC_UTIL_H_
#define _VIV_DC_UTIL_H_

#include "viv_dc_type.h"
#include "viv_dc_options.h"
#include "viv_dc_core.h"

#define gcd2D_COMPRESSION_DEC400_ALIGN_MODE_32_BYTES 32
typedef enum _vivCOMPRESSION_DEC400_ALIGN_MODE
{
    vivCOMPRESSION_DEC400_16_BYTES_ALIGNED = 0,
    vivCOMPRESSION_DEC400_32_BYTES_ALIGNED,
    vivCOMPRESSION_DEC400_64_BYTES_ALIGNED,
} vivCOMPRESSION_DEC400_ALIGN_MODE;

typedef gctUINT   gctUINT;
typedef gctINT    gctBOOL;
typedef gctINT    gctINT;
typedef gctPOINTER gctPOINTER;
typedef gctUINT   gceSURF_FORMAT;

#define gcvFALSE 0
#define gcvTRUE  1

#define gcdPI                   3.14159265358979323846f

#define gcoMATH_Sine(X)       (gctFLOAT)(sinf((X)))

#define vivMATH_Add(X, Y)          (gctFLOAT)((X) + (Y))
#define vivMATH_Multiply(X, Y)     (gctFLOAT)((X) * (Y))
#define vivMATH_Divide(X, Y)       (gctFLOAT)((X) / (Y))
#define vivMATH_DivideFromUInteger(X, Y) (gctFLOAT)(X) / (gctFLOAT)(Y)

#define vivMATH_Int2Float(X)   (gctFLOAT)(X)

#define MEM_THRESHOLD    0x384000 /* 1280*720*4 */ //IFX - Fix Warning comparision with integer max will result always true.
/********************************* BMP header ******************************/
#define BF_TYPE 0x4D42             /* "MB" */

#pragma pack(1)
/**** BMP file header structure ****/
typedef struct BMPFILEHEADER {
    unsigned short bfType;           /* Magic number for file */
    unsigned int   bfSize;           /* Size of file */
    unsigned short bfReserved1;      /* Reserved */
    unsigned short bfReserved2;      /* ... */
    unsigned int   bfOffBits;        /* Offset to bitmap data */
} BMPFILEHEADER;

/**** BMP file info structure ****/
typedef struct BMPINFOHEADER {
    unsigned int   biSize;           /* Size of info header */
    int            biWidth;          /* Width of image */
    int            biHeight;         /* Height of image */
    unsigned short biPlanes;         /* Number of color planes */
    unsigned short biBitCount;       /* Number of bits per pixel */
    unsigned int   biCompression;    /* Type of compression to use */
    unsigned int   biSizeImage;      /* Size of image data */
    int            biXPelsPerMeter;  /* X pixels per meter */
    int            biYPelsPerMeter;  /* Y pixels per meter */
    unsigned int   biClrUsed;        /* Number of colors used */
    unsigned int   biClrImportant;   /* Number of important colors */
} BMPINFOHEADER;

/*
 * Constants for the biCompression field...
 */

#define BIT_RGB       0             /* No compression - straight BGR data */
#define BIT_RLE8      1             /* 8-bit run-length compression */
#define BIT_RLE4      2             /* 4-bit run-length compression */
#define BIT_BITFIELDS 3             /* RGB bitmap with RGB masks */

/**** Colormap entry structure ****/
typedef struct RGB {
    unsigned char   rgbBlue;          /* Blue value */
    unsigned char   rgbGreen;         /* Green value */
    unsigned char   rgbRed;           /* Red value */
    unsigned char   rgbReserved;      /* Reserved */
} RGB;

/**** Bitmap information structure ****/
typedef struct _BMPINFO {
    BMPINFOHEADER   bmiHeader;      /* Image header */
    union {
    RGB             bmiColors[256]; /* Image colormap */
    gctUINT         mask[3];        /* RGB masks */
    };
} BMPINFO;
#pragma pack()

typedef struct _Degamma
{
    gctUINT16 degamma_table[DEGAMMA_TABLE_SIZE][3];
}
Degamma;

typedef struct _Gamma
{
    gctUINT16 gamma_table[GAMMA_TABLE_SIZE][3];
}
Gamma;

typedef struct _Layer
{
    /* layer id */
    gctUINT layer_id;

    /* security */
    gctBOOL layer_sec;

    /* layer enable */
    gctBOOL enable;

    /* Source. */
    gctUINT8 resource[100];

#if vivENABLE_LAYER_DECOMPRESS
    gctUINT8 tile_status_file[3][100];
#endif

    /* buffer */
    viv_dc_buffer buffer;
    char format_string[20];
    char tiling_string[40];
    gctUINT32 plane_num;
    gctUINT32 bpp[3];
    gctUINT aligned_width[3];
    gctUINT aligned_height[3];
    gctUINT32 fb_size;
    gctPOINTER handle;
    gctPOINTER logical;
    gctADDRESS hardwareAddress;

    /* clear */
    viv_dc_color clear_color;
    gctBOOL      clear_color_enable;

    /* roi */
    gctBOOL      roi_enable;
    viv_dc_rect  roi_rect;

    /* position */
    gctUINT32 br_x;
    gctUINT32 br_y;
    viv_dc_rect display_rect;

    /* colorkey */
    viv_dc_color colorkey;
    viv_dc_color colorkey_high;
    gctBOOL transparency;

#if vivENABLE_LAYER_DEGAMMA
    /* degamma */
    gctBOOL         degamma_enable;
    viv_dc_degamma  degamma_table;
#endif

#if vivENABLE_LAYER_ROT
    /* rotation */
    char rot_string[30];
#endif
    viv_rotation_type rot;

#if vivENABLE_LAYER_SCALE
    /* scale */
    char filter_tap_string[20];
#endif
    viv_filter_tap_type filter_tap;
    gctBOOL scale_enable;

    /* decompress */
    viv_tilestatus_buffer tilestatus_buffer;
    gctBOOL decompress_enable;
    viv_cache_mode cache_mode;

    /* alpha blend */
    viv_layer_alpha_mode alpha;
    gctBOOL alpha_blend_enable;
    viv_porter_duff_mode blend_mode;
    char blend_mode_string[20];
    char src_global_alpha_mode_string[20];
    char src_alpha_mode_string[20];
    char dst_global_alpha_mode_string[20];
    char dst_alpha_mode_string[20];

    /* watermark */
    gctUINT32 watermark_value;

    /* display */
    viv_display display_id;

    /* zorder */
    gctUINT8 zorder;

#if vivENABLE_DISPLAY_3DLUT
    /* threed_lut */
    gctBOOL lut_enable;
    gctUINT32 lut;
    viv_lut_enlarge enlarge;
#endif

    /* qos */
    gctUINT32 qos_low;
    gctUINT32 qos_high;
}
Layer;

typedef struct _Cursor
{
    gctBOOL enable;
    gctBOOL security;

    viv_display display_id;
    char format_string[20];
    char size_type_string[20];
    viv_cursor cursor;

    /* buffer */
    viv_dc_buffer cursor_buffer;
}
Cursor;

/* Alignment with a power of two value. */
#define gcmALIGN(n, align) \
( \
    ((n) + ((align) - 1)) & ~((align) - 1) \
)

/* FilterBlt information. */
#define gcvMAXKERNELSIZE        9
#define gcvSUBPIXELINDEXBITS    5

#define gcvSUBPIXELCOUNT \
    (1 << gcvSUBPIXELINDEXBITS)

#define gcvSUBPIXELLOADCOUNT \
    (gcvSUBPIXELCOUNT / 2 + 1)

#define gcvWEIGHTSTATECOUNT \
    (((gcvSUBPIXELLOADCOUNT * gcvMAXKERNELSIZE + 1) & ~1) / 2)

#define gcvKERNELTABLESIZE \
    (gcvSUBPIXELLOADCOUNT * gcvMAXKERNELSIZE * sizeof(gctUINT16))

#define gcvKERNELSTATES \
    (gcmALIGN(gcvKERNELTABLESIZE + 4, 8))

/* Filter types. */
typedef enum _vivFILTER_TYPE
{
    vivFILTER_SYNC = 0,
    vivFILTER_BLUR,
    vivFILTER_USER
}
vivFILTER_TYPE;

typedef struct _gcsFILTER_BLIT_ARRAY
{
    gctUINT8      kernelSize;
    gctUINT32     scaleFactor;
    gctUINT32_PTR kernelStates;
}
gcsFILTER_BLIT_ARRAY;

typedef gcsFILTER_BLIT_ARRAY * gcsFILTER_BLIT_ARRAY_PTR;

/******************************/
/*      General Function      */
/******************************/

gctINT viv_util_get_channel(
    gctUINT32 format,
    gctUINT16* a,
    gctUINT16* r,
    gctUINT16* g,
    gctUINT16* b
    );

gctUINT8* viv_util_output_string(
    gctUINT32 output
    );

gctINT viv_util_free_hwcursor(
    Cursor *cursor
    );

gctINT viv_util_prepare_cursor_config(
    Cursor* cursor
    );

gctVOID viv_util_prepare_gamma_config(
    Gamma* gamma
    );

gctFLOAT viv_util_dc_to_gamma(
    gctFLOAT  x
    );

#if vivENABLE_DISPLAY_NEWGMMA
gctVOID viv_util_prepare_new_gamma(
    Gamma* new_gamma
    );
#endif

#if vivENABLE_LAYER_DEGAMMA
gctFLOAT viv_util_dc_to_degamma(
    gctFLOAT  x
    );

gctVOID viv_util_prepare_degamma(
    Degamma*  de_gamma,
    gctBOOL   BT709
    );
#endif

#if vivENABLE_DISPLAY_3DLUT
vivSTATUS viv_util_prepare_threed_lut(
    gctUINT32* threed_lut
    );
#endif

gctINT viv_util_load_bmp_subarea(
    gctUINT8* file_name,
    gctUINT8* buf,
    gctUINT32 buf_width,
    gctUINT32 buf_height,
    gctUINT32 buf_stride,
    gctUINT8 *lut,
    gctUINT32 *ret_width,
    gctUINT32 *ret_height
    );

gctINT viv_util_load_raw_area(
    gctUINT8** plane_addr,
    gctUINT32*  plane_stride,
    gctUINT32*  align_height,
    gctUINT32*  align_width,
    gctUINT32*  bpps,
    gctUINT32   format,
    gctUINT32   plane_num,
    gctUINT8*   filename
    );

gctINT viv_source_capture_dump(
    gctPOINTER logical,
    gctUINT32  size,
    gctADDRESS  phys_addr,
    gctBOOL    video,
    gctBOOL    final_plane
    );

vivSTATUS viv_cursor_clear(
    Cursor* cursor,
    gctUINT32 color
    );

vivSTATUS viv_util_free_layer_buffer(
    Layer *layer
    );

gctINT viv_util_load_bmp_area(
    gctUINT8* file_name,
    gctUINT8* buf,
    gctUINT32 buf_width,
    gctUINT32 buf_height,
    gctUINT32 buf_stride,
    gctUINT32 format,
    gctUINT32 tile_mode,
    gctUINT32 compression,
    gctUINT *lut,
    gctUINT32 *ret_buf_width,
    gctUINT32 *ret_buf_height,
    gctUINT32 *ret_img_width,
    gctUINT32 *ret_img_height
    );

gctINT viv_util_load_raw(
    gctUINT8* Buffer,
    gctUINT32 Size,
    gctUINT8* filename
    );

gctBOOL GalSaveDIB(
    gctPOINTER bits,
    gceSURF_FORMAT  format,
    gctUINT stride,
    gctUINT width,
    gctUINT height,
    const char *bmpFileName);

vivSTATUS viv_util_prepare_layer_config(
    Layer *layer,
    gctUINT id,
    gctADDRESS physical
    );

#if vivENABLE_WRITEBACK
vivSTATUS viv_util_prepare_wb_config(
    viv_dc_buffer *buffer,
    viv_display_type type,
    gctUINT *buffer_size,
    gctUINT width,
    gctUINT height
    );
#endif
#if 0 //Unused API - Resolve compiler warning
gctINT viv_util_load_vimg(
    gctUINT8 *file,
    viv_input_format_type format,
    gctUINT32 tile_mode,
    gctUINT32 compression,
    gctUINT8 **plane_addr,
    gctUINT32 *plane_width,
    gctUINT32 *plane_height,
    gctUINT32 *plane_stride,
    gctUINT32 plane_num,
    gctUINT8 **ts_buf,
    gctUINT32 *ret_buf_width,
    gctUINT32 *ret_buf_height,
    gctUINT32 *ret_img_width,
    gctUINT32 *ret_img_height
    );
#endif
#define viv_print   viv_os_print
#define viv_sprint  viv_os_sprint

#endif

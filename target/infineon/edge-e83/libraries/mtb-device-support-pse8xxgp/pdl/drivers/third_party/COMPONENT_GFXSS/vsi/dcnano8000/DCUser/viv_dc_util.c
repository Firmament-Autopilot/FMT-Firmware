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


#include "viv_dc_setting.h"
#include "viv_dc_tools.h"
#include "errno.h"

#include "math.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef RTOS
#include "viv_dc_os.h"
#else
#include "viv_dc_platform.h"
#endif

#define CHANNLE_TABLE_NUM 4
#define BPP_TABLE_NUM 6

static gctPOINTER g_back_addr = vivNULL;
static gctUINT32 g_back_size = 0;
static gctBOOL Features[vivFEATURE_COUNT];

static gctPOINTER *fp_src = vivNULL;

gctUINT32 GalLoadVimgToTSurfWithPool(
    gctUINT8 * Filename,
    gctUINT8 * Buffer, gctUINT8* TileStatus[],
    gctUINT32 Size
    );

typedef struct
{
    gctUINT8 magic[3]; /*"VIV"*/
    gctUINT8 version;
} VIMG_FILEHEADER;

typedef struct
{
    gctUINT32 format; /* gceSURF_FORMAT */
    gctUINT32 tiling;
    gctUINT32 imageStride;
    gctUINT32 imageWidth;
    gctUINT32 imageHeight;
    gctUINT32 bitsOffset;
} VIMG_V1;

/* Image with FC tile status. */
typedef struct
{
    VIMG_V1      v1;
    gctUINT32 tileStatusConfig;
    gctUINT32 tileStatusSize;
    gctUINT32 compressedFormat;
    gctUINT32 clearValue;
    gctUINT32 tileStatusOffset;
    gctUINT32 tileStatusOffsetEx[2];
    gctUINT32 tileStatusSizeEx[2];
} VIMG_V2;

static gctUINT16 ChannelTable[CHANNLE_TABLE_NUM][4] =
{
    {1, 5, 5, 5}, /* RGB555 */
    {4, 4, 4, 4}, /* RGB444 */
    {0, 5, 6, 5}, /* RGB565 */
    {8, 8, 8, 8}, /* ARGB8888 */
};

/* Get bit width of each channel.
 * Format supports vivARGB1555/vivARGB4444/vivRGB565/vivARGB8888.
 */
gctINT viv_util_get_channel(
    gctUINT32 format,
    gctUINT16* a,
    gctUINT16* r,
    gctUINT16* g,
    gctUINT16* b
    )
{
    if (format >= CHANNLE_TABLE_NUM)
        return vivSTATUS_INVALID_ARGUMENTS;

    if (a != vivNULL)
        *a = ChannelTable[format][0];

    if (r != vivNULL)
        *r = ChannelTable[format][1];

    if (g != vivNULL)
        *g = ChannelTable[format][2];

    if (b != vivNULL)
        *b = ChannelTable[format][3];

    return vivSTATUS_OK;
}

/* Get bpp of format.
 * Format supports vivARGB1555/vivARGB4444/vivRGB565/vivARGB8888/vivNV12/vivYUY2.
 */
gctINT viv_util_get_bpp(
    viv_input_format_type Format,
    gctUINT16* l1,
    gctUINT16* l2,
    gctUINT16* l3
    )
{
    switch (Format)
    {
    case vivNV12:
    case vivNV16:
    case vivNV21:
        /* 8-bit colors. */
        *l1 = 8;
        break;

    case vivARGB4444:
    case vivABGR4444:
    case vivRGBA4444:
    case vivBGRA4444:
    case vivXRGB4444:
    case vivXBGR4444:
    case vivRGBX4444:
    case vivBGRX4444:
    case vivARGB1555:
    case vivABGR1555:
    case vivRGBA1555:
    case vivBGRA1555:
    case vivXRGB1555:
    case vivXBGR1555:
    case vivRGBX1555:
    case vivBGRX1555:
    case vivRGB565:
    case vivBGR565:
    case vivUYVY:
    case vivYUY2:
    case vivYV12:
    case vivYU12:
        /* 16-bit colors. */
        *l1 = 16;
        break;
    default:
        /* Default to 32-bit colors. */
        *l1 = 32;
        break;
    }

    return vivSTATUS_OK;
}

static vivSTATUS
viv_util_get_plane_bpp(
    viv_input_format_type format,
    gctUINT32 *plane_num,
    gctUINT32 *bits_per_pixel
    )
{
    vivSTATUS status = vivSTATUS_OK;
    gctUINT32 num, bpp[3];
    gctUINT32 i;

    if (!plane_num && !bits_per_pixel)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    switch (format)
    {
    case vivARGB4444:
    case vivABGR4444:
    case vivRGBA4444:
    case vivBGRA4444:
    case vivXRGB4444:
    case vivXBGR4444:
    case vivRGBX4444:
    case vivBGRX4444:
    case vivARGB1555:
    case vivABGR1555:
    case vivRGBA1555:
    case vivBGRA1555:
    case vivXRGB1555:
    case vivXBGR1555:
    case vivRGBX1555:
    case vivBGRX1555:
    case vivRGB565:
    case vivBGR565:
    case vivUYVY:
    case vivYUY2:
        num = 1;
        bpp[0] = 16;
        break;

    case vivNV12:
    case vivNV21:
    case vivNV16:
        num = 2;
        bpp[0] = 8;
        bpp[1] = 16;
        break;

    case vivP010:
        num = 2;
        bpp[0] = 16;
        bpp[1] = 32;
        break;

    case vivYV12:
    case vivYU12:
        num = 3;
        bpp[0] = 8;
        bpp[1] = 8;
        bpp[2] = 8;
        break;

    case vivNV12_10BIT:
        num = 2;
        bpp[0] = 10;
        bpp[1] = 20;
        break;

    case vivYUV444:
        num = 3;
        bpp[0] =
        bpp[1] =
        bpp[2] = 8;
        break;

    case vivYUV444_10BIT:
        num = 3;
        bpp[0] =
        bpp[1] =
        bpp[2] = 10;
        break;


    default:
        num = 1;
        bpp[0] = 32;
        break;
    }

    if (plane_num)
    {
        *plane_num = num;
    }

    if (bits_per_pixel)
    {
        for (i = 0; i < num; i++)
        {
            bits_per_pixel[i] = bpp[i];
        }
    }

    return status;
}

gctBOOL viv_util_is_yuv(
    viv_input_format_type format
    )
{
    switch (format)
    {
    case vivUYVY:
    case vivYUY2:
    case vivYV12:
    case vivYU12:
    case vivP010:
    case vivNV12:
    case vivNV21:
    case vivNV16:
        return vivTRUE;
        break;
    default:
        return vivFALSE;
    }

    //return vivFALSE; //IFX: Fix IAR Warning. Code not reachable.
}

/* Return the string name of format.
 */
gctUINT8* viv_util_format_string(
    viv_input_format_type format
    )
{
    switch (format)
    {
        case vivARGB1555:
            return (gctUINT8*)"RGB1555";

        case vivARGB4444:
            return (gctUINT8*)"RGB444";

        case vivRGB565:
            return (gctUINT8*)"RGB565";

        case vivARGB8888:
            return (gctUINT8*)"RGB888";

        case vivNV12:
            return (gctUINT8*)"NV12";

        case vivYUY2:
            return (gctUINT8*)"YUY2";
        default:
            return vivNULL;
    }

    //return vivNULL; //IFX: Fix IAR Warning. Code not reachable.
}

/* Return the string name of output.
 */
gctUINT8* viv_util_output_string(
    gctUINT32 output
    )
{
    switch (output)
    {
        case vivDPI:
            return (gctUINT8*)"DPI";
    }

    return vivNULL;
}

#define UP_ALIGN(x, alignment) ( (x + alignment - 1) & ~(alignment - 1) )

gctINT alignSize(
    viv_input_format_type Format,
    gctUINT TileMode,
    gctUINT Compressed,
    viv_cache_mode CacheMode,
    gctUINT *Width,
    gctUINT *Height
    )
{
    switch (TileMode)
    {
        case vivTILED4X4:
            switch (Format)
            {
                case vivYUV444:
                case vivYUV444_10BIT:
                    *Width = UP_ALIGN(*Width, 32);
                    *Height = UP_ALIGN(*Height, 4);
                    break;
                case vivNV12:
                    if (Features[vivFEATURE_CUSTOMER_TILE4X4])
                    {
                        *Width = UP_ALIGN(*Width, 8);
                        *Height = UP_ALIGN(*Height, 8);
                    }
                    else
                    {
                        *Width = UP_ALIGN(*Width, 64);
                        *Height = UP_ALIGN(*Height, 4);
                    }
                    break;
                case vivNV12_10BIT:
                    *Width = UP_ALIGN(*Width, 64);
                    *Height = UP_ALIGN(*Height, 4);
                    break;
                case vivARGB8888:
                    *Width = UP_ALIGN(*Width, 4);
                    *Height = UP_ALIGN(*Height, 4);
                    break;
                case vivYUY2:
                    *Width = UP_ALIGN(*Width, 4);
                    *Height = UP_ALIGN(*Height, 4);
                    break;
                default:
                    viv_os_print("current format is not supported\n");
                    return vivSTATUS_NOT_SUPPORT;
                    break;
            }
            break;
        case vivTILED8X8:
            *Width  = UP_ALIGN(*Width, 16);
            *Height = UP_ALIGN(*Height, 8);
            break;
        case vivSUPER_TILED_X:
        case vivSUPER_TILED_Y:
            *Width  = UP_ALIGN(*Width, 64);
            *Height = UP_ALIGN(*Height, 64);
            break;
        case vivLINEAR:
            if (Compressed)
            {
                switch (Format)
                {
                    case vivARGB8888:
                    case vivXRGB8888:
                    case vivARGB2101010:
                        if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 64);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 32);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    case vivRGB565:
                    case vivARGB1555:
                    case vivXRGB1555:
                    case vivARGB4444:
                    case vivXRGB4444:
                        if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 128);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 64);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    case vivYUY2:
                    case vivUYVY:
                        if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 128);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 64);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    case vivNV12:
                    case vivNV21:
                        if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 128);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 256);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    case vivP010:
                        if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 64);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 128);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    case vivNV16:
                        if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 128);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 256);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    case vivYV12:
                    case vivYU12:
                        if (CacheMode == vivCACHE_128)
                        {
                            *Width = UP_ALIGN(*Width, 128);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        else if (CacheMode == vivCACHE_256)
                        {
                            *Width = UP_ALIGN(*Width, 512);
                            *Height = UP_ALIGN(*Height, 1);
                        }
                        break;
                    default:
                        viv_os_print("current format is not supported\n");
                        return vivSTATUS_NOT_SUPPORT;
                        break;
                }
            }
            break;
        default:
            break;
    }

    return 0;
}

gctINT calculateBufferSize(
    viv_input_format_type format,
    gctUINT imageWidth,
    gctUINT imageHeight,
    gctUINT *nPlane,
    gctUINT *width,
    gctUINT *height,
    gctUINT *bpp
    )
{
    gctINT i;
    gctUINT16 l1, l2, l3;

    for (i = 0; i < 3; i++)
    {
        width[i] = 0;
        height[i] = 0;
        bpp[i] = 0;
    }

    /* Check the type. */
    switch (format)
    {
    case vivYUY2:
        *nPlane = 1;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 16;
        break;

    case vivUYVY:
        *nPlane = 1;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 2 * 8;
        break;

    case vivYV12:
    case vivYU12:
        *nPlane = 3;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 1 * 8;
        width[1] = width[2] = imageWidth / 2;
        height[1] = height[2] = imageHeight / 2;
        bpp[1] = bpp[2] = 1 * 8;
        break;

    case vivNV16:
        *nPlane = 2;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 1 * 8;
        width[1] = imageWidth / 2;
        height[1] = imageHeight;
        bpp[1] = 2 * 8;
        break;

    case vivNV12:
    case vivNV21:
        *nPlane = 2;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 1 * 8;
        width[1] = imageWidth / 2;
        height[1] = imageHeight / 2;
        bpp[1] = 2 * 8;
        break;

    case vivNV12_10BIT:
        *nPlane = 2;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 1 * 10;
        width[1] = imageWidth / 2;
        height[1] = imageHeight / 2;
        bpp[1] = 2 * 10;
        break;

    case vivP010:
        *nPlane = 2;
        width[0] = imageWidth;
        height[0] = imageHeight;
        bpp[0] = 16;
        width[1] = imageWidth / 2;
        height[1] = imageHeight / 2;
        bpp[1] = 32;
        break;

    case vivYUV444:
        *nPlane = 3;
        width[0]  = width[1]  = width[2]  = imageWidth;
        height[0] = height[1] = height[2] = imageHeight;
        bpp[0] = bpp[1] = bpp[2] = 8;
        break;

    case vivYUV444_10BIT:
        *nPlane = 3;
        width[0]  = width[1]  = width[2]  = imageWidth;
        height[0] = height[1] = height[2] = imageHeight;
        bpp[0] = bpp[1] = bpp[2] = 10;
        break;

    default:
        width[0] = imageWidth;
        height[0] = imageHeight;

        /* Other format. */
        viv_util_get_bpp(format, &l1, &l2, &l3);

        bpp[0] = l1;
        *nPlane = 1;
        break;
    }

    return 0;
}

#if vivENABLE_WRITEBACK
vivSTATUS viv_util_prepare_wb_config(
    viv_dc_buffer *buffer,
    viv_display_type type,
    gctUINT *buffer_size,
    gctUINT width,
    gctUINT height
    )
{
    gctUINT i = 0;
    vivSTATUS ret = vivSTATUS_OK;
    gctUINT size = 0;
    gctUINT dest_nplane = 0;
    gctUINT dest_bpps[3] = {0};
    gctUINT dest_width[3] = {0};
    gctUINT dest_height[3] = {0};
    gctUINT dest_delta = 0;

    if(!Features[vivFEATURE_PROGRAM_WB])
    {
        if(type == vivDP)
        {
            size = width * height * 8; /* For DP output, HW use 64bits/pixel write back */
            buffer->stride[0] = width * 8;
        }
        else
        {
           size = width * height * 4;
           buffer->stride[0] = width * 4;
        }
    }
    else
    {
        calculateBufferSize(
            buffer->format,
            width,
            height,
            &dest_nplane,
            dest_width,
            dest_height,
            dest_bpps
            );

        for (i = 0; i < dest_nplane; i++)
        {
            buffer->stride[i] = dest_width[i] * dest_bpps[i] / 8;
            size += buffer->stride[i] * dest_height[i];
        }

    }
        /* Allocate dest buffer. */
#if defined(RTOS)
    viv_alloc_buffer(
        size,
        &buffer->handle[0],
        (gctADDRESS *)&buffer->phyAddress[0],
        &buffer->logical[0],
        (gctBOOL)vivFALSE,
        gcvPOOL_CONTIGUOUS);
#else
#if vivENABLE_MMU
    if (Features[vivFEATURE_MMU])
    {
        viv_alloc_buffer(
            size,
            &buffer->handle[0],
            &buffer->phyAddress[0],
            &buffer->logical[0],
            (gctBOOL)vivFALSE,
            gcvPOOL_DEFAULT);
    }
    else
#endif
    if (size <= MEM_THRESHOLD)
    {
        viv_alloc_buffer(
            size,
            &buffer->handle[0],
            &buffer->phyAddress[0],
            &buffer->logical[0],
            (gctBOOL)vivFALSE,
            gcvPOOL_CONTIGUOUS);
    }
    else
    {
        /* Solution for large mem alloc*/
        ret = viv_os_get_dev_mem(
                size,
                &(buffer->phyAddress[0]),
                &buffer->logical[0]);
        if (ret)
            return ret;
    }
#endif

    if(Features[vivFEATURE_PROGRAM_WB])
    {
        for(i = 1; i < dest_nplane; i++)
        {
            dest_delta = buffer->stride[i-1] * dest_height[i-1];
            buffer->logical[i] = (gctUINT8 *)buffer->logical[i-1] + dest_delta;
            buffer->phyAddress[i] = buffer->phyAddress[i-1] + dest_delta;
        }
    }

    viv_os_memset(vivNULL, buffer->logical[0], 0, size);

    if(!!buffer_size)
    {
        *buffer_size = size;
    }

    return ret;
}
#endif

/* Prepare layer config value. */
vivSTATUS viv_util_prepare_layer_config(
    Layer *layer,
    gctUINT id,
    gctADDRESS physical
    )
{
    gctUINT16 y, uv;
    gctUINT32 srcWidth, srcHeight;
    gctUINT32 width[3], height[3];
    gctUINT32 bpps[3];
    gctUINT32 nPlane;
    gctUINT i = 0, layerCount = 0;
    gctUINT32 addressAlign = 1;
    gctADDRESS delta = 0;
#if vivENABLE_LAYER_DECOMPRESS
    gctADDRESS tsHwAddress[3] = {0, 0, 0};
    gctPOINTER tsLogical[3] = {NULL, NULL, NULL};
#endif
    vivSTATUS ret = vivSTATUS_OK;
    gctUINT layerRotateCap = 0, layerTileCap = 0, layerROICap = 0;
    gctUINT layerDecompressCap = 0, layerScaleCap = 0;

    /* Fill chip feature bit values to Features. */
    viv_query_chipinfo(Features);
    ret = viv_dc_query_feature(vivFEATURE_LAYER_COUNT, &layerCount);
    if(vivSTATUS_OK != ret)
       return ret;

    if (!layerCount)
    {
        viv_print("layer feature is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    if(viv_layer_query_capability(id, vivLAYER_CAP_DEC400_COMPRESSION, &layerDecompressCap)||
       viv_layer_query_capability(id, vivLAYER_CAP_ROTATION, &layerRotateCap)||
       viv_layer_query_capability(id, vivLAYER_CAP_SCALE, &layerScaleCap)||
       viv_layer_query_capability(id, vivLAYER_CAP_TILED, &layerTileCap)||
       viv_layer_query_capability(id, vivLAYER_CAP_ROI, &layerROICap))
    {
       viv_print("layer feature is not supported.\n");
       return vivSTATUS_NOT_SUPPORT;
    }

#if vivENABLE_LAYER_ROT
    if ((!layerRotateCap) && (layer->rot != vivROTANGLE_0))
    {
        viv_print("Ratation is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }
#endif

    if ((!layerTileCap) && (layer->buffer.tiling != vivLINEAR))
    {
        viv_print("Tiled format is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

#if vivENABLE_LAYER_DECOMPRESS
    if ((!layerDecompressCap) && (layer->decompress_enable == 1))
    {
        viv_print("Decompressed is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }
#endif

#if vivENABLE_LAYER_SCALE
    if ((!layerScaleCap) && (layer->scale_enable == 1))
    {
        viv_print("Scale is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }
#endif

#if vivENABLE_LAYER_ROI
    if ((!layerROICap) && (layer->roi_enable == 1))
    {
        viv_print("Roi is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }
#endif

    /* Get bpp of format. */
    if (viv_util_get_bpp(layer->buffer.format, &y, &uv, vivNULL) != vivSTATUS_OK)
    {
        viv_print("Layer format %d is not support\n", layer->buffer.format);
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    /* Get buffer size. */
    if ((layer->rot == vivROTANGLE_0) && (layer->scale_enable == 0) && (!layer->roi_enable))
    {
        /* Input size is same as output size. */
        layer->buffer.width = layer->display_rect.w;
        layer->buffer.height = layer->display_rect.h;
    }

    srcWidth = layer->buffer.width;
    srcHeight = layer->buffer.height;

    alignSize(layer->buffer.format,
        layer->buffer.tiling,
        layer->decompress_enable,
        layer->cache_mode,
        &srcWidth,
        &srcHeight);

    /* Get implied information. */
    calculateBufferSize(layer->buffer.format, srcWidth, srcHeight, &nPlane, width, height, bpps);
    layer->plane_num = nPlane;

    for (i = 0; i < nPlane; i++)
    {
        layer->bpp[i] = bpps[i];
        layer->aligned_width[i] = width[i];
        layer->aligned_height[i] = height[i];
        layer->buffer.stride[i] = width[i] * bpps[i] / 8;

        if (layer->buffer.tiling == vivLINEAR)
        {
            layer->buffer.stride[i] = gcmALIGN(layer->buffer.stride[i], 128);
        }

        layer->fb_size += gcmALIGN((layer->buffer.stride[i] * height[i]), addressAlign);
    }

    /* Allocate layer buffer */
    if (physical == 0xFFFFFFFF)
    {
#if defined(RTOS)
        viv_alloc_buffer(
            layer->fb_size + addressAlign,
            &layer->handle,
            &layer->hardwareAddress,
            &layer->logical,
            layer->layer_sec || layer->buffer.security,
            gcvPOOL_CONTIGUOUS);
#else
#if vivENABLE_MMU
        if (Features[vivFEATURE_MMU])
        {
            viv_alloc_buffer(
                layer->fb_size + addressAlign,
                &layer->handle,
                &layer->hardwareAddress,
                &layer->logical,
                layer->layer_sec || layer->buffer.security,
                gcvPOOL_DEFAULT);
        }
        else
#endif
        if ((layer->fb_size + addressAlign) <= MEM_THRESHOLD)
        {
            viv_alloc_buffer(
                layer->fb_size + addressAlign,
                &layer->handle,
                &layer->hardwareAddress,
                &layer->logical,
                layer->layer_sec || layer->buffer.security,
                gcvPOOL_CONTIGUOUS);
        }
        else
        {
            /* Solution for large mem alloc*/
            ret = viv_os_get_dev_mem(
                layer->fb_size + addressAlign,
                &layer->hardwareAddress,
                &layer->logical);

            if (ret != vivSTATUS_OK)
                return ret;
        }
#endif

        physical = gcmALIGN(layer->hardwareAddress, (gctADDRESS)addressAlign);
        delta = physical - layer->hardwareAddress;
    }

    layer->buffer.logical[0] = (gctUINT8 *)layer->logical + delta;
    layer->buffer.phyAddress[0] = physical;

    for (i = 1; i < nPlane; i++)
    {
        layer->buffer.phyAddress[i] = layer->buffer.phyAddress[i - 1] + gcmALIGN((layer->buffer.stride[i - 1] * height[i - 1]),addressAlign);
        delta = layer->buffer.phyAddress[i] - layer->buffer.phyAddress[i - 1];
        layer->buffer.logical[i] = (gctUINT8 *)layer->buffer.logical[i - 1] + delta;
    }

    /* Allocate tile status buffer */
#if vivENABLE_LAYER_DECOMPRESS
    if (layer->decompress_enable)
    {
        for (i = 0; i < nPlane; i++)
        {
#if defined(RTOS)
            viv_alloc_buffer(
                layer->fb_size / 128 + addressAlign,
                &(layer->tilestatus_buffer.tileStatusHandle[i]),
                &(tsHwAddress[i]),
                &(tsLogical[i]),
                layer->layer_sec || layer->buffer.security,
                gcvPOOL_CONTIGUOUS);
#else
#if vivENABLE_MMU
            if (Features[vivFEATURE_MMU])
            {
                viv_alloc_buffer(
                    layer->fb_size / 128 + addressAlign,
                    &(layer->tilestatus_buffer.tileStatusHandle[i]),
                    &(tsHwAddress[i]),
                    &(tsLogical[i]),
                    layer->layer_sec || layer->buffer.security,
                    gcvPOOL_DEFAULT);
            }
            else
#endif
            if ((layer->fb_size / 128 + addressAlign) <= MEM_THRESHOLD)
            {
                viv_alloc_buffer(
                    layer->fb_size / 128 + addressAlign,
                    &(layer->tilestatus_buffer.tileStatusHandle[i]),
                    &(tsHwAddress[i]),
                    &(tsLogical[i]),
                    layer->layer_sec || layer->buffer.security,
                    gcvPOOL_CONTIGUOUS);
            }
            else
            {
                /* Solution for large mem alloc*/
                ret = viv_os_get_dev_mem(
                        layer->fb_size / 128 + addressAlign,
                        &(tsHwAddress[i]),
                        &(tsLogical[i]));

                if (ret != vivSTATUS_OK)
                    return ret;
            }
#endif

            layer->tilestatus_buffer.tileStatusHWAddress[i] = (gctADDRESS)gcmALIGN(tsHwAddress[i], (gctADDRESS)addressAlign);
            delta = layer->tilestatus_buffer.tileStatusHWAddress[i] - (gctADDRESS)(tsHwAddress[i]);
            layer->tilestatus_buffer.tileStatusLogical[i] = (gctUINT8 *)tsLogical[i] + delta;
        }
    }
#endif

    return vivSTATUS_OK;
}

/* Free layer*/
vivSTATUS viv_util_free_layer_buffer(
    Layer *layer
    )
{
    if (!layer->handle)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    viv_free_buffer(layer->handle);

#if vivENABLE_LAYER_DECOMPRESS
    if (layer->tilestatus_buffer.tileStatusHandle[0])
    {
        viv_free_buffer(layer->tilestatus_buffer.tileStatusHandle[0]);

        if (layer->tilestatus_buffer.tileStatusHandle[1])
        {
            viv_free_buffer(layer->tilestatus_buffer.tileStatusHandle[1]);

            if (layer->tilestatus_buffer.tileStatusHandle[2])
            {
                viv_free_buffer(layer->tilestatus_buffer.tileStatusHandle[2]);
            }
        }
    }
#endif

    layer->handle = vivNULL;

    return vivSTATUS_OK;
}

gctINT viv_util_prepare_cursor_config(
    Cursor* cursor
    )
{
    gctUINT32 cursor_width = 0;
    gctUINT32 cursor_height = 0;
    gctUINT32 cursor_size = 0;
    gctUINT32 cursor_count = 0;
    vivSTATUS ret = vivSTATUS_OK;

    ret = viv_dc_query_feature(vivFEATURE_CURSOR_COUNT, &cursor_count);
    if(vivSTATUS_OK != ret)
        return ret;

    if ((!cursor_count) && (cursor->enable == 1))
    {
        viv_print("Cursor feature is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    switch(cursor->cursor.size)
    {
        case vivCURSOR_32x32:
            cursor_width = cursor_height = 32;
            break;

        case vivCURSOR_64x64:
            cursor_width = cursor_height = 64;
            break;

        default:
            viv_print("Invalid cursor size type.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (cursor->cursor.hsx > cursor_width || cursor->cursor.hsy > cursor_height)
    {
        viv_print("Cursor hot spot out of range.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    cursor_size = cursor_width * cursor_height * 4;

#if vivENABLE_MMU
    if (Features[vivFEATURE_MMU])
    {
        viv_alloc_buffer(
            cursor_size,
            &cursor->cursor_buffer.handle[0],
            &cursor->cursor_buffer.phyAddress[0],
            &cursor->cursor_buffer.logical[0],
            cursor->security || cursor->cursor_buffer.security,
            gcvPOOL_DEFAULT);
    }
    else
#endif
    {
        viv_alloc_buffer(
            cursor_size,
            &cursor->cursor_buffer.handle[0],
            &cursor->cursor_buffer.phyAddress[0],
            &cursor->cursor_buffer.logical[0],
            cursor->security || cursor->cursor_buffer.security,
            gcvPOOL_CONTIGUOUS);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_cursor_clear(
    Cursor* cursor,
    gctUINT32 color
    )
{
    gctUINT col = 0, row = 0, width = 0, height = 0;
    gctUINT32* addr = vivNULL;

    if (cursor->cursor_buffer.logical[0] == vivNULL)
        return vivSTATUS_INVALID_ARGUMENTS;

    if (cursor->cursor.format == vivCURSOR_ARGB)
    {
        switch(cursor->cursor.size)
        {
            case vivCURSOR_32x32:
                width = height = 32;
                break;
            case vivCURSOR_64x64:
                width = height = 64;
                break;
            default:
                viv_print("Not support size.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
        }
        /* Leave a hot spot. */
        for (row = 0; row < height; row++)
        {
            for (col = 0; col < width; col++)
            {
                addr = (gctUINT32*) cursor->cursor_buffer.logical[0] + row * width + col;

                if (col < cursor->cursor.hsx || row < cursor->cursor.hsy)
                {
                    *addr = 0xFF00FF00;
                }
                else
                {
                    *addr = color;
                }

            }
        }
    }
    else
    {
        viv_print("Not support format.\n");
        return vivSTATUS_INVALID_ARGUMENTS;
    }
    return vivSTATUS_OK;
}

/* Prepare gamma table config.
 */
gctVOID viv_util_prepare_gamma_config( /* @suppress("No return") */
    Gamma* gamma
    )
{
    gctINT i;
    gctFLOAT tmpf;
    gctUINT8 temp = 0;
    gctUINT32 ttt;

    for(i=0; i < GAMMA_TABLE_SIZE; i++)
    {
        tmpf = (i + 0.5f)/256.0f;
        tmpf = (gctFLOAT)(vivPOW((gctDOUBLE)tmpf, (gctDOUBLE)0.45));
        temp = (gctUINT8)(tmpf*256 - 0.5f);
        ttt = ((temp<<22) | (temp<<12) |(temp<<2));
        gamma->gamma_table[i][0] = (ttt >> 20) & 0x3FF;
        gamma->gamma_table[i][1] = (ttt >> 10) & 0x3FF;
        gamma->gamma_table[i][2] = ttt & 0x3FF;
    }
}

/* Prepare new gamma table config.
 */
gctFLOAT viv_util_dc_to_gamma(
    gctFLOAT  x
    )
{
    gctDOUBLE c1, c2, c3;
    gctDOUBLE m, y;
    gctFLOAT ret;

    if(!x)
        return 0;

    m = (gctDOUBLE)((2523.f/4096.f) * 128.f);
    c1 = (gctDOUBLE)(3424.f/4096.f);
    c2 = (gctDOUBLE)((2413.f/4096.f) *32.f);
    c3 = (gctDOUBLE)((2392.f/4096.f) *32.f);
    y  = (gctDOUBLE)(x/10000.f);

    c1 = c1 + c2 * y;
    c3 = 1+ c3 * y;
    c1 = c1 / c3;
    x = (gctFLOAT)(vivPOW(c1, m));

    ret = (gctFLOAT)(x*4095.f /4096.f);

    return ret;
}

#if vivENABLE_DISPLAY_NEWGMMA
gctVOID viv_util_prepare_new_gamma(
    Gamma* new_gamma
    )
{
    gctUINT i, table_value;
    gctFLOAT tmpf0, tmpf1;
    gctUINT table0[17] = {0};
    gctUINT table1[257] = {0};

    for(i = 0; i <= 16; i++)
    {
        tmpf0 = (gctFLOAT)(i/1024.f * 10000.f);
        tmpf1 = viv_util_dc_to_gamma(tmpf0);
        table0[i] = (gctUINT)(tmpf1*4095.f + 0.95f);
    }

    for(i = 4; i < 256; i++)
    {
        tmpf0 = (gctFLOAT)(i/256.f * 10000.f);
        tmpf1 = viv_util_dc_to_gamma(tmpf0);
        table1[i] = (gctUINT)(tmpf1*4095.f + 0.5f);
    }
    table1[256] = 4095;

    /* final table construct */
    for(i = 0; i < GAMMA_TABLE_SIZE; i++)
    {
        /* When input data is less than 32, directly look up the table
         * Direct look up needs 32 entries
         */
        if(i < 32)
        {
            tmpf0 = (gctFLOAT)(i/1024.f * 10000.f);
            tmpf1 = viv_util_dc_to_gamma(tmpf0);
            table_value = (gctUINT)(tmpf1*(16384 - 1.f));
        }

        /* When input data >=32 and < 256, look up the table and then do interpolation
         * Each interval has 16 data. [32,48),[48,64),[240,256).
         * It needs 15 entries
         */
        else if(i < 47)
            table_value = table0[i-30]; /* use table0[2] - [16] */

        /* When input data >=256, look up the  table and then do interpolation
         * Each interval has 64 data. [256,320),[320,384),[16320,12384)
         * It needs 252+1 entries.  Extra 1 is for 10384 look up.
         */
        else
            table_value = table1[i-43]; /* use table1[4] - [256] */

        new_gamma->gamma_table[i][0] = table_value & 0xFFF;
        new_gamma->gamma_table[i][1] = table_value & 0xFFF;
        new_gamma->gamma_table[i][2] = table_value & 0xFFF;
    }
}
#endif

#if vivENABLE_LAYER_DEGAMMA
/* Prepare de-gamma table config.
 */
gctFLOAT viv_util_dc_to_degamma(
    gctFLOAT  x
    )
{
    gctDOUBLE c1, c2, c3;
    gctDOUBLE m1, m2;
    gctFLOAT ret;

    m1 = (gctDOUBLE)(2610.f/16384.f);
    m2 = (gctDOUBLE)((2523.f/4096.f) * 128.f);
    c1 = (gctDOUBLE)(3424.f/4096.f);
    c2 = (gctDOUBLE)((2413.f/4096.f) *32.f);
    c3 = (gctDOUBLE)((2392.f/4096.f) *32.f);

    x = (gctFLOAT)((x*4096)/4095.f);  /* This make 4095 mapping to 1.0 */
    if(x > 1.0)
        x = 1.0;

    m1 = 1.f/m1;
    m2 = vivPOW((gctDOUBLE)x, 1.f/m2);
    c2 = c2 - c3 * m2;
    c1 = m2 - c1;
    if(c1 < 0)
        return 0;

    c1 /= c2;
    c1 = vivPOW(c1, m1) * 10000;
    ret = (gctFLOAT)c1;

    return ret;
}

gctVOID viv_util_prepare_degamma(
    Degamma*  de_gamma,
    gctBOOL   BT709
    )
{
    gctUINT i, table_value;
    gctFLOAT tmpf0, tmpf1;
    gctUINT table1[257] = {0};
    gctUINT table2[4] = {0};

    /* This part is used to interpolation and each interval have 4 datas.
     * [0,4),[4,8),...[1016,1020)
     * There are 255+1 entries for interpolation
     */
    for(i = 0; i < 256; i++)
    {
        tmpf0 = (gctFLOAT)(i/256.f);
        if(BT709)
            tmpf1 = (gctFLOAT)vivPOW(tmpf0, 2.4f);    /* for 709 */
        else
            tmpf1 = viv_util_dc_to_degamma(tmpf0) / 10000.f;    /* for 2020 */

        table1[i] = (gctUINT)(tmpf1*(1<<14)*2.f);
    }
    table1[256] = (gctUINT)((1<<14)*2.f - 1.f);

    /* When input data <1020, look up table and do interpolation.
     * When input data >=1020 ([1020,1023]),  directly look up the table.
     * There are 4 entries for direct look up.
     */
    for(i = 1020; i <= 1023; i++)
    {
        tmpf0 = (gctFLOAT)(i/1024.f);
        if(BT709)
            tmpf1 = (gctFLOAT)vivPOW(tmpf0, 2.4f);    /* for 709 */
        else
            tmpf1 = viv_util_dc_to_degamma(tmpf0) / 10000.f;    /* for 2020 */

        table2[i-1020] = (gctUINT)(tmpf1*((1<<14) - 1));
    }

    /* final table construct */
    for(i = 0; i < DEGAMMA_TABLE_SIZE; i++)
    {
        if(i < 256)
            table_value = table1[i];
        else
            table_value = table2[i-256];

        de_gamma->degamma_table[i][0] = table_value & 0x7FFF;
        de_gamma->degamma_table[i][1] = table_value & 0x7FFF;
        de_gamma->degamma_table[i][2] = table_value & 0x7FFF;
    }
}
#endif

#if vivENABLE_DISPLAY_3DLUT
vivSTATUS viv_util_prepare_threed_lut(
    gctUINT32* threed_lut
    )
{
    gctUINT32 r_index = 0, g_index = 0, b_index = 0;
    gctUINT32 r_temp = 0, g_temp = 0, b_temp = 0;
    gctFLOAT r = 0, g = 0, b = 0;
    gctUINT lut = 0;
    vivSTATUS ret = vivSTATUS_OK;

    ret = viv_dc_query_feature(vivFEATURE_3D_LUT, &lut);
    if(vivSTATUS_OK != ret)
        return ret;

    if (!lut)
    {
        viv_print("3D_LUT feature is not supported.\n");
        return vivSTATUS_NOT_SUPPORT;
    }

    for (r_index = 0; r_index < 17; r_index ++)
    {
        for (g_index = 0; g_index < 17; g_index ++)
        {
            for (b_index = 0; b_index < 17; b_index ++)
            {
                r = (gctFLOAT) r_index/16.f;
                g = (gctFLOAT) g_index/16.f;
                b = (gctFLOAT) b_index/16.f;

                r_temp = (((gctUINT)(r * 1023.99f)) & 0x3FF) << 20;
                g_temp = (((gctUINT)(g * 1023.99f)) & 0x3FF) << 10;
                b_temp = ((gctUINT)(b * 1023.99f)) & 0x3FF;

                threed_lut[r_index*17*17 + g_index*17 + b_index] = r_temp | g_temp | b_temp;
            }
        }
    }

    return vivSTATUS_OK;
}
#endif

/* Load bmp data into framebuffer or overlay.
 */
gctINT viv_util_load_bmp(
    gctUINT8* filename,
    gctUINT8* logical,
    gctUINT32 Size,
    gctUINT8* Lut,
    gctUINT32 Stride
    )
{
	vivSTATUS ret = vivSTATUS_OK;  //IFX: IAR warning integer conversion looses sign
    gctUINT32 i, size, offset, bpp;
    gctSIZE_T width, height, stride;
    gctPOINTER fp = vivNULL;
    gctUINT8* bits = vivNULL;
    gctINT h;
    gctUINT32 infosize;
    gctUINT32 lut_tmp[256];

    if (filename == vivNULL || logical == vivNULL)
    {
        ret = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if ((fp = viv_os_file_open((gctCHAR *)filename, vivFILE_READB)) == vivNULL)
    {
        viv_print("Can not find %s\n", filename);
        ret = vivSTATUS_FAILED;
        goto exit;
    }

    viv_os_file_read_word(fp);
    viv_os_file_read_dword(fp);
    viv_os_file_read_word(fp);
    viv_os_file_read_word(fp);
    offset = viv_os_file_read_dword(fp);
    size   = viv_os_file_read_dword(fp);
    width  = viv_os_file_read_long(fp);
    h = viv_os_file_read_long(fp);
    height = vivABS(h);
    viv_os_file_read_word(fp);
    bpp = viv_os_file_read_word(fp);
    stride = ((width*bpp/8)+3)&(~3);
    size = vivMAX(size, stride * height);

    /* biCompression. */
    viv_os_file_read_dword(fp);
    /* biSizeImage. */
    viv_os_file_read_dword(fp);
    /* biXPelsPerMeter*/
    viv_os_file_read_long(fp);
    /* biYPelsPerMeter*/
    viv_os_file_read_long(fp);


    /* biClrUsed. */
    viv_os_file_read_dword(fp);
    /* biClrImportant. */
    viv_os_file_read_dword(fp);

    if (size > Size)
    {
        viv_print("Load bmp failed. Too large to current FB.");
        ret = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    infosize = offset - 14;

    if (infosize > 40)
    {
        int n = (infosize - 40) / 4;
        unsigned int *p = (unsigned int *)lut_tmp;

        while (n > 0)
        {
            *p = viv_os_file_read_dword(fp);
            p++;
            n--;
        }

        dc_os_memcpy(Lut, lut_tmp, 256 * 4);
    }

    if (viv_os_file_seek(fp, offset, vivFALSE) == vivSTATUS_OK)
    {
        if (g_back_addr == vivNULL || Size > g_back_size)
        {
            if (g_back_addr != vivNULL)
            {
                viv_os_mem_free(g_back_addr);
                g_back_addr = vivNULL;
            }

            if ((g_back_addr = viv_os_mem_alloc(Size)) == vivNULL)
            {
                viv_print("Load bmp failed. Fail to alloc memory.\n");
                return vivSTATUS_OOM;
            }

            g_back_size = Size;
        }

        for (i = 0; i < height; i++)
        {
            bits = h >= 0
                 ? (gctUINT8 *)g_back_addr + (height - i - 1) * Stride
                 : (gctUINT8 *)g_back_addr + i * Stride
                 ;

            if (viv_os_file_read(bits, stride, fp) < stride)
            {
                ret = vivSTATUS_FAILED;
                goto exit;
            }
        }

        dc_os_memcpy(
            logical,
            g_back_addr,
            Size);
    }
    else
    {
        ret = vivSTATUS_FAILED;
    }

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return (gctINT)ret; //IFX - Fix Warning typecast needed.
}

/* Load bmp data into framebuffer.
 */
gctINT viv_util_load_bmp2buffer(
    gctUINT8* filename,
    gctUINT32 bufferStride,
    gctUINT8* buffer,
    gctUINT32 *Width,
    gctUINT32 *Height
    )
{
	viv_status_type ret = vivSTATUS_OK; //IFX: Fix IAR warning, enumerated type mixed with integer.
    gctUINT32 i, j, size, offset, bpp;
    gctSIZE_T width, height, stride;
    gctPOINTER fp = vivNULL;
    gctUINT8* bits = vivNULL;
    gctINT h;

    if (filename == vivNULL)
    {
        ret = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if ((fp = viv_os_file_open((gctCHAR *)filename, vivFILE_READB)) == vivNULL)
    {
        viv_print("Can not find %s\n", filename);
        ret = vivSTATUS_FAILED;
        goto exit;
    }

    viv_os_file_read_word(fp);
    viv_os_file_read_dword(fp);
    viv_os_file_read_word(fp);
    viv_os_file_read_word(fp);
    offset = viv_os_file_read_dword(fp);
    size   = viv_os_file_read_dword(fp);
    width  = viv_os_file_read_long(fp);
    h = viv_os_file_read_long(fp);
    height = vivABS(h);
    viv_os_file_read_word(fp);
    bpp = viv_os_file_read_word(fp);
    stride = ((width*(bpp/8))+3)&(~3);
    size = vivMAX(size, stride * height);

    if (bufferStride == 0)
    {
        bufferStride = width * 4;

        *Width = width;
        *Height = height;
    }

    if (viv_os_file_seek(fp, offset, vivFALSE) == vivSTATUS_OK)
    {
        for (i=0, bits=buffer; i<height; i++, bits+=bufferStride)
        {
            bits = h >= 0
                 ? (gctUINT8 *)buffer + (height - i - 1) * bufferStride
                 : (gctUINT8 *)buffer + i * bufferStride
                 ;

            if (bpp == 32)
            {
                if (viv_os_file_read(bits, stride, fp) < stride)
                {
                    ret = vivSTATUS_FAILED;
                    goto exit;
                }
            }
            else
            {
                for (j = 0; j < stride; j += 3)
                {
                    if (viv_os_file_read(bits + j / 3 * 4, 3, fp) < 3)
                    {
                        ret = vivSTATUS_FAILED;
                        goto exit;
                    }
                }
            }
        }
    }
    else
    {
        ret = vivSTATUS_FAILED;
    }

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return (gctINT)ret; //IFX - Fix Warning typecast needed.
}

vivSTATUS viv_util_get_tile_size(
    gctUINT32 format,
    gctUINT32 tile_mode,
    gctUINT32 compressed,
    gctUINT32 *tile_width_l1,
    gctUINT32 *tile_height_l1,
    gctUINT32 *tile_width_l2,
    gctUINT32 *tile_height_l2,
    gctUINT32 *tile_size_l2
    )
{
    vivSTATUS status = vivSTATUS_OK;
    gctUINT32 w1[3], h1[3], w2[3], h2[3];
    gctUINT32 s2[3], bpp[3];
    gctUINT32 plane_num, i;

    status = viv_util_get_plane_bpp((viv_input_format_type)format, &plane_num, bpp); //IFX - Fix Warning typecast needed.
    if (status != vivSTATUS_OK)
    {
        return status;
    }

    switch (tile_mode)
    {
    case vivTILED4X4:
        w1[0] = w1[1] = w1[2] = 4;
        h1[0] = h1[1] = h1[2] = 4;
        w2[0] = 4;
        h2[0] = 4;
        break;

    case vivTILED8X8:
        w1[0] = 8;
        h1[0] = 8;
        w2[0] = 8;
        h2[0] = 8;

        switch (format)
        {
        case vivNV12:
        case vivNV21:
            w1[1] = 8;
            h1[1] = 4;
            w2[1] = 8;
            h2[1] = 4;
            break;

        default:
            break;
        }
        break;

    case vivSUPER_TILED_X:
        if ((format == vivARGB8888) || (format == vivXRGB8888) || (format == vivARGB2101010))
        {
            w1[0] = 64;
            h1[0] = 64;
            w2[0] = 8;
            h2[0] = 4;
        }
        else if ((format == vivRGB565) || (format == vivARGB1555) || (format == vivXRGB1555) ||
            (format == vivARGB4444) || (format == vivXRGB4444))
        {
            w1[0] = 64;
            h1[0] = 64;
            w2[0] = 8;
            h2[0] = 8;
        }
        else
        {
            viv_os_print("current format and tile is not supported\n");
            return vivSTATUS_NOT_SUPPORT;
        }
        break;

    case vivSUPER_TILED_Y:
        w1[0] = 64;
        h1[0] = 64;
        w2[0] = 4;
        h2[0] = 8;
        break;

    default:
        for (i = 0; i < plane_num; i++)
        {
            w1[i] = 8;
            h1[i] = 1;
            w2[i] = 8;
            h2[i] = 1;
        }
        break;
    }

    for (i = 0; i < plane_num; i++)
    {
        s2[i] = w2[i] * h2[i] * bpp[i] / 8;
    }

    if (tile_width_l1)
    {
        for (i = 0; i < plane_num; i++)
        {
            tile_width_l1[i] = w1[i];
        }
    }

    if (tile_height_l1)
    {
        for (i = 0; i < plane_num; i++)
        {
            tile_height_l1[i] = h1[i];
        }
    }

    if (tile_width_l2)
    {
        for (i = 0; i < plane_num; i++)
        {
            tile_width_l2[i] = w2[i];
        }
    }

    if (tile_height_l2)
    {
        for (i = 0; i < plane_num; i++)
        {
            tile_height_l2[i] = h2[i];
        }
    }

    if (tile_size_l2)
    {
        for (i = 0; i < plane_num; i++)
        {
            tile_size_l2[i] = s2[i];
        }
    }

    return status;
}

/*
 * Load subarea of bmp into framebuffer or overlay.
 *
 * It loads the data into the buffer with the followings.
 * with = min(buf_width, img_width)
 * height = min(buf_height, img_height)
 */
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
    )
{
    viv_status_type ret = vivSTATUS_OK;
    gctUINT i, j;
    gctUINT32 offset, bpp;
    gctUINT32 img_width, img_height, img_stride;
    gctUINT32 width, height, stride;
    gctINT h;
    gctPOINTER fp = vivNULL;

    gctUINT8 *img_buf = vivNULL;

    if (!file_name|| !buf)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    fp = viv_os_file_open((gctCHAR *)file_name, vivFILE_READB);
    if (!fp)
    {
        viv_print("Can not find %s\n", file_name);
        ret = vivSTATUS_FAILED;
        goto exit;
    }

    viv_os_file_read_word(fp);
    viv_os_file_read_dword(fp);
    viv_os_file_read_word(fp);
    viv_os_file_read_word(fp);
    offset = viv_os_file_read_dword(fp);
    viv_os_file_read_dword(fp);
    img_width = viv_os_file_read_long(fp);
    h = viv_os_file_read_long(fp);
    img_height = vivABS(h);
    viv_os_file_read_word(fp);
    bpp = viv_os_file_read_word(fp);
    img_stride = (img_width*bpp/8+3)&(~3);

    width  = vivMIN(buf_width, img_width);
    height = vivMIN(buf_height, img_height);
    stride = vivMIN(buf_stride, img_stride);

    /* biCompression. */
    viv_os_file_read_dword(fp);
    /* biSizeImage. */
    viv_os_file_read_dword(fp);
    /* biXPelsPerMeter*/
    viv_os_file_read_long(fp);
    /* biYPelsPerMeter*/
    viv_os_file_read_long(fp);

    /* biClrUsed. */
    viv_os_file_read_dword(fp);
    /* biClrImportant. */
    viv_os_file_read_dword(fp);

    /* Check LUT. */
    if (lut)
    {
        gctUINT32 info_size = offset - 14;

        if (info_size > 40)
        {
            gctUINT n = (info_size - 40) / 4;
            gctUINT32 *p = lut;

            while (n-- > 0)
            {
                *p++ = viv_os_file_read_dword(fp);
            }
        }
    }

    if (viv_os_file_seek(fp, offset, vivFALSE) == vivSTATUS_OK)
    {
        gctUINT8 *bits = vivNULL;
        gctUINT32 pos;
        gctUINT32 tile_height_l1;
        gctUINT8 *img_bits = vivNULL;

        ret = viv_util_get_tile_size(
            format,
            tile_mode,
            compression,
            vivNULL,
            &tile_height_l1,
            vivNULL,
            vivNULL,
            vivNULL);
        if (ret != vivSTATUS_OK)
        {
            goto exit;
        }

        if (h >= 0)
        {
            if (tile_height_l1 > 1)
            {
                /*
                 * Use tmp buffer to make life easier for
                 * tiled and bottom-to-top stored bmp file.
                 */
                gctUINT32 size = img_stride * img_height;

                img_buf = viv_os_mem_alloc(size);
                if (!img_buf)
                {
                    ret = vivSTATUS_OOM;
                    goto exit;
                }

                for (i = 0; i < img_height; i++)
                {
                    if (viv_os_file_read(img_buf + (img_height - i - 1) * img_stride, img_stride, fp) < img_stride)
                    {
                        ret = vivSTATUS_FAILED;
                        goto exit;
                    }
                }
            }
            else if (img_height > buf_height)
            {
                viv_os_file_seek(fp, dc_os_file_tell(fp) + (img_height - buf_height) * img_stride, vivFALSE);
            }
        }

        for (i = 0; i < height; i += tile_height_l1)
        {
            if (img_buf)
            {
                /* h >= 0 && tile_height > 1 */
                bits = (gctUINT8 *)buf + i * buf_stride;
                img_bits = img_buf + i * img_stride;

                viv_os_memcpy(bits, img_bits, img_stride * tile_height_l1);
            }
            else
            {
                /* h < 0 || tile_height == 1 */
                bits = (h >= 0)
                    ? (gctUINT8 *)buf + (height - i - tile_height_l1) * buf_stride
                    : (gctUINT8 *)buf + i * buf_stride;

                pos = dc_os_file_tell(fp);

                if (bpp == 24)
                {
                    for (j = 0; j < width * tile_height_l1; j++)
                    {
                        if (viv_os_file_read(bits + j * 4, 3, fp) < 3)
                        {
                            ret = vivSTATUS_FAILED;
                            goto exit;
                        }
                    }
                }
                else
                {
                    if (viv_os_file_read(bits, stride * tile_height_l1, fp) < stride * tile_height_l1)
                    {
                        viv_os_print("stride = %d\n", stride);
                        ret = vivSTATUS_FAILED;
                        goto exit;
                    }
                }

                /* Move to the next position. */
                viv_os_file_seek(fp, pos + img_stride * tile_height_l1, vivFALSE);
            }
        }

        if (ret_buf_width && ret_buf_height)
        {
            *ret_buf_width  = buf_width;
            *ret_buf_height = buf_height;
        }

        if (ret_img_width && ret_img_height)
        {
            *ret_img_width  = img_width;
            *ret_img_height = img_height;
        }
    }
    else
    {
        ret = vivSTATUS_FAILED;
    }

exit:
    if (img_buf)
    {
        viv_os_mem_free(img_buf);
    }

    if (fp)
    {
        viv_os_file_close(fp);
    }

    return ret;
}

gctINT viv_util_load_text_raw(
    gctUINT8* filename,
    gctUINT32* Buffer,
    gctUINT32 Size,
    gctUINT32 Format,
    gctUINT32 Height,
    gctUINT32 Stride[]
    )
{
    gctINT ret = vivSTATUS_OK;
    gctPOINTER *fp = vivNULL;
    char line[16];
    gctUINT32 number;
    gctUINT32 bytes = 0;
    gctUINT i, n;
    gctUINT32 *bits = vivNULL;
    gctUINT nPlane;
    gctUINT32 width[3], height[3];
    gctUINT32 bpps[3];
    gctUINT32 offset[3];

    if (filename == vivNULL ||
        Buffer == vivNULL)
    {
        ret = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if ((fp = viv_os_file_open((gctCHAR *)filename, vivFILE_READ)) == vivNULL)
    {
        viv_print("Can not find %s\n", filename);
        ret = vivSTATUS_FAILED;
        goto exit;
    }

    calculateBufferSize((viv_input_format_type)Format, 0, Height, &nPlane, width, height, bpps); //IFX - Fix Warning typecast needed.

    offset[0] = 0;
    offset[1] = offset[0] + height[0] * Stride[0];
    offset[2] = offset[1] + height[1] * Stride[1];

    for (n = 0; n < nPlane; n++)
    {

        for (i = 0; i < height[n]; i++)
        {
            bytes = 0;
            bits = (gctUINT32 *)((gctUINT8*)Buffer + offset[n] + i * Stride[n]);

            while (bytes < Stride[n] && viv_os_fgets(line, 16, fp))
            {
                sscanf(line, "%x", &number);

                *bits++ = number;

                bytes += 4;
            }
        }
    }

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return ret;
}

gctINT viv_util_load_raw(
    gctUINT8* Buffer,
    gctUINT32 Size,
    gctUINT8* filename
    )
{
    gctINT ret = vivSTATUS_OK;
    gctPOINTER *fp = vivNULL;

    if (filename == vivNULL ||
        Buffer == vivNULL)
    {
        ret = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if ((fp = viv_os_file_open((gctCHAR *)filename, vivFILE_READB)) == vivNULL)
    {
        viv_print("Can not find %s\n", filename);
        ret = vivSTATUS_FAILED;
        goto exit;
    }

    viv_os_file_read(Buffer, Size, fp);

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return ret;
}

gctINT viv_util_load_raw_area(
    gctUINT8** plane_addr,
    gctUINT32*  plane_stride,
    gctUINT32*  align_height,
    gctUINT32*  align_width,
    gctUINT32*  bpps,
    gctUINT32  format,
    gctUINT32   plane_num,
    gctUINT8*   filename
    )
{
    gctINT ret = vivSTATUS_OK;
    gctPOINTER *fp = vivNULL;
    gctUINT32 i = 0, j = 0;
    gctUINT8* p = vivNULL;

    if (filename == vivNULL || *plane_addr == vivNULL)
    {
        ret = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if ((fp = viv_os_file_open((gctCHAR *)filename, vivFILE_READB)) == vivNULL)
    {
        viv_print("Can not find %s\n", filename);
        ret = vivSTATUS_FAILED;
        goto exit;
    }

    for(i = 0; i < plane_num; i++)
    {
        gctUINT32 pos_line, pos_plane;
        p = plane_addr[i];
        pos_plane = dc_os_file_tell(fp);
        for(j = 0;j < align_height[i];j++){

            pos_line = dc_os_file_tell(fp);

            viv_os_file_read(p, align_width[i]*bpps[i]/8, fp);
            p += plane_stride[i];
            viv_os_file_seek(fp, pos_line + align_width[i] * bpps[i] / 8, vivFALSE);
        }
        viv_os_file_seek(fp, pos_plane + align_width[i] * align_height[i] * bpps[i] / 8, vivFALSE);
    }

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return ret;
}

/* Dump video/overlay source capture
 */
gctINT viv_source_capture_dump(
    gctPOINTER logical,
    gctUINT32  size,
    gctADDRESS  phys_addr,
    gctBOOL    video,
    gctBOOL    final_plane
    )
{
    gctINT    ret = vivSTATUS_OK;
    gctCHAR*  std_srting_0 = "40'h";
    gctCHAR*  std_srting_1 = " f 32'h";
    gctUINT32* source;
    gctUINT32 i = 0;

    if(fp_src == vivNULL)
    {
        if(video)
        {
            if ((fp_src = viv_os_file_open(VIDEO_SOURCE_PATH, vivFILE_WRITE)) == vivNULL)
            {
                viv_print("Video source capture file can't be opene\n");
                ret = vivSTATUS_FAILED;
                goto exit;
            }
        }
        else if((fp_src = viv_os_file_open(OVERLAY_SOURCE_PATH, vivFILE_WRITE)) == vivNULL)
        {
            viv_print("Overlay source capture file can't be opene\n");
            ret = vivSTATUS_FAILED;
            goto exit;
        }
    }

    if(!logical || !size)
    {
        viv_os_file_close(fp_src);
        fp_src = vivNULL;
        return ret;
    }
    source = (gctUINT32 *)logical;
    for (i = 0; i < size / 4; i++)
    {
        viv_os_fprint(fp_src, "%s", std_srting_0);

        viv_os_fprint(fp_src, "%010llX", phys_addr);
        phys_addr += 4;
        viv_os_fprint(fp_src, "%s", std_srting_1);

        viv_os_fprint(fp_src, "%08X", source[i] & 0xFFFFFFFF);
        viv_os_fprint(fp_src, "\n");
    }

    if (size % 4 != 0)
        viv_os_fprint(fp_src, "\n");

    if(final_plane)
    {
        viv_os_file_close(fp_src);
        fp_src = vivNULL;
    }
    return ret;

exit:
    if (fp_src)
        viv_os_file_close(fp_src);
    fp_src = vivNULL;

    return ret;
}

vivSTATUS viv_util_get_ts_bit(
    gctUINT32 format,
    gctUINT32 tile_mode,
    gctUINT32 alignment,
    gctUINT32 plane_num,
    gctUINT32 *tile_size,
    gctUINT32 *ts_bit_len
    )
{
    vivSTATUS status = vivSTATUS_OK;
    gctUINT32 i;

    if (!ts_bit_len)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (!viv_util_is_yuv((viv_input_format_type)format) || //IFX - Fix Warning typecast needed.
        (format == vivYUY2) ||
        (format == vivUYVY))
    {
        ts_bit_len[0] = 4;
    }
    else
    {
        if (!tile_size)
        {
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        for (i = 0; i < plane_num; i++)
        {
            if (tile_size[i] > 256)
            {
                return vivSTATUS_INVALID_ARGUMENTS;
            }

            if ((tile_size[i] > 128) &&
                (tile_size[i] < 256))
            {
                tile_size[i] = 256;
            }
            else if ((tile_size[i] > 64) &&
                     (tile_size[i] < 128))
            {
                tile_size[i] = 128;
            }

            switch (alignment)
            {
            case vivCOMPRESSION_DEC400_16_BYTES_ALIGNED:
                switch (tile_size[i])
                {
                case 256:
                case 128:
                    ts_bit_len[i] = 4;
                    break;
                case 64:
                    ts_bit_len[i] = 2;
                    break;
                default:
                    break;
                }
                break;
            case vivCOMPRESSION_DEC400_32_BYTES_ALIGNED:
                switch (tile_size[i])
                {
                case 256:
                    ts_bit_len[i] = 4;
                    break;
                case 128:
                    ts_bit_len[i] = 2;
                    break;
                case 64:
                    ts_bit_len[i] = 1;
                    break;
                default:
                    break;
                }
                break;
            case vivCOMPRESSION_DEC400_64_BYTES_ALIGNED:
                switch (tile_size[i])
                {
                case 256:
                    ts_bit_len[i] = 2;
                    break;
                case 128:
                case 64:
                    ts_bit_len[i] = 1;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }

    return status;
}

vivSTATUS viv_util_load_raw_ts(
    gctUINT8 *file_name,
    gctUINT8 *buf,
    gctUINT32 ts_bit_len,
    gctUINT32 tile_width_l1,
    gctUINT32 tile_height_l1,
    gctUINT32 tile_width_l2,
    gctUINT32 tile_height_l2,
    gctUINT32 buf_width_in_tile_l1,
    gctUINT32 buf_height_in_tile_l1,
    gctUINT32 img_width_in_tile_l1,
    gctUINT32 img_height_in_tile_l1
    )
{
    vivSTATUS status = vivSTATUS_OK;
    gctPOINTER *fp = vivNULL;
    gctUINT32 i;
    gctUINT32 l2_tile_num_in_l1_block;
    gctUINT32 width_in_tile_l1, height_in_tile_l1;

    if (!file_name || !buf)
    {
        status = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    fp = viv_os_file_open((gctCHAR *)file_name, vivFILE_READ);
    if (!fp)
    {
        viv_print("Failed to load ts file: %s.\n", file_name);
        status = vivSTATUS_FAILED;

        goto exit;
    }

    l2_tile_num_in_l1_block = (tile_width_l1 / tile_width_l2) * (tile_height_l1 / tile_height_l2);

    width_in_tile_l1  = vivMIN(buf_width_in_tile_l1, img_width_in_tile_l1);
    height_in_tile_l1 = vivMIN(buf_height_in_tile_l1, img_height_in_tile_l1);

    for (i = 0; i < height_in_tile_l1; i++)
    {
        gctUINT8 *p = buf + i * buf_width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8;
        gctUINT32 pos = dc_os_file_tell(fp);

        switch (ts_bit_len)
        {
        case 8:
            if (viv_os_file_read(p,  width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
            {
                viv_print("Failed to read file.\n");
                goto exit;
            };
            break;
        case 4:
            if (width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len % 8)
            {
                /* TODO. */
            }
            else
            {
                if (viv_os_file_read(p, width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
                {
                    viv_print("Failed to read file.\n");
                    goto exit;
                };
            }
            break;
        case 2:
            viv_print("2-bit ts buffer is not supported yet.\n");
            break;
        case 1:
            if (width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len % 8)
            {
                /* TODO. */
            }
            else
            {
                if (viv_os_file_read(p, width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
                {
                    viv_print("Failed to read file.\n");
                    goto exit;
                };
            }
            break;
        default:
            viv_print("TS bit length of %d is not supported.\n", ts_bit_len);
            goto exit;
        }

        viv_os_file_seek(fp, pos + img_width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, vivFALSE);
    }

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return status;
}

vivSTATUS viv_util_load_ts(
    gctPOINTER *fp,
    gctUINT32 offset,
    gctUINT8 *buf,
    gctUINT32 ts_bit_len,
    gctUINT32 tile_width_l1,
    gctUINT32 tile_height_l1,
    gctUINT32 tile_width_l2,
    gctUINT32 tile_height_l2,
    gctUINT32 buf_width_in_tile_l1,
    gctUINT32 buf_height_in_tile_l1,
    gctUINT32 img_width_in_tile_l1,
    gctUINT32 img_height_in_tile_l1
    )
{
    vivSTATUS status = vivSTATUS_OK;
    gctUINT32 i;
    gctUINT32 l2_tile_num_in_l1_block;
    gctUINT32 width_in_tile_l1, height_in_tile_l1;

    if (!fp || !buf)
    {
        status = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if (viv_os_file_seek(fp, offset, vivFALSE) < 0)
    {
        status = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    l2_tile_num_in_l1_block = (tile_width_l1 / tile_width_l2) * (tile_height_l1 / tile_height_l2);

    width_in_tile_l1  = vivMIN(buf_width_in_tile_l1, img_width_in_tile_l1);
    height_in_tile_l1 = vivMIN(buf_height_in_tile_l1, img_height_in_tile_l1);

    for (i = 0; i < height_in_tile_l1; i++)
    {
        gctUINT8 *p = buf + i * buf_width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8;
        gctUINT32 pos = dc_os_file_tell(fp);

        switch (ts_bit_len)
        {
        case 8:
            if (viv_os_file_read(p,  width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
            {
                viv_print("Failed to read file.\n");
                goto exit;
            };
            break;
        case 4:
            if (width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len % 8)
            {
                /* TODO. */
                viv_print("TODO: ts bit is not aligned.\n");
            }
            else
            {
                if (viv_os_file_read(p, width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
                {
                    viv_print("Failed to read file.\n");
                    goto exit;
                };
            }
            break;
        case 2:
            if (width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len % 8)
            {
                /* TODO. */
                viv_print("TODO: ts bit is not aligned.\n");
            }
            else
            {
                if (viv_os_file_read(p, width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
                {
                    viv_print("Failed to read file.\n");
                    goto exit;
                };
            }
            break;
        case 1:
            if (width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len % 8)
            {
                /* TODO. */
                viv_print("TODO: ts bit is not aligned.\n");
            }
            else
            {
                if (viv_os_file_read(p, width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, fp) <= 0)
                {
                    viv_print("Failed to read file.\n");
                    goto exit;
                };
            }
            break;
        default:
            viv_print("TS bit length of %d is not supported.\n", ts_bit_len);
            goto exit;
        }

        viv_os_file_seek(fp, pos + img_width_in_tile_l1 * l2_tile_num_in_l1_block * ts_bit_len / 8, vivFALSE);
    }

exit:
    return status;
}


gctINT viv_util_free_hwcursor(
    Cursor *cursor
    )
{
    if (!cursor->cursor_buffer.handle[0])
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    viv_free_buffer(cursor->cursor_buffer.handle[0]);

    cursor->cursor_buffer.handle[0] = vivNULL;
    cursor->cursor_buffer.logical[0] = vivNULL;
    cursor->cursor_buffer.phyAddress[0] = 0;

    return vivSTATUS_OK;
}

gctUINT32 GalLoadVimgToTSurfWithPool(
    gctUINT8 * Filename,
    gctUINT8 * Buffer, gctUINT8* TileStatus[],
    gctUINT32 Size
    )
{
    gctPOINTER file = vivNULL;
    vivSTATUS status;

    VIMG_FILEHEADER head;
    VIMG_V1 *v1 = vivNULL;
    VIMG_V2 *v2 = vivNULL;
    VIMG_V2 vhead;

    /* gceTILING tiling; */
    /* gce2D_TILE_STATUS_CONFIG tsc = gcv2D_TSC_DISABLE; */
    gctUINT n = 0;

    file = viv_os_file_open((gctCHAR *)Filename, vivFILE_READB);

    if (!file)
    {
        status = vivSTATUS_FAILED;
        goto OnError;
    }
    viv_os_file_read(&head, sizeof(head), file);

    if (head.magic[0] != 'V' || head.magic[1] != 'I'
        || head.magic[2] != 'V')
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (head.version == 1 || head.version == 2)
    {
        vhead.v1.format = viv_os_file_read_dword(file);
        vhead.v1.tiling = viv_os_file_read_dword(file);
        vhead.v1.imageStride = viv_os_file_read_dword(file);
        vhead.v1.imageWidth = viv_os_file_read_dword(file);
        vhead.v1.imageHeight = viv_os_file_read_dword(file);
        vhead.v1.bitsOffset = viv_os_file_read_dword(file);
        v1 = &vhead.v1;

        if (head.version == 2)
        {
            vhead.tileStatusConfig = viv_os_file_read_dword(file);
            vhead.tileStatusSize = viv_os_file_read_dword(file);
            vhead.compressedFormat = viv_os_file_read_dword(file);
            vhead.clearValue = viv_os_file_read_dword(file);
            vhead.tileStatusOffset = viv_os_file_read_dword(file);
            vhead.tileStatusOffsetEx[0] = viv_os_file_read_dword(file);
            vhead.tileStatusOffsetEx[1] = viv_os_file_read_dword(file);
            vhead.tileStatusSizeEx[0] = viv_os_file_read_dword(file);
            vhead.tileStatusSizeEx[1] = viv_os_file_read_dword(file);
            v2 = &vhead;
        }
    }
    else
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    viv_os_file_seek(file, 0, vivTRUE);

    n = dc_os_file_tell(file);

    if (n - v1->bitsOffset < v1->imageHeight * v1->imageStride)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (v2 != vivNULL)
    {
        if ((v2->tileStatusOffset - v1->bitsOffset < v1->imageHeight * v1->imageStride)
            || (n - v2->tileStatusOffset < v2->tileStatusSize))
        {
            return vivSTATUS_INVALID_ARGUMENTS;
        }

    }

    viv_os_file_seek(file, v1->bitsOffset, vivFALSE);

    if (v2 != vivNULL)
    {
        if (!viv_os_file_read(Buffer, Size, file))
        {
            status = vivSTATUS_FAILED;
            goto OnError;
        }
    }
    else
    {
        /* Use tile status later. */
        switch (v1->imageStride / v1->imageWidth)
        {
        case 1:
            {
            unsigned char* p = Buffer;
            int count = Size;

            viv_os_file_read(
                p,
                count,
                file
                );

            break;
            }

        case 2:
            {
                unsigned short* p = (unsigned short *)Buffer;
                int n = Size / 2;
                while (n > 0)
                {
                    *p = viv_os_file_read_word(file);
                    p++;
                    n--;
                }
            }
            break;

        case 3:
            {
                unsigned char* p = Buffer;
                int n = Size / 3;
                while (n > 0)
                {
                    *(p + 2) = viv_os_file_read_byte(file);
                    *(p + 1) = viv_os_file_read_byte(file);
                    *(p)     = viv_os_file_read_byte(file);
                    p += 3;
                    n--;
                }
            }
            break;

        case 4:
            {
                unsigned int* p = (unsigned int *)Buffer;
                int n = Size / 4;
                while (n > 0)
                {
                    *p = viv_os_file_read_dword(file);
                    p++;
                    n--;
                }
            }
            break;
        }
    }

    if (v2 != vivNULL)
    {
        viv_os_file_seek(file, v2->tileStatusOffset, vivFALSE);

        viv_os_file_read(TileStatus[0], v2->tileStatusSize, file);
        viv_os_file_seek(file, v2->tileStatusOffsetEx[0], vivFALSE);
        viv_os_file_read(TileStatus[1], v2->tileStatusSizeEx[0], file);
    }

    viv_os_file_close(file);

    file = vivNULL;


    return vivSTATUS_OK;

OnError:

    if (file)
    {
        viv_os_file_close(file);
    }

    return status;
}

/*
 *       Y11 Y10 Y9  Y8  Y7  Y6  Y5  Y4  Y3  Y2  Y1  Y0
 * 0:                                     2  10  10  10
 * 1:                         4  10  10  8
 * 2:            6  10   10   6
 * 3: 8  10  10  4
 */
struct viv_l1_format
{
    gctUINT32 Y0:        10;
    gctUINT32 Y1:        10;
    gctUINT32 Y2:        10;
    gctUINT32 dummy_0:   2;

    gctUINT32 Y3:        10;
    gctUINT32 Y4:        10;
    gctUINT32 Y5:        10;
    gctUINT32 dummy_1:   2;

    gctUINT32 Y6:        10;
    gctUINT32 Y7:        10;
    gctUINT32 Y8:        10;
    gctUINT32 dummy_2:   2;

    gctUINT32 Y9:        10;
    gctUINT32 Y10:       10;
    gctUINT32 Y11:       10;
    gctUINT32 dummy_3:   2;
};
#if 0 //Unused API - Resolved compiler warning
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
    )
{
    gctINT status = vivSTATUS_OK;
    gctPOINTER fp = vivNULL;
    VIMG_FILEHEADER head;
    VIMG_V2 img;
    gctUINT32 img_width[3], img_height[3];
    gctUINT32 img_bpp[3];
    gctUINT32 i, j, n;
    gctBOOL swap_uv = vivFALSE;
    gctUINT32 tile_width_l1[3], tile_height_l1[3];
    gctUINT32 tile_width_l2[3], tile_height_l2[3];
    gctUINT32 tile_size_l2[3];

    fp = viv_os_file_open((gctCHAR *)file, vivFILE_READB);
    if (!fp)
    {
        status = vivSTATUS_OUT_OF_RESOURCES;
        goto exit;
    }

    n = viv_os_file_read(&head, sizeof(head), fp);
    if (n < sizeof(head))
    {
        status = vivSTATUS_OUT_OF_RESOURCES;
        goto exit;
    }

    if (viv_os_memcmp((gctCHAR *)head.magic, "VIV", 3))
    {
        status = vivSTATUS_INVALID_ARGUMENTS;
        goto exit;
    }

    if ((head.version == 1) ||
        (head.version == 2))
    {
        img.v1.format      = viv_os_file_read_dword(fp);
        img.v1.tiling      = viv_os_file_read_dword(fp);
        img.v1.imageStride = viv_os_file_read_dword(fp);
        img.v1.imageWidth  = viv_os_file_read_dword(fp);
        img.v1.imageHeight = viv_os_file_read_dword(fp);
        img.v1.bitsOffset  = viv_os_file_read_dword(fp);

        if (head.version == 2)
        {
            img.tileStatusConfig      = viv_os_file_read_dword(fp);
            img.tileStatusSize        = viv_os_file_read_dword(fp);
            img.compressedFormat      = viv_os_file_read_dword(fp);
            img.clearValue            = viv_os_file_read_dword(fp);
            img.tileStatusOffset      = viv_os_file_read_dword(fp);
            img.tileStatusOffsetEx[0] = viv_os_file_read_dword(fp);
            img.tileStatusOffsetEx[1] = viv_os_file_read_dword(fp);
            img.tileStatusSizeEx[0]   = viv_os_file_read_dword(fp);
            img.tileStatusSizeEx[1]   = viv_os_file_read_dword(fp);
        }
    }
    else
    {
        status = vivSTATUS_NOT_SUPPORT;
        goto exit;
    }

    status = viv_util_get_tile_size(
        format,
        tile_mode,
        compression,
        tile_width_l1,
        tile_height_l1,
        tile_width_l2,
        tile_height_l2,
        tile_size_l2);
    if (status != vivSTATUS_OK)
    {
        goto exit;
    }

    /* Check the type. */
    switch (format)
    {
    case vivYUY2:
    case vivUYVY:
        img_width[0]  = img.v1.imageWidth;
        img_height[0] = img.v1.imageHeight;
        img_bpp[0]    = 16;
        break;

    case vivYV12:
    case vivYU12:
        img_width[0] = img.v1.imageWidth;
        img_height[0] = img.v1.imageHeight;
        img_bpp[0] = 8;
        img_width[1] = img_width[2] = img.v1.imageWidth / 2;
        img_height[1] = img_height[2] = img.v1.imageHeight / 2;
        img_bpp[1] = img_bpp[2] = 8;
        swap_uv = vivTRUE;
        break;

    case vivNV16:
        img_width[0]  = img.v1.imageWidth;
        img_height[0] = img.v1.imageHeight;
        img_bpp[0]    = 8;
        img_width[1]  = img.v1.imageWidth / 2;
        img_height[1] = img.v1.imageHeight;
        img_bpp[1]    = 16;
        break;

    case vivNV12:
    case vivNV21:
        img_width[0]  = img.v1.imageWidth;
        img_height[0] = img.v1.imageHeight;
        img_bpp[0]    = 8;
        img_width[1]  = img.v1.imageWidth / 2;
        img_height[1] = img.v1.imageHeight / 2;
        img_bpp[1]    = 16;
        break;

    case vivNV12_10BIT:
        img_width[0]  = img.v1.imageWidth;
        img_height[0] = img.v1.imageHeight;
        img_bpp[0]    = 10;
        img_width[1]  = img.v1.imageWidth / 2;
        img_height[1] = img.v1.imageHeight / 2;
        img_bpp[1]    = 20;
        break;

    case vivYUV444:
        img_width[0] =
        img_width[1] =
        img_width[2] = img.v1.imageWidth;
        img_height[0] =
        img_height[1] =
        img_height[2] = img.v1.imageHeight;
        img_bpp[0] =
        img_bpp[1] =
        img_bpp[2] = 8;
        break;

    case vivYUV444_10BIT:
        img_width[0] =
        img_width[1] =
        img_width[2] = img.v1.imageWidth;
        img_height[0] =
        img_height[1] =
        img_height[2] = img.v1.imageHeight;
        img_bpp[0] =
        img_bpp[1] =
        img_bpp[2] = 10;
        break;

    case vivP010:
        img_width[0]  = img.v1.imageWidth;
        img_height[0] = img.v1.imageHeight;
        img_bpp[0]    = 16;
        img_width[1]  = img.v1.imageWidth / 2;
        img_height[1] = img.v1.imageHeight / 2;
        img_bpp[1]    = 32;
        break;

    default:
        status = vivSTATUS_NOT_SUPPORT;
        viv_print("Format %d is not supported.\n", format);
        goto exit;
    }

    if (swap_uv)
    {
        gctUINT8 *addr = vivNULL;
        gctUINT32 stride;

        /* Swap U and V channels. */
        addr = plane_addr[1];
        plane_addr[1] = plane_addr[2];
        plane_addr[2] = addr;

        stride = plane_stride[1];
        plane_stride[1] = plane_stride[2];
        plane_stride[2] = stride;
    }

    viv_os_file_seek(fp, img.v1.bitsOffset, vivFALSE);

    for (j = 0; j < plane_num; j++)
    {
        gctUINT32 width, height;
        gctUINT32 pos_line, pos_plane;
        gctUINT8 *p = plane_addr[j];

        width  = vivMIN(plane_width[j], img_width[j]);
        height = vivMIN(plane_height[j], img_height[j]);

        pos_plane = dc_os_file_tell(fp);

        for (i = 0; i < height; i += tile_height_l1[j])
        {
            pos_line = dc_os_file_tell(fp);

            viv_os_file_read(p, width * tile_height_l1[j] * img_bpp[j] / 8, fp);

            p += plane_stride[j] * tile_height_l1[j];
            viv_os_file_seek(fp, pos_line + img_width[j] * tile_height_l1[j] * img_bpp[j] / 8, vivFALSE);
        }

        viv_os_file_seek(fp, pos_plane + img_width[j] * img_height[j] * img_bpp[j] / 8, vivFALSE);
    }

    if (head.version >= 2)
    {
        gctUINT32 ts_bit_len[3];
        gctUINT32 offset[3];

        offset[0] = img.tileStatusOffset;
        offset[1] = img.tileStatusOffsetEx[0];

        status = viv_util_get_ts_bit(
            format,
            tile_mode,
            vivCOMPRESSION_DEC400_32_BYTES_ALIGNED,
            plane_num,
            tile_size_l2,
            ts_bit_len
            );
        if (status != vivSTATUS_OK)
        {
            goto exit;
        }

        for (i = 0; i < plane_num; i++)
        {
            viv_util_load_ts(fp,
                offset[i],
                ts_buf[i],
                ts_bit_len[i],
                tile_width_l1[i],
                tile_height_l1[i],
                tile_width_l2[i],
                tile_height_l2[i],
                plane_width[i] / tile_width_l1[i],
                plane_height[i] / tile_height_l1[i],
                img_width[i] / tile_width_l1[i],
                img_height[i] / tile_height_l1[i]);
        }
    }

    if (ret_buf_width)
    {
        for (i = 0; i < plane_num; i++)
        {
            ret_buf_width[i] = plane_width[i];
        }
    }

    if (ret_buf_height)
    {
        for (i = 0; i < plane_num; i++)
        {
            ret_buf_height[i] = plane_height[i];
        }
    }

    if (ret_img_width)
    {
        for (i = 0; i < plane_num; i++)
        {
            ret_img_width[i] = img_width[i];
        }
    }

    if (ret_img_height)
    {
        for (i = 0; i < plane_num; i++)
        {
            ret_img_height[i] = img_height[i];
        }
    }

exit:
    if (fp)
    {
        viv_os_file_close(fp);
    }

    return status;
}
#endif
int static GalSaveDIBitmap(const char *filename, BMPINFO *info, unsigned char *bits, gctUINT stride)
{
    gctPOINTER fp;                      /* Open file pointer */
    unsigned int    size,                     /* Size of file */
        infosize,                 /* Size of bitmap info */
        bitsize;                  /* Size of bitmap pixels */
    gctINT i;
    gctUINT bmpStride  =  info->bmiHeader.biWidth * ((info->bmiHeader.biBitCount + 7) / 8);

    if (bmpStride > stride)
    {
        return -1;
    }

    fp = viv_os_file_open((gctCHAR *)filename, vivFILE_WRITEB);

    if (!fp)
    {
        return -1;
    }

    /* Figure out the bitmap size */
    if (info->bmiHeader.biSizeImage == 0)
    {
        bitsize =  info->bmiHeader.biWidth *
            ((info->bmiHeader.biBitCount + 7) / 8) *
            abs(info->bmiHeader.biHeight);
    }
    else
    {
        bitsize = info->bmiHeader.biSizeImage;
    }

    /* Figure out the header size */
    infosize = sizeof(BMPINFOHEADER);
    switch (info->bmiHeader.biCompression)
    {
    case BIT_BITFIELDS :
        infosize += 12; /* Add 3 RGB doubleword masks */
        if (info->bmiHeader.biClrUsed == 0)
            break;
        /*no break here*/
    case BIT_RGB :
        if (info->bmiHeader.biBitCount > 8 &&
            info->bmiHeader.biClrUsed == 0)
            break;
        /*no break here*/
    case BIT_RLE8 :
    case BIT_RLE4 :
        if (info->bmiHeader.biClrUsed == 0)
            infosize += (1 << info->bmiHeader.biBitCount) * 4;
        else
            infosize += info->bmiHeader.biClrUsed * 4;
        break;
    }

    size = sizeof(BMPFILEHEADER) + infosize + bitsize;

    /* Write the file header, bitmap information, and bitmap pixel data... */
    dc_os_file_write_word(fp, BF_TYPE);        /* bfType */
    dc_os_file_write_dword(fp, size);          /* bfSize */
    dc_os_file_write_word(fp, 0);              /* bfReserved1 */
    dc_os_file_write_word(fp, 0);              /* bfReserved2 */
    dc_os_file_write_dword(fp, 14 + infosize); /* bfOffBits */

    dc_os_file_write_dword(fp, info->bmiHeader.biSize);
    dc_os_file_write_long(fp, info->bmiHeader.biWidth);
    dc_os_file_write_long(fp, abs(info->bmiHeader.biHeight)/*info->bmiHeader.biHeight*/); // bugbug: keep height positive
    dc_os_file_write_word(fp, info->bmiHeader.biPlanes);
    dc_os_file_write_word(fp, info->bmiHeader.biBitCount);
    dc_os_file_write_dword(fp, info->bmiHeader.biCompression);
    dc_os_file_write_dword(fp, info->bmiHeader.biSizeImage);
    dc_os_file_write_long(fp, info->bmiHeader.biXPelsPerMeter);
    dc_os_file_write_long(fp, info->bmiHeader.biYPelsPerMeter);
    dc_os_file_write_dword(fp, info->bmiHeader.biClrUsed);
    dc_os_file_write_dword(fp, info->bmiHeader.biClrImportant);

    if (infosize > 40)
    {
        int n = (infosize - 40) / 4;
        unsigned int *p = (unsigned int *)(info->bmiColors);

        while (n > 0)
        {
            dc_os_file_write_dword(fp, *p);
            p++;
            n--;
        }
    }

    /* gcmASSERT(infosize + 14 == dc_os_file_tell(fp)); */

    for (i = 0; i < abs(info->bmiHeader.biHeight); i++)
    {
        if (info->bmiHeader.biHeight > 0)
        {
                viv_os_file_write(bits + stride * i, bmpStride, fp);
        }
        else
        {

            {
                viv_os_file_write(bits + stride * (abs(info->bmiHeader.biHeight) - 1 - i), bmpStride, fp);
            }
        }
    }

    /* OK, everything went fine - return... */
    viv_os_file_close(fp);
    return (0);
}

gctBOOL GalSaveDIB(
    gctPOINTER bits,
    gceSURF_FORMAT  format,
    gctUINT stride,
    gctUINT width,
    gctUINT height,
    const char *bmpFileName)
{
    gctBOOL ret = gcvFALSE;

    if (bits && bmpFileName && bmpFileName[0])
    {
        BMPINFO bitmap;
        gctINT bitCount;

        switch (format)
        {
        case 0:
            bitmap.mask[0] = 0x00FF0000;
            bitmap.mask[1] = 0x0000FF00;
            bitmap.mask[2] = 0x000000FF;
            bitCount = 32;
            break;

        default:
            /* can not save and display */
            return gcvFALSE;
        }

        /* Fill in the BITMAPINFOHEADER information. */
        bitmap.bmiHeader.biSize = sizeof(bitmap.bmiHeader);
        bitmap.bmiHeader.biWidth = width;
        bitmap.bmiHeader.biHeight = -(gctINT)height;
        bitmap.bmiHeader.biPlanes = 1;
        bitmap.bmiHeader.biBitCount = bitCount;
        bitmap.bmiHeader.biCompression = BIT_BITFIELDS;
        bitmap.bmiHeader.biSizeImage = 0;
        bitmap.bmiHeader.biXPelsPerMeter = 0;
        bitmap.bmiHeader.biYPelsPerMeter = 0;
        bitmap.bmiHeader.biClrUsed = 0;
        bitmap.bmiHeader.biClrImportant = 0;

        if (GalSaveDIBitmap(bmpFileName, (BMPINFO *)&bitmap, bits, stride) == 0)
        {
            ret = gcvTRUE;
        }
    }

    return ret;
}

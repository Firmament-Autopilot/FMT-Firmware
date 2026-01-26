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


#include "viv_dc_hardware.h"
#include "viv_dc_os.h"
#include "viv_dc_database.h"
#include "dc_layer_feature.h"

#if vivCHIP_MODEL
#include "viv_common_reg.h"
#endif
#include "viv_dc_reg.h"

#if vivENABLE_SEC
#include "viv_dc_hardware_sec.h"
#endif

#if vivENABLE_MMU
#include "viv_dc_mmu.h"
#endif

#if (vivENABLE_ADDRESS_40BITS || vivENABLE_LAYER_DECOMPRESS)
#define UPPER_ALIGN(x, alignment) ( (x + alignment - 1) & ~(alignment - 1) )
#endif

#ifndef BIT
#define BIT(x) (1UL<<x)
#endif

typedef struct _viv_dc_node
{
    gctUINT32  address;
    gctUINT32  size;
    gctUINT32  layer_id;
}
viv_dc_node ;

gctBOOL chip_feature[vivFEATURE_COUNT];
//static gctUINT32 layer_count; // IFX: Fix IAR Warning - Variable set but not used.
static gctUINT32 chip_id;

/* YUV601 to RGB with limite range */
static gctINT YUV2RGB_LR601[YUV2RGB_LR_COEF_NUM] =
{
    297,  0,       407,   297,
    -100, -207,    297,   514,
    0,    -56848, 34544,  -70544,
    16,   235,     16,     235
};

/* YUV709 to RGB with limite range */
static gctINT YUV2RGB_LR709[YUV2RGB_LR_COEF_NUM] =
{
    297, 0,       457,   297,
    -54, -136,    297,   539,
    0,    -63248, 19568, -73744,
    16,   235,     16,     235
};

/* YUV2020 to RGB with limite range */
static gctINT YUV2RGB_LR2020[YUV2RGB_LR_COEF_NUM] =
{
    1196,    0,       1724,     1196,
    -192,   -668,     1196,     2200,
    0,      -959232,  363776,  -1202944,
    64,      940,     64,       960
};

/* YUV601 to RGB with full range */
static gctINT YUV2RGB_FR601[YUV2RGB_FR_COEF_NUM] =
{
    255, 0,       358,   255,
    -88, -182,    255,   452,
    0,    -45824, 34560, -57856
};

/* YUV709 to RGB with full range */
static gctINT YUV2RGB_FR709[YUV2RGB_FR_COEF_NUM] =
{
    255, 0,       402,   255,
    -48, -119,    255,   473,
    0,    -51456, 21376, -60544
};

/* YUV2020 to RGB with full range */
static gctINT YUV2RGB_FR2020[YUV2RGB_FR_COEF_NUM] =
{
    1023, 0,       1509,   1023,
    -168, -585,    1023,   1925,
    0,    -772608, 385536, -985600
};

#if vivENABLE_DISPLAY_R2Y
/* RGB to YUV601 with limite range */
static gctINT RGB2YUV_LR601[RGB2YUV_COEF_NUM] =
{
    66,  129,  25,
    -38, -74, 112,
    112,  -94, -18,
    16,   128,  128
};

/* RGB to YUV709 with limite range */
static gctINT RGB2YUV_LR709[RGB2YUV_COEF_NUM] =
{
    47,  157,  16,
    -26, -86, 112,
    112,  -102, -10,
    16,   128,  128
};

/* RGB to YUV2020 with limite range */
static gctINT RGB2YUV_LR2020[RGB2YUV_COEF_NUM] =
{
    230,  594,  52,
    -125, -323, 448,
    448,  -412, -36,
    64,   512,  512
};

/* RGB to YUV601 with full range */
static gctINT RGB2YUV_FR601[RGB2YUV_COEF_NUM] =
{
    77,  150,  29,
    -43, -84, 128,
    128,  -107, -21,
    0,    128,  128
};

/* RGB to YUV709 with full range */
static gctINT RGB2YUV_FR709[RGB2YUV_COEF_NUM] =
{
    54,  183,  19,
    -29, -99, 128,
    128,  -116, -12,
    0,    128,  128
};

/* RGB to YUV2020 with full range */
static gctINT RGB2YUV_FR2020[RGB2YUV_COEF_NUM] =
{
    269,  694,  61,
    -143, -369, 512,
    512,  -471, -41,
    0,    512,  512
};
#endif

#if vivENABLE_DISPLAY_R2Y
/* RGB709 to RGB2020 */
static gctINT RGB2RGB_2020[RGB2RGB_COEF_NUM] =
{
    10279,  5395,   709,
    1132,   15065,  187,
    269,    1442,   14674
};

/* RGB2020 to RGB709 */
static gctINT RGB2RGB_709[RGB2RGB_COEF_NUM] =
{
    27206,  -9629, -1193,
    -2041,  18562, -138,
    -298,   -1648, 18329
};
#endif

#if vivENABLE_ADDRESS_40BITS
static gctINT32 _vs_get_ts_buf_size(gctINT32 buf_size, gctINT16 tile_size)
{
    gctINT32 ts_size = UPPER_ALIGN(buf_size, 512) / 512;

    if (tile_size == 128)
        ts_size = ts_size << 1;

    return ts_size;
}

static gctINT32 _vs_cal_bo_size(viv_dc_core *core, gctINT8 layerId, gctINT8 index)
{
    gctINT16 tile_size;
    gctINT32 ts_buf_size, stride;
    gctINT64 aligned_area;
    viv_cache_mode cacheMode;

    cacheMode = core->display.layers[layerId].dec_cache_mode;
    tile_size = (cacheMode == vivCACHE_NONE) ? 0 : (cacheMode == vivCACHE_128) ? 128 : 256;
    stride = core->display.layers[layerId].buffer.stride[index];
    aligned_area = UPPER_ALIGN(stride, tile_size) * core->display.layers[layerId].buffer.height;
    /* Align ts buf size to stride, so we can get integer height */
    ts_buf_size = _vs_get_ts_buf_size(aligned_area, tile_size);

    return ts_buf_size;
}

static gctBOOL isIntersection(viv_dc_node node1,viv_dc_node node2)
{
    if((node1.address <= node2.address && (node1.address + node1.size) >= node2.address && (node1.address + node1.size) <= (node2.address + node2.size))
        || (node2.address <= node1.address && (node2.address + node2.size) >= node1.address && (node2.address + node2.size) <= (node1.address + node1.size)) )
        return vivTRUE;
    else
        return vivFALSE;
}
#endif

#if vivENABLE_LAYER_DECOMPRESS
gctINT _viv_align_size(
    viv_input_format_type format,
    gctUINT tile_mode,
    gctBOOL compressed,
    viv_cache_mode cache_mode,
    gctUINT *width,
    gctUINT *height
    )
{
    switch (tile_mode)
    {
        case vivTILED4X4:
            switch (format)
            {
                case vivYUV444:
                case vivYUV444_10BIT:
                    *width = UPPER_ALIGN(*width, 32);
                    *height = UPPER_ALIGN(*height, 4);
                    break;
                case vivNV12:
                case vivNV12_10BIT:
                    *width = UPPER_ALIGN(*width, 64);
                    *height = UPPER_ALIGN(*height, 4);
                    break;
                default:
                    viv_os_print("current format is not supported\n");
                    return vivSTATUS_NOT_SUPPORT;
                    break;
            }
            break;
        case vivTILED8X8:
            *width = UPPER_ALIGN(*width, 16);
            *height = UPPER_ALIGN(*height, 8);
            break;
        case vivSUPER_TILED_X:
        case vivSUPER_TILED_Y:
            *width = UPPER_ALIGN(*width, 64);
            *height = UPPER_ALIGN(*height, 64);
            break;
        case vivLINEAR:
            if (compressed)
            {
                switch (format)
                {
                    case vivARGB8888:
                    case vivXRGB8888:
                    case vivARGB2101010:
                        if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 64);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 32);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        break;
                    case vivRGB565:
                    case vivARGB1555:
                    case vivXRGB1555:
                    case vivARGB4444:
                    case vivXRGB4444:
                        if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 128);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 64);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        break;
                    case vivYUY2:
                    case vivUYVY:
                        if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 128);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 64);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        break;
                    case vivNV12:
                    case vivNV21:
                        if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 128);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 256);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        break;
                    case vivP010:
                        if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 64);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 128);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        break;
                    case vivNV16:
                        if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 128);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 256);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        break;
                    case vivYV12:
                    case vivYU12:
                        if (cache_mode == vivCACHE_128)
                        {
                            *width = UPPER_ALIGN(*width, 128);
                            *height = UPPER_ALIGN(*height, 1);
                        }
                        else if (cache_mode == vivCACHE_256)
                        {
                            *width = UPPER_ALIGN(*width, 512);
                            *height = UPPER_ALIGN(*height, 1);
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

gctINT _calculate_buffer_size(
    viv_input_format_type format,
    gctUINT image_width,
    gctUINT image_height,
    gctUINT *width,
    gctUINT *height
    )
{
    gctINT i;

    for (i = 0; i < 3; i++)
    {
        width[i] = 0;
        height[i] = 0;
    }

    /* Check the type. */
    switch (format)
    {
        case vivYUY2:
            width[0] = image_width;
            height[0] = image_height;
            break;
        case vivUYVY:
            width[0] = image_width;
            height[0] = image_height;
            break;
        case vivYV12:
        case vivYU12:
            width[0] = image_width;
            height[0] = image_height;
            width[1] = width[2] = image_width / 2;
            height[1] = height[2] = image_height / 2;
            break;
        case vivNV16:
            width[0] = image_width;
            height[0] = image_height;
            width[1] = image_width / 2;
            height[1] = image_height;
            break;
        case vivNV12:
        case vivNV21:
            width[0] = image_width;
            height[0] = image_height;
            width[1] = image_width / 2;
            height[1] = image_height / 2;
            break;
        case vivP010:
            width[0] = image_width;
            height[0] = image_height;
            width[1] = image_width / 2;
            height[1] = image_height / 2;
            break;
        default:
            width[0] = image_width;
            height[0] = image_height;
            break;
    }

    return 0;
}
#endif

#if (vivENABLE_DISPLAY_DP && vivENABLE_DISPLAY_R2Y)
gctBOOL _viv_is_dp_yuv_format (
    gctUINT32 format
    )
{
    gctBOOL dp_yuv = vivFALSE;

    switch(format){
        case vivDPYUV420B8CFG1:
        case vivDPYUV420B8CFG2:
        case vivDPYUV420B8CFG3:
        case vivDPYUV422B8CFG1:
        case vivDPYUV422B8CFG2:
        case vivDPYUV444B8CFG1:
        case vivDPYUV444B8CFG2:
        case vivDPYUV444B8CFG3:
        case vivDPYUV420B10CFG1:
        case vivDPYUV420B10CFG2:
        case vivDPYUV420B10CFG3:
        case vivDPYUV422B10CFG1:
        case vivDPYUV422B10CFG2:
        case vivDPYUV444B10CFG1:
        case vivDPYUV444B10CFG2:
        case vivDPYUV444B10CFG3:
            dp_yuv = vivTRUE;
            break;

        default:
            break;
    }
    return dp_yuv;
}
#endif

gctBOOL _viv_is_yuv_format(
    viv_input_format_type format
    )
{
    gctBOOL is_yuv = vivFALSE;

    switch(format){
        case vivNV21:
        case vivYU12:
        case vivYUY2:
        case vivUYVY:
        case vivYV12:
        case vivNV12:
        case vivNV16:
        case vivP010:
        case vivNV12_10BIT:
        case vivYUV444:
        case vivYUV444_10BIT:
            is_yuv = vivTRUE;
            break;

        default:
            break;
    }
    return is_yuv;
}

gctUINT _viv_api_layer_to_hw_layer(
    gctUINT id
    )
{
    if(id >= chip_feature[vivFEATURE_LAYER_COUNT])
    {
        return 0;
    }
    return _DCQueryLayerHWId(id);
}

vivSTATUS viv_conf_dc_reset(
    viv_dc_core *core
    )
{
    vivSTATUS ret = vivSTATUS_OK;

    viv_init_reg_config();
#if vivENABLE_SEC
    viv_init_sec_reg_config();
#endif

    viv_hw_dc_reset(core->hardware);

    //layer_count = _DCQueryLayerCount(); //IFX: Fix warning variable "layer_count" was set but never used

#if vivENABLE_MMU
    dcMMU_Config(core->hw_sec, core->mmu);
#endif
    return ret;
}

#if vivENABLE_LAYER_DECOMPRESS
/*******************************************************************************
** DEC400 Configuration
*/
gctVOID viv_conf_dec400_config(
    viv_dc_core *core,
    gctUINT layerId
    )
{
    viv_input_format_type dcFormat;
    viv_tiling_type dcTiling;
    viv_cache_mode cacheMode;
    gctADDRESS bufferBase[3] = {0};
    gctADDRESS tileStatusAddress[3] = {0};
    gctADDRESS bufferEnd[3] = {0};
    gctUINT32 streamBase = 0;
    gctUINT32 srcWidth, srcHeight;
    gctUINT32 planeWidth[3] = {0};
    gctUINT32 planeHeight[3] = {0};
    gctUINT32 fc_value = 0;
    gctUINT32 i, j;
    gctUINT32 hw_id = 0;

    fc_value = (core->display.layers[layerId].clear_color.a << 24
               |core->display.layers[layerId].clear_color.r << 16
               |core->display.layers[layerId].clear_color.g << 8
               |core->display.layers[layerId].clear_color.b);
    dcFormat = core->display.layers[layerId].buffer.format;
    dcTiling = core->display.layers[layerId].buffer.tiling;
    cacheMode = core->display.layers[layerId].dec_cache_mode;
    srcWidth = core->display.layers[layerId].buffer.width;
    srcHeight = core->display.layers[layerId].buffer.height;

    _viv_align_size(dcFormat, dcTiling, core->display.layers[layerId].dec_enable, cacheMode, &srcWidth, &srcHeight);
    _calculate_buffer_size(dcFormat, srcWidth, srcHeight, planeWidth, planeHeight);

    hw_id = _viv_api_layer_to_hw_layer(layerId);
    switch (hw_id)
    {
        case 0:
            streamBase = 0;
            break;
        case 1:
            streamBase = 3;
            break;
        case 2:
            streamBase = 6;
            break;
        case 3:
            streamBase = 16;
            break;
        case 4:
            streamBase = 19;
            break;
        case 5:
            streamBase = 22;
            break;
        default:
            break;
    }

    switch(dcFormat)
    {
        /* use one streams */
        case vivXRGB8888:
        case vivARGB8888:
        case vivRGB565:
        case vivARGB1555:
        case vivXRGB1555:
        case vivARGB4444:
        case vivXRGB4444:
        case vivARGB2101010:
        case vivYUY2:
        case vivUYVY:
            for(j = 0; j < 1; j++)
            {
                bufferBase[j] = core->display.layers[layerId].buffer.phyAddress[j];
                bufferEnd[j] = bufferBase[j] + core->display.layers[layerId].buffer.stride[j] * planeHeight[j] - 1;
                tileStatusAddress[j] = core->display.layers[layerId].tile_status_biffer.tileStatusHWAddress[j];
            }

#if vivENABLE_SEC
            if(core->display.layer_security[layerId])
            {
                viv_hw_sec_dec400_stream_set(
                    core->hw_sec,
                    bufferBase[0],
                    bufferEnd[0],
                    tileStatusAddress[0],
                    dcFormat,
                    dcTiling,
                    cacheMode,
                    streamBase,
                    fc_value);

                for(i = 1; i < 3; i++)
                {
                    viv_hw_sec_dec400_stream_disable(core->hw_sec, streamBase + i);
                }
            }
            else
#endif
            {
                viv_hw_dec400_stream_set(
                    core->hardware,
                    bufferBase[0],
                    bufferEnd[0],
                    tileStatusAddress[0],
                    dcFormat,
                    dcTiling,
                    cacheMode,
                    streamBase,
                    fc_value);

                for(i = 1; i < 3; i++)
                {
                    viv_hw_dec400_stream_disable(core->hardware, streamBase + i);
                }
            }
            break;

        /* use two streams */
        case vivNV12:
        case vivNV21:
        case vivNV16:
        case vivP010:
            for(j = 0; j < 2; j++)
            {
                bufferBase[j] = core->display.layers[layerId].buffer.phyAddress[j];
                bufferEnd[j] = bufferBase[j] + core->display.layers[layerId].buffer.stride[j] * planeHeight[j] -1;
                tileStatusAddress[j] = core->display.layers[layerId].tile_status_biffer.tileStatusHWAddress[j];
            }

#if vivENABLE_SEC
            if(core->display.layer_security[layerId])
            {
                for(i = 0; i < 2; i++)
                {
                    viv_hw_sec_dec400_stream_set(
                        core->hw_sec,
                        bufferBase[i],
                        bufferEnd[i],
                        tileStatusAddress[i],
                        dcFormat,
                        dcTiling,
                        cacheMode,
                        streamBase + i,
                        fc_value);
                }

                viv_hw_sec_dec400_stream_disable(core->hw_sec, streamBase+2);
            }
            else
#endif
            {
                for(i = 0; i < 2; i++)
                {
                    viv_hw_dec400_stream_set(
                        core->hardware,
                        bufferBase[i],
                        bufferEnd[i],
                        tileStatusAddress[i],
                        dcFormat,
                        dcTiling,
                        cacheMode,
                        streamBase + i,
                        fc_value);
                }

                viv_hw_dec400_stream_disable(core->hardware, streamBase+2);
            }
            break;

        /* use three streams */
        case vivYV12:
        case vivYU12:
            for(j = 0; j < 3; j++)
            {
                bufferBase[j] = core->display.layers[layerId].buffer.phyAddress[j];
                bufferEnd[j] = bufferBase[j] + core->display.layers[layerId].buffer.stride[j] * planeHeight[j] -1;
                tileStatusAddress[j] = core->display.layers[layerId].tile_status_biffer.tileStatusHWAddress[j];
            }
#if vivENABLE_SEC
            if(core->display.layer_security[layerId])
            {
                for(i = 0; i < 3; i++)
                {
                    viv_hw_sec_dec400_stream_set(
                        core->hw_sec,
                        bufferBase[i],
                        bufferEnd[i],
                        tileStatusAddress[i],
                        dcFormat,
                        dcTiling,
                        cacheMode,
                        streamBase + i,
                        fc_value);
                }
            }
            else
#endif
            {
                for(i = 0; i < 3; i++)
                {
                    viv_hw_dec400_stream_set(
                        core->hardware,
                        bufferBase[i],
                        bufferEnd[i],
                        tileStatusAddress[i],
                        dcFormat,
                        dcTiling,
                        cacheMode,
                        streamBase + i,
                        fc_value);
                }
            }
            break;
        default:
            break;
    }
}

gctVOID viv_conf_dec400_disable(
    viv_dc_core *core,
    gctUINT layerId
    )
{
    gctUINT32 i, streamBase = 0;
    gctUINT32 hw_id = 0;

    hw_id = _viv_api_layer_to_hw_layer(layerId);
    switch (hw_id)
    {
        case 0:
            streamBase = 0;
            break;
        case 1:
            streamBase = 3;
            break;
        case 2:
            streamBase = 6;
            break;
        case 3:
            streamBase = 16;
            break;
        case 4:
            streamBase = 19;
            break;
        case 5:
            streamBase = 22;
            break;
        default:
            break;
    }
#if vivENABLE_SEC
    if(core->display.layer_security[layerId])
    {
        for(i = 0; i < 3; i++)
        {
            viv_hw_sec_dec400_stream_disable(core->hw_sec, streamBase + i);
        }
    }
    else
#endif
    {
        for(i = 0; i < 3; i++)
        {
            viv_hw_dec400_stream_disable(core->hardware, streamBase + i);
        }
    }
}

gctVOID viv_conf_dec400_commit(
    viv_dc_core *core
    )
{
    gctUINT i = 0;
    gctBOOL compressed = 0;

    viv_hw_dec400_init(core->hardware);

#if vivENABLE_SEC
    viv_hw_sec_dec400_init(core->hw_sec);
#endif

    for (i = 0; i < chip_feature[vivFEATURE_LAYER_COUNT]; i++)
    {
        if (core->display.layer_dirty[i] == vivTRUE)
        {
            compressed = core->display.layers[i].dec_enable;

            if(!compressed)
            {
                viv_conf_dec400_disable(core, i);
            }
            else
            {
                viv_conf_dec400_config(core, i);
            }
        }
    }
}
#endif

/*******************************************************************************
** Layer
*/
gctVOID viv_conf_layer_enable(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable
    )
{
    core->display.layers[id].layer_enable = !!enable;

    core->display.layer_dirty[id] = vivTRUE;
}

#if vivENABLE_SEC
vivSTATUS viv_conf_layer_security(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    core->display.layer_security[id] = !!enable;

    core->display.layer_dirty[id] = vivTRUE;
    return ret;
}
#endif

gctVOID viv_conf_layer_set_buffer(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_buffer *buffer
    )
{
    viv_os_memcpy(&core->display.layers[id].buffer, buffer, sizeof(viv_dc_buffer));
    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_layer_set_colorkey(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_color colorkey,
    viv_dc_color colorkey_high,
    gctBOOL transparency
    )
{
    core->display.layers[id].colorkey = colorkey;
    core->display.layers[id].colorkey_high = colorkey_high;
    core->display.layers[id].transparency = transparency;

    core->display.layer_dirty[id] = vivTRUE;
}

#if vivENABLE_LAYER_ROT
gctVOID viv_conf_layer_set_rotation(
    viv_dc_core *core,
    gctUINT id,
    viv_rotation_type rotation
    )
{
    core->display.layers[id].rotation = rotation;

    core->display.layer_dirty[id] = vivTRUE;
}
#endif

gctVOID viv_conf_layer_set_csc(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_layer layer
    )
{
    gctBOOL input_yuv = 0;
    gctUINT hw_id = 0;
#if vivENABLE_DISPLAY_R2Y
    gctUINT display_id = 0;
    gctBOOL display_yuv = 0;
    viv_csc_mode y2r_mode = (viv_csc_mode)0, r2y_mode = (viv_csc_mode)0;
#endif

    input_yuv = _viv_is_yuv_format(layer.buffer.format);
#if (vivENABLE_DISPLAY_DP && vivENABLE_DISPLAY_R2Y)
    display_id = (gctUINT)layer.display_id;
    display_yuv = _viv_is_dp_yuv_format(core->display.output[display_id].format);
#endif
    hw_id = _viv_api_layer_to_hw_layer(id);

    if (input_yuv)
    {
        /* If not set, use default YUV2020 to RGB yuvClamp enabled conversion parameters */
        if(!layer.y2r_dirty)
        {
            viv_layer_conf_y2r(core, id, 1, vivCSC_BT2020, vivNULL, 0);
        }

#if vivENABLE_SEC
        if (core->display.layer_security[id])
        {
            viv_hw_sec_layer_y2r_set_config(core->hw_sec, hw_id, core->display.layers[id]);
        }
        else
#endif
        {
            viv_hw_layer_y2r_set_config(core->hardware, hw_id, core->display.layers[id]);
        }
    }

#if vivENABLE_DISPLAY_R2Y
    /* To judge whether should must set layer r2r and ensure y2r and r2y color space have matched. */
    if(input_yuv && display_yuv && (!core->display.layers[id].r2r_dirty))
    {
        y2r_mode = core->display.layers[id].y2r_mode;

        if(!core->display.r2y_dirty[display_id])
        {
            /* use default RGB to YUV2020 limit range conversion parameters */
            viv_display_conf_set_output_csc(core, layer.display_id, 0, vivCSC_BT2020, vivNULL, 0);
        }

        r2y_mode = core->display.r2y_mode[display_id];
        /* If y2r and r2y csc mode can not match, set the layer r2r */
        if(y2r_mode != r2y_mode)
        {
            /* As long as one of y2r/r2r/r2y was setted in vivCSC_USER_DEF, the others should be setted in vivCSC_USER_DEF. */
            if((y2r_mode == vivCSC_USER_DEF) || (r2y_mode == vivCSC_USER_DEF))
            {
                viv_layer_conf_r2r(core, id, 1, vivCSC_USER_DEF, vivNULL, 0);
            }
            viv_layer_conf_r2r(core, id, 1, r2y_mode, vivNULL, 0);
        }
    }
#endif

    if (core->display.layers[id].r2r_dirty)
    {
#if vivENABLE_SEC
        if (core->display.layer_security[id])
        {
            viv_hw_sec_layer_r2r_set_config(core->hw_sec, hw_id, core->display.layers[id]);
        }
        else
#endif
        {
            viv_hw_layer_r2r_set_config(core->hardware, hw_id, core->display.layers[id]);
        }
    }
}

#if vivENABLE_LAYER_DECOMPRESS
gctVOID viv_conf_layer_set_decompress(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable,
    viv_tilestatus_buffer buffer
    )
{
    core->display.layers[id].dec_enable = enable;
    core->display.layers[id].tile_status_biffer = buffer;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_layer_set_cache_mode(
    viv_dc_core *core,
    gctUINT id,
    viv_cache_mode mode
    )
{
    core->display.layers[id].dec_cache_mode = mode;

    core->display.layer_dirty[id] = vivTRUE;
}
#endif

gctVOID viv_conf_layer_set_watermark(
    viv_dc_core *core,
    gctUINT id,
    gctUINT32 value
    )
{
    core->display.layers[id].watermark = value;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_layer_set_alpha(
    viv_dc_core *core,
    gctUINT id,
    viv_layer_alpha_mode alpha
    )
{
    core->display.layers[id].alpha_mode = alpha;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_layer_set_poterbuff_blend_mode(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable,
    viv_porter_duff_mode mode
    )
{
    core->display.layers[id].blend_enable = !!enable;
    core->display.layers[id].blend_mode = mode;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_layer_set_zorder(
    viv_dc_core *core,
    gctUINT id,
    gctUINT8 value
    )
{
    core->display.layers[id].zorder = value;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_layer_set_display(
    viv_dc_core *core,
    gctUINT id,
    viv_display display_id
    )
{
    core->display.layers[id].display_id = display_id;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_conf_display_set_size(
    viv_dc_core *core,
    viv_display display,
    viv_display_size_type type
    )
{
    core->display.size[display] = type;

    core->display.display_dirty[display] = vivTRUE;
}

gctVOID viv_conf_display_set_custom_size(
    viv_dc_core *core,
    viv_display display,
    gctUINT hactive,
    gctUINT hsync_start,
    gctUINT hsync_end,
    gctUINT htotal,
    gctUINT vactive,
    gctUINT vsync_start,
    gctUINT vsync_end,
    gctUINT vtotal
    )
{
    core->display.size[display] = vivDISPLAY_CUSTOMIZED;

    core->display.display_dirty[display] = vivTRUE;

    core->display.dpy_hline = hactive;
    core->display.dpy_vline = vactive;
    core->display.dpy_htotal = htotal;
    core->display.dpy_vtotal = vtotal;
    core->display.dpy_hsync_start = hsync_start;
    core->display.dpy_vsync_start = vsync_start;
    core->display.dpy_hsync_end = hsync_end;
    core->display.dpy_vsync_end = vsync_end;
}

gctVOID viv_display_conf_set_output(
    viv_dc_core *core,
    viv_display display,
    gctBOOL enable,
    viv_output output
    )
{
    core->display.display_enable[display] = enable;
    viv_os_memcpy(&core->display.output[display], &output, sizeof(viv_output));

    core->display.display_dirty[display] = vivTRUE;
}

gctVOID viv_display_conf_dbi_reset(
    viv_dc_core *core
    )
{
    viv_hw_display_dbi_reset(core->hardware);
}

gctVOID viv_display_conf_dbi_set_config(
    viv_dc_core *core,
    viv_display display,
    viv_dbi_type dbi_type
    )
{
    core->display.dbi_type[display] = dbi_type;

    core->display.display_dirty[display] = vivTRUE;
}

#if vivENABLE_DISPLAY_R2Y
gctVOID viv_display_conf_set_output_csc(
    viv_dc_core *core,
    viv_display display,
    gctBOOL full_range,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    )
{
    gctUINT i;
    core->display.r2y_mode[display] = mode;

    switch (mode)
    {
        case vivCSC_USER_DEF:
            viv_os_memset(core->os, core->display.r2y_coef[display], 0, sizeof(core->display.r2y_coef[display]));
            viv_os_memcpy(core->display.r2y_coef[display], coef, sizeof(gctINT) * num);
            break;

        case vivCSC_BT601:
            if(full_range)
            {
                for(i = 0; i < RGB2YUV_COEF_NUM; i++)
                    core->display.r2y_coef[display][i] = RGB2YUV_FR601[i];
            }
            else
            {
                for(i = 0; i < RGB2YUV_COEF_NUM; i++)
                    core->display.r2y_coef[display][i] = RGB2YUV_LR601[i];
            }
            break;

        case vivCSC_BT709:
            if(full_range)
            {
                for(i = 0; i < RGB2YUV_COEF_NUM; i++)
                    core->display.r2y_coef[display][i] = RGB2YUV_FR709[i];
            }
            else
            {
                for(i = 0; i < RGB2YUV_COEF_NUM; i++)
                    core->display.r2y_coef[display][i] = RGB2YUV_LR709[i];
            }
            break;

        case vivCSC_BT2020:
            if(full_range)
            {
                for(i = 0; i < RGB2YUV_COEF_NUM; i++)
                    core->display.r2y_coef[display][i] = RGB2YUV_FR2020[i];
            }
            else
            {
                for(i = 0; i < RGB2YUV_COEF_NUM; i++)
                    core->display.r2y_coef[display][i] = RGB2YUV_LR2020[i];
            }
            break;

        default:
            break;
    }

    core->display.r2y_dirty[display] = vivTRUE;
}

gctVOID viv_conf_output_csc_commit(
    viv_dc_core *core
    )
{
    gctUINT i;
    gctBOOL dp_yuv;

    for (i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        dp_yuv = _viv_is_dp_yuv_format(core->display.output[i].format);

        if(dp_yuv)
        {
            if(!core->display.r2y_dirty[i])
            {
                /* use default RGB to YUV2020 limit range conversion parameters */
                viv_display_conf_set_output_csc(core, (viv_display)i, 0, vivCSC_BT2020, vivNULL, 0);
            }

            viv_hw_set_output_csc(
                core->hardware,
                (viv_display)i,
                core->display.r2y_coef[i]
                );
            core->display.r2y_enable[i] = vivTRUE;
        }
        else
        {
            core->display.r2y_enable[i] = vivFALSE;
        }
    }
}
#endif

#if vivENABLE_WRITEBACK
gctVOID viv_display_conf_set_dest(
    viv_dc_core *core,
    gctBOOL enable,
    viv_display display,
    viv_dc_buffer *buffer_ptr,
    viv_write_back_type type
    )
{
    core->display.writeback_enable[display] = !!enable;
    core->display.mem2mem[display] = !!enable;

    if(enable)
    {
        viv_os_memcpy(&core->display.writeback_buffer[display], buffer_ptr, sizeof(viv_dc_buffer));
        core->display.writeback_type[display] = type;
    }
    else
    {
        core->display.writeback_buffer[display].stride[0] = 0;
    }
    core->display.dest_dirty[display] = vivTRUE;
}

gctVOID viv_conf_dest_commit(
    viv_dc_core *core
    )
{
    gctUINT i;

    for(i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if(core->display.dest_dirty[i])
        {
            viv_hw_set_dest_address(
                core->hardware,
                core->display.writeback_enable[i],
                (viv_display)i,
                &core->display.writeback_buffer[i],
                core->display.writeback_type[i]
                );

            if(core->display.writeback_type[i] == vivWB_DEFAULT)
            {
#if vivENABLE_SEC
                viv_hw_sec_set_dest_address(
                    core->hw_sec,
                    core->display.writeback_enable[i],
                    (viv_display)i,
                    &core->display.writeback_buffer[i],
                    core->display.writeback_type[i]
                    );
#endif
            }

            viv_hw_set_dest_stride(core->hardware, (viv_display)i, core->display.writeback_buffer[i].stride[0]);
        }
    }
}

/*
** Set write back dither
*/
gctVOID viv_conf_set_write_back_dither(
    viv_dc_core *core,
    gctBOOL enable,
    viv_display display_id,
    gctUINT table_low,
    gctUINT table_high
    )
{
    core->display.wb_dither_enable[display_id] = enable;

    if(enable)
    {
        core->display.wb_table_low[display_id] = table_low;
        core->display.wb_table_high[display_id] = table_high;
    }
    else
    {
        core->display.wb_table_low[display_id] = 0;
        core->display.wb_table_high[display_id] = 0;
    }

    core->display.wb_dither_dirty[display_id] = vivTRUE;
}
#endif

gctVOID viv_layer_commit(
    viv_dc_core *core
    )
{
    gctUINT i = 0, id = 0;

    for (i = 0; i < chip_feature[vivFEATURE_LAYER_COUNT]; i++)
    {
        if (core->display.layer_dirty[i] == vivTRUE)
        {

            id = _viv_api_layer_to_hw_layer(i);
            viv_hw_layer_set_config(
                core->hardware,
                id,
                core->display.layers[i],
                core->display.gamma_enabled[core->display.layers[i].display_id]
                );
            viv_hw_layer_clear(
                core->hardware,
                id,
                core->display.layers[i]
                );
#if vivENABLE_LAYER_ROI
            viv_hw_layer_roi(
                core->hardware,
                id,
                core->display.layers[i]
                );
#endif
            viv_hw_layer_set_position(
                core->hardware,
                id,
                core->display.layers[i],
                core->display.size[core->display.layers[i].display_id]
                );
            viv_hw_layer_colorkey_set_config(
                core->hardware,
                id,
                core->display.layers[i]
                );
            viv_conf_layer_set_csc(
                core,
                i,
                core->display.layers[i]
                );
#if vivENABLE_LAYER_SCALE
            viv_hw_scale_set_config(
                core->hardware,
                id,
                core->display.layers[i].filter,
                core->display.layers[i].scale_factor_x,
                core->display.layers[i].scale_factor_y,
                core->display.layers[i].hor_kernel,
                core->display.layers[i].ver_kernel,
                core->display.layers[i].scale_enable
                );
#endif
            viv_hw_layer_set_watermark(
                core->hardware,
                id,
                core->display.layers[i].watermark
                );
            viv_hw_set_alpha(
                core->hardware,
                id,
                core->display.layers[i].alpha_mode
                );
            viv_hw_set_blend_mode(
                core->hardware,
                id,
                core->display.layers[i].blend_enable,
                core->display.layers[i].blend_mode,
                core->display.layers[i].alpha_mode
                );
#if vivENABLE_SEC
            if (core->display.layer_security[i])
            {
                /*Security layer settings*/
                viv_hw_sec_layer_set_config(
                    core->hw_sec,
                    id,
                    core->display.layers[i]
                    );
                viv_hw_sec_layer_clear(
                    core->hw_sec,
                    id,
                    core->display.layers[i]
                    );
                viv_hw_sec_layer_roi(
                    core->hw_sec,
                    id,
                    core->display.layers[i]
                    );
                viv_hw_sec_layer_set_position(
                    core->hw_sec,
                    id,
                    core->display.layers[i],
                    core->display.size[core->display.layers[i].display_id]
                    );
                viv_hw_sec_layer_colorkey_set_config(
                    core->hw_sec,
                    id,
                    core->display.layers[i]
                    );
                if (chip_feature[vivFEATURE_CSC_MOUDLE])
                {
                    viv_conf_layer_set_csc(
                        core,
                        i,
                        core->display.layers[i]
                        );
                }
                viv_hw_sec_scale_set_config(
                    core->hw_sec,
                    id,
                    core->display.layers[i].filter,
                    core->display.layers[i].scale_factor_x,
                    core->display.layers[i].scale_factor_y,
                    core->display.layers[i].hor_kernel,
                    core->display.layers[i].ver_kernel,
                    core->display.layers[i].scale_enable
                    );
                viv_hw_sec_layer_set_watermark(
                    core->hw_sec,
                    id,
                    core->display.layers[i].watermark
                    );
                viv_hw_sec_set_alpha(
                    core->hw_sec,
                    id,
                    core->display.layers[i].alpha_mode
                    );
                viv_hw_sec_set_blend_mode(
                    core->hw_sec,
                    id,
                    core->display.layers[i].blend_enable,
                    core->display.layers[i].blend_mode,
                    core->display.layers[i].alpha_mode
                    );
            }
#endif
        }
    }
}

gctVOID viv_background_commit(
    viv_dc_core *core
    )
{
    gctUINT i = 0;
#if vivENABLE_DISPLAY_CLRBAR
    int j = 0;
#endif
    for (i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if (vivTRUE == core->display.bg_dirty[i])
        {
            viv_hw_set_background(
                core->hardware,
                (viv_display)i, // IFX: Fix IAR Warning - Enumerated type mixed with Integer.
                core->display.bg_color[i]
                );
        }
#if vivENABLE_DISPLAY_CLRBAR
        for(j = 0; j < DC_COLORBAR_NUM; j++)
        {
            if(vivTRUE == core->display.colorbar_dirty[i][j])
            {
                viv_hw_set_color_bar(
                    core->hardware,
                    (viv_display)i,
                    core->display.colorbar_enabled[i][j],
                    j,
                    core->display.colorbar_range[i][j],
                    core->display.colorbar_color[i][j]
                    );
            }
        }
#endif
    }
}

gctVOID viv_cursor_commit(
    viv_dc_core *core
    )
{
    gctUINT i = 0;
    for (i = 0; i < chip_feature[vivFEATURE_CURSOR_COUNT]; i++)
    {
        if (vivTRUE == core->display.cursor_dirty[i])
        {
            viv_hw_cursor_hotspot(
                core->hardware,
                (viv_display)i,
                &core->display.cursors[i]
                );
            viv_hw_cursor_set(
                core->hardware,
                (viv_display)i,
                core->display.cursor_enable[i],
                &core->display.cursor_buffer[i],
                &core->display.cursors[i]
                );
#if vivENABLE_SEC
            if (core->display.cursor_security[i])
            {
                viv_hw_sec_cursor_hotspot(
                    core->hw_sec,
                    (viv_display)i,
                    &core->display.cursors[i]
                    );
                viv_hw_sec_cursor_set(
                    core->hw_sec,
                    (viv_display)i,
                    core->display.cursor_enable[i],
                    &core->display.cursor_buffer[i],
                    &core->display.cursors[i]
                    );
            }
#endif
        }
    }
}

gctVOID viv_qos_commit(
    viv_dc_core *core
    )
{
    if(vivTRUE == core->display.qos_dirty)
    {
        viv_hw_set_qos(
            core->hardware,
            core->display.qos_low,
            core->display.qos_high
            );
    }
}

gctVOID viv_dither_commit(
    viv_dc_core* core
    )
{
    gctUINT i;
    for (i = 0;i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if (vivTRUE == core->display.dither_dirtys[i])
        {
            viv_hw_dither_enable(
                core->hardware,
                (viv_display)i,
                core->display.dither_enabled[i],
                core->display.table_low[i],
                core->display.table_high[i]
                );
        }
#if vivENABLE_WRITEBACK
        if (vivTRUE == core->display.wb_dither_dirty[i])
        {
            viv_hw_set_write_back_dither(
                core->hardware,
                (viv_display)i,
                core->display.wb_dither_enable[i],
                core->display.wb_table_low[i],
                core->display.wb_table_high[i]
                );
        }
#endif
    }
}

#if vivENABLE_DISPLAY_CRC
gctVOID viv_crc_commit(
    viv_dc_core* core
    )
{
    gctUINT i = 0;

    for (i = 0; i < MAX_CRC_NUM; i++)
    {
        if (core->display.crc_dirty[i] == vivTRUE)
        {
            viv_hw_set_crc_range(
                core->hardware,
                i,
                core->display.crc_enable[i],
                core->display.crc_rect[i]
                );
        }
    }
}
#endif

gctVOID viv_conf_display_commit(
    viv_dc_core *core
    )
{
    gctUINT i;

    for(i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if(core->display.display_dirty[i])
        {
            if(core->display.size[i] == vivDISPLAY_CUSTOMIZED)
            {
                viv_hw_set_custom_display_size(
                    core->hardware,
                    (viv_display)i,
                    core->display.dpy_hline,
                    core->display.dpy_hsync_start,
                    core->display.dpy_hsync_end,
                    core->display.dpy_htotal,
                    core->display.dpy_vline,
                    core->display.dpy_vsync_start,
                    core->display.dpy_vsync_end,
                    core->display.dpy_vtotal,
                    core->display.mem2mem
                    );
            }
            else
            {
                viv_hw_display_set_size(
                    core->hardware,
                    (viv_display)i,
                    core->display.size[i],
                    core->display.mem2mem
                    );
            }
            viv_hw_display_set_output(
                core->hardware,
                (viv_display)i,
                core->display.display_enable[i],
                core->display.output[i],
                core->display.gamma_enabled[i],
#if vivENABLE_DISPLAY_R2Y
                core->display.r2y_enable[i],
#endif
                core->display.lut_enable[i]
                );

            if (core->display.output[i].type == vivDBI)
            {
                viv_hw_display_dbi_set_config(
                    core->hardware,
                    core->display.dbi_type[i],
                    core->display.output[i].format
                    );

                viv_hw_display_dbi_set_write(
                    core->hardware
                    );
            }
        }
    }
}

gctVOID viv_conf_output_dbi_reset(
    viv_dc_core *core
    )
{
    viv_hw_dbi_reset(core->hardware);
}

/*******************************************************************************
** Dither
*/
gctVOID viv_conf_dither_enable(
    viv_dc_core *core,
    viv_display display_id,
    gctBOOL enable
    )
{
    if (enable != core->display.dither_enabled[display_id])
    {
        core->display.dither_enabled[display_id] = enable;
        core->display.dither_dirtys[display_id] = vivTRUE;
    }
}

gctVOID viv_conf_dither_set_config(
    viv_dc_core *core,
    viv_display display_id,
    gctUINT table_low,
    gctUINT table_high
    )
{

    core->display.table_low[display_id]  = table_low;
    core->display.table_high[display_id] = table_high;
    core->display.dither_dirtys[display_id] = vivTRUE;
}

/*******************************************************************************
** Gamma Correction
*/
gctVOID viv_conf_enable_gamma(
    viv_dc_core *core,
    viv_display  disp_id,
    gctBOOL      enable
    )
{
    gctUINT id = (disp_id == vivDISPLAY_0 ? 0 : 1);

    if (enable != core->display.gamma_enabled[id])
    {
        core->display.gamma_enabled[id] = enable;
        core->display.gamma_dirtys[id] = vivTRUE;
    }
}

gctVOID viv_conf_gamma_set_config(
    viv_dc_core  *core,
    viv_display  disp_id,
    gctUINT   index,
    gctUINT16 red,
    gctUINT16 green,
    gctUINT16 blue
    )
{
    gctUINT id = (disp_id == vivDISPLAY_0 ? 0 : 1);

    if (index < GAMMA_TABLE_SIZE)
    {
        core->display.gamma_table[id].gammaTable[index][0] = red;
        core->display.gamma_table[id].gammaTable[index][1] = green;
        core->display.gamma_table[id].gammaTable[index][2] = blue;

        core->display.gamma_dirtys[id] = vivTRUE;
    }
}

gctVOID viv_conf_gamma_commit(
    viv_dc_core *core
    )
{
    gctUINT i;

    for(i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if(core->display.gamma_dirtys[i] == vivTRUE)
        {
            if(core->display.gamma_enabled[i])
            {
                /* TO DO
                 * PanelConfig, Set gamma enable filed
                 */
                viv_hw_gamma_set_config(core->hardware, i,
                                        core->display.gamma_table[i].gammaTable);
            }
            else
            {
                /* TO DO
                 * PanelConfig, Set gamma enable filed
                 */
                viv_os_memset(core->os, core->display.gamma_table[i].gammaTable, 0, sizeof(core->display.gamma_table[i].gammaTable));
                viv_hw_gamma_set_config(core->hardware, i,
                                        core->display.gamma_table[i].gammaTable);
            }
        }
    }
}

#if vivENABLE_DISPLAY_3DLUT
/*******************************************************************************
** sets 3d lut table.
*/
gctVOID viv_conf_3d_lut_set_config(
    viv_dc_core *core,
    viv_display display_id,
    gctBOOL enable,
    gctUINT32 index,
    gctUINT32 lut
    )
{
    core->display.lut_enable[display_id] = enable;
    core->display.lut_table[display_id][index] = lut;

    core->display.lut_dirty[display_id] = vivTRUE;
}

gctVOID viv_conf_3d_lut_set_enlarge(
    viv_dc_core *core,
    viv_display display_id,
    viv_lut_enlarge enlarge
    )
{
    int i = 0;

    core->display.lut_enlarge_val[display_id] = enlarge;

    /* TO DO
     * configure scale and offset for each channel
     * for scale, bits 0-7 represent the value of decimal, bits 8-9 represent the value of integer part
     */
    for (i = 0; i < 3; i++)
    {
        /* currently use register default value, scale = 1, offset = 0 */
        core->display.lut_scale_val[display_id][i] = 256;
        core->display.lut_offset_val[display_id][i] = 0;
    }

    core->display.lut_dirty[display_id] = vivTRUE;
}

gctVOID viv_conf_3d_lut_commit(
    viv_dc_core *core
    )
{
    gctUINT i = 0;

    for (i = 0;i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if (core->display.lut_dirty[i] == vivTRUE)
        {
            viv_hw_3d_lut_set_config(
                core->hardware,
                (viv_display)i,
                core->display.lut_enable[i],
                core->display.lut_table[i]
                );

            viv_hw_3d_lut_ex_config(
                core->hardware,
                (viv_display)i,
                core->display.lut_scale_val[i],
                core->display.lut_offset_val[i]
                );

            viv_hw_3d_lut_set_enlarge(
                core->hardware,
                (viv_display)i,
                core->display.lut_enlarge_val[i]
                );
        }
    }
}
#endif

/*******************************************************************************
** Query chip feature
*/
gctVOID viv_conf_query_feature_support(
    viv_dc_core *core
    )
{
    gcsDC_FEATURES* feature;
    viv_interface_query_chip_identity chip_info;

    dc_conf_query_chip_identity(core, &chip_info);
    chip_id = chip_info.chipModel;

    feature =_DCQueryFeatures(
            chip_info.chipModel,
            chip_info.chipRevision,
            chip_info.productID,
            chip_info.ecoID,
            chip_info.customerID
    );

    if (feature == gcvNULL)
    {
        viv_os_print("Could not find matched hw.\n");
    }
    else
    {
        chip_feature[vivFEATURE_DISPLAY_COUNT] = feature->DC_DISPLAY_COUNT;
        chip_feature[vivFEATURE_LAYER_COUNT] = feature->DC_LAYER_COUNT;
        chip_feature[vivFEATURE_CURSOR_COUNT] = feature->DC_CURSOR_COUNT;
        chip_feature[vivFEATURE_SECURITY] = feature->DC_SECURITY;
        chip_feature[vivFEATURE_MMU] = feature->DC_MMU;
        chip_feature[vivFEATURE_CURSOR_VERSION] = feature->DC_CURSOR_VERSION;
        chip_feature[vivFEATURE_CSC_MOUDLE] = feature->DC_CSC_MODULE;
        chip_feature[vivFEATURE_3D_LUT] = feature->DC_3D_LUT;
        chip_feature[vivFEATURE_DE_GAMMA] = feature->DC_DE_GAMMA;
        chip_feature[vivFEATURE_DP] = feature->DC_DP;
        chip_feature[vivFEATURE_DP_YUV] = feature->DC_DP_YUV;
        chip_feature[vivFEATURE_40BIT_ADDRESS] = feature->DC_40BIT_ADDRESS;
    }
}

gctVOID viv_layer_clear_enable(
    viv_dc_core *core,
    gctUINT layer_id,
    gctBOOL enable
    )
{
    core->display.layers[layer_id].clear_color_enable = !!enable;
    core->display.layer_dirty[layer_id] = vivTRUE;
}

gctVOID viv_layer_clear_color(
    viv_dc_core  *core,
    gctUINT layer_id,
    viv_dc_color* clear_color_ptr
    )
{
    viv_os_memcpy(&core->display.layers[layer_id].clear_color,clear_color_ptr,sizeof(viv_dc_color));
    core->display.layer_dirty[layer_id] = vivTRUE;
}

gctVOID viv_layer_conf_y2r(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL yuvClamp,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    )
{
    gctUINT i;
    core->display.layers[layer_id].y2r_mode = mode;
    core->display.layers[layer_id].y2r_clamp = yuvClamp;

    switch (mode)
    {
        case vivCSC_USER_DEF:
            viv_os_memset(core->os, core->display.layers[layer_id].y2r_coef, 0, sizeof(core->display.layers[layer_id].y2r_coef));
            viv_os_memcpy(core->display.layers[layer_id].y2r_coef, coef, sizeof(gctINT) * num);
            break;

        case vivCSC_BT601:
            if(yuvClamp)
            {
                for(i = 0; i < YUV2RGB_LR_COEF_NUM; i++)
                    core->display.layers[layer_id].y2r_coef[i] = YUV2RGB_LR601[i];
            }
            else
            {
                for(i = 0; i < YUV2RGB_FR_COEF_NUM; i++)
                    core->display.layers[layer_id].y2r_coef[i] = YUV2RGB_FR601[i];
            }
            break;

       case vivCSC_BT709:
            if(yuvClamp)
            {
                for(i = 0; i < YUV2RGB_LR_COEF_NUM; i++)
                    core->display.layers[layer_id].y2r_coef[i] = YUV2RGB_LR709[i];
            }
            else
            {
                for(i = 0; i < YUV2RGB_FR_COEF_NUM; i++)
                    core->display.layers[layer_id].y2r_coef[i] = YUV2RGB_FR709[i];
            }
            break;

       case vivCSC_BT2020:
            if(yuvClamp)
            {
                for(i = 0; i < YUV2RGB_LR_COEF_NUM; i++)
                    core->display.layers[layer_id].y2r_coef[i] = YUV2RGB_LR2020[i];
            }
            else
            {
                for(i = 0; i < YUV2RGB_FR_COEF_NUM; i++)
                    core->display.layers[layer_id].y2r_coef[i] = YUV2RGB_FR2020[i];
            }
            break;

        default:
            break;
    }

    core->display.layers[layer_id].y2r_dirty = vivTRUE;
    core->display.layer_dirty[layer_id] = vivTRUE;
}

vivSTATUS viv_layer_conf_r2r(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL enable,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    )
{
#if vivENABLE_DISPLAY_R2Y
    gctUINT i = 0;
    gctBOOL input_yuv = 0;
    gctBOOL display_yuv = 0;
    gctUINT display_id = 0;
    viv_csc_mode y2r_mode = (viv_csc_mode)0;
    viv_csc_mode r2y_mode = (viv_csc_mode)0;

    core->display.layers[layer_id].r2r_enable = enable;

    if(enable)
    {
        display_id = (gctUINT)core->display.layers[layer_id].display_id;
        input_yuv = _viv_is_yuv_format(core->display.layers[layer_id].buffer.format);
#if vivENABLE_DISPLAY_DP
        display_yuv = _viv_is_dp_yuv_format(core->display.output[display_id].format);
#endif
        if(input_yuv)
        {
            if(core->display.layers[layer_id].y2r_dirty != vivTRUE)
            {
                viv_os_print("In this situation, layer r2r should set after layer y2r has setted.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }

            y2r_mode = core->display.layers[layer_id].y2r_mode;

            if(((mode == vivCSC_BT709) && (y2r_mode != vivCSC_BT2020)) ||
                ((mode == vivCSC_BT2020) && (y2r_mode != vivCSC_BT709)) ||
                ((mode == vivCSC_USER_DEF) && (y2r_mode != vivCSC_USER_DEF))
                )
            {
                viv_os_print("The color space should set match with others' color space.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }
        }

        if(display_yuv)
        {
            if(core->display.r2y_dirty[display_id] != vivTRUE)
            {
                viv_os_print("In this situation, layer r2r should set after displye r2y has setted.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }

            r2y_mode = core->display.r2y_mode[display_id];

            if(((mode == vivCSC_BT709) && (r2y_mode != vivCSC_BT709)) ||
                ((mode == vivCSC_BT2020) && (r2y_mode != vivCSC_BT2020)) ||
                ((mode == vivCSC_USER_DEF) && (y2r_mode != vivCSC_USER_DEF))
                )
            {
                viv_os_print("The color space should set match with others' color space.\n");
                return vivSTATUS_INVALID_ARGUMENTS;
            }
        }

        if(mode == vivCSC_USER_DEF)
        {
            viv_os_memset(core->os, core->display.layers[layer_id].r2r_coef, 0, sizeof(core->display.layers[layer_id].r2r_coef));
            viv_os_memcpy(core->display.layers[layer_id].r2r_coef, coef, sizeof(gctINT) * num);
        }
        if(mode == vivCSC_BT601)
        {
            viv_os_print("There is no default coeffient form RGB709 to RGB601 or RGB2020 to RGB601.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }
        if(mode == vivCSC_BT709)
        {
            for(i = 0; i < RGB2RGB_COEF_NUM; i++)
                core->display.layers[layer_id].r2r_coef[i] = RGB2RGB_709[i];
        }
        if(mode == vivCSC_BT2020)
        {
            for(i = 0; i < RGB2RGB_COEF_NUM; i++)
            core->display.layers[layer_id].r2r_coef[i] = RGB2RGB_2020[i];
        }
    }

    core->display.layers[layer_id].r2r_dirty = vivTRUE;
    core->display.layer_dirty[layer_id] = vivTRUE;
#endif
    return vivSTATUS_OK;
}

#if vivENABLE_LAYER_ROI
gctVOID viv_layer_conf_roi_enable(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL enable
    )
{
    core->display.layers[layer_id].roi_enable = enable;
    core->display.layer_dirty[layer_id] = vivTRUE;
}

gctVOID viv_layer_conf_roi_rect(
    viv_dc_core  *core,
    gctUINT layer_id,
    viv_dc_rect* rect_ptr
    )
{
    viv_os_memcpy(&core->display.layers[layer_id].roi_rect,rect_ptr,sizeof(viv_dc_rect));
    core->display.layer_dirty[layer_id] = vivTRUE;
}
#endif

gctVOID viv_layer_conf_set_position(
    viv_dc_core *core,
    gctUINT layer_id,
    gctUINT x,
    gctUINT y
    )
{
    core->display.layers[layer_id].pos_x = x;
    core->display.layers[layer_id].pos_y = y;
}

#if vivENABLE_LAYER_DEGAMMA
gctVOID viv_layer_conf_enable_degamma(
    viv_dc_core *core,
    gctUINT layer_id,
    gctBOOL enable
    )
{
    if (enable != core->display.layers[layer_id].degamma_enable)
    {
        core->display.layers[layer_id].degamma_enable = enable;
        core->display.layer_dirty[layer_id] = vivTRUE;
    }
}

gctVOID viv_layer_conf_set_degamma(
    viv_dc_core *core,
    gctUINT   layer_id,
    gctUINT   index,
    gctUINT16 red,
    gctUINT16 green,
    gctUINT16 blue
    )
{
    if (index >= DEGAMMA_TABLE_SIZE)
        return;

    core->display.layers[layer_id].degamma.degammaTable[index][0] = red;
    core->display.layers[layer_id].degamma.degammaTable[index][1] = green;
    core->display.layers[layer_id].degamma.degammaTable[index][2] = blue;
    core->display.layer_dirty[layer_id] = vivTRUE;
}
#endif

gctVOID viv_layer_conf_set_background(
    viv_dc_core* core,
    viv_display display_id,
    viv_dc_color* bg_color_ptr
    )
{
    viv_os_memcpy(&core->display.bg_color[display_id], bg_color_ptr, sizeof(viv_dc_color));
    core->display.bg_dirty[display_id] = vivTRUE;
}

#if vivENABLE_DISPLAY_CLRBAR
vivSTATUS viv_conf_set_color_bar(
    viv_dc_core* core,
    viv_display display_id,
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect* range,
    viv_dc_color* color
    )
{
    core->display.colorbar_enabled[display_id][index] = enable;

    if(enable)
    {
        gctINT i;
        gctUINT cmp_tl_x, cmp_tr_x, cmp_tl_y, cmp_bl_y;
        gctUINT tl_x, tl_y, tr_x, tr_y, bl_x, bl_y, br_x, br_y;
        gctUINT max_width, max_height;

        tl_x = bl_x = range->x;
        tr_x = br_x = range->x + range->w;
        tl_y = tr_y = range->y;
        bl_y = br_y = range->y +range->h;

        switch (core->display.size[display_id])
        {
            case vivDISPLAY_640_480_60:
                max_width = 640;
                max_height = 480;
                break;
            case vivDISPLAY_720_480_60:
                 max_width = 720;
                 max_height = 480;
                 break;
            case vivDISPLAY_800_480_60:
                 max_width = 800;
                 max_height = 480;
                 break;
            case vivDISPLAY_1024_600_60:
                max_width = 1024;
                max_height = 600;
                break;
            case vivDISPLAY_1280_720_60:
                max_width = 1280;
                max_height = 720;
                break;
            case vivDISPLAY_1920_1080_60:
                max_width = 1920;
                max_height = 1080;
                break;
            case vivDISPLAY_3840_2160_30:
                max_width = 3840;
                max_height = 2160;
                break;
            case vivDISPLAY_3840_2160_60:
                max_width = 3840;
                max_height = 2160;
                break;
            case vivDISPLAY_4096_2160_60:
                max_width = 4096;
                max_height = 2160;
                break;
            case vivDISPLAY_5760_756_60:
                max_width = 5760;
                max_height = 756;
                break;
            default:
                max_width = 640;
                max_height = 480;
                break;
        }
        /* To determine the color bar rect whether out of display range. */
        if((tr_x > max_width) || (bl_y > max_height))
        {
            viv_os_print("The color bar rectange range is out of rang.\n");
            return vivSTATUS_INVALID_ARGUMENTS;
        }

        for(i = 0; i < DC_COLORBAR_NUM; i++)
        {
            if(core->display.colorbar_enabled[display_id][i] && core->display.colorbar_dirty[display_id][i])
            {
                cmp_tl_x = core->display.colorbar_range[display_id][i].x;
                cmp_tl_y = core->display.colorbar_range[display_id][i].y;
                cmp_tr_x = core->display.colorbar_range[display_id][i].x + core->display.colorbar_range[display_id][i].w;
                cmp_bl_y = core->display.colorbar_range[display_id][i].y + core->display.colorbar_range[display_id][i].h;
                /* To determine the four vertices whether in the enabled color bar rect range */
                if((tl_x >= cmp_tl_x && tl_x < cmp_tr_x && tl_y >= cmp_tl_y && tl_y < cmp_bl_y) ||
                   (tr_x >= cmp_tl_x && tr_x < cmp_tr_x && tr_y >= cmp_tl_y && tr_y < cmp_bl_y) ||
                   (bl_x >= cmp_tl_x && bl_x < cmp_tr_x && bl_y >= cmp_tl_y && bl_y < cmp_bl_y) ||
                   (br_x >= cmp_tl_x && br_x < cmp_tr_x && br_y >= cmp_tl_y && br_y < cmp_bl_y)
                  )
                  {
                    viv_os_print("The color bar rectange range has intersection with others.\n");
                    return vivSTATUS_INVALID_ARGUMENTS;
                  }
            }
        }

        viv_os_memcpy(&core->display.colorbar_range[display_id][index], range, sizeof(viv_dc_rect));
        viv_os_memcpy(&core->display.colorbar_color[display_id][index], color, sizeof(viv_dc_color));
    }

    core->display.colorbar_dirty[display_id][index] = vivTRUE;
    return vivSTATUS_OK;
}
#endif

gctVOID viv_cursor_conf_hotspot(
    viv_dc_core* core,
    viv_display display_id,
    gctUINT32 hsx,
    gctUINT32 hsy
    )
{
    core->display.cursors[display_id].hsx = hsx;
    core->display.cursors[display_id].hsy = hsy;
    core->display.cursor_dirty[display_id]= vivTRUE;
}

gctVOID viv_cursor_conf_move(
    viv_dc_core* core,
    viv_display display_id,
    gctUINT32 x,
    gctUINT32 y
    )
{
    core->display.cursors[display_id].x = x;
    core->display.cursors[display_id].y = y;
    viv_hw_cursor_move(core->hardware, display_id, &core->display.cursors[display_id]);
}

gctVOID viv_cursor_conf_enable(
    viv_dc_core* core,
    viv_display display_id,
    gctBOOL enable
    )
{
    core->display.cursor_enable[display_id] = enable;
    core->display.cursor_dirty[display_id]= vivTRUE;
}

gctVOID viv_cursor_conf_set(
    viv_dc_core* core,
    viv_display display_id,
    viv_dc_buffer* buffer_ptr,
    viv_cursor* cursor_ptr
    )
{
    viv_os_memcpy(&core->display.cursors[display_id], cursor_ptr, sizeof(viv_cursor));
    viv_os_memcpy(&core->display.cursor_buffer[display_id], buffer_ptr, sizeof(viv_dc_buffer));
    core->display.cursor_dirty[display_id]= vivTRUE;
}

#if vivENABLE_SEC
vivSTATUS viv_cursor_conf_security(
    viv_dc_core *core,
    viv_display display_id,
    gctBOOL enable
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    core->display.cursor_security[display_id] = !!enable;
    core->display.cursor_dirty[display_id] = vivTRUE;
    return ret;
}
#endif

#if vivENABLE_LAYER_SCALE
gctVOID viv_conf_layer_set_scale(
    viv_dc_core *core,
    gctUINT id,
    viv_filter_tap_type filter,
    gctUINT32 *horkernel,
    gctUINT32 *verkernel,
    gctUINT32 factorx,
    gctUINT32 factory,
    gctBOOL enable
    )
{
    core->display.layers[id].filter = filter;
    core->display.layers[id].scale_factor_x = factorx;
    core->display.layers[id].scale_factor_y = factory;
    core->display.layers[id].scale_enable = enable;

    viv_os_memcpy(core->display.layers[id].hor_kernel, horkernel, sizeof(gctUINT32) * 78);
    viv_os_memcpy(core->display.layers[id].ver_kernel, verkernel, sizeof(gctUINT32) * 78);

    core->display.layer_dirty[id] = vivTRUE;
}
#endif

gctVOID viv_conf_layer_set_rect(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_rect rect
    )
{
    core->display.layers[id].pos_x = rect.x;
    core->display.layers[id].pos_y = rect.y;
    core->display.layers[id].width = rect.w;
    core->display.layers[id].height = rect.h;

    core->display.layer_dirty[id] = vivTRUE;
}

gctVOID viv_dc_conf_qos(
    viv_dc_core* core,
    gctUINT32 low,
    gctUINT32 high
    )
{
    core->display.qos_low = low;
    core->display.qos_high = high;
    core->display.qos_dirty = vivTRUE;
}

gctVOID viv_conf_set_display(
    viv_dc_core *core,
    gctUINT32 mask
    )
{
    core->display.display_mask = mask;
}

#if vivENABLE_DISPLAY_CRC
gctVOID viv_crc_set_range(
    viv_dc_core *core,
    gctUINT32 index,
    gctBOOL enable,
    viv_dc_rect* range
    )
{
    core->display.crc_enable[index] = enable;
    viv_os_memcpy(&core->display.crc_rect[index], range, sizeof(viv_dc_rect));
    core->display.crc_dirty[index] = vivTRUE;
}

gctVOID viv_crc_get_value(
    viv_dc_core *core,
    gctUINT32 index,
    gctUINT32 *value
    )
{
    viv_hw_get_crc_value(core->hardware, index, value);
}
#endif

gctVOID viv_conf_start_panel_commit(
    viv_dc_core *core
    )
{
    gctUINT i = 0;
    gctUINT count = 0;

    viv_hw_layer_set_zorder(core->hardware);

    for(i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if (core->display.output[i].type == vivDBI)
        {
            viv_hw_display_dbi_set_command(
                core->hardware,
                core->display.output[i].format,
                vivDBI_COMMAND_MEM,
                0x0
                );
            count++;
        }
    }

    if (count != chip_feature[vivFEATURE_DISPLAY_COUNT])
    {
        viv_hw_start_panel_set_config(core->hardware, core->display.display_mask);
    }

}

gctVOID viv_conf_reset_dirty(
    viv_dc_core *core
    )
{
    gctUINT i = 0;
#if vivENABLE_DISPLAY_CLRBAR
    gctUINT j = 0;
#endif

    for(i = 0; i < chip_feature[vivFEATURE_DISPLAY_COUNT]; i++)
    {
        if(core->display.display_dirty[i])
        {
            core->display.display_dirty[i] = vivFALSE;
        }

        if (core->display.dither_dirtys[i])
        {
            core->display.dither_dirtys[i] = vivFALSE;
        }

#if vivENABLE_DISPLAY_3DLUT
        if (core->display.lut_dirty[i])
        {
            core->display.lut_dirty[i] = vivFALSE;
        }
#endif

        if(core->display.gamma_dirtys[i])
        {
            core->display.gamma_dirtys[i] = vivFALSE;
        }

#if vivENABLE_WRITEBACK
        if(core->display.dest_dirty[i])
        {
            core->display.dest_dirty[i] = vivFALSE;
        }

        if(core->display.wb_dither_dirty[i])
        {
            core->display.wb_dither_dirty[i] = vivFALSE;
        }
#endif

        if (core->display.bg_dirty[i])
        {
            core->display.bg_dirty[i] = vivFALSE;
        }

#if vivENABLE_DISPLAY_CLRBAR
        for(j = 0; j < DC_COLORBAR_NUM; j++)
        {
            if(core->display.colorbar_dirty[i][j])
            {
                core->display.colorbar_dirty[i][j] = vivFALSE;
            }
        }
#endif

#if vivENABLE_DISPLAY_R2Y
        if (core->display.r2y_dirty[i])
        {
            core->display.r2y_dirty[i] = vivFALSE;
        }
#endif
    }

    for (i = 0; i < chip_feature[vivFEATURE_CURSOR_COUNT]; i++)
    {
        if (core->display.cursor_dirty[i])
        {
            core->display.cursor_dirty[i] = vivFALSE;
        }
    }

    if(core->display.qos_dirty)
    {
        core->display.qos_dirty = vivFALSE;
    }

    for (i = 0; i < chip_feature[vivFEATURE_LAYER_COUNT]; i++)
    {
        if (core->display.layer_dirty[i])
        {
            core->display.layer_dirty[i] = vivFALSE;
            core->display.layers[i].buffer.phyAddress[0] = 0;
            core->display.layers[i].buffer.phyAddress[1] = 0;
            core->display.layers[i].buffer.phyAddress[2] = 0;
        }

        if (core->display.layers[i].y2r_dirty)
        {
            core->display.layers[i].y2r_dirty = vivFALSE;
        }

        if (core->display.layers[i].r2r_dirty)
        {
            core->display.layers[i].r2r_dirty = vivFALSE;
        }
    }
#if vivENABLE_DISPLAY_CRC
    for (i = 0; i < MAX_CRC_NUM; i++)
    {
        if (core->display.crc_dirty[i])
        {
            core->display.crc_dirty[i] = vivFALSE;
        }
    }
#endif
}

#if vivENABLE_ADDRESS_40BITS
vivSTATUS viv_check_buffer_address_valid(
    viv_dc_core *core
    )
{
    vivSTATUS ret = vivSTATUS_OK;
    gctBOOL compressed;
    int i,j;
    gctUINT8 upper_address = 0;
    viv_input_format_type dc_format;
    viv_dc_node address_node[DC_LAYER_NUM * 3 * 2] = {{0, 0, 0}};
    gctUINT32 layer_buffer_address_index = 0;

    viv_os_memset(vivNULL, address_node, 0, sizeof(address_node));
    if(!chip_feature[vivFEATURE_40BIT_ADDRESS])
        return vivSTATUS_OK;

    for (i = 0; i < chip_feature[vivFEATURE_LAYER_COUNT]; i++)
    {
        if (core->display.layer_dirty[i] == vivTRUE)
        {
            compressed = core->display.layers[i].dec_enable;
            if(compressed)
            {
                upper_address = (gctUINT8)(core->display.layers[i].tile_status_biffer.tileStatusHWAddress[0] >> 32);
                break;
            }
        }
    }

    for (i = 0; i < chip_feature[vivFEATURE_LAYER_COUNT]; i++)
    {
        if(core->display.layer_dirty[i])
        {
            dc_format = core->display.layers[i].buffer.format;
            switch(dc_format)
            {
                /* use one streams */
                case vivXRGB8888:
                case vivARGB8888:
                case vivABGR8888:
                case vivRGB565:
                case vivARGB1555:
                case vivXRGB1555:
                case vivARGB4444:
                case vivXRGB4444:
                case vivARGB2101010:
                case vivYUY2:
                case vivUYVY:
                    for(j = 0; j < 1; j++)
                    {
                        if(core->display.layers[i].layer_enable)
                        {
                            address_node[layer_buffer_address_index].layer_id = i;
                            address_node[layer_buffer_address_index].address = (gctUINT32)core->display.layers[i].buffer.phyAddress[j];
                            address_node[layer_buffer_address_index++].size = core->display.layers[i].buffer.stride[j] * core->display.layers[i].buffer.height;
                            if(core->display.layers[i].dec_enable)
                            {
                                address_node[layer_buffer_address_index].layer_id = i;
                                address_node[layer_buffer_address_index].address = (gctUINT32)core->display.layers[i].tile_status_biffer.tileStatusHWAddress[j];
                                address_node[layer_buffer_address_index++].size = _vs_cal_bo_size(core, i, j);

                                if(upper_address != (gctUINT8)(core->display.layers[i].tile_status_biffer.tileStatusHWAddress[j] >> 32))
                                {
                                    core->display.layers[i].layer_enable = 0;
                                    core->display.layer_dirty[i] = 0;
                                    viv_os_print("tile_status_buffer upper address could not match.\n");
                                }
                            }
                        }
                    }
                    break;

                /* use two streams */
                case vivNV12:
                case vivNV21:
                case vivNV16:
                case vivP010:
                    for(j = 0; j < 2; j++)
                    {
                        if(core->display.layers[i].layer_enable == 0)
                        {
                            address_node[layer_buffer_address_index].layer_id = i;
                            address_node[layer_buffer_address_index].address = (gctUINT32)core->display.layers[i].buffer.phyAddress[j];
                            address_node[layer_buffer_address_index++].size = core->display.layers[i].buffer.stride[j] * core->display.layers[i].buffer.height;
                            if(core->display.layers[i].dec_enable){
                                address_node[layer_buffer_address_index].layer_id = i;
                                address_node[layer_buffer_address_index].address = (gctUINT32)core->display.layers[i].tile_status_biffer.tileStatusHWAddress[j];
                                address_node[layer_buffer_address_index++].size = _vs_cal_bo_size(core, i, j);

                                if(upper_address != (gctUINT8)(core->display.layers[i].tile_status_biffer.tileStatusHWAddress[j] >> 32))
                                {
                                    core->display.layers[i].layer_enable = 0;
                                    core->display.layer_dirty[i] = 0;
                                    viv_os_print("tile_status_buffer upper address could not match.\n");
                                    break;
                                }
                            }
                        }
                    }
                    break;

                /* use three streams */
                case vivYV12:
                case vivYU12:
                    for(j = 0; j < 3; j++)
                    {
                        if(core->display.layers[i].layer_enable == 0)
                        {
                            address_node[layer_buffer_address_index].layer_id = i;
                            address_node[layer_buffer_address_index].address = (gctUINT32)core->display.layers[i].buffer.phyAddress[j];
                            address_node[layer_buffer_address_index++].size = core->display.layers[i].buffer.stride[j] * core->display.layers[i].buffer.height;
                            if(core->display.layers[i].dec_enable){
                                address_node[layer_buffer_address_index].layer_id = i;
                                address_node[layer_buffer_address_index].address = (gctUINT32)core->display.layers[i].tile_status_biffer.tileStatusHWAddress[j];
                                address_node[layer_buffer_address_index++].size = _vs_cal_bo_size(core, i, j);

                                if(upper_address != (gctUINT8)(core->display.layers[i].tile_status_biffer.tileStatusHWAddress[j] >> 32))
                                {
                                    core->display.layers[i].layer_enable = 0;
                                    core->display.layer_dirty[i] = 0;
                                    viv_os_print("tile_status_buffer upper address could not match.\n");
                                    break;
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

    for(i = 0; i < layer_buffer_address_index - 1; i++)
        for(j = i + 1; j < layer_buffer_address_index ; j++)
        {
            if(core->display.layers[address_node[i].layer_id].layer_enable == 0)
                break;
            if(core->display.layers[address_node[j].layer_id].layer_enable == 0)
                continue;
            if(isIntersection(address_node[i],address_node[j]))
            {
                core->display.layers[address_node[j].layer_id].layer_enable = 0;
                core->display.layer_dirty[address_node[j].layer_id] = 0;
                viv_os_print("tile_status_buffer or data buffer low 32 bit address have overlap.\n");
            }
        }

    return ret;
}
#endif

/*******************************************************************************
** Commit All
*/
gctVOID viv_conf_commit(
    viv_dc_core *core
    )
{
    viv_conf_query_feature_support(core);

#if vivENABLE_ADDRESS_40BITS
    viv_check_buffer_address_valid(core);
#endif

#if vivENABLE_LAYER_DECOMPRESS
    viv_conf_dec400_commit(core);
#endif

    viv_hw_shadow_register_pending_enable(core->hardware, vivFALSE, core->display.layer_dirty, core->display.display_dirty);

#if vivENABLE_SEC
    viv_hw_sec_shadow_register_pending_enable(core->hw_sec, vivFALSE, core->display.layer_dirty, core->display.layer_security);
#endif

#if vivENABLE_DISPLAY_R2Y
    viv_conf_output_csc_commit(core);
#endif

    viv_conf_display_commit(core);

#if vivENABLE_DISPLAY_CRC
    viv_crc_commit(core);
#endif

    viv_dither_commit(core);

#if vivENABLE_DISPLAY_3DLUT
    viv_conf_3d_lut_commit(core);
#endif

    viv_conf_gamma_commit(core);

    viv_cursor_commit(core);

#if vivENABLE_WRITEBACK
    viv_conf_dest_commit(core);
#endif

    viv_background_commit(core);

    viv_qos_commit(core);

    viv_layer_commit(core);

    viv_hw_shadow_register_pending_enable(core->hardware, vivTRUE, core->display.layer_dirty, core->display.display_dirty);

#if vivENABLE_SEC
    viv_hw_sec_shadow_register_pending_enable(core->hw_sec, vivTRUE, core->display.layer_dirty, core->display.layer_security);
#endif

#if DUMP_MMU_PAGE_TABLE
    dcMMU_DumpPageTable(core->mmu);
#endif
//IFXEXP-182
if (core->display.output->type != vivDBI){
   viv_conf_start_panel_commit(core);
}

#if vivENABLE_DISPLAY_CRC
    viv_hw_reset_sw_stat();
#endif

    viv_conf_reset_dirty(core);
}

/*******************************************************************************
** Interrupt
*/
gctVOID viv_conf_interrupt_enable(
    viv_dc_core *core,
    gctBOOL enable
    )
{
    viv_hw_interrupt_enable(core->hardware, enable);
}

gctUINT viv_conf_interrupt_get(
    viv_dc_core *core
    )
{
    gctUINT interrupt = 0;
#if vivENABLE_MMU
    gctUINT mmu_interrupt = 0;
#endif

    interrupt = viv_hw_interrupt_get(core->hardware);

    if (chip_id == 0x8000)
    {
        if(interrupt)
        {
            /*TODO add a lock*/
            if(interrupt & BIT(0))
                core->vblank_count[vivDISPLAY_0] += 1;
            if(interrupt & BIT(4))
                core->vblank_count[vivDISPLAY_1] += 1;
            if(interrupt & BIT(30))
                core->interrupts[vivDC_INT_SW_RESET_DONE] = 1;
        }
    }
    else
    {
        if(interrupt)
        {
            /*TODO add a lock*/
            if(interrupt & BIT(0))
                core->vblank_count[vivDISPLAY_0] += 1;
            if(interrupt & BIT(1))
                core->vblank_count[vivDISPLAY_1] += 1;
            if(interrupt & BIT(2))
                core->interrupts[vivDC_INT_SW_RESET_DONE] = 1;
            if(interrupt & (BIT(3) | BIT(4) | BIT(5) | BIT(6) | BIT(7) | BIT(8)))
                core->interrupts[vivDC_INT_LAYER_CONFLICT] = 1;
            if(interrupt & (BIT(30) | BIT(31)))
                core->interrupts[vivDC_INT_AXI_BUS_ERR] = 1;
        }
    }
#if vivENABLE_MMU
    mmu_interrupt = dcMMU_Interrupt_Get(core->hw_sec);
    if(mmu_interrupt)
    {
        if(mmu_interrupt & BIT(0))
            viv_os_print("MMU0 slave not presend.\n");
        if(mmu_interrupt & BIT(1))
            viv_os_print("MMU0 client out of bound.\n");
        if(mmu_interrupt & BIT(2))
            viv_os_print("MMU0 size of bound.\n");
        if(mmu_interrupt & BIT(3))
            viv_os_print("MMU0 read security exception.\n");
        if(mmu_interrupt & BIT(4))
            viv_os_print("MMU0 write security exception.\n");
        if(mmu_interrupt & BIT(5))
            viv_os_print("MMU0 page not present.\n");
        if(mmu_interrupt & BIT(6))
            viv_os_print("MMU0 page write to unwritable page.\n");
        if(mmu_interrupt & BIT(7))
            viv_os_print("MMU0 read security mem violation.\n");
        if(mmu_interrupt & BIT(8))
            viv_os_print("MMU1 slave not presend.\n");
        if(mmu_interrupt & BIT(9))
            viv_os_print("MMU1 client out of bound.\n");
        if(mmu_interrupt & BIT(10))
            viv_os_print("MMU1 size of bound.\n");
        if(mmu_interrupt & BIT(11))
            viv_os_print("MMU1 read security exception.\n");
        if(mmu_interrupt & BIT(12))
            viv_os_print("MMU1 write security exception.\n");
        if(mmu_interrupt & BIT(13))
            viv_os_print("MMU1 page not present.\n");
        if(mmu_interrupt & BIT(14))
            viv_os_print("MMU1 page write to unwritable page.\n");
        if(mmu_interrupt & BIT(15))
            viv_os_print("MMU1 read security mem violation.\n");
    }
#endif

    return interrupt;
}

/*******************************************************************************
** Info
*/
gctVOID viv_conf_info_get(
    viv_dc_core *core,
    gctUINT* chip_id,
    gctUINT* chip_revision,
    gctUINT* chip_patch_revision,
    gctUINT* chip_info,
    gctUINT* product_id,
    gctUINT* eco_id,
    gctUINT* customer_id,
    gctUINT* product_date,
    gctUINT* product_time
    )
{
    viv_hw_version_get(core->hardware,
                       chip_id,
                       chip_revision,
                       chip_patch_revision,
                       chip_info,
                       product_id,
                       eco_id,
                       customer_id,
                       product_date,
                       product_time);
}

gctVOID dc_conf_query_chip_identity(
    viv_dc_core *core,
    viv_interface_query_chip_identity_ptr Identity
    )
{
    dc_query_hardware_chip_identity(core->hardware, Identity);
}

/*
 * Get Vblank Counter
 */
vivSTATUS viv_conf_get_vblank(
    viv_dc_core *core,
    viv_display  display,
    gctUINT32 *vblank)
{
    gctUINT32 disp = (gctUINT32) display;
    if(disp >= DC_DISPLAY_NUM)
        return vivSTATUS_INVALID_ARGUMENTS;
    if(!vblank)
        return vivSTATUS_INVALID_ARGUMENTS;

    /*TODO add a lock*/
    *vblank = core->vblank_count[disp];
    return vivSTATUS_OK;
}

#if vivENABLE_DUALOS
vivSTATUS viv_get_layer_status(
    viv_dc_core *core,
    gctUINT layer_id,
    viv_layer_status *status)
{
    gctUINT32 hw_layer;
    vivSTATUS ret;

    hw_layer = _viv_api_layer_to_hw_layer(layer_id);
    ret = viv_hw_get_layer_status(core->hardware,hw_layer,status);

    return ret;
}

vivSTATUS viv_request_control(
    viv_dc_core *core,
    gctBOOL *success)
{
    gctUINT i = 0, id = 0;
    vivSTATUS ret = vivSTATUS_OK;
    ret = viv_hw_request_control(core->hardware,success);
    for (i = 0; i < chip_feature[vivFEATURE_LAYER_COUNT]; i++)
    {
        if(core->display.layer_dirty[i] == vivTRUE) {
            id = _viv_api_layer_to_hw_layer(i);
            viv_hw_layer_enable_set_config(
                core->hardware,
                id,
                core->display.layers[i]);
        }
    }
    return ret;
}
#endif

gctVOID viv_interrupt_enable(
    viv_dc_core *core,
    gctBOOL *interrupt_enable)
{
    viv_hw_enable_interrupt(core->hardware,interrupt_enable);
}

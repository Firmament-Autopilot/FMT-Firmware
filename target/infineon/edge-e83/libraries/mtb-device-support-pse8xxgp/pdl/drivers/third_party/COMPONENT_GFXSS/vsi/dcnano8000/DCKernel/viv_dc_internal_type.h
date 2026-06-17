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


#ifndef _VIV_DC_INTER_TYPE_H_
#define _VIV_DC_INTER_TYPE_H_

typedef struct _viv_dc_layer
{
    /* buffer */
    viv_dc_buffer           buffer;

#if vivENABLE_SEC
    gctBOOL                 security;
#endif

#if vivENABLE_LAYER_DECOMPRESS
    /* DEC */
    gctBOOL                 dec_enable;
    viv_tilestatus_buffer   tile_status_biffer;
    viv_cache_mode          dec_cache_mode;
#endif

    gctBOOL               scale_enable;
    /* scale */
#if vivENABLE_LAYER_SCALE
    viv_filter_tap_type   filter;
    gctUINT32             scale_factor_x;
    gctUINT32             scale_factor_y;
    gctUINT32             hor_kernel[78];
    gctUINT32             ver_kernel[78];
#endif

#if vivENABLE_LAYER_ROT
    /* rotation */
    viv_rotation_type     rotation;
#endif

    /* color */
    viv_dc_color       colorkey;
    viv_dc_color       colorkey_high;
    viv_dc_color       clear_color;
    gctBOOL            clear_color_enable;
    gctBOOL            transparency;

    /* alpha */
    viv_layer_alpha_mode  alpha_mode;

    /* poterbuff blend */
    gctBOOL               blend_enable;
    viv_porter_duff_mode  blend_mode;

    /* roi */
#if vivENABLE_LAYER_ROI
    gctBOOL           roi_enable;
    viv_dc_rect       roi_rect;
#endif

    /* position */
    gctUINT32         pos_x;
    gctUINT32         pos_y;
    gctUINT32         width;
    gctUINT32         height;

    /* degamma */
#if vivENABLE_LAYER_DEGAMMA
    gctBOOL           degamma_enable;
    viv_dc_degamma    degamma;
#endif

    /* watermark */
    gctUINT32          watermark;

    /* csc y2r */
    viv_csc_mode      y2r_mode;
    gctBOOL           y2r_clamp;
    gctINT            y2r_coef[YUV2RGB_LR_COEF_NUM];
    gctBOOL           y2r_dirty;

    /* csc r2r */
    gctBOOL           r2r_enable;
    gctUINT           r2r_coef[RGB2RGB_COEF_NUM];
    gctBOOL           r2r_dirty;

    /* zorder */
    gctUINT8           zorder;

    /* display */
    viv_display        display_id;

    /* layer enable */
    gctBOOL            layer_enable;
}
viv_dc_layer;

#endif

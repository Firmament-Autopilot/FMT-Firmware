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


#ifndef _VIV_DC_SETTING_H_
#define _VIV_DC_SETTING_H_

#include "viv_dc_util.h"
#include "viv_dc_options.h"
#include "viv_dc_type.h"

#if (vivENABLE_DISPLAY_DP && vivENABLE_DISPLAY_R2Y)
gctBOOL viv_is_dp_yuv(
    gctUINT32 output_format
    );
#endif

gctINT viv_set_dither(
    viv_display display,
    gctBOOL enable
    );

#if vivENABLE_WRITEBACK
vivSTATUS viv_set_write_back_dither(
    viv_display display,
    gctBOOL enable
    );

gctINT viv_set_dest(
    gctBOOL enable,
    viv_display display,
    viv_dc_buffer *buffer,
    viv_write_back_type type,
    viv_display_format_type format
    );
#endif

#if vivENABLE_DISPLAY_3DLUT
vivSTATUS viv_set_3d_lut(
    viv_display display,
    gctBOOL enable,
    gctUINT32* threed_lut
    );

vivSTATUS viv_set_3d_lut_enlarge(
    viv_display display,
    viv_lut_enlarge value
    );
#endif

gctINT viv_set_register(
    gctUINT32 offset,
    gctUINT32 write,
    gctUINT32* read,
    gctBOOL reset
    );

gctINT viv_read_register(
    gctUINT32 offset,
    gctUINT32* read
    );

#if ALLOC_RESERVED_MEM_IN_KERNEL
vivSTATUS free_all_reserved_mem_node(gctVOID);

vivSTATUS viv_alloc_reserved_mem(
    gctUINT32 size,
    gctADDRESS *physical,
    gctPOINTER *logical,
    gctUINT32 *resmem_handle
    );
#endif

gctINT viv_alloc_buffer(
    gctSIZE_T Size,
    gctPOINTER * Handle,
    gctADDRESS * HardwareAddress,
    gctPOINTER * Logical,
    gctBOOL   security,
    viv_pool_type Pool
    );

gctINT viv_free_buffer(
    gctPOINTER Handle
    );

#if vivENABLE_MMU
gctINT viv_map_buffer(
    gctUINT size,
    gctUINT physicalAddr,
    gctUINT *dcVirtualAddr,
    gctBOOL security,
    viv_pool_type pool
    );

gctINT viv_unmap_buffer(
    gctUINT size,
    gctUINT dcVirtualAddr
    );
#endif

vivSTATUS viv_query_chipinfo(
    gctBOOL *Features
    );

vivSTATUS viv_dc_query_feature(
    viv_dc_features features,
    gctUINT* value
    );

vivSTATUS viv_layer_query_capability(
    gctUINT layer_id,
    viv_dc_layer_cap cap,
    gctUINT *value
    );

vivSTATUS viv_dc_init(
    gctVOID
    );

vivSTATUS viv_dc_deinit(
    gctVOID
    );

vivSTATUS viv_dc_select_layer(
    gctUINT layer_id
    );

vivSTATUS viv_layer_set(
    viv_dc_buffer *buffer
    );

vivSTATUS viv_layer_set_y2r(
    gctBOOL yuvClamp,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    );

vivSTATUS viv_layer_set_r2r(
    gctBOOL enable,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    );

vivSTATUS viv_layer_clear(
    viv_dc_color *clearColor,
    gctBOOL enable
    );

#if vivENABLE_LAYER_ROI
vivSTATUS viv_layer_roi_enable(
    gctBOOL enable
    );

vivSTATUS viv_layer_roi_rect(
    viv_dc_rect *rect
    );
#endif

vivSTATUS viv_layer_set_position(
    gctUINT x,
    gctUINT y
    );

vivSTATUS viv_layer_colorkey(
    viv_dc_color *colorkey,
    viv_dc_color *colorkeyHigh,
    gctBOOL transparency
    );

#if vivENABLE_DISPLAY_NEWGMMA
vivSTATUS viv_new_gamma_init(
    viv_dc_gamma  *gamma
    );
#endif

vivSTATUS viv_gamma_init(
    viv_dc_gamma* gamma,
    gctFLOAT gamma_value
    );

vivSTATUS viv_gamma_enable(
    viv_display  display,
    gctBOOL      enable
    );

vivSTATUS viv_set_gamma(
    viv_display  display,
    gctUINT32    index,
    gctUINT16    r,
    gctUINT16    g,
    gctUINT16    b
    );

#if vivENABLE_LAYER_DEGAMMA
vivSTATUS viv_layer_degamma_init(
    viv_dc_degamma  *degamma
    );

vivSTATUS viv_layer_degamma_enable(
    gctBOOL      enable
    );

vivSTATUS viv_layer_set_degamma(
    gctUINT32    index,
    gctUINT16    r,
    gctUINT16    g,
    gctUINT16    b
    );
#endif

vivSTATUS viv_layer_set_background(
    viv_display display,
    viv_dc_color *bgColor
    );

#if vivENABLE_DISPLAY_CLRBAR
vivSTATUS viv_set_color_bar(
    viv_display display,
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect *range,
    viv_dc_color *color
    );
#endif

#if vivENABLE_LAYER_ROT
vivSTATUS viv_layer_rotation(
    viv_rotation_type rotation
    );
#endif

vivSTATUS viv_layer_scale(
    viv_dc_rect *displayRect,
    viv_filter_tap_type filter
    );

vivSTATUS viv_cursor_offset(
    viv_display display,
    gctUINT32 hsx,
    gctUINT32 hsy
    );

vivSTATUS viv_cursor_move(
    viv_display display,
    gctUINT32 x,
    gctUINT32 y
    );

vivSTATUS viv_set_cursor(
    viv_display display,
    viv_dc_buffer *buffer,
    viv_cursor *cursor,
    gctBOOL  enable
    );

vivSTATUS viv_dc_set_qos(
    gctUINT32 low,
    gctUINT32 high
    );

#if vivENABLE_LAYER_DECOMPRESS
vivSTATUS viv_layer_decompress(
    viv_tilestatus_buffer *tilebuffer,
    gctBOOL enable
    );

vivSTATUS viv_layer_cache_mode(
    viv_cache_mode cache_mode
    );
#endif

vivSTATUS viv_layer_set_watermark(
    gctUINT32 watermark
    );

vivSTATUS viv_set_alpha(
    viv_layer_alpha_mode *Alpha
    );

vivSTATUS viv_layer_poterduff_blend(
    gctBOOL enable,
    viv_porter_duff_mode Mode
    );

vivSTATUS viv_layer_zorder(
    gctUINT8 zorder
    );

vivSTATUS viv_layer_set_display(
    viv_display display
    );

vivSTATUS viv_set_display_size(
    viv_display display,
    viv_display_size_type type
    );

/*
 * This function sets custom display settings for the display.
 *
 *  @display
 *     display output.
 *
 *  @hactive
 *     hactive = display's width.
 *
 *  @hsync_start
 *     hsync_start = hactive + HFP.
 *
 *  @hsync_end
 *     hsync_end = hactive + HFP + HSlen.
 *
 *  @htotal
 *     htotal =  hactive + HFP + HSlen + HBP.
 *
 *  @vactive
 *     vactive = display's height.
 *
 *  @vsync_start
 *     vsync_start = vactive + VFP.
 *
 *  @vsync_end
 *     vsync_end = vactive + VFP + VSlen.
 *
 *  @vtotal
 *     vtotal = vactive + VFP + VSlen + VBP.
 */
vivSTATUS viv_set_custom_display_size(
    viv_display display,
    gctUINT hactive,
    gctUINT hsync_start,
    gctUINT hsync_end,
    gctUINT htotal,
    gctUINT vactive,
    gctUINT vsync_start,
    gctUINT vsync_end,
    gctUINT vtotal
    );

vivSTATUS viv_get_vblank_count(
    viv_display display,
    gctUINT32 *count
    );

vivSTATUS viv_set_output(
    viv_display display,
    viv_output *output,
    gctBOOL enable
    );

vivSTATUS viv_reset_dbi(
    );

vivSTATUS viv_set_output_dbi(
    viv_display display,
    viv_dbi_type type
    );

#if vivENABLE_DISPLAY_R2Y
vivSTATUS viv_set_output_csc(
    viv_display display,
    gctBOOL fullRange,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    );
#endif

vivSTATUS viv_set_commit(
    gctUINT32 display_mask
    );

vivSTATUS viv_layer_enable(
    gctBOOL enable
    );

#if vivENABLE_SEC
/* set security layer */
vivSTATUS viv_layer_security(
    gctBOOL layer_sec
    );

vivSTATUS viv_cursor_security(
    viv_display display,
    gctBOOL  enable
    );
#endif

vivSTATUS viv_dc_reset(
    gctVOID
    );

vivSTATUS viv_dc_init_lcd(
    gctVOID
    );

#if vivENABLE_DISPLAY_CRC
vivSTATUS viv_set_crc_range(
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect *range
    );

vivSTATUS viv_get_crc_value(
    gctUINT index,
    gctUINT *value
    );
#endif

#if vivENABLE_DUALOS
/*
 * Get layer status.
 *
 *  @status
 @     point to current layer status object.
 */
vivSTATUS viv_layer_get_status(
    viv_layer_status *status
    );

/*
 * request layer contorl.
 *
 *  @success
 @     0 means get layer control fail,1 means get layer control success.
 */
vivSTATUS viv_dc_request(
    gctBOOL *success
    );

/*
 * enable/disable dc interrupt
 *
 *  @enable
 @     vivFALSE means disable interrupt,vivTRUE means enable interrupt.
 */
gctVOID viv_dc_interrupt_enable(
    gctBOOL enable
    );
#endif
#endif

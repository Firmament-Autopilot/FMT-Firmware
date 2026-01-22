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


#ifndef _VIV_DC_HARDWARE_H_
#define _VIV_DC_HARDWARE_H_

#include "viv_dc_core.h"

#define __gcmSTART(reg_field) \
    (0 ? reg_field)

#define __gcmEND(reg_field) \
    (1 ? reg_field)

#define __gcmGETSIZE(reg_field) \
    (__gcmEND(reg_field) - __gcmSTART(reg_field) + 1)

#define __gcmALIGN(data, reg_field) \
    (((gctUINT32) (data)) << __gcmSTART(reg_field))

#define __gcmMASK(reg_field) \
    ((gctUINT32) ((__gcmGETSIZE(reg_field) == 32) \
    ?  ~0UL \
    : (~(~0UL << __gcmGETSIZE(reg_field)))))

/*******************************************************************************
**
**  gcmSETFIELD
**
**      Set the value of a field within specified data.
**
**  ARGUMENTS:
**
**      data    Data value.
**      reg     Name of register.
**      field   Name of field within register.
**      value   Value for field.
*/
#define gcmSETFIELD(data, reg, field, value) \
    ( \
    (((gctUINT32) (data)) \
    & ~__gcmALIGN(__gcmMASK(reg##_##field), reg##_##field)) \
    |  __gcmALIGN((gctUINT32) (value) \
    & __gcmMASK(reg##_##field), reg##_##field) \
    )

/*******************************************************************************
**
**  gcmSETFIELDVALUE
**
**      Set the value of a field within specified data with a
**      predefined value.
**
**  ARGUMENTS:
**
**      data    Data value.
**      reg     Name of register.
**      field   Name of field within register.
**      value   Name of the value within the field.
*/
#define gcmSETFIELDVALUE(data, reg, field, value) \
    ( \
    (((gctUINT32) (data)) \
    & ~__gcmALIGN(__gcmMASK(reg##_##field), reg##_##field)) \
    |  __gcmALIGN(reg##_##field##_##value \
    & __gcmMASK(reg##_##field), reg##_##field) \
    )

typedef struct _viv_dc_hardware {
    struct _viv_dc_os *os;

    gctUINT chip_id;
    gctUINT chip_info;
    gctUINT chip_revision;
    gctUINT chip_patch_revision;
    gctUINT product_id;
    gctUINT eco_id;
    gctUINT customer_id;
    gctUINT product_date;
    gctUINT product_time;
    gctBOOL info_got;
}
viv_dc_hardware;

vivSTATUS viv_init_reg_config(
    gctVOID
    );

gctUINT viv_get_reg_config(
    gctUINT addr
    );

vivSTATUS viv_set_reg_config(
    gctUINT addr,
    gctUINT config
    );

#if vivENABLE_DISPLAY_CRC
vivSTATUS viv_hw_reset_sw_stat(
    gctVOID
    );
#endif

vivSTATUS dc_query_hardware_chip_identity(
    viv_dc_hardware *hardware,
    viv_interface_query_chip_identity_ptr Identity
    );

vivSTATUS viv_hw_version_get(
    viv_dc_hardware *hardware,
    gctUINT* chip_id,
    gctUINT* chip_revision,
    gctUINT* chip_patch_revision,
    gctUINT* chip_info,
    gctUINT* product_id,
    gctUINT* eco_id,
    gctUINT* customer_id,
    gctUINT* product_date,
    gctUINT* product_time
    );

#if vivENABLE_LAYER_DECOMPRESS
vivSTATUS viv_hw_dec400_init(
    viv_dc_hardware* hardware
    );

vivSTATUS viv_hw_dec400_stream_disable(
    viv_dc_hardware* hardware,
    gctUINT32 stream_index
    );

vivSTATUS viv_hw_dec400_stream_set(
    viv_dc_hardware* hardware,
    gctUINT32 buffer_base,
    gctUINT32 buffer_end,
    gctUINT32 tile_status_base,
    viv_input_format_type format,
    viv_tiling_type dc_tile_mode,
    viv_cache_mode cache_mode,
    gctUINT32 stream_index,
    gctUINT32 fast_clear_value
    );
#endif

vivSTATUS viv_hw_shadow_register_pending_enable(
    viv_dc_hardware *hardware,
    gctBOOL enable,
    gctBOOL *layer_dirty,
    gctBOOL *display_dirty
    );

#if vivENABLE_DISPLAY_R2Y
vivSTATUS viv_hw_set_output_csc(
    viv_dc_hardware *hardware,
    viv_display id,
    gctINT *coef
    );
#endif

vivSTATUS viv_hw_dither_enable(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT low,
    gctUINT high
    );

#if vivENABLE_WRITEBACK
vivSTATUS viv_hw_set_write_back_dither(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT low,
    gctUINT high
    );

vivSTATUS viv_hw_set_dest_address(
    viv_dc_hardware *hardware,
    gctBOOL enable,
    viv_display id,
    viv_dc_buffer *buffer_ptr,
    viv_write_back_type type
    );

vivSTATUS viv_hw_set_dest_stride(
    viv_dc_hardware *hardware,
    viv_display id,
    gctUINT stride
    );
#endif

vivSTATUS viv_hw_gamma_set_config(
    viv_dc_hardware *hardware,
    gctUINT disp_id,
    gctUINT16 gamma[][3]
    );

vivSTATUS viv_hw_set_background(
    viv_dc_hardware *hardware,
    viv_display display_id,
    viv_dc_color bg_color
    );

#if vivENABLE_DISPLAY_CLRBAR
vivSTATUS viv_hw_set_color_bar(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect range,
    viv_dc_color color
    );
#endif

#if vivENABLE_DISPLAY_CRC
vivSTATUS viv_hw_set_crc_range(
    viv_dc_hardware *hardware,
    gctUINT i,
    gctBOOL enable,
    viv_dc_rect range
    );

vivSTATUS viv_hw_get_crc_value(
    viv_dc_hardware *hardware,
    gctUINT index,
    gctUINT32 *value
    );
#endif

vivSTATUS viv_hw_set_qos(
    viv_dc_hardware* hardware,
    gctUINT32 low,
    gctUINT32 high
    );

vivSTATUS viv_hw_cursor_hotspot(
    viv_dc_hardware* hardware,
    viv_display display_id,
    viv_cursor* cursor_ptr
    );

vivSTATUS viv_hw_cursor_set(
    viv_dc_hardware* hardware,
    viv_display display_id,
    gctBOOL enable,
    viv_dc_buffer* buffer_ptr,
    viv_cursor* cursor_ptr
    );

vivSTATUS viv_hw_layer_clear(
    viv_dc_hardware *hardware,
    gctUINT layer_id,
    viv_dc_layer layer
    );

#if vivENABLE_LAYER_ROI
vivSTATUS viv_hw_layer_roi(
    viv_dc_hardware *hardware,
    gctUINT layer_id,
    viv_dc_layer layer
    );
#endif

#if vivENABLE_LAYER_SCALE
vivSTATUS viv_hw_scale_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_filter_tap_type filter,
    gctUINT32 factorx,
    gctUINT32 factory,
    gctUINT32 *hor_kernel,
    gctUINT32 *ver_kernel,
    gctBOOL enable
    );
#endif

vivSTATUS viv_hw_layer_set_watermark(
    viv_dc_hardware *hardware,
    gctUINT id,
    gctUINT32 value
    );

vivSTATUS viv_hw_layer_set_position(
    viv_dc_hardware *hardware,
    gctUINT layer_id,
    viv_dc_layer layer,
    viv_display_size_type size
    );

vivSTATUS viv_hw_layer_colorkey_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer
    );

vivSTATUS viv_hw_layer_y2r_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer
    );

vivSTATUS viv_hw_layer_r2r_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer
    );

vivSTATUS viv_hw_set_alpha(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_layer_alpha_mode alpha
    );

vivSTATUS viv_hw_set_blend_mode(
    viv_dc_hardware *hardware,
    gctUINT id,
    gctBOOL enable,
    viv_porter_duff_mode mode,
    viv_layer_alpha_mode alpha_mode
    );

vivSTATUS viv_hw_layer_set_zorder(
    viv_dc_hardware *hardware
    );

vivSTATUS viv_hw_layer_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer,
    gctBOOL gamma
    );

vivSTATUS viv_hw_display_set_size(
    viv_dc_hardware *hardware,
    viv_display id,
    viv_display_size_type size,
    gctBOOL *mem2mem
    );

/* Set custom display size */
vivSTATUS viv_hw_set_custom_display_size(
    viv_dc_hardware *hardware,
    viv_display id,
    gctUINT hactive,
    gctUINT hsync_start,
    gctUINT hsync_end,
    gctUINT htotal,
    gctUINT vactive,
    gctUINT vsync_start,
    gctUINT vsync_end,
    gctUINT vtotal,
    gctBOOL *mem2mem
    );

vivSTATUS viv_hw_display_set_output(
    viv_dc_hardware *hardware,
    viv_display id,
    gctBOOL enable,
    viv_output output,
    gctBOOL gamma_enable,
#if vivENABLE_DISPLAY_R2Y
    gctBOOL rgb2yuv,
#endif
    gctBOOL threed_lut_enable
    );

vivSTATUS viv_hw_start_panel_set_config(
    viv_dc_hardware *hardware,
    gctUINT32 mask
    );

vivSTATUS viv_hw_display_dbi_reset(
    viv_dc_hardware *hardware
    );

vivSTATUS viv_hw_display_dbi_set_command(
    viv_dc_hardware *hardware,
    viv_display_format_type format,
    viv_dbi_command_type type,
    gctUINT command
    );

vivSTATUS viv_hw_display_dbi_set_config(
    viv_dc_hardware *hardware,
    viv_dbi_type type,
    viv_display_format_type format
    );

vivSTATUS viv_hw_display_dbi_set_write(
    viv_dc_hardware *hardware
    );

vivSTATUS viv_hw_dbi_reset(
    viv_dc_hardware *hardware
    );

vivSTATUS viv_hw_dbi_set_command(
    viv_dc_hardware *hardware,
    gctUINT type,
    gctUINT command
    );

#if vivENABLE_DISPLAY_3DLUT
vivSTATUS viv_hw_3d_lut_set_config(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT32* lut
    );

vivSTATUS viv_hw_3d_lut_ex_config(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctUINT32* scale_val,
    gctUINT32* offset_val
    );

vivSTATUS viv_hw_3d_lut_set_enlarge(
    viv_dc_hardware *hardware,
    viv_display display_id,
    viv_lut_enlarge value
    );
#endif

vivSTATUS viv_hw_cursor_set_pos(
    viv_dc_hardware *hardware,
    gctUINT x,
    gctUINT y
    );

vivSTATUS viv_hw_cursor_move(
    viv_dc_hardware *hardware,
    viv_display display_id,
    viv_cursor* cursor_ptr
    );

vivSTATUS viv_hw_interrupt_enable(
    viv_dc_hardware *hardware,
    gctBOOL enable
    );

gctUINT viv_hw_interrupt_get(
    viv_dc_hardware *hardware
    );

gctUINT viv_hw_get_vblank_counter(
    viv_dc_hardware *hardware
    );

vivSTATUS viv_hw_dc_reset(
    viv_dc_hardware *hardware
    );

/*
 * set dc interrupt enable/disable.
 *  @hardware:
 *     point to hardware object.
 *  @interrupt_enable
 @     vivFALSE means disable interrupt,vivTRUE means enable interrupt.
 */
gctVOID viv_hw_enable_interrupt(
    viv_dc_hardware *hardware,
    gctBOOL *interrupt_enable);

#if vivENABLE_DUALOS
/*
 * Get layer status.
 *  @hardware:
 *     point to hardware object.
 *  @hw_layer:
 *     the current layer.
 *  @status
 @     point to current layer status object.
 */
vivSTATUS viv_hw_get_layer_status(
    viv_dc_hardware *hardware,
    gctUINT hw_layer,
    viv_layer_status *status);

/*
 * request layer contorl.
 *  @hardware:
 *     point to hardware object.
 *  @success
 @     0 means get layer control fail,1 means get layer control success.
 */
vivSTATUS viv_hw_request_control(
    viv_dc_hardware *hardware,
    gctBOOL *success);
#endif
#endif

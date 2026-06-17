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


#ifndef _VIV_DC_CORE_H_
#define _VIV_DC_CORE_H_

#include "viv_dc_type.h"
#include "viv_dc_options.h"
#include "viv_dc_internal_type.h"
#include "dc_layer_feature.h"

/*#include <linux/spinlock_types.h>*/

typedef struct _viv_dc_os viv_dc_os;

typedef enum _viv_dc_interrupt_type {
    vivDC_INT_DEC400_FLUSH = 0,
    vivDC_INT_LAYER_CONFLICT,
    vivDC_INT_AXI_BUS_ERR,
    vivDC_INT_SW_RESET_DONE,
    vivDC_INT_COUNT
}
viv_dc_interrupt_type;

#if vivENABLE_DISPLAY_3DLUT
#define THREED_LUT_SIZE 17*17*17
#define THREED_LUT_CHANNEL 3
#endif

#if vivENABLE_DISPLAY_CLRBAR
#define DC_COLORBAR_NUM 16
#endif

typedef struct _viv_dc_display {
    /* layer */
    viv_dc_layer  layers[DC_LAYER_NUM];
    gctBOOL       layer_dirty[DC_LAYER_NUM];
#if vivENABLE_SEC
    gctBOOL       layer_security[DC_LAYER_NUM];
#endif

    /* cursor */
    gctBOOL       cursor_enable[DC_CURSOR_NUM];
    viv_cursor    cursors[DC_CURSOR_NUM];
    viv_dc_buffer cursor_buffer[DC_CURSOR_NUM];
    gctBOOL       cursor_dirty[DC_CURSOR_NUM];
#if vivENABLE_SEC
    gctBOOL       cursor_security[DC_CURSOR_NUM];
#endif

    /* pure color background */
    viv_dc_color   bg_color[DC_DISPLAY_NUM];
    gctBOOL        bg_dirty[DC_DISPLAY_NUM];

    /* color bar */
#if vivENABLE_DISPLAY_CLRBAR
    gctBOOL        colorbar_enabled[DC_DISPLAY_NUM][DC_COLORBAR_NUM];
    gctBOOL        colorbar_dirty[DC_DISPLAY_NUM][DC_COLORBAR_NUM];
    viv_dc_rect    colorbar_range[DC_DISPLAY_NUM][DC_COLORBAR_NUM];
    viv_dc_color   colorbar_color[DC_DISPLAY_NUM][DC_COLORBAR_NUM];
#endif

    /* display */
    viv_display_size_type  size[DC_DISPLAY_NUM];
    viv_output             output[DC_DISPLAY_NUM];
    gctBOOL                display_enable[DC_DISPLAY_NUM];
    viv_dbi_type           dbi_type[DC_DISPLAY_NUM];
    gctBOOL                display_dirty[DC_DISPLAY_NUM];
    gctUINT                dpy_hline, dpy_htotal;
    gctUINT                dpy_vline, dpy_vtotal;
    gctUINT                dpy_hsync_start, dpy_hsync_end;
    gctUINT                dpy_vsync_start, dpy_vsync_end;

    /* gamma */
    gctBOOL          gamma_enabled[DC_DISPLAY_NUM];
    viv_dc_gamma     gamma_table[DC_DISPLAY_NUM];
    gctBOOL          gamma_dirtys[DC_DISPLAY_NUM];

    /* lut */
    gctBOOL          lut_enable[DC_DISPLAY_NUM];
#if vivENABLE_DISPLAY_3DLUT
    gctUINT32        lut_table[DC_DISPLAY_NUM][THREED_LUT_SIZE];
    gctUINT32        lut_scale_val[DC_DISPLAY_NUM][THREED_LUT_CHANNEL];
    gctUINT32        lut_offset_val[DC_DISPLAY_NUM][THREED_LUT_CHANNEL];
    viv_lut_enlarge  lut_enlarge_val[DC_DISPLAY_NUM];
    gctBOOL          lut_dirty[DC_DISPLAY_NUM];
#endif

    /* dither */
    gctBOOL          dither_enabled[DC_DISPLAY_NUM];
    gctBOOL          dither_dirtys[DC_DISPLAY_NUM];
    gctUINT          table_low[DC_DISPLAY_NUM];
    gctUINT          table_high[DC_DISPLAY_NUM];

    /* write back dither */
#if vivENABLE_WRITEBACK
    gctBOOL          wb_dither_enable[DC_DISPLAY_NUM];
    gctBOOL          wb_dither_dirty[DC_DISPLAY_NUM];
    gctUINT          wb_table_low[DC_DISPLAY_NUM];
    gctUINT          wb_table_high[DC_DISPLAY_NUM];

    /* dest */
    gctBOOL              writeback_enable[DC_DISPLAY_NUM];
    viv_dc_buffer        writeback_buffer[DC_DISPLAY_NUM];
    viv_write_back_type  writeback_type[DC_DISPLAY_NUM];
    gctBOOL              dest_dirty[DC_DISPLAY_NUM];
#endif
    gctBOOL              mem2mem[DC_DISPLAY_NUM];
    /* qos */
    gctUINT32 qos_low;
    gctUINT32 qos_high;
    gctBOOL   qos_dirty;

    /* output csc */
#if vivENABLE_DISPLAY_R2Y
    viv_csc_mode   r2y_mode[DC_DISPLAY_NUM];
    gctINT         r2y_coef[DC_DISPLAY_NUM][RGB2YUV_COEF_NUM];
    gctBOOL        r2y_dirty[DC_DISPLAY_NUM];
    gctBOOL        r2y_enable[DC_DISPLAY_NUM];
#endif

    /* crc */
#if vivENABLE_DISPLAY_CRC
    gctBOOL        crc_enable[MAX_CRC_NUM];
    viv_dc_rect    crc_rect[MAX_CRC_NUM];
    gctUINT32      crc_value[MAX_CRC_NUM];
    gctBOOL        crc_dirty[MAX_CRC_NUM];
#endif

    /* commit */
    gctUINT32      display_mask;
}
viv_dc_display;

typedef struct _viv_dc_core {
    /* os */
    struct _viv_dc_os *os;

    /* hardware */
    struct _viv_dc_hardware *hardware;

#if ALLOC_RESERVED_MEM_IN_KERNEL
    viv_mem_node_list_table* reserved_mem;
#endif

#if ((vivENABLE_MMU) || (vivENABLE_SEC))
    struct _viv_dc_hardware *hw_sec;
#endif

    struct _viv_dc_display display;

    /*interrupt handle*/
    gctBOOL interrupts[vivDC_INT_COUNT];
    gctUINT32 vblank_count[2];

#if vivENABLE_MMU
    /* MMU */
    struct _dc_mmu *mmu;
#endif
}
viv_dc_core;

/* To be extended. */
typedef struct _viv_dc_device {
    /* dc cores. */
    viv_dc_core *core[MULTI_DC_NUM];

#if vivENABLE_MMU
    /* MMU */
    struct _dc_mmu *mmu;
#endif
}
viv_dc_device;

/************************************************************************
 * Below is the main interface.
 * It can be called directly after initialiation.
 ************************************************************************/
#if vivENABLE_LAYER_DECOMPRESS
/*
 * DEC400 configuration
 */
gctVOID viv_conf_dec400_config(
    viv_dc_core *core,
    gctUINT layerId
    );

gctVOID viv_conf_dec400_disable(
    viv_dc_core *core,
    gctUINT layerId
    );

gctVOID viv_conf_dec400_commit(
    viv_dc_core *core
    );
#endif

/*
 * Reset the dc.
 *
 *  @core:
 *     Point to core object.
 */
vivSTATUS viv_conf_dc_reset(
    viv_dc_core *core
    );

/*
 * Enable/disable the layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @enable:
 *     enable/disable layer.
 */
gctVOID viv_conf_layer_enable(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable
    );

#if vivENABLE_SEC
/*
 * Enable/disable layer security.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @enable:
 *     enable/disable layer security.
 */
vivSTATUS viv_conf_layer_security(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable
    );
#endif

/*
 * Set the following attributes of buffer: size, stride, foramt.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @buffer:
 *     layer buffer.
 */
gctVOID viv_conf_layer_set_buffer(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_buffer *buffer
    );

/*
 * Set colorkey related configuration for layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @colorkey:
 *     colorkey value for layer layer.
 *
 *  @colorkey_high:
 *     colorkey high value for layer layer.
 *
 *  @transparency:
 *     enable/ disable transparency for layer.
 */
gctVOID viv_conf_layer_set_colorkey(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_color colorkey,
    viv_dc_color colorkey_high,
    gctBOOL transparency
    );

#if vivENABLE_LAYER_ROT
/*
 * Set rotation related configuration for layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @rotation:
 *     rotation angle.
 */
gctVOID viv_conf_layer_set_rotation(
    viv_dc_core *core,
    gctUINT id,
    viv_rotation_type rotation
    );
#endif

#if vivENABLE_LAYER_SCALE
/*
 * Set scale related configuration for layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @filter:
 *     Horizontal and vertical scaling tap configuration.
 *
 *  @horkernel:
 *     the pointer of horizontal filter kernel coefficient table.
 *
 *  @verkernel:
 *     the pointer of vertical filter kernel coefficient table.
 *
 *  @factorx:
 *     scale factor x.
 *
 *  @factory:
 *     scale factor y.
 *
 *  @enable:
 *     enable/disable scale.
 */
gctVOID viv_conf_layer_set_scale(
    viv_dc_core *core,
    gctUINT id,
    viv_filter_tap_type filter,
    gctUINT32 *horkernel,
    gctUINT32 *verkernel,
    gctUINT32 factorx,
    gctUINT32 factory,
    gctBOOL enable
    );
#endif

/*
 * Set scale related configuration for layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @rect:
 *     Display rectangle.
 */
gctVOID viv_conf_layer_set_rect(
    viv_dc_core *core,
    gctUINT id,
    viv_dc_rect rect
    );


#if vivENABLE_LAYER_DECOMPRESS
/*
 * Set decompress related configuration for layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @enable:
 *     enable/disable compression for layer.
 *
 *  @buffer:
 *     Pointer to tile status buffer.
 */
gctVOID viv_conf_layer_set_decompress(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable,
    viv_tilestatus_buffer buffer
    );

/*
 * Set cache mode of compression.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @mode:
 *     cache mode.
 */
gctVOID viv_conf_layer_set_cache_mode(
    viv_dc_core *core,
    gctUINT id,
    viv_cache_mode mode
    );
#endif

/*
 * Set watermark value for layer.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @value:
 *     watermark value.
 */
gctVOID viv_conf_layer_set_watermark(
    viv_dc_core *core,
    gctUINT id,
    gctUINT32 value
    );

/*
 * sets source/ dest alpha value and mode.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @alpha:
 *     which contains settings for the alpha configuration.
 */
gctVOID viv_conf_layer_set_alpha(
    viv_dc_core *core,
    gctUINT id,
    viv_layer_alpha_mode alpha
    );

/*
 * sets poterbuff blend mode.
 *
 *  @core:
 *     Point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @enable:
 *     enable/ disable alpha blending.
 *
 *  @mode:
 *     Porter duff blending mode.
 */
gctVOID viv_conf_layer_set_poterbuff_blend_mode(
    viv_dc_core *core,
    gctUINT id,
    gctBOOL enable,
    viv_porter_duff_mode mode
    );

/*
 * Set zorder for layer.
 *
 *  @core:
 *     point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @value:
 *     zorder value of this layer.
 */
gctVOID viv_conf_layer_set_zorder(
    viv_dc_core *core,
    gctUINT id,
    gctUINT8 value
    );

/*
 * Set which display/output that layer displayed.
 *
 *  @core:
 *     point to core object.
 *
 *  @id:
 *     layer buffer id.
 *
 *  @display_id:
 *     display id of DC.
 */
gctVOID viv_conf_layer_set_display(
    viv_dc_core *core,
    gctUINT id,
    viv_display display_id
    );

/*
 * Set display settings for the display’s horizontal and vertical dimensions, sync and polarity.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display:
 *     display output.
 *
 *  @type:
 *     display size type.
 */
gctVOID viv_conf_display_set_size(
    viv_dc_core *core,
    viv_display display,
    viv_display_size_type type
    );

/*
 * Set custom display settings for the display.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display:
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
    );

/*
 * Set output for display.
 *
 *  @core:
 *     point to core object.
 *
 *  @display:
 *     display output.
 *
 *  @enable:
 *     enable/disable output.
 *
 *  @output:
 *     pointer to the viv_output structure which contains settings for the output configuration.
 */
gctVOID viv_display_conf_set_output(
    viv_dc_core *core,
    viv_display display,
    gctBOOL enable,
    viv_output output
    );

/*
 * reset output dbi.
 *
 *  @core:
 *     point to core object.
 */
gctVOID viv_display_conf_dbi_reset(
    viv_dc_core *core
    );

/*
 * Set dbi config for display.
 *
 *  @core:
 *     point to core object.
 *
 *  @display:
 *     display output.
 *
 *  @dbi_type:
 *     dbi type:
 */
gctVOID viv_display_conf_dbi_set_config(
    viv_dc_core *core,
    viv_display display,
    viv_dbi_type dbi_type
    );

#if vivENABLE_DISPLAY_R2Y
/*
 * Set programmable output csc factor.
 *
 *  @core:
 *     point to core object.
 *
 *  @display:
 *     display id.
 *
 *  @full_range:
 *     if clamp.
 *
 *  @mode:
 *     Csc mode to use, include vivCSC_BT601/vivCSC_BT709/vivCSC_BT2020/vivCSC_USER_DEF.
 *
 *  @coef:
 *     Programmble csc factors.
 *
 *  @num:
 *     valid number of factors.
 *
 */
gctVOID viv_display_conf_set_output_csc(
    viv_dc_core *core,
    viv_display display,
    gctBOOL full_range,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    );
#endif

#if vivENABLE_WRITEBACK
/*
* set write back dither.
*
*  @core:
*     Point to core object.
*
*  @enable:
*     Enable write back dither or not.
*     Parameters: SET_ENABLE / SET_DISABLE
*
*  @display_id:
*    Display output id.
*
*  @table_low:
*     Dither table of refreence value is 64bits. These are the lower 32 bits.
*     Y0_X0    3:0  Dither reference value at coordinate (0, 0)
*     Y0_X1    7:4  Dither reference value at coordinate (1, 0)
*     Y0_X2   11:8  Dither reference value at coordinate (2, 0)
*     Y0_X3  15:12  Dither reference value at coordinate (3, 0)
*     Y1_X0  19:16  Dither reference value at coordinate (0, 1)
*     Y1_X1  23:20  Dither reference value at coordinate (1, 1).
*     Y1_X2  27:24  Dither reference value at coordinate (2, 1)
*     Y1_X3  31:28  Dither reference value at coordinate (3, 1)
*
*  @table_high:
*     Dither table of reference value is 64bits. These are the high 32 bits.
*     Y2_X0    3:0  Dither reference value at coordinate (0, 2)
*     Y2_X1    7:4  Dither reference value at coordinate (1, 2)
*     Y2_X2   11:8  Dither reference value at coordinate (2, 2)
*     Y2_X3  15:12  Dither reference value at coordinate (3, 2)
*     Y3_X0  19:16  Dither reference value at coordinate (0, 3)
*     Y3_X1  23:20  Dither reference value at coordinate (1, 3).
*     Y3_X2  27:24  Dither reference value at coordinate (2, 3)
*     Y3_X3  31:28  Dither reference value at coordinate (3, 3)
*/
gctVOID viv_conf_set_write_back_dither(
viv_dc_core *core,
gctBOOL enable,
viv_display display_id,
gctUINT table_low,
gctUINT table_high
);

/*
 * Set dest buffer physical address and stride.
 *
 *  @core:
 *     point to core object.
 *
 *  @enable:
 *     enable writeback or not.
 *
 *  @display:
 *     display id.
 *
 *  @buffer_ptr:
 *     Point to viv_dc_buffer object.
 *
 *  @type:
 *     The write back type.
 */
gctVOID viv_display_conf_set_dest(
    viv_dc_core *core,
    gctBOOL enable,
    viv_display display,
    viv_dc_buffer *buffer_ptr,
    viv_write_back_type type
    );

/*
* Commit the set of write back.
*
*  @core:
*     Point to core projrct.
*/
gctVOID viv_conf_dest_commit(
    viv_dc_core *core
    );
#endif

/*
 * Commit the set of layer.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_layer_commit(
    viv_dc_core *core
    );

/*
 * Commit the set of background.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_background_commit(
    viv_dc_core *core
    );

/*
 * Commit the set of cursor.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_cursor_commit(
    viv_dc_core *core
    );

/*
 * Commit the value of qos.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_qos_commit(
    viv_dc_core *core
    );

/*
 * Commit the value of qos.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_dither_commit(
    viv_dc_core* core
    );

/*
 * Commit the display.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_conf_display_commit(
    viv_dc_core *core
    );

#if vivENABLE_DISPLAY_R2Y
/*
 * Commit the output csc.
 *
 *  @core:
 *     Point to core object.
 */
gctVOID viv_conf_output_csc_commit(
    viv_dc_core *core
    );
#endif

 /*
  *  Reset DBI interface to idle state.
  *
  *  @core:
  *     Point to core object.
  */
gctVOID viv_conf_output_dbi_reset(
    viv_dc_core *core
    );

 /*
  * Enable/Disable dither.
  *
  *  @core:
  *     Point to core object.
  *
  *  @enable:
  *     Enable dither or not.
  *     When enabled, R8G8B8 mode show better on panels with fewer bits per pixel.
  *     Parameters: SET_ENABLE / SET_DISABLE
  */
gctVOID viv_conf_dither_enable(
    viv_dc_core *core,
    viv_display display_id,
    gctBOOL enable
    );

 /*
  * Set dither setting.
  *
  *  @core:
  *     Point to core object.
  *
  *  @red_channel:
  *     Significant bit width for red channel.
  *
  *  @green_channel:
  *     Significant bits width for green channel.
  *
  *  @blue_channel:
  *     Significant bits width for blue channel.
  *
  *  @table_low:
  *     Dither table of refreence value is 64bits. These are the lower 32 bits.
  *     Y0_X0    3:0  Dither reference value at coordinate (0, 0)
  *     Y0_X1    7:4  Dither reference value at coordinate (1, 0)
  *     Y0_X2   11:8  Dither reference value at coordinate (2, 0)
  *     Y0_X3  15:12  Dither reference value at coordinate (3, 0)
  *     Y1_X0  19:16  Dither reference value at coordinate (0, 1)
  *     Y1_X1  23:20  Dither reference value at coordinate (1, 1).
  *     Y1_X2  27:24  Dither reference value at coordinate (2, 1)
  *     Y1_X3  31:28  Dither reference value at coordinate (3, 1)
  *
  *  @table_high:
  *     Dither table of reference value is 64bits. These are the high 32 bits.
  *     Y2_X0    3:0  Dither reference value at coordinate (0, 2)
  *     Y2_X1    7:4  Dither reference value at coordinate (1, 2)
  *     Y2_X2   11:8  Dither reference value at coordinate (2, 2)
  *     Y2_X3  15:12  Dither reference value at coordinate (3, 2)
  *     Y3_X0  19:16  Dither reference value at coordinate (0, 3)
  *     Y3_X1  23:20  Dither reference value at coordinate (1, 3).
  *     Y3_X2  27:24  Dither reference value at coordinate (2, 3)
  *     Y3_X3  31:28  Dither reference value at coordinate (3, 3)
  */
gctVOID viv_conf_dither_set_config(
    viv_dc_core *core,
    viv_display display_id,
    gctUINT table_low,
    gctUINT table_high
    );

 /*
  * Enable/Disable gamma correction.
  *
  *  @core:
  *     Point to core object.
  *
  *  @disp_id:
  *    Display output id.
  *
  *  @enable:
  *     Enable gamma correction or not.
  *     Parameters: SET_ENABLE / SET_DISABLE
  */
gctVOID viv_conf_enable_gamma(
    viv_dc_core *core,
    viv_display  disp_id,
    gctBOOL      enable
    );

 /*
  * Set gamma translation value.
  *
  *  @core:
  *     Point to core object.
  *
  *  @disp_id:
  *    Display output id.
  *
  *  @index:
  *     Index into the Gamma LUT.
  *     Each index is corresponding to one set of red+green+blue gamma value.
  *
  *  @red:
  *     Gamma correction RED value
  *
  *  @green:
  *     Gamma correction GREEN value
  *
  *  @blue:
  *     Gamma correction BLUE value
  */
gctVOID viv_conf_gamma_set_config(
    viv_dc_core  *core,
    viv_display  disp_id,
    gctUINT   index,
    gctUINT16 red,
    gctUINT16 green,
    gctUINT16 blue
    );

#if vivENABLE_DISPLAY_3DLUT
/*
 * Sets 3d lut table.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     display id.
 *
 *  @enable:
 *     Enable 3D-LUT. When set to 1, 3D-LUT is enabled
 *
 *  @index:
 *     index of lut value
 *
 *  @lut:
 *     Pointer to lookup table for 3D-LUT.
 */
gctVOID viv_conf_3d_lut_set_config(
    viv_dc_core *core,
    viv_display display_id,
    gctBOOL enable,
    gctUINT32 index,
    gctUINT32 lut
    );

/*
 * Sets enlarge value for 3d lut.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     display id.
 *
 *  @enlarge:
 *     Enlarge value.
 */
gctVOID viv_conf_3d_lut_set_enlarge(
    viv_dc_core *core,
    viv_display display_id,
    viv_lut_enlarge enlarge
    );
#endif

 /*
  * Enable/Disable interrupt.
  *
  *  @core:
  *     Point to core object.
  *
  *  @enable:
  *     Enable dc interrupt or not
  *     Parameters: SET_ENABLE / SET_DISABLE
  */
gctVOID viv_conf_interrupt_enable(
    viv_dc_core *core,
    gctBOOL enable
    );

 /*
  * Query chip feature support.
  *
  *  @core:
  *     Point to core object.
  */
gctVOID viv_conf_query_feature_support(
    viv_dc_core *core
    );

/*
 * Set start panel for commit.
 *
 *  @core:
 *     point to core object.
 */
gctVOID viv_conf_start_panel_commit(
    viv_dc_core *core
    );

/*
 * Reset all dirty.
 *
 *  @core:
 *     point to core object.
 */
gctVOID viv_conf_reset_dirty(
    viv_dc_core *core
    );

 /*
  * Commit the commands to DC after setting.
  *
  *  @core:
  *     Point to core object.
  */
gctVOID viv_conf_commit(
    viv_dc_core *core
    );

 /*
  * Get interrupt.
  *
  * Return interrupt signal if existed.
  * The signal will be pulled up only after enable interrupt through viv_conf_interrupt_enable().
  *
  *  @core:
  *     Point to core object.
  */
gctUINT viv_conf_interrupt_get(
    viv_dc_core *core
    );

 /*
  * Get hardware info.
  *
  *  @core:
  *     Point to core object.
  *
  *  @chip_id:
  *     Show the ID for the chip in BCD.
  *
  *  @chip_revision:
  *     Show the revision for the chip in BCD.
  *
  *  @chip_patch_revision:
  *     Show the patch revision level for the chip.
  *
  *  @chip_info:
  *     Show chip info.
  *
  *  @product_id:
  *     Show product id.
  *
  *  @product_date:
  *     Show the release date for the IP.
  *
  *  @product_time:
  *     Show the release time for the IP.
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
    );

gctVOID dc_conf_query_chip_identity(
    viv_dc_core *core,
    viv_interface_query_chip_identity_ptr Identity
    );

#if vivENABLE_ADDRESS_40BITS
 /*
  *  Check whether the tilestatus buffer and data buffer address valid.
  *
  *  @core:
  *     Point to core object.
  */
vivSTATUS viv_check_buffer_address_valid(
    viv_dc_core *core
    );
#endif

/*
 * Enable/Disable layer clear.
 *
 *  @core:
 *     Point to core object.
 *
 *  @layer_id:
 *     Which layer need to be cleard.
 *
 *  @enable:
 *     Enable layer clear or not.
 *     Parameters: SET_ENABLE / SET_DISABLE
 */
 gctVOID viv_layer_clear_enable(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL enable
    );

/*
 * set clear color for layer which is specified by layer_id.
 *
 *  @core:
 *     Point to core object.
 *
 *  @layer_id:
 *     Which layer need to be cleard.
 *
 *  @clear_color_ptr:
 *     Color is used to clear layer which is specified by layer_id.
 */
gctVOID viv_layer_clear_color(
    viv_dc_core  *core,
    gctUINT layer_id,
    viv_dc_color* clear_color_ptr
    );

/*
 * Layer csc y2r set.
 *
 *  @core:
 *     Point to core object.
 *
 *  @layer_id:
 *     Which layer to set.
 *
 *  @yuvClamp:
 *     Enable/disable yuvClamp.
 *
 *  @mode:
 *     Csc mode to use, include vivCSC_BT601/vivCSC_BT709/vivCSC_BT2020/vivCSC_USER_DEF.
 *
 *  @coef:
 *     If mode is vivCSC_USER_DEF, point to user's csc coefficients.
 *
 *  @num:
 *     The num of the coefficients.
 */
gctVOID viv_layer_conf_y2r(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL yuvClamp,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    );

/*
 * Layer csc r2r set.
 *
 *  @core:
 *     Point to core object.
 *
 *  @enable:
 *     Enable/disable r2r.
 *
 *  @mode:
 *     Csc mode to use, include vivCSC_BT709/vivCSC_BT2020/vivCSC_USER_DEF.
 *
 *  @coef:
 *     If mode is vivCSC_USER_DEF, point to user's csc coefficients.
 *
 *  @num:
 *     The num of the coefficients.
 */
vivSTATUS viv_layer_conf_r2r(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL enable,
    viv_csc_mode mode,
    gctINT *coef,
    gctUINT num
    );

#if vivENABLE_LAYER_ROI
/*
 * Enable/Disable layer roi.
 *
 *  @core:
 *     Point to core object.
 *
 *  @layer_id:
 *     Which layer need to enable/disable roi.
 *
 *  @enable:
 *     Enable layer roi or not.
 *     Parameters: SET_ENABLE / SET_DISABLE
 */
gctVOID viv_layer_conf_roi_enable(
    viv_dc_core  *core,
    gctUINT layer_id,
    gctBOOL enable
    );

/*
 * set rect for layer which is specified by layer_id.
 *
 *  @core:
 *     Point to core object.
 *
 *  @layer_id:
 *     Which layer need to set roi.
 *
 *  @rect_ptr:
 *    set rect to layer which is specified by layer_id.
 */
gctVOID viv_layer_conf_roi_rect(
    viv_dc_core  *core,
    gctUINT layer_id,
    viv_dc_rect* rect_ptr
    );
#endif

/*
 * set position for layer which is specified by layer_id.
 *
 *  @core:
 *     Point to core object.
 *
 *  @layer_id:
 *     Which layer needs to set lut.
 *
 *  @x:
 *     x coordinate value.
 *  @y:
 *     y coordinate value.
 */
gctVOID viv_layer_conf_set_position(
    viv_dc_core *core,
    gctUINT layer_id,
    gctUINT x,
    gctUINT y
    );

#if vivENABLE_LAYER_DEGAMMA
 /*
  * Enable/Disable layer degamma correction.
  *
  *  @core:
  *     Point to core object.
  *
  *  @layer_id:
 *     Layer id.
  *
  *  @enable:
  *     Enable degamma correction or not.
  *     Parameters: SET_ENABLE / SET_DISABLE
  */
gctVOID viv_layer_conf_enable_degamma(
    viv_dc_core *core,
    gctUINT layer_id,
    gctBOOL enable
    );

 /*
  * Set degamma translation value.
  *
  *  @core:
  *     Point to core object.
  *
  *  @layer_id:
  *    Layer id.
  *
  *  @index:
  *     Index into the degamma LUT.
  *     Each index is corresponding to one set of red+green+blue degamma value.
  *
  *  @red:
  *     Degamma correction RED value
  *
  *  @green:
  *     Degamma correction GREEN value
  *
  *  @blue:
  *     Degamma correction BLUE value
  */
gctVOID viv_layer_conf_set_degamma(
    viv_dc_core *core,
    gctUINT   layer_id,
    gctUINT   index,
    gctUINT16 red,
    gctUINT16 green,
    gctUINT16 blue
    );
#endif

/*
 * Set display's background color.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which display needs to set background color.
 *
 *  @bg_color_ptr:
 *     Which is used to set display's background color.
 */
gctVOID viv_layer_conf_set_background(
    viv_dc_core* core,
    viv_display display_id,
    viv_dc_color* bg_color_ptr
    );

#if vivENABLE_DISPLAY_CLRBAR
/*
 * Set display's color bar.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which display needs to set color bar.
 *
 *  @enable:
 *    Enables or disables to the color bar.
 *    Parameters:SET_ENABLE/SET_DISABLE.
 *
 *  @index:
 *    The index of the color bar range.
 *    Vaild values range from 0 to 15.
 *
 *  @range:
 *    Thr region of the current index color bar to display on the panel.
 *
 *  @color:
 *     Which is used to set the color of the current index color bar.
 */
vivSTATUS viv_conf_set_color_bar(
    viv_dc_core* core,
    viv_display display_id,
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect* range,
    viv_dc_color* color
    );
#endif

#if vivENABLE_DISPLAY_CRC
/*
 * Set frame or region csc range.
 *
 *  @core:
 *      Point to core object.
 *
 *  @index:
 *      The index of the csc unit.
 *
 *  @enable:
 *      Enable/disable csc
 *
 *  @range:
 *      The coordinate of csc region.
 */
gctVOID viv_crc_set_range(
    viv_dc_core *core,
    gctUINT32 index,
    gctBOOL enable,
    viv_dc_rect* range
    );

/*
 * Get the crc value.
 *  @core:
 *     point to core object.
 *
 *  @index:
 *     CRC unit id.
 *
 *  @value:
 *     The return csc value.
 */
gctVOID viv_crc_get_value(
    viv_dc_core *core,
    gctUINT32 index,
    gctUINT32 *value
    );
#endif

/*
 * Set cursor hotspot's X/Y coordinate specified by display_id .
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which display needs to set hotspot's coordinate.
 *
 *  @hsx:
 *    X coordinate value.
 *
 *  @hsy:
 *     Y coordinate value.
 */
gctVOID viv_cursor_conf_hotspot(
    viv_dc_core* core,
    viv_display display_id,
    gctUINT32 hsx,
    gctUINT32 hsy
    );

/*
 * Set cursor's new position specified by parameters x/y.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which display needs to set new coordinate.
 *
 *  @x:
 *     New x coordinate value.
 *
 *  @y:
 *     New y coordinate value.
 */
gctVOID viv_cursor_conf_move(
    viv_dc_core* core,
    viv_display display_id,
    gctUINT32 x,
    gctUINT32 y
    );

/*
 * Enable to set cursor's initial params.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which display needs to enable set params.
 *
 *  @enable:
 *     Enable set cursor's initial params or not.
 *     Parameters: SET_ENABLE / SET_DISABLE
 */
gctVOID viv_cursor_conf_enable(
    viv_dc_core* core,
    viv_display display_id,
    gctBOOL enable
    );

#if vivENABLE_SEC
/*
 * Enable to set security cursor.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which cursor needs to enable security.
 *
 *  @enable:
 *     Enable security cursor or not.
 */
vivSTATUS viv_cursor_conf_security(
    viv_dc_core *core,
    viv_display display_id,
    gctBOOL enable
    );
#endif

/*
 * Set cursor's initial params.
 *
 *  @core:
 *     Point to core object.
 *
 *  @display_id:
 *     Which display needs to set cursor's initial params.
 *
 *  @buffer_ptr:
 *     Point to viv_dc_buffer object.
 *
 *  @cursor_ptr:
 *     Point to viv_cursor object.
 */
gctVOID viv_cursor_conf_set(
    viv_dc_core* core,
    viv_display display_id,
    viv_dc_buffer* buffer_ptr,
    viv_cursor* cursor_ptr
    );

/*
 * Set dc qos value.
 *
 *  @core:
 *     Point to core object.
 *
 *  @low:
 *     The qos low value.
 *
 *  @high:
 *     The qos high value.
 */
gctVOID viv_dc_conf_qos(
    viv_dc_core* core,
    gctUINT32 low,
    gctUINT32 high
    );

/*
 * Set display for commit.
 *
 *  @core:
 *     point to core object.
 *
 *  @mask:
 *     display0 is bit0, display1 is bit1, if mask = 3, commit displya0 and display1 at the same time.
 */
gctVOID viv_conf_set_display(
    viv_dc_core *core,
    gctUINT32 mask
    );

/*
 * Get the vlbank count of specify display.
 *  @core:
 *     point to core object.
 *  @display:
 *     display id;
 *
 *  @vblank:
 *     return value, will return the vblank count of display
 */
vivSTATUS viv_conf_get_vblank(
    viv_dc_core *core,
    viv_display  display,
    gctUINT32 *vblank
    );

/*
 * Init lcd for dbi case.
 *  @core:
 *     point to core object.
 */
gctVOID viv_init_lcd(
    viv_dc_core *core
    );

#if vivENABLE_DUALOS
/*
 * Get layer status.
 *  @core:
 *     point to core object.
 *  @layer_id:
 *     the id of current layer.
 *  @status
 @     point to current layer status object.
 */
vivSTATUS viv_get_layer_status(
    viv_dc_core *core,
    gctUINT layer_id,
    viv_layer_status *status);

/*
 * request layer contorl.
 *  @core:
 *     point to core object.
 *  @success
 @     0 means get layer control fail,1 means get layer control success.
 */
vivSTATUS viv_request_control(
    viv_dc_core *core,
    gctBOOL *success);
#endif

/*
 * set dc interrupt enable/disable.
 *  @core:
 *     point to core object.
 *  @interrupt_enable
 @     vivFALSE means disable interrupt,vivTRUE means enable interrupt.
 */
gctVOID viv_interrupt_enable(
    viv_dc_core *core,
    gctBOOL *interrupt_enable);

#endif

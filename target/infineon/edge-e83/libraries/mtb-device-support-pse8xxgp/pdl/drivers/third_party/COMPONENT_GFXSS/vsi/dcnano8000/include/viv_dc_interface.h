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


#ifndef _VIV_DC_INTERFACE_H_
#define _VIV_DC_INTERFACE_H_

#include "viv_dc_type.h"
#include "viv_dc_options.h"

#define VIV_DC_INTERFACE    30000

typedef enum _viv_interface_command_type {
    vivIFACE_NONE = 0,
    vivIFACE_MEMORY_MAP = 1,
    vivIFACE_MEMORY_UNMAP,
    vivIFACE_FRAMEBUFFER,
    vivIFACE_DISPLAY,
    vivIFACE_LAYER,
    vivIFACE_BACKGROUND,
    vivIFACE_CURSOR,
    vivIFACE_QOS,
    vivIFACE_PANEL,
    vivIFACE_OUTPUT,
    vivIFACE_DITHER,
    vivIFACE_WB_DITHER,
    vivIFACE_GAMMA_ENABLE,
    vivIFACE_GAMMA,
    vivIFACE_SELECT_DC,
    vivIFACE_MULTI_MODE,
    vivIFACE_3D_LUT,
    vivIFACE_3D_LUT_ENLARGE,
    vivIFACE_CURSOR_INIT,
    vivIFACE_CURSOR_MOVE,/*20*/
    vivIFACE_CURSOR_SIZE,
    vivIFACE_COMMIT,
    vivIFACE_RESET,
    vivIFACE_REGISTER,
    vivIFACE_READ_REGISTER,
    vivIFACE_REGISTER_RESET,
    vivIFACE_DBI_RESET,
    vivIFACE_ALLOC_BUFFER,
    vivIFACE_FREE_BUFFER,
    vivIFACE_OVERLAY,/*30*/
    vivIFACE_DEST,
    vivIFACE_VIDEO_ROI,
    vivIFACE_OVERLAY_ROI,
    vivIFACE_ROI_ENABLE,
    vivIFACE_ROI_RESET,
    vivIFACE_VIDEO_CSC,
    vivIFACE_OVERLAY_CSC,
    vivIFACE_QUERY,
    vivIFACE_CRC,
    vivIFACE_READ_AXIFE_CONFIG,
    vivIFACE_READ_AXIFE_STATIS,
    vivIFACE_CONFIG_AXIFE,
    vivIFACE_CONFIG_AXIFE_CHNS,
    vivIFACE_CONFIG_AXIFE_REMAIN_CHNS,
    vivIFACE_ENABLE_AXIFE,
    vivIFACE_RESET_AXIFE,
    vivIFACE_READ_APB_CONFIG,
    vivIFACE_CONFIG_APB,
    vivIFACE_CONFIG_APB_PAGE_SEL,
    vivIFACE_INIT_LCD,
    vivIFACE_OS_REQUEST_CONTROL,
    vivIFACE_INTERRUPT_ENABLE,
}
viv_interface_command_type;

typedef enum _viv_dc_layer_cmd{
    vivLAYER_ENABLE,
    vivLAYER_CLEAR,
    vivLAYER_ROI_ENABLE,
    vivLAYER_SET_LUT,
    vivLAYER_SET_POSITION,
    vivLAYER_SET_RECT,
    vivLAYER_SET_BACKGROUND,
    vivLAYER_SET_DISPLAY,
    vivLAYER_CMD_BUFFER,
    vivLAYER_SET_COLORKEY,
    vivLAYER_ENABLE_DEGAMMA,
    vivLAYER_SET_DEGAMMA,
    vivLAYER_SET_ROTATION,
    vivLAYER_SET_SCALE,
    vivLAYER_SET_DECOMPRESS,
    vivLAYER_SET_CACHE_MODE,
    vivLAYER_SET_WATERMARK,
    vivLAYER_SET_ALPHA,
    vivLAYER_SET_POTERBUFF_BLEND_MODE,
    vivLAYER_SET_ZORDER,
    vivLAYER_SET_SECURITY,
    vivLAYER_SET_CSC_Y2R,
    vivLAYER_SET_CSC_R2R,
}
viv_dc_layer_cmd;

typedef enum _viv_dc_query_cmd {
    vivQUERY_CHIP_IDENTITY,
    vivQUERY_VBLANK_COUNT,
    vivQUERY_LAYER_STATUS,
}
viv_dc_query_cmd;

typedef enum _viv_dc_display_cmd{
    vivDISPLAY_SET_SIZE,
    vivDISPLAY_SET_CUSTOM_SIZE,
    vivDISPLAY_SET_OUTPUT,
    vivDISPLAY_SET_CSC,
    vivDISPLAY_SET_DEST,
    vivDISPLAY_RESET_DBI,
    vivDISPLAY_SET_DBI,
}
viv_dc_display_cmd;

/* background enum include pure color and color bar background */
typedef enum _viv_dc_background_cmd{
    vivBACKGROUND_SET_COLOR,
    vivBACKGROUND_SET_COLORBAR,
}
viv_dc_background_cmd;

typedef enum _viv_dc_cursor_cmd {
    vivCURSOR_SET,
    vivCURSOR_HOTSPOT,
    vivCURSOR_MOVE,
    vivCURSOR_SECURITY,
}
viv_dc_cursor_cmd;

typedef enum _viv_dc_crc_cmd {
    vivCRC_SET_RANGE,
    vivCRC_GET_VALUE,
}
viv_dc_crc_cmd;

typedef struct _viv_interface {
    gctUINT command;

    union _u {
#if vivENABLE_MMU
        struct _viv_interface_memory_map {
            gctUINT physical;
            gctUINT size;
            gctADDRESS dpu_addrress;
            viv_pool_type pool;
            gctBOOL    security;
        } memory_map;

        struct _viv_interface_memory_unmap {
            gctUINT dpu_addrress;
            gctUINT size;
        } memory_unmap;
#endif

        struct _viv_interface_display {
            viv_display display_id;
            viv_dc_display_cmd cmd;
            union _display_u {
                struct _viv_display_size {
                    viv_display_size_type type;
                    gctUINT hactive;
                    gctUINT hsync_start;
                    gctUINT hsync_end;
                    gctUINT htotal;
                    gctUINT vactive;
                    gctUINT vsync_start;
                    gctUINT vsync_end;
                    gctUINT vtotal;
                } size;
                struct _viv_display_output {
                    viv_output output;
                    gctBOOL enable;
                } output;
                struct _viv_display_output_dbi {
                    viv_dbi_type type;
                } output_dbi;
#if vivENABLE_DISPLAY_R2Y
                struct _viv_display_output_csc {
                    gctBOOL full_range;
                    viv_csc_mode mode;
                    gctINT coef[MAX_CSC_COEF_NUM];
                    gctUINT num;
                }output_csc;
#endif

#if vivENABLE_WRITEBACK
                struct _viv_dest {
                    gctBOOL enable;
                    viv_dc_buffer buffer;
                    viv_write_back_type type;
                }dest;
#endif
            } u;
        } display;

        struct _viv_interface_commit {
            gctUINT32 display_mask;
        } commit;

        struct _viv_interface_output {
            gctBOOL enable;
            gctUINT output_type;
            union _iu {
                struct _viv_interface_output_dbi {
                    gctBOOL reset;

                    gctUINT type;
                    gctUINT format;
                    gctBOOL polarity;
                    gctUINT actime;

                    gctINT reg_select;
                    gctUINT period;
                    gctUINT eor_assert;
                    gctUINT cs_assert;

                    gctINT command_type;
                    gctUINT command;
                } dbi;
                struct _viv_interface_output_dpi {
                    gctUINT format;
                } dpi;
                struct _viv_interface_output_dp {
                    gctUINT format;
                } dp;
            } iu;
        } output;

        struct _viv_interface_layer {
            gctUINT layer_id;
            viv_dc_layer_cmd cmd;
            union _layer_u {
                struct _viv_layer_buffer {
                    viv_dc_buffer buffer;
                } buffer;
                struct _viv_layer_clear {
                    viv_dc_color clear_color;
                    gctBOOL clear_color_enable;
                } clear;

#if vivENABLE_LAYER_ROI
                struct _viv_layer_roi_enable {
                    gctBOOL roi_enable;
                } roi_enable;
                struct _viv_layer_roi_rect {
                    viv_dc_rect roi_rect;
                }roi_rect;
#endif
                struct _viv_layer_set_position {
                    gctUINT x;
                    gctUINT y;
                } position;
                struct _viv_layer_colorkey {
                    viv_dc_color colorkey;
                    viv_dc_color colorkey_high;
                    gctBOOL transparency;
                } colorkey;

#if vivENABLE_LAYER_DEGAMMA
                struct _viv_layer_degamma {
                    gctBOOL     enable;
                    gctUINT     index;
                    gctUINT16   item[3];
                } degamma;
#endif

#if vivENABLE_LAYER_ROT
                struct _viv_layer_rotation {
                    viv_rotation_type rot;
                } rotation;
#endif

                struct _viv_layer_scale {
                    viv_dc_rect display_rect;
#if vivENABLE_LAYER_SCALE
                    viv_filter_tap_type filter;
                    gctUINT32 scale_factorx;
                    gctUINT32 scale_factory;
                    gctUINT horkernel[78];
                    gctUINT verkernel[78];
                    gctBOOL scale_enable;
#endif
                } scale;

#if vivENABLE_LAYER_DECOMPRESS
                struct _viv_layer_decompress {
                    viv_tilestatus_buffer tilestatus_buffer;
                    gctBOOL decompress_enable;
                    viv_cache_mode cache_mode;
                } decompress;
#endif
                struct _viv_layer_watermark {
                    gctUINT32 watermark_value;
                } watermark;
                struct _viv_layer_alpha {
                    viv_layer_alpha_mode alpha;
                } alpha;
                struct _viv_layer_poterduff_blend {
                    gctBOOL enable;
                    viv_porter_duff_mode mode;
                } poterduff_blend;
                struct _viv_layer_zorder {
                    gctUINT8 zorder;
                } zorder;
                struct _viv_layer_display {
                    viv_display display_id;
                } display;
                struct _viv_layer_enable {
                    gctBOOL layer_enable;
                } layer_enable;
#if vivENABLE_SEC
                struct _viv_layer_security {
                    gctBOOL enable;
                } security;
#endif
                struct _viv_layer_y2r {
                    gctBOOL yuvClamp;
                    viv_csc_mode mode;
                    gctINT coef[MAX_CSC_COEF_NUM];
                    gctUINT num;
                } y2r;
                struct _viv_layer_r2r {
                    gctBOOL enable;
                    viv_csc_mode mode;
                    gctINT coef[MAX_CSC_COEF_NUM];
                    gctUINT num;
                } r2r;
            } u;
        } layer;

   /* put pure color and color bar background into an union */
        struct _viv_interface_background {
            viv_display display_id;
            viv_dc_background_cmd cmd;
            union _background_u {
                struct _viv_background_purecolor {
                    viv_dc_color color;
                } purecolor;
#if vivENABLE_DISPLAY_CLRBAR
                struct _viv_background_colorbar {
                    gctBOOL enable;
                    gctUINT index;
                    viv_dc_rect range;
                    viv_dc_color color;
                } colorbar;
#endif
            } iu;
        } background;

        struct _viv_interface_cursor {
            viv_display display_id;
            viv_dc_cursor_cmd cmd;
            union _cursor_u {
                struct _viv_cursor_hotspot {
                    gctUINT32 hsx;
                    gctUINT32 hsy;
                } hotspot;
                struct _viv_cursor_move {
                    gctUINT32 x;
                    gctUINT32 y;
                } move;
                struct _viv_cursor_set {
                    viv_dc_buffer buffer;
                    viv_cursor cursor;
                    gctBOOL enable;
                } set;
#if vivENABLE_SEC
                struct _viv_cusor_security {
                    gctBOOL enable;
                } security;
#endif
            } iu;
        }cursor;

        struct _viv_interface_qos {
            gctUINT32 low;
            gctUINT32 high;
        } qos;

        struct _viv_interface_dither {
            viv_display display_id;
            gctBOOL enable;
            gctUINT table_low;
            gctUINT table_high;
        } dither;

#if vivENABLE_WRITEBACK
        struct _viv_interface_wb_dither {
            viv_display display_id;
            gctBOOL enable;
            gctUINT table_low;
            gctUINT table_high;
        } wb_dither;
#endif

        struct _viv_interface_gamma {
            gctBOOL     enable;
            gctUINT     index;
            gctUINT16   item[3];
            viv_display disp_id;
        } gamma;

        struct _viv_interface_registers {
            gctUINT offset;
            gctUINT write;
            gctUINT read;
        } registers;

#if ALLOC_RESERVED_MEM_IN_KERNEL
        struct _viv_interface_alloc_resmem {
            gctUINT32 size;
            gctADDRESS physicalAddr;
            gctUINT32 handle;

#if USE_ARCH64
            gctUINT64 logical;
#else
            gctUINT32 logical;
#endif

        } alloc_resmem;
#endif

        struct _viv_interface_alloc {
            gctSIZE_T size;
            gctADDRESS hardwareAddress;
#if USE_ARCH64
            gctUINT64 logical;
            gctUINT64 handle;
#else
            gctUINT32 logical;
            gctUINT32 handle;
#endif
            gctBOOL   security;
            viv_pool_type pool;
        } alloc;

        struct _viv_interface_free {
#if USE_ARCH64
            gctUINT64 handle;
#else
            gctUINT32 handle;
#endif
        } free;

#if vivENABLE_DISPLAY_3DLUT
        struct _viv_interface_3d_lut {
            viv_display display_id;
            gctBOOL enable;
            gctUINT32 index;
            gctUINT32 lut;
            viv_lut_enlarge enlarge;
        } threed_lut;
#endif

#if vivENABLE_DISPLAY_CRC
        struct _viv_interface_crc {
            gctUINT32 index;
            viv_dc_crc_cmd cmd;
            union _crc_u {
                struct _viv_crc_range {
                    gctBOOL enable;
                    viv_dc_rect range;
                } crc_range;
                struct _viv_crc_value {
                    gctUINT32 value;
                } crc_value;
            } u;
        } crc;
#endif

        struct _viv_interface_query {
            viv_dc_query_cmd cmd;
            union _query_u {
                viv_interface_query_chip_identity queryChipIdentity;
                struct _viv_vblank_count {
                    viv_display disp_id;
                    gctUINT32      count;
                } vblank;

#if vivENABLE_DUALOS
                struct _viv_query_layer_status{
                    viv_layer_status queryLayerStatus;
                    gctUINT layer_id;
                }viv_query_layer_status;
#endif
            }u;
        } query;

#if vivENABLE_DUALOS
        struct _viv_interface_os_request_control {
            gctBOOL result;
        } request;
#endif

        struct _viv_interface_interrupt {
            gctBOOL interrupt_enable;
        } interrupt;

    }u;
}
viv_interface;

#endif

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
#include "dc_layer_feature.h"
#include "viv_dc_reg.h"

static gctUINT frameBufferConfig;
static gctUINT overlayConfig;
static gctUINT overlayConfig1;
static gctUINT cursorConfig;
static gctUINT tileInCfg;
static gctUINT overlayTileInCfg;
static gctUINT panelFunctionConfig;

static gctUINT zorder[DC_LAYER_NUM];
extern gctBOOL chip_feature[vivFEATURE_COUNT];

vivSTATUS _viv_format_to_hw_format(
    viv_input_format_type format,
    gctUINT8 *hw_format,
    gctUINT8* swizzle,
    gctUINT8* uv_swizzle
    )
{
    if (!swizzle || !hw_format || !uv_swizzle)
        return vivSTATUS_INVALID_ARGUMENTS;

    *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ARGB;
    *uv_swizzle = 0;

    switch(format)
    {
        case vivARGB4444:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A4R4G4B4;
            break;
        case vivABGR4444:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A4R4G4B4;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ABGR;
            break;
        case vivRGBA4444:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A4R4G4B4;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_RGBA;
            break;
        case vivBGRA4444:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A4R4G4B4;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_BGRA;
            break;
        case vivARGB1555:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A1R5G5B5;
            break;
        case vivABGR1555:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A1R5G5B5;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ABGR;
            break;
        case vivRGBA1555:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A1R5G5B5;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_RGBA;
            break;
        case vivBGRA1555:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A1R5G5B5;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_BGRA;
            break;
        case vivRGB565:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_R5G6B5;
            break;
        case vivBGR565:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_R5G6B5;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ABGR;
            break;
        case vivARGB8888:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A8R8G8B8;
            break;
        case vivABGR8888:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A8R8G8B8;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_ABGR;
            break;
        case vivRGBA8888:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A8R8G8B8;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_RGBA;
            break;
        case vivBGRA8888:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A8R8G8B8;
            *swizzle = GCREG_FRAME_BUFFER_CONFIG_SWIZZLE_BGRA;
            break;
        case vivYUY2:
            *hw_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_YUY2;
            break;
        case vivNV12:
            *hw_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NV12;
            break;
        case vivCURSOR_ARGB:
            *hw_format = GCREG_CURSOR_CONFIG_FORMAT_A8R8G8B8;
            break;
        default:
            *hw_format = GCREG_FRAME_BUFFER_CONFIG_FORMAT_A8R8G8B8;
            break;
    }

    return vivSTATUS_OK;
}

vivSTATUS _viv_get_tile_format(
    viv_tiling_type tiling,
    viv_input_format_type format,
    gctUINT8 *tile_format
    )
{
    if (!tile_format)
        return vivSTATUS_INVALID_ARGUMENTS;

    switch(tiling)
    {
        case vivLINEAR:
            *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NONE;
            break;
        case vivTILED4X4:
            switch(format)
            {
                case vivARGB8888:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_ARGB8888;
                    break;
                case vivABGR8888:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_ARGB8888;
                    break;
                case vivRGBA8888:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_ARGB8888;
                    break;
                case vivBGRA8888:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_ARGB8888;
                    break;
                case vivYUY2:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_YUY2;
                    break;
                case vivNV12:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NV12;
                    break;
                default:
                    *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NONE;
                    break;
            }
            break;
        default:
            *tile_format = GCREG_DC_TILE_IN_CFG_TILE_FORMAT_NONE;
            break;
    }

    return vivSTATUS_OK;
}

vivSTATUS _viv_get_plane_stride(
    viv_tiling_type tiling,
    viv_input_format_type format,
    gctUINT32 *stride,
    gctUINT32 *tile_stride
    )
{
    if ((!stride) || (!tile_stride))
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    switch(tiling)
    {
        case vivLINEAR:
            tile_stride[0] = stride[0];
            tile_stride[1] = stride[1];
            break;
        case vivTILED4X4:
            switch(format)
            {
                case vivARGB8888:
                case vivABGR8888:
                case vivRGBA8888:
                case vivBGRA8888:
                case vivYUY2:
                    tile_stride[0] = stride[0] * 4;
                    break;
                case vivNV12:
                    tile_stride[0] = stride[0] * 8;
                    tile_stride[1] = stride[1] * 4;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_init_reg_config(
    gctVOID
    )
{
    gctUINT i = 0;
    for(i = 0;i < DC_LAYER_NUM;i++)
        zorder[i] = 0;
    frameBufferConfig = GCREG_FRAME_BUFFER_CONFIG_ResetValue;
    overlayConfig = GCREG_OVERLAY_CONFIG_ResetValue;
    overlayConfig1 = GCREG_OVERLAY_CONFIG1_ResetValue;
    cursorConfig = GCREG_CURSOR_CONFIG_ResetValue;
    tileInCfg = GCREG_DC_TILE_IN_CFG_ResetValue;
    overlayTileInCfg = GCREG_DC_OVERLAY_TILE_IN_CFG_ResetValue;
    panelFunctionConfig = GCREG_PANEL_FUNCTION_ResetValue;

    return vivSTATUS_OK;
}

gctUINT viv_get_reg_config(
    gctUINT addr
    )
{
    gctUINT config = 0;

    switch(addr)
    {
        case GCREG_FRAME_BUFFER_CONFIG_Address:
            config = frameBufferConfig;
            break;
        case GCREG_OVERLAY_CONFIG_Address:
            config = overlayConfig;
            break;
        case GCREG_OVERLAY_CONFIG1_Address:
            config = overlayConfig1;
            break;
        case GCREG_CURSOR_CONFIG_Address:
            config = cursorConfig;
            break;
        case GCREG_DC_TILE_IN_CFG_Address:
            config = tileInCfg;
            break;
        case GCREG_DC_OVERLAY_TILE_IN_CFG_Address:
            config = overlayTileInCfg;
            break;
        case GCREG_PANEL_FUNCTION_Address:
            config = panelFunctionConfig;
            break;
        default:
            config = 0xFFFFFFFF;
            break;
    }

    return config;
}

vivSTATUS viv_set_reg_config(
    gctUINT addr,
    gctUINT config
    )
{
    vivSTATUS stat = vivSTATUS_OK;

    switch(addr)
    {
        case GCREG_FRAME_BUFFER_CONFIG_Address:
            frameBufferConfig = config;
            break;
        case GCREG_OVERLAY_CONFIG_Address:
            overlayConfig = config;
            break;
        case GCREG_OVERLAY_CONFIG1_Address:
            overlayConfig1 = config;
            break;
        case GCREG_CURSOR_CONFIG_Address:
            cursorConfig = config;
            break;
        case GCREG_DC_TILE_IN_CFG_Address:
            tileInCfg = config;
            break;
        case GCREG_DC_OVERLAY_TILE_IN_CFG_Address:
            overlayTileInCfg = config;
            break;
        case GCREG_PANEL_FUNCTION_Address:
            panelFunctionConfig = config;
            break;
        default:
            stat = vivSTATUS_FAILED;
            break;
    }

    return stat;
}

#if vivENABLE_DISPLAY_CRC
vivSTATUS viv_hw_reset_sw_stat(
    gctVOID
    )
{
    return vivSTATUS_OK;
}
#endif

vivSTATUS dc_query_hardware_chip_identity(
    viv_dc_hardware *hardware,
    viv_interface_query_chip_identity_ptr Identity
    )
{
    vivSTATUS ret = vivSTATUS_OK;

    ret = viv_hw_version_get(
        hardware,
        (gctUINT *)&Identity->chipModel,
        &Identity->chipRevision,
        &Identity->chipPatchRevision,
        &Identity->chipInfo,
        &Identity->productID,
        &Identity->ecoID,
        &Identity->customerID,
        &Identity->productDate,
        &Identity->productTime);

    return ret;
}

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
    )
{
    viv_dc_os *os = hardware->os;

    if (!hardware->info_got)
    {
        hardware->chip_id = viv_os_read_reg(os, GCREG_DC_CHIP_ID_Address);
        hardware->chip_revision = viv_os_read_reg(os, GCREG_DC_CHIP_REV_Address);
        hardware->chip_patch_revision = viv_os_read_reg(os, GCREG_DC_CHIP_PATCH_REV_Address);
        hardware->chip_info = viv_os_read_reg(os, GCREG_DC_CHIP_INFO_Address);
        hardware->product_id = viv_os_read_reg(os, GCREG_DC_PRODUCT_ID_Address);
        hardware->eco_id = viv_os_read_reg(os, GCREG_DC_ECO_ID_Address);
        hardware->customer_id = viv_os_read_reg(os, GCREG_DC_CUSTOMER_ID_Address);
        hardware->product_date = viv_os_read_reg(os, GCREG_DC_CHIP_DATE_Address);
        hardware->product_time = viv_os_read_reg(os, GCREG_DC_CHIP_TIME_Address);

        hardware->info_got = vivTRUE;
    }

    if (chip_id != vivNULL)
        *chip_id = hardware->chip_id;

    if (chip_revision != vivNULL)
        *chip_revision = hardware->chip_revision;

    if (chip_patch_revision != vivNULL)
        *chip_patch_revision = hardware->chip_patch_revision;

    if (chip_info != vivNULL)
        *chip_info = hardware->chip_info;

    if (product_id != vivNULL)
        *product_id = hardware->product_id;

    if (eco_id != vivNULL)
        *eco_id = hardware->eco_id;

    if (customer_id != vivNULL)
        *customer_id = hardware->customer_id;

    if (product_date != vivNULL)
        *product_date = hardware->product_date;

    if (product_time != vivNULL)
        *product_time = hardware->product_time;

    return vivSTATUS_OK;
}

#if vivENABLE_LAYER_DECOMPRESS
vivSTATUS viv_hw_dec400_init(
    viv_dc_hardware* hardware
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_dec400_stream_disable(
    viv_dc_hardware* hardware,
    gctUINT32 stream_index
    )
{
    return vivSTATUS_OK;
}

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
    )
{
    return vivSTATUS_OK;
}
#endif

/* Begin to copy a new set of registers at the next VBLANK */
vivSTATUS viv_hw_shadow_register_pending_enable(
    viv_dc_hardware *hardware,
    gctBOOL enable,
    gctBOOL *layer_dirty,
    gctBOOL *display_dirty
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;

    if (enable)
    {
        config = gcmSETFIELDVALUE(0, GCREG_PANEL_CONTROL, VALID, WORKING);
    }
    else
    {
        config = gcmSETFIELDVALUE(0, GCREG_PANEL_CONTROL, VALID, PENDING);
    }

    viv_os_write_reg(os, GCREG_PANEL_CONTROL_Address, config);

    return vivSTATUS_OK;
}

#if vivENABLE_DISPLAY_R2Y
vivSTATUS viv_hw_set_output_csc(
    viv_dc_hardware *hardware,
    viv_display id,
    gctINT *coef
    )
{
    return vivSTATUS_OK;
}
#endif

/* Dither Operation */
vivSTATUS viv_hw_dither_enable(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT low,
    gctUINT high
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;

    config = viv_get_reg_config(GCREG_PANEL_FUNCTION_Address);
    config = gcmSETFIELD(config, GCREG_PANEL_FUNCTION, DITHER, enable);
    viv_os_write_reg(os, GCREG_PANEL_FUNCTION_Address, config);
    viv_set_reg_config(GCREG_PANEL_FUNCTION_Address, config);

    if (enable)
    {
        viv_os_write_reg(os, GCREG_DISPLAY_DITHER_TABLE_LOW_Address, low);
        viv_os_write_reg(os, GCREG_DISPLAY_DITHER_TABLE_HIGH_Address, high);
    }
    else
    {
        viv_os_write_reg(os, GCREG_DISPLAY_DITHER_TABLE_LOW_Address, 0);
        viv_os_write_reg(os, GCREG_DISPLAY_DITHER_TABLE_HIGH_Address, 0);
    }

    return vivSTATUS_OK;
}

#if vivENABLE_WRITEBACK
vivSTATUS viv_hw_set_write_back_dither(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT low,
    gctUINT high
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_set_dest_address(
    viv_dc_hardware *hardware,
    gctBOOL enable,
    viv_display id,
    viv_dc_buffer *buffer_ptr,
    viv_write_back_type type
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT32 address = (gctUINT32)(buffer_ptr->phyAddress[0]);

    if (id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (type != vivWB_DEFAULT)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (enable)
    {
        viv_os_write_reg(os, GCREG_PANEL_DEST_ADDRESS_Address, address);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_set_dest_stride(
    viv_dc_hardware *hardware,
    viv_display id,
    gctUINT stride
    )
{
    viv_dc_os *os = hardware->os;

    if (id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    viv_os_write_reg(os, GCREG_DEST_STRIDE_Address, stride);

    return vivSTATUS_OK;
}
#endif

/* Gamma Correctrion Operation */
vivSTATUS viv_hw_gamma_set_config(
    viv_dc_hardware *hardware,
    gctUINT disp_id,
    gctUINT16 gamma[][3]
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT i, config;
    gctUINT table_size = 0;

    viv_os_write_reg(os, GCREG_GAMMA_INDEX_Address, 0);

    table_size = (chip_feature[vivFEATURE_NEW_GAMMA] == 1) ? 300 : 256;
    for (i = 0; i < table_size; i++)
    {
        config = gcmSETFIELD(0, GCREG_GAMMA_DATA, RED, gamma[i][0])
               | gcmSETFIELD(0, GCREG_GAMMA_DATA, GREEN, gamma[i][1])
               | gcmSETFIELD(0, GCREG_GAMMA_DATA, BLUE, gamma[i][2]);

        viv_os_write_reg(os, GCREG_GAMMA_DATA_Address, config);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_set_background(
    viv_dc_hardware *hardware,
    viv_display display_id,
    viv_dc_color bg_color
    )
{
    viv_dc_os *os = hardware->os;

    viv_os_write_reg(
        os,
        GCREG_FRAME_BUFFER_BACKGROUND_Address,
        gcmSETFIELD(0, GCREG_FRAME_BUFFER_BACKGROUND, ALPHA, bg_color.a) |
        gcmSETFIELD(0, GCREG_FRAME_BUFFER_BACKGROUND, RED, bg_color.r) |
        gcmSETFIELD(0, GCREG_FRAME_BUFFER_BACKGROUND, GREEN, bg_color.g) |
        gcmSETFIELD(0, GCREG_FRAME_BUFFER_BACKGROUND, BLUE, bg_color.b)
        );

    return vivSTATUS_OK;
}

#if vivENABLE_DISPLAY_CLRBAR
vivSTATUS viv_hw_set_color_bar(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT index,
    viv_dc_rect range,
    viv_dc_color color
    )
{
     return vivSTATUS_OK;
}
#endif

#if vivENABLE_DISPLAY_CRC
vivSTATUS viv_hw_set_crc_range(
    viv_dc_hardware *hardware,
    gctUINT i,
    gctBOOL enable,
    viv_dc_rect range
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_get_crc_value(
    viv_dc_hardware *hardware,
    gctUINT index,
    gctUINT32 *value
    )
{
    return vivSTATUS_OK;
}
#endif

vivSTATUS viv_hw_set_qos(
    viv_dc_hardware* hardware,
    gctUINT32 low,
    gctUINT32 high
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_cursor_hotspot(
    viv_dc_hardware* hardware,
    viv_display display_id,
    viv_cursor* cursor_ptr
    )
{
    viv_dc_os* os = hardware->os;
    gctUINT config = 0;

    if (display_id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    config = viv_os_read_reg(os, GCREG_CURSOR_CONFIG_Address);

    config = gcmSETFIELD(config, GCREG_CURSOR_CONFIG, HOT_SPOT_X, cursor_ptr->hsx)
           | gcmSETFIELD(config, GCREG_CURSOR_CONFIG, HOT_SPOT_Y, cursor_ptr->hsy);

    viv_os_write_reg(os, GCREG_CURSOR_CONFIG_Address, config);

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_cursor_set(
    viv_dc_hardware* hardware,
    viv_display display_id,
    gctBOOL enable,
    viv_dc_buffer* buffer_ptr,
    viv_cursor* cursor_ptr
    )
{
    viv_dc_os* os = hardware->os;
    gctUINT config_field = 0;
    gctUINT location_field = 0;

    if (display_id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (enable)
    {
        config_field = viv_os_read_reg(os, GCREG_CURSOR_CONFIG_Address);

        config_field = gcmSETFIELD(config_field, GCREG_CURSOR_CONFIG, FORMAT, (cursor_ptr->format >> 8) & 0x3)
                    |gcmSETFIELD(config_field, GCREG_CURSOR_CONFIG, DISPLAY, display_id);

        viv_os_write_reg(os, GCREG_CURSOR_CONFIG_Address, config_field);

        location_field = gcmSETFIELD(0, GCREG_CURSOR_LOCATION, X, (cursor_ptr->x) & 0x1FFF)
                     | gcmSETFIELD(0, GCREG_CURSOR_LOCATION, Y, (cursor_ptr->y) & 0x0FFF);

        viv_os_write_reg(os, GCREG_CURSOR_LOCATION_Address, location_field);

        viv_os_write_reg(os, GCREG_CURSOR_ADDRESS_Address, buffer_ptr->phyAddress[0] & 0xFFFFFFFF);

        viv_os_write_reg(os, GCREG_CURSOR_BACKGROUND_Address, (cursor_ptr->bg_color) & 0xFFFFFF);

        viv_os_write_reg(os, GCREG_CURSOR_FOREGROUND_Address, (cursor_ptr->fg_color) & 0xFFFFFF);
    }
    else
    {
        viv_os_write_reg(os, GCREG_CURSOR_CONFIG_Address, 0);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_layer_clear(
    viv_dc_hardware *hardware,
    gctUINT layer_id,
    viv_dc_layer layer
    )
{
    viv_dc_os *os = hardware->os;

    if (layer_id == 0)
    {
        if (layer.clear_color_enable)
        {
            viv_os_write_reg(
                os,
                GCREG_FRAME_BUFFER_CLEAR_VALUE_Address,
                gcmSETFIELD(0, GCREG_FRAME_BUFFER_CLEAR_VALUE, ALPHA, layer.clear_color.a) |
                gcmSETFIELD(0, GCREG_FRAME_BUFFER_CLEAR_VALUE, RED, layer.clear_color.r) |
                gcmSETFIELD(0, GCREG_FRAME_BUFFER_CLEAR_VALUE, GREEN, layer.clear_color.g) |
                gcmSETFIELD(0, GCREG_FRAME_BUFFER_CLEAR_VALUE, BLUE, layer.clear_color.b)
                );
        }
    }
    else if (layer_id == 1)
    {
        if (layer.clear_color_enable)
        {
            viv_os_write_reg(
                os,
                GCREG_OVERLAY_CLEAR_VALUE_Address,
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE, ALPHA, layer.clear_color.a) |
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE, RED, layer.clear_color.r) |
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE, GREEN, layer.clear_color.g) |
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE, BLUE, layer.clear_color.b)
                );
        }
    }
    else if (layer_id == 2)
    {
        if (layer.clear_color_enable)
        {
            viv_os_write_reg(
                os,
                GCREG_OVERLAY_CLEAR_VALUE1_Address,
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE1, ALPHA, layer.clear_color.a) |
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE1, RED, layer.clear_color.r) |
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE1, GREEN, layer.clear_color.g) |
                gcmSETFIELD(0, GCREG_OVERLAY_CLEAR_VALUE1, BLUE, layer.clear_color.b)
                );
        }
    }

    return vivSTATUS_OK;
}

#if vivENABLE_LAYER_ROI
vivSTATUS viv_hw_layer_roi(
    viv_dc_hardware *hardware,
    gctUINT layer_id,
    viv_dc_layer layer
    )
{
    return vivSTATUS_OK;
}
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
    )
{
    return vivSTATUS_OK;
}
#endif

vivSTATUS viv_hw_layer_set_watermark(
    viv_dc_hardware *hardware,
    gctUINT id,
    gctUINT32 value
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_layer_set_position(
    viv_dc_hardware *hardware,
    gctUINT layer_id,
    viv_dc_layer layer,
    viv_display_size_type size
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT max_width = 0, max_height = 0;
    gctUINT config_tl = 0, config_size = 0;

    switch (size)
    {
        case vivDISPLAY_320_480_60:
            max_width = 320;
            max_height = 480;
            break;
        case vivDISPLAY_480_800_60:
            max_width = 480;
            max_height = 800;
            break;
        case vivDISPLAY_480_864_60:
            max_width = 480;
            max_height = 864;
            break;
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
        case vivDISPLAY_1024_768_60:
            max_width = 1024;
            max_height = 768;
            break;
        case vivDISPLAY_1920_1080_60:
            max_width = 1920;
            max_height = 1080;
            break;

        default:
            //IFXEXP-180
		max_height = 1080;
		max_width = 1920;
            //viv_os_print("current resolution is not supported!\n");
            //return vivSTATUS_NOT_SUPPORT;
            break;
    }

    if (((layer.pos_y + layer.height) > max_height) || ((layer.pos_x + layer.width) > max_width))
    {
        viv_os_print("display position execcds maximum!\n");
        return vivSTATUS_FAILED;
    }

    if (layer_id == 0)
    {
        config_tl = gcmSETFIELD(0, GCREG_VIDEO_TL, X, layer.pos_x)
                    |gcmSETFIELD(0, GCREG_VIDEO_TL, Y, layer.pos_y);
        viv_os_write_reg(os, GCREG_VIDEO_TL_Address, config_tl);

        config_size = gcmSETFIELD(0, GCREG_FRAME_BUFFER_SIZE, WIDTH, layer.width)
                       |gcmSETFIELD(0, GCREG_FRAME_BUFFER_SIZE, HEIGHT, layer.height);
        viv_os_write_reg(os, GCREG_FRAME_BUFFER_SIZE_Address, config_size);
    }
    else if (layer_id == 1)
    {
        config_tl = gcmSETFIELD(0, GCREG_OVERLAY_TL, X, layer.pos_x)
                    |gcmSETFIELD(0, GCREG_OVERLAY_TL, Y, layer.pos_y);
        viv_os_write_reg(os, GCREG_OVERLAY_TL_Address, config_tl);

        config_size = gcmSETFIELD(0, GCREG_OVERLAY_SIZE, WIDTH, layer.width)
                      |gcmSETFIELD(0, GCREG_OVERLAY_SIZE, HEIGHT, layer.height);
        viv_os_write_reg(os, GCREG_OVERLAY_SIZE_Address, config_size);
    }
    else if (layer_id == 2)
    {
        config_tl = gcmSETFIELD(0, GCREG_OVERLAY_TL1, X, layer.pos_x)
                    |gcmSETFIELD(0, GCREG_OVERLAY_TL1, Y, layer.pos_y);
        viv_os_write_reg(os, GCREG_OVERLAY_TL1_Address, config_tl);

        config_size = gcmSETFIELD(0, GCREG_OVERLAY_SIZE1, WIDTH, layer.width)
                      |gcmSETFIELD(0, GCREG_OVERLAY_SIZE1, HEIGHT, layer.height);
        viv_os_write_reg(os, GCREG_OVERLAY_SIZE1_Address, config_size);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_layer_colorkey_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT32 colorkey = 0, colorkey_high = 0;

    colorkey = (layer.colorkey.a << 24) | (layer.colorkey.r << 16) | (layer.colorkey.g << 8) | (layer.colorkey.b << 0);
    colorkey_high = (layer.colorkey_high.a << 24) | (layer.colorkey_high.r << 16) | (layer.colorkey_high.g << 8) | \
        (layer.colorkey_high.b << 0);

    if (id == 0)
    {
        viv_os_write_reg(os, GCREG_FRAME_BUFFER_COLOR_KEY_Address, colorkey);
        viv_os_write_reg(os, GCREG_FRAME_BUFFER_COLOR_KEY_HIGH_Address, colorkey_high);
    }
    else if (id == 1)
    {
        viv_os_write_reg(os, GCREG_OVERLAY_COLOR_KEY_Address, colorkey);
        viv_os_write_reg(os, GCREG_OVERLAY_COLOR_KEY_HIGH_Address, colorkey_high);
    }
    else
    {
        viv_os_write_reg(os, GCREG_OVERLAY_COLOR_KEY1_Address, colorkey);
        viv_os_write_reg(os, GCREG_OVERLAY_COLOR_KEY_HIGH1_Address, colorkey_high);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_layer_y2r_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;

    if (id == 0)
    {
        config = viv_get_reg_config(GCREG_DC_TILE_IN_CFG_Address);
        config = gcmSETFIELDVALUE(config, GCREG_DC_TILE_IN_CFG, YUV_STANDARD, BT601);

        viv_os_write_reg(os, GCREG_DC_TILE_IN_CFG_Address, config);
        viv_set_reg_config(GCREG_DC_TILE_IN_CFG_Address, config);
    }
    else if (id == 1)
    {
        config = viv_get_reg_config(GCREG_DC_OVERLAY_TILE_IN_CFG_Address);
        config = gcmSETFIELDVALUE(config, GCREG_DC_OVERLAY_TILE_IN_CFG, YUV_STANDARD, BT601);

        viv_os_write_reg(os, GCREG_DC_OVERLAY_TILE_IN_CFG_Address, config);
        viv_set_reg_config(GCREG_DC_OVERLAY_TILE_IN_CFG_Address, config);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_layer_r2r_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_set_alpha(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_layer_alpha_mode alpha
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;

    if (id == 1)
    {
        config = gcmSETFIELD(0, GCREG_OVERLAY_GLOBAL_ALPHA, SRC_ALPHA, (gctUINT8)(alpha.srcGlobalAlphaValue >> 24))
                   | gcmSETFIELD(0, GCREG_OVERLAY_GLOBAL_ALPHA, DST_ALPHA, (gctUINT8)(alpha.dstGlobalAlphaValue >> 24));

        viv_os_write_reg(os, GCREG_OVERLAY_GLOBAL_ALPHA_Address, config);
    }
    else if (id == 2)
    {
        config = gcmSETFIELD(0, GCREG_OVERLAY_GLOBAL_ALPHA1, SRC_ALPHA, (gctUINT8)(alpha.srcGlobalAlphaValue >> 24))
                   | gcmSETFIELD(0, GCREG_OVERLAY_GLOBAL_ALPHA1, DST_ALPHA, (gctUINT8)(alpha.dstGlobalAlphaValue >> 24));

        viv_os_write_reg(os, GCREG_OVERLAY_GLOBAL_ALPHA1_Address, config);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_set_blend_mode(
    viv_dc_hardware *hardware,
    gctUINT id,
    gctBOOL enable,
    viv_porter_duff_mode mode,
    viv_layer_alpha_mode alpha_mode
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT8 src_blend_mode = vivBLENDING_ZERO;
    gctUINT8 dst_blend_mode = vivBLENDING_ZERO;

    switch (mode)
    {
        case vivPD_CLEAR:
            src_blend_mode = vivBLENDING_ZERO;
            dst_blend_mode = vivBLENDING_ZERO;
            break;

        case vivPD_SRC:
            src_blend_mode = vivBLENDING_ONE;
            dst_blend_mode = vivBLENDING_ZERO;
            break;

        case vivPD_DST:
            src_blend_mode = vivBLENDING_ZERO;
            dst_blend_mode = vivBLENDING_ONE;
            break;

        case vivPD_SRC_OVER:
            src_blend_mode = vivBLENDING_ONE;
            dst_blend_mode = vivBLENDING_INVERSED;
            break;

        case vivPD_DST_OVER:
            src_blend_mode = vivBLENDING_INVERSED;
            dst_blend_mode = vivBLENDING_ONE;
            break;

        case vivPD_SRC_IN:
            src_blend_mode = vivBLENDING_NORMAL;
            dst_blend_mode = vivBLENDING_ZERO;
            break;

        case vivPD_DST_IN:
            src_blend_mode = vivBLENDING_ZERO;
            dst_blend_mode = vivBLENDING_NORMAL;
            break;

        case vivPD_SRC_OUT:
            src_blend_mode = vivBLENDING_INVERSED;
            dst_blend_mode = vivBLENDING_ZERO;
            break;

        case vivPD_DST_OUT:
            src_blend_mode = vivBLENDING_ZERO;
            dst_blend_mode = vivBLENDING_INVERSED;
            break;

        case vivPD_SRC_ATOP:
            src_blend_mode = vivBLENDING_NORMAL;
            dst_blend_mode = vivBLENDING_INVERSED;
            break;

        case vivPD_DST_ATOP:
            src_blend_mode = vivBLENDING_INVERSED;
            dst_blend_mode = vivBLENDING_NORMAL;
            break;

        case vivPD_XOR:
            src_blend_mode = vivBLENDING_INVERSED;
            dst_blend_mode = vivBLENDING_INVERSED;
            break;

        default:
            viv_os_print("current mode is not supported\n");
            return vivSTATUS_NOT_SUPPORT;
    }

    if (enable)
    {
        if (id == 1)
        {
            viv_os_write_reg(os, GCREG_OVERLAY_ALPHA_BLEND_CONFIG_Address,
                gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, SRC_BLENDING_MODE, src_blend_mode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, SRC_ALPHA_FACTOR, GCREG_OVERLAY_ALPHA_BLEND_CONFIG_SRC_ALPHA_FACTOR_DISABLED)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, SRC_ALPHA_MODE, alpha_mode.srcAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, SRC_GLOBAL_ALPHA_MODE, alpha_mode.srcGlobalAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, DST_BLENDING_MODE, dst_blend_mode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, DST_ALPHA_FACTOR, GCREG_OVERLAY_ALPHA_BLEND_CONFIG_DST_ALPHA_FACTOR_DISABLED)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, DST_ALPHA_MODE, alpha_mode.dstAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, DST_GLOBAL_ALPHA_MODE, alpha_mode.dstGlobalAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, ALPHA_BLEND, GCREG_OVERLAY_ALPHA_BLEND_CONFIG_ALPHA_BLEND_ENABLED)
              );
        }
        else if (id == 2)
        {
            viv_os_write_reg(os, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_Address,
                gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, SRC_BLENDING_MODE, src_blend_mode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, SRC_ALPHA_FACTOR, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_SRC_ALPHA_FACTOR_DISABLED)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, SRC_ALPHA_MODE, alpha_mode.srcAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, SRC_GLOBAL_ALPHA_MODE, alpha_mode.srcGlobalAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, DST_BLENDING_MODE, dst_blend_mode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, DST_ALPHA_FACTOR, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_DST_ALPHA_FACTOR_DISABLED)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, DST_ALPHA_MODE, alpha_mode.dstAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, DST_GLOBAL_ALPHA_MODE, alpha_mode.dstGlobalAlphaMode)
              | gcmSETFIELD(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, ALPHA_BLEND, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_ALPHA_BLEND_ENABLED)
            );
        }
    }
    else
    {
        if (id == 1)
        {
            viv_os_write_reg(os, GCREG_OVERLAY_ALPHA_BLEND_CONFIG_Address,
                gcmSETFIELDVALUE(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG, ALPHA_BLEND, DISABLED));
        }
        else if (id == 2)
        {
            viv_os_write_reg(os, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1_Address,
                gcmSETFIELDVALUE(0, GCREG_OVERLAY_ALPHA_BLEND_CONFIG1, ALPHA_BLEND, DISABLED));
        }
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_layer_set_zorder(
    viv_dc_hardware* hardware
    )
{
    vivSTATUS stat = vivSTATUS_OK;
    gctUINT zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1;

    if((zorder[0] == zorder[1]) && (zorder[1] == zorder[2]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1;

    else if((zorder[0] == zorder[1]) && (zorder[1] > zorder[2]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY1_VIDEO_OVERLAY0;

    else if((zorder[0] == zorder[1]) && (zorder[1] < zorder[2]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1;

    else if((zorder[0] == zorder[2]) && (zorder[2] > zorder[1]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY0_VIDEO_OVERLAY1;

    else if((zorder[0] == zorder[2]) && (zorder[2] < zorder[1]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY1_OVERLAY0;

    else if((zorder[1] == zorder[2]) && (zorder[2] > zorder[0]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1;

    else if((zorder[1] == zorder[2]) && (zorder[2] < zorder[0]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY0_OVERLAY1_VIDEO;

    else if((zorder[0] < zorder[1]) && (zorder[1] < zorder[2]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1;

    else if((zorder[0] < zorder[2]) && (zorder[2] < zorder[1]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY1_OVERLAY0;

    else if((zorder[1] < zorder[0]) && (zorder[0] < zorder[2]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY0_VIDEO_OVERLAY1;

    else if((zorder[1] < zorder[2]) && (zorder[2] < zorder[0]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY0_OVERLAY1_VIDEO;

    else if((zorder[2] < zorder[0]) && (zorder[0] < zorder[1]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY1_VIDEO_OVERLAY0;

    else if((zorder[2] < zorder[1]) && (zorder[1] < zorder[0]))
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_OVERLAY1_OVERLAY0_VIDEO;

    else
        zorder_config = GCREG_BLEND_STACK_ORDER_ORDER_VIDEO_OVERLAY0_OVERLAY1;

    viv_os_write_reg(hardware->os, GCREG_BLEND_STACK_ORDER_Address, zorder_config & 0x7);
    return stat;
}

vivSTATUS viv_hw_layer_set_config(
    viv_dc_hardware *hardware,
    gctUINT id,
    viv_dc_layer layer,
    gctBOOL gamma
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;
    gctUINT8 format = 0, swizzle = 0, uv_swizzle = 0, tile_format = 0;
    gctUINT8 colorkey_enable = 0;
    gctUINT32 tile_stride[3] = {0};

    layer.zorder = layer.zorder > (DC_LAYER_NUM - 1)? (DC_LAYER_NUM - 1) : layer.zorder;
    zorder[id] = layer.zorder;
    _viv_format_to_hw_format(layer.buffer.format, &format, &swizzle, &uv_swizzle);
    _viv_get_tile_format(layer.buffer.tiling, layer.buffer.format, &tile_format);
    _viv_get_plane_stride(layer.buffer.tiling, layer.buffer.format, layer.buffer.stride, tile_stride);

    if (id == 0)
    {
        if (layer.transparency)
        {
            colorkey_enable = GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_ENABLED;
        }
        else
        {
            colorkey_enable = GCREG_FRAME_BUFFER_CONFIG_COLOR_KEY_EN_DISABLED;
        }

        viv_os_write_reg(os, GCREG_FRAME_BUFFER_ADDRESS_Address, (gctUINT32)layer.buffer.phyAddress[0]);
        viv_os_write_reg(os, GCREG_DC_TILE_UV_FRAME_BUFFER_ADR_Address, (gctUINT32)layer.buffer.phyAddress[1]);

        viv_os_write_reg(os, GCREG_FRAME_BUFFER_STRIDE_Address, tile_stride[0]);
        viv_os_write_reg(os, GCREG_DC_TILE_UV_FRAME_BUFFER_STR_Address, tile_stride[1]);

        config = viv_get_reg_config(GCREG_FRAME_BUFFER_CONFIG_Address);
        if(!layer.layer_enable)
            config  &= 0xFFFFFFF7;
        config = gcmSETFIELD(config, GCREG_FRAME_BUFFER_CONFIG, FORMAT, format);
        config = gcmSETFIELD(config, GCREG_FRAME_BUFFER_CONFIG, ENABLE, layer.layer_enable);
        config = gcmSETFIELD(config, GCREG_FRAME_BUFFER_CONFIG, CLEAR_EN, layer.clear_color_enable);
        config = gcmSETFIELD(config, GCREG_FRAME_BUFFER_CONFIG, COLOR_KEY_EN, colorkey_enable);
        config = gcmSETFIELD(config, GCREG_FRAME_BUFFER_CONFIG, SWIZZLE, swizzle);
        config = gcmSETFIELD(config, GCREG_FRAME_BUFFER_CONFIG, UV_SWIZZLE, uv_swizzle);

        viv_os_write_reg(os, GCREG_FRAME_BUFFER_CONFIG_Address, config);
        viv_set_reg_config(GCREG_FRAME_BUFFER_CONFIG_Address, config);

        config = viv_get_reg_config(GCREG_DC_TILE_IN_CFG_Address);
        config = gcmSETFIELD(config, GCREG_DC_TILE_IN_CFG, TILE_FORMAT, tile_format);

        viv_os_write_reg(os, GCREG_DC_TILE_IN_CFG_Address, config);
        viv_set_reg_config(GCREG_DC_TILE_IN_CFG_Address, config);
    }
    else if (id == 1)
    {
        if (layer.transparency)
        {
            colorkey_enable = GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_ENABLED;
        }
        else
        {
            colorkey_enable = GCREG_OVERLAY_CONFIG_COLOR_KEY_EN_DISABLED;
        }

        viv_os_write_reg(os, GCREG_OVERLAY_ADDRESS_Address, (gctUINT32)layer.buffer.phyAddress[0]);
        viv_os_write_reg(os, GCREG_DC_TILE_UV_OVERLAY_ADR_Address, (gctUINT32)layer.buffer.phyAddress[1]);

        viv_os_write_reg(os, GCREG_OVERLAY_STRIDE_Address, tile_stride[0]);
        viv_os_write_reg(os, GCREG_DC_TILE_UV_OVERLAY_STR_Address, tile_stride[1]);

        config = viv_get_reg_config(GCREG_OVERLAY_CONFIG_Address);
        if(!layer.layer_enable)
            config  &= 0xFFFFFFF7;
        config = gcmSETFIELD(config, GCREG_OVERLAY_CONFIG, FORMAT, format)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG, CLEAR_EN, layer.clear_color_enable)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG, COLOR_KEY_EN, colorkey_enable)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG, SWIZZLE, swizzle)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG, UV_SWIZZLE, uv_swizzle)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG, ENABLE, layer.layer_enable);

        viv_os_write_reg(os, GCREG_OVERLAY_CONFIG_Address, config);
        viv_set_reg_config(GCREG_OVERLAY_CONFIG_Address, config);

        config = viv_get_reg_config(GCREG_DC_OVERLAY_TILE_IN_CFG_Address);
        config = gcmSETFIELD(config, GCREG_DC_OVERLAY_TILE_IN_CFG, TILE_FORMAT, tile_format);

        viv_os_write_reg(os, GCREG_DC_OVERLAY_TILE_IN_CFG_Address, config);
        viv_set_reg_config(GCREG_DC_OVERLAY_TILE_IN_CFG_Address, config);
    }
    else if (id == 2)
    {
        if (layer.transparency)
        {
            colorkey_enable = GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_ENABLED;
        }
        else
        {
            colorkey_enable = GCREG_OVERLAY_CONFIG1_COLOR_KEY_EN_DISABLED;
        }

        viv_os_write_reg(os, GCREG_OVERLAY_ADDRESS1_Address, (gctUINT32)layer.buffer.phyAddress[0]);

        viv_os_write_reg(os, GCREG_OVERLAY_STRIDE1_Address, tile_stride[0]);

        config = viv_get_reg_config(GCREG_OVERLAY_CONFIG1_Address);
        if(!layer.layer_enable)
            config  &= 0xFFFFFFF7;
        config = gcmSETFIELD(config, GCREG_OVERLAY_CONFIG1, FORMAT, format)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG1, CLEAR_EN, layer.clear_color_enable)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG1, COLOR_KEY_EN, colorkey_enable)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG1, SWIZZLE, swizzle)
            | gcmSETFIELD(config, GCREG_OVERLAY_CONFIG1, ENABLE, layer.layer_enable);

        viv_os_write_reg(os, GCREG_OVERLAY_CONFIG1_Address, config);
        viv_set_reg_config(GCREG_OVERLAY_CONFIG1_Address, config);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_display_set_size(
    viv_dc_hardware *hardware,
    viv_display id,
    viv_display_size_type size,
    gctBOOL *mem2mem
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT horizontal_total = 0, hsync_start = 0, hsync_end = 0;
    gctUINT vertical_total = 0, vsync_start = 0, vsync_end = 0;
    gctUINT width = 0, height = 0;
    gctUINT config = 0;
    gctBOOL hsync_polarity = SET_POSITIVE;
    gctBOOL vsync_polarity = SET_POSITIVE;

    if (id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    switch (size)
    {
        case vivDISPLAY_320_480_60:
            width = 320;
            height = 480;
            hsync_start = 0;
            hsync_end = width;
            vsync_start = height + 1;
            vsync_end = vsync_start + 1;
            horizontal_total = width;
            vertical_total = height + 5;
            break;

        case vivDISPLAY_480_800_60:
            width = 480;
            height = 800;
            hsync_start = width + 22;
            hsync_end = hsync_start + 20;
            vsync_start = height + 25;
            vsync_end = vsync_start + 16;
            horizontal_total = width + 80;
            vertical_total = height + 60;
            break;

        case vivDISPLAY_480_864_60:
            width = 480;
            height = 864;
            hsync_start = width + 20;
            hsync_end = hsync_start + 2;
            vsync_start = height + 16;
            vsync_end = vsync_start + 10;
            horizontal_total = width + 42;
            vertical_total = height + 32;
            break;

        case vivDISPLAY_640_480_60:
            width = 640;
            height = 480;
            hsync_start = width + 16;
            hsync_end = hsync_start + 96;
            vsync_start = height + 10;
            vsync_end = vsync_start + 2;
            horizontal_total = width + 160;
            vertical_total = height + 45;
            break;

        case vivDISPLAY_720_480_60:
            width = 720;
            height = 480;
            hsync_start = width + 16;
            hsync_end = hsync_start + 62;
            vsync_start = height + 9;
            vsync_end = vsync_start + 6;
            horizontal_total = width + 138;
            vertical_total = height + 45;
            break;

        case vivDISPLAY_800_480_60:
            width = 800;
            height = 480;
            hsync_start = width + 82;
            hsync_end = hsync_start + 3;
            vsync_start = height + 22;
            vsync_end = vsync_start + 3;
            horizontal_total = width + 128;
            vertical_total = height + 45;
            break;

        case vivDISPLAY_1024_600_60:
            width = 1024;
            height = 600;
            hsync_start = width + 160;
            hsync_end = hsync_start + 20;
            vsync_start = height + 12;
            vsync_end = vsync_start + 12;
            horizontal_total = width + 320;
            vertical_total = height + 44;
            break;

        case vivDISPLAY_1024_768_60:
            width = 1024;
            height = 768;
            hsync_start = width + 24;
            hsync_end = hsync_start + 136;
            vsync_start = height + 3;
            vsync_end = vsync_start + 6;
            horizontal_total = width + 320;
            vertical_total = height + 38;
            break;

        case vivDISPLAY_1280_720_60:
            width = 1280;
            height = 720;
            hsync_start = width + 110;
            hsync_end = hsync_start + 40;
            vsync_start = height + 5;
            vsync_end = vsync_start + 5;
            horizontal_total = width + 370;
            vertical_total = height + 30;
            break;

        case vivDISPLAY_1920_1080_60:
            width = 1920;
            height = 1080;
            hsync_start = width + 88;
            hsync_end = hsync_start + 44;
            vsync_start = height + 4;
            vsync_end = vsync_start + 5;
            horizontal_total = width + 280;
            vertical_total = height + 45;
            break;

        default:
            viv_os_print("Not support display size :0x%x .\n", size);
            return vivSTATUS_INVALID_ARGUMENTS;
    }

    config = gcmSETFIELD(0, GCREG_HDISPLAY, DISPLAY_END, width)
        | gcmSETFIELD(0, GCREG_HDISPLAY, TOTAL, horizontal_total);
    viv_os_write_reg(os, GCREG_HDISPLAY_Address, config);

    config = gcmSETFIELD(0, GCREG_VDISPLAY, DISPLAY_END, height)
        | gcmSETFIELD(0, GCREG_VDISPLAY, TOTAL, vertical_total);
    viv_os_write_reg(os, GCREG_VDISPLAY_Address, config);

    config = gcmSETFIELD(0, GCREG_HSYNC, START, hsync_start)
        | gcmSETFIELD(0, GCREG_HSYNC, END, hsync_end);

    config = gcmSETFIELDVALUE(config, GCREG_HSYNC, PULSE, ENABLED);

    config = hsync_polarity ?
        gcmSETFIELDVALUE(config, GCREG_HSYNC, POLARITY, POSITIVE) :
        gcmSETFIELDVALUE(config, GCREG_HSYNC, POLARITY, NEGATIVE);

    viv_os_write_reg(os, GCREG_HSYNC_Address, config);

    config = gcmSETFIELD(0, GCREG_VSYNC, START, vsync_start)
        | gcmSETFIELD(0, GCREG_VSYNC, END, vsync_end);

    config = gcmSETFIELDVALUE(config, GCREG_VSYNC, PULSE, ENABLED);

    config = vsync_polarity ?
        gcmSETFIELDVALUE(config, GCREG_VSYNC, POLARITY, POSITIVE) :
        gcmSETFIELDVALUE(config, GCREG_VSYNC, POLARITY, NEGATIVE);

    viv_os_write_reg(os, GCREG_VSYNC_Address, config);

    return vivSTATUS_OK;
}

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
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;
    gctBOOL hsync_polarity = SET_POSITIVE;
    gctBOOL vsync_polarity = SET_POSITIVE;

    if (id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    config = gcmSETFIELD(0, GCREG_HDISPLAY, DISPLAY_END, hactive)
        | gcmSETFIELD(0, GCREG_HDISPLAY, TOTAL, htotal);
    viv_os_write_reg(os, GCREG_HDISPLAY_Address, config);

    config = gcmSETFIELD(0, GCREG_VDISPLAY, DISPLAY_END, vactive)
        | gcmSETFIELD(0, GCREG_VDISPLAY, TOTAL, vtotal);
    viv_os_write_reg(os, GCREG_VDISPLAY_Address, config);

    config = gcmSETFIELD(0, GCREG_HSYNC, START, hsync_start)
        | gcmSETFIELD(0, GCREG_HSYNC, END, hsync_end);

    config = gcmSETFIELDVALUE(config, GCREG_HSYNC, PULSE, ENABLED);

    config = hsync_polarity ?
        gcmSETFIELDVALUE(config, GCREG_HSYNC, POLARITY, POSITIVE) :
        gcmSETFIELDVALUE(config, GCREG_HSYNC, POLARITY, NEGATIVE);

    viv_os_write_reg(os, GCREG_HSYNC_Address, config);

    config = gcmSETFIELD(0, GCREG_VSYNC, START, vsync_start)
        | gcmSETFIELD(0, GCREG_VSYNC, END, vsync_end);

    config = gcmSETFIELDVALUE(config, GCREG_VSYNC, PULSE, ENABLED);

    config = vsync_polarity ?
        gcmSETFIELDVALUE(config, GCREG_VSYNC, POLARITY, POSITIVE) :
        gcmSETFIELDVALUE(config, GCREG_VSYNC, POLARITY, NEGATIVE);

    viv_os_write_reg(os, GCREG_VSYNC_Address, config);

    return vivSTATUS_OK;
}

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
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;

    if (id != vivDISPLAY_0)
    {
        return vivSTATUS_INVALID_ARGUMENTS;
    }

    if (enable)
    {
        config = GCREG_PANEL_CONFIG_ResetValue;
        config = gcmSETFIELDVALUE(config, GCREG_PANEL_CONFIG, DE, ENABLED)
            | gcmSETFIELDVALUE(config, GCREG_PANEL_CONFIG, DE_POLARITY, POSITIVE)
            | gcmSETFIELDVALUE(config, GCREG_PANEL_CONFIG, CLOCK, ENABLED)
            | gcmSETFIELDVALUE(config, GCREG_PANEL_CONFIG, CLOCK_POLARITY, POSITIVE)
            | gcmSETFIELDVALUE(config, GCREG_PANEL_CONFIG, DATA_POLARITY, POSITIVE);

        viv_os_write_reg(os, GCREG_PANEL_CONFIG_Address, config);

        /* ToDo: set up GCREG_PANEL_TIMING_Address register */
        config = GCREG_PANEL_TIMING_ResetValue;
        viv_os_write_reg(os, GCREG_PANEL_TIMING_Address, config);

        config = viv_get_reg_config(GCREG_PANEL_FUNCTION_Address);
        config = gcmSETFIELDVALUE(config, GCREG_PANEL_FUNCTION, OUTPUT, ENABLED)
            | gcmSETFIELD(config, GCREG_PANEL_FUNCTION, GAMMA, gamma_enable);
        viv_os_write_reg(os, GCREG_PANEL_FUNCTION_Address, config);
        viv_set_reg_config(GCREG_PANEL_FUNCTION_Address, config);

        if (output.type == vivDPI)
        {
            config = GCREG_DBI_CONFIG_ResetValue;
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, BUS_OUTPUT_SEL, DPI);
            viv_os_write_reg(os, GCREG_DBI_CONFIG_Address, config);

            config = GCREG_DPI_CONFIG_ResetValue;
            switch (output.format)
            {
                case vivD24:
                    config = gcmSETFIELDVALUE(config, GCREG_DPI_CONFIG, DPI_DATA_FORMAT, D24);
                    break;
                case vivD16CFG1:
                    config = gcmSETFIELDVALUE(config, GCREG_DPI_CONFIG, DPI_DATA_FORMAT, D16CFG1);
                    break;
                case vivD16CFG2:
                    config = gcmSETFIELDVALUE(config, GCREG_DPI_CONFIG, DPI_DATA_FORMAT, D16CFG2);
                    break;
                case vivD16CFG3:
                    config = gcmSETFIELDVALUE(config, GCREG_DPI_CONFIG, DPI_DATA_FORMAT, D16CFG3);
                    break;
                case vivD18CFG1:
                    config = gcmSETFIELDVALUE(config, GCREG_DPI_CONFIG, DPI_DATA_FORMAT, D18CFG1);
                    break;
                case vivD18CFG2:
                    config = gcmSETFIELDVALUE(config, GCREG_DPI_CONFIG, DPI_DATA_FORMAT, D18CFG2);
                    break;
                default:
                    config = GCREG_DPI_CONFIG_ResetValue;
                    break;
            }

            viv_os_write_reg(os, GCREG_DPI_CONFIG_Address, config);
        }
    }
    else
    {
        config = GCREG_PANEL_CONFIG_ResetValue;
        viv_os_write_reg(os, GCREG_PANEL_CONFIG_Address, config);
    }

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_start_panel_set_config(
    viv_dc_hardware *hardware,
    gctUINT32 mask
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = GCREG_PANEL_WORKING_ResetValue;
    config = gcmSETFIELD(config, GCREG_PANEL_WORKING, WORKING, 0x1);
    viv_os_write_reg(os, GCREG_PANEL_WORKING_Address, config);

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_display_dbi_reset(
    viv_dc_hardware *hardware
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = GCREG_DBI_IF_RESET_ResetValue;

    config = gcmSETFIELDVALUE(config, GCREG_DBI_IF_RESET, DBI_IF_LEVEL_RESET, RESET);
    viv_os_write_reg(os, GCREG_DBI_IF_RESET_Address, config);

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_display_dbi_set_command(
    viv_dc_hardware *hardware,
    viv_display_format_type format,
    viv_dbi_command_type type,
    gctUINT command
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = GCREG_DBI_CMD_ResetValue;

    config = gcmSETFIELD(config, GCREG_DBI_CMD, DBI_COMMAND_WORD, command);

    switch (type)
    {
        case vivDBI_COMMAND_ADDRESS:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CMD, DBI_COMMANDFLAG, ADDRESS);
            break;
        case vivDBI_COMMAND_MEM:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CMD, DBI_COMMANDFLAG, WRITE_MEM_START);
            break;
        case vivDBI_COMMAND_DATA:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CMD, DBI_COMMANDFLAG, PARAMETER_OR_DATA);
            if ((format == vivD1R5G6B5OP1) || (format == vivD1R8G8B8OP1))
            {
               config = config | 0x80000100;
            }
            break;
        default:
            config = GCREG_DBI_CMD_ResetValue;
            break;
    }

    viv_os_write_reg(os, GCREG_DBI_CMD_Address, config);

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_display_dbi_set_config(
    viv_dc_hardware *hardware,
    viv_dbi_type type,
    viv_display_format_type format
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = GCREG_DBI_CONFIG_ResetValue;
    gctUINT config1 = GCREG_DBI_TYPEC_CFG_ResetValue;

    switch (type)
    {
        case vivDBI_AFIXED:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_TYPE, TYPE_AFIXED_E);
            break;
        case vivDBI_ACLOCK:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_TYPE, TYPE_ACLOCK_E);
            break;
        case vivDBI_B:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_TYPE, TYPE_B);
            break;
        case vivDBI_C:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_TYPE, TYPE_C);
            break;
        default:
            break;
    }

    switch (format)
    {
        case vivD8R3G3B2:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D8R3G3B2);
            break;
        case vivD8R4G4B4:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D8R4G4B4);
            break;
        case vivD8R5G6B5:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D8R5G6B5);
            break;
        case vivD8R6G6B6:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D8R6G6B6);
            break;
        case vivD8R8G8B8:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D8R8G8B8);
            break;
        case vivD9R6G6B6:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D9R6G6B6);
            break;
        case vivD16R3G3B2:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16R3G3B2);
            break;
        case vivD16R4G4B4:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16R4G4B4);
            break;
        case vivD16R5G6B5:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16R5G6B5);
            break;
        case vivD16R6G6B6OP1:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16_R6_G6_B6_OP1);
            break;
        case vivD16R6G6B6OP2:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16_R6_G6_B6_OP2);
            break;
        case vivD16R8G8B8OP1:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16_R8_G8_B8_OP1);
            break;
        case vivD16R8G8B8OP2:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D16_R8_G8_B8_OP2);
            break;
        case vivD1R5G6B5OP1:
        case vivD1R5G6B5OP2:
        case vivD1R5G6B5OP3:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D1R5G6B5);
            break;
        case vivD1R8G8B8OP1:
        case vivD1R8G8B8OP2:
        case vivD1R8G8B8OP3:
            config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBI_DATA_FORMAT, D1R8G8B8);
            break;
        default:
            break;
    }

    if (type == vivDBI_C)
    {
        switch (format)
        {
            case vivD1R5G6B5OP1:
            case vivD1R8G8B8OP1:
                config = gcmSETFIELD(config, GCREG_DBI_CONFIG, DBI_TYPEC_OPT, 0);
                break;
            case vivD1R5G6B5OP2:
            case vivD1R8G8B8OP2:
                config = gcmSETFIELD(config, GCREG_DBI_CONFIG, DBI_TYPEC_OPT, 1);
                break;
            case vivD1R5G6B5OP3:
            case vivD1R8G8B8OP3:
                config = gcmSETFIELD(config, GCREG_DBI_CONFIG, DBI_TYPEC_OPT, 2);
                break;
            default:
                break;
        }

        config1 = gcmSETFIELD(config1, GCREG_DBI_TYPEC_CFG, TAS, 0x1)
            | gcmSETFIELD(config1, GCREG_DBI_TYPEC_CFG, SCL_TWRL, 0x1)
            | gcmSETFIELD(config1, GCREG_DBI_TYPEC_CFG, SCL_TWRH, 0x1)
            | gcmSETFIELD(config1, GCREG_DBI_TYPEC_CFG, SCL_SEL, 0x0);

        viv_os_write_reg(os, GCREG_DBI_TYPEC_CFG_Address, config1);
    }

    config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, BUS_OUTPUT_SEL, DBI);

    config = gcmSETFIELDVALUE(config, GCREG_DBI_CONFIG, DBIX_POLARITY, DEFAULT);

    config = gcmSETFIELD(config, GCREG_DBI_CONFIG, DBI_AC_TIME_UNIT, 0);

    viv_os_write_reg(os, GCREG_DBI_CONFIG_Address, config);

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_display_dbi_set_write(
    viv_dc_hardware *hardware
    )
{
    viv_dc_os *os = hardware->os;
    gctUINT config = 0;

    config = gcmSETFIELD(0, GCREG_DBI_WR_CHAR1, DBI_WR_PERIOD, 0x5);
    config = gcmSETFIELD(config, GCREG_DBI_WR_CHAR1, DBI_WR_EOR_WR_ASSERT, 0x2);
    config = gcmSETFIELD(config, GCREG_DBI_WR_CHAR1, DBI_WR_CS_ASSERT, 0x1);
    viv_os_write_reg(os, GCREG_DBI_WR_CHAR1_Address, config);

    config = gcmSETFIELD(0, GCREG_DBI_WR_CHAR2, DBI_WR_EOR_WR_DE_ASRT, 0x3);
    config = gcmSETFIELD(config, GCREG_DBI_WR_CHAR2, DBI_WR_CS_DE_ASRT, 0x4);
    viv_os_write_reg(os, GCREG_DBI_WR_CHAR2_Address, config);

    return vivSTATUS_OK;
}

vivSTATUS viv_hw_dbi_reset(
    viv_dc_hardware *hardware
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_dbi_set_command(
    viv_dc_hardware *hardware,
    gctUINT type,
    gctUINT command
    )
{
    return vivSTATUS_OK;
}

#if vivENABLE_DISPLAY_3DLUT
vivSTATUS viv_hw_3d_lut_set_config(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctBOOL enable,
    gctUINT32* lut
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_3d_lut_ex_config(
    viv_dc_hardware *hardware,
    viv_display display_id,
    gctUINT32* scale_val,
    gctUINT32* offset_val
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_3d_lut_set_enlarge(
    viv_dc_hardware *hardware,
    viv_display display_id,
    viv_lut_enlarge value
    )
{
    return vivSTATUS_OK;
}
#endif

vivSTATUS viv_hw_cursor_set_pos(
    viv_dc_hardware *hardware,
    gctUINT x,
    gctUINT y
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_cursor_move(
    viv_dc_hardware *hardware,
    viv_display display_id,
    viv_cursor* cursor_ptr
    )
{
    return vivSTATUS_OK;
}

/* Inerrupt Operation */
vivSTATUS viv_hw_interrupt_enable(
    viv_dc_hardware *hardware,
    gctBOOL enable
    )
{
    viv_dc_os *os = hardware->os;

    if (enable)
    {
        viv_os_write_reg(os, GCREG_DISPLAY_INTR_ENABLE_Address, 0xFFFFFFFF);
    }
    else
    {
        viv_os_write_reg(os, GCREG_DISPLAY_INTR_ENABLE_Address, 0);
    }

    return vivSTATUS_OK;
}

gctUINT viv_hw_interrupt_get(
    viv_dc_hardware *hardware
    )
{
    gctUINT ret = 0;
    viv_dc_os *os = hardware->os;

    ret = viv_os_read_reg(os, GCREG_DISPLAY_INTR_Address);

    return ret;
}

gctUINT viv_hw_get_vblank_counter(
    viv_dc_hardware *hardware
    )
{
    return vivSTATUS_OK;
}

vivSTATUS viv_hw_dc_reset(
    viv_dc_hardware *hardware
    )
{
    vivSTATUS stat = vivSTATUS_OK;
    gctUINT ret = 0;

    viv_os_write_reg(hardware->os, GCREG_DISPLAY_INTR_ENABLE_Address, 0xFFFFFFFF);

    ret = viv_os_read_reg(hardware->os, GCREG_DISPLAY_INTR_Address);

    ret = viv_os_read_reg(hardware->os, GCREG_SOFT_RESET_Address);
    viv_os_write_reg(hardware->os, GCREG_SOFT_RESET_Address, ret | (1 << 0));

    viv_os_sleep(1);

    ret = viv_os_read_reg(hardware->os, GCREG_DISPLAY_INTR_Address);

    viv_os_write_reg(hardware->os, GCREG_DISPLAY_INTR_ENABLE_Address, 0xFFFFFFFF);

    return stat;
}

gctVOID viv_hw_enable_interrupt(
    viv_dc_hardware *hardware,
    gctBOOL *interrupt_enable
    )
{
    return;
}

#if vivENABLE_DUALOS
vivSTATUS viv_hw_get_layer_status(
    viv_dc_hardware *hardware,
    gctUINT hw_layer,
    viv_layer_status *status)
{
    return vivSTATUS_NOT_SUPPORT;
}

vivSTATUS viv_hw_request_control(
    viv_dc_hardware *hardware,
    gctBOOL *success)
{
    return vivSTATUS_NOT_SUPPORT;
}
#endif

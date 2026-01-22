/***************************************************************************//**
* \file cy_graphics.c
* \version 1.0
*
* Provides an API implementation for Graphics Driver
*
********************************************************************************
* \copyright
* Copyright 2021-2022 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include <string.h>
#if defined(CY_IP_MXS22GFXSS)

#include "cy_graphics.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CLEAR_INTERRUPT      (0xFFFFFFFF)
#define GPU_IDLE_MASK        (0x00000b05) /* Based on GC Nano AQHIIDLE (Idle status register) */
#define CY_GFXSS_WAIT_1_UNIT             (1U)
#define CY_GFXSS_TOTAL_NO_OF_RETRIES     (100U)
#define CLK_SYS_FREQ          (100U) /* System clock frequency in MHz */
#define DC_CLK_FREQ_KHZ       (400000U)
#define MIPI_ENTER_SLEEP_MODE (0x10)
#define MIPI_EXIT_SLEEP_MODE  (0x11)
#define MIPI_SET_DISPLAY_OFF  (0x28)
#define MIPI_SET_DISPLAY_ON   (0x29)
#define AXI_BURST_LENGTH      (128U) /* AXI bus burst length in bytes */

static void cy_gfxss_update_display_rect_params(viv_display_size_type display_size, viv_dc_rect *dc_rect);
static uint8_t cy_gfxss_get_bpp_from_format(viv_input_format_type        format);
static vivSTATUS cy_gfxss_dc_init(GFXSS_Type *base, cy_stc_gfx_dc_config_t *config, cy_stc_mipidsi_config_t *mipi_dsi_cfg);
extern gctBOOL _viv_is_yuv_format(viv_input_format_type format);


static void cy_gfxss_update_display_rect_params(viv_display_size_type display_size, viv_dc_rect *dc_rect)
{

    dc_rect->x = 0;
    dc_rect->y = 0;

    switch(display_size)
    {
        case vivDISPLAY_320_480_60:
            dc_rect->w = 320;
            dc_rect->h = 480;
            break;

        case vivDISPLAY_480_800_60:
            dc_rect->w = 480;
            dc_rect->h = 800;
            break;

        case vivDISPLAY_480_864_60:
            dc_rect->w = 480;
            dc_rect->h = 864;
            break;

        case vivDISPLAY_640_480_60:
            dc_rect->w = 640;
            dc_rect->h = 480;
            break;

        case vivDISPLAY_720_480_60:
            dc_rect->w = 720;
            dc_rect->h = 480;
            break;

        case vivDISPLAY_800_480_60:
            dc_rect->w = 800;
            dc_rect->h = 480;
            break;

        case vivDISPLAY_1024_600_60:
            dc_rect->w = 1024;
            dc_rect->h = 600;
            break;

        case vivDISPLAY_1024_768_60:
            dc_rect->w = 1024;
            dc_rect->h = 768;
            break;

        case vivDISPLAY_1280_720_60:
            dc_rect->w = 1280;
            dc_rect->h = 720;
            break;

        case vivDISPLAY_1920_1080_60:
            dc_rect->w = 1920;
            dc_rect->h = 1080;
            break;

        default:
            dc_rect->w = 0;
            dc_rect->h = 0;
        }
}

/** Get number of bits per pixel from the given display format */
static uint8_t cy_gfxss_get_bpp_from_format(viv_input_format_type format)
{
    uint8_t bpp = 0;

    switch(format)
    {
      case vivNV12:
      case vivNV16:
      case vivNV21:
          {
              bpp = 8;
          }
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

           {
               bpp = 16;
           }
           break;
      case vivARGB8888:
      case vivABGR8888:
      case vivRGBA8888:
      case vivBGRA8888:
      case vivXRGB8888:
      case vivXBGR8888:
      case vivRGBX8888:
      case vivBGRX8888:
      case vivARGB2101010:
           {
               bpp = 32;
           }
           break;
      default:
           {
               bpp = 0;
           }

    }

    return bpp;
}

static uint32_t cy_gfxss_configure_layer(cy_stc_gfx_layer_config_t *layer_config)
{
    gctUINT bpp = 0, stride = 0;
    viv_dc_buffer buffer = {0};
    uint32_t ret = 0;
    viv_dc_rect display_rect = {0};

    /* select layer */
    viv_dc_select_layer(layer_config->layer_type);

    /* enable layer if visibility is true*/
    if (layer_config->visibility)
    {
        viv_layer_enable(vivTRUE);
    }
    bpp = cy_gfxss_get_bpp_from_format(layer_config->input_format_type);

    stride = layer_config->width * bpp / 8;

    /* config the buffer's phyAddr/format/tilemode/bufferWidth/bufferHeight/stride to kernel */
    buffer.phyAddress[0] = (gctADDRESS) layer_config->buffer_address;
    buffer.stride[0] = stride;
    if ((layer_config->input_format_type == vivNV12) || (layer_config->input_format_type == vivYUY2))
    {
        buffer.phyAddress[1] = (gctADDRESS) layer_config->uv_buffer_address;
        buffer.stride[1] = stride;
    }
    buffer.format = layer_config->input_format_type;
    buffer.tiling = layer_config->tiling_type;
    buffer.width = layer_config->width;
    buffer.height = layer_config->height;
    viv_layer_set(&buffer);

    /* config display region on panel */
    display_rect.x = 0;
    display_rect.y = 0;
    display_rect.w = layer_config->width;
    display_rect.h = layer_config->height;

    viv_layer_scale(&display_rect, vivFILTER_H3_V3);

    viv_layer_set_position(layer_config->pos_x, layer_config->pos_y);

    viv_layer_zorder(layer_config->zorder);

    viv_layer_poterduff_blend(vivTRUE, vivPD_SRC_OVER);

    viv_layer_set_display(vivDISPLAY_0);

    return ret;
}
/** Display controller initialization */
static vivSTATUS cy_gfxss_dc_init(GFXSS_Type *base, cy_stc_gfx_dc_config_t *config, cy_stc_mipidsi_config_t *mipi_dsi_cfg)
{
    vivSTATUS ret = vivSTATUS_OK;
    viv_dc_rect display_rect;
    viv_output display_output;

    memset(&display_rect, 0, sizeof(viv_dc_rect));
    memset(&display_output, 0, sizeof(viv_output));

    (void)base;

    /* open device */
    ret = viv_dc_init();

    if(ret)
        return ret;

    /* reset DC */
    viv_dc_reset();

    if ((config->display_type == GFX_DISP_TYPE_DPI) || (config->display_type == GFX_DISP_TYPE_DSI_DPI))
    {
        viv_conf_display_set_custom_size(dcCore, vivDISPLAY_0,
        mipi_dsi_cfg->display_params->hdisplay,
        mipi_dsi_cfg->display_params->hdisplay + mipi_dsi_cfg->display_params->hfp,
        mipi_dsi_cfg->display_params->hdisplay + mipi_dsi_cfg->display_params->hfp + mipi_dsi_cfg->display_params->hsync_width,
        mipi_dsi_cfg->display_params->hdisplay + mipi_dsi_cfg->display_params->hfp + mipi_dsi_cfg->display_params->hsync_width + mipi_dsi_cfg->display_params->hbp,
        mipi_dsi_cfg->display_params->vdisplay,
        mipi_dsi_cfg->display_params->vdisplay + mipi_dsi_cfg->display_params->vfp,
        mipi_dsi_cfg->display_params->vdisplay + mipi_dsi_cfg->display_params->vfp + mipi_dsi_cfg->display_params->vsync_width,
        mipi_dsi_cfg->display_params->vdisplay + mipi_dsi_cfg->display_params->vfp + mipi_dsi_cfg->display_params->vsync_width + mipi_dsi_cfg->display_params->vbp
        );
    }
    else
    {
        viv_conf_display_set_custom_size(dcCore, vivDISPLAY_0,
        mipi_dsi_cfg->display_params->hdisplay,
        0,
        mipi_dsi_cfg->display_params->hdisplay,
        mipi_dsi_cfg->display_params->hdisplay,
        mipi_dsi_cfg->display_params->vdisplay,
        0,
        mipi_dsi_cfg->display_params->vdisplay,
        mipi_dsi_cfg->display_params->vdisplay
        );
    }

    /* Configure Graphics/Video Layer */
    if(config->gfx_layer_config != NULL && config->gfx_layer_config->layer_enable )
    {
        cy_gfxss_configure_layer(config->gfx_layer_config);
    }

    /* Configure Overlay 0 Layer */
    if(config->ovl0_layer_config != NULL && config->ovl0_layer_config->layer_enable )
    {
        cy_gfxss_configure_layer(config->ovl0_layer_config);
    }

    /* Configure Overlay 1 Layer */
    if(config->ovl1_layer_config != NULL && config->ovl1_layer_config->layer_enable )
    {
        /* Check if Overlay 1 is using YUV format and unsupported tiling type */
    if ((config->ovl1_layer_config->input_format_type >= vivYUY2 && config->ovl1_layer_config->input_format_type <= vivNV21)
            || config->ovl1_layer_config->tiling_type != vivLINEAR )
        {
            return vivSTATUS_NOT_SUPPORT;
        }

        cy_gfxss_configure_layer(config->ovl1_layer_config);
    }


    /* Get display size from viv_display_size_type */
    cy_gfxss_update_display_rect_params(config->display_size, &display_rect);

    viv_set_display_size(vivDISPLAY_0, config->display_size);

    display_output.format = config->display_format;

    if ((config->display_type == GFX_DISP_TYPE_DPI) || (config->display_type == GFX_DISP_TYPE_DSI_DPI))
    {
        display_output.type = vivDPI;
        viv_set_output(vivDISPLAY_0, &display_output, vivTRUE);
    }
    else
    {
        display_output.type = vivDBI;

        if(config->display_type == GFX_DISP_TYPE_DSI_DBI)
        {
            viv_set_output_dbi(vivDISPLAY_0, vivDBI_B);
        }
        else
        {
            viv_set_output_dbi(vivDISPLAY_0, (viv_dbi_type)config->display_type);
        }
        viv_set_output(vivDISPLAY_0, &display_output, vivTRUE);
        viv_set_commit(1);
    }


    return ret;
}

cy_en_gfx_status_t Cy_GFXSS_Init(GFXSS_Type *base, cy_stc_gfx_config_t *config, cy_stc_gfx_context_t *context)
{

/* Configures:-

 - Clock and power
 - Enable IP Block
 - Call vg_lite_init() and vg_lite_allocate() with video/graphics layer resolution.
 - Sets the user provided interrupt mask setting.  */

    if ((NULL == base) || (NULL == config) || (NULL == context) || (NULL == config->dc_cfg))
    {
        return CY_GFX_BAD_PARAM;
    }

    uint32_t frac_divider;
    cy_en_gfx_status_t result = CY_GFX_SUCCESS;
    GFXSS_GPU_Type *gpu_base = &(base->GFXSS_GPU);
    GFXSS_DC_Type *dc_base = &(base->GFXSS_DC);
    GFXSS_MIPIDSI_Type *mipidsi_base = &(base->GFXSS_MIPIDSI);

    cy_stc_gfx_dc_config_t *dc_cfg = config->dc_cfg;
    cy_stc_mipidsi_config_t *mipi_dsi_cfg = config->mipi_dsi_cfg;

    /* Assume Clock and Power are already available by this moment */

    /* Enable GPU if user provided configuration */
    if (config->gpu_cfg->enable)
    {
        gpu_base->MXGPU.CTL |= GFXSS_GPU_MXGPU_CTL_ENABLED_Msk;
        context->gpu_context.enabled = true;
    }

    /* Configure MIPI DSI */
    if (((config->dc_cfg->display_type == GFX_DISP_TYPE_DSI_DBI) ||
         (config->dc_cfg->display_type == GFX_DISP_TYPE_DSI_DPI)) &&
        (mipi_dsi_cfg != NULL) && (result == CY_GFX_SUCCESS))
    {
        /* DSI specific Configuration */
        mipidsi_base->MXMIPIDSI.CLK_CTL |= GFXSS_MIPIDSI_MXMIPIDSI_CLK_CTL_CLK_CFG_Msk;
        mipidsi_base->MXMIPIDSI.CTL |= GFXSS_MIPIDSI_MXMIPIDSI_CTL_ENABLED_Msk;
        mipidsi_base->MXMIPIDSI.PHY_FREQ_RANGE = _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_PHY_FREQ_RANGE_CFG_CLK_FREQ_RANGE, (((CLK_SYS_FREQ / 2)   - 17U) * 4U));
        mipidsi_base->MXMIPIDSI.INTR_MASK = _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_CORE_MASK, 1U) | _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DBI_TE_MASK, 1U) | _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DPI_HALT_MASK, 1U);

        if (config->dc_cfg->display_type == GFX_DISP_TYPE_DSI_DPI)
        {
            mipidsi_base->MXMIPIDSI.DBI_CMD = 1;
        }
        else
        {
            mipidsi_base->MXMIPIDSI.DPI_CMD = 1; /* Default Polarity */
        }

        if (Cy_MIPIDSI_Init(mipidsi_base, mipi_dsi_cfg, &context->mipidsi_context) != CY_MIPIDSI_SUCCESS)
        {
            result = CY_GFX_BAD_PARAM;
        }

        context->clockHz = config->clockHz;
        context->mipidsi_context.virtual_ch = mipi_dsi_cfg->virtual_ch;             /**< Display controller configuration */
        context->mipidsi_context.num_of_lanes = mipi_dsi_cfg->num_of_lanes;           /**< GPU configuration is optional */
        context->mipidsi_context.per_lane_mbps = mipi_dsi_cfg->per_lane_mbps;          /**< per lane speed in mbps */
        context->mipidsi_context.dpi_fmt = mipi_dsi_cfg->dpi_fmt;                /**< MIPI DSI configuration */
        context->mipidsi_context.max_phy_clk = mipi_dsi_cfg->max_phy_clk;            /**< device max DPHY clock in MHz unit */
        context->mipidsi_context.dsi_mode = mipi_dsi_cfg->dsi_mode;               /**< Command mode/Video mode */
        context->mipidsi_context.mode_flags = mipi_dsi_cfg->mode_flags;             /**< Additional mode information */
        context->mipidsi_context.enable = true;

        memcpy(&context->mipidsi_context.display_params, mipi_dsi_cfg->display_params, sizeof(cy_stc_mipidsi_display_params_t));        /**< Display parameters */
    }else{
         context->mipidsi_context.enable = false;
    }

    /* Configure Display Controller */

        frac_divider = (uint32_t)(((float)(config->clockHz / 1000U) / mipi_dsi_cfg->display_params->pixel_clock) * BIT(16));   //Getting fractional divider value for pixel clock in fixed point representation.
        frac_divider < 0x20000 ? frac_divider = 0x20000 : frac_divider; //Minimum value of fractional divider is 2.
        dc_base->MXDC.CLK_CTL = _VAL2FLD(GFXSS_DC_MXDC_CLK_CTL_CLK_DIV, frac_divider) | GFXSS_DC_MXDC_CLK_CTL_CLK_CORE_Msk;
        dc_base->MXDC.CTL |= GFXSS_DC_MXDC_CTL_ENABLED_Msk;
        dc_base->MXDC.INTR_MASK |= _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_CORE_MASK, 1U) | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR0_MASK, 1U)
                                | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR1_MASK, 1U) | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR2_MASK, 1U)
                                | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR3_MASK, 1U) | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_RLAD_ERROR_MASK, 1U);

        switch(config->dc_cfg->display_type)
        {
            case GFX_DISP_TYPE_DPI:
            {
                dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_DPI_ENABLED_Msk;
            }
            break;
            case GFX_DISP_TYPE_DBI_A:
            case GFX_DISP_TYPE_DBI_B:
            case GFX_DISP_TYPE_DBI_C:
            {
                dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_DBI_ENABLED_Msk;

                /* SPI Interface */
                if (config->dc_cfg->display_type == GFX_DISP_TYPE_DBI_C)
                {
                    dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_SPI_ENABLED_Msk;
                }
            }
            break;
            case GFX_DISP_TYPE_DSI_DBI:
            case GFX_DISP_TYPE_DSI_DPI:
            {
                if(mipidsi_base == NULL)
                {
                    return CY_GFX_BAD_PARAM;
                }

                dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_DPI_ENABLED_Msk;
            }

            break;
            default:
            {
                /* Unsupported Display type */
                return CY_GFX_BAD_PARAM;
            }
        }

        if (cy_gfxss_dc_init(base,dc_cfg,mipi_dsi_cfg) != 0U)
        {
            result = CY_GFX_BAD_PARAM;
        }else
        {
            if(dc_cfg->gfx_layer_config == NULL) {
                context->dc_context.gfx_layer_config.layer_enable = false;
            }else
            {
                memcpy(&context->dc_context.gfx_layer_config, dc_cfg->gfx_layer_config, sizeof(cy_stc_gfx_layer_config_t));
            }
            if(dc_cfg->ovl0_layer_config == NULL) {
                context->dc_context.ovl0_layer_config.layer_enable = false;
            }else
            {
                memcpy(&context->dc_context.ovl0_layer_config, dc_cfg->ovl0_layer_config, sizeof(cy_stc_gfx_layer_config_t));
            }
            if(dc_cfg->ovl1_layer_config == NULL) {
                context->dc_context.ovl1_layer_config.layer_enable = false;
            }else
            {
                memcpy(&context->dc_context.ovl1_layer_config, dc_cfg->ovl1_layer_config, sizeof(cy_stc_gfx_layer_config_t));
            }
            if(dc_cfg->rlad_config == NULL) {
                context->dc_context.rlad_config.enable = false;
            }else
            {
                memcpy(&context->dc_context.rlad_config, dc_cfg->rlad_config, sizeof(cy_stc_gfx_rlad_cfg_t));
                Cy_GFXSS_RLAD_SetImage(base, dc_cfg->rlad_config, context);
                if(context->dc_context.rlad_config.enable == 1U){
                    Cy_GFXSS_RLAD_Enable(base, context);
                }
            }
            if(dc_cfg->cursor_config == NULL) {
                context->dc_context.cursor_config.enable = false;
            }else
            {
                memcpy(&context->dc_context.cursor_config, dc_cfg->cursor_config, sizeof(cy_stc_gfx_cursor_config_t));
            }
            context->dc_context.display_type = dc_cfg->display_type;
            context->dc_context.display_format = dc_cfg->display_format;
            context->dc_context.display_size = dc_cfg->display_size;
            context->dc_context.display_width = dc_cfg->display_width;
            context->dc_context.display_height = dc_cfg->display_height;
            context->dc_context.interrupt_mask = dc_cfg->interrupt_mask;
        }

    return result;

}

cy_en_gfx_status_t  Cy_GFXSS_SleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    /*
     * No action required for sleep mode.
     * The graphics subsystem is an active component and does not retain state across sleep.
     * No context save/restore is needed before or after sleep transitions.
     */
    (void)callbackParams;
    (void)mode;
    return CY_GFX_SUCCESS;
}

cy_en_syspm_status_t  Cy_GFXSS_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{

    if ((NULL == callbackParams) || (NULL == callbackParams->base) || (NULL == callbackParams->context))
    {
        return CY_SYSPM_FAIL;
    }

    cy_en_syspm_status_t retStatus = CY_SYSPM_SUCCESS;
    int32_t ts_width, ts_height, intr_mask;
    GFXSS_Type *locBase = (GFXSS_Type *) callbackParams->base;
    cy_stc_gfx_context_t *locContext = (cy_stc_gfx_context_t *) callbackParams->context;

    GFXSS_GPU_Type *gpu_base = &(locBase->GFXSS_GPU);
    GFXSS_DC_Type *dc_base = &(locBase->GFXSS_DC);
    GFXSS_MIPIDSI_Type *mipidsi_base = &(locBase->GFXSS_MIPIDSI);

    switch(mode)
    {
        case CY_SYSPM_CHECK_READY:
        {
		bool checkFail = false;
            intr_mask = dc_base->MXDC.INTR_MASK;
            dc_base->MXDC.INTR_MASK = 0U;
            if(locContext->gpu_context.enabled)
            {
                checkFail = (gpu_base->GCNANO.AQHIIDLE & GPU_IDLE_MASK ) != GPU_IDLE_MASK;
            }
            if (checkFail)
            {
                dc_base->MXDC.INTR_MASK = intr_mask;
                retStatus = CY_SYSPM_FAIL;
            }
            else
            {
                retStatus = CY_SYSPM_SUCCESS;
            }
        }
        break;

        case CY_SYSPM_CHECK_FAIL:
        {
            retStatus = CY_SYSPM_SUCCESS;
        }
        break;
        case CY_SYSPM_AFTER_TRANSITION:
        {
            /* Enable GPU if user provided configuration */
            if(locContext->gpu_context.enabled)
            {
                gpu_base->MXGPU.CTL |= GFXSS_GPU_MXGPU_CTL_ENABLED_Msk;
            }

            /* Configure Display Controller */
            uint32_t frac_divider = (uint32_t)(((float)(locContext->clockHz / 1000U) / locContext->mipidsi_context.display_params.pixel_clock) * BIT(16));   //Getting fractional divider value for pixel clock in fixed point representation.
            frac_divider < 0x20000 ? frac_divider = 0x20000 : frac_divider; //Minimum value of fractional divider is 2.
            dc_base->MXDC.CLK_CTL = _VAL2FLD(GFXSS_DC_MXDC_CLK_CTL_CLK_DIV, frac_divider) | GFXSS_DC_MXDC_CLK_CTL_CLK_CORE_Msk;
            dc_base->MXDC.CTL |= GFXSS_DC_MXDC_CTL_ENABLED_Msk;

            dc_base->MXDC.INTR_MASK |= _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_CORE_MASK, 1U) | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR0_MASK, 1U)
                                    | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR1_MASK, 1U) | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR2_MASK, 1U)
                                    | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_ADDR3_MASK, 1U) | _VAL2FLD(GFXSS_DC_MXDC_INTR_MASK_RLAD_ERROR_MASK, 1U);

            switch(locContext->dc_context.display_type)
            {
                case GFX_DISP_TYPE_DPI:
                {
                    dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_DPI_ENABLED_Msk;
                }
                break;
                case GFX_DISP_TYPE_DBI_A:
                case GFX_DISP_TYPE_DBI_B:
                case GFX_DISP_TYPE_DBI_C:
                {
                    dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_DBI_ENABLED_Msk;
                    /* SPI Interface */
                    if (locContext->dc_context.display_type == GFX_DISP_TYPE_DBI_C)
                    {
                        dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_SPI_ENABLED_Msk;
                    }
                }
                break;
                case GFX_DISP_TYPE_DSI_DBI:
                case GFX_DISP_TYPE_DSI_DPI:
                {
                    if(mipidsi_base == NULL)
                    {
                        retStatus = CY_SYSPM_FAIL;
                    }

                    dc_base->MXDC.IO_CTL |= GFXSS_DC_MXDC_IO_CTL_DPI_ENABLED_Msk;

                    /* DSI specific Configuration */
                    mipidsi_base->MXMIPIDSI.CLK_CTL |= GFXSS_MIPIDSI_MXMIPIDSI_CLK_CTL_CLK_CFG_Msk;
                    mipidsi_base->MXMIPIDSI.CTL |= GFXSS_MIPIDSI_MXMIPIDSI_CTL_ENABLED_Msk;
                    mipidsi_base->MXMIPIDSI.PHY_FREQ_RANGE = _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_PHY_FREQ_RANGE_CFG_CLK_FREQ_RANGE, (((CLK_SYS_FREQ / 2)   - 17U) * 4U));
                    mipidsi_base->MXMIPIDSI.INTR_MASK = _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_CORE_MASK, 1U) | _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DBI_TE_MASK, 1U) | _VAL2FLD(GFXSS_MIPIDSI_MXMIPIDSI_INTR_MASK_DPI_HALT_MASK, 1U);

                    if (locContext->dc_context.display_type == GFX_DISP_TYPE_DSI_DPI)
                    {
                        mipidsi_base->MXMIPIDSI.DBI_CMD = 1;
                    }
                    else
                    {
                        mipidsi_base->MXMIPIDSI.DPI_CMD = 1; /* Default Polarity */
                    }
                }

                break;
            }

            cy_stc_gfx_dc_config_t dccfg;
            cy_stc_mipidsi_config_t dsicfg;

            if(locContext->dc_context.gfx_layer_config.layer_enable==false){
                dccfg.gfx_layer_config = NULL;
            }else{
                dccfg.gfx_layer_config = &locContext->dc_context.gfx_layer_config;
            }
            if(locContext->dc_context.ovl0_layer_config.layer_enable==false){
                dccfg.ovl0_layer_config = NULL;
            }else{
                dccfg.ovl0_layer_config = &locContext->dc_context.ovl0_layer_config;
            }
            if(locContext->dc_context.ovl1_layer_config.layer_enable==false){
                dccfg.ovl1_layer_config = NULL;
            }else{
                dccfg.ovl1_layer_config = &locContext->dc_context.ovl1_layer_config;
            }
            if(locContext->dc_context.rlad_config.enable==false){
                dccfg.rlad_config = NULL;
            }else{
                dccfg.rlad_config = &locContext->dc_context.rlad_config;
            }
            if(locContext->dc_context.cursor_config.enable==false){
                dccfg.cursor_config = NULL;
            }else{
                dccfg.cursor_config = &locContext->dc_context.cursor_config;
            }
            dccfg.display_type = locContext->dc_context.display_type;
            dccfg.display_format = locContext->dc_context.display_format;
            dccfg.display_size = locContext->dc_context.display_size;
            dccfg.display_width = locContext->dc_context.display_width;
            dccfg.display_height = locContext->dc_context.display_height;
            dccfg.interrupt_mask = locContext->dc_context.interrupt_mask;

            /* Configure MIPI DSI */
            if(locContext->mipidsi_context.enable != false){
                dsicfg.virtual_ch = locContext->mipidsi_context.virtual_ch;
                dsicfg.num_of_lanes = locContext->mipidsi_context.num_of_lanes;
                dsicfg.per_lane_mbps = locContext->mipidsi_context.per_lane_mbps;
                dsicfg.dpi_fmt = locContext->mipidsi_context.dpi_fmt;
                dsicfg.max_phy_clk = locContext->mipidsi_context.max_phy_clk;
                dsicfg.dsi_mode = locContext->mipidsi_context.dsi_mode;
                dsicfg.mode_flags = locContext->mipidsi_context.mode_flags;
                dsicfg.display_params = &locContext->mipidsi_context.display_params;
                Cy_MIPIDSI_Init(mipidsi_base, &dsicfg, &locContext->mipidsi_context);
            }
            cy_gfxss_dc_init(locBase, &dccfg, &dsicfg);

            if(dccfg.rlad_config != NULL)
            {
                Cy_GFXSS_RLAD_SetImage(locBase, dccfg.rlad_config, locContext);
                if(locContext->dc_context.rlad_config.enable){
                    Cy_GFXSS_RLAD_Enable(locBase, locContext);
                }
            }

            if(locContext->dc_context.gfx_layer_config.layer_enable){
                if ((locContext->dc_context.gfx_layer_config.input_format_type == vivNV12) || (locContext->dc_context.gfx_layer_config.input_format_type == vivYUY2))
                {
                    Cy_GFXSS_Set_FrameBuffer_YUV(locBase, (uint32_t *)(locContext->dc_context.gfx_layer_config.buffer_address), (uint32_t *)(locContext->dc_context.gfx_layer_config.uv_buffer_address), locContext);
                }
                else
                {
                    Cy_GFXSS_Set_FrameBuffer(locBase, (uint32_t *)(locContext->dc_context.gfx_layer_config.buffer_address), locContext);
                }
            }
            if(locContext->dc_context.ovl0_layer_config.layer_enable){
                if ((locContext->dc_context.gfx_layer_config.input_format_type == vivNV12) || (locContext->dc_context.gfx_layer_config.input_format_type == vivYUY2))
                {
                    Cy_GFXSS_Set_Overlay0_YUV(locBase, (uint32_t *)(locContext->dc_context.ovl0_layer_config.buffer_address), (uint32_t *)(locContext->dc_context.ovl0_layer_config.uv_buffer_address), locContext);
                }
                else
                {
                    Cy_GFXSS_Set_Overlay0(locBase, (uint32_t *)(locContext->dc_context.ovl0_layer_config.buffer_address), locContext);
                }
            }
            if(locContext->dc_context.ovl1_layer_config.layer_enable){
		Cy_GFXSS_Set_Overlay1(locBase, (uint32_t *)(locContext->dc_context.ovl1_layer_config.buffer_address), locContext);
            }
            if(locContext->gpu_context.enabled && locContext->gpu_context.vg_lite_initialised){
                vg_lite_init(locContext->gpu_context.ts_width, locContext->gpu_context.ts_height);
            }

            retStatus = CY_SYSPM_SUCCESS;

        }
        break;

        case CY_SYSPM_BEFORE_TRANSITION:
        {
            if( vg_lite_get_tessellation_parameters( &ts_width, &ts_height) == VG_LITE_SUCCESS){
                locContext->gpu_context.vg_lite_initialised = true;
                locContext->gpu_context.ts_width = (uint32_t)ts_width;
                locContext->gpu_context.ts_height = (uint32_t)ts_height;
                vg_lite_close();
            }else{
                locContext->gpu_context.vg_lite_initialised = false;
            }

            viv_dc_deinit();

            retStatus = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retStatus = CY_SYSPM_FAIL;
            break;
    }

    return (retStatus);
}

void Cy_GFXSS_Clear_DC_Interrupt(GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
  CY_ASSERT(base != NULL);

  (void)context;

  GFXSS_DC_Type *dc_base = &(base->GFXSS_DC);

  /* DC */
  if (dc_base != NULL)
  {
      (void)(dc_base->DCNANO.GCREGDISPLAYINTR);
      dc_base->MXDC.INTR = CLEAR_INTERRUPT;
  }
}

void Cy_GFXSS_Clear_GPU_Interrupt(GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
  CY_ASSERT(base != NULL);

  (void)context;

  GFXSS_GPU_Type *gpu_base = &(base->GFXSS_GPU);

  if (gpu_base != NULL)
  {
      gpu_base->MXGPU.INTR = CLEAR_INTERRUPT;
  }
}


void  Cy_GFXSS_Interrupt(GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
  CY_ASSERT(base != NULL);

  (void)context;

  GFXSS_GPU_Type *gpu_base = &(base->GFXSS_GPU);
  GFXSS_DC_Type *dc_base = &(base->GFXSS_DC);
  GFXSS_MIPIDSI_Type *mipidsi_base = &(base->GFXSS_MIPIDSI);

  /* Clear interrupts */

  /* GPU */
  if (gpu_base != NULL)
  {
      gpu_base->MXGPU.INTR = CLEAR_INTERRUPT;
  }

  /* DC */
  if (dc_base != NULL)
  {
      dc_base->MXDC.INTR = CLEAR_INTERRUPT;
  }

  /* MIPI DSI */
  if (mipidsi_base != NULL)
  {
      mipidsi_base->MXMIPIDSI.INTR = CLEAR_INTERRUPT;
  }
}

cy_en_gfx_status_t Cy_GFXSS_Set_FrameBuffer(GFXSS_Type *base, uint32_t* gfx_layer_buffer, cy_stc_gfx_context_t *context)
{

    if ((NULL == base) || (NULL == context) || (NULL == gfx_layer_buffer))
    {
        return CY_GFX_BAD_PARAM;
    }

    base->GFXSS_DC.DCNANO.GCREGFRAMEBUFFERADDRESS = (uint32_t)gfx_layer_buffer;
    context->dc_context.gfx_layer_config.buffer_address = (gctADDRESS *)gfx_layer_buffer;
    viv_set_commit(0x1);

    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Set_FrameBuffer_YUV(GFXSS_Type *base, uint32_t* y_buffer, uint32_t* uv_buffer, cy_stc_gfx_context_t *context)
{
   if ((base == NULL) || (y_buffer == NULL)){
    return CY_GFX_BAD_PARAM;
    }

    base->GFXSS_DC.DCNANO.GCREGFRAMEBUFFERADDRESS = (uint32_t)y_buffer;
    context->dc_context.gfx_layer_config.buffer_address = (gctADDRESS *)y_buffer;

    viv_input_format_type format = context->dc_context.gfx_layer_config.input_format_type;

    if (format == vivNV12 || format == vivNV21){
        if (uv_buffer == NULL){
            return CY_GFX_BAD_PARAM;
        }
        base->GFXSS_DC.DCNANO.GCREGDCTILEUVFRAMEBUFFERADR = (uint32_t)uv_buffer;
        context->dc_context.gfx_layer_config.uv_buffer_address = (gctADDRESS *)uv_buffer;
    }
    viv_set_commit(0x1);
    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Set_Overlay0(GFXSS_Type *base, uint32_t* overlay0_buffer, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context) || (NULL == overlay0_buffer))
    {
        return CY_GFX_BAD_PARAM;
    }

    base->GFXSS_DC.DCNANO.GCREGOVERLAYADDRESS = (uint32_t)overlay0_buffer;
    context->dc_context.ovl0_layer_config.buffer_address = (gctADDRESS *)overlay0_buffer;
    viv_set_commit(0x1);
    return CY_GFX_SUCCESS;

}

cy_en_gfx_status_t Cy_GFXSS_Set_Overlay0_YUV(GFXSS_Type *base, uint32_t* y_buffer, uint32_t* uv_buffer, cy_stc_gfx_context_t *context)
{
    CY_ASSERT(base != NULL);

    if ((y_buffer != NULL) && (uv_buffer != NULL))
    {
        base->GFXSS_DC.DCNANO.GCREGOVERLAYADDRESS = (uint32_t)y_buffer;
        base->GFXSS_DC.DCNANO.GCREGDCTILEUVOVERLAYADR = (uint32_t)uv_buffer;
        context->dc_context.ovl0_layer_config.buffer_address = (gctADDRESS *)y_buffer;
        context->dc_context.ovl0_layer_config.uv_buffer_address = (gctADDRESS *)uv_buffer;
        viv_set_commit(0x1);

    }
    else
    {
        return CY_GFX_BAD_PARAM;
    }

    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Set_Overlay1(GFXSS_Type *base, uint32_t* overlay1_buffer, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context) || (NULL == overlay1_buffer))  /* CHANGE: Add all checks */
    {
        return CY_GFX_BAD_PARAM;
    }

    base->GFXSS_DC.DCNANO.GCREGOVERLAYADDRESS1 = (uint32_t)overlay1_buffer;
    context->dc_context.ovl1_layer_config.buffer_address = (gctADDRESS *)overlay1_buffer;
    viv_set_commit(0x1);
    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Set_Layer_Enabled(GFXSS_Type *base, cy_en_gfx_layer_type_t layer_id, bool enable)
{
    if (NULL == base)
    {
        return CY_GFX_BAD_PARAM;
    }

    switch(layer_id)
    {
        case GFX_LAYER_GRAPHICS:
            if(enable)
            {
                base->GFXSS_DC.DCNANO.GCREGFRAMEBUFFERCONFIG |= GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_ENABLE_Msk;
            }
            else
            {
                base->GFXSS_DC.DCNANO.GCREGFRAMEBUFFERCONFIG &= ~GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_ENABLE_Msk;
            }
            break;

        case GFX_LAYER_OVERLAY0:
            if (enable)
            {
                base->GFXSS_DC.DCNANO.GCREGOVERLAYCONFIG |= GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_ENABLE_Msk;
            }
            else
            {
                base->GFXSS_DC.DCNANO.GCREGOVERLAYCONFIG &= ~GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_ENABLE_Msk;
            }
            break;
        case GFX_LAYER_OVERLAY1:
            if (enable)
            {
                base->GFXSS_DC.DCNANO.GCREGOVERLAYCONFIG1 |= GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_ENABLE_Msk;
            }
            else
            {
                base->GFXSS_DC.DCNANO.GCREGOVERLAYCONFIG1 &= ~GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_ENABLE_Msk;
            }
            break;
        default:
            return CY_GFX_BAD_PARAM;
    }
    viv_set_commit(0x1);
    return CY_GFX_SUCCESS;
}

uint32_t* Cy_GFXSS_Get_FrameBufferAddress(GFXSS_Type *base)
{
    CY_ASSERT(base != NULL);

    return (uint32_t *)(base->GFXSS_DC.DCNANO.GCREGFRAMEBUFFERADDRESS);

}

cy_en_gfx_status_t Cy_GFXSS_DeInit(GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    GFXSS_GPU_Type *gpu_base = &(base->GFXSS_GPU);
    GFXSS_DC_Type *dc_base = &(base->GFXSS_DC);
    GFXSS_MIPIDSI_Type *mipidsi_base = &(base->GFXSS_MIPIDSI);

    /* Disable GPU */
    gpu_base->MXGPU.CTL &= ~GFXSS_GPU_MXGPU_CTL_ENABLED_Msk;
    context->gpu_context.enabled = false;


    /* Disable DC */
    if(context->dc_context.gfx_layer_config.layer_enable){
        viv_dc_select_layer(context->dc_context.gfx_layer_config.layer_type);
        viv_layer_enable(vivFALSE);
        viv_set_commit(0x1);
    }
    if(context->dc_context.ovl0_layer_config.layer_enable){
        viv_dc_select_layer(context->dc_context.ovl0_layer_config.layer_type);
        viv_layer_enable(vivFALSE);
        viv_set_commit(0x1);
    }
    if(context->dc_context.ovl1_layer_config.layer_enable){
        viv_dc_select_layer(context->dc_context.ovl1_layer_config.layer_type);
        viv_layer_enable(vivFALSE);
        viv_set_commit(0x1);
    }

    viv_dc_deinit();
    dc_base->MXDC.CTL &= ~GFXSS_DC_MXDC_CTL_ENABLED_Msk;

    /* MIPI DSI Base */
    Cy_MIPIDSI_DeInit(mipidsi_base);
    Cy_MIPIDSI_Disable(mipidsi_base);

    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_RLAD_SetImage(GFXSS_Type *base, cy_stc_gfx_rlad_cfg_t *rlad_cfg, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == rlad_cfg) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    GFXSS_DC_Type *gfxss_dc = &(base->GFXSS_DC);

    if(gfxss_dc !=NULL)
    {
        context->dc_context.rlad_config = *rlad_cfg;
        /* Update Layer ID and Disable RLAD by default */
        gfxss_dc->MXDC.RLAD_CTL = _VAL2FLD(GFXSS_DC_MXDC_RLAD_CTL_RLAD_LAYER, rlad_cfg->layer_id + 1U);

        /* Image properties */
        gfxss_dc->MXDC.RLAD_IMG = (_VAL2FLD(GFXSS_DC_MXDC_RLAD_IMG_RLAD_WIDTH, rlad_cfg->image_width) |
                                    _VAL2FLD(GFXSS_DC_MXDC_RLAD_IMG_RLAD_HEIGHT, rlad_cfg->image_height) |
                                    _VAL2FLD(GFXSS_DC_MXDC_RLAD_IMG_RLAD_FORMAT, rlad_cfg->rlad_format));
        /* RLAD compression mode */
        gfxss_dc->MXDC.RLAD_ENC = _VAL2FLD(GFXSS_DC_MXDC_RLAD_ENC_RLAD_MODE, rlad_cfg->compression_mode);
        gfxss_dc->MXDC.RLAD_ENC |= _VAL2FLD(GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_R, 8U);
        gfxss_dc->MXDC.RLAD_ENC |= _VAL2FLD(GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_G, 8U);
        gfxss_dc->MXDC.RLAD_ENC |= _VAL2FLD(GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_B, 8U);
        gfxss_dc->MXDC.RLAD_ENC |= _VAL2FLD(GFXSS_DC_MXDC_RLAD_ENC_RLAD_BITS_A, 8U);

        /* Compressed Image address */
        gfxss_dc->MXDC.RLAD_BUF0 = (uint32_t)rlad_cfg->image_address;

        /* Compressed Image size */
        gfxss_dc->MXDC.RLAD_BUF1 = _VAL2FLD(GFXSS_DC_MXDC_RLAD_BUF1_RLAD_SIZE, rlad_cfg->compressed_image_size);

        return CY_GFX_SUCCESS;
    }
    else
    {
        return CY_GFX_BAD_PARAM;
    }
}

cy_en_gfx_status_t Cy_GFXSS_RLAD_Enable( GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    GFXSS_DC_Type *gfxss_dc = &(base->GFXSS_DC);

    if(gfxss_dc !=NULL)
    {
        gfxss_dc->MXDC.RLAD_CTL |= GFXSS_DC_MXDC_RLAD_CTL_RLAD_ENABLE_Msk;
        context->dc_context.rlad_config.enable = true;
    }
    else
    {
        return CY_GFX_BAD_PARAM;
    }
    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_RLAD_Disable( GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    GFXSS_DC_Type *gfxss_dc = &(base->GFXSS_DC);

    if(gfxss_dc !=NULL)
    {
        gfxss_dc->MXDC.RLAD_CTL &= ~GFXSS_DC_MXDC_RLAD_CTL_RLAD_ENABLE_Msk;
        context->dc_context.rlad_config.enable = false;
    }
    else
    {
        return CY_GFX_BAD_PARAM;
    }

    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Transfer_Frame( GFXSS_Type *base, cy_stc_gfx_context_t *context){

    if ((NULL == base) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    GFXSS_DC_Type *gfxss_dc = &(base->GFXSS_DC);
    GFXSS_MIPIDSI_Type *mipi_dsi_base = &(base->GFXSS_MIPIDSI);

    uint8_t packet_col_address[5], packet_row_address[5];
    uint32_t horizontal_resolution = context->dc_context.display_width;
    uint32_t vertical_resolution = context->dc_context.display_height;
    uint32_t No_of_lines = 0, i=0, j = 0, line_stride = 0, line_stride_overlay = 0, line_stride_overlay1 = 0;
    bool is_yuv_gfx = false, is_yuv_ovl0 = false;
    uint32_t uv_stride = 0, uv_stride_overlay = 0;
    uint8_t bytes_per_pixel_framebuffer = RGB_16_BIT_PIXEL_FORMAT_IN_BYTES;
    float bytes_per_pixel_dc_output = 0;
    uint8_t bytes_per_pixel_overlay = RGB_16_BIT_PIXEL_FORMAT_IN_BYTES;
    uint8_t bytes_per_pixel_overlay1 = RGB_16_BIT_PIXEL_FORMAT_IN_BYTES;
    uint32_t rtos_delay_us = 0, yuv_tile_setup_delay_us = 0;

    switch(context->dc_context.display_format)
    {
    case vivD8R3G3B2:
	case vivD16R3G3B2:
         bytes_per_pixel_dc_output = 1.0f;
         break;
    case vivD8R4G4B4:
    case vivD16R4G4B4:
         bytes_per_pixel_dc_output = 1.5f;
         break;
    case vivD8R5G6B5:
    case vivD16R5G6B5:
         bytes_per_pixel_dc_output = 2.0f;
         break;
    case vivD8R6G6B6:
    case vivD9R6G6B6:
    case vivD16R6G6B6OP1:
    case vivD16R6G6B6OP2:
         bytes_per_pixel_dc_output = 2.25f;
         break;
    case vivD8R8G8B8:
    case vivD16R8G8B8OP1:
    case vivD16R8G8B8OP2:
         bytes_per_pixel_dc_output = 3.0f;
         break;

    default:
         bytes_per_pixel_dc_output = 2.0f;
         break;
    }

    /*Dc_dbitypeab_div_int == dc_gcregdbiwrchar1_dbi_wr_period * (m_dc_gcregdbiconfig_dbi_ac_time_unit +1);
    500 Mbps per lane
    500/8 = 62.5 MHz lane byte clock
    max DBI clock should be 1/4th of lane byte clock = 15.625 MHz
    Divider value close to 15.625 MHz = 13 for 15.38 Mhz */
    uint32_t lane_byte_clock_KHz = (context->mipidsi_context.per_lane_mbps * 1000U) / 8U;  /* 500000/8 = 62500 KHz lane byte clock*/
    uint32_t dbi_clock_KHz = lane_byte_clock_KHz / 4U;                           /* Max DBI clock should be 1/4th of lane byte clock = 62500 / 4 = 15625 KHz*/
    uint32_t dsi_clock_KHz = context->clockHz / 2000U;                     /* DSI internal divider of 2 and conversion to KHz, dsi clock = (400000000 / 2) / 1000 MHz = 200000 KHz*/
    uint32_t divider = (dsi_clock_KHz + dbi_clock_KHz - 1) / dbi_clock_KHz;      /* ceil of divider value dsi_clock_KHz / dbi_clock_KHz = 200000 / 15625 = 13*/
    divider < 3 ? divider = 3 : divider;       /* minimum value for divider is 3*/
    dbi_clock_KHz = dsi_clock_KHz / divider;   /* calculate dbi clock value after divider */

    gfxss_dc->DCNANO.GCREGDBIWRCHAR1 &= ~GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_PERIOD_Msk;
    gfxss_dc->DCNANO.GCREGDBIWRCHAR1 |= _VAL2FLD(GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_PERIOD, divider);

    /* Calculate time required by DMA to transfer one slice */
    if ((context->dc_context.display_format == vivD16R8G8B8OP1) || (context->dc_context.display_format == vivD16R8G8B8OP2))
    {
        rtos_delay_us = ((DBI_SCLICE_LIMIT_IN_BYTES * 1000U / 2U) / dbi_clock_KHz) + 50U;
    }
    else
    {
        rtos_delay_us = ((DBI_SCLICE_LIMIT_IN_BYTES * 1000U )/ dbi_clock_KHz) + 50U;
    }

    if (context->dc_context.gfx_layer_config.layer_enable) {
        is_yuv_gfx = _viv_is_yuv_format(context->dc_context.gfx_layer_config.input_format_type);
    }
    if (context->dc_context.ovl0_layer_config.layer_enable) {
        is_yuv_ovl0 = _viv_is_yuv_format(context->dc_context.ovl0_layer_config.input_format_type);
    }
    // Only yuv tiled format is supported for YUV input buffers
    if (is_yuv_gfx){
        bytes_per_pixel_framebuffer = 1;  // Y plane has 1 byte per pixel
        // YUV stride calculation for tiled format
        switch (context->dc_context.gfx_layer_config.input_format_type) {
            case vivNV12:
            case vivNV21:
                line_stride = horizontal_resolution *8; //  For each UV tile line DC sends, there should be 2 corresponding Y tile lines
                uv_stride = horizontal_resolution * 4;
                break;
            case vivYUY2:
            case vivUYVY:
                line_stride = horizontal_resolution * 4;
                uv_stride = 0;  // Packed format
                break;
            default:
                return CY_GFX_BAD_PARAM;
        }

        if (line_stride % AXI_BURST_LENGTH != 0U) {
            line_stride = AXI_BURST_LENGTH * ((line_stride / AXI_BURST_LENGTH) + 1);
        }
        if (uv_stride > 0 && uv_stride % AXI_BURST_LENGTH != 0U) {
            uv_stride = AXI_BURST_LENGTH * ((uv_stride / AXI_BURST_LENGTH) + 1);
        }
    } else {
        if(_FLD2VAL(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_FORMAT, gfxss_dc->DCNANO.GCREGFRAMEBUFFERCONFIG) == 4U) {
            bytes_per_pixel_framebuffer = RGB_32_BIT_PIXEL_FORMAT_IN_BYTES;
        }
        if ((horizontal_resolution * bytes_per_pixel_framebuffer) % AXI_BURST_LENGTH != 0U) {
            line_stride = AXI_BURST_LENGTH * (((horizontal_resolution * bytes_per_pixel_framebuffer) / AXI_BURST_LENGTH) + 1);
        } else {
            line_stride = horizontal_resolution * bytes_per_pixel_framebuffer;
        }
    }

    if (is_yuv_ovl0){
        bytes_per_pixel_overlay = 1;  // Y plane has 1 byte per pixel
        // YUV stride calculation for tiled format
        switch (context->dc_context.ovl0_layer_config.input_format_type) {
            case vivNV12:
            case vivNV21:
                line_stride_overlay = horizontal_resolution *8; //  For each UV tile line DC sends, there should be 2 corresponding Y tile lines
                uv_stride_overlay = horizontal_resolution * 4;
                break;
            case vivYUY2:
            case vivUYVY:
                line_stride_overlay = horizontal_resolution * 4;
                uv_stride_overlay = 0;  // Packed format
                break;
            default:
                return CY_GFX_BAD_PARAM;
        }

        if (line_stride_overlay % AXI_BURST_LENGTH != 0U) {
            line_stride_overlay = AXI_BURST_LENGTH * ((line_stride_overlay / AXI_BURST_LENGTH) + 1);
        }
        if (uv_stride_overlay > 0 && uv_stride_overlay % AXI_BURST_LENGTH != 0U) {
            uv_stride_overlay = AXI_BURST_LENGTH * ((uv_stride_overlay / AXI_BURST_LENGTH) + 1);
        }
    } else {
        if(_FLD2VAL(GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_FORMAT, gfxss_dc->DCNANO.GCREGOVERLAYCONFIG) == 4U) {
            bytes_per_pixel_overlay = RGB_32_BIT_PIXEL_FORMAT_IN_BYTES;
        }
        if ((horizontal_resolution * bytes_per_pixel_overlay) % AXI_BURST_LENGTH != 0U) {
            line_stride_overlay = AXI_BURST_LENGTH * (((horizontal_resolution * bytes_per_pixel_overlay) / AXI_BURST_LENGTH) + 1);
        } else {
            line_stride_overlay = horizontal_resolution * bytes_per_pixel_overlay;
        }
    }

    // Overlay 1 supports RGB only
    if(_FLD2VAL(GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_FORMAT, gfxss_dc->DCNANO.GCREGOVERLAYCONFIG1) == 4U)
    {
        bytes_per_pixel_overlay1 = RGB_32_BIT_PIXEL_FORMAT_IN_BYTES;
    }

        if ((horizontal_resolution * bytes_per_pixel_overlay1) % AXI_BURST_LENGTH != 0U)
    {
        line_stride_overlay1 = AXI_BURST_LENGTH * (((horizontal_resolution * bytes_per_pixel_overlay1) / AXI_BURST_LENGTH) + 1);
    }
    else
    {
        line_stride_overlay1 = horizontal_resolution * bytes_per_pixel_overlay1;
    }

    No_of_lines = (uint32_t)(DBI_SCLICE_LIMIT_IN_BYTES / (horizontal_resolution * bytes_per_pixel_dc_output));
    // Adjust for YUV tiled formats - must be multiple of 8
    if ((is_yuv_gfx || is_yuv_ovl0) && (No_of_lines % 8 != 0)) {
	No_of_lines = (No_of_lines / 8) * 8;
    }

    mipi_dsi_base->DWCMIPIDSI.DBI_CMDSIZE = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_WR_CMD_SIZE , (No_of_lines * bytes_per_pixel_dc_output * horizontal_resolution) + 1U ) |
                                   _VAL2FLD( GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_ALLOWED_CMD_SIZE , ((uint8_t)(AXI_BURST_LENGTH / bytes_per_pixel_dc_output)) * bytes_per_pixel_dc_output + 1U);
    mipi_dsi_base->DWCMIPIDSI.DBI_CFG = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_OUT_DBI_CONF , context->mipidsi_context.dpi_fmt) |
                                   _VAL2FLD( GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_IN_DBI_CONF , context->mipidsi_context.dpi_fmt);
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERSTRIDE = line_stride;
    gfxss_dc->DCNANO.GCREGOVERLAYSTRIDE = line_stride_overlay;
    gfxss_dc->DCNANO.GCREGOVERLAYSTRIDE1 = line_stride_overlay1;
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGOVERLAYSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGOVERLAYSIZE1 = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGVDISPLAY = _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_DISPLAY_END, No_of_lines) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_TOTAL, (No_of_lines + 1));
    gfxss_dc->DCNANO.GCREGVSYNC =  _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_START, 0U ) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_END,  No_of_lines);

    if(is_yuv_gfx){
        // Ensure we wait for YUV tile setup complete before starting the transfer
        yuv_tile_setup_delay_us = ((46U * lane_byte_clock_KHz) / 1000U) + 1000U;
        Cy_SysLib_Rtos_DelayUs(yuv_tile_setup_delay_us);
    }

    packet_col_address[0] = 0x2A;
    packet_col_address[1] = 0x00;
    packet_col_address[2] = 0x00;
    packet_col_address[3] = ( (horizontal_resolution - 1) >> 8) & 0xff;
    packet_col_address[4] = ( (horizontal_resolution - 1) & 0xff);

    packet_row_address[0] = 0x2B;

    uint32_t tile_rows = No_of_lines  / 8;

    for(i = 0; i <= vertical_resolution-No_of_lines; i += No_of_lines){
        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_col_address[0], 5);

        packet_row_address[1] = ((j * No_of_lines) >> 8) & 0xff;
        packet_row_address[2] =  (j * No_of_lines) & 0xff ;
        packet_row_address[3] = (( (j * No_of_lines) + (No_of_lines - 1) ) >> 8) & 0xff;
        packet_row_address[4] =  ( (j * No_of_lines) + (No_of_lines - 1) ) & 0xff;
        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_row_address[0], 5);

        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_ADDRESS, 0x2C); // send data
        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_MEM, 0x0);
        Cy_SysLib_Rtos_DelayUs(rtos_delay_us);
        if (is_yuv_gfx) {
            // TILED: Advance by tile rows
            gfxss_dc->DCNANO.GCREGFRAMEBUFFERADDRESS += (tile_rows * line_stride);

            if (uv_stride > 0) {
                gfxss_dc->DCNANO.GCREGDCTILEUVFRAMEBUFFERADR += (tile_rows * uv_stride);

            }
        } else {
            gfxss_dc->DCNANO.GCREGFRAMEBUFFERADDRESS += (No_of_lines * line_stride);
        }

        if (is_yuv_ovl0) {
            gfxss_dc->DCNANO.GCREGOVERLAYADDRESS += (tile_rows * line_stride_overlay);
            if (uv_stride_overlay > 0) {
                gfxss_dc->DCNANO.GCREGDCTILEUVOVERLAYADR += (tile_rows * uv_stride_overlay);
                }
        } else {
            gfxss_dc->DCNANO.GCREGOVERLAYADDRESS += (No_of_lines * line_stride_overlay);
        }
        j++;
    }

    No_of_lines = vertical_resolution % No_of_lines;

    if(No_of_lines > 0 )
    {
        mipi_dsi_base->DWCMIPIDSI.DBI_CMDSIZE = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_WR_CMD_SIZE , (No_of_lines * bytes_per_pixel_dc_output * horizontal_resolution) + 1U ) |
                                       _VAL2FLD( GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_ALLOWED_CMD_SIZE , ((uint8_t)(AXI_BURST_LENGTH / bytes_per_pixel_dc_output)) * bytes_per_pixel_dc_output + 1U);

        gfxss_dc->DCNANO.GCREGFRAMEBUFFERSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT, No_of_lines);
        gfxss_dc->DCNANO.GCREGOVERLAYSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_HEIGHT, No_of_lines);
        gfxss_dc->DCNANO.GCREGOVERLAYSIZE1 = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_HEIGHT, No_of_lines);
        gfxss_dc->DCNANO.GCREGVDISPLAY = _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_DISPLAY_END, No_of_lines) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_TOTAL, (No_of_lines + 1));
        gfxss_dc->DCNANO.GCREGVSYNC =  _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_START, 0U ) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_END,  No_of_lines);

        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_col_address[0], 5);

        packet_row_address[1] = ((vertical_resolution - No_of_lines) >> 8) & 0xff;
        packet_row_address[2] = (vertical_resolution - No_of_lines) & 0xff;
        packet_row_address[3] = ((vertical_resolution - 1) >> 8) & 0xff;
        packet_row_address[4] = (vertical_resolution - 1) & 0xff;
        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_row_address[0], 5);

        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_ADDRESS, 0x2C); // send data
        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_MEM, 0x0);
        /* Calculate time required by DMA to transfer remaining slice */
        if ((context->dc_context.display_format == vivD16R8G8B8OP1) || (context->dc_context.display_format == vivD16R8G8B8OP2))
        {
            rtos_delay_us = ((No_of_lines *line_stride * 1000U / 2U) / dbi_clock_KHz) + 50U;
        }
        else
        {
            rtos_delay_us = ((No_of_lines * line_stride * 1000U )/ dbi_clock_KHz) + 50U;
        }
        Cy_SysLib_Rtos_DelayUs(rtos_delay_us);
    }
        return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_TransferPartialFrame(GFXSS_Type *base, uint32_t start_line_offset, uint32_t end_line_offset, cy_stc_gfx_context_t *context) {


    // Check if start_line_offset and end_line_offset is in required vertical length of display panel

    if ((NULL == base) || (NULL == context) || (start_line_offset >= end_line_offset) || (end_line_offset > context->dc_context.display_height))
    {
        return CY_GFX_BAD_PARAM;
    }

    GFXSS_DC_Type *gfxss_dc =    &(base->GFXSS_DC);
    GFXSS_MIPIDSI_Type *mipi_dsi_base = &(base->GFXSS_MIPIDSI);
    uint32_t partial_size = (end_line_offset - start_line_offset);

    uint8_t packet_col_address[5], packet_row_address[5];
    uint32_t horizontal_resolution = context->dc_context.display_width;
    uint32_t No_of_lines = 0, i = 0, line_stride = 0, line_stride_overlay = 0, line_stride_overlay1 = 0;

    uint8_t bytes_per_pixel_framebuffer = RGB_16_BIT_PIXEL_FORMAT_IN_BYTES;
    float bytes_per_pixel_dc_output = 0;
    uint8_t bytes_per_pixel_overlay = RGB_16_BIT_PIXEL_FORMAT_IN_BYTES;
    uint8_t bytes_per_pixel_overlay1 = RGB_16_BIT_PIXEL_FORMAT_IN_BYTES;
    uint32_t rtos_delay_us = 0;

    switch(context->dc_context.display_format)
    {
    case vivD8R3G3B2:
	case vivD16R3G3B2:
         bytes_per_pixel_dc_output = 1.0f;
         break;
    case vivD8R4G4B4:
    case vivD16R4G4B4:
         bytes_per_pixel_dc_output = 1.5f;
         break;
    case vivD8R5G6B5:
    case vivD16R5G6B5:
         bytes_per_pixel_dc_output = 2.0f;
         break;
    case vivD8R6G6B6:
    case vivD9R6G6B6:
    case vivD16R6G6B6OP1:
    case vivD16R6G6B6OP2:
         bytes_per_pixel_dc_output = 2.25f;
         break;
    case vivD8R8G8B8:
    case vivD16R8G8B8OP1:
    case vivD16R8G8B8OP2:
         bytes_per_pixel_dc_output = 3.0f;
         break;

    default:
         bytes_per_pixel_dc_output = 2.0f;
         break;
    }

    /*Dc_dbitypeab_div_int == dc_gcregdbiwrchar1_dbi_wr_period * (m_dc_gcregdbiconfig_dbi_ac_time_unit +1);
    500 Mbps per lane
    500/8 = 62.5 MHz lane byte clock
    max DBI clock should be 1/4th of lane byte clock = 15.625 MHz
    Divider value close to 15.625 MHz = 13 for 15.38 Mhz */
    uint32_t lane_byte_clock_KHz = (context->mipidsi_context.per_lane_mbps * 1000U) / 8U;  /* 500000/8 = 62500 KHz lane byte clock*/
    uint32_t dbi_clock_KHz = lane_byte_clock_KHz / 4U;                           /* Max DBI clock should be 1/4th of lane byte clock = 62500 / 4 = 15625 KHz*/
    uint32_t dsi_clock_KHz = context->clockHz / 2000U;                     /* DSI internal divider of 2 and conversion to KHz, dsi clock = (400000000 / 2) / 1000 MHz = 200000 KHz*/
    uint32_t divider = (dsi_clock_KHz + dbi_clock_KHz - 1) / dbi_clock_KHz;      /* ceil of divider value dsi_clock_KHz / dbi_clock_KHz = 200000 / 15625 = 13*/
    divider < 3 ? divider = 3 : divider;       /* minimum value for divider is 3*/
    dbi_clock_KHz = dsi_clock_KHz / divider;   /* calculate dbi clock value after divider */

    gfxss_dc->DCNANO.GCREGDBIWRCHAR1 &= ~GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_PERIOD_Msk;
    gfxss_dc->DCNANO.GCREGDBIWRCHAR1 |= _VAL2FLD(GFXSS_DC_DCNANO_GCREGDBIWRCHAR1_GCREGDBIWRCHAR1_DBI_WR_PERIOD, divider);

        /* Calculate time required by DMA to transfer one slice */
    if ((context->dc_context.display_format == vivD16R8G8B8OP1) || (context->dc_context.display_format == vivD16R8G8B8OP2))
    {
        rtos_delay_us = ((DBI_SCLICE_LIMIT_IN_BYTES * 1000U / 2U) / dbi_clock_KHz) + 50U;
    }
    else
    {
        rtos_delay_us = ((DBI_SCLICE_LIMIT_IN_BYTES * 1000U )/ dbi_clock_KHz) + 50U;
    }


    if(_FLD2VAL(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERCONFIG_GCREGFRAMEBUFFERCONFIG_FORMAT, gfxss_dc->DCNANO.GCREGFRAMEBUFFERCONFIG) == 4U)
    {
        bytes_per_pixel_framebuffer = RGB_32_BIT_PIXEL_FORMAT_IN_BYTES;
    }
    if(_FLD2VAL(GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG_GCREGOVERLAYCONFIG_FORMAT, gfxss_dc->DCNANO.GCREGOVERLAYCONFIG) == 4U)
    {
        bytes_per_pixel_overlay = RGB_32_BIT_PIXEL_FORMAT_IN_BYTES;
    }
    if(_FLD2VAL(GFXSS_DC_DCNANO_GCREGOVERLAYCONFIG1_GCREGOVERLAYCONFIG1_FORMAT, gfxss_dc->DCNANO.GCREGOVERLAYCONFIG1) == 4U)
    {
        bytes_per_pixel_overlay1 = RGB_32_BIT_PIXEL_FORMAT_IN_BYTES;
    }

    No_of_lines = (uint32_t)(DBI_SCLICE_LIMIT_IN_BYTES / (horizontal_resolution * bytes_per_pixel_dc_output));
        if (No_of_lines > (end_line_offset - start_line_offset)) {
        No_of_lines = end_line_offset - start_line_offset;
    }
    mipi_dsi_base->DWCMIPIDSI.DBI_CMDSIZE = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_WR_CMD_SIZE , (No_of_lines * bytes_per_pixel_dc_output * horizontal_resolution) + 1U ) |
                                   _VAL2FLD( GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_ALLOWED_CMD_SIZE , ((uint8_t)(AXI_BURST_LENGTH / bytes_per_pixel_dc_output)) * bytes_per_pixel_dc_output + 1U);
    mipi_dsi_base->DWCMIPIDSI.DBI_CFG = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_OUT_DBI_CONF , context->mipidsi_context.dpi_fmt) |
                                   _VAL2FLD( GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CFG_DBI_CFG_IN_DBI_CONF , context->mipidsi_context.dpi_fmt);

    if ((horizontal_resolution * bytes_per_pixel_framebuffer) % AXI_BURST_LENGTH != 0U)
    {
        line_stride = AXI_BURST_LENGTH * (((horizontal_resolution * bytes_per_pixel_framebuffer) / AXI_BURST_LENGTH) + 1);
    }
    else
    {
        line_stride = horizontal_resolution * bytes_per_pixel_framebuffer;

    }

    if ((horizontal_resolution * bytes_per_pixel_overlay) % AXI_BURST_LENGTH != 0U)
    {
        line_stride_overlay = AXI_BURST_LENGTH * (((horizontal_resolution * bytes_per_pixel_overlay) / AXI_BURST_LENGTH) + 1);
    }
    else
    {
        line_stride_overlay = horizontal_resolution * bytes_per_pixel_overlay;
    }

    if ((horizontal_resolution * bytes_per_pixel_overlay1) % AXI_BURST_LENGTH != 0U)
    {
        line_stride_overlay1 = AXI_BURST_LENGTH * (((horizontal_resolution * bytes_per_pixel_overlay1) / AXI_BURST_LENGTH) + 1);
    }
    else
    {
        line_stride_overlay1 = horizontal_resolution * bytes_per_pixel_overlay1;
    }

    // Configure frame buffer for partial transfer based on total number of lines in possible for command buffer
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERADDRESS = (uint32_t) context->dc_context.gfx_layer_config.buffer_address;
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERADDRESS += (start_line_offset * line_stride);
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERSTRIDE = line_stride;
    gfxss_dc->DCNANO.GCREGOVERLAYSTRIDE = line_stride_overlay;
    gfxss_dc->DCNANO.GCREGOVERLAYSTRIDE1 = line_stride_overlay1;
    gfxss_dc->DCNANO.GCREGFRAMEBUFFERSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGOVERLAYSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGOVERLAYSIZE1 = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_HEIGHT, No_of_lines);
    gfxss_dc->DCNANO.GCREGVDISPLAY = _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_DISPLAY_END, No_of_lines) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_TOTAL, (No_of_lines + 1));
    gfxss_dc->DCNANO.GCREGVSYNC =  _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_START, 0U ) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_END,  No_of_lines);

    packet_col_address[0] = 0x2A;
    packet_col_address[1] = 0x00;
    packet_col_address[2] = 0x00;
    packet_col_address[3] = ( (horizontal_resolution - 1) >> 8) & 0xff;
    packet_col_address[4] = ( (horizontal_resolution - 1) & 0xff);

    packet_row_address[0] = 0x2B;
    for(i = No_of_lines; i <= partial_size; i += No_of_lines){

        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_col_address[0], 5);

        packet_row_address[1] = ((start_line_offset) >> 8) & 0xff;
        packet_row_address[2] =  (start_line_offset) & 0xff ;
        packet_row_address[3] = ((start_line_offset + (No_of_lines - 1) ) >> 8) & 0xff;
        packet_row_address[4] =  ( start_line_offset + (No_of_lines - 1) ) & 0xff;
        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_row_address[0], 5);

        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_ADDRESS, 0x2C); // send data
        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_MEM, 0x0);

        Cy_SysLib_Rtos_DelayUs(rtos_delay_us);
        start_line_offset += (No_of_lines);
       // Update frame buffer addresses for specified range
        gfxss_dc->DCNANO.GCREGFRAMEBUFFERADDRESS += (No_of_lines * line_stride);
        gfxss_dc->DCNANO.GCREGOVERLAYADDRESS += (No_of_lines * line_stride_overlay);
        gfxss_dc->DCNANO.GCREGOVERLAYADDRESS1 += (No_of_lines * line_stride_overlay1);

    }

    // Remaining number of lines
    No_of_lines = partial_size % No_of_lines;


    if(No_of_lines > 0 )
    {
        // Configure delay required to transfer remaining number of lines
        if ((context->dc_context.display_format == vivD16R8G8B8OP1) || (context->dc_context.display_format == vivD16R8G8B8OP2))
        {
            rtos_delay_us = ((No_of_lines *line_stride * 1000U / 2U) / dbi_clock_KHz) + 50U;
        }
        else
        {
            rtos_delay_us = ((No_of_lines * line_stride * 1000U )/ dbi_clock_KHz) + 50U;
        }

        // Update frame buffer for remaining number of lines
        mipi_dsi_base->DWCMIPIDSI.DBI_CMDSIZE = _VAL2FLD(GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_WR_CMD_SIZE , (No_of_lines * bytes_per_pixel_dc_output * horizontal_resolution) + 1U ) |
                                       _VAL2FLD( GFXSS_MIPIDSI_DWCMIPIDSI_DBI_CMDSIZE_DBI_CMDSIZE_ALLOWED_CMD_SIZE , ((uint8_t)(AXI_BURST_LENGTH / bytes_per_pixel_dc_output)) * bytes_per_pixel_dc_output + 1U);

        gfxss_dc->DCNANO.GCREGFRAMEBUFFERSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGFRAMEBUFFERSIZE_GCREGFRAMEBUFFERSIZE_HEIGHT, No_of_lines);
        gfxss_dc->DCNANO.GCREGOVERLAYSIZE = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE_GCREGOVERLAYSIZE_HEIGHT, No_of_lines);
        gfxss_dc->DCNANO.GCREGOVERLAYSIZE1 = _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_WIDTH, horizontal_resolution) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGOVERLAYSIZE1_GCREGOVERLAYSIZE1_HEIGHT, No_of_lines);
        gfxss_dc->DCNANO.GCREGVDISPLAY = _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_DISPLAY_END, No_of_lines) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVDISPLAY_GCREGVDISPLAY_TOTAL, (No_of_lines + 1));
        gfxss_dc->DCNANO.GCREGVSYNC =  _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_START, 0U ) | _VAL2FLD(GFXSS_DC_DCNANO_GCREGVSYNC_GCREGVSYNC_END,  No_of_lines);

        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_col_address[0], 5);

        packet_row_address[1] = ((end_line_offset - No_of_lines) >> 8) & 0xff;
        packet_row_address[2] = (end_line_offset - No_of_lines) & 0xff;
        packet_row_address[3] = ((end_line_offset - 1) >> 8) & 0xff;
        packet_row_address[4] = (end_line_offset - 1) & 0xff;
        (void)Cy_MIPIDSI_WritePacket(mipi_dsi_base, &packet_row_address[0], 5);

        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_ADDRESS, 0x2C); // send data
        viv_hw_display_dbi_set_command(DC_CORE->hardware, context->dc_context.display_format, vivDBI_COMMAND_MEM, 0x0);

        Cy_SysLib_Rtos_DelayUs(rtos_delay_us);
    }
        return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Enable_GPU( GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    uint32_t timeout = CY_GFXSS_TOTAL_NO_OF_RETRIES;
    GFXSS_GPU_Type *gpu_base = &(base->GFXSS_GPU);

    gpu_base->MXGPU.CTL |= GFXSS_GPU_MXGPU_CTL_ENABLED_Msk;

    while ((_FLD2VAL(GFXSS_GPU_MXGPU_STATUS_CORE_RST, gpu_base->MXGPU.STATUS) != 0U) && ( timeout > 0u))
    {
        Cy_SysLib_DelayUs(CY_GFXSS_WAIT_1_UNIT);
        timeout--;
    }
    if(_FLD2VAL(GFXSS_GPU_MXGPU_STATUS_CORE_RST, gpu_base->MXGPU.STATUS) != 0U)
    {
        return CY_GFX_TIMEOUT;
    }
    context->gpu_context.enabled = true;
    return CY_GFX_SUCCESS;
}

cy_en_gfx_status_t Cy_GFXSS_Disable_GPU( GFXSS_Type *base, cy_stc_gfx_context_t *context)
{
    if ((NULL == base) || (NULL == context))
    {
        return CY_GFX_BAD_PARAM;
    }

    uint32_t timeout = CY_GFXSS_TOTAL_NO_OF_RETRIES;
    GFXSS_GPU_Type *gpu_base = &(base->GFXSS_GPU);

    while((gpu_base->GCNANO.AQHIIDLE & GPU_IDLE_MASK ) != GPU_IDLE_MASK );
    gpu_base->MXGPU.CTL &= ~GFXSS_GPU_MXGPU_CTL_ENABLED_Msk;

    while ((_FLD2VAL(GFXSS_GPU_MXGPU_STATUS_CORE_RST, gpu_base->MXGPU.STATUS) != 1U) && ( timeout > 0u))
    {
        Cy_SysLib_DelayUs(CY_GFXSS_WAIT_1_UNIT);
        timeout--;
    }
    if(_FLD2VAL(GFXSS_GPU_MXGPU_STATUS_CORE_RST, gpu_base->MXGPU.STATUS) != 1U)
    {
        return CY_GFX_TIMEOUT;
    }
    context->gpu_context.enabled = false;
    return CY_GFX_SUCCESS;
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22GFXSS */
/* [] END OF FILE */

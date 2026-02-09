/***************************************************************************//**
* \file cy_graphics.h
* \version 1.0
*
* This file provides constants and parameter values for the APIs provided
* by Graphics Sub system.
*
********************************************************************************
* \copyright
* Copyright 2021 Cypress Semiconductor Corporation
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
*
*******************************************************************************/

/**
* \addtogroup group_graphics           GFXSS        (Graphics Sub System)
* \{
*
* The Graphics Sub System driver provides an application interface
* for configuring graphics IP.
*
* GFXSS features graphics rendering to memory and control of one display:
* - Vector Graphics and Blit Operations.
* - Rendering fill rate up to 200Mpix/s.
* - MIPI-DSI displays with DPI (pixel interface) or DBI Type B (bus interface).
* - GPIO displays with parallel or serial interface (DPI and all DBI types).
* - Display modes up to 1024 x 768 pixels @ 60 Hz (64 MHz) with 24-bit color resolution.
*
* Graphics Processing Unit (GPU):
* - Display list command processing.
* - 2D geometry processing with perspective correction and no depth coordinate (=2.5D).
* - Tessellation of line, quad and Bezier curve primitives.
* - Vector graphics rasterization for linear and curved paths.
* - Textured, solid and linear fill pattern.
* - 8 Porter Duff blending modes.
* - Various ARGB formats for textures and destination buffers (8, 16 or 32 bpp).
* - Color palette for textures (1, 2, 4 or 8 index bpp).
* - Chroma sub-sampled destination buffers (YUV 4:2:2 or 4:2:0 with 16 or 12 bpp).
*
* Display Controller (DC):
* - 3 display layers with transparency (alpha blending).
* - 2 layers with support for YUV up-sampling.
* - 1 layer with support for RLAD decompression.
* - Cursor overlay.
* - Gamma correction.
* - Color keying.
* - Spatial dithering.
* - Various ARGB formats (16 or 32 bpp).
* - Various YUV formats, packed and semi-planar (12 or 16 bpp).
* - Video Timing Generator for DPI displays.
* - Configuration and Frame Buffer update for DBI displays (DCS write only).
*
* MIPI-DSI Host Controller and D-PHY (MIPIDSI)
* - DPI-2 and and DBI-2 Type B displays.
* - Up to 2 data lanes, max 1.5 Gbps per lane.
* - PLL for high-speed mode clock generation.
* - Generic command interface (DCS and proprietary read & write).
* - Video Pattern generator.
* - Ultra-Low-Power mode with disabled PLL.
* - Tearing Effect interrupt for DBI displays.
* - Shutdown and Color Mode control for DPI displays.

* The functions and other declarations used in this driver are in cy_graphics.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* \section group_graphics_section_more_information More Information
*
* For more information on the Graphics subsystem, refer to the technical reference
* manual (TRM).
*
* \defgroup group_graphics_macros Macros
* \defgroup group_graphics_functions Functions
* \defgroup group_graphics_data_structures Data Structures
* \defgroup group_graphics_enums Enumerated Types
*/

#if !defined (CY_GRAPHICS_H)
#define CY_GRAPHICS_H

#include "cy_device.h"

#if defined (CY_IP_MXS22GFXSS)

#include "viv_dc_type.h"
#include "viv_dc_util.h"
#include "viv_dc_setting.h"
#include "cy_syspm.h"
#include "cy_mipidsi.h"
#include "cy_syslib.h"
#include "viv_dc_hardware.h"
#include "vg_lite.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_graphics_macros
* \{
*/

/** Graphics driver identifier */
#define CY_GRAPHICS_ID                                   (CY_PDL_DRV_ID(0x4DU))

/** Driver major version */
#define CY_GRAPHICS_DRV_VERSION_MAJOR                    1

/** Driver minor version */
#define CY_GRAPHICS_DRV_VERSION_MINOR                    0

/** DBI slice limit in bytes*/
#define DBI_SCLICE_LIMIT_IN_BYTES                        65536

/** Output pixel format in bytes*/
#define RGB_16_BIT_PIXEL_FORMAT_IN_BYTES                 2

/** Pixel format in bytes*/
#define RGB_32_BIT_PIXEL_FORMAT_IN_BYTES                 4

/** Pointer to dc core*/
#define DC_CORE                                          dcCore

/** Pointer to dc core*/
extern viv_dc_core* dcCore;

/** Interrupt status mask for CORE interrupt */
#define GFXSS_DC_INTR_CORE_MASK                         (0x00001)

/** Interrupt status mask for reading from ADDR0 completed */
#define GFXSS_DC_INTR_ADDR0_MASK                        (0x00100)

/** Interrupt status mask for reading from ADDR0 completed */
#define GFXSS_DC_INTR_ADDR1_MASK                        (0x00200)

/** Interrupt status mask for reading from ADDR0 completed */
#define GFXSS_DC_INTR_ADDR2_MASK                        (0x00400)

/** Interrupt status mask for reading from ADDR0 completed */
#define GFXSS_DC_INTR_ADDR3_MASK                        (0x00800)

/** Interrupt status mask for RLAD Decoder error */
#define GFXSS_DC_INTR_RLAD_ERROR_MASK                   (0x10000)

/**
* \defgroup group_graphics_macros_intrupter_macros Interrupt Mask
* \{
*/

/** Display0 interrupt*/
#define GFXSS_DC_DISP0_INT_MASK           GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_DISP0_Msk
/** Display0 DBI configure error*/
#define GFXSS_DC_DISP0_DBI_CFG_ERROR_MASK GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_Msk
/** Panel underflow intr*/
#define GFXSS_DC_PANEL_UNDERFLOW_MASK     GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_PANEL_UNDERFLOW_Msk
/** Soft reset done*/
#define GFXSS_DC_SOFT_RESET_DONE_MASK     GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_SOFT_RESET_DONE_Msk
/** Bus error*/
#define GFXSS_DC_BUS_ERROR_MASK           GFXSS_DC_DCNANO_GCREGDISPLAYINTRENABLE_GCREGDISPLAYINTRENABLE_BUS_ERROR_Msk

/** \} group_graphics_macros_intr_macros */

/** \} group_graphics_macros */

/*******************************************************************************
*       Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_graphics_enums
* \{
*/

/** Graphics API result */
typedef enum
{
   CY_GFX_SUCCESS,          /**< Success */
   CY_GFX_BAD_PARAM,        /**< Bad parameter */
   CY_GFX_TIMEOUT,          /**< Operation timeout */
} cy_en_gfx_status_t;

/** RLAD image format */
typedef enum
{
     CY_GFX_RLAD_FMT_ARGB4444,
     CY_GFX_RLAD_FMT_ARGB1555,
     CY_GFX_RLAD_FMT_RGB565,
     CY_GFX_RLAD_FMT_ARGB8888,
     CY_GFX_RLAD_FMT_RGB888,
     CY_GFX_RLAD_FMT_RGB666,
     CY_GFX_RLAD_FMT_RGB444,
     CY_GFX_RLAD_FMT_GRAY8,
     CY_GFX_RLAD_FMT_GRAY6,
     CY_GFX_RLAD_FMT_GRAY4
}cy_en_gfx_rlad_fmt_t;

/** RLAD decoder status */
typedef enum
{
     CY_GFX_RLAD_NORMAL_OPERATION,   /**< No fail state or Normal Operation. */
     CY_GFX_RLAD_AXI_ERROR,          /**< An AXI error response was received when reading compressed image data. */
     CY_GFX_RLAD_BUF_TOO_SMALL,      /**< The RLAD_SIZE setting is inconsistent with the compressed image data (image decompression not complete when end of buffer was reached). */
     CY_GFX_RLAD_BUF_TOO_LARGE,      /**< The RLAD_SIZE setting is inconsistent with the compressed image data (image decompression completed before end of buffer was reached). */
     CY_GFX_RLAD_DC_INVALID_SIZE,    /**< The DC was reading the first pixel of a frame when it was not expected. This means an inconsistent setup of RLAD and DC configuration. */
     CY_GFX_RLAD_DC_INVALID_FORMAT   /**< The DC was reading data with an unexpected burst length. This means an invalid buffer format was configured. */
}cy_en_gfx_rlad_status_t;

/** RLAD compression mode */
typedef enum
{
     CY_GFX_RLAD_MODE_RLAD,          /**< 'Run Length Adaptive Dithering' compression. It is a lossless image compression type. */
     CY_GFX_RLAD_MODE_RLAD_UNIFORM,  /**< 'Run Length Adaptive Dithering' compression with uniform bits per pixel. It is a lossless image compression type. */
     CY_GFX_RLAD_MODE_RLA,           /**< 'Run Length Adaptive' compression. It is a lossless image compression type. */
     CY_GFX_RLAD_MODE_RL             /**< 'Run length Encoded' compression. It is a lossless image compression type. */
}cy_en_gfx_rlad_comp_mode_t;

/** Layer type */
typedef enum {
    GFX_LAYER_GRAPHICS,
    GFX_LAYER_OVERLAY0,
    GFX_LAYER_OVERLAY1,
}cy_en_gfx_layer_type_t;

/** Display type */
typedef enum {
    GFX_DISP_TYPE_DPI,
    GFX_DISP_TYPE_DBI_A,
    GFX_DISP_TYPE_DBI_B,
    GFX_DISP_TYPE_DBI_C,
    GFX_DISP_TYPE_DSI_DBI,
    GFX_DISP_TYPE_DSI_DPI
}cy_en_gfx_display_type_t;

/** Display format type */
typedef enum {
    /* DPI */
    GFX_DPI_D24,
    GFX_DPI_D16CFG1,
    GFX_DPI_D16CFG2,
    GFX_DPI_D16CFG3,
    GFX_DPI_D18CFG1,
    GFXSS_DPI_D18CFG2,

     /* DBI */
    GFX_DBI_D8R3G3B2,
    GFX_DBI_D8R4G4B4,
    GFX_DBI_D8R5G6B5,
    GFX_DBI_D8R6G6B6,
    GFX_DBI_D8R8G8B8,
    GFX_DBI_D9R6G6B6,
    GFX_DBI_D16R3G3B2,
    GFX_DBI_D16R4G4B4,
    GFX_DBI_D16R5G6B5,
    GFX_DBI_D16R6G6B6OP1,
    GFX_DBI_D16R6G6B6OP2,
    GFX_DBI_D16R8G8B8OP1,
    GFX_DBI_D16R8G8B8OP2,
    GFX_DBI_D1R5G6B5,
    GFX_DBI_D1R8G8B8,
}cy_en_gfx_display_format_t;

/** Display buffer update type */
typedef enum
{
   GFX_SINGLE_BUFFER,
   GFX_DOUBLE_BUFFER,
   GFX_SPLIT_BUFFER,
} cy_en_gfx_disp_buffer_update_type_t;

/** \} group_graphics_enums */


/*******************************************************************************
*      Types definition
*******************************************************************************/

/**
* \addtogroup group_graphics_data_structures
* \{
*/

/** Cursor Configuration */
typedef struct {
    uint32_t *image_address;              /**< Cursor image address */
    uint8_t  hotspot_x;                   /**< Cursor hotspot x location */
    uint8_t  hotspot_y;                   /**< Cursor hotspot y location */
    uint16_t pos_x;                       /**< Cursor position x location */
    uint16_t pos_y;                       /**< Cursor position y location */
    uint32_t bgcolor;                     /**< Cursor background colour */
    uint32_t fgcolor;                     /**< Cursor foreground colour */
    bool     enable;                      /**<  Layer state */
}cy_stc_gfx_cursor_config_t;


/** RLAD configuration structure */
typedef struct
{
  cy_en_gfx_layer_type_t      layer_id;                  /**<  Layer ID*/
  uint32_t                    image_width;               /**<  Width of the image in number of pixels minus one. */
  uint32_t                    image_height;              /**<  Height of the image in number of pixels minus one */
  uint32_t                    compressed_image_size;     /**<  Size of the the encoded image in number of 32-bit words minus one. Defined in image header file.*/
  uint32_t                    *image_address;            /**<  Image address */
  cy_en_gfx_rlad_comp_mode_t  compression_mode;          /**<  RLAD compression mode */
  cy_en_gfx_rlad_fmt_t        rlad_format;               /**<  RLAD display format */
  bool                        enable;                    /**<  Layer state */
}cy_stc_gfx_rlad_cfg_t;

/** GPU configuration structure. Reserved for future use. */
typedef struct
{
    bool enable;   /**<  GPU  status */
}cy_stc_gfx_gpu_cfg_t;

/** GPU context */
typedef struct
{
    /** \cond INTERNAL */

    bool enabled;             /**< vglite initialization status */
    uint32_t ts_width;        /**< tessellation width */
    uint32_t ts_height;       /**< tessellation height */
    bool vg_lite_initialised; /**< vg_Lite initialisation status */

    /** \endcond */
}cy_stc_gfx_gpu_context_t;

/** Layer Configuration structure */
typedef struct {
    cy_en_gfx_layer_type_t  layer_type;            /**< Layer type */
    gctADDRESS              *buffer_address;       /**< Buffer */
    gctADDRESS              *uv_buffer_address;    /**< UV Buffer, this is not available for overlay 1 */
    viv_input_format_type   input_format_type;     /**< Input format, Overlay 1 supports only linear format while Graphics/Video Layer and Overlay 0 support both linear and tiled formats */
    viv_tiling_type         tiling_type;           /**< Tiliing format, Overlay 1 supports only vivLINEAR tiling type */
    viv_layer_alpha_mode    alpha_mode;            /**< Alpha mode */
    gctUINT32               pos_x;                 /**< Position X */
    gctUINT32               pos_y;                 /**< Position Y */
    gctUINT32               width;                 /**< Width */
    gctUINT32               height;                /**< Height */
    gctUINT8                zorder;                /**< Z Order */
    gctBOOL                 layer_enable;          /**< Layer status */
    gctBOOL                 visibility;            /**< Layer visibility */

 }cy_stc_gfx_layer_config_t;

/** Display controller Configuration */
typedef struct {
   cy_stc_gfx_layer_config_t       *gfx_layer_config;     /**< Graphics/Video Layer configuration */
   cy_stc_gfx_layer_config_t       *ovl0_layer_config;    /**< Overlay0 Layer configuration */
   cy_stc_gfx_layer_config_t       *ovl1_layer_config;    /**< Overlay1 Layer configuration */
   cy_stc_gfx_rlad_cfg_t           *rlad_config;          /**< RLAD configuration */
   cy_stc_gfx_cursor_config_t      *cursor_config;        /**< Cursor configuration */
   cy_en_gfx_display_type_t        display_type;          /**< Display type */
   viv_display_format_type         display_format;        /**< Display format */
   viv_display_size_type           display_size;          /**< Display size */
   uint32_t                        display_width;         /**< Display width */
   uint32_t                        display_height;        /**< Display height */
   /** Interrupt mask refer to \ref group_graphics_macros_intrupter_macros */
   uint32_t                        interrupt_mask;
} cy_stc_gfx_dc_config_t;

/** Display controller context */
typedef struct {
    /** \cond INTERNAL */

   cy_stc_gfx_layer_config_t       gfx_layer_config;     /**< Graphics/Video Layer configuration */
   cy_stc_gfx_layer_config_t       ovl0_layer_config;    /**< Overlay0 Layer configuration */
   cy_stc_gfx_layer_config_t       ovl1_layer_config;    /**< Overlay1 Layer configuration */
   cy_stc_gfx_rlad_cfg_t           rlad_config;          /**< RLAD configuration */
   cy_stc_gfx_cursor_config_t      cursor_config;        /**< Cursor configuration */
   cy_en_gfx_display_type_t        display_type;          /**< Display type */
   viv_display_format_type         display_format;        /**< Display format */
   viv_display_size_type           display_size;          /**< Display size */
   uint32_t                        display_width;         /**< Display width */
   uint32_t                        display_height;         /**< Display height */
   uint32_t                        interrupt_mask;        /**< Interrupt mask */

    /** \endcond */
}cy_stc_gfx_dc_context_t;

/** Graphics Block Configuration */
typedef struct {
    cy_stc_gfx_dc_config_t                   *dc_cfg;             /**< Display controller configuration */
    cy_stc_gfx_gpu_cfg_t                     *gpu_cfg;            /**< GPU configuration is optional */
    cy_stc_mipidsi_config_t                  *mipi_dsi_cfg;       /**< MIPI DSI configuration */
    cy_en_gfx_disp_buffer_update_type_t      display_update_type; /**< Single / Dual / Split */
    uint32_t clockHz;     /**< The frequency of the clock connected to the GFXSS block in Hz. */
}cy_stc_gfx_config_t;

 /** The Graphics internal context data. The user must not modify it. */
typedef struct
{
    /** \cond INTERNAL */

    cy_stc_mipidsi_context_t     mipidsi_context;     /**< MIPI DSI context */
    cy_stc_gfx_dc_context_t      dc_context;             /**< Display controller configuration */
    cy_stc_gfx_gpu_context_t     gpu_context;            /**< GPU configuration is optional */

    uint32_t clockHz;     /**< The frequency of the clock connected to the GFXSS block in Hz. */

    /** \endcond */
}cy_stc_gfx_context_t;
/** \} group_graphics_data_structures */


/*******************************************************************************
*    Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_graphics_functions
*  Following section describes the functions available in graphics subsystem.
*  For GPU specific functions,Please refer to <a href="vglite.pdf"> VGLite API Reference Manual </a>
*
*  Display controller functionality is taken care with high level graphics API implementation.
*  If user is looking for any specific functionality using direct display controller API directly,
*  please refer to <a href="dpu_api.pdf"> DPU API reference guide </a>
* \{
*/

/*******************************************************************************
* Function Name: Cy_GFXSS_Init
****************************************************************************//**
*
* Initializes graphics pipeline
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param config
* Pointer to the pin config structure base address.
*
* \param context
* context information used by the driver.
*
* \return
* Initialization status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Init(GFXSS_Type *base, cy_stc_gfx_config_t *config, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_SleepCallback
****************************************************************************//**
*
* Sleep callback implementation for graphics sub system.
*
* \param *callbackParams
*     A \ref cy_stc_syspm_callback_params_t structure with callback
*     parameters that consists of mode, base and context fields:
*    *base - a graphics register structure pointer.
*    *context - context for the call-back function.
*     mode
*     * CY_SYSPM_CHECK_READY - no action for this state.
*     * CY_SYSPM_CHECK_FAIL - no action for this state.
*     * CY_SYSPM_BEFORE_TRANSITION -
*     * CY_SYSPM_AFTER_TRANSITION -
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_SleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);

/*******************************************************************************
* Function Name: Cy_GFXSS_DeepSleepCallback
****************************************************************************//**
*
* Initializes graphics pipeline
*
* \param *callbackParams
*     A \ref cy_stc_syspm_callback_params_t structure with callback
*     parameters that consists of mode, base and context fields:
*    *base - a graphics register structure pointer.
*    *context - context for the call-back function.
*     mode
*     * CY_SYSPM_CHECK_READY - no action for this state.
*     * CY_SYSPM_CHECK_FAIL - no action for this state.
*     * CY_SYSPM_BEFORE_TRANSITION -
*     * CY_SYSPM_AFTER_TRANSITION -
*
* \param mode
* Callback mode, see \ref cy_en_syspm_callback_mode_t
*
* \return
* \ref cy_en_syspm_status_t
*
*******************************************************************************/
cy_en_syspm_status_t Cy_GFXSS_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode);

/*******************************************************************************
* Function Name: Cy_GFXSS_Interrupt
****************************************************************************//**
*
* The Interrupt Service Routine for the Graphics sub sytem.
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param context
* context information used by the driver.
*
*******************************************************************************/
void Cy_GFXSS_Interrupt(GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Clear_DC_Interrupt
****************************************************************************//**
*
* The Interrupt Service Routine to clear Display Controller interrupts
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param context
* context information used by the driver.
*
*******************************************************************************/
void Cy_GFXSS_Clear_DC_Interrupt(GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Clear_GPU_Interrupt
****************************************************************************//**
*
* The Interrupt Service Routine to clear GPU interrupts
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param context
* context information used by the driver.
*
*******************************************************************************/
void Cy_GFXSS_Clear_GPU_Interrupt(GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Get_DC_Interrupt_Status
****************************************************************************//**
*
* Gets Display Controller interrupt status.
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \return Returns a word with bits set at positions corresponding to the
* interrupts triggered in the display controller.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_GFXSS_Get_DC_Interrupt_Status(GFXSS_Type *base);

/*******************************************************************************
* Function Name: Cy_GFXSS_Get_GPU_Interrupt_Status
****************************************************************************//**
*
* Gets GPU interrupt status.
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \return Returns a word with bits set at positions corresponding to the
* interrupts triggered in the GPU.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Cy_GFXSS_Get_GPU_Interrupt_Status(GFXSS_Type *base);

/*******************************************************************************
* Function Name: Cy_GFXSS_Get_RLAD_Status
****************************************************************************//**
*
* Gets RLAD decoder status within Display Controller
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \return Returns \ref cy_en_gfx_rlad_status_t indicating decoder status.
*
*******************************************************************************/
__STATIC_INLINE cy_en_gfx_rlad_status_t Cy_GFXSS_Get_RLAD_Status(GFXSS_Type *base);

/*******************************************************************************
* Function Name: Cy_GFXSS_Set_FrameBuffer
****************************************************************************//**
*
* Sets Video/Graphics layer buffer address
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param gfx_layer_buffer
* Pointer to the frame buffer address to be used by Display Controller for transferring frame.
*
* \param context
* Pointer to the graphics config structure base address.
*
* \return
* CY_GFX_SUCCESS/CY_GFX_BAD_PARAM
*
* \note Framebuffer base address and stride for linear data should be
*       128-byte aligned.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Set_FrameBuffer(GFXSS_Type *base, uint32_t* gfx_layer_buffer, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Set_FrameBuffer_YUV
****************************************************************************//**
*
* Sets Video/Graphics layer YUV buffer addresses.
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param y_buffer
* Pointer to the Y buffer address to be used by Display Controller for transferring frame.
*
* \param uv_buffer
* Pointer to the UV buffer address to be used by Display Controller for transferring frame.
*
* \param context
* Pointer to the graphics config structure base address.
*
* \return
* CY_GFX_SUCCESS/CY_GFX_BAD_PARAM
*
* \note YUV Framebuffer base address and stride for linear data should be
*       64-byte aligned.
*       For YUY2_Packed Format uv_buffer can be set to NULL.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Set_FrameBuffer_YUV(GFXSS_Type *base, uint32_t* y_buffer, uint32_t* uv_buffer, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Get_FrameBufferAddress
****************************************************************************//**
*
* Gets the video/graphics layer buffer address used for transferring frame through Display Controller.
*
* \return
* frame buffer address.
*
*******************************************************************************/
uint32_t* Cy_GFXSS_Get_FrameBufferAddress(GFXSS_Type *base);

/*******************************************************************************
* Function Name: Cy_GFXSS_Set_Overlay0
****************************************************************************//**
*
* Sets Overlay0 buffer address
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param overlay0_buffer
* Pointer to the overlay0 buffer address to be used by Display Controller for transferring frame.
*
* \param context
* Pointer to the graphics config structure base address.
*
* \return
* CY_GFX_SUCCESS/CY_GFX_BAD_PARAM
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Set_Overlay0(GFXSS_Type *base, uint32_t* overlay0_buffer, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Set_Overlay0_YUV
****************************************************************************//**
*
* Sets Overlay0 YUV buffer addresses
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param y_buffer
* Pointer to the Y buffer address to be used by Display Controller for transferring frame.
*
* \param uv_buffer
* Pointer to the UV buffer address to be used by Display Controller for transferring frame.
*
* \param context
* Pointer to the graphics config structure base address.
*
* \return
* CY_GFX_SUCCESS/CY_GFX_BAD_PARAM
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Set_Overlay0_YUV(GFXSS_Type *base, uint32_t* y_buffer, uint32_t* uv_buffer, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Set_Overaly1
****************************************************************************//**
*
* Sets Overlay1 buffer address
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param overlay1_buffer
* Pointer to the overlay1 buffer address to be used by Display Controller for transferring frame.
*
* \param context
* Pointer to the graphics config structure base address.
*
* \return
* CY_GFX_SUCCESS/CY_GFX_BAD_PARAM
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Set_Overlay1(GFXSS_Type *base, uint32_t* overlay1_buffer, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Set_Layer_Enabled
****************************************************************************//**
*
* Enable/Disable the selected Layer
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param layer_id
* Layer type to be enabled/disabled.
*
* \param enable
* Enable/Disable visibility of the Layer
*
* \return
* SUCCESS/FAILURE.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Set_Layer_Enabled(GFXSS_Type *base, cy_en_gfx_layer_type_t  layer_id, bool enable);

/*******************************************************************************
* Function Name: Cy_GFXSS_DeInit
****************************************************************************//**
*
* DeInitializes graphics pipeline
*
* \param base
* Holds the base address of the Graphics block registers.
*
* \param context
* context information used by the driver.
*
* \return
* SUCCESS/FAILURE.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_DeInit(GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_RLAD_SetImage
****************************************************************************//**
*
* Set image configuration for RLAD.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param rlad_cfg
* Pointer to the RLAD configuration structure.
*
* \param context
* context information used by the driver.
*
* \return
* SUCESS/TIMEOUT status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_RLAD_SetImage(GFXSS_Type *base,  cy_stc_gfx_rlad_cfg_t *rlad_cfg, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_RLAD_Enable
****************************************************************************//**
*
* Enable RLAD in graphics pipeline.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param context
* context information used by the driver.
*
* \return
* SUCESS/FAILURE
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_RLAD_Enable( GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_RLAD_Disable
****************************************************************************//**
*
* Disable RLAD in graphics pipeline.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param context
* context information used by the driver.
*
* \return
* Initialization status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_RLAD_Disable( GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Enable_GPU
****************************************************************************//**
*
* Enable GPU for composition.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param context
* context information used by the driver.
*
* \return
* SUCESS/TIMEOUT status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Enable_GPU( GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Disable_GPU
****************************************************************************//**
*
* Disable GPU and let Display controller refresh display based on already composed buffer stored in frame buffer address.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param context
* context information used by the driver.
*
* \return
* SUCESS/TIMEOUT status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Disable_GPU( GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Transfer_Frame
****************************************************************************//**
*
* Transfer frame to display in DBI command mode.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param context
* context information used by the driver.
*
* \return
* SUCESS/TIMEOUT status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_Transfer_Frame( GFXSS_Type *base, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_TransferPartialFrame
****************************************************************************//**
*
* Transfer partial frame to display in DBI command mode.
*
* \param base
* Pointer to the graphics sub system base address.
*
* \param start_line_offset
* Start line offset from the top of the frame buffer, beginning of partial frame.
*
* \param end_line_offset
* End line offset from the top of the frame buffer, end of partial frame.
*
* \param context
* context information used by the driver.
*
* \return
* SUCESS/TIMEOUT status.
*
*******************************************************************************/
cy_en_gfx_status_t Cy_GFXSS_TransferPartialFrame(GFXSS_Type *base, uint32_t start_line_offset, uint32_t end_line_offset, cy_stc_gfx_context_t *context);

/*******************************************************************************
* Function Name: Cy_GFXSS_Enable_GPU_Interrupt
****************************************************************************//**
*
* Enables GPU interrupt.
*
* \param base
* Pointer to the graphics sub system base address.
*
*
*******************************************************************************/
__STATIC_INLINE void Cy_GFXSS_Enable_GPU_Interrupt(GFXSS_Type *base)
{
    base->GFXSS_GPU.MXGPU.INTR_MASK |= GFXSS_GPU_MXGPU_INTR_MASK_CORE_MASK_Msk;
}

/*******************************************************************************
* Function Name: Cy_GFXSS_Disable_GPU_Interrupt
****************************************************************************//**
*
* Disables GPU interrupt.
*
* \param base
* Pointer to the graphics sub system base address.
*
*******************************************************************************/
__STATIC_INLINE void Cy_GFXSS_Disable_GPU_Interrupt(GFXSS_Type *base)
{
    base->GFXSS_GPU.MXGPU.INTR_MASK &= ~GFXSS_GPU_MXGPU_INTR_MASK_CORE_MASK_Msk;
}

__STATIC_INLINE uint32_t Cy_GFXSS_Get_DC_Interrupt_Status(GFXSS_Type *base)
{
    return base->GFXSS_DC.MXDC.INTR;
}
__STATIC_INLINE uint32_t Cy_GFXSS_Get_GPU_Interrupt_Status(GFXSS_Type *base)
{
	return base->GFXSS_GPU.MXGPU.INTR;
}
__STATIC_INLINE cy_en_gfx_rlad_status_t Cy_GFXSS_Get_RLAD_Status(GFXSS_Type *base)
{
	return ((cy_en_gfx_rlad_status_t) _FLD2VAL(GFXSS_DC_MXDC_RLAD_STATUS_RLAD_FAILED, base->GFXSS_DC.MXDC.RLAD_STATUS));
}


/** \} group_graphics_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22GFXSS */

/** \} group_graphics */



#endif /* CY_GRAPHICS_H */

/* [] END OF FILE */

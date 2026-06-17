/***************************************************************************//**
* \file cy_mipidsi.h
* \version 1.0
*
* This file provides constants and parameter values for the APIs provided
* by MIPI DSI.
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
* \addtogroup group_mipidsi            MIPI DSI     (MIPI Display Serial Interface)
* \{
*
* MIPI DSI driver provides an application interface for configuring MIPI DSI IP Block.
*
* MIPI-DSI Host Controller and D-PHY (MIPIDSI) features
* - DPI-2 and and DBI-2 Type B displays.
* - Up to 2 data lanes, max 1.5 Gbps per lane.
* - PLL for high-speed mode clock generation.
* - Generic command interface (DCS and proprietary read & write).
* - Video Pattern generator.
* - Ultra-Low-Power mode with disabled PLL.
* - Tearing Effect interrupt for DBI displays.
* - Shutdown and Color Mode control for DPI displays.

* The functions and other declarations used in this driver are in cy_mipidsi.h.
* You can include cy_pdl.h to get access to all functions
* and declarations in the PDL.
*
* \section group_mipidsi_section_more_information More Information
*
* For more information on the MIPI DSI and Graphics subsystem, refer to the technical reference
* manual (TRM).
*
* \defgroup group_mipidsi_macros Macros
* \defgroup group_mipidsi_functions Functions
* \defgroup group_mipidsi_data_structures Data Structures
* \defgroup group_mipidsi_enums Enumerated Types
*/

#if !defined (CY_MIPIDSI_H)
#define CY_MIPIDSI_H

#include "cy_device.h"

#if defined (CY_IP_MXS22GFXSS)

#include "cy_syspm.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_mipidsi_macros
* \{
*/

/**
* \defgroup group_mipidsi_version_macros Version Macros
* \{
*/

/** Graphics driver identifier */
#define CY_MIPIDSI_ID                                   (CY_PDL_DRV_ID(0x4EU))

/** Driver major version */
#define CY_MIPIDSI_DRV_VERSION_MAJOR                    1

/** Driver minor version */
#define CY_MIPIDSI_DRV_VERSION_MINOR                    0

/** \} group_mipidsi_version_macros */

/**
* \defgroup group_mipidsi_mode_macros Mode Flags
* \{
*/

/** Video Mode Non Burst Sync Pulses */
#define VID_MODE_TYPE_NON_BURST_SYNC_PULSES                0x0UL
/** Video Mode Non Burst Sync Events */
#define VID_MODE_TYPE_NON_BURST_SYNC_EVENTS                0x1UL
/** Video Mode Burst */
#define VID_MODE_TYPE_BURST                                0x2UL
/** Video mode mask */
#define VID_MODE_TYPE_MASK                                 0x3

/** BIT definition */
#ifndef BIT
#define BIT(x)                                            (1UL << (x))
#endif

/** video mode */
#define MIPI_DSI_MODE_VIDEO        BIT(0)
/** video burst mode */
#define MIPI_DSI_MODE_VIDEO_BURST    BIT(1)
/** video pulse mode */
#define MIPI_DSI_MODE_VIDEO_SYNC_PULSE    BIT(2)
/** enable auto vertical count mode */
#define MIPI_DSI_MODE_VIDEO_AUTO_VERT    BIT(3)
/** enable hsync-end packets in vsync-pulse and v-porch area */
#define MIPI_DSI_MODE_VIDEO_HSE        BIT(4)
/** disable hfront-porch area */
#define MIPI_DSI_MODE_VIDEO_NO_HFP    BIT(5)
/** disable hback-porch area */
#define MIPI_DSI_MODE_VIDEO_NO_HBP    BIT(6)
/** disable hsync-active area */
#define MIPI_DSI_MODE_VIDEO_NO_HSA    BIT(7)
/** flush display FIFO on vsync pulse */
#define MIPI_DSI_MODE_VSYNC_FLUSH    BIT(8)
/** disable EoT packets in HS mode */
#define MIPI_DSI_MODE_NO_EOT_PACKET    BIT(9)
/** device supports non-continuous clock behavior (DSI spec 5.6.1) */
#define MIPI_DSI_CLOCK_NON_CONTINUOUS    BIT(10)
/** transmit data in low power */
#define MIPI_DSI_MODE_LPM        BIT(11)
/** Allow low power transmission during video transfer */
#define ENABLE_LOW_POWER        (0x3FUL << 8)
/** Enable command transmission only in Low Power mode */
#define ENABLE_LOW_POWER_CMD        BIT(15)

/** \} group_mipidsi_mode_macros */

/**
* \defgroup group_mipidsi_display_polarity_macros Display Parameter Flags
* \{
*/
/** Display parameter polarity flags - Positive HSYNC */
#define DISPLAY_PARAMS_FLAG_PHSYNC            (1U<<0)
/** Display parameter polarity flags - Negative HSYNC */
#define DISPLAY_PARAMS_FLAG_NHSYNC            (1U<<1)
/** Display parameter polarity flags - Positive VSYNC */
#define DISPLAY_PARAMS_FLAG_PVSYNC            (1U<<2)
/** Display parameter polarity flags - Negative VSYNC */
#define DISPLAY_PARAMS_FLAG_NVSYNC            (1U<<3)
/** \} group_mipidsi_display_polarity_macros */

/**
* \defgroup group_mipidsi_intr_mask_macros Interrupt Mask Macros
* \{
*/

/** Interrupt from MIPI DSI CORE. */
#define MIPIDSI_CORE_INTERRUPT_MASK            (1U<<0)

/** Command transmission error occurred in DPI mode. */
#define MIPIDSI_DPI_HALT_INTERRUPT_MASK        (1U<<16)

/** Tearing Effect interrupt by display in DBI mode. */
#define MIPIDSI_DBI_TE_INTERRUPT_MASK          (1U<<8)

/** \} group_mipidsi_intr_mask_macros */

/** \} group_mipidsi_macros */

/*******************************************************************************
*       Enumerated Types
*******************************************************************************/

/**
* \addtogroup group_mipidsi_enums
* \{
*/

/** MIPI DSI API result */
typedef enum
{
   CY_MIPIDSI_SUCCESS,          /**< Success */
   CY_MIPIDSI_BAD_PARAM,        /**< Bad parameter */
   CY_MIPIDSI_TIMEOUT,          /**< Operation timeout */
} cy_en_mipidsi_status_t;

/** DPI/DBI interface pixel color format */
typedef enum
{
   CY_MIPIDSI_FMT_8BIT_8BPP,
   CY_MIPIDSI_FMT_8BIT_12BPP,
   CY_MIPIDSI_FMT_8BIT_16BPP,
   CY_MIPIDSI_FMT_8BIT_18BPP,
   CY_MIPIDSI_FMT_8BIT_24BPP,
   CY_MIPIDSI_FMT_9BIT_18BPP,
   CY_MIPIDSI_FMT_16BIT_8BPP,
   CY_MIPIDSI_FMT_16BIT_12BPP,
   CY_MIPIDSI_FMT_16BIT_16BPP,
   CY_MIPIDSI_FMT_16BIT_18BPP_OP1,
   CY_MIPIDSI_FMT_16BIT_18BPP_OP2,
   CY_MIPIDSI_FMT_16BIT_24BPP_OP1,
   CY_MIPIDSI_FMT_16BIT_24BPP_OP2,
   CY_MIPIDSI_FMT_RGB888,
   CY_MIPIDSI_FMT_RGB666,
   CY_MIPIDSI_FMT_RGB666_PACKED,
   CY_MIPIDSI_FMT_RGB565
} cy_en_mipidsi_pixel_format_t;

/** MIPI DSI Packet Type */
typedef enum {
    MIPI_DSI_V_SYNC_START = 0x01,
    MIPI_DSI_V_SYNC_END = 0x11,
    MIPI_DSI_H_SYNC_START = 0x21,
    MIPI_DSI_H_SYNC_END = 0x31,
    MIPI_DSI_COLOR_MODE_OFF = 0x02,
    MIPI_DSI_COLOR_MODE_ON = 0x12,
    MIPI_DSI_SHUTDOWN_PERIPHERAL = 0x22,
    MIPI_DSI_TURN_ON_PERIPHERAL = 0x32,
    MIPI_DSI_GENERIC_SHORT_WRITE_0_PARAM = 0x03,
    MIPI_DSI_GENERIC_SHORT_WRITE_1_PARAM = 0x13,
    MIPI_DSI_GENERIC_SHORT_WRITE_2_PARAM = 0x23,
    MIPI_DSI_GENERIC_READ_REQUEST_0_PARAM = 0x04,
    MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM = 0x14,
    MIPI_DSI_GENERIC_READ_REQUEST_2_PARAM = 0x24,
    MIPI_DSI_DCS_SHORT_WRITE = 0x05,
    MIPI_DSI_DCS_SHORT_WRITE_PARAM = 0x15,
    MIPI_DSI_DCS_READ = 0x06,
    MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE = 0x37,
    MIPI_DSI_END_OF_TRANSMISSION = 0x08,
    MIPI_DSI_NULL_PACKET = 0x09,
    MIPI_DSI_BLANKING_PACKET = 0x19,
    MIPI_DSI_GENERIC_LONG_WRITE = 0x29,
    MIPI_DSI_DCS_LONG_WRITE = 0x39,
    MIPI_DSI_LOOSELY_PACKED_PIXEL_STREAM_YCBCR20 = 0x0c,
    MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR24 = 0x1c,
    MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR16 = 0x2c,
    MIPI_DSI_PACKED_PIXEL_STREAM_30 = 0x0d,
    MIPI_DSI_PACKED_PIXEL_STREAM_36 = 0x1d,
    MIPI_DSI_PACKED_PIXEL_STREAM_YCBCR12 = 0x3d,
    MIPI_DSI_PACKED_PIXEL_STREAM_16 = 0x0e,
    MIPI_DSI_PACKED_PIXEL_STREAM_18 = 0x1e,
    MIPI_DSI_PIXEL_STREAM_3BYTE_18 = 0x2e,
    MIPI_DSI_PACKED_PIXEL_STREAM_24 = 0x3e
}cy_en_mipidsi_packet_type_t;

/** MIPI DCS commands */
typedef enum {
    MIPI_DCS_NOP            = 0x00,
    MIPI_DCS_SOFT_RESET        = 0x01,
    MIPI_DCS_GET_COMPRESSION_MODE    = 0x03,
    MIPI_DCS_GET_DISPLAY_ID        = 0x04,
    MIPI_DCS_GET_ERROR_COUNT_ON_DSI    = 0x05,
    MIPI_DCS_GET_RED_CHANNEL    = 0x06,
    MIPI_DCS_GET_GREEN_CHANNEL    = 0x07,
    MIPI_DCS_GET_BLUE_CHANNEL    = 0x08,
    MIPI_DCS_GET_DISPLAY_STATUS    = 0x09,
    MIPI_DCS_GET_POWER_MODE        = 0x0A,
    MIPI_DCS_GET_ADDRESS_MODE    = 0x0B,
    MIPI_DCS_GET_PIXEL_FORMAT    = 0x0C,
    MIPI_DCS_GET_DISPLAY_MODE    = 0x0D,
    MIPI_DCS_GET_SIGNAL_MODE    = 0x0E,
    MIPI_DCS_GET_DIAGNOSTIC_RESULT    = 0x0F,
    MIPI_DCS_ENTER_SLEEP_MODE    = 0x10,
    MIPI_DCS_EXIT_SLEEP_MODE    = 0x11,
    MIPI_DCS_ENTER_PARTIAL_MODE    = 0x12,
    MIPI_DCS_ENTER_NORMAL_MODE    = 0x13,
    MIPI_DCS_GET_IMAGE_CHECKSUM_RGB    = 0x14,
    MIPI_DCS_GET_IMAGE_CHECKSUM_CT    = 0x15,
    MIPI_DCS_EXIT_INVERT_MODE    = 0x20,
    MIPI_DCS_ENTER_INVERT_MODE    = 0x21,
    MIPI_DCS_SET_GAMMA_CURVE    = 0x26,
    MIPI_DCS_SET_DISPLAY_OFF    = 0x28,
    MIPI_DCS_SET_DISPLAY_ON        = 0x29,
    MIPI_DCS_SET_COLUMN_ADDRESS    = 0x2A,
    MIPI_DCS_SET_PAGE_ADDRESS    = 0x2B,
    MIPI_DCS_WRITE_MEMORY_START    = 0x2C,
    MIPI_DCS_WRITE_LUT        = 0x2D,
    MIPI_DCS_READ_MEMORY_START    = 0x2E,
    MIPI_DCS_SET_PARTIAL_ROWS    = 0x30,        /* MIPI DCS 1.02 - MIPI_DCS_SET_PARTIAL_AREA before that */
    MIPI_DCS_SET_PARTIAL_COLUMNS    = 0x31,
    MIPI_DCS_SET_SCROLL_AREA    = 0x33,
    MIPI_DCS_SET_TEAR_OFF        = 0x34,
    MIPI_DCS_SET_TEAR_ON        = 0x35,
    MIPI_DCS_SET_ADDRESS_MODE    = 0x36,
    MIPI_DCS_SET_SCROLL_START    = 0x37,
    MIPI_DCS_EXIT_IDLE_MODE        = 0x38,
    MIPI_DCS_ENTER_IDLE_MODE    = 0x39,
    MIPI_DCS_SET_PIXEL_FORMAT    = 0x3A,
    MIPI_DCS_WRITE_MEMORY_CONTINUE    = 0x3C,
    MIPI_DCS_SET_3D_CONTROL        = 0x3D,
    MIPI_DCS_READ_MEMORY_CONTINUE    = 0x3E,
    MIPI_DCS_GET_3D_CONTROL        = 0x3F,
    MIPI_DCS_SET_VSYNC_TIMING    = 0x40,
    MIPI_DCS_SET_TEAR_SCANLINE    = 0x44,
    MIPI_DCS_GET_SCANLINE        = 0x45,
    MIPI_DCS_SET_DISPLAY_BRIGHTNESS = 0x51,        /* MIPI DCS 1.3 */
    MIPI_DCS_GET_DISPLAY_BRIGHTNESS = 0x52,        /* MIPI DCS 1.3 */
    MIPI_DCS_WRITE_CONTROL_DISPLAY  = 0x53,        /* MIPI DCS 1.3 */
    MIPI_DCS_GET_CONTROL_DISPLAY    = 0x54,        /* MIPI DCS 1.3 */
    MIPI_DCS_WRITE_POWER_SAVE    = 0x55,        /* MIPI DCS 1.3 */
    MIPI_DCS_GET_POWER_SAVE        = 0x56,        /* MIPI DCS 1.3 */
    MIPI_DCS_SET_CABC_MIN_BRIGHTNESS = 0x5E,    /* MIPI DCS 1.3 */
    MIPI_DCS_GET_CABC_MIN_BRIGHTNESS = 0x5F,    /* MIPI DCS 1.3 */
    MIPI_DCS_READ_DDB_START        = 0xA1,
    MIPI_DCS_READ_PPS_START        = 0xA2,
    MIPI_DCS_READ_DDB_CONTINUE    = 0xA8,
    MIPI_DCS_READ_PPS_CONTINUE    = 0xA9,
}cy_en_mipidsi_dcs_cmd_type_t;

/** MIPI DSI mode of operation */
typedef enum  {
    DSI_VIDEO_MODE,
    DSI_COMMAND_MODE
}cy_en_mipidsi_mode_t;

/** MIPI DSI transfer mode */
typedef enum  {
    DSI_LP_MODE,
    DSI_HS_MODE
}cy_en_mipi_dsi_transfer_mode;


/** \} group_mipidsi_enums */


/*******************************************************************************
*      Types definition
*******************************************************************************/

/**
* \addtogroup group_mipidsi_data_structures
* \{
*/

/** MIPI DSI Display params. */
typedef struct
{
    uint32_t pixel_clock;     /**< Pixel clock in kHz */
    uint16_t hdisplay;        /**< Display size in horizontal direction */
    uint16_t hsync_width;     /**< Hsync Width */
    uint16_t hfp;             /**< Hsync end position */
    uint16_t hbp;             /**< Horizontal Total */
    uint16_t vdisplay;        /**< Display size in vertical direction */
    uint16_t vsync_width;     /**< VSync Width */
    uint16_t vfp;             /**< Vertical Front Porch */
    uint16_t vbp;             /**< Vertical Back Porch */
    uint32_t polarity_flags;  /**< Polarity flags */
}cy_stc_mipidsi_display_params_t;

/** MIPI DSI Block Configuration */
typedef struct {
    uint32_t                          virtual_ch;             /**< Display controller configuration */
    uint32_t                          num_of_lanes;           /**< GPU configuration is optional */
    uint32_t                          per_lane_mbps;          /**< per lane speed in mbps */
    cy_en_mipidsi_pixel_format_t      dpi_fmt;                /**< MIPI DSI configuration */
    uint32_t                          max_phy_clk;            /**< device max DPHY clock in MHz unit */
    cy_en_mipidsi_mode_t              dsi_mode;               /**< Command mode/Video mode */
    uint32_t                          mode_flags;             /**< Additional mode information */
    cy_stc_mipidsi_display_params_t   *display_params;        /**< Display parameters */
}cy_stc_mipidsi_config_t;

/** MIPI DSI internal context data. The user must not modify it. */
typedef struct
{
    /** \cond INTERNAL */

    uint32_t                          virtual_ch;             /**< Display controller configuration */
    uint32_t                          num_of_lanes;           /**< GPU configuration is optional */
    uint32_t                          per_lane_mbps;          /**< per lane speed in mbps */
    cy_en_mipidsi_pixel_format_t      dpi_fmt;                /**< MIPI DSI configuration */
    uint32_t                          max_phy_clk;            /**< device max DPHY clock in MHz unit */
    cy_en_mipidsi_mode_t              dsi_mode;               /**< Command mode/Video mode */
    uint32_t                          mode_flags;             /**< Additional mode information */
    cy_stc_mipidsi_display_params_t   display_params;         /**< Display parameters */
    bool                              enable;                  /**< Dsi enable state*/

    /** \endcond */
}cy_stc_mipidsi_context_t;

/** \} group_mipidsi_data_structures */


/*******************************************************************************
*    Function Prototypes
*******************************************************************************/
/**
* \addtogroup group_mipidsi_functions
* \{
*/

/*******************************************************************************
* Function Name: Cy_MIPIDSI_Init
****************************************************************************//**
*
* Initializes MIPI DSI IP Block.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \param config
* Pointer to the configuration structure.
*
* \param context
* context information used by the driver.
*
* \return
* Initialization status.
*
*******************************************************************************/
cy_en_mipidsi_status_t  Cy_MIPIDSI_Init(GFXSS_MIPIDSI_Type *base, cy_stc_mipidsi_config_t const *config, cy_stc_mipidsi_context_t *context);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_Enable
****************************************************************************//**
*
* Enables MIPI DSI IP Block.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
*******************************************************************************/
void Cy_MIPIDSI_Enable(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_Disable
****************************************************************************//**
*
* Disable MIPI DSI IP Block.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
*******************************************************************************/
void Cy_MIPIDSI_Disable(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_DeInit
****************************************************************************//**
*
* DeInitializes MIPI DSI IP Block resources.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
*******************************************************************************/
void Cy_MIPIDSI_DeInit(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_SetInterruptMask
****************************************************************************//**
*
* Set interrupt mask for MIPI DSI Block
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \param interrupt_mask
* interrupt mask containing the list of interrupts to be notified.
*
* See \ref group_mipidsi_intr_mask_macros for the set of constants.
*******************************************************************************/
void  Cy_MIPIDSI_SetInterruptMask(GFXSS_MIPIDSI_Type *base, uint32_t interrupt_mask);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_GetInterruptMask
****************************************************************************//**
*
* Get MIPI DSI Block interrupt mask
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* interrupt mask.
*
* See \ref group_mipidsi_intr_mask_macros for the set of constants.
*******************************************************************************/
uint32_t  Cy_MIPIDSI_GetInterruptMask(GFXSS_MIPIDSI_Type const *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_GetInterruptStatusMasked
****************************************************************************//**
*
* Get interrupt status
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* interrupt status
*
* See \ref group_mipidsi_intr_mask_macros for the set of constants.
*******************************************************************************/
uint32_t  Cy_MIPIDSI_GetInterruptStatusMasked(GFXSS_MIPIDSI_Type const *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_WritePacket
****************************************************************************//**
*
* Writes DCS packet on DSI interface.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \param buf
* buffer containing the packet.
*
* \param length
* length of the packet.
*
* \return
* packet write status.
*
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_WritePacket(GFXSS_MIPIDSI_Type *base, const uint8_t *buf, uint32_t length);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_GenericWritePacket
****************************************************************************//**
*
* Writes Generic packet on DSI interface.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \param buf
* buffer containing the packet.
*
* \param length
* length of the packet.
*
* \return
* packet write status.
*
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_GenericWritePacket(GFXSS_MIPIDSI_Type *base, const uint8_t *buf, uint32_t length);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_ReadPacket
****************************************************************************//**
*
* Read packet from DSI
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \param packet_type
* Packet type either short or long packet.
*
* \param buf
* pointer to the output buffer read from the interface.
*
* \param length
* length of the packet.
*
* \return
* packet read status.
*
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_ReadPacket(GFXSS_MIPIDSI_Type *base, cy_en_mipidsi_packet_type_t packet_type, uint32_t *buf, uint32_t length);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_EnterSleep
****************************************************************************//**
*
* Sends MIPI DSI DCS Command MIPI_DCS_ENTER_SLEEP_MODE.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Command transfer status.
*
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_EnterSleep(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_ExitSleep
****************************************************************************//**
*
* Sends MIPI DSI DCS Command MIPI_DCS_EXIT_SLEEP_MODE.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Command transfer status.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_ExitSleep(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_SoftReset
****************************************************************************//**
*
* Sends MIPI DSI DCS Command MIPI_DCS_SOFT_RESET.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Command transfer status.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_SoftReset(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_DisplayON
****************************************************************************//**
*
* Sends MIPI DSI DCS Command MIPI_DCS_SET_DISPLAY_ON.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Command transfer status.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_DisplayON(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_DisplayOFF
****************************************************************************//**
*
* Sends MIPI DSI DCS Command MIPI_DCS_SET_DISPLAY_OFF.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Command transfer status.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_DisplayOFF(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_EnterULPM
****************************************************************************//**
*
* Enter Ultra Low Power Mode for both clock and data lines
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Status of the operation.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_EnterULPM(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_ExitULPM
****************************************************************************//**
*
* Exit Ultra Low Power Mode for both clock and data lines
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Status of the operation.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_ExitULPM(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_EnterULPM_Data
****************************************************************************//**
*
* Enter Ultra Low Power Mode for data lines
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Status of the operation.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_EnterULPM_Data(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_ExitULPM_Data
****************************************************************************//**
*
* Exit Ultra Low Power Mode for data lines
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \return
* Status of the operation.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_ExitULPM_Data(GFXSS_MIPIDSI_Type *base);

/*******************************************************************************
* Function Name: Cy_MIPIDSI_CMD_MODE_DCS_SetLowPower(GFXSS_MIPIDSI_Type *base, bool enable)
****************************************************************************//**
*
* Enable Low Power transfer of DCS packets for CMD mode displays.
*
* \param base
* Pointer to the MIPI DSI register base address.
*
* \param enable
* Enable/Disable Low Power transfer of DCS packets for CMD mode displays.
*
* \return
* Status of the operation.
*
* \note Default configuration for Command mode displays is set to send command \n
*  mode data in HS mode. Some panels do not support HS mode for panel commands, \n
* in that case this function can be used to enable Low Power transfer of DCS \n
* packets.
*******************************************************************************/
cy_en_mipidsi_status_t Cy_MIPIDSI_CMD_MODE_DCS_SetLowPower(GFXSS_MIPIDSI_Type *base, bool enable);

/** \} group_mipidsi_functions */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22MIPI DSI */

#endif /* CY_GRAPHICS_H */

/** \} group_mipidsi */

/* [] END OF FILE */

/***************************************************************************//**
* \file mtb_hal_hw_types_memoryspi_smif.h
*
*********************************************************************************
* \copyright
* Copyright(c) 2024-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
*
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

#pragma once

#include "cy_pdl.h"

#if defined(CY_IP_MXSMIF)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)
/** Macro specifying whether the MemorySPI driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)

/** \} group_hal_availability */


/**
 * @brief MemorySPI object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    SMIF_Type*                          base; //!< Base address for the SMIF
    cy_en_smif_slave_select_t           chip_select; //!< Active chip select */
    uint32_t                            configured_csel; //!< All configured chip selects */
    uint32_t                            instNumber; //!< SMIF instance number
    cy_stc_smif_context_t*              context;    //!< SMIF context for PDL use
    uint32_t                            enabled_events; //!< Events enabled by the user
    _mtb_hal_event_callback_data_t      callback_data;  //!< Registered callback, if any
    const mtb_hal_clock_t*              clock;          //!< Associated clock instance
} mtb_hal_memoryspi_t;

/**
 * @brief MemorySPI configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    SMIF_Type*                              base; //!< Base address for the SMIF
    const cy_stc_smif_config_t*             config; //!< PDL-level SMIF configuration
    uint32_t                                instNumber; //!< SMIF instance number
    cy_stc_smif_context_t                   context; //!< SMIF context for PDL use
    const mtb_hal_clock_t*                  clock;   //!< Default clock to use
    bool                                    csel[4]; //!< Used stus of each chip select
    /** Bit representation of currently not supported interrupts:
        Bit 5 : Memory Mode Alignment Error
        Bit 4 : RX Data FIFO Underflow
        Bit 3 : TX Command FIFO Overflow
        Bit 2 : TX Data FIFO Overflow
        Bit 1 : RX FIFO Level Trigger
        Bit 0 : TX FIFO Level Trigger
     */
    uint8_t                                 irqs;
    /** Bit representation of DMA triggers activation indicators:
        Bit 1 : RX Trigger Output activated in configurator
        Bit 0 : TX Trigger Output activated in configurator
     */
    uint8_t                                 dmas;
} mtb_hal_memoryspi_configurator_t;

#endif // defined(CY_IP_MXSMIF)

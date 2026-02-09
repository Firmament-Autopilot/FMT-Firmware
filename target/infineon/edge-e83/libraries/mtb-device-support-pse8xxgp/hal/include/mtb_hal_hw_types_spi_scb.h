/***************************************************************************//**
* \file mtb_hal_hw_types_spi_scb.h
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
#include "mtb_hal_hw_types_clock.h"

/* Older IP versions don't define SCB_SPI; it is always present */
#if (defined(CY_IP_MXSCB) || defined(CY_IP_MXS22SCB)) && (!defined(SCB_SPI) || (SCB_SPI))

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_SPI)
/** Macro specifying whether the SPI driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_SPI (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_SPI)

/** \} group_hal_availability */


/** SPI HAL to PDL enum map to enable/disable/report interrupt cause flags. */
#define MTB_HAL_MAP_SPI_IRQ_DATA_IN_FIFO                      (CY_SCB_SPI_TRANSFER_IN_FIFO_EVENT)
#define MTB_HAL_MAP_SPI_IRQ_DONE                              (CY_SCB_SPI_TRANSFER_CMPLT_EVENT)
#define MTB_HAL_MAP_SPI_IRQ_ERROR                             (CY_SCB_SPI_TRANSFER_ERR_EVENT)

/**
 * @brief SPI object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    CySCB_Type*                         base;//!< Base address for the SCB
    const mtb_hal_clock_t*              clock;//!< Clock interface
    cy_stc_scb_spi_context_t*           context;//!< PDL context
    uint16_t volatile                   pending; //!< Flags for pending operations
    bool                                is_target; //!< Configured as target
    uint8_t                             data_bits; //!< Width of data bus
    uint32_t                            irq_cause; //!< User-enabled events
    uint8_t                             write_fill; //!< Placeholder value when reading more than
                                                    //!< writing
    void* rx_buffer; //!< Buffer for read operations
    uint32_t                            rx_buffer_size; //!< Size of read buffer
    const void* tx_buffer; //!< Buffer for write operations
    uint32_t                            tx_buffer_size; //!< Size of write buffer
    bool                                is_async; //!< Is an async operation in progress
    _mtb_hal_event_callback_data_t      callback_data; //!< User-registered callback
} mtb_hal_spi_t;

/**
 * @brief SPI configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    CySCB_Type*                             base; //!< Base address for the SCB
    const mtb_hal_clock_t*                  clock; //!< Default clock object
    const cy_stc_scb_spi_config_t*          config; //!< PDL-level configuration structure
} mtb_hal_spi_configurator_t;

#endif // defined(CY_IP_MXSCB) || defined(CY_IP_MXS22SCB)

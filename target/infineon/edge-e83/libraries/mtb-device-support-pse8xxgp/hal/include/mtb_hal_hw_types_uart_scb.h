/***************************************************************************//**
* \file mtb_hal_hw_types_uart_scb.h
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
#include "mtb_hal_impl_types.h"

/* Older IP versions don't define SCB_UART; it is always present */
#if (defined(CY_IP_MXSCB) || defined(CY_IP_MXS22SCB)) && (!defined(SCB_UART) || (SCB_UART))

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_UART)
/** Macro specifying whether the UART driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_UART (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_UART)

/** \} group_hal_availability */


/** UART HAL to PDL enum map to enable/disable/report interrupt cause flags. */
#define MTB_HAL_MAP_UART_IRQ_TX_TRANSMIT_IN_FIFO              (CY_SCB_UART_TRANSMIT_IN_FIFO_EVENT)
#define MTB_HAL_MAP_UART_IRQ_TX_DONE                          (CY_SCB_UART_TRANSMIT_DONE_EVENT)
#define MTB_HAL_MAP_UART_IRQ_RX_DONE                          (CY_SCB_UART_RECEIVE_DONE_EVENT)
#define MTB_HAL_MAP_UART_IRQ_RX_FULL                          (CY_SCB_UART_RB_FULL_EVENT)
#define MTB_HAL_MAP_UART_IRQ_RX_ERROR                         (CY_SCB_UART_RECEIVE_ERR_EVENT)
#define MTB_HAL_MAP_UART_IRQ_TX_ERROR                         (CY_SCB_UART_TRANSMIT_ERR_EVENT)
#define MTB_HAL_MAP_UART_IRQ_RX_NOT_EMPTY                     (CY_SCB_UART_RECEIVE_NOT_EMTPY)
#define MTB_HAL_MAP_UART_IRQ_TX_EMPTY                         (CY_SCB_UART_TRANSMIT_EMTPY)
#define MTB_HAL_MAP_UART_IRQ_TX_FIFO                          (CY_SCB_UART_TRANSMIT_EMTPY << 1)
#define MTB_HAL_MAP_UART_IRQ_RX_FIFO                          (CY_SCB_UART_TRANSMIT_EMTPY << 2)

/**
 * @brief UART pin structure
 *
 * This is the pin structure that stores info about the pin configurations
 */
typedef struct
{
    GPIO_PRT_Type*  port;       /**< Port base address */
    uint8_t         pinNum;     /**< Pin number */
} _mtb_hal_uart_pin_t;

/**
 * @brief UART object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    CySCB_Type*                         base; //!< Base address for the SCB
    cy_stc_scb_uart_context_t*          context; //!< PDL context
    const mtb_hal_clock_t*              clock; //!< Clock interface
    _mtb_hal_event_callback_data_t      callback_data; //!< User-registered callback
    uint32_t                            irq_cause; //!< User-enabled events
    _mtb_hal_uart_pin_t                 tx_pin; //!< TX pin info
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    bool                                rts_enable; //!< Is the RTS pin connected to the SCB
    _mtb_hal_uart_pin_t                 rts_pin; //!< RTS pin info (if used)
    /** Function pointer to call during process_interrupts for handling async transfers */
    async_transfer_handler_t            async_handler;
    mtb_async_transfer_context_t*       async_ctx; //!< Context for async-transfer
    mtb_async_transfer_event_callback_t async_event_callback; //!< Callback registerd with
                                                              //!< async-transfer
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
} mtb_hal_uart_t;


/**
 * @brief UART configurator struct
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
    uint8_t                                 tx_port; //!< TX Pin port number
    uint8_t                                 tx_pin; //!< TX Pin number
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    /** Set if the Flow control is enabled and RTS is connected to a pin */
    bool                                    rts_enable;
    uint8_t                                 rts_port; //!< RTS Pin port number (if specified)
    uint8_t                                 rts_pin; //!< RTS Pin number (if specified)
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
} mtb_hal_uart_configurator_t;

#endif // defined(CY_IP_MXSCB) || defined(CY_IP_MXS22SCB)

/***************************************************************************//**
* \file mtb_syspm_callbacks_scb_uart.h
*
* Description:
* Provides a high level interface for syspm callbacks for the SCB UART IP.
*
********************************************************************************
* \copyright
* Copyright 2024-2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
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
#include "mtb_syspm_callbacks_hw_resources.h"

#if defined(COMPONENT_MW_ASYNC_TRANSFER)
#include "mtb_async_transfer.h"
#endif // defined(COMPONENT_MW_ASYNC_TRANSFER)

#if defined(__cplusplus)
extern "C" {
#endif

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');

/**
 * \addtogroup mtb_syspm_group_uart SCB UART Deep Sleep Callback
 * \{
 * Implementation of the SCB UART Deep Sleep callback
 */


/** This is the pin structure that stores the info about the pin configurations */
typedef struct
{
    GPIO_PRT_Type*  port;       /**< Port base address */
    uint32_t        pinNum;     /**< Pin number */
    en_hsiom_sel_t  hsiom;      /**< HSIOM setting*/
} mtb_syspm_callbacks_uart_pins;

/**Context Reference Structure for SCB UART peripheral */
typedef struct
{
    mtb_syspm_callbacks_uart_pins   tx_pin;         /**< TX pin info */
    mtb_syspm_callbacks_uart_pins   rts_pin;        /**< RTS pin info */
    cy_stc_scb_uart_context_t*      uart_context;   /**< Pointer to UART context structure */
    #if defined(COMPONENT_MW_ASYNC_TRANSFER)
    mtb_async_transfer_context_t*   async_context;  /**< Pointer to async context structure if
                                                       available*/
    #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
} mtb_syspm_uart_deepsleep_context_t;

/** Deepsleep callback for SCB UART IP
 *
 * @param[in] params    The param structure for the callback for which the context element should be
 * of type \ref mtb_syspm_uart_deepsleep_context_t
 * @param[in] mode      The callback mode
 * @return Returns CY_SYSPM_SUCCESS if successful, an error code otherwise
 */
cy_en_syspm_status_t mtb_syspm_scb_uart_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode);


#if defined(__cplusplus)
}
#endif

/** \} mtb_syspm_group_uart */
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');

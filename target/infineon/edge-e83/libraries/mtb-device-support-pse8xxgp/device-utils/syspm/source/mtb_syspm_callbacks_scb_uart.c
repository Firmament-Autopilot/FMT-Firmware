/***************************************************************************//**
* \file mtb_syspm_callbacks_scb_uart.c
*
* Description:
* Provides the implementation for syspm callbacks for the SCB UART IP.
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

#include "cy_pdl.h"
#include "cy_utils.h"
#include "mtb_syspm_callbacks_scb_uart.h"

void restore_pins(const mtb_syspm_uart_deepsleep_context_t* context);

//--------------------------------------------------------------------------------------------------
// restore_pins
//--------------------------------------------------------------------------------------------------
void restore_pins(const mtb_syspm_uart_deepsleep_context_t* context)
{
    if (NULL != context->tx_pin.port)
    {
        Cy_GPIO_SetHSIOM(context->tx_pin.port, context->tx_pin.pinNum, context->tx_pin.hsiom);
    }
    if (NULL != context->rts_pin.port)
    {
        Cy_GPIO_SetHSIOM(context->rts_pin.port, context->rts_pin.pinNum, context->rts_pin.hsiom);
    }
}


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Rule requires const attributes for inputs but signature for following APIs needs to match requested one in PDL');
//--------------------------------------------------------------------------------------------------
// mtb_syspm_scb_uart_deepsleep_callback
//--------------------------------------------------------------------------------------------------
cy_en_syspm_status_t mtb_syspm_scb_uart_deepsleep_callback(
    cy_stc_syspm_callback_params_t* params,
    cy_en_syspm_callback_mode_t mode)
{
    bool allow = false;
    mtb_syspm_uart_deepsleep_context_t* context =
        (mtb_syspm_uart_deepsleep_context_t*)(params->context);

    // The output pins need to be set to high before going to deepsleep.
    // Otherwise the UART on the other side would see incoming data as '0'.
    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
            /* Check whether the High-level API is not busy executing the transmit
             * or receive operation.
             */
            if ((0UL ==
                 (CY_SCB_UART_TRANSMIT_ACTIVE &
                  Cy_SCB_UART_GetTransmitStatus(params->base, context->uart_context))) &&
                (0UL ==
                 (CY_SCB_UART_RECEIVE_ACTIVE  &
                  Cy_SCB_UART_GetReceiveStatus(params->base, context->uart_context)))
                #if defined(COMPONENT_MW_ASYNC_TRANSFER)
                //Checks whether the async-transfer instance is available to start a write or
                // read, meaning one isn't in progress
                && ((context->async_context == NULL) ||
                    ((context->async_context != NULL) &&
                     (context->async_context->dest_addr == NULL) &&
                     (context->async_context->src_addr == NULL)))
                #endif // defined(COMPONENT_MW_ASYNC_TRANSFER)
                )

            {
                /* Not all interrupts are preserved across DeepSleep entry/exit. For example,
                 * TX_UART_DONE is not. So block DeepSleep entry if any of our interrupts are
                 * unmasked. It is safe to check at the SCB level rather than the NVIC because
                 * the HAL never unmasks an interrupt without registering a handler.
                 *
                 * Neither of the FIFOs are preserved, so also block DeepSleep if either of them
                 * has contents.
                 */
                uint32_t txMasked = Cy_SCB_GetTxInterruptStatusMasked(params->base);
                uint32_t rxMasked = Cy_SCB_GetRxInterruptStatusMasked(params->base);
                /* If all data elements are transmitted from the TX FIFO and
                 * shifter and the RX FIFO is empty: the UART is ready to enter
                 * Deep Sleep mode.
                 */

                if (Cy_SCB_UART_IsTxComplete(params->base)
                    && (0UL == Cy_SCB_UART_GetNumInRxFifo(params->base))
                    && (0UL == txMasked) && (0UL == rxMasked))
                {
                    /* Disable the UART. The transmitter stops driving the
                     * lines and the receiver stops receiving data until
                     * the UART is enabled.
                     * This happens when the device failed to enter Deep
                     * Sleep or it is awaken from Deep Sleep mode.
                     */

                    if (NULL != context->tx_pin.port)
                    {
                        context->tx_pin.hsiom = Cy_GPIO_GetHSIOM(context->tx_pin.port,
                                                                 context->tx_pin.pinNum);
                        Cy_GPIO_Set(context->tx_pin.port, context->tx_pin.pinNum);
                        Cy_GPIO_SetHSIOM(context->tx_pin.port, context->tx_pin.pinNum,
                                         HSIOM_SEL_GPIO);
                    }
                    if (NULL != context->rts_pin.port)
                    {
                        context->rts_pin.hsiom = Cy_GPIO_GetHSIOM(context->rts_pin.port,
                                                                  context->rts_pin.pinNum);
                        Cy_GPIO_Set(context->rts_pin.port, context->rts_pin.pinNum);
                        Cy_GPIO_SetHSIOM(context->rts_pin.port, context->rts_pin.pinNum,
                                         HSIOM_SEL_GPIO);
                    }
                    allow = true;
                }
            }

            break;

        case CY_SYSPM_BEFORE_TRANSITION:
            allow = true;
            Cy_SCB_UART_Disable(params->base, context->uart_context);
            break;

        case CY_SYSPM_CHECK_FAIL:
            allow = true;
            restore_pins(context);
            break;

        case CY_SYSPM_AFTER_TRANSITION:
            allow = true;
            restore_pins(context);
            Cy_SCB_UART_Enable(params->base);
            break;

        default:
            CY_ASSERT(false);
            break;
    }
    if (allow)
    {
        return CY_SYSPM_SUCCESS;
    }
    else
    {
        return CY_SYSPM_FAIL;
    }
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');

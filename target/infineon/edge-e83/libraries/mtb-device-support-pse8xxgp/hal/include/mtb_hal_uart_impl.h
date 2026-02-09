/***************************************************************************//**
* \file mtb_hal_uart_impl.h
*
* Description:
* Provides a high level interface for interacting with the Infineon UART. This is
* a wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "mtb_hal_uart.h"
#include "mtb_hal_system.h"
#if (defined(CY_IP_MXSCB) && (CY_IP_MXSCB_VERSION == 1))
#include "mtb_hal_uart_mxscb_v1.h"
#elif (defined(CY_IP_MXSCB) && (CY_IP_MXSCB_VERSION >= 2))
#include "mtb_hal_uart_common.h"
#elif (defined(CY_IP_MXS22SCB) && (CY_IP_MXS22SCB_VERSION == 1))
#include "mtb_hal_uart_common.h"
#else
#error "Unhandled version"
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/
/** Initialize the UART Object.
 *
 * \note The application is responsible for initializing HAL objects
 *
 * @param[out] obj           Pointer to a UART object. The caller must allocate
 *                           the memory for this object, but the init function will
 *                           initialize its contents.
 * @param[in] config         The configurator-generated HAL config structure for this
 *                           peripheral instance
 * @param[in]  context       Pointer to the UART context structure. This is the context
 *                           structure passed when doing the UART Driver HW Initialization
 * @param[in]  clock         The clock used by the UART peripheral. Application shall allocate
 *                           and enable the clock
 * @return The status of the init request
 */
cy_rslt_t mtb_hal_uart_setup(mtb_hal_uart_t* obj, const mtb_hal_uart_configurator_t* config,
                             cy_stc_scb_uart_context_t* context, const mtb_hal_clock_t* clock);

//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_uart_enable(mtb_hal_uart_t* obj, bool enable)
{
    enable ? Cy_SCB_UART_Enable(obj->base) : Cy_SCB_UART_Disable(obj->base, obj->context);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_uart_enable _mtb_hal_uart_enable

//--------------------------------------------------------------------------------------------------
// mtb_hal_uart_get_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t mtb_hal_uart_get_internal(mtb_hal_uart_t* obj, uint8_t* value,
                                                    uint32_t timeout)
{
    uint32_t read_value = Cy_SCB_UART_Get(obj->base);
    uint32_t timeoutTicks = timeout;
    while (read_value == CY_SCB_UART_RX_NO_DATA)
    {
        if (timeout != 0UL)
        {
            if (timeoutTicks > 0UL)
            {
                mtb_hal_system_delay_ms(1);
                timeoutTicks--;
            }
            else
            {
                return MTB_HAL_UART_RSLT_ERR_CSP_UART_GETC_TIMEOUT;
            }
        }
        read_value = Cy_SCB_UART_Get(obj->base);
    }
    *value = (uint8_t)read_value;
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_uart_get(obj, value, timeout) mtb_hal_uart_get_internal(obj, value, timeout)

//--------------------------------------------------------------------------------------------------
// mtb_hal_uart_put_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t mtb_hal_uart_put_internal(mtb_hal_uart_t* obj, uint32_t value)
{
    uint32_t count = 0;
    while (count == 0)
    {
        count = Cy_SCB_UART_Put(obj->base, value);
    }

    return CY_RSLT_SUCCESS;
}


#define mtb_hal_uart_put(obj, value) mtb_hal_uart_put_internal(obj, value)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_uart_write_string
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_uart_write_string(mtb_hal_uart_t* obj, const char* tx)
{
    Cy_SCB_UART_PutString(obj->base, tx);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_uart_write_string _mtb_hal_uart_write_string

#if defined(__cplusplus)
}
#endif /* __cplusplus */

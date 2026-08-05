/***************************************************************************//**
* \file mtb_hal_hw_types_timer_tcpwm.h
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

#if defined(CY_IP_MXTCPWM)
#include "mtb_hal_hw_types_tcpwm.h"
#include "mtb_hal_irq_impl.h"

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_TIMER)
/** Macro specifying whether the Timer driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_TIMER (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_TIMER)

/** \} group_hal_availability */


/** Timer HAL to PDL enum map for defining timer events */
#define MTB_HAL_MAP_TIMER_EVENT_NONE                          (CY_TCPWM_INT_NONE)
#define MTB_HAL_MAP_TIMER_EVENT_TERMINAL_COUNT                (CY_TCPWM_INT_ON_TC)
#define MTB_HAL_MAP_TIMER_EVENT_COMPARE_CC0                   (CY_TCPWM_INT_ON_CC0)
#define MTB_HAL_MAP_TIMER_EVENT_COMPARE_CC0_OR_TERMINAL_COUNT (CY_TCPWM_INT_ON_CC0_OR_TC)
#define MTB_HAL_MAP_TIMER_EVENT_COMPARE_CC1                   (CY_TCPWM_INT_ON_CC1)
#define MTB_HAL_MAP_TIMER_EVENT_ALL                           (CY_TCPWM_INT_ON_TC | \
    CY_TCPWM_INT_ON_CC0 | CY_TCPWM_INT_ON_CC0_OR_TC | CY_TCPWM_INT_ON_CC1)

/**
 * @brief Timer object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    mtb_hal_tcpwm_t                 tcpwm; //!< Shared TCPWM data structure
    _mtb_hal_event_callback_data_t  callback_data; //!< User-registered callback
    uint32_t                        callback_event;//!< Event requested
    #if (_MTB_HAL_IRQ_MUXING)
    /** Events that should be disabled the next time process_interrupts runs */
    uint32_t                        clear_intr_mask;
    #endif /* (_MTB_HAL_IRQ_MUXING) */
} mtb_hal_timer_t;

/**
 * @brief Timer configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    TCPWM_Type*             tcpwm_base; //!< Base address for the TCPWM
    uint32_t                tcpwm_cntnum;//!< Counter number within the TCPWM block
    const mtb_hal_clock_t*  clock; //!< Default clock to use
} mtb_hal_timer_configurator_t;

#endif // defined(CY_IP_MXTCPWM)

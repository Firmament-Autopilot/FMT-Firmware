/***************************************************************************//**
* \file mtb_hal_hw_types_pwm_tcpwm.h
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

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_PWM)
/** Macro specifying whether the PWM driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_PWM (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_PWM)

/** \} group_hal_availability */


/**
 * @brief PWM object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    mtb_hal_tcpwm_t                     tcpwm; //!< Common TCPWM data
    _mtb_hal_event_callback_data_t      callback_data;
    uint32_t                            callback_event;   //!< Event requested
} mtb_hal_pwm_t;

/**
 * @brief PWM configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    TCPWM_Type*             base;      //!< TCPWM base
    uint32_t                group;     //!< The resource group index
    uint32_t                cntnum;    //!< The resource counter index
    uint32_t                max_count; //!< The max count for the counter
    const mtb_hal_clock_t*  clock;     //!< The clock resource pointer
} mtb_hal_pwm_configurator_t;

#endif // defined(CY_IP_MXTCPWM)

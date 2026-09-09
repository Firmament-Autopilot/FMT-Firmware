/***************************************************************************//**
* \file mtb_hal_syspm_impl.h
*
* \brief
* Provides an interface for interacting with the Infineon power
* management and system clock configuration. This interface abstracts out the
* chip specific details. If any chip specific functionality is necessary, or
* performance is critical the low level functions can be used directly.
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

#if defined(__cplusplus)
extern "C" {
#endif

#if defined (CY_IP_MXS22SRSS)
#include "mtb_hal_syspm_mxs22srss.h"
#elif defined(CY_IP_MXS40SSRSS)
#include "mtb_hal_syspm_mxs40ssrss.h"
#elif defined(CY_IP_MXS40SRSS)
#include "mtb_hal_syspm_mxs40srss.h"
#else
#error "Unhandled SRSS version"
#endif

#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0)

/*******************************************************************************
*                   Public Function Prototypes
*******************************************************************************/

cy_rslt_t _mtb_hal_syspm_tickless_sleep_deepsleep(mtb_hal_lptimer_t* obj, uint32_t desired_ms,
                                                  uint32_t* actual_ms, bool deep_sleep);

void _mtb_hal_syspm_tickless_timer_presleep(mtb_hal_lptimer_t* obj, uint32_t desired_ms,
                                            uint32_t* initial_ticks);

void _mtb_hal_syspm_tickless_timer_postsleep(mtb_hal_lptimer_t* obj, uint32_t* initial_ticks,
                                             uint32_t* actual_ms);

/*******************************************************************************
*                   Defines
*******************************************************************************/

#define mtb_hal_syspm_tickless_deepsleep(obj, desired_ms, actual_ms) \
    _mtb_hal_syspm_tickless_sleep_deepsleep(obj, desired_ms, actual_ms, true)

#define mtb_hal_syspm_tickless_sleep(obj, desired_ms, actual_ms) \
    _mtb_hal_syspm_tickless_sleep_deepsleep(obj, desired_ms, actual_ms, false)

#endif /* (MTB_HAL_DRIVER_AVAILABLE_LPTIMER != 0) */

#define mtb_hal_syspm_sleep() Cy_SysPm_CpuEnterSleep(CY_SYSPM_WAIT_FOR_INTERRUPT)

#if defined(__cplusplus)
}
#endif

/***************************************************************************//**
* \file mtb_hal_syspm_mxs22srss.h
*
* \brief
* Provides an interface for interacting with the Infineon power
* management on MXS22SRSS devices
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
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
#include "mtb_hal_hw_types_syspm.h"

/**
 * \addtogroup group_hal_impl_syspm System Power Management
 * \ingroup group_hal_impl
 * \{
 * The Power Management has the following characteristics:<br>
 * \ref MTB_HAL_SYSPM_CB_SYSTEM_HIGH equates to the High Power mode<br>
 * \ref MTB_HAL_SYSPM_CB_SYSTEM_NORMAL equates to the Low Power mode<br>
 * \ref MTB_HAL_SYSPM_CB_SYSTEM_LOW equates to the Ultra Low Power mode
 * \} group_hal_impl_syspm
 */

#if defined(__cplusplus)
extern "C" {
#endif

#define _MTB_HAL_SYSPM_SUPPORTS_DS_MODES

#if defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) && \
    (CY_IP_MXS22SRSS_VERSION_MINOR >= 1)

#define _MTB_HAL_SYSPM_SUPPORTS_HIB_RAM_MODE

#endif

//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_get_pdl_dsmode
//--------------------------------------------------------------------------------------------------
static inline cy_en_syspm_deep_sleep_mode_t _mtb_hal_syspm_get_pdl_dsmode(void)
{
    #if (CY_CPU_CORTEX_M55)
    return Cy_SysPm_GetAppDeepSleepMode();
    #else
    return Cy_SysPm_GetSysDeepSleepMode();
    #endif
}


#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
extern cy_en_syspm_status_t _mtb_hal_syspm_handle_lptimer(cy_stc_syspm_callback_params_t* params,
                                                          cy_en_syspm_callback_mode_t mode);
extern cy_stc_syspm_callback_params_t _mtb_hal_syspm_cb_params_default;

//--------------------------------------------------------------------------------------------------
// _mtb_hal_syspm_ensure_cb_registered_dsram_lptimer
//--------------------------------------------------------------------------------------------------
static inline bool _mtb_hal_syspm_ensure_cb_registered_dsram_lptimer(void)
{
    static cy_stc_syspm_callback_t cb_deepsleep_ram =
    {
        .callback       = _mtb_hal_syspm_handle_lptimer,
        .type           = CY_SYSPM_DEEPSLEEP_RAM,
        // We need to start the LPTimer before transition and stop it after the transition
        .skipMode       = (CY_SYSPM_SKIP_CHECK_READY | CY_SYSPM_SKIP_CHECK_FAIL),
        .callbackParams = &_mtb_hal_syspm_cb_params_default,
        .prevItm        = NULL,
        .nextItm        = NULL,
        /* We want this to be the last to run before DeepSleep entry, so that the LPTimer
         * delay corresponds as closely as possible to the actual time asleep. This also
         * means this will be the first to run on wakeup, which is also what we want
         * so that we can accurately capture the time spent actually asleep for debugging
         */
        .order          = 255u,
    };

    return Cy_SysPm_RegisterCallback(&cb_deepsleep_ram);
}


#endif // (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
#if defined(__cplusplus)
}
#endif

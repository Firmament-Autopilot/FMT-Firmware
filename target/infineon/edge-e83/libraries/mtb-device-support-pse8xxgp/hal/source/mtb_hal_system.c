/***************************************************************************//**
* \file mtb_hal_system.c
*
* \brief
* Provides a high level interface for interacting with the Infineon power
* management and system clock configuration. This interface abstracts out the
* chip specific details. If any chip specific functionality is necessary, or
* performance is critical the low level functions can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "mtb_hal_system_impl.h"
#include "cy_syslib.h"

#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
#include "cyabs_rtos.h"
#endif

#if (MTB_HAL_DRIVER_AVAILABLE_SYSTEM)

#if defined(__cplusplus)
extern "C"
{
#endif


#if !defined(MTB_HAL_DISABLE_WEAK_FUNC_IMPL)
/* Overrides weak implemenation for Cy_SysLib_Rtos_Delay to provide a way
 * to call into a RTOS if so configured. This function is only available
 * in mtb-pdl-cat1 version 2.2.0 or later.
 */
void Cy_SysLib_Rtos_Delay(uint32_t milliseconds)
{
    cy_rslt_t result = mtb_hal_system_delay_ms(milliseconds);
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    CY_UNUSED_PARAMETER(result);
}


#endif // if !defined(MTB_HAL_DISABLE_WEAK_FUNC_IMPL)

//--------------------------------------------------------------------------------------------------
// mtb_hal_system_delay_ms
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_system_delay_ms(uint32_t milliseconds)
{
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    // The RTOS is configured to round down, while this API is intended to wait at least the
    // requested time. Add 1 to the requested time to make it behave the same.
    return cy_rtos_delay_milliseconds(milliseconds + 1);
    #else
    Cy_SysLib_Delay(milliseconds);
    return CY_RSLT_SUCCESS;
    #endif
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_system_get_reset_reason
//--------------------------------------------------------------------------------------------------
mtb_hal_reset_reason_t mtb_hal_system_get_reset_reason(void)
{
    uint32_t pdl_reason = Cy_SysLib_GetResetReason();

    return _mtb_hal_system_convert_reset_reason(pdl_reason);
}


#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_SYSTEM */

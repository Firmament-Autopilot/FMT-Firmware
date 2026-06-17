/***************************************************************************//**
* \file mtb_hal_system_impl.h
*
* \brief
* Provides a PSOC™ Specific interface for interacting with the Infineon power
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

#pragma once

#include "mtb_hal_system.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CY_IP_MXS40SRSS) || defined(CY_IP_S8SRSSLT) || defined(CY_IP_MXS28SRSS) || \
    defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SRSS)

#define mtb_hal_system_critical_section_enter()   Cy_SysLib_EnterCriticalSection()

#define mtb_hal_system_critical_section_exit(x)   Cy_SysLib_ExitCriticalSection(x)

#define mtb_hal_system_delay_us(microseconds)     Cy_SysLib_DelayUs(microseconds)

#if defined(BCM55500)
#define mtb_hal_system_reset_device()             btss_system_forceSystemReset()
#else
#define mtb_hal_system_reset_device()             __NVIC_SystemReset()
#endif // defined(BCM55500)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_system_convert_reset_reason
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE mtb_hal_reset_reason_t _mtb_hal_system_convert_reset_reason(uint32_t pdl_reason)
{
    //Use int type because cpp interprets result of |= as int. Cast explicitly before returning.
    uint32_t reason = 0;

    if (CY_SYSLIB_RESET_SOFT & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_SOFT;
    }
    if (CY_SYSLIB_RESET_HWWDT & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_WDT;
    }
    #if defined(CY_IP_S8SRSSLT)
    if (CY_SYSLIB_PROT_FAULT & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_PROTECTION;
    }
    #endif
    #if defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SRSS)
    if (CY_SYSLIB_RESET_ACT_FAULT & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_ACTIVE_FAULT;
    }
    if (CY_SYSLIB_RESET_DPSLP_FAULT & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_DEEPSLEEP_FAULT;
    }
    if (CY_SYSLIB_RESET_HIB_WAKEUP & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_HIB_WAKEUP;
    }
    if (CY_SYSLIB_RESET_CSV_LOSS_WAKEUP & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_SYS_CLK_ERR;
    }
    if (CY_SYSLIB_RESET_CSV_ERROR_WAKEUP & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_SYS_CLK_ERR;
    }
    if ((CY_SYSLIB_RESET_SWWDT0 | CY_SYSLIB_RESET_SWWDT1 | CY_SYSLIB_RESET_SWWDT2 |
         CY_SYSLIB_RESET_SWWDT3) & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_WDT;
    }
    #endif // if defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SRSS)
    #if defined(CY_SYSLIB_RESET_SOFT0) && defined(CY_SYSLIB_RESET_SOFT1) \
    && defined(CY_SYSLIB_RESET_SOFT2)
    if ((CY_SYSLIB_RESET_SOFT0 | CY_SYSLIB_RESET_SOFT1 | CY_SYSLIB_RESET_SOFT2) & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_SOFT;
    }
    #endif // if defined(CY_SYSLIB_RESET_SOFT0) && defined(CY_SYSLIB_RESET_SOFT1)
    //                                   && defined(CY_SYSLIB_RESET_SOFT2)
    #if (SRSS_WCOCSV_PRESENT != 0U)
    if (CY_SYSLIB_RESET_CSV_WCO_LOSS & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_WCO_ERR;
    }
    #endif
    #if (SRSS_MASK_HFCSV != 0U)
    if ((CY_SYSLIB_RESET_HFCLK_LOSS | CY_SYSLIB_RESET_HFCLK_ERR) & pdl_reason)
    {
        reason |= MTB_HAL_SYSTEM_RESET_SYS_CLK_ERR;
    }
    #endif

    #if defined(CY_IP_MXS40SSRSS)
    if ((reason == MTB_HAL_SYSTEM_RESET_NONE) && Cy_SysLib_IsDSRAMWarmBootEntry())
    {
        reason |= MTB_HAL_SYSTEM_RESET_WARMBOOT;
    }
    #endif

    return (mtb_hal_reset_reason_t)reason;
}


#else // if defined(CY_IP_MXS40SRSS) || defined(CY_IP_S8SRSSLT) || defined(CY_IP_MXS28SRSS) ||
// defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS22SRSS)
#error "Unhandled version"
#endif \
    /* defined(CY_IP_MXS40SRSS) || defined(CY_IP_S8SRSSLT) || defined(CY_IP_MXS28SRSS) ||
       defined(CY_IP_MXS40SSRSS) */

#if defined(__cplusplus)
}
#endif

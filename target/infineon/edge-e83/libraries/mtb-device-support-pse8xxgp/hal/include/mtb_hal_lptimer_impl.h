/***************************************************************************//**
* \file mtb_hal_lptimer_impl.h
*
* \brief
* Provides a high level interface for interacting with the Infineon Low-Power Timer.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company) or
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

//! IP-specific implementation header for LPTimer
#if defined(CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION >= 2) && defined(SRSS_NUM_WDT_A) && \
    (SRSS_NUM_WDT_A > 1)
#include "mtb_hal_lptimer_mxwdt.h"
#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0)
#include "mtb_hal_lptimer_mcwdt_b.h"
#elif defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) || \
    defined(CY_IP_MXS22SRSS)
#include "mtb_hal_lptimer_mcwdt.h"
#elif defined(CY_IP_M0S8WCO)
#include "mtb_hal_lptimer_m0s8wo.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/
#define _MTB_HAL_LPTIMER_ISR_CRITICAL_SECTION_MASK      (0x02)

/*******************************************************************************
*       Functions
*******************************************************************************/

#if defined(__cplusplus)
}
#endif

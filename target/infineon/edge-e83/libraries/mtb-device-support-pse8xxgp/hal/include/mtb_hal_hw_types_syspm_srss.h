/***************************************************************************//**
* \file mtb_hal_hw_types_syspm_srss.h
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

#if defined(CY_IP_MXS22SRSS) || defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_SYSPM)
/** Macro specifying whether the SysPm driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_SYSPM (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_SYSPM)

/** \} group_hal_availability */


/** \cond INTERNAL
 * The corresponding enum members are already documented in the public API header
 */
#define MTB_HAL_MAP_SYSPM_CHECK_READY              CY_SYSPM_CHECK_READY
#define MTB_HAL_MAP_SYSPM_CHECK_FAIL               CY_SYSPM_CHECK_FAIL
#define MTB_HAL_MAP_SYSPM_BEFORE_TRANSITION        CY_SYSPM_BEFORE_TRANSITION
#define MTB_HAL_MAP_SYSPM_AFTER_TRANSITION         CY_SYSPM_AFTER_TRANSITION

#define MTB_HAL_MAP_SYSPM_CB_SLEEP          CY_SYSPM_SLEEP
#define MTB_HAL_MAP_SYSPM_CB_DEEPSLEEP      CY_SYSPM_DEEPSLEEP

#define MTB_HAL_MAP_SYSPM_CB_HIBERNATE      CY_SYSPM_HIBERNATE

typedef cy_en_syspm_hibernate_wakeup_source_t  mtb_hal_syspm_hibernate_wakeup_source_t;

/** \endcond */
#endif // defined(CY_IP_MXS22SRSS) || defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS)

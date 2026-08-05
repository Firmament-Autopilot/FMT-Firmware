/***************************************************************************//**
* \file mtb_hal_hw_types_syspm_mxs22srss.h
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
#include "mtb_hal_hw_types_syspm_srss.h"

#if defined(CY_IP_MXS22SRSS)

#define MTB_HAL_MAP_SYSPM_CB_DEEPSLEEP_RAM  CY_SYSPM_DEEPSLEEP_RAM
#define MTB_HAL_MAP_SYSPM_CB_NORMAL         CY_SYSPM_LP
#define MTB_HAL_MAP_SYSPM_CB_LOW            CY_SYSPM_ULP
#define MTB_HAL_MAP_SYSPM_CB_HIGH           CY_SYSPM_HP

// The following value does not apply to this IP, give them
// placeholder values to satisfy the interface
#define MTB_HAL_MAP_SYSPM_AFTER_DS_WFI_TRANSITION  (5u)

#if defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) && \
    (CY_IP_MXS22SRSS_VERSION_MINOR >= 1)
#define MTB_HAL_MAP_SYSPM_CB_HIBERNATE_RAM          CY_SYSPM_HIBERNATE_RAM
#else
// The following value does not apply to this IP, give them
// placeholder values to satisfy the interface
#define MTB_HAL_MAP_SYSPM_CB_HIBERNATE_RAM          (9u)
#endif \
    /* defined(CY_IP_MXS22SRSS_VERSION) && (CY_IP_MXS22SRSS_VERSION == 2) &&
       (CY_IP_MXS22SRSS_VERSION_MINOR >= 1) */

#endif // if defined(CY_IP_MXS22SRSS)

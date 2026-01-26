/***************************************************************************//**
* \file mtb_hal_hw_types_system_srss.h
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

#if !defined(MTB_HAL_DRIVER_AVAILABLE_SYSTEM)
/** Macro specifying whether the System driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_SYSTEM (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_SYSTEM)

/** \} group_hal_availability */

#endif

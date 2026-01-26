/***************************************************************************//**
* \file mtb_hal_hw_types_nvm_flash.h
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

#if (defined(CY_IP_MXS40FLASHC) || \
    (defined(FLASHC_BASE) && (FLASHC_BASE > 0)) || \
    (defined(CPUSS_FLASHC_PRESENT) && (CPUSS_FLASHC_PRESENT) > 0))
#if !defined(_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)
#define _MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH (1u)
#endif // !defined(_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_NVM)
/** Macro specifying whether the NVM driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_NVM (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_NVM)

/** \} group_hal_availability */

#endif

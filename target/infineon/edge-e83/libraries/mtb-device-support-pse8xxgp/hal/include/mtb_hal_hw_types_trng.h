/***************************************************************************//**
* \file mtb_hal_hw_types_trng.h
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

/**
 * \brief
 * Provides implementation specific values for types that are part of the
 * portable HAL TRNG API.
 *
 * \addtogroup group_hal_impl_hw_types Specific Hardware Types
 * \{
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "mtb_hal_impl_types.h"
#include "mtb_hal_hw_types_trng_crypto.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_TRNG)
//! Implementation specific header for TRNG
#define MTB_HAL_TRNG_IMPL_HEADER          "mtb_hal_trng_impl.h"

/**
 * @brief TRNG configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef void* mtb_hal_trng_configurator_t;

#endif

/** \} group_hal_impl_hw_types */


#ifdef __cplusplus
}
#endif

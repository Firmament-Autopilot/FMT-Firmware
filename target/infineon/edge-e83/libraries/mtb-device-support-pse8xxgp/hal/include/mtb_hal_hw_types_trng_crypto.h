/***************************************************************************//**
* \file mtb_hal_hw_types_trng_crypto.h
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

#if defined(CY_IP_MXCRYPTO_INSTANCES) || defined(CPUSS_CRYPTO_PRESENT) \
    || defined(CY_IP_M0S8CRYPTO)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_TRNG)
/** Macro specifying whether the TRNG driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_TRNG (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_TRNG)

/** \} group_hal_availability */


/**
 * @brief RNG object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    CRYPTO_Type*                base; //!< Base address of CRYPTO IP instance
} mtb_hal_trng_t;

#endif // if defined(CY_IP_MXCRYPTO_INSTANCES) || defined(CPUSS_CRYPTO_PRESENT) ||
// defined(CY_IP_M0S8CRYPTO)

/***************************************************************************//**
* \file mtb_hal_trng.h
*
* \brief
* Provides a high level interface for interacting with the Infineon True Random
* Number Generator. This interface abstracts out the chip specific details. If
* any chip specific functionality is necessary, or performance is critical the
* low level functions can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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

/**
 * \addtogroup group_hal_trng TRNG (True Random Number Generator)
 * \ingroup group_hal
 * \{
 * High level interface to the True Random Number Generator (TRNG).
 *
 * This block uses dedicated hardware to efficiently generate true random numbers.
 *
 * \section subsection_trng_features Features
 * * Number generated is statistically random
 * * Based on physical processes exhibiting random variation
 * * Generated sequences of numbers cannot be duplicated by running the process again
 * * Uses polynomial generators with fixed and programmable polynomials
 *
 * \note This driver is not intended to be used directly as a security library, but can be used
 * in a security context. If a full security library is needed something like Mbed TLS should
 * be used instead.
 *
 * \section subsection_trng_quickstart Quick Start
 *
 * See \ref subsection_trng_use_case_1.
 *
 * \subsection subsection_trng_use_case_1 Simple TRNG number generation example
 * The following snippet initializes a TRNG and generates a true random number.
 *
 * \snippet hal_trng.c snippet_mtb_hal_trng_simple_init
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_TRNG)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_trng TRNG HAL Results
 *  TRNG specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** An invalid argument was passed to a function. */
#define MTB_HAL_TRNG_RSLT_ERR_BAD_ARGUMENT                \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_TRNG, 0))

/**
 * \}
 */

/** Get a random uint32_t number.
 *
 * @param[in]  obj   The TRNG object
 * @param[out] value Location to store the random number
 * @return Status of number generation request
 *
 * See \ref subsection_trng_use_case_1
 */
cy_rslt_t mtb_hal_trng_get_uint32(const mtb_hal_trng_t* obj, uint32_t* value);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_TRNG_IMPL_HEADER
#include MTB_HAL_TRNG_IMPL_HEADER
#endif /* MTB_HAL_TRNG_IMPL_HEADER */

#endif //defined(MTB_HAL_DRIVER_AVAILABLE_TRNG)

/** \} group_hal_trng */

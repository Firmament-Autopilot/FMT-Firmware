/***************************************************************************//**
* \file mtb_hal_utils.h
*
* \brief
* Provides utility functions.
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

/** \cond INTERNAL */
/**
 * \addtogroup group_hal_impl
 * \{
 * Common utility macros & functions used by multiple HAL drivers.
 */

#pragma once

#include "cy_result.h"
#include "mtb_hal_hw_types.h"
#include "cy_utils.h"
#include "mtb_hal_utils_impl.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define _MTB_HAL_UTILS_NS_PER_SECOND          (1000000000)
#define _MTB_HAL_UTILS_US_PER_MS              (1000)
#define _MTB_HAL_UTILS_ONE_TIME_UNIT          (1)     /**< Used to do a delay in one time unit (1
                                                         ms, 1 us) */
#define _MTB_HAL_UTILS_KHZ_TO_HZ(khz)         (((uint64_t)(khz)) * 1000ULL)
#define _MTB_HAL_UTILS_MHZ_TO_HZ(mhz)         ((uint32_t)((mhz) * 1000UL * 1000UL))
#define _MTB_HAL_UTILS_HZ_TO_KHZ(hz)          ((uint32_t)((hz) / 1000UL))

/* Return the smaller of two uint32_t values */
#define _MTB_HAL_MIN(actBufSize, bufSize)  (((uint32_t) (actBufSize) < (uint32_t) (bufSize)) ? \
                                           ((uint32_t) (actBufSize)) : ((uint32_t) (bufSize)) )

#if defined(__cplusplus)
}
#endif

/** \} group_hal_impl_utils */
/** \} group_hal_impl */
/** \endcond */

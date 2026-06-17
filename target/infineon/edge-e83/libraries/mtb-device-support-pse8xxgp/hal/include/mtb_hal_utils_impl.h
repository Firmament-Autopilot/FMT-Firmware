/***************************************************************************//**
* \file mtb_hal_utils_impl.h
*
* \brief
* Provides utility functions for working with the HAL.
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
#include "cy_pdl.h"
#include "mtb_hal_hw_types.h"
#include "cy_utils.h"
#include "mtb_hal_utils.h"
#if MTB_HAL_DRIVER_AVAILABLE_CLOCK
#include "mtb_hal_clock.h"
#endif /* MTB_HAL_DRIVER_AVAILABLE_CLOCK */

#if defined(__cplusplus)
extern "C" {
#endif

#if MTB_HAL_DRIVER_AVAILABLE_CLOCK
/**
 * Calculates clock tolerance in the specified units given a desired and actual frequency
 *
 * @param[in] type                  tolerance type
 * @param[in] desired_hz            desired clock frequency in hertz
 * @param[in] actual_hz             actual clock frequency in hertz
 * @return the computed tolerance
 */
int32_t _mtb_hal_utils_calculate_tolerance(mtb_hal_clock_tolerance_unit_t type, uint32_t desired_hz,
                                           uint32_t actual_hz);
#endif /* MTB_HAL_DRIVER_AVAILABLE_CLOCK */

typedef bool (* _mtb_hal_wait_status_funcptr_t)(void* obj, uint32_t status);

/**
 * Wait status with timeout value.  If not enabled, returns zero
 *
 * @param[in]       obj                 The object of HAL driver
 * @param[in]       status              The status(enum) the object is waiting for
 * @param[in,out]   timeout             The timeout value
 * @param[in]       funcptr             The function pointer to definition of waiting logic
 * @return CY_RSLT_SUCCESS if no timeout happens, else an error.
 */
cy_rslt_t _mtb_hal_wait_for_status(void* obj, uint32_t status, uint32_t* timeout,
                                   _mtb_hal_wait_status_funcptr_t funcptr);


#if defined(COMPONENT_SECURE_DEVICE) || defined(CY_PDL_TZ_ENABLED)
/** Define if the image is secure or non-secure */
#define _MTB_HAL_IMAGE_TYPE_SECURE
#endif

#if defined(__cplusplus)
}
#endif

/** \} group_hal_impl_utils */
/** \} group_hal_impl */
/** \endcond */

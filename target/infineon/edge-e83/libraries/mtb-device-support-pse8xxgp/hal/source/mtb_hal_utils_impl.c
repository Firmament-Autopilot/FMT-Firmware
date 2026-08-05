/***************************************************************************//**
* \file mtb_hal_utils_impl.c
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

#include <stdlib.h>
#include <stdarg.h>
#include "mtb_hal_utils.h"
#include "mtb_hal_utils_impl.h"
#include "mtb_hal_system_impl.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#if MTB_HAL_DRIVER_AVAILABLE_CLOCK
//--------------------------------------------------------------------------------------------------
// _mtb_hal_utils_calculate_tolerance
//--------------------------------------------------------------------------------------------------
int32_t _mtb_hal_utils_calculate_tolerance(mtb_hal_clock_tolerance_unit_t type, uint32_t desired_hz,
                                           uint32_t actual_hz)
{
    switch (type)
    {
        case MTB_HAL_TOLERANCE_HZ:
            return (int32_t)(desired_hz - actual_hz);

        case MTB_HAL_TOLERANCE_PPM:
            return (int32_t)(((int64_t)(desired_hz - actual_hz)) * 1000000) / ((int32_t)desired_hz);

        case MTB_HAL_TOLERANCE_PERCENT:
            return (int32_t)((((int64_t)desired_hz - actual_hz) * 100) / desired_hz);

        default:
            CY_ASSERT(false);
            return 0;
    }
}


#endif /* MTB_HAL_DRIVER_AVAILABLE_CLOCK */


//--------------------------------------------------------------------------------------------------
// _mtb_hal_wait_for_status
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_hal_wait_for_status(void* obj, uint32_t status, uint32_t* timeout,
                                   _mtb_hal_wait_status_funcptr_t funcptr)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t timeout_us = _MTB_HAL_UTILS_US_PER_MS;

    if (*timeout > 0)
    {
        while ((funcptr(obj, status) == true) && *timeout > 0)
        {
            if (timeout_us > 0)
            {
                mtb_hal_system_delay_us(_MTB_HAL_UTILS_ONE_TIME_UNIT);
                --timeout_us;
            }
            else
            {
                timeout_us = _MTB_HAL_UTILS_US_PER_MS;
                (*timeout)--;
            }
        }
        result = (*timeout > 0) ? CY_RSLT_SUCCESS : (cy_rslt_t)(-1);
    }
    return result;
}


#if defined(__cplusplus)
}
#endif

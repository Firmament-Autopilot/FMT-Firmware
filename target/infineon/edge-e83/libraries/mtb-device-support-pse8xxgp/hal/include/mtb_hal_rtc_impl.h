/***************************************************************************//**
* \file mtb_hal_rtc_impl.h
*
* Description:
* Provides a high level interface for interacting with the Infineon RTC.
*
********************************************************************************
* \copyright
* Copyright 2019-2024 Cypress Semiconductor Corporation (an Infineon company) or
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

#pragma once

#if (defined (CY_IP_MXS40SRSS_RTC) && (CY_IP_MXS40SRSS_RTC_VERSION == 2))
#include "mtb_hal_rtc_mxs40srss_ver2.h"
#elif (defined (CY_IP_MXS40SRSS_RTC))
#include "mtb_hal_rtc_mxs40srss_ver3.h"
#elif (defined (CY_IP_MXS40SSRSS))
#include "mtb_hal_rtc_mxs40ssrss.h"
#elif (defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 1))
#include "mtb_hal_rtc_mxs22srss_v1.h"
#elif (defined (CY_IP_MXS22SRSS) && (CY_IP_MXS22SRSS_VERSION == 2))
#include "mtb_hal_rtc_mxs22srss_v2.h"
#else
#error "Unhandled version"
#endif // if (defined (CY_IP_MXS40SRSS_RTC) && (CY_IP_MXS40SRSS_RTC_VERSION == 2))

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj   The HAL driver instance object. The caller must allocate the
 *                   memory for this object, but the HAL will initialize its contents
 * @param[in] config The configurator-generated HAL config structure for this
 *                   peripheral instance
 * @return the status of the HAL setup
 */
__STATIC_INLINE cy_rslt_t mtb_hal_rtc_setup(mtb_hal_rtc_t* obj,
                                            const mtb_hal_rtc_configurator_t* config)
{
    CY_UNUSED_PARAMETER(obj);
    CY_UNUSED_PARAMETER(config);
    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

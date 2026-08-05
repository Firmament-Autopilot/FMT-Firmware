/***************************************************************************//**
* \file mtb_hal_timer_impl.h
*
* Description:
* Provides a high level interface for interacting with the Infineon Timer/Counter.
*
********************************************************************************
* \copyright
* Copyright 2019-2021 Cypress Semiconductor Corporation (an Infineon company) or
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

#if (defined(CY_IP_M0S8TCPWM) && (CY_IP_M0S8TCPWM_VERSION == 2))
#include "mtb_hal_timer_common_v2.h"
#elif (defined(CY_IP_MXTCPWM) && (CY_IP_MXTCPWM_VERSION == 1))
#include "mtb_hal_timer_common_v2.h"
#elif (defined(CY_IP_MXTCPWM) && (CY_IP_MXTCPWM_VERSION == 2))
#include "mtb_hal_timer_common_v1.h"
#elif ((defined(CY_IP_MXS40TCPWM) && (CY_IP_MXS40TCPWM_VERSION == 1)) || (defined(CY_IP_MXTCPWM) && \
    (CY_IP_MXTCPWM_VERSION == 3)))
#include "mtb_hal_timer_common_v1.h"
#else
#error "Unhandled version"
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Defines
*******************************************************************************/

/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_timer_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_timer_enable(mtb_hal_timer_t* obj, bool enable)
{
    enable ? Cy_TCPWM_Counter_Enable(obj->tcpwm.base, obj->tcpwm.cntnum) : Cy_TCPWM_Counter_Disable(
        obj->tcpwm.base, obj->tcpwm.cntnum);
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_timer_enable _mtb_hal_timer_enable

#if defined(__cplusplus)
}
#endif /* __cplusplus */

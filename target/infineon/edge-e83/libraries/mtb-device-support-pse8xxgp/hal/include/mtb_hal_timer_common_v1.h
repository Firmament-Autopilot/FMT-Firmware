/***************************************************************************//**
* \file mtb_hal_timer_common_v1.h
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

#include "mtb_hal_hw_types.h"
#include "cy_tcpwm.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

//--------------------------------------------------------------------------------------------------
// _mtb_hal_timer_trigger_start
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_timer_trigger_start(mtb_hal_timer_t* obj)
{
    Cy_TCPWM_TriggerStart_Single(obj->tcpwm.base, obj->tcpwm.cntnum);
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

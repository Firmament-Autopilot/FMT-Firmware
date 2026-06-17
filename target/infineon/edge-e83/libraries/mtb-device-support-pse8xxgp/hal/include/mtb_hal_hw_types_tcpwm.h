/***************************************************************************//**
* \file mtb_hal_hw_types_tcpwm.h
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
#include "mtb_hal_hw_types_clock.h"

#if defined(CY_IP_MXTCPWM)
/**
 * @brief Shared TCPWM data between timer/counter and PWM
 *
 * Application code should not rely on the specific content of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    #ifdef CY_IP_MXTCPWM
    TCPWM_Type*                         base;         //!< The base address pointer of the TCPWM
                                                      //!< resource
    uint32_t                            group;        //!< The associated group number
    uint32_t                            cntnum;       //!< The associated counter number
    TCPWM_GRP_CNT_Type*                grp_cnt_base;  //!< The base address of the group counter
    uint32_t                            max_count;    //!< The max count for the counter
    const mtb_hal_clock_t*              clock;        //!< The associated clock resource pointer
    uint32_t                            clock_hz;     //!< The associated clock frequency
    #else // ifdef CY_IP_MXTCPWM
    void* empty;
    #endif // ifdef CY_IP_MXTCPWM
} mtb_hal_tcpwm_t;
#endif // if defined(CY_IP_MXTCPWM)

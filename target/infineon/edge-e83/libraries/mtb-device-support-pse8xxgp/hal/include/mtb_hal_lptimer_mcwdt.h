/***************************************************************************//**
* \file mtb_hal_lptimer_mcwdt.h
*
* \brief
* Provides common API declarations of the mcwdt driver
*
********************************************************************************
* \copyright
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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

#include "mtb_hal_lptimer.h"
#include <stdlib.h>
#include "cy_pdl.h"
#include "cy_mcwdt.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) || \
    defined(CY_IP_MXS22SRSS)

/* */
#include "mtb_hal_lptimer_mcwdt_resources.h"

/*******************************************************************************
*                           Defines
*******************************************************************************/

#define _MTB_HAL_LPTIMER_MCWDT
#define _MTB_HAL_LPTIMER_ISR_CALL_USER_CB_MASK          (0x01)
#define  _MTB_HAL_LPTIMER_SETMATCH_TIME_US              (0)

#define _mtb_hal_lptimer_get_interrupt_status           Cy_MCWDT_GetInterruptStatus

/*******************************************************************************
*                           Typedefs
*******************************************************************************/



/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/



/*******************************************************************************
*                        Inlined Functions
*******************************************************************************/


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_enable_event
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_enable_event(mtb_hal_lptimer_t* obj)
{
    uint32_t critical_section = Cy_SysLib_EnterCriticalSection();
    Cy_MCWDT_ClearInterrupt(obj->base, _MTB_HAL_LPTIMER_CNTR);
    Cy_MCWDT_SetInterruptMask(obj->base, _MTB_HAL_LPTIMER_CNTR);
    Cy_SysLib_ExitCriticalSection(critical_section);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_disable_event
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_disable_event(mtb_hal_lptimer_t* obj)
{
    uint32_t critical_section = Cy_SysLib_EnterCriticalSection();
    Cy_MCWDT_ClearInterrupt(obj->base, _MTB_HAL_LPTIMER_CNTR);
    Cy_MCWDT_SetInterruptMask(obj->base, 0);
    Cy_SysLib_ExitCriticalSection(critical_section);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_set_delay_rollover
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_set_delay_rollover(uint16_t* c0_match, uint16_t* c1_match)
{
    // These IPs need no rollover adjustment
    CY_UNUSED_PARAMETER(c0_match);
    CY_UNUSED_PARAMETER(c1_match);
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_set_delay_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE void _mtb_hal_lptimer_set_delay_enable(mtb_hal_lptimer_t* obj)
{
    Cy_MCWDT_SetInterruptMask(obj->base, _MTB_HAL_LPTIMER_CNTR);
}


#endif \
    /* defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) ||
       defined(CY_IP_MXS22SRSS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

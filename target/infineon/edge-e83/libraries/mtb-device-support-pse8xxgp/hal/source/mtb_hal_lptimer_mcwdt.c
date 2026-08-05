/***************************************************************************//**
* \file mtb_hal_lptimer_mcwdt.c
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


#include "mtb_hal_lptimer.h"
#include <stdlib.h>
#include "cy_pdl.h"
#include "mtb_hal_lptimer_mcwdt.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && (defined(CY_IP_MXS40SRSS) || \
    defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) || \
    defined(CY_IP_MXS22SRSS))

/*******************************************************************************
*                           Defines
*******************************************************************************/

/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Internal Functions
*******************************************************************************/


/*******************************************************************************
*                        Public Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_lptimer_process_interrupt(mtb_hal_lptimer_t* obj)
{
    CY_ASSERT(obj != NULL);
    Cy_MCWDT_ClearInterrupt(obj->base, _MTB_HAL_LPTIMER_PROCESS_CLR_INTR_CNTR);
    /* Clear interrupt mask if set only from mtb_hal_lptimer_set_delay() function */
    if (obj->clear_int_mask)
    {
        Cy_MCWDT_SetInterruptMask(obj->base, 0);
    }
    {
        if ((NULL != obj->callback_data.callback) &&
            ((obj->isr_instruction & _MTB_HAL_LPTIMER_ISR_CALL_USER_CB_MASK) != 0))
        {
            mtb_hal_lptimer_event_callback_t callback =
                (mtb_hal_lptimer_event_callback_t)obj->callback_data.callback;
            callback(obj->callback_data.callback_arg, MTB_HAL_LPTIMER_COMPARE_MATCH);
        }
    }
    #if (_MTB_HAL_IRQ_MUXING)
    /* Check if the event flag should have been cleared when inside a critical situation */
    if ((obj->isr_instruction & _MTB_HAL_LPTIMER_ISR_CRITICAL_SECTION_MASK) != 0)
    {
        Cy_MCWDT_ClearInterrupt(obj->base, _MTB_HAL_LPTIMER_CNTR);
        Cy_MCWDT_SetInterruptMask(obj->base, 0);
        obj->isr_instruction &= ~_MTB_HAL_LPTIMER_ISR_CRITICAL_SECTION_MASK;
    }
    #endif
    return CY_RSLT_SUCCESS;
}


#endif \
    /* defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && defined(CY_IP_MXS40SRSS) ||
       defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) ||
       defined(CY_IP_MXS22SRSS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

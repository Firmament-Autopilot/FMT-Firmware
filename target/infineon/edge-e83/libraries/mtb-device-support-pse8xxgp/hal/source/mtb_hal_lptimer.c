/***************************************************************************//**
* \file mtb_hal_lptimer.c
*
* \brief
* Provides a high level interface for interacting with the Infineon Low-Power Timer.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cmsis_compiler.h"
#include "cy_syslib.h"
#include "cy_sysint.h"
#include "mtb_hal_lptimer.h"
#include "mtb_hal_irq_impl.h"

#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER)

#if defined(__cplusplus)
extern "C" {
#endif

//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_lptimer_setup(mtb_hal_lptimer_t* obj,
                                const mtb_hal_lptimer_configurator_t* config)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != config);

    obj->base = config->base;
    obj->clear_int_mask = false;
    obj->callback_data.callback = NULL;
    obj->callback_data.callback_arg = NULL;
    obj->isr_instruction = 0;
    obj->lfclk_freqhz = config->lfclk_freqhz;

    /* Perform any additional IP-specific setup */
    _mtb_hal_lptimer_setup(obj);

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_lptimer_register_callback(mtb_hal_lptimer_t* obj,
                                       mtb_hal_lptimer_event_callback_t callback,
                                       void* callback_arg)
{
    CY_ASSERT(obj != NULL);

    uint32_t savedIntrStatus = Cy_SysLib_EnterCriticalSection();
    obj->callback_data.callback = (cy_israddress)callback;
    obj->callback_data.callback_arg = callback_arg;
    Cy_SysLib_ExitCriticalSection(savedIntrStatus);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_lptimer_enable_event(mtb_hal_lptimer_t* obj, mtb_hal_lptimer_event_t event,
                                  bool enable)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(event == MTB_HAL_LPTIMER_COMPARE_MATCH);
    CY_UNUSED_PARAMETER(event);

    obj->isr_instruction &= ~_MTB_HAL_LPTIMER_ISR_CALL_USER_CB_MASK;
    obj->isr_instruction |= (uint8_t)enable;

    if (enable)
    {
        _mtb_hal_lptimer_enable_event(obj);
    }
    else
    {
        #if (_MTB_HAL_IRQ_MUXING)
        /* We may be in a critical section. Only clear the interrupt status if there isn't a pending
           interrupt */
        if (_mtb_hal_lptimer_get_interrupt_status(obj->base) != 0)
        {
            obj->isr_instruction |= _MTB_HAL_LPTIMER_ISR_CRITICAL_SECTION_MASK;
        }
        else
        #endif
        {
            _mtb_hal_lptimer_disable_event(obj);
        }
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_read
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_lptimer_read(const mtb_hal_lptimer_t* obj)
{
    return _mtb_hal_lptimer_read(obj);
}


#if defined(__cplusplus)
}
#endif

#endif // MTB_HAL_DRIVER_AVAILABLE_LPTIMER

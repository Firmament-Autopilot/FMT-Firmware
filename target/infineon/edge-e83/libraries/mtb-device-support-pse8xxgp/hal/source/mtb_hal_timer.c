/***************************************************************************//**
* \file mtb_hal_timer.c
*
* \brief
* Provides a high level interface for interacting with the Infineon Timer/Counter.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
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
#include <string.h>
#include <stdio.h>
#include "cy_device_headers.h"
#include "mtb_hal_gpio.h"
#include "mtb_hal_hw_types.h"
#include "mtb_hal_system.h"
#include "mtb_hal_timer.h"
#include "mtb_hal_utils_impl.h"
#include "mtb_hal_irq_impl.h"

#if (MTB_HAL_DRIVER_AVAILABLE_TIMER)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Timer HAL Functions
*******************************************************************************/
//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_setup
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_timer_setup(mtb_hal_timer_t* obj, const mtb_hal_timer_configurator_t* hal_config,
                              mtb_hal_clock_t* clk)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != obj, MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT);
    CY_ASSERT_AND_RETURN(NULL != hal_config, MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT);
    #else
    if ((NULL == obj) || (NULL == hal_config))
    {
        return MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    /* start with a clean Timer object */
    memset(obj, 0, sizeof(mtb_hal_timer_t));

    if (NULL != clk)
    {
        obj->tcpwm.clock = clk;    // Copy clock info if passed in separately
    }
    else if (hal_config->clock != NULL)
    {
        obj->tcpwm.clock = ((mtb_hal_clock_t*)hal_config->clock);    // Copy clock info from config
    }

    /* Set timer base and index */
    obj->tcpwm.base    = hal_config->tcpwm_base;
    obj->tcpwm.cntnum  = hal_config->tcpwm_cntnum;

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_start
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_timer_start(mtb_hal_timer_t* obj)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != obj, MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT);
    #else
    if (NULL == obj)
    {
        return MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    Cy_TCPWM_Counter_Enable(obj->tcpwm.base, obj->tcpwm.cntnum);

    /* Call IP-specific Start */
    _mtb_hal_timer_trigger_start(obj);

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_stop
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_timer_stop(mtb_hal_timer_t* obj)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != obj, MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT);
    #else
    if (NULL == obj)
    {
        return MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    Cy_TCPWM_Counter_Disable(obj->tcpwm.base, obj->tcpwm.cntnum);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_reset
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_timer_reset(mtb_hal_timer_t* obj, uint32_t start_value)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != obj, MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT);
    #else
    if (NULL == obj)
    {
        return MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    Cy_TCPWM_Counter_SetCounter(obj->tcpwm.base, obj->tcpwm.cntnum, start_value);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_read
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_timer_read(const mtb_hal_timer_t* obj)
{
    if (NULL == obj)
    {
        return 0xFFFFFFFF;  // MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT
    }
    uint32_t read_value;

    read_value = Cy_TCPWM_Counter_GetCounter(obj->tcpwm.base, obj->tcpwm.cntnum);

    return read_value;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_hal_timer_register_callback(mtb_hal_timer_t* obj, mtb_hal_timer_event_callback_t callback,
                                     void* callback_arg)
{
    if (obj != NULL)
    {
        uint32_t savedIntrStatus = Cy_SysLib_EnterCriticalSection();
        obj->callback_data.callback     = (cy_israddress)callback;
        obj->callback_data.callback_arg = callback_arg;
        obj->callback_event             = MTB_HAL_TIMER_EVENT_NONE;
        Cy_SysLib_ExitCriticalSection(savedIntrStatus);
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_hal_timer_enable_event(mtb_hal_timer_t* obj, mtb_hal_timer_event_t event, bool enable)
{
    if (obj != NULL)
    {
        uint32_t savedIntrStatus = Cy_SysLib_EnterCriticalSection();

        uint32_t old_mask = Cy_TCPWM_GetInterruptMask(obj->tcpwm.base, obj->tcpwm.cntnum);
        if (enable)
        {
            // Clear any newly enabled events so that old IRQs don't trigger ISRs
            Cy_TCPWM_ClearInterrupt(obj->tcpwm.base, obj->tcpwm.cntnum, ~old_mask & event);
        }
        #if (_MTB_HAL_IRQ_MUXING)
        /* Only clear the interrupt status if there isn't a pending interrupt */
        if ((Cy_TCPWM_GetInterruptStatus(obj->tcpwm.base, obj->tcpwm.cntnum) == 0) || enable)
        #endif
        {
            uint32_t new_event = enable ? (old_mask | event) : (old_mask & ~event);
            Cy_TCPWM_SetInterruptMask(obj->tcpwm.base, obj->tcpwm.cntnum, new_event);
        }
        #if (_MTB_HAL_IRQ_MUXING)
        else
        {
            /* Note that this interrupt cause should be cleared the next time an interrupt
             * is triggered
             */
            obj->clear_intr_mask |= event;
        }
        #endif

        if (enable)
        {
            obj->callback_event    |= event;
        }
        else
        {
            obj->callback_event    &= ~event;
        }

        Cy_SysLib_ExitCriticalSection(savedIntrStatus);
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_timer_process_interrupt
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_timer_process_interrupt(mtb_hal_timer_t* obj)
{
    /* Return warning result code in case the interrupt status is
          not set for the requested timer */
    cy_rslt_t result     = MTB_HAL_TIMER_RSLT_WRN_INTERRUPT_STATUS_NOT_SET;

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != obj, MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT);
    #else
    if (NULL == obj)
    {
        return MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    // Get and clear the interrupt cause
    uint32_t intrCause = Cy_TCPWM_GetInterruptStatusMasked(obj->tcpwm.base, obj->tcpwm.cntnum);
    Cy_TCPWM_ClearInterrupt(obj->tcpwm.base, obj->tcpwm.cntnum, intrCause);

    if (obj->callback_data.callback != NULL)
    {
        if (intrCause & obj->callback_event)
        {
            mtb_hal_timer_event_callback_t user_callback =
                (mtb_hal_timer_event_callback_t)obj->callback_data.callback;

            user_callback(obj->callback_data.callback_arg,
                          (mtb_hal_timer_event_t)(intrCause & obj->callback_event));
            result = CY_RSLT_SUCCESS;
        }
    }

    #if (_MTB_HAL_IRQ_MUXING)
    /* Disable any interrupts that couldn't be disabled from enable_event */
    if (0u != obj->clear_intr_mask)
    {
        uint32_t cnt_num = obj->tcpwm.cntnum;
        uint32_t old_mask = Cy_TCPWM_GetInterruptMask(obj->tcpwm.base, cnt_num);
        Cy_TCPWM_SetInterruptMask(obj->tcpwm.base, cnt_num,
                                  (old_mask & ~(obj->clear_intr_mask)));
        obj->clear_intr_mask = 0u;
    }
    #endif // (_MTB_HAL_IRQ_MUXING)

    return result;
}


#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_TIMER */

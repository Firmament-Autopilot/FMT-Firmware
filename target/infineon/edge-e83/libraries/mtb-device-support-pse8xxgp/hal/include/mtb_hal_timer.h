/***************************************************************************//**
* \file mtb_hal_timer.h
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

/**
 * \addtogroup group_hal_timer Timer (Timer/Counter)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the Timer/Counter hardware resource.
 *
 * The timer block is commonly used to measure the time of occurrence of an event,
 * to measure the time difference between two events or perform an action after
 * a specified period of time. The driver also allows the user to invoke a callback function
 * when a particular event occurs.
 *
 * Some use case scenarios of timer -
 *
 * * Creating a periodic interrupt for executing periodic tasks
 * * Measuring time between two events
 * * Triggering other system resources after a certain number of events
 * * Capturing time stamps when events occur
 *
 * \section subsection_timer_features Features
 * * Runtime configurable parameters like period and compare value
 * * Configurable counting direction
 * * Interrupt on various events
 * * Continuous or One Shot run modes
 *
 * \section subsection_timer_quickstart Quick Start
 *
 * See \ref subsection_timer_snippet_1.
 *
 * \section subsection_timer_sample_snippets Code Snippets
 *
 * \subsection subsection_timer_snippet_1 Snippet 1: Measuring time of an operation
 * The following snippet initializes a Timer and measures the time between two events.
 * The clock will be defined in design.modus, and can be over-ridden with the
 * mtb_hal_timer_setup() call.
 * \snippet hal_timer.c snippet_mtb_hal_timer_event_measure
 *
 * \subsection subsection_timer_snippet_2 Snippet 2: Handling an event in a callback function
 * The following snippet initializes a Timer and triggers an event after every one second.
 * The clock will be defined in design.modus, and can be over-ridden with the
 * mtb_hal_timer_setup() call.
 * \snippet hal_timer.c snippet_mtb_hal_timer_event_interrupt
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_TIMER)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_timer Timer HAL Results
 *  Timer specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Bad argument. eg: null pointer */
#define MTB_HAL_TIMER_RSLT_ERR_BAD_ARGUMENT               \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_TIMER, 0))
/** Feature unsupported with this Timer */
#define MTB_HAL_TIMER_RSLT_ERR_UNSUPPORTED                \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_TIMER, 1))
/** Interrupt status bit is not set for the specified timer */
#define MTB_HAL_TIMER_RSLT_WRN_INTERRUPT_STATUS_NOT_SET     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_TIMER, 2))

/**
 * \}
 */

/*******************************************************************************
*       Enumerations
*******************************************************************************/

/** HAL Timer events */
typedef enum
{
    /** No event */
    MTB_HAL_TIMER_EVENT_NONE            = (MTB_HAL_MAP_TIMER_EVENT_NONE),
    /** Timer Event Terminal Count = (timer reached max count), */
    MTB_HAL_TIMER_EVENT_TERMINAL_COUNT  = (MTB_HAL_MAP_TIMER_EVENT_TERMINAL_COUNT),
    /** Timer Event Compare Count 0 = (timer reached compare 0 count), */
    MTB_HAL_TIMER_EVENT_COMPARE_CC0     = (MTB_HAL_MAP_TIMER_EVENT_COMPARE_CC0),
    /** Timer Event Compare Count 0 -or- Terminal Count */
    MTB_HAL_TIMER_EVENT_COMPARE_CC0_OR_TERMINAL_COUNT \
        = (MTB_HAL_MAP_TIMER_EVENT_COMPARE_CC0_OR_TERMINAL_COUNT),
    /** Timer Event Compare Count 1 = (timer reached compare 1 count), */
    MTB_HAL_TIMER_EVENT_COMPARE_CC1     = (MTB_HAL_MAP_TIMER_EVENT_COMPARE_CC1),
    /** All Timer Events Combined */
    MTB_HAL_TIMER_EVENT_ALL             = (MTB_HAL_MAP_TIMER_EVENT_ALL)
} mtb_hal_timer_event_t;

/*******************************************************************************
*       Data Structures
*******************************************************************************/

/*******************************************************************************
*       Typedefs
*******************************************************************************/

/** Handler for timer events, callback_arg is a pointer to the timer obj */
typedef void(* mtb_hal_timer_event_callback_t)(void* callback_arg, mtb_hal_timer_event_t event);

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
 * @param[in] clock  The HAL clock object that is connected to this peripheral instance
 * @return the status of the HAL setup
 */
cy_rslt_t mtb_hal_timer_setup(mtb_hal_timer_t* obj, const mtb_hal_timer_configurator_t* config,
                              mtb_hal_clock_t* clock);

/** Enable/disable the Timer.
 *
 * The function returns without waiting for the enable to complete.
 *
 * @param[in] obj          The Timer object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_timer_enable(mtb_hal_timer_t* obj, bool enable);

/** Starts the timer/counter with the pre-set configuration.
 * This does not reset the counter. The count value will start from the value that was
 * set by the last operation to modify it.
 * See \ref subsection_timer_snippet_1.
 *
 * @param[in] obj     The timer/counter object
 * @return The status of the start request
 */
cy_rslt_t mtb_hal_timer_start(mtb_hal_timer_t* obj);

/** Stops the timer/counter. Does not reset counter value. <br>
 *
 * @param[in] obj     The timer/counter object
 * @return The status of the stop request
 */
cy_rslt_t mtb_hal_timer_stop(mtb_hal_timer_t* obj);

/** Reset the timer/counter value.
 *
 * @param[in] obj           The timer/counter object
 * @param[in] start_value   Start value for the timer.
 * @return The status of the reset request
 */
cy_rslt_t mtb_hal_timer_reset(mtb_hal_timer_t* obj, uint32_t start_value);

/** Reads the current value from the timer/counter <br>
 * See \ref subsection_timer_snippet_1.
 *
 * @param[in] obj     The timer/counter object
 * @return The current value of the timer/counter
 */
uint32_t mtb_hal_timer_read(const mtb_hal_timer_t* obj);

/** Register a timer/counter callback handler<br>
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_timer_enable_event
 * occurs.
 *
 * See \ref subsection_timer_snippet_2.
 *
 * @param[in] obj          The timer/counter object
 * @param[in] callback     The callback handler which will be invoked when the event occurs
 * @param[in] callback_arg Generic argument that will be provided to the callback when called
 */
void mtb_hal_timer_register_callback(mtb_hal_timer_t* obj, mtb_hal_timer_event_callback_t callback,
                                     void* callback_arg);

/** Configure timer/counter event enablement <br>
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_timer_register_callback will
 * be called.
 *
 * See \ref subsection_timer_snippet_2.
 *
 * @param[in] obj           The timer/counter object
 * @param[in] event         The timer/counter event \ref mtb_hal_timer_event_t
 * @param[in] enable        True to turn on interrupts, False to turn off
 */
void mtb_hal_timer_enable_event(mtb_hal_timer_t* obj, mtb_hal_timer_event_t event, bool enable);

/**
 * Process interrupts related related to a Timer instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_timer_process_interrupt(mtb_hal_timer_t* obj);
#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_TIMER_IMPL_HEADER
#include MTB_HAL_TIMER_IMPL_HEADER
#endif /* MTB_HAL_TIMER_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_TIMER)

/** \} group_hal_timer */

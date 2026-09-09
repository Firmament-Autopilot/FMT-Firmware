/***************************************************************************//**
* \file mtb_hal_lptimer.h
*
* \brief
* Provides a high level interface for interacting with the Infineon Low-Power Timer.
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
//" *SUSPEND-FORMATTING*"
/**
 * \addtogroup group_hal_lptimer LPTimer (Low-Power Timer)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the low-power timer (LPTimer).
 *
 * LPTimer can operate in all possible low power modes. It can be used either to measure timing
 * between events, or to perform
 * some action after a specified interval of time.
 * \section subsection_lptimer_features Features
 * * Wake the device up from deepsleep
 * * Configurable to create a free-running timer or generate periodic interrupts.
 * * Configurable to update the match value of an already configured LPTimer set up to generate an
 * interrupt on match.
 * * Used for measuring time between events in free-running mode.
 *
 * \section subsection_lptimer_quickstart Quick Start
 *
 * See \ref subsection_lptimer_snippet_2.
 *
 * \section subsection_lptimer_snippets Code snippets
 *
 * \subsection subsection_lptimer_snippet_1 Snippet 1: LPTimer initialization with Default configuration
 * The following snippet initializes a LPTimer in free running mode.
 * \snippet hal_lptimer.c snippet_mtb_hal_lptimer_simple_setup_def
 *
 * \subsection subsection_lptimer_snippet_2 Snippet 2: LPTimer interrupts
 * The following snippet initializes a LPTimer and uses \ref mtb_hal_lptimer_set_delay() to trigger
 * an interrupt
 * on match. Subsequent interrupts can be triggered at required times using \ref
 * mtb_hal_lptimer_set_delay() called from the ISR.
 * \snippet hal_lptimer.c snippet_mtb_hal_lptimer_interrupt
 */
//" *RESUME-FORMATTING*"
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_lptimer LPTimer HAL Results
 *  LPTimer specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Failed to configure power management callback */
#define MTB_HAL_LPTIMER_RSLT_ERR_PM_CALLBACK              \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_LPTIMER, 0))

/** Failed to execute not supported API */
#define MTB_HAL_LPTIMER_RSLT_ERR_NOT_SUPPORTED            \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_LPTIMER, 1))

/** Timer is not enabled or it is not clocked */
#define MTB_HAL_LPTIMER_RSLT_ERR_DISABLED            \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_LPTIMER, 2))

/** Bad argument. eg: null pointer */
#define MTB_HAL_LPTIMER_RSLT_ERR_BAD_ARGUMENT            \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_LPTIMER, 3))

/**
 * \}
 */

/** LPTimer interrupt triggers */
typedef enum
{
    MTB_HAL_LPTIMER_COMPARE_MATCH
} mtb_hal_lptimer_event_t;

/** Handler for LPTimer interrupts */
typedef void (* mtb_hal_lptimer_event_callback_t)(void* callback_arg,
                                                  mtb_hal_lptimer_event_t event);

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
cy_rslt_t mtb_hal_lptimer_setup(mtb_hal_lptimer_t* obj,
                                const mtb_hal_lptimer_configurator_t* config);

/** Update the match/compare value
 *
 * Update the match value of an already configured LPTimer set up
 * to generate an interrupt on match delay from the current counter value.
 * Note that this function does not reinitialize the counter or the
 * associated peripheral initialization
 * sequence.
 *
 * @param[in] obj   The LPTimer object
 * @param[in] delay The ticks to wait. The minimum permitted delay value can be
 *                  found in the implementation specific documentation.
 *
 * @return The status of the set_delay request. On success it returns \ref CY_RSLT_SUCCESS.
 */
cy_rslt_t mtb_hal_lptimer_set_delay(mtb_hal_lptimer_t* obj, uint32_t delay);

/** Read the current tick
 *
 * If no rollover has occurred, the seconds passed since mtb_hal_lptimer_init() or
 * mtb_hal_lptimer_set_time()
 * was called can be found by dividing the ticks returned by this function
 * by the frequency of the source clock (Refer to BSP Settings section in the kit's BSP API
 * Reference Manual for details on the clock source for LPTimer).
 *
 * @param[in] obj    The LPTimer object
 * @return The timer's timer value in ticks
 */
uint32_t mtb_hal_lptimer_read(const mtb_hal_lptimer_t* obj);

/** Register a LPTimer match event handler
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_lptimer_enable_event
 * occurs.
 *
 * @param[in] obj          The LPTimer object
 * @param[in] callback     The callback handler which will be invoked when the interrupt triggers
 * @param[in] callback_arg Generic argument that will be provided to the handler when called
 */
void mtb_hal_lptimer_register_callback(mtb_hal_lptimer_t* obj,
                                       mtb_hal_lptimer_event_callback_t callback,
                                       void* callback_arg);

/** Configure and Enable/Disable the LPTimer events
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_lptimer_register_callback
 * will be called.
 *
 * @param[in] obj            The LPTimer object
 * @param[in] event          The LPTimer event type
 * @param[in] enable         True to turn on event, False to turn off
 */
void mtb_hal_lptimer_enable_event(mtb_hal_lptimer_t* obj, mtb_hal_lptimer_event_t event,
                                  bool enable);

/**
 * Process interrupts related related to an LPTimer instance.
 *
 * @param[in] obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_lptimer_process_interrupt(mtb_hal_lptimer_t* obj);

#if defined(MTB_HAL_LPTIMER_IMPL_HEADER)
#include MTB_HAL_LPTIMER_IMPL_HEADER
#endif /* defined(MTB_HAL_LPTIMER_IMPL_HEADER) */

#if defined(__cplusplus)
}
#endif

#endif //defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER)

/** \} group_hal_lptimer */

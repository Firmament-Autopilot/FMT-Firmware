/***************************************************************************//**
* \file mtb_hal_pwm.h
*
* \brief
* Provides a high level interface for interacting with the Infineon PWM.
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
 * \addtogroup group_hal_pwm PWM (Pulse Width Modulator)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the pulse width modulator (PWM) hardware resource
 *
 * The PWM driver can be used to generate periodic digital waveforms with configurable frequency and
 * duty cycle.
 * The driver allows assigning the PWM output and an optional inverted output to supplied pins.
 * The driver supports interrupt generation on PWM terminal count and compare events.
 *
 * \section section_pwm_features Features
 * * Configurable pin assignment for the PWM output
 * * Optional complementary (inverted) PWM output to a second pin
 * * Configurable dead time between normal and inverted PWM outputs
 * * Configurable alignment: left, right or center
 * * Continuous or One-shot operation
 * * Option to instantiate and use a new clock or use pre-allocated clock for clock input
 * * Configurable interrupt and callback assignment on PWM events: terminal count, compare match or
 * combination of both
 *
 * \section section_pwm_quickstart Quick Start
 *
 * See \ref subsection_pwm_snippet_1 for a code snippet that generates a signal with the specified
 * frequency and duty cycle on the specified pin.
 *
 * \section section_pwm_snippets Code snippets
 *
 * \subsection subsection_pwm_snippet_1 Snippet 1: Simple PWM initialization and output to pin
 * The clock parameter <b>clk</b> is optional and need not be provided (NULL), to generate and use
 * an available clock resource with a default frequency. <br>
 * The clock frequency and the duty cycle is set using \ref mtb_hal_pwm_set_period. <br>
 * \ref mtb_hal_pwm_start starts the PWM output on the pin.
 *
 * \snippet hal_pwm.c snippet_mtb_hal_pwm_init
 *
 *
 * \subsection subsection_pwm_snippet_2 Snippet 2: Starting and stopping the PWM output
 * \ref mtb_hal_pwm_start and \ref mtb_hal_pwm_stop functions can be used after PWM initialization
 * to start and stop the PWM output.
 *
 * \snippet hal_pwm.c snippet_mtb_hal_pwm_start_stop
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "cy_result.h"
#include "cy_utils.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_PWM)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_pwm PWM HAL Results
 *  PWM specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Bad argument */
#define MTB_HAL_PWM_RSLT_BAD_ARGUMENT                     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_PWM, 0))
/** The requested operation is not supported on the current hardware */
#define MTB_HAL_PWM_RSLT_ERR_UNSUPPORTED                  \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_PWM, 1))

/**
 * \}
 */

/** PWM event types */
typedef enum
{
    MTB_HAL_PWM_EVENT_NONE            =  0,             /**< No event */
    MTB_HAL_PWM_EVENT_TERMINAL_COUNT  =  1 << 0,        /**< Event on terminal count match event */
    MTB_HAL_PWM_EVENT_COMPARE         =  1 << 1,        /**< Event on compare match event */
    MTB_HAL_PWM_EVENT_ALL             = (1 << 2) - 1    /**< Event on any events */
} mtb_hal_pwm_event_t;

/** PWM output source */
typedef enum
{
    /* Can map to cy_en_line_select_config_t */
    MTB_HAL_PWM_OUTPUT_CONSTANT_0           = 0, /**< Output signal is 0. */
    MTB_HAL_PWM_OUTPUT_CONSTANT_1           = 1, /**< Output signal is 1. */
    MTB_HAL_PWM_OUTPUT_PWM_SIGNAL           = 2, /**< Output signal is PWM Signal. */
    MTB_HAL_PWM_OUTPUT_INVERTED_PWM_SIGNAL  = 3, /**< Output signal is inverted PWM Signal. */
    MTB_HAL_PWM_OUTPUT_PORT_DEFAULT         = 4, /**< Output is not driven by the TCPWM. Instead the
                                                    port default level configuration applies, e.g.
                                                    "Z" (high impedance). */
    MTB_HAL_PWM_OUTPUT_SOURCE_MOTIF         = 5  /**< Source for PWM signal conditioning comes from
                                                    MOTIF modulation output control signals. It can
                                                    be set to '0' , '1' or PWM. */
} mtb_hal_pwm_output_t;

/** Handler for PWM events */
typedef void(* mtb_hal_pwm_event_callback_t)(void* callback_arg, mtb_hal_pwm_event_t event);

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
cy_rslt_t mtb_hal_pwm_setup(mtb_hal_pwm_t* obj, const mtb_hal_pwm_configurator_t* config,
                            const mtb_hal_clock_t* clock);

/** Set the number of microseconds for the PWM period & pulse width
 *
 * @param[in] obj            The PWM object
 * @param[in] period_us      The period in microseconds
 * @param[in] pulse_width_us The pulse width in microseconds
 * @return                   The status of the period request
 */
cy_rslt_t mtb_hal_pwm_set_period(mtb_hal_pwm_t* obj, uint32_t period_us, uint32_t pulse_width_us);

/** Enable/disable the PWM.
 *
 * The function returns without waiting for the enable to complete.
 *
 * @param[in] obj          The PWM object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_pwm_enable(mtb_hal_pwm_t* obj, bool enable);

/** Starts the PWM generation and outputs on <b>pin</b> and <b>compl_pin</b>.
 *
 * @param[in] obj           The PWM object
 * @return                  The status of the start request
 */
cy_rslt_t mtb_hal_pwm_start(mtb_hal_pwm_t* obj);

/** Stops the PWM generation and outputs on <b>pin</b> and <b>compl_pin</b>.
 *
 * @param[in] obj          The PWM object
 * @return                 The status of the stop request
 */
cy_rslt_t mtb_hal_pwm_stop(mtb_hal_pwm_t* obj);

/** Sets the period count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The period value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_period_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the alternative period count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The period value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_period_alt_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the compare count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The compare value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_compare_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the shadow compare count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The compare value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_compare_shadow_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the alternative compare count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The compare value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_compare_alt_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the alternative shadow compare count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The compare value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_compare_alt_shadow_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the deadtime count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The deadtime value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_deadtime_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Sets the shadow deadtime count value
 *
 * @param[in] obj            The PWM object
 * @param[in] count          The deadtime value in counts
 * @return The status of the count set request
 */
cy_rslt_t mtb_hal_pwm_set_deadtime_shadow_count(mtb_hal_pwm_t* obj, uint32_t count);

/** Configures the source of the output pins
 *
 * @param[in] obj            The PWM object
 * @param[in] out            Output source for pwm pin
 * @param[in] out_compl      Output source for the complementary pwm pin
 * @return The status of the output source configuration request
 */
cy_rslt_t mtb_hal_pwm_configure_output(mtb_hal_pwm_t* obj, mtb_hal_pwm_output_t out,
                                       mtb_hal_pwm_output_t out_compl);

/** Resume the PWM counter
 *
 * This function is intented for starting an already enabled PWM.
 * For enabling the PWM, use mtb_hal_pwm_start
 *
 * @param[in] obj            The PWM object
 */
void mtb_hal_pwm_resume(mtb_hal_pwm_t* obj);

/** Pause the PWM counter
 *
 * This function is intented for temporarily stopping the PWM.
 * For disabling the PWM, use mtb_hal_pwm_stop
 *
 * @param[in] obj            The PWM object
 */
void mtb_hal_pwm_pause(mtb_hal_pwm_t* obj);

/** Reload the PWM counter
 *
 * This function resets the counter to its initial value at configuration.
 *
 * @param[in] obj            The PWM object
 */
void mtb_hal_pwm_reload(mtb_hal_pwm_t* obj);

/** Register/clear a callback handler for PWM events
 *
 * The referenced function will be called when one of the events enabled by
 * mtb_hal_pwm_enable_event occurs.
 *
 * @param[in] obj           The PWM object
 * @param[in] callback      The callback handler which will be invoked when the event occurs
 * @param[in] callback_arg  Generic argument that will be provided to the callback when called
 */
void mtb_hal_pwm_register_callback(mtb_hal_pwm_t* obj, mtb_hal_pwm_event_callback_t callback,
                                   void* callback_arg);

/** Enable or Disable the specified PWM event
 *
 * When an enabled event occurs, the function specified by mtb_hal_pwm_register_callback will
 * be called.
 *
 * @param[in] obj           The PWM object
 * @param[in] event         The PWM event
 * @param[in] enable        True to turn on interrupts, False to turn off
 */
void mtb_hal_pwm_enable_event(mtb_hal_pwm_t* obj, mtb_hal_pwm_event_t event, bool enable);

/** Process interrupts related related to a PWM instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_pwm_process_interrupt(mtb_hal_pwm_t* obj);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_PWM_IMPL_HEADER
#include MTB_HAL_PWM_IMPL_HEADER
#endif /* MTB_HAL_PWM_IMPL_HEADER */

#endif //defined(MTB_HAL_DRIVER_AVAILABLE_PWM)

/** \} group_hal_pwm */

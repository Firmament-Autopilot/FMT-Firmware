/***************************************************************************//**
* \file mtb_hal_comp.h
*
* Provides a high level interface for interacting with the Infineon Analog Comparator.
* This interface abstracts out the chip specific details.
* If any chip specific functionality is required the low level functions can
* be used directly.
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
 * \addtogroup group_hal_comp COMP (Analog Comparator)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with an analog Comparator.
 *
 * \section mtb_hal_comp_features Features
 * The analog comparator measures one input voltage from the non-inverting pin against
 * a second voltage provided on the inverting pin. The result of this comparison can
 * be used in two ways:
 * - Output to pin or other on-chip destination (configured via configurator)
 * - Read state via firmware (see @ref mtb_hal_comp_read)
 *
 * These abilities can be used in any combination.
 *
 * \section mtb_hal_comp_quickstart Quickstart
 * Call \ref mtb_hal_comp_setup to initialize the HAL for a peripheral instance. The peripheral
 * must]
 * have already been initialized and configured using the PDL.
 *
 * Use \ref mtb_hal_comp_read to read the comparator state from firmware.
 *
 * \section subsection_comp_snippets Code Snippets:
 * \note Error checking is omitted for clarity
 * \section subsection_comp_snippet_1 Snippet 1: Comparator read value
 * The following snippet reads the current comparator value into a variable
 * \snippet hal_comp.c snippet_mtb_hal_comp_read
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "mtb_hal_gpio.h"
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_COMP)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_comp Comparator HAL Results
 *  Comparator specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Bad argument */
#define MTB_HAL_COMP_RSLT_ERR_BAD_ARGUMENT                  \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_COMP, 0))
/** Not supported */
#define MTB_HAL_COMP_RSLT_ERR_NOT_SUPPORTED                  \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_COMP, 1))

/**
 * \}
 */

/** Comparator event types */
typedef enum
{
    MTB_HAL_COMP_EDGE_NONE    = 0,  //!< No trigger on either edge
    MTB_HAL_COMP_RISING_EDGE  = 1,  //!< Rising edge on comparator output
    MTB_HAL_COMP_FALLING_EDGE = 2,  //!< Falling edge on comparator output
    MTB_HAL_COMP_BOTH_EDGE    = 3   //!< Falling edge on comparator output
} mtb_hal_comp_event_t;

/** Handler for Comparator events */
typedef void (* mtb_hal_comp_event_callback_t)(void* callback_arg, mtb_hal_comp_event_t event);

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
cy_rslt_t mtb_hal_comp_setup(mtb_hal_comp_t* obj, const mtb_hal_comp_configurator_t* config);

/** Reads the Comparator state.
 *
 * @param[in]  obj    Comparator object
 * @return The Comparator state. True if the non-inverting pin voltage is greater than the
 * inverting pin voltage, false otherwise.
 */
bool mtb_hal_comp_read(mtb_hal_comp_t* obj);

/** Sets the reference voltage value
 *
 * @param[in] obj            Comparator object
 * @param[in] ref_mv         Reference voltage in millivolts
 * @return The status of the set reference request
 */
cy_rslt_t mtb_hal_comp_set_ref(mtb_hal_comp_t* obj, uint16_t ref_mv);

/** Enable/disable the comparator
 *
 * @param[in] obj          The Comp object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_comp_enable(mtb_hal_comp_t* obj, bool enable);

/** Enable/disable the slope generator slice
 *
 * @param[in] obj          The Comp object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_comp_slice_enable(mtb_hal_comp_t* obj, bool enable);

/** Read the output state of the slope generator slice
 *
 * @param[in] obj          The Comp object
 * @return The Comparator state. True if the non-inverting pin voltage is greater than the
 * inverting pin voltage, false otherwise.
 */
bool mtb_hal_comp_slice_read(mtb_hal_comp_t* obj);

/** Sets the reference count of the slope generator slice
 *
 * @param[in] obj          The Comp object
 * @param[in] count        Reference count
 * @return The status of the set reference request
 */
cy_rslt_t mtb_hal_comp_slice_set_ref_count(mtb_hal_comp_t* obj, uint32_t count);

/** Sets the reference voltage of the slope generator slice
 *
 * @param[in] obj          The Comp object
 * @param[in] ref_mv       Reference voltage in millivolts
 * @return The status of the set reference request
 */
cy_rslt_t mtb_hal_comp_slice_set_ref_mv(mtb_hal_comp_t* obj, uint32_t ref_mv);


/** Register/clear a callback handler for Comp events
 *
 * The referenced function will be called when one of the events enabled by
 * by mtb_hal_comp_enable_event occurs.
 *
 * @param[in] obj           The Comp object
 * @param[in] callback      The callback handler which will be invoked when the event occurs
 * @param[in] callback_arg  Generic argument that will be provided to the callback when called
 */
void mtb_hal_comp_register_callback(mtb_hal_comp_t* obj, mtb_hal_comp_event_callback_t callback,
                                    void* callback_arg);

/** Enable or Disable the specified Comp event
 *
 * When an enabled event occurs, the function specified by mtb_hal_comp_register_callback will
 * be called.
 *
 * @param[in] obj           The Comp object
 * @param[in] event         The Comp event
 * @param[in] enable        True to turn on interrupts, False to turn off
 */
void mtb_hal_comp_enable_event(mtb_hal_comp_t* obj, mtb_hal_comp_event_t event, bool enable);

/** Process interrupts related related to a Comp instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_comp_process_interrupt(mtb_hal_comp_t* obj);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_COMP_IMPL_HEADER
#include MTB_HAL_COMP_IMPL_HEADER
#endif /* MTB_HAL_COMP_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_COMP)

/** \} group_hal_comp */

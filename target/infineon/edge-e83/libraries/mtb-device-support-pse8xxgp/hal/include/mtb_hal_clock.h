/***************************************************************************//**
* \file mtb_hal_clock.h
*
* \brief
* Provides a high level interface for interacting with the the clocks on the device
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary the low level functions can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
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

/**
 * \addtogroup group_hal_clock Clock
 * \ingroup group_hal
 * \{
 * Interface for enabling or disabling the clock and updating the clock
 * frequency
 *
 *******************************************************************************
 * \section group_hal_clock_features  Features
 *******************************************************************************
 * * Enable/disable the clock
 * * Update the clock frequency
 *
 *******************************************************************************
 * \section subsection_clock_snippets Code snippets
 *******************************************************************************
 * \note Error checking is omitted for clarity
 * \subsection subsection_clock_snippet_1 Snippet 1: Defining and using a custom clock
 * interface, both directly and passing to a HAL driver to manipulate.
 * \snippet hal_clock.c snippet_mtb_hal_clock_custom_interface
 */

#pragma once

#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_CLOCK)

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */


/*******************************************************************************
*                           Defines
*******************************************************************************/

/** \addtogroup group_hal_results_clock Clock HAL Results
 *  Clock specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Error configuring clock frequency, divider, or multiplier. */
#define MTB_HAL_CLOCK_RSLT_ERR_FREQ               \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_CLOCK, 0))
/** Unsupported operation. */
#define MTB_HAL_CLOCK_RSLT_ERR_NOT_SUPPORTED               \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_CLOCK, 1))

/**
 * \}
 */

/*******************************************************************************
*                           Enums
*******************************************************************************/

/** Enum defining the different ways of specifying the acceptable clock tolerance. */
typedef enum
{
    MTB_HAL_TOLERANCE_HZ,         //!< Clock tolerance specified directly in Hertz.
    MTB_HAL_TOLERANCE_PPM,        //!< Clock tolerance specified in parts-per-million.
    MTB_HAL_TOLERANCE_PERCENT     //!< Clock tolerance specified in a percent.
} mtb_hal_clock_tolerance_unit_t;

/** Structure defining a clock tolerance. */
typedef struct
{
    mtb_hal_clock_tolerance_unit_t type;  //!< The type of the clock tolerance value.
    uint32_t                     value; //!< The tolerance value to use.
} mtb_hal_clock_tolerance_t;

/*******************************************************************************
*                          Function Pointers
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/** Attempts to update the enablement of the specified clock.
 *
 * \note If disabled, any clocks or peripherals that are using this will stop working. Make sure
 * to switch the clock source of any downstream clocks if necessary to keep them running prior to
 * disabling their source.
 *
 * @param[in] clock         The clock object to update the enablement of.
 * @param[in] enabled       Whether the clock should be enabled (true) or disabled (false).
 * @param[in] wait_for_lock Whether to wait for the clock to enable & lock (true), or just send
 *                          the request and return (false). Most clocks behave the same either
 *                          way, however Crystals, PLLs, and similar require time to lock. If
 *                          false, the clocks enabled state needs be checked before using the clock.
 * @return The status of the requested to change the clocks enablement.
 */
cy_rslt_t mtb_hal_clock_set_enabled(mtb_hal_clock_t* clock, bool enabled, bool wait_for_lock);

/** Attempts to update the operating frequency of the clock.
 *
 * \note Some clocks (eg: FLLs & PLLs) may need to be stopped before their frequency can
 * be changed. This function will take care of disabling & re-enabling as necessary, however,
 * this can cause a temporary glitch on anything that is running off of the clock at the time.
 * If glitch free operation is required, change the source of any downstream clocks the
 * application before changing the clock frequency.
 *
 * @param[in] clock     The clock object to set the frequency for.
 * @param[in] hz        The frequency, in hertz, to set the clock to.
 * @param[in] tolerance The allowed tolerance from the desired hz that is acceptable, use NULL if no
 *                      tolerance check is required.
 * @return The status of the request to set the clock frequency.
 */
cy_rslt_t mtb_hal_clock_set_frequency(mtb_hal_clock_t* clock, uint32_t hz,
                                      const mtb_hal_clock_tolerance_t* tolerance);


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#ifdef MTB_HAL_CLOCK_IMPL_HEADER
#include MTB_HAL_CLOCK_IMPL_HEADER
#endif /* MTB_HAL_CLOCK_IMPL_HEADER */

/** \} group_hal_clock */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_CLOCK)

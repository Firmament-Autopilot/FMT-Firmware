/***************************************************************************//**
* \file mtb_hal_clock_impl.h
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
 * * Interface for getting and changing clock configuration
 *
 * The clock driver is a single interface designed to allow reading and configuring
 * any clock in the system.
 *
 */

#pragma once

#include "cy_result.h"
#include "mtb_hal_hw_types.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */


/*******************************************************************************
*                           Defines
*******************************************************************************/
/** TODO: Temporarily preserved for backwards compatibility */
#define mtb_hal_clock_interface    mtb_hal_clock_peri_interface


/*******************************************************************************
*                           Enums
*******************************************************************************/


/*******************************************************************************
*                           Structs
*******************************************************************************/
/** Default global interface for peripheral clocks */
extern const mtb_hal_clock_interface_t mtb_hal_clock_peri_interface;

/** Default global interface for high freqeuncy clocks */
extern const mtb_hal_clock_interface_t mtb_hal_clock_hf_interface;

/*******************************************************************************
*                          Function Pointers
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/** Gets the frequency in hertz the peripheral clock is currently operating at.
 *
 * @param[in] clk               Clock reference. For peri clock, expected clock
 *                              object is of type mtb_hal_peri_div_t*
 *
 * @return The frequency the clock is currently running at
 */
uint32_t mtb_hal_clock_get_peri_clock_freq(const void* clk);

/** Update the operating frequency of the peripheral clock
 *
 * @param[in] clk               Clock reference. For peri clock, expected clock
 *                              object is of type mtb_hal_peri_div_t*
 * @param[in] frequency         Desired clock frequency
 * @param[in] tolerance_ppm     The allowed tolerance in the units of PPM from the desired frequency
 * that is acceptable ,
 *
 * @return The result of the request to set the clock frequency.
 */
cy_rslt_t mtb_hal_clock_set_peri_clock_freq(const void* clk, uint32_t frequency,
                                            uint32_t tolerance_ppm);

/** Enable/Disable the peripheral clock
 *
 * @param[in] clk               Clock reference. For peri clock, expected clock
 *                              object is of type mtb_hal_peri_div_t*
 * @param[in] enable            true to enable. false to diable
 *
 * @return The result of the enable/disable request
 */
cy_rslt_t mtb_hal_clock_set_peri_clock_enabled(const void* clk, bool enable);
/** Gets the peripheral source clock frequency that is feeding the clock tree for the specified
 * resource.
 *
 * @param[in] clk         Clock reference. For peri clock, expected clock
 *                        object is of type mtb_hal_peri_div_t*
 * @return The peripheral clock frequency for the provided resource type
 */
uint32_t mtb_hal_clock_get_peri_src_clock_freq(const void* clk);

/** Gets the frequency in hertz the high frequency clock is currently operating at.
 *
 * @param[in] clk               Clock reference. For HF clock, expected clock
 *                              object is of type mtb_hal_hf_clock_t*
 *
 * @return The frequency the clock is currently running at
 */
uint32_t mtb_hal_clock_get_hf_clock_freq(const void* clk);

/** Update the operating frequency of the high frequency clock
 * @note currently this operation is not supported and will always return an error
 *
 * @param[in] clk               Clock reference. For HF clock, expected clock
 *                              object is of type mtb_hal_hf_clock_t*
 * @param[in] frequency         Desired clock frequency
 * @param[in] tolerance_ppm     The allowed tolerance in the units of PPM from the desired frequency
 * that is acceptable ,
 *
 * @return The result of the request to set the clock frequency.
 */
cy_rslt_t mtb_hal_clock_set_hf_clock_freq(const void* clk, uint32_t frequency,
                                          uint32_t tolerance_ppm);

/** Enable/Disable the high frequency clock
 *
 * @param[in] clk               Clock reference. For HF clock, expected clock
 *                              object is of type mtb_hal_hf_clock_t*
 * @param[in] enable            true to enable. false to diable
 *
 * @return The result of the enable/disable request
 */
cy_rslt_t mtb_hal_clock_set_hf_clock_enabled(const void* clk, bool enable);

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

/** \} group_hal_clock */

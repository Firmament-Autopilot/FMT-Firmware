/***************************************************************************//**
* \file mtb_hal_adc.h
*
* \brief
* Provides a high level interface for interacting with the Infineon Analog to
* Digital Converter. This interface abstracts out the chip specific details.
* If any chip specific functionality is necessary, or performance is critical
* the low level functions can be used directly.
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
 * \addtogroup group_hal_adc ADC (Analog to Digital Converter)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the analog to digital converter (ADC).
 *
 * \section mtb_hal_adc_features Features
 * Both single-ended and differential channels are supported. The values returned
 * by the read API are relative to the ADC's voltage range, which is device specific.
 * See the BSP documentation for details.
 *
 * \section mtb_hal_adc_quickstart Quickstart
 *   1. Initialize the ADC hardware and channels via PDL call
 *   2. Allocate the memory for the HAL ADC object
 *   3. Set up the HAL ADC using mtb_hal_adc_setup by passing the HAL ADC
 *      object and the pre-initialized ADC structures.
 *
 * \note \ref mtb_hal_adc_read_u16 always returns a 16 bit value in the range
 * 0x0000-0xFFFF. If the underlying hardware does not support 16 bit resolution the
 * value is scaled linearly to cover the full 16 bits.
 *
 * \section subsection_adc_snippets Code snippets
 * \note Error checking is omitted for clarity
 * \subsection subsection_adc_snippet_1 Snippet 1: Simple ADC initialization and reading conversion result
 * The following snippet initializes an ADC and one channel.
 * One ADC conversion result is returned corresponding to the input at the specified
 * pin.
 * \snippet hal_adc.c snippet_mtb_hal_adc_simple_init
 * \subsection subsection_adc_snippet_2 Snippet 2: Single-channel ADC initialization set to start a fresh conversion and read the latest result.
 * \snippet hal_adc.c snippet_mtb_hal_read_latest
 */
//" *RESUME-FORMATTING*"
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"
#include "mtb_hal_gpio.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_ADC)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_adc ADC HAL Results
 *  ADC specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Hardware/Operation is busy */
#define MTB_HAL_ADC_RSLT_ERR_BUSY                         \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_ADC, 1))
/** Unsupported operation */
#define MTB_HAL_ADC_RSLT_ERR_NOT_SUPPORTED                      \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_ADC, 2))
/**
 * \}
 */

/** Enum of ADC filter types that get applied to the acquired ADC data */
typedef enum
{
    MTB_HAL_ADC_FILTER_MEDIAN  = 0, /**< Median filter */
    MTB_HAL_ADC_FILTER_LIF     = 1, /**< Linear interpolation filter */
    MTB_HAL_ADC_FILTER_AVG     = 2, /**< Average filter */
    MTB_HAL_ADC_FILTER_CIC     = 3, /**< Cascaded integrated comb filter */
    MTB_HAL_ADC_FILTER_LPF     = 4  /**< Low pass filter */
} mtb_hal_adc_filter_t;

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj     The HAL driver instance object. The caller must allocate the
 *                     memory for this object, but the HAL will initialize its contents
 * @param[in] config   The configurator-generated HAL config structure for this
 *                     peripheral instance
 * @param[in] clk      Clock instance that clocks this peripheral
 * @param[in] channels Array of channels used by the ADC. Unused channels should be passed as NULL
 * @return the status of the HAL setup
 */
cy_rslt_t mtb_hal_adc_setup(mtb_hal_adc_t* obj, const mtb_hal_adc_configurator_t* config,
                            mtb_hal_clock_t* clk, mtb_hal_adc_channel_t** channels);

/** Read the value from the ADC pin, represented as an unsigned 16bit value
 *  where 0x0000 represents the minimum value in the ADC's range, and 0xFFFF
 *  represents the maximum value in the ADC's range.
 * If continous scanning is disabled, this will block while a conversion is
 *   performed on the selected channel, then return the result. Depending on the
 *   ADC speed this function may block for some time.
 * If continuous scanning is enabled, this will return the value from the most
 *   recent conversion of the specified channel (if called shortly after enabling
 *   continuous scanning it may block until at least one conversion has been performed
 *   on this channel).
 *
 * @param[in] obj The ADC object
 * @return An unsigned 16bit value representing the current input voltage
 */
uint16_t mtb_hal_adc_read_u16(const mtb_hal_adc_channel_t* obj);

/** Returns true if the most recently triggered conversion has completed for the specified channel.
 *
 * If continuous conversion is enabled, returns true if at least one conversion has completed.
 *
 * @param[in] obj          The ADC object
 * @return True if conversion completed, false if still ongoing
 */
bool mtb_hal_adc_is_conversion_complete(const mtb_hal_adc_channel_t* obj);

/** Reads the result of the most recent scan for the specified channel and writes it to the given
 * `result` location.
 *
 * This function will return the latest available value.
 *
 * @param[in] obj          The ADC object
 * @param[out] result      Scanned result
 * @return The status of the read operation
 */
cy_rslt_t mtb_hal_adc_read_latest(const mtb_hal_adc_channel_t* obj, int32_t* result);

/** Read the value from the most recent scan for the specified set of ADC channels and writes it to
 * the array specified by result.
 * If a conversion has not completed for one or more of the specified channels, it will return error
 * and will not update value to the array.
 * "channels" and "result" list must have "num_channels" space in order to get ADC channels and
 * store the results respectively.
 *
 * This function will return the latest available value.
 *
 * @param[in] channels     The ADC channels object pointer
 * @param[in] num_channels The number of ADC channels
 * @param[out] result      Scanned result
 * @return The status of the read operation
 */
cy_rslt_t mtb_hal_adc_read_multiple(mtb_hal_adc_channel_t** channels, uint32_t num_channels,
                                    int32_t* result);

/** Triggers start of conversion for all enabled channels.
 *
 * The function returns without waiting for the conversion to complete.
 *
 * @param[in] obj          The ADC object
 * @return The status of the conversion request
 */
cy_rslt_t mtb_hal_adc_start_convert(mtb_hal_adc_t* obj);

/** Enable/disable the ADC.
 *
 * The function returns without waiting for the enable to complete.
 * Check the ADC status using mtb_hal_adc_is_ready.
 *
 * @param[in] obj          The ADC object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_adc_enable(mtb_hal_adc_t* obj, bool enable);

/** Check if ADC is ready to be used.
 *
 * @param[in] obj          The ADC object
 * @return The status of the ADC ready state
 */
bool mtb_hal_adc_is_ready(mtb_hal_adc_t* obj);

/** Reads the filtered result of the most recent scan for the specified channel and
 * writes it to the given `result` location.
 *
 * This function will return the latest available value.
 *
 * @param[in] obj          The ADC object
 * @param[in] filter       Filter type
 * @param[out] result      Scanned result
 * @return The status of the read operation
 */
cy_rslt_t mtb_hal_adc_read_filtered(const mtb_hal_adc_channel_t* obj, mtb_hal_adc_filter_t filter,
                                    int32_t* result);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_ADC_IMPL_HEADER
#include MTB_HAL_ADC_IMPL_HEADER
#endif /* MTB_HAL_ADC_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_ADC)

/** \} group_hal_adc */

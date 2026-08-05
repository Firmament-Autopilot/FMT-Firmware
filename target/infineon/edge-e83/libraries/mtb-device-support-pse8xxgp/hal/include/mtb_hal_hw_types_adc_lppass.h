/***************************************************************************//**
* \file mtb_hal_hw_types_adc_lppass.h
*
*********************************************************************************
* \copyright
* Copyright(c) 2024-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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

#pragma once

#include "cy_pdl.h"
#include "mtb_hal_hw_types_clock.h"

#if defined(CY_IP_MXS22LPPASS_SAR)
 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_ADC)
/** Macro specifying whether the ADC driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_ADC (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_ADC)

/** \} group_hal_availability */

#if !defined(_MTB_HAL_DRIVER_AVAILABLE_ADC_SAR)
#define _MTB_HAL_DRIVER_AVAILABLE_ADC_SAR (1u)
#endif // !defined(_MTB_HAL_DRIVER_AVAILABLE_ADC_SAR)


#define CY_SAR_MAX_NUM_CHANNELS (PASS_SAR_SAR_GPIO_CHANNELS)

/**
 * @brief ADC object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    struct _mtb_hal_adc_channel_s*      channel_config[CY_SAR_MAX_NUM_CHANNELS];
    /* Intentionally no base pointer, unnecessary for this IP */
    uint32_t                            enabled_channels;
    uint32_t                            enabled_diff;
    uint32_t                            enabled_signed;
    bool                                enabled_continuous;
    const mtb_hal_clock_t*              clock;
    uint8_t                             adc_index;
} mtb_hal_adc_t;


/**
 * @brief ADC configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    /* Intentionally no base pointer, unnecessary for this IP */
    cy_stc_autanalog_sar_t*             config;
    const mtb_hal_clock_t*              clock;
    uint8_t                             num_channels;
    uint8_t                             adc_index;
} mtb_hal_adc_configurator_t;

/**
 * @brief ADC channel object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct _mtb_hal_adc_channel_s   /* Struct given an explicit name to make the forward
                                           declaration above work */
{
    mtb_hal_adc_t*                      adc;
    uint8_t                             channel_idx;
    uint8_t                             channel_msk;
} mtb_hal_adc_channel_t;


#endif // defined(CY_IP_MXS22LPPASS_SAR)

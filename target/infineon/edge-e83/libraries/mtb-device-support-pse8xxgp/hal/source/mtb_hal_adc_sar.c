/***************************************************************************/ /**
 * \file mtb_hal_adc_sar.c
 *
 * \brief
 * Provides a high level interface for interacting with the Cypress Analog/Digital
 * converter. This interface abstracts out the chip specific details. If any chip
 * specific functionality is necessary, or performance is critical the low level
 * functions can be used directly.
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

#include <cmsis_compiler.h>

#include "mtb_hal_adc.h"
#include "mtb_hal_clock.h"
#include "mtb_hal_utils.h"
#include "mtb_hal_system.h"
#include <string.h>

#if (_MTB_HAL_DRIVER_AVAILABLE_ADC_SAR)

#if defined(__cplusplus)
extern "C"
{
#endif

/*******************************************************************************
*       Internal helper functions
*******************************************************************************/

/*******************************************************************************
*       ADC HAL Functions
*******************************************************************************/

cy_rslt_t mtb_hal_adc_setup(mtb_hal_adc_t* obj, const mtb_hal_adc_configurator_t* config,
                            mtb_hal_clock_t* clk, mtb_hal_adc_channel_t** channels)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(config != NULL);
    CY_ASSERT(config->num_channels >= 1);
    CY_ASSERT(channels != NULL);
    #if !defined(_MTB_HAL_ADC_SAR_SKIP_BASE)
    obj->base                   = config->base;
    #endif
    obj->clock                  = (clk == NULL) ? config->clock : clk;

    /* IP-specific setup */
    return _mtb_hal_adc_setup(obj, config, channels);
}


/*******************************************************************************
*       ADC Channel HAL Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// mtb_hal_adc_read_u16
//--------------------------------------------------------------------------------------------------
uint16_t mtb_hal_adc_read_u16(const mtb_hal_adc_channel_t* obj)
{
    int32_t signed_result = _mtb_hal_adc_read(obj);
    return _mtb_hal_adc_counts_to_u16(obj, signed_result);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_adc_read_multiple
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_adc_read_multiple(mtb_hal_adc_channel_t** channels, uint32_t num_channels,
                                    int32_t* result)
{
    /* If one or more ADC channels conversion is not done yet, return busy. */
    for (uint8_t i = 0; i < num_channels; ++i)
    {
        #if defined(MTB_HAL_DISABLE_ERR_CHECK)
        CY_ASSERT_AND_RETURN(_mtb_hal_adc_is_conversion_complete(
                                 channels[i]), MTB_HAL_ADC_RSLT_ERR_BUSY);
        #else
        if (_mtb_hal_adc_is_conversion_complete(channels[i]) == false)
        {
            return MTB_HAL_ADC_RSLT_ERR_BUSY;
        }
        #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
        _mtb_hal_adc_read_latest(channels[i], &result[i]);
    }
    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif /* (_MTB_HAL_DRIVER_AVAILABLE_ADC_SAR) */

/***************************************************************************//**
* \file mtb_hal_adc_mxs22lppass_v1.h
*
* \brief
* Provides common API declarations of the mxs22lppass_v1 driver
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

#pragma once

#include "mtb_hal_adc.h"
#include "mtb_hal_system.h"
#include <stdlib.h>
#include "cy_pdl.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Defines
*******************************************************************************/

#define _MTB_HAL_SAR_MAX_NUM_CHANNELS           \
    (PASS_SAR_SAR_GPIO_CHANNELS)
#define _MTB_HAL_ADC_SAR_SKIP_BASE

/*******************************************************************************
*                           Typedefs
*******************************************************************************/

typedef void* _MTB_HAL_ADC_SAR_Type;


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/*******************************************************************************
*       Inlined functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_setup
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_adc_setup(mtb_hal_adc_t* obj,
                                             const mtb_hal_adc_configurator_t* config,
                                             mtb_hal_adc_channel_t** channels)
{
    cy_rslt_t status = CY_RSLT_SUCCESS;
    uint32_t enabled_channels = 0;
    uint32_t enabled_diff = 0;
    uint32_t enabled_signed = 0;
    bool enabled_continuous = true;
    mtb_hal_adc_channel_t* channel;

    for (uint8_t cnt = 0; cnt < _MTB_HAL_SAR_MAX_NUM_CHANNELS; cnt++)
    {
        if (config->config->sarStaCfg->hsStaCfg->hsGpioChan[cnt] != NULL)
        {
            enabled_channels |= (uint32_t)(1u << cnt);

            if (config->config->sarStaCfg->hsStaCfg->hsGpioChan[cnt]->hsDiffEn == true)
            {
                enabled_diff |= (uint32_t)(1u << cnt);
            }
            if (config->config->sarStaCfg->hsStaCfg->hsGpioChan[cnt]->sign == true)
            {
                enabled_signed |= (uint32_t)(1u << cnt);
            }

            // It is possible to have channels array that is smaller than supported channels
            if ((cnt < config->num_channels) && (channels[cnt] != NULL))
            {
                channel = channels[cnt];
                memset(channel, 0, sizeof(mtb_hal_adc_channel_t));
                channel->adc = obj;
                channel->channel_idx = cnt;
                channel->channel_msk = (uint32_t)(1UL << cnt);
                obj->channel_config[cnt] = channel;
            }
            else
            {
                obj->channel_config[cnt] = NULL;
            }
        }
        else
        if ((config->config->hsSeqTabArr[cnt - 1].nextAction ==
             CY_AUTANALOG_SAR_NEXT_ACTION_STATE_STOP)
            && (cnt > 0))
        {
            enabled_continuous = false;
        }
    }

    obj->adc_index = config->adc_index;
    obj->enabled_channels = enabled_channels;
    obj->enabled_diff = enabled_diff;
    obj->enabled_signed = enabled_signed;
    obj->enabled_continuous = enabled_continuous;

    return status;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_is_conversion_complete
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_adc_is_conversion_complete(const mtb_hal_adc_channel_t* obj)
{
    return ((obj->channel_msk && Cy_AutAnalog_SAR_GetHSchanResultStatus(obj->adc->adc_index)) > 0);
}


#define mtb_hal_adc_is_conversion_complete(obj)  _mtb_hal_adc_is_conversion_complete(obj)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_start_convert
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_adc_start_convert(mtb_hal_adc_t* obj)
{
    if (!obj->enabled_continuous)
    {
        Cy_AutAnalog_SAR_ClearHSchanResultStatus(obj->adc_index, obj->enabled_channels);
        Cy_AutAnalog_StartAutonomousControl();
    }
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_adc_start_convert(obj) _mtb_hal_adc_start_convert(obj)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_read_latest
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_adc_read_latest(const mtb_hal_adc_channel_t* obj,
                                                   int32_t* result)
{
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(_mtb_hal_adc_is_conversion_complete(obj), MTB_HAL_ADC_RSLT_ERR_BUSY);
    #else
    if (!_mtb_hal_adc_is_conversion_complete(obj))
    {
        return MTB_HAL_ADC_RSLT_ERR_BUSY;
    }
    else
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        *result = Cy_AutAnalog_SAR_ReadResult(obj->adc->adc_index,
                                              CY_AUTANALOG_SAR_INPUT_GPIO, obj->channel_idx);
        return CY_RSLT_SUCCESS;
    }
}


#define mtb_hal_adc_read_latest(obj, result) _mtb_hal_adc_read_latest(obj, result)

//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_read
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE int32_t _mtb_hal_adc_read(const mtb_hal_adc_channel_t* obj)
{
    int32_t latest = 0;
    uint32_t timeout = 1000UL;

    Cy_AutAnalog_SAR_ClearHSchanResultStatus(obj->adc->adc_index, obj->channel_idx);
    _mtb_hal_adc_start_convert(obj->adc);
    while ((!_mtb_hal_adc_is_conversion_complete(obj)) && (timeout != 0))
    {
        mtb_hal_system_delay_us(1);
        timeout--;
    }

    CY_ASSERT(timeout > 0);

    (void)_mtb_hal_adc_read_latest(obj, &latest);

    return latest;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_counts_to_u16
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE uint16_t _mtb_hal_adc_counts_to_u16(const mtb_hal_adc_channel_t* obj,
                                                    int32_t signed_result)
{
    const uint8_t RESULT_SCALING_FACTOR = UINT16_MAX / 0xFFF; // constant 12-bit SAR resolution
    uint16_t unsigned_result;

    if (((obj->adc->enabled_signed) & (uint32_t)(1u << obj->channel_idx)) != 0u)
    {
        /* An unsigned value will range from 0 to vref * 2, rather than -vref to vref. Offset
           accordingly */
        unsigned_result = (uint16_t)(signed_result + 0x800);
    }
    else
    {
        /* Safe to cast from int32_t to uint16_t, as signed_result is actually unsigned. */
        unsigned_result = (uint16_t)signed_result;
    }

    /* The SAR provides a 12-bit result, but this API is defined to fill a full 16-bit range */
    uint16_t scaled_result = ((uint16_t)unsigned_result) * RESULT_SCALING_FACTOR;

    return scaled_result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_enable
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_adc_enable(mtb_hal_adc_t* obj, bool enable)
{
    CY_UNUSED_PARAMETER(obj);
    enable ? Cy_AutAnalog_Enable() : Cy_AutAnalog_Disable();
    return CY_RSLT_SUCCESS;
}


#define mtb_hal_adc_enable  _mtb_hal_adc_enable

//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_is_ready
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_adc_is_ready(mtb_hal_adc_t* obj)
{
    CY_UNUSED_PARAMETER(obj);
    return Cy_AutAnalog_IsBusy();
}


#define mtb_hal_adc_is_ready _mtb_hal_adc_is_ready

//--------------------------------------------------------------------------------------------------
// _mtb_hal_adc_read_filtered
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_adc_read_filtered(const mtb_hal_adc_channel_t* obj,
                                                     mtb_hal_adc_filter_t filter, int32_t* result)
{
    CY_UNUSED_PARAMETER(obj);
    CY_UNUSED_PARAMETER(filter);
    CY_UNUSED_PARAMETER(result);
    return MTB_HAL_ADC_RSLT_ERR_NOT_SUPPORTED;
}


#define mtb_hal_adc_read_filtered _mtb_hal_adc_read_filtered

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

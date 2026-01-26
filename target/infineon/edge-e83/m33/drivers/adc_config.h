/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef __ADC_CONFIG_H__
#define __ADC_CONFIG_H__

#include "cy_autanalog.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BSP_USING_ADC1)

struct ifx_sar_adc_config
{
    uint8_t  sar_idx;        /* SAR index */
    uint8_t  sequencer;      /* SAR sequencer */
    uint8_t  channel;        /* GPIO: 0~7, MUX: 0~15 */
    bool     low_power;      /* false: HS, true: LP */
    cy_en_autanalog_sar_input_t input;
    uint32_t vref_mv;        /* Reference voltage (mV) */
};

static const struct ifx_sar_adc_config adc1_cfg =
{
    .sar_idx    = 0,
    .sequencer = 0,
    .channel   = 0,
    .input     = CY_AUTANALOG_SAR_INPUT_GPIO,
    .low_power = false,
    .vref_mv   = 1800,
};

#define ADC1_CONFIG        \
{                          \
    .cfg  = &adc1_cfg,     \
    .name = "adc1",        \
}

#endif /* BSP_USING_ADC1 */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_CONFIG_H__ */

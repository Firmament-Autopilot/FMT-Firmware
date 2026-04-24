/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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
#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ADC channel count: P15[4], P15[5], P15[6], P15[7] => GPIO4-GPIO7 */
#define ADC0_CHANNEL_NUM 4

/* Logical-to-physical GPIO channel mapping table
 * Logical channel 0 (BAT1_V) => SAR GPIO channel 4 (P15[4])
 * Logical channel 1 (BAT1_I) => SAR GPIO channel 5 (P15[5])
 * Logical channel 2 (BAT2_V) => SAR GPIO channel 6 (P15[6])
 * Logical channel 3 (BAT2_I) => SAR GPIO channel 7 (P15[7])
 */
#define ADC0_CH0_GPIO  4  /* P15[4] */
#define ADC0_CH1_GPIO  5  /* P15[5] */
#define ADC0_CH2_GPIO  6  /* P15[6] */
#define ADC0_CH3_GPIO  7  /* P15[7] */

#if defined(BSP_USING_ADC0)

struct ifx_sar_adc_config {
    uint8_t sar_idx;
    uint8_t sequencer;
    uint8_t num_channels;
    bool low_power;
    cy_en_autanalog_sar_input_t input;
    uint32_t vref_mv;
    const uint8_t* channel_map;  /* logical channel -> physical GPIO channel */
};

/* Physical GPIO channel mapping: logical ch 0-3 => GPIO 4-7 */
static const uint8_t adc0_channel_map[ADC0_CHANNEL_NUM] = {
    ADC0_CH0_GPIO,  /* logical 0 -> GPIO4 (P15[4]) */
    ADC0_CH1_GPIO,  /* logical 1 -> GPIO5 (P15[5]) */
    ADC0_CH2_GPIO,  /* logical 2 -> GPIO6 (P15[6]) */
    ADC0_CH3_GPIO,  /* logical 3 -> GPIO7 (P15[7]) */
};

static const struct ifx_sar_adc_config adc0_cfg = {
    .sar_idx = 0,
    .sequencer = 0,
    .num_channels = ADC0_CHANNEL_NUM,
    .input = CY_AUTANALOG_SAR_INPUT_GPIO,
    .low_power = false,
    .vref_mv = 1800,
    .channel_map = adc0_channel_map,
};

    #define ADC0_CONFIG       \
        {                     \
            .cfg = &adc0_cfg, \
            .name = "adc0",   \
        }

#endif /* BSP_USING_ADC0 */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_CONFIG_H__ */
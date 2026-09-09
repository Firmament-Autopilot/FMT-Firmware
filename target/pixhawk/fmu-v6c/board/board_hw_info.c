/******************************************************************************
 * Copyright 2026 The Firmament Authors. All Rights Reserved.
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

#include "board.h"

#include <stddef.h>

#define HW_ID_SAMPLE_COUNT       16U
#define HW_ID_ADC_TIMEOUT_MS     10U
#define HW_ID_ADC_FULL_SCALE     65535U
#define HW_ID_ADC_12BIT_SHIFT    4U
#define HW_ID_PRESENT_THRESHOLD ((HW_ID_ADC_FULL_SCALE * 975U) / 1000U)

extern ADC_HandleTypeDef hadc3;

static uint8_t dn_to_ordinal(uint32_t dn)
{
    static const uint16_t upper_bound[] = {
        0, 579, 967, 1356, 1756, 2137, 2519, 2919, 3308, 3699, 4095
    };

    for (uint8_t id = 0; id < sizeof(upper_bound) / sizeof(upper_bound[0]); id++) {
        if (dn <= upper_bound[id]) {
            return id;
        }
    }

    return 0;
}

static rt_err_t adc3_sample(uint32_t channel, uint32_t* sample)
{
    ADC_ChannelConfTypeDef config = { 0 };
    uint32_t sum = 0;

    config.Channel = channel;
    config.Rank = ADC_REGULAR_RANK_1;
    config.SamplingTime = ADC_SAMPLETIME_64CYCLES_5;
    config.SingleDiff = ADC_SINGLE_ENDED;
    config.OffsetNumber = ADC_OFFSET_NONE;
    config.Offset = 0;
    config.OffsetSignedSaturation = DISABLE;

    if (HAL_ADC_ConfigChannel(&hadc3, &config) != HAL_OK) {
        return -RT_ERROR;
    }

    for (uint32_t i = 0; i < HW_ID_SAMPLE_COUNT; i++) {
        if (HAL_ADC_Start(&hadc3) != HAL_OK) {
            return -RT_ERROR;
        }

        if (HAL_ADC_PollForConversion(&hadc3, HW_ID_ADC_TIMEOUT_MS) != HAL_OK) {
            HAL_ADC_Stop(&hadc3);
            return -RT_ETIMEOUT;
        }

        sum += HAL_ADC_GetValue(&hadc3);
        HAL_ADC_Stop(&hadc3);
    }

    *sample = sum / HW_ID_SAMPLE_COUNT;
    return RT_EOK;
}

static rt_err_t read_id_dn(uint32_t channel, uint32_t* dn)
{
    uint32_t high;
    uint32_t low;
    rt_err_t err;

    HAL_GPIO_WritePin(HW_VER_REV_DRIVE_GPIO_Port, HW_VER_REV_DRIVE_Pin, GPIO_PIN_SET);
    rt_thread_mdelay(1);
    err = adc3_sample(channel, &high);

    if (err != RT_EOK) {
        return err;
    }

    HAL_GPIO_WritePin(HW_VER_REV_DRIVE_GPIO_Port, HW_VER_REV_DRIVE_Pin, GPIO_PIN_RESET);
    rt_thread_mdelay(1);
    err = adc3_sample(channel, &low);

    /* The identification network expects the common drive pin to idle high. */
    HAL_GPIO_WritePin(HW_VER_REV_DRIVE_GPIO_Port, HW_VER_REV_DRIVE_Pin, GPIO_PIN_SET);

    if (err != RT_EOK) {
        return err;
    }

    /* With no identification resistors fitted, the high sample does not reach
       full scale. PX4 defines that condition as hardware ID zero. */
    *dn = (high > low && high > HW_ID_PRESENT_THRESHOLD)
        ? (low >> HW_ID_ADC_12BIT_SHIFT)
        : 0;

    return RT_EOK;
}

rt_err_t board_determine_hw_info(board_hw_info_t* info)
{
    GPIO_InitTypeDef gpio = { 0 };
    uint32_t dn;
    rt_err_t err;

    if (info == NULL) {
        return -RT_EINVAL;
    }

    __HAL_RCC_GPIOE_CLK_ENABLE();

    gpio.Pin = HW_VER_REV_DRIVE_Pin;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(HW_VER_REV_DRIVE_GPIO_Port, &gpio);
    HAL_GPIO_WritePin(HW_VER_REV_DRIVE_GPIO_Port, HW_VER_REV_DRIVE_Pin, GPIO_PIN_SET);

    hadc3.Instance = ADC3;
    hadc3.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV4;
    hadc3.Init.Resolution = ADC_RESOLUTION_16B;
    hadc3.Init.ScanConvMode = ADC_SCAN_DISABLE;
    hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    hadc3.Init.LowPowerAutoWait = DISABLE;
    hadc3.Init.ContinuousConvMode = DISABLE;
    hadc3.Init.NbrOfConversion = 1;
    hadc3.Init.DiscontinuousConvMode = DISABLE;
    hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc3.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
    hadc3.Init.Overrun = ADC_OVR_DATA_PRESERVED;
    hadc3.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
    hadc3.Init.OversamplingMode = DISABLE;

    if (HAL_ADC_Init(&hadc3) != HAL_OK
        || HAL_ADCEx_Calibration_Start(&hadc3, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK) {
        return -RT_ERROR;
    }

    err = read_id_dn(ADC_CHANNEL_10, &dn);
    if (err != RT_EOK) {
        return err;
    }
    info->revision = dn_to_ordinal(dn);

    err = read_id_dn(ADC_CHANNEL_11, &dn);
    if (err != RT_EOK) {
        return err;
    }
    info->version = dn_to_ordinal(dn);

    return RT_EOK;
}

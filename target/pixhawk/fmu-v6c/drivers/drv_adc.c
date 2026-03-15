/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include <firmament.h>

#include "drv_adc.h"
#include "hal/adc/adc.h"
#include "stm32h7xx_hal.h"

#define ADC_CONVERSION_TIMEOUT_MS 10

struct stm32_adc {
    ADC_HandleTypeDef* adc_handle;
};

static struct stm32_adc stm_adc1;
static struct adc_device adc1;
static ADC_HandleTypeDef hadc1;
static struct rt_completion convert_cplt;

/* ADC interrupt handler */
void ADC_IRQHandler(void)
{
    /* Enter interrupt */
    rt_interrupt_enter();

    /* Call HAL ADC IRQ handler */
    HAL_ADC_IRQHandler(&hadc1);

    /* Leave interrupt */
    rt_interrupt_leave();
}

/* ADC conversion complete callback */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if (hadc->Instance == ADC1) {
        /* Signal conversion complete */
        rt_completion_done(&convert_cplt);
    }
}

static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;
    ADC_ChannelConfTypeDef sConfig = { 0 };
    uint32_t adc_channel;
    uint32_t adcData;

    if (adc->adc_handle->Instance != ADC1) {
        return RT_EINVAL;
    }

    /* Map logical channel to physical ADC channel */
    switch (channel) {
    case 0: /* ADC1_INP4  - PC4 */
        adc_channel = ADC_CHANNEL_4;
        break;
    case 1: /* ADC1_INP5  - PB1 */
        adc_channel = ADC_CHANNEL_5;
        break;
    case 2: /* ADC1_INP8  - PC5 */
        adc_channel = ADC_CHANNEL_8;
        break;
    case 3: /* ADC1_INP14 - PA2 */
        adc_channel = ADC_CHANNEL_14;
        break;
    case 4: /* ADC1_INP18 - PA4 (VBAT sense) */
        adc_channel = ADC_CHANNEL_18;
        break;
    default:
        return RT_EINVAL;
    }

    /* Configure ADC channel */
    sConfig.Channel = adc_channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_64CYCLES_5;
    sConfig.SingleDiff = ADC_SINGLE_ENDED;
    sConfig.OffsetNumber = ADC_OFFSET_NONE;
    sConfig.Offset = 0;
    sConfig.OffsetSignedSaturation = DISABLE;

    if (HAL_ADC_ConfigChannel(adc->adc_handle, &sConfig) != HAL_OK) {
        return RT_ERROR;
    }

    /* Start ADC conversion with interrupt */
    if (HAL_ADC_Start_IT(adc->adc_handle) != HAL_OK) {
        return RT_ERROR;
    }

    /* Wait for conversion complete */
    if (rt_completion_wait(&convert_cplt, rt_tick_from_millisecond(ADC_CONVERSION_TIMEOUT_MS)) != RT_EOK) {
        HAL_ADC_Stop_IT(adc->adc_handle);
        return RT_ETIMEOUT;
    }

    /* Get ADC value */
    adcData = HAL_ADC_GetValue(adc->adc_handle);

    /* Convert to millivolts
     * STM32H7 ADC: 16-bit resolution with 4-bit right shift (12-bit effective)
     * VREFINT = 3300mV
     */
    *mVolt = (adcData * 3300) / 65535;

    return RT_EOK;
}

static rt_err_t adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle->Instance != ADC1) {
        return RT_EINVAL;
    }

    if (enable == ADC_CMD_ENABLE) {
        /* Calibration */
        if (HAL_ADCEx_Calibration_Start(adc->adc_handle, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK) {
            return RT_ERROR;
        }
        /* ADC is automatically enabled after calibration */
        sys_msleep(10); /* Stabilization time */
    } else if (enable == ADC_CMD_DISABLE) {
        HAL_ADC_Stop(adc->adc_handle);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t adc_hw_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };

    /* Configure ADC clock */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
    PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_CLKP;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
        return RT_ERROR;
    }

    /* Enable ADC1 clock */
    __HAL_RCC_ADC12_CLK_ENABLE();

    /* Enable GPIO clocks */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /* Configure GPIO pins for ADC
     * PA4 -> ADC1_INP18 (VBAT sense)
     * PC4 -> ADC1_INP4
     * PC5 -> ADC1_INP8
     * PA2 -> ADC1_INP14
     * PB1 -> ADC1_INP5
     */
    GPIO_InitStruct.Pin = GPIO_PIN_4 | GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_4 | GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Configure ADC1 */
    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV4;
    hadc1.Init.Resolution = ADC_RESOLUTION_16B;
    hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    hadc1.Init.LowPowerAutoWait = DISABLE;
    hadc1.Init.ContinuousConvMode = DISABLE;
    hadc1.Init.NbrOfConversion = 1;
    hadc1.Init.DiscontinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
    hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
    hadc1.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
    hadc1.Init.OversamplingMode = ENABLE;
    hadc1.Init.Oversampling.Ratio = 16;
    hadc1.Init.Oversampling.RightBitShift = ADC_RIGHTBITSHIFT_4;
    hadc1.Init.Oversampling.TriggeredMode = ADC_TRIGGEREDMODE_SINGLE_TRIGGER;
    hadc1.Init.Oversampling.OversamplingStopReset = ADC_REGOVERSAMPLING_CONTINUED_MODE;

    if (HAL_ADC_Init(&hadc1) != HAL_OK) {
        return RT_ERROR;
    }

    /* Enable ADC interrupt */
    HAL_NVIC_SetPriority(ADC_IRQn, 7, 0);
    HAL_NVIC_EnableIRQ(ADC_IRQn);

    return RT_EOK;
}

/* ADC driver operations */
static const struct adc_ops _adc_ops = {
    .enable = adc_enable,
    .measure = adc_measure
};

rt_err_t drv_adc_init(void)
{
    rt_err_t ret;

    /* Initialize hardware */
    ret = adc_hw_init();
    if (ret != RT_EOK) {
        return ret;
    }

    /* Initialize completion */
    rt_completion_init(&convert_cplt);

    /* Setup ADC device structure */
    stm_adc1.adc_handle = &hadc1;
    adc1.ops = &_adc_ops;

    /* Register ADC device */
    return hal_adc_register(&adc1, "adc0", RT_DEVICE_FLAG_RDONLY, &stm_adc1);
}

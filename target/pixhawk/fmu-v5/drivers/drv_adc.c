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
#include "stm32f7xx_ll_adc.h"

#define ADC_CONVERSION_TIMEOUT_MS 2

struct stm32_adc {
    ADC_TypeDef* adc_handle;
} stm_adc1 = {
    .adc_handle = ADC1
};

static struct adc_device adc1;
static struct rt_completion convert_cplt;

void ADC_IRQHandler(void)
{
    /* Check whether ADC group regular end of unitary conversion caused         */
    /* the ADC interruption.                                                    */
    /* Note: On this STM32 serie, ADC group regular end of conversion           */
    /*       must be selected among end of unitary conversion                   */
    /*       or end of sequence conversions.                                    */
    /*       Refer to function "LL_ADC_REG_SetFlagEndOfConversion()".           */
    if (LL_ADC_IsActiveFlag_EOCS(ADC1) != 0) {
        /* Clear flag ADC group regular end of unitary conversion */
        LL_ADC_ClearFlag_EOCS(ADC1);

        /* inform the completion of adc convertion */
        rt_completion_done(&convert_cplt);
    }

    /* Check whether ADC group regular overrun caused the ADC interruption */
    if (LL_ADC_IsActiveFlag_OVR(ADC1) != 0) {
        /* Clear flag ADC group regular overrun */
        LL_ADC_ClearFlag_OVR(ADC1);

        /* TODO: data is lost, maybe we can inform the waiting thread */
    }
}

static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    uint32_t adc_channel;
    uint16_t adcData;
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle != ADC1) {
        return RT_EINVAL;
    }

    switch (channel) {
    case 0:
        adc_channel = LL_ADC_CHANNEL_0;
        break;
    case 1:
        adc_channel = LL_ADC_CHANNEL_1;
        break;
    case 2:
        adc_channel = LL_ADC_CHANNEL_2;
        break;
    case 3:
        adc_channel = LL_ADC_CHANNEL_3;
        break;
    case 4:
        adc_channel = LL_ADC_CHANNEL_4;
        break;
    case 8:
        adc_channel = LL_ADC_CHANNEL_8;
        break;
    case 10:
        adc_channel = LL_ADC_CHANNEL_10;
        break;
    case 11:
        adc_channel = LL_ADC_CHANNEL_11;
        break;
    case 12:
        adc_channel = LL_ADC_CHANNEL_12;
        break;
    case 13:
        adc_channel = LL_ADC_CHANNEL_13;
        break;
    case 14:
        adc_channel = LL_ADC_CHANNEL_14;
        break;
    default:
        return RT_EINVAL;
    }

    LL_ADC_REG_SetSequencerRanks(adc->adc_handle, LL_ADC_REG_RANK_1, adc_channel);
    LL_ADC_SetChannelSamplingTime(adc->adc_handle, adc_channel, LL_ADC_SAMPLINGTIME_56CYCLES);

    LL_ADC_REG_StartConversionSWStart(adc->adc_handle);

    if (rt_completion_wait(&convert_cplt, TICKS_FROM_MS(ADC_CONVERSION_TIMEOUT_MS)) != RT_EOK) {
        return RT_ERROR;
    }

    adcData = LL_ADC_REG_ReadConversionData12(adc->adc_handle);
    *mVolt = __LL_ADC_CALC_DATA_TO_VOLTAGE(3300, adcData, LL_ADC_RESOLUTION_12B);

    return RT_EOK;
}

static rt_err_t adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle != ADC1) {
        return RT_EINVAL;
    }

    if (enable == ADC_CMD_ENABLE) {
        LL_ADC_Enable(adc->adc_handle);
        /* the ADC needs a stabilization time of tSTAB 
         * before it starts converting accurately 
         */
        sys_msleep(1);
    } else if (enable == ADC_CMD_DISABLE) {
        LL_ADC_Disable(adc->adc_handle);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t adc_hw_init(void)
{
    LL_ADC_InitTypeDef ADC_InitStruct = { 0 };
    LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = { 0 };
    LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = { 0 };

    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    /* Peripheral clock enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC1);

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    /**ADC1 GPIO Configuration
  PC0   ------> ADC1_IN10
  PC1   ------> ADC1_IN11
  PC2   ------> ADC1_IN12
  PC3   ------> ADC1_IN13
  PA1   ------> ADC1_IN1
  PA0/WKUP   ------> ADC1_IN0
  PA4   ------> ADC1_IN4
  PC4   ------> ADC1_IN14
  PA2   ------> ADC1_IN2
  PA3   ------> ADC1_IN3
  PB0   ------> ADC1_IN8
  */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_3;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* ADC1 interrupt Init */
    NVIC_SetPriority(ADC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(ADC_IRQn);

    /** Common config
  */
    ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
    ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
    ADC_InitStruct.SequencersScanMode = LL_ADC_SEQ_SCAN_DISABLE;
    LL_ADC_Init(ADC1, &ADC_InitStruct);
    ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
    ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
    ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_NONE;
    LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
    LL_ADC_REG_SetFlagEndOfConversion(ADC1, LL_ADC_REG_FLAG_EOC_UNITARY_CONV);
    ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV4;
    ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
    LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1), &ADC_CommonInitStruct);
    /** Configure Regular Channel
  */
    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_0);
    LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_0, LL_ADC_SAMPLINGTIME_3CYCLES);

    return RT_EOK;
}

static void adc_interrupt_configure(struct stm32_adc* adc)
{
    /* Enable  ADC interruptions */
    LL_ADC_EnableIT_EOCS(adc->adc_handle);
    LL_ADC_EnableIT_OVR(adc->adc_handle);
}

/* usart driver operations */
static const struct adc_ops _adc_ops = {
    .enable = adc_enable,
    .measure = adc_measure
};

rt_err_t drv_adc_init(void)
{
    RT_CHECK(adc_hw_init());

    adc_interrupt_configure(&stm_adc1);

    rt_completion_init(&convert_cplt);

    adc1.ops = &_adc_ops;

    return hal_adc_register(&adc1, "adc0", RT_DEVICE_FLAG_RDONLY, &stm_adc1);
}
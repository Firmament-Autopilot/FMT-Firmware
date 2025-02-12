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

#define ADC_ENABLE 1

#if ADC_ENABLE == 1

    #include "drv_adc.h"
    #include "hal/adc/adc.h"
    #include "stm32h7xx_ll_adc.h"

    #define ADC_CONVERSION_TIMEOUT_MS 2

struct stm32_adc {
    ADC_TypeDef* adc_handle;
} stm_adc3 = { .adc_handle = ADC3 };

static struct adc_device adc0;
static struct rt_completion convert_cplt;

void ADC3_IRQHandler(void)
{
    /* Check whether ADC group regular end of unitary conversion caused         */
    /* the ADC interruption.                                                    */
    /* Note: On this STM32 serie, ADC group regular end of conversion           */
    /*       must be selected among end of unitary conversion                   */
    /*       or end of sequence conversions.                                    */
    /*       Refer to function "LL_ADC_REG_SetFlagEndOfConversion()".           */
    if (LL_ADC_IsActiveFlag_EOC(ADC3) != 0) {
        /* Clear flag ADC group regular end of unitary conversion */
        LL_ADC_ClearFlag_EOC(ADC3);

        /* inform the completion of adc convertion */
        rt_completion_done(&convert_cplt);
    }

    /* Check whether ADC group regular overrun caused the ADC interruption */
    if (LL_ADC_IsActiveFlag_OVR(ADC3) != 0) {
        /* Clear flag ADC group regular overrun */
        LL_ADC_ClearFlag_OVR(ADC3);

        /* TODO: data is lost, maybe we can inform the waiting thread */
    }
}

static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    uint32_t adc_channel;
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle != ADC3) {
        return RT_EINVAL;
    }

    switch (channel) {
    case 0:
        /* Bat1 Volt */
        adc_channel = LL_ADC_CHANNEL_14;
        break;
    case 1:
        /* Bat1 Current */
        adc_channel = LL_ADC_CHANNEL_13;
        break;
    case 2:
        /* Bat2 Volt */
        adc_channel = LL_ADC_CHANNEL_16;
        break;
    case 3:
        /* Bat2 Current */
        adc_channel = LL_ADC_CHANNEL_15;
        break;
    default:
        return RT_EINVAL;
    }

    LL_ADC_REG_SetSequencerRanks(adc->adc_handle, LL_ADC_REG_RANK_1, adc_channel);
    LL_ADC_SetChannelSamplingTime(adc->adc_handle, adc_channel, LL_ADC_SAMPLINGTIME_32CYCLES_5);

    LL_ADC_REG_StartConversion(adc->adc_handle);

    if (rt_completion_wait(&convert_cplt, TICKS_FROM_MS(ADC_CONVERSION_TIMEOUT_MS)) != RT_EOK) {
        return RT_ERROR;
    }

    uint16_t adcData = LL_ADC_REG_ReadConversionData16(adc->adc_handle);
    *mVolt = __LL_ADC_CALC_DATA_TO_VOLTAGE(3300, adcData, LL_ADC_RESOLUTION_16B);

    return RT_EOK;
}

static rt_err_t adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle != ADC3) {
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

    LL_RCC_SetADCClockSource(LL_RCC_ADC_CLKSOURCE_PLL2P);

    /* Peripheral clock enable */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_ADC3);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOH);
    /**ADC3 GPIO Configuration
    PH2   ------> ADC3_INP13
    PH3   ------> ADC3_INP14
    PH4   ------> ADC3_INP15
    PH5   ------> ADC3_INP16
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_2 | LL_GPIO_PIN_3 | LL_GPIO_PIN_4 | LL_GPIO_PIN_5;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    /* ADC3 interrupt Init */
    NVIC_SetPriority(ADC3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(ADC3_IRQn);

    /** Common config
     */
    LL_ADC_SetOverSamplingScope(ADC3, LL_ADC_OVS_DISABLE);
    ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_16B;
    ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
    LL_ADC_Init(ADC3, &ADC_InitStruct);
    ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = DISABLE;
    ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
    ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_PRESERVED;
    LL_ADC_REG_Init(ADC3, &ADC_REG_InitStruct);
    ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
    LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC3), &ADC_CommonInitStruct);

    /* Disable ADC deep power down (enabled by default after reset state) */
    LL_ADC_DisableDeepPowerDown(ADC3);
    /* Enable ADC internal voltage regulator */
    LL_ADC_EnableInternalRegulator(ADC3);
    /* Delay for ADC internal voltage regulator stabilization. */
    /* Compute number of CPU cycles to wait for, from delay in us. */
    /* Note: Variable divided by 2 to compensate partially */
    /* CPU processing cycles (depends on compilation optimization). */
    /* Note: If system core clock frequency is below 200kHz, wait time */
    /* is only a few CPU processing cycles. */
    __IO uint32_t wait_loop_index;
    wait_loop_index = ((LL_ADC_DELAY_INTERNAL_REGUL_STAB_US * (SystemCoreClock / (100000 * 2))) / 10);
    while (wait_loop_index != 0) {
        wait_loop_index--;
    }

    /** Configure Regular Channel
     */
    LL_ADC_REG_SetSequencerRanks(ADC3, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_16);
    LL_ADC_SetChannelSamplingTime(ADC3, LL_ADC_CHANNEL_16, LL_ADC_SAMPLINGTIME_1CYCLE_5);
    LL_ADC_SetChannelSingleDiff(ADC3, LL_ADC_CHANNEL_16, LL_ADC_SINGLE_ENDED);

    return RT_EOK;
}

static void adc_interrupt_configure(struct stm32_adc* adc)
{
    /* Enable ADC interruptions */
    LL_ADC_EnableIT_EOC(adc->adc_handle);
    LL_ADC_EnableIT_OVR(adc->adc_handle);
}

/* usart driver operations */
static const struct adc_ops _adc_ops = { .enable = adc_enable, .measure = adc_measure };

#endif

rt_err_t drv_adc_init(void)
{
#if ADC_ENABLE == 1
    RT_TRY(adc_hw_init());

    adc_interrupt_configure(&stm_adc3);

    rt_completion_init(&convert_cplt);

    adc0.ops = &_adc_ops;

    return hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, &stm_adc3);
#else
    return RT_EOK;
#endif
}
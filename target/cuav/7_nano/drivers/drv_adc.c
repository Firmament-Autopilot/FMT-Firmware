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
#include "stm32h7xx_ll_adc.h"

#define ADC_CONVERSION_TIMEOUT_MS 2

struct stm32_adc {
    ADC_TypeDef* adc_handle;
    struct rt_completion convert_cplt;
} stm_adc1 = { .adc_handle = ADC1 }, stm_adc3 = { .adc_handle = ADC3 };

static struct adc_device adc0;
// static struct adc_device adc1;

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
        rt_completion_done(&stm_adc3.convert_cplt);
    }

    /* Check whether ADC group regular overrun caused the ADC interruption */
    if (LL_ADC_IsActiveFlag_OVR(ADC3) != 0) {
        /* Clear flag ADC group regular overrun */
        LL_ADC_ClearFlag_OVR(ADC3);

        /* TODO: data is lost, maybe we can inform the waiting thread */
    }
}

void ADC_IRQHandler(void)
{
    /* Check whether ADC group regular end of unitary conversion caused         */
    /* the ADC interruption.                                                    */
    /* Note: On this STM32 serie, ADC group regular end of conversion           */
    /*       must be selected among end of unitary conversion                   */
    /*       or end of sequence conversions.                                    */
    /*       Refer to function "LL_ADC_REG_SetFlagEndOfConversion()".           */
    if (LL_ADC_IsActiveFlag_EOC(ADC1) != 0) {
        /* Clear flag ADC group regular end of unitary conversion */
        LL_ADC_ClearFlag_EOC(ADC1);

        /* inform the completion of adc convertion */
        rt_completion_done(&stm_adc1.convert_cplt);
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
    ADC_TypeDef* adc_handle;
    struct rt_completion* adc_cplt;

    if (adc_dev == &adc0) {
        switch (channel) {
        case BAT1_V_CHANNEL:
            /* Bat1 Volt */
            adc_channel = LL_ADC_CHANNEL_0;
            adc_handle = stm_adc3.adc_handle;
            adc_cplt = &stm_adc3.convert_cplt;
            break;
        case BAT1_I_CHANNEL:
            /* Bat1 Current */
            adc_channel = LL_ADC_CHANNEL_9;
            adc_handle = stm_adc1.adc_handle;
            adc_cplt = &stm_adc1.convert_cplt;
            break;
        default:
            return RT_EINVAL;
        }
    } else {
        return RT_EINVAL;
    }

    if (LL_ADC_REG_IsConversionOngoing(adc_handle)) {
        return RT_EBUSY;
    }

    LL_ADC_REG_SetSequencerRanks(adc_handle, LL_ADC_REG_RANK_1, adc_channel);
    LL_ADC_SetChannelSamplingTime(adc_handle, adc_channel, LL_ADC_SAMPLINGTIME_64CYCLES_5);
    LL_ADC_SetChannelSingleDiff(adc_handle, adc_channel, LL_ADC_SINGLE_ENDED);

    LL_ADC_REG_StartConversion(adc_handle);

    if (rt_completion_wait(adc_cplt, TICKS_FROM_MS(ADC_CONVERSION_TIMEOUT_MS)) != RT_EOK) {
        return RT_ERROR;
    }

    uint16_t adcData = LL_ADC_REG_ReadConversionData14(adc_handle);
    *mVolt = __LL_ADC_CALC_DATA_TO_VOLTAGE(3300, adcData, LL_ADC_RESOLUTION_14B);

    return RT_EOK;
}

static rt_err_t adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    if (enable == ADC_CMD_ENABLE) {
        if (adc_dev == &adc0) {
            LL_ADC_Enable(ADC3);
            LL_ADC_Enable(ADC1);
        } else {
            return RT_EINVAL;
        }
        /* the ADC needs a stabilization time of tSTAB
         * before it starts converting accurately
         */
        sys_msleep(5);
    } else if (enable == ADC_CMD_DISABLE) {
        if (adc_dev == &adc0) {
            LL_ADC_Disable(ADC3);
            LL_ADC_Disable(ADC1);
        } else {
            return RT_EINVAL;
        }
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t adc3_hw_init(void)
{
    LL_ADC_InitTypeDef ADC_InitStruct = { 0 };
    LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = { 0 };
    LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = { 0 };
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_RCC_SetADCClockSource(LL_RCC_ADC_CLKSOURCE_PLL2P);

    /* Peripheral clock enable */
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_ADC3);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOC);
    /**ADC3 GPIO Configuration
    PC2   ------> ADC3_INP0
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* ADC3 interrupt Init */
    NVIC_SetPriority(ADC3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
    NVIC_EnableIRQ(ADC3_IRQn);

    /** Common config
     */
    LL_ADC_SetOverSamplingScope(ADC3, LL_ADC_OVS_DISABLE);
    ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_14B;
    ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
    LL_ADC_Init(ADC3, &ADC_InitStruct);
    ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = DISABLE;
    ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
    ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_OVERWRITTEN;
    LL_ADC_REG_Init(ADC3, &ADC_REG_InitStruct);
    ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_ASYNC_DIV1;
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

    LL_ADC_StartCalibration(ADC3, LL_ADC_CALIB_OFFSET_LINEARITY, LL_ADC_SINGLE_ENDED);
    while (LL_ADC_IsCalibrationOnGoing(ADC3)) { /* Wait */
    }

    /* Channels preselection, which need be set before  starting conversion */
    ADC3->PCSEL |= (1UL << __LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_CHANNEL_0));

    rt_completion_init(&stm_adc3.convert_cplt);

    LL_ADC_EnableIT_EOC(ADC3);
    LL_ADC_EnableIT_OVR(ADC3);

    return RT_EOK;
}

static rt_err_t adc1_hw_init(void)
{
    /* ADC1 Init */
    LL_ADC_InitTypeDef ADC_InitStruct = { 0 };
    LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = { 0 };
    LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = { 0 };
    LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    LL_RCC_SetADCClockSource(LL_RCC_ADC_CLKSOURCE_PLL2P);

    /* Peripheral clock enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_ADC12);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
    /**ADC1 GPIO Configuration
    PB0   ------> ADC1_INP9
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* ADC1 interrupt Init */
    NVIC_SetPriority(ADC_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0));
    NVIC_EnableIRQ(ADC_IRQn);

    /** Common config
     */
    LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
    ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_14B;
    ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
    LL_ADC_Init(ADC1, &ADC_InitStruct);
    ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = DISABLE;
    ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
    ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_OVERWRITTEN;
    LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
    ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_ASYNC_DIV1;
    ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
    LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC1), &ADC_CommonInitStruct);

    /* Disable ADC deep power down (enabled by default after reset state) */
    LL_ADC_DisableDeepPowerDown(ADC1);
    /* Enable ADC internal voltage regulator */
    LL_ADC_EnableInternalRegulator(ADC1);
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

    LL_ADC_StartCalibration(ADC1, LL_ADC_CALIB_OFFSET_LINEARITY, LL_ADC_SINGLE_ENDED);
    while (LL_ADC_IsCalibrationOnGoing(ADC1)) { /* Wait */
    }

    /* Channels preselection, which need be set before  starting conversion */
    ADC1->PCSEL |= (1UL << __LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_CHANNEL_9));

    rt_completion_init(&stm_adc1.convert_cplt);

    LL_ADC_EnableIT_EOC(ADC1);
    LL_ADC_EnableIT_OVR(ADC1);

    return RT_EOK;
}

/* usart driver operations */
static const struct adc_ops _adc_ops = {
    .enable = adc_enable,
    .measure = adc_measure
};

rt_err_t drv_adc_init(void)
{
    RT_TRY(adc3_hw_init());
    RT_TRY(adc1_hw_init());

    adc0.ops = &_adc_ops;
    // adc1.ops = &_adc_ops;

    RT_TRY(hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, NULL));
    // RT_TRY(hal_adc_register(&adc1, "adc1", RT_DEVICE_FLAG_RDONLY, &stm_adc1));

    return RT_EOK;
}
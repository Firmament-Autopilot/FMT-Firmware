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
#include "stm32f4xx_adc.h"

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
    if (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == SET) {
        /* Clear flag ADC group regular end of unitary conversion */
        ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);

        /* inform the completion of adc convertion */
        rt_completion_done(&convert_cplt);
    }

    /* Check whether ADC group regular overrun caused the ADC interruption */
    if (ADC_GetFlagStatus(ADC1, ADC_FLAG_OVR) == SET) {
        /* Clear flag ADC group regular overrun */
        ADC_ClearITPendingBit(ADC1, ADC_FLAG_OVR);
        /* TODO: data is lost, maybe we can inform the waiting thread */
    }
}

//about voltage_k_  ref : https://blog.csdn.net/killhu/article/details/126440993?ops_request_misc=&request_id=&biz_id=102&utm_term=px4%E5%88%86%E5%8E%8B&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-126440993.142

static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    const float voltage_k_ = 0.09868; //the Partial pressure ratio of power measure
    uint32_t adc_channel;
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle != ADC1) {
        return RT_EINVAL;
    }

    switch (channel) {
    case 0:
        adc_channel = ADC_Channel_2; // because fmu v2 only have one power
        break;
    case 1:
        adc_channel = ADC_Channel_3; // because fmu v2 only have one power
        break;
    case 2:
        adc_channel = ADC_Channel_2; //the voltage measure
        break;
    case 3:
        adc_channel = ADC_Channel_3; // the current measure
        break;
    default:
        return RT_EINVAL;
    }
    // 配置 ADC 通道转换顺序为1，第一个转换，采样时间为3个时钟周期
    ADC_RegularChannelConfig(ADC1, adc_channel, 1, ADC_SampleTime_56Cycles);
    //开始adc转换，软件触发
    ADC_SoftwareStartConv(ADC1);
    if (rt_completion_wait(&convert_cplt, TICKS_FROM_MS(ADC_CONVERSION_TIMEOUT_MS)) != RT_EOK) {
        return RT_ERROR;
    }

    uint16_t ADC_ConvertedValue = ADC_GetConversionValue(ADC1);
    float power_measure_ = (float)ADC_ConvertedValue / 4096 * (float)3.3;
    float power_total_ = (float)power_measure_ / voltage_k_;
    *mVolt = (uint32_t)(power_total_ * 1000); // V to mv

    return RT_EOK;
}

static rt_err_t adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    struct stm32_adc* adc = (struct stm32_adc*)adc_dev->parent.user_data;

    if (adc->adc_handle != ADC1) {
        return RT_EINVAL;
    }

    if (enable == ADC_CMD_ENABLE) {
        ADC_Cmd(adc->adc_handle, ENABLE);
        /* the ADC needs a stabilization time of tSTAB 
         * before it starts converting accurately 
         */
        sys_msleep(1);
    } else if (enable == ADC_CMD_DISABLE) {
        ADC_Cmd(adc->adc_handle, DISABLE);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t adc_hw_init(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;

    // 使能 GPIO 时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    // 配置 IO
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //current adc in PA2 of fmu and voltage adc in PA3
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; //不上拉不下拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    ADC_InitTypeDef ADC_InitStructure;
    ADC_CommonInitTypeDef ADC_CommonInitStructure;

    // 开启ADC时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    // -------------------ADC Common 结构体 参数 初始化------------------------
    // 独立ADC模式
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    // 时钟为fpclk x分频
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
    // 禁止DMA直接访问模式
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    // 采样时间间隔
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_20Cycles;
    ADC_CommonInit(&ADC_CommonInitStructure);

    // -------------------ADC Init 结构体 参数 初始化--------------------------
    ADC_StructInit(&ADC_InitStructure);
    // ADC 分辨率
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    // 禁止扫描模式，多通道采集才需要s
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    // no连续转换
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    //禁止外部边沿触发
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    //外部触发通道，本例子使用软件触发，此值随便赋值即可
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
    //数据右对齐
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    //转换通道 1个
    ADC_InitStructure.ADC_NbrOfConversion = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
    //---------------------------------------------------------------------------

    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);

    return RT_EOK;
}

static void adc_interrupt_configure(struct stm32_adc* adc)
{
    /* Enable  ADC interruptions */
    ADC_ITConfig(adc->adc_handle, ADC_IT_EOC, ENABLE);
    ADC_ITConfig(adc->adc_handle, ADC_IT_OVR, ENABLE);
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
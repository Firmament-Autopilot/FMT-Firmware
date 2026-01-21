/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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
#include "drv_adc.h"
#include "hal/adc/adc.h"

#define ADC_CONVERSION_TIMEOUT_MS 2

static struct adc_device adc0;
static struct rt_completion convert_cplt;

void ADC_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
#if 0
    if (adc_interrupt_flag_get(ADC0, ADC_INT_FLAG_EOC)) {
        adc_interrupt_flag_clear(ADC0, ADC_INT_FLAG_EOC);

        /* inform the completion of adc convertion */
        rt_completion_done(&convert_cplt);
    }
#endif
    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t adc_hw_init(void)
{
    stc_adc_init_t stcAdcInit;
    stc_gpio_init_t stcGpioInit;

    
    LL_PERIPH_WE(LL_PERIPH_GPIO | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU);


    /* 1. Enable ADC peripheral clock. */
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_ADC1, ENABLE);

    /* 2. Modify the default value depends on the application. Not needed here. */
    (void)ADC_StructInit(&stcAdcInit);

    /* 3. Initializes ADC. */
    (void)ADC_Init(CM_ADC1, &stcAdcInit);

    /* 4. ADC channel configuration. */
    /* 4.1 Set the ADC pin to analog input mode. */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinAttr = PIN_ATTR_ANALOG;
    (void)GPIO_Init(GPIO_PORT_A, GPIO_PIN_03|GPIO_PIN_04, &stcGpioInit);

    /* 4.2 Enable ADC channels. Call ADC_ChCmd() again to enable more channels if needed. */
    ADC_ChCmd(CM_ADC1, ADC_SEQ_A, ADC_CH3, ENABLE);
    ADC_ChCmd(CM_ADC1, ADC_SEQ_A, ADC_CH4, ENABLE);

    /* 5. Set sampling time if needed. */
    ADC_SetSampleTime(CM_ADC1, ADC_CH3, 0x40U);
    ADC_SetSampleTime(CM_ADC1, ADC_CH4, 0x40U);

    /* 6. Conversion data average calculation function, if needed.
          Call ADC_ConvDataAverageChCmd() again to enable more average channels if needed. */
    ADC_ConvDataAverageConfig(CM_ADC1, ADC_AVG_CNT8);
    ADC_ConvDataAverageChCmd(CM_ADC1, ADC_CH3, ENABLE);
    ADC_ConvDataAverageChCmd(CM_ADC1, ADC_CH4, ENABLE);
    
    ADC_ChCmd(CM_ADC1, ADC_SEQ_A, ADC_CH3, DISABLE);
    ADC_ChCmd(CM_ADC1, ADC_SEQ_A, ADC_CH4, DISABLE);
    LL_PERIPH_WP(LL_PERIPH_GPIO | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU);
    return RT_EOK;
#if 0
    /* enable GPIOA clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    /* enable ADC clock */
    rcu_periph_clock_enable(RCU_ADC0);
    /* config ADC clock */
    adc_clock_config(ADC_ADCCK_PCLK2_DIV8);

    /* config the GPIO as analog mode. PC0: BAT_VOL PC3：BAT_CURRENT */
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_PULLDOWN, GPIO_PIN_0);
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_PULLDOWN, GPIO_PIN_3);

    /* reset ADC */
    adc_deinit();
    /* ADC mode config */
    adc_sync_mode_config(ADC_SYNC_MODE_INDEPENDENT);
    /* ADC contineous function disable */
    adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, DISABLE);
    /* ADC scan mode disable */
    adc_special_function_config(ADC0, ADC_SCAN_MODE, DISABLE);
    /* ADC 12B resolution */
    adc_resolution_config(ADC0, ADC_RESOLUTION_12B);
    /* ADC data alignment config */
    adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
    /* ADC channel length config */
    adc_channel_length_config(ADC0, ADC_REGULAR_CHANNEL, ADC_CHANNEL_10);

    /* ADC trigger config */
    adc_external_trigger_config(ADC0, ADC_REGULAR_CHANNEL, EXTERNAL_TRIGGER_DISABLE);

    /* enable ADC end of conversion interrupt */
    adc_interrupt_enable(ADC0, ADC_INT_EOC);
    nvic_irq_enable(ADC_IRQn, 1, 1);

    return RT_EOK;
#endif
}

static rt_err_t enable(adc_dev_t adc_dev, uint8_t enable)
{
    if (enable == ADC_CMD_ENABLE) {
        /* enable ADC interface */
//adc_enable(ADC0);
        /* ADC calibration and reset calibration */
//adc_calibration_enable(ADC0);
        /* the ADC needs a stabilization time of tSTAB 
         * before it starts converting accurately 
         */
        sys_msleep(1);
    } else if (enable == ADC_CMD_DISABLE) {
//adc_disable(ADC0);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

#define ADC_TIMEOUT_VAL                 (1000U)
static rt_err_t measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    uint32_t adc_channel;
    uint16_t adcData;
    uint16_t u16AdcValue;
    int32_t iRet = LL_ERR;
    __IO uint32_t u32TimeCount = 0UL;
#if 1
    switch (channel) {
    case 0: /* BAT1_VOL */
        adc_channel = ADC_CH3;
        *mVolt = 2048 * 3300 / 4095*3;
        return RT_EOK;
        break;
    case 1: /* BAT1_CURRENT */
        adc_channel = ADC_CH4;
        break;
    default:
        return RT_EINVAL;
    }
#endif

    ADC_ChCmd(CM_ADC1, ADC_SEQ_A, adc_channel, ENABLE);
    ADC_Start(CM_ADC1);

    do {
        if (ADC_GetStatus(CM_ADC1, ADC_FLAG_EOCA) == SET) {
            ADC_ClearStatus(CM_ADC1, ADC_FLAG_EOCA);
            iRet = LL_OK;
            break;
        }
    } while (u32TimeCount++ < ADC_TIMEOUT_VAL);

    if (iRet == LL_OK) {
        /* Get any ADC value of sequence A channel that needed. */
        u16AdcValue = ADC_GetValue(CM_ADC1, adc_channel);
    } else {
        ADC_Stop(CM_ADC1);
        ADC_ChCmd(CM_ADC1, ADC_SEQ_A, adc_channel, DISABLE);
        return RT_ERROR;
    }
    adcData = u16AdcValue;
    *mVolt = adcData * 3300 / 4095;
    ADC_ChCmd(CM_ADC1, ADC_SEQ_A, adc_channel, DISABLE);
    return RT_EOK;

#if 0
    /* ADC routine channel config */
    adc_regular_channel_config(ADC0, 0U, adc_channel, ADC_SAMPLETIME_3);
    /* ADC software trigger enable */
    adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);

    if (rt_completion_wait(&convert_cplt, TICKS_FROM_MS(ADC_CONVERSION_TIMEOUT_MS)) != RT_EOK) {
        return RT_ERROR;
    }

    adcData = adc_regular_data_read(ADC0);
    *mVolt = adcData * 3300 / 4095;

    return RT_EOK;
#endif
}

/* usart driver operations */
static const struct adc_ops _adc_ops = {
    .enable = enable,
    .measure = measure
};

void test_adc(void)
{
    uint32_t data;
    measure(0,0,&data);
    printf("adc ch3 is  %ld\n",data);

    rt_thread_delay(1);
    measure(0,1,&data);
    printf("adc ch4 is  %ld\n",data);
}

rt_err_t drv_adc_init(void)
{
    RT_CHECK(adc_hw_init());

    rt_completion_init(&convert_cplt);

    adc0.ops = &_adc_ops;

    return hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, RT_NULL);
}



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
    if (adc_interrupt_flag_get(ADC0, ADC_INT_FLAG_EOC)) {
        adc_interrupt_flag_clear(ADC0, ADC_INT_FLAG_EOC);

        /* inform the completion of adc convertion */
        rt_completion_done(&convert_cplt);
    }
    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t adc_hw_init(void)
{
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
}

static rt_err_t enable(adc_dev_t adc_dev, uint8_t enable)
{
    if (enable == ADC_CMD_ENABLE) {
        /* enable ADC interface */
        adc_enable(ADC0);
        /* ADC calibration and reset calibration */
        adc_calibration_enable(ADC0);
        /* the ADC needs a stabilization time of tSTAB 
         * before it starts converting accurately 
         */
        sys_msleep(1);
    } else if (enable == ADC_CMD_DISABLE) {
        adc_disable(ADC0);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    uint32_t adc_channel;
    uint16_t adcData;

    switch (channel) {
    case 0: /* BAT1_VOL */
        adc_channel = ADC_CHANNEL_10;
        break;
    case 1: /* BAT1_CURRENT */
        adc_channel = ADC_CHANNEL_13;
        break;
    default:
        return RT_EINVAL;
    }

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
}

/* usart driver operations */
static const struct adc_ops _adc_ops = {
    .enable = enable,
    .measure = measure
};

rt_err_t drv_adc_init(void)
{
    RT_CHECK(adc_hw_init());

    rt_completion_init(&convert_cplt);

    adc0.ops = &_adc_ops;

    return hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, RT_NULL);
}
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
#include <board_bsp.h>
#include <firmament.h>

#include "drv_adc.h"
#include "hal/adc/adc.h"

#define ADC_TIMEOUT_VAL (1000U)

static struct adc_device adc0;

static rt_err_t adc_hw_init(void)
{
    stc_adc_init_t stcAdcInit;
    stc_gpio_init_t stcGpioInit;

    /* 1. Enable ADC peripheral clock. */
    FCG_Fcg3PeriphClockCmd(FCG3_PERIPH_ADC3, ENABLE);

    /* 2. Modify the default value depends on the application. Not needed here. */
    (void)ADC_StructInit(&stcAdcInit);

    /* 3. Initializes ADC. */
    (void)ADC_Init(CM_ADC3, &stcAdcInit);

    /* 4. ADC channel configuration. */
    /* PF3 set to ADC3-IN9
       PF4 set to ADC3-IN14
       PF5 set to ADC3-IN15
       PF6 set to ADC3-IN4 */
    (void)GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16PinAttr = PIN_ATTR_ANALOG;
    (void)GPIO_Init(GPIO_PORT_F, GPIO_PIN_03 | GPIO_PIN_04 | GPIO_PIN_05 | GPIO_PIN_06, &stcGpioInit);

    /* 5. Set sampling time if needed. */
    ADC_SetSampleTime(CM_ADC3, ADC_CH4, 0x40U);
    ADC_SetSampleTime(CM_ADC3, ADC_CH9, 0x40U);
    ADC_SetSampleTime(CM_ADC3, ADC_CH14, 0x40U);
    ADC_SetSampleTime(CM_ADC3, ADC_CH15, 0x40U);

    /* 6. Conversion data average calculation function, if needed.
          Call ADC_ConvDataAverageChCmd() again to enable more average channels if needed. */
    ADC_ConvDataAverageConfig(CM_ADC3, ADC_AVG_CNT8);
    ADC_ConvDataAverageChCmd(CM_ADC3, ADC_CH4, ENABLE);
    ADC_ConvDataAverageChCmd(CM_ADC3, ADC_CH9, ENABLE);
    ADC_ConvDataAverageChCmd(CM_ADC3, ADC_CH14, ENABLE);
    ADC_ConvDataAverageChCmd(CM_ADC3, ADC_CH15, ENABLE);

    return RT_EOK;
}

static rt_err_t enable(adc_dev_t adc_dev, uint8_t enable)
{
    if (enable == ADC_CMD_ENABLE) {
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH4, ENABLE);
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH15, ENABLE);
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH9, ENABLE);
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH14, ENABLE);
    } else if (enable == ADC_CMD_DISABLE) {
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH4, DISABLE);
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH15, DISABLE);
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH9, DISABLE);
        ADC_ChCmd(CM_ADC3, ADC_SEQ_A, ADC_CH14, DISABLE);
    } else {
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    uint32_t adc_channel;
    uint16_t u16AdcValue = 0;
    rt_err_t iRet = RT_ETIMEOUT;
    __IO uint32_t u32TimeCount = 0UL;

    switch (channel) {
    case BAT1_V_CHANNEL: 
        adc_channel = ADC_CH15;
        break;
    case BAT1_I_CHANNEL: 
        adc_channel = ADC_CH4;
        break;
    case BAT2_V_CHANNEL: 
        adc_channel = ADC_CH9;
        break;
    case BAT2_I_CHANNEL: 
        adc_channel = ADC_CH14;
        break;
    default:
        return RT_EINVAL;
    }

    /* Can ONLY start sequence A conversion.
       Sequence B needs hardware trigger to start conversion. */
    ADC_Start(CM_ADC3);

    do {
        if (ADC_GetStatus(CM_ADC3, ADC_FLAG_EOCA) == SET) {
            ADC_ClearStatus(CM_ADC3, ADC_FLAG_EOCA);
            iRet = RT_EOK;
            break;
        }
    } while (u32TimeCount++ < ADC_TIMEOUT_VAL);

    if (iRet == RT_EOK) {
        /* Get any ADC value of sequence A channel that needed. */
        u16AdcValue = ADC_GetValue(CM_ADC3, adc_channel);
    } else {
        ADC_Stop(CM_ADC3);
    }

    *mVolt = u16AdcValue * 3300 / 4095;

    return iRet;
}

/* usart driver operations */
static const struct adc_ops _adc_ops = {
    .enable = enable,
    .measure = measure
};

rt_err_t drv_adc_init(void)
{
    RT_CHECK(adc_hw_init());

    adc0.ops = &_adc_ops;

    return hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, RT_NULL);
}

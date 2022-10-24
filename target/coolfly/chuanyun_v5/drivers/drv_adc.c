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

#define ADC_CONVERSION_TIMEOUT_MS 2

static struct adc_device adc1;

static uint32_t adc_reg_read32(uint32_t regAddr)
{
	return *((volatile uint32_t *)regAddr);
}

static void adc_reg_wr32(uint32_t regAddr, uint32_t regData)
{
	*((volatile uint32_t *)regAddr) = regData;
}



static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
	uint32_t u32_dateAddr = 0x40B000F4;
	uint32_t u32_SarAddr = 0x40B000EC;

    uint32_t u32_recValue = 0;

    if(channel > 9)
    {
        u32_recValue = 0;
    }
    else
    {
	    adc_reg_wr32(u32_SarAddr, channel << 2);
	    systime_udelay(1);
	    u32_recValue = adc_reg_read32(u32_dateAddr);
    }

    *mVolt = u32_recValue * 3300 / 1023;

    return RT_EOK;
}

static rt_err_t adc_enable(adc_dev_t adc_dev, uint8_t enable)
{
    return RT_EOK;
}


static rt_err_t adc_hw_init(void)
{
    return RT_EOK;
}


/* usart driver operations */
static const struct adc_ops _adc_ops = {
    .enable = adc_enable,
    .measure = adc_measure
};

rt_err_t drv_adc_init(void)
{
    RT_CHECK(adc_hw_init());

    adc1.ops = &_adc_ops;

    return hal_adc_register(&adc1, "adc1", RT_DEVICE_FLAG_RDONLY, NULL);
}
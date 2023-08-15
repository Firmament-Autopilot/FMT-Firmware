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

static struct adc_device adc0;
static struct adc_device adc9;

static uint32_t adc_reg_read32(uint32_t regAddr)
{
    return *((volatile uint32_t*)regAddr);
}

static void adc_reg_wr32(uint32_t regAddr, uint32_t regData)
{
    *((volatile uint32_t*)regAddr) = regData;
}

static rt_err_t adc_measure(adc_dev_t adc_dev, uint32_t channel, uint32_t* mVolt)
{
    uint32_t u32_dateAddr = 0x40B000F4;
    uint32_t u32_SarAddr  = 0x40B000EC;

    uint32_t u32_recValue = 0;

    // pmu_init 是公共函数 通道给写死了  我不想改了 就在这里重新映射一下
    if (channel > 9) {
        u32_recValue = 0;
    } else if (channel == 0) // bat1 = vol
    {
        adc_reg_wr32(u32_SarAddr, 8 << 2);
        systime_udelay(1);
        u32_recValue = adc_reg_read32(u32_dateAddr);
    } else if (channel == 1) // bat1 = cur
    {
        u32_recValue = 0;
    } else {
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
    .enable  = adc_enable,
    .measure = adc_measure
};

rt_err_t drv_adc_init(void)
{
    RT_CHECK(adc_hw_init());

    adc0.ops = &_adc_ops;
    adc9.ops = &_adc_ops;

    hal_adc_register(&adc0, "adc0", RT_DEVICE_FLAG_RDONLY, NULL);
    return hal_adc_register(&adc9, "adc9", RT_DEVICE_FLAG_RDONLY, NULL);
}

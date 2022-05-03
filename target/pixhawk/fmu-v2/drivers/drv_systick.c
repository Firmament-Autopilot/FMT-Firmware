/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#include "hal/systick/systick.h"

static systick_dev_t _systick_dev;
rt_uint32_t _ticksPerUs; /* tick count for 1us */

/**
 * This is the systick timer interrupt service routine.
 *
 */
void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    hal_systick_isr(_systick_dev);

    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}

static void _set_systick_freq(rt_uint32_t freq)
{
    RCC_ClocksTypeDef rcc_clocks;
    rt_uint32_t cnts;

    RCC_GetClocksFreq(&rcc_clocks);

    cnts = (rt_uint32_t)rcc_clocks.HCLK_Frequency / freq;

    if (_systick_dev) {
        _systick_dev->ticks_per_us = rcc_clocks.HCLK_Frequency / 1e6;
        _systick_dev->ticks_per_isr = cnts;
    }

    SysTick_Config(cnts);
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
}

static rt_err_t systick_configure(systick_dev_t systick, struct systick_configure* cfg)
{
    _set_systick_freq(cfg->tick_freq);

    systick->config = *cfg;

    return RT_EOK;
}

static rt_uint32_t systick_read(systick_dev_t systick)
{
    return (SysTick->LOAD - SysTick->VAL) / systick->ticks_per_us;
}

const static struct systick_ops _systick_ops = {
    systick_configure,
    systick_read
};

rt_err_t drv_systick_init(void)
{
    RCC_ClocksTypeDef rcc_clocks;
    static struct systick_device systick_dev = {
        .ops = &_systick_ops,
        .config = SYSTICK_CONFIG_DEFAULT,
        .systick_isr_cb = RT_NULL
    };

    _systick_dev = &systick_dev;

    _set_systick_freq(systick_dev.config.tick_freq);

    RCC_GetClocksFreq(&rcc_clocks);

    return hal_systick_register(&systick_dev, "systick", RT_DEVICE_FLAG_RDONLY, RT_NULL);
}

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
#include "hal/systick.h"

static systick_dev_t systick_dev;

/**
 * This function will delay for some us.
 *
 * @param us the delay time of us
 */
static void _delay_us(rt_uint32_t us)
{
    rt_uint32_t start, now, delta, reload, us_tick;
    start = SysTick->VAL;
    reload = SysTick->LOAD;
    us_tick =systick_dev->ticks_per_us;
    do {
        now = SysTick->VAL;
        delta = start >= now ? start - now : reload + start - now;
    } while (delta < us_tick * us);
}

/* HAL exported functions */
uint32_t HAL_GetTick(void)
{
    /* return current ticks of ms */
    return rt_tick_get() / (RT_TICK_PER_SECOND / 1000);
}

void HAL_SuspendTick(void)
{
}

void HAL_ResumeTick(void)
{
}

void HAL_Delay(__IO uint32_t Delay)
{
    if (rt_thread_self()) {
        rt_thread_mdelay(Delay);
    } else {
        for (rt_uint32_t count = 0; count < Delay; count++) {
            _delay_us(1000);
        }
    }
}

/* re-implement tick interface for STM32 HAL */
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
    /* Return function status */
    return HAL_OK;
}

/**
 * This is the systick timer interrupt service routine.
 *
 */
void SysTick_Handler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    HAL_IncTick();
    rt_tick_increase();

    hal_systick_isr(systick_dev);

    /* leave interrupt */
    rt_interrupt_leave();
}

static void _set_systick_freq(rt_uint32_t freq)
{
    rt_uint32_t ClockFreq;
    rt_uint32_t TicksNum;

    RT_ASSERT(freq > 0);

#if defined(SOC_SERIES_STM32H7)
    ClockFreq = HAL_RCCEx_GetD1SysClockFreq();
#elif defined(SOC_SERIES_STM32MP1)
    ClockFreq = HAL_RCC_GetSystemCoreClockFreq();
#else
    ClockFreq = HAL_RCC_GetHCLKFreq();
#endif
#if !defined(SOC_SERIES_STM32MP1)
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
#endif

    TicksNum = ClockFreq / freq;
    HAL_SYSTICK_Config(TicksNum);

    if (systick_dev) {
        systick_dev->ticks_per_us = ClockFreq / 1e6;
        systick_dev->ticks_per_isr = TicksNum;
    }
}

static rt_err_t systick_configure(systick_dev_t systick, struct systick_configure* cfg)
{
    _set_systick_freq(cfg->tick_freq);

    systick->config = *cfg;

    return RT_EOK;
}

// TODO: return ticks number instead of us
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
    static struct systick_device dev = {
        .ops = &_systick_ops,
        .config = SYSTICK_CONFIG_DEFAULT,
        .systick_isr_cb = RT_NULL
    };
    systick_dev = &dev;

    _set_systick_freq(dev.config.tick_freq);

    return hal_systick_register(systick_dev, "systick", RT_DEVICE_FLAG_RDONLY, RT_NULL);
}
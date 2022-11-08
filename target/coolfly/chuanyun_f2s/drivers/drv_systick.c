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

#include "drv_systick.h"
#include "hal/systick/systick.h"


#include "ar1002_chip.h"

static systick_dev_t systick_dev;



/* HAL exported functions */
uint32_t HAL_GetTick(void)
{
    /* return current ticks of ms */
    return rt_tick_get() / (RT_TICK_PER_SECOND / 1000);
}

void HAL_Delay(volatile uint32_t Delay)
{
    if (rt_thread_self()) {
        rt_thread_mdelay(Delay);
    } else {
        for (rt_uint32_t count = 0; count < Delay; count++) {
            SysTicks_DelayUS(1000);
        }
    }
}

/**
 * This is the systick timer interrupt service routine.
 *
 */
void SysTick_Handler(void)
{
    SysTicks_IncTickCount();

    /* enter interrupt */
    rt_interrupt_enter();

    hal_systick_isr(systick_dev);
    
    rt_tick_increase();

    /* leave interrupt */
    rt_interrupt_leave();
}


static volatile uint32_t g_u32SysTickCount = 0;
static volatile uint32_t g_u32SysTickLoad = 0;


static void _set_systick_freq(rt_uint32_t freq)
{
    rt_uint32_t ClockFreq;
    rt_uint32_t TicksNum;

    RT_ASSERT(freq > 0);
    RT_ASSERT(systick_dev != NULL);

    ClockFreq = 200000000;
    TicksNum = ClockFreq / freq;

    systick_dev->ticks_per_us = ClockFreq / 1e6;
    systick_dev->ticks_per_isr = TicksNum;

    SysTick_Config(TicksNum);

    g_u32SysTickLoad = (uint32_t)(TicksNum - 1UL);

}

void SysTicks_IncTickCount(void)
{
    g_u32SysTickCount++;
}

uint32_t SysTicks_GetTickCount(void)
{
    return g_u32SysTickCount;
}

/**
  * @brief Provides a us tick value
  * @note: Call xTaskGetTickCount instead if the FreeRTOS is running.  
  * @retval Tick value
  */
uint64_t SysTicks_GetUsTickCount(void)
{
    uint64_t val = (uint64_t)(SysTick->VAL);
    uint64_t tmp_SysTickCount = (uint64_t)(g_u32SysTickCount);

    uint16_t u16_pllClk;
    uint64_t ret;
    static uint64_t calc_SysTickCount = 0;
    static uint64_t pre_val = 0;
    
    PLLCTRL_GetCoreClk(&u16_pllClk, CPUINFO_GetLocalCpuId());

    if(calc_SysTickCount > tmp_SysTickCount)
    {
        if (val > pre_val)
        {
            calc_SysTickCount += 1;
        }
    }
    else
    {
        if((val > pre_val) && (calc_SysTickCount == tmp_SysTickCount))
        {
            calc_SysTickCount = tmp_SysTickCount + 1;
        }
        else
        {
            calc_SysTickCount = tmp_SysTickCount;
        }
    }

    ret = (uint64_t)(calc_SysTickCount * 1000 + (uint32_t)(g_u32SysTickLoad - val) / u16_pllClk);

    pre_val = val;

    return ret;
}


void SysTicks_DelayMS(uint32_t msDelay)
{
    uint32_t tickstart = 0;
    uint32_t tickcurrent = 0;
    tickstart = g_u32SysTickCount;
    while(1)
    {
        tickcurrent = g_u32SysTickCount;
        if (tickcurrent >= tickstart)
        {
            if ((tickcurrent - tickstart) >= msDelay)
            {
                break;
            }
        }
        else
        {
            if (((MAX_SYS_TICK_COUNT - tickstart) + tickcurrent) >= msDelay)
            {
                break;
            }
        }
    }
}


void SysTicks_DelayUS(uint64_t usDelay)
{
    uint64_t tickstart = 0;
    uint64_t tickcurrent = 0;
    tickstart = SysTicks_GetUsTickCount();
    while(1)
    {
        tickcurrent = SysTicks_GetUsTickCount();
        if (tickcurrent >= tickstart)
        {
            if ((tickcurrent - tickstart) >= usDelay)
            {
                break;
            }
        }
        else
        {
            if (((((uint64_t)0xFFFFFFFFFFFFFFFF) - tickstart) + tickcurrent) >= usDelay)
            {
                break;
            }
        }
    }
}

uint32_t SysTicks_GetDiff(uint32_t u32_start, uint32_t u32_end)
{
    if (u32_end >= u32_start)
    {
        return (u32_end - u32_start);
    }
    else
    {
       return ((MAX_SYS_TICK_COUNT - u32_start) + u32_end);
    }
}

uint64_t SysTicks_GetUsDiff(uint64_t u64_start, uint64_t u64_end)
{
    if (u64_end >= u64_start)
    {
        return (u64_end - u64_start);
    }
    else
    {
       return ((((uint64_t)0xFFFFFFFFFFFFFFFF) - u64_start) + u64_end);
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
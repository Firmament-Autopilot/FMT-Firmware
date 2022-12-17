
/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-22     Jesven       first version
 */
/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

static systick_dev_t systick_dev;

static rt_err_t systick_configure(systick_dev_t systick, struct systick_configure* cfg)
{
    return RT_EOK;
}

// TODO: return ticks number instead of us
static rt_uint32_t systick_read(systick_dev_t systick)
{
    return (TIMER_LOAD(TIMER_HW_BASE) - TIMER_VALUE(TIMER_HW_BASE)) / systick->ticks_per_us;
}

static void rt_hw_timer_isr(int vector, void* param)
{
    /* enter interrupt */
    rt_interrupt_enter();

    hal_systick_isr(systick_dev);

    rt_tick_increase();
    /* clear interrupt */
    TIMER_INTCLR(TIMER_HW_BASE) = 0x01;

    /* leave interrupt */
    rt_interrupt_leave();
}

int rt_hw_timer_init(void)
{
    rt_uint32_t val;

    SYS_CTRL |= REALVIEW_REFCLK;

    /* Setup Timer0 for generating irq */
    val = TIMER_CTRL(TIMER_HW_BASE);
    val &= ~TIMER_CTRL_ENABLE;
    val |= (TIMER_CTRL_32BIT | TIMER_CTRL_PERIODIC | TIMER_CTRL_IE);
    TIMER_CTRL(TIMER_HW_BASE) = val;

    TIMER_LOAD(TIMER_HW_BASE) = 1000000 / RT_TICK_PER_SECOND;

    /* enable timer */
    TIMER_CTRL(TIMER_HW_BASE) |= TIMER_CTRL_ENABLE;

    rt_hw_interrupt_install(IRQ_PBA8_TIMER2_3, rt_hw_timer_isr, RT_NULL, "tick");
    rt_hw_interrupt_umask(IRQ_PBA8_TIMER2_3);

    return 0;
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

    rt_hw_timer_init();

    systick_dev->ticks_per_us = 1000;
    systick_dev->ticks_per_isr = 1000000;

    return hal_systick_register(systick_dev, "systick", RT_DEVICE_FLAG_RDONLY, RT_NULL);
}
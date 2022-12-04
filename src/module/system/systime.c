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
#include "module/system/systime.h"

typedef struct {
    volatile uint32_t msPeriod; /* current time in ms */
    uint32_t msPerPeriod;       /* ms count for each period (SysTick_Handler fire) */
} systime_t;

static systime_t __systime;
static rt_device_t systick_dev;

/**
 * @brief Systick ISR callback
 *
 */
static void systick_isr_cb(void)
{
    __systime.msPeriod += __systime.msPerPeriod;
}

/**
 * @brief Check if the period of time has elapsed
 *
 * @param timetag Time tag which stores the period and time information
 * @return uint8_t 1 indicates true
 */
uint8_t check_timetag(TimeTag* timetag)
{
    uint32_t now = systime_now_ms();

    if (timetag->period > 0 && now - timetag->tag >= timetag->period) {
        timetag->tag = now;
        return 1;
    }
    return 0;
}

/**
 * @brief Check if the period of time has elapsed with specified time now
 *
 * @param timetag Time tag which stores the period and time information
 * @param now Time now in ms
 * @return uint8_t uint8_t 1 indicates true
 */
uint8_t check_timetag2(TimeTag* timetag, uint32_t now)
{
    if (timetag->period && now - timetag->tag >= timetag->period) {
        timetag->tag = now;
        return 1;
    }
    return 0;
}

/**
 * @brief Check if the period of time has elapsed with specified time now and period
 *
 * @param timetag Time tag which stores the period and time information
 * @param now Time now in ms
 * @param period Period in ms
 * @return uint8_t uint8_t 1 indicates true
 */
uint8_t check_timetag3(TimeTag* timetag, uint32_t now, uint32_t period)
{
    if (period > 0 && now - timetag->tag >= period) {
        timetag->tag = now;
        return 1;
    }
    return 0;
}

/**
 * @brief Get current systime in us
 *
 * @return uint64_t systime in us
 */
uint64_t systime_now_us(void)
{
    uint32_t systick_us = 0;
    uint64_t time_now_ms;
    uint32_t level;

    rt_device_read(systick_dev, SYSTICK_RD_TIME_US, &systick_us, sizeof(uint32_t));

    level = rt_hw_interrupt_disable();
    /* atomic read */
    time_now_ms = __systime.msPeriod;
    rt_hw_interrupt_enable(level);

    return time_now_ms * (uint64_t)1000 + systick_us;
}

/**
 * @brief Get current systime in ms
 *
 * @return uint32_t systime in ms
 */
uint32_t systime_now_ms(void)
{
    uint32_t time_now_ms = systime_now_us() / 1e3;

    return time_now_ms;
}

/**
 * @brief Delay for us
 *
 * @param time_us Delay time in us
 */
void systime_udelay(uint32_t time_us)
{
    uint64_t target = systime_now_us() + time_us;

    while (systime_now_us() < target)
        ;
}

/**
 * @brief Delay for ms
 *
 * @param time_ms Delay time in ms
 */
inline void systime_mdelay(uint32_t time_ms)
{
    systime_udelay(time_ms * 1000);
}

/**
 * @brief Sleep for ms
 * @note In thread context it will suspend the thread for specific milliseconds,
 *       otherwise it will just do normal delay.
 *
 * @param time_ms Sleep time in ms
 */
void systime_msleep(uint32_t time_ms)
{
    if (rt_thread_self()) {
        rt_thread_delay(TICKS_FROM_MS(time_ms));
    } else {
        systime_mdelay(time_ms);
    }
}

/**
 * @brief Initialize systime module
 *
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t systime_init(void)
{
    systick_dev_t systick_device;

    systick_dev = rt_device_find("systick");

    if (systick_dev == RT_NULL) {
        return FMT_ERROR;
    }

    if (rt_device_open(systick_dev, RT_DEVICE_FLAG_RDONLY) != RT_EOK) {
        return FMT_ERROR;
    }

    systick_device = (systick_dev_t)systick_dev;

    __systime.msPeriod = 0;
    __systime.msPerPeriod = systick_device->ticks_per_isr / systick_device->ticks_per_us / 1e3;

    systick_device->systick_isr_cb = systick_isr_cb;

    FMT_ASSERT(__systime.msPerPeriod > 0);

    return FMT_EOK;
}

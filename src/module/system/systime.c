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
#include "module/system/systime.h"
#include "hal/systick/systick.h"

typedef struct {
    volatile uint32_t msPeriod; /* current time in ms */
    uint32_t msPerPeriod;       /* ms count for each period (SysTick_Handler fire) */
} systime_t;

static systime_t __systime;
static rt_device_t systick_dev;
static rt_device_t rtc_dev;
static uint32_t mlog_time_ref = 0;

/**
 * @brief Systick ISR callback
 */
static void systick_isr_cb(void)
{
    __systime.msPeriod += __systime.msPerPeriod;
    rt_tick_increase();
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

    if (timetag->period > 0 && ((now - timetag->tag) >= timetag->period)) {
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
    if (timetag->period && ((now - timetag->tag) >= timetag->period)) {
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
    if (period > 0 && ((now - timetag->tag) >= period)) {
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
    uint64_t now_us;
    uint32_t level;
    static uint64_t monotonic_us = 0;

    if (systick_dev == NULL) {
        return 0;
    }

    level = rt_hw_interrupt_disable();

    /* atomic read */
    rt_device_read(systick_dev, SYSTICK_RD_TIME_US, &systick_us, sizeof(uint32_t));
    time_now_ms = __systime.msPeriod;

    now_us = time_now_ms * 1000ULL + systick_us;

    /* Fix the race condition where the SysTick hardware timer has wrapped around */
    if (now_us < monotonic_us) {
        now_us += (uint64_t)__systime.msPerPeriod * 1000ULL;
    }

    /* Ensure strict monotonicity */
    monotonic_us = now_us;

    rt_hw_interrupt_enable(level);

    return now_us;
}

/**
 * @brief Get current systime in ms
 *
 * @return uint32_t systime in ms
 */
inline uint32_t systime_now_ms(void)
{
    return (uint32_t)((systime_now_us() + 500) / 1000);
}

/**
 * @brief Delay for us
 *
 * @param time_us Delay time in us
 */
void systime_udelay(uint32_t time_us)
{
    if (systick_dev == NULL) {
        return;
    }

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
    systime_udelay(time_ms * 1000ULL);
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
 * @brief Set rtc time
 * @param time rtc time structure
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t systime_set_rtc(const struct rtc_time* time)
{
    if (rtc_dev == NULL || time == NULL) {
        return FMT_EEMPTY;
    }

    if (rt_device_write(rtc_dev, 0, time, 1) == 1) {
        return FMT_EOK;
    }

    return FMT_ERROR;
}

/**
 * @brief Get rtc time
 * @param time rtc time structure
 * @return fmt_err_t FMT_EOK indicates success
 */
fmt_err_t systime_get_rtc(struct rtc_time* time)
{
    if (rtc_dev == NULL || time == NULL) {
        return FMT_EEMPTY;
    }

    if (rt_device_read(rtc_dev, 0, time, 1) == 1) {
        return FMT_EOK;
    }

    return FMT_ERROR;
}

void unix_sec_to_rtc(uint64_t unix_sec, int8_t timezone_oft, struct rtc_time* time)
{
    static const uint8_t days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    uint32_t days, sec_of_day;
    uint16_t year;
    uint8_t month;

    /* add time zone offset */
    unix_sec += timezone_oft * 3600;

    days = (uint32_t)(unix_sec / 86400ULL);
    sec_of_day = (uint32_t)(unix_sec % 86400ULL);

    time->hours = sec_of_day / 3600;
    time->minutes = (sec_of_day % 3600) / 60;
    time->seconds = sec_of_day % 60;

    year = 1970;
    while (1) {
        uint16_t days_in_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 366 : 365;
        if (days < days_in_year) {
            break;
        }
        days -= days_in_year;
        year++;
    }
    time->year = year;

    month = 1;
    while (1) {
        uint8_t dim = days_in_month[month - 1];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            dim = 29;
        }
        if (days < dim) {
            break;
        }
        days -= dim;
        month++;
    }
    time->month = month;

    time->day = (uint8_t)(days + 1);
}

uint64_t rtc_to_unix_sec(int8_t timezone_oft, const struct rtc_time* time)
{
    static const uint8_t days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    uint64_t days = 0;

    for (uint16_t y = 1970; y < time->year; y++) {
        days += (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? 366 : 365;
    }

    for (uint8_t m = 1; m < time->month; m++) {
        days += days_in_month[m - 1];
        if (m == 2 && ((time->year % 4 == 0 && time->year % 100 != 0) || time->year % 400 == 0)) {
            days += 1;
        }
    }

    days += (time->day - 1);

    return days * 86400ULL + time->hours * 3600ULL + time->minutes * 60ULL + time->seconds - timezone_oft * 3600;
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

    if (systick_dev == NULL) {
        return FMT_ERROR;
    }

    if (rt_device_open(systick_dev, RT_DEVICE_FLAG_RDONLY) != RT_EOK) {
        return FMT_ERROR;
    }

    systick_device = (systick_dev_t)systick_dev;

    __systime.msPeriod = 0;
    /* Calculate integer ms without losing precision */
    __systime.msPerPeriod = systick_device->ticks_per_isr / (systick_device->ticks_per_us * 1000UL);

    systick_device->systick_isr_cb = systick_isr_cb;

    FMT_ASSERT(__systime.msPerPeriod > 0);

    rtc_dev = rt_device_find("rtc");
    if (rtc_dev != NULL) {
        if (rt_device_open(rtc_dev, RT_DEVICE_FLAG_RDWR) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    return FMT_EOK;
}

/**
 * @brief Get the mlog time reference point
 *
 * If the reference has not been set yet, it will be initialized on first call.
 *
 * @return uint32_t The reference time in ms
 */
uint32_t systime_get_origin(void)
{
    if (mlog_time_ref == 0) {
        mlog_time_ref = systime_now_ms();
    }
    return mlog_time_ref;
}

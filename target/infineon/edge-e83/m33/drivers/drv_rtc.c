/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date         Author         Notes
 * 2022-07-25   Rbb666         first version
 */

#include "board.h"
#include <rtdevice.h>

#ifdef BSP_USING_RTC

#define LOG_TAG "drv.rtc"
#include <drv_log.h>

static rt_rtc_dev_t ifx32_rtc_dev;

static int get_day_of_week(int day, int month, int year)
{
    if (month < 3)
    {
        month += 12;
        year -= 1;
    }

    int k = year % 100;
    int j = year / 100;

    int ret = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    ret = (ret + 6) % 7;

    return ret + 1;
}

static rt_err_t set_rtc_time_stamp(time_t timestamp)
{
    struct tm tm = {0};
    gmtime_r(&timestamp, &tm);

    int full_year = tm.tm_year + 1900;
    if (full_year < 2000 || full_year > 2099)
    {
        LOG_E("RTC year out of range: %d", full_year);
        return -RT_ERROR;
    }

    cy_stc_rtc_config_t new_time;
    memset(&new_time, 0, sizeof(new_time));

    new_time.sec      = tm.tm_sec;
    new_time.min      = tm.tm_min;
    new_time.hour     = tm.tm_hour;
    new_time.date     = tm.tm_mday;
    new_time.month    = tm.tm_mon + 1;
    new_time.year     = full_year - 2000;
    new_time.dayOfWeek = get_day_of_week(tm.tm_mday, tm.tm_mon + 1, full_year);

    new_time.hrFormat = CY_RTC_24_HOURS;
    new_time.amPm     = CY_RTC_AM;

    LOG_D("SET RTC %04d-%02d-%02d %02d:%02d:%02d (W=%d)",
          full_year, new_time.month, new_time.date,
          new_time.hour, new_time.min, new_time.sec,
          new_time.dayOfWeek);

    cy_en_rtc_status_t status = Cy_RTC_SetDateAndTime(&new_time);
    return (status == CY_RTC_SUCCESS) ? RT_EOK : -RT_ERROR;
}

static rt_err_t ifx_rtc_get_timeval(struct timeval *tv)
{
    cy_stc_rtc_config_t dt;
    Cy_RTC_GetDateAndTime(&dt);

    struct tm tm_new = {0};
    tm_new.tm_sec  = dt.sec;
    tm_new.tm_min  = dt.min;
    tm_new.tm_hour = dt.hour;
    tm_new.tm_mday = dt.date;
    tm_new.tm_mon  = dt.month - 1;
    tm_new.tm_year = dt.year + 100;

    tv->tv_sec = timegm(&tm_new);
    tv->tv_usec = 0;

    LOG_D("GET RTC %04d-%02d-%02d %02d:%02d:%02d",
          tm_new.tm_year + 1900, tm_new.tm_mon + 1, tm_new.tm_mday,
          tm_new.tm_hour, tm_new.tm_min, tm_new.tm_sec);

    return RT_EOK;
}

static rt_err_t _rtc_get_secs(time_t *sec)
{
    struct timeval tv;
    ifx_rtc_get_timeval(&tv);
    *sec = tv.tv_sec;
    return RT_EOK;
}

static rt_err_t _rtc_set_secs(time_t *sec)
{
    return set_rtc_time_stamp(*sec);
}

static rt_err_t _rtc_init(void)
{
    cy_en_rtc_status_t status;
    uint32_t retry = 500;

    do
    {
        status = Cy_RTC_Init(&CYBSP_RTC_config);
        rt_thread_mdelay(5);
    }
    while (status != CY_RTC_SUCCESS && retry--);

    return (status == CY_RTC_SUCCESS) ? RT_EOK : -RT_ERROR;
}

static const struct rt_rtc_ops _rtc_ops =
{
    _rtc_init,
    _rtc_get_secs,
    _rtc_set_secs,
    RT_NULL,
    RT_NULL,
    ifx_rtc_get_timeval,
    RT_NULL,
};

static int rt_hw_rtc_init(void)
{
    ifx32_rtc_dev.ops = &_rtc_ops;

    if (rt_hw_rtc_register(&ifx32_rtc_dev, "rtc", RT_DEVICE_FLAG_RDWR, RT_NULL) != RT_EOK)
    {
        LOG_E("RTC register failed");
        return -RT_ERROR;
    }

    LOG_D("RTC init success");
    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_hw_rtc_init);

#endif

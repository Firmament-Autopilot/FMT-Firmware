/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#include "hal/rtc/rtc.h"
// #define RTC_HANDLE RTC

// void rtc_get_datetime(void)
// {
//     uint32_t time_bcd, date_bcd;
//     uint8_t hours, minutes, seconds;
//     uint8_t year, month, day, weekday;

//     /* 1. 获取原始数据 (BCD 格式) */
//     time_bcd = LL_RTC_TIME_Get(RTC_HANDLE);
//     date_bcd = LL_RTC_DATE_Get(RTC_HANDLE);

//     /* 2. 使用 ST 提供的宏提取字段并转换为二进制 */
//     /* 注意：LL_RTC_GET_XXX 宏提取的仍是 BCD，需要用 LL_RTC_CONVERT_BCD2BIN 转换 */

//     // 时间字段
//     seconds = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_SECOND(time_bcd));
//     minutes = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_MINUTE(time_bcd));
//     hours = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_HOUR(time_bcd));

//     // 日期字段
//     weekday = __LL_RTC_GET_WEEKDAY(date_bcd); // 星期不需要转换，本身就是枚举值
//     day = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_DAY(date_bcd));
//     month = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_MONTH(date_bcd));
//     year = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_YEAR(date_bcd));

//     // 此时 hours/minutes/seconds 等已经是日常使用的十进制格式了
//     // 可以打印或者发送给上层使用
//     printf("Time: %02d:%02d:%02d, Date: 20%02d-%02d-%02d, Weekday: %d\r\n",
//            hours,
//            minutes,
//            seconds,
//            year,
//            month,
//            day,
//            weekday);
// }

int cmd_test(int argc, char** argv)
{
    // /* add your test code here */
    // rtc_get_datetime();

    // rt_device_t dev = rt_device_find("rtc");

    struct rtc_time time = { .year = 2026, .month = 10, .day = 11, .hours = 11, .minutes = 6, .seconds = 5 };
    // if (rt_device_write(dev, 0, &time, 1) == 1) {
    //     printf("time write ok\n");
    // }

    if(systime_set_rtc(&time) == FMT_EOK) {
        printf("time write ok\n");
    }
    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_test, __cmd_test, user test command);
/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

static rt_err_t rtc_init(rtc_dev_t dev)
{
    LL_RTC_InitTypeDef RTC_InitStruct = { 0 };
    LL_RTC_TimeTypeDef RTC_TimeStruct = { 0 };
    LL_RTC_DateTypeDef RTC_DateStruct = { 0 };

    /* enable backup access */
    LL_PWR_EnableBkUpAccess();
    while (LL_PWR_IsEnabledBkUpAccess() == 0U) {
    }

    if (LL_RCC_GetRTCClockSource() != LL_RCC_RTC_CLKSOURCE_LSE) {
        LL_RCC_ForceBackupDomainReset();
        LL_RCC_ReleaseBackupDomainReset();
        LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_LOW);
        LL_RCC_LSE_Enable();

        /* Wait till LSE is ready */
        while (LL_RCC_LSE_IsReady() != 1) {
        }
        LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSE);
    }

    LL_RCC_EnableRTC();

    RTC_InitStruct.HourFormat = LL_RTC_HOURFORMAT_24HOUR;
    RTC_InitStruct.AsynchPrescaler = 127;
    RTC_InitStruct.SynchPrescaler = 255;
    if (LL_RTC_Init(RTC, &RTC_InitStruct) != SUCCESS) {
        return RT_ERROR;
    }

    /* check backup register */
    if (LL_RTC_BAK_GetRegister(RTC, LL_RTC_BKP_DR0) != RTC_BKP_MAGIC) {
        /* rtc not configured before */
        RTC_TimeStruct.Hours = 0x0;
        RTC_TimeStruct.Minutes = 0x0;
        RTC_TimeStruct.Seconds = 0x0;
        if (LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_TimeStruct) != SUCCESS) {
            return RT_ERROR;
        }

        RTC_DateStruct.WeekDay = LL_RTC_WEEKDAY_MONDAY;
        RTC_DateStruct.Month = LL_RTC_MONTH_JANUARY;
        RTC_DateStruct.Day = 0x1;
        RTC_DateStruct.Year = 0x0;
        if (LL_RTC_DATE_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_DateStruct) != SUCCESS) {
            return RT_ERROR;
        }

        /* update backup register */
        LL_RTC_BAK_SetRegister(RTC, LL_RTC_BKP_DR0, RTC_BKP_MAGIC);
    }

    return RT_EOK;
}
static rt_err_t rtc_read(rtc_dev_t dev, struct rtc_time* time)
{
    uint32_t time_bcd, date_bcd;

    time_bcd = LL_RTC_TIME_Get(RTC);
    date_bcd = LL_RTC_DATE_Get(RTC);

    time->seconds = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_SECOND(time_bcd));
    time->minutes = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_MINUTE(time_bcd));
    time->hours = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_HOUR(time_bcd));

    time->day = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_DAY(date_bcd));
    time->month = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_MONTH(date_bcd));
    time->year = __LL_RTC_CONVERT_BCD2BIN(__LL_RTC_GET_YEAR(date_bcd)) + 2000;

    return RT_EOK;
}

static rt_err_t rtc_write(rtc_dev_t dev, const struct rtc_time* time)
{
    LL_RTC_TimeTypeDef RTC_TimeStruct = { 0 };
    LL_RTC_DateTypeDef RTC_DateStruct = { 0 };

    RTC_TimeStruct.Hours = __LL_RTC_CONVERT_BIN2BCD(time->hours);
    RTC_TimeStruct.Minutes = __LL_RTC_CONVERT_BIN2BCD(time->minutes);
    RTC_TimeStruct.Seconds = __LL_RTC_CONVERT_BIN2BCD(time->seconds);

    RTC_DateStruct.Month = __LL_RTC_CONVERT_BIN2BCD(time->month);
    RTC_DateStruct.Day = __LL_RTC_CONVERT_BIN2BCD(time->day);
    RTC_DateStruct.Year = __LL_RTC_CONVERT_BIN2BCD(time->year - 2000);

    LL_RTC_DisableWriteProtection(RTC);

    if (LL_RTC_EnterInitMode(RTC) == SUCCESS) {
        LL_RTC_TIME_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_TimeStruct);
        LL_RTC_DATE_Init(RTC, LL_RTC_FORMAT_BCD, &RTC_DateStruct);

        LL_RTC_ExitInitMode(RTC);
        LL_RTC_EnableWriteProtection(RTC);

        return RT_EOK;
    }

    return RT_ERROR;
}

const static struct rtc_ops _ops = {
    .init = rtc_init,
    .read = rtc_read,
    .write = rtc_write
};

static struct rtc_device rtc_dev = {
    .ops = &_ops
};

rt_err_t drv_rtc_init(void)
{
    return hal_rtc_register(&rtc_dev, "rtc", RT_DEVICE_FLAG_RDWR, RT_NULL);
}
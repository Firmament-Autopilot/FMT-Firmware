/***************************************************************************//**
* \file mtb_hal_rtc.c
*
* \brief
* Provides a high level interface for interacting with the Infineon Real-Time Clock.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_rtc.h"
#include "cy_utils.h"
#include "mtb_hal_rtc.h"
#include "mtb_hal_system.h"
#include "mtb_hal_rtc_impl.h"

/**
 * \addtogroup group_hal_impl_rtc RTC (Real Time Clock)
 * \ingroup group_hal_impl
 * \{
 *
 * Internally the RTC only stores the year as a two digit BCD value
 * (0-99); no century information is stored. On RTC initialization the HAL must,
 * as a result, assume a default century. If mtb_hal_rtc_write has been called
 * with a different century than the default, its value must be stored and that
 * value must persist through deep sleep, hibernate, software resets, etc.
 * hardware provides a number of BREG registers which exist in the BACKUP domain
 * and will persist over these power modes and resets. The HAL uses the highest
 * indexed BACKUP->BREG register to store the century for the RTC.
 *
 * Therefore do not use the highest indexed BACKUP->BREG register as it is
 * reserved for internal HAL usage.
 *
 * \note A century rollover (eg: 1999 to 2000) will only be detected if the backup
 * domain is reset. This happens automatically on a hardware reset, or can be done
 * manually by calling Cy_SysLib_ResetBackupDomain(). Calling the reset function
 * will clear any existing RTC/WCO/WDT configuration, so they must be setup after
 * the reset.
 *
 * \} group_hal_impl_wdt
 */

#if (MTB_HAL_DRIVER_AVAILABLE_RTC)

#if defined(__cplusplus)
extern "C" {
#endif

#define _MTB_HAL_RTC_TM_YEAR_BASE 1900
#define _MTB_HAL_RTC_BREG_CENTURY_Pos 0UL
#define _MTB_HAL_RTC_BREG_CENTURY_Msk 0x0000FFFFUL
#define _MTB_HAL_RTC_BREG_STATE_Pos 16UL
#define _MTB_HAL_RTC_BREG_STATE_Msk 0xFFFF0000UL

static const uint32_t _MTB_HAL_RTC_MAX_RETRY = 10;
static const uint32_t _MTB_HAL_RTC_RETRY_DELAY_MS = 1;

// Note: Use PDL directly rather than HAL. RTOS-aware delay is not needed and actually breaks
// functionality.
#define _MTB_HAL_RTC_WAIT_ONE_MS()   Cy_SysLib_Delay(_MTB_HAL_RTC_RETRY_DELAY_MS);

// After making changes to RTC, wait until it is no longer busy
static void _mtb_hal_rtc_wait_until_not_busy(void)
{
    uint32_t retry = 0;
    while (CY_RTC_BUSY == Cy_RTC_GetSyncStatus() && retry < _MTB_HAL_RTC_MAX_RETRY)
    {
        _MTB_HAL_RTC_WAIT_ONE_MS();
        ++retry;
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_rtc_from_pdl_time
//--------------------------------------------------------------------------------------------------
static void _mtb_hal_rtc_from_pdl_time(cy_stc_rtc_config_t* pdlTime, const uint16_t year,
                                       struct tm* time)
{
    CY_ASSERT(NULL != pdlTime);
    CY_ASSERT(NULL != time);

    // The number of days that precede each month of the year, not including Feb 29
    static const uint16_t CUMULATIVE_DAYS[] =
        { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

    time->tm_sec = (int32_t)pdlTime->sec;
    time->tm_min = (int32_t)pdlTime->min;
    time->tm_hour = (int32_t)pdlTime->hour;
    time->tm_mday = (int32_t)pdlTime->date;
    time->tm_mon = (int32_t)(pdlTime->month - 1u);
    time->tm_year = (int32_t)(year - _MTB_HAL_RTC_TM_YEAR_BASE);
    time->tm_wday = (int32_t)(pdlTime->dayOfWeek - 1u);
    time->tm_yday = (int32_t)CUMULATIVE_DAYS[time->tm_mon] + (int32_t)pdlTime->date - 1 +
                    (((int32_t)(pdlTime->month) >= 3 &&
                      (int32_t)(Cy_RTC_IsLeapYear((uint32_t)year) ? 1u : 0u)));
    time->tm_isdst = -1;
}


/* Returns century portion of BREG register used to store century info */
__STATIC_INLINE uint16_t _mtb_hal_rtc_get_century(void)
{
    return _FLD2VAL(_MTB_HAL_RTC_BREG_CENTURY, _MTB_HAL_RTC_BREG);
}


/* Sets century portion of BREG register used to store century info */
__STATIC_INLINE void _mtb_hal_rtc_set_century(uint16_t century)
{
    _MTB_HAL_RTC_BREG &= _MTB_HAL_RTC_BREG_STATE_Msk;
    _MTB_HAL_RTC_BREG |= _VAL2FLD(_MTB_HAL_RTC_BREG_CENTURY, century);

    _mtb_hal_rtc_wait_until_not_busy();
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_rtc_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_rtc_read(mtb_hal_rtc_t* obj, struct tm* time)
{
    CY_UNUSED_PARAMETER(obj);
    CY_ASSERT(NULL != obj);

    cy_stc_rtc_config_t dateTime = { .hrFormat = CY_RTC_24_HOURS };
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    Cy_RTC_GetDateAndTime(&dateTime);
    const uint16_t year = (uint16_t)(dateTime.year + _mtb_hal_rtc_get_century());
    mtb_hal_system_critical_section_exit(savedIntrStatus);

    _mtb_hal_rtc_from_pdl_time(&dateTime, year, time);

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_rtc_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_rtc_write(mtb_hal_rtc_t* obj, const struct tm* time)
{
    CY_UNUSED_PARAMETER(obj);
    CY_ASSERT(NULL != obj);
    uint32_t year = _MTB_HAL_RTC_TM_YEAR_BASE + (uint32_t)time->tm_year;
    uint32_t year2digit = year % 100;

    cy_rslt_t rslt;
    uint32_t retry = 0;
    if (!CY_RTC_IS_SEC_VALID((uint32_t)time->tm_sec) ||
        !CY_RTC_IS_MIN_VALID((uint32_t)time->tm_min) ||
        !CY_RTC_IS_HOUR_VALID((uint32_t)time->tm_hour) ||
        !CY_RTC_IS_MONTH_VALID((uint32_t)(time->tm_mon + 1)) ||
        !CY_RTC_IS_YEAR_SHORT_VALID(year2digit))
    {
        return MTB_HAL_RTC_RSLT_BAD_ARGUMENT;
    }
    do
    {
        if (retry != 0)
        {
            _MTB_HAL_RTC_WAIT_ONE_MS();
        }
        uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
        rslt = Cy_RTC_SetDateAndTimeDirect((uint32_t)time->tm_sec, (uint32_t)time->tm_min,
                                           (uint32_t)time->tm_hour, (uint32_t)time->tm_mday,
                                           (uint32_t)(time->tm_mon + 1), year2digit);
        if (rslt == CY_RSLT_SUCCESS)
        {
            _mtb_hal_rtc_set_century((uint16_t)(year) - (uint16_t)(year2digit));
        }
        mtb_hal_system_critical_section_exit(savedIntrStatus);
        ++retry;
    } while (rslt == CY_RTC_INVALID_STATE && retry < _MTB_HAL_RTC_MAX_RETRY);

    _mtb_hal_rtc_wait_until_not_busy();

    return rslt;
}


#if defined(__cplusplus)
}
#endif

#endif /* MTB_HAL_DRIVER_AVAILABLE_RTC */

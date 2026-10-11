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

int cmd_time(int argc, char** argv)
{
    struct rtc_time time;

    printf("timestamp:%d ", systime_now_ms());
    if (systime_get_rtc(&time) == FMT_EOK) {
        printf("RTC(UTC:%d): %02d:%02d:%02d, %02d-%02d-%02d",
               PARAM_GET_INT8(SYSTEM, TIMEZONE_OFT),
               time.hours,
               time.minutes,
               time.seconds,
               time.year,
               time.month,
               time.day);
    }

    printf("\r\n");
    return 0;
}
FINSH_FUNCTION_EXPORT_ALIAS(cmd_time, __cmd_time, show system time);
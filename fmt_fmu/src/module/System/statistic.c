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

#include "module/console/console.h"
#include "module/system/statistic.h"
#include "module/system/systime.h"

#define CPU_USAGE_CALC_INTERVAL 1000
#define CPU_USAGE_LOOP          10

static float cpu_usage = 0;
static uint64_t total_count = 0;

static void cpu_usage_idle_hook(void)
{
    uint32_t time_start;
    uint64_t count;
    volatile rt_uint32_t loop;

    if (total_count == 0) {
        /* get total count */
        rt_enter_critical();
        time_start = systime_now_ms();
        while (systime_now_ms() - time_start < CPU_USAGE_CALC_INTERVAL) {
            total_count++;
            loop = 0;
            while (loop < CPU_USAGE_LOOP)
                loop++;
        }
        rt_exit_critical();
    }

    count = 0;
    /* get CPU usage */
    time_start = systime_now_ms();
    while (systime_now_ms() - time_start < CPU_USAGE_CALC_INTERVAL) {
        count++;
        loop = 0;
        while (loop < CPU_USAGE_LOOP)
            loop++;
    }

    /* calculate major and minor */
    if (count < total_count) {
        cpu_usage = 100.0 - ((double)count / total_count) * 100.0;
    } else {
        total_count = count;
    }
}

/**
 * @brief Get the cpu usage consumption
 * 
 * @return float The cpu usage in percent. e.g, 50.0 means 50%
 */
float get_cpu_usage(void)
{
    return cpu_usage;
}

/**
 * @brief Initialize system statistic module
 * 
 * @return fmt_err FMT_EOK if successful
 */
fmt_err sys_stat_init(void)
{
    rt_thread_idle_sethook(cpu_usage_idle_hook);

    return FMT_EOK;
}
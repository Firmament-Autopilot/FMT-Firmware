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

static uint64_t prev_schedule_time;
static uint64_t prev_usage_cal_time;
static rt_thread_t idle_thread;

static void calculate_cpu_usage(void)
{
    uint64_t time_now;

    time_now = systime_now_us();
    /* time_now could less than prev_usage_cal_time, this is because systick isr
     * is preempted by higher priority isr, which triggers thread schedule. At that 
     * moment, the systime is not updated yet */
    if (time_now > prev_usage_cal_time && time_now - prev_usage_cal_time >= CPU_USAGE_CALC_INTERVAL * 1000) {
        struct rt_object_information* info;
        struct rt_list_node* list;
        struct rt_thread* thread;
        cpu_usage_stats* stats;

        info = rt_object_get_information(RT_Object_Class_Thread);
        list = &info->object_list;

        for (struct rt_list_node* node = list->next; node != list; node = node->next) {
            thread = rt_list_entry(node, struct rt_thread, list);
            stats = (cpu_usage_stats*)thread->user_data;

            if (stats != NULL) {
                stats->cpu_usage = (stats->exec_time * 100.0f) / (time_now - prev_usage_cal_time);
                stats->exec_time = 0;
            }
        }
        /* update previous cpu usage calculate time */
        prev_usage_cal_time = time_now;
    }
}

static void scheduler_hook(rt_thread_t from, rt_thread_t to)
{
    uint64_t time_now;
    cpu_usage_stats* stats = (cpu_usage_stats*)from->user_data;
    RT_ASSERT(stats != NULL);

    time_now = systime_now_us();

    if (time_now < prev_schedule_time) {
        /* This could happen, because higher priority isr preempt systick isr,
         * so the systick time is not updated yet. 
         */
        time_now += 1000000 / RT_TICK_PER_SECOND;
    }
    /* from thread execution time = current time - last scheduled time */
    stats->exec_time += time_now - prev_schedule_time;
    stats->total_exec_time += stats->exec_time;

    /* update previous schedule time */
    prev_schedule_time = time_now;

    if (to == idle_thread) {
        /* if switch to idle thread, then we calculate the cpu usage */
        calculate_cpu_usage();
    }
}

static void thread_inited_hook(rt_thread_t thread)
{
    cpu_usage_stats* stats = (cpu_usage_stats*)rt_malloc(sizeof(cpu_usage_stats));
    RT_ASSERT(stats != NULL);

    stats->exec_time = 0;
    stats->total_exec_time = 0;
    stats->cpu_usage = 0.0;

    thread->user_data = (uint32_t)stats;
}

static void thread_deleted_hook(rt_thread_t thread)
{
    rt_free((void*)thread->user_data);
}

/**
 * @brief Get the cpu usage consumption
 * 
 * @return float The cpu usage in percent. e.g, 50.0 means 50%
 */
float get_cpu_usage(void)
{
    rt_thread_t idle = rt_thread_idle_gethandler();
    cpu_usage_stats* stats = (cpu_usage_stats*)idle->user_data;
    float cpu_usage = -1.0f;

    if (stats != NULL) {
        cpu_usage = 100.0f - stats->cpu_usage;
    }

    return cpu_usage;
}

/**
 * @brief Initialize system statistic module
 * 
 * @return fmt_err_t FMT_EOK if successful
 */
fmt_err_t sys_stat_init(void)
{
    rt_thread_inited_sethook(thread_inited_hook);
    rt_thread_deleted_sethook(thread_deleted_hook);
    rt_scheduler_sethook(scheduler_hook);

    idle_thread = rt_thread_idle_gethandler();

    return FMT_EOK;
}
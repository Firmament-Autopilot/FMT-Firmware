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

#include "module/sensor/sensor_hub.h"
#include "module/system/systime.h"
#include "module/task_manager/task_manager.h"

#define LOW_FREQ_SENSORS_PERIOD_MS    10
#define EVENT_LOW_FREQ_SENSORS_UPDATE (1 << 0)

static struct rt_timer timer_low_freq_sensors;
static struct rt_event event_low_freq_sensors;

static void timer_low_freq_sensors_update(void* parameter)
{
    rt_event_send(&event_low_freq_sensors, EVENT_LOW_FREQ_SENSORS_UPDATE);
}

fmt_err_t task_low_freq_sensors_init(void)
{
    if (rt_event_init(&event_low_freq_sensors, "lfsens", RT_IPC_FLAG_FIFO) != RT_EOK) {
        return FMT_ERROR;
    }

    rt_timer_init(&timer_low_freq_sensors,
                  "lfsens",
                  timer_low_freq_sensors_update,
                  RT_NULL,
                  TICKS_FROM_MS(LOW_FREQ_SENSORS_PERIOD_MS),
                  RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer_low_freq_sensors) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

void task_low_freq_sensors_entry(void* parameter)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    uint32_t wait_set = EVENT_LOW_FREQ_SENSORS_UPDATE;

    while (1) {
        res = rt_event_recv(&event_low_freq_sensors, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_LOW_FREQ_SENSORS_UPDATE) {
#if !defined(FMT_USING_HIL) && !defined(FMT_USING_SIH)
                sensor_collect_low_freq();
#endif
            }
        }
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "low_freq_sensors",
    .init = task_low_freq_sensors_init,
    .entry = task_low_freq_sensors_entry,
    .priority = LOW_FREQ_SENSORS_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 3072,
    .param = NULL,
    .dependency = NULL
};

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

#include "model/control/control_interface.h"
#include "model/fms/fms_interface.h"
#include "model/ins/ins_interface.h"
#include "model/plant/plant_interface.h"
#include "module/file_manager/file_manager.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/gcs_cmd.h"
#include "module/sysio/mission_data.h"
#include "module/sysio/pilot_cmd.h"
#include "module/task_manager/task_manager.h"
#include "task/logger/task_logger.h"

#define EVENT_VEHICLE_UPDATE (1 << 0)

extern rt_device_t main_out_dev;
extern rt_device_t aux_out_dev;

static struct rt_timer timer_vehicle;
static struct rt_event event_vehicle;

static void timer_vehicle_update(void* parameter)
{
    rt_event_send(&event_vehicle, EVENT_VEHICLE_UPDATE);
}

void task_vehicle_entry(void* parameter)
{
    static uint32_t time_start = 0;
    uint32_t time_now;
    uint32_t timestamp;
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    uint32_t wait_set = EVENT_VEHICLE_UPDATE;

    while (1) {
        res = rt_event_recv(&event_vehicle, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_VEHICLE_UPDATE) {
                time_now = systime_now_ms();
                /* record loop start time */
                if (time_start == 0) {
                    time_start = time_now;
                }
                /* the model simulation start from 0, so we calcualtet the timestamp relative to start time */
                timestamp = time_now - time_start;

#if !defined(FMT_USING_HIL) && !defined(FMT_USING_SIH)
                sensor_collect();
#endif
                pilot_cmd_collect();
                gcs_cmd_collect();
                mission_data_collect();

#ifdef FMT_USING_SIH
                /* run Plant model */
                PERIOD_EXECUTE3(plant_step, plant_model_info.period, time_now, plant_interface_step(timestamp););
#endif
                /* run INS model */
                PERIOD_EXECUTE3(ins_step, ins_model_info.period, time_now, ins_interface_step(timestamp););
                /* run FMS model */
                PERIOD_EXECUTE3(fms_step, fms_model_info.period, time_now, fms_interface_step(timestamp););
                /* run Controller model */
                PERIOD_EXECUTE3(control_step, control_model_info.period, time_now, control_interface_step(timestamp););

                /* send actuator command */
                send_actuator_cmd();
            }
        }
    }
}

fmt_err_t task_vehicle_init(void)
{
#if defined(FMT_USING_SIH)
    /* init plant model */
    plant_interface_init();
#endif

    /* init ins model */
    ins_interface_init();

    /* init fms model */
    fms_interface_init();

    /* init controller model */
    control_interface_init();

    /* create event */
    if (rt_event_init(&event_vehicle, "vehicle", RT_IPC_FLAG_FIFO) != RT_EOK) {
        return FMT_ERROR;
    }

    /* register timer event */
    rt_timer_init(&timer_vehicle, "vehicle", timer_vehicle_update, RT_NULL, 1, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer_vehicle) != RT_EOK) {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

TASK_EXPORT __fmt_task_desc = {
    .name = "vehicle",
    .init = task_vehicle_init,
    .entry = task_vehicle_entry,
    .priority = VEHICLE_THREAD_PRIORITY,
    .auto_start = true,
    .stack_size = 5 * 1024,
    .param = NULL,
    .dependency = NULL
};

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

#include "module/controller/controller_model.h"
#include "module/file_manager/file_manager.h"
#include "module/fms/fms_model.h"
#include "module/ins/ins_model.h"
#include "module/plant/plant_model.h"
#include "module/sensor/sensor_hub.h"
#include "module/sysio/actuator_cmd.h"
#include "module/sysio/pilot_cmd.h"
#include "task/task_logger.h"
#include "module/task_manager/task_manager.h"

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
    rt_err_t res;
    uint32_t recv_set = 0;
    uint32_t wait_set = EVENT_VEHICLE_UPDATE;

    while (1) {
        res = rt_event_recv(&event_vehicle, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_VEHICLE_UPDATE) {

                uint32_t time_now = systime_now_ms();

#ifndef FMT_USING_HIL
                sensor_collect();
#endif
                pilot_cmd_collect();

#ifdef FMT_USING_SIH
                /* run Plant model in internal HIL mode */
                TIMETAG_CHECK_EXECUTE3(plant_model_update, PLANT_EXPORT.period, time_now, plant_model_step(););
#endif

                /* run INS model */
                TIMETAG_CHECK_EXECUTE3(ins_model_update, INS_EXPORT.period, time_now, ins_model_step(););

                /* run FMS model */
                TIMETAG_CHECK_EXECUTE3(fms_model_update, FMS_EXPORT.period, time_now, fms_model_step(););

                /* run Controller model */
                TIMETAG_CHECK_EXECUTE3(control_model_update, CONTROL_EXPORT.period, time_now, controller_model_step(););

#if defined(FMT_HIL_WITH_ACTUATOR) || !defined(FMT_USING_HIL) || defined(FMT_TEST_MOTOR)
                send_actuator_cmd();
#endif

#if defined(FMT_USING_HIL) && !defined(FMT_USING_SIH)
                send_hil_actuator_cmd();
#endif
            }
        }
    }
}

fmt_err_t task_vehicle_init(void)
{
    /* create event */
    if (rt_event_init(&event_vehicle, "vehicle", RT_IPC_FLAG_FIFO) != RT_EOK) {
        return FMT_ERROR;
    }

    /* register timer event */
    rt_timer_init(&timer_vehicle, "vehicle_update",
        timer_vehicle_update,
        RT_NULL,
        1,
        RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer_vehicle) != RT_EOK) {
        return FMT_ERROR;
    }

    /* init ins model */
    ins_model_init();

    /* init fms model */
    fms_model_init();

    /* init controller model */
    controller_model_init();

#if defined(FMT_USING_SIH)
    /* init plant model */
    plant_model_init();
#endif

    return FMT_EOK;
}

FMT_TASK_EXPORT(
    vehicle,                 /* name */
    task_vehicle_init,       /* init */
    task_vehicle_entry,      /* entry */
    VEHICLE_THREAD_PRIORITY, /* priority */
    10240,                   /* stack size */
    NULL,                    /* param */
    NULL                     /* dependency */
);

/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
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

#include "module/mavproxy/mavproxy.h"
#include "module/sensor/sensor_hub.h"
#include "module/task_manager/task_manager.h"

MCN_DECLARE(sensor_imu0);

fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

void task_local_entry(void* parameter)
{
    mavlink_debug_float_array_t debug_float_array = { .array_id = 0, .name = "imu_data" };
    mavlink_message_t msg;
    mavlink_system_t mav_sys = mavproxy_get_system();

    /* main loop */
    while (1) {
        imu_data_t imu_report;
        mcn_copy_from_hub(MCN_HUB(sensor_imu0), &imu_report);
        debug_float_array.time_usec = systime_now_us();
        debug_float_array.data[0] = imu_report.gyr_B_radDs[0];
        debug_float_array.data[1] = imu_report.gyr_B_radDs[1];
        debug_float_array.data[2] = imu_report.gyr_B_radDs[2];
        debug_float_array.data[3] = imu_report.acc_B_mDs2[0];
        debug_float_array.data[4] = imu_report.acc_B_mDs2[1];
        debug_float_array.data[5] = imu_report.acc_B_mDs2[2];

        mavlink_msg_debug_float_array_encode(mav_sys.sysid, mav_sys.compid, &msg, &debug_float_array);
        mavproxy_send_immediate_msg(MAVPROXY_GCS_CHAN, &msg, false);

        sys_msleep(20);
    }
}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "local",
//     .init = task_local_init,
//     .entry = task_local_entry,
//     .priority = 25,
//     .auto_start = true,
//     .stack_size = 4096,
//     .param = NULL,
//     .dependency = NULL
// };

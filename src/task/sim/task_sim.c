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
#include "module/mavproxy/mavproxy.h"
#include "module/sensor/sensor_hub.h"
#include "module/task_manager/task_manager.h"
#include "module/workqueue/workqueue_manager.h"
#include "task/comm/task_comm.h"

#define MAVPROXY_SIM_CHAN 2

MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(control_output);

static Control_Out_Bus control_out;

static fmt_err_t handle_mavlink_message(mavlink_message_t* msg, mavlink_system_t this_system)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HIL_SENSOR: {
        mavlink_hil_sensor_t hil_sensor;
        imu_data_t imu_data;
        mag_data_t mag_data;
        baro_data_t baro_data;

        mavlink_msg_hil_sensor_decode(msg, &hil_sensor);

        /* publish hil sensor data */
        imu_data.acc_B_mDs2[0] = hil_sensor.xacc;
        imu_data.acc_B_mDs2[1] = hil_sensor.yacc;
        imu_data.acc_B_mDs2[2] = hil_sensor.zacc;
        imu_data.gyr_B_radDs[0] = hil_sensor.xgyro;
        imu_data.gyr_B_radDs[1] = hil_sensor.ygyro;
        imu_data.gyr_B_radDs[2] = hil_sensor.zgyro;
        imu_data.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_imu0), &imu_data);

        mag_data.mag_B_gauss[0] = hil_sensor.xmag;
        mag_data.mag_B_gauss[1] = hil_sensor.ymag;
        mag_data.mag_B_gauss[2] = hil_sensor.zmag;
        mag_data.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_mag0), &mag_data);

        baro_data.pressure_pa = hil_sensor.abs_pressure * 1e-3;
        baro_data.temperature_deg = hil_sensor.temperature;
        baro_data.altitude_m = hil_sensor.pressure_alt;
        baro_data.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_baro), &baro_data);
    } break;

    case MAVLINK_MSG_ID_HIL_GPS: {
        mavlink_hil_gps_t hil_gps;
        gps_data_t gps_data;

        mavlink_msg_hil_gps_decode(msg, &hil_gps);

        gps_data.lat = hil_gps.lat;
        gps_data.lon = hil_gps.lon;
        gps_data.height = hil_gps.alt;
        gps_data.velN = (float)hil_gps.vn * 0.01f;
        gps_data.velE = (float)hil_gps.ve * 0.01f;
        gps_data.velD = (float)hil_gps.vd * 0.01f;
        gps_data.hAcc = (float)hil_gps.eph * 0.01f;
        gps_data.vAcc = (float)hil_gps.epv * 0.01f;
        gps_data.sAcc = 0; // speed accurancy unknown
        gps_data.numSV = hil_gps.satellites_visible;
        gps_data.fixType = hil_gps.fix_type;
        gps_data.timestamp_ms = systime_now_ms();

        mcn_publish(MCN_HUB(sensor_gps), &gps_data);
    } break;
    default: {
        return FMT_ENOTHANDLE;
    } break;
    }

    return FMT_EOK;
}

static void send_hil_actuator_cmd(void* parameter)
{
    mavlink_hil_actuator_controls_t hil_actuator_ctrl;
    mavlink_message_t msg;
    mavlink_system_t mav_sys;

    /* send command by mavlink */
    mav_sys = mavproxy_get_system();

    if (mcn_copy_from_hub(MCN_HUB(control_output), &control_out) != FMT_EOK)
        return;

    hil_actuator_ctrl.time_usec = systime_now_us();
    hil_actuator_ctrl.mode = MAV_MODE_FLAG_SAFETY_ARMED;
    hil_actuator_ctrl.flags = 0;
    for (int i = 0; i < 16; i++) {
        if (control_out.actuator_cmd[i] > 0) {
            /* map to -1~1 */
            hil_actuator_ctrl.controls[i] = (float)control_out.actuator_cmd[i] * 0.002f - 3.0f;
        } else {
            hil_actuator_ctrl.controls[i] = 0;
        }
    }
    /* encode hil msg */
    mavlink_msg_hil_actuator_controls_encode(mav_sys.sysid, mav_sys.compid, &msg, &hil_actuator_ctrl);

    /* async mode to avoid block the task when usb is not connected */
    mavproxy_send_immediate_msg(MAVPROXY_SIM_CHAN, &msg, false);
}

static fmt_err_t task_sim_init(void)
{
    /* register channel */
    FMT_TRY(mavproxy_register_channel(MAVPROXY_SIM_CHAN));

    /* register periodical mavlink msg */
    FMT_TRY(mavproxy_register_period_msg(MAVPROXY_SIM_CHAN, MAVLINK_MSG_ID_HEARTBEAT, 1, mavlink_msg_heartbeat_pack_func, true));

    /* register gcs mavlink handler */
    FMT_TRY(mavproxy_monitor_register_handler(MAVPROXY_SIM_CHAN, handle_mavlink_message));

    return FMT_EOK;
}

static struct WorkItem work_item = {
    .name = "sim",
    .period = 4,
    .schedule_time = 0,
    .run = send_hil_actuator_cmd
};

static void task_sim_entry(void* parameter)
{
    WorkQueue_t hp_wq = workqueue_find("wq:hp_work");
    RT_ASSERT(hp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(hp_wq, &work_item));

    /* execute mavproxy main loop */
    mavproxy_channel_loop(MAVPROXY_SIM_CHAN);
}

TASK_EXPORT __fmt_task_desc = {
    .name = "sim",
    .init = task_sim_init,
    .entry = task_sim_entry,
    .priority = 18,
    .auto_start = true,
    .stack_size = 2048,
    .param = NULL,
    .dependency = NULL
};

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

#include "module/file_manager/file_manager.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavproxy.h"
#include "module/sensor/sensor_hub.h"

#define TAG "MAV_Monitor"

#define EVENT_MAV_RX (1 << 0)

MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);

static char thread_mavlink_rx_stack[4096];
static struct rt_thread thread_mavlink_rx_handle;
static struct rt_event mav_rx_event;

static fmt_err mavproxy_rx_ind(uint32_t size)
{
    /* wakeup thread to handle received data */
    rt_err_t rt_err = rt_event_send(&mav_rx_event, EVENT_MAV_RX);

    return (rt_err == RT_EOK) ? FMT_EOK : FMT_ERROR;
}

static void send_mavlink_command_ack(mavlink_command_ack_t* command_ack, mavlink_message_t* msg)
{
    mavlink_system_t mav_sys = mavproxy_get_system();

    mavlink_msg_command_ack_encode(mav_sys.sysid, mav_sys.compid, msg, command_ack);
    mavproxy_send_immediate_msg(msg, true);
}

static void handle_mavlink_command(mavlink_command_long_t* command, mavlink_message_t* msg)
{
    switch (command->command) {
    case MAV_CMD_PREFLIGHT_CALIBRATION: {
        mavlink_command_ack_t command_ack;

        if (command->param1 == 1) { // calibration gyr
            mavproxy_cmd_set(MAVCMD_CALIBRATION_GYR, NULL);
        } else if (command->param2 == 1) { // calibration mag
            mavproxy_cmd_set(MAVCMD_CALIBRATION_MAG, NULL);
        } else if (command->param5 == 1) { // calibration acc
            mavproxy_cmd_set(MAVCMD_CALIBRATION_ACC, NULL);
        } else if (command->param5 == 2) { // calibration level
            mavproxy_cmd_set(MAVCMD_CALIBRATION_LEVEL, NULL);
        } else {
            /* all 0 command, cancel current process */
        }

        command_ack.command = MAV_CMD_PREFLIGHT_CALIBRATION;
        command_ack.result = MAV_CMD_ACK_OK | MAV_CMD_ACK_ENUM_END;
        send_mavlink_command_ack(&command_ack, msg);
        break;
    }

    default:
        break;
    }
}

static fmt_err handle_mavlink_msg(mavlink_message_t* msg, mavlink_system_t system)
{
    switch (msg->msgid) {
    case MAVLINK_MSG_ID_HEARTBEAT: {

    } break;

    case MAVLINK_MSG_ID_PARAM_REQUEST_READ: {
        if (system.sysid == mavlink_msg_param_request_read_get_target_system(msg)) {
            mavlink_param_request_read_t request_read;
            mavlink_msg_param_request_read_decode(msg, &request_read);

            param_t* param = param_get_by_name(request_read.param_id);

            if (param) {
                mavlink_param_send(param);
            } else {
                // ulog_w(TAG, "get unknown parameter:%s\n", request_read.param_id);
                send_mavlink_param(request_read.param_id);
            }
        }
    } break;

    case MAVLINK_MSG_ID_PARAM_REQUEST_LIST: {
        if (system.sysid == mavlink_msg_param_request_list_get_target_system(msg)) {
            mavproxy_send_event(EVENT_SEND_ALL_PARAM);
        }
    } break;

    case MAVLINK_MSG_ID_PARAM_SET: {
        if (system.sysid == mavlink_msg_param_set_get_target_system(msg)) {
            mavlink_param_set_t param_set;
            mavlink_msg_param_set_decode(msg, &param_set);

            if (mavlink_param_set(param_set.param_id, param_set.param_value) == FMT_EOK) {
                param_t* param = param_get_by_name(param_set.param_id);
                mavlink_param_send(param);
            } else {
                // ulog_w(TAG, "set unknown parameter:%s\n", param_set.param_id);
            }
        }
    } break;

    case MAVLINK_MSG_ID_COMMAND_LONG: {
        if (system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_long_t command;
            mavlink_msg_command_long_decode(msg, &command);

            handle_mavlink_command(&command, msg);
        }
    } break;

    case MAVLINK_MSG_ID_SERIAL_CONTROL: {
        mavlink_serial_control_t serial_control;
        mavlink_msg_serial_control_decode(msg, &serial_control);

        /* handle received msg */
        mavlink_console_process_rx_msg(&serial_control);
    } break;

    case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: {
        if (system.sysid == mavlink_msg_file_transfer_protocol_get_target_system(msg)) {
            mavlink_file_transfer_protocol_t ftp_protocol_t;

            mavlink_msg_file_transfer_protocol_decode(msg, &ftp_protocol_t);

            if (ftp_process_request(ftp_protocol_t.payload, msg->sysid, msg->compid) == FMT_EOK) {

                ftp_protocol_t.target_system = msg->sysid;
                ftp_protocol_t.target_component = msg->compid;
                ftp_protocol_t.target_network = 0;

                mavlink_msg_file_transfer_protocol_encode(system.sysid, system.compid, msg, &ftp_protocol_t);

                if (mavproxy_send_immediate_msg(msg, 0) != FMT_EOK) {
                    console_printf("ftp msg send err\n");
                    return FMT_ERROR;
                }
            }
        }
    } break;

#if defined(FMT_USING_HIL) && !defined(FMT_USING_SIH)
    case MAVLINK_MSG_ID_HIL_SENSOR: {
        mavlink_hil_sensor_t hil_sensor;
        imu_data_t imu_report;
        mag_data_t mag_report;
        baro_data_t baro_report;

        mavlink_msg_hil_sensor_decode(msg, &hil_sensor);

        /* publish hil sensor data */
        imu_report.acc_B_mDs2[0] = hil_sensor.xacc;
        imu_report.acc_B_mDs2[1] = hil_sensor.yacc;
        imu_report.acc_B_mDs2[2] = hil_sensor.zacc;
        imu_report.gyr_B_radDs[0] = hil_sensor.xgyro;
        imu_report.gyr_B_radDs[1] = hil_sensor.ygyro;
        imu_report.gyr_B_radDs[2] = hil_sensor.zgyro;
        imu_report.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_imu), &imu_report);

        mag_report.mag_B_gauss[0] = hil_sensor.xmag;
        mag_report.mag_B_gauss[1] = hil_sensor.ymag;
        mag_report.mag_B_gauss[2] = hil_sensor.zmag;
        mag_report.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_mag), &mag_report);

        baro_report.pressure_pa = hil_sensor.abs_pressure * 1e-3;
        baro_report.temperature_deg = hil_sensor.temperature;
        baro_report.altitude_m = hil_sensor.pressure_alt;
        baro_report.timestamp_ms = systime_now_ms();
        mcn_publish(MCN_HUB(sensor_baro), &baro_report);
    } break;

    case MAVLINK_MSG_ID_HIL_GPS: {
        mavlink_hil_gps_t hil_gps;
        gps_data_t gps_report;

        gps_report.lat = hil_gps.lat;
        gps_report.lon = hil_gps.lon;
        gps_report.height = hil_gps.alt;
        gps_report.velN = (float)hil_gps.vn * 0.01f;
        gps_report.velE = (float)hil_gps.ve * 0.01f;
        gps_report.velD = (float)hil_gps.vd * 0.01f;
        gps_report.hAcc = (float)hil_gps.eph * 0.01f;
        gps_report.vAcc = (float)hil_gps.epv * 0.01f;
        gps_report.sAcc = 0; // speed accurancy unknown
        gps_report.numSV = hil_gps.satellites_visible;
        gps_report.fixType = hil_gps.fix_type;
        gps_report.timestamp_ms = systime_now_ms();
        ;
        mcn_publish(MCN_HUB(sensor_gps), &gps_report);
    } break;
#endif

    default: {
        // console_printf("unknown mavlink msg:%d\n", msg->msgid);
        return FMT_ENOTHANDLE;
    } break;
    }

    return FMT_EOK;
}

static void mavproxy_rx_entry(void* param)
{
    mavlink_message_t msg;
    mavlink_status_t mav_status;
    mavlink_system_t mavlink_system;
    char byte;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAV_RX;
    rt_err_t rt_err;

    mavlink_system = mavproxy_get_system();

    while (1) {
        /* wait event happen */
        rt_err = rt_event_recv(&mav_rx_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_MAV_RX) {
                while (mavproxy_dev_read(&byte, 1, 0)) {
                    /* decode mavlink package */
                    if (mavlink_parse_char(0, byte, &msg, &mav_status) == 1) {
                        handle_mavlink_msg(&msg, mavlink_system);
                    }
                }
            }
        }
    }
}

fmt_err mavproxy_monitor_create(void)
{
    rt_err_t res;

    res = rt_thread_init(&thread_mavlink_rx_handle,
        "mav_rx",
        mavproxy_rx_entry,
        RT_NULL,
        &thread_mavlink_rx_stack[0],
        sizeof(thread_mavlink_rx_stack), MAVLINK_RX_THREAD_PRIORITY, 5);

    if (res != RT_EOK) {
        console_printf("mav rx thread create fail\n");
        return FMT_ERROR;
    }

    if (rt_event_init(&mav_rx_event, "mav_rx", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("mav rx event create fail\n");
        return FMT_ERROR;
    }
    /* set mavproxy device rx indicator */
    mavproxy_dev_set_rx_indicate(mavproxy_rx_ind);
    /* start rx thread */
    rt_thread_startup(&thread_mavlink_rx_handle);

    return FMT_EOK;
}
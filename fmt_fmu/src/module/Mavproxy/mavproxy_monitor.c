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

#include "module/fs_manager/fs_manager.h"
#include "module/ftp/ftp_manager.h"
#include "module/mavproxy/mavlink_param.h"
#include "module/mavproxy/mavproxy_dev.h"
#include "task/task_comm.h"

#define TAG "MAV_Monitor"

#define EVENT_MAV_RX (1 << 0)

static char thread_mavlink_rx_stack[4096];
struct rt_thread thread_mavlink_rx_handle;

static struct rt_event _mav_rx_event;

static fmt_err _mavproxy_rx_ind(uint32_t size)
{
    /* wakeup thread to handle received data */
    rt_err_t rt_err = rt_event_send(&_mav_rx_event, EVENT_MAV_RX);

    return (rt_err == RT_EOK) ? FMT_EOK : FMT_ERROR;
}

static fmt_err _handle_mavlink_msg(mavlink_message_t* msg, mavlink_system_t system)
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
                //TODO: save parameter?
            } else {
                // ulog_w(TAG, "set unknown parameter:%s\n", param_set.param_id);
            }
        }
    } break;

    case MAVLINK_MSG_ID_COMMAND_LONG: {
        if (system.sysid == mavlink_msg_command_long_get_target_system(msg)) {
            mavlink_command_long_t command;
            mavlink_msg_command_long_decode(msg, &command);

            mavproxy_proc_command(&command, msg);
        }
    } break;

    case MAVLINK_MSG_ID_SERIAL_CONTROL: {
        mavlink_serial_control_t serial_control;
        mavlink_msg_serial_control_decode(msg, &serial_control);

        /* handle received msg */
        mavlink_console_process_rx_msg(&serial_control);
    } break;

    case MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL: {
        mavlink_file_transfer_protocol_t ftp_protocol_t;

        if (system.sysid != mavlink_msg_file_transfer_protocol_get_target_system(msg)) {
            return FMT_ERROR;
        }

        mavlink_msg_file_transfer_protocol_decode(msg, &ftp_protocol_t);

        if (ftp_process_request(ftp_protocol_t.payload, msg->sysid, msg->compid) == FMT_EOK) {

            ftp_protocol_t.target_system = msg->sysid;
            ftp_protocol_t.target_component = msg->compid;
            ftp_protocol_t.target_network = 0;

            mavlink_msg_file_transfer_protocol_encode(system.sysid, system.compid, msg, &ftp_protocol_t);

            if (mavproxy_send_immediate_msg(msg, 0) != 1) {
                console_printf("ftp msg send err\n");
                return FMT_ERROR;
            }
        }
    } break;

    default: {
        // console_printf("unknown mavlink msg:%d\n", msg->msgid);
        return FMT_ENOTHANDLE;
    } break;
    }

    return FMT_EOK;
}

void mavproxy_rx_entry(void* param)
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
        rt_err = rt_event_recv(&_mav_rx_event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (rt_err == RT_EOK) {
            if (recv_set & EVENT_MAV_RX) {
                while (mavproxy_dev_read(_mav_dev_chan, &byte, 1, 0)) {
                    /* decode mavlink package */
                    if (mavlink_parse_char(0, byte, &msg, &mav_status) == 1) {
                        _handle_mavlink_msg(&msg, mavlink_system);
                    }
                }
            }
        } else {
            console_printf("mav rx event err\n");
        }
    }
}

void mavproxy_monitor_create(void)
{
    rt_err_t res;

    res = rt_thread_init(&thread_mavlink_rx_handle,
        "mav_rx",
        mavproxy_rx_entry,
        RT_NULL,
        &thread_mavlink_rx_stack[0],
        sizeof(thread_mavlink_rx_stack), MAVLINK_RX_THREAD_PRIORITY, 5);

    if (rt_event_init(&_mav_rx_event, "mav_rx", RT_IPC_FLAG_FIFO) != RT_EOK) {
        console_printf("mav rx event create fail\n");
        return;
    }

    mavproxy_dev_set_rx_indicate(_mavproxy_rx_ind);

    if (res == RT_EOK)
        rt_thread_startup(&thread_mavlink_rx_handle);
}
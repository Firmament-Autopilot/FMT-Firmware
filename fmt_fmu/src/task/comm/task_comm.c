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
#include <string.h>

#include "driver/gps.h"
#include "hal/cdcacm.h"
#include "module/ftp/ftp_manager.h"
#include "module/ins/ins_model.h"
#include "module/mavproxy/mavcmd.h"
#include "module/mavproxy/mavlink_param.h"
#include "module/mavproxy/mavlink_status.h"
#include "module/mavproxy/mavproxy_dev.h"
#include "module/sensor/sensor_manager.h"
#include "module/system/statistic.h"
#include "shell.h"
#include "task/task_comm.h"
#include "task/task_vehicle.h"

static uint8_t mav_tx_buff[1024];
static mavlink_system_t mavlink_system;
static rt_sem_t _mavproxy_tx_lock;

static struct rt_timer timer_mavproxy;
static struct rt_event event_mavproxy;

static MAV_PeriodMsg_Queue _period_msg_queue;
static MAV_ImmediateMsg_Queue _imm_msg_queue;

static rt_device_t _mav_console_dev;
uint8_t _mav_dev_chan = 0; /* mavproxy device channel */

MCN_DECLARE(ins_output);
MCN_DECLARE(usb_status);

extern void mavproxy_monitor_create(void);
extern rt_err_t mavlink_console_init(void);
extern void mav_console_handle_timeout(void);

static void timer_mavproxy_update(void* parameter)
{
    rt_event_send(&event_mavproxy, EVENT_MAVPROXY_UPDATE);
}

static void usb_status_change_cb(void* parameter)
{
    USB_Status* usb_status = (USB_Status*)parameter;

    /* channel 0: usart    channel 1: usb */
    if (usb_status->connected && _mav_dev_chan != 1) {
        _mav_dev_chan = 1;
    }

    if (!usb_status->connected && _mav_dev_chan != 0) {
        _mav_dev_chan = 0;
    }
}

static void mavproxy_msg_heartbeat_pack(mavlink_message_t* msg_t)
{
    mavlink_heartbeat_t heartbeat;
    // uint16_t len;

    heartbeat.type = MAV_TYPE_QUADROTOR;
    heartbeat.autopilot = MAV_AUTOPILOT_PX4;
    // TODO, fill base_mode and custom_mode
    heartbeat.base_mode = MAV_MODE_FLAG_CUSTOM_MODE_ENABLED;
    heartbeat.custom_mode = 0;
    heartbeat.system_status = MAV_STATE_STANDBY;

    mavlink_msg_heartbeat_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &heartbeat);
}

static void mavproxy_msg_sys_status_pack(mavlink_message_t* msg_t)
{
    mavlink_sys_status_t sys_status;
    // uint16_t len;

    sys_status.onboard_control_sensors_present = 1;
    sys_status.onboard_control_sensors_enabled = 1;
    sys_status.onboard_control_sensors_health = 1;
    sys_status.load = (uint16_t)(sysstat_get_cpu_usage() * 1e3);
    sys_status.voltage_battery = 11000;
    sys_status.current_battery = -1;
    sys_status.battery_remaining = -1;

    mavlink_msg_sys_status_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &sys_status);
}

static void mavproxy_msg_attitude_pack(mavlink_message_t* msg_t)
{
    mavlink_attitude_t attitude;
    INS_Out_Bus ins_out;

    mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out);

    attitude.roll = ins_out.phi;
    attitude.pitch = ins_out.theta;
    attitude.yaw = ins_out.psi;
    attitude.rollspeed = ins_out.p;
    attitude.pitchspeed = ins_out.q;
    attitude.yawspeed = ins_out.r;

    mavlink_msg_attitude_encode(mavlink_system.sysid, mavlink_system.compid,
        msg_t, &attitude);
}

static void _msg_local_pos_pack(mavlink_message_t* msg_t)
{
    INS_Out_Bus ins_out;

    mcn_copy_from_hub(MCN_HUB(ins_output), &ins_out);

    mavlink_msg_local_position_ned_pack(
        mavlink_system.sysid, mavlink_system.compid, msg_t, systime_now_ms(),
        ins_out.x_R, ins_out.y_R, -ins_out.h_R, ins_out.vn, ins_out.ve,
        ins_out.vd);
}

static void mavlink_send_command_ack(mavlink_command_ack_t* command_ack,
    mavlink_message_t* msg)
{
    mavlink_msg_command_ack_encode(mavlink_system.sysid, mavlink_system.compid,
        msg, command_ack);

    mavproxy_send_immediate_msg(msg, 1);
}

void mavproxy_proc_command(mavlink_command_long_t* command,
    mavlink_message_t* msg)
{
    switch (command->command) {
    case MAV_CMD_PREFLIGHT_CALIBRATION: {
        mavlink_command_ack_t command_ack;

        if (command->param1 == 1) { // calibration gyr
            mavcmd_set(MAVCMD_CALIBRATION_GYR, NULL);
        } else if (command->param2 == 1) { // calibration mag
            mavcmd_set(MAVCMD_CALIBRATION_MAG, NULL);
        } else if (command->param5 == 1) { // calibration acc
            mavcmd_set(MAVCMD_CALIBRATION_ACC, NULL);
        } else if (command->param5 == 2) { // calibration level
            // mavproxy_send_statustext_msg(CAL_START_LEVEL, msg);
        } else {
            /* all 0 command, cancel current process */
        }

        command_ack.command = MAV_CMD_PREFLIGHT_CALIBRATION;
        command_ack.result = MAV_CMD_ACK_OK | MAV_CMD_ACK_ENUM_END;
        mavlink_send_command_ack(&command_ack, msg);
        break;
    }

    default:
        break;
    }
}

static uint8_t try_send_immediate_msg(void)
{
    while (_imm_msg_queue.head != _imm_msg_queue.tail) {
        if (mavproxy_send_immediate_msg(&_imm_msg_queue.queue[_imm_msg_queue.tail],
                1)) {
            OS_ENTER_CRITICAL;
            _imm_msg_queue.tail = (_imm_msg_queue.tail + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
            OS_EXIT_CRITICAL;
        }
    }

    return 1;
}

static uint8_t try_send_period_msg(void)
{
    for (uint16_t i = 0; i < _period_msg_queue.size; i++) {
        uint32_t now = systime_now_ms();
        MAV_PeriodMsg* msg_t = &_period_msg_queue.queue[_period_msg_queue.index];
        _period_msg_queue.index = (_period_msg_queue.index + 1) % _period_msg_queue.size;

        // find next msg to be sent
        if (now - msg_t->time_stamp >= msg_t->period && msg_t->enable) {
            msg_t->time_stamp = now;
            // pack msg
            mavlink_message_t msg;
            msg_t->msg_pack_cb(&msg);
            // send out msg
            mavproxy_send_immediate_msg(&msg, 1);

            return 1;
        }
    }

    return 0;
}

void mavproxy_send_event(uint32_t event_set)
{
    rt_event_send(&event_mavproxy, event_set);
}

mavlink_system_t mavproxy_get_system(void) { return mavlink_system; }

uint8_t mavproxy_register_period_msg(
    uint8_t msgid, uint16_t period_ms,
    void (*msg_pack_cb)(mavlink_message_t* msg_t), uint8_t enable)
{
    MAV_PeriodMsg msg;

    msg.msgid = msgid;
    msg.enable = enable;
    msg.period = period_ms;
    msg.msg_pack_cb = msg_pack_cb;
    msg.time_stamp = 0;

    if (_period_msg_queue.size < MAX_PERIOD_MSG_QUEUE_SIZE) {
        OS_ENTER_CRITICAL;
        _period_msg_queue.queue[_period_msg_queue.size++] = msg;
        OS_EXIT_CRITICAL;

        return 1;
    } else {
        console_printf("mavproxy period msg queue is full\n");
        return 0;
    }
}

uint8_t mavproxy_send_immediate_msg(const mavlink_message_t* msg,
    uint8_t sync)
{
    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(_mavproxy_tx_lock, RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(mav_tx_buff, msg);
        //size = mavproxy_dev_sync_write(_mav_dev_chan, mav_tx_buff, len);
        size = mavproxy_dev_write(_mav_dev_chan, mav_tx_buff, len, RT_WAITING_FOREVER);

        rt_sem_release(_mavproxy_tx_lock);

        return size == len ? 1 : 0;
    }

    /* otherwise, push msg into queue (asynchronize mode) */
    OS_ENTER_CRITICAL;

    if ((_imm_msg_queue.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE == _imm_msg_queue.tail) {
        OS_EXIT_CRITICAL;
        return 0;
    }

    _imm_msg_queue.queue[_imm_msg_queue.head] = *msg;
    _imm_msg_queue.head = (_imm_msg_queue.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
    OS_EXIT_CRITICAL;

    /* wakeup mavproxy to send out temporary msg immediately */
    rt_event_send(&event_mavproxy, EVENT_MAVPROXY_UPDATE);

    return 1;
}

fmt_err task_comm_init(void)
{
    /* init mavlink system info */
    mavlink_system.sysid = FMT_MAVLINK_SYS_ID;
    mavlink_system.compid = FMT_MAVLINK_COMP_ID;

    /* init message queue */
    _period_msg_queue.size = 0;
    _period_msg_queue.index = 0;
    _imm_msg_queue.head = 0;
    _imm_msg_queue.tail = 0;

    mavproxy_dev_init(_mav_dev_chan);
    mavlink_console_init();

    _mavproxy_tx_lock = rt_sem_create("mav_tx_lock", 1, RT_IPC_FLAG_FIFO);

    /* register callback function to monitor usb status */
    mcn_subscribe(MCN_HUB(usb_status), NULL, usb_status_change_cb);

    /* get mavlink console device */
    _mav_console_dev = rt_device_find("mav_console");
    /* create event */
    rt_event_init(&event_mavproxy, "mavproxy", RT_IPC_FLAG_FIFO);

    /* register timer event */
    rt_timer_init(&timer_mavproxy, "comm_update", timer_mavproxy_update, RT_NULL, 2,
        RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    rt_timer_start(&timer_mavproxy);

    /* register periodical mavlink msg */
    mavproxy_register_period_msg(MAVLINK_MSG_ID_HEARTBEAT, 1000,
        mavproxy_msg_heartbeat_pack, 1);
    mavproxy_register_period_msg(MAVLINK_MSG_ID_SYS_STATUS, 1000,
        mavproxy_msg_sys_status_pack, 1);
    mavproxy_register_period_msg(MAVLINK_MSG_ID_ATTITUDE, 100,
        mavproxy_msg_attitude_pack, 1);
    mavproxy_register_period_msg(MAVLINK_MSG_ID_LOCAL_POSITION_NED, 200,
        _msg_local_pos_pack, 1);

    return FMT_EOK;
}

void task_comm_entry(void* parameter)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAVPROXY_UPDATE | EVENT_MAVCONSOLE_TIMEOUT | EVENT_SEND_ALL_PARAM;

    /* create mavproxy monitor to parse received msg */
    mavproxy_monitor_create();

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event_mavproxy, wait_set,
            RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_SEND_ALL_PARAM) {
                mavlink_param_send_all();
            }

            if (recv_set & EVENT_MAVCONSOLE_TIMEOUT) {
                mav_console_handle_timeout();
            }

            if (recv_set & EVENT_MAVPROXY_UPDATE) {
                // try to send out immediate msg first
                try_send_immediate_msg();
                // try to send out periodical msg
                try_send_period_msg();
                // process mavlink command
                mavcmd_process();
            }
        } else {
            // some err happen
            console_printf("mavproxy loop, err:%d\r\n", res);
        }
    }
}

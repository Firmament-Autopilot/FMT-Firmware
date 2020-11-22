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

#include "hal/cdcacm.h"
#include "module/mavproxy/mavproxy.h"

#define MAX_PERIOD_MSG_QUEUE_SIZE    20
#define MAX_IMMEDIATE_MSG_QUEUE_SIZE 10
#define MAVPROXY_DEFAULT_CHAN        0

void mavproxy_monitor_create(void);

/* subscribed uMCN topics */
MCN_DECLARE(ins_output);
MCN_DECLARE(usb_status);

typedef struct {
    uint8_t msgid;
    uint8_t enable;
    uint16_t period;
    uint32_t time_stamp;
    void (*msg_pack_cb)(mavlink_message_t* msg_t);
} MAV_PeriodMsg;

typedef struct {
    MAV_PeriodMsg queue[MAX_PERIOD_MSG_QUEUE_SIZE];
    uint16_t size;
    uint16_t index;
} MAV_PeriodMsg_Queue;

typedef struct {
    mavlink_message_t queue[MAX_IMMEDIATE_MSG_QUEUE_SIZE];
    uint16_t head;
    uint16_t tail;
} MAV_ImmediateMsg_Queue;

static uint8_t _mav_tx_buff[1024];
static mavlink_system_t _mavlink_system;
static rt_sem_t _mavproxy_tx_lock;
static MAV_PeriodMsg_Queue _period_msg_queue;
static MAV_ImmediateMsg_Queue _imm_msg_queue;
static struct rt_timer _timer_mavproxy;
static struct rt_event _event_mavproxy;
static rt_device_t _mav_console_dev;
static uint8_t _mav_dev_chan = MAVPROXY_DEFAULT_CHAN;

static void _mavproxy_timer_update(void* parameter)
{
    rt_event_send(&_event_mavproxy, EVENT_MAVPROXY_UPDATE);
}

static void _usb_status_change(void* parameter)
{
    USB_Status usb_status = *(USB_Status*)parameter;
    int usb_chan;

    if (usb_status.connected) {
        usb_chan = mavproxy_get_dev_chan("usb");
        if (usb_chan >= 0) {
            _mav_dev_chan = usb_chan;
        }
    } else {
        _mav_dev_chan = MAVPROXY_DEFAULT_CHAN;
    }
}

static uint8_t _send_immediate_msg(void)
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

static uint8_t _send_period_msg(void)
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

static void _send_mavlink_command_ack(mavlink_command_ack_t* command_ack, mavlink_message_t* msg)
{
    mavlink_msg_command_ack_encode(_mavlink_system.sysid, _mavlink_system.compid,
        msg, command_ack);

    mavproxy_send_immediate_msg(msg, 1);
}

void mavproxy_handle_command(mavlink_command_long_t* command, mavlink_message_t* msg)
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
        _send_mavlink_command_ack(&command_ack, msg);
        break;
    }

    default:
        break;
    }
}

uint8_t mavproxy_register_period_msg(uint8_t msgid, uint16_t period_ms,
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

uint8_t mavproxy_send_immediate_msg(const mavlink_message_t* msg, uint8_t sync)
{
    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(_mavproxy_tx_lock, RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(_mav_tx_buff, msg);
        //size = mavproxy_dev_sync_write(_mav_dev_chan, _mav_tx_buff, len);
        size = mavproxy_dev_write(_mav_dev_chan, _mav_tx_buff, len, RT_WAITING_FOREVER);

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
    rt_event_send(&_event_mavproxy, EVENT_MAVPROXY_UPDATE);

    return 1;
}

fmt_err mavproxy_send_event(uint32_t event_set)
{
    return rt_event_send(&_event_mavproxy, event_set);
}

mavlink_system_t mavproxy_get_system(void)
{
    return _mavlink_system;
}

uint8_t mavproxy_get_device_channel(void)
{
    return _mav_dev_chan;
}

void mavproxy_loop(void)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAVPROXY_UPDATE | EVENT_MAVCONSOLE_TIMEOUT | EVENT_SEND_ALL_PARAM;

    /* register callback function to monitor usb status */
    mcn_subscribe(MCN_HUB(usb_status), NULL, _usb_status_change);

    /* create mavproxy monitor to handle received msg */
    mavproxy_monitor_create();

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&_event_mavproxy, wait_set,
            RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_SEND_ALL_PARAM) {
                mavlink_param_send_all();
            }

            if (recv_set & EVENT_MAVCONSOLE_TIMEOUT) {
                mavlink_console_handle_timeout();
            }

            if (recv_set & EVENT_MAVPROXY_UPDATE) {
                // send out immediate msg
                _send_immediate_msg();
                // send out periodical msg
                _send_period_msg();
                // process mavlink command
                mavcmd_process();
            }
        } else {
            // some err happen
            console_printf("mavproxy loop, err:%d\r\n", res);
        }
    }
}

fmt_err mavproxy_init(void)
{
    /* init mavlink system info */
    _mavlink_system.sysid = FMT_MAVLINK_SYS_ID;
    _mavlink_system.compid = FMT_MAVLINK_COMP_ID;

    /* init message queue */
    _period_msg_queue.size = 0;
    _period_msg_queue.index = 0;
    _imm_msg_queue.head = 0;
    _imm_msg_queue.tail = 0;

    mavproxy_dev_init();
    mavlink_console_init();

    _mavproxy_tx_lock = rt_sem_create("mav_tx_lock", 1, RT_IPC_FLAG_FIFO);

    /* get mavlink console device */
    _mav_console_dev = rt_device_find("mav_console");
    /* create event */
    rt_event_init(&_event_mavproxy, "mavproxy", RT_IPC_FLAG_FIFO);

    /* register timer event */
    rt_timer_init(&_timer_mavproxy, "mav_update", _mavproxy_timer_update, RT_NULL, 2,
        RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    rt_timer_start(&_timer_mavproxy);

    return FMT_EOK;
}

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

#include "hal/serial.h"
#include "module/mavproxy/mavproxy.h"

#define MAVPROXY_INTERVAL            2
#define MAVPROXY_BUFFER_SIZE         1024
#define MAXperiod_mq_SIZE            20
#define MAX_IMMEDIATE_MSG_QUEUE_SIZE 10
#define MAVPROXY_DEFAULT_CHAN        0
#define MAVPROXY_UNSET_CHAN          0xFF

void mavproxy_monitor_create(void);
fmt_err mavproxy_switch_channel(uint8_t chan);
uint8_t mavproxy_get_channel_num(void);

typedef struct {
    uint8_t msgid;
    uint8_t enable;
    uint16_t period;
    uint32_t time_stamp;
    bool (*msg_pack_cb)(mavlink_message_t* msg_t);
} MAV_PeriodMsg;

typedef struct {
    MAV_PeriodMsg queue[MAXperiod_mq_SIZE];
    uint16_t size;
    uint16_t index;
} MAV_PeriodMsg_Queue;

typedef struct {
    mavlink_message_t queue[MAX_IMMEDIATE_MSG_QUEUE_SIZE];
    uint16_t head;
    uint16_t tail;
} MAV_ImmediateMsg_Queue;

typedef struct {
    mavlink_system_t system;
    MAV_ImmediateMsg_Queue imm_mq;
    MAV_PeriodMsg_Queue period_mq;
    rt_sem_t tx_lock;
    struct rt_timer timer;
    struct rt_event event;
    uint8_t chan;
    uint8_t new_chan;
    uint8_t* tx_buffer;
} mavproxy_handler;

static mavproxy_handler mav_handle = {
    .system = {
        .sysid = FMT_MAVLINK_SYS_ID,
        .compid = FMT_MAVLINK_COMP_ID },
    .imm_mq = { .head = 0, .tail = 0 },
    .period_mq = { .size = 0, .index = 0 },
    .chan = MAVPROXY_UNSET_CHAN,
    .new_chan = 0,
    .tx_buffer = NULL
};

static void mavproxy_timer_update(void* parameter)
{
    rt_event_send(&mav_handle.event, EVENT_MAVPROXY_UPDATE);
}

static uint8_t _send_immediate_msg(void)
{
    while (mav_handle.imm_mq.head != mav_handle.imm_mq.tail) {
        if (mavproxy_send_immediate_msg(&mav_handle.imm_mq.queue[mav_handle.imm_mq.tail], true) == FMT_EOK) {
            OS_ENTER_CRITICAL;
            mav_handle.imm_mq.tail = (mav_handle.imm_mq.tail + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
            OS_EXIT_CRITICAL;
        }
    }

    return 1;
}

static uint8_t _send_period_msg(void)
{
    for (uint16_t i = 0; i < mav_handle.period_mq.size; i++) {
        uint32_t now = systime_now_ms();
        MAV_PeriodMsg* msg_t = &mav_handle.period_mq.queue[mav_handle.period_mq.index];
        mav_handle.period_mq.index = (mav_handle.period_mq.index + 1) % mav_handle.period_mq.size;

        // find next msg to send
        if (now - msg_t->time_stamp >= msg_t->period && msg_t->enable) {
            msg_t->time_stamp = now;
            // pack msg
            mavlink_message_t msg;
            if (msg_t->msg_pack_cb(&msg) == true) {
                // send out msg
                mavproxy_send_immediate_msg(&msg, true);
            }
        }
    }

    return 1;
}

static void _send_mavlink_command_ack(mavlink_command_ack_t* command_ack, mavlink_message_t* msg)
{
    mavlink_msg_command_ack_encode(mav_handle.system.sysid, mav_handle.system.compid,
        msg, command_ack);

    mavproxy_send_immediate_msg(msg, true);
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
            mavcmd_set(MAVCMD_CALIBRATION_LEVEL, NULL);
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
    msg_pack_cb_t msg_pack_cb, uint8_t enable)
{
    MAV_PeriodMsg msg;

    msg.msgid = msgid;
    msg.enable = enable;
    msg.period = period_ms;
    msg.msg_pack_cb = msg_pack_cb;
    /* Add offset for msg */
    msg.time_stamp = systime_now_ms() + mav_handle.period_mq.size * MAVPROXY_INTERVAL;

    if (mav_handle.period_mq.size < MAXperiod_mq_SIZE) {
        OS_ENTER_CRITICAL;
        mav_handle.period_mq.queue[mav_handle.period_mq.size++] = msg;
        OS_EXIT_CRITICAL;
        return 1;
    } else {
        console_printf("mavproxy period msg queue is full\n");
        return 0;
    }
}

fmt_err mavproxy_send_immediate_msg(const mavlink_message_t* msg, bool sync)
{
    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(mav_handle.tx_lock, RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(mav_handle.tx_buffer, msg);
        size = mavproxy_dev_write(mav_handle.tx_buffer, len, RT_WAITING_FOREVER);

        rt_sem_release(mav_handle.tx_lock);

        return size == len ? FMT_EOK : FMT_ERROR;
    }

    /* otherwise, push msg into queue (asynchronize mode) */
    OS_ENTER_CRITICAL;

    if ((mav_handle.imm_mq.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE == mav_handle.imm_mq.tail) {
        OS_EXIT_CRITICAL;
        return FMT_EFULL;
    }

    mav_handle.imm_mq.queue[mav_handle.imm_mq.head] = *msg;
    mav_handle.imm_mq.head = (mav_handle.imm_mq.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
    OS_EXIT_CRITICAL;

    /* wakeup mavproxy to send out temporary msg immediately */
    rt_event_send(&mav_handle.event, EVENT_MAVPROXY_UPDATE);

    return FMT_EOK;
}

fmt_err mavproxy_send_event(uint32_t event_set)
{
    return rt_event_send(&mav_handle.event, event_set);
}

mavlink_system_t mavproxy_get_system(void)
{
    return mav_handle.system;
}

fmt_err mavproxy_set_channel(uint8_t chan)
{
    if (chan >= mavproxy_get_channel_num()) {
        return FMT_EINVAL;
    }
    OS_ENTER_CRITICAL;
    mav_handle.new_chan = chan;
    OS_EXIT_CRITICAL;

    return FMT_EOK;
}

void mavproxy_loop(void)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAVPROXY_UPDATE | EVENT_MAVCONSOLE_TIMEOUT | EVENT_SEND_ALL_PARAM;

    /* create mavproxy monitor to handle received msg */
    mavproxy_monitor_create();

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&mav_handle.event, wait_set,
            RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR,
            RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            /* switch mavproxy channel if needed */
            if (mav_handle.chan != mav_handle.new_chan) {
                if (mavproxy_switch_channel(mav_handle.new_chan) == FMT_EOK) {
                    mav_handle.chan = mav_handle.new_chan;
                } else {
                    console_printf("mavproxy switch channel fail!\n");
                    mav_handle.new_chan = mav_handle.chan;
                }
            }

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
                mavproxy_cmd_process();
            }
        } else {
            // some err happen
            console_printf("mavproxy loop, err:%d\r\n", res);
        }
    }
}

/**
 * Initialize the mavproxy module.
 * 
 * @return FMT Errors
 */
fmt_err mavproxy_init(void)
{
    /* init mavproxy device */
    mavproxy_dev_init();

    /* init mavlink console */
    mavlink_console_init();

    /* create tx lock */
    mav_handle.tx_lock = rt_sem_create("mav_tx_lock", 1, RT_IPC_FLAG_FIFO);

    /* malloc buffer space */
    mav_handle.tx_buffer = (uint8_t*)rt_malloc(MAVPROXY_BUFFER_SIZE);
    if (mav_handle.tx_buffer == NULL) {
        console_printf("fail to malloc for mavproxy tx buffer\n");
        return FMT_ENOMEM;
    }

    /* create event */
    rt_event_init(&mav_handle.event, "mavproxy", RT_IPC_FLAG_FIFO);

    /* register timer event to periodly wakeup itself */
    rt_timer_init(&mav_handle.timer, "mav_update", mavproxy_timer_update, RT_NULL, MAVPROXY_INTERVAL,
        RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    rt_timer_start(&mav_handle.timer);

    return FMT_EOK;
}

/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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
#include "module/mavproxy/mavproxy_config.h"

#define MAVPROXY_INTERVAL            1
#define MAVPROXY_BUFFER_SIZE         1024
#define MAX_PERIOD_MSG_QUEUE_SIZE    20
#define MAX_IMMEDIATE_MSG_QUEUE_SIZE 10
#define MAVPROXY_UNSET_CHAN          0xFF
#define MAX_DUMP_MSG_COUNT           20

typedef struct {
    uint8_t msgid;
    uint8_t enable;
    uint16_t period;
    uint32_t time_stamp;
    bool (*msg_pack_cb)(mavlink_message_t* msg_t);
} mav_period_msg;

typedef struct {
    mav_period_msg queue[MAX_PERIOD_MSG_QUEUE_SIZE];
    uint16_t size;
    uint16_t index;
} mav_period_msg_queue;

typedef struct {
    mavlink_message_t queue[MAX_IMMEDIATE_MSG_QUEUE_SIZE];
    uint16_t head;
    uint16_t tail;
} mav_immediate_msg_queue;

typedef struct {
    mavlink_system_t system;
    struct rt_timer timer[MAVPROXY_CHAN_NUM];
    struct rt_event event[MAVPROXY_CHAN_NUM];
    mav_immediate_msg_queue imm_mq[MAVPROXY_CHAN_NUM];
    mav_period_msg_queue period_mq[MAVPROXY_CHAN_NUM];
    rt_sem_t tx_lock[MAVPROXY_CHAN_NUM];
    uint8_t devid[MAVPROXY_CHAN_NUM];
    uint8_t new_devid[MAVPROXY_CHAN_NUM];
    uint8_t* tx_buffer[MAVPROXY_CHAN_NUM];
} mavproxy_handler;

static mavproxy_handler mav_handle = {
    .devid = { MAVPROXY_UNSET_CHAN, MAVPROXY_UNSET_CHAN },
    .new_devid = { MAVPROXY_UNSET_CHAN, MAVPROXY_UNSET_CHAN },
};

static void on_param_modify(param_t* param)
{
    /* parameter modified, send new value to GCS */
    mavlink_param_send(param);
}

static void mavproxy_chan0_timer_update(void* parameter)
{
    rt_event_send(&mav_handle.event[0], EVENT_MAVPROXY_UPDATE);
}

static void mavproxy_chan1_timer_update(void* parameter)
{
    rt_event_send(&mav_handle.event[1], EVENT_MAVPROXY_UPDATE);
}

static void dump_immediate_msg(uint8_t chan)
{
    uint16_t cnt = 0;
    while (mav_handle.imm_mq[chan].head != mav_handle.imm_mq[chan].tail) {
        if (mavproxy_send_immediate_msg(chan, &mav_handle.imm_mq[chan].queue[mav_handle.imm_mq[chan].tail], true) == FMT_EOK) {
            OS_ENTER_CRITICAL;
            mav_handle.imm_mq[chan].tail = (mav_handle.imm_mq[chan].tail + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
            OS_EXIT_CRITICAL;

            if (++cnt >= MAX_DUMP_MSG_COUNT) {
                /* To prevent sending data too rapidly and overwhelming the buffer, ensure that this while loop does not overrun. */
                break;
            }
        }
    }
}

static void dump_period_msg(uint8_t chan)
{
    for (uint16_t i = 0; i < mav_handle.period_mq[chan].size; i++) {
        uint32_t now = systime_now_ms();
        mav_period_msg* msg_t = &mav_handle.period_mq[chan].queue[mav_handle.period_mq[chan].index];
        mav_handle.period_mq[chan].index = (mav_handle.period_mq[chan].index + 1) % mav_handle.period_mq[chan].size;

        /* find next msg to send */
        if (now - msg_t->time_stamp >= msg_t->period && msg_t->enable && msg_t->msg_pack_cb) {
            msg_t->time_stamp = now;
            /* pack msg */
            mavlink_message_t msg;
            if (msg_t->msg_pack_cb(&msg) == true) {
                /* send out msg */
                mavproxy_send_immediate_msg(chan, &msg, true);
            }
        }
    }
}

/**
 * Register to send a mavlink message periodically
 * 
 * @param msgid mavlink message id
 * @param msg_rate_hz  message send rate in Hz
 * @param msg_pack_cb callback function to prepare the mavlink message data
 * @param auto_start auto start of sending the message
 * 
 * @return FMT Errors
 */
fmt_err_t mavproxy_register_period_msg(uint8_t chan, uint8_t msgid, uint16_t msg_rate_hz,
                                       msg_pack_cb_t msg_pack_cb, bool start)
{
    mav_period_msg msg;

    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    msg.msgid = msgid;
    msg.enable = (start == true) ? 1 : 0;
    msg.period = 1000.0f / msg_rate_hz;
    msg.msg_pack_cb = msg_pack_cb;
    /* Add offset for each msg to stagger sending time */
    msg.time_stamp = systime_now_ms() + mav_handle.period_mq[chan].size * MAVPROXY_INTERVAL;

    /* check if the message is already registered, if so, just update it. */
    for (uint16_t i = 0; i < mav_handle.period_mq[chan].size; i++) {
        if (mav_handle.period_mq[chan].queue[i].msgid == msgid) {
            OS_ENTER_CRITICAL;
            mav_handle.period_mq[chan].queue[i] = msg;
            OS_EXIT_CRITICAL;
            return FMT_EOK;
        }
    }

    /* push message to period queue */
    if (mav_handle.period_mq[chan].size < MAX_PERIOD_MSG_QUEUE_SIZE) {
        OS_ENTER_CRITICAL;
        mav_handle.period_mq[chan].queue[mav_handle.period_mq[chan].size++] = msg;
        OS_EXIT_CRITICAL;
        return FMT_EOK;
    } else {
        console_printf("mavproxy period msg queue is full\n");
        return FMT_EFULL;
    }
}

/**
 * Send a mavlink message via the mavproxy device
 * 
 * @param msg mavlink message
 * @param sync  true: wait until the mavproxy device is available and send message
 *              false: push the message into a queue and return directly
 * 
 * @return FMT Errors
 */
fmt_err_t mavproxy_send_immediate_msg(uint8_t chan, const mavlink_message_t* msg, bool sync)
{
    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(mav_handle.tx_lock[chan], RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(mav_handle.tx_buffer[chan], msg);
        size = mavproxy_dev_write(chan, mav_handle.tx_buffer[chan], len, RT_WAITING_FOREVER);

        rt_sem_release(mav_handle.tx_lock[chan]);

        return size == len ? FMT_EOK : FMT_ERROR;
    }

    /* otherwise, push msg into queue (asynchronize mode) */
    OS_ENTER_CRITICAL;

    if ((mav_handle.imm_mq[chan].head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE == mav_handle.imm_mq[chan].tail) {
        OS_EXIT_CRITICAL;
        return FMT_EFULL;
    }

    mav_handle.imm_mq[chan].queue[mav_handle.imm_mq[chan].head] = *msg;
    mav_handle.imm_mq[chan].head = (mav_handle.imm_mq[chan].head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
    OS_EXIT_CRITICAL;

    /* wakeup mavproxy to send out temporary msg immediately */
    rt_event_send(&mav_handle.event[chan], EVENT_MAVPROXY_UPDATE);

    return FMT_EOK;
}

/**
 * Send a event to mavproxy
 * 
 * @brief the event will be handled in mavproxy main loop
 * 
 * @param event_set event set
 * 
 * @return FMT Errors
 */
fmt_err_t mavproxy_send_event(uint8_t chan, uint32_t event_set)
{
    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    return rt_event_send(&mav_handle.event[chan], event_set);
}

/**
 * Get mavlink system information. sysid and compid
 * 
 * @return mavlink system
 */
mavlink_system_t mavproxy_get_system(void)
{
    return mav_handle.system;
}

/**
 * Set mavproxy channel.
 * 
 * @param chan channel of mavproxy device
 * @param devid mavproxy device id
 * 
 * @return FMT Errors
 */
fmt_err_t mavproxy_set_device(uint8_t chan, uint8_t devid)
{
    if (chan >= MAVPROXY_CHAN_NUM) {
        return FMT_EINVAL;
    }

    if (devid >= mavproxy_get_dev_num(chan)) {
        return FMT_EINVAL;
    }

    OS_ENTER_CRITICAL;
    mav_handle.new_devid[chan] = devid;
    OS_EXIT_CRITICAL;

    return FMT_EOK;
}

/**
 * @brief Main loop for mavproxy channel
 * 
 * @param chan mavproxy channel
 */
void mavproxy_channel_loop(uint8_t chan)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = chan == MAVPROXY_GCS_CHAN ? (EVENT_MAVPROXY_UPDATE | EVENT_MAVCONSOLE_TIMEOUT | EVENT_SEND_ALL_PARAM) : EVENT_MAVPROXY_UPDATE;

    if (chan >= MAVPROXY_CHAN_NUM) {
        return;
    }

    /* Set mavproxy new channel to 0 if not set. Here we need critical section
       since the new channel can possible be set in usb ISR. */
    OS_ENTER_CRITICAL;
    if (mavproxy_get_dev_num(chan) > 0 && mav_handle.new_devid[chan] == MAVPROXY_UNSET_CHAN) {
        mav_handle.new_devid[chan] = 0;
    }
    OS_EXIT_CRITICAL;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&mav_handle.event[chan], wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            /* switch mavproxy channel if needed */
            if (mav_handle.devid[chan] != mav_handle.new_devid[chan]) {
                if (mavproxy_switch_dev(chan, mav_handle.new_devid[chan]) == FMT_EOK) {
                    mav_handle.devid[chan] = mav_handle.new_devid[chan];
                } else {
                    console_printf("mavproxy switch channel fail! current devid:%d new devid:%d\n",
                                   mav_handle.devid[chan],
                                   mav_handle.new_devid[chan]);
                    mav_handle.new_devid[chan] = mav_handle.devid[chan];
                }
            }

            if (recv_set & EVENT_SEND_ALL_PARAM) {
                mavlink_param_sendall();
            }

            if (recv_set & EVENT_MAVCONSOLE_TIMEOUT) {
                mavlink_console_handle_timeout();
            }

            if (recv_set & EVENT_MAVPROXY_UPDATE) {
                /* send out immediate msg */
                dump_immediate_msg(chan);
                /* send out periodical msg */
                dump_period_msg(chan);
                if (chan == MAVPROXY_GCS_CHAN) {
                    /* handle mavlink command */
                    mavproxy_cmd_exec();
                }
            }
        }
    }
}

/**
 * Initialize the mavproxy module.
 * 
 * @return FMT Errors
 */
fmt_err_t mavproxy_init(void)
{
    /* get mavlink system and component ID */
    mav_handle.system.sysid = PARAM_GET_UINT8(SYSTEM, MAV_SYS_ID);
    mav_handle.system.compid = PARAM_GET_UINT8(SYSTEM, MAV_COMP_ID);

    /* init mavproxy device */
    mavproxy_dev_init();

    /* init mavlink console */
    mavlink_console_init();

    /* create tx lock */
    mav_handle.tx_lock[0] = rt_sem_create("mav0_tx_lock", 1, RT_IPC_FLAG_FIFO);
    mav_handle.tx_lock[1] = rt_sem_create("mav1_tx_lock", 1, RT_IPC_FLAG_FIFO);
    FMT_ASSERT((mav_handle.tx_lock[0] != NULL) && (mav_handle.tx_lock[1] != NULL));

    /* malloc buffer space */
    mav_handle.tx_buffer[0] = (uint8_t*)rt_malloc(MAVPROXY_BUFFER_SIZE);
    mav_handle.tx_buffer[1] = (uint8_t*)rt_malloc(MAVPROXY_BUFFER_SIZE);
    FMT_ASSERT((mav_handle.tx_buffer[0] != NULL) && (mav_handle.tx_buffer[1] != NULL));

    /* create event */
    RT_CHECK(rt_event_init(&mav_handle.event[0], "mav_chan0", RT_IPC_FLAG_FIFO));
    RT_CHECK(rt_event_init(&mav_handle.event[1], "mav_chan1", RT_IPC_FLAG_FIFO));

    /* register parameter modify callback */
    register_param_modify_callback(on_param_modify);

    /* register timer event to periodly wakeup itself */
    rt_timer_init(&mav_handle.timer[0], "mav_chan0", mavproxy_chan0_timer_update, RT_NULL, MAVPROXY_INTERVAL, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    RT_CHECK(rt_timer_start(&mav_handle.timer[0]));
    rt_timer_init(&mav_handle.timer[1], "mav_chan1", mavproxy_chan1_timer_update, RT_NULL, MAVPROXY_INTERVAL, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    RT_CHECK(rt_timer_start(&mav_handle.timer[1]));

    /* create mavproxy monitor to handle received mavlink msgs */
    FMT_CHECK(mavproxy_monitor_create());

    return FMT_EOK;
}

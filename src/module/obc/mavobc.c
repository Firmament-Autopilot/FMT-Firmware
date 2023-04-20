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

#include "module/obc/mavobc.h"
#include "module/obc/mavobc_dev.h"

#define MAVOBC_INTERVAL              1
#define MAVOBC_BUFFER_SIZE           1024
#define MAX_PERIOD_MSG_QUEUE_SIZE    20
#define MAX_IMMEDIATE_MSG_QUEUE_SIZE 10
#define MAVOBC_UNSET_CHAN            0xFF

fmt_err_t mavobc_switch_channel(uint8_t chan);
uint8_t mavobc_get_channel_num(void);

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
    mav_immediate_msg_queue imm_mq;
    mav_period_msg_queue period_mq;
    rt_sem_t tx_lock;
    struct rt_timer timer;
    struct rt_event event;
    uint8_t chan;
    uint8_t new_chan;
    uint8_t* tx_buffer;
} mavobc_handler;

static mavobc_handler mav_handle = {
    .system = {
        .sysid = 0,
        .compid = 0 },
    .imm_mq = { .head = 0, .tail = 0 },
    .period_mq = { .size = 0, .index = 0 },
    .chan = MAVOBC_UNSET_CHAN,
    .new_chan = MAVOBC_UNSET_CHAN,
    .tx_buffer = NULL
};

static void mavobc_timer_update(void* parameter)
{
    rt_event_send(&mav_handle.event, EVENT_MAVOBC_UPDATE);
}

static void dump_immediate_msg(void)
{
    while (mav_handle.imm_mq.head != mav_handle.imm_mq.tail) {
        if (mavobc_send_immediate_msg(&mav_handle.imm_mq.queue[mav_handle.imm_mq.tail], true) == FMT_EOK) {
            OS_ENTER_CRITICAL;
            mav_handle.imm_mq.tail = (mav_handle.imm_mq.tail + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
            OS_EXIT_CRITICAL;
        }
    }
}

static void dump_period_msg(void)
{
    for (uint16_t i = 0; i < mav_handle.period_mq.size; i++) {
        uint32_t now = systime_now_ms();
        mav_period_msg* msg_t = &mav_handle.period_mq.queue[mav_handle.period_mq.index];
        mav_handle.period_mq.index = (mav_handle.period_mq.index + 1) % mav_handle.period_mq.size;

        /* find next msg to send */
        if (now - msg_t->time_stamp >= msg_t->period && msg_t->enable && msg_t->msg_pack_cb) {
            msg_t->time_stamp = now;
            /* pack msg */
            mavlink_message_t msg;
            if (msg_t->msg_pack_cb(&msg) == true) {
                /* send out msg */
                mavobc_send_immediate_msg(&msg, true);
            }
        }
    }
}

/**
 * Register to send a mavlink message periodically
 * 
 * @param msgid mavlink message id
 * @param period_ms  message send period in ms
 * @param msg_pack_cb callback function to prepare the mavlink message data
 * @param auto_start auto start of sending the message
 * 
 * @return FMT Errors
 */
fmt_err_t mavobc_register_period_msg(uint8_t msgid, uint16_t period_ms,
                                     msg_pack_cb_t msg_pack_cb, bool start)
{
    mav_period_msg msg;

    msg.msgid = msgid;
    msg.enable = (start == true) ? 1 : 0;
    msg.period = period_ms;
    msg.msg_pack_cb = msg_pack_cb;
    /* Add offset for each msg to stagger sending time */
    msg.time_stamp = systime_now_ms() + mav_handle.period_mq.size * MAVOBC_INTERVAL;

    /* check if the message is already registered, if so, just update it. */
    for (uint16_t i = 0; i < mav_handle.period_mq.size; i++) {
        if (mav_handle.period_mq.queue[i].msgid == msgid) {
            OS_ENTER_CRITICAL;
            mav_handle.period_mq.queue[i] = msg;
            OS_EXIT_CRITICAL;
            return FMT_EOK;
        }
    }

    /* push message to period queue */
    if (mav_handle.period_mq.size < MAX_PERIOD_MSG_QUEUE_SIZE) {
        OS_ENTER_CRITICAL;
        mav_handle.period_mq.queue[mav_handle.period_mq.size++] = msg;
        OS_EXIT_CRITICAL;
        return FMT_EOK;
    } else {
        printf("mavobc period msg queue is full\n");
        return FMT_EFULL;
    }
}

/**
 * Send a mavlink message via the mavobc device
 * 
 * @param msg mavlink message
 * @param sync  true: wait until the mavobc device is available and send message
 *              false: push the message into a queue and return directly
 * 
 * @return FMT Errors
 */
fmt_err_t mavobc_send_immediate_msg(const mavlink_message_t* msg, bool sync)
{
    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(mav_handle.tx_lock, RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(mav_handle.tx_buffer, msg);
        size = mavobc_dev_write(mav_handle.tx_buffer, len, RT_WAITING_FOREVER);

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

    /* wakeup mavobc to send out temporary msg immediately */
    rt_event_send(&mav_handle.event, EVENT_MAVOBC_UPDATE);

    return FMT_EOK;
}

/**
 * Get mavlink system information. sysid and compid
 * 
 * @return mavlink system
 */
mavlink_system_t mavobc_get_system(void)
{
    return mav_handle.system;
}

/**
 * Set mavobc channel.
 * 
 * @param chan channel of mavobc device
 * 
 * @return FMT Errors
 */
fmt_err_t mavobc_set_channel(uint8_t chan)
{
    if (chan >= mavobc_get_channel_num()) {
        return FMT_EINVAL;
    }
    OS_ENTER_CRITICAL;
    mav_handle.new_chan = chan;
    OS_EXIT_CRITICAL;

    return FMT_EOK;
}

/**
 * Main loop of mavlink onboard computer.
 * @note this function should be called in a thread
 */
void mavobc_loop(void)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MAVOBC_UPDATE;

    /* create mavobc monitor to handle received mavlink msgs */
    mavobc_monitor_create();

    /* Set mavobc new channel to 0 if not set. Here we need critical section
       since the new channel can possible be set in usb ISR. */
    OS_ENTER_CRITICAL;
    if (mavobc_get_channel_num() > 0 && mav_handle.new_chan == MAVOBC_UNSET_CHAN) {
        mav_handle.new_chan = 0;
    }
    OS_EXIT_CRITICAL;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&mav_handle.event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            /* switch mavobc channel if needed */
            if (mav_handle.chan != mav_handle.new_chan) {
                if (mavobc_switch_channel(mav_handle.new_chan) == FMT_EOK) {
                    mav_handle.chan = mav_handle.new_chan;
                } else {
                    printf("mavobc switch channel fail! current chan:%d new chan:%d\n",
                           mav_handle.chan,
                           mav_handle.new_chan);
                    mav_handle.new_chan = mav_handle.chan;
                }
            }

            if (recv_set & EVENT_MAVOBC_UPDATE) {
                /* send out immediate msg */
                dump_immediate_msg();
                /* send out periodical msg */
                dump_period_msg();
            }
        }
    }
}

/**
 * Initialize the mavlink onboard computer module.
 * 
 * @return FMT Errors
 */
fmt_err_t mavobc_init(void)
{
    /* get mavlink system and component ID */
    mav_handle.system.sysid = PARAM_GET_UINT8(SYSTEM, MAV_SYS_ID);
    mav_handle.system.compid = PARAM_GET_UINT8(SYSTEM, MAV_COMP_ID);

    /* init mavobc device */
    mavobc_dev_init();

    /* create tx lock */
    mav_handle.tx_lock = rt_sem_create("mavobc_tx_lock", 1, RT_IPC_FLAG_FIFO);

    /* malloc buffer space */
    mav_handle.tx_buffer = (uint8_t*)rt_malloc(MAVOBC_BUFFER_SIZE);
    if (mav_handle.tx_buffer == NULL) {
        printf("fail to malloc for mavobc tx buffer\n");
        return FMT_ENOMEM;
    }

    /* create event */
    rt_event_init(&mav_handle.event, "mavobc", RT_IPC_FLAG_FIFO);

    /* register timer event to periodly wakeup itself */
    rt_timer_init(&mav_handle.timer, "mavobc", mavobc_timer_update, RT_NULL, MAVOBC_INTERVAL, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);
    rt_timer_start(&mav_handle.timer);

    return FMT_EOK;
}

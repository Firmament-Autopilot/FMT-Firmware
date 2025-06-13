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
#include "module/utils/list.h"

#define MAVPROXY_INTERVAL            1
#define MAX_PERIOD_MSG_QUEUE_SIZE    25
#define MAX_IMMEDIATE_MSG_QUEUE_SIZE 20
#define MAVPROXY_BUFFER_SIZE         1024
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
    struct rt_timer timer;
    struct rt_event event;
    mav_immediate_msg_queue imm_mq;
    mav_period_msg_queue period_mq;
    rt_sem_t tx_lock;
    uint8_t devid;
    uint8_t new_devid;
    uint8_t* tx_buffer;
    struct list_head rx_handler_list;
} mavproxy_chan_handler;

typedef struct {
    mavlink_system_t system;
    mavproxy_chan_handler* chan_handle_list[MAXPROXY_MAX_CHAN];
} mavproxy_handler;

static mavproxy_handler mav_handle;

static void on_param_modify(param_t* param)
{
    /* parameter modified, send new value to GCS */
    mavlink_param_send(param, MAVPROXY_GCS_CHAN);
}

static void mavproxy_chan_timer_update(void* parameter)
{
    rt_event_send(&mav_handle.chan_handle_list[(uint32_t)parameter]->event, EVENT_MAVPROXY_UPDATE);
}

static void dump_immediate_msg(uint8_t chan)
{
    uint16_t cnt = 0;

    if (mav_handle.chan_handle_list[chan] == NULL)
        return;

    while (mav_handle.chan_handle_list[chan]->imm_mq.head != mav_handle.chan_handle_list[chan]->imm_mq.tail) {
        if (mavproxy_send_immediate_msg(chan, &mav_handle.chan_handle_list[chan]->imm_mq.queue[mav_handle.chan_handle_list[chan]->imm_mq.tail], true) == FMT_EOK) {
            OS_ENTER_CRITICAL;
            mav_handle.chan_handle_list[chan]->imm_mq.tail = (mav_handle.chan_handle_list[chan]->imm_mq.tail + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
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
    if (mav_handle.chan_handle_list[chan] == NULL)
        return;

    for (uint16_t i = 0; i < mav_handle.chan_handle_list[chan]->period_mq.size; i++) {
        uint32_t now = systime_now_ms();
        mav_period_msg* msg_t = &mav_handle.chan_handle_list[chan]->period_mq.queue[mav_handle.chan_handle_list[chan]->period_mq.index];
        mav_handle.chan_handle_list[chan]->period_mq.index = (mav_handle.chan_handle_list[chan]->period_mq.index + 1) % mav_handle.chan_handle_list[chan]->period_mq.size;

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

    if (mav_handle.chan_handle_list[chan] == NULL)
        return FMT_EINVAL;

    msg.msgid = msgid;
    msg.enable = (start == true) ? 1 : 0;
    msg.period = 1000.0f / msg_rate_hz;
    msg.msg_pack_cb = msg_pack_cb;
    /* Add offset for each msg to stagger sending time */
    msg.time_stamp = systime_now_ms() + mav_handle.chan_handle_list[chan]->period_mq.size * MAVPROXY_INTERVAL;

    /* check if the message is already registered, if so, just update it. */
    for (uint16_t i = 0; i < mav_handle.chan_handle_list[chan]->period_mq.size; i++) {
        if (mav_handle.chan_handle_list[chan]->period_mq.queue[i].msgid == msgid) {
            OS_ENTER_CRITICAL;
            mav_handle.chan_handle_list[chan]->period_mq.queue[i] = msg;
            OS_EXIT_CRITICAL;
            return FMT_EOK;
        }
    }

    /* push message to period queue */
    if (mav_handle.chan_handle_list[chan]->period_mq.size < MAX_PERIOD_MSG_QUEUE_SIZE) {
        OS_ENTER_CRITICAL;
        mav_handle.chan_handle_list[chan]->period_mq.queue[mav_handle.chan_handle_list[chan]->period_mq.size++] = msg;
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
    if (mav_handle.chan_handle_list[chan] == NULL)
        return FMT_EINVAL;

    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(mav_handle.chan_handle_list[chan]->tx_lock, RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(mav_handle.chan_handle_list[chan]->tx_buffer, msg);
        size = mavproxy_dev_write(chan, mav_handle.chan_handle_list[chan]->tx_buffer, len, TICKS_FROM_MS(500));

        rt_sem_release(mav_handle.chan_handle_list[chan]->tx_lock);

        return size == len ? FMT_EOK : FMT_ERROR;
    }

    /* otherwise, push msg into queue (asynchronize mode) */
    OS_ENTER_CRITICAL;

    if ((mav_handle.chan_handle_list[chan]->imm_mq.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE == mav_handle.chan_handle_list[chan]->imm_mq.tail) {
        OS_EXIT_CRITICAL;
        return FMT_EFULL;
    }

    mav_handle.chan_handle_list[chan]->imm_mq.queue[mav_handle.chan_handle_list[chan]->imm_mq.head] = *msg;
    mav_handle.chan_handle_list[chan]->imm_mq.head = (mav_handle.chan_handle_list[chan]->imm_mq.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
    OS_EXIT_CRITICAL;

    /* wakeup mavproxy to send out temporary msg immediately */
    rt_event_send(&mav_handle.chan_handle_list[chan]->event, EVENT_MAVPROXY_UPDATE);

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
    if (mav_handle.chan_handle_list[chan] == NULL)
        return FMT_EINVAL;

    return rt_event_send(&mav_handle.chan_handle_list[chan]->event, event_set);
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

bool mavproxy_is_valid_chan(uint8_t chan)
{
    return chan < MAXPROXY_MAX_CHAN && mav_handle.chan_handle_list[chan] != NULL;
}

struct list_head* mavproxy_get_rx_handler_list(uint8_t chan)
{
    if (mavproxy_is_valid_chan(chan)) {
        return &mav_handle.chan_handle_list[chan]->rx_handler_list;
    } else {
        return NULL;
    }
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
    if (mav_handle.chan_handle_list[chan] == NULL)
        return FMT_EINVAL;

    if (devid >= mavproxy_get_dev_num(chan)) {
        return FMT_EINVAL;
    }

    OS_ENTER_CRITICAL;
    mav_handle.chan_handle_list[chan]->new_devid = devid;
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
    rt_uint32_t wait_set = chan == MAVPROXY_GCS_CHAN ? (EVENT_MAVPROXY_UPDATE | EVENT_MAVCONSOLE_TIMEOUT | EVENT_SEND_ALL_PARAM | EVENT_SEND_NEXT_PARAM) : EVENT_MAVPROXY_UPDATE;

    if (mav_handle.chan_handle_list[chan] == NULL)
        return;

    if (chan == MAVPROXY_GCS_CHAN) {
        /* init mavlink rtcm devices */
        mavlink_rtcm_device_init();
    }

    /* Set mavproxy new channel to 0 if not set. Here we need critical section
       since the new channel can possible be set in usb ISR. */
    OS_ENTER_CRITICAL;
    if (mavproxy_get_dev_num(chan) > 0 && mav_handle.chan_handle_list[chan]->new_devid == MAVPROXY_UNSET_CHAN) {
        mav_handle.chan_handle_list[chan]->new_devid = 0;
    }
    OS_EXIT_CRITICAL;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&mav_handle.chan_handle_list[chan]->event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            /* switch mavproxy channel if needed */
            if (mav_handle.chan_handle_list[chan]->devid != mav_handle.chan_handle_list[chan]->new_devid) {
                if (mavproxy_switch_dev(chan, mav_handle.chan_handle_list[chan]->new_devid) == FMT_EOK) {
                    mav_handle.chan_handle_list[chan]->devid = mav_handle.chan_handle_list[chan]->new_devid;
                } else {
                    console_printf("mavproxy chan%d switch channel fail! current devid:%d new devid:%d\n",
                                   chan,
                                   mav_handle.chan_handle_list[chan]->devid,
                                   mav_handle.chan_handle_list[chan]->new_devid);
                    mav_handle.chan_handle_list[chan]->new_devid = mav_handle.chan_handle_list[chan]->devid;
                }
            }

            if (chan == MAVPROXY_GCS_CHAN) {
                if (recv_set & EVENT_SEND_ALL_PARAM) {
                    mavlink_param_sendall();
                }

                if (recv_set & EVENT_SEND_NEXT_PARAM) {
                    /* Send next parameter */
                    mavlink_param_send_next();
                }

                if (recv_set & EVENT_MAVCONSOLE_TIMEOUT) {
                    mavlink_console_handle_timeout();
                }
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

fmt_err_t mavproxy_register_channel(uint8_t chan)
{
    mavproxy_chan_handler* chan_handler;
    uint32_t chan_id = chan;
    char name_buf[50];

    if (chan >= MAXPROXY_MAX_CHAN) {
        /* no enough channel available */
        return FMT_EINVAL;
    }

    if (mav_handle.chan_handle_list[chan] != NULL) {
        /* channel is occupied */
        return FMT_ENOSYS;
    }

    OS_ENTER_CRITICAL;
    mav_handle.chan_handle_list[chan] = (mavproxy_chan_handler*)rt_malloc(sizeof(mavproxy_chan_handler));
    if (mav_handle.chan_handle_list[chan] == NULL) {
        OS_EXIT_CRITICAL;
        return FMT_ENOMEM;
    }

    chan_handler = mav_handle.chan_handle_list[chan];

    /* init variables */
    chan_handler->devid = chan_handler->new_devid = MAVPROXY_UNSET_CHAN;
    chan_handler->imm_mq.head = chan_handler->imm_mq.tail = 0;
    chan_handler->period_mq.index = chan_handler->period_mq.size = 0;

    /* init rx handler list head */
    chan_handler->rx_handler_list.prev = &chan_handler->rx_handler_list;
    chan_handler->rx_handler_list.next = &chan_handler->rx_handler_list;

    /* create tx lock */
    sprintf(name_buf, "mav%u_tx_lock", chan);
    chan_handler->tx_lock = rt_sem_create(name_buf, 1, RT_IPC_FLAG_FIFO);
    FMT_ASSERT(chan_handler->tx_lock != NULL);

    /* malloc buffer space */
    chan_handler->tx_buffer = (uint8_t*)rt_malloc(MAVPROXY_BUFFER_SIZE);
    FMT_ASSERT(chan_handler->tx_buffer != NULL);

    /* create event */
    sprintf(name_buf, "mav_chan%u", chan);
    RT_CHECK(rt_event_init(&chan_handler->event, name_buf, RT_IPC_FLAG_FIFO));

    /* register timer event to periodly wakeup itself */
    rt_timer_init(&chan_handler->timer, name_buf, mavproxy_chan_timer_update, (void*)chan_id, MAVPROXY_INTERVAL, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    RT_CHECK(rt_timer_start(&chan_handler->timer));

    OS_EXIT_CRITICAL;

    return FMT_EOK;
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

    /* register parameter modify callback */
    register_param_modify_callback(on_param_modify);

    mavlink_param_init();

    /* create mavproxy monitor to handle received mavlink msgs */
    FMT_CHECK(mavproxy_monitor_create());

    return FMT_EOK;
}

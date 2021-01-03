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

#include "hal/cdcacm.h"
#include "hal/serial.h"
#include "module/mavproxy/mavproxy.h"

#define MAVPROXY_INTERVAL            2
#define MAX_PERIOD_MSG_QUEUE_SIZE    20
#define MAX_IMMEDIATE_MSG_QUEUE_SIZE 10
#define MAVPROXY_SERIAL_BAUDRATE     57600
#define MAVPROXY_MAX_DEVICE_NUM      5
#define MAVPROXY_DEFAULT_CHAN        0
#define MAVPROXY_UNSET_CHAN          0xFF

#define MATCH(a, b)                 (strcmp(a, b) == 0)
#define DEVICE_LIST                 _mavproxy_device_list
#define DEVICE_NUM                  _mavproxy_device_num
#define DEVICE_TYPE_IS(_idx, _name) MATCH(DEVICE_LIST[_idx].type, #_name)

void mavproxy_monitor_create(void);

/* subscribed uMCN topics */
MCN_DECLARE(ins_output);
MCN_DECLARE(usb_status);

typedef struct {
    uint8_t msgid;
    uint8_t enable;
    uint16_t period;
    uint32_t time_stamp;
    bool (*msg_pack_cb)(mavlink_message_t* msg_t);
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

typedef struct {
    uint32_t baudrate;
} mavproxy_serial_dev_config;

typedef struct {
    char* type;
    char* name;
    void* config;
} mavproxy_device_info;

static uint8_t _mav_tx_buff[1024];
static rt_sem_t _mavproxy_tx_lock;
static MAV_PeriodMsg_Queue _period_msg_queue;
static MAV_ImmediateMsg_Queue _imm_msg_queue;
static struct rt_timer _timer_mavproxy;
static struct rt_event _event_mavproxy;
static uint8_t _mav_dev_chan = MAVPROXY_UNSET_CHAN;
static uint8_t _new_mav_dev_chan = MAVPROXY_DEFAULT_CHAN;
static mavproxy_device_info _mavproxy_device_list[MAVPROXY_MAX_DEVICE_NUM] = { 0 };
static uint8_t _mavproxy_device_num = 0;
static mavlink_system_t _mavlink_system = {
    .sysid = FMT_MAVLINK_SYS_ID,
    .compid = FMT_MAVLINK_COMP_ID
};

/////////////// TOML Configuration //////////////
void list_mavproxy_devices(void)
{
    for (int i = 0; i < DEVICE_NUM; i++) {
        console_printf("[mavproxy %d]:\n", i);
        console_printf("type:%s\n", _mavproxy_device_list[i].type);
        console_printf("name:%s\n", _mavproxy_device_list[i].name);
        if (DEVICE_TYPE_IS(i, serial)) {
            mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)_mavproxy_device_list[i].config;
            console_printf("baudrate:%d\n", config->baudrate);
        }
        console_printf("\n");
    }
}

static void _init_device_list(void)
{
    for (int i = 0; i < MAVPROXY_MAX_DEVICE_NUM; i++) {
        if (DEVICE_LIST[i].type) {
            rt_free(DEVICE_LIST[i].type);
        }
        if (DEVICE_LIST[i].name) {
            rt_free(DEVICE_LIST[i].name);
        }
        if (DEVICE_LIST[i].config) {
            rt_free(DEVICE_LIST[i].config);
        }
        DEVICE_LIST[i].type = NULL;
        DEVICE_LIST[i].name = NULL;
        DEVICE_LIST[i].config = NULL;
    }
    DEVICE_NUM = 0;
}

static fmt_err _mavproxy_parse_device(const toml_table_t* curtab, int idx)
{
    fmt_err err = FMT_EOK;
    int i;
    const char* key;

    /* get device type */
    if (toml_string_in(curtab, "type", &DEVICE_LIST[idx].type) == 0) {
        if (DEVICE_TYPE_IS(idx, serial)) {
            mavproxy_serial_dev_config serial_default_config = {
                .baudrate = MAVPROXY_SERIAL_BAUDRATE
            };
            DEVICE_LIST[idx].config = rt_malloc(sizeof(mavproxy_serial_dev_config));

            /* set default value */
            if (DEVICE_LIST[idx].config) {
                *(mavproxy_serial_dev_config*)DEVICE_LIST[idx].config = serial_default_config;
            } else {
                console_printf("TOML Mavproxy: fail to malloc memory\n");
                err = FMT_ERROR;
            }
        } else if (DEVICE_TYPE_IS(idx, usb)) {
            /* no configuration for usb device */
        } else {
            console_printf("TOML Mavproxy: unknown device type: %s\n", DEVICE_LIST[idx].type);
            err = FMT_ERROR;
        }
    } else {
        console_printf("TOML Mavproxy: fail to parse type value\n");
        return FMT_ERROR;
    }

    if (toml_string_in(curtab, "name", &DEVICE_LIST[idx].name) != 0) {
        console_printf("TOML Mavproxy: fail to parse name value\n");
        return FMT_ERROR;
    }

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(curtab, i)); i++) {
        if (MATCH(key, "type") || MATCH(key, "name")) {
            /* already handled */
            continue;
        }

        if (DEVICE_TYPE_IS(idx, serial)) {
            mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)DEVICE_LIST[idx].config;
            if (MATCH(key, "baudrate")) {
                int64_t ival;
                if (toml_int_in(curtab, key, &ival) == 0) {
                    config->baudrate = (uint32_t)ival;
                } else {
                    console_printf("TOML Mavproxy: fail to parse baudrate value\n");
                    continue;
                }
            } else {
                console_printf("TOML Mavproxy: unknown config key: %s\n", key);
                continue;
            }
        } else if (DEVICE_TYPE_IS(idx, usb)) {
            console_printf("TOML Mavproxy: unknown config key: %s\n", key);
            continue;
        } else {
            // unknown type
            continue;
        }
    }

    return err;
}

static fmt_err _mavproxy_parse_devices(const toml_array_t* array)
{
    int i;
    toml_table_t* curtab;
    fmt_err err = FMT_EOK;
    uint32_t idx = 0;

    for (i = 0; 0 != (curtab = toml_table_at(array, i)); i++) {
        err = _mavproxy_parse_device(curtab, idx);

        if (err != FMT_EOK) {
            console_printf("TOML Mavproxy: device parse fail: %d\n", err);
            continue;
        }

        if (++idx >= MAVPROXY_MAX_DEVICE_NUM) {
            console_printf("TOML Mavproxy: too many devices\n");
            break;
        }
    }

    DEVICE_NUM = idx;

    return err;
}
/////////////// TOML Configuration End //////////////

static void _mavproxy_timer_update(void* parameter)
{
    rt_event_send(&_event_mavproxy, EVENT_MAVPROXY_UPDATE);
}

static void _usb_status_change(void* parameter)
{
    USB_Status usb_status = *(USB_Status*)parameter;

    if (usb_status.connected) {
        for (uint8_t i = 0; i < DEVICE_NUM; i++) {
            if (DEVICE_TYPE_IS(i, usb)) {
                _new_mav_dev_chan = i;
                break;
            }
        }
    } else {
        _new_mav_dev_chan = MAVPROXY_DEFAULT_CHAN;
    }
}

static uint8_t _send_immediate_msg(void)
{
    while (_imm_msg_queue.head != _imm_msg_queue.tail) {
        if (mavproxy_send_immediate_msg(&_imm_msg_queue.queue[_imm_msg_queue.tail], true) == FMT_EOK) {
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
    mavlink_msg_command_ack_encode(_mavlink_system.sysid, _mavlink_system.compid,
        msg, command_ack);

    mavproxy_send_immediate_msg(msg, true);
}

static fmt_err _switch_channel(uint8_t chan)
{
    rt_device_t old_device, new_device;

    if (chan >= DEVICE_NUM) {
        return FMT_EINVAL;
    }

    old_device = mavproxy_get_device();
    if (mavproxy_set_device(_mavproxy_device_list[chan].name) == FMT_EOK) {
        /* configure serial device if needed */
        if (DEVICE_TYPE_IS(chan, serial)) {
            serial_dev_t serial_dev;
            mavproxy_serial_dev_config* config = (mavproxy_serial_dev_config*)_mavproxy_device_list[chan].config;

            new_device = mavproxy_get_device();
            serial_dev = (serial_dev_t)new_device;

            if (serial_dev->config.baud_rate != config->baudrate) {
                struct serial_configure pconfig = serial_dev->config;
                pconfig.baud_rate = config->baudrate;
                if (rt_device_control(new_device, RT_DEVICE_CTRL_CONFIG, &pconfig) != RT_EOK) {
                    return FMT_ERROR;
                }
            }
        }
        /* now we can safely close the old device */
        if (old_device != NULL) {
            rt_device_close(old_device);
        }
    } else {
        return FMT_ERROR;
    }

    return FMT_EOK;
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
    msg.time_stamp = systime_now_ms() + _period_msg_queue.size * MAVPROXY_INTERVAL;

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

fmt_err mavproxy_send_immediate_msg(const mavlink_message_t* msg, bool sync)
{
    /* if sync flag set, send out msg immediately */
    if (sync) {
        uint16_t len;
        rt_size_t size;

        /* make sure only one thread can access tx buffer at mean time. */
        rt_sem_take(_mavproxy_tx_lock, RT_WAITING_FOREVER);

        len = mavlink_msg_to_send_buffer(_mav_tx_buff, msg);
        size = mavproxy_dev_write(_mav_tx_buff, len, RT_WAITING_FOREVER);

        rt_sem_release(_mavproxy_tx_lock);

        return size == len ? FMT_EOK : FMT_ERROR;
    }

    /* otherwise, push msg into queue (asynchronize mode) */
    OS_ENTER_CRITICAL;

    if ((_imm_msg_queue.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE == _imm_msg_queue.tail) {
        OS_EXIT_CRITICAL;
        return FMT_EFULL;
    }

    _imm_msg_queue.queue[_imm_msg_queue.head] = *msg;
    _imm_msg_queue.head = (_imm_msg_queue.head + 1) % MAX_IMMEDIATE_MSG_QUEUE_SIZE;
    OS_EXIT_CRITICAL;

    /* wakeup mavproxy to send out temporary msg immediately */
    rt_event_send(&_event_mavproxy, EVENT_MAVPROXY_UPDATE);

    return FMT_EOK;
}

fmt_err mavproxy_send_event(uint32_t event_set)
{
    return rt_event_send(&_event_mavproxy, event_set);
}

mavlink_system_t mavproxy_get_system(void)
{
    return _mavlink_system;
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
            /* switch mavproxy channel if needed */
            if (_mav_dev_chan != _new_mav_dev_chan) {
                if (_switch_channel(_new_mav_dev_chan) == FMT_EOK) {
                    _mav_dev_chan = _new_mav_dev_chan;
                } else {
                    TIMETAG_CHECK_EXECUTE(mavproxy, 500, console_printf("mavproxy switch channel fail!\n"););
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

/* config mavproxy via toml system configuration file */
fmt_err mavproxy_toml_init(toml_table_t* table)
{
    int i;
    const char* key;
    toml_array_t* arr;
    toml_table_t* tab;
    fmt_err err = FMT_EOK;

    /* traverse keys in table */
    for (i = 0; 0 != (key = toml_key_in(table, i)); i++) {
        if (MATCH(key, "devices")) {
            /* we get new device configuration, override original one */
            _init_device_list();

            if (toml_array_table_in(table, key, &arr) == 0) {
                err = _mavproxy_parse_devices(arr);
                if (err != FMT_EOK) {
                    console_printf("TOML Mavproxy: fail to parse devices\n");
                    return err;
                }
            } else {
                console_printf("TOML Mavproxy: fail to parse devices\n");
                return FMT_ERROR;
            }
        } else if (MATCH(key, "device")) {
            /* we get new device configuration, override original one */
            _init_device_list();

            if ((tab = toml_table_in(table, key)) != 0) {
                err = _mavproxy_parse_device(tab, 0);
                if (err == FMT_EOK) {
                    DEVICE_NUM = 1;
                }
            } else {
                console_printf("Error: wrong element type: %s\n", key);
                err = FMT_ERROR;
            }
        } else {
            console_printf("Error: unknown config key: %s\n", key);
            err = FMT_ERROR;
        }
    }

    return err;
}

fmt_err mavproxy_init(void)
{
    /* init message queue */
    _period_msg_queue.size = 0;
    _period_msg_queue.index = 0;
    _imm_msg_queue.head = 0;
    _imm_msg_queue.tail = 0;

    /* init mavproxy device */
    mavproxy_dev_init();

    /* init mavlink console */
    mavlink_console_init();

    /* create tx lock */
    _mavproxy_tx_lock = rt_sem_create("mav_tx_lock", 1, RT_IPC_FLAG_FIFO);

    /* create event */
    rt_event_init(&_event_mavproxy, "mavproxy", RT_IPC_FLAG_FIFO);

    /* register timer event to periodly wakeup itself */
    rt_timer_init(&_timer_mavproxy, "mav_update", _mavproxy_timer_update, RT_NULL, MAVPROXY_INTERVAL,
        RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    rt_timer_start(&_timer_mavproxy);

    return FMT_EOK;
}

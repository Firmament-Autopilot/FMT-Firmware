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

#include "module/utils/device_mq.h"

#define MQ_MAX_MSG 20

typedef struct {
    rt_device_t device;
    void (*notify)(void* msg);
    int registered;
    int fill;
} handler_list;

static rt_mq_t _mq = NULL;
static handler_list _handler_list[MQ_MAX_MSG] = { 0 };

static int _find_handler_id(rt_device_t device)
{
    int idx = 0;

    for (; idx < MQ_MAX_MSG; idx++) {
        if (_handler_list[idx].registered == 1 && _handler_list[idx].device == device) {
            return idx;
        }
    }

    return -1;
}

fmt_err device_mq_create(void)
{
    _mq = rt_mq_create("dev_mq", sizeof(device_status), MQ_MAX_MSG, RT_IPC_FLAG_FIFO);

    if (_mq == NULL) {
        return FMT_ERROR;
    }

    /* clear register list */
    for (int i = 0; i < MQ_MAX_MSG; i++) {
        _handler_list[i].registered = 0;
        _handler_list[i].fill = 0;
    }

    return FMT_EOK;
}

fmt_err device_mq_register(const char* dev_name, void (*notify)(void* msg))
{
    int idx = 0;
    rt_device_t device;

    if ((device = rt_device_find(dev_name)) == NULL) {
        return FMT_ERROR;
    }

    if((idx = _find_handler_id(device)) >= 0){
        /* already registered, just update it */
        _handler_list[idx].fill = 0;
        _handler_list[idx].notify = notify;
        return FMT_EOK;
    }

    /* find an empty slot */
    for (idx = 0; idx < MQ_MAX_MSG; idx++) {
        if (_handler_list[idx].registered == 0) {
            break;
        }
    }

    if (idx >= MQ_MAX_MSG) {
        // register list is full
        return FMT_EFULL;
    }

    _handler_list[idx].device = device;
    _handler_list[idx].notify = notify;
    _handler_list[idx].registered = 1;

    return FMT_EOK;
}

fmt_err device_mq_deregister(const char* dev_name)
{
    int idx = 0;
    rt_device_t device;

    if ((device = rt_device_find(dev_name)) == NULL) {
        return FMT_ERROR;
    }

    /* find handler */
    for (; idx < MQ_MAX_MSG; idx++) {
        if (_handler_list[idx].registered && _handler_list[idx].device == device) {
            _handler_list[idx].device = NULL;
            _handler_list[idx].notify = NULL;
            _handler_list[idx].registered = _handler_list[idx].fill = 0;
            return FMT_EOK;
        }
    }

    return FMT_EEMPTY;
}

fmt_err device_mq_notify(rt_device_t device, int status)
{
    int idx = 0;
    device_status dev_status;

    /* find handler */
    for (; idx < MQ_MAX_MSG; idx++) {
        if (_handler_list[idx].registered && _handler_list[idx].device == device) {
            break;
        }
    }

    if (idx >= MQ_MAX_MSG) {
        /* can not find device handler */
        return FMT_EEMPTY;
    }

    if (_handler_list[idx].fill) {
        /* if there is a msg in mq and not handled,we don't push new 
        msg to that device in case of mq become full easily */
        return FMT_EBUSY;
    }

    /* notify device status */
    dev_status.device = device;
    dev_status.status = status;
    return rt_mq_send(_mq, &dev_status, sizeof(dev_status));
}

fmt_err device_mq_handle_msg(void)
{
    device_status dev_status;

    while (rt_mq_recv(_mq, &dev_status, sizeof(dev_status), 0) == RT_EOK) {
        int idx = _find_handler_id(dev_status.device);

        if (idx == -1) {
            continue;
        }

        if (_handler_list[idx].registered && _handler_list[idx].notify) {
            _handler_list[idx].notify(&dev_status);
            _handler_list[idx].fill = 0;
        }
    }

    return FMT_EOK;
}

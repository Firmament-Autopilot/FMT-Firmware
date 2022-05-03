/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "module/utils/devmq.h"
#include "module/workqueue/workqueue_manager.h"

#define DEVMQ_MAX_HANDLER  10
#define DEVMQ_MAX_MSG_SIZE 128

struct devmq_handler {
    rt_mq_t mq;
    uint32_t msg_size;
    uint32_t max_msgs;
    rt_device_t device;
    void (*handler)(rt_device_t dev, void* msg);
};
typedef struct devmq_handler* devmq_handler_t;

typedef struct devmq_node* devmq_node_t;
struct devmq_node {
    devmq_handler_t handle;
    devmq_node_t next;
};

static struct devmq_node devmq_list = { .handle = NULL, .next = NULL };

static devmq_node_t find_last_node(void)
{
    devmq_node_t nod = &devmq_list;

    while (nod->next != NULL) {
        nod = nod->next;
    }
    return nod;
}

static devmq_node_t find_device_node(rt_device_t device)
{
    for (devmq_node_t nod = &devmq_list; nod != NULL && nod->handle != NULL; nod = nod->next) {
        if (nod->handle->device == device) {
            return nod;
        }
    }
    return NULL;
}

fmt_err_t devmq_create(rt_device_t device, uint32_t msg_size, uint32_t max_msgs)
{
    RT_ASSERT(device != NULL);
    RT_ASSERT(msg_size > 0);
    RT_ASSERT(max_msgs > 0);

    if (msg_size > DEVMQ_MAX_MSG_SIZE) {
        console_printf("devmq create fail, exceed max msg size: %d %d\n", msg_size, DEVMQ_MAX_MSG_SIZE);
        return FMT_EINVAL;
    }

    if (find_device_node(device) != NULL) {
        console_printf("devmq is already created for %s\n", device->parent.name);
        return FMT_EBUSY;
    }

    devmq_node_t new_nod = find_last_node();
    if (new_nod->handle != NULL) {
        new_nod->next = (devmq_node_t)rt_malloc(sizeof(struct devmq_node));
        if (new_nod->next == NULL) {
            return FMT_ENOMEM;
        }
        new_nod = new_nod->next;
    }

    new_nod->handle = (devmq_handler_t)rt_malloc(sizeof(struct devmq_handler));
    if (new_nod->handle == NULL) {
        console_printf("devmq malloc fail for %s\n", device->parent.name);
        return FMT_ENOMEM;
    }
    new_nod->next = NULL;

    memset(new_nod->handle, 0, sizeof(struct devmq_handler));

    new_nod->handle->device = device;
    new_nod->handle->msg_size = msg_size;
    new_nod->handle->max_msgs = max_msgs;
    new_nod->handle->mq = rt_mq_create(device->parent.name, msg_size, max_msgs, RT_IPC_FLAG_FIFO);
    if (new_nod->handle->mq == RT_NULL) {
        console_printf("create devmq fail for %s\n", device->parent.name);
        return FMT_ERROR;
    }

    return FMT_EOK;
}

fmt_err_t devmq_register(rt_device_t device, void (*handler)(rt_device_t dev, void* msg))
{
    RT_ASSERT(device != NULL);
    RT_ASSERT(handler != NULL);

    devmq_node_t nod = find_device_node(device);
    if (nod == NULL) {
        console_printf("%s devmq is not created\n", device->parent.name);
        return FMT_ENOSYS;
    }

    nod->handle->handler = handler;
    return FMT_EOK;
}

fmt_err_t devmq_deregister(rt_device_t device)
{
    RT_ASSERT(device != NULL);

    devmq_node_t nod = find_device_node(device);
    if (nod == NULL) {
        console_printf("%s devmq is not created\n", device->parent.name);
        return FMT_ENOSYS;
    }

    nod->handle->handler = NULL;
    return FMT_EOK;
}

fmt_err_t devmq_notify(rt_device_t device, void* msg)
{
    RT_ASSERT(device != NULL);
    RT_ASSERT(msg != NULL);

    devmq_node_t nod = find_device_node(device);
    if (nod == NULL) {
        console_printf("%s devmq is not created\n", device->parent.name);
        return FMT_ENOSYS;
    }

    rt_err_t rt_err = rt_mq_send(nod->handle->mq, msg, nod->handle->msg_size);
    return (rt_err == RT_EOK) ? FMT_EOK : FMT_ERROR;
}

void devmq_distribute_msg(void* parameter)
{
    static uint8_t msg_buffer[DEVMQ_MAX_MSG_SIZE];

    /* traverse all device nodes */
    for (devmq_node_t nod = &devmq_list; nod != NULL; nod = nod->next) {
        if (nod->handle) {
            /* check if handler is registered */
            if (nod->handle->handler == NULL) {
                continue;
            }
            /* now distribute messages to handler */
            while (rt_mq_recv(nod->handle->mq, msg_buffer, nod->handle->msg_size, RT_WAITING_NO) == RT_EOK) {
                nod->handle->handler(nod->handle->device, msg_buffer);
            }
        }
    }
}

fmt_err_t devmq_start_work(void)
{
    static struct WorkItem item = {
        .name = "devmq",
        .period = 50,
        .schedule_time = 0,
        .run = devmq_distribute_msg
    };
    WorkQueue_t wq = workqueue_find("wq:lp_work");
    if (wq == NULL) {
        return FMT_ENOSYS;
    }

    if (workqueue_schedule_work(wq, &item) != FMT_EOK) {
        return FMT_ERROR;
    }
    return FMT_EOK;
}

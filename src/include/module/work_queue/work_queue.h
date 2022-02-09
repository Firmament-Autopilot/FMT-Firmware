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
#ifndef WORK_QUEUE_H__
#define WORK_QUEUE_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SCHEDULE_DELAY(_delay_ms) (systime_now_ms() + _delay_ms)

struct WorkItem {
    const char* name;
    uint32_t schedule_time; /* work scheduled time */
    uint16_t period;        /* period of work, 0 means only execute once */
    void* parameter;
    void (*run)(void* parameter);
};
typedef struct WorkItem* WorkItem_t;

struct WorkQueue {
    rt_thread_t thread;
    uint8_t qsize;
    uint8_t size;
    WorkItem_t* queue;
    rt_sem_t lock;
};
typedef struct WorkQueue* WorkQueue_t;

WorkQueue_t workqueue_create(const char* name, uint8_t size, uint16_t stack_size, uint8_t priority);
fmt_err_t workqueue_delete(WorkQueue_t work_queue);
fmt_err_t workqueue_schedule_work(WorkQueue_t work_queue, WorkItem_t item);
fmt_err_t workqueue_cancel_work(WorkQueue_t work_queue, WorkItem_t item);

#ifdef __cplusplus
}
#endif

#endif
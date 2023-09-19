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

#include "module/workqueue/work_queue.h"

#define work_lock(_wq)   rt_sem_take(_wq->lock, RT_WAITING_FOREVER)
#define work_unlock(_wq) rt_sem_release(_wq->lock)

static void __swap_item(WorkItem_t* a, WorkItem_t* b)
{
    WorkItem_t temp = *b;
    *b              = *a;
    *a              = temp;
}

static void __heapify(WorkItem_t* queue, uint8_t size, int idx)
{
    if (size == 1) {
        /* single element in the heap */
        return;
    }

    /* Find the smallest among root, left child and right child */
    int smallest = idx;
    int l        = 2 * idx + 1;
    int r        = 2 * idx + 2;
    if (l < size && queue[l]->schedule_time < queue[smallest]->schedule_time)
        smallest = l;
    if (r < size && queue[r]->schedule_time < queue[smallest]->schedule_time)
        smallest = r;

    /* Swap and continue heapifying if root is not smallest */
    if (smallest != idx) {
        __swap_item(&queue[idx], &queue[smallest]);
        __heapify(queue, size, smallest);
    }
}

rt_inline int find_workitem_idx(WorkQueue_t work_queue, WorkItem_t item)
{
    int idx = -1;

    for (int i = 0; i < work_queue->size; i++) {
        if (item == work_queue->queue[i]) {
            idx = i;
            break;
        }
    }

    return idx;
}

/**
 * @brief Pop the latest work from workqueue
 *
 * @param work_queue The target workqueue
 * @return WorkItem_t The latest work item
 */
static WorkItem_t workqueue_pop(WorkQueue_t work_queue)
{
    RT_ASSERT(work_queue != NULL);

    work_lock(work_queue);

    if (work_queue->size == 0) {
        work_unlock(work_queue);
        return NULL;
    }
    WorkItem_t dq_item = work_queue->queue[0];

    work_unlock(work_queue);

    if (workqueue_cancel_work(work_queue, dq_item) != FMT_EOK) {
        return NULL;
    }

    return dq_item;
}

/**
 * @brief Workqueue execution thread
 *
 * @param parameter the pointer of workqueue
 */
static void workqueue_executor(void* parameter)
{
    RT_ASSERT(parameter != NULL);

    WorkQueue_t work_queue = (WorkQueue_t)parameter;
    WorkItem_t  work_item;
    uint32_t    time_now, schedule_time;

    while (1) {
        if (work_queue->size == 0) {
            /* no work scheduled, suspend itself */
            rt_thread_suspend(rt_thread_self());
            rt_schedule();
        }

        time_now      = systime_now_ms();
        schedule_time = work_queue->queue[0]->schedule_time;
        if (schedule_time > time_now) {
            sys_msleep(schedule_time - time_now);
            continue;
        }

        work_item = workqueue_pop(work_queue);
        if (work_item != NULL) {
            /* do work */
            work_item->run(work_item->parameter);
            /* if period is set and no same workitem in queue, push work item back to queue */
            if (work_item->period > 0 && find_workitem_idx(work_queue, work_item) == -1) {
                work_item->schedule_time = SCHEDULE_DELAY(work_item->period);
                workqueue_schedule_work(work_queue, work_item);
            }
        }
    }
}

/**
 * @brief Schedule a work for workqueue
 * @note  schedule_time of item indicates when the work should be executed.
 *        0 means it should be executed immediately.
 *
 * @param work_queue The target workqueue
 * @param item The work item to be scheduled
 * @return fmt_err_t FMT_EOK on OK
 */
fmt_err_t workqueue_schedule_work(WorkQueue_t work_queue, WorkItem_t item)
{
    RT_ASSERT(work_queue != NULL);
    RT_ASSERT(item != NULL);
    RT_ASSERT(item->run != NULL);

    /* first cancel old work if any */
    workqueue_cancel_work(work_queue, item);

    work_lock(work_queue);

    if (work_queue->size >= work_queue->qsize - 1) {
        work_unlock(work_queue);
        return FMT_EFULL;
    }

    if (work_queue->size == 0) {
        work_queue->queue[0] = item;
        work_queue->size += 1;
    } else {
        work_queue->queue[work_queue->size] = item;
        work_queue->size += 1;
        for (int i = work_queue->size / 2 - 1; i >= 0; i--) {
            __heapify(work_queue->queue, work_queue->size, i);
        }
    }

    work_unlock(work_queue);

    /* wakeup workqueue thread */
    rt_thread_resume(work_queue->thread);
    /* perform a schedule */
    rt_schedule();

    return FMT_EOK;
}

/**
 * @brief Cancel a work from workqueue
 *
 * @param work_queue The target workqueue
 * @param item The work item to be canceled
 * @return fmt_err_t FMT_EOK on OK
 */
fmt_err_t workqueue_cancel_work(WorkQueue_t work_queue, WorkItem_t item)
{
    RT_ASSERT(work_queue != NULL);
    RT_ASSERT(item != NULL);

    int idx;

    work_lock(work_queue);

    idx = find_workitem_idx(work_queue, item);

    if (idx == -1) {
        work_unlock(work_queue);
        return FMT_EEMPTY;
    }

    __swap_item(&work_queue->queue[idx], &work_queue->queue[work_queue->size - 1]);

    work_queue->size -= 1;
    for (int i = work_queue->size / 2 - 1; i >= 0; i--) {
        __heapify(work_queue->queue, work_queue->size, i);
    }

    work_unlock(work_queue);

    return FMT_EOK;
}

/**
 * @brief Delete a workqueue
 *
 * @param work_queue Workqueue to be deleted
 * @return fmt_err_t FMT_EOK on OK
 */
fmt_err_t workqueue_delete(WorkQueue_t work_queue)
{
    RT_ASSERT(work_queue != NULL);

    if (rt_thread_delete(work_queue->thread) != RT_EOK) {
        return FMT_ERROR;
    }
    if (rt_sem_delete(work_queue->lock) != RT_EOK) {
        return FMT_ERROR;
    }
    rt_free(work_queue->queue);
    rt_free(work_queue);

    return FMT_EOK;
}

/**
 * @brief Create a workqueue
 *
 * @param name Name of workqueue
 * @param size Size of workqueue
 * @param stack_size Stack size of workqueue thread
 * @param priority Priority of workqueue thread
 * @return WorkQueue_t Workqueue pointer
 */
WorkQueue_t workqueue_create(const char* name, uint8_t size, uint16_t stack_size, uint8_t priority)
{
    RT_ASSERT(size > 0);
    RT_ASSERT(stack_size > 0);

    WorkQueue_t work_queue = (WorkQueue_t)rt_malloc(sizeof(struct WorkQueue));
    if (work_queue == NULL) {
        return NULL;
    }

    work_queue->thread = rt_thread_create(name,
                                          workqueue_executor,
                                          work_queue,
                                          stack_size,
                                          priority,
                                          10);

    if (work_queue->thread == NULL) {
        goto error_exit;
    }

    work_queue->queue = (WorkItem_t*)rt_malloc(size * sizeof(WorkItem_t));
    if (work_queue->queue == NULL) {
        goto error_exit;
    }
    work_queue->qsize = size;
    work_queue->size  = 0;

    work_queue->lock = rt_sem_create(name, 1, RT_IPC_FLAG_FIFO);
    if (work_queue->lock == NULL) {
        goto error_exit;
    }

    if (rt_thread_startup(work_queue->thread) != RT_EOK) {
        rt_free(work_queue->thread->stack_addr);
        goto error_exit;
    }

    return work_queue;

error_exit:
    rt_free(work_queue);
    return NULL;
}

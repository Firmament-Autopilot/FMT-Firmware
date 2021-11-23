/******************************************************************************
 * Copyright 2020-2021 The Firmament-Autopilot Authors. All Rights Reserved.
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
#include <string.h>

#include "module/task_manager/task_manager.h"

#define MAX_INIT_TIME (5000)

static fmt_task_desc_t task_table;
static uint32_t task_num;
static uint8_t* task_status;

/**
 * @brief Get the task num
 *
 * @return uint32_t Number of task
 */
uint32_t get_task_num(void)
{
    return task_num;
}

/**
 * @brief Get the task table object
 *
 * @return fmt_task_desc_t Task table object
 */
fmt_task_desc_t get_task_table(void)
{
    return task_table;
}

/**
 * @brief Get the task status object
 *
 * @param name Task name
 * @return uint8_t Task status
 */
uint8_t get_task_status(const char* name)
{
    for (uint32_t i = 0; i < task_num; i++) {
        if (strcmp(name, task_table[i].name) == 0) {
            return task_status[i];
        }
    }

    return 0;
}

/**
 * @brief Initialize tasks
 *
 */
void task_init(void)
{
    extern const int __fmt_task_start;
    extern const int __fmt_task_end;

    uint32_t init_done = 0;
    uint32_t time_start_init = systime_now_ms();

    task_table = (fmt_task_desc_t)&__fmt_task_start;
    task_num = (fmt_task_desc_t)&__fmt_task_end - task_table;

    if (task_num == 0) {
        /* No task defined */
        return;
    }

    task_status = (uint8_t*)rt_malloc(task_num);
    RT_ASSERT(task_status != NULL);
    memset(task_status, TASK_IDLE, task_num);

    for (uint32_t i = 0; i < task_num; i++) {
        RT_ASSERT(task_table[i].name != NULL);
        RT_ASSERT(task_table[i].init != NULL);
        RT_ASSERT(task_table[i].entry != NULL);
    }

    /* wait all task has been initialized or init timeout */
    while (init_done < task_num && (systime_now_ms() - time_start_init) < MAX_INIT_TIME) {
        for (uint32_t i = 0; i < task_num; i++) {
            uint8_t depend_met = 1;

            /* check task dependency */
            for (uint32_t n = 0; task_table[i].dependency != NULL && task_table[i].dependency[n] != NULL; n++) {
                for (uint32_t k = 0; k < task_num; k++) {
                    /* find depended task */
                    if (strcmp(task_table[i].dependency[n], task_table[k].name) == 0) {
                        if (task_status[k] == TASK_IDLE) {
                            /* wait the depended task to be initialized */
                            depend_met = 0;
                            break;
                        } else if (task_status[k] == TASK_FAIL) {
                            /* if the depended task failed, then the related task fails as well */
                            depend_met = 0;
                            task_status[i] = TASK_FAIL;
                            /* increase init task count */
                            init_done++;
                        }
                    }
                }
            }

            /* if task is not initialized yet, call the init function */
            if (depend_met && task_status[i] == TASK_IDLE) {
                if (task_table[i].init() == FMT_EOK) {
                    task_status[i] = TASK_OK;
                } else {
                    task_status[i] = TASK_FAIL;
                }
                /* increase init task count */
                init_done++;
            }
        }
    }
}

/**
 * @brief Start tasks
 *
 */
void task_start(void)
{
    for (uint32_t i = 0; i < task_num; i++) {
        if (task_status[i] != TASK_OK)
            continue;

        rt_thread_t tid = rt_thread_create(task_table[i].name,
            task_table[i].entry, task_table[i].param,
            task_table[i].stack_size, task_table[i].priority, 1);
        RT_ASSERT(tid != NULL);

        RT_CHECK(rt_thread_startup(tid));
    }
}

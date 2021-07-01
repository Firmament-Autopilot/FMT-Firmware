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

#include "module/task_manager/task_manager.h"

static fmt_task_desc_t task_table;
static uint32_t task_num;

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
 * @brief Initialize tasks
 * 
 */
void task_init(void)
{
    extern const int __fmt_task_start;
    extern const int __fmt_task_end;
    task_table = (fmt_task_desc_t)&__fmt_task_start;
    task_num = (fmt_task_desc_t)&__fmt_task_end - task_table;

    for (uint32_t i = 0; i < task_num; i++) {
        RT_ASSERT(task_table[i].name != NULL);
        RT_ASSERT(task_table[i].init != NULL);
        RT_ASSERT(task_table[i].entry != NULL);

        if (task_table[i].init() == FMT_EOK) {
            task_table[i].status = TASK_OK;
        } else {
            task_table[i].status = TASK_FAIL;
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
        if (task_table[i].status == TASK_FAIL)
            continue;

        rt_thread_t tid = rt_thread_create(task_table[i].name,
            task_table[i].entry, task_table[i].param,
            task_table[i].stack_size, task_table[i].priority, 1);
        RT_ASSERT(tid != NULL);

        RT_CHECK(rt_thread_startup(tid));
    }
}
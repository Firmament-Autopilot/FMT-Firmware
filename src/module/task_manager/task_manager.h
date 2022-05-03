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
#ifndef TASK_MANAGER_H__
#define TASK_MANAGER_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef fmt_err_t (*task_init_t)(void);
typedef void (*task_entry_t)(void* param);

enum {
    TASK_IDLE = 0,
    TASK_OK,
    TASK_FAIL
};

struct fmt_task_desc {
    const char* name;
    task_init_t init;
    task_entry_t entry;
    uint8_t priority;
    uint32_t stack_size;
    void* param;
    char** dependency;
};
typedef struct fmt_task_desc* fmt_task_desc_t;

#define TASK_EXPORT RT_USED static const struct fmt_task_desc SECTION("TaskTab")

void task_init(void);
void task_start(void);
uint8_t get_task_status(const char* name);
uint32_t get_task_num(void);
fmt_task_desc_t get_task_table(void);

#ifdef __cplusplus
}
#endif

#endif

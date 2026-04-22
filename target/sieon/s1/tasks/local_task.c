/******************************************************************************
 * Copyright 2021-2023 The Firmament Authors. All Rights Reserved.
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

#include "module/task_manager/task_manager.h"

fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

void task_local_entry(void* parameter)
{
    rt_device_t dev = rt_device_find("eth_dev0");
    rt_device_open(dev, RT_DEVICE_OFLAG_RDWR);

    uint8_t ch[128] = { 0 };
    /* main loop */
    while (1) {
        printf("waiting...\n");
        if (rt_device_read(dev, 0, ch, 128) > 0) {
            printf("data:%s\r\n", ch);
        }
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "local",
    .init = task_local_init,
    .entry = task_local_entry,
    .priority = 25,
    .auto_start = false,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};

/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#include "stm32h7xx_ll_gpio.h"

rt_device_t fdcan_dev;

fmt_err_t task_local_init(void)
{

    return FMT_EOK;
}

// char** str = (char*[]) { "Hello", "C++", "World", NULL };

void task_local_entry(void* parameter)
{
    printf("Hello FMT! This is a local demo task.\n");

    // for (int i = 0; str[i] != NULL; i++) {
    //     printf("%s\n", str[i]);
    // }

    fdcan_dev = rt_device_find("fdcan1");
    if (fdcan_dev == RT_NULL)
        return FMT_ERROR;

    if ((fdcan_dev->write) == NULL) {
        printf("fdcan_dev->write == NULL\n");
        return FMT_ERROR;
    }
    rt_device_open(fdcan_dev, RT_DEVICE_OFLAG_RDWR);

    while (1) {
        rt_size_t ret = rt_device_write(fdcan_dev, 0, "sss", 3);

        printf("ret=%d\r\n", ret);

        sys_msleep(1000);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "local",
    .init = task_local_init,
    .entry = task_local_entry,
    .priority = 25,
    .auto_start = true,
    .stack_size = 1024,
    .param = NULL,
    .dependency = NULL
};

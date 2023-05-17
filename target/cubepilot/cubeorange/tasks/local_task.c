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

#include "module/dronecan/dronecan.h"
#include "module/task_manager/task_manager.h"

#include "drivers/drv_fdcan.h"
#include "stm32h7xx_ll_gpio.h"

rt_device_t fdcan_dev;

fmt_err_t task_local_init(void)
{

    return FMT_EOK;
}

// uint8_t buffer[12];
// rt_uint32_t boxno;
// rt_size_t size;
void task_local_entry(void* parameter)
{
    // printf("Hello FMT! This is a local demo task.\n");

    // fdcan_dev = rt_device_find("fdcan1");
    // if (fdcan_dev == RT_NULL)
    //     printf("fdcan_dev == NULL\n");

    // if ((fdcan_dev->write) == NULL) {
    //     printf("fdcan_dev->write == NULL\n");
    // }

    // rt_device_open(fdcan_dev, RT_DEVICE_OFLAG_RDWR);

    // while (1) {
    //     rt_size_t size = rt_device_read(fdcan_dev, 0, buffer, 8);

    //     printf("size=%d\n", size);

    //     sys_msleep(500);
    // }
}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "local",
//     .init = task_local_init,
//     .entry = task_local_entry,
//     .priority = 25,
//     .auto_start = true,
//     .stack_size = 1024,
//     .param = NULL,
//     .dependency = NULL
// };

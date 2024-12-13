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

#include "hal/can/can.h"
#include "module/task_manager/task_manager.h"

fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

char** str = (char*[]) { "Hello", "C++", "World", NULL };

void task_local_entry(void* parameter)
{
    printf("Hello FMT! This is a local demo task.\n");

    rt_device_t can_dev = rt_device_find("can1");
    rt_device_open(can_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);

    can_msg msg;

    while (1) {
        while (rt_device_read(can_dev, RT_WAITING_FOREVER, &msg, 1)) {
            printf("can recv msg, id:0x%x, data:%x,%x,%x,%x,%x,%x,%x,%x\n", msg.std_id, msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7]);

            msg.std_id = 0x200;
            msg.id_type = CAN_ID_STANDARD;
            msg.frame_type = CAN_FRAME_DATA;
            msg.data_len = 8;
            msg.data[0] = 0x88;
            msg.data[1] = 0x77;
            msg.data[2] = 0x66;
            msg.data[3] = 0x55;
            msg.data[4] = 0x44;
            msg.data[5] = 0xFF;
            msg.data[6] = 0xEE;
            msg.data[7] = 0xDD;
            rt_device_write(can_dev, 5000, &msg, 1);
        }

        // sys_msleep(1000);
    }
}

TASK_EXPORT __fmt_task_desc = {
    .name = "local",
    .init = task_local_init,
    .entry = task_local_entry,
    .priority = 25,
    .auto_start = true,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};

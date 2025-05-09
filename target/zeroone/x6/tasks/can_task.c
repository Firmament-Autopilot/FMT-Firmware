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

#include "hal/can/can.h"
#include "module/task_manager/task_manager.h"

static rt_device_t can_dev;

fmt_err_t task_can_init(void)
{
    can_dev = rt_device_find("can1");
    return FMT_EOK;
}

void task_can_entry(void* parameter)
{
    can_msg msg;
    struct can_filter filter = { .filter_type = CAN_FILTER_TYPE_MASK, .filter_id1 = 0x200, .filter_id2 = 0xFFF };

    rt_device_open(can_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
    rt_device_control(can_dev, CAN_SET_RX_FILTER, &filter);

    /* main loop */
    while (1) {
        while (rt_device_read(can_dev, RT_WAITING_NO, &msg, 1) > 0) {
            printf("can recv msg, id:0x%x, data:%x,%x,%x,%x,%x,%x,%x,%x\n", msg.std_id, msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7]);
        }

        msg.std_id = 0x100;
        msg.id_type = CAN_ID_STANDARD;
        msg.frame_type = CAN_FRAME_DATA;
        msg.data_len = 8;
        msg.data[0] = 0x11;
        msg.data[1] = 0x22;
        msg.data[2] = 0x33;
        msg.data[3] = 0x44;
        msg.data[4] = 0x55;
        msg.data[5] = 0x66;
        msg.data[6] = 0x77;
        msg.data[7] = 0x88;
        rt_device_write(can_dev, RT_WAITING_FOREVER, &msg, 1);

        sys_msleep(500);
    }
}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "can",
//     .init = task_can_init,
//     .entry = task_can_entry,
//     .priority = 25,
//     .auto_start = true,
//     .stack_size = 4096,
//     .param = NULL,
//     .dependency = NULL
// };

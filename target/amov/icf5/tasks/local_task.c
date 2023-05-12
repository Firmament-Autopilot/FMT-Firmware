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

// #include "cdc_acm_core.h"

// extern usb_core_driver cdc_acm;

fmt_err_t task_local_init(void)
{
    return FMT_EOK;
}

void task_local_entry(void* parameter)
{
    printf("Hello FMT! This is a local demo task.\n");

    // rt_device_t dev = rt_device_find("usbd0");
    // char c;
    // uint8_t buff[10];
    // rt_size_t rb;

    // rt_device_open(dev, RT_DEVICE_OFLAG_RDWR);

    // rt_device_t dev = rt_device_find("serial1");

    // rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX);

    /* main loop */
    while (1) {
        // if (USBD_CONFIGURED == cdc_acm.dev.cur_status) {
        //     if (0U == cdc_acm_check_ready(&cdc_acm)) {
        //         cdc_acm_data_receive(&cdc_acm);
        //     } else {
        //         cdc_acm_data_send(&cdc_acm);
        //     }
        // }

        // rb = rt_device_read(dev, 0, buff, 10);
        // if (rb) {
        //     rt_device_write(dev, 0, buff, rb);
        // }

        sys_msleep(1);
    }
}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "local",
//     .init = task_local_init,
//     .entry = task_local_entry,
//     .priority = 25,
//     .auto_start = false,
//     .stack_size = 1024,
//     .param = NULL,
//     .dependency = NULL
// };

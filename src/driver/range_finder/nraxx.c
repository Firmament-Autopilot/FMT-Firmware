/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "FMS.h"

#include "nraxx.h"
#include "hal/can/can.h"
#include "module/sensor/sensor_hub.h"

#define NRAXX_TARGET_STATUS_ID 0x70B
#define NRAXX_TARGET_INFO_ID   0x70C

MCN_DECLARE(terrain_info);

static rt_device_t can_dev;
static rt_thread_t thread;

static void thread_entry(void* args)
{
    Terrain_Info_Bus terrain_info;
    can_msg msg;

    while (1) {
        while (rt_device_read(can_dev, 0, &msg, 1) > 0) {
            if (msg.std_id == NRAXX_TARGET_INFO_ID) {
                uint16_t range = (msg.data[2] << 8) | msg.data[3];
                terrain_info.range_m = (float)range * 0.01f;
                terrain_info.timestamp = systime_now_ms();

                if (terrain_info.range_m > 0.0f) {
                    mcn_publish(MCN_HUB(terrain_info), &terrain_info);
                }
            }
        }
    }
}

rt_err_t drv_nraxx_init(const char* can_dev_name)
{
    can_dev = rt_device_find(can_dev_name);
    if (can_dev == NULL) {
        return RT_EEMPTY;
    }

    /* configure can baudrate before device open */
    RT_TRY(rt_device_control(can_dev, CAN_SET_BAUDRATE, (void*)CAN_BAUD_RATE_500K));

    /* open device */
    RT_TRY(rt_device_open(can_dev, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX));

    thread = rt_thread_create("nraxx", thread_entry, RT_NULL, 4096, 25, 1);
    RT_ASSERT(thread != NULL);

    RT_TRY(rt_thread_startup(thread));

    return RT_EOK;
}

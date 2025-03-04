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

#include "module/sensor/sensor_hub.h"
#include "module/workqueue/workqueue_manager.h"
#include "drv_i2c.h"
#include "hal/i2c/i2c.h"

#define EVENT_TFluna_UPDATE (1 << 0)

MCN_DECLARE(TFluna_rangefinder);

static rt_device_t i2c_dev;
static rt_thread_t thread;
static struct rt_event event;
static struct rt_timer timer;
static rf_data_t tfluna_data = {0};

static int TFluna_ID;

// mlog_elem_t TFluna_rangefinder_Elems[] = {
//     MLOG_ELEMENT(timestamp, MLOG_UINT32),
//     MLOG_ELEMENT(distance, MLOG_FLOAT),
// };
// MLOG_BUS_DEFINE(TFluna, TFluna_rangefinder_Elems);

// typedef struct {
//     uint32_t timestamp_ms;
//     float distance_m;
//     // float Amp;
//     // float temperature_deg;
// } TFluna_data_t;


static void timer_update(void* parameter)
{
    rt_event_send(&event, EVENT_TFluna_UPDATE);
}



static rt_err_t TFluna_init(void)
{

    
    if (i2c_write_reg(i2c_dev, 0x23, 0x01) != RT_EOK) {
        rt_kprintf("Failed to set order triger mode");

        return RT_ERROR;
    }

    return RT_EOK;
}

rt_size_t TFluna_read(void* data, rt_size_t size)
{
    uint8_t signature[6] = {0};     // 签名数组长度定义为5
    uint16_t dis_raw;
    uint16_t amp_raw;
    uint16_t temp_raw;
    float* report = (float*)data;

    if (data == RT_NULL) {
        return 0;
    }

    if (i2c_read_regs(i2c_dev, 0x00, signature, size) != RT_EOK)
    {
        rt_kprintf("Failed to read signature from register 0x3C!\n");
        return 1;  // 读取寄存器失败，处理错误
    }

    dis_raw = (signature[1] << 8) | signature[0];
    amp_raw = (signature[3] << 8) | signature[2];
    temp_raw = (signature[5] << 8) | signature[4];

    if (amp_raw < 100 || amp_raw > 65535) {
        // rt_kprintf("unreliable data \n");
        return RT_ERROR;
    }

    report[0] = (float)dis_raw * 0.01f;
    report[1] = amp_raw;
    report[2] = ((float)temp_raw / 8) - 256;


    return RT_EOK;
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_TFluna_UPDATE;
    float report[3];
    
    while (1) {
        if (i2c_write_reg(i2c_dev, 0x24, 0x01) != RT_EOK)
        {
            rt_kprintf("Failed to write to register 0x25!\n");
            break;
        }

        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK && (recv_set & EVENT_TFluna_UPDATE)) {
            if (TFluna_read(report, 6) == RT_EOK) {
                tfluna_data.distance_m = report[0];
                // tfluna_data.Amp = report[1];
                // tfluna_data.temperature_deg = report[2];
                tfluna_data.timestamp_ms = systime_now_ms();

                mcn_publish(MCN_HUB(TFluna_rangefinder), &tfluna_data);
                mlog_push_msg((uint8_t*)&tfluna_data, TFluna_ID, sizeof(tfluna_data));
            }
        }
    }
}

rt_err_t tfluna_drv_init(const char* i2c_device_name) {

    rt_kprintf("TFluna driver init\n");

    /* 查找I2C设备 */
    i2c_dev = rt_device_find(i2c_device_name);  
    RT_ASSERT(i2c_dev != NULL);  // 确保设备找到

    if (rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK)
    {
        rt_kprintf("Failed to open I2C device!\n");
        return RT_ERROR;  // 如果打开失败，打印错误信息并返回
    }
    
    RT_TRY(TFluna_init());

    TFluna_ID = mlog_get_bus_id("TFluna");

    RT_CHECK(rt_event_init(&event, "TFluna", RT_IPC_FLAG_FIFO));

    thread = rt_thread_create("TFluna", thread_entry, RT_NULL, 2 * 1024, 7, 1);
    RT_ASSERT(thread != NULL);
    RT_CHECK(rt_thread_startup(thread));

     /* register timer event */
    rt_timer_init(&timer, "TFluna", timer_update, RT_NULL, TICKS_FROM_MS(10), RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer) != RT_EOK) {
        return RT_ERROR;
    }

    return RT_EOK;
}
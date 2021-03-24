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

#include <firmament.h>

#include "hal/pin.h"
#include "hal/usbd_cdc.h"
#include "module/utils/devmq.h"

#define FMU_LED_PIN 17
static rt_device_t pin_device;


static void _led_on(void)
{
    struct device_pin_status pin_sta = { FMU_LED_PIN, 0 };

    if (pin_device != RT_NULL) {
        pin_device->write(pin_device, 0, (void*)&pin_sta, sizeof(&pin_sta));
    }
}

static void _led_off(void)
{
    struct device_pin_status pin_sta = { FMU_LED_PIN, 1 };

    if (pin_device != RT_NULL) {
        pin_device->write(pin_device, 0, (void*)&pin_sta, sizeof(&pin_sta));
    }
}

fmt_err task_simple_init(void)
{
    return FMT_EOK;
}

void task_simple_entry(void* parameter)
{
    struct device_pin_mode mode = { FMU_LED_PIN, PIN_MODE_OUTPUT, PIN_OUT_TYPE_OD };

    pin_device = rt_device_find("pin");
    pin_device->control(pin_device, 0, &mode);

    // rt_device_t serial_dev = rt_device_find("serial1");
    // if (rt_device_open(serial_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX) != RT_EOK) {
    //     return;
    // }

    // uint8_t usbd_open_res;
    // rt_device_t usbd_cdc_dev = rt_device_find("usbd0");
    // usbd_open_res = rt_device_open(usbd_cdc_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX);

    // uint8_t buffer[50] = "Hello";
    while (1) {
        _led_on();
        rt_thread_delay(100);
        _led_off();
        rt_thread_delay(100);

        // uint32_t cnt = rt_device_read(serial_dev, 0, buffer, 50);
        // if (cnt) {
        //     rt_device_write(serial_dev, 0, buffer, cnt);
        // }

        // if (usbd_open_res == RT_EOK) {
        //     char usbd_data_buf[100];
        //     uint32_t rb = rt_device_read(usbd_cdc_dev, 0, usbd_data_buf, sizeof(usbd_data_buf));
        //     if (rb) {
        //         rt_device_write(usbd_cdc_dev, 0, usbd_data_buf, rb);
        //     }
        // }

        devmq_distribute_msg();
    }
}
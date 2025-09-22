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
#include <firmament.h>

#include "driver/gps/gps_ubx.h"
#include "hal/gps/gps.h"
#include "hal/serial/serial.h"
#include "module/sensor/sensor_hub.h"
#include "protocol/ublox/ublox.h"

rt_err_t gps_nmea_init(const char* serial_device_name, const char* gps_device_name)
{
    // char* str_buffer;

    // gps_device.ops = &gps_ops;

    // str_buffer = (char*)rt_malloc(21);
    // RT_ASSERT(str_buffer != NULL);
    // memset(str_buffer, 0, 21);
    // strncpy(str_buffer, gps_device_name, 20);

    // serial_device = rt_device_find(serial_device_name);
    // RT_ASSERT(serial_device != NULL);

    // /* set gps rx indicator */
    // RT_CHECK(rt_device_set_rx_indicate(serial_device, gps_serial_rx_ind));
    // /* open serial device */
    // RT_CHECK(rt_device_open(serial_device, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX));
    // /* init ublox decoder */
    // FMT_CHECK(init_ubx_decoder(&ubx_decoder, serial_device, ubx_rx_handle));

    // /* create a thread to probe the gps connection */
    // rt_thread_t tid = rt_thread_create("gps_probe", gps_probe_entry, str_buffer, 4096, RT_THREAD_PRIORITY_MAX - 2, 5);
    // RT_ASSERT(tid != NULL);

    // RT_CHECK(rt_thread_startup(tid));

    return RT_EOK;
}
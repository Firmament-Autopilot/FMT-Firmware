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

#include "hal/airspeed/airspeed.h"
#include "hal/i2c/i2c.h"
#include "module/sensor/sensor_hub.h"

#define EVENT_MS4525_UPDATE (1 << 0)

MCN_DECLARE(sensor_airspeed);

static rt_device_t i2c_dev;
static rt_thread_t thread;
static struct rt_event event;
static struct rt_timer timer;
static float diff_press_offset;

static void timer_update(void* parameter)
{
    rt_event_send(&event, EVENT_MS4525_UPDATE);
}

static rt_err_t ms4525_collect(uint8_t* val)
{
    struct rt_i2c_msg msgs;
    struct rt_i2c_device* i2c_device = (struct rt_i2c_device*)i2c_dev;

    msgs.flags = RT_I2C_RD | i2c_device->flags;
    msgs.buf = val;
    msgs.len = 4;

    if (rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, &msgs, 1) != 1) {
        return RT_ERROR;
    }

    uint8_t status = (val[0] & 0xC0) >> 6;

    switch (status) {
    case 0:
        // normal status. good data packet
        break;

    case 1:
        // command status
        return RT_ERROR;

    case 2:
        // busy status
        return RT_ERROR;

    case 3:
        // dianostic status
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t ms4525_init(void)
{
    uint8_t val[4];

    for (uint8_t i = 0; i < 5; i++) {
        /* try to read ms4525 data and check status */
        if (ms4525_collect(val) == RT_EOK) {
            return RT_EOK;
        }
        systime_mdelay(5);
    }

    /* exceed maximum try times, return error */
    return RT_ERROR;
}

rt_size_t ms4525_read(airspeed_dev_t dev, rt_off_t pos, void* data, rt_size_t size)
{
    uint8_t val[4];
    int16_t dp_raw;
    int16_t temp_raw;
    float* report = (float*)data;

    if (data == RT_NULL) {
        return 0;
    }

    if (ms4525_collect(val) != RT_EOK) {
        return 0;
    }

    dp_raw = ((val[0] << 8) + val[1]) & 0x3FFF;
    temp_raw = (((val[2] << 8) + val[3]) & 0xFFE0) >> 5;

    // temp_raw max is almost certainly an invalid reading
    if (temp_raw == 2047) {
        return 0;
    }

    float temperature = ((200.0f * temp_raw) / 2047) - 50;

    // Calculate differential pressure. As its centered around 8000
    // and can go positive or negative
    const float P_min = -1.0f;
    const float P_max = 1.0f;
    const float PSI_to_Pa = 6894.757f;
    /*
	  this equation is an inversion of the equation in the
	  pressure transfer function figure on page 4 of the datasheet

	  We negate the result so that positive differential pressures
	  are generated when the bottom port is used as the static
	  port on the pitot and top port is used as the dynamic port
	 */
    float diff_press_PSI = -((dp_raw - 0.1f * 16383) * (P_max - P_min) / (0.8f * 16383) + P_min);
    float diff_press_pa_raw = diff_press_PSI * PSI_to_Pa;

    report[0] = diff_press_pa_raw;
    report[1] = temperature;

    return size;
}

static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_MS4525_UPDATE;
    float report[2];
    airspeed_data_t airspeed_data;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK && (recv_set & EVENT_MS4525_UPDATE)) {
            if (ms4525_read(NULL, 0, report, 8) == 8) {
                airspeed_data.diff_pressure_pa = report[0] - diff_press_offset;
                airspeed_data.temperature_deg = report[1];
                airspeed_data.timestamp_ms = systime_now_ms();

                mcn_publish(MCN_HUB(sensor_airspeed), &airspeed_data);
            }
        }
    }
}

const static struct airspeed_ops __airspeed_ops = {
    .airspeed_control = RT_NULL,
    .airspeed_read = ms4525_read
};

rt_err_t drv_ms4525_init(const char* i2c_device_name, const char* device_name)
{
    static struct airspeed_device airspeed_dev = {
        .ops = &__airspeed_ops,
        .bus_type = AIRSPEED_I2C_BUS_TYPE
    };

    i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(i2c_dev != NULL);

    RT_TRY(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(ms4525_init());

    if (device_name != NULL) {
        RT_TRY(hal_airspeed_register(&airspeed_dev, device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    } else {
        FMT_CHECK(param_link_variable(PARAM_GET(CALIB, DIFF_PRESS_OFFSET), &diff_press_offset));

        RT_CHECK(rt_event_init(&event, "ms4525", RT_IPC_FLAG_FIFO));

        thread = rt_thread_create("ms4525", thread_entry, RT_NULL, 2 * 1024, 7, 1);
        RT_ASSERT(thread != NULL);
        RT_CHECK(rt_thread_startup(thread));

        /* register timer event */
        rt_timer_init(&timer, "ms4525", timer_update, RT_NULL, TICKS_FROM_MS(10), RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
        if (rt_timer_start(&timer) != RT_EOK) {
            return FMT_ERROR;
        }
    }

    return RT_EOK;
}
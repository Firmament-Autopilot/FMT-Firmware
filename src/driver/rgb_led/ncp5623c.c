/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#include "driver/rgb_led/ncp5623c.h"
#include "hal/i2c/i2c.h"

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define NCP5623_LED_OFF     0x00 /**< off */
#define NCP5623_LED_CURRENT 0x20 /**< current register */
#define NCP5623_LED_PWM0    0x40 /**< pwm0 register */
#define NCP5623_LED_PWM1    0x60 /**< pwm1 register */
#define NCP5623_LED_PWM2    0x80 /**< pwm2 register */

#define LED_BRIGHT 0x1f /**< full brightness */

static struct rt_i2c_device* i2c_device;
static struct rt_device ncp5623c_dev;
static uint8_t _r = 0;
static uint8_t _g = 0;
static uint8_t _b = 0;
static uint8_t _brightness = 0;

static void send_led_rgb(void)
{
    /* Do not pack 3 data into a single msg, otherwise color set would fail some how,
     * it could because that the ncp5623 speed is relatively slow */
    struct rt_i2c_msg msgs[3];
    uint8_t data[3] = { NCP5623_LED_PWM0 | _r, NCP5623_LED_PWM1 | _g, NCP5623_LED_PWM2 | _b };

    msgs[0].flags = RT_I2C_WR | i2c_device->flags;
    msgs[0].buf = &data[0];
    msgs[0].len = 1;

    msgs[1].flags = RT_I2C_WR | i2c_device->flags;
    msgs[1].buf = &data[1];
    msgs[1].len = 1;

    msgs[2].flags = RT_I2C_WR | i2c_device->flags;
    msgs[2].buf = &data[2];
    msgs[2].len = 1;

    rt_size_t ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, msgs, 3);
    if (ret != 3) {
        DRV_DBG("set led rgb fail!\n");
    }
}

static void send_led_bright(void)
{
    struct rt_i2c_msg msgs;
    uint8_t data = { NCP5623_LED_CURRENT | _brightness };

    msgs.flags = RT_I2C_WR | i2c_device->flags;
    msgs.buf = &data;
    msgs.len = 1;

    rt_size_t ret = rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, &msgs, 1);
    if (ret != 1) {
        PERIOD_EXECUTE(dbg, 1000, DRV_DBG("set led bright fail! IC1 ISR:0x%x ret:%d\n", I2C1->ISR, ret););
    }
}

static rt_err_t led_shutdown(void)
{
    struct rt_i2c_msg msgs;
    uint8_t data = NCP5623_LED_OFF;

    msgs.flags = RT_I2C_WR | i2c_device->flags;
    msgs.buf = &data;
    msgs.len = 1;

    if (rt_i2c_transfer(i2c_device->bus, i2c_device->slave_addr, &msgs, 1) != 1) {
        DRV_DBG("rgb led shutdown fail\n");
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t ncp5623c_control(rt_device_t dev, int cmd, void* args)
{
    uint8_t color;

    switch (cmd) {
    case NCP5623_CMD_SET_COLOR:
        color = (uint32_t)args;
        if (color == NCP5623_LED_RED) {
            _r = LED_BRIGHT;
            _g = 0;
            _b = 0;
        } else if (color == NCP5623_LED_GREEN) {
            _r = 0;
            _g = LED_BRIGHT;
            _b = 0;
        } else if (color == NCP5623_LED_BLUE) {
            _r = 0;
            _g = 0;
            _b = LED_BRIGHT;
        } else if (color == NCP5623_LED_YELLOW) {
            _r = LED_BRIGHT;
            _g = LED_BRIGHT;
            _b = 0;
        } else if (color == NCP5623_LED_PURPLE) {
            _r = LED_BRIGHT;
            _g = 0;
            _b = LED_BRIGHT;
        } else if (color == NCP5623_LED_CYAN) {
            _r = 0;
            _g = LED_BRIGHT;
            _b = LED_BRIGHT;
        } else if (color == NCP5623_LED_WHITE) {
            _r = LED_BRIGHT;
            _g = LED_BRIGHT;
            _b = LED_BRIGHT;
        } else {
            _r = 0;
            _g = 0;
            _b = 0;
        }
        send_led_rgb();
        break;

    case NCP5623_CMD_SET_BRIGHT:
        _brightness = (uint32_t)args & 0x1F;
        // NOTE: NCP5623C speed is low, so don't write i2c command too fast
        send_led_bright();
        break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_err_t probe(void)
{
    return led_shutdown();
}

rt_err_t drv_ncp5623c_init(const char* i2c_dev_name)
{
    i2c_device = (struct rt_i2c_device*)rt_device_find(i2c_dev_name);
    RT_ASSERT(i2c_device != NULL);

    RT_CHECK(rt_device_open(&i2c_device->parent, RT_DEVICE_OFLAG_RDWR));

    rt_device_t device = &ncp5623c_dev;

    device->type = RT_Device_Class_Miscellaneous;
    device->rx_indicate = RT_NULL;
    device->tx_complete = RT_NULL;
    device->user_data = RT_NULL;

    device->init = RT_NULL;
    device->open = RT_NULL;
    device->close = RT_NULL;
    device->read = RT_NULL;
    device->write = RT_NULL;
    device->control = ncp5623c_control;

    RT_TRY(probe());

    RT_CHECK(rt_device_register(device, "ncp5623c", RT_DEVICE_OFLAG_RDWR));

    return RT_EOK;
}

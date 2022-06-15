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

#include "driver/rgb_led/tca62724.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_bit_ops.h"
#include "hal/i2c/i2c_dev.h"
#include <firmament.h>

#define SALVE_ADDR  0x55 //7 bit addr
#define DUTY_OUT0   0x81
#define DUTY_OUT1   0x82
#define DUTY_OUT2   0x83
#define ENABLE_SHDN 0x84

static struct rt_device _tca62724_dev;
static rt_device_t _i2c_device;
static int _color = -1;
static int _bright = 7; // between 0 ~ 15

static uint8_t color_index[][4] = {
    { TCA62724_LED_RED, 0x00, 0x00, 0x01 },
    { TCA62724_LED_GREEN, 0x00, 0x01, 0x00 },
    { TCA62724_LED_BLUE, 0x01, 0x00, 0x00 },
    { TCA62724_LED_YELLOW, 0x00, 0x01, 0x01 },
    { TCA62724_LED_WHITE, 0x01, 0x01, 0x01 },
};

static uint8_t _write_reg(uint8_t duty0, uint8_t duty1, uint8_t duty2)
{
    uint16_t flags = 0x0000;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    uint8_t buffer[6];
    buffer[0] = DUTY_OUT0;
    buffer[1] = duty0;
    buffer[2] = DUTY_OUT1;
    buffer[3] = duty1;
    buffer[4] = DUTY_OUT2;
    buffer[5] = duty2;

    rt_size_t w_bytes = rt_device_write(_i2c_device, pos, (void*)buffer, sizeof(buffer));

    return w_bytes > 0 ? 0 : 1;
}

static uint8_t _read_reg(uint8_t reg_val[2])
{
    uint16_t flags = 0x0000;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR | 1);

    uint8_t buffer[2];

    rt_device_read(_i2c_device, pos, (void*)buffer, sizeof(buffer));

    reg_val[0] = buffer[0];
    reg_val[1] = buffer[1];

    return 0;
}

static rt_err_t tca62724_open(rt_device_t dev, rt_uint16_t oflag)
{
    uint16_t flags = RT_I2C_WR;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    uint8_t buffer[2];
    buffer[0] = ENABLE_SHDN;
    buffer[1] = 0x03;

    rt_device_write(_i2c_device, pos, (void*)buffer, sizeof(buffer));

    return RT_EOK;
}

rt_err_t tca62724_close(rt_device_t dev)
{
    uint16_t flags = RT_I2C_WR;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    uint8_t buffer[2];
    buffer[0] = ENABLE_SHDN;
    buffer[1] = 0x00;

    rt_device_write(_i2c_device, pos, (void*)buffer, sizeof(buffer));

    return RT_EOK;
}

static rt_size_t tca62724_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    if (pos < TCA62724_COLOR_NUM) {
        _color = pos;
        _write_reg(color_index[_color][1] * _bright, color_index[_color][2] * _bright, color_index[_color][3] * _bright);
        return size;
    }

    return 0;
}

static rt_err_t tca62724_control(rt_device_t dev, int cmd, void* args)
{
    switch (cmd) {
    case TCA62724_CMD_SET_BRIGHT: {
        if ((int)args <= TCA62724_MAX_BRIGHT) {
            _bright = (int)args;

            if (_color >= 0) {
                _write_reg(color_index[_color][1] * _bright, color_index[_color][2] * _bright, color_index[_color][3] * _bright);
            }
        }
    }

    default:
        break;
    }

    return RT_EOK;
}

rt_err_t tca62724_drv_init(const char* i2c_dev_name)
{
    _i2c_device = rt_device_find(i2c_dev_name);

    if (_i2c_device == RT_NULL) {
        return RT_ERROR;
    }

    if (rt_device_open(_i2c_device, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
        return RT_ERROR;
    }

    struct rt_device* device = &_tca62724_dev;

    device->type = RT_Device_Class_Miscellaneous;

    device->ref_count = 0;

    device->rx_indicate = RT_NULL;

    device->tx_complete = RT_NULL;

    device->init = RT_NULL;

    device->open = tca62724_open;

    device->close = tca62724_close;

    device->read = RT_NULL;

    device->write = tca62724_write;

    device->control = tca62724_control;

    device->user_data = RT_NULL;

    /* register pin device */
    return rt_device_register(device, "tca62724", RT_DEVICE_OFLAG_RDWR);
}
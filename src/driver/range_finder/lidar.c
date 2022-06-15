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

#include "driver/range_finder/lidar.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_bit_ops.h"
#include "hal/i2c/i2c_dev.h"
#include "module/sensor/sensor_hub.h"

static rt_device_t _i2c_device;
static struct rt_device _lidar_device;

#define SALVE_ADDR 0x62 /* 7 bit address, i2c_bit_send_address() will left shift address by 1 bit */

static int _write_reg(uint8_t reg, uint8_t val)
{
    uint16_t flags = 0x0000;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    uint8_t buffer[2] = { reg, val };
    return rt_device_write(_i2c_device, pos, (void*)buffer, sizeof(buffer));
}

static int _read_reg(uint8_t reg, uint8_t* buffer, uint8_t count)
{
    uint16_t flags = 0x0000;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    int ret;
    ret = rt_device_write(_i2c_device, pos, (void*)&reg, 1);

    if (ret != 1)
        return 0;

    return rt_device_read(_i2c_device, pos, (void*)buffer, count);
}

float lidar_measure(void)
{
    uint8_t dis_reg[2];
    uint16_t distance_cm;
    float distance_m;
    int res;

    res = _read_reg(0x8f, dis_reg, 2);

    if (res != 2) {
        return -1;
    }

    distance_cm = dis_reg[0] << 8 | dis_reg[1];
    distance_m = (float)distance_cm * 0.01f;

    return distance_m;
}

rt_size_t lidar_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    if (pos == 1) { /* read lidar data */
        float dis;
        dis = lidar_measure();

        if (dis < 0.0f) {
            console_printf("lidar read fail\n");
            return 0;
        }

        *((float*)buffer) = dis;
    } else {
        /* unknow pos */
        return 0;
    }

    return size;
}

rt_err_t lidar_init(rt_device_t dev)
{
    rt_err_t res;

    if (_i2c_device != RT_NULL) {
        res = rt_device_open(_i2c_device, RT_DEVICE_OFLAG_RDWR);

        if (res != RT_EOK) {
            printf("fail to open lidar i2c\n");
            return res;
        }

        //_write_reg(0x45, 0x28);	//50Hz
        _write_reg(0x45, 0x14); //100Hz
        _write_reg(0x11, 0xff); //indefinite repetition measure
        _write_reg(0x00, 0x04); //start measurement
    } else {
        printf("can not find lidar i2c device!\n");
        res = RT_EEMPTY;
    }

    return res;
}

rt_err_t rt_lidar_init(char* i2c_device_name)
{
    rt_err_t res = RT_EOK;

    /* set device type */
    _lidar_device.type = RT_Device_Class_Char;
    _lidar_device.init = lidar_init;
    _lidar_device.open = RT_NULL;
    _lidar_device.close = RT_NULL;
    _lidar_device.read = lidar_read;
    _lidar_device.write = RT_NULL;
    _lidar_device.control = RT_NULL;

    /* register to device manager */
    res |= rt_device_register(&_lidar_device, "lidar", RT_DEVICE_FLAG_RDWR);

    _i2c_device = rt_device_find(i2c_device_name);

    if (_i2c_device == RT_NULL) {
        rt_kprintf("i2c device %s not found!\r\n", i2c_device_name);
        return RT_EEMPTY;
    }

    return res;
}
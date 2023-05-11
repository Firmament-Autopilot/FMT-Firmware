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
#include <math.h>

#include "driver/mag/hmc5883.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_bit_ops.h"
#include "hal/i2c/i2c_dev.h"
#include "module/sensor/sensor_hub.h"

#define SALVE_ADDR 0x1E /* 7 bit address, i2c_bit_send_address() will left shift address by 1 bit */

#define ADDR_CONF_A         0x00
#define ADDR_CONF_B         0x01
#define ADDR_MODE           0x02
#define ADDR_DATA_OUT_X_MSB 0x03
#define ADDR_DATA_OUT_X_LSB 0x04
#define ADDR_DATA_OUT_Z_MSB 0x05
#define ADDR_DATA_OUT_Z_LSB 0x06
#define ADDR_DATA_OUT_Y_MSB 0x07
#define ADDR_DATA_OUT_Y_LSB 0x08
#define ADDR_STATUS         0x09
#define ADDR_IDENTI_REG_A   0x0A
#define ADDR_IDENTI_REG_B   0x0B
#define ADDR_IDENTI_REG_C   0x0C

#define MODE_REG_CONTINOUS_MODE (0 << 0)
#define MODE_REG_SINGLE_MODE    (1 << 0) /* default */

#ifdef USE_HMC5983
    #define RANGE_8_1G_RESOLUTION  0.00435f
    #define RANGE_5_6G_RESOLUTION  0.00303f
    #define RANGE_4_7G_RESOLUTION  0.00256f
    #define RANGE_4G_RESOLUTION    0.00227f
    #define RANGE_2_5G_RESOLUTION  0.00152f
    #define RANGE_1_9G_RESOLUTION  0.00122f
    #define RANGE_1_3G_RESOLUTION  0.00092f
    #define RANGE_0_88G_RESOLUTION 0.00073f
#else
    #define RANGE_8_1G_RESOLUTION  0.00457f
    #define RANGE_5_6G_RESOLUTION  0.00326f
    #define RANGE_4_7G_RESOLUTION  0.00277f
    #define RANGE_4G_RESOLUTION    0.00241f
    #define RANGE_2_5G_RESOLUTION  0.00163f
    #define RANGE_1_9G_RESOLUTION  0.00130f
    #define RANGE_1_3G_RESOLUTION  0.00098f
    #define RANGE_0_88G_RESOLUTION 0.00078f
#endif

float mgPerDigit;

typedef enum {
    HMC5883_SAMPLES_8 = 0b11,
    HMC5883_SAMPLES_4 = 0b10,
    HMC5883_SAMPLES_2 = 0b01,
    HMC5883_SAMPLES_1 = 0b00
} hmc5883_samples_def;

typedef enum {
    HMC5883_DATARATE_75HZ = 0b110,
    HMC5883_DATARATE_30HZ = 0b101,
    HMC5883_DATARATE_15HZ = 0b100,
    HMC5883_DATARATE_7_5HZ = 0b011,
    HMC5883_DATARATE_3HZ = 0b010,
    HMC5883_DATARATE_1_5HZ = 0b001,
    HMC5883_DATARATE_0_75_HZ = 0b000
} hmc5883_dataRate_def;

typedef enum {
    HMC5883_RANGE_8_1GA = 0b111,
    HMC5883_RANGE_5_6GA = 0b110,
    HMC5883_RANGE_4_7GA = 0b101,
    HMC5883_RANGE_4GA = 0b100,
    HMC5883_RANGE_2_5GA = 0b011,
    HMC5883_RANGE_1_9GA = 0b010,
    HMC5883_RANGE_1_3GA = 0b001,
    HMC5883_RANGE_0_88GA = 0b000
} hmc5883_range_def;

typedef enum {
    HMC5883_SLEEP = 0b11,
    HMC5883_IDLE = 0b10,
    HMC5883_SINGLE = 0b01,
    HMC5883_CONTINOUS = 0b00
} hmc5883_mode_def;

static rt_device_t _i2c_device;
static struct rt_device ext_mag_device;

/* Re-implement this function to define customized rotation */
RT_WEAK void hmc5883_rotate_to_frd(float* data)
{
    /* do nothing */
}

int _write_reg(uint8_t reg, uint8_t val)
{
    uint16_t flags = 0x0000;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    uint8_t buffer[2] = { reg, val };
    return rt_device_write(_i2c_device, pos, (void*)buffer, sizeof(buffer));
}

int _read_reg(uint8_t reg, uint8_t* buffer, uint8_t count)
{
    uint16_t flags = 0x0000;
    rt_off_t pos = (rt_off_t)((flags << 16) | SALVE_ADDR);

    int ret;
    ret = rt_device_write(_i2c_device, pos, (void*)&reg, 1);

    if (ret != 1)
        return 0;

    return rt_device_read(_i2c_device, pos, (void*)buffer, count);
}

int _hmc5883_measure(void)
{
    int ret;

    ret = _write_reg(ADDR_MODE, MODE_REG_SINGLE_MODE);

    return ret;
}

int _hmc5883_collect(int16_t raw_mag[3])
{
    uint8_t data_reg[6]; /* XA,XB,ZA,ZB,YA,YB */
    int16_t raw_val[3];

    _read_reg(ADDR_DATA_OUT_X_MSB, data_reg, sizeof(data_reg));

    raw_val[0] = (data_reg[0] << 8) + data_reg[1];
    raw_val[1] = (data_reg[4] << 8) + data_reg[5];
    raw_val[2] = (data_reg[2] << 8) + data_reg[3];

    console_printf("raw mag:%d %d %d\n", raw_val[0], raw_val[1], raw_val[2]);

    /*
	 * If any of the values are -4096, there was an internal math error in the sensor.
	 * Generalise this to a simple range check that will also catch some bit errors.
	 */
    if ((abs(raw_val[0]) > 2048) || (abs(raw_val[1]) > 2048) || (abs(raw_val[2]) > 2048)) {
        console_printf("hmc5883 collect error\n");
        return 1;
    }

    /* change to NED axis */
    raw_mag[0] = -raw_val[1];
    raw_mag[1] = raw_val[0];
    raw_mag[2] = raw_val[2];

    return 0;
}

int _hmc5883_check_identity(void)
{
    uint8_t reg_buffer[3];

    _read_reg(ADDR_IDENTI_REG_A, reg_buffer, sizeof(reg_buffer));

    if (reg_buffer[0] != 0x48 || reg_buffer[1] != 0x34 || reg_buffer[2] != 0x33) {
        return 0;
    }

    return 1;
}

void _hmc5883_set_range(hmc5883_range_def range)
{
    switch (range) {
    case HMC5883_RANGE_0_88GA:
        mgPerDigit = RANGE_0_88G_RESOLUTION;
        break;

    case HMC5883_RANGE_1_3GA:
        mgPerDigit = RANGE_1_3G_RESOLUTION;
        break;

    case HMC5883_RANGE_1_9GA:
        mgPerDigit = RANGE_1_9G_RESOLUTION;
        break;

    case HMC5883_RANGE_2_5GA:
        mgPerDigit = RANGE_2_5G_RESOLUTION;
        break;

    case HMC5883_RANGE_4GA:
        mgPerDigit = RANGE_4G_RESOLUTION;
        break;

    case HMC5883_RANGE_4_7GA:
        mgPerDigit = RANGE_4_7G_RESOLUTION;
        break;

    case HMC5883_RANGE_5_6GA:
        mgPerDigit = RANGE_5_6G_RESOLUTION;
        break;

    case HMC5883_RANGE_8_1GA:
        mgPerDigit = RANGE_8_1G_RESOLUTION;
        break;

    default:
        break;
    }

    _write_reg(ADDR_CONF_B, range << 5);
}

void _hmc5883_set_measure_mode(hmc5883_mode_def mode)
{
    uint8_t value;

    _read_reg(ADDR_MODE, &value, 1);
    value &= 0b11111100;
    value |= mode;

    _write_reg(ADDR_MODE, value);
}

void _hmc5883_set_date_rate(hmc5883_dataRate_def dataRate)
{
    uint8_t value;

    _read_reg(ADDR_CONF_A, &value, 1);
    value &= 0b11100011;
    value |= (dataRate << 2);

    _write_reg(ADDR_CONF_A, value);
}

rt_err_t hmc5883_init(rt_device_t dev)
{
    rt_err_t res;

    if (_i2c_device != RT_NULL) {
        res = rt_device_open(_i2c_device, RT_DEVICE_OFLAG_RDWR);

        if (res != RT_EOK) {
            console_printf("hmc5883 i2c open fail\n");
            return res;
        }

        if (!_hmc5883_check_identity()) {
            console_printf("hmc5883 identity check fail\n");
            return RT_ERROR;
        }

        _hmc5883_set_range(HMC5883_RANGE_1_9GA);
        /* we use single mode, so do not need to set rate */
        //_hmc5883_set_date_rate(HMC5883_DATARATE_75HZ);

        /* 1 measurement should take 8.6ms, so we start the first measurement here */
        _hmc5883_measure();
    } else {
        printf("fail to open hmc5883 i2c device!\n");
        res = RT_EEMPTY;
    }

    return res;
}

rt_size_t hmc5883_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    int res;
    int16_t tbuff[3];
    res = _hmc5883_collect(tbuff);
    /* after collect, we start next measurement */
    _hmc5883_measure();

    if (res != 0 || buffer == NULL) {
        return 0;
    }

    ((float*)buffer)[0] = tbuff[0] * mgPerDigit;
    ((float*)buffer)[1] = tbuff[1] * mgPerDigit;
    ((float*)buffer)[2] = tbuff[2] * mgPerDigit;

    hmc5883_rotate_to_frd(buffer);

    return size;
}

rt_err_t hmc5883_control(rt_device_t dev, int cmd, void* args)
{
    rt_err_t res = RT_EOK;

    switch (cmd) {
    case SENSOR_SET_MAG_RANGE: {
        _hmc5883_set_range(*(hmc5883_range_def*)args);
    } break;

    case SENSOR_SET_MAG_SAMPLERATE: {
        _hmc5883_set_date_rate(*(hmc5883_dataRate_def*)args);
    } break;

    default:
        return RT_ERROR;
    }

    return res;
}

rt_err_t rt_hmc5883_init(char* i2c_device_name)
{
    rt_err_t res = RT_EOK;

    /* set device type */
    ext_mag_device.type = RT_Device_Class_Char;
    ext_mag_device.init = hmc5883_init;
    ext_mag_device.open = RT_NULL;
    ext_mag_device.close = RT_NULL;
    ext_mag_device.read = hmc5883_read;
    ext_mag_device.write = RT_NULL;
    ext_mag_device.control = hmc5883_control;

    /* register to device manager */
    res |= rt_device_register(&ext_mag_device, "hmc5883", RT_DEVICE_FLAG_RDWR);

    _i2c_device = rt_device_find(i2c_device_name);

    if (_i2c_device == RT_NULL) {
        rt_kprintf("i2c device %s not found!\r\n", i2c_device_name);
        return RT_EEMPTY;
    }

    return res;
}

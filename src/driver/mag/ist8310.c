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
#include "driver/mag/ist8310.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_dev.h"
#include "hal/mag/mag.h"

// #define DRV_DBG(...)                   console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define REG_WHOAMI       0x00
#define REG_STAT1        0x02
#define REG_DATA_OUT_X_L 0x03
#define REG_DATA_OUT_X_H 0x04
#define REG_DATA_OUT_Y_L 0x05
#define REG_DATA_OUT_Y_H 0x06
#define REG_DATA_OUT_Z_L 0x07
#define REG_DATA_OUT_Z_H 0x08
#define REG_STAT2        0x09
#define REG_CTRL1        0x0a
#define REG_CTRL2        0x0b
#define REG_TEMP_L       0x1c
#define REG_TEMP_H       0x1d
#define REG_CTRL3        0x41
#define REG_CTRL4        0x42

#define CTRL1_ODR_SINGLE 0x01 /* Single measurement mode */
#define CTRL1_ODR_10_HZ  0x03
#define CTRL1_ODR_20_HZ  0x05
#define CTRL1_ODR_50_HZ  0x07
#define CTRL1_ODR_100_HZ 0x06
#define CTRL1_ODR_200_HZ 0x0B

#define CTRL2_SRST 0x01 /* Software reset */

#define CTRL3_SAMPLEAVG_16 0x24 /* Sample Averaging 16 */
#define CTRL3_SAMPLEAVG_8  0x1b /* Sample Averaging 8 */
#define CTRL3_SAMPLEAVG_4  0x12 /* Sample Averaging 4 */
#define CTRL3_SAMPLEAVG_2  0x09 /* Sample Averaging 2 */
#define CTRL4_SRPD         0xC0 /* Set Reset Pulse Duration */

#define IST8310_DEVICE_ID      0x10
#define IST8310_SCALE_TO_GAUSS 0.003f

#define IST8310_CONFIG_DEFAULT                              \
    {                                                       \
        100,                /* 100hz sample rate */         \
            50,             /* 16 times average */          \
            MAG_RANGE_16GA, /* xy +-16guess, z +-25guess */ \
    }

static rt_device_t i2c_dev;
static float _range_scale = IST8310_SCALE_TO_GAUSS;

RT_WEAK void ist8310_user_calibrate(float data[3]);

/* Re-implement this function to define customized rotation */
RT_WEAK void ist8310_rotate_to_frd(float* data)
{
    /* do nothing */
}

static rt_err_t mag_raw_measure(int16_t mag[3])
{
    uint8_t buffer[6];

    RT_TRY(i2c_read_regs(i2c_dev, REG_DATA_OUT_X_L, buffer, sizeof(buffer)));

    /* swap the data */
    mag[0] = ((int16_t)buffer[1] << 8) | (int16_t)buffer[0];
    mag[1] = ((int16_t)buffer[3] << 8) | (int16_t)buffer[2];
    mag[2] = ((int16_t)buffer[5] << 8) | (int16_t)buffer[4];
    /* start next measurement */
    // RT_TRY(i2c_write_reg(i2c_dev, REG_CTRL1, CTRL1_ODR_SINGLE));

    return RT_EOK;
}

static rt_err_t mag_measure(float mag[3])
{
    int16_t raw[3];

    RT_TRY(mag_raw_measure(raw));

    mag[0] = _range_scale * raw[0];
    mag[1] = _range_scale * raw[1];
    mag[2] = _range_scale * raw[2];

    ist8310_rotate_to_frd(mag);

    if (ist8310_user_calibrate != RT_NULL) {
        /* do user defined calibration */
        ist8310_user_calibrate(mag);
    }

    return RT_EOK;
}

static rt_err_t probe(void)
{
    uint8_t device_id;

    RT_TRY(i2c_read_reg(i2c_dev, REG_WHOAMI, &device_id));

    if (device_id != IST8310_DEVICE_ID) {
        DRV_DBG("ist8310 unmatched id: 0x%x\n", device_id);
        return RT_ERROR;
    }

    return RT_EOK;
}

static rt_err_t ist8310_init(void)
{
    /* check if device connected */
    RT_TRY(probe());

    /* software reset */
    RT_CHECK(i2c_write_reg(i2c_dev, REG_CTRL2, CTRL2_SRST));

    sys_msleep(10);

    /* configure control register 3 */
    RT_CHECK(i2c_write_reg(i2c_dev, REG_CTRL3, CTRL3_SAMPLEAVG_16));

    /* configure control register 4 */
    RT_CHECK(i2c_write_reg(i2c_dev, REG_CTRL4, CTRL4_SRPD));

    /* Trigger one time measurement */
    // RT_CHECK(i2c_write_reg(i2c_dev, REG_CTRL1, CTRL1_ODR_SINGLE));

    RT_CHECK(i2c_write_reg(i2c_dev, REG_CTRL1, CTRL1_ODR_100_HZ));

    return RT_EOK;
}

static rt_size_t ist8310_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (mag_measure(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct mag_ops __mag_ops = {
    NULL,
    NULL,
    ist8310_read,
};

rt_err_t drv_ist8310_init(const char* i2c_device_name, const char* mag_device_name)
{
    static struct mag_device mag_dev = {
        .ops = &__mag_ops,
        .config = IST8310_CONFIG_DEFAULT,
        .bus_type = MAG_I2C_BUS_TYPE
    };

    i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(i2c_dev != NULL);

    RT_CHECK(rt_device_open(i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(ist8310_init());

    RT_CHECK(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

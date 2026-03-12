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

#include "board_device.h"
#include "driver/imu/bmi055.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)

#define REG_WHO_AM_I     0x00
#define REG_REVOSION_ID  0x01
#define REG_CTRL1        0x02
#define REG_CTRL2        0x03
#define REG_CTRL3        0x04
#define REG_CTRL5        0x06
#define REG_CTRL7        0x08
#define REG_ACCEL_XOUT_L 0x35
#define REG_GYRO_XOUT_L  0x3B

#define DEVICE_ID        0x05
#define REVISION_ID      0x7C

#define M_PI_F           3.1415926f

static rt_device_t imu_spi_dev;

/* Re-implement this function to define customized rotation */
RT_WEAK void qmi8a01_rotate_to_frd(float* val)
{
    /* do nothing */
}

static rt_err_t imu_lowlevel_init(void)
{
    uint8_t dev_id;
    uint8_t revision_id;

    /* init spi bus */
    RT_TRY(rt_device_open(imu_spi_dev, RT_DEVICE_OFLAG_RDWR));

    /* chip probe */
    RT_TRY(spi_read_reg8(imu_spi_dev, REG_WHO_AM_I, &dev_id));
    RT_TRY(spi_read_reg8(imu_spi_dev, REG_REVOSION_ID, &revision_id));
    if (dev_id != DEVICE_ID || revision_id != REVISION_ID) {
        DRV_DBG("QMI8A01 wrong device id:%x revision id:%x\n", dev_id, revision_id);
        return RT_EIO;
    }

    RT_TRY(spi_write_reg8(imu_spi_dev, REG_CTRL1, 0x60)); /* address auto increment */
    RT_TRY(spi_write_reg8(imu_spi_dev, REG_CTRL2, 0x32)); /* acc config: +-16g, 1793.6Hz sample rate */
    RT_TRY(spi_write_reg8(imu_spi_dev, REG_CTRL3, 0x72)); /* gyr config: +-2048dps, 1793.6Hz sample rate */
    RT_TRY(spi_write_reg8(imu_spi_dev, REG_CTRL5, 0x77)); /* Enable internal lpf, 239.8Hz(13.37% of ODR) cut-off freq */
    RT_TRY(spi_write_reg8(imu_spi_dev, REG_CTRL7, 0x03)); /* gyro and accel enable */

    systime_mdelay(200);

    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    int16_t raw[3] = { 0 };
    float* gyro_data = (float*)data;
    static float gyro_range_scale = (M_PI_F / (180.0f * 16));

    if (data == RT_NULL) {
        return 0;
    }

    if (spi_read_multi_reg8(imu_spi_dev, REG_GYRO_XOUT_L, (uint8_t*)raw, 6) != RT_EOK) {
        return 0;
    }

    gyro_data[0] = raw[0] * gyro_range_scale;
    gyro_data[1] = raw[1] * gyro_range_scale;
    gyro_data[2] = raw[2] * gyro_range_scale;

    qmi8a01_rotate_to_frd(gyro_data);

    return size;
}

static rt_size_t accel_read(accel_dev_t accel_dev, rt_off_t pos, void* data, rt_size_t size)
{
    int16_t raw[3] = { 0 };
    float* accel_data = (float*)data;
    static float accel_range_scale = (9.80665f / 2048.0f);

    if (data == NULL) {
        return 0;
    }

    if (spi_read_multi_reg8(imu_spi_dev, REG_ACCEL_XOUT_L, (uint8_t*)raw, 6) != RT_EOK) {
        return 0;
    }

    accel_data[0] = raw[0] * accel_range_scale;
    accel_data[1] = raw[1] * accel_range_scale;
    accel_data[2] = raw[2] * accel_range_scale;

    qmi8a01_rotate_to_frd(accel_data);

    return size;
}

const static struct gyro_ops _gyro_ops = {
    .gyro_config = NULL,
    .gyro_control = NULL,
    .gyro_read = gyro_read
};

const static struct accel_ops _accel_ops = {
    .accel_config = NULL,
    .accel_control = NULL,
    .accel_read = accel_read
};

static struct accel_device accel_dev = {
    .ops = &_accel_ops,
    .config = {
        1794,            /* sample rate */
        240,             /* internal lpf cut-off freq */
        ACCEL_RANGE_16G, /* +-16g */
    },
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct gyro_device gyro_dev = {
    .ops = &_gyro_ops,
    .config = {
        1794,               /* sample rate */
        240,                /* internal lpf cut-off freq */
        GYRO_RANGE_2000DPS, /* +-2048 dps */
    },
    .bus_type = GYRO_SPI_BUS_TYPE
};

rt_err_t drv_qmi8a01_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    /* Initialize gyroscope */

    imu_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(imu_spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 10000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)imu_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* init spi bus */
    RT_TRY(rt_device_open(imu_spi_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(imu_lowlevel_init());

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}
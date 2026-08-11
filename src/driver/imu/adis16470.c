/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"

#define DIR_WRITE      0x8000
#define DEG2RAD_FACTOR 0.01745329f

struct ADIS16470_Data {
    float gyro_radPs[3];
    float accel_mPs2[3];
    uint64_t timestamp_us;
} adis16470_data = { 0 };

/* Re-implement this function to define customized rotation */
RT_WEAK void adis16470_rotate_to_frd(float* data, uint8_t dev_id)
{
    /* do nothing */
    (void)data;
    (void)dev_id;
}

static rt_err_t adis16470_read_reg(rt_device_t spi_device, uint16_t reg, uint16_t* data)
{
    if (rt_spi_send((struct rt_spi_device*)spi_device, &reg, 1) != 1)
        return RT_ERROR;

    systime_udelay(16); /* 16us stall time */

    if (rt_spi_recv((struct rt_spi_device*)spi_device, data, 1) != 1)
        return RT_ERROR;

    return RT_EOK;
}

static rt_err_t adis16470_write_reg(rt_device_t spi_device, uint16_t reg, uint16_t data)
{
    uint16_t cmd[2];

    cmd[0] = (reg & 0xFF00) | DIR_WRITE | (data & 0x00FF);
    cmd[1] = ((reg & 0x00FF) << 8) | DIR_WRITE | ((data & 0xFF00) >> 8);

    if (rt_spi_send((struct rt_spi_device*)spi_device, &cmd[0], 1) != 1)
        return RT_ERROR;

    systime_udelay(16); /* 16us stall time */

    if (rt_spi_send((struct rt_spi_device*)spi_device, &cmd[1], 1) != 1)
        return RT_ERROR;

    return RT_EOK;
}

static rt_err_t adis16470_burst_read(rt_device_t bus_dev)
{
    struct BurstRead {
        uint16_t DIAG_STAT;
        int16_t X_GYRO_OUT;
        int16_t Y_GYRO_OUT;
        int16_t Z_GYRO_OUT;
        int16_t X_ACCL_OUT;
        int16_t Y_ACCL_OUT;
        int16_t Z_ACCL_OUT;
        int16_t TEMP_OUT;
        uint16_t DATA_CNTR;
        uint16_t CHECK_SUM;
    } buffer;
    uint16_t cmd = 0x6800;
    uint16_t cs = 0;
    uint8_t* dp = (uint8_t*)&buffer;

    RT_TRY(rt_spi_send_then_recv((struct rt_spi_device*)bus_dev, &cmd, 1, &buffer, 10));

    for (uint8_t i = 0; i < 18; i++) {
        cs += dp[i];
    }

    if (cs != buffer.CHECK_SUM) {
        /* checksum failed */
        return RT_ERROR;
    }

    adis16470_data.gyro_radPs[0] = buffer.X_GYRO_OUT / 10.0f * DEG2RAD_FACTOR;
    adis16470_data.gyro_radPs[1] = buffer.Y_GYRO_OUT / 10.0f * DEG2RAD_FACTOR;
    adis16470_data.gyro_radPs[2] = buffer.Z_GYRO_OUT / 10.0f * DEG2RAD_FACTOR;
    adis16470_data.accel_mPs2[0] = buffer.X_ACCL_OUT / 800.0f * 9.806f;
    adis16470_data.accel_mPs2[1] = buffer.Y_ACCL_OUT / 800.0f * 9.806f;
    adis16470_data.accel_mPs2[2] = buffer.Z_ACCL_OUT / 800.0f * 9.806f;
    adis16470_data.timestamp_us = systime_now_us();

    adis16470_rotate_to_frd(adis16470_data.gyro_radPs, 0);
    adis16470_rotate_to_frd(adis16470_data.accel_mPs2, 0);

    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    float* dp = data;

    if (data == NULL) {
        return 0;
    }

    if (systime_now_us() - adis16470_data.timestamp_us >= 500) {
        if (adis16470_burst_read(gyro->bus_dev) != RT_EOK) {
            return 0;
        }
    }

    dp[0] = adis16470_data.gyro_radPs[0];
    dp[1] = adis16470_data.gyro_radPs[1];
    dp[2] = adis16470_data.gyro_radPs[2];

    return size;
}

static rt_size_t accel_read(accel_dev_t accel, rt_off_t pos, void* data, rt_size_t size)
{
    float* dp = data;

    if (data == NULL) {
        return 0;
    }

    if (systime_now_us() - adis16470_data.timestamp_us >= 500) {
        if (adis16470_burst_read(accel->bus_dev) != RT_EOK) {
            return 0;
        }
    }

    dp[0] = adis16470_data.accel_mPs2[0];
    dp[1] = adis16470_data.accel_mPs2[1];
    dp[2] = adis16470_data.accel_mPs2[2];

    return size;
}

const static struct gyro_ops __gyro_ops = {
    .gyro_config = NULL,
    .gyro_control = NULL,
    .gyro_read = gyro_read,
};

const static struct accel_ops __accel_ops = {
    .accel_config = NULL,
    .accel_control = NULL,
    .accel_read = accel_read,
};

static rt_err_t adis16470_init(rt_device_t bus_dev)
{
    uint16_t dev_id;

    RT_TRY(rt_device_open(bus_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(adis16470_read_reg(bus_dev, 0x7273, &dev_id));
    if (dev_id != 0x4056) {
        // printf("wrong adis16470 product id:0x%x\n", dev_id);
        return RT_ENOSYS;
    }

    return RT_EOK;
}

#define GYRO_CONFIG                                   \
    {                                                 \
        1000,                   /* 1K sample rate */  \
            500,                /* 500Hz bandwidth */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */    \
    }

#define ACCEL_CONFIG                   \
    {                                  \
        1000,    /* 1K sample rate */  \
            500, /* 500Hz bandwidth */ \
            40,  /* +-16g */           \
    }

static struct gyro_device gyro_dev = {
    .ops = &__gyro_ops,
    .config = GYRO_CONFIG,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct accel_device accel_dev = {
    .ops = &__accel_ops,
    .config = ACCEL_CONFIG,
    .bus_type = GYRO_SPI_BUS_TYPE
};

rt_err_t drv_adis16470_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    rt_device_t bus_dev = rt_device_find(spi_device_name);
    RT_ASSERT(bus_dev != NULL);

    gyro_dev.bus_dev = bus_dev;
    accel_dev.bus_dev = bus_dev;

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 16;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 1000000;   /* max speed for burst read is 1M */

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)bus_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* sensor init */
    RT_TRY(adis16470_init(bus_dev));

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, NULL));
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}
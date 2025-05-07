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

#include "driver/mag/rm3100.h"
#include "hal/i2c/i2c.h"
#include "hal/i2c/i2c_dev.h"
#include "hal/mag/mag.h"
#include "hal/spi/spi.h"

#define DRV_DBG(...)       printf(__VA_ARGS__)

#define RM3100_REVID       0x22

#define RM3100_POLL_REG    0x00
#define RM3100_CMM_REG     0x01
#define RM3100_CCX_MSB_REG 0x04
#define RM3100_CCX_LSB_REG 0x05
#define RM3100_CCY_MSB_REG 0x06
#define RM3100_CCY_LSB_REG 0x07
#define RM3100_CCZ_MSB_REG 0x08
#define RM3100_CCZ_LSB_REG 0x09
#define RM3100_TMRC_REG    0x0B
#define RM3100_MX2_REG     0x24
#define RM3100_STATUS_REG  0x34
#define RM3100_REVID_REG   0x36

#define RM3100_TMRC_600HZ  0x92
#define RM3100_TMRC_300HZ  0x93
#define RM3100_TMRC_150HZ  0x94
#define RM3100_TMRC_75HZ   0x95
#define RM3100_TMRC_37HZ   0x96
#define RM3100_TMRC_18HZ   0x97
#define RM3100_TMRC_9HZ    0x98

#define GAIN_CC200         75.0f
#define UTESLA_TO_GAUSS    0.01f // uT to Gauss conversion

static rt_device_t mag_spi_dev;
static rt_device_t mag_i2c_dev;
static float scale = 1.0;

/* Re-implement this function to define customized rotation */
RT_WEAK void rm310_rotate_to_frd(float* data)
{
    /* do nothing */
    (void)data;
}

static rt_err_t lowlevel_init(void)
{
    uint8_t mag_id = 0;

    if (mag_spi_dev != NULL) {
        /* init spi bus */
        RT_TRY(rt_device_open(mag_i2c_dev, RT_DEVICE_OFLAG_RDWR));

        RT_TRY(spi_read_reg8(mag_spi_dev, RM3100_REVID_REG, &mag_id));
        if (RM3100_REVID != mag_id) {
            DRV_DBG("rm3100 wrong chip id:0x%x\n", mag_id);
            return RT_ERROR;
        }

        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_TMRC_REG, RM3100_TMRC_150HZ));

        /* set default cycle count */
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CCX_MSB_REG, 0x00));
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CCX_LSB_REG, 0xC8));
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CCY_MSB_REG, 0x00));
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CCY_LSB_REG, 0xC8));
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CCZ_MSB_REG, 0x00));
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CCZ_LSB_REG, 0xC8));
        /* has to be changed if using a different cycle count */
        scale = (1 / GAIN_CC200) * UTESLA_TO_GAUSS;

        /* Set CMZ,CMY,CMX and START (Continue Mode) */
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CMM_REG, 0x71));
    } else if (mag_i2c_dev != NULL) {
        RT_TRY(i2c_read_reg(mag_i2c_dev, RM3100_REVID_REG, &mag_id));
        if (RM3100_REVID != mag_id) {
            DRV_DBG("rm3100 wrong chip id:0x%x\n", mag_id);
            return RT_ERROR;
        }

        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_TMRC_REG, RM3100_TMRC_150HZ));

        /* set default cycle count */
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CCX_MSB_REG, 0x00));
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CCX_LSB_REG, 0xC8));
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CCY_MSB_REG, 0x00));
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CCY_LSB_REG, 0xC8));
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CCZ_MSB_REG, 0x00));
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CCZ_LSB_REG, 0xC8));
        /* has to be changed if using a different cycle count */
        scale = (1 / GAIN_CC200) * UTESLA_TO_GAUSS;

        /* Set CMZ,CMY,CMX and START (Continue Mode) */
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CMM_REG, 0x71));
    }

    return RT_EOK;
}

static rt_err_t mag_measure(float mag[3])
{
    uint8_t mag_data[9];
    uint8_t status;
    int32_t magx = 0;
    int32_t magy = 0;
    int32_t magz = 0;

    if (mag_spi_dev != NULL) {
        RT_TRY(spi_read_reg8(mag_spi_dev, RM3100_STATUS_REG, &status));
        if (!(status & 0x80)) {
            /* data is not ready */
            return RT_EBUSY;
        }

        RT_TRY(spi_read_multi_reg8(mag_spi_dev, RM3100_MX2_REG, mag_data, sizeof(mag_data)));

        // the 24 bits of data for each axis are in 2s complement representation
        // each byte is shifted to its position in a 24-bit unsigned integer and from 8 more bits to be left-aligned in a 32-bit integer
        magx = ((uint32_t)mag_data[0] << 24) | ((uint32_t)mag_data[1] << 16) | ((uint32_t)mag_data[2] << 8);
        magy = ((uint32_t)mag_data[3] << 24) | ((uint32_t)mag_data[4] << 16) | ((uint32_t)mag_data[5] << 8);
        magz = ((uint32_t)mag_data[6] << 24) | ((uint32_t)mag_data[7] << 16) | ((uint32_t)mag_data[8] << 8);
        // right-shift signed integer back to get correct measurement value
        magx >>= 8;
        magy >>= 8;
        magz >>= 8;
        // apply scaler
        mag[0] = magx * scale;
        mag[1] = magy * scale;
        mag[2] = magz * scale;

        /* start next measurement */
        RT_TRY(spi_write_reg8(mag_spi_dev, RM3100_CMM_REG, 0x71));
    } else if (mag_i2c_dev != NULL) {
        RT_TRY(i2c_read_reg(mag_i2c_dev, RM3100_STATUS_REG, &status));
        if (!(status & 0x80)) {
            /* data is not ready */
            return RT_EBUSY;
        }

        RT_TRY(i2c_read_regs(mag_i2c_dev, RM3100_MX2_REG, mag_data, sizeof(mag_data)));

        // the 24 bits of data for each axis are in 2s complement representation
        // each byte is shifted to its position in a 24-bit unsigned integer and from 8 more bits to be left-aligned in a 32-bit integer
        magx = ((uint32_t)mag_data[0] << 24) | ((uint32_t)mag_data[1] << 16) | ((uint32_t)mag_data[2] << 8);
        magy = ((uint32_t)mag_data[3] << 24) | ((uint32_t)mag_data[4] << 16) | ((uint32_t)mag_data[5] << 8);
        magz = ((uint32_t)mag_data[6] << 24) | ((uint32_t)mag_data[7] << 16) | ((uint32_t)mag_data[8] << 8);
        // right-shift signed integer back to get correct measurement value
        magx >>= 8;
        magy >>= 8;
        magz >>= 8;
        // apply scaler
        mag[0] = magx * scale;
        mag[1] = magy * scale;
        mag[2] = magz * scale;

        /* start next measurement */
        RT_TRY(i2c_write_reg(mag_i2c_dev, RM3100_CMM_REG, 0x71));
    }

    rm310_rotate_to_frd(mag);

    return RT_EOK;
}

static rt_size_t rm3100_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
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
    .mag_config = NULL,
    .mag_control = NULL,
    .mag_read = rm3100_read,
};

rt_err_t drv_rm3100_init(const char* spi_device_name, const char* mag_device_name)
{
    static struct mag_device mag_dev = {
        .ops = &__mag_ops,
        .config = { 0 },
        .bus_type = MAG_SPI_BUS_TYPE
    };

    mag_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(mag_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 1000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)mag_spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    RT_TRY(lowlevel_init());

    RT_TRY(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

rt_err_t drv_rm3100_i2c_init(const char* i2c_device_name, const char* mag_device_name)
{
    static struct mag_device mag_dev = {
        .ops = &__mag_ops,
        .config = { 0 },
        .bus_type = MAG_I2C_BUS_TYPE
    };

    mag_i2c_dev = rt_device_find(i2c_device_name);

    RT_ASSERT(mag_i2c_dev != NULL);

    RT_CHECK(rt_device_open(mag_i2c_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(lowlevel_init());

    RT_TRY(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

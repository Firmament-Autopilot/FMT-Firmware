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

#define DRV_DBG(...)

#ifdef BIT
    #undef BIT
#endif

#define BIT(_idx) (1 << _idx)
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

#define DEVICE_ID 0x47

/* Bank0 Registers */
#define REG_DEVICE_CONFIG      0x11
#define REG_INT_CONFIG         0x14
#define REG_FIFO_CONFIG        0x16
#define REG_TEMP_DATA1         0x1D
#define REG_TEMP_DATA0         0x1E
#define REG_ACCEL_DATA_X1      0x1F
#define REG_GYRO_DATA_X1       0x25
#define REG_INT_STATUS         0x2D
#define REG_FIFO_COUNTH        0x2E
#define REG_FIFO_COUNTL        0x2F
#define REG_FIFO_DATA          0x30
#define REG_SIGNAL_PATH_RESET  0x4B
#define REG_INTF_CONFIG0       0x4C
#define REG_INTF_CONFIG1       0x4D
#define REG_PWR_MGMT0          0x4E
#define REG_GYRO_CONFIG0       0x4F
#define REG_ACCEL_CONFIG0      0x50
#define REG_GYRO_CONFIG1       0x51
#define REG_GYRO_ACCEL_CONFIG0 0x52
#define REG_ACCEL_CONFIG1      0x53
#define REG_TMST_CONFIG        0x54
#define REG_FIFO_CONFIG1       0x5F
#define REG_FIFO_CONFIG2       0x60
#define REG_FIFO_CONFIG3       0x61
#define REG_INT_CONFIG0        0x63
#define REG_INT_CONFIG1        0x64
#define REG_INT_SOURCE0        0x65
#define REG_SELF_TEST_CONFIG   0x70
#define REG_WHO_AM_I           0x75
#define REG_REG_BANK_SEL       0x76

/* Bank1 Registers */
#define REG_GYRO_CONFIG_STATIC2 0x0B
#define REG_INTF_CONFIG5        0x7B

/* Bank2 Registers */
#define REG_ACCEL_CONFIG_STATIC2 0x03

#define GYRO_RANGE_2000_DPS   REG_VAL(0, BIT(5) | BIT(6) | BIT(7))
#define GYRO_RANGE_1000_DPS   REG_VAL(BIT(5), BIT(6) | BIT(7))
#define GYRO_RANGE_500_DPS    REG_VAL(BIT(6), BIT(5) | BIT(7))
#define GYRO_RANGE_250_DPS    REG_VAL(BIT(5) | BIT(6), BIT(7))
#define GYRO_RANGE_125_DPS    REG_VAL(BIT(7), BIT(5) | BIT(6))
#define GYRO_RANGE_62_5_DPS   REG_VAL(BIT(5) | BIT(7), BIT(6))
#define GYRO_RANGE_31_25_DPS  REG_VAL(BIT(6) | BIT(7), BIT(5))
#define GYRO_RANGE_15_625_DPS REG_VAL(BIT(5) | BIT(6) | BIT(7), 0)

#define ACCEL_RANGE_16_G REG_VAL(0, BIT(5) | BIT(6) | BIT(7))
#define ACCEL_RANGE_8_G  REG_VAL(BIT(5), BIT(6) | BIT(7))
#define ACCEL_RANGE_4_G  REG_VAL(BIT(6), BIT(5) | BIT(7))
#define ACCEL_RANGE_2_G  REG_VAL(BIT(5) | BIT(6), BIT(7))

#define GYRO_ODR_32000 REG_VAL(BIT(0), BIT(1) | BIT(2) | BIT(3))
#define GYRO_ODR_16000 REG_VAL(BIT(1), BIT(1) | BIT(2) | BIT(3))
#define GYRO_ODR_8000  REG_VAL(BIT(0) | BIT(1), BIT(2) | BIT(3))
#define GYRO_ODR_4000  REG_VAL(BIT(2), BIT(0) | BIT(1) | BIT(3))
#define GYRO_ODR_2000  REG_VAL(BIT(0) | BIT(2), BIT(1) | BIT(3))
#define GYRO_ODR_1000  REG_VAL(BIT(1) | BIT(2), BIT(0) | BIT(3))
#define GYRO_ODR_500   REG_VAL(BIT(0) | BIT(1) | BIT(2) | BIT(3), 0)
#define GYRO_ODR_200   REG_VAL(BIT(0) | BIT(1) | BIT(2), BIT(3))
#define GYRO_ODR_100   REG_VAL(BIT(3), BIT(0) | BIT(1) | BIT(2))
#define GYRO_ODR_50    REG_VAL(BIT(0) | BIT(3), BIT(1) | BIT(2))
#define GYRO_ODR_25    REG_VAL(BIT(1) | BIT(3), BIT(0) | BIT(2))
#define GYRO_ODR_12_5  REG_VAL(BIT(0) | BIT(1) | BIT(3), BIT(2))

#define ACCEL_ODR_32000 REG_VAL(BIT(0), BIT(1) | BIT(2) | BIT(3))
#define ACCEL_ODR_16000 REG_VAL(BIT(1), BIT(1) | BIT(2) | BIT(3))
#define ACCEL_ODR_8000  REG_VAL(BIT(0) | BIT(1), BIT(2) | BIT(3))
#define ACCEL_ODR_4000  REG_VAL(BIT(2), BIT(0) | BIT(1) | BIT(3))
#define ACCEL_ODR_2000  REG_VAL(BIT(0) | BIT(2), BIT(1) | BIT(3))
#define ACCEL_ODR_1000  REG_VAL(BIT(1) | BIT(2), BIT(0) | BIT(3))
#define ACCEL_ODR_500   REG_VAL(BIT(0) | BIT(1) | BIT(2) | BIT(3), 0)
#define ACCEL_ODR_200   REG_VAL(BIT(0) | BIT(1) | BIT(2), BIT(3))
#define ACCEL_ODR_100   REG_VAL(BIT(3), BIT(0) | BIT(1) | BIT(2))
#define ACCEL_ODR_50    REG_VAL(BIT(0) | BIT(3), BIT(1) | BIT(2))
#define ACCEL_ODR_25    REG_VAL(BIT(1) | BIT(3), BIT(0) | BIT(2))
#define ACCEL_ODR_12_5  REG_VAL(BIT(0) | BIT(1) | BIT(3), BIT(2))

#define M_PI_F  3.1415926f
#define M_ONE_G 9.80665f

#define GYRO_CONFIG                                   \
    {                                                 \
        1000,                   /* 1K sample rate */  \
            500,                /* 500Hz bandwidth */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */    \
    }

#define ACCEL_CONFIG                               \
    {                                              \
        1000,                /* 1K sample rate */  \
            500,             /* 500Hz bandwidth */ \
            ACCEL_RANGE_16G, /* +-16g */           \
    }

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static rt_device_t spi_dev;
static float gyro_range_scale;
static float accel_range_scale;

/* Re-implement this function to define customized rotation */
RT_WEAK void icm42688_rotate_to_frd(float* data, uint32_t dev_id)
{
    /* do nothing */
    /* do nothing */
    (void)data;
    (void)dev_id;
}

static rt_err_t __write_checked_reg(rt_device_t spi_device, rt_uint8_t reg, rt_uint8_t val)
{
    rt_uint8_t r_val;

    RT_TRY(spi_write_reg8(spi_device, reg, val));
    RT_TRY(spi_read_reg8(spi_device, reg, &r_val));

    return (r_val == val) ? RT_EOK : RT_ERROR;
}

static rt_err_t __modify_reg(rt_device_t spi_device, rt_uint8_t reg, reg_val_t reg_val)
{
    uint8_t value;

    RT_TRY(spi_read_reg8(spi_device, reg, &value));

    value &= ~reg_val.clearbits;
    value |= reg_val.setbits;

    RT_TRY(__write_checked_reg(spi_device, reg, value));

    return RT_EOK;
}

static rt_err_t gyro_set_range(uint32_t max_dps)
{
    reg_val_t reg_val;
    float lsb_per_dps;

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 23) {
        reg_val = GYRO_RANGE_15_625_DPS;
        lsb_per_dps = 32768.0f / 15.625f;
    } else if (max_dps <= 47) {
        reg_val = GYRO_RANGE_31_25_DPS;
        lsb_per_dps = 32768.0f / 31.25f;
    } else if (max_dps <= 94) {
        reg_val = GYRO_RANGE_62_5_DPS;
        lsb_per_dps = 32768.0f / 62.5f;
    } else if (max_dps <= 188) {
        reg_val = GYRO_RANGE_125_DPS;
        lsb_per_dps = 32768.0f / 125.0f;
    } else if (max_dps <= 375) {
        reg_val = GYRO_RANGE_250_DPS;
        lsb_per_dps = 32768.0f / 250.0f;
    } else if (max_dps <= 750) {
        reg_val = GYRO_RANGE_500_DPS;
        lsb_per_dps = 32768.0f / 500.0f;
    } else if (max_dps <= 1500) {
        reg_val = GYRO_RANGE_1000_DPS;
        lsb_per_dps = 32768.0f / 1000.0f;
    } else if (max_dps <= 2000) {
        reg_val = GYRO_RANGE_2000_DPS;
        lsb_per_dps = 32768.0f / 2000.0f;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(spi_dev, REG_GYRO_CONFIG0, reg_val));

    gyro_range_scale = M_PI_F / 180.0f / lsb_per_dps;

    return RT_EOK;
}

static rt_err_t gyro_set_sample_rate(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= 19) {
        reg_val = GYRO_ODR_12_5;
    } else if (frequency_hz <= 38) {
        reg_val = GYRO_ODR_25;
    } else if (frequency_hz <= 75) {
        reg_val = GYRO_ODR_50;
    } else if (frequency_hz <= 150) {
        reg_val = GYRO_ODR_100;
    } else if (frequency_hz <= 350) {
        reg_val = GYRO_ODR_200;
    } else if (frequency_hz <= 750) {
        reg_val = GYRO_ODR_500;
    } else if (frequency_hz <= 1500) {
        reg_val = GYRO_ODR_1000;
    } else if (frequency_hz <= 3000) {
        reg_val = GYRO_ODR_2000;
    } else if (frequency_hz <= 6000) {
        reg_val = GYRO_ODR_4000;
    } else if (frequency_hz <= 12000) {
        reg_val = GYRO_ODR_8000;
    } else if (frequency_hz <= 24000) {
        reg_val = GYRO_ODR_16000;
    } else if (frequency_hz <= 32000) {
        reg_val = GYRO_ODR_32000;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(spi_dev, REG_GYRO_CONFIG0, reg_val));

    return RT_EOK;
}

static rt_err_t gyro_set_dlpf_filter(uint16_t frequency_hz)
{
    /* do not enable lpf */
    return RT_EOK;
}

static rt_err_t accel_set_range(uint32_t max_g)
{
    reg_val_t reg_val;
    float lsb_per_g;

    if (max_g == 0) {
        max_g = 16;
    }

    if (max_g <= 3) {
        reg_val = ACCEL_RANGE_2_G;
        lsb_per_g = 32768.0f / 2.0f;
    } else if (max_g <= 6) {
        reg_val = ACCEL_RANGE_4_G;
        lsb_per_g = 32768.0f / 4.0f;
    } else if (max_g <= 12) {
        reg_val = ACCEL_RANGE_8_G;
        lsb_per_g = 32768.0f / 8.0f;
    } else if (max_g <= 16) {
        reg_val = ACCEL_RANGE_16_G;
        lsb_per_g = 32768.0f / 16.0f;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(spi_dev, REG_ACCEL_CONFIG0, reg_val));

    accel_range_scale = (M_ONE_G / lsb_per_g);

    return RT_EOK;
}

static rt_err_t accel_set_sample_rate(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz <= 19) {
        reg_val = ACCEL_ODR_12_5;
    } else if (frequency_hz <= 38) {
        reg_val = ACCEL_ODR_25;
    } else if (frequency_hz <= 75) {
        reg_val = ACCEL_ODR_50;
    } else if (frequency_hz <= 150) {
        reg_val = ACCEL_ODR_100;
    } else if (frequency_hz <= 350) {
        reg_val = ACCEL_ODR_200;
    } else if (frequency_hz <= 750) {
        reg_val = ACCEL_ODR_1000;
    } else if (frequency_hz <= 1500) {
        reg_val = ACCEL_ODR_2000;
    } else if (frequency_hz <= 3000) {
        reg_val = ACCEL_ODR_4000;
    } else if (frequency_hz <= 6000) {
        reg_val = ACCEL_ODR_8000;
    } else if (frequency_hz <= 12000) {
        reg_val = ACCEL_ODR_16000;
    } else if (frequency_hz <= 24000) {
        reg_val = ACCEL_ODR_32000;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(spi_dev, REG_ACCEL_CONFIG0, reg_val));

    return RT_EOK;
}

static rt_err_t accel_set_dlpf_filter(uint16_t frequency_hz)
{
    /* do not enable lpf */
    return RT_EOK;
}

static rt_err_t low_level_init(void)
{
    uint8_t dev_id;

    /* init spi bus */
    RT_TRY(rt_device_open(spi_dev, RT_DEVICE_OFLAG_RDWR));

    /* chip probe */
    RT_TRY(spi_read_reg8(spi_dev, REG_WHO_AM_I, &dev_id));
    if (dev_id != DEVICE_ID) {
        DRV_DBG("ICM42688P wrong device id:0x%x\n", dev_id);
        return RT_ENOSYS;
    }

    /* select bank0 */
    RT_TRY(spi_write_reg8(spi_dev, REG_REG_BANK_SEL, 0));
    /* temperature sensor enabled (note that if it's disabled there will be a bias for gyro), 
       gyro and accel work in low noise (LN) mode */
    RT_TRY(spi_write_reg8(spi_dev, REG_PWR_MGMT0, 0x0F));
    /* gyro need 30ms startup time */
    systime_mdelay(30);
    /* gyro config */
    RT_TRY(gyro_set_range(2000));
    RT_TRY(gyro_set_sample_rate(1000));
    /* accel config */
    RT_TRY(accel_set_range(16));
    RT_TRY(accel_set_sample_rate(1000));
    /* 0 BW (ODR/2) for gyro and accel */
    RT_TRY(spi_write_reg8(spi_dev, REG_GYRO_ACCEL_CONFIG0, 0x00));

    /* select bank1 */
    RT_TRY(spi_write_reg8(spi_dev, REG_REG_BANK_SEL, 1));
    /* disable gyro internal anti-aliasing filter and notch filter */
    RT_TRY(spi_write_reg8(spi_dev, REG_GYRO_CONFIG_STATIC2, 0x03));

    /* select bank2 */
    RT_TRY(spi_write_reg8(spi_dev, REG_REG_BANK_SEL, 2));
    /* disable accel internal anti-aliasing filter */
    RT_TRY(spi_write_reg8(spi_dev, REG_ACCEL_CONFIG_STATIC2, 0x01));

    /* select bank0 */
    RT_TRY(spi_write_reg8(spi_dev, REG_REG_BANK_SEL, 0));

    return RT_EOK;
}

static rt_err_t gyro_read_raw(int16_t gyro[3])
{
    uint8_t raw[6];

    RT_TRY(spi_read_multi_reg8(spi_dev, REG_GYRO_DATA_X1, raw, 6));

    gyro[0] = int16_t_from_bytes(&raw[0]);
    gyro[1] = int16_t_from_bytes(&raw[2]);
    gyro[2] = int16_t_from_bytes(&raw[4]);

    return RT_EOK;
}

static rt_err_t gyro_read_rad_s(float gyr[3])
{
    int16_t gyr_raw[3];

    RT_TRY(gyro_read_raw(gyr_raw));

    gyr[0] = gyro_range_scale * gyr_raw[0];
    gyr[1] = gyro_range_scale * gyr_raw[1];
    gyr[2] = gyro_range_scale * gyr_raw[2];

    return RT_EOK;
}

static rt_err_t accel_read_raw(int16_t accel[3])
{
    uint8_t raw[6];

    RT_TRY(spi_read_multi_reg8(spi_dev, REG_ACCEL_DATA_X1, raw, 6));

    accel[0] = int16_t_from_bytes(&raw[0]);
    accel[1] = int16_t_from_bytes(&raw[2]);
    accel[2] = int16_t_from_bytes(&raw[4]);

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];
    rt_err_t res;
    res = accel_read_raw(acc_raw);

    acc[0] = accel_range_scale * acc_raw[0];
    acc[1] = accel_range_scale * acc_raw[1];
    acc[2] = accel_range_scale * acc_raw[2];

    return res;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    RT_ASSERT(cfg != RT_NULL);

    RT_TRY(gyro_set_range(cfg->gyro_range_dps));

    RT_TRY(gyro_set_sample_rate(cfg->sample_rate_hz));

    RT_TRY(gyro_set_dlpf_filter(cfg->dlpf_freq_hz));

    gyro->config = *cfg;

    return RT_EOK;
}

static rt_err_t gyro_control(gyro_dev_t gyro, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t gyro_read(gyro_dev_t gyro, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == NULL) {
        return 0;
    }

    if (gyro_read_rad_s(((float*)data)) != RT_EOK) {
        return 0;
    }

    icm42688_rotate_to_frd((float*)data, (uint32_t)gyro->parent.user_data);

    return size;
}

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    RT_ASSERT(cfg != NULL);

    RT_TRY(accel_set_range(cfg->acc_range_g));

    RT_TRY(accel_set_sample_rate(cfg->sample_rate_hz));

    RT_TRY(accel_set_dlpf_filter(cfg->dlpf_freq_hz));

    accel->config = *cfg;

    return RT_EOK;
}

static rt_err_t accel_control(accel_dev_t accel, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_size_t accel_read(accel_dev_t accel, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == NULL) {
        return 0;
    }

    if (accel_read_m_s2(((float*)data)) != RT_EOK) {
        return 0;
    }

    icm42688_rotate_to_frd((float*)data, (uint32_t)accel->parent.user_data);

    return size;
}

const static struct gyro_ops __gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

const static struct accel_ops __accel_ops = {
    accel_config,
    accel_control,
    accel_read,
};

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

rt_err_t drv_icm42688_init(const char* spi_dev_name, const char* gyro_dev_name, const char* accel_dev_name, uint32_t dev_id)
{
    spi_dev = rt_device_find(spi_dev_name);
    RT_ASSERT(spi_dev != NULL);
    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;
        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;

        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }
    /* device low-level init */
    RT_TRY(low_level_init());

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_dev_name, RT_DEVICE_FLAG_RDWR, (void*)dev_id));
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_dev_name, RT_DEVICE_FLAG_RDWR, (void*)dev_id));

    return RT_EOK;
}

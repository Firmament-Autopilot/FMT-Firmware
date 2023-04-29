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
#include "driver/imu/icm20689.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/spi/spi.h"
#include "module/math/conversion.h"

#define DRV_DBG(...) printf(__VA_ARGS__)

#define DIR_READ       0x80
#define DIR_WRITE      0x00
#define ICM20689_ONE_G 9.80665f
#define M_PI_F         3.1415926f

#define BIT(_idx) (1 << _idx)
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

#define SELF_TEST_X_GYRO  0x00
#define SELF_TEST_Y_GYRO  0x01
#define SELF_TEST_Z_GYRO  0x02
#define SELF_TEST_X_ACCEL 0x0D
#define SELF_TEST_Y_ACCEL 0x0E
#define SELF_TEST_Z_ACCEL 0x0F
#define XG_OFFS_USRH      0x13
#define XG_OFFS_USRL      0x14
#define YG_OFFS_USRH      0x15
#define YG_OFFS_USRL      0x16
#define ZG_OFFS_USRH      0x17
#define ZG_OFFS_USRL      0x18
#define SMPLRT_DIV        0x19
#define MPUREG_CONFIG     0x1A
#define GYRO_CONFIG       0x1B
#define ACCEL_CONFIG      0x1C
#define ACCEL_CONFIG_2    0x1D
#define LOW_POWER_MODE    0x1E
#define MPU_FIFO_EN_REG   0X23
#define MPU_INTBP_CFG_REG 0X37
#define MPU_INT_EN_REG    0X38
#define MPU_INT_STA_REG   0X3A
#define ACCEL_XOUT_H      0x3B
#define ACCEL_XOUT_L      0x3C
#define ACCEL_YOUT_H      0x3D
#define ACCEL_YOUT_L      0x3E
#define ACCEL_ZOUT_H      0x3F
#define ACCEL_ZOUT_L      0x40
#define TEMP_OUT_H        0x41
#define TEMP_OUT_L        0x42
#define GYRO_XOUT_H       0x43
#define GYRO_XOUT_L       0x44
#define GYRO_YOUT_H       0x45
#define GYRO_YOUT_L       0x46
#define GYRO_ZOUT_H       0x47
#define GYRO_ZOUT_L       0x48
#define USER_CONTROL      0x6A
#define PWR_MGMT_1        0x6B
#define PWR_MGMT_2        0x6C
#define WHO_AM_I          0x75

#define GYRO_RANGE_2000_DPS REG_VAL(BIT(3) | BIT(4), 0)
#define GYRO_RANGE_1000_DPS REG_VAL(BIT(4), BIT(3))
#define GYRO_RANGE_500_DPS  REG_VAL(BIT(3), BIT(4))
#define GYRO_RANGE_250_DPS  REG_VAL(0, BIT(3) | BIT(4))

#define GYRO_BW_5    REG_VAL(BIT(1) | BIT(2), BIT(0))
#define GYRO_BW_10   REG_VAL(BIT(0) | BIT(2), BIT(1))
#define GYRO_BW_20   REG_VAL(BIT(2), BIT(0) | BIT(1))
#define GYRO_BW_41   REG_VAL(BIT(0) | BIT(1), BIT(2))
#define GYRO_BW_92   REG_VAL(BIT(1), BIT(0) | BIT(2))
#define GYRO_BW_176  REG_VAL(BIT(0), BIT(1) | BIT(2))
#define GYRO_BW_250  REG_VAL(0, BIT(0) | BIT(1) | BIT(2))
#define GYRO_BW_3281 REG_VAL(BIT(0) | BIT(1) | BIT(2), 0)

#define ACCEL_RANGE_2_G  REG_VAL(0, BIT(3) | BIT(4))
#define ACCEL_RANGE_4_G  REG_VAL(BIT(3), BIT(4))
#define ACCEL_RANGE_8_G  REG_VAL(BIT(4), BIT(3))
#define ACCEL_RANGE_16_G REG_VAL(BIT(3) | BIT(4), 0)

#define ACCEL_BW_5_1   REG_VAL(BIT(1) | BIT(2), BIT(0))
#define ACCEL_BW_10_2  REG_VAL(BIT(0) | BIT(2), BIT(1))
#define ACCEL_BW_21_2  REG_VAL(BIT(2), BIT(0) | BIT(1))
#define ACCEL_BW_44_8  REG_VAL(BIT(0) | BIT(1), BIT(2))
#define ACCEL_BW_99    REG_VAL(BIT(1), BIT(0) | BIT(2))
#define ACCEL_BW_218_1 REG_VAL(BIT(0), BIT(1) | BIT(2))
#define ACCEL_BW_420   REG_VAL(BIT(0) | BIT(1) | BIT(2), 0)

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

static float gyro_range_scale;
static float accel_range_scale;
static rt_device_t imu_spi_dev;

/* Re-implement this function to define customized rotation */
RT_WEAK void icm20689_rotate_to_frd(float* val)
{
    /* do nothing */
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

static rt_err_t gyro_set_dlpf_filter(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz < 10) {
        reg_val = GYRO_BW_5;
    } else if (frequency_hz < 20) {
        reg_val = GYRO_BW_10;
    } else if (frequency_hz < 41) {
        reg_val = GYRO_BW_20;
    } else if (frequency_hz < 92) {
        reg_val = GYRO_BW_41;
    } else if (frequency_hz < 176) {
        reg_val = GYRO_BW_92;
    } else if (frequency_hz < 250) {
        reg_val = GYRO_BW_176;
    } else if (frequency_hz < 3281) {
        reg_val = GYRO_BW_250;
    } else {
        reg_val = GYRO_BW_3281;
    }

    RT_TRY(__modify_reg(imu_spi_dev, MPUREG_CONFIG, reg_val));

    return RT_EOK;
}

static rt_err_t gyro_set_range(uint32_t max_dps)
{
    reg_val_t reg_val;
    float lsb_per_dps;

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 250) {
        reg_val = GYRO_RANGE_250_DPS;
        lsb_per_dps = 131;
    } else if (max_dps <= 500) {
        reg_val = GYRO_RANGE_500_DPS;
        lsb_per_dps = 65.5;
    } else if (max_dps <= 1000) {
        reg_val = GYRO_RANGE_1000_DPS;
        lsb_per_dps = 32.8;
    } else if (max_dps <= 2000) {
        reg_val = GYRO_RANGE_2000_DPS;
        lsb_per_dps = 16.4;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(imu_spi_dev, GYRO_CONFIG, reg_val));

    gyro_range_scale = (M_PI_F / (180.0f * lsb_per_dps));

    return RT_EOK;
}

static rt_err_t accel_set_dlpf_filter(uint32_t frequency_hz)
{
    reg_val_t reg_val;

    if (frequency_hz < 8) {
        reg_val = ACCEL_BW_5_1;
    } else if (frequency_hz < 16) {
        reg_val = ACCEL_BW_10_2;
    } else if (frequency_hz < 38) {
        reg_val = ACCEL_BW_21_2;
    } else if (frequency_hz < 72) {
        reg_val = ACCEL_BW_44_8;
    } else if (frequency_hz < 159) {
        reg_val = ACCEL_BW_99;
    } else if (frequency_hz < 319) {
        reg_val = ACCEL_BW_218_1;
    } else {
        reg_val = ACCEL_BW_420;
    }

    RT_TRY(__modify_reg(imu_spi_dev, ACCEL_CONFIG_2, reg_val));

    return RT_EOK;
}

static rt_err_t accel_set_range(uint32_t max_g)
{
    reg_val_t reg_val;
    float lsb_per_g;

    if (max_g == 0) {
        max_g = 16;
    }

    if (max_g <= 2) {
        reg_val = ACCEL_RANGE_2_G;
        lsb_per_g = 16384;
    } else if (max_g <= 4) {
        reg_val = ACCEL_RANGE_4_G;
        lsb_per_g = 8192;
    } else if (max_g <= 8) {
        reg_val = ACCEL_RANGE_8_G;
        lsb_per_g = 4096;
    } else if (max_g <= 16) {
        reg_val = ACCEL_RANGE_16_G;
        lsb_per_g = 2048;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(__modify_reg(imu_spi_dev, ACCEL_CONFIG, reg_val));

    accel_range_scale = (ICM20689_ONE_G / lsb_per_g);

    return RT_EOK;
}

static rt_err_t imu_init(void)
{
    uint8_t chip_id;

    /* open spi device */
    RT_TRY(rt_device_open(imu_spi_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(spi_read_reg8(imu_spi_dev, WHO_AM_I, &chip_id));
    if (chip_id != 0x98) {
        DRV_DBG("ICM20689 unmatched chip id:0x%x\n", chip_id);
        return FMT_ERROR;
    }

    /* soft reset */
    RT_TRY(spi_write_reg8(imu_spi_dev, PWR_MGMT_1, BIT(7)));
    systime_udelay(5000);

    /* wakeup and set clock */
    RT_TRY(__modify_reg(imu_spi_dev, PWR_MGMT_1, REG_VAL(BIT(0), BIT(6)))); /* CLKSEL[2:0] set to 001 to achieve full gyroscope performance. */
    systime_udelay(1000);

    RT_TRY(__write_checked_reg(imu_spi_dev, MPUREG_CONFIG, 0x00));                             /* Gyro 8K rate, 250Hz BW */
    RT_TRY(__modify_reg(imu_spi_dev, GYRO_CONFIG, REG_VAL(BIT(3) | BIT(4), BIT(0) | BIT(1)))); /* 2000dps, FCHOICE_B[0,0] */
    RT_TRY(__modify_reg(imu_spi_dev, ACCEL_CONFIG, REG_VAL(BIT(3) | BIT(4), 0)));              /* 16g */
    RT_TRY(__modify_reg(imu_spi_dev, ACCEL_CONFIG_2, REG_VAL(0, 0x0F)));                       /* Accel 1K rate, 218Hz BW */
    RT_TRY(__write_checked_reg(imu_spi_dev, MPU_FIFO_EN_REG, 0x00));                           /* disable fifo */
    RT_TRY(__write_checked_reg(imu_spi_dev, MPU_INT_EN_REG, 0x00));                            /* disable interrupts */
    RT_TRY(__modify_reg(imu_spi_dev, USER_CONTROL, REG_VAL(BIT(4), BIT(6))));                  /* SPI only and disable fifo */

    return RT_EOK;
}

static rt_err_t gyro_read_raw(int16_t gyr[3])
{
    uint16_t raw[3];

    RT_TRY(spi_read_multi_reg8(imu_spi_dev, GYRO_XOUT_H, (uint8_t*)raw, 6));
    // big-endian to little-endian
    gyr[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    gyr[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    gyr[2] = int16_t_from_bytes((uint8_t*)&raw[2]);

    return RT_EOK;
}

static rt_err_t gyro_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];

    RT_TRY(gyro_read_raw(gyr_raw));

    gyr[0] = gyro_range_scale * gyr_raw[0];
    gyr[1] = gyro_range_scale * gyr_raw[1];
    gyr[2] = gyro_range_scale * gyr_raw[2];
    // change to NED coordinate
    icm20689_rotate_to_frd(gyr);

    return RT_EOK;
}

static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    RT_ASSERT(cfg != NULL);

    RT_TRY(gyro_set_range(cfg->gyro_range_dps));

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

    if (gyro_read_rad(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

const static struct gyro_ops _gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

static rt_err_t accel_read_raw(int16_t acc[3])
{
    int16_t raw[3];

    RT_TRY(spi_read_multi_reg8(imu_spi_dev, ACCEL_XOUT_H, (rt_uint8_t*)raw, 6));
    // big-endian to little-endian
    acc[0] = int16_t_from_bytes((uint8_t*)&raw[0]);
    acc[1] = int16_t_from_bytes((uint8_t*)&raw[1]);
    acc[2] = int16_t_from_bytes((uint8_t*)&raw[2]);

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];

    RT_TRY(accel_read_raw(acc_raw));

    acc[0] = accel_range_scale * acc_raw[0];
    acc[1] = accel_range_scale * acc_raw[1];
    acc[2] = accel_range_scale * acc_raw[2];
    // change to NED coordinate
    icm20689_rotate_to_frd(acc);

    return RT_EOK;
}

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    RT_ASSERT(cfg != NULL);

    RT_TRY(accel_set_range(cfg->acc_range_g));

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

    return size;
}

const static struct accel_ops _accel_ops = {
    accel_config,
    accel_control,
    accel_read,
};

#define GYRO_CONFIGURE                                \
    {                                                 \
        1000,                   /* 1K sample rate */  \
            92,                 /* 256Hz bandwidth */ \
            GYRO_RANGE_2000DPS, /* +-2000 deg/s */    \
    }

#define ACCEL_CONFIGURE                           \
    {                                             \
        1000,                /* 1K sample rate */ \
            99,              /* 99Hz bandwidth */ \
            ACCEL_RANGE_16G, /* +-16g */          \
    }

static struct gyro_device gyro_dev = {
    .ops = &_gyro_ops,
    .config = GYRO_CONFIGURE,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct accel_device accel_dev = {
    .ops = &_accel_ops,
    .config = ACCEL_CONFIGURE,
    .bus_type = GYRO_SPI_BUS_TYPE
};

rt_err_t drv_icm20689_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    imu_spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(imu_spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = SPI1_SPEED_HZ;

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)imu_spi_dev;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* driver low-level init */
    RT_TRY(imu_init());

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

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
#include "driver/imu/icm20649.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"
#include "hal/mag/mag.h"
#include "hal/spi/spi.h"
#include "module/math/conversion.h"
#include "module/math/rotation.h"
#include "module/workqueue/workqueue_manager.h"

/* Typedefs */
typedef enum {
    ub_0 = 0 << 4,
    ub_1 = 1 << 4,
    ub_2 = 2 << 4,
    ub_3 = 3 << 4
} userbank;

typedef enum {
    _500dps,
    _1000dps,
    _2000dps,
    _4000dps,
} gyro_full_scale;

typedef enum {
    _4g,
    _8g,
    _16g,
    _30g,
} accel_full_scale;

typedef struct
{
    float x;
    float y;
    float z;
} axises;

/* ICM-20948 Registers */
#define icm20649_ID                0xE1
#define REG_BANK_SEL               0x7F

// USER BANK 0
#define B0_WHO_AM_I                0x00
#define B0_USER_CTRL               0x03
#define B0_LP_CONFIG               0x05
#define B0_PWR_MGMT_1              0x06
#define B0_PWR_MGMT_2              0x07
#define B0_INT_PIN_CFG             0x0F
#define B0_INT_ENABLE              0x10
#define B0_INT_ENABLE_1            0x11
#define B0_INT_ENABLE_2            0x12
#define B0_INT_ENABLE_3            0x13
#define B0_I2C_MST_STATUS          0x17
#define B0_INT_STATUS              0x19
#define B0_INT_STATUS_1            0x1A
#define B0_INT_STATUS_2            0x1B
#define B0_INT_STATUS_3            0x1C
#define B0_DELAY_TIMEH             0x28
#define B0_DELAY_TIMEL             0x29
#define B0_ACCEL_XOUT_H            0x2D
#define B0_ACCEL_XOUT_L            0x2E
#define B0_ACCEL_YOUT_H            0x2F
#define B0_ACCEL_YOUT_L            0x30
#define B0_ACCEL_ZOUT_H            0x31
#define B0_ACCEL_ZOUT_L            0x32
#define B0_GYRO_XOUT_H             0x33
#define B0_GYRO_XOUT_L             0x34
#define B0_GYRO_YOUT_H             0x35
#define B0_GYRO_YOUT_L             0x36
#define B0_GYRO_ZOUT_H             0x37
#define B0_GYRO_ZOUT_L             0x38
#define B0_TEMP_OUT_H              0x39
#define B0_TEMP_OUT_L              0x3A
#define B0_EXT_SLV_SENS_DATA_00    0x3B
#define B0_EXT_SLV_SENS_DATA_01    0x3C
#define B0_EXT_SLV_SENS_DATA_02    0x3D
#define B0_EXT_SLV_SENS_DATA_03    0x3E
#define B0_EXT_SLV_SENS_DATA_04    0x3F
#define B0_EXT_SLV_SENS_DATA_05    0x40
#define B0_EXT_SLV_SENS_DATA_06    0x41
#define B0_EXT_SLV_SENS_DATA_07    0x42
#define B0_EXT_SLV_SENS_DATA_08    0x43
#define B0_EXT_SLV_SENS_DATA_09    0x44
#define B0_EXT_SLV_SENS_DATA_10    0x45
#define B0_EXT_SLV_SENS_DATA_11    0x46
#define B0_EXT_SLV_SENS_DATA_12    0x47
#define B0_EXT_SLV_SENS_DATA_13    0x48
#define B0_EXT_SLV_SENS_DATA_14    0x49
#define B0_EXT_SLV_SENS_DATA_15    0x4A
#define B0_EXT_SLV_SENS_DATA_16    0x4B
#define B0_EXT_SLV_SENS_DATA_17    0x4C
#define B0_EXT_SLV_SENS_DATA_18    0x4D
#define B0_EXT_SLV_SENS_DATA_19    0x4E
#define B0_EXT_SLV_SENS_DATA_20    0x4F
#define B0_EXT_SLV_SENS_DATA_21    0x50
#define B0_EXT_SLV_SENS_DATA_22    0x51
#define B0_EXT_SLV_SENS_DATA_23    0x52
#define B0_FIFO_EN_1               0x66
#define B0_FIFO_EN_2               0x67
#define B0_FIFO_RST                0x68
#define B0_FIFO_MODE               0x69
#define B0_FIFO_COUNTH             0X70
#define B0_FIFO_COUNTL             0X71
#define B0_FIFO_R_W                0x72
#define B0_DATA_RDY_STATUS         0x74
#define B0_FIFO_CFG                0x76
// USER BANK 1
#define B1_SELF_TEST_X_GYRO        0x02
#define B1_SELF_TEST_Y_GYRO        0x03
#define B1_SELF_TEST_Z_GYRO        0x04
#define B1_SELF_TEST_X_ACCEL       0x0E
#define B1_SELF_TEST_Y_ACCEL       0x0F
#define B1_SELF_TEST_Z_ACCEL       0x10
#define B1_XA_OFFS_H               0x14
#define B1_XA_OFFS_L               0x15
#define B1_YA_OFFS_H               0x17
#define B1_YA_OFFS_L               0x18
#define B1_ZA_OFFS_H               0x1A
#define B1_ZA_OFFS_L               0x1B
#define B1_TIMEBASE_CORRECTION_PLL 0x28
// USER BANK 2
#define B2_GYRO_SMPLRT_DIV         0x00
#define B2_GYRO_CONFIG_1           0x01
#define B2_GYRO_CONFIG_2           0x02
#define B2_XG_OFFS_USRH            0x03
#define B2_XG_OFFS_USRL            0x04
#define B2_YG_OFFS_USRH            0x05
#define B2_YG_OFFS_USRL            0x06
#define B2_ZG_OFFS_USRH            0x07
#define B2_ZG_OFFS_USRL            0x08
#define B2_ODR_ALIGN_EN            0x09
#define B2_ACCEL_SMPLRT_DIV_1      0x10
#define B2_ACCEL_SMPLRT_DIV_2      0x11
#define B2_ACCEL_INTEL_CTRL        0x12
#define B2_ACCEL_WOM_THR           0x13
#define B2_ACCEL_CONFIG            0x14
#define B2_ACCEL_CONFIG_2          0x15
#define B2_FSYNC_CONFIG            0x52
#define B2_TEMP_CONFIG             0x53
#define B2_MOD_CTRL_USR            0X54
// USER BANK 3
#define B3_I2C_MST_ODR_CONFIG      0x00
#define B3_I2C_MST_CTRL            0x01
#define B3_I2C_MST_DELAY_CTRL      0x02
#define B3_I2C_SLV0_ADDR           0x03
#define B3_I2C_SLV0_REG            0x04
#define B3_I2C_SLV0_CTRL           0x05
#define B3_I2C_SLV0_DO             0x06
#define B3_I2C_SLV1_ADDR           0x07
#define B3_I2C_SLV1_REG            0x08
#define B3_I2C_SLV1_CTRL           0x09
#define B3_I2C_SLV1_DO             0x0A
#define B3_I2C_SLV2_ADDR           0x0B
#define B3_I2C_SLV2_REG            0x0C
#define B3_I2C_SLV2_CTRL           0x0D
#define B3_I2C_SLV2_DO             0x0E
#define B3_I2C_SLV3_ADDR           0x0F
#define B3_I2C_SLV3_REG            0x10
#define B3_I2C_SLV3_CTRL           0x11
#define B3_I2C_SLV3_DO             0x12
#define B3_I2C_SLV4_ADDR           0x13
#define B3_I2C_SLV4_REG            0x14
#define B3_I2C_SLV4_CTRL           0x15
#define B3_I2C_SLV4_DO             0x16
#define B3_I2C_SLV4_DI             0x17

#define M_PI_F                     3.1415926f
#define M_ONE_G                    9.80665f

#define DRV_DBG(...)               printf(__VA_ARGS__)

//////////////////////////////////////////////
//////////////////////////////////////////////
static rt_device_t spi_dev;
static float       gyro_range_scale;
static float       accel_range_scale;

//////////////////////////////////////////////
//////////////////////////////////////////////

RT_WEAK void icm20649_rotate_to_frd(float* data)
{
}


//////////////////////////////////////////////
//////////////////////////////////////////////
rt_inline void select_user_bank(userbank ub)
{
    spi_write_reg8(spi_dev, REG_BANK_SEL, ub);
}

static uint8_t read_single_icm20649_reg(userbank ub, uint8_t reg)
{
    uint8_t reg_val;
    select_user_bank(ub);

    spi_read_reg8(spi_dev, reg, &reg_val);

    return reg_val;
}

static void write_single_icm20649_reg(userbank ub, uint8_t reg, uint8_t val)
{
    select_user_bank(ub);
    spi_write_reg8(spi_dev, reg, val);
}

static void read_multiple_icm20649_reg(userbank ub, uint8_t reg, uint8_t* buffer, uint8_t len)
{
    select_user_bank(ub);
    spi_read_multi_reg8(spi_dev, reg, buffer, len);
}

//////////////////////////////////////////////
//////////////////////////////////////////////
/* Sub Functions */
static rt_err_t icm20649_who_am_i()
{
    uint8_t icm20649_id = read_single_icm20649_reg(ub_0, B0_WHO_AM_I);

    if (icm20649_id == icm20649_ID) {
        DRV_DBG("icm20649 right device id:0x%X\n", icm20649_id);
        return RT_EOK;

    } else {
        DRV_DBG("icm20649 wrong device id:0x%X\n", icm20649_id);
        return RT_ERROR;
    }
}


static void icm20649_device_reset()
{
    write_single_icm20649_reg(ub_0, B0_PWR_MGMT_1, 0x80 | 0x41);
    sys_msleep(100);
}

static void icm20649_wakeup()
{
    uint8_t new_val = read_single_icm20649_reg(ub_0, B0_PWR_MGMT_1);
    new_val &= 0xBF;

    write_single_icm20649_reg(ub_0, B0_PWR_MGMT_1, new_val);
    sys_msleep(100);
}

static void icm20649_sleep()
{
    uint8_t new_val = read_single_icm20649_reg(ub_0, B0_PWR_MGMT_1);
    new_val |= 0x40;

    write_single_icm20649_reg(ub_0, B0_PWR_MGMT_1, new_val);
    sys_msleep(100);
}

static void icm20649_spi_slave_enable()
{
    uint8_t new_val = read_single_icm20649_reg(ub_0, B0_USER_CTRL);
    new_val |= 0x10;

    write_single_icm20649_reg(ub_0, B0_USER_CTRL, new_val);
}

static void icm20649_i2c_master_reset()
{
    uint8_t new_val = read_single_icm20649_reg(ub_0, B0_USER_CTRL);
    new_val |= 0x02;

    write_single_icm20649_reg(ub_0, B0_USER_CTRL, new_val);
}

static void icm20649_i2c_master_enable()
{
    uint8_t new_val = read_single_icm20649_reg(ub_0, B0_USER_CTRL);
    new_val |= 0x20;

    write_single_icm20649_reg(ub_0, B0_USER_CTRL, new_val);
    sys_msleep(100);
}

static void icm20649_i2c_master_clk_frq(uint8_t config)
{
    uint8_t new_val = read_single_icm20649_reg(ub_3, B3_I2C_MST_CTRL);
    new_val |= config;

    write_single_icm20649_reg(ub_3, B3_I2C_MST_CTRL, new_val);
}

static void icm20649_clock_source(uint8_t source)
{
    uint8_t new_val = read_single_icm20649_reg(ub_0, B0_PWR_MGMT_1);
    new_val |= source;

    write_single_icm20649_reg(ub_0, B0_PWR_MGMT_1, new_val);
}

static void icm20649_odr_align_enable()
{
    write_single_icm20649_reg(ub_2, B2_ODR_ALIGN_EN, 0x01);
}

static void icm20649_gyro_low_pass_filter(uint8_t config)
{
    uint8_t new_val = read_single_icm20649_reg(ub_2, B2_GYRO_CONFIG_1);
    new_val |= config << 3;

    write_single_icm20649_reg(ub_2, B2_GYRO_CONFIG_1, new_val);
}

static void icm20649_accel_low_pass_filter(uint8_t config)
{
    uint8_t new_val = read_single_icm20649_reg(ub_2, B2_ACCEL_CONFIG);
    new_val |= config << 3;

    write_single_icm20649_reg(ub_2, B2_GYRO_CONFIG_1, new_val);
}

static void icm20649_gyro_sample_rate_divider(uint8_t divider)
{
    write_single_icm20649_reg(ub_2, B2_GYRO_SMPLRT_DIV, divider);
}

static void icm20649_accel_sample_rate_divider(uint16_t divider)
{
    uint8_t divider_1 = (uint8_t)(divider >> 8);
    uint8_t divider_2 = (uint8_t)(0x0F & divider);

    write_single_icm20649_reg(ub_2, B2_ACCEL_SMPLRT_DIV_1, divider_1);
    write_single_icm20649_reg(ub_2, B2_ACCEL_SMPLRT_DIV_2, divider_2);
}

static void icm20649_gyro_full_scale_select(gyro_full_scale full_scale)
{
    uint8_t new_val = read_single_icm20649_reg(ub_2, B2_GYRO_CONFIG_1);
    float   lsb_per_dps;

    switch (full_scale) {
    case _500dps:
        new_val |= 0x00;
        lsb_per_dps = 32768.0f / 500.0f;
        break;
    case _1000dps:
        new_val |= 0x02;
        lsb_per_dps = 32768.0f / 1000.0f;
        break;
    case _2000dps:
        new_val |= 0x04;
        lsb_per_dps = 32768.0f / 2000.0f;
    case _4000dps:
        new_val |= 0x06;
        lsb_per_dps = 32768.0f / 4000.0f;
        break;
    }

    gyro_range_scale = M_PI_F / 180.0f / lsb_per_dps;

    write_single_icm20649_reg(ub_2, B2_GYRO_CONFIG_1, new_val);
}

static void icm20649_accel_full_scale_select(accel_full_scale full_scale)
{
    uint8_t new_val = read_single_icm20649_reg(ub_2, B2_ACCEL_CONFIG);
    float   lsb_per_g;

    switch (full_scale) {
    case _4g:
        new_val |= 0x00;
        lsb_per_g = 32768.0f / 4.0f;
        break;
    case _8g:
        new_val |= 0x02;
        lsb_per_g = 32768.0f / 8.0f;
        break;
    case _16g:
        new_val |= 0x04;
        lsb_per_g = 32768.0f / 16.0f;
        break;
    case _30g:
        new_val |= 0x06;
        lsb_per_g = 32768.0f / 30.0f;
        break;
    }

    accel_range_scale = (M_ONE_G / lsb_per_g);

    write_single_icm20649_reg(ub_2, B2_ACCEL_CONFIG, new_val);
}

static rt_err_t icm20649_gyro_read(int16_t gyro[3])
{
    uint8_t raw[6];

    read_multiple_icm20649_reg(ub_0, B0_GYRO_XOUT_H, raw, 6);

    gyro[0] = (int16_t)(raw[0] << 8 | raw[1]);
    gyro[1] = (int16_t)(raw[2] << 8 | raw[3]);
    gyro[2] = (int16_t)(raw[4] << 8 | raw[5]);

    return RT_EOK;
}

static rt_err_t icm20649_accel_read(int16_t acc[3])
{
    uint8_t raw[6];

    read_multiple_icm20649_reg(ub_0, B0_ACCEL_XOUT_H, raw, 6);

    acc[0] = (int16_t)(raw[0] << 8 | raw[1]);
    acc[1] = (int16_t)(raw[2] << 8 | raw[3]);
    acc[2] = (int16_t)(raw[4] << 8 | raw[5]);

    return RT_EOK;
}

//////////////////////////////////////////////
//////////////////////////////////////////////
static rt_err_t gyro_config(gyro_dev_t gyro, const struct gyro_configure* cfg)
{
    return RT_EOK;
}

static rt_err_t accel_config(accel_dev_t accel, const struct accel_configure* cfg)
{
    return RT_EOK;
}

static rt_err_t gyro_control(gyro_dev_t gyro, int cmd, void* arg)
{
    return RT_EOK;
}

static rt_err_t accel_control(accel_dev_t accel, int cmd, void* arg)
{
    return RT_EOK;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

static rt_err_t gyro_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];

    RT_TRY(icm20649_gyro_read(gyr_raw));

    gyr[0] = gyro_range_scale * gyr_raw[0];
    gyr[1] = gyro_range_scale * gyr_raw[1];
    gyr[2] = gyro_range_scale * gyr_raw[2];

    // change to NED coordinate
    icm20649_rotate_to_frd(gyr);

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];

    RT_TRY(icm20649_accel_read(acc_raw));

    acc[0] = accel_range_scale * acc_raw[0];
    acc[1] = accel_range_scale * acc_raw[1];
    acc[2] = accel_range_scale * acc_raw[2];

    icm20649_rotate_to_frd(acc);

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

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

static rt_err_t lowlevel_init(void)
{
    /* open spi device */
    RT_TRY(rt_device_open(spi_dev, RT_DEVICE_OFLAG_RDWR));

    // icm20649_init
    RT_TRY(icm20649_who_am_i());

    icm20649_device_reset();
    icm20649_wakeup();

    icm20649_clock_source(1);
    icm20649_odr_align_enable();

    icm20649_spi_slave_enable();

    icm20649_gyro_low_pass_filter(0);
    icm20649_accel_low_pass_filter(0);

    icm20649_gyro_sample_rate_divider(0);
    icm20649_accel_sample_rate_divider(0);

    icm20649_gyro_full_scale_select(_2000dps);
    icm20649_accel_full_scale_select(_16g);

    return RT_EOK;
}

const static struct gyro_ops _gyro_ops = {
    gyro_config,
    gyro_control,
    gyro_read,
};

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
    .ops      = &_gyro_ops,
    .config   = GYRO_CONFIGURE,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct accel_device accel_dev = {
    .ops      = &_accel_ops,
    .config   = ACCEL_CONFIGURE,
    .bus_type = GYRO_SPI_BUS_TYPE
};

rt_err_t drv_icm20649_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name)
{
    spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode       = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz     = 20000000;                   /* Max SPI speed: 7MHz */

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode       = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz     = cfg.max_hz;
        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* driver low-level init */
    RT_TRY(lowlevel_init());

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

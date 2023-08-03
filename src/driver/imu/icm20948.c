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
#include "driver/imu/icm20948.h"
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
    _250dps,
    _500dps,
    _1000dps,
    _2000dps
} gyro_full_scale;

typedef enum {
    _2g,
    _4g,
    _8g,
    _16g
} accel_full_scale;

typedef struct
{
    float x;
    float y;
    float z;
} axises;

typedef enum {
    power_down_mode              = 0,
    single_measurement_mode      = 1,
    continuous_measurement_10hz  = 2,
    continuous_measurement_20hz  = 4,
    continuous_measurement_50hz  = 6,
    continuous_measurement_100hz = 8
} operation_mode;

/* ICM-20948 Registers */
#define ICM20948_ID                0xEA
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
/* AK09916 Registers */
#define AK09916_ID                 0x09
#define MAG_SLAVE_ADDR             0x0C
#define MAG_WIA2                   0x01
#define MAG_ST1                    0x10
#define MAG_HXL                    0x11
#define MAG_HXH                    0x12
#define MAG_HYL                    0x13
#define MAG_HYH                    0x14
#define MAG_HZL                    0x15
#define MAG_HZH                    0x16
#define MAG_ST2                    0x18
#define MAG_CNTL2                  0x31
#define MAG_CNTL3                  0x32
#define MAG_TS1                    0x33
#define MAG_TS2                    0x34

#define AK09916_SCALE_TO_uT        0.15f
#define uT_to_GAUSS                0.01f
#define AK09916_SCALE_TO_GAUSS     (AK09916_SCALE_TO_uT * uT_to_GAUSS)

#define M_PI_F                     3.1415926f
#define M_ONE_G                    9.80665f

#define DRV_DBG(...)               printf(__VA_ARGS__)

//////////////////////////////////////////////
//////////////////////////////////////////////

static rt_thread_t thread;
static struct rt_event event;
static struct rt_timer timer;
#define EVENT_AK09916_UPDATE (1 << 0)

static rt_device_t spi_dev;

static float gyro_range_scale;
static float accel_range_scale;

static userbank current_bank = 0;

//////////////////////////////////////////////
//////////////////////////////////////////////

RT_WEAK void icm20948_rotate_to_frd(float* data)
{
}

RT_WEAK void ak09916_rotate_to_frd(float* data)
{
}


//////////////////////////////////////////////
//////////////////////////////////////////////
static void select_user_bank(userbank ub)
{
    if (ub == current_bank)
        return;

    current_bank = ub;

    spi_write_reg8(spi_dev, REG_BANK_SEL, ub);
}

static uint8_t read_single_icm20948_reg(userbank ub, uint8_t reg)
{
    uint8_t reg_val;
    select_user_bank(ub);

    spi_read_reg8(spi_dev, reg, &reg_val);

    return reg_val;
}

static void write_single_icm20948_reg(userbank ub, uint8_t reg, uint8_t val)
{
    select_user_bank(ub);
    spi_write_reg8(spi_dev, reg, val);
}

static void read_multiple_icm20948_reg(userbank ub, uint8_t reg, uint8_t* buffer, uint8_t len)
{
    select_user_bank(ub);
    spi_read_multi_reg8(spi_dev, reg, buffer, len);
}

static uint8_t read_single_ak09916_reg(uint8_t reg)
{
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x80 | MAG_SLAVE_ADDR);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, reg);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x81);

    return read_single_icm20948_reg(ub_0, B0_EXT_SLV_SENS_DATA_00);
}

static void write_single_ak09916_reg(uint8_t reg, uint8_t val)
{
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x00 | MAG_SLAVE_ADDR);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, reg);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_DO, val);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x81);
}

static void read_multiple_ak09916_reg(uint8_t reg, uint8_t* buffer, uint8_t len)
{
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x80 | MAG_SLAVE_ADDR);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, reg);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x80 | len);

    read_multiple_icm20948_reg(ub_0, B0_EXT_SLV_SENS_DATA_00, buffer, len);
}

//////////////////////////////////////////////
//////////////////////////////////////////////
/* Sub Functions */
static rt_err_t icm20948_who_am_i()
{
    uint8_t icm20948_id = read_single_icm20948_reg(ub_0, B0_WHO_AM_I);

    if (icm20948_id == ICM20948_ID) {
        DRV_DBG("ICM20948 right device id:0x%X\n", icm20948_id);
        return RT_EOK;

    } else {
        DRV_DBG("ICM20948 wrong device id:0x%X\n", icm20948_id);
        return RT_ERROR;
    }
}

static rt_err_t ak09916_who_am_i()
{
    uint8_t ak09916_id;

    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x80 | MAG_SLAVE_ADDR);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, MAG_WIA2);
    write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x81);

    sys_msleep(2);

    ak09916_id = read_single_icm20948_reg(ub_0, B0_EXT_SLV_SENS_DATA_00);

    if (ak09916_id == AK09916_ID) {
        DRV_DBG("AK09916 right device id:0x%X\n", ak09916_id);
        return RT_EOK;
    } else {
        DRV_DBG("AK09916 wrong device id:0x%X\n", ak09916_id);
        return RT_ERROR;
    }
}

static void icm20948_device_reset()
{
    write_single_icm20948_reg(ub_0, B0_PWR_MGMT_1, 0x80 | 0x41);
    sys_msleep(100);
}

static void ak09916_soft_reset()
{
    write_single_ak09916_reg(MAG_CNTL3, 0x01);
    sys_msleep(100);
}

static void icm20948_wakeup()
{
    uint8_t new_val = read_single_icm20948_reg(ub_0, B0_PWR_MGMT_1);
    new_val &= 0xBF;

    write_single_icm20948_reg(ub_0, B0_PWR_MGMT_1, new_val);
    sys_msleep(100);
}

static void icm20948_sleep()
{
    uint8_t new_val = read_single_icm20948_reg(ub_0, B0_PWR_MGMT_1);
    new_val |= 0x40;

    write_single_icm20948_reg(ub_0, B0_PWR_MGMT_1, new_val);
    sys_msleep(100);
}

static void icm20948_spi_slave_enable()
{
    uint8_t new_val = read_single_icm20948_reg(ub_0, B0_USER_CTRL);
    new_val |= 0x10;

    write_single_icm20948_reg(ub_0, B0_USER_CTRL, new_val);
}

static void icm20948_i2c_master_reset()
{
    uint8_t new_val = read_single_icm20948_reg(ub_0, B0_USER_CTRL);
    new_val |= 0x02;

    write_single_icm20948_reg(ub_0, B0_USER_CTRL, new_val);
}

static void icm20948_i2c_master_enable()
{
    uint8_t new_val = read_single_icm20948_reg(ub_0, B0_USER_CTRL);
    new_val |= 0x20;

    write_single_icm20948_reg(ub_0, B0_USER_CTRL, new_val);
    sys_msleep(100);
}

static void icm20948_i2c_master_clk_frq(uint8_t config)
{
    uint8_t new_val = read_single_icm20948_reg(ub_3, B3_I2C_MST_CTRL);
    new_val |= config;

    write_single_icm20948_reg(ub_3, B3_I2C_MST_CTRL, new_val);
}

static void icm20948_clock_source(uint8_t source)
{
    uint8_t new_val = read_single_icm20948_reg(ub_0, B0_PWR_MGMT_1);
    new_val |= source;

    write_single_icm20948_reg(ub_0, B0_PWR_MGMT_1, new_val);
}

static void icm20948_odr_align_enable()
{
    write_single_icm20948_reg(ub_2, B2_ODR_ALIGN_EN, 0x01);
}

static void icm20948_gyro_low_pass_filter(uint8_t config)
{
    uint8_t new_val = read_single_icm20948_reg(ub_2, B2_GYRO_CONFIG_1);
    new_val |= config << 3;

    write_single_icm20948_reg(ub_2, B2_GYRO_CONFIG_1, new_val);
}

static void icm20948_accel_low_pass_filter(uint8_t config)
{
    uint8_t new_val = read_single_icm20948_reg(ub_2, B2_ACCEL_CONFIG);
    new_val |= config << 3;

    write_single_icm20948_reg(ub_2, B2_GYRO_CONFIG_1, new_val);
}

static void icm20948_gyro_sample_rate_divider(uint8_t divider)
{
    write_single_icm20948_reg(ub_2, B2_GYRO_SMPLRT_DIV, divider);
}

static void icm20948_accel_sample_rate_divider(uint16_t divider)
{
    uint8_t divider_1 = (uint8_t)(divider >> 8);
    uint8_t divider_2 = (uint8_t)(0x0F & divider);

    write_single_icm20948_reg(ub_2, B2_ACCEL_SMPLRT_DIV_1, divider_1);
    write_single_icm20948_reg(ub_2, B2_ACCEL_SMPLRT_DIV_2, divider_2);
}

static void ak09916_operation_mode_setting(operation_mode mode)
{
    write_single_ak09916_reg(MAG_CNTL2, mode);
    sys_msleep(100);
}

static void icm20948_gyro_full_scale_select(gyro_full_scale full_scale)
{
    uint8_t new_val = read_single_icm20948_reg(ub_2, B2_GYRO_CONFIG_1);
    float   lsb_per_dps;

    switch (full_scale) {
    case _250dps:
        new_val |= 0x00;
        lsb_per_dps = 131.0;
        break;
    case _500dps:
        new_val |= 0x02;
        lsb_per_dps = 65.5;
        break;
    case _1000dps:
        new_val |= 0x04;
        lsb_per_dps = 32.8;
        break;
    case _2000dps:
        new_val |= 0x06;
        lsb_per_dps = 16.4;
        break;
    }

    gyro_range_scale = M_PI_F / 180.0f / lsb_per_dps;

    write_single_icm20948_reg(ub_2, B2_GYRO_CONFIG_1, new_val);
}

static void icm20948_accel_full_scale_select(accel_full_scale full_scale)
{
    uint8_t new_val = read_single_icm20948_reg(ub_2, B2_ACCEL_CONFIG);
    float   lsb_per_g;

    switch (full_scale) {
    case _2g:
        new_val |= 0x00;
        lsb_per_g = 16384;
        break;
    case _4g:
        new_val |= 0x02;
        lsb_per_g = 8192;
        break;
    case _8g:
        new_val |= 0x04;
        lsb_per_g = 4096;
        break;
    case _16g:
        new_val |= 0x06;
        lsb_per_g = 2048;
        break;
    }

    accel_range_scale = (M_ONE_G / lsb_per_g);

    write_single_icm20948_reg(ub_2, B2_ACCEL_CONFIG, new_val);
}

static rt_err_t icm20948_gyro_read(int16_t gyro[3])
{
    uint8_t raw[6];

    read_multiple_icm20948_reg(ub_0, B0_GYRO_XOUT_H, raw, 6);

    gyro[0] = (int16_t)(raw[0] << 8 | raw[1]);
    gyro[1] = (int16_t)(raw[2] << 8 | raw[3]);
    gyro[2] = (int16_t)(raw[4] << 8 | raw[5]);

    return RT_EOK;
}

static rt_err_t icm20948_accel_read(int16_t acc[3])
{
    uint8_t raw[6];

    read_multiple_icm20948_reg(ub_0, B0_ACCEL_XOUT_H, raw, 6);

    acc[0] = (int16_t)(raw[0] << 8 | raw[1]);
    acc[1] = (int16_t)(raw[2] << 8 | raw[3]);
    acc[2] = (int16_t)(raw[4] << 8 | raw[5]);

    return RT_EOK;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
static void probe_ak09916(int16_t* probe_mag)
{
    static uint8_t  temp[6];
    static uint8_t  step = 0;
    static uint64_t t_start;
    static uint8_t  drdy;

    switch (step) {
    case 0:
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x80 | MAG_SLAVE_ADDR);
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, MAG_ST1);
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x81);

        t_start = systime_now_us();
        step    = 1;
        break;

    case 1:
        if ((systime_now_us() - t_start) > 1000) {
            drdy = read_single_icm20948_reg(ub_0, B0_EXT_SLV_SENS_DATA_00);
            if (drdy & 0x01) {
                t_start = systime_now_us();
                step    = 2;
            }
        }
        break;

    case 2:
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x80 | MAG_SLAVE_ADDR);
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, MAG_HXL);
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x80 | 6);
        t_start = systime_now_us();
        step    = 3;
        break;

    case 3:
        if ((systime_now_us() - t_start) > 1000) {
            read_multiple_icm20948_reg(ub_0, B0_EXT_SLV_SENS_DATA_00, temp, 6);
            probe_mag[0] = (int16_t)(temp[1] << 8 | temp[0]);
            probe_mag[1] = (int16_t)(temp[3] << 8 | temp[2]);
            probe_mag[2] = (int16_t)(temp[5] << 8 | temp[4]);

            step = 4;
        }
        break;

    case 4:
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_ADDR, 0x80 | MAG_SLAVE_ADDR);
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_REG, MAG_ST2);
        write_single_icm20948_reg(ub_3, B3_I2C_SLV0_CTRL, 0x81);

        t_start = systime_now_us();
        step    = 5;

        break;

    case 5:
        if ((systime_now_us() - t_start) > 1000) {
            read_single_icm20948_reg(ub_0, B0_EXT_SLV_SENS_DATA_00);
            step = 0;
        }
        break;

    default:
        step = 0;
        break;
    }
}

static void timer_update(void* parameter)
{
    rt_event_send(&event, EVENT_AK09916_UPDATE);
}

static int16_t mag_raw[3];
static void thread_entry(void* args)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    rt_uint32_t wait_set = EVENT_AK09916_UPDATE;

    while (1) {
        /* wait event occur */
        res = rt_event_recv(&event, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK && (recv_set & EVENT_AK09916_UPDATE)) {
            probe_ak09916(mag_raw);
        }
    }
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
static rt_err_t mag_read_gauss(float mag[3])
{
    // static int16_t raw[3];

    // ak09916_mag_read(raw);

    mag[0] = AK09916_SCALE_TO_GAUSS * mag_raw[0];
    mag[1] = AK09916_SCALE_TO_GAUSS * mag_raw[1];
    mag[2] = AK09916_SCALE_TO_GAUSS * mag_raw[2];

    ak09916_rotate_to_frd(mag);

    return RT_EOK;
}

static rt_err_t gyro_read_rad(float gyr[3])
{
    int16_t gyr_raw[3];

    RT_TRY(icm20948_gyro_read(gyr_raw));

    gyr[0] = gyro_range_scale * gyr_raw[0];
    gyr[1] = gyro_range_scale * gyr_raw[1];
    gyr[2] = gyro_range_scale * gyr_raw[2];

    // change to NED coordinate
    icm20948_rotate_to_frd(gyr);

    return RT_EOK;
}

static rt_err_t accel_read_m_s2(float acc[3])
{
    int16_t acc_raw[3];

    RT_TRY(icm20948_accel_read(acc_raw));

    acc[0] = accel_range_scale * acc_raw[0];
    acc[1] = accel_range_scale * acc_raw[1];
    acc[2] = accel_range_scale * acc_raw[2];

    icm20948_rotate_to_frd(acc);

    return RT_EOK;
}

static rt_size_t mag_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == NULL) {
        return 0;
    }

    if (mag_read_gauss(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
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

    // icm20948_init
    RT_TRY(icm20948_who_am_i());

    icm20948_device_reset();
    icm20948_wakeup();

    /* Auto select best available clock source PLL if ready, else use internal oscillator */
    icm20948_clock_source(1);
    icm20948_odr_align_enable();

    icm20948_spi_slave_enable();

    icm20948_gyro_low_pass_filter(0);
    icm20948_accel_low_pass_filter(0);

    icm20948_gyro_sample_rate_divider(0);
    icm20948_accel_sample_rate_divider(0);

    icm20948_gyro_full_scale_select(_2000dps);
    icm20948_accel_full_scale_select(_16g);

    // ak09916_init
    icm20948_i2c_master_reset();
    icm20948_i2c_master_enable();

    /* Set I2C Master clock frequency */
    /**< I2C_MST_CLK = 345.6 kHz (for 400 kHz Max)          */
    icm20948_i2c_master_clk_frq(7);

    RT_TRY(ak09916_who_am_i());

    ak09916_soft_reset();
    ak09916_operation_mode_setting(continuous_measurement_100hz);

    read_single_ak09916_reg(MAG_ST2);

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

const static struct mag_ops _mag_ops = {
    NULL,
    NULL,
    mag_read,
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

#define AK09916_CONFIG_DEFAULT                              \
    {                                                       \
        100,                /* 100hz sample rate */         \
            50,             /* 16 times average */          \
            MAG_RANGE_16GA, /* xy +-16guess, z +-25guess */ \
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

static struct mag_device mag_dev = {
    .ops      = &_mag_ops,
    .config   = AK09916_CONFIG_DEFAULT,
    .bus_type = MAG_SPI_BUS_TYPE
};

rt_err_t drv_icm20948_init(const char* spi_device_name, const char* gyro_device_name, const char* accel_device_name, const char* mag_device_name)
{
    spi_dev = rt_device_find(spi_device_name);
    RT_ASSERT(spi_dev != NULL);

    /* config spi */
    {
        struct rt_spi_configuration cfg;
        cfg.data_width = 8;
        cfg.mode       = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz     = 8000000;                    /* Max SPI speed: 7MHz */

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode       = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz     = cfg.max_hz;
        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* driver low-level init */
    RT_TRY(lowlevel_init());

    RT_CHECK(rt_event_init(&event, "ak09916", RT_IPC_FLAG_FIFO));

    thread = rt_thread_create("ak09916", thread_entry, RT_NULL, 3 * 1024, 8, 1);
    RT_ASSERT(thread != NULL);
    RT_CHECK(rt_thread_startup(thread));

    /* register timer event */
    rt_timer_init(&timer, "ak09916", timer_update, RT_NULL, TICKS_FROM_MS(2), RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer) != RT_EOK) {
        return FMT_ERROR;
    }

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    /* register mag hal device */
    RT_TRY(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

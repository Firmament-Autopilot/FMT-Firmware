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
#include "module/workqueue/workqueue_manager.h"

#include "module/math/rotation.h"

#define DRV_DBG(...) printf(__VA_ARGS__)

#define WHO_AM_I 0xEA

#define REG_BANK0 0x00U
#define REG_BANK1 0x01U
#define REG_BANK2 0x02U
#define REG_BANK3 0x03U

#define INV2REG(b, r) ((((uint16_t)b) << 8) | (r))
#define GET_BANK(r)   ((r) >> 8)
#define GET_REG(r)    ((r)&0xFFU)

#define BIT_READ_FLAG   0x80
#define BIT_I2C_SLVX_EN 0x80

//Register Map
#define INV2REG_WHO_AM_I            INV2REG(REG_BANK0, 0x00U)
#define INV2REG_USER_CTRL           INV2REG(REG_BANK0, 0x03U)
#define BIT_USER_CTRL_I2C_MST_RESET 0x02 // reset I2C Master (only applicable if I2C_MST_EN bit is set)
#define BIT_USER_CTRL_SRAM_RESET    0x04 // Reset (i.e. clear) FIFO buffer
#define BIT_USER_CTRL_DMP_RESET     0x08 // Reset DMP
#define BIT_USER_CTRL_I2C_IF_DIS    0x10 // Disable primary I2C interface and enable hal.spi->interface
#define BIT_USER_CTRL_I2C_MST_EN    0x20 // Enable MPU to act as the I2C Master to external slave sensors
#define BIT_USER_CTRL_FIFO_EN       0x40 // Enable FIFO operations
#define BIT_USER_CTRL_DMP_EN        0x80 // Enable DMP operations
#define INV2REG_LP_CONFIG           INV2REG(REG_BANK0, 0x05U)
#define INV2REG_PWR_MGMT_1          INV2REG(REG_BANK0, 0x06U)
#define BIT_PWR_MGMT_1_CLK_INTERNAL 0x00 // clock set to internal 8Mhz oscillator
#define BIT_PWR_MGMT_1_CLK_AUTO     0x01 // PLL with X axis gyroscope reference
#define BIT_PWR_MGMT_1_CLK_STOP     0x07 // Stops the clock and keeps the timing generator in reset
#define BIT_PWR_MGMT_1_TEMP_DIS     0x08 // disable temperature sensor
#define BIT_PWR_MGMT_1_SLEEP        0x40 // put sensor into low power sleep mode
#define BIT_PWR_MGMT_1_DEVICE_RESET 0x80 // reset entire device
#define INV2REG_PWR_MGMT_2          INV2REG(REG_BANK0, 0x07U)
#define INV2REG_INT_PIN_CFG         INV2REG(REG_BANK0, 0x0FU)
#define BIT_BYPASS_EN               0x02
#define BIT_INT_RD_CLEAR            0x10 // clear the interrupt when any read occurs
#define BIT_LATCH_INT_EN            0x20 // latch data ready pin
#define INV2REG_INT_ENABLE          INV2REG(REG_BANK0, 0x10U)
#define BIT_PLL_RDY_EN              0x04
#define INV2REG_INT_ENABLE_1        INV2REG(REG_BANK0, 0x11U)
#define INV2REG_INT_ENABLE_2        INV2REG(REG_BANK0, 0x12U)
#define INV2REG_INT_ENABLE_3        INV2REG(REG_BANK0, 0x13U)
#define INV2REG_I2C_MST_STATUS      INV2REG(REG_BANK0, 0x17U)
#define INV2REG_INT_STATUS          INV2REG(REG_BANK0, 0x19U)

#define INV2REG_INT_STATUS_1         INV2REG(REG_BANK0, 0x1AU)
#define INV2REG_INT_STATUS_2         INV2REG(REG_BANK0, 0x1BU)
#define INV2REG_INT_STATUS_3         INV2REG(REG_BANK0, 0x1CU)
#define INV2REG_DELAY_TIMEH          INV2REG(REG_BANK0, 0x28U)
#define INV2REG_DELAY_TIMEL          INV2REG(REG_BANK0, 0x29U)
#define INV2REG_ACCEL_XOUT_H         INV2REG(REG_BANK0, 0x2DU)
#define INV2REG_ACCEL_XOUT_L         INV2REG(REG_BANK0, 0x2EU)
#define INV2REG_ACCEL_YOUT_H         INV2REG(REG_BANK0, 0x2FU)
#define INV2REG_ACCEL_YOUT_L         INV2REG(REG_BANK0, 0x30U)
#define INV2REG_ACCEL_ZOUT_H         INV2REG(REG_BANK0, 0x31U)
#define INV2REG_ACCEL_ZOUT_L         INV2REG(REG_BANK0, 0x32U)
#define INV2REG_GYRO_XOUT_H          INV2REG(REG_BANK0, 0x33U)
#define INV2REG_GYRO_XOUT_L          INV2REG(REG_BANK0, 0x34U)
#define INV2REG_GYRO_YOUT_H          INV2REG(REG_BANK0, 0x35U)
#define INV2REG_GYRO_YOUT_L          INV2REG(REG_BANK0, 0x36U)
#define INV2REG_GYRO_ZOUT_H          INV2REG(REG_BANK0, 0x37U)
#define INV2REG_GYRO_ZOUT_L          INV2REG(REG_BANK0, 0x38U)
#define INV2REG_TEMP_OUT_H           INV2REG(REG_BANK0, 0x39U)
#define INV2REG_TEMP_OUT_L           INV2REG(REG_BANK0, 0x3AU)
#define INV2REG_EXT_SLV_SENS_DATA_00 INV2REG(REG_BANK0, 0x3BU)
#define INV2REG_EXT_SLV_SENS_DATA_01 INV2REG(REG_BANK0, 0x3CU)
#define INV2REG_EXT_SLV_SENS_DATA_02 INV2REG(REG_BANK0, 0x3DU)
#define INV2REG_EXT_SLV_SENS_DATA_03 INV2REG(REG_BANK0, 0x3EU)
#define INV2REG_EXT_SLV_SENS_DATA_04 INV2REG(REG_BANK0, 0x3FU)
#define INV2REG_EXT_SLV_SENS_DATA_05 INV2REG(REG_BANK0, 0x40U)
#define INV2REG_EXT_SLV_SENS_DATA_06 INV2REG(REG_BANK0, 0x41U)
#define INV2REG_EXT_SLV_SENS_DATA_07 INV2REG(REG_BANK0, 0x42U)
#define INV2REG_EXT_SLV_SENS_DATA_08 INV2REG(REG_BANK0, 0x43U)
#define INV2REG_EXT_SLV_SENS_DATA_09 INV2REG(REG_BANK0, 0x44U)
#define INV2REG_EXT_SLV_SENS_DATA_10 INV2REG(REG_BANK0, 0x45U)
#define INV2REG_EXT_SLV_SENS_DATA_11 INV2REG(REG_BANK0, 0x46U)
#define INV2REG_EXT_SLV_SENS_DATA_12 INV2REG(REG_BANK0, 0x47U)
#define INV2REG_EXT_SLV_SENS_DATA_13 INV2REG(REG_BANK0, 0x48U)
#define INV2REG_EXT_SLV_SENS_DATA_14 INV2REG(REG_BANK0, 0x49U)
#define INV2REG_EXT_SLV_SENS_DATA_15 INV2REG(REG_BANK0, 0x4AU)
#define INV2REG_EXT_SLV_SENS_DATA_16 INV2REG(REG_BANK0, 0x4BU)
#define INV2REG_EXT_SLV_SENS_DATA_17 INV2REG(REG_BANK0, 0x4CU)
#define INV2REG_EXT_SLV_SENS_DATA_18 INV2REG(REG_BANK0, 0x4DU)
#define INV2REG_EXT_SLV_SENS_DATA_19 INV2REG(REG_BANK0, 0x4EU)
#define INV2REG_EXT_SLV_SENS_DATA_20 INV2REG(REG_BANK0, 0x4FU)
#define INV2REG_EXT_SLV_SENS_DATA_21 INV2REG(REG_BANK0, 0x50U)
#define INV2REG_EXT_SLV_SENS_DATA_22 INV2REG(REG_BANK0, 0x51U)
#define INV2REG_EXT_SLV_SENS_DATA_23 INV2REG(REG_BANK0, 0x52U)
#define INV2REG_FIFO_EN_1            INV2REG(REG_BANK0, 0x66U)
#define BIT_SLV3_FIFO_EN             0x08
#define BIT_SLV2_FIFO_EN             0x04
#define BIT_SLV1_FIFO_EN             0x02
#define BIT_SLV0_FIFI_EN0            0x01
#define INV2REG_FIFO_EN_2            INV2REG(REG_BANK0, 0x67U)
#define BIT_ACCEL_FIFO_EN            0x10
#define BIT_ZG_FIFO_EN               0x08
#define BIT_YG_FIFO_EN               0x04
#define BIT_XG_FIFO_EN               0x02
#define BIT_TEMP_FIFO_EN             0x01
#define INV2REG_FIFO_RST             INV2REG(REG_BANK0, 0x68U)
#define INV2REG_FIFO_MODE            INV2REG(REG_BANK0, 0x69U)
#define INV2REG_FIFO_COUNTH          INV2REG(REG_BANK0, 0x70U)
#define INV2REG_FIFO_COUNTL          INV2REG(REG_BANK0, 0x71U)
#define INV2REG_FIFO_R_W             INV2REG(REG_BANK0, 0x72U)
#define INV2REG_DATA_RDY_STATUS      INV2REG(REG_BANK0, 0x74U)
#define INV2REG_FIFO_CFG             INV2REG(REG_BANK0, 0x76U)

#define INV2REG_SELF_TEST_X_GYRO   INV2REG(REG_BANK1, 0x02U)
#define INV2REG_SELF_TEST_Y_GYRO   INV2REG(REG_BANK1, 0x03U)
#define INV2REG_SELF_TEST_Z_GYRO   INV2REG(REG_BANK1, 0x04U)
#define INV2REG_SELF_TEST_X_ACCEL  INV2REG(REG_BANK1, 0x0EU)
#define INV2REG_SELF_TEST_Y_ACCEL  INV2REG(REG_BANK1, 0x0FU)
#define INV2REG_SELF_TEST_Z_ACCEL  INV2REG(REG_BANK1, 0x10U)
#define INV2REG_XA_OFFS_H          INV2REG(REG_BANK1, 0x14U)
#define INV2REG_XA_OFFS_L          INV2REG(REG_BANK1, 0x15U)
#define INV2REG_YA_OFFS_H          INV2REG(REG_BANK1, 0x17U)
#define INV2REG_YA_OFFS_L          INV2REG(REG_BANK1, 0x18U)
#define INV2REG_ZA_OFFS_H          INV2REG(REG_BANK1, 0x1AU)
#define INV2REG_ZA_OFFS_L          INV2REG(REG_BANK1, 0x1BU)
#define INV2REG_TIMEBASE_CORRECTIO INV2REG(REG_BANK1, 0x28U)

#define INV2REG_GYRO_SMPLRT_DIV    INV2REG(REG_BANK2, 0x00U)
#define INV2REG_GYRO_CONFIG_1      INV2REG(REG_BANK2, 0x01U)
#define BIT_GYRO_NODLPF_9KHZ       0x00
#define BIT_GYRO_DLPF_ENABLE       0x01
#define GYRO_DLPF_CFG_229HZ        0x00
#define GYRO_DLPF_CFG_188HZ        0x01
#define GYRO_DLPF_CFG_154HZ        0x02
#define GYRO_DLPF_CFG_73HZ         0x03
#define GYRO_DLPF_CFG_35HZ         0x04
#define GYRO_DLPF_CFG_17HZ         0x05
#define GYRO_DLPF_CFG_9HZ          0x06
#define GYRO_DLPF_CFG_376HZ        0x07
#define GYRO_DLPF_CFG_SHIFT        0x03
#define BITS_GYRO_FS_250DPS        0x00
#define BITS_GYRO_FS_500DPS        0x02
#define BITS_GYRO_FS_1000DPS       0x04
#define BITS_GYRO_FS_2000DPS       0x06
#define BITS_GYRO_FS_2000DPS_20649 0x04
#define BITS_GYRO_FS_MASK          0x06 // only bits 1 and 2 are used for gyro full scale so use this to mask off other bits
#define INV2REG_GYRO_CONFIG_2      INV2REG(REG_BANK2, 0x02U)
#define INV2REG_XG_OFFS_USRH       INV2REG(REG_BANK2, 0x03U)
#define INV2REG_XG_OFFS_USRL       INV2REG(REG_BANK2, 0x04U)
#define INV2REG_YG_OFFS_USRH       INV2REG(REG_BANK2, 0x05U)
#define INV2REG_YG_OFFS_USRL       INV2REG(REG_BANK2, 0x06U)
#define INV2REG_ZG_OFFS_USRH       INV2REG(REG_BANK2, 0x07U)
#define INV2REG_ZG_OFFS_USRL       INV2REG(REG_BANK2, 0x08U)
#define INV2REG_ODR_ALIGN_EN       INV2REG(REG_BANK2, 0x09U)
#define INV2REG_ACCEL_SMPLRT_DIV_1 INV2REG(REG_BANK2, 0x10U)
#define INV2REG_ACCEL_SMPLRT_DIV_2 INV2REG(REG_BANK2, 0x11U)
#define INV2REG_ACCEL_INTEL_CTRL   INV2REG(REG_BANK2, 0x12U)
#define INV2REG_ACCEL_WOM_THR      INV2REG(REG_BANK2, 0x13U)
#define INV2REG_ACCEL_CONFIG       INV2REG(REG_BANK2, 0x14U)
#define BIT_ACCEL_NODLPF_4_5KHZ    0x00
#define BIT_ACCEL_DLPF_ENABLE      0x01
#define ACCEL_DLPF_CFG_265HZ       0x00
#define ACCEL_DLPF_CFG_136HZ       0x02
#define ACCEL_DLPF_CFG_68HZ        0x03
#define ACCEL_DLPF_CFG_34HZ        0x04
#define ACCEL_DLPF_CFG_17HZ        0x05
#define ACCEL_DLPF_CFG_8HZ         0x06
#define ACCEL_DLPF_CFG_499HZ       0x07
#define ACCEL_DLPF_CFG_SHIFT       0x03
#define BITS_ACCEL_FS_2G           0x00
#define BITS_ACCEL_FS_4G           0x01
#define BITS_ACCEL_FS_8G           0x02
#define BITS_ACCEL_FS_16G          0x03
#define BITS_ACCEL_FS_30G_20649    0x06
#define BITS_ACCEL_FS_MASK         0x06 // only bits 1 and 2 are used for gyro full scale so use this to mask off other bits
#define INV2REG_FSYNC_CONFIG       INV2REG(REG_BANK2, 0x52U)
#define FSYNC_CONFIG_EXT_SYNC_TEMP 0x01
#define FSYNC_CONFIG_EXT_SYNC_GX   0x02
#define FSYNC_CONFIG_EXT_SYNC_GY   0x03
#define FSYNC_CONFIG_EXT_SYNC_GZ   0x04
#define FSYNC_CONFIG_EXT_SYNC_AX   0x05
#define FSYNC_CONFIG_EXT_SYNC_AY   0x06
#define FSYNC_CONFIG_EXT_SYNC_AZ   0x07
#define INV2REG_TEMP_CONFIG        INV2REG(REG_BANK2, 0x53U)
#define INV2REG_MOD_CTRL_USR       INV2REG(REG_BANK2, 0x54U)

#define INV2REG_I2C_MST_ODR_CONFIG INV2REG(REG_BANK3, 0x00U)
#define INV2REG_I2C_MST_CTRL       INV2REG(REG_BANK3, 0x01U)
#define BIT_I2C_MST_P_NSR          0x10
#define BIT_I2C_MST_CLK_400KHZ     0x0D
#define INV2REG_I2C_MST_DELAY_CTRL INV2REG(REG_BANK3, 0x02U)
#define BIT_I2C_SLV0_DLY_EN        0x01
#define BIT_I2C_SLV1_DLY_EN        0x02
#define BIT_I2C_SLV2_DLY_EN        0x04
#define BIT_I2C_SLV3_DLY_EN        0x08
#define INV2REG_I2C_SLV0_ADDR      INV2REG(REG_BANK3, 0x03U)
#define INV2REG_I2C_SLV0_REG       INV2REG(REG_BANK3, 0x04U)
#define INV2REG_I2C_SLV0_CTRL      INV2REG(REG_BANK3, 0x05U)
#define INV2REG_I2C_SLV0_DO        INV2REG(REG_BANK3, 0x06U)
#define INV2REG_I2C_SLV1_ADDR      INV2REG(REG_BANK3, 0x07U)
#define INV2REG_I2C_SLV1_REG       INV2REG(REG_BANK3, 0x08U)
#define INV2REG_I2C_SLV1_CTRL      INV2REG(REG_BANK3, 0x09U)
#define INV2REG_I2C_SLV1_DO        INV2REG(REG_BANK3, 0x0AU)
#define INV2REG_I2C_SLV2_ADDR      INV2REG(REG_BANK3, 0x0BU)
#define INV2REG_I2C_SLV2_REG       INV2REG(REG_BANK3, 0x0CU)
#define INV2REG_I2C_SLV2_CTRL      INV2REG(REG_BANK3, 0x0DU)
#define INV2REG_I2C_SLV2_DO        INV2REG(REG_BANK3, 0x0EU)
#define INV2REG_I2C_SLV3_ADDR      INV2REG(REG_BANK3, 0x0FU)
#define INV2REG_I2C_SLV3_REG       INV2REG(REG_BANK3, 0x10U)
#define INV2REG_I2C_SLV3_CTRL      INV2REG(REG_BANK3, 0x11U)
#define INV2REG_I2C_SLV3_DO        INV2REG(REG_BANK3, 0x12U)
#define INV2REG_I2C_SLV4_ADDR      INV2REG(REG_BANK3, 0x13U)
#define INV2REG_I2C_SLV4_REG       INV2REG(REG_BANK3, 0x14U)
#define INV2REG_I2C_SLV4_CTRL      INV2REG(REG_BANK3, 0x15U)
#define BIT_I2C_SLV4_EN            (1 << 7)
#define INV2REG_I2C_SLV4_DO        INV2REG(REG_BANK3, 0x16U)
#define INV2REG_I2C_SLV4_DI        INV2REG(REG_BANK3, 0x17U)

#define INV2REG_BANK_SEL 0x7F

//////////////////////////////////////////////
//                  AK09946
//////////////////////////////////////////////
#define REG_COMPANY_ID 0x00
#define REG_DEVICE_ID  0x01
#define REG_ST1        0x10
#define REG_HXL        0x11
#define REG_HXH        0x12
#define REG_HYL        0x13
#define REG_HYH        0x14
#define REG_HZL        0x15
#define REG_HZH        0x16
#define REG_TMPS       0x17
#define REG_ST2        0x18
#define REG_CNTL1      0x30
#define REG_CNTL2      0x31
#define REG_CNTL3      0x32

#define REG_ICM_WHOAMI      0x00
#define REG_ICM_PWR_MGMT_1  0x06
#define REG_ICM_INT_PIN_CFG 0x0f

#define ICM_WHOAMI_VAL    0xEA
#define AK09916_Device_ID 0x09

#define AK09916_I2C_ADDR 0x0C

#define AK09916_SCALE_TO_uT    0.15f
#define uT_to_GAUSS            0.01f
#define AK09916_SCALE_TO_GAUSS (AK09916_SCALE_TO_uT * uT_to_GAUSS)

//////////////////////////////////////////////

#define ICM20948_ONE_G 9.80665f
#define M_PI_F         3.1415926f

//////////////////////////////////////////////

static float gyro_range_scale;
static float accel_range_scale;
static rt_device_t spi_dev;

RT_WEAK void icm20948_rotate_to_ned(float* data)
{
}

RT_WEAK void ak09916_rotate_to_ned(float* data)
{
}

static rt_err_t _register_read_multi(uint16_t reg, uint8_t* buffer, uint8_t len)
{
    return spi_read_bank_multi_reg8(spi_dev, INV2REG_BANK_SEL, GET_BANK(reg) << 4, GET_REG(reg), buffer, len);
}

/**
 * @brief 
 * 
 * @param reg 
 * @return uint8_t 
 */
static rt_err_t _register_read(uint16_t reg, uint8_t* data)
{
    spi_read_bank_reg8(spi_dev, INV2REG_BANK_SEL, GET_BANK(reg) << 4, GET_REG(reg), data);
    return RT_EOK;
}

/**
 * @brief 
 * 
 * @param reg 
 * @param val 
 * @return rt_err_t 
 */
static rt_err_t _register_write(uint16_t reg, uint8_t val)
{
    uint8_t res = 0;

    spi_write_bank_reg8(spi_dev, INV2REG_BANK_SEL, GET_BANK(reg) << 4, GET_REG(reg), val);

    spi_read_bank_reg8(spi_dev, INV2REG_BANK_SEL, GET_BANK(reg) << 4, GET_REG(reg), &res);

    if (res != val) {
        // RT_ASSERT(RT_EOK);

        return RT_ERROR;
    }
    return RT_EOK;
}

/**
 * @brief 
 * 
 * @param val 
 */
static rt_err_t _register_write_aux(uint8_t reg, uint8_t data)
{
    /* Ensure the slave read/write is disabled before changing the registers */
    _register_write(INV2REG_I2C_SLV0_CTRL, 0x81);

    _register_write(INV2REG_I2C_SLV0_DO, data);

    _register_write(INV2REG_I2C_SLV0_ADDR, AK09916_I2C_ADDR);
    _register_write(INV2REG_I2C_SLV0_REG, reg);
    _register_write(INV2REG_I2C_SLV0_DO, data); //

    return RT_EOK;
}

/**
 * @brief 
 * 
 * @param reg 
 * @param data 
 * @return rt_err_t 
 */
static rt_err_t _register_read_aux(uint8_t reg, uint8_t* data)
{
    _register_write(INV2REG_I2C_SLV0_CTRL, 0x81);

    _register_write(INV2REG_I2C_SLV0_ADDR, AK09916_I2C_ADDR | 0x80);
    _register_write(INV2REG_I2C_SLV0_REG, reg);
    _register_write(INV2REG_I2C_SLV0_DO, 0xff); //read

    systime_mdelay(10);

    _register_read(INV2REG_EXT_SLV_SENS_DATA_00, data);

    return RT_EOK;
}

__PACKED__(
    struct sample_regs {
        uint8_t st1;
        int16_t val[3];
        uint8_t tmps;
        uint8_t st2;
    });

/**
 * @brief 
 * 
 * @param reg 
 * @param data 
 * @return rt_err_t 
 */
static rt_err_t _register_read_multi_aux(uint8_t reg, uint8_t* data, uint8_t size)
{
    _register_write(INV2REG_I2C_SLV0_CTRL, 0x80 | size);

    _register_write(INV2REG_I2C_SLV0_ADDR, AK09916_I2C_ADDR | 0x80);
    _register_write(INV2REG_I2C_SLV0_REG, reg);
    _register_write(INV2REG_I2C_SLV0_DO, 0xff); // read

    systime_mdelay(5);

    _register_read_multi(INV2REG_EXT_SLV_SENS_DATA_00, data, size);

    return RT_EOK;
}

static rt_err_t mag_raw_measure(int16_t mag[3])
{
    struct sample_regs regs = { 0 };

    RT_TRY(_register_read_multi_aux(REG_ST1, (uint8_t*)&regs, sizeof(regs)));

    /* swap the data */
    mag[0] = regs.val[0];
    mag[1] = regs.val[1];
    mag[2] = regs.val[2];

    return RT_EOK;
}

const float _range_scale = AK09916_SCALE_TO_GAUSS;

static rt_err_t mag_measure(float mag[3])
{
    int16_t raw[3];

    RT_TRY(mag_raw_measure(raw));

    mag[0] = _range_scale * raw[0];
    mag[1] = _range_scale * raw[1];
    mag[2] = _range_scale * raw[2];

    ak09916_rotate_to_ned(mag);

    return RT_EOK;
}

static rt_size_t ak09916_read(mag_dev_t mag, rt_off_t pos, void* data, rt_size_t size)
{
    if (data == RT_NULL) {
        return 0;
    }

    if (mag_measure(((float*)data)) != RT_EOK) {
        return 0;
    }

    return size;
}

static rt_err_t gyro_set_dlpf_filter(uint32_t frequency_hz)
{
    uint8_t reg_val;

    _register_read(INV2REG_GYRO_CONFIG_1, &reg_val);

    reg_val &= ~((7 << 3) | 1);

    if (frequency_hz <= 9) {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_9HZ << 3));
    } else if (frequency_hz < 17) {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_17HZ << 3));
    } else if (frequency_hz < 35) {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_35HZ << 3));
    } else if (frequency_hz < 73) {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_73HZ << 3));
    } else if (frequency_hz < 154) {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_154HZ << 3));
    } else if (frequency_hz < 188) {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_188HZ << 3));
    } else {
        reg_val |= (BIT_GYRO_DLPF_ENABLE | (GYRO_DLPF_CFG_229HZ << 3));
    }

    RT_TRY(_register_write(INV2REG_GYRO_CONFIG_1, reg_val));

    return RT_EOK;
}

static rt_err_t gyro_set_range(uint32_t max_dps)
{
    uint8_t reg_val;
    float lsb_per_dps;

    _register_read(INV2REG_GYRO_CONFIG_1, &reg_val);

    reg_val &= ~(2 << 1);

    if (max_dps == 0) {
        max_dps = 2000;
    }

    if (max_dps <= 250) {
        reg_val |= BITS_GYRO_FS_250DPS << 1;
        lsb_per_dps = 131;
    } else if (max_dps <= 500) {
        reg_val |= BITS_GYRO_FS_500DPS << 1;
        lsb_per_dps = 65.5;
    } else if (max_dps <= 1000) {
        reg_val |= BITS_GYRO_FS_1000DPS << 1;
        lsb_per_dps = 32.8;
    } else if (max_dps <= 2000) {
        reg_val |= BITS_GYRO_FS_2000DPS << 1;
        lsb_per_dps = 16.4;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(_register_write(INV2REG_GYRO_CONFIG_1, reg_val));

    gyro_range_scale = (M_PI_F / (180.0f * lsb_per_dps));

    return RT_EOK;
}

static rt_err_t accel_set_dlpf_filter(uint32_t frequency_hz)
{
    uint8_t reg_val;

    _register_read(INV2REG_ACCEL_CONFIG, &reg_val);

    reg_val &= ~((7 << 3) | 1);

    if (frequency_hz <= 8) {
        reg_val |= (BIT_ACCEL_DLPF_ENABLE | (ACCEL_DLPF_CFG_8HZ << 3));
    } else if (frequency_hz <= 17) {
        reg_val |= (BIT_ACCEL_DLPF_ENABLE | (ACCEL_DLPF_CFG_17HZ << 3));
    } else if (frequency_hz <= 34) {
        reg_val |= (BIT_ACCEL_DLPF_ENABLE | (ACCEL_DLPF_CFG_34HZ << 3));
    } else if (frequency_hz <= 68) {
        reg_val |= (BIT_ACCEL_DLPF_ENABLE | (ACCEL_DLPF_CFG_68HZ << 3));
    } else if (frequency_hz <= 136) {
        reg_val |= (BIT_ACCEL_DLPF_ENABLE | (ACCEL_DLPF_CFG_136HZ << 3));
    } else {
        reg_val |= (BIT_ACCEL_DLPF_ENABLE | (ACCEL_DLPF_CFG_265HZ << 3));
    }

    RT_TRY(_register_write(INV2REG_ACCEL_CONFIG, reg_val));

    return RT_EOK;
}

static rt_err_t accel_set_range(uint32_t max_g)
{
    uint8_t reg_val;
    float lsb_per_g;

    _register_read(INV2REG_ACCEL_CONFIG, &reg_val);
    reg_val &= ~(2 << 1);

    if (max_g == 0) {
        max_g = 16;
    }

    if (max_g <= 2) {
        reg_val |= BITS_ACCEL_FS_2G << 1;
        lsb_per_g = 16384;
    } else if (max_g <= 4) {
        reg_val |= BITS_ACCEL_FS_4G << 1;
        lsb_per_g = 8192;
    } else if (max_g <= 8) {
        reg_val |= BITS_ACCEL_FS_8G << 1;
        lsb_per_g = 4096;
    } else if (max_g <= 16) {
        reg_val |= BITS_ACCEL_FS_16G << 1;
        lsb_per_g = 2048;
    } else {
        return RT_EINVAL;
    }

    RT_TRY(_register_write(INV2REG_ACCEL_CONFIG, reg_val));

    accel_range_scale = (ICM20948_ONE_G / lsb_per_g);

    return RT_EOK;
}

/*
 * Return true if the Invensense has new data available for reading.
 *
 * We use the data ready pin if it is available.  Otherwise, read the
 * status register.
 */
static bool _data_ready()
{
    uint8_t status;
    _register_read(INV2REG_INT_STATUS_1, &status);
    return status != 0;
}

static rt_err_t lowlevel_init(void)
{
    uint8_t chip_id;
    uint8_t last_stat_user_ctrl;

    /* open spi device */
    RT_TRY(rt_device_open(spi_dev, RT_DEVICE_OFLAG_RDWR));

    RT_TRY(spi_read_bank_reg8(spi_dev, INV2REG_BANK_SEL, GET_BANK(INV2REG_WHO_AM_I), GET_REG(INV2REG_WHO_AM_I), &chip_id));
    if (chip_id != WHO_AM_I) {
        DRV_DBG("ICM20948 unmatched chip id:0x%x\n", chip_id);
        return FMT_ERROR;
    }

    _register_read(INV2REG_USER_CTRL, &last_stat_user_ctrl);

    /* Chip reset */
    uint8_t tries;
    for (tries = 0; tries < 5; tries++) {

        /* First disable the master I2C to avoid hanging the slaves on the
         * aulixiliar I2C bus - it will be enabled again if the AuxiliaryBus
         * is used */
        if (last_stat_user_ctrl & BIT_USER_CTRL_I2C_MST_EN) {
            last_stat_user_ctrl &= ~BIT_USER_CTRL_I2C_MST_EN;
            RT_TRY(_register_write(INV2REG_USER_CTRL, last_stat_user_ctrl));

            systime_udelay(1000);
        }

        /* reset device */
        _register_write(INV2REG_PWR_MGMT_1, BIT_PWR_MGMT_1_DEVICE_RESET);
        systime_udelay(5000);

        /* Disable I2C bus if SPI selected (Recommended in Datasheet to be
         * done just after the device is reset) */
        last_stat_user_ctrl |= BIT_USER_CTRL_I2C_IF_DIS;
        _register_write(INV2REG_USER_CTRL, last_stat_user_ctrl);

        // Wake up device and select Auto clock. Note that the
        // Invensense starts up in sleep mode, and it can take some time
        // for it to come out of sleep
        _register_write(INV2REG_PWR_MGMT_1, BIT_PWR_MGMT_1_CLK_AUTO);
        systime_udelay(5000);

        // check it has woken up
        uint8_t ret;
        _register_read(INV2REG_PWR_MGMT_1, &ret);
        if (ret == BIT_PWR_MGMT_1_CLK_AUTO) {
            break;
        }

        systime_udelay(5000);
        if (_data_ready()) {
            break;
        }
    }
    if (tries == 5) {
        DRV_DBG("Failed to boot Invensense 5 times\r\n");
        return RT_ERROR;
    }

    accel_set_range(16);
    gyro_set_range(2000);
    gyro_set_dlpf_filter(250);
    accel_set_dlpf_filter(250);
    DRV_DBG("boot Invensense %d times\r\n", tries);

    //////////////////////////////////////////////////////////////////////////
    //                          aux ak09966
    //////////////////////////////////////////////////////////////////////////

    /* Enable the I2C master to slaves on the auxiliary I2C bus*/
    if (!(last_stat_user_ctrl & BIT_USER_CTRL_I2C_MST_EN)) {
        last_stat_user_ctrl |= BIT_USER_CTRL_I2C_MST_EN;
        _register_write(INV2REG_USER_CTRL, last_stat_user_ctrl);
    }

    // _register_write(INV2REG_INT_PIN_CFG, 0x30); // INT Pin / Bypass Enable Configuration

    /* stop condition between reads; clock at 400kHz */
    _register_write(INV2REG_I2C_MST_CTRL, BIT_I2C_MST_P_NSR | BIT_I2C_MST_CLK_400KHZ);

    /* I2C_SLV0 _DLY_ enable */
    _register_write(INV2REG_I2C_MST_DELAY_CTRL, BIT_I2C_SLV0_DLY_EN);

    /*  enable IIC	and EXT_SENS_DATA==1 Byte */
    _register_write(INV2REG_I2C_SLV0_CTRL, 0x81);

    // Initialize magnetometer
    // Reset AK8963
    _register_write_aux(REG_CNTL3, 0x01);

    // Read ID
    uint8_t ak0996_id[2];
    _register_read_multi_aux(REG_COMPANY_ID, ak0996_id, 2);

    if ((ak0996_id[1] != AK09916_Device_ID) && (ak0996_id[0] != 0x48)) {
        DRV_DBG("ak09916 id:0x%x, 0x%x\r\n", ak0996_id[0], ak0996_id[1]);
        return RT_ERROR;
    }
    DRV_DBG("ak09916 id:0x%x, 0x%x\r\n", ak0996_id[0], ak0996_id[1]);

    _register_write_aux(REG_CNTL2, 0x08); //Continuous Mode 2

    return RT_EOK;
}

static rt_err_t gyro_read_raw(int16_t gyr[3])
{
    uint16_t raw[3];

    _register_read_multi(INV2REG_GYRO_XOUT_H, (uint8_t*)raw, 6);

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
    icm20948_rotate_to_ned(gyr);

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

static rt_err_t accel_read_raw(int16_t acc[3])
{
    int16_t raw[3];

    _register_read_multi(INV2REG_ACCEL_XOUT_H, (rt_uint8_t*)raw, 6);
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

    icm20948_rotate_to_ned(acc);

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

const static struct mag_ops __mag_ops = {
    NULL,
    NULL,
    ak09916_read,
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
    .ops = &_gyro_ops,
    .config = GYRO_CONFIGURE,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct accel_device accel_dev = {
    .ops = &_accel_ops,
    .config = ACCEL_CONFIGURE,
    .bus_type = GYRO_SPI_BUS_TYPE
};

static struct mag_device mag_dev = {
    .ops = &__mag_ops,
    .config = AK09916_CONFIG_DEFAULT,
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
        cfg.mode = RT_SPI_MODE_3 | RT_SPI_MSB; /* SPI Compatible Modes 3 */
        cfg.max_hz = 7000000;                  /* Max SPI speed: 7MHz */

        struct rt_spi_device* spi_device_t = (struct rt_spi_device*)spi_dev;

        spi_device_t->config.data_width = cfg.data_width;
        spi_device_t->config.mode = cfg.mode & RT_SPI_MODE_MASK;
        spi_device_t->config.max_hz = cfg.max_hz;
        RT_TRY(rt_spi_configure(spi_device_t, &cfg));
    }

    /* driver low-level init */
    RT_TRY(lowlevel_init());

    /* register gyro hal device */
    RT_TRY(hal_gyro_register(&gyro_dev, gyro_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    /* register accel hal device */
    RT_TRY(hal_accel_register(&accel_dev, accel_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));
    /* register mag hal device */
    RT_TRY(hal_mag_register(&mag_dev, mag_device_name, RT_DEVICE_FLAG_RDWR, RT_NULL));

    return RT_EOK;
}

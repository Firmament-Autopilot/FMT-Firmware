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
#ifndef __BMI055_H__
#define __BMI055_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BIT(_idx) (1 << _idx)
#define REG_VAL(_setbits, _clearbits) \
    (reg_val_t) { .setbits = (_setbits), .clearbits = (_clearbits) }

#define BMI055_ACC_I2C_ADDR1        0x18                 //SDO is low(GND)
#define BMI055_ACC_I2C_ADDR2        0x19                 //SDO is high(VCC)
#define BMI055_ACC_DEFAULT_ADDRESS  BMI055_ACC_I2C_ADDR2 //in the LPC54102 SPM-S
#define BMI055_ACC_BGW_CHIPID_VALUE 0xFA
#define BMI055_ACC_BGW_CHIPID       0x00
#define BMI055_ACCD_X_LSB           0x02
#define BMI055_ACCD_X_MSB           0x03
#define BMI055_ACCD_Y_LSB           0x04
#define BMI055_ACCD_Y_MSB           0x05
#define BMI055_ACCD_Z_LSB           0x06
#define BMI055_ACCD_Z_MSB           0x07
#define BMI055_ACCD_TEMP            0x08
#define BMI055_INT_STATUS_0         0x09
#define BMI055_INT_STATUS_1         0x0A
#define BMI055_INT_STATUS_2         0x0B
#define BMI055_INT_STATUS_3         0x0C
#define BMI055_FIFO_STATUS          0x0E
#define BMI055_PMU_RANGE            0x0F
#define BMI055_PMU_BW               0x10
#define BMI055_PMU_LPW              0x11
#define BMI055_PMU_LOW_POWER        0x12
#define BMI055_ACCD_HBW             0x13
#define BMI055_BGW_SOFTRESET        0x14
#define BMI055_INT_EN_0             0x16
#define BMI055_INT_EN_1             0x17
#define BMI055_INT_EN_2             0x18
#define BMI055_INT_MAP_0            0x19
#define BMI055_INT_MAP_1            0x1A
#define BMI055_INT_MAP_2            0x1B
#define BMI055_INT_SRC              0x1E
#define BMI055_INT_OUT_CTRL         0x20
#define BMI055_INT_RST_LATCH        0x21
#define BMI055_INT_0                0x22
#define BMI055_INT_1                0x23
#define BMI055_INT_2                0x24
#define BMI055_INT_3                0x25
#define BMI055_INT_4                0x26
#define BMI055_INT_5                0x27
#define BMI055_INT_6                0x28
#define BMI055_INT_7                0x29
#define BMI055_INT_8                0x2A
#define BMI055_INT_9                0x2B
#define BMI055_INT_A                0x2C
#define BMI055_INT_B                0x2D
#define BMI055_INT_C                0x2E
#define BMI055_INT_D                0x2F
#define BMI055_FIFO_CONFIG_0        0x30
#define BMI055_PMU_SELF_TEST        0x32
#define BMI055_TRIM_NVM_CTRL        0x33
#define BMI055_BGW_SPI3_WDT         0x34
#define BMI055_OFC_CTRL             0x36
#define BMI055_OFC_SETTING          0x37
#define BMI055_OFC_OFFSET_X         0x38
#define BMI055_OFC_OFFSET_Y         0x39
#define BMI055_OFC_OFFSET_Z         0x3A
#define BMI055_TRIM_GP0             0x3B
#define BMI055_TRIM_GP1             0x3C
#define BMI055_FIFO_CONFIG_1        0x3E
#define BMI055_FIFO_DATA            0x3F

#define BMI055_GYRO_I2C_ADDR1        0x68 //SDO is low(GND)
#define BMI055_GYRO_I2C_ADDR2        0x69 //SDO is high(VCC)
#define BMI055_GYRO_DEFAULT_ADDRESS  BMI055_GYRO_I2C_ADDR2
#define BMI055_GRRO_CHIP_ID          0x0F
#define BMI055_CHIP_ID_ADDR          0x00
#define BMI055_RATE_X_LSB_ADDR       0x02
#define BMI055_RATE_X_MSB_ADDR       0x03
#define BMI055_RATE_Y_LSB_ADDR       0x04
#define BMI055_RATE_Y_MSB_ADDR       0x05
#define BMI055_RATE_Z_LSB_ADDR       0x06
#define BMI055_RATE_Z_MSB_ADDR       0x07
#define BMI055_TEMP_ADDR             0x08
#define BMI055_INTR_STAT0_ADDR       0x09
#define BMI055_INTR_STAT1_ADDR       0x0A
#define BMI055_INTR_STAT2_ADDR       0x0B
#define BMI055_INTR_STAT3_ADDR       0x0C
#define BMI055_FIFO_STAT_ADDR        0x0E
#define BMI055_RANGE_ADDR            0x0F
#define BMI055_BW_ADDR               0x10
#define BMI055_MODE_LPM1_ADDR        0x11
#define BMI055_MODE_LPM2_ADDR        0x12
#define BMI055_HIGH_BW_ADDR          0x13
#define BMI055_BGW_SOFT_RST_ADDR     0x14
#define BMI055_INTR_ENABLE0_ADDR     0x15
#define BMI055_INTR_ENABLE1_ADDR     0x16
#define BMI055_INTR_MAP_ZERO_ADDR    0x17
#define BMI055_INTR_MAP_ONE_ADDR     0x18
#define BMI055_INTR_MAP_TWO_ADDR     0x19
#define BMI055_INTR_ZERO_ADDR        0x1A
#define BMI055_INTR_ONE_ADDR         0x1B
#define BMI055_INTR_TWO_ADDR         0x1C
#define BMI055_INTR_4_ADDR           0x1E
#define BMI055_RST_LATCH_ADDR        0x21
#define BMI055_HIGHRATE_THRES_X_ADDR 0x22
#define BMI055_HIGHRATE_DURN_X_ADDR  0x23
#define BMI055_HIGHRATE_THRES_Y_ADDR 0x24
#define BMI055_HIGHRATE_DURN_Y_ADDR  0x25
#define BMI055_HIGHRATE_THRES_Z_ADDR 0x26
#define BMI055_HIGHRATE_DURN_Z_ADDR  0x27
#define BMI055_SOC_ADDR              0x31
#define BMI055_A_FOC_ADDR            0x32
#define BMI055_TRIM_NVM_CTRL_ADDR    0x33
#define BMI055_BGW_SPI3_WDT_ADDR     0x34
#define BMI055_OFC1_ADDR             0x36
#define BMI055_OFC2_ADDR             0x37
#define BMI055_OFC3_ADDR             0x38
#define BMI055_OFC4_ADDR             0x39
#define BMI055_TRIM_GP0_ADDR         0x3A
#define BMI055_TRIM_GP1_ADDR         0x3B
#define BMI055_SELECTF_TEST_ADDR     0x3C
#define BMI055_FIFO_CGF1_ADDR        0x3D
#define BMI055_FIFO_CGF0_ADDR        0x3E
#define BMI055_FIFO_DATA_ADDR        0x3F

#define BMI055_GYRO_RANGE_2000_DPS REG_VAL(0, BIT(2) | BIT(1) | BIT(0))
#define BMI055_GYRO_RANGE_1000_DPS REG_VAL(BIT(0), BIT(2) | BIT(1))
#define BMI055_GYRO_RANGE_500_DPS  REG_VAL(BIT(1), BIT(2) | BIT(0))
#define BMI055_GYRO_RANGE_250_DPS  REG_VAL(BIT(1) | BIT(0), BIT(2))
#define BMI055_GYRO_RANGE_125_DPS  REG_VAL(BIT(2), BIT(1) | BIT(0))

#define BMI055_GYRO_RATE_100  REG_VAL(BIT(2) | BIT(1) | BIT(0), BIT(3))
#define BMI055_GYRO_RATE_200  REG_VAL(BIT(2) | BIT(1), BIT(3) | BIT(0))
#define BMI055_GYRO_RATE_400  REG_VAL(BIT(1) | BIT(0), BIT(3) | BIT(2))
#define BMI055_GYRO_RATE_1000 REG_VAL(BIT(1), BIT(3) | BIT(2) | BIT(0))
#define BMI055_GYRO_RATE_2000 REG_VAL(BIT(0), BIT(3) | BIT(2) | BIT(1))

#define BMI055_ACCEL_RANGE_2_G  REG_VAL(BIT(1) | BIT(0), BIT(3) | BIT(2))
#define BMI055_ACCEL_RANGE_4_G  REG_VAL(BIT(2) | BIT(0), BIT(3) | BIT(1))
#define BMI055_ACCEL_RANGE_8_G  REG_VAL(BIT(3), BIT(2) | BIT(1) | BIT(0))
#define BMI055_ACCEL_RANGE_16_G REG_VAL(BIT(3) | BIT(2), BIT(1) | BIT(0))

#define BMI055_ACCEL_BW_7_81  REG_VAL(BIT(3), BIT(4) | BIT(2) | BIT(1) | BIT(0))
#define BMI055_ACCEL_BW_15_63 REG_VAL(BIT(3) | BIT(0), BIT(4) | BIT(2) | BIT(1))
#define BMI055_ACCEL_BW_31_25 REG_VAL(BIT(3) | BIT(1), BIT(4) | BIT(2) | BIT(0))
#define BMI055_ACCEL_BW_62_5  REG_VAL(BIT(3) | BIT(1) | BIT(0), BIT(4) | BIT(2))
#define BMI055_ACCEL_BW_125   REG_VAL(BIT(3) | BIT(2), BIT(4) | BIT(1) | BIT(0))
#define BMI055_ACCEL_BW_250   REG_VAL(BIT(3) | BIT(2) | BIT(0), BIT(4) | BIT(1))
#define BMI055_ACCEL_BW_500   REG_VAL(BIT(3) | BIT(2) | BIT(1), BIT(4) | BIT(0))
#define BMI055_ACCEL_BW_1000  REG_VAL(BIT(3) | BIT(2) | BIT(1) | BIT(0), BIT(4))

typedef struct {
    uint8_t setbits;
    uint8_t clearbits;
} reg_val_t;

rt_err_t drv_bmi055_init(void);

#ifdef __cplusplus
}
#endif

#endif

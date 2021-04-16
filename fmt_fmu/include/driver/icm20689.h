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
#ifndef __ICM20689_H__
#define __ICM20689_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHECK_RETURN(__func)  \
    if ((__func) != RT_EOK) { \
        return RT_ERROR;      \
    }

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

rt_err_t drv_icm20689_init(void);

#ifdef __cplusplus
}
#endif

#endif

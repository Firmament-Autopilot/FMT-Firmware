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

#ifndef FMTCONFIG_H__
#define FMTCONFIG_H__

#define FMT_USING_CHECKED

/* HIL simulation */
// #define FMT_USING_HIL
/* SIG simulation */
// #define FMT_USING_SIH

/* Mavlink */
#define FMT_USING_MAVLINK_V2
#define FMT_MAVLINK_SYS_ID  1
#define FMT_MAVLINK_COMP_ID 1

/* Send out pilot cmd via mavlink */
#define FMT_OUTPUT_PILOT_CMD

/* MLog */
#define MLOG_BUFFER_SIZE         128 * 1024
#define MLOG_SECTOR_SIZE         4096
#define MLOG_MAX_SECTOR_TO_WRITE 5

/* ULog */
#define FMT_USING_ULOG
#ifdef FMT_USING_ULOG
// #define ENABLE_ULOG_FS_BACKEND
#define ENABLE_ULOG_CONSOLE_BACKEND
#endif

/* Cortex-M Backtrace */
#define FMT_USING_CM_BACKTRACE

/* Unit Test */
// #define FMT_USING_UNIT_TEST

// #define FMT_RECORD_CALIBRATION_DATA

#define BOARD_TYPE_CUAVV5P

//*******************************************//
//                  IMU                      //
//*******************************************//
// #define BOARD_USE_BMI055
#define BOARD_USE_ICM20689

#ifdef BOARD_USE_BMI055
    #define BMI055_ROTATION ROTATION_ROLL_180_PITCH_270
    #define BMI055_DEV_NAME "spi1_dev3"
    #define BMI055_ACC_NAME "acc1"
    #define BMI055_GYRO_NAME "gyro1"   
#endif

#ifdef BOARD_USE_ICM20689
    #define ICM20689_ROTATION ROTATION_ROLL_180_PITCH_270
    #define ICM20689_DEV_NAME "spi1_dev1"
    #define ICM20689_ACC_NAME "acc0"
    #define ICM20689_GYRO_NAME "gyro0"  
#endif

//*******************************************//
//                  MAG                      //
//*******************************************//
#define BOARD_USE_IST8310
// #define BOARD_USE_HMC5883

#ifdef BOARD_USE_IST8310
    #define IST8310_ROTATION ROTATION_ROLL_180_PITCH_270
    #define IST8310_DEV_NAME "i2c3_dev1"
    #define IST8310_NAME "mag0"
#endif

//*******************************************//
//                  BARO                     //
//*******************************************//
#define BOARD_USE_MS5611
// #define BOARD_USE_SPL06

#ifdef BOARD_USE_MS5611
    #define MS5611_DEV_NAME "spi4_dev1"
    #define MS5611_NAME "barometer"
#endif


#endif

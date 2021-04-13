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

#ifndef __BOARD_DEVICE_H__
#define __BOARD_DEVICE_H__

// Device Name
#define CONSOLE_DEVICE_NAME        "serial0"
#define FMTIO_DEVICE_NAME          "serial5"
#define GDB_DEVICE_NAME            "serial6"
#define MAVPROXY_CHAN1_DEVICE_NAME "serial1"
#define MAVPROXY_CHAN2_DEVICE_NAME "usb"
#define FS_DEVICE_NAME             "sd0"
#define GPS_SERIAL_DEVICE_NAME     "serial2"
#define MPU6000_SPI_DEVICE_NAME    "spi1_dev4"
#define L3GD20H_SPI_DEVICE_NAME    "spi1_dev2"
#define LSM303D_SPI_DEVICE_NAME    "spi1_dev1"

#define MS5611_SPI_DEVICE_NAME     "spi4_dev1"
#define ICM20689_SPI_DEVICE_NAME   "spi1_dev1"

#define BMI055_ACC_SPI_DEVICE_NAME      "spi1_dev4"
#define BMI055_GYRO_SPI_DEVICE_NAME     "spi1_dev3"

#define SENSOR_USING_IMU0
#define SENSOR_USING_IMU1
// #define SENSOR_USING_MAG0
// #define SENSOR_USING_MAG1
#define SENSOR_USING_BAROMETER
// #define SENSOR_USING_GPS

#endif
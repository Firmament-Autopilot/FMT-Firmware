/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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
#include "module/sensor/sensor_imu.h"
#include "hal/accel/accel.h"
#include "hal/gyro/gyro.h"

/**
 * @brief Set gyro rotation matrix
 * 
 * @param imu_dev IMU sensor device
 * @param rotation Gyro rotation matrix (3x3)
 */
void sensor_gyr_set_rotation(sensor_imu_t imu_dev, const float rotation[9])
{
    imu_dev->gyr_rotation[0][0] = rotation[0];
    imu_dev->gyr_rotation[0][1] = rotation[1];
    imu_dev->gyr_rotation[0][2] = rotation[2];
    imu_dev->gyr_rotation[1][0] = rotation[3];
    imu_dev->gyr_rotation[1][1] = rotation[4];
    imu_dev->gyr_rotation[1][2] = rotation[5];
    imu_dev->gyr_rotation[2][0] = rotation[6];
    imu_dev->gyr_rotation[2][1] = rotation[7];
    imu_dev->gyr_rotation[2][2] = rotation[8];
}

/**
 * @brief Set gyro offset
 * 
 * @param imu_dev IMU sensor device
 * @param offset Gyro offset
 */
void sensor_gyr_set_offset(sensor_imu_t imu_dev, const float offset[3])
{
    imu_dev->gyr_offset[0] = offset[0];
    imu_dev->gyr_offset[1] = offset[1];
    imu_dev->gyr_offset[2] = offset[2];
}

/**
 * @brief Correct gyro data based on offset and rotation matrix
 * 
 * @param imu_dev IMU sensor device
 * @param src Original gyro data
 * @param dst Corrected gyro data
 */
void sensor_gyr_correct(sensor_imu_t imu_dev, const float src[3], float dst[3])
{
    float temp[3];

    temp[0] = src[0] - imu_dev->gyr_offset[0];
    temp[1] = src[1] - imu_dev->gyr_offset[1];
    temp[2] = src[2] - imu_dev->gyr_offset[2];

    dst[0] = imu_dev->gyr_rotation[0][0] * temp[0] + imu_dev->gyr_rotation[0][1] * temp[1] + imu_dev->gyr_rotation[0][2] * temp[2];
    dst[1] = imu_dev->gyr_rotation[1][0] * temp[0] + imu_dev->gyr_rotation[1][1] * temp[1] + imu_dev->gyr_rotation[1][2] * temp[2];
    dst[2] = imu_dev->gyr_rotation[2][0] * temp[0] + imu_dev->gyr_rotation[2][1] * temp[1] + imu_dev->gyr_rotation[2][2] * temp[2];
}

/**
 * @brief Measure scaled gyro data (rad/s)
 * 
 * @param imu_dev IMU sensor device
 * @param buffer Data buffer
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t sensor_gyr_measure(sensor_imu_t imu_dev, float buffer[3])
{
    rt_size_t r_size;

    RT_ASSERT(imu_dev != NULL);

    r_size = rt_device_read(imu_dev->gyr_dev, 0, (void*)buffer, 12);

    return r_size == 12 ? FMT_EOK : FMT_ERROR;
}

/**
 * @brief Set accel rotation matrix
 * 
 * @param imu_dev IMU sensor device
 * @param rotation Accel rotation matrix (3x3)
 */
void sensor_acc_set_rotation(sensor_imu_t imu_dev, const float rotation[9])
{
    imu_dev->acc_rotation[0][0] = rotation[0];
    imu_dev->acc_rotation[0][1] = rotation[1];
    imu_dev->acc_rotation[0][2] = rotation[2];
    imu_dev->acc_rotation[1][0] = rotation[3];
    imu_dev->acc_rotation[1][1] = rotation[4];
    imu_dev->acc_rotation[1][2] = rotation[5];
    imu_dev->acc_rotation[2][0] = rotation[6];
    imu_dev->acc_rotation[2][1] = rotation[7];
    imu_dev->acc_rotation[2][2] = rotation[8];
}

/**
 * @brief Set accel offset
 * 
 * @param imu_dev IMU sensor device
 * @param offset Accel offset
 */
void sensor_acc_set_offset(sensor_imu_t imu_dev, const float offset[3])
{
    imu_dev->acc_offset[0] = offset[0];
    imu_dev->acc_offset[1] = offset[1];
    imu_dev->acc_offset[2] = offset[2];
}

/**
 * @brief Correct accel data based on offset and rotation matrix
 * 
 * @param imu_dev IMU sensor device
 * @param src Original accel data
 * @param dst Corrected accel data
 */
void sensor_acc_correct(sensor_imu_t imu_dev, const float src[3], float dst[3])
{
    float temp[3];

    temp[0] = src[0] - imu_dev->acc_offset[0];
    temp[1] = src[1] - imu_dev->acc_offset[1];
    temp[2] = src[2] - imu_dev->acc_offset[2];

    dst[0] = imu_dev->acc_rotation[0][0] * temp[0] + imu_dev->acc_rotation[0][1] * temp[1] + imu_dev->acc_rotation[0][2] * temp[2];
    dst[1] = imu_dev->acc_rotation[1][0] * temp[0] + imu_dev->acc_rotation[1][1] * temp[1] + imu_dev->acc_rotation[1][2] * temp[2];
    dst[2] = imu_dev->acc_rotation[2][0] * temp[0] + imu_dev->acc_rotation[2][1] * temp[1] + imu_dev->acc_rotation[2][2] * temp[2];
}

/**
 * @brief Measure scaled accel data (m/s2)
 * 
 * @param imu_dev IMU sensor device
 * @param buffer Data buffer
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t sensor_acc_measure(sensor_imu_t imu_dev, float buffer[3])
{
    rt_size_t r_size;

    RT_ASSERT(imu_dev != NULL);

    r_size = rt_device_read(imu_dev->acc_dev, 0, (void*)buffer, 12);

    return r_size == 12 ? FMT_EOK : FMT_ERROR;
}

/**
 * @brief Initialize imu sensor device
 * 
 * @param gyr_dev_name Gyroscope device name
 * @param acc_dev_name Accelerometer device name
 * @return sensor_imu_t IMU sensor device
 */
sensor_imu_t sensor_imu_init(const char* gyr_dev_name, const char* acc_dev_name)
{
    sensor_imu_t imu_dev = (sensor_imu_t)rt_malloc(sizeof(struct sensor_imu));
    RT_ASSERT(imu_dev != NULL);

    imu_dev->gyr_dev = rt_device_find(gyr_dev_name);
    RT_ASSERT(imu_dev->gyr_dev != NULL);

    RT_CHECK(rt_device_open(imu_dev->gyr_dev, RT_DEVICE_OFLAG_RDWR));

    imu_dev->acc_dev = rt_device_find(acc_dev_name);
    RT_ASSERT(imu_dev->acc_dev != NULL);

    RT_CHECK(rt_device_open(imu_dev->acc_dev, RT_DEVICE_OFLAG_RDWR));

    return imu_dev;
}
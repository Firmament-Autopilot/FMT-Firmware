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

#include <firmament.h>

#include "module/sensor/sensor_imu.h"
#include "hal/gyro.h"
#include "hal/accel.h"

static rt_device_t gyro_t[SENSOR_IMU_NUM];
static rt_device_t accel_t[SENSOR_IMU_NUM];

/**************************	GYR API	**************************/

fmt_err sensor_gyr_raw_measure(int16_t gyr[3], uint8_t imu_id)
{
	rt_size_t r_size;

	if(imu_id > SENSOR_IMU_NUM - 1) {
		/* invalid imu id */
		return 0;
	}

	if(gyro_t[imu_id] == NULL) {
		return 0;
	}

	r_size = rt_device_read(gyro_t[imu_id], GYRO_RD_RAW, (void*)gyr, 6);

	return r_size == 6 ? FMT_EOK : FMT_ERROR;
}

// unit: rad/s
fmt_err sensor_gyr_measure(float gyr[3], uint8_t imu_id)
{
	rt_size_t r_size;

	if(imu_id > SENSOR_IMU_NUM - 1) {
		/* invalid imu id */
		return 0;
	}

	if(gyro_t[imu_id] == NULL) {
		return 0;
	}

	r_size = rt_device_read(gyro_t[imu_id], GYRO_RD_SCALE, (void*)gyr, 12);

	return r_size == 12 ? FMT_EOK : FMT_ERROR;
}


/**************************	ACC API	**************************/

fmt_err sensor_acc_raw_measure(int16_t acc[3], uint8_t imu_id)
{
	rt_size_t r_size;

	if(imu_id > SENSOR_IMU_NUM - 1) {
		/* invalid imu id */
		return 0;
	}

	if(accel_t[imu_id] == NULL) {
		return 0;
	}

	r_size = rt_device_read(accel_t[imu_id], ACCEL_RD_RAW, (void*)acc, 6);

	return r_size == 6 ? FMT_EOK : FMT_ERROR;
}

// unit: m/s2
fmt_err sensor_acc_measure(float acc[3], uint8_t imu_id)
{
	rt_size_t r_size;

	if(imu_id > SENSOR_IMU_NUM - 1) {
		/* invalid imu id */
		return 0;
	}

	if(accel_t[imu_id] == NULL) {
		return 0;
	}

	r_size = rt_device_read(accel_t[imu_id], ACCEL_RD_SCALE, (void*)acc, 12);

	return r_size == 12 ? FMT_EOK : FMT_ERROR;
}

fmt_err sensor_imu_init(void)
{
	rt_err_t rt_err = FMT_EOK;

	gyro_t[0] = rt_device_find("gyro0");

	if(gyro_t[0]) {
		rt_err |= rt_device_open(gyro_t[0], RT_DEVICE_OFLAG_RDWR);
	}

	accel_t[0] = rt_device_find("accel0");

	if(accel_t[0]) {
		rt_err |= rt_device_open(accel_t[0], RT_DEVICE_OFLAG_RDWR);
	}

	gyro_t[1] = rt_device_find("gyro1");

	if(gyro_t[1]) {
		rt_err |= rt_device_open(gyro_t[1], RT_DEVICE_OFLAG_RDWR);
	}

	accel_t[1] = rt_device_find("accel1");

	if(accel_t[1]) {
		rt_err |= rt_device_open(accel_t[1], RT_DEVICE_OFLAG_RDWR);
	}

	if(gyro_t[0] == NULL || accel_t[0] == NULL) {
		/* main imu must be available */
		console_printf("main imu is not available\n");
		rt_err = RT_ERROR;
	}

	return rt_err == RT_EOK ? FMT_EOK : FMT_ERROR;
}
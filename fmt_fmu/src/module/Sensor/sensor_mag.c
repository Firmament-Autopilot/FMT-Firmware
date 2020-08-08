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

#include "hal/mag.h"

// #include <stdio.h>

static rt_device_t _mag_t[2];

/**************************	MAG API	**************************/

rt_err_t sensor_mag_raw_measure(int16_t mag[3], uint8_t mag_id)
{
	rt_size_t r_byte;

	r_byte = rt_device_read(_mag_t[mag_id], MAG_RD_RAW, (void*)mag, 6);

	return r_byte == 6 ? RT_EOK : RT_ERROR;
}

rt_err_t sensor_mag_measure(float mag[3], uint8_t mag_id)
{
	rt_size_t r_byte;

	r_byte = rt_device_read(_mag_t[mag_id], MAG_RD_SCALE, (void*)mag, 12);

	return r_byte == 12 ? RT_EOK : RT_ERROR;
}

rt_err_t sensor_mag_init(void)
{
	rt_err_t rt_err = RT_EOK;

	_mag_t[0] = rt_device_find("mag0");

	if(_mag_t[0]) {
		rt_err |= rt_device_open(_mag_t[0], RT_DEVICE_OFLAG_RDWR);
	}

	_mag_t[1] = rt_device_find("mag1");

	if(_mag_t[1]) {
		rt_err |= rt_device_open(_mag_t[1], RT_DEVICE_OFLAG_RDWR);
	}

	return rt_err;
}


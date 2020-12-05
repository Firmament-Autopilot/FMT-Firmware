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
#include "module/sensor/sensor_manager.h"

rt_err_t sensor_mag_raw_measure(sensor_mag_t mag_dev, int16_t mag[3])
{
	rt_size_t r_byte;

	r_byte = rt_device_read(mag_dev->dev, MAG_RD_RAW, (void*)mag, 6);

	return r_byte == 6 ? RT_EOK : RT_ERROR;
}

rt_err_t sensor_mag_measure(sensor_mag_t mag_dev, float mag[3])
{
	rt_size_t r_byte;

	r_byte = rt_device_read(mag_dev->dev, MAG_RD_SCALE, (void*)mag, 12);

	return r_byte == 12 ? RT_EOK : RT_ERROR;
}

void sensor_mag_set_rotation(sensor_mag_t mag_dev, const float rotation[9])
{
    mag_dev->rotation[0][0] = rotation[0];
    mag_dev->rotation[0][1] = rotation[1];
    mag_dev->rotation[0][2] = rotation[2];
    mag_dev->rotation[1][0] = rotation[3];
    mag_dev->rotation[1][1] = rotation[4];
    mag_dev->rotation[1][2] = rotation[5];
    mag_dev->rotation[2][0] = rotation[6];
    mag_dev->rotation[2][1] = rotation[7];
    mag_dev->rotation[2][2] = rotation[8];
}

void sensor_mag_set_offset(sensor_mag_t mag_dev, const float offset[3])
{
    mag_dev->offset[0] = offset[0];
    mag_dev->offset[1] = offset[1];
    mag_dev->offset[2] = offset[2];
}

void sensor_mag_correct(sensor_mag_t mag_dev, const float mag[3], float mag_cor[3])
{
    float temp[3];

    temp[0] = mag[0] - mag_dev->offset[0];
    temp[1] = mag[1] - mag_dev->offset[1];
    temp[2] = mag[2] - mag_dev->offset[2];

    mag_cor[0] = mag_dev->rotation[0][0] * temp[0] + mag_dev->rotation[0][1] * temp[1] + mag_dev->rotation[0][2] * temp[2];
    mag_cor[1] = mag_dev->rotation[1][0] * temp[0] + mag_dev->rotation[1][1] * temp[1] + mag_dev->rotation[1][2] * temp[2];
    mag_cor[2] = mag_dev->rotation[2][0] * temp[0] + mag_dev->rotation[2][1] * temp[1] + mag_dev->rotation[2][2] * temp[2];
}

sensor_mag_t sensor_mag_init(const char* mag_dev_name)
{
    sensor_mag_t mag_dev = (sensor_mag_t)rt_malloc(sizeof(struct sensor_mag));

    if (mag_dev == NULL) {
        return mag_dev;
    }

    if (mag_dev_name) {
        mag_dev->dev = rt_device_find(mag_dev_name);
        if (mag_dev->dev == NULL) {
            goto err;
        }
        if (rt_device_open(mag_dev->dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
            goto err;
        }
    }

    return mag_dev;
err:
    rt_free(mag_dev);
    return NULL;
}


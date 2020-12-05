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

#include "hal/accel.h"
#include "hal/gyro.h"
#include "module/sensor/sensor_imu.h"

/**************************	GYR API	**************************/

fmt_err sensor_gyr_raw_measure(sensor_imu_t imu_dev, int16_t gyr[3])
{
    rt_size_t r_size;

    if (imu_dev == NULL || imu_dev->gyr_dev == NULL) {
        return FMT_EEMPTY;
    }

    r_size = rt_device_read(imu_dev->gyr_dev, GYRO_RD_RAW, (void*)gyr, 6);

    return r_size == 6 ? FMT_EOK : FMT_ERROR;
}

// unit: rad/s
fmt_err sensor_gyr_measure(sensor_imu_t imu_dev, float gyr[3])
{
    rt_size_t r_size;

    if (imu_dev == NULL || imu_dev->gyr_dev == NULL) {
        return FMT_EEMPTY;
    }

    r_size = rt_device_read(imu_dev->gyr_dev, GYRO_RD_SCALE, (void*)gyr, 12);

    return r_size == 12 ? FMT_EOK : FMT_ERROR;
}

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

void sensor_gyr_set_offset(sensor_imu_t imu_dev, const float offset[3])
{
    imu_dev->gyr_offset[0] = offset[0];
    imu_dev->gyr_offset[1] = offset[1];
    imu_dev->gyr_offset[2] = offset[2];
}

void sensor_gyr_correct(sensor_imu_t imu_dev, const float gyr[3], float gyr_cor[3])
{
    float temp[3];

    temp[0] = gyr[0] - imu_dev->gyr_offset[0];
    temp[1] = gyr[1] - imu_dev->gyr_offset[1];
    temp[2] = gyr[2] - imu_dev->gyr_offset[2];

    gyr_cor[0] = imu_dev->gyr_rotation[0][0] * temp[0] + imu_dev->gyr_rotation[0][1] * temp[1] + imu_dev->gyr_rotation[0][2] * temp[2];
    gyr_cor[1] = imu_dev->gyr_rotation[1][0] * temp[0] + imu_dev->gyr_rotation[1][1] * temp[1] + imu_dev->gyr_rotation[1][2] * temp[2];
    gyr_cor[2] = imu_dev->gyr_rotation[2][0] * temp[0] + imu_dev->gyr_rotation[2][1] * temp[1] + imu_dev->gyr_rotation[2][2] * temp[2];
}

/**************************	ACC API	**************************/

fmt_err sensor_acc_raw_measure(sensor_imu_t imu_dev, int16_t acc[3])
{
    rt_size_t r_size;

    if (imu_dev == NULL || imu_dev->acc_dev == NULL) {
        return FMT_EEMPTY;
    }

    r_size = rt_device_read(imu_dev->acc_dev, ACCEL_RD_RAW, (void*)acc, 6);

    return r_size == 6 ? FMT_EOK : FMT_ERROR;
}

// unit: m/s2
fmt_err sensor_acc_measure(sensor_imu_t imu_dev, float acc[3])
{
    rt_size_t r_size;

    if (imu_dev == NULL || imu_dev->acc_dev == NULL) {
        return FMT_EEMPTY;
    }

    r_size = rt_device_read(imu_dev->acc_dev, ACCEL_RD_SCALE, (void*)acc, 12);

    return r_size == 12 ? FMT_EOK : FMT_ERROR;
}

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

void sensor_acc_set_offset(sensor_imu_t imu_dev, const float offset[3])
{
    imu_dev->acc_offset[0] = offset[0];
    imu_dev->acc_offset[1] = offset[1];
    imu_dev->acc_offset[2] = offset[2];
}

void sensor_acc_correct(sensor_imu_t imu_dev, const float acc[3], float acc_cor[3])
{
    float temp[3];

    temp[0] = acc[0] - imu_dev->acc_offset[0];
    temp[1] = acc[1] - imu_dev->acc_offset[1];
    temp[2] = acc[2] - imu_dev->acc_offset[2];

    acc_cor[0] = imu_dev->acc_rotation[0][0] * temp[0] + imu_dev->acc_rotation[0][1] * temp[1] + imu_dev->acc_rotation[0][2] * temp[2];
    acc_cor[1] = imu_dev->acc_rotation[1][0] * temp[0] + imu_dev->acc_rotation[1][1] * temp[1] + imu_dev->acc_rotation[1][2] * temp[2];
    acc_cor[2] = imu_dev->acc_rotation[2][0] * temp[0] + imu_dev->acc_rotation[2][1] * temp[1] + imu_dev->acc_rotation[2][2] * temp[2];
}

sensor_imu_t sensor_imu_init(const char* gyr_dev_name, const char* acc_dev_name)
{
    sensor_imu_t imu_dev = (sensor_imu_t)rt_malloc(sizeof(struct sensor_imu));

    if (imu_dev == NULL) {
        return imu_dev;
    }

    if (gyr_dev_name) {
        imu_dev->gyr_dev = rt_device_find(gyr_dev_name);
        if (imu_dev->gyr_dev == NULL) {
            goto err;
        }
        if (rt_device_open(imu_dev->gyr_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
            goto err;
        }
    }

    if (acc_dev_name) {
        imu_dev->acc_dev = rt_device_find(acc_dev_name);
        if (imu_dev->acc_dev == NULL) {
            goto err;
        }
        if (rt_device_open(imu_dev->acc_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
            goto err;
        }
    }

    return imu_dev;
err:
    rt_free(imu_dev);
    return NULL;
}
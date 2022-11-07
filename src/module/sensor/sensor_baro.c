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
#include "module/sensor/sensor_baro.h"
#include "hal/barometer/barometer.h"

/**
 * @brief Check if barometer data is ready to read
 * 
 * @param baro_dev Barometer sensor device
 * @return uint8_t 1:ready 0:not-ready
 */
uint8_t sensor_baro_check_ready(sensor_baro_t baro_dev)
{
    uint8_t ready = 0;

    rt_device_control(baro_dev->dev, BARO_CMD_CHECK_READY, &ready);

    return ready;
}

/**
 * @brief Read barometer data
 * 
 * @param baro_dev Barometer sensor device
 * @param baro_data Barometer data buffer
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t sensor_baro_read(sensor_baro_t baro_dev, baro_data_t* baro_data)
{
    baro_report_t report;
    if (rt_device_read(baro_dev->dev, BARO_RD_REPORT, &report, sizeof(baro_report_t)) != sizeof(baro_report_t)) {
        return FMT_ERROR;
    }

    baro_data->temperature_deg = report.temperature_deg;
    baro_data->pressure_pa = report.pressure_Pa;
    baro_data->altitude_m = report.altitude_m;
    baro_data->timestamp_ms = report.timestamp_ms;

    return FMT_EOK;
}

/**
 * @brief Initialize barometer sensor device
 * 
 * @param baro_dev_name Barometer device name
 * @return sensor_baro_t Barometer sensor device
 */
sensor_baro_t sensor_baro_init(const char* baro_dev_name)
{
    sensor_baro_t baro_dev = (sensor_baro_t)rt_malloc(sizeof(struct sensor_baro));
    RT_ASSERT(baro_dev != NULL);

    /* find baro device */
    baro_dev->dev = rt_device_find(baro_dev_name);
    RT_ASSERT(baro_dev->dev != NULL);

    /* open device */
    RT_CHECK(rt_device_open(baro_dev->dev, RT_DEVICE_OFLAG_RDWR));

    return baro_dev;
}
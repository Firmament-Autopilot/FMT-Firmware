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
#include "module/sensor/sensor_gps.h"
#include "hal/gps/gps.h"

/**
 * @brief Check if gps data is ready to read
 * 
 * @param gps_dev GPS sensor device
 * @return uint8_t 1:ready 0:not-ready
 */
uint8_t sensor_gps_check_ready(sensor_gps_t gps_dev)
{
    uint8_t ready = 0;

    rt_device_control(gps_dev->dev, GPS_CMD_CHECK_READY, &ready);

    return ready;
}

/**
 * @brief Read gps data
 * 
 * @param gps_dev GPS sensor device
 * @param gps_data GPS data buffer
 * @return fmt_err_t FMT_EOK for success
 */
fmt_err_t sensor_gps_read(sensor_gps_t gps_dev, gps_data_t* gps_data)
{
    gps_report_t gps_drv_report;
    rt_size_t r_size = rt_device_read(gps_dev->dev, GPS_READ_REPORT, &gps_drv_report, sizeof(gps_report_t));

    gps_data->timestamp_ms = gps_drv_report.timestamp_velocity;
    gps_data->fixType = gps_drv_report.fix_type;
    gps_data->numSV = gps_drv_report.satellites_used;
    gps_data->lon = gps_drv_report.lon;
    gps_data->lat = gps_drv_report.lat;
    gps_data->height = gps_drv_report.alt;
    gps_data->hAcc = gps_drv_report.eph;
    gps_data->vAcc = gps_drv_report.epv;
    gps_data->velN = gps_drv_report.vel_n_m_s;
    gps_data->velE = gps_drv_report.vel_e_m_s;
    gps_data->velD = gps_drv_report.vel_d_m_s;
    gps_data->vel = gps_drv_report.vel_m_s;
    gps_data->cog = gps_drv_report.cog_rad;
    gps_data->sAcc = gps_drv_report.s_variance_m_s;

    return (r_size == sizeof(gps_report_t)) ? FMT_EOK : FMT_ERROR;
}

/**
 * @brief Initialize gps sensor device
 * 
 * @param gps_dev_name GPS device name
 * @return sensor_gps_t GPS sensor device
 */
sensor_gps_t sensor_gps_init(const char* gps_dev_name)
{
    sensor_gps_t gps_dev = (sensor_gps_t)rt_malloc(sizeof(struct sensor_gps));
    RT_ASSERT(gps_dev != NULL);

    /* find sensor device */
    gps_dev->dev = rt_device_find(gps_dev_name);
    RT_ASSERT(gps_dev->dev != NULL);

    /* open device */
    RT_CHECK(rt_device_open(gps_dev->dev, RT_DEVICE_OFLAG_RDWR));

    return gps_dev;
}
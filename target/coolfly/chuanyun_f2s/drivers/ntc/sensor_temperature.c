/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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

#include "board.h"
#include <board_device.h>
#include <firmament.h>

#include "hal_temperature.h"
#include "sensor_temperature.h"

static sensor_temperature_t temperature_dev = NULL;
MCN_DEFINE(sensor_temperature, sizeof(temperature_data_t));

/**
 * @brief Measure temperature data
 *
 * @param airspeed_dev Airspeed sensor device
 * @param airspeed_report Airspeed data buffer
 * @return fmt_err_t FMT_EOK for success
 */
_EXT_DTCM1
fmt_err_t sensor_temperature_measure(sensor_temperature_t temperature_dev, temperature_data_t* temp_report)
{
    rt_size_t            r_size;
    temperature_report_t report;

    RT_ASSERT(temperature_dev != NULL);

    r_size = rt_device_read(temperature_dev->dev, 9, &report, sizeof(temperature_data_t));

    temp_report->timestamp_ms    = report.timestamp_ms;
    temp_report->temperature_deg = report.temperature_deg;

    return r_size == sizeof(temperature_data_t) ? FMT_EOK : FMT_ERROR;
}

/**
 * @brief Initialize temperature sensor device
 *
 * @param temp_dev_name temperature device name
 * @return sensor_temperature_t temperature sensor device
 */
_EXT_DTCM1
sensor_temperature_t sensor_temperature_init(const char* temperature_dev_name)
{
    sensor_temperature_t temperature_dev = (sensor_temperature_t)rt_malloc(sizeof(struct sensor_temperature));
    RT_ASSERT(temperature_dev != NULL);

    /* find temperature device */
    temperature_dev->dev = rt_device_find(temperature_dev_name);
    RT_ASSERT(temperature_dev->dev != NULL);

    /* open device */
    RT_CHECK(rt_device_open(temperature_dev->dev, RT_DEVICE_OFLAG_RDWR));

    return temperature_dev;
}

_EXT_DTCM1
static int echo_sensor_temperature(void* param)
{
    fmt_err_t          err;
    temperature_data_t temperature_report;

    err = mcn_copy_from_hub((McnHub*)param, &temperature_report);

    if (err != FMT_EOK) {
        return -1;
    }

    console_printf("timestamp:%u temperature:%f\n",
                   temperature_report.timestamp_ms,
                   temperature_report.temperature_deg);

    return 0;
}

/**
 * @brief Advertise sensor temperature topic
 *
 * @param id sensor topic
 * @return fmt_err_t FMT_EOK for success
 */
_EXT_DTCM1
fmt_err_t advertise_sensor_temperature(uint8_t id)
{
    switch (id) {
    case 0:
        FMT_TRY(mcn_advertise(MCN_HUB(sensor_temperature), echo_sensor_temperature));
        break;
    default:
        return FMT_EINVAL;
    }

    return FMT_EOK;
}

/**
 * @brief Register temperature sensor
 *
 * @param dev_name temperature device name
 * @return fmt_err_t FMT_EOK for success
 */
_EXT_DTCM1
fmt_err_t register_sensor_temperature(const char* dev_name, uint8_t id)
{
    temperature_dev = sensor_temperature_init(dev_name);
    if (temperature_dev == NULL) {
        return FMT_ERROR;
    }

    return advertise_sensor_temperature(id);
}

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

#include "module/sensor/sensor_gps.h"
#include "driver/gps.h"

static rt_device_t _gps_device_t;
struct vehicle_gps_position_s _gps_position;

fmt_err sensor_gps_get_report(GPS_Report* gps_report)
{
	rt_size_t r_size = rt_device_read(_gps_device_t, RD_COMPLETED_REPORT, &_gps_position, sizeof(_gps_position));

	gps_report->timestamp_ms = _gps_position.timestamp_velocity;
	gps_report->fixType = _gps_position.fix_type;
	gps_report->numSV = _gps_position.satellites_used;
	gps_report->lon = _gps_position.lon;
	gps_report->lat = _gps_position.lat;
	gps_report->height = _gps_position.alt;
	gps_report->hAcc = _gps_position.eph;
	gps_report->vAcc = _gps_position.epv;
	gps_report->velN = _gps_position.vel_n_m_s;
	gps_report->velE = _gps_position.vel_e_m_s;
	gps_report->velD = _gps_position.vel_d_m_s;
	gps_report->sAcc = _gps_position.s_variance_m_s;

	return (r_size == sizeof(_gps_position)) ? FMT_EOK : FMT_ERROR;
}

uint8_t sensor_gps_report_ready(void)
{
	uint8_t ready;

	rt_device_read(_gps_device_t, GPS_REPORT_READY, &ready, 1);

	return ready;
}

fmt_err sensor_gps_init(void)
{
	rt_err_t err;

	/* find sensor device */
	_gps_device_t = rt_device_find("gps");

	if(_gps_device_t == RT_NULL) {
		console_printf("can't find gps device\r\n");
		return FMT_ERROR;
	}

	/* open device */
	err = rt_device_open(_gps_device_t, RT_DEVICE_OFLAG_RDWR);

	if(err != RT_EOK) {
		return FMT_ERROR;
	}

	return FMT_EOK;
}
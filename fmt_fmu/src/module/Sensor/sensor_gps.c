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
// #include "driver/gps.h"
#include "hal/gps.h"

static rt_device_t _gps_device_t;
static gps_report_t _gps_report;

fmt_err sensor_gps_get_report(GPS_Report* gps_report)
{
	rt_size_t r_size = rt_device_read(_gps_device_t, GPS_READ_REPORT, &_gps_report, sizeof(gps_report_t));

	gps_report->timestamp_ms = _gps_report.timestamp_velocity;
	gps_report->fixType = _gps_report.fix_type;
	gps_report->numSV = _gps_report.satellites_used;
	gps_report->lon = _gps_report.lon;
	gps_report->lat = _gps_report.lat;
	gps_report->height = _gps_report.alt;
	gps_report->hAcc = _gps_report.eph;
	gps_report->vAcc = _gps_report.epv;
	gps_report->velN = _gps_report.vel_n_m_s;
	gps_report->velE = _gps_report.vel_e_m_s;
	gps_report->velD = _gps_report.vel_d_m_s;
	gps_report->sAcc = _gps_report.s_variance_m_s;

	return (r_size == sizeof(gps_report_t)) ? FMT_EOK : FMT_ERROR;
}

uint8_t sensor_gps_report_ready(void)
{
	uint8_t ready = 0;

	// rt_device_read(_gps_device_t, GPS_REPORT_READY, &ready, 1);

    rt_device_control(_gps_device_t, GPS_CMD_CHECK_UPDATE, &ready);

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
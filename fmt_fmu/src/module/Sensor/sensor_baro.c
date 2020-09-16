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

#include "module/sensor/sensor_baro.h"
#include "hal/barometer.h"

static rt_device_t _baro_device_t;

uint8_t sensor_baro_check_update(void)
{
	uint8_t update = 0;

	rt_device_control(_baro_device_t, BARO_CMD_CHECK_UPDATE, &update);

	return update;
}

fmt_err sensor_baro_update(void)
{
    return rt_device_control(_baro_device_t, BARO_CMD_UPDATE, NULL) == RT_EOK ? FMT_EOK : FMT_ERROR;
}

fmt_err sensor_baro_get_report(baro_report_t* report)
{
	if(rt_device_read(_baro_device_t, BARO_RD_REPORT, report, sizeof(baro_report_t))) {
		return FMT_EOK;
	}

	return FMT_ERROR;
}

fmt_err sensor_baro_init(void)
{
	rt_err_t res = RT_EOK;

	/* find baro device */
	_baro_device_t = rt_device_find("barometer");

	if(_baro_device_t == RT_NULL) {
		console_printf("can't find barometer device\r\n");
		res |= RT_EEMPTY;
	}

	/* open device */
	res |= rt_device_open(_baro_device_t, RT_DEVICE_OFLAG_RDWR);

	return FMT_EOK;
}
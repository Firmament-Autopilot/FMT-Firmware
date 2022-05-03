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
#include "hal/barometer/barometer.h"

static rt_err_t hal_baro_init(struct rt_device* dev)
{
	rt_err_t ret = RT_EOK;
	baro_dev_t baro;

	RT_ASSERT(dev != RT_NULL);
	baro = (baro_dev_t)dev;

	/* apply configuration */
	if(baro->ops->baro_config) {
		ret = baro->ops->baro_config(baro, &baro->config);
	}

	return ret;
}

static rt_size_t hal_baro_read(struct rt_device* dev,
                               rt_off_t          pos,
                               void*             buffer,
                               rt_size_t         size)
{
	rt_size_t rb = 0;
	baro_dev_t baro;

	RT_ASSERT(dev != RT_NULL);
	RT_ASSERT(buffer != RT_NULL);

	baro = (baro_dev_t)dev;

	if(pos == BARO_RD_REPORT && baro->ops->baro_read) {
		rb = baro->ops->baro_read(baro, buffer);
	}

	return rb;
}

static rt_err_t hal_baro_control(struct rt_device*  dev,
                                 int               cmd,
                                 void*             args)
{
	rt_err_t ret = RT_EOK;
	baro_dev_t baro;

	RT_ASSERT(dev != RT_NULL);

	baro = (baro_dev_t)dev;

	if(baro->ops->baro_control) {
		ret = baro->ops->baro_control(baro, cmd, args);
	}

	return ret;
}

rt_err_t hal_baro_register(baro_dev_t baro, const char* name, rt_uint32_t flag, void* data)
{
	rt_err_t ret;
	struct rt_device* device;

	RT_ASSERT(baro != RT_NULL);

	device = &(baro->parent);

	device->type        = RT_Device_Class_SPIDevice;
	device->ref_count   = 0;
	device->rx_indicate = RT_NULL;
	device->tx_complete = RT_NULL;

	device->init        = hal_baro_init;
	device->open        = RT_NULL;
	device->close       = RT_NULL;
	device->read        = hal_baro_read;
	device->write       = RT_NULL;
	device->control     = hal_baro_control;
	device->user_data   = data;

	/* register a character device */
	ret = rt_device_register(device, name, flag);

	return ret;
}
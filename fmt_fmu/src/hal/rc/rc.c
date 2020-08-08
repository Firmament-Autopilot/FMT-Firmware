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
#include "hal/rc.h"

static rt_err_t hal_rc_init(struct rt_device* dev)
{
	rt_err_t ret = RT_EOK;
	rc_dev_t rc;

	RT_ASSERT(dev != RT_NULL);

	rc = (rc_dev_t)dev;

	/* apply configuration */
	if(rc->ops->rc_configure) {
		ret = rc->ops->rc_configure(rc, &rc->config);
	}

	return ret;
}

static rt_size_t hal_rc_read(struct rt_device* dev, rt_off_t pos, void* buffer, rt_size_t size)
{
	rt_size_t rb = 0;
	rc_dev_t rc;

	RT_ASSERT(dev != RT_NULL);

	rc = (rc_dev_t)dev;

	if(rc->ops->rc_read && buffer) {
		rc->ops->rc_read(rc, (uint16_t)pos, buffer);
		rb = size;
	}

	return rb;
}

static rt_err_t hal_rc_control(struct rt_device* dev, int cmd, void* args)
{
	rc_dev_t rc;

	RT_ASSERT(dev != RT_NULL);

	rc = (rc_dev_t)dev;

	if(rc->ops->rc_control) {
		return rc->ops->rc_control(rc, cmd, args);
	}

	return RT_EOK;
}

rt_err_t hal_rc_rx_ind(rc_dev_t rc, rt_size_t size)
{
	rt_device_t device = &(rc->parent);

	if(device->rx_indicate) {
		return device->rx_indicate(device, size);
	}

	return RT_EOK;
}

rt_err_t hal_rc_register(rc_dev_t rc, const char* name, rt_uint32_t flag, void* data)
{
	struct rt_device* device;

	RT_ASSERT(rc != RT_NULL);

	device = &(rc->parent);

	device->type        = RT_Device_Class_Miscellaneous;
	device->ref_count   = 0;
	device->rx_indicate = RT_NULL;
	device->tx_complete = RT_NULL;

	device->init        = hal_rc_init;
	device->open        = RT_NULL;
	device->close       = RT_NULL;
	device->read        = hal_rc_read;
	device->write       = RT_NULL;
	device->control     = hal_rc_control;

	device->user_data   = data;

	if(rc->channel_num > MAX_RC_CHANNEL_NUM) {
		rc->channel_num = MAX_RC_CHANNEL_NUM;
	}

	/* register pin device */
	return rt_device_register(device, name, flag);
}

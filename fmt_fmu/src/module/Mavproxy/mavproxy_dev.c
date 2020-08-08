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
#include <string.h>
#include "shell.h"

#include "task/task_comm.h"
#include "module/mavproxy/mavcmd.h"
#include "hal/cdcacm.h"
#include "hal/cdcacm.h"


#define MAVPROXY_DEV_CHAN_NUM       2

static rt_device_t _mavproxy_dev = RT_NULL;
static rt_sem_t _mavproxy_dev_rx_sem, _mavproxy_dev_tx_sem;
static uint8_t _dev_chan;

static char chan_device[MAVPROXY_DEV_CHAN_NUM][10] = {
	{MAVPROXY_CHAN1_DEVICE_NAME},
	{MAVPROXY_CHAN2_DEVICE_NAME},
};

fmt_err(*_mav_rx_indicate)(uint32_t size);

rt_err_t mavproxy_dev_tx_done(rt_device_t dev, void* buffer)
{
	return rt_sem_release(_mavproxy_dev_tx_sem);
}

rt_err_t mavproxy_dev_rx_ind(rt_device_t dev, rt_size_t size)
{
	rt_err_t rt_err;
	rt_err = rt_sem_release(_mavproxy_dev_rx_sem);

	if(_mav_rx_indicate) {
		_mav_rx_indicate(size);
	}

	return rt_err;
}

static int device_switch(char* dev_name)
{
	rt_device_t new_dev;

	new_dev = rt_device_find(dev_name);

	if(new_dev == RT_NULL) {
		return 1;
	}

	if(rt_device_open(new_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX
	                  | RT_DEVICE_FLAG_DMA_TX) != RT_EOK) {
		console_printf("mavproxy device open fail\n");
		return 1;
	}

	/* set callback functions */
	rt_device_set_tx_complete(new_dev, mavproxy_dev_tx_done);
	rt_device_set_rx_indicate(new_dev, mavproxy_dev_rx_ind);

	if(_mavproxy_dev) {
		/* close old device */
		rt_device_close(_mavproxy_dev);
	}

	_mavproxy_dev = new_dev;

	return 0;
}

static int switch_chan_if_needed(uint8_t new_chan)
{
	if(new_chan != _dev_chan && new_chan < MAVPROXY_DEV_CHAN_NUM) {
		if(device_switch(chan_device[new_chan]) == 0) {
			_dev_chan = new_chan;
			return 1;
		}
	}

	return 0;
}

uint8_t mavproxy_dev_used_channel(void)
{
	return _dev_chan;
}

rt_size_t mavproxy_dev_sync_write(uint8_t chan, const void* buffer, uint32_t len)
{
	rt_size_t size;

	switch_chan_if_needed(chan);

	/* write data to device */
	OS_ENTER_CRITICAL;
	size = rt_device_write(_mavproxy_dev, 0, buffer, len);
	OS_EXIT_CRITICAL;

	/* wait write complete (synchronized write) */
	rt_sem_take(_mavproxy_dev_tx_sem, RT_WAITING_FOREVER);

	return size;
}

rt_size_t mavproxy_dev_sync_read(uint8_t chan, void* buffer, uint32_t len)
{
	rt_size_t cnt = 0;

	switch_chan_if_needed(chan);

	/* try to read data */
	OS_ENTER_CRITICAL;
	cnt = rt_device_read(_mavproxy_dev, 0, buffer, len);
	OS_EXIT_CRITICAL;

	/* if not enough data reveived, wait it */
	while(cnt < len) {
		/* wait until something reveived (synchronized read) */
		rt_sem_take(_mavproxy_dev_rx_sem, RT_WAITING_FOREVER);
		/* read rest data */
		OS_ENTER_CRITICAL;
		cnt += rt_device_read(_mavproxy_dev, 0, (void*)((uint32_t)buffer + cnt), len - cnt);
		OS_EXIT_CRITICAL;
	}

	return len;
}

rt_size_t mavproxy_dev_read(uint8_t chan, void* buffer, uint32_t len, int32_t timeout)
{
	rt_size_t cnt = 0;

	switch_chan_if_needed(chan);

	/* try to read data */
	cnt = rt_device_read(_mavproxy_dev, 0, buffer, len);

	/* sync mode */
	if(timeout != 0) {
		/* if not enough data reveived, wait it */
		while(cnt < len) {
			rt_err_t rt_err;
			/* wait until something reveived (synchronized read) */
			rt_err = rt_sem_take(_mavproxy_dev_rx_sem, timeout);

			if(rt_err != RT_EOK)
				break;

			/* read rest data */
			cnt += rt_device_read(_mavproxy_dev, 0, (void*)((uint32_t)buffer + cnt), len - cnt);
		}
	}

	return cnt;
}

void mavproxy_dev_set_rx_indicate(fmt_err(*rx_ind)(uint32_t size))
{
	_mav_rx_indicate = rx_ind;
}

int mavproxy_dev_init(uint8_t chan)
{
	if(chan >= MAVPROXY_DEV_CHAN_NUM) {
		console_printf("illegal device channel\n");
		return 1;
	}

	_dev_chan = chan;

	_mavproxy_dev = rt_device_find(chan_device[_dev_chan]);

	if(_mavproxy_dev == RT_NULL) {
		console_printf("err, can not find %d device\n", chan_device[_dev_chan]);
		return 1;
	}

	if(rt_device_open(_mavproxy_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_DMA_RX
	                  | RT_DEVICE_FLAG_DMA_TX) != RT_EOK) {
		console_printf("mavproxy device open fail\n");
		return 1;
	}

	_mavproxy_dev_rx_sem = rt_sem_create("mavdev_rx_sem", 0, RT_IPC_FLAG_FIFO);
	_mavproxy_dev_tx_sem = rt_sem_create("mavdev_tx_sem", 0, RT_IPC_FLAG_FIFO);

	if(_mavproxy_dev_rx_sem == RT_NULL || _mavproxy_dev_tx_sem == RT_NULL) {
		console_printf("mavproxy rx/tx sem create fail\n");
		return 1;
	}

	/* set callback functions */
	rt_device_set_tx_complete(_mavproxy_dev, mavproxy_dev_tx_done);
	rt_device_set_rx_indicate(_mavproxy_dev, mavproxy_dev_rx_ind);

	return 0;
}
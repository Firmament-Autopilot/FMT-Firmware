/******************************************************************************
 * Copyright 2020-2023 The Firmament Authors. All Rights Reserved.
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

#include "hal/usb/usbd_cdc.h"
#include "module/utils/devmq.h"

#define USBD_WAIT_TIMEOUT 1000
#define USBD_RX_FIFO_SIZE 2048

static rt_err_t hal_usbd_cdc_init(rt_device_t dev)
{
    usbd_cdc_dev_t usbd = (usbd_cdc_dev_t)dev;
    rt_err_t err = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    usbd->rx_rb = ringbuffer_create(USBD_RX_FIFO_SIZE);
    if (usbd->rx_rb == NULL) {
        return FMT_ENOMEM;
    }

    usbd->tx_lock = rt_mutex_create("usbd_tx", RT_IPC_FLAG_FIFO);
    if (usbd->tx_lock == NULL) {
        return FMT_ENOMEM;
    }

    if (usbd->ops->dev_init) {
        err = usbd->ops->dev_init(usbd);
    }
    return err;
}

static rt_err_t hal_usbd_cdc_open(rt_device_t dev, rt_uint16_t oflag)
{
    RT_ASSERT(dev != RT_NULL);

    if ((dev->flag & oflag) != oflag) {
        return RT_EIO;
    }

    return RT_EOK;
}

static rt_size_t hal_usbd_cdc_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    usbd_cdc_dev_t usbd = (usbd_cdc_dev_t)dev;
    rt_size_t rb = 0;

    RT_ASSERT(dev != RT_NULL);

    if (usbd->ops->dev_read) {
        rb = usbd->ops->dev_read(usbd, pos, buffer, size);
    }

    return rb;
}

static rt_size_t hal_usbd_cdc_write(rt_device_t dev, rt_off_t pos, const void* buffer, rt_size_t size)
{
    usbd_cdc_dev_t usbd = (usbd_cdc_dev_t)dev;
    rt_size_t wb = 0;

    RT_ASSERT(dev != RT_NULL);

    if (usbd->status != USBD_STATUS_CONNECT) {
        return 0;
    }

    if (rt_mutex_take(usbd->tx_lock, TICKS_FROM_MS(USBD_WAIT_TIMEOUT)) != RT_EOK) {
        return 0;
    }

    if (usbd->ops->dev_write) {
        wb = usbd->ops->dev_write(usbd, pos, buffer, size);
    }

    /* wait until send is finished */
    rt_completion_wait(&usbd->tx_cplt, TICKS_FROM_MS(USBD_WAIT_TIMEOUT));

    rt_mutex_release(usbd->tx_lock);
    return wb;
}

/**
 * @brief notify the usbd status
 * 
 * @param usbd 
 * @param status 
 */
void hal_usbd_cdc_notify_status(usbd_cdc_dev_t usbd, int status)
{
    device_status dev_sta;

    switch (status) {
    case USBD_STATUS_DISCONNECT:
        usbd->status = USBD_STATUS_DISCONNECT;
        /* notify usb disconnect status */
        dev_sta = DEVICE_STAUTS_DISCONNECT;
        devmq_notify(&usbd->parent, &dev_sta);
        break;
    case USBD_STATUS_CONNECT:
        usbd->status = USBD_STATUS_CONNECT;
        /* notify usb connect status */
        dev_sta = DEVICE_STATUS_CONNECT;
        devmq_notify(&usbd->parent, &dev_sta);
        break;
    case USBD_STATUS_TX_COMPLETE:
        rt_completion_done(&usbd->tx_cplt);
        if (usbd->parent.tx_complete) {
            usbd->parent.tx_complete(&usbd->parent, RT_NULL);
        }
        break;
    case USBD_STATUS_RX:
        if (usbd->parent.rx_indicate) {
            usbd->parent.rx_indicate(&usbd->parent, ringbuffer_getlen(usbd->rx_rb));
        }
        break;
    default:
        break;
    }
}

/**
 * @brief register a usbd_cdc device
 * 
 * @param usbd usbd cdc device
 * @param name device name
 * @param flag device flag
 * @param data device data
 * @return rt_err_t RT_EOK for success
 */
rt_err_t hal_usbd_cdc_register(usbd_cdc_dev_t usbd, const char* name, rt_uint16_t flag, void* data)
{
    rt_device_t dev = &usbd->parent;

    dev->type = RT_Device_Class_USBDevice;
    dev->ref_count = 0;

    dev->rx_indicate = RT_NULL;
    dev->tx_complete = RT_NULL;

    dev->init = hal_usbd_cdc_init;
    dev->open = hal_usbd_cdc_open;
    dev->close = RT_NULL;
    dev->read = hal_usbd_cdc_read;
    dev->write = hal_usbd_cdc_write;
    dev->control = RT_NULL;

    dev->user_data = RT_NULL;

    if (rt_device_register(dev, name, flag) != RT_EOK) {
        return FMT_ERROR;
    }

    if (devmq_create(dev, sizeof(device_status), 5) != FMT_EOK) {
        return FMT_ERROR;
    }

    rt_completion_init(&usbd->tx_cplt);

    return FMT_EOK;
}
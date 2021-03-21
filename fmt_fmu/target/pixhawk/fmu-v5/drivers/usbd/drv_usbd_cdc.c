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
#include <firmament.h>

#include "drv_usbd_cdc.h"
#include "hal/usbd_cdc.h"

// extern USBD_HandleTypeDef hUsbDeviceFS;
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;

static struct usbd_cdc_dev usbd_dev;

// struct usbd_cdc_ops _usbd_cdc_ops = {
//     usbd_cdc_dev_write,
//     usbd_cdc_dev_read,
//     usbd_cdc_dev_init,
//     usbd_cdc_dev_ringbuf_put,
// };

void OTG_FS_IRQHandler(void)
{
    rt_interrupt_enter();

    HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_err_t usbd_cdc_init(usbd_cdc_dev_t usbd)
{
    MX_USB_DEVICE_Init();

    return RT_EOK;
}

static rt_size_t usbd_cdc_read(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t rb;

    RT_ASSERT(usbd->rx_rb != NULL);

    rb = ringbuffer_get(usbd->rx_rb, buf, size);
    return rb;
}

static rt_size_t usbd_cdc_write(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size)
{
    if (CDC_Transmit_FS((uint8_t*)buf, size) != USBD_OK) {
        return 0;
    }
    return size;
}

void drv_usbd_cdc_connect_cb(PCD_HandleTypeDef *hpcd)
{
    if(hpcd == &hpcd_USB_OTG_FS){
        hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);
    }
}

void drv_usbd_cdc_disconnect_cb(PCD_HandleTypeDef *hpcd)
{
    if(hpcd == &hpcd_USB_OTG_FS){
        hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);
    }
}

void drv_usbd_cdc_receive(uint8_t* buffer, uint32_t size)
{
    (void)ringbuffer_put(usbd_dev.rx_rb, buffer, size);
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_RX);
}

void drv_usbd_cdc_transmist_complete(uint8_t* buffer, uint32_t size)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_TX_COMPLETE);
}

// static rt_err_t usbd_cdc_dev_init(rt_device_t device)
// {
//     uint16_t rx_buf_size = 0;
//     rx_buf_size = sizeof(uint8_t) * USBD_CDC_RX_BUFSIZE;

//     usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

//     MX_USB_DEVICE_Init();

//     /*waiting for USBD init in USBD USBD_IRQ_HANDLER . the hcdc->TxState pointor */
//     uint8_t wait_count = 0;
//     while (hUsbDeviceFS.pClassData == 0x0) {
//         rt_thread_delay(1); /* in release version ,must add delay. */
//         wait_count++;
//         if (wait_count == 1000)
//             return RT_ERROR;
//     }

//     USBD_CDC_HandleTypeDef* hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

//     dev->connect_status = &(hUsbDeviceFS.dev_connection_status);
//     dev->tx_stutus = &(hcdc->TxState);
//     dev->rx_status = &(hcdc->RxState);

//     dev->rx_ringbuf = ringbuffer_create(rx_buf_size);

//     dev->ops = &_usbd_cdc_ops;

//     return RT_EOK;
// }

// static rt_size_t usbd_cdc_dev_ringbuf_put(rt_device_t device, uint8_t* Buf, uint32_t* Len) /*usbd cdc receive call back*/
// {
//     rt_size_t res;

//     usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

//     res = ringbuffer_put(dev->rx_ringbuf, Buf, *Len);

//     return res;
// }

struct usbd_cdc_ops usbd_ops = {
    .dev_init = usbd_cdc_init,
    .dev_read = usbd_cdc_read,
    .dev_write = usbd_cdc_write,
    .dev_control = NULL
};

rt_err_t drv_usb_cdc_init(void)
{
    usbd_dev.ops = &usbd_ops;

    return hal_usbd_cdc_register(&usbd_dev, "usbd0",
        RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX, RT_NULL);
}
/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-04-10     ZYH          first version
 * 2019-10-27     flybreak     Compatible with the HS
 */

#include <firmament.h>
#include <rtdevice.h>

#include "drv_usbd_cdc.h"
#include "hal/usbd_cdc.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;

static rt_err_t  usbd_cdc_dev_init(rt_device_t device);
static rt_size_t usbd_cdc_dev_read(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size);
static rt_err_t  usbd_cdc_dev_write(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size);
static rt_size_t usbd_cdc_dev_ringbuf_put(rt_device_t device,uint8_t* Buf, uint32_t *Len);

struct usbd_cdc_ops _usbd_cdc_ops = {
    usbd_cdc_dev_write,
    usbd_cdc_dev_read,
    usbd_cdc_dev_init,
    usbd_cdc_dev_ringbuf_put,
};

void OTG_FS_IRQHandler(void)
{
    rt_interrupt_enter();

    HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
    /* leave interrupt */
    rt_interrupt_leave();
}

static rt_size_t usbd_cdc_dev_read(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size)
{
    usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

	return ringbuffer_get(dev->rx_ringbuf, buf, size);
}

static rt_err_t usbd_cdc_dev_write(rt_device_t device, rt_off_t pos, void* buf, rt_size_t size)
{ 
    usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

    if ((*(dev->connect_status) == 1) && (hUsbDeviceFS.pClassData != NULL)){
        return CDC_Transmit_FS((uint8_t *)buf, size);
    }else{
        return RT_ERROR;
    }    
}

static rt_err_t usbd_cdc_dev_init(rt_device_t device)
{
    uint16_t rx_buf_size = 0;
    rx_buf_size = sizeof(uint8_t)*USBD_CDC_RX_BUFSIZE;

    usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

    MX_USB_DEVICE_Init();

    /*waiting for USBD init in USBD USBD_IRQ_HANDLER . the hcdc->TxState pointor */
    uint8_t wait_count = 0;
    while(hUsbDeviceFS.pClassData == 0x0){
        rt_thread_delay(1); /* in release version ,must add delay. */
        wait_count++;
        if(wait_count == 1000) return RT_ERROR;
    }   

    USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;

    dev->connect_status = &(hUsbDeviceFS.dev_connection_status);
    dev->tx_stutus      = &(hcdc->TxState);
    dev->rx_status      = &(hcdc->RxState);

    dev->rx_ringbuf = ringbuffer_create(rx_buf_size);

    dev->ops = &_usbd_cdc_ops;

    return RT_EOK;
}

static rt_size_t  usbd_cdc_dev_ringbuf_put(rt_device_t device,uint8_t* Buf, uint32_t *Len) /*usbd cdc receive call back*/
{ 
    rt_size_t res;

    usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

    res = ringbuffer_put(dev->rx_ringbuf,Buf,*Len);

    return res;
}

struct usbd_cdc_dev usbd_cdc_device;
rt_err_t drv_usb_cdc_init(void)
{
    usbd_cdc_dev_t usbd_cdc_device_t = &usbd_cdc_device;

    usbd_cdc_device_t->ops = &_usbd_cdc_ops;

    uint32_t flag =RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX;

    return hal_usbd_cdc_register(usbd_cdc_device_t, "usbd0", flag, RT_NULL);
}
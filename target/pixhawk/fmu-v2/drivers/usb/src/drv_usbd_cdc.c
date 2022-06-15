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
#include "hal/usb/usbd_cdc.h"
#include "usb_dcd_int.h"
#include "usbd_cdc_core_loopback.h"
#include "usbd_cdc_vcp.h"
#include "usbd_desc.h"
#include "usbd_usr.h"

__ALIGN_BEGIN USB_OTG_CORE_HANDLE USB_OTG_dev __ALIGN_END;

static struct usbd_cdc_dev usbd_dev = { 0 };
static uint8_t rx_buffer[10 * RX_FIFO_FS_SIZE];

/**
  * @brief  This function handles OTG_HS Handler.
  * @param  None
  * @retval None
  */
#ifdef USE_USB_OTG_HS
void OTG_HS_IRQHandler(void)
#else
void OTG_FS_IRQHandler(void)
#endif
{
    /* enter interrupt */
    rt_interrupt_enter();

    USBD_OTG_ISR_Handler(&USB_OTG_dev);

    /* leave interrupt */
    rt_interrupt_leave();
}

#ifdef USB_OTG_HS_DEDICATED_EP1_ENABLED
/**
  * @brief  This function handles EP1_IN Handler.
  * @param  None
  * @retval None
  */
void OTG_HS_EP1_IN_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    USBD_OTG_EP1IN_ISR_Handler(&USB_OTG_dev);

    /* leave interrupt */
    rt_interrupt_leave();
}

/**
  * @brief  This function handles EP1_OUT Handler.
  * @param  None
  * @retval None
  */
void OTG_HS_EP1_OUT_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();

    USBD_OTG_EP1OUT_ISR_Handler(&USB_OTG_dev);

    /* leave interrupt */
    rt_interrupt_leave();
}
#endif

static rt_size_t usbd_cdc_read(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t rb;

    RT_ASSERT(usbd->rx_rb != NULL);

    rb = ringbuffer_get(usbd->rx_rb, buf, size);
    return rb;
}

static rt_size_t usbd_cdc_write(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size)
{
    if (DCD_EP_Tx(&USB_OTG_dev, CDC_IN_EP, (uint8_t*)buf, size) != USBD_OK) {
        return 0;
    }
    return size;
}

static uint16_t drv_usbd_cdc_tx_cplt_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_TX_COMPLETE);

    return USBD_OK;
}

static uint16_t drv_usbd_cdc_rx_cb(uint32_t Len)
{
    DCD_EP_PrepareRx(&USB_OTG_dev, CDC_OUT_EP, rx_buffer, Len);

    if (usbd_dev.rx_rb == NULL) {
        return 0;
    }

    (void)ringbuffer_put(usbd_dev.rx_rb, rx_buffer, Len);
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_RX);

    return USBD_OK;
}

CDC_IF_Prop_TypeDef VCP_fops = {
    drv_usbd_cdc_tx_cplt_cb,
    drv_usbd_cdc_rx_cb
};

void drv_usbd_cdc_connect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);
}

void drv_usbd_cdc_disconnect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);
}

struct usbd_cdc_ops usbd_ops = {
    .dev_init = NULL,
    .dev_read = usbd_cdc_read,
    .dev_write = usbd_cdc_write,
    .dev_control = NULL
};

rt_err_t drv_usb_cdc_init(void)
{
    rt_err_t err;
    usbd_dev.ops = &usbd_ops;

    err = hal_usbd_cdc_register(&usbd_dev, "usbd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX, RT_NULL);
    if (err != RT_EOK) {
        return err;
    }

    /* init usbd after devmq has been registered */
    USBD_Init(&USB_OTG_dev,
#ifdef USE_USB_OTG_HS
              USB_OTG_HS_CORE_ID,
#else
              USB_OTG_FS_CORE_ID,
#endif
              &USR_desc,
              &USBD_CDC_cb,
              &USR_cb);

    return RT_EOK;
}

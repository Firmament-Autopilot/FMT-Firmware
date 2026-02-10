/******************************************************************************
 * Copyright The Firmament Authors. All Rights Reserved.
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

#include "usb_dev_cdc_class.h"
#include "usb_dev_desc.h"
#include "usb_dev_user.h"

#include "hal/usb/usbd_cdc.h"
#include "module/utils/ringbuffer.h"

usb_core_instance usb_dev;
static struct usbd_cdc_dev usbd_dev;

void drv_usbd_cdc_transmist_complete(uint8_t* buffer, uint32_t size)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_TX_COMPLETE);
}

void drv_usbd_cdc_receive(uint8_t* buffer, uint32_t size)
{
    if (usbd_dev.rx_rb == NULL) {
        /* usbd is not initialized */
        return;
    }
    (void)ringbuffer_put(usbd_dev.rx_rb, buffer, size);
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_RX);
}

void drv_usbd_cdc_connect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_CONNECT);
    // printf("usb connect\n");
}

void drv_usbd_cdc_disconnect_cb(void)
{
    hal_usbd_cdc_notify_status(&usbd_dev, USBD_STATUS_DISCONNECT);
    // printf("usb disconnect\n");
}

static void usb_rcu_config(void)
{

    stc_usb_port_identify stcPortIdentify;
#if defined(USB_FS_MODE)
    stcPortIdentify.u8CoreID = USBFS_CORE_ID;
    stcPortIdentify.u8PhyType = USBHS_PHY_EMBED;
#elif defined(USB_HS_MODE) && (!defined(USB_HS_EXTERNAL_PHY))
    stcPortIdentify.u8CoreID = USBHS_CORE_ID;
    stcPortIdentify.u8PhyType = USBHS_PHY_EMBED;
#elif defined(USB_HS_MODE) && (defined(USB_HS_EXTERNAL_PHY))
    stcPortIdentify.u8CoreID = USBHS_CORE_ID;
    stcPortIdentify.u8PhyType = USBHS_PHY_EXT;
#endif
    usb_dev_init(&usb_dev, &stcPortIdentify, &user_desc, &class_cdc_cbk, &user_cb);
}
uint8_t tmp_buf_usb[64];

static rt_size_t usbd_cdc_read(usbd_cdc_dev_t usbd, rt_off_t pos, void* buf, rt_size_t size)
{
    rt_size_t rb;

    RT_ASSERT(usbd->rx_rb != NULL);

    rb = ringbuffer_get(usbd->rx_rb, buf, size);

    return rb;
}

static rt_size_t usbd_cdc_write(usbd_cdc_dev_t usbd, rt_off_t pos, const void* buf, rt_size_t size)
{
    uint32_t tx_size = size > APP_TX_DATA_SIZE ? APP_TX_DATA_SIZE : size;
    uint32_t tx_cnt = 0;
    const uint8_t* tx_buffer_ptr = buf;

    if(APP_Rx_ptr_in + tx_size < APP_TX_DATA_SIZE){
        memcpy(&usb_tx_buffer[APP_Rx_ptr_in], tx_buffer_ptr, size);

        OS_ENTER_CRITICAL;
        APP_Rx_ptr_in += tx_size;
        if(APP_Rx_ptr_in >= APP_TX_DATA_SIZE) {
            APP_Rx_ptr_in = 0;
        }
    }else{
        memcpy(&usb_tx_buffer[APP_Rx_ptr_in], tx_buffer_ptr, APP_TX_DATA_SIZE - APP_Rx_ptr_in);
        tx_cnt += APP_TX_DATA_SIZE - APP_Rx_ptr_in;
        memcpy(usb_tx_buffer, &tx_buffer_ptr[tx_cnt], tx_size - tx_cnt);

        OS_ENTER_CRITICAL;
        APP_Rx_ptr_in = (APP_Rx_ptr_in + tx_size) % APP_TX_DATA_SIZE;
    }
    OS_EXIT_CRITICAL;

    return tx_size;
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

    usb_rcu_config();

    err = hal_usbd_cdc_register(&usbd_dev, "usbd0", RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX, RT_NULL);
    if (err != RT_EOK) {
        return err;
    }

    return RT_EOK;
}

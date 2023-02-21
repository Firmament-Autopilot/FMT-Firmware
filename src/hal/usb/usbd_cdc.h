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
#ifndef USBD_CDC_H__
#define USBD_CDC_H__

#include <firmament.h>

#include "module/utils/ringbuffer.h"

#ifdef __cplusplus
extern "C" {
#endif

#define USBD_CDC_TX_BUFSIZE 1280
#define USBD_CDC_RX_BUFSIZE 1280

#define USBD_STATUS_DISCONNECT  0
#define USBD_STATUS_CONNECT     1
#define USBD_STATUS_TX_COMPLETE 2
#define USBD_STATUS_RX          3

struct usbd_cdc_dev {
    struct rt_device parent;
    struct usbd_cdc_ops* ops;
    ringbuffer* rx_rb;
    struct rt_completion tx_cplt;
    rt_mutex_t tx_lock;
    int status;
};
typedef struct usbd_cdc_dev* usbd_cdc_dev_t;

/* usb driver operations */
struct usbd_cdc_ops {
    /**
     * @brief usb initialize
     * @param dev usb device
     */
    rt_err_t (*dev_init)(usbd_cdc_dev_t dev);
    /**
     * @brief usb read function
     * @param dev usb device
     * @param pos read position
     * @param buf read buffer
     * @param size read size
     */
    rt_size_t (*dev_read)(usbd_cdc_dev_t dev, rt_off_t pos, void* buf, rt_size_t size);
    /**
     * @brief usb write function
     * @param dev usb device
     * @param pos write position
     * @param buf write buffer
     * @param size write size
     */
    rt_size_t (*dev_write)(usbd_cdc_dev_t dev, rt_off_t pos, const void* buf, rt_size_t size);
    /**
     * @brief usb control function (optional)
     * @param dev usb device
     * @param cmd operation command
     * @param arg command argument
     */
    rt_err_t (*dev_control)(usbd_cdc_dev_t dev, int cmd, void* arg);
};

rt_err_t hal_usbd_cdc_register(usbd_cdc_dev_t usbd, const char* name, rt_uint16_t flag, void* data);
void hal_usbd_cdc_notify_status(usbd_cdc_dev_t usbd, int status);

#ifdef __cplusplus
}
#endif

#endif
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

#ifndef __CDCACM_H__
#define __CDCACM_H__

#include "usbd_cdc_core_loopback.h"
#include "usbd_cdc_vcp.h"
#include "usbd_desc.h"
#include "usbd_usr.h"
#include <firmament.h>

#define USB_DEVICE_NAME "usb"
#define USB_CMD_RECEIVE_CNT 0
#define USB_CMD_RECEIVE_FIN 1
#define USB_CMD_SEND_FIN 2

typedef struct {
    uint8_t connected;
} USB_Status;

extern USB_OTG_CORE_HANDLE USB_OTG_dev;

fmt_err usb_cdc_init(void);
void cdc_send_data(uint8_t* pbuf, uint32_t buf_len);
uint8_t cdc_receive_data(uint8_t* pbuf, uint32_t len);
uint8_t cdc_check_sent(void);
uint8_t cdc_check_receive(void);
uint32_t cdc_get_receive_cnt(void);

#endif

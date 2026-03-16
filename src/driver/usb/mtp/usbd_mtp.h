/******************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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
#ifndef USBD_MTP_H
#define USBD_MTP_H

#include "driver/usb/mtp/usb_mtp.h"

#ifdef __cplusplus
extern "C" {
#endif

struct usbd_interface *usbd_mtp_init_intf(uint8_t busid,
                                          struct usbd_interface *intf,
                                          const uint8_t out_ep,
                                          const uint8_t in_ep,
                                          const uint8_t int_ep);

int usbd_mtp_notify_object_add(const char *path);
int usbd_mtp_notify_object_remove(const char *path);

#include "usbd_mtp_object.h"

/* MTP object manager accessor */
mtp_object_manager_t *usbd_mtp_get_obj_manager(void);



#ifdef __cplusplus
}
#endif

#endif /* USBD_MTP_H */

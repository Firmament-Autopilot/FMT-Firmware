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

#ifndef MAVPROXY_DEV_H__
#define MAVPROXY_DEV_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

fmt_err_t mavproxy_dev_init(void);
rt_size_t mavproxy_dev_write(uint8_t chan, const void* buffer, uint32_t len, int32_t timeout);
rt_size_t mavproxy_dev_read(uint8_t chan, void* buffer, uint32_t len, int32_t timeout);
void mavproxy_dev_set_rx_indicate(uint8_t chan, fmt_err_t (*rx_ind)(uint32_t size));
fmt_err_t mavproxy_dev_set_device(uint8_t chan, const char* dev_name);
rt_device_t mavproxy_dev_get_device(uint8_t chan);

#ifdef __cplusplus
}
#endif

#endif

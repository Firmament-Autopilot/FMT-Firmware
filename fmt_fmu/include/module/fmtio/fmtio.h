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

#ifndef __FMTIO_H__
#define __FMTIO_H__

#include <firmament.h>

#include "module/fmtio/fmtio_protocol.h"

typedef fmt_err (*fmtio_rx_handler_t)(const PackageStruct* pkg);

fmt_err fmtio_init(void);
void fmtio_loop(void);
fmt_err fmtio_register_rx_handler(fmtio_rx_handler_t rx_handler);
fmt_err fmtio_send_message(uint16_t cmd, const void* data, uint16_t len);
fmt_err fmtio_send_package(const void* data, uint16_t len, PackageStruct* pkg);

rt_device_t fmtio_get_device(void);
void fmtio_suspend_comm(uint8_t suspend);

#endif
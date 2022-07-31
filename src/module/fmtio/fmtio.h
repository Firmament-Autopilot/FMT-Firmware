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
#ifndef FMTIO_H__
#define FMTIO_H__

#include "module/fmtio/protocol.h"
#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

fmt_err_t fmtio_init(const char* dev_name);
void fmtio_loop(void);
void fmtio_suspend_comm(uint8_t suspend);
fmt_err_t send_io_cmd(uint8_t code, void* data, uint16_t len);
rt_device_t fmtio_get_device(void);
fmt_err_t send_io_cmd(uint8_t code, void* data, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif
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
#ifndef FMTIO_DEV_H__
#define FMTIO_DEV_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FMTIO_SET_BAUDRATE 0x10
#define FMTIO_GET_BAUDRATE 0x11

rt_err_t hal_fmtio_dev_register(rt_device_t io_dev, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif

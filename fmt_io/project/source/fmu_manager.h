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

#ifndef  _FMU_MANAGER_H_
#define  _FMU_MANAGER_H_

#include "stm32f10x.h"
#include "protocol.h"

FMT_Error handle_fmu_package(const PackageStruct* pkg);
FMT_Error fmt_init_pkg(uint16_t cmd, void* buffer, PackageStruct* pkg);
FMT_Error fmt_create_pkg(uint16_t cmd, uint16_t buff_len, PackageStruct* pkg);
FMT_Error fmt_send_pkg(const void* data, uint16_t len, PackageStruct* pkg);
FMT_Error fmt_send_message(uint16_t cmd, const void* data, uint16_t len);
uint8_t fmt_sync_finish(void);

#endif

/*
 * Copyright (c) 2020-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// clang-format off
#ifndef ETHOSU_INTERFACE_WRAPPER_
#define ETHOSU_INTERFACE_WRAPPER_
#include "cy_device.h"
#define xstr(a) str(a)
#define str(a)  #a

#define catm(a, b)  catm_(a, b)
#define catm_(a, b) a##b

#define ETHOSU_INTERFACE_FILE xstr(catm(ethos, ETHOSU_ARCH)_interface.h)

#include ETHOSU_INTERFACE_FILE

#endif // ETHOSU_INTERFACE_WRAPPER_

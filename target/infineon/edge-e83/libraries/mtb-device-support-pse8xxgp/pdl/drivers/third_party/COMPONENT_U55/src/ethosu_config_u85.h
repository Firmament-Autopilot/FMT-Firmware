/*
 * SPDX-FileCopyrightText: Copyright 2020, 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifndef ETHOSU_CONFIG_U85_H
#define ETHOSU_CONFIG_U85_H

/* Set default values if not manually overriden */

/* Default MEM_ATTR entries */
#ifndef NPU_MEM_ATTR_0
#define NPU_MEM_ATTR_0 0 /* SRAM AXI port, non_sharable, device_non_bufferable */
#endif

#ifndef NPU_MEM_ATTR_1
#define NPU_MEM_ATTR_1 0 /* SRAM AXI port, non_sharable, device_non_bufferable */
#endif

#ifndef NPU_MEM_ATTR_2
#define NPU_MEM_ATTR_2 (1 << 2) /* EXT AXI port, non_sharable, device_non_bufferable */
#endif

#ifndef NPU_MEM_ATTR_3
#define NPU_MEM_ATTR_3 (1 << 2) /* EXT AXI port, non_sharable, device_non_bufferable */
#endif

/* Default MEM_ATTR index to use for command stream */
#ifndef NPU_QCONFIG
#define NPU_QCONFIG 2
#endif

/* Default MEM_ATTR index to use for regions 0-7 */
#ifndef NPU_REGIONCFG_0
#define NPU_REGIONCFG_0 3
#endif

#ifndef NPU_REGIONCFG_1
#define NPU_REGIONCFG_1 0
#endif

#ifndef NPU_REGIONCFG_2
#define NPU_REGIONCFG_2 1
#endif

#ifndef NPU_REGIONCFG_3
#define NPU_REGIONCFG_3 1
#endif

#ifndef NPU_REGIONCFG_4
#define NPU_REGIONCFG_4 1
#endif

#ifndef NPU_REGIONCFG_5
#define NPU_REGIONCFG_5 1
#endif

#ifndef NPU_REGIONCFG_6
#define NPU_REGIONCFG_6 1
#endif

#ifndef NPU_REGIONCFG_7
#define NPU_REGIONCFG_7 1
#endif

/* AXI SRAM/EXT limits
 * Set defaults to max. Hardware can be configured to cap at lower values.
 */
#ifndef AXI_LIMIT_SRAM_MAX_OUTSTANDING_READ_M1
#define AXI_LIMIT_SRAM_MAX_OUTSTANDING_READ_M1 64
#endif

#ifndef AXI_LIMIT_SRAM_MAX_OUTSTANDING_WRITE_M1
#define AXI_LIMIT_SRAM_MAX_OUTSTANDING_WRITE_M1 32
#endif

#ifndef AXI_LIMIT_SRAM_MAX_BEATS
#define AXI_LIMIT_SRAM_MAX_BEATS 2 /* 0=64B, 1=128B, 2=256B */
#endif

#ifndef AXI_LIMIT_EXT_MAX_OUTSTANDING_READ_M1
#define AXI_LIMIT_EXT_MAX_OUTSTANDING_READ_M1 64
#endif

#ifndef AXI_LIMIT_EXT_MAX_OUTSTANDING_WRITE_M1
#define AXI_LIMIT_EXT_MAX_OUTSTANDING_WRITE_M1 32
#endif

#ifndef AXI_LIMIT_EXT_MAX_BEATS
#define AXI_LIMIT_EXT_MAX_BEATS 2 /* 0=64B, 1=128B, 2=256B */
#endif

#endif /* #ifndef ETHOSU_CONFIG_U85_H */

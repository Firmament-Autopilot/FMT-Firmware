/*
 * Copyright (c) 2019-2020,2022 Arm Limited.
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

#ifndef ETHOSU_CONFIG_H
#define ETHOSU_CONFIG_H

/* Set default values if not manually overriden */

#ifndef NPU_QCONFIG
#define NPU_QCONFIG 2
#endif

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

#ifndef AXI_LIMIT0_MAX_BEATS_BYTES
#define AXI_LIMIT0_MAX_BEATS_BYTES 0x0
#endif

#ifndef AXI_LIMIT0_MEM_TYPE
#define AXI_LIMIT0_MEM_TYPE 0x0
#endif

#ifndef AXI_LIMIT0_MAX_OUTSTANDING_READS
#define AXI_LIMIT0_MAX_OUTSTANDING_READS 32
#endif

#ifndef AXI_LIMIT0_MAX_OUTSTANDING_WRITES
#define AXI_LIMIT0_MAX_OUTSTANDING_WRITES 16
#endif

#ifndef AXI_LIMIT1_MAX_BEATS_BYTES
#define AXI_LIMIT1_MAX_BEATS_BYTES 0x0
#endif

#ifndef AXI_LIMIT1_MEM_TYPE
#define AXI_LIMIT1_MEM_TYPE 0x0
#endif

#ifndef AXI_LIMIT1_MAX_OUTSTANDING_READS
#define AXI_LIMIT1_MAX_OUTSTANDING_READS 32
#endif

#ifndef AXI_LIMIT1_MAX_OUTSTANDING_WRITES
#define AXI_LIMIT1_MAX_OUTSTANDING_WRITES 16
#endif

#ifndef AXI_LIMIT2_MAX_BEATS_BYTES
#define AXI_LIMIT2_MAX_BEATS_BYTES 0x0
#endif

#ifndef AXI_LIMIT2_MEM_TYPE
#define AXI_LIMIT2_MEM_TYPE 0x0
#endif

#ifndef AXI_LIMIT2_MAX_OUTSTANDING_READS
#define AXI_LIMIT2_MAX_OUTSTANDING_READS 32
#endif

#ifndef AXI_LIMIT2_MAX_OUTSTANDING_WRITES
#define AXI_LIMIT2_MAX_OUTSTANDING_WRITES 16
#endif

#ifndef AXI_LIMIT3_MAX_BEATS_BYTES
#define AXI_LIMIT3_MAX_BEATS_BYTES 0x0
#endif

#ifndef AXI_LIMIT3_MEM_TYPE
#define AXI_LIMIT3_MEM_TYPE 0x0
#endif

#ifndef AXI_LIMIT3_MAX_OUTSTANDING_READS
#define AXI_LIMIT3_MAX_OUTSTANDING_READS 32
#endif

#ifndef AXI_LIMIT3_MAX_OUTSTANDING_WRITES
#define AXI_LIMIT3_MAX_OUTSTANDING_WRITES 16
#endif

#endif /* #ifndef ETHOSU_CONFIG_H */

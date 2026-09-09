/***************************************************************************//**
* \file partition_edge.h
* \version 1.0.0
*
* Partition file contains memory addresses
*
* The main purpose of the partition file is to describe how the sections in the
* linker files should be mapped into the output file, and to control the memory
* layout of the output file.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
// Start address of the SYS_MMIO registers
#define MMIO_NS_M33SYS_START        0x42000000
// Start address of the SYS_MMIO registers for secure access
#define MMIO_S_M33SYS_START         0x52000000
// Size of the SYS_MMIO registers
#define MMIO_M33SYS_SIZE            0x02000000

// Start address of the APP_MMIO registers
#define MMIO_NS_M55APP_START        0x44000000
// Start address of the APP_MMIO registers for secure access
#define MMIO_S_M55APP_START         0x54000000
// Size of the APP_MMIO registers (APP_MMIO 0 through 3)
#define MMIO_M55APP_SIZE            0x01000000

// Start address of the SRAM non-secure SAHB
#define SRAM0_NS_SAHB_START        CY_SRAM_NS_SBUS_BASE
// Start address of the RRAM non-secure SAHB
#define RRAM_NS_SAHB_START         CY_RRAM_NS_SBUS_BASE
// Start address of the SOCMEM non-secure SAHB
#define SOCMEM_NS_RAM_SAHB_START   CY_SOCMEM_RAM_NS_SBUS_BASE
// Start address of the EXT FLASH non-secure SAHB
#define FLASH_NS_SAHB_START        CY_XIP_PORT0_BASE
// Size of SOCMEM_RAM
#define SOCMEM_RAM_SIZE             0x00500000

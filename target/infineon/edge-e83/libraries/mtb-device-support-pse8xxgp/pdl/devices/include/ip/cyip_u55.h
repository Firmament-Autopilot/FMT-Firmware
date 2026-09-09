/***************************************************************************//**
* U55 IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

#ifndef _CYIP_U55_H_
#define _CYIP_U55_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     U55
*******************************************************************************/

#define U55_BASE_1_0_SECTION_SIZE               0x00000080UL
#define U55_BASE_POINTERS_1_0_SECTION_SIZE      0x00000040UL
#define U55_PAGE_PMU_1_0_SECTION_SIZE           0x00000400UL
#define U55_PAGE_ID_1_0_SECTION_SIZE            0x00000100UL
#define U55_MXU55_CTL_1_0_SECTION_SIZE          0x00001000UL
#define U55_MXU55_PPU_SECTION_SIZE              0x00001000UL
#define U55_PD_SECTION_SIZE                     0x00000020UL
#define U55_SECTION_SIZE                        0x00010000UL

/**
  * \brief Page BASE (U55_BASE_1_0)
  */
typedef struct {
   __IM uint32_t ID;                            /*!< 0x00000000 ID Register */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Register describes the current operating status of the NPU */
  __IOM uint32_t CMD;                           /*!< 0x00000008 Command register, reads as last written command */
  __IOM uint32_t RESET;                         /*!< 0x0000000C Request Reset and new security mode */
  __IOM uint32_t QBASE0;                        /*!< 0x00000010 Base address of Command-queue bits [31 downto 0]. The address
                                                                is 4-byte-aligned */
  __IOM uint32_t QBASE1;                        /*!< 0x00000014 Address extension bits [47 downto 32] for queue base */
   __IM uint32_t QREAD;                         /*!< 0x00000018 Read offset in the command stream in bytes. Multiples of 4 in
                                                                the range 0-16 MB */
  __IOM uint32_t QCONFIG;                       /*!< 0x0000001C AXI configuration for the command stream in the range 0-3. Same
                                                                encoding as for REGIONCFG */
  __IOM uint32_t QSIZE;                         /*!< 0x00000020 Size of the command stream in bytes. Multiples of 4 in the
                                                                range 0-16 MB */
   __IM uint32_t PROT;                          /*!< 0x00000024 Protection level configured for the NPU when acting as an AXI
                                                                master */
   __IM uint32_t CONFIG;                        /*!< 0x00000028 RTL configuration */
  __IOM uint32_t LOCK;                          /*!< 0x0000002C Lock register. This register is designed for driver use and
                                                                does not affect NPU functionality */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t REGIONCFG;                     /*!< 0x0000003C Base pointer configuration. Bits[2*k+1 downto 2*k] give the
                                                                memory type for REGION[k] */
  __IOM uint32_t AXI_LIMIT0;                    /*!< 0x00000040 AXI limits for port 0 counter 0 */
  __IOM uint32_t AXI_LIMIT1;                    /*!< 0x00000044 AXI limits for port 0 counter 1 */
  __IOM uint32_t AXI_LIMIT2;                    /*!< 0x00000048 AXI limits for port 1 counter 2 */
  __IOM uint32_t AXI_LIMIT3;                    /*!< 0x0000004C AXI limits for port 1 counter 3 */
   __IM uint32_t RESERVED1[12];
} U55_BASE_1_0_Type;                            /*!< Size = 128 (0x80) */

/**
  * \brief Page BASE_POINTERS (U55_BASE_POINTERS_1_0)
  */
typedef struct {
  __IOM uint32_t BASEP0;                        /*!< 0x00000000 Lower 32 bits of the base pointer for region index 0 */
  __IOM uint32_t BASEP1;                        /*!< 0x00000004 Upper 32-bits of the base pointer for region index 0 */
  __IOM uint32_t BASEP2;                        /*!< 0x00000008 Lower 32 bits of the base pointer for region index 1 */
  __IOM uint32_t BASEP3;                        /*!< 0x0000000C Upper 32-bits of the base pointer for region index 1 */
  __IOM uint32_t BASEP4;                        /*!< 0x00000010 Lower 32 bits of the base pointer for region index 2 */
  __IOM uint32_t BASEP5;                        /*!< 0x00000014 Upper 32-bits of the base pointer for region index 2 */
  __IOM uint32_t BASEP6;                        /*!< 0x00000018 Lower 32 bits of the base pointer for region index 3 */
  __IOM uint32_t BASEP7;                        /*!< 0x0000001C Upper 32-bits of the base pointer for region index 3 */
  __IOM uint32_t BASEP8;                        /*!< 0x00000020 Lower 32 bits of the base pointer for region index 4 */
  __IOM uint32_t BASEP9;                        /*!< 0x00000024 Upper 32-bits of the base pointer for region index 4 */
  __IOM uint32_t BASEP10;                       /*!< 0x00000028 Lower 32 bits of the base pointer for region index 5 */
  __IOM uint32_t BASEP11;                       /*!< 0x0000002C Upper 32-bits of the base pointer for region index 5 */
  __IOM uint32_t BASEP12;                       /*!< 0x00000030 Lower 32 bits of the base pointer for region index 6 */
  __IOM uint32_t BASEP13;                       /*!< 0x00000034 Upper 32-bits of the base pointer for region index 6 */
  __IOM uint32_t BASEP14;                       /*!< 0x00000038 Lower 32 bits of the base pointer for region index 7 */
  __IOM uint32_t BASEP15;                       /*!< 0x0000003C Upper 32-bits of the base pointer for region index 7 */
} U55_BASE_POINTERS_1_0_Type;                   /*!< Size = 64 (0x40) */

/**
  * \brief Page PMU (U55_PAGE_PMU_1_0)
  */
typedef struct {
   __IM uint32_t RESERVED[32];
  __IOM uint32_t PMCR;                          /*!< 0x00000080 PMU master control register */
  __IOM uint32_t PMCNTENSET;                    /*!< 0x00000084 Count-enable set register */
  __IOM uint32_t PMCNTENCLR;                    /*!< 0x00000088 Count-enable clear register */
  __IOM uint32_t PMOVSSET;                      /*!< 0x0000008C Overflow-flag status set register */
  __IOM uint32_t PMOVSCLR;                      /*!< 0x00000090 Overflow-flag status clear register */
  __IOM uint32_t PMINTSET;                      /*!< 0x00000094 Interrupt-enable set register */
  __IOM uint32_t PMINTCLR;                      /*!< 0x00000098 Interrupt-enable clear register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t PMCCNTR_LO;                    /*!< 0x000000A0 Performance-monitor cycle count low register */
  __IOM uint32_t PMCCNTR_HI;                    /*!< 0x000000A4 Performance-monitor cycle count high register */
  __IOM uint32_t PMCCNTR_CFG;                   /*!< 0x000000A8 Set start/stop event on the cycle counter. */
  __IOM uint32_t PMCAXI_CHAN;                   /*!< 0x000000AC Set which AXI channel monitor */
   __IM uint32_t RESERVED2[84];
   __OM uint32_t PMU_EVCNTR[4];                 /*!< 0x00000200 Performance monitor event counters */
   __IM uint32_t RESERVED3[28];
  __IOM uint32_t PMU_ENTYPER[4];                /*!< 0x00000280 Performance monitor event type control counters */
   __IM uint32_t RESERVED4[92];
} U55_PAGE_PMU_1_0_Type;                        /*!< Size = 1024 (0x400) */

/**
  * \brief Page ID and Component ID (U55_PAGE_ID_1_0)
  */
typedef struct {
   __IM uint32_t RESERVED[52];
   __IM uint32_t PID4;                          /*!< 0x000000D0 Peripheral ID byte 4 (Arm = code 4) */
   __IM uint32_t PID5;                          /*!< 0x000000D4 Peripheral ID byte 5. (reserved) */
   __IM uint32_t PID6;                          /*!< 0x000000D8 Peripheral ID byte 6. (reserved) */
   __IM uint32_t PID7;                          /*!< 0x000000DC Peripheral ID byte 7. (reserved) */
   __IM uint32_t PID0;                          /*!< 0x000000E0 Peripheral ID byte 0. This is bits[7 downto 0] of the part
                                                                number. */
   __IM uint32_t PID1;                          /*!< 0x000000E4 Peripheral ID byte 1. This is bits[11 downto 8] of the part
                                                                number in bits[3 downto 0], and bits[3 downto 0] of the Arm ID
                                                                in bits[7 downto 4]. */
   __IM uint32_t PID2;                          /*!< 0x000000E8 Peripheral ID byte 2. This is bits[6 downto 4] of the Arm ID in
                                                                bits[2 downto 0], and bit 3 indicates format B. */
   __IM uint32_t PID3;                          /*!< 0x000000EC Peripheral ID byte 3 */
   __IM uint32_t CID0;                          /*!< 0x000000F0 Component ID byte 0 */
   __IM uint32_t CID1;                          /*!< 0x000000F4 Component ID byte 1 */
   __IM uint32_t CID2;                          /*!< 0x000000F8 Component ID byte 2 */
   __IM uint32_t CID3;                          /*!< 0x000000FC Component ID byte 3 */
} U55_PAGE_ID_1_0_Type;                         /*!< Size = 256 (0x100) */

/**
  * \brief System configuration settings (U55_MXU55_CTL_1_0)
  */
typedef struct {
  __IOM uint32_t ROT_INIT;                      /*!< 0x00000000 Initial settings */
  __IOM uint32_t ACG_CTL;                       /*!< 0x00000004 ACG Configuration of ARMU55 Bridge */
   __IM uint32_t RESERVED[1022];
} U55_MXU55_CTL_1_0_Type;                       /*!< Size = 4096 (0x1000) */

/**
  * \brief Power Policy Unit Registers for System RAM (U55_MXU55_PPU)
  */
typedef struct {
  __IOM uint32_t PWPR;                          /*!< 0x00000000 Power Policy Register */
  __IOM uint32_t PMER;                          /*!< 0x00000004 Power Mode Emulation Register */
   __IM uint32_t PWSR;                          /*!< 0x00000008 Power Status Register */
   __IM uint32_t RESERVED;
   __IM uint32_t DISR;                          /*!< 0x00000010 Device Interface Input Current Status Register */
   __IM uint32_t MISR;                          /*!< 0x00000014 Miscellaneous Input Current Status Register */
   __IM uint32_t STSR;                          /*!< 0x00000018 Stored Status Register */
  __IOM uint32_t UNLK;                          /*!< 0x0000001C Unlock register */
  __IOM uint32_t PWCR;                          /*!< 0x00000020 Power Configuration Register */
  __IOM uint32_t PTCR;                          /*!< 0x00000024 Power Mode Transition Configuration Register */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t IMR;                           /*!< 0x00000030 Interrupt Mask Register */
  __IOM uint32_t AIMR;                          /*!< 0x00000034 Additional Interrupt Mask Register */
  __IOM uint32_t ISR;                           /*!< 0x00000038 Interrupt Status Register */
  __IOM uint32_t AISR;                          /*!< 0x0000003C Additional Interrupt Status Register */
  __IOM uint32_t IESR;                          /*!< 0x00000040 Input Edge Sensitivity Register */
  __IOM uint32_t OPSR;                          /*!< 0x00000044 Operating Mode Active Edge Sensitivity Register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t FUNRR;                         /*!< 0x00000050 Functional Retention RAM Configuration Register */
  __IOM uint32_t FULRR;                         /*!< 0x00000054 Full Retention RAM Configuration Register */
  __IOM uint32_t MEMRR;                         /*!< 0x00000058 Memory Retention RAM Configuration Register */
   __IM uint32_t RESERVED3[65];
  __IOM uint32_t EDTR0;                         /*!< 0x00000160 Power Mode Entry Delay Register 0 */
  __IOM uint32_t EDTR1;                         /*!< 0x00000164 Power Mode Entry Delay Register 1 */
   __IM uint32_t RESERVED4[2];
   __IM uint32_t DCDR0;                         /*!< 0x00000170 Device Control Delay Configuration Register 0 */
   __IM uint32_t DCDR1;                         /*!< 0x00000174 Device Control Delay Configuration Register 1 */
   __IM uint32_t RESERVED5[910];
   __IM uint32_t IDR0;                          /*!< 0x00000FB0 PPU Identification Register 0 */
   __IM uint32_t IDR1;                          /*!< 0x00000FB4 PPU Identification Register 1 */
   __IM uint32_t RESERVED6[4];
   __IM uint32_t IIDR;                          /*!< 0x00000FC8 Implementation Identification Register */
   __IM uint32_t AIDR;                          /*!< 0x00000FCC Architecture Identification Register */
   __IM uint32_t PID4;                          /*!< 0x00000FD0 Implementation Defined Identification Register (PID4) */
   __IM uint32_t RESERVED7[3];
   __IM uint32_t PID0;                          /*!< 0x00000FE0 Implementation Defined Identification Register (PID0) */
   __IM uint32_t PID1;                          /*!< 0x00000FE4 Implementation Defined Identification Register (PID1) */
   __IM uint32_t PID2;                          /*!< 0x00000FE8 Implementation Defined Identification Register (PID2) */
   __IM uint32_t PID3;                          /*!< 0x00000FEC Implementation Defined Identification Register (PID3) */
   __IM uint32_t ID0;                           /*!< 0x00000FF0 Implementation Defined Identification Register (ID0) */
   __IM uint32_t ID1;                           /*!< 0x00000FF4 Implementation Defined Identification Register (ID1) */
   __IM uint32_t ID2;                           /*!< 0x00000FF8 Implementation Defined Identification Register (ID2) */
   __IM uint32_t ID3;                           /*!< 0x00000FFC Implementation Defined Identification Register (ID3) */
} U55_MXU55_PPU_Type;                           /*!< Size = 4096 (0x1000) */

/**
  * \brief Power Domain Controller (U55_PD)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Power Domain Control */
  __IOM uint32_t PWR_UP_DELAY;                  /*!< 0x00000004 Active switch weak enable to active switch strong enable delay */
   __IM uint32_t RESERVED[6];
} U55_PD_Type;                                  /*!< Size = 32 (0x20) */

/**
  * \brief Top level section for IP generation only, contains IP memory map (U55)
  */
typedef struct {
        U55_BASE_1_0_Type BASE_1_0;             /*!< 0x00000000 Page BASE */
        U55_BASE_POINTERS_1_0_Type BASE_POINTERS_1_0; /*!< 0x00000080 Page BASE_POINTERS */
   __IM uint32_t RESERVED[16];
        U55_PAGE_PMU_1_0_Type PAGE_PMU_1_0;     /*!< 0x00000100 Page PMU */
   __IM uint32_t RESERVED1[640];
        U55_PAGE_ID_1_0_Type PAGE_ID_1_0;       /*!< 0x00000F00 Page ID and Component ID */
        U55_MXU55_CTL_1_0_Type MXU55_CTL_1_0;   /*!< 0x00001000 System configuration settings */
        U55_MXU55_PPU_Type MXU55_PPU;           /*!< 0x00002000 Power Policy Unit Registers for System RAM */
        U55_PD_Type PD;                         /*!< 0x00003000 Power Domain Controller */
} U55_Type;                                     /*!< Size = 12320 (0x3020) */


/* U55_BASE_1_0.ID */
#define U55_BASE_1_0_ID_VERSION_STATUS_Pos      0UL
#define U55_BASE_1_0_ID_VERSION_STATUS_Msk      0xFUL
#define U55_BASE_1_0_ID_VERSION_MINOR_Pos       4UL
#define U55_BASE_1_0_ID_VERSION_MINOR_Msk       0xF0UL
#define U55_BASE_1_0_ID_VERSION_MAJOR_Pos       8UL
#define U55_BASE_1_0_ID_VERSION_MAJOR_Msk       0xF00UL
#define U55_BASE_1_0_ID_PRODUCT_MAJOR_Pos       12UL
#define U55_BASE_1_0_ID_PRODUCT_MAJOR_Msk       0xF000UL
#define U55_BASE_1_0_ID_ARCH_PATCH_REV_Pos      16UL
#define U55_BASE_1_0_ID_ARCH_PATCH_REV_Msk      0xF0000UL
#define U55_BASE_1_0_ID_ARCH_MINOR_REV_Pos      20UL
#define U55_BASE_1_0_ID_ARCH_MINOR_REV_Msk      0xFF00000UL
#define U55_BASE_1_0_ID_ARCH_MAJOR_REV_Pos      28UL
#define U55_BASE_1_0_ID_ARCH_MAJOR_REV_Msk      0xF0000000UL
/* U55_BASE_1_0.STATUS */
#define U55_BASE_1_0_STATUS_STATE_Pos           0UL
#define U55_BASE_1_0_STATUS_STATE_Msk           0x1UL
#define U55_BASE_1_0_STATUS_IRQ_RAISED_Pos      1UL
#define U55_BASE_1_0_STATUS_IRQ_RAISED_Msk      0x2UL
#define U55_BASE_1_0_STATUS_BUS_STATUS_Pos      2UL
#define U55_BASE_1_0_STATUS_BUS_STATUS_Msk      0x4UL
#define U55_BASE_1_0_STATUS_RESET_STATUS_Pos    3UL
#define U55_BASE_1_0_STATUS_RESET_STATUS_Msk    0x8UL
#define U55_BASE_1_0_STATUS_CMD_PARSE_ERROR_Pos 4UL
#define U55_BASE_1_0_STATUS_CMD_PARSE_ERROR_Msk 0x10UL
#define U55_BASE_1_0_STATUS_CMD_END_REACHED_Pos 5UL
#define U55_BASE_1_0_STATUS_CMD_END_REACHED_Msk 0x20UL
#define U55_BASE_1_0_STATUS_PMU_IRQ_RAISED_Pos  6UL
#define U55_BASE_1_0_STATUS_PMU_IRQ_RAISED_Msk  0x40UL
#define U55_BASE_1_0_STATUS_FAULTING_INTERFACE_Pos 11UL
#define U55_BASE_1_0_STATUS_FAULTING_INTERFACE_Msk 0x800UL
#define U55_BASE_1_0_STATUS_FAULTING_CHANNEL_Pos 12UL
#define U55_BASE_1_0_STATUS_FAULTING_CHANNEL_Msk 0xF000UL
#define U55_BASE_1_0_STATUS_IRQ_HISTORY_MASK_Pos 16UL
#define U55_BASE_1_0_STATUS_IRQ_HISTORY_MASK_Msk 0xFFFF0000UL
/* U55_BASE_1_0.CMD */
#define U55_BASE_1_0_CMD_TRANSITION_TO_RUNNING_STATE_Pos 0UL
#define U55_BASE_1_0_CMD_TRANSITION_TO_RUNNING_STATE_Msk 0x1UL
#define U55_BASE_1_0_CMD_CLEAR_IRQ_Pos          1UL
#define U55_BASE_1_0_CMD_CLEAR_IRQ_Msk          0x2UL
#define U55_BASE_1_0_CMD_CLOCK_Q_ENABLE_Pos     2UL
#define U55_BASE_1_0_CMD_CLOCK_Q_ENABLE_Msk     0x4UL
#define U55_BASE_1_0_CMD_POWER_Q_ENABLE_Pos     3UL
#define U55_BASE_1_0_CMD_POWER_Q_ENABLE_Msk     0x8UL
#define U55_BASE_1_0_CMD_CLEAR_IRQ_HISTORY_Pos  16UL
#define U55_BASE_1_0_CMD_CLEAR_IRQ_HISTORY_Msk  0xFFFF0000UL
/* U55_BASE_1_0.RESET */
#define U55_BASE_1_0_RESET_PENDING_CPL_Pos      0UL
#define U55_BASE_1_0_RESET_PENDING_CPL_Msk      0x1UL
#define U55_BASE_1_0_RESET_PENDING_CSL_Pos      1UL
#define U55_BASE_1_0_RESET_PENDING_CSL_Msk      0x2UL
/* U55_BASE_1_0.QBASE0 */
#define U55_BASE_1_0_QBASE0_QBASE0_Pos          0UL
#define U55_BASE_1_0_QBASE0_QBASE0_Msk          0xFFFFFFFFUL
/* U55_BASE_1_0.QBASE1 */
#define U55_BASE_1_0_QBASE1_QBASE1_Pos          0UL
#define U55_BASE_1_0_QBASE1_QBASE1_Msk          0xFFFFFFFFUL
/* U55_BASE_1_0.QREAD */
#define U55_BASE_1_0_QREAD_QREAD_Pos            0UL
#define U55_BASE_1_0_QREAD_QREAD_Msk            0xFFFFFFFFUL
/* U55_BASE_1_0.QCONFIG */
#define U55_BASE_1_0_QCONFIG_QCONFIG_Pos        0UL
#define U55_BASE_1_0_QCONFIG_QCONFIG_Msk        0xFFFFFFFFUL
/* U55_BASE_1_0.QSIZE */
#define U55_BASE_1_0_QSIZE_QSIZE_Pos            0UL
#define U55_BASE_1_0_QSIZE_QSIZE_Msk            0xFFFFFFFFUL
/* U55_BASE_1_0.PROT */
#define U55_BASE_1_0_PROT_ACTIVE_CPL_Pos        0UL
#define U55_BASE_1_0_PROT_ACTIVE_CPL_Msk        0x1UL
#define U55_BASE_1_0_PROT_ACTIVE_CSL_Pos        1UL
#define U55_BASE_1_0_PROT_ACTIVE_CSL_Msk        0x2UL
/* U55_BASE_1_0.CONFIG */
#define U55_BASE_1_0_CONFIG_MACS_PER_CC_Pos     0UL
#define U55_BASE_1_0_CONFIG_MACS_PER_CC_Msk     0xFUL
#define U55_BASE_1_0_CONFIG_CMD_STREAM_VERSION_Pos 4UL
#define U55_BASE_1_0_CONFIG_CMD_STREAM_VERSION_Msk 0xF0UL
#define U55_BASE_1_0_CONFIG_SHRAM_SIZE_Pos      8UL
#define U55_BASE_1_0_CONFIG_SHRAM_SIZE_Msk      0xFF00UL
#define U55_BASE_1_0_CONFIG_PRODUCT_Pos         28UL
#define U55_BASE_1_0_CONFIG_PRODUCT_Msk         0xF0000000UL
/* U55_BASE_1_0.LOCK */
#define U55_BASE_1_0_LOCK_LOCK_Pos              0UL
#define U55_BASE_1_0_LOCK_LOCK_Msk              0xFFFFFFFFUL
/* U55_BASE_1_0.REGIONCFG */
#define U55_BASE_1_0_REGIONCFG_REGION0_Pos      0UL
#define U55_BASE_1_0_REGIONCFG_REGION0_Msk      0x3UL
#define U55_BASE_1_0_REGIONCFG_REGION1_Pos      2UL
#define U55_BASE_1_0_REGIONCFG_REGION1_Msk      0xCUL
#define U55_BASE_1_0_REGIONCFG_REGION2_Pos      4UL
#define U55_BASE_1_0_REGIONCFG_REGION2_Msk      0x30UL
#define U55_BASE_1_0_REGIONCFG_REGION3_Pos      6UL
#define U55_BASE_1_0_REGIONCFG_REGION3_Msk      0xC0UL
#define U55_BASE_1_0_REGIONCFG_REGION4_Pos      8UL
#define U55_BASE_1_0_REGIONCFG_REGION4_Msk      0x300UL
#define U55_BASE_1_0_REGIONCFG_REGION5_Pos      10UL
#define U55_BASE_1_0_REGIONCFG_REGION5_Msk      0xC00UL
#define U55_BASE_1_0_REGIONCFG_REGION6_Pos      12UL
#define U55_BASE_1_0_REGIONCFG_REGION6_Msk      0x3000UL
#define U55_BASE_1_0_REGIONCFG_REGION7_Pos      14UL
#define U55_BASE_1_0_REGIONCFG_REGION7_Msk      0xC000UL
/* U55_BASE_1_0.AXI_LIMIT0 */
#define U55_BASE_1_0_AXI_LIMIT0_MAX_BEATS_Pos   0UL
#define U55_BASE_1_0_AXI_LIMIT0_MAX_BEATS_Msk   0x3UL
#define U55_BASE_1_0_AXI_LIMIT0_MEMTYPE_Pos     4UL
#define U55_BASE_1_0_AXI_LIMIT0_MEMTYPE_Msk     0xF0UL
#define U55_BASE_1_0_AXI_LIMIT0_MAX_OUTSTANDING_READ_M1_Pos 16UL
#define U55_BASE_1_0_AXI_LIMIT0_MAX_OUTSTANDING_READ_M1_Msk 0xFF0000UL
#define U55_BASE_1_0_AXI_LIMIT0_MAX_OUTSTANDING_WRITE_M1_Pos 24UL
#define U55_BASE_1_0_AXI_LIMIT0_MAX_OUTSTANDING_WRITE_M1_Msk 0xFF000000UL
/* U55_BASE_1_0.AXI_LIMIT1 */
#define U55_BASE_1_0_AXI_LIMIT1_MAX_BEATS_Pos   0UL
#define U55_BASE_1_0_AXI_LIMIT1_MAX_BEATS_Msk   0x3UL
#define U55_BASE_1_0_AXI_LIMIT1_MEMTYPE_Pos     4UL
#define U55_BASE_1_0_AXI_LIMIT1_MEMTYPE_Msk     0xF0UL
#define U55_BASE_1_0_AXI_LIMIT1_MAX_OUTSTANDING_READ_M1_Pos 16UL
#define U55_BASE_1_0_AXI_LIMIT1_MAX_OUTSTANDING_READ_M1_Msk 0xFF0000UL
#define U55_BASE_1_0_AXI_LIMIT1_MAX_OUTSTANDING_WRITE_M1_Pos 24UL
#define U55_BASE_1_0_AXI_LIMIT1_MAX_OUTSTANDING_WRITE_M1_Msk 0xFF000000UL
/* U55_BASE_1_0.AXI_LIMIT2 */
#define U55_BASE_1_0_AXI_LIMIT2_MAX_BEATS_Pos   0UL
#define U55_BASE_1_0_AXI_LIMIT2_MAX_BEATS_Msk   0x3UL
#define U55_BASE_1_0_AXI_LIMIT2_MEMTYPE_Pos     4UL
#define U55_BASE_1_0_AXI_LIMIT2_MEMTYPE_Msk     0xF0UL
#define U55_BASE_1_0_AXI_LIMIT2_MAX_OUTSTANDING_READ_M1_Pos 16UL
#define U55_BASE_1_0_AXI_LIMIT2_MAX_OUTSTANDING_READ_M1_Msk 0xFF0000UL
#define U55_BASE_1_0_AXI_LIMIT2_MAX_OUTSTANDING_WRITE_M1_Pos 24UL
#define U55_BASE_1_0_AXI_LIMIT2_MAX_OUTSTANDING_WRITE_M1_Msk 0xFF000000UL
/* U55_BASE_1_0.AXI_LIMIT3 */
#define U55_BASE_1_0_AXI_LIMIT3_MAX_BEATS_Pos   0UL
#define U55_BASE_1_0_AXI_LIMIT3_MAX_BEATS_Msk   0x3UL
#define U55_BASE_1_0_AXI_LIMIT3_MEMTYPE_Pos     4UL
#define U55_BASE_1_0_AXI_LIMIT3_MEMTYPE_Msk     0xF0UL
#define U55_BASE_1_0_AXI_LIMIT3_MAX_OUTSTANDING_READ_M1_Pos 16UL
#define U55_BASE_1_0_AXI_LIMIT3_MAX_OUTSTANDING_READ_M1_Msk 0xFF0000UL
#define U55_BASE_1_0_AXI_LIMIT3_MAX_OUTSTANDING_WRITE_M1_Pos 24UL
#define U55_BASE_1_0_AXI_LIMIT3_MAX_OUTSTANDING_WRITE_M1_Msk 0xFF000000UL


/* U55_BASE_POINTERS_1_0.BASEP0 */
#define U55_BASE_POINTERS_1_0_BASEP0_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP0_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP1 */
#define U55_BASE_POINTERS_1_0_BASEP1_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP1_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP2 */
#define U55_BASE_POINTERS_1_0_BASEP2_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP2_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP3 */
#define U55_BASE_POINTERS_1_0_BASEP3_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP3_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP4 */
#define U55_BASE_POINTERS_1_0_BASEP4_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP4_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP5 */
#define U55_BASE_POINTERS_1_0_BASEP5_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP5_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP6 */
#define U55_BASE_POINTERS_1_0_BASEP6_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP6_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP7 */
#define U55_BASE_POINTERS_1_0_BASEP7_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP7_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP8 */
#define U55_BASE_POINTERS_1_0_BASEP8_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP8_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP9 */
#define U55_BASE_POINTERS_1_0_BASEP9_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP9_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP10 */
#define U55_BASE_POINTERS_1_0_BASEP10_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP10_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP11 */
#define U55_BASE_POINTERS_1_0_BASEP11_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP11_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP12 */
#define U55_BASE_POINTERS_1_0_BASEP12_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP12_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP13 */
#define U55_BASE_POINTERS_1_0_BASEP13_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP13_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP14 */
#define U55_BASE_POINTERS_1_0_BASEP14_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP14_ADDR_WORD_Msk 0xFFFFFFFFUL
/* U55_BASE_POINTERS_1_0.BASEP15 */
#define U55_BASE_POINTERS_1_0_BASEP15_ADDR_WORD_Pos 0UL
#define U55_BASE_POINTERS_1_0_BASEP15_ADDR_WORD_Msk 0xFFFFFFFFUL


/* U55_PAGE_PMU_1_0.PMCR */
#define U55_PAGE_PMU_1_0_PMCR_CNT_EN_Pos        0UL
#define U55_PAGE_PMU_1_0_PMCR_CNT_EN_Msk        0x1UL
#define U55_PAGE_PMU_1_0_PMCR_EVENT_CNT_RST_Pos 1UL
#define U55_PAGE_PMU_1_0_PMCR_EVENT_CNT_RST_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMCR_CYCLE_CNT_RST_Pos 2UL
#define U55_PAGE_PMU_1_0_PMCR_CYCLE_CNT_RST_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMCR_MASK_EN_Pos       3UL
#define U55_PAGE_PMU_1_0_PMCR_MASK_EN_Msk       0x8UL
#define U55_PAGE_PMU_1_0_PMCR_NUM_EVENT_CNT_Pos 11UL
#define U55_PAGE_PMU_1_0_PMCR_NUM_EVENT_CNT_Msk 0xF800UL
/* U55_PAGE_PMU_1_0.PMCNTENSET */
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_0_Pos 0UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_0_Msk 0x1UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_1_Pos 1UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_1_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_2_Pos 2UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_2_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_3_Pos 3UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_EVENT_CNT_3_Msk 0x8UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_CYCLE_CNT_Pos 31UL
#define U55_PAGE_PMU_1_0_PMCNTENSET_CYCLE_CNT_Msk 0x80000000UL
/* U55_PAGE_PMU_1_0.PMCNTENCLR */
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_0_Pos 0UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_0_Msk 0x1UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_1_Pos 1UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_1_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_2_Pos 2UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_2_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_3_Pos 3UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_EVENT_CNT_3_Msk 0x8UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_CYCLE_CNT_Pos 31UL
#define U55_PAGE_PMU_1_0_PMCNTENCLR_CYCLE_CNT_Msk 0x80000000UL
/* U55_PAGE_PMU_1_0.PMOVSSET */
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_0_OVF_Pos 0UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_0_OVF_Msk 0x1UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_1_OVF_Pos 1UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_1_OVF_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_2_OVF_Pos 2UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_2_OVF_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_3_OVF_Pos 3UL
#define U55_PAGE_PMU_1_0_PMOVSSET_EVENT_CNT_3_OVF_Msk 0x8UL
#define U55_PAGE_PMU_1_0_PMOVSSET_CYCLE_CNT_OVF_Pos 31UL
#define U55_PAGE_PMU_1_0_PMOVSSET_CYCLE_CNT_OVF_Msk 0x80000000UL
/* U55_PAGE_PMU_1_0.PMOVSCLR */
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_0_OVF_Pos 0UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_0_OVF_Msk 0x1UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_1_OVF_Pos 1UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_1_OVF_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_2_OVF_Pos 2UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_2_OVF_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_3_OVF_Pos 3UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_EVENT_CNT_3_OVF_Msk 0x8UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_CYCLE_CNT_OVF_Pos 31UL
#define U55_PAGE_PMU_1_0_PMOVSCLR_CYCLE_CNT_OVF_Msk 0x80000000UL
/* U55_PAGE_PMU_1_0.PMINTSET */
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_0_INT_Pos 0UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_0_INT_Msk 0x1UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_1_INT_Pos 1UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_1_INT_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_2_INT_Pos 2UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_2_INT_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_3_INT_Pos 3UL
#define U55_PAGE_PMU_1_0_PMINTSET_EVENT_CNT_3_INT_Msk 0x8UL
#define U55_PAGE_PMU_1_0_PMINTSET_CYCLE_CNT_INT_Pos 31UL
#define U55_PAGE_PMU_1_0_PMINTSET_CYCLE_CNT_INT_Msk 0x80000000UL
/* U55_PAGE_PMU_1_0.PMINTCLR */
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_0_INT_Pos 0UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_0_INT_Msk 0x1UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_1_INT_Pos 1UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_1_INT_Msk 0x2UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_2_INT_Pos 2UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_2_INT_Msk 0x4UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_3_INT_Pos 3UL
#define U55_PAGE_PMU_1_0_PMINTCLR_EVENT_CNT_3_INT_Msk 0x8UL
#define U55_PAGE_PMU_1_0_PMINTCLR_CYCLE_CNT_INT_Pos 31UL
#define U55_PAGE_PMU_1_0_PMINTCLR_CYCLE_CNT_INT_Msk 0x80000000UL
/* U55_PAGE_PMU_1_0.PMCCNTR_LO */
#define U55_PAGE_PMU_1_0_PMCCNTR_LO_CYCLE_CNT_LO_Pos 0UL
#define U55_PAGE_PMU_1_0_PMCCNTR_LO_CYCLE_CNT_LO_Msk 0xFFFFFFFFUL
/* U55_PAGE_PMU_1_0.PMCCNTR_HI */
#define U55_PAGE_PMU_1_0_PMCCNTR_HI_CYCLE_CNT_HI_Pos 0UL
#define U55_PAGE_PMU_1_0_PMCCNTR_HI_CYCLE_CNT_HI_Msk 0xFFFFUL
/* U55_PAGE_PMU_1_0.PMCCNTR_CFG */
#define U55_PAGE_PMU_1_0_PMCCNTR_CFG_CYCLE_CNT_CFG_START_Pos 0UL
#define U55_PAGE_PMU_1_0_PMCCNTR_CFG_CYCLE_CNT_CFG_START_Msk 0x3FFUL
#define U55_PAGE_PMU_1_0_PMCCNTR_CFG_CYCLE_CNT_CFG_STOP_Pos 16UL
#define U55_PAGE_PMU_1_0_PMCCNTR_CFG_CYCLE_CNT_CFG_STOP_Msk 0x3FF0000UL
/* U55_PAGE_PMU_1_0.PMCAXI_CHAN */
#define U55_PAGE_PMU_1_0_PMCAXI_CHAN_CH_SEL_Pos 0UL
#define U55_PAGE_PMU_1_0_PMCAXI_CHAN_CH_SEL_Msk 0xFUL
#define U55_PAGE_PMU_1_0_PMCAXI_CHAN_AXI_CNT_SEL_Pos 8UL
#define U55_PAGE_PMU_1_0_PMCAXI_CHAN_AXI_CNT_SEL_Msk 0x300UL
#define U55_PAGE_PMU_1_0_PMCAXI_CHAN_BW_CH_SEL_EN_Pos 10UL
#define U55_PAGE_PMU_1_0_PMCAXI_CHAN_BW_CH_SEL_EN_Msk 0x400UL
/* U55_PAGE_PMU_1_0.PMU_EVCNTR */
#define U55_PAGE_PMU_1_0_PMU_EVCNTR_PMU_EVCNTR_Pos 0UL
#define U55_PAGE_PMU_1_0_PMU_EVCNTR_PMU_EVCNTR_Msk 0xFFFFFFFFUL
/* U55_PAGE_PMU_1_0.PMU_ENTYPER */
#define U55_PAGE_PMU_1_0_PMU_ENTYPER_EV_TYPE_Pos 0UL
#define U55_PAGE_PMU_1_0_PMU_ENTYPER_EV_TYPE_Msk 0x3FFUL


/* U55_PAGE_ID_1_0.PID4 */
#define U55_PAGE_ID_1_0_PID4_PID4_Pos           0UL
#define U55_PAGE_ID_1_0_PID4_PID4_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID5 */
#define U55_PAGE_ID_1_0_PID5_PID5_Pos           0UL
#define U55_PAGE_ID_1_0_PID5_PID5_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID6 */
#define U55_PAGE_ID_1_0_PID6_PID6_Pos           0UL
#define U55_PAGE_ID_1_0_PID6_PID6_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID7 */
#define U55_PAGE_ID_1_0_PID7_PID7_Pos           0UL
#define U55_PAGE_ID_1_0_PID7_PID7_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID0 */
#define U55_PAGE_ID_1_0_PID0_PID0_Pos           0UL
#define U55_PAGE_ID_1_0_PID0_PID0_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID1 */
#define U55_PAGE_ID_1_0_PID1_PID1_Pos           0UL
#define U55_PAGE_ID_1_0_PID1_PID1_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID2 */
#define U55_PAGE_ID_1_0_PID2_PID2_Pos           0UL
#define U55_PAGE_ID_1_0_PID2_PID2_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.PID3 */
#define U55_PAGE_ID_1_0_PID3_PID3_Pos           0UL
#define U55_PAGE_ID_1_0_PID3_PID3_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.CID0 */
#define U55_PAGE_ID_1_0_CID0_CID0_Pos           0UL
#define U55_PAGE_ID_1_0_CID0_CID0_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.CID1 */
#define U55_PAGE_ID_1_0_CID1_CID1_Pos           0UL
#define U55_PAGE_ID_1_0_CID1_CID1_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.CID2 */
#define U55_PAGE_ID_1_0_CID2_CID2_Pos           0UL
#define U55_PAGE_ID_1_0_CID2_CID2_Msk           0xFFFFFFFFUL
/* U55_PAGE_ID_1_0.CID3 */
#define U55_PAGE_ID_1_0_CID3_CID3_Pos           0UL
#define U55_PAGE_ID_1_0_CID3_CID3_Msk           0xFFFFFFFFUL


/* U55_MXU55_CTL_1_0.ROT_INIT */
#define U55_MXU55_CTL_1_0_ROT_INIT_PRIVILEGE_LEVEL_Pos 1UL
#define U55_MXU55_CTL_1_0_ROT_INIT_PRIVILEGE_LEVEL_Msk 0x2UL
#define U55_MXU55_CTL_1_0_ROT_INIT_SECURITY_LEVEL_Pos 2UL
#define U55_MXU55_CTL_1_0_ROT_INIT_SECURITY_LEVEL_Msk 0x4UL
/* U55_MXU55_CTL_1_0.ACG_CTL */
#define U55_MXU55_CTL_1_0_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define U55_MXU55_CTL_1_0_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL


/* U55_MXU55_PPU.PWPR */
#define U55_MXU55_PPU_PWPR_PWR_POLICY_Pos       0UL
#define U55_MXU55_PPU_PWPR_PWR_POLICY_Msk       0xFUL
#define U55_MXU55_PPU_PWPR_PWR_DYN_EN_Pos       8UL
#define U55_MXU55_PPU_PWPR_PWR_DYN_EN_Msk       0x100UL
#define U55_MXU55_PPU_PWPR_LOCK_EN_Pos          12UL
#define U55_MXU55_PPU_PWPR_LOCK_EN_Msk          0x1000UL
#define U55_MXU55_PPU_PWPR_OP_POLICY_Pos        16UL
#define U55_MXU55_PPU_PWPR_OP_POLICY_Msk        0xF0000UL
#define U55_MXU55_PPU_PWPR_OP_DYN_EN_Pos        24UL
#define U55_MXU55_PPU_PWPR_OP_DYN_EN_Msk        0x1000000UL
/* U55_MXU55_PPU.PMER */
#define U55_MXU55_PPU_PMER_EMU_EN_Pos           0UL
#define U55_MXU55_PPU_PMER_EMU_EN_Msk           0x1UL
/* U55_MXU55_PPU.PWSR */
#define U55_MXU55_PPU_PWSR_PWR_STATUS_Pos       0UL
#define U55_MXU55_PPU_PWSR_PWR_STATUS_Msk       0xFUL
#define U55_MXU55_PPU_PWSR_PWR_DYN_STATUS_Pos   8UL
#define U55_MXU55_PPU_PWSR_PWR_DYN_STATUS_Msk   0x100UL
#define U55_MXU55_PPU_PWSR_LOCK_STATUS_Pos      12UL
#define U55_MXU55_PPU_PWSR_LOCK_STATUS_Msk      0x1000UL
#define U55_MXU55_PPU_PWSR_OP_STATUS_Pos        16UL
#define U55_MXU55_PPU_PWSR_OP_STATUS_Msk        0xF0000UL
#define U55_MXU55_PPU_PWSR_OP_DYN_STATUS_Pos    24UL
#define U55_MXU55_PPU_PWSR_OP_DYN_STATUS_Msk    0x1000000UL
/* U55_MXU55_PPU.DISR */
#define U55_MXU55_PPU_DISR_PWR_DEVACTIVE_STATUS_Pos 0UL
#define U55_MXU55_PPU_DISR_PWR_DEVACTIVE_STATUS_Msk 0x7FFUL
#define U55_MXU55_PPU_DISR_OP_DEVACTIVE_STATUS_Pos 24UL
#define U55_MXU55_PPU_DISR_OP_DEVACTIVE_STATUS_Msk 0xFF000000UL
/* U55_MXU55_PPU.MISR */
#define U55_MXU55_PPU_MISR_PCSMPACCEPT_STATUS_Pos 0UL
#define U55_MXU55_PPU_MISR_PCSMPACCEPT_STATUS_Msk 0x1UL
#define U55_MXU55_PPU_MISR_DEVACCEPT_STATUS_Pos 8UL
#define U55_MXU55_PPU_MISR_DEVACCEPT_STATUS_Msk 0xFF00UL
#define U55_MXU55_PPU_MISR_DEVDENY_STATUS_Pos   16UL
#define U55_MXU55_PPU_MISR_DEVDENY_STATUS_Msk   0xFF0000UL
/* U55_MXU55_PPU.STSR */
#define U55_MXU55_PPU_STSR_STORED_DEVDENY_Pos   0UL
#define U55_MXU55_PPU_STSR_STORED_DEVDENY_Msk   0xFFUL
/* U55_MXU55_PPU.UNLK */
#define U55_MXU55_PPU_UNLK_UNLOCK_Pos           0UL
#define U55_MXU55_PPU_UNLK_UNLOCK_Msk           0x1UL
/* U55_MXU55_PPU.PWCR */
#define U55_MXU55_PPU_PWCR_DEVREQEN_Pos         0UL
#define U55_MXU55_PPU_PWCR_DEVREQEN_Msk         0xFFUL
#define U55_MXU55_PPU_PWCR_PWR_DEVACTIVEEN_Pos  8UL
#define U55_MXU55_PPU_PWCR_PWR_DEVACTIVEEN_Msk  0x7FF00UL
#define U55_MXU55_PPU_PWCR_OP_DEVACTIVEEN_Pos   24UL
#define U55_MXU55_PPU_PWCR_OP_DEVACTIVEEN_Msk   0xFF000000UL
/* U55_MXU55_PPU.PTCR */
#define U55_MXU55_PPU_PTCR_WARM_RST_DEVREQEN_Pos 0UL
#define U55_MXU55_PPU_PTCR_WARM_RST_DEVREQEN_Msk 0x1UL
#define U55_MXU55_PPU_PTCR_DBG_RECOV_PORST_EN_Pos 1UL
#define U55_MXU55_PPU_PTCR_DBG_RECOV_PORST_EN_Msk 0x2UL
/* U55_MXU55_PPU.IMR */
#define U55_MXU55_PPU_IMR_STA_POLICY_TRN_IRQ_MASK_Pos 0UL
#define U55_MXU55_PPU_IMR_STA_POLICY_TRN_IRQ_MASK_Msk 0x1UL
#define U55_MXU55_PPU_IMR_STA_ACCEPT_IRQ_MASK_Pos 1UL
#define U55_MXU55_PPU_IMR_STA_ACCEPT_IRQ_MASK_Msk 0x2UL
#define U55_MXU55_PPU_IMR_STA_DENY_IRQ_MASK_Pos 2UL
#define U55_MXU55_PPU_IMR_STA_DENY_IRQ_MASK_Msk 0x4UL
#define U55_MXU55_PPU_IMR_EMU_ACCEPT_IRQ_MASK_Pos 3UL
#define U55_MXU55_PPU_IMR_EMU_ACCEPT_IRQ_MASK_Msk 0x8UL
#define U55_MXU55_PPU_IMR_EMU_DENY_IRQ_MASK_Pos 4UL
#define U55_MXU55_PPU_IMR_EMU_DENY_IRQ_MASK_Msk 0x10UL
#define U55_MXU55_PPU_IMR_LOCKED_IRQ_MASK_Pos   5UL
#define U55_MXU55_PPU_IMR_LOCKED_IRQ_MASK_Msk   0x20UL
/* U55_MXU55_PPU.AIMR */
#define U55_MXU55_PPU_AIMR_UNSPT_POLICY_IRQ_MASK_Pos 0UL
#define U55_MXU55_PPU_AIMR_UNSPT_POLICY_IRQ_MASK_Msk 0x1UL
#define U55_MXU55_PPU_AIMR_DYN_ACCEPT_IRQ_MASK_Pos 1UL
#define U55_MXU55_PPU_AIMR_DYN_ACCEPT_IRQ_MASK_Msk 0x2UL
#define U55_MXU55_PPU_AIMR_DYN_DENY_IRQ_MASK_Pos 2UL
#define U55_MXU55_PPU_AIMR_DYN_DENY_IRQ_MASK_Msk 0x4UL
#define U55_MXU55_PPU_AIMR_STA_POLICY_PWR_IRQ_MASK_Pos 3UL
#define U55_MXU55_PPU_AIMR_STA_POLICY_PWR_IRQ_MASK_Msk 0x8UL
#define U55_MXU55_PPU_AIMR_STA_POLICY_OP_IRQ_MASK_Pos 4UL
#define U55_MXU55_PPU_AIMR_STA_POLICY_OP_IRQ_MASK_Msk 0x10UL
/* U55_MXU55_PPU.ISR */
#define U55_MXU55_PPU_ISR_STA_POLICY_TRN_IRQ_Pos 0UL
#define U55_MXU55_PPU_ISR_STA_POLICY_TRN_IRQ_Msk 0x1UL
#define U55_MXU55_PPU_ISR_STA_ACCEPT_IRQ_Pos    1UL
#define U55_MXU55_PPU_ISR_STA_ACCEPT_IRQ_Msk    0x2UL
#define U55_MXU55_PPU_ISR_STA_DENY_IRQ_Pos      2UL
#define U55_MXU55_PPU_ISR_STA_DENY_IRQ_Msk      0x4UL
#define U55_MXU55_PPU_ISR_EMU_ACCEPT_IRQ_Pos    3UL
#define U55_MXU55_PPU_ISR_EMU_ACCEPT_IRQ_Msk    0x8UL
#define U55_MXU55_PPU_ISR_EMU_DENY_IRQ_Pos      4UL
#define U55_MXU55_PPU_ISR_EMU_DENY_IRQ_Msk      0x10UL
#define U55_MXU55_PPU_ISR_LOCKED_IRQ_Pos        5UL
#define U55_MXU55_PPU_ISR_LOCKED_IRQ_Msk        0x20UL
#define U55_MXU55_PPU_ISR_OTHER_IRQ_Pos         7UL
#define U55_MXU55_PPU_ISR_OTHER_IRQ_Msk         0x80UL
#define U55_MXU55_PPU_ISR_PWR_ACTIVE_EDGE_IRQ_Pos 8UL
#define U55_MXU55_PPU_ISR_PWR_ACTIVE_EDGE_IRQ_Msk 0x7FF00UL
#define U55_MXU55_PPU_ISR_OP_ACTIVE_EDGE_IRQ_Pos 24UL
#define U55_MXU55_PPU_ISR_OP_ACTIVE_EDGE_IRQ_Msk 0xFF000000UL
/* U55_MXU55_PPU.AISR */
#define U55_MXU55_PPU_AISR_UNSPT_POLICY_IRQ_Pos 0UL
#define U55_MXU55_PPU_AISR_UNSPT_POLICY_IRQ_Msk 0x1UL
#define U55_MXU55_PPU_AISR_DYN_ACCEPT_IRQ_Pos   1UL
#define U55_MXU55_PPU_AISR_DYN_ACCEPT_IRQ_Msk   0x2UL
#define U55_MXU55_PPU_AISR_DYN_DENY_IRQ_Pos     2UL
#define U55_MXU55_PPU_AISR_DYN_DENY_IRQ_Msk     0x4UL
#define U55_MXU55_PPU_AISR_STA_POLICY_PWR_IRQ_Pos 3UL
#define U55_MXU55_PPU_AISR_STA_POLICY_PWR_IRQ_Msk 0x8UL
#define U55_MXU55_PPU_AISR_STA_POLICY_OP_IRQ_Pos 4UL
#define U55_MXU55_PPU_AISR_STA_POLICY_OP_IRQ_Msk 0x10UL
/* U55_MXU55_PPU.IESR */
#define U55_MXU55_PPU_IESR_DEVACTIVE00_EDGE_Pos 0UL
#define U55_MXU55_PPU_IESR_DEVACTIVE00_EDGE_Msk 0x3UL
#define U55_MXU55_PPU_IESR_DEVACTIVE01_EDGE_Pos 2UL
#define U55_MXU55_PPU_IESR_DEVACTIVE01_EDGE_Msk 0xCUL
#define U55_MXU55_PPU_IESR_DEVACTIVE02_EDGE_Pos 4UL
#define U55_MXU55_PPU_IESR_DEVACTIVE02_EDGE_Msk 0x30UL
#define U55_MXU55_PPU_IESR_DEVACTIVE03_EDGE_Pos 6UL
#define U55_MXU55_PPU_IESR_DEVACTIVE03_EDGE_Msk 0xC0UL
#define U55_MXU55_PPU_IESR_DEVACTIVE04_EDGE_Pos 8UL
#define U55_MXU55_PPU_IESR_DEVACTIVE04_EDGE_Msk 0x300UL
#define U55_MXU55_PPU_IESR_DEVACTIVE05_EDGE_Pos 10UL
#define U55_MXU55_PPU_IESR_DEVACTIVE05_EDGE_Msk 0xC00UL
#define U55_MXU55_PPU_IESR_DEVACTIVE06_EDGE_Pos 12UL
#define U55_MXU55_PPU_IESR_DEVACTIVE06_EDGE_Msk 0x3000UL
#define U55_MXU55_PPU_IESR_DEVACTIVE07_EDGE_Pos 14UL
#define U55_MXU55_PPU_IESR_DEVACTIVE07_EDGE_Msk 0xC000UL
#define U55_MXU55_PPU_IESR_DEVACTIVE08_EDGE_Pos 16UL
#define U55_MXU55_PPU_IESR_DEVACTIVE08_EDGE_Msk 0x30000UL
#define U55_MXU55_PPU_IESR_DEVACTIVE09_EDGE_Pos 18UL
#define U55_MXU55_PPU_IESR_DEVACTIVE09_EDGE_Msk 0xC0000UL
#define U55_MXU55_PPU_IESR_DEVACTIVE10_EDGE_Pos 20UL
#define U55_MXU55_PPU_IESR_DEVACTIVE10_EDGE_Msk 0x300000UL
/* U55_MXU55_PPU.OPSR */
#define U55_MXU55_PPU_OPSR_DEVACTIVE16_EDGE_Pos 0UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE16_EDGE_Msk 0x3UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE17_EDGE_Pos 2UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE17_EDGE_Msk 0xCUL
#define U55_MXU55_PPU_OPSR_DEVACTIVE18_EDGE_Pos 4UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE18_EDGE_Msk 0x30UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE19_EDGE_Pos 6UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE19_EDGE_Msk 0xC0UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE20_EDGE_Pos 8UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE20_EDGE_Msk 0x300UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE21_EDGE_Pos 10UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE21_EDGE_Msk 0xC00UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE22_EDGE_Pos 12UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE22_EDGE_Msk 0x3000UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE23_EDGE_Pos 14UL
#define U55_MXU55_PPU_OPSR_DEVACTIVE23_EDGE_Msk 0xC000UL
/* U55_MXU55_PPU.FUNRR */
#define U55_MXU55_PPU_FUNRR_FUNC_RET_RAM_CFG_Pos 0UL
#define U55_MXU55_PPU_FUNRR_FUNC_RET_RAM_CFG_Msk 0xFFUL
/* U55_MXU55_PPU.FULRR */
#define U55_MXU55_PPU_FULRR_FULL_RET_RAM_CFG_Pos 0UL
#define U55_MXU55_PPU_FULRR_FULL_RET_RAM_CFG_Msk 0xFFUL
/* U55_MXU55_PPU.MEMRR */
#define U55_MXU55_PPU_MEMRR_MEM_RET_RAM_CFG_Pos 0UL
#define U55_MXU55_PPU_MEMRR_MEM_RET_RAM_CFG_Msk 0xFFUL
/* U55_MXU55_PPU.EDTR0 */
#define U55_MXU55_PPU_EDTR0_OFF_DEL_Pos         0UL
#define U55_MXU55_PPU_EDTR0_OFF_DEL_Msk         0xFFUL
#define U55_MXU55_PPU_EDTR0_MEM_RET_DEL_Pos     8UL
#define U55_MXU55_PPU_EDTR0_MEM_RET_DEL_Msk     0xFF00UL
#define U55_MXU55_PPU_EDTR0_LOGIC_RET_DEL_Pos   16UL
#define U55_MXU55_PPU_EDTR0_LOGIC_RET_DEL_Msk   0xFF0000UL
#define U55_MXU55_PPU_EDTR0_FULL_RET_DEL_Pos    24UL
#define U55_MXU55_PPU_EDTR0_FULL_RET_DEL_Msk    0xFF000000UL
/* U55_MXU55_PPU.EDTR1 */
#define U55_MXU55_PPU_EDTR1_MEM_OFF_DEL_Pos     0UL
#define U55_MXU55_PPU_EDTR1_MEM_OFF_DEL_Msk     0xFFUL
#define U55_MXU55_PPU_EDTR1_FUNC_RET_DEL_Pos    8UL
#define U55_MXU55_PPU_EDTR1_FUNC_RET_DEL_Msk    0xFF00UL
/* U55_MXU55_PPU.DCDR0 */
#define U55_MXU55_PPU_DCDR0_CLKEN_RST_DLY_Pos   0UL
#define U55_MXU55_PPU_DCDR0_CLKEN_RST_DLY_Msk   0xFFUL
#define U55_MXU55_PPU_DCDR0_ISO_CLKEN_DLY_Pos   8UL
#define U55_MXU55_PPU_DCDR0_ISO_CLKEN_DLY_Msk   0xFF00UL
#define U55_MXU55_PPU_DCDR0_RST_HWSTAT_DLY_Pos  16UL
#define U55_MXU55_PPU_DCDR0_RST_HWSTAT_DLY_Msk  0xFF0000UL
/* U55_MXU55_PPU.DCDR1 */
#define U55_MXU55_PPU_DCDR1_ISO_RST_DLY_Pos     0UL
#define U55_MXU55_PPU_DCDR1_ISO_RST_DLY_Msk     0xFFUL
#define U55_MXU55_PPU_DCDR1_CLKEN_ISO_DLY_Pos   8UL
#define U55_MXU55_PPU_DCDR1_CLKEN_ISO_DLY_Msk   0xFF00UL
/* U55_MXU55_PPU.IDR0 */
#define U55_MXU55_PPU_IDR0_DEVCHAN_Pos          0UL
#define U55_MXU55_PPU_IDR0_DEVCHAN_Msk          0xFUL
#define U55_MXU55_PPU_IDR0_NUM_OPMODE_Pos       4UL
#define U55_MXU55_PPU_IDR0_NUM_OPMODE_Msk       0xF0UL
#define U55_MXU55_PPU_IDR0_STA_OFF_SPT_Pos      8UL
#define U55_MXU55_PPU_IDR0_STA_OFF_SPT_Msk      0x100UL
#define U55_MXU55_PPU_IDR0_STA_OFF_EMU_SPT_Pos  9UL
#define U55_MXU55_PPU_IDR0_STA_OFF_EMU_SPT_Msk  0x200UL
#define U55_MXU55_PPU_IDR0_STA_MEM_RET_SPT_Pos  10UL
#define U55_MXU55_PPU_IDR0_STA_MEM_RET_SPT_Msk  0x400UL
#define U55_MXU55_PPU_IDR0_STA_MEM_RET_EMU_SPT_Pos 11UL
#define U55_MXU55_PPU_IDR0_STA_MEM_RET_EMU_SPT_Msk 0x800UL
#define U55_MXU55_PPU_IDR0_STA_LGC_RET_SPT_Pos  12UL
#define U55_MXU55_PPU_IDR0_STA_LGC_RET_SPT_Msk  0x1000UL
#define U55_MXU55_PPU_IDR0_STA_MEM_OFF_SPT_Pos  13UL
#define U55_MXU55_PPU_IDR0_STA_MEM_OFF_SPT_Msk  0x2000UL
#define U55_MXU55_PPU_IDR0_STA_FULL_RET_SPT_Pos 14UL
#define U55_MXU55_PPU_IDR0_STA_FULL_RET_SPT_Msk 0x4000UL
#define U55_MXU55_PPU_IDR0_STA_FUNC_RET_SPT_Pos 15UL
#define U55_MXU55_PPU_IDR0_STA_FUNC_RET_SPT_Msk 0x8000UL
#define U55_MXU55_PPU_IDR0_STA_ON_SPT_Pos       16UL
#define U55_MXU55_PPU_IDR0_STA_ON_SPT_Msk       0x10000UL
#define U55_MXU55_PPU_IDR0_STA_WRM_RST_SPT_Pos  17UL
#define U55_MXU55_PPU_IDR0_STA_WRM_RST_SPT_Msk  0x20000UL
#define U55_MXU55_PPU_IDR0_STA_DBG_RECOV_SPT_Pos 18UL
#define U55_MXU55_PPU_IDR0_STA_DBG_RECOV_SPT_Msk 0x40000UL
#define U55_MXU55_PPU_IDR0_DYN_OFF_SPT_Pos      20UL
#define U55_MXU55_PPU_IDR0_DYN_OFF_SPT_Msk      0x100000UL
#define U55_MXU55_PPU_IDR0_DYN_OFF_EMU_SPT_Pos  21UL
#define U55_MXU55_PPU_IDR0_DYN_OFF_EMU_SPT_Msk  0x200000UL
#define U55_MXU55_PPU_IDR0_DYN_MEM_RET_SPT_Pos  22UL
#define U55_MXU55_PPU_IDR0_DYN_MEM_RET_SPT_Msk  0x400000UL
#define U55_MXU55_PPU_IDR0_DYN_MEM_RET_EMU_SPT_Pos 23UL
#define U55_MXU55_PPU_IDR0_DYN_MEM_RET_EMU_SPT_Msk 0x800000UL
#define U55_MXU55_PPU_IDR0_DYN_LGC_RET_SPT_Pos  24UL
#define U55_MXU55_PPU_IDR0_DYN_LGC_RET_SPT_Msk  0x1000000UL
#define U55_MXU55_PPU_IDR0_DYN_MEM_OFF_SPT_Pos  25UL
#define U55_MXU55_PPU_IDR0_DYN_MEM_OFF_SPT_Msk  0x2000000UL
#define U55_MXU55_PPU_IDR0_DYN_FULL_RET_SPT_Pos 26UL
#define U55_MXU55_PPU_IDR0_DYN_FULL_RET_SPT_Msk 0x4000000UL
#define U55_MXU55_PPU_IDR0_DYN_FUNC_RET_SPT_Pos 27UL
#define U55_MXU55_PPU_IDR0_DYN_FUNC_RET_SPT_Msk 0x8000000UL
#define U55_MXU55_PPU_IDR0_DYN_ON_SPT_Pos       28UL
#define U55_MXU55_PPU_IDR0_DYN_ON_SPT_Msk       0x10000000UL
#define U55_MXU55_PPU_IDR0_DYN_WRM_RST_SPT_Pos  29UL
#define U55_MXU55_PPU_IDR0_DYN_WRM_RST_SPT_Msk  0x20000000UL
/* U55_MXU55_PPU.IDR1 */
#define U55_MXU55_PPU_IDR1_PWR_MODE_ENTRY_DEL_SPT_Pos 0UL
#define U55_MXU55_PPU_IDR1_PWR_MODE_ENTRY_DEL_SPT_Msk 0x1UL
#define U55_MXU55_PPU_IDR1_SW_DEV_DEL_SPT_Pos   1UL
#define U55_MXU55_PPU_IDR1_SW_DEV_DEL_SPT_Msk   0x2UL
#define U55_MXU55_PPU_IDR1_LOCK_SPT_Pos         2UL
#define U55_MXU55_PPU_IDR1_LOCK_SPT_Msk         0x4UL
#define U55_MXU55_PPU_IDR1_MEM_RET_RAM_REG_Pos  4UL
#define U55_MXU55_PPU_IDR1_MEM_RET_RAM_REG_Msk  0x10UL
#define U55_MXU55_PPU_IDR1_FULL_RET_RAM_REG_Pos 5UL
#define U55_MXU55_PPU_IDR1_FULL_RET_RAM_REG_Msk 0x20UL
#define U55_MXU55_PPU_IDR1_FUNC_RET_RAM_REG_Pos 6UL
#define U55_MXU55_PPU_IDR1_FUNC_RET_RAM_REG_Msk 0x40UL
#define U55_MXU55_PPU_IDR1_STA_POLICY_PWR_IRQ_SPT_Pos 8UL
#define U55_MXU55_PPU_IDR1_STA_POLICY_PWR_IRQ_SPT_Msk 0x100UL
#define U55_MXU55_PPU_IDR1_STA_POLICY_OP_IRQ_SPT_Pos 9UL
#define U55_MXU55_PPU_IDR1_STA_POLICY_OP_IRQ_SPT_Msk 0x200UL
#define U55_MXU55_PPU_IDR1_OP_ACTIVE_Pos        10UL
#define U55_MXU55_PPU_IDR1_OP_ACTIVE_Msk        0x400UL
#define U55_MXU55_PPU_IDR1_OFF_MEM_RET_TRANS_Pos 12UL
#define U55_MXU55_PPU_IDR1_OFF_MEM_RET_TRANS_Msk 0x1000UL
/* U55_MXU55_PPU.IIDR */
#define U55_MXU55_PPU_IIDR_IMPLEMENTER_Pos      0UL
#define U55_MXU55_PPU_IIDR_IMPLEMENTER_Msk      0xFFFUL
#define U55_MXU55_PPU_IIDR_REVISION_Pos         12UL
#define U55_MXU55_PPU_IIDR_REVISION_Msk         0xF000UL
#define U55_MXU55_PPU_IIDR_VARIANT_Pos          16UL
#define U55_MXU55_PPU_IIDR_VARIANT_Msk          0xF0000UL
#define U55_MXU55_PPU_IIDR_PRODUCT_ID_Pos       20UL
#define U55_MXU55_PPU_IIDR_PRODUCT_ID_Msk       0xFFF00000UL
/* U55_MXU55_PPU.AIDR */
#define U55_MXU55_PPU_AIDR_ARCH_REV_MINOR_Pos   0UL
#define U55_MXU55_PPU_AIDR_ARCH_REV_MINOR_Msk   0xFUL
#define U55_MXU55_PPU_AIDR_ARCH_REV_MAJOR_Pos   4UL
#define U55_MXU55_PPU_AIDR_ARCH_REV_MAJOR_Msk   0xF0UL
/* U55_MXU55_PPU.PID4 */
#define U55_MXU55_PPU_PID4_IMPLEMENTER_11_8_Pos 0UL
#define U55_MXU55_PPU_PID4_IMPLEMENTER_11_8_Msk 0xFUL
/* U55_MXU55_PPU.PID0 */
#define U55_MXU55_PPU_PID0_PRODUCT_ID_7_0_Pos   0UL
#define U55_MXU55_PPU_PID0_PRODUCT_ID_7_0_Msk   0xFFUL
/* U55_MXU55_PPU.PID1 */
#define U55_MXU55_PPU_PID1_PRODUCT_ID_11_8_Pos  0UL
#define U55_MXU55_PPU_PID1_PRODUCT_ID_11_8_Msk  0xFUL
#define U55_MXU55_PPU_PID1_IMPLEMENTER_3_0_Pos  4UL
#define U55_MXU55_PPU_PID1_IMPLEMENTER_3_0_Msk  0xF0UL
/* U55_MXU55_PPU.PID2 */
#define U55_MXU55_PPU_PID2_JEP106_ID_6_4_Pos    0UL
#define U55_MXU55_PPU_PID2_JEP106_ID_6_4_Msk    0x7UL
#define U55_MXU55_PPU_PID2_JDEC_Pos             3UL
#define U55_MXU55_PPU_PID2_JDEC_Msk             0x8UL
#define U55_MXU55_PPU_PID2_REV_Pos              4UL
#define U55_MXU55_PPU_PID2_REV_Msk              0xF0UL
/* U55_MXU55_PPU.PID3 */
#define U55_MXU55_PPU_PID3_PID3_REV_CONST_Pos   0UL
#define U55_MXU55_PPU_PID3_PID3_REV_CONST_Msk   0xFUL
#define U55_MXU55_PPU_PID3_PID3_REVISION_Pos    4UL
#define U55_MXU55_PPU_PID3_PID3_REVISION_Msk    0xF0UL
/* U55_MXU55_PPU.ID0 */
#define U55_MXU55_PPU_ID0_ID0_Pos               0UL
#define U55_MXU55_PPU_ID0_ID0_Msk               0xFFUL
/* U55_MXU55_PPU.ID1 */
#define U55_MXU55_PPU_ID1_ID1_Pos               0UL
#define U55_MXU55_PPU_ID1_ID1_Msk               0xFFUL
/* U55_MXU55_PPU.ID2 */
#define U55_MXU55_PPU_ID2_ID2_Pos               0UL
#define U55_MXU55_PPU_ID2_ID2_Msk               0xFFUL
/* U55_MXU55_PPU.ID3 */
#define U55_MXU55_PPU_ID3_ID3_Pos               0UL
#define U55_MXU55_PPU_ID3_ID3_Msk               0xFFUL


/* U55_PD.CTL */
#define U55_PD_CTL_BLEED_EN_Pos                 0UL
#define U55_PD_CTL_BLEED_EN_Msk                 0x1UL
/* U55_PD.PWR_UP_DELAY */
#define U55_PD_PWR_UP_DELAY_COUNT_LOAD_Pos      0UL
#define U55_PD_PWR_UP_DELAY_COUNT_LOAD_Msk      0xFFUL
#define U55_PD_PWR_UP_DELAY_MEM_COUNT_LOAD_Pos  8UL
#define U55_PD_PWR_UP_DELAY_MEM_COUNT_LOAD_Msk  0xFF00UL


#endif /* _CYIP_U55_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* SOCMEM IP definitions
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

#ifndef _CYIP_SOCMEM_H_
#define _CYIP_SOCMEM_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    SOCMEM
*******************************************************************************/

#define SOCMEM_SRAM_MPC_SECTION_SIZE            0x00001000UL
#define SOCMEM_SRAM_SECTION_SIZE                0x00001000UL
#define SOCMEM_SROM_MPC_SECTION_SIZE            0x00001000UL
#define SOCMEM_SROM_SECTION_SIZE                0x00001000UL
#define SOCMEM_PORT_STRUCT_SECTION_SIZE         0x00001000UL
#define SOCMEM_PPU_SOCMEM_SECTION_SIZE          0x00001000UL
#define SOCMEM_SOCMEM_PD_SECTION_SIZE           0x00000020UL
#define SOCMEM_SOCMEM_SECTION_SIZE              0x00001000UL
#define SOCMEM_SECTION_SIZE                     0x00040000UL

/**
  * \brief MPC Memory Protection Controller registers (SOCMEM_SRAM_MPC)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 Config register with error response, RegionID PPC_MPC_MAIN is
                                                                the security owner PC. The error response configuration is
                                                                located in CFG.RESPONSE, only one such configuration exists
                                                                applying to all protection contexts in the system. */
   __IM uint32_t RESERVED[63];
  __IOM uint32_t CTRL;                          /*!< 0x00000100 Control register with lock bit and auto-increment only
                                                                (Separate CTRL for each PC depends on access_pc) */
   __IM uint32_t BLK_MAX;                       /*!< 0x00000104 Max value of block-based index register */
   __IM uint32_t BLK_CFG;                       /*!< 0x00000108 Block size & initialization in progress */
  __IOM uint32_t BLK_IDX;                       /*!< 0x0000010C Index of 32-block group accessed through BLK_LUT (Separate IDX
                                                                for each PC depending on access_pc) */
  __IOM uint32_t BLK_LUT;                       /*!< 0x00000110 NS status for 32 blocks at BLK_IDX with PC=<access_pc> */
   __IM uint32_t RESERVED1[59];
  __IOM uint32_t ROT_CTRL;                      /*!< 0x00000200 Control register with lock bit and auto-increment only */
   __IM uint32_t RESERVED2;
   __IM uint32_t ROT_BLK_MAX;                   /*!< 0x00000208 Max value of block-based index register for ROT */
   __IM uint32_t ROT_BLK_CFG;                   /*!< 0x0000020C Same as BLK_CFG */
  __IOM uint32_t ROT_BLK_IDX;                   /*!< 0x00000210 Index of 8-block group accessed through ROT_BLK_LUT_* */
  __IOM uint32_t ROT_BLK_PC;                    /*!< 0x00000214 Protection context of 8-block group accesses through
                                                                ROT_BLK_LUT */
  __IOM uint32_t ROT_BLK_LUT;                   /*!< 0x00000218 (R,W,NS) bits for 8 blocks at ROT_BLK_IDX for PC=ROT_BKL_PC */
   __IM uint32_t RESERVED3[889];
} SOCMEM_SRAM_MPC_Type;                         /*!< Size = 4096 (0x1000) */

/**
  * \brief SRAM MPC (SOCMEM_SRAM)
  */
typedef struct {
        SOCMEM_SRAM_MPC_Type MPC[1];            /*!< 0x00000000 MPC Memory Protection Controller registers */
} SOCMEM_SRAM_Type;                             /*!< Size = 4096 (0x1000) */

/**
  * \brief MPC Memory Protection Controller registers (SOCMEM_SROM_MPC)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 Config register with error response, RegionID PPC_MPC_MAIN is
                                                                the security owner PC. The error response configuration is
                                                                located in CFG.RESPONSE, only one such configuration exists
                                                                applying to all protection contexts in the system. */
   __IM uint32_t RESERVED[63];
  __IOM uint32_t CTRL;                          /*!< 0x00000100 Control register with lock bit and auto-increment only
                                                                (Separate CTRL for each PC depends on access_pc) */
   __IM uint32_t BLK_MAX;                       /*!< 0x00000104 Max value of block-based index register */
   __IM uint32_t BLK_CFG;                       /*!< 0x00000108 Block size & initialization in progress */
  __IOM uint32_t BLK_IDX;                       /*!< 0x0000010C Index of 32-block group accessed through BLK_LUT (Separate IDX
                                                                for each PC depending on access_pc) */
  __IOM uint32_t BLK_LUT;                       /*!< 0x00000110 NS status for 32 blocks at BLK_IDX with PC=<access_pc> */
   __IM uint32_t RESERVED1[59];
  __IOM uint32_t ROT_CTRL;                      /*!< 0x00000200 Control register with lock bit and auto-increment only */
   __IM uint32_t RESERVED2;
   __IM uint32_t ROT_BLK_MAX;                   /*!< 0x00000208 Max value of block-based index register for ROT */
   __IM uint32_t ROT_BLK_CFG;                   /*!< 0x0000020C Same as BLK_CFG */
  __IOM uint32_t ROT_BLK_IDX;                   /*!< 0x00000210 Index of 8-block group accessed through ROT_BLK_LUT_* */
  __IOM uint32_t ROT_BLK_PC;                    /*!< 0x00000214 Protection context of 8-block group accesses through
                                                                ROT_BLK_LUT */
  __IOM uint32_t ROT_BLK_LUT;                   /*!< 0x00000218 (R,W,NS) bits for 8 blocks at ROT_BLK_IDX for PC=ROT_BKL_PC */
   __IM uint32_t RESERVED3[889];
} SOCMEM_SROM_MPC_Type;                         /*!< Size = 4096 (0x1000) */

/**
  * \brief SROM MPC (SOCMEM_SROM)
  */
typedef struct {
        SOCMEM_SROM_MPC_Type MPC[1];            /*!< 0x00000000 MPC Memory Protection Controller registers */
} SOCMEM_SROM_Type;                             /*!< Size = 4096 (0x1000) */

/**
  * \brief Port structure (SOCMEM_PORT_STRUCT)
  */
typedef struct {
  __IOM uint32_t PATCH_CTL;                     /*!< 0x00000000 Patch control */
   __IM uint32_t PATCH_STATUS;                  /*!< 0x00000004 Patch status */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t PATCH_SROM;                    /*!< 0x00000010 Patch SROM boundary */
  __IOM uint32_t PATCH_SRAM;                    /*!< 0x00000014 Patch SRAM address */
   __IM uint32_t RESERVED1[2];
   __IM uint32_t PATCH_CFG;                     /*!< 0x00000020 Patch configuration */
   __IM uint32_t RESERVED2[503];
  __IOM uint32_t PATCH_STRUCT_CTL[512];         /*!< 0x00000800 Patch structure control */
} SOCMEM_PORT_STRUCT_Type;                      /*!< Size = 4096 (0x1000) */

/**
  * \brief Power Policy Unit Registers for SOCMEM PPU (SOCMEM_PPU_SOCMEM)
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
} SOCMEM_PPU_SOCMEM_Type;                       /*!< Size = 4096 (0x1000) */

/**
  * \brief Power Domain Controller (SOCMEM_SOCMEM_PD)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Power Domain Control */
  __IOM uint32_t PWR_UP_DELAY;                  /*!< 0x00000004 Active switch weak enable to active switch strong enable delay */
   __IM uint32_t RESERVED[6];
} SOCMEM_SOCMEM_PD_Type;                        /*!< Size = 32 (0x20) */

/**
  * \brief Power Domain controller (SOCMEM_SOCMEM)
  */
typedef struct {
        SOCMEM_SOCMEM_PD_Type PD;               /*!< 0x00000000 Power Domain Controller */
   __IM uint32_t RESERVED[1016];
} SOCMEM_SOCMEM_Type;                           /*!< Size = 4096 (0x1000) */

/**
  * \brief SoC memory (SOCMEM)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Status */
  __IOM uint32_t GK_CTL;                        /*!< 0x00000008 Gate keeper control */
   __IM uint32_t GK_STATUS;                     /*!< 0x0000000C Gate keeper status */
  __IOM uint32_t ARB_DYN_CTL[16];               /*!< 0x00000010 Port arbitration control */
   __IM uint32_t RESERVED[4];
  __IOM uint32_t MPC_READ_PORT_CTL;             /*!< 0x00000060 MPC MMIO read port index control */
   __IM uint32_t RESERVED1[39];
  __IOM uint32_t ECC_CTL;                       /*!< 0x00000100 ECC control */
  __IOM uint32_t ECC_MATCH;                     /*!< 0x00000104 ECC match */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t WOUNDING;                      /*!< 0x00000110 Wounding */
   __IM uint32_t RESERVED3[59];
  __IOM uint32_t PWR_PARTITION_CTL[16];         /*!< 0x00000200 SRAM partition power control */
   __IM uint32_t RESERVED4[16];
  __IOM uint32_t PWR_PARTITION_CTL_LOCK;        /*!< 0x00000280 SRAM power partition control Lock */
  __IOM uint32_t PWR_DELAY_CTL;                 /*!< 0x00000284 SRAM power switch power up & sequence delay */
   __IM uint32_t PWR_STATUS;                    /*!< 0x00000288 SRAM power status */
   __IM uint32_t RESERVED5[1885];
        SOCMEM_SRAM_Type SRAM;                  /*!< 0x00002000 SRAM MPC */
        SOCMEM_SROM_Type SROM;                  /*!< 0x00003000 SROM MPC */
   __IM uint32_t RESERVED6[12288];
        SOCMEM_PORT_STRUCT_Type PORT_STRUCT[16]; /*!< 0x00010000 Port structure */
        SOCMEM_PPU_SOCMEM_Type PPU_SOCMEM;      /*!< 0x00020000 Power Policy Unit Registers for SOCMEM PPU */
        SOCMEM_SOCMEM_Type SOCMEM;              /*!< 0x00021000 Power Domain controller */
} SOCMEM_Type;                                  /*!< Size = 139264 (0x22000) */


/* SOCMEM_SRAM_MPC.CFG */
#define SOCMEM_SRAM_MPC_CFG_RESPONSE_Pos        4UL
#define SOCMEM_SRAM_MPC_CFG_RESPONSE_Msk        0x10UL
/* SOCMEM_SRAM_MPC.CTRL */
#define SOCMEM_SRAM_MPC_CTRL_AUTO_INC_Pos       8UL
#define SOCMEM_SRAM_MPC_CTRL_AUTO_INC_Msk       0x100UL
#define SOCMEM_SRAM_MPC_CTRL_LOCK_Pos           31UL
#define SOCMEM_SRAM_MPC_CTRL_LOCK_Msk           0x80000000UL
/* SOCMEM_SRAM_MPC.BLK_MAX */
#define SOCMEM_SRAM_MPC_BLK_MAX_VALUE_Pos       0UL
#define SOCMEM_SRAM_MPC_BLK_MAX_VALUE_Msk       0xFFFFFFFFUL
/* SOCMEM_SRAM_MPC.BLK_CFG */
#define SOCMEM_SRAM_MPC_BLK_CFG_BLOCK_SIZE_Pos  0UL
#define SOCMEM_SRAM_MPC_BLK_CFG_BLOCK_SIZE_Msk  0xFUL
#define SOCMEM_SRAM_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SOCMEM_SRAM_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SOCMEM_SRAM_MPC.BLK_IDX */
#define SOCMEM_SRAM_MPC_BLK_IDX_VALUE_Pos       0UL
#define SOCMEM_SRAM_MPC_BLK_IDX_VALUE_Msk       0xFFFFFFFFUL
/* SOCMEM_SRAM_MPC.BLK_LUT */
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS0_Pos    0UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS0_Msk    0x1UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS1_Pos    1UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS1_Msk    0x2UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS2_Pos    2UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS2_Msk    0x4UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS3_Pos    3UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS3_Msk    0x8UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS4_Pos    4UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS4_Msk    0x10UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS5_Pos    5UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS5_Msk    0x20UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS6_Pos    6UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS6_Msk    0x40UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS7_Pos    7UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS7_Msk    0x80UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS8_Pos    8UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS8_Msk    0x100UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS9_Pos    9UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS9_Msk    0x200UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS10_Pos   10UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS10_Msk   0x400UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS11_Pos   11UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS11_Msk   0x800UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS12_Pos   12UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS12_Msk   0x1000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS13_Pos   13UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS13_Msk   0x2000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS14_Pos   14UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS14_Msk   0x4000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS15_Pos   15UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS15_Msk   0x8000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS16_Pos   16UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS16_Msk   0x10000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS17_Pos   17UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS17_Msk   0x20000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS18_Pos   18UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS18_Msk   0x40000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS19_Pos   19UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS19_Msk   0x80000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS20_Pos   20UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS20_Msk   0x100000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS21_Pos   21UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS21_Msk   0x200000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS22_Pos   22UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS22_Msk   0x400000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS23_Pos   23UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS23_Msk   0x800000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS24_Pos   24UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS24_Msk   0x1000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS25_Pos   25UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS25_Msk   0x2000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS26_Pos   26UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS26_Msk   0x4000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS27_Pos   27UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS27_Msk   0x8000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS28_Pos   28UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS28_Msk   0x10000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS29_Pos   29UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS29_Msk   0x20000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS30_Pos   30UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS30_Msk   0x40000000UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS31_Pos   31UL
#define SOCMEM_SRAM_MPC_BLK_LUT_ATTR_NS31_Msk   0x80000000UL
/* SOCMEM_SRAM_MPC.ROT_CTRL */
#define SOCMEM_SRAM_MPC_ROT_CTRL_AUTO_INC_Pos   8UL
#define SOCMEM_SRAM_MPC_ROT_CTRL_AUTO_INC_Msk   0x100UL
#define SOCMEM_SRAM_MPC_ROT_CTRL_LOCK_Pos       31UL
#define SOCMEM_SRAM_MPC_ROT_CTRL_LOCK_Msk       0x80000000UL
/* SOCMEM_SRAM_MPC.ROT_BLK_MAX */
#define SOCMEM_SRAM_MPC_ROT_BLK_MAX_VALUE_Pos   0UL
#define SOCMEM_SRAM_MPC_ROT_BLK_MAX_VALUE_Msk   0xFFFFFFFFUL
/* SOCMEM_SRAM_MPC.ROT_BLK_CFG */
#define SOCMEM_SRAM_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define SOCMEM_SRAM_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define SOCMEM_SRAM_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SOCMEM_SRAM_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SOCMEM_SRAM_MPC.ROT_BLK_IDX */
#define SOCMEM_SRAM_MPC_ROT_BLK_IDX_VALUE_Pos   0UL
#define SOCMEM_SRAM_MPC_ROT_BLK_IDX_VALUE_Msk   0xFFFFFFFFUL
/* SOCMEM_SRAM_MPC.ROT_BLK_PC */
#define SOCMEM_SRAM_MPC_ROT_BLK_PC_PC_Pos       0UL
#define SOCMEM_SRAM_MPC_ROT_BLK_PC_PC_Msk       0xFUL
/* SOCMEM_SRAM_MPC.ROT_BLK_LUT */
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR0_Pos   0UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR0_Msk   0x7UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR1_Pos   4UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR1_Msk   0x70UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR2_Pos   8UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR2_Msk   0x700UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR3_Pos   12UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR3_Msk   0x7000UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR4_Pos   16UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR4_Msk   0x70000UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR5_Pos   20UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR5_Msk   0x700000UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR6_Pos   24UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR6_Msk   0x7000000UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR7_Pos   28UL
#define SOCMEM_SRAM_MPC_ROT_BLK_LUT_ATTR7_Msk   0x70000000UL


/* SOCMEM_SROM_MPC.CFG */
#define SOCMEM_SROM_MPC_CFG_RESPONSE_Pos        4UL
#define SOCMEM_SROM_MPC_CFG_RESPONSE_Msk        0x10UL
/* SOCMEM_SROM_MPC.CTRL */
#define SOCMEM_SROM_MPC_CTRL_AUTO_INC_Pos       8UL
#define SOCMEM_SROM_MPC_CTRL_AUTO_INC_Msk       0x100UL
#define SOCMEM_SROM_MPC_CTRL_LOCK_Pos           31UL
#define SOCMEM_SROM_MPC_CTRL_LOCK_Msk           0x80000000UL
/* SOCMEM_SROM_MPC.BLK_MAX */
#define SOCMEM_SROM_MPC_BLK_MAX_VALUE_Pos       0UL
#define SOCMEM_SROM_MPC_BLK_MAX_VALUE_Msk       0xFFFFFFFFUL
/* SOCMEM_SROM_MPC.BLK_CFG */
#define SOCMEM_SROM_MPC_BLK_CFG_BLOCK_SIZE_Pos  0UL
#define SOCMEM_SROM_MPC_BLK_CFG_BLOCK_SIZE_Msk  0xFUL
#define SOCMEM_SROM_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SOCMEM_SROM_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SOCMEM_SROM_MPC.BLK_IDX */
#define SOCMEM_SROM_MPC_BLK_IDX_VALUE_Pos       0UL
#define SOCMEM_SROM_MPC_BLK_IDX_VALUE_Msk       0xFFFFFFFFUL
/* SOCMEM_SROM_MPC.BLK_LUT */
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS0_Pos    0UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS0_Msk    0x1UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS1_Pos    1UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS1_Msk    0x2UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS2_Pos    2UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS2_Msk    0x4UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS3_Pos    3UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS3_Msk    0x8UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS4_Pos    4UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS4_Msk    0x10UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS5_Pos    5UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS5_Msk    0x20UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS6_Pos    6UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS6_Msk    0x40UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS7_Pos    7UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS7_Msk    0x80UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS8_Pos    8UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS8_Msk    0x100UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS9_Pos    9UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS9_Msk    0x200UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS10_Pos   10UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS10_Msk   0x400UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS11_Pos   11UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS11_Msk   0x800UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS12_Pos   12UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS12_Msk   0x1000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS13_Pos   13UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS13_Msk   0x2000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS14_Pos   14UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS14_Msk   0x4000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS15_Pos   15UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS15_Msk   0x8000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS16_Pos   16UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS16_Msk   0x10000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS17_Pos   17UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS17_Msk   0x20000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS18_Pos   18UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS18_Msk   0x40000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS19_Pos   19UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS19_Msk   0x80000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS20_Pos   20UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS20_Msk   0x100000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS21_Pos   21UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS21_Msk   0x200000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS22_Pos   22UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS22_Msk   0x400000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS23_Pos   23UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS23_Msk   0x800000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS24_Pos   24UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS24_Msk   0x1000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS25_Pos   25UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS25_Msk   0x2000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS26_Pos   26UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS26_Msk   0x4000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS27_Pos   27UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS27_Msk   0x8000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS28_Pos   28UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS28_Msk   0x10000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS29_Pos   29UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS29_Msk   0x20000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS30_Pos   30UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS30_Msk   0x40000000UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS31_Pos   31UL
#define SOCMEM_SROM_MPC_BLK_LUT_ATTR_NS31_Msk   0x80000000UL
/* SOCMEM_SROM_MPC.ROT_CTRL */
#define SOCMEM_SROM_MPC_ROT_CTRL_AUTO_INC_Pos   8UL
#define SOCMEM_SROM_MPC_ROT_CTRL_AUTO_INC_Msk   0x100UL
#define SOCMEM_SROM_MPC_ROT_CTRL_LOCK_Pos       31UL
#define SOCMEM_SROM_MPC_ROT_CTRL_LOCK_Msk       0x80000000UL
/* SOCMEM_SROM_MPC.ROT_BLK_MAX */
#define SOCMEM_SROM_MPC_ROT_BLK_MAX_VALUE_Pos   0UL
#define SOCMEM_SROM_MPC_ROT_BLK_MAX_VALUE_Msk   0xFFFFFFFFUL
/* SOCMEM_SROM_MPC.ROT_BLK_CFG */
#define SOCMEM_SROM_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define SOCMEM_SROM_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define SOCMEM_SROM_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SOCMEM_SROM_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SOCMEM_SROM_MPC.ROT_BLK_IDX */
#define SOCMEM_SROM_MPC_ROT_BLK_IDX_VALUE_Pos   0UL
#define SOCMEM_SROM_MPC_ROT_BLK_IDX_VALUE_Msk   0xFFFFFFFFUL
/* SOCMEM_SROM_MPC.ROT_BLK_PC */
#define SOCMEM_SROM_MPC_ROT_BLK_PC_PC_Pos       0UL
#define SOCMEM_SROM_MPC_ROT_BLK_PC_PC_Msk       0xFUL
/* SOCMEM_SROM_MPC.ROT_BLK_LUT */
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR0_Pos   0UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR0_Msk   0x7UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR1_Pos   4UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR1_Msk   0x70UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR2_Pos   8UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR2_Msk   0x700UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR3_Pos   12UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR3_Msk   0x7000UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR4_Pos   16UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR4_Msk   0x70000UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR5_Pos   20UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR5_Msk   0x700000UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR6_Pos   24UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR6_Msk   0x7000000UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR7_Pos   28UL
#define SOCMEM_SROM_MPC_ROT_BLK_LUT_ATTR7_Msk   0x70000000UL


/* SOCMEM_PORT_STRUCT.PATCH_CTL */
#define SOCMEM_PORT_STRUCT_PATCH_CTL_ENABLED_Pos 31UL
#define SOCMEM_PORT_STRUCT_PATCH_CTL_ENABLED_Msk 0x80000000UL
/* SOCMEM_PORT_STRUCT.PATCH_STATUS */
#define SOCMEM_PORT_STRUCT_PATCH_STATUS_PATCH_IDX_Pos 0UL
#define SOCMEM_PORT_STRUCT_PATCH_STATUS_PATCH_IDX_Msk 0x1FFUL
#define SOCMEM_PORT_STRUCT_PATCH_STATUS_PATCH_VALID_Pos 31UL
#define SOCMEM_PORT_STRUCT_PATCH_STATUS_PATCH_VALID_Msk 0x80000000UL
/* SOCMEM_PORT_STRUCT.PATCH_SROM */
#define SOCMEM_PORT_STRUCT_PATCH_SROM_BOUNDARY_Pos 0UL
#define SOCMEM_PORT_STRUCT_PATCH_SROM_BOUNDARY_Msk 0xFFFFFFFFUL
/* SOCMEM_PORT_STRUCT.PATCH_SRAM */
#define SOCMEM_PORT_STRUCT_PATCH_SRAM_ADDR_Pos  0UL
#define SOCMEM_PORT_STRUCT_PATCH_SRAM_ADDR_Msk  0xFFFFFFFFUL
/* SOCMEM_PORT_STRUCT.PATCH_CFG */
#define SOCMEM_PORT_STRUCT_PATCH_CFG_PATCH_NR_Pos 0UL
#define SOCMEM_PORT_STRUCT_PATCH_CFG_PATCH_NR_Msk 0x3FFUL
#define SOCMEM_PORT_STRUCT_PATCH_CFG_PATCH_SIZE_Pos 16UL
#define SOCMEM_PORT_STRUCT_PATCH_CFG_PATCH_SIZE_Msk 0x30000UL
/* SOCMEM_PORT_STRUCT.PATCH_STRUCT_CTL */
#define SOCMEM_PORT_STRUCT_PATCH_STRUCT_CTL_VALID_Pos 0UL
#define SOCMEM_PORT_STRUCT_PATCH_STRUCT_CTL_VALID_Msk 0x1UL
#define SOCMEM_PORT_STRUCT_PATCH_STRUCT_CTL_MATCH_ADDR_Pos 3UL
#define SOCMEM_PORT_STRUCT_PATCH_STRUCT_CTL_MATCH_ADDR_Msk 0xFFFFFFF8UL


/* SOCMEM_PPU_SOCMEM.PWPR */
#define SOCMEM_PPU_SOCMEM_PWPR_PWR_POLICY_Pos   0UL
#define SOCMEM_PPU_SOCMEM_PWPR_PWR_POLICY_Msk   0xFUL
#define SOCMEM_PPU_SOCMEM_PWPR_PWR_DYN_EN_Pos   8UL
#define SOCMEM_PPU_SOCMEM_PWPR_PWR_DYN_EN_Msk   0x100UL
#define SOCMEM_PPU_SOCMEM_PWPR_LOCK_EN_Pos      12UL
#define SOCMEM_PPU_SOCMEM_PWPR_LOCK_EN_Msk      0x1000UL
#define SOCMEM_PPU_SOCMEM_PWPR_OP_POLICY_Pos    16UL
#define SOCMEM_PPU_SOCMEM_PWPR_OP_POLICY_Msk    0xF0000UL
#define SOCMEM_PPU_SOCMEM_PWPR_OP_DYN_EN_Pos    24UL
#define SOCMEM_PPU_SOCMEM_PWPR_OP_DYN_EN_Msk    0x1000000UL
/* SOCMEM_PPU_SOCMEM.PMER */
#define SOCMEM_PPU_SOCMEM_PMER_EMU_EN_Pos       0UL
#define SOCMEM_PPU_SOCMEM_PMER_EMU_EN_Msk       0x1UL
/* SOCMEM_PPU_SOCMEM.PWSR */
#define SOCMEM_PPU_SOCMEM_PWSR_PWR_STATUS_Pos   0UL
#define SOCMEM_PPU_SOCMEM_PWSR_PWR_STATUS_Msk   0xFUL
#define SOCMEM_PPU_SOCMEM_PWSR_PWR_DYN_STATUS_Pos 8UL
#define SOCMEM_PPU_SOCMEM_PWSR_PWR_DYN_STATUS_Msk 0x100UL
#define SOCMEM_PPU_SOCMEM_PWSR_LOCK_STATUS_Pos  12UL
#define SOCMEM_PPU_SOCMEM_PWSR_LOCK_STATUS_Msk  0x1000UL
#define SOCMEM_PPU_SOCMEM_PWSR_OP_STATUS_Pos    16UL
#define SOCMEM_PPU_SOCMEM_PWSR_OP_STATUS_Msk    0xF0000UL
#define SOCMEM_PPU_SOCMEM_PWSR_OP_DYN_STATUS_Pos 24UL
#define SOCMEM_PPU_SOCMEM_PWSR_OP_DYN_STATUS_Msk 0x1000000UL
/* SOCMEM_PPU_SOCMEM.DISR */
#define SOCMEM_PPU_SOCMEM_DISR_PWR_DEVACTIVE_STATUS_Pos 0UL
#define SOCMEM_PPU_SOCMEM_DISR_PWR_DEVACTIVE_STATUS_Msk 0x7FFUL
#define SOCMEM_PPU_SOCMEM_DISR_OP_DEVACTIVE_STATUS_Pos 24UL
#define SOCMEM_PPU_SOCMEM_DISR_OP_DEVACTIVE_STATUS_Msk 0xFF000000UL
/* SOCMEM_PPU_SOCMEM.MISR */
#define SOCMEM_PPU_SOCMEM_MISR_PCSMPACCEPT_STATUS_Pos 0UL
#define SOCMEM_PPU_SOCMEM_MISR_PCSMPACCEPT_STATUS_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_MISR_DEVACCEPT_STATUS_Pos 8UL
#define SOCMEM_PPU_SOCMEM_MISR_DEVACCEPT_STATUS_Msk 0xFF00UL
#define SOCMEM_PPU_SOCMEM_MISR_DEVDENY_STATUS_Pos 16UL
#define SOCMEM_PPU_SOCMEM_MISR_DEVDENY_STATUS_Msk 0xFF0000UL
/* SOCMEM_PPU_SOCMEM.STSR */
#define SOCMEM_PPU_SOCMEM_STSR_STORED_DEVDENY_Pos 0UL
#define SOCMEM_PPU_SOCMEM_STSR_STORED_DEVDENY_Msk 0xFFUL
/* SOCMEM_PPU_SOCMEM.UNLK */
#define SOCMEM_PPU_SOCMEM_UNLK_UNLOCK_Pos       0UL
#define SOCMEM_PPU_SOCMEM_UNLK_UNLOCK_Msk       0x1UL
/* SOCMEM_PPU_SOCMEM.PWCR */
#define SOCMEM_PPU_SOCMEM_PWCR_DEVREQEN_Pos     0UL
#define SOCMEM_PPU_SOCMEM_PWCR_DEVREQEN_Msk     0xFFUL
#define SOCMEM_PPU_SOCMEM_PWCR_PWR_DEVACTIVEEN_Pos 8UL
#define SOCMEM_PPU_SOCMEM_PWCR_PWR_DEVACTIVEEN_Msk 0x7FF00UL
#define SOCMEM_PPU_SOCMEM_PWCR_OP_DEVACTIVEEN_Pos 24UL
#define SOCMEM_PPU_SOCMEM_PWCR_OP_DEVACTIVEEN_Msk 0xFF000000UL
/* SOCMEM_PPU_SOCMEM.PTCR */
#define SOCMEM_PPU_SOCMEM_PTCR_WARM_RST_DEVREQEN_Pos 0UL
#define SOCMEM_PPU_SOCMEM_PTCR_WARM_RST_DEVREQEN_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_PTCR_DBG_RECOV_PORST_EN_Pos 1UL
#define SOCMEM_PPU_SOCMEM_PTCR_DBG_RECOV_PORST_EN_Msk 0x2UL
/* SOCMEM_PPU_SOCMEM.IMR */
#define SOCMEM_PPU_SOCMEM_IMR_STA_POLICY_TRN_IRQ_MASK_Pos 0UL
#define SOCMEM_PPU_SOCMEM_IMR_STA_POLICY_TRN_IRQ_MASK_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_IMR_STA_ACCEPT_IRQ_MASK_Pos 1UL
#define SOCMEM_PPU_SOCMEM_IMR_STA_ACCEPT_IRQ_MASK_Msk 0x2UL
#define SOCMEM_PPU_SOCMEM_IMR_STA_DENY_IRQ_MASK_Pos 2UL
#define SOCMEM_PPU_SOCMEM_IMR_STA_DENY_IRQ_MASK_Msk 0x4UL
#define SOCMEM_PPU_SOCMEM_IMR_EMU_ACCEPT_IRQ_MASK_Pos 3UL
#define SOCMEM_PPU_SOCMEM_IMR_EMU_ACCEPT_IRQ_MASK_Msk 0x8UL
#define SOCMEM_PPU_SOCMEM_IMR_EMU_DENY_IRQ_MASK_Pos 4UL
#define SOCMEM_PPU_SOCMEM_IMR_EMU_DENY_IRQ_MASK_Msk 0x10UL
#define SOCMEM_PPU_SOCMEM_IMR_LOCKED_IRQ_MASK_Pos 5UL
#define SOCMEM_PPU_SOCMEM_IMR_LOCKED_IRQ_MASK_Msk 0x20UL
/* SOCMEM_PPU_SOCMEM.AIMR */
#define SOCMEM_PPU_SOCMEM_AIMR_UNSPT_POLICY_IRQ_MASK_Pos 0UL
#define SOCMEM_PPU_SOCMEM_AIMR_UNSPT_POLICY_IRQ_MASK_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_AIMR_DYN_ACCEPT_IRQ_MASK_Pos 1UL
#define SOCMEM_PPU_SOCMEM_AIMR_DYN_ACCEPT_IRQ_MASK_Msk 0x2UL
#define SOCMEM_PPU_SOCMEM_AIMR_DYN_DENY_IRQ_MASK_Pos 2UL
#define SOCMEM_PPU_SOCMEM_AIMR_DYN_DENY_IRQ_MASK_Msk 0x4UL
#define SOCMEM_PPU_SOCMEM_AIMR_STA_POLICY_PWR_IRQ_MASK_Pos 3UL
#define SOCMEM_PPU_SOCMEM_AIMR_STA_POLICY_PWR_IRQ_MASK_Msk 0x8UL
#define SOCMEM_PPU_SOCMEM_AIMR_STA_POLICY_OP_IRQ_MASK_Pos 4UL
#define SOCMEM_PPU_SOCMEM_AIMR_STA_POLICY_OP_IRQ_MASK_Msk 0x10UL
/* SOCMEM_PPU_SOCMEM.ISR */
#define SOCMEM_PPU_SOCMEM_ISR_STA_POLICY_TRN_IRQ_Pos 0UL
#define SOCMEM_PPU_SOCMEM_ISR_STA_POLICY_TRN_IRQ_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_ISR_STA_ACCEPT_IRQ_Pos 1UL
#define SOCMEM_PPU_SOCMEM_ISR_STA_ACCEPT_IRQ_Msk 0x2UL
#define SOCMEM_PPU_SOCMEM_ISR_STA_DENY_IRQ_Pos  2UL
#define SOCMEM_PPU_SOCMEM_ISR_STA_DENY_IRQ_Msk  0x4UL
#define SOCMEM_PPU_SOCMEM_ISR_EMU_ACCEPT_IRQ_Pos 3UL
#define SOCMEM_PPU_SOCMEM_ISR_EMU_ACCEPT_IRQ_Msk 0x8UL
#define SOCMEM_PPU_SOCMEM_ISR_EMU_DENY_IRQ_Pos  4UL
#define SOCMEM_PPU_SOCMEM_ISR_EMU_DENY_IRQ_Msk  0x10UL
#define SOCMEM_PPU_SOCMEM_ISR_LOCKED_IRQ_Pos    5UL
#define SOCMEM_PPU_SOCMEM_ISR_LOCKED_IRQ_Msk    0x20UL
#define SOCMEM_PPU_SOCMEM_ISR_OTHER_IRQ_Pos     7UL
#define SOCMEM_PPU_SOCMEM_ISR_OTHER_IRQ_Msk     0x80UL
#define SOCMEM_PPU_SOCMEM_ISR_PWR_ACTIVE_EDGE_IRQ_Pos 8UL
#define SOCMEM_PPU_SOCMEM_ISR_PWR_ACTIVE_EDGE_IRQ_Msk 0x7FF00UL
#define SOCMEM_PPU_SOCMEM_ISR_OP_ACTIVE_EDGE_IRQ_Pos 24UL
#define SOCMEM_PPU_SOCMEM_ISR_OP_ACTIVE_EDGE_IRQ_Msk 0xFF000000UL
/* SOCMEM_PPU_SOCMEM.AISR */
#define SOCMEM_PPU_SOCMEM_AISR_UNSPT_POLICY_IRQ_Pos 0UL
#define SOCMEM_PPU_SOCMEM_AISR_UNSPT_POLICY_IRQ_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_AISR_DYN_ACCEPT_IRQ_Pos 1UL
#define SOCMEM_PPU_SOCMEM_AISR_DYN_ACCEPT_IRQ_Msk 0x2UL
#define SOCMEM_PPU_SOCMEM_AISR_DYN_DENY_IRQ_Pos 2UL
#define SOCMEM_PPU_SOCMEM_AISR_DYN_DENY_IRQ_Msk 0x4UL
#define SOCMEM_PPU_SOCMEM_AISR_STA_POLICY_PWR_IRQ_Pos 3UL
#define SOCMEM_PPU_SOCMEM_AISR_STA_POLICY_PWR_IRQ_Msk 0x8UL
#define SOCMEM_PPU_SOCMEM_AISR_STA_POLICY_OP_IRQ_Pos 4UL
#define SOCMEM_PPU_SOCMEM_AISR_STA_POLICY_OP_IRQ_Msk 0x10UL
/* SOCMEM_PPU_SOCMEM.IESR */
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE00_EDGE_Pos 0UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE00_EDGE_Msk 0x3UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE01_EDGE_Pos 2UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE01_EDGE_Msk 0xCUL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE02_EDGE_Pos 4UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE02_EDGE_Msk 0x30UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE03_EDGE_Pos 6UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE03_EDGE_Msk 0xC0UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE04_EDGE_Pos 8UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE04_EDGE_Msk 0x300UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE05_EDGE_Pos 10UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE05_EDGE_Msk 0xC00UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE06_EDGE_Pos 12UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE06_EDGE_Msk 0x3000UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE07_EDGE_Pos 14UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE07_EDGE_Msk 0xC000UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE08_EDGE_Pos 16UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE08_EDGE_Msk 0x30000UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE09_EDGE_Pos 18UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE09_EDGE_Msk 0xC0000UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE10_EDGE_Pos 20UL
#define SOCMEM_PPU_SOCMEM_IESR_DEVACTIVE10_EDGE_Msk 0x300000UL
/* SOCMEM_PPU_SOCMEM.OPSR */
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE16_EDGE_Pos 0UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE16_EDGE_Msk 0x3UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE17_EDGE_Pos 2UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE17_EDGE_Msk 0xCUL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE18_EDGE_Pos 4UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE18_EDGE_Msk 0x30UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE19_EDGE_Pos 6UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE19_EDGE_Msk 0xC0UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE20_EDGE_Pos 8UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE20_EDGE_Msk 0x300UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE21_EDGE_Pos 10UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE21_EDGE_Msk 0xC00UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE22_EDGE_Pos 12UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE22_EDGE_Msk 0x3000UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE23_EDGE_Pos 14UL
#define SOCMEM_PPU_SOCMEM_OPSR_DEVACTIVE23_EDGE_Msk 0xC000UL
/* SOCMEM_PPU_SOCMEM.FUNRR */
#define SOCMEM_PPU_SOCMEM_FUNRR_FUNC_RET_RAM_CFG_Pos 0UL
#define SOCMEM_PPU_SOCMEM_FUNRR_FUNC_RET_RAM_CFG_Msk 0xFFUL
/* SOCMEM_PPU_SOCMEM.FULRR */
#define SOCMEM_PPU_SOCMEM_FULRR_FULL_RET_RAM_CFG_Pos 0UL
#define SOCMEM_PPU_SOCMEM_FULRR_FULL_RET_RAM_CFG_Msk 0xFFUL
/* SOCMEM_PPU_SOCMEM.MEMRR */
#define SOCMEM_PPU_SOCMEM_MEMRR_MEM_RET_RAM_CFG_Pos 0UL
#define SOCMEM_PPU_SOCMEM_MEMRR_MEM_RET_RAM_CFG_Msk 0xFFUL
/* SOCMEM_PPU_SOCMEM.EDTR0 */
#define SOCMEM_PPU_SOCMEM_EDTR0_OFF_DEL_Pos     0UL
#define SOCMEM_PPU_SOCMEM_EDTR0_OFF_DEL_Msk     0xFFUL
#define SOCMEM_PPU_SOCMEM_EDTR0_MEM_RET_DEL_Pos 8UL
#define SOCMEM_PPU_SOCMEM_EDTR0_MEM_RET_DEL_Msk 0xFF00UL
#define SOCMEM_PPU_SOCMEM_EDTR0_LOGIC_RET_DEL_Pos 16UL
#define SOCMEM_PPU_SOCMEM_EDTR0_LOGIC_RET_DEL_Msk 0xFF0000UL
#define SOCMEM_PPU_SOCMEM_EDTR0_FULL_RET_DEL_Pos 24UL
#define SOCMEM_PPU_SOCMEM_EDTR0_FULL_RET_DEL_Msk 0xFF000000UL
/* SOCMEM_PPU_SOCMEM.EDTR1 */
#define SOCMEM_PPU_SOCMEM_EDTR1_MEM_OFF_DEL_Pos 0UL
#define SOCMEM_PPU_SOCMEM_EDTR1_MEM_OFF_DEL_Msk 0xFFUL
#define SOCMEM_PPU_SOCMEM_EDTR1_FUNC_RET_DEL_Pos 8UL
#define SOCMEM_PPU_SOCMEM_EDTR1_FUNC_RET_DEL_Msk 0xFF00UL
/* SOCMEM_PPU_SOCMEM.DCDR0 */
#define SOCMEM_PPU_SOCMEM_DCDR0_CLKEN_RST_DLY_Pos 0UL
#define SOCMEM_PPU_SOCMEM_DCDR0_CLKEN_RST_DLY_Msk 0xFFUL
#define SOCMEM_PPU_SOCMEM_DCDR0_ISO_CLKEN_DLY_Pos 8UL
#define SOCMEM_PPU_SOCMEM_DCDR0_ISO_CLKEN_DLY_Msk 0xFF00UL
#define SOCMEM_PPU_SOCMEM_DCDR0_RST_HWSTAT_DLY_Pos 16UL
#define SOCMEM_PPU_SOCMEM_DCDR0_RST_HWSTAT_DLY_Msk 0xFF0000UL
/* SOCMEM_PPU_SOCMEM.DCDR1 */
#define SOCMEM_PPU_SOCMEM_DCDR1_ISO_RST_DLY_Pos 0UL
#define SOCMEM_PPU_SOCMEM_DCDR1_ISO_RST_DLY_Msk 0xFFUL
#define SOCMEM_PPU_SOCMEM_DCDR1_CLKEN_ISO_DLY_Pos 8UL
#define SOCMEM_PPU_SOCMEM_DCDR1_CLKEN_ISO_DLY_Msk 0xFF00UL
/* SOCMEM_PPU_SOCMEM.IDR0 */
#define SOCMEM_PPU_SOCMEM_IDR0_DEVCHAN_Pos      0UL
#define SOCMEM_PPU_SOCMEM_IDR0_DEVCHAN_Msk      0xFUL
#define SOCMEM_PPU_SOCMEM_IDR0_NUM_OPMODE_Pos   4UL
#define SOCMEM_PPU_SOCMEM_IDR0_NUM_OPMODE_Msk   0xF0UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_OFF_SPT_Pos  8UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_OFF_SPT_Msk  0x100UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_OFF_EMU_SPT_Pos 9UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_OFF_EMU_SPT_Msk 0x200UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_MEM_RET_SPT_Pos 10UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_MEM_RET_SPT_Msk 0x400UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_MEM_RET_EMU_SPT_Pos 11UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_MEM_RET_EMU_SPT_Msk 0x800UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_LGC_RET_SPT_Pos 12UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_LGC_RET_SPT_Msk 0x1000UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_MEM_OFF_SPT_Pos 13UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_MEM_OFF_SPT_Msk 0x2000UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_FULL_RET_SPT_Pos 14UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_FULL_RET_SPT_Msk 0x4000UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_FUNC_RET_SPT_Pos 15UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_FUNC_RET_SPT_Msk 0x8000UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_ON_SPT_Pos   16UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_ON_SPT_Msk   0x10000UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_WRM_RST_SPT_Pos 17UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_WRM_RST_SPT_Msk 0x20000UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_DBG_RECOV_SPT_Pos 18UL
#define SOCMEM_PPU_SOCMEM_IDR0_STA_DBG_RECOV_SPT_Msk 0x40000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_OFF_SPT_Pos  20UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_OFF_SPT_Msk  0x100000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_OFF_EMU_SPT_Pos 21UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_OFF_EMU_SPT_Msk 0x200000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_MEM_RET_SPT_Pos 22UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_MEM_RET_SPT_Msk 0x400000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_MEM_RET_EMU_SPT_Pos 23UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_MEM_RET_EMU_SPT_Msk 0x800000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_LGC_RET_SPT_Pos 24UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_LGC_RET_SPT_Msk 0x1000000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_MEM_OFF_SPT_Pos 25UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_MEM_OFF_SPT_Msk 0x2000000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_FULL_RET_SPT_Pos 26UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_FULL_RET_SPT_Msk 0x4000000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_FUNC_RET_SPT_Pos 27UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_FUNC_RET_SPT_Msk 0x8000000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_ON_SPT_Pos   28UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_ON_SPT_Msk   0x10000000UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_WRM_RST_SPT_Pos 29UL
#define SOCMEM_PPU_SOCMEM_IDR0_DYN_WRM_RST_SPT_Msk 0x20000000UL
/* SOCMEM_PPU_SOCMEM.IDR1 */
#define SOCMEM_PPU_SOCMEM_IDR1_PWR_MODE_ENTRY_DEL_SPT_Pos 0UL
#define SOCMEM_PPU_SOCMEM_IDR1_PWR_MODE_ENTRY_DEL_SPT_Msk 0x1UL
#define SOCMEM_PPU_SOCMEM_IDR1_SW_DEV_DEL_SPT_Pos 1UL
#define SOCMEM_PPU_SOCMEM_IDR1_SW_DEV_DEL_SPT_Msk 0x2UL
#define SOCMEM_PPU_SOCMEM_IDR1_LOCK_SPT_Pos     2UL
#define SOCMEM_PPU_SOCMEM_IDR1_LOCK_SPT_Msk     0x4UL
#define SOCMEM_PPU_SOCMEM_IDR1_MEM_RET_RAM_REG_Pos 4UL
#define SOCMEM_PPU_SOCMEM_IDR1_MEM_RET_RAM_REG_Msk 0x10UL
#define SOCMEM_PPU_SOCMEM_IDR1_FULL_RET_RAM_REG_Pos 5UL
#define SOCMEM_PPU_SOCMEM_IDR1_FULL_RET_RAM_REG_Msk 0x20UL
#define SOCMEM_PPU_SOCMEM_IDR1_FUNC_RET_RAM_REG_Pos 6UL
#define SOCMEM_PPU_SOCMEM_IDR1_FUNC_RET_RAM_REG_Msk 0x40UL
#define SOCMEM_PPU_SOCMEM_IDR1_STA_POLICY_PWR_IRQ_SPT_Pos 8UL
#define SOCMEM_PPU_SOCMEM_IDR1_STA_POLICY_PWR_IRQ_SPT_Msk 0x100UL
#define SOCMEM_PPU_SOCMEM_IDR1_STA_POLICY_OP_IRQ_SPT_Pos 9UL
#define SOCMEM_PPU_SOCMEM_IDR1_STA_POLICY_OP_IRQ_SPT_Msk 0x200UL
#define SOCMEM_PPU_SOCMEM_IDR1_OP_ACTIVE_Pos    10UL
#define SOCMEM_PPU_SOCMEM_IDR1_OP_ACTIVE_Msk    0x400UL
#define SOCMEM_PPU_SOCMEM_IDR1_OFF_MEM_RET_TRANS_Pos 12UL
#define SOCMEM_PPU_SOCMEM_IDR1_OFF_MEM_RET_TRANS_Msk 0x1000UL
/* SOCMEM_PPU_SOCMEM.IIDR */
#define SOCMEM_PPU_SOCMEM_IIDR_IMPLEMENTER_Pos  0UL
#define SOCMEM_PPU_SOCMEM_IIDR_IMPLEMENTER_Msk  0xFFFUL
#define SOCMEM_PPU_SOCMEM_IIDR_REVISION_Pos     12UL
#define SOCMEM_PPU_SOCMEM_IIDR_REVISION_Msk     0xF000UL
#define SOCMEM_PPU_SOCMEM_IIDR_VARIANT_Pos      16UL
#define SOCMEM_PPU_SOCMEM_IIDR_VARIANT_Msk      0xF0000UL
#define SOCMEM_PPU_SOCMEM_IIDR_PRODUCT_ID_Pos   20UL
#define SOCMEM_PPU_SOCMEM_IIDR_PRODUCT_ID_Msk   0xFFF00000UL
/* SOCMEM_PPU_SOCMEM.AIDR */
#define SOCMEM_PPU_SOCMEM_AIDR_ARCH_REV_MINOR_Pos 0UL
#define SOCMEM_PPU_SOCMEM_AIDR_ARCH_REV_MINOR_Msk 0xFUL
#define SOCMEM_PPU_SOCMEM_AIDR_ARCH_REV_MAJOR_Pos 4UL
#define SOCMEM_PPU_SOCMEM_AIDR_ARCH_REV_MAJOR_Msk 0xF0UL
/* SOCMEM_PPU_SOCMEM.PID4 */
#define SOCMEM_PPU_SOCMEM_PID4_IMPLEMENTER_11_8_Pos 0UL
#define SOCMEM_PPU_SOCMEM_PID4_IMPLEMENTER_11_8_Msk 0xFUL
/* SOCMEM_PPU_SOCMEM.PID0 */
#define SOCMEM_PPU_SOCMEM_PID0_PRODUCT_ID_7_0_Pos 0UL
#define SOCMEM_PPU_SOCMEM_PID0_PRODUCT_ID_7_0_Msk 0xFFUL
/* SOCMEM_PPU_SOCMEM.PID1 */
#define SOCMEM_PPU_SOCMEM_PID1_PRODUCT_ID_11_8_Pos 0UL
#define SOCMEM_PPU_SOCMEM_PID1_PRODUCT_ID_11_8_Msk 0xFUL
#define SOCMEM_PPU_SOCMEM_PID1_IMPLEMENTER_3_0_Pos 4UL
#define SOCMEM_PPU_SOCMEM_PID1_IMPLEMENTER_3_0_Msk 0xF0UL
/* SOCMEM_PPU_SOCMEM.PID2 */
#define SOCMEM_PPU_SOCMEM_PID2_IMPLEMENTER_6_4_Pos 0UL
#define SOCMEM_PPU_SOCMEM_PID2_IMPLEMENTER_6_4_Msk 0x7UL
#define SOCMEM_PPU_SOCMEM_PID2_CONST_HIGH_Pos   3UL
#define SOCMEM_PPU_SOCMEM_PID2_CONST_HIGH_Msk   0x8UL
#define SOCMEM_PPU_SOCMEM_PID2_REV_CONST_Pos    4UL
#define SOCMEM_PPU_SOCMEM_PID2_REV_CONST_Msk    0xF0UL
/* SOCMEM_PPU_SOCMEM.PID3 */
#define SOCMEM_PPU_SOCMEM_PID3_PID3_REV_CONST_Pos 0UL
#define SOCMEM_PPU_SOCMEM_PID3_PID3_REV_CONST_Msk 0xFUL
#define SOCMEM_PPU_SOCMEM_PID3_PID3_REVISION_Pos 4UL
#define SOCMEM_PPU_SOCMEM_PID3_PID3_REVISION_Msk 0xF0UL
/* SOCMEM_PPU_SOCMEM.ID0 */
#define SOCMEM_PPU_SOCMEM_ID0_ID0_Pos           0UL
#define SOCMEM_PPU_SOCMEM_ID0_ID0_Msk           0xFFUL
/* SOCMEM_PPU_SOCMEM.ID1 */
#define SOCMEM_PPU_SOCMEM_ID1_ID1_Pos           0UL
#define SOCMEM_PPU_SOCMEM_ID1_ID1_Msk           0xFFUL
/* SOCMEM_PPU_SOCMEM.ID2 */
#define SOCMEM_PPU_SOCMEM_ID2_ID2_Pos           0UL
#define SOCMEM_PPU_SOCMEM_ID2_ID2_Msk           0xFFUL
/* SOCMEM_PPU_SOCMEM.ID3 */
#define SOCMEM_PPU_SOCMEM_ID3_ID3_Pos           0UL
#define SOCMEM_PPU_SOCMEM_ID3_ID3_Msk           0xFFUL


/* SOCMEM_SOCMEM_PD.CTL */
#define SOCMEM_SOCMEM_PD_CTL_BLEED_EN_Pos       0UL
#define SOCMEM_SOCMEM_PD_CTL_BLEED_EN_Msk       0x1UL
/* SOCMEM_SOCMEM_PD.PWR_UP_DELAY */
#define SOCMEM_SOCMEM_PD_PWR_UP_DELAY_COUNT_LOAD_Pos 0UL
#define SOCMEM_SOCMEM_PD_PWR_UP_DELAY_COUNT_LOAD_Msk 0xFFUL
#define SOCMEM_SOCMEM_PD_PWR_UP_DELAY_MEM_COUNT_LOAD_Pos 8UL
#define SOCMEM_SOCMEM_PD_PWR_UP_DELAY_MEM_COUNT_LOAD_Msk 0xFF00UL


/* SOCMEM.CTL */
#define SOCMEM_CTL_SRAM_WS_Pos                  0UL
#define SOCMEM_CTL_SRAM_WS_Msk                  0x3UL
#define SOCMEM_CTL_SROM_WS_Pos                  4UL
#define SOCMEM_CTL_SROM_WS_Msk                  0x30UL
#define SOCMEM_CTL_AUTO_GK_Pos                  16UL
#define SOCMEM_CTL_AUTO_GK_Msk                  0x10000UL
/* SOCMEM.STATUS */
#define SOCMEM_STATUS_WB_EMPTY_Pos              0UL
#define SOCMEM_STATUS_WB_EMPTY_Msk              0xFFFFUL
#define SOCMEM_STATUS_PORT_MPC_INIT_DONE_Pos    16UL
#define SOCMEM_STATUS_PORT_MPC_INIT_DONE_Msk    0x10000UL
/* SOCMEM.GK_CTL */
#define SOCMEM_GK_CTL_OPEN_Pos                  0UL
#define SOCMEM_GK_CTL_OPEN_Msk                  0xFFFFUL
/* SOCMEM.GK_STATUS */
#define SOCMEM_GK_STATUS_OPEN_Pos               0UL
#define SOCMEM_GK_STATUS_OPEN_Msk               0xFFFFUL
/* SOCMEM.ARB_DYN_CTL */
#define SOCMEM_ARB_DYN_CTL_CREDIT_Pos           0UL
#define SOCMEM_ARB_DYN_CTL_CREDIT_Msk           0x7FUL
#define SOCMEM_ARB_DYN_CTL_LATENCY_Pos          16UL
#define SOCMEM_ARB_DYN_CTL_LATENCY_Msk          0x10000UL
/* SOCMEM.MPC_READ_PORT_CTL */
#define SOCMEM_MPC_READ_PORT_CTL_INDEX_Pos      0UL
#define SOCMEM_MPC_READ_PORT_CTL_INDEX_Msk      0xFUL
/* SOCMEM.ECC_CTL */
#define SOCMEM_ECC_CTL_EN_Pos                   0UL
#define SOCMEM_ECC_CTL_EN_Msk                   0x1UL
#define SOCMEM_ECC_CTL_AUTO_CORRECT_Pos         1UL
#define SOCMEM_ECC_CTL_AUTO_CORRECT_Msk         0x2UL
#define SOCMEM_ECC_CTL_INJ_EN_Pos               2UL
#define SOCMEM_ECC_CTL_INJ_EN_Msk               0x4UL
#define SOCMEM_ECC_CTL_CHECK_EN_Pos             3UL
#define SOCMEM_ECC_CTL_CHECK_EN_Msk             0x8UL
#define SOCMEM_ECC_CTL_PARITY_Pos               16UL
#define SOCMEM_ECC_CTL_PARITY_Msk               0xFF0000UL
/* SOCMEM.ECC_MATCH */
#define SOCMEM_ECC_MATCH_WORD_ADDR_Pos          3UL
#define SOCMEM_ECC_MATCH_WORD_ADDR_Msk          0xFFFFF8UL
/* SOCMEM.WOUNDING */
#define SOCMEM_WOUNDING_WOUND_Pos               0UL
#define SOCMEM_WOUNDING_WOUND_Msk               0x7UL
/* SOCMEM.PWR_PARTITION_CTL */
#define SOCMEM_PWR_PARTITION_CTL_ACT_OFF_Pos    0UL
#define SOCMEM_PWR_PARTITION_CTL_ACT_OFF_Msk    0x3UL
#define SOCMEM_PWR_PARTITION_CTL_RET_OFF_Pos    8UL
#define SOCMEM_PWR_PARTITION_CTL_RET_OFF_Msk    0x300UL
/* SOCMEM.PWR_PARTITION_CTL_LOCK */
#define SOCMEM_PWR_PARTITION_CTL_LOCK_PWR_PARTITION_CTL_LOCK_Pos 0UL
#define SOCMEM_PWR_PARTITION_CTL_LOCK_PWR_PARTITION_CTL_LOCK_Msk 0x3UL
/* SOCMEM.PWR_DELAY_CTL */
#define SOCMEM_PWR_DELAY_CTL_UP_Pos             0UL
#define SOCMEM_PWR_DELAY_CTL_UP_Msk             0x3FFUL
#define SOCMEM_PWR_DELAY_CTL_SEQ0_DELAY_Pos     16UL
#define SOCMEM_PWR_DELAY_CTL_SEQ0_DELAY_Msk     0xFF0000UL
#define SOCMEM_PWR_DELAY_CTL_SEQ1_DELAY_Pos     24UL
#define SOCMEM_PWR_DELAY_CTL_SEQ1_DELAY_Msk     0xFF000000UL
/* SOCMEM.PWR_STATUS */
#define SOCMEM_PWR_STATUS_PWR_DONE_Pos          0UL
#define SOCMEM_PWR_STATUS_PWR_DONE_Msk          0x1UL


#endif /* _CYIP_SOCMEM_H_ */


/* [] END OF FILE */

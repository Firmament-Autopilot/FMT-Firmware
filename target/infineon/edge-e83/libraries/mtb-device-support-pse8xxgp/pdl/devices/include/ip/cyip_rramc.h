/***************************************************************************//**
* RRAMC IP definitions
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

#ifndef _CYIP_RRAMC_H_
#define _CYIP_RRAMC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    RRAMC
*******************************************************************************/

#define RRAMC_RRAM_EXTRA_AREA_SECTION_SIZE      0x00010000UL
#define RRAMC_RRAMC_SECTION_SIZE                0x00001000UL
#define RRAMC_MPC_SECTION_SIZE                  0x00001000UL
#define RRAMC_RRAM_SFR_SECTION_SIZE             0x00001000UL
#define RRAMC_SECTION_SIZE                      0x00020000UL

/**
  * \brief RRAM OTP map and Extra region (RRAMC_RRAM_EXTRA_AREA)
  */
typedef struct {
   __IM uint32_t RESERVED[4096];
  __IOM uint32_t GENERAL_OTP[1408];             /*!< 0x00004000 GENERAL_OTP subregion (5.5KB) */
   __IM uint32_t RESERVED1[10880];
} RRAMC_RRAM_EXTRA_AREA_Type;                   /*!< Size = 65536 (0x10000) */

/**
  * \brief RRAMC controller registers (RRAMC_RRAMC)
  */
typedef struct {
  __IOM uint32_t AHB_HRESP;                     /*!< 0x00000000 RRAMC AHB HRESP */
   __IM uint32_t RESERVED[7];
  __IOM uint32_t PC_MASK;                       /*!< 0x00000020 PC acquisition and releasing */
   __IM uint32_t RRAM_PROTECTED_X;              /*!< 0x00000024 Size of PROTECTED_NVM subregion (8KB * X) */
   __IM uint32_t RRAM_SFLASH_Y;                 /*!< 0x00000028 Size of SFLASH_NVM subregion (8KB * Y) */
   __IM uint32_t RRAM_WORK_Z;                   /*!< 0x0000002C Size of WORK_NVM subregion (8KB * Z) */
   __IM uint32_t RRAM_MAIN_N;                   /*!< 0x00000030 Size of MAIN_NVM subregion (8KB * N) */
   __IM uint32_t RESERVED1[51];
  __IOM uint32_t RRAM_CTL;                      /*!< 0x00000100 RRAM macro OSC control */
  __IOM uint32_t PROTECTED_LOCKABLE_LOCK;       /*!< 0x00000104 PROTECTED_NVM lockable configuarion */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t UDS_CTL;                       /*!< 0x00000110 UDS control */
  __IOM uint32_t RECLAIMED_MAIN_NVM_SIZE;       /*!< 0x00000114 Reclaimed size (KB) from upgradeable */
  __IOM uint32_t TB_GATING_CTL;                 /*!< 0x00000118 Turn-off Tagbit post-read gating control check */
   __IM uint32_t RESERVED3[953];
} RRAMC_RRAMC_Type;                             /*!< Size = 4096 (0x1000) */

/**
  * \brief MPC Memory Protection Controller registers (RRAMC_MPC)
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
} RRAMC_MPC_Type;                               /*!< Size = 4096 (0x1000) */

/**
  * \brief RRAM macro SFR registers (RRAMC_RRAM_SFR)
  */
typedef struct {
   __IM uint32_t NVM_STATUS;                    /*!< 0x00000000 status register */
  __IOM uint32_t NVM_PROG;                      /*!< 0x00000004 programming control register */
  __IOM uint32_t NVM_ADDR;                      /*!< 0x00000008 address register */
  __IOM uint32_t NVM_CONF1;                     /*!< 0x0000000C configuration register */
  __IOM uint32_t NVM_HARDEN1;                   /*!< 0x00000010 hardening configuration register */
  __IOM uint32_t NVM_HARDADDR;                  /*!< 0x00000014 hardening address register */
  __IOM uint32_t NVM_HRESP;                     /*!< 0x00000018 bus response register */
   __IM uint32_t NVM_ECCLOG;                    /*!< 0x0000001C ECC failure logging register */
  __IOM uint32_t NVM_ECCLOGIR;                  /*!< 0x00000020 ECC failure logging interrupt register */
  __IOM uint32_t NVM_VMODE;                     /*!< 0x00000024 voltage mode register */
   __IM uint32_t RESERVED[1014];
} RRAMC_RRAM_SFR_Type;                          /*!< Size = 4096 (0x1000) */

/**
  * \brief RRAM controller registers (RRAMC)
  */
typedef struct {
        RRAMC_RRAM_EXTRA_AREA_Type RRAM_EXTRA_AREA; /*!< 0x00000000 RRAM OTP map and Extra region */
        RRAMC_RRAMC_Type RRAMC[1];              /*!< 0x00010000 RRAMC controller registers */
        RRAMC_MPC_Type MPC[2];                  /*!< 0x00011000 MPC Memory Protection Controller registers */
        RRAMC_RRAM_SFR_Type RRAM_SFR;           /*!< 0x00013000 RRAM macro SFR registers */
} RRAMC_Type;                                   /*!< Size = 81920 (0x14000) */


/* RRAMC_RRAM_EXTRA_AREA.GENERAL_OTP */
#define RRAMC_RRAM_EXTRA_AREA_GENERAL_OTP_GENERAL_OTP_VALUE_Pos 0UL
#define RRAMC_RRAM_EXTRA_AREA_GENERAL_OTP_GENERAL_OTP_VALUE_Msk 0xFFFFFFFFUL


/* RRAMC_RRAMC.AHB_HRESP */
#define RRAMC_RRAMC_AHB_HRESP_HRESP_Pos         0UL
#define RRAMC_RRAMC_AHB_HRESP_HRESP_Msk         0xFUL
#define RRAMC_RRAMC_AHB_HRESP_RESET_HRESP_Pos   31UL
#define RRAMC_RRAMC_AHB_HRESP_RESET_HRESP_Msk   0x80000000UL
/* RRAMC_RRAMC.PC_MASK */
#define RRAMC_RRAMC_PC_MASK_PC_Pos              0UL
#define RRAMC_RRAMC_PC_MASK_PC_Msk              0xFUL
#define RRAMC_RRAMC_PC_MASK_PC_LOCK_Pos         28UL
#define RRAMC_RRAMC_PC_MASK_PC_LOCK_Msk         0xF0000000UL
/* RRAMC_RRAMC.RRAM_PROTECTED_X */
#define RRAMC_RRAMC_RRAM_PROTECTED_X_PROTECTED_X_Pos 0UL
#define RRAMC_RRAMC_RRAM_PROTECTED_X_PROTECTED_X_Msk 0xFFFFFFFFUL
/* RRAMC_RRAMC.RRAM_SFLASH_Y */
#define RRAMC_RRAMC_RRAM_SFLASH_Y_SFLASH_Y_Pos  0UL
#define RRAMC_RRAMC_RRAM_SFLASH_Y_SFLASH_Y_Msk  0xFFFFFFFFUL
/* RRAMC_RRAMC.RRAM_WORK_Z */
#define RRAMC_RRAMC_RRAM_WORK_Z_WORK_Z_Pos      0UL
#define RRAMC_RRAMC_RRAM_WORK_Z_WORK_Z_Msk      0xFFFFFFFFUL
/* RRAMC_RRAMC.RRAM_MAIN_N */
#define RRAMC_RRAMC_RRAM_MAIN_N_MAIN_N_Pos      0UL
#define RRAMC_RRAMC_RRAM_MAIN_N_MAIN_N_Msk      0xFFFFFFFFUL
/* RRAMC_RRAMC.RRAM_CTL */
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK160_EN_Pos 0UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK160_EN_Msk 0x1UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK80_EN_Pos 1UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK80_EN_Msk 0x2UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK40_EN_Pos 2UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK40_EN_Msk 0x4UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK10_EN_Pos 3UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXCLK10_EN_Msk 0x8UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXKEEP_RUN_Pos 4UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_EXKEEP_RUN_Msk 0x10UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_OUT_ON_Pos     5UL
#define RRAMC_RRAMC_RRAM_CTL_OSC_OUT_ON_Msk     0x20UL
/* RRAMC_RRAMC.PROTECTED_LOCKABLE_LOCK */
#define RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_PARTITION_SIZE_0_Pos 0UL
#define RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_PARTITION_SIZE_0_Msk 0xFFUL
#define RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_PARTITION_SIZE_1_Pos 8UL
#define RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_PARTITION_SIZE_1_Msk 0xFF00UL
#define RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_LOCK_Pos 28UL
#define RRAMC_RRAMC_PROTECTED_LOCKABLE_LOCK_LOCK_Msk 0xF0000000UL
/* RRAMC_RRAMC.UDS_CTL */
#define RRAMC_RRAMC_UDS_CTL_CONFIG_Pos          0UL
#define RRAMC_RRAMC_UDS_CTL_CONFIG_Msk          0x1UL
#define RRAMC_RRAMC_UDS_CTL_LOCK_Pos            28UL
#define RRAMC_RRAMC_UDS_CTL_LOCK_Msk            0xF0000000UL
/* RRAMC_RRAMC.RECLAIMED_MAIN_NVM_SIZE */
#define RRAMC_RRAMC_RECLAIMED_MAIN_NVM_SIZE_RECLAIMED_SIZE_0_Pos 0UL
#define RRAMC_RRAMC_RECLAIMED_MAIN_NVM_SIZE_RECLAIMED_SIZE_0_Msk 0xFFUL
#define RRAMC_RRAMC_RECLAIMED_MAIN_NVM_SIZE_RECLAIMED_SIZE_1_Pos 8UL
#define RRAMC_RRAMC_RECLAIMED_MAIN_NVM_SIZE_RECLAIMED_SIZE_1_Msk 0xFF00UL
/* RRAMC_RRAMC.TB_GATING_CTL */
#define RRAMC_RRAMC_TB_GATING_CTL_TB_GATING_OFF_Pos 28UL
#define RRAMC_RRAMC_TB_GATING_CTL_TB_GATING_OFF_Msk 0xF0000000UL


/* RRAMC_MPC.CFG */
#define RRAMC_MPC_CFG_RESPONSE_Pos              4UL
#define RRAMC_MPC_CFG_RESPONSE_Msk              0x10UL
/* RRAMC_MPC.CTRL */
#define RRAMC_MPC_CTRL_AUTO_INC_Pos             8UL
#define RRAMC_MPC_CTRL_AUTO_INC_Msk             0x100UL
#define RRAMC_MPC_CTRL_LOCK_Pos                 31UL
#define RRAMC_MPC_CTRL_LOCK_Msk                 0x80000000UL
/* RRAMC_MPC.BLK_MAX */
#define RRAMC_MPC_BLK_MAX_VALUE_Pos             0UL
#define RRAMC_MPC_BLK_MAX_VALUE_Msk             0xFFFFFFFFUL
/* RRAMC_MPC.BLK_CFG */
#define RRAMC_MPC_BLK_CFG_BLOCK_SIZE_Pos        0UL
#define RRAMC_MPC_BLK_CFG_BLOCK_SIZE_Msk        0xFUL
#define RRAMC_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos  31UL
#define RRAMC_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk  0x80000000UL
/* RRAMC_MPC.BLK_IDX */
#define RRAMC_MPC_BLK_IDX_VALUE_Pos             0UL
#define RRAMC_MPC_BLK_IDX_VALUE_Msk             0xFFFFFFFFUL
/* RRAMC_MPC.BLK_LUT */
#define RRAMC_MPC_BLK_LUT_ATTR_NS0_Pos          0UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS0_Msk          0x1UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS1_Pos          1UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS1_Msk          0x2UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS2_Pos          2UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS2_Msk          0x4UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS3_Pos          3UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS3_Msk          0x8UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS4_Pos          4UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS4_Msk          0x10UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS5_Pos          5UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS5_Msk          0x20UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS6_Pos          6UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS6_Msk          0x40UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS7_Pos          7UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS7_Msk          0x80UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS8_Pos          8UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS8_Msk          0x100UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS9_Pos          9UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS9_Msk          0x200UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS10_Pos         10UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS10_Msk         0x400UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS11_Pos         11UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS11_Msk         0x800UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS12_Pos         12UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS12_Msk         0x1000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS13_Pos         13UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS13_Msk         0x2000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS14_Pos         14UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS14_Msk         0x4000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS15_Pos         15UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS15_Msk         0x8000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS16_Pos         16UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS16_Msk         0x10000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS17_Pos         17UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS17_Msk         0x20000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS18_Pos         18UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS18_Msk         0x40000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS19_Pos         19UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS19_Msk         0x80000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS20_Pos         20UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS20_Msk         0x100000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS21_Pos         21UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS21_Msk         0x200000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS22_Pos         22UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS22_Msk         0x400000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS23_Pos         23UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS23_Msk         0x800000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS24_Pos         24UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS24_Msk         0x1000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS25_Pos         25UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS25_Msk         0x2000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS26_Pos         26UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS26_Msk         0x4000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS27_Pos         27UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS27_Msk         0x8000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS28_Pos         28UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS28_Msk         0x10000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS29_Pos         29UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS29_Msk         0x20000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS30_Pos         30UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS30_Msk         0x40000000UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS31_Pos         31UL
#define RRAMC_MPC_BLK_LUT_ATTR_NS31_Msk         0x80000000UL
/* RRAMC_MPC.ROT_CTRL */
#define RRAMC_MPC_ROT_CTRL_AUTO_INC_Pos         8UL
#define RRAMC_MPC_ROT_CTRL_AUTO_INC_Msk         0x100UL
#define RRAMC_MPC_ROT_CTRL_LOCK_Pos             31UL
#define RRAMC_MPC_ROT_CTRL_LOCK_Msk             0x80000000UL
/* RRAMC_MPC.ROT_BLK_MAX */
#define RRAMC_MPC_ROT_BLK_MAX_VALUE_Pos         0UL
#define RRAMC_MPC_ROT_BLK_MAX_VALUE_Msk         0xFFFFFFFFUL
/* RRAMC_MPC.ROT_BLK_CFG */
#define RRAMC_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos    0UL
#define RRAMC_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk    0xFUL
#define RRAMC_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define RRAMC_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* RRAMC_MPC.ROT_BLK_IDX */
#define RRAMC_MPC_ROT_BLK_IDX_VALUE_Pos         0UL
#define RRAMC_MPC_ROT_BLK_IDX_VALUE_Msk         0xFFFFFFFFUL
/* RRAMC_MPC.ROT_BLK_PC */
#define RRAMC_MPC_ROT_BLK_PC_PC_Pos             0UL
#define RRAMC_MPC_ROT_BLK_PC_PC_Msk             0xFUL
/* RRAMC_MPC.ROT_BLK_LUT */
#define RRAMC_MPC_ROT_BLK_LUT_ATTR0_Pos         0UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR0_Msk         0x7UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR1_Pos         4UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR1_Msk         0x70UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR2_Pos         8UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR2_Msk         0x700UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR3_Pos         12UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR3_Msk         0x7000UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR4_Pos         16UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR4_Msk         0x70000UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR5_Pos         20UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR5_Msk         0x700000UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR6_Pos         24UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR6_Msk         0x7000000UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR7_Pos         28UL
#define RRAMC_MPC_ROT_BLK_LUT_ATTR7_Msk         0x70000000UL


/* RRAMC_RRAM_SFR.NVM_STATUS */
#define RRAMC_RRAM_SFR_NVM_STATUS_BUSY_Pos      0UL
#define RRAMC_RRAM_SFR_NVM_STATUS_BUSY_Msk      0x1UL
#define RRAMC_RRAM_SFR_NVM_STATUS_SLEEP_Pos     1UL
#define RRAMC_RRAM_SFR_NVM_STATUS_SLEEP_Msk     0x2UL
#define RRAMC_RRAM_SFR_NVM_STATUS_VERR_Pos      2UL
#define RRAMC_RRAM_SFR_NVM_STATUS_VERR_Msk      0x1CUL
#define RRAMC_RRAM_SFR_NVM_STATUS_WRPERR_Pos    5UL
#define RRAMC_RRAM_SFR_NVM_STATUS_WRPERR_Msk    0x20UL
#define RRAMC_RRAM_SFR_NVM_STATUS_RWWERR_Pos    6UL
#define RRAMC_RRAM_SFR_NVM_STATUS_RWWERR_Msk    0x40UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC1READ_Pos  7UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC1READ_Msk  0x80UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC2READ_Pos  8UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC2READ_Msk  0x100UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC3READ_Pos  9UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC3READ_Msk  0x200UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC4READ_Pos  10UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC4READ_Msk  0x400UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECCAREAD_Pos  11UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECCAREAD_Msk  0x800UL
#define RRAMC_RRAM_SFR_NVM_STATUS_WBFILL_Pos    12UL
#define RRAMC_RRAM_SFR_NVM_STATUS_WBFILL_Msk    0xF000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC1MRD_Pos   16UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC1MRD_Msk   0x10000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC2MRD_Pos   17UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC2MRD_Msk   0x20000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC3MRD_Pos   18UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC3MRD_Msk   0x40000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC4MRD_Pos   19UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECC4MRD_Msk   0x80000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECCAMRD_Pos   20UL
#define RRAMC_RRAM_SFR_NVM_STATUS_ECCAMRD_Msk   0x100000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_CONFSTATE_Pos 24UL
#define RRAMC_RRAM_SFR_NVM_STATUS_CONFSTATE_Msk 0x7000000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_OLRFLAG_Pos   27UL
#define RRAMC_RRAM_SFR_NVM_STATUS_OLRFLAG_Msk   0x8000000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_HARDFLAG_Pos  28UL
#define RRAMC_RRAM_SFR_NVM_STATUS_HARDFLAG_Msk  0x10000000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_REREA_Pos     29UL
#define RRAMC_RRAM_SFR_NVM_STATUS_REREA_Msk     0x60000000UL
#define RRAMC_RRAM_SFR_NVM_STATUS_WSUSP_Pos     31UL
#define RRAMC_RRAM_SFR_NVM_STATUS_WSUSP_Msk     0x80000000UL
/* RRAMC_RRAM_SFR.NVM_PROG */
#define RRAMC_RRAM_SFR_NVM_PROG_ACTION_Pos      0UL
#define RRAMC_RRAM_SFR_NVM_PROG_ACTION_Msk      0xFUL
#define RRAMC_RRAM_SFR_NVM_PROG_SELRCS_Pos      8UL
#define RRAMC_RRAM_SFR_NVM_PROG_SELRCS_Msk      0x100UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTTRAP_Pos     9UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTTRAP_Msk     0x200UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTIR_Pos       10UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTIR_Msk       0x400UL
#define RRAMC_RRAM_SFR_NVM_PROG_RBINVAL_Pos     11UL
#define RRAMC_RRAM_SFR_NVM_PROG_RBINVAL_Msk     0x800UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTVERR_Pos     12UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTVERR_Msk     0x1000UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTECC_Pos      13UL
#define RRAMC_RRAM_SFR_NVM_PROG_RSTECC_Msk      0x2000UL
#define RRAMC_RRAM_SFR_NVM_PROG_STARTOP_Pos     14UL
#define RRAMC_RRAM_SFR_NVM_PROG_STARTOP_Msk     0xC000UL
#define RRAMC_RRAM_SFR_NVM_PROG_OLREN_Pos       16UL
#define RRAMC_RRAM_SFR_NVM_PROG_OLREN_Msk       0x70000UL
#define RRAMC_RRAM_SFR_NVM_PROG_SELAL_Pos       20UL
#define RRAMC_RRAM_SFR_NVM_PROG_SELAL_Msk       0x300000UL
#define RRAMC_RRAM_SFR_NVM_PROG_RDWB_Pos        24UL
#define RRAMC_RRAM_SFR_NVM_PROG_RDWB_Msk        0x1000000UL
#define RRAMC_RRAM_SFR_NVM_PROG_TEMP_Pos        28UL
#define RRAMC_RRAM_SFR_NVM_PROG_TEMP_Msk        0xF0000000UL
/* RRAMC_RRAM_SFR.NVM_ADDR */
#define RRAMC_RRAM_SFR_NVM_ADDR_ADDRB_Pos       0UL
#define RRAMC_RRAM_SFR_NVM_ADDR_ADDRB_Msk       0x1FUL
#define RRAMC_RRAM_SFR_NVM_ADDR_ADDRWL_Pos      5UL
#define RRAMC_RRAM_SFR_NVM_ADDR_ADDRWL_Msk      0xE0UL
#define RRAMC_RRAM_SFR_NVM_ADDR_ADDRS_Pos       8UL
#define RRAMC_RRAM_SFR_NVM_ADDR_ADDRS_Msk       0x3FF00UL
/* RRAMC_RRAM_SFR.NVM_CONF1 */
#define RRAMC_RRAM_SFR_NVM_CONF1_HRLEV_Pos      0UL
#define RRAMC_RRAM_SFR_NVM_CONF1_HRLEV_Msk      0x3UL
#define RRAMC_RRAM_SFR_NVM_CONF1_DWVERR_Pos     4UL
#define RRAMC_RRAM_SFR_NVM_CONF1_DWVERR_Msk     0x70UL
#define RRAMC_RRAM_SFR_NVM_CONF1_TRAP_ON_Pos    14UL
#define RRAMC_RRAM_SFR_NVM_CONF1_TRAP_ON_Msk    0x4000UL
#define RRAMC_RRAM_SFR_NVM_CONF1_NVM_ON_Pos     15UL
#define RRAMC_RRAM_SFR_NVM_CONF1_NVM_ON_Msk     0x8000UL
#define RRAMC_RRAM_SFR_NVM_CONF1_SECPROT_Pos    16UL
#define RRAMC_RRAM_SFR_NVM_CONF1_SECPROT_Msk    0x3FF0000UL
#define RRAMC_RRAM_SFR_NVM_CONF1_WPLCK_Pos      31UL
#define RRAMC_RRAM_SFR_NVM_CONF1_WPLCK_Msk      0x80000000UL
/* RRAMC_RRAM_SFR.NVM_HARDEN1 */
#define RRAMC_RRAM_SFR_NVM_HARDEN1_BLOCKS_Pos   0UL
#define RRAMC_RRAM_SFR_NVM_HARDEN1_BLOCKS_Msk   0x1FFUL
#define RRAMC_RRAM_SFR_NVM_HARDEN1_ALLMEM_Pos   15UL
#define RRAMC_RRAM_SFR_NVM_HARDEN1_ALLMEM_Msk   0x8000UL
/* RRAMC_RRAM_SFR.NVM_HARDADDR */
#define RRAMC_RRAM_SFR_NVM_HARDADDR_ADDRB_Pos   0UL
#define RRAMC_RRAM_SFR_NVM_HARDADDR_ADDRB_Msk   0x1FUL
#define RRAMC_RRAM_SFR_NVM_HARDADDR_ADDRWL_Pos  5UL
#define RRAMC_RRAM_SFR_NVM_HARDADDR_ADDRWL_Msk  0xE0UL
#define RRAMC_RRAM_SFR_NVM_HARDADDR_ADDRS_Pos   8UL
#define RRAMC_RRAM_SFR_NVM_HARDADDR_ADDRS_Msk   0x3FF00UL
/* RRAMC_RRAM_SFR.NVM_HRESP */
#define RRAMC_RRAM_SFR_NVM_HRESP_HRESP_Pos      0UL
#define RRAMC_RRAM_SFR_NVM_HRESP_HRESP_Msk      0x7UL
#define RRAMC_RRAM_SFR_NVM_HRESP_RSTHRESP_Pos   15UL
#define RRAMC_RRAM_SFR_NVM_HRESP_RSTHRESP_Msk   0x8000UL
/* RRAMC_RRAM_SFR.NVM_ECCLOG */
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC1CNT_Pos   0UL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC1CNT_Msk   0xFFFFUL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC2CNT_Pos   16UL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC2CNT_Msk   0xFF0000UL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC3CNT_Pos   24UL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC3CNT_Msk   0xF000000UL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC4CNT_Pos   28UL
#define RRAMC_RRAM_SFR_NVM_ECCLOG_ECC4CNT_Msk   0xF0000000UL
/* RRAMC_RRAM_SFR.NVM_ECCLOGIR */
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC1CNTIR_Pos 0UL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC1CNTIR_Msk 0xFFFFUL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC2CNTIR_Pos 16UL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC2CNTIR_Msk 0xFF0000UL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC3CNTIR_Pos 24UL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC3CNTIR_Msk 0xF000000UL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC4CNTIR_Pos 28UL
#define RRAMC_RRAM_SFR_NVM_ECCLOGIR_ECC4CNTIR_Msk 0xF0000000UL
/* RRAMC_RRAM_SFR.NVM_VMODE */
#define RRAMC_RRAM_SFR_NVM_VMODE_VMODE_Pos      0UL
#define RRAMC_RRAM_SFR_NVM_VMODE_VMODE_Msk      0x3UL


#endif /* _CYIP_RRAMC_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* SMIF IP definitions
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

#ifndef _CYIP_SMIF_V6_H_
#define _CYIP_SMIF_V6_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     SMIF
*******************************************************************************/

#define SMIF_CACHE_BLOCK_MMIO_SECTION_SIZE      0x00000080UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_SECTION_SIZE 0x00001000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_SECTION_SIZE 0x00001000UL
#define SMIF_CACHE_BLOCK_SECTION_SIZE           0x00010000UL
#define SMIF_CORE_SMIF_CRYPTO_SECTION_SIZE      0x00000080UL
#define SMIF_CORE_DEVICE_SECTION_SIZE           0x00000080UL
#define SMIF_CORE_AXI_MPC_SECTION_SIZE          0x00001000UL
#define SMIF_CORE_AXI_SECTION_SIZE              0x00001000UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_SECTION_SIZE 0x00000010UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_SECTION_SIZE 0x00000010UL
#define SMIF_CORE_SMIF_HSIOM_SECTION_SIZE       0x00004000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_SECTION_SIZE 0x00000080UL
#define SMIF_CORE_SMIF_GPIO_SECTION_SIZE        0x00010000UL
#define SMIF_CORE_SECTION_SIZE                  0x00020000UL
#define SMIF_SECTION_SIZE                       0x00040000UL

/**
  * \brief MMIO regs for cacheblock (anything other than cache IP related MMIO regs) (SMIF_CACHE_BLOCK_MMIO)
  */
typedef struct {
  __IOM uint32_t BYPASS_WI;                     /*!< 0x00000000 Bypass wrap to increment conversion logic */
  __IOM uint32_t MASTER_ID;                     /*!< 0x00000004 The cache generates transactions (linefill and eviction
                                                                Write-Back) that are marked with the value specified by
                                                                MASTER_ID on hmaster_m. */
  __IOM uint32_t DIS_CACHE_EN_MAINT;            /*!< 0x00000008 This signal turns on/off cache enable maintenance. */
  __IOM uint32_t DIS_CACHE_DIS_MAINT;           /*!< 0x0000000C This signal turns on/off cache disable maintenance. */
  __IOM uint32_t APB_VIOLATION_RESP;            /*!< 0x00000010 This signal controls if the APB interface of cache responds
                                                                with an error to illegal operations on the APB interface.
                                                                Illegal operations on the APB interface include Writing with no
                                                                full write strobe, Accessing non-word aligned addresses,
                                                                Instruction accesses, Non-privileged accesses 1 - The Cache
                                                                responds with an APB error. Read data is masked with zeros and
                                                                write data is ignored. 0 - The Cache sends an OK response. Read
                                                                data is masked with zeros and write data is ignored. */
  __IOM uint32_t MMIO_ACTIVE_EN;                /*!< 0x00000014 SW control to put SMIF.6 in active or clock gated mode */
  __IOM uint32_t POWER_ON_ENABLE;               /*!< 0x00000018 This signal configures the cache to enable the cache
                                                                automatically after powerup. */
  __IOM uint32_t MMIO_CACHE_RET_EN;             /*!< 0x0000001C Controls if cache SRAMs are retained during DPSLP */
  __IOM uint32_t DIS_PWR_DOWN_MAINT;            /*!< 0x00000020 This signal turns on/off powerdown maintenance. */
  __IOM uint32_t REGION0_BASE;                  /*!< 0x00000024 Region 0 Attributes - register 0; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION0_LIMIT;                 /*!< 0x00000028 Region 0 Attributes - register 1; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION1_BASE;                  /*!< 0x0000002C Region 1 Attributes - register 0; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION1_LIMIT;                 /*!< 0x00000030 Region 1 Attributes - register 1; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION2_BASE;                  /*!< 0x00000034 Region 2 Attributes - register 0; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION2_LIMIT;                 /*!< 0x00000038 Region 2 Attributes - register 1; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION3_BASE;                  /*!< 0x0000003C Region 3 Attributes - register 0; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
  __IOM uint32_t REGION3_LIMIT;                 /*!< 0x00000040 Region 3 Attributes - register 1; Region attributes shall be
                                                                changed exclusively while the SMIF is disabled, and the XIP
                                                                interfaces are idle */
   __IM uint32_t RESERVED[15];
} SMIF_CACHE_BLOCK_MMIO_Type;                   /*!< Size = 128 (0x80) */

/**
  * \brief MPC Memory Protection Controller registers (SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC)
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
} SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_Type;       /*!< Size = 4096 (0x1000) */

/**
  * \brief SMIF Cacheblock MPC (SMIF_CACHE_BLOCK_CACHEBLK_AHB)
  */
typedef struct {
        SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_Type MPC[1]; /*!< 0x00000000 MPC Memory Protection Controller registers */
} SMIF_CACHE_BLOCK_CACHEBLK_AHB_Type;           /*!< Size = 4096 (0x1000) */

/**
  * \brief Serial Memory Interface (SMIF_CACHE_BLOCK)
  */
typedef struct {
   __IM uint32_t HWPARAMS;                      /*!< 0x00000000 Hardware Parameter register */
   __IM uint32_t RESERVED[3];
  __IOM uint32_t CTRL;                          /*!< 0x00000010 Control Register */
   __IM uint32_t NSEC_ACCESS;                   /*!< 0x00000014 Non-secure access information */
   __IM uint32_t RESERVED1[2];
   __OM uint32_t MAINT_CTRL_ALL;                /*!< 0x00000020 Maintenance control for the entire cache */
   __OM uint32_t MAINT_CTRL_LINES;              /*!< 0x00000024 Maintenance control for individual lines */
   __IM uint32_t MAINT_STATUS;                  /*!< 0x00000028 Maintenance status for the cache */
   __IM uint32_t RESERVED2[53];
   __IM uint32_t SECIRQSTAT;                    /*!< 0x00000100 Secure Interrupt Request Status register */
   __OM uint32_t SECIRQSCLR;                    /*!< 0x00000104 Secure Interrupt Status Clear register */
  __IOM uint32_t SECIRQEN;                      /*!< 0x00000108 Secure Interrupt Enable register */
   __IM uint32_t SECIRQINFO1;                   /*!< 0x0000010C Secure transfer error information 1 */
   __IM uint32_t SECIRQINFO2;                   /*!< 0x00000110 Secure transfer error information 2 */
   __IM uint32_t RESERVED3[11];
   __IM uint32_t NSECIRQSTAT;                   /*!< 0x00000140 Non-secure Interrupt Request Status register */
   __OM uint32_t NSECIRQSCLR;                   /*!< 0x00000144 Non-secure Interrupt Status Clear register */
  __IOM uint32_t NSECIRQEN;                     /*!< 0x00000148 Non-secure Interrupt Enable register */
   __IM uint32_t NSECIRQINFO1;                  /*!< 0x0000014C Non-secure transfer error information 1 */
   __IM uint32_t NSECIRQINFO2;                  /*!< 0x00000150 Non-secure transfer error information 2 */
   __IM uint32_t RESERVED4[107];
   __IM uint32_t SECHIT;                        /*!< 0x00000300 Secure transfers Hit register */
   __IM uint32_t SECMISS;                       /*!< 0x00000304 Secure transfers Miss register */
  __IOM uint32_t SECSTATCTRL;                   /*!< 0x00000308 Secure transfers statistic counters control */
   __IM uint32_t RESERVED5;
   __IM uint32_t NSECHIT;                       /*!< 0x00000310 Non-secure transfers Hit register */
   __IM uint32_t NSECMISS;                      /*!< 0x00000314 Non-secure transfers Miss register */
  __IOM uint32_t NSECSTATCTRL;                  /*!< 0x00000318 Non-secure transfers statistic counters control */
   __IM uint32_t RESERVED6[185];
   __IM uint32_t PMSVR0;                        /*!< 0x00000600 Saved Value Register 0 - Secure Hit */
   __IM uint32_t PMSVR1;                        /*!< 0x00000604 Saved Value Register 1 - Secure Miss */
   __IM uint32_t PMSVR2;                        /*!< 0x00000608 Saved Value Register 2 - Non-secure Hit */
   __IM uint32_t PMSVR3;                        /*!< 0x0000060C Saved Value Register 3 - Non-secure Miss */
   __IM uint32_t RESERVED7[28];
   __IM uint32_t PMSSSR;                        /*!< 0x00000680 PMU Snapshot Status Register */
   __IM uint32_t RESERVED8[27];
   __OM uint32_t PMSSCR;                        /*!< 0x000006F0 PMU Snapshot Capture Register */
  __IOM uint32_t PMSSRR;                        /*!< 0x000006F4 PMU Snapshot Reset Register */
   __IM uint32_t RESERVED9[566];
   __IM uint32_t PIDR4;                         /*!< 0x00000FD0 Peripheral ID 4 */
   __IM uint32_t PIDR5;                         /*!< 0x00000FD4 Peripheral ID 5 */
   __IM uint32_t PIDR6;                         /*!< 0x00000FD8 Peripheral ID 6 */
   __IM uint32_t PIDR7;                         /*!< 0x00000FDC Peripheral ID 7 */
   __IM uint32_t PIDR0;                         /*!< 0x00000FE0 Peripheral ID 0 */
   __IM uint32_t PIDR1;                         /*!< 0x00000FE4 Peripheral ID 1 */
   __IM uint32_t PIDR2;                         /*!< 0x00000FE8 Peripheral ID 2 */
   __IM uint32_t PIDR3;                         /*!< 0x00000FEC Peripheral ID 3 */
   __IM uint32_t CIDR0;                         /*!< 0x00000FF0 Component ID 0 */
   __IM uint32_t CIDR1;                         /*!< 0x00000FF4 Component ID 1 */
   __IM uint32_t CIDR2;                         /*!< 0x00000FF8 Component ID 2 */
   __IM uint32_t CIDR3;                         /*!< 0x00000FFC Component ID 3 */
   __IM uint32_t RESERVED10[1024];
        SMIF_CACHE_BLOCK_MMIO_Type MMIO;        /*!< 0x00002000 MMIO regs for cacheblock (anything other than cache IP related
                                                                MMIO regs) */
   __IM uint32_t RESERVED11[2016];
        SMIF_CACHE_BLOCK_CACHEBLK_AHB_Type CACHEBLK_AHB; /*!< 0x00004000 SMIF Cacheblock MPC */
   __IM uint32_t RESERVED12[11264];
} SMIF_CACHE_BLOCK_Type;                        /*!< Size = 65536 (0x10000) */

/**
  * \brief Cryptography registers (one set for each key) (SMIF_CORE_SMIF_CRYPTO)
  */
typedef struct {
  __IOM uint32_t CRYPTO_CMD;                    /*!< 0x00000000 Cryptography command */
  __IOM uint32_t CRYPTO_ADDR;                   /*!< 0x00000004 Cryptography base address */
  __IOM uint32_t CRYPTO_MASK;                   /*!< 0x00000008 Cryptography mask */
  __IOM uint32_t CRYPTO_SUBREGION;              /*!< 0x0000000C Cryptography subregion disable */
   __IM uint32_t RESERVED[4];
  __IOM uint32_t CRYPTO_INPUT0;                 /*!< 0x00000020 Cryptography input 0 */
  __IOM uint32_t CRYPTO_INPUT1;                 /*!< 0x00000024 Cryptography input 1 */
  __IOM uint32_t CRYPTO_INPUT2;                 /*!< 0x00000028 Cryptography input 2 */
  __IOM uint32_t CRYPTO_INPUT3;                 /*!< 0x0000002C Cryptography input 3 */
   __IM uint32_t RESERVED1[4];
   __OM uint32_t CRYPTO_KEY0;                   /*!< 0x00000040 Cryptography key 0 */
   __OM uint32_t CRYPTO_KEY1;                   /*!< 0x00000044 Cryptography key 1 */
   __OM uint32_t CRYPTO_KEY2;                   /*!< 0x00000048 Cryptography key 2 */
   __OM uint32_t CRYPTO_KEY3;                   /*!< 0x0000004C Cryptography key 3 */
   __IM uint32_t RESERVED2[4];
  __IOM uint32_t CRYPTO_OUTPUT0;                /*!< 0x00000060 Cryptography output 0 */
  __IOM uint32_t CRYPTO_OUTPUT1;                /*!< 0x00000064 Cryptography output 1 */
  __IOM uint32_t CRYPTO_OUTPUT2;                /*!< 0x00000068 Cryptography output 2 */
  __IOM uint32_t CRYPTO_OUTPUT3;                /*!< 0x0000006C Cryptography output 3 */
   __IM uint32_t RESERVED3[4];
} SMIF_CORE_SMIF_CRYPTO_Type;                   /*!< Size = 128 (0x80) */

/**
  * \brief Device (only used for XIP acceses) (SMIF_CORE_DEVICE)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t RESERVED;
  __IOM uint32_t ADDR;                          /*!< 0x00000008 Device region base address */
  __IOM uint32_t MASK;                          /*!< 0x0000000C Device region mask */
   __IM uint32_t RESERVED1[4];
  __IOM uint32_t ADDR_CTL;                      /*!< 0x00000020 Address control */
   __IM uint32_t RESERVED2;
  __IOM uint32_t RX_CAPTURE_CONFIG;             /*!< 0x00000028 RX capture configuration */
   __IM uint32_t RESERVED3;
   __IM uint32_t RD_STATUS;                     /*!< 0x00000030 Read status */
   __IM uint32_t RESERVED4[3];
  __IOM uint32_t RD_CMD_CTL;                    /*!< 0x00000040 Read command control */
  __IOM uint32_t RD_ADDR_CTL;                   /*!< 0x00000044 Read address control */
  __IOM uint32_t RD_MODE_CTL;                   /*!< 0x00000048 Read mode control */
  __IOM uint32_t RD_DUMMY_CTL;                  /*!< 0x0000004C Read dummy control */
  __IOM uint32_t RD_DATA_CTL;                   /*!< 0x00000050 Read data control */
  __IOM uint32_t RD_CRC_CTL;                    /*!< 0x00000054 Read Bus CRC control */
  __IOM uint32_t RD_BOUND_CTL;                  /*!< 0x00000058 Read boundary control */
   __IM uint32_t RESERVED5;
  __IOM uint32_t WR_CMD_CTL;                    /*!< 0x00000060 Write command control */
  __IOM uint32_t WR_ADDR_CTL;                   /*!< 0x00000064 Write address control */
  __IOM uint32_t WR_MODE_CTL;                   /*!< 0x00000068 Write mode control */
  __IOM uint32_t WR_DUMMY_CTL;                  /*!< 0x0000006C Write dummy control */
  __IOM uint32_t WR_DATA_CTL;                   /*!< 0x00000070 Write data control */
  __IOM uint32_t WR_CRC_CTL;                    /*!< 0x00000074 Write Bus CRC control */
  __IOM uint32_t HB_FW_DEL_TAP_SEL_0;           /*!< 0x00000078 HB FW Calibration Delay Tap Select 0 */
  __IOM uint32_t HB_FW_DEL_TAP_SEL_1;           /*!< 0x0000007C HB FW Calibration Delay Tap Select 1 */
} SMIF_CORE_DEVICE_Type;                        /*!< Size = 128 (0x80) */

/**
  * \brief MPC Memory Protection Controller registers (SMIF_CORE_AXI_MPC)
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
} SMIF_CORE_AXI_MPC_Type;                       /*!< Size = 4096 (0x1000) */

/**
  * \brief Serial Memory Interface (SMIF_CORE_AXI)
  */
typedef struct {
        SMIF_CORE_AXI_MPC_Type MPC[1];          /*!< 0x00000000 MPC Memory Protection Controller registers */
} SMIF_CORE_AXI_Type;                           /*!< Size = 4096 (0x1000) */

/**
  * \brief HSIOM port registers (SMIF_CORE_SMIF_HSIOM_SMIF_PRT)
  */
typedef struct {
  __IOM uint32_t PORT_SEL0;                     /*!< 0x00000000 Port selection 0 */
  __IOM uint32_t PORT_SEL1;                     /*!< 0x00000004 Port selection 1 */
   __IM uint32_t RESERVED[2];
} SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type;           /*!< Size = 16 (0x10) */

/**
  * \brief HSIOM secure attribute port registers (SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT)
  */
typedef struct {
  __IOM uint32_t NONSECURE_MASK;                /*!< 0x00000000 Non-Secure Mask */
   __IM uint32_t RESERVED[3];
} SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type;    /*!< Size = 16 (0x10) */

/**
  * \brief IO Matrix (IOM) (SMIF_CORE_SMIF_HSIOM)
  */
typedef struct {
        SMIF_CORE_SMIF_HSIOM_SMIF_PRT_Type SMIF_PRT[3]; /*!< 0x00000000 HSIOM port registers */
   __IM uint32_t RESERVED[1012];
        SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_Type SMIF_SECURE_PRT[3]; /*!< 0x00001000 HSIOM secure attribute port registers */
   __IM uint32_t RESERVED1[1012];
  __IOM uint32_t AMUX_SPLIT_CTL[64];            /*!< 0x00002000 AMUX splitter cell control */
   __IM uint32_t RESERVED2[64];
  __IOM uint32_t MONITOR_CTL_0;                 /*!< 0x00002200 Power/Ground Monitor cell control 0 */
  __IOM uint32_t MONITOR_CTL_1;                 /*!< 0x00002204 Power/Ground Monitor cell control 1 */
  __IOM uint32_t MONITOR_CTL_2;                 /*!< 0x00002208 Power/Ground Monitor cell control 2 */
  __IOM uint32_t MONITOR_CTL_3;                 /*!< 0x0000220C Power/Ground Monitor cell control 3 */
   __IM uint32_t RESERVED3[1916];
} SMIF_CORE_SMIF_HSIOM_Type;                    /*!< Size = 16384 (0x4000) */

/**
  * \brief GPIO port registers (SMIF_CORE_SMIF_GPIO_SMIF_PRT)
  */
typedef struct {
  __IOM uint32_t OUT;                           /*!< 0x00000000 Port output data register */
  __IOM uint32_t OUT_CLR;                       /*!< 0x00000004 Port output data clear register */
  __IOM uint32_t OUT_SET;                       /*!< 0x00000008 Port output data set register */
  __IOM uint32_t OUT_INV;                       /*!< 0x0000000C Port output data invert register */
   __IM uint32_t IN;                            /*!< 0x00000010 Port input state register */
  __IOM uint32_t INTR;                          /*!< 0x00000014 Port interrupt status register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000018 Port interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000001C Port interrupt masked status register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000020 Port interrupt set register */
   __IM uint32_t RESERVED[7];
  __IOM uint32_t INTR_CFG;                      /*!< 0x00000040 Port interrupt configuration register */
  __IOM uint32_t CFG;                           /*!< 0x00000044 Port configuration register */
  __IOM uint32_t CFG_IN;                        /*!< 0x00000048 Port input buffer configuration register */
  __IOM uint32_t CFG_OUT;                       /*!< 0x0000004C Port output buffer configuration register */
  __IOM uint32_t CFG_SIO;                       /*!< 0x00000050 Port SIO configuration register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CFG_IN_AUTOLVL;                /*!< 0x00000058 Port input buffer AUTOLVL configuration register for S40E GPIO */
   __IM uint32_t RESERVED2;
  __IOM uint32_t CFG_OUT2;                      /*!< 0x00000060 Port output buffer configuration register 2 */
  __IOM uint32_t CFG_SLEW_EXT;                  /*!< 0x00000064 Port output buffer slew extension configuration register */
  __IOM uint32_t CFG_DRIVE_EXT0;                /*!< 0x00000068 Port output buffer drive sel extension configuration register */
  __IOM uint32_t CFG_DRIVE_EXT1;                /*!< 0x0000006C Port output buffer drive sel extension configuration register */
  __IOM uint32_t CFG_OUT3;                      /*!< 0x00000070 Port output buffer configuration register 3 */
  __IOM uint32_t CFG_RES;                       /*!< 0x00000074 Port resistor configuration register 3 */
  __IOM uint32_t MSC_ANA;                       /*!< 0x00000078 Port MSCv3 AMUX enable */
   __IM uint32_t RESERVED3;
} SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type;            /*!< Size = 128 (0x80) */

/**
  * \brief IO port control/configuration (SMIF_CORE_SMIF_GPIO)
  */
typedef struct {
        SMIF_CORE_SMIF_GPIO_SMIF_PRT_Type SMIF_PRT[3]; /*!< 0x00000000 GPIO port registers */
   __IM uint32_t RESERVED[7072];
   __IM uint32_t SEC_INTR_CAUSE0;               /*!< 0x00007000 Secure Interrupt port cause register 0 */
   __IM uint32_t SEC_INTR_CAUSE1;               /*!< 0x00007004 Secure Interrupt port cause register 1 */
   __IM uint32_t SEC_INTR_CAUSE2;               /*!< 0x00007008 Secure Interrupt port cause register 2 */
   __IM uint32_t SEC_INTR_CAUSE3;               /*!< 0x0000700C Secure Interrupt port cause register 3 */
   __IM uint32_t RESERVED1[1020];
   __IM uint32_t INTR_CAUSE0;                   /*!< 0x00008000 Interrupt port cause register 0 */
   __IM uint32_t INTR_CAUSE1;                   /*!< 0x00008004 Interrupt port cause register 1 */
   __IM uint32_t INTR_CAUSE2;                   /*!< 0x00008008 Interrupt port cause register 2 */
   __IM uint32_t INTR_CAUSE3;                   /*!< 0x0000800C Interrupt port cause register 3 */
   __IM uint32_t VDD_ACTIVE;                    /*!< 0x00008010 Extern power supply detection register */
  __IOM uint32_t VDD_INTR;                      /*!< 0x00008014 Supply detection interrupt register */
  __IOM uint32_t VDD_INTR_MASK;                 /*!< 0x00008018 Supply detection interrupt mask register */
   __IM uint32_t VDD_INTR_MASKED;               /*!< 0x0000801C Supply detection interrupt masked register */
  __IOM uint32_t VDD_INTR_SET;                  /*!< 0x00008020 Supply detection interrupt set register */
   __IM uint32_t VDD_PWRSW_STATUS;              /*!< 0x00008024 Power switch status */
   __IM uint32_t RESERVED2[54];
  __IOM uint32_t VDD_PWRSW_CTL;                 /*!< 0x00008100 Power Switch control */
   __IM uint32_t RESERVED3[8127];
} SMIF_CORE_SMIF_GPIO_Type;                     /*!< Size = 65536 (0x10000) */

/**
  * \brief Serial Memory Interface (SMIF_CORE)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Status */
  __IOM uint32_t CTL2;                          /*!< 0x00000008 Control 2 */
   __IM uint32_t RESERVED;
   __IM uint32_t DLP_DELAY_TAP_SEL0;            /*!< 0x00000010 DLP Delay Tap Select Register 0 */
   __IM uint32_t DLP_DELAY_TAP_SEL1;            /*!< 0x00000014 DLP Delay Tap Select Register 1 */
  __IOM uint32_t DLP_CTL;                       /*!< 0x00000018 DLP Control Register */
   __IM uint32_t RESERVED1;
   __IM uint32_t DLP_STATUS0;                   /*!< 0x00000020 DLP Status Register 0 */
   __IM uint32_t DLP_STATUS1;                   /*!< 0x00000024 DLP Status Register 1 */
   __IM uint32_t RESERVED2[7];
   __IM uint32_t TX_CMD_FIFO_STATUS;            /*!< 0x00000044 Transmitter command FIFO status */
   __IM uint32_t TX_CMD_MMIO_FIFO_STATUS;       /*!< 0x00000048 Transmitter command MMIO FIFO status */
   __IM uint32_t RESERVED3;
   __OM uint32_t TX_CMD_MMIO_FIFO_WR;           /*!< 0x00000050 Transmitter command MMIO FIFO write */
   __IM uint32_t RESERVED4[11];
  __IOM uint32_t TX_DATA_MMIO_FIFO_CTL;         /*!< 0x00000080 Transmitter data MMIO FIFO control */
   __IM uint32_t TX_DATA_FIFO_STATUS;           /*!< 0x00000084 Transmitter data FIFO status */
   __IM uint32_t TX_DATA_MMIO_FIFO_STATUS;      /*!< 0x00000088 Transmitter data MMIO FIFO status */
   __IM uint32_t RESERVED5;
   __OM uint32_t TX_DATA_MMIO_FIFO_WR1;         /*!< 0x00000090 Transmitter data MMIO FIFO write */
   __OM uint32_t TX_DATA_MMIO_FIFO_WR2;         /*!< 0x00000094 Transmitter data MMIO FIFO write */
   __OM uint32_t TX_DATA_MMIO_FIFO_WR4;         /*!< 0x00000098 Transmitter data MMIO FIFO write */
   __OM uint32_t TX_DATA_MMIO_FIFO_WR1ODD;      /*!< 0x0000009C Transmitter data MMIO FIFO write */
   __IM uint32_t RESERVED6[8];
  __IOM uint32_t RX_DATA_MMIO_FIFO_CTL;         /*!< 0x000000C0 Receiver data MMIO FIFO control */
   __IM uint32_t RX_DATA_MMIO_FIFO_STATUS;      /*!< 0x000000C4 Receiver data MMIO FIFO status */
   __IM uint32_t RX_DATA_FIFO_STATUS;           /*!< 0x000000C8 Receiver data FIFO status */
   __IM uint32_t RESERVED7;
   __IM uint32_t RX_DATA_MMIO_FIFO_RD1;         /*!< 0x000000D0 Receiver data MMIO FIFO read */
   __IM uint32_t RX_DATA_MMIO_FIFO_RD2;         /*!< 0x000000D4 Receiver data MMIO FIFO read */
   __IM uint32_t RX_DATA_MMIO_FIFO_RD4;         /*!< 0x000000D8 Receiver data MMIO FIFO read */
   __IM uint32_t RESERVED8;
   __IM uint32_t RX_DATA_MMIO_FIFO_RD1_SILENT;  /*!< 0x000000E0 Receiver data MMIO FIFO silent read */
   __IM uint32_t RESERVED9[7];
  __IOM uint32_t SLOW_CA_CTL;                   /*!< 0x00000100 Slow cache control */
   __IM uint32_t RESERVED10;
  __IOM uint32_t SLOW_CA_CMD;                   /*!< 0x00000108 Slow cache command */
   __IM uint32_t RESERVED11[29];
  __IOM uint32_t FAST_CA_CTL;                   /*!< 0x00000180 Fast cache control */
   __IM uint32_t RESERVED12;
  __IOM uint32_t FAST_CA_CMD;                   /*!< 0x00000188 Fast cache command */
   __IM uint32_t RESERVED13[29];
        SMIF_CORE_SMIF_CRYPTO_Type SMIF_CRYPTO_BLOCK[4]; /*!< 0x00000200 Cryptography registers (one set for each key) */
   __IM uint32_t RESERVED14[128];
  __IOM uint32_t CRC_CMD;                       /*!< 0x00000600 CRC Command */
   __IM uint32_t RESERVED15[7];
  __IOM uint32_t CRC_INPUT0;                    /*!< 0x00000620 CRC input 0 */
  __IOM uint32_t CRC_INPUT1;                    /*!< 0x00000624 CRC input 1 */
   __IM uint32_t RESERVED16[6];
   __IM uint32_t CRC_OUTPUT;                    /*!< 0x00000640 CRC output */
   __IM uint32_t RESERVED17[95];
  __IOM uint32_t INTR;                          /*!< 0x000007C0 Interrupt register */
  __IOM uint32_t INTR_SET;                      /*!< 0x000007C4 Interrupt set register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000007C8 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000007CC Interrupt masked register */
   __IM uint32_t RESERVED18[2];
  __IOM uint32_t DLL_IDAC;                      /*!< 0x000007D8 DLL IDAC ( when DLL runs in open loop, selects the delay of the
                                                                delay line) */
  __IOM uint32_t DLL_IVR;                       /*!< 0x000007DC DLL IVR (Contol Output Voltage of internal Voltage Regulator ) */
   __IM uint32_t RESERVED19[8];
        SMIF_CORE_DEVICE_Type DEVICE[4];        /*!< 0x00000800 Device (only used for XIP acceses) */
   __IM uint32_t RESERVED20[2432];
        SMIF_CORE_AXI_Type AXI;                 /*!< 0x00003000 Serial Memory Interface */
        SMIF_CORE_SMIF_HSIOM_Type SMIF_HSIOM;   /*!< 0x00004000 IO Matrix (IOM) */
   __IM uint32_t RESERVED21[8192];
        SMIF_CORE_SMIF_GPIO_Type SMIF_GPIO;     /*!< 0x00010000 IO port control/configuration */
} SMIF_CORE_Type;                               /*!< Size = 131072 (0x20000) */

/**
  * \brief SMIF subsystem (1 SMIF cores, no bridge, 1 cache_block and 1 Q_LPI expander) (SMIF_STRUCT)
  */
typedef struct {
   __IM uint32_t RESERVED[16384];
        SMIF_CACHE_BLOCK_Type CACHE_BLOCK;      /*!< 0x00010000 Serial Memory Interface */
        SMIF_CORE_Type CORE;                    /*!< 0x00020000 Serial Memory Interface */
} SMIF_STRUCT_Type;                             /*!< Size = 262144 (0x40000) */


/* SMIF_CACHE_BLOCK_MMIO.BYPASS_WI */
#define SMIF_CACHE_BLOCK_MMIO_BYPASS_WI_BYPASS_WI_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_BYPASS_WI_BYPASS_WI_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.MASTER_ID */
#define SMIF_CACHE_BLOCK_MMIO_MASTER_ID_MASTER_ID_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_MASTER_ID_MASTER_ID_Msk 0xFFUL
/* SMIF_CACHE_BLOCK_MMIO.DIS_CACHE_EN_MAINT */
#define SMIF_CACHE_BLOCK_MMIO_DIS_CACHE_EN_MAINT_DIS_CACHE_EN_MAINT_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_DIS_CACHE_EN_MAINT_DIS_CACHE_EN_MAINT_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.DIS_CACHE_DIS_MAINT */
#define SMIF_CACHE_BLOCK_MMIO_DIS_CACHE_DIS_MAINT_DIS_CACHE_DIS_MAINT_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_DIS_CACHE_DIS_MAINT_DIS_CACHE_DIS_MAINT_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.APB_VIOLATION_RESP */
#define SMIF_CACHE_BLOCK_MMIO_APB_VIOLATION_RESP_APB_VIOLATION_RESP_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_APB_VIOLATION_RESP_APB_VIOLATION_RESP_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.MMIO_ACTIVE_EN */
#define SMIF_CACHE_BLOCK_MMIO_MMIO_ACTIVE_EN_MMIO_ACTIVE_EN_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_MMIO_ACTIVE_EN_MMIO_ACTIVE_EN_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.POWER_ON_ENABLE */
#define SMIF_CACHE_BLOCK_MMIO_POWER_ON_ENABLE_POWER_ON_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_POWER_ON_ENABLE_POWER_ON_ENABLE_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.MMIO_CACHE_RET_EN */
#define SMIF_CACHE_BLOCK_MMIO_MMIO_CACHE_RET_EN_MMIO_CACHE_RET_EN_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_MMIO_CACHE_RET_EN_MMIO_CACHE_RET_EN_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.DIS_PWR_DOWN_MAINT */
#define SMIF_CACHE_BLOCK_MMIO_DIS_PWR_DOWN_MAINT_DIS_PWR_DOWN_MAINT_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_DIS_PWR_DOWN_MAINT_DIS_PWR_DOWN_MAINT_Msk 0x1UL
/* SMIF_CACHE_BLOCK_MMIO.REGION0_BASE */
#define SMIF_CACHE_BLOCK_MMIO_REGION0_BASE_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION0_BASE_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION0_LIMIT */
#define SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ENABLE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ATTR_Pos 1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ATTR_Msk 0x3EUL
#define SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION0_LIMIT_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION1_BASE */
#define SMIF_CACHE_BLOCK_MMIO_REGION1_BASE_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION1_BASE_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION1_LIMIT */
#define SMIF_CACHE_BLOCK_MMIO_REGION1_LIMIT_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_REGION1_LIMIT_ENABLE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION1_LIMIT_ATTR_Pos 1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION1_LIMIT_ATTR_Msk 0x3EUL
#define SMIF_CACHE_BLOCK_MMIO_REGION1_LIMIT_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION1_LIMIT_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION2_BASE */
#define SMIF_CACHE_BLOCK_MMIO_REGION2_BASE_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION2_BASE_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION2_LIMIT */
#define SMIF_CACHE_BLOCK_MMIO_REGION2_LIMIT_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_REGION2_LIMIT_ENABLE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION2_LIMIT_ATTR_Pos 1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION2_LIMIT_ATTR_Msk 0x3EUL
#define SMIF_CACHE_BLOCK_MMIO_REGION2_LIMIT_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION2_LIMIT_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION3_BASE */
#define SMIF_CACHE_BLOCK_MMIO_REGION3_BASE_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION3_BASE_ADDR_Msk 0x7FFF000UL
/* SMIF_CACHE_BLOCK_MMIO.REGION3_LIMIT */
#define SMIF_CACHE_BLOCK_MMIO_REGION3_LIMIT_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_MMIO_REGION3_LIMIT_ENABLE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION3_LIMIT_ATTR_Pos 1UL
#define SMIF_CACHE_BLOCK_MMIO_REGION3_LIMIT_ATTR_Msk 0x3EUL
#define SMIF_CACHE_BLOCK_MMIO_REGION3_LIMIT_ADDR_Pos 12UL
#define SMIF_CACHE_BLOCK_MMIO_REGION3_LIMIT_ADDR_Msk 0x7FFF000UL


/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.CFG */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_CFG_RESPONSE_Pos 4UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_CFG_RESPONSE_Msk 0x10UL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.CTRL */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_CTRL_AUTO_INC_Pos 8UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_CTRL_AUTO_INC_Msk 0x100UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_CTRL_LOCK_Pos 31UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_CTRL_LOCK_Msk 0x80000000UL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.BLK_MAX */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_MAX_VALUE_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_MAX_VALUE_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.BLK_CFG */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.BLK_IDX */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_IDX_VALUE_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_IDX_VALUE_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.BLK_LUT */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS0_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS0_Msk 0x1UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS1_Pos 1UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS1_Msk 0x2UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS2_Pos 2UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS2_Msk 0x4UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS3_Pos 3UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS3_Msk 0x8UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS4_Pos 4UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS4_Msk 0x10UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS5_Pos 5UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS5_Msk 0x20UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS6_Pos 6UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS6_Msk 0x40UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS7_Pos 7UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS7_Msk 0x80UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS8_Pos 8UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS8_Msk 0x100UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS9_Pos 9UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS9_Msk 0x200UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS10_Pos 10UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS10_Msk 0x400UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS11_Pos 11UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS11_Msk 0x800UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS12_Pos 12UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS12_Msk 0x1000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS13_Pos 13UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS13_Msk 0x2000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS14_Pos 14UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS14_Msk 0x4000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS15_Pos 15UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS15_Msk 0x8000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS16_Pos 16UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS16_Msk 0x10000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS17_Pos 17UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS17_Msk 0x20000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS18_Pos 18UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS18_Msk 0x40000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS19_Pos 19UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS19_Msk 0x80000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS20_Pos 20UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS20_Msk 0x100000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS21_Pos 21UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS21_Msk 0x200000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS22_Pos 22UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS22_Msk 0x400000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS23_Pos 23UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS23_Msk 0x800000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS24_Pos 24UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS24_Msk 0x1000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS25_Pos 25UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS25_Msk 0x2000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS26_Pos 26UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS26_Msk 0x4000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS27_Pos 27UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS27_Msk 0x8000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS28_Pos 28UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS28_Msk 0x10000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS29_Pos 29UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS29_Msk 0x20000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS30_Pos 30UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS30_Msk 0x40000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS31_Pos 31UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_BLK_LUT_ATTR_NS31_Msk 0x80000000UL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.ROT_CTRL */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_CTRL_AUTO_INC_Pos 8UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_CTRL_AUTO_INC_Msk 0x100UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_CTRL_LOCK_Pos 31UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_CTRL_LOCK_Msk 0x80000000UL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.ROT_BLK_MAX */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_MAX_VALUE_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_MAX_VALUE_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.ROT_BLK_CFG */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.ROT_BLK_IDX */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_IDX_VALUE_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_IDX_VALUE_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.ROT_BLK_PC */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_PC_PC_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_PC_PC_Msk 0xFUL
/* SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC.ROT_BLK_LUT */
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR0_Pos 0UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR0_Msk 0x7UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR1_Pos 4UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR1_Msk 0x70UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR2_Pos 8UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR2_Msk 0x700UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR3_Pos 12UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR3_Msk 0x7000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR4_Pos 16UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR4_Msk 0x70000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR5_Pos 20UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR5_Msk 0x700000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR6_Pos 24UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR6_Msk 0x7000000UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR7_Pos 28UL
#define SMIF_CACHE_BLOCK_CACHEBLK_AHB_MPC_ROT_BLK_LUT_ATTR7_Msk 0x70000000UL


/* SMIF_CACHE_BLOCK.HWPARAMS */
#define SMIF_CACHE_BLOCK_HWPARAMS_ENDIANNESS_Pos 0UL
#define SMIF_CACHE_BLOCK_HWPARAMS_ENDIANNESS_Msk 0x3UL
#define SMIF_CACHE_BLOCK_HWPARAMS_XOM_Pos       2UL
#define SMIF_CACHE_BLOCK_HWPARAMS_XOM_Msk       0x4UL
#define SMIF_CACHE_BLOCK_HWPARAMS_SNAPSHOTTING_Pos 3UL
#define SMIF_CACHE_BLOCK_HWPARAMS_SNAPSHOTTING_Msk 0x8UL
#define SMIF_CACHE_BLOCK_HWPARAMS_CACHE_MEM_SIZE_Pos 8UL
#define SMIF_CACHE_BLOCK_HWPARAMS_CACHE_MEM_SIZE_Msk 0xFF00UL
#define SMIF_CACHE_BLOCK_HWPARAMS_MASTER_ID_Pos 16UL
#define SMIF_CACHE_BLOCK_HWPARAMS_MASTER_ID_Msk 0xFF0000UL
#define SMIF_CACHE_BLOCK_HWPARAMS_DIS_CACHE_EN_MAINT_Pos 24UL
#define SMIF_CACHE_BLOCK_HWPARAMS_DIS_CACHE_EN_MAINT_Msk 0x1000000UL
#define SMIF_CACHE_BLOCK_HWPARAMS_DIS_CACHE_DIS_MAINT_Pos 25UL
#define SMIF_CACHE_BLOCK_HWPARAMS_DIS_CACHE_DIS_MAINT_Msk 0x2000000UL
#define SMIF_CACHE_BLOCK_HWPARAMS_DIS_PWR_DOWN_MAINT_Pos 26UL
#define SMIF_CACHE_BLOCK_HWPARAMS_DIS_PWR_DOWN_MAINT_Msk 0x4000000UL
#define SMIF_CACHE_BLOCK_HWPARAMS_POWER_ON_ENABLE_Pos 27UL
#define SMIF_CACHE_BLOCK_HWPARAMS_POWER_ON_ENABLE_Msk 0x8000000UL
#define SMIF_CACHE_BLOCK_HWPARAMS_APB_VIOLATION_RESP_Pos 30UL
#define SMIF_CACHE_BLOCK_HWPARAMS_APB_VIOLATION_RESP_Msk 0x40000000UL
#define SMIF_CACHE_BLOCK_HWPARAMS_AHB_VIOLATION_RESP_Pos 31UL
#define SMIF_CACHE_BLOCK_HWPARAMS_AHB_VIOLATION_RESP_Msk 0x80000000UL
/* SMIF_CACHE_BLOCK.CTRL */
#define SMIF_CACHE_BLOCK_CTRL_ENABLE_Pos        0UL
#define SMIF_CACHE_BLOCK_CTRL_ENABLE_Msk        0x1UL
#define SMIF_CACHE_BLOCK_CTRL_FORCE_WT_Pos      1UL
#define SMIF_CACHE_BLOCK_CTRL_FORCE_WT_Msk      0x2UL
#define SMIF_CACHE_BLOCK_CTRL_DENY_POWERDOWN_Pos 8UL
#define SMIF_CACHE_BLOCK_CTRL_DENY_POWERDOWN_Msk 0x100UL
#define SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_ENABLE_READ_Pos 16UL
#define SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_ENABLE_READ_Msk 0x10000UL
#define SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_MAINT_LINES_Pos 17UL
#define SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_MAINT_LINES_Msk 0x20000UL
#define SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_NSECSTAT_Pos 18UL
#define SMIF_CACHE_BLOCK_CTRL_ALLOW_NSEC_NSECSTAT_Msk 0x40000UL
/* SMIF_CACHE_BLOCK.NSEC_ACCESS */
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_CACHE_ENABLED_Pos 0UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_CACHE_ENABLED_Msk 0x1UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_NSEC_ENABLE_READ_ALLOWED_Pos 16UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_NSEC_ENABLE_READ_ALLOWED_Msk 0x10000UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_NSEC_MAINT_LINES_ALLOWED_Pos 17UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_NSEC_MAINT_LINES_ALLOWED_Msk 0x20000UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_NSEC_NSECSTAT_ALLOWED_Pos 18UL
#define SMIF_CACHE_BLOCK_NSEC_ACCESS_NSEC_NSECSTAT_ALLOWED_Msk 0x40000UL
/* SMIF_CACHE_BLOCK.MAINT_CTRL_ALL */
#define SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_CLEAN_ALL_Pos 0UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_CLEAN_ALL_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_INVALIDATE_ALL_Pos 1UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_ALL_TRIG_INVALIDATE_ALL_Msk 0x2UL
/* SMIF_CACHE_BLOCK.MAINT_CTRL_LINES */
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_CLEAN_Pos 0UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_CLEAN_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_INVALIDATE_Pos 1UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_TRIG_INVALIDATE_Msk 0x2UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY_Pos 2UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_SECURITY_Msk 0x4UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_ADDR_Pos 5UL
#define SMIF_CACHE_BLOCK_MAINT_CTRL_LINES_ADDR_Msk 0xFFFFFFE0UL
/* SMIF_CACHE_BLOCK.MAINT_STATUS */
#define SMIF_CACHE_BLOCK_MAINT_STATUS_CACHE_ENABLED_Pos 0UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_CACHE_ENABLED_Msk 0x1UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_EN_DIS_Pos 1UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_EN_DIS_Msk 0x2UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Pos 2UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_MAINT_Msk 0x4UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_PWR_MAINT_Pos 3UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_ONGOING_PWR_MAINT_Msk 0x8UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_CACHE_IS_CLEAN_Pos 8UL
#define SMIF_CACHE_BLOCK_MAINT_STATUS_CACHE_IS_CLEAN_Msk 0x100UL
/* SMIF_CACHE_BLOCK.SECIRQSTAT */
#define SMIF_CACHE_BLOCK_SECIRQSTAT_ENABLE_DONE_Pos 0UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_ENABLE_DONE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_DISABLE_DONE_Pos 1UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_DISABLE_DONE_Msk 0x2UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_MAINT_DONE_Pos 2UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_MAINT_DONE_Msk 0x4UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_MAINT_IGNORED_Pos 3UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_MAINT_IGNORED_Msk 0x8UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_TR_ERR_Pos  4UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_TR_ERR_Msk  0x10UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_SECURE_CNT_SAT_Pos 5UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_SECURE_CNT_SAT_Msk 0x20UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_NSECURE_CNT_SAT_Pos 6UL
#define SMIF_CACHE_BLOCK_SECIRQSTAT_NSECURE_CNT_SAT_Msk 0x40UL
/* SMIF_CACHE_BLOCK.SECIRQSCLR */
#define SMIF_CACHE_BLOCK_SECIRQSCLR_ENABLE_DONE_Pos 0UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_ENABLE_DONE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_DISABLE_DONE_Pos 1UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_DISABLE_DONE_Msk 0x2UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_MAINT_DONE_Pos 2UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_MAINT_DONE_Msk 0x4UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_MAINT_IGNORED_Pos 3UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_MAINT_IGNORED_Msk 0x8UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_TR_ERR_Pos  4UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_TR_ERR_Msk  0x10UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_SECURE_CNT_SAT_Pos 5UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_SECURE_CNT_SAT_Msk 0x20UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_NSECURE_CNT_SAT_Pos 6UL
#define SMIF_CACHE_BLOCK_SECIRQSCLR_NSECURE_CNT_SAT_Msk 0x40UL
/* SMIF_CACHE_BLOCK.SECIRQEN */
#define SMIF_CACHE_BLOCK_SECIRQEN_ENABLE_DONE_Pos 0UL
#define SMIF_CACHE_BLOCK_SECIRQEN_ENABLE_DONE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_SECIRQEN_DISABLE_DONE_Pos 1UL
#define SMIF_CACHE_BLOCK_SECIRQEN_DISABLE_DONE_Msk 0x2UL
#define SMIF_CACHE_BLOCK_SECIRQEN_MAINT_DONE_Pos 2UL
#define SMIF_CACHE_BLOCK_SECIRQEN_MAINT_DONE_Msk 0x4UL
#define SMIF_CACHE_BLOCK_SECIRQEN_MAINT_IGNORED_Pos 3UL
#define SMIF_CACHE_BLOCK_SECIRQEN_MAINT_IGNORED_Msk 0x8UL
#define SMIF_CACHE_BLOCK_SECIRQEN_TR_ERR_Pos    4UL
#define SMIF_CACHE_BLOCK_SECIRQEN_TR_ERR_Msk    0x10UL
#define SMIF_CACHE_BLOCK_SECIRQEN_SECURE_CNT_SAT_Pos 5UL
#define SMIF_CACHE_BLOCK_SECIRQEN_SECURE_CNT_SAT_Msk 0x20UL
#define SMIF_CACHE_BLOCK_SECIRQEN_NSECURE_CNT_SAT_Pos 6UL
#define SMIF_CACHE_BLOCK_SECIRQEN_NSECURE_CNT_SAT_Msk 0x40UL
/* SMIF_CACHE_BLOCK.SECIRQINFO1 */
#define SMIF_CACHE_BLOCK_SECIRQINFO1_ADDR_Pos   0UL
#define SMIF_CACHE_BLOCK_SECIRQINFO1_ADDR_Msk   0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.SECIRQINFO2 */
#define SMIF_CACHE_BLOCK_SECIRQINFO2_MASTER_Pos 0UL
#define SMIF_CACHE_BLOCK_SECIRQINFO2_MASTER_Msk 0xFFUL
#define SMIF_CACHE_BLOCK_SECIRQINFO2_ERROR_SRC_Pos 8UL
#define SMIF_CACHE_BLOCK_SECIRQINFO2_ERROR_SRC_Msk 0x300UL
/* SMIF_CACHE_BLOCK.NSECIRQSTAT */
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_MAINT_DONE_Pos 2UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_MAINT_DONE_Msk 0x4UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_MAINT_IGNORED_Pos 3UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_MAINT_IGNORED_Msk 0x8UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_TR_ERR_Pos 4UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_TR_ERR_Msk 0x10UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_NSECURE_CNT_SAT_Pos 6UL
#define SMIF_CACHE_BLOCK_NSECIRQSTAT_NSECURE_CNT_SAT_Msk 0x40UL
/* SMIF_CACHE_BLOCK.NSECIRQSCLR */
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_MAINT_DONE_Pos 2UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_MAINT_DONE_Msk 0x4UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_MAINT_IGNORED_Pos 3UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_MAINT_IGNORED_Msk 0x8UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_TR_ERR_Pos 4UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_TR_ERR_Msk 0x10UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_NSECURE_CNT_SAT_Pos 6UL
#define SMIF_CACHE_BLOCK_NSECIRQSCLR_NSECURE_CNT_SAT_Msk 0x40UL
/* SMIF_CACHE_BLOCK.NSECIRQEN */
#define SMIF_CACHE_BLOCK_NSECIRQEN_MAINT_DONE_Pos 2UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_MAINT_DONE_Msk 0x4UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_MAINT_IGNORED_Pos 3UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_MAINT_IGNORED_Msk 0x8UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_TR_ERR_Pos   4UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_TR_ERR_Msk   0x10UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_NSECURE_CNT_SAT_Pos 6UL
#define SMIF_CACHE_BLOCK_NSECIRQEN_NSECURE_CNT_SAT_Msk 0x40UL
/* SMIF_CACHE_BLOCK.NSECIRQINFO1 */
#define SMIF_CACHE_BLOCK_NSECIRQINFO1_ADDR_Pos  0UL
#define SMIF_CACHE_BLOCK_NSECIRQINFO1_ADDR_Msk  0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.NSECIRQINFO2 */
#define SMIF_CACHE_BLOCK_NSECIRQINFO2_MASTER_Pos 0UL
#define SMIF_CACHE_BLOCK_NSECIRQINFO2_MASTER_Msk 0xFFUL
#define SMIF_CACHE_BLOCK_NSECIRQINFO2_ERROR_SRC_Pos 8UL
#define SMIF_CACHE_BLOCK_NSECIRQINFO2_ERROR_SRC_Msk 0x300UL
/* SMIF_CACHE_BLOCK.SECHIT */
#define SMIF_CACHE_BLOCK_SECHIT_SECHITCNT_Pos   0UL
#define SMIF_CACHE_BLOCK_SECHIT_SECHITCNT_Msk   0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.SECMISS */
#define SMIF_CACHE_BLOCK_SECMISS_SECMISSCNT_Pos 0UL
#define SMIF_CACHE_BLOCK_SECMISS_SECMISSCNT_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.SECSTATCTRL */
#define SMIF_CACHE_BLOCK_SECSTATCTRL_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_SECSTATCTRL_ENABLE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_SECSTATCTRL_RESET_Pos  1UL
#define SMIF_CACHE_BLOCK_SECSTATCTRL_RESET_Msk  0x2UL
/* SMIF_CACHE_BLOCK.NSECHIT */
#define SMIF_CACHE_BLOCK_NSECHIT_NSECHITCNT_Pos 0UL
#define SMIF_CACHE_BLOCK_NSECHIT_NSECHITCNT_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.NSECMISS */
#define SMIF_CACHE_BLOCK_NSECMISS_NSECMISSCNT_Pos 0UL
#define SMIF_CACHE_BLOCK_NSECMISS_NSECMISSCNT_Msk 0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.NSECSTATCTRL */
#define SMIF_CACHE_BLOCK_NSECSTATCTRL_ENABLE_Pos 0UL
#define SMIF_CACHE_BLOCK_NSECSTATCTRL_ENABLE_Msk 0x1UL
#define SMIF_CACHE_BLOCK_NSECSTATCTRL_RESET_Pos 1UL
#define SMIF_CACHE_BLOCK_NSECSTATCTRL_RESET_Msk 0x2UL
/* SMIF_CACHE_BLOCK.PMSVR0 */
#define SMIF_CACHE_BLOCK_PMSVR0_SHCS_Pos        0UL
#define SMIF_CACHE_BLOCK_PMSVR0_SHCS_Msk        0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PMSVR1 */
#define SMIF_CACHE_BLOCK_PMSVR1_SMCS_Pos        0UL
#define SMIF_CACHE_BLOCK_PMSVR1_SMCS_Msk        0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PMSVR2 */
#define SMIF_CACHE_BLOCK_PMSVR2_NSHCS_Pos       0UL
#define SMIF_CACHE_BLOCK_PMSVR2_NSHCS_Msk       0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PMSVR3 */
#define SMIF_CACHE_BLOCK_PMSVR3_NSMCS_Pos       0UL
#define SMIF_CACHE_BLOCK_PMSVR3_NSMCS_Msk       0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PMSSSR */
#define SMIF_CACHE_BLOCK_PMSSSR_NC_Pos          0UL
#define SMIF_CACHE_BLOCK_PMSSSR_NC_Msk          0x1UL
/* SMIF_CACHE_BLOCK.PMSSCR */
#define SMIF_CACHE_BLOCK_PMSSCR_SS_Pos          0UL
#define SMIF_CACHE_BLOCK_PMSSCR_SS_Msk          0x1UL
/* SMIF_CACHE_BLOCK.PMSSRR */
#define SMIF_CACHE_BLOCK_PMSSRR_RP_SHC_Pos      0UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_SHC_Msk      0x1UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_SMC_Pos      1UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_SMC_Msk      0x2UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_NSHC_Pos     2UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_NSHC_Msk     0x4UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_NSMC_Pos     3UL
#define SMIF_CACHE_BLOCK_PMSSRR_RP_NSMC_Msk     0x8UL
/* SMIF_CACHE_BLOCK.PIDR4 */
#define SMIF_CACHE_BLOCK_PIDR4_DES_2_Pos        0UL
#define SMIF_CACHE_BLOCK_PIDR4_DES_2_Msk        0xFUL
#define SMIF_CACHE_BLOCK_PIDR4_SIZE_Pos         4UL
#define SMIF_CACHE_BLOCK_PIDR4_SIZE_Msk         0xF0UL
/* SMIF_CACHE_BLOCK.PIDR5 */
#define SMIF_CACHE_BLOCK_PIDR5_RSVD_Pos         0UL
#define SMIF_CACHE_BLOCK_PIDR5_RSVD_Msk         0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PIDR6 */
#define SMIF_CACHE_BLOCK_PIDR6_RSVD_Pos         0UL
#define SMIF_CACHE_BLOCK_PIDR6_RSVD_Msk         0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PIDR7 */
#define SMIF_CACHE_BLOCK_PIDR7_RSVD_Pos         0UL
#define SMIF_CACHE_BLOCK_PIDR7_RSVD_Msk         0xFFFFFFFFUL
/* SMIF_CACHE_BLOCK.PIDR0 */
#define SMIF_CACHE_BLOCK_PIDR0_PART_0_Pos       0UL
#define SMIF_CACHE_BLOCK_PIDR0_PART_0_Msk       0xFFUL
#define SMIF_CACHE_BLOCK_PIDR0_RES0_0_Pos       8UL
#define SMIF_CACHE_BLOCK_PIDR0_RES0_0_Msk       0xFFFFFF00UL
/* SMIF_CACHE_BLOCK.PIDR1 */
#define SMIF_CACHE_BLOCK_PIDR1_PART_1_Pos       0UL
#define SMIF_CACHE_BLOCK_PIDR1_PART_1_Msk       0xFUL
#define SMIF_CACHE_BLOCK_PIDR1_DES_0_Pos        4UL
#define SMIF_CACHE_BLOCK_PIDR1_DES_0_Msk        0xF0UL
/* SMIF_CACHE_BLOCK.PIDR2 */
#define SMIF_CACHE_BLOCK_PIDR2_DES_1_Pos        0UL
#define SMIF_CACHE_BLOCK_PIDR2_DES_1_Msk        0x7UL
#define SMIF_CACHE_BLOCK_PIDR2_JEDEC_Pos        3UL
#define SMIF_CACHE_BLOCK_PIDR2_JEDEC_Msk        0x8UL
#define SMIF_CACHE_BLOCK_PIDR2_REVISION_Pos     4UL
#define SMIF_CACHE_BLOCK_PIDR2_REVISION_Msk     0xF0UL
#define SMIF_CACHE_BLOCK_PIDR2_RES0_0_Pos       8UL
#define SMIF_CACHE_BLOCK_PIDR2_RES0_0_Msk       0xFFFFFF00UL
/* SMIF_CACHE_BLOCK.PIDR3 */
#define SMIF_CACHE_BLOCK_PIDR3_CMOD_Pos         0UL
#define SMIF_CACHE_BLOCK_PIDR3_CMOD_Msk         0xFUL
#define SMIF_CACHE_BLOCK_PIDR3_REVAND_Pos       4UL
#define SMIF_CACHE_BLOCK_PIDR3_REVAND_Msk       0xF0UL
/* SMIF_CACHE_BLOCK.CIDR0 */
#define SMIF_CACHE_BLOCK_CIDR0_PRMBL_0_Pos      0UL
#define SMIF_CACHE_BLOCK_CIDR0_PRMBL_0_Msk      0xFFUL
/* SMIF_CACHE_BLOCK.CIDR1 */
#define SMIF_CACHE_BLOCK_CIDR1_PRMBL_1_Pos      0UL
#define SMIF_CACHE_BLOCK_CIDR1_PRMBL_1_Msk      0xFUL
#define SMIF_CACHE_BLOCK_CIDR1_CLASS_Pos        4UL
#define SMIF_CACHE_BLOCK_CIDR1_CLASS_Msk        0xF0UL
/* SMIF_CACHE_BLOCK.CIDR2 */
#define SMIF_CACHE_BLOCK_CIDR2_PRMBL_2_Pos      0UL
#define SMIF_CACHE_BLOCK_CIDR2_PRMBL_2_Msk      0xFFUL
#define SMIF_CACHE_BLOCK_CIDR2_RES0_0_Pos       8UL
#define SMIF_CACHE_BLOCK_CIDR2_RES0_0_Msk       0xFFFFFF00UL
/* SMIF_CACHE_BLOCK.CIDR3 */
#define SMIF_CACHE_BLOCK_CIDR3_PRMBL_3_Pos      0UL
#define SMIF_CACHE_BLOCK_CIDR3_PRMBL_3_Msk      0xFFUL


/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_CMD */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_CMD_START_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_CMD_START_Msk 0x1UL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_ADDR */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_ADDR_ADDR_Pos 8UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_ADDR_ADDR_Msk 0xFFFFFF00UL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_MASK */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_MASK_MASK_Pos 8UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_MASK_MASK_Msk 0xFFFFFF00UL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_SUBREGION */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_SUBREGION_SUBREGION_DISABLE_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_SUBREGION_SUBREGION_DISABLE_Msk 0xFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_INPUT0 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_LSB_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_LSB_Msk 0xFUL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_MSB_Pos 4UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT0_INPUT_MSB_Msk 0xFFFFFFF0UL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_INPUT1 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT1_INPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT1_INPUT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_INPUT2 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT2_INPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT2_INPUT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_INPUT3 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT3_INPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_INPUT3_INPUT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_KEY0 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY0_KEY_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY0_KEY_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_KEY1 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY1_KEY_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY1_KEY_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_KEY2 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY2_KEY_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY2_KEY_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_KEY3 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY3_KEY_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_KEY3_KEY_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_OUTPUT0 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT0_OUTPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT0_OUTPUT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_OUTPUT1 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT1_OUTPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT1_OUTPUT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_OUTPUT2 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT2_OUTPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT2_OUTPUT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_CRYPTO.CRYPTO_OUTPUT3 */
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT3_OUTPUT_Pos 0UL
#define SMIF_CORE_SMIF_CRYPTO_CRYPTO_OUTPUT3_OUTPUT_Msk 0xFFFFFFFFUL


/* SMIF_CORE_DEVICE.CTL */
#define SMIF_CORE_DEVICE_CTL_WR_EN_Pos          0UL
#define SMIF_CORE_DEVICE_CTL_WR_EN_Msk          0x1UL
#define SMIF_CORE_DEVICE_CTL_CRYPTO_EN_Pos      4UL
#define SMIF_CORE_DEVICE_CTL_CRYPTO_EN_Msk      0x10UL
#define SMIF_CORE_DEVICE_CTL_DATA_SEL_Pos       8UL
#define SMIF_CORE_DEVICE_CTL_DATA_SEL_Msk       0x300UL
#define SMIF_CORE_DEVICE_CTL_MERGE_TIMEOUT_Pos  12UL
#define SMIF_CORE_DEVICE_CTL_MERGE_TIMEOUT_Msk  0x7000UL
#define SMIF_CORE_DEVICE_CTL_MERGE_EN_Pos       15UL
#define SMIF_CORE_DEVICE_CTL_MERGE_EN_Msk       0x8000UL
#define SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_Pos  16UL
#define SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_Msk  0x3FFF0000UL
#define SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_EN_Pos 30UL
#define SMIF_CORE_DEVICE_CTL_TOTAL_TIMEOUT_EN_Msk 0x40000000UL
#define SMIF_CORE_DEVICE_CTL_ENABLED_Pos        31UL
#define SMIF_CORE_DEVICE_CTL_ENABLED_Msk        0x80000000UL
/* SMIF_CORE_DEVICE.ADDR */
#define SMIF_CORE_DEVICE_ADDR_ADDR_Pos          8UL
#define SMIF_CORE_DEVICE_ADDR_ADDR_Msk          0xFFFFFF00UL
/* SMIF_CORE_DEVICE.MASK */
#define SMIF_CORE_DEVICE_MASK_MASK_Pos          8UL
#define SMIF_CORE_DEVICE_MASK_MASK_Msk          0xFFFFFF00UL
/* SMIF_CORE_DEVICE.ADDR_CTL */
#define SMIF_CORE_DEVICE_ADDR_CTL_SIZE3_Pos     0UL
#define SMIF_CORE_DEVICE_ADDR_CTL_SIZE3_Msk     0x7UL
#define SMIF_CORE_DEVICE_ADDR_CTL_DIV2_Pos      8UL
#define SMIF_CORE_DEVICE_ADDR_CTL_DIV2_Msk      0x100UL
/* SMIF_CORE_DEVICE.RX_CAPTURE_CONFIG */
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_NEG_SDL_TAP_SEL_Pos 0UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_NEG_SDL_TAP_SEL_Msk 0xFUL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_POS_SDL_TAP_SEL_Pos 4UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_POS_SDL_TAP_SEL_Msk 0xF0UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_FW_CALIBRATION_MODE_Pos 8UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_FW_CALIBRATION_MODE_Msk 0x100UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_SDR_PIPELINE_NEG_DAT_Pos 16UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_SDR_PIPELINE_NEG_DAT_Msk 0x10000UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_SDR_SWAP_BYTES_Pos 17UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_SDR_SWAP_BYTES_Msk 0x20000UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_DDR_PIPELINE_POS_DAT_Pos 24UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_DDR_PIPELINE_POS_DAT_Msk 0x1000000UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_DDR_SWAP_BYTES_Pos 25UL
#define SMIF_CORE_DEVICE_RX_CAPTURE_CONFIG_DDR_SWAP_BYTES_Msk 0x2000000UL
/* SMIF_CORE_DEVICE.RD_STATUS */
#define SMIF_CORE_DEVICE_RD_STATUS_FS_STATUS_Pos 0UL
#define SMIF_CORE_DEVICE_RD_STATUS_FS_STATUS_Msk 0xFFUL
/* SMIF_CORE_DEVICE.RD_CMD_CTL */
#define SMIF_CORE_DEVICE_RD_CMD_CTL_CODE_Pos    0UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_CODE_Msk    0xFFUL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_CODEH_Pos   8UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_CODEH_Msk   0xFF00UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_WIDTH_Pos   16UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_WIDTH_Msk   0x30000UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_DDR_MODE_Msk 0x40000UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_PRESENT2_Pos 30UL
#define SMIF_CORE_DEVICE_RD_CMD_CTL_PRESENT2_Msk 0xC0000000UL
/* SMIF_CORE_DEVICE.RD_ADDR_CTL */
#define SMIF_CORE_DEVICE_RD_ADDR_CTL_WIDTH_Pos  16UL
#define SMIF_CORE_DEVICE_RD_ADDR_CTL_WIDTH_Msk  0x30000UL
#define SMIF_CORE_DEVICE_RD_ADDR_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_RD_ADDR_CTL_DDR_MODE_Msk 0x40000UL
/* SMIF_CORE_DEVICE.RD_MODE_CTL */
#define SMIF_CORE_DEVICE_RD_MODE_CTL_CODE_Pos   0UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_CODE_Msk   0xFFUL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_CODEH_Pos  8UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_CODEH_Msk  0xFF00UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_WIDTH_Pos  16UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_WIDTH_Msk  0x30000UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_DDR_MODE_Msk 0x40000UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_PRESENT2_Pos 30UL
#define SMIF_CORE_DEVICE_RD_MODE_CTL_PRESENT2_Msk 0xC0000000UL
/* SMIF_CORE_DEVICE.RD_DUMMY_CTL */
#define SMIF_CORE_DEVICE_RD_DUMMY_CTL_SIZE5_Pos 0UL
#define SMIF_CORE_DEVICE_RD_DUMMY_CTL_SIZE5_Msk 0x1FUL
#define SMIF_CORE_DEVICE_RD_DUMMY_CTL_PRESENT2_Pos 30UL
#define SMIF_CORE_DEVICE_RD_DUMMY_CTL_PRESENT2_Msk 0xC0000000UL
/* SMIF_CORE_DEVICE.RD_DATA_CTL */
#define SMIF_CORE_DEVICE_RD_DATA_CTL_WIDTH_Pos  16UL
#define SMIF_CORE_DEVICE_RD_DATA_CTL_WIDTH_Msk  0x30000UL
#define SMIF_CORE_DEVICE_RD_DATA_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_RD_DATA_CTL_DDR_MODE_Msk 0x40000UL
/* SMIF_CORE_DEVICE.RD_CRC_CTL */
#define SMIF_CORE_DEVICE_RD_CRC_CTL_STATUS_CHECK_MASK_Pos 0UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_STATUS_CHECK_MASK_Msk 0xFFUL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_STATUS_ERROR_POL_Pos 8UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_STATUS_ERROR_POL_Msk 0xFF00UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_DATA_CRC_INPUT_SIZE_Pos 16UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_DATA_CRC_INPUT_SIZE_Msk 0xFF0000UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_WIDTH_Pos 24UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_WIDTH_Msk 0x3000000UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Pos 26UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Msk 0x4000000UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_INPUT_Pos 27UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_INPUT_Msk 0x8000000UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_DATA_CRC_CHECK_Pos 28UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_DATA_CRC_CHECK_Msk 0x10000000UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_PRESENT_Pos 30UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_CMD_ADDR_CRC_PRESENT_Msk 0x40000000UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_DATA_CRC_PRESENT_Pos 31UL
#define SMIF_CORE_DEVICE_RD_CRC_CTL_DATA_CRC_PRESENT_Msk 0x80000000UL
/* SMIF_CORE_DEVICE.RD_BOUND_CTL */
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SIZE5_Pos 0UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SIZE5_Msk 0x1FUL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Pos 16UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_SIZE_Msk 0x30000UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Pos 20UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SUB_PAGE_NR_Msk 0x300000UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Pos 28UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_SUBSEQ_BOUND_EN_Msk 0x10000000UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_PRESENT_Pos 31UL
#define SMIF_CORE_DEVICE_RD_BOUND_CTL_PRESENT_Msk 0x80000000UL
/* SMIF_CORE_DEVICE.WR_CMD_CTL */
#define SMIF_CORE_DEVICE_WR_CMD_CTL_CODE_Pos    0UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_CODE_Msk    0xFFUL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_CODEH_Pos   8UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_CODEH_Msk   0xFF00UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_WIDTH_Pos   16UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_WIDTH_Msk   0x30000UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_DDR_MODE_Msk 0x40000UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_PRESENT2_Pos 30UL
#define SMIF_CORE_DEVICE_WR_CMD_CTL_PRESENT2_Msk 0xC0000000UL
/* SMIF_CORE_DEVICE.WR_ADDR_CTL */
#define SMIF_CORE_DEVICE_WR_ADDR_CTL_WIDTH_Pos  16UL
#define SMIF_CORE_DEVICE_WR_ADDR_CTL_WIDTH_Msk  0x30000UL
#define SMIF_CORE_DEVICE_WR_ADDR_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_WR_ADDR_CTL_DDR_MODE_Msk 0x40000UL
/* SMIF_CORE_DEVICE.WR_MODE_CTL */
#define SMIF_CORE_DEVICE_WR_MODE_CTL_CODE_Pos   0UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_CODE_Msk   0xFFUL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_CODEH_Pos  8UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_CODEH_Msk  0xFF00UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_WIDTH_Pos  16UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_WIDTH_Msk  0x30000UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_DDR_MODE_Msk 0x40000UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_PRESENT2_Pos 30UL
#define SMIF_CORE_DEVICE_WR_MODE_CTL_PRESENT2_Msk 0xC0000000UL
/* SMIF_CORE_DEVICE.WR_DUMMY_CTL */
#define SMIF_CORE_DEVICE_WR_DUMMY_CTL_SIZE5_Pos 0UL
#define SMIF_CORE_DEVICE_WR_DUMMY_CTL_SIZE5_Msk 0x1FUL
#define SMIF_CORE_DEVICE_WR_DUMMY_CTL_RWDS_EN_Pos 17UL
#define SMIF_CORE_DEVICE_WR_DUMMY_CTL_RWDS_EN_Msk 0x20000UL
#define SMIF_CORE_DEVICE_WR_DUMMY_CTL_PRESENT2_Pos 30UL
#define SMIF_CORE_DEVICE_WR_DUMMY_CTL_PRESENT2_Msk 0xC0000000UL
/* SMIF_CORE_DEVICE.WR_DATA_CTL */
#define SMIF_CORE_DEVICE_WR_DATA_CTL_WIDTH_Pos  16UL
#define SMIF_CORE_DEVICE_WR_DATA_CTL_WIDTH_Msk  0x30000UL
#define SMIF_CORE_DEVICE_WR_DATA_CTL_DDR_MODE_Pos 18UL
#define SMIF_CORE_DEVICE_WR_DATA_CTL_DDR_MODE_Msk 0x40000UL
/* SMIF_CORE_DEVICE.WR_CRC_CTL */
#define SMIF_CORE_DEVICE_WR_CRC_CTL_DATA_CRC_INPUT_SIZE_Pos 16UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_DATA_CRC_INPUT_SIZE_Msk 0xFF0000UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_WIDTH_Pos 24UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_WIDTH_Msk 0x3000000UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Pos 26UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_DDR_MODE_Msk 0x4000000UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_INPUT_Pos 27UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_INPUT_Msk 0x8000000UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_PRESENT_Pos 30UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_CMD_ADDR_CRC_PRESENT_Msk 0x40000000UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_DATA_CRC_PRESENT_Pos 31UL
#define SMIF_CORE_DEVICE_WR_CRC_CTL_DATA_CRC_PRESENT_Msk 0x80000000UL
/* SMIF_CORE_DEVICE.HB_FW_DEL_TAP_SEL_0 */
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT0_TAP_SEL_POS_Pos 0UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT0_TAP_SEL_POS_Msk 0xFUL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT0_TAP_SEL_NEG_Pos 4UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT0_TAP_SEL_NEG_Msk 0xF0UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT1_TAP_SEL_POS_Pos 8UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT1_TAP_SEL_POS_Msk 0xF00UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT1_TAP_SEL_NEG_Pos 12UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT1_TAP_SEL_NEG_Msk 0xF000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT2_TAP_SEL_POS_Pos 16UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT2_TAP_SEL_POS_Msk 0xF0000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT2_TAP_SEL_NEG_Pos 20UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT2_TAP_SEL_NEG_Msk 0xF00000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT3_TAP_SEL_POS_Pos 24UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT3_TAP_SEL_POS_Msk 0xF000000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT3_TAP_SEL_NEG_Pos 28UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_0_DATA_BIT3_TAP_SEL_NEG_Msk 0xF0000000UL
/* SMIF_CORE_DEVICE.HB_FW_DEL_TAP_SEL_1 */
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT4_TAP_SEL_POS_Pos 0UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT4_TAP_SEL_POS_Msk 0xFUL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT4_TAP_SEL_NEG_Pos 4UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT4_TAP_SEL_NEG_Msk 0xF0UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT5_TAP_SEL_POS_Pos 8UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT5_TAP_SEL_POS_Msk 0xF00UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT5_TAP_SEL_NEG_Pos 12UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT5_TAP_SEL_NEG_Msk 0xF000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT6_TAP_SEL_POS_Pos 16UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT6_TAP_SEL_POS_Msk 0xF0000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT6_TAP_SEL_NEG_Pos 20UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT6_TAP_SEL_NEG_Msk 0xF00000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT7_TAP_SEL_POS_Pos 24UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT7_TAP_SEL_POS_Msk 0xF000000UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT7_TAP_SEL_NEG_Pos 28UL
#define SMIF_CORE_DEVICE_HB_FW_DEL_TAP_SEL_1_DATA_BIT7_TAP_SEL_NEG_Msk 0xF0000000UL


/* SMIF_CORE_AXI_MPC.CFG */
#define SMIF_CORE_AXI_MPC_CFG_RESPONSE_Pos      4UL
#define SMIF_CORE_AXI_MPC_CFG_RESPONSE_Msk      0x10UL
/* SMIF_CORE_AXI_MPC.CTRL */
#define SMIF_CORE_AXI_MPC_CTRL_AUTO_INC_Pos     8UL
#define SMIF_CORE_AXI_MPC_CTRL_AUTO_INC_Msk     0x100UL
#define SMIF_CORE_AXI_MPC_CTRL_LOCK_Pos         31UL
#define SMIF_CORE_AXI_MPC_CTRL_LOCK_Msk         0x80000000UL
/* SMIF_CORE_AXI_MPC.BLK_MAX */
#define SMIF_CORE_AXI_MPC_BLK_MAX_VALUE_Pos     0UL
#define SMIF_CORE_AXI_MPC_BLK_MAX_VALUE_Msk     0xFFFFFFFFUL
/* SMIF_CORE_AXI_MPC.BLK_CFG */
#define SMIF_CORE_AXI_MPC_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define SMIF_CORE_AXI_MPC_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define SMIF_CORE_AXI_MPC_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SMIF_CORE_AXI_MPC_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SMIF_CORE_AXI_MPC.BLK_IDX */
#define SMIF_CORE_AXI_MPC_BLK_IDX_VALUE_Pos     0UL
#define SMIF_CORE_AXI_MPC_BLK_IDX_VALUE_Msk     0xFFFFFFFFUL
/* SMIF_CORE_AXI_MPC.BLK_LUT */
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS0_Pos  0UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS0_Msk  0x1UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS1_Pos  1UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS1_Msk  0x2UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS2_Pos  2UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS2_Msk  0x4UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS3_Pos  3UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS3_Msk  0x8UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS4_Pos  4UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS4_Msk  0x10UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS5_Pos  5UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS5_Msk  0x20UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS6_Pos  6UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS6_Msk  0x40UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS7_Pos  7UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS7_Msk  0x80UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS8_Pos  8UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS8_Msk  0x100UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS9_Pos  9UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS9_Msk  0x200UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS10_Pos 10UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS10_Msk 0x400UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS11_Pos 11UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS11_Msk 0x800UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS12_Pos 12UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS12_Msk 0x1000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS13_Pos 13UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS13_Msk 0x2000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS14_Pos 14UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS14_Msk 0x4000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS15_Pos 15UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS15_Msk 0x8000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS16_Pos 16UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS16_Msk 0x10000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS17_Pos 17UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS17_Msk 0x20000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS18_Pos 18UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS18_Msk 0x40000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS19_Pos 19UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS19_Msk 0x80000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS20_Pos 20UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS20_Msk 0x100000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS21_Pos 21UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS21_Msk 0x200000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS22_Pos 22UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS22_Msk 0x400000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS23_Pos 23UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS23_Msk 0x800000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS24_Pos 24UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS24_Msk 0x1000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS25_Pos 25UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS25_Msk 0x2000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS26_Pos 26UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS26_Msk 0x4000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS27_Pos 27UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS27_Msk 0x8000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS28_Pos 28UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS28_Msk 0x10000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS29_Pos 29UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS29_Msk 0x20000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS30_Pos 30UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS30_Msk 0x40000000UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS31_Pos 31UL
#define SMIF_CORE_AXI_MPC_BLK_LUT_ATTR_NS31_Msk 0x80000000UL
/* SMIF_CORE_AXI_MPC.ROT_CTRL */
#define SMIF_CORE_AXI_MPC_ROT_CTRL_AUTO_INC_Pos 8UL
#define SMIF_CORE_AXI_MPC_ROT_CTRL_AUTO_INC_Msk 0x100UL
#define SMIF_CORE_AXI_MPC_ROT_CTRL_LOCK_Pos     31UL
#define SMIF_CORE_AXI_MPC_ROT_CTRL_LOCK_Msk     0x80000000UL
/* SMIF_CORE_AXI_MPC.ROT_BLK_MAX */
#define SMIF_CORE_AXI_MPC_ROT_BLK_MAX_VALUE_Pos 0UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_MAX_VALUE_Msk 0xFFFFFFFFUL
/* SMIF_CORE_AXI_MPC.ROT_BLK_CFG */
#define SMIF_CORE_AXI_MPC_ROT_BLK_CFG_BLOCK_SIZE_Pos 0UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_CFG_BLOCK_SIZE_Msk 0xFUL
#define SMIF_CORE_AXI_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Pos 31UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_CFG_INIT_IN_PROGRESS_Msk 0x80000000UL
/* SMIF_CORE_AXI_MPC.ROT_BLK_IDX */
#define SMIF_CORE_AXI_MPC_ROT_BLK_IDX_VALUE_Pos 0UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_IDX_VALUE_Msk 0xFFFFFFFFUL
/* SMIF_CORE_AXI_MPC.ROT_BLK_PC */
#define SMIF_CORE_AXI_MPC_ROT_BLK_PC_PC_Pos     0UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_PC_PC_Msk     0xFUL
/* SMIF_CORE_AXI_MPC.ROT_BLK_LUT */
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR0_Pos 0UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR0_Msk 0x7UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR1_Pos 4UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR1_Msk 0x70UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR2_Pos 8UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR2_Msk 0x700UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR3_Pos 12UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR3_Msk 0x7000UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR4_Pos 16UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR4_Msk 0x70000UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR5_Pos 20UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR5_Msk 0x700000UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR6_Pos 24UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR6_Msk 0x7000000UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR7_Pos 28UL
#define SMIF_CORE_AXI_MPC_ROT_BLK_LUT_ATTR7_Msk 0x70000000UL


/* SMIF_CORE_SMIF_HSIOM_SMIF_PRT.PORT_SEL0 */
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO0_SEL_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO0_SEL_Msk 0x1FUL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO1_SEL_Pos 8UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO1_SEL_Msk 0x1F00UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO2_SEL_Pos 16UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO2_SEL_Msk 0x1F0000UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO3_SEL_Pos 24UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL0_IO3_SEL_Msk 0x1F000000UL
/* SMIF_CORE_SMIF_HSIOM_SMIF_PRT.PORT_SEL1 */
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO4_SEL_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO4_SEL_Msk 0x1FUL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO5_SEL_Pos 8UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO5_SEL_Msk 0x1F00UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO6_SEL_Pos 16UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO6_SEL_Msk 0x1F0000UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO7_SEL_Pos 24UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_PRT_PORT_SEL1_IO7_SEL_Msk 0x1F000000UL


/* SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT.NONSECURE_MASK */
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE0_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE0_Msk 0x1UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE1_Pos 1UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE1_Msk 0x2UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE2_Pos 2UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE2_Msk 0x4UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE3_Pos 3UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE3_Msk 0x8UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE4_Pos 4UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE4_Msk 0x10UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE5_Pos 5UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE5_Msk 0x20UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE6_Pos 6UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE6_Msk 0x40UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE7_Pos 7UL
#define SMIF_CORE_SMIF_HSIOM_SMIF_SECURE_PRT_NONSECURE_MASK_NONSECURE7_Msk 0x80UL


/* SMIF_CORE_SMIF_HSIOM.AMUX_SPLIT_CTL */
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SL_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SL_Msk 0x1UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SR_Pos 1UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SR_Msk 0x2UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_S0_Pos 2UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_S0_Msk 0x4UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Pos 4UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Msk 0x10UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SR_Pos 5UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SR_Msk 0x20UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_S0_Pos 6UL
#define SMIF_CORE_SMIF_HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_S0_Msk 0x40UL
/* SMIF_CORE_SMIF_HSIOM.MONITOR_CTL_0 */
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_0_MONITOR_EN_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_0_MONITOR_EN_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_HSIOM.MONITOR_CTL_1 */
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_1_MONITOR_EN_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_1_MONITOR_EN_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_HSIOM.MONITOR_CTL_2 */
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_2_MONITOR_EN_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_2_MONITOR_EN_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_HSIOM.MONITOR_CTL_3 */
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_3_MONITOR_EN_Pos 0UL
#define SMIF_CORE_SMIF_HSIOM_MONITOR_CTL_3_MONITOR_EN_Msk 0xFFFFFFFFUL


/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.OUT */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_OUT7_Msk 0x80UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.OUT_CLR */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_CLR_OUT7_Msk 0x80UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.OUT_SET */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_SET_OUT7_Msk 0x80UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.OUT_INV */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_OUT_INV_OUT7_Msk 0x80UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.IN */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_IN7_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_FLT_IN_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_IN_FLT_IN_Msk 0x100UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.INTR */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_EDGE7_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_FLT_EDGE_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_FLT_EDGE_Msk 0x100UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN0_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN0_Msk 0x10000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN1_Pos 17UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN1_Msk 0x20000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN2_Pos 18UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN2_Msk 0x40000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN3_Pos 19UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN3_Msk 0x80000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN4_Pos 20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN4_Msk 0x100000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN5_Pos 21UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN5_Msk 0x200000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN6_Pos 22UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN6_Msk 0x400000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN7_Pos 23UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_IN_IN7_Msk 0x800000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_FLT_IN_IN_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_FLT_IN_IN_Msk 0x1000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.INTR_MASK */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_EDGE7_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_FLT_EDGE_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASK_FLT_EDGE_Msk 0x100UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.INTR_MASKED */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_EDGE7_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_FLT_EDGE_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_MASKED_FLT_EDGE_Msk 0x100UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.INTR_SET */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_EDGE7_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_FLT_EDGE_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_SET_FLT_EDGE_Msk 0x100UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.INTR_CFG */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE0_SEL_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE0_SEL_Msk 0x3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE1_SEL_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE1_SEL_Msk 0xCUL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE2_SEL_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE2_SEL_Msk 0x30UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE3_SEL_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE3_SEL_Msk 0xC0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE4_SEL_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE4_SEL_Msk 0x300UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE5_SEL_Pos 10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE5_SEL_Msk 0xC00UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE6_SEL_Pos 12UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE6_SEL_Msk 0x3000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE7_SEL_Pos 14UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_EDGE7_SEL_Msk 0xC000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_FLT_EDGE_SEL_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_FLT_EDGE_SEL_Msk 0x30000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_FLT_SEL_Pos 18UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_INTR_CFG_FLT_SEL_Msk 0x1C0000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE0_Msk 0x7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN0_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN0_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE1_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE1_Msk 0x70UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN1_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN1_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE2_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE2_Msk 0x700UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN2_Pos 11UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN2_Msk 0x800UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE3_Pos 12UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE3_Msk 0x7000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN3_Pos 15UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN3_Msk 0x8000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE4_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE4_Msk 0x70000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN4_Pos 19UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN4_Msk 0x80000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE5_Pos 20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE5_Msk 0x700000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN5_Pos 23UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN5_Msk 0x800000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE6_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE6_Msk 0x7000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN6_Pos 27UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN6_Msk 0x8000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE7_Pos 28UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_MODE7_Msk 0x70000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN7_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_EN7_Msk 0x80000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_IN */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL0_0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL0_0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL1_0_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL1_0_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL2_0_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL2_0_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL3_0_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL3_0_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL4_0_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL4_0_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL5_0_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL5_0_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL6_0_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL6_0_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL7_0_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_VTRIP_SEL7_0_Msk 0x80UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_OUT */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_SLOW7_Msk 0x80UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL0_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL0_Msk 0x30000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL1_Pos 18UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL1_Msk 0xC0000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL2_Pos 20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL2_Msk 0x300000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL3_Pos 22UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL3_Msk 0xC00000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL4_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL4_Msk 0x3000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL5_Pos 26UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL5_Msk 0xC000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL6_Pos 28UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL6_Msk 0x30000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL7_Pos 30UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT_DRIVE_SEL7_Msk 0xC0000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_SIO */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN01_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN01_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL01_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL01_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL01_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL01_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL01_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL01_Msk 0x18UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL01_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL01_Msk 0xE0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN23_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN23_Msk 0x100UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL23_Pos 9UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL23_Msk 0x200UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL23_Pos 10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL23_Msk 0x400UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL23_Pos 11UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL23_Msk 0x1800UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL23_Pos 13UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL23_Msk 0xE000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN45_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN45_Msk 0x10000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL45_Pos 17UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL45_Msk 0x20000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL45_Pos 18UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL45_Msk 0x40000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL45_Pos 19UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL45_Msk 0x180000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL45_Pos 21UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL45_Msk 0xE00000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN67_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREG_EN67_Msk 0x1000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL67_Pos 25UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_IBUF_SEL67_Msk 0x2000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL67_Pos 26UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VTRIP_SEL67_Msk 0x4000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL67_Pos 27UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VREF_SEL67_Msk 0x18000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL67_Pos 29UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SIO_VOH_SEL67_Msk 0xE0000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_IN_AUTOLVL */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL0_1_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL0_1_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL1_1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL1_1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL2_1_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL2_1_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL3_1_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL3_1_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL4_1_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL4_1_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL5_1_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL5_1_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL6_1_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL6_1_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL7_1_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_IN_AUTOLVL_VTRIP_SEL7_1_Msk 0x80UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_OUT2 */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM0_Msk 0x7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM1_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM1_Msk 0x38UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM2_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM2_Msk 0x1C0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM3_Pos 9UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM3_Msk 0xE00UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM4_Pos 12UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM4_Msk 0x7000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM5_Pos 15UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM5_Msk 0x38000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM6_Pos 18UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM6_Msk 0x1C0000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM7_Pos 21UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT2_DS_TRIM7_Msk 0xE00000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_SLEW_EXT */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW0_Msk 0x7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW1_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW1_Msk 0x70UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW2_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW2_Msk 0x700UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW3_Pos 12UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW3_Msk 0x7000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW4_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW4_Msk 0x70000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW5_Pos 20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW5_Msk 0x700000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW6_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW6_Msk 0x7000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW7_Pos 28UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_SLEW_EXT_SLEW7_Msk 0x70000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_DRIVE_EXT0 */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT0_Msk 0x1FUL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT1_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT1_Msk 0x1F00UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT2_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT2_Msk 0x1F0000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT3_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT0_DRIVE_SEL_EXT3_Msk 0x1F000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_DRIVE_EXT1 */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT4_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT4_Msk 0x1FUL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT5_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT5_Msk 0x1F00UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT6_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT6_Msk 0x1F0000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT7_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_DRIVE_EXT1_DRIVE_SEL_EXT7_Msk 0x1F000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_OUT3 */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT0_Msk 0xFUL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT1_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT1_Msk 0xF0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT2_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT2_Msk 0xF00UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT3_Pos 12UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT3_Msk 0xF000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT4_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT4_Msk 0xF0000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT5_Pos 20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT5_Msk 0xF00000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT6_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT6_Msk 0xF000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT7_Pos 28UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_OUT3_DRIVEMODE_EXT7_Msk 0xF0000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.CFG_RES */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG0_Msk 0xFUL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG1_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG1_Msk 0xF0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG2_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG2_Msk 0xF00UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG3_Pos 12UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG3_Msk 0xF000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG4_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG4_Msk 0xF0000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG5_Pos 20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG5_Msk 0xF00000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG6_Pos 24UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG6_Msk 0xF000000UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG7_Pos 28UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_CFG_RES_RESISTOR_CFG7_Msk 0xF0000000UL
/* SMIF_CORE_SMIF_GPIO_SMIF_PRT.MSC_ANA */
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA0_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA0_Msk 0x1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA1_Pos 1UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA1_Msk 0x2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA2_Pos 2UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA2_Msk 0x4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA3_Pos 3UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA3_Msk 0x8UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA4_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA4_Msk 0x10UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA5_Pos 5UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA5_Msk 0x20UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA6_Pos 6UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA6_Msk 0x40UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA7_Pos 7UL
#define SMIF_CORE_SMIF_GPIO_SMIF_PRT_MSC_ANA_DATA7_Msk 0x80UL


/* SMIF_CORE_SMIF_GPIO.SEC_INTR_CAUSE0 */
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE0_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE0_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.SEC_INTR_CAUSE1 */
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE1_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE1_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.SEC_INTR_CAUSE2 */
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE2_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE2_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.SEC_INTR_CAUSE3 */
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE3_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_SEC_INTR_CAUSE3_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.INTR_CAUSE0 */
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE0_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE0_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.INTR_CAUSE1 */
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE1_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE1_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.INTR_CAUSE2 */
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE2_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE2_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.INTR_CAUSE3 */
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE3_PORT_INT_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_INTR_CAUSE3_PORT_INT_Msk 0xFFFFFFFFUL
/* SMIF_CORE_SMIF_GPIO.VDD_ACTIVE */
#define SMIF_CORE_SMIF_GPIO_VDD_ACTIVE_VDDIO_ACTIVE_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_ACTIVE_VDDIO_ACTIVE_Msk 0xFFFFUL
#define SMIF_CORE_SMIF_GPIO_VDD_ACTIVE_VDDA_ACTIVE_Pos 30UL
#define SMIF_CORE_SMIF_GPIO_VDD_ACTIVE_VDDA_ACTIVE_Msk 0x40000000UL
#define SMIF_CORE_SMIF_GPIO_VDD_ACTIVE_VDDD_ACTIVE_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_VDD_ACTIVE_VDDD_ACTIVE_Msk 0x80000000UL
/* SMIF_CORE_SMIF_GPIO.VDD_INTR */
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_VDDIO_ACTIVE_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_VDDIO_ACTIVE_Msk 0xFFFFUL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_VDDA_ACTIVE_Pos 30UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_VDDA_ACTIVE_Msk 0x40000000UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_VDDD_ACTIVE_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_VDDD_ACTIVE_Msk 0x80000000UL
/* SMIF_CORE_SMIF_GPIO.VDD_INTR_MASK */
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASK_VDDIO_ACTIVE_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASK_VDDIO_ACTIVE_Msk 0xFFFFUL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASK_VDDA_ACTIVE_Pos 30UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASK_VDDA_ACTIVE_Msk 0x40000000UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASK_VDDD_ACTIVE_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASK_VDDD_ACTIVE_Msk 0x80000000UL
/* SMIF_CORE_SMIF_GPIO.VDD_INTR_MASKED */
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASKED_VDDIO_ACTIVE_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASKED_VDDIO_ACTIVE_Msk 0xFFFFUL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASKED_VDDA_ACTIVE_Pos 30UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASKED_VDDA_ACTIVE_Msk 0x40000000UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASKED_VDDD_ACTIVE_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_MASKED_VDDD_ACTIVE_Msk 0x80000000UL
/* SMIF_CORE_SMIF_GPIO.VDD_INTR_SET */
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_SET_VDDIO_ACTIVE_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_SET_VDDIO_ACTIVE_Msk 0xFFFFUL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_SET_VDDA_ACTIVE_Pos 30UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_SET_VDDA_ACTIVE_Msk 0x40000000UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_SET_VDDD_ACTIVE_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_VDD_INTR_SET_VDDD_ACTIVE_Msk 0x80000000UL
/* SMIF_CORE_SMIF_GPIO.VDD_PWRSW_STATUS */
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_STATUS_PWROK_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_STATUS_PWROK_Msk 0x1UL
/* SMIF_CORE_SMIF_GPIO.VDD_PWRSW_CTL */
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_ILIM_Pos 0UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_ILIM_Msk 0x3UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_THRES_SEL_Pos 4UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_THRES_SEL_Msk 0x30UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_SW_ON_Pos 8UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_SW_ON_Msk 0x100UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_PWROK_BYPASS_Pos 9UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_PWROK_BYPASS_Msk 0x200UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_MODEHV_LOCK_Pos 16UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_MODEHV_LOCK_Msk 0xFF0000UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_MODEHV_Pos 31UL
#define SMIF_CORE_SMIF_GPIO_VDD_PWRSW_CTL_MODEHV_Msk 0x80000000UL


/* SMIF_CORE.CTL */
#define SMIF_CORE_CTL_XIP_MODE_Pos              0UL
#define SMIF_CORE_CTL_XIP_MODE_Msk              0x1UL
#define SMIF_CORE_CTL_DESELECT_DELAY_Pos        16UL
#define SMIF_CORE_CTL_DESELECT_DELAY_Msk        0x70000UL
#define SMIF_CORE_CTL_SELECT_SETUP_DELAY_Pos    20UL
#define SMIF_CORE_CTL_SELECT_SETUP_DELAY_Msk    0x300000UL
#define SMIF_CORE_CTL_SELECT_HOLD_DELAY_Pos     22UL
#define SMIF_CORE_CTL_SELECT_HOLD_DELAY_Msk     0xC00000UL
#define SMIF_CORE_CTL_BLOCK_Pos                 24UL
#define SMIF_CORE_CTL_BLOCK_Msk                 0x1000000UL
#define SMIF_CORE_CTL_CLOCK_IF_SEL_Pos          25UL
#define SMIF_CORE_CTL_CLOCK_IF_SEL_Msk          0x2000000UL
#define SMIF_CORE_CTL_ENABLED_Pos               31UL
#define SMIF_CORE_CTL_ENABLED_Msk               0x80000000UL
/* SMIF_CORE.STATUS */
#define SMIF_CORE_STATUS_DLL_LOCKED_Pos         0UL
#define SMIF_CORE_STATUS_DLL_LOCKED_Msk         0x1UL
#define SMIF_CORE_STATUS_BUSY_Pos               31UL
#define SMIF_CORE_STATUS_BUSY_Msk               0x80000000UL
/* SMIF_CORE.CTL2 */
#define SMIF_CORE_CTL2_DLL_SPEED_MODE_Pos       0UL
#define SMIF_CORE_CTL2_DLL_SPEED_MODE_Msk       0x3UL
#define SMIF_CORE_CTL2_DLL_OPENLOOP_ENABLE_Pos  2UL
#define SMIF_CORE_CTL2_DLL_OPENLOOP_ENABLE_Msk  0x4UL
#define SMIF_CORE_CTL2_DLL_BYPASS_MODE_Pos      3UL
#define SMIF_CORE_CTL2_DLL_BYPASS_MODE_Msk      0x8UL
#define SMIF_CORE_CTL2_CLKOUT_DIV_Pos           4UL
#define SMIF_CORE_CTL2_CLKOUT_DIV_Msk           0x30UL
#define SMIF_CORE_CTL2_DLL_MDL_BYPASS_MODE_Pos  6UL
#define SMIF_CORE_CTL2_DLL_MDL_BYPASS_MODE_Msk  0x40UL
#define SMIF_CORE_CTL2_DLL_IGNORE_LOCK_Pos      7UL
#define SMIF_CORE_CTL2_DLL_IGNORE_LOCK_Msk      0x80UL
#define SMIF_CORE_CTL2_MDL_TAP_SEL_Pos          8UL
#define SMIF_CORE_CTL2_MDL_TAP_SEL_Msk          0xF00UL
#define SMIF_CORE_CTL2_DLL_GATING_PERIOD_Pos    12UL
#define SMIF_CORE_CTL2_DLL_GATING_PERIOD_Msk    0x7000UL
#define SMIF_CORE_CTL2_DLL_UNLOCK_VALUE_Pos     15UL
#define SMIF_CORE_CTL2_DLL_UNLOCK_VALUE_Msk     0x38000UL
#define SMIF_CORE_CTL2_DLL_SKIP_LSB_Pos         18UL
#define SMIF_CORE_CTL2_DLL_SKIP_LSB_Msk         0xC0000UL
#define SMIF_CORE_CTL2_RX_CAPTURE_MODE_Pos      20UL
#define SMIF_CORE_CTL2_RX_CAPTURE_MODE_Msk      0x300000UL
#define SMIF_CORE_CTL2_RX_CHASE_MARGIN_Pos      22UL
#define SMIF_CORE_CTL2_RX_CHASE_MARGIN_Msk      0xC00000UL
#define SMIF_CORE_CTL2_TX_SDR_EXTRA_SETUP_Pos   31UL
#define SMIF_CORE_CTL2_TX_SDR_EXTRA_SETUP_Msk   0x80000000UL
/* SMIF_CORE.DLP_DELAY_TAP_SEL0 */
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT0_TAP_SEL_Pos 0UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT0_TAP_SEL_Msk 0xFFUL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT1_TAP_SEL_Pos 8UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT1_TAP_SEL_Msk 0xFF00UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT2_TAP_SEL_Pos 16UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT2_TAP_SEL_Msk 0xFF0000UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT3_TAP_SEL_Pos 24UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL0_DATA_BIT3_TAP_SEL_Msk 0xFF000000UL
/* SMIF_CORE.DLP_DELAY_TAP_SEL1 */
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT4_TAP_SEL_Pos 0UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT4_TAP_SEL_Msk 0xFFUL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT5_TAP_SEL_Pos 8UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT5_TAP_SEL_Msk 0xFF00UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT6_TAP_SEL_Pos 16UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT6_TAP_SEL_Msk 0xFF0000UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT7_TAP_SEL_Pos 24UL
#define SMIF_CORE_DLP_DELAY_TAP_SEL1_DATA_BIT7_TAP_SEL_Msk 0xFF000000UL
/* SMIF_CORE.DLP_CTL */
#define SMIF_CORE_DLP_CTL_DLP_Pos               0UL
#define SMIF_CORE_DLP_CTL_DLP_Msk               0xFFFFUL
#define SMIF_CORE_DLP_CTL_DLP_SIZE_Pos          16UL
#define SMIF_CORE_DLP_CTL_DLP_SIZE_Msk          0xF0000UL
#define SMIF_CORE_DLP_CTL_DLP_WARNING_LEVEL_Pos 24UL
#define SMIF_CORE_DLP_CTL_DLP_WARNING_LEVEL_Msk 0xF000000UL
/* SMIF_CORE.DLP_STATUS0 */
#define SMIF_CORE_DLP_STATUS0_DATA_BIT0_Pos     0UL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT0_Msk     0x1FUL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT1_Pos     8UL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT1_Msk     0x1F00UL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT2_Pos     16UL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT2_Msk     0x1F0000UL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT3_Pos     24UL
#define SMIF_CORE_DLP_STATUS0_DATA_BIT3_Msk     0x1F000000UL
/* SMIF_CORE.DLP_STATUS1 */
#define SMIF_CORE_DLP_STATUS1_DATA_BIT4_Pos     0UL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT4_Msk     0x1FUL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT5_Pos     8UL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT5_Msk     0x1F00UL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT6_Pos     16UL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT6_Msk     0x1F0000UL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT7_Pos     24UL
#define SMIF_CORE_DLP_STATUS1_DATA_BIT7_Msk     0x1F000000UL
/* SMIF_CORE.TX_CMD_FIFO_STATUS */
#define SMIF_CORE_TX_CMD_FIFO_STATUS_USED4_Pos  0UL
#define SMIF_CORE_TX_CMD_FIFO_STATUS_USED4_Msk  0xFUL
/* SMIF_CORE.TX_CMD_MMIO_FIFO_STATUS */
#define SMIF_CORE_TX_CMD_MMIO_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_CORE_TX_CMD_MMIO_FIFO_STATUS_USED4_Msk 0xFUL
/* SMIF_CORE.TX_CMD_MMIO_FIFO_WR */
#define SMIF_CORE_TX_CMD_MMIO_FIFO_WR_DATA27_Pos 0UL
#define SMIF_CORE_TX_CMD_MMIO_FIFO_WR_DATA27_Msk 0x7FFFFFFUL
/* SMIF_CORE.TX_DATA_MMIO_FIFO_CTL */
#define SMIF_CORE_TX_DATA_MMIO_FIFO_CTL_TX_TRIGGER_LEVEL_Pos 0UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_CTL_TX_TRIGGER_LEVEL_Msk 0x7UL
/* SMIF_CORE.TX_DATA_FIFO_STATUS */
#define SMIF_CORE_TX_DATA_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_CORE_TX_DATA_FIFO_STATUS_USED4_Msk 0xFUL
/* SMIF_CORE.TX_DATA_MMIO_FIFO_STATUS */
#define SMIF_CORE_TX_DATA_MMIO_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_STATUS_USED4_Msk 0xFUL
/* SMIF_CORE.TX_DATA_MMIO_FIFO_WR1 */
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR1_DATA0_Pos 0UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR1_DATA0_Msk 0xFFUL
/* SMIF_CORE.TX_DATA_MMIO_FIFO_WR2 */
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR2_DATA0_Pos 0UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR2_DATA0_Msk 0xFFUL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR2_DATA1_Pos 8UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR2_DATA1_Msk 0xFF00UL
/* SMIF_CORE.TX_DATA_MMIO_FIFO_WR4 */
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA0_Pos 0UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA0_Msk 0xFFUL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA1_Pos 8UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA1_Msk 0xFF00UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA2_Pos 16UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA2_Msk 0xFF0000UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA3_Pos 24UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR4_DATA3_Msk 0xFF000000UL
/* SMIF_CORE.TX_DATA_MMIO_FIFO_WR1ODD */
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR1ODD_DATA0_Pos 0UL
#define SMIF_CORE_TX_DATA_MMIO_FIFO_WR1ODD_DATA0_Msk 0xFFUL
/* SMIF_CORE.RX_DATA_MMIO_FIFO_CTL */
#define SMIF_CORE_RX_DATA_MMIO_FIFO_CTL_RX_TRIGGER_LEVEL_Pos 0UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_CTL_RX_TRIGGER_LEVEL_Msk 0x7UL
/* SMIF_CORE.RX_DATA_MMIO_FIFO_STATUS */
#define SMIF_CORE_RX_DATA_MMIO_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_STATUS_USED4_Msk 0xFUL
/* SMIF_CORE.RX_DATA_FIFO_STATUS */
#define SMIF_CORE_RX_DATA_FIFO_STATUS_USED4_Pos 0UL
#define SMIF_CORE_RX_DATA_FIFO_STATUS_USED4_Msk 0xFUL
#define SMIF_CORE_RX_DATA_FIFO_STATUS_RX_SR_USED_Pos 8UL
#define SMIF_CORE_RX_DATA_FIFO_STATUS_RX_SR_USED_Msk 0x100UL
/* SMIF_CORE.RX_DATA_MMIO_FIFO_RD1 */
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD1_DATA0_Pos 0UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD1_DATA0_Msk 0xFFUL
/* SMIF_CORE.RX_DATA_MMIO_FIFO_RD2 */
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD2_DATA0_Pos 0UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD2_DATA0_Msk 0xFFUL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD2_DATA1_Pos 8UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD2_DATA1_Msk 0xFF00UL
/* SMIF_CORE.RX_DATA_MMIO_FIFO_RD4 */
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA0_Pos 0UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA0_Msk 0xFFUL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA1_Pos 8UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA1_Msk 0xFF00UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA2_Pos 16UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA2_Msk 0xFF0000UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA3_Pos 24UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD4_DATA3_Msk 0xFF000000UL
/* SMIF_CORE.RX_DATA_MMIO_FIFO_RD1_SILENT */
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD1_SILENT_DATA0_Pos 0UL
#define SMIF_CORE_RX_DATA_MMIO_FIFO_RD1_SILENT_DATA0_Msk 0xFFUL
/* SMIF_CORE.SLOW_CA_CTL */
#define SMIF_CORE_SLOW_CA_CTL_WAY_Pos           16UL
#define SMIF_CORE_SLOW_CA_CTL_WAY_Msk           0x30000UL
#define SMIF_CORE_SLOW_CA_CTL_SET_ADDR_Pos      24UL
#define SMIF_CORE_SLOW_CA_CTL_SET_ADDR_Msk      0x3000000UL
#define SMIF_CORE_SLOW_CA_CTL_PREF_EN_Pos       30UL
#define SMIF_CORE_SLOW_CA_CTL_PREF_EN_Msk       0x40000000UL
#define SMIF_CORE_SLOW_CA_CTL_ENABLED_Pos       31UL
#define SMIF_CORE_SLOW_CA_CTL_ENABLED_Msk       0x80000000UL
/* SMIF_CORE.SLOW_CA_CMD */
#define SMIF_CORE_SLOW_CA_CMD_INV_Pos           0UL
#define SMIF_CORE_SLOW_CA_CMD_INV_Msk           0x1UL
/* SMIF_CORE.FAST_CA_CTL */
#define SMIF_CORE_FAST_CA_CTL_WAY_Pos           16UL
#define SMIF_CORE_FAST_CA_CTL_WAY_Msk           0x30000UL
#define SMIF_CORE_FAST_CA_CTL_SET_ADDR_Pos      24UL
#define SMIF_CORE_FAST_CA_CTL_SET_ADDR_Msk      0x3000000UL
#define SMIF_CORE_FAST_CA_CTL_PREF_EN_Pos       30UL
#define SMIF_CORE_FAST_CA_CTL_PREF_EN_Msk       0x40000000UL
#define SMIF_CORE_FAST_CA_CTL_ENABLED_Pos       31UL
#define SMIF_CORE_FAST_CA_CTL_ENABLED_Msk       0x80000000UL
/* SMIF_CORE.FAST_CA_CMD */
#define SMIF_CORE_FAST_CA_CMD_INV_Pos           0UL
#define SMIF_CORE_FAST_CA_CMD_INV_Msk           0x1UL
/* SMIF_CORE.CRC_CMD */
#define SMIF_CORE_CRC_CMD_START_Pos             0UL
#define SMIF_CORE_CRC_CMD_START_Msk             0x1UL
#define SMIF_CORE_CRC_CMD_CONTINUE_Pos          1UL
#define SMIF_CORE_CRC_CMD_CONTINUE_Msk          0x2UL
/* SMIF_CORE.CRC_INPUT0 */
#define SMIF_CORE_CRC_INPUT0_INPUT_Pos          0UL
#define SMIF_CORE_CRC_INPUT0_INPUT_Msk          0xFFFFFFFFUL
/* SMIF_CORE.CRC_INPUT1 */
#define SMIF_CORE_CRC_INPUT1_INPUT_Pos          0UL
#define SMIF_CORE_CRC_INPUT1_INPUT_Msk          0xFFFFFFFFUL
/* SMIF_CORE.CRC_OUTPUT */
#define SMIF_CORE_CRC_OUTPUT_CRC_OUTPUT_Pos     0UL
#define SMIF_CORE_CRC_OUTPUT_CRC_OUTPUT_Msk     0xFFUL
/* SMIF_CORE.INTR */
#define SMIF_CORE_INTR_TR_TX_REQ_Pos            0UL
#define SMIF_CORE_INTR_TR_TX_REQ_Msk            0x1UL
#define SMIF_CORE_INTR_TR_RX_REQ_Pos            1UL
#define SMIF_CORE_INTR_TR_RX_REQ_Msk            0x2UL
#define SMIF_CORE_INTR_XIP_ALIGNMENT_ERROR_Pos  2UL
#define SMIF_CORE_INTR_XIP_ALIGNMENT_ERROR_Msk  0x4UL
#define SMIF_CORE_INTR_TX_CMD_FIFO_OVERFLOW_Pos 3UL
#define SMIF_CORE_INTR_TX_CMD_FIFO_OVERFLOW_Msk 0x8UL
#define SMIF_CORE_INTR_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_CORE_INTR_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_CORE_INTR_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_CORE_INTR_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_CORE_INTR_DLP_FAIL_Pos             8UL
#define SMIF_CORE_INTR_DLP_FAIL_Msk             0x100UL
#define SMIF_CORE_INTR_DLP_WARNING_Pos          12UL
#define SMIF_CORE_INTR_DLP_WARNING_Msk          0x1000UL
#define SMIF_CORE_INTR_DLL_LOCK_Pos             13UL
#define SMIF_CORE_INTR_DLL_LOCK_Msk             0x2000UL
#define SMIF_CORE_INTR_DLL_UNLOCK_Pos           14UL
#define SMIF_CORE_INTR_DLL_UNLOCK_Msk           0x4000UL
#define SMIF_CORE_INTR_CRC_ERROR_Pos            16UL
#define SMIF_CORE_INTR_CRC_ERROR_Msk            0x10000UL
#define SMIF_CORE_INTR_FS_STATUS_ERROR_Pos      17UL
#define SMIF_CORE_INTR_FS_STATUS_ERROR_Msk      0x20000UL
/* SMIF_CORE.INTR_SET */
#define SMIF_CORE_INTR_SET_TR_TX_REQ_Pos        0UL
#define SMIF_CORE_INTR_SET_TR_TX_REQ_Msk        0x1UL
#define SMIF_CORE_INTR_SET_TR_RX_REQ_Pos        1UL
#define SMIF_CORE_INTR_SET_TR_RX_REQ_Msk        0x2UL
#define SMIF_CORE_INTR_SET_XIP_ALIGNMENT_ERROR_Pos 2UL
#define SMIF_CORE_INTR_SET_XIP_ALIGNMENT_ERROR_Msk 0x4UL
#define SMIF_CORE_INTR_SET_TX_CMD_FIFO_OVERFLOW_Pos 3UL
#define SMIF_CORE_INTR_SET_TX_CMD_FIFO_OVERFLOW_Msk 0x8UL
#define SMIF_CORE_INTR_SET_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_CORE_INTR_SET_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_CORE_INTR_SET_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_CORE_INTR_SET_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_CORE_INTR_SET_DLP_FAIL_Pos         8UL
#define SMIF_CORE_INTR_SET_DLP_FAIL_Msk         0x100UL
#define SMIF_CORE_INTR_SET_DLP_WARNING_Pos      12UL
#define SMIF_CORE_INTR_SET_DLP_WARNING_Msk      0x1000UL
#define SMIF_CORE_INTR_SET_DLL_LOCK_Pos         13UL
#define SMIF_CORE_INTR_SET_DLL_LOCK_Msk         0x2000UL
#define SMIF_CORE_INTR_SET_DLL_UNLOCK_Pos       14UL
#define SMIF_CORE_INTR_SET_DLL_UNLOCK_Msk       0x4000UL
#define SMIF_CORE_INTR_SET_CRC_ERROR_Pos        16UL
#define SMIF_CORE_INTR_SET_CRC_ERROR_Msk        0x10000UL
#define SMIF_CORE_INTR_SET_FS_STATUS_ERROR_Pos  17UL
#define SMIF_CORE_INTR_SET_FS_STATUS_ERROR_Msk  0x20000UL
/* SMIF_CORE.INTR_MASK */
#define SMIF_CORE_INTR_MASK_TR_TX_REQ_Pos       0UL
#define SMIF_CORE_INTR_MASK_TR_TX_REQ_Msk       0x1UL
#define SMIF_CORE_INTR_MASK_TR_RX_REQ_Pos       1UL
#define SMIF_CORE_INTR_MASK_TR_RX_REQ_Msk       0x2UL
#define SMIF_CORE_INTR_MASK_XIP_ALIGNMENT_ERROR_Pos 2UL
#define SMIF_CORE_INTR_MASK_XIP_ALIGNMENT_ERROR_Msk 0x4UL
#define SMIF_CORE_INTR_MASK_TX_CMD_FIFO_OVERFLOW_Pos 3UL
#define SMIF_CORE_INTR_MASK_TX_CMD_FIFO_OVERFLOW_Msk 0x8UL
#define SMIF_CORE_INTR_MASK_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_CORE_INTR_MASK_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_CORE_INTR_MASK_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_CORE_INTR_MASK_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_CORE_INTR_MASK_DLP_FAIL_Pos        8UL
#define SMIF_CORE_INTR_MASK_DLP_FAIL_Msk        0x100UL
#define SMIF_CORE_INTR_MASK_DLP_WARNING_Pos     12UL
#define SMIF_CORE_INTR_MASK_DLP_WARNING_Msk     0x1000UL
#define SMIF_CORE_INTR_MASK_DLL_LOCK_Pos        13UL
#define SMIF_CORE_INTR_MASK_DLL_LOCK_Msk        0x2000UL
#define SMIF_CORE_INTR_MASK_DLL_UNLOCK_Pos      14UL
#define SMIF_CORE_INTR_MASK_DLL_UNLOCK_Msk      0x4000UL
#define SMIF_CORE_INTR_MASK_CRC_ERROR_Pos       16UL
#define SMIF_CORE_INTR_MASK_CRC_ERROR_Msk       0x10000UL
#define SMIF_CORE_INTR_MASK_FS_STATUS_ERROR_Pos 17UL
#define SMIF_CORE_INTR_MASK_FS_STATUS_ERROR_Msk 0x20000UL
/* SMIF_CORE.INTR_MASKED */
#define SMIF_CORE_INTR_MASKED_TR_TX_REQ_Pos     0UL
#define SMIF_CORE_INTR_MASKED_TR_TX_REQ_Msk     0x1UL
#define SMIF_CORE_INTR_MASKED_TR_RX_REQ_Pos     1UL
#define SMIF_CORE_INTR_MASKED_TR_RX_REQ_Msk     0x2UL
#define SMIF_CORE_INTR_MASKED_XIP_ALIGNMENT_ERROR_Pos 2UL
#define SMIF_CORE_INTR_MASKED_XIP_ALIGNMENT_ERROR_Msk 0x4UL
#define SMIF_CORE_INTR_MASKED_TX_CMD_FIFO_OVERFLOW_Pos 3UL
#define SMIF_CORE_INTR_MASKED_TX_CMD_FIFO_OVERFLOW_Msk 0x8UL
#define SMIF_CORE_INTR_MASKED_TX_DATA_FIFO_OVERFLOW_Pos 4UL
#define SMIF_CORE_INTR_MASKED_TX_DATA_FIFO_OVERFLOW_Msk 0x10UL
#define SMIF_CORE_INTR_MASKED_RX_DATA_MMIO_FIFO_UNDERFLOW_Pos 5UL
#define SMIF_CORE_INTR_MASKED_RX_DATA_MMIO_FIFO_UNDERFLOW_Msk 0x20UL
#define SMIF_CORE_INTR_MASKED_DLP_FAIL_Pos      8UL
#define SMIF_CORE_INTR_MASKED_DLP_FAIL_Msk      0x100UL
#define SMIF_CORE_INTR_MASKED_DLP_WARNING_Pos   12UL
#define SMIF_CORE_INTR_MASKED_DLP_WARNING_Msk   0x1000UL
#define SMIF_CORE_INTR_MASKED_DLL_LOCK_Pos      13UL
#define SMIF_CORE_INTR_MASKED_DLL_LOCK_Msk      0x2000UL
#define SMIF_CORE_INTR_MASKED_DLL_UNLOCK_Pos    14UL
#define SMIF_CORE_INTR_MASKED_DLL_UNLOCK_Msk    0x4000UL
#define SMIF_CORE_INTR_MASKED_CRC_ERROR_Pos     16UL
#define SMIF_CORE_INTR_MASKED_CRC_ERROR_Msk     0x10000UL
#define SMIF_CORE_INTR_MASKED_FS_STATUS_ERROR_Pos 17UL
#define SMIF_CORE_INTR_MASKED_FS_STATUS_ERROR_Msk 0x20000UL
/* SMIF_CORE.DLL_IDAC */
#define SMIF_CORE_DLL_IDAC_SEL_Pos              0UL
#define SMIF_CORE_DLL_IDAC_SEL_Msk              0xFFFUL
/* SMIF_CORE.DLL_IVR */
#define SMIF_CORE_DLL_IVR_SELECT_Pos            0UL
#define SMIF_CORE_DLL_IVR_SELECT_Msk            0x7UL


#endif /* _CYIP_SMIF_V6_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* SRSS IP definitions
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

#ifndef _CYIP_SRSS_V1_1_H_
#define _CYIP_SRSS_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define CLK_ECO_SECTION_SIZE                    0x00000010UL
#define CSV_HF_CSV_SECTION_SIZE                 0x00000010UL
#define CSV_HF_SECTION_SIZE                     0x00000100UL
#define CSV_REF_CSV_SECTION_SIZE                0x00000010UL
#define CSV_REF_SECTION_SIZE                    0x00000010UL
#define CSV_LF_CSV_SECTION_SIZE                 0x00000010UL
#define CSV_LF_SECTION_SIZE                     0x00000010UL
#define CSV_PILO_CSV_SECTION_SIZE               0x00000010UL
#define CSV_PILO_SECTION_SIZE                   0x00000010UL
#define CLK_DPLL_LP_SECTION_SIZE                0x00000020UL
#define CLK_DPLL_HP_SECTION_SIZE                0x00000040UL
#define CLK_TRIM_DPLL_LP_SECTION_SIZE           0x00000020UL
#define RAM_TRIM_SECTION_SIZE                   0x00000040UL
#define WDT_SECTION_SIZE                        0x00000080UL
#define MCWDT_STRUCT_SECTION_SIZE               0x00000040UL
#define MCWDT_CTR_SECTION_SIZE                  0x00000020UL
#define MCWDT_SECTION_SIZE                      0x00000100UL
#define SRSS_SECTION_SIZE                       0x00010000UL

/**
  * \brief ECO Configuration (CLK_ECO)
  */
typedef struct {
  __IOM uint32_t CONFIG;                        /*!< 0x00000000 ECO Configuration Register */
  __IOM uint32_t CONFIG2;                       /*!< 0x00000004 ECO Configuration Register 2 */
   __IM uint32_t STATUS;                        /*!< 0x00000008 ECO Status Register */
   __IM uint32_t RESERVED;
} CLK_ECO_Type;                                 /*!< Size = 16 (0x10) */

/**
  * \brief Active domain Clock Supervisor (CSV) registers (CSV_HF_CSV)
  */
typedef struct {
  __IOM uint32_t REF_CTL;                       /*!< 0x00000000 Clock Supervision Reference Control */
  __IOM uint32_t REF_LIMIT;                     /*!< 0x00000004 Clock Supervision Reference Limits */
  __IOM uint32_t MON_CTL;                       /*!< 0x00000008 Clock Supervision Monitor Control */
   __IM uint32_t RESERVED;
} CSV_HF_CSV_Type;                              /*!< Size = 16 (0x10) */

/**
  * \brief Clock Supervisor (CSV) registers for Root clocks (CSV_HF)
  */
typedef struct {
        CSV_HF_CSV_Type CSV[16];                /*!< 0x00000000 Active domain Clock Supervisor (CSV) registers */
} CSV_HF_Type;                                  /*!< Size = 256 (0x100) */

/**
  * \brief Active domain Clock Supervisor (CSV) registers for CSV Reference clock (CSV_REF_CSV)
  */
typedef struct {
  __IOM uint32_t REF_CTL;                       /*!< 0x00000000 Clock Supervision Reference Control */
  __IOM uint32_t REF_LIMIT;                     /*!< 0x00000004 Clock Supervision Reference Limits */
  __IOM uint32_t MON_CTL;                       /*!< 0x00000008 Clock Supervision Monitor Control */
   __IM uint32_t RESERVED;
} CSV_REF_CSV_Type;                             /*!< Size = 16 (0x10) */

/**
  * \brief CSV registers for the CSV Reference clock (CSV_REF)
  */
typedef struct {
        CSV_REF_CSV_Type CSV;                   /*!< 0x00000000 Active domain Clock Supervisor (CSV) registers for CSV
                                                                Reference clock */
} CSV_REF_Type;                                 /*!< Size = 16 (0x10) */

/**
  * \brief LF clock Clock Supervisor registers (CSV_LF_CSV)
  */
typedef struct {
  __IOM uint32_t REF_CTL;                       /*!< 0x00000000 Clock Supervision Reference Control */
  __IOM uint32_t REF_LIMIT;                     /*!< 0x00000004 Clock Supervision Reference Limits */
  __IOM uint32_t MON_CTL;                       /*!< 0x00000008 Clock Supervision Monitor Control */
   __IM uint32_t RESERVED;
} CSV_LF_CSV_Type;                              /*!< Size = 16 (0x10) */

/**
  * \brief CSV registers for LF clock (CSV_LF)
  */
typedef struct {
        CSV_LF_CSV_Type CSV;                    /*!< 0x00000000 LF clock Clock Supervisor registers */
} CSV_LF_Type;                                  /*!< Size = 16 (0x10) */

/**
  * \brief HVILO clock DeepSleep domain Clock Supervisor registers (CSV_PILO_CSV)
  */
typedef struct {
  __IOM uint32_t REF_CTL;                       /*!< 0x00000000 Clock Supervision Reference Control */
  __IOM uint32_t REF_LIMIT;                     /*!< 0x00000004 Clock Supervision Reference Limits */
  __IOM uint32_t MON_CTL;                       /*!< 0x00000008 Clock Supervision Monitor Control */
   __IM uint32_t RESERVED;
} CSV_PILO_CSV_Type;                            /*!< Size = 16 (0x10) */

/**
  * \brief CSV registers for PILO clock (CSV_PILO)
  */
typedef struct {
        CSV_PILO_CSV_Type CSV;                  /*!< 0x00000000 HVILO clock DeepSleep domain Clock Supervisor registers */
} CSV_PILO_Type;                                /*!< Size = 16 (0x10) */

/**
  * \brief DPLL LP Configuration Register (CLK_DPLL_LP)
  */
typedef struct {
  __IOM uint32_t CONFIG;                        /*!< 0x00000000 DPLL_LP Configuration Register */
  __IOM uint32_t CONFIG2;                       /*!< 0x00000004 DPLL_LP Configuration Register 2 */
  __IOM uint32_t CONFIG3;                       /*!< 0x00000008 DPLL_LP Configuration Register 3 */
  __IOM uint32_t CONFIG4;                       /*!< 0x0000000C DPLL_LP Configuration Register 4 */
  __IOM uint32_t CONFIG5;                       /*!< 0x00000010 DPLL_LP Configuration Register 5 */
  __IOM uint32_t CONFIG6;                       /*!< 0x00000014 DPLL_LP Configuration Register 6 */
  __IOM uint32_t CONFIG7;                       /*!< 0x00000018 DPLL_LP Configuration Register 7 */
  __IOM uint32_t STATUS;                        /*!< 0x0000001C DPLL_LP Status Register */
} CLK_DPLL_LP_Type;                             /*!< Size = 32 (0x20) */

/**
  * \brief DPLL HP Configuration Register (CLK_DPLL_HP)
  */
typedef struct {
  __IOM uint32_t CONFIG;                        /*!< 0x00000000 DPLL_HP Configuration Register */
  __IOM uint32_t CONFIG2;                       /*!< 0x00000004 DPLL_HP Configuration Register 2 */
  __IOM uint32_t CONFIG3;                       /*!< 0x00000008 DPLL_HP Configuration Register 3 */
  __IOM uint32_t CONFIG4;                       /*!< 0x0000000C DPLL_HP Configuration Register 4 */
  __IOM uint32_t CONFIG5;                       /*!< 0x00000010 DPLL_HP Configuration Register 5 */
  __IOM uint32_t TRIGMOD;                       /*!< 0x00000014 DPLL_HP Trigmod SSCG Register */
  __IOM uint32_t TRIGMOD2;                      /*!< 0x00000018 DPLL_HP Trigmod2 SSCG Register */
  __IOM uint32_t STATUS;                        /*!< 0x0000001C DPLL_HP Status Register */
  __IOM uint32_t DUTYCAL_CTRL;                  /*!< 0x00000020 DPLL_HP_User DUTYCAL Control Register */
   __IM uint32_t RESERVED[7];
} CLK_DPLL_HP_Type;                             /*!< Size = 64 (0x40) */

/**
  * \brief DPLL LP Trims (CLK_TRIM_DPLL_LP)
  */
typedef struct {
  __IOM uint32_t DPLL_LP_CTL;                   /*!< 0x00000000 DPLL LP Trim Register */
   __IM uint32_t RESERVED;
  __IOM uint32_t DPLL_LP_CTL3;                  /*!< 0x00000008 DPLL LP Trim Register 3 */
  __IOM uint32_t DPLL_LP_CTL4;                  /*!< 0x0000000C DPLL LP Trim Register 4 */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t DPLL_LP_TEST4;                 /*!< 0x0000001C DPLL LP Test Register 4 */
} CLK_TRIM_DPLL_LP_Type;                        /*!< Size = 32 (0x20) */

/**
  * \brief SRAM Trim registers (RAM_TRIM)
  */
typedef struct {
  __IOM uint32_t TRIM_RAM_CTL[10];              /*!< 0x00000000 Trim Register for RAM Type 0 */
   __IM uint32_t RESERVED[6];
} RAM_TRIM_Type;                                /*!< Size = 64 (0x40) */

/**
  * \brief Watchdog Timer (Type B) (WDT)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 WDT Control Register */
  __IOM uint32_t LOWER_LIMIT;                   /*!< 0x00000004 WDT Lower Limit Register */
  __IOM uint32_t UPPER_LIMIT;                   /*!< 0x00000008 WDT Upper Limit Register */
  __IOM uint32_t WARN_LIMIT;                    /*!< 0x0000000C WDT Warn Limit Register */
  __IOM uint32_t CONFIG;                        /*!< 0x00000010 WDT Configuration Register */
  __IOM uint32_t CNT;                           /*!< 0x00000014 WDT Count Register */
   __IM uint32_t RESERVED[10];
  __IOM uint32_t LOCK;                          /*!< 0x00000040 WDT Lock register */
  __IOM uint32_t SERVICE;                       /*!< 0x00000044 WDT Service register */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t INTR;                          /*!< 0x00000050 WDT Interrupt Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000054 WDT Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000058 WDT Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000005C WDT Interrupt Masked Register */
   __IM uint32_t RESERVED2[8];
} WDT_Type;                                     /*!< Size = 128 (0x80) */

/**
  * \brief Multi-Counter Watchdog Timer (Type A) (MCWDT_STRUCT)
  */
typedef struct {
   __IM uint32_t RESERVED;
  __IOM uint32_t MCWDT_CNTLOW;                  /*!< 0x00000004 Multi-Counter Watchdog Sub-counters 0/1 */
  __IOM uint32_t MCWDT_CNTHIGH;                 /*!< 0x00000008 Multi-Counter Watchdog Sub-counter 2 */
  __IOM uint32_t MCWDT_MATCH;                   /*!< 0x0000000C Multi-Counter Watchdog Counter Match Register */
  __IOM uint32_t MCWDT_CONFIG;                  /*!< 0x00000010 Multi-Counter Watchdog Counter Configuration */
  __IOM uint32_t MCWDT_CTL;                     /*!< 0x00000014 Multi-Counter Watchdog Counter Control */
  __IOM uint32_t MCWDT_INTR;                    /*!< 0x00000018 Multi-Counter Watchdog Counter Interrupt Register */
  __IOM uint32_t MCWDT_INTR_SET;                /*!< 0x0000001C Multi-Counter Watchdog Counter Interrupt Set Register */
  __IOM uint32_t MCWDT_INTR_MASK;               /*!< 0x00000020 Multi-Counter Watchdog Counter Interrupt Mask Register */
   __IM uint32_t MCWDT_INTR_MASKED;             /*!< 0x00000024 Multi-Counter Watchdog Counter Interrupt Masked Register */
  __IOM uint32_t MCWDT_LOCK;                    /*!< 0x00000028 Multi-Counter Watchdog Counter Lock Register */
  __IOM uint32_t MCWDT_LOWER_LIMIT;             /*!< 0x0000002C Multi-Counter Watchdog Counter Lower Limit Register */
   __IM uint32_t RESERVED1[4];
} MCWDT_STRUCT_Type;                            /*!< Size = 64 (0x40) */

/**
  * \brief MCWDT Configuration for Subcounter 0 and 1 (MCWDT_CTR)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 MCWDT Subcounter Control Register */
  __IOM uint32_t LOWER_LIMIT;                   /*!< 0x00000004 MCWDT Subcounter Lower Limit Register */
  __IOM uint32_t UPPER_LIMIT;                   /*!< 0x00000008 MCWDT Subcounter Upper Limit Register */
  __IOM uint32_t WARN_LIMIT;                    /*!< 0x0000000C MCWDT Subcounter Warn Limit Register */
  __IOM uint32_t CONFIG;                        /*!< 0x00000010 MCWDT Subcounter Configuration Register */
  __IOM uint32_t CNT;                           /*!< 0x00000014 MCWDT Subcounter Count Register */
   __IM uint32_t RESERVED[2];
} MCWDT_CTR_Type;                               /*!< Size = 32 (0x20) */

/**
  * \brief Multi-Counter Watchdog Timer (Type B) (MCWDT)
  */
typedef struct {
        MCWDT_CTR_Type CTR[2];                  /*!< 0x00000000 MCWDT Configuration for Subcounter 0 and 1 */
  __IOM uint32_t CPU_SELECT;                    /*!< 0x00000040 MCWDT CPU selection register */
   __IM uint32_t RESERVED[15];
  __IOM uint32_t CTR2_CTL;                      /*!< 0x00000080 MCWDT Subcounter 2 Control register */
  __IOM uint32_t CTR2_CONFIG;                   /*!< 0x00000084 MCWDT Subcounter 2 Configuration register */
  __IOM uint32_t CTR2_CNT;                      /*!< 0x00000088 MCWDT Subcounter 2 Count Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t LOCK;                          /*!< 0x00000090 MCWDT Lock Register */
  __IOM uint32_t SERVICE;                       /*!< 0x00000094 MCWDT Service Register */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t INTR;                          /*!< 0x000000A0 MCWDT Interrupt Register */
  __IOM uint32_t INTR_SET;                      /*!< 0x000000A4 MCWDT Interrupt Set Register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x000000A8 MCWDT Interrupt Mask Register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x000000AC MCWDT Interrupt Masked Register */
   __IM uint32_t RESERVED3[20];
} MCWDT_Type;                                   /*!< Size = 256 (0x100) */

/**
  * \brief SRSS Core Registers (SRSS)
  */
typedef struct {
   __IM uint32_t RESERVED[64];
  __IOM uint32_t CLK_DSI_SELECT[16];            /*!< 0x00000100 Clock DSI Select Register */
  __IOM uint32_t CLK_OUTPUT_FAST;               /*!< 0x00000140 Fast Clock Output Select Register */
  __IOM uint32_t CLK_OUTPUT_SLOW;               /*!< 0x00000144 Slow Clock Output Select Register */
  __IOM uint32_t CLK_CAL_CNT1;                  /*!< 0x00000148 Clock Calibration Counter 1 */
   __IM uint32_t CLK_CAL_CNT2;                  /*!< 0x0000014C Clock Calibration Counter 2 */
   __IM uint32_t RESERVED1[44];
  __IOM uint32_t SRSS_INTR;                     /*!< 0x00000200 SRSS Interrupt Register */
  __IOM uint32_t SRSS_INTR_SET;                 /*!< 0x00000204 SRSS Interrupt Set Register */
  __IOM uint32_t SRSS_INTR_MASK;                /*!< 0x00000208 SRSS Interrupt Mask Register */
   __IM uint32_t SRSS_INTR_MASKED;              /*!< 0x0000020C SRSS Interrupt Masked Register */
   __IM uint32_t RESERVED2[60];
  __IOM uint32_t SRSS_AINTR;                    /*!< 0x00000300 SRSS Additional Interrupt Register */
  __IOM uint32_t SRSS_AINTR_SET;                /*!< 0x00000304 SRSS Additional Interrupt Set Register */
  __IOM uint32_t SRSS_AINTR_MASK;               /*!< 0x00000308 SRSS Additional Interrupt Mask Register */
   __IM uint32_t SRSS_AINTR_MASKED;             /*!< 0x0000030C SRSS Additional Interrupt Masked Register */
   __IM uint32_t RESERVED3[12];
   __IM uint32_t PWR_LVD_STATUS;                /*!< 0x00000340 High Voltage / Low Voltage Detector (HVLVD) Status Register */
   __IM uint32_t RESERVED4[48];
  __IOM uint32_t BOOT_DLM_CTL;                  /*!< 0x00000404 Debug Control Register */
  __IOM uint32_t BOOT_DLM_CTL2;                 /*!< 0x00000408 Debug Control Register 2 */
  __IOM uint32_t BOOT_DLM_STATUS;               /*!< 0x0000040C Debug Status Register */
  __IOM uint32_t RES_SOFT_CTL;                  /*!< 0x00000410 Soft Reset Trigger Register */
   __IM uint32_t RESERVED5;
  __IOM uint32_t BOOT_STATUS;                   /*!< 0x00000418 Boot Execution Status Register */
   __IM uint32_t RESERVED6[5];
  __IOM uint32_t BOOT_ENTRY;                    /*!< 0x00000430 Warm Boot Entry Address */
   __IM uint32_t RESERVED7[3];
   __IM uint32_t DECODED_LCS_DATA;              /*!< 0x00000440 Decoded Life Cycle Stage Data Register */
   __IM uint32_t RESERVED8[239];
  __IOM uint32_t PWR_HIB_DATA[32];              /*!< 0x00000800 Hibernate Data Register */
   __IM uint32_t RESERVED9[8];
  __IOM uint32_t PWR_HIB_WAKE_CTL;              /*!< 0x000008A0 Hibernate Wakeup Mask Register */
  __IOM uint32_t PWR_HIB_WAKE_CTL2;             /*!< 0x000008A4 Hibernate Wakeup Polarity Register */
   __IM uint32_t RESERVED10;
  __IOM uint32_t PWR_HIB_WAKE_CAUSE;            /*!< 0x000008AC Hibernate Wakeup Cause Register */
   __IM uint32_t RESERVED11[25];
  __IOM uint32_t TST_XRES_SECURE;               /*!< 0x00000914 SECURE TEST and FIRMWARE TEST Key control register */
   __IM uint32_t RESERVED12[442];
   __IM uint32_t PWR_CTL;                       /*!< 0x00001000 Power Mode Control */
  __IOM uint32_t PWR_CTL2;                      /*!< 0x00001004 Power Mode Control 2 */
  __IOM uint32_t PWR_HIBERNATE;                 /*!< 0x00001008 HIBERNATE Mode Register */
   __IM uint32_t RESERVED13[5];
  __IOM uint32_t PWR_LVD_CTL;                   /*!< 0x00001020 High Voltage / Low Voltage Detector (HVLVD) Configuration
                                                                Register */
   __IM uint32_t RESERVED14[119];
  __IOM uint32_t CLK_PATH_SELECT[16];           /*!< 0x00001200 Clock Path Select Register */
  __IOM uint32_t CLK_ROOT_SELECT[16];           /*!< 0x00001240 Clock Root Select Register */
  __IOM uint32_t CLK_DIRECT_SELECT[16];         /*!< 0x00001280 Clock Root Direct Select Register */
   __IM uint32_t RESERVED15[16];
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00001300 Clock selection register */
  __IOM uint32_t CLK_MF_SELECT;                 /*!< 0x00001304 Medium Frequency Clock Select Register */
   __IM uint32_t RESERVED16[2];
  __IOM uint32_t CLK_ALTHF_CTL[2];              /*!< 0x00001310 Alternate High Frequency Clock Control Register */
   __IM uint32_t RESERVED17[2];
  __IOM uint32_t CLK_ECO_PRESCALE;              /*!< 0x00001320 ECO Prescaler Configuration Register */
   __IM uint32_t RESERVED18[7];
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00001340 IMO Configuration */
  __IOM uint32_t CLK_IHO_CONFIG;                /*!< 0x00001344 IHO Configuration Register */
   __IM uint32_t RESERVED19[6];
        CLK_ECO_Type CLK_ECO_STRUCT;            /*!< 0x00001360 ECO Configuration */
  __IOM uint32_t CLK_PILO_CONFIG;               /*!< 0x00001370 Precision ILO Configuration Register */
   __IM uint32_t CLK_PILO_STATUS;               /*!< 0x00001374 Precision ILO Status Register */
   __IM uint32_t RESERVED20[2];
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x00001380 ILO Configuration */
  __IOM uint32_t CLK_TRIM_ILO_CTL;              /*!< 0x00001384 ILO Trim Register */
   __IM uint32_t RESERVED21[2];
  __IOM uint32_t CLK_WCO_CONFIG;                /*!< 0x00001390 WCO Configuration Register */
   __IM uint32_t CLK_WCO_STATUS;                /*!< 0x00001394 WCO Status Register */
   __IM uint32_t RESERVED22[26];
        CSV_HF_Type CSV_HF_STRUCT;              /*!< 0x00001400 Clock Supervisor (CSV) registers for Root clocks */
  __IOM uint32_t CSV_REF_SEL;                   /*!< 0x00001500 Select CSV Reference clock for Active domain */
   __IM uint32_t RESERVED23[3];
        CSV_REF_Type CSV_REF_STRUCT;            /*!< 0x00001510 CSV registers for the CSV Reference clock */
  __IOM uint32_t CSV_LF_REF_SEL;                /*!< 0x00001520 Select CSV Reference clock for LF clock */
   __IM uint32_t RESERVED24[3];
        CSV_LF_Type CSV_LF_STRUCT;              /*!< 0x00001530 CSV registers for LF clock */
  __IOM uint32_t CSV_PILO_REF_SEL;              /*!< 0x00001540 Select CSV Reference clock for PILO clock */
   __IM uint32_t RESERVED25[3];
        CSV_PILO_Type CSV_PILO;                 /*!< 0x00001550 CSV registers for PILO clock */
   __IM uint32_t RESERVED26[40];
        CLK_DPLL_LP_Type CLK_DPLL_LP[15];       /*!< 0x00001600 DPLL LP Configuration Register */
   __IM uint32_t RESERVED27[8];
        CLK_DPLL_HP_Type CLK_DPLL_HP[15];       /*!< 0x00001800 DPLL HP Configuration Register */
   __IM uint32_t RESERVED28[4];
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00001BD0 Reset Cause Observation Register */
  __IOM uint32_t RES_CAUSE2;                    /*!< 0x00001BD4 Reset Cause Observation Register 2 */
   __IM uint32_t RESERVED29[3];
   __OM uint32_t RES_PXRES_CTL;                 /*!< 0x00001BE4 Programmable XRES Control Register */
   __IM uint32_t RESERVED30[7];
  __IOM uint32_t RES_CAUSE_EXTEND;              /*!< 0x00001C04 Extended Reset Cause Observation Register */
   __IM uint32_t RESERVED31[2];
  __IOM uint32_t PWR_CBUCK_CTL;                 /*!< 0x00001C10 Core Buck Control Register */
  __IOM uint32_t PWR_CBUCK_CTL2;                /*!< 0x00001C14 Core Buck Control Register 2 */
   __IM uint32_t RESERVED32;
  __IOM uint32_t PWR_CBUCK_DPSLP_CTL;           /*!< 0x00001C1C Core Buck Deepsleep Control Register */
   __IM uint32_t PWR_CBUCK_STATUS;              /*!< 0x00001C20 Core Buck Status Register */
  __IOM uint32_t PWR_RETLDO_CTL;                /*!< 0x00001C24 RETLDO Control Register */
  __IOM uint32_t PWR_SRAMLDO_CTL;               /*!< 0x00001C28 SRAMLDO Control Register */
   __IM uint32_t RESERVED33;
  __IOM uint32_t PWR_MISCLDO_CTL;               /*!< 0x00001C30 MISCLDO Control Register */
   __IM uint32_t RESERVED34[311];
  __IOM uint32_t PWR_TRIM_PMU_CTL0;             /*!< 0x00002110 PMU Trim Register 0 */
   __IM uint32_t RESERVED35[963];
  __IOM uint32_t CLK_TRIM_ECO_CTL;              /*!< 0x00003020 ECO Trim Register */
   __IM uint32_t RESERVED36[119];
        CLK_TRIM_DPLL_LP_Type CLK_TRIM_DPLL_LP[15]; /*!< 0x00003200 DPLL LP Trims */
   __IM uint32_t RESERVED37[776];
        RAM_TRIM_Type RAM_TRIM_STRUCT;          /*!< 0x00004000 SRAM Trim registers */
   __IM uint32_t RESERVED38[8176];
  __IOM uint32_t WDT_CTL;                       /*!< 0x0000C000 Watchdog Counter Control Register (Type A) */
  __IOM uint32_t WDT_CNT;                       /*!< 0x0000C004 Watchdog Counter Count Register (Type A) */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x0000C008 Watchdog Counter Match Register (Type A) */
  __IOM uint32_t WDT_MATCH2;                    /*!< 0x0000C00C Watchdog Counter Match Register 2 (Type A) */
   __IM uint32_t RESERVED39[60];
        WDT_Type WDT[4];                        /*!< 0x0000C100 Watchdog Timer (Type B) */
   __IM uint32_t RESERVED40[832];
        MCWDT_STRUCT_Type MCWDT_STRUCT[4];      /*!< 0x0000D000 Multi-Counter Watchdog Timer (Type A) */
   __IM uint32_t RESERVED41[960];
        MCWDT_Type MCWDT[4];                    /*!< 0x0000E000 Multi-Counter Watchdog Timer (Type B) */
} SRSS_Type;                                    /*!< Size = 58368 (0xE400) */


/* CLK_ECO.CONFIG */
#define CLK_ECO_CONFIG_ECO_DIV_DISABLE_Pos      27UL
#define CLK_ECO_CONFIG_ECO_DIV_DISABLE_Msk      0x8000000UL
#define CLK_ECO_CONFIG_ECO_DIV_ENABLE_Pos       28UL
#define CLK_ECO_CONFIG_ECO_DIV_ENABLE_Msk       0x10000000UL
#define CLK_ECO_CONFIG_ECO_EN_Pos               31UL
#define CLK_ECO_CONFIG_ECO_EN_Msk               0x80000000UL
/* CLK_ECO.CONFIG2 */
#define CLK_ECO_CONFIG2_ECO_TRIM_CL_Pos         0UL
#define CLK_ECO_CONFIG2_ECO_TRIM_CL_Msk         0x1FUL
#define CLK_ECO_CONFIG2_ECO_TRIM_GAIN_Pos       8UL
#define CLK_ECO_CONFIG2_ECO_TRIM_GAIN_Msk       0xF00UL
#define CLK_ECO_CONFIG2_ECO_CTRL_AMPDETEN_Pos   16UL
#define CLK_ECO_CONFIG2_ECO_CTRL_AMPDETEN_Msk   0x10000UL
/* CLK_ECO.STATUS */
#define CLK_ECO_STATUS_ECO_OK_Pos               0UL
#define CLK_ECO_STATUS_ECO_OK_Msk               0x1UL
#define CLK_ECO_STATUS_ECO_READY_Pos            1UL
#define CLK_ECO_STATUS_ECO_READY_Msk            0x2UL


/* CSV_HF_CSV.REF_CTL */
#define CSV_HF_CSV_REF_CTL_CSV_STARTUP_Pos      0UL
#define CSV_HF_CSV_REF_CTL_CSV_STARTUP_Msk      0xFFFFUL
#define CSV_HF_CSV_REF_CTL_CSV_ACTION_Pos       30UL
#define CSV_HF_CSV_REF_CTL_CSV_ACTION_Msk       0x40000000UL
#define CSV_HF_CSV_REF_CTL_CSV_EN_Pos           31UL
#define CSV_HF_CSV_REF_CTL_CSV_EN_Msk           0x80000000UL
/* CSV_HF_CSV.REF_LIMIT */
#define CSV_HF_CSV_REF_LIMIT_CSV_LOWER_Pos      0UL
#define CSV_HF_CSV_REF_LIMIT_CSV_LOWER_Msk      0xFFFFUL
#define CSV_HF_CSV_REF_LIMIT_CSV_UPPER_Pos      16UL
#define CSV_HF_CSV_REF_LIMIT_CSV_UPPER_Msk      0xFFFF0000UL
/* CSV_HF_CSV.MON_CTL */
#define CSV_HF_CSV_MON_CTL_CSV_PERIOD_Pos       0UL
#define CSV_HF_CSV_MON_CTL_CSV_PERIOD_Msk       0xFFFFUL


/* CSV_REF_CSV.REF_CTL */
#define CSV_REF_CSV_REF_CTL_CSV_STARTUP_Pos     0UL
#define CSV_REF_CSV_REF_CTL_CSV_STARTUP_Msk     0xFFFFUL
#define CSV_REF_CSV_REF_CTL_CSV_ACTION_Pos      30UL
#define CSV_REF_CSV_REF_CTL_CSV_ACTION_Msk      0x40000000UL
#define CSV_REF_CSV_REF_CTL_CSV_EN_Pos          31UL
#define CSV_REF_CSV_REF_CTL_CSV_EN_Msk          0x80000000UL
/* CSV_REF_CSV.REF_LIMIT */
#define CSV_REF_CSV_REF_LIMIT_CSV_LOWER_Pos     0UL
#define CSV_REF_CSV_REF_LIMIT_CSV_LOWER_Msk     0xFFFFUL
#define CSV_REF_CSV_REF_LIMIT_CSV_UPPER_Pos     16UL
#define CSV_REF_CSV_REF_LIMIT_CSV_UPPER_Msk     0xFFFF0000UL
/* CSV_REF_CSV.MON_CTL */
#define CSV_REF_CSV_MON_CTL_CSV_PERIOD_Pos      0UL
#define CSV_REF_CSV_MON_CTL_CSV_PERIOD_Msk      0xFFFFUL


/* CSV_LF_CSV.REF_CTL */
#define CSV_LF_CSV_REF_CTL_CSV_STARTUP_Pos      0UL
#define CSV_LF_CSV_REF_CTL_CSV_STARTUP_Msk      0xFFUL
#define CSV_LF_CSV_REF_CTL_CSV_EN_Pos           31UL
#define CSV_LF_CSV_REF_CTL_CSV_EN_Msk           0x80000000UL
/* CSV_LF_CSV.REF_LIMIT */
#define CSV_LF_CSV_REF_LIMIT_CSV_LOWER_Pos      0UL
#define CSV_LF_CSV_REF_LIMIT_CSV_LOWER_Msk      0xFFUL
#define CSV_LF_CSV_REF_LIMIT_CSV_UPPER_Pos      16UL
#define CSV_LF_CSV_REF_LIMIT_CSV_UPPER_Msk      0xFF0000UL
/* CSV_LF_CSV.MON_CTL */
#define CSV_LF_CSV_MON_CTL_CSV_PERIOD_Pos       0UL
#define CSV_LF_CSV_MON_CTL_CSV_PERIOD_Msk       0xFFUL


/* CSV_PILO_CSV.REF_CTL */
#define CSV_PILO_CSV_REF_CTL_CSV_STARTUP_Pos    0UL
#define CSV_PILO_CSV_REF_CTL_CSV_STARTUP_Msk    0xFFUL
#define CSV_PILO_CSV_REF_CTL_CSV_EN_Pos         31UL
#define CSV_PILO_CSV_REF_CTL_CSV_EN_Msk         0x80000000UL
/* CSV_PILO_CSV.REF_LIMIT */
#define CSV_PILO_CSV_REF_LIMIT_CSV_LOWER_Pos    0UL
#define CSV_PILO_CSV_REF_LIMIT_CSV_LOWER_Msk    0xFFUL
#define CSV_PILO_CSV_REF_LIMIT_CSV_UPPER_Pos    16UL
#define CSV_PILO_CSV_REF_LIMIT_CSV_UPPER_Msk    0xFF0000UL
/* CSV_PILO_CSV.MON_CTL */
#define CSV_PILO_CSV_MON_CTL_CSV_PERIOD_Pos     0UL
#define CSV_PILO_CSV_MON_CTL_CSV_PERIOD_Msk     0xFFUL


/* CLK_DPLL_LP.CONFIG */
#define CLK_DPLL_LP_CONFIG_FEEDBACK_DIV_Pos     0UL
#define CLK_DPLL_LP_CONFIG_FEEDBACK_DIV_Msk     0xFFUL
#define CLK_DPLL_LP_CONFIG_REFERENCE_DIV_Pos    8UL
#define CLK_DPLL_LP_CONFIG_REFERENCE_DIV_Msk    0x1F00UL
#define CLK_DPLL_LP_CONFIG_OUTPUT_DIV_Pos       16UL
#define CLK_DPLL_LP_CONFIG_OUTPUT_DIV_Msk       0x1F0000UL
#define CLK_DPLL_LP_CONFIG_PLL_DCO_MODE_Pos     27UL
#define CLK_DPLL_LP_CONFIG_PLL_DCO_MODE_Msk     0x8000000UL
#define CLK_DPLL_LP_CONFIG_BYPASS_SEL_Pos       28UL
#define CLK_DPLL_LP_CONFIG_BYPASS_SEL_Msk       0x30000000UL
#define CLK_DPLL_LP_CONFIG_ENABLE_Pos           31UL
#define CLK_DPLL_LP_CONFIG_ENABLE_Msk           0x80000000UL
/* CLK_DPLL_LP.CONFIG2 */
#define CLK_DPLL_LP_CONFIG2_FRAC_DIV_Pos        0UL
#define CLK_DPLL_LP_CONFIG2_FRAC_DIV_Msk        0xFFFFFFUL
#define CLK_DPLL_LP_CONFIG2_FRAC_DITHER_EN_Pos  28UL
#define CLK_DPLL_LP_CONFIG2_FRAC_DITHER_EN_Msk  0x70000000UL
#define CLK_DPLL_LP_CONFIG2_FRAC_EN_Pos         31UL
#define CLK_DPLL_LP_CONFIG2_FRAC_EN_Msk         0x80000000UL
/* CLK_DPLL_LP.CONFIG3 */
#define CLK_DPLL_LP_CONFIG3_SSCG_DEPTH_Pos      0UL
#define CLK_DPLL_LP_CONFIG3_SSCG_DEPTH_Msk      0x3FFUL
#define CLK_DPLL_LP_CONFIG3_SSCG_RATE_Pos       16UL
#define CLK_DPLL_LP_CONFIG3_SSCG_RATE_Msk       0x70000UL
#define CLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN_Pos  24UL
#define CLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN_Msk  0x1000000UL
#define CLK_DPLL_LP_CONFIG3_SSCG_MODE_Pos       28UL
#define CLK_DPLL_LP_CONFIG3_SSCG_MODE_Msk       0x10000000UL
#define CLK_DPLL_LP_CONFIG3_SSCG_EN_Pos         31UL
#define CLK_DPLL_LP_CONFIG3_SSCG_EN_Msk         0x80000000UL
/* CLK_DPLL_LP.CONFIG4 */
#define CLK_DPLL_LP_CONFIG4_DCO_CODE_Pos        0UL
#define CLK_DPLL_LP_CONFIG4_DCO_CODE_Msk        0x7FFUL
#define CLK_DPLL_LP_CONFIG4_PLL_CS_PB2_DIS_Pos  13UL
#define CLK_DPLL_LP_CONFIG4_PLL_CS_PB2_DIS_Msk  0x2000UL
#define CLK_DPLL_LP_CONFIG4_PLL_TG_Pos          20UL
#define CLK_DPLL_LP_CONFIG4_PLL_TG_Msk          0x300000UL
#define CLK_DPLL_LP_CONFIG4_PLL_SP_Pos          24UL
#define CLK_DPLL_LP_CONFIG4_PLL_SP_Msk          0x1000000UL
/* CLK_DPLL_LP.CONFIG5 */
#define CLK_DPLL_LP_CONFIG5_KI_INT_Pos          0UL
#define CLK_DPLL_LP_CONFIG5_KI_INT_Msk          0x3FUL
#define CLK_DPLL_LP_CONFIG5_KP_INT_Pos          7UL
#define CLK_DPLL_LP_CONFIG5_KP_INT_Msk          0x1F80UL
#define CLK_DPLL_LP_CONFIG5_KI_ACC_INT_Pos      14UL
#define CLK_DPLL_LP_CONFIG5_KI_ACC_INT_Msk      0xFC000UL
#define CLK_DPLL_LP_CONFIG5_KP_ACC_INT_Pos      21UL
#define CLK_DPLL_LP_CONFIG5_KP_ACC_INT_Msk      0x7E00000UL
#define CLK_DPLL_LP_CONFIG5_PWRUP_ACC_INT_Pos   28UL
#define CLK_DPLL_LP_CONFIG5_PWRUP_ACC_INT_Msk   0x70000000UL
/* CLK_DPLL_LP.CONFIG6 */
#define CLK_DPLL_LP_CONFIG6_KI_FRACT_Pos        0UL
#define CLK_DPLL_LP_CONFIG6_KI_FRACT_Msk        0x3FUL
#define CLK_DPLL_LP_CONFIG6_KP_FRACT_Pos        7UL
#define CLK_DPLL_LP_CONFIG6_KP_FRACT_Msk        0x1F80UL
#define CLK_DPLL_LP_CONFIG6_KI_ACC_FRACT_Pos    14UL
#define CLK_DPLL_LP_CONFIG6_KI_ACC_FRACT_Msk    0xFC000UL
#define CLK_DPLL_LP_CONFIG6_KP_ACC_FRACT_Pos    21UL
#define CLK_DPLL_LP_CONFIG6_KP_ACC_FRACT_Msk    0x7E00000UL
#define CLK_DPLL_LP_CONFIG6_PWRUP_ACC_FRACT_Pos 28UL
#define CLK_DPLL_LP_CONFIG6_PWRUP_ACC_FRACT_Msk 0x70000000UL
/* CLK_DPLL_LP.CONFIG7 */
#define CLK_DPLL_LP_CONFIG7_KI_SSCG_Pos         0UL
#define CLK_DPLL_LP_CONFIG7_KI_SSCG_Msk         0x3FUL
#define CLK_DPLL_LP_CONFIG7_KP_SSCG_Pos         7UL
#define CLK_DPLL_LP_CONFIG7_KP_SSCG_Msk         0x1F80UL
#define CLK_DPLL_LP_CONFIG7_KI_ACC_SSCG_Pos     14UL
#define CLK_DPLL_LP_CONFIG7_KI_ACC_SSCG_Msk     0xFC000UL
#define CLK_DPLL_LP_CONFIG7_KP_ACC_SSCG_Pos     21UL
#define CLK_DPLL_LP_CONFIG7_KP_ACC_SSCG_Msk     0x7E00000UL
#define CLK_DPLL_LP_CONFIG7_PWRUP_ACC_SSCG_Pos  28UL
#define CLK_DPLL_LP_CONFIG7_PWRUP_ACC_SSCG_Msk  0x70000000UL
/* CLK_DPLL_LP.STATUS */
#define CLK_DPLL_LP_STATUS_LOCKED_Pos           0UL
#define CLK_DPLL_LP_STATUS_LOCKED_Msk           0x1UL
#define CLK_DPLL_LP_STATUS_UNLOCK_OCCURRED_Pos  1UL
#define CLK_DPLL_LP_STATUS_UNLOCK_OCCURRED_Msk  0x2UL


/* CLK_DPLL_HP.CONFIG */
#define CLK_DPLL_HP_CONFIG_PLL_FREQ_NDIV_INT_SEL_Pos 0UL
#define CLK_DPLL_HP_CONFIG_PLL_FREQ_NDIV_INT_SEL_Msk 0xFFUL
#define CLK_DPLL_HP_CONFIG_PLL_FREQ_PDIV_SEL_Pos 8UL
#define CLK_DPLL_HP_CONFIG_PLL_FREQ_PDIV_SEL_Msk 0x700UL
#define CLK_DPLL_HP_CONFIG_PLL_FREQ_KDIV_SEL_Pos 12UL
#define CLK_DPLL_HP_CONFIG_PLL_FREQ_KDIV_SEL_Msk 0x7000UL
#define CLK_DPLL_HP_CONFIG_BYPASS_SEL_Pos       28UL
#define CLK_DPLL_HP_CONFIG_BYPASS_SEL_Msk       0x30000000UL
#define CLK_DPLL_HP_CONFIG_ENABLE_Pos           31UL
#define CLK_DPLL_HP_CONFIG_ENABLE_Msk           0x80000000UL
/* CLK_DPLL_HP.CONFIG2 */
#define CLK_DPLL_HP_CONFIG2_PLL_FREQ_NDIV_FRACT_SEL_Pos 0UL
#define CLK_DPLL_HP_CONFIG2_PLL_FREQ_NDIV_FRACT_SEL_Msk 0x1FFFFFUL
#define CLK_DPLL_HP_CONFIG2_PLL_FREQ_MODE_SEL_Pos 21UL
#define CLK_DPLL_HP_CONFIG2_PLL_FREQ_MODE_SEL_Msk 0xE00000UL
#define CLK_DPLL_HP_CONFIG2_PLL_IVR_TRIM_Pos    24UL
#define CLK_DPLL_HP_CONFIG2_PLL_IVR_TRIM_Msk    0xF000000UL
/* CLK_DPLL_HP.CONFIG3 */
#define CLK_DPLL_HP_CONFIG3_PLL_CLKR_SEL_Pos    0UL
#define CLK_DPLL_HP_CONFIG3_PLL_CLKR_SEL_Msk    0x1UL
#define CLK_DPLL_HP_CONFIG3_PLL_FDSM_SEL_Pos    29UL
#define CLK_DPLL_HP_CONFIG3_PLL_FDSM_SEL_Msk    0x20000000UL
/* CLK_DPLL_HP.CONFIG4 */
#define CLK_DPLL_HP_CONFIG4_PLL_LF_LC_ALPHA_Pos 0UL
#define CLK_DPLL_HP_CONFIG4_PLL_LF_LC_ALPHA_Msk 0x1FUL
#define CLK_DPLL_HP_CONFIG4_PLL_LF_LC_BETA_Pos  5UL
#define CLK_DPLL_HP_CONFIG4_PLL_LF_LC_BETA_Msk  0x3E0UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_EN_THRESH_Pos 11UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_EN_THRESH_Msk 0x3800UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_WAITPER_Pos 16UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_WAITPER_Msk 0xF0000UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_THRESH_Pos 20UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_THRESH_Msk 0x700000UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_WAITPER_Pos 23UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_WAITPER_Msk 0x7800000UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_OBSWIN_Pos 27UL
#define CLK_DPLL_HP_CONFIG4_PLL_FLOCK_OBSWIN_Msk 0x78000000UL
/* CLK_DPLL_HP.CONFIG5 */
#define CLK_DPLL_HP_CONFIG5_PLL_LF_ALPHA_Pos    0UL
#define CLK_DPLL_HP_CONFIG5_PLL_LF_ALPHA_Msk    0x1FUL
#define CLK_DPLL_HP_CONFIG5_PLL_LF_BETA_Pos     5UL
#define CLK_DPLL_HP_CONFIG5_PLL_LF_BETA_Msk     0x3E0UL
#define CLK_DPLL_HP_CONFIG5_PLL_LF_SET_PARAMS_Pos 12UL
#define CLK_DPLL_HP_CONFIG5_PLL_LF_SET_PARAMS_Msk 0x1000UL
#define CLK_DPLL_HP_CONFIG5_PLL_DT_CAL_DIG_Pos  16UL
#define CLK_DPLL_HP_CONFIG5_PLL_DT_CAL_DIG_Msk  0x1FFF0000UL
/* CLK_DPLL_HP.TRIGMOD */
#define CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_FREQ_Pos 0UL
#define CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_FREQ_Msk 0xFFFFUL
#define CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_GRD_Pos  16UL
#define CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_GRD_Msk  0xFFFF0000UL
/* CLK_DPLL_HP.TRIGMOD2 */
#define CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_RATE_Pos 0UL
#define CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_RATE_Msk 0x7FFFFUL
#define CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_EN_Pos  20UL
#define CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_EN_Msk  0x100000UL
#define CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_STP_Pos 24UL
#define CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_STP_Msk 0x1000000UL
/* CLK_DPLL_HP.STATUS */
#define CLK_DPLL_HP_STATUS_LOCKED_Pos           0UL
#define CLK_DPLL_HP_STATUS_LOCKED_Msk           0x1UL
#define CLK_DPLL_HP_STATUS_UNLOCK_OCCURRED_Pos  1UL
#define CLK_DPLL_HP_STATUS_UNLOCK_OCCURRED_Msk  0x2UL
#define CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES_Pos  16UL
#define CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES_Msk  0x10000UL
#define CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES_ACK_Pos 20UL
#define CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES_ACK_Msk 0x100000UL
/* CLK_DPLL_HP.DUTYCAL_CTRL */
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_DELTA_Pos 0UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_DELTA_Msk 0x7UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_RATIO_OK_Pos 3UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_RATIO_OK_Msk 0x8UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_OK_Pos 4UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_OK_Msk 0x10UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_TARGET_Pos 16UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_TARGET_Msk 0x1FFF0000UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_CTRL_RG_EN_Pos 29UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_CTRL_RG_EN_Msk 0x20000000UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_EN_Pos 31UL
#define CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_EN_Msk 0x80000000UL


/* CLK_TRIM_DPLL_LP.DPLL_LP_CTL */
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_CYCLE_STOP_COLD_Pos 0UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_CYCLE_STOP_COLD_Msk 0xFUL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_CYCLE_STOP_FAST_Pos 4UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_CYCLE_STOP_FAST_Msk 0xF0UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_DIS_COLD_Pos 8UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_DIS_COLD_Msk 0x100UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_DIS_FAST_Pos 9UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_SAR_DIS_FAST_Msk 0x200UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_PLL_SAR_FSM_EN_Pos 10UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_PLL_SAR_FSM_EN_Msk 0x400UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_LDO_DCO_TRIM_Pos 12UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_LDO_DCO_TRIM_Msk 0x7000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_PLL_DCO_SD_SEL_Pos 16UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_PLL_DCO_SD_SEL_Msk 0x30000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_LDO_PERI_TRIM_Pos 19UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_LDO_PERI_TRIM_Msk 0x380000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_PLL_FRAC_ORDER_Pos 22UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_PLL_FRAC_ORDER_Msk 0xC00000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_ISOLATE_N_Pos 24UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_ISOLATE_N_Msk 0x1000000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_ISOLATE_CNT_Pos 25UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_ISOLATE_CNT_Msk 0x7E000000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_ENABLE_CNT_Pos 31UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL_ENABLE_CNT_Msk 0x80000000UL
/* CLK_TRIM_DPLL_LP.DPLL_LP_CTL3 */
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL3_PHASE_ACC_CNT_Pos 0UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL3_PHASE_ACC_CNT_Msk 0x1FFUL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL3_PHASE_ACC_CNT_SSCG_Pos 16UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL3_PHASE_ACC_CNT_SSCG_Msk 0x1FF0000UL
/* CLK_TRIM_DPLL_LP.DPLL_LP_CTL4 */
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL4_LOCK_WAIT_FALL_Pos 0UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL4_LOCK_WAIT_FALL_Msk 0x3UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL4_LOCK_WAIT_RISE_COLD_Pos 4UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL4_LOCK_WAIT_RISE_COLD_Msk 0xFF0UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL4_LOCK_WAIT_RISE_FAST_Pos 20UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_CTL4_LOCK_WAIT_RISE_FAST_Msk 0xFF00000UL
/* CLK_TRIM_DPLL_LP.DPLL_LP_TEST4 */
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PLL_USER_DCO_CODE_Pos 0UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PLL_USER_DCO_CODE_Msk 0x7FFUL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PLL_DIS_FAST_LOCK_Pos 14UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PLL_DIS_FAST_LOCK_Msk 0x4000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PLL_READ_EN_Pos 15UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PLL_READ_EN_Msk 0x8000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PHASE_ACC_USER_WRITE_INT_Pos 16UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PHASE_ACC_USER_WRITE_INT_Msk 0x3F0000UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PHASE_ACC_USER_WRITE_FRACT_Pos 23UL
#define CLK_TRIM_DPLL_LP_DPLL_LP_TEST4_PHASE_ACC_USER_WRITE_FRACT_Msk 0x1F800000UL


/* RAM_TRIM.TRIM_RAM_CTL */
#define RAM_TRIM_TRIM_RAM_CTL_TRIM_Pos          0UL
#define RAM_TRIM_TRIM_RAM_CTL_TRIM_Msk          0xFFFFFFFFUL


/* WDT.CTL */
#define WDT_CTL_ENABLED_Pos                     0UL
#define WDT_CTL_ENABLED_Msk                     0x1UL
#define WDT_CTL_ENABLE_Pos                      31UL
#define WDT_CTL_ENABLE_Msk                      0x80000000UL
/* WDT.LOWER_LIMIT */
#define WDT_LOWER_LIMIT_LOWER_LIMIT_Pos         0UL
#define WDT_LOWER_LIMIT_LOWER_LIMIT_Msk         0xFFFFFFFFUL
/* WDT.UPPER_LIMIT */
#define WDT_UPPER_LIMIT_UPPER_LIMIT_Pos         0UL
#define WDT_UPPER_LIMIT_UPPER_LIMIT_Msk         0xFFFFFFFFUL
/* WDT.WARN_LIMIT */
#define WDT_WARN_LIMIT_WARN_LIMIT_Pos           0UL
#define WDT_WARN_LIMIT_WARN_LIMIT_Msk           0xFFFFFFFFUL
/* WDT.CONFIG */
#define WDT_CONFIG_LOWER_ACTION_Pos             0UL
#define WDT_CONFIG_LOWER_ACTION_Msk             0x1UL
#define WDT_CONFIG_UPPER_ACTION_Pos             4UL
#define WDT_CONFIG_UPPER_ACTION_Msk             0x10UL
#define WDT_CONFIG_WARN_ACTION_Pos              8UL
#define WDT_CONFIG_WARN_ACTION_Msk              0x100UL
#define WDT_CONFIG_AUTO_SERVICE_Pos             12UL
#define WDT_CONFIG_AUTO_SERVICE_Msk             0x1000UL
#define WDT_CONFIG_DEBUG_TRIGGER_EN_Pos         28UL
#define WDT_CONFIG_DEBUG_TRIGGER_EN_Msk         0x10000000UL
#define WDT_CONFIG_DPSLP_PAUSE_Pos              29UL
#define WDT_CONFIG_DPSLP_PAUSE_Msk              0x20000000UL
#define WDT_CONFIG_HIB_PAUSE_Pos                30UL
#define WDT_CONFIG_HIB_PAUSE_Msk                0x40000000UL
#define WDT_CONFIG_DEBUG_RUN_Pos                31UL
#define WDT_CONFIG_DEBUG_RUN_Msk                0x80000000UL
/* WDT.CNT */
#define WDT_CNT_CNT_Pos                         0UL
#define WDT_CNT_CNT_Msk                         0xFFFFFFFFUL
/* WDT.LOCK */
#define WDT_LOCK_WDT_LOCK_Pos                   0UL
#define WDT_LOCK_WDT_LOCK_Msk                   0x3UL
/* WDT.SERVICE */
#define WDT_SERVICE_SERVICE_Pos                 0UL
#define WDT_SERVICE_SERVICE_Msk                 0x1UL
/* WDT.INTR */
#define WDT_INTR_WDT_Pos                        0UL
#define WDT_INTR_WDT_Msk                        0x1UL
/* WDT.INTR_SET */
#define WDT_INTR_SET_WDT_Pos                    0UL
#define WDT_INTR_SET_WDT_Msk                    0x1UL
/* WDT.INTR_MASK */
#define WDT_INTR_MASK_WDT_Pos                   0UL
#define WDT_INTR_MASK_WDT_Msk                   0x1UL
/* WDT.INTR_MASKED */
#define WDT_INTR_MASKED_WDT_Pos                 0UL
#define WDT_INTR_MASKED_WDT_Msk                 0x1UL


/* MCWDT_STRUCT.MCWDT_CNTLOW */
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR0_Pos  0UL
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR0_Msk  0xFFFFUL
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR1_Pos  16UL
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR1_Msk  0xFFFF0000UL
/* MCWDT_STRUCT.MCWDT_CNTHIGH */
#define MCWDT_STRUCT_MCWDT_CNTHIGH_WDT_CTR2_Pos 0UL
#define MCWDT_STRUCT_MCWDT_CNTHIGH_WDT_CTR2_Msk 0xFFFFFFFFUL
/* MCWDT_STRUCT.MCWDT_MATCH */
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH0_Msk 0xFFFFUL
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH1_Pos 16UL
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH1_Msk 0xFFFF0000UL
/* MCWDT_STRUCT.MCWDT_CONFIG */
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE0_Msk 0x3UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR0_Pos 2UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR0_Msk 0x4UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE0_1_Pos 3UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE0_1_Msk 0x8UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_LOWER_MODE0_Pos 4UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_LOWER_MODE0_Msk 0x30UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CARRY0_1_Pos 6UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CARRY0_1_Msk 0x40UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MATCH0_1_Pos 7UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MATCH0_1_Msk 0x80UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE1_Pos 8UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE1_Msk 0x300UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR1_Pos 10UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR1_Msk 0x400UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE1_2_Pos 11UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE1_2_Msk 0x800UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_LOWER_MODE1_Pos 12UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_LOWER_MODE1_Msk 0x3000UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CARRY1_2_Pos 14UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CARRY1_2_Msk 0x4000UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MATCH1_2_Pos 15UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MATCH1_2_Msk 0x8000UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE2_Pos 16UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE2_Msk 0x10000UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_BITS2_Pos 24UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_BITS2_Msk 0x1F000000UL
/* MCWDT_STRUCT.MCWDT_CTL */
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE0_Pos  0UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE0_Msk  0x1UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED0_Pos 1UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED0_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET0_Pos   3UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET0_Msk   0x8UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE1_Pos  8UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE1_Msk  0x100UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED1_Pos 9UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED1_Msk 0x200UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET1_Pos   11UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET1_Msk   0x800UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE2_Pos  16UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE2_Msk  0x10000UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED2_Pos 17UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED2_Msk 0x20000UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET2_Pos   19UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET2_Msk   0x80000UL
/* MCWDT_STRUCT.MCWDT_INTR */
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT0_Pos  0UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT0_Msk  0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT1_Pos  1UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT1_Msk  0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT2_Pos  2UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT2_Msk  0x4UL
/* MCWDT_STRUCT.MCWDT_INTR_SET */
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT0_Msk 0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT1_Pos 1UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT1_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT2_Pos 2UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT2_Msk 0x4UL
/* MCWDT_STRUCT.MCWDT_INTR_MASK */
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT0_Msk 0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT1_Pos 1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT1_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT2_Pos 2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT2_Msk 0x4UL
/* MCWDT_STRUCT.MCWDT_INTR_MASKED */
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT0_Msk 0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT1_Pos 1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT1_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT2_Pos 2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT2_Msk 0x4UL
/* MCWDT_STRUCT.MCWDT_LOCK */
#define MCWDT_STRUCT_MCWDT_LOCK_MCWDT_LOCK_Pos  30UL
#define MCWDT_STRUCT_MCWDT_LOCK_MCWDT_LOCK_Msk  0xC0000000UL
/* MCWDT_STRUCT.MCWDT_LOWER_LIMIT */
#define MCWDT_STRUCT_MCWDT_LOWER_LIMIT_WDT_LOWER_LIMIT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_LOWER_LIMIT_WDT_LOWER_LIMIT0_Msk 0xFFFFUL
#define MCWDT_STRUCT_MCWDT_LOWER_LIMIT_WDT_LOWER_LIMIT1_Pos 16UL
#define MCWDT_STRUCT_MCWDT_LOWER_LIMIT_WDT_LOWER_LIMIT1_Msk 0xFFFF0000UL


/* MCWDT_CTR.CTL */
#define MCWDT_CTR_CTL_ENABLED_Pos               0UL
#define MCWDT_CTR_CTL_ENABLED_Msk               0x1UL
#define MCWDT_CTR_CTL_ENABLE_Pos                31UL
#define MCWDT_CTR_CTL_ENABLE_Msk                0x80000000UL
/* MCWDT_CTR.LOWER_LIMIT */
#define MCWDT_CTR_LOWER_LIMIT_LOWER_LIMIT_Pos   0UL
#define MCWDT_CTR_LOWER_LIMIT_LOWER_LIMIT_Msk   0xFFFFUL
/* MCWDT_CTR.UPPER_LIMIT */
#define MCWDT_CTR_UPPER_LIMIT_UPPER_LIMIT_Pos   0UL
#define MCWDT_CTR_UPPER_LIMIT_UPPER_LIMIT_Msk   0xFFFFUL
/* MCWDT_CTR.WARN_LIMIT */
#define MCWDT_CTR_WARN_LIMIT_WARN_LIMIT_Pos     0UL
#define MCWDT_CTR_WARN_LIMIT_WARN_LIMIT_Msk     0xFFFFUL
/* MCWDT_CTR.CONFIG */
#define MCWDT_CTR_CONFIG_LOWER_ACTION_Pos       0UL
#define MCWDT_CTR_CONFIG_LOWER_ACTION_Msk       0x3UL
#define MCWDT_CTR_CONFIG_UPPER_ACTION_Pos       4UL
#define MCWDT_CTR_CONFIG_UPPER_ACTION_Msk       0x30UL
#define MCWDT_CTR_CONFIG_WARN_ACTION_Pos        8UL
#define MCWDT_CTR_CONFIG_WARN_ACTION_Msk        0x100UL
#define MCWDT_CTR_CONFIG_AUTO_SERVICE_Pos       12UL
#define MCWDT_CTR_CONFIG_AUTO_SERVICE_Msk       0x1000UL
#define MCWDT_CTR_CONFIG_DEBUG_TRIGGER_EN_Pos   28UL
#define MCWDT_CTR_CONFIG_DEBUG_TRIGGER_EN_Msk   0x10000000UL
#define MCWDT_CTR_CONFIG_SLEEPDEEP_PAUSE_Pos    30UL
#define MCWDT_CTR_CONFIG_SLEEPDEEP_PAUSE_Msk    0x40000000UL
#define MCWDT_CTR_CONFIG_DEBUG_RUN_Pos          31UL
#define MCWDT_CTR_CONFIG_DEBUG_RUN_Msk          0x80000000UL
/* MCWDT_CTR.CNT */
#define MCWDT_CTR_CNT_CNT_Pos                   0UL
#define MCWDT_CTR_CNT_CNT_Msk                   0xFFFFUL


/* MCWDT.CPU_SELECT */
#define MCWDT_CPU_SELECT_CPU_SEL_Pos            0UL
#define MCWDT_CPU_SELECT_CPU_SEL_Msk            0x3UL
/* MCWDT.CTR2_CTL */
#define MCWDT_CTR2_CTL_ENABLED_Pos              0UL
#define MCWDT_CTR2_CTL_ENABLED_Msk              0x1UL
#define MCWDT_CTR2_CTL_ENABLE_Pos               31UL
#define MCWDT_CTR2_CTL_ENABLE_Msk               0x80000000UL
/* MCWDT.CTR2_CONFIG */
#define MCWDT_CTR2_CONFIG_ACTION_Pos            0UL
#define MCWDT_CTR2_CONFIG_ACTION_Msk            0x1UL
#define MCWDT_CTR2_CONFIG_BITS_Pos              16UL
#define MCWDT_CTR2_CONFIG_BITS_Msk              0x1F0000UL
#define MCWDT_CTR2_CONFIG_DEBUG_TRIGGER_EN_Pos  28UL
#define MCWDT_CTR2_CONFIG_DEBUG_TRIGGER_EN_Msk  0x10000000UL
#define MCWDT_CTR2_CONFIG_SLEEPDEEP_PAUSE_Pos   30UL
#define MCWDT_CTR2_CONFIG_SLEEPDEEP_PAUSE_Msk   0x40000000UL
#define MCWDT_CTR2_CONFIG_DEBUG_RUN_Pos         31UL
#define MCWDT_CTR2_CONFIG_DEBUG_RUN_Msk         0x80000000UL
/* MCWDT.CTR2_CNT */
#define MCWDT_CTR2_CNT_CNT2_Pos                 0UL
#define MCWDT_CTR2_CNT_CNT2_Msk                 0xFFFFFFFFUL
/* MCWDT.LOCK */
#define MCWDT_LOCK_MCWDT_LOCK_Pos               0UL
#define MCWDT_LOCK_MCWDT_LOCK_Msk               0x3UL
/* MCWDT.SERVICE */
#define MCWDT_SERVICE_CTR0_SERVICE_Pos          0UL
#define MCWDT_SERVICE_CTR0_SERVICE_Msk          0x1UL
#define MCWDT_SERVICE_CTR1_SERVICE_Pos          1UL
#define MCWDT_SERVICE_CTR1_SERVICE_Msk          0x2UL
/* MCWDT.INTR */
#define MCWDT_INTR_CTR0_INT_Pos                 0UL
#define MCWDT_INTR_CTR0_INT_Msk                 0x1UL
#define MCWDT_INTR_CTR1_INT_Pos                 1UL
#define MCWDT_INTR_CTR1_INT_Msk                 0x2UL
#define MCWDT_INTR_CTR2_INT_Pos                 2UL
#define MCWDT_INTR_CTR2_INT_Msk                 0x4UL
/* MCWDT.INTR_SET */
#define MCWDT_INTR_SET_CTR0_INT_Pos             0UL
#define MCWDT_INTR_SET_CTR0_INT_Msk             0x1UL
#define MCWDT_INTR_SET_CTR1_INT_Pos             1UL
#define MCWDT_INTR_SET_CTR1_INT_Msk             0x2UL
#define MCWDT_INTR_SET_CTR2_INT_Pos             2UL
#define MCWDT_INTR_SET_CTR2_INT_Msk             0x4UL
/* MCWDT.INTR_MASK */
#define MCWDT_INTR_MASK_CTR0_INT_Pos            0UL
#define MCWDT_INTR_MASK_CTR0_INT_Msk            0x1UL
#define MCWDT_INTR_MASK_CTR1_INT_Pos            1UL
#define MCWDT_INTR_MASK_CTR1_INT_Msk            0x2UL
#define MCWDT_INTR_MASK_CTR2_INT_Pos            2UL
#define MCWDT_INTR_MASK_CTR2_INT_Msk            0x4UL
/* MCWDT.INTR_MASKED */
#define MCWDT_INTR_MASKED_CTR0_INT_Pos          0UL
#define MCWDT_INTR_MASKED_CTR0_INT_Msk          0x1UL
#define MCWDT_INTR_MASKED_CTR1_INT_Pos          1UL
#define MCWDT_INTR_MASKED_CTR1_INT_Msk          0x2UL
#define MCWDT_INTR_MASKED_CTR2_INT_Pos          2UL
#define MCWDT_INTR_MASKED_CTR2_INT_Msk          0x4UL


/* SRSS.CLK_DSI_SELECT */
#define SRSS_CLK_DSI_SELECT_DSI_MUX_Pos         0UL
#define SRSS_CLK_DSI_SELECT_DSI_MUX_Msk         0x1FUL
/* SRSS.CLK_OUTPUT_FAST */
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Pos      0UL
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Msk      0xFUL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL0_Pos      4UL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL0_Msk      0xF0UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0_Pos     8UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0_Msk     0xF00UL
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Pos      16UL
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Msk      0xF0000UL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL1_Pos      20UL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL1_Msk      0xF00000UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1_Pos     24UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1_Msk     0xF000000UL
/* SRSS.CLK_OUTPUT_SLOW */
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0_Pos      0UL
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0_Msk      0xFUL
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1_Pos      4UL
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1_Msk      0xF0UL
/* SRSS.CLK_CAL_CNT1 */
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER1_Pos      0UL
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER1_Msk      0xFFFFFFUL
#define SRSS_CLK_CAL_CNT1_CAL_RESET_Pos         29UL
#define SRSS_CLK_CAL_CNT1_CAL_RESET_Msk         0x20000000UL
#define SRSS_CLK_CAL_CNT1_CAL_CLK1_PRESENT_Pos  30UL
#define SRSS_CLK_CAL_CNT1_CAL_CLK1_PRESENT_Msk  0x40000000UL
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE_Pos  31UL
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE_Msk  0x80000000UL
/* SRSS.CLK_CAL_CNT2 */
#define SRSS_CLK_CAL_CNT2_CAL_COUNTER2_Pos      0UL
#define SRSS_CLK_CAL_CNT2_CAL_COUNTER2_Msk      0xFFFFFFUL
/* SRSS.SRSS_INTR */
#define SRSS_SRSS_INTR_WDT_MATCH_Pos            0UL
#define SRSS_SRSS_INTR_WDT_MATCH_Msk            0x1UL
#define SRSS_SRSS_INTR_CLK_CAL_Pos              5UL
#define SRSS_SRSS_INTR_CLK_CAL_Msk              0x20UL
#define SRSS_SRSS_INTR_CSV_LF_Pos               8UL
#define SRSS_SRSS_INTR_CSV_LF_Msk               0x100UL
#define SRSS_SRSS_INTR_CSV_PILO_Pos             9UL
#define SRSS_SRSS_INTR_CSV_PILO_Msk             0x200UL
#define SRSS_SRSS_INTR_AINTR_Pos                31UL
#define SRSS_SRSS_INTR_AINTR_Msk                0x80000000UL
/* SRSS.SRSS_INTR_SET */
#define SRSS_SRSS_INTR_SET_WDT_MATCH_Pos        0UL
#define SRSS_SRSS_INTR_SET_WDT_MATCH_Msk        0x1UL
#define SRSS_SRSS_INTR_SET_CLK_CAL_Pos          5UL
#define SRSS_SRSS_INTR_SET_CLK_CAL_Msk          0x20UL
#define SRSS_SRSS_INTR_SET_CSV_LF_Pos           8UL
#define SRSS_SRSS_INTR_SET_CSV_LF_Msk           0x100UL
#define SRSS_SRSS_INTR_SET_CSV_PILO_Pos         9UL
#define SRSS_SRSS_INTR_SET_CSV_PILO_Msk         0x200UL
/* SRSS.SRSS_INTR_MASK */
#define SRSS_SRSS_INTR_MASK_WDT_MATCH_Pos       0UL
#define SRSS_SRSS_INTR_MASK_WDT_MATCH_Msk       0x1UL
#define SRSS_SRSS_INTR_MASK_CLK_CAL_Pos         5UL
#define SRSS_SRSS_INTR_MASK_CLK_CAL_Msk         0x20UL
#define SRSS_SRSS_INTR_MASK_CSV_LF_Pos          8UL
#define SRSS_SRSS_INTR_MASK_CSV_LF_Msk          0x100UL
#define SRSS_SRSS_INTR_MASK_CSV_PILO_Pos        9UL
#define SRSS_SRSS_INTR_MASK_CSV_PILO_Msk        0x200UL
/* SRSS.SRSS_INTR_MASKED */
#define SRSS_SRSS_INTR_MASKED_WDT_MATCH_Pos     0UL
#define SRSS_SRSS_INTR_MASKED_WDT_MATCH_Msk     0x1UL
#define SRSS_SRSS_INTR_MASKED_CLK_CAL_Pos       5UL
#define SRSS_SRSS_INTR_MASKED_CLK_CAL_Msk       0x20UL
#define SRSS_SRSS_INTR_MASKED_CSV_LF_Pos        8UL
#define SRSS_SRSS_INTR_MASKED_CSV_LF_Msk        0x100UL
#define SRSS_SRSS_INTR_MASKED_CSV_PILO_Pos      9UL
#define SRSS_SRSS_INTR_MASKED_CSV_PILO_Msk      0x200UL
#define SRSS_SRSS_INTR_MASKED_AINTR_Pos         31UL
#define SRSS_SRSS_INTR_MASKED_AINTR_Msk         0x80000000UL
/* SRSS.SRSS_AINTR */
#define SRSS_SRSS_AINTR_OVDVCCD_Pos             0UL
#define SRSS_SRSS_AINTR_OVDVCCD_Msk             0x1UL
#define SRSS_SRSS_AINTR_HVLVD_Pos               1UL
#define SRSS_SRSS_AINTR_HVLVD_Msk               0x2UL
/* SRSS.SRSS_AINTR_SET */
#define SRSS_SRSS_AINTR_SET_OVDVCCD_Pos         0UL
#define SRSS_SRSS_AINTR_SET_OVDVCCD_Msk         0x1UL
#define SRSS_SRSS_AINTR_SET_HVLVD_Pos           1UL
#define SRSS_SRSS_AINTR_SET_HVLVD_Msk           0x2UL
/* SRSS.SRSS_AINTR_MASK */
#define SRSS_SRSS_AINTR_MASK_OVDVCCD_Pos        0UL
#define SRSS_SRSS_AINTR_MASK_OVDVCCD_Msk        0x1UL
#define SRSS_SRSS_AINTR_MASK_HVLVD_Pos          1UL
#define SRSS_SRSS_AINTR_MASK_HVLVD_Msk          0x2UL
/* SRSS.SRSS_AINTR_MASKED */
#define SRSS_SRSS_AINTR_MASKED_OVDVCCD_Pos      0UL
#define SRSS_SRSS_AINTR_MASKED_OVDVCCD_Msk      0x1UL
#define SRSS_SRSS_AINTR_MASKED_HVLVD_Pos        1UL
#define SRSS_SRSS_AINTR_MASKED_HVLVD_Msk        0x2UL
/* SRSS.PWR_LVD_STATUS */
#define SRSS_PWR_LVD_STATUS_HVLVD_OK_Pos        0UL
#define SRSS_PWR_LVD_STATUS_HVLVD_OK_Msk        0x1UL
/* SRSS.BOOT_DLM_CTL */
#define SRSS_BOOT_DLM_CTL_REQUEST_Pos           0UL
#define SRSS_BOOT_DLM_CTL_REQUEST_Msk           0xFUL
#define SRSS_BOOT_DLM_CTL_INPUT_AVAIL_Pos       29UL
#define SRSS_BOOT_DLM_CTL_INPUT_AVAIL_Msk       0x20000000UL
#define SRSS_BOOT_DLM_CTL_RESET_Pos             30UL
#define SRSS_BOOT_DLM_CTL_RESET_Msk             0x40000000UL
#define SRSS_BOOT_DLM_CTL_WFA_Pos               31UL
#define SRSS_BOOT_DLM_CTL_WFA_Msk               0x80000000UL
/* SRSS.BOOT_DLM_CTL2 */
#define SRSS_BOOT_DLM_CTL2_APP_CTL_Pos          0UL
#define SRSS_BOOT_DLM_CTL2_APP_CTL_Msk          0xFFFFFFFFUL
/* SRSS.BOOT_DLM_STATUS */
#define SRSS_BOOT_DLM_STATUS_DEBUG_STATUS_Pos   0UL
#define SRSS_BOOT_DLM_STATUS_DEBUG_STATUS_Msk   0xFFFFFFFFUL
/* SRSS.RES_SOFT_CTL */
#define SRSS_RES_SOFT_CTL_TRIGGER_SOFT_Pos      0UL
#define SRSS_RES_SOFT_CTL_TRIGGER_SOFT_Msk      0x1UL
/* SRSS.BOOT_STATUS */
#define SRSS_BOOT_STATUS_DEBUG_STATUS_Pos       0UL
#define SRSS_BOOT_STATUS_DEBUG_STATUS_Msk       0xFFFFFFFFUL
/* SRSS.BOOT_ENTRY */
#define SRSS_BOOT_ENTRY_WARM_BOOT_ENTRY_Pos     0UL
#define SRSS_BOOT_ENTRY_WARM_BOOT_ENTRY_Msk     0xFFFFFFFFUL
/* SRSS.DECODED_LCS_DATA */
#define SRSS_DECODED_LCS_DATA_K_CODE_Pos        0UL
#define SRSS_DECODED_LCS_DATA_K_CODE_Msk        0x3UL
#define SRSS_DECODED_LCS_DATA_P_CODE_Pos        2UL
#define SRSS_DECODED_LCS_DATA_P_CODE_Msk        0xCUL
#define SRSS_DECODED_LCS_DATA_S_CODE_Pos        4UL
#define SRSS_DECODED_LCS_DATA_S_CODE_Msk        0x30UL
#define SRSS_DECODED_LCS_DATA_N_CODE_Pos        6UL
#define SRSS_DECODED_LCS_DATA_N_CODE_Msk        0xC0UL
#define SRSS_DECODED_LCS_DATA_R_CODE_Pos        8UL
#define SRSS_DECODED_LCS_DATA_R_CODE_Msk        0x300UL
#define SRSS_DECODED_LCS_DATA_B_CODE_Pos        10UL
#define SRSS_DECODED_LCS_DATA_B_CODE_Msk        0xC00UL
/* SRSS.PWR_HIB_DATA */
#define SRSS_PWR_HIB_DATA_HIB_DATA_Pos          0UL
#define SRSS_PWR_HIB_DATA_HIB_DATA_Msk          0xFFFFFFFFUL
/* SRSS.PWR_HIB_WAKE_CTL */
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC_Pos  0UL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC_Msk  0xFFFFFFUL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_CSV_BAK_Pos 29UL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_CSV_BAK_Msk 0x20000000UL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Pos  30UL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk  0x40000000UL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Pos  31UL
#define SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk  0x80000000UL
/* SRSS.PWR_HIB_WAKE_CTL2 */
#define SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC_Pos 0UL
#define SRSS_PWR_HIB_WAKE_CTL2_HIB_WAKE_SRC_Msk 0xFFFFFFUL
/* SRSS.PWR_HIB_WAKE_CAUSE */
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_SRC_Pos 0UL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_SRC_Msk 0xFFFFFFUL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_CSV_BAK_Pos 29UL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_CSV_BAK_Msk 0x20000000UL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_RTC_Pos 30UL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_RTC_Msk 0x40000000UL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_WDT_Pos 31UL
#define SRSS_PWR_HIB_WAKE_CAUSE_HIB_WAKE_WDT_Msk 0x80000000UL
/* SRSS.TST_XRES_SECURE */
#define SRSS_TST_XRES_SECURE_DATA8_Pos          0UL
#define SRSS_TST_XRES_SECURE_DATA8_Msk          0xFFUL
#define SRSS_TST_XRES_SECURE_FW_WR_Pos          8UL
#define SRSS_TST_XRES_SECURE_FW_WR_Msk          0xF00UL
#define SRSS_TST_XRES_SECURE_SECURE_WR_Pos      16UL
#define SRSS_TST_XRES_SECURE_SECURE_WR_Msk      0xF0000UL
#define SRSS_TST_XRES_SECURE_FW_KEY_OK_Pos      29UL
#define SRSS_TST_XRES_SECURE_FW_KEY_OK_Msk      0x20000000UL
#define SRSS_TST_XRES_SECURE_SECURE_KEY_OK_Pos  30UL
#define SRSS_TST_XRES_SECURE_SECURE_KEY_OK_Msk  0x40000000UL
#define SRSS_TST_XRES_SECURE_SECURE_DISABLE_Pos 31UL
#define SRSS_TST_XRES_SECURE_SECURE_DISABLE_Msk 0x80000000UL
/* SRSS.PWR_CTL */
#define SRSS_PWR_CTL_DEBUG_SESSION_Pos          4UL
#define SRSS_PWR_CTL_DEBUG_SESSION_Msk          0x10UL
#define SRSS_PWR_CTL_LPM_READY_Pos              5UL
#define SRSS_PWR_CTL_LPM_READY_Msk              0x20UL
/* SRSS.PWR_CTL2 */
#define SRSS_PWR_CTL2_REFSYS_VREF_OK_Pos        17UL
#define SRSS_PWR_CTL2_REFSYS_VREF_OK_Msk        0x20000UL
#define SRSS_PWR_CTL2_REFSYS_VBUF_DIS_Pos       20UL
#define SRSS_PWR_CTL2_REFSYS_VBUF_DIS_Msk       0x100000UL
#define SRSS_PWR_CTL2_REFSYS_VREFBUF_OK_Pos     21UL
#define SRSS_PWR_CTL2_REFSYS_VREFBUF_OK_Msk     0x200000UL
#define SRSS_PWR_CTL2_REFSYS_IREF_OK_Pos        25UL
#define SRSS_PWR_CTL2_REFSYS_IREF_OK_Msk        0x2000000UL
#define SRSS_PWR_CTL2_PORBOD_LPMODE_Pos         27UL
#define SRSS_PWR_CTL2_PORBOD_LPMODE_Msk         0x8000000UL
#define SRSS_PWR_CTL2_BGREF_LPMODE_Pos          28UL
#define SRSS_PWR_CTL2_BGREF_LPMODE_Msk          0x10000000UL
#define SRSS_PWR_CTL2_FREEZE_DPSLP_Pos          30UL
#define SRSS_PWR_CTL2_FREEZE_DPSLP_Msk          0x40000000UL
#define SRSS_PWR_CTL2_FREEZE_DPSLP_PD1_Pos      31UL
#define SRSS_PWR_CTL2_FREEZE_DPSLP_PD1_Msk      0x80000000UL
/* SRSS.PWR_HIBERNATE */
#define SRSS_PWR_HIBERNATE_TOKEN_Pos            0UL
#define SRSS_PWR_HIBERNATE_TOKEN_Msk            0xFFUL
#define SRSS_PWR_HIBERNATE_UNLOCK_Pos           8UL
#define SRSS_PWR_HIBERNATE_UNLOCK_Msk           0xFF00UL
#define SRSS_PWR_HIBERNATE_FREEZE_Pos           17UL
#define SRSS_PWR_HIBERNATE_FREEZE_Msk           0x20000UL
#define SRSS_PWR_HIBERNATE_MASK_HIBALARM_Pos    18UL
#define SRSS_PWR_HIBERNATE_MASK_HIBALARM_Msk    0x40000UL
#define SRSS_PWR_HIBERNATE_MASK_HIBWDT_Pos      19UL
#define SRSS_PWR_HIBERNATE_MASK_HIBWDT_Msk      0x80000UL
#define SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Pos  20UL
#define SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Msk  0xF00000UL
#define SRSS_PWR_HIBERNATE_MASK_HIBPIN_Pos      24UL
#define SRSS_PWR_HIBERNATE_MASK_HIBPIN_Msk      0xF000000UL
#define SRSS_PWR_HIBERNATE_SENSE_MODE_Pos       29UL
#define SRSS_PWR_HIBERNATE_SENSE_MODE_Msk       0x20000000UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_DISABLE_Pos 30UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_DISABLE_Msk 0x40000000UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_Pos        31UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_Msk        0x80000000UL
/* SRSS.PWR_LVD_CTL */
#define SRSS_PWR_LVD_CTL_HVLVD_TRIPSEL_Pos      0UL
#define SRSS_PWR_LVD_CTL_HVLVD_TRIPSEL_Msk      0xFUL
#define SRSS_PWR_LVD_CTL_HVLVD_DPSLP_EN_Pos     6UL
#define SRSS_PWR_LVD_CTL_HVLVD_DPSLP_EN_Msk     0x40UL
#define SRSS_PWR_LVD_CTL_HVLVD_EN_Pos           7UL
#define SRSS_PWR_LVD_CTL_HVLVD_EN_Msk           0x80UL
#define SRSS_PWR_LVD_CTL_HVLVD_EDGE_SEL_Pos     16UL
#define SRSS_PWR_LVD_CTL_HVLVD_EDGE_SEL_Msk     0x30000UL
#define SRSS_PWR_LVD_CTL_HVLVD_ACTION_Pos       18UL
#define SRSS_PWR_LVD_CTL_HVLVD_ACTION_Msk       0x40000UL
/* SRSS.CLK_PATH_SELECT */
#define SRSS_CLK_PATH_SELECT_PATH_MUX_Pos       0UL
#define SRSS_CLK_PATH_SELECT_PATH_MUX_Msk       0x7UL
/* SRSS.CLK_ROOT_SELECT */
#define SRSS_CLK_ROOT_SELECT_ROOT_MUX_Pos       0UL
#define SRSS_CLK_ROOT_SELECT_ROOT_MUX_Msk       0xFUL
#define SRSS_CLK_ROOT_SELECT_ROOT_DIV_Pos       8UL
#define SRSS_CLK_ROOT_SELECT_ROOT_DIV_Msk       0xF00UL
#define SRSS_CLK_ROOT_SELECT_ENABLE_Pos         31UL
#define SRSS_CLK_ROOT_SELECT_ENABLE_Msk         0x80000000UL
/* SRSS.CLK_DIRECT_SELECT */
#define SRSS_CLK_DIRECT_SELECT_DIRECT_MUX_Pos   8UL
#define SRSS_CLK_DIRECT_SELECT_DIRECT_MUX_Msk   0x100UL
/* SRSS.CLK_SELECT */
#define SRSS_CLK_SELECT_LFCLK_SEL_Pos           0UL
#define SRSS_CLK_SELECT_LFCLK_SEL_Msk           0x7UL
/* SRSS.CLK_MF_SELECT */
#define SRSS_CLK_MF_SELECT_MFCLK_SEL_Pos        0UL
#define SRSS_CLK_MF_SELECT_MFCLK_SEL_Msk        0x7UL
#define SRSS_CLK_MF_SELECT_MFCLK_DIV_Pos        8UL
#define SRSS_CLK_MF_SELECT_MFCLK_DIV_Msk        0xFF00UL
#define SRSS_CLK_MF_SELECT_ENABLE_Pos           31UL
#define SRSS_CLK_MF_SELECT_ENABLE_Msk           0x80000000UL
/* SRSS.CLK_ALTHF_CTL */
#define SRSS_CLK_ALTHF_CTL_ALTHF_ENABLED_Pos    0UL
#define SRSS_CLK_ALTHF_CTL_ALTHF_ENABLED_Msk    0x1UL
#define SRSS_CLK_ALTHF_CTL_ALTHF_ENABLE_Pos     31UL
#define SRSS_CLK_ALTHF_CTL_ALTHF_ENABLE_Msk     0x80000000UL
/* SRSS.CLK_ECO_PRESCALE */
#define SRSS_CLK_ECO_PRESCALE_ECO_DIV_ENABLED_Pos 0UL
#define SRSS_CLK_ECO_PRESCALE_ECO_DIV_ENABLED_Msk 0x1UL
#define SRSS_CLK_ECO_PRESCALE_ECO_FRAC_DIV_Pos  8UL
#define SRSS_CLK_ECO_PRESCALE_ECO_FRAC_DIV_Msk  0xFF00UL
#define SRSS_CLK_ECO_PRESCALE_ECO_INT_DIV_Pos   16UL
#define SRSS_CLK_ECO_PRESCALE_ECO_INT_DIV_Msk   0x3FF0000UL
/* SRSS.CLK_IMO_CONFIG */
#define SRSS_CLK_IMO_CONFIG_DPSLP_ENABLE_Pos    30UL
#define SRSS_CLK_IMO_CONFIG_DPSLP_ENABLE_Msk    0x40000000UL
#define SRSS_CLK_IMO_CONFIG_ENABLE_Pos          31UL
#define SRSS_CLK_IMO_CONFIG_ENABLE_Msk          0x80000000UL
/* SRSS.CLK_IHO_CONFIG */
#define SRSS_CLK_IHO_CONFIG_IHO_TRIM_FREQ_Pos   0UL
#define SRSS_CLK_IHO_CONFIG_IHO_TRIM_FREQ_Msk   0x7FFUL
#define SRSS_CLK_IHO_CONFIG_DPSLP_ENABLE_Pos    30UL
#define SRSS_CLK_IHO_CONFIG_DPSLP_ENABLE_Msk    0x40000000UL
/* SRSS.CLK_PILO_CONFIG */
#define SRSS_CLK_PILO_CONFIG_PILO_EN_Pos        31UL
#define SRSS_CLK_PILO_CONFIG_PILO_EN_Msk        0x80000000UL
/* SRSS.CLK_PILO_STATUS */
#define SRSS_CLK_PILO_STATUS_PILO_OK_Pos        0UL
#define SRSS_CLK_PILO_STATUS_PILO_OK_Msk        0x1UL
/* SRSS.CLK_ILO_CONFIG */
#define SRSS_CLK_ILO_CONFIG_ENABLE_Pos          31UL
#define SRSS_CLK_ILO_CONFIG_ENABLE_Msk          0x80000000UL
/* SRSS.CLK_TRIM_ILO_CTL */
#define SRSS_CLK_TRIM_ILO_CTL_ILO_FTRIM_Pos     0UL
#define SRSS_CLK_TRIM_ILO_CTL_ILO_FTRIM_Msk     0x3FUL
/* SRSS.CLK_WCO_CONFIG */
#define SRSS_CLK_WCO_CONFIG_WCO_EN_Pos          3UL
#define SRSS_CLK_WCO_CONFIG_WCO_EN_Msk          0x8UL
#define SRSS_CLK_WCO_CONFIG_CLK_RTC_SEL_Pos     8UL
#define SRSS_CLK_WCO_CONFIG_CLK_RTC_SEL_Msk     0x700UL
#define SRSS_CLK_WCO_CONFIG_PRESCALER_Pos       12UL
#define SRSS_CLK_WCO_CONFIG_PRESCALER_Msk       0x3000UL
#define SRSS_CLK_WCO_CONFIG_WCO_BYPASS_Pos      16UL
#define SRSS_CLK_WCO_CONFIG_WCO_BYPASS_Msk      0x10000UL
#define SRSS_CLK_WCO_CONFIG_WCO_TRIM_GAIN_Pos   20UL
#define SRSS_CLK_WCO_CONFIG_WCO_TRIM_GAIN_Msk   0xF00000UL
#define SRSS_CLK_WCO_CONFIG_WCO_CTRL_PWRMOD_Pos 24UL
#define SRSS_CLK_WCO_CONFIG_WCO_CTRL_PWRMOD_Msk 0x3000000UL
/* SRSS.CLK_WCO_STATUS */
#define SRSS_CLK_WCO_STATUS_WCO_OK_Pos          2UL
#define SRSS_CLK_WCO_STATUS_WCO_OK_Msk          0x4UL
/* SRSS.CSV_REF_SEL */
#define SRSS_CSV_REF_SEL_REF_MUX_Pos            0UL
#define SRSS_CSV_REF_SEL_REF_MUX_Msk            0x7UL
/* SRSS.CSV_LF_REF_SEL */
#define SRSS_CSV_LF_REF_SEL_LF_REF_MUX_Pos      0UL
#define SRSS_CSV_LF_REF_SEL_LF_REF_MUX_Msk      0x3UL
/* SRSS.CSV_PILO_REF_SEL */
#define SRSS_CSV_PILO_REF_SEL_PILO_REF_MUX_Pos  0UL
#define SRSS_CSV_PILO_REF_SEL_PILO_REF_MUX_Msk  0x3UL
/* SRSS.RES_CAUSE */
#define SRSS_RES_CAUSE_RESET_WDT_Pos            0UL
#define SRSS_RES_CAUSE_RESET_WDT_Msk            0x1UL
#define SRSS_RES_CAUSE_RESET_ACT_FAULT_Pos      1UL
#define SRSS_RES_CAUSE_RESET_ACT_FAULT_Msk      0x2UL
#define SRSS_RES_CAUSE_RESET_DPSLP_FAULT_Pos    2UL
#define SRSS_RES_CAUSE_RESET_DPSLP_FAULT_Msk    0x4UL
#define SRSS_RES_CAUSE_RESET_TC_DBGRESET_Pos    3UL
#define SRSS_RES_CAUSE_RESET_TC_DBGRESET_Msk    0x8UL
#define SRSS_RES_CAUSE_RESET_SOFT_Pos           4UL
#define SRSS_RES_CAUSE_RESET_SOFT_Msk           0x10UL
#define SRSS_RES_CAUSE_RESET_SOFT1_Pos          5UL
#define SRSS_RES_CAUSE_RESET_SOFT1_Msk          0x20UL
#define SRSS_RES_CAUSE_RESET_SOFT2_Pos          6UL
#define SRSS_RES_CAUSE_RESET_SOFT2_Msk          0x40UL
#define SRSS_RES_CAUSE_RESET_MCWDT0_Pos         8UL
#define SRSS_RES_CAUSE_RESET_MCWDT0_Msk         0x100UL
#define SRSS_RES_CAUSE_RESET_MCWDT1_Pos         9UL
#define SRSS_RES_CAUSE_RESET_MCWDT1_Msk         0x200UL
#define SRSS_RES_CAUSE_RESET_MCWDT2_Pos         10UL
#define SRSS_RES_CAUSE_RESET_MCWDT2_Msk         0x400UL
#define SRSS_RES_CAUSE_RESET_MCWDT3_Pos         11UL
#define SRSS_RES_CAUSE_RESET_MCWDT3_Msk         0x800UL
/* SRSS.RES_CAUSE2 */
#define SRSS_RES_CAUSE2_RESET_CSV_HF_Pos        0UL
#define SRSS_RES_CAUSE2_RESET_CSV_HF_Msk        0xFFFFUL
#define SRSS_RES_CAUSE2_RESET_CSV_REF_Pos       16UL
#define SRSS_RES_CAUSE2_RESET_CSV_REF_Msk       0x10000UL
/* SRSS.RES_PXRES_CTL */
#define SRSS_RES_PXRES_CTL_PXRES_TRIGGER_Pos    0UL
#define SRSS_RES_PXRES_CTL_PXRES_TRIGGER_Msk    0x1UL
/* SRSS.RES_CAUSE_EXTEND */
#define SRSS_RES_CAUSE_EXTEND_RESET_XRES_Pos    16UL
#define SRSS_RES_CAUSE_EXTEND_RESET_XRES_Msk    0x10000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_BODVDDD_Pos 17UL
#define SRSS_RES_CAUSE_EXTEND_RESET_BODVDDD_Msk 0x20000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_BODVCCD_Pos 19UL
#define SRSS_RES_CAUSE_EXTEND_RESET_BODVCCD_Msk 0x80000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_BODVBAT_Pos 20UL
#define SRSS_RES_CAUSE_EXTEND_RESET_BODVBAT_Msk 0x100000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_OVDVCCD_Pos 22UL
#define SRSS_RES_CAUSE_EXTEND_RESET_OVDVCCD_Msk 0x400000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_PXRES_Pos   28UL
#define SRSS_RES_CAUSE_EXTEND_RESET_PXRES_Msk   0x10000000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_STRUCT_XRES_Pos 29UL
#define SRSS_RES_CAUSE_EXTEND_RESET_STRUCT_XRES_Msk 0x20000000UL
#define SRSS_RES_CAUSE_EXTEND_RESET_PORVDDD_Pos 30UL
#define SRSS_RES_CAUSE_EXTEND_RESET_PORVDDD_Msk 0x40000000UL
/* SRSS.PWR_CBUCK_CTL */
#define SRSS_PWR_CBUCK_CTL_CBUCK_VSEL_Pos       0UL
#define SRSS_PWR_CBUCK_CTL_CBUCK_VSEL_Msk       0x1FUL
#define SRSS_PWR_CBUCK_CTL_CBUCK_MODE_Pos       8UL
#define SRSS_PWR_CBUCK_CTL_CBUCK_MODE_Msk       0x1F00UL
/* SRSS.PWR_CBUCK_CTL2 */
#define SRSS_PWR_CBUCK_CTL2_CBUCK_PROFILE_Pos   0UL
#define SRSS_PWR_CBUCK_CTL2_CBUCK_PROFILE_Msk   0x3UL
#define SRSS_PWR_CBUCK_CTL2_RESERVED_CTL2_Pos   30UL
#define SRSS_PWR_CBUCK_CTL2_RESERVED_CTL2_Msk   0x40000000UL
#define SRSS_PWR_CBUCK_CTL2_RESERVED_CTL_Pos    31UL
#define SRSS_PWR_CBUCK_CTL2_RESERVED_CTL_Msk    0x80000000UL
/* SRSS.PWR_CBUCK_DPSLP_CTL */
#define SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_VSEL_Pos 0UL
#define SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_VSEL_Msk 0x1FUL
#define SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_MODE_Pos 8UL
#define SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_MODE_Msk 0x1F00UL
#define SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_OVERRIDE_Pos 31UL
#define SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_OVERRIDE_Msk 0x80000000UL
/* SRSS.PWR_CBUCK_STATUS */
#define SRSS_PWR_CBUCK_STATUS_SRAMLDO_DONE_Pos  0UL
#define SRSS_PWR_CBUCK_STATUS_SRAMLDO_DONE_Msk  0x1UL
#define SRSS_PWR_CBUCK_STATUS_SRAMLDO_SW_ON_Pos 1UL
#define SRSS_PWR_CBUCK_STATUS_SRAMLDO_SW_ON_Msk 0x2UL
#define SRSS_PWR_CBUCK_STATUS_RETLDO_DONE_Pos   8UL
#define SRSS_PWR_CBUCK_STATUS_RETLDO_DONE_Msk   0x100UL
#define SRSS_PWR_CBUCK_STATUS_MISCLDO_DONE_Pos  15UL
#define SRSS_PWR_CBUCK_STATUS_MISCLDO_DONE_Msk  0x8000UL
#define SRSS_PWR_CBUCK_STATUS_SR_CUR_MODE_Pos   24UL
#define SRSS_PWR_CBUCK_STATUS_SR_CUR_MODE_Msk   0x7000000UL
#define SRSS_PWR_CBUCK_STATUS_PMU_DONE_Pos      31UL
#define SRSS_PWR_CBUCK_STATUS_PMU_DONE_Msk      0x80000000UL
/* SRSS.PWR_RETLDO_CTL */
#define SRSS_PWR_RETLDO_CTL_RETLDO_LVL_Pos      0UL
#define SRSS_PWR_RETLDO_CTL_RETLDO_LVL_Msk      0x1FUL
#define SRSS_PWR_RETLDO_CTL_RETLDO_GAIN_Pos     5UL
#define SRSS_PWR_RETLDO_CTL_RETLDO_GAIN_Msk     0x20UL
#define SRSS_PWR_RETLDO_CTL_RETLDO_LVL_DPSLP_Pos 8UL
#define SRSS_PWR_RETLDO_CTL_RETLDO_LVL_DPSLP_Msk 0x1F00UL
#define SRSS_PWR_RETLDO_CTL_RETLDO_GAIN_DPSLP_Pos 13UL
#define SRSS_PWR_RETLDO_CTL_RETLDO_GAIN_DPSLP_Msk 0x2000UL
/* SRSS.PWR_SRAMLDO_CTL */
#define SRSS_PWR_SRAMLDO_CTL_SRAMLDO_EN_Pos     0UL
#define SRSS_PWR_SRAMLDO_CTL_SRAMLDO_EN_Msk     0x1UL
#define SRSS_PWR_SRAMLDO_CTL_SRAMLDO_DPSLP_EN_Pos 1UL
#define SRSS_PWR_SRAMLDO_CTL_SRAMLDO_DPSLP_EN_Msk 0x2UL
#define SRSS_PWR_SRAMLDO_CTL_SRAMLDO_VOUT_Pos   2UL
#define SRSS_PWR_SRAMLDO_CTL_SRAMLDO_VOUT_Msk   0x7CUL
/* SRSS.PWR_MISCLDO_CTL */
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_EN_Pos     0UL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_EN_Msk     0x1UL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_MODE_Pos   1UL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_MODE_Msk   0x2UL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_VOUT_Pos   2UL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_VOUT_Msk   0x7CUL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_VCCACT_TRIM_Pos 7UL
#define SRSS_PWR_MISCLDO_CTL_MISCLDO_VCCACT_TRIM_Msk 0x780UL
/* SRSS.PWR_TRIM_PMU_CTL0 */
#define SRSS_PWR_TRIM_PMU_CTL0_LP_BUF_TRIM_Pos  0UL
#define SRSS_PWR_TRIM_PMU_CTL0_LP_BUF_TRIM_Msk  0x1FUL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_DIS_CHOP_Pos 5UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_DIS_CHOP_Msk 0x20UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_CHOP_DELAY_Pos 6UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_CHOP_DELAY_Msk 0xC0UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_TRIM_Pos    8UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_TRIM_Msk    0xF00UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_RCTAT_ADJ_Pos 12UL
#define SRSS_PWR_TRIM_PMU_CTL0_HPBG_RCTAT_ADJ_Msk 0xF000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC8M_FORCE_EN_Pos 16UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC8M_FORCE_EN_Msk 0x10000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC4M_FORCE_EN_Pos 17UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC4M_FORCE_EN_Msk 0x20000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC4M_FREQ_SEL_Pos 18UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC4M_FREQ_SEL_Msk 0x40000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_FREQ_SEL_Pos 19UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_FREQ_SEL_Msk 0x80000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_RESET_Pos 20UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_RESET_Msk 0x100000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_START_Pos 21UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_START_Msk 0x200000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_MANUAL_8M_Pos 22UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_MANUAL_8M_Msk 0x400000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_MANUAL_4M_Pos 23UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_MANUAL_4M_Msk 0x800000UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_CODE_8M_Pos 24UL
#define SRSS_PWR_TRIM_PMU_CTL0_OSC_CAL_CODE_8M_Msk 0x1F000000UL
/* SRSS.CLK_TRIM_ECO_CTL */
#define SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_IBOOSTEN_Pos 0UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_IBOOSTEN_Msk 0x1UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_CPBOOST_Pos 4UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_CPBOOST_Msk 0x10UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_WDBOOST_Pos 8UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_WDBOOST_Msk 0x100UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_TRIM_FBK_Pos  16UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_TRIM_FBK_Msk  0x30000UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_TRIM_WDHYST_Pos 18UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_TRIM_WDHYST_Msk 0xC0000UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_TRIM_IREF_Pos 20UL
#define SRSS_CLK_TRIM_ECO_CTL_ECO_TRIM_IREF_Msk 0x1F00000UL
/* SRSS.WDT_CTL */
#define SRSS_WDT_CTL_WDT_EN_Pos                 0UL
#define SRSS_WDT_CTL_WDT_EN_Msk                 0x1UL
#define SRSS_WDT_CTL_WDT_CLK_SEL_Pos            4UL
#define SRSS_WDT_CTL_WDT_CLK_SEL_Msk            0x30UL
#define SRSS_WDT_CTL_WDT_LOCK_Pos               30UL
#define SRSS_WDT_CTL_WDT_LOCK_Msk               0xC0000000UL
/* SRSS.WDT_CNT */
#define SRSS_WDT_CNT_COUNTER_Pos                0UL
#define SRSS_WDT_CNT_COUNTER_Msk                0xFFFFFFFFUL
/* SRSS.WDT_MATCH */
#define SRSS_WDT_MATCH_MATCH_Pos                0UL
#define SRSS_WDT_MATCH_MATCH_Msk                0xFFFFFFFFUL
/* SRSS.WDT_MATCH2 */
#define SRSS_WDT_MATCH2_IGNORE_BITS_ABOVE_Pos   0UL
#define SRSS_WDT_MATCH2_IGNORE_BITS_ABOVE_Msk   0x1FUL


#endif /* _CYIP_SRSS_V1_1_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* I3C IP definitions
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

#ifndef _CYIP_I3C_V1_1_H_
#define _CYIP_I3C_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     I3C
*******************************************************************************/

#define I3C_CORE_SECTION_SIZE                   0x00000300UL
#define I3C_SECTION_SIZE                        0x00010000UL

/**
  * \brief registers in I3C IP core (I3C_CORE)
  */
typedef struct {
  __IOM uint32_t DEVICE_CTRL;                   /*!< 0x00000000 Device Control Register */
  __IOM uint32_t DEVICE_ADDR;                   /*!< 0x00000004 Device Address Register */
   __IM uint32_t RESERVED;
   __OM uint32_t COMMAND_QUEUE_PORT;            /*!< 0x0000000C COMMAND_QUEUE_PORT */
   __IM uint32_t RESPONSE_QUEUE_PORT;           /*!< 0x00000010 RESPONSE_QUEUE_PORT */
  __IOM uint32_t TX_RX_DATA_PORT;               /*!< 0x00000014 Transmit/Receive Data Port Register */
   __IM uint32_t IBI_QUEUE_DATA;                /*!< 0x00000018 In-Band Interrupt Queue Data Register */
  __IOM uint32_t QUEUE_THLD_CTRL;               /*!< 0x0000001C Queue Threshold Control Register */
  __IOM uint32_t DATA_BUFFER_THLD_CTRL;         /*!< 0x00000020 Data Buffer Threshold Control Register */
  __IOM uint32_t IBI_QUEUE_CTRL;                /*!< 0x00000024 IBI Queue Control Register */
   __IM uint32_t RESERVED1[3];
  __IOM uint32_t RESET_CTRL;                    /*!< 0x00000034 Reset Control Register */
  __IOM uint32_t TGT_EVENT_STATUS;              /*!< 0x00000038 Target Event Status Register */
  __IOM uint32_t INTR_STATUS;                   /*!< 0x0000003C Reset Control Register */
  __IOM uint32_t INTR_STATUS_EN;                /*!< 0x00000040 Interrupt Status Enable Register. */
  __IOM uint32_t INTR_SIGNAL_EN;                /*!< 0x00000044 Interrupt Signal Enable Register */
   __OM uint32_t INTR_FORCE;                    /*!< 0x00000048 Interrupt Force Enable Register */
   __IM uint32_t QUEUE_STATUS_LEVEL;            /*!< 0x0000004C Queue Status Level Register. */
   __IM uint32_t DATA_BUFFER_STATUS_LEVEL;      /*!< 0x00000050 Data Buffer Status Level Register. */
   __IM uint32_t PRESENT_STATE;                 /*!< 0x00000054 Present State Register */
   __IM uint32_t CCC_DEVICE_STATUS;             /*!< 0x00000058 Device Operating Status Register. */
   __IM uint32_t DEVICE_ADDR_TABLE_POINTER;     /*!< 0x0000005C Pointer for Device Address Table */
  __IOM uint32_t DEV_CHAR_TABLE_POINTER;        /*!< 0x00000060 Pointer for Device Characteristics Table */
   __IM uint32_t RESERVED2[2];
   __IM uint32_t VENDOR_SPECIFIC_REG_POINTER;   /*!< 0x0000006C Pointer for Vendor Specific Registers. */
  __IOM uint32_t TGT_MIPI_ID_VALUE;             /*!< 0x00000070 I3C  MIPI Manufacturer ID Register */
  __IOM uint32_t TGT_PID_VALUE;                 /*!< 0x00000074 I3C Normal Provisional ID Register */
  __IOM uint32_t TGT_CHAR_CTRL;                 /*!< 0x00000078 I3C Target Characteristic Register. */
   __IM uint32_t TGT_MAX_LEN;                   /*!< 0x0000007C I3C Max Write/Read Length Register. */
   __IM uint32_t MAX_READ_TURNAROUND;           /*!< 0x00000080 MXDS Maximum Read Turnaround Time. */
  __IOM uint32_t MAX_DATA_SPEED;                /*!< 0x00000084 Maximum Data Speed Register */
   __IM uint32_t RESERVED3;
  __IOM uint32_t TGT_INTR_REQ;                  /*!< 0x0000008C Target Interrupt Request Register */
   __IM uint32_t RESERVED4;
  __IOM uint32_t TGT_TIR_DATA;                  /*!< 0x00000094 Target Interrupt Request Data Register */
   __IM uint32_t TGT_IBI_RESP;                  /*!< 0x00000098 Target IBI Response Register */
   __IM uint32_t RESERVED5[5];
  __IOM uint32_t DEVICE_CTRL_EXTENDED;          /*!< 0x000000B0 Device Control Extended Register */
  __IOM uint32_t SCL_I3C_OD_TIMING;             /*!< 0x000000B4 SCL I3C Open Drain Timing Register */
  __IOM uint32_t SCL_I3C_PP_TIMING;             /*!< 0x000000B8 SCL I3C Push Pull Timing Register */
  __IOM uint32_t SCL_I2C_FM_TIMING;             /*!< 0x000000BC SCL I2C Fast Mode Timing Register */
  __IOM uint32_t SCL_I2C_FMP_TIMING;            /*!< 0x000000C0 SCL I2C Fast Mode Plus Timing Register */
   __IM uint32_t RESERVED6;
  __IOM uint32_t SCL_EXT_LCNT_TIMING;           /*!< 0x000000C8 SCL Extended Low Count Timing Register. */
  __IOM uint32_t SCL_EXT_TERMN_LCNT_TIMING;     /*!< 0x000000CC SCL Termination Bit Low Count Timing Register */
  __IOM uint32_t SDA_HOLD_SWITCH_DLY_TIMING;    /*!< 0x000000D0 SDA Hold and Mode Switch Delay Timing Register */
  __IOM uint32_t BUS_FREE_AVAIL_TIMING;         /*!< 0x000000D4 Bus Free and Available Timing Register */
  __IOM uint32_t BUS_IDLE_TIMING;               /*!< 0x000000D8 Bus Idle Timing Register */
  __IOM uint32_t SCL_LOW_CTR_EXT_TIMEOUT;       /*!< 0x000000DC SCL LOW Controller Timeout */
   __IM uint32_t RESERVED7[3];
  __IOM uint32_t RELEASE_SDA_TIMING;            /*!< 0x000000EC Release SDA count value. */
   __IM uint32_t RESERVED8[16];
   __OM uint32_t EXT_TX_DATA_PORT_0;            /*!< 0x00000130 DWC_mipi_i3c Directed read Vendor-specific CCC 0 TX Data Port
                                                                Register */
   __OM uint32_t EXT_TX_DATA_PORT_1;            /*!< 0x00000134 DWC_mipi_i3c Directed read Vendor-specific CCC 1 TX Data Port
                                                                Register */
   __OM uint32_t EXT_TX_DATA_PORT_2;            /*!< 0x00000138 DWC_mipi_i3c Directed read Vendor-specific CCC 2 TX Data Port
                                                                Register */
   __OM uint32_t EXT_TX_DATA_PORT_3;            /*!< 0x0000013C DWC_mipi_i3c Directed read Vendor-specific CCC 3 TX Data Port
                                                                Register */
   __IM uint32_t RESERVED9[5];
   __IM uint32_t EXT_0_1_DATA_BUF_STS_LEVEL;    /*!< 0x00000154 Vendor-specific CCC types 0 and 1 Data Buffer Status Level
                                                                Register */
   __IM uint32_t EXT_2_3_DATA_BUF_STS_LEVEL;    /*!< 0x00000158 Vendor-specific CCC types 2 and 3 Data Buffer Status Level
                                                                Register */
   __IM uint32_t RESERVED10[2];
  __IOM uint32_t EXT_CMD_REG_0;                 /*!< 0x00000164 TID, CCC type value and Defining Byte of Vendor-specific CCC 0
                                                                Register */
  __IOM uint32_t EXT_CMD_REG_1;                 /*!< 0x00000168 TID, CCC type value and Defining Byte of Vendor-specific CCC 1
                                                                Register */
  __IOM uint32_t EXT_CMD_REG_2;                 /*!< 0x0000016C TID, CCC type value and Defining Byte of Vendor-specific CCC 2
                                                                Register */
  __IOM uint32_t EXT_CMD_REG_3;                 /*!< 0x00000170 TID, CCC type value and Defining Byte of Vendor-specific CCC 3
                                                                Register */
   __IM uint32_t RESERVED11[4];
  __IOM uint32_t EXT_TX_QUEUE_RESET_CTRL;       /*!< 0x00000184 Individual Vendor CCC buffer reset. */
   __IM uint32_t RESERVED12[30];
   __IM uint32_t DEV_CHAR_TABLE1_LOC1;          /*!< 0x00000200 Device Characteristic Table Location-1 of Device1,
                                                                MSB_PROVISIONAL_ID */
   __IM uint32_t DEV_CHAR_TABLE1_LOC2;          /*!< 0x00000204 Device Characteristic Table Location-2 of Device1,
                                                                LSB_PROVISIONAL_ID */
   __IM uint32_t DEV_CHAR_TABLE1_LOC3;          /*!< 0x00000208 Device Characteristic Table Location-3 of Device1, BCR, DCR */
   __IM uint32_t DEV_CHAR_TABLE1_LOC4;          /*!< 0x0000020C Device Characteristic Table Location-4 of Device1,
                                                                DEV_DYNAMIC_ADDR */
   __IM uint32_t DEV_CHAR_TABLE2_LOC1;          /*!< 0x00000210 Device Characteristic Table Location-1 of Device2 */
   __IM uint32_t DEV_CHAR_TABLE2_LOC2;          /*!< 0x00000214 Device Characteristic Table Location-2 of Device2 */
   __IM uint32_t DEV_CHAR_TABLE2_LOC3;          /*!< 0x00000218 Device Characteristic Table Location-3 of Device2 */
   __IM uint32_t DEV_CHAR_TABLE2_LOC4;          /*!< 0x0000021C Device Characteristic Table Location-4 of Device2 */
   __IM uint32_t DEV_CHAR_TABLE3_LOC1;          /*!< 0x00000220 Device Characteristic Table Location-1 of Device3 */
   __IM uint32_t DEV_CHAR_TABLE3_LOC2;          /*!< 0x00000224 Device Characteristic Table Location-2 of Device3 */
   __IM uint32_t DEV_CHAR_TABLE3_LOC3;          /*!< 0x00000228 Device Characteristic Table Location-3 of Device3 */
   __IM uint32_t DEV_CHAR_TABLE3_LOC4;          /*!< 0x0000022C Device Characteristic Table Location-4 of Device3 */
   __IM uint32_t DEV_CHAR_TABLE4_LOC1;          /*!< 0x00000230 Device Characteristic Table Location-1 of Device4 */
   __IM uint32_t DEV_CHAR_TABLE4_LOC2;          /*!< 0x00000234 Device Characteristic Table Location-2 of Device4 */
   __IM uint32_t DEV_CHAR_TABLE4_LOC3;          /*!< 0x00000238 Device Characteristic Table Location-3 of Device4 */
   __IM uint32_t DEV_CHAR_TABLE4_LOC4;          /*!< 0x0000023C Device Characteristic Table Location-4 of Device4 */
   __IM uint32_t DEV_CHAR_TABLE5_LOC1;          /*!< 0x00000240 Device Characteristic Table Location-1 of Device5 */
   __IM uint32_t DEV_CHAR_TABLE5_LOC2;          /*!< 0x00000244 Device Characteristic Table Location-4 of Device10 */
   __IM uint32_t DEV_CHAR_TABLE5_LOC3;          /*!< 0x00000248 Device Characteristic Table Location-3 of Device5 */
   __IM uint32_t DEV_CHAR_TABLE5_LOC4;          /*!< 0x0000024C Device Characteristic Table Location-4 of Device5 */
   __IM uint32_t DEV_CHAR_TABLE6_LOC1;          /*!< 0x00000250 Device Characteristic Table Location-1 of Device6 */
   __IM uint32_t DEV_CHAR_TABLE6_LOC2;          /*!< 0x00000254 Device Characteristic Table Location-2 of Device6 */
   __IM uint32_t DEV_CHAR_TABLE6_LOC3;          /*!< 0x00000258 Device Characteristic Table Location-3 of Device6 */
   __IM uint32_t DEV_CHAR_TABLE6_LOC4;          /*!< 0x0000025C Device Characteristic Table Location-4 of Device6 */
   __IM uint32_t DEV_CHAR_TABLE7_LOC1;          /*!< 0x00000260 Device Address Table of Device3 */
   __IM uint32_t DEV_CHAR_TABLE7_LOC2;          /*!< 0x00000264 Device Characteristic Table Location-2 of Device7 */
   __IM uint32_t DEV_CHAR_TABLE7_LOC3;          /*!< 0x00000268 Device Characteristic Table Location-3 of Device7 */
   __IM uint32_t DEV_CHAR_TABLE7_LOC4;          /*!< 0x0000026C Device Characteristic Table Location-4 of Device7 */
   __IM uint32_t DEV_CHAR_TABLE8_LOC1;          /*!< 0x00000270 Device Characteristic Table Location-1 of Device8 */
   __IM uint32_t DEV_CHAR_TABLE8_LOC2;          /*!< 0x00000274 Device Characteristic Table Location-2 of Device8 */
   __IM uint32_t DEV_CHAR_TABLE8_LOC3;          /*!< 0x00000278 Device Characteristic Table Location-3 of Device8 */
   __IM uint32_t DEV_CHAR_TABLE8_LOC4;          /*!< 0x0000027C Device Address Table of Device10 */
   __IM uint32_t DEV_CHAR_TABLE9_LOC1;          /*!< 0x00000280 Device Characteristic Table Location-1 of Device9 */
   __IM uint32_t DEV_CHAR_TABLE9_LOC2;          /*!< 0x00000284 Device Characteristic Table Location-2 of Device9 */
   __IM uint32_t DEV_CHAR_TABLE9_LOC3;          /*!< 0x00000288 Device Characteristic Table Location-3 of Device9 */
   __IM uint32_t DEV_CHAR_TABLE9_LOC4;          /*!< 0x0000028C Device Characteristic Table Location-4 of Device9 */
   __IM uint32_t DEV_CHAR_TABLE10_LOC1;         /*!< 0x00000290 Device Characteristic Table Location-1 of Device10 */
   __IM uint32_t DEV_CHAR_TABLE10_LOC2;         /*!< 0x00000294 Device Characteristic Table Location-2 of Device10 */
   __IM uint32_t DEV_CHAR_TABLE10_LOC3;         /*!< 0x00000298 Device Characteristic Table Location-3 of Device10 */
   __IM uint32_t DEV_CHAR_TABLE10_LOC4;         /*!< 0x0000029C Device Characteristic Table Location-4 of Device10 */
   __IM uint32_t DEV_CHAR_TABLE11_LOC1;         /*!< 0x000002A0 Device Characteristic Table Location-1 of Device11 */
   __IM uint32_t DEV_CHAR_TABLE11_LOC2;         /*!< 0x000002A4 0 */
   __IM uint32_t DEV_CHAR_TABLE11_LOC3;         /*!< 0x000002A8 Device Characteristic Table Location-3 of Device11 */
   __IM uint32_t DEV_CHAR_TABLE11_LOC4;         /*!< 0x000002AC Device Characteristic Table Location-4 of Device11 */
   __IM uint32_t RESERVED13[4];
  __IOM uint32_t DEV_ADDR_TABLE_LOC1;           /*!< 0x000002C0 Device Address Table of Device1 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC2;           /*!< 0x000002C4 Device Address Table of Device2 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC3;           /*!< 0x000002C8 Device Address Table of Device3 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC4;           /*!< 0x000002CC Device Address Table of Device4 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC5;           /*!< 0x000002D0 Device Address Table of Device5 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC6;           /*!< 0x000002D4 Device Address Table of Device6 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC7;           /*!< 0x000002D8 Device Address Table of Device7 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC8;           /*!< 0x000002DC Device Address Table of Device8 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC9;           /*!< 0x000002E0 Device Address Table of Device9 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC10;          /*!< 0x000002E4 Device Address Table of Device10 */
  __IOM uint32_t DEV_ADDR_TABLE_LOC11;          /*!< 0x000002E8 Device Address Table of Device11 */
   __IM uint32_t RESERVED14[5];
} I3C_CORE_Type;                                /*!< Size = 768 (0x300) */

/**
  * \brief I3C controller top (I3C)
  */
typedef struct {
        I3C_CORE_Type CORE;                     /*!< 0x00000000 registers in I3C IP core */
   __IM uint32_t RESERVED[64];
  __IOM uint32_t CTRL;                          /*!< 0x00000400 I3C Block Control */
   __IM uint32_t RESERVED1[5];
   __IM uint32_t TGT_STATUS;                    /*!< 0x00000418 This register provides additional status information when
                                                                functioning as a Target. */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t CCC_GETSTATUS;                 /*!< 0x00000424 This register provides additional information on GETSTATUS CCCs
                                                                received when functioning as a Target. */
   __IM uint32_t RESERVED3;
  __IOM uint32_t TIMING_CNT_CTRL;               /*!< 0x0000042C Controls the Counter used for timestamping I3C-relevant events,
                                                                especially when communicating with Asynchronous Timing Control
                                                                Mode 0 enabled. */
   __IM uint32_t TIMING_CNT0;                   /*!< 0x00000430 Most Significant Bits of the Counter */
   __IM uint32_t TIMING_CNT1;                   /*!< 0x00000434 Least Significant Bits of the Counter */
} I3C_Type;                                     /*!< Size = 1080 (0x438) */


/* I3C_CORE.DEVICE_CTRL */
#define I3C_CORE_DEVICE_CTRL_IBA_INCLUDE_Pos    0UL
#define I3C_CORE_DEVICE_CTRL_IBA_INCLUDE_Msk    0x1UL
#define I3C_CORE_DEVICE_CTRL_I2C_TARGET_PRESENT_Pos 7UL
#define I3C_CORE_DEVICE_CTRL_I2C_TARGET_PRESENT_Msk 0x80UL
#define I3C_CORE_DEVICE_CTRL_HOT_JOIN_CTRL_Pos  8UL
#define I3C_CORE_DEVICE_CTRL_HOT_JOIN_CTRL_Msk  0x100UL
#define I3C_CORE_DEVICE_CTRL_IDLE_CNT_MULTPLIER_Pos 24UL
#define I3C_CORE_DEVICE_CTRL_IDLE_CNT_MULTPLIER_Msk 0x3000000UL
#define I3C_CORE_DEVICE_CTRL_TARGET_PEC_EN_Pos  26UL
#define I3C_CORE_DEVICE_CTRL_TARGET_PEC_EN_Msk  0x4000000UL
#define I3C_CORE_DEVICE_CTRL_ADAPTIVE_I2C_I3C_Pos 27UL
#define I3C_CORE_DEVICE_CTRL_ADAPTIVE_I2C_I3C_Msk 0x8000000UL
#define I3C_CORE_DEVICE_CTRL_ABORT_Pos          29UL
#define I3C_CORE_DEVICE_CTRL_ABORT_Msk          0x20000000UL
#define I3C_CORE_DEVICE_CTRL_RESUME_Pos         30UL
#define I3C_CORE_DEVICE_CTRL_RESUME_Msk         0x40000000UL
#define I3C_CORE_DEVICE_CTRL_ENABLE_Pos         31UL
#define I3C_CORE_DEVICE_CTRL_ENABLE_Msk         0x80000000UL
/* I3C_CORE.DEVICE_ADDR */
#define I3C_CORE_DEVICE_ADDR_STATIC_ADDR_Pos    0UL
#define I3C_CORE_DEVICE_ADDR_STATIC_ADDR_Msk    0x7FUL
#define I3C_CORE_DEVICE_ADDR_STATIC_ADDR_VALID_Pos 15UL
#define I3C_CORE_DEVICE_ADDR_STATIC_ADDR_VALID_Msk 0x8000UL
#define I3C_CORE_DEVICE_ADDR_DYNAMIC_ADDR_Pos   16UL
#define I3C_CORE_DEVICE_ADDR_DYNAMIC_ADDR_Msk   0x7F0000UL
#define I3C_CORE_DEVICE_ADDR_DYNAMIC_ADDR_VALID_Pos 31UL
#define I3C_CORE_DEVICE_ADDR_DYNAMIC_ADDR_VALID_Msk 0x80000000UL
/* I3C_CORE.COMMAND_QUEUE_PORT */
#define I3C_CORE_COMMAND_QUEUE_PORT_COMMAND_Pos 0UL
#define I3C_CORE_COMMAND_QUEUE_PORT_COMMAND_Msk 0xFFFFFFFFUL
/* I3C_CORE.RESPONSE_QUEUE_PORT */
#define I3C_CORE_RESPONSE_QUEUE_PORT_RESPONSE_Pos 0UL
#define I3C_CORE_RESPONSE_QUEUE_PORT_RESPONSE_Msk 0xFFFFFFFFUL
/* I3C_CORE.TX_RX_DATA_PORT */
#define I3C_CORE_TX_RX_DATA_PORT_TX_RX_DATA_PORT_Pos 0UL
#define I3C_CORE_TX_RX_DATA_PORT_TX_RX_DATA_PORT_Msk 0xFFFFFFFFUL
/* I3C_CORE.IBI_QUEUE_DATA */
#define I3C_CORE_IBI_QUEUE_DATA_IBI_DATA_Pos    0UL
#define I3C_CORE_IBI_QUEUE_DATA_IBI_DATA_Msk    0xFFFFFFFFUL
/* I3C_CORE.QUEUE_THLD_CTRL */
#define I3C_CORE_QUEUE_THLD_CTRL_CMD_EMPTY_BUF_THLD_Pos 0UL
#define I3C_CORE_QUEUE_THLD_CTRL_CMD_EMPTY_BUF_THLD_Msk 0xFFUL
#define I3C_CORE_QUEUE_THLD_CTRL_RESP_BUF_THLD_Pos 8UL
#define I3C_CORE_QUEUE_THLD_CTRL_RESP_BUF_THLD_Msk 0xFF00UL
#define I3C_CORE_QUEUE_THLD_CTRL_IBI_DATA_THLD_Pos 16UL
#define I3C_CORE_QUEUE_THLD_CTRL_IBI_DATA_THLD_Msk 0xFF0000UL
#define I3C_CORE_QUEUE_THLD_CTRL_IBI_STATUS_THLD_Pos 24UL
#define I3C_CORE_QUEUE_THLD_CTRL_IBI_STATUS_THLD_Msk 0xFF000000UL
/* I3C_CORE.DATA_BUFFER_THLD_CTRL */
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD_Pos 0UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_EMPTY_BUF_THLD_Msk 0x7UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD_Pos 8UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_BUF_THLD_Msk 0x700UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_START_THLD_Pos 16UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_TX_START_THLD_Msk 0x70000UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_START_THLD_Pos 24UL
#define I3C_CORE_DATA_BUFFER_THLD_CTRL_RX_START_THLD_Msk 0x7000000UL
/* I3C_CORE.IBI_QUEUE_CTRL */
#define I3C_CORE_IBI_QUEUE_CTRL_NOTIFY_HJ_REJECTED_Pos 0UL
#define I3C_CORE_IBI_QUEUE_CTRL_NOTIFY_HJ_REJECTED_Msk 0x1UL
#define I3C_CORE_IBI_QUEUE_CTRL_NOTIFY_CR_REJECTED_Pos 1UL
#define I3C_CORE_IBI_QUEUE_CTRL_NOTIFY_CR_REJECTED_Msk 0x2UL
#define I3C_CORE_IBI_QUEUE_CTRL_NOTIFY_TIR_REJECTED_Pos 3UL
#define I3C_CORE_IBI_QUEUE_CTRL_NOTIFY_TIR_REJECTED_Msk 0x8UL
/* I3C_CORE.RESET_CTRL */
#define I3C_CORE_RESET_CTRL_SOFT_RST_Pos        0UL
#define I3C_CORE_RESET_CTRL_SOFT_RST_Msk        0x1UL
#define I3C_CORE_RESET_CTRL_CMD_QUEUE_RST_Pos   1UL
#define I3C_CORE_RESET_CTRL_CMD_QUEUE_RST_Msk   0x2UL
#define I3C_CORE_RESET_CTRL_RESP_QUEUE_RST_Pos  2UL
#define I3C_CORE_RESET_CTRL_RESP_QUEUE_RST_Msk  0x4UL
#define I3C_CORE_RESET_CTRL_TX_FIFO_RST_Pos     3UL
#define I3C_CORE_RESET_CTRL_TX_FIFO_RST_Msk     0x8UL
#define I3C_CORE_RESET_CTRL_RX_FIFO_RST_Pos     4UL
#define I3C_CORE_RESET_CTRL_RX_FIFO_RST_Msk     0x10UL
#define I3C_CORE_RESET_CTRL_IBI_QUEUE_RST_Pos   5UL
#define I3C_CORE_RESET_CTRL_IBI_QUEUE_RST_Msk   0x20UL
#define I3C_CORE_RESET_CTRL_BUS_RESET_TYPE_Pos  28UL
#define I3C_CORE_RESET_CTRL_BUS_RESET_TYPE_Msk  0x70000000UL
#define I3C_CORE_RESET_CTRL_BUS_RESET_Pos       31UL
#define I3C_CORE_RESET_CTRL_BUS_RESET_Msk       0x80000000UL
/* I3C_CORE.TGT_EVENT_STATUS */
#define I3C_CORE_TGT_EVENT_STATUS_TIR_EN_Pos    0UL
#define I3C_CORE_TGT_EVENT_STATUS_TIR_EN_Msk    0x1UL
#define I3C_CORE_TGT_EVENT_STATUS_CR_EN_Pos     1UL
#define I3C_CORE_TGT_EVENT_STATUS_CR_EN_Msk     0x2UL
#define I3C_CORE_TGT_EVENT_STATUS_HJ_EN_Pos     3UL
#define I3C_CORE_TGT_EVENT_STATUS_HJ_EN_Msk     0x8UL
#define I3C_CORE_TGT_EVENT_STATUS_ACTIVITY_STATE_Pos 4UL
#define I3C_CORE_TGT_EVENT_STATUS_ACTIVITY_STATE_Msk 0x30UL
#define I3C_CORE_TGT_EVENT_STATUS_MRL_UPDATED_Pos 6UL
#define I3C_CORE_TGT_EVENT_STATUS_MRL_UPDATED_Msk 0x40UL
#define I3C_CORE_TGT_EVENT_STATUS_MWL_UPDATED_Pos 7UL
#define I3C_CORE_TGT_EVENT_STATUS_MWL_UPDATED_Msk 0x80UL
/* I3C_CORE.INTR_STATUS */
#define I3C_CORE_INTR_STATUS_TX_THLD_STS_Pos    0UL
#define I3C_CORE_INTR_STATUS_TX_THLD_STS_Msk    0x1UL
#define I3C_CORE_INTR_STATUS_RX_THLD_STS_Pos    1UL
#define I3C_CORE_INTR_STATUS_RX_THLD_STS_Msk    0x2UL
#define I3C_CORE_INTR_STATUS_IBI_THLD_STS_Pos   2UL
#define I3C_CORE_INTR_STATUS_IBI_THLD_STS_Msk   0x4UL
#define I3C_CORE_INTR_STATUS_CMD_QUEUE_READY_STS_Pos 3UL
#define I3C_CORE_INTR_STATUS_CMD_QUEUE_READY_STS_Msk 0x8UL
#define I3C_CORE_INTR_STATUS_RESP_READY_STS_Pos 4UL
#define I3C_CORE_INTR_STATUS_RESP_READY_STS_Msk 0x10UL
#define I3C_CORE_INTR_STATUS_TRANSFER_ABORT_STS_Pos 5UL
#define I3C_CORE_INTR_STATUS_TRANSFER_ABORT_STS_Msk 0x20UL
#define I3C_CORE_INTR_STATUS_CCC_UPDATED_STS_Pos 6UL
#define I3C_CORE_INTR_STATUS_CCC_UPDATED_STS_Msk 0x40UL
#define I3C_CORE_INTR_STATUS_DYN_ADDR_ASSGN_STS_Pos 8UL
#define I3C_CORE_INTR_STATUS_DYN_ADDR_ASSGN_STS_Msk 0x100UL
#define I3C_CORE_INTR_STATUS_TRANSFER_ERR_STS_Pos 9UL
#define I3C_CORE_INTR_STATUS_TRANSFER_ERR_STS_Msk 0x200UL
#define I3C_CORE_INTR_STATUS_DEFTGT_STS_Pos     10UL
#define I3C_CORE_INTR_STATUS_DEFTGT_STS_Msk     0x400UL
#define I3C_CORE_INTR_STATUS_READ_REQ_RECV_STS_Pos 11UL
#define I3C_CORE_INTR_STATUS_READ_REQ_RECV_STS_Msk 0x800UL
#define I3C_CORE_INTR_STATUS_IBI_UPDATED_STS_Pos 12UL
#define I3C_CORE_INTR_STATUS_IBI_UPDATED_STS_Msk 0x1000UL
#define I3C_CORE_INTR_STATUS_BUSOWNER_UPDATED_STS_Pos 13UL
#define I3C_CORE_INTR_STATUS_BUSOWNER_UPDATED_STS_Msk 0x2000UL
#define I3C_CORE_INTR_STATUS_BUS_RESET_DONE_STS_Pos 15UL
#define I3C_CORE_INTR_STATUS_BUS_RESET_DONE_STS_Msk 0x8000UL
#define I3C_CORE_INTR_STATUS_START_DET_STS_Pos  16UL
#define I3C_CORE_INTR_STATUS_START_DET_STS_Msk  0x10000UL
#define I3C_CORE_INTR_STATUS_TGT_RST_PATTERN_DET_STS_Pos 17UL
#define I3C_CORE_INTR_STATUS_TGT_RST_PATTERN_DET_STS_Msk 0x20000UL
#define I3C_CORE_INTR_STATUS_SDA_RELEASED_STS_Pos 19UL
#define I3C_CORE_INTR_STATUS_SDA_RELEASED_STS_Msk 0x80000UL
#define I3C_CORE_INTR_STATUS_EXT_CMD_SENT_STS_Pos 20UL
#define I3C_CORE_INTR_STATUS_EXT_CMD_SENT_STS_Msk 0x100000UL
/* I3C_CORE.INTR_STATUS_EN */
#define I3C_CORE_INTR_STATUS_EN_TX_THLD_STS_EN_Pos 0UL
#define I3C_CORE_INTR_STATUS_EN_TX_THLD_STS_EN_Msk 0x1UL
#define I3C_CORE_INTR_STATUS_EN_RX_THLD_STS_EN_Pos 1UL
#define I3C_CORE_INTR_STATUS_EN_RX_THLD_STS_EN_Msk 0x2UL
#define I3C_CORE_INTR_STATUS_EN_IBI_THLD_STS_EN_Pos 2UL
#define I3C_CORE_INTR_STATUS_EN_IBI_THLD_STS_EN_Msk 0x4UL
#define I3C_CORE_INTR_STATUS_EN_CMD_QUEUE_READY_STS_EN_Pos 3UL
#define I3C_CORE_INTR_STATUS_EN_CMD_QUEUE_READY_STS_EN_Msk 0x8UL
#define I3C_CORE_INTR_STATUS_EN_RESP_READY_STS_EN_Pos 4UL
#define I3C_CORE_INTR_STATUS_EN_RESP_READY_STS_EN_Msk 0x10UL
#define I3C_CORE_INTR_STATUS_EN_TRANSFER_ABORT_STS_EN_Pos 5UL
#define I3C_CORE_INTR_STATUS_EN_TRANSFER_ABORT_STS_EN_Msk 0x20UL
#define I3C_CORE_INTR_STATUS_EN_CCC_UPDATED_STS_EN_Pos 6UL
#define I3C_CORE_INTR_STATUS_EN_CCC_UPDATED_STS_EN_Msk 0x40UL
#define I3C_CORE_INTR_STATUS_EN_DYN_ADDR_ASSGN_STS_EN_Pos 8UL
#define I3C_CORE_INTR_STATUS_EN_DYN_ADDR_ASSGN_STS_EN_Msk 0x100UL
#define I3C_CORE_INTR_STATUS_EN_TRANSFER_ERR_STS_EN_Pos 9UL
#define I3C_CORE_INTR_STATUS_EN_TRANSFER_ERR_STS_EN_Msk 0x200UL
#define I3C_CORE_INTR_STATUS_EN_DEFTGT_STS_EN_Pos 10UL
#define I3C_CORE_INTR_STATUS_EN_DEFTGT_STS_EN_Msk 0x400UL
#define I3C_CORE_INTR_STATUS_EN_READ_REQ_RECV_STS_EN_Pos 11UL
#define I3C_CORE_INTR_STATUS_EN_READ_REQ_RECV_STS_EN_Msk 0x800UL
#define I3C_CORE_INTR_STATUS_EN_IBI_UPDATED_STS_EN_Pos 12UL
#define I3C_CORE_INTR_STATUS_EN_IBI_UPDATED_STS_EN_Msk 0x1000UL
#define I3C_CORE_INTR_STATUS_EN_BUSOWNER_UPDATED_STS_EN_Pos 13UL
#define I3C_CORE_INTR_STATUS_EN_BUSOWNER_UPDATED_STS_EN_Msk 0x2000UL
#define I3C_CORE_INTR_STATUS_EN_BUS_RESET_DONE_STS_EN_Pos 15UL
#define I3C_CORE_INTR_STATUS_EN_BUS_RESET_DONE_STS_EN_Msk 0x8000UL
#define I3C_CORE_INTR_STATUS_EN_START_DET_STS_EN_Pos 16UL
#define I3C_CORE_INTR_STATUS_EN_START_DET_STS_EN_Msk 0x10000UL
#define I3C_CORE_INTR_STATUS_EN_TGT_RST_PATTERN_DET_STS_EN_Pos 17UL
#define I3C_CORE_INTR_STATUS_EN_TGT_RST_PATTERN_DET_STS_EN_Msk 0x20000UL
#define I3C_CORE_INTR_STATUS_EN_SDA_RELEASED_STS_EN_Pos 19UL
#define I3C_CORE_INTR_STATUS_EN_SDA_RELEASED_STS_EN_Msk 0x80000UL
#define I3C_CORE_INTR_STATUS_EN_EXT_CMD_SENT_STS_EN_Pos 20UL
#define I3C_CORE_INTR_STATUS_EN_EXT_CMD_SENT_STS_EN_Msk 0x100000UL
/* I3C_CORE.INTR_SIGNAL_EN */
#define I3C_CORE_INTR_SIGNAL_EN_TX_THLD_SIGNAL_EN_Pos 0UL
#define I3C_CORE_INTR_SIGNAL_EN_TX_THLD_SIGNAL_EN_Msk 0x1UL
#define I3C_CORE_INTR_SIGNAL_EN_RX_THLD_SIGNAL_EN_Pos 1UL
#define I3C_CORE_INTR_SIGNAL_EN_RX_THLD_SIGNAL_EN_Msk 0x2UL
#define I3C_CORE_INTR_SIGNAL_EN_IBI_THLD_SIGNAL_EN_Pos 2UL
#define I3C_CORE_INTR_SIGNAL_EN_IBI_THLD_SIGNAL_EN_Msk 0x4UL
#define I3C_CORE_INTR_SIGNAL_EN_CMD_QUEUE_READY_SIGNAL_EN_Pos 3UL
#define I3C_CORE_INTR_SIGNAL_EN_CMD_QUEUE_READY_SIGNAL_EN_Msk 0x8UL
#define I3C_CORE_INTR_SIGNAL_EN_RESP_READY_SIGNAL_EN_Pos 4UL
#define I3C_CORE_INTR_SIGNAL_EN_RESP_READY_SIGNAL_EN_Msk 0x10UL
#define I3C_CORE_INTR_SIGNAL_EN_TRANSFER_ABORT_SIGNAL_EN_Pos 5UL
#define I3C_CORE_INTR_SIGNAL_EN_TRANSFER_ABORT_SIGNAL_EN_Msk 0x20UL
#define I3C_CORE_INTR_SIGNAL_EN_CCC_UPDATED_SIGNAL_EN_Pos 6UL
#define I3C_CORE_INTR_SIGNAL_EN_CCC_UPDATED_SIGNAL_EN_Msk 0x40UL
#define I3C_CORE_INTR_SIGNAL_EN_DYN_ADDR_ASSGN_SIGNAL_EN_Pos 8UL
#define I3C_CORE_INTR_SIGNAL_EN_DYN_ADDR_ASSGN_SIGNAL_EN_Msk 0x100UL
#define I3C_CORE_INTR_SIGNAL_EN_TRANSFER_ERR_SIGNAL_EN_Pos 9UL
#define I3C_CORE_INTR_SIGNAL_EN_TRANSFER_ERR_SIGNAL_EN_Msk 0x200UL
#define I3C_CORE_INTR_SIGNAL_EN_DEFTGT_SIGNAL_EN_Pos 10UL
#define I3C_CORE_INTR_SIGNAL_EN_DEFTGT_SIGNAL_EN_Msk 0x400UL
#define I3C_CORE_INTR_SIGNAL_EN_READ_REQ_RECV_SIGNAL_EN_Pos 11UL
#define I3C_CORE_INTR_SIGNAL_EN_READ_REQ_RECV_SIGNAL_EN_Msk 0x800UL
#define I3C_CORE_INTR_SIGNAL_EN_IBI_UPDATED_SIGNAL_EN_Pos 12UL
#define I3C_CORE_INTR_SIGNAL_EN_IBI_UPDATED_SIGNAL_EN_Msk 0x1000UL
#define I3C_CORE_INTR_SIGNAL_EN_BUSOWNER_UPDATED_SIGNAL_EN_Pos 13UL
#define I3C_CORE_INTR_SIGNAL_EN_BUSOWNER_UPDATED_SIGNAL_EN_Msk 0x2000UL
#define I3C_CORE_INTR_SIGNAL_EN_BUS_RESET_DONE_SIGNAL_EN_Pos 15UL
#define I3C_CORE_INTR_SIGNAL_EN_BUS_RESET_DONE_SIGNAL_EN_Msk 0x8000UL
#define I3C_CORE_INTR_SIGNAL_EN_START_DET_SIGNAL_EN_Pos 16UL
#define I3C_CORE_INTR_SIGNAL_EN_START_DET_SIGNAL_EN_Msk 0x10000UL
#define I3C_CORE_INTR_SIGNAL_EN_TGT_RST_PATTERN_DET_SIGNAL_EN_Pos 17UL
#define I3C_CORE_INTR_SIGNAL_EN_TGT_RST_PATTERN_DET_SIGNAL_EN_Msk 0x20000UL
#define I3C_CORE_INTR_SIGNAL_EN_SDA_RELEASED_SIGNAL_EN_Pos 19UL
#define I3C_CORE_INTR_SIGNAL_EN_SDA_RELEASED_SIGNAL_EN_Msk 0x80000UL
#define I3C_CORE_INTR_SIGNAL_EN_EXT_CMD_SENT_SIGNAL_EN_Pos 20UL
#define I3C_CORE_INTR_SIGNAL_EN_EXT_CMD_SENT_SIGNAL_EN_Msk 0x100000UL
/* I3C_CORE.INTR_FORCE */
#define I3C_CORE_INTR_FORCE_TX_THLD_FORCE_EN_Pos 0UL
#define I3C_CORE_INTR_FORCE_TX_THLD_FORCE_EN_Msk 0x1UL
#define I3C_CORE_INTR_FORCE_RX_THLD_FORCE_EN_Pos 1UL
#define I3C_CORE_INTR_FORCE_RX_THLD_FORCE_EN_Msk 0x2UL
#define I3C_CORE_INTR_FORCE_IBI_THLD_FORCE_EN_Pos 2UL
#define I3C_CORE_INTR_FORCE_IBI_THLD_FORCE_EN_Msk 0x4UL
#define I3C_CORE_INTR_FORCE_CMD_QUEUE_READY_FORCE_EN_Pos 3UL
#define I3C_CORE_INTR_FORCE_CMD_QUEUE_READY_FORCE_EN_Msk 0x8UL
#define I3C_CORE_INTR_FORCE_RESP_READY_FORCE_EN_Pos 4UL
#define I3C_CORE_INTR_FORCE_RESP_READY_FORCE_EN_Msk 0x10UL
#define I3C_CORE_INTR_FORCE_TRANSFER_ABORT_FORCE_EN_Pos 5UL
#define I3C_CORE_INTR_FORCE_TRANSFER_ABORT_FORCE_EN_Msk 0x20UL
#define I3C_CORE_INTR_FORCE_CCC_UPDATED_FORCE_EN_Pos 6UL
#define I3C_CORE_INTR_FORCE_CCC_UPDATED_FORCE_EN_Msk 0x40UL
#define I3C_CORE_INTR_FORCE_DYN_ADDR_ASSGN_FORCE_EN_Pos 8UL
#define I3C_CORE_INTR_FORCE_DYN_ADDR_ASSGN_FORCE_EN_Msk 0x100UL
#define I3C_CORE_INTR_FORCE_TRANSFER_ERR_FORCE_EN_Pos 9UL
#define I3C_CORE_INTR_FORCE_TRANSFER_ERR_FORCE_EN_Msk 0x200UL
#define I3C_CORE_INTR_FORCE_DEFTGT_FORCE_EN_Pos 10UL
#define I3C_CORE_INTR_FORCE_DEFTGT_FORCE_EN_Msk 0x400UL
#define I3C_CORE_INTR_FORCE_READ_REQ_FORCE_EN_Pos 11UL
#define I3C_CORE_INTR_FORCE_READ_REQ_FORCE_EN_Msk 0x800UL
#define I3C_CORE_INTR_FORCE_IBI_UPDATED_FORCE_EN_Pos 12UL
#define I3C_CORE_INTR_FORCE_IBI_UPDATED_FORCE_EN_Msk 0x1000UL
#define I3C_CORE_INTR_FORCE_BUSOWNER_UPDATED_FORCE_EN_Pos 13UL
#define I3C_CORE_INTR_FORCE_BUSOWNER_UPDATED_FORCE_EN_Msk 0x2000UL
#define I3C_CORE_INTR_FORCE_BUS_RESET_DONE_FORCE_EN_Pos 15UL
#define I3C_CORE_INTR_FORCE_BUS_RESET_DONE_FORCE_EN_Msk 0x8000UL
#define I3C_CORE_INTR_FORCE_START_DET_FORCE_EN_Pos 16UL
#define I3C_CORE_INTR_FORCE_START_DET_FORCE_EN_Msk 0x10000UL
#define I3C_CORE_INTR_FORCE_TGT_RST_PATTERN_DET_FORCE_EN_Pos 17UL
#define I3C_CORE_INTR_FORCE_TGT_RST_PATTERN_DET_FORCE_EN_Msk 0x20000UL
#define I3C_CORE_INTR_FORCE_SDA_RELEASED_FORCE_EN_Pos 19UL
#define I3C_CORE_INTR_FORCE_SDA_RELEASED_FORCE_EN_Msk 0x80000UL
#define I3C_CORE_INTR_FORCE_EXT_CMD_SENT_FORCE_EN_Pos 20UL
#define I3C_CORE_INTR_FORCE_EXT_CMD_SENT_FORCE_EN_Msk 0x100000UL
/* I3C_CORE.QUEUE_STATUS_LEVEL */
#define I3C_CORE_QUEUE_STATUS_LEVEL_CMD_QUEUE_EMPTY_LOC_Pos 0UL
#define I3C_CORE_QUEUE_STATUS_LEVEL_CMD_QUEUE_EMPTY_LOC_Msk 0xFFUL
#define I3C_CORE_QUEUE_STATUS_LEVEL_RESP_BUF_BLR_Pos 8UL
#define I3C_CORE_QUEUE_STATUS_LEVEL_RESP_BUF_BLR_Msk 0xFF00UL
#define I3C_CORE_QUEUE_STATUS_LEVEL_IBI_BUF_BLR_Pos 16UL
#define I3C_CORE_QUEUE_STATUS_LEVEL_IBI_BUF_BLR_Msk 0xFF0000UL
#define I3C_CORE_QUEUE_STATUS_LEVEL_IBI_STS_CNT_Pos 24UL
#define I3C_CORE_QUEUE_STATUS_LEVEL_IBI_STS_CNT_Msk 0x1F000000UL
/* I3C_CORE.DATA_BUFFER_STATUS_LEVEL */
#define I3C_CORE_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC_Pos 0UL
#define I3C_CORE_DATA_BUFFER_STATUS_LEVEL_TX_BUF_EMPTY_LOC_Msk 0xFFUL
#define I3C_CORE_DATA_BUFFER_STATUS_LEVEL_RX_BUF_BLR_Pos 16UL
#define I3C_CORE_DATA_BUFFER_STATUS_LEVEL_RX_BUF_BLR_Msk 0xFF0000UL
/* I3C_CORE.PRESENT_STATE */
#define I3C_CORE_PRESENT_STATE_SCL_LINE_SIGNAL_LEVEL_Pos 0UL
#define I3C_CORE_PRESENT_STATE_SCL_LINE_SIGNAL_LEVEL_Msk 0x1UL
#define I3C_CORE_PRESENT_STATE_SDA_LINE_SIGNAL_LEVEL_Pos 1UL
#define I3C_CORE_PRESENT_STATE_SDA_LINE_SIGNAL_LEVEL_Msk 0x2UL
#define I3C_CORE_PRESENT_STATE_ACTIVE_CONTROLLER_Pos 2UL
#define I3C_CORE_PRESENT_STATE_ACTIVE_CONTROLLER_Msk 0x4UL
#define I3C_CORE_PRESENT_STATE_CM_TFR_STS_Pos   8UL
#define I3C_CORE_PRESENT_STATE_CM_TFR_STS_Msk   0x3F00UL
#define I3C_CORE_PRESENT_STATE_CM_TFR_ST_STS_Pos 16UL
#define I3C_CORE_PRESENT_STATE_CM_TFR_ST_STS_Msk 0x3F0000UL
#define I3C_CORE_PRESENT_STATE_CMD_TID_Pos      24UL
#define I3C_CORE_PRESENT_STATE_CMD_TID_Msk      0xF000000UL
#define I3C_CORE_PRESENT_STATE_CONTROLLER_IDLE_Pos 28UL
#define I3C_CORE_PRESENT_STATE_CONTROLLER_IDLE_Msk 0x10000000UL
/* I3C_CORE.CCC_DEVICE_STATUS */
#define I3C_CORE_CCC_DEVICE_STATUS_PENDING_INTR_Pos 0UL
#define I3C_CORE_CCC_DEVICE_STATUS_PENDING_INTR_Msk 0xFUL
#define I3C_CORE_CCC_DEVICE_STATUS_PROTOCOL_ERR_Pos 5UL
#define I3C_CORE_CCC_DEVICE_STATUS_PROTOCOL_ERR_Msk 0x20UL
#define I3C_CORE_CCC_DEVICE_STATUS_ACTIVITY_MODE_Pos 6UL
#define I3C_CORE_CCC_DEVICE_STATUS_ACTIVITY_MODE_Msk 0xC0UL
#define I3C_CORE_CCC_DEVICE_STATUS_UNDERFLOW_ERR_Pos 8UL
#define I3C_CORE_CCC_DEVICE_STATUS_UNDERFLOW_ERR_Msk 0x100UL
#define I3C_CORE_CCC_DEVICE_STATUS_TARGET_BUSY_Pos 9UL
#define I3C_CORE_CCC_DEVICE_STATUS_TARGET_BUSY_Msk 0x200UL
#define I3C_CORE_CCC_DEVICE_STATUS_OVERFLOW_ERR_Pos 10UL
#define I3C_CORE_CCC_DEVICE_STATUS_OVERFLOW_ERR_Msk 0x400UL
#define I3C_CORE_CCC_DEVICE_STATUS_DATA_NOT_READY_Pos 11UL
#define I3C_CORE_CCC_DEVICE_STATUS_DATA_NOT_READY_Msk 0x800UL
#define I3C_CORE_CCC_DEVICE_STATUS_BUFFER_NOT_AVAIL_Pos 12UL
#define I3C_CORE_CCC_DEVICE_STATUS_BUFFER_NOT_AVAIL_Msk 0x1000UL
#define I3C_CORE_CCC_DEVICE_STATUS_FRAME_ERROR_Pos 13UL
#define I3C_CORE_CCC_DEVICE_STATUS_FRAME_ERROR_Msk 0x2000UL
/* I3C_CORE.DEVICE_ADDR_TABLE_POINTER */
#define I3C_CORE_DEVICE_ADDR_TABLE_POINTER_P_DEV_ADDR_TABLE_START_ADDR_Pos 0UL
#define I3C_CORE_DEVICE_ADDR_TABLE_POINTER_P_DEV_ADDR_TABLE_START_ADDR_Msk 0xFFFFUL
#define I3C_CORE_DEVICE_ADDR_TABLE_POINTER_DEV_ADDR_TABLE_DEPTH_Pos 16UL
#define I3C_CORE_DEVICE_ADDR_TABLE_POINTER_DEV_ADDR_TABLE_DEPTH_Msk 0xFFFF0000UL
/* I3C_CORE.DEV_CHAR_TABLE_POINTER */
#define I3C_CORE_DEV_CHAR_TABLE_POINTER_P_DEV_CHAR_TABLE_START_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE_POINTER_P_DEV_CHAR_TABLE_START_ADDR_Msk 0xFFFUL
#define I3C_CORE_DEV_CHAR_TABLE_POINTER_DEV_CHAR_TABLE_DEPTH_Pos 12UL
#define I3C_CORE_DEV_CHAR_TABLE_POINTER_DEV_CHAR_TABLE_DEPTH_Msk 0x7F000UL
#define I3C_CORE_DEV_CHAR_TABLE_POINTER_PRESENT_DEV_CHAR_TABLE_INDX_Pos 19UL
#define I3C_CORE_DEV_CHAR_TABLE_POINTER_PRESENT_DEV_CHAR_TABLE_INDX_Msk 0x780000UL
/* I3C_CORE.VENDOR_SPECIFIC_REG_POINTER */
#define I3C_CORE_VENDOR_SPECIFIC_REG_POINTER_P_VENDOR_REG_START_ADDR_Pos 0UL
#define I3C_CORE_VENDOR_SPECIFIC_REG_POINTER_P_VENDOR_REG_START_ADDR_Msk 0xFFFFUL
/* I3C_CORE.TGT_MIPI_ID_VALUE */
#define I3C_CORE_TGT_MIPI_ID_VALUE_TGT_PROV_ID_SEL_Pos 0UL
#define I3C_CORE_TGT_MIPI_ID_VALUE_TGT_PROV_ID_SEL_Msk 0x1UL
#define I3C_CORE_TGT_MIPI_ID_VALUE_TGT_MIPI_MFG_ID_Pos 1UL
#define I3C_CORE_TGT_MIPI_ID_VALUE_TGT_MIPI_MFG_ID_Msk 0xFFFEUL
/* I3C_CORE.TGT_PID_VALUE */
#define I3C_CORE_TGT_PID_VALUE_TGT_PID_DCR_Pos  0UL
#define I3C_CORE_TGT_PID_VALUE_TGT_PID_DCR_Msk  0xFFFUL
#define I3C_CORE_TGT_PID_VALUE_TGT_INST_ID_Pos  12UL
#define I3C_CORE_TGT_PID_VALUE_TGT_INST_ID_Msk  0xF000UL
#define I3C_CORE_TGT_PID_VALUE_TGT_PART_ID_Pos  16UL
#define I3C_CORE_TGT_PID_VALUE_TGT_PART_ID_Msk  0xFFFF0000UL
/* I3C_CORE.TGT_CHAR_CTRL */
#define I3C_CORE_TGT_CHAR_CTRL_MAX_DATA_SPEED_LIMIT_Pos 0UL
#define I3C_CORE_TGT_CHAR_CTRL_MAX_DATA_SPEED_LIMIT_Msk 0x1UL
#define I3C_CORE_TGT_CHAR_CTRL_IBI_REQUEST_CAPABLE_Pos 1UL
#define I3C_CORE_TGT_CHAR_CTRL_IBI_REQUEST_CAPABLE_Msk 0x2UL
#define I3C_CORE_TGT_CHAR_CTRL_IBI_PAYLOAD_Pos  2UL
#define I3C_CORE_TGT_CHAR_CTRL_IBI_PAYLOAD_Msk  0x4UL
#define I3C_CORE_TGT_CHAR_CTRL_OFFLINE_CAPABLE_Pos 3UL
#define I3C_CORE_TGT_CHAR_CTRL_OFFLINE_CAPABLE_Msk 0x8UL
#define I3C_CORE_TGT_CHAR_CTRL_BRIDGE_IDENTIFIER_Pos 4UL
#define I3C_CORE_TGT_CHAR_CTRL_BRIDGE_IDENTIFIER_Msk 0x10UL
#define I3C_CORE_TGT_CHAR_CTRL_HDR_CAPABLE_Pos  5UL
#define I3C_CORE_TGT_CHAR_CTRL_HDR_CAPABLE_Msk  0x20UL
#define I3C_CORE_TGT_CHAR_CTRL_DEVICE_ROLE_Pos  6UL
#define I3C_CORE_TGT_CHAR_CTRL_DEVICE_ROLE_Msk  0xC0UL
#define I3C_CORE_TGT_CHAR_CTRL_DCR_Pos          8UL
#define I3C_CORE_TGT_CHAR_CTRL_DCR_Msk          0xFF00UL
#define I3C_CORE_TGT_CHAR_CTRL_HDR_CAP_Pos      16UL
#define I3C_CORE_TGT_CHAR_CTRL_HDR_CAP_Msk      0xFF0000UL
/* I3C_CORE.TGT_MAX_LEN */
#define I3C_CORE_TGT_MAX_LEN_MWL_Pos            0UL
#define I3C_CORE_TGT_MAX_LEN_MWL_Msk            0xFFFFUL
#define I3C_CORE_TGT_MAX_LEN_MRL_Pos            16UL
#define I3C_CORE_TGT_MAX_LEN_MRL_Msk            0xFFFF0000UL
/* I3C_CORE.MAX_READ_TURNAROUND */
#define I3C_CORE_MAX_READ_TURNAROUND_MXDS_MAX_RD_TURN_Pos 0UL
#define I3C_CORE_MAX_READ_TURNAROUND_MXDS_MAX_RD_TURN_Msk 0xFFFFFFUL
/* I3C_CORE.MAX_DATA_SPEED */
#define I3C_CORE_MAX_DATA_SPEED_MXDS_MAX_WR_SPEED_Pos 0UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_MAX_WR_SPEED_Msk 0x7UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_DEF_BYTE_SUPPORT_Pos 3UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_DEF_BYTE_SUPPORT_Msk 0x8UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_MAX_RD_SPEED_Pos 8UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_MAX_RD_SPEED_Msk 0x700UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_CLK_DATA_TURN_Pos 16UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_CLK_DATA_TURN_Msk 0x70000UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_STOP_PERMIT_Pos 19UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_STOP_PERMIT_Msk 0x80000UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_ACTIVITY_STATE_Pos 24UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_ACTIVITY_STATE_Msk 0x3000000UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_SET_ACTIVITY_STATE_Pos 26UL
#define I3C_CORE_MAX_DATA_SPEED_MXDS_SET_ACTIVITY_STATE_Msk 0x4000000UL
/* I3C_CORE.TGT_INTR_REQ */
#define I3C_CORE_TGT_INTR_REQ_TIR_Pos           0UL
#define I3C_CORE_TGT_INTR_REQ_TIR_Msk           0x1UL
#define I3C_CORE_TGT_INTR_REQ_TIR_CTRL_Pos      1UL
#define I3C_CORE_TGT_INTR_REQ_TIR_CTRL_Msk      0x6UL
#define I3C_CORE_TGT_INTR_REQ_CR_Pos            3UL
#define I3C_CORE_TGT_INTR_REQ_CR_Msk            0x8UL
#define I3C_CORE_TGT_INTR_REQ_TS_Pos            4UL
#define I3C_CORE_TGT_INTR_REQ_TS_Msk            0x10UL
#define I3C_CORE_TGT_INTR_REQ_CE3_RECOVERY_Pos  7UL
#define I3C_CORE_TGT_INTR_REQ_CE3_RECOVERY_Msk  0x80UL
#define I3C_CORE_TGT_INTR_REQ_MDB_Pos           8UL
#define I3C_CORE_TGT_INTR_REQ_MDB_Msk           0xFF00UL
#define I3C_CORE_TGT_INTR_REQ_TIR_DATA_LENGTH_Pos 16UL
#define I3C_CORE_TGT_INTR_REQ_TIR_DATA_LENGTH_Msk 0xFF0000UL
/* I3C_CORE.TGT_TIR_DATA */
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE0_Pos 0UL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE0_Msk 0xFFUL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE1_Pos 8UL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE1_Msk 0xFF00UL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE2_Pos 16UL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE2_Msk 0xFF0000UL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE3_Pos 24UL
#define I3C_CORE_TGT_TIR_DATA_TIR_DATA_BYTE3_Msk 0xFF000000UL
/* I3C_CORE.TGT_IBI_RESP */
#define I3C_CORE_TGT_IBI_RESP_IBI_STS_Pos       0UL
#define I3C_CORE_TGT_IBI_RESP_IBI_STS_Msk       0x3UL
#define I3C_CORE_TGT_IBI_RESP_TIR_RESP_DATA_LENGTH_Pos 8UL
#define I3C_CORE_TGT_IBI_RESP_TIR_RESP_DATA_LENGTH_Msk 0xFFFF00UL
/* I3C_CORE.DEVICE_CTRL_EXTENDED */
#define I3C_CORE_DEVICE_CTRL_EXTENDED_DEV_OPERATION_MODE_Pos 0UL
#define I3C_CORE_DEVICE_CTRL_EXTENDED_DEV_OPERATION_MODE_Msk 0x3UL
#define I3C_CORE_DEVICE_CTRL_EXTENDED_GETACCCR_ACK_CTRL_Pos 3UL
#define I3C_CORE_DEVICE_CTRL_EXTENDED_GETACCCR_ACK_CTRL_Msk 0x8UL
#define I3C_CORE_DEVICE_CTRL_EXTENDED_DEEP_SLEEP_CAP_Pos 4UL
#define I3C_CORE_DEVICE_CTRL_EXTENDED_DEEP_SLEEP_CAP_Msk 0x10UL
/* I3C_CORE.SCL_I3C_OD_TIMING */
#define I3C_CORE_SCL_I3C_OD_TIMING_I3C_OD_LCNT_Pos 0UL
#define I3C_CORE_SCL_I3C_OD_TIMING_I3C_OD_LCNT_Msk 0xFFUL
#define I3C_CORE_SCL_I3C_OD_TIMING_I3C_OD_HCNT_Pos 16UL
#define I3C_CORE_SCL_I3C_OD_TIMING_I3C_OD_HCNT_Msk 0xFF0000UL
/* I3C_CORE.SCL_I3C_PP_TIMING */
#define I3C_CORE_SCL_I3C_PP_TIMING_I3C_PP_LCNT_Pos 0UL
#define I3C_CORE_SCL_I3C_PP_TIMING_I3C_PP_LCNT_Msk 0xFFUL
#define I3C_CORE_SCL_I3C_PP_TIMING_I3C_PP_HCNT_Pos 16UL
#define I3C_CORE_SCL_I3C_PP_TIMING_I3C_PP_HCNT_Msk 0xFF0000UL
/* I3C_CORE.SCL_I2C_FM_TIMING */
#define I3C_CORE_SCL_I2C_FM_TIMING_I2C_FM_LCNT_Pos 0UL
#define I3C_CORE_SCL_I2C_FM_TIMING_I2C_FM_LCNT_Msk 0xFFFFUL
#define I3C_CORE_SCL_I2C_FM_TIMING_I2C_FM_HCNT_Pos 16UL
#define I3C_CORE_SCL_I2C_FM_TIMING_I2C_FM_HCNT_Msk 0xFFFF0000UL
/* I3C_CORE.SCL_I2C_FMP_TIMING */
#define I3C_CORE_SCL_I2C_FMP_TIMING_I2C_FMP_LCNT_Pos 0UL
#define I3C_CORE_SCL_I2C_FMP_TIMING_I2C_FMP_LCNT_Msk 0xFFFFUL
#define I3C_CORE_SCL_I2C_FMP_TIMING_I2C_FMP_HCNT_Pos 16UL
#define I3C_CORE_SCL_I2C_FMP_TIMING_I2C_FMP_HCNT_Msk 0xFF0000UL
/* I3C_CORE.SCL_EXT_LCNT_TIMING */
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_1_Pos 0UL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_1_Msk 0xFFUL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_2_Pos 8UL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_2_Msk 0xFF00UL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_3_Pos 16UL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_3_Msk 0xFF0000UL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_4_Pos 24UL
#define I3C_CORE_SCL_EXT_LCNT_TIMING_I3C_EXT_LCNT_4_Msk 0xFF000000UL
/* I3C_CORE.SCL_EXT_TERMN_LCNT_TIMING */
#define I3C_CORE_SCL_EXT_TERMN_LCNT_TIMING_I3C_EXT_TERMN_LCNT_Pos 0UL
#define I3C_CORE_SCL_EXT_TERMN_LCNT_TIMING_I3C_EXT_TERMN_LCNT_Msk 0xFUL
#define I3C_CORE_SCL_EXT_TERMN_LCNT_TIMING_STOP_HLD_CNT_Pos 28UL
#define I3C_CORE_SCL_EXT_TERMN_LCNT_TIMING_STOP_HLD_CNT_Msk 0xF0000000UL
/* I3C_CORE.SDA_HOLD_SWITCH_DLY_TIMING */
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING_SDA_OD_PP_SWITCH_DLY_Pos 0UL
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING_SDA_OD_PP_SWITCH_DLY_Msk 0x7UL
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING_SDA_PP_OD_SWITCH_DLY_Pos 8UL
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING_SDA_PP_OD_SWITCH_DLY_Msk 0x700UL
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING_SDA_TX_HOLD_Pos 16UL
#define I3C_CORE_SDA_HOLD_SWITCH_DLY_TIMING_SDA_TX_HOLD_Msk 0x70000UL
/* I3C_CORE.BUS_FREE_AVAIL_TIMING */
#define I3C_CORE_BUS_FREE_AVAIL_TIMING_BUS_FREE_TIME_Pos 0UL
#define I3C_CORE_BUS_FREE_AVAIL_TIMING_BUS_FREE_TIME_Msk 0xFFFFUL
#define I3C_CORE_BUS_FREE_AVAIL_TIMING_BUS_AVAILABLE_TIME_Pos 16UL
#define I3C_CORE_BUS_FREE_AVAIL_TIMING_BUS_AVAILABLE_TIME_Msk 0xFFFF0000UL
/* I3C_CORE.BUS_IDLE_TIMING */
#define I3C_CORE_BUS_IDLE_TIMING_BUS_IDLE_TIME_Pos 0UL
#define I3C_CORE_BUS_IDLE_TIMING_BUS_IDLE_TIME_Msk 0xFFFFFUL
/* I3C_CORE.SCL_LOW_CTR_EXT_TIMEOUT */
#define I3C_CORE_SCL_LOW_CTR_EXT_TIMEOUT_SCL_LOW_CTR_TIMEOUT_COUNT_Pos 0UL
#define I3C_CORE_SCL_LOW_CTR_EXT_TIMEOUT_SCL_LOW_CTR_TIMEOUT_COUNT_Msk 0x3FFFFFFUL
/* I3C_CORE.RELEASE_SDA_TIMING */
#define I3C_CORE_RELEASE_SDA_TIMING_RELEASE_SDA_TIME_Pos 0UL
#define I3C_CORE_RELEASE_SDA_TIMING_RELEASE_SDA_TIME_Msk 0xFFFFFUL
/* I3C_CORE.EXT_TX_DATA_PORT_0 */
#define I3C_CORE_EXT_TX_DATA_PORT_0_EXT_TX_DATA_PORT_0_Pos 0UL
#define I3C_CORE_EXT_TX_DATA_PORT_0_EXT_TX_DATA_PORT_0_Msk 0xFFFFFFFFUL
/* I3C_CORE.EXT_TX_DATA_PORT_1 */
#define I3C_CORE_EXT_TX_DATA_PORT_1_EXT_TX_DATA_PORT_1_Pos 0UL
#define I3C_CORE_EXT_TX_DATA_PORT_1_EXT_TX_DATA_PORT_1_Msk 0xFFFFFFFFUL
/* I3C_CORE.EXT_TX_DATA_PORT_2 */
#define I3C_CORE_EXT_TX_DATA_PORT_2_EXT_TX_DATA_PORT_2_Pos 0UL
#define I3C_CORE_EXT_TX_DATA_PORT_2_EXT_TX_DATA_PORT_2_Msk 0xFFFFFFFFUL
/* I3C_CORE.EXT_TX_DATA_PORT_3 */
#define I3C_CORE_EXT_TX_DATA_PORT_3_EXT_TX_DATA_PORT_3_Pos 0UL
#define I3C_CORE_EXT_TX_DATA_PORT_3_EXT_TX_DATA_PORT_3_Msk 0xFFFFFFFFUL
/* I3C_CORE.EXT_0_1_DATA_BUF_STS_LEVEL */
#define I3C_CORE_EXT_0_1_DATA_BUF_STS_LEVEL_EXT_0_TX_BUF_EMPTY_LOC_Pos 0UL
#define I3C_CORE_EXT_0_1_DATA_BUF_STS_LEVEL_EXT_0_TX_BUF_EMPTY_LOC_Msk 0xFFUL
#define I3C_CORE_EXT_0_1_DATA_BUF_STS_LEVEL_EXT_1_TX_BUF_EMPTY_LOC_Pos 16UL
#define I3C_CORE_EXT_0_1_DATA_BUF_STS_LEVEL_EXT_1_TX_BUF_EMPTY_LOC_Msk 0xFF0000UL
/* I3C_CORE.EXT_2_3_DATA_BUF_STS_LEVEL */
#define I3C_CORE_EXT_2_3_DATA_BUF_STS_LEVEL_EXT_2_TX_BUF_EMPTY_LOC_Pos 0UL
#define I3C_CORE_EXT_2_3_DATA_BUF_STS_LEVEL_EXT_2_TX_BUF_EMPTY_LOC_Msk 0xFFUL
#define I3C_CORE_EXT_2_3_DATA_BUF_STS_LEVEL_EXT_3_TX_BUF_EMPTY_LOC_Pos 16UL
#define I3C_CORE_EXT_2_3_DATA_BUF_STS_LEVEL_EXT_3_TX_BUF_EMPTY_LOC_Msk 0xFF0000UL
/* I3C_CORE.EXT_CMD_REG_0 */
#define I3C_CORE_EXT_CMD_REG_0_TID_Pos          3UL
#define I3C_CORE_EXT_CMD_REG_0_TID_Msk          0x38UL
#define I3C_CORE_EXT_CMD_REG_0_DL_LSB_Pos       6UL
#define I3C_CORE_EXT_CMD_REG_0_DL_LSB_Msk       0xC0UL
#define I3C_CORE_EXT_CMD_REG_0_DEFINING_BYTE_Pos 16UL
#define I3C_CORE_EXT_CMD_REG_0_DEFINING_BYTE_Msk 0xFF0000UL
#define I3C_CORE_EXT_CMD_REG_0_CCC_TYPE_Pos     24UL
#define I3C_CORE_EXT_CMD_REG_0_CCC_TYPE_Msk     0xFF000000UL
/* I3C_CORE.EXT_CMD_REG_1 */
#define I3C_CORE_EXT_CMD_REG_1_TID_Pos          3UL
#define I3C_CORE_EXT_CMD_REG_1_TID_Msk          0x38UL
#define I3C_CORE_EXT_CMD_REG_1_DL_LSB_Pos       6UL
#define I3C_CORE_EXT_CMD_REG_1_DL_LSB_Msk       0xC0UL
#define I3C_CORE_EXT_CMD_REG_1_DEFINING_BYTE_Pos 16UL
#define I3C_CORE_EXT_CMD_REG_1_DEFINING_BYTE_Msk 0xFF0000UL
#define I3C_CORE_EXT_CMD_REG_1_CCC_TYPE_Pos     24UL
#define I3C_CORE_EXT_CMD_REG_1_CCC_TYPE_Msk     0xFF000000UL
/* I3C_CORE.EXT_CMD_REG_2 */
#define I3C_CORE_EXT_CMD_REG_2_TID_Pos          3UL
#define I3C_CORE_EXT_CMD_REG_2_TID_Msk          0x38UL
#define I3C_CORE_EXT_CMD_REG_2_DL_LSB_Pos       6UL
#define I3C_CORE_EXT_CMD_REG_2_DL_LSB_Msk       0xC0UL
#define I3C_CORE_EXT_CMD_REG_2_DEFINING_BYTE_Pos 16UL
#define I3C_CORE_EXT_CMD_REG_2_DEFINING_BYTE_Msk 0xFF0000UL
#define I3C_CORE_EXT_CMD_REG_2_CCC_TYPE_Pos     24UL
#define I3C_CORE_EXT_CMD_REG_2_CCC_TYPE_Msk     0xFF000000UL
/* I3C_CORE.EXT_CMD_REG_3 */
#define I3C_CORE_EXT_CMD_REG_3_TID_Pos          3UL
#define I3C_CORE_EXT_CMD_REG_3_TID_Msk          0x38UL
#define I3C_CORE_EXT_CMD_REG_3_DL_LSB_Pos       6UL
#define I3C_CORE_EXT_CMD_REG_3_DL_LSB_Msk       0xC0UL
#define I3C_CORE_EXT_CMD_REG_3_DEFINING_BYTE_Pos 16UL
#define I3C_CORE_EXT_CMD_REG_3_DEFINING_BYTE_Msk 0xFF0000UL
#define I3C_CORE_EXT_CMD_REG_3_CCC_TYPE_Pos     24UL
#define I3C_CORE_EXT_CMD_REG_3_CCC_TYPE_Msk     0xFF000000UL
/* I3C_CORE.EXT_TX_QUEUE_RESET_CTRL */
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_0_Pos 0UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_0_Msk 0x1UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_1_Pos 1UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_1_Msk 0x2UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_2_Pos 2UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_2_Msk 0x4UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_3_Pos 3UL
#define I3C_CORE_EXT_TX_QUEUE_RESET_CTRL_EXT_TX_FIFO_RST_3_Msk 0x8UL
/* I3C_CORE.DEV_CHAR_TABLE1_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE1_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE1_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE1_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE1_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE1_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE1_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE1_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE1_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE1_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE1_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE1_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE1_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE1_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE2_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE2_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE2_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE2_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE2_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE2_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE2_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE2_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE2_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE2_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE2_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE2_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE2_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE2_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE3_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE3_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE3_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE3_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE3_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE3_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE3_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE3_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE3_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE3_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE3_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE3_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE3_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE3_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE4_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE4_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE4_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE4_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE4_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE4_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE4_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE4_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE4_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE4_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE4_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE4_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE4_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE4_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE5_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE5_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE5_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE5_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE5_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE5_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE5_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE5_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE5_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE5_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE5_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE5_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE5_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE5_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE6_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE6_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE6_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE6_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE6_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE6_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE6_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE6_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE6_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE6_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE6_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE6_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE6_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE6_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE7_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE7_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE7_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE7_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE7_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE7_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE7_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE7_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE7_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE7_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE7_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE7_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE7_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE7_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE8_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE8_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE8_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE8_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE8_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE8_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE8_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE8_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE8_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE8_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE8_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE8_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE8_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE8_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE9_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE9_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE9_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE9_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE9_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE9_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE9_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE9_LOC3_DCR_Pos   0UL
#define I3C_CORE_DEV_CHAR_TABLE9_LOC3_DCR_Msk   0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE9_LOC3_BCR_Pos   8UL
#define I3C_CORE_DEV_CHAR_TABLE9_LOC3_BCR_Msk   0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE9_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE9_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE9_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE10_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE10_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE10_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE10_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE10_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE10_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE10_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE10_LOC3_DCR_Pos  0UL
#define I3C_CORE_DEV_CHAR_TABLE10_LOC3_DCR_Msk  0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE10_LOC3_BCR_Pos  8UL
#define I3C_CORE_DEV_CHAR_TABLE10_LOC3_BCR_Msk  0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE10_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE10_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE10_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_CHAR_TABLE11_LOC1 */
#define I3C_CORE_DEV_CHAR_TABLE11_LOC1_MSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE11_LOC1_MSB_PROVISIONAL_ID_Msk 0xFFFFFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE11_LOC2 */
#define I3C_CORE_DEV_CHAR_TABLE11_LOC2_LSB_PROVISIONAL_ID_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE11_LOC2_LSB_PROVISIONAL_ID_Msk 0xFFFFUL
/* I3C_CORE.DEV_CHAR_TABLE11_LOC3 */
#define I3C_CORE_DEV_CHAR_TABLE11_LOC3_DCR_Pos  0UL
#define I3C_CORE_DEV_CHAR_TABLE11_LOC3_DCR_Msk  0xFFUL
#define I3C_CORE_DEV_CHAR_TABLE11_LOC3_BCR_Pos  8UL
#define I3C_CORE_DEV_CHAR_TABLE11_LOC3_BCR_Msk  0xFF00UL
/* I3C_CORE.DEV_CHAR_TABLE11_LOC4 */
#define I3C_CORE_DEV_CHAR_TABLE11_LOC4_DEV_DYNAMIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_CHAR_TABLE11_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFFUL
/* I3C_CORE.DEV_ADDR_TABLE_LOC1 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC1_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC2 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC2_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC3 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC3_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC4 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC4_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC5 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC5_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC6 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC6_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC7 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC7_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC8 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC8_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC9 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_TS_Pos     15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_TS_Msk     0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC9_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC10 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_TS_Pos    15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_TS_Msk    0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC10_LEGACY_I2C_DEVICE_Msk 0x80000000UL
/* I3C_CORE.DEV_ADDR_TABLE_LOC11 */
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_DEV_STATIC_ADDR_Pos 0UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_DEV_STATIC_ADDR_Msk 0x7FUL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_IBI_PEC_EN_Pos 11UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_IBI_PEC_EN_Msk 0x800UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_IBI_WITH_DATA_Pos 12UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_IBI_WITH_DATA_Msk 0x1000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_TIR_REJECT_Pos 13UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_TIR_REJECT_Msk 0x2000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_CR_REJECT_Pos 14UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_CR_REJECT_Msk 0x4000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_TS_Pos    15UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_TS_Msk    0x8000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_DEV_DYNAMIC_ADDR_Pos 16UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_DEV_DYNAMIC_ADDR_Msk 0xFF0000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_DEV_NACK_RETRY_CNT_Pos 29UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_DEV_NACK_RETRY_CNT_Msk 0x60000000UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_LEGACY_I2C_DEVICE_Pos 31UL
#define I3C_CORE_DEV_ADDR_TABLE_LOC11_LEGACY_I2C_DEVICE_Msk 0x80000000UL


/* I3C.CTRL */
#define I3C_CTRL_ENABLED_Pos                    31UL
#define I3C_CTRL_ENABLED_Msk                    0x80000000UL
/* I3C.TGT_STATUS */
#define I3C_TGT_STATUS_WAKEUP_Pos               0UL
#define I3C_TGT_STATUS_WAKEUP_Msk               0x1UL
#define I3C_TGT_STATUS_I2C_GLITCH_FILTER_EN_Pos 8UL
#define I3C_TGT_STATUS_I2C_GLITCH_FILTER_EN_Msk 0x100UL
#define I3C_TGT_STATUS_IBI_PAYLOAD_SIZE_Pos     16UL
#define I3C_TGT_STATUS_IBI_PAYLOAD_SIZE_Msk     0xFF0000UL
/* I3C.CCC_GETSTATUS */
#define I3C_CCC_GETSTATUS_PENDING_INT_Pos       16UL
#define I3C_CCC_GETSTATUS_PENDING_INT_Msk       0xF0000UL
#define I3C_CCC_GETSTATUS_ACT_MODE_Pos          24UL
#define I3C_CCC_GETSTATUS_ACT_MODE_Msk          0x3000000UL
/* I3C.TIMING_CNT_CTRL */
#define I3C_TIMING_CNT_CTRL_CNT_RESET_Pos       30UL
#define I3C_TIMING_CNT_CTRL_CNT_RESET_Msk       0x40000000UL
#define I3C_TIMING_CNT_CTRL_CNT_ENABLE_Pos      31UL
#define I3C_TIMING_CNT_CTRL_CNT_ENABLE_Msk      0x80000000UL
/* I3C.TIMING_CNT0 */
#define I3C_TIMING_CNT0_TIMING_COUNTER_MSB_Pos  0UL
#define I3C_TIMING_CNT0_TIMING_COUNTER_MSB_Msk  0xFFFFFFFFUL
/* I3C.TIMING_CNT1 */
#define I3C_TIMING_CNT1_TIMING_COUNTER_LSB_Pos  0UL
#define I3C_TIMING_CNT1_TIMING_COUNTER_LSB_Msk  0xFFFFFFFFUL


#endif /* _CYIP_I3C_V1_1_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* ACTRLR IP definitions
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

#ifndef _CYIP_ACTRLR_V1_1_H_
#define _CYIP_ACTRLR_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    ACTRLR
*******************************************************************************/

#define ACTRLR_TTCFG_SECTION_SIZE               0x00000020UL
#define ACTRLR_SECTION_SIZE                     0x00010000UL

/**
  * \brief Timer Table Structure  (only accessible if CTRL.EN=0) (ACTRLR_TTCFG)
  */
typedef struct {
  __IOM uint32_t TT_CFG0;                       /*!< 0x00000000 AC Table Configuration 0 */
  __IOM uint32_t TT_CFG1;                       /*!< 0x00000004 AC Table Configuration 1 */
  __IOM uint32_t TT_CFG2;                       /*!< 0x00000008 AC Table Configuration 2 */
  __IOM uint32_t TT_CFG3;                       /*!< 0x0000000C AC Table Configuration 3 */
  __IOM uint32_t TT_CFG4;                       /*!< 0x00000010 AC Table Configuration 4 */
   __IM uint32_t RESERVED[3];
} ACTRLR_TTCFG_Type;                            /*!< Size = 32 (0x20) */

/**
  * \brief Autonomnous Controller (ACTRLR)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 control register */
  __IOM uint32_t CMD_RUN;                       /*!< 0x00000004 run command register */
  __IOM uint32_t CMD_STATE;                     /*!< 0x00000008 state override register */
   __IM uint32_t RESERVED;
  __IOM uint32_t FW_TR[4];                      /*!< 0x00000010 firmware trigger */
   __IM uint32_t STATUS;                        /*!< 0x00000020 status register */
  __IOM uint32_t CFG;                           /*!< 0x00000024 config register (only accessible if CTRL.EN=0) */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t DEBUG_PAUSE;                   /*!< 0x00000030 pause debug register */
  __IOM uint32_t DEBUG_SINGLE_STEP;             /*!< 0x00000034 single step debug register */
   __IM uint32_t PWR_STATUS;                    /*!< 0x00000038 power status register */
   __IM uint32_t RESERVED2[49];
   __IM uint32_t CNTR_STATUS[4];                /*!< 0x00000100 Loop/Interval counter status register */
   __IM uint32_t RESERVED3[444];
        ACTRLR_TTCFG_Type TTCFG[64];            /*!< 0x00000800 Timer Table Structure  (only accessible if CTRL.EN=0) */
} ACTRLR_Type;                                  /*!< Size = 4096 (0x1000) */


/* ACTRLR_TTCFG.TT_CFG0 */
#define ACTRLR_TTCFG_TT_CFG0_DOUT_Pos           0UL
#define ACTRLR_TTCFG_TT_CFG0_DOUT_Msk           0xFUL
#define ACTRLR_TTCFG_TT_CFG0_MODE_Pos           4UL
#define ACTRLR_TTCFG_TT_CFG0_MODE_Msk           0x10UL
#define ACTRLR_TTCFG_TT_CFG0_MODE_UNLOCK_Pos    8UL
#define ACTRLR_TTCFG_TT_CFG0_MODE_UNLOCK_Msk    0x100UL
#define ACTRLR_TTCFG_TT_CFG0_PRB_UNLOCK_Pos     9UL
#define ACTRLR_TTCFG_TT_CFG0_PRB_UNLOCK_Msk     0x200UL
#define ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK_Pos     10UL
#define ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK_Msk     0x400UL
#define ACTRLR_TTCFG_TT_CFG0_DAC0_UNLOCK_Pos    11UL
#define ACTRLR_TTCFG_TT_CFG0_DAC0_UNLOCK_Msk    0x800UL
#define ACTRLR_TTCFG_TT_CFG0_DAC1_UNLOCK_Pos    12UL
#define ACTRLR_TTCFG_TT_CFG0_DAC1_UNLOCK_Msk    0x1000UL
#define ACTRLR_TTCFG_TT_CFG0_PTC_UNLOCK_Pos     13UL
#define ACTRLR_TTCFG_TT_CFG0_PTC_UNLOCK_Msk     0x2000UL
#define ACTRLR_TTCFG_TT_CFG0_CTBL0_UNLOCK_Pos   14UL
#define ACTRLR_TTCFG_TT_CFG0_CTBL0_UNLOCK_Msk   0x4000UL
#define ACTRLR_TTCFG_TT_CFG0_CTBL1_UNLOCK_Pos   15UL
#define ACTRLR_TTCFG_TT_CFG0_CTBL1_UNLOCK_Msk   0x8000UL
#define ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK_Pos    16UL
#define ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK_Msk    0x10000UL
/* ACTRLR_TTCFG.TT_CFG1 */
#define ACTRLR_TTCFG_TT_CFG1_BR_ADDR_Pos        0UL
#define ACTRLR_TTCFG_TT_CFG1_BR_ADDR_Msk        0x3FUL
#define ACTRLR_TTCFG_TT_CFG1_RESERVED_0_Pos     6UL
#define ACTRLR_TTCFG_TT_CFG1_RESERVED_0_Msk     0xC0UL
#define ACTRLR_TTCFG_TT_CFG1_COND_Pos           8UL
#define ACTRLR_TTCFG_TT_CFG1_COND_Msk           0x3F00UL
#define ACTRLR_TTCFG_TT_CFG1_RESERVED_1_Pos     14UL
#define ACTRLR_TTCFG_TT_CFG1_RESERVED_1_Msk     0xC000UL
#define ACTRLR_TTCFG_TT_CFG1_ACTION_Pos         16UL
#define ACTRLR_TTCFG_TT_CFG1_ACTION_Msk         0x70000UL
#define ACTRLR_TTCFG_TT_CFG1_INTR_SET_Pos       19UL
#define ACTRLR_TTCFG_TT_CFG1_INTR_SET_Msk       0x80000UL
#define ACTRLR_TTCFG_TT_CFG1_CNT_Pos            20UL
#define ACTRLR_TTCFG_TT_CFG1_CNT_Msk            0xFFF00000UL
/* ACTRLR_TTCFG.TT_CFG2 */
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_GAIN_Pos 0UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_GAIN_Msk 0xFUL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_CFG_Pos  4UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_CFG_Msk  0x70UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_EN_Pos   7UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_EN_Msk   0x80UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_GAIN_Pos 8UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_GAIN_Msk 0xF00UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_CFG_Pos  12UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_CFG_Msk  0x7000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_EN_Pos   15UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_EN_Msk   0x8000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_GAIN_Pos 16UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_GAIN_Msk 0xF0000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_CFG_Pos  20UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_CFG_Msk  0x700000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_EN_Pos   23UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_EN_Msk   0x800000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_GAIN_Pos 24UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_GAIN_Msk 0xF000000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_CFG_Pos  28UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_CFG_Msk  0x70000000UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_EN_Pos   31UL
#define ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_EN_Msk   0x80000000UL
/* ACTRLR_TTCFG.TT_CFG3 */
#define ACTRLR_TTCFG_TT_CFG3_SAR_ENTRY_ADDR_Pos 0UL
#define ACTRLR_TTCFG_TT_CFG3_SAR_ENTRY_ADDR_Msk 0x1FUL
#define ACTRLR_TTCFG_TT_CFG3_RESERVED_2_Pos     5UL
#define ACTRLR_TTCFG_TT_CFG3_RESERVED_2_Msk     0x20UL
#define ACTRLR_TTCFG_TT_CFG3_SAR_TR_Pos         6UL
#define ACTRLR_TTCFG_TT_CFG3_SAR_TR_Msk         0x40UL
#define ACTRLR_TTCFG_TT_CFG3_SAR_EN_Pos         7UL
#define ACTRLR_TTCFG_TT_CFG3_SAR_EN_Msk         0x80UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_CHANNEL_Pos   8UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_CHANNEL_Msk   0xF00UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_TR_Pos        12UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_TR_Msk        0x1000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_INC_Pos       13UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_INC_Msk       0x2000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_DEC_Pos       14UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_DEC_Msk       0x4000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_EN_Pos        15UL
#define ACTRLR_TTCFG_TT_CFG3_DAC0_EN_Msk        0x8000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_CHANNEL_Pos   16UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_CHANNEL_Msk   0xF0000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_TR_Pos        20UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_TR_Msk        0x100000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_INC_Pos       21UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_INC_Msk       0x200000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_DEC_Pos       22UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_DEC_Msk       0x400000UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_EN_Pos        23UL
#define ACTRLR_TTCFG_TT_CFG3_DAC1_EN_Msk        0x800000UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_CFG_Pos   24UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_CFG_Msk   0x7000000UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_EN_Pos    27UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_EN_Msk    0x8000000UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_CFG_Pos   28UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_CFG_Msk   0x70000000UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_EN_Pos    31UL
#define ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_EN_Msk    0x80000000UL
/* ACTRLR_TTCFG.TT_CFG4 */
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF0_VAL_Pos  16UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF0_VAL_Msk  0xF0000UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF0_FW_MODE_Pos 23UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF0_FW_MODE_Msk 0x800000UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF1_VAL_Pos  24UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF1_VAL_Msk  0xF000000UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF1_FW_MODE_Pos 31UL
#define ACTRLR_TTCFG_TT_CFG4_PRB_VREF1_FW_MODE_Msk 0x80000000UL


/* ACTRLR.CTRL */
#define ACTRLR_CTRL_ENABLED_Pos                 31UL
#define ACTRLR_CTRL_ENABLED_Msk                 0x80000000UL
/* ACTRLR.CMD_RUN */
#define ACTRLR_CMD_RUN_RUN_Pos                  0UL
#define ACTRLR_CMD_RUN_RUN_Msk                  0x1UL
/* ACTRLR.CMD_STATE */
#define ACTRLR_CMD_STATE_STATE_Pos              0UL
#define ACTRLR_CMD_STATE_STATE_Msk              0x3FUL
/* ACTRLR.FW_TR */
#define ACTRLR_FW_TR_FW_TR_Pos                  0UL
#define ACTRLR_FW_TR_FW_TR_Msk                  0x1UL
/* ACTRLR.STATUS */
#define ACTRLR_STATUS_CUR_STATE_Pos             0UL
#define ACTRLR_STATUS_CUR_STATE_Msk             0x3FUL
#define ACTRLR_STATUS_STATUS_Pos                8UL
#define ACTRLR_STATUS_STATUS_Msk                0x300UL
#define ACTRLR_STATUS_MODE_Pos                  10UL
#define ACTRLR_STATUS_MODE_Msk                  0x400UL
/* ACTRLR.CFG */
#define ACTRLR_CFG_DOUT_EN_Pos                  0UL
#define ACTRLR_CFG_DOUT_EN_Msk                  0xFUL
#define ACTRLR_CFG_SLEEP_MODE_Pos               16UL
#define ACTRLR_CFG_SLEEP_MODE_Msk               0x10000UL
#define ACTRLR_CFG_DISABLE_MODE_Pos             17UL
#define ACTRLR_CFG_DISABLE_MODE_Msk             0x20000UL
/* ACTRLR.DEBUG_PAUSE */
#define ACTRLR_DEBUG_PAUSE_PAUSE_Pos            0UL
#define ACTRLR_DEBUG_PAUSE_PAUSE_Msk            0x1UL
/* ACTRLR.DEBUG_SINGLE_STEP */
#define ACTRLR_DEBUG_SINGLE_STEP_SINGLE_STEP_Pos 0UL
#define ACTRLR_DEBUG_SINGLE_STEP_SINGLE_STEP_Msk 0x1UL
/* ACTRLR.PWR_STATUS */
#define ACTRLR_PWR_STATUS_SW_OK_Pos             0UL
#define ACTRLR_PWR_STATUS_SW_OK_Msk             0x1UL
/* ACTRLR.CNTR_STATUS */
#define ACTRLR_CNTR_STATUS_CUR_STATE_Pos        0UL
#define ACTRLR_CNTR_STATUS_CUR_STATE_Msk        0x3FUL
#define ACTRLR_CNTR_STATUS_CUR_CNT_Pos          8UL
#define ACTRLR_CNTR_STATUS_CUR_CNT_Msk          0xFFF00UL
#define ACTRLR_CNTR_STATUS_BUSY_Pos             31UL
#define ACTRLR_CNTR_STATUS_BUSY_Msk             0x80000000UL


#endif /* _CYIP_ACTRLR_V1_1_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* DAC IP definitions
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

#ifndef _CYIP_DAC_V1_1_H_
#define _CYIP_DAC_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     DAC
*******************************************************************************/

#define DAC_STA_SECTION_SIZE                    0x00000200UL
#define DAC_TRIM_SECTION_SIZE                   0x00000040UL
#define DAC_SECTION_SIZE                        0x00010000UL

/**
  * \brief DAC static configuration registers (DAC_STA)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 DAC control register (only accessible if ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t SAMPLE_TIME;                   /*!< 0x00000004 Sample control register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t STEP_VAL[3];                   /*!< 0x00000008 step val register  (only accessible if ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED;
  __IOM uint32_t DEGLITCH_TIME;                 /*!< 0x00000018 deglitch time register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CHAN_CFG[15];                  /*!< 0x00000020 Channel configuration register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED2;
  __IOM uint32_t FW_DAC_VAL;                    /*!< 0x00000060 Firmare Channel DAC Value (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t FW_DAC_VAL_NXT;                /*!< 0x00000064 Firmware Channel DAC Value Next */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t CHAN_STATUS_CFG[3];            /*!< 0x00000070 Channel status configuration register */
   __IM uint32_t RESERVED4;
  __IOM uint32_t RANGE_STATUS;                  /*!< 0x00000080 Range status register */
   __IM uint32_t RESERVED5[95];
} DAC_STA_Type;                                 /*!< Size = 512 (0x200) */

/**
  * \brief DAC trim registers (only accessible if ACTRLR.STATUS.MODE=0) (DAC_TRIM)
  */
typedef struct {
  __IOM uint32_t REFBUF_OFFSET_TRIM;            /*!< 0x00000000 Reference buffer trim control */
  __IOM uint32_t REFBUF_SLOPE_OFFSET_TRIM;      /*!< 0x00000004 Reference buffer trim control */
  __IOM uint32_t REFBUF_COMP_TRIM;              /*!< 0x00000008 Reference buffer trim control */
  __IOM uint32_t OUTBUF_OFFSET_TRIM[2];         /*!< 0x0000000C Output buffer trim control */
  __IOM uint32_t OUTBUF_SLOPE_OFFSET_TRIM[2];   /*!< 0x00000014 Output buffer trim control */
  __IOM uint32_t OUTBUF_COMP_TRIM[2];           /*!< 0x0000001C Output buffer trim control */
  __IOM uint32_t RMP_TRIM;                      /*!< 0x00000024 Risk Mitigation bits */
   __IM uint32_t RESERVED[6];
} DAC_TRIM_Type;                                /*!< Size = 64 (0x40) */

/**
  * \brief DAC (DAC)
  */
typedef struct {
  __IOM uint32_t SRAM[512];                     /*!< 0x00000000 SRAM Waveform Table (only accessible if ACTRLR.STATUS.MODE=0) */
        DAC_STA_Type STA;                       /*!< 0x00000800 DAC static configuration registers */
   __IM uint32_t RESERVED[320];
        DAC_TRIM_Type TRIM;                     /*!< 0x00000F00 DAC trim registers (only accessible if ACTRLR.STATUS.MODE=0) */
} DAC_Type;                                     /*!< Size = 3904 (0xF40) */


/* DAC_STA.CTRL */
#define DAC_STA_CTRL_TOPO_Pos                   0UL
#define DAC_STA_CTRL_TOPO_Msk                   0x7UL
#define DAC_STA_CTRL_VREF_SEL_Pos               3UL
#define DAC_STA_CTRL_VREF_SEL_Msk               0x8UL
#define DAC_STA_CTRL_DEGLITCH_EN_Pos            4UL
#define DAC_STA_CTRL_DEGLITCH_EN_Msk            0x10UL
#define DAC_STA_CTRL_BOT_SEL_Pos                5UL
#define DAC_STA_CTRL_BOT_SEL_Msk                0x20UL
#define DAC_STA_CTRL_DISABLED_MODE_Pos          6UL
#define DAC_STA_CTRL_DISABLED_MODE_Msk          0x40UL
#define DAC_STA_CTRL_REFBUF_PWR_MODE_Pos        8UL
#define DAC_STA_CTRL_REFBUF_PWR_MODE_Msk        0xF00UL
#define DAC_STA_CTRL_OUTBUF_PWR_MODE_Pos        12UL
#define DAC_STA_CTRL_OUTBUF_PWR_MODE_Msk        0xF000UL
#define DAC_STA_CTRL_FORMAT_Pos                 16UL
#define DAC_STA_CTRL_FORMAT_Msk                 0x10000UL
#define DAC_STA_CTRL_REF_MUX_SEL_Pos            28UL
#define DAC_STA_CTRL_REF_MUX_SEL_Msk            0x70000000UL
/* DAC_STA.SAMPLE_TIME */
#define DAC_STA_SAMPLE_TIME_SAMPLE_TIME_Pos     0UL
#define DAC_STA_SAMPLE_TIME_SAMPLE_TIME_Msk     0xFFUL
/* DAC_STA.STEP_VAL */
#define DAC_STA_STEP_VAL_VAL_Pos                0UL
#define DAC_STA_STEP_VAL_VAL_Msk                0xFFUL
/* DAC_STA.DEGLITCH_TIME */
#define DAC_STA_DEGLITCH_TIME_DEGLITCH_TIME_Pos 0UL
#define DAC_STA_DEGLITCH_TIME_DEGLITCH_TIME_Msk 0xFFUL
/* DAC_STA.CHAN_CFG */
#define DAC_STA_CHAN_CFG_START_ADDR_Pos         0UL
#define DAC_STA_CHAN_CFG_START_ADDR_Msk         0x7FFUL
#define DAC_STA_CHAN_CFG_END_ADDR_Pos           12UL
#define DAC_STA_CHAN_CFG_END_ADDR_Msk           0x7FF000UL
#define DAC_STA_CHAN_CFG_MODE_Pos               24UL
#define DAC_STA_CHAN_CFG_MODE_Msk               0x7000000UL
#define DAC_STA_CHAN_CFG_SAMPLE_AND_HOLD_EN_Pos 27UL
#define DAC_STA_CHAN_CFG_SAMPLE_AND_HOLD_EN_Msk 0x8000000UL
#define DAC_STA_CHAN_CFG_STEP_VAL_SEL_Pos       28UL
#define DAC_STA_CHAN_CFG_STEP_VAL_SEL_Msk       0x30000000UL
#define DAC_STA_CHAN_CFG_STATUS_SEL_Pos         30UL
#define DAC_STA_CHAN_CFG_STATUS_SEL_Msk         0xC0000000UL
/* DAC_STA.FW_DAC_VAL */
#define DAC_STA_FW_DAC_VAL_VALUE_Pos            0UL
#define DAC_STA_FW_DAC_VAL_VALUE_Msk            0xFFFUL
#define DAC_STA_FW_DAC_VAL_OUT_DM_Pos           14UL
#define DAC_STA_FW_DAC_VAL_OUT_DM_Msk           0xC000UL
/* DAC_STA.FW_DAC_VAL_NXT */
#define DAC_STA_FW_DAC_VAL_NXT_VALUE_Pos        0UL
#define DAC_STA_FW_DAC_VAL_NXT_VALUE_Msk        0xFFFUL
#define DAC_STA_FW_DAC_VAL_NXT_OUT_DM_Pos       14UL
#define DAC_STA_FW_DAC_VAL_NXT_OUT_DM_Msk       0xC000UL
/* DAC_STA.CHAN_STATUS_CFG */
#define DAC_STA_CHAN_STATUS_CFG_RANGE_COND_Pos  0UL
#define DAC_STA_CHAN_STATUS_CFG_RANGE_COND_Msk  0x3UL
#define DAC_STA_CHAN_STATUS_CFG_RANGE_LOW_Pos   8UL
#define DAC_STA_CHAN_STATUS_CFG_RANGE_LOW_Msk   0xFFF00UL
#define DAC_STA_CHAN_STATUS_CFG_RANGE_HIGH_Pos  20UL
#define DAC_STA_CHAN_STATUS_CFG_RANGE_HIGH_Msk  0xFFF00000UL
/* DAC_STA.RANGE_STATUS */
#define DAC_STA_RANGE_STATUS_CHAN_RANGE_STATUS_Pos 0UL
#define DAC_STA_RANGE_STATUS_CHAN_RANGE_STATUS_Msk 0x7FFFUL


/* DAC_TRIM.REFBUF_OFFSET_TRIM */
#define DAC_TRIM_REFBUF_OFFSET_TRIM_REFBUF_OFFSET_TRIM_Pos 0UL
#define DAC_TRIM_REFBUF_OFFSET_TRIM_REFBUF_OFFSET_TRIM_Msk 0x3FUL
/* DAC_TRIM.REFBUF_SLOPE_OFFSET_TRIM */
#define DAC_TRIM_REFBUF_SLOPE_OFFSET_TRIM_REFBUF_SLOPE_OFFSET_TRIM_Pos 0UL
#define DAC_TRIM_REFBUF_SLOPE_OFFSET_TRIM_REFBUF_SLOPE_OFFSET_TRIM_Msk 0x3FUL
/* DAC_TRIM.REFBUF_COMP_TRIM */
#define DAC_TRIM_REFBUF_COMP_TRIM_REFBUF_COMP_TRIM_Pos 0UL
#define DAC_TRIM_REFBUF_COMP_TRIM_REFBUF_COMP_TRIM_Msk 0xFUL
/* DAC_TRIM.OUTBUF_OFFSET_TRIM */
#define DAC_TRIM_OUTBUF_OFFSET_TRIM_OUTBUF_OFFSET_TRIM_Pos 0UL
#define DAC_TRIM_OUTBUF_OFFSET_TRIM_OUTBUF_OFFSET_TRIM_Msk 0x3FUL
/* DAC_TRIM.OUTBUF_SLOPE_OFFSET_TRIM */
#define DAC_TRIM_OUTBUF_SLOPE_OFFSET_TRIM_OUTBUF_SLOPE_OFFSET_TRIM_Pos 0UL
#define DAC_TRIM_OUTBUF_SLOPE_OFFSET_TRIM_OUTBUF_SLOPE_OFFSET_TRIM_Msk 0x3FUL
/* DAC_TRIM.OUTBUF_COMP_TRIM */
#define DAC_TRIM_OUTBUF_COMP_TRIM_OUTBUF_COMP_TRIM_Pos 0UL
#define DAC_TRIM_OUTBUF_COMP_TRIM_OUTBUF_COMP_TRIM_Msk 0xFUL
/* DAC_TRIM.RMP_TRIM */
#define DAC_TRIM_RMP_TRIM_RMP_TRIM_Pos          0UL
#define DAC_TRIM_RMP_TRIM_RMP_TRIM_Msk          0xFUL


/* DAC.SRAM */
#define DAC_SRAM_WAVEFORM_Pos                   0UL
#define DAC_SRAM_WAVEFORM_Msk                   0xFFFUL
#define DAC_SRAM_RESERVED_Pos                   12UL
#define DAC_SRAM_RESERVED_Msk                   0x3000UL
#define DAC_SRAM_OUT_DM_Pos                     14UL
#define DAC_SRAM_OUT_DM_Msk                     0xC000UL


#endif /* _CYIP_DAC_V1_1_H_ */


/* [] END OF FILE */

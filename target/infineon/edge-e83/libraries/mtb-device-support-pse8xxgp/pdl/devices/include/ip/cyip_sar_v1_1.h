/***************************************************************************//**
* SAR IP definitions
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

#ifndef _CYIP_SAR_V1_1_H_
#define _CYIP_SAR_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     SAR
*******************************************************************************/

#define SAR_STA_SECTION_SIZE                    0x00000200UL
#define SAR_FIR0_SECTION_SIZE                   0x00000008UL
#define SAR_FIR1_SECTION_SIZE                   0x00000008UL
#define SAR_HS_CAL_MEM_SECTION_SIZE             0x00000080UL
#define SAR_LP_CAL_MEM_SECTION_SIZE             0x00000080UL
#define SAR_TRIM_SECTION_SIZE                   0x00000020UL
#define SAR_SECTION_SIZE                        0x00010000UL

/**
  * \brief SAR static configuration registers (SAR_STA)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 SAR Control register (only accessible if ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED;
  __IOM uint32_t FIR_CFG[2];                    /*!< 0x00000008 FIR Configuration register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED1[2];
  __IOM uint32_t TR_SAMPLE_TIME;                /*!< 0x00000018 SAR Trigger Sample Time (Risk Mitigation Only) */
   __IM uint32_t RESERVED2;
  __IOM uint32_t SAMPLE_TIME[4];                /*!< 0x00000020 Sample control register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t GPIO_CHAN_CFG[8];              /*!< 0x00000030 High Speed GPIO Channel configuration register (only accessible
                                                                if ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t MUX_CHAN_CFG[16];              /*!< 0x00000050 High Speed / Low Power Muxed Channel configuration register
                                                                (Channel 0 routing is used for default routing (i.e. when the
                                                                SAR gets enabled) (only accessible if ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t STATUS_CFG[4];                 /*!< 0x00000090 Global range detect mode register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t STATUS_RANGE_LOW[4];           /*!< 0x000000A0 Global range detect low value register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t STATUS_RANGE_HIGH[4];          /*!< 0x000000B0 Global range detect high value register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t GPIO_CHAN_RESULT[8];           /*!< 0x000000C0 High Speed GPIO Channel result register */
   __IM uint32_t MUX_CHAN_RESULT[16];           /*!< 0x000000E0 High Speed / Low Power Muxed Channel result register */
   __IM uint32_t FIR_RESULT[2];                 /*!< 0x00000120 FIR result register */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t CHAN_RESULT_MASK;              /*!< 0x00000130 Channel result mask (only accessible if ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t FIR_RESULT_MASK;               /*!< 0x00000134 FIR result mask (only accessible if ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t CHAN_RESULT_UPDATED;           /*!< 0x00000138 Channel result register status */
  __IOM uint32_t FIR_RESULT_UPDATED;            /*!< 0x0000013C FIR result register status */
   __IM uint32_t STATUS;                        /*!< 0x00000140 SAR status register */
  __IOM uint32_t RANGE_STATUS;                  /*!< 0x00000144 Range status register */
   __IM uint32_t RESERVED4[2];
  __IOM uint32_t CHAN_COEFF[8];                 /*!< 0x00000150 Channel correction coefficients (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED5[36];
} SAR_STA_Type;                                 /*!< Size = 512 (0x200) */

/**
  * \brief SAR FIR0 registers (only accessible if ACTRLR.STATUS.MODE=0) (SAR_FIR0)
  */
typedef struct {
  __IOM uint32_t COEF;                          /*!< 0x00000000 Coefficient Value */
  __IOM uint32_t TAP;                           /*!< 0x00000004 Tap Value */
} SAR_FIR0_Type;                                /*!< Size = 8 (0x8) */

/**
  * \brief SAR FIR1 registers (only accessible if ACTRLR.STATUS.MODE=0) (SAR_FIR1)
  */
typedef struct {
  __IOM uint32_t COEF;                          /*!< 0x00000000 Coefficient Value */
  __IOM uint32_t TAP;                           /*!< 0x00000004 Tap Value */
} SAR_FIR1_Type;                                /*!< Size = 8 (0x8) */

/**
  * \brief SAR HS Core Calibration Memory (only accessible when the SAR is disabled (AC.SAR_EN=0) and ACTRLR.STATUS.MODE=0) (SAR_HS_CAL_MEM)
  */
typedef struct {
   __IM uint32_t RESERVED[5];
  __IOM uint32_t CALCTRL;                       /*!< 0x00000014 SAR HS Core Calibration Control Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CONVCTRL;                      /*!< 0x0000001C SAR HS Core Conversion Control Register */
  __IOM uint32_t ADFTMUX;                       /*!< 0x00000020 SAR HS Core Analog DFT Multiplexer Control Register */
   __IM uint32_t RESERVED2[7];
  __IOM uint32_t CALMEM0[10];                   /*!< 0x00000040 SAR HS Core Channel Calibration Values */
   __IM uint32_t RESERVED3[6];
} SAR_HS_CAL_MEM_Type;                          /*!< Size = 128 (0x80) */

/**
  * \brief SAR LP Core Calibration Memory (only accessible when the SAR is disabled (AC.SAR_EN=0) and ACTRLR.STATUS.MODE=0) (SAR_LP_CAL_MEM)
  */
typedef struct {
   __IM uint32_t RESERVED[5];
  __IOM uint32_t CALCTRL;                       /*!< 0x00000014 SAR LP Core Calibration Control Register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CONVCTRL;                      /*!< 0x0000001C SAR LP Core Conversion Control Register */
  __IOM uint32_t ADFTMUX;                       /*!< 0x00000020 SAR LP Core Analog DFT Multiplexer Control Register */
   __IM uint32_t RESERVED2[7];
  __IOM uint32_t CALMEM0;                       /*!< 0x00000040 SAR LP Core Channel Calibration Values */
   __IM uint32_t RESERVED3[15];
} SAR_LP_CAL_MEM_Type;                          /*!< Size = 128 (0x80) */

/**
  * \brief SAR Trim registers (only accessible if ACTRLR.STATUS.MODE=0) (SAR_TRIM)
  */
typedef struct {
  __IOM uint32_t BUF0_OFFSET_TRIM;              /*!< 0x00000000 Buffer zero trim control */
  __IOM uint32_t BUF0_SLOPE_OFFSET_TRIM;        /*!< 0x00000004 Buffer zero trim control */
  __IOM uint32_t BUF0_COMP_TRIM;                /*!< 0x00000008 Buffer zero trim control */
  __IOM uint32_t BUF1_OFFSET_TRIM;              /*!< 0x0000000C Buffer one trim control */
  __IOM uint32_t BUF1_SLOPE_OFFSET_TRIM;        /*!< 0x00000010 Buffer one trim control */
  __IOM uint32_t BUF1_COMP_TRIM;                /*!< 0x00000014 Buffer one trim control */
  __IOM uint32_t RMP_TRIM;                      /*!< 0x00000018 Risk Mitigation bits */
   __IM uint32_t RESERVED;
} SAR_TRIM_Type;                                /*!< Size = 32 (0x20) */

/**
  * \brief SAR (SAR)
  */
typedef struct {
   __IM uint32_t RESERVED[64];
  __IOM uint32_t SEQ_HS_DATA[32];               /*!< 0x00000100 SAR Sequencer High Speed Data (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t SEQ_LP_DATA[32];               /*!< 0x00000180 SAR Sequencer Low Power Data (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED1[128];
        SAR_STA_Type STA;                       /*!< 0x00000400 SAR static configuration registers */
        SAR_FIR0_Type FIR0[64];                 /*!< 0x00000600 SAR FIR0 registers (only accessible if ACTRLR.STATUS.MODE=0) */
        SAR_FIR1_Type FIR1[64];                 /*!< 0x00000800 SAR FIR1 registers (only accessible if ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED2[128];
        SAR_HS_CAL_MEM_Type HS_CAL_MEM;         /*!< 0x00000C00 SAR HS Core Calibration Memory (only accessible when the SAR is
                                                                disabled (AC.SAR_EN=0) and ACTRLR.STATUS.MODE=0) */
        SAR_LP_CAL_MEM_Type LP_CAL_MEM;         /*!< 0x00000C80 SAR LP Core Calibration Memory (only accessible when the SAR is
                                                                disabled (AC.SAR_EN=0) and ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED3[128];
        SAR_TRIM_Type TRIM;                     /*!< 0x00000F00 SAR Trim registers (only accessible if ACTRLR.STATUS.MODE=0) */
} SAR_Type;                                     /*!< Size = 3872 (0xF20) */


/* SAR_STA.CTRL */
#define SAR_STA_CTRL_HS_VREF_SEL_Pos            0UL
#define SAR_STA_CTRL_HS_VREF_SEL_Msk            0x7UL
#define SAR_STA_CTRL_LP_VREF_SEL_Pos            4UL
#define SAR_STA_CTRL_LP_VREF_SEL_Msk            0x70UL
#define SAR_STA_CTRL_LP_DIFFERENTIAL_EN_Pos     7UL
#define SAR_STA_CTRL_LP_DIFFERENTIAL_EN_Msk     0x80UL
#define SAR_STA_CTRL_BUF0_PWR_MODE_Pos          8UL
#define SAR_STA_CTRL_BUF0_PWR_MODE_Msk          0xF00UL
#define SAR_STA_CTRL_BUF1_PWR_MODE_Pos          12UL
#define SAR_STA_CTRL_BUF1_PWR_MODE_Msk          0xF000UL
#define SAR_STA_CTRL_AVG_MODE_Pos               16UL
#define SAR_STA_CTRL_AVG_MODE_Msk               0x30000UL
#define SAR_STA_CTRL_STARTUP_CAL_EN_Pos         18UL
#define SAR_STA_CTRL_STARTUP_CAL_EN_Msk         0xC0000UL
#define SAR_STA_CTRL_CHAN_ID_EN_Pos             20UL
#define SAR_STA_CTRL_CHAN_ID_EN_Msk             0x100000UL
#define SAR_STA_CTRL_SHIFT_MODE_Pos             21UL
#define SAR_STA_CTRL_SHIFT_MODE_Msk             0x200000UL
#define SAR_STA_CTRL_LP_SAR_PWR_MODE_Pos        22UL
#define SAR_STA_CTRL_LP_SAR_PWR_MODE_Msk        0xC00000UL
/* SAR_STA.FIR_CFG */
#define SAR_STA_FIR_CFG_CHANNEL_SEL_Pos         0UL
#define SAR_STA_FIR_CFG_CHANNEL_SEL_Msk         0x1FUL
#define SAR_STA_FIR_CFG_TAP_SEL_Pos             8UL
#define SAR_STA_FIR_CFG_TAP_SEL_Msk             0x3F00UL
#define SAR_STA_FIR_CFG_SHIFT_SEL_Pos           16UL
#define SAR_STA_FIR_CFG_SHIFT_SEL_Msk           0xF0000UL
#define SAR_STA_FIR_CFG_WAIT_TAP_INIT_Pos       20UL
#define SAR_STA_FIR_CFG_WAIT_TAP_INIT_Msk       0x100000UL
#define SAR_STA_FIR_CFG_STATUS_SEL_Pos          24UL
#define SAR_STA_FIR_CFG_STATUS_SEL_Msk          0x7000000UL
#define SAR_STA_FIR_CFG_FIFO_SEL_Pos            28UL
#define SAR_STA_FIR_CFG_FIFO_SEL_Msk            0xF0000000UL
/* SAR_STA.TR_SAMPLE_TIME */
#define SAR_STA_TR_SAMPLE_TIME_HS_TR_SAMPLE_TIME_Pos 0UL
#define SAR_STA_TR_SAMPLE_TIME_HS_TR_SAMPLE_TIME_Msk 0x3FFUL
#define SAR_STA_TR_SAMPLE_TIME_LP_TR_SAMPLE_TIME_Pos 16UL
#define SAR_STA_TR_SAMPLE_TIME_LP_TR_SAMPLE_TIME_Msk 0x3FF0000UL
/* SAR_STA.SAMPLE_TIME */
#define SAR_STA_SAMPLE_TIME_HS_SAMPLE_TIME_Pos  0UL
#define SAR_STA_SAMPLE_TIME_HS_SAMPLE_TIME_Msk  0x3FFUL
#define SAR_STA_SAMPLE_TIME_LP_SAMPLE_TIME_Pos  16UL
#define SAR_STA_SAMPLE_TIME_LP_SAMPLE_TIME_Msk  0x3FF0000UL
/* SAR_STA.GPIO_CHAN_CFG */
#define SAR_STA_GPIO_CHAN_CFG_POS_PIN_Pos       0UL
#define SAR_STA_GPIO_CHAN_CFG_POS_PIN_Msk       0x7UL
#define SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN_Pos 5UL
#define SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN_Msk 0x20UL
#define SAR_STA_GPIO_CHAN_CFG_SIGNED_Pos        6UL
#define SAR_STA_GPIO_CHAN_CFG_SIGNED_Msk        0x40UL
#define SAR_STA_GPIO_CHAN_CFG_POS_COEFF_SEL_Pos 8UL
#define SAR_STA_GPIO_CHAN_CFG_POS_COEFF_SEL_Msk 0xF00UL
#define SAR_STA_GPIO_CHAN_CFG_NEG_PIN_Pos       12UL
#define SAR_STA_GPIO_CHAN_CFG_NEG_PIN_Msk       0x7000UL
#define SAR_STA_GPIO_CHAN_CFG_AVG_SHIFT_Pos     19UL
#define SAR_STA_GPIO_CHAN_CFG_AVG_SHIFT_Msk     0x80000UL
#define SAR_STA_GPIO_CHAN_CFG_NEG_COEFF_SEL_Pos 20UL
#define SAR_STA_GPIO_CHAN_CFG_NEG_COEFF_SEL_Msk 0xF00000UL
#define SAR_STA_GPIO_CHAN_CFG_STATUS_SEL_Pos    24UL
#define SAR_STA_GPIO_CHAN_CFG_STATUS_SEL_Msk    0x7000000UL
#define SAR_STA_GPIO_CHAN_CFG_FIFO_SEL_Pos      28UL
#define SAR_STA_GPIO_CHAN_CFG_FIFO_SEL_Msk      0xF0000000UL
/* SAR_STA.MUX_CHAN_CFG */
#define SAR_STA_MUX_CHAN_CFG_POS_MUX_SEL_Pos    0UL
#define SAR_STA_MUX_CHAN_CFG_POS_MUX_SEL_Msk    0x1FUL
#define SAR_STA_MUX_CHAN_CFG_SIGNED_Pos         6UL
#define SAR_STA_MUX_CHAN_CFG_SIGNED_Msk         0x40UL
#define SAR_STA_MUX_CHAN_CFG_POS_COEFF_SEL_Pos  8UL
#define SAR_STA_MUX_CHAN_CFG_POS_COEFF_SEL_Msk  0xF00UL
#define SAR_STA_MUX_CHAN_CFG_NEG_MUX_SEL_Pos    12UL
#define SAR_STA_MUX_CHAN_CFG_NEG_MUX_SEL_Msk    0x1F000UL
#define SAR_STA_MUX_CHAN_CFG_BUF_BYPASS_Pos     18UL
#define SAR_STA_MUX_CHAN_CFG_BUF_BYPASS_Msk     0x40000UL
#define SAR_STA_MUX_CHAN_CFG_AVG_SHIFT_Pos      19UL
#define SAR_STA_MUX_CHAN_CFG_AVG_SHIFT_Msk      0x80000UL
#define SAR_STA_MUX_CHAN_CFG_NEG_COEFF_SEL_Pos  20UL
#define SAR_STA_MUX_CHAN_CFG_NEG_COEFF_SEL_Msk  0xF00000UL
#define SAR_STA_MUX_CHAN_CFG_STATUS_SEL_Pos     24UL
#define SAR_STA_MUX_CHAN_CFG_STATUS_SEL_Msk     0x7000000UL
#define SAR_STA_MUX_CHAN_CFG_FIFO_SEL_Pos       28UL
#define SAR_STA_MUX_CHAN_CFG_FIFO_SEL_Msk       0xF0000000UL
/* SAR_STA.STATUS_CFG */
#define SAR_STA_STATUS_CFG_RANGE_COND_Pos       0UL
#define SAR_STA_STATUS_CFG_RANGE_COND_Msk       0x3UL
/* SAR_STA.STATUS_RANGE_LOW */
#define SAR_STA_STATUS_RANGE_LOW_RANGE_LOW_Pos  0UL
#define SAR_STA_STATUS_RANGE_LOW_RANGE_LOW_Msk  0xFFFFFFFFUL
/* SAR_STA.STATUS_RANGE_HIGH */
#define SAR_STA_STATUS_RANGE_HIGH_RANGE_HIGH_Pos 0UL
#define SAR_STA_STATUS_RANGE_HIGH_RANGE_HIGH_Msk 0xFFFFFFFFUL
/* SAR_STA.GPIO_CHAN_RESULT */
#define SAR_STA_GPIO_CHAN_RESULT_RESULT_Pos     0UL
#define SAR_STA_GPIO_CHAN_RESULT_RESULT_Msk     0xFFFFFFFFUL
/* SAR_STA.MUX_CHAN_RESULT */
#define SAR_STA_MUX_CHAN_RESULT_RESULT_Pos      0UL
#define SAR_STA_MUX_CHAN_RESULT_RESULT_Msk      0xFFFFFFFFUL
/* SAR_STA.FIR_RESULT */
#define SAR_STA_FIR_RESULT_RESULT_Pos           0UL
#define SAR_STA_FIR_RESULT_RESULT_Msk           0xFFFFFFFFUL
/* SAR_STA.CHAN_RESULT_MASK */
#define SAR_STA_CHAN_RESULT_MASK_GPIO_CHAN_RESULT_MASK_Pos 0UL
#define SAR_STA_CHAN_RESULT_MASK_GPIO_CHAN_RESULT_MASK_Msk 0xFFUL
#define SAR_STA_CHAN_RESULT_MASK_MUX_CHAN_RESULT_MASK_Pos 16UL
#define SAR_STA_CHAN_RESULT_MASK_MUX_CHAN_RESULT_MASK_Msk 0xFFFF0000UL
/* SAR_STA.FIR_RESULT_MASK */
#define SAR_STA_FIR_RESULT_MASK_FIR_RESULT_MASK_Pos 0UL
#define SAR_STA_FIR_RESULT_MASK_FIR_RESULT_MASK_Msk 0x3UL
/* SAR_STA.CHAN_RESULT_UPDATED */
#define SAR_STA_CHAN_RESULT_UPDATED_GPIO_CHAN_RESULT_UPDATED_Pos 0UL
#define SAR_STA_CHAN_RESULT_UPDATED_GPIO_CHAN_RESULT_UPDATED_Msk 0xFFUL
#define SAR_STA_CHAN_RESULT_UPDATED_MUX_CHAN_RESULT_UPDATED_Pos 16UL
#define SAR_STA_CHAN_RESULT_UPDATED_MUX_CHAN_RESULT_UPDATED_Msk 0xFFFF0000UL
/* SAR_STA.FIR_RESULT_UPDATED */
#define SAR_STA_FIR_RESULT_UPDATED_FIR_RESULT_UPDATED_Pos 0UL
#define SAR_STA_FIR_RESULT_UPDATED_FIR_RESULT_UPDATED_Msk 0x3UL
/* SAR_STA.STATUS */
#define SAR_STA_STATUS_BUSY_Pos                 31UL
#define SAR_STA_STATUS_BUSY_Msk                 0x80000000UL
/* SAR_STA.RANGE_STATUS */
#define SAR_STA_RANGE_STATUS_GPIO_CHAN_RANGE_STATUS_Pos 0UL
#define SAR_STA_RANGE_STATUS_GPIO_CHAN_RANGE_STATUS_Msk 0xFFUL
#define SAR_STA_RANGE_STATUS_FIR_RANGE_STATUS_Pos 8UL
#define SAR_STA_RANGE_STATUS_FIR_RANGE_STATUS_Msk 0x300UL
#define SAR_STA_RANGE_STATUS_MUX_CHAN_RANGE_STATUS_Pos 16UL
#define SAR_STA_RANGE_STATUS_MUX_CHAN_RANGE_STATUS_Msk 0xFFFF0000UL
/* SAR_STA.CHAN_COEFF */
#define SAR_STA_CHAN_COEFF_OFFSET_Pos           0UL
#define SAR_STA_CHAN_COEFF_OFFSET_Msk           0xFFFUL
#define SAR_STA_CHAN_COEFF_GAIN_Pos             16UL
#define SAR_STA_CHAN_COEFF_GAIN_Msk             0xFFFF0000UL


/* SAR_FIR0.COEF */
#define SAR_FIR0_COEF_COEF_Pos                  0UL
#define SAR_FIR0_COEF_COEF_Msk                  0xFFFFUL
/* SAR_FIR0.TAP */
#define SAR_FIR0_TAP_TAP_Pos                    0UL
#define SAR_FIR0_TAP_TAP_Msk                    0xFFFFFFFFUL


/* SAR_FIR1.COEF */
#define SAR_FIR1_COEF_COEF_Pos                  0UL
#define SAR_FIR1_COEF_COEF_Msk                  0xFFFFUL
/* SAR_FIR1.TAP */
#define SAR_FIR1_TAP_TAP_Pos                    0UL
#define SAR_FIR1_TAP_TAP_Msk                    0xFFFFFFFFUL


/* SAR_HS_CAL_MEM.CALCTRL */
#define SAR_HS_CAL_MEM_CALCTRL_OFFDEP_Pos       0UL
#define SAR_HS_CAL_MEM_CALCTRL_OFFDEP_Msk       0x1UL
#define SAR_HS_CAL_MEM_CALCTRL_R1_Pos           1UL
#define SAR_HS_CAL_MEM_CALCTRL_R1_Msk           0xFEUL
#define SAR_HS_CAL_MEM_CALCTRL_AVG_Pos          8UL
#define SAR_HS_CAL_MEM_CALCTRL_AVG_Msk          0x300UL
#define SAR_HS_CAL_MEM_CALCTRL_STC_Pos          10UL
#define SAR_HS_CAL_MEM_CALCTRL_STC_Msk          0xC00UL
#define SAR_HS_CAL_MEM_CALCTRL_R12_Pos          12UL
#define SAR_HS_CAL_MEM_CALCTRL_R12_Msk          0xFFFFF000UL
/* SAR_HS_CAL_MEM.CONVCTRL */
#define SAR_HS_CAL_MEM_CONVCTRL_INIT_TC_Pos     0UL
#define SAR_HS_CAL_MEM_CONVCTRL_INIT_TC_Msk     0x3UL
#define SAR_HS_CAL_MEM_CONVCTRL_R2_Pos          2UL
#define SAR_HS_CAL_MEM_CONVCTRL_R2_Msk          0xCUL
#define SAR_HS_CAL_MEM_CONVCTRL_MSB_CTRL_Pos    4UL
#define SAR_HS_CAL_MEM_CONVCTRL_MSB_CTRL_Msk    0x10UL
#define SAR_HS_CAL_MEM_CONVCTRL_RES_RAW_Pos     5UL
#define SAR_HS_CAL_MEM_CONVCTRL_RES_RAW_Msk     0x20UL
#define SAR_HS_CAL_MEM_CONVCTRL_R6_Pos          6UL
#define SAR_HS_CAL_MEM_CONVCTRL_R6_Msk          0xFFFFFFC0UL
/* SAR_HS_CAL_MEM.ADFTMUX */
#define SAR_HS_CAL_MEM_ADFTMUX_EN_Pos           0UL
#define SAR_HS_CAL_MEM_ADFTMUX_EN_Msk           0x1UL
#define SAR_HS_CAL_MEM_ADFTMUX_SEL_Pos          1UL
#define SAR_HS_CAL_MEM_ADFTMUX_SEL_Msk          0x1EUL
#define SAR_HS_CAL_MEM_ADFTMUX_R5_Pos           5UL
#define SAR_HS_CAL_MEM_ADFTMUX_R5_Msk           0xFFFFFFE0UL
/* SAR_HS_CAL_MEM.CALMEM0 */
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT9_Pos      0UL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT9_Msk      0x3FUL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT10_Pos     6UL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT10_Msk     0xFC0UL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT11_Pos     12UL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT11_Msk     0x3F000UL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT12_Pos     18UL
#define SAR_HS_CAL_MEM_CALMEM0_LINBIT12_Msk     0x1FC0000UL
#define SAR_HS_CAL_MEM_CALMEM0_OFFSET_Pos       25UL
#define SAR_HS_CAL_MEM_CALMEM0_OFFSET_Msk       0xFE000000UL


/* SAR_LP_CAL_MEM.CALCTRL */
#define SAR_LP_CAL_MEM_CALCTRL_OFFDEP_Pos       0UL
#define SAR_LP_CAL_MEM_CALCTRL_OFFDEP_Msk       0x1UL
#define SAR_LP_CAL_MEM_CALCTRL_R1_Pos           1UL
#define SAR_LP_CAL_MEM_CALCTRL_R1_Msk           0xFEUL
#define SAR_LP_CAL_MEM_CALCTRL_AVG_Pos          8UL
#define SAR_LP_CAL_MEM_CALCTRL_AVG_Msk          0x300UL
#define SAR_LP_CAL_MEM_CALCTRL_STC_Pos          10UL
#define SAR_LP_CAL_MEM_CALCTRL_STC_Msk          0xC00UL
#define SAR_LP_CAL_MEM_CALCTRL_R12_Pos          12UL
#define SAR_LP_CAL_MEM_CALCTRL_R12_Msk          0xFFFFF000UL
/* SAR_LP_CAL_MEM.CONVCTRL */
#define SAR_LP_CAL_MEM_CONVCTRL_R0_Pos          0UL
#define SAR_LP_CAL_MEM_CONVCTRL_R0_Msk          0x1FUL
#define SAR_LP_CAL_MEM_CONVCTRL_RES_RAW_Pos     5UL
#define SAR_LP_CAL_MEM_CONVCTRL_RES_RAW_Msk     0x20UL
#define SAR_LP_CAL_MEM_CONVCTRL_R6_Pos          6UL
#define SAR_LP_CAL_MEM_CONVCTRL_R6_Msk          0xFFFFFFC0UL
/* SAR_LP_CAL_MEM.ADFTMUX */
#define SAR_LP_CAL_MEM_ADFTMUX_EN_Pos           0UL
#define SAR_LP_CAL_MEM_ADFTMUX_EN_Msk           0x1UL
#define SAR_LP_CAL_MEM_ADFTMUX_SEL_Pos          1UL
#define SAR_LP_CAL_MEM_ADFTMUX_SEL_Msk          0x6UL
#define SAR_LP_CAL_MEM_ADFTMUX_R5_Pos           3UL
#define SAR_LP_CAL_MEM_ADFTMUX_R5_Msk           0xFFFFFFF8UL
/* SAR_LP_CAL_MEM.CALMEM0 */
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT9_Pos      0UL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT9_Msk      0x3FUL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT10_Pos     6UL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT10_Msk     0xFC0UL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT11_Pos     12UL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT11_Msk     0x3F000UL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT12_Pos     18UL
#define SAR_LP_CAL_MEM_CALMEM0_LINBIT12_Msk     0x1FC0000UL
#define SAR_LP_CAL_MEM_CALMEM0_OFFSET_Pos       25UL
#define SAR_LP_CAL_MEM_CALMEM0_OFFSET_Msk       0xFE000000UL


/* SAR_TRIM.BUF0_OFFSET_TRIM */
#define SAR_TRIM_BUF0_OFFSET_TRIM_BUF0_OFFSET_TRIM_Pos 0UL
#define SAR_TRIM_BUF0_OFFSET_TRIM_BUF0_OFFSET_TRIM_Msk 0x3FUL
/* SAR_TRIM.BUF0_SLOPE_OFFSET_TRIM */
#define SAR_TRIM_BUF0_SLOPE_OFFSET_TRIM_BUF0_SLOPE_OFFSET_TRIM_Pos 0UL
#define SAR_TRIM_BUF0_SLOPE_OFFSET_TRIM_BUF0_SLOPE_OFFSET_TRIM_Msk 0x3FUL
/* SAR_TRIM.BUF0_COMP_TRIM */
#define SAR_TRIM_BUF0_COMP_TRIM_BUF0_COMP_TRIM_Pos 0UL
#define SAR_TRIM_BUF0_COMP_TRIM_BUF0_COMP_TRIM_Msk 0xFUL
/* SAR_TRIM.BUF1_OFFSET_TRIM */
#define SAR_TRIM_BUF1_OFFSET_TRIM_BUF1_OFFSET_TRIM_Pos 0UL
#define SAR_TRIM_BUF1_OFFSET_TRIM_BUF1_OFFSET_TRIM_Msk 0x3FUL
/* SAR_TRIM.BUF1_SLOPE_OFFSET_TRIM */
#define SAR_TRIM_BUF1_SLOPE_OFFSET_TRIM_BUF1_SLOPE_OFFSET_TRIM_Pos 0UL
#define SAR_TRIM_BUF1_SLOPE_OFFSET_TRIM_BUF1_SLOPE_OFFSET_TRIM_Msk 0x3FUL
/* SAR_TRIM.BUF1_COMP_TRIM */
#define SAR_TRIM_BUF1_COMP_TRIM_BUF1_COMP_TRIM_Pos 0UL
#define SAR_TRIM_BUF1_COMP_TRIM_BUF1_COMP_TRIM_Msk 0xFUL
/* SAR_TRIM.RMP_TRIM */
#define SAR_TRIM_RMP_TRIM_RMP_TRIM_Pos          0UL
#define SAR_TRIM_RMP_TRIM_RMP_TRIM_Msk          0xFUL
#define SAR_TRIM_RMP_TRIM_TEMP_SENSOR_TRIM_Pos  4UL
#define SAR_TRIM_RMP_TRIM_TEMP_SENSOR_TRIM_Msk  0x10UL


/* SAR.SEQ_HS_DATA */
#define SAR_SEQ_HS_DATA_HS_GPIO_CHAN_EN_Pos     0UL
#define SAR_SEQ_HS_DATA_HS_GPIO_CHAN_EN_Msk     0xFFUL
#define SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL_Pos  8UL
#define SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL_Msk  0x700UL
#define SAR_SEQ_HS_DATA_RESERVED_0_Pos          11UL
#define SAR_SEQ_HS_DATA_RESERVED_0_Msk          0x800UL
#define SAR_SEQ_HS_DATA_MUX0_CHAN_SEL_Pos       12UL
#define SAR_SEQ_HS_DATA_MUX0_CHAN_SEL_Msk       0xF000UL
#define SAR_SEQ_HS_DATA_MUX1_CHAN_SEL_Pos       16UL
#define SAR_SEQ_HS_DATA_MUX1_CHAN_SEL_Msk       0xF0000UL
#define SAR_SEQ_HS_DATA_SAMPLE_TIME_SEL_Pos     20UL
#define SAR_SEQ_HS_DATA_SAMPLE_TIME_SEL_Msk     0x300000UL
#define SAR_SEQ_HS_DATA_SAMPLE_TIME_EN_Pos      22UL
#define SAR_SEQ_HS_DATA_SAMPLE_TIME_EN_Msk      0x400000UL
#define SAR_SEQ_HS_DATA_TR_SAMPLE_TIME_EN_Pos   23UL
#define SAR_SEQ_HS_DATA_TR_SAMPLE_TIME_EN_Msk   0x800000UL
#define SAR_SEQ_HS_DATA_AVG_CNT_Pos             24UL
#define SAR_SEQ_HS_DATA_AVG_CNT_Msk             0x7000000UL
#define SAR_SEQ_HS_DATA_AVG_EN_Pos              27UL
#define SAR_SEQ_HS_DATA_AVG_EN_Msk              0x8000000UL
#define SAR_SEQ_HS_DATA_CALIBRATE_Pos           28UL
#define SAR_SEQ_HS_DATA_CALIBRATE_Msk           0x30000000UL
#define SAR_SEQ_HS_DATA_NEXT_ACTION_Pos         30UL
#define SAR_SEQ_HS_DATA_NEXT_ACTION_Msk         0xC0000000UL
/* SAR.SEQ_LP_DATA */
#define SAR_SEQ_LP_DATA_LP_CHAN_EN_Pos          0UL
#define SAR_SEQ_LP_DATA_LP_CHAN_EN_Msk          0x1UL
#define SAR_SEQ_LP_DATA_RESERVED_1_Pos          1UL
#define SAR_SEQ_LP_DATA_RESERVED_1_Msk          0xFFEUL
#define SAR_SEQ_LP_DATA_CHAN_SEL_Pos            12UL
#define SAR_SEQ_LP_DATA_CHAN_SEL_Msk            0xF000UL
#define SAR_SEQ_LP_DATA_RESERVED_2_Pos          16UL
#define SAR_SEQ_LP_DATA_RESERVED_2_Msk          0xF0000UL
#define SAR_SEQ_LP_DATA_SAMPLE_TIME_SEL_Pos     20UL
#define SAR_SEQ_LP_DATA_SAMPLE_TIME_SEL_Msk     0x300000UL
#define SAR_SEQ_LP_DATA_SAMPLE_TIME_EN_Pos      22UL
#define SAR_SEQ_LP_DATA_SAMPLE_TIME_EN_Msk      0x400000UL
#define SAR_SEQ_LP_DATA_TR_SAMPLE_TIME_EN_Pos   23UL
#define SAR_SEQ_LP_DATA_TR_SAMPLE_TIME_EN_Msk   0x800000UL
#define SAR_SEQ_LP_DATA_AVG_CNT_Pos             24UL
#define SAR_SEQ_LP_DATA_AVG_CNT_Msk             0x7000000UL
#define SAR_SEQ_LP_DATA_AVG_EN_Pos              27UL
#define SAR_SEQ_LP_DATA_AVG_EN_Msk              0x8000000UL
#define SAR_SEQ_LP_DATA_CALIBRATE_Pos           28UL
#define SAR_SEQ_LP_DATA_CALIBRATE_Msk           0x30000000UL
#define SAR_SEQ_LP_DATA_NEXT_ACTION_Pos         30UL
#define SAR_SEQ_LP_DATA_NEXT_ACTION_Msk         0xC0000000UL


#endif /* _CYIP_SAR_V1_1_H_ */


/* [] END OF FILE */

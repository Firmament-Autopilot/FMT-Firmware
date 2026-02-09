/***************************************************************************//**
* INFRA IP definitions
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

#ifndef _CYIP_INFRA_V1_1_H_
#define _CYIP_INFRA_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    INFRA
*******************************************************************************/

#define INFRA_LPOSC_SECTION_SIZE                0x00000100UL
#define INFRA_AREF_SECTION_SIZE                 0x00000100UL
#define INFRA_PRB_SECTION_SIZE                  0x00000100UL
#define INFRA_TIMER_SECTION_SIZE                0x00000100UL
#define INFRA_SECTION_SIZE                      0x00010000UL

/**
  * \brief LPOSC configuration (only accessible if ACTRLR.STATUS.MODE=0) (INFRA_LPOSC)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 Low Power Oscillator configuration register */
   __IM uint32_t RESERVED[59];
  __IOM uint32_t TRIM;                          /*!< 0x000000F0 LPOSC Trim Register */
   __IM uint32_t RESERVED1[3];
} INFRA_LPOSC_Type;                             /*!< Size = 256 (0x100) */

/**
  * \brief AREF configuration (only accessible if ACTRLR.STATUS.MODE=0) (INFRA_AREF)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 AREF control */
   __IM uint32_t RESERVED[51];
  __IOM uint32_t VREF_TRIM0;                    /*!< 0x000000D0 VREF Trim bits */
  __IOM uint32_t VREF_TRIM1;                    /*!< 0x000000D4 VREF Trim bits */
  __IOM uint32_t VREF_TRIM2;                    /*!< 0x000000D8 VREF Trim bits */
  __IOM uint32_t VREF_TRIM3;                    /*!< 0x000000DC VREF Trim bits */
  __IOM uint32_t IZTAT_TRIM0;                   /*!< 0x000000E0 IZTAT Trim bits */
  __IOM uint32_t IPTAT_TRIM0;                   /*!< 0x000000E4 IPTAT Trim bits */
  __IOM uint32_t IPTAT_TRIM1;                   /*!< 0x000000E8 IPTAT Trim bits */
  __IOM uint32_t ICTAT_TRIM0;                   /*!< 0x000000EC ICTAT Trim bits */
  __IOM uint32_t ICTAT_TRIM1;                   /*!< 0x000000F0 ICTAT Trim bits */
  __IOM uint32_t ICTAT_TRIM2;                   /*!< 0x000000F4 ICTAT Trim bits */
   __IM uint32_t RESERVED1[2];
} INFRA_AREF_Type;                              /*!< Size = 256 (0x100) */

/**
  * \brief PRB configuration (only accessible if ACTRLR.STATUS.MODE=0) (INFRA_PRB)
  */
typedef struct {
  __IOM uint32_t VREF_CTRL[2];                  /*!< 0x00000000 PRB VREF Control */
   __IM uint32_t RESERVED[62];
} INFRA_PRB_Type;                               /*!< Size = 256 (0x100) */

/**
  * \brief Wakeup Timer configuration (only accessible if ACTRLR.STATUS.MODE=0) (INFRA_TIMER)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Timer trigger control register */
  __IOM uint32_t CFG;                           /*!< 0x00000004 Timer trigger configuration register */
  __IOM uint32_t PERIOD;                        /*!< 0x00000008 Timer trigger period register */
   __IM uint32_t RESERVED[61];
} INFRA_TIMER_Type;                             /*!< Size = 256 (0x100) */

/**
  * \brief LPPASS infrastructure (INFRA)
  */
typedef struct {
   __IM uint32_t RESERVED;
  __IOM uint32_t CLOCK_PTC_LP_DIV;              /*!< 0x00000004 Low Power Clock divider for PTC (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
  __IOM uint32_t CLOCK_DAC_LP_DIV[2];           /*!< 0x00000008 Low Power Clock divider for DAC (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED1;
  __IOM uint32_t CLOCK_PRIO_HS_DIV;             /*!< 0x00000014 Clock enable for IP priority enabler (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t PRIO_CFG[4];                   /*!< 0x00000020 Sub IP Block IP priority enabler configuration (only accessible
                                                                if ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED3[52];
        INFRA_LPOSC_Type LPOSC;                 /*!< 0x00000100 LPOSC configuration (only accessible if ACTRLR.STATUS.MODE=0) */
        INFRA_AREF_Type AREF;                   /*!< 0x00000200 AREF configuration (only accessible if ACTRLR.STATUS.MODE=0) */
        INFRA_PRB_Type PRB;                     /*!< 0x00000300 PRB configuration (only accessible if ACTRLR.STATUS.MODE=0) */
        INFRA_TIMER_Type TIMER;                 /*!< 0x00000400 Wakeup Timer configuration (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
} INFRA_Type;                                   /*!< Size = 1280 (0x500) */


/* INFRA_LPOSC.CFG */
#define INFRA_LPOSC_CFG_MODE_Pos                30UL
#define INFRA_LPOSC_CFG_MODE_Msk                0x40000000UL
#define INFRA_LPOSC_CFG_ENABLE_Pos              31UL
#define INFRA_LPOSC_CFG_ENABLE_Msk              0x80000000UL
/* INFRA_LPOSC.TRIM */
#define INFRA_LPOSC_TRIM_LPOSC_CTRL_FTRIM_Pos   0UL
#define INFRA_LPOSC_TRIM_LPOSC_CTRL_FTRIM_Msk   0x1FFUL
#define INFRA_LPOSC_TRIM_LPOSC_CTRL_TCTRIM_Pos  16UL
#define INFRA_LPOSC_TRIM_LPOSC_CTRL_TCTRIM_Msk  0x1F0000UL
#define INFRA_LPOSC_TRIM_LPOSC_CTRL_REFTRIM_Pos 24UL
#define INFRA_LPOSC_TRIM_LPOSC_CTRL_REFTRIM_Msk 0xFF000000UL


/* INFRA_AREF.CTRL */
#define INFRA_AREF_CTRL_VREF_SEL_Pos            8UL
#define INFRA_AREF_CTRL_VREF_SEL_Msk            0x100UL
/* INFRA_AREF.VREF_TRIM0 */
#define INFRA_AREF_VREF_TRIM0_VREF_ABS_TRIM_Pos 0UL
#define INFRA_AREF_VREF_TRIM0_VREF_ABS_TRIM_Msk 0x1FUL
/* INFRA_AREF.VREF_TRIM1 */
#define INFRA_AREF_VREF_TRIM1_VREF_TEMPCO_TRIM_Pos 0UL
#define INFRA_AREF_VREF_TRIM1_VREF_TEMPCO_TRIM_Msk 0x3FUL
/* INFRA_AREF.VREF_TRIM2 */
#define INFRA_AREF_VREF_TRIM2_VREF_IPTAT2_ICTAT_TRIM_Pos 0UL
#define INFRA_AREF_VREF_TRIM2_VREF_IPTAT2_ICTAT_TRIM_Msk 0xFUL
/* INFRA_AREF.VREF_TRIM3 */
#define INFRA_AREF_VREF_TRIM3_VREF_IPTAT2_DAC_TRIM_Pos 0UL
#define INFRA_AREF_VREF_TRIM3_VREF_IPTAT2_DAC_TRIM_Msk 0x1FUL
/* INFRA_AREF.IZTAT_TRIM0 */
#define INFRA_AREF_IZTAT_TRIM0_IZTAT_COARSE_TRIM_Pos 0UL
#define INFRA_AREF_IZTAT_TRIM0_IZTAT_COARSE_TRIM_Msk 0xFUL
#define INFRA_AREF_IZTAT_TRIM0_IZTAT_FINE_TRIM_Pos 4UL
#define INFRA_AREF_IZTAT_TRIM0_IZTAT_FINE_TRIM_Msk 0xF0UL
/* INFRA_AREF.IPTAT_TRIM0 */
#define INFRA_AREF_IPTAT_TRIM0_IPTAT_COARSE_TRIM_Pos 0UL
#define INFRA_AREF_IPTAT_TRIM0_IPTAT_COARSE_TRIM_Msk 0xFUL
#define INFRA_AREF_IPTAT_TRIM0_IPTAT_FINE_TRIM_Pos 4UL
#define INFRA_AREF_IPTAT_TRIM0_IPTAT_FINE_TRIM_Msk 0xF0UL
/* INFRA_AREF.IPTAT_TRIM1 */
#define INFRA_AREF_IPTAT_TRIM1_IPTAT_DAC_TRIM_Pos 0UL
#define INFRA_AREF_IPTAT_TRIM1_IPTAT_DAC_TRIM_Msk 0x1FUL
/* INFRA_AREF.ICTAT_TRIM0 */
#define INFRA_AREF_ICTAT_TRIM0_RESERVED_Pos     0UL
#define INFRA_AREF_ICTAT_TRIM0_RESERVED_Msk     0xFUL
/* INFRA_AREF.ICTAT_TRIM1 */
#define INFRA_AREF_ICTAT_TRIM1_ICTAT_COARSE_TRIM_Pos 0UL
#define INFRA_AREF_ICTAT_TRIM1_ICTAT_COARSE_TRIM_Msk 0x1FUL
/* INFRA_AREF.ICTAT_TRIM2 */
#define INFRA_AREF_ICTAT_TRIM2_ICTAT_FINE_TRIM_Pos 0UL
#define INFRA_AREF_ICTAT_TRIM2_ICTAT_FINE_TRIM_Msk 0x7UL


/* INFRA_PRB.VREF_CTRL */
#define INFRA_PRB_VREF_CTRL_CFG_Pos             0UL
#define INFRA_PRB_VREF_CTRL_CFG_Msk             0x1UL
#define INFRA_PRB_VREF_CTRL_VAL_Pos             4UL
#define INFRA_PRB_VREF_CTRL_VAL_Msk             0xF0UL
#define INFRA_PRB_VREF_CTRL_EN_Pos              31UL
#define INFRA_PRB_VREF_CTRL_EN_Msk              0x80000000UL


/* INFRA_TIMER.CTRL */
#define INFRA_TIMER_CTRL_ENABLED_Pos            31UL
#define INFRA_TIMER_CTRL_ENABLED_Msk            0x80000000UL
/* INFRA_TIMER.CFG */
#define INFRA_TIMER_CFG_CLOCK_SEL_Pos           0UL
#define INFRA_TIMER_CFG_CLOCK_SEL_Msk           0x3UL
/* INFRA_TIMER.PERIOD */
#define INFRA_TIMER_PERIOD_PER_VAL_Pos          0UL
#define INFRA_TIMER_PERIOD_PER_VAL_Msk          0xFFFFUL


/* INFRA.CLOCK_PTC_LP_DIV */
#define INFRA_CLOCK_PTC_LP_DIV_DIV_VAL_Pos      0UL
#define INFRA_CLOCK_PTC_LP_DIV_DIV_VAL_Msk      0x3FFUL
/* INFRA.CLOCK_DAC_LP_DIV */
#define INFRA_CLOCK_DAC_LP_DIV_DIV_VAL_Pos      0UL
#define INFRA_CLOCK_DAC_LP_DIV_DIV_VAL_Msk      0x3FFUL
/* INFRA.CLOCK_PRIO_HS_DIV */
#define INFRA_CLOCK_PRIO_HS_DIV_DIV_VAL_Pos     0UL
#define INFRA_CLOCK_PRIO_HS_DIV_DIV_VAL_Msk     0x3FFUL
/* INFRA.PRIO_CFG */
#define INFRA_PRIO_CFG_COUNT_VAL_Pos            0UL
#define INFRA_PRIO_CFG_COUNT_VAL_Msk            0x3FUL
#define INFRA_PRIO_CFG_SAR_READY_Pos            8UL
#define INFRA_PRIO_CFG_SAR_READY_Msk            0x100UL
#define INFRA_PRIO_CFG_DAC0_READY_Pos           9UL
#define INFRA_PRIO_CFG_DAC0_READY_Msk           0x200UL
#define INFRA_PRIO_CFG_DAC1_READY_Pos           10UL
#define INFRA_PRIO_CFG_DAC1_READY_Msk           0x400UL
#define INFRA_PRIO_CFG_PTC_CMP0_READY_Pos       11UL
#define INFRA_PRIO_CFG_PTC_CMP0_READY_Msk       0x800UL
#define INFRA_PRIO_CFG_PTC_CMP1_READY_Pos       12UL
#define INFRA_PRIO_CFG_PTC_CMP1_READY_Msk       0x1000UL
#define INFRA_PRIO_CFG_CTBL0_OA0_READY_Pos      13UL
#define INFRA_PRIO_CFG_CTBL0_OA0_READY_Msk      0x2000UL
#define INFRA_PRIO_CFG_CTBL0_OA1_READY_Pos      14UL
#define INFRA_PRIO_CFG_CTBL0_OA1_READY_Msk      0x4000UL
#define INFRA_PRIO_CFG_CTBL1_OA0_READY_Pos      15UL
#define INFRA_PRIO_CFG_CTBL1_OA0_READY_Msk      0x8000UL
#define INFRA_PRIO_CFG_CTBL1_OA1_READY_Pos      16UL
#define INFRA_PRIO_CFG_CTBL1_OA1_READY_Msk      0x10000UL


#endif /* _CYIP_INFRA_V1_1_H_ */


/* [] END OF FILE */

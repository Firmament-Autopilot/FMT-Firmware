/***************************************************************************//**
* PTC IP definitions
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

#ifndef _CYIP_PTC_V1_1_H_
#define _CYIP_PTC_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     PTC
*******************************************************************************/

#define PTC_STA_SECTION_SIZE                    0x00000200UL
#define PTC_DYN_SECTION_SIZE                    0x00000010UL
#define PTC_PP_SECTION_SIZE                     0x00000010UL
#define PTC_TRIM_SECTION_SIZE                   0x00000010UL
#define PTC_SECTION_SIZE                        0x00010000UL

/**
  * \brief PTC Static Configuration (PTC_STA)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 PTC Configuration Register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t COMP_STAT;                     /*!< 0x00000004 PTC Status Register */
  __IOM uint32_t PP_CFG[2];                     /*!< 0x00000008 Post Process Configuration register (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED[124];
} PTC_STA_Type;                                 /*!< Size = 512 (0x200) */

/**
  * \brief PTC Dynamic Configuration (only accessible if ACTRLR.STATUS.MODE=0) (PTC_DYN)
  */
typedef struct {
  __IOM uint32_t MUX_CFG;                       /*!< 0x00000000 PTC Mux Configuration */
   __IM uint32_t RESERVED[3];
} PTC_DYN_Type;                                 /*!< Size = 16 (0x10) */

/**
  * \brief PTC Post Process (only accessible if ACTRLR.STATUS.MODE=0) (PTC_PP)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 Post Processing configuration */
  __IOM uint32_t FRAME;                         /*!< 0x00000004 Post Processing frame */
  __IOM uint32_t THRESHOLD;                     /*!< 0x00000008 Post Processing threshold */
  __IOM uint32_t WINDOW;                        /*!< 0x0000000C Post Processing window */
} PTC_PP_Type;                                  /*!< Size = 16 (0x10) */

/**
  * \brief PTC Trim registers (only accessible if ACTRLR.STATUS.MODE=0) (PTC_TRIM)
  */
typedef struct {
  __IOM uint32_t CMP0_OFFSET_TRIM;              /*!< 0x00000000 Comparator 0 offset trim register */
  __IOM uint32_t CMP1_OFFSET_TRIM;              /*!< 0x00000004 Comparator 1 offset trim register */
   __IM uint32_t RESERVED[2];
} PTC_TRIM_Type;                                /*!< Size = 16 (0x10) */

/**
  * \brief Programmable Threshold Comparator (PTC)
  */
typedef struct {
   __IM uint32_t RESERVED[256];
        PTC_STA_Type STA;                       /*!< 0x00000400 PTC Static Configuration */
        PTC_DYN_Type DYN[8];                    /*!< 0x00000600 PTC Dynamic Configuration (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED1[32];
        PTC_PP_Type PP[2];                      /*!< 0x00000700 PTC Post Process (only accessible if ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED2[504];
        PTC_TRIM_Type TRIM;                     /*!< 0x00000F00 PTC Trim registers (only accessible if ACTRLR.STATUS.MODE=0) */
} PTC_Type;                                     /*!< Size = 3856 (0xF10) */


/* PTC_STA.CFG */
#define PTC_STA_CFG_COMP0_MODE_Pos              0UL
#define PTC_STA_CFG_COMP0_MODE_Msk              0x3UL
#define PTC_STA_CFG_COMP0_HYST_Pos              2UL
#define PTC_STA_CFG_COMP0_HYST_Msk              0x4UL
#define PTC_STA_CFG_COMP0_OUT_Pos               4UL
#define PTC_STA_CFG_COMP0_OUT_Msk               0x30UL
#define PTC_STA_CFG_COMP1_MODE_Pos              8UL
#define PTC_STA_CFG_COMP1_MODE_Msk              0x300UL
#define PTC_STA_CFG_COMP1_HYST_Pos              10UL
#define PTC_STA_CFG_COMP1_HYST_Msk              0x400UL
#define PTC_STA_CFG_COMP1_OUT_Pos               12UL
#define PTC_STA_CFG_COMP1_OUT_Msk               0x3000UL
/* PTC_STA.COMP_STAT */
#define PTC_STA_COMP_STAT_OUT0_Pos              0UL
#define PTC_STA_COMP_STAT_OUT0_Msk              0x1UL
#define PTC_STA_COMP_STAT_OUT1_Pos              16UL
#define PTC_STA_COMP_STAT_OUT1_Msk              0x10000UL
/* PTC_STA.PP_CFG */
#define PTC_STA_PP_CFG_INPUT_SEL_Pos            0UL
#define PTC_STA_PP_CFG_INPUT_SEL_Msk            0x3UL


/* PTC_DYN.MUX_CFG */
#define PTC_DYN_MUX_CFG_INP_MUX_SEL_Pos         0UL
#define PTC_DYN_MUX_CFG_INP_MUX_SEL_Msk         0x1FUL
#define PTC_DYN_MUX_CFG_INN_MUX_SEL_Pos         8UL
#define PTC_DYN_MUX_CFG_INN_MUX_SEL_Msk         0x1F00UL


/* PTC_PP.CFG */
#define PTC_PP_CFG_INPUT_TYPE_Pos               0UL
#define PTC_PP_CFG_INPUT_TYPE_Msk               0x3UL
#define PTC_PP_CFG_MODE_Pos                     2UL
#define PTC_PP_CFG_MODE_Msk                     0xCUL
#define PTC_PP_CFG_LUT_Pos                      8UL
#define PTC_PP_CFG_LUT_Msk                      0xF00UL
/* PTC_PP.FRAME */
#define PTC_PP_FRAME_PERIOD_Pos                 0UL
#define PTC_PP_FRAME_PERIOD_Msk                 0xFFFUL
/* PTC_PP.THRESHOLD */
#define PTC_PP_THRESHOLD_LOW_Pos                0UL
#define PTC_PP_THRESHOLD_LOW_Msk                0xFFFUL
#define PTC_PP_THRESHOLD_HIGH_Pos               16UL
#define PTC_PP_THRESHOLD_HIGH_Msk               0xFFF0000UL
#define PTC_PP_THRESHOLD_COND_Pos               28UL
#define PTC_PP_THRESHOLD_COND_Msk               0x30000000UL
/* PTC_PP.WINDOW */
#define PTC_PP_WINDOW_SIZE_Pos                  0UL
#define PTC_PP_WINDOW_SIZE_Msk                  0x7UL


/* PTC_TRIM.CMP0_OFFSET_TRIM */
#define PTC_TRIM_CMP0_OFFSET_TRIM_CMP0_MAGNITUDE_Pos 0UL
#define PTC_TRIM_CMP0_OFFSET_TRIM_CMP0_MAGNITUDE_Msk 0xFUL
#define PTC_TRIM_CMP0_OFFSET_TRIM_CMP0_POLARITY_Pos 4UL
#define PTC_TRIM_CMP0_OFFSET_TRIM_CMP0_POLARITY_Msk 0x10UL
#define PTC_TRIM_CMP0_OFFSET_TRIM_CMP0_EN_Pos   5UL
#define PTC_TRIM_CMP0_OFFSET_TRIM_CMP0_EN_Msk   0x20UL
/* PTC_TRIM.CMP1_OFFSET_TRIM */
#define PTC_TRIM_CMP1_OFFSET_TRIM_CMP1_MAGNITUDE_Pos 0UL
#define PTC_TRIM_CMP1_OFFSET_TRIM_CMP1_MAGNITUDE_Msk 0xFUL
#define PTC_TRIM_CMP1_OFFSET_TRIM_CMP1_POLARITY_Pos 4UL
#define PTC_TRIM_CMP1_OFFSET_TRIM_CMP1_POLARITY_Msk 0x10UL
#define PTC_TRIM_CMP1_OFFSET_TRIM_CMP1_EN_Pos   5UL
#define PTC_TRIM_CMP1_OFFSET_TRIM_CMP1_EN_Msk   0x20UL


#endif /* _CYIP_PTC_V1_1_H_ */


/* [] END OF FILE */

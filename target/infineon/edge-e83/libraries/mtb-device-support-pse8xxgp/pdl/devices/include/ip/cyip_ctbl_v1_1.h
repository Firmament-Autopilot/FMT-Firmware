/***************************************************************************//**
* CTBL IP definitions
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

#ifndef _CYIP_CTBL_V1_1_H_
#define _CYIP_CTBL_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     CTBL
*******************************************************************************/

#define CTBL_STA_SECTION_SIZE                   0x00000200UL
#define CTBL_DYN_SECTION_SIZE                   0x00000010UL
#define CTBL_TRIM_SECTION_SIZE                  0x00000020UL
#define CTBL_SECTION_SIZE                       0x00010000UL

/**
  * \brief CTBL static configuration (CTBL_STA)
  */
typedef struct {
  __IOM uint32_t CFG;                           /*!< 0x00000000 Configuration (only accessible if ACTRLR.STATUS.MODE=0) */
   __IM uint32_t COMP_STAT;                     /*!< 0x00000004 Comparator status */
   __IM uint32_t RESERVED[126];
} CTBL_STA_Type;                                /*!< Size = 512 (0x200) */

/**
  * \brief CTBL dynamic configuration structure (only accessible if ACTRLR.STATUS.MODE=0) (CTBL_DYN)
  */
typedef struct {
  __IOM uint32_t OA_MUX_CFG;                    /*!< 0x00000000 Opamp Mux Configuration */
   __IM uint32_t RESERVED[3];
} CTBL_DYN_Type;                                /*!< Size = 16 (0x10) */

/**
  * \brief CTBL trim structure (only accessible if ACTRLR.STATUS.MODE=0) (CTBL_TRIM)
  */
typedef struct {
  __IOM uint32_t OA0_OFFSET_TRIM;               /*!< 0x00000000 Opamp0 trim control */
  __IOM uint32_t OA0_SLOPE_OFFSET_TRIM;         /*!< 0x00000004 Opamp0 trim control */
  __IOM uint32_t OA0_COMP_TRIM;                 /*!< 0x00000008 Opamp0 trim control */
  __IOM uint32_t OA1_OFFSET_TRIM;               /*!< 0x0000000C Opamp1 trim control */
  __IOM uint32_t OA1_SLOPE_OFFSET_TRIM;         /*!< 0x00000010 Opamp1 trim control */
  __IOM uint32_t OA1_COMP_TRIM;                 /*!< 0x00000014 Opamp1 trim control */
  __IOM uint32_t RMP_TRIM;                      /*!< 0x00000018 Risk Mitigation bits */
   __IM uint32_t RESERVED;
} CTBL_TRIM_Type;                               /*!< Size = 32 (0x20) */

/**
  * \brief Continuous Time Block Lite (CTBL)
  */
typedef struct {
   __IM uint32_t RESERVED[256];
        CTBL_STA_Type STA;                      /*!< 0x00000400 CTBL static configuration */
        CTBL_DYN_Type DYN[8];                   /*!< 0x00000600 CTBL dynamic configuration structure (only accessible if
                                                                ACTRLR.STATUS.MODE=0) */
   __IM uint32_t RESERVED1[544];
        CTBL_TRIM_Type TRIM;                    /*!< 0x00000F00 CTBL trim structure (only accessible if ACTRLR.STATUS.MODE=0) */
} CTBL_Type;                                    /*!< Size = 3872 (0xF20) */


/* CTBL_STA.CFG */
#define CTBL_STA_CFG_OA0_PWR_MODE_Pos           0UL
#define CTBL_STA_CFG_OA0_PWR_MODE_Msk           0xFUL
#define CTBL_STA_CFG_OA0_TOPO_Pos               4UL
#define CTBL_STA_CFG_OA0_TOPO_Msk               0xF0UL
#define CTBL_STA_CFG_OA0_COMP_OUT_Pos           8UL
#define CTBL_STA_CFG_OA0_COMP_OUT_Msk           0x300UL
#define CTBL_STA_CFG_RES0_SWAP_Pos              10UL
#define CTBL_STA_CFG_RES0_SWAP_Msk              0x400UL
#define CTBL_STA_CFG_OA0_CC_ENABLE_Pos          11UL
#define CTBL_STA_CFG_OA0_CC_ENABLE_Msk          0x800UL
#define CTBL_STA_CFG_C0_FB_Pos                  12UL
#define CTBL_STA_CFG_C0_FB_Msk                  0xF000UL
#define CTBL_STA_CFG_OA1_PWR_MODE_Pos           16UL
#define CTBL_STA_CFG_OA1_PWR_MODE_Msk           0xF0000UL
#define CTBL_STA_CFG_OA1_TOPO_Pos               20UL
#define CTBL_STA_CFG_OA1_TOPO_Msk               0xF00000UL
#define CTBL_STA_CFG_OA1_COMP_OUT_Pos           24UL
#define CTBL_STA_CFG_OA1_COMP_OUT_Msk           0x3000000UL
#define CTBL_STA_CFG_RES1_SWAP_Pos              26UL
#define CTBL_STA_CFG_RES1_SWAP_Msk              0x4000000UL
#define CTBL_STA_CFG_OA1_CC_ENABLE_Pos          27UL
#define CTBL_STA_CFG_OA1_CC_ENABLE_Msk          0x8000000UL
#define CTBL_STA_CFG_C1_FB_Pos                  28UL
#define CTBL_STA_CFG_C1_FB_Msk                  0xF0000000UL
/* CTBL_STA.COMP_STAT */
#define CTBL_STA_COMP_STAT_OA0_COMP_Pos         0UL
#define CTBL_STA_COMP_STAT_OA0_COMP_Msk         0x1UL
#define CTBL_STA_COMP_STAT_OA1_COMP_Pos         16UL
#define CTBL_STA_COMP_STAT_OA1_COMP_Msk         0x10000UL


/* CTBL_DYN.OA_MUX_CFG */
#define CTBL_DYN_OA_MUX_CFG_OA_INP_DIRECT_Pos   0UL
#define CTBL_DYN_OA_MUX_CFG_OA_INP_DIRECT_Msk   0x3UL
#define CTBL_DYN_OA_MUX_CFG_OA_INP_REF_Pos      4UL
#define CTBL_DYN_OA_MUX_CFG_OA_INP_REF_Msk      0x70UL
#define CTBL_DYN_OA_MUX_CFG_OA_INM_DIRECT_Pos   8UL
#define CTBL_DYN_OA_MUX_CFG_OA_INM_DIRECT_Msk   0x300UL
#define CTBL_DYN_OA_MUX_CFG_OA_RES_DIRECT_Pos   12UL
#define CTBL_DYN_OA_MUX_CFG_OA_RES_DIRECT_Msk   0x3000UL
#define CTBL_DYN_OA_MUX_CFG_OA_RES_REF_Pos      16UL
#define CTBL_DYN_OA_MUX_CFG_OA_RES_REF_Msk      0x70000UL
#define CTBL_DYN_OA_MUX_CFG_CTBBUS_MUX_IN_Pos   20UL
#define CTBL_DYN_OA_MUX_CFG_CTBBUS_MUX_IN_Msk   0xF00000UL
#define CTBL_DYN_OA_MUX_CFG_CTBBUS_MUX_OUT_Pos  24UL
#define CTBL_DYN_OA_MUX_CFG_CTBBUS_MUX_OUT_Msk  0xF000000UL
#define CTBL_DYN_OA_MUX_CFG_OA_TO_PIN_Pos       30UL
#define CTBL_DYN_OA_MUX_CFG_OA_TO_PIN_Msk       0x40000000UL


/* CTBL_TRIM.OA0_OFFSET_TRIM */
#define CTBL_TRIM_OA0_OFFSET_TRIM_OA0_OFFSET_TRIM_Pos 0UL
#define CTBL_TRIM_OA0_OFFSET_TRIM_OA0_OFFSET_TRIM_Msk 0x3FUL
/* CTBL_TRIM.OA0_SLOPE_OFFSET_TRIM */
#define CTBL_TRIM_OA0_SLOPE_OFFSET_TRIM_OA0_SLOPE_OFFSET_TRIM_Pos 0UL
#define CTBL_TRIM_OA0_SLOPE_OFFSET_TRIM_OA0_SLOPE_OFFSET_TRIM_Msk 0x3FUL
/* CTBL_TRIM.OA0_COMP_TRIM */
#define CTBL_TRIM_OA0_COMP_TRIM_OA0_COMP_TRIM_Pos 0UL
#define CTBL_TRIM_OA0_COMP_TRIM_OA0_COMP_TRIM_Msk 0xFUL
/* CTBL_TRIM.OA1_OFFSET_TRIM */
#define CTBL_TRIM_OA1_OFFSET_TRIM_OA1_OFFSET_TRIM_Pos 0UL
#define CTBL_TRIM_OA1_OFFSET_TRIM_OA1_OFFSET_TRIM_Msk 0x3FUL
/* CTBL_TRIM.OA1_SLOPE_OFFSET_TRIM */
#define CTBL_TRIM_OA1_SLOPE_OFFSET_TRIM_OA1_SLOPE_OFFSET_TRIM_Pos 0UL
#define CTBL_TRIM_OA1_SLOPE_OFFSET_TRIM_OA1_SLOPE_OFFSET_TRIM_Msk 0x3FUL
/* CTBL_TRIM.OA1_COMP_TRIM */
#define CTBL_TRIM_OA1_COMP_TRIM_OA1_COMP_TRIM_Pos 0UL
#define CTBL_TRIM_OA1_COMP_TRIM_OA1_COMP_TRIM_Msk 0xFUL
/* CTBL_TRIM.RMP_TRIM */
#define CTBL_TRIM_RMP_TRIM_RMP_TRIM_Pos         0UL
#define CTBL_TRIM_RMP_TRIM_RMP_TRIM_Msk         0xFUL


#endif /* _CYIP_CTBL_V1_1_H_ */


/* [] END OF FILE */

/***************************************************************************//**
* SAXI_DMAC IP definitions
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

#ifndef _CYIP_SAXI_DMAC_H_
#define _CYIP_SAXI_DMAC_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                  SAXI_DMAC
*******************************************************************************/

#define SAXI_DMAC_CH_SECTION_SIZE               0x00000100UL
#define SAXI_DMAC_SECTION_SIZE                  0x00010000UL

/**
  * \brief AXI DMA controller channel (SAXI_DMAC_CH)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Channel control */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Channel status */
   __IM uint32_t RESERVED[2];
   __IM uint32_t IDX;                           /*!< 0x00000010 Channel current X and Y indices */
   __IM uint32_t SRC;                           /*!< 0x00000014 Channel current source address */
   __IM uint32_t DST;                           /*!< 0x00000018 Channel current destination address */
   __IM uint32_t M_IDX;                         /*!< 0x0000001C Channel current M index */
  __IOM uint32_t CURR;                          /*!< 0x00000020 Channel current descriptor pointer */
   __IM uint32_t RESERVED1;
  __IOM uint32_t TR_CMD;                        /*!< 0x00000028 Channel software trigger */
   __IM uint32_t RESERVED2[5];
   __IM uint32_t DESCR_STATUS;                  /*!< 0x00000040 Channel descriptor status */
   __IM uint32_t RESERVED3[3];
   __IM uint32_t DESCR_CTL;                     /*!< 0x00000050 Channel descriptor control */
   __IM uint32_t DESCR_SRC;                     /*!< 0x00000054 Channel descriptor source */
   __IM uint32_t DESCR_DST;                     /*!< 0x00000058 Channel descriptor destination */
   __IM uint32_t DESCR_M_SIZE;                  /*!< 0x0000005C Channel descriptor M size */
   __IM uint32_t DESCR_X_SIZE;                  /*!< 0x00000060 Channel descriptor X size */
   __IM uint32_t DESCR_X_INCR;                  /*!< 0x00000064 Channel descriptor X increment */
   __IM uint32_t DESCR_Y_SIZE;                  /*!< 0x00000068 Channel descriptor Y size */
   __IM uint32_t DESCR_Y_INCR;                  /*!< 0x0000006C Channel descriptor Y increment */
   __IM uint32_t DESCR_NEXT;                    /*!< 0x00000070 Channel descriptor next pointer */
   __IM uint32_t RESERVED4[3];
  __IOM uint32_t INTR;                          /*!< 0x00000080 Interrupt */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000084 Interrupt set */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000088 Interrupt mask */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000008C Interrupt masked */
   __IM uint32_t RESERVED5[28];
} SAXI_DMAC_CH_Type;                            /*!< Size = 256 (0x100) */

/**
  * \brief AXI DMAC (SAXI_DMAC)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Control */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Enabled channels */
   __IM uint32_t ACTIVE;                        /*!< 0x00000008 Active channels */
   __IM uint32_t RESERVED[1021];
        SAXI_DMAC_CH_Type CH[8];                /*!< 0x00001000 AXI DMA controller channel */
} SAXI_DMAC_Type;                               /*!< Size = 6144 (0x1800) */


/* SAXI_DMAC_CH.CTL */
#define SAXI_DMAC_CH_CTL_P_Pos                  0UL
#define SAXI_DMAC_CH_CTL_P_Msk                  0x1UL
#define SAXI_DMAC_CH_CTL_NS_Pos                 1UL
#define SAXI_DMAC_CH_CTL_NS_Msk                 0x2UL
#define SAXI_DMAC_CH_CTL_B_Pos                  2UL
#define SAXI_DMAC_CH_CTL_B_Msk                  0x4UL
#define SAXI_DMAC_CH_CTL_PC_Pos                 4UL
#define SAXI_DMAC_CH_CTL_PC_Msk                 0xF0UL
#define SAXI_DMAC_CH_CTL_PRIO_Pos               8UL
#define SAXI_DMAC_CH_CTL_PRIO_Msk               0x300UL
#define SAXI_DMAC_CH_CTL_ENABLED_Pos            31UL
#define SAXI_DMAC_CH_CTL_ENABLED_Msk            0x80000000UL
/* SAXI_DMAC_CH.STATUS */
#define SAXI_DMAC_CH_STATUS_ENABLED_Pos         31UL
#define SAXI_DMAC_CH_STATUS_ENABLED_Msk         0x80000000UL
/* SAXI_DMAC_CH.IDX */
#define SAXI_DMAC_CH_IDX_X_Pos                  0UL
#define SAXI_DMAC_CH_IDX_X_Msk                  0xFFFFUL
#define SAXI_DMAC_CH_IDX_Y_Pos                  16UL
#define SAXI_DMAC_CH_IDX_Y_Msk                  0xFFFF0000UL
/* SAXI_DMAC_CH.SRC */
#define SAXI_DMAC_CH_SRC_ADDR_Pos               0UL
#define SAXI_DMAC_CH_SRC_ADDR_Msk               0xFFFFFFFFUL
/* SAXI_DMAC_CH.DST */
#define SAXI_DMAC_CH_DST_ADDR_Pos               0UL
#define SAXI_DMAC_CH_DST_ADDR_Msk               0xFFFFFFFFUL
/* SAXI_DMAC_CH.M_IDX */
#define SAXI_DMAC_CH_M_IDX_M_Pos                0UL
#define SAXI_DMAC_CH_M_IDX_M_Msk                0xFFFFFFUL
/* SAXI_DMAC_CH.CURR */
#define SAXI_DMAC_CH_CURR_PTR_Pos               3UL
#define SAXI_DMAC_CH_CURR_PTR_Msk               0xFFFFFFF8UL
/* SAXI_DMAC_CH.TR_CMD */
#define SAXI_DMAC_CH_TR_CMD_ACTIVATE_Pos        0UL
#define SAXI_DMAC_CH_TR_CMD_ACTIVATE_Msk        0x1UL
/* SAXI_DMAC_CH.DESCR_STATUS */
#define SAXI_DMAC_CH_DESCR_STATUS_VALID_Pos     31UL
#define SAXI_DMAC_CH_DESCR_STATUS_VALID_Msk     0x80000000UL
/* SAXI_DMAC_CH.DESCR_CTL */
#define SAXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Pos 0UL
#define SAXI_DMAC_CH_DESCR_CTL_WAIT_FOR_DEACT_Msk 0x3UL
#define SAXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Pos    2UL
#define SAXI_DMAC_CH_DESCR_CTL_INTR_TYPE_Msk    0xCUL
#define SAXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Pos  4UL
#define SAXI_DMAC_CH_DESCR_CTL_TR_OUT_TYPE_Msk  0x30UL
#define SAXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Pos   6UL
#define SAXI_DMAC_CH_DESCR_CTL_TR_IN_TYPE_Msk   0xC0UL
#define SAXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Pos 8UL
#define SAXI_DMAC_CH_DESCR_CTL_DATA_PREFETCH_Msk 0x100UL
#define SAXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Pos   24UL
#define SAXI_DMAC_CH_DESCR_CTL_CH_DISABLE_Msk   0x1000000UL
#define SAXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Pos   28UL
#define SAXI_DMAC_CH_DESCR_CTL_DESCR_TYPE_Msk   0x30000000UL
/* SAXI_DMAC_CH.DESCR_SRC */
#define SAXI_DMAC_CH_DESCR_SRC_ADDR_Pos         0UL
#define SAXI_DMAC_CH_DESCR_SRC_ADDR_Msk         0xFFFFFFFFUL
/* SAXI_DMAC_CH.DESCR_DST */
#define SAXI_DMAC_CH_DESCR_DST_ADDR_Pos         0UL
#define SAXI_DMAC_CH_DESCR_DST_ADDR_Msk         0xFFFFFFFFUL
/* SAXI_DMAC_CH.DESCR_M_SIZE */
#define SAXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Pos   0UL
#define SAXI_DMAC_CH_DESCR_M_SIZE_M_COUNT_Msk   0xFFFFFFUL
/* SAXI_DMAC_CH.DESCR_X_SIZE */
#define SAXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Pos   0UL
#define SAXI_DMAC_CH_DESCR_X_SIZE_X_COUNT_Msk   0xFFFFUL
/* SAXI_DMAC_CH.DESCR_X_INCR */
#define SAXI_DMAC_CH_DESCR_X_INCR_SRC_X_Pos     0UL
#define SAXI_DMAC_CH_DESCR_X_INCR_SRC_X_Msk     0xFFFFUL
#define SAXI_DMAC_CH_DESCR_X_INCR_DST_X_Pos     16UL
#define SAXI_DMAC_CH_DESCR_X_INCR_DST_X_Msk     0xFFFF0000UL
/* SAXI_DMAC_CH.DESCR_Y_SIZE */
#define SAXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Pos   0UL
#define SAXI_DMAC_CH_DESCR_Y_SIZE_Y_COUNT_Msk   0xFFFFUL
/* SAXI_DMAC_CH.DESCR_Y_INCR */
#define SAXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Pos     0UL
#define SAXI_DMAC_CH_DESCR_Y_INCR_SRC_Y_Msk     0xFFFFUL
#define SAXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Pos     16UL
#define SAXI_DMAC_CH_DESCR_Y_INCR_DST_Y_Msk     0xFFFF0000UL
/* SAXI_DMAC_CH.DESCR_NEXT */
#define SAXI_DMAC_CH_DESCR_NEXT_PTR_Pos         3UL
#define SAXI_DMAC_CH_DESCR_NEXT_PTR_Msk         0xFFFFFFF8UL
/* SAXI_DMAC_CH.INTR */
#define SAXI_DMAC_CH_INTR_COMPLETION_Pos        0UL
#define SAXI_DMAC_CH_INTR_COMPLETION_Msk        0x1UL
#define SAXI_DMAC_CH_INTR_SRC_BUS_ERROR_Pos     1UL
#define SAXI_DMAC_CH_INTR_SRC_BUS_ERROR_Msk     0x2UL
#define SAXI_DMAC_CH_INTR_DST_BUS_ERROR_Pos     2UL
#define SAXI_DMAC_CH_INTR_DST_BUS_ERROR_Msk     0x4UL
#define SAXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Pos 3UL
#define SAXI_DMAC_CH_INTR_INVALID_DESCR_TYPE_Msk 0x8UL
#define SAXI_DMAC_CH_INTR_CURR_PTR_NULL_Pos     5UL
#define SAXI_DMAC_CH_INTR_CURR_PTR_NULL_Msk     0x20UL
#define SAXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Pos 6UL
#define SAXI_DMAC_CH_INTR_ACTIVE_CH_DISABLED_Msk 0x40UL
#define SAXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Pos   7UL
#define SAXI_DMAC_CH_INTR_DESCR_BUS_ERROR_Msk   0x80UL
/* SAXI_DMAC_CH.INTR_SET */
#define SAXI_DMAC_CH_INTR_SET_COMPLETION_Pos    0UL
#define SAXI_DMAC_CH_INTR_SET_COMPLETION_Msk    0x1UL
#define SAXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Pos 1UL
#define SAXI_DMAC_CH_INTR_SET_SRC_BUS_ERROR_Msk 0x2UL
#define SAXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Pos 2UL
#define SAXI_DMAC_CH_INTR_SET_DST_BUS_ERROR_Msk 0x4UL
#define SAXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Pos 3UL
#define SAXI_DMAC_CH_INTR_SET_INVALID_DESCR_TYPE_Msk 0x8UL
#define SAXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Pos 5UL
#define SAXI_DMAC_CH_INTR_SET_CURR_PTR_NULL_Msk 0x20UL
#define SAXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Pos 6UL
#define SAXI_DMAC_CH_INTR_SET_ACTIVE_CH_DISABLED_Msk 0x40UL
#define SAXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Pos 7UL
#define SAXI_DMAC_CH_INTR_SET_DESCR_BUS_ERROR_Msk 0x80UL
/* SAXI_DMAC_CH.INTR_MASK */
#define SAXI_DMAC_CH_INTR_MASK_COMPLETION_Pos   0UL
#define SAXI_DMAC_CH_INTR_MASK_COMPLETION_Msk   0x1UL
#define SAXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Pos 1UL
#define SAXI_DMAC_CH_INTR_MASK_SRC_BUS_ERROR_Msk 0x2UL
#define SAXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Pos 2UL
#define SAXI_DMAC_CH_INTR_MASK_DST_BUS_ERROR_Msk 0x4UL
#define SAXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Pos 3UL
#define SAXI_DMAC_CH_INTR_MASK_INVALID_DESCR_TYPE_Msk 0x8UL
#define SAXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Pos 5UL
#define SAXI_DMAC_CH_INTR_MASK_CURR_PTR_NULL_Msk 0x20UL
#define SAXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Pos 6UL
#define SAXI_DMAC_CH_INTR_MASK_ACTIVE_CH_DISABLED_Msk 0x40UL
#define SAXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Pos 7UL
#define SAXI_DMAC_CH_INTR_MASK_DESCR_BUS_ERROR_Msk 0x80UL
/* SAXI_DMAC_CH.INTR_MASKED */
#define SAXI_DMAC_CH_INTR_MASKED_COMPLETION_Pos 0UL
#define SAXI_DMAC_CH_INTR_MASKED_COMPLETION_Msk 0x1UL
#define SAXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Pos 1UL
#define SAXI_DMAC_CH_INTR_MASKED_SRC_BUS_ERROR_Msk 0x2UL
#define SAXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Pos 2UL
#define SAXI_DMAC_CH_INTR_MASKED_DST_BUS_ERROR_Msk 0x4UL
#define SAXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Pos 3UL
#define SAXI_DMAC_CH_INTR_MASKED_INVALID_DESCR_TYPE_Msk 0x8UL
#define SAXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Pos 5UL
#define SAXI_DMAC_CH_INTR_MASKED_CURR_PTR_NULL_Msk 0x20UL
#define SAXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Pos 6UL
#define SAXI_DMAC_CH_INTR_MASKED_ACTIVE_CH_DISABLED_Msk 0x40UL
#define SAXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Pos 7UL
#define SAXI_DMAC_CH_INTR_MASKED_DESCR_BUS_ERROR_Msk 0x80UL


/* SAXI_DMAC.CTL */
#define SAXI_DMAC_CTL_ENABLED_Pos               31UL
#define SAXI_DMAC_CTL_ENABLED_Msk               0x80000000UL
/* SAXI_DMAC.STATUS */
#define SAXI_DMAC_STATUS_CH_EN_Pos              0UL
#define SAXI_DMAC_STATUS_CH_EN_Msk              0xFFUL
/* SAXI_DMAC.ACTIVE */
#define SAXI_DMAC_ACTIVE_ACTIVE_Pos             0UL
#define SAXI_DMAC_ACTIVE_ACTIVE_Msk             0xFFUL


#endif /* _CYIP_SAXI_DMAC_H_ */


/* [] END OF FILE */

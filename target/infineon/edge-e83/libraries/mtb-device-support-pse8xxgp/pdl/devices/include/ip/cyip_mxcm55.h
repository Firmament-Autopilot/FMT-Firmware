/***************************************************************************//**
* MXCM55 IP definitions
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

#ifndef _CYIP_MXCM55_H_
#define _CYIP_MXCM55_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    MXCM55
*******************************************************************************/

#define MXCM55_SECTION_SIZE                     0x00010000UL

/**
  * \brief MXCM55-0/1 (MXCM55)
  */
typedef struct {
  __IOM uint32_t CM55_CTL;                      /*!< 0x00000000 Control */
  __IOM uint32_t CM55_CMD;                      /*!< 0x00000004 Command */
   __IM uint32_t CM55_STATUS;                   /*!< 0x00000008 Status */
  __IOM uint32_t CM55_TCM_CTL;                  /*!< 0x0000000C TCM control */
   __IM uint32_t RESERVED[12];
   __IM uint32_t CM55_INT_STATUS[16];           /*!< 0x00000040 CM55 interrupt status */
  __IOM uint32_t CM55_NMI_CTL[4];               /*!< 0x00000080 CM55 NMI control */
   __IM uint32_t RESERVED1[12];
  __IOM uint32_t CM55_EVENT_CTL;                /*!< 0x000000C0 CM55 EVENT control */
   __IM uint32_t RESERVED2[975];
  __IOM uint32_t CM55_S_VECTOR_TABLE_BASE;      /*!< 0x00001000 CM55 secure vector table base */
  __IOM uint32_t CM55_NS_VECTOR_TABLE_BASE;     /*!< 0x00001004 CM55 non-secure vector table base */
   __IM uint32_t RESERVED3[1070];
  __IOM uint32_t WOUNDING;                      /*!< 0x000020C0 Wounding */
   __IM uint32_t RESERVED4[6095];
  __IOM uint32_t CM55_SYSTEM_INT_CTL[1023];     /*!< 0x00008000 CM55 system interrupt control */
} MXCM55_Type;                                  /*!< Size = 36860 (0x8FFC) */


/* MXCM55.CM55_CTL */
#define MXCM55_CM55_CTL_CPU_WAIT_Pos            4UL
#define MXCM55_CM55_CTL_CPU_WAIT_Msk            0x10UL
#define MXCM55_CM55_CTL_LOCKNSVTOR_Pos          8UL
#define MXCM55_CM55_CTL_LOCKNSVTOR_Msk          0x100UL
#define MXCM55_CM55_CTL_LOCKSVTAIRCR_Pos        9UL
#define MXCM55_CM55_CTL_LOCKSVTAIRCR_Msk        0x200UL
#define MXCM55_CM55_CTL_LOCKSMPU_Pos            10UL
#define MXCM55_CM55_CTL_LOCKSMPU_Msk            0x400UL
#define MXCM55_CM55_CTL_LOCKNSMPU_Pos           11UL
#define MXCM55_CM55_CTL_LOCKNSMPU_Msk           0x800UL
#define MXCM55_CM55_CTL_LOCKSAU_Pos             12UL
#define MXCM55_CM55_CTL_LOCKSAU_Msk             0x1000UL
#define MXCM55_CM55_CTL_LOCKPAHB_Pos            13UL
#define MXCM55_CM55_CTL_LOCKPAHB_Msk            0x2000UL
#define MXCM55_CM55_CTL_LOCKDCAIC_Pos           14UL
#define MXCM55_CM55_CTL_LOCKDCAIC_Msk           0x4000UL
#define MXCM55_CM55_CTL_LOCKTCM_Pos             15UL
#define MXCM55_CM55_CTL_LOCKTCM_Msk             0x8000UL
#define MXCM55_CM55_CTL_LOCKITGU_Pos            16UL
#define MXCM55_CM55_CTL_LOCKITGU_Msk            0x10000UL
#define MXCM55_CM55_CTL_LOCKDTGU_Pos            17UL
#define MXCM55_CM55_CTL_LOCKDTGU_Msk            0x20000UL
#define MXCM55_CM55_CTL_IOC_MASK_Pos            24UL
#define MXCM55_CM55_CTL_IOC_MASK_Msk            0x1000000UL
#define MXCM55_CM55_CTL_DZC_MASK_Pos            25UL
#define MXCM55_CM55_CTL_DZC_MASK_Msk            0x2000000UL
#define MXCM55_CM55_CTL_OFC_MASK_Pos            26UL
#define MXCM55_CM55_CTL_OFC_MASK_Msk            0x4000000UL
#define MXCM55_CM55_CTL_UFC_MASK_Pos            27UL
#define MXCM55_CM55_CTL_UFC_MASK_Msk            0x8000000UL
#define MXCM55_CM55_CTL_IXC_MASK_Pos            28UL
#define MXCM55_CM55_CTL_IXC_MASK_Msk            0x10000000UL
#define MXCM55_CM55_CTL_IDC_MASK_Pos            31UL
#define MXCM55_CM55_CTL_IDC_MASK_Msk            0x80000000UL
/* MXCM55.CM55_CMD */
#define MXCM55_CM55_CMD_RESET_Pos               0UL
#define MXCM55_CM55_CMD_RESET_Msk               0x1UL
#define MXCM55_CM55_CMD_VECTKEYSTAT_Pos         16UL
#define MXCM55_CM55_CMD_VECTKEYSTAT_Msk         0xFFFF0000UL
/* MXCM55.CM55_STATUS */
#define MXCM55_CM55_STATUS_SLEEPING_Pos         0UL
#define MXCM55_CM55_STATUS_SLEEPING_Msk         0x1UL
#define MXCM55_CM55_STATUS_SLEEPDEEP_Pos        1UL
#define MXCM55_CM55_STATUS_SLEEPDEEP_Msk        0x2UL
/* MXCM55.CM55_TCM_CTL */
#define MXCM55_CM55_TCM_CTL_ITCM_READ_WS_Pos    0UL
#define MXCM55_CM55_TCM_CTL_ITCM_READ_WS_Msk    0x1UL
#define MXCM55_CM55_TCM_CTL_DTCM_READ_WS_Pos    16UL
#define MXCM55_CM55_TCM_CTL_DTCM_READ_WS_Msk    0x10000UL
/* MXCM55.CM55_INT_STATUS */
#define MXCM55_CM55_INT_STATUS_SYSTEM_INT_IDX_Pos 0UL
#define MXCM55_CM55_INT_STATUS_SYSTEM_INT_IDX_Msk 0x3FFUL
#define MXCM55_CM55_INT_STATUS_SYSTEM_INT_VALID_Pos 31UL
#define MXCM55_CM55_INT_STATUS_SYSTEM_INT_VALID_Msk 0x80000000UL
/* MXCM55.CM55_NMI_CTL */
#define MXCM55_CM55_NMI_CTL_SYSTEM_INT_IDX_Pos  0UL
#define MXCM55_CM55_NMI_CTL_SYSTEM_INT_IDX_Msk  0x3FFUL
/* MXCM55.CM55_EVENT_CTL */
#define MXCM55_CM55_EVENT_CTL_MASK_Pos          0UL
#define MXCM55_CM55_EVENT_CTL_MASK_Msk          0x1FUL
/* MXCM55.CM55_S_VECTOR_TABLE_BASE */
#define MXCM55_CM55_S_VECTOR_TABLE_BASE_ADDR25_Pos 7UL
#define MXCM55_CM55_S_VECTOR_TABLE_BASE_ADDR25_Msk 0xFFFFFF80UL
/* MXCM55.CM55_NS_VECTOR_TABLE_BASE */
#define MXCM55_CM55_NS_VECTOR_TABLE_BASE_ADDR25_Pos 7UL
#define MXCM55_CM55_NS_VECTOR_TABLE_BASE_ADDR25_Msk 0xFFFFFF80UL
/* MXCM55.WOUNDING */
#define MXCM55_WOUNDING_FPU_WOUND_Pos           0UL
#define MXCM55_WOUNDING_FPU_WOUND_Msk           0x1UL
/* MXCM55.CM55_SYSTEM_INT_CTL */
#define MXCM55_CM55_SYSTEM_INT_CTL_CPU_INT_IDX_Pos 0UL
#define MXCM55_CM55_SYSTEM_INT_CTL_CPU_INT_IDX_Msk 0xFUL
#define MXCM55_CM55_SYSTEM_INT_CTL_CPU_INT_VALID_Pos 31UL
#define MXCM55_CM55_SYSTEM_INT_CTL_CPU_INT_VALID_Msk 0x80000000UL


#endif /* _CYIP_MXCM55_H_ */


/* [] END OF FILE */

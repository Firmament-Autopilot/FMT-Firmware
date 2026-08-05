/***************************************************************************//**
* MS_CTL IP definitions
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

#ifndef _CYIP_MS_CTL_V1_1_H_
#define _CYIP_MS_CTL_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    MS_CTL
*******************************************************************************/

#define MS_CTL_MS_SECTION_SIZE                  0x00000010UL
#define MS_CTL_MS_PC_SECTION_SIZE               0x00000010UL
#define MS_CTL_SECTION_SIZE                     0x00004000UL

/**
  * \brief Master protection context control (MS_CTL_MS)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Master 'x' protection context control */
   __IM uint32_t RESERVED[3];
} MS_CTL_MS_Type;                               /*!< Size = 16 (0x10) */

/**
  * \brief Master protection context value (MS_CTL_MS_PC)
  */
typedef struct {
  __IOM uint32_t PC;                            /*!< 0x00000000 Master 'x' protection context value */
   __IM uint32_t PC_READ_MIR;                   /*!< 0x00000004 Master 'x' protection context value read mirror register */
   __IM uint32_t RESERVED[2];
} MS_CTL_MS_PC_Type;                            /*!< Size = 16 (0x10) */

/**
  * \brief Master control registers (MS_CTL)
  */
typedef struct {
        MS_CTL_MS_Type MS[32];                  /*!< 0x00000000 Master protection context control */
   __IM uint32_t RESERVED[896];
        MS_CTL_MS_PC_Type MS_PC[32];            /*!< 0x00001000 Master protection context value */
   __IM uint32_t RESERVED1[896];
  __IOM uint32_t SYS_MS0_MSC_ACG_CTL;           /*!< 0x00002000 SYS_MS0  master security Controller & ACG configuration */
  __IOM uint32_t SYS_MS1_MSC_ACG_CTL;           /*!< 0x00002004 SYS_MS1  master security Controller & ACG configuration */
   __IM uint32_t RESERVED2[2];
  __IOM uint32_t AXIDMAC0_MSC_ACG_CTL;          /*!< 0x00002010 AXI DMAC0 MSC and ACG configuration */
  __IOM uint32_t AXIDMAC1_MSC_ACG_CTL;          /*!< 0x00002014 AXI DMAC1 MSC and ACG configuration */
   __IM uint32_t RESERVED3[6];
  __IOM uint32_t AXI_MS0_MSC_ACG_CTL;           /*!< 0x00002030 AXI_MS0  master security Controller & ACG configuration */
  __IOM uint32_t AXI_MS1_MSC_ACG_CTL;           /*!< 0x00002034 AXI_MS1  master security Controller & ACG configuration */
  __IOM uint32_t AXI_MS2_MSC_ACG_CTL;           /*!< 0x00002038 AXI_MS2  master security Controller & ACG configuration */
  __IOM uint32_t AXI_MS3_MSC_ACG_CTL;           /*!< 0x0000203C AXI_MS3  master security Controller & ACG configuration */
  __IOM uint32_t EXP_MS0_MSC_ACG_CTL;           /*!< 0x00002040 EXP_MS0  master security Controller & ACG configuration */
  __IOM uint32_t EXP_MS1_MSC_ACG_CTL;           /*!< 0x00002044 EXP_MS1  master security Controller & ACG configuration */
  __IOM uint32_t EXP_MS2_MSC_ACG_CTL;           /*!< 0x00002048 EXP_MS2  master security Controller & ACG configuration */
  __IOM uint32_t EXP_MS3_MSC_ACG_CTL;           /*!< 0x0000204C EXP_MS3  master security Controller & ACG configuration */
} MS_CTL_Type;                                  /*!< Size = 8272 (0x2050) */


/* MS_CTL_MS.CTL */
#define MS_CTL_MS_CTL_P_Pos                     0UL
#define MS_CTL_MS_CTL_P_Msk                     0x1UL
#define MS_CTL_MS_CTL_NS_Pos                    1UL
#define MS_CTL_MS_CTL_NS_Msk                    0x2UL
#define MS_CTL_MS_CTL_PC_MASK_Pos               16UL
#define MS_CTL_MS_CTL_PC_MASK_Msk               0xFFFF0000UL


/* MS_CTL_MS_PC.PC */
#define MS_CTL_MS_PC_PC_PC_Pos                  0UL
#define MS_CTL_MS_PC_PC_PC_Msk                  0xFUL
#define MS_CTL_MS_PC_PC_PC_SAVED_Pos            16UL
#define MS_CTL_MS_PC_PC_PC_SAVED_Msk            0xF0000UL
/* MS_CTL_MS_PC.PC_READ_MIR */
#define MS_CTL_MS_PC_PC_READ_MIR_PC_Pos         0UL
#define MS_CTL_MS_PC_PC_READ_MIR_PC_Msk         0xFUL
#define MS_CTL_MS_PC_PC_READ_MIR_PC_SAVED_Pos   16UL
#define MS_CTL_MS_PC_PC_READ_MIR_PC_SAVED_Msk   0xF0000UL


/* MS_CTL.SYS_MS0_MSC_ACG_CTL */
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.SYS_MS1_MSC_ACG_CTL */
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.AXIDMAC0_MSC_ACG_CTL */
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.AXIDMAC1_MSC_ACG_CTL */
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.AXI_MS0_MSC_ACG_CTL */
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.AXI_MS1_MSC_ACG_CTL */
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.AXI_MS2_MSC_ACG_CTL */
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.AXI_MS3_MSC_ACG_CTL */
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.EXP_MS0_MSC_ACG_CTL */
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.EXP_MS1_MSC_ACG_CTL */
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.EXP_MS2_MSC_ACG_CTL */
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL
/* MS_CTL.EXP_MS3_MSC_ACG_CTL */
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Pos 0UL
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_Msk 0x1UL
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_Pos 1UL
#define MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_Msk 0x2UL


#endif /* _CYIP_MS_CTL_V1_1_H_ */


/* [] END OF FILE */

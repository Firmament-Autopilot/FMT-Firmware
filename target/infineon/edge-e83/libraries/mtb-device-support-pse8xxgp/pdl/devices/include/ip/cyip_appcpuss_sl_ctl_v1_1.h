/***************************************************************************//**
* APPCPUSS_SL_CTL IP definitions
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

#ifndef _CYIP_APPCPUSS_SL_CTL_V1_1_H_
#define _CYIP_APPCPUSS_SL_CTL_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                               APPCPUSS_SL_CTL
*******************************************************************************/

#define APPCPUSS_SL_CTL_SECTION_SIZE            0x00000010UL

/**
  * \brief APPCPUSS Internal slave control registers (APPCPUSS_SL_CTL)
  */
typedef struct {
  __IOM uint32_t SL_CTL;                        /*!< 0x00000000 Slave control (Clock enables) */
  __IOM uint32_t SL_CTL2;                       /*!< 0x00000004 Slave control2 (Reset enables) */
} APPCPUSS_SL_CTL_Type;                         /*!< Size = 8 (0x8) */


/* APPCPUSS_SL_CTL.SL_CTL */
#define APPCPUSS_SL_CTL_SL_CTL_AXIDMAC0_ENABLED_Pos 0UL
#define APPCPUSS_SL_CTL_SL_CTL_AXIDMAC0_ENABLED_Msk 0x1UL
#define APPCPUSS_SL_CTL_SL_CTL_AXIDMAC1_ENABLED_Pos 1UL
#define APPCPUSS_SL_CTL_SL_CTL_AXIDMAC1_ENABLED_Msk 0x2UL
#define APPCPUSS_SL_CTL_SL_CTL_IPC_ENABLED_Pos  2UL
#define APPCPUSS_SL_CTL_SL_CTL_IPC_ENABLED_Msk  0x4UL
/* APPCPUSS_SL_CTL.SL_CTL2 */
#define APPCPUSS_SL_CTL_SL_CTL2_AXIDMAC0_RST_Pos 0UL
#define APPCPUSS_SL_CTL_SL_CTL2_AXIDMAC0_RST_Msk 0x1UL
#define APPCPUSS_SL_CTL_SL_CTL2_AXIDMAC1_RST_Pos 1UL
#define APPCPUSS_SL_CTL_SL_CTL2_AXIDMAC1_RST_Msk 0x2UL
#define APPCPUSS_SL_CTL_SL_CTL2_IPC_RST_Pos     2UL
#define APPCPUSS_SL_CTL_SL_CTL2_IPC_RST_Msk     0x4UL


#endif /* _CYIP_APPCPUSS_SL_CTL_V1_1_H_ */


/* [] END OF FILE */

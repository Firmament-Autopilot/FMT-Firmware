/***************************************************************************//**
* MAIN_NVM IP definitions
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

#ifndef _CYIP_MAIN_NVM_PSE84_H_
#define _CYIP_MAIN_NVM_PSE84_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   MAIN_NVM
*******************************************************************************/

#define MAIN_NVM_SECTION_SIZE                   0x00040000UL

/**
  * \brief Main NVM Region (256kb) (MAIN_NVM)
  */
typedef struct {
  __IOM uint8_t  UPGRADE_FLAGS[32];             /*!< 0x00000000 PSC1 and above */
   __IM uint8_t  RESERVED_MAIN_NVM_1[4064];     /*!< 0x00000020 MAIN_NVM - Region 1 free bytes */
  __IOM uint8_t  CM33_L1_BOOT_POLICY[256];      /*!< 0x00001000 PSC1 and above */
   __IM uint8_t  RESERVED_MAIN_NVM_0[558];      /*!< 0x00001100 MAIN_NVM - Region 0 free bytes */
  __IOM uint8_t  IAK_LITE_PRIVATE_KEY[36];      /*!< 0x0000132E PSC2 MPN device wounded from PSC4 */
  __IOM uint8_t  IAK_LITE_PUBLIC_KEY[69];       /*!< 0x00001352 PSC2 MPN device wounded from PSC4 */
  __IOM uint8_t  HUK_LITE[36];                  /*!< 0x00001397 PSC2 MPN device wounded from PSC4 */
  __IOM uint8_t  ROTPK_LITE[69];                /*!< 0x000013BB PSC2 MPN device wounded from PSC4 */
   __IM uint32_t RESERVED[16128];
  __IOM uint8_t  USER_NVM[192512];              /*!< 0x00011000 PSC1 and above */
} MAIN_NVM_Type;                                /*!< Size = 262144 (0x40000) */


/* MAIN_NVM.UPGRADE_FLAGS */
#define MAIN_NVM_UPGRADE_FLAGS_DATA8_Pos        0UL
#define MAIN_NVM_UPGRADE_FLAGS_DATA8_Msk        0xFFUL
/* MAIN_NVM.RESERVED_MAIN_NVM_1 */
#define MAIN_NVM_RESERVED_MAIN_NVM_1_DATA8_Pos  0UL
#define MAIN_NVM_RESERVED_MAIN_NVM_1_DATA8_Msk  0xFFUL
/* MAIN_NVM.CM33_L1_BOOT_POLICY */
#define MAIN_NVM_CM33_L1_BOOT_POLICY_DATA8_Pos  0UL
#define MAIN_NVM_CM33_L1_BOOT_POLICY_DATA8_Msk  0xFFUL
/* MAIN_NVM.RESERVED_MAIN_NVM_0 */
#define MAIN_NVM_RESERVED_MAIN_NVM_0_DATA8_Pos  0UL
#define MAIN_NVM_RESERVED_MAIN_NVM_0_DATA8_Msk  0xFFUL
/* MAIN_NVM.IAK_LITE_PRIVATE_KEY */
#define MAIN_NVM_IAK_LITE_PRIVATE_KEY_DATA8_Pos 0UL
#define MAIN_NVM_IAK_LITE_PRIVATE_KEY_DATA8_Msk 0xFFUL
/* MAIN_NVM.IAK_LITE_PUBLIC_KEY */
#define MAIN_NVM_IAK_LITE_PUBLIC_KEY_DATA8_Pos  0UL
#define MAIN_NVM_IAK_LITE_PUBLIC_KEY_DATA8_Msk  0xFFUL
/* MAIN_NVM.HUK_LITE */
#define MAIN_NVM_HUK_LITE_DATA8_Pos             0UL
#define MAIN_NVM_HUK_LITE_DATA8_Msk             0xFFUL
/* MAIN_NVM.ROTPK_LITE */
#define MAIN_NVM_ROTPK_LITE_DATA8_Pos           0UL
#define MAIN_NVM_ROTPK_LITE_DATA8_Msk           0xFFUL
/* MAIN_NVM.USER_NVM */
#define MAIN_NVM_USER_NVM_DATA8_Pos             0UL
#define MAIN_NVM_USER_NVM_DATA8_Msk             0xFFUL


#endif /* _CYIP_MAIN_NVM_PSE84_H_ */


/* [] END OF FILE */

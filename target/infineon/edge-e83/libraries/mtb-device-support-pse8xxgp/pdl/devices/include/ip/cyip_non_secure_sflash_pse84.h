/***************************************************************************//**
* NON_SECURE_SFLASH IP definitions
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

#ifndef _CYIP_NON_SECURE_SFLASH_PSE84_H_
#define _CYIP_NON_SECURE_SFLASH_PSE84_H_

#include "cyip_headers.h"

/*******************************************************************************
*                              NON_SECURE_SFLASH
*******************************************************************************/

#define NON_SECURE_SFLASH_SECTION_SIZE          0x00002000UL

/**
  * \brief NVM non secure subregion (8kb) (NON_SECURE_SFLASH)
  */
typedef struct {
  __IOM uint8_t  DIE_ID[14];                    /*!< 0x00000000 PSC1 and above */
  __IOM uint8_t  DEVICE_ID_TO[7];               /*!< 0x0000000E PSC1 and above */
  __IOM uint8_t  DEVICE_ID_MPN[6];              /*!< 0x00000015 PSC1 and above */
  __IOM uint8_t  L0_VERSION[20];                /*!< 0x0000001B PSC1 and above */
  __IOM uint8_t  L1_VERSION[28];                /*!< 0x0000002F PSC1 and above */
  __IOM uint8_t  DEVICE_RT_CFG_PUBLIC[28];      /*!< 0x0000004B PSC1 and above */
  __IOM uint8_t  DEVICE_RT_CFG_PUBLIC_2[512];   /*!< 0x00000067 PSC1 and above */
  __IOM uint8_t  IFX_DEVICE_CERT[612];          /*!< 0x00000267 PSC2 and above */
  __IOM uint8_t  IFX_CHAIN_OF_TRUST[1280];      /*!< 0x000004CB PSC2 and above */
  __IOM uint8_t  ALIAS_CERT[512];               /*!< 0x000009CB PSC2 and above */
  __IOM uint8_t  OEM_CHAIN_OF_TRUST[5120];      /*!< 0x00000BCB PSC2 and above */
   __IM uint8_t  RESERVED_NON_SEC_SFLASH_0[53]; /*!< 0x00001FCB NON_SECURE_SFLASH 0: region free bytes */
} NON_SECURE_SFLASH_Type;                       /*!< Size = 8192 (0x2000) */


/* NON_SECURE_SFLASH.DIE_ID */
#define NON_SECURE_SFLASH_DIE_ID_DATA8_Pos      0UL
#define NON_SECURE_SFLASH_DIE_ID_DATA8_Msk      0xFFUL
/* NON_SECURE_SFLASH.DEVICE_ID_TO */
#define NON_SECURE_SFLASH_DEVICE_ID_TO_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_DEVICE_ID_TO_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.DEVICE_ID_MPN */
#define NON_SECURE_SFLASH_DEVICE_ID_MPN_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_DEVICE_ID_MPN_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.L0_VERSION */
#define NON_SECURE_SFLASH_L0_VERSION_DATA8_Pos  0UL
#define NON_SECURE_SFLASH_L0_VERSION_DATA8_Msk  0xFFUL
/* NON_SECURE_SFLASH.L1_VERSION */
#define NON_SECURE_SFLASH_L1_VERSION_DATA8_Pos  0UL
#define NON_SECURE_SFLASH_L1_VERSION_DATA8_Msk  0xFFUL
/* NON_SECURE_SFLASH.DEVICE_RT_CFG_PUBLIC */
#define NON_SECURE_SFLASH_DEVICE_RT_CFG_PUBLIC_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_DEVICE_RT_CFG_PUBLIC_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.DEVICE_RT_CFG_PUBLIC_2 */
#define NON_SECURE_SFLASH_DEVICE_RT_CFG_PUBLIC_2_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_DEVICE_RT_CFG_PUBLIC_2_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.IFX_DEVICE_CERT */
#define NON_SECURE_SFLASH_IFX_DEVICE_CERT_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_IFX_DEVICE_CERT_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.IFX_CHAIN_OF_TRUST */
#define NON_SECURE_SFLASH_IFX_CHAIN_OF_TRUST_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_IFX_CHAIN_OF_TRUST_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.ALIAS_CERT */
#define NON_SECURE_SFLASH_ALIAS_CERT_DATA8_Pos  0UL
#define NON_SECURE_SFLASH_ALIAS_CERT_DATA8_Msk  0xFFUL
/* NON_SECURE_SFLASH.OEM_CHAIN_OF_TRUST */
#define NON_SECURE_SFLASH_OEM_CHAIN_OF_TRUST_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_OEM_CHAIN_OF_TRUST_DATA8_Msk 0xFFUL
/* NON_SECURE_SFLASH.RESERVED_NON_SEC_SFLASH_0 */
#define NON_SECURE_SFLASH_RESERVED_NON_SEC_SFLASH_0_DATA8_Pos 0UL
#define NON_SECURE_SFLASH_RESERVED_NON_SEC_SFLASH_0_DATA8_Msk 0xFFUL


#endif /* _CYIP_NON_SECURE_SFLASH_PSE84_H_ */


/* [] END OF FILE */

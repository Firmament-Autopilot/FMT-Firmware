/***************************************************************************//**
* M0SECCPUSS_STATUS IP definitions
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

#ifndef _CYIP_M0SECCPUSS_STATUS_V2_H_
#define _CYIP_M0SECCPUSS_STATUS_V2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                              M0SECCPUSS_STATUS
*******************************************************************************/

#define M0SECCPUSS_STATUS_SECTION_SIZE          0x00000100UL

/**
  * \brief Cortex-M0+ Secured CPU subsystem (M0SECCPUSS_STATUS)
  */
typedef struct {
   __IM uint32_t VERSION;                       /*!< 0x00000000 IP Version */
} M0SECCPUSS_STATUS_Type;                       /*!< Size = 4 (0x4) */


/* M0SECCPUSS_STATUS.VERSION */
#define M0SECCPUSS_STATUS_VERSION_MINOR_Pos     0UL
#define M0SECCPUSS_STATUS_VERSION_MINOR_Msk     0xFFUL
#define M0SECCPUSS_STATUS_VERSION_MAJOR_Pos     8UL
#define M0SECCPUSS_STATUS_VERSION_MAJOR_Msk     0xFF00UL


#endif /* _CYIP_M0SECCPUSS_STATUS_V2_H_ */


/* [] END OF FILE */

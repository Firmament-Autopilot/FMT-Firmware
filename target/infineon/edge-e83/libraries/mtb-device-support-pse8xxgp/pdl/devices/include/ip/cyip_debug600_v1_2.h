/***************************************************************************//**
* DEBUG600 IP definitions
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

#ifndef _CYIP_DEBUG600_V1_2_H_
#define _CYIP_DEBUG600_V1_2_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                   DEBUG600
*******************************************************************************/

#define DEBUG600_SECTION_SIZE                   0x00000100UL

/**
  * \brief DEBUG600
  */
typedef struct {
   __IM uint32_t VERSION;                       /*!< 0x00000000 IP Version Information */
} DEBUG600_Type;                                /*!< Size = 4 (0x4) */


/* DEBUG600.VERSION */
#define DEBUG600_VERSION_MINOR_Pos              0UL
#define DEBUG600_VERSION_MINOR_Msk              0xFFUL
#define DEBUG600_VERSION_MAJOR_Pos              8UL
#define DEBUG600_VERSION_MAJOR_Msk              0xFF00UL


#endif /* _CYIP_DEBUG600_V1_2_H_ */


/* [] END OF FILE */

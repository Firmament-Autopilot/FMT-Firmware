/***************************************************************************//**
* PD IP definitions
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

#ifndef _CYIP_PD_V1_1_H_
#define _CYIP_PD_V1_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                      PD
*******************************************************************************/

#define PD_SECTION_SIZE                         0x00000020UL

/**
  * \brief Power Domain Controller (PD)
  */
typedef struct {
  __IOM uint32_t CTL;                           /*!< 0x00000000 Power Domain Control */
  __IOM uint32_t PWR_UP_DELAY;                  /*!< 0x00000004 Active switch weak enable to active switch strong enable delay */
} PD_Type;                                      /*!< Size = 8 (0x8) */


/* PD.CTL */
#define PD_CTL_BLEED_EN_Pos                     0UL
#define PD_CTL_BLEED_EN_Msk                     0x1UL
/* PD.PWR_UP_DELAY */
#define PD_PWR_UP_DELAY_COUNT_LOAD_Pos          0UL
#define PD_PWR_UP_DELAY_COUNT_LOAD_Msk          0xFFUL
#define PD_PWR_UP_DELAY_MEM_COUNT_LOAD_Pos      8UL
#define PD_PWR_UP_DELAY_MEM_COUNT_LOAD_Msk      0xFF00UL


#endif /* _CYIP_PD_V1_1_H_ */


/* [] END OF FILE */

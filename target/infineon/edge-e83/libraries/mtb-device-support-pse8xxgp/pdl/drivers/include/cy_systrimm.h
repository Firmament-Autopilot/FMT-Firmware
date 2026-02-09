/***************************************************************************//**
* \file cy_systrimm.h
* \version 1.0
*
* \brief
* This file provides declarations for the system trimming for MXS22 platform.
*
********************************************************************************
* \copyright
* Copyright(c) 2023-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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


#if !defined(CY_SYSTRIMM_H)
#define CY_SYSTRIMM_H

#include "cy_device.h"

#if defined (CY_IP_MXS22LPCOMP) || defined (CY_IP_MXS22LPPASS)

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "cy_syslib.h"
#include "cy_rram.h"

#if defined(__cplusplus)
extern "C" {
#endif


/* Trimming macros external */
#define TRIMM_SECTION_SIZE_BYTES                                         (512UL)


/*******************************************************************************
* Function Name: Cy_Trimm_ReadRRAMdata
****************************************************************************//**
*
* Reads the trimming structure from the RRAM.
*
* \param size
* Size of the trimming structure in the RRAM in bytes.
*
* \param data
* Pointer to the structure used to store the trimming data.
*
* \return
* Status of operation
 - FALSE - ERROR
 - TRUE - SUCCESS
*
*******************************************************************************/
bool Cy_Trimm_ReadRRAMdata(uint32_t size, uint32_t * data);


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXS22LPCOMP, CY_IP_MXS22LPPASS */

#endif /** !defined(CY_SYSTRIMM_H) */

/* [] END OF FILE */

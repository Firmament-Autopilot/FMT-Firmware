/*******************************************************************************
* \file cy_systrimm.c
* \version 1.0
*
* \brief
* This file provides definitions for the system trimming for MXS22 platform.
*
********************************************************************************
* \copyright
* Copyright 2023-2025 Cypress Semiconductor Corporation
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

#include "cy_device.h"

#if defined (CY_IP_MXS22LPCOMP) || defined (CY_IP_MXS22LPPASS)

#include "cy_systrimm.h"


/* Trimming macros internal */
#define TRIMM_BASE_ADDR                         (0x13C2B067UL)
#if (CY_CPU_CORTEX_M0P)
#define TRIMM_BASE_ADDR_PUBLIC                  TRIMM_BASE_ADDR
#else
#define TRIMM_BASE_ADDR_PUBLIC                  (TRIMM_BASE_ADDR & ~SECURE_ALIAS_OFFSET)
#endif

#if !((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
#define TRIMM_ITEM_SIZE_BYTES                   (4UL)


/*******************************************************************************
* Function Name: Trimm_CRC32d6a_update
****************************************************************************//**
*
* Updates CRC stage value in the 32-bit CRC calculation.
* (the BootROM is the origin of the CRC calculation approach)
*
* \param crc
* Pointer to the CRC stage value.
*
* \param data
* Update value.
*
*******************************************************************************/
__STATIC_INLINE void Trimm_CRC32d6a_update(uint32_t *crc, uint8_t data)
{
    const uint32_t s = 8UL;
    const uint32_t h = 32UL;
    const uint32_t hs = h - s;
    uint32_t A = (*crc >> hs) ^ data;
    uint32_t B = (A << 18U) ^ (A << 17U) ^ (A << 15U) ^ (A << 14U) ^ A;
    *crc = B ^ (*crc << s);
}


/*******************************************************************************
* Function Name: Trimm_CRC32d6a
****************************************************************************//**
*
* Calculates 32-bit CRC code.
*
* \param data
* Input data for CRC calculation.
*
* \param size
* Size of input data.
*
* \param init
* Initial value for CRC calculation. Should not be 0.
*
* \return
* Calculated 32-bit CRC.
*
*******************************************************************************/
__STATIC_INLINE uint32_t Trimm_CRC32d6a(uint8_t const* data, uint32_t size, uint32_t init)
{
    uint32_t result = init;

    for (uint32_t i = 0U; i < size; ++i)
    {
        Trimm_CRC32d6a_update(&result, data[i]);
    }

    return result;
}
#endif


bool Cy_Trimm_ReadRRAMdata(uint32_t size, uint32_t * data)
{
    bool status = false;

    if ((0UL != size) && (size <= TRIMM_SECTION_SIZE_BYTES) && (NULL != data))
    {
        if (CY_RRAM_SUCCESS == Cy_RRAM_NvmReadByteArray(RRAMC0, TRIMM_BASE_ADDR_PUBLIC, (uint8_t *)data, size))
        {
#if !((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
            /* Get the number of trimming constants (first element of the array) */
            uint32_t numItems = data[0UL];

            /* Get preserved CRC (element immediately after trimming constants in the array) */
            uint32_t crc = data[numItems + 1UL];

            /* Check CRC for array of trimming constants (number of trimming data included in CRC) */
            if (Trimm_CRC32d6a((uint8_t *)data, (numItems + 1U) * TRIMM_ITEM_SIZE_BYTES, TRIMM_BASE_ADDR) == crc)
#endif
            {
                status = true;
            }
        }
    }

    return status;
}


#endif /* CY_IP_MXLPCOMP, CY_IP_MXS22LPPASS */

/* [] END OF FILE */

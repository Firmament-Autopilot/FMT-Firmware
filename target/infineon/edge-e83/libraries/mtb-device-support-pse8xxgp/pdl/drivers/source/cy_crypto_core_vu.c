/***************************************************************************//**
* \file cy_crypto_core_vu.c
* \version 2.150
*
* \brief
*  This file provides the source code to the API for the Vector Unit helpers
*  in the Crypto driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2020-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"

#if defined (CY_IP_MXCRYPTO)

#include "cy_crypto_core_vu.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_VU == 1)

#include "cy_crypto_core_mem.h"
#include "cy_syslib.h"

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 4, \
'CRYPTO_Type will typecast to either CRYPTO_V1_Type or CRYPTO_V2_Type but not both on PDL initialization based on the target device at compile time.')
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 14.3', 4, \
'Since value of CY_CRYPTO_V1 is decided by PDL device agnostic / hardware specific model, controlling expression will not have an invariant value.')

#if !defined (CY_CRYPTO_SERVICE_LIBRARY_LEVEL)
    #define CY_CRYPTO_SERVICE_LIBRARY_LEVEL CY_CRYPTO_FULL_LIBRARY
#endif

void Cy_Crypto_Core_Vu_SetMemValue(CRYPTO_Type *base, uint32_t dstReg, uint8_t const *src, uint32_t size)
{
    uint32_t reg0_data = 0uL;
    uint32_t reg1_data = 0uL;
    uint8_t *srcRemap;

    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);

    Cy_Crypto_Core_Vu_WaitForComplete(base);

    if (CY_CRYPTO_V1)
    {
        CY_CRYPTO_VU_SAVE_REG(base, CY_CRYPTO_VU_HW_REG0, &reg0_data);
        CY_CRYPTO_VU_SAVE_REG(base, CY_CRYPTO_VU_HW_REG1, &reg1_data);
    }

    /* Copy value to Crypto SRAM */
    uint16_t byteSize = (uint16_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(size);
    uint32_t destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, dstReg);

    CY_ASSERT_L1(size <= Cy_Crypto_Core_Vu_RegBitSizeRead(base, dstReg));
    CY_ASSERT_L1( ((destAddr + byteSize) - 1u) < ((uint32_t)Cy_Crypto_Core_GetVuMemoryAddress(base) + Cy_Crypto_Core_GetVuMemorySize(base)));

    Cy_Crypto_Core_MemSet(base, (void*)destAddr, 0u, (uint16_t)CY_CRYPTO_WORD_SIZE_OF_BITS(size) * 4u);
    Cy_Crypto_Core_MemCpy(base, (void*)destAddr, (const void*)srcRemap, byteSize);

    if (CY_CRYPTO_V1)
    {
        CY_CRYPTO_VU_RESTORE_REG(base, CY_CRYPTO_VU_HW_REG0, reg0_data);
        CY_CRYPTO_VU_RESTORE_REG(base, CY_CRYPTO_VU_HW_REG1, reg1_data);
    }
}

void Cy_Crypto_Core_Vu_GetMemValue(CRYPTO_Type *base, uint8_t *dst, uint32_t srcReg, uint32_t size)
{
    uint32_t reg0_data = 0uL;
    uint32_t reg1_data = 0uL;
    uint8_t *dstRemap;
    dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);

    Cy_Crypto_Core_Vu_WaitForComplete(base);

    if (CY_CRYPTO_V1)
    {
        CY_CRYPTO_VU_SAVE_REG(base, CY_CRYPTO_VU_HW_REG0, &reg0_data);
        CY_CRYPTO_VU_SAVE_REG(base, CY_CRYPTO_VU_HW_REG1, &reg1_data);
    }

    /* Copy value from Crypto SRAM */
    uint16_t byteSize = (uint16_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(size);
    uint32_t dataAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, srcReg);

    CY_ASSERT_L1(size <= Cy_Crypto_Core_Vu_RegBitSizeRead(base, srcReg));
    CY_ASSERT_L1( ((dataAddr + byteSize) - 1u) < ((uint32_t)Cy_Crypto_Core_GetVuMemoryAddress(base) + Cy_Crypto_Core_GetVuMemorySize(base)));

    Cy_Crypto_Core_MemCpy(base, (void*)dstRemap, (void*)dataAddr, byteSize);

    if (CY_CRYPTO_V1)
    {
        CY_CRYPTO_VU_RESTORE_REG(base, CY_CRYPTO_VU_HW_REG0, reg0_data);
        CY_CRYPTO_VU_RESTORE_REG(base, CY_CRYPTO_VU_HW_REG1, reg1_data);
    }
}

bool Cy_Crypto_Core_Vu_IsRegZero(CRYPTO_Type *base, uint32_t srcReg)
{
    bool tmpResult;
    uint32_t status;

    CY_CRYPTO_VU_TST(base, srcReg);
    status = Cy_Crypto_Core_Vu_StatusRead(base);

    if (0u != (status & CY_CRYPTO_VU_STATUS_ZERO_BIT))
    {
        tmpResult = true;
    }
    else
    {
        tmpResult = false;
    }

    return tmpResult;
}

bool Cy_Crypto_Core_Vu_IsRegEqual(CRYPTO_Type *base, uint32_t srcReg0, uint32_t srcReg1)
{
    bool tmpResult;
    uint32_t status;

    CY_CRYPTO_VU_CMP_SUB (base, srcReg1, srcReg0);                /* C = (a >= b) */
    status = Cy_Crypto_Core_Vu_StatusRead(base);

    if (0u != (status &  CY_CRYPTO_VU_STATUS_ZERO_BIT))
    {
        tmpResult = true;
    }
    else
    {
        tmpResult = false;
    }

    return tmpResult;
}

bool Cy_Crypto_Core_Vu_IsRegLess(CRYPTO_Type *base, uint32_t srcReg0, uint32_t srcReg1)
{
    bool tmpResult;
    uint32_t status;

    CY_CRYPTO_VU_CMP_SUB (base, srcReg1, srcReg0);                /* C = (a >= b) */
    status = Cy_Crypto_Core_Vu_StatusRead(base);

    if (0u != (status &  CY_CRYPTO_VU_STATUS_CARRY_BIT))
    {
        tmpResult = true;
    }
    else
    {
        tmpResult = false;
    }

    return tmpResult;
}

void Cy_Crypto_Core_VU_RegInvertEndianness(CRYPTO_Type *base, uint32_t srcReg)
{
    uint32_t  byteSize = CY_CRYPTO_BYTE_SIZE_OF_BITS(Cy_Crypto_Core_Vu_RegBitSizeRead(base, srcReg));
#if (CY_CPU_CORTEX_M55)
    uint32_t *dataAddr = (uint32_t *)CY_REMAP_ADDRESS_FOR_CPU(Cy_Crypto_Core_Vu_RegMemPointer(base, srcReg));
#else
    uint32_t *dataAddr = Cy_Crypto_Core_Vu_RegMemPointer(base, srcReg);
#endif
    Cy_Crypto_Core_InvertEndianness(dataAddr, byteSize);
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 14.3')
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')

#endif /* #if (CPUSS_CRYPTO_VU == 1) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */


/* [] END OF FILE */

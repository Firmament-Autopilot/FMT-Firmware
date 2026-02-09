/***************************************************************************//**
* \file cy_crypto_core_aes_v2.c
* \version 2.150
*
* \brief
*  This file provides the source code fro the API for the AES method
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

#if defined(CY_IP_MXCRYPTO)

#include "cy_crypto_core_aes_v2.h"

#if defined(CY_CRYPTO_CFG_HW_V2_ENABLE)

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_AES_C)

#include "cy_crypto_core_hw_v2.h"
#include "cy_crypto_core_mem_v2.h"
#include "cy_syslib.h"
#include <string.h>

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.3', 18, \
'Intentional Pointer Type Conversion')

#define CY_CRYPTO_IS_KEYLENGTH_VALID(keyLength) ((CY_CRYPTO_KEY_AES_128 == (keyLength)) || \
                                                 (CY_CRYPTO_KEY_AES_192 == (keyLength)) || \
                                                 (CY_CRYPTO_KEY_AES_256 == (keyLength)))



#if defined(CY_CRYPTO_CFG_CCM_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Init
****************************************************************************//*
*
* Performs an AES CCM Init operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesCcmBuffer The buffers should be a SAHB mapped addresses.
* The pointer to the memory buffers storage.
*
* \param aesState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Init(CRYPTO_Type *base,
                                            cy_stc_crypto_aes_ccm_buffers_t * aesCcmBuffer, cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmBuffer) || (NULL == aesCcmState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    Cy_Crypto_Core_V2_MemSet(base, (void *)aesCcmBuffer, 0u, (uint16_t)sizeof(cy_stc_crypto_aes_ccm_buffers_t));
    Cy_Crypto_Core_V2_MemSet(base, (void *)aesCcmState, 0u, (uint16_t)sizeof(cy_stc_crypto_aes_ccm_state_t));

    aesCcmState->aesCbcMacState.buffers = &aesCcmBuffer->aesCbcMacBuffer;
    aesCcmState->aesCtrState.buffers = &aesCcmBuffer->aesCtrBuffer;
    aesCcmState->temp = aesCcmBuffer->temp_buffer;
    aesCcmState->ctr = aesCcmBuffer->ctr;
    aesCcmState->y = aesCcmBuffer->y;

    return CY_CRYPTO_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_SetKey
****************************************************************************//*
*
* Sets AES CCM Key for the operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param key
* The pointer to the CCM key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_SetKey(CRYPTO_Type *base,
                                            uint8_t const *key, cy_en_crypto_aes_key_length_t keyLength,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == key) || (NULL == aesCcmState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }
    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_CleanDCache_by_Addr((volatile void *)key,(int32_t)((int32_t)CY_CRYPTO_AES_128_KEY_SIZE+((int32_t)8*(int32_t)keyLength)));
    #endif

    // Sets the AES Key for the CBC MAC operation
    status = Cy_Crypto_Core_V2_Aes_Init(base, key, keyLength, &aesCcmState->aesCbcMacState, aesCcmState->aesCbcMacState.buffers);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    // Sets the AES Key for the CTR operation
    status = Cy_Crypto_Core_V2_Aes_Init(base, key, keyLength, &aesCcmState->aesCtrState, aesCcmState->aesCtrState.buffers);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    return CY_CRYPTO_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Initial_Block
****************************************************************************//*
*
*  Performs the Initial CCM calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
static cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Initial_Block(CRYPTO_Type *base,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint32_t size_left = 0u;

    if(aesCcmState->isIvSet == false || aesCcmState->isLengthSet == false)
    {
        return CY_CRYPTO_SUCCESS;
    }

    status = Cy_Crypto_Core_V2_Aes_CbcMac_Setup(base, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    aesCcmState->y[0] |= (uint8_t)(aesCcmState->aadLength > 0u) << 6u;
    aesCcmState->y[0] |= ((aesCcmState->tagLength - 2u) / 2u) << 3u;
    aesCcmState->y[0] |= (uint8_t)aesCcmState->L - 1u;

    size_left = aesCcmState->textLength;
    for (uint32_t i = 0u; i < aesCcmState->L; i++)
    {
        aesCcmState->y[15u - i] = (uint8_t)size_left & 0xffu ;
         size_left >>= 8u;
    }

    __DSB();
    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_CleanDCache_by_Addr((volatile void*)aesCcmState->y,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif
    // Performs the CBC MAC update operation for the Initial Block data formatted with flags and length
    status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base, CY_CRYPTO_AES_BLOCK_SIZE, aesCcmState->y, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    if (aesCcmState->aadLength > 0u)
    {
        aesCcmState->temp[0] = (uint8_t)(aesCcmState->aadLength >> 8u) & 0xffu;
        aesCcmState->temp[1] = (uint8_t)(aesCcmState->aadLength & 0xffu);
        __DSB();
    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_CleanDCache_by_Addr((volatile void*)aesCcmState->temp,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif

        status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base, 2u, aesCcmState->temp, &aesCcmState->aesCbcMacState);

        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }

        aesCcmState->aadLengthProcessed += 2u;
    }

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Set_Length
****************************************************************************//*
*
* Sets the length for Additional authentication data, plain text and Tag for AES CCM operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aadSize
* The Size of the Additional Authentication Data.
*
* \param textSize
* The Size of the Text.
*
* \param tagLength
* The Size of the Tag.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Set_Length(CRYPTO_Type *base,
                                            uint32_t aadSize,  uint32_t textSize, uint32_t tagLength,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (tagLength < 3u || tagLength > CY_CRYPTO_AES_BLOCK_SIZE || (tagLength % 2u != 0u))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if( aadSize >= 0xFF00UL )
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    aesCcmState->textLength = textSize;
    aesCcmState->aadLength = aadSize;
    aesCcmState->tagLength = (uint8_t)tagLength;
    aesCcmState->aadLengthProcessed = 0u;
    aesCcmState->isAadProcessed = false;
    aesCcmState->isLengthSet = true;

    return Cy_Crypto_Core_V2_Aes_Ccm_Initial_Block(base, aesCcmState);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Start
****************************************************************************//*
*
* Function to set IV for the AES CCM operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Start(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                             uint32_t ivSize, uint8_t const * iv,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == iv) || (NULL == aesCcmState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if (ivSize < 7u || ivSize > 13u)
    {
        return status;
    }

    aesCcmState->dirMode = dirMode;
    aesCcmState->L = CY_CRYPTO_AES_BLOCK_SIZE - ivSize - 1u;
    aesCcmState->isIvSet = true;

    Cy_Crypto_Core_V2_MemSet(base, aesCcmState->ctr, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
    aesCcmState->ctr[0] = (uint8_t)aesCcmState->L - 1u;
    aesCcmState->ctr[15] = 1u;

    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_CleanDCache_by_Addr((volatile void*)aesCcmState->ctr,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif
    __DSB();

    Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesCcmState->ctr[1], (void*)iv, (uint16_t)ivSize);

    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr((volatile void *)aesCcmState->ctr, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif
    Cy_Crypto_Core_V2_MemSet(base, aesCcmState->y, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesCcmState->y[1], (void*)iv, (uint16_t)ivSize);

    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr((volatile void *)aesCcmState->y, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif
    // Sets the IV for the AES CTR operation
    status = Cy_Crypto_Core_V2_Aes_Ctr_Setup(base, &aesCcmState->aesCtrState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Aes_Ctr_Set_IV(base, aesCcmState->ctr, &aesCcmState->aesCtrState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    return Cy_Crypto_Core_V2_Aes_Ccm_Initial_Block(base, aesCcmState);
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Update_Aad
****************************************************************************//*
*
* Performs an AES CCM update AAD Multistage  operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Update_Aad(CRYPTO_Type *base,
                                            uint32_t aadSize,
                                            uint8_t const *aad,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)


{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;

    if(0u == aadSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

    if( aadSize >= 0xFF00UL )
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState) || (NULL == aad))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base, aadSize, aad, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    aesCcmState->aadLengthProcessed += aadSize;

    return status;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Update
****************************************************************************//*
*
* Performs an AES CCM Update Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination block.
*
* \param src
* The pointer to a source block.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Update(CRYPTO_Type *base,
                                            uint32_t srcSize,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)


{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t *temp = NULL;
    uint8_t *cipherText_ptr;

    if(0u == srcSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState) || (NULL == dst) || (NULL == src))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    temp = aesCcmState->temp;

    Cy_Crypto_Core_V2_MemSet(base, temp, 0u, CY_CRYPTO_AES_BLOCK_SIZE);

    if( aesCcmState->aadLengthProcessed % CY_CRYPTO_AES_BLOCK_SIZE != 0u && aesCcmState->isAadProcessed == false)
    {
        status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base,  CY_CRYPTO_AES_BLOCK_SIZE - aesCcmState->aadLengthProcessed % CY_CRYPTO_AES_BLOCK_SIZE, temp, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }

        aesCcmState->isAadProcessed = true;
    }

    if(aesCcmState->dirMode == CY_CRYPTO_ENCRYPT)
    {
        cipherText_ptr = (uint8_t *)src;

        status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base, srcSize, cipherText_ptr, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }
        status =  Cy_Crypto_Core_V2_Aes_Ctr_Update(base, srcSize, dst, src, &aesCcmState->aesCtrState);
    }
    else
    {
        status =  Cy_Crypto_Core_V2_Aes_Ctr_Update(base, srcSize, dst, src, &aesCcmState->aesCtrState);

        cipherText_ptr = dst;
        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }
        status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base, srcSize, cipherText_ptr, &aesCcmState->aesCbcMacState);
    }

    return status;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Finish
****************************************************************************//*
*
* Performs an AES CCM finish operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param tag
* The pointer to the CCM Tag.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Finish(CRYPTO_Type *base, uint8_t *tag, cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{
    uint8_t *temp = NULL;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    uint8_t y_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0u};
    uint8_t *y = (uint8_t*)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(y_t);
#else
    uint8_t y[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)] = {0u};
#endif
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesCcmState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    temp = aesCcmState->temp;

    Cy_Crypto_Core_V2_MemSet(base, temp, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_MemSet(base, y, 0u, CY_CRYPTO_AES_BLOCK_SIZE);

    if( aesCcmState->aadLengthProcessed % CY_CRYPTO_AES_BLOCK_SIZE != 0u && aesCcmState->isAadProcessed == false)
    {
        status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base,  CY_CRYPTO_AES_BLOCK_SIZE - aesCcmState->aadLengthProcessed % CY_CRYPTO_AES_BLOCK_SIZE, temp, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }
    }

    if (aesCcmState->textLength % CY_CRYPTO_AES_BLOCK_SIZE  != 0u)
    {
        status = Cy_Crypto_Core_V2_Aes_CbcMac_Update(base, CY_CRYPTO_AES_BLOCK_SIZE - aesCcmState->textLength % CY_CRYPTO_AES_BLOCK_SIZE, temp, &aesCcmState->aesCbcMacState);
        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }
    }

    status = Cy_Crypto_Core_V2_Aes_CbcMac_Finish(base, temp, &aesCcmState->aesCbcMacState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    for (uint32_t i = 0u; i < aesCcmState->L; i++)
    {
        aesCcmState->aesCtrState.buffers->iv[15u-i] = 0u;
    }

    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_CleanDCache_by_Addr((volatile void *)aesCcmState->aesCtrState.buffers->iv, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif
    aesCcmState->aesCtrState.unProcessedBytes = 0u;

    status = Cy_Crypto_Core_V2_Aes_Ctr_Update(base, CY_CRYPTO_AES_BLOCK_SIZE,
                                            y,
                                            temp,
                                            &aesCcmState->aesCtrState);

    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    Cy_Crypto_Core_V2_MemCpy(base, (void*)tag, (void*)y, aesCcmState->tagLength);
    Cy_Crypto_Core_V2_MemSet(base, aesCcmState->ctr, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_MemSet(base, aesCcmState->y, 0u, CY_CRYPTO_AES_BLOCK_SIZE);

    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr((volatile void *)tag, (int32_t)aesCcmState->tagLength);
        SCB_InvalidateDCache_by_Addr((volatile void *)aesCcmState->ctr, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
        SCB_InvalidateDCache_by_Addr((volatile void *)aesCcmState->y, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif
    aesCcmState->isIvSet = false;
    aesCcmState->isAadProcessed = false;

    return status;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm
****************************************************************************//*
*
* Performs an AES CCM operation.
* \note Cy_Crypto_Core_V2_Aes_Ccm_Init() and Cy_Crypto_Core_V2_Aes_Ccm_SetKey() should be called before calling this function.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination block.
*
* \param src
* The pointer to a source block.
*
* \param tagSize
* The size of the Tag.
*
* \param tag
* The pointer to the tags.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
static cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                            uint32_t ivSize, uint8_t const * iv,
                                            uint32_t aadSize, uint8_t const *aad,
                                            uint32_t srcSize, uint8_t *dst, uint8_t const *src,
                                            uint32_t tagSize, uint8_t *tag,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)

{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;

     /* Input parameters verification */
    if ((NULL == base) || ((NULL == iv) && (ivSize > 0u)) || ((NULL == aad) && (aadSize > 0u)) ||
     ((srcSize > 0u) && ((NULL == dst) || (NULL == src)))|| (NULL == aesCcmState) || (NULL == tag))
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Aes_Ccm_Set_Length(base, aadSize,  srcSize, tagSize, aesCcmState);

    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Aes_Ccm_Start(base, dirMode, ivSize, iv, aesCcmState);

    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Aes_Ccm_Update_Aad(base, aadSize, aad, aesCcmState);

    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Aes_Ccm_Update(base, srcSize, dst, src, aesCcmState);

    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Aes_Ccm_Finish(base, tag, aesCcmState);

    return status;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Encrypt_Tag
****************************************************************************//*
*
* Performs an AES CCM Encrypt operation.
* \note Cy_Crypto_Core_V2_Aes_Ccm_Init() and Cy_Crypto_Core_V2_Aes_Ccm_SetKey() should be called before calling this function
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param srcSize
* The size of the source block.
*
* \param cipherTxt
* The pointer to a cipher text block.
*
* \param plainTxt
* The pointer to a plain text block.
*
* \param tagSize
* The size of the Tag.
*
* \param tag
* The pointer to the tags.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Encrypt_Tag(CRYPTO_Type *base,
                                            uint32_t ivSize, uint8_t const * iv,
                                            uint32_t aadSize, uint8_t const *aad,
                                            uint32_t srcSize, uint8_t *cipherTxt, uint8_t const *plainTxt,
                                            uint32_t tagSize, uint8_t *tag,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)

{

return Cy_Crypto_Core_V2_Aes_Ccm(base, CY_CRYPTO_ENCRYPT, ivSize, iv, aadSize, aad,
                                             srcSize, cipherTxt, plainTxt, tagSize, tag,
                                            aesCcmState);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Decrypt
****************************************************************************//*
*
* Performs an AES CCM Decrypt operation.
* \note Cy_Crypto_Core_V2_Aes_Ccm_Init() and Cy_Crypto_Core_V2_Aes_Ccm_SetKey() should be called before calling this function
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param ivSize
* The size of the IV.
*
* \param iv
* The pointer to the IV.
*
* \param aadSize
* The size of the AAD.
*
* \param aad
* The pointer to a AAD.
*
* \param srcSize
* The size of the source block.
*
* \param plainTxt
* The pointer to a plain text block.
*
* \param cipherTxt
* The pointer to a cipher text block.
*
* \param tagSize
* The size of the Tag.
*
* \param tag
* The pointer to the tags.
*
* \param isValid
* The pointer Store the authentication status.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Decrypt(CRYPTO_Type *base,
                                            uint32_t ivSize, uint8_t const * iv,
                                            uint32_t aadSize, uint8_t const *aad,
                                            uint32_t srcSize, uint8_t *plainTxt, uint8_t const *cipherTxt,
                                            uint32_t tagSize, uint8_t const *tag, cy_en_crypto_aesccm_tag_verify_result_t *isValid,
                                            cy_stc_crypto_aes_ccm_state_t *aesCcmState)

{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t TagCal_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0u};
    uint8_t *TagCal = (uint8_t*)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(TagCal_t);
    *isValid = CY_CRYPTO_CCM_TAG_INVALID;

    status = Cy_Crypto_Core_V2_Aes_Ccm(base, CY_CRYPTO_DECRYPT, ivSize, iv, aadSize, aad,
                                                srcSize, (uint8_t *)plainTxt, cipherTxt, tagSize, TagCal,
                                                aesCcmState);
    if(CY_CRYPTO_SUCCESS != status)
    {
        return status;
    }

    if(Cy_Crypto_Core_V2_MemCmp(base, tag, TagCal, (uint16_t)tagSize) == 0u)
    {
        *isValid = CY_CRYPTO_CCM_TAG_VALID;
    }

    return CY_CRYPTO_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ccm_Free
****************************************************************************//*
*
* Clears AES CCM operation context.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesCcmState
* The pointer to the AES CCM state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ccm_Free(CRYPTO_Type *base, cy_stc_crypto_aes_ccm_state_t *aesCcmState)
{
    if((NULL != base) && (NULL != aesCcmState))
    {
       if(NULL != aesCcmState->aesCbcMacState.buffers)
       {
            Cy_Crypto_Core_V2_MemSet(base, (void *)aesCcmState->aesCbcMacState.buffers, 0u, (uint16_t)sizeof(cy_stc_crypto_aes_buffers_t));
       }
       if(NULL != aesCcmState->aesCtrState.buffers)
       {
           Cy_Crypto_Core_V2_MemSet(base, (void *)aesCcmState->aesCtrState.buffers, 0u, (uint16_t)sizeof(cy_stc_crypto_aes_buffers_t));
       }
       Cy_Crypto_Core_V2_MemSet(base, (void *)aesCcmState, 0u, (uint16_t)sizeof(cy_stc_crypto_aes_ccm_state_t));
    }

    return CY_CRYPTO_SUCCESS;
}

#endif /* CY_CRYPTO_CFG_CCM_C */

#if (CPUSS_CRYPTO_GCM == 1) && defined(CY_CRYPTO_CFG_GCM_C)

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

/*******************************************************************************
* Function Name: Cy_Crypto_Aes_GCM_Increment_counter
****************************************************************************//**
*
* The function to increase the counter.
*
* \param counter_block
* The pointer to the counter to increase.
*******************************************************************************/

static void Cy_Crypto_Aes_GCM_Increment_counter(uint8_t * counter_block)
{
    uint32_t i;

    for (i=0U; i < 4U; i++)
    {
        if (++(counter_block[15U - i]) != 0U)
        {
            break;
        }
    }

}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Ghash
****************************************************************************//**
*
* The function to perform the GHASH multiplication operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param h
* The pointer to the Hash Subkey.
*
* \param input
* The pointer to the input data for ghash.
*
* \param length
* The length of the input data.
*
* \param y
* The pointer holding the current hash value and it gets updated after the ghash multiplication.

*******************************************************************************/
static void Cy_Crypto_Core_V2_Aes_GCM_Ghash(CRYPTO_Type *base, uint8_t *h,  const uint8_t *input, uint32_t length, uint8_t *y)

{
    uint32_t load_length;
    static const uint8_t p_padding[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_CleanDCache_by_Addr((volatile void*)h,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    SCB_CleanDCache_by_Addr((volatile void*)input,(int32_t)length);
    SCB_CleanDCache_by_Addr((volatile void*)y,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif
    // Load the Hash Sub Key H
    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, h, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov_Reflect(base, CY_CRYPTO_V2_RB_BLOCK3, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_Sync(base);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, y, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov_Reflect(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_Sync(base);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, input, length);

    while (length != 0U)
    {
        load_length = MIN (length, CY_CRYPTO_AES_BLOCK_SIZE);

        // Padding for the last block if the length is not AES Block size
        if (load_length < CY_CRYPTO_AES_BLOCK_SIZE)
        {
             Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, (const uint8_t*)CY_REMAP_ADDRESS_FOR_CRYPTO(p_padding) , CY_CRYPTO_AES_BLOCK_SIZE-load_length);
        }

        input  += load_length;
        length   -= load_length;

        Cy_Crypto_Core_V2_BlockMov_Reflect(base, CY_CRYPTO_V2_RB_BLOCK2, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_BLOCK2, CY_CRYPTO_AES_BLOCK_SIZE);

        // Perform the AES GHASH operation
        Cy_Crypto_Core_V2_BlockGcm(base);
   }

    // Store the calculated output value to Y
    Cy_Crypto_Core_V2_BlockMov_Reflect(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, y, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_RBStore(base, CY_CRYPTO_AES_BLOCK_SIZE, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_FFStoreSync(base);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr((volatile void*)y,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Init
****************************************************************************//**
*
* The function to initialize AES GCM operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesGCMBuffers
* The pointer to the AES GCM memory buffers storage.
*
* \param aesGCMctx
* The pointer to the AES GCM structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Init(CRYPTO_Type *base, cy_stc_crypto_aes_gcm_buffers_t *aesGCMBuffers, cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    cy_stc_crypto_aes_gcm_buffers_t *aesGCMBuffersRemap;
    if((NULL != base) && (NULL != aesGCMBuffers) && (NULL != aesGCMctx))
    {
        aesGCMBuffersRemap = (cy_stc_crypto_aes_gcm_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMBuffers);

        Cy_Crypto_Core_V2_MemSet(base, aesGCMctx, 0U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_state_t));
        Cy_Crypto_Core_V2_MemSet(base, aesGCMBuffersRemap, 0U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_buffers_t));

        aesGCMctx->h = aesGCMBuffers->h;
        aesGCMctx->icb = aesGCMBuffers->icb;
        aesGCMctx->cb = aesGCMBuffers->cb;
        aesGCMctx->y = aesGCMBuffers->y;
        aesGCMctx->temp = aesGCMBuffers->temp;
        aesGCMctx->aes_data = aesGCMBuffers->aes_data;
        aesGCMctx->aes_buffer = &aesGCMBuffers->aes_buffer;

        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Setkey
****************************************************************************//**
*
* The function to set AES GCM Key.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aes_key
* The pointer to the AES key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param aesGCMctx
* The pointer to the AES GCM structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_SetKey(CRYPTO_Type *base, uint8_t const *aesKey, cy_en_crypto_aes_key_length_t keyLength, cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *keyRemap;
    uint8_t *hRemap;
    cy_stc_crypto_aes_buffers_t *aesBuffersRemap;

    if((NULL != base) && (NULL != aesKey) && (NULL != aesGCMctx) && (NULL != aesGCMctx->aes_buffer))
    {
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)aesKey,(int32_t)((int32_t)CY_CRYPTO_AES_128_KEY_SIZE+((int32_t)8*(int32_t)keyLength)));
#endif

        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesKey);
        hRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->h);
        aesBuffersRemap = (cy_stc_crypto_aes_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->aes_buffer);

        tmpResult = Cy_Crypto_Core_V2_Aes_Init(base, keyRemap, keyLength, &aesGCMctx->aesState,aesBuffersRemap);

        if(CY_CRYPTO_SUCCESS == tmpResult)
        {
            Cy_Crypto_Core_V2_MemSet(base, hRemap, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
            tmpResult = Cy_Crypto_Core_V2_Aes_Ecb(base, CY_CRYPTO_ENCRYPT, hRemap, hRemap, &aesGCMctx->aesState);
        }
    }

    return tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Start
****************************************************************************//**
*
* The function to Start AES GCM operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param mode
* mode of operation encrypt/decrypt
*
* \param iv
* The pointer to the Initialization vector.
*
* \param ivSize
* The length of the iv.
*
* \param aesGCMctx
* The pointer to the AES GCM structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Start(CRYPTO_Type *base, cy_en_crypto_dir_mode_t mode, uint8_t const *iv, uint32_t ivSize, cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    uint8_t ivBitlen_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(uint64_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint64_t *ivBitlen = (uint64_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(ivBitlen_t);
    uint8_t temp_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0u};
    uint8_t *temp = (uint8_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(temp_t);
#else
    uint64_t ivBitlen_t;
    uint64_t *ivBitlen = &ivBitlen_t;
    uint8_t temp[CY_CRYPTO_AES_BLOCK_SIZE] = {0u};
#endif
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *ivRemap;
    uint8_t *icbRemap;
    uint8_t *yRemap;
    uint8_t *tempRemap;
    uint8_t *hRemap;
    uint8_t *cbRemap;

    if((NULL != base) && ((NULL != iv) && ivSize >0U) && (NULL != aesGCMctx) && (NULL != aesGCMctx->aes_buffer))
    {

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)iv,(int32_t)ivSize);
#endif

        ivRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(iv);
        icbRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->icb);
        yRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->y);
        tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->temp);
        hRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->h);
        cbRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->cb);

        aesGCMctx->mode = mode;
        Cy_Crypto_Core_V2_MemSet(base, icbRemap, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_MemSet(base, yRemap, 0u, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_MemSet(base, tempRemap, 0u, CY_CRYPTO_AES_BLOCK_SIZE);

        aesGCMctx->data_size = 0u;
        aesGCMctx->aad_size = 0u;
        aesGCMctx->partial_aad_processed = false;

        if(CY_CRYPTO_AES_GCM_IV_SIZE == ivSize)
        {
            Cy_Crypto_Core_V2_MemCpy(base, (void*)icbRemap, (void*)ivRemap, (uint16_t)ivSize);
            aesGCMctx->icb[15U] = 1U;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)aesGCMctx->icb,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif
            __DSB();

        }

        else
        {
            ivBitlen[0] = (uint64_t)ivSize << 3U;
            ivBitlen[0] = CY_SWAP_ENDIAN64(ivBitlen[0]);

            Cy_Crypto_Core_V2_MemSet(base, CY_REMAP_ADDRESS_FOR_CRYPTO(temp), 0u, CY_CRYPTO_AES_BLOCK_SIZE);
            Cy_Crypto_Core_V2_MemCpy(base, CY_REMAP_ADDRESS_FOR_CRYPTO(&temp[8U]), (void*)ivBitlen, 8U);

            Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, ivRemap, ivSize, icbRemap);
            Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, CY_REMAP_ADDRESS_FOR_CRYPTO(temp), CY_CRYPTO_AES_BLOCK_SIZE, icbRemap);
        }

        Cy_Crypto_Core_V2_MemCpy(base, (void*)cbRemap,  (void*)icbRemap, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Aes_GCM_Increment_counter(aesGCMctx->cb);
        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_AAD_Update
****************************************************************************//**
*
* The function to update the Additional Authentication Data.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aad
* The pointer to the Additional Authentication Data.
*
* \param aadSize
*  The length of the additional Authentication Data
*
* \param aesGCMctx
* The pointer to the AES aesGCMctx structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_AAD_Update(CRYPTO_Type *base,  uint8_t *aad,   uint32_t aadSize, cy_stc_crypto_aes_gcm_state_t* aesGCMctx)

{
    uint32_t rem_add_size;
    uint32_t copy_size;
    uint32_t block_count;
    uint8_t* aadRemap ;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *hRemap;
    uint8_t *yRemap;
    uint8_t *tempRemap;

    if(0u == aadSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

    if((NULL != base) && (NULL != aad) && (NULL != aesGCMctx))
    {

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)aad,(int32_t)aadSize);
#endif
        aadRemap =  (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aad);

        hRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->h);
        yRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->y);
        tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->temp);

        rem_add_size = aesGCMctx->aad_size % CY_CRYPTO_AES_BLOCK_SIZE;

        if(rem_add_size + aadSize < CY_CRYPTO_AES_BLOCK_SIZE)
        {
            Cy_Crypto_Core_V2_MemCpy(base, (void*)&tempRemap[rem_add_size], (void*)aadRemap, (uint16_t)aadSize);
            aesGCMctx->aad_size += aadSize;
        }

        else
        {
            copy_size = CY_CRYPTO_AES_BLOCK_SIZE - rem_add_size;
            Cy_Crypto_Core_V2_MemCpy(base, (void*)&tempRemap[rem_add_size], (void*)aadRemap, (uint16_t)copy_size);
            aesGCMctx->aad_size += copy_size;
            aadSize -=  copy_size;
            aadRemap += copy_size;

            Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE, yRemap);
            block_count = aadSize/CY_CRYPTO_AES_BLOCK_SIZE;
            Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, aadRemap, block_count * CY_CRYPTO_AES_BLOCK_SIZE, yRemap);
            aadRemap += block_count *CY_CRYPTO_AES_BLOCK_SIZE;
            Cy_Crypto_Core_V2_MemCpy(base, (void*)tempRemap, (void*)aadRemap, (uint16_t)(aadSize % CY_CRYPTO_AES_BLOCK_SIZE));
            aesGCMctx->aad_size +=  block_count *CY_CRYPTO_AES_BLOCK_SIZE + aadSize % CY_CRYPTO_AES_BLOCK_SIZE;
        }

        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Update
****************************************************************************//**
*
* The function to update the data
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param input
* The pointer to the input data to be encrypted/decrypted.
*
* \param inputSize
*  The length of the input data.
*
* \param output
* The pointer to the encrypted/decrypted output data.
*
* \param aesGCMctx
* The pointer to the AES aesGCMctx structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Update(CRYPTO_Type *base, uint8_t const *input,   uint32_t inputSize,  uint8_t *output,
                                                         cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{

    uint32_t process_size;
    uint32_t index=0, i=0;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t temp[CY_CRYPTO_AES_BLOCK_SIZE];
    uint8_t *hRemap;
    uint8_t *yRemap;
    uint8_t *tempRemap;
    uint8_t *aesdataRemap;
    uint8_t *cbRemap;

    if(0u ==inputSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

    if((NULL != base) && (NULL != input)  && (NULL != output) &&  (NULL != aesGCMctx))
    {

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)input,(int32_t)inputSize);
#endif

        hRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->h);
        yRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->y);
        tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->temp);
        aesdataRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->aes_data);
        cbRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->cb);

        if(aesGCMctx->aad_size %CY_CRYPTO_AES_BLOCK_SIZE != 0u)
        {
            if(aesGCMctx->partial_aad_processed == false)
            {
                Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, tempRemap, aesGCMctx->aad_size%CY_CRYPTO_AES_BLOCK_SIZE , yRemap);
                aesGCMctx->partial_aad_processed = true;
            }
        }

        while(inputSize != 0u)
        {
            if(aesGCMctx->data_size % CY_CRYPTO_AES_BLOCK_SIZE == 0u)
            {
                (void)Cy_Crypto_Core_V2_Aes_Ecb(base, CY_CRYPTO_ENCRYPT,  aesdataRemap, cbRemap, &aesGCMctx->aesState);
                Cy_Crypto_Aes_GCM_Increment_counter(aesGCMctx->cb);
            }
            if(aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE + inputSize < CY_CRYPTO_AES_BLOCK_SIZE)
            {
                process_size =  aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE + inputSize;
            }

            else
            {
                process_size =  CY_CRYPTO_AES_BLOCK_SIZE;
            }

            for (i=aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE; i< process_size  ; i++)
            {
                temp[i] = aesGCMctx->aes_data[i] ^ input[index];

                if(CY_CRYPTO_ENCRYPT == aesGCMctx->mode)
                {
                    output[index] = temp[i];
                    aesGCMctx->aes_data[i] = output[index];
                }
                else
                {
                    aesGCMctx->aes_data[i] = input[index];
                    output[index] = temp[i];
                }

                index++;
            }

            inputSize -= process_size - aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE;
            aesGCMctx->data_size += process_size - aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE;

            if (aesGCMctx->data_size % CY_CRYPTO_AES_BLOCK_SIZE == 0u)
            {
                Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, aesdataRemap, CY_CRYPTO_AES_BLOCK_SIZE , yRemap);
            }

        }
        tmpResult = CY_CRYPTO_SUCCESS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(output, (int32_t)inputSize);
#endif

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_tag
****************************************************************************//**
*
* The function to calculate the tag.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param p_tag
* The pointer to the buffer for storing tag.
*
* \param tagSize
*  The length of the p_tag.
*
*
* \param aesGCMctx
* The pointer to the AES aesGCMctx structure allocated by the user. The user
* must not modify anything in this structure.
*******************************************************************************/
static void Cy_Crypto_Core_V2_Aes_GCM_tag(CRYPTO_Type *base,  uint8_t *p_tag,   uint32_t tagSize, cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    uint8_t bitlen_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(uint64_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint64_t *bitlen = (uint64_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(bitlen_t);
    uint8_t aadbitlen_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(uint64_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint64_t *aadbitlen = (uint64_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(aadbitlen_t);
    uint8_t temp_data_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0u};
    uint8_t *temp_data = (uint8_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(temp_data_t);
#else
    uint8_t temp_data[CY_CRYPTO_AES_BLOCK_SIZE] = {0};
    uint64_t bitlen_t;
    uint64_t aadbitlen_t;
    uint64_t *bitlen = &bitlen_t;
    uint64_t *aadbitlen = &aadbitlen_t;
#endif
   uint32_t i=0;
   uint8_t* tempRemap ;
   uint8_t *hRemap;
   uint8_t *yRemap;
   uint8_t *icbRemap;

   bitlen[0] = (uint64_t)aesGCMctx->data_size << 3U; // Bytes to bits
   aadbitlen[0] = (uint64_t)aesGCMctx->aad_size << 3U; // Bytes to bits

   tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(&temp_data[0u]);
   hRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->h);
   yRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->y);
   icbRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->icb);


   bitlen[0] = CY_SWAP_ENDIAN64(bitlen[0]);
   aadbitlen[0] = CY_SWAP_ENDIAN64(aadbitlen[0]);

    __DSB();

   Cy_Crypto_Core_V2_MemCpy(base, (void*)tempRemap, (void*)aadbitlen, (uint16_t)sizeof(aadbitlen[0]));
   Cy_Crypto_Core_V2_MemCpy(base, (void*)(tempRemap + 8u), (void*)bitlen, (uint16_t)sizeof(bitlen[0]));

   Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE , yRemap);

   (void)Cy_Crypto_Core_V2_Aes_Ecb(base, CY_CRYPTO_ENCRYPT, tempRemap, icbRemap, &aesGCMctx->aesState);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(temp_data, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

   for (i = 0u; i < tagSize; i++)
    {
      p_tag[i] = aesGCMctx->y[i] ^ temp_data[i];
    }
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Finish
****************************************************************************//**
*
* The function to finish the AES GCM operation and to calculates the tag.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param p_tag
* The pointer to the buffer for storing tag.
*
* \param tagSize
*  The length of the p_tag.
*
* \param aesGCMctx
* The pointer to the AES aesGCMctx structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Finish(CRYPTO_Type *base,  uint8_t *p_tag,  uint32_t tagSize, cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *hRemap;
    uint8_t *yRemap;
    uint8_t *tempRemap;
    uint8_t *aesdataRemap;

    if ((NULL != base) && (NULL != p_tag)  && !((tagSize > CY_CRYPTO_AES_BLOCK_SIZE) || (tagSize < 4u)) &&  (NULL != aesGCMctx))
    {

        hRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->h);
        yRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->y);
        tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->temp);
        aesdataRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesGCMctx->aes_data);

        if((0u == aesGCMctx->data_size) &&  (0u != aesGCMctx->aad_size %CY_CRYPTO_AES_BLOCK_SIZE))
        {
            Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, tempRemap, aesGCMctx->aad_size%CY_CRYPTO_AES_BLOCK_SIZE , yRemap);
        }

        if(0u != aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE)
        {
            Cy_Crypto_Core_V2_Aes_GCM_Ghash(base, hRemap, aesdataRemap, aesGCMctx->data_size %CY_CRYPTO_AES_BLOCK_SIZE , yRemap);
        }

        Cy_Crypto_Core_V2_Aes_GCM_tag(base,  p_tag, tagSize, aesGCMctx);
        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return  tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Encrypt_Tag
****************************************************************************//**
*
* The function performs the AES GCM encryption and generates the TAG
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aes_key
* The pointer to the AES key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param iv
* The pointer to the Initialization vector.
*
* \param ivSize
* The length of the iv.
*
* \param aad
* The pointer to the Additional Authentication Data.
*
* \param aadSize
*  The length of the additional Authentication Data
*
* \param input
* The pointer to the input data to be encrypted/decrypted.
*
* \param inputSize
*  The length of the input data.
*
* \param output
* The pointer to the encrypted/decrypted output data.
*
* \param tag
* The pointer to the tag.
*
* \param tagSize
*  The length of the p_tag.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Encrypt_Tag(CRYPTO_Type *base, uint8_t const *aesKey, cy_en_crypto_aes_key_length_t keyLength,
                                                            uint8_t const *iv, uint32_t ivSize, uint8_t *aad,   uint32_t aadSize,
                                                            uint8_t const *input,   uint32_t inputSize,  uint8_t *output, uint8_t *tag, uint32_t tagSize)

{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t aesGCMctx_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_aes_gcm_state_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t aesGCMBuffers_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_aes_gcm_buffers_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];

    cy_stc_crypto_aes_gcm_state_t  *aesGCMctx = (cy_stc_crypto_aes_gcm_state_t*) CY_CRYPTO_DCACHE_ALIGN_ADDRESS(aesGCMctx_t);
    cy_stc_crypto_aes_gcm_buffers_t *aesGCMBuffers = (cy_stc_crypto_aes_gcm_buffers_t*) CY_CRYPTO_DCACHE_ALIGN_ADDRESS(aesGCMBuffers_t);

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesKey) || ((NULL == iv) && (ivSize > 0u))
        || ( ((NULL == input) || (NULL == output)) && (inputSize > 0u)))
    {
        return status;
    }

    Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx, 0x00U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_state_t));
    Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMBuffers, 0x00U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_buffers_t));

    status = Cy_Crypto_Core_V2_Aes_GCM_Init(base, aesGCMBuffers, aesGCMctx);

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_SetKey(base, aesKey, keyLength, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_Start(base, CY_CRYPTO_ENCRYPT, iv, ivSize, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_AAD_Update(base, aad, aadSize, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_Update(base, input, inputSize, output, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status =  Cy_Crypto_Core_V2_Aes_GCM_Finish(base, tag, tagSize, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status =  Cy_Crypto_Core_V2_Aes_GCM_Free(base, aesGCMctx);
    }

    return (status);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Decrypt_Tag
****************************************************************************//**
*
* The function performs the AES GCM decryption and verifies the TAG.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aes_key
* The pointer to the AES key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param iv
* The pointer to the Initialization vector.
*
* \param ivSize
* The length of the iv.
*
* \param aad
* The pointer to the Additional Authentication Data.
*
* \param aadSize
*  The length of the additional Authentication Data
*
* \param input
* The pointer to the input data to be encrypted/decrypted.
*
* \param inputSize
*  The length of the input data.
*
* \param output
* The pointer to the encrypted/decrypted output data.
*
* \param tag
* The pointer to the tag.
*
* \param tagSize
*  The length of the p_tag.
*
* \param isVerified
* The status of the AES GCM verification.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Decrypt_Tag(CRYPTO_Type *base, uint8_t const *aesKey, cy_en_crypto_aes_key_length_t keyLength,
                                                            uint8_t const *iv, uint32_t ivSize, uint8_t *aad,   uint32_t aadSize,
                                                            uint8_t const *input,   uint32_t inputSize, uint8_t *tag, uint32_t tagSize, uint8_t *output, cy_en_crypto_aesgcm_tag_verify_result_t * isVerified)

{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t expected_tag_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0};
    uint8_t *expected_tag = (uint8_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(expected_tag_t);
    *isVerified  = CY_CRYPTO_TAG_INVALID;

    uint8_t aesGCMctx_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_aes_gcm_state_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t aesGCMBuffers_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_aes_gcm_buffers_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    cy_stc_crypto_aes_gcm_state_t  *aesGCMctx = (cy_stc_crypto_aes_gcm_state_t*) CY_CRYPTO_DCACHE_ALIGN_ADDRESS(aesGCMctx_t);
    cy_stc_crypto_aes_gcm_buffers_t *aesGCMBuffers = (cy_stc_crypto_aes_gcm_buffers_t*) CY_CRYPTO_DCACHE_ALIGN_ADDRESS(aesGCMBuffers_t);
#else
    cy_stc_crypto_aes_gcm_state_t *aesGCMctx = (cy_stc_crypto_aes_gcm_state_t *)&aesGCMctx_t;
    cy_stc_crypto_aes_gcm_buffers_t *aesGCMBuffers = (cy_stc_crypto_aes_gcm_buffers_t*)&aesGCMBuffers_t;
#endif

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesKey) || ((NULL == iv) && (ivSize > 0u))
        || ( ((NULL == input) || (NULL == output)) &&(inputSize > 0u)))
    {
        return status;
    }

    Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx, 0x00U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_state_t));
    Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMBuffers, 0x00U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_buffers_t));

    status = Cy_Crypto_Core_V2_Aes_GCM_Init(base, aesGCMBuffers, aesGCMctx);

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_SetKey(base, aesKey, keyLength, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_Start(base, CY_CRYPTO_DECRYPT, iv, ivSize, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_AAD_Update(base, aad, aadSize, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Aes_GCM_Update(base, input, inputSize, output, aesGCMctx);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status =  Cy_Crypto_Core_V2_Aes_GCM_Finish(base, expected_tag, tagSize, aesGCMctx);
    }

    if(CY_CRYPTO_SUCCESS == status)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','from essential type "unsigned 32-bit int" to different or narrower essential type "unsigned 16-bit int');
        if(Cy_Crypto_Core_V2_MemCmp(base, tag, expected_tag, tagSize) == 0U)
        {
            *isVerified = CY_CRYPTO_TAG_VALID;
        }
    }

    if (CY_CRYPTO_SUCCESS == status)
    {
        status =  Cy_Crypto_Core_V2_Aes_GCM_Free(base, aesGCMctx);
    }

    return (status);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_GCM_Free
****************************************************************************//**
*
* The function to finish the encryption process and calculate tag.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesGCMctx
* The pointer to the AES aesGCMctx structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_GCM_Free(CRYPTO_Type *base,  cy_stc_crypto_aes_gcm_state_t* aesGCMctx)
{
    if((NULL != base) && (NULL != aesGCMctx))
    {
        if(NULL != aesGCMctx->aes_buffer)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->aes_buffer, 0U, (uint16_t)sizeof(cy_stc_crypto_aes_buffers_t));
        }

        if(NULL != aesGCMctx->h)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->h, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        if(NULL != aesGCMctx->icb)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->icb, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        if(NULL != aesGCMctx->cb)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->cb, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        if(NULL != aesGCMctx->y)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->y, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        if(NULL != aesGCMctx->temp)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->temp, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        if(NULL != aesGCMctx->aes_data)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx->aes_data, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        Cy_Crypto_Core_V2_MemSet(base, (void*)aesGCMctx, 0U, (uint16_t)sizeof(cy_stc_crypto_aes_gcm_state_t));

    }

    return CY_CRYPTO_SUCCESS;
}
#endif /* (CPUSS_CRYPTO_GCM == 1) && defined(CY_CRYPTO_CFG_GCM_C)*/

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_LoadEncKey
****************************************************************************//**
*
* Calculates an inverse block cipher key from the block cipher key.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
*******************************************************************************/
void Cy_Crypto_Core_V2_Aes_LoadEncKey(CRYPTO_Type *base,
                                      cy_stc_crypto_aes_state_t const *aesState)
{

    uint8_t *keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesState->buffers->key);

    /* Set the key mode: 128, 192 or 256 Bit */
    uint32_t keySize = CY_CRYPTO_AES_128_KEY_SIZE + ((uint32_t)aesState->keyLength * 8u);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, keyRemap, keySize);
    Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_KEY0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_128_KEY_SIZE);

    keySize -= CY_CRYPTO_AES_128_KEY_SIZE;

    if (keySize != 0u)
    {
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_KEY1, CY_CRYPTO_V2_RB_FF_LOAD0, keySize);
    }

    REG_CRYPTO_AES_CTL(base) = (uint32_t)(_VAL2FLD(CRYPTO_AES_CTL_KEY_SIZE, aesState->keyLength));

    Cy_Crypto_Core_WaitForReady(base);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_LoadDecKey
****************************************************************************//**
*
* Calculates an inverse block cipher key from the block cipher key.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
*******************************************************************************/
void Cy_Crypto_Core_V2_Aes_LoadDecKey(CRYPTO_Type *base,
                                      cy_stc_crypto_aes_state_t const  *aesState)
{

    /* Issue the AES_KEY instruction to prepare the key for decrypt operation */
    uint32_t keySize = CY_CRYPTO_AES_128_KEY_SIZE + ((uint32_t)aesState->keyLength * 8u);

    Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState);

    Cy_Crypto_Core_V2_RunAes(base);             /* dummy encryption */

    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_KEY0, CY_CRYPTO_V2_RB_KEY2, CY_CRYPTO_AES_128_KEY_SIZE);

    keySize -= CY_CRYPTO_AES_128_KEY_SIZE;

    if (keySize != 0u)
    {
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_KEY1, CY_CRYPTO_V2_RB_KEY3, keySize);
    }

    Cy_Crypto_Core_WaitForReady(base);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Free
****************************************************************************//**
*
* Clears AES operation context.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Free(CRYPTO_Type *base, cy_stc_crypto_aes_state_t *aesState)
{
    if((NULL != base) && (aesState != NULL))
    {
        if(aesState->buffers != NULL)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void *)aesState->buffers, 0u, ((uint16_t)sizeof(cy_stc_crypto_aes_buffers_t)));
        }
        Cy_Crypto_Core_V2_MemSet(base, (void *)aesState, 0u, ((uint16_t)sizeof(cy_stc_crypto_aes_state_t)));
    }

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Init
****************************************************************************//**
*
* Sets AES mode and prepares inverse key.
*
* When D-Cache is enabled parameters key, aesState and aesBuffers must align and end in 32 byte boundary.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param key
* The pointer to the encryption/decryption key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \param aesBuffers
* The pointer to the memory buffers storage.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Init(CRYPTO_Type *base,
                                                 uint8_t const *key,
                                                 cy_en_crypto_aes_key_length_t keyLength,
                                                 cy_stc_crypto_aes_state_t *aesState,
                                                 cy_stc_crypto_aes_buffers_t *aesBuffers)
{
    CY_ASSERT_L1(NULL != key);
    CY_ASSERT_L1(NULL != aesState);
    CY_ASSERT_L1(NULL != aesBuffers);
    CY_ASSERT_L3(CY_CRYPTO_IS_KEYLENGTH_VALID(keyLength));
    uint8_t * keyRemap;
    cy_stc_crypto_aes_buffers_t *aesBuffersRemap;

    keyRemap = (uint8_t *) CY_REMAP_ADDRESS_FOR_CRYPTO(key);
    aesBuffersRemap = (cy_stc_crypto_aes_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesBuffers);

    uint16_t keySize = CY_CRYPTO_AES_128_KEY_SIZE + ((uint16_t)keyLength * 8u);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)key,(int32_t)keySize);
#endif
    Cy_Crypto_Core_V2_MemSet(base, aesState, 0u, ((uint16_t)sizeof(cy_stc_crypto_aes_state_t)));

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr((volatile void *)aesState, (int32_t)sizeof(cy_stc_crypto_aes_state_t));
#endif

    aesState->buffers = aesBuffers;
    aesState->keyLength = keyLength;
    Cy_Crypto_Core_V2_MemCpy(base, aesBuffersRemap->key, keyRemap, keySize);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(aesState->buffers->key, (int32_t)keySize);
#endif

    return (CY_CRYPTO_SUCCESS);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ecb
****************************************************************************//**
*
* Performs an AES operation on one block.
*
* When D-Cache is enabled parameters dst and src must align and end in 32 byte boundary.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t).
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source block.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ecb(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)
{
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    uint8_t *dstRemap;
    uint8_t *srcRemap;

    dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);

    (CY_CRYPTO_ENCRYPT == dirMode) ? \
        Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState) : Cy_Crypto_Core_V2_Aes_LoadDecKey(base, aesState);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, CY_CRYPTO_AES_BLOCK_SIZE);

    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);

    (CY_CRYPTO_ENCRYPT == dirMode) ? Cy_Crypto_Core_V2_RunAes(base) : Cy_Crypto_Core_V2_RunAesInv(base);

    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

    Cy_Crypto_Core_WaitForReady(base);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(dst, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    return (CY_CRYPTO_SUCCESS);
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ecb_Setup
****************************************************************************//**
*
* Performs an AES ECB init operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t).
*
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ecb_Setup(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == aesState->buffers))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    aesState->dirMode = dirMode;
    aesState->unProcessedBytes = 0u;

    return CY_CRYPTO_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ecb_Update
****************************************************************************//**
*
* Performs an AES ECB Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source block.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ecb_Update(CRYPTO_Type *base,
                                            uint32_t srcSize,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)


{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint32_t bytes_to_copy=0u;
    uint8_t *dstRemap;
    uint8_t *srcRemap;

    if(0u == srcSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == src))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if(((aesState->unProcessedBytes + srcSize) >= CY_CRYPTO_AES_BLOCK_SIZE) && (NULL == dst))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
#endif

    dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);

    if(aesState->unProcessedBytes + srcSize < CY_CRYPTO_AES_BLOCK_SIZE)
    {

        Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->unProcessedData[aesState->unProcessedBytes], (void*)srcRemap, (uint16_t)srcSize);
        aesState->unProcessedBytes += srcSize;
        status = CY_CRYPTO_SUCCESS;
    }
    else
    {

        if(aesState->unProcessedBytes > 0u)
        {

            bytes_to_copy = CY_CRYPTO_AES_BLOCK_SIZE - aesState->unProcessedBytes;

            if (srcSize < bytes_to_copy)
            {
                bytes_to_copy = srcSize;
            }

            Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->unProcessedData[aesState->unProcessedBytes], (void*)srcRemap, (uint16_t)bytes_to_copy);
            status = Cy_Crypto_Core_V2_Aes_Ecb(base, aesState->dirMode, dstRemap, (void*)aesState->buffers->unProcessedData, aesState);

            if(CY_CRYPTO_SUCCESS != status)
            {
                return status;
            }

            srcSize -= bytes_to_copy;
            srcRemap += bytes_to_copy;
            dstRemap += CY_CRYPTO_AES_BLOCK_SIZE;
            aesState->unProcessedBytes = 0u;
        }

        while(srcSize >= CY_CRYPTO_AES_BLOCK_SIZE)
        {

            status = Cy_Crypto_Core_V2_Aes_Ecb(base, aesState->dirMode, dstRemap, srcRemap, aesState);

            if(CY_CRYPTO_SUCCESS != status)
            {
                return status;
            }

            dstRemap += CY_CRYPTO_AES_BLOCK_SIZE;
            srcRemap += CY_CRYPTO_AES_BLOCK_SIZE;
            srcSize -= CY_CRYPTO_AES_BLOCK_SIZE;
        }

        if(srcSize > 0u)
        {
            Cy_Crypto_Core_V2_MemCpy(base, aesState->buffers->unProcessedData, (void*)srcRemap, (uint16_t)srcSize);
            aesState->unProcessedBytes = srcSize;
        }
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(dst, (int32_t)srcSize);
#endif

    return status;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ecb_Finish
****************************************************************************//**
*
* Performs an AES ECB finish operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ecb_Finish(CRYPTO_Type *base, cy_stc_crypto_aes_state_t *aesState)
{

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if(aesState->unProcessedBytes > 0u)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    return CY_CRYPTO_SUCCESS;
}




#if defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cbc
****************************************************************************//**
*
* Performs AES operation on a plain text with Cipher Block Chaining (CBC).
*
* When D-Cache is enabled parameters ivPtr, dst and src must align and end in 32 byte boundary.
* When DCache disabled, src must be 4-Byte aligned.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* The size of the source plain text.
*
* \param ivPtr
* The pointer to the initial vector.
*
* \param dst
* The pointer to a destination cipher text.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cbc(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                            uint32_t srcSize,
                                            uint8_t *ivPtr,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    uint32_t size = srcSize;
    uint32_t ivBlockId = CY_CRYPTO_V2_RB_BLOCK1;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_SIZE_NOT_X16;
    uint8_t *dstRemap;
    uint8_t *srcRemap;
    uint8_t *ivRemap;

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)ivPtr,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
#endif

    /* Check whether the data size is multiple of CY_CRYPTO_AES_BLOCK_SIZE */
    if (0UL == (srcSize & ((uint32_t)CY_CRYPTO_AES_BLOCK_SIZE - 1UL)))
    {

        ivRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ivPtr);
        dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
        srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);

        (CY_CRYPTO_ENCRYPT == dirMode) ? \
            Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState) : Cy_Crypto_Core_V2_Aes_LoadDecKey(base, aesState);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, ivRemap, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, size);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, size);

        if (CY_CRYPTO_ENCRYPT == dirMode)
        {
            ivBlockId = CY_CRYPTO_V2_RB_BLOCK1;

            /* Load the Initialization Vector to the local buffer */
            Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

            while (size != 0U)
            {
                Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0,
                                                 CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
                Cy_Crypto_Core_V2_RunAes(base);
                Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

                size -= CY_CRYPTO_AES_BLOCK_SIZE;
            }
        }
        else
        {
            ivBlockId = CY_CRYPTO_V2_RB_BLOCK2;

            /* Load the Initialization Vector to the temporary buffer */
            Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK2, CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

            while (size != 0U)
            {
                Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);
                Cy_Crypto_Core_V2_RunAesInv(base);
                Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_FF_STORE,
                                                 CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_BLOCK2, CY_CRYPTO_AES_BLOCK_SIZE);

                /* temporary cipher block */
                Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK2, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);

                size -= CY_CRYPTO_AES_BLOCK_SIZE;
            }
        }

        Cy_Crypto_Core_V2_Sync(base);

        /* Copy the local Initialization Vector to the external Initialization Vector */
        Cy_Crypto_Core_V2_FFStart (base, CY_CRYPTO_V2_RB_FF_STORE, ivRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, ivBlockId, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_Sync(base);

        tmpResult = CY_CRYPTO_SUCCESS;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr((volatile void *)dst, (int32_t)srcSize);
#endif
    }


    return (tmpResult);
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cbc_Setup
****************************************************************************//**
*
* Performs an AES CBC setup operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t).
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cbc_Setup(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == aesState->buffers))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    aesState->dirMode = dirMode;
    aesState->unProcessedBytes = 0u;

    return CY_CRYPTO_SUCCESS;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cbc_Set_IV
****************************************************************************//**
*
* Function to set AES CBC IV.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param iv
* The pointer to the IV.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cbc_Set_IV(CRYPTO_Type *base,
                                            uint8_t const * iv,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    uint8_t *ivRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == iv))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)iv,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    ivRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(iv);

    Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->iv, (void*)ivRemap, (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE);

    return CY_CRYPTO_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cbc_Update
****************************************************************************//**
*
* Performs an AES CBC Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source block.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cbc_Update(CRYPTO_Type *base,
                                            uint32_t srcSize,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)


{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint32_t bytes_to_copy=0u;
    uint32_t cnt=0u;
    uint8_t *dstRemap;
    uint8_t *srcRemap;

    if(0u == srcSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == src))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if(((aesState->unProcessedBytes + srcSize) >= CY_CRYPTO_AES_BLOCK_SIZE) && (NULL == dst))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
#endif


    dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);

    if(aesState->unProcessedBytes + srcSize < CY_CRYPTO_AES_BLOCK_SIZE)
    {

        Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->unProcessedData[aesState->unProcessedBytes], (void*)srcRemap, (uint16_t)srcSize);
        aesState->unProcessedBytes += srcSize;
        status = CY_CRYPTO_SUCCESS;
    }
    else
    {

        if(aesState->unProcessedBytes > 0u)
        {

            bytes_to_copy = CY_CRYPTO_AES_BLOCK_SIZE - aesState->unProcessedBytes;

            if (srcSize < bytes_to_copy)
            {
                bytes_to_copy = srcSize;
            }

            Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->unProcessedData[aesState->unProcessedBytes], (void*)srcRemap, (uint16_t)bytes_to_copy);

            status = Cy_Crypto_Core_V2_Aes_Cbc(base, aesState->dirMode, CY_CRYPTO_AES_BLOCK_SIZE, aesState->buffers->iv, dstRemap, aesState->buffers->unProcessedData, aesState);
            if(CY_CRYPTO_SUCCESS != status)
            {
                return status;
            }

            srcSize -= bytes_to_copy;
            srcRemap += bytes_to_copy;
            dstRemap += CY_CRYPTO_AES_BLOCK_SIZE;
            aesState->unProcessedBytes = 0u;
        }

        cnt = (uint32_t)(srcSize / CY_CRYPTO_AES_BLOCK_SIZE);

        if(cnt != 0u)
        {
            status = Cy_Crypto_Core_V2_Aes_Cbc(base, aesState->dirMode, cnt * CY_CRYPTO_AES_BLOCK_SIZE, aesState->buffers->iv, dstRemap, srcRemap, aesState);

            if(CY_CRYPTO_SUCCESS != status)
            {
                return status;
            }

            dstRemap +=  cnt * CY_CRYPTO_AES_BLOCK_SIZE;
            srcRemap += cnt * CY_CRYPTO_AES_BLOCK_SIZE;
            srcSize -= cnt * CY_CRYPTO_AES_BLOCK_SIZE;
        }

        if(srcSize > 0u)
        {
            Cy_Crypto_Core_V2_MemCpy(base, aesState->buffers->unProcessedData, (void*)srcRemap, (uint16_t)srcSize);
            aesState->unProcessedBytes = srcSize;
        }
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(dst, (int32_t)srcSize);
#endif

    return status;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cbc_Finish
****************************************************************************//**
*
* Performs an AES CBC finish operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cbc_Finish(CRYPTO_Type *base, cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if(aesState->unProcessedBytes > 0u)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    return CY_CRYPTO_SUCCESS;
}



#if defined(CY_CRYPTO_CFG_CBC_MAC_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_CbcMac_Setup
****************************************************************************//**
*
* Performs an AES CBC MAC setup operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_CbcMac_Setup(CRYPTO_Type *base,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == aesState->buffers))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    Cy_Crypto_Core_V2_MemSet(base, (void*)&aesState->buffers->iv, 0u,  (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE);
    aesState->unProcessedBytes = 0u;

    #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr((volatile void*)&aesState->buffers->iv, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    #endif

    return CY_CRYPTO_SUCCESS;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_CbcMac_Update
****************************************************************************//**
*
* Performs an AES CBC MAC Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of the source block.
*
* \param src
* The pointer to a source block.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_CbcMac_Update(CRYPTO_Type *base,
                                            uint32_t srcSize,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)


{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint32_t bytes_to_copy=0u;
    uint32_t cnt=0u;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    uint8_t tempbuf[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_AES_BLOCK_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0u};
    uint8_t *temp = (uint8_t*)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(tempbuf);
    uint8_t *srcRemap;
#else
    uint8_t temp[CY_CRYPTO_AES_BLOCK_SIZE] = {0u};
    uint8_t *srcRemap;
#endif

    if(0u == srcSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == src))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
#endif

    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);

    if(aesState->unProcessedBytes + srcSize < CY_CRYPTO_AES_BLOCK_SIZE)
    {
        #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            SCB_CleanDCache_by_Addr((volatile void *)aesState->buffers->unProcessedData, (int32_t)srcSize);
        #endif

        Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->unProcessedData[aesState->unProcessedBytes], (void*)srcRemap, (uint16_t)srcSize);

        #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            SCB_InvalidateDCache_by_Addr((volatile void *)aesState->buffers->unProcessedData, (int32_t)srcSize);
        #endif

        aesState->unProcessedBytes += srcSize;
        status = CY_CRYPTO_SUCCESS;
    }
    else
    {

        if(aesState->unProcessedBytes > 0u)
        {

            bytes_to_copy = CY_CRYPTO_AES_BLOCK_SIZE - aesState->unProcessedBytes;

            if (srcSize < bytes_to_copy)
            {
                bytes_to_copy = srcSize;
            }

            #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
                SCB_CleanDCache_by_Addr((volatile void *)aesState->buffers->unProcessedData, (int32_t)bytes_to_copy);
            #endif

            Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->unProcessedData[aesState->unProcessedBytes], (void*)srcRemap, (uint16_t)bytes_to_copy);

            #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
                SCB_InvalidateDCache_by_Addr((volatile void *)aesState->buffers->unProcessedData, (int32_t)bytes_to_copy);
            #endif

            status = Cy_Crypto_Core_V2_Aes_Cbc(base, CY_CRYPTO_ENCRYPT, CY_CRYPTO_AES_BLOCK_SIZE, aesState->buffers->iv, temp, aesState->buffers->unProcessedData, aesState);
            if(CY_CRYPTO_SUCCESS != status)
            {
                return status;
            }

            srcSize -= bytes_to_copy;
            srcRemap += bytes_to_copy;
            aesState->unProcessedBytes = 0u;
        }

        cnt = (uint32_t)(srcSize / CY_CRYPTO_AES_BLOCK_SIZE);

        while(cnt != 0u)
        {
            status = Cy_Crypto_Core_V2_Aes_Cbc(base, CY_CRYPTO_ENCRYPT, CY_CRYPTO_AES_BLOCK_SIZE, aesState->buffers->iv, temp, srcRemap, aesState);

            if(CY_CRYPTO_SUCCESS != status)
            {
                return status;
            }

            srcRemap +=  CY_CRYPTO_AES_BLOCK_SIZE;
            srcSize -= CY_CRYPTO_AES_BLOCK_SIZE;
            cnt--;
        }

        if(srcSize > 0u)
        {
            Cy_Crypto_Core_V2_MemCpy(base, aesState->buffers->unProcessedData, (void*)srcRemap, (uint16_t)srcSize);
            aesState->unProcessedBytes = srcSize;
        }
    }

    return status;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_CbcMac_Finish
****************************************************************************//**
*
* Performs an AES CBC finish operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param mac
* The pointer to a cbc-mac.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_CbcMac_Finish(CRYPTO_Type *base, uint8_t *mac, cy_stc_crypto_aes_state_t *aesState)
{
    uint8_t *macRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == mac))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if(aesState->unProcessedBytes > 0u)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    macRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(mac);

    Cy_Crypto_Core_V2_MemCpy(base, macRemap, (void*)&aesState->buffers->iv, (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(mac, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    return CY_CRYPTO_SUCCESS;
}
#endif /* defined(CY_CRYPTO_CFG_CBC_MAC_C) */

#endif /* defined(CY_CRYPTO_CFG_CIPHER_MODE_CBC) */

#if defined(CY_CRYPTO_CFG_CIPHER_MODE_CFB)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cfb
********************************************************************************
*
* Performs AES operation on a plain text with the Cipher Feedback Block method (CFB).
*
* When D-Cache is enabled parameters ivPtr, dst and src must align and end in 32 byte boundary.
* When DCache disabled, src must be 4-Byte aligned.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param srcSize
* The size of the source plain text.
*
* \param ivPtr
* The pointer to the initial vector.
*
* \param dst
* The pointer to a destination cipher text.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cfb(CRYPTO_Type *base,
                                             cy_en_crypto_dir_mode_t dirMode,
                                             uint32_t srcSize,
                                             uint8_t *ivPtr,
                                             uint8_t *dst,
                                             uint8_t const *src,
                                             cy_stc_crypto_aes_state_t *aesState)
{
    uint32_t size = srcSize;

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_SIZE_NOT_X16;
    uint8_t *ivRemap;
    uint8_t *dstRemap;
    uint8_t *srcRemap;

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)ivPtr,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
        SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
#endif

    /* Check whether the data size is multiple of CY_CRYPTO_AES_BLOCK_SIZE */
    if (0UL == (size & ((uint32_t)CY_CRYPTO_AES_BLOCK_SIZE - 1UL)))
    {

        ivRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ivPtr);
        dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
        srcRemap = (uint8_t *) CY_REMAP_ADDRESS_FOR_CRYPTO(src);

        Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState);

        /* Load the Initialization Vector to the src buffer */
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, ivRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, size);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, size);

        if (CY_CRYPTO_ENCRYPT == dirMode)
        {
            while (size != 0U)
            {
                Cy_Crypto_Core_V2_RunAes(base);
                Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0,
                                                 CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
                Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);

                size -= CY_CRYPTO_AES_BLOCK_SIZE;
            }
        }
        else
        {
            while (size != 0U)
            {
                Cy_Crypto_Core_V2_RunAes(base);
                Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);
                Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_FF_STORE,
                                                 CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);

                size -= CY_CRYPTO_AES_BLOCK_SIZE;
            }
        }

        Cy_Crypto_Core_V2_Sync(base);

        /* Copy the local Initialization Vector to the external Initialization Vector */
        Cy_Crypto_Core_V2_FFStart (base, CY_CRYPTO_V2_RB_FF_STORE, ivRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_Sync(base);

        tmpResult = CY_CRYPTO_SUCCESS;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr(dst, (int32_t)srcSize);
#endif
    }


    return (tmpResult);
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cfb_Setup
****************************************************************************//**
*
* Performs an AES CFB setup operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t).
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cfb_Setup(CRYPTO_Type *base,
                                            cy_en_crypto_dir_mode_t dirMode,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == aesState->buffers))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    aesState->dirMode = dirMode;
    aesState->unProcessedBytes = 0u;

    return CY_CRYPTO_SUCCESS;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cfb_Set_IV
****************************************************************************//**
*
* Sets IV for AES CFB mode.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param iv
* The pointer to iv.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cfb_Set_IV(CRYPTO_Type *base,
                                            uint8_t const * iv,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    uint8_t *ivRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == iv))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)iv,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    ivRemap =(uint8_t *) CY_REMAP_ADDRESS_FOR_CRYPTO(iv);

    Cy_Crypto_Core_V2_MemCpy(base, (void*)&aesState->buffers->iv, (void*)ivRemap, (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE);

    return CY_CRYPTO_SUCCESS;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cfb_Update
****************************************************************************//**
*
* Performs an AES CFB Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source block.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cfb_Update(CRYPTO_Type *base,
                                             uint32_t srcSize,
                                             uint8_t *dst,
                                             uint8_t const *src,
                                             cy_stc_crypto_aes_state_t *aesState)
{
    uint32_t bytes_rem=0u;
    uint32_t cnt=0u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_SIZE_NOT_X16;
    uint8_t *dstRemap;
    uint8_t *srcRemap;
    uint8_t *unprocessedRemap;
    uint8_t *ivRemap;

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
#endif

    dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);
    unprocessedRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesState->buffers->unProcessedData);
    ivRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesState->buffers->iv);

    if(aesState->unProcessedBytes !=0u)
    {
        bytes_rem = CY_CRYPTO_AES_BLOCK_SIZE - aesState->unProcessedBytes;
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, &unprocessedRemap[aesState->unProcessedBytes], bytes_rem);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_FF_LOAD1, bytes_rem);

        if (srcSize < bytes_rem)
        {
            bytes_rem = srcSize;
        }

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, bytes_rem);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, bytes_rem);

        Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, bytes_rem);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, bytes_rem);

        if(aesState->dirMode == CY_CRYPTO_ENCRYPT)
        {
            Cy_Crypto_Core_V2_MemCpy(base, &ivRemap[aesState->unProcessedBytes], dstRemap, (uint16_t)bytes_rem);
        }
        else
        {
            Cy_Crypto_Core_V2_MemCpy(base, &ivRemap[aesState->unProcessedBytes], srcRemap, (uint16_t)bytes_rem);
        }

        aesState->unProcessedBytes += bytes_rem;
        srcSize -= bytes_rem;
        srcRemap += bytes_rem;
        dstRemap += bytes_rem;

        if(aesState->unProcessedBytes == CY_CRYPTO_AES_BLOCK_SIZE)
        {
           aesState->unProcessedBytes = 0;
        }

        tmpResult = CY_CRYPTO_SUCCESS;
    }

    cnt = (uint32_t)(srcSize / CY_CRYPTO_AES_BLOCK_SIZE);

    if(cnt != 0u)
    {
        tmpResult = Cy_Crypto_Core_V2_Aes_Cfb(CRYPTO, aesState->dirMode, cnt * CY_CRYPTO_AES_BLOCK_SIZE, aesState->buffers->iv, dstRemap, srcRemap, aesState);

        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }
        srcSize -= cnt * CY_CRYPTO_AES_BLOCK_SIZE;
        srcRemap += cnt * CY_CRYPTO_AES_BLOCK_SIZE;
        dstRemap += cnt * CY_CRYPTO_AES_BLOCK_SIZE;
    }

    if(srcSize > 0u)
    {
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, ivRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState);
        Cy_Crypto_Core_V2_RunAes(base);

        Cy_Crypto_Core_V2_FFStart (base, CY_CRYPTO_V2_RB_FF_STORE, unprocessedRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, srcSize);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, srcSize);

        Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, srcSize);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, srcSize);

        if(aesState->dirMode == CY_CRYPTO_ENCRYPT)
        {
            Cy_Crypto_Core_V2_MemCpy(base, &aesState->buffers->iv, dstRemap, (uint16_t)srcSize);
        }
        else
        {
            Cy_Crypto_Core_V2_MemCpy(base, &aesState->buffers->iv, srcRemap, (uint16_t)srcSize);
        }

        aesState->unProcessedBytes += srcSize;
        srcSize -= bytes_rem;

        tmpResult = CY_CRYPTO_SUCCESS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(dst, (int32_t)srcSize);
#endif

    return tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Cfb_Finish
****************************************************************************//**
*
* Performs an AES CFB finish operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Cfb_Finish(CRYPTO_Type *base, cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    return CY_CRYPTO_SUCCESS;
}

#endif /* defined(CY_CRYPTO_CFG_CIPHER_MODE_CFB) */

#if defined(CY_CRYPTO_CFG_CIPHER_MODE_CTR)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ctr
********************************************************************************
*
* Performs AES operation on a plain text using the counter method (CTR).
*
* When D-Cache is enabled parameters ivPtr, streamBlock, dst and src must align and end in 32 byte boundary.
* When DCache disabled, src must be 4-Byte aligned.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of a source plain text.
*
* \param srcOffset
* The size of an offset within the current block stream for resuming within the
* current cipher stream.
*
* \param ivPtr
* The 128-bit initial vector that contains a 64-bit nonce and 64-bit counter.
*
* \param streamBlock
* The saved stream-block for resuming. Is over-written by the function.
*
* \param dst
* The pointer to a destination cipher text.
*
* \param src
* The pointer to a source plain text.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
#define CY_CRYPTO_AES_CTR_CNT_POS           (2U)
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ctr(CRYPTO_Type *base,
                                            uint32_t srcSize,
                                            uint32_t *srcOffset,
                                            uint8_t *ivPtr,
                                            uint8_t *streamBlock,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    uint32_t blockCount_t[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_AES_BLOCK_SIZE_U32)+CY_CRYPTO_DCAHCE_PADDING_SIZE_WORD] = {0,};
    uint32_t *blockCount = (uint32_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(blockCount_t);
    uint16_t blockCount_size = (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE;
    uint32_t *blockCounter = (uint32_t *) CY_REMAP_ADDRESS_FOR_CRYPTO((const void *)blockCount);

    uint64_t counter;
    uint32_t cnt;
    uint32_t i;
    uint8_t *dstRemap;
    uint8_t *srcRemap;
    uint8_t *ivRemap;

    (void)streamBlock; /* Suppress warning */

    Cy_Crypto_Core_V2_MemSet(base, (void*)blockCounter, 0x00U, blockCount_size);

    dstRemap =(uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);
    ivRemap =(uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ivPtr);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)ivPtr,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
    SCB_CleanDCache_by_Addr((volatile void *)streamBlock,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    blockCount[ 0] = (uint32_t) CY_CRYPTO_MERGE_BYTES(ivPtr[ 3], ivPtr[ 2], ivPtr[ 1], ivPtr[ 0]);
    blockCount[ 1] = (uint32_t) CY_CRYPTO_MERGE_BYTES(ivPtr[ 7], ivPtr[ 6], ivPtr[ 5], ivPtr[ 4]);
    blockCount[ 2] = (uint32_t) CY_CRYPTO_MERGE_BYTES(ivPtr[11], ivPtr[10], ivPtr[ 9], ivPtr[ 8]);
    blockCount[ 3] = (uint32_t) CY_CRYPTO_MERGE_BYTES(ivPtr[15], ivPtr[14], ivPtr[13], ivPtr[12]);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)blockCount,(int32_t)blockCount_size);
#endif

    counter = CY_SWAP_ENDIAN64(*(uint64_t*)(blockCount + CY_CRYPTO_AES_CTR_CNT_POS));

    Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, (const uint8_t *) blockCounter, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK0,   CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

    /* CTR counter is placed into last 4 bytes of the Nonce block */
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 4U, (uint8_t)((counter >> 24U) & 0xffU));
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 3U, (uint8_t)((counter >> 16U) & 0xffU));
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 2U, (uint8_t)((counter >>  8U) & 0xffU));
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 1U, (uint8_t)((counter) & 0xffU));

    Cy_Crypto_Core_V2_RunAes(base);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, srcSize);
    Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, srcSize);

    cnt = (uint32_t)(srcSize / CY_CRYPTO_AES_BLOCK_SIZE);

    for (i = 0uL; i < cnt; i++)
    {
        Cy_Crypto_Core_V2_RunAes(base);

        /* Increment the nonce counter */
        counter++;
        *(uint64_t*)(blockCount + CY_CRYPTO_AES_CTR_CNT_POS) = CY_SWAP_ENDIAN64(counter);

        /* CTR counter is placed into last 4 bytes of the Nonce block */
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 4U, (uint8_t)((counter >> 24u) & 0xffU));
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 3U, (uint8_t)((counter >> 16u) & 0xffU));
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 2U, (uint8_t)((counter >>  8u) & 0xffU));
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 1U, (uint8_t)((counter) & 0xffU));

        Cy_Crypto_Core_V2_RBXor  (base, CY_CRYPTO_AES_BLOCK_SIZE, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_RBStore(base, CY_CRYPTO_AES_BLOCK_SIZE, CY_CRYPTO_AES_BLOCK_SIZE);
    }

    Cy_Crypto_Core_V2_MemCpy(base, ivRemap, blockCounter, CY_CRYPTO_AES_BLOCK_SIZE);

    /* Save the reminder of the last non-complete block */
    *srcOffset = (uint32_t)(srcSize % CY_CRYPTO_AES_BLOCK_SIZE);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(dst, (int32_t)srcSize);
#endif

    return (CY_CRYPTO_SUCCESS);
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ctr_Setup
****************************************************************************//**
*
* Performs an AES CTR Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ctr_Setup(CRYPTO_Type *base,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == aesState->buffers))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    aesState->unProcessedBytes = 0u;
    return CY_CRYPTO_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ctr_Set_IV
****************************************************************************//**
*
* Sets IV for the AES CTR operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param iv
* The pointer to iv.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ctr_Set_IV(CRYPTO_Type *base,
                                            uint8_t const *iv,
                                            cy_stc_crypto_aes_state_t *aesState)
{
    uint8_t *ivRemap;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == iv) || (NULL == aesState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)iv,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    ivRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(iv);

    Cy_Crypto_Core_V2_MemCpy(base, (void*)aesState->buffers->iv, (void*)ivRemap, (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE);
    return CY_CRYPTO_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ctr_Update
****************************************************************************//**
*
* Performs an AES CTR Multistage update operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param srcSize
* The size of the source block.
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source block.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ctr_Update(CRYPTO_Type *base,
                                            uint32_t srcSize,
                                            uint8_t *dst,
                                            uint8_t const *src,
                                            cy_stc_crypto_aes_state_t *aesState)


{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t *dstRemap;
    uint8_t *srcRemap;
    uint8_t *unprocessedRemap;

    if(0u == srcSize)
    {
        return CY_CRYPTO_SUCCESS;
    }

        /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState) || (NULL == dst) || (NULL == src))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)src,(int32_t)srcSize);
    SCB_InvalidateDCache_by_Addr(aesState->buffers->iv, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    dstRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(dst);
    srcRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(src);
    unprocessedRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(aesState->buffers->unProcessedData);

    uint32_t blockCount_t[CY_CRYPTO_ALIGN_CACHE_LINE_WORD(CY_CRYPTO_AES_BLOCK_SIZE_U32)+CY_CRYPTO_DCAHCE_PADDING_SIZE_WORD];
    uint32_t *blockCount = (uint32_t*)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(blockCount_t);
    uint32_t *blockCounter = (uint32_t *) CY_REMAP_ADDRESS_FOR_CRYPTO(blockCount);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    uint16_t blockCount_size = (uint16_t)CY_CRYPTO_AES_BLOCK_SIZE;
    uint32_t dstSize = srcSize;
#endif
    uint64_t counter;
    uint32_t cnt;
    uint32_t srcOffset;
    uint32_t bytes_rem;

    blockCount[ 0] = (uint32_t) CY_CRYPTO_MERGE_BYTES( aesState->buffers->iv[3], aesState->buffers->iv[ 2], aesState->buffers->iv[ 1], aesState->buffers->iv[ 0]);
    blockCount[ 1] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[ 7], aesState->buffers->iv[ 6], aesState->buffers->iv[ 5], aesState->buffers->iv[ 4]);
    blockCount[ 2] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[11], aesState->buffers->iv[10], aesState->buffers->iv[ 9], aesState->buffers->iv[ 8]);
    blockCount[ 3] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[15], aesState->buffers->iv[14], aesState->buffers->iv[13], aesState->buffers->iv[12]);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)blockCount,(int32_t)blockCount_size);
#endif

    counter = CY_SWAP_ENDIAN64(*(uint64_t*)(blockCount + CY_CRYPTO_AES_CTR_CNT_POS));

    Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, (const uint8_t *) blockCounter, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK0,   CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

    /* CTR counter is placed into last 4 bytes of the Nonce block */
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 4U, (uint8_t)((counter >> 24U) & 0xffU));
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 3U, (uint8_t)((counter >> 16U) & 0xffU));
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 2U, (uint8_t)((counter >>  8U) & 0xffU));
    Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 1U, (uint8_t)((counter) & 0xffU));

    if(aesState->unProcessedBytes == 0u)
    {
        Cy_Crypto_Core_V2_RunAes(base);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, unprocessedRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
    }
    else
    {
        bytes_rem = CY_CRYPTO_AES_BLOCK_SIZE - aesState->unProcessedBytes;
        if (srcSize < bytes_rem)
        {
            bytes_rem = srcSize;
        }
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, &unprocessedRemap[aesState->unProcessedBytes], bytes_rem);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK1,   CY_CRYPTO_V2_RB_FF_LOAD1, bytes_rem);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, bytes_rem);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, bytes_rem);

        Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, bytes_rem);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, bytes_rem);

        srcSize -= bytes_rem;
        aesState->unProcessedBytes += bytes_rem;
        srcRemap += bytes_rem;
        dstRemap += bytes_rem;


    }

    if(aesState->unProcessedBytes == CY_CRYPTO_AES_BLOCK_SIZE)
    {
        aesState->unProcessedBytes = 0;

        /* Increment the nonce counter */
        counter++;
        *(uint64_t*)(blockCount + CY_CRYPTO_AES_CTR_CNT_POS) = CY_SWAP_ENDIAN64(counter);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)blockCount,(int32_t)blockCount_size);
#endif
        /* CTR counter is placed into last 4 bytes of the Nonce block */
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 4U, (uint8_t)((counter >> 24u) & 0xffU));
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 3U, (uint8_t)((counter >> 16u) & 0xffU));
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 2U, (uint8_t)((counter >>  8u) & 0xffU));
        Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 1U, (uint8_t)((counter) & 0xffU));

        Cy_Crypto_Core_V2_MemCpy(base, aesState->buffers->iv, blockCounter, CY_CRYPTO_AES_BLOCK_SIZE);

    }

    cnt = (uint32_t)(srcSize / CY_CRYPTO_AES_BLOCK_SIZE);
    if(cnt > 0u)
    {
        status = Cy_Crypto_Core_V2_Aes_Ctr(CRYPTO,cnt*CY_CRYPTO_AES_BLOCK_SIZE, &srcOffset, aesState->buffers->iv, NULL, dstRemap, srcRemap, aesState);

        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }
        srcSize -= cnt*CY_CRYPTO_AES_BLOCK_SIZE;
        srcRemap += cnt*CY_CRYPTO_AES_BLOCK_SIZE;
        dstRemap += cnt*CY_CRYPTO_AES_BLOCK_SIZE;

        blockCount[ 0] = (uint32_t) CY_CRYPTO_MERGE_BYTES( aesState->buffers->iv[3], aesState->buffers->iv[ 2], aesState->buffers->iv[ 1], aesState->buffers->iv[ 0]);
        blockCount[ 1] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[ 7], aesState->buffers->iv[ 6], aesState->buffers->iv[ 5], aesState->buffers->iv[ 4]);
        blockCount[ 2] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[11], aesState->buffers->iv[10], aesState->buffers->iv[ 9], aesState->buffers->iv[ 8]);
        blockCount[ 3] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[15], aesState->buffers->iv[14], aesState->buffers->iv[13], aesState->buffers->iv[12]);
    }

    if(srcSize>0u)
    {

        if(aesState->unProcessedBytes == 0u)
        {
            blockCount[ 0] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[3], aesState->buffers->iv[ 2], aesState->buffers->iv[ 1], aesState->buffers->iv[ 0]);
            blockCount[ 1] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[ 7], aesState->buffers->iv[ 6], aesState->buffers->iv[ 5], aesState->buffers->iv[ 4]);
            blockCount[ 2] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[11], aesState->buffers->iv[10], aesState->buffers->iv[ 9], aesState->buffers->iv[ 8]);
            blockCount[ 3] = (uint32_t) CY_CRYPTO_MERGE_BYTES(aesState->buffers->iv[15], aesState->buffers->iv[14], aesState->buffers->iv[13], aesState->buffers->iv[12]);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)blockCount,(int32_t)blockCount_size);
#endif

            counter = CY_SWAP_ENDIAN64(*(uint64_t*)(blockCount + CY_CRYPTO_AES_CTR_CNT_POS));

            Cy_Crypto_Core_V2_Aes_LoadEncKey(base, aesState);

            Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD1, (const uint8_t *) blockCounter, CY_CRYPTO_AES_BLOCK_SIZE);
            Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK0,   CY_CRYPTO_V2_RB_FF_LOAD1, CY_CRYPTO_AES_BLOCK_SIZE);

            /* CTR counter is placed into last 4 bytes of the Nonce block */
            Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 4U, (uint8_t)((counter >> 24U) & 0xffU));
            Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 3U, (uint8_t)((counter >> 16U) & 0xffU));
            Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 2U, (uint8_t)((counter >>  8U) & 0xffU));
            Cy_Crypto_Core_V2_RBSetByte(base, CY_CRYPTO_AES_BLOCK_SIZE - 1U, (uint8_t)((counter) & 0xffU));

            Cy_Crypto_Core_V2_RunAes(base);

        }

        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, unprocessedRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

        bytes_rem = CY_CRYPTO_AES_BLOCK_SIZE - aesState->unProcessedBytes;

        if (srcSize < bytes_rem)
        {
            bytes_rem = srcSize;
        }

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, &unprocessedRemap[aesState->unProcessedBytes], bytes_rem);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_BLOCK1,   CY_CRYPTO_V2_RB_FF_LOAD0, bytes_rem);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, srcRemap, bytes_rem);
        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, dstRemap, bytes_rem);

        Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, bytes_rem);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, bytes_rem);

        aesState->unProcessedBytes += bytes_rem;
    }

    Cy_Crypto_Core_V2_MemCpy(base, aesState->buffers->iv, blockCounter, CY_CRYPTO_AES_BLOCK_SIZE);


#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(dst, (int32_t)dstSize);
#endif

    return CY_CRYPTO_SUCCESS;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Aes_Ctr_Finish
****************************************************************************//**
*
* Performs an AES CTR Finish operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Aes_Ctr_Finish(CRYPTO_Type *base, cy_stc_crypto_aes_state_t *aesState)
{
    /* Input parameters verification */
    if ((NULL == base) || (NULL == aesState))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    return CY_CRYPTO_SUCCESS;
}

#endif /* defined(CY_CRYPTO_CFG_CIPHER_MODE_CTR) */
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.3')
#endif /* (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_AES_C) */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_CRYPTO_CFG_HW_V2_ENABLE) */

#endif /* defined(CY_IP_MXCRYPTO) */


/* [] END OF FILE */

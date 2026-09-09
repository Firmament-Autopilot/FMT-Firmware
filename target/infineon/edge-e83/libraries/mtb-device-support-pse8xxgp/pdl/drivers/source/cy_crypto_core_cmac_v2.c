/***************************************************************************//**
* \file cy_crypto_core_cmac_v2.c
* \version 2.150
*
* \brief
*  This file provides the source code to the API for the CMAC method
*  in the Crypto block driver.
*
*  Implementation is done in accordance with information from this weblink:
*  nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication800-38b.pdf
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

#include "cy_crypto_core_cmac_v2.h"

#if defined(CY_CRYPTO_CFG_HW_V2_ENABLE)

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_CMAC_C)

#include "cy_crypto_core_aes_v2.h"
#include "cy_crypto_core_hw_v2.h"
#include "cy_syslib.h"
#include "cy_crypto_core_mem_v2.h"
/* The bit string used to generate sub-keys */
#define CY_CRYPTO_CMAC_RB  (0x87u)

static void Cy_Crypto_Core_V2_Cmac_CalcSubKey(uint8_t *srcDstPtr);

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac_CalcSubKey
****************************************************************************//**
*
* Calculates the sub-key for the CMAC algorithm
* according to the NIST publication 800-38B, page 7.
*
* \param srcDstPtr
* The pointer to the source data for sub-key calculation, see 800-38B.
*
*******************************************************************************/
static void Cy_Crypto_Core_V2_Cmac_CalcSubKey(uint8_t *srcDstPtr)
{
    int32_t i;
    uint32_t c;
    uint32_t msb = 0UL;

    for (i = (int32_t)((int32_t)CY_CRYPTO_AES_BLOCK_SIZE - 1); i >= 0; i--)
    {
        c = (uint32_t)srcDstPtr[i];
        c = (c << 1U) | msb;
        srcDstPtr[i] = (uint8_t) c;
        msb = (c >> 8U) & 1UL;
    }

    if (0UL != msb)
    {
        /* Just one byte is valuable, the rest are zeros */
        srcDstPtr[(uint8_t)(CY_CRYPTO_AES_BLOCK_SIZE - 1U)] ^= CY_CRYPTO_CMAC_RB;
    }
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)srcDstPtr,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac_Init
****************************************************************************//**
*
* The function for initialization of CMAC operation.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \param buffer
* The pointer to the cmac buffer.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Cmac_Init(CRYPTO_Type *base, cy_stc_crypto_v2_cmac_state_t* cmacState, cy_stc_crypto_v2_cmac_buffers_t* buffer)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    cy_stc_crypto_v2_cmac_buffers_t *bufferRemap;
    cy_stc_crypto_v2_cmac_state_t *cmacStateRemap;

    if( (NULL != cmacState) && (NULL != buffer))
    {
        bufferRemap = (cy_stc_crypto_v2_cmac_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(buffer);
        cmacStateRemap = (cy_stc_crypto_v2_cmac_state_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState);

        Cy_Crypto_Core_V2_MemSet(base, cmacStateRemap, 0U, (uint16_t)sizeof(cy_stc_crypto_v2_cmac_state_t));
        Cy_Crypto_Core_V2_MemSet(base, bufferRemap, 0U, (uint16_t)sizeof(cy_stc_crypto_v2_cmac_buffers_t));

        cmacState->k = buffer->k;
        cmacState->temp = buffer->temp;
        cmacState->aesState.buffers = &buffer->aesBuffersData;
        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac_Start
****************************************************************************//**
*
* Starts CMAC calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \param aesKey
* The pointer to the cmac key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Cmac_Start(CRYPTO_Type *base, cy_stc_crypto_v2_cmac_state_t *cmacState,
                                                   uint8_t const *aesKey, cy_en_crypto_aes_key_length_t keyLength)
{

    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t *kRemap;

    kRemap =  (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->k);

    status = Cy_Crypto_Core_V2_Aes_Init(base, aesKey, keyLength, &cmacState->aesState, cmacState->aesState.buffers);

    if(status != CY_CRYPTO_SUCCESS)
    {
        return status;
    }

    Cy_Crypto_Core_V2_Aes_LoadEncKey(base, &cmacState->aesState);

    /* Calculate the K1 sub-key */
    Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_BLOCK0,
                                     CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_RunAes(base);
    Cy_Crypto_Core_V2_FFStart (base, CY_CRYPTO_V2_RB_FF_STORE, kRemap, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_Sync(base);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(cmacState->k, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif
    Cy_Crypto_Core_V2_Cmac_CalcSubKey(cmacState->k);

    return status;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac_Update
****************************************************************************//**
*
* Performs cmac update for multi stage operation.
*
* When D-Cache is enabled parameter message must align and end in 32 byte boundary.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \param message
* The pointer to the message whose CMAC is being computed.
*
* \param messageSize
* The size of the message whose CMAC is being computed.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Cmac_Update(CRYPTO_Type *base,
                                                    cy_stc_crypto_v2_cmac_state_t *cmacState,
                                                    uint8_t const *message,
                                                    uint32_t  messageSize)
{
    uint32_t count = 0u;
    uint32_t cnt=0u;
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t *tempRemap;
    cy_stc_crypto_aes_buffers_t  *bufferRemap;
    uint8_t *messageRemap;

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    /* Flush the cache */
    SCB_CleanDCache_by_Addr((volatile void *)message,(int32_t)messageSize);
#endif

    if(messageSize == 0u)
    {
        return CY_CRYPTO_SUCCESS;
    }

    tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->temp);
    bufferRemap = (cy_stc_crypto_aes_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->aesState.buffers);

    messageRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(message);

    if(cmacState->aesState.unProcessedBytes > 0u && messageSize > CY_CRYPTO_AES_BLOCK_SIZE-cmacState->aesState.unProcessedBytes)
    {
        Cy_Crypto_Core_V2_MemCpy(base, (void*)&bufferRemap->unProcessedData[cmacState->aesState.unProcessedBytes], (void*)messageRemap, (uint16_t)(CY_CRYPTO_AES_BLOCK_SIZE-cmacState->aesState.unProcessedBytes));

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, bufferRemap->unProcessedData, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);

        status = Cy_Crypto_Core_V2_Aes_Ecb(base, cmacState->aesState.dirMode, tempRemap, (void*)tempRemap, &cmacState->aesState);

        if(CY_CRYPTO_SUCCESS != status)
        {
            return status;
        }

        messageSize -= CY_CRYPTO_AES_BLOCK_SIZE-cmacState->aesState.unProcessedBytes;
        messageRemap+= CY_CRYPTO_AES_BLOCK_SIZE-cmacState->aesState.unProcessedBytes;
        cmacState->aesState.unProcessedBytes = 0u;
    }

    cnt = (uint32_t)((messageSize + CY_CRYPTO_AES_BLOCK_SIZE -1u) / CY_CRYPTO_AES_BLOCK_SIZE);

    if(cnt > 1u)
    {
        --cnt;
        count =  cnt*CY_CRYPTO_AES_BLOCK_SIZE;

        Cy_Crypto_Core_V2_Aes_LoadEncKey(base, &cmacState->aesState);
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, messageRemap, count);

        while (count > 0u)
        {
            Cy_Crypto_Core_V2_BlockXor(base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0,
                                            CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
            Cy_Crypto_Core_V2_RunAes(base);
            count -= CY_CRYPTO_AES_BLOCK_SIZE;
        }

        Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE);
        Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

        messageSize -= cnt*CY_CRYPTO_AES_BLOCK_SIZE;
        messageRemap += cnt*CY_CRYPTO_AES_BLOCK_SIZE;
    }

    if(messageSize > 0u)
    {
        Cy_Crypto_Core_V2_MemCpy(base, (void*)&bufferRemap->unProcessedData[cmacState->aesState.unProcessedBytes], (void*)messageRemap, (uint16_t)messageSize);
        cmacState->aesState.unProcessedBytes += messageSize;
    }

    return CY_CRYPTO_SUCCESS;
}


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 9.3', 2, \
    'Partial initialization is intentional')

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac_Finish
****************************************************************************//**
*
* Completes CMAC calculation.
*
* When D-Cache is enabled parameter cmac must align and end in 32 byte boundary.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param cmac
* The pointer to the computed CMAC value.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Cmac_Finish(CRYPTO_Type *base, cy_stc_crypto_v2_cmac_state_t *cmacState, uint8_t* cmac)
{

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    CRYPTO_MEM_ALIGN static const uint8_t p_padding[CY_CRYPTO_ALIGN_CACHE_LINE(16)] =
    {
        0x80u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };
#else
    uint8_t const p_padding[16] =
    {
        0x80u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };
#endif

    uint8_t *tempRemap;
    uint8_t  *kRemap;
    uint8_t *cmacRemap;
    cy_stc_crypto_aes_buffers_t * bufferRemap;

    cmacRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmac);
    tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->temp);
    kRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->k);
    bufferRemap = (cy_stc_crypto_aes_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->aesState.buffers);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)p_padding,(int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, tempRemap, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_AES_BLOCK_SIZE);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, bufferRemap->unProcessedData, cmacState->aesState.unProcessedBytes);

    if(cmacState->aesState.unProcessedBytes < CY_CRYPTO_AES_BLOCK_SIZE)
    {
        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, (const uint8_t*)CY_REMAP_ADDRESS_FOR_CRYPTO(p_padding), CY_CRYPTO_AES_BLOCK_SIZE - cmacState->aesState.unProcessedBytes);
        Cy_Crypto_Core_V2_Cmac_CalcSubKey(cmacState->k);        /* calculate "k2" */
    }

    Cy_Crypto_Core_V2_BlockXor  (base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0,
                                    CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);

    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, kRemap, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockXor  (base, CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_V2_RB_FF_LOAD0,
                                       CY_CRYPTO_V2_RB_BLOCK0, CY_CRYPTO_AES_BLOCK_SIZE);

    Cy_Crypto_Core_V2_Aes_LoadEncKey(base, &cmacState->aesState);
    Cy_Crypto_Core_V2_RunAes(base);

    Cy_Crypto_Core_V2_FFStart   (base, CY_CRYPTO_V2_RB_FF_STORE, cmacRemap, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_BlockMov  (base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_BLOCK1, CY_CRYPTO_AES_BLOCK_SIZE);
    Cy_Crypto_Core_V2_Sync(base);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
    SCB_InvalidateDCache_by_Addr(cmac, (int32_t)CY_CRYPTO_AES_BLOCK_SIZE);
#endif

    return (CY_CRYPTO_SUCCESS);
}

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 9.3')

/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac_Free
****************************************************************************//**
*
*
* When D-Cache is enabled parameter cmac must align and end in 32 byte boundary.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param cmacState
* The pointer to the structure which stores the CMAC context.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Cmac_Free(CRYPTO_Type *base,
                                cy_stc_crypto_v2_cmac_state_t *cmacState
                                )


{
    uint8_t *tempRemap;
    uint8_t  *kRemap;
    cy_stc_crypto_aes_buffers_t  *bufferRemap;

    if( (NULL != base) && (NULL != cmacState))
    {
        bufferRemap = (cy_stc_crypto_aes_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->aesState.buffers);
        tempRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->temp);
        kRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacState->k);

        if(bufferRemap  != NULL)
        {
            Cy_Crypto_Core_V2_MemSet(base, bufferRemap, 0U, (uint16_t)sizeof(cy_stc_crypto_aes_buffers_t));
        }

        if(kRemap != NULL)
        {
            Cy_Crypto_Core_V2_MemSet(base, kRemap, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        if(tempRemap  != NULL)
        {
            Cy_Crypto_Core_V2_MemSet(base, tempRemap, 0U, CY_CRYPTO_AES_BLOCK_SIZE);
        }

        Cy_Crypto_Core_V2_MemSet(base, cmacState, 0U, (uint16_t)sizeof(cy_stc_crypto_v2_cmac_state_t));
    }

    return CY_CRYPTO_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Cmac
****************************************************************************//**
*
* Performs CMAC(Cipher-based Message Authentication Code) operation
* on a message to produce message authentication code using AES.
*
* When DCache disabled, message & key must be 4-Byte aligned.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param message
* The pointer to a source plain text.
*
* \param messageSize
* The size of a source plain text.
*
* \param key
* The pointer to the encryption key.
*
* \param keyLength
* \ref cy_en_crypto_aes_key_length_t
*
* \param cmac
* The pointer to the calculated CMAC.
*
* \param aesState
* The pointer to the AES state structure allocated by the user. The user
* must not modify anything in this structure.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Cmac(CRYPTO_Type *base,
                                          uint8_t const *message,
                                          uint32_t messageSize,
                                          uint8_t const *key,
                                          cy_en_crypto_aes_key_length_t keyLength,
                                          uint8_t *cmac,
                                          cy_stc_crypto_aes_state_t *aesState)
{
    (void)aesState;
    /* Allocate space for the structure which stores the CMAC context */
    uint8_t  cmacStateLoc_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_cmac_state_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t  cmacBuffersData_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_cmac_buffers_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0,};

    cy_stc_crypto_v2_cmac_buffers_t *cmacBuffersData = (cy_stc_crypto_v2_cmac_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(cmacBuffersData_t);
    cy_stc_crypto_v2_cmac_state_t *cmacStateLoc = (cy_stc_crypto_v2_cmac_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(cmacStateLoc_t);
    cy_stc_crypto_v2_cmac_buffers_t *cmacBuffersDataRemap = (cy_stc_crypto_v2_cmac_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(cmacBuffersData);
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;


    Cy_Crypto_Core_V2_MemSet(base, cmacBuffersDataRemap, 0, (uint16_t)sizeof(cy_stc_crypto_v2_cmac_buffers_t));
    Cy_Crypto_Core_V2_MemSet(base, CY_REMAP_ADDRESS_FOR_CRYPTO(cmacStateLoc), 0, (uint16_t)sizeof(cy_stc_crypto_v2_cmac_state_t));

    status = Cy_Crypto_Core_V2_Cmac_Init  (base, cmacStateLoc, cmacBuffersData);

    if(CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Cmac_Start (base, cmacStateLoc, key, keyLength);
    }

    if(CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Cmac_Update(base, cmacStateLoc,  message, messageSize);
    }

    if(CY_CRYPTO_SUCCESS == status)
    {
        status = Cy_Crypto_Core_V2_Cmac_Finish(base, cmacStateLoc, cmac);
    }

    return (CY_CRYPTO_SUCCESS);
}

#endif /* (CPUSS_CRYPTO_AES == 1) && defined(CY_CRYPTO_CFG_CMAC_C) */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_CRYPTO_CFG_HW_V2_ENABLE) */

#endif /* defined(CY_IP_MXCRYPTO) */


/* [] END OF FILE */

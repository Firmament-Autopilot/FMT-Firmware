/***************************************************************************//**
* \file cy_crypto_core_chacha.c
* \version 2.150
*
* \brief
*  This file provides the source code to the API for the CHACHA method
*  in the Crypto block driver.
*
********************************************************************************
* \copyright
* Copyright (c) 2022-2024, Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_crypto_core_chacha.h"

#if defined(__cplusplus)
extern "C" {
#endif



#if defined(CY_CRYPTO_CFG_CHACHA_ENABLED) && (CPUSS_CRYPTO_CHACHA == 1)

#include "cy_crypto_core_hw_v2.h"
#include "cy_crypto_core_mem_v2.h"
#include "cy_syslib.h"


#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void Cy_Crypto_Core_V2_Chacha_execute(CRYPTO_Type *base,
                             cy_stc_crypto_chacha_state_t *chachaState);




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Chacha_Init
****************************************************************************//**
*
* The function to initialize CHACHA operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param chachaState
* The pointer to a Chacha State.
*
* \param rounds
*  The number of rounds to perform for the chacha operation
*
* \param chachaBuffers
* The pointer to the memory buffers storage.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_Init(CRYPTO_Type *base,
                             cy_stc_crypto_chacha_state_t *chachaState,
                             uint8_t rounds,
                             cy_stc_crypto_v2_chacha_buffers_t * chachaBuffers)

{
    (void)base; /* Suppress warning */
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    if((NULL != chachaState) && (NULL != chachaBuffers))
    {
        chachaState->state = &chachaBuffers->state;
        chachaState->key = chachaBuffers->keyStream;
        chachaState->keyIndexUsed = 64U;
        chachaState->round = rounds;

        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Chacha_start
****************************************************************************//**
*
* Initializes the state with the key, nonce, counter and constant.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param chachaState
* The pointer to the chachaState state.
*
* \param key
* The pointer to the 32 byte buffer containing the chacha key in big endian format.
*
* \param nonce
* The pointer to the 12 byte buffer containing the nonce in big endian format.
*
* \param counter
* The counter value as 4 byte integer for the chacha operation.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_start(CRYPTO_Type *base, cy_stc_crypto_chacha_state_t *chachaState,
                             uint8_t const *key,
                             uint8_t const *nonce,
                             uint32_t counter)

{
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE))  || CY_CPU_CORTEX_M55)
    CRYPTO_MEM_ALIGN static const uint32_t p_constants[CY_CRYPTO_ALIGN_CACHE_LINE(4)] = {0x61707865, 0x3320646e, 0x79622d32, 0x6b206574 };
#else
    static const uint32_t p_constants[4] = {0x61707865, 0x3320646e, 0x79622d32, 0x6b206574 };
#endif
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *keyRemap;
    uint8_t *nonceRemap;
    uint8_t *counterRemap;
    uint8_t *constRemap;
    uint8_t *keyInRemap;
    uint8_t *nonceInRemap;

    if((NULL != chachaState) && (NULL != key) && (NULL != nonce))
    {

        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->state->key);
        nonceRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->state->nonce);
        counterRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(&chachaState->state->counter);
        constRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->state->constant);
        keyInRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key);
        nonceInRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(nonce);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)key,(int32_t)CHACHA_KEY_SIZE);
        SCB_CleanDCache_by_Addr((volatile void *)nonce,(int32_t)CHACHA_NONCE_SIZE);
#endif
        Cy_Crypto_Core_V2_MemCpy(base, keyRemap, keyInRemap, CHACHA_KEY_SIZE);
        Cy_Crypto_Core_V2_MemCpy(base, nonceRemap, nonceInRemap, CHACHA_NONCE_SIZE);
        Cy_Crypto_Core_V2_MemCpy(base, counterRemap, &counter, CHACHA_COUNTER_SIZE);
        Cy_Crypto_Core_V2_MemCpy(base, constRemap, (void *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_constants), CHACHA_CONST_SIZE);

        tmpResult = CY_CRYPTO_SUCCESS;

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_InvalidateDCache_by_Addr(chachaState->state, (int32_t)sizeof(cy_stc_crypto_v2_chacha_input_buffer));
#endif

    }



    return tmpResult;

}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Chacha_update
****************************************************************************//**
*
* Performs the chacha operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param chachaState
* The pointer to the chachaState state.
*
* \param input
* The pointer to a input message where the data needs to be encrypted/decrypted.
*
* \param inputSize
* The size of a input message.
*
* \param output
* The pointer to the output buffer.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_update(CRYPTO_Type *base,  cy_stc_crypto_chacha_state_t *chachaState, uint8_t const *input, uint32_t inputSize, uint8_t *output)
{

    uint8_t bytesToUse = 0U;
    uint32_t bytesOffset = 0U;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint32_t keyindexrem = 0u;

    uint8_t *keyRemap;
    uint8_t *inputRemap;
    uint8_t *outputRemap;


    if((NULL != chachaState) && (NULL != input) && (NULL != output) && (NULL != base))
    {
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)input,(int32_t)inputSize);
        SCB_InvalidateDCache_by_Addr(output, (int32_t)inputSize);
#endif
        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->key);
        inputRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(input);
        outputRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(output);

        // If a already calculated keystream is available and is not fully utilized
        if( inputSize> 0U && chachaState->keyIndexUsed < CHACHA_KEYSTREAM_SIZE)
        {

            Cy_Crypto_Core_V2_RBClear(base);
            Cy_Crypto_Core_V2_Sync(base);

            keyindexrem = (uint32_t)CHACHA_BLOCK_SIZE - chachaState->keyIndexUsed;

            bytesToUse = (uint8_t)MIN(inputSize, keyindexrem);

            /* Load the keystream with key used offset to the register buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, (uint8_t*)keyRemap + chachaState->keyIndexUsed, bytesToUse);
            Cy_Crypto_Core_V2_RBXor(base, 0U, bytesToUse);

            /* XOR keystream with the input data and store it in register buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, inputRemap, bytesToUse);
            Cy_Crypto_Core_V2_RBXor(base, 0U, bytesToUse);

            chachaState->keyIndexUsed += bytesToUse;
            inputSize -= bytesToUse;
            bytesOffset += bytesToUse;

            /* Store the XOR data from the register buffer to the output buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)outputRemap, bytesToUse);
            Cy_Crypto_Core_V2_RBStore(base, 0U, bytesToUse);
            Cy_Crypto_Core_V2_FFStoreSync(base);


        }


        while(inputSize >=CHACHA_BLOCK_SIZE)
        {

            /* Calculate the key stream from the chacha state */
            Cy_Crypto_Core_V2_Chacha_execute(base, chachaState);

            chachaState->state->counter++;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            SCB_CleanDCache_by_Addr((volatile void *)&chachaState->state->counter, (int32_t)4u);

#endif
            Cy_Crypto_Core_V2_RBClear(base);
            Cy_Crypto_Core_V2_Sync(base);

            /* Load the keystream to the register buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, (uint8_t*)keyRemap, CHACHA_KEYSTREAM_SIZE);
            Cy_Crypto_Core_V2_RBXor(base, 0U, CHACHA_KEYSTREAM_SIZE);

            /* XOR keystream with the input data and store it in register buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, inputRemap + bytesOffset, CHACHA_BLOCK_SIZE);
            Cy_Crypto_Core_V2_RBXor(base, 0U, CHACHA_BLOCK_SIZE);

            /* Store the XOR data from the register buffer to the output buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)outputRemap + bytesOffset, CHACHA_BLOCK_SIZE);
            Cy_Crypto_Core_V2_RBStore(base, 0U, CHACHA_BLOCK_SIZE);
            Cy_Crypto_Core_V2_FFStoreSync(base);

            inputSize -= CHACHA_BLOCK_SIZE;
            bytesOffset += CHACHA_BLOCK_SIZE;

        }

        // Partial block data is available for the chacha operation
        if( inputSize > 0U )
        {
            /* Calculate the key stream from the chacha state */
            Cy_Crypto_Core_V2_Chacha_execute(base, chachaState);

            chachaState->state->counter++;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            SCB_CleanDCache_by_Addr((volatile void *)&chachaState->state->counter, (int32_t)4u);

#endif
            Cy_Crypto_Core_V2_RBClear(base);
            Cy_Crypto_Core_V2_Sync(base);

            /* Load the keystream to the register buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, (uint8_t*)keyRemap, CHACHA_KEYSTREAM_SIZE);
            Cy_Crypto_Core_V2_RBXor(base, 0U, CHACHA_KEYSTREAM_SIZE);

            /* XOR keystream with the input data and store it in register buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, inputRemap + bytesOffset, inputSize);
            Cy_Crypto_Core_V2_RBXor(base, 0U, inputSize);

            /* Store the XOR data from the register buffer to the output buffer */
            Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)outputRemap + bytesOffset, inputSize);
            Cy_Crypto_Core_V2_RBStore(base, 0U, inputSize);
            Cy_Crypto_Core_V2_FFStoreSync(base);

            chachaState->keyIndexUsed = (uint8_t)inputSize;
        }

        tmpResult = CY_CRYPTO_SUCCESS;
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
                /* Flush the cache */
        SCB_InvalidateDCache_by_Addr(output, (int32_t)inputSize);

#endif


    }

    return tmpResult;


}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Chacha_execute
****************************************************************************//**
*
* Performs the chacha operation .
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param chachaState
* The pointer to the chachaState state.
*
*
*******************************************************************************/

void Cy_Crypto_Core_V2_Chacha_execute(CRYPTO_Type *base,
                             cy_stc_crypto_chacha_state_t *chachaState)

{
    uint8_t *keyRemap;
    uint8_t *stateRemap;

    keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->key);
    stateRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->state);

    /* Load the calculated hash state from the context buffer */
    Cy_Crypto_Core_V2_RBClear(base);
    Cy_Crypto_Core_V2_Sync(base);

    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, stateRemap, CHACHA_STATE_SIZE);
    Cy_Crypto_Core_V2_RBXor(base, 64U, CHACHA_STATE_SIZE);

    Cy_Crypto_Core_V2_RunChacha(base, chachaState->round);

    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, keyRemap, CHACHA_KEYSTREAM_SIZE);
    Cy_Crypto_Core_V2_RBStore(base, 0U, CHACHA_KEYSTREAM_SIZE);

    Cy_Crypto_Core_V2_FFStoreSync(base);

}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Chacha_Free
****************************************************************************//**
*
* Frees the chacha state and buffers.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param chachaState
* The pointer to the chachaState state.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_Free(CRYPTO_Type *base, cy_stc_crypto_chacha_state_t *chachaState)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *keyRemap;
    uint8_t *stateRemap;

    if ((NULL != base) && (NULL != chachaState))
    {

        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->key);
        stateRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(chachaState->state);

        /* Clears the context buffers */
        if(NULL != stateRemap)
        {
            Cy_Crypto_Core_V2_MemSet(base, stateRemap, 0x00U, (uint16_t)CHACHA_STATE_SIZE);
        }
        if(NULL != keyRemap)
        {
            Cy_Crypto_Core_V2_MemSet(base, keyRemap, 0x00U, (uint16_t)CHACHA_KEYSTREAM_SIZE);
        }

        /* Clears the CHACHA state */
        Cy_Crypto_Core_V2_MemSet(base, chachaState,  0x00U, (uint16_t)sizeof(cy_stc_crypto_chacha_state_t));

        /* Clears the memory buffer. */
        Cy_Crypto_Core_V2_RBClear(base);
        Cy_Crypto_Core_V2_Sync(base);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr((volatile void *)chachaState, (int32_t)sizeof(cy_stc_crypto_chacha_state_t));
#endif
        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return (tmpResult);
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_Chacha20
****************************************************************************//**
*
* Performs the chacha20 operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param mode
* \ref cy_en_crypto_sha_mode_t
*
* \param message
* The pointer to a message whose hash value is being computed.
*
* \param messageSize
* The size of a message.
*
* \param digest
* The pointer to the hash digest.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_Chacha20(CRYPTO_Type *base,
                                     uint8_t const *key, uint8_t const *nonce, uint32_t counter, uint8_t const *input,
                                     uint32_t inputSize, uint8_t *output)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t state_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_chacha_state_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t buffer_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_chacha_buffers_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];

    cy_stc_crypto_chacha_state_t *state = (cy_stc_crypto_chacha_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(state_t);
    cy_stc_crypto_v2_chacha_buffers_t *buffer = (cy_stc_crypto_v2_chacha_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(buffer_t);

    if((NULL != input) && (NULL != key) && (NULL != output) && (NULL != base) && (NULL != nonce))
    {
        Cy_Crypto_Core_V2_MemSet(base, state, 0, (uint16_t)sizeof(cy_stc_crypto_chacha_state_t));
        Cy_Crypto_Core_V2_MemSet(base, buffer, 0, (uint16_t)sizeof(cy_stc_crypto_v2_chacha_buffers_t));

        tmpResult = Cy_Crypto_Core_V2_Chacha_Init(CRYPTO, state, 10U, buffer);

        if (CY_CRYPTO_SUCCESS == tmpResult)
        {
            tmpResult = Cy_Crypto_Core_V2_Chacha_start(CRYPTO, state, key, nonce, counter);
        }

        if (CY_CRYPTO_SUCCESS == tmpResult)
        {
            tmpResult = Cy_Crypto_Core_V2_Chacha_update(CRYPTO, state, input, inputSize, output);
        }

        if (CY_CRYPTO_SUCCESS == tmpResult)
        {
            tmpResult = Cy_Crypto_Core_V2_Chacha_Free(base, state);
        }
    }
    return (tmpResult);
}

#endif /* #if (CPUSS_CRYPTO_CHACHA == 1) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */


/* [] END OF FILE */

/***************************************************************************//**
* \file cy_crypto_core_poly1305.c
* \version 2.150
*
* \brief
*  This file provides the source code to the API for the poly1305 method
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

#include "cy_crypto_core_poly1305.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_POLY1305_ENABLED)

#include "cy_crypto_core_hw_v2.h"
#include "cy_crypto_core_vu.h"
#include "cy_crypto_core_mem_v2.h"

#define MIN( x, y ) ( ( x ) < ( y ) ? ( x ) : ( y ) )


#define POLY_1305_S_VREG (0u) // 130-bit state S
#define POLY_1305_M_VREG (1u) // 129-bit message M
#define POLY_1305_R_VREG (2u) // 128-bit key R
#define POLY_1305_K_VREG (3u) // 128-bit key K
#define POLY_1305_P_VREG (4u) // 130-bit prime P

#define POLY_1305_T_259_VREG (5u)
#define POLY_1305_T_132_VREG (6u)
#define POLY_1305_T_5_VREG (7u)
#define POLY_1305_C_5_VREG (8u)
#define POLY_1305_C_130_VREG (9u)



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_poly_1305_load_ctx
****************************************************************************//**
*
* The function that loads context to internal memory for poly 1305 mac operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param state
* The pointer to the poly 1305 state.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
static cy_en_crypto_status_t Cy_Crypto_Core_V2_poly_1305_load_ctx(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state)
{
    uint32_t destAddr = 0u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    uint8_t *stateRemap;
    uint8_t *keyRemap;

    static const uint8_t  polynomial[CY_CRYPTO_POLY1305_POLYNOMIAL_SIZE] = {
      0xfbu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
      0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu, 0xffu,
      0x03u};

    static const uint8_t constant_5[] = { 0x05u };


#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)state->state,(int32_t)CY_CRYPTO_POLY1305_STATE_SIZE);
        SCB_CleanDCache_by_Addr((volatile void *)state->key,(int32_t)CY_CRYPTO_POLY1305_KEY_SIZE);
#endif

    stateRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(state->state);
    keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(state->key);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_S_VREG, 130u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_M_VREG, 129u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_R_VREG, 128u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_K_VREG, 128u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_P_VREG, 130u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_T_259_VREG, 259u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_T_132_VREG, 132u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_T_5_VREG, 5u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_C_5_VREG, 3u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM      (base, POLY_1305_C_130_VREG, 130u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    CY_CRYPTO_VU_SET_REG (base, POLY_1305_C_130_VREG, 130u, 1u);

    // Loading the R part of the Key from context to the internal Vu register
    destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_R_VREG);
    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, keyRemap, CY_CRYPTO_POLY1305_KEY_SIZE);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)destAddr, 16u);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 16u);

    // Loading the K part of the Key from context to the internal Vu register
    destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_K_VREG);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*) destAddr, 16u);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 16u);

    // Loading the prime polynomial to the internal Vu register
    destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_P_VREG);
    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, (const uint8_t* )CY_REMAP_ADDRESS_FOR_CRYPTO(polynomial), CY_CRYPTO_POLY1305_POLYNOMIAL_SIZE);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)destAddr, CY_CRYPTO_POLY1305_POLYNOMIAL_SIZE);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 16u);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 1u);

    // Loading Constant to the internal Vu register
    destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_C_5_VREG);
    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, (const uint8_t* )CY_REMAP_ADDRESS_FOR_CRYPTO(constant_5), 1u);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)destAddr, 1u);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 1u);

    // Loading the poly_1305 state from context to the internal Vu register
    destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_S_VREG);
    Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, stateRemap, CY_CRYPTO_POLY1305_STATE_SIZE);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)destAddr, CY_CRYPTO_POLY1305_STATE_SIZE);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 16u);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 1u);


    return CY_CRYPTO_SUCCESS;

}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_poly_1305_store_ctx
****************************************************************************//**
*
* The function to save context from internal memory for poly 1305 mac operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param state
* The pointer to the poly 1305 state.
*
*******************************************************************************/
static void Cy_Crypto_Core_V2_poly_1305_store_ctx(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state)
{
    uint32_t destAddr = 0u;
    uint8_t *stateRemap;


    stateRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(state->state);

    // Storing the poly 1305 state from the internal VU memory to the context
    destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_S_VREG);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, (uint8_t*)destAddr, CY_CRYPTO_POLY1305_STATE_SIZE);
    Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)stateRemap, CY_CRYPTO_POLY1305_STATE_SIZE);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 16u);
    Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, 1u);

    // Freeing the allocated memory from the internal VU register
    CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(POLY_1305_S_VREG) | CY_CRYPTO_VU_REG_BIT(POLY_1305_M_VREG) |
    CY_CRYPTO_VU_REG_BIT(POLY_1305_R_VREG) | CY_CRYPTO_VU_REG_BIT(POLY_1305_K_VREG) | CY_CRYPTO_VU_REG_BIT(POLY_1305_P_VREG) |
    CY_CRYPTO_VU_REG_BIT(POLY_1305_T_259_VREG) | CY_CRYPTO_VU_REG_BIT(POLY_1305_T_132_VREG) | CY_CRYPTO_VU_REG_BIT(POLY_1305_T_5_VREG) |
    CY_CRYPTO_VU_REG_BIT(POLY_1305_C_5_VREG) | CY_CRYPTO_VU_REG_BIT(POLY_1305_C_130_VREG) );

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_InvalidateDCache_by_Addr((volatile void *)state->state,(int32_t)CY_CRYPTO_POLY1305_STATE_SIZE);
#endif

}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_poly_1305_calculate
****************************************************************************//**
*
* The function to calculate poly 1305 mac.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param state
* The pointer to the poly 1305 state.
*
* \param p_message
* The pointer to the message.
*
* \param size
* The length of the message.
*
*******************************************************************************/
static void Cy_Crypto_Core_V2_poly_1305_calculate(CRYPTO_Type *base,  uint8_t * p_message,  uint32_t size)
{

    uint32_t load_size;
    uint32_t destAddr ;
    uint8_t *p_messageRemap;

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)p_message,(int32_t)size);
#endif

    p_messageRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_message);

    while (size != 0u) {
        load_size = MIN (size, CY_CRYPTO_POLY1305_BLOCK_SIZE);

        if (load_size == CY_CRYPTO_POLY1305_BLOCK_SIZE)
        {
            CY_CRYPTO_VU_SET_BIT_IMM (base, POLY_1305_M_VREG, 128u);

        }
        else
        {
            CY_CRYPTO_VU_SET_TO_ZERO (base, POLY_1305_M_VREG);

        }

        Cy_Crypto_Core_V2_FFContinue(base, CY_CRYPTO_V2_RB_FF_LOAD0, p_messageRemap, load_size);


        p_messageRemap += load_size;
        size      -= load_size;


        destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_M_VREG);
        Cy_Crypto_Core_V2_FFStart  (base, CY_CRYPTO_V2_RB_FF_STORE,  (uint8_t*) destAddr, load_size);
        Cy_Crypto_Core_V2_BlockMov (base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, load_size); // M

        if (load_size < CY_CRYPTO_POLY1305_BLOCK_SIZE)
        {
            CY_CRYPTO_VU_SET_BIT_IMM (base, POLY_1305_M_VREG, load_size*8u);

        }


        CY_CRYPTO_VU_ADD  (base, POLY_1305_T_132_VREG, POLY_1305_S_VREG, POLY_1305_M_VREG);
        CY_CRYPTO_VU_UMUL (base, POLY_1305_T_259_VREG, POLY_1305_T_132_VREG, POLY_1305_R_VREG);

        CY_CRYPTO_VU_LSR  (base, POLY_1305_T_132_VREG, POLY_1305_T_259_VREG, POLY_1305_C_130_VREG);
        CY_CRYPTO_VU_UMUL (base, POLY_1305_T_132_VREG, POLY_1305_T_132_VREG, POLY_1305_C_5_VREG);
        CY_CRYPTO_VU_MOV  (base, POLY_1305_S_VREG, POLY_1305_T_259_VREG);
        CY_CRYPTO_VU_ADD  (base, POLY_1305_T_132_VREG, POLY_1305_T_132_VREG, POLY_1305_S_VREG);

        CY_CRYPTO_VU_LSR  (base, POLY_1305_T_5_VREG, POLY_1305_T_132_VREG, POLY_1305_C_130_VREG);
        CY_CRYPTO_VU_UMUL (base, POLY_1305_T_5_VREG, POLY_1305_T_5_VREG, POLY_1305_C_5_VREG);
        CY_CRYPTO_VU_ADD  (base, POLY_1305_S_VREG, POLY_1305_T_132_VREG, POLY_1305_T_5_VREG);

        CY_CRYPTO_VU_COND_SUB (base, CY_CRYPTO_VU_COND_CS, POLY_1305_S_VREG, POLY_1305_S_VREG, POLY_1305_P_VREG);

    }

}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_poly_1305_Init
****************************************************************************//**
*
* The function to initialize poly 1305 operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param key
* The pointer to the key.
*
* \param state
* The pointer to the poly 1305 state.
*
* \param buffer
* The pointer to the poly 1305 buffer.
*
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Init(CRYPTO_Type *base, uint8_t const *key, cy_stc_crypto_poly_1305_state_t *state, cy_stc_crypto_poly_1305_buffers_t *buffer)
{

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *keyRemap;
    uint8_t *keyInRemap;
    cy_stc_crypto_poly_1305_buffers_t *bufferRemap;

    if((NULL != key) && (NULL != state) && (NULL != buffer))
    {
        keyInRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key);
        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(buffer->key);
        bufferRemap = (cy_stc_crypto_poly_1305_buffers_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(buffer);

        Cy_Crypto_Core_V2_MemSet(base, bufferRemap, 0u, (uint16_t)sizeof(cy_stc_crypto_poly_1305_buffers_t));
        Cy_Crypto_Core_V2_MemCpy(base, keyRemap, (void *)keyInRemap, CY_CRYPTO_POLY1305_KEY_SIZE);

        state->state = buffer->state;
        state->key = buffer->key;
        state->partialMessage = buffer->partialMessage;
        state->messageIndex = 0u;

        state->key[3u] &= 0x0fu;
        state->key[7u] &= 0x0fu;
        state->key[11u] &= 0x0fu;
        state->key[15u] &= 0x0fu;
        state->key[4u] &= 0xfcu;
        state->key[8u] &= 0xfcu;
        state->key[12u] &= 0xfcu;

        #if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)state->key,(int32_t)CY_CRYPTO_POLY1305_KEY_SIZE);

        SCB_InvalidateDCache_by_Addr((volatile void *)buffer,(int32_t)sizeof(cy_stc_crypto_poly_1305_buffers_t));
        #endif

        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}




/*******************************************************************************
* Function Name: Cy_Crypto_Core_poly_1305_Update
****************************************************************************//**
*
* The function to perform poly 1305 update.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param state
* The pointer to the poly 1305 state.
*
* \param p_message
* The pointer to the message.
*
* \param size
* The length of the message.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/

cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Update(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state, uint8_t const * p_message, uint32_t size)
{


    uint32_t copy_size=0u;
    uint32_t block_count=0u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_SUCCESS;
    uint8_t *p_messageRemap;
    uint8_t *partialMessageRemap;

    if ((NULL == state) || (NULL == p_message))
    {
      tmpResult = CY_CRYPTO_BAD_PARAMS;
    }

    if ((tmpResult == CY_CRYPTO_SUCCESS) && (size > 0UL))
    {

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)p_message,(int32_t)CY_CRYPTO_POLY1305_BLOCK_SIZE);
        SCB_CleanDCache_by_Addr((volatile void *)state->partialMessage,(int32_t)CY_CRYPTO_POLY1305_BLOCK_SIZE);
#endif

        p_messageRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_message);
        partialMessageRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(state->partialMessage);

        tmpResult = Cy_Crypto_Core_V2_poly_1305_load_ctx(base, state);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        if(state->messageIndex + size < CY_CRYPTO_POLY1305_BLOCK_SIZE)
        {
                Cy_Crypto_Core_V2_MemCpy(base, (void*)&partialMessageRemap[state->messageIndex], (void*)p_messageRemap, (uint16_t)size);
                state->messageIndex += size;
        }

        else
        {

            if(state->messageIndex != 0u)
            {
                copy_size = CY_CRYPTO_POLY1305_BLOCK_SIZE - state->messageIndex;
                Cy_Crypto_Core_V2_MemCpy(base, (void*)&partialMessageRemap[state->messageIndex], (void*)p_messageRemap, (uint16_t)copy_size);

                Cy_Crypto_Core_V2_poly_1305_calculate(base,  partialMessageRemap, CY_CRYPTO_POLY1305_BLOCK_SIZE);

                size = size - copy_size;
                p_messageRemap += copy_size;
                state->messageIndex = 0u;
            }


            block_count = size/CY_CRYPTO_AES_BLOCK_SIZE;
            Cy_Crypto_Core_V2_poly_1305_calculate(base,  p_messageRemap, block_count * CY_CRYPTO_POLY1305_BLOCK_SIZE);
            p_messageRemap += block_count * CY_CRYPTO_POLY1305_BLOCK_SIZE;

            if((size % CY_CRYPTO_POLY1305_BLOCK_SIZE) != 0u)
            {
                Cy_Crypto_Core_V2_MemCpy(base, (void*)partialMessageRemap, (void*)p_messageRemap, (uint16_t)(size % CY_CRYPTO_POLY1305_BLOCK_SIZE));
                state->messageIndex += size % CY_CRYPTO_POLY1305_BLOCK_SIZE;
            }

        }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_InvalidateDCache_by_Addr((volatile void *)state->partialMessage,(int32_t)CY_CRYPTO_POLY1305_BLOCK_SIZE);
#endif
        Cy_Crypto_Core_V2_poly_1305_store_ctx(base, state);
        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return tmpResult;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_poly_1305_Finish
****************************************************************************//**
*
* The function to finish the poly 1305 calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param state
* The pointer to the poly 1305 state.
*
* \param p_mac
* The pointer to the mac.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Finish(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state, uint8_t * p_mac)

{

    uint32_t destAddr;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *p_macRemap;
    uint8_t *partialMessageRemap;

    if((NULL != state) &&  (NULL != p_mac))
    {
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)state->partialMessage,(int32_t)CY_CRYPTO_POLY1305_BLOCK_SIZE);
#endif
        p_macRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_mac);
        partialMessageRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(&state->partialMessage[0u]);

        tmpResult = Cy_Crypto_Core_V2_poly_1305_load_ctx(base, state);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        if(state->messageIndex < CY_CRYPTO_POLY1305_BLOCK_SIZE)
        {
            Cy_Crypto_Core_V2_poly_1305_calculate(base,  partialMessageRemap,  state->messageIndex);
        }

        CY_CRYPTO_VU_SUB (base, POLY_1305_S_VREG, POLY_1305_S_VREG, POLY_1305_P_VREG);
        CY_CRYPTO_VU_COND_ADD (base, CY_CRYPTO_VU_COND_CC, POLY_1305_S_VREG, POLY_1305_S_VREG, POLY_1305_P_VREG);

        CY_CRYPTO_VU_ADD  (base, POLY_1305_S_VREG, POLY_1305_S_VREG, POLY_1305_K_VREG);

        destAddr = (uint32_t)Cy_Crypto_Core_Vu_RegMemPointer(base, POLY_1305_S_VREG);
        Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_LOAD0, (uint8_t*)destAddr, CY_CRYPTO_POLY1305_BLOCK_SIZE);
        Cy_Crypto_Core_V2_FFStart(base, CY_CRYPTO_V2_RB_FF_STORE, (uint8_t*)p_macRemap, CY_CRYPTO_POLY1305_BLOCK_SIZE);

        Cy_Crypto_Core_V2_BlockMov(base, CY_CRYPTO_V2_RB_FF_STORE, CY_CRYPTO_V2_RB_FF_LOAD0, CY_CRYPTO_POLY1305_BLOCK_SIZE);
        Cy_Crypto_Core_V2_poly_1305_store_ctx(base, state);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_InvalidateDCache_by_Addr((volatile void *)p_mac,(int32_t)CY_CRYPTO_POLY1305_BLOCK_SIZE);
#endif

        tmpResult = CY_CRYPTO_SUCCESS;

    }

    return tmpResult;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_poly_1305_Free
****************************************************************************//**
*
* The function to free the poly 1305 operation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param state
* The pointer to the poly 1305 state.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Free(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state)

{
    if((NULL != base) && (NULL != state))
    {
        if(NULL != state->state)
        {
            Cy_Crypto_Core_V2_MemSet(base, (void*)state->state, 0U, (uint16_t)sizeof(cy_stc_crypto_poly_1305_buffers_t));
        }
        Cy_Crypto_Core_V2_MemSet(base, (void*)state, 0U, (uint16_t)sizeof(cy_stc_crypto_poly_1305_state_t));
    }

    return CY_CRYPTO_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_poly_1305_mac
****************************************************************************//**
*
* The function to perform the poly 1305 mac calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param p_message
* The pointer to the message.
*
* \param size
* The length of the message.
*
*
* \param p_mac
* The pointer to the mac.
*
* \return
* \ref cy_en_crypto_status_t
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_mac(CRYPTO_Type *base, uint8_t const *key, uint8_t const * p_message, uint32_t size,  uint8_t * p_mac)

{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t state_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_poly_1305_state_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t buffer_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_poly_1305_buffers_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];

    /* Input parameters verification */
    if ((NULL == base) || (NULL == key) || ((NULL == p_message) && (size > 0u))
        ||  (NULL == p_mac) )
    {
        return status;
    }

    cy_stc_crypto_poly_1305_state_t *state = (cy_stc_crypto_poly_1305_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(state_t);
    cy_stc_crypto_poly_1305_buffers_t *buffer = (cy_stc_crypto_poly_1305_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(buffer_t);

    Cy_Crypto_Core_V2_MemSet(base, state, 0u, (uint16_t)sizeof(cy_stc_crypto_poly_1305_state_t));
    Cy_Crypto_Core_V2_MemSet(base, buffer, 0u, (uint16_t)sizeof(cy_stc_crypto_poly_1305_buffers_t));

    status = Cy_Crypto_Core_poly_1305_Init(base, key, state, buffer);

    if (CY_CRYPTO_SUCCESS == status)
    {

        status = Cy_Crypto_Core_poly_1305_Update(base, state, p_message, size);

    }

    if (CY_CRYPTO_SUCCESS == status)
    {

        status = Cy_Crypto_Core_poly_1305_Finish(base, state, p_mac);
    }

    if (CY_CRYPTO_SUCCESS == status)
    {

        status = Cy_Crypto_Core_poly_1305_Free(base, state);
    }


    return status;
}


#endif /* #if (CPUSS_CRYPTO_VU == 1)  && (CY_CRYPTO_CFG_POLY1305_ENABLED == 1)*/

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */


/* [] END OF FILE */

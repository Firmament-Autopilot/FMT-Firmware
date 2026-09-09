/***************************************************************************//**
* \file cy_crypto_core_hkdf_v2.c
* \version 2.150
*
* \brief
*  This file provides the source code to the API for the HKDF method
*  in the Crypto block driver.
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

#include "cy_crypto_core_hkdf_v2.h"

#if defined(CY_CRYPTO_CFG_HW_V2_ENABLE)

#if defined(__cplusplus)
extern "C" {
#endif

#if (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_HKDF_C)

#include "cy_crypto_core_hmac_v2.h"
#include "cy_crypto_core_mem_v2.h"
#include "cy_syslib.h"

static uint32_t Cy_Crypto_Core_sha_hashSize(cy_en_crypto_sha_mode_t mode)
{
    uint32_t hashSize=0UL;

    switch (mode)
    {
#if defined(CY_CRYPTO_CFG_SHA1_ENABLED)
    case CY_CRYPTO_MODE_SHA1:
        hashSize = CY_CRYPTO_SHA1_DIGEST_SIZE;
        break;
#endif
#if defined(CY_CRYPTO_CFG_SHA2_256_ENABLED)
    case CY_CRYPTO_MODE_SHA224:
        hashSize = CY_CRYPTO_SHA224_DIGEST_SIZE;
        break;
    case CY_CRYPTO_MODE_SHA256:
        hashSize = CY_CRYPTO_SHA256_DIGEST_SIZE;
        break;
#endif
#if defined(CY_CRYPTO_CFG_SHA2_512_ENABLED)
    case CY_CRYPTO_MODE_SHA384:
        hashSize = CY_CRYPTO_SHA384_DIGEST_SIZE;
        break;
    case CY_CRYPTO_MODE_SHA512:
        hashSize = CY_CRYPTO_SHA512_DIGEST_SIZE;
        break;
    case CY_CRYPTO_MODE_SHA512_224:
        hashSize = CY_CRYPTO_SHA512_224_DIGEST_SIZE;
        break;
    case CY_CRYPTO_MODE_SHA512_256:
        hashSize = CY_CRYPTO_SHA512_256_DIGEST_SIZE;
        break;
#endif
    default:
        hashSize = 0UL;
        break;
    }

    return hashSize;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Hkdf_Extract
****************************************************************************//**
*
* Performs HKDF Extract calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param mode
* \ref cy_en_crypto_sha_mode_t
*
* \param salt
* The pointer to salt.
*
* \param saltLength
* The size of a salt.
*
* \param ikm
* The pointer to the Input Key material.
*
* \param ikmLength
* The length of the IKM.
*
* \param prk
* The pointer to store the generated prk.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Hkdf_Extract(CRYPTO_Type *base, cy_en_crypto_sha_mode_t mode,
                                          uint8_t const *salt,
                                          uint32_t saltLength,
                                          uint8_t const  *ikm,
                                          uint32_t ikmLength,
                                          uint8_t *prk)
{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t nullSalt[CY_CRYPTO_SHA_MAX_HASH_SIZE] = {0u};
    uint8_t *saltptr;
    uint32_t  saltlen;

    /* Input parameters verification */
    if ((NULL == base) || (NULL == prk) || ((NULL == salt) && (0UL != saltLength))
        ||((NULL == ikm) && (0UL != ikmLength)))
    {
        return status;
    }

    saltptr = (uint8_t  *)salt;
    saltlen = saltLength;

    if(NULL == salt)
    {
        saltlen = Cy_Crypto_Core_sha_hashSize(mode);
        if(saltlen == 0UL)
        {
            return status;
        }

        saltptr = nullSalt;
    }

    return Cy_Crypto_Core_V2_Hmac(base, prk, ikm, ikmLength, saltptr, saltlen, mode);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Hkdf_Expand
****************************************************************************//**
*
* Performs HKDF Expand calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param mode
* \ref cy_en_crypto_sha_mode_t
*
* \param prk
* The pointer to the pseudo random key.
*
* \param prkLength
* The length of the prk.
*
* \param info
* The pointer to info.
*
* \param infoLength
* The length of the info.
*
* \param okm
* The pointer to Output key material.
*
* \param okmLength
* The length of okm to be generated.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Hkdf_Expand(CRYPTO_Type *base, cy_en_crypto_sha_mode_t mode,
                                          uint8_t const *prk,
                                          uint32_t prkLength,
                                          uint8_t const *info,
                                          uint32_t infoLength,
                                          uint8_t *okm,
                                          uint32_t okmLength)
{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint32_t  hashlen;
    uint32_t  n,i;
    uint8_t  counter=0u;
    uint32_t tLength=0u;
    uint32_t bytesCopy=0u;
    uint32_t offset=0u;
    uint8_t t_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_SHA_MAX_HASH_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t *t = (uint8_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(&t_t);
    uint8_t hmacState_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_hmac_state_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];
    uint8_t hmacBuffer_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_hmac_buffers_t))+CY_CRYPTO_DCAHCE_PADDING_SIZE];

    cy_stc_crypto_v2_hmac_buffers_t *hmacBuffer = (cy_stc_crypto_v2_hmac_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(hmacBuffer_t);
    cy_stc_crypto_hmac_state_t *hmacState = (cy_stc_crypto_hmac_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(hmacState_t);

    /* Input parameters verification */
    if ((NULL == base) || ((NULL == prk) && (0UL != prkLength)) || ((NULL == info) && (0UL != infoLength))
        ||((NULL == okm) && (0UL != okmLength)))
    {
        return status;
    }

    Cy_Crypto_Core_V2_MemSet(base, (void*)hmacState, 0x00U, (uint16_t)sizeof(cy_stc_crypto_hmac_state_t));
    Cy_Crypto_Core_V2_MemSet(base, (void*)hmacBuffer, 0x00U, (uint16_t)sizeof(cy_stc_crypto_v2_hmac_buffers_t));

    hashlen = Cy_Crypto_Core_sha_hashSize(mode);
    if(hashlen == 0u)
    {
        return status;
    }

    n = (okmLength + (hashlen - 1u))/ hashlen;

    if( n > 255u)
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    for(i=1u; i<=n; i++)
    {
        counter++;

        status = Cy_Crypto_Core_V2_Hmac_Init(base, hmacState, mode, hmacBuffer);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        status = Cy_Crypto_Core_V2_Hmac_Start(base, hmacState, prk, prkLength);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        status = Cy_Crypto_Core_V2_Hmac_Update(base, hmacState, t, tLength);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        status = Cy_Crypto_Core_V2_Hmac_Update(base, hmacState, info, infoLength);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        status = Cy_Crypto_Core_V2_Hmac_Update(base, hmacState, &counter, 1u);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        status =  Cy_Crypto_Core_V2_Hmac_Finish(base, hmacState, t);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        status =  Cy_Crypto_Core_V2_Hmac_Free(base, hmacState);
        if(status != CY_CRYPTO_SUCCESS)
        {
            break;
        }

        if(i != n)
        {
            bytesCopy = hashlen;
        }
        else
        {
            bytesCopy = okmLength - offset;
        }

        Cy_Crypto_Core_V2_MemCpy(base, (void*)(okm + offset), (void *)t, (uint16_t)bytesCopy);
        offset += hashlen;
        tLength = hashlen;
    }

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr((volatile void *)okm,(int32_t)okmLength);
#endif
    return status;
}



/*******************************************************************************
* Function Name: Cy_Crypto_Core_V2_Hkdf
****************************************************************************//**
*
* Performs HKDF calculation.
*
* \param base
* The pointer to the CRYPTO instance.
*
* \param mode
* \ref cy_en_crypto_sha_mode_t
*
* \param salt
* The pointer to salt.
*
* \param saltLength
* The size of a salt.
*
* \param ikm
* The pointer to the Input Key material.
*
* \param ikmLength
* The length of the IKM.
*
* \param info
* The pointer to info.
*
* \param infoLength
* The length of the info.
*
* \param okm
* The pointer to Output key material.
*
* \param okmLength
* The length of okm to be generated.
*
* \return
* \ref cy_en_crypto_status_t
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_V2_Hkdf(CRYPTO_Type *base, cy_en_crypto_sha_mode_t mode,
                                          uint8_t const *salt,
                                          uint32_t saltLength,
                                          uint8_t const *ikm,
                                          uint32_t ikmLength,
                                          uint8_t const *info,
                                          uint32_t infoLength,
                                          uint8_t *okm,
                                          uint32_t okmLength)
{
    cy_en_crypto_status_t status = CY_CRYPTO_BAD_PARAMS;
    uint8_t prk_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_SHA_MAX_HASH_SIZE)+CY_CRYPTO_DCAHCE_PADDING_SIZE] = {0u};
    uint8_t *prk = (uint8_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(&prk_t);

    /* Input parameters verification */
    if ((NULL == base) || ((NULL == salt) && (0UL != saltLength))
        ||((NULL == ikm) && (0UL != ikmLength)) || ((NULL == info) && (0UL != infoLength))
        ||((NULL == okm) && (0UL != okmLength)))
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Hkdf_Extract(base, mode, salt, saltLength, ikm, ikmLength, prk);
    if(status != CY_CRYPTO_SUCCESS)
    {
        return status;
    }

    status = Cy_Crypto_Core_V2_Hkdf_Expand(base, mode, prk, Cy_Crypto_Core_sha_hashSize(mode), info, infoLength, okm, okmLength);

    Cy_Crypto_Core_V2_MemSet(base, prk, 0u, CY_CRYPTO_SHA_MAX_HASH_SIZE);

    return status;
}

#endif /* (CPUSS_CRYPTO_SHA == 1) && defined(CY_CRYPTO_CFG_HKDF_C) */

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_CRYPTO_CFG_HW_V2_ENABLE) */

#endif /* defined(CY_IP_MXCRYPTO) */


/* [] END OF FILE */

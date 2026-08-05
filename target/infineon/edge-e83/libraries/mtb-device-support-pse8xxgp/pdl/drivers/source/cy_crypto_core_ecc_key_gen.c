/***************************************************************************//**
* \file cy_crypto_core_ecc_key_gen.c
* \version 2.150
*
* \brief
*  This file provides constant and parameters for the API for the ECC key
*  generations in the Crypto driver.
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

#include "cy_crypto_core_ecc.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CY_CRYPTO_CFG_ECDSA_C)

#include "cy_crypto_core_ecc_nist_p.h"
#include "cy_crypto_core_vu.h"

#if defined(CY_CRYPTO_CFG_ECDSA_GENKEY_C)
#include "cy_crypto_core_trng.h"

#define CY_ECC_CONFIG_TR_GARO_CTL      0x6C740B8DuL
#define CY_ECC_CONFIG_TR_FIRO_CTL      0x52D246E1uL

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ECC_MakeKeyPair
****************************************************************************//**
*
* Make a new ECC key pair.
*
* When D-Cache is enabled parameter key(k, x&y) must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param key
* [out] Destination of the newly created key. See \ref cy_stc_crypto_ecc_key.
*
* \param GetRandomDataFunc
* See \ref cy_func_get_random_data_t.
*
* \param randomDataInfo
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ECC_MakeKeyPair(CRYPTO_Type *base,
        cy_en_crypto_ecc_curve_id_t curveID,
        cy_stc_crypto_ecc_key *key,
        cy_func_get_random_data_t GetRandomDataFunc,
        void *randomDataInfo)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    if ((key != NULL) && (key->k != NULL) && (key->pubkey.x != NULL))
    {
        if(curveID == CY_CRYPTO_ECC_ECP_EC25519)
        {
            tmpResult = Cy_Crypto_Core_EC25519_MakePrivateKey(base, key->k, GetRandomDataFunc, randomDataInfo);
            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                tmpResult = Cy_Crypto_Core_EC25519_MakePublicKey(base, (const uint8_t *)key->k, key);
                key->type = PK_PRIVATE;
            }
        }
        else if(key->pubkey.y != NULL)
        {
            tmpResult = Cy_Crypto_Core_ECC_MakePrivateKey(base, curveID, key->k, GetRandomDataFunc, randomDataInfo);
            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                tmpResult = Cy_Crypto_Core_ECC_MakePublicKey(base, curveID, key->k, key);
                key->type = PK_PRIVATE;
            }
        }
        else
        {
        }
    }

    return (tmpResult);
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_ECC_MakePrivateKey
****************************************************************************//**
*
* Make a new ECC private key
*
* When D-Cache is enabled parameter key must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param key
* [out] Destination of the newly created key.
*
* \param GetRandomDataFunc
* See \ref cy_func_get_random_data_t.
*
* \param randomDataInfo
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ECC_MakePrivateKey(CRYPTO_Type *base,
        cy_en_crypto_ecc_curve_id_t curveID,
        uint8_t *key,
        cy_func_get_random_data_t GetRandomDataFunc, void *randomDataInfo)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t *keyRemap;

    const cy_stc_crypto_ecc_dp_type *eccDp = Cy_Crypto_Core_ECC_GetCurveParams(curveID);

    if ((eccDp != NULL) && (key != NULL))
    {
        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key);

        uint32_t bitsize = eccDp->size;
        uint32_t bytesize = CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize);

        uint32_t p_temp = 8u;     /* temporal values */
        uint32_t p_key  = 9u;     /* private key */

        /* Load random data into VU */
        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_D, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }
        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_key, bytesize * 8u);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }
        /* generate random string */
        #if (CY_CPU_CORTEX_M55)
            uint32_t *keyRegPtr = (uint32_t *)CY_REMAP_ADDRESS_FOR_CPU(Cy_Crypto_Core_Vu_RegMemPointer(base, p_key));
        #else
            uint32_t *keyRegPtr = Cy_Crypto_Core_Vu_RegMemPointer(base, p_key);
        #endif

        if (GetRandomDataFunc != NULL)
        {
            if (GetRandomDataFunc( randomDataInfo, (uint8_t *)keyRegPtr, bytesize ) != 0)
            {
                tmpResult = CY_CRYPTO_HW_ERROR;
            }
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            /* Flush the cache */
            SCB_CleanDCache_by_Addr((volatile void *)key,(int32_t)bytesize);
#endif
        }
        else
        {
            #if defined(CY_CRYPTO_CFG_TRNG_C)
            uint32_t i = 0U;
            int32_t randomsize = (int32_t)bitsize;
            cy_en_crypto_status_t status = CY_CRYPTO_SUCCESS;

            while ((randomsize > 0) && (CY_CRYPTO_SUCCESS == status))
            {
                uint32_t randombits = (uint32_t)CY_CRYPTO_MIN(randomsize, (int32_t)CY_CRYPTO_HW_REGS_WIDTH);

                status = Cy_Crypto_Core_Trng(base, CY_ECC_CONFIG_TR_GARO_CTL, CY_ECC_CONFIG_TR_FIRO_CTL,
                                                   randombits, &(keyRegPtr)[i]);
                randomsize -= (int32_t)CY_CRYPTO_HW_REGS_WIDTH;
                i++;

                if (CY_CRYPTO_SUCCESS != status)
                {
                    tmpResult = CY_CRYPTO_HW_ERROR;
                }
            }
            #else
            tmpResult = CY_CRYPTO_NOT_SUPPORTED;
            #endif
        }

        if (CY_CRYPTO_SUCCESS == tmpResult)
        {
            Cy_Crypto_Core_VU_RegInvertEndianness(base, p_key);

            if ((bytesize * 8u) > bitsize)
            {
                /* Shift random data right */
                CY_CRYPTO_VU_SET_REG(base, p_temp, (bytesize * 8u) - bitsize, 1u);
                CY_CRYPTO_VU_LSR(base, p_key, p_key, p_temp);
            }

            CY_CRYPTO_VU_MOV(base, VR_D, p_key);
            Cy_Crypto_Core_Vu_WaitForComplete(base);

            /* load prime and order defining the curve as well as the barrett coefficient. */
            /* P and BARRETT_U are "globally" defined in cy_crypto_core_ecc.h */
            tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_P, bitsize);
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            Cy_Crypto_Core_Vu_SetMemValue (base, VR_P, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->order), bitsize);

            /* check that key is smaller than the order of the base point */
            if (!Cy_Crypto_Core_Vu_IsRegLess(base, VR_D, VR_P))
            {
                /* private key (random data) >= order, needs reduction */
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_BARRETT, bitsize + 1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_BARRETT, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->barrett_o), bitsize + 1u);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_temp, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                CY_CRYPTO_VU_MOV(base, p_temp, VR_D);

                /* use Barrett reduction algorithm for operations modulo n (order of the base point) */
                Cy_Crypto_Core_EC_NistP_SetRedAlg(eccDp->algo);
                Cy_Crypto_Core_EC_NistP_SetMode(bitsize);

                /* z = x % mod */
                tmpResult = Cy_Crypto_Core_EC_Bar_MulRed(base, VR_D, p_temp, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(VR_BARRETT) |
                                            CY_CRYPTO_VU_REG_BIT(p_temp));
            }

            CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(VR_P));

            Cy_Crypto_Core_Vu_GetMemValue(base, (uint8_t *)keyRemap, VR_D, bitsize);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            SCB_InvalidateDCache_by_Addr(key, (int32_t)bytesize);
#endif
            tmpResult = CY_CRYPTO_SUCCESS;
        }

        CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(VR_D) | CY_CRYPTO_VU_REG_BIT(p_key));
    }

    return (tmpResult);
}
#endif /* defined(CY_CRYPTO_CFG_ECDSA_GENKEY_C) */

#if defined(CY_CRYPTO_CFG_ECDSA_GENKEY_C) || defined(CY_CRYPTO_CFG_ECDSA_SIGN_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_ECC_MakePublicKey
****************************************************************************//**
*
* Make a new ECC public key
*
* When D-Cache is enabled parameters privateKey and  x & y  of publicKey must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param privateKey
* [out] Destination of the newly created key.
*
* \param publicKey
* See \ref cy_stc_crypto_ecc_key.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ECC_MakePublicKey(CRYPTO_Type *base,
        cy_en_crypto_ecc_curve_id_t curveID,
        const uint8_t *privateKey,
        cy_stc_crypto_ecc_key *publicKey)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t * privateKeyRemap;
    uint8_t * publicKeyXRemap;
    uint8_t * publicKeyYRemap;

    cy_stc_crypto_ecc_dp_type *eccDp = Cy_Crypto_Core_ECC_GetCurveParams(curveID);

    if ((eccDp != NULL) && (privateKey != NULL) && (publicKey != NULL) &&
        (publicKey->pubkey.x != NULL) && (publicKey->pubkey.y != NULL))
    {

        privateKeyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(privateKey);
        publicKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.x);
        publicKeyYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.y);

        uint32_t bitsize = eccDp->size;

        uint32_t p_order = 9u;    /* order of the curve */
        uint32_t p_d = 10u;       /* private key */
        uint32_t p_x = 11u;       /* x coordinate */
        uint32_t p_y = 12u;       /* y coordinate */
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)privateKey,(int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
#endif
        /* make the public key
         * EC scalar multiplication - X,Y-only co-Z arithmetic
         */
        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_P, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_order, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_BARRETT, bitsize + 1u);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_x, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_y, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        /* Apply domain parameters */
        /* load prime and order defining the curve as well as the barrett coefficient. */
        /* P and BARRETT_U are "globally" defined in cy_crypto_core_ecc.h */
        Cy_Crypto_Core_Vu_SetMemValue (base, VR_P, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->prime), bitsize);
        Cy_Crypto_Core_Vu_SetMemValue (base, p_order, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->order), bitsize);
        Cy_Crypto_Core_Vu_SetMemValue (base, VR_BARRETT, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->barrett_p), bitsize + 1u);

        /*Base Point, G = (p_x, p_y) */
        Cy_Crypto_Core_Vu_SetMemValue (base, p_x, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->Gx), bitsize);
        Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->Gy), bitsize);

        Cy_Crypto_Core_EC_NistP_SetMode(bitsize);
        Cy_Crypto_Core_EC_NistP_SetRedAlg(eccDp->algo);

        /* Load private key */
        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_d, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        Cy_Crypto_Core_Vu_SetMemValue(base, p_d, (uint8_t *)privateKeyRemap, bitsize);

        tmpResult = Cy_Crypto_Core_EC_NistP_PointMul(base, p_x, p_y, p_d, p_order, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        Cy_Crypto_Core_Vu_GetMemValue(base, (uint8_t *)publicKeyXRemap, p_x, bitsize);
        Cy_Crypto_Core_Vu_GetMemValue(base, (uint8_t *)publicKeyYRemap, p_y, bitsize);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        SCB_InvalidateDCache_by_Addr(publicKey->pubkey.x, (int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
        SCB_InvalidateDCache_by_Addr(publicKey->pubkey.y, (int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
#endif
        publicKey->type = PK_PUBLIC;
        publicKey->curveID = curveID;

        CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(VR_P) |
                                    CY_CRYPTO_VU_REG_BIT(p_order) | CY_CRYPTO_VU_REG_BIT(VR_BARRETT) |
                                    CY_CRYPTO_VU_REG_BIT(p_x) | CY_CRYPTO_VU_REG_BIT(p_y) |
                                    CY_CRYPTO_VU_REG_BIT(p_d));

        tmpResult = CY_CRYPTO_SUCCESS;
    }

    return (tmpResult);
}
#endif /* defined(CY_CRYPTO_CFG_ECDSA_GENKEY_C) || defined(CY_CRYPTO_CFG_ECDSA_SIGN_C) */


/*******************************************************************************
* Function Name: Cy_Crypto_Core_ECC_CheckPublicKey
****************************************************************************//**
*
* Validate an ECC public key
*
* When D-Cache is enabled parameters privateKey and  x & y  of publicKey must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param publicKey
* See \ref cy_stc_crypto_ecc_key.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ECC_CheckPublicKey(CRYPTO_Type *base,
        cy_en_crypto_ecc_curve_id_t curveID,
        cy_stc_crypto_ecc_key *publicKey)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    uint8_t * publicKeyXRemap;
    uint8_t * publicKeyYRemap;

    cy_stc_crypto_ecc_dp_type *eccDp = Cy_Crypto_Core_ECC_GetCurveParams(curveID);

    if ((eccDp != NULL) && (publicKey != NULL) &&
        (publicKey->pubkey.x != NULL) && (publicKey->pubkey.y != NULL))
    {

        publicKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.x);
        publicKeyYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.y);

        uint32_t bitsize = eccDp->size;

        uint32_t p_temp = 8u;    /* temp */
        uint32_t p_lhs = 9u;     /* LHS */
        uint32_t p_rhs = 10u;    /* RHS */
        uint32_t p_x = 11u;      /* x coordinate */
        uint32_t p_y = 12u;      /* y coordinate */
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
        /* Flush the cache */
        SCB_CleanDCache_by_Addr((volatile void *)publicKey->pubkey.x,(int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
        SCB_CleanDCache_by_Addr((volatile void *)publicKey->pubkey.y,(int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
#endif

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_P, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_temp, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, VR_BARRETT, bitsize + 1u);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_lhs, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_rhs, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_x, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_y, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        /* Apply domain parameters */
        /* load prime and order defining the curve as well as the barrett coefficient. */
        /* P and BARRETT_U are "globally" defined in cy_crypto_core_ecc.h */
        Cy_Crypto_Core_Vu_SetMemValue (base, VR_P, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->prime), bitsize);
        Cy_Crypto_Core_Vu_SetMemValue (base, VR_BARRETT, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->barrett_p), bitsize + 1u);

        /*
        * Check that an affine point is valid as a public key,
        * short weierstrass curves (SEC1 3.2.3.1)
        */
        /*validate x and y point boundary*/
        Cy_Crypto_Core_Vu_SetMemValue (base, p_x, (uint8_t const *)publicKeyXRemap, bitsize);
        Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)publicKeyYRemap, bitsize);

        if (Cy_Crypto_Core_Vu_IsRegZero(base, p_x))
        {
            /* x is zero!!! */
            return CY_CRYPTO_BAD_PARAMS;
        }
        if (!Cy_Crypto_Core_Vu_IsRegLess(base, p_x, VR_P))
        {
            /* x is not less than n!!! */
            return CY_CRYPTO_BAD_PARAMS;
        }
        if (Cy_Crypto_Core_Vu_IsRegZero(base, p_y))
        {
            /* y is zero!!! */
            return CY_CRYPTO_BAD_PARAMS;
        }
        if (!Cy_Crypto_Core_Vu_IsRegLess(base, p_y, VR_P))
        {
            /* y is not less than n!!! */
            return CY_CRYPTO_BAD_PARAMS;
        }

        /* compute and check if LHS == RHS for the given public key
        * LHS = Y^2
        * RHS = X (X^2 + A) + B = X^3 + A X + B
        */

        tmpResult = Cy_Crypto_Core_EC_SquareMod( base, p_lhs, p_y, bitsize);       /* lhs = Y^2 */
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        tmpResult = Cy_Crypto_Core_EC_SquareMod( base, p_rhs, p_x, bitsize);       /* rhs = X^2 */
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }
        /* (X^2 + A)*/
        Cy_Crypto_Core_Vu_SetMemValue (base, p_temp, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->a), bitsize);
        Cy_Crypto_Core_EC_AddMod( base, p_rhs, p_rhs, p_temp);
        /* X (X^2 + A) */
        tmpResult = Cy_Crypto_Core_EC_MulMod( base, p_rhs, p_rhs, p_x, bitsize);
        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }
        /* RHS = X^3 + A X + B */
        Cy_Crypto_Core_Vu_SetMemValue (base, p_temp, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(eccDp->b), bitsize);
        Cy_Crypto_Core_EC_AddMod( base, p_rhs, p_rhs, p_temp);
        /* check LHS == RHS*/
        if (Cy_Crypto_Core_Vu_IsRegEqual(base, p_lhs, p_rhs))
        {
            /* LHS != RHS */
            tmpResult = CY_CRYPTO_SUCCESS;
        }
        else
        {
            tmpResult = CY_CRYPTO_BAD_PARAMS;
        }
        CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(VR_P) |
                                    CY_CRYPTO_VU_REG_BIT(p_temp) | CY_CRYPTO_VU_REG_BIT(VR_BARRETT) |
                                    CY_CRYPTO_VU_REG_BIT(p_x) | CY_CRYPTO_VU_REG_BIT(p_y) |
                                    CY_CRYPTO_VU_REG_BIT(p_lhs) | CY_CRYPTO_VU_REG_BIT(p_rhs));
    }

    return (tmpResult);
}
#endif /* defined(CY_CRYPTO_CFG_ECDSA_C) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */


/* [] END OF FILE */

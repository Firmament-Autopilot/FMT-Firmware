/***************************************************************************//**
* \file cy_crypto_core_ecc_ec25519.c
* \version 2.150
*
* \brief
*  This file provides constant and parameters for the API for the ECC EC25519
*  in the Crypto driver. EC25519 is used for ECDH
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
#include "stdio.h"
#if defined (CY_IP_MXCRYPTO)

#include "cy_crypto_core_ecc.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CY_CRYPTO_CFG_EC25519_C)

#include "cy_crypto_core_ecc_nist_p.h"
#include "cy_crypto_core_mem.h"
#include "cy_crypto_core_vu.h"

#if defined(CY_CRYPTO_CFG_EC25519_GENKEY_C)
#include "cy_crypto_core_trng.h"

#define CY_ECC_CONFIG_TR_GARO_CTL      0x6C740B8DuL
#define CY_ECC_CONFIG_TR_FIRO_CTL      0x52D246E1uL
#endif

cy_en_crypto_status_t Cy_Crypto_Core_EC25519_Mont_ladder (CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp,
                                        uint32_t p_gx,
                                        uint32_t p_d,
                                        uint32_t p_x,
                                        uint32_t p_z );

/* curve const a24 size in bits*/
#define CY_ECC_EC25519_CURVE_SIZE_A (17u)

/*******************************************************************************
* Function Name: Cy_Crypto_Core_EC25519_Mont_ladder
****************************************************************************//**
*
* EC 25519 multiplication with montgomery ladder
*
* \param base
* The pointer to a Crypto instance.
*
* \param edwDp
* Structure defining domain parameters
*
* \param p_gx
* Register index for curve base point x.
*
* \param p_d
* Register index for Scalar value.
*
* \param p_x
* Register index for output x buffer of bit size value.
*
* \param p_z
* Register index for output z buffer of bit size value.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_EC25519_Mont_ladder (CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp,
                                        uint32_t p_gx,
                                        uint32_t p_d,
                                        uint32_t p_x,
                                        uint32_t p_z )
{
   uint32_t i;
   uint8_t bit_curr;
   uint32_t bitsize = edwDp->size;
   uint32_t bitpos;
   uint8_t swap;
   uint8_t *pd_ptr;
   cy_en_crypto_status_t tmpResult = CY_CRYPTO_NOT_SUPPORTED;
   /* Do not use REG 5,6 and 7, these are alloc for arg pg_x,p_x and p_z*/
   uint32_t t1 = 4;
   uint32_t t2 = 8;
   uint32_t a  = 9;
   uint32_t x2 = p_x;
   uint32_t x1 = p_gx;
   uint32_t z2 = p_z;
   uint32_t x3 = 10;
   uint32_t z3 = 11;

   CY_CRYPTO_VU_PUSH_REG (base);

    pd_ptr = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_d);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t1, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t2, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, a, CY_ECC_EC25519_CURVE_SIZE_A);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, x3, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, z3, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Crypto_Core_Vu_SetMemValue (base, a, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->a), CY_ECC_EC25519_CURVE_SIZE_A);

    /* compute r = (u*d)mod p */
    /*x1 = u, x2=1, x3=u, z2=0, z3=1*/
    CY_CRYPTO_VU_SET_TO_ONE (base, x2);
    CY_CRYPTO_VU_SET_TO_ZERO (base, z2);
    CY_CRYPTO_VU_MOV (base, x3, x1);
    CY_CRYPTO_VU_SET_TO_ONE (base, z3);
    swap = 0u;
    bitpos = CY_CRYPTO_ECC_EC25519_SIZE-1u;

    for (i = CY_CRYPTO_ECC_EC25519_SIZE; i > 0u; i--)
    {
        bit_curr = (pd_ptr[bitpos >> 3u] >> (bitpos & 7u)) & 1u;
        bitpos--;
        swap = bit_curr ^ swap;

        CY_CRYPTO_VU_MOV_IMM_TO_STATUS(base, swap);
        CY_CRYPTO_VU_COND_SWAP_REG( base, CY_CRYPTO_VU_COND_CS, x2, x3);
        CY_CRYPTO_VU_COND_SWAP_REG( base, CY_CRYPTO_VU_COND_CS, z2, z3);

        swap = bit_curr;

        /*A = x_2 + z_2*/
        Cy_Crypto_Core_EC_AddMod( base, t1, x2, z2);
        /*B = x_2 - z_2*/
        Cy_Crypto_Core_EC_SubMod( base, t2, x2, z2);
        /*C = x_3 + z_3*/
        Cy_Crypto_Core_EC_AddMod( base, x2, x3, z3);
        /*D = x_3 - z_3*/
        Cy_Crypto_Core_EC_SubMod( base, z2, x3, z3);
        /*DA = D * A*/
        (void)Cy_Crypto_Core_ED25519_MulMod( base, z3, t1, z2, bitsize);
        /*CB = C * B*/
        (void)Cy_Crypto_Core_ED25519_MulMod( base, x3, t2, x2, bitsize);
        /*BB = B * B*/
        (void)Cy_Crypto_Core_ED25519_SquareMod( base, z2, t2, bitsize);
        /*AA = A * A*/
        (void)Cy_Crypto_Core_ED25519_SquareMod( base, t2, t1, bitsize);
        /*x_2 = AA * BB*/
        (void)Cy_Crypto_Core_ED25519_MulMod( base, x2, t2, z2, bitsize);
        /*E = AA - BB*/
        Cy_Crypto_Core_EC_SubMod (base, t1, t2, z2);
        /*(DA + CB)*/
        Cy_Crypto_Core_EC_AddMod( base, z2, x3, z3);
        /*(DA - CB)*/
        Cy_Crypto_Core_EC_SubMod (base, z3, x3, z3);
        /*(DA + CB)^2*/
        (void)Cy_Crypto_Core_ED25519_SquareMod(base, x3, z2, bitsize);//x2 to 3
        /*(DA - CB)^2*/
        (void)Cy_Crypto_Core_ED25519_SquareMod(base, z2, z3, bitsize);
        /*z_3 = x_1 * (DA - CB)^2*/
        (void)Cy_Crypto_Core_ED25519_MulMod(base, z3, z2, x1, bitsize);
        /*z_2 = E * (AA + a24 * E)*/
        (void)Cy_Crypto_Core_ED25519_MulMod( base, z2, t1, a, bitsize);
        Cy_Crypto_Core_EC_AddMod( base, t2, t2, z2);
        (void)Cy_Crypto_Core_ED25519_MulMod( base, z2, t1, t2, bitsize);
    }

    CY_CRYPTO_VU_MOV_IMM_TO_STATUS(base, swap);

    CY_CRYPTO_VU_COND_SWAP_REG( base, CY_CRYPTO_VU_COND_CS, x2, x3);
    CY_CRYPTO_VU_COND_SWAP_REG( base, CY_CRYPTO_VU_COND_CS, z2, z3);

    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(t1) | CY_CRYPTO_VU_REG_BIT(t2) |
                             CY_CRYPTO_VU_REG_BIT(x3) | CY_CRYPTO_VU_REG_BIT(z3) |
                             CY_CRYPTO_VU_REG_BIT(a));

    Cy_Crypto_Core_Vu_WaitForComplete(base);
    CY_CRYPTO_VU_POP_REG (base);

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_EC25519_PointMultiplication
****************************************************************************//**
*
* EC25519 Elliptic curve point multiplication in GF(p).
*
* When D-Cache is enabled parameter p_r, p_x and p_d must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param p_r
* Pointer to result point.
*
* \param p_x
* Pointer to X coordinate of base point.
*
* \param p_d
* Pointer to Scalar multiplication value.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_EC25519_PointMultiplication(CRYPTO_Type *base, uint8_t *p_r, const uint8_t *p_x, const uint8_t *p_d)
{
    /* Note: Pre conditions 0 < px, py < p-1 (consider randomizing the base point)*/
    /* DCache coherency for p_x,p_d and p_r are done by calls to Cy_Crypto_Core_Vu_SetMemValue and Cy_Crypto_Core_Vu_GetMemValue
       no separate cache clean/invalidate required **/

    uint32_t bitsize;
    uint8_t *pr_Remap;
    uint8_t *px_Remap;
    uint8_t *pd_Remap;
    uint8_t *pd_ptr;
    cy_stc_crypto_edw_dp_type edwDp_t;
    cy_stc_crypto_edw_dp_type *edwDp = &edwDp_t;

    uint32_t my_p_x  = 5u;
    uint32_t my_s_z  = 6u;
    uint32_t my_t_x  = 7u;
    uint32_t my_d   = 9u;

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    if(CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDW_GetCurveParams(edwDp, CY_CRYPTO_ECC_ECP_EC25519))
    {
        return CY_CRYPTO_NOT_SUPPORTED;
    }

    if( p_r == NULL || p_x == NULL || p_d == NULL )
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    pr_Remap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_r);
    px_Remap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_x);
    pd_Remap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(p_d);

    CY_CRYPTO_VU_PUSH_REG (base);

    bitsize = edwDp->size;

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, my_p_x, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    Cy_Crypto_Core_Vu_SetMemValue (base, my_p_x, (uint8_t const *)px_Remap, bitsize);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, my_d, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    Cy_Crypto_Core_Vu_SetMemValue (base, my_d, (uint8_t const *)pd_Remap, bitsize);


    pd_ptr = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, my_d);
    /* Decode scalar(RFC-7748 sec-5)*/
    /* For EC25519, in order to decode 32 random bytes as an integer scalar, set the three
    least significant bits of the first byte and the most significant bit of the last to zero,
    set the second most significant bit of the last byte to 1 and, finally, decode as little-endian.
    */
    pd_ptr[31] &= 0xF8u;
    pd_ptr[0]  &= 0x7Fu;
    pd_ptr[0]  |= 0x40u;

    Cy_Crypto_Core_InvertEndianness((void *)pd_ptr, (uint32_t)CY_CRYPTO_ECC_ED25519_BYTE_SIZE);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, my_s_z, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, my_t_x, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* load prime defining the curve as well as the barrett coefficient. */
    /* VR_P and VR_BARRETT_U are "globally" defined in cy_crypto_core_ecc.h */
    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_P, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    Cy_Crypto_Core_Vu_SetMemValue (base, VR_P, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->prime), bitsize);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_BARRETT, edwDp->barret_psize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    Cy_Crypto_Core_Vu_SetMemValue (base, VR_BARRETT, (uint8_t const*)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->barrett_p), edwDp->barret_psize);


    /*point mul using montgomery ladder*/
    tmpResult = Cy_Crypto_Core_EC25519_Mont_ladder (base, edwDp, my_p_x, my_d, my_t_x, my_s_z);

    if(CY_CRYPTO_SUCCESS == tmpResult)
    {
        /* Inverse transform (re-uses my_d and my_p_x) */
        /* t1 = 1 */
        CY_CRYPTO_VU_SET_TO_ONE (base, my_p_x);
        /* t2 = 1/Z */
        tmpResult = Cy_Crypto_Core_EC_DivMod( base, my_d, my_p_x, my_s_z, bitsize);
        /* my_p_x = X/Z */
        if(CY_CRYPTO_SUCCESS == tmpResult)
        {
            tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_p_x, my_t_x, my_d, bitsize);
        }
    }
    /* get result in p_r */
    Cy_Crypto_Core_Vu_GetMemValue(base, pr_Remap, my_p_x, bitsize);

    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(my_s_z) | CY_CRYPTO_VU_REG_BIT(my_t_x)|
                                 CY_CRYPTO_VU_REG_BIT(my_d)   | CY_CRYPTO_VU_REG_BIT(my_p_x)|
                                 CY_CRYPTO_VU_REG_BIT(VR_P)   | CY_CRYPTO_VU_REG_BIT(VR_BARRETT));

    Cy_Crypto_Core_Vu_WaitForComplete(base);
    CY_CRYPTO_VU_POP_REG (base);

    return tmpResult;
}

#if defined (CY_CRYPTO_CFG_EC25519_GENKEY_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_EC25519_MakePrivateKey
****************************************************************************//**
*
* Make a new EC25519 private key
*
* When D-Cache is enabled parameter key must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
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
cy_en_crypto_status_t Cy_Crypto_Core_EC25519_MakePrivateKey(CRYPTO_Type *base,
        uint8_t *key,
        cy_func_get_random_data_t GetRandomDataFunc, void *randomDataInfo)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    cy_en_crypto_ecc_curve_id_t curveID = CY_CRYPTO_ECC_ECP_EC25519;
    cy_stc_crypto_edw_dp_type edwDp_t;
    cy_stc_crypto_edw_dp_type *edwDp = &edwDp_t;
    uint8_t *keyRemap;

    if(CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDW_GetCurveParams(edwDp, curveID))
    {
        return CY_CRYPTO_NOT_SUPPORTED;
    }

    if (key != NULL)
    {
        keyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key);

        uint32_t bitsize = edwDp->size;
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
        uint32_t *keyRegPtr = Cy_Crypto_Core_Vu_RegMemPointer(base, p_key);

        if (GetRandomDataFunc != NULL)
        {
            if (GetRandomDataFunc( randomDataInfo, (uint8_t *)keyRegPtr, bytesize ) != 0)
            {
                tmpResult = CY_CRYPTO_HW_ERROR;
            }
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
            uint8_t *pd_ptr = (uint8_t*)keyRegPtr;

            Cy_Crypto_Core_VU_RegInvertEndianness(base, p_key);
            /* [Curve25519] page 5 */
            /* Generate a (bitsize+1)-bit random number by generating just enough
             * random bytes, then shifting out extra bits from the top (necessary
             * when (bitsize+1) is not a multiple of 8). */
            if ((bytesize * 8u) > bitsize)
            {
                /* Shift random data right */
                CY_CRYPTO_VU_SET_REG(base, p_temp, (bytesize * 8u) - bitsize, 1u);
                CY_CRYPTO_VU_LSR(base, p_key, p_key, p_temp);
            }
            Cy_Crypto_Core_Vu_WaitForComplete(base);

            /* Make sure the 255 bit is set and least three bits are unset for Curve25519 */
            pd_ptr[0]  &= 0xF8u;
            pd_ptr[31] &= 0x7Fu;
            pd_ptr[31] |= 0x40u;

            Cy_Crypto_Core_Vu_GetMemValue(base, (uint8_t *)keyRemap, p_key, bitsize);
            tmpResult = CY_CRYPTO_SUCCESS;
        }

        CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(VR_D) | CY_CRYPTO_VU_REG_BIT(p_key));
    }

    return (tmpResult);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_EC25519_MakePublicKey
****************************************************************************//**
*
* Make a new EC25519 public key
*
* When D-Cache is enabled parameters privateKey and  x of publicKey must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
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
cy_en_crypto_status_t Cy_Crypto_Core_EC25519_MakePublicKey(CRYPTO_Type *base,
        const uint8_t *privateKey,
        cy_stc_crypto_ecc_key *publicKey)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;
    cy_en_crypto_ecc_curve_id_t curveID = CY_CRYPTO_ECC_ECP_EC25519;
    uint8_t * privateKeyRemap;
    uint8_t * publicKeyXRemap;
    uint8_t * curvebasexRemap;
    cy_stc_crypto_edw_dp_type edwDp_t;
    cy_stc_crypto_edw_dp_type *edwDp = &edwDp_t;

    if(CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDW_GetCurveParams(edwDp, curveID))
    {
        return CY_CRYPTO_NOT_SUPPORTED;
    }

    if ((privateKey != NULL) && (publicKey != NULL) && (publicKey->pubkey.x != NULL))
    {
        privateKeyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(privateKey);
        publicKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.x);
        curvebasexRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gx);

        /* make the public key EC scalar multiplication - X-only co-Z arithmetic */
        tmpResult = Cy_Crypto_Core_EC25519_PointMultiplication( base, publicKeyXRemap, (uint8_t const *)curvebasexRemap, (const uint8_t *)privateKeyRemap);

        publicKey->type = PK_PUBLIC;
        publicKey->curveID = curveID;
    }

    return tmpResult;
}
#endif /* defined (CY_CRYPTO_CFG_EC25519_GENKEY_C) */

#endif /* defined(CY_CRYPTO_CFG_EC25519_C) */
#endif /* defined (CY_IP_MXCRYPTO) */

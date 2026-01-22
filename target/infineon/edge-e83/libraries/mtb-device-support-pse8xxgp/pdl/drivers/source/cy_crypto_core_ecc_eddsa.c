/***************************************************************************//**
* \file cy_crypto_core_ecc_eddsa.c
* \version 2.150
*
* \brief
*  This file provides constant and parameters for the API for the ECC EDDSA
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

#include "cy_crypto_core_sha.h"
#include "cy_crypto_core_ecc.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CY_CRYPTO_CFG_EDDSA_C) || defined(CY_CRYPTO_CFG_EC25519_C)

#include "cy_crypto_core_ecc_nist_p.h"
#include "cy_crypto_core_mem.h"
#include "cy_crypto_core_vu.h"

cy_en_crypto_status_t Cy_Crypto_Core_ED25519_ExpMod(CRYPTO_Type *base, uint32_t p_x, uint32_t p_y, uint32_t p_e, uint32_t bitsize);
cy_en_crypto_status_t Cy_Crypto_Core_ED25519Add(CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp, uint32_t s_x,
                                                uint32_t s_y, uint32_t s_z,
                                                uint32_t t_x, uint32_t t_y,
                                                uint32_t size);
cy_en_crypto_status_t Cy_Crypto_Core_ED25519Double(CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp, uint32_t s_x,
                                                uint32_t s_y, uint32_t s_z,
                                                uint32_t size);
cy_en_crypto_status_t Cy_Crypto_Core_ED25519InvTransform(CRYPTO_Type *base, uint32_t s_x, uint32_t s_y, uint32_t s_z, uint32_t size);
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_PointMul(CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp, uint32_t p_x, uint32_t p_y,
                                                uint32_t p_d, uint32_t bitsize);
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_PointMulAdd(CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp,
                                                        uint32_t p_x, uint32_t p_y, uint32_t s,
                                                        uint32_t q_x, uint32_t q_y, uint32_t h,
                                                        uint32_t bitsize);


#define CY_ED25519SIG_VERIFY_PASS (0xA1A1A1A1u)
#define CY_ED25519SIG_VERIFY_FAIL (0x00BADBADu)

/*******************************************************************************
* Function Name: Cy_Crypto_Core_EDDSA_Bar_MulRed
****************************************************************************//**
*
* Barrett multiplication modular reduction.
* r = t mod p for known value of p
* r = t - (floor[t * 1/p]*p)
* VR_BARRET = | (1 << 2*bitsize)/ p |
* q = floor([t * VR_BARRETT] >> 2*bitsize)
* r = t - p*q
*
* r = IF (r >= p) r = r - p           - reduce r using mod
* r = IF (r >= p) r = r - p
*
* \param base
* The pointer to a Crypto instance.
*
* \param z
* Register index for Barrett reduced value.
*
* \param x
* Register index for non reduced value.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_EDDSA_Bar_MulRed(CRYPTO_Type *base,
    uint32_t z,
    uint32_t x,
    uint32_t size)
{

    uint32_t sh          = 0u;
    uint32_t t1          = 1u;
    uint32_t t1_plus2    = 3u;
    uint32_t t2_plus2    = 4u;
    uint32_t t_double    = 5u;
    uint32_t z_double    = 6u;
    uint32_t my_z        = 7u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_LD_REG (base, my_z, z);
    CY_CRYPTO_VU_LD_REG (base, z_double, x);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t_double, (3u * size) + 7u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t1, size+4u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    CY_CRYPTO_VU_UMUL (base, t_double, z_double, VR_BARRETT);
    CY_CRYPTO_VU_SET_REG (base, sh, 512u, 2u);
    CY_CRYPTO_VU_LSR (base, t1, t_double, sh);
    CY_CRYPTO_VU_UMUL (base, t_double, t1, VR_P);
    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(t1));

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t1_plus2, size + 2u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t2_plus2, size + 2u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    CY_CRYPTO_VU_SUB (base, t2_plus2, z_double, t_double);
    CY_CRYPTO_VU_SUB (base, t1_plus2, t2_plus2, VR_P);
    CY_CRYPTO_VU_COND_SWAP_REG (base, CY_CRYPTO_VU_COND_CC, t1_plus2, t2_plus2);
    CY_CRYPTO_VU_SUB (base, t2_plus2, t1_plus2, VR_P);
    CY_CRYPTO_VU_COND_MOV (base, CY_CRYPTO_VU_COND_CC, my_z, t1_plus2);
    CY_CRYPTO_VU_COND_MOV (base, CY_CRYPTO_VU_COND_CS, my_z, t2_plus2);

    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(t2_plus2) |
                                 CY_CRYPTO_VU_REG_BIT(t1_plus2) |
                                 CY_CRYPTO_VU_REG_BIT(t_double));
    CY_CRYPTO_VU_POP_REG (base);

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_MulMod
****************************************************************************//**
*
* Modular multiplication in GF(VR_P).
* Leaf function.
*
* \param base
* The pointer to a Crypto instance.
*
* \param z
* Result = a * b % mod. Register index for product value.
*
* \param a
* Register index for multiplicand value.
*
* \param b
* Register index for multiplier value.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_MulMod( CRYPTO_Type *base,
    uint32_t z,
    uint32_t a,
    uint32_t b,
    uint32_t size)
{
    uint32_t ab_double       = 0u;
    uint32_t my_z            = 1u;
    uint32_t my_a            = 2u;
    uint32_t my_b            = 3u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_LD_REG(base, my_z, z);
    CY_CRYPTO_VU_LD_REG(base, my_a, a);
    CY_CRYPTO_VU_LD_REG(base, my_b, b);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, ab_double, 2u * size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    CY_CRYPTO_VU_UMUL (base, ab_double, my_a, my_b);

    /* Barrett reduction */
    tmpResult = Cy_Crypto_Core_EDDSA_Bar_MulRed(base, my_z, ab_double, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(ab_double));

    CY_CRYPTO_VU_POP_REG (base);

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_SquareMod
****************************************************************************//**
*
* Modular squaring in GF(VR_P).
*
* \param base
* The pointer to a Crypto instance.
*
* \param z
* Result = a * a % mod. Register index for product value.
*
* \param a
* Register index for multiplicand and multiplier value.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_SquareMod( CRYPTO_Type *base,
    uint32_t z,
    uint32_t a,
    uint32_t size)
{
    return Cy_Crypto_Core_ED25519_MulMod( base, z, a, a, size);
}

#if defined(CY_CRYPTO_CFG_EDDSA_C)
static void Cy_Crypto_Core_ED25519_dom2_ctx( CRYPTO_Type *base, cy_en_eddsa_sig_type_t sigType, const uint8_t *ctx,
                uint32_t ctx_len, cy_stc_crypto_sha_state_t *shaState )
{
    uint8_t ct_init_string[] = "SigEd25519 no Ed25519 collisions";
    uint8_t ct_flag;
    uint8_t ct_ctx_len = (uint8_t)(ctx_len & 0xffu);

    ct_flag = (sigType == CY_CRYPTO_EDDSA_CTX)? (uint8_t)0: (uint8_t)1;
    /*Note: Can merge to one update call*/
    (void)Cy_Crypto_Core_Sha_Update(base, shaState, (uint8_t const*)ct_init_string, 32u);
    (void)Cy_Crypto_Core_Sha_Update(base, shaState, (uint8_t const*)&ct_flag, 1u);
    (void)Cy_Crypto_Core_Sha_Update(base, shaState, (uint8_t const*)&ct_ctx_len, 1u);

    if( ctx != NULL && ctx_len > 0u)
    {
        (void)Cy_Crypto_Core_Sha_Update(base, shaState, ctx, ctx_len );

    }
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519Add
****************************************************************************//**
* ED25519 (Edwards and Twisted Edwards) point add on projective coordinates in GF(VR_P).
*
* Add for: R = P + Q
*
* https://hyperelliptic.org/EFD/g1p/auto-code/twisted/projective/addition/add-2008-bbjlp.op3
* with
* P = (X1, Z1)
* Q = (X2, Z2)
* R = (X3, Z3)
* and eliminating temporary variables t0, t3, ..., t9.
*
* Cost: 10M + 1S
*
* \param base
* The pointer to a Crypto instance.
*
* \param s_x
* Register index for  projective X coordinate.
*
* \param s_y
* Register index for  projective Y coordinate.
*
* \param s_z
* Register index for  projective Z coordinate.
*
* \param t_x
* Register index for affine X coordinate.
*
* \param t_y
* Register index for affine Y coordinate.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519Add(CRYPTO_Type *base,
    cy_stc_crypto_edw_dp_type *edwDp,
    uint32_t s_x,
    uint32_t s_y,
    uint32_t s_z,
    uint32_t t_x,
    uint32_t t_y,
    uint32_t size
)
{
    uint32_t t1    = 1u;
    uint32_t b     = 0u;
    uint32_t c     = 3u;
    uint32_t d     = 4u;
    uint32_t e     = 5u;
    uint32_t f     = 6u;
    uint32_t g     = 7u;
    uint32_t my_s_x = 8u;
    uint32_t my_s_y = 9u;
    uint32_t my_s_z = 10u;
    uint32_t my_t_x = 11u;
    uint32_t my_t_y = 12u;
    uint32_t t2;
    uint32_t r_s_x, r_s_y, r_s_z, r_t_x, r_t_y;

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_SAVE_REG(base, s_x, &r_s_x);
    CY_CRYPTO_VU_SAVE_REG(base, s_y, &r_s_y);
    CY_CRYPTO_VU_SAVE_REG(base, s_z, &r_s_z);
    CY_CRYPTO_VU_SAVE_REG(base, t_x, &r_t_x);
    CY_CRYPTO_VU_SAVE_REG(base, t_y, &r_t_y);

    CY_CRYPTO_VU_RESTORE_REG(base, my_s_x, r_s_x);
    CY_CRYPTO_VU_RESTORE_REG(base, my_s_y, r_s_y);
    CY_CRYPTO_VU_RESTORE_REG(base, my_s_z, r_s_z);
    CY_CRYPTO_VU_RESTORE_REG(base, my_t_x, r_t_x);
    CY_CRYPTO_VU_RESTORE_REG(base, my_t_y, r_t_y);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t1, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, b, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, c, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, d, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, e, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, f, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, g, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* A = Z1*Z2 */
    /* Z2 = 1 skip first step
    Note: Revisit if we randomize the base points*/
    /* B = A^2 */
    tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, b, my_s_z, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* C = X1*X2 */
    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, c, my_s_x, my_t_x, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* D = Y1*Y2 */
    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, d, my_s_y, my_t_y, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* E = d*C*D */
    Cy_Crypto_Core_Vu_SetMemValue (base, t1, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->d), size);
    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, f, c, d, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, e, f, t1, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* F = B-E */
    Cy_Crypto_Core_EC_SubMod( base, f, b, e);
    /* G = B+E */
    Cy_Crypto_Core_EC_AddMod( base, g, b, e);
    /* X3 = A*F*((X1+Y1)*(X2+Y2)-C-D) */
    t2 = b;
    Cy_Crypto_Core_EC_AddMod( base, t1, my_s_x, my_s_y);
    Cy_Crypto_Core_EC_AddMod( base, t2, my_t_x, my_t_y);

    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, my_s_x, t1, t2, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Crypto_Core_EC_SubMod( base, my_s_x, my_s_x, c);
    Cy_Crypto_Core_EC_SubMod( base, my_s_x, my_s_x, d);

    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, t1, my_s_z, f, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_s_x, my_s_x, t1, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* Y3 = A*G*(D-a*C) */
    Cy_Crypto_Core_Vu_SetMemValue (base, t1, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->a), size);
    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, t2, my_s_z, g, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, t1, t1, c, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Crypto_Core_EC_SubMod( base, my_s_y, d, t1);
    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, my_s_y, my_s_y, t2, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* Z3 = F*G */
    tmpResult =Cy_Crypto_Core_ED25519_MulMod( base, my_s_z, f, g, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(t1) | CY_CRYPTO_VU_REG_BIT(b) |
                                 CY_CRYPTO_VU_REG_BIT(c) | CY_CRYPTO_VU_REG_BIT(d)  |
                                 CY_CRYPTO_VU_REG_BIT(e) | CY_CRYPTO_VU_REG_BIT(f)  |
                                 CY_CRYPTO_VU_REG_BIT(g));

    CY_CRYPTO_VU_POP_REG (base);

    return CY_CRYPTO_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519Double
****************************************************************************//**
*
* ED25519 (Edwards and Twisted Edwards) point doubling on projective coordinates in GF(VR_P).
*
* Double for: R = 2 * P for both Edwards and Twisted Edwards curves in projective
* coordinates.
*
* https://hyperelliptic.org/EFD/g1p/auto-code/twisted/projective/doubling/dbl-2008-bbjlp.op3
* with
* P = (X1, Z1)
* R = (X3, Z3)
* and eliminating H and temporary variables t0, ..., t4.
*
* Cost: 3M + 4S
*
* \param base
* The pointer to a Crypto instance.
*
* \param s_x
* Register index for projective X coordinate.
*
* \param s_y
* Register index for projective Y coordinate.
*
* \param s_z
* Register index for projective Z coordinate.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519Double(CRYPTO_Type *base,
    cy_stc_crypto_edw_dp_type *edwDp,
    uint32_t s_x,
    uint32_t s_y,
    uint32_t s_z,
    uint32_t size
)
/* 3M + 4S */
{
    uint32_t b      = 1u;
    uint32_t c      = 0u;
    uint32_t d      = 3u;
    uint32_t e      = 4u;
    uint32_t f      = 5u;
    uint32_t j      = 6u;
    uint32_t my_s_x = 7u;
    uint32_t my_s_y = 8u;
    uint32_t my_s_z = 9u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_LD_REG(base, my_s_x, s_x);
    CY_CRYPTO_VU_LD_REG(base, my_s_y, s_y);
    CY_CRYPTO_VU_LD_REG(base, my_s_z, s_z);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, b, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, c, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, d, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, e, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, f, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    Cy_Crypto_Core_Vu_SetMemValue (base, f, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->a), size);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, j, size+1u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* B = (X1 + Y1)^2 */
    Cy_Crypto_Core_EC_AddMod( base, b, my_s_x, my_s_y);
    tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, b, b, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* C = X1^2 */
    tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, c, my_s_x, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* D = Y1^2 */
    tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, d, my_s_y, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* E = eddp->a*C */
    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, e, f, c, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* F = E+D */
    Cy_Crypto_Core_EC_AddMod( base, f, e, d);
    /* J = F - 2*(Z1^2) */
    tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, j, my_s_z, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /*2*(Z1^2) mod p*/
    Cy_Crypto_Core_EC_AddMod( base, j, j, j);
    Cy_Crypto_Core_EC_SubMod (base, j, f, j);
    /* X3 = (B-C-D)*J */
    Cy_Crypto_Core_EC_SubMod (base, b, b, c);
    Cy_Crypto_Core_EC_SubMod (base, b, b, d);
    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_s_x, b, j, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* Y3 = F*(E-D) */
    Cy_Crypto_Core_EC_SubMod (base, e, e, d);
    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_s_y, f, e, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* Z3 = F*J */
    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_s_z, f, j, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(b) | CY_CRYPTO_VU_REG_BIT(c) |
                                 CY_CRYPTO_VU_REG_BIT(d) | CY_CRYPTO_VU_REG_BIT(e) |
                                 CY_CRYPTO_VU_REG_BIT(f) | CY_CRYPTO_VU_REG_BIT(j) );
    CY_CRYPTO_VU_POP_REG (base);

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519InvTransform
****************************************************************************//**
*
* Transformation from projective coordinates to affine coordinates in GF(VR_P).
* (s_x, s_y, s_z) -> (p_x, p_y), where p_x = s_x/s_z, p_y = s_y/s_z
*
* \param base
* The pointer to a Crypto instance.
*
* \param s_x
* Register index for affine X coordinate and projective X coordinate.
*
* \param s_y
* Register index for affine Y coordinate and projective Y coordinate.
*
* \param s_z
* Register index for projective Z coordinate.
*
* \param size
* Bit size.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519InvTransform(CRYPTO_Type *base, uint32_t s_x, uint32_t s_y, uint32_t s_z, uint32_t size)
{

    uint32_t t1     = 7u;
    uint32_t t2     = 8u;
    uint32_t my_s_x = 9u;
    uint32_t my_s_y = 10u;
    uint32_t my_s_z = 11u;
    uint32_t r_s_x, r_s_y, r_s_z;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_SAVE_REG(base, s_x, &r_s_x);
    CY_CRYPTO_VU_SAVE_REG(base, s_y, &r_s_y);
    CY_CRYPTO_VU_SAVE_REG(base, s_z, &r_s_z);

    CY_CRYPTO_VU_RESTORE_REG(base, my_s_x, r_s_x);
    CY_CRYPTO_VU_RESTORE_REG(base, my_s_y, r_s_y);
    CY_CRYPTO_VU_RESTORE_REG(base, my_s_z, r_s_z);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t1, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t2, size);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    CY_CRYPTO_VU_SET_TO_ONE (base, t1);                                 /* t1 = 1 */

    tmpResult = Cy_Crypto_Core_EC_DivMod( base, t2, t1, my_s_z, size);  /* t2 = 1/Z */
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_s_x, my_s_x, t2, size);  /* my_s_x = X/Z */
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, my_s_y, my_s_y, t2, size);  /* t3 = Y/Z */
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(t1) | CY_CRYPTO_VU_REG_BIT(t2));

    CY_CRYPTO_VU_POP_REG (base);

    return CY_CRYPTO_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_PointMulAdd
****************************************************************************//**
*
* Edward 25519 Elliptic curve point multiply-Add in GF(p).
*
* R = s*P + h*Q
*
* \param base
* The pointer to a Crypto instance.
*
* \param p_x
* Register index for affine X coordinate of point.
*
* \param p_y
* Register index for affine Y coordinate of point.
*
* \param s
* Register index for multiplication value.
*
* \param q_x
* Register index for affine X coordinate of point.
*
* \param q_y
* Register index for affine Y coordinate of point.
*
* \param h
* Register index for multiplication value.
*
* \param bitsize
* Bit size of the used curve.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_PointMulAdd(CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp,
                                                        uint32_t p_x, uint32_t p_y, uint32_t s,
                                                        uint32_t q_x, uint32_t q_y, uint32_t h,
                                                        uint32_t bitsize)
{
    /* Note: Pre conditions 0 < (px,py)(qx,qy) < N-1 */
    /* Do not use all arg REG (5,7,8,9,11,12), also on V1 reg2 is modified by mem ops */
    uint32_t p_z     = 1u;
    uint32_t my_s    = 3u;
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_LD_REG(base, my_s, s);

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


    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_z, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* init point->z to 1. */
    CY_CRYPTO_VU_SET_TO_ONE (base, p_z);

    /*sB = point_mul(s, G)*/
    tmpResult = Cy_Crypto_Core_ED25519_PointMul(base, edwDp, p_x, p_y, my_s, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /*hA = point_mul(h, A)*/
    tmpResult = Cy_Crypto_Core_ED25519_PointMul(base, edwDp, q_x, q_y, h, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* R = point_add(sB, hA) */
    /* RFC Sec 5.1.7 Check the group equation [S]B = R + [k]A'.  It's sufficient.
       We perform fast single-signature verification by computing R = [s]B + [-k]A'. compressing 'R' and comparing with Sig[R] without
       decompressing it.
    */
    tmpResult = Cy_Crypto_Core_ED25519Add (base, edwDp, p_x, p_y, p_z, q_x, q_y, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }
    /* Inverse transform */
    Cy_Crypto_Core_Vu_WaitForComplete(base);
    tmpResult = Cy_Crypto_Core_ED25519InvTransform(base, p_x, p_y, p_z, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Crypto_Core_Vu_WaitForComplete(base);
    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(p_z)|CY_CRYPTO_VU_REG_BIT(VR_P)|CY_CRYPTO_VU_REG_BIT(VR_BARRETT));
    CY_CRYPTO_VU_POP_REG (base);

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_PointMul
****************************************************************************//**
*
* Edward 25519 Elliptic curve point multiplication in GF(p).
*
* \param base
* The pointer to a Crypto instance.
*
* \param p_x
* Register index for affine X coordinate of base point.
*
* \param p_y
* Register index for affine Y coordinate of base point.
*
* \param p_d
* Register index for multiplication value.
*
* \param bitsize
* Bit size of the used curve.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_PointMul(CRYPTO_Type *base, cy_stc_crypto_edw_dp_type *edwDp, uint32_t p_x, uint32_t p_y, uint32_t p_d, uint32_t bitsize)
{
    /* Note: Pre conditions 0 < px, py < p-1 (consider randomizing the base point)*/

    uint32_t i;
    uint32_t status;
    uint32_t carry;
    uint16_t clsame;
    uint32_t loop;

    uint32_t clr     = 5u;
    uint32_t t       = 6u;
    uint32_t my_s_x  = 7u;
    uint32_t my_s_y  = 8u;
    uint32_t my_s_z  = 9u;
    uint32_t my_t_x  = 10u;
    uint32_t my_t_y  = 11u;
    uint32_t my_d    = 12u;
    uint32_t r_p_x, r_p_y, r_p_d;

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_SAVE_REG(base, p_x, &r_p_x);
    CY_CRYPTO_VU_SAVE_REG(base, p_y, &r_p_y);
    CY_CRYPTO_VU_SAVE_REG(base, p_d, &r_p_d);

    CY_CRYPTO_VU_RESTORE_REG(base, my_s_x, r_p_x);
    CY_CRYPTO_VU_RESTORE_REG(base, my_s_y, r_p_y);
    CY_CRYPTO_VU_RESTORE_REG(base, my_d, r_p_d);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, clr, bitsize+1u);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

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

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, my_t_y, bitsize);
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


    CY_CRYPTO_VU_MOV (base, my_t_x, my_s_x);
    CY_CRYPTO_VU_MOV (base, my_t_y, my_s_y);

    /* init point->z to 1. */
    CY_CRYPTO_VU_SET_TO_ONE (base, my_s_z);

    /* EC scalar multiplication (irregular) operation. */
    CY_CRYPTO_VU_SET_TO_ZERO (base, clr);
    CY_CRYPTO_VU_CLSAME (base, t, my_d, clr);

    /* This is needed, otherwise clsame is wrong */
    Cy_Crypto_Core_Vu_WaitForComplete(base);

    clsame = Cy_Crypto_Core_Vu_RegDataPtrRead (base, t);

    CY_CRYPTO_VU_LSL  (base, my_d, my_d, t); /* Get rid of leading '0's */
    CY_CRYPTO_VU_LSL1 (base, my_d, my_d);    /* Get rid of leading '1' */

    /* Binary left-to-right algorithm
    * Perform point addition and point doubling to implement scalar multiplication
    * Scan the bits of the scalar from left to right; perform point doubling for each bit,
    * and perform point addition when the bit is set.
    * Carry set if current bit is equal to 1 (hence, perform point addition - point
    * doubling is always performed)
    */
    if( bitsize >= clsame)
    {
        loop = (uint32_t)(bitsize - clsame);
    }
    else
    {
        return CY_CRYPTO_HW_ERROR;
    }

    for (i = 0; i < (loop); i++)
    {
        /* Carry set if current bit is equal to 1 (hence, perform point addition - point
        * doubling is always performed)
        */
        CY_CRYPTO_VU_LSL1 (base, my_d, my_d);
        status = Cy_Crypto_Core_Vu_StatusRead(base);

        carry = status & CY_CRYPTO_VU_STATUS_CARRY_BIT;

        tmpResult = Cy_Crypto_Core_ED25519Double (base, edwDp, my_s_x, my_s_y, my_s_z, bitsize);

        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        if (carry != 0u)
        {
            tmpResult = Cy_Crypto_Core_ED25519Add (base, edwDp, my_s_x, my_s_y, my_s_z, my_t_x, my_t_y, bitsize);

            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
        }
    }
    Cy_Crypto_Core_Vu_WaitForComplete(base);
    /* Inverse transform */
    tmpResult = Cy_Crypto_Core_ED25519InvTransform(base, my_s_x, my_s_y, my_s_z, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    Cy_Crypto_Core_Vu_WaitForComplete(base);
    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(my_s_z) | CY_CRYPTO_VU_REG_BIT(my_t_x) |
                                 CY_CRYPTO_VU_REG_BIT(my_t_y) | CY_CRYPTO_VU_REG_BIT(t) |
                                 CY_CRYPTO_VU_REG_BIT(VR_P)   | CY_CRYPTO_VU_REG_BIT(VR_BARRETT) |
                                 CY_CRYPTO_VU_REG_BIT(clr) );


    CY_CRYPTO_VU_POP_REG (base);

    return tmpResult;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_PointMultiplication
****************************************************************************//**
*
* Edwards 25519 elliptic curve point multiplication in GF(p).
*
* When D-Cache is enabled parameters ecpGX,ecpGY,ecpD,ecpQX and ecpQY must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param ecpGX
* X coordinate of base point.
*
* \param ecpGY
* Y coordinate of base point.
*
* \param ecpD
* multiplication scalar value.
*
* \param ecpQX
* X coordinate of result point.
*
* \param ecpQY
* Y coordinate of result point.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_PointMultiplication(CRYPTO_Type *base,
    cy_en_crypto_ecc_curve_id_t curveID,
    const uint8_t *ecpGX,
    const uint8_t *ecpGY,
    const uint8_t *ecpD,
    uint8_t *ecpQX,
    uint8_t *ecpQY)
{
    cy_stc_crypto_edw_dp_type edw_Dp;
    cy_stc_crypto_edw_dp_type *edwDp = &edw_Dp;

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_NOT_SUPPORTED;

    if(CY_CRYPTO_SUCCESS == Cy_Crypto_Core_EDW_GetCurveParams(edwDp, curveID))
    {
        uint32_t bitsize;

        bitsize   = edwDp->size;
        tmpResult = CY_CRYPTO_BAD_PARAMS;

        if ((NULL != ecpGX) && (NULL != ecpGY) && (NULL != ecpD) && (NULL != ecpQX) && (NULL != ecpQY))
        {
            uint8_t *ecpGXRemap;
            uint8_t *ecpGYRemap;
            uint8_t *ecpDRemap;
            uint8_t *ecpQXRemap;
            uint8_t *ecpQYRemap;

            ecpGXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ecpGX);
            ecpGYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ecpGY);
            ecpDRemap  = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ecpD);
            ecpQXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ecpQX);
            ecpQYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(ecpQY);

            /* Public parameters and characteristics of elliptic curve */
            tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_D, bitsize+1u);        /* Scalar factor */
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_S_X, bitsize);
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_S_Y, bitsize);
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            Cy_Crypto_Core_Vu_SetMemValue (base, VR_S_X, ecpGXRemap, bitsize);
            Cy_Crypto_Core_Vu_SetMemValue (base, VR_S_Y, ecpGYRemap, bitsize);
            Cy_Crypto_Core_Vu_SetMemValue (base, VR_D, ecpDRemap, bitsize+1u);

            /* ECC calculation: d * G mod p */
            tmpResult = Cy_Crypto_Core_ED25519_PointMul(base, edwDp, VR_S_X, VR_S_Y, VR_D, bitsize);

            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            /* Get result P = (X,Y) = d.G from Ed25519 scalar multiplication */
            Cy_Crypto_Core_Vu_GetMemValue (base, ecpQXRemap, VR_S_X, bitsize);
            Cy_Crypto_Core_Vu_GetMemValue (base, ecpQYRemap, VR_S_Y, bitsize);

            Cy_Crypto_Core_Vu_WaitForComplete(base);
            /* Free memory */
            CY_CRYPTO_VU_FREE_MEM (base,
                                    CY_CRYPTO_VU_REG_BIT(VR_S_Y) |
                                    CY_CRYPTO_VU_REG_BIT(VR_S_X) |
                                    CY_CRYPTO_VU_REG_BIT(VR_D));

            tmpResult = CY_CRYPTO_SUCCESS;
        }
    }

    return tmpResult;
}
#endif /*#if defined(CY_CRYPTO_CFG_EDDSA_C)*/

#if defined (CY_CRYPTO_CFG_EDDSA_GENKEY_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_MakePublicKey
****************************************************************************//**
*
* Make a new ED25519 public key
*
* When D-Cache is enabled parameters privateKey, publicKey( x&y) must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param privateKey
* [in] Private key.
*
* \param publicKey
* [out] Newly created Public key.
* See \ref cy_stc_crypto_ecc_key.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_MakePublicKey(CRYPTO_Type *base,
        cy_en_crypto_ecc_curve_id_t curveID,
        const uint8_t *privateKey,
        cy_stc_crypto_ecc_key *publicKey)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_NOT_SUPPORTED;

    cy_stc_crypto_edw_dp_type edw_Dp;
    cy_stc_crypto_edw_dp_type *edwDp = &edw_Dp;
    uint8_t *privateKeyRemap;
    uint8_t *publicKeyXRemap;
    uint8_t *publicKeyYRemap;
    uint8_t *digest;

    if(CY_CRYPTO_SUCCESS == Cy_Crypto_Core_EDW_GetCurveParams(edwDp, curveID))
    {
        if ((privateKey != NULL) && (publicKey != NULL) &&
            (publicKey->pubkey.x != NULL) && (publicKey->pubkey.y != NULL))
        {
#if (CY_IP_MXCRYPTO_VERSION == 1u)
            cy_stc_crypto_v1_sha512_buffers_t shaBuffers_t;
            cy_stc_crypto_sha_state_t shaHashState_t;
            cy_stc_crypto_sha_state_t *shaHashState = &shaHashState_t;
            cy_stc_crypto_v1_sha512_buffers_t *shaBuffers = &shaBuffers_t;
#else
            uint8_t shaBuffers_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_sha512_buffers_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
            uint8_t shaHashState_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_sha_state_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
            cy_stc_crypto_v2_sha512_buffers_t *shaBuffers = (cy_stc_crypto_v2_sha512_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(shaBuffers_t);
            cy_stc_crypto_sha_state_t *shaHashState = (cy_stc_crypto_sha_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(shaHashState_t);
#endif

            uint32_t bitsize  = edwDp->size;
            uint32_t bytesize = CY_CRYPTO_BYTE_SIZE_OF_BITS(edwDp->size);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            /* Flush the cache */
            SCB_CleanDCache_by_Addr((volatile void *)privateKey,(int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
#endif
            privateKeyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(privateKey);
            publicKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.x);
            publicKeyYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey->pubkey.y);

            uint32_t p_d = 10u;       /* private key */
            uint32_t p_x = 11u;       /* x coordinate */
            uint32_t p_y = 12u;       /* y coordinate */
            uint32_t p_sha = 4u;      /* digest */

            tmpResult = Cy_Crypto_Core_Sha_Init(base, shaHashState, (cy_en_crypto_sha_mode_t)CY_CRYPTO_MODE_SHA512, (void *)shaBuffers);
            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                tmpResult = Cy_Crypto_Core_Sha_Start(base, shaHashState);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
            }
            else
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

            tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_sha, (CY_CRYPTO_SHA512_HASH_SIZE*8u));
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            digest = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_sha);
            /*Base Point, G = (p_x, p_y) */
            Cy_Crypto_Core_Vu_SetMemValue (base, p_x, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gx), bitsize);
            Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gy), bitsize);

            /* Load private key */
            tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_d, bitsize+1u);
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            /*step1: Compute secret scalar 's' and prefix*/
            /*SHA expects big-endian input*/
            tmpResult = Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)privateKeyRemap, bytesize);
            if(CY_CRYPTO_SUCCESS == tmpResult)
            {
                tmpResult = Cy_Crypto_Core_Sha_Finish(base, shaHashState, digest);
            }
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }

            /*Prune the buffer: The lowest three bits of the first octet are cleared, the highest bit of the last octet is cleared,
            and the second highest bit of the last octet is set.*/
            digest[0]  &= ~((uint8_t)0x7);
            digest[31] &= ~((uint8_t)0x80);
            digest[31] |= (uint8_t)0x40;

            /*s = digest[0-31] prefix = digest[32-63]*/
            Cy_Crypto_Core_Vu_SetMemValue(base, p_d, (uint8_t *)&digest[0], bitsize+1u);
            /* make the public key
             * ED25519 scalar point multiplication - X,Y-only co-Z arithmetic
             */
            tmpResult = Cy_Crypto_Core_ED25519_PointMul(base, edwDp, p_x, p_y, p_d, bitsize);
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

            Cy_Crypto_Core_Vu_WaitForComplete(base);
            CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(p_x) | CY_CRYPTO_VU_REG_BIT(p_y) |
                                        CY_CRYPTO_VU_REG_BIT(p_sha) | CY_CRYPTO_VU_REG_BIT(p_d));
            /* free sha context*/
            (void)Cy_Crypto_Core_Sha_Free(base, shaHashState);
            tmpResult = CY_CRYPTO_SUCCESS;
        }
    }

    return (tmpResult);
}
#endif /* defined (CY_CRYPTO_CFG_EDDSA_GENKEY_C)*/

#if defined(CY_CRYPTO_CFG_EDDSA_SIGN_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_Sign
****************************************************************************//**
*
* Sign a message.
*
* When D-Cache is enabled parameters hash, sig, key(k) and sigctx must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param hash
* The message to sign. Provided as is in data buffer. This is usually the hash of
* the original data to be signed.
*
* \param hashlen
* The length of the message in bytes.
*
* \param sig
* [out] The destination for the signature, 'r' followed by 's'.
*
* \param key
* Key used for signature generation. See \ref cy_stc_crypto_ecc_key.
*
* \param sigType
* signature Type. CY_CRYPTO_EDDSA_PURE,CY_CRYPTO_EDDSA_CTX or CY_CRYPTO_EDDSA_PREHASH
*
* \param sigctx
* signature context. can be NULL if EDDSA_PURE is used or if no context is provided.
*
* \param sigctx_len
* The length of the signature context
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_Sign(CRYPTO_Type *base, const uint8_t *hash, uint32_t hashlen, uint8_t *sig,
        const cy_stc_crypto_ecc_key *key, cy_en_eddsa_sig_type_t sigType,const uint8_t *sigctx, uint32_t sigctx_len)
{
     cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    uint8_t *sigPtrRemap;
    uint8_t *hashPtrRemap;
    uint8_t *keyKRemap;
    uint32_t mallocMask = 0u;

    cy_stc_crypto_edw_dp_type edwDp_t;
    cy_stc_crypto_edw_dp_type *edwDp = &edwDp_t;

    /* input param validation */
    if ( hash == NULL && 0u != hashlen )
    {
        return CY_CRYPTO_BAD_PARAMS;
    }
    /*
    Value of context is set by the signer and verifier (maximum of 255
    octets; the default is empty string, except for Ed25519, which can't
    have context) and has to match octet by octet for verification to be
    successful.
    */
    if(sigType != CY_CRYPTO_EDDSA_PURE)
    {
        if(sigType == CY_CRYPTO_EDDSA_CTX)
        {
            if( sigctx == NULL  || sigctx_len == 0u || sigctx_len > 255u)
            {
                return CY_CRYPTO_BAD_PARAMS;
            }
        }
        else
        {
            if (sigType == CY_CRYPTO_EDDSA_PREHASH && hashlen != CY_CRYPTO_SHA512_HASH_SIZE)
            {
                return CY_CRYPTO_BAD_PARAMS;
            }
        }
    }

    if ((sig != NULL) && (key != NULL) && (sigType < CY_CRYPTO_EDDSA_NONE))
    {
        tmpResult = CY_CRYPTO_NOT_SUPPORTED;

        hashPtrRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(hash);
        sigPtrRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(sig);
        keyKRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key->k);

        if(CY_CRYPTO_SUCCESS == Cy_Crypto_Core_EDW_GetCurveParams(edwDp, key->curveID))
        {
#if (CY_IP_MXCRYPTO_VERSION == 1u)
            cy_stc_crypto_v1_sha512_buffers_t shaBuffers_t;
            cy_stc_crypto_sha_state_t shaHashState_t;
            cy_stc_crypto_sha_state_t *shaHashState = &shaHashState_t;
            cy_stc_crypto_v1_sha512_buffers_t *shaBuffers = &shaBuffers_t;
#else
            uint8_t shaBuffers_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_sha512_buffers_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
            uint8_t shaHashState_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_sha_state_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
            cy_stc_crypto_v2_sha512_buffers_t *shaBuffers = (cy_stc_crypto_v2_sha512_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(shaBuffers_t);
            cy_stc_crypto_sha_state_t *shaHashState = (cy_stc_crypto_sha_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(shaHashState_t);
#endif
            uint32_t bitsize  = edwDp->size;
            uint32_t bytesize = CY_CRYPTO_BYTE_SIZE_OF_BITS(edwDp->size);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            /* Flush the cache */
            SCB_CleanDCache_by_Addr((volatile void *)hash,(int32_t)hashlen);
            SCB_CleanDCache_by_Addr((volatile void *)key->k, (int32_t)bytesize);
            /* sigctx is managed by the SHA functions */
#endif

            tmpResult = Cy_Crypto_Core_Sha_Init(base, shaHashState, (cy_en_crypto_sha_mode_t)CY_CRYPTO_MODE_SHA512, (void *)shaBuffers);
            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                tmpResult = Cy_Crypto_Core_Sha_Start(base, shaHashState);
            }

            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                uint32_t p_sha  = 4u;
                uint32_t p_temp = 5u;
                uint32_t p_r    = 6u;
                uint32_t p_s    = 7u;
                uint32_t p_x    = 8u;
                uint32_t p_y    = 9u;

                uint8_t *digest;
                uint8_t *scalar;
                uint8_t *prefix;
                uint8_t *pubkey_x;
                uint8_t *pubkey_y;
                uint8_t *r_x;
                uint8_t *r_y;
                uint8_t pr_t[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_ECC_ED25519_BYTE_SIZE) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
                uint8_t *pr = (uint8_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(pr_t);

                /*Curve Order*/
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_P, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_P, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->order), bitsize);
                /* Barret coef for Order*/
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_BARRETT, edwDp->barret_osize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_BARRETT, (uint8_t const*)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->barrett_o), edwDp->barret_osize);
                /* Gx co-ordinate */
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_S_X, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_S_X, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gx), bitsize);
                /* Gy co-ordinate */
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_S_Y, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_S_Y, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gy), bitsize+1u);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_r, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_MemSet(base, (void*)Cy_Crypto_Core_Vu_RegMemPointer(base, p_r), (uint8_t)0, (uint16_t)bytesize);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_s, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_sha, (CY_CRYPTO_SHA512_HASH_SIZE*8u));
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                digest = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_sha);

               tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_temp, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_x, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, p_x, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gx), bitsize);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_y, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gy), bitsize+1u);

                mallocMask = CY_CRYPTO_VU_REG_BIT(VR_P)   | CY_CRYPTO_VU_REG_BIT(VR_BARRETT) |
                             CY_CRYPTO_VU_REG_BIT(VR_S_X) | CY_CRYPTO_VU_REG_BIT(VR_S_Y) |
                             CY_CRYPTO_VU_REG_BIT(p_r)    | CY_CRYPTO_VU_REG_BIT(p_s) |
                             CY_CRYPTO_VU_REG_BIT(p_x)    | CY_CRYPTO_VU_REG_BIT(p_y) |
                             CY_CRYPTO_VU_REG_BIT(p_sha)  | CY_CRYPTO_VU_REG_BIT(p_temp);

                /*step1: Compute secret scalar 's' and prefix*/
                /*SHA expects big-endian*/
                tmpResult = Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)keyKRemap, bytesize);
                if(CY_CRYPTO_SUCCESS == tmpResult)
                {
                    tmpResult = Cy_Crypto_Core_Sha_Finish(base, shaHashState, digest);
                }
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /*Prune the buffer: The lowest three bits of the first octet are cleared, the highest bit of the last octet is cleared,
                and the second highest bit of the last octet is set.*/
                digest[0]  &= ~((uint8_t)0x7);
                digest[31] &= ~((uint8_t)0x80);
                digest[31] |= (uint8_t)0x40;

                /*s = digest[0-31] prefix = digest[32-63]*/
                scalar = &digest[0];
                prefix = &digest[32];
                /* Note: Point mul does in-place use for p_s which clears it, REG use needs to be re-looked to optimize*/
                Cy_Crypto_Core_Vu_SetMemValue (base, p_s, (uint8_t const*)scalar, ((CY_CRYPTO_SHA512_HASH_SIZE*8u) >> 1u));
                /* generate pubKey A = [s]B */
                tmpResult =  Cy_Crypto_Core_ED25519_PointMul(base, edwDp, VR_S_X, VR_S_Y, p_s, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, p_s, (uint8_t const*)scalar, ((CY_CRYPTO_SHA512_HASH_SIZE*8u) >> 1u));

                pubkey_x = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, VR_S_X);
                pubkey_y = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, VR_S_Y);

                /* step2: 'r' computation */
                (void)Cy_Crypto_Core_Sha_Start(base, shaHashState);
                /* EDDSA sig mode as per 5.1 RFC 8032 */
                if(sigType != CY_CRYPTO_EDDSA_PURE)
                {
                    Cy_Crypto_Core_ED25519_dom2_ctx( base, sigType, sigctx, sigctx_len, shaHashState);
                }

                /*update prefix and input hash */
                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)prefix, (CY_CRYPTO_SHA512_HASH_SIZE >> 1u));
                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)hashPtrRemap, hashlen);
                (void)Cy_Crypto_Core_Sha_Finish(base, shaHashState, digest);

                /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
                if ( CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDDSA_Bar_MulRed(base, p_r, p_sha, bitsize) )
                {
                    return CY_CRYPTO_BAD_PARAMS;
                }
                /* Note: Point mul does in-place use for p_r which clears it, REG use needs to be re-looked to optimize*/
                Cy_Crypto_Core_Vu_GetMemValue (base, (uint8_t*)pr, p_r, bitsize);
                /* Step 3 */
                tmpResult = Cy_Crypto_Core_ED25519_PointMul(base, edwDp, p_x, p_y, p_r, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, p_r, (uint8_t const*)pr, ((CY_CRYPTO_SHA512_HASH_SIZE*8u) >> 1u));

                /*Note: key encode/decode can be a separate function helps verify */
                /* encode point: From RFC 5.1.2, we shall copy LSB of x to the MSB of y */
                /* Test p_x for odd */
                r_x = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_x);
                r_y = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_y);
                if((bool)(((uint8_t*)r_x)[0] & (uint8_t)0x01))
                {
                    ((uint8_t*)r_y)[31] = ((uint8_t*)r_y)[31] | (uint8_t)0x80;
                }

                /* Copy r to sig result */
                Cy_Crypto_Core_Vu_GetMemValue (base, &sigPtrRemap[0], p_y, bitsize);

                /* Step4: 's' computation */
                (void)Cy_Crypto_Core_Sha_Start(base, shaHashState);
                /* EDDSA sig mode as per 5.1 RFC 8032 */
                if(sigType != CY_CRYPTO_EDDSA_PURE)
                {
                    Cy_Crypto_Core_ED25519_dom2_ctx( base, sigType, sigctx, sigctx_len, shaHashState);
                }

                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)r_y, bytesize);
                /*Note: key encode/decode can be a separate function */
                /* encode point: From RFC 5.1.2, we shall copy LSB of x to the MSB of y */
                if((bool)(((uint8_t*)pubkey_x)[0] & (uint8_t)0x01))
                {
                    ((uint8_t*)pubkey_y)[31] = ((uint8_t*)pubkey_y)[31] | (uint8_t)0x80;
                }

                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)pubkey_y, bytesize);
                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)hashPtrRemap, hashlen);
                (void)Cy_Crypto_Core_Sha_Finish(base, shaHashState, digest);

                /* step5 */
                /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
                if ( CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDDSA_Bar_MulRed(base, p_temp, p_sha, bitsize) )
                {
                    return CY_CRYPTO_BAD_PARAMS;
                }

                CY_CRYPTO_VU_UMUL(base, p_sha, p_temp, p_s);
                CY_CRYPTO_VU_ADD(base, p_sha, p_sha, p_r);

                /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
                if ( CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDDSA_Bar_MulRed(base, p_s, p_sha, bitsize))
                {
                    return CY_CRYPTO_HW_ERROR;
                }

                /* copy s to sig buffer*/
                if (!Cy_Crypto_Core_Vu_IsRegZero(base, p_s))
                {
                    /* S is not zero!!! */
                    Cy_Crypto_Core_Vu_GetMemValue (base, &sigPtrRemap[bytesize], p_s, bitsize);
                }
                else
                {
                    tmpResult = CY_CRYPTO_HW_ERROR;
                }

                Cy_Crypto_Core_Vu_WaitForComplete(base);
                /* Free all mem allocations */
                CY_CRYPTO_VU_FREE_MEM(base, mallocMask);
                (void)Cy_Crypto_Core_Sha_Free(base, shaHashState);
#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
                CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to int32_t.');
                SCB_InvalidateDCache_by_Addr(sig, (int32_t)(bytesize*2U));
#endif
            }
        }
    }

    return (tmpResult);
}
#endif /* defined(CY_CRYPTO_CFG_EDDSA_SIGN_C) */

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_ExpMod
****************************************************************************//**
*
* Modular exponentiation x = y^e mod p.
*
* \param base
* The pointer to a Crypto instance.
*
* \param p_x
* Register index for result X .
*
* \param p_y
* Register index for input integer Y.
*
* \param p_e
* Register index for exponent.
*
* \param bitsize
* Bit size of the input Y.
*
* \return status code. See \ref cy_en_crypto_status_t.
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_ExpMod(CRYPTO_Type *base, uint32_t p_x,
                                                    uint32_t p_y, uint32_t p_e,
                                                    uint32_t bitsize)
{
    uint32_t i;
    uint32_t status;
    uint32_t carry;
    uint16_t clsame;
    uint32_t loop;

    uint32_t clr     = 5u;
    uint32_t t       = 6u;
    uint32_t my_s_x  = 7u;
    uint32_t my_s_y  = 8u;
    uint32_t my_e    = 9u;
    uint32_t r_p_x, r_p_y, r_p_e;

    cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    CY_CRYPTO_VU_PUSH_REG (base);

    CY_CRYPTO_VU_SAVE_REG(base, p_x, &r_p_x);
    CY_CRYPTO_VU_SAVE_REG(base, p_y, &r_p_y);
    CY_CRYPTO_VU_SAVE_REG(base, p_e, &r_p_e);

    CY_CRYPTO_VU_RESTORE_REG(base, my_s_x, r_p_x);
    CY_CRYPTO_VU_RESTORE_REG(base, my_s_y, r_p_y);
    CY_CRYPTO_VU_RESTORE_REG(base, my_e, r_p_e);

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, clr, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, t, bitsize);
    if(CY_CRYPTO_SUCCESS != tmpResult)
    {
        return tmpResult;
    }

    /* normalize exp */
    CY_CRYPTO_VU_MOV (base, my_s_x, my_s_y);
    CY_CRYPTO_VU_SET_TO_ZERO (base, clr);
    CY_CRYPTO_VU_CLSAME (base, t, my_e, clr);
    /* This is needed, otherwise clsame is wrong */
    Cy_Crypto_Core_Vu_WaitForComplete(base);
    clsame = Cy_Crypto_Core_Vu_RegDataPtrRead (base, t);

    CY_CRYPTO_VU_LSL  (base, my_e, my_e, t); /* Get rid of leading '0's */
    CY_CRYPTO_VU_LSL1 (base, my_e, my_e);    /* Get rid of leading '1' */

    /* Binary left-to-right algorithm
    * Perform mul and squaring to implement exponential mod multiplication
    * Scan the bits of the exponent from left to right; perform squaring for each bit,
    * and perform mul when the bit is set. Carry set if current bit is equal to 1
    * (hence perform mul, squaring is always performed)
    */
    if( bitsize >= clsame)
    {
        loop = (uint32_t)(bitsize - clsame - 1u);
    }
    else
    {
        return CY_CRYPTO_HW_ERROR;
    }

    for (i = 0; i < (loop); i++)
    {
        /* Carry set if current bit is equal to 1 (hence, perform multiply,
        * squaring is always performed)
        */
        CY_CRYPTO_VU_LSL1 (base, my_e, my_e);
        status = Cy_Crypto_Core_Vu_StatusRead(base);

        carry = status & CY_CRYPTO_VU_STATUS_CARRY_BIT;

        tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, my_s_x, my_s_x, bitsize);

        if(CY_CRYPTO_SUCCESS != tmpResult)
        {
            return tmpResult;
        }

        if (carry != 0u)
        {
            (void)Cy_Crypto_Core_ED25519_MulMod (base, my_s_x, my_s_x, my_s_y, bitsize);
        }
    }

    Cy_Crypto_Core_Vu_WaitForComplete(base);
    /* free memory */
    CY_CRYPTO_VU_FREE_MEM (base, CY_CRYPTO_VU_REG_BIT(t) | CY_CRYPTO_VU_REG_BIT(clr));
    CY_CRYPTO_VU_POP_REG (base);

    return tmpResult;
}

#if defined(CY_CRYPTO_CFG_EDDSA_VERIFY_C)
/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_PointDecode
****************************************************************************//**
*
* Decode ED25519 encoded public key in to x and y
*
* When D-Cache is enabled parameters publicKey, pubKey_x and pubKey_y must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param curveID
* See \ref cy_en_crypto_ecc_curve_id_t.
*
* \param publicKey
* [in] encoded 32 byte Public key.
*
* \param pubKey_x
* [out] Decoded 32 bytes Public key x in little-endian format.
*
* \param pubKey_y
* [out] Decoded 32 bytes Public key y in little-endian format.
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_PointDecode(CRYPTO_Type *base,
        cy_en_crypto_ecc_curve_id_t curveID,
        const uint8_t *publicKey,
        uint8_t *pubKey_x, uint8_t *pubKey_y)
{
    cy_en_crypto_status_t tmpResult = CY_CRYPTO_NOT_SUPPORTED;

    cy_stc_crypto_edw_dp_type edw_Dp;
    cy_stc_crypto_edw_dp_type *edwDp = &edw_Dp;
    uint8_t *publicKeyRemap;
    uint8_t *publicKeyXRemap;
    uint8_t *publicKeyYRemap;
    uint8_t x_0;

    /* (p-5)/8 */
    CY_ALIGN(4) static const uint8_t  ed25519_pb8_exp[CY_CRYPTO_ECC_ED25519_BYTE_SIZE] =
    {
        0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f
    };
    /* 2^((p-1)/4) */
    CY_ALIGN(4)static const uint8_t ed25519_sqrt_m1[] =
    {
        0xB0, 0xA0, 0x0E, 0x4A, 0x27, 0x1B, 0xEE, 0xC4, 0x78, 0xE4, 0x2F, 0xAD,
        0x06, 0x18, 0x43, 0x2F, 0xA7, 0xD7, 0xFB, 0x3D, 0x99, 0x00, 0x4D, 0x2B,
        0x0B, 0xDF, 0xC1, 0x4F, 0x80, 0x24, 0x83, 0x2B
    };

    CY_CRYPTO_VU_PUSH_REG (base);

    if(CY_CRYPTO_SUCCESS == Cy_Crypto_Core_EDW_GetCurveParams(edwDp, curveID))
    {
        if ((publicKey != NULL) && (pubKey_x != NULL) && (pubKey_y != NULL))
        {
            uint32_t bitsize  = edwDp->size;
            uint32_t bytesize = CY_CRYPTO_BYTE_SIZE_OF_BITS(edwDp->size);

#if (((CY_CPU_CORTEX_M7) && defined (ENABLE_CM7_DATA_CACHE)) || CY_CPU_CORTEX_M55)
            /* Flush the cache */
            SCB_CleanDCache_by_Addr((volatile void *)publicKey,(int32_t)CY_CRYPTO_BYTE_SIZE_OF_BITS(bitsize));
#endif
            publicKeyRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(publicKey);
            publicKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(pubKey_x);
            publicKeyYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(pubKey_y);

            uint32_t p_a = 7u;       /* grp->A */
            uint32_t p_d = 6u;       /* grp->D */
            uint32_t p_x = 3u;       /* pub x coordinate */
            uint32_t p_y = 4u;       /* pub y coordinate */
            uint32_t p_uv = 5u;      /* (u*v) RFC 8032 sec 5.1.3 */

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

            tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_a, bitsize);
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            Cy_Crypto_Core_Vu_SetMemValue (base, p_a, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->a), bitsize);

            tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_d, bitsize);
            if(CY_CRYPTO_SUCCESS != tmpResult)
            {
                return tmpResult;
            }
            Cy_Crypto_Core_Vu_SetMemValue (base, p_d, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->d), bitsize);

            tmpResult = CY_CRYPTO_VU_ALLOC_MEM(base, p_uv, bitsize);
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

            /* Recover x_0 and generate p_y*/
            Cy_Crypto_Core_MemCpy(base, (void*)publicKeyYRemap, (void const *)publicKeyRemap, (uint16_t)bytesize);

            x_0 = pubKey_y[31] >> (uint8_t)0x07;
            pubKey_y[31] &= (uint8_t)0x7F;

            /* If the resulting y >= grp->P, decoding fails. */
            Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)publicKeyYRemap, bitsize);
            if (!Cy_Crypto_Core_Vu_IsRegLess(base, p_y, VR_P))
            {
                /* p_y is not less than P!!! */
                tmpResult = CY_CRYPTO_BAD_PARAMS;
            }

            /*
            To recover the x-coordinates, the curve equation implies x^2 = (y^2 - 1) / (d y^2 - a) (mod p).
            The denominator is always non-zero mod p. Let u = y^2 - 1 and v = d y^2 - a.
            We compute the square root of (u/v) depending on p (mod 8),for ED25519 its 5. The candidate root is
            x = sqrt(u/v) = u (u v)^((p-5)/8)
            */
            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                /*y^2*/
                tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, p_y, p_y, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /* dy^2*/
                tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, p_d, p_d, p_y, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /* v = (dy^2 - a) */
                Cy_Crypto_Core_EC_SubMod (base, p_d, p_d, p_a);
                /* u = y^2 - 1 */
                CY_CRYPTO_VU_SET_TO_ONE(base, p_x);
                CY_CRYPTO_VU_SUB(base, p_y, p_y, p_x);
                /* compute u*((uv)^((p-5)/8)) mod p */
                Cy_Crypto_Core_Vu_SetMemValue (base, p_x, (uint8_t const *)ed25519_pb8_exp, bitsize);
                tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, p_a, p_d, p_y, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                tmpResult = Cy_Crypto_Core_ED25519_ExpMod( base, p_uv, p_a, p_x, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, p_uv, p_uv, p_y, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                /* If v * x^2 = u (mod p), x is a square root. */
                tmpResult = Cy_Crypto_Core_ED25519_SquareMod( base, p_x, p_uv, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, p_x, p_x, p_d, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                if (Cy_Crypto_Core_Vu_IsRegEqual(base, p_x, p_y) != true)
                {
                    /* Otherwise if v x^2 = -u (mod p), x * 2^((p-1)/4) is a square
                    * root. */
                    Cy_Crypto_Core_EC_SubMod(base, p_x, VR_P, p_x);
                    if (Cy_Crypto_Core_Vu_IsRegEqual(base, p_x, p_y) != true)
                    {
                        return CY_CRYPTO_BAD_PARAMS;
                    }
                    /* x *= 2^((p-1)/4) */
                    Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)ed25519_sqrt_m1, bitsize);
                    tmpResult = Cy_Crypto_Core_ED25519_MulMod( base, p_x, p_uv, p_y, bitsize);
                    if(CY_CRYPTO_SUCCESS != tmpResult)
                    {
                        return tmpResult;
                    }
                }
                else
                {
                    p_x = p_uv;
                }
                /* Use the x_0 bit to select the right square root. */
                if (Cy_Crypto_Core_Vu_IsRegZero(base, p_x) && x_0 == 1u)
                {
                    return CY_CRYPTO_BAD_PARAMS;
                }
                else
                {
                    uint8_t *x = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_x);

                    if( (x[0] & 0x1u) != x_0)
                    {
                        Cy_Crypto_Core_EC_SubMod(base, p_x, VR_P, p_x);
                    }
                }

                Cy_Crypto_Core_Vu_GetMemValue (base, publicKeyXRemap, p_x, bitsize);
            }

            Cy_Crypto_Core_Vu_WaitForComplete(base);

            CY_CRYPTO_VU_FREE_MEM(base, CY_CRYPTO_VU_REG_BIT(p_x) | CY_CRYPTO_VU_REG_BIT(p_y) |
                                        CY_CRYPTO_VU_REG_BIT(p_a) | CY_CRYPTO_VU_REG_BIT(p_d) |
                                        CY_CRYPTO_VU_REG_BIT(VR_P)| CY_CRYPTO_VU_REG_BIT(p_uv)|
                                        CY_CRYPTO_VU_REG_BIT(VR_BARRETT));

            CY_CRYPTO_VU_POP_REG (base);
        }
    }
    return (tmpResult);
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_ED25519_Verify
****************************************************************************//**
*
* Verify ED25519 signed message.
*
* When D-Cache is enabled parameters hash, sig, key(x & y) and sigctx must align and end in 32 byte boundary.
*
* \param base
* The pointer to a Crypto instance.
*
* \param sig
* The signature to verify, 'R' followed by 'S'.
*
* \param hash
* The hash or message that was signed.
*
* \param hashlen
* The length of the hash or message (octets).
*
* \param stat
* Result of signature verification, 0xA1A1A1A1==valid, 0x00BADBAD==invalid.
*
* \param key
* The corresponding uncompressed public key to use (little-endian). See \ref cy_stc_crypto_ecc_key.
*
* \param sigType
* signature Type. CY_CRYPTO_EDDSA_PURE,CY_CRYPTO_EDDSA_CTX or CY_CRYPTO_EDDSA_PREHASH
*
* \param sigctx
* signature context. can be NULL if EDDSA_PURE is used or if no context is provided.
*
* \param sigctx_len
* The length of the signature context
*
* \return status code. See \ref cy_en_crypto_status_t.
*
*******************************************************************************/
cy_en_crypto_status_t Cy_Crypto_Core_ED25519_Verify(CRYPTO_Type *base, uint8_t *sig, const uint8_t *hash, uint32_t hashlen,
        const cy_stc_crypto_ecc_key *key, uint32_t *stat, cy_en_eddsa_sig_type_t sigType,const uint8_t *sigctx, uint32_t sigctx_len)
{
     cy_en_crypto_status_t tmpResult = CY_CRYPTO_BAD_PARAMS;

    uint8_t *sigPtrRemap;
    uint8_t *hashPtrRemap;
    uint8_t *pubKeyXRemap;
    uint8_t *pubKeyYRemap;
    uint32_t mallocMask = 0u;

    cy_stc_crypto_edw_dp_type edwDp_t;
    cy_stc_crypto_edw_dp_type *edwDp = &edwDp_t;

    /*
    Value of context is set by the signer and verifier (maximum of 255
    octets; the default is empty string, except for Ed25519, which can't
    have context) and has to match octet by octet for verification to be
    successful.
    */
    if(sigType == CY_CRYPTO_EDDSA_CTX)
    {
        if( sigctx == NULL  || sigctx_len == 0u || sigctx_len > 255u)
        {
            return CY_CRYPTO_BAD_PARAMS;
        }
    }

    /* input param validation */
    if ((hash == NULL) && (0u != hashlen))
    {
        return CY_CRYPTO_BAD_PARAMS;
    }

    if ((sig != NULL) && (stat != NULL)  && (sigType < CY_CRYPTO_EDDSA_NONE))
    {
        tmpResult = CY_CRYPTO_NOT_SUPPORTED;
        *stat = CY_ED25519SIG_VERIFY_FAIL;

        hashPtrRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(hash);
        sigPtrRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(sig);
        pubKeyXRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key->pubkey.x);
        pubKeyYRemap = (uint8_t *)CY_REMAP_ADDRESS_FOR_CRYPTO(key->pubkey.y);

        if(CY_CRYPTO_SUCCESS == Cy_Crypto_Core_EDW_GetCurveParams(edwDp, key->curveID))
        {
#if (CY_IP_MXCRYPTO_VERSION == 1u)
            cy_stc_crypto_v1_sha512_buffers_t shaBuffers_t;
            cy_stc_crypto_sha_state_t shaHashState_t;
            cy_stc_crypto_sha_state_t *shaHashState = &shaHashState_t;
            cy_stc_crypto_v1_sha512_buffers_t *shaBuffers = &shaBuffers_t;
#else
            uint8_t shaBuffers_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_v2_sha512_buffers_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
            uint8_t shaHashState_t[CY_CRYPTO_ALIGN_CACHE_LINE(sizeof(cy_stc_crypto_sha_state_t)) + CY_CRYPTO_DCAHCE_PADDING_SIZE];
            cy_stc_crypto_v2_sha512_buffers_t *shaBuffers = (cy_stc_crypto_v2_sha512_buffers_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(shaBuffers_t);
            cy_stc_crypto_sha_state_t *shaHashState = (cy_stc_crypto_sha_state_t *)CY_CRYPTO_DCACHE_ALIGN_ADDRESS(shaHashState_t);
#endif

            uint32_t bitsize  = edwDp->size;
            uint32_t bytesize = CY_CRYPTO_BYTE_SIZE_OF_BITS(edwDp->size);

            tmpResult = Cy_Crypto_Core_Sha_Init(base, shaHashState, (cy_en_crypto_sha_mode_t)CY_CRYPTO_MODE_SHA512, (void *)shaBuffers);
            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                tmpResult = Cy_Crypto_Core_Sha_Start(base, shaHashState);
            }

            if (CY_CRYPTO_SUCCESS == tmpResult)
            {
                uint32_t p_sha  = 4u;
                uint32_t p_temp = 5u;
                uint32_t p_r    = 6u;
                uint32_t p_s    = 7u;
                uint32_t p_x    = 8u;
                uint32_t p_y    = 9u;

                uint8_t *digest;
                uint8_t *pubkey_x;
                uint8_t *pubkey_y;
                uint8_t *sig_r;
                uint8_t *sig_s;

                sig_r = &sigPtrRemap[0];
                sig_s = &sigPtrRemap[bytesize];
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_r, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue(base, p_r, (uint8_t const *)sig_r,  bitsize+1u);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_s, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue(base, p_s, (uint8_t const *)sig_s,  bitsize+1u);

                /*Curve Order*/
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_P, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_P, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->order), bitsize);

                /* Check R and S range */
                if (Cy_Crypto_Core_Vu_IsRegZero(base, p_r))
                {
                    /* R is zero!!! */
                    return CY_CRYPTO_BAD_PARAMS;
                }
                if (Cy_Crypto_Core_Vu_IsRegZero(base, p_s))
                {
                    /* S is zero!!! */
                    return CY_CRYPTO_BAD_PARAMS;
                }

                /* Barret coef for Order*/
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_BARRETT, edwDp->barret_osize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_BARRETT, (uint8_t const*)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->barrett_o), edwDp->barret_osize);
                /* Gx co-ordinate */
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_S_X, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_S_X, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gx), bitsize);
                /* Gy co-ordinate */
                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, VR_S_Y, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, VR_S_Y, (uint8_t const *)CY_REMAP_ADDRESS_FOR_CRYPTO(edwDp->Gy), bitsize+1u);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_sha, (CY_CRYPTO_SHA512_HASH_SIZE*8u));
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                digest = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_sha);

               tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_temp, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_x, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, p_x, (uint8_t const *)pubKeyXRemap, bitsize+1u);

                tmpResult = CY_CRYPTO_VU_ALLOC_MEM (base, p_y, bitsize+1u);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }
                Cy_Crypto_Core_Vu_SetMemValue (base, p_y, (uint8_t const *)pubKeyYRemap, bitsize+1u);

                mallocMask = CY_CRYPTO_VU_REG_BIT(VR_P)   | CY_CRYPTO_VU_REG_BIT(VR_BARRETT) |
                             CY_CRYPTO_VU_REG_BIT(VR_S_X) | CY_CRYPTO_VU_REG_BIT(VR_S_Y) |
                             CY_CRYPTO_VU_REG_BIT(p_r)    | CY_CRYPTO_VU_REG_BIT(p_s) |
                             CY_CRYPTO_VU_REG_BIT(p_x)    | CY_CRYPTO_VU_REG_BIT(p_y) |
                             CY_CRYPTO_VU_REG_BIT(p_sha)  | CY_CRYPTO_VU_REG_BIT(p_temp);

                /* step1 */
                /*SHA expects big-endian*/
                if(sigType != CY_CRYPTO_EDDSA_PURE)
                {
                    Cy_Crypto_Core_ED25519_dom2_ctx( base, sigType, sigctx, sigctx_len, shaHashState);
                }

                /* step2: h = sha512(Rs + public + msg) mod N */
                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)sig_r, bytesize);
                /* compress public key */
                pubkey_x = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_x);
                pubkey_y = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, p_y);

                if((bool)(((uint8_t*)pubkey_x)[0] & (uint8_t)0x01))
                {
                    ((uint8_t*)pubkey_y)[31] |= (uint8_t)0x80;
                }
                /* interpret as little-endian */
                (void)Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)pubkey_y, bytesize);
                /* For EDDSA_PREHASH, buf should contain the SHA512 hash. It contains the whole message otherwise */
                tmpResult = Cy_Crypto_Core_Sha_Update(base, shaHashState, (uint8_t const*)hashPtrRemap, hashlen);
                if(CY_CRYPTO_SUCCESS == tmpResult)
                {
                    tmpResult = Cy_Crypto_Core_Sha_Finish(base, shaHashState, digest);
                    if(CY_CRYPTO_SUCCESS != tmpResult)
                    {
                        return tmpResult;
                    }
                }

                /* Mod reduction modulo n (order of the base point in VR_P and barret_o in VR_BARRET) */
                if ( CY_CRYPTO_SUCCESS != Cy_Crypto_Core_EDDSA_Bar_MulRed(base, p_temp, p_sha, bitsize) )
                {
                    return CY_CRYPTO_BAD_PARAMS;
                }
                /* Step 3 */
                /* We perform fast single-signature verification by compressing sB-hA and comparing with r without decompressing it */
                ((uint8_t*)pubkey_y)[31] &= (uint8_t)0x7F;

                CY_CRYPTO_VU_SUB (base, p_temp, VR_P, p_temp);
                /* R = sG + hA */
                tmpResult =  Cy_Crypto_Core_ED25519_PointMulAdd(base, edwDp, VR_S_X, VR_S_Y, p_s, p_x, p_y, p_temp, bitsize);
                if(CY_CRYPTO_SUCCESS != tmpResult)
                {
                    return tmpResult;
                }

                /* Compress R (we re-use pubkey_x & y)*/
                pubkey_x = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, VR_S_X);
                pubkey_y = (uint8_t *)Cy_Crypto_Core_Vu_RegMemPointer(base, VR_S_Y);
                if((bool)(((uint8_t*)pubkey_x)[0] & (uint8_t)0x01))
                {
                    ((uint8_t*)pubkey_y)[31] |= (uint8_t)0x80;
                }
                /* since its compressed we are free to compare with r without decompressing it */
                if (Cy_Crypto_Core_Vu_IsRegEqual(base, VR_S_Y, p_r))
                {
                    *stat = CY_ED25519SIG_VERIFY_PASS;
                }
                else
                {
                    *stat = CY_ED25519SIG_VERIFY_FAIL;
                }
                /* Free all mem allocations */
                CY_CRYPTO_VU_FREE_MEM(base, mallocMask);
                (void)Cy_Crypto_Core_Sha_Free(base, shaHashState);
            }
        }
    }

    return (tmpResult);
}
#endif /* defined(CY_CRYPTO_CFG_EDDSA_VERIFY_C) */
#endif /* (CY_CRYPTO_CFG_EDDSA_C) || defined(CY_CRYPTO_CFG_EC25519_C) */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */

/* [] END OF FILE */

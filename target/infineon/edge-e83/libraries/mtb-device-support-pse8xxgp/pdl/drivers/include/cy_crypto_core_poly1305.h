/***************************************************************************//**
* \file cy_crypto_core_poly1305.h
* \version 2.150
*
* \brief
*  This file provides constants and function prototypes
*  for the API for the poly1305 method in the Crypto block driver.
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


#if !defined (CY_CRYPTO_CORE_POLY1305_H)
#define CY_CRYPTO_CORE_POLY1305_H

#include "cy_crypto_common.h"

#if defined (CY_IP_MXCRYPTO)

#if defined(__cplusplus)
extern "C" {
#endif

/** \cond INTERNAL */

#if (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_POLY1305_ENABLED)

typedef struct
{
    uint32_t messageIndex;
    uint8_t *state;
    uint8_t *key;
    uint8_t *partialMessage;
} cy_stc_crypto_poly_1305_state_t;

/** Defines the poly1305 state size (in bytes) */
#define CY_CRYPTO_POLY1305_POLYNOMIAL_SIZE         (17u)

typedef struct
{
    uint8_t partialMessage[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_POLY1305_BLOCK_SIZE)];
    uint8_t state[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_POLY1305_STATE_SIZE)];
    uint8_t key[CY_CRYPTO_ALIGN_CACHE_LINE(CY_CRYPTO_POLY1305_KEY_SIZE)];
} cy_stc_crypto_poly_1305_buffers_t;

cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Init(CRYPTO_Type *base, uint8_t const *key, cy_stc_crypto_poly_1305_state_t *state, cy_stc_crypto_poly_1305_buffers_t *buffer);
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Update(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state, uint8_t const * p_message, uint32_t size);
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Finish(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state, uint8_t * p_mac);
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_Free(CRYPTO_Type *base, cy_stc_crypto_poly_1305_state_t *state);
cy_en_crypto_status_t Cy_Crypto_Core_poly_1305_mac(CRYPTO_Type *base, uint8_t const *key, uint8_t const * p_message, uint32_t size,  uint8_t * p_mac);



#endif /* #if #if (CPUSS_CRYPTO_VU == 1) && defined(CY_CRYPTO_CFG_POLY1305_ENABLED)*/

/** \endcond */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */

#endif /* #if !defined (CY_CRYPTO_CORE_POLY1305_H) */


/* [] END OF FILE */

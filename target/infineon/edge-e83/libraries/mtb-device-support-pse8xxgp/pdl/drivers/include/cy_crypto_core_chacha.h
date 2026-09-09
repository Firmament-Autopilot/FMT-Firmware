/***************************************************************************//**
* \file cy_crypto_core_chacha.h
* \version 2.150
*
* \brief
*  This file provides constants and function prototypes
*  for the API for the CHACHA method in the Crypto block driver.
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


#if !defined (CY_CRYPTO_CORE_CHACHA_H)
#define CY_CRYPTO_CORE_CHACHA_H

#include "cy_crypto_common.h"

#if defined (CY_IP_MXCRYPTO)

#if defined(__cplusplus)
extern "C" {
#endif

/** \cond INTERNAL */

#if defined(CY_CRYPTO_CFG_CHACHA_ENABLED) && (CPUSS_CRYPTO_CHACHA == 1)
CRYPTO_MEM_ALIGN typedef struct
{
    cy_stc_crypto_v2_chacha_input_buffer state;
    uint8_t keyStream[CHACHA_KEYSTREAM_SIZE];
} cy_stc_crypto_v2_chacha_buffers_t;

cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_Init(CRYPTO_Type *base,
                             cy_stc_crypto_chacha_state_t *chachaState,
                             uint8_t rounds,
                             cy_stc_crypto_v2_chacha_buffers_t * chachaBuffers);


cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_start(CRYPTO_Type *base, cy_stc_crypto_chacha_state_t *chachaState,
                             uint8_t const *key,
                             uint8_t const *nonce,
                             uint32_t counter);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_update(CRYPTO_Type *base,  cy_stc_crypto_chacha_state_t *chachaState, uint8_t const *input, uint32_t inputSize, uint8_t *output);

cy_en_crypto_status_t Cy_Crypto_Core_Chacha20(CRYPTO_Type *base,
                                     uint8_t const *key, uint8_t const *nonce, uint32_t counter, uint8_t const *input,
                                     uint32_t inputSize, uint8_t *output);

cy_en_crypto_status_t Cy_Crypto_Core_V2_Chacha_Free(CRYPTO_Type *base, cy_stc_crypto_chacha_state_t *chachaState);



#endif /* #if (CPUSS_CRYPTO_CHACHA == 1)  && (CPUSS_CRYPTO_CHACHA == 1)*/

/** \endcond */

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */

#endif /* #if !defined (CY_CRYPTO_CORE_CHACHA_H) */


/* [] END OF FILE */

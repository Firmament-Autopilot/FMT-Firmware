/***************************************************************************//**
* \file mtb_hal_trng_mxcrypto.h
*
* \brief
* Provides common API declarations of the mxcrypto driver
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include "mtb_hal_trng.h"
#include <stdlib.h>
#include "cy_pdl.h"

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(CY_IP_MXCRYPTO) || defined(CPUSS_CRYPTO_PRESENT)

/*******************************************************************************
*                           Defines
*******************************************************************************/

/** Galois ring oscillator value */
#define MTB_HAL_GARO31_INITSTATE        (0x04c11db7UL)
/** Fibonacci ring oscillator value */
#define MTB_HAL_FIRO31_INITSTATE        (0x04c11db7UL)

#define MAX_TRNG_BIT_SIZE               (32UL)

/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/


/*******************************************************************************
*                         Inlined functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_trng_setup
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_trng_setup(mtb_hal_trng_t* obj)
{
    obj->base = CRYPTO;
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_trng_get_uint32_internal
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_trng_get_uint32_internal(const mtb_hal_trng_t* obj,
                                                            uint32_t* value)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != obj->base);
    return (cy_rslt_t)Cy_Crypto_Core_Trng(
        obj->base, MTB_HAL_GARO31_INITSTATE, MTB_HAL_FIRO31_INITSTATE, MAX_TRNG_BIT_SIZE, value);
}


#define mtb_hal_trng_get_uint32(obj, value) _mtb_hal_trng_get_uint32_internal(obj, value)

#endif /* defined(CY_IP_MXCRYPTO) || defined(CPUSS_CRYPTO_PRESENT) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

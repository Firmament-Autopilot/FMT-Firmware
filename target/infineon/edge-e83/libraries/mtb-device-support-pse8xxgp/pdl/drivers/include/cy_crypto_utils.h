/***************************************************************************//**
* \file cy_crypto_utils.h
* \version 2.150
*
* \brief
*  This file provides provides helper functions
*  for the Crypto driver.
*
********************************************************************************
* Copyright 2025 Cypress Semiconductor Corporation
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
#if !defined (CY_CRYPTO_UTILS_H)
#define CY_CRYPTO_UTILS_H

#include "cy_device.h"

#if defined(CY_IP_MXCRYPTO)

#if defined(__cplusplus)
extern "C" {
#endif


/**
* \addtogroup group_crypto_lld_mem_functions
* \{
*/
/*******************************************************************************
* Function Name: Cy_Crypto_InvertEndianness
****************************************************************************//**
*
* This function inverts endianness of the byte-array.
* Odd or even byteSize are acceptable.
*
* \param inArrPtr
* The pointer to the memory whose endianness is to be inverted.
*
* \param byteSize
* The length of the memory array whose endianness is to be inverted (in bytes)
*
*******************************************************************************/
void Cy_Crypto_InvertEndianness(void *inArrPtr, uint32_t byteSize);

/** \cond INTERNAL */
/* For backward compatibility */
#define Cy_Crypto_Rsa_InvertEndianness(p, s) Cy_Crypto_InvertEndianness((p), (s))
/** \endcond */

/** \} group_crypto_lld_mem_functions */


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXCRYPTO */

#endif
/* [] END OF FILE */

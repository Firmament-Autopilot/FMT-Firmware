/***************************************************************************//**
* \file cy_crypto_utils.c
* \version 2.150
*
* \brief
*  Provides utility functions.
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
#include "cy_device.h"

#if defined (CY_IP_MXCRYPTO)

#include "cy_crypto_utils.h"
#include <stdlib.h>

void Cy_Crypto_InvertEndianness(void *inArrPtr, uint32_t byteSize)
{
    int32_t limit;
    int32_t i;
    int32_t j = 0;
    uint8_t temp;
    uint8_t *tempPtr = (uint8_t*)inArrPtr;

    if (byteSize > 1u)
    {
        limit = (int32_t)byteSize / 2;
        if (0u == (byteSize % 2u))
        {
            --limit;
        }

        j = 0;
        i = (int32_t)byteSize - 1;
        while ( i > limit)
        {
            temp = tempPtr[j];
            tempPtr[j] = tempPtr[i];
            tempPtr[i] = temp;

            --i;
            ++j;
        }
    }
}


#endif /*defined(CY_IP_MXCRYPTO)*/

/***************************************************************************//**
* \file mtb_hal_uart_common.h
*
* \brief
* Provides IP Specific common API declarations that is applicable for multiple
* IP versions of the SCB drivers
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

#include <stdlib.h>
#include "cy_pdl.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */


/*******************************************************************************
*                           Defines
*******************************************************************************/


/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/
/** Return the SCB data transfer width, in bytes */
__STATIC_INLINE uint32_t _mtb_hal_scb_get_transfer_width(CySCB_Type* base)
{
    uint32_t transfer_width = 0;

    uint8_t mem_width = _FLD2VAL(SCB_CTRL_MEM_WIDTH, SCB_CTRL(base));
    if (CY_SCB_MEM_WIDTH_BYTE == mem_width)
    {
        transfer_width = 1;
    }
    else if (CY_SCB_MEM_WIDTH_HALFWORD == mem_width)
    {
        transfer_width = 2;
    }
    else
    {
        transfer_width = 4;
    }
    return transfer_width;
}


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

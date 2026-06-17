/***************************************************************************//**
* \file mtb_hal_i2c_mxs22scb_v1.h
*
* \brief
* Provides common API declarations of the mxs22scb_v1 driver
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
__STATIC_INLINE void _mtb_hal_scb_i2c_enable(CySCB_Type* base, cy_stc_scb_i2c_context_t* context)
{
    CY_UNUSED_PARAMETER(context);
    (void)Cy_SCB_I2C_Enable(base);
}


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

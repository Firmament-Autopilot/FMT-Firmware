/*******************************************************************************
* \file mtb_syspm_callbacks_nvm_mxs22rramc.h
*
* Description:
* Provides the implementation for syspm callbacks for the MXS22RRAMC IP
*
********************************************************************************
* \copyright
* Copyright 2024-2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
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

#include "cy_pdl.h"
#include "cy_utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined (CY_IP_MXS22RRAMC)

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 2, \
                             'API definitions must match between IPs and not all IPs allow the arguments to be const');
//--------------------------------------------------------------------------------------------------
// _mtb_syspm_nvm_check_ready
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_syspm_nvm_check_ready(mtb_syspm_nvm_type_t type, void* base)
{
    /* This IP needs no check-ready update */
    CY_UNUSED_PARAMETER(type);
    CY_UNUSED_PARAMETER(base);
    return true;
}


//--------------------------------------------------------------------------------------------------
// _mtb_syspm_nvm_before_transition
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_syspm_nvm_before_transition(mtb_syspm_nvm_type_t type, void* base)
{
    /* A note on the "(uint32_t)enum == (uint32_t)enum" below - in some very specific
     * cases, the basic "context->enum == enum" can be automatically cast into a
     * "int32_t == uint32_t" comparison.  Cast both to uint32_t to avoid this. */
    if (((uint32_t)(type) == (uint32_t)(MTB_SYSPM_NVM_TYPE_OTP))
        || ((uint32_t)(type) == (uint32_t)(MTB_SYSPM_NVM_TYPE_RRAM)))
    {
        /* RRAM/OTP works in sleep, but we must set to sleep mode */
        Cy_RRAM_EnableSleepMode((RRAMC_Type*)(base));
    }
    return true;
}


//--------------------------------------------------------------------------------------------------
// _mtb_syspm_nvm_after_transition
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_syspm_nvm_after_transition(mtb_syspm_nvm_type_t type, void* base)
{
    /* A note on the "(uint32_t)enum == (uint32_t)enum" below - in some very specific
     * cases, the basic "context->enum == enum" can be automatically cast into a
     * "int32_t == uint32_t" comparison.  Cast both to uint32_t to avoid this. */
    if (((uint32_t)(type) == (uint32_t)(MTB_SYSPM_NVM_TYPE_OTP))
        || ((uint32_t)(type) == (uint32_t)(MTB_SYSPM_NVM_TYPE_RRAM)))
    {
        /* Restore RRAM/OTP to normal mode */
        Cy_RRAM_DisableSleepMode((RRAMC_Type*)(base));
    }
    return true;
}


//--------------------------------------------------------------------------------------------------
// _mtb_syspm_nvm_check_fail
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_syspm_nvm_check_fail(mtb_syspm_nvm_type_t type, void* base)
{
    /* This IP needs no check-fail update */
    CY_UNUSED_PARAMETER(type);
    CY_UNUSED_PARAMETER(base);
    return true;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');

#endif /* defined (CY_IP_MXS22RRAMC) */

#if defined(__cplusplus)
}
#endif

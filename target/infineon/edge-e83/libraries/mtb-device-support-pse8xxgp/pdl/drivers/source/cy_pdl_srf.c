/***************************************************************************//**
* \file cy_pdl_srf.c
* \version 1.000
*
* This file contains the PDL SRF module registration and information on the
* sub-modules.
*
********************************************************************************
* \copyright
* Copyright (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
*
*******************************************************************************/

#include "cy_pdl_srf.h"

#if defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE)

/* If the user marks every Secure Aware PPC region as NS but leaves CY_PDL_ENABLE_SECURE_AWARE enabled,
 * swap module registration to a NOP */
#if defined(CY_PDL_RTC_ENABLE_SRF_INTEG) || defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) || defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
#define CY_PDL_ENABLE_SRF_INTEG (1)
#endif

#if (CY_PDL_ENABLE_SRF_INTEG)

mtb_srf_op_s_t* cy_pdl_srf_operations[CY_PDL_SECURE_SUBMODULE_END] =
{
#if defined(CY_PDL_RTC_ENABLE_SRF_INTEG)
    _cy_pdl_rtc_srf_operations,
#endif /* defined(CY_PDL_RTC_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    _cy_pdl_smif_srf_operations,
#endif /* defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
    _cy_pdl_sysclk_srf_operations,
#endif /* defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    _cy_pdl_syspm_srf_operations,
#endif /* defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */
};

size_t cy_pdl_srf_num_operations[] =
{
#if defined(CY_PDL_RTC_ENABLE_SRF_INTEG)
    sizeof(_cy_pdl_rtc_srf_operations) / sizeof(_cy_pdl_rtc_srf_operations[0]),
#endif /* defined(CY_PDL_RTC_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SMIF_ENABLE_SRF_INTEG)
    sizeof(_cy_pdl_smif_srf_operations) / sizeof(_cy_pdl_smif_srf_operations[0]),
#endif /* defined(CY_PDL_SMIF_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
    sizeof(_cy_pdl_sysclk_srf_operations) / sizeof(_cy_pdl_sysclk_srf_operations[0]),
#endif /* defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */
#if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    sizeof(_cy_pdl_syspm_srf_operations) / sizeof(_cy_pdl_syspm_srf_operations[0]),
#endif /* defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */
};

mtb_srf_module_s_t _cy_pdl_srf_module =
{
    .module_id = MTB_SRF_MODULE_PDL,
    .op_by_submod = cy_pdl_srf_operations,
    .num_op_by_submod = cy_pdl_srf_num_operations,
    .num_submod = CY_PDL_SECURE_SUBMODULE_END
};

#endif

cy_rslt_t cy_pdl_srf_module_register(mtb_srf_context_s_t* context)
{
    #if (CY_PDL_ENABLE_SRF_INTEG)
    return mtb_srf_module_register(context, &_cy_pdl_srf_module);
    #else
    CY_UNUSED_PARAMETER(context);
    /* If all PPC regions are disabled, then there's no point in registering anything */
    return CY_RSLT_SUCCESS;
    #endif
}

#endif /* defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_ENABLE_SECURE_AWARE) */

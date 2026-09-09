/***************************************************************************//**
* \file cy_sysclk_v2.c
* \version 3.150
*
* Provides an API implementation of the sysclk driver.
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
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
*******************************************************************************/

#include "cy_device.h"

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)

#include "cy_sysclk.h"
#include "cy_syslib.h"
#include <stdlib.h>
#include <string.h>

/* Static variable declarations */
/* Cy_SysClk_StartClkMeasurementCounters() input parameter saved for use later in other functions */
static uint32_t clk1Count1;

/* These variables act as locks to prevent collisions between clock measurement and entry into
   Deep Sleep mode. See Cy_SysClk_DeepSleep(). */
static bool clkCounting = false;
static bool preventCounting = false;

/* End static variable section */

#if defined (CY_IP_MXS22SRSS)
#define SLOW_SEL_OUTPUT_INDEX       11UL
#else
#define SLOW_SEL_OUTPUT_INDEX       7UL
#endif

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
#define CSV_MIN_TARGET_VAL          200UL /* Minimum Target value to get 1 percent accuracy for CSV (Clock Supervision). */
#define CSV_MIN_STARTUP_DELAY       0.0001F /* Minimum Start up delay value 100 usec*/
#endif

/* ECO Prescaler timeout value in micro seconds */
#define CY_SYSCLK_ECO_PRESCALER_TIMEOUT_US 1000U

/*******************************************************************************
*    Secure Aware Support
*******************************************************************************/
#if defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && (CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
typedef struct {
    cy_en_sysclk_status_t status;
} cy_pdl_sysclk_srf_status_out_t;

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF)
typedef struct {
    bool is_enabled;
} cy_pdl_sysclk_srf_clkhf_is_enabled_out_t;

typedef struct {
    cy_en_clkhf_dividers_t found_div;
} cy_pdl_sysclk_srf_clkhf_get_div_out_t;

typedef struct {
    cy_en_clkhf_dividers_t divider;
} cy_pdl_sysclk_srf_clkhf_set_div_in_t;

typedef struct {
    uint32_t freq;
} cy_pdl_sysclk_srf_clkhf_get_freq_out_t;
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF) */
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF)
typedef struct {
    uint32_t freq;
} cy_pdl_sysclk_srf_clklf_get_freq_num_out_t;
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF) */
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)
typedef struct {
    uint32_t found_div;
} cy_pdl_sysclk_srf_perigroup_get_div_out_t;

typedef struct {
    uint32_t divider;
} cy_pdl_sysclk_srf_perigroup_set_div_in_t;

#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) */
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)
typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
} cy_pdl_sysclk_srf_peripclk_get_div_in_t;

typedef struct {
    uint32_t found_div;
} cy_pdl_sysclk_srf_peripclk_get_div_out_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
    uint32_t dividerVal;
} cy_pdl_sysclk_srf_peripclk_set_div_in_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
} cy_pdl_sysclk_srf_peripclk_get_frac_div_in_t;

typedef struct {
    uint32_t dividerIntValue;
    uint32_t dividerFracValue;
} cy_pdl_sysclk_srf_peripclk_get_frac_div_out_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
    uint32_t dividerIntValue;
    uint32_t dividerFracValue;
} cy_pdl_sysclk_srf_peripclk_set_frac_div_in_t;

typedef struct {
    uint32_t assigned_div;
} cy_pdl_sysclk_srf_peripclk_get_assn_div_out_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
} cy_pdl_sysclk_srf_peripclk_enable_in_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
} cy_pdl_sysclk_srf_peripclk_disable_in_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
} cy_pdl_sysclk_srf_peripclk_get_freq_in_t;

typedef struct {
    uint32_t freq;
} cy_pdl_sysclk_srf_peripclk_get_freq_out_t;

typedef struct {
    cy_en_divider_types_t dividerType;
    uint32_t dividerNum;
} cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_in_t;

typedef struct {
    bool is_enabled;
} cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_out_t;
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */

#endif /* defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && (CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)
/* Track which PERI's are marked Secured for run-time checking */
static bool mtb_pdl_sysclk_peri_group_div_srf_secured[] =
{
#if (PERI0_PCLK_GROUP_NR > 0) && defined(CYCFG_PPC_SECURED_PERI_PCLK0_MAIN)
    CYCFG_PPC_SECURED_PERI_PCLK0_MAIN,
#else
    0,
#endif
#if (PERI1_PCLK_GROUP_NR > 0) && defined(CYCFG_PPC_SECURED_PERI_PCLK1_MAIN)
    CYCFG_PPC_SECURED_PERI_PCLK1_MAIN,
#else
    0,
#endif
#if (PERI2_PCLK_GROUP_NR > 0)
    #error Incomplete mtb_pdl_sysclk_peri_group_div_srf_secured array
#endif
};
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)
/* Track which PERI Groups's are marked Secured for run-time checking */
static bool mtb_pdl_sysclk_peri0_group_srf_secured[] =
{
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR0_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR0_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR1_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR1_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR2_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR2_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR3_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR3_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR4_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR4_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR5_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI0_GR5_GROUP,
#else
    0,
#endif
};
static bool mtb_pdl_sysclk_peri1_group_srf_secured[] =
{
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR0_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR0_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR1_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR1_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR2_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR2_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR3_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR3_GROUP,
#else
    0,
#endif
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR4_GROUP)
    _CY_PDL_SYSCLK_PPC_SECURED_PERI1_GR4_GROUP,
#else
    0,
#endif
};
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)*/

#endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG)
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF)
/* Default CLK_HF permissions.  These may be overriden by declaring a custom structure.  It is
* not recommended to allow writing to CLK_HF instances that feed the CPU(s). */
__WEAK mtb_srf_permission_s_t mtb_pdl_sysclk_clkhf_srf_permissions[] = /* SRSS_NUM_HFROOT */
{
    {
        .base = NULL,
        .sub_block = 0UL,
        .write_allowed = false,
    },
#if (SRSS_NUM_HFROOT > 0)
    {
        .base = NULL,
        .sub_block = 1UL,
        .write_allowed = false,
    },
#endif
#if (SRSS_NUM_HFROOT > 1)
    {
        .base = NULL,
        .sub_block = 2UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 2)
    {
        .base = NULL,
        .sub_block = 3UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 3)
    {
        .base = NULL,
        .sub_block = 4UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 4)
    {
        .base = NULL,
        .sub_block = 5UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 5)
    {
        .base = NULL,
        .sub_block = 6UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 6)
    {
        .base = NULL,
        .sub_block = 7UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 7)
    {
        .base = NULL,
        .sub_block = 8UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 8)
    {
        .base = NULL,
        .sub_block = 9UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 9)
    {
        .base = NULL,
        .sub_block = 10UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 10)
    {
        .base = NULL,
        .sub_block = 11UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 12)
    {
        .base = NULL,
        .sub_block = 13UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 13)
    {
        .base = NULL,
        .sub_block = 14UL,
        .write_allowed = true,
    },
#endif
#if (SRSS_NUM_HFROOT > 14)
    #error Incomplete mtb_pdl_sysclk_clkhf_srf_permissions array
#endif
};
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF) */


#if defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF)

__WEAK mtb_srf_permission_s_t mtb_pdl_sysclk_clklf_srf_permissions[] =
{
    {
        .base = NULL,
        .sub_block = 0UL,
        .write_allowed = false,
    }
};
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF) */

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)
/* PERI0_PCLK_GROUP_NR + PERI1_PCLK_GROUP_NR - These are Peripheral Clock Divider Groups */
__WEAK mtb_srf_permission_s_t mtb_pdl_sysclk_peri_group_div_srf_permissions[] =
{
    {
        .base = PERI0,
        .sub_block = 0UL,
        .write_allowed = true,
    },
#if (PERI0_PCLK_GROUP_NR > 0)
    {
        .base = PERI0,
        .sub_block = 1UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 1)
    {
        .base = PERI0,
        .sub_block = 2UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 2)
    {
        .base = PERI0,
        .sub_block = 3UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 3)
    {
        .base = PERI0,
        .sub_block = 4UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 4)
    {
        .base = PERI0,
        .sub_block = 5UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 5)
    {
        .base = PERI0,
        .sub_block = 6UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 6)
    {
        .base = PERI0,
        .sub_block = 7UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 7)
    {
        .base = PERI0,
        .sub_block = 8UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 8)
    {
        .base = PERI0,
        .sub_block = 9UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 9)
    {
        .base = PERI0,
        .sub_block = 10UL,
        .write_allowed = true,
    },
#endif
#if (PERI0_PCLK_GROUP_NR > 10)
    #error Incomplete mtb_pdl_sysclk_peri_group_div_srf_permissions array
#endif
    {
        .base = PERI1,
        .sub_block = 0UL,
        .write_allowed = true,
    },
#if (PERI1_PCLK_GROUP_NR > 0)
    {
        .base = PERI1,
        .sub_block = 1UL,
        .write_allowed = true,
    },
#endif
#if (PERI1_PCLK_GROUP_NR > 1)
    {
        .base = PERI1,
        .sub_block = 2UL,
        .write_allowed = true,
    },
#endif
#if (PERI1_PCLK_GROUP_NR > 2)
    {
        .base = PERI1,
        .sub_block = 3UL,
        .write_allowed = true,
    },
#endif
#if (PERI1_PCLK_GROUP_NR > 3)
    {
        .base = PERI1,
        .sub_block = 4UL,
        .write_allowed = true,
    },
#endif
#if (PERI1_PCLK_GROUP_NR > 4)
    {
        .base = PERI1,
        .sub_block = 5UL,
        .write_allowed = true,
    },
#endif
#if (PERI1_PCLK_GROUP_NR > 5)
    {
        .base = PERI1,
        .sub_block = 6UL,
        .write_allowed = true,
    },
#endif
#if (PERI1_PCLK_GROUP_NR > 6)
    #error Incomplete mtb_pdl_sysclk_peri_group_div_srf_permissions array
#endif
};
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)
/* These are Peripheral Groups, e.g. MMIO */
__WEAK mtb_srf_permission_s_t mtb_pdl_sysclk_perigroup_srf_permissions[] =
{
    {
        .base = PERI0,
        .sub_block = PERI_0_GROUP_0,
        .write_allowed = true,
    },
    {
        .base = PERI0,
        .sub_block = PERI_0_GROUP_1,
        .write_allowed = true,
    },
    {
        .base = PERI0,
        .sub_block = PERI_0_GROUP_2,
        .write_allowed = true,
    },
    {
        .base = PERI0,
        .sub_block = PERI_0_GROUP_3,
        .write_allowed = true,
    },
    {
        .base = PERI0,
        .sub_block = PERI_0_GROUP_4,
        .write_allowed = true,
    },
    {
        .base = PERI0,
        .sub_block = PERI_0_GROUP_5,
        .write_allowed = true,
    },
    {
        .base = PERI1,
        .sub_block = PERI_1_GROUP_0,
        .write_allowed = true,
    },
    {
        .base = PERI1,
        .sub_block = PERI_1_GROUP_1,
        .write_allowed = true,
    },
    {
        .base = PERI1,
        .sub_block = PERI_1_GROUP_2,
        .write_allowed = true,
    },
    {
        .base = PERI1,
        .sub_block = PERI_1_GROUP_3,
        .write_allowed = true,
    },
    {
        .base = PERI1,
        .sub_block = PERI_1_GROUP_4,
        .write_allowed = true,
    },
};
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) */

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF)
cy_rslt_t cy_pdl_sysclk_srf_clkhf_is_enabled_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_HF_IS_ENABLED);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_clkhf_is_enabled_out_t output;
    uint32_t clkHf = (inputs_ns->request).sub_block;
    output.is_enabled = Cy_SysClk_ClkHfIsEnabled(clkHf);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_clkhf_get_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_HF_GET_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_clkhf_get_div_out_t output;
    uint32_t clkHf = (inputs_ns->request).sub_block;
    output.found_div = Cy_SysClk_ClkHfGetDivider(clkHf);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_clkhf_set_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_HF_SET_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_clkhf_set_div_in_t input;
    cy_pdl_sysclk_srf_status_out_t output;
    uint32_t clkHf = (inputs_ns->request).sub_block;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.status = Cy_SysClk_ClkHfSetDivider(clkHf, input.divider);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_clkhf_get_freq_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_HF_GET_FREQ);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_clkhf_get_freq_out_t output;
    uint32_t clkHf = (inputs_ns->request).sub_block;
    output.freq = Cy_SysClk_ClkHfGetFrequency(clkHf);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF) */

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF)
cy_rslt_t cy_pdl_sysclk_srf_clklf_get_freq_num_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_CLKLF_GET_FREQ);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_clklf_get_freq_num_out_t output;
    output.freq = Cy_SysClk_ClkLfGetFrequency();
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF) */

#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)
cy_rslt_t cy_pdl_sysclk_srf_perigroup_get_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERI_GET_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_perigroup_get_div_out_t output;
    uint32_t groupNum = (inputs_ns->request).sub_block;
    output.found_div = Cy_SysClk_PeriGroupGetDivider(groupNum);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_perigroup_set_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERI_SET_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_perigroup_set_div_in_t input;
    cy_pdl_sysclk_srf_status_out_t output;
    uint32_t groupNum = (inputs_ns->request).sub_block;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.status = Cy_SysClk_PeriGroupSetDivider(groupNum, input.divider);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) */


#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)
static en_clk_dst_t Cy_SysClk_PeriPclkMakeIpBlock(uint32_t grpNum, uint32_t instNum)
{
  return (en_clk_dst_t)(
    ((grpNum << PERI_PCLK_GR_NUM_Pos) & PERI_PCLK_GR_NUM_Msk) |
    ((instNum << PERI_PCLK_INST_NUM_Pos) & PERI_PCLK_INST_NUM_Msk)
    );
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_get_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_get_div_in_t input;
    cy_pdl_sysclk_srf_peripclk_get_div_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.found_div = Cy_SysClk_PeriPclkGetDivider(ipBlock, input.dividerType, input.dividerNum);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_set_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                mtb_srf_output_ns_t* outputs_ns,
                                                mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                uint8_t inputs_ptr_cnt_ns,
                                                mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_SET_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_set_div_in_t input;
    cy_pdl_sysclk_srf_status_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.status = Cy_SysClk_PeriPclkSetDivider(ipBlock, input.dividerType, input.dividerNum, input.dividerVal);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_get_frac_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_GET_FRAC_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_get_frac_div_in_t input;
    cy_pdl_sysclk_srf_peripclk_get_frac_div_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    Cy_SysClk_PeriPclkGetFracDivider(ipBlock, input.dividerType, input.dividerNum, &output.dividerIntValue, &output.dividerFracValue);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}


cy_rslt_t cy_pdl_sysclk_srf_peripclk_set_frac_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_SET_FRAC_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_set_frac_div_in_t input;
    cy_pdl_sysclk_srf_status_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.status = Cy_SysClk_PeriPclkSetFracDivider(ipBlock, input.dividerType, input.dividerNum, input.dividerIntValue, input.dividerFracValue);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_get_assn_div_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_GET_ASSN_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_get_assn_div_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);

    output.assigned_div = Cy_SysClk_PeriPclkGetAssignedDivider(ipBlock);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_enable_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_ENABLE_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_enable_in_t input;
    cy_pdl_sysclk_srf_status_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.status = Cy_SysClk_PeriPclkEnableDivider(ipBlock, input.dividerType, input.dividerNum);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_disable_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_DISABLE_DIV);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_disable_in_t input;
    cy_pdl_sysclk_srf_status_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.status = Cy_SysClk_PeriPclkDisableDivider(ipBlock, input.dividerType, input.dividerNum);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_get_freq_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_GET_FREQ);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_get_freq_in_t input;
    cy_pdl_sysclk_srf_peripclk_get_freq_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.freq = Cy_SysClk_PeriPclkGetFrequency(ipBlock, input.dividerType, input.dividerNum);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                                        mtb_srf_output_ns_t* outputs_ns,
                                                        mtb_srf_invec_ns_t* inputs_ptr_ns,
                                                        uint8_t inputs_ptr_cnt_ns,
                                                        mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                                        uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    CY_ASSERT_L2((inputs_ns->request).module_id == MTB_SRF_MODULE_PDL);
    CY_ASSERT_L2((inputs_ns->request).op_id == CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV_ENABLED);
    CY_ASSERT_L2((inputs_ns->request).submodule_id == CY_PDL_SECURE_SUBMODULE_SYSCLK);

    cy_rslt_t status;
    cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_in_t input;
    cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_out_t output;
    uint32_t grpNum = (inputs_ns->request).sub_block;
    uint32_t instNum = (((inputs_ns->request).base == PERI0) ? 0U : 1U);
    en_clk_dst_t ipBlock = Cy_SysClk_PeriPclkMakeIpBlock(grpNum, instNum);
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.is_enabled = Cy_SysClk_PeriPclkGetDividerEnabled(ipBlock, input.dividerType, input.dividerNum);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */

/* All operations for the SysCLK submodule of the PDL module */
mtb_srf_op_s_t _cy_pdl_sysclk_srf_operations[] =
{
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF)
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_HF_IS_ENABLED,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_clkhf_is_enabled_impl_s,
        .input_values_len = 0U,
        .output_values_len = sizeof(cy_pdl_sysclk_srf_clkhf_is_enabled_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_clkhf_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_clkhf_srf_permissions)/sizeof(mtb_pdl_sysclk_clkhf_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_HF_GET_DIV,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_clkhf_get_div_impl_s,
        .input_values_len = 0U,
        .output_values_len = sizeof(cy_pdl_sysclk_srf_clkhf_get_div_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_clkhf_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_clkhf_srf_permissions)/sizeof(mtb_pdl_sysclk_clkhf_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_HF_SET_DIV,
        .write_required = true,
        .impl = cy_pdl_sysclk_srf_clkhf_set_div_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_clkhf_set_div_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_status_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_clkhf_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_clkhf_srf_permissions)/sizeof(mtb_pdl_sysclk_clkhf_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_HF_GET_FREQ,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_clkhf_get_freq_impl_s,
        .input_values_len = 0U,
        .output_values_len = sizeof(cy_pdl_sysclk_srf_clkhf_get_freq_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_clkhf_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_clkhf_srf_permissions)/sizeof(mtb_pdl_sysclk_clkhf_srf_permissions[0]))
    },
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF) */
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF)
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_CLKLF_GET_FREQ,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_clklf_get_freq_num_impl_s,
        .input_values_len = 0U,
        .output_values_len = sizeof(cy_pdl_sysclk_srf_clklf_get_freq_num_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_clklf_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_clklf_srf_permissions) / sizeof(mtb_pdl_sysclk_clklf_srf_permissions[0]))
    },
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF) */
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP)
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERI_GET_DIV,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_perigroup_get_div_impl_s,
        .input_values_len = 0U,
        .output_values_len = sizeof(cy_pdl_sysclk_srf_perigroup_get_div_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_perigroup_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_perigroup_srf_permissions)/sizeof(mtb_pdl_sysclk_perigroup_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERI_SET_DIV,
        .write_required = true,
        .impl = cy_pdl_sysclk_srf_perigroup_set_div_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_perigroup_set_div_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_status_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_perigroup_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_perigroup_srf_permissions)/sizeof(mtb_pdl_sysclk_perigroup_srf_permissions[0]))
    },
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) */
#if defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK)
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_peripclk_get_div_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_div_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_div_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_SET_DIV,
        .write_required = true,
        .impl = cy_pdl_sysclk_srf_peripclk_set_div_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_set_div_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_status_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_FRAC_DIV,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_peripclk_get_frac_div_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_frac_div_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_frac_div_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_SET_FRAC_DIV,
        .write_required = true,
        .impl = cy_pdl_sysclk_srf_peripclk_set_frac_div_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_set_frac_div_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_status_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_ASSN_DIV,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_peripclk_get_assn_div_impl_s,
        .input_values_len = 0U,
        .output_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_assn_div_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_ENABLE_DIV,
        .write_required = true,
        .impl = cy_pdl_sysclk_srf_peripclk_enable_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_enable_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_status_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_DISABLE_DIV,
        .write_required = true,
        .impl = cy_pdl_sysclk_srf_peripclk_disable_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_disable_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_status_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_FREQ,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_peripclk_get_freq_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_freq_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_freq_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV_ENABLED,
        .write_required = false,
        .impl = cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_impl_s,
        .input_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_in_t),
        .output_values_len = sizeof(cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_out_t),
        .input_len = {0, 0, 0},
        .needs_copy = { false, false, false },
        .output_len = {0, 0, 0},
        .allowed_rsc = mtb_pdl_sysclk_peri_group_div_srf_permissions,
        .num_allowed = (sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions) / sizeof(mtb_pdl_sysclk_peri_group_div_srf_permissions[0]))
    },
#endif /* defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) */
};

#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) */


cy_en_sysclk_status_t Cy_SysClk_PeriPclkSetDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType,
                                                  uint32_t dividerNum, uint32_t dividerValue)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;

#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_set_div_in_t input_args;
        cy_pdl_sysclk_srf_status_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;
        input_args.dividerVal = dividerValue;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_SET_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.status;
    }
#endif

    if (dividerType == CY_SYSCLK_DIV_8_BIT)
    {
        if ((dividerNum < (PERI_PCLK_GR_DIV_8_NR(instNum, grpNum))) &&
            (dividerValue <= (PERI_DIV_8_CTL_INT8_DIV_Msk >> PERI_DIV_8_CTL_INT8_DIV_Pos)))
        {
            CY_REG32_CLR_SET(PERI_DIV_8_CTL(instNum, grpNum, dividerNum), PERI_DIV_8_CTL_INT8_DIV, dividerValue);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else if (dividerType == CY_SYSCLK_DIV_16_BIT)
    {
        if ((dividerNum < (PERI_PCLK_GR_DIV_16_NR(instNum, grpNum))) &&
            (dividerValue <= (PERI_DIV_16_CTL_INT16_DIV_Msk >> PERI_DIV_16_CTL_INT16_DIV_Pos)))
        {
            CY_REG32_CLR_SET(PERI_DIV_16_CTL(instNum, grpNum, dividerNum), PERI_DIV_16_CTL_INT16_DIV, dividerValue);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else
    { /* return bad parameter */
    }
    return (retVal);
}


uint32_t Cy_SysClk_PeriPclkGetDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    uint32_t retVal;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_get_div_in_t input_args;
        cy_pdl_sysclk_srf_peripclk_get_div_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.found_div;
    }
#endif

    CY_ASSERT_L1(dividerType <= CY_SYSCLK_DIV_16_BIT);
    if (dividerType == CY_SYSCLK_DIV_8_BIT)
    {
        CY_ASSERT_L1(dividerNum < PERI_PCLK_GR_DIV_8_NR(instNum, grpNum));
        retVal = _FLD2VAL(PERI_DIV_8_CTL_INT8_DIV, PERI_DIV_8_CTL(instNum, grpNum, dividerNum));
    }
    else
    { /* 16-bit divider */
        CY_ASSERT_L1(dividerNum < PERI_PCLK_GR_DIV_16_NR(instNum, grpNum));
        retVal = _FLD2VAL(PERI_DIV_16_CTL_INT16_DIV, PERI_DIV_16_CTL(instNum, grpNum, dividerNum));
    }
    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_PeriPclkSetFracDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType,
                                      uint32_t dividerNum, uint32_t dividerIntValue, uint32_t dividerFracValue)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_set_frac_div_in_t input_args;
        cy_pdl_sysclk_srf_status_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;
        input_args.dividerIntValue = dividerIntValue;
        input_args.dividerFracValue = dividerFracValue;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_SET_FRAC_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);
        return output_args.status;
    }
#endif

#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    if (dividerType == CY_SYSCLK_DIV_16_5_BIT)
    {
        if (((uint32_t)dividerNum < (PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum))) &&
            (dividerIntValue <= (PERI_DIV_16_5_CTL_INT16_DIV_Msk >> PERI_DIV_16_5_CTL_INT16_DIV_Pos)) &&
            (dividerFracValue <= (PERI_DIV_16_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_16_5_CTL_FRAC5_DIV_Pos)))
        {
            CY_REG32_CLR_SET(PERI_DIV_16_5_CTL(instNum, grpNum, dividerNum), PERI_DIV_16_5_CTL_INT16_DIV, dividerIntValue);
            CY_REG32_CLR_SET(PERI_DIV_16_5_CTL(instNum, grpNum, dividerNum), PERI_DIV_16_5_CTL_FRAC5_DIV, dividerFracValue);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
#endif

    if (dividerType == CY_SYSCLK_DIV_24_5_BIT)
    {
        if (((uint32_t)dividerNum < (PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum))) &&
            (dividerIntValue <= (PERI_DIV_24_5_CTL_INT24_DIV_Msk >> PERI_DIV_24_5_CTL_INT24_DIV_Pos)) &&
            (dividerFracValue <= (PERI_DIV_24_5_CTL_FRAC5_DIV_Msk >> PERI_DIV_24_5_CTL_FRAC5_DIV_Pos)))
        {
            CY_REG32_CLR_SET(PERI_DIV_24_5_CTL(instNum, grpNum, dividerNum), PERI_DIV_24_5_CTL_INT24_DIV, dividerIntValue);
            CY_REG32_CLR_SET(PERI_DIV_24_5_CTL(instNum, grpNum, dividerNum), PERI_DIV_24_5_CTL_FRAC5_DIV, dividerFracValue);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }

    /* if none of the above conditions are true, the function will return bad parameter */

    return (retVal);
}


void Cy_SysClk_PeriPclkGetFracDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                      uint32_t *dividerIntValue, uint32_t *dividerFracValue)
{
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif
    CY_ASSERT_L1(((dividerType == CY_SYSCLK_DIV_16_5_BIT) || (dividerType == CY_SYSCLK_DIV_24_5_BIT)) && \
                (dividerIntValue != NULL) && (dividerFracValue != NULL));

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_get_frac_div_in_t input_args;
        cy_pdl_sysclk_srf_peripclk_get_frac_div_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_FRAC_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));
        *dividerIntValue = output_args.dividerIntValue;
        *dividerFracValue = output_args.dividerFracValue;

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);
        return;
    }
#endif

#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    if (dividerType == CY_SYSCLK_DIV_16_5_BIT)
    {
        CY_ASSERT_L1(dividerNum < PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum));
        *dividerIntValue  = _FLD2VAL(PERI_DIV_16_5_CTL_INT16_DIV, PERI_DIV_16_5_CTL(instNum, grpNum, dividerNum));
        *dividerFracValue = _FLD2VAL(PERI_DIV_16_5_CTL_FRAC5_DIV, PERI_DIV_16_5_CTL(instNum, grpNum, dividerNum));
    }
#endif

    if (dividerType == CY_SYSCLK_DIV_24_5_BIT)
    { /* 24.5-bit divider */
        CY_ASSERT_L1(dividerNum < PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum));
        *dividerIntValue  = _FLD2VAL(PERI_DIV_24_5_CTL_INT24_DIV, PERI_DIV_24_5_CTL(instNum, grpNum, dividerNum));
        *dividerFracValue = _FLD2VAL(PERI_DIV_24_5_CTL_FRAC5_DIV, PERI_DIV_24_5_CTL(instNum, grpNum, dividerNum));
    }
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkAssignDivider(en_clk_dst_t ipBlock,
                                              cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
    uint8_t periNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum    = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);
    periNum  = (uint8_t)((uint32_t)ipBlock & PERI_PCLK_PERI_NUM_Msk);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#endif
    if (CY_SYSCLK_DIV_24_5_BIT >= dividerType)
    {
        if (((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < (PERI_PCLK_GR_DIV_8_NR(instNum, grpNum))))    ||
            ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < (PERI_PCLK_GR_DIV_16_NR(instNum, grpNum))))   ||
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            ((dividerType == CY_SYSCLK_DIV_16_5_BIT) && (dividerNum < (PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum)))) ||
#endif
            ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < (PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum)))))
        {
#if defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3))
            CY_UNUSED_PARAMETER(grpNum);
            CY_UNUSED_PARAMETER(instNum);
            CY_UNUSED_PARAMETER(periNum);
            if (CY_PERI_CLOCK_NR > (uint32_t)ipBlock)
            {
                PERI_CLOCK_CTL[ipBlock] = _VAL2FLD(CY_PERI_CLOCK_CTL_TYPE_SEL, dividerType) |
                                        _VAL2FLD(CY_PERI_CLOCK_CTL_DIV_SEL, dividerNum);

                retVal = CY_SYSCLK_SUCCESS;
            }
#else
            PERI_CLOCK_CTL(instNum, grpNum, periNum) = _VAL2FLD(CY_PERI_CLOCK_CTL_TYPE_SEL, dividerType) |
                                      _VAL2FLD(CY_PERI_CLOCK_CTL_DIV_SEL, dividerNum);

            retVal = CY_SYSCLK_SUCCESS;
#endif
        }
    }
    return (retVal);
}


uint32_t Cy_SysClk_PeriPclkGetAssignedDivider(en_clk_dst_t ipBlock)
{
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3))
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_ASSERT_L1(CY_PERI_CLOCK_NR > (uint32_t)ipBlock);
#else
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#endif
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_get_assn_div_out_t output_args;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_ASSN_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3))
            .base = NULL,
            .sub_block = 0UL,
        #else
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #endif
            .input_base = NULL,
            .input_len = 0UL,
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.assigned_div;
    }
#endif
#if defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3))
    CY_UNUSED_PARAMETER(periNum);
    CY_ASSERT_L1(CY_PERI_CLOCK_NR > (uint32_t)ipBlock);
    return (PERI_CLOCK_CTL[ipBlock] & (CY_PERI_CLOCK_CTL_DIV_SEL_Msk | CY_PERI_CLOCK_CTL_TYPE_SEL_Msk));
#else
    uint8_t periNum  = (uint8_t)((uint32_t)ipBlock & PERI_PCLK_PERI_NUM_Msk);
    return (PERI_CLOCK_CTL(instNum, grpNum, periNum) & (CY_PERI_CLOCK_CTL_DIV_SEL_Msk | CY_PERI_CLOCK_CTL_TYPE_SEL_Msk));
#endif
}


cy_en_sysclk_status_t Cy_SysClk_PeriPclkEnableDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType,
                                                      uint32_t dividerNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_enable_in_t input_args;
        cy_pdl_sysclk_srf_status_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_ENABLE_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.status;
    }
#endif

    if (dividerType <= CY_SYSCLK_DIV_24_5_BIT)
    {
        if (((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < (PERI_PCLK_GR_DIV_8_NR(instNum, grpNum))))    ||
            ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < (PERI_PCLK_GR_DIV_16_NR(instNum, grpNum))))   ||
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            ((dividerType == CY_SYSCLK_DIV_16_5_BIT) && (dividerNum < (PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum)))) ||
#endif
            ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < (PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum)))))
        {
            /* specify the divider, make the reference = clk_peri, and enable the divider */
            PERI_DIV_CMD(instNum, grpNum) = PERI_DIV_CMD_ENABLE_Msk                         |
                           CY_PERI_DIV_CMD_PA_TYPE_SEL_Msk                 |
                           CY_PERI_DIV_CMD_PA_DIV_SEL_Msk                  |
                           _VAL2FLD(CY_PERI_DIV_CMD_TYPE_SEL, dividerType) |
                           _VAL2FLD(CY_PERI_DIV_CMD_DIV_SEL,  dividerNum);
            (void)PERI_DIV_CMD(instNum, grpNum); /* dummy read to handle buffered writes */
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_PeriPclkDisableDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType,
                                                        uint32_t dividerNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif

#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_disable_in_t input_args;
        cy_pdl_sysclk_srf_status_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_DISABLE_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.status;
    }
#endif

    if (dividerType <= CY_SYSCLK_DIV_24_5_BIT)
    {
        if (((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < (PERI_PCLK_GR_DIV_8_NR(instNum, grpNum))))    ||
            ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < (PERI_PCLK_GR_DIV_16_NR(instNum, grpNum))))   ||
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            ((dividerType == CY_SYSCLK_DIV_16_5_BIT) && (dividerNum < (PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum)))) ||
#endif
            ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < (PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum)))))
        {
            /* specify the divider and disable it */
            PERI_DIV_CMD(instNum, grpNum) = PERI_DIV_CMD_DISABLE_Msk          |
             _VAL2FLD(CY_PERI_DIV_CMD_TYPE_SEL, dividerType) |
             _VAL2FLD(CY_PERI_DIV_CMD_DIV_SEL,  dividerNum);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    return (retVal);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriPclkEnablePhaseAlignDivider(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                        cy_en_divider_types_t dividerTypePA, uint32_t dividerNumPA)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif
    if (dividerTypePA <= CY_SYSCLK_DIV_24_5_BIT)
    {
        if (((dividerTypePA == CY_SYSCLK_DIV_8_BIT)    && (dividerNumPA < (PERI_PCLK_GR_DIV_8_NR(instNum, grpNum))))    ||
            ((dividerTypePA == CY_SYSCLK_DIV_16_BIT)   && (dividerNumPA < (PERI_PCLK_GR_DIV_16_NR(instNum, grpNum))))   ||
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            ((dividerTypePA == CY_SYSCLK_DIV_16_5_BIT) && (dividerNumPA < (PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum)))) ||
#endif
            ((dividerTypePA == CY_SYSCLK_DIV_24_5_BIT) && ((dividerNumPA < (PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum))) || (dividerNumPA == 63u))))
        {
            /* First, disable the divider that is to be phase-aligned.
               The other two parameters are checked in that function;
               if they're not valid, the divider is not disabled. */
            retVal = Cy_SysClk_PeriphDisableDivider(dividerType, dividerNum);
            if (retVal == CY_SYSCLK_SUCCESS)
            {
                /* Then, specify the reference divider, and the divider, and enable the divider */
                PERI_DIV_CMD(instNum, grpNum) = PERI_DIV_CMD_ENABLE_Msk             |
                 _VAL2FLD(CY_PERI_DIV_CMD_PA_TYPE_SEL, dividerTypePA) |
                 _VAL2FLD(CY_PERI_DIV_CMD_PA_DIV_SEL,  dividerNumPA)  |
                 _VAL2FLD(CY_PERI_DIV_CMD_TYPE_SEL, dividerType)   |
                 _VAL2FLD(CY_PERI_DIV_CMD_DIV_SEL,  dividerNum);
            }
        }
    }
    return (retVal);
}


bool Cy_SysClk_PeriPclkGetDividerEnabled(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    uint8_t grpNum = 0;
    uint8_t instNum = 0;
#if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
    grpNum = (uint8_t)((((uint32_t)ipBlock) & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos);
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#else
    CY_UNUSED_PARAMETER(grpNum);
    CY_UNUSED_PARAMETER(instNum);
    CY_UNUSED_PARAMETER(ipBlock);
#endif
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_in_t input_args;
        cy_pdl_sysclk_srf_peripclk_get_div_is_enabled_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_DIV_ENABLED,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if defined (CY_IP_MXSPERI) || (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.is_enabled;
    }
#endif
    bool retVal = false;

#if (defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3U)))
    CY_ASSERT_L1(((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < PERI_PCLK_GR_DIV_8_NR(instNum, grpNum)))    || \
                 ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < PERI_PCLK_GR_DIV_16_NR(instNum, grpNum)))   || \
                 ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum))));
#else
    CY_ASSERT_L1(((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < PERI_PCLK_GR_DIV_8_NR(instNum, grpNum)))    || \
                 ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < PERI_PCLK_GR_DIV_16_NR(instNum, grpNum)))   || \
                 ((dividerType == CY_SYSCLK_DIV_16_5_BIT) && (dividerNum < PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum))) || \
                 ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum))));
#endif

    switch(dividerType)
    {
        case CY_SYSCLK_DIV_8_BIT:
            retVal = _FLD2BOOL(PERI_DIV_8_CTL_EN, PERI_DIV_8_CTL(instNum, grpNum, dividerNum));
            break;
        case CY_SYSCLK_DIV_16_BIT:
            retVal = _FLD2BOOL(PERI_DIV_16_CTL_EN, PERI_DIV_16_CTL(instNum, grpNum, dividerNum));
            break;
        case CY_SYSCLK_DIV_16_5_BIT:
            retVal = _FLD2BOOL(PERI_DIV_16_5_CTL_EN, PERI_DIV_16_5_CTL(instNum, grpNum, dividerNum));
            break;
        case CY_SYSCLK_DIV_24_5_BIT:
            retVal = _FLD2BOOL(PERI_DIV_24_5_CTL_EN, PERI_DIV_24_5_CTL(instNum, grpNum, dividerNum));
            break;
        default:
            /* Unknown Divider */
            break;
    }
    return (retVal);
}


/* ========================================================================== */
/* =====================    clk_peripherals SECTION    ====================== */
/* ========================================================================== */


uint32_t Cy_SysClk_PeriphGetFrequency(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkGetFrequency((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriphSetDivider(cy_en_divider_types_t dividerType,
                                           uint32_t dividerNum, uint32_t dividerValue)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkSetDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum, dividerValue);
}


uint32_t Cy_SysClk_PeriphGetDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkGetDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriphSetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                               uint32_t dividerIntValue, uint32_t dividerFracValue)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum, dividerIntValue, dividerFracValue);
}


void Cy_SysClk_PeriphGetFracDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                    uint32_t *dividerIntValue, uint32_t *dividerFracValue)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    Cy_SysClk_PeriPclkGetFracDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum, dividerIntValue, dividerFracValue);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriphAssignDivider(en_clk_dst_t ipBlock,
                                              cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    return Cy_SysClk_PeriPclkAssignDivider(ipBlock, dividerType, dividerNum);
}


uint32_t Cy_SysClk_PeriphGetAssignedDivider(en_clk_dst_t ipBlock)
{
    return Cy_SysClk_PeriPclkGetAssignedDivider(ipBlock);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriphEnableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriphDisableDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum);
}


cy_en_sysclk_status_t
                Cy_SysClk_PeriphEnablePhaseAlignDivider(cy_en_divider_types_t dividerType, uint32_t dividerNum,
                                                        cy_en_divider_types_t dividerTypePA, uint32_t dividerNumPA)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkEnablePhaseAlignDivider((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum, dividerTypePA,  dividerNumPA);
}


bool Cy_SysClk_PeriphGetDividerEnabled(cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to en_clk_dst_t enum.');
    return Cy_SysClk_PeriPclkGetDividerEnabled((en_clk_dst_t)PERI_PCLK_PERIPHERAL_GROUP_NUM, dividerType, dividerNum);
}


/* ========================================================================== */
/* =========================    clk_slow SECTION    ========================= */
/* ========================================================================== */

#if defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)

uint32_t Cy_SysClk_ClkSlowGetFrequency(void)
{
#if defined (CY_IP_M7CPUSS)
    uint32_t locFreq = Cy_SysClk_ClkMemGetFrequency(); /* Get Mem frequency */
#elif defined (CY_IP_M4CPUSS)
    uint32_t locFreq = Cy_SysClk_ClkPeriGetFrequency(); /* Get Peri frequency */
#else
    #error "Unsupported Core Type"
#endif
    uint32_t locDiv = 1UL + (uint32_t)Cy_SysClk_ClkSlowGetDivider(); /* Range (1-256) */

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(locFreq, locDiv));
}


void Cy_SysClk_ClkSlowSetDivider(uint8_t divider)
{
#if defined (CY_IP_M7CPUSS)
    CY_REG32_CLR_SET(CPUSS_SLOW_CLOCK_CTL, CPUSS_SLOW_CLOCK_CTL_INT_DIV, divider);
#elif defined (CY_IP_M4CPUSS)
    CY_REG32_CLR_SET(CPUSS_CM0_CLOCK_CTL, CPUSS_CM0_CLOCK_CTL_SLOW_INT_DIV, divider);
#else
    #error "Unsupported Core Type"
#endif
}


uint8_t Cy_SysClk_ClkSlowGetDivider(void)
{
#if defined (CY_IP_M7CPUSS)
    return ((uint8_t)_FLD2VAL(CPUSS_SLOW_CLOCK_CTL_INT_DIV, CPUSS_SLOW_CLOCK_CTL));
#elif defined (CY_IP_M4CPUSS)
    return ((uint8_t)_FLD2VAL(CPUSS_CM0_CLOCK_CTL_SLOW_INT_DIV, CPUSS_CM0_CLOCK_CTL));
#else
    #error "Unsupported Core Type"
#endif
}

#endif /* defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2) */

/* ========================================================================== */
/* =========================    clk_mem SECTION    ========================= */
/* ========================================================================== */

#if defined (CY_IP_MXS40SRSS) && defined (CY_IP_M7CPUSS)

uint32_t Cy_SysClk_ClkMemGetFrequency(void)
{
    uint32_t locFreq = Cy_SysClk_ClkHfGetFrequency(CY_SYSCLK_CLK_MEM_HF_PATH_NUM); /* Get HF frequency */
    uint32_t locDiv = 1UL + (uint32_t)Cy_SysClk_ClkMemGetDivider(); /* Range (1-256) */

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(locFreq, locDiv));
}


void Cy_SysClk_ClkMemSetDivider(uint8_t divider)
{
    CY_REG32_CLR_SET(CPUSS_MEM_CLOCK_CTL, CPUSS_MEM_CLOCK_CTL_INT_DIV, divider);
}


uint8_t Cy_SysClk_ClkMemGetDivider(void)
{
    return ((uint8_t)_FLD2VAL(CPUSS_MEM_CLOCK_CTL_INT_DIV, CPUSS_MEM_CLOCK_CTL));
}

#endif /* defined (CY_IP_MXS40SRSS) && defined (CY_IP_M7CPUSS) */

/* ========================================================================== */
/* =========================    clk_pump SECTION    ========================= */
/* ========================================================================== */

#if defined (CY_IP_MXS40SSRSS)
void Cy_SysClk_ClkPumpSetSource(cy_en_clkpump_in_sources_t source)
{
    CY_ASSERT_L3(source <= CY_SYSCLK_PUMP_IN_CLKPATH15);
    CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_PUMP_SEL, source);
}

cy_en_clkpump_in_sources_t Cy_SysClk_ClkPumpGetSource(void)
{
    return ((cy_en_clkpump_in_sources_t)((uint32_t)_FLD2VAL(SRSS_CLK_SELECT_PUMP_SEL, SRSS_CLK_SELECT)));
}

void Cy_SysClk_ClkPumpSetDivider(cy_en_clkpump_divide_t divider)
{
    CY_ASSERT_L3(CY_SYSCLK_FLL_IS_DIVIDER_VALID(divider));
    CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_PUMP_DIV, divider);
}

cy_en_clkpump_divide_t Cy_SysClk_ClkPumpGetDivider(void)
{
    return ((cy_en_clkpump_divide_t)((uint32_t)_FLD2VAL(SRSS_CLK_SELECT_PUMP_DIV, SRSS_CLK_SELECT)));
}

bool Cy_SysClk_ClkPumpIsEnabled(void)
{
    return (_FLD2BOOL(SRSS_CLK_SELECT_PUMP_ENABLE, SRSS_CLK_SELECT));
}

void Cy_SysClk_ClkPumpEnable(void)
{
    SRSS_CLK_SELECT |= SRSS_CLK_SELECT_PUMP_ENABLE_Msk;
}


void Cy_SysClk_ClkPumpDisable(void)
{
    SRSS_CLK_SELECT &= ~SRSS_CLK_SELECT_PUMP_ENABLE_Msk;
}

uint32_t Cy_SysClk_ClkPumpGetFrequency(void)
{
    /* Divide the input frequency down and return the result */
    return (Cy_SysClk_ClkPumpIsEnabled() ?
            (Cy_SysClk_ClkPathGetFrequency((uint32_t)Cy_SysClk_ClkPumpGetSource()) /
             (1UL << (uint32_t)Cy_SysClk_ClkPumpGetDivider())) : 0UL);
}
#endif /* defined (CY_IP_MXS40SSRSS) */
/* ========================================================================== */
/* ==========================    clk_bak SECTION    ========================= */
/* ========================================================================== */

void Cy_SysClk_ClkBakSetSource(cy_en_clkbak_in_sources_t source)
{
    CY_ASSERT_L3(source <= CY_SYSCLK_BAK_IN_PILO);

#if defined (CY_IP_MXS22SRSS)
    BACKUP_CTL = (_CLR_SET_FLD32U(BACKUP_CTL, SRSS_CLK_WCO_CONFIG_CLK_RTC_SEL, (uint32_t) source));
#else
    BACKUP_CTL = (_CLR_SET_FLD32U(BACKUP_CTL, BACKUP_CTL_CLK_SEL, (uint32_t) source));
#endif
}


cy_en_clkbak_in_sources_t Cy_SysClk_ClkBakGetSource(void)
{
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Intentional typecast to cy_en_clkbak_in_sources_t enum.')
#if defined (CY_IP_MXS22SRSS)
    return ((cy_en_clkbak_in_sources_t)_FLD2VAL(SRSS_CLK_WCO_CONFIG_CLK_RTC_SEL, BACKUP_CTL));
#else
    return ((cy_en_clkbak_in_sources_t)_FLD2VAL(BACKUP_CTL_CLK_SEL, BACKUP_CTL));
#endif
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8')
}

/* ========================================================================== */
/* ===========================    clkLf SECTION    ========================== */
/* ========================================================================== */

void Cy_SysClk_ClkLfSetSource(cy_en_clklf_in_sources_t source)
{
    CY_ASSERT_L3(source <= CY_SYSCLK_CLKLF_IN_MAX);
    CY_REG32_CLR_SET(SRSS_CLK_SELECT, SRSS_CLK_SELECT_LFCLK_SEL, source);
}


cy_en_clklf_in_sources_t Cy_SysClk_ClkLfGetSource(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_clklf_in_sources_t enum.');
    return ((cy_en_clklf_in_sources_t)(_FLD2VAL(SRSS_CLK_SELECT_LFCLK_SEL, SRSS_CLK_SELECT)));
}


#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
uint32_t Cy_SysClk_ClkLfGetFrequency(void)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_LF) && (_CY_PDL_SYSCLK_PPC_SECURED_LF))
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clklf_get_freq_num_out_t output_args;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_CLKLF_GET_FREQ,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = 0UL,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.freq;
#else
    uint32_t freq = 0UL;

    cy_en_clklf_in_sources_t source = Cy_SysClk_ClkLfGetSource();

    /* Get the frequency of the source  */
    switch(source)
     {
#if (!(defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)))
        case CY_SYSCLK_CLKLF_IN_PILO:
            freq = (0UL != (SRSS_CLK_PILO_CONFIG & SRSS_CLK_PILO_CONFIG_PILO_EN_Msk)) ? CY_SYSCLK_PILO_FREQ : 0UL;
            break;
#endif /* if (!(defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))) */

        case CY_SYSCLK_CLKLF_IN_WCO:
            freq = (Cy_SysClk_WcoOkay()) ? CY_SYSCLK_WCO_FREQ : 0UL;
            break;

        case CY_SYSCLK_CLKLF_IN_ILO:
            freq = (0UL != (SRSS_CLK_ILO_CONFIG & SRSS_CLK_ILO_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;

#if ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)))
        case CY_SYSCLK_CLKLF_IN_ILO1:
            freq = (0UL != (SRSS_CLK_ILO1_CONFIG & SRSS_CLK_ILO1_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;
#endif /* if ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))) */

        case CY_SYSCLK_CLKLF_IN_ECO_PRESCALER:
            freq = Cy_SysClk_EcoPrescaleGetFrequency();
            break;

        default:
            /* Don't know the frequency of dsi_out, leave freq = 0UL */
            break;
     }
    return (freq);
#endif
 }


#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && defined(SRSS_CSV_LF_CSV_REF_CTL))
uint32_t Cy_SysClk_ClkLfCsvGetRefFrequency(cy_en_clklf_csv_ref_clk_t refClk)
 {
    uint32_t freq = 0UL;

    /* Get the frequency of the source  */
    switch(refClk)
     {
 #if defined (CY_IP_MXS22SRSS)
        case CY_SYSCLK_CLKLF_CSV_REF_PILO:
            freq = (0UL != (SRSS_CLK_PILO_CONFIG & SRSS_CLK_PILO_CONFIG_PILO_EN_Msk)) ? CY_SYSCLK_PILO_FREQ : 0UL;
            break;

        case CY_SYSCLK_CLKLF_CSV_REF_ILO:
            freq = (0UL != (SRSS_CLK_ILO_CONFIG & SRSS_CLK_ILO_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;

        case CY_SYSCLK_CLKLF_CSV_REF_WCO:
            freq = (Cy_SysClk_WcoOkay()) ? CY_SYSCLK_WCO_FREQ : 0UL;
            break;

#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
        case CY_SYSCLK_CLKLF_CSV_REF_ILO0:
            freq = (0UL != (SRSS_CLK_ILO0_CONFIG & SRSS_CLK_ILO0_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;

        case CY_SYSCLK_CLKLF_CSV_REF_ILO1:
            freq = (0UL != (SRSS_CLK_ILO1_CONFIG & SRSS_CLK_ILO1_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;

#else
        case CY_SYSCLK_CLKLF_CSV_REF_IMO: /* The IMO frequency is fixed at 8 MHz */
            freq = CY_SYSCLK_IMO_FREQ;
            break;

        case CY_SYSCLK_CLKLF_CSV_REF_EXT:
            freq = Cy_SysClk_ExtClkGetFrequency();
            break;

        case CY_SYSCLK_CLKLF_CSV_REF_ECO:
            freq = Cy_SysClk_EcoGetFrequency();
            break;

        case CY_SYSCLK_CLKLF_CSV_REF_IHO:
            freq = (Cy_SysClk_IhoIsEnabled()) ? CY_SYSCLK_IHO_FREQ : 0UL;
            break;
#endif
        default:
            /* Don't know the frequency of dsi_out, leave freq = 0UL */
            break;
     }
    return (freq);
 }


cy_en_sysclk_status_t Cy_SysClk_ClkLfCsvManualConfigure(cy_en_clklf_csv_ref_clk_t refClk, const cy_stc_clklf_csv_manual_config_t * csvConfig)
{
    /* Check for errors */
    CY_ASSERT_L1(csvConfig != NULL);

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint32_t monitorFreq = Cy_SysClk_ClkLfGetFrequency();
    uint32_t refFreq = Cy_SysClk_ClkLfCsvGetRefFrequency(refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;

    CY_ASSERT_L1(csvConfig->upperLimit > CSV_MIN_TARGET_VAL);
    CY_ASSERT_L1(csvConfig->lowerLimit < csvConfig->upperLimit -1UL);
    CY_ASSERT_L1(monitorFreq > 0UL);
    CY_ASSERT_L1((int32_t) csvConfig->startTime >= (((int32_t)(((float32_t)(csvConfig->period +3UL)) * (f_refFreq / f_monitorFreq))) - ((int32_t)csvConfig->upperLimit)));
    (void) monitorFreq; /* Used only in Assert comparison. */
    (void) refFreq;  /* Used only in Assert comparison.  */
    (void) f_monitorFreq; /* Used only in Assert comparison. */
    (void) f_refFreq;  /* Used only in Assert comparison.  */

#if defined (CY_IP_MXS22SRSS) && defined (SRSS_CSV_LF_REF_SEL)
    CY_REG32_CLR_SET(SRSS_CSV_LF_REF_SEL, SRSS_CSV_LF_REF_SEL_LF_REF_MUX, refClk);
#elif (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
    CY_REG32_CLR_SET(SRSS_CSV_REF_SEL, SRSS_CSV_REF_SEL_REF_MUX, refClk);
#endif

    CY_REG32_CLR_SET(SRSS_CSV_LF_CSV_REF_CTL, CSV_LF_CSV_REF_CTL_CSV_STARTUP, csvConfig->startTime - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_LF_CSV_REF_LIMIT, CSV_LF_CSV_REF_LIMIT_CSV_LOWER, csvConfig->lowerLimit - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_LF_CSV_REF_LIMIT, CSV_LF_CSV_REF_LIMIT_CSV_UPPER, csvConfig->upperLimit - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_LF_CSV_MON_CTL, CSV_LF_CSV_MON_CTL_CSV_PERIOD, csvConfig->period - 1UL);
    retVal = CY_SYSCLK_SUCCESS;

    return retVal;
}


cy_en_sysclk_status_t Cy_SysClk_ClkLfCsvConfigure(cy_en_clklf_csv_ref_clk_t refClk, uint32_t accuracy)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    cy_stc_clklf_csv_manual_config_t csvConfig= {0, 0, 0, 0};

    uint32_t target = CSV_MIN_TARGET_VAL;
    uint32_t monitorFreq = Cy_SysClk_ClkLfGetFrequency();
    uint32_t refFreq = Cy_SysClk_ClkLfCsvGetRefFrequency(refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;

    CY_ASSERT_L1(monitorFreq > 0UL);

    if(monitorFreq > 0UL && refFreq > 0UL)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.lowerLimit = target - (uint32_t) (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F));
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.upperLimit = target + (uint32_t) (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F));
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.period =  (uint32_t) ((float32_t)target / (f_refFreq / f_monitorFreq));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.startTime = (uint32_t) ((((float32_t)(csvConfig.period + 3UL)) * (f_refFreq / f_monitorFreq))
                                + (CSV_MIN_STARTUP_DELAY * f_refFreq)
                                + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F))) + 1U;

        retVal= Cy_SysClk_ClkLfCsvManualConfigure(refClk, &csvConfig);
    }

    return retVal;
}


void Cy_SysClk_ClkLfCsvEnable(void)
{
    CY_REG32_CLR_SET(SRSS_CSV_LF_CSV_REF_CTL, CSV_LF_CSV_REF_CTL_CSV_EN, 1U);
}


void Cy_SysClk_ClkLfCsvDisable(void)
{
    CY_REG32_CLR_SET(SRSS_CSV_LF_CSV_REF_CTL, CSV_LF_CSV_REF_CTL_CSV_EN, 0U);
}


bool Cy_SysClk_IsClkLfCsvEnabled(void)
{
    return (0UL != (SRSS_CSV_LF_CSV_REF_CTL & CSV_LF_CSV_REF_CTL_CSV_EN_Msk));
}
#endif /* defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && defined(SRSS_CSV_LF_CSV_REF_CTL)) */
#endif


/* ========================================================================== */
/* ========================    clk_peri SECTION    ========================== */
/* ========================================================================== */

#if defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)

uint32_t Cy_SysClk_ClkPeriGetFrequency(void)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && (CYCFG_PPC_SECURED_CLK_PERI)
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkperi_get_freq_out_t output_args;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_CLKPERI_GET_FREQ,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = 0UL,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.freq;
#else
    uint32_t locFreq = Cy_SysClk_ClkHfGetFrequency(0UL); /* Get root frequency */
    uint32_t locDiv = 1UL + (uint32_t)Cy_SysClk_ClkPeriGetDivider(); /* peri prescaler (1-256) */

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(locFreq, locDiv));
#endif
}

void Cy_SysClk_ClkPeriSetDivider(uint8_t divider)
{
    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && (CYCFG_PPC_SECURED_CLK_PERI)
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkperi_set_div_in_t input_args;
    input_args.divider = divider;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_CLKPERI_SET_DIV,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = 0UL,
        .input_base = (uint8_t*)&input_args,
        .input_len = sizeof(input_args),
        .output_base = NULL,
        .output_len = 0UL,
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);
#else
#if defined (CY_IP_M7CPUSS)
    CY_REG32_CLR_SET(CPUSS_PERI_CLOCK_CTL, CPUSS_PERI_CLOCK_CTL_INT_DIV, divider);
#elif defined (CY_IP_M4CPUSS)
    CY_REG32_CLR_SET(CPUSS_CM0_CLOCK_CTL, CPUSS_CM0_CLOCK_CTL_PERI_INT_DIV, divider);
#else
    #error "Unsupported Core Type"
#endif
#endif
}

uint8_t Cy_SysClk_ClkPeriGetDivider(void)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && (CYCFG_PPC_SECURED_CLK_PERI)
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkperi_get_div_out_t output_args;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_CLKPERI_GET_DIV,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = 0UL,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.found_div;
#else
#if defined (CY_IP_M7CPUSS)
    return ((uint8_t)_FLD2VAL(CPUSS_PERI_CLOCK_CTL_INT_DIV, CPUSS_PERI_CLOCK_CTL));
#elif defined (CY_IP_M4CPUSS)
    return ((uint8_t)_FLD2VAL(CPUSS_CM0_CLOCK_CTL_PERI_INT_DIV, CPUSS_CM0_CLOCK_CTL));
#else
    #error "Unsupported Core Type"
#endif
#endif
}

#endif /* defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2) */

/* ========================================================================== */
/* ========================    PERI SECTION    ========================== */
/* ========================================================================== */


/** \cond INTERNAL */
/* Mask to evaluate group number value */
#define CY_SYSCLK_PERI_GR_NUM_Msk (0x000000FFUL)
/** \endcond */

cy_en_sysclk_status_t Cy_SysClk_PeriGroupSetDivider(uint32_t groupNum, uint32_t divider)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t instNum = (uint8_t)(((uint32_t)groupNum & PERI_GR_INST_NUM_Msk )>>PERI_GR_INST_NUM_Pos);

    uint32_t groupNumMsked = (uint8_t)(groupNum & CY_SYSCLK_PERI_GR_NUM_Msk);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNumMsked < CY_PERI_GROUP_NR);

    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
        (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP))
    if((instNum == 0 && mtb_pdl_sysclk_peri0_group_srf_secured[groupNumMsked]) || (instNum == 1 && mtb_pdl_sysclk_peri1_group_srf_secured[groupNumMsked]))
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_perigroup_set_div_in_t input_args;
        cy_pdl_sysclk_srf_status_out_t output_args;
        input_args.divider = divider;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERI_SET_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = groupNum,
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);

        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.status;
    }
#endif

    if (divider <= (PERI_GR_CLOCK_CTL_INT8_DIV_Msk >> PERI_GR_CLOCK_CTL_INT8_DIV_Pos))
    {
        CY_REG32_CLR_SET(PERI_GR_CLOCK_CTL(instNum, groupNumMsked), PERI_GR_CLOCK_CTL_INT8_DIV, divider);
        retVal = CY_SYSCLK_SUCCESS;
    }

    return retVal;
}


uint32_t Cy_SysClk_PeriGroupGetDivider(uint32_t groupNum)
{
    uint8_t instNum = (uint8_t)(((uint32_t)groupNum & PERI_GR_INST_NUM_Msk )>>PERI_GR_INST_NUM_Pos);
    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);

    uint32_t groupNumMsked = (uint8_t)(groupNum & CY_SYSCLK_PERI_GR_NUM_Msk);
    CY_ASSERT_L1(groupNumMsked < CY_PERI_GROUP_NR);
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_GR_GROUP))
    if((instNum == 0 && mtb_pdl_sysclk_peri0_group_srf_secured[groupNumMsked]) || (instNum == 1 && mtb_pdl_sysclk_peri1_group_srf_secured[groupNumMsked]))
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_perigroup_get_div_out_t output_args;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERI_GET_DIV,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = groupNum,
            .input_base = NULL,
            .input_len = 0UL,
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.found_div;
    }
#endif
    return(_FLD2VAL(PERI_GR_CLOCK_CTL_INT8_DIV, PERI_GR_CLOCK_CTL(instNum, groupNumMsked)));
}

cy_en_sysclk_status_t Cy_SysClk_PeriGroupSetSlaveCtl(uint32_t groupNum, cy_en_peri_grp_sl_ctl_num_t slaveCtl, uint32_t value)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint8_t instNum = (uint8_t)(((uint32_t)groupNum & PERI_GR_INST_NUM_Msk )>>PERI_GR_INST_NUM_Pos);

    groupNum = (uint8_t)(groupNum & CY_SYSCLK_PERI_GR_NUM_Msk);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNum  < CY_PERI_GROUP_NR);
    CY_ASSERT_L1(CY_SYSCLK_IS_SL_CTL_NUM_VALID(slaveCtl));

    switch(slaveCtl)
    {
        case CY_SYSCLK_PERI_GROUP_SL_CTL:
            PERI_GR_SL_CTL(instNum, groupNum) = value;
            retVal = CY_SYSCLK_SUCCESS;
            break;
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
        case CY_SYSCLK_PERI_GROUP_SL_CTL2:
            PERI_GR_SL_CTL2(instNum, groupNum) = value;
            retVal = CY_SYSCLK_SUCCESS;
            break;
        case CY_SYSCLK_PERI_GROUP_SL_CTL3:
            /* Writes not allowed on SL_CTL3 */
            retVal = CY_SYSCLK_BAD_PARAM;
            break;
#endif
        default:
            retVal = CY_SYSCLK_BAD_PARAM;
            break;
    }

    return retVal;
}


uint32_t Cy_SysClk_PeriGroupGetSlaveCtl(uint32_t groupNum, cy_en_peri_grp_sl_ctl_num_t slaveCtl)
{
    uint32_t retVal = 0;
    uint8_t instNum = (uint8_t)(((uint32_t)groupNum & PERI_GR_INST_NUM_Msk )>>PERI_GR_INST_NUM_Pos);

    groupNum = (uint8_t)(groupNum & CY_SYSCLK_PERI_GR_NUM_Msk);

    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNum < CY_PERI_GROUP_NR);
    CY_ASSERT_L1(CY_SYSCLK_IS_SL_CTL_NUM_VALID(slaveCtl));

    switch(slaveCtl)
    {
        case CY_SYSCLK_PERI_GROUP_SL_CTL:
            retVal = PERI_GR_SL_CTL(instNum, groupNum);
            break;
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
        case CY_SYSCLK_PERI_GROUP_SL_CTL2:
            retVal = PERI_GR_SL_CTL2(instNum, groupNum);
            break;
        case CY_SYSCLK_PERI_GROUP_SL_CTL3:
            retVal = PERI_GR_SL_CTL3(instNum, groupNum);
            break;
#endif
        default:
            retVal = (uint32_t)CY_SYSCLK_BAD_PARAM;
            break;
    }

    return retVal;
}

bool Cy_SysClk_IsPeriGroupSlaveCtlSet(uint32_t groupNum,cy_en_peri_grp_sl_ctl_num_t slaveCtl, uint32_t slaveMsk)
{
    bool retVal = false;
    uint8_t instNum = (uint8_t)(((uint32_t)groupNum & PERI_GR_INST_NUM_Msk )>>PERI_GR_INST_NUM_Pos);

    groupNum = (uint8_t)(groupNum & CY_SYSCLK_PERI_GR_NUM_Msk);


    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNum < CY_PERI_GROUP_NR);
    CY_ASSERT_L1(CY_SYSCLK_IS_SL_CTL_NUM_VALID(slaveCtl));

    switch(slaveCtl)
    {
        case CY_SYSCLK_PERI_GROUP_SL_CTL:
            if ((PERI_GR_SL_CTL(instNum, groupNum) & slaveMsk) != 0UL)
            {
                retVal = true;
            }
            break;
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
        case CY_SYSCLK_PERI_GROUP_SL_CTL2:
            if ((PERI_GR_SL_CTL2(instNum, groupNum) & slaveMsk) != 0UL)
            {
                retVal = true;
            }
            break;
        case CY_SYSCLK_PERI_GROUP_SL_CTL3:
            if ((PERI_GR_SL_CTL3(instNum, groupNum) & slaveMsk) != 0UL)
            {
                retVal = true;
            }
            break;
#endif
        default:
            CY_ASSERT_L2(false);
            break;
    }

    return retVal;
}

#if  defined (CY_IP_MXS22SRSS)
void Cy_SysClk_PeriGroupSlaveInit(uint32_t periNum, uint32_t groupNum, uint32_t slaveNum, uint32_t clkHfNum)
{
    CY_ASSERT_L1(periNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNum  < CY_PERI_GROUP_NR);
    CY_ASSERT_L1(clkHfNum < CY_SRSS_NUM_HFROOT);
    CY_ASSERT_L1(slaveNum < 32U);

    if(false == Cy_SysClk_ClkHfIsEnabled(clkHfNum))
    {
        (void)Cy_SysClk_ClkHfEnable(clkHfNum);         /* Suppress a compiler warning about unused return value */
    }

    /* Release reset for the IP */
    PERI_GR_SL_CTL2(periNum, groupNum) &= ~(0x1UL << slaveNum);

    /* Enable IP */
    PERI_GR_SL_CTL(periNum, groupNum) |= (0x1UL << slaveNum);
}

void Cy_SysClk_PeriGroupSlaveDeinit(uint32_t periNum, uint32_t groupNum, uint32_t slaveNum)
{
    CY_ASSERT_L1(periNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNum  < CY_PERI_GROUP_NR);
    CY_ASSERT_L1(slaveNum < 32U);

    /* Release reset for the IP */
    PERI_GR_SL_CTL(periNum, groupNum) &= ~(0x1UL << slaveNum);
}

bool Cy_SysClk_IsPeriGroupSlaveEnabled(uint32_t periNum, uint32_t groupNum, uint32_t slaveNum)
{
    CY_ASSERT_L1(periNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(groupNum  < CY_PERI_GROUP_NR);
    CY_ASSERT_L1(slaveNum < 32U);

    return (((PERI_GR_SL_CTL(periNum, groupNum) & (0x1UL << slaveNum)) != 0U) ? true : false);
}

#endif


/* ========================================================================== */
/* =========================    clk_fast SECTION    ========================= */
/* ========================================================================== */

#if defined (CY_IP_MXS40SRSS) && defined (CY_IP_M7CPUSS)

uint32_t Cy_SysClk_ClkFastSrcGetFrequency(uint32_t clkFastNum)
{
    uint32_t freq = Cy_SysClk_ClkHfGetFrequency(CY_SYSCLK_CLK_FAST_HF_NUM); /* Get root frequency */
    uint32_t integer = 0UL;        /* Integer part of peripheral divider */
    uint32_t locFrac;
    uint32_t locDiv;
    uint64_t locFreq = freq * 32ULL;

    Cy_SysClk_ClkFastSrcGetDivider(clkFastNum, &integer, &locFrac);
    /* For fractional dividers, the divider is (int + 1) + frac/32 */
    locDiv = ((1UL + integer) * 32UL) + locFrac;

    return (uint32_t) CY_SYSLIB_DIV_ROUND(locFreq, (uint64_t)locDiv);
}

void Cy_SysClk_ClkFastSrcSetDivider(uint32_t clkFastNum, uint8_t intDiv, uint8_t fracDiv)
{
    if(0UL == clkFastNum)
    {
        CY_REG32_CLR_SET(CPUSS_FAST_0_CLOCK_CTL, CPUSS_FAST_0_CLOCK_CTL_INT_DIV, intDiv);
        CY_REG32_CLR_SET(CPUSS_FAST_0_CLOCK_CTL, CPUSS_FAST_0_CLOCK_CTL_FRAC_DIV, fracDiv);
    }
    else
    {
        CY_REG32_CLR_SET(CPUSS_FAST_1_CLOCK_CTL, CPUSS_FAST_1_CLOCK_CTL_INT_DIV, intDiv);
        CY_REG32_CLR_SET(CPUSS_FAST_1_CLOCK_CTL, CPUSS_FAST_1_CLOCK_CTL_FRAC_DIV, fracDiv);
    }
}

void Cy_SysClk_ClkFastSrcGetDivider(uint32_t clkFastNum, uint32_t *dividerIntValue, uint32_t *dividerFracValue)
{
    if(0UL == clkFastNum)
    {
        *dividerIntValue = ((uint8_t)_FLD2VAL(CPUSS_FAST_0_CLOCK_CTL_INT_DIV, CPUSS_FAST_0_CLOCK_CTL));
        *dividerFracValue = ((uint8_t)_FLD2VAL(CPUSS_FAST_0_CLOCK_CTL_FRAC_DIV, CPUSS_FAST_0_CLOCK_CTL));
    }
    else
    {
        *dividerIntValue = ((uint8_t)_FLD2VAL(CPUSS_FAST_1_CLOCK_CTL_INT_DIV, CPUSS_FAST_1_CLOCK_CTL));
        *dividerFracValue = ((uint8_t)_FLD2VAL(CPUSS_FAST_1_CLOCK_CTL_FRAC_DIV, CPUSS_FAST_1_CLOCK_CTL));
    }
}

#endif /* defined (CY_IP_MXS40SRSS) && defined (CY_IP_M7CPUSS) */

#if defined (CY_IP_MXS40SRSS) && defined (CY_IP_M4CPUSS)

uint32_t Cy_SysClk_ClkFastGetFrequency(void)
{
    uint32_t locFreq = Cy_SysClk_ClkHfGetFrequency(0UL); /* Get root frequency */
    uint32_t locDiv = 1UL + (uint32_t)Cy_SysClk_ClkFastGetDivider(); /* fast prescaler (1-256) */

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(locFreq, locDiv));
}


void Cy_SysClk_ClkFastSetDivider(uint8_t divider)
{
#if defined (CY_DEVICE_SECURE)
    cy_en_pra_status_t retStatus;
    retStatus = CY_PRA_FUNCTION_CALL_RETURN_PARAM(CY_PRA_MSG_TYPE_FUNC_POLICY, CY_PRA_CLK_FUNC_FAST_SET_DIVIDER, divider);

    if (retStatus != CY_PRA_STATUS_SUCCESS)
    {
        CY_ASSERT_L1(false);
    }
#endif /* defined (CY_DEVICE_SECURE) */
#if ((CY_CPU_CORTEX_M0P) || (!defined(CY_DEVICE_SECURE)))
    CY_REG32_CLR_SET(CPUSS_CM4_CLOCK_CTL, CPUSS_CM4_CLOCK_CTL_FAST_INT_DIV, divider);
#endif /* ((CY_CPU_CORTEX_M0P) || (!defined(CY_DEVICE_SECURE))) */
}


uint8_t Cy_SysClk_ClkFastGetDivider(void)
{
    return ((uint8_t)_FLD2VAL(CPUSS_CM4_CLOCK_CTL_FAST_INT_DIV, CPUSS_CM4_CLOCK_CTL));
}

#endif /* defined (CY_IP_MXS40SRSS) && defined (CY_IP_M4CPUSS) */

/* ========================================================================== */
/* =========================    clkHf[n] SECTION    ========================= */
/* ========================================================================== */

cy_en_sysclk_status_t Cy_SysClk_ClkHfEnable_Safe(uint32_t clkHf)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint32_t hfFreq = Cy_SysClk_ClkHfGetFrequency(clkHf);

    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        if (hfFreq <= CY_SYSCLK_HF_MAX_FREQ(clkHf))
        {
            retVal = Cy_SysClk_ClkHfEnable(clkHf);
        }
        else
        {
            retVal = CY_SYSCLK_INVALID_STATE;
        }
    }
    return (retVal);
}

cy_en_sysclk_status_t Cy_SysClk_ClkHfEnable(uint32_t clkHf)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        SRSS_CLK_ROOT_SELECT[clkHf] |= SRSS_CLK_ROOT_SELECT_ENABLE_Msk;
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}

bool Cy_SysClk_ClkHfIsEnabled(uint32_t clkHf)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF))
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkhf_is_enabled_out_t output_args;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_HF_IS_ENABLED,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = clkHf,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.is_enabled;
#else
    bool retVal = false;
    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        retVal = _FLD2BOOL(SRSS_CLK_ROOT_SELECT_ENABLE, SRSS_CLK_ROOT_SELECT[clkHf]);
    }
    return (retVal);
#endif
}

cy_en_sysclk_status_t Cy_SysClk_ClkHfDisable(uint32_t clkHf)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if ((0UL < clkHf) /* prevent CLK_HF0 disabling */
           && (clkHf < CY_SRSS_NUM_HFROOT))
    {
        SRSS_CLK_ROOT_SELECT[clkHf] &= ~SRSS_CLK_ROOT_SELECT_ENABLE_Msk;
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_ClkHfSetSource(uint32_t clkHf, cy_en_clkhf_in_sources_t source)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if ((clkHf < CY_SRSS_NUM_HFROOT) && (source <= CY_SYSCLK_CLKHF_IN_CLKPATH15))
    {
        CY_REG32_CLR_SET(SRSS_CLK_ROOT_SELECT[clkHf], SRSS_CLK_ROOT_SELECT_ROOT_MUX, source);
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}


cy_en_clkhf_in_sources_t Cy_SysClk_ClkHfGetSource(uint32_t clkHf)
{
    CY_ASSERT_L1(clkHf < CY_SRSS_NUM_HFROOT);
    return ((cy_en_clkhf_in_sources_t)((uint32_t)(_FLD2VAL(SRSS_CLK_ROOT_SELECT_ROOT_MUX, SRSS_CLK_ROOT_SELECT[clkHf]))));
}


cy_en_sysclk_status_t Cy_SysClk_ClkHfSetDivider(uint32_t clkHf, cy_en_clkhf_dividers_t divider)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF))
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkhf_set_div_in_t input_args;
    cy_pdl_sysclk_srf_status_out_t output_args;
    input_args.divider = divider;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_HF_SET_DIV,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = clkHf,
        .input_base = (uint8_t*)&input_args,
        .input_len = sizeof(input_args),
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.status;
#else
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if ((clkHf < CY_SRSS_NUM_HFROOT) && (divider < CY_SYSCLK_CLKHF_MAX_DIVIDER))
    {
        CY_REG32_CLR_SET(SRSS_CLK_ROOT_SELECT[clkHf], SRSS_CLK_ROOT_SELECT_ROOT_DIV, divider);
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
#endif
}


cy_en_clkhf_dividers_t Cy_SysClk_ClkHfGetDivider(uint32_t clkHf)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF))
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkhf_get_div_out_t output_args;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_HF_GET_DIV,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = clkHf,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.found_div;
#else
    CY_ASSERT_L1(clkHf < CY_SRSS_NUM_HFROOT);
#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
    return ((cy_en_clkhf_dividers_t)(((uint32_t)_FLD2VAL(SRSS_CLK_ROOT_SELECT_ROOT_DIV_INT, SRSS_CLK_ROOT_SELECT[clkHf]))));
#else
    return ((cy_en_clkhf_dividers_t)(((uint32_t)_FLD2VAL(SRSS_CLK_ROOT_SELECT_ROOT_DIV, SRSS_CLK_ROOT_SELECT[clkHf]))));
#endif
#endif
}

uint32_t Cy_SysClk_ClkHfGetFrequency(uint32_t clkHf)
{
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_HF) && (_CY_PDL_SYSCLK_PPC_SECURED_HF))
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_sysclk_srf_clkhf_get_freq_out_t output_args;

    cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSCLK_OP_HF_GET_FREQ,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        .base = NULL,
        .sub_block = clkHf,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = (uint8_t*)&output_args,
        .output_len = sizeof(output_args),
        .invec_bases = NULL,
        .invec_sizes = 0UL,
        .outvec_bases = NULL,
        .outvec_sizes = 0UL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    /* Output values are passed in by value. Make a copy before freeing the ioVec */
    memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);

    return output_args.freq;
#else
    /* variables holding intermediate clock frequencies, dividers and FLL/PLL settings */
#if defined (CY_IP_MXS22SRSS) || (defined (CY_MXS40SSRSS_VER_1_2) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
    uint32_t pDiv = (uint32_t)Cy_SysClk_ClkHfGetDivider(clkHf) + 1U; /* root prescaler */
#else
    uint32_t pDiv = 1UL << (uint32_t)Cy_SysClk_ClkHfGetDivider(clkHf); /* root prescaler */
#endif
    uint32_t path = (uint32_t) Cy_SysClk_ClkHfGetSource(clkHf); /* path input for root 0 (clkHf[0]) */
    uint32_t freq = Cy_SysClk_ClkPathGetFrequency(path);

    /* Divide the path input frequency down and return the result */
#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
    if(Cy_SysClk_IsClkHfDirectSelEnabled(clkHf))
    {
        return (CY_SYSCLK_IMO_FREQ);
    }
    else
    {
        return (CY_SYSLIB_DIV_ROUND(freq, pDiv));
    }
#else
        return (CY_SYSLIB_DIV_ROUND(freq, pDiv));
#endif
#endif
}

#if defined (CY_IP_MXS22SRSS)
uint32_t Cy_SysClk_ClkHfGetMaskOnPath(cy_en_clkhf_in_sources_t clkPath)
{
  uint32_t clkHfMask = 0;
  if (clkPath <= CY_SYSCLK_CLKHF_IN_CLKPATH15)
  {
    for (uint32_t i = 0; i < CY_SRSS_NUM_HFROOT; i++)
    {
      bool enabled;
      cy_en_clkhf_in_sources_t src;
      enabled = Cy_SysClk_ClkHfIsEnabled(i);
      if (enabled)
      {
        src = Cy_SysClk_ClkHfGetSource(i);
        if (src == clkPath)
        {
          clkHfMask |= (1UL  << i);
        }
      }
    }
  }
  return clkHfMask;
}

uint32_t Cy_SysClk_ClkHfAllGetMask(void)
{
    uint32_t clkHfMask = 0;
    for (uint32_t i = 0; i < CY_SRSS_NUM_HFROOT; i++)
    {
        bool enabled;
        enabled = Cy_SysClk_ClkHfIsEnabled(i);
        if (enabled)
        {
            clkHfMask |= (1UL  << i);
        }
      }
  return clkHfMask;
}

void Cy_SysClk_ClkHfEnableDividerWithMask(uint32_t clkHfMask, cy_en_clkhf_dividers_t divider)
{
    uint32_t clkHf = 0UL;

    if (clkHfMask != 0UL)
    {
        while (clkHfMask != 0UL)
        {
            if ((clkHfMask & 1UL) != 0UL)
            {
                /* disable/disable root selection and enable clock path */
                (void)Cy_SysClk_ClkHfSetDivider(clkHf, divider);
            }
            clkHfMask = clkHfMask >> 1;
            clkHf++;
        }
    }
}

void Cy_SysClk_ClkHfEnableDirectMuxWithMask(uint32_t clkHfMask, bool enable)
{
  uint32_t clkHf = 0UL;

  if (clkHfMask != 0UL)
  {
    while (clkHfMask != 0UL)
    {
      if ((clkHfMask & 1UL) != 0UL)
      {
        /* disable/disable root selection and enable clock path */
        (void)Cy_SysClk_ClkHfDirectSel(clkHf, enable);
      }
      clkHfMask = clkHfMask >> 1;
      clkHf++;
    }
  }
}
#endif /*  defined (CY_IP_MXS22SRSS) */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

cy_en_sysclk_status_t Cy_SysClk_ClkHfDirectSel(uint32_t clkHf, bool enable)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        CY_REG32_CLR_SET(SRSS_CLK_DIRECT_SELECT[clkHf], SRSS_CLK_DIRECT_SELECT_DIRECT_MUX, !(enable));
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}

bool Cy_SysClk_IsClkHfDirectSelEnabled(uint32_t clkHf)
{
    bool retVal = false;
    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        return !(_FLD2BOOL(SRSS_CLK_DIRECT_SELECT_DIRECT_MUX, SRSS_CLK_DIRECT_SELECT[clkHf]));
    }
    return (retVal);
}

#elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
cy_en_sysclk_status_t Cy_SysClk_ClkHfDirectSel(uint32_t clkHf, bool enable)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        CY_REG32_CLR_SET(SRSS_CLK_ROOT_SELECT[clkHf], SRSS_CLK_ROOT_SELECT_DIRECT_MUX, !(enable));
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}

bool Cy_SysClk_IsClkHfDirectSelEnabled(uint32_t clkHf)
{
    bool retVal = false;
    if (clkHf < CY_SRSS_NUM_HFROOT)
    {
        return !(_FLD2BOOL(SRSS_CLK_ROOT_SELECT_DIRECT_MUX, SRSS_CLK_ROOT_SELECT[clkHf]));
    }
    return (retVal);
}

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) || \
    ((defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && defined(SRSS_CSV_HF_CSV_REF_CTL))
uint32_t Cy_SysClk_ClkHfCsvGetRefFrequency(cy_en_clkhf_csv_ref_clk_t refClk)
 {
    uint32_t freq = 0UL;

    /* Get the frequency of the source  */
    switch(refClk)
     {
        case CY_SYSCLK_CLKHF_CSV_REF_IMO: /* The IMO frequency is fixed at 8 MHz */
            freq = CY_SYSCLK_IMO_FREQ;
            break;

        case CY_SYSCLK_CLKHF_CSV_REF_EXT:
            freq = Cy_SysClk_ExtClkGetFrequency();
            break;

        case CY_SYSCLK_CLKHF_CSV_REF_ECO:
            freq = Cy_SysClk_EcoGetFrequency();
            break;

#if !(defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3))
        case CY_SYSCLK_CLKHF_CSV_REF_IHO:
            freq = (Cy_SysClk_IhoIsEnabled()) ? CY_SYSCLK_IHO_FREQ : 0UL;
            break;
#endif /* !(defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) */

        default:
            /* Don't know the frequency of dsi_out, leave freq = 0UL */
            break;
     }
    return (freq);
 }


cy_en_sysclk_status_t Cy_SysClk_ClkHfCsvManualConfigure(const cy_stc_clkhf_csv_hf_config_t * hfConfig, const cy_stc_clkhf_csv_manual_config_t * csvConfig)
{
    /* Check for errors */
    CY_ASSERT_L1(hfConfig != NULL);
    CY_ASSERT_L1(csvConfig != NULL);
    CY_ASSERT_L1(hfConfig->clkHf < CY_SRSS_NUM_HFROOT);

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint32_t monitorFreq = Cy_SysClk_ClkHfGetFrequency(hfConfig->clkHf);
    uint32_t refFreq = Cy_SysClk_ClkHfCsvGetRefFrequency(hfConfig->refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;

    CY_ASSERT_L1(csvConfig->upperLimit > CSV_MIN_TARGET_VAL);
    CY_ASSERT_L1(csvConfig->lowerLimit < csvConfig->upperLimit -1U);
    CY_ASSERT_L1((int32_t) csvConfig->startTime >= (((int32_t)(((float32_t)(csvConfig->period +3UL)) * (f_refFreq / f_monitorFreq))) - ((int32_t)csvConfig->upperLimit)));

    (void) monitorFreq; /* Used only in Assert comparison. */
    (void) refFreq;  /* Used only in Assert comparison.  */
    (void) f_monitorFreq; /* Used only in Assert comparison. */
    (void) f_refFreq;  /* Used only in Assert comparison.  */

    if(hfConfig->clkHf < CY_SRSS_NUM_HFROOT)
    {
        CY_REG32_CLR_SET(SRSS_CSV_REF_SEL, SRSS_CSV_REF_SEL_REF_MUX, hfConfig->refClk);
        CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_REF_CTL(hfConfig->clkHf), CSV_HF_CSV_REF_CTL_CSV_STARTUP, csvConfig->startTime - 1UL);
        CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_REF_LIMIT(hfConfig->clkHf), CSV_HF_CSV_REF_LIMIT_CSV_LOWER, csvConfig->lowerLimit - 1UL);
        CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_REF_LIMIT(hfConfig->clkHf), CSV_HF_CSV_REF_LIMIT_CSV_UPPER, csvConfig->upperLimit - 1UL);
        CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_MON_CTL(hfConfig->clkHf), CSV_HF_CSV_MON_CTL_CSV_PERIOD, csvConfig->period - 1UL);
        retVal = CY_SYSCLK_SUCCESS;
    }

    return retVal;
}


cy_en_sysclk_status_t Cy_SysClk_ClkHfCsvConfigure(const cy_stc_clkhf_csv_hf_config_t * hfConfig, uint32_t accuracy)
{
    CY_ASSERT_L1(hfConfig != NULL);
    CY_ASSERT_L1(hfConfig->clkHf < CY_SRSS_NUM_HFROOT);

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    cy_stc_clkhf_csv_manual_config_t csvConfig= {0, 0, 0, 0};

    if(hfConfig->clkHf < CY_SRSS_NUM_HFROOT)
    {
        uint32_t target = CSV_MIN_TARGET_VAL;
        uint32_t monitorFreq = Cy_SysClk_ClkHfGetFrequency(hfConfig->clkHf);
        uint32_t refFreq = Cy_SysClk_ClkHfCsvGetRefFrequency(hfConfig->refClk);
        float32_t f_monitorFreq = (float32_t) monitorFreq;
        float32_t f_refFreq = (float32_t) refFreq;
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.lowerLimit = (uint32_t) ((float32_t)target - (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F)));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.upperLimit = (uint32_t) ((float32_t)target + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F)));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.period =  (uint32_t) (((float32_t) target) / (f_refFreq / f_monitorFreq));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.startTime = (uint32_t) ((((float32_t)(csvConfig.period + 3UL)) * (f_refFreq / f_monitorFreq))
                                + (CSV_MIN_STARTUP_DELAY * f_refFreq)
                                + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F))) + 1U;

        retVal= Cy_SysClk_ClkHfCsvManualConfigure(hfConfig, &csvConfig);
    }
    return retVal;
}


void Cy_SysClk_ClkHfCsvAction(uint32_t clkHf, cy_en_clkhf_csv_action_t action)
{
    CY_ASSERT_L1(clkHf < CY_SRSS_NUM_HFROOT);
    CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_REF_CTL(clkHf), CSV_HF_CSV_REF_CTL_CSV_ACTION, action);
}


void Cy_SysClk_ClkHfCsvEnable(uint32_t clkHf)
{
    CY_ASSERT_L1(clkHf < CY_SRSS_NUM_HFROOT);
    CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_REF_CTL(clkHf), CSV_HF_CSV_REF_CTL_CSV_EN, 1U);
}


void Cy_SysClk_ClkHfCsvDisable(uint32_t clkHf)
{
    CY_ASSERT_L1(clkHf < CY_SRSS_NUM_HFROOT);
    CY_REG32_CLR_SET(SRSS_CSV_HF_CSV_REF_CTL(clkHf), CSV_HF_CSV_REF_CTL_CSV_EN, 0U);
}


bool Cy_SysClk_IsClkHfCsvEnabled(uint32_t clkHf)
{
    CY_ASSERT_L1(clkHf < CY_SRSS_NUM_HFROOT);
    return (0UL != (SRSS_CSV_HF_CSV_REF_CTL(clkHf) & CSV_HF_CSV_REF_CTL_CSV_EN_Msk));
}
#endif

/* ========================================================================== */
/* ============================    MFO SECTION    ============================ */
/* ========================================================================== */

#if defined (CY_IP_MXS40SSRSS)

void Cy_SysClk_MfoEnable(bool deepSleepEnable)
{
#if (defined(CY_SRSS_MFO_PRESENT) && (CY_SRSS_MFO_PRESENT))
#if defined (CY_IP_MXS28SRSS)
    SRSS_CLK_MFO_CONFIG = SRSS_CLK_MFO_CONFIG_ENABLE_Msk;
#else
    SRSS_CLK_MFO_CONFIG = SRSS_CLK_MFO_CONFIG_ENABLE_Msk | (deepSleepEnable ? SRSS_CLK_MFO_CONFIG_DPSLP_ENABLE_Msk : 0UL);
#endif
#endif
    (void) deepSleepEnable;
}

bool Cy_SysClk_MfoIsEnabled(void)
{
#if (defined(CY_SRSS_MFO_PRESENT) && (CY_SRSS_MFO_PRESENT))
    return (0UL != (SRSS_CLK_MFO_CONFIG & SRSS_CLK_MFO_CONFIG_ENABLE_Msk));
#else
    return false;
#endif

}

void Cy_SysClk_MfoDisable(void)
{
#if (defined(CY_SRSS_MFO_PRESENT) && (CY_SRSS_MFO_PRESENT))
    SRSS_CLK_MFO_CONFIG = 0UL;
#endif
}
#endif

/* ========================================================================== */
/* ============================    CLK_MF SECTION    ============================ */
/* ========================================================================== */

#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 == 0UL)) || defined (CY_IP_MXS28SRSS)

void Cy_SysClk_ClkMfEnable(void)
{
    SRSS_CLK_MF_SELECT |= SRSS_CLK_MF_SELECT_ENABLE_Msk;
}


bool Cy_SysClk_ClkMfIsEnabled(void)
{
    return ((0UL != (SRSS_CLK_MF_SELECT & SRSS_CLK_MF_SELECT_ENABLE_Msk)));
}


void Cy_SysClk_ClkMfDisable(void)
{
    SRSS_CLK_MF_SELECT &= ~SRSS_CLK_MF_SELECT_ENABLE_Msk;
}


void Cy_SysClk_ClkMfSetDivider(uint32_t divider)
{
    if (CY_SYSCLK_IS_MF_DIVIDER_VALID(divider))
    {
        if (!Cy_SysClk_ClkMfIsEnabled())
        {
            CY_REG32_CLR_SET(SRSS_CLK_MF_SELECT, SRSS_CLK_MF_SELECT_MFCLK_DIV, divider - 1UL);
        }
    }
}


uint32_t Cy_SysClk_ClkMfGetDivider(void)
{
    return ((1UL + _FLD2VAL(SRSS_CLK_MF_SELECT_MFCLK_DIV, SRSS_CLK_MF_SELECT)));
}


uint32_t Cy_SysClk_ClkMfGetFrequency(void)
{
    uint32_t mfFreq = 0UL, mfDiv;

      /* Get the frequency of the source, i.e., the path mux input */
        switch(Cy_SysClk_ClkMfGetSource())
        {
#if defined(CY_IP_MXS22SRSS)
            case CY_SYSCLK_CLKMF_IN_IMO: /* The IMO frequency is fixed at 8 MHz */
                mfFreq = CY_SYSCLK_IMO_FREQ;
                break;
#else
            case CY_SYSCLK_CLKMF_IN_MFO: /* The IMO frequency is fixed at 8 MHz */
                mfFreq =(Cy_SysClk_MfoIsEnabled()) ? CY_SYSCLK_MFO_FREQ : 0UL;
                break;
#endif
            case CY_SYSCLK_CLKMF_IN_ILO:
                mfFreq = CY_SYSCLK_ILO_FREQ;
                break;

            case CY_SYSCLK_CLKMF_IN_WCO:
                mfFreq = (Cy_SysClk_WcoOkay()) ? CY_SYSCLK_WCO_FREQ : 0UL;
                break;

#if (defined (CY_SRSS_ALTHF_PRESENT) && (CY_SRSS_ALTHF_PRESENT == 1U))
            case CY_SYSCLK_CLKMF_IN_ALTLF:
                mfFreq = (Cy_SysClk_IsAltHfEnabled()) ? Cy_SysClk_AltHfGetFrequency() : 0UL;
                break;
#endif

            case CY_SYSCLK_CLKMF_IN_PILO:
                mfFreq = (0UL != (SRSS_CLK_PILO_CONFIG & SRSS_CLK_PILO_CONFIG_PILO_EN_Msk)) ? CY_SYSCLK_PILO_FREQ : 0UL;
                break;

#if defined(CY_IP_MXS22SRSS)
            case CY_SYSCLK_CLKMF_IN_IHO:
                mfFreq = CY_SYSCLK_IHO_FREQ;
                break;
#endif

            default:
                /* Don't know the frequency of dsi_out, leave freq = 0UL */
                break;
        }

    mfDiv = Cy_SysClk_ClkMfGetDivider(); /* clkMf prescaler (1-256) */

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(mfFreq, mfDiv));
}

void Cy_SysClk_ClkMfSetSource(cy_en_clkmf_in_sources_t source)
{
    CY_ASSERT_L3(CY_SYSCLK_IF_MF_SOURCE_VALID(source));
    CY_REG32_CLR_SET(SRSS_CLK_MF_SELECT, SRSS_CLK_MF_SELECT_MFCLK_SEL, source);
}


cy_en_clkmf_in_sources_t Cy_SysClk_ClkMfGetSource(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_clkmf_in_sources_t enum.');
    return ((cy_en_clkmf_in_sources_t)(_FLD2VAL(SRSS_CLK_MF_SELECT_MFCLK_SEL, SRSS_CLK_MF_SELECT)));
}

#endif /* (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 == 0UL)) || defined (CY_IP_MXS28SRSS) */

/* ========================================================================== */
/* ===========================    WCO SECTION    =========================== */
/* ========================================================================== */

cy_en_sysclk_status_t Cy_SysClk_WcoEnable(uint32_t timeoutus)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_TIMEOUT;

    /* Enable WCO */
#if defined (CY_IP_MXS28SRSS)
    BACKUP_WCO_CTL |= BACKUP_WCO_CTL_WCO_EN_Msk;
#elif defined (CY_IP_MXS22SRSS)
    BACKUP_CTL |= SRSS_CLK_WCO_CONFIG_WCO_EN_Msk;
#else
    BACKUP_CTL |= BACKUP_CTL_WCO_EN_Msk;
#endif

    /* now do the timeout wait for STATUS, bit WCO_OK */
    for (; (Cy_SysClk_WcoOkay() == false) && (0UL != timeoutus); timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    if (0UL != timeoutus)
    {
        retVal = CY_SYSCLK_SUCCESS;
    }

    return (retVal);
}

bool Cy_SysClk_WcoOkay(void)
{
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
    return (_FLD2BOOL(BACKUP_STATUS_WCO_OK, BACKUP_STATUS));
#elif defined (CY_IP_MXS22SRSS)
    return (_FLD2BOOL(SRSS_CLK_WCO_STATUS_WCO_OK, BACKUP_WCO_STATUS));
#else
    return (_FLD2BOOL(BACKUP_WCO_STATUS_WCO_OK, BACKUP_STATUS));
#endif
}

void Cy_SysClk_WcoDisable(void)
{
#if defined (CY_IP_MXS28SRSS)
    BACKUP_WCO_CTL &= (uint32_t)~BACKUP_WCO_CTL_WCO_EN_Msk;
#elif defined (CY_IP_MXS22SRSS)
    BACKUP_CTL &= (uint32_t)~SRSS_CLK_WCO_CONFIG_WCO_EN_Msk;
#else
    BACKUP_CTL &= (uint32_t)~BACKUP_CTL_WCO_EN_Msk;
#endif
}

#if defined (CY_IP_MXS28SRSS)
void Cy_SysClk_WcoGainControl(cy_en_wco_gain_ctrl_modes_t gmMode)
{
    CY_REG32_CLR_SET(BACKUP_WCO_CTL, BACKUP_WCO_CTL_GM, gmMode);
}
#endif /* defined (CY_IP_MXS28SRSS) */

void Cy_SysClk_WcoBypass(cy_en_wco_bypass_modes_t bypass)
{
#if defined (CY_IP_MXS28SRSS)
    CY_REG32_CLR_SET(BACKUP_WCO_CTL, BACKUP_WCO_CTL_WCO_BYP_EN, bypass);
#elif defined (CY_IP_MXS22SRSS)
    CY_REG32_CLR_SET(BACKUP_CTL, SRSS_CLK_WCO_CONFIG_WCO_BYPASS, bypass);
#else
    CY_REG32_CLR_SET(BACKUP_CTL, BACKUP_CTL_WCO_BYPASS, bypass);
#endif
}

/* ========================================================================== */
/* ===========================    PILO SECTION    =========================== */
/* ========================================================================== */

#define CY_SYSCLK_PILO_STARTUP_DELAY 250U
#define CY_SYSCLK_PILO_TEST_COUNT 10U
#define CY_SYSCLK_PILO_TEST_DELAY 100U

void Cy_SysClk_PiloEnable(void)
{
#if (defined (CY_SRSS_PILO_PRESENT) && (0U != CY_SRSS_PILO_PRESENT))
    SRSS_CLK_PILO_CONFIG |= SRSS_CLK_PILO_CONFIG_PILO_EN_Msk; /* 1 = enable */
#endif

    /* Max 150us is needed for PILO Startup */
    Cy_SysLib_DelayUs(CY_SYSCLK_PILO_STARTUP_DELAY);
}
#if defined (CY_IP_MXS40SSRSS)
void Cy_SysClk_PiloBackupEnable(void)
{
#if defined (CY_SRSS_PILO_PRESENT) && (0U != CY_SRSS_PILO_PRESENT)
    SRSS_CLK_PILO_CONFIG |= SRSS_CLK_PILO_CONFIG_PILO_BACKUP_Msk; /* 1 = enable */
#endif
}

void Cy_SysClk_PiloBackupDisable(void)
{
#if defined (CY_SRSS_PILO_PRESENT) && (0U != CY_SRSS_PILO_PRESENT)
    /* Clear PILO_BACKUP bitfields. */
    SRSS_CLK_PILO_CONFIG &= (uint32_t)~(SRSS_CLK_PILO_CONFIG_PILO_BACKUP_Msk);
#endif
}
#endif

#if defined (CY_IP_MXS40SSRSS)
void Cy_SysClk_PiloTcscEnable(void)
{
#if (CY_SRSS_PILO_PRESENT)
    SRSS_CLK_PILO_CONFIG |= SRSS_CLK_PILO_CONFIG_PILO_TCSC_EN_Msk; /* 1 = enable */
#endif
}

void Cy_SysClk_PiloTcscDisable(void)
{
#if (CY_SRSS_PILO_PRESENT)
    /* Clear PILO_TCSC_EN( Second order temperature curvature correction.) bitfields. */
    SRSS_CLK_PILO_CONFIG &= (uint32_t)~(SRSS_CLK_PILO_CONFIG_PILO_TCSC_EN_Msk);
#endif
}

bool Cy_SysClk_PiloOkay(void)
{
#if (CY_SRSS_PILO_PRESENT)
    SRSS_CLK_OUTPUT_FAST = SLOW_SEL_OUTPUT_INDEX;
    SRSS_CLK_OUTPUT_SLOW = (uint32_t)CY_SYSCLK_MEAS_CLK_PILO;
    SRSS_CLK_CAL_CNT1 = CY_SYSCLK_PILO_TEST_COUNT;

    /* Wait atleast two PILO clock cycles before reading CAL_CLK1_PRESENT bit */
    Cy_SysLib_DelayUs(CY_SYSCLK_PILO_TEST_DELAY);

    return (_FLD2BOOL(SRSS_CLK_CAL_CNT1_CAL_CLK1_PRESENT, SRSS_CLK_CAL_CNT1));
#else
    return false;
#endif
}
#endif /* defined (CY_IP_MXS40SSRSS) */

bool Cy_SysClk_PiloIsEnabled(void)
{
#if (defined (CY_SRSS_PILO_PRESENT) && (0U != CY_SRSS_PILO_PRESENT))
    return (_FLD2BOOL(SRSS_CLK_PILO_CONFIG_PILO_EN, SRSS_CLK_PILO_CONFIG));
#else
    return false;
#endif
}

void Cy_SysClk_PiloDisable(void)
{
#if (defined (CY_SRSS_PILO_PRESENT) && (0U != CY_SRSS_PILO_PRESENT))
    /* Clear PILO_EN */
    SRSS_CLK_PILO_CONFIG &= (uint32_t)~(SRSS_CLK_PILO_CONFIG_PILO_EN_Msk);
#endif
}

/* ========================================================================== */
/* ==========================    ALTLF SECTION    =========================== */
/* ========================================================================== */


uint32_t Cy_SysClk_AltLfGetFrequency(void)
{
    return (0UL);
}


bool Cy_SysClk_AltLfIsEnabled(void)
{
    return (false);
}


/* ========================================================================== */
/* ===========================    ILO SECTION    ============================ */
/* ========================================================================== */

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))


/* Below ILO API's are valid for both ILO0 and ILO1 */
void Cy_SysClk_IloSrcEnable(uint32_t iloNum)
{
    CY_ASSERT_L1(iloNum < CY_SRSS_ILO_COUNT);

    if (0UL == iloNum)
    {
        SRSS_CLK_ILO0_CONFIG |= SRSS_CLK_ILO0_CONFIG_ENABLE_Msk;
    }
    else
    {
        SRSS_CLK_ILO1_CONFIG |= SRSS_CLK_ILO1_CONFIG_ENABLE_Msk;
    }
}

cy_en_sysclk_status_t Cy_SysClk_IloSrcDisable(uint32_t iloNum)
{
    CY_ASSERT_L1(iloNum < CY_SRSS_ILO_COUNT);
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if (0UL == iloNum)
    {
        if (!_FLD2BOOL(WDT_CTL_ENABLED, SRSS_WDT_CTL)) /* if disabled */
        {
            SRSS_CLK_ILO0_CONFIG &= ~SRSS_CLK_ILO0_CONFIG_ENABLE_Msk;
            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else
    {
        SRSS_CLK_ILO1_CONFIG &= ~SRSS_CLK_ILO1_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}

bool Cy_SysClk_IloSrcIsEnabled(uint32_t iloNum)
{
    CY_ASSERT_L1(iloNum < CY_SRSS_ILO_COUNT);

    if (0UL == iloNum)
    {
        return (_FLD2BOOL(SRSS_CLK_ILO0_CONFIG_ENABLE, SRSS_CLK_ILO0_CONFIG));
    }
    else
    {
        return (_FLD2BOOL(SRSS_CLK_ILO1_CONFIG_ENABLE, SRSS_CLK_ILO1_CONFIG));
    }
}

void Cy_SysClk_IloSrcHibernateOn(uint32_t iloNum, bool on)
{
    if (0UL == iloNum)
    {
        CY_REG32_CLR_SET(SRSS_CLK_ILO0_CONFIG, SRSS_CLK_ILO0_CONFIG_ILO0_BACKUP, ((on) ? 1UL : 0UL));
    }
}

#elif (defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS))
void Cy_SysClk_IloEnable(void)
{
#if (CY_SRSS_ILO_PRESENT)
    SRSS_CLK_ILO_CONFIG |= SRSS_CLK_ILO_CONFIG_ENABLE_Msk;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_IloDisable(void)
{
#if (CY_SRSS_ILO_PRESENT)
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;
    if (!_FLD2BOOL(SRSS_WDT_CTL_WDT_EN, SRSS_WDT_CTL)) /* if disabled */
    {
        SRSS_CLK_ILO_CONFIG &= ~SRSS_CLK_ILO_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

bool Cy_SysClk_IloIsEnabled(void)
{
#if (CY_SRSS_ILO_PRESENT)
    return (_FLD2BOOL(SRSS_CLK_ILO_CONFIG_ENABLE, SRSS_CLK_ILO_CONFIG));
#else
    return false;
#endif
}

void Cy_SysClk_IloHibernateOn(bool on)
{
    CY_UNUSED_PARAMETER(on);
#if (CY_SRSS_ILO_PRESENT)
    CY_REG32_CLR_SET(SRSS_CLK_ILO_CONFIG, SRSS_CLK_ILO_CONFIG_ILO_BACKUP, ((on) ? 1UL : 0UL));
#endif
}

#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) */


/* ========================================================================== */
/* =========================    EXTCLK SECTION    =========================== */
/* ========================================================================== */


    static uint32_t cySysClkExtFreq = 0UL;

#if defined (SRSS_HT_VARIANT)
#define CY_SYSCLK_EXTCLK_MAX_FREQ (80000000UL) /* 80 MHz */
#else
#define CY_SYSCLK_EXTCLK_MAX_FREQ (100000000UL) /* 100 MHz */
#endif


void Cy_SysClk_ExtClkSetFrequency(uint32_t freq)
{
    if (freq <= CY_SYSCLK_EXTCLK_MAX_FREQ)
    {
        cySysClkExtFreq = freq;
    }
}

/*******************************************************************************
* Function Name: Cy_SysClk_ExtClkGetFrequency
****************************************************************************//**
*
* Returns the frequency of the External Clock Source (EXTCLK) from the
* internal storage.
*
* \return The frequency of the External Clock Source.
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_ExtClkSetFrequency
*
*******************************************************************************/
uint32_t Cy_SysClk_ExtClkGetFrequency(void)
{
    return (cySysClkExtFreq);
}

/* ========================================================================== */
/* ===========================    ECO SECTION    ============================ */
/* ========================================================================== */

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || \
    (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL))
#if (CY_SRSS_ECO_PRESENT)
static uint32_t ecoFrequency = 0UL; /* Internal storage for ECO frequency user setting */
#endif

#define CY_SYSCLK_INVALID_TRIM_VALUE (0xFFFFFFFFUL)


#if defined (CY_IP_MXS22SRSS)

cy_en_sysclk_status_t Cy_SysClk_EcoManualConfigure(const cy_stc_clk_eco_config_t *ecoConfig)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L3(CY_SYSCLK_IS_CLK_ECO_CTRIM_VALID(ecoConfig->ecoCtrim));
    CY_ASSERT_L3(CY_SYSCLK_IS_CLK_ECO_GTRIM_VALID(ecoConfig->ecoGtrim));

    /* Invalid state error if ECO is already enabled */
    if (0UL != (SRSS_CLK_ECO_CONFIG_ECO_EN_Msk & SRSS_CLK_ECO_CONFIG))
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }

    if( CY_SYSCLK_SUCCESS == retVal)
    {
        SRSS_CLK_ECO_CONFIG2 =
        _VAL2FLD(SRSS_CLK_ECO_CONFIG2_ECO_TRIM_CL, ecoConfig->ecoCtrim) |
        _VAL2FLD(SRSS_CLK_ECO_CONFIG2_ECO_TRIM_GAIN, ecoConfig->ecoGtrim);

        SRSS_CLK_TRIM_ECO_CTL |=
        _VAL2FLD(SRSS_CLK_TRIM_ECO_CTL_ECO_CTRL_IBOOSTEN, ecoConfig->ecoIboost);

        ecoFrequency = ecoConfig->ecoClkfreq;
    }

    return retVal;

}


#endif /* defined (CY_IP_MXS22SRSS) */


void Cy_SysClk_EcoDisable(void)
{
#if (CY_SRSS_ECO_PRESENT)
    SRSS_CLK_ECO_CONFIG &= ~SRSS_CLK_ECO_CONFIG_ECO_EN_Msk;
#endif
}


uint32_t Cy_SysClk_EcoGetStatus(void)
{
#if (CY_SRSS_ECO_PRESENT)
    return (SRSS_CLK_ECO_STATUS & SRSS_CLK_ECO_STATUS_Msk);
#else
    return 0;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_EcoEnable(uint32_t timeoutus)
{
#if (CY_SRSS_ECO_PRESENT)
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;
    bool zeroTimeout = (0UL == timeoutus);

    /* Invalid state error if ECO is already enabled */
    if (0UL == (SRSS_CLK_ECO_CONFIG_ECO_EN_Msk & SRSS_CLK_ECO_CONFIG))
    {
        /* Set ECO enable */
        SRSS_CLK_ECO_CONFIG |= SRSS_CLK_ECO_CONFIG_ECO_EN_Msk;

        /* Wait for CY_SYSCLK_ECOSTAT_OK_AND_READY */
        for (; (CY_SYSCLK_ECOSTAT_OK_AND_READY != Cy_SysClk_EcoGetStatus()) && (0UL != timeoutus); timeoutus--)
        {
            Cy_SysLib_DelayUs(1U);
        }

        if (zeroTimeout || (0UL != timeoutus))
        {
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            /* If ECO doesn't start, then disable it */
            SRSS_CLK_ECO_CONFIG &= ~SRSS_CLK_ECO_CONFIG_ECO_EN_Msk;
            retVal = CY_SYSCLK_TIMEOUT;
        }
    }

    return (retVal);

#else
    (void) timeoutus;
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

uint32_t Cy_SysClk_EcoGetFrequency(void)
{
#if (CY_SRSS_ECO_PRESENT)
    return ((CY_SYSCLK_ECOSTAT_OK_AND_READY == Cy_SysClk_EcoGetStatus()) ? ecoFrequency : 0UL);
#else
    return 0;
#endif
}

void Cy_SysClk_EcoSetFrequency(uint32_t freq)
{
#if (CY_SRSS_ECO_PRESENT)
    ecoFrequency = freq;
#else
    ecoFrequency = 0;
#endif
}

cy_en_sysclk_status_t Cy_SysClk_EcoPrescaleConfigure(uint32_t enable, uint32_t int_div, uint32_t frac_div)
{
    uint32_t timeoutus = CY_SYSCLK_ECO_PRESCALER_TIMEOUT_US;
    (void) enable;
#if (CY_SRSS_ECO_PRESENT)
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if(0UL != enable) {
        /* Invalid state error if CO_DIV_ENABLED is already enabled */
        if (0UL == (SRSS_CLK_ECO_PRESCALE_ECO_DIV_ENABLED_Msk & SRSS_CLK_ECO_PRESCALE))
        {
            SRSS_CLK_ECO_PRESCALE = (_VAL2FLD(SRSS_CLK_ECO_PRESCALE_ECO_INT_DIV, int_div) | \
                                      _VAL2FLD(SRSS_CLK_ECO_PRESCALE_ECO_FRAC_DIV, frac_div));

            SRSS_CLK_ECO_CONFIG |= SRSS_CLK_ECO_CONFIG_ECO_DIV_ENABLE_Msk;

            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    else {
        /* Invalid state error if CO_DIV_ENABLED is already disabled */
        if (1UL == (SRSS_CLK_ECO_PRESCALE_ECO_DIV_ENABLED_Msk & SRSS_CLK_ECO_PRESCALE))
        {
            SRSS_CLK_ECO_CONFIG |= (SRSS_CLK_ECO_CONFIG_ECO_DIV_DISABLE_Msk);
            retVal = CY_SYSCLK_SUCCESS;
        }
    }

    if(retVal == CY_SYSCLK_SUCCESS)
    {
        /* Wait until ENABLED bit is set or cleared */
        for (; (_FLD2BOOL(SRSS_CLK_ECO_PRESCALE_ECO_DIV_ENABLED, SRSS_CLK_ECO_PRESCALE) != (bool)enable) &&
               (0UL != timeoutus);
             timeoutus--)
        {
            Cy_SysLib_DelayUs(1U);
        }

        if ((0UL != timeoutus))
        {
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            retVal = CY_SYSCLK_TIMEOUT;
        }
    }
    return retVal;
#else
    (void) frac_div;
    (void) int_div;

    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


bool Cy_SysClk_EcoPrescaleIsEnabled(void)
{
#if (CY_SRSS_ECO_PRESENT)
    return (_FLD2BOOL(SRSS_CLK_ECO_PRESCALE_ECO_DIV_ENABLED, SRSS_CLK_ECO_PRESCALE));
#else
    return false;
#endif
}

uint32_t Cy_SysClk_EcoPrescaleGetFrequency(void)
{
    uint32_t freq = Cy_SysClk_EcoGetFrequency();
    uint32_t div =  (_FLD2VAL(SRSS_CLK_ECO_PRESCALE_ECO_INT_DIV, SRSS_CLK_ECO_PRESCALE) + \
                    (_FLD2VAL(SRSS_CLK_ECO_PRESCALE_ECO_FRAC_DIV, SRSS_CLK_ECO_PRESCALE) / 256UL));

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(freq, div));
}

#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) */


#if defined (CY_IP_MXS28SRSS)
cy_en_sysclk_status_t Cy_SysClk_EcoBleControl(cy_en_eco_for_ble_t control, uint32_t timeoutus)
{
#if (CY_SRSS_ECO_PRESENT)
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;
    bool zeroTimeout = (0UL == timeoutus);

    CY_ASSERT_L1(control < sizeof(cy_en_eco_for_ble_t));

    /* Set ECO for BLE with control value */
    SRSS_CLK_ECO_CONFIG |= (control << SRSS_CLK_ECO_CONFIG_ECO_BLE_EN_Pos);

    /* Wait for stable ECO condition */
    for (; (CY_SYSCLK_ECOSTAT_BLE_ENABLED != Cy_SysClk_EcoBleGetStatus()) && (0UL != timeoutus); timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    retVal = (zeroTimeout || (0UL != timeoutus)) ? CY_SYSCLK_SUCCESS : CY_SYSCLK_TIMEOUT;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

#endif /* defined (CY_IP_MXS28SRSS) */

#if defined (CY_IP_MXS28SRSS)

uint32_t Cy_SysClk_EcoBleGetStatus(void)
{
#if defined (CY_IP_MXS28SRSS)
#if (CY_SRSS_ECO_PRESENT)
    /* if ECO for BLE is Enabled, report 1. Otherwise report 0 */
    return ((SRSS_CLK_ECO_STATUS_ECO_BLE_ENABLED_Msk == (SRSS_CLK_ECO_STATUS_ECO_BLE_ENABLED_Msk & SRSS_CLK_ECO_STATUS)) ?
      CY_SYSCLK_ECOSTAT_BLE_ENABLED : CY_SYSCLK_ECOSTAT_BLE_DISABLED);
#else
    return 0;
#endif
#else
    return 0;
#endif

}

#endif /* defined (CY_IP_MXS28SRSS) */

/* ========================================================================== */
/* ==========================    LPECO SECTION    =========================== */
/* ========================================================================== */

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && (defined (SRSS_BACKUP_S40E_LPECO_PRESENT) && (SRSS_BACKUP_S40E_LPECO_PRESENT == 1u))

#define Cy_SysClk_LpEco_PRESCALER_MAX_INT_DIV (1023u) /* 10 bit value */
#define Cy_SysClk_LpEco_PRESCALER_MAX_FRAC_DIV (255u) /* 8 bit value */

static uint32_t lpecoFrequency = 0UL; /* Internal storage for LPECO frequency user setting */

void Cy_SysClk_LpEcoConfigure(cy_en_clkbak_lpeco_loadcap_range_t capValue,
                              cy_en_clkbak_lpeco_frequency_range_t freqValue,
                              cy_en_clkbak_lpeco_max_amplitude_t ampValue,
                              bool ampDetEn)
{
    BACKUP_LPECO_CTL |= (_VAL2FLD(BACKUP_LPECO_CTL_LPECO_CRANGE, capValue) |
                         _VAL2FLD(BACKUP_LPECO_CTL_LPECO_FRANGE, freqValue) |
                         _VAL2FLD(BACKUP_LPECO_CTL_LPECO_AMP_SEL, ampValue) |
                         _VAL2FLD(BACKUP_LPECO_CTL_LPECO_AMPDET_EN, (ampDetEn ? 1u : 0u)));
}

cy_en_sysclk_status_t Cy_SysClk_LpEcoEnable(uint32_t timeoutus)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;
    bool zeroTimeout = (0U == timeoutus);

    /* Invalid state error if ECO is already enabled */
    if (0UL == (SRSS_CLK_ECO_CONFIG_ECO_EN_Msk & SRSS_CLK_ECO_CONFIG))
    {
        /* Enable the LPECO */
        BACKUP_LPECO_CTL |= BACKUP_LPECO_CTL_LPECO_EN_Msk;

        if (zeroTimeout)
        {
            /* Do not wait for the LPECO to stabilize, just exit and report success */
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            bool ampDetEn = _FLD2BOOL(BACKUP_LPECO_CTL_LPECO_AMPDET_EN, BACKUP_LPECO_CTL);

            /* Wait for the LPECO to stabilize OR the timeout to expire */
            do {
                bool lpecoStable = Cy_SysClk_LpEcoIsReady();
                if (ampDetEn)
                {
                    /* Only check the LPECO amplitude if checking is enabled */
                    lpecoStable = lpecoStable && Cy_SysClk_LpEcoAmplitudeOkay();
                }

                if (lpecoStable)
                {
                    retVal = CY_SYSCLK_SUCCESS;
                    break;
                }

                timeoutus--;
                Cy_SysLib_DelayUs(1U);

            } while (timeoutus > 0U);

            if (retVal != CY_SYSCLK_SUCCESS)
            {
                /* If LPECO doesn't start, then disable it */
                Cy_SysClk_LpEcoDisable();
                retVal = CY_SYSCLK_TIMEOUT;
            }
        }
    }

    return retVal;
}

void Cy_SysClk_LpEcoDisable(void)
{
    BACKUP_LPECO_CTL &= ~BACKUP_LPECO_CTL_LPECO_EN_Msk;
}

void Cy_SysClk_LpEcoSetFrequency(uint32_t freq)
{
    lpecoFrequency = freq;
}

uint32_t Cy_SysClk_LpEcoGetFrequency(void)
{
    bool lpecoStable = Cy_SysClk_LpEcoIsReady();
    if (_FLD2BOOL(BACKUP_LPECO_CTL_LPECO_AMPDET_EN, BACKUP_LPECO_CTL))
    {
        /* Only check the LPECO amplitude if checking is enabled */
        lpecoStable = lpecoStable && Cy_SysClk_LpEcoAmplitudeOkay();
    }
    return (lpecoStable ? lpecoFrequency : 0UL);
}

cy_en_sysclk_status_t Cy_SysClk_LpEcoPrescaleConfigure(bool enable, uint32_t int_div, uint32_t frac_div)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    if (enable)
    {
        /* Do not attempt to enable the LPECO if the inputs are invalid OR the LPECO is already enabled */
        if ((int_div > Cy_SysClk_LpEco_PRESCALER_MAX_INT_DIV) || (frac_div > Cy_SysClk_LpEco_PRESCALER_MAX_FRAC_DIV))
        {
            retVal = CY_SYSCLK_BAD_PARAM;
        }
        else if (!Cy_SysClk_LpEcoPrescaleIsEnabled())
        {
            BACKUP_LPECO_PRESCALE |= (_VAL2FLD(BACKUP_LPECO_PRESCALE_LPECO_INT_DIV, int_div) |
                                    _VAL2FLD(BACKUP_LPECO_PRESCALE_LPECO_FRAC_DIV, frac_div));

            BACKUP_LPECO_CTL |= BACKUP_LPECO_CTL_LPECO_DIV_ENABLE_Msk;
            retVal = CY_SYSCLK_SUCCESS;
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Disable the prescaler */
        BACKUP_LPECO_CTL &= ~BACKUP_LPECO_CTL_LPECO_DIV_ENABLE_Msk;
        retVal = CY_SYSCLK_SUCCESS;
    }

    return retVal;
}

bool Cy_SysClk_LpEcoPrescaleIsEnabled(void)
{
    return (_FLD2BOOL(BACKUP_LPECO_PRESCALE_LPECO_DIV_ENABLED, BACKUP_LPECO_PRESCALE));
}

bool Cy_SysClk_LpEcoAmplitudeOkay(void)
{
    return (_FLD2BOOL(BACKUP_LPECO_STATUS_LPECO_AMPDET_OK, BACKUP_LPECO_STATUS));
}

bool Cy_SysClk_LpEcoIsReady(void)
{
    return (_FLD2BOOL(BACKUP_LPECO_STATUS_LPECO_READY, BACKUP_LPECO_STATUS));
}

#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && (defined (SRSS_BACKUP_S40E_LPECO_PRESENT) && (SRSS_BACKUP_S40E_LPECO_PRESENT == 1u)) */

/* ========================================================================== */
/* ===========================    IHO SECTION    ============================ */
/* ========================================================================== */

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
bool Cy_SysClk_IhoIsEnabled(void)
{
#if (CY_SRSS_IHO_PRESENT)
  #if !defined(CY_IP_MXS22SRSS_VERSION_MINOR) || CY_IP_MXS22SRSS_VERSION_MINOR == (0u)
    return (_FLD2BOOL(SRSS_CLK_IHO_CONFIG_ENABLE, SRSS_CLK_IHO_CONFIG));
  #else
    return true;
  #endif
#else
    return false;
#endif
}

void Cy_SysClk_IhoDisable(void)
{
#if (CY_SRSS_IHO_PRESENT) && (!defined(CY_IP_MXS22SRSS_VERSION_MINOR) || CY_IP_MXS22SRSS_VERSION_MINOR == (0u))
    SRSS_CLK_IHO_CONFIG &= ~SRSS_CLK_IHO_CONFIG_ENABLE_Msk;
#endif
}

void Cy_SysClk_IhoEnable(void)
{
#if (CY_SRSS_IHO_PRESENT) && (!defined(CY_IP_MXS22SRSS_VERSION_MINOR) || CY_IP_MXS22SRSS_VERSION_MINOR == (0u))
    SRSS_CLK_IHO_CONFIG |= SRSS_CLK_IHO_CONFIG_ENABLE_Msk;
#endif
}

#endif /* defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS) */

#if defined (CY_IP_MXS22SRSS)
void Cy_SysClk_IhoDeepsleepEnable(void)
{
#if (CY_SRSS_IHO_PRESENT)
    SRSS_CLK_IHO_CONFIG |= SRSS_CLK_IHO_CONFIG_DPSLP_ENABLE_Msk;
#endif
}

bool Cy_SysClk_IhoIsDeepsleepEnabled(void)
{
#if (CY_SRSS_IHO_PRESENT)
    return (_FLD2BOOL(SRSS_CLK_IHO_CONFIG_DPSLP_ENABLE, SRSS_CLK_IHO_CONFIG));
#else
    return false;
#endif
}

void Cy_SysClk_IhoDeepsleepDisable(void)
{
#if (CY_SRSS_IHO_PRESENT)
    SRSS_CLK_IHO_CONFIG &= ~SRSS_CLK_IHO_CONFIG_DPSLP_ENABLE_Msk;
#endif
}

void Cy_SysClk_IhoSetTrim(uint32_t trimVal)
{
#if (CY_SRSS_IHO_PRESENT)
    CY_REG32_CLR_SET(SRSS_CLK_IHO_CONFIG, SRSS_CLK_IHO_CONFIG_IHO_TRIM_FREQ, trimVal);
#endif
}

uint32_t Cy_SysClk_IhoGetTrim(void)
{
#if (CY_SRSS_IHO_PRESENT)
    return (_FLD2VAL(SRSS_CLK_IHO_CONFIG_IHO_TRIM_FREQ, SRSS_CLK_IHO_CONFIG));
#else
    return 0U;
#endif
}


#endif /* defined (CY_IP_MXS22SRSS) */


/* ========================================================================== */
/* ===========================    IMO SECTION    ============================ */
/* ========================================================================== */
#if defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))

void Cy_SysClk_ImoEnable(void)
{
#if defined (CY_SRSS_IMO_PRESENT) && (CY_SRSS_IMO_PRESENT == 1)
    SRSS_CLK_IMO_CONFIG |= SRSS_CLK_IMO_CONFIG_ENABLE_Msk;
#endif
}

void Cy_SysClk_ImoDisable(void)
{
#if defined (CY_SRSS_IMO_PRESENT) && (CY_SRSS_IMO_PRESENT == 1)
    SRSS_CLK_IMO_CONFIG &= ~SRSS_CLK_IMO_CONFIG_ENABLE_Msk;
#endif
}

bool Cy_SysClk_ImoIsEnabled(void)
{
#if defined (CY_SRSS_IMO_PRESENT) && (CY_SRSS_IMO_PRESENT == 1)
    return (_FLD2BOOL(SRSS_CLK_IMO_CONFIG_ENABLE, SRSS_CLK_IMO_CONFIG));
#else
    return false;
#endif
}
#endif /* defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) */

#if defined (CY_IP_MXS40SSRSS)

void Cy_SysClk_ImoDeepsleepEnable(void)
{
#if (CY_SRSS_IMO_PRESENT)
    SRSS_CLK_IMO_CONFIG |= SRSS_CLK_IMO_CONFIG_DPSLP_ENABLE_Msk;
#endif
}

bool Cy_SysClk_ImoIsDeepsleepEnabled(void)
{
#if (CY_SRSS_IMO_PRESENT)
    return (_FLD2BOOL(SRSS_CLK_IMO_CONFIG_DPSLP_ENABLE, SRSS_CLK_IMO_CONFIG));
#else
    return false;
#endif
}

void Cy_SysClk_ImoDeepsleepDisable(void)
{
#if (CY_SRSS_IMO_PRESENT)
    SRSS_CLK_IMO_CONFIG &= ~SRSS_CLK_IMO_CONFIG_DPSLP_ENABLE_Msk;
#endif
}
#endif /* defined (CY_IP_MXS40SSRSS) */

/* ========================================================================== */
/* ====================    INPUT MULTIPLEXER SECTION    ===================== */
/* ========================================================================== */


cy_en_sysclk_status_t Cy_SysClk_ClkPathSetSource(uint32_t clkPath, cy_en_clkpath_in_sources_t source)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L3(CY_SYSCLK_IS_CLKPATH_SOURCE_VALID(source));

    if (clkPath < CY_SRSS_NUM_CLKPATH)
    {
        if (source >= CY_SYSCLK_CLKPATH_IN_DSI)
        {
            SRSS_CLK_DSI_SELECT[clkPath] = _VAL2FLD(SRSS_CLK_DSI_SELECT_DSI_MUX, (uint32_t)source);
            SRSS_CLK_PATH_SELECT[clkPath] = _VAL2FLD(SRSS_CLK_PATH_SELECT_PATH_MUX, (uint32_t)CY_SYSCLK_CLKPATH_IN_DSIMUX);
        }
        else
        {
            SRSS_CLK_PATH_SELECT[clkPath] = _VAL2FLD(SRSS_CLK_PATH_SELECT_PATH_MUX, (uint32_t)source);
        }
        retVal = CY_SYSCLK_SUCCESS;
    }
    return (retVal);
}

cy_en_clkpath_in_sources_t Cy_SysClk_ClkPathGetSource(uint32_t clkPath)
{
    CY_ASSERT_L1(clkPath < CY_SRSS_NUM_CLKPATH);
    cy_en_clkpath_in_sources_t retVal =
        (cy_en_clkpath_in_sources_t )((uint32_t)_FLD2VAL(SRSS_CLK_PATH_SELECT_PATH_MUX, SRSS_CLK_PATH_SELECT[clkPath]));
    if (retVal == CY_SYSCLK_CLKPATH_IN_DSIMUX)
    {
        retVal = (cy_en_clkpath_in_sources_t)((uint32_t)(((uint32_t)CY_SYSCLK_CLKPATH_IN_DSI) |
                    ((uint32_t)(_FLD2VAL(SRSS_CLK_DSI_SELECT_DSI_MUX, SRSS_CLK_DSI_SELECT[clkPath])))));
    }
    return (retVal);
}

uint32_t Cy_SysClk_ClkPathMuxGetFrequency(uint32_t clkPath)
{
    CY_ASSERT_L1(clkPath < CY_SRSS_NUM_CLKPATH);

    uint32_t freq = 0UL;    /* The path mux output frequency in Hz, 0 = an unknown frequency */

    /* Get the frequency of the source, i.e., the path mux input */
    switch(Cy_SysClk_ClkPathGetSource(clkPath))
    {
        case CY_SYSCLK_CLKPATH_IN_IMO: /* The IMO frequency is fixed at 8 MHz */
            freq = CY_SYSCLK_IMO_FREQ;
            break;

        case CY_SYSCLK_CLKPATH_IN_EXT:
            freq = Cy_SysClk_ExtClkGetFrequency();
            break;

        case CY_SYSCLK_CLKPATH_IN_ECO:
#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) || \
            (defined (CY_IP_MXS40SSRSS) && (SRSS_ECO_PRESENT == 1UL))
            freq = Cy_SysClk_EcoGetFrequency();
#endif
            break;

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3)) && (defined (SRSS_BACKUP_S40E_LPECO_PRESENT) && (SRSS_BACKUP_S40E_LPECO_PRESENT == 1u))
        case CY_SYSCLK_CLKPATH_IN_LPECO:
            freq = Cy_SysClk_LpEcoGetFrequency();
            break;
#endif

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS)
        case CY_SYSCLK_CLKPATH_IN_ALTHF:
            freq = Cy_SysClk_AltHfGetFrequency();
            break;
#endif
#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
        case CY_SYSCLK_CLKPATH_IN_PILO:
            freq = (0UL != (SRSS_CLK_PILO_CONFIG & SRSS_CLK_PILO_CONFIG_PILO_EN_Msk)) ? CY_SYSCLK_PILO_FREQ : 0UL;
            break;
#endif

#if defined (CY_IP_MXS40SSRSS)
        case CY_SYSCLK_CLKPATH_IN_ALTLF:
            freq = Cy_SysClk_AltLfGetFrequency();
            break;
#endif

#if defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)
        case CY_SYSCLK_CLKPATH_IN_IHO:
            freq = (Cy_SysClk_IhoIsEnabled()) ? CY_SYSCLK_IHO_FREQ : 0UL;
            break;
#endif

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
        case CY_SYSCLK_CLKPATH_IN_ILO0:
#else
        case CY_SYSCLK_CLKPATH_IN_ILO:
#endif
            freq = (0UL != (SRSS_CLK_ILO_CONFIG & SRSS_CLK_ILO_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;

        case CY_SYSCLK_CLKPATH_IN_WCO:
            freq = (Cy_SysClk_WcoOkay()) ? CY_SYSCLK_WCO_FREQ : 0UL;
            break;

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))
        case CY_SYSCLK_CLKPATH_IN_ILO1:
            freq = (0UL != (SRSS_CLK_ILO_CONFIG & SRSS_CLK_ILO_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;
#endif

        default:
            /* Don't know the frequency of dsi_out, leave freq = 0UL */
            break;
    }

    return (freq);
}

/*******************************************************************************
* Function Name: Cy_SysClk_ClkPathGetFrequency
****************************************************************************//**
*
* Returns the output frequency of the clock path mux.
*
* \return The output frequency of the path mux.
*
* \note If the return value equals zero, that means either:
* - the selected path mux source signal frequency is unknown (e.g. dsi_out, etc.) or
* - the selected path mux source is not configured/enabled/stable (e.g. ECO, EXTCLK, etc.).
*
* \funcusage
* \snippet sysclk/snippet/main.c snippet_Cy_SysClk_FllEnable
*
*******************************************************************************/
uint32_t Cy_SysClk_ClkPathGetFrequency(uint32_t clkPath)
{
    CY_ASSERT_L1(clkPath < CY_SRSS_NUM_CLKPATH);

    uint32_t freq = Cy_SysClk_ClkPathMuxGetFrequency(clkPath);

#if defined (CY_IP_MXS22SRSS)
#if (CY_SRSS_PLL_PRESENT > 0U)
    if (clkPath < (CY_SRSS_NUM_PLL) && Cy_SysClk_PllIsEnabled(clkPath)) /* PLL? (always path 1...N)*/
    {
        freq = Cy_SysClk_PllGetFrequency(clkPath);
    }
#endif /* CY_SRSS_PLL_PRESENT */
    else
    {
        /* Do nothing with the path mux frequency */
    }
#elif (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
    if (clkPath == (uint32_t)CY_SYSCLK_CLKHF_IN_CLKPATH0 && Cy_SysClk_FllIsEnabled()) /* FLL? (always path 0) */
    {
        freq = Cy_SysClk_FllGetFrequency();
    }
    else if ((clkPath != 0UL) && (clkPath <= (CY_SRSS_NUM_PLL)) && Cy_SysClk_PllIsEnabled(clkPath))
    {
        freq = Cy_SysClk_PllGetFrequency(clkPath);
    }
    else
    {
        /* Do nothing with the path mux frequency */
    }
#else
    if (clkPath == (uint32_t)CY_SYSCLK_CLKHF_IN_CLKPATH0 && Cy_SysClk_FllIsEnabled()) /* FLL? (always path 0) */
    {
        freq = Cy_SysClk_FllGetFrequency();
    }
#if ((CY_SRSS_PLL_PRESENT > 0U) && (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)))
    else if ((clkPath > 0UL) && (clkPath <= CY_SRSS_NUM_PLL) && Cy_SysClk_PllIsEnabled(clkPath)) /* PLL? (always path 1...N)*/
    {
        freq = Cy_SysClk_PllGetFrequency(clkPath);
    }
#endif /* CY_SRSS_PLL_PRESENT */
    else
    {
        /* Do nothing with the path mux frequency */
    }
#endif /* defined (CY_IP_MXS22SRSS) */

    return (freq);
}

/* ========================================================================== */
/* ===========================    FLL SECTION    ============================ */
/* ========================================================================== */
#if defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2))

/* min and max FLL output frequencies, in Hz */
#define  CY_SYSCLK_FLL_MIN_CCO_OUTPUT_FREQ (48000000UL)
#define  CY_SYSCLK_FLL_MIN_OUTPUT_FREQ     (CY_SYSCLK_FLL_MIN_CCO_OUTPUT_FREQ / 2U)

#define  CY_SYSCLK_FLL_IS_CCO_RANGE_VALID(range) (((range) == CY_SYSCLK_FLL_CCO_RANGE0) || \
                                                  ((range) == CY_SYSCLK_FLL_CCO_RANGE1) || \
                                                  ((range) == CY_SYSCLK_FLL_CCO_RANGE2) || \
                                                  ((range) == CY_SYSCLK_FLL_CCO_RANGE3) || \
                                                  ((range) == CY_SYSCLK_FLL_CCO_RANGE4))
/** \cond INTERNAL */
#define  CY_SYSCLK_FLL_INT_COEF (327680000UL)
#define  CY_SYSCLK_FLL_GAIN_IDX (11U)
#define  CY_SYSCLK_FLL_GAIN_VAL (8UL * CY_SYSCLK_FLL_INT_COEF)

#define TRIM_STEPS_SCALE        (100000000ULL) /* 10 ^ 8 */
#define MARGIN_SCALE            (100000ULL) /* 10 ^ 5 */
/** \endcond */

bool Cy_SysClk_FllIsEnabled(void)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    return (_FLD2BOOL(SRSS_CLK_FLL_CONFIG_FLL_ENABLE, SRSS_CLK_FLL_CONFIG));
#else
    return false;
#endif
}


bool Cy_SysClk_FllLocked(void)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    return (_FLD2BOOL(SRSS_CLK_FLL_STATUS_LOCKED, SRSS_CLK_FLL_STATUS));
#else
    return false;
#endif
}

cy_en_sysclk_status_t Cy_SysClk_FllDisable(void)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    uint32_t timeoutus = CY_SYSCLK_FLL_DISABLE_TIMEOUT;
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;


    CY_REG32_CLR_SET(SRSS_CLK_FLL_CONFIG3, SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);

    /* Wait until BYPASS bits are changed with a timeout */
    for (; (((uint32_t)CY_SYSCLK_FLLPLL_OUTPUT_INPUT) != _FLD2VAL(SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, SRSS_CLK_FLL_CONFIG3)) &&
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    retVal = (0UL != timeoutus) ? CY_SYSCLK_SUCCESS : CY_SYSCLK_TIMEOUT;

    if(retVal == CY_SYSCLK_SUCCESS)
    {
        Cy_SysLib_DelayUs((uint16_t)CY_SYSCLK_BYPASS_CONFIGURE_DELAY);

        SRSS_CLK_FLL_CONFIG  &= ~SRSS_CLK_FLL_CONFIG_FLL_ENABLE_Msk;
        SRSS_CLK_FLL_CONFIG4 &= ~SRSS_CLK_FLL_CONFIG4_CCO_ENABLE_Msk;

    }

    return retVal;
#else
    return (CY_SYSCLK_UNSUPPORTED_STATE);
#endif
}

void Cy_SysClk_FllOutputDividerEnable(bool enable)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    SRSS_CLK_FLL_CONFIG = _BOOL2FLD(SRSS_CLK_FLL_CONFIG_FLL_OUTPUT_DIV, enable);
#else
    CY_UNUSED_PARAMETER(enable); /* Suppress a compiler warning about unused variables */
#endif
}


cy_en_sysclk_status_t Cy_SysClk_FllConfigure(uint32_t inputFreq, uint32_t outputFreq, cy_en_fll_pll_output_mode_t outputMode)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    /* check for errors */
    if ((outputFreq < CY_SYSCLK_FLL_MIN_OUTPUT_FREQ) || (CY_SYSCLK_FLL_MAX_OUTPUT_FREQ < outputFreq) || /* invalid output frequency */
      (outputFreq  < ((inputFreq * 11UL) / 10UL ))) /* check output/input frequency ratio */
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }
    else /* no errors */
    {
        /* If output mode is bypass (input routed directly to output), then done.
           The output frequency equals the input frequency regardless of the
           frequency parameters. */
        if (outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
            cy_stc_fll_manual_config_t config;
            uint32_t ccoFreq;
            bool wcoSource = (CY_SYSCLK_CLKPATH_IN_WCO == Cy_SysClk_ClkPathGetSource(0UL/*FLL*/)) ? true : false;

            config.outputMode = outputMode;
            /* 1. Output division by 2 is always required */
            config.enableOutputDiv = true;
            /* 2. Compute the target CCO frequency from the target output frequency and output division */
            ccoFreq = outputFreq * 2UL;
            /* 3. Compute the CCO range value from the CCO frequency */
            config.ccoRange = ((ccoFreq >= 150339200UL) ? CY_SYSCLK_FLL_CCO_RANGE4 :
                               ((ccoFreq >= 113009380UL) ? CY_SYSCLK_FLL_CCO_RANGE3 :
                                ((ccoFreq >=  84948700UL) ? CY_SYSCLK_FLL_CCO_RANGE2 :
                                 ((ccoFreq >=  63855600UL) ? CY_SYSCLK_FLL_CCO_RANGE1 : CY_SYSCLK_FLL_CCO_RANGE0))));

        /* 4. Compute the FLL reference divider value.
              refDiv is a constant if the WCO is the FLL source, otherwise the formula is
              refDiv = ROUNDUP((inputFreq / outputFreq) * 250) */
            config.refDiv = wcoSource ? 19U : (uint16_t)CY_SYSLIB_DIV_ROUNDUP((uint64_t)inputFreq * 250ULL, (uint64_t)outputFreq);

        /* 5. Compute the FLL multiplier value.
              Formula is fllMult = ccoFreq / (inputFreq / refDiv) */
            config.fllMult = (uint32_t)CY_SYSLIB_DIV_ROUNDUP((uint64_t)ccoFreq * (uint64_t)config.refDiv, (uint64_t)inputFreq);
        /* 6. Compute the lock tolerance.
              Formula is lock tolerance = 1.5 * fllMult * (((1 + CCO accuracy) / (1 - source clock accuracy)) - 1)
              We assume CCO accuracy is 0.25%.
              We assume the source clock accuracy = 1%. This is the accuracy of the IMO.
              Therefore the formula is lock tolerance = 1.5 * fllMult * 0.012626 = 0.018939 * fllMult */
            config.lockTolerance = (uint16_t)CY_SYSLIB_DIV_ROUNDUP(config.fllMult * 18939UL, 1000000UL);

            {
                /* constants indexed by ccoRange */
                const uint32_t trimSteps[] = {110340UL, 110200UL, 110000UL, 110000UL, 117062UL}; /* Scaled by 10^8 */
                const uint32_t margin[] = {436UL, 581UL, 772UL, 1030UL, 1320UL}; /* Scaled by 10^5 */
        /* 7. Compute the CCO igain and pgain */
                {
                    /* intermediate parameters */
                    uint32_t kcco = (trimSteps[config.ccoRange] * margin[config.ccoRange]);
                    uint32_t ki_p = (uint32_t)CY_SYSLIB_DIV_ROUND(850ULL * CY_SYSCLK_FLL_INT_COEF * inputFreq, (uint64_t)kcco * (uint64_t)config.refDiv);

                    /* find the largest IGAIN value that is less than or equal to ki_p */
                    uint32_t locigain = CY_SYSCLK_FLL_GAIN_VAL;
                    uint32_t locpgain = CY_SYSCLK_FLL_GAIN_VAL;

                    /* find the largest IGAIN value that is less than or equal to ki_p */
                    for(config.igain = CY_SYSCLK_FLL_GAIN_IDX; config.igain != 0UL; config.igain--)
                    {
                       if(locigain <= ki_p)
                       {
                          break;
                       }
                       locigain >>= 1U;
                    }
                    /* decrement igain if the WCO is the FLL source */
                    if (wcoSource && (config.igain > 0U))
                    {
                        config.igain--;
                        locigain >>= 1U;
                    }

                    /* then find the largest PGAIN value that is less than or equal to ki_p - igain */
                    for(config.pgain = CY_SYSCLK_FLL_GAIN_IDX; config.pgain != 0UL; config.pgain--)
                    {
                      if(locpgain <= (ki_p - locigain))
                      {
                          break;
                      }
                      locpgain >>= 1U;
                    }

                    /* decrement pgain if the WCO is the FLL source */
                    if (wcoSource && (config.pgain > 0U))
                    {
                        config.pgain--;
                    }
                }

        /* 8. Compute the CCO_FREQ bits in CLK_FLL_CONFIG4 register */
                {
                    uint64_t cmp = CY_SYSLIB_DIV_ROUND(((TRIM_STEPS_SCALE / MARGIN_SCALE) * (uint64_t)ccoFreq), (uint64_t)margin[config.ccoRange]);
                    uint64_t mlt = TRIM_STEPS_SCALE + (uint64_t)trimSteps[config.ccoRange];
                    uint64_t res = mlt;

                    config.cco_Freq = 0U;

                    while(res < cmp)
                    {
                        res *= mlt;
                        res /= TRIM_STEPS_SCALE;
                        config.cco_Freq++;
                    }
                }
            }

        /* 9. Compute the settling count, using a 1 usec settling time. Use a constant if the WCO is the FLL source */
            {
                uint64_t fref = CY_SYSLIB_DIV_ROUND(6000ULL * (uint64_t)inputFreq, (uint64_t)config.refDiv);
                uint32_t divval = CY_SYSLIB_DIV_ROUNDUP(inputFreq, 1000000UL);
                uint32_t altval = (uint32_t)CY_SYSLIB_DIV_ROUNDUP((uint64_t)divval * fref, 6000000ULL) + 1UL;

                config.settlingCount = wcoSource ? 200U : (uint16_t)
                          ((outputFreq < fref) ? divval :
                            ((divval > altval) ? divval : altval));
            }
        /* Configure FLL based on calculated values */
            retVal = Cy_SysClk_FllManualConfigure(&config);
        }
        else /* if not, bypass output mode */
        {
            CY_REG32_CLR_SET(SRSS_CLK_FLL_CONFIG3, SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
        }
    }

    return (retVal);
#else
    CY_UNUSED_PARAMETER(inputFreq); /* Suppress a compiler warning about unused variables */
    CY_UNUSED_PARAMETER(outputFreq); /* Suppress a compiler warning about unused variables */
    CY_UNUSED_PARAMETER(outputMode); /* Suppress a compiler warning about unused variables */
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_FllManualConfigure(const cy_stc_fll_manual_config_t *config)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    cy_en_sysclk_status_t retVal = CY_SYSCLK_INVALID_STATE;

    /* Check for errors */
    CY_ASSERT_L1(config != NULL);

    if (!Cy_SysClk_FllIsEnabled()) /* If disabled */
    {
        /* update CLK_FLL_CONFIG register with 2 parameters; FLL_ENABLE is already 0 */
        /* asserts just check for bitfield overflow */
        CY_ASSERT_L1(config->fllMult <= (SRSS_CLK_FLL_CONFIG_FLL_MULT_Msk >> SRSS_CLK_FLL_CONFIG_FLL_MULT_Pos));

        SRSS_CLK_FLL_CONFIG = _VAL2FLD(SRSS_CLK_FLL_CONFIG_FLL_MULT, config->fllMult) |
                             _BOOL2FLD(SRSS_CLK_FLL_CONFIG_FLL_OUTPUT_DIV, config->enableOutputDiv);

        /* update CLK_FLL_CONFIG2 register with 2 parameters */
        /* asserts just check for bitfield overflow */
        CY_ASSERT_L1(config->refDiv <= (SRSS_CLK_FLL_CONFIG2_FLL_REF_DIV_Msk >> SRSS_CLK_FLL_CONFIG2_FLL_REF_DIV_Pos));
        CY_ASSERT_L1(config->lockTolerance <= (SRSS_CLK_FLL_CONFIG2_LOCK_TOL_Msk >> SRSS_CLK_FLL_CONFIG2_LOCK_TOL_Pos));

        SRSS_CLK_FLL_CONFIG2 = _VAL2FLD(SRSS_CLK_FLL_CONFIG2_FLL_REF_DIV, config->refDiv) |
                               _VAL2FLD(SRSS_CLK_FLL_CONFIG2_LOCK_TOL, config->lockTolerance);

        /* update CLK_FLL_CONFIG3 register with 4 parameters */
        /* asserts just check for bitfield overflow */
        CY_ASSERT_L1(config->igain <= (SRSS_CLK_FLL_CONFIG3_FLL_LF_IGAIN_Msk >> SRSS_CLK_FLL_CONFIG3_FLL_LF_IGAIN_Pos));
        CY_ASSERT_L1(config->pgain <= (SRSS_CLK_FLL_CONFIG3_FLL_LF_PGAIN_Msk >> SRSS_CLK_FLL_CONFIG3_FLL_LF_PGAIN_Pos));
        CY_ASSERT_L1(config->settlingCount <= (SRSS_CLK_FLL_CONFIG3_SETTLING_COUNT_Msk >> SRSS_CLK_FLL_CONFIG3_SETTLING_COUNT_Pos));

        SRSS_CLK_FLL_CONFIG3 = _VAL2FLD(SRSS_CLK_FLL_CONFIG3_FLL_LF_IGAIN, config->igain) |
                               _VAL2FLD(SRSS_CLK_FLL_CONFIG3_FLL_LF_PGAIN, config->pgain) |
                               _VAL2FLD(SRSS_CLK_FLL_CONFIG3_SETTLING_COUNT, config->settlingCount) |
                               _VAL2FLD(SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, config->outputMode);

        /* update CLK_FLL_CONFIG4 register with 1 parameter; preserve other bits */
        /* asserts just check for bitfield overflow */
        CY_ASSERT_L1(CY_SYSCLK_FLL_IS_CCO_RANGE_VALID(config->ccoRange));
        CY_ASSERT_L1(config->cco_Freq <= (SRSS_CLK_FLL_CONFIG4_CCO_FREQ_Msk >> SRSS_CLK_FLL_CONFIG4_CCO_FREQ_Pos));

        CY_REG32_CLR_SET(SRSS_CLK_FLL_CONFIG4, SRSS_CLK_FLL_CONFIG4_CCO_RANGE, (uint32_t)(config->ccoRange));
        CY_REG32_CLR_SET(SRSS_CLK_FLL_CONFIG4, SRSS_CLK_FLL_CONFIG4_CCO_FREQ, (uint32_t)(config->cco_Freq));

        retVal = CY_SYSCLK_SUCCESS;
    }

    return (retVal);
#else
    CY_UNUSED_PARAMETER(config); /* Suppress a compiler warning about unused variables */
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


void Cy_SysClk_FllGetConfiguration(cy_stc_fll_manual_config_t *config)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    CY_ASSERT_L1(config != NULL);
    /* read 2 parameters from CLK_FLL_CONFIG register */
    uint32_t tempReg = SRSS_CLK_FLL_CONFIG;
    config->fllMult         = _FLD2VAL(SRSS_CLK_FLL_CONFIG_FLL_MULT, tempReg);
    config->enableOutputDiv = _FLD2BOOL(SRSS_CLK_FLL_CONFIG_FLL_OUTPUT_DIV, tempReg);
    /* read 2 parameters from CLK_FLL_CONFIG2 register */
    tempReg = SRSS_CLK_FLL_CONFIG2;
    config->refDiv          = (uint16_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG2_FLL_REF_DIV, tempReg);
    config->lockTolerance   = (uint16_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG2_LOCK_TOL, tempReg);
    /* read 4 parameters from CLK_FLL_CONFIG3 register */
    tempReg = SRSS_CLK_FLL_CONFIG3;
    config->igain           = (uint8_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG3_FLL_LF_IGAIN, tempReg);
    config->pgain           = (uint8_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG3_FLL_LF_PGAIN, tempReg);
    config->settlingCount   = (uint16_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG3_SETTLING_COUNT, tempReg);
    config->outputMode      = (cy_en_fll_pll_output_mode_t)((uint32_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, tempReg));
    /* read 2 parameters from CLK_FLL_CONFIG4 register */
    tempReg = SRSS_CLK_FLL_CONFIG4;
    config->ccoRange        = (cy_en_fll_cco_ranges_t)((uint32_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG4_CCO_RANGE, tempReg));
    config->cco_Freq        = (uint16_t)_FLD2VAL(SRSS_CLK_FLL_CONFIG4_CCO_FREQ, tempReg);
#else
    CY_UNUSED_PARAMETER(config); /* Suppress a compiler warning about unused variables */
#endif
}

#if defined (__ARMCC_VERSION)
cy_en_sysclk_status_t __attribute__((optnone)) Cy_SysClk_FllEnable(uint32_t timeoutus)
#elif defined(__GNUC__)
cy_en_sysclk_status_t __attribute__((optimize("Og"))) Cy_SysClk_FllEnable(uint32_t timeoutus)
#else
cy_en_sysclk_status_t Cy_SysClk_FllEnable(uint32_t timeoutus)
#endif /* defined (__ARMCC_VERSION) */
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))
    bool zeroTimeout = (0UL == timeoutus);

    /* first set the CCO enable bit */
    SRSS_CLK_FLL_CONFIG4 |= SRSS_CLK_FLL_CONFIG4_CCO_ENABLE_Msk;

    /* Wait until CCO is ready */
    for (; (!_FLD2BOOL(SRSS_CLK_FLL_STATUS_CCO_READY, SRSS_CLK_FLL_STATUS)) && /* if cco_ready == 0 */
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    /* Set the FLL bypass mode to FLL_REF */
    CY_REG32_CLR_SET(SRSS_CLK_FLL_CONFIG3, SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);

    /* Set the FLL enable bit, if CCO is ready */
    if (zeroTimeout || (0UL != timeoutus))
    {
        SRSS_CLK_FLL_CONFIG |= SRSS_CLK_FLL_CONFIG_FLL_ENABLE_Msk;
    }

    /* now do the timeout wait for FLL_STATUS, bit LOCKED */
    for (; (!Cy_SysClk_FllLocked()) && /* if locked == 0 */
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    if (zeroTimeout || (0UL != timeoutus))
    {
        /* Set the FLL bypass mode to FLL_OUT (ignoring lock indicator) */
        CY_REG32_CLR_SET(SRSS_CLK_FLL_CONFIG3, SRSS_CLK_FLL_CONFIG3_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT);
    }
    else
    {
        /* If lock doesn't occur, FLL is stopped */
        (void)Cy_SysClk_FllDisable();
    }

    return ((zeroTimeout || (0UL != timeoutus)) ? CY_SYSCLK_SUCCESS : CY_SYSCLK_TIMEOUT);
#else
    CY_UNUSED_PARAMETER(timeoutus); /* Suppress a compiler warning about unused variables */
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

uint32_t Cy_SysClk_FllGetFrequency(void)
{
#if ((defined CY_SRSS_FLL_PRESENT) && (CY_SRSS_FLL_PRESENT == 1U))

    uint32_t fDiv ;    /* FLL multiplier/feedback divider */
    uint32_t rDiv;    /* FLL reference divider */
    uint32_t oDiv;    /* FLL output divider */
    bool  enabled;    /* FLL enable status; n/a for direct */
    uint32_t freq = 0UL;    /* FLL Frequency */

    cy_stc_fll_manual_config_t fllCfg = {0UL,0U,CY_SYSCLK_FLL_CCO_RANGE0,false,0U,0U,0U,0U,CY_SYSCLK_FLLPLL_OUTPUT_AUTO,0U};
    Cy_SysClk_FllGetConfiguration(&fllCfg);
    enabled = (Cy_SysClk_FllIsEnabled()) && (CY_SYSCLK_FLLPLL_OUTPUT_INPUT != fllCfg.outputMode);
    fDiv = fllCfg.fllMult;
    rDiv = fllCfg.refDiv;
    oDiv = (fllCfg.enableOutputDiv) ? 2UL : 1UL;

    if (enabled && /* If FLL is enabled and not bypassed */
        (0UL != rDiv)) /* to avoid division by zero */
    {
        freq = Cy_SysClk_ClkPathMuxGetFrequency(0UL); /* FLL mapped always to path 0 */
        freq = (uint32_t)CY_SYSLIB_DIV_ROUND(((uint64_t)freq * (uint64_t)fDiv),
                                             ((uint64_t)rDiv * (uint64_t)oDiv));
    }

    return (freq);
#else
    return 0U;
#endif
}
#endif /* defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) */
/* ========================================================================== */
/* ===========================    PLL SECTION    ============================ */
/* ========================================================================== */

/* PLL200M */
/* PLL OUTPUT_DIV bitfield allowable range */
#define CY_SYSCLK_PLL_MIN_OUTPUT_DIV   (2UL)
#define CY_SYSCLK_PLL_MAX_OUTPUT_DIV   (16UL)

/* PLL REFERENCE_DIV bitfield allowable range */
#define CY_SYSCLK_PLL_MIN_REF_DIV      (1UL)
#define CY_SYSCLK_PLL_MAX_REF_DIV      (18UL)

/* PLL FEEDBACK_DIV bitfield allowable ranges, LF and normal modes */
#define CY_SYSCLK_PLL_MIN_FB_DIV_LF    (19UL)
#define CY_SYSCLK_PLL_MAX_FB_DIV_LF    (56UL)
#define CY_SYSCLK_PLL_MIN_FB_DIV_NORM  (22UL)
#define CY_SYSCLK_PLL_MAX_FB_DIV_NORM  (112UL)

/* PLL FEEDBACK_DIV bitfield allowable range selection */
#define CY_SYSCLK_PLL_MIN_FB_DIV       ((config->lfMode) ? CY_SYSCLK_PLL_MIN_FB_DIV_LF : CY_SYSCLK_PLL_MIN_FB_DIV_NORM)
#define CY_SYSCLK_PLL_MAX_FB_DIV       ((config->lfMode) ? CY_SYSCLK_PLL_MAX_FB_DIV_LF : CY_SYSCLK_PLL_MAX_FB_DIV_NORM)

/* PLL Fvco range allowable ranges, LF and normal modes */
#define CY_SYSCLK_PLL_MIN_FVCO_LF      (170000000UL)
#define CY_SYSCLK_PLL_MAX_FVCO_LF      (200000000UL)
#define CY_SYSCLK_PLL_MIN_FVCO_NORM    (200000000UL)
#define CY_SYSCLK_PLL_MAX_FVCO_NORM    (400000000UL)
/* PLL Fvco range selection */
#define CY_SYSCLK_PLL_MIN_FVCO         ((config->lfMode) ? CY_SYSCLK_PLL_MIN_FVCO_LF : CY_SYSCLK_PLL_MIN_FVCO_NORM)
#define CY_SYSCLK_PLL_MAX_FVCO         ((config->lfMode) ? CY_SYSCLK_PLL_MAX_FVCO_LF : CY_SYSCLK_PLL_MAX_FVCO_NORM)

/* PLL input and output frequency limits */
#define CY_SYSCLK_PLL_MIN_IN_FREQ  (4000000UL)
#define CY_SYSCLK_PLL_MAX_IN_FREQ  (64000000UL)
#define CY_SYSCLK_PLL_MIN_OUT_FREQ (CY_SYSCLK_PLL_MIN_FVCO / CY_SYSCLK_PLL_MAX_OUTPUT_DIV)
#if defined (CY_DEVICE_SERIES_CYT2B6)
#define CY_SYSCLK_PLL_MAX_OUT_FREQ (80000000UL)
#elif defined (CY_DEVICE_TVIIBE)
#define CY_SYSCLK_PLL_MAX_OUT_FREQ (160000000UL)
#else
#define CY_SYSCLK_PLL_MAX_OUT_FREQ (200000000UL)
#endif

/* PLL400M */

/* Only include PLL400M macros for devices that contain PLL400M IP. */
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)
/* PLL OUTPUT_DIV bitfield allowable range */
#define CY_SYSCLK_PLL400M_MIN_OUTPUT_DIV   (2UL)
#define CY_SYSCLK_PLL400M_MAX_OUTPUT_DIV   (16UL)

/* PLL REFERENCE_DIV bitfield allowable range */
#define CY_SYSCLK_PLL400M_MIN_REF_DIV      (1UL)
#define CY_SYSCLK_PLL400M_MAX_REF_DIV      (16UL)

/* PLL FEEDBACK_DIV bitfield allowable range selection */
#define CY_SYSCLK_PLL400M_MIN_FB_DIV       (16UL)
#define CY_SYSCLK_PLL400M_MAX_FB_DIV       (200UL)

/* PLL Fvco range selection */
#define CY_SYSCLK_PLL400M_MIN_FVCO         (400000000UL)
#define CY_SYSCLK_PLL400M_MAX_FVCO         (800000000UL)

/* PLL input and output frequency limits */
#define CY_SYSCLK_PLL400M_MIN_IN_FREQ  (4000000UL)
#define CY_SYSCLK_PLL400M_MAX_IN_FREQ  (64000000UL)
#define CY_SYSCLK_PLL400M_MIN_OUT_FREQ (25000000UL)
#define CY_SYSCLK_PLL400M_MAX_OUT_FREQ (400000000UL)
#endif



/* DPLL-LP */

/* DPLL-LP OUTPUT_DIV bitfield allowable range */
#define CY_SYSCLK_DPLL_LP_MIN_OUTPUT_DIV   (1UL)
#define CY_SYSCLK_DPLL_LP_MAX_OUTPUT_DIV   (16UL)

/* DPLL-LP REFERENCE_DIV bitfield allowable range */
#define CY_SYSCLK_DPLL_LP_MIN_REF_DIV      (1UL)
#define CY_SYSCLK_DPLL_LP_MAX_REF_DIV      (16UL)

/* DPLL-LP FEEDBACK_DIV bitfield allowable range selection */
#define CY_SYSCLK_DPLL_LP_MIN_FB_DIV       (16UL)
#define CY_SYSCLK_DPLL_LP_MAX_FB_DIV       (200UL)

/* DPLL-LP Fdco range selection */
#define CY_SYSCLK_DPLL_LP_MIN_FDCO         (160000000UL)
#define CY_SYSCLK_DPLL_LP_MAX_FDCO         (480000000UL)
#define CY_SYSCLK_DPLL_LP_DCO_MODE_LIMIT   (310000000UL)

/* DPLL-LP pdf range selection */
#define CY_SYSCLK_DPLL_LP_MIN_PDF         (4000000UL)
#define CY_SYSCLK_DPLL_LP_MAX_PDF         (8000000UL)

/* DPLL-LP input and output frequency limits */
#define CY_SYSCLK_DPLL_LP_MIN_IN_FREQ  (4000000UL)
#define CY_SYSCLK_DPLL_LP_MAX_IN_FREQ  (64000000UL)
#define CY_SYSCLK_DPLL_LP_MIN_OUT_FREQ (10000000UL)
#define CY_SYSCLK_DPLL_LP_MAX_OUT_FREQ (400000000UL)

/* DPLL-LP default config values */
#if defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (0u)
#define CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE  (0xFUL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT    (0xAUL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_FRACT  (0xBUL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_SSCG   (0x7UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT    (0x8UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_FRACT  (0x9UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_SSCG   (0x7UL)
#elif defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (1u)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DEPTH         (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_RATE          (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN     (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_MODE          (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_EN            (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE           (0x0FUL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_PLL_TG             (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT             (0x28UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT             (0x20UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_ACC_INT         (0x27UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_ACC_INT         (0x23UL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KI_FRAC            (0x2CUL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KP_FRAC            (0x24UL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KI_ACC_FRAC        (0x27UL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KP_ACC_FRAC        (0x1CUL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KI_SSCG            (0x1CUL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KP_SSCG            (0x1CUL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KI_ACC_SSCG        (0x27UL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KP_ACC_SSCG        (0x23UL)
#else
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DEPTH         (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_RATE          (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN     (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_MODE          (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_EN            (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE           (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_ACC_MODE           (0x01UL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_TDC_MODE           (0x01UL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_PLL_TG             (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG4_ACC_CNT_LOCK       (0x00UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT             (0x24UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT             (0x1CUL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KI_ACC_INT         (0x23UL)
#define CY_SYSCLK_DPLL_LP_CONFIG5_KP_ACC_INT         (0x1AUL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KI_FRAC            (0x24UL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KP_FRAC            (0x20UL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KI_ACC_FRAC        (0x23UL)
#define CY_SYSCLK_DPLL_LP_CONFIG6_KP_ACC_FRAC        (0x1AUL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KI_SSCG            (0x18UL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KP_SSCG            (0x18UL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KI_ACC_SSCG        (0x16UL)
#define CY_SYSCLK_DPLL_LP_CONFIG7_KP_ACC_SSCG        (0x14UL)
#endif
/* DPLL-HP */

/* DPLL-HP NDIV bitfield allowable range */
#define CY_SYSCLK_DPLL_HP_MIN_NDIV   (8UL)
#define CY_SYSCLK_DPLL_HP_MAX_NDIV   (250UL)

/* DPLL-HP PDIV bitfield allowable range */
#define CY_SYSCLK_DPLL_HP_MIN_PDIV   (1UL)
#define CY_SYSCLK_DPLL_HP_MAX_PDIV   (8UL)

/* DPLL-HP KDIV bitfield allowable range */
#define CY_SYSCLK_DPLL_HP_MIN_KDIV   (2UL)
#define CY_SYSCLK_DPLL_HP_MAX_KDIV   (8UL)
/* DPLL-HP Fdco range selection */
#define CY_SYSCLK_DPLL_HP_MIN_FDCO         (400000UL)
#define CY_SYSCLK_DPLL_HP_MAX_FDCO         (1000000UL)

/* DPLL-HP pdf range selection */
#define CY_SYSCLK_DPLL_HP_MIN_PDF         (17000UL)
#define CY_SYSCLK_DPLL_HP_MAX_PDF         (50000UL)

/* DPLL-HP input and output frequency limits */
#define CY_SYSCLK_DPLL_HP_MIN_IN_FREQ  (4000000UL)
#define CY_SYSCLK_DPLL_HP_MAX_IN_FREQ  (50000000UL)
#define CY_SYSCLK_DPLL_HP_MIN_OUT_FREQ (50000000UL)
#define CY_SYSCLK_DPLL_HP_MAX_OUT_FREQ (400000000UL)

/* DPLL-HP default config values */
#define CY_SYSCLK_DPLL_HP_CONFIG2_FREQ_MODE_SEL_CODE  (CY_SYSCLK_DPLL_HP_CLK50MHZ_1US_CNT_VAL)
#define CY_SYSCLK_DPLL_HP_CONFIG2_IVR_TRIM            (0x8U)
#define CY_SYSCLK_DPLL_HP_CONFIG3_CLKR_SEL            (true)

#define CY_SYSCLK_DPLL_HP_CONFIG4_LF_LC_ALPHA         (0xCU)
#define CY_SYSCLK_DPLL_HP_CONFIG4_LF_LC_BETA          (0x5U)

#define CY_SYSCLK_DPLL_HP_CONFIG4_FLOCK_EN_TH3        (0x3U)
#define CY_SYSCLK_DPLL_HP_CONFIG4_FLOCK_EN_TH7        (0x7U)

#define CY_SYSCLK_DPLL_HP_CONFIG4_FLOCK_WAITPER       (0x6U)
#define CY_SYSCLK_DPLL_HP_CONFIG4_LK_TH               (0x7U)
#define CY_SYSCLK_DPLL_HP_CONFIG4_LK_WAITPER          (0x8U)

#define CY_SYSCLK_DPLL_HP_CONFIG5_LF_ALPHA            (0x14U)
#define CY_SYSCLK_DPLL_HP_CONFIG5_LF_BETA             (0x14U)
#define CY_SYSCLK_DPLL_HP_CONFIG5_LF_SET_PARAMS       (true)

#define CY_SYSCLK_DPLL_HP_DUTY_CAL_CTL_DC_EN          (true)


#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined(CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2))

/* Only include PLL400M functions for devices that contain PLL400M IP. */
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)
bool Cy_SysClk_Pll400MIsEnabled(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)
    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);
    return (_FLD2BOOL(CLK_PLL400M_CONFIG_ENABLE, SRSS_CLK_PLL_400M_CONFIG(pllNum)));
#else
    return false;
#endif
}


bool Cy_SysClk_Pll400MLocked(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)
    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);
    return (_FLD2BOOL(CLK_PLL400M_STATUS_LOCKED, SRSS_CLK_PLL_400M_STATUS(pllNum)));
#else
     return false;
#endif
}


bool Cy_SysClk_Pll400MLostLock(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)
    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    bool retVal = _FLD2BOOL(CLK_PLL400M_STATUS_UNLOCK_OCCURRED, SRSS_CLK_PLL_400M_STATUS(pllNum));
    /* write a 1 to clear the unlock occurred bit */
    SRSS_CLK_PLL_400M_STATUS(pllNum) = CLK_PLL400M_STATUS_UNLOCK_OCCURRED_Msk;
    return (retVal);
#else
    return false;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_Pll400MDisable(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    /* First bypass PLL */
    CY_REG32_CLR_SET(SRSS_CLK_PLL_400M_CONFIG(pllNum), CLK_PLL400M_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
    /* Wait at least 6 PLL clock cycles */
    Cy_SysLib_DelayUs(1U);
    /* And now disable the PLL itself */
    SRSS_CLK_PLL_400M_CONFIG(pllNum) &= ~CLK_PLL400M_CONFIG_ENABLE_Msk;
    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_Pll400MConfigure(uint32_t pllNum, const cy_stc_pll_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    if (((config->inputFreq)  < CY_SYSCLK_PLL400M_MIN_IN_FREQ)  || (CY_SYSCLK_PLL400M_MAX_IN_FREQ  < (config->inputFreq)) ||
        ((config->outputFreq) < CY_SYSCLK_PLL400M_MIN_OUT_FREQ) || (CY_SYSCLK_PLL400M_MAX_OUT_FREQ < (config->outputFreq)))
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }
    else
    {
        cy_stc_pll_manual_config_t manualConfig = {0U,0U,0U,false,CY_SYSCLK_FLLPLL_OUTPUT_AUTO, 0, false, false, 0 , 0 , false};

        /* If output mode is not bypass (input routed directly to output), then
           calculate new parameters. */
        if (config->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
            /* for each possible value of OUTPUT_DIV and REFERENCE_DIV (Q), try
               to find a value for FEEDBACK_DIV (P) that gives an output frequency
               as close as possible to the desired output frequency. */
            uint32_t p, q, out;
            uint32_t foutBest = 0UL; /* to ensure at least one pass through the for loops below */

            /* REFERENCE_DIV (Q) selection */
            for (q = CY_SYSCLK_PLL400M_MIN_REF_DIV; q <= CY_SYSCLK_PLL400M_MAX_REF_DIV; q++)
            {
                /* FEEDBACK_DIV (P) selection */
                for (p = CY_SYSCLK_PLL400M_MIN_FB_DIV; p <= CY_SYSCLK_PLL400M_MAX_FB_DIV; p++)
                {
                    /* Calculate the intermediate Fvco, and make sure that it's in range */
                    uint32_t fvco = (uint32_t)(((uint64_t)(config->inputFreq) * (uint64_t)p) / (uint64_t)q);
                    if ((CY_SYSCLK_PLL400M_MIN_FVCO <= fvco) && (fvco <= CY_SYSCLK_PLL400M_MAX_FVCO))
                    {
                        /* OUTPUT_DIV selection */
                        for (out = CY_SYSCLK_PLL400M_MIN_OUTPUT_DIV; out <= CY_SYSCLK_PLL400M_MAX_OUTPUT_DIV; out++)
                        {
                            uint64_t tempVco = ((uint64_t)config->outputFreq) * ((uint64_t)out);
                            uint64_t tempFeedBackDivLeftShifted = ((tempVco << (uint64_t)SRSS_PLL400M_FRAC_BIT_COUNT) * (uint64_t)q) / (uint64_t)config->inputFreq;
                            volatile uint32_t feedBackFracDiv  = (uint32_t)(tempFeedBackDivLeftShifted & ((1ULL << (uint64_t)SRSS_PLL400M_FRAC_BIT_COUNT) - 1ULL));
                            /* Calculate what output frequency will actually be produced.
                               If it's closer to the target than what we have so far, then save it. */
                            uint32_t fout = (uint32_t)((((uint64_t)config->inputFreq * (((uint64_t)p << SRSS_PLL400M_FRAC_BIT_COUNT) + (uint64_t)feedBackFracDiv)) / ((uint64_t)q * (uint64_t)out)) >> SRSS_PLL400M_FRAC_BIT_COUNT);

                            if ((uint32_t)abs((int32_t)fout - (int32_t)(config->outputFreq)) <
                                (uint32_t)abs((int32_t)foutBest - (int32_t)(config->outputFreq)))
                            {
                                if (foutBest == (config->outputFreq))
                                {
                                   break;
                                }

                                foutBest = fout;
                                manualConfig.feedbackDiv  = (uint8_t)p;
                                manualConfig.referenceDiv = (uint8_t)q;
                                manualConfig.outputDiv    = (uint8_t)out;
                                manualConfig.fracEn       = (feedBackFracDiv != 0UL);
                                manualConfig.fracDiv      = feedBackFracDiv;
                            }
                        }
                    }
                }
            }
            /* exit loops if foutBest equals outputFreq */

        } /* if not, bypass output mode */

        /* If output mode is bypass (input routed directly to output), then
           use old parameters. */
        else
        {
            (void)Cy_SysClk_Pll400MGetConfiguration(pllNum, &manualConfig);
        }
        /* configure PLL based on calculated values */

        manualConfig.outputMode = config->outputMode;
        retVal = Cy_SysClk_Pll400MManualConfigure(pllNum, &manualConfig);

    } /* if no error */

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_Pll400MManualConfigure(uint32_t pllNum, const cy_stc_pll_manual_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    if (Cy_SysClk_Pll400MIsEnabled(pllNum))
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }
    /* valid divider bitfield values */
    else if ((config->outputDiv    < CY_SYSCLK_PLL400M_MIN_OUTPUT_DIV) || (CY_SYSCLK_PLL400M_MAX_OUTPUT_DIV < config->outputDiv)    ||
             (config->referenceDiv < CY_SYSCLK_PLL400M_MIN_REF_DIV)    || (CY_SYSCLK_PLL400M_MAX_REF_DIV    < config->referenceDiv) ||
             (config->feedbackDiv  < CY_SYSCLK_PLL400M_MIN_FB_DIV)     || (CY_SYSCLK_PLL400M_MAX_FB_DIV     < config->feedbackDiv))
    {
         retVal = CY_SYSCLK_BAD_PARAM;
    }
    else /* no errors */
    {
        /* If output mode is bypass (input routed directly to output), then done.
           The output frequency equals the input frequency regardless of the frequency parameters. */
        if (config->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
                SRSS_CLK_PLL_400M_CONFIG(pllNum) =
                _VAL2FLD(CLK_PLL400M_CONFIG_FEEDBACK_DIV,  config->feedbackDiv)  |
                _VAL2FLD(CLK_PLL400M_CONFIG_REFERENCE_DIV, config->referenceDiv) |
                _VAL2FLD(CLK_PLL400M_CONFIG_OUTPUT_DIV,    config->outputDiv);

                SRSS_CLK_PLL_400M_CONFIG2(pllNum) =
                _VAL2FLD(CLK_PLL400M_CONFIG2_FRAC_DIV, config->fracDiv)  |
                _VAL2FLD(CLK_PLL400M_CONFIG2_FRAC_DITHER_EN, config->fracDitherEn) |
                _VAL2FLD(CLK_PLL400M_CONFIG2_FRAC_EN, config->fracEn);

                SRSS_CLK_PLL_400M_CONFIG3(pllNum) =
                _VAL2FLD(CLK_PLL400M_CONFIG3_SSCG_DEPTH, config->sscgDepth)  |
                _VAL2FLD(CLK_PLL400M_CONFIG3_SSCG_RATE, config->sscgRate) |
                _VAL2FLD(CLK_PLL400M_CONFIG3_SSCG_EN, config->sscgEn);

        }

        CY_REG32_CLR_SET(SRSS_CLK_PLL_400M_CONFIG(pllNum), CLK_PLL400M_CONFIG_BYPASS_SEL, (uint32_t)config->outputMode);
    }

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_Pll400MGetConfiguration(uint32_t pllNum, cy_stc_pll_manual_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    /* Initialize config structure to 0 */
    *config = (cy_stc_pll_manual_config_t){0};

    uint32_t tempReg = SRSS_CLK_PLL_400M_CONFIG(pllNum);
    config->feedbackDiv  = (uint8_t)_FLD2VAL(CLK_PLL400M_CONFIG_FEEDBACK_DIV,  tempReg);
    config->referenceDiv = (uint8_t)_FLD2VAL(CLK_PLL400M_CONFIG_REFERENCE_DIV, tempReg);
    config->outputDiv    = (uint8_t)_FLD2VAL(CLK_PLL400M_CONFIG_OUTPUT_DIV,    tempReg);
    config->outputMode   = (cy_en_fll_pll_output_mode_t)((uint32_t)_FLD2VAL(CLK_PLL400M_CONFIG_BYPASS_SEL, tempReg));

    tempReg = SRSS_CLK_PLL_400M_CONFIG2(pllNum);
    config->fracDiv      = _FLD2VAL(CLK_PLL400M_CONFIG2_FRAC_DIV,  tempReg);
    config->fracDitherEn = (bool)_FLD2VAL(CLK_PLL400M_CONFIG2_FRAC_DITHER_EN, tempReg);
    config->fracEn       = (bool)_FLD2VAL(CLK_PLL400M_CONFIG2_FRAC_EN,    tempReg);

    tempReg = SRSS_CLK_PLL_400M_CONFIG3(pllNum);
    config->sscgDepth  = (uint8_t)_FLD2VAL(CLK_PLL400M_CONFIG3_SSCG_DEPTH,  tempReg);
    config->sscgRate   = (uint8_t)_FLD2VAL(CLK_PLL400M_CONFIG3_SSCG_RATE, tempReg);
    config->sscgEn     = (bool)_FLD2VAL(CLK_PLL400M_CONFIG3_SSCG_EN,    tempReg);

    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

cy_en_sysclk_status_t Cy_SysClk_Pll400MEnable(uint32_t pllNum, uint32_t timeoutus)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(timeoutus);
#if defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    bool zeroTimeout = (timeoutus == 0UL);

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    /* first set the PLL enable bit */
    SRSS_CLK_PLL_400M_CONFIG(pllNum) |= CLK_PLL400M_CONFIG_ENABLE_Msk;

    /* now do the timeout wait for PLL_STATUS, bit LOCKED */
    for (; (0UL == (CLK_PLL400M_STATUS_LOCKED_Msk & SRSS_CLK_PLL_400M_STATUS(pllNum))) &&
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    if (zeroTimeout || (0UL != timeoutus))
    {
        /* Unbypass PLL, if it is not in AUTO mode */
        if ((uint32_t)CY_SYSCLK_FLLPLL_OUTPUT_INPUT == (uint32_t)_FLD2VAL(CLK_PLL400M_CONFIG_BYPASS_SEL, SRSS_CLK_PLL_400M_CONFIG(pllNum)))
        {
            CY_REG32_CLR_SET(SRSS_CLK_PLL_400M_CONFIG(pllNum), CLK_PLL400M_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT);
        }

        retVal = CY_SYSCLK_SUCCESS;
    }
    else
    {
        /* If lock doesn't occur, then bypass PLL */
        CY_REG32_CLR_SET(SRSS_CLK_PLL_400M_CONFIG(pllNum), CLK_PLL400M_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
        /* Wait at least 6 PLL clock cycles */
        Cy_SysLib_DelayUs(1U);
        /* And now disable the PLL itself */
        SRSS_CLK_PLL_400M_CONFIG(pllNum) &= ~CLK_PLL400M_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_TIMEOUT;
    }

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

uint32_t Cy_SysClk_Pll400MGetFrequency(uint32_t pllNum)
{
    uint32_t fDiv;    /* PLL multiplier/feedback divider */
    uint32_t rDiv;    /* PLL reference divider */
    uint32_t oDiv;    /* PLL output divider */
    uint32_t fracDiv; /* PLL Fractional divider */
    bool  enabled;    /* PLL enable status; n/a for direct */
    uint32_t freq=0UL;    /* PLL Frequency */


    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL400M);

    cy_stc_pll_manual_config_t pllcfg = {0U,0U,0U,false,CY_SYSCLK_FLLPLL_OUTPUT_AUTO, 0, false, false, 0 , 0 , false};
    (void)Cy_SysClk_Pll400MGetConfiguration(pllNum, &pllcfg);
    enabled = (Cy_SysClk_Pll400MIsEnabled(pllNum)) && (CY_SYSCLK_FLLPLL_OUTPUT_INPUT != pllcfg.outputMode);
    fDiv    = pllcfg.feedbackDiv;
    rDiv    = pllcfg.referenceDiv;
    oDiv    = pllcfg.outputDiv;
    fracDiv = pllcfg.fracDiv;

    if (enabled && /* If PLL is enabled and not bypassed */
    (0UL != rDiv) && (0UL != oDiv)) /* to avoid division by zero */
    {
        freq = Cy_SysClk_ClkPathMuxGetFrequency(pllNum + 1UL);
        freq = (uint32_t)((((uint64_t)freq * (((uint64_t)fDiv << SRSS_PLL400M_FRAC_BIT_COUNT) + (uint64_t)fracDiv)) / ((uint64_t)rDiv * (uint64_t)oDiv)) >> SRSS_PLL400M_FRAC_BIT_COUNT);
    }

    return (freq);
}

#endif  /* defined (CY_SRSS_PLL400M_PRESENT) && (CY_SRSS_PLL400M_PRESENT == 1u) */

/* PLL200M */

bool Cy_SysClk_Pll200MIsEnabled(uint32_t pllNum)
{
    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    return (_FLD2BOOL(SRSS_CLK_PLL_CONFIG_ENABLE, SRSS_CLK_PLL_CONFIG[pllNum]));
}

bool Cy_SysClk_Pll200MLocked(uint32_t pllNum)
{
    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    return (_FLD2BOOL(SRSS_CLK_PLL_STATUS_LOCKED, SRSS_CLK_PLL_STATUS[pllNum]));
}

bool Cy_SysClk_Pll200MLostLock(uint32_t pllNum)
{
    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    bool retVal = _FLD2BOOL(SRSS_CLK_PLL_STATUS_UNLOCK_OCCURRED, SRSS_CLK_PLL_STATUS[pllNum]);
    /* write a 1 to clear the unlock occurred bit */
    SRSS_CLK_PLL_STATUS[pllNum] = SRSS_CLK_PLL_STATUS_UNLOCK_OCCURRED_Msk;
    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_Pll200MDisable(uint32_t pllNum)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    /* First bypass PLL */
    CY_REG32_CLR_SET(SRSS_CLK_PLL_CONFIG[pllNum], SRSS_CLK_PLL_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
    /* Wait at least 6 PLL clock cycles */
    Cy_SysLib_DelayUs(1U);
    /* And now disable the PLL itself */
    SRSS_CLK_PLL_CONFIG[pllNum] &= ~SRSS_CLK_PLL_CONFIG_ENABLE_Msk;
    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_Pll200MConfigure(uint32_t pllNum, const cy_stc_pll_config_t *config)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    if (((config->inputFreq)  < CY_SYSCLK_PLL_MIN_IN_FREQ)  || (CY_SYSCLK_PLL_MAX_IN_FREQ  < (config->inputFreq)) ||
        ((config->outputFreq) < CY_SYSCLK_PLL_MIN_OUT_FREQ) || (CY_SYSCLK_PLL_MAX_OUT_FREQ < (config->outputFreq)))
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }
    else
    {
        cy_stc_pll_manual_config_t manualConfig;

        /* If output mode is not bypass (input routed directly to output), then
           calculate new parameters. */
        if (config->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
            /* for each possible value of OUTPUT_DIV and REFERENCE_DIV (Q), try
               to find a value for FEEDBACK_DIV (P) that gives an output frequency
               as close as possible to the desired output frequency. */
            uint32_t p, q, out;
            uint32_t foutBest = 0UL; /* to ensure at least one pass through the for loops below */

            /* REFERENCE_DIV (Q) selection */
            for (q = CY_SYSCLK_PLL_MIN_REF_DIV; q <= CY_SYSCLK_PLL_MAX_REF_DIV; q++)
            {
                /* FEEDBACK_DIV (P) selection */
                for (p = CY_SYSCLK_PLL_MIN_FB_DIV; p <= CY_SYSCLK_PLL_MAX_FB_DIV; p++)
                {
                    /* Calculate the intermediate Fvco, and make sure that it's in range */
                    uint32_t fvco = (uint32_t)(((uint64_t)(config->inputFreq) * (uint64_t)p) / (uint64_t)q);
                    if ((CY_SYSCLK_PLL_MIN_FVCO <= fvco) && (fvco <= CY_SYSCLK_PLL_MAX_FVCO))
                    {
                        /* OUTPUT_DIV selection */
                        for (out = CY_SYSCLK_PLL_MIN_OUTPUT_DIV; out <= CY_SYSCLK_PLL_MAX_OUTPUT_DIV; out++)
                        {
                            /* Calculate what output frequency will actually be produced.
                               If it's closer to the target than what we have so far, then save it. */
                            uint32_t fout = ((p * config->inputFreq) / q) / out;
                            if ((uint32_t)abs((int32_t)fout - (int32_t)(config->outputFreq)) <
                                (uint32_t)abs((int32_t)foutBest - (int32_t)(config->outputFreq)))
                            {
                                if (foutBest == (config->outputFreq))
                                {
                                   break;
                                }

                                foutBest = fout;
                                manualConfig.feedbackDiv  = (uint8_t)p;
                                manualConfig.referenceDiv = (uint8_t)q;
                                manualConfig.outputDiv    = (uint8_t)out;
                            }
                        }
                    }
                }
            }
            /* exit loops if foutBest equals outputFreq */

            manualConfig.lfMode = config->lfMode;
        } /* if not, bypass output mode */

        /* If output mode is bypass (input routed directly to output), then
           use old parameters. */
        else
        {
            (void)Cy_SysClk_Pll200MGetConfiguration(pllNum, &manualConfig);
        }
        /* configure PLL based on calculated values */

        manualConfig.outputMode = config->outputMode;
        retVal = Cy_SysClk_Pll200MManualConfigure(pllNum, &manualConfig);

    } /* if no error */

    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_Pll200MManualConfigure(uint32_t pllNum, const cy_stc_pll_manual_config_t *config)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    if (Cy_SysClk_Pll200MIsEnabled(pllNum))
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }
    /* valid divider bitfield values */
    else if ((config->outputDiv    < CY_SYSCLK_PLL_MIN_OUTPUT_DIV) || (CY_SYSCLK_PLL_MAX_OUTPUT_DIV < config->outputDiv)    ||
             (config->referenceDiv < CY_SYSCLK_PLL_MIN_REF_DIV)    || (CY_SYSCLK_PLL_MAX_REF_DIV    < config->referenceDiv) ||
             (config->feedbackDiv  < CY_SYSCLK_PLL_MIN_FB_DIV)     || (CY_SYSCLK_PLL_MAX_FB_DIV     < config->feedbackDiv))
    {
         retVal = CY_SYSCLK_BAD_PARAM;
    }
    else /* no errors */
    {
        /* If output mode is bypass (input routed directly to output), then done.
           The output frequency equals the input frequency regardless of the frequency parameters. */
        if (config->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
            SRSS_CLK_PLL_CONFIG[pllNum] =
                _VAL2FLD(SRSS_CLK_PLL_CONFIG_FEEDBACK_DIV,  config->feedbackDiv)  |
                _VAL2FLD(SRSS_CLK_PLL_CONFIG_REFERENCE_DIV, config->referenceDiv) |
                _VAL2FLD(SRSS_CLK_PLL_CONFIG_OUTPUT_DIV,    config->outputDiv)    |
                _VAL2FLD(SRSS_CLK_PLL_CONFIG_PLL_LF_MODE,   config->lfMode);
        }

        CY_REG32_CLR_SET(SRSS_CLK_PLL_CONFIG[pllNum], SRSS_CLK_PLL_CONFIG_BYPASS_SEL, (uint32_t)config->outputMode);
    }

    return (retVal);
}


cy_en_sysclk_status_t Cy_SysClk_Pll200MGetConfiguration(uint32_t pllNum, cy_stc_pll_manual_config_t *config)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    /* Initialize config structure to 0 */
    *config = (cy_stc_pll_manual_config_t){0};

    uint32_t tempReg = SRSS_CLK_PLL_CONFIG[pllNum];
    config->feedbackDiv  = (uint8_t)_FLD2VAL(SRSS_CLK_PLL_CONFIG_FEEDBACK_DIV,  tempReg);
    config->referenceDiv = (uint8_t)_FLD2VAL(SRSS_CLK_PLL_CONFIG_REFERENCE_DIV, tempReg);
    config->outputDiv    = (uint8_t)_FLD2VAL(SRSS_CLK_PLL_CONFIG_OUTPUT_DIV,    tempReg);
    config->lfMode       =         _FLD2BOOL(SRSS_CLK_PLL_CONFIG_PLL_LF_MODE,   tempReg);
    config->outputMode   = (cy_en_fll_pll_output_mode_t)((uint32_t)_FLD2VAL(SRSS_CLK_PLL_CONFIG_BYPASS_SEL, tempReg));
    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
}

cy_en_sysclk_status_t Cy_SysClk_Pll200MEnable(uint32_t pllNum, uint32_t timeoutus)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    bool zeroTimeout = (timeoutus == 0UL);

    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    /* first set the PLL enable bit */
    SRSS_CLK_PLL_CONFIG[pllNum] |= SRSS_CLK_PLL_CONFIG_ENABLE_Msk;

    /* now do the timeout wait for PLL_STATUS, bit LOCKED */
    for (; (0UL == (SRSS_CLK_PLL_STATUS_LOCKED_Msk & SRSS_CLK_PLL_STATUS[pllNum])) &&
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    if (zeroTimeout || (0UL != timeoutus))
    {
        /* Unbypass PLL, if it is not in AUTO mode */
        if ((uint32_t)CY_SYSCLK_FLLPLL_OUTPUT_INPUT == (uint32_t)_FLD2VAL(SRSS_CLK_PLL_CONFIG_BYPASS_SEL, SRSS_CLK_PLL_CONFIG[pllNum]))
        {
            CY_REG32_CLR_SET(SRSS_CLK_PLL_CONFIG[pllNum], SRSS_CLK_PLL_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT);
        }

        retVal = CY_SYSCLK_SUCCESS;
    }
    else
    {
        /* If lock doesn't occur, then bypass PLL */
        CY_REG32_CLR_SET(SRSS_CLK_PLL_CONFIG[pllNum], SRSS_CLK_PLL_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
        /* Wait at least 6 PLL clock cycles */
        Cy_SysLib_DelayUs(1U);
        /* And now disable the PLL itself */
        SRSS_CLK_PLL_CONFIG[pllNum] &= ~SRSS_CLK_PLL_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_TIMEOUT;
    }

    return (retVal);
}


uint32_t Cy_SysClk_Pll200MGetFrequency(uint32_t pllNum)
{
    uint32_t fDiv;    /* PLL multiplier/feedback divider */
    uint32_t rDiv;    /* PLL reference divider */
    uint32_t oDiv;    /* PLL output divider */
    bool  enabled;    /* PLL enable status; n/a for direct */
    uint32_t freq=0UL;    /* PLL Frequency */


    CY_ASSERT_L1(pllNum < CY_SRSS_NUM_PLL200M);

    cy_stc_pll_manual_config_t pllcfg = {0U,0U,0U,false,CY_SYSCLK_FLLPLL_OUTPUT_AUTO, 0, false, false, 0 , 0 , false};
    (void)Cy_SysClk_Pll200MGetConfiguration(pllNum, &pllcfg);
    enabled = (Cy_SysClk_Pll200MIsEnabled(pllNum)) && (CY_SYSCLK_FLLPLL_OUTPUT_INPUT != pllcfg.outputMode);
    fDiv = pllcfg.feedbackDiv;
    rDiv = pllcfg.referenceDiv;
    oDiv = pllcfg.outputDiv;

    if (enabled && /* If PLL is enabled and not bypassed */
    (0UL != rDiv) && (0UL != oDiv)) /* to avoid division by zero */
    {
        freq = Cy_SysClk_ClkPathMuxGetFrequency((pllNum + 1UL) + CY_SRSS_NUM_PLL400M);

        freq = (uint32_t)CY_SYSLIB_DIV_ROUND(((uint64_t)freq * (uint64_t)fDiv),
                                             ((uint64_t)rDiv * (uint64_t)oDiv));
    }

    return (freq);
}

#endif

#if defined (CY_IP_MXS22SRSS) || (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
/* DPLL-LP */
bool Cy_SysClk_DpllLpIsEnabled(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_LP_PRESENT != 0U )
    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);
    return (_FLD2BOOL(CLK_DPLL_LP_CONFIG_ENABLE, SRSS_CLK_DPLL_LP_CONFIG(pllNum)));
#else
    return false;
#endif
}


bool Cy_SysClk_DpllLpLocked(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_LP_PRESENT != 0U )
    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);
    return (_FLD2BOOL(CLK_DPLL_LP_STATUS_LOCKED, SRSS_CLK_DPLL_LP_STATUS(pllNum)));
#else
     return false;
#endif
}


bool Cy_SysClk_DpllLpLostLock(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_LP_PRESENT != 0U )
    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    bool retVal = _FLD2BOOL(CLK_DPLL_LP_STATUS_UNLOCK_OCCURRED, SRSS_CLK_DPLL_LP_STATUS(pllNum));
    /* write a 1 to clear the unlock occurred bit */
    SRSS_CLK_DPLL_LP_STATUS(pllNum) = CLK_DPLL_LP_STATUS_UNLOCK_OCCURRED_Msk;
    return (retVal);
#else
    return false;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllLpDisable(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_LP_PRESENT != 0U )

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    /* First bypass PLL */
    CY_REG32_CLR_SET(SRSS_CLK_DPLL_LP_CONFIG(pllNum), CLK_DPLL_LP_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
    /* Wait at least 6 PLL clock cycles */
    Cy_SysLib_DelayUs(1U);
    /* And now disable the PLL itself */
    SRSS_CLK_DPLL_LP_CONFIG(pllNum) &= ~CLK_DPLL_LP_CONFIG_ENABLE_Msk;
    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllLpConfigure(uint32_t pllNum, const cy_stc_pll_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if (CY_SRSS_DPLL_LP_PRESENT != 0U )

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    if (((config->inputFreq)  < CY_SYSCLK_DPLL_LP_MIN_IN_FREQ)  || (CY_SYSCLK_DPLL_LP_MAX_IN_FREQ  < (config->inputFreq)) ||
        ((config->outputFreq) < CY_SYSCLK_DPLL_LP_MIN_OUT_FREQ) || (CY_SYSCLK_DPLL_LP_MAX_OUT_FREQ < (config->outputFreq)))
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }
    else
    {
        cy_stc_dpll_lp_config_t    manualDpllLpConfig = (cy_stc_dpll_lp_config_t){0};
#if defined (CY_IP_MXS22SRSS)
        cy_stc_pll_manual_config_t manualConfig = {&manualDpllLpConfig, NULL};
#else
        cy_stc_pll_manual_config_t manualConfig = {&manualDpllLpConfig};
#endif
        /* If output mode is not bypass (input routed directly to output), then
           calculate new parameters. */
        if (config->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
            /* for each possible value of OUTPUT_DIV and REFERENCE_DIV (Q), try
               to find a value for FEEDBACK_DIV (P) that gives an output frequency
               as close as possible to the desired output frequency. */
            uint32_t p, q, out;
            uint32_t foutBest = 0UL; /* to ensure at least one pass through the for loops below */

        #if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
            /* Modify automatic DPLL settings to generate 2x target clock internally and use 2x
               output divider to provide a 50/50 duty cycle clock. */
            uint32_t outputFrequency = config->outputFreq * 2UL;
        #else
            uint32_t outputFrequency = config->outputFreq;
        #endif /* (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) */

            /* REFERENCE_DIV (Q) selection */
            for (q = CY_SYSCLK_DPLL_LP_MIN_REF_DIV; q <= CY_SYSCLK_DPLL_LP_MAX_REF_DIV; q++)
            {
                /* FEEDBACK_DIV (P) selection */
                for (p = CY_SYSCLK_DPLL_LP_MIN_FB_DIV; p <= CY_SYSCLK_DPLL_LP_MAX_FB_DIV; p++)
                {
                    /* Calculate the intermediate FDCO,PDF and make sure that it's in range */
                    uint32_t pdf = (uint32_t)((uint64_t)(config->inputFreq) / (uint64_t)q);
                    uint32_t fdco = (uint32_t)((uint64_t)(pdf) * (uint64_t)p);

                    if (((CY_SYSCLK_DPLL_LP_MIN_FDCO <= fdco) && (fdco <= CY_SYSCLK_DPLL_LP_MAX_FDCO)) && ((CY_SYSCLK_DPLL_LP_MIN_PDF <= pdf) && (pdf <= CY_SYSCLK_DPLL_LP_MAX_PDF)))
                    {
                        /* OUTPUT_DIV selection */
                        for (out = CY_SYSCLK_DPLL_LP_MIN_OUTPUT_DIV; out <= CY_SYSCLK_DPLL_LP_MAX_OUTPUT_DIV; out++)
                        {
                            uint64_t tempVco = ((uint64_t)outputFrequency) * ((uint64_t)out);
                            uint64_t tempFeedBackDivLeftShifted = ((tempVco << (uint64_t)SRSS_DPLL_LP_FRAC_BIT_COUNT) * (uint64_t)q) / (uint64_t)config->inputFreq;
                            volatile uint32_t feedBackFracDiv  = (uint32_t)(tempFeedBackDivLeftShifted & ((1ULL << (uint64_t)SRSS_DPLL_LP_FRAC_BIT_COUNT) - 1ULL));
                            /* Calculate what output frequency will actually be produced.
                               If it's closer to the target than what we have so far, then save it. */
                            uint32_t fout = (uint32_t)((((uint64_t)config->inputFreq * (((uint64_t)p << SRSS_DPLL_LP_FRAC_BIT_COUNT) + (uint64_t)feedBackFracDiv)) / ((uint64_t)q * (uint64_t)out)) >> SRSS_DPLL_LP_FRAC_BIT_COUNT);

                            if ((uint32_t)abs((int32_t)fout - (int32_t)(outputFrequency)) <
                                (uint32_t)abs((int32_t)foutBest - (int32_t)(outputFrequency)))
                            {
                                if (foutBest == (outputFrequency))
                                {
                                   break;
                                }

                                foutBest = fout;
                                manualConfig.lpPllCfg->feedbackDiv  = (uint8_t)p;
                                manualConfig.lpPllCfg->referenceDiv = (uint8_t)q;

                            #if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))
                                /* Modify automatic DPLL settings to generate 2x target clock internally and use 2x
                                output divider to provide a 50/50 duty cycle clock. */
                                manualConfig.lpPllCfg->outputDiv    = (uint8_t)(out * 2UL);
                            #else
                                manualConfig.lpPllCfg->outputDiv    = (uint8_t)(out);
                            #endif /* (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL)) */
                                manualConfig.lpPllCfg->fracEn       = true;
                                manualConfig.lpPllCfg->fracDiv      = feedBackFracDiv;
                                manualConfig.lpPllCfg->pllDcoMode   = (fdco >= CY_SYSCLK_DPLL_LP_DCO_MODE_LIMIT) ? true : false;
                            }
                        }
                    }
                }
            }
            /* exit loops if foutBest equals outputFreq */

        } /* if not, bypass output mode */

        /* If output mode is bypass (input routed directly to output), then
           use old parameters. */
        else
        {
            (void)Cy_SysClk_DpllLpGetConfiguration(pllNum, &manualConfig);
        }
        /* configure PLL based on calculated values */

        manualConfig.lpPllCfg->outputMode = config->outputMode;
        /* Set the default parameters to remaining PLL configurations */
        #if defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (0u)
        manualConfig.lpPllCfg->dcoCode = CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE;
        manualConfig.lpPllCfg->kiInt   = CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT;
        manualConfig.lpPllCfg->kiFrac  = CY_SYSCLK_DPLL_LP_CONFIG5_KI_FRACT;
        manualConfig.lpPllCfg->kiSscg  = CY_SYSCLK_DPLL_LP_CONFIG5_KI_SSCG;
        manualConfig.lpPllCfg->kpInt   = CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT;
        manualConfig.lpPllCfg->kpFrac  = CY_SYSCLK_DPLL_LP_CONFIG5_KP_FRACT;
        manualConfig.lpPllCfg->kpSscg  = CY_SYSCLK_DPLL_LP_CONFIG5_KP_SSCG;
        #elif defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (1u)
        manualConfig.lpPllCfg->sscgDepth    = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DEPTH;
        manualConfig.lpPllCfg->sscgRate     = (uint8_t)CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_RATE;
        manualConfig.lpPllCfg->sscgDitherEn = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN;
        manualConfig.lpPllCfg->sscgMode     = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_MODE;
        manualConfig.lpPllCfg->sscgEn       = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_EN;
        manualConfig.lpPllCfg->dcoCode      = CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE;
        manualConfig.lpPllCfg->pllTg        = CY_SYSCLK_DPLL_LP_CONFIG4_PLL_TG;
        manualConfig.lpPllCfg->kiInt        = CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT;
        manualConfig.lpPllCfg->kpInt        = CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT;
        manualConfig.lpPllCfg->kiAccInt     = CY_SYSCLK_DPLL_LP_CONFIG5_KI_ACC_INT;
        manualConfig.lpPllCfg->kpAccInt     = CY_SYSCLK_DPLL_LP_CONFIG5_KP_ACC_INT;
        manualConfig.lpPllCfg->kiFrac       = CY_SYSCLK_DPLL_LP_CONFIG6_KI_FRAC;
        manualConfig.lpPllCfg->kpFrac       = CY_SYSCLK_DPLL_LP_CONFIG6_KP_FRAC;
        manualConfig.lpPllCfg->kiAccFrac    = CY_SYSCLK_DPLL_LP_CONFIG6_KI_ACC_FRAC;
        manualConfig.lpPllCfg->kpAccFrac    = CY_SYSCLK_DPLL_LP_CONFIG6_KP_ACC_FRAC;
        manualConfig.lpPllCfg->kiSscg       = CY_SYSCLK_DPLL_LP_CONFIG7_KI_SSCG;
        manualConfig.lpPllCfg->kpSscg       = CY_SYSCLK_DPLL_LP_CONFIG7_KP_SSCG;
        manualConfig.lpPllCfg->kiAccSscg    = CY_SYSCLK_DPLL_LP_CONFIG7_KI_ACC_SSCG;
        manualConfig.lpPllCfg->kpAccSscg    = CY_SYSCLK_DPLL_LP_CONFIG7_KP_ACC_SSCG;
        #else
        manualConfig.lpPllCfg->sscgDepth    = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DEPTH;
        manualConfig.lpPllCfg->sscgRate     = (uint8_t)CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_RATE;
        manualConfig.lpPllCfg->sscgDitherEn = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN;
        manualConfig.lpPllCfg->sscgMode     = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_MODE;
        manualConfig.lpPllCfg->sscgEn       = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_EN;
        manualConfig.lpPllCfg->dcoCode      = CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE;
        manualConfig.lpPllCfg->accMode      = CY_SYSCLK_DPLL_LP_CONFIG4_ACC_MODE;
        manualConfig.lpPllCfg->tdcMode      = CY_SYSCLK_DPLL_LP_CONFIG4_TDC_MODE;
        manualConfig.lpPllCfg->pllTg        = CY_SYSCLK_DPLL_LP_CONFIG4_PLL_TG;
        manualConfig.lpPllCfg->accCntLock   = CY_SYSCLK_DPLL_LP_CONFIG4_ACC_CNT_LOCK;
        manualConfig.lpPllCfg->kiInt        = CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT;
        manualConfig.lpPllCfg->kpInt        = CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT;
        manualConfig.lpPllCfg->kiAccInt     = CY_SYSCLK_DPLL_LP_CONFIG5_KI_ACC_INT;
        manualConfig.lpPllCfg->kpAccInt     = CY_SYSCLK_DPLL_LP_CONFIG5_KP_ACC_INT;
        manualConfig.lpPllCfg->kiFrac       = CY_SYSCLK_DPLL_LP_CONFIG6_KI_FRAC;
        manualConfig.lpPllCfg->kpFrac       = CY_SYSCLK_DPLL_LP_CONFIG6_KP_FRAC;
        manualConfig.lpPllCfg->kiAccFrac    = CY_SYSCLK_DPLL_LP_CONFIG6_KI_ACC_FRAC;
        manualConfig.lpPllCfg->kpAccFrac    = CY_SYSCLK_DPLL_LP_CONFIG6_KP_ACC_FRAC;
        manualConfig.lpPllCfg->kiSscg       = CY_SYSCLK_DPLL_LP_CONFIG7_KI_SSCG;
        manualConfig.lpPllCfg->kpSscg       = CY_SYSCLK_DPLL_LP_CONFIG7_KP_SSCG;
        manualConfig.lpPllCfg->kiAccSscg    = CY_SYSCLK_DPLL_LP_CONFIG7_KI_ACC_SSCG;
        manualConfig.lpPllCfg->kpAccSscg    = CY_SYSCLK_DPLL_LP_CONFIG7_KP_ACC_SSCG;
        #endif

        retVal = Cy_SysClk_DpllLpManualConfigure(pllNum, &manualConfig);

    } /* if no error */

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllLpManualConfigure(uint32_t pllNum, const cy_stc_pll_manual_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

    #if defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (1u)
    /* Overwrite with default values as personality generated config structure not updated */
    config->lpPllCfg->sscgDepth    = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DEPTH;
    config->lpPllCfg->sscgRate     = (uint8_t)CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_RATE;
    config->lpPllCfg->sscgDitherEn = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN;
    config->lpPllCfg->sscgMode     = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_MODE;
    config->lpPllCfg->sscgEn       = CY_SYSCLK_DPLL_LP_CONFIG3_SSCG_EN;
    config->lpPllCfg->dcoCode      = CY_SYSCLK_DPLL_LP_CONFIG4_DCO_CODE;
    config->lpPllCfg->pllTg        = CY_SYSCLK_DPLL_LP_CONFIG4_PLL_TG;
    config->lpPllCfg->kiInt        = CY_SYSCLK_DPLL_LP_CONFIG5_KI_INT;
    config->lpPllCfg->kpInt        = CY_SYSCLK_DPLL_LP_CONFIG5_KP_INT;
    config->lpPllCfg->kiAccInt     = CY_SYSCLK_DPLL_LP_CONFIG5_KI_ACC_INT;
    config->lpPllCfg->kpAccInt     = CY_SYSCLK_DPLL_LP_CONFIG5_KP_ACC_INT;
    config->lpPllCfg->kiFrac       = CY_SYSCLK_DPLL_LP_CONFIG6_KI_FRAC;
    config->lpPllCfg->kpFrac       = CY_SYSCLK_DPLL_LP_CONFIG6_KP_FRAC;
    config->lpPllCfg->kiAccFrac    = CY_SYSCLK_DPLL_LP_CONFIG6_KI_ACC_FRAC;
    config->lpPllCfg->kpAccFrac    = CY_SYSCLK_DPLL_LP_CONFIG6_KP_ACC_FRAC;
    config->lpPllCfg->kiSscg       = CY_SYSCLK_DPLL_LP_CONFIG7_KI_SSCG;
    config->lpPllCfg->kpSscg       = CY_SYSCLK_DPLL_LP_CONFIG7_KP_SSCG;
    config->lpPllCfg->kiAccSscg    = CY_SYSCLK_DPLL_LP_CONFIG7_KI_ACC_SSCG;
    config->lpPllCfg->kpAccSscg    = CY_SYSCLK_DPLL_LP_CONFIG7_KP_ACC_SSCG;
    #endif

#if (CY_SRSS_DPLL_LP_PRESENT != 0U )

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    if (Cy_SysClk_DpllLpIsEnabled(pllNum))
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }
    /* valid divider bitfield values */
    else if ((config->lpPllCfg->outputDiv    < CY_SYSCLK_DPLL_LP_MIN_OUTPUT_DIV) || (CY_SYSCLK_DPLL_LP_MAX_OUTPUT_DIV < config->lpPllCfg->outputDiv)    ||
             (config->lpPllCfg->referenceDiv < CY_SYSCLK_DPLL_LP_MIN_REF_DIV)    || (CY_SYSCLK_DPLL_LP_MAX_REF_DIV    < config->lpPllCfg->referenceDiv) ||
             (config->lpPllCfg->feedbackDiv  < CY_SYSCLK_DPLL_LP_MIN_FB_DIV)     || (CY_SYSCLK_DPLL_LP_MAX_FB_DIV     < config->lpPllCfg->feedbackDiv))
    {
         retVal = CY_SYSCLK_BAD_PARAM;
    }
    else /* no errors */
    {
        /* If output mode is bypass (input routed directly to output), then done.
           The output frequency equals the input frequency regardless of the frequency parameters. */
        if (config->lpPllCfg->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
                SRSS_CLK_DPLL_LP_CONFIG(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG_FEEDBACK_DIV,  config->lpPllCfg->feedbackDiv)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG_REFERENCE_DIV, config->lpPllCfg->referenceDiv) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG_OUTPUT_DIV,    config->lpPllCfg->outputDiv)    |
        #if defined (CY_IP_MXS22SRSS)
                _VAL2FLD(CLK_DPLL_LP_CONFIG_PLL_DCO_MODE,    config->lpPllCfg->pllDcoMode);
        #else
                _VAL2FLD(CLK_DPLL_LP_CONFIG_PLL_DCO_CODE_MULT,    config->lpPllCfg->pllDcoMode);
        #endif

                SRSS_CLK_DPLL_LP_CONFIG2(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG2_FRAC_DIV, config->lpPllCfg->fracDiv)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG2_FRAC_DITHER_EN, config->lpPllCfg->fracDitherEn) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG2_FRAC_EN, config->lpPllCfg->fracEn);

                SRSS_CLK_DPLL_LP_CONFIG3(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG3_SSCG_DEPTH, config->lpPllCfg->sscgDepth)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG3_SSCG_RATE, config->lpPllCfg->sscgRate) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN, config->lpPllCfg->sscgDitherEn) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG3_SSCG_MODE, config->lpPllCfg->sscgMode) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG3_SSCG_EN, config->lpPllCfg->sscgEn);
         #if defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (0u)
                SRSS_CLK_DPLL_LP_CONFIG4(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_DCO_CODE, config->lpPllCfg->dcoCode)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_PLL_CS_PB2_DIS, config->lpPllCfg->disableBias) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_DCO_SD_EN, config->lpPllCfg->enableDcoSd);

                SRSS_CLK_DPLL_LP_CONFIG5(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_INT, config->lpPllCfg->kiInt)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_FRACT, config->lpPllCfg->kiFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_SSCG, config->lpPllCfg->kiSscg)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_INT, config->lpPllCfg->kpInt)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_FRACT, config->lpPllCfg->kpFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_SSCG, config->lpPllCfg->kpSscg);
         #elif defined (CY_IP_MXS22SRSS) && CY_IP_MXS22SRSS_VERSION_MINOR == (1u)
                SRSS_CLK_DPLL_LP_CONFIG4(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_DCO_CODE, config->lpPllCfg->dcoCode)  |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_PLL_CS_PB2_DIS, config->lpPllCfg->disableBias) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_PLL_TG, config->lpPllCfg->pllTg);

                SRSS_CLK_DPLL_LP_CONFIG5(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_INT, config->lpPllCfg->kiInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_INT, config->lpPllCfg->kpInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_ACC_INT, config->lpPllCfg->kiAccInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_ACC_INT, config->lpPllCfg->kpAccInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_PWRUP_ACC_INT, config->lpPllCfg->pwrupAccInt);

                 SRSS_CLK_DPLL_LP_CONFIG6(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KI_FRACT, config->lpPllCfg->kiFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KP_FRACT, config->lpPllCfg->kpFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KI_ACC_FRACT, config->lpPllCfg->kiAccFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KP_ACC_FRACT, config->lpPllCfg->kpAccFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_PWRUP_ACC_FRACT, config->lpPllCfg->pwrupAccFrac);

                 SRSS_CLK_DPLL_LP_CONFIG7(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KI_SSCG, config->lpPllCfg->kiSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KP_SSCG, config->lpPllCfg->kpSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KI_ACC_SSCG, config->lpPllCfg->kiAccSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KP_ACC_SSCG, config->lpPllCfg->kpAccSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_PWRUP_ACC_SSCG, config->lpPllCfg->pwrupAccSscg);

         #else
                 SRSS_CLK_DPLL_LP_CONFIG4(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_DCO_CODE, config->lpPllCfg->dcoCode) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_ACC_MODE, config->lpPllCfg->accMode) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_TDC_MODE, config->lpPllCfg->tdcMode) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_PLL_TG, config->lpPllCfg->pllTg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG4_ACC_CNT_LOCK, config->lpPllCfg->accCntLock);

                 SRSS_CLK_DPLL_LP_CONFIG5(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_INT, config->lpPllCfg->kiInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_INT, config->lpPllCfg->kpInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KI_ACC_INT, config->lpPllCfg->kiAccInt) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG5_KP_ACC_INT, config->lpPllCfg->kpAccInt);

                 SRSS_CLK_DPLL_LP_CONFIG6(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KI_FRACT, config->lpPllCfg->kiFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KP_FRACT, config->lpPllCfg->kpFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KI_ACC_FRACT, config->lpPllCfg->kiAccFrac) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG6_KP_ACC_FRACT, config->lpPllCfg->kpAccFrac);

                 SRSS_CLK_DPLL_LP_CONFIG7(pllNum) =
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KI_SSCG, config->lpPllCfg->kiSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KP_SSCG, config->lpPllCfg->kpSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KI_ACC_SSCG, config->lpPllCfg->kiAccSscg) |
                _VAL2FLD(CLK_DPLL_LP_CONFIG7_KP_ACC_SSCG, config->lpPllCfg->kpAccSscg);
         #endif
        }

        CY_REG32_CLR_SET(SRSS_CLK_DPLL_LP_CONFIG(pllNum), CLK_DPLL_LP_CONFIG_BYPASS_SEL, (uint32_t)config->lpPllCfg->outputMode);
    }

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllLpGetConfiguration(uint32_t pllNum, cy_stc_pll_manual_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if (CY_SRSS_DPLL_LP_PRESENT != 0U )

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    /* Initialize config structure to 0 */
    *(config->lpPllCfg) = (cy_stc_dpll_lp_config_t){0};

    uint32_t tempReg = SRSS_CLK_DPLL_LP_CONFIG(pllNum);
    config->lpPllCfg->feedbackDiv  = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG_FEEDBACK_DIV,  tempReg);
    config->lpPllCfg->referenceDiv = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG_REFERENCE_DIV, tempReg);
    config->lpPllCfg->outputDiv    = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG_OUTPUT_DIV,    tempReg);
#if defined (CY_IP_MXS22SRSS)
    config->lpPllCfg->pllDcoMode   = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG_PLL_DCO_MODE,tempReg);
#else
    config->lpPllCfg->pllDcoMode   = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG_PLL_DCO_CODE_MULT,tempReg);
#endif
    config->lpPllCfg->outputMode   = (cy_en_fll_pll_output_mode_t)((uint32_t)_FLD2VAL(CLK_DPLL_LP_CONFIG_BYPASS_SEL, tempReg));

    tempReg = SRSS_CLK_DPLL_LP_CONFIG2(pllNum);
    config->lpPllCfg->fracDiv      = _FLD2VAL(CLK_DPLL_LP_CONFIG2_FRAC_DIV,  tempReg);
    config->lpPllCfg->fracDitherEn = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG2_FRAC_DITHER_EN, tempReg);
    config->lpPllCfg->fracEn       = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG2_FRAC_EN,    tempReg);

    tempReg = SRSS_CLK_DPLL_LP_CONFIG3(pllNum);
    config->lpPllCfg->sscgDepth  = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG3_SSCG_DEPTH,  tempReg);
    config->lpPllCfg->sscgRate   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG3_SSCG_RATE, tempReg);
    config->lpPllCfg->sscgDitherEn   = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG3_SSCG_DITHER_EN, tempReg);
    config->lpPllCfg->sscgMode   = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG3_SSCG_MODE, tempReg);
    config->lpPllCfg->sscgEn     = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG3_SSCG_EN,    tempReg);

#if (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))

    tempReg = SRSS_CLK_DPLL_LP_CONFIG4(pllNum);
    config->lpPllCfg->dcoCode  = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG4_DCO_CODE,  tempReg);
    config->lpPllCfg->accMode   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG4_ACC_MODE, tempReg);
    config->lpPllCfg->tdcMode   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG4_TDC_MODE, tempReg);
    config->lpPllCfg->pllTg   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG4_PLL_TG, tempReg);
    config->lpPllCfg->accCntLock     = (bool)_FLD2VAL(CLK_DPLL_LP_CONFIG4_ACC_CNT_LOCK, tempReg);

    tempReg = SRSS_CLK_DPLL_LP_CONFIG5(pllNum);
    config->lpPllCfg->kiInt  = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG5_KI_INT,  tempReg);
    config->lpPllCfg->kpInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG5_KP_INT, tempReg);
    config->lpPllCfg->kiAccInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG5_KI_ACC_INT, tempReg);
    config->lpPllCfg->kpAccInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG5_KP_ACC_INT, tempReg);

    tempReg = SRSS_CLK_DPLL_LP_CONFIG6(pllNum);
    config->lpPllCfg->kiInt  = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG6_KI_FRACT,  tempReg);
    config->lpPllCfg->kpInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG6_KP_FRACT, tempReg);
    config->lpPllCfg->kiAccInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG6_KI_ACC_FRACT, tempReg);
    config->lpPllCfg->kpAccInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG6_KP_ACC_FRACT, tempReg);

    tempReg = SRSS_CLK_DPLL_LP_CONFIG7(pllNum);
    config->lpPllCfg->kiInt  = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG7_KI_SSCG,  tempReg);
    config->lpPllCfg->kpInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG7_KP_SSCG, tempReg);
    config->lpPllCfg->kiAccInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG7_KI_ACC_SSCG, tempReg);
    config->lpPllCfg->kpAccInt   = (uint8_t)_FLD2VAL(CLK_DPLL_LP_CONFIG7_KP_ACC_SSCG, tempReg);
#endif
    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

cy_en_sysclk_status_t Cy_SysClk_DpllLpEnable(uint32_t pllNum, uint32_t timeoutus)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(timeoutus);
#if (CY_SRSS_DPLL_LP_PRESENT != 0U )

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    bool zeroTimeout = (timeoutus == 0UL);

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    /* first set the PLL enable bit */
    SRSS_CLK_DPLL_LP_CONFIG(pllNum) |= CLK_DPLL_LP_CONFIG_ENABLE_Msk;

    /* now do the timeout wait for PLL_STATUS, bit LOCKED */
    for (; (0UL == (CLK_DPLL_LP_STATUS_LOCKED_Msk & SRSS_CLK_DPLL_LP_STATUS(pllNum))) &&
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    if (zeroTimeout || (0UL != timeoutus))
    {
        /* Unbypass PLL, if it is not in AUTO mode */
        if ((uint32_t)CY_SYSCLK_FLLPLL_OUTPUT_INPUT == (uint32_t)_FLD2VAL(CLK_DPLL_LP_CONFIG_BYPASS_SEL, SRSS_CLK_DPLL_LP_CONFIG(pllNum)))
        {
            CY_REG32_CLR_SET(SRSS_CLK_DPLL_LP_CONFIG(pllNum), CLK_DPLL_LP_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT);
        }

        retVal = CY_SYSCLK_SUCCESS;
    }
    else
    {
        /* If lock doesn't occur, then bypass PLL */
        CY_REG32_CLR_SET(SRSS_CLK_DPLL_LP_CONFIG(pllNum), CLK_DPLL_LP_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
        /* Wait at least 6 PLL clock cycles */
        Cy_SysLib_DelayUs(1U);
        /* And now disable the PLL itself */
        SRSS_CLK_DPLL_LP_CONFIG(pllNum) &= ~CLK_DPLL_LP_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_TIMEOUT;
    }

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

uint32_t Cy_SysClk_DpllLpGetFrequency(uint32_t pllNum)
{
    uint32_t fDiv;    /* PLL multiplier/feedback divider */
    uint32_t rDiv;    /* PLL reference divider */
    uint32_t oDiv;    /* PLL output divider */
    uint32_t fracDiv; /* PLL Fractional divider */
    bool  enabled;    /* PLL enable status; n/a for direct */
    uint32_t freq=0UL;    /* PLL Frequency */


    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    cy_stc_dpll_lp_config_t    DpllLpConfig = (cy_stc_dpll_lp_config_t){0};
#if defined (CY_IP_MXS22SRSS)
    cy_stc_pll_manual_config_t pllcfg = {&DpllLpConfig, NULL};
#else
    cy_stc_pll_manual_config_t pllcfg = {&DpllLpConfig};
#endif
    (void)Cy_SysClk_DpllLpGetConfiguration(pllNum, &pllcfg);
    enabled = (Cy_SysClk_DpllLpIsEnabled(pllNum)) && (CY_SYSCLK_FLLPLL_OUTPUT_INPUT != pllcfg.lpPllCfg->outputMode);
    fDiv    = pllcfg.lpPllCfg->feedbackDiv;
    rDiv    = pllcfg.lpPllCfg->referenceDiv;
    oDiv    = pllcfg.lpPllCfg->outputDiv;
    fracDiv = pllcfg.lpPllCfg->fracDiv;

    if (enabled && /* If PLL is enabled and not bypassed */
    (0UL != rDiv) && (0UL != oDiv)) /* to avoid division by zero */
    {
#if defined (CY_IP_MXS40SSRSS)
        pllNum++; /* to correctly access PLL source clock */
#endif
        freq = Cy_SysClk_ClkPathMuxGetFrequency(pllNum);
        freq = (uint32_t)((((uint64_t)freq * (((uint64_t)fDiv << SRSS_DPLL_LP_FRAC_BIT_COUNT) + (uint64_t)fracDiv)) / ((uint64_t)rDiv * (uint64_t)oDiv)) >> SRSS_DPLL_LP_FRAC_BIT_COUNT);
    }

    return (freq);
}


/* DPLL-HP */
#if defined(CY_IP_MXS22SRSS) || defined(CY_DOXYGEN)
bool Cy_SysClk_DpllHpIsEnabled(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_HP_PRESENT)
    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);
    return (_FLD2BOOL(CLK_DPLL_HP_CONFIG_ENABLE, SRSS_CLK_DPLL_HP_CONFIG(pllNum)));
#else
    return false;
#endif
}


bool Cy_SysClk_DpllHpLocked(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_HP_PRESENT)
    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);
    return (_FLD2BOOL(CLK_DPLL_HP_STATUS_LOCKED, SRSS_CLK_DPLL_HP_STATUS(pllNum)));
#else
     return false;
#endif
}


bool Cy_SysClk_DpllHpLostLock(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_HP_PRESENT)
    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);

    bool retVal = _FLD2BOOL(CLK_DPLL_HP_STATUS_UNLOCK_OCCURRED, SRSS_CLK_DPLL_HP_STATUS(pllNum));
    /* write a 1 to clear the unlock occurred bit */
    SRSS_CLK_DPLL_HP_STATUS(pllNum) = CLK_DPLL_HP_STATUS_UNLOCK_OCCURRED_Msk;
    return (retVal);
#else
    return false;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllHpDisable(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);
#if (CY_SRSS_DPLL_HP_PRESENT)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);

    /* First bypass PLL */
    CY_REG32_CLR_SET(SRSS_CLK_DPLL_HP_CONFIG(pllNum), CLK_DPLL_HP_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
    /* Wait at least 6 PLL clock cycles */
    Cy_SysLib_DelayUs(1U);
    /* And now disable the PLL itself */
    SRSS_CLK_DPLL_HP_CONFIG(pllNum) &= ~CLK_DPLL_HP_CONFIG_ENABLE_Msk;
    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

__STATIC_INLINE cy_en_wait_mode_select_t Cy_SysClk_DpllHpGetFreqMode(uint32_t inputFreq)
{
    cy_en_wait_mode_select_t freqMode = CY_SYSCLK_DPLL_HP_CLK50MHZ_1US_CNT_VAL;

    if((inputFreq > 45000000U) && (inputFreq <= 50000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK50MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 40000000U) && (inputFreq <= 45000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK45MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 32000000U) && (inputFreq <= 40000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK40MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 25000000U) && (inputFreq <= 32000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK30MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 16000000U) && (inputFreq <= 25000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK20MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 10000000U) && (inputFreq <= 16000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK15MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 6000000U) && (inputFreq <= 10000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK10MHZ_1US_CNT_VAL;
    }
    else if((inputFreq > 4000000U) && (inputFreq <= 6000000U))
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK4MHZ_1US_CNT_VAL;
    }
    else
    {
        freqMode = CY_SYSCLK_DPLL_HP_CLK50MHZ_1US_CNT_VAL;
    }

    return freqMode;
}

__STATIC_INLINE uint8_t Cy_SysClk_DpllHpGetFlockTh(uint32_t nDiv)
{
    uint8_t flockEnTh;

    if(nDiv < 20U)
    {
        flockEnTh = 0x3U;
    }
    else
    {
        flockEnTh = 0x7U;
    }

    return flockEnTh;
}

__STATIC_INLINE uint8_t Cy_SysClk_DpllHpGetLfBeta(uint32_t inputFreq, uint32_t pDiv)
{
    uint8_t lfBeta;
    uint32_t pfd = inputFreq/(pDiv + 1U);

    if(pfd < 25000000U)
    {
        lfBeta = 0x10U;
    }
    else
    {
        lfBeta = 0x14U;
    }

    return lfBeta;
}

cy_en_sysclk_status_t Cy_SysClk_DpllHpConfigure(uint32_t pllNum, const cy_stc_pll_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if (CY_SRSS_DPLL_HP_PRESENT)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);

    if (((config->inputFreq)  < CY_SYSCLK_DPLL_HP_MIN_IN_FREQ)  || (CY_SYSCLK_DPLL_HP_MAX_IN_FREQ  < (config->inputFreq)) ||
        ((config->outputFreq) < CY_SYSCLK_DPLL_HP_MIN_OUT_FREQ) || (CY_SYSCLK_DPLL_HP_MAX_OUT_FREQ < (config->outputFreq)))
    {
        retVal = CY_SYSCLK_BAD_PARAM;
    }
    else
    {
        cy_stc_dpll_hp_config_t    DpllHpConfig = (cy_stc_dpll_hp_config_t){0};
        cy_stc_pll_manual_config_t manualConfig = {NULL, &DpllHpConfig};

        /* If output mode is not bypass (input routed directly to output), then
           calculate new parameters. */
        if (config->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
            /* for each possible value of NDIV(nDiv) and PDIV(pDiv), try
               to find a value for KDIV (kDiv) that gives an output frequency
               as close as possible to the desired output frequency. */
            uint32_t pDiv, kDiv, nDiv;
            uint32_t foutBest = 0UL; /* to ensure at least one pass through the for loops below */

            /* PDIV (pDiv) selection */
            for (pDiv = CY_SYSCLK_DPLL_HP_MIN_PDIV; pDiv <= CY_SYSCLK_DPLL_HP_MAX_PDIV; pDiv++)
            {
                /* NDIV (nDiv) selection */
                for (nDiv = CY_SYSCLK_DPLL_HP_MIN_NDIV; nDiv <= CY_SYSCLK_DPLL_HP_MAX_NDIV; nDiv++)
                {
                    uint32_t pdf = (uint32_t)((uint32_t)(config->inputFreq/1000U) / (uint32_t)(pDiv));
                    uint32_t fdco = (uint32_t)((uint32_t)(pdf) * (uint32_t)(nDiv));
                    if (((CY_SYSCLK_DPLL_HP_MIN_FDCO <= fdco) && (fdco <= CY_SYSCLK_DPLL_HP_MAX_FDCO))  && ((CY_SYSCLK_DPLL_HP_MIN_PDF <= pdf) && (pdf <= CY_SYSCLK_DPLL_HP_MAX_PDF)))
                    {
                        /* KDIV (kDiv) selection */
                        for (kDiv = CY_SYSCLK_DPLL_HP_MIN_KDIV; kDiv <= CY_SYSCLK_DPLL_HP_MAX_KDIV; kDiv++)
                        {
                            uint64_t tempVco = ((uint64_t)config->outputFreq) * ((uint64_t)kDiv);
                            uint64_t tempFeedBackDivLeftShifted = ((tempVco << (uint64_t)SRSS_DPLL_HP_FRAC_BIT_COUNT) * (uint64_t)pDiv) / (uint64_t)config->inputFreq;
                            volatile uint32_t feedBackFracDiv  = (uint32_t)(tempFeedBackDivLeftShifted & ((1ULL << (uint64_t)SRSS_DPLL_HP_FRAC_BIT_COUNT) - 1ULL));
                            /* Calculate what output frequency will actually be produced.
                               If it's closer to the target than what we have so far, then save it. */
                            uint32_t fout = (uint32_t)((((uint64_t)config->inputFreq * (((uint64_t)nDiv << SRSS_DPLL_HP_FRAC_BIT_COUNT) + (uint64_t)feedBackFracDiv)) / ((uint64_t)pDiv * (uint64_t)kDiv)) >> SRSS_DPLL_HP_FRAC_BIT_COUNT);

                            if (((uint32_t)abs((int32_t)fout - (int32_t)(config->outputFreq)) <
                                (uint32_t)abs((int32_t)foutBest - (int32_t)(config->outputFreq))))
                            {
                                if (foutBest == (config->outputFreq))
                                {
                                   break;
                                }

                                foutBest = fout;
                                manualConfig.hpPllCfg->nDiv  = (uint8_t)(nDiv - 1U);
                                manualConfig.hpPllCfg->pDiv  = (uint8_t)(pDiv - 1U);
                                manualConfig.hpPllCfg->kDiv  = (uint8_t)(kDiv - 1U);
                                manualConfig.hpPllCfg->nDivFract  = feedBackFracDiv;
                            }
                        }
                    }
                }
            }
            /* exit loops if foutBest equals outputFreq */

        } /* if not, bypass output mode */

        /* If output mode is bypass (input routed directly to output), then
           use old parameters. */
        else
        {
            (void)Cy_SysClk_DpllHpGetConfiguration(pllNum, &manualConfig);
        }
        /* configure PLL based on calculated values */
        manualConfig.hpPllCfg->outputMode = config->outputMode;

        manualConfig.hpPllCfg->freqModeSel = Cy_SysClk_DpllHpGetFreqMode(config->inputFreq);
        manualConfig.hpPllCfg->flockThresh = (uint8_t)Cy_SysClk_DpllHpGetFlockTh(manualConfig.hpPllCfg->nDiv);
        manualConfig.hpPllCfg->betaExt     = (uint8_t)Cy_SysClk_DpllHpGetLfBeta(config->inputFreq, manualConfig.hpPllCfg->pDiv);

        /* Set the default parameters to remaining PLL configurations */
        manualConfig.hpPllCfg->ivrTrim     = (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG2_IVR_TRIM;
        manualConfig.hpPllCfg->clkrSel     = CY_SYSCLK_DPLL_HP_CONFIG3_CLKR_SEL;
        manualConfig.hpPllCfg->alphaCoarse = (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG4_LF_LC_ALPHA;
        manualConfig.hpPllCfg->betaCoarse  = (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG4_LF_LC_BETA;
        manualConfig.hpPllCfg->flockWait   = (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG4_FLOCK_WAITPER;
        manualConfig.hpPllCfg->flockLkThres= (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG4_LK_TH;
        manualConfig.hpPllCfg->flockLkWait = (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG4_LK_WAITPER;
        manualConfig.hpPllCfg->alphaExt    = (uint8_t)CY_SYSCLK_DPLL_HP_CONFIG5_LF_ALPHA;
        manualConfig.hpPllCfg->lfEn        = CY_SYSCLK_DPLL_HP_CONFIG5_LF_SET_PARAMS;
        manualConfig.hpPllCfg->dcEn        = CY_SYSCLK_DPLL_HP_DUTY_CAL_CTL_DC_EN;

        retVal = Cy_SysClk_DpllHpManualConfigure(pllNum, &manualConfig);

    } /* if no error */

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllHpManualConfigure(uint32_t pllNum, const cy_stc_pll_manual_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if (CY_SRSS_DPLL_HP_PRESENT)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_SUCCESS;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_LP);

    if (Cy_SysClk_DpllHpIsEnabled(pllNum))
    {
        retVal = CY_SYSCLK_INVALID_STATE;
    }
    /* valid divider bitfield values */
    else if ((config->hpPllCfg->nDiv    < (CY_SYSCLK_DPLL_HP_MIN_NDIV - 1U)) || ((CY_SYSCLK_DPLL_HP_MAX_NDIV - 1U) < config->hpPllCfg->nDiv)    ||
             ((CY_SYSCLK_DPLL_HP_MAX_PDIV - 1U)    < config->hpPllCfg->pDiv) || ((CY_SYSCLK_DPLL_HP_MAX_KDIV - 1U)     < config->hpPllCfg->kDiv))
    {
         retVal = CY_SYSCLK_BAD_PARAM;
    }
    else /* no errors */
    {
        /* If output mode is bypass (input routed directly to output), then done.
           The output frequency equals the input frequency regardless of the frequency parameters. */
        if (config->hpPllCfg->outputMode != CY_SYSCLK_FLLPLL_OUTPUT_INPUT)
        {
                SRSS_CLK_DPLL_HP_CONFIG(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_CONFIG_PLL_FREQ_NDIV_INT_SEL, config->hpPllCfg->nDiv)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG_PLL_FREQ_PDIV_SEL, config->hpPllCfg->pDiv) |
                _VAL2FLD(CLK_DPLL_HP_CONFIG_PLL_FREQ_KDIV_SEL, config->hpPllCfg->kDiv) |
                _VAL2FLD(CLK_DPLL_HP_CONFIG_ENABLE, config->hpPllCfg->pllEn);

                SRSS_CLK_DPLL_HP_CONFIG2(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_CONFIG2_PLL_FREQ_NDIV_FRACT_SEL, config->hpPllCfg->nDivFract)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG2_PLL_FREQ_MODE_SEL, config->hpPllCfg->freqModeSel) |
                _VAL2FLD(CLK_DPLL_HP_CONFIG2_PLL_IVR_TRIM, config->hpPllCfg->ivrTrim);

                SRSS_CLK_DPLL_HP_CONFIG3(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_CONFIG3_PLL_CLKR_SEL, config->hpPllCfg->clkrSel)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG3_PLL_FDSM_SEL, config->hpPllCfg->fdsmSel);

                SRSS_CLK_DPLL_HP_CONFIG4(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_LF_LC_ALPHA, config->hpPllCfg->alphaCoarse)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_LF_LC_BETA, config->hpPllCfg->betaCoarse)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_EN_THRESH, config->hpPllCfg->flockThresh)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_WAITPER, config->hpPllCfg->flockWait)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_THRESH, config->hpPllCfg->flockLkThres)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_WAITPER, config->hpPllCfg->flockLkWait)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_OBSWIN, config->hpPllCfg->flockObs);

                SRSS_CLK_DPLL_HP_CONFIG5(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_CONFIG5_PLL_LF_ALPHA, config->hpPllCfg->alphaExt)  |
                _VAL2FLD(CLK_DPLL_HP_CONFIG5_PLL_LF_BETA, config->hpPllCfg->betaExt) |
                _VAL2FLD(CLK_DPLL_HP_CONFIG5_PLL_LF_SET_PARAMS, config->hpPllCfg->lfEn);

                SRSS_CLK_DPLL_HP_TRIGMOD(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_FREQ, config->hpPllCfg->tmodFreq)  |
                _VAL2FLD(CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_GRD, config->hpPllCfg->tmodGrad);

                SRSS_CLK_DPLL_HP_TRIGMOD2(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_RATE, config->hpPllCfg->tmodRate)  |
                _VAL2FLD(CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_EN, config->hpPllCfg->tmodEn)  |
                _VAL2FLD(CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_STP, config->hpPllCfg->tmodStop);

                SRSS_CLK_DPLL_HP_STATUS(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_STATUS_LOCKED, config->hpPllCfg->pllLocked)  |
                _VAL2FLD(CLK_DPLL_HP_STATUS_UNLOCK_OCCURRED, config->hpPllCfg->pllUnlock) |
                _VAL2FLD(CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES, config->hpPllCfg->lockDetReset) |
                _VAL2FLD(CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES_ACK, config->hpPllCfg->lockDetRstAck);

                SRSS_CLK_DPLL_HP_DUTYCAL_CTRL(pllNum) =
                _VAL2FLD(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_DELTA, config->hpPllCfg->dcCalDelta)  |
                _VAL2FLD(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_RATIO_OK, config->hpPllCfg->dcRatioStatus)  |
                _VAL2FLD(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_OK, config->hpPllCfg->dcStatus)  |
                _VAL2FLD(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_TARGET, config->hpPllCfg->dcTarget)  |
                _VAL2FLD(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_CTRL_RG_EN, config->hpPllCfg->dcEnRingOsc)  |
                _VAL2FLD(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_EN, config->hpPllCfg->dcEn);
        }

        CY_REG32_CLR_SET(SRSS_CLK_DPLL_HP_CONFIG(pllNum), CLK_DPLL_HP_CONFIG_BYPASS_SEL, (uint32_t)config->hpPllCfg->outputMode);
    }

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}


cy_en_sysclk_status_t Cy_SysClk_DpllHpGetConfiguration(uint32_t pllNum, cy_stc_pll_manual_config_t *config)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(config);

#if (CY_SRSS_DPLL_HP_PRESENT)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);

    /* Initialize config structure to 0 */
    *(config->hpPllCfg) = (cy_stc_dpll_hp_config_t){0};

    uint32_t tempReg = SRSS_CLK_DPLL_HP_CONFIG(pllNum);
    config->hpPllCfg->nDiv          = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG_PLL_FREQ_NDIV_INT_SEL, tempReg);
    config->hpPllCfg->pDiv          = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG_PLL_FREQ_PDIV_SEL, tempReg);
    config->hpPllCfg->kDiv          = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG_PLL_FREQ_KDIV_SEL, tempReg);
    config->hpPllCfg->outputMode    = (cy_en_fll_pll_output_mode_t)((uint32_t)_FLD2VAL(CLK_DPLL_HP_CONFIG_BYPASS_SEL, tempReg));
    config->hpPllCfg->pllEn         = (bool)_FLD2VAL(CLK_DPLL_HP_CONFIG_ENABLE, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_CONFIG2(pllNum);
    config->hpPllCfg->nDivFract     = (uint32_t)_FLD2VAL(CLK_DPLL_HP_CONFIG2_PLL_FREQ_NDIV_FRACT_SEL, tempReg);
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Cast of composite expression of essential type unsigned to essential type enum');
    config->hpPllCfg->freqModeSel   = (cy_en_wait_mode_select_t)_FLD2VAL(CLK_DPLL_HP_CONFIG2_PLL_FREQ_MODE_SEL, tempReg);
    config->hpPllCfg->ivrTrim       = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG2_PLL_IVR_TRIM, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_CONFIG3(pllNum);
    config->hpPllCfg->clkrSel       = (bool)_FLD2VAL(CLK_DPLL_HP_CONFIG3_PLL_CLKR_SEL, tempReg);
    config->hpPllCfg->fdsmSel       = (bool)_FLD2VAL(CLK_DPLL_HP_CONFIG3_PLL_FDSM_SEL, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_CONFIG4(pllNum);
    config->hpPllCfg->alphaCoarse   = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_LF_LC_ALPHA, tempReg);
    config->hpPllCfg->betaCoarse    = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_LF_LC_BETA, tempReg);
    config->hpPllCfg->flockThresh   = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_EN_THRESH, tempReg);
    config->hpPllCfg->flockWait     = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_WAITPER, tempReg);
    config->hpPllCfg->flockLkThres  = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_THRESH, tempReg);
    config->hpPllCfg->flockLkWait   = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_LK_WAITPER, tempReg);
    config->hpPllCfg->flockObs      = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG4_PLL_FLOCK_OBSWIN, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_CONFIG5(pllNum);
    config->hpPllCfg->alphaExt      = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG5_PLL_LF_ALPHA, tempReg);
    config->hpPllCfg->betaExt       = (uint8_t)_FLD2VAL(CLK_DPLL_HP_CONFIG5_PLL_LF_BETA, tempReg);
    config->hpPllCfg->lfEn          = (bool)_FLD2VAL(CLK_DPLL_HP_CONFIG5_PLL_LF_SET_PARAMS, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_TRIGMOD(pllNum);
    config->hpPllCfg->tmodFreq     = (uint16_t)_FLD2VAL(CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_FREQ, tempReg);
    config->hpPllCfg->tmodGrad     = (uint16_t)_FLD2VAL(CLK_DPLL_HP_TRIGMOD_PLL_TRIMOD_GRD, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_TRIGMOD2(pllNum);
    config->hpPllCfg->tmodRate      = (uint32_t)_FLD2VAL(CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_RATE, tempReg);
    config->hpPllCfg->tmodEn        = (bool)_FLD2VAL(CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_EN, tempReg);
    config->hpPllCfg->tmodStop      = (bool)_FLD2VAL(CLK_DPLL_HP_TRIGMOD2_PLL_TRIMOD_STP, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_STATUS(pllNum);
    config->hpPllCfg->pllLocked      = (bool)_FLD2VAL(CLK_DPLL_HP_STATUS_LOCKED, tempReg);
    config->hpPllCfg->pllUnlock      = (bool)_FLD2VAL(CLK_DPLL_HP_STATUS_UNLOCK_OCCURRED, tempReg);
    config->hpPllCfg->lockDetReset   = (bool)_FLD2VAL(CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES, tempReg);
    config->hpPllCfg->lockDetRstAck  = (bool)_FLD2VAL(CLK_DPLL_HP_STATUS_PLL_LOCKDET_RES_ACK, tempReg);

    tempReg = SRSS_CLK_DPLL_HP_DUTYCAL_CTRL(pllNum);
    config->hpPllCfg->dcCalDelta    = (uint8_t)_FLD2VAL(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_DELTA, tempReg);
    config->hpPllCfg->dcRatioStatus = (bool)_FLD2VAL(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_RATIO_OK, tempReg);
    config->hpPllCfg->dcStatus      = (bool)_FLD2VAL(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTY_CAL_OK, tempReg);
    config->hpPllCfg->dcTarget      = (uint16_t)_FLD2VAL(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_TARGET, tempReg);
    config->hpPllCfg->dcEnRingOsc   = (bool)_FLD2VAL(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_CTRL_RG_EN, tempReg);
    config->hpPllCfg->dcEn          = (bool)_FLD2VAL(CLK_DPLL_HP_DUTYCAL_CTRL_PLL_DUTYCAL_EN, tempReg);

    retVal = CY_SYSCLK_SUCCESS;

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

cy_en_sysclk_status_t Cy_SysClk_DpllHpEnable(uint32_t pllNum, uint32_t timeoutus)
{
    CY_UNUSED_PARAMETER(pllNum);
    CY_UNUSED_PARAMETER(timeoutus);

#if (CY_SRSS_DPLL_HP_PRESENT)

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    bool zeroTimeout = (timeoutus == 0UL);

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);

    /* first set the PLL enable bit */
    SRSS_CLK_DPLL_HP_CONFIG(pllNum) |= CLK_DPLL_HP_CONFIG_ENABLE_Msk;

    /* now do the timeout wait for PLL_STATUS, bit LOCKED */
    for (; (0UL == (CLK_DPLL_HP_STATUS_LOCKED_Msk & SRSS_CLK_DPLL_HP_STATUS(pllNum))) &&
           (0UL != timeoutus);
         timeoutus--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    if (zeroTimeout || (0UL != timeoutus))
    {
        /* Unbypass PLL, if it is not in AUTO mode */
        if ((uint32_t)CY_SYSCLK_FLLPLL_OUTPUT_INPUT == (uint32_t)_FLD2VAL(CLK_DPLL_HP_CONFIG_BYPASS_SEL, SRSS_CLK_DPLL_HP_CONFIG(pllNum)))
        {
            CY_REG32_CLR_SET(SRSS_CLK_DPLL_HP_CONFIG(pllNum), CLK_DPLL_HP_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_OUTPUT);
        }

        retVal = CY_SYSCLK_SUCCESS;
    }
    else
    {
        /* If lock doesn't occur, then bypass PLL */
        CY_REG32_CLR_SET(SRSS_CLK_DPLL_HP_CONFIG(pllNum), CLK_DPLL_HP_CONFIG_BYPASS_SEL, CY_SYSCLK_FLLPLL_OUTPUT_INPUT);
        /* Wait at least 6 PLL clock cycles */
        Cy_SysLib_DelayUs(1U);
        /* And now disable the PLL itself */
        SRSS_CLK_DPLL_HP_CONFIG(pllNum) &= ~CLK_DPLL_HP_CONFIG_ENABLE_Msk;
        retVal = CY_SYSCLK_TIMEOUT;
    }

    return (retVal);
#else
    return CY_SYSCLK_UNSUPPORTED_STATE;
#endif
}

uint32_t Cy_SysClk_DpllHpGetFrequency(uint32_t pllNum)
{
    CY_UNUSED_PARAMETER(pllNum);

#if (CY_SRSS_DPLL_HP_PRESENT)
    uint32_t nDiv;
    uint32_t pDiv;
    uint32_t kDiv;
    uint32_t nDivFract;
    bool  enabled;
    uint32_t freq=0UL;

    CY_ASSERT_L1(pllNum < SRSS_NUM_DPLL_HP);

    cy_stc_dpll_hp_config_t    DpllHpConfig = (cy_stc_dpll_hp_config_t){0};
    cy_stc_pll_manual_config_t pllcfg = {NULL, &DpllHpConfig};

    (void)Cy_SysClk_DpllHpGetConfiguration(pllNum, &pllcfg);
    enabled  = (Cy_SysClk_DpllHpIsEnabled(pllNum)) && (CY_SYSCLK_FLLPLL_OUTPUT_INPUT != pllcfg.hpPllCfg->outputMode);
    nDiv     = (uint32_t)pllcfg.hpPllCfg->nDiv + 1U;
    pDiv     = (uint32_t)pllcfg.hpPllCfg->pDiv + 1U;
    kDiv     = (uint32_t)pllcfg.hpPllCfg->kDiv + 1U;
    nDivFract = pllcfg.hpPllCfg->nDivFract;

    if (enabled )/* If PLL is enabled and not bypassed */
    {
        freq = Cy_SysClk_ClkPathMuxGetFrequency(pllNum + SRSS_DPLL_HP_0_PATH_NUM);
        if(0U == nDivFract)
        {
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','unsigned 64-bit int" to different or narrower essential type "unsigned 32-bit int');
            freq = (uint32_t)((uint64_t)freq * ((uint64_t)nDiv)) / (((uint64_t)pDiv) * ((uint64_t)kDiv));
        }
        else
        {
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','unsigned 64-bit int" to different or narrower essential type "unsigned 32-bit int');
            freq = (uint32_t)((((uint64_t)freq * (((uint64_t)nDiv << SRSS_DPLL_HP_FRAC_BIT_COUNT) + (uint64_t)nDivFract)) / ((uint64_t)pDiv * (uint64_t)kDiv)) >> SRSS_DPLL_HP_FRAC_BIT_COUNT);
        }
    }

    return (freq);
#else
    return 0U;
#endif
}


#endif /* DPLL-HP */
#endif /* DPLL-LP, DPLL-HP */


bool Cy_SysClk_PllIsEnabled(uint32_t clkPath)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpIsEnabled(clkPath);
    }
    else
    {
        return Cy_SysClk_DpllHpIsEnabled(clkPath - SRSS_NUM_DPLL_LP);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));
    if(clkPath< SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpIsEnabled(clkPath);
    }
    else
    {
        return false;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MIsEnabled(clkPath);
    }
    else
#endif
    {
        return Cy_SysClk_Pll200MIsEnabled(clkPath - CY_SRSS_NUM_PLL400M);
    }
#endif
}

bool Cy_SysClk_PllLocked(uint32_t clkPath)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpLocked(clkPath);
    }
    else
    {
        return Cy_SysClk_DpllHpLocked(clkPath - SRSS_NUM_DPLL_LP);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpLocked(clkPath);
    }
    else
    {
        return false;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MLocked(clkPath);
    }
    else
    {
        return Cy_SysClk_Pll200MLocked(clkPath - CY_SRSS_NUM_PLL400M);
    }
#else
    return Cy_SysClk_Pll200MLocked(clkPath);
#endif
#endif
}

bool Cy_SysClk_PllLostLock(uint32_t clkPath)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpLostLock(clkPath);
    }
    else
    {
        return Cy_SysClk_DpllHpLostLock(clkPath - SRSS_NUM_DPLL_LP);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpLostLock(clkPath);
    }
    else
    {
        return false;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MLostLock(clkPath);
    }
    else
    {
        return Cy_SysClk_Pll200MLostLock(clkPath - CY_SRSS_NUM_PLL400M);
    }
#else
    return Cy_SysClk_Pll200MLostLock(clkPath);
#endif
#endif
}

cy_en_sysclk_status_t Cy_SysClk_PllDisable(uint32_t clkPath)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpDisable(clkPath);
    }
    else
    {
        return Cy_SysClk_DpllHpDisable(clkPath - SRSS_NUM_DPLL_LP);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpDisable(clkPath);
    }
    else
    {
        return CY_SYSCLK_BAD_PARAM;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MDisable(clkPath);
    }
    else
    {
        return Cy_SysClk_Pll200MDisable(clkPath - CY_SRSS_NUM_PLL400M);
    }
#else
    return Cy_SysClk_Pll200MDisable(clkPath);
#endif
#endif
}


cy_en_sysclk_status_t Cy_SysClk_PllConfigure(uint32_t clkPath, const cy_stc_pll_config_t *config)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpConfigure(clkPath, config);
    }
    else
    {
        return Cy_SysClk_DpllHpConfigure(clkPath - SRSS_NUM_DPLL_LP, config);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpConfigure(clkPath, config);
    }
    else
    {
        return CY_SYSCLK_BAD_PARAM;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MConfigure(clkPath, config);
    }
    else
    {
        return Cy_SysClk_Pll200MConfigure((clkPath - CY_SRSS_NUM_PLL400M), config);
    }
#else
    return Cy_SysClk_Pll200MConfigure(clkPath, config);
#endif
#endif
}

cy_en_sysclk_status_t Cy_SysClk_PllManualConfigure(uint32_t clkPath, const cy_stc_pll_manual_config_t *config)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpManualConfigure(clkPath, config);
    }
    else
    {
        return Cy_SysClk_DpllHpManualConfigure(clkPath - SRSS_NUM_DPLL_LP, config);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpManualConfigure(clkPath, config);
    }
    else
    {
        return CY_SYSCLK_BAD_PARAM;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MManualConfigure(clkPath, config);
    }
    else
    {
        return Cy_SysClk_Pll200MManualConfigure((clkPath - CY_SRSS_NUM_PLL400M), config);
    }
#else
    return Cy_SysClk_Pll200MManualConfigure(clkPath, config);
#endif
#endif
}

cy_en_sysclk_status_t Cy_SysClk_PllGetConfiguration(uint32_t clkPath, cy_stc_pll_manual_config_t *config)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpGetConfiguration(clkPath, config);
    }
    else
    {
        return Cy_SysClk_DpllHpGetConfiguration(clkPath - SRSS_NUM_DPLL_LP, config);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpGetConfiguration(clkPath, config);
    }
    else
    {
        return CY_SYSCLK_BAD_PARAM;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MGetConfiguration(clkPath, config);
    }
    else
    {
        return Cy_SysClk_Pll200MGetConfiguration((clkPath - CY_SRSS_NUM_PLL400M), config);
    }
#else
    return Cy_SysClk_Pll200MGetConfiguration(clkPath, config);
#endif
#endif
}

cy_en_sysclk_status_t Cy_SysClk_PllEnable(uint32_t clkPath, uint32_t timeoutus)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpEnable(clkPath, timeoutus);
    }
    else
    {
        return Cy_SysClk_DpllHpEnable(clkPath - SRSS_NUM_DPLL_LP, timeoutus);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpEnable(clkPath, timeoutus);
    }
    else
    {
        return CY_SYSCLK_BAD_PARAM;
    }
#else
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MEnable(clkPath, timeoutus);
    }
    else
    {
        return Cy_SysClk_Pll200MEnable((clkPath - CY_SRSS_NUM_PLL400M), timeoutus);
    }
#else
    return Cy_SysClk_Pll200MEnable(clkPath, timeoutus);
#endif  /* defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0) */
#endif
}

uint32_t Cy_SysClk_PllGetFrequency(uint32_t clkPath)
{
#if defined(CY_IP_MXS22SRSS)
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpGetFrequency(clkPath);
    }
    else
    {
        return Cy_SysClk_DpllHpGetFrequency(clkPath - SRSS_NUM_DPLL_LP);
    }
#elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
    CY_ASSERT_L1(clkPath > 0U);
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

    if(clkPath < SRSS_NUM_DPLL_LP)
    {
        return Cy_SysClk_DpllLpGetFrequency(clkPath);
    }
    else
    {
        return 0UL;
    }
#else
    CY_ASSERT_L1(clkPath > 0U);
    clkPath--; /* to correctly access PLL config and status registers structures */
    CY_ASSERT_L1(clkPath < (CY_SRSS_NUM_PLL));

#if defined (CY_SRSS_NUM_PLL400M) && (CY_SRSS_NUM_PLL400M > 0)
    if(clkPath < CY_SRSS_NUM_PLL400M)
    {
        return Cy_SysClk_Pll400MGetFrequency(clkPath);
    }
    else
    {
        return Cy_SysClk_Pll200MGetFrequency(clkPath - CY_SRSS_NUM_PLL400M);
    }
#else
    return Cy_SysClk_Pll200MGetFrequency(clkPath);
#endif
#endif
}


#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) */

/* ========================================================================== */
/* ====================    Clock Measurement section    ===================== */
/* ========================================================================== */
/* Slow control register default value */
#define TST_DDFT_SLOW_CTL_DEFAULT_VAL      (0x00001F1FUL)

/* Fast control register */
#define TST_DDFT_FAST_CTL_REG              (*(volatile uint32_t *) 0x40260104U)

/* Slow control register default value */
#define TST_DDFT_FAST_CTL_DEFAULT_VAL      (0x00003D3DUL)

/* Define for select signal outputs in slow clock */
#define SRSS_CLK_OUTPUT_SLOW_MASK  ((uint32_t) SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0_Msk | \
                                               SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1_Msk)

/* Define for select signal outputs in fast clock */
#define SRSS_CLK_OUTPUT_FAST_MASK  ((uint32_t) SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Msk  | \
                                               SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Msk  | \
                                               SRSS_CLK_OUTPUT_FAST_PATH_SEL0_Msk  | \
                                               SRSS_CLK_OUTPUT_FAST_PATH_SEL1_Msk  | \
                                               SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0_Msk | \
                                               SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1_Msk)


bool Cy_SysClk_ClkMeasurementCountersDone(void)
{
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return (_FLD2BOOL(SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE, SRSS_CLK_CAL_CNT1));
}

cy_en_sysclk_status_t Cy_SysClk_StartClkMeasurementCounters(cy_en_meas_clks_t clock1, uint32_t count1, cy_en_meas_clks_t clock2)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;

    uint32_t clkOutputSlowVal = 0UL;
    uint32_t clkOutputFastVal = 0UL;

    uint32_t clkOutputSlowMask = 0UL;
    uint32_t clkOutputFastMask = 0UL;

    /* Prepare values for measurement control registers */

    /* Connect the indicated clocks to the respective counters:

       if clock1 is a slow clock,
         select it in SRSS_CLK_OUTPUT_SLOW.SLOW_SEL0, and SRSS_CLK_OUTPUT_FAST.FAST_SEL0 = SLOW_SEL0
       else if clock1 is a fast clock,
         select it in SRSS_CLK_OUTPUT_FAST.FAST_SEL0,
       else error, do nothing and return.

       if clock2 is a slow clock,
         select it in SRSS_CLK_OUTPUT_SLOW.SLOW_SEL1, and SRSS_CLK_OUTPUT_FAST.FAST_SEL1 = SLOW_SEL1
       else if clock2 is a fast clock,
         select it in SRSS_CLK_OUTPUT_FAST.FAST_SEL1,
       else error, do nothing and return.
    */
    if ((clock1 < CY_SYSCLK_MEAS_CLK_LAST_CLK) && (clock2 < CY_SYSCLK_MEAS_CLK_LAST_CLK) &&
        (count1 <= (SRSS_CLK_CAL_CNT1_CAL_COUNTER1_Msk >> SRSS_CLK_CAL_CNT1_CAL_COUNTER1_Pos)))
    {
        /* Disallow entry into Deep Sleep mode while counting */
        clkCounting = true;

        if (clock1 < CY_SYSCLK_MEAS_CLK_FAST_CLKS)
        { /* slow clock */
            clkOutputSlowVal |= _VAL2FLD(SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0, (uint32_t)clock1);
            clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_FAST_SEL0, SLOW_SEL_OUTPUT_INDEX /*slow_sel0 output*/);

            clkOutputSlowMask |= SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0_Msk;
            clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Msk;
        }
        else
        { /* fast clock */
            if (clock1 < CY_SYSCLK_MEAS_CLK_PATH_CLKS)
            { /* ECO, EXT, ALTHF */
                clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_FAST_SEL0, (uint32_t)clock1);
                clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Msk;
            }
            else
            { /* PATH or CLKHF */
                clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_FAST_SEL0, (((uint32_t)clock1 >> 8) & 0xFUL) /*use enum bits [11:8]*/);
                clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Msk;

                if (clock1 < CY_SYSCLK_MEAS_CLK_CLKHFS)
                { /* PATH select */
                    clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_PATH_SEL0, ((uint32_t)clock1 & 0xFUL) /*use enum bits [3:0]*/);
                    clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_PATH_SEL0_Msk;
                }
                else
                { /* CLKHF select */
                    clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0, ((uint32_t)clock1 & 0xFUL) /*use enum bits [3:0]*/);
                    clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0_Msk;
                }
            }
        } /* clock1 fast clock */

        if (clock2 < CY_SYSCLK_MEAS_CLK_FAST_CLKS)
        { /* slow clock */
            clkOutputSlowVal |= _VAL2FLD(SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1, (uint32_t)clock2);
            clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_FAST_SEL1, SLOW_SEL_OUTPUT_INDEX /*slow_sel1 output*/);

            clkOutputSlowMask |= SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1_Msk;
            clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Msk;
        }
        else
        { /* fast clock */
            if (clock2 < CY_SYSCLK_MEAS_CLK_PATH_CLKS)
            { /* ECO, EXT, ALTHF */
                clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_FAST_SEL1, (uint32_t)clock2);
                clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Msk;
            }
            else
            { /* PATH or CLKHF */
                clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_FAST_SEL1, (((uint32_t)clock2 >> 8) & 0xFUL) /*use enum bits [11:8]*/);
                clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Msk;

                if (clock2 < CY_SYSCLK_MEAS_CLK_CLKHFS)
                { /* PATH select */
                    clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_PATH_SEL1, ((uint32_t)clock2 & 0xFUL) /*use enum bits [3:0]*/);
                    clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_PATH_SEL1_Msk;
                }
                else
                { /* CLKHF select */
                    clkOutputFastVal |= _VAL2FLD(SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1, ((uint32_t)clock2 & 0xFUL) /*use enum bits [3:0]*/);
                    clkOutputFastMask |= SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1_Msk;
                }
            }
        } /* clock2 fast clock */

        if ((!preventCounting) /* don't start a measurement if about to enter Deep Sleep mode */  ||
            (_FLD2VAL(SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE, SRSS_CLK_CAL_CNT1) != 0UL/*1 = done */))
        {
            /* Set default values for counters measurement control registers */
            SRSS_TST_DDFT_SLOW_CTL_REG = TST_DDFT_SLOW_CTL_DEFAULT_VAL;
            SRSS_TST_DDFT_FAST_CTL_REG = TST_DDFT_FAST_CTL_DEFAULT_VAL;

            SRSS_CLK_OUTPUT_SLOW = ((SRSS_CLK_OUTPUT_SLOW & ((uint32_t) ~clkOutputSlowMask)) | clkOutputSlowVal);
            SRSS_CLK_OUTPUT_FAST = ((SRSS_CLK_OUTPUT_FAST & ((uint32_t) ~clkOutputFastMask)) | clkOutputFastVal);

            /* Save this input parameter for use later, in other functions.
               No error checking is done on this parameter */
            clk1Count1 = count1;

            /* Counting starts when counter1 is written with a nonzero value */
            SRSS_CLK_CAL_CNT1 = clk1Count1;

            retVal = CY_SYSCLK_SUCCESS;
        }
    }
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return (retVal);
}


uint32_t Cy_SysClk_ClkMeasurementCountersGetFreq(bool measuredClock, uint32_t refClkFreq)
{
    uint32_t retVal = 0UL;
    bool isMeasurementValid = false;

    /* Done counting; allow entry into Deep Sleep mode */
    clkCounting = false;

    /* Check whether the device was in the Deep Sleep mode or the flash partially blocked while the
    *  operation was done
    */
    if(SRSS_TST_DDFT_SLOW_CTL_REG == TST_DDFT_SLOW_CTL_DEFAULT_VAL)
    {
       if(SRSS_TST_DDFT_FAST_CTL_REG == TST_DDFT_FAST_CTL_DEFAULT_VAL)
       {
           isMeasurementValid = true;
       }
    }

    retVal = _FLD2VAL(SRSS_CLK_CAL_CNT2_CAL_COUNTER2, SRSS_CLK_CAL_CNT2);

    if (isMeasurementValid && (0UL != retVal))
    {
        if (!measuredClock)
        {   /* clock1 is the measured clock */
            retVal = (uint32_t)CY_SYSLIB_DIV_ROUND((uint64_t)clk1Count1 * (uint64_t)refClkFreq, (uint64_t)retVal);
        }
        else
        {   /* clock2 is the measured clock */
            retVal = (uint32_t)CY_SYSLIB_DIV_ROUND((uint64_t)retVal * (uint64_t)refClkFreq, (uint64_t)clk1Count1);
        }
    }
    else
    {
        /* Return zero value to indicate invalid measurement */
        retVal = 0UL;
    }
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return (retVal);
}


/* ========================================================================== */
/* ==========================    TRIM SECTION    ============================ */
/* ========================================================================== */

/** \cond INTERNAL */
#define CY_SYSCLK_ILO_TARGET_FREQ  (32768UL)
/* Nominal trim step size is 1.5% of "the frequency". Using the target frequency */
#define CY_SYSCLK_ILO_TRIM_STEP    (CY_SYSLIB_DIV_ROUND(CY_SYSCLK_ILO_TARGET_FREQ * 15UL, 1000UL))
/** \endcond */

#if defined (CY_IP_MXS40SSRSS)
int32_t Cy_SysClk_IloTrim(uint32_t iloFreq)
{
    int32_t changeInTrim;
    uint32_t diff;
    bool sign = false;

    if(iloFreq > (CY_SYSCLK_ILO_TARGET_FREQ + CY_SYSCLK_ILO_TRIM_STEP))
    {
        diff = iloFreq - CY_SYSCLK_ILO_TARGET_FREQ;
    }
    else if (iloFreq < (CY_SYSCLK_ILO_TARGET_FREQ - CY_SYSCLK_ILO_TRIM_STEP))
    {
        diff = CY_SYSCLK_ILO_TARGET_FREQ - iloFreq;
        sign = true;
    }
    else
    {
        diff = 0UL;
    }

    /* Do nothing if iloFreq is already within one trim step from the target */
    if(0UL != diff)
    {
        /* Get current trim value */
        uint32_t trim = Cy_SysClk_IloGetTrim();

        diff = CY_SYSLIB_DIV_ROUND(diff, CY_SYSCLK_ILO_TRIM_STEP);

        if(sign)
        {
            trim += diff;
        }
        else
        {
            trim -= diff;
    }

    /* Update the trim value */
    Cy_SysClk_IloSetTrim(trim);
    }

    changeInTrim = (sign ? (int32_t)diff : (0L - (int32_t)diff));
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return changeInTrim;

}

void Cy_SysClk_IloSetTrim(uint32_t trimVal)
{
#if defined (CY_IP_MXS40SSRSS)
    CY_REG32_CLR_SET(SRSS_CLK_TRIM_ILO_CTL, SRSS_CLK_TRIM_ILO_CTL_ILO_FTRIM, trimVal);
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */
#else
    CY_UNUSED_PARAMETER(trimVal); /* Suppress a compiler warning about unused variables */
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */
#endif
}

uint32_t Cy_SysClk_IloGetTrim(void)
{
#if defined (CY_IP_MXS40SSRSS)
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return (_FLD2VAL(SRSS_CLK_TRIM_ILO_CTL_ILO_FTRIM, SRSS_CLK_TRIM_ILO_CTL));
#else
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return 0;
#endif
}
#endif /* defined (CY_IP_MXS40SSRSS) */

/* ========================================================================== */
/* ======================    POWER MANAGEMENT SECTION    ==================== */
/* ========================================================================== */


/** \cond INTERNAL */
/* Timeout count for use in function Cy_SysClk_DeepSleepCallback() is sufficiently large for ~1 second */
#define TIMEOUT (1000000UL)
/** \endcond */

cy_en_syspm_status_t Cy_SysClk_DeepSleepCallback(cy_stc_syspm_callback_params_t * callbackParams, cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    /* Suppress "not used" warning */
    CY_UNUSED_PARAMETER(callbackParams);
    CY_UNUSED_PARAMETER(clkCounting);

    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
            /* Don't allow entry into Deep Sleep mode if currently measuring a frequency */
            if (!clkCounting)
            {
                /* Indicating that we can go into Deep Sleep.
                 * Prevent starting a new clock measurement until
                 * after we've come back from Deep Sleep.
                 */
                preventCounting = true;
                retVal = CY_SYSPM_SUCCESS;
            }
            break;

        case CY_SYSPM_CHECK_FAIL:
            /* Cancellation of going into Deep Sleep, therefore allow a new clock measurement */
            preventCounting = false;
            retVal = CY_SYSPM_SUCCESS;
            break;

        case CY_SYSPM_BEFORE_TRANSITION:
            retVal = CY_SYSPM_SUCCESS;
            break;

        case CY_SYSPM_AFTER_TRANSITION:
            preventCounting = false; /* Allow clock measurement */
            break;

        default: /* Unsupported mode, return CY_SYSPM_FAIL */
            break;
    }

    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */

    return (retVal);

}


/** \cond INTERNAL */
/* Value to indicate invalid HF NUM */
#define CY_SYSCLK_INVALID_HF_NUM (0xFFFFFFFFUL)
/** \endcond */
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.1', 5, \
'Suppressing taking true and false branch.')
uint32_t Cy_Sysclk_PeriPclkGetClkHfNum(uint32_t ipBlock)
{
#if (defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3U)))
    /* MXPERI versions 1 & 2 do not use peri groups, this function is not compatible with PERI ver2. */
    CY_UNUSED_PARAMETER(ipBlock);
    return CY_SYSCLK_INVALID_HF_NUM;
#else
    uint32_t grpNum = (ipBlock & PERI_PCLK_GR_NUM_Msk) >> PERI_PCLK_GR_NUM_Pos;
    uint32_t instNum = (uint8_t)((ipBlock & PERI_PCLK_INST_NUM_Msk) >> PERI_PCLK_INST_NUM_Pos);
#endif
#if !(defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3U)))

    if (grpNum >= PERI_PCLK_GR_NUM(instNum))
    {
        return CY_SYSCLK_INVALID_HF_NUM;
    }

    #if defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION >= 3)
        uint32_t peri0GrpToHfArray[] = { PERI0_PCLK_GR_NUM_0_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_1_CLK_HF_NUM,
                                  };
    #elif (defined (CY_IP_MXS40SSRSS) && (SRSS_NUM_TOTAL_PLL > 0UL))
        uint32_t peri0GrpToHfArray[] = { PERI0_PCLK_GR_NUM_0_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_1_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_2_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_3_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_4_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_5_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_6_CLK_HF_NUM
                                  };
    #elif defined (CY_IP_MXS22SRSS)
        uint32_t peri0GrpToHfArray[PERI0_PCLK_GROUP_NR] = { PERI0_PCLK_GR_NUM_0_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_1_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_2_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_3_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_4_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_5_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_6_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_7_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_8_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_9_CLK_HF_NUM,
                                  };
    #else
        uint32_t peri0GrpToHfArray[] = { PERI0_PCLK_GR_NUM_0_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_1_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_2_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_3_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_4_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_5_CLK_HF_NUM,
                                    PERI0_PCLK_GR_NUM_6_CLK_HF_NUM
                                  };
    #endif

#if defined (CY_IP_MXS22SRSS)
    uint32_t peri1GrpToHfArray[PERI1_PCLK_GROUP_NR] = { PERI1_PCLK_GR_NUM_0_CLK_HF_NUM,
                                PERI1_PCLK_GR_NUM_1_CLK_HF_NUM,
                                PERI1_PCLK_GR_NUM_2_CLK_HF_NUM,
                                PERI1_PCLK_GR_NUM_3_CLK_HF_NUM,
                                PERI1_PCLK_GR_NUM_4_CLK_HF_NUM,
                                PERI1_PCLK_GR_NUM_5_CLK_HF_NUM,
                              };
#endif

#if defined (CY_IP_MXS22SRSS)
    if(0UL == instNum)
    {
        return peri0GrpToHfArray[grpNum];
    }
    else
    {
        return peri1GrpToHfArray[grpNum];
    }
#else
    return peri0GrpToHfArray[grpNum];
#endif
#endif
}

uint32_t Cy_SysClk_PeriPclkGetFrequency(en_clk_dst_t ipBlock, cy_en_divider_types_t dividerType, uint32_t dividerNum)
{
    uint32_t grpNum = 0UL;
    uint32_t instNum = 0UL;
#if !(defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION <= 2))
    grpNum = (((uint32_t)ipBlock) & PERI_PCLK_GR_NUM_Msk )>>PERI_PCLK_GR_NUM_Pos;
    instNum = (uint8_t)(((uint32_t)ipBlock & PERI_PCLK_INST_NUM_Msk )>>PERI_PCLK_INST_NUM_Pos);
    CY_ASSERT_L1(instNum < PERI_INSTANCE_COUNT);
    CY_ASSERT_L1(grpNum < PERI_PCLK_GR_NUM(instNum));
#endif
#if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSCLK_ENABLE_SRF_INTEG) && \
    (defined(_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK) && (_CY_PDL_SYSCLK_PPC_SECURED_PERI_PCLK))
    /* If the PERI instance is marked secured, route this request through the SRF */
    if(mtb_pdl_sysclk_peri_group_div_srf_secured[instNum])
    {
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_sysclk_srf_peripclk_get_freq_in_t input_args;
        cy_pdl_sysclk_srf_peripclk_get_freq_out_t output_args;
        input_args.dividerType = dividerType;
        input_args.dividerNum = dividerNum;

        cy_rslt_t result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSCLK_SRF_POOL_TIMEOUT);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSCLK_OP_PERIPCLK_GET_FREQ,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSCLK,
        #if !(defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION <= 2))
            .base = (instNum == 0 ? PERI0 : PERI1),
            .sub_block = grpNum,
        #else
            .base = NULL,
            .sub_block = 0UL,
        #endif
            .input_base = (uint8_t*)&input_args,
            .input_len = sizeof(input_args),
            .output_base = (uint8_t*)&output_args,
            .output_len = sizeof(output_args),
            .invec_bases = NULL,
            .invec_sizes = 0UL,
            .outvec_bases = NULL,
            .outvec_sizes = 0UL
        };
        result = _Cy_PDL_Invoke_SRF(&invoke_args);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

        /* Output values are passed in by value. Make a copy before freeing the ioVec */
        memcpy(&output_args, (&(output->output_values[0])), sizeof(output_args));

        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);

        return output_args.freq;
    }
#endif
    uint32_t integer = 0UL;        /* Integer part of peripheral divider */
    uint32_t freq = 0UL;
    uint32_t hfNum = CY_SYSCLK_INVALID_HF_NUM;
#if defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)
    uint32_t peri_div = 1UL + (uint32_t)Cy_SysClk_ClkPeriGetDivider();
#endif
#if defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION <= 2)
    hfNum = 0UL;
#else
#if defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)
    peri_div = (grpNum == 0UL) ? (1UL + (uint32_t)Cy_SysClk_ClkPeriGetDivider()) : 1U;
#endif
    hfNum = Cy_Sysclk_PeriPclkGetClkHfNum((uint32_t)ipBlock);
#endif

#if (defined (CY_IP_MXS40SRSS) && (defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION < 3U)))
        CY_ASSERT_L1(((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < PERI_PCLK_GR_DIV_8_NR(instNum, grpNum)))    || \
                     ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < PERI_PCLK_GR_DIV_16_NR(instNum, grpNum)))   || \
                     ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum))));
#else
        CY_ASSERT_L1(((dividerType == CY_SYSCLK_DIV_8_BIT)    && (dividerNum < PERI_PCLK_GR_DIV_8_NR(instNum, grpNum)))    || \
                     ((dividerType == CY_SYSCLK_DIV_16_BIT)   && (dividerNum < PERI_PCLK_GR_DIV_16_NR(instNum, grpNum)))   || \
                     ((dividerType == CY_SYSCLK_DIV_16_5_BIT) && (dividerNum < PERI_PCLK_GR_DIV_16_5_NR(instNum, grpNum))) || \
                     ((dividerType == CY_SYSCLK_DIV_24_5_BIT) && (dividerNum < PERI_PCLK_GR_DIV_24_5_NR(instNum, grpNum))));
#endif


#if !(defined (CY_IP_MXPERI) && (CY_IP_MXPERI_VERSION <= 2))
    if(hfNum != CY_SYSCLK_INVALID_HF_NUM)
#endif
    {
        freq = Cy_SysClk_ClkHfGetFrequency(hfNum); /* Get CLK_HF* frequency */
#if defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)
        /* get the peri clock tree frequency */
        freq = CY_SYSLIB_DIV_ROUND(freq, peri_div);
#endif
        /* get the divider value for clk_peri to the selected peripheral clock */
        switch(dividerType)
        {
            case CY_SYSCLK_DIV_8_BIT:
            case CY_SYSCLK_DIV_16_BIT:
                integer = 1UL + Cy_SysClk_PeriPclkGetDivider(ipBlock, dividerType, dividerNum);
                freq = CY_SYSLIB_DIV_ROUND(freq, integer);
                break;

            case CY_SYSCLK_DIV_16_5_BIT:
            case CY_SYSCLK_DIV_24_5_BIT:
                {
                    uint32_t locFrac = 0;
                    uint32_t locDiv = 0;
                    uint64_t locFreq = freq * 32ULL;
                    Cy_SysClk_PeriPclkGetFracDivider(ipBlock, dividerType, dividerNum, &integer, &locFrac);
                    /* For fractional dividers, the divider is (int + 1) + frac/32 */
                    locDiv = ((1UL + integer) * 32UL) + locFrac;
                    freq = (uint32_t) CY_SYSLIB_DIV_ROUND(locFreq, (uint64_t)locDiv);
                }
                break;

            default:
                /* Unknown Divider */
                break;
        }
    }
    CY_UNUSED_PARAMETER(clkCounting); /* Suppress a compiler warning about unused variables */
    CY_UNUSED_PARAMETER(instNum); /* Suppress a compiler warning about unused variables */
    CY_UNUSED_PARAMETER(grpNum); /* Suppress a compiler warning about unused variables */

    return (freq);
}
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.1')


/* ========================================================================== */
/* ===========================    CLKPWR SECTION    =========================== */
/* ========================================================================== */
#if (defined (CY_IP_MXS40SSRSS) && (CY_MXS40SSRSS_VER_1_2 > 0UL))

void Cy_SysClk_ClkPwrSetDivider(uint32_t divider)
{
    if (CY_SYSCLK_IS_CLKPWR_DIVIDER_VALID(divider))
    {
        CY_REG32_CLR_SET(PWRMODE_PWR_SELECT, PWRMODE_CLK_SELECT_CLK_PWR_DIV, divider - 1UL);
    }
}


uint32_t Cy_SysClk_ClkPwrGetDivider(void)
{
    return ((1UL + _FLD2VAL(PWRMODE_CLK_SELECT_CLK_PWR_DIV, PWRMODE_PWR_SELECT)));
}

uint32_t Cy_SysClk_ClkPwrGetFrequency(void)
{
    uint32_t pwrFreq = 0UL, pwrDiv;

      /* Get the frequency of the source */
        switch(Cy_SysClk_ClkPwrGetSource())
        {
            case CY_SYSCLK_CLKPWR_IN_IMO: /* The IMO frequency is fixed at 8 MHz */
                pwrFreq = CY_SYSCLK_IMO_FREQ;
                break;

            case CY_SYSCLK_CLKPWR_IN_IHO:
                pwrFreq = CY_SYSCLK_IHO_FREQ;
                break;

            default:
                /* Don't know the frequency of dsi_out, leave freq = 0UL */
                break;
        }

    pwrDiv = Cy_SysClk_ClkPwrGetDivider(); /* clkPwr prescaler (1-256) */

    /* Divide the path input frequency down and return the result */
    return (CY_SYSLIB_DIV_ROUND(pwrFreq, pwrDiv));
}


void Cy_SysClk_ClkPwrSetSource(cy_en_clkpwr_in_sources_t source)
{
    CY_ASSERT_L3(CY_SYSCLK_IF_CLKPWR_SOURCE_VALID(source));
    CY_REG32_CLR_SET(PWRMODE_PWR_SELECT, PWRMODE_CLK_SELECT_CLK_PWR_MUX, source);
}


cy_en_clkpwr_in_sources_t Cy_SysClk_ClkPwrGetSource(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_clkpwr_in_sources_t enum.');
    return ((cy_en_clkpwr_in_sources_t)(_FLD2VAL(PWRMODE_CLK_SELECT_CLK_PWR_MUX, PWRMODE_PWR_SELECT)));
}

#endif


#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3) && defined(SRSS_CSV_REF_CSV_REF_CTL))

/* ========================================================================== */
/* ===========================    CSV_REF SECTION  ========================== */
/* ========================================================================== */

uint32_t Cy_SysClk_ClkRefGetFrequency(void)
{
    uint32_t freq;
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_clkhf_csv_ref_clk_t enum.');
    cy_en_clkhf_csv_ref_clk_t monSrc = (cy_en_clkhf_csv_ref_clk_t) _FLD2VAL(SRSS_CSV_REF_SEL_REF_MUX, SRSS_CSV_REF_SEL);
    freq = Cy_SysClk_ClkHfCsvGetRefFrequency(monSrc);

    return (freq);
}

uint32_t Cy_SysClk_ClkRefCsvGetRefFrequency(cy_en_clkref_csv_ref_clk_t refClk)
 {
    uint32_t freq = 0UL;

    /* Get the frequency of the source  */
    switch(refClk)
     {
        case CY_SYSCLK_CLKREF_CSV_REF_ILO0:
            freq = (0UL != (SRSS_CLK_ILO0_CONFIG & SRSS_CLK_ILO0_CONFIG_ENABLE_Msk)) ? CY_SYSCLK_ILO_FREQ : 0UL;
            break;
        default:
            /* Don't know the frequency of dsi_out, leave freq = 0UL */
            break;
     }
    return (freq);
 }


cy_en_sysclk_status_t Cy_SysClk_ClkRefCsvManualConfigure(cy_en_clkref_csv_ref_clk_t refClk, const cy_stc_clkref_csv_manual_config_t * csvConfig)
{
    /* Check for errors */
    CY_ASSERT_L1(csvConfig != NULL);

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint32_t monitorFreq = Cy_SysClk_ClkRefGetFrequency();
    uint32_t refFreq = Cy_SysClk_ClkRefCsvGetRefFrequency(refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;

    CY_ASSERT_L1(csvConfig->upperLimit > CSV_MIN_TARGET_VAL);
    CY_ASSERT_L1(csvConfig->lowerLimit < csvConfig->upperLimit -1UL);
    CY_ASSERT_L1(monitorFreq > 0UL);
    CY_ASSERT_L1((int32_t) csvConfig->startTime >= (((int32_t)(((float32_t)(csvConfig->period +3UL)) * (f_refFreq / f_monitorFreq))) - ((int32_t)csvConfig->upperLimit)));

    (void) monitorFreq; /* Used only in Assert comparison. */
    (void) refFreq;  /* Used only in Assert comparison.  */
    (void) f_monitorFreq; /* Used only in Assert comparison. */
    (void) f_refFreq;  /* Used only in Assert comparison.  */

    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_REF_CTL, CSV_REF_CSV_REF_CTL_CSV_STARTUP, csvConfig->startTime - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_REF_LIMIT, CSV_REF_CSV_REF_LIMIT_CSV_LOWER, csvConfig->lowerLimit - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_REF_LIMIT, CSV_REF_CSV_REF_LIMIT_CSV_UPPER, csvConfig->upperLimit - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_MON_CTL, CSV_REF_CSV_MON_CTL_CSV_PERIOD, csvConfig->period - 1UL);
    retVal = CY_SYSCLK_SUCCESS;

    return retVal;
}


cy_en_sysclk_status_t Cy_SysClk_ClkRefCsvConfigure(cy_en_clkref_csv_ref_clk_t refClk, uint32_t accuracy)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    cy_stc_clkref_csv_manual_config_t csvConfig= {0, 0, 0, 0};

    float32_t target = (float32_t) CSV_MIN_TARGET_VAL;
    uint32_t monitorFreq = Cy_SysClk_ClkRefGetFrequency();
    uint32_t refFreq = Cy_SysClk_ClkRefCsvGetRefFrequency(refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;

    CY_ASSERT_L1(monitorFreq > 0UL);

    if(monitorFreq > 0UL && refFreq > 0UL)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.lowerLimit = (uint32_t) ((float32_t)target - (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F)));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.upperLimit = (uint32_t) ((float32_t)target + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F)));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.period =  (uint32_t) (((float32_t) target) / (f_refFreq / f_monitorFreq));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.startTime = (uint32_t) ((((float32_t)(csvConfig.period + 3UL)) * (f_refFreq / f_monitorFreq))
                                + (CSV_MIN_STARTUP_DELAY * f_refFreq)
                                + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F))) + 1U;

        retVal= Cy_SysClk_ClkRefCsvManualConfigure(refClk, &csvConfig);
    }

    return retVal;
}


void Cy_SysClk_ClkRefCsvAction(cy_en_clkref_csv_action_t action)
{
    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_REF_CTL, CSV_REF_CSV_REF_CTL_CSV_ACTION, action);
}


void Cy_SysClk_ClkRefCsvEnable(void)
{
    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_REF_CTL, CSV_REF_CSV_REF_CTL_CSV_EN, 1U);
}


void Cy_SysClk_ClkRefCsvDisable(void)
{
    CY_REG32_CLR_SET(SRSS_CSV_REF_CSV_REF_CTL, CSV_REF_CSV_REF_CTL_CSV_EN, 0U);
}


bool Cy_SysClk_IsClkRefCsvEnabled(void)
{
    return (0UL != (SRSS_CSV_REF_CSV_REF_CTL & CSV_REF_CSV_REF_CTL_CSV_EN_Msk));
}
#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3) && defined(SRSS_CSV_REF_CSV_REF_CTL)) */

#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3) && defined(SRSS_CSV_ILO_CSV_REF_CTL))

/* ========================================================================== */
/* ===========================    CSV_ILO SECTION  ========================== */
/* ========================================================================== */

uint32_t Cy_SysClk_ClkIloGetFrequency(void)
{
    uint32_t freq = 0UL;
    if (0UL != (SRSS_CLK_ILO0_CONFIG & SRSS_CLK_ILO0_CONFIG_ENABLE_Msk)) {
       freq = CY_SYSCLK_ILO_FREQ;
    }
    return (freq);
}

uint32_t Cy_SysClk_ClkIloCsvGetRefFrequency(cy_en_clkilo_csv_ref_clk_t refClk)
 {
    uint32_t freq;
    (void) refClk; /* Not used */

    freq =  Cy_SysClk_ClkLfGetFrequency();

    return (freq);
 }


cy_en_sysclk_status_t Cy_SysClk_ClkIloCsvManualConfigure(cy_en_clkilo_csv_ref_clk_t refClk, const cy_stc_clkilo_csv_manual_config_t * csvConfig)
{
    /* Check for errors */
    CY_ASSERT_L1(csvConfig != NULL);

    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    uint32_t monitorFreq = Cy_SysClk_ClkIloGetFrequency();
    uint32_t refFreq = Cy_SysClk_ClkIloCsvGetRefFrequency(refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;


    CY_ASSERT_L1(csvConfig->upperLimit > CSV_MIN_TARGET_VAL);
    CY_ASSERT_L1(csvConfig->lowerLimit < csvConfig->upperLimit -1UL);
    CY_ASSERT_L1(monitorFreq > 0UL);
    CY_ASSERT_L1((int32_t) csvConfig->startTime >= (((int32_t)(((float32_t)(csvConfig->period +3UL)) * (f_refFreq / f_monitorFreq))) - ((int32_t)csvConfig->upperLimit)));

    (void) monitorFreq; /* Used only in Assert comparison. */
    (void) refFreq;  /* Used only in Assert comparison.  */
    (void) f_monitorFreq; /* Used only in Assert comparison. */
    (void) f_refFreq;  /* Used only in Assert comparison.  */

    CY_REG32_CLR_SET(SRSS_CSV_ILO_CSV_REF_CTL, CSV_ILO_CSV_REF_CTL_CSV_STARTUP, csvConfig->startTime - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_ILO_CSV_REF_LIMIT, CSV_ILO_CSV_REF_LIMIT_CSV_LOWER, csvConfig->lowerLimit - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_ILO_CSV_REF_LIMIT, CSV_ILO_CSV_REF_LIMIT_CSV_UPPER, csvConfig->upperLimit - 1UL);
    CY_REG32_CLR_SET(SRSS_CSV_ILO_CSV_MON_CTL, CSV_ILO_CSV_MON_CTL_CSV_PERIOD, csvConfig->period - 1UL);
    retVal = CY_SYSCLK_SUCCESS;

    return retVal;
}


cy_en_sysclk_status_t Cy_SysClk_ClkIloCsvConfigure(cy_en_clkilo_csv_ref_clk_t refClk, uint32_t accuracy)
{
    cy_en_sysclk_status_t retVal = CY_SYSCLK_BAD_PARAM;
    cy_stc_clkilo_csv_manual_config_t csvConfig= {0, 0, 0, 0};

    uint32_t target = CSV_MIN_TARGET_VAL;
    uint32_t monitorFreq = Cy_SysClk_ClkIloGetFrequency();
    uint32_t refFreq = Cy_SysClk_ClkIloCsvGetRefFrequency(refClk);
    float32_t f_monitorFreq = (float32_t) monitorFreq;
    float32_t f_refFreq = (float32_t) refFreq;

    CY_ASSERT_L1(monitorFreq > 0UL);

    if(monitorFreq > 0UL && refFreq > 0UL)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.lowerLimit = (uint32_t) ((float32_t)target - (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F)));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.upperLimit = (uint32_t) ((float32_t)target + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F)));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.period =  (uint32_t) ((float32_t)target / (f_refFreq / f_monitorFreq));

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to uint32_t.');
        csvConfig.startTime = (uint32_t) ((((float32_t)(csvConfig.period + 3UL)) * (f_refFreq / f_monitorFreq))
                                + (CSV_MIN_STARTUP_DELAY * f_refFreq)
                                + (((float32_t)CSV_MIN_TARGET_VAL / 100.0F) * ((float32_t)accuracy / 2.0F))) + 1U;

        retVal= Cy_SysClk_ClkIloCsvManualConfigure(refClk, &csvConfig);
    }

    return retVal;
}


void Cy_SysClk_ClkIloCsvEnable(void)
{
    CY_REG32_CLR_SET(SRSS_CSV_ILO_CSV_REF_CTL, CSV_ILO_CSV_REF_CTL_CSV_EN, 1U);
}


void Cy_SysClk_ClkIloCsvDisable(void)
{
    CY_REG32_CLR_SET(SRSS_CSV_ILO_CSV_REF_CTL, CSV_ILO_CSV_REF_CTL_CSV_EN, 0U);
}


bool Cy_SysClk_IsClkIloCsvEnabled(void)
{
    return (0UL != (SRSS_CSV_ILO_CSV_REF_CTL & CSV_ILO_CSV_REF_CTL_CSV_EN_Msk));
}

#endif /* (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 3) && defined(SRSS_CSV_ILO_CSV_REF_CTL)) */

#endif /* defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS) */
/* [] END OF FILE */

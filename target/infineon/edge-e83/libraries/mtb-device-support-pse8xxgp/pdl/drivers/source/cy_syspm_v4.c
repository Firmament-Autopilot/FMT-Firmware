/***************************************************************************//**
* \file cy_syspm_v4.c
* \version 5.180
*
* This driver provides the source code for API power management.
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
#include "cy_sysclk.h"

#if defined (CY_IP_MXS22SRSS)

#include "cy_syspm.h"
#include "cy_syspm_ppu.h"
#include "cy_rram.h"
#include "cy_ipc_sema.h"
#include "mtb_srf.h"
#include "system_edge.h"

/*******************************************************************************
*       Internal Functions
*******************************************************************************/
#if defined (__ARMCC_VERSION)
static void __attribute__((optnone)) Cy_SysPm_SetTrimRamCtl(uint8_t index, uint32_t trimValue);
#endif

/*******************************************************************************
*       Internal Defines
*******************************************************************************/

/* The define for number of callback roots */
#define CALLBACK_ROOT_NR                (8U)

/* The mask to unlock the Hibernate power mode */
#define HIBERNATE_UNLOCK_VAL                 ((uint32_t) 0x3Au << SRSS_PWR_HIBERNATE_UNLOCK_Pos)

/* The mask to set the Hibernate power mode */
#define SET_HIBERNATE_MODE                   ((HIBERNATE_UNLOCK_VAL |\
                                               SRSS_PWR_HIBERNATE_FREEZE_Msk |\
                                               SRSS_PWR_HIBERNATE_HIBERNATE_Msk))

/* The mask to retain the Hibernate power mode status */
#define HIBERNATE_RETAIN_STATUS_MASK         ((SRSS_PWR_HIBERNATE_TOKEN_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBALARM_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBWDT_Msk |\
                                               SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBPIN_Msk))

/** The mask for the Hibernate wakeup sources */
#define HIBERNATE_WAKEUP_MASK               ((SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_CSV_BAK_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk))

/** The define to update the token to indicate the transition into Hibernate */
#define HIBERNATE_TOKEN                    ((uint32_t) CY_SYSLIB_HIBERNATE_TOKEN << SRSS_PWR_HIBERNATE_TOKEN_Pos)
/** The define to update the token to indicate the transition into DS OFF */
#define DS_OFF_TOKEN                       ((uint32_t)CY_SYSLIB_DEEP_SLEEP_OFF_TOKEN << SRSS_PWR_HIBERNATE_TOKEN_Pos)

/* The wait time for transition into the minimum regulator current mode
*/
#define SET_MIN_CURRENT_MODE_DELAY_US        (1U)

/* The wait delay time that occurs before the active reference is settled.
*  Intermediate delay is used in transition into the normal regulator current
*  mode, it should be two IHO cycles, which is (2 x 1/50000000)
*  = 1 micro second(Approximated)
*/
#define ACT_REF_SETTLE_DELAY_US              (1U)

/* The wait delay time that occurs after the active reference is settled.
*  Final delay is used in transition into the normal regulator current mode
*/
#define SET_NORMAL_CURRENT_MODE_DELAY_US     (1U)

/* The internal define of the tries number in the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function
*/
#define WAIT_DELAY_TRIES                (100U)

/* SRAM TRIM Values
*/
#define RAM_TRIM_VAL_A      0x0000000AU
#define RAM_TRIM_VAL_B      0x0000000BU
#define RAM_TRIM_VAL_C      0x0000000CU
#define RAM_TRIM_VAL_F      0x0000000FU
#define RAM_TRIM_VAL_1B     0x0000001BU
#define RAM_TRIM_VAL_2D     0x0000002DU
#define RAM_TRIM_VAL_3F     0x0000003FU
#define RAM_TRIM_VAL_202    0x00000202U
#define RAM_TRIM_VAL_203    0x00000203U
#define RAM_TRIM_VAL_204    0x00000204U
#define RAM_TRIM_VAL_206    0x00000206U
#define RAM_TRIM_VAL_207    0x00000207U
#define RAM_TRIM_VAL_20A    0x0000020AU
#define RAM_TRIM_VAL_20B    0x0000020BU
#define RAM_TRIM_VAL_20C    0x0000020CU
#define RAM_TRIM_VAL_20F    0x0000020FU
#define RAM_TRIM_VAL_21A    0x0000021AU
#define RAM_TRIM_VAL_21B    0x0000021BU
#define RAM_TRIM_VAL_21F    0x0000021FU
#define RAM_TRIM_VAL_22D    0x0000022DU
#define RAM_TRIM_VAL_23D    0x0000023DU
#define RAM_TRIM_VAL_23F    0x0000023FU
#define RAM_TRIM_VAL_342    0x00000342U
#define RAM_TRIM_VAL_343    0x00000343U
#define RAM_TRIM_VAL_603    0x00000603U
#define RAM_TRIM_VAL_604    0x00000604U
#define RAM_TRIM_VAL_605    0x00000605U
#define RAM_TRIM_VAL_606    0x00000606U
#define RAM_TRIM_VAL_607    0x00000607U
#define RAM_TRIM_VAL_60B    0x0000060BU
#define RAM_TRIM_VAL_60C    0x0000060CU
#define RAM_TRIM_VAL_60D    0x0000060DU
#define RAM_TRIM_VAL_60F    0x0000060FU
#define RAM_TRIM_VAL_61B    0x0000061BU
#define RAM_TRIM_VAL_61C    0x0000061CU
#define RAM_TRIM_VAL_61D    0x0000061DU
#define RAM_TRIM_VAL_61F    0x0000061FU
#define RAM_TRIM_VAL_62D    0x0000062DU
#define RAM_TRIM_VAL_63D    0x0000063DU
#define RAM_TRIM_VAL_63F    0x0000063FU
#define RAM_TRIM_VAL_743    0x00000743U
#define RAM_TRIM_VAL_E1F    0x00000E1FU
#define RAM_TRIM_VAL_E3F    0x00000E3FU
#define RAM_TRIM_VAL_1E3F   0x00001E3FU

/* Clock HF macros */
#define SYSPM_CLOCK_HF0_INDEX  0U
#define SYSPM_CLOCK_HF1_INDEX  1U
#define SYSPM_CLOCK_HF10_INDEX 10U

/*******************************************************************************
*       Internal Variables
*******************************************************************************/

/* Array of the callback roots */
static cy_stc_syspm_callback_t* pmCallbackRoot[CALLBACK_ROOT_NR] = {(void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U};

/* The array of the pointers to failed callback */
static cy_stc_syspm_callback_t* failedCallback[CALLBACK_ROOT_NR] = {(void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U, (void *)0U};

/** Holds DeepSleepMode. Updated by \ref Cy_SysPm_DeepSleepUpdate(). */
static uint32_t cy_DeepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
/*******************************************************************************
*    Secure Aware Support
*******************************************************************************/
#if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
typedef struct {
    cy_en_syspm_status_t retVal;
} cy_pdl_syspm_srf_status_out_t;

typedef struct {
    cy_en_syspm_waitfor_t waitFor;
} cy_pdl_syspm_srf_cpuentersleep_in_t;

typedef struct {
    cy_en_syspm_waitfor_t waitFor;
} cy_pdl_syspm_srf_cpuenterdeepsleep_in_t;

typedef struct {
    uint32_t mode;
} cy_pdl_syspm_srf_getprogrammedpwrmode_out_t;

typedef struct {
    uint32_t mode;
} cy_pdl_syspm_srf_setpwrmode_in_t;

typedef struct {
    bool retVal;
} cy_pdl_syspm_srf_islpmready_out_t;
#endif

#if defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
__WEAK mtb_srf_permission_s_t mtb_pdl_syspm_srf_cm55_permissions[] =
{
    {
        .base = MXCM55,
        .sub_block = 0,
        .write_allowed = true,
    },
};

__WEAK mtb_srf_permission_s_t mtb_pdl_syspm_srf_pwrmode_permissions[] =
{
    {
        .base = (void*)CY_PPU_MAIN_BASE,
        .sub_block = 0,
        .write_allowed = false,
    },
    {
        .base = (void*)CY_PPU_PD1_BASE,
        .sub_block = 0,
        .write_allowed = true,
    },
    {
        .base = (void*)CY_PPU_APPCPU_BASE,
        .sub_block = 0,
        .write_allowed = true,
    },
    {
        .base = (void*)CY_PPU_APPCPUSS_BASE,
        .sub_block = 0,
        .write_allowed = true,
    },
};

cy_rslt_t cy_pdl_syspm_srf_cpuentersleep_impl_s(mtb_srf_input_ns_t* inputs_ns,
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

    cy_rslt_t status;
    cy_pdl_syspm_srf_cpuentersleep_in_t input;
    cy_pdl_syspm_srf_status_out_t output;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.retVal = Cy_SysPm_CpuEnterSleep(input.waitFor);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}


cy_rslt_t cy_pdl_syspm_srf_cpuenterdeepsleep_impl_s(mtb_srf_input_ns_t* inputs_ns,
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

    cy_rslt_t status;
    cy_pdl_syspm_srf_cpuenterdeepsleep_in_t input;
    cy_pdl_syspm_srf_status_out_t output;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    output.retVal = Cy_SysPm_CpuEnterDeepSleep(input.waitFor);
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}


cy_rslt_t cy_pdl_syspm_srf_systementerhibernate_impl_s(mtb_srf_input_ns_t* inputs_ns,
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

    cy_rslt_t status;
    cy_pdl_syspm_srf_status_out_t output;
    output.retVal = Cy_SysPm_SystemEnterHibernate();
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_syspm_srf_getprogrammedpwrmode_impl_s(mtb_srf_input_ns_t* inputs_ns,
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

    cy_rslt_t status;
    cy_pdl_syspm_srf_getprogrammedpwrmode_out_t output;
    output.mode = (uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)((inputs_ns->request).base));
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_syspm_srf_setpwrmode_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(outputs_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    cy_rslt_t status;
    cy_pdl_syspm_srf_setpwrmode_in_t input;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)((inputs_ns->request).base), (uint32_t)input.mode);

    return status;
}

cy_rslt_t cy_pdl_syspm_srf_islpmready_impl_s(mtb_srf_input_ns_t* inputs_ns,
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

    cy_rslt_t status;
    cy_pdl_syspm_srf_islpmready_out_t output;
    output.retVal = Cy_SysPm_IsLpmReady();
    status = mtb_srf_copy_output_value(outputs_ns, &output, sizeof(output));

    return status;
}

cy_rslt_t cy_pdl_syspm_srf_syscm55enable_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(outputs_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    cy_rslt_t status;
    cy_pdl_syspm_srf_syscm55enable_in_t input;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    Cy_SysCM55Enable(
        #if defined(_CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55) && (_CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55)
        (MXCM55_Type *)((inputs_ns->request).base),
        #else
        (MXCM55_Type *)GET_NSALIAS_ADDRESS((inputs_ns->request).base),
        #endif
        input.vectorTableOffset,
        input.dbgMode,
        input.waitus);

    return status;
}


cy_rslt_t cy_pdl_syspm_srf_syscm55reset_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(outputs_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    cy_rslt_t status;
    cy_pdl_syspm_srf_syscm55reset_in_t input;
    status = mtb_srf_copy_input_value(&input, sizeof(input), inputs_ns);
    if (status != CY_RSLT_SUCCESS)
        return status;
    Cy_SysCM55Reset(
        #if defined(_CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55) && (_CY_PDL_SYSPM_PPC_SECURED_MXCM55_CM55)
        (MXCM55_Type *)((inputs_ns->request).base),
        #else
        (MXCM55_Type *)GET_NSALIAS_ADDRESS((inputs_ns->request).base),
        #endif
        input.waitus);

    return status;
}

cy_rslt_t cy_pdl_syspm_srf_syscm55disable_impl_s(mtb_srf_input_ns_t* inputs_ns,
                                            mtb_srf_output_ns_t* outputs_ns,
                                            mtb_srf_invec_ns_t* inputs_ptr_ns,
                                            uint8_t inputs_ptr_cnt_ns,
                                            mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                            uint8_t outputs_ptr_cnt_ns)
{
    CY_UNUSED_PARAMETER(inputs_ns);
    CY_UNUSED_PARAMETER(outputs_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_ns);
    CY_UNUSED_PARAMETER(inputs_ptr_cnt_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_ns);
    CY_UNUSED_PARAMETER(outputs_ptr_cnt_ns);

    Cy_SysCM55Disable();
    return (cy_rslt_t)CY_RSLT_SUCCESS;
}

/* All operations for the SYSPM submodule of the PDL module */
mtb_srf_op_s_t _cy_pdl_syspm_srf_operations[] =
{
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_CPUENTERSLEEP,
        .write_required = false,
        .impl = cy_pdl_syspm_srf_cpuentersleep_impl_s,
        .input_values_len = sizeof(cy_pdl_syspm_srf_cpuentersleep_in_t),
        .output_values_len = sizeof(cy_pdl_syspm_srf_status_out_t),
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = NULL,
        .num_allowed = 0UL,
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_CPUENTERDEEPSLEEP,
        .write_required = false,
        .impl = cy_pdl_syspm_srf_cpuenterdeepsleep_impl_s,
        .input_values_len = sizeof(cy_pdl_syspm_srf_cpuenterdeepsleep_in_t),
        .output_values_len = sizeof(cy_pdl_syspm_srf_status_out_t),
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = NULL,
      .num_allowed = 0UL,
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_SYSTEMENTERHIBERNATE,
        .write_required = false,
        .impl = cy_pdl_syspm_srf_systementerhibernate_impl_s,
        .input_values_len = 0UL,
        .output_values_len = sizeof(cy_pdl_syspm_srf_status_out_t),
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = NULL,
        .num_allowed = 0UL,
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_GETPROGRAMMEDPWRMODE,
        .write_required = false,
        .impl = cy_pdl_syspm_srf_getprogrammedpwrmode_impl_s,
        .input_values_len = 0UL,
        .output_values_len = sizeof(cy_pdl_syspm_srf_getprogrammedpwrmode_out_t),
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = mtb_pdl_syspm_srf_pwrmode_permissions,
        .num_allowed = (sizeof(mtb_pdl_syspm_srf_pwrmode_permissions)/sizeof(mtb_pdl_syspm_srf_pwrmode_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_SETPWRMODE,
        .write_required = false,
        .impl = cy_pdl_syspm_srf_setpwrmode_impl_s,
        .input_values_len = sizeof(cy_pdl_syspm_srf_setpwrmode_in_t),
        .output_values_len = 0UL,
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = mtb_pdl_syspm_srf_pwrmode_permissions,
        .num_allowed = (sizeof(mtb_pdl_syspm_srf_pwrmode_permissions)/sizeof(mtb_pdl_syspm_srf_pwrmode_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_ISLPMREADY,
        .write_required = false,
        .impl = cy_pdl_syspm_srf_islpmready_impl_s,
        .input_values_len = 0UL,
        .output_values_len = sizeof(cy_pdl_syspm_srf_islpmready_out_t),
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = NULL,
        .num_allowed = 0UL,
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_SYSCM55ENABLE,
        .write_required = true,
        .impl = cy_pdl_syspm_srf_syscm55enable_impl_s,
        .input_values_len = sizeof(cy_pdl_syspm_srf_syscm55enable_in_t),
        .output_values_len = 0UL,
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = mtb_pdl_syspm_srf_cm55_permissions,
        .num_allowed = (sizeof(mtb_pdl_syspm_srf_cm55_permissions)/sizeof(mtb_pdl_syspm_srf_cm55_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_SYSCM55RESET,
        .write_required = true,
        .impl = cy_pdl_syspm_srf_syscm55reset_impl_s,
        .input_values_len = sizeof(cy_pdl_syspm_srf_syscm55reset_in_t),
        .output_values_len = 0UL,
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = mtb_pdl_syspm_srf_cm55_permissions,
        .num_allowed = (sizeof(mtb_pdl_syspm_srf_cm55_permissions)/sizeof(mtb_pdl_syspm_srf_cm55_permissions[0]))
    },
    {
        .module_id = MTB_SRF_MODULE_PDL,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .op_id = CY_PDL_SYSPM_OP_SYSCM55DISABLE,
        .write_required = true,
        .impl = cy_pdl_syspm_srf_syscm55disable_impl_s,
        .input_values_len = 0UL,
        .output_values_len = 0UL,
        .input_len ={ 0UL, 0UL, 0UL },
        .needs_copy = { false, false, false },
        .output_len ={ 0UL, 0UL, 0UL },
        .allowed_rsc = NULL,
        .num_allowed = 0UL,
    },
};

#endif /* defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */

void Cy_SysPm_Init(void)
{
    /* Set Default mode to DEEPSLEEP */
    (void)Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP);

#if !defined (CY_PDL_TZ_ENABLED)
    cy_en_ipcsema_status_t ipcStatus;
    /* Initialize IP Semaphore */
    ipcStatus = Cy_IPC_Sema_Init(IPC0_SEMA_CH_NUM, 0UL, NULL);
    CY_ASSERT_L2(CY_IPC_SEMA_SUCCESS == ipcStatus);
    (void) ipcStatus; /* Suppress 'unused variable' warning */
#endif
}

void Cy_SysPm_DeepSleepSetup(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    cy_DeepSleepMode = (uint32_t) deepSleepMode;
}

void Cy_SysPm_DeepSleepUpdate(void)
{
    cy_DeepSleepMode = (uint32_t) Cy_SysPm_GetDeepSleepMode();
    // Currently CM33_S doesn't reference cy_DeepSleepMode (avoid compiler error)
    CY_UNUSED_PARAMETER(cy_DeepSleepMode);
}

cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(cy_en_syspm_waitfor_t waitFor)
{
    uint32_t interruptState;
    uint32_t cbSleepRootIdx = (uint32_t) CY_SYSPM_SLEEP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_WAIT_FOR_VALID(waitFor));

    /* Call registered callback functions with CY_SYSPM_CHECK_READY parameter */
    if (pmCallbackRoot[cbSleepRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_READY);
    }

    /* The CPU can switch into the Sleep power mode only when
    *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55)
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        cy_rslt_t result = CY_RSLT_SUCCESS;

        result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
        if (result != CY_RSLT_SUCCESS)
        {
            return CY_SYSPM_FAIL;
        }
        #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55) */

        /* Call the registered callback functions with
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_BEFORE_TRANSITION);
        }

        #if defined(COMPONENT_SECURE_DEVICE) || !defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || (CY_CPU_CORTEX_M55)
        /* The CPU enters the Sleep power mode upon execution of WFI/WFE */
        SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;
        __DSB();                   /* Ensure completion of memory access */

        if(waitFor != CY_SYSPM_WAIT_FOR_EVENT)
        {
            __WFI();
        }
        else
        {
            __WFE();
        }

        /* Clear SCB_SCR_SLEEPDEEP flag */
        SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;
        #else
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_syspm_srf_cpuentersleep_in_t input_args;
        cy_pdl_syspm_srf_status_out_t output_args;
        input_args.waitFor = waitFor;
        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSPM_OP_CPUENTERSLEEP,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
            .base = NULL,
            .sub_block = 0UL,
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
        memcpy(&output_args, &(output->output_values[0]), sizeof(output_args));
        retVal = output_args.retVal;
        #endif /* defined(COMPONENT_SECURE_DEVICE) || !defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || (CY_CPU_CORTEX_M55) */

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        *  CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_AFTER_TRANSITION);
        }

        #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55)
        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);
        #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55) */
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SetSysDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    switch(deepSleepMode)
    {
        case CY_SYSPM_MODE_DEEPSLEEP:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE, (uint32_t)CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE, (uint32_t)CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE, (uint32_t)CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */

            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_RAM:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE, (uint32_t)CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE, (uint32_t)CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE, (uint32_t)CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */

#if (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_ICACTIVE_Msk);
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_DCACTIVE_Msk);
            EWIC_EWCI_ASCR &= ~(EWIC_EWIC_ASCR_ASPU_Msk);
#endif

            retVal = CY_SYSPM_SUCCESS;
        }

        break;

        case CY_SYSPM_MODE_DEEPSLEEP_OFF:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE, (uint32_t)CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE, (uint32_t)CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE, (uint32_t)CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */

#if (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_ICACTIVE_Msk);
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_DCACTIVE_Msk);
            EWIC_EWCI_ASCR &= ~(EWIC_EWIC_ASCR_ASPU_Msk);
#endif

            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retVal = CY_SYSPM_BAD_PARAM;
        break;
    }
    return retVal;
}

cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetSysDeepSleepMode(void)
{
    uint32_t mode;
    cy_en_syspm_deep_sleep_mode_t deepSleepMode;

    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    cy_rslt_t retVal = CY_RSLT_SUCCESS;
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;

    retVal = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);

    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_getprogrammedpwrmode_out_t output_args;
    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_GETPROGRAMMEDPWRMODE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .base = (void*)CY_PPU_MAIN_BASE,
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
    retVal = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    memcpy((void*)&output_args, (void*)&(output->output_values[0]), sizeof(output_args));
    mode = output_args.mode;

    retVal = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(retVal);
    #else
    mode = (uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE);
    #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */

    switch(mode)
    {
        case (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
        }
        break;

        case (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_RAM;
        }
        break;

        case (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_OFF;
        }
        break;

        default:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_NONE;
        }
        break;
    }

    return deepSleepMode;
}

cy_en_syspm_status_t Cy_SysPm_SetAppDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;

    result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_setpwrmode_in_t input_args;
    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_SETPWRMODE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
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
    #endif

    switch(deepSleepMode)
    {
        case CY_SYSPM_MODE_DEEPSLEEP:
        {
            #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
            input_args.mode = CY_SYSTEM_PD1_PPU_DEEPSLEEP_MODE;
            invoke_args.base = (void*)CY_PPU_PD1_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            input_args.mode = CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_MODE;
            invoke_args.base = (void*)CY_PPU_APPCPU_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            input_args.mode = CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_MODE;
            invoke_args.base = (void*)CY_PPU_APPCPUSS_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            #else
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPUSS_BASE, (uint32_t)CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            #endif

            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_RAM:
        {
            #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
            input_args.mode = CY_SYSTEM_PD1_PPU_DEEPSLEEP_RAM_MODE;
            invoke_args.base = (void*)CY_PPU_PD1_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            input_args.mode = CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_RAM_MODE;
            invoke_args.base = (void*)CY_PPU_APPCPU_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            input_args.mode = CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_RAM_MODE;
            invoke_args.base = (void*)CY_PPU_APPCPUSS_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            #else
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPUSS_BASE, (uint32_t)CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            #endif

#if (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_ICACTIVE_Msk);
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_DCACTIVE_Msk);
            EWIC_EWCI_ASCR &= ~(EWIC_EWIC_ASCR_ASPU_Msk);
#endif

            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_OFF:
        {
            #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
            input_args.mode = CY_SYSTEM_PD1_PPU_DEEPSLEEP_OFF_MODE;
            invoke_args.base = (void*)CY_PPU_PD1_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            input_args.mode = CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_OFF_MODE;
            invoke_args.base = (void*)CY_PPU_APPCPU_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            input_args.mode = CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_OFF_MODE;
            invoke_args.base = (void*)CY_PPU_APPCPUSS_BASE;
            result = _Cy_PDL_Invoke_SRF(&invoke_args);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            #else
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPUSS_BASE, (uint32_t)CY_SYSTEM_APPCPUSS_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            #endif

#if (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_ICACTIVE_Msk);
            MEM_CTL_MSCR &= ~(MEMSYSCTL_MSCR_DCACTIVE_Msk);
            EWIC_EWCI_ASCR &= ~(EWIC_EWIC_ASCR_ASPU_Msk);
#endif

            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retVal = CY_SYSPM_BAD_PARAM;
        break;
    }

    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(result);
    #endif

    return retVal;
}

cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetAppDeepSleepMode(void)
{
    uint32_t mode;
    cy_en_syspm_deep_sleep_mode_t deepSleepMode;

    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    cy_rslt_t retVal = CY_RSLT_SUCCESS;
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;

    retVal = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);

    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_getprogrammedpwrmode_out_t output_args;
    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_GETPROGRAMMEDPWRMODE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .base = (void*)CY_PPU_PD1_BASE,
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
    retVal = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    memcpy((void*)&output_args, (void*)&(output->output_values[0]), sizeof(output_args));
    mode = output_args.mode;

    retVal = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(retVal);
    #else
    mode = (uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE);
    #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */

    switch(mode)
    {
        case (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_MODE:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
        }
        break;

        case (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_RAM_MODE:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_RAM;
        }
        break;

        case (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_OFF_MODE:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_OFF;
        }
        break;

        default:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_NONE;
        }
        break;
    }

    return deepSleepMode;
}


cy_en_syspm_status_t Cy_SysPm_SetDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    #if (defined (CY_CPU_CORTEX_M33) && CY_CPU_CORTEX_M33)
        return Cy_SysPm_SetSysDeepSleepMode(deepSleepMode);
    #elif (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)
        return Cy_SysPm_SetAppDeepSleepMode(deepSleepMode);
    #else
        return Cy_SysPm_SetSysDeepSleepMode(deepSleepMode);
    #endif
}

cy_en_syspm_status_t Cy_SysPm_SetPPUDeepSleepMode(uint32_t ppu, uint32_t mode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    if(cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)ppu) == PPU_V1_MODE_ON)
    {
        (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)ppu, (uint32_t)mode); /* Suppress a compiler warning about unused return value */
        retVal = CY_SYSPM_SUCCESS;
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SetSOCMEMDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    switch(deepSleepMode)
    {
        case CY_SYSPM_MODE_DEEPSLEEP:
        {
            if(cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE) == PPU_V1_MODE_ON)
            {
                (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            }
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_RAM:
        {
            if(cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE) == PPU_V1_MODE_ON)
            {
                (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            }
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_OFF:
        {
            if(cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE) == PPU_V1_MODE_ON)
            {
                (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            }
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retVal = CY_SYSPM_BAD_PARAM;
        break;
    }
    return retVal;
}


cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetDeepSleepMode(void)
{
    cy_en_syspm_deep_sleep_mode_t deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
    uint32_t mode;

    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    cy_rslt_t retVal = CY_RSLT_SUCCESS;
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;

    retVal = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);

    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_getprogrammedpwrmode_out_t output_args;
    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_GETPROGRAMMEDPWRMODE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .base = (void*)CY_PPU_MAIN_BASE,
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
    retVal = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    memcpy((void*)&output_args, (void*)&(output->output_values[0]), sizeof(output_args));
    mode = output_args.mode;

    retVal = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(retVal);
    #else
    mode = (uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE);
    #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */

    #if (defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55)
    #if defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    uint32_t pd1_mode;

    retVal = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);

    invoke_args.base = (void*)CY_PPU_PD1_BASE;
    retVal = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    memcpy((void*)&pd1_mode, (void*)&(output->output_values[0]), sizeof(pd1_mode));
    mode |= (pd1_mode << 8U);

    retVal = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(retVal == CY_RSLT_SUCCESS);
    CY_UNUSED_PARAMETER(retVal);
    #else
    mode |= ((uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE) << 8U);
    #endif /* defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */
    #endif /* defined (CY_CPU_CORTEX_M55) && CY_CPU_CORTEX_M55) */

    switch(mode)
    {
        case CY_SYSTEM_DEEPSLEEP_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
        }
        break;

        case CY_SYSTEM_DEEPSLEEP_RAM_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_RAM;
        }
        break;

        case CY_SYSTEM_DEEPSLEEP_OFF_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_OFF;
        }
        break;

        default:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_NONE;
        }
        break;
    }

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_deep_sleep_mode_t enum.');
    return deepSleepMode;
}

cy_en_syspm_boot_mode_t Cy_SysPm_GetBootMode(void)
{
    uint32_t resCause, resCause2;
    cy_en_syspm_boot_mode_t deepSleepWakeMode = CY_SYSPM_POR_BOOT_MODE;

    resCause = SRSS_RES_CAUSE;
    resCause2 = SRSS_RES_CAUSE2;

    if((resCause == 0UL) || (resCause2 == 0UL))
    {
        switch(Cy_SysPm_GetDeepSleepMode())
        {
            case CY_SYSPM_MODE_DEEPSLEEP_RAM:
            {
                deepSleepWakeMode = CY_SYSPM_WARM_BOOT_MODE;
            }
            break;

            case CY_SYSPM_MODE_DEEPSLEEP_OFF:
            {
                deepSleepWakeMode = CY_SYSPM_COLD_BOOT_MODE;
            }
            break;

            default:
            {
                deepSleepWakeMode = CY_SYSPM_POR_BOOT_MODE;
            }
            break;
        }

    }

    return ((cy_en_syspm_boot_mode_t)deepSleepWakeMode);
}

cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(cy_en_syspm_waitfor_t waitFor)
{
    uint32_t interruptState;
    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    uint32_t cbDeepSleepRootIdx = cy_DeepSleepMode;
    #else
    uint32_t cbDeepSleepRootIdx = (uint32_t) Cy_SysPm_GetDeepSleepMode();
    #endif
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_WAIT_FOR_VALID(waitFor));
    CY_ASSERT_L3(CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(cbDeepSleepRootIdx));

    //Check if LPM is ready
    #if !(!defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG))
    if(!Cy_SysPm_IsLpmReady())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    #endif
    {
        /* Call the registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_READY);
        }

        /* The CPU can switch into the Deep Sleep power mode only when
        *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter return CY_SYSPM_SUCCESS
        */
        if (retVal == CY_SYSPM_SUCCESS)
        {
            #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55)
            mtb_srf_invec_ns_t* inVec = NULL;
            mtb_srf_outvec_ns_t* outVec = NULL;
            cy_rslt_t result = CY_RSLT_SUCCESS;

            result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
            if (result != CY_RSLT_SUCCESS)
            {
                return CY_SYSPM_FAIL;
            }
            #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55) */
            /* Call the registered callback functions with the
            * CY_SYSPM_BEFORE_TRANSITION parameter
            */
            interruptState = Cy_SysLib_EnterCriticalSection();
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION);
            }

            #if defined(COMPONENT_SECURE_DEVICE) || !defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || (CY_CPU_CORTEX_M55)
            // TODO: CM55 may have to handle SRSS_PWR_HIBERNATE case via IPC-SRF
            /* Preserve the token that will be retained through a wakeup sequence.
            * This could be used by Cy_SysLib_GetResetReason() to differentiate
            * Wakeup from a general reset event.
            */
            if ((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_OFF == cbDeepSleepRootIdx)
            {
                SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE  | DS_OFF_TOKEN);
            }

            /* The CPU enters Deep Sleep mode upon execution of WFI/WFE
             * use Cy_SysPm_SetDeepSleepMode to set various deepsleep modes */
            SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;
            __DSB();                   /* Ensure completion of memory access */

            /* Disable FPU for DS-RAM/DS-OFF Entry to work*/
            if(((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_RAM == cbDeepSleepRootIdx) || ((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_OFF == cbDeepSleepRootIdx))
            {
                SCS_CPPWR |= (SCS_ENABLE_CPPWR_SU10_SU11);
                SCB_CPACR &= ~(SCB_ENABLE_CPACR_CP10_CP11);
                __DSB();                   /* Ensure completion of memory access */
            }

            #if (defined (CY_IP_MXS22SRSS_VERSION) && defined (CY_IP_MXS22SRSS_VERSION_MINOR)) && \
             ((CY_IP_MXS22SRSS_VERSION == 1) && (CY_IP_MXS22SRSS_VERSION_MINOR == 0))
            Cy_SysPm_SetRamTrimsPreDs();
            #endif /* ((CY_IP_MXS22SRSS_VERSION == 1) && (CY_IP_MXS22SRSS_VERSION_MINOR == 0)) */
            if(waitFor != CY_SYSPM_WAIT_FOR_EVENT)
            {
                __WFI();
            }
            else
            {
                __WFE();
            }
            #if (defined (CY_IP_MXS22SRSS_VERSION) && defined (CY_IP_MXS22SRSS_VERSION_MINOR)) && \
             ((CY_IP_MXS22SRSS_VERSION == 1) && (CY_IP_MXS22SRSS_VERSION_MINOR == 0))
            Cy_SysPm_SetRamTrimsPostDs();
            #endif /* ((CY_IP_MXS22SRSS_VERSION == 1) && (CY_IP_MXS22SRSS_VERSION_MINOR == 0)) */

            /* Enable back FPU if it was used in case of DS-RAM/DS-OFF.
             *
             * This is not required for DS-RAM/DS-OFF because device should go to reset after __WFI.
             * If requirements for entering into DS-RAM/DS-OFF were not met (for example, active debug session),
             * the device will operate as in normal deep sleep mode.
             * Because of that FPU is re-enabling.
             */
            if(((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_RAM == cbDeepSleepRootIdx) || ((uint32_t)CY_SYSPM_MODE_DEEPSLEEP_OFF == cbDeepSleepRootIdx))
            {
                SCS_CPPWR &= ~(SCS_ENABLE_CPPWR_SU10_SU11);
                SCB->CPACR |= SCB_ENABLE_CPACR_CP10_CP11;
                __DSB();                   /* Ensure completion of memory access */
            }

            /* Clear SCB_SCR_SLEEPDEEP flag */
            SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;

            #else
            mtb_srf_output_ns_t* output = NULL;
            cy_pdl_syspm_srf_cpuenterdeepsleep_in_t input_args;
            cy_pdl_syspm_srf_status_out_t output_args;
            input_args.waitFor = waitFor;
            cy_pdl_invoke_srf_args invoke_args =
            {
                .inVec = inVec,
                .outVec = outVec,
                .output_ptr = &output,
                .op_id = CY_PDL_SYSPM_OP_CPUENTERDEEPSLEEP,
                .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
                .base = NULL,
                .sub_block = 0UL,
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
            memcpy(&output_args, &(output->output_values[0]), sizeof(output_args));
            retVal = output_args.retVal;
            #endif /* defined(COMPONENT_SECURE_DEVICE) || !defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || (CY_CPU_CORTEX_M55) */


            Cy_SysLib_ExitCriticalSection(interruptState);

            /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_AFTER_TRANSITION);
            }

            #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55)
            result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
            CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
            CY_UNUSED_PARAMETER(result);
            #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55) */
        }
        else
        {
            /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
            *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_FAIL);
            }
        }
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterHibernate(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    const uint32_t cbHibernateRootIdx = (uint32_t) CY_SYSPM_HIBERNATE;
    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into Hibernate power mode only when
    *  all executed registered callback functions with CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55)
        mtb_srf_invec_ns_t* inVec = NULL;
        mtb_srf_outvec_ns_t* outVec = NULL;
        cy_rslt_t result = CY_RSLT_SUCCESS;

        result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
        if (result != CY_RSLT_SUCCESS)
        {
            return CY_SYSPM_FAIL;
        }
        #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55) */
        /* Call registered callback functions with CY_SYSPM_BEFORE_TRANSITION
        *  parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_BEFORE_TRANSITION);
        }

        #if defined(COMPONENT_SECURE_DEVICE) || !defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || (CY_CPU_CORTEX_M55)
        /* Preserve the token that will be retained through a wakeup sequence.
         * This could be used by Cy_SysLib_GetResetReason() to differentiate
         * Wakeup from a general reset event.
         * Preserve the wakeup source(s) configuration.
         */
        SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE  | HIBERNATE_TOKEN);

        /* Clear Previous Wakeup Reasons */
        Cy_SysPm_ClearHibernateWakeupCause();

        /* Disable overriding by the peripherals the next pin-freeze command */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* The second write causes freezing of I/O cells to save the I/O-cell state */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* Third write cause system to enter Hibernate */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* Read register to make sure it is settled */
        (void) SRSS_PWR_HIBERNATE;

        /* Wait for transition */
        __WFI();

        /* The callback function calls with the CY_SYSPM_AFTER_TRANSITION
        * parameter in the Hibernate power mode are not applicable as system
        * wake-up was made on system reboot.
        */

        /* A wakeup from Hibernate is performed by toggling of the wakeup
        * pins, or WDT matches, or Backup domain alarm expires. This depends on
        * what item is configured in the Hibernate register. After a wakeup
        * event, a normal Boot procedure occurs.
        * There is no need to exit from the critical section.
        */
        #else
        mtb_srf_output_ns_t* output = NULL;
        cy_pdl_syspm_srf_status_out_t output_args;
        cy_pdl_invoke_srf_args invoke_args =
        {
            .inVec = inVec,
            .outVec = outVec,
            .output_ptr = &output,
            .op_id = CY_PDL_SYSPM_OP_SYSTEMENTERHIBERNATE,
            .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
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
        CY_UNUSED_PARAMETER(result);
        memcpy(&output_args, &(output->output_values[0]), sizeof(output_args));
        retVal = output_args.retVal;
        #endif /* defined(COMPONENT_SECURE_DEVICE) || !defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) || (CY_CPU_CORTEX_M55) */

        Cy_SysLib_ExitCriticalSection(interruptState);
        /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION parameter */
        if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_AFTER_TRANSITION);
        }

        #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55)
        result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
        CY_ASSERT_L2(result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(result);
        #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) && !(CY_CPU_CORTEX_M55) */
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter. The return value should be CY_SYSPM_SUCCESS.
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemSetMinRegulatorCurrent(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_CANCELED;

    /* Check if the power circuits are ready to enter into regulator minimum
    *  current mode
    */
    if (Cy_SysPm_IsLpmReady())
    {
        SRSS_PWR_CTL2 |= (SRSS_PWR_CTL2_BGREF_LPMODE_Msk |
                          SRSS_PWR_CTL2_PORBOD_LPMODE_Msk);

        /* This wait time allows the circuits to remove their dependence on
        *  the Active mode circuits, such as active Reference
        */
        Cy_SysLib_DelayUs(SET_MIN_CURRENT_MODE_DELAY_US);

        /* Disable active reference */
        SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_REFSYS_VBUF_DIS_Msk;

        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;


}

cy_en_syspm_status_t Cy_SysPm_SystemSetNormalRegulatorCurrent(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;

    uint32_t timeOut = WAIT_DELAY_TRIES;

    /* Configure the regulator normal current mode for the POR/BOD circuits
    *  and for the Voltage References
    */

    /* Bring Regulators Power Circuit out of LPMODE */
    SRSS_PWR_CTL2 &= (uint32_t)~(SRSS_PWR_CTL2_REFSYS_VBUF_DIS_Msk      |
                                 SRSS_PWR_CTL2_PORBOD_LPMODE_Msk);

    /* This wait time allows setting active Reference */
    Cy_SysLib_DelayUs(ACT_REF_SETTLE_DELAY_US);

    while ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFSYS_VREF_OK, SRSS_PWR_CTL2)) && (0U != timeOut))
    {
        timeOut--;
    }

    if (0U != timeOut)
    {
        /* Disable the low-power for Bandgap reference circuit */
        SRSS_PWR_CTL2 &= (uint32_t) ~SRSS_PWR_CTL2_BGREF_LPMODE_Msk;

        /* Delay to finally set the normal current mode */
        Cy_SysLib_DelayUs(SET_NORMAL_CURRENT_MODE_DELAY_US);

        retVal= CY_SYSPM_SUCCESS;
    }

    return retVal;

}


cy_en_syspm_status_t Cy_SysPm_LdoSetMode(cy_en_syspm_ldo_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_LDO_MODE_VALID(mode));

    cy_en_syspm_status_t retVal = CY_SYSPM_CANCELED;

    switch (mode)
    {
        case CY_SYSPM_LDO_MODE_NORMAL:
        {
            retVal = Cy_SysPm_SystemSetNormalRegulatorCurrent();
        }
        break;

        case CY_SYSPM_LDO_MODE_MIN:
        {
            retVal = Cy_SysPm_SystemSetMinRegulatorCurrent();
        }
        break;

        default:
            retVal = CY_SYSPM_FAIL;
        break;
    }

    return retVal;
}


void Cy_SysPm_SetHibernateWakeupSource(uint32_t wakeupSource)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource));

    uint32_t polarityMask = 0U;
    uint32_t wakeSrcMask = 0U;

    /* LPCOMP0 & LPCOMP1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK;
    }

    /* PIN0 & PIN1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN1_MASK;
    }

    /* RTC */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_RTC_MASK;
    }

    /* WDT */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_WDT))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_WDT_MASK;
    }

    /* Polarity Mask */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK;
    }

    SRSS_PWR_HIB_WAKE_CTL = (SRSS_PWR_HIB_WAKE_CTL | wakeSrcMask);
    SRSS_PWR_HIB_WAKE_CTL2 = (SRSS_PWR_HIB_WAKE_CTL2 | polarityMask);

    /* Read registers to make sure it is settled */
    (void) SRSS_PWR_HIB_WAKE_CTL;
    (void) SRSS_PWR_HIB_WAKE_CTL2;

}

void Cy_SysPm_ClearHibernateWakeupSource(uint32_t wakeupSource)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource));

    uint32_t polarityMask = 0U;
    uint32_t wakeSrcMask = 0U;

    /* LPCOMP0 & LPCOMP1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK;
    }

    /* PIN0 & PIN1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN1_MASK;
    }

    /* RTC */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_RTC_MASK;
    }

    /* WDT */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_WDT))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_WDT_MASK;
    }

    /* Polarity Mask */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK;
    }

    SRSS_PWR_HIB_WAKE_CTL = (SRSS_PWR_HIB_WAKE_CTL & (~wakeSrcMask));
    SRSS_PWR_HIB_WAKE_CTL2 = (SRSS_PWR_HIB_WAKE_CTL2 & (~polarityMask));

    /* Read registers to make sure it is settled */
    (void) SRSS_PWR_HIB_WAKE_CTL;
    (void) SRSS_PWR_HIB_WAKE_CTL2;
}

cy_en_syspm_hibernate_wakeup_source_t Cy_SysPm_GetHibernateWakeupCause(void)
{
    uint32_t wakeupCause;
    uint32_t wakeupCausePolarity;

    wakeupCause = SRSS_PWR_HIB_WAKE_CAUSE;

    wakeupCausePolarity = (wakeupCause & (uint32_t)(CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK |
                                          CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK |
                                          CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    |
                                          CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK ));

    switch(wakeupCause)
    {
        case CY_SYSPM_HIB_WAKEUP_PIN0_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_PIN1_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_RTC_MASK:
        {
            wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM);
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_WDT_MASK:
        {
            wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_WDT);
        }
        break;

        default:
            CY_ASSERT_L2(false);
        break;
    }

    return (cy_en_syspm_hibernate_wakeup_source_t)wakeupCause;
}

cy_en_syspm_status_t Cy_SysPm_RetLdoStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_RETLDO_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_DelayUs(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_RetLdoConfigure(cy_stc_syspm_retldo_params_t *retLdoParam)
{
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_VOLTAGE_VALID(retLdoParam->activeVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_VOLTAGE_VALID(retLdoParam->deepsleepVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_GAIN_VALID(retLdoParam->activeGain));
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_GAIN_VALID(retLdoParam->deepsleepGain));

    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_LVL, retLdoParam->activeVoltSel);
    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_GAIN, retLdoParam->activeGain);

    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_LVL_DPSLP, retLdoParam->deepsleepVoltSel);
    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_GAIN_DPSLP, retLdoParam->deepsleepGain);

    return Cy_SysPm_RetLdoStatus();
}

cy_en_syspm_status_t Cy_SysPm_SramLdoStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_SRAMLDO_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_DelayUs(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SramLdoConfigure(cy_stc_syspm_sramldo_params_t *sramLdoParam)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SRAMLDO_VOLTAGE_VALID(sramLdoParam->sramLdoVoltSel));

    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_EN, (sramLdoParam->sramLdoEnable ? 1U : 0U));

    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_DPSLP_EN, (sramLdoParam->deepsleepSramLdoEnable ? 1U : 0U));

    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_VOUT, sramLdoParam->sramLdoVoltSel);

    return Cy_SysPm_SramLdoStatus();
}

cy_en_syspm_status_t Cy_SysPm_MiscLdoStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_MISCLDO_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_DelayUs(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_US);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_MiscLdoConfigure(cy_stc_syspm_miscldo_params_t *miscLdoParam)
{
    CY_ASSERT_L2(CY_SYSPM_IS_MISCLDO_VOLTAGE_VALID(miscLdoParam->miscLdoVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_MISCLDO_VCCACT_TRIM_VALID(miscLdoParam->miscLdoVaccActTrimSel));
    CY_ASSERT_L2(CY_SYSPM_IS_MISCLDO_MODE_VALID(miscLdoParam->miscLdoMode));

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_EN, (miscLdoParam->miscLdoEnable ? 1U : 0U));

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_MODE, miscLdoParam->miscLdoMode);

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_VOUT, miscLdoParam->miscLdoVoltSel);

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_VCCACT_TRIM, miscLdoParam->miscLdoVaccActTrimSel);

    return Cy_SysPm_MiscLdoStatus();
}

bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t* handler)
{
    bool retVal = false;

    /* Verify the input parameters. */
    if ((handler != NULL) && (handler->callbackParams != NULL) && (handler->callback != NULL))
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;

        /* If the callback list is not empty. */
        if (pmCallbackRoot[callbackRootIdx] != NULL)
        {
            cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];
            cy_stc_syspm_callback_t* insertPos  = curCallback;

            /* Find the callback after which the new callback is to be
             * inserted. Ensure the given callback has not been registered.
             */
            while ((NULL != curCallback->nextItm) && (curCallback != handler))
            {
                curCallback = curCallback->nextItm;
                /* Callbacks with the same order value are stored in the order
                 * they are registered.
                 */
                if (curCallback->order <= handler->order)
                {
                    insertPos = curCallback;
                }
            }
            /* If the callback has not been registered. */
            if (curCallback != handler)
            {
                /* If the callback is to be inserted at the beginning of the list. */
                if ((insertPos->prevItm == NULL) && (handler->order < insertPos->order))
                {
                    handler->nextItm = insertPos;
                    handler->prevItm = NULL;
                    handler->nextItm->prevItm = handler;
                    pmCallbackRoot[callbackRootIdx] = handler;
                }
                else
                {
                    handler->nextItm = insertPos->nextItm;
                    handler->prevItm = insertPos;

                    /* If the callback is not inserted at the end of the list. */
                    if (handler->nextItm != NULL)
                    {
                        handler->nextItm->prevItm = handler;
                    }
                    insertPos->nextItm = handler;
                }
                retVal = true;
            }
        }
        else
        {
            /* The callback list is empty. */
            pmCallbackRoot[callbackRootIdx] = handler;
            handler->nextItm = NULL;
            handler->prevItm = NULL;
            retVal = true;
        }
    }
    return retVal;
}

bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler)
{
    bool retVal = false;

    if (handler != NULL)
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;
        cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];

        /* Search requested callback item in the linked list */
        while (curCallback != NULL)
        {
            /* Requested callback is found */
            if (curCallback == handler)
            {
                retVal = true;
                break;
            }

            /* Go to next callback item in the linked list */
            curCallback = curCallback->nextItm;
        }

        if (retVal)
        {
            /* Requested callback is first in the list */
            if (pmCallbackRoot[callbackRootIdx] == handler)
            {
                /* Check whether this the only callback registered */
                if (pmCallbackRoot[callbackRootIdx]->nextItm != NULL)
                {
                    pmCallbackRoot[callbackRootIdx] = pmCallbackRoot[callbackRootIdx]->nextItm;
                    pmCallbackRoot[callbackRootIdx]->prevItm = NULL;
                }
                else
                {
                    /* We had only one callback */
                    pmCallbackRoot[callbackRootIdx] = NULL;
                }
            }
            else
            {
                /* Update links of related to unregistered callback items */
                curCallback->prevItm->nextItm = curCallback->nextItm;

                if (curCallback->nextItm != NULL)
                {
                    curCallback->nextItm->prevItm = curCallback->prevItm;
                }
            }
        }
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_TYPE_VALID(type));
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_MODE_VALID(mode));

    static cy_stc_syspm_callback_t* lastExecutedCallback = NULL;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[(uint32_t) type];
    cy_stc_syspm_callback_params_t curParams;

    if ((mode == CY_SYSPM_BEFORE_TRANSITION) || (mode == CY_SYSPM_CHECK_READY))
    {
        /* Execute registered callbacks with order from first registered to the
        *  last registered. Stop executing if CY_SYSPM_FAIL was returned in
        *  CY_SYSPM_CHECK_READY mode
        */
        while ((curCallback != NULL) && ((retVal != CY_SYSPM_FAIL) || (mode != CY_SYSPM_CHECK_READY)))
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);

                /* Update callback pointer with value of executed callback.
                * Such update is required to execute further callbacks in
                * backward order after exit from LP mode or to undo
                * configuration after callback returned fail: from last called
                * to first registered.
                */
                lastExecutedCallback = curCallback;
            }
            curCallback = curCallback->nextItm;
        }

        if (mode == CY_SYSPM_CHECK_READY)
        {
            /* Update the pointer to  the failed callback with the result of the callback execution.
            *  If the callback fails, the value of the pointer will be updated
            *  with the address of the callback which returned CY_SYSPM_FAIL, else,
            *  it will be updated with NULL.
            */
            if(retVal == CY_SYSPM_FAIL)
            {
                failedCallback[(uint32_t) type] = lastExecutedCallback;
            }
            else
            {
                failedCallback[(uint32_t) type] = NULL;
            }
        }
    }
    else
    {
        /* Execute registered callbacks with order from lastCallback or last
        * executed to the first registered callback. Such a flow is required if
        * a previous callback function returned CY_SYSPM_FAIL or a previous
        * callback mode was CY_SYSPM_BEFORE_TRANSITION. Such an order is
        * required to undo configurations in correct backward order.
        */
        if (mode != CY_SYSPM_CHECK_FAIL)
        {
            while (curCallback->nextItm != NULL)
            {
                curCallback = curCallback->nextItm;
            }
        }
        else
        {
            /* Skip last executed callback that returns CY_SYSPM_FAIL, as this
            *  callback already knows that it failed.
            */
            curCallback = lastExecutedCallback;

            if (curCallback != NULL)
            {
                curCallback = curCallback->prevItm;
            }
        }

        /* Execute callback functions with required type and mode */
        while (curCallback != NULL)
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);
            }
            curCallback = curCallback->prevItm;
        }
    }

    return retVal;
}

cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type)
{
    return failedCallback[(uint32_t) type];
}

void Cy_SysPm_IoUnfreeze(void)
{
    uint32_t interruptState;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Preserve the last reset reason and wakeup polarity. Then, unfreeze I/O:
     * write PWR_HIBERNATE.FREEZE=0, .UNLOCK=0x3A, .HIBERNATE=0
     */
    SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE & HIBERNATE_RETAIN_STATUS_MASK) | HIBERNATE_UNLOCK_VAL;

    /* Lock the Hibernate mode:
    * write PWR_HIBERNATE.HIBERNATE=0, UNLOCK=0x00, HIBERNATE=0
    */
    SRSS_PWR_HIBERNATE &= HIBERNATE_RETAIN_STATUS_MASK;

    /* Read register to make sure it is settled */
    (void) SRSS_PWR_HIBERNATE;

    Cy_SysLib_ExitCriticalSection(interruptState);
}


void Cy_SysPm_DeepSleepIoUnfreeze(void)
{
    uint32_t interruptState;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Unfreeze IO's which are frozen during DEEPSLEEP-RAM/OFF
    * Entry
    */
    /* For PD0 */
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_FREEZE_DPSLP_Msk;

    /* For PD1 */
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_FREEZE_DPSLP_PD1_Msk;

    Cy_SysLib_ExitCriticalSection(interruptState);
}

bool Cy_SysPm_DeepSleepIoIsFrozen(void)
{
    return ((0U != _FLD2VAL(SRSS_PWR_CTL2_FREEZE_DPSLP, SRSS_PWR_CTL2)) || (0U != _FLD2VAL(SRSS_PWR_CTL2_FREEZE_DPSLP_PD1, SRSS_PWR_CTL2)));
}


bool Cy_SysPm_IsLpmReady(void)
{
    #if !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, CY_PDL_SYSPM_SRF_POOL_TIMEOUT);
    if (result != CY_RSLT_SUCCESS)
    {
        return false;
    }
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_islpmready_out_t output_args;
    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_ISLPMREADY,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
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
    memcpy((void*)&output_args, (void*)&(output->output_values[0]), sizeof(output_args));

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(result == CY_RSLT_SUCCESS);

    return output_args.retVal;
    #else
    return (_FLD2BOOL(SRSS_PWR_CTL_LPM_READY, SRSS_PWR_CTL)? true : false);
    #endif /* !defined(COMPONENT_SECURE_DEVICE) && defined(CY_PDL_SYSPM_ENABLE_SRF_INTEG) */
}

cy_en_syspm_status_t Cy_SysPm_SetSOCMemPartActivePwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum, cy_en_syspm_socmem_sram_pwr_mode_t socmemSramPwrMode)
{
    CY_ASSERT_L3((socmemSramPwrMode == CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_ON) || (socmemSramPwrMode == CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_OFF));
    CY_ASSERT_L3(socmemSramPartNum < CY_SOCMEM_PARTITION_NR);

    /* Unlock PWR Partition Control */
    /* Clear bit 0(CLR0)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR1;

    switch(socmemSramPwrMode)
    {
        case CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_ON:
        {
            CY_REG32_CLR_SET(SOCMEM_PWR_PARTITION_CTL(socmemSramPartNum), SOCMEM_PWR_PARTITION_CTL_ACT_OFF,  0UL);
        }
        break;

        case CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_OFF:
        {
            CY_REG32_CLR_SET(SOCMEM_PWR_PARTITION_CTL(socmemSramPartNum), SOCMEM_PWR_PARTITION_CTL_ACT_OFF,  1UL);
        }
        break;

        default:
        {
            CY_ASSERT_L3(false);
        }
        break;
    }

    /* Wait for the PWR_DONE status */
    while(!_FLD2BOOL(SOCMEM_PWR_STATUS_PWR_DONE, SOCMEM_PWR_STATUS)){}

    /* Lock PWR Partition Control(Set SET01) */
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_SET01;

    return CY_SYSPM_SUCCESS;
}

cy_en_syspm_status_t Cy_SysPm_SetSOCMemPartDsPwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum, cy_en_syspm_socmem_sram_pwr_mode_t socmemSramPwrMode)
{
    CY_ASSERT_L3((socmemSramPwrMode == CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_ON) || (socmemSramPwrMode == CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_OFF));
    CY_ASSERT_L3(socmemSramPartNum < CY_SOCMEM_PARTITION_NR);

    /* Unlock PWR Partition Control */
    /* Clear bit 0(CLR0)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR1;

    switch(socmemSramPwrMode)
    {
        case CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_ON:
        {
            CY_REG32_CLR_SET(SOCMEM_PWR_PARTITION_CTL(socmemSramPartNum), SOCMEM_PWR_PARTITION_CTL_RET_OFF,  0UL);
        }
        break;

        case CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_OFF:
        {
            CY_REG32_CLR_SET(SOCMEM_PWR_PARTITION_CTL(socmemSramPartNum), SOCMEM_PWR_PARTITION_CTL_RET_OFF,  1UL);
        }
        break;

        default:
        {
            CY_ASSERT_L3(false);
        }
        break;
    }

    /* Lock PWR Partition Control(Set SET01) */
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_SET01;

    return CY_SYSPM_SUCCESS;
}


cy_en_syspm_socmem_sram_pwr_mode_t Cy_SysPm_GetSOCMemSramPartActivePwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum)
{
    cy_en_syspm_socmem_sram_pwr_mode_t value;

    CY_ASSERT_L3(socmemSramPartNum < CY_SOCMEM_PARTITION_NR);

    /* Unlock PWR Partition Control */
    /* Clear bit 0(CLR0)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR1;


    value = (((SOCMEM_PWR_PARTITION_CTL(socmemSramPartNum) & (SOCMEM_PWR_PARTITION_CTL_ACT_OFF_Msk)) != 0UL) ? CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_OFF:CY_SYSPM_SOCMEM_SRAM_ACTIVE_MODE_ON);

    /* Lock PWR Partition Control(Set SET01) */
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_SET01;

    return value;
}

cy_en_syspm_socmem_sram_pwr_mode_t Cy_SysPm_GetSOCMemSramPartDsPwrMode(cy_en_syspm_socmem_sram_partition_index_t socmemSramPartNum)
{
    cy_en_syspm_socmem_sram_pwr_mode_t value;

    CY_ASSERT_L3(socmemSramPartNum < CY_SOCMEM_PARTITION_NR);

    /* Unlock PWR Partition Control */
    /* Clear bit 0(CLR0)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_CLR1;


    value = (((SOCMEM_PWR_PARTITION_CTL(socmemSramPartNum) & (SOCMEM_PWR_PARTITION_CTL_RET_OFF_Msk)) != 0UL) ? CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_OFF:CY_SYSPM_SOCMEM_SRAM_DS_MODE_RET_ON);

    /* Lock PWR Partition Control(Set SET01) */
    SOCMEM_PWR_PARTITION_CTL_LOCK = SOCMEM_PWR_PARTITION_CTL_LOCK_SET01;

    return value;
}


/* This API is an inline version of Cy_SysPm_SetSRAMMacroPwrMode */
__STATIC_FORCEINLINE cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrModeInline(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    CY_ASSERT_L3((sramNum == CY_SYSPM_SRAM0_MEMORY) || (sramNum == CY_SYSPM_SRAM1_MEMORY));
    CY_ASSERT_L3((sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON) || (sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_OFF));
    CY_ASSERT_L3(sramMacroNum < CY_CPUSS_RAMC_MACRO_NR(sramNum));

    /* Unlock PWR MACRO Control */
    /* Clear bit 0(CLR0)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum) = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum) = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1;

    if(sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON)
    {
        /* Enable the Macro Number */
        MXSRAMC_PWR_MACRO_CTL(sramNum) &= ~(0x1UL << (uint32_t)sramMacroNum);
    }
    else
    {
        /* Disable the Macro Number */
        MXSRAMC_PWR_MACRO_CTL(sramNum) |= (0x1UL << (uint32_t)sramMacroNum);
    }
    /* Wait for the PWR_DONE status */
    while(!_FLD2BOOL(RAMC_STATUS_PWR_DONE, MXSRAMC_STATUS(sramNum))){}

    /* Lock PWR MACRO Control(Set SET01) */
    MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum) = MXSRAMC_PWR_MACRO_CTL_LOCK_SET01;

    return CY_SYSPM_SUCCESS;
}

cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    return Cy_SysPm_SetSRAMMacroPwrModeInline(sramNum, sramMacroNum, sramPwrMode);
}

cy_en_syspm_sram_pwr_mode_t Cy_SysPm_GetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum)
{
    cy_en_syspm_sram_pwr_mode_t value;

    CY_ASSERT_L3((sramNum == CY_SYSPM_SRAM0_MEMORY) || (sramNum == CY_SYSPM_SRAM1_MEMORY));
    CY_ASSERT_L3(sramMacroNum < CY_CPUSS_RAMC_MACRO_NR(sramNum));

    /* Unlock PWR MACRO Control */
    /* Clear bit 0(CLR0)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum) = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum) = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1;

    value = (((MXSRAMC_PWR_MACRO_CTL(sramNum) & (0x1UL << (uint32_t)sramMacroNum)) != 0UL) ? CY_SYSPM_SRAM_PWR_MODE_OFF:CY_SYSPM_SRAM_PWR_MODE_ON);

    /* Lock PWR MACRO Control(Set SET01) */
    MXSRAMC_PWR_MACRO_CTL_LOCK(sramNum) = MXSRAMC_PWR_MACRO_CTL_LOCK_SET01;

    return value;

}


cy_en_syspm_status_t Cy_SysPm_SetSRAMPwrMode(cy_en_syspm_sram_index_t sramNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    uint8_t macroNum;
    CY_ASSERT_L3((sramNum == CY_SYSPM_SRAM0_MEMORY) || (sramNum == CY_SYSPM_SRAM1_MEMORY));
    CY_ASSERT_L3((sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON) || (sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_OFF));

    for(macroNum = 0; (macroNum < CY_CPUSS_RAMC_MACRO_NR(sramNum));macroNum++)
    {
        (void)Cy_SysPm_SetSRAMMacroPwrMode(sramNum, (uint32_t)macroNum, sramPwrMode);
    }

    return CY_SYSPM_SUCCESS;
}

void Cy_SysPm_TriggerSoftReset(void)
{
    SRSS_RES_SOFT_CTL = SRSS_RES_SOFT_CTL_TRIGGER_SOFT_Msk;
}

void Cy_SysPm_TriggerXRes(void)
{
    SRSS_RES_PXRES_CTL = SRSS_RES_PXRES_CTL_PXRES_TRIGGER_Msk;
}

bool Cy_SysPm_IsSystemLp(void)
{
    return(CY_SYSPM_CORE_BUCK_PROFILE_LP == Cy_SysPm_CoreBuckGetProfile());
}

bool Cy_SysPm_IsSystemUlp(void)
{
    return(CY_SYSPM_CORE_BUCK_PROFILE_ULP == Cy_SysPm_CoreBuckGetProfile());
}

bool Cy_SysPm_IsSystemHp(void)
{
    return(CY_SYSPM_CORE_BUCK_PROFILE_HP == Cy_SysPm_CoreBuckGetProfile());
}

static void Cy_SysPm_SetTrimRamCtl(uint8_t index, uint32_t trimValue)
{
    SRSS_TRIM_RAM_CTL(index) = trimValue;
}

static void Cy_SysPm_SystemEnterHpToDs(void)
{
    uint32_t clkHfMask = Cy_SysClk_ClkHfAllGetMask();
    /* HP to DS Sequence */
    /* HP->DS(1) */
    /* Change HP frequency to 50MHz */
    Cy_SysClk_ClkHfEnableDirectMuxWithMask(clkHfMask, true);

    /* HP->DS(2) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_60B);

    /* HP->DS(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_E1F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_61F);

    /* HP->DS(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_1E3F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_E3F);

    /* HP->DS(5) */
    /* Change frequency to 4MHz */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_DIVIDE_BY_12); */
}

static void Cy_SysPm_SystemEnterDsToHp(void)
{
    uint32_t clkHfMask = Cy_SysClk_ClkHfAllGetMask();
    /* DS to HP Sequence */
    /* DS->HP(2) */
    /* Change frequency to 50MHz */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_NO_DIVIDE); */

    /* DS->HP(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_E1F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_61F);

    /* DS->HP(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_60B);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_20B);

    /* DS->HP(5) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_202);

    /* DS->HP(6) */
    /* Change frequency to HP Frequency */
    Cy_SysClk_ClkHfEnableDirectMuxWithMask(clkHfMask, false);
}

static void Cy_SysPm_SystemEnterLpToDs(void)
{
    uint32_t clkHfMask = Cy_SysClk_ClkHfAllGetMask();
    /* LP to DS Sequence */
    /* LP->DS(1) */
    /* Change LP frequency to 50MHz */
    Cy_SysClk_ClkHfEnableDirectMuxWithMask(clkHfMask, true);

    /* LP->DS(2) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_60D);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_60D);

    /* LP->DS(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_E1F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_61F);

    /* LP->DS(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_1E3F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_E3F);

    /* LP->DS(5) */
    /* Change frequency to 4MHz */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_DIVIDE_BY_12); */
}

static void Cy_SysPm_SystemEnterDsToLp(void)
{
    uint32_t clkHfMask = Cy_SysClk_ClkHfAllGetMask();
    /* DS to LP Sequence */
    /* DS->LP(2) */
    /* Change frequency to 50MHz */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_NO_DIVIDE); */

    /* DS->LP(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_E1F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_61F);

    /* DS->LP(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_60D);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_60D);

    /* DS->LP(5) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_604);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_604);

    /* DS->LP(6) */
    /* Change frequency to LP Frequency */
    Cy_SysClk_ClkHfEnableDirectMuxWithMask(clkHfMask, false);
}


static void Cy_SysPm_SystemEnterUlpToDs(void)
{
    uint32_t clkHfMask = Cy_SysClk_ClkHfAllGetMask();

    /* ULP to DS Sequence */
    /* ULP->DS(1) */
    /* Change ULP frequency to 25MHz */
    Cy_SysClk_ClkHfEnableDirectMuxWithMask(clkHfMask, true);
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_DIVIDE_BY_2); */

    /* ULP->DS(2) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_60F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_60F);

    /* ULP->DS(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_E1F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_61F);

    /* ULP->DS(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_1E3F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_E3F);

    /* ULP->DS(5) */
    /* Change frequency to 4MHz */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_DIVIDE_BY_12); */
}

static void Cy_SysPm_SystemEnterDsToUlp(void)
{
    uint32_t clkHfMask = Cy_SysClk_ClkHfAllGetMask();
    /* DS to ULP Sequence */
    /* DS->ULP(2) */
    /* Change frequency to 25MHz */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_DIVIDE_BY_2); */

    /* DS->ULP(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_E1F);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_61F);

    /* DS->ULP(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_60B);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_60B);

    /* DS->ULP(5) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_603);
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_603);

    /* DS->ULP(6) */
    /* Change frequency to ULP Frequency */
    /* Revisit this code during B0 */
    /* Cy_SysClk_ClkHfEnableDividerWithMask(clkHfMask, CY_SYSCLK_CLKHF_NO_DIVIDE); */
    Cy_SysClk_ClkHfEnableDirectMuxWithMask(clkHfMask, false);
}

void Cy_SysPm_SetRamTrimsPreDs(void)
{
    while (CY_IPC_SEMA_STATUS_LOCKED == Cy_IPC_Sema_Status(CY_SYSPM_SEMA_NUM_MULTI_CORE)){}
    (void)Cy_IPC_Sema_Set(CY_SYSPM_SEMA_NUM_MULTI_CORE, false);

#if (CY_CPU_CORTEX_M33)
    if(Cy_SysPm_Cm55IsDeepSleep())
#endif
#if (CY_CPU_CORTEX_M55)
    if(Cy_SysPm_Cm33IsDeepSleep())
#endif
    {
        if(Cy_SysPm_IsSystemHp())
        {
            Cy_SysPm_SystemEnterHpToDs();
        }
        else if(Cy_SysPm_IsSystemLp())
        {
            Cy_SysPm_SystemEnterLpToDs();
        }
        else if(Cy_SysPm_IsSystemUlp())
        {
            Cy_SysPm_SystemEnterUlpToDs();
        }
        else
        {
            /* Do Nothing */
        }
    }

    (void)Cy_IPC_Sema_Clear(CY_SYSPM_SEMA_POST_TRIM_STATUS, false);

    (void)Cy_IPC_Sema_Clear(CY_SYSPM_SEMA_NUM_MULTI_CORE, false);
}

void Cy_SysPm_SetRamTrimsPostDs(void)
{
    while (CY_IPC_SEMA_STATUS_LOCKED == Cy_IPC_Sema_Status(CY_SYSPM_SEMA_NUM_MULTI_CORE)){}
    (void)Cy_IPC_Sema_Set(CY_SYSPM_SEMA_NUM_MULTI_CORE, false);

    if (CY_IPC_SEMA_STATUS_UNLOCKED == Cy_IPC_Sema_Status(CY_SYSPM_SEMA_POST_TRIM_STATUS)){}
    {
        if(Cy_SysPm_IsSystemHp())
        {
            Cy_SysPm_SystemEnterDsToHp();
        }
        else if(Cy_SysPm_IsSystemLp())
        {
            Cy_SysPm_SystemEnterDsToLp();
        }
        else if(Cy_SysPm_IsSystemUlp())
        {
            Cy_SysPm_SystemEnterDsToUlp();
        }
        else
        {
            /* Do Nothing */
        }

        (void)Cy_IPC_Sema_Set(CY_SYSPM_SEMA_POST_TRIM_STATUS, false);
    }

    (void)Cy_IPC_Sema_Clear(CY_SYSPM_SEMA_NUM_MULTI_CORE, false);
}

cy_en_syspm_status_t Cy_SysPm_SystemTransitionHpToLp(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* HP to LP Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */

    /* 2) Retention Level change */

    /* 3) Reduce the frequency so it is at least ??% (400MHz to <=75MHz) below the static timing closure limits at the new voltage setting for SRAM timing margin */
    /* Frequency Reduction needs to be done before calling this API */


    /* 4) SRAM trim updates - HP->LP(2) through HP->LP(5) */

    /* HP->LP(2) */
    Cy_SysPm_SetTrimRamCtl(0U, RAM_TRIM_VAL_343);
    Cy_SysPm_SetTrimRamCtl(1U, RAM_TRIM_VAL_343);

    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_206);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_206);

    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_20F);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_20F);

    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_3F);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_3F);

    Cy_SysPm_SetTrimRamCtl(8U, RAM_TRIM_VAL_B);

    /* HP->LP(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_204);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_204);

    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_20C);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_20C);

    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_2D);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_2D);

    /* HP->LP(4) */
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_204);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_204);

    /* HP->LP(5) */
    Cy_SysPm_SetTrimRamCtl(0U, RAM_TRIM_VAL_743);
    Cy_SysPm_SetTrimRamCtl(1U, RAM_TRIM_VAL_743);

    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_604);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_604);

    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_22D);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_22D);

    /* 5) Change the voltage */
    Cy_SysPm_CoreBuckSetProfile(CY_SYSPM_CORE_BUCK_PROFILE_LP);

    if(CY_SYSPM_SUCCESS != Cy_SysPm_CoreBuckStatus())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* 6) SRAM trim updates - HP->LP(7) */
        /* HP->LP(7) */
        Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_604);
        Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_604);

        /* 7) M33 send IPC to m0seccpuss - Voltage at target level */

        /* 8) Change RRAM to LP mode  */
        /* Moved to callback */

        /* 9) Change Frequency  */
        /* Frequency Change needs to be done after calling this API */

        /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
    }


    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemTransitionLpToHp(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* LP to HP Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */

    /* 2) Retention Level change */

    /* 3) Reduce frequency by at least 38% (120MHz to <=75MHz) for SRAM timing margin */
    /* Frequency Reduction needs to be done before calling this API */

    /* 4) SRAM trim updates - LP->HP(2) through LP->HP(5) */

    /* LP->HP(2) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_606);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_606);

    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_606);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_606);

    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_23F);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_23F);

    /* LP->HP(3) */
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_607);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_607);

    /* LP->HP(4) */
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_60F);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_60F);

    /* LP->HP(5) */
    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_20F);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_20F);

    /* 5) Change the voltage */
    Cy_SysPm_CoreBuckSetProfile(CY_SYSPM_CORE_BUCK_PROFILE_HP);

    if(CY_SYSPM_SUCCESS != Cy_SysPm_CoreBuckStatus())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* 6) SRAM trim updates - LP->HP(7) & LP->HP(8) */
        /* LP->HP(7) */
        Cy_SysPm_SetTrimRamCtl(0U, RAM_TRIM_VAL_343);
        Cy_SysPm_SetTrimRamCtl(1U, RAM_TRIM_VAL_343);

        Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_206);
        Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_206);

        Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_3F);
        Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_3F);

        Cy_SysPm_SetTrimRamCtl(8U, RAM_TRIM_VAL_A);

        /* LP->HP(8) */
        Cy_SysPm_SetTrimRamCtl(0U, RAM_TRIM_VAL_342);
        Cy_SysPm_SetTrimRamCtl(1U, RAM_TRIM_VAL_342);

        Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_202);
        Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_202);

        Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_20B);
        Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_20B);

        Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_1B);
        Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_1B);

        /* 7) M33 send IPC to m0seccpuss - Voltage at target level */

        /* 8) Change RRAM to LP mode  */
        /* Moved to callback */

        /* 9) Change Frequency  */
        /* Frequency Change needs to be done after calling this API */

        /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
    }


    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemTransitionUlpToLp(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* ULP to LP Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */

    /* 2) Retention Level change */

    /* 3) ULP->LP(1), Reduce frequency by at least 18% (50MHz to <= 41MHz) for SRAM timing margin */
    /* Frequency Reduction needs to be done before calling this API */

    /* 4) SRAM trim updates - ULP->LP(3) through ULP->LP(5) */

    /* ULP->LP(3) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_607);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_607);

    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_607);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_607);

    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_63D);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_63D);

    Cy_SysPm_SetTrimRamCtl(8U, RAM_TRIM_VAL_F);

    /* ULP->LP(4) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_606);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_606);

    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_606);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_606);

    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_62D);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_62D);

    Cy_SysPm_SetTrimRamCtl(8U, RAM_TRIM_VAL_B);

    /* ULP->LP(5) */
    Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_604);
    Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_604);

    Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_604);
    Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_604);

    /* 5) Change the voltage */
    Cy_SysPm_CoreBuckSetProfile(CY_SYSPM_CORE_BUCK_PROFILE_LP);

    if(CY_SYSPM_SUCCESS != Cy_SysPm_CoreBuckStatus())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* 5.1 Disable the SRAMLDO allowing CBUCK to supply SRAM Core */
        retVal = Cy_SysPm_SramLdoEnable(false);

        if(CY_SYSPM_SUCCESS != retVal)
        {
            retVal = CY_SYSPM_FAIL;
        }
        else
        {
            /* 6) SRAM trim updates - ULP->LP(7) */
            Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_22D);
            Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_22D);

            /* 7) M33 send IPC to m0seccpuss - Voltage at target level */

           /* 8) Change RRAM to LP mode  */
           /* Moved to callback */

            /* 9) Change Frequency  */
            /* Frequency Change needs to be done after calling this API */

            /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
        }
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemTransitionLpToUlp(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* LP to ULP Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */

    /* 2) Retention Level change */

    /* 3) Reduce the operating frequency so it is at least 66% (120MHz to 41MHz) */
    /* Frequency Reduction needs to be done before calling this API */

    /* 4) SRAM trim updates - ULP->LP(3) through ULP->LP(5) */
    /* LP->ULP(2) */
    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_23D);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_23D);

    Cy_SysPm_SetTrimRamCtl(8U, RAM_TRIM_VAL_F);

    /* LP->ULP(3) */
    Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_63D);
    Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_63D);

    /* 5) Change the voltage */
    /* 5.1 Enable the SRAMLDO to supply SRAM Core  */
    retVal = Cy_SysPm_SramLdoEnable(true);

    if(CY_SYSPM_SUCCESS != retVal)
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* 5.2 Select the ULP voltage profile */
        Cy_SysPm_CoreBuckSetProfile(CY_SYSPM_CORE_BUCK_PROFILE_ULP);

        if(CY_SYSPM_SUCCESS != Cy_SysPm_CoreBuckStatus())
        {
            retVal = CY_SYSPM_FAIL;
        }
        else
        {
            /* 6) SRAM trim updates - LP->ULP(5) & LP->ULP(7) */
            /* LP->ULP(5) */
            Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_606);
            Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_606);

            Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_606);
            Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_606);

            Cy_SysPm_SetTrimRamCtl(6U, RAM_TRIM_VAL_61D);
            Cy_SysPm_SetTrimRamCtl(7U, RAM_TRIM_VAL_61D);

            Cy_SysPm_SetTrimRamCtl(8U, RAM_TRIM_VAL_C);

            /* LP->ULP(6) */
            Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_607);
            Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_607);

            Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_607);
            Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_607);

            /* LP->ULP(7) */
            Cy_SysPm_SetTrimRamCtl(2U, RAM_TRIM_VAL_603);
            Cy_SysPm_SetTrimRamCtl(3U, RAM_TRIM_VAL_603);

            Cy_SysPm_SetTrimRamCtl(4U, RAM_TRIM_VAL_603);
            Cy_SysPm_SetTrimRamCtl(5U, RAM_TRIM_VAL_603);

            /* 7) M33 send IPC to m0seccpuss - Voltage at target level */

            /* 8) Change RRAM to ULP mode  */
            /* Moved to callback */

            /* 9) Change Frequency  */
            /* Frequency Change needs to be done after calling this API */

            /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
        }
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterHp(void)
{
    uint32_t interruptState;
    const uint32_t cbLpRootIdx = (uint32_t) CY_SYSPM_HP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbLpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_HP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into LP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {

        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbLpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HP, CY_SYSPM_BEFORE_TRANSITION);
        }

        if(Cy_SysPm_IsSystemLp())
        {
           (void) Cy_SysPm_SystemTransitionLpToHp();
        }
        else if(Cy_SysPm_IsSystemUlp())
        {
            (void) Cy_SysPm_SystemTransitionUlpToLp();
            (void) Cy_SysPm_SystemTransitionLpToHp();
        }
        else
        {
            /*Block added to avoid MISRA errors */
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbLpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SystemEnterUlp(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    const uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_ULP;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the ULP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_BEFORE_TRANSITION);
        }

        if(Cy_SysPm_IsSystemLp())
        {
           (void) Cy_SysPm_SystemTransitionLpToUlp();
        }
        else if(Cy_SysPm_IsSystemHp())
        {
           (void) Cy_SysPm_SystemTransitionHpToLp();
           (void) Cy_SysPm_SystemTransitionLpToUlp();
        }
        else
        {
           /*Block added to avoid MISRA errors */
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SystemEnterLp(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    const uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_LP;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the ULP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_BEFORE_TRANSITION);
        }

        if(Cy_SysPm_IsSystemHp())
        {
           (void) Cy_SysPm_SystemTransitionHpToLp();
        }
        else if(Cy_SysPm_IsSystemUlp())
        {
           (void) Cy_SysPm_SystemTransitionUlpToLp();
        }
        else
        {
            /*Block added to avoid MISRA errors */
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}


uint32_t Cy_SysPm_ReadStatus(void)
{
    uint32_t pmStatus = 0UL;

    /* Check whether the device is in ULP/LP/HP mode by reading
    *  the core buck profile:
    *  - 0.7V (nominal) - System ULP mode
    *  - 0.8V (nominal) - System LP mode
    *  - 0.9V (nominal) - System HP mode
    */

    /* Read current active regulator */
    /* Current active regulator is LDO */
    if (Cy_SysPm_CoreBuckGetProfile() == CY_SYSPM_CORE_BUCK_PROFILE_LP)
    {
        pmStatus |= CY_SYSPM_STATUS_SYSTEM_LP;
    }
    else if (Cy_SysPm_CoreBuckGetProfile() == CY_SYSPM_CORE_BUCK_PROFILE_ULP)
    {
        pmStatus |= CY_SYSPM_STATUS_SYSTEM_ULP;
    }
    else
    {
        pmStatus |= CY_SYSPM_STATUS_SYSTEM_HP;
    }

    /* Check whether CM33 is in the deep sleep mode*/
    if((0u != _FLD2VAL(MXCM33_CM33_STATUS_SLEEPING, MXCM33_CM33_STATUS)) &&
       (0u != _FLD2VAL(MXCM33_CM33_STATUS_SLEEPDEEP, MXCM33_CM33_STATUS)))
    {
        pmStatus |= (uint32_t) CY_SYSPM_STATUS_CM33_DEEPSLEEP;
    }
    /* Check whether CM33 is in the sleep mode*/
    else if (0u != _FLD2VAL(MXCM33_CM33_STATUS_SLEEPING, MXCM33_CM33_STATUS))
    {
        pmStatus |= CY_SYSPM_STATUS_CM33_SLEEP;
    }
    else
    {
        pmStatus |= CY_SYSPM_STATUS_CM33_ACTIVE;
    }

    /* Check whether CM55 is in the deep sleep mode*/
    if((0u != _FLD2VAL(MXCM55_CM55_STATUS_SLEEPING, MXCM55_CM55_STATUS)) &&
       (0u != _FLD2VAL(MXCM55_CM55_STATUS_SLEEPDEEP, MXCM55_CM55_STATUS)))
    {
        pmStatus |= (uint32_t) CY_SYSPM_STATUS_CM55_DEEPSLEEP;
    }
    /* Check whether CM33 is in the sleep mode*/
    else if (0u != _FLD2VAL(MXCM55_CM55_STATUS_SLEEPING, MXCM55_CM55_STATUS))
    {
        pmStatus |= CY_SYSPM_STATUS_CM55_SLEEP;
    }
    else
    {
        pmStatus |= CY_SYSPM_STATUS_CM55_ACTIVE;
    }

    return pmStatus;
}

#endif /* CY_IP_MXS22SRSS */
/* [] END OF FILE */

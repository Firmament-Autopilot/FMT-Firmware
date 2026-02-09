/***************************************************************************//**
* \file system_edge.c
*
* \brief
* The device common system-source file.
*
********************************************************************************
* \copyright
* (c) (2016-2025), Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_device.h"
#include "cy_device_headers.h"
#include "cmsis_compiler.h"
#include "cy_syslib.h"
#include "cy_syspm.h"
#include "cy_sysclk.h"
#include "cy_syspm_pdcm.h"
#include "cy_syspm_ppu.h"
#include "cycfg_system.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_system_config_system_macro_edge
* \{
*/

#define CY_SYS_CORE_PWR_CTL_KEY_OPEN            (0x05FAUL)  /**< Power Control Key Open */
#define CY_SYS_CORE_PWR_CTL_KEY_CLOSE           (0xFA05UL)  /**< Power Control Key Close */

/** \} group_system_config_system_macro_edge */

#define CY_SYS_CORE_VECTOR_TABLE_VALID_ADDR     (0x0003FFUL)  /**< Valid Vector Table Address*/

#define CY_SYS_CORE_WAIT_10US                   (10U)

#define CY_SYS_CM55_IN_RESET                    (0x1U)
#define CY_SYS_CM55_NOT_IN_RESET                (0x0U)
#define CY_SYS_CM33_IN_RESET                    (0x0U)
#define CY_SYS_CM33_NOT_IN_RESET                (0x1U)

#define CM55_0_CPU_EVENT                        (0xFU)
#define CM33_0_CPU_EVENT                        (0xFU)

#define CY_SYS_CPU_WAIT_DEFAULT                 (0x1U)

#define CY_SYS_SOCMEM_HF_NUM                    (2U)
#define CY_SYS_SOCMEM_PERI_GROUP_ENABLE_OFFSET  (0x2U)
#define CY_SOCMEM_DC_GPU_PORT_NUM               (0x2U)

#if (CY_SYSTEM_CPU_M33 == 1UL)
#define CY_SYS_CURRENT_CPU_PD                   (CY_PD_PDCM_SYSCPU)
#elif (CY_SYSTEM_CPU_M55 == 1UL) || defined(CY_DOXYGEN)
#define CY_SYS_CURRENT_CPU_PD                   (CY_PD_PDCM_APPCPU)
#define CY_SYS_U55_PERI_GROUP_HF_NUM            (1U)
#define CY_SYS_U55_PERI_GROUP_ENABLE_MASK       (0x1U)

/*******************************************************************************
* Function Name: Cy_SysU55Enable
****************************************************************************//**
*
* This function enables or disables the U55 ML accelerator
* When enabling, this enables the clock, configures the PPU to active, and sets
* PDCM dependency to keep the U55 active as long as the current CPU is active.
* In Disable case it configures the PPU to off, clears the PDCM dependency to
* allow the U55 to disable, then disables the clock once the U55 has successfully
* powered off. This function waits to return until the U55 has powered off.
*
* \param enable
* Enable or disable U55
*
*******************************************************************************/
void Cy_SysU55Enable(bool enable)
{
#if defined(CY_IP_MXU55)
    cy_rslt_t result;
    if(enable)
    {
        /* Enable U55 SCTL */
         Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_MXU550_PERI_NR, CY_MMIO_MXU550_GROUP_NR, CY_MMIO_MXU550_SLAVE_NR, CY_MMIO_MXU550_CLK_HF_NR);
        /* enable U55 PPC */
        result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_U55_BASE, (uint32_t)CY_CFG_PWR_PPU_U55);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
        /* Ensure that this stays awake for as long as the CPU that requested it is awake. In the case of the U55,
         * this is less strictly necessary since the PPU is generally configured to a static "ON", but we do so
         * both for consistency and to future proof against potential changes to the default PPU configuration */
        result = cy_pd_pdcm_set_dependency(CY_PD_PDCM_U55, CY_SYS_CURRENT_CPU_PD);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
    }
    else
    {
        result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_U55_BASE, (uint32_t)PPU_V1_MODE_OFF);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
        result = cy_pd_pdcm_clear_dependency(CY_PD_PDCM_U55, CY_SYS_CURRENT_CPU_PD);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
        while(PPU_V1_MODE_OFF != cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_U55_BASE))
        {
            /* Ensure that the U55 has finished powering off before de-initializing the peri slave group,
             * otherwise the powered off state may not propagate to the PDCM */
        }

        Cy_SysClk_PeriGroupSlaveDeinit(CY_MMIO_MXU550_PERI_NR, CY_MMIO_MXU550_GROUP_NR, CY_MMIO_MXU550_SLAVE_NR);
    }
    CY_UNUSED_PARAMETER(result);
#else
    CY_UNUSED_PARAMETER(enable);
#endif /* CY_IP_MXU55 */
}
#endif /* (CY_SYSTEM_CPU_M55 == 1UL) || defined(CY_DOXYGEN) */

#if (CY_SYSTEM_CPU_M33 == 1UL) || defined(CY_DOXYGEN)

#define CY_PD1_CLKHF_NUM                    (1U)
#define CY_PD1_PWR_UP_US                    (20U)
#define CY_APPSS_PWR_UP_US                  (12U)
#define CY_SOCMEM_PWR_UP_US                 (12U)
#define CY_PWRMODE_CLK_SEL_DEFAULT_VALUE    (0X00000004U)

/*******************************************************************************
* Function Name: Cy_System_EnablePD1
****************************************************************************//**
*
* Safely Enables the PD1 Power Domain
*
* This function implements the sequence required to safely enable PD1 power
* domain, which includes
*
* - Enabling the required CLK_HF's
*
* - Enabling/Disabling the required Power Domain Dependencies
*
* - Configuring the Power Domain PPU's with appropriate configuration
*
* - Making sure the PD's are properly enabled using the required delay's
*
* As an illustration on when to call this function , refer to below
* PDCM(Power Dependency Control Matrix)...
*
* ![](PSE84_PDCM_Default.png)
*
* Where the table indicates the default PDCM dependencies.
*
* With respect to PD1, table indicates below constraints
*
* 1) If APPCPU, SOCMEM and U55 are ON then APPSS needs to be ON.
*
* 2) If APPSS is ON then PD1 needs to be ON.
*
* If any of the APPCPU, SOCMEM, U55 and APPSS power domains need to be switched
* ON, user needs to call this API first to switch ON PD1 safely.
*
* \note
*
* - Enabling peripherals in SYS_MMIO groups i.e. PERI0 group requires PD0 power domain to be
* ON.
*
* - Enabling peripherals in APP_MMIO groups i.e. PERI1 group requires PD1 power domain to be
* ON.
*
* Once PD1 is enabled, switching ON/OFF of individual power domains under PD1
* can be done using below API's
*
* \ref Cy_SysEnableSOCMEM
*
* \ref Cy_SysCM55Enable
*
* \ref Cy_SysU55Enable
*
*******************************************************************************/
void Cy_System_EnablePD1(void)
{
    uint32_t timeoutUs = CY_PD1_PWR_UP_US;
    cy_rslt_t result;

    /* Sequence based on CDT_005513-163 */

    /* Enable HF1 */
    if(false == Cy_SysClk_ClkHfIsEnabled(CY_PD1_CLKHF_NUM))
    {
        (void)Cy_SysClk_ClkHfEnable(CY_PD1_CLKHF_NUM);         /* Suppress a compiler warning about unused return value */
    }

    /* Configure CLK_SELECT CLK_PWR_DIV to reset value of 4 (to ensure IHO/5), CLK_PWR_MUX to 0 to select IHO as source.*/
    CY_PWRMODE_CLK_SELECT = CY_PWRMODE_CLK_SEL_DEFAULT_VALUE;

    /* Also enables PD1 dynamic transitions */
    cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_CFG_PWR_PPU_PD1);

    /* Set dependency between SYSTEM and APPCPUSS
     *
     * The PDCM configuration doesn't let us express a dependency directly on PD1, so we depend on APPCPUSS which in turn
     *   has a hard-wired dependency on PD1. Note that this is the subsystem containing the APPCPU (M55), not the APPCPU itself.
     *
     * While we follow our standard approach and set the dependency from the current CPU, in practice this will always be the
     *   CM33 because the CM55 cannot execute without PD1 being enabled.
     * */
    result = cy_pd_pdcm_set_dependency(CY_PD_PDCM_APPCPUSS, CY_SYS_CURRENT_CPU_PD);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    /* Give wait for up to PD1_PWR_UP_US timeout while polling PD1_PPU_MAIN->PWSR_PWR_POLICY == 0x8 */
    for (; (cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE) != PPU_V1_MODE_ON ) &&
           (0UL != timeoutUs);
         timeoutUs--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    CY_ASSERT_L2(timeoutUs != 0);

    /* Wait for APPSS_PWR_UP_US (12us?, this is the time to wait on APPCPUSS to exit quiescence state before accessing the APPCPUSS registers */
    Cy_SysLib_DelayUs(CY_APPSS_PWR_UP_US);

    /* Give wait for up to 1us timeout while polling APPCPUSS->PWSR_PWR_POLICY == 0x8 */
    timeoutUs = CY_APPSS_PWR_UP_US;
    for (; (cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPUSS_BASE) != PPU_V1_MODE_ON ) &&
           (0UL != timeoutUs);
         timeoutUs--)
    {
        Cy_SysLib_DelayUs(1U);
    }

    CY_ASSERT(timeoutUs != 0);

    /* Also enables APPCPUSS  dynamic transitions */
    cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPUSS_BASE, (uint32_t)CY_CFG_PWR_PPU_APPCPUSS);

    /* Unfreeze IO Pins */
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_FREEZE_DPSLP_PD1_Msk;

    CY_UNUSED_PARAMETER(result);
}

/*******************************************************************************
* Function Name: Cy_System_DisablePD1
****************************************************************************//**
*
* Safely Disables the PD1 Power Domain
*
*******************************************************************************/
void Cy_System_DisablePD1(void)
{
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)PPU_V1_MODE_OFF); /* Suppress a compiler warning about unused return value */
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPUSS_BASE, (uint32_t)PPU_V1_MODE_OFF); /* Suppress a compiler warning about unused return value */
    (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)PPU_V1_MODE_OFF); /* Suppress a compiler warning about unused return value */

    cy_rslt_t result = cy_pd_pdcm_clear_dependency(CY_PD_PDCM_APPCPUSS, CY_SYS_CURRENT_CPU_PD);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
    CY_UNUSED_PARAMETER(result);
}

/*******************************************************************************
* Function Name: Cy_SysCM55GetStatus
****************************************************************************//**
*
* Returns the Cortex-M55 core power mode.
* \param CM55Base MXCM55 base address
* \return \ref group_system_config_core_status_macro_edge
*
*******************************************************************************/
uint32_t Cy_SysCM55GetStatus(MXCM55_Type *CM55Base)
{
    CY_ASSERT_L2(NULL != CM55Base);
    /* Return current power mode */
    return (CM55Base->CM55_STATUS);
}


/*******************************************************************************
* Function Name: Cy_SysEnableSOCMEM
****************************************************************************//**
*
* Enables SOCMEM IP
*
* \param enable
* Enable or disable SOCMEM
*
*******************************************************************************/
void Cy_SysEnableSOCMEM(bool enable)
{
    uint32_t timeoutUs = CY_SOCMEM_PWR_UP_US;
    cy_rslt_t result;

    if(enable)
    {
        /* Enable HF2 for SOCMEM */
#if  (!defined(CY_USE_FULL_PROTECTION) || (CY_USE_FULL_PROTECTION == 0)) || defined (COMPONENT_SECURE_DEVICE)
        /*  With protection applied clocks needs to be enabled in Sec context */
        if(false == Cy_SysClk_ClkHfIsEnabled(CY_SYS_SOCMEM_HF_NUM))
        {
            result = Cy_SysClk_ClkHfEnable(CY_SYS_SOCMEM_HF_NUM);         /* Suppress a compiler warning about unused return value */
            CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
        }
#endif
        /* Enable SOCMEM SCTL */
        if(!Cy_SysClk_IsPeriGroupSlaveEnabled(CY_MMIO_SOCMEM_PERI_NR, CY_MMIO_SOCMEM_GROUP_NR, CY_MMIO_SOCMEM_SLAVE_NR))
        {
            Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_SOCMEM_PERI_NR, CY_MMIO_SOCMEM_GROUP_NR, CY_MMIO_SOCMEM_SLAVE_NR, CY_MMIO_SOCMEM_CLK_HF_NR);
        }

        SOCMEM->CTL &= ~(SOCMEM_CTL_SRAM_WS_Msk | SOCMEM_CTL_SROM_WS_Msk);
        SOCMEM->GK_CTL = SOCMEM_GK_STATUS_OPEN_Msk;

        /* Display Controller and GPU are attached to SOCMEM Port 2 which are Latency Sensitive and hence enable LATENCY setting  */
        SOCMEM->ARB_DYN_CTL[CY_SOCMEM_DC_GPU_PORT_NUM] = SOCMEM_ARB_DYN_CTL_LATENCY_Msk;

        result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_CFG_PWR_PPU_SOCMEM);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

        result = cy_pd_pdcm_set_dependency(CY_PD_PDCM_SOCMEM, CY_SYS_CURRENT_CPU_PD);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

        for (; (cy_pd_ppu_get_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE) != PPU_V1_MODE_ON ) &&
               (0UL != timeoutUs);
             timeoutUs--)
        {
            Cy_SysLib_DelayUs(1U);
        }

        CY_ASSERT_L2(timeoutUs != 0);

    }
    else
    {
        /* Remove SOCMEM dependency from current CPU and power off */
        result = cy_pd_pdcm_clear_dependency(CY_PD_PDCM_SOCMEM, CY_SYS_CURRENT_CPU_PD);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
        result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)PPU_V1_MODE_OFF);
        CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
    }
    CY_UNUSED_PARAMETER(result);
}
/*******************************************************************************
* Function Name: Cy_SysCM55SetDbgPort
****************************************************************************//**
*
* Set APPCPU debug port mode policy
*
* \param dbgMode debug port policy
*
*******************************************************************************/
void Cy_SysCM55SetDbgPort(cy_app_cpu_dbg_port_type_t dbgMode)
{
    switch (dbgMode)
    {
        /** Disable debug port for CM55 */
        case APPCPUSS_DBG_DISABLE:
            APPCPUSS->AP_CTL &= ~(APPCPUSS_AP_CTL_CM55_0_ENABLE_Msk | APPCPUSS_AP_CTL_CM55_0_DBG_ENABLE_Msk |
                APPCPUSS_AP_CTL_CM55_0_NID_ENABLE_Msk);
            break;
        /** Enables invasive debug CM55 */
        case APPCPUSS_DBG_INVASIVE_MODE:
            APPCPUSS->AP_CTL &= ~(APPCPUSS_AP_CTL_CM55_0_NID_ENABLE_Msk);
            APPCPUSS->AP_CTL |= (APPCPUSS_AP_CTL_CM55_0_ENABLE_Msk | APPCPUSS_AP_CTL_CM55_0_DBG_ENABLE_Msk);
            break;
        /** Enables all trace and non-invasive debug features */
        case APPCPUSS_DBG_TRACES_NON_INVASIVE_MODE:
            APPCPUSS->AP_CTL &= ~(APPCPUSS_AP_CTL_CM55_0_DBG_ENABLE_Msk);
                    APPCPUSS->AP_CTL |= (APPCPUSS_AP_CTL_CM55_0_ENABLE_Msk | APPCPUSS_AP_CTL_CM55_0_NID_ENABLE_Msk);
            break;
        /** Enables invasive debug & all trace and non-invasive enable for CM55 */
        case APPCPUSS_DBG_ENABLE_ALL:
            APPCPUSS->AP_CTL |= (APPCPUSS_AP_CTL_CM55_0_ENABLE_Msk | APPCPUSS_AP_CTL_CM55_0_DBG_ENABLE_Msk |
                APPCPUSS_AP_CTL_CM55_0_NID_ENABLE_Msk);
            break;
        /** Invalid value passed */
        default:
            /* Invalid value  */
            break;
    }

}

/*******************************************************************************
* Function Name: Cy_SysCM55Disable
****************************************************************************//**
*
* Disables CM55
*
* \note Below is the sequence that needs to be followed
* - Turn OFF the APPCPU PPU.
* - Enter DS on CM55.
*
*******************************************************************************/
void Cy_SysCM55Disable(void)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
#if !defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;

    result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 0UL);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_SYSCM55DISABLE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .base = NULL,
        .sub_block = 0UL,
        .input_base = NULL,
        .input_len = 0UL,
        .output_base = NULL,
        .output_len = 0UL,
        .invec_bases = NULL,
        .invec_sizes = NULL,
        .outvec_bases = NULL,
        .outvec_sizes = NULL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
#else
    /* Power OFF the APPCPU Power Domain. The APPCPU is self-sustaining, so no PDCM dependency to clear */
    result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)PPU_V1_MODE_OFF);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
#endif
    CY_UNUSED_PARAMETER(result); /* Only used in asserts */
}

/*******************************************************************************
* Function Name: Cy_SysCM55Enable
****************************************************************************//**
*
* Sets vector table base address and enables the Cortex-M55 core and its
* debug port policy.
*
* \note If the CPU is already enabled, it is reset and then enabled.
* \note APP_MMIO_TCM IP should be enabled before call of this API
* \param CM55Base MXCM55 base address
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
* \param dbgMode debug port policy.
* \param waitus The timeout value in microsecond used to wait for core to be
* booted. value zero is for infinite wait till the core is booted successfully.
*
* \note: For the PSE84 device, this functions clears the first 16 words in
* the default vector address (for PSE84 device it is ITCM memory). The processor reads
* the first two words at the default vector table address to get Stack pointer
* and Secure reset vector address. Because the processor branches to the address
* read from this reset vector, this operation may causes access violation exception.
*
*******************************************************************************/

void Cy_SysCM55Enable(MXCM55_Type *CM55Base, uint32_t vectorTableOffset, cy_app_cpu_dbg_port_type_t dbgMode, uint32_t waitus)
{
    CY_ASSERT_L2(NULL != CM55Base);
    CY_ASSERT_L2((vectorTableOffset & CY_SYS_CORE_VECTOR_TABLE_VALID_ADDR) == 0UL);
    cy_rslt_t result;

#if !defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_syscm55enable_in_t input_args;
    input_args.vectorTableOffset = vectorTableOffset;
    input_args.dbgMode = dbgMode;
    input_args.waitus = waitus;

    result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 0UL);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_SYSCM55ENABLE,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .base = CM55Base,
        .sub_block = 0UL,
        .input_base = (uint8_t*)(&input_args),
        .input_len = sizeof(input_args),
        .output_base = NULL,
        .output_len = 0UL,
        .invec_bases = NULL,
        .invec_sizes = NULL,
        .outvec_bases = NULL,
        .outvec_sizes = NULL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
#else

    uint32_t interruptState;
    uint32_t cpuState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Set CM55 debug port policy*/
    Cy_SysCM55SetDbgPort(dbgMode);


    result = cy_pd_pdcm_set_dependency(CY_PD_PDCM_SYSCPU, CY_PD_PDCM_APPCPU);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    /* Power ON the APPCPU Power Domain */
    result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)PPU_V1_MODE_ON);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    /* For the CPU with Security Extension, clear the first 16 words in ITCM memory to avoid
     * possible access violation exception.
     * The processor always reads the first two words at the default vector table address
     * to get Stack pointer and Secure reset vector address. Because the processor branches to the address
     * read from this reset vector, this operation may causes access violation exception.
     */
    uint32_t * vector_addr = (uint32_t *)(CY_SYS_CM55_DEFAULT_VECTOR_ADDRESS);
    for (uint32_t SYSTEM_IRQn = 16UL; SYSTEM_IRQn > 0UL; SYSTEM_IRQn--)
    {
        *vector_addr++ = 0UL;
    }

    /* CDT_005459-211 to check how can we power on/off core.
       Here we need to power-on the core if it is already in off state. */
    cpuState = Cy_SysCM55GetStatus(CM55Base);
    if (CY_SYS_CORE_STATUS_ACTIVE == cpuState)
    {
        /* Set CPU wait */
        CY_REG32_CLR_SET(CM55Base->CM55_CTL, MXCM55_CM55_CTL_CPU_WAIT, CY_SYS_CPU_WAIT_DEFAULT);
        /* Resets the core */
        Cy_SysCM55Reset(CM55Base, CY_SYS_CORE_WAIT_10US);
    }

    /* Set NS vector table address */
    CM55Base->CM55_NS_VECTOR_TABLE_BASE = vectorTableOffset;

    /* Reset the core after setting the vector table base address */
    regValue = CM55Base->CM55_CMD & ~(MXCM55_CM55_CMD_RESET_Msk | MXCM55_CM55_CMD_VECTKEYSTAT_Msk);
    regValue |= _VAL2FLD(MXCM55_CM55_CMD_VECTKEYSTAT, CY_SYS_CORE_PWR_CTL_KEY_OPEN); /* set key bits */
    regValue |= _VAL2FLD(MXCM55_CM55_CMD_RESET, CY_SYS_CM55_IN_RESET); /* set reset bit */
    CM55Base->CM55_CMD = regValue;

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        while(Cy_SysCM55GetStatus(CM55Base) != CY_SYS_CORE_STATUS_ACTIVE)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if (Cy_SysCM55GetStatus(CM55Base) != CY_SYS_CORE_STATUS_ACTIVE)
        {
            Cy_SysLib_DelayUs((uint16_t)waitus);
        }
    }

    /* Release CPU wait */
    CM55Base->CM55_CTL &= ~(_VAL2FLD(MXCM55_CM55_CTL_CPU_WAIT, CY_SYS_CPU_WAIT_DEFAULT));

    /* Enable Event from CM33 */
    CM55Base->CM55_EVENT_CTL = CM33_0_CPU_EVENT;

    /* Now that the CM55 is on and self-sustaining, set its PPU so that it can enter lower power modes if desired */
    result = cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_CFG_PWR_PPU_APPCPU);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    Cy_SysLib_ExitCriticalSection(interruptState);
#endif
    CY_UNUSED_PARAMETER(result);
}


/*******************************************************************************
* Function Name: Cy_SysCM55Reset
****************************************************************************//**
*
* Resets the Cortex-M55 core and waits for the mode to take the effect.
* \param CM55Base MXCM55 base address
* \param waitus The timeout value in microsecond used to wait for core to be
* reset. value zero is for infinite wait till the core is reset successfully.
*
* \warning Do not call the function while the Cortex-M55 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M55 core is in the Sleep or Deep Sleep low-power mode. Use
* the Power Management (syspm) API to put the CPU into the
* low-power modes. Use the Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysCM55Reset(MXCM55_Type *CM55Base, uint32_t waitus)
{
    CY_ASSERT_L2(NULL != CM55Base);

#if !defined(COMPONENT_SECURE_DEVICE) && (CY_PDL_SYSPM_ENABLE_SRF_INTEG)
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_srf_invec_ns_t* inVec = NULL;
    mtb_srf_outvec_ns_t* outVec = NULL;
    mtb_srf_output_ns_t* output = NULL;
    cy_pdl_syspm_srf_syscm55reset_in_t input_args;
    input_args.waitus = waitus;

    result = mtb_srf_pool_allocate(&cy_pdl_srf_default_pool, &inVec, &outVec, 0UL);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    cy_pdl_invoke_srf_args invoke_args =
    {
        .inVec = inVec,
        .outVec = outVec,
        .output_ptr = &output,
        .op_id = CY_PDL_SYSPM_OP_SYSCM55RESET,
        .submodule_id = CY_PDL_SECURE_SUBMODULE_SYSPM,
        .base = CM55Base,
        .sub_block = 0UL,
        .input_base = (uint8_t*)(&input_args),
        .input_len = sizeof(input_args),
        .output_base = NULL,
        .output_len = 0UL,
        .invec_bases = NULL,
        .invec_sizes = NULL,
        .outvec_bases = NULL,
        .outvec_sizes = NULL
    };
    result = _Cy_PDL_Invoke_SRF(&invoke_args);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);

    result = mtb_srf_pool_free(&cy_pdl_srf_default_pool, inVec, outVec);
    CY_ASSERT_L2(CY_RSLT_SUCCESS == result);
    CY_UNUSED_PARAMETER(result);
#else
    uint32_t interruptState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    regValue = CM55Base->CM55_CMD & ~(MXCM55_CM55_CMD_RESET_Msk | MXCM55_CM55_CMD_VECTKEYSTAT_Msk);
    regValue |= _VAL2FLD(MXCM55_CM55_CMD_VECTKEYSTAT, CY_SYS_CORE_PWR_CTL_KEY_OPEN); /* set key bits */
    regValue |= _VAL2FLD(MXCM55_CM55_CMD_RESET, CY_SYS_CM55_IN_RESET); /* set reset bit */
    CM55Base->CM55_CMD = regValue;

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        /* HW automatically clears this field to '0'. This effectively results in a CM55 reset */
        while( _FLD2VAL(MXCM55_CM55_CMD_RESET, CM55Base->CM55_CMD) != CY_SYS_CM55_NOT_IN_RESET)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if( _FLD2VAL(MXCM55_CM55_CMD_RESET, CM55Base->CM55_CMD) != CY_SYS_CM55_NOT_IN_RESET)
        {
            Cy_SysLib_DelayUs((uint16_t)waitus);
        }
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
#endif
}

#endif /* (CY_SYSTEM_CPU_M33 == 1UL) || defined(CY_DOXYGEN) */

#if (CY_SYSTEM_CPU_M0P == 1UL) || defined(CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_SysCM33GetStatus
****************************************************************************//**
*
* Returns the Cortex-M33 core power mode.
*
* \return \ref group_system_config_core_status_macro_edge
*
*******************************************************************************/
uint32_t Cy_SysCM33GetStatus(void)
{
    /* Return current power mode */
    return (MXCM33->CM33_STATUS);
}


/*******************************************************************************
* Function Name: Cy_SysCM33Enable
****************************************************************************//**
*
* Sets vector table base address and enables the Cortex-M33 core in secure mode.
*
* \note If the CPU is already enabled, it is reset and then enabled.
*
* \param vectorTableOffset The offset of the vector table base address from
* memory address 0x00000000. The offset should be multiple to 1024 bytes.
* \param waitus The timeout value in microsecond used to wait for core to be
* booted. value zero is for infinite wait till the core is booted successfully.
*
*******************************************************************************/
void Cy_SysCM33Enable(uint32_t vectorTableOffset, uint32_t waitus)
{
    uint32_t interruptState;
    uint32_t cpuState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    cpuState = Cy_SysCM33GetStatus();
    if (CY_SYS_CORE_STATUS_ACTIVE == cpuState)
    {
        Cy_SysCM33Reset(CY_SYS_CORE_WAIT_10US);
    }

    MXCM33->CM33_S_VECTOR_TABLE_BASE = vectorTableOffset;

    regValue = MXCM33->CM33_CMD & ~(MXCM33_CM33_CMD_ENABLED_Msk | MXCM33_CM33_CMD_VECTKEYSTAT_Msk);
    regValue |= _VAL2FLD(MXCM33_CM33_CMD_VECTKEYSTAT, CY_SYS_CORE_PWR_CTL_KEY_OPEN); /* set key bits */
    regValue |= _VAL2FLD(MXCM33_CM33_CMD_ENABLED, CY_SYS_CM33_IN_RESET); /* reset enable bit */
    MXCM33->CM33_CMD = regValue;

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        while (Cy_SysCM33GetStatus() != CY_SYS_CORE_STATUS_ACTIVE)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if (Cy_SysCM33GetStatus() != CY_SYS_CORE_STATUS_ACTIVE)
        {
            Cy_SysLib_DelayUs(waitus);
        }
    }

    MXCM33->CM33_CTL &= ~(_VAL2FLD(MXCM33_CM33_CTL_CPU_WAIT, CY_SYS_CPU_WAIT_DEFAULT));

    /* Enable Event from CM55 */
    MXCM33->CM33_EVENT_CTL = CM55_0_CPU_EVENT;

    Cy_SysLib_ExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Cy_SysCM33Reset
****************************************************************************//**
*
* Resets the Cortex-M33 core and waits for the mode to take the effect.
*
* \param waitus The timeout value in microsecond used to wait for core to be
* reset. value zero is for infinite wait till the core is reset successfully.
*
* \warning Do not call the function while the Cortex-M33 is executing because
* such a call may corrupt/abort a pending bus-transaction by the CPU and cause
* unexpected behavior in the system including a deadlock. Call the function
* while the Cortex-M55 core is in the Sleep or Deep Sleep low-power mode. Use
* the Power Management (syspm) API to put the CPU into the
* low-power modes. Use the Cy_SysPm_ReadStatus() to get a status of the CPU.
*
*******************************************************************************/
void Cy_SysCM33Reset(uint32_t waitus)
{
    uint32_t interruptState;
    uint32_t regValue;

    interruptState = Cy_SysLib_EnterCriticalSection();

    regValue = MXCM33->CM33_CMD & ~(MXCM33_CM33_CMD_ENABLED_Msk | MXCM33_CM33_CMD_VECTKEYSTAT_Msk);
    regValue |= _VAL2FLD(MXCM33_CM33_CMD_VECTKEYSTAT, CY_SYS_CORE_PWR_CTL_KEY_OPEN); /* set key bits */
    regValue |= _VAL2FLD(MXCM33_CM33_CMD_ENABLED, CY_SYS_CM33_IN_RESET); /* reset enable bit */
    MXCM33->CM33_CMD = regValue;

    if (waitus == CY_SYS_CORE_WAIT_INFINITE)
    {
        /* After SW clears this field to '0', HW automatically sets this field to '1'.
         * This effectively results in a CM33 reset, followed by a CM33 warm boot. */
        while ( _FLD2VAL(MXCM33_CM33_CMD_ENABLED, MXCM33->CM33_CMD) != CY_SYS_CM33_NOT_IN_RESET)
        {
            /* Wait for the power mode to take effect */
        }
    }
    else
    {
        if ( _FLD2VAL(MXCM33_CM33_CMD_ENABLED, MXCM33->CM33_CMD) != CY_SYS_CM33_NOT_IN_RESET)
        {
            Cy_SysLib_DelayUs(waitus);
        }
    }

    Cy_SysLib_ExitCriticalSection(interruptState);
}

#endif /* (CY_SYSTEM_CPU_M0P == 1UL) || defined(CY_DOXYGEN) */

#if defined(__cplusplus)
}
#endif

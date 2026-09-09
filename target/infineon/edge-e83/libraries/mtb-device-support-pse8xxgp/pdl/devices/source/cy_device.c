/***************************************************************************//**
* \file cy_device.c
* \version 2.0
*
* This file provides the definitions for core and peripheral block HW base
* addresses, versions, and parameters.
*
********************************************************************************
* \copyright
* Copyright 2018-2025 Cypress Semiconductor Corporation
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
#include "cy_pdl.h"

/*******************************************************************************
*                   Global Variables
*******************************************************************************/

/* This is set in Cy_PDL_Init() to the device information relevant
 * for the current target.
 */
const cy_stc_device_t* cy_device;

/* Platform and peripheral block configuration */
const cy_stc_device_t cy_deviceIpBlockCfg ;

const uint32_t IPC_CHANNELS_NR[CY_IPC_INSTANCES] =
{
    CY_IPC_IP0_CH,CY_IPC_IP1_CH,
};

const uint32_t IPC_IRQ_NR[CY_IPC_INSTANCES] =
{
    CY_IPC_IP0_INT,CY_IPC_IP1_INT,
};

const uint32_t IPC_BASE_PTR[CY_IPC_INSTANCES] =
{
    IPC0_BASE,IPC1_BASE,
};

/******************************************************************************
* Function Name: Cy_PDL_Init
****************************************************************************//**
*
* \brief Initializes the platform and peripheral block configuration for the
* given target device.
*
* \param device
* Pointer to the platform and peripheral block configuration
*
* \note
* This function must be called prior calling any function in PDL.
*
*******************************************************************************/
void Cy_PDL_Init(const cy_stc_device_t * device)
{
    cy_device = device;
}
#if defined (CY_IP_MXSMIF) && ((CY_IP_MXSMIF_VERSION == 5) || (CY_IP_MXSMIF_VERSION == 6))

#ifdef SMIF_JEDEC_STANDARD_DEVICE_RESET_SUPPORT
#if defined(CORE_NAME_CM55_0)
CY_SECTION_ITCM_BEGIN
#else
CY_SECTION_RAMFUNC_BEGIN
#endif
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.6', 1, \
            'Cy_SMIF_Reset_Memory is a WEAK function and can have multiple definition.')
__WEAK void Cy_SMIF_Reset_Memory(SMIF_Type *base, cy_en_smif_slave_select_t slaveSelect)
{
    uint32_t interruptState = 0;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* RESET SEQUENCE - JESD252.01 - START */
    Cy_GPIO_Pin_FastInit(SMIF_SS_PORT(base, slaveSelect), SMIF_SS_PIN(base, slaveSelect), CY_GPIO_DM_STRONG, 1U, HSIOM_SEL_GPIO);
    Cy_GPIO_Pin_FastInit(SMIF_DQ0_PORT(base), 0U, CY_GPIO_DM_STRONG, 1U, HSIOM_SEL_GPIO);

    for(int i=0; i <4;i++)
    {
        Cy_GPIO_Inv(SMIF_DQ0_PORT(base), 0U);
        Cy_GPIO_Inv(SMIF_SS_PORT(base, slaveSelect), SMIF_SS_PIN(base, slaveSelect));
        Cy_SysLib_Delay(1);
        Cy_GPIO_Inv(SMIF_SS_PORT(base, slaveSelect), SMIF_SS_PIN(base, slaveSelect));
        Cy_SysLib_Delay(1);
    }
    /* RESET SEQUENCE - JESD252.01 - END */

    /* Mux the pins back to SMIF functionality */
    Cy_GPIO_Pin_FastInit(SMIF_SS_PORT(base, slaveSelect), SMIF_SS_PIN(base, slaveSelect), CY_GPIO_DM_STRONG, 1U, HSIOM_SEL_ACT_0);
    Cy_GPIO_Pin_FastInit(SMIF_DQ0_PORT(base), 0U, CY_GPIO_DM_STRONG, 1U, HSIOM_SEL_ACT_15);

    Cy_SysLib_ExitCriticalSection(interruptState);
}
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.6')
#if CY_CPU_CORTEX_M55
CY_SECTION_ITCM_END
#else
CY_SECTION_RAMFUNC_END
#endif
#endif

#endif

/* [] END OF FILE */

/***************************************************************************//**
* \file  cy_ppc.c
* \version 1.10
*
* \brief
* Provides an API implementation of the secure PPC driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Cypress Semiconductor Corporation
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

#if defined (CY_IP_M33SYSCPUSS)

#include "cy_ppc.h"
/*******************************************************************************
* Function Name: Cy_Ppc_InitPpc
****************************************************************************//**
*
* \brief Initializes the referenced ppc
*
* \param base
* Base address of ppc being configured
*
* \param ppcResponse
* PPC Response type on violation
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_InitPpc(PPC_Type* base, const cy_en_ppc_resp_cfg_t ppcResponse)
{

    if (ppcResponse == CY_PPC_RZWI)
    {
        base->CTL = base->CTL & (~PPC_CTL_RESP_CFG_Msk);
    }
    else
    {
        base->CTL = base->CTL | PPC_CTL_RESP_CFG_Msk;
    }

    return CY_PPC_SUCCESS;
}

__STATIC_INLINE void prog_attribute(PPC_Type* base, const cy_stc_ppc_attribute_t* attribute, uint32_t value, uint32_t offset)
{
    uint32_t *nsAttPtr = (uint32_t*)(base->NS_ATT);
    uint32_t *sPrivAttPtr = (uint32_t*)(base->S_P_ATT);
    uint32_t *nsPrivAttPtr = (uint32_t*)(base->NS_P_ATT);

    /* Max supported registers are 32 for NS_ATT, S_P_ATT and NS_P_ATT */
    if(offset < 32U)
    {
        /* Configure Security attribute */
        if (attribute->secAttribute == CY_PPC_SECURE)
        {
            nsAttPtr[offset] &= ~value;
        }
        else
        {
            nsAttPtr[offset] |= value;
        }
        /* Configure Secure privilege attribute */
        if (attribute->privAttribute == CY_PPC_PRIV)
        {
            sPrivAttPtr[offset] &= ~value;
        }
        else
        {
            sPrivAttPtr[offset] |= value;
        }

        /* Configure Non-secure privilege attribute */
        if (attribute->privAttribute == CY_PPC_PRIV)
        {
            nsPrivAttPtr[offset] &= ~value;
        }
        else
        {
            nsPrivAttPtr[offset] |= value;
        }
    }
}

/*******************************************************************************
* Function Name: Cy_Ppc_ConfigAttrib
****************************************************************************//**
*
* \brief Configure the referenced ppc with the security and access attributes
*
* \param base
* Base address of ppc being configured
*
* \param region
* PPC region to configure
*
* \param attribute
* PPC attribute configuration structure
*
* \return
* Initialization status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_ConfigAttrib(PPC_Type* base, const cy_en_prot_region_t region, const cy_stc_ppc_attribute_t* attribute)
{
    if (!(PPC_IS_VALID(base, region)))
    {
        return CY_PPC_BAD_PARAM;
    }

    // Region can go over to the next Peripheral Instance, and this is controlled by the base address.
    // Therefore, we need to convert the region number to the actual region within the PPC.
    uint32_t actual_region = PPC_REGION_GET_ACTUAL(base, region);

    // Peripheral region number (32i+j) is controlled by the j-th bit in the i-th instance of the attribute registers.
    uint32_t regionBitValue = (1UL << (actual_region % 32U)); // j-th bit is region % 32U
    uint32_t regionInstance = actual_region >> 5U;            // i-th Instance is region / 32U

    prog_attribute(base, attribute, regionBitValue, regionInstance);

    return CY_PPC_SUCCESS;
}

/*******************************************************************************
* Function Name: Cy_Ppc_SetPcMask
****************************************************************************//**
*
* \brief Configure the PC mask for a given range of regions of referenced PPC
*
* \param base
* Base address of ppc being configured
*
* \param region
* PPC region to set PC Mask for
*
* \param pcMask
* PPC mask to set to
*
* \return
* Operation status
*
*******************************************************************************/
cy_en_ppc_status_t Cy_Ppc_SetPcMask(PPC_Type* base, const cy_en_prot_region_t region, uint32_t pcMask)
{
    if (!(PPC_IS_VALID(base, region)))
    {
        return CY_PPC_BAD_PARAM;
    }

    // Region can go over to the next Peripheral Instance, and this is controlled by the base address.
    // Therefore, we need to convert the region number to the actual region within the PPC.
    uint32_t actual_region = PPC_REGION_GET_ACTUAL(base, region);

    /* Max supported registers are 1024 for PC_MASK */
    if(actual_region < 1024U)
    {
        /* Configure Protection Context Mask */
        base->PC_MASK[actual_region] = pcMask;
    }

    return CY_PPC_SUCCESS;
}

#endif
/* [] END OF FILE */

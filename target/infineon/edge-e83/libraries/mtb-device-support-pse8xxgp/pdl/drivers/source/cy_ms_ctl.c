/***************************************************************************//**
* \file  cy_ms_ctl.c
* \version 1.2
*
* \brief
* Provides an API implementation of the master security control driver.
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

#include "cy_ms_ctl.h"

static void Cy_Ms_Ctl_SetMscAcgResp(uint32_t *reg, uint32_t gate_mask, uint32_t gate_pos, cy_en_ms_ctl_cfg_gate_resp_t gateResp, uint32_t sec_mask, uint32_t sec_pos, cy_en_ms_ctl_sec_resp_t secResp)
{
    uint32_t value = *reg;
    value &= ~(gate_mask | sec_mask);
    if (gateResp == CY_MS_CTL_GATE_RESP_ERR)
    {
        value |= ((1U << gate_pos) & gate_mask);
    }
    if (secResp == CY_MS_CTL_SEC_RESP_ERR)
    {
        value |= ((1U << sec_pos) & sec_mask);
    }
    *reg = value;
}

static uint32_t Cy_Ms_Ctl_SetBusMasterConfig(uint32_t value, bool privileged, bool nonSecure, uint32_t pcMask)
{
    uint32_t reg_value = value;

    if (privileged)
    {
        reg_value |= ((1U << MS_CTL_P_Pos) & MS_CTL_P_Msk);
    }
    else
    {
        reg_value &= (~((1U << MS_CTL_P_Pos) & MS_CTL_P_Msk));
    }

    if (nonSecure)
    {
        reg_value |= ((1U << MS_CTL_NS_Pos) & MS_CTL_NS_Msk);
    }
    else
    {
        reg_value &= (~((1U << MS_CTL_NS_Pos) & MS_CTL_NS_Msk));
    }

    reg_value &= (~MS_CTL_PC_MASK_Msk);
    reg_value |= ((pcMask << MS_CTL_PC_MASK_Pos) & MS_CTL_PC_MASK_Msk);

    return reg_value;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_ConfigBusMaster
****************************************************************************//**
*
* \brief Configures the referenced bus master by setting the privilege , non-secure
* and protection context (PC) mask settings
*
* \param busMaster
* Bus master being initialized
*
* \param privileged
* privileged setting, 'false': user mode; 'true': privileged mode
*
* \param pcMask
* pcMask
*
* \param nonSecure
* Bus master security  setting, 'false': secure; 'true': non-secure
*
* \return
* Requested operation status
*
*******************************************************************************/
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigBusMaster(en_ms_ctl_master_t busMaster, bool privileged, bool nonSecure, uint32_t pcMask)
{
    uint32_t value = MS_CTL_PC_CTL_VX(busMaster);

    MS_CTL_PC_CTL_VX(busMaster) = Cy_Ms_Ctl_SetBusMasterConfig(value, privileged, nonSecure, pcMask);

    return CY_MS_CTL_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_ConfigMscAcgResp
****************************************************************************//**
*
* \brief Response configuration for ACG and MSC for the referenced bus master
*
* \param busMaster
* Bus master for which response is being initialized
*
* \param gateResp
* Response type when the ACG is blocking the incoming transfers:
*
* \param secResp
* Bust master privileged setting
*
* \return
* Requested operation status
*
*******************************************************************************/
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigMscAcgResp(en_ms_ctl_master_sc_acg_t busMaster, cy_en_ms_ctl_cfg_gate_resp_t gateResp, cy_en_ms_ctl_sec_resp_t secResp)
{
    uint32_t *reg = NULL;
    uint32_t gate_mask = 0, gate_pos = 0, sec_mask = 0, sec_pos = 0;

    switch (busMaster)
    {
        case CODE_MS0_MSC:
            reg = (uint32_t *)&MS_CTL_CODE_MS0_MSC_ACG_CTL_VX;
            gate_mask = MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk;
            gate_pos  = MS_CTL_CODE_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos;
            sec_mask  = MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk;
            sec_pos   = MS_CTL_CODE_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos;
            break;
        case SYS_MS0_MSC:
            reg = (uint32_t *)&MS_CTL_SYS_MS0_MSC_ACG_CTL_VX;
            gate_mask = MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk;
            gate_pos  = MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos;
            sec_mask  = MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Msk;
            sec_pos   = MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_VX_Pos;
            break;
        case SYS_MS1_MSC:
            reg = (uint32_t *)&MS_CTL_SYS_MS1_MSC_ACG_CTL_VX;
            gate_mask = MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk;
            gate_pos  = MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos;
            sec_mask  = MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Msk;
            sec_pos   = MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_VX_Pos;
            break;
        case EXP_MS_MSC:
            reg = (uint32_t *)&MS_CTL_EXP_MS_MSC_ACG_CTL_VX;
            gate_mask = MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk;
            gate_pos  = MS_CTL_EXP_MS_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos;
            sec_mask  = MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Msk;
            sec_pos   = MS_CTL_EXP_MS_MSC_ACG_CTL_SEC_RESP_VX_Pos;
            break;
        case DMAC0_MSC:
            reg = (uint32_t *)&MS_CTL_DMAC0_MSC_ACG_CTL_VX;
            gate_mask = MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk;
            gate_pos  = MS_CTL_DMAC0_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos;
            sec_mask  = MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Msk;
            sec_pos   = MS_CTL_DMAC0_MSC_ACG_CTL_SEC_RESP_VX_Pos;
            break;
        case DMAC1_MSC:
            reg = (uint32_t *)&MS_CTL_DMAC1_MSC_ACG_CTL_VX;
            gate_mask = MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Msk;
            gate_pos  = MS_CTL_DMAC1_MSC_ACG_CTL_CFG_GATE_RESP_VX_Pos;
            sec_mask  = MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Msk;
            sec_pos   = MS_CTL_DMAC1_MSC_ACG_CTL_SEC_RESP_VX_Pos;
            break;
        default:
            return CY_MS_CTL_BAD_PARAM;
    }

    Cy_Ms_Ctl_SetMscAcgResp(reg, gate_mask, gate_pos, gateResp, sec_mask, sec_pos, secResp);

    return CY_MS_CTL_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_SetPcHandler
****************************************************************************//**
*
* \brief Sets the handler address for the given PC. This is used to detect entry to
* "trusted" code through an exception/interrupt.
*
* \note The function can't update the handler address for the PC lower than the current application's PC.
* For example, if the application is running in PC2 it can't update handler address for PC0 or PC1.
*
* \param pc
* Protection context for which the handler is being set
*
* \param handler
* Address of the protection context  handler
*
* \return
* Requested operation status
*
*******************************************************************************/
cy_en_ms_ctl_status_t Cy_Ms_Ctl_SetPcHandler(uint32_t pc, cy_israddress handler)
{
    cy_en_ms_ctl_status_t ret = CY_MS_CTL_BAD_PARAM;

#if (defined(CY_IP_M33SYSCPUSS_VERSION) && defined(CY_IP_M33SYSCPUSS_VERSION_MINOR)) && \
    ((CY_IP_M33SYSCPUSS_VERSION <= 2u) && (CY_IP_M33SYSCPUSS_VERSION_MINOR < 2u))

    if (pc < 4UL)
    {
        MXCM33->CM33_PC_CTL = (((MXCM33->CM33_PC_CTL)|(0x1UL << pc)) & (MXCM33_CM33_PC_CTL_VALID_Msk));
    }

#endif /* (CY_IP_M33SYSCPUSS_VERSION <= 2u) && (CY_IP_M33SYSCPUSS_VERSION_MINOR < 2u) */

    switch(pc)
    {
        case 0:
        {
            MXCM33->CM33_PC0_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        case 1:
        {
            MXCM33->CM33_PC1_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        case 2:
        {
            MXCM33->CM33_PC2_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        case 3:
        {
            MXCM33->CM33_PC3_HANDLER = (uint32_t)handler;
            ret = CY_MS_CTL_SUCCESS;
            break;
        }
        default:
        {
            // default case and will return error */
            break;
        }
    }
    return ret;
}


cy_israddress Cy_Ms_Ctl_GetPcHandler(uint32_t pc)
{
    cy_israddress handler = NULL;
    switch(pc)
    {
        case 0:
        {
            handler = (cy_israddress)MXCM33->CM33_PC0_HANDLER;
            break;
        }
        case 1:
        {
            handler = (cy_israddress)MXCM33->CM33_PC1_HANDLER;
            break;
        }
        case 2:
        {
            handler = (cy_israddress)MXCM33->CM33_PC2_HANDLER;
            break;
        }
        case 3:
        {
            handler = (cy_israddress)MXCM33->CM33_PC3_HANDLER;
            break;
        }
        default:
        {
            // default case and will return error */
            break;
        }
    }
    return handler;
}

#if defined (CY_IP_M55APPCPUSS)

/*******************************************************************************
* Function Name: Cy_Ms_Ctl_ConfigBusMasterV1
****************************************************************************//**
*
* \brief Configures the referenced bus master by setting the privilege, non-secure
* and protection context (PC) mask settings in APPCPUSS.
*
* \param busMaster
* Bus master being initialized
*
* \param privileged
* privileged setting, 'false': user mode; 'true': privileged mode
*
* \param pcMask
* pcMask
*
* \param nonSecure
* Bus master security  setting, 'false': secure; 'true': non-secure
*
* \return
* Requested operation status
*
*******************************************************************************/
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigBusMasterV1(en_ms_ctl_master_t busMaster, bool privileged, bool nonSecure, uint32_t pcMask)
{
    uint32_t value = MS_CTL_PC_CTL_V1(busMaster);

    MS_CTL_PC_CTL_V1(busMaster) = Cy_Ms_Ctl_SetBusMasterConfig(value, privileged, nonSecure, pcMask);

    return CY_MS_CTL_SUCCESS;
}


/*******************************************************************************
* Function Name: Cy_Ms_Ctl_ConfigMscAcgRespV1
****************************************************************************//**
*
* \brief Response configuration for ACG and MSC for the referenced bus master in APPCPUSS
*
* \param busMaster
* Bus master for which response is being initialized
*
* \param gateResp
* Response type when the ACG is blocking the incoming transfers:
*
* \param secResp
* Bust master privileged setting
*
* \return
* Requested operation status
*
*******************************************************************************/
cy_en_ms_ctl_status_t Cy_Ms_Ctl_ConfigMscAcgRespV1(en_ms_ctl_master_sc_acg_v1_t busMaster, cy_en_ms_ctl_cfg_gate_resp_t gateResp, cy_en_ms_ctl_sec_resp_t secResp)
{
    uint32_t *reg = NULL;
    uint32_t gate_mask = 0, gate_pos = 0, sec_mask = 0, sec_pos = 0;

    switch (busMaster)
    {
        case APP_SYS_MS0_MSC:
            reg = (uint32_t *)&MS_CTL_SYS_MS0_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_SYS_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_SYS_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_SYS_MS1_MSC:
            reg = (uint32_t *)&MS_CTL_SYS_MS1_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_SYS_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_SYS_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_AXIDMAC0_MSC:
            reg = (uint32_t *)&MS_CTL_AXIDMAC0_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_AXIDMAC0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_AXIDMAC0_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_AXIDMAC1_MSC:
            reg = (uint32_t *)&MS_CTL_AXIDMAC1_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_AXIDMAC1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_AXIDMAC1_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_AXI_MS0_MSC:
            reg = (uint32_t *)&MS_CTL_AXI_MS0_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_AXI_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_AXI_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_AXI_MS1_MSC:
            reg = (uint32_t *)&MS_CTL_AXI_MS1_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_AXI_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_AXI_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_AXI_MS2_MSC:
            reg = (uint32_t *)&MS_CTL_AXI_MS2_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_AXI_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_AXI_MS2_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_AXI_MS3_MSC:
            reg = (uint32_t *)&MS_CTL_AXI_MS3_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_AXI_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_AXI_MS3_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_EXP_MS0_MSC:
            reg = (uint32_t *)&MS_CTL_EXP_MS0_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_EXP_MS0_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_EXP_MS0_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_EXP_MS1_MSC:
            reg = (uint32_t *)&MS_CTL_EXP_MS1_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_EXP_MS1_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_EXP_MS1_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_EXP_MS2_MSC:
            reg = (uint32_t *)&MS_CTL_EXP_MS2_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_EXP_MS2_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_EXP_MS2_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        case APP_EXP_MS3_MSC:
            reg = (uint32_t *)&MS_CTL_EXP_MS3_MSC_ACG_CTL_V1;
            gate_mask = MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Msk;
            gate_pos  = MS_CTL_EXP_MS3_MSC_ACG_CTL_CFG_GATE_RESP_V1_Pos;
            sec_mask  = MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Msk;
            sec_pos   = MS_CTL_EXP_MS3_MSC_ACG_CTL_SEC_RESP_V1_Pos;
            break;
        default:
            return CY_MS_CTL_BAD_PARAM;
    }

    Cy_Ms_Ctl_SetMscAcgResp(reg, gate_mask, gate_pos, gateResp, sec_mask, sec_pos, secResp);

    return CY_MS_CTL_SUCCESS;
}

#endif /* #if defined (CY_IP_M55APPCPUSS) */

#endif /* #if defined (CY_IP_M33SYSCPUSS) */

/* [] END OF FILE */

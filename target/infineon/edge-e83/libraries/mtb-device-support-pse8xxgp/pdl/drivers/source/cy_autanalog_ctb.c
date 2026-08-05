/***************************************************************************//**
* \file cy_autanalog_ctb.c
* \version 2.0
*
* \brief
* Provides an API definition for the CTB in the Autonomous Analog driver.
*
********************************************************************************
* \copyright
* Copyright 2022-2025 Cypress Semiconductor Corporation
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
#include "cy_autanalog_ctb.h"

#ifdef CY_IP_MXS22LPPASS_CTB

/* Helper macros for range validation */
#define AUTANALOG_CTB_DYN_CFG_NUM(value)                      ((value) <= CY_AUTANALOG_CTB_DYN_CFG_MAX)
/* Validate enumerations for static configuration */
#define AUTANALOG_CTB_OA_PWR(value)                           ((value) <= CY_AUTANALOG_CTB_OA_PWR_ULTRA_HIGH_RAIL)
#define AUTANALOG_CTB_OA_MODE(value)                          ((value) <= CY_AUTANALOG_CTB_OA_TOPO_BUFFER)
#define AUTANALOG_CTB_COMP_INT(value)                         ((value) <= CY_AUTANALOG_CTB_COMP_INT_EDGE_BOTH)
#define AUTANALOG_CTB_OA_FB_CAP(value)                        ((value) <= CY_AUTANALOG_CTB_OA_FB_CAP_10_5_pF)
#define AUTANALOG_CTB_OA_CC_CAP(value)                        ((value) <= CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED)
/* Validate enumerations for dynamic configuration */
#define AUTANALOG_CTB_OA_NINV_INP_DIR(value)                  ((value) <= CY_AUTANALOG_CTB_OA_NINV_PIN_OA0_P1_OA1_P4)
#define AUTANALOG_CTB_OA_NINV_INP_REF(value)                  ((value) <= CY_AUTANALOG_CTB_OA_NINV_REF_CTB_OA1_OUT)
#define AUTANALOG_CTB_OA_INV_INP_DIR(value)                   ((value) <= CY_AUTANALOG_CTB_OA_INV_PIN_OA0_P1_OA1_P4)
#define AUTANALOG_CTB_OA_RES_INP_DIR(value)                   ((value) <= CY_AUTANALOG_CTB_OA_RES_PIN_OA0_P1_OA1_P4)
#define AUTANALOG_CTB_OA_RES_INP_REF(value)                   ((value) <= CY_AUTANALOG_CTB_OA_RES_REF_VSSA)
#define AUTANALOG_CTB_OA_CTBBUS_MUX_IN(value)                 ((value) <= CY_AUTANALOG_CTB_OA_MUX_IN_P7)
#define AUTANALOG_CTB_OA_CTBBUS_MUX_OUT(value)                ((value) <= CY_AUTANALOG_CTB_OA_MUX_OUT_RES)


cy_en_autanalog_status_t Cy_AutAnalog_CTB_LoadConfig(uint8_t ctbIdx, const cy_stc_autanalog_ctb_t * ctbCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_CTB_BAD_PARAM;

    if (NULL != ctbCfg)
    {
        if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_CTB_LoadStaticConfig(ctbIdx, ctbCfg->ctbStaCfg))
        {
            result = Cy_AutAnalog_CTB_LoadDynamicConfig(ctbIdx, ctbCfg->ctbDynCfgNum, ctbCfg->ctbDynCfgArr);
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_CTB_LoadStaticConfig(uint8_t ctbIdx, const cy_stc_autanalog_ctb_sta_t * ctbStaCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_CTB_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;

    if (NULL != ctbStaCfg)
    {
        /* Validate enumerations for the Opamp0 configuration */
        CY_ASSERT_L3(AUTANALOG_CTB_OA_PWR(ctbStaCfg->pwrOpamp0));
        CY_ASSERT_L3(AUTANALOG_CTB_OA_MODE(ctbStaCfg->topologyOpamp0));
        CY_ASSERT_L3(AUTANALOG_CTB_COMP_INT(ctbStaCfg->intComp0));
        CY_ASSERT_L3(AUTANALOG_CTB_OA_FB_CAP(ctbStaCfg->capFbOpamp0));
        CY_ASSERT_L3(AUTANALOG_CTB_OA_CC_CAP(ctbStaCfg->capCcOpamp0));

        /* Validate enumerations for the Opamp1 configuration */
        CY_ASSERT_L3(AUTANALOG_CTB_OA_PWR(ctbStaCfg->pwrOpamp1));
        CY_ASSERT_L3(AUTANALOG_CTB_OA_MODE(ctbStaCfg->topologyOpamp1));
        CY_ASSERT_L3(AUTANALOG_CTB_COMP_INT(ctbStaCfg->intComp1));
        CY_ASSERT_L3(AUTANALOG_CTB_OA_FB_CAP(ctbStaCfg->capFbOpamp1));
        CY_ASSERT_L3(AUTANALOG_CTB_OA_CC_CAP(ctbStaCfg->capCcOpamp1));

        regVal =
                /* The static configuration for Opamp0 */
                _VAL2FLD(CTBL_STA_CFG_OA0_PWR_MODE, ctbStaCfg->pwrOpamp0) |
                _VAL2FLD(CTBL_STA_CFG_OA0_TOPO, ctbStaCfg->topologyOpamp0) |
                _VAL2FLD(CTBL_STA_CFG_OA0_COMP_OUT, ctbStaCfg->intComp0) |
                _VAL2FLD(CTBL_STA_CFG_RES0_SWAP, 0UL) | /* Set default value */
#if ((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
                _VAL2FLD(CTBL_STA_CFG_OA0_CC_OVERRIDE, ctbStaCfg->capCcOpamp0 == CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED ? 0UL : 1UL) |
#else
                _VAL2FLD(CTBL_STA_CFG_OA0_CC_ENABLE, ctbStaCfg->capCcOpamp0 == CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED ? 0UL : 1UL) |
#endif
                _VAL2FLD(CTBL_STA_CFG_C0_FB, ctbStaCfg->capFbOpamp0) |
                /* The static configuration for Opamp1 */
                _VAL2FLD(CTBL_STA_CFG_OA1_PWR_MODE, ctbStaCfg->pwrOpamp1) |
                _VAL2FLD(CTBL_STA_CFG_OA1_TOPO, ctbStaCfg->topologyOpamp1) |
                _VAL2FLD(CTBL_STA_CFG_OA1_COMP_OUT, ctbStaCfg->intComp1) |
                _VAL2FLD(CTBL_STA_CFG_RES1_SWAP, 0UL) | /* Set default value */
#if ((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
                _VAL2FLD(CTBL_STA_CFG_OA1_CC_OVERRIDE, ctbStaCfg->capCcOpamp1 == CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED ? 0UL : 1UL) |
#else
                _VAL2FLD(CTBL_STA_CFG_OA1_CC_ENABLE, ctbStaCfg->capCcOpamp1 == CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED ? 0UL : 1UL) |
#endif
                _VAL2FLD(CTBL_STA_CFG_C1_FB, ctbStaCfg->capFbOpamp1);

        if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_CTB, ctbIdx, &baseAddr))
        {
            if (0U == ctbIdx)
            {
#if defined(CTBL0_BASE)
                /* Enables the required start-up/settling delay for the enabled OpAmp0 in CTB0 */
                if (CY_AUTANALOG_CTB_OA_PWR_OFF != ctbStaCfg->pwrOpamp0)
                {
                    AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_CTBL0_OA0_READY_Msk;
                }
                /* Enables compensation capacitor for OpAmp0 in CTB0 */
                CTBL0->TRIM.OA0_COMP_TRIM = (ctbStaCfg->capCcOpamp0 != CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED) ?
                                            (uint32_t)ctbStaCfg->capCcOpamp0 :
                                             0UL;

                /* Enables the required start-up/settling delay for the enabled OpAmp1 in CTB0 */
                if (CY_AUTANALOG_CTB_OA_PWR_OFF != ctbStaCfg->pwrOpamp1)
                {
                    AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_CTBL0_OA1_READY_Msk;
                }
                /* Enables compensation capacitor for OpAmp1 in CTB0 */
                CTBL0->TRIM.OA1_COMP_TRIM = (ctbStaCfg->capCcOpamp1 != CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED) ?
                                            (uint32_t)ctbStaCfg->capCcOpamp1 :
                                             0UL;
#endif
            }
            else
            {
#if defined(CTBL1_BASE)
                /* Enables the required start-up/settling delay for the enabled OpAmp0 in CTB1 */
                if (CY_AUTANALOG_CTB_OA_PWR_OFF != ctbStaCfg->pwrOpamp0)
                {
                    AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_CTBL1_OA0_READY_Msk;
                }

                /* Enables compensation capacitor for OpAmp0 in CTB1 */
                CTBL1->TRIM.OA0_COMP_TRIM = (ctbStaCfg->capCcOpamp0 != CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED) ?
                                            (uint32_t)ctbStaCfg->capCcOpamp0 :
                                             0UL;

                /* Enables the required start-up/settling delay for the enabled OpAmp1 in CTB1 */
                if (CY_AUTANALOG_CTB_OA_PWR_OFF != ctbStaCfg->pwrOpamp1)
                {
                    AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_CTBL1_OA1_READY_Msk;
                }
                /* Enables compensation capacitor for OpAmp1 in CTB1 */
                CTBL1->TRIM.OA1_COMP_TRIM = (ctbStaCfg->capCcOpamp1 != CY_AUTANALOG_CTB_OA_CC_CAP_DISABLED) ?
                                            (uint32_t)ctbStaCfg->capCcOpamp1 :
                                             0UL;
#endif
            }

            AUTANALOG_CTBX_STA_CFG(baseAddr) = regVal;
            result = CY_AUTANALOG_SUCCESS;
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_CTB_LoadDynamicConfig(uint8_t ctbIdx, uint8_t ctbDynCfgNum, const cy_stc_autanalog_ctb_dyn_t * ctbDynCfgArr)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_CTB_BAD_PARAM;

    uint8_t cfgIdx;
    uint32_t baseAddr;
    uint32_t regVal;

    CY_ASSERT_L3(!((NULL == ctbDynCfgArr) && (ctbDynCfgNum > 0U)));
    CY_ASSERT_L3(!((NULL != ctbDynCfgArr) && (ctbDynCfgNum == 0U)));

    if (AUTANALOG_CTB_DYN_CFG_NUM(ctbDynCfgNum) && (NULL != ctbDynCfgArr))
    {
        for (cfgIdx = 0; cfgIdx < ctbDynCfgNum; cfgIdx++)
        {
            /* Validate enumerations for dynamic configuration */
            CY_ASSERT_L3(AUTANALOG_CTB_OA_NINV_INP_DIR(ctbDynCfgArr[cfgIdx].ninvInpPin));
            CY_ASSERT_L3(AUTANALOG_CTB_OA_NINV_INP_REF(ctbDynCfgArr[cfgIdx].ninvInpRef));
            CY_ASSERT_L3(AUTANALOG_CTB_OA_INV_INP_DIR(ctbDynCfgArr[cfgIdx].invInpPin));
            CY_ASSERT_L3(AUTANALOG_CTB_OA_RES_INP_DIR(ctbDynCfgArr[cfgIdx].resInpPin));
            CY_ASSERT_L3(AUTANALOG_CTB_OA_RES_INP_REF(ctbDynCfgArr[cfgIdx].resInpRef));
            CY_ASSERT_L3(AUTANALOG_CTB_OA_CTBBUS_MUX_IN(ctbDynCfgArr[cfgIdx].sharedMuxIn));
            CY_ASSERT_L3(AUTANALOG_CTB_OA_CTBBUS_MUX_OUT(ctbDynCfgArr[cfgIdx].sharedMuxOut));

            regVal =
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_OA_INP_DIRECT, ctbDynCfgArr[cfgIdx].ninvInpPin) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_OA_INP_REF, ctbDynCfgArr[cfgIdx].ninvInpRef) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_OA_INM_DIRECT, ctbDynCfgArr[cfgIdx].invInpPin) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_OA_RES_DIRECT, ctbDynCfgArr[cfgIdx].resInpPin) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_OA_RES_REF, ctbDynCfgArr[cfgIdx].resInpRef) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_CTBBUS_MUX_IN, ctbDynCfgArr[cfgIdx].sharedMuxIn) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_CTBBUS_MUX_OUT, ctbDynCfgArr[cfgIdx].sharedMuxOut) |
                    _VAL2FLD(CTBL_DYN_OA_MUX_CFG_OA_TO_PIN, ctbDynCfgArr[cfgIdx].outToPin ? 1UL : 0UL);

            if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_CTB, ctbIdx, &baseAddr))
            {
                CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 13.5','Review shows that accessing of volatile object does not have any negative drawbacks');
                AUTANALOG_CTBX_DYN_CFG(baseAddr, cfgIdx) = regVal;
                result = CY_AUTANALOG_SUCCESS;
            }
        }
    }

    return result;
}

#endif /* CY_IP_MXS22LPPASS_CTB */

/* [] END OF FILE */

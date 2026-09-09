/***************************************************************************//**
* \file cy_autanalog_ptc.c
* \version 2.0
*
* \brief
* Provides the public functions for the PTComp subsystem of the
* Low Power Peripheral Analog System.
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
#include "cy_autanalog_ptc.h"

#ifdef CY_IP_MXS22LPPASS_PTC

/* Helper macros for range validation */
#define AUTANALOG_PTCOMP_DYN_CFG_NUM(value)                   ((value) <= CY_AUTANALOG_PTCOMP_DYN_CFG_MAX)
/* Validation macros for CLOCK_DIV registers */
#define AUTANALOG_PTCOMP_CLOCK_DIV(value)                     ((value) <= INFRA_CLOCK_PTC_LP_DIV_DIV_VAL_Msk)
/* Validate enumerations for static configuration */
#define AUTANALOG_PTCOMP_PWR(value)                           ((value) <= CY_AUTANALOG_PTCOMP_COMP_PWR_NORMAL)
#define AUTANALOG_PTCOMP_HYST(value)                          ((value) <= CY_AUTANALOG_PTCOMP_COMP_HYST_ON)
#define AUTANALOG_PTCOMP_INT(value)                           ((value) <= CY_AUTANALOG_PTCOMP_COMP_INT_EDGE_BOTH)
/* Validate enumerations for dynamic configuration */
#define AUTANALOG_PTCOMP_INPUT(value)                         ((value) <= CY_AUTANALOG_PTCOMP_COMP_GPIO7)
/* Validate post-processing configuration */
#define AUTANALOG_PTCOMP_PP_CFG_NUM(value)                    ((value) <= CY_AUTANALOG_PTCOMP_PP_CFG_MAX)
#define AUTANALOG_PTCOMP_PP_INPUT_SEL(value)                  ((value) <= CY_AUTANALOG_PTCOMP_PP_IN_SRC_COMP1)
#define AUTANALOG_PTCOMP_PP_INPUT_TYPE(value)                 ((value) <= CY_AUTANALOG_PTCOMP_PP_IN_TYPE_EDGE_BOTH)
#define AUTANALOG_PTCOMP_PP_CNT_MODE(value)                   ((value) <= CY_AUTANALOG_PTCOMP_PP_CNT_MODE_WINDOW)
#define AUTANALOG_PTCOMP_PP_LUT_FUNC(value)                   ((value) <= CY_AUTANALOG_PTCOMP_PP_DATA_FUNC_A_NAND_B)
#define AUTANALOG_PTCOMP_PP_WINDOW_SIZE(value)                ((value) <= CY_AUTANALOG_PTCOMP_PP_WINDOW_ONE_TWENTY_EIGHT)
#define AUTANALOG_PTCOMP_PP_FRAME_PERIOD(value)               ((value) <= PTC_PP_FRAME_PERIOD_Msk)
/* Validate enumerations for range conditions */
#define AUTANALOG_PTCOMP_PP_THRESHOLD_LOW(value)              ((value) <= PTC_PP_THRESHOLD_LOW_Msk)
#define AUTANALOG_PTCOMP_PP_THRESHOLD_HIGH(value)             ((value) <= 0x0FFFUL)
#define AUTANALOG_PTCOMP_PP_COND_RANGE(value)                 ((value) <= CY_AUTANALOG_PTCOMP_PP_COND_OUTSIDE)
/* Validate enumerations for trimming parameters */
#define AUTANALOG_PTCOMP_TRIM_POLARITY(value)                 ((value) <= CY_AUTANALOG_PTCOMP_TRIM_POSITIVE)
#define AUTANALOG_PTCOMP_TRIM_MAGNITUDE(value)                ((value) <= CY_AUTANALOG_PTCOMP_TRIM_15mV)


cy_en_autanalog_status_t Cy_AutAnalog_PTComp_LoadConfig(uint8_t ptcompIdx, const cy_stc_autanalog_ptcomp_t * ptcompCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_PTCOMP_BAD_PARAM;

    if (NULL != ptcompCfg)
    {
        /* Static configuration of the PTComp */
        result = Cy_AutAnalog_PTComp_LoadStaticConfig(ptcompIdx, ptcompCfg->ptcompStaCfg);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            /* Dynamic configuration of the PTComp */
            result = Cy_AutAnalog_PTComp_LoadDynamicConfig(ptcompIdx, ptcompCfg->ptcompDynCfgNum, ptcompCfg->ptcompDynCfgArr);
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_PTComp_LoadStaticConfig(uint8_t ptcompIdx, const cy_stc_autanalog_ptcomp_comp_sta_t * ptcompStaCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_PTCOMP_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    if (NULL != ptcompStaCfg)
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_PTC, ptcompIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            /* Validate enumeration for CLOCK_PTCOMP_LP_DIV register */
            CY_ASSERT_L3(AUTANALOG_PTCOMP_CLOCK_DIV(ptcompStaCfg->lpDivPtcomp));
            /* Update CLOCK_PTCOMP_LP_DIV register */
            AUTANALOG_INFRA_CLOCK_PTC_LP_DIV(INFRA_BASE) = ptcompStaCfg->lpDivPtcomp;

            /* Validate enumerations for Comp0 static configuration */
            CY_ASSERT_L3(AUTANALOG_PTCOMP_PWR(ptcompStaCfg->powerModeComp0));
            CY_ASSERT_L3(AUTANALOG_PTCOMP_HYST(ptcompStaCfg->compHystComp0));
            CY_ASSERT_L3(AUTANALOG_PTCOMP_INT(ptcompStaCfg->compEdgeComp0));

            /* Validate enumerations for Comp1 static configuration */
            CY_ASSERT_L3(AUTANALOG_PTCOMP_PWR(ptcompStaCfg->powerModeComp1));
            CY_ASSERT_L3(AUTANALOG_PTCOMP_HYST(ptcompStaCfg->compHystComp1));
            CY_ASSERT_L3(AUTANALOG_PTCOMP_INT(ptcompStaCfg->compEdgeComp1));

            regVal =
                    /* Static configuration for Comp0 */
                    _VAL2FLD(PTC_STA_CFG_COMP0_MODE, ptcompStaCfg->powerModeComp0) |
                    _VAL2FLD(PTC_STA_CFG_COMP0_HYST, ptcompStaCfg->compHystComp0) |
                    _VAL2FLD(PTC_STA_CFG_COMP0_OUT, ptcompStaCfg->compEdgeComp0) |
                    /* Static configuration for Comp1 */
                    _VAL2FLD(PTC_STA_CFG_COMP1_MODE, ptcompStaCfg->powerModeComp1) |
                    _VAL2FLD(PTC_STA_CFG_COMP1_HYST, ptcompStaCfg->compHystComp1) |
                    _VAL2FLD(PTC_STA_CFG_COMP1_OUT, ptcompStaCfg->compEdgeComp1);

            AUTANALOG_PTC_STA_CFG(baseAddr) = regVal;

            /* Enables the required start-up/settling delay depending on the power mode for the enabled COMP  */
            /* PTC, COMP0 */
            if (CY_AUTANALOG_PTCOMP_COMP_PWR_ULP == ptcompStaCfg->powerModeComp0)
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP3) |= INFRA_PRIO_CFG_PTC_CMP0_READY_Msk;
            }
            else if (CY_AUTANALOG_PTCOMP_COMP_PWR_LP == ptcompStaCfg->powerModeComp0)
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_PTC_CMP0_READY_Msk;
            }
            else if (CY_AUTANALOG_PTCOMP_COMP_PWR_NORMAL == ptcompStaCfg->powerModeComp0)
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP0) |= INFRA_PRIO_CFG_PTC_CMP0_READY_Msk;
            }
            else
            {
                /* MISRA */
            }

            /* PTC, COMP1 */
            if (CY_AUTANALOG_PTCOMP_COMP_PWR_ULP == ptcompStaCfg->powerModeComp1)
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP3) |= INFRA_PRIO_CFG_PTC_CMP1_READY_Msk;
            }
            else if (CY_AUTANALOG_PTCOMP_COMP_PWR_LP == ptcompStaCfg->powerModeComp1)
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_PTC_CMP1_READY_Msk;
            }
            else if (CY_AUTANALOG_PTCOMP_COMP_PWR_NORMAL == ptcompStaCfg->powerModeComp1)
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP0) |= INFRA_PRIO_CFG_PTC_CMP1_READY_Msk;
            }
            else
            {
                /* MISRA */
            }

            /* The post-processing configuration might be optional */
            CY_ASSERT_L3(!((NULL == ptcompStaCfg->compPpCfgArr) && (ptcompStaCfg->compPpCfgNum > 0U)));
            CY_ASSERT_L3(!((NULL != ptcompStaCfg->compPpCfgArr) && (ptcompStaCfg->compPpCfgNum == 0U)));
            if (NULL != ptcompStaCfg->compPpCfgArr)
            {
                /* Validate post-processing configuration */
                if (AUTANALOG_PTCOMP_PP_CFG_NUM(ptcompStaCfg->compPpCfgNum))
                {
                    for (cfgIdx = 0U; cfgIdx < ptcompStaCfg->compPpCfgNum; cfgIdx++)
                    {
                        /* Validate enumeration for post-processing input selector */
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_INPUT_SEL(ptcompStaCfg->compPpCfgArr[cfgIdx].inpSrc));
                        /* Validate enumerations for post-processing configuration */
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_INPUT_TYPE(ptcompStaCfg->compPpCfgArr[cfgIdx].inputType));
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_CNT_MODE(ptcompStaCfg->compPpCfgArr[cfgIdx].cntMode));
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_LUT_FUNC(ptcompStaCfg->compPpCfgArr[cfgIdx].dataFunction));
                        /* Validate enumeration for post-processing window size */
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_WINDOW_SIZE(ptcompStaCfg->compPpCfgArr[cfgIdx].windowSize));
                        /* Validate enumerations for post-processing period */
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_FRAME_PERIOD(ptcompStaCfg->compPpCfgArr[cfgIdx].period));
                        /* Validate enumerations for post-processing range conditions */
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_THRESHOLD_LOW(ptcompStaCfg->compPpCfgArr[cfgIdx].thresholdLow));
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_THRESHOLD_HIGH(ptcompStaCfg->compPpCfgArr[cfgIdx].thresholdHigh));
                        CY_ASSERT_L3(AUTANALOG_PTCOMP_PP_COND_RANGE(ptcompStaCfg->compPpCfgArr[cfgIdx].limitCondition));

                        regVal =
                                _VAL2FLD(PTC_STA_PP_CFG_INPUT_SEL, ptcompStaCfg->compPpCfgArr[cfgIdx].inpSrc);
                        AUTANALOG_PTC_STA_PP_CFG(baseAddr, cfgIdx) = regVal;

                        regVal =
                                _VAL2FLD(PTC_PP_CFG_INPUT_TYPE, ptcompStaCfg->compPpCfgArr[cfgIdx].inputType) |
                                _VAL2FLD(PTC_PP_CFG_MODE, ptcompStaCfg->compPpCfgArr[cfgIdx].cntMode) |
                                _VAL2FLD(PTC_PP_CFG_LUT, ptcompStaCfg->compPpCfgArr[cfgIdx].dataFunction);
                        AUTANALOG_PTC_PP_CFG(baseAddr, cfgIdx) = regVal;

                        regVal =
                                _VAL2FLD(PTC_PP_WINDOW_SIZE, ptcompStaCfg->compPpCfgArr[cfgIdx].windowSize);
                        AUTANALOG_PTC_PP_WINDOW(baseAddr, cfgIdx) = regVal;

                        regVal =
                                _VAL2FLD(PTC_PP_FRAME_PERIOD, ptcompStaCfg->compPpCfgArr[cfgIdx].period);
                        AUTANALOG_PTC_PP_FRAME(baseAddr, cfgIdx) = regVal;

                        regVal =
                                _VAL2FLD(PTC_PP_THRESHOLD_LOW, ptcompStaCfg->compPpCfgArr[cfgIdx].thresholdLow) |
                                _VAL2FLD(PTC_PP_THRESHOLD_HIGH, ptcompStaCfg->compPpCfgArr[cfgIdx].thresholdHigh) |
                                _VAL2FLD(PTC_PP_THRESHOLD_COND, ptcompStaCfg->compPpCfgArr[cfgIdx].limitCondition);
                        AUTANALOG_PTC_PP_THRESHOLD(baseAddr, cfgIdx) = regVal;
                    }
                }
                else
                {
                    result = CY_AUTANALOG_PTCOMP_BAD_PARAM;
                }
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_PTComp_LoadDynamicConfig(uint8_t ptcompIdx, uint8_t ptcompDynCfgNum, const cy_stc_autanalog_ptcomp_comp_dyn_t * ptcompDynCfgArr)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_PTCOMP_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    CY_ASSERT_L1(0U != ptcompDynCfgNum);

    if (AUTANALOG_PTCOMP_DYN_CFG_NUM(ptcompDynCfgNum) && (NULL != ptcompDynCfgArr))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_PTC, ptcompIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (cfgIdx = 0U; cfgIdx < ptcompDynCfgNum; cfgIdx++)
            {
                /* Validate enumerations for dynamic configuration */
                CY_ASSERT_L3(AUTANALOG_PTCOMP_INPUT(ptcompDynCfgArr[cfgIdx].ninvInpMux));
                CY_ASSERT_L3(AUTANALOG_PTCOMP_INPUT(ptcompDynCfgArr[cfgIdx].invInpMux));

                regVal =
                        _VAL2FLD(PTC_DYN_MUX_CFG_INP_MUX_SEL, ptcompDynCfgArr[cfgIdx].ninvInpMux) |
                        _VAL2FLD(PTC_DYN_MUX_CFG_INN_MUX_SEL, ptcompDynCfgArr[cfgIdx].invInpMux);

                AUTANALOG_PTC_DYN_CFG(baseAddr, cfgIdx) = regVal;
            }
        }
    }

    return result;
}

#endif /* CY_IP_MXS22LPPASS_PTC */

/* [] END OF FILE */

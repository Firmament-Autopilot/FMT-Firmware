/***************************************************************************//**
* \file cy_autanalog.c
* \version 2.0
*
* \brief
* Provides an API definition of the Autonomous Analog driver.
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
#include <string.h>
#include "cy_autanalog.h"

#ifdef CY_IP_MXS22LPPASS

#include "cy_systrimm.h"

/* Helper macros for range validation */
#define AUTANALOG_PRB_IDX(value)                                    ((value) < CY_AUTANALOG_PRB_NUM)
/* Validation macros for CLOCK_DIV registers */
#define AUTANALOG_CLOCK_DIV_PRIO_HS_DEFAULT                         (19UL)
#define AUTANALOG_CLOCK_DIV(value)                                  ((value) <= INFRA_CLOCK_PTC_LP_DIV_DIV_VAL_Msk)
/* Validation macros for PRIO_CFG register */
#define AUTANALOG_PRIO_CFG_DEFAULT                                  (0UL)
/* Validation macros for LPOSC register */
#define AUTANALOG_LPOSC_CFG_DEFAULT                                 (0x80000000U) /* ENABLE, ALWAYS_ON */
/* Validation macros for AREF register */
#define AUTANALOG_AREF_CTRL_DEFAULT                                 (0UL)
#define AUTANALOG_AREF_CTRL(value)                                  ((value) <= CY_AUTANALOG_VREF_EXT)
/* Validation macros for PRB register */
#define AUTANALOG_PRB_VREF_CTRL_CFG(value)                          ((value) <= CY_AUTANALOG_PRB_VDDA)
#define AUTANALOG_PRB_VREF_CTRL_VAL(value)                          ((value) <= CY_AUTANALOG_PRB_TAP_15)

/* Validation macros for State Transition Table registers of AC */
#define AUTANALOG_STT_AC_CFG1_CNT(value)                             ((value) <= 0x0FFFUL)
#define AUTANALOG_STT_AC_CFG1_ACTION(value)                          ((value) <= CY_AUTANALOG_STT_AC_ACTION_BRANCH_IF_FALSE_CLR)
#define AUTANALOG_STT_AC_CFG1_COND(value)                            ((value) <= CY_AUTANALOG_STT_AC_CONDITION_DAC1_STROBE)
#define AUTANALOG_STT_AC_CFG1_BR_ADDR(value)                         ((value) < CY_AUTANALOG_STATE_TRANSITION_TABLE_STATES_NUM)
/* Validation macros for State Transition Table registers of CTB */
#define AUTANALOG_STT_CTB_CFG(value)                                 ((value) <  CY_AUTANALOG_CTB_DYN_CFG_MAX)
#define AUTANALOG_STT_CTB_GAIN(value)                                ((value) <= CY_AUTANALOG_STT_CTB_OA_GAIN_32_00)
/* Validation macros for State Transition Table registers of PTComp */
#define AUTANALOG_STT_PTCOMP_CFG(value)                              ((value) <  CY_AUTANALOG_PTCOMP_DYN_CFG_MAX)
/* Validation macros for State Transition Table registers of DAC */
#define AUTANALOG_STT_DAC_CHANNEL(value)                             ((value) <=  CY_AUTANALOG_DAC_CH_CFG_NUM)
#define AUTANALOG_STT_DAC_DIRECTION(value)                           ((value) <= CY_AUTANALOG_DAC_DIRECTION_REVERSE)
/* Validation macros for State Transition Table registers of SAR */
#define AUTANALOG_STT_SAR_STATE(value)                               ((value) <= ACTRLR_TTCFG_TT_CFG3_SAR_ENTRY_ADDR_Msk)
#if !defined (CY_AUTANALOG_TRIMM_DISABLE)
/* Trimming block die temp */
#define AUTANALOG_RRAM_TRIMM_START_IDX_DIE_TEMP                      (1UL)
/* Trimming block CTB0 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_10X_RMP                  (11UL)
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_1X_RMP                   (18UL)
/* Trimming block CTB1 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_10X_RMP                  (25UL)
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_1X_RMP                   (32UL)
/* Trimming block CTB0, OA0 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA0_10X                  (5UL)
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA0_1X                   (8UL)
/* Trimming block CTB0, OA1 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA1_10X                  (8UL)
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA1_1X                   (15UL)
/* Trimming block CTB1, OA0 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA0_10X                  (19UL)
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA0_1X                   (22UL)
/* Trimming block CTB1, OA1 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA1_10X                  (22UL)
#define AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA1_1X                   (29UL)
/* Trimming block PTC */
#define AUTANALOG_RRAM_TRIMM_START_IDX_PTC                           (33UL)
/* Trimming block DAC0 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_DAC0                          (35UL)
/* Trimming block DAC1 */
#define AUTANALOG_RRAM_TRIMM_START_IDX_DAC1                          (45UL)
/* Trimming block ADC, HS */
#define AUTANALOG_RRAM_TRIMM_START_IDX_ADC_HS_CALCTRL                (55UL)
/* Trimming block ADC, LP */
#define AUTANALOG_RRAM_TRIMM_START_IDX_ADC_LP_CALCTRL                (68UL)
/* Trimming block ADC */
#define AUTANALOG_RRAM_TRIMM_START_IDX_ADC                           (72UL)
/* Trimming block INFRA, LPOSC */
#define AUTANALOG_RRAM_TRIMM_START_IDX_LPOSC                         (79UL)
/* Trimming block INFRA, AREF */
#define AUTANALOG_RRAM_TRIMM_START_IDX_AREF                          (80UL)
#endif

/* Forward declarations */
#if !defined (CY_AUTANALOG_TRIMM_DISABLE)
static cy_en_autanalog_status_t Analog_LoadTrimmValues(const cy_stc_autanalog_cfg_t * analogCfg);
#endif
static void Analog_UpdateTimerTable_AC(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState);
#if !defined (CY_AUTANALOG_PRB_DISABLE)
static void Analog_UpdateTimerTable_PRB(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState);
#endif
#if defined (CY_IP_MXS22LPPASS_CTB) && !defined (CY_AUTANALOG_CTB_DISABLE)
static void Analog_UpdateTimerTable_CTB(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState);
#endif
#if defined (CY_IP_MXS22LPPASS_PTC) && !defined (CY_AUTANALOG_PTC_DISABLE)
static void Analog_UpdateTimerTable_PTC(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState);
#endif
#if defined (CY_IP_MXS22LPPASS_DAC) && !defined (CY_AUTANALOG_DAC_DISABLE)
static void Analog_UpdateTimerTable_DAC(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState);
#endif
#if defined (CY_IP_MXS22LPPASS_SAR) && !defined (CY_AUTANALOG_SAR_DISABLE)
static void Analog_UpdateTimerTable_SAR(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState);
#endif


#if !((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
void Cy_AutAnalog_AdvPowerControl(bool sleepModeAC, bool lpOscDutyCycle, bool sarLpCorePowerCycle)
#else
void Cy_AutAnalog_AdvPowerControl(bool sleepModeAC, bool lpOscDutyCycle)
#endif
{
    /* Update AC CFG register */
    CY_REG32_CLR_SET(AUTANALOG_AC_CFG(ACTRLR_BASE), ACTRLR_CFG_SLEEP_MODE, sleepModeAC);

    /* Update LPOSC CFG register */
    CY_REG32_CLR_SET(AUTANALOG_INFRA_LPOSC_CFG(INFRA_BASE), INFRA_LPOSC_CFG_MODE, lpOscDutyCycle);

    /* Update SAR CTRL register */
#if !((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
#ifdef SAR_BASE
    CY_REG32_CLR_SET(AUTANALOG_SAR_CTRL(SAR_BASE), SAR_STA_CTRL_LP_SAR_PWR_MODE, sarLpCorePowerCycle);
#else
    (void) sarLpCorePowerCycle;
#endif
#endif
}


void Cy_AutAnalog_Clear(void)
{
    /* Disable the digital switched supply (clear content in registers and SRAM) */
    CY_REG32_CLR_SET(AUTANALOG_AC_CFG(ACTRLR_BASE), ACTRLR_CFG_DISABLE_MODE, 0x1U);

    /* Unregister SysPm callback */
    (void)Cy_SysPm_UnregisterCallback(&deepSleepCallback);
}


uint32_t Cy_AutAnalog_Init(const cy_stc_autanalog_t * cfgAndStates)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from enum to uint32_t does not have any negative drawbacks');
    uint32_t retVal = CY_AUTANALOG_BAD_PARAM;

    if (NULL != cfgAndStates)
    {
        /* Loads static and dynamic pairs of the configuration into the MMIO */
        retVal = Cy_AutAnalog_LoadConfig(cfgAndStates->configuration);

        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.4','Review shows that comparison of enum with uint32_t does not have any negative drawbacks');
        if (CY_AUTANALOG_SUCCESS == retVal)
        {
            /* Loads the entire content of the State Transition Table into the MMIO */
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that assignment of enum to uint32_t does not have any negative drawbacks');
            retVal = Cy_AutAnalog_LoadStateTransitionTable(cfgAndStates->numSttEntries, cfgAndStates->stateTransitionTable);
        }
    }

    return retVal;
}


void Cy_AutAnalog_Disable(void)
{
    /* Disable the digital switched supply (clear content in registers and SRAM) */
    CY_REG32_CLR_SET(AUTANALOG_AC_CFG(ACTRLR_BASE), ACTRLR_CFG_DISABLE_MODE, 0x1U);

    /* Disable the Autonomous Analog power domain */
    AUTANALOG_AC_CTRL(ACTRLR_BASE) = _VAL2FLD(ACTRLR_CTRL_ENABLED, 0x0U);

    /* Unregister SysPm callback */
    (void)Cy_SysPm_UnregisterCallback(&deepSleepCallback);
}


void Cy_AutAnalog_Enable(void)
{
    /* Enable the digital switched supply */
    CY_REG32_CLR_SET(AUTANALOG_AC_CFG(ACTRLR_BASE), ACTRLR_CFG_DISABLE_MODE, 0x0U);

    /* Enable the Autonomous Analog power domain */
    AUTANALOG_AC_CTRL(ACTRLR_BASE) = _VAL2FLD(ACTRLR_CTRL_ENABLED, 0x1U);
}


uint32_t Cy_AutAnalog_LoadConfig(const cy_stc_autanalog_cfg_t * analogCfg)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from enum to uint32_t does not have any negative drawbacks');
    uint32_t retVal = CY_AUTANALOG_BAD_PARAM;

    if (NULL != analogCfg)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from enum to uint32_t does not have any negative drawbacks');
        retVal = CY_AUTANALOG_ENABLE_ERR;

        uint8_t cfgIdx;
        uint32_t regVal;

        /* Enable IP block for further operation */
        Cy_AutAnalog_Enable();

        /* Delay for powering of the LPPASS, 10uS maximum */
        Cy_SysLib_DelayUs(10U);

        /* Get acknowledge about readiness of the LPPASS for further operation */
        regVal = _FLD2VAL(ACTRLR_PWR_STATUS_SW_OK, AUTANALOG_AC_PWR_STATUS(ACTRLR_BASE));
        if (regVal != 0U)
        {
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from enum to uint32_t does not have any negative drawbacks');
            retVal = CY_AUTANALOG_SUCCESS;

            /* Delay for startup of IZTAT current reference, 200uS maximum */
            Cy_SysLib_DelayUs(200U);

            /* Update LPOSC register */
            AUTANALOG_INFRA_LPOSC_CFG(INFRA_BASE) = AUTANALOG_LPOSC_CFG_DEFAULT;

            /* Validate enumerations for CLOCK_PRIO_HS_DIV register */
            CY_ASSERT_L3(AUTANALOG_CLOCK_DIV(AUTANALOG_CLOCK_DIV_PRIO_HS_DEFAULT));
            /* Update CLOCK_PRIO_HS_DIV register */
            AUTANALOG_INFRA_CLOCK_PRIO_HS_DIV(INFRA_BASE) = AUTANALOG_CLOCK_DIV_PRIO_HS_DEFAULT;

            /* Update registers PRIO_CFG[] with initial values for the delay counter */
            AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP0) = (uint32_t)CY_AUTANALOG_PRIORITY_GROUP0_CNT;
            AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP1) = (uint32_t)CY_AUTANALOG_PRIORITY_GROUP1_CNT;
            AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) = (uint32_t)CY_AUTANALOG_PRIORITY_GROUP2_CNT;
            AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP3) = (uint32_t)CY_AUTANALOG_PRIORITY_GROUP3_CNT;

            /* Update AREF register */
            AUTANALOG_INFRA_AREF_CTRL(INFRA_BASE) = AUTANALOG_AREF_CTRL_DEFAULT;

            /* Configure PRBs */
#if !defined (CY_AUTANALOG_PRB_DISABLE)
            if (NULL != analogCfg->prb)
            {
                for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_PRB_NUM; cfgIdx++)
                {
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
                    retVal |= Cy_AutAnalog_PRB_LoadConfig(cfgIdx, analogCfg->prb);
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
                }
            }
#endif

            /* Configure CTBs */
#if defined (CY_IP_MXS22LPPASS_CTB) && !defined (CY_AUTANALOG_CTB_DISABLE)
            for (cfgIdx = 0U; cfgIdx < PASS_NR_CTBLS; cfgIdx++)
            {
#ifndef CTBL0_BASE
                   if (0U == cfgIdx)
                   {
                       continue;
                   }
#endif
#ifndef CTBL1_BASE
                   if (1U == cfgIdx)
                   {
                       continue;
                   }
#endif
                if (NULL != analogCfg->ctb[cfgIdx])
                {
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
                    retVal |= Cy_AutAnalog_CTB_LoadConfig(cfgIdx, analogCfg->ctb[cfgIdx]);
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
                }
            }
#endif

            /* Configure PTC */
#if defined (CY_IP_MXS22LPPASS_PTC) && !defined (CY_AUTANALOG_PTC_DISABLE)
            for (cfgIdx = 0U; cfgIdx < PASS_NR_PTCS; cfgIdx++)
            {
#ifndef PTC_BASE
                break;
#endif
                if (NULL != analogCfg->ptcomp[cfgIdx])
                {
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
                    retVal |= Cy_AutAnalog_PTComp_LoadConfig(cfgIdx, analogCfg->ptcomp[cfgIdx]);
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
                }
            }
#endif

            /* Configure DACs */
#if defined (CY_IP_MXS22LPPASS_DAC) && !defined (CY_AUTANALOG_DAC_DISABLE)
            for (cfgIdx = 0U; cfgIdx < PASS_NR_DACS; cfgIdx++)
            {
#ifndef DAC0_BASE
                if (0U == cfgIdx)
                {
                    continue;
                }
#endif
#ifndef DAC1_BASE
                if (1U == cfgIdx)
                {
                    continue;
                }
#endif
                if (NULL != analogCfg->dac[cfgIdx])
                {
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
                    retVal |= Cy_AutAnalog_DAC_LoadConfig(cfgIdx, analogCfg->dac[cfgIdx]);
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
                }
            }
#endif

            /* Configure SAR */
#if defined (CY_IP_MXS22LPPASS_SAR) && !defined (CY_AUTANALOG_SAR_DISABLE)
            for (cfgIdx = 0U; cfgIdx < PASS_NR_SARS; cfgIdx++)
            {
#ifndef SAR_BASE
                break;
#endif
                if (NULL != analogCfg->sar[cfgIdx])
                {
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
                    retVal |= Cy_AutAnalog_SAR_LoadConfig(cfgIdx, analogCfg->sar[cfgIdx]);
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
                }
            }
#endif

            /* Configure AC */
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
            retVal |= Cy_AutAnalog_AC_LoadConfig(analogCfg->ac);
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
#if !defined (CY_AUTANALOG_TRIMM_DISABLE)
            /* Read and apply trimming values for the LPPASS subsystems */
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, 'Review shows that usage type enum as operand to the arithmetic operator OR does not have any negative drawbacks');
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.4', 1, 'Review shows that interpretation of type enum as uint32_t does not have any negative drawbacks');
            retVal |= Analog_LoadTrimmValues(analogCfg);
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.4');
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1');
#endif
            /* Check the need for start-up/settling delays according to the configuration provided */
            for (int32_t i = (int32_t)CY_AUTANALOG_PRIORITY_ENABLER_NUM - 1; i >= 0; i--)
            {
                /* Check for assignment of any subsystem in the particular delay group */
                if (0U == (AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, (uint32_t)i) & 0x0001FF00UL)) /* Mask for all subsystems */
                {
                    /* Delete unnecessary delay for empty group */
                    AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, (uint32_t)i) = 0U;
                }
                else
                {
                    /* Stop at the first occupied group counted from the end */
                    break;
                }
            }
        }
    }

    return retVal;
}


cy_en_autanalog_status_t Cy_AutAnalog_LoadStateTransitionTable(uint8_t numEntries, const cy_stc_autanalog_stt_t * stateTransitionTable)
{
    cy_en_autanalog_status_t retVal = CY_AUTANALOG_BAD_PARAM;

    if ((CY_AUTANALOG_STATE_TRANSITION_TABLE_STATES_NUM >= numEntries) && (NULL != stateTransitionTable))
    {
        uint8_t stateIdx;

        /* Resets to default the MMIO registers that contain the State Transition table */
        for (stateIdx = 0U; stateIdx < CY_AUTANALOG_STATE_TRANSITION_TABLE_STATES_NUM; stateIdx++)
        {
            AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, stateIdx) = 0x0UL;
            AUTANALOG_AC_TT_CFG1(ACTRLR_BASE, stateIdx) = 0x0UL;
            AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, stateIdx) = 0x0UL;
            AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, stateIdx) = 0x0UL;
            AUTANALOG_AC_TT_CFG4(ACTRLR_BASE, stateIdx) = 0x0UL;
        }

        /* Updates the MMIO registers that contain the State Transition table */
        retVal = Cy_AutAnalog_UpdateStateTransitionTable(numEntries, stateTransitionTable, 0U);
    }

    return retVal;
}


cy_en_autanalog_status_t Cy_AutAnalog_UpdateStateTransitionTable(uint8_t numEntries, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t startState)
{
    cy_en_autanalog_status_t retVal = CY_AUTANALOG_BAD_PARAM;

    /* Checks the valid ranges for the STT update */
    if ((numEntries > 0U) && (CY_AUTANALOG_STATE_TRANSITION_TABLE_STATES_NUM - startState >= numEntries) && (NULL != stateTransitionTable))
    {
        uint8_t stateIdx;

        for (stateIdx = 0U; stateIdx < numEntries; stateIdx++)
        {
            /* Updates the section of the STT related to the AC */
            Analog_UpdateTimerTable_AC(stateIdx, stateTransitionTable, startState);

#if !defined (CY_AUTANALOG_PRB_DISABLE)
            /* Updates the section of STT related to the PRB */
            Analog_UpdateTimerTable_PRB(stateIdx, stateTransitionTable, startState);
#endif

#if defined (CY_IP_MXS22LPPASS_CTB) && !defined (CY_AUTANALOG_CTB_DISABLE)
            /* Updates the section of STT related to the CTB */
            Analog_UpdateTimerTable_CTB(stateIdx, stateTransitionTable, startState);
#endif

#if defined (CY_IP_MXS22LPPASS_PTC) && !defined (CY_AUTANALOG_PTC_DISABLE)
            /* Updates the section of STT related to the PTComp */
            Analog_UpdateTimerTable_PTC(stateIdx, stateTransitionTable, startState);
#endif

#if defined (CY_IP_MXS22LPPASS_DAC) && !defined (CY_AUTANALOG_DAC_DISABLE)
            /* Updates the section of STT related to the DAC */
            Analog_UpdateTimerTable_DAC(stateIdx, stateTransitionTable, startState);
#endif

#if defined (CY_IP_MXS22LPPASS_SAR) && !defined (CY_AUTANALOG_SAR_DISABLE)
            /* Updates the section of STT related to the SAR ADC */
            Analog_UpdateTimerTable_SAR(stateIdx, stateTransitionTable, startState);
#endif
            startState++;
        }

        retVal = CY_AUTANALOG_SUCCESS;
    }

    return retVal;
}


cy_en_autanalog_status_t Cy_AutAnalog_PRB_LoadConfig(uint8_t prbIdx, const cy_stc_autanalog_prb_t * prbCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_PRB_BAD_PARAM;
    uint32_t regVal;

    if ((CY_AUTANALOG_PRB_NUM > prbIdx) && (NULL != prbCfg))
    {
        if (NULL != prbCfg->prb[prbIdx])
        {
            /* Validate enumerations for PRB_VREF_CTRL register */
            CY_ASSERT_L1(AUTANALOG_PRB_VREF_CTRL_CFG(prbCfg->prb[prbIdx]->src));
            CY_ASSERT_L1(AUTANALOG_PRB_VREF_CTRL_VAL(prbCfg->prb[prbIdx]->tap));

            /* Define value for PRB_VREF_CTRL register */
            regVal = _VAL2FLD(INFRA_PRB_VREF_CTRL_CFG, prbCfg->prb[prbIdx]->src);
            regVal |= _VAL2FLD(INFRA_PRB_VREF_CTRL_VAL, prbCfg->prb[prbIdx]->tap);
            regVal |= _VAL2FLD(INFRA_PRB_VREF_CTRL_EN, prbCfg->prb[prbIdx]->enable);

            /* Update PRB_VREF_CTRL register */
            AUTANALOG_INFRA_PRB_VREF_CTRL(INFRA_BASE, prbIdx) = regVal;

            /* Start up delay depends on used Vref for the PRB: VDDA (150uS) or VBGR (100uS) */
            Cy_SysLib_DelayUs(prbCfg->prb[prbIdx]->src == CY_AUTANALOG_PRB_VDDA ? 150U : 100U);
        }

        result = CY_AUTANALOG_SUCCESS;
    }

    return result;
}


void Cy_AutAnalog_PRB_Write(uint8_t prbIdx, cy_en_autanalog_prb_tap_t tap)
{
    uint32_t regVal;

    /* Validate enumerations for PRB_VREF_CTRL register */
    CY_ASSERT_L1(AUTANALOG_PRB_IDX(prbIdx));
    CY_ASSERT_L1(AUTANALOG_PRB_VREF_CTRL_VAL(tap));

    /* Sets the value for PRB_VREF_CTRL register */
    regVal = AUTANALOG_INFRA_PRB_VREF_CTRL(INFRA_BASE, prbIdx);
    regVal &= ~INFRA_PRB_VREF_CTRL_VAL_Msk;
    regVal |= _VAL2FLD(INFRA_PRB_VREF_CTRL_VAL, tap);

    /* Updates the PRB_VREF_CTRL register */
    AUTANALOG_INFRA_PRB_VREF_CTRL(INFRA_BASE, prbIdx) = regVal;
}

#if !defined (CY_AUTANALOG_TRIMM_DISABLE)
/*******************************************************************************
* Function Name: Analog_LoadTrimmValues
****************************************************************************//**
*
* Used to load trimming values for Autonomous Analog from RRAM into MMIO.
*
* \param analogCfg
* The pointer to the structure containing configuration data
* for the entire Autonomous Analog.
*
* \return
* Status of operation, \ref cy_en_autanalog_status_t.
*
*******************************************************************************/
static cy_en_autanalog_status_t Analog_LoadTrimmValues(const cy_stc_autanalog_cfg_t * analogCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_BAD_PARAM;

    if (NULL != analogCfg)
    {
        result = CY_AUTANALOG_TRIMM_ERR;

        uint32_t trimmData[TRIMM_SECTION_SIZE_BYTES / sizeof(int)];

        /* Read array of trimming constants */
        if (Cy_Trimm_ReadRRAMdata(TRIMM_SECTION_SIZE_BYTES, trimmData))
        {
            result = CY_AUTANALOG_SUCCESS;

            uint8_t idx;

            /* Die temperature */
            Cy_AutAnalog_SAR_LoadDieTempTrimmCoeff(trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DIE_TEMP],
                                                   trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DIE_TEMP + 1U],
                                                   trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DIE_TEMP + 2U],
                                                   trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DIE_TEMP + 3U]);

#if defined (CY_IP_MXS22LPPASS_CTB) && !defined (CY_AUTANALOG_CTB_DISABLE)
            /* Check CTB configuration */
#if defined(CTBL0_BASE)
            uint8_t offset_CTB0_1X = 7U; /* Relative offset from CTB0_10X */
#endif
#if defined(CTBL1_BASE)
            uint8_t offset_CTB1_1X = 7U; /* Relative offset from CTB1_10X */
#endif

#if !((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
/* Defines position and size of trim data in RRAM based on OpAmps power mode */
#define CTB_OA_PWR_HIGH_Pos              0UL
#define CTB_OA_PWR_HIGH_Msk              0xFFUL
#define CTB_OA_PWR_ULTRA_HIGH_Pos        8UL
#define CTB_OA_PWR_ULTRA_HIGH_Msk        0xFF00UL
#define CTB_OA_PWR_MEDIUM_Pos            16UL
#define CTB_OA_PWR_MEDIUM_Msk            0xFF0000UL
#endif

#if defined(CTBL0_BASE)
            if (NULL != analogCfg->ctb[0U])
            {
                if ((NULL != analogCfg->ctb[0U]->ctbDynCfgArr) && (0U < analogCfg->ctb[0U]->ctbDynCfgNum))
                {
                    for (idx = 0U; idx < analogCfg->ctb[0U]->ctbDynCfgNum; idx++)
                    {
                        if (analogCfg->ctb[0U]->ctbDynCfgArr[idx].outToPin)
                        {
                            offset_CTB0_1X = 0U;
                            break;
                        }
                    }
                }
            }

#if ((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
            /* CTB0, OA0 */
            CTBL0->TRIM.OA0_OFFSET_TRIM       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA0_10X + offset_CTB0_1X];
            CTBL0->TRIM.OA0_SLOPE_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA0_10X + offset_CTB0_1X + 1U];

            /* CTB0, OA1 */
            CTBL0->TRIM.OA1_OFFSET_TRIM       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA1_10X + offset_CTB0_1X];
            CTBL0->TRIM.OA1_SLOPE_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA1_10X + offset_CTB0_1X + 1U];
#else
            /* CTB0, OA0 */
            uint32_t ctb0Oa0_OffsetTrim       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA0_10X + offset_CTB0_1X];
            uint32_t ctb0Oa0_SlopeTrim        = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA0_10X + offset_CTB0_1X + 1U];

            /* CTB0, OA1 */
            uint32_t ctb0Oa1_OffsetTrim       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA1_10X + offset_CTB0_1X];
            uint32_t ctb0Oa1_SlopeTrim        = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_OA1_10X + offset_CTB0_1X + 1U];

            if (NULL != analogCfg->ctb[0U])
            {
                if (NULL != analogCfg->ctb[0U]->ctbStaCfg)
                {
                    /* CTB0, OA0 */
                    if (analogCfg->ctb[0U]->ctbStaCfg->pwrOpamp0 == CY_AUTANALOG_CTB_OA_PWR_ULTRA_HIGH_RAIL)
                    {
                        CTBL0->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb0Oa0_OffsetTrim);
                        CTBL0->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb0Oa0_SlopeTrim);
                    }
                    else if (analogCfg->ctb[0U]->ctbStaCfg->pwrOpamp0 == CY_AUTANALOG_CTB_OA_PWR_HIGH_RAIL)
                    {
                        CTBL0->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_HIGH, ctb0Oa0_OffsetTrim);
                        CTBL0->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_HIGH, ctb0Oa0_SlopeTrim);
                    }
                    else
                    {
                        CTBL0->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa0_OffsetTrim);
                        CTBL0->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa0_SlopeTrim);
                    }

                    /* CTB0, OA1 */
                    if (analogCfg->ctb[0U]->ctbStaCfg->pwrOpamp1 == CY_AUTANALOG_CTB_OA_PWR_ULTRA_HIGH_RAIL)
                    {
                        CTBL0->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb0Oa1_OffsetTrim);
                        CTBL0->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb0Oa1_SlopeTrim);
                    }
                    else if (analogCfg->ctb[0U]->ctbStaCfg->pwrOpamp1 == CY_AUTANALOG_CTB_OA_PWR_HIGH_RAIL)
                    {
                        CTBL0->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_HIGH, ctb0Oa1_OffsetTrim);
                        CTBL0->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_HIGH, ctb0Oa1_SlopeTrim);
                    }
                    else
                    {
                        CTBL0->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa1_OffsetTrim);
                        CTBL0->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa1_SlopeTrim);
                    }
                }
            }
            else /* Default value */
            {
                /* CTB0, OA0 */
                CTBL0->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa0_OffsetTrim);
                CTBL0->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa0_SlopeTrim);

                /* CTB0, OA1 */
                CTBL0->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa1_OffsetTrim);
                CTBL0->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb0Oa1_SlopeTrim);
            }
#endif

            /* CTB0, RMR */
            CTBL0->TRIM.RMP_TRIM              = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB0_10X_RMP + offset_CTB0_1X];
#endif /* CTBL0_BASE */

#if defined(CTBL1_BASE)
            if (NULL != analogCfg->ctb[1U])
            {
                if ((NULL != analogCfg->ctb[1U]->ctbDynCfgArr) && (0U < analogCfg->ctb[1U]->ctbDynCfgNum))
                {
                    for (idx = 0U; idx < analogCfg->ctb[1U]->ctbDynCfgNum; idx++)
                    {
                        if (analogCfg->ctb[1U]->ctbDynCfgArr[idx].outToPin)
                        {
                            offset_CTB1_1X = 0U;
                            break;
                        }
                    }
                }
            }

#if ((CY_IP_MXS22LPPASS_VERSION == 1UL) && (CY_IP_MXS22LPPASS_VERSION_MINOR == 0UL))
            /* CTB1, OA0 */
            CTBL1->TRIM.OA0_OFFSET_TRIM       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA0_10X + offset_CTB1_1X];
            CTBL1->TRIM.OA0_SLOPE_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA0_10X + offset_CTB1_1X + 1U];

            /* CTB1, OA1 */
            CTBL1->TRIM.OA1_OFFSET_TRIM       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA1_10X + offset_CTB1_1X];
            CTBL1->TRIM.OA1_SLOPE_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA1_10X + offset_CTB1_1X + 1U];
#else
            /* CTB1, OA0 */
            uint32_t ctb1Oa0_OffsetTrim       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA0_10X + offset_CTB1_1X];
            uint32_t ctb1Oa0_SlopeTrim        = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA0_10X + offset_CTB1_1X + 1U];

            /* CTB1, OA1 */
            uint32_t ctb1Oa1_OffsetTrim       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA1_10X + offset_CTB1_1X];
            uint32_t ctb1Oa1_SlopeTrim        = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_OA1_10X + offset_CTB1_1X + 1U];

            if (NULL != analogCfg->ctb[1U])
            {
                if (NULL != analogCfg->ctb[1U]->ctbStaCfg)
                {
                    /* CTB1, OA0 */
                    if (analogCfg->ctb[1U]->ctbStaCfg->pwrOpamp0 == CY_AUTANALOG_CTB_OA_PWR_ULTRA_HIGH_RAIL)
                    {
                        CTBL1->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb1Oa0_OffsetTrim);
                        CTBL1->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb1Oa0_SlopeTrim);
                    }
                    else if (analogCfg->ctb[1U]->ctbStaCfg->pwrOpamp0 == CY_AUTANALOG_CTB_OA_PWR_HIGH_RAIL)
                    {
                        CTBL1->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_HIGH, ctb1Oa0_OffsetTrim);
                        CTBL1->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_HIGH, ctb1Oa0_SlopeTrim);
                    }
                    else
                    {
                        CTBL1->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa0_OffsetTrim);
                        CTBL1->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa0_SlopeTrim);
                    }

                    /* CTB1, OA1 */
                    if (analogCfg->ctb[1U]->ctbStaCfg->pwrOpamp1 == CY_AUTANALOG_CTB_OA_PWR_ULTRA_HIGH_RAIL)
                    {
                        CTBL1->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb1Oa1_OffsetTrim);
                        CTBL1->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_ULTRA_HIGH, ctb1Oa1_SlopeTrim);
                    }
                    else if (analogCfg->ctb[1U]->ctbStaCfg->pwrOpamp1 == CY_AUTANALOG_CTB_OA_PWR_HIGH_RAIL)
                    {
                        CTBL1->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_HIGH, ctb1Oa1_OffsetTrim);
                        CTBL1->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_HIGH, ctb1Oa1_SlopeTrim);
                    }
                    else
                    {
                        CTBL1->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa1_OffsetTrim);
                        CTBL1->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa1_SlopeTrim);
                    }
                }
            }
            else /* Default value */
            {
                /* CTB1, OA0 */
                CTBL1->TRIM.OA0_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa0_OffsetTrim);
                CTBL1->TRIM.OA0_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa0_SlopeTrim);

                /* CTB1, OA1 */
                CTBL1->TRIM.OA1_OFFSET_TRIM       = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa1_OffsetTrim);
                CTBL1->TRIM.OA1_SLOPE_OFFSET_TRIM = _FLD2VAL(CTB_OA_PWR_MEDIUM, ctb1Oa1_SlopeTrim);
            }
#endif

            /* CTB1, RMR */
            CTBL1->TRIM.RMP_TRIM              = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_CTB1_10X_RMP + offset_CTB1_1X];
#endif /* CTBL1_BASE */
#endif /* CY_IP_MXS22LPPASS_CTB */

#if defined (CY_IP_MXS22LPPASS_PTC) && !defined (CY_AUTANALOG_PTC_DISABLE)
#if defined(PTC_BASE)
            /* PTC */
            PTC->TRIM.CMP0_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_PTC];
            PTC->TRIM.CMP1_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_PTC + 1U];
#endif /* PTC_BASE */
#endif /* CY_IP_MXS22LPPASS_PTC */

#if defined (CY_IP_MXS22LPPASS_DAC) && !defined (CY_AUTANALOG_DAC_DISABLE)
#if defined(DAC0_BASE)
            /* DAC0 */
            DAC0->TRIM.REFBUF_OFFSET_TRIM           = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0];
            DAC0->TRIM.REFBUF_SLOPE_OFFSET_TRIM     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 1U];
            DAC0->TRIM.REFBUF_COMP_TRIM             = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 2U];
            DAC0->TRIM.OUTBUF_OFFSET_TRIM[0U]       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 3U];
            DAC0->TRIM.OUTBUF_OFFSET_TRIM[1U]       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 4U];
            DAC0->TRIM.OUTBUF_SLOPE_OFFSET_TRIM[0U] = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 5U];
            DAC0->TRIM.OUTBUF_SLOPE_OFFSET_TRIM[1U] = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 6U];
            DAC0->TRIM.OUTBUF_COMP_TRIM[0U]         = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 7U];
            DAC0->TRIM.OUTBUF_COMP_TRIM[1U]         = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 8U];
            DAC0->TRIM.RMP_TRIM                     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC0 + 9U];
#endif /* DAC0_BASE */

#if defined(DAC1_BASE)
            /* DAC1 */
            DAC1->TRIM.REFBUF_OFFSET_TRIM           = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1];
            DAC1->TRIM.REFBUF_SLOPE_OFFSET_TRIM     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 1U];
            DAC1->TRIM.REFBUF_COMP_TRIM             = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 2U];
            DAC1->TRIM.OUTBUF_OFFSET_TRIM[0U]       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 3U];
            DAC1->TRIM.OUTBUF_OFFSET_TRIM[1U]       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 4U];
            DAC1->TRIM.OUTBUF_SLOPE_OFFSET_TRIM[0U] = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 5U];
            DAC1->TRIM.OUTBUF_SLOPE_OFFSET_TRIM[1U] = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 6U];
            DAC1->TRIM.OUTBUF_COMP_TRIM[0U]         = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 7U];
            DAC1->TRIM.OUTBUF_COMP_TRIM[1U]         = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 8U];
            DAC1->TRIM.RMP_TRIM                     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_DAC1 + 9U];
#endif /* DAC1_BASE */
#endif /* CY_IP_MXS22LPPASS_DAC */

#if defined (CY_IP_MXS22LPPASS_SAR) && !defined (CY_AUTANALOG_SAR_DISABLE)
#if defined(SAR_BASE)
            /* SAR, HS */
            SAR->HS_CAL_MEM.CALCTRL     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_HS_CALCTRL];
            SAR->HS_CAL_MEM.CONVCTRL    = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_HS_CALCTRL + 1U];
            SAR->HS_CAL_MEM.ADFTMUX     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_HS_CALCTRL + 2U];
            for (idx = 0U; idx < 10U; idx++)
            {
                SAR->HS_CAL_MEM.CALMEM0[idx] = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_HS_CALCTRL + 3U + idx];
            }

            /* SAR, LP */
            SAR->LP_CAL_MEM.CALCTRL     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_LP_CALCTRL];
            SAR->LP_CAL_MEM.CONVCTRL    = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_LP_CALCTRL + 1U];
            SAR->LP_CAL_MEM.ADFTMUX     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_LP_CALCTRL + 2U];
            SAR->LP_CAL_MEM.CALMEM0     = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC_LP_CALCTRL + 3U];

            /* SAR, TRIM */
            SAR->TRIM.BUF0_OFFSET_TRIM       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC];
            SAR->TRIM.BUF0_SLOPE_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC + 1U];
            SAR->TRIM.BUF0_COMP_TRIM         = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC + 2U];
            SAR->TRIM.BUF1_OFFSET_TRIM       = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC + 3U];
            SAR->TRIM.BUF1_SLOPE_OFFSET_TRIM = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC + 4U];
            SAR->TRIM.BUF1_COMP_TRIM         = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC + 5U];
            SAR->TRIM.RMP_TRIM               = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_ADC + 6U];
#endif /* SAR_BASE */
#endif /* CY_IP_MXS22LPPASS_SAR */

            /* INFRA, LPOSC */
            INFRA->LPOSC.TRIM      = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_LPOSC];

            /* INFRA, AREF */
            INFRA->AREF.VREF_TRIM0  = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF];
            INFRA->AREF.VREF_TRIM1  = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 1U];
            INFRA->AREF.VREF_TRIM2  = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 2U];
            INFRA->AREF.VREF_TRIM3  = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 3U];
            INFRA->AREF.IZTAT_TRIM0 = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 4U];
            INFRA->AREF.IPTAT_TRIM0 = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 5U];
            INFRA->AREF.IPTAT_TRIM1 = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 6U];
            INFRA->AREF.ICTAT_TRIM0 = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 7U];
            INFRA->AREF.ICTAT_TRIM1 = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 8U];
            INFRA->AREF.ICTAT_TRIM2 = trimmData[AUTANALOG_RRAM_TRIMM_START_IDX_AREF + 9U];
        }
    }

    return result;
}
#endif

/*******************************************************************************
* Function Name: Analog_UpdateTimerTable_AC
****************************************************************************//**
*
* Used to update a particular state in the State Transition Table for the AC subsystem.
*
* \param stateIdx
* Defines the state in the State Transition Table to update the AC subsystem.
*
* \param stateTransitionTable
* Pointer to array containing new set of configuration data for State Transition Table,
* which must be updated.
*
*******************************************************************************/
static void Analog_UpdateTimerTable_AC(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState)
{
    if (NULL != stateTransitionTable[stateIdx].ac)
    {
        uint32_t regVal;

        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_DOUT_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_MODE_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_MODE_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_PRB_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_CTBL0_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_CTBL1_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_PTC_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_DAC0_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_DAC1_UNLOCK_Msk;
        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK_Msk;

        CY_ASSERT_L3(AUTANALOG_STT_AC_CFG0_DOUT(stateTransitionTable[stateIdx].ac->gpioOut));

        regVal =
                _BOOL2FLD(ACTRLR_TTCFG_TT_CFG0_DOUT_UNLOCK, stateTransitionTable[stateIdx].ac->unlockGpioOut) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_DOUT, stateTransitionTable[stateIdx].ac->gpioOut) |
                _BOOL2FLD(ACTRLR_TTCFG_TT_CFG0_MODE, stateTransitionTable[stateIdx].ac->lpMode) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_MODE_UNLOCK, stateTransitionTable[stateIdx].ac->unlock);

#if !defined (CY_AUTANALOG_PRB_DISABLE)
                if (NULL != stateTransitionTable[stateIdx].prb)
                {
                    regVal |= _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_PRB_UNLOCK, stateTransitionTable[stateIdx].prb->unlock);
                }
#endif

#if defined (CY_IP_MXS22LPPASS_CTB) && !defined (CY_AUTANALOG_CTB_DISABLE)
                for (uint8_t devIdx = 0U; devIdx < PASS_NR_CTBLS; devIdx++)
                {
#ifndef CTBL0_BASE
                    if (0U == devIdx)
                    {
                        continue;
                    }
#endif
#ifndef CTBL1_BASE
                    if (1U == devIdx)
                    {
                        continue;
                    }
#endif
                    if (NULL != stateTransitionTable[stateIdx].ctb[devIdx])
                    {
                        regVal |= (0U == devIdx) ?
                       _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_CTBL0_UNLOCK, stateTransitionTable[stateIdx].ctb[devIdx]->unlock) :
                       _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_CTBL1_UNLOCK, stateTransitionTable[stateIdx].ctb[devIdx]->unlock);
                    }
                }
#endif

#if defined (CY_IP_MXS22LPPASS_PTC) && !defined (CY_AUTANALOG_PTC_DISABLE)
#if defined(PTC_BASE)
                if (NULL != stateTransitionTable[stateIdx].ptcomp[0U])
                {
                    regVal |= _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_PTC_UNLOCK, stateTransitionTable[stateIdx].ptcomp[0U]->unlock);
                }
#endif
#endif

#if defined (CY_IP_MXS22LPPASS_DAC) && !defined (CY_AUTANALOG_DAC_DISABLE)
                for (uint8_t devIdx = 0U; devIdx < PASS_NR_DACS; devIdx++)
                {
#ifndef DAC0_BASE
                    if (0U == devIdx)
                    {
                        continue;
                    }
#endif
#ifndef DAC1_BASE
                    if (1U == devIdx)
                    {
                        continue;
                    }
#endif
                    if (NULL != stateTransitionTable[stateIdx].dac[devIdx])
                    {
                        regVal |= (0U == devIdx) ?
                       _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_DAC0_UNLOCK, stateTransitionTable[stateIdx].dac[devIdx]->unlock) :
                       _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_DAC1_UNLOCK, stateTransitionTable[stateIdx].dac[devIdx]->unlock);
                    }
                }
#endif

#if defined (CY_IP_MXS22LPPASS_SAR) && !defined (CY_AUTANALOG_SAR_DISABLE)
#if defined(SAR_BASE)
                if (NULL != stateTransitionTable[stateIdx].sar[0U])
                {
                    regVal |= _VAL2FLD(ACTRLR_TTCFG_TT_CFG0_SAR_UNLOCK, stateTransitionTable[stateIdx].sar[0U]->unlock);
                }
#endif
#endif

        AUTANALOG_AC_TT_CFG0(ACTRLR_BASE, targetState) |= regVal;

        /* AUTANALOG_AC_TT_CFG1 */
        CY_ASSERT_L3(AUTANALOG_STT_AC_CFG1_CNT(stateTransitionTable[stateIdx].ac->count));
        CY_ASSERT_L3(AUTANALOG_STT_AC_CFG1_ACTION(stateTransitionTable[stateIdx].ac->action));
        CY_ASSERT_L3(AUTANALOG_STT_AC_CFG1_COND(stateTransitionTable[stateIdx].ac->condition));
        CY_ASSERT_L3(AUTANALOG_STT_AC_CFG1_BR_ADDR(stateTransitionTable[stateIdx].ac->branchState));

        regVal =
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG1_CNT, stateTransitionTable[stateIdx].ac->count) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG1_ACTION, stateTransitionTable[stateIdx].ac->action) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG1_COND, stateTransitionTable[stateIdx].ac->condition) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG1_BR_ADDR, stateTransitionTable[stateIdx].ac->branchState) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG1_INTR_SET, stateTransitionTable[stateIdx].ac->trigInt);

        AUTANALOG_AC_TT_CFG1(ACTRLR_BASE, targetState) = regVal;
    }
}


#if !defined (CY_AUTANALOG_PRB_DISABLE)
/*******************************************************************************
* Function Name: Analog_UpdateTimerTable_PRB
****************************************************************************//**
*
* Used to update a particular state in the State Transition Table for the PRB subsystem.
*
* \param stateIdx
* Defines the state in the State Transition Table to update the PRB subsystem.
*
* \param stateTransitionTable
* Pointer to array containing new set of configuration data for State Transition Table,
* which must be updated.
*
*******************************************************************************/
static void Analog_UpdateTimerTable_PRB(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState)
{
    if (NULL != stateTransitionTable[stateIdx].prb)
    {
        uint32_t regVal;

        /* AUTANALOG_AC_TT_CFG4 */
        CY_ASSERT_L3(AUTANALOG_PRB_VREF_CTRL_VAL(stateTransitionTable[stateIdx].prb->prbVref0Tap));
        CY_ASSERT_L3(AUTANALOG_PRB_VREF_CTRL_VAL(stateTransitionTable[stateIdx].prb->prbVref1Tap));

        regVal =
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG4_PRB_VREF0_FW_MODE, stateTransitionTable[stateIdx].prb->prbVref0Fw) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG4_PRB_VREF0_VAL, stateTransitionTable[stateIdx].prb->prbVref0Tap) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG4_PRB_VREF1_FW_MODE, stateTransitionTable[stateIdx].prb->prbVref1Fw) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG4_PRB_VREF1_VAL, stateTransitionTable[stateIdx].prb->prbVref1Tap);

        AUTANALOG_AC_TT_CFG4(ACTRLR_BASE, targetState) = regVal;
    }
}
#endif


/* Two instances of the CTB are currently supported */
#if defined (CY_IP_MXS22LPPASS_CTB) && !defined (CY_AUTANALOG_CTB_DISABLE)
/*******************************************************************************
* Function Name: Analog_UpdateTimerTable_CTB
****************************************************************************//**
*
* Used to update a particular state in the State Transition Table for the CTB subsystem.
*
* \param stateIdx
* Defines the state in the State Transition Table for update of the CTB subsystem.
*
* \param stateTransitionTable
* Pointer to array containing new set of configuration data for State Transition Table,
* which must be updated.
*
*******************************************************************************/
static void Analog_UpdateTimerTable_CTB(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState)
{
    uint8_t devIdx;
    uint32_t regVal;

    for (devIdx = 0U; devIdx < PASS_NR_CTBLS; devIdx++)
    {
#ifndef CTBL0_BASE
        if (0U == devIdx)
        {
            continue;
        }
#endif
#ifndef CTBL1_BASE
        if (1U == devIdx)
        {
            continue;
        }
#endif
        if (NULL != stateTransitionTable[stateIdx].ctb[devIdx])
        {
            /* AUTANALOG_AC_TT_CFG2 */
            CY_ASSERT_L3(AUTANALOG_STT_CTB_CFG(stateTransitionTable[stateIdx].ctb[devIdx]->cfgOpamp0));
            CY_ASSERT_L3(AUTANALOG_STT_CTB_GAIN(stateTransitionTable[stateIdx].ctb[devIdx]->gainOpamp0));
            CY_ASSERT_L3(AUTANALOG_STT_CTB_CFG(stateTransitionTable[stateIdx].ctb[devIdx]->cfgOpamp1));
            CY_ASSERT_L3(AUTANALOG_STT_CTB_GAIN(stateTransitionTable[stateIdx].ctb[devIdx]->gainOpamp1));

            if (0U == devIdx)
            {
                /* CTB0 */
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_EN_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_CFG_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_GAIN_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_EN_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_CFG_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_GAIN_Msk;
            }
            else
            {
                /* CTB1 */
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_EN_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_CFG_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_GAIN_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_EN_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_CFG_Msk;
                AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_GAIN_Msk;
            }

            regVal = (0U == devIdx) ?
                    /* CTB0 */
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_EN, stateTransitionTable[stateIdx].ctb[devIdx]->enableOpamp0) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_CFG, stateTransitionTable[stateIdx].ctb[devIdx]->cfgOpamp0) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL0_OA0_GAIN, stateTransitionTable[stateIdx].ctb[devIdx]->gainOpamp0) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_EN, stateTransitionTable[stateIdx].ctb[devIdx]->enableOpamp1) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_CFG, stateTransitionTable[stateIdx].ctb[devIdx]->cfgOpamp1) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL0_OA1_GAIN, stateTransitionTable[stateIdx].ctb[devIdx]->gainOpamp1):
                    /* CTB1 */
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_EN, stateTransitionTable[stateIdx].ctb[devIdx]->enableOpamp0) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_CFG, stateTransitionTable[stateIdx].ctb[devIdx]->cfgOpamp0) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL1_OA0_GAIN, stateTransitionTable[stateIdx].ctb[devIdx]->gainOpamp0) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_EN, stateTransitionTable[stateIdx].ctb[devIdx]->enableOpamp1) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_CFG, stateTransitionTable[stateIdx].ctb[devIdx]->cfgOpamp1) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG2_CTBL1_OA1_GAIN, stateTransitionTable[stateIdx].ctb[devIdx]->gainOpamp1);

            AUTANALOG_AC_TT_CFG2(ACTRLR_BASE, targetState) |= regVal;
        }
    }
#if !defined (CTBL0_BASE) && !defined (CTBL1_BASE)
    (void) stateIdx;
    (void) stateTransitionTable;
    (void) targetState;
    (void) regVal;
#endif
}
#endif


/* One instance of the PTComp is currently supported */
#if defined (CY_IP_MXS22LPPASS_PTC) && !defined (CY_AUTANALOG_PTC_DISABLE)
/*******************************************************************************
* Function Name: Analog_UpdateTimerTable_PTC
****************************************************************************//**
*
* Used to update a particular state in the State Transition Table for the PTComp subsystem.
*
* \param stateIdx
* Defines the state in the State Transition Table to update the PTComp subsystem.
*
* \param stateTransitionTable
* Pointer to array containing new set of configuration data for State Transition Table,
* which must be updated.
*
*******************************************************************************/
static void Analog_UpdateTimerTable_PTC(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState)
{
    uint32_t regVal;

#if defined(PTC_BASE)
    if (NULL != stateTransitionTable[stateIdx].ptcomp[0U])
    {
        /* AUTANALOG_AC_TT_CFG3 */
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_EN_Msk;
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_CFG_Msk;
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_EN_Msk;
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_CFG_Msk;

        CY_ASSERT_L3(AUTANALOG_STT_PTCOMP_CFG(stateTransitionTable[stateIdx].ptcomp[0U]->dynCfgIdxComp0));
        CY_ASSERT_L3(AUTANALOG_STT_PTCOMP_CFG(stateTransitionTable[stateIdx].ptcomp[0U]->dynCfgIdxComp1));

        regVal =
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_EN, stateTransitionTable[stateIdx].ptcomp[0U]->enableComp0) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_PTC_CMP0_CFG, stateTransitionTable[stateIdx].ptcomp[0U]->dynCfgIdxComp0) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_EN, stateTransitionTable[stateIdx].ptcomp[0U]->enableComp1) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_PTC_CMP1_CFG, stateTransitionTable[stateIdx].ptcomp[0U]->dynCfgIdxComp1);

         AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) |= regVal;
    }
#else
    (void) stateIdx;
    (void) stateTransitionTable;
    (void) targetState;
    (void) regVal;
#endif
}
#endif


/* Two instances of the DAC are currently supported */
#if defined (CY_IP_MXS22LPPASS_DAC) && !defined (CY_AUTANALOG_DAC_DISABLE)
/*******************************************************************************
* Function Name: Analog_UpdateTimerTable_DAC
****************************************************************************//**
*
* Used to update a particular state in the State Transition Table for the DAC subsystem.
*
* \param stateIdx
* Defines the state in the State Transition Table for update of the DAC subsystem.
*
* \param stateTransitionTable
* Pointer to array containing new set of configuration data for State Transition Table,
* which must be updated.
*
*******************************************************************************/
static void Analog_UpdateTimerTable_DAC(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState)
{
    uint8_t devIdx;
    uint32_t regVal;
    uint32_t direction;

    for (devIdx = 0U; devIdx < PASS_NR_DACS; devIdx++)
    {
#ifndef DAC0_BASE
        if (0U == devIdx)
        {
            continue;
        }
#endif
#ifndef DAC1_BASE
        if (1U == devIdx)
        {
            continue;
        }
#endif
        if (NULL != stateTransitionTable[stateIdx].dac[devIdx])
        {
            direction = 0U;

            /* AUTANALOG_AC_TT_CFG3 */
            CY_ASSERT_L3(AUTANALOG_STT_DAC_CHANNEL(stateTransitionTable[stateIdx].dac[devIdx]->channel));
            CY_ASSERT_L3(AUTANALOG_STT_DAC_DIRECTION(stateTransitionTable[stateIdx].dac[devIdx]->direction));

            if (0U == devIdx)
            {
                /* DAC0 */
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC0_EN_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC0_CHANNEL_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC0_INC_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC0_DEC_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC0_TR_Msk;
            }
            else
            {
                /* DAC1 */
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC1_EN_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC1_CHANNEL_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC1_INC_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC1_DEC_Msk;
                AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_DAC1_TR_Msk;
            }

            if (stateTransitionTable[stateIdx].dac[devIdx]->direction != CY_AUTANALOG_DAC_DIRECTION_DISABLED)
            {
                direction = (0U == devIdx) ?
                        /* DAC0 */
                        (stateTransitionTable[stateIdx].dac[devIdx]->direction == CY_AUTANALOG_DAC_DIRECTION_FORWARD ?
                            ACTRLR_TTCFG_TT_CFG3_DAC0_INC_Msk:
                            ACTRLR_TTCFG_TT_CFG3_DAC0_DEC_Msk):
                        /* DAC1 */
                        (stateTransitionTable[stateIdx].dac[devIdx]->direction == CY_AUTANALOG_DAC_DIRECTION_FORWARD ?
                            ACTRLR_TTCFG_TT_CFG3_DAC1_INC_Msk:
                            ACTRLR_TTCFG_TT_CFG3_DAC1_DEC_Msk);
            }

            regVal = (0U == devIdx) ?
                    /* DAC0 */
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_DAC0_EN, stateTransitionTable[stateIdx].dac[devIdx]->enable) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_DAC0_CHANNEL, stateTransitionTable[stateIdx].dac[devIdx]->channel) |
                    direction |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_DAC0_TR, stateTransitionTable[stateIdx].dac[devIdx]->trigger):
                    /* DAC1 */
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_DAC1_EN, stateTransitionTable[stateIdx].dac[devIdx]->enable) |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_DAC1_CHANNEL, stateTransitionTable[stateIdx].dac[devIdx]->channel) |
                    direction |
                    _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_DAC1_TR, stateTransitionTable[stateIdx].dac[devIdx]->trigger);

            AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) |= regVal;
        }
    }
#if !defined (DAC0_BASE) && !defined (DAC1_BASE)
    (void) stateIdx;
    (void) stateTransitionTable;
    (void) targetState;
    (void) regVal;
    (void) direction;
#endif
}
#endif


/* One instance of the SAR is currently supported */
#if defined (CY_IP_MXS22LPPASS_SAR) && !defined (CY_AUTANALOG_SAR_DISABLE)
/*******************************************************************************
* Function Name: Analog_UpdateTimerTable_SAR
****************************************************************************//**
*
* Used to update a particular state in the State Transition Table for the SAR subsystem.
*
* \param stateIdx
* Defines the state in the State Transition Table to update the SAR subsystem.
*
* \param stateTransitionTable
* Pointer to array containing new set of configuration data for State Transition Table,
* which must be updated.
*
*******************************************************************************/
static void Analog_UpdateTimerTable_SAR(uint8_t stateIdx, const cy_stc_autanalog_stt_t * stateTransitionTable, uint8_t targetState)
{
    uint32_t regVal;

#if defined(SAR_BASE)
    if (NULL != stateTransitionTable[stateIdx].sar[0U])
    {
        /* AUTANALOG_AC_TT_CFG3 */
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_SAR_ENTRY_ADDR_Msk;
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_SAR_TR_Msk;
        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) &= ~ACTRLR_TTCFG_TT_CFG3_SAR_EN_Msk;

        CY_ASSERT_L3(AUTANALOG_STT_SAR_STATE(stateTransitionTable[stateIdx].sar[0U]->entryState));

        regVal =
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_SAR_ENTRY_ADDR, stateTransitionTable[stateIdx].sar[0U]->entryState) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_SAR_TR, stateTransitionTable[stateIdx].sar[0U]->trigger) |
                _VAL2FLD(ACTRLR_TTCFG_TT_CFG3_SAR_EN, stateTransitionTable[stateIdx].sar[0U]->enable);

        AUTANALOG_AC_TT_CFG3(ACTRLR_BASE, targetState) |= regVal;
    }
#else
    (void) stateIdx;
    (void) stateTransitionTable;
    (void) targetState;
    (void) regVal;
#endif
}
#endif

#endif /* CY_IP_MXS22LPPASS */

/* [] END OF FILE */

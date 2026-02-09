/***************************************************************************//**
* \file cy_autanalog_ac.c
* \version 2.0
*
* \brief
* Provides the public functions for the Autonomous Controller subsystem of the
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

#include "cy_autanalog_ac.h"

#ifdef CY_IP_MXS22LPPASS

/* Acknowledge delay for changing of operation mode for the FIFO */
#define AUTANALOG_MMIO_FIFO_MODE_ACK_DELAY                          (5U) /* MAX 5uS for acknowledge */
/* Delay for wake-up LPOSC */
#define AUTANALOG_MMIO_LPOSC_WAKEUP_DELAY                           (3U) /* MAX 3uS for wake-up */

/* Validation macros for TIMER register */
#define AUTANALOG_TIMER_CFG(value)                                  ((value) <= CY_AUTANALOG_TIMER_CLK_LF)
/* Validation macros for FW_TR[] registers */
#define AUTANALOG_FW_TRIGG_REG(value)                               ((value) <= CY_AUTANALOG_FW_TRIGGER3)
/* Validation macros for TR_OUT[] registers */
#define AUTANALOG_AC_OUT_TRIGG_REG(value)                           ((value) <= CY_AUTANALOG_AC_OUT_TRIGGER7)
#define AUTANALOG_AC_OUT_TRIGG_MASK(value)                          ((value) != CY_AUTANALOG_AC_OUT_TRIG_MASK_DAC0_EPOCH + 1U)
/* Validation macros for STATE_OVERRIDE register */
#define AUTANALOG_AC_STATE_OVERRIDE(value)                          ((value) < CY_AUTANALOG_STATE_TRANSITION_TABLE_STATES_NUM)


/* Set the SysPm callback parameters */
static cy_stc_syspm_callback_params_t deepSleepCallbackParams =
{
    (void*)LPPASS_MMIO_BASE,
    NULL
};


/* Configure the SysPm callback structure */
cy_stc_syspm_callback_t deepSleepCallback =
{
    &Cy_AutAnalog_DeepSleepCallback,
    CY_SYSPM_DEEPSLEEP,
    0u,
    &deepSleepCallbackParams,
    NULL,
    NULL,
    0
};


cy_en_autanalog_status_t Cy_AutAnalog_AC_LoadConfig(const cy_stc_autanalog_ac_t * acCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_AC_BAD_PARAM;

    if (NULL != acCfg)
    {
        /* Validate enumerations for TIMER register */
        CY_ASSERT_L3(AUTANALOG_TIMER_CFG(acCfg->timer.clkSrc));

        /* Validate enumerations for AUTANALOG_AC_CFG register */
        CY_ASSERT_L3(AUTANALOG_STT_AC_CFG0_DOUT(acCfg->gpioOutEn));

        /* Update TIMER CFG register */
        AUTANALOG_INFRA_TIMER_CFG(INFRA_BASE) = _VAL2FLD(INFRA_TIMER_CFG_CLOCK_SEL, acCfg->timer.clkSrc);

        /* Update TIMER PERIOD register */
        AUTANALOG_INFRA_TIMER_PERIOD(INFRA_BASE) = _VAL2FLD(INFRA_TIMER_PERIOD_PER_VAL, acCfg->timer.period);

        /* Update TIMER CTRL register */
        AUTANALOG_INFRA_TIMER_CTRL(INFRA_BASE) = _VAL2FLD(INFRA_TIMER_CTRL_ENABLED, acCfg->timer.enable);

        /* Update AC CFG register */
        CY_REG32_CLR_SET(AUTANALOG_AC_CFG(ACTRLR_BASE), ACTRLR_CFG_DOUT_EN, acCfg->gpioOutEn);

        /* Setup masks for output triggers, might be optional */
        for (uint8_t trigIdx = 0; trigIdx < CY_AUTANALOG_TRIG_OUT_NUM; trigIdx++)
        {
            if (NULL != acCfg->mask[trigIdx])
            {
                Cy_AutAnalog_SetOutputTriggerMask((cy_en_autanalog_ac_out_trigger_idx_t)trigIdx, *acCfg->mask[trigIdx]);
            }
        }

        /* Unregister SysPm callback (if any) */
        (void)Cy_SysPm_UnregisterCallback(&deepSleepCallback);

        /* Register a new SysPm callback */
        if (Cy_SysPm_RegisterCallback(&deepSleepCallback))
        {
            result = CY_AUTANALOG_SUCCESS;
        }
    }

    return result;
}


void Cy_AutAnalog_StartAutonomousControl(void)
{
    cy_stc_autanalog_state_t currState;

    if (Cy_AutAnalog_GetControllerState(&currState) == CY_AUTANALOG_SUCCESS && currState.ac.status != CY_AUTANALOG_AC_STATUS_RUNNING)
    {
        AUTANALOG_AC_CMD_RUN(ACTRLR_BASE) = 0x1U;
    }
}


uint8_t Cy_AutAnalog_PauseAutonomousControl(void)
{
    AUTANALOG_AC_CMD_PAUSE(ACTRLR_BASE) = 0x1U;

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from uint32_t to uint8_t does not have any negative drawbacks');
    return _FLD2VAL(ACTRLR_STATUS_CUR_STATE, AUTANALOG_AC_STATUS(ACTRLR_BASE));
}


void Cy_AutAnalog_SingleStepAutonomousControl(void)
{
    cy_stc_autanalog_state_t currState;

    if (Cy_AutAnalog_GetControllerState(&currState) == CY_AUTANALOG_SUCCESS && currState.ac.status != CY_AUTANALOG_AC_STATUS_RUNNING)
    {
        AUTANALOG_AC_CMD_SINGLE_STEP(ACTRLR_BASE) = 0x1U;
    }
}


cy_en_autanalog_status_t Cy_AutAnalog_GetControllerState(cy_stc_autanalog_state_t * ctrlState)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_BAD_PARAM;

    uint8_t cntIdx;

    if (NULL != ctrlState)
    {
        /* The Autonomous Controller status and state */
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Review shows that type conversion from uint32_t to enum does not have any negative drawbacks');
        ctrlState->ac.status = (cy_en_autanalog_ac_status_t)_FLD2VAL(ACTRLR_STATUS_STATUS, AUTANALOG_AC_STATUS(ACTRLR_BASE));
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from uint32_t to uint8_t does not have any negative drawbacks');
        ctrlState->ac.state = _FLD2VAL(ACTRLR_STATUS_CUR_STATE, AUTANALOG_AC_STATUS(ACTRLR_BASE));
        ctrlState->lpModeEnabled = _FLD2BOOL(ACTRLR_STATUS_MODE, AUTANALOG_AC_STATUS(ACTRLR_BASE));

        /* The Timer/Counter[] state */
        for (cntIdx = 0U; cntIdx < CY_AUTANALOG_TC_NUM; cntIdx++)
        {
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from uint32_t to uint8_t does not have any negative drawbacks');
            ctrlState->tc[cntIdx].state = _FLD2VAL(ACTRLR_CNTR_STATUS_CUR_STATE, AUTANALOG_AC_CNTR_STATUS(ACTRLR_BASE, cntIdx));
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from uint32_t to uint16_t does not have any negative drawbacks');
            ctrlState->tc[cntIdx].val = _FLD2VAL(ACTRLR_CNTR_STATUS_CUR_CNT, AUTANALOG_AC_CNTR_STATUS(ACTRLR_BASE, cntIdx));
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from uint32_t to boolean does not have any negative drawbacks');
            ctrlState->tc[cntIdx].busy = _FLD2VAL(ACTRLR_CNTR_STATUS_BUSY, AUTANALOG_AC_CNTR_STATUS(ACTRLR_BASE, cntIdx));
        }

        result = CY_AUTANALOG_SUCCESS;
    }

    return result;
}


void Cy_AutAnalog_OverrideControllerState(uint8_t newState)
{
    cy_stc_autanalog_state_t currState;

    CY_ASSERT_L3(AUTANALOG_AC_STATE_OVERRIDE(newState));

    if (Cy_AutAnalog_GetControllerState(&currState) == CY_AUTANALOG_SUCCESS && currState.ac.status != CY_AUTANALOG_AC_STATUS_RUNNING)
    {
        AUTANALOG_AC_CMD_STATE(ACTRLR_BASE) = newState;
    }
}


void Cy_AutAnalog_RunControllerState(uint8_t newState)
{
    Cy_AutAnalog_OverrideControllerState(newState);
    Cy_AutAnalog_StartAutonomousControl();
}


void Cy_AutAnalog_SetOutputTriggerMask(cy_en_autanalog_ac_out_trigger_idx_t trigIdx, cy_en_autanalog_ac_out_trigger_mask_t mask)
{
    CY_ASSERT_L3(AUTANALOG_AC_OUT_TRIGG_REG(trigIdx));
    CY_ASSERT_L3(AUTANALOG_AC_OUT_TRIGG_MASK(mask));

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from enum to uint32_t does not have any negative drawbacks');
    AUTANALOG_MMIO_TR_OUT(LPPASS_MMIO_BASE, trigIdx) = (uint32_t)mask;
}


cy_en_autanalog_ac_out_trigger_mask_t Cy_AutAnalog_GetOutputTriggerMask(cy_en_autanalog_ac_out_trigger_idx_t trigIdx)
{
    CY_ASSERT_L3(AUTANALOG_AC_OUT_TRIGG_REG(trigIdx));

    return (cy_en_autanalog_ac_out_trigger_mask_t)AUTANALOG_MMIO_TR_OUT(LPPASS_MMIO_BASE, trigIdx);
}


void Cy_AutAnalog_FwTrigger(cy_en_autanalog_fw_trigger_t triggNum)
{
    CY_ASSERT_L3(AUTANALOG_FW_TRIGG_REG(triggNum));

    AUTANALOG_AC_FW_TR(ACTRLR_BASE, triggNum) = 0x1U;
}


cy_en_syspm_status_t Cy_AutAnalog_DeepSleepCallback(cy_stc_syspm_callback_params_t *callbackParams, cy_en_syspm_callback_mode_t mode)
{
    cy_en_syspm_status_t ret = CY_SYSPM_FAIL;

    LPPASS_MMIO_Type *baseAddr = (LPPASS_MMIO_Type *) (callbackParams->base);

    switch (mode)
    {
        case CY_SYSPM_CHECK_READY:
        {
            ret = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_CHECK_FAIL:
        {
            ret = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_BEFORE_TRANSITION:
        {
            AUTANALOG_MMIO_FIFO_STA_MODE(baseAddr) = _VAL2FLD(LPPASS_MMIO_STA_MODE_RD_LOCKOUT_EN, true);
            Cy_SysLib_DelayUs(AUTANALOG_MMIO_FIFO_MODE_ACK_DELAY);
            if (!_FLD2BOOL(LPPASS_MMIO_STA_MODE_STATUS_RD_LOCKOUT, AUTANALOG_MMIO_FIFO_STA_MODE_STATUS(baseAddr)))
            {
                Cy_SysLib_DelayUs(AUTANALOG_MMIO_LPOSC_WAKEUP_DELAY);
            }
            ret = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_AFTER_TRANSITION:
        {
            AUTANALOG_MMIO_FIFO_STA_MODE(baseAddr) = _VAL2FLD(LPPASS_MMIO_STA_MODE_RD_LOCKOUT_EN, false);
            Cy_SysLib_DelayUs(AUTANALOG_MMIO_FIFO_MODE_ACK_DELAY);
            ret = _FLD2BOOL(LPPASS_MMIO_STA_MODE_STATUS_RD_LOCKOUT, AUTANALOG_MMIO_FIFO_STA_MODE_STATUS(baseAddr)) ?
                            CY_SYSPM_FAIL : CY_SYSPM_SUCCESS;
        }
        break;

        default:
            CY_ASSERT_L1(false);
        break;
    }

    return (ret);
}

#endif /* CY_IP_MXS22LPPASS */

/* [] END OF FILE */

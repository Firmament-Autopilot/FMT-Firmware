/***************************************************************************//**
* \file cy_tcpwm_pwm.c
* \version 1.80
*
* \brief
*  The source file of the tcpwm driver.
*
********************************************************************************
* \copyright
* Copyright 2016-2025 Cypress Semiconductor Corporation (an Infineon company) or
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

#include "cy_tcpwm_pwm.h"

#ifdef CY_IP_MXTCPWM

#if defined (CY_DEVICE_PSC3)
#include "cy_ms_ctl.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif


/*******************************************************************************
* Function Name: Cy_TCPWM_PWM_Init
****************************************************************************//**
*
* Initializes the counter in the TCPWM block for the PWM operation.
*
* \note After initialization, connected PWM output pins Drive modes
* are set to High-Z state. To set Drive modes as set by PWM output pins
* configuration, call the \ref Cy_TCPWM_PWM_Enable function.
*
* \note PSOC C3 device: This API also tries to disable HRPWM wounding when this feature is
* available on the target device. when HRPWM feature is enabled in the
* configuration structure this function checks if TCPWM wounding register is accessible and
* if yes then activate HRPWM feature. This operation could be done only if the application
* is running in protection context (PCTX) = 2 and because of that HRPWM feature
* could be automatically enable by this function only when PC == 2.
* The example how to activate HRPWM feature on the device which support it is in code snippet
* for this function.
*
* \param base
* The pointer to a TCPWM instance.
*
* \param cntNum
* The Counter instance number in the selected TCPWM.
*
* \param config
* The pointer to a configuration structure. See \ref cy_stc_tcpwm_pwm_config_t.
*
* \return error / status code. See \ref cy_en_tcpwm_status_t.
*
* \funcusage
* \snippet tcpwm/pwm/snippet/main.c snippet_Cy_TCPWM_V1_PWM_Init
* \snippet tcpwm/pwm/snippet/main.c snippet_Cy_TCPWM_V2_PWM_Init
* \snippet tcpwm/pwm/snippet/main.c snippet_Cy_TCPWM_V3_PWM_Init_HRPWM
*
*******************************************************************************/
cy_en_tcpwm_status_t Cy_TCPWM_PWM_Init(TCPWM_Type *base, uint32_t cntNum,  cy_stc_tcpwm_pwm_config_t const *config)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_SUCCESS;

    if ((NULL != base) && (NULL != config))
    {
#if (CY_IP_MXTCPWM_VERSION == 1U)

            TCPWM_CNT_CTRL(base, cntNum) =
                    ((config->enableCompareSwap ? TCPWM_CNT_CTRL_AUTO_RELOAD_CC_Msk : 0UL) |
                    (config->enablePeriodSwap ? TCPWM_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk : 0UL) |
                    _VAL2FLD(TCPWM_CNT_CTRL_ONE_SHOT, config->runMode) |
                    _VAL2FLD(TCPWM_CNT_CTRL_UP_DOWN_MODE, config->pwmAlignment) |
                    _VAL2FLD(TCPWM_CNT_CTRL_MODE, config->pwmMode) |
                    _VAL2FLD(TCPWM_CNT_CTRL_QUADRATURE_MODE,
                        (config->invertPWMOut | (config->invertPWMOutN << 1U))) |
                        (config->killMode << CY_TCPWM_PWM_CTRL_SYNC_KILL_OR_STOP_ON_KILL_POS) |
                        _VAL2FLD(TCPWM_CNT_CTRL_GENERIC, ((CY_TCPWM_PWM_MODE_DEADTIME == config->pwmMode) ?
                                config->deadTimeClocks : config->clockPrescaler)));

            if (CY_TCPWM_PWM_MODE_PSEUDORANDOM == config->pwmMode)
            {
                TCPWM_CNT_COUNTER(base, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_PWM_MODE_PR;
            }
            else
            {
                if (CY_TCPWM_PWM_LEFT_ALIGN == config->pwmAlignment)
                {
                    TCPWM_CNT_COUNTER(base, cntNum) = CY_TCPWM_CNT_UP_INIT_VAL;
                    TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_PWM_MODE_LEFT;
                }
                else if (CY_TCPWM_PWM_RIGHT_ALIGN == config->pwmAlignment)
                {
                    TCPWM_CNT_COUNTER(base, cntNum) = config->period0;
                    TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_PWM_MODE_RIGHT;
                }
                else if ((CY_TCPWM_PWM_CENTER_ALIGN == config->pwmAlignment) || (CY_TCPWM_PWM_ASYMMETRIC_ALIGN == config->pwmAlignment))
                {
                    TCPWM_CNT_COUNTER(base, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                    TCPWM_CNT_TR_CTRL2(base, cntNum) = (config->swapOverflowUnderflow ? CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM_SWAPPED : CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM);
                }
                else
                {
                    /* Invalid mode */
                    status = CY_TCPWM_UNSUPPORTED_FEATURE;
                }
            }

            TCPWM_CNT_CC(base, cntNum) = config->compare0;
            TCPWM_CNT_CC_BUFF(base, cntNum) = config->compare1;
            TCPWM_CNT_PERIOD(base, cntNum) = config->period0;
            TCPWM_CNT_PERIOD_BUFF(base, cntNum) = config->period1;

            if (CY_TCPWM_INPUT_CREATOR != config->countInput)
            {
                TCPWM_CNT_TR_CTRL0(base, cntNum) =
                        (_VAL2FLD(TCPWM_CNT_TR_CTRL0_CAPTURE_SEL, config->swapInput) |
                        _VAL2FLD(TCPWM_CNT_TR_CTRL0_RELOAD_SEL, config->reloadInput) |
                        _VAL2FLD(TCPWM_CNT_TR_CTRL0_START_SEL, config->startInput) |
                        _VAL2FLD(TCPWM_CNT_TR_CTRL0_STOP_SEL, config->killInput) |
                        _VAL2FLD(TCPWM_CNT_TR_CTRL0_COUNT_SEL, config->countInput));
            }

            TCPWM_CNT_TR_CTRL1(base, cntNum) =
                    (_VAL2FLD(TCPWM_CNT_TR_CTRL1_CAPTURE_EDGE, config->swapInputMode) |
                    _VAL2FLD(TCPWM_CNT_TR_CTRL1_RELOAD_EDGE, config->reloadInputMode) |
                    _VAL2FLD(TCPWM_CNT_TR_CTRL1_START_EDGE, config->startInputMode) |
                    _VAL2FLD(TCPWM_CNT_TR_CTRL1_STOP_EDGE, config->killInputMode) |
                    _VAL2FLD(TCPWM_CNT_TR_CTRL1_COUNT_EDGE, config->countInputMode));

            TCPWM_CNT_INTR_MASK(base, cntNum) = config->interruptSources;
#else
            uint32_t grp = TCPWM_GRP_CNT_GET_GRP(cntNum);
            bool enabled_bit = _FLD2BOOL(TCPWM_GRP_CNT_V2_CTRL_ENABLED, TCPWM_GRP_CNT_CTRL(base, grp, cntNum));
#if defined (CY_IP_MXS40TCPWM)
            bool dithering_present = ((bool)TCPWM_GRP_DITHERING_PRESENT(grp));
#endif

            TCPWM_GRP_CNT_CTRL(base, grp, cntNum) =
                    ((config->enableCompareSwap ? TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC0_Msk : 0UL) |
                    (config->enablePeriodSwap ? TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_PERIOD_Msk : 0UL) |
                    _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_ONE_SHOT, config->runMode) |
                    _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_MODE, config->pwmMode) |
                    _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_QUAD_ENCODING_MODE, (config->invertPWMOut | (config->invertPWMOutN << 1U))) |
                    _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_PWM_STOP_ON_KILL, (config->killMode) >> 1UL) |
                    _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_PWM_SYNC_KILL, config->killMode) |
                    _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE, config->pwmOnDisable) |
                    (config->immediateKill ? TCPWM_GRP_CNT_V2_CTRL_PWM_IMM_KILL_Msk : 0UL) |
                    (config->reloadLineSelect ? TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_LINE_SEL_Msk : 0UL) |
#if defined (CY_IP_MXS40TCPWM)
                    _VAL2FLD(TCPWM_GRP_CNT_V3_CTRL_SWAP_ENABLED, config->buffer_swap_enable) |
                    _VAL2FLD(TCPWM_GRP_CNT_V3_CTRL_DITHEREN,(dithering_present ? ((uint32_t)config->dithering_mode) : 0UL)) |
                    _VAL2FLD(TCPWM_GRP_CNT_CTRL_KILL_LINE_POLARITY, config->kill_line_polarity) |
                    _VAL2FLD(TCPWM_GRP_CNT_CTRL_PWM_TC_SYNC_KILL_DT, config->pwm_tc_sync_kill_dt) |
                    _VAL2FLD(TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_DT, config->pwm_sync_kill_dt) |
#endif /* defined (CY_IP_MXS40TCPWM) */
                    (enabled_bit ? TCPWM_GRP_CNT_V2_CTRL_ENABLED_Msk : 0UL));

            if (CY_TCPWM_PWM_MODE_DEADTIME == config->pwmMode)
            {
                TCPWM_GRP_CNT_DT(base, grp, cntNum) =
                        (_VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L, (uint8_t)(config->deadTimeClocks)) |
                        _VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_H, (uint8_t)(config->deadTimeClocks >> 8)) |
                        _VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_COMPL_OUT, config->deadTimeClocks_linecompl_out));
#if defined (CY_IP_MXS40TCPWM)
                TCPWM_GRP_CNT_DT_BUFF(base, grp, cntNum) =
                        (_VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L, (uint8_t)(config->deadTimeClocksBuff)) |
                        _VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_H, (uint8_t)(config->deadTimeClocksBuff >> 8)) |
                        _VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_COMPL_OUT, config->deadTimeClocksBuff_linecompl_out));
#endif /* defined (CY_IP_MXS40TCPWM) */
            }
#if !defined (CY_IP_MXS40TCPWM)
            else
            {
                 TCPWM_GRP_CNT_DT(base, grp, cntNum) = _VAL2FLD(TCPWM_GRP_CNT_V2_DT_DT_LINE_OUT_L, (uint8_t)config->clockPrescaler);
            }
#endif /* !defined (CY_IP_MXS40TCPWM) */
            if (CY_TCPWM_PWM_MODE_PSEUDORANDOM == config->pwmMode)
            {
                TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = CY_TCPWM_PWM_MODE_PR;
            }
            else
            {
                if (CY_TCPWM_PWM_LEFT_ALIGN == config->pwmAlignment)
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                            _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE, CY_TCPWM_PWM_LEFT_ALIGN);
                    TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_CNT_UP_INIT_VAL;
                    TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = (CY_TCPWM_PWM_MODE_LEFT |
                                                                    CY_TCPWM_PWM_MODE_CC1_IGNORE);
                }
                else if (CY_TCPWM_PWM_RIGHT_ALIGN == config->pwmAlignment)
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                            _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE, CY_TCPWM_PWM_RIGHT_ALIGN);
                    TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = config->period0;
                    TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = (CY_TCPWM_PWM_MODE_RIGHT |
                                                                    CY_TCPWM_PWM_MODE_CC1_IGNORE);
                }
                else if (CY_TCPWM_PWM_ASYMMETRIC_ALIGN == config->pwmAlignment)
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                            _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE, CY_TCPWM_PWM_ASYMMETRIC_ALIGN);
                    TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                    TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = ((config->swapOverflowUnderflow ? CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM_SWAPPED : CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM) |
                                                                    CY_TCPWM_PWM_MODE_CC1_IGNORE);
                }
                else if (CY_TCPWM_PWM_CENTER_ALIGN == config->pwmAlignment)
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                            _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE, CY_TCPWM_PWM_CENTER_ALIGN);
                    TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                    TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = ((config->swapOverflowUnderflow ? CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM_SWAPPED : CY_TCPWM_PWM_MODE_CNTR_OR_ASYMM) |
                                                                    CY_TCPWM_PWM_MODE_CC1_IGNORE);
                }
                else if (TCPWM_GRP_CC1(base, grp) && (CY_TCPWM_PWM_ASYMMETRIC_CC0_CC1_ALIGN == config->pwmAlignment))
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                            _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE, CY_TCPWM_PWM_LEFT_ALIGN);
                    TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                    TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = CY_TCPWM_PWM_MODE_ASYMM_CC0_CC1;
                }
                else if (TCPWM_GRP_CC1(base, grp) && (CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN == config->pwmAlignment))
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                            _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_UP_DOWN_MODE, CY_TCPWM_PWM_CENTER_ALIGN);
                    TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_CNT_UP_DOWN_INIT_VAL;
                    TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = CY_TCPWM_PWM_MODE_CNTR_ASYMM_CC0_CC1;
                }
                else
                {
                    /* Invalid mode for specified counter group */
                    status = CY_TCPWM_UNSUPPORTED_FEATURE;
                }
            }

            TCPWM_GRP_CNT_CC0(base, grp, cntNum) = config->compare0;
            TCPWM_GRP_CNT_CC0_BUFF(base, grp, cntNum) = config->compare1;
            TCPWM_GRP_CNT_PERIOD(base, grp, cntNum) = config->period0;

            if (CY_TCPWM_PWM_MODE_PSEUDORANDOM == config->pwmMode)
            {
                TCPWM_GRP_CNT_PERIOD_BUFF(base, grp, cntNum) = config->tapsEnabled;
            }
            else
            {
                TCPWM_GRP_CNT_PERIOD_BUFF(base, grp, cntNum) = config->period1;
            }
#if defined (CY_IP_MXS40TCPWM)
            cy_en_gf_depth_value_t gf_depth_val = (config->glitch_filter_enable) ? config->gf_depth : CY_GLITCH_FILTER_DEPTH_SUPPORT_VALUE_0;
#endif
#if !defined (CY_IP_MXS40TCPWM)
            TCPWM_GRP_CNT_TR_IN_SEL0(base, grp, cntNum) =
                    (_VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_SEL0_CAPTURE0_SEL, config->swapInput) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_SEL0_RELOAD_SEL, config->reloadInput) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_SEL0_STOP_SEL, config->killInput) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_SEL0_COUNT_SEL, config->countInput));

            TCPWM_GRP_CNT_TR_IN_SEL1(base, grp, cntNum) = _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_SEL1_START_SEL, config->startInput);

            TCPWM_GRP_CNT_TR_IN_EDGE_SEL(base, grp, cntNum) =
                    (_VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE0_EDGE, config->swapInputMode) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_RELOAD_EDGE, config->reloadInputMode) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_START_EDGE, config->startInputMode) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_STOP_EDGE, config->killInputMode) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_COUNT_EDGE, config->countInputMode));
#else
            Cy_TCPWM_InputTriggerSetupWithGF(base, cntNum, CY_TCPWM_INPUT_TR_START, config->startInputMode, config->startInput, gf_depth_val);
            Cy_TCPWM_InputTriggerSetupWithGF(base, cntNum, CY_TCPWM_INPUT_TR_RELOAD_OR_INDEX, config->reloadInputMode, config->reloadInput, gf_depth_val);
            Cy_TCPWM_InputTriggerSetupWithGF(base, cntNum, CY_TCPWM_INPUT_TR_STOP_OR_KILL, config->killInputMode, config->killInput, gf_depth_val);
            Cy_TCPWM_InputTriggerSetupWithGF(base, cntNum, CY_TCPWM_INPUT_TR_COUNT, config->countInputMode, config->countInput, gf_depth_val);
            Cy_TCPWM_InputTriggerSetupWithGF(base, cntNum, CY_TCPWM_INPUT_TR_CAPTURE0, config->swapInputMode, config->swapInput, gf_depth_val);
#endif
            TCPWM_GRP_CNT_TR_OUT_SEL(base, grp, cntNum) =
                    (_VAL2FLD(TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT0, config->trigger0Event) |
                     _VAL2FLD(TCPWM_GRP_CNT_V2_TR_OUT_SEL_OUT1, config->trigger1Event));

            TCPWM_GRP_CNT_INTR_MASK(base, grp, cntNum) = config->interruptSources;

            if(TCPWM_GRP_CC1(base, grp))
            {
                TCPWM_GRP_CNT_CC1(base, grp, cntNum) = config->compare2;
                TCPWM_GRP_CNT_CC1_BUFF(base, grp, cntNum) = config->compare3;

                TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                    (config->enableCompare1Swap ? TCPWM_GRP_CNT_V2_CTRL_AUTO_RELOAD_CC1_Msk : 0UL);
#if !defined (CY_IP_MXS40TCPWM)
                TCPWM_GRP_CNT_TR_IN_SEL1(base, grp, cntNum) |= _VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_SEL1_CAPTURE1_SEL, config->kill1Input);
                TCPWM_GRP_CNT_TR_IN_EDGE_SEL(base, grp, cntNum) |=
                    (_VAL2FLD(TCPWM_GRP_CNT_V2_TR_IN_EDGE_SEL_CAPTURE1_EDGE, config->kill1InputMode));
#else
                Cy_TCPWM_InputTriggerSetupWithGF(base, cntNum, CY_TCPWM_INPUT_TR_CAPTURE1, config->kill1InputMode, config->kill1Input, gf_depth_val);
#endif
            }

            if(TCPWM_GRP_AMC(base, grp))
            {
                if(CY_TCPWM_PWM_CENTER_ASYMMETRIC_CC0_CC1_ALIGN != config->pwmAlignment)
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |=
                       ((config->compare0MatchUp ? TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_UP_EN_Msk : 0UL) |
                        (config->compare0MatchDown ? TCPWM_GRP_CNT_V2_CTRL_CC0_MATCH_DOWN_EN_Msk : 0UL) |
                        (config->compare1MatchUp ? TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_UP_EN_Msk : 0UL) |
                        (config->compare1MatchDown ? TCPWM_GRP_CNT_V2_CTRL_CC1_MATCH_DOWN_EN_Msk : 0UL));
                }
                else
                {
                    TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |= CY_TCPWM_PWM_MODE_CNTR_ASYMM_CC0_CC1_MATCH;
                }
            }
            TCPWM_GRP_CNT_LINE_SEL(base, grp, cntNum) = (_VAL2FLD(TCPWM_GRP_CNT_V2_LINE_SEL_OUT_SEL, config->line_out_sel) |
                                                         _VAL2FLD(TCPWM_GRP_CNT_V2_LINE_SEL_COMPL_OUT_SEL, config->linecompl_out_sel));
            TCPWM_GRP_CNT_LINE_SEL_BUFF(base, grp, cntNum) = (_VAL2FLD(TCPWM_GRP_CNT_V2_LINE_SEL_OUT_SEL, config->line_out_sel_buff) |
                                                         _VAL2FLD(TCPWM_GRP_CNT_V2_LINE_SEL_COMPL_OUT_SEL, config->linecompl_out_sel_buff));
#if defined (CY_IP_MXS40TCPWM)
            bool hrpwm_present = ((bool)TCPWM_GRP_HRPWM_PRESENT(grp));
            if(hrpwm_present && config->hrpwm_enable)
            {
            #if defined (CY_DEVICE_PSC3) && defined(CY_PDL_TZ_ENABLED)
                /* There is a hardware issue related to HRPWM feature activation on PSOC C3 devices.
                 *  The workaround for automatic HRPWM availability detection is to check if HRPWM feature is present in the device.
                 *  This workaround will work only in the Secure mode.
                 */
                uint32_t activePC = Cy_Ms_Ctl_GetActivePC(CY_MS_CTL_ID_CM33_0);

                if (activePC < 3UL)
                {
                    uint32_t pc_mask = PPC->PC_MASK[PROT_TCPWM0_BOOT];
                    if (0UL != ((pc_mask >> activePC) & 1UL))
                    {
                        /* Enable HRPWM feature if it is present. */
                       CY_SET_REG32(GET_ALIAS_ADDRESS(CY_SYSTEM_TCPWM_DISABLE_ADDR), 0);
                    }
                }
            #endif /* defined (CY_DEVICE_PSC3) && defined(CY_PDL_TZ_ENABLED)*/

                TCPWM_GRP_CNT_HRPWM_CTRL(base, grp, cntNum) = (_VAL2FLD(TCPWM_GRP_CNT_HRPWM_CTRL_HRPWM_EN, 1UL) |
                    _VAL2FLD(TCPWM_GRP_CNT_HRPWM_CTRL_FREQ_SEL, config->hrpwm_input_freq));
            }

            if(config->dithering_mode != CY_TCPWM_DITHERING_DISABLE)
            {
                TCPWM_GRP_CNT_LFSR(base, grp, cntNum)  = (_VAL2FLD(TCPWM_GRP_CNT_V3_LFSR_PLFSR, config->period_dithering_value) |
                                                  _VAL2FLD(TCPWM_GRP_CNT_V3_LFSR_DLFSR, config->duty_dithering_value) |
                                                  _VAL2FLD(TCPWM_GRP_CNT_V3_LFSR_LIMITER, config->limiter));
            }
            TCPWM_GRP_CNT_PS(base, grp, cntNum) = (_VAL2FLD(TCPWM_GRP_CNT_PS_PS_DIV, config->clockPrescaler));
#endif /*defined (CY_IP_MXS40TCPWM)*/
#endif /* (CY_IP_MXTCPWM_VERSION == 1U) */
    }
    else
    {
        status = CY_TCPWM_BAD_PARAM;
    }

    return(status);
}

/*******************************************************************************
* Function Name: Cy_TCPWM_PWM_DeInit
****************************************************************************//**
*
* De-initializes the counter in the TCPWM block, returns register values to
* default.
*
* \param base
* The pointer to a TCPWM instance.
*
* \param cntNum
* The Counter instance number in the selected TCPWM.
*
* \param config
* The pointer to a configuration structure. See \ref cy_stc_tcpwm_pwm_config_t.
*
* \funcusage
* \snippet tcpwm/pwm/snippet/main.c snippet_Cy_TCPWM_PWM_DeInit
*
*******************************************************************************/
void Cy_TCPWM_PWM_DeInit(TCPWM_Type *base, uint32_t cntNum, cy_stc_tcpwm_pwm_config_t const *config)
{
#if (CY_IP_MXTCPWM_VERSION == 1U)

        TCPWM_CNT_CTRL(base, cntNum) = CY_TCPWM_CNT_CTRL_DEFAULT;
        TCPWM_CNT_COUNTER(base, cntNum) = CY_TCPWM_CNT_COUNTER_DEFAULT;
        TCPWM_CNT_CC(base, cntNum) = CY_TCPWM_CNT_CC_DEFAULT;
        TCPWM_CNT_CC_BUFF(base, cntNum) = CY_TCPWM_CNT_CC_BUFF_DEFAULT;
        TCPWM_CNT_PERIOD(base, cntNum) = CY_TCPWM_CNT_PERIOD_DEFAULT;
        TCPWM_CNT_PERIOD_BUFF(base, cntNum) = CY_TCPWM_CNT_PERIOD_BUFF_DEFAULT;
        TCPWM_CNT_TR_CTRL1(base, cntNum) = CY_TCPWM_CNT_TR_CTRL1_DEFAULT;
        TCPWM_CNT_TR_CTRL2(base, cntNum) = CY_TCPWM_CNT_TR_CTRL2_DEFAULT;
        TCPWM_CNT_INTR(base, cntNum) = CY_TCPWM_CNT_INTR_DEFAULT;
        TCPWM_CNT_INTR_SET(base, cntNum) = CY_TCPWM_CNT_INTR_SET_DEFAULT;
        TCPWM_CNT_INTR_MASK(base, cntNum) = CY_TCPWM_CNT_INTR_MASK_DEFAULT;

        if (CY_TCPWM_INPUT_CREATOR != config->countInput)
        {
            TCPWM_CNT_TR_CTRL0(base, cntNum) = CY_TCPWM_CNT_TR_CTRL0_DEFAULT;
        }
#else
        (void)config;
        uint32_t grp = TCPWM_GRP_CNT_GET_GRP(cntNum);
        bool enabled_bit = _FLD2BOOL(TCPWM_GRP_CNT_V2_CTRL_ENABLED, TCPWM_GRP_CNT_CTRL(base, grp, cntNum));

        TCPWM_GRP_CNT_CTRL(base, grp, cntNum) = (CY_TCPWM_GRP_CNT_CTRL_DEFAULT | (enabled_bit ? TCPWM_GRP_CNT_V2_CTRL_ENABLED_Msk : 0UL));
        TCPWM_GRP_CNT_DT(base, grp, cntNum) = CY_TCPWM_GRP_CNT_DT_DEFAULT;
        TCPWM_GRP_CNT_COUNTER(base, grp, cntNum) = CY_TCPWM_GRP_CNT_COUNTER_DEFAULT;
        TCPWM_GRP_CNT_TR_PWM_CTRL(base, grp, cntNum) = CY_TCPWM_GRP_CNT_TR_PWM_CTRL_DEFAULT;
        TCPWM_GRP_CNT_CC0(base, grp, cntNum) = CY_TCPWM_GRP_CNT_CC0_DEFAULT;
        TCPWM_GRP_CNT_CC0_BUFF(base, grp, cntNum) = CY_TCPWM_GRP_CNT_CC0_BUFF_DEFAULT;
        TCPWM_GRP_CNT_CC1(base, grp, cntNum) = CY_TCPWM_GRP_CNT_CC0_DEFAULT;
        TCPWM_GRP_CNT_CC1_BUFF(base, grp, cntNum) = CY_TCPWM_GRP_CNT_CC0_BUFF_DEFAULT;
        TCPWM_GRP_CNT_PERIOD(base, grp, cntNum) = CY_TCPWM_GRP_CNT_PERIOD_DEFAULT;
        TCPWM_GRP_CNT_PERIOD_BUFF(base, grp, cntNum) = CY_TCPWM_GRP_CNT_PERIOD_BUFF_DEFAULT;
        TCPWM_GRP_CNT_TR_IN_SEL0(base, grp, cntNum) = CY_TCPWM_GRP_CNT_TR_IN_SEL0_DEFAULT;
        TCPWM_GRP_CNT_TR_IN_SEL1(base, grp, cntNum) = CY_TCPWM_GRP_CNT_TR_IN_SEL1_DEFAULT;
        TCPWM_GRP_CNT_TR_IN_EDGE_SEL(base, grp, cntNum) = CY_TCPWM_GRP_CNT_TR_IN_EDGE_SEL_DEFAULT;
        TCPWM_GRP_CNT_INTR_MASK(base, grp, cntNum) = CY_TCPWM_GRP_CNT_INTR_MASK_DEFAULT;
#endif
}

#if defined (CY_IP_MXS40TCPWM) || defined (CY_DOXYGEN)
/*******************************************************************************
* Function Name: Cy_TCPWM_PWM_Configure_Dithering
****************************************************************************//**
*
* configures dithering. applicable only when GRP_DITHERING_PRESENT and in PWM and PWM_DT mode
*
* \param base
* The pointer to a TCPWM instance.
*
* \param cntNum
* The Counter instance number in the selected TCPWM.
*
* \param mode
* Dithering mode See \ref cy_en_tcpwm_dithering_t .
*
* \param period
* initial value for period LFSR. Should be non zero value.
*
* \param duty
* Initial value for duty LFSR. Should be non zero value.
*
* \param limiter
* Dithering limiter values. It defines the magnitude of the pseudo-random value to be added to period/CC0/CC1 \ref cy_en_dithering_limiter_t
*
* \return
* Error / Status code. See cy_en_tcpwm_status_t.
*
*  \note When PWM alignment mode set to "asymmetric CC0 and CC1",
*  The duty width remains the same, because the same value is added to CC0 and CC1. As LFSR is updated at tc event and both CC0 match and CC1 match happen before tc event.
*******************************************************************************/
cy_en_tcpwm_status_t Cy_TCPWM_PWM_Configure_Dithering(TCPWM_Type *base, uint32_t cntNum, cy_en_tcpwm_dithering_t  mode, uint8_t period, uint8_t duty, cy_en_dithering_limiter_t limiter)
{
    cy_en_tcpwm_status_t status = CY_TCPWM_SUCCESS;
    uint32_t grp = TCPWM_GRP_CNT_GET_GRP(cntNum);
    bool dithering_present = ((bool)TCPWM_GRP_DITHERING_PRESENT(grp));
    if(dithering_present)
    {
        if((period == 0U) || (duty == 0U))
        {
            status = CY_TCPWM_BAD_PARAM;
        }
        TCPWM_GRP_CNT_CTRL(base, grp, cntNum) |= _VAL2FLD(TCPWM_GRP_CNT_V3_CTRL_DITHEREN, mode);
        TCPWM_GRP_CNT_LFSR(base, grp, cntNum)  = (_VAL2FLD(TCPWM_GRP_CNT_V3_LFSR_PLFSR, period) |
                                                  _VAL2FLD(TCPWM_GRP_CNT_V3_LFSR_DLFSR, duty) |
                                                  _VAL2FLD(TCPWM_GRP_CNT_V3_LFSR_LIMITER, limiter));
    }
    else
    {
        status = CY_TCPWM_BAD_PARAM;
    }
    return status;
}

#endif /* defined (CY_IP_MXS40TCPWM) */
#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXTCPWM */

/* [] END OF FILE */

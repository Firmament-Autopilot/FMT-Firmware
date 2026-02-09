/***************************************************************************//**
* \file cy_autanalog_dac.c
* \version 2.0
*
* \brief
* Provides an API definition for the CT DAC in the Autonomous Analog driver.
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
#include "cy_autanalog_dac.h"

#ifdef CY_IP_MXS22LPPASS_DAC

/* Helper macros for range validation */
#define AUTANALOG_DAC_CH_IDX(value)                                  ((value) < CY_AUTANALOG_DAC_CH_CFG_NUM)
/* Validation macros for CLOCK_DIV register */
#define AUTANALOG_DAC_CLOCK_DIV(value)                               ((value) <= INFRA_CLOCK_DAC_LP_DIV_DIV_VAL_Msk)
/* Validation macros for CTRL register */
#define AUTANALOG_DAC_TOPO_CFG(value)                                ((value) <= CY_AUTANALOG_DAC_TOPO_BUFFERED_EXTERNAL)
#define AUTANALOG_DAC_VREF_SEL(value)                                ((value) <= CY_AUTANALOG_DAC_VREF_VDDA)
#define AUTANALOG_DAC_REF_BUF_POW(value)                             ((value) <= CY_AUTANALOG_DAC_REF_BUF_PWR_ULTRA_HIGH_RAIL)
#define AUTANALOG_DAC_OUT_BUF_POW(value)                             ((value) <= CY_AUTANALOG_DAC_OUT_BUF_PWR_ULTRA_HIGH_RAIL)
#define AUTANALOG_DAC_VREF_MUX(value)                                ((value) <= CY_AUTANALOG_DAC_VREF_MUX_PRB_OUT1)
/* Validation macros for CHAN_CFG register */
#define AUTANALOG_DAC_START_ADDR(value)                              ((value) <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM - 1U)
#define AUTANALOG_DAC_END_ADDR(value)                                ((value) <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM - 1U)
#define AUTANALOG_DAC_OPER_MODE(value)                               ((value) <= CY_AUTANALOG_DAC_WAVEFORM_MODE_DATA)
#define AUTANALOG_DAC_STEP_SEL(value)                                ((value) <= CY_AUTANALOG_DAC_STEP_SEL_2)
#define AUTANALOG_DAC_STATUS_SEL(value)                              ((value) <= CY_AUTANALOG_DAC_STATUS_SEL_2)
/* Validation macros for CHAN_STATUS_CFG registers */
#define AUTANALOG_DAC_CH_RANGE_COND(value)                           ((value) <= CY_AUTANALOG_DAC_CH_LIMIT_OUTSIDE)


cy_en_autanalog_status_t Cy_AutAnalog_DAC_LoadConfig(uint8_t dacIdx, const cy_stc_autanalog_dac_t * dacCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_DAC_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint16_t sampleIdx;

    if (NULL != dacCfg)
    {
        result = Cy_AutAnalog_DAC_LoadStaticConfig(dacIdx, dacCfg->dacStaCfg);

        /* The waveform configuration may be optional */
        if ((CY_AUTANALOG_SUCCESS == result) && (NULL != dacCfg->waveform))
        {
            CY_ASSERT_L3(!((NULL == dacCfg->waveform->waveformData) && (dacCfg->waveform->numSamples > 0U)));
            CY_ASSERT_L3(!((NULL != dacCfg->waveform->waveformData) && (dacCfg->waveform->numSamples == 0U)));
            CY_ASSERT_L3(!((NULL != dacCfg->waveform->waveformData) && (NULL == dacCfg->waveform->driveMode)));
            CY_ASSERT_L3(!((NULL == dacCfg->waveform->waveformData) && (NULL != dacCfg->waveform->driveMode)));

            result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr);
            if ((NULL != dacCfg->waveform->waveformData) && (NULL != dacCfg->waveform->driveMode))
            {
                if ((dacCfg->waveform->numSamples <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM) && (CY_AUTANALOG_SUCCESS == result))
                {
                    if (!dacCfg->waveform->isDriveModeArray)
                    {
                        CY_ASSERT_L3(AUTANALOG_DAC_OUT_DM(*dacCfg->waveform->driveMode));
                    }

                    for (sampleIdx = 0U; sampleIdx < dacCfg->waveform->numSamples; sampleIdx++)
                    {
                        if (dacCfg->waveform->isDriveModeArray)
                        {
                            CY_ASSERT_L3(AUTANALOG_DAC_OUT_DM(dacCfg->waveform->driveMode[sampleIdx]));
                        }

                        regVal =
                                _VAL2FLD(DAC_SRAM_WAVEFORM, ((uint32_t)(dacCfg->waveform->waveformData[sampleIdx]) &
                                    DAC_STA_FW_DAC_VAL_VALUE_Msk)) |
                                ((dacCfg->waveform->isDriveModeArray) ?
                                _VAL2FLD(DAC_SRAM_OUT_DM, dacCfg->waveform->driveMode[sampleIdx]) :
                                _VAL2FLD(DAC_SRAM_OUT_DM, *dacCfg->waveform->driveMode));

                        AUTANALOG_DAC_LUT(baseAddr, sampleIdx) = regVal;
                    }
                }
                else
                {
                    result = CY_AUTANALOG_DAC_BAD_PARAM;
                }
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_DAC_LoadStaticConfig(uint8_t dacIdx, const cy_stc_autanalog_dac_sta_t * dacStaCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_DAC_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    if (NULL != dacStaCfg)
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            /* Validate enumeration for CLOCK_DAC_LP_DIV register */
            CY_ASSERT_L3(AUTANALOG_DAC_CLOCK_DIV(dacStaCfg->lpDivDac));

            /* Update CLOCK_DAC_LP_DIV register */
            AUTANALOG_INFRA_CLOCK_DAC_LP_DIV(INFRA_BASE, dacIdx) = dacStaCfg->lpDivDac;

            /* Update CTRL register */
            /* Validate enumerations for CTRL register */
            CY_ASSERT_L3(AUTANALOG_DAC_TOPO_CFG(dacStaCfg->topology));
            CY_ASSERT_L3(AUTANALOG_DAC_VREF_SEL(dacStaCfg->vrefSel));
            CY_ASSERT_L3(AUTANALOG_DAC_REF_BUF_POW(dacStaCfg->refBuffPwr));
            CY_ASSERT_L3(AUTANALOG_DAC_OUT_BUF_POW(dacStaCfg->outBuffPwr));
            CY_ASSERT_L3(AUTANALOG_DAC_VREF_MUX(dacStaCfg->vrefMux));

            /* Configure CTRL value */
            regVal =
                    _VAL2FLD(DAC_STA_CTRL_TOPO, dacStaCfg->topology) |
                    _VAL2FLD(DAC_STA_CTRL_VREF_SEL, dacStaCfg->vrefSel) |
                    _VAL2FLD(DAC_STA_CTRL_DEGLITCH_EN, dacStaCfg->deGlitch) |
                    _VAL2FLD(DAC_STA_CTRL_BOT_SEL, dacStaCfg->bottomSel) |
                    _VAL2FLD(DAC_STA_CTRL_DISABLED_MODE, dacStaCfg->disabledMode) |
                    _VAL2FLD(DAC_STA_CTRL_REFBUF_PWR_MODE, dacStaCfg->refBuffPwr) |
                    _VAL2FLD(DAC_STA_CTRL_OUTBUF_PWR_MODE, dacStaCfg->outBuffPwr) |
                    _VAL2FLD(DAC_STA_CTRL_FORMAT, dacStaCfg->sign) |
                    _VAL2FLD(DAC_STA_CTRL_REF_MUX_SEL, dacStaCfg->vrefMux);

            /* Update CTRL register */
            AUTANALOG_DAC_CTRL(baseAddr) = regVal;

            /* Update SAMPLE_TIME register */
            AUTANALOG_DAC_SAMPLE_TIME(baseAddr) = dacStaCfg->sampleTime;

            /* Update STEP_VAL[] registers */
            for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_DAC_STEP_VAL_NUM; cfgIdx++)
            {
                AUTANALOG_DAC_STEP_VAL(baseAddr, cfgIdx) = dacStaCfg->stepVal[cfgIdx];
            }

            /* Update DEGLITCH_TIME register */
            AUTANALOG_DAC_DEGLITCH_TIME(baseAddr) = dacStaCfg->deGlitchTime;

            /* Update CHAN_CFG[] registers */
            for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_DAC_CH_CFG_NUM; cfgIdx++)
            {
                if (NULL != dacStaCfg->chCfg[cfgIdx])
                {
                    /* Validate enumerations for CHAN_CFG register */
                    CY_ASSERT_L3(AUTANALOG_DAC_START_ADDR(dacStaCfg->chCfg[cfgIdx]->startAddr));
                    CY_ASSERT_L3(AUTANALOG_DAC_END_ADDR(dacStaCfg->chCfg[cfgIdx]->endAddr));
                    CY_ASSERT_L3(AUTANALOG_DAC_OPER_MODE(dacStaCfg->chCfg[cfgIdx]->operMode));
                    CY_ASSERT_L3(AUTANALOG_DAC_STEP_SEL(dacStaCfg->chCfg[cfgIdx]->stepSel));
                    CY_ASSERT_L3(AUTANALOG_DAC_STATUS_SEL(dacStaCfg->chCfg[cfgIdx]->statSel));

                    /* Configure CHAN_CFG[idx] value */
                    regVal =
                            _VAL2FLD(DAC_STA_CHAN_CFG_START_ADDR, ((uint32_t)dacStaCfg->chCfg[cfgIdx]->startAddr) * 4U) | /* in bytes */
                            _VAL2FLD(DAC_STA_CHAN_CFG_END_ADDR, ((uint32_t)dacStaCfg->chCfg[cfgIdx]->endAddr) * 4U)| /* in bytes */
                            _VAL2FLD(DAC_STA_CHAN_CFG_MODE, dacStaCfg->chCfg[cfgIdx]->operMode) |
                            _VAL2FLD(DAC_STA_CHAN_CFG_SAMPLE_AND_HOLD_EN, dacStaCfg->chCfg[cfgIdx]->sampleAndHold) |
                            _VAL2FLD(DAC_STA_CHAN_CFG_STEP_VAL_SEL, dacStaCfg->chCfg[cfgIdx]->stepSel) |
                            _VAL2FLD(DAC_STA_CHAN_CFG_STATUS_SEL, dacStaCfg->chCfg[cfgIdx]->statSel);

                    /* Update CHAN_CFG register[idx] */
                    AUTANALOG_DAC_CHAN_CFG(baseAddr, cfgIdx) = regVal;
                }
            }

            /* Update CHAN_STATUS_CFG[] registers */
            for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_DAC_CH_RANGE_NUM; cfgIdx++)
            {
                if (NULL != dacStaCfg->chLimitCfg[cfgIdx])
                {
                    /* Validate enumerations for CHAN_STATUS_CFG register */
                    CY_ASSERT_L3(AUTANALOG_DAC_CH_RANGE_COND(dacStaCfg->chLimitCfg[cfgIdx]->cond));

                    /* Configure CHAN_STATUS_CFG[idx] value */
                    regVal =
                            _VAL2FLD(DAC_STA_CHAN_STATUS_CFG_RANGE_COND, dacStaCfg->chLimitCfg[cfgIdx]->cond) |
                            _VAL2FLD(DAC_STA_CHAN_STATUS_CFG_RANGE_LOW, ((uint32_t)(dacStaCfg->chLimitCfg[cfgIdx]->low) &
                                DAC_STA_FW_DAC_VAL_VALUE_Msk)) |
                            _VAL2FLD(DAC_STA_CHAN_STATUS_CFG_RANGE_HIGH, ((uint32_t)(dacStaCfg->chLimitCfg[cfgIdx]->high) &
                                DAC_STA_FW_DAC_VAL_VALUE_Msk));

                    /* Update CHAN_STATUS_CFG register[idx] */
                    AUTANALOG_DAC_CHAN_STATUS_CFG(baseAddr, cfgIdx) = regVal;
                }
            }

            /*
             * Enables the required start-up/settling delay depending on Vref and used buffers for the enabled DAC
             */
            /* Internal Vref and used buffers */
            if ((CY_AUTANALOG_DAC_VREF_VDDA != dacStaCfg->vrefSel) &&
                ((CY_AUTANALOG_DAC_REF_BUF_PWR_OFF != dacStaCfg->refBuffPwr) ||
                 (CY_AUTANALOG_DAC_OUT_BUF_PWR_OFF != dacStaCfg->outBuffPwr)))
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |=
                    (0U == dacIdx) ? INFRA_PRIO_CFG_DAC0_READY_Msk : INFRA_PRIO_CFG_DAC1_READY_Msk;
            }
            /* External Vref and used buffers */
            else if ((CY_AUTANALOG_DAC_VREF_VDDA == dacStaCfg->vrefSel) &&
                     ((CY_AUTANALOG_DAC_REF_BUF_PWR_OFF != dacStaCfg->refBuffPwr) ||
                      (CY_AUTANALOG_DAC_OUT_BUF_PWR_OFF != dacStaCfg->outBuffPwr)))
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP1) |=
                    (0U == dacIdx) ? INFRA_PRIO_CFG_DAC0_READY_Msk : INFRA_PRIO_CFG_DAC1_READY_Msk;
            }
            /* External Vref without buffers */
            else if ((CY_AUTANALOG_DAC_VREF_VDDA == dacStaCfg->vrefSel) &&
                     (CY_AUTANALOG_DAC_REF_BUF_PWR_OFF == dacStaCfg->refBuffPwr) &&
                     (CY_AUTANALOG_DAC_OUT_BUF_PWR_OFF == dacStaCfg->outBuffPwr))
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP0) |=
                    (0U == dacIdx) ? INFRA_PRIO_CFG_DAC0_READY_Msk : INFRA_PRIO_CFG_DAC1_READY_Msk;
            }
            else
            {
                /* MISRA */
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_ReadWaveform(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, int32_t * waveform)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_DAC_BAD_PARAM;

    uint32_t baseAddr;
    uint16_t sampleIdx;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    if ((dataIdx + numSamples <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM) && (NULL != waveform))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (sampleIdx = 0U; sampleIdx < numSamples; sampleIdx++)
            {
                CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that type conversion from uint32_t to int32_t does not have any negative drawbacks');
                waveform[sampleIdx] = _FLD2VAL(DAC_SRAM_WAVEFORM, AUTANALOG_DAC_LUT(baseAddr, dataIdx++));
            }
        }
    }

    return result;
}

cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_GetDriveModeArray(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, cy_en_autanalog_dac_out_drive_mode_t * driveModeArray)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_DAC_BAD_PARAM;

    uint32_t baseAddr;
    uint16_t sampleIdx;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    if ((dataIdx + numSamples <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM) && (NULL != driveModeArray))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (sampleIdx = 0U; sampleIdx < numSamples; sampleIdx++)
            {
                CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Review shows that type conversion from uint32_t to enum does not have any negative drawbacks');
                driveModeArray[sampleIdx] = (cy_en_autanalog_dac_out_drive_mode_t)_FLD2VAL(DAC_SRAM_OUT_DM, AUTANALOG_DAC_LUT(baseAddr, dataIdx++));
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_WriteWaveform(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, const int32_t * waveform)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_DAC_BAD_PARAM;

    uint32_t baseAddr;
    uint16_t sampleIdx;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    if ((dataIdx + numSamples <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM) && (NULL != waveform))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (sampleIdx = 0U; sampleIdx < numSamples; sampleIdx++)
            {
                CY_REG32_CLR_SET(AUTANALOG_DAC_LUT(baseAddr, dataIdx), DAC_SRAM_WAVEFORM, (uint32_t)waveform[sampleIdx]);
                dataIdx++;
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_DAC_Data_SetDriveModeArray(uint8_t dacIdx, uint16_t dataIdx, uint16_t numSamples, const cy_en_autanalog_dac_out_drive_mode_t * driveModeArray)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_DAC_BAD_PARAM;

    uint32_t baseAddr;
    uint16_t sampleIdx;

    CY_ASSERT_L2(AUTANALOG_DAC_LUT_IDX(dataIdx));

    if ((dataIdx + numSamples <= CY_AUTANALOG_DAC_DATA_SAMPLES_NUM) && (NULL != driveModeArray))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (sampleIdx = 0U; sampleIdx < numSamples; sampleIdx++)
            {
                CY_ASSERT_L2(AUTANALOG_DAC_OUT_DM(driveModeArray[sampleIdx]));
                CY_REG32_CLR_SET(AUTANALOG_DAC_LUT(baseAddr, dataIdx), DAC_SRAM_OUT_DM, driveModeArray[sampleIdx]);
                dataIdx++;
            }
        }
    }

    return result;
}


void Cy_AutAnalog_DAC_Data_SetDriveModeAll(uint8_t dacIdx, const cy_en_autanalog_dac_out_drive_mode_t driveModeAll)
{
    CY_ASSERT_L2(AUTANALOG_DAC_OUT_DM(driveModeAll));

    uint32_t baseAddr;
    uint16_t sampleIdx;

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_DAC, dacIdx, &baseAddr))
    {
        for (sampleIdx = 0U; sampleIdx < CY_AUTANALOG_DAC_DATA_SAMPLES_NUM; sampleIdx++)
        {
            CY_REG32_CLR_SET(AUTANALOG_DAC_LUT(baseAddr, sampleIdx), DAC_SRAM_OUT_DM, driveModeAll);
        }
    }
}

#endif /* CY_IP_MXS22LPPASS_DAC */

/* [] END OF FILE */

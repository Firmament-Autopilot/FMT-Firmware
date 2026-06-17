/***************************************************************************//**
* \file cy_autanalog_sar.c
* \version 2.0
*
* \brief
* Provides an API definition for the SAR ADC in the Autonomous Analog driver.
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
#include "cy_autanalog_sar.h"

#ifdef CY_IP_MXS22LPPASS_SAR

/* Validation macros for HS/LP sequencers */
#define AUTANALOG_SAR_SEQ_NUM(value)                        ((value) <=  CY_AUTANALOG_SAR_SEQUENCER_NUM)
#define AUTANALOG_SAR_SEQ_MUX_MODE(value)                   ((value) <= 0x04UL)
#define AUTANALOG_SAR_SEQ_MUX_SEL(value)                    ((value) <= 0x0FUL)
#define AUTANALOG_SAR_SEQ_SAMPLE_TIME(value)                ((value) <= CY_AUTANALOG_SAR_SAMPLE_TIME3)
#define AUTANALOG_SAR_SEQ_AVG_CNT(value)                    ((value) <= CY_AUTANALOG_SAR_ACC_CNT256)
#define AUTANALOG_SAR_SEQ_CAL_REQ(value)                    ((value) <= CY_AUTANALOG_SAR_CAL_LINEARITY)
#define AUTANALOG_SAR_SEQ_NEXT_STATE(value)                 ((value) <= CY_AUTANALOG_SAR_NEXT_ACTION_GO_TO_NEXT)
/* Validation macros for static cfg */
#define AUTANALOG_SAR_STA_CFG_CH_DEFAULT_GAIN               (0x8000UL)
#define AUTANALOG_SAR_STA_CFG_CH_DEFAULT_OFFSET             (0x0UL)
#define AUTANALOG_SAR_STA_CFG_TR_HS_CH_DEFAULT_SAMPLE_TIME  (31UL)
#define AUTANALOG_SAR_STA_CFG_TR_LP_CH_DEFAULT_SAMPLE_TIME  (5UL)
#define AUTANALOG_SAR_STA_CFG_SAMPLE_TIME(value)            ((value) <= SAR_STA_TR_SAMPLE_TIME_HS_TR_SAMPLE_TIME_Msk)
#define AUTANALOG_SAR_STA_CFG_FIR_MASK(value)               ((value) <= SAR_STA_FIR_RESULT_MASK_FIR_RESULT_MASK_Msk)
#define AUTANALOG_SAR_STA_CFG_CH_GAIN(value)                ((uint16_t)(value) != 0U)
#define AUTANALOG_SAR_STA_CFG_CH_OFFSET(value)              (((int16_t)(value) >= -2048) && ((int16_t)(value) <= 2047))
/* Validation macros for CTRL register */
#define AUTANALOG_SAR_CTRL_VREF(value)                      ((value) <= CY_AUTANALOG_SAR_VREF_PRB_OUT1)
#define AUTANALOG_SAR_CTRL_BUFF_PWR(value)                  ((value) <= CY_AUTANALOG_SAR_BUF_PWR_ULTRA_HIGH_RAIL)
#define AUTANALOG_SAR_CTRL_AVG_MODE(value)                  ((value) <= CY_AUTANALOG_SAR_ACC_ACCUNDUMP)
#define AUTANALOG_SAR_CTRL_STARTUP_CAL(value)               ((value) <= CY_AUTANALOG_SAR_CAL_LINEARITY)
/* Validation macros for GPIO CH CFG registers */
#define AUTANALOG_SAR_GPIO_PIN(value)                       ((value) <= CY_AUTANALOG_SAR_PIN_GPIO7)
#define AUTANALOG_SAR_CH_COEF(value)                        ((value) <= CY_AUTANALOG_SAR_CH_COEFF7)
/* Validation macros for MUX CH CFG registers */
#define AUTANALOG_SAR_MUX_PIN(value)                       (((value) <= CY_AUTANALOG_SAR_PIN_MUX_GPIO7) || \
                                                            ((value) == CY_AUTANALOG_SAR_PIN_MUX_VSSA))
/* Validation macros for STATUS registers */
#define AUTANALOG_SAR_STATUS_SEL(value)                     ((value) <= CY_AUTANALOG_SAR_LIMIT_STATUS_STC3)
#define AUTANALOG_SAR_STATUS_COND(value)                    ((value) <= CY_AUTANALOG_SAR_COND_OUTSIDE)
/* Validation macros for FIR registers */
#define AUTANALOG_SAR_FIR_CHANNEL_SEL(value)                ((value) <= CY_AUTANALOG_SAR_FIR_CH_MUX15)
#define AUTANALOG_SAR_FIR_TAP_SEL(value)                    ((value) < CY_AUTANALOG_SAR_FIR_TAP_NUM)
#define AUTANALOG_SAR_FIR_SHIFT_SEL(value)                  ((value) <= 0x0FUL)
/* Validation macros for FIFO registers */
#define AUTANALOG_MMIO_FIFO_CFG(value)                      ((value) <= CY_AUTANALOG_FIFO_SPLIT8)
/* Validation macros for FIFO LEVEL register */
#define AUTANALOG_MMIO_FIFO_SEL(value)                      ((value) <= CY_AUTANALOG_FIFO_SELECT7)
#define AUTANALOG_MMIO_FIFO_LEVEL(value)                    ((value) <= LPPASS_MMIO_STA_LEVEL_LEVEL_Msk)
/* Position of the sign in FIFO data with channel ID */
#define AUTANALOG_MMIO_FIFO_SIGN_POS                        (23U)
#define AUTANALOG_MMIO_FIFO_SIGN_MASK                       (0x1UL << AUTANALOG_MMIO_FIFO_SIGN_POS)
/* Position of the channel ID in FIFO data for GPIO channels */
#define AUTANALOG_MMIO_FIFO_CH_ID_POS_GPIO                  (24U)
#define AUTANALOG_MMIO_FIFO_CH_ID_MASK_GPIO                 (0x7UL << AUTANALOG_MMIO_FIFO_CH_ID_POS_GPIO)
/* Position of the channel ID in FIFO data for MUX channels */
#define AUTANALOG_MMIO_FIFO_CH_ID_POS_MUX                   (28U)
#define AUTANALOG_MMIO_FIFO_CH_ID_MASK_MUX                  (0xFUL << AUTANALOG_MMIO_FIFO_CH_ID_POS_MUX)
/* SAR ADC conversion macros */
#define AUTANALOG_SAR_SEQ_IDX(value)                        ((value) <  CY_AUTANALOG_SAR_SEQUENCER_NUM)
#define AUTANALOG_SAR_VREF_MAX(value)                       ((value) <= 1800) /* Vdda is 1.8V */
#define AUTANALOG_SAR_10V_COUNTS                            (10UL)
#define AUTANALOG_SAR_10mV_COUNTS                           (10000UL)
#define AUTANALOG_SAR_10uV_COUNTS                           (10000000UL)
#define AUTANALOG_SAR_MAX_BITS12                            (0x00001000L)
#define AUTANALOG_SAR_MAX_BITS16                            (0x00010000L)
#define AUTANALOG_SAR_OFFSET_BITS12                         (AUTANALOG_SAR_MAX_BITS12 / 2L)
#define AUTANALOG_SAR_OFFSET_BITS16                         (AUTANALOG_SAR_MAX_BITS16 / 2L)
/* SAR ADC die temperature macros */
#define AUTANALOG_SAR_TEMP_DIV                              (0x10000L)  /* 1 in Q16.16 format */
#define AUTANALOG_SAR_TEMP_HALF                             (0x8000L)   /* 0.5 in Q16.16 format */


/* Local variables for die temperature trimmings */
static uint32_t dieTempMultiplierHS = 0x00016000UL;
static uint32_t dieTempOffsetHS     = 0xFEDC6000UL;
static uint32_t dieTempMultiplierLP = 0x00016000UL;
static uint32_t dieTempOffsetLP     = 0xFEDC6000UL;


/* Forward declarations */
#if !defined (CY_AUTANALOG_FIR_DISABLE)
static cy_en_autanalog_status_t SAR_LoadFIR(uint8_t sarIdx, uint8_t cfgNum, const cy_stc_autanalog_sar_fir_cfg_t * firCfg);
#endif
static void SAR_LoadGpioChan(uint32_t baseAddr, uint8_t cfgNum, cy_stc_autanalog_sar_hs_chan_t * const hsGpioChan[]);
static void SAR_LoadMuxChan(uint32_t baseAddr, uint8_t cfgNum, cy_stc_autanalog_sar_mux_chan_t * const intMuxChan[]);
static void SAR_LoadRangeCond(uint32_t baseAddr, uint8_t cfgNum, cy_stc_autanalog_sar_limit_t * const limitCond[]);
static int32_t SAR_CheckChanOffset(uint32_t baseAddr, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                   uint8_t sarChannel, bool sarMode16);
static int32_t SAR_GetAverageVoltCounts(uint32_t baseAddr, bool sarLP, uint8_t sarSequencer,
               cy_en_autanalog_sar_input_t sarInput, uint8_t sarChannel, int32_t sarCounts, bool * sarMode16);
static int32_t SAR_GetAverageTempCounts(bool avgShiftMode16, uint8_t avgCnt, int32_t sarCounts);
static int32_t SAR_CountsToDegreeC(bool sarLP, int32_t sarCounts);


cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadConfig(uint8_t sarIdx, const cy_stc_autanalog_sar_t * sarCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    if (NULL != sarCfg)
    {
        result = Cy_AutAnalog_SAR_LoadStaticConfig(sarIdx, sarCfg->sarStaCfg);

        /* The High Speed configuration might be optional */
        if ((CY_AUTANALOG_SUCCESS == result) && (0U != sarCfg->hsSeqTabNum) && (NULL != sarCfg->hsSeqTabArr))
        {
            result = Cy_AutAnalog_SAR_LoadHSseqTable(sarIdx, sarCfg->hsSeqTabNum, sarCfg->hsSeqTabArr);
        }

        /* The Low Power configuration might be optional */
        if ((CY_AUTANALOG_SUCCESS == result) && (0U != sarCfg->lpSeqTabNum) && (NULL != sarCfg->lpSeqTabArr))
        {
            result = Cy_AutAnalog_SAR_LoadLPseqTable(sarIdx, sarCfg->lpSeqTabNum, sarCfg->lpSeqTabArr);
        }

        /*
         * Enables the required start-up/settling delay for the ADC
         */
        /* ADC is configured for operation in both modes HS and LP */
        if ((NULL != sarCfg->sarStaCfg) && (CY_AUTANALOG_SUCCESS == result) &&
            (NULL != sarCfg->sarStaCfg->hsStaCfg) && (0U != sarCfg->hsSeqTabNum) &&
            (NULL != sarCfg->sarStaCfg->lpStaCfg) && (0U != sarCfg->lpSeqTabNum))
        {
            /* Internal Vref used for at least one ADC core */
            if (((CY_AUTANALOG_SAR_VREF_VDDA != sarCfg->sarStaCfg->hsStaCfg->hsVref) &&
                 (CY_AUTANALOG_SAR_VREF_VDDA_BY_2 != sarCfg->sarStaCfg->hsStaCfg->hsVref) &&
                 (CY_AUTANALOG_SAR_VREF_EXT != sarCfg->sarStaCfg->hsStaCfg->hsVref)) ||
                 ((CY_AUTANALOG_SAR_VREF_VDDA != sarCfg->sarStaCfg->lpStaCfg->lpVref) &&
                  (CY_AUTANALOG_SAR_VREF_VDDA_BY_2 != sarCfg->sarStaCfg->lpStaCfg->lpVref) &&
                  (CY_AUTANALOG_SAR_VREF_EXT != sarCfg->sarStaCfg->lpStaCfg->lpVref)))
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_SAR_READY_Msk;
            }
            else
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP1) |= INFRA_PRIO_CFG_SAR_READY_Msk;
            }
        }
        /* ADC is configured for operation in HS mode */
        else if ((NULL != sarCfg->sarStaCfg) && (CY_AUTANALOG_SUCCESS == result) &&
                 (NULL != sarCfg->sarStaCfg->hsStaCfg) && (0U != sarCfg->hsSeqTabNum))
        {
            /* Internal Vref */
            if ((CY_AUTANALOG_SAR_VREF_VDDA != sarCfg->sarStaCfg->hsStaCfg->hsVref) &&
                (CY_AUTANALOG_SAR_VREF_VDDA_BY_2 != sarCfg->sarStaCfg->hsStaCfg->hsVref) &&
                (CY_AUTANALOG_SAR_VREF_EXT != sarCfg->sarStaCfg->hsStaCfg->hsVref))
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_SAR_READY_Msk;
            }
            /* External Vref */
            else
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP1) |= INFRA_PRIO_CFG_SAR_READY_Msk;
            }
        }
        /* ADC is configured for operation in LP mode */
        else if ((NULL != sarCfg->sarStaCfg) && (CY_AUTANALOG_SUCCESS == result) &&
                 (NULL != sarCfg->sarStaCfg->lpStaCfg) && (0U != sarCfg->lpSeqTabNum))
        {
            /* Internal Vref */
            if ((CY_AUTANALOG_SAR_VREF_VDDA != sarCfg->sarStaCfg->lpStaCfg->lpVref) &&
                (CY_AUTANALOG_SAR_VREF_VDDA_BY_2 != sarCfg->sarStaCfg->lpStaCfg->lpVref) &&
                (CY_AUTANALOG_SAR_VREF_EXT != sarCfg->sarStaCfg->lpStaCfg->lpVref))
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP2) |= INFRA_PRIO_CFG_SAR_READY_Msk;
            }
            /* External Vref */
            else
            {
                AUTANALOG_INFRA_PRIO_CFG(INFRA_BASE, CY_AUTANALOG_PRIORITY_GROUP1) |= INFRA_PRIO_CFG_SAR_READY_Msk;
            }
        }
        else
        {
            /* MISRA */
        }

#if !defined (CY_AUTANALOG_FIR_DISABLE)
        /* FIR filter configuration */
        if ((CY_AUTANALOG_SUCCESS == result) && (sarCfg->firNum > 0U))
        {
            result = SAR_LoadFIR(sarIdx, sarCfg->firNum, sarCfg->firCfg);
        }
#endif

#if !defined (CY_AUTANALOG_FIFO_DISABLE)
        /* Currently, single instance of FIFO is tightly linked with SAR */
        if ((CY_AUTANALOG_SUCCESS == result) && (NULL != sarCfg->fifoCfg))
        {
            result = Cy_AutAnalog_FIFO_LoadConfig(0U, sarCfg->fifoCfg);
        }
#endif
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadStaticConfig(uint8_t sarIdx, const cy_stc_autanalog_sar_sta_t * sarStaCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    if (NULL != sarStaCfg)
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            uint16_t hsSampleTime[CY_AUTANALOG_SAR_SAMPLE_TIME_NUM] = {0U};
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.9','Review shows that usage macro NULL does not have any negative drawbacks');
            cy_stc_autanalog_sar_hs_chan_t * hsGpioChan[PASS_SAR_SAR_GPIO_CHANNELS] = {NULL};

            cy_en_autanalog_sar_vref_t hsVref = (NULL != sarStaCfg->hsStaCfg) ? sarStaCfg->hsStaCfg->hsVref : CY_AUTANALOG_SAR_VREF_VDDA;
            uint8_t hsGpioResultMask = (NULL != sarStaCfg->hsStaCfg) ? sarStaCfg->hsStaCfg->hsGpioResultMask : 0U;
            if (NULL != sarStaCfg->hsStaCfg)
            {
                (void)memcpy(hsSampleTime, sarStaCfg->hsStaCfg->hsSampleTime, sizeof(hsSampleTime));
                (void)memcpy(hsGpioChan, sarStaCfg->hsStaCfg->hsGpioChan, sizeof(hsGpioChan));
            }

            bool lpDiffEn = (NULL != sarStaCfg->lpStaCfg) ? sarStaCfg->lpStaCfg->lpDiffEn : false;
            cy_en_autanalog_sar_vref_t lpVref = (NULL != sarStaCfg->lpStaCfg) ? sarStaCfg->lpStaCfg->lpVref : CY_AUTANALOG_SAR_VREF_VDDA;
            uint16_t lpSampleTime[CY_AUTANALOG_SAR_SAMPLE_TIME_NUM] = {0U};
            if (NULL != sarStaCfg->lpStaCfg)
            {
                (void)memcpy(lpSampleTime, sarStaCfg->lpStaCfg->lpSampleTime, sizeof(lpSampleTime));
            }

            CY_ASSERT_L3(AUTANALOG_SAR_CTRL_VREF(hsVref));
            CY_ASSERT_L3(AUTANALOG_SAR_CTRL_VREF(lpVref));
            CY_ASSERT_L3(AUTANALOG_SAR_CTRL_BUFF_PWR(sarStaCfg->posBufPwr));
            CY_ASSERT_L3(AUTANALOG_SAR_CTRL_BUFF_PWR(sarStaCfg->negBufPwr));
            CY_ASSERT_L3(AUTANALOG_SAR_CTRL_AVG_MODE(sarStaCfg->accMode));
            CY_ASSERT_L3(AUTANALOG_SAR_CTRL_STARTUP_CAL(sarStaCfg->startupCal));

            regVal = _VAL2FLD(SAR_STA_CTRL_HS_VREF_SEL, hsVref);
            regVal |= _VAL2FLD(SAR_STA_CTRL_LP_VREF_SEL, lpVref);
            regVal |= _VAL2FLD(SAR_STA_CTRL_LP_DIFFERENTIAL_EN, lpDiffEn);
            regVal |= _VAL2FLD(SAR_STA_CTRL_BUF0_PWR_MODE, sarStaCfg->posBufPwr);
            regVal |= _VAL2FLD(SAR_STA_CTRL_BUF1_PWR_MODE, sarStaCfg->negBufPwr);
            regVal |= _VAL2FLD(SAR_STA_CTRL_AVG_MODE, sarStaCfg->accMode);
            regVal |= _VAL2FLD(SAR_STA_CTRL_STARTUP_CAL_EN, sarStaCfg->startupCal);
            regVal |= _VAL2FLD(SAR_STA_CTRL_CHAN_ID_EN, sarStaCfg->chanID);
            regVal |= _VAL2FLD(SAR_STA_CTRL_SHIFT_MODE, sarStaCfg->shiftMode);
            AUTANALOG_SAR_CTRL(baseAddr) = regVal;

            CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_SAMPLE_TIME(AUTANALOG_SAR_STA_CFG_TR_HS_CH_DEFAULT_SAMPLE_TIME));
            CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_SAMPLE_TIME(AUTANALOG_SAR_STA_CFG_TR_LP_CH_DEFAULT_SAMPLE_TIME));
            CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_FIR_MASK(sarStaCfg->firResultMask));

            SAR_LoadGpioChan(baseAddr, PASS_SAR_SAR_GPIO_CHANNELS, hsGpioChan);
            SAR_LoadMuxChan(baseAddr, PASS_SAR_SAR_MUX_CHANNELS, sarStaCfg->intMuxChan);
            SAR_LoadRangeCond(baseAddr, (uint8_t)CY_AUTANALOG_SAR_LIMIT_CFG_NUM, sarStaCfg->limitCond);

            /* Set default values for HS/LP trigger sample time */
            regVal = _VAL2FLD(SAR_STA_TR_SAMPLE_TIME_HS_TR_SAMPLE_TIME, AUTANALOG_SAR_STA_CFG_TR_HS_CH_DEFAULT_SAMPLE_TIME);
            regVal |= _VAL2FLD(SAR_STA_TR_SAMPLE_TIME_LP_TR_SAMPLE_TIME, AUTANALOG_SAR_STA_CFG_TR_LP_CH_DEFAULT_SAMPLE_TIME);
            AUTANALOG_SAR_TR_SAMPLE_TIME(baseAddr) = regVal;

            for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_SAR_SAMPLE_TIME_NUM; cfgIdx++)
            {
                CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_SAMPLE_TIME(hsSampleTime[cfgIdx]));
                CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_SAMPLE_TIME(lpSampleTime[cfgIdx]));

                regVal = _VAL2FLD(SAR_STA_SAMPLE_TIME_HS_SAMPLE_TIME, hsSampleTime[cfgIdx]);
                regVal |= _VAL2FLD(SAR_STA_SAMPLE_TIME_LP_SAMPLE_TIME, lpSampleTime[cfgIdx]);
                AUTANALOG_SAR_SAMPLE_TIME(baseAddr, cfgIdx) = regVal;
            }

            regVal = _VAL2FLD(SAR_STA_CHAN_RESULT_MASK_GPIO_CHAN_RESULT_MASK, hsGpioResultMask);
            regVal |= _VAL2FLD(SAR_STA_CHAN_RESULT_MASK_MUX_CHAN_RESULT_MASK, sarStaCfg->muxResultMask);
            AUTANALOG_SAR_CHAN_RESULT_MASK(baseAddr) = regVal;

            regVal = _VAL2FLD(SAR_STA_FIR_RESULT_MASK_FIR_RESULT_MASK, sarStaCfg->firResultMask);
            AUTANALOG_SAR_FIR_RESULT_MASK(baseAddr) = regVal;

            for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_SAR_CH_CORR_COEFF_NUM; cfgIdx++)
            {
                CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_CH_GAIN(AUTANALOG_SAR_STA_CFG_CH_DEFAULT_GAIN));
                CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_CH_OFFSET(AUTANALOG_SAR_STA_CFG_CH_DEFAULT_OFFSET));

                /* Set default values for gain and offset */
                regVal = _VAL2FLD(SAR_STA_CHAN_COEFF_GAIN, AUTANALOG_SAR_STA_CFG_CH_DEFAULT_GAIN);
                regVal |= _VAL2FLD(SAR_STA_CHAN_COEFF_OFFSET, ((uint16_t)AUTANALOG_SAR_STA_CFG_CH_DEFAULT_OFFSET) & SAR_STA_CHAN_COEFF_OFFSET_Msk);
                AUTANALOG_SAR_CHAN_COEFF(baseAddr, cfgIdx) = regVal;
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadHSseqTable(uint8_t sarIdx, uint8_t seqTabNum, const cy_stc_autanalog_sar_seq_tab_hs_t * seqTabArr)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    CY_ASSERT_L2(AUTANALOG_SAR_SEQ_NUM(seqTabNum));

    result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr);

    if ((CY_AUTANALOG_SUCCESS == result) && (seqTabNum > 0U) && (NULL != seqTabArr))
    {
        for (cfgIdx = 0U; cfgIdx < seqTabNum; cfgIdx++)
        {
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_MUX_MODE(seqTabArr[cfgIdx].muxMode));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_MUX_SEL(seqTabArr[cfgIdx].mux0Sel));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_MUX_SEL(seqTabArr[cfgIdx].mux1Sel));

            regVal =
                    _VAL2FLD(SAR_SEQ_HS_DATA_HS_GPIO_CHAN_EN, seqTabArr[cfgIdx].chanEn) |
                    _VAL2FLD(SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL, seqTabArr[cfgIdx].muxMode) |
                    _VAL2FLD(SAR_SEQ_HS_DATA_MUX0_CHAN_SEL, seqTabArr[cfgIdx].mux0Sel) |
                    _VAL2FLD(SAR_SEQ_HS_DATA_MUX1_CHAN_SEL, seqTabArr[cfgIdx].mux1Sel);

            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_SAMPLE_TIME(seqTabArr[cfgIdx].sampleTime));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_AVG_CNT(seqTabArr[cfgIdx].accCount));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_CAL_REQ(seqTabArr[cfgIdx].calReq));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_NEXT_STATE(seqTabArr[cfgIdx].nextAction));

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_SAMPLE_TIME_EN, seqTabArr[cfgIdx].sampleTimeEn);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_TR_SAMPLE_TIME_EN, 0U); /* Set default value */

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_SAMPLE_TIME_SEL, seqTabArr[cfgIdx].sampleTime);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_AVG_EN, seqTabArr[cfgIdx].accEn);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_AVG_CNT, seqTabArr[cfgIdx].accCount);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_CALIBRATE, seqTabArr[cfgIdx].calReq);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_NEXT_ACTION, seqTabArr[cfgIdx].nextAction);

            AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, cfgIdx) = regVal;
        }
    }
    else
    {
        result = CY_AUTANALOG_SAR_BAD_PARAM;
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadLPseqTable(uint8_t sarIdx, uint8_t seqTabNum, const cy_stc_autanalog_sar_seq_tab_lp_t * seqTabArr)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    CY_ASSERT_L2(AUTANALOG_SAR_SEQ_NUM(seqTabNum));

    result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr);

    if ((CY_AUTANALOG_SUCCESS == result) && (seqTabNum > 0U) && (NULL != seqTabArr))
    {
        for (cfgIdx = 0U; cfgIdx < seqTabNum; cfgIdx++)
        {
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_MUX_SEL(seqTabArr[cfgIdx].mux0Sel));

            regVal =
                    _VAL2FLD(SAR_SEQ_LP_DATA_LP_CHAN_EN, seqTabArr[cfgIdx].chanEn) |
                    _VAL2FLD(SAR_SEQ_LP_DATA_CHAN_SEL, seqTabArr[cfgIdx].mux0Sel);

            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_SAMPLE_TIME(seqTabArr[cfgIdx].sampleTime));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_AVG_CNT(seqTabArr[cfgIdx].accCount));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_CAL_REQ(seqTabArr[cfgIdx].calReq));
            CY_ASSERT_L3(AUTANALOG_SAR_SEQ_NEXT_STATE(seqTabArr[cfgIdx].nextAction));

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_SAMPLE_TIME_EN, seqTabArr[cfgIdx].sampleTimeEn);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_TR_SAMPLE_TIME_EN, 0U); /* Set default value */

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_SAMPLE_TIME_SEL, seqTabArr[cfgIdx].sampleTime);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_AVG_EN, seqTabArr[cfgIdx].accEn);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_AVG_CNT, seqTabArr[cfgIdx].accCount);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_CALIBRATE, seqTabArr[cfgIdx].calReq);

            regVal |=
                    _VAL2FLD(SAR_SEQ_HS_DATA_NEXT_ACTION, seqTabArr[cfgIdx].nextAction);

            AUTANALOG_SAR_SEQ_LP_DATA(baseAddr, cfgIdx) = regVal;
        }
    }
    else
    {
        result = CY_AUTANALOG_SAR_BAD_PARAM;
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadFIRconfig(uint8_t sarIdx, uint8_t firIdx, const cy_stc_autanalog_sar_fir_cfg_t * firCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t tapIdx;

    CY_ASSERT_L2(AUTANALOG_SAR_FIR_IDX(firIdx));

    if ((NULL != firCfg) && (NULL != firCfg->coeff))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            CY_ASSERT_L3(AUTANALOG_SAR_FIR_CHANNEL_SEL(firCfg->chanSel));
            CY_ASSERT_L3(AUTANALOG_SAR_FIR_TAP_SEL(firCfg->tapSel));
            CY_ASSERT_L3(AUTANALOG_SAR_FIR_SHIFT_SEL(firCfg->shiftSel));
            CY_ASSERT_L3(AUTANALOG_SAR_STATUS_SEL(firCfg->firLimit));
            CY_ASSERT_L3(AUTANALOG_MMIO_FIFO_SEL(firCfg->fifoSel));

            regVal = _VAL2FLD(SAR_STA_FIR_CFG_CHANNEL_SEL, firCfg->chanSel);
            regVal |= _VAL2FLD(SAR_STA_FIR_CFG_TAP_SEL, firCfg->tapSel);
            regVal |= _VAL2FLD(SAR_STA_FIR_CFG_SHIFT_SEL, firCfg->shiftSel);
            regVal |= _VAL2FLD(SAR_STA_FIR_CFG_WAIT_TAP_INIT, firCfg->waitTapInit);
            regVal |= _VAL2FLD(SAR_STA_FIR_CFG_STATUS_SEL, firCfg->firLimit);
            regVal |= _VAL2FLD(SAR_STA_FIR_CFG_FIFO_SEL, firCfg->fifoSel);

            AUTANALOG_SAR_FIR_CFG(baseAddr, firIdx) = regVal;

            for (tapIdx = 0U; tapIdx <= firCfg->tapSel; tapIdx++)
            {
                if (0U == firIdx)
                {
                    AUTANALOG_SAR_FIR0_COEF(baseAddr, tapIdx) = (uint32_t)firCfg->coeff[tapIdx];
                }
                else
                {
                    AUTANALOG_SAR_FIR1_COEF(baseAddr, tapIdx) = (uint32_t)firCfg->coeff[tapIdx];
                }
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_SAR_FIRloadCoeff(uint8_t sarIdx, uint8_t firIdx, uint8_t firCoeffNum,
                                                        const int16_t * firCoeffArr)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    uint32_t baseAddr;
    uint8_t tapIdx;

    CY_ASSERT_L2(AUTANALOG_SAR_FIR_IDX(firIdx));
    CY_ASSERT_L3(AUTANALOG_SAR_FIR_TAP_SEL(firCoeffNum - 1U));

    if (NULL != firCoeffArr)
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (tapIdx = 0U; tapIdx < firCoeffNum; tapIdx++)
            {
                if (0U == firIdx)
                {
                    AUTANALOG_SAR_FIR0_COEF(baseAddr, tapIdx) = (uint32_t)firCoeffArr[tapIdx];
                }
                else
                {
                    AUTANALOG_SAR_FIR1_COEF(baseAddr, tapIdx) = (uint32_t)firCoeffArr[tapIdx];
                }
            }
        }
    }

    return result;
}


cy_en_autanalog_status_t Cy_AutAnalog_SAR_LoadOffsetGainCorr(uint8_t sarIdx, uint16_t chanGain[], int16_t chanOffset[])
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SAR_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    if ((NULL != chanGain) && (NULL != chanOffset))
    {
        result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr);

        if (CY_AUTANALOG_SUCCESS == result)
        {
            for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_SAR_CH_CORR_COEFF_NUM; cfgIdx++)
            {
                CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_CH_GAIN(chanGain[cfgIdx]));
                CY_ASSERT_L3(AUTANALOG_SAR_STA_CFG_CH_OFFSET(chanOffset[cfgIdx]));

                regVal = _VAL2FLD(SAR_STA_CHAN_COEFF_GAIN, chanGain[cfgIdx]);
                regVal |= _VAL2FLD(SAR_STA_CHAN_COEFF_OFFSET, ((uint16_t)chanOffset[cfgIdx]) & SAR_STA_CHAN_COEFF_OFFSET_Msk);
                AUTANALOG_SAR_CHAN_COEFF(baseAddr, cfgIdx) = regVal;
            }
        }
    }

    return result;
}


float32_t Cy_AutAnalog_SAR_CountsTo_Volts(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                       uint8_t sarChannel, uint32_t VrefmV, int32_t sarCounts)
{
    uint32_t  baseAddr;
    uint32_t  sarGain;
    int32_t   sarOffset;
    uint32_t  diffSARdiv = 2U;
    bool     hsDiffmode = false;
    bool      sarMode16 = false;
    float32_t Volts     = 0.0F;

    CY_ASSERT_L2(AUTANALOG_SAR_SEQ_IDX(sarSequencer));
    CY_ASSERT_L2(AUTANALOG_SAR_INPUT(sarInput));
    CY_ASSERT_L2(AUTANALOG_SAR_CHANNEL(sarInput, sarChannel));
    CY_ASSERT_L2(AUTANALOG_SAR_VREF_MAX(VrefmV));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        /* Check ADC resolution and calculate average if any */
        sarCounts = SAR_GetAverageVoltCounts(baseAddr, sarLP, sarSequencer, sarInput, sarChannel, sarCounts, &sarMode16);

        /* Set gain divider depends on ADC architecture and pseudo-differential mode */
        if (sarLP == false)
        {
            /* Get DIFFERENTIAL_EN parameter for GPIO/MUX channel */
            hsDiffmode = (CY_AUTANALOG_SAR_INPUT_GPIO == sarInput) ?
                         _FLD2BOOL(SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN, AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, sarChannel)) :
                         (CY_AUTANALOG_SAR_CHAN_CFG_MUX0_PSEUDO_DIFF == _FLD2VAL(SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)));

            if (!hsDiffmode)
            {
                diffSARdiv = 1U;
            }
        }

        /* Calculate gain for SAR ADC channel */
        sarGain = sarMode16 ? (uint32_t)AUTANALOG_SAR_MAX_BITS16 : (uint32_t)AUTANALOG_SAR_MAX_BITS12;
        sarGain = CY_SYSLIB_DIV_ROUND(sarGain * (uint32_t) AUTANALOG_SAR_10mV_COUNTS / diffSARdiv, (uint32_t) VrefmV);

        /* Calculate offset for SAR ADC channel */
        sarOffset = SAR_CheckChanOffset(baseAddr, sarLP, sarSequencer, sarInput, sarChannel, sarMode16);

        /* SAR ADC result in V */
        Volts = (((float32_t) sarCounts + (float32_t) sarOffset) * (float32_t) AUTANALOG_SAR_10V_COUNTS) / (float32_t) sarGain;
    }

    return Volts;
}


int16_t Cy_AutAnalog_SAR_CountsTo_mVolts(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                      uint8_t sarChannel, uint32_t VrefmV, int32_t sarCounts)
{
    uint32_t baseAddr;
    uint32_t sarGain;
    int32_t  sarOffset;
    uint32_t diffSARdiv = 2U;
    bool     hsDiffmode = false;
    bool     sarMode16 = false;
    int32_t  mVolts    = 0;

    CY_ASSERT_L2(AUTANALOG_SAR_SEQ_IDX(sarSequencer));
    CY_ASSERT_L2(AUTANALOG_SAR_INPUT(sarInput));
    CY_ASSERT_L2(AUTANALOG_SAR_CHANNEL(sarInput, sarChannel));
    CY_ASSERT_L2(AUTANALOG_SAR_VREF_MAX(VrefmV));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        /* Check ADC resolution and calculate average if any */
        sarCounts = SAR_GetAverageVoltCounts(baseAddr, sarLP, sarSequencer, sarInput, sarChannel, sarCounts, &sarMode16);

        /* Set gain divider depends on ADC architecture and pseudo-differential mode */
        if (sarLP == false)
        {
            /* Get DIFFERENTIAL_EN parameter for GPIO/MUX channel */
            hsDiffmode = (CY_AUTANALOG_SAR_INPUT_GPIO == sarInput) ?
                         _FLD2BOOL(SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN, AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, sarChannel)) :
                         (CY_AUTANALOG_SAR_CHAN_CFG_MUX0_PSEUDO_DIFF == _FLD2VAL(SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)));

            if (!hsDiffmode)
            {
                diffSARdiv = 1U;
            }
        }

        /* Calculate gain for SAR ADC channel */
        sarGain = sarMode16 ? (uint32_t)AUTANALOG_SAR_MAX_BITS16 : (uint32_t)AUTANALOG_SAR_MAX_BITS12;
        sarGain = CY_SYSLIB_DIV_ROUND(sarGain * (uint32_t) AUTANALOG_SAR_10mV_COUNTS / diffSARdiv, (uint32_t) VrefmV);

        /* Calculate offset for SAR ADC channel */
        sarOffset = SAR_CheckChanOffset(baseAddr, sarLP, sarSequencer, sarInput, sarChannel, sarMode16);

        /* SAR ADC result in mV */
        sarCounts += (int32_t) sarOffset;
        mVolts = sarCounts * (int32_t) AUTANALOG_SAR_10mV_COUNTS;
        if (sarCounts > 0)
        {
            mVolts += (int32_t) sarGain / 2;
        }
        else
        {
            mVolts -= (int32_t) sarGain / 2;
        }
        mVolts /= (int32_t) sarGain;
    }

    return (int16_t) mVolts;
}


int32_t Cy_AutAnalog_SAR_CountsTo_uVolts(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                      uint8_t sarChannel, uint32_t VrefmV, int32_t sarCounts)
{
    uint32_t baseAddr;
    uint32_t sarGain;
    int32_t  sarOffset;
    uint32_t diffSARdiv = 2U;
    bool     hsDiffmode = false;
    bool     sarMode16 = false;
    int64_t  uVolts    = 0;

    CY_ASSERT_L2(AUTANALOG_SAR_SEQ_IDX(sarSequencer));
    CY_ASSERT_L2(AUTANALOG_SAR_INPUT(sarInput));
    CY_ASSERT_L2(AUTANALOG_SAR_CHANNEL(sarInput, sarChannel));
    CY_ASSERT_L2(AUTANALOG_SAR_VREF_MAX(VrefmV));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        /* Check ADC resolution and calculate average if any */
        sarCounts = SAR_GetAverageVoltCounts(baseAddr, sarLP, sarSequencer, sarInput, sarChannel, sarCounts, &sarMode16);

        /* Set gain divider depends on ADC architecture and pseudo-differential mode */
        if (sarLP == false)
        {
            /* Get DIFFERENTIAL_EN parameter for GPIO/MUX channel */
            hsDiffmode = (CY_AUTANALOG_SAR_INPUT_GPIO == sarInput) ?
                         _FLD2BOOL(SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN, AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, sarChannel)) :
                         (CY_AUTANALOG_SAR_CHAN_CFG_MUX0_PSEUDO_DIFF == _FLD2VAL(SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)));

            if (!hsDiffmode)
            {
                diffSARdiv = 1U;
            }
        }

        /* Calculate gain for SAR ADC channel */
        sarGain = sarMode16 ? (uint32_t)AUTANALOG_SAR_MAX_BITS16 : (uint32_t)AUTANALOG_SAR_MAX_BITS12;
        sarGain = CY_SYSLIB_DIV_ROUND(sarGain * (uint32_t) AUTANALOG_SAR_10mV_COUNTS / diffSARdiv, (uint32_t) VrefmV);

        /* Calculate offset for SAR ADC channel */
        sarOffset = SAR_CheckChanOffset(baseAddr, sarLP, sarSequencer, sarInput, sarChannel, sarMode16);

        /* SAR ADC result in uV */
        uVolts = (((int64_t) sarCounts + (int64_t) sarOffset) * (int64_t) AUTANALOG_SAR_10uV_COUNTS) / (int64_t) sarGain;
    }

    return (int32_t) uVolts;
}


int16_t Cy_AutAnalog_SAR_CountsTo_degreeC(uint8_t sarIdx, bool sarLP, uint8_t sarSequencer, uint8_t sarChannel,
                                          int32_t sarCounts)
{
    uint32_t                    baseAddr;
    bool                        accEn;
    cy_en_autanalog_sar_acc_mode_t accMode;
    bool                        accShift;
    bool                        avgShiftMode16;
    uint8_t                     avgCnt;

    int32_t                     temp = 0;

    CY_ASSERT_L2(AUTANALOG_SAR_SEQ_IDX(sarSequencer));
    CY_ASSERT_L2(AUTANALOG_SAR_CHANNEL(CY_AUTANALOG_SAR_INPUT_MUX, sarChannel));

    if (CY_AUTANALOG_SUCCESS == Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_SAR, sarIdx, &baseAddr))
    {
        /* Get AVG_EN parameter for SAR ADC sequencer */
        accEn = (sarLP == false) ?
                 _FLD2BOOL(SAR_SEQ_HS_DATA_AVG_EN, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)):
                 _FLD2BOOL(SAR_SEQ_LP_DATA_AVG_EN, AUTANALOG_SAR_SEQ_LP_DATA(baseAddr, sarSequencer));

        /* Get AVG_MODE parameter for SAR ADC channel */
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Review shows that conversion from uint32_t to enum does not have any negative drawbacks');
        accMode = (cy_en_autanalog_sar_acc_mode_t)_FLD2VAL(SAR_STA_CTRL_AVG_MODE, AUTANALOG_SAR_CTRL(baseAddr));

        /* Get SHIFT_MODE parameter for SAR ADC channel */
        avgShiftMode16 = _FLD2BOOL(SAR_STA_CTRL_SHIFT_MODE, AUTANALOG_SAR_CTRL(baseAddr));

        /* Averaging is configured */
        if (accEn && (accMode != CY_AUTANALOG_SAR_ACC_DISABLED))
        {
            /* Get AVG_SHIFT parameter for SAR ADC channel */
            accShift = _FLD2BOOL(SAR_STA_MUX_CHAN_CFG_AVG_SHIFT, AUTANALOG_SAR_MUX_CHAN_CFG(baseAddr, sarChannel));

            /* Get AVG_CNT parameter for SAR ADC sequencer */
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that conversion from uint32_t to uint8_t does not have any negative drawbacks');
            avgCnt = (sarLP == false) ?
                      _FLD2VAL(SAR_SEQ_HS_DATA_AVG_CNT, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)):
                      _FLD2VAL(SAR_SEQ_LP_DATA_AVG_CNT, AUTANALOG_SAR_SEQ_LP_DATA(baseAddr, sarSequencer));

            /* Averaging is not done in HW */
            if (!accShift || (avgShiftMode16 && (avgCnt < (uint8_t)CY_AUTANALOG_SAR_ACC_CNT32)))
            {
                /* Calculate average value in 16b presentation */
                sarCounts = SAR_GetAverageTempCounts(avgShiftMode16, avgCnt, sarCounts);
            }
        }

        /* Shift 12b value to 16b */
        if (!avgShiftMode16)
        {
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.1','Review shows that operator "<<" does not have any negative drawbacks');
            sarCounts <<= 4UL;
        }

        /* Calculate die temperature based on SAR ACD counts in 16b presentation */
        temp = SAR_CountsToDegreeC(sarLP, sarCounts);
    }

    return (int16_t) temp;
}


cy_en_autanalog_status_t Cy_AutAnalog_FIFO_LoadConfig(uint8_t fifoIdx, const cy_stc_autanalog_fifo_cfg_t * fifoCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_FIFO_BAD_PARAM;

    uint32_t baseAddr;
    uint32_t regVal;
    uint8_t cfgIdx;

    result = Cy_AutAnalog_IdxToBaseAddr(CY_AUTANALOG_FIFO, fifoIdx, &baseAddr);

    if ((CY_AUTANALOG_SUCCESS == result) && (NULL != fifoCfg))
    {
        /* Update CFG register */
        /* Validate enumerations for CFG register */
        CY_ASSERT_L3(AUTANALOG_MMIO_FIFO_CFG(fifoCfg->split));

        regVal = _VAL2FLD(LPPASS_MMIO_STA_CFG_SEL, fifoCfg->split);

        AUTANALOG_MMIO_FIFO_STA_CFG(baseAddr) = regVal;

        /* Update LEVEL[] registers */
        for (cfgIdx = 0U; cfgIdx < CY_AUTANALOG_FIFO_BUFS_NUM; cfgIdx++)
        {
            /* Validate enumerations for LEVEL[] registers */
            CY_ASSERT_L3(AUTANALOG_MMIO_FIFO_LEVEL(fifoCfg->level[cfgIdx]));

            regVal = _VAL2FLD(LPPASS_MMIO_STA_LEVEL_LEVEL, fifoCfg->level[cfgIdx]);

            AUTANALOG_MMIO_FIFO_STA_LEVEL(baseAddr, cfgIdx) = regVal;
        }
    }
    else
    {
        result = CY_AUTANALOG_FIFO_BAD_PARAM;
    }

    return result;
}


uint16_t Cy_AutAnalog_FIFO_ReadData(uint8_t fifoIdx, uint8_t buffIdx, uint16_t words, int32_t * data)
{
    uint16_t locSize = 0U;

    CY_ASSERT_L2(AUTANALOG_MMIO_FIFO_BUFF_IDX(buffIdx));

    if (NULL != data && words > 0U)
    {
        locSize = Cy_AutAnalog_FIFO_GetSize(fifoIdx, buffIdx);

        locSize = (words <= locSize) ? words : locSize;

        for (uint16_t idx = 0U; idx < locSize; idx++)
        {
            data[idx] = Cy_AutAnalog_FIFO_ReadWord(fifoIdx, buffIdx);
        }
    }

    return locSize;
}


uint16_t Cy_AutAnalog_FIFO_ReadAllData(uint8_t fifoIdx, uint8_t buffIdx, int32_t * data)
{
    uint16_t locSize = 0U;

    CY_ASSERT_L2(AUTANALOG_MMIO_FIFO_BUFF_IDX(buffIdx));

    if (NULL != data)
    {
        locSize = Cy_AutAnalog_FIFO_GetSize(fifoIdx, buffIdx);

        for (uint16_t idx = 0U; idx < locSize; idx++)
        {
            data[idx] = Cy_AutAnalog_FIFO_ReadWord(fifoIdx, buffIdx);
        }
    }

    return locSize;
}


uint16_t Cy_AutAnalog_FIFO_ReadDataChanId(uint8_t fifoIdx, uint8_t buffIdx, cy_en_autanalog_sar_input_t input, int32_t * data, uint8_t * chanID)
{
    uint16_t locSize = 0U;
    uint32_t locData = 0U;

    CY_ASSERT_L2(AUTANALOG_SAR_INPUT(input));

    if ((NULL != data) && (NULL != chanID))
    {
        locSize = Cy_AutAnalog_FIFO_GetSize(fifoIdx, buffIdx);

        for (uint16_t idx = 0U; idx < locSize; idx++)
        {
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.8', 1, 'Review shows that type conversion from signed to unsigned does not have any negative drawbacks');
            locData = (uint32_t)Cy_AutAnalog_FIFO_ReadWord(fifoIdx, buffIdx);
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.8');

            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.3', 1, 'Review shows that type conversion from uint32_t to uint8_t does not have any negative drawbacks');
            chanID[idx] = (CY_AUTANALOG_SAR_INPUT_GPIO == input) ?
                          (locData & AUTANALOG_MMIO_FIFO_CH_ID_MASK_GPIO) >> AUTANALOG_MMIO_FIFO_CH_ID_POS_GPIO :
                          (locData & AUTANALOG_MMIO_FIFO_CH_ID_MASK_MUX)  >> AUTANALOG_MMIO_FIFO_CH_ID_POS_MUX;
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.3');

            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.3', 2, 'Review shows that type conversion from uint16_t to int32_t does not have any negative drawbacks');
            data[idx] = ((locData & AUTANALOG_MMIO_FIFO_SIGN_MASK) == AUTANALOG_MMIO_FIFO_SIGN_MASK) ?
                        (int32_t)(int16_t)CY_LO16(locData) :
                        (int32_t)CY_LO16(locData);
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.3');
        }
    }

    return locSize;
}


#if !defined (CY_AUTANALOG_FIR_DISABLE)
static cy_en_autanalog_status_t SAR_LoadFIR(uint8_t sarIdx, uint8_t cfgNum, const cy_stc_autanalog_sar_fir_cfg_t * firCfg)
{
    cy_en_autanalog_status_t result = CY_AUTANALOG_SUCCESS;

    uint8_t cfgIdx;

    for (cfgIdx = 0U; cfgIdx < cfgNum; cfgIdx++)
    {
        CY_ASSERT_L3(AUTANALOG_SAR_FIR_IDX(cfgIdx));

        if (CY_AUTANALOG_SUCCESS != Cy_AutAnalog_SAR_LoadFIRconfig(sarIdx, cfgIdx, &firCfg[cfgIdx]))
        {
            result = CY_AUTANALOG_SAR_BAD_PARAM;
            break;
        }
    }

    return result;
}
#endif


static void SAR_LoadGpioChan(uint32_t baseAddr, uint8_t cfgNum, cy_stc_autanalog_sar_hs_chan_t * const hsGpioChan[])
{
    uint32_t regVal;
    uint8_t cfgIdx;

    if (NULL != hsGpioChan)
    {
        for (cfgIdx = 0U; cfgIdx < cfgNum; cfgIdx++)
        {
            CY_ASSERT_L3(AUTANALOG_SAR_CHANNEL(CY_AUTANALOG_SAR_INPUT_GPIO, cfgIdx));

            if (NULL != hsGpioChan[cfgIdx])
            {
                CY_ASSERT_L3(AUTANALOG_SAR_GPIO_PIN(hsGpioChan[cfgIdx]->posPin));
                CY_ASSERT_L3(AUTANALOG_SAR_CH_COEF(hsGpioChan[cfgIdx]->posCoeff));
                CY_ASSERT_L3(AUTANALOG_SAR_GPIO_PIN(hsGpioChan[cfgIdx]->negPin));
                CY_ASSERT_L3(AUTANALOG_SAR_CH_COEF(hsGpioChan[cfgIdx]->negCoeff));
                CY_ASSERT_L3(AUTANALOG_SAR_STATUS_SEL(hsGpioChan[cfgIdx]->hsLimit));
                CY_ASSERT_L3(AUTANALOG_MMIO_FIFO_SEL(hsGpioChan[cfgIdx]->fifoSel));

                regVal = _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_POS_PIN, hsGpioChan[cfgIdx]->posPin);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN, hsGpioChan[cfgIdx]->hsDiffEn);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_SIGNED, hsGpioChan[cfgIdx]->sign);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_POS_COEFF_SEL, hsGpioChan[cfgIdx]->posCoeff);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_NEG_PIN, hsGpioChan[cfgIdx]->negPin);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_AVG_SHIFT, hsGpioChan[cfgIdx]->accShift);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_NEG_COEFF_SEL, hsGpioChan[cfgIdx]->negCoeff);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_STATUS_SEL, hsGpioChan[cfgIdx]->hsLimit);
                regVal |= _VAL2FLD(SAR_STA_GPIO_CHAN_CFG_FIFO_SEL, hsGpioChan[cfgIdx]->fifoSel);

                AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, cfgIdx) = regVal;
            }
            else
            {
                AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, cfgIdx) = 0U;
            }
        }
    }
}


static void SAR_LoadMuxChan(uint32_t baseAddr, uint8_t cfgNum, cy_stc_autanalog_sar_mux_chan_t * const intMuxChan[])
{
    uint32_t regVal;
    uint8_t cfgIdx;

    if (NULL != intMuxChan)
    {
        for (cfgIdx = 0U; cfgIdx < cfgNum; cfgIdx++)
        {
            CY_ASSERT_L3(AUTANALOG_SAR_CHANNEL(CY_AUTANALOG_SAR_INPUT_MUX, cfgIdx));

            if (NULL != intMuxChan[cfgIdx])
            {
                CY_ASSERT_L3(AUTANALOG_SAR_MUX_PIN(intMuxChan[cfgIdx]->posPin));
                CY_ASSERT_L3(AUTANALOG_SAR_CH_COEF(intMuxChan[cfgIdx]->posCoeff));
                CY_ASSERT_L3(AUTANALOG_SAR_MUX_PIN(intMuxChan[cfgIdx]->negPin));
                CY_ASSERT_L3(AUTANALOG_SAR_CH_COEF(intMuxChan[cfgIdx]->negCoeff));
                CY_ASSERT_L3(AUTANALOG_SAR_STATUS_SEL(intMuxChan[cfgIdx]->muxLimit));
                CY_ASSERT_L3(AUTANALOG_MMIO_FIFO_SEL(intMuxChan[cfgIdx]->fifoSel));

                regVal = _VAL2FLD(SAR_STA_MUX_CHAN_CFG_POS_MUX_SEL, intMuxChan[cfgIdx]->posPin);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_SIGNED, intMuxChan[cfgIdx]->sign);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_POS_COEFF_SEL, intMuxChan[cfgIdx]->posCoeff);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_NEG_MUX_SEL, intMuxChan[cfgIdx]->negPin);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_BUF_BYPASS, intMuxChan[cfgIdx]->buffBypass);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_AVG_SHIFT, intMuxChan[cfgIdx]->accShift);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_NEG_COEFF_SEL, intMuxChan[cfgIdx]->negCoeff);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_STATUS_SEL, intMuxChan[cfgIdx]->muxLimit);
                regVal |= _VAL2FLD(SAR_STA_MUX_CHAN_CFG_FIFO_SEL, intMuxChan[cfgIdx]->fifoSel);

                AUTANALOG_SAR_MUX_CHAN_CFG(baseAddr, cfgIdx) = regVal;
            }
            else
            {
                AUTANALOG_SAR_MUX_CHAN_CFG(baseAddr, cfgIdx) = 0U;
            }
        }
    }
}


static void SAR_LoadRangeCond(uint32_t baseAddr, uint8_t cfgNum, cy_stc_autanalog_sar_limit_t * const limitCond[])
{
    uint32_t regVal;
    uint8_t cfgIdx;

    if (NULL != limitCond)
    {
        for (cfgIdx = 0U; cfgIdx < cfgNum; cfgIdx++)
        {
            if (NULL != limitCond[cfgIdx])
            {
                CY_ASSERT_L3(AUTANALOG_SAR_STATUS_COND(limitCond[cfgIdx]->cond));

                regVal = _VAL2FLD(SAR_STA_STATUS_CFG_RANGE_COND, limitCond[cfgIdx]->cond);
                AUTANALOG_SAR_STATUS_CFG(baseAddr, cfgIdx) = regVal;

                regVal = (uint32_t)_VAL2FLD(SAR_STA_STATUS_RANGE_LOW_RANGE_LOW, limitCond[cfgIdx]->low);
                AUTANALOG_SAR_STATUS_RANGE_LOW(baseAddr, cfgIdx) = regVal;

                regVal = (uint32_t)_VAL2FLD(SAR_STA_STATUS_RANGE_HIGH_RANGE_HIGH, limitCond[cfgIdx]->high);
                AUTANALOG_SAR_STATUS_RANGE_HIGH(baseAddr, cfgIdx) = regVal;
            }
            else
            {
                AUTANALOG_SAR_STATUS_CFG(baseAddr, cfgIdx) = 0U;
                AUTANALOG_SAR_STATUS_RANGE_LOW(baseAddr, cfgIdx) = 0U;
                AUTANALOG_SAR_STATUS_RANGE_HIGH(baseAddr, cfgIdx) = 0U;
            }
        }
    }
}


static int32_t SAR_CheckChanOffset(uint32_t baseAddr, bool sarLP, uint8_t sarSequencer, cy_en_autanalog_sar_input_t sarInput,
                                   uint8_t sarChannel, bool sarMode16)
{
    int32_t offset;

    bool sign = false;
    bool diff = false;

    /* In pseudo-differential mode the result voltage after subtraction can be negative */
    if (CY_AUTANALOG_SAR_INPUT_GPIO == sarInput)
    {
        /* Get HS_DIFFERENTIAL_EN parameter for GPIO channel */
        diff = _FLD2BOOL(SAR_STA_GPIO_CHAN_CFG_HS_DIFFERENTIAL_EN, AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, sarChannel));

        /* Get SIGN parameter for GPIO channel in pseudo-differential mode */
        sign = _FLD2BOOL(SAR_STA_GPIO_CHAN_CFG_SIGNED, AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, sarChannel));
    }
    /* Reference voltage can be routed to negative pin of SAR ADC just for MUX channels */
    else if (CY_AUTANALOG_SAR_INPUT_MUX == sarInput)
    {
        /* Get SIGN parameter for MUX channel */
        sign = _FLD2BOOL(SAR_STA_MUX_CHAN_CFG_SIGNED, AUTANALOG_SAR_MUX_CHAN_CFG(baseAddr, sarChannel));

        /* Get DIFFERENTIAL_EN parameter for MUX channel */
        diff = sarLP ? _FLD2BOOL(SAR_STA_CTRL_LP_DIFFERENTIAL_EN, AUTANALOG_SAR_CTRL(baseAddr)) :
        (CY_AUTANALOG_SAR_CHAN_CFG_MUX0_PSEUDO_DIFF == _FLD2VAL(SAR_SEQ_HS_DATA_HS_MUX_CHAN_EN_SEL, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)));
    }
    else
    {
        /* MISRA */
    }

    /* For signed, not pseudo-differential channels in single-ended mode, offset should be set to half of scale with positive sign,
     * depend on SAR ADC numeric resolution.
     */
    if (sign && !diff)
    {
        offset = sarMode16 ? AUTANALOG_SAR_OFFSET_BITS16 : AUTANALOG_SAR_OFFSET_BITS12;
    }
    /* For unsigned differential channels, offset should be set to half of scale with negative sign,
     * depend on SAR ADC numeric resolution.
     */
    else if (!sign && diff)
    {
        offset = sarMode16 ? -AUTANALOG_SAR_OFFSET_BITS16 : -AUTANALOG_SAR_OFFSET_BITS12;
    }
    else
    {
        offset = 0;
    }

    return offset;
}


static int32_t SAR_GetAverageVoltCounts(uint32_t baseAddr, bool sarLP, uint8_t sarSequencer,
               cy_en_autanalog_sar_input_t sarInput, uint8_t sarChannel, int32_t sarCounts, bool * sarMode16)
{
    bool                           avgEn;
    cy_en_autanalog_sar_acc_mode_t avgMode;
    uint8_t                        avgCnt;
    bool                           avgShift;
    bool                           avgShiftMode16 = false;

    /* Get AVG_EN parameter for SAR ADC sequencer */
    avgEn = (sarLP == false) ?
             _FLD2BOOL(SAR_SEQ_HS_DATA_AVG_EN, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)):
             _FLD2BOOL(SAR_SEQ_LP_DATA_AVG_EN, AUTANALOG_SAR_SEQ_LP_DATA(baseAddr, sarSequencer));

    /* Get AVG_MODE parameter for SAR ADC channel */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Review shows that conversion from uint32_t to enum does not have any negative drawbacks');
    avgMode = (cy_en_autanalog_sar_acc_mode_t)_FLD2VAL(SAR_STA_CTRL_AVG_MODE, AUTANALOG_SAR_CTRL(baseAddr));

    /* Check if average is enabled */
    if (avgEn && (avgMode != CY_AUTANALOG_SAR_ACC_DISABLED))
    {
        /* Get AVG_CNT parameter for SAR ADC sequencer */
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that conversion from uint32_t to uint8_t does not have any negative drawbacks');
        avgCnt = (sarLP == false) ?
                  _FLD2VAL(SAR_SEQ_HS_DATA_AVG_CNT, AUTANALOG_SAR_SEQ_HS_DATA(baseAddr, sarSequencer)):
                  _FLD2VAL(SAR_SEQ_LP_DATA_AVG_CNT, AUTANALOG_SAR_SEQ_LP_DATA(baseAddr, sarSequencer));

        /* Get AVG_SHIFT parameter for SAR ADC channel */
        avgShift = (sarInput == CY_AUTANALOG_SAR_INPUT_GPIO) ?
                    _FLD2BOOL(SAR_STA_GPIO_CHAN_CFG_AVG_SHIFT, AUTANALOG_SAR_GPIO_CHAN_CFG(baseAddr, sarChannel)):
                    _FLD2BOOL(SAR_STA_MUX_CHAN_CFG_AVG_SHIFT, AUTANALOG_SAR_MUX_CHAN_CFG(baseAddr, sarChannel));

        /* Get SHIFT_MODE parameter for SAR ADC channel */
        avgShiftMode16 = _FLD2BOOL(SAR_STA_CTRL_SHIFT_MODE, AUTANALOG_SAR_CTRL(baseAddr));

        /* Averaging is configured but division is not done in HW */
        if (!avgShift)
        {
            /* Calculate average value */
            CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Review shows that conversion from unsigned to signed does not have any negative drawbacks');
            sarCounts /= (int32_t)(1UL << (avgCnt + 1UL));
        }

        /* Counts value is within 12bits resolution */
        if (((sarCounts < 0) && (sarCounts > -4096)) || (((uint32_t)sarCounts <= 4095U)))
        {
            avgShiftMode16 = false;
        }
    }

    if (NULL != sarMode16)
    {
        *sarMode16 = avgShiftMode16;
    }

    return sarCounts;
}


static int32_t SAR_GetAverageTempCounts(bool avgShiftMode16, uint8_t avgCnt, int32_t sarCounts)
{
    uint16_t avgDivider;

    /* Calculate divider value */
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.3','Review shows that conversion from uint32_t to uint16_t does not have any negative drawbacks');
    avgDivider = (uint16_t)(1UL << (avgCnt + 1UL));

    /* Averaged value */
    sarCounts /= (int32_t)avgDivider;

    /* Shift 12b value to 16b */
    if (avgShiftMode16)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.1','Review shows that operator "<<" does not have any negative drawbacks');
        sarCounts <<= 4UL;
    }

    return sarCounts;
}


static int32_t SAR_CountsToDegreeC(bool sarLP, int32_t sarCounts)
{
    int32_t temp = sarCounts;

    /* Calculate tInitial in Q16.16 */
    if (true == sarLP)
    {
        temp = ((int32_t)dieTempMultiplierLP * temp) +
               ((int32_t)dieTempOffsetLP);
    }
    else
    {
        temp = ((int32_t)dieTempMultiplierHS * temp) +
               ((int32_t)dieTempOffsetHS);
    }

    /* Add tInitial + 0.5 to round to nearest int. Shift off frac bits, and return. */
    temp = (temp + AUTANALOG_SAR_TEMP_HALF) / AUTANALOG_SAR_TEMP_DIV;

    return temp;
}

void Cy_AutAnalog_SAR_LoadDieTempTrimmCoeff(uint32_t dieTrimmMultiplierHS, uint32_t dieTrimmOffsetHS, uint32_t dieTrimmMultiplierLP, uint32_t dieTrimmOffsetLP)
{
    dieTempMultiplierHS = dieTrimmMultiplierHS;
    dieTempOffsetHS     = dieTrimmOffsetHS;
    dieTempMultiplierLP = dieTrimmMultiplierLP;
    dieTempOffsetLP     = dieTrimmOffsetLP;
}

#endif /* CY_IP_MXS22LPPASS_SAR */

/* [] END OF FILE */

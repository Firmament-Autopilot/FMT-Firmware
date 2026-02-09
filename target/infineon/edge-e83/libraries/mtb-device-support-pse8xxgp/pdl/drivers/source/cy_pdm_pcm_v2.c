/***************************************************************************//**
* \file cy_pdm_pcm_v2.c
* \version 1.10
*
* The source code file for the PDM_PCM driver.
*
********************************************************************************
* \copyright
* Copyright 2019-2022 Cypress Semiconductor Corporation
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

#if defined (CY_IP_MXPDM)

#include "cy_pdm_pcm_v2.h"

#define CY_PDM_PCM_MAX_24BIT  ((int32_t)8388607)
#define CY_PDM_PCM_MIN_24BIT  ((int32_t)-8388608)
#define CY_PDM_PCM_MAX_16BIT  ((int32_t)32767)
#define CY_PDM_PCM_MIN_16BIT  ((int32_t)-32768)

/* Gain table for -30dB to +30dB in Q8.8 format (gain * 256)
   gain_db = 20 log(out/in) */
static const uint16_t cy_pdm_pcm_gain_table[81] = {
    3, 3, 3, 4, 4, 5, 5, 6, 6, 7,
    8, 9, 10, 11, 13, 14, 16, 18, 20, 23,
    26, 29, 32, 36, 41, 46, 51, 57, 64, 72,
    81, 91, 102, 114, 128, 144, 162, 181, 203, 228,
    256, 287, 322, 362, 406, 455, 511, 573, 643, 722,
    810, 908, 1019, 1144, 1283, 1440, 1615, 1812, 2033, 2282,
    2560, 2872, 3223, 3616, 4057, 4552, 5108, 5731, 6430, 7215,
    8095, 9083, 10192, 11435, 12830, 14396, 16153, 18123, 20335, 22816,
    25600
};


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 14.3', 14, \
'Checked manually, passed 1 or 0 in _BOOL2FLD for appropriate functionality.')

CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 10.1', 1, \
'Checked manually, passed 1 or 0 in _BOOL2FLD for appropriate functionality.')

/**
* \addtogroup group_pdm_pcm_functions_v2
* \{
*/

/******************************************************************************
* Function Name: Cy_PDM_PCM_Channel_Init
***************************************************************************//**
*
* Initialize the PDM-PCM Channel
*
* \pre Make sure PDM-PCM is initialized before calling this function. \ref Cy_PDM_PCM_Init
*
* \param  base The pointer to the PDM-PCM instance address
* \param  channel_config The pointer to a configuration structure.
* \param  channel_num The channel number to be initialized.
* \return error / status code. See \ref cy_en_pdm_pcm_status_t.
*
* \funcusage
* \snippet pdm_pcmv2/snippet/main.c snippet_Cy_PDM_PCM_Channel_Init
*
*******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_Channel_Init(PDM_Type * base, cy_stc_pdm_pcm_channel_config_t const * channel_config, uint8_t channel_num)
{
    cy_en_pdm_pcm_status_t ret = CY_PDM_PCM_BAD_PARAM;

    if((NULL != base) && (NULL != channel_config))
    {
        CY_ASSERT_L2(CY_PDM_PCM_IS_WORD_SIZE_VALID(channel_config->wordSize));
        CY_ASSERT_L2(CY_PDM_PCM_IS_SIGNEXTENSION_VALID(channel_config->signExtension));
        CY_ASSERT_L2(CY_PDM_PCM_IS_TRIG_LEVEL(channel_config->rxFifoTriggerLevel));
        CY_ASSERT_L2(CY_PDM_PCM_IS_SCALE_VALID(channel_config->fir0_scale));
        CY_ASSERT_L2(CY_PDM_PCM_IS_SCALE_VALID(channel_config->fir1_scale));


        ret = CY_PDM_PCM_SUCCESS;


        PDM_PCM_RX_FIFO_CTL(base, channel_num) = _VAL2FLD(PDM_CH_RX_FIFO_CTL_TRIGGER_LEVEL, channel_config->rxFifoTriggerLevel);


        PDM_PCM_CH_CTL(base, channel_num) = _VAL2FLD(PDM_CH_CTL_WORD_SIZE, channel_config->wordSize) |
                                  _BOOL2FLD(PDM_CH_CTL_WORD_SIGN_EXTEND, channel_config->signExtension) |
                                  _BOOL2FLD(PDM_CH_CTL_ENABLED, CY_PDM_PCM_ENABLE);

        PDM_PCM_CH_IF_CTL(base, channel_num) = _VAL2FLD(PDM_CH_IF_CTL_SAMPLE_DELAY,      channel_config->sampledelay);


        PDM_PCM_CH_CIC_CTL(base, channel_num) = ((uint32_t)channel_config->cic_decim_code);

        PDM_PCM_CH_FIR0_CTL(base, channel_num) = _VAL2FLD(PDM_CH_FIR0_CTL_DECIM3,  channel_config->fir0_decim_code) |
                                       _VAL2FLD(PDM_CH_FIR0_CTL_SCALE,        channel_config->fir0_scale) |
                                       _VAL2FLD(PDM_CH_FIR0_CTL_ENABLED,     channel_config->fir0_enable);

        PDM_PCM_CH_FIR1_CTL(base, channel_num) = _VAL2FLD(PDM_CH_FIR1_CTL_DECIM2,  channel_config->fir1_decim_code) |
                                       _VAL2FLD(PDM_CH_FIR1_CTL_SCALE,        channel_config->fir1_scale) |
                                       _VAL2FLD(PDM_CH_FIR1_CTL_ENABLED,     CY_PDM_PCM_ENABLE);
        if(!channel_config->dc_block_disable)
        {
            PDM_PCM_CH_DC_BLOCK_CTL(base, channel_num) = _VAL2FLD(PDM_CH_DC_BLOCK_CTL_CODE,    channel_config->dc_block_code) |
                                           _VAL2FLD(PDM_CH_DC_BLOCK_CTL_ENABLED, CY_PDM_PCM_ENABLE);
        }
        else
        {
            PDM_PCM_CH_DC_BLOCK_CTL(base, channel_num) = _VAL2FLD(PDM_CH_DC_BLOCK_CTL_ENABLED, CY_PDM_PCM_DISABLE);
        }

    }
    return ret;
}

/******************************************************************************
* Function Name: Cy_PDM_PCM_Init
***************************************************************************//**
*
* Initializes the PDM-PCM module
*
* \param  base The pointer to the PDM-PCM instance address
* \param  config The pointer to a configuration structure. \ref cy_stc_pdm_pcm_config_v2_t
* \return error / status code. See \ref cy_en_pdm_pcm_status_t.
*
* \funcusage
* \snippet pdm_pcmv2/snippet/main.c snippet_Cy_PDM_PCM_Init
*
*******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_Init(PDM_Type * base, cy_stc_pdm_pcm_config_v2_t const * config)
{
    cy_en_pdm_pcm_status_t ret = CY_PDM_PCM_BAD_PARAM;

    if((NULL != base) && (NULL != config))
    {
        CY_ASSERT_L2(CY_PDM_PCM_IS_CLK_SEL_VALID(config->clksel));
        CY_ASSERT_L2(CY_PDM_PCM_IS_HALVE_RATE_SET_VALID(config->halverate));
        CY_ASSERT_L2(CY_PDM_PCM_IS_ROUTE_VALID(config->route));

        ret = CY_PDM_PCM_SUCCESS;

        /* The clock setting */
        PDM_PCM_CLOCK_CTL(base) = _VAL2FLD(PDM_CLOCK_CTL_CLOCK_DIV, config->clkDiv) |
                                  _VAL2FLD(PDM_CLOCK_CTL_CLOCK_SEL, config->clksel) |
                                  _VAL2FLD(PDM_CLOCK_CTL_HALVE,     config->halverate);

        /* PDM-PCM ROUTE setting */
        PDM_PCM_ROUTE_CTL(base) = _VAL2FLD(PDM_ROUTE_CTL_DATA_SEL,  config->route);

        if(config->fir0_coeff_user_value != 0U)
        {
            PDM_PCM_FIR0_COEFF0(base) = _VAL2FLD(PDM_FIR0_COEFF0_DATA0, config->fir0_coeff[0].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF0_DATA1,     config->fir0_coeff[0].coeff_data1);

            PDM_PCM_FIR0_COEFF1(base) = _VAL2FLD(PDM_FIR0_COEFF1_DATA0, config->fir0_coeff[1].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF1_DATA1,     config->fir0_coeff[1].coeff_data1);

            PDM_PCM_FIR0_COEFF2(base) = _VAL2FLD(PDM_FIR0_COEFF2_DATA0, config->fir0_coeff[2].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF2_DATA1,     config->fir0_coeff[2].coeff_data1);

            PDM_PCM_FIR0_COEFF3(base) = _VAL2FLD(PDM_FIR0_COEFF3_DATA0, config->fir0_coeff[3].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF3_DATA1,     config->fir0_coeff[3].coeff_data1);

            PDM_PCM_FIR0_COEFF4(base) = _VAL2FLD(PDM_FIR0_COEFF4_DATA0, config->fir0_coeff[4].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF4_DATA1,     config->fir0_coeff[4].coeff_data1);

            PDM_PCM_FIR0_COEFF5(base) = _VAL2FLD(PDM_FIR0_COEFF5_DATA0, config->fir0_coeff[5].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF5_DATA1,     config->fir0_coeff[5].coeff_data1);

            PDM_PCM_FIR0_COEFF6(base) = _VAL2FLD(PDM_FIR0_COEFF6_DATA0, config->fir0_coeff[6].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF6_DATA1,     config->fir0_coeff[6].coeff_data1);

            PDM_PCM_FIR0_COEFF7(base) = _VAL2FLD(PDM_FIR0_COEFF7_DATA0, config->fir0_coeff[7].coeff_data0) |
                                 _VAL2FLD(PDM_FIR0_COEFF7_DATA1,     config->fir0_coeff[7].coeff_data1);
        }

        if(config->fir1_coeff_user_value != 0U)
        {
            PDM_PCM_FIR1_COEFF0(base) = _VAL2FLD(PDM_FIR1_COEFF0_DATA0, config->fir1_coeff[0].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF0_DATA1,     config->fir1_coeff[0].coeff_data1);

            PDM_PCM_FIR1_COEFF1(base) = _VAL2FLD(PDM_FIR1_COEFF1_DATA0, config->fir1_coeff[1].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF1_DATA1,     config->fir1_coeff[1].coeff_data1);

            PDM_PCM_FIR1_COEFF2(base) = _VAL2FLD(PDM_FIR1_COEFF2_DATA0, config->fir1_coeff[2].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF2_DATA1,     config->fir1_coeff[2].coeff_data1);

            PDM_PCM_FIR1_COEFF3(base) = _VAL2FLD(PDM_FIR1_COEFF3_DATA0, config->fir1_coeff[3].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF3_DATA1,     config->fir1_coeff[3].coeff_data1);

            PDM_PCM_FIR1_COEFF4(base) = _VAL2FLD(PDM_FIR1_COEFF4_DATA0, config->fir1_coeff[4].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF4_DATA1,     config->fir1_coeff[4].coeff_data1);

            PDM_PCM_FIR1_COEFF5(base) = _VAL2FLD(PDM_FIR1_COEFF5_DATA0, config->fir1_coeff[5].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF5_DATA1,     config->fir1_coeff[5].coeff_data1);

            PDM_PCM_FIR1_COEFF6(base) = _VAL2FLD(PDM_FIR1_COEFF6_DATA0, config->fir1_coeff[6].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF6_DATA1,     config->fir1_coeff[6].coeff_data1);

            PDM_PCM_FIR1_COEFF7(base) = _VAL2FLD(PDM_FIR1_COEFF7_DATA0, config->fir1_coeff[7].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF7_DATA1,     config->fir1_coeff[7].coeff_data1);

            PDM_PCM_FIR1_COEFF8(base) = _VAL2FLD(PDM_FIR1_COEFF8_DATA0, config->fir1_coeff[8].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF8_DATA1,     config->fir1_coeff[8].coeff_data1);

            PDM_PCM_FIR1_COEFF9(base) = _VAL2FLD(PDM_FIR1_COEFF9_DATA0, config->fir1_coeff[9].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF9_DATA1,     config->fir1_coeff[9].coeff_data1);

            PDM_PCM_FIR1_COEFF10(base) = _VAL2FLD(PDM_FIR1_COEFF10_DATA0, config->fir1_coeff[10].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF10_DATA1,     config->fir1_coeff[10].coeff_data1);

            PDM_PCM_FIR1_COEFF11(base) = _VAL2FLD(PDM_FIR1_COEFF11_DATA0, config->fir1_coeff[11].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF11_DATA1,     config->fir1_coeff[11].coeff_data1);

            PDM_PCM_FIR1_COEFF12(base) = _VAL2FLD(PDM_FIR1_COEFF12_DATA0, config->fir1_coeff[12].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF12_DATA1,     config->fir1_coeff[12].coeff_data1);

            PDM_PCM_FIR1_COEFF13(base) = _VAL2FLD(PDM_FIR1_COEFF13_DATA0, config->fir1_coeff[13].coeff_data0) |
                                 _VAL2FLD(PDM_FIR1_COEFF13_DATA1,     config->fir1_coeff[13].coeff_data1);

        }

    }

    return (ret);
}

/******************************************************************************
* Function Name: Cy_PDM_PCM_test_Init
***************************************************************************//**
*
* Initializes the PDM-PCM module test mode.
*
* \param  base The pointer to the PDM-PCM instance address
* \param  config The pointer to a configuration structure. \ref cy_stc_pdm_pcm_config_v2_t
* \param test_config test  Mode configuration. \ref cy_stc_test_config_t
* \return error / status code. See \ref cy_en_pdm_pcm_status_t.
*
*******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_test_Init(PDM_Type * base, cy_stc_pdm_pcm_config_v2_t const * config, cy_stc_test_config_t const * test_config)
{
    cy_en_pdm_pcm_status_t ret = CY_PDM_PCM_BAD_PARAM;

    if((NULL != base) && (NULL != config) && (NULL != test_config) )
    {
        if(!test_config->enable)
        {
            return ret;
        }
        CY_ASSERT_L2(CY_PDM_PCM_IS_CLK_SEL_VALID(config->clksel));
        CY_ASSERT_L2(CY_PDM_PCM_IS_HALVE_RATE_SET_VALID(config->halverate));
        CY_ASSERT_L2(CY_PDM_PCM_IS_ROUTE_VALID(config->route));

        ret = CY_PDM_PCM_SUCCESS;

        PDM_PCM_TEST_CTL(base) = _VAL2FLD(PDM_TEST_CTL_DRIVE_DELAY_HI, test_config->drive_delay_hi) |
                             _VAL2FLD(PDM_TEST_CTL_DRIVE_DELAY_LO,     test_config->drive_delay_lo);
        PDM_PCM_TEST_CTL(base) |= _VAL2FLD(PDM_TEST_CTL_MODE_HI,            test_config->mode_hi) |
                             _VAL2FLD(PDM_TEST_CTL_MODE_LO,            test_config->mode_lo);
        PDM_PCM_TEST_CTL(base) |= _VAL2FLD(PDM_TEST_CTL_AUDIO_FREQ_DIV,     test_config->audio_freq_div) |
                             _BOOL2FLD(PDM_TEST_CTL_CH_ENABLED,        test_config->enable);

    }

    return (ret);
}


/*******************************************************************************
* Function Name: Cy_PDM_PCM_Channel_DeInit
****************************************************************************//**
*
* Uninitializes the PDM-PCM channel.
*
* \param base The pointer to the PDM-PCM instance address.
* \param channel_num channel number to be de initialized.
*
* \funcusage
* \snippet pdm_pcmv2/snippet/main.c snippet_Cy_PDM_PCM_Channel_DeInit
*
*******************************************************************************/
void Cy_PDM_PCM_Channel_DeInit(PDM_Type * base, uint8_t channel_num)
{
    PDM_PCM_CH_IF_CTL(base, channel_num) = CY_PDM_PCM_CH_IF_CTL_DEFAULT;/* Channel interface control default value */
    PDM_PCM_CH_CTL(base, channel_num) = CY_PDM_PCM_CH_CTL_DEFAULT; /* Channel control default values */
    PDM_PCM_CH_CIC_CTL(base, channel_num) = CY_PDM_PCM_CH_CIC_DECIM_CODE_DEFAULT;
    PDM_PCM_CH_FIR1_CTL(base, channel_num) = CY_PDM_PCM_CH_FIR1_DEFAULT;
    PDM_PCM_CH_DC_BLOCK_CTL(base, channel_num) = CY_PDM_PCM_CH_DCBLOCK_DEFAULT;
    PDM_PCM_CH_FIR0_CTL(base, channel_num) = 0UL;
    PDM_PCM_INTR_RX_MASK(base, channel_num) = 0UL; /* Disable interrupts */
    PDM_PCM_RX_FIFO_CTL(base, channel_num) = 0UL;
    PDM_PCM_CTL_CLR(base) = (1UL << channel_num);

}


/*******************************************************************************
* Function Name: Cy_PDM_PCM_DeInit
****************************************************************************//**
*
* Uninitializes the PDM-PCM module.
*
* \param base The pointer to the PDM-PCM instance address.
*
* \funcusage
* \snippet pdm_pcmv2/snippet/main.c snippet_Cy_PDM_PCM_DeInit
*
*******************************************************************************/
void Cy_PDM_PCM_DeInit(PDM_Type * base)
{
    PDM_PCM_ROUTE_CTL(base) = 0UL; /* Default Route settings */
    PDM_PCM_TEST_CTL(base) = CY_PDM_PCM_TEST_CTL_DEFAULT; /* Default Test settings */
    PDM_PCM_CTL(base) = 0UL; /* Disable the PDM_PCM IP block */
    PDM_PCM_CLOCK_CTL(base) = CY_PDM_PCM_CLK_CTL_DEFAULT; /* The default clock settings */
}

/******************************************************************************
* Function Name: Cy_PDM_PCM_SetGain
***************************************************************************//**
*
* Sets the gain factor for the given channel.
*
* \param base
* The pointer to the PDM-PCM instance address.
*
* \param channel_num
* The channel number for gain setting.
*
* \param gain
* Gain value defined as cy_en_pdm_pcm_gain_scale_t
*
******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_SetGain (PDM_Type * base, uint8_t channel_num, cy_en_pdm_pcm_gain_sel_t gain)
{
    cy_en_pdm_pcm_status_t result = CY_PDM_PCM_SUCCESS;
    cy_en_pdm_pcm_ch_fir1_decimcode_t decim_code;
    uint8_t fir1_scale_value = (uint8_t)gain;

    if (!CY_PDM_PCM_IS_SCALE_VALID(fir1_scale_value))
    {
        result = CY_PDM_PCM_BAD_PARAM;
    }

    if (CY_PDM_PCM_SUCCESS == result)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Value retrieved is compatible with cy_en_pdm_pcm_ch_fir1_decimcode_t enum.');
        decim_code = (cy_en_pdm_pcm_ch_fir1_decimcode_t)_FLD2VAL(PDM_CH_FIR1_CTL_DECIM2, PDM_PCM_CH_FIR1_CTL(base, channel_num));
        Cy_PDM_PCM_Channel_Set_Fir1(base, channel_num, decim_code, fir1_scale_value);
    }

    return result;
}

/******************************************************************************
* Function Name: Cy_PDM_PCM_SetFIR0_Scale
***************************************************************************//**
*
* Sets the FIR0 Scale factor for the given channel.
*
* \param base
* The pointer to the PDM-PCM instance address.
*
* \param channel_num
* The channel number for gain setting.
*
* \param scale
* scale value defined as cy_en_pdm_pcm_gain_scale_t
*
******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_SetFIR0_Scale (PDM_Type * base, uint8_t channel_num, cy_en_pdm_pcm_gain_sel_t scale)
{
    cy_en_pdm_pcm_status_t result = CY_PDM_PCM_SUCCESS;
    cy_en_pdm_pcm_ch_fir0_decimcode_t decim_code;
    uint8_t fir0_scale_value = (uint8_t)scale;

    if (!CY_PDM_PCM_IS_SCALE_VALID(fir0_scale_value))
    {
        result = CY_PDM_PCM_BAD_PARAM;
    }

    if (CY_PDM_PCM_SUCCESS == result)
    {
        CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Value retrieved is compatible with cy_en_pdm_pcm_ch_fir0_decimcode_t enum.');
        decim_code = (cy_en_pdm_pcm_ch_fir0_decimcode_t)_FLD2VAL(PDM_CH_FIR0_CTL_DECIM3, PDM_PCM_CH_FIR0_CTL(base, channel_num));
        Cy_PDM_PCM_Channel_Set_Fir0(base, channel_num, decim_code, fir0_scale_value);
    }

    return result;
}

/******************************************************************************
* Function Name: Cy_PDM_PCM_ApplyPCM_Gain
***************************************************************************//**
*
* This function applies gain in software to one 24-bit PCM sample data
* output PCM format can be 24-bit or 16-bit, gain should be in the range
* of -40db to 40db.
*
* \param in_sample
* The pointer to the 24-bit PCM input.
*
* \param gain_db
* The gain to apply. must be within -40db to +40db.
*
* \param out_format
* PCM output format defined as cy_en_pdm_pcm_format_t
*
* \param out_sample
* pointer to output PCM. For 16-bit out format, lower 16-bits holds data.
******************************************************************************/
cy_en_pdm_pcm_status_t Cy_PDM_PCM_ApplyPCM_Gain (const int32_t *in_sample, int32_t gain_db, cy_en_pdm_pcm_format_t out_format, int32_t *out_sample)
{
    int32_t idx;
    int32_t  value;
    uint16_t gain;

    idx = gain_db + (int32_t)40;

    if (idx < (int32_t)0 || idx > (int32_t)80)
    {
        return CY_PDM_PCM_BAD_PARAM;
    }

    gain = cy_pdm_pcm_gain_table[idx];
    value = (int32_t)(((int64_t)in_sample[0] * (int32_t)gain) + (int32_t)128) >> 8u;

    if (out_format == CY_PDM_PCM_16BIT)
    {
        // Convert to 16-bit PCM and clip
        int32_t val16 = value >> 8u;
        if (val16 > CY_PDM_PCM_MAX_16BIT)
        {
            val16 = CY_PDM_PCM_MAX_16BIT;
        }
        else if (val16 < CY_PDM_PCM_MIN_16BIT)
        {
            val16 = CY_PDM_PCM_MIN_16BIT;
        }
        else
        {
            /*empty else*/
        }

        out_sample[0] = val16 & (int32_t)0x0000FFFF; /*lower 16 bits hold PCM value*/
    }
    else
    {
        if (value > CY_PDM_PCM_MAX_24BIT)
        {
            value = CY_PDM_PCM_MAX_24BIT;
        }
        else if (value < CY_PDM_PCM_MIN_24BIT)
        {
            value = CY_PDM_PCM_MIN_24BIT;
        }
        else
        {
            /*empty else*/
        }

        out_sample[0] = value;
    }

    return CY_PDM_PCM_SUCCESS;
}

/** \} group_pdm_pcm_functions_v2 */

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 10.1')

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 14.3')

#endif /* CY_IP_MXPDM */

/* [] END OF FILE */

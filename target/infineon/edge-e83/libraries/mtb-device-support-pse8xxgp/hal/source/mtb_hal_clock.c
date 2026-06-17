/***************************************************************************//**
* \file mtb_hal_clock.c
*
* \brief
* Provides an implementation for high level interface for interacting with the
* device clock
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

#include <stdlib.h>
#include "mtb_hal_utils.h"
#include "mtb_hal_clock.h"

#if (MTB_HAL_DRIVER_AVAILABLE_CLOCK)

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Private Defines
*******************************************************************************/


/*******************************************************************************
*                           Private Typedefs
*******************************************************************************/


/*******************************************************************************
*                       Private Function Definitions
*******************************************************************************/


/*******************************************************************************
*                           Public Structures
*******************************************************************************/

const mtb_hal_clock_interface_t mtb_hal_clock_peri_interface =
{
    .get_frequency_hz = mtb_hal_clock_get_peri_clock_freq,
    .set_frequency_hz = mtb_hal_clock_set_peri_clock_freq,
    .set_enabled      = mtb_hal_clock_set_peri_clock_enabled,
};

const mtb_hal_clock_interface_t mtb_hal_clock_hf_interface =
{
    .get_frequency_hz = mtb_hal_clock_get_hf_clock_freq,
    .set_frequency_hz = mtb_hal_clock_set_hf_clock_freq,
    .set_enabled      = mtb_hal_clock_set_hf_clock_enabled,
};

/*******************************************************************************
*                        Public Function Definitions
*******************************************************************************/
/** Gets the frequency in hertz the peripheral clock is currently operating at.*/
uint32_t mtb_hal_clock_get_peri_clock_freq(const void* clk)
{
    cy_en_divider_types_t dividerType;
    uint32_t              dividerNum;
    uint32_t              freq         = 0;

    CY_ASSERT(NULL != clk);
    dividerType = ((mtb_hal_peri_div_t*)clk)->div_type;
    dividerNum  = ((mtb_hal_peri_div_t*)clk)->div_num;

    /* Get the frequency of the output of the peripheral divider */
    #if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && \
    (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)
    en_clk_dst_t clk_dst = ((mtb_hal_peri_div_t*)clk)->clk_dst;
    freq = Cy_SysClk_PeriPclkGetFrequency(clk_dst, dividerType, dividerNum);
    #elif defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)
    freq = Cy_SysClk_PeriphGetFrequency(dividerType, dividerNum);
    #endif
    return freq;
}


/** Update the operating frequency of the peripheral clock */
cy_rslt_t mtb_hal_clock_set_peri_clock_freq(const void* clk, uint32_t frequency,
                                            uint32_t tolerance_ppm)
{
    cy_en_divider_types_t dividerType;
    uint32_t              dividerNum;
    en_clk_dst_t          clk_dst;
    uint32_t              source_freq;

    CY_ASSERT(NULL != clk);
    CY_ASSERT(frequency != 0);
    dividerType = ((mtb_hal_peri_div_t*)clk)->div_type;
    dividerNum  = ((mtb_hal_peri_div_t*)clk)->div_num;
    clk_dst     = ((mtb_hal_peri_div_t*)clk)->clk_dst;
    /* Get CLK_HF frequency */
    source_freq = mtb_hal_clock_get_peri_src_clock_freq(clk);
    CY_ASSERT(source_freq != 0);

    uint32_t dividerValue     = (source_freq / frequency);
    uint32_t dividerFracValue = 0;
    double   rslt_freq        = (((double)source_freq) / dividerValue); /* What frequency we'd
                                                                           achieve with
                                                                           this divider */

    /* Calculate the fractional divider value */
    if (dividerType >= CY_SYSCLK_DIV_16_5_BIT)
    {
        double closest_freq = rslt_freq;
        double combined_div = 0;
        // 31U = max fractional divider value
        while ((closest_freq > (double)frequency) && dividerFracValue < 31U)
        {
            combined_div = ((double)dividerValue + ((double)(dividerFracValue + 1) / 32));
            closest_freq = source_freq / combined_div;
            if (closest_freq > (double)frequency)
            {
                dividerFracValue += 1;
                rslt_freq = closest_freq;
            }
        }
    }

    if ((uint32_t)(abs(_mtb_hal_utils_calculate_tolerance(MTB_HAL_TOLERANCE_PPM, frequency,
                                                          (uint32_t)rslt_freq))) > tolerance_ppm)
    {
        return MTB_HAL_CLOCK_RSLT_ERR_FREQ;
    }

    dividerValue -= 1;
    /* dividerFracValue does not need -1 here as this register is 0-inclusive */

    #if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && \
    (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)

    Cy_SysClk_PeriPclkDisableDivider(clk_dst, dividerType, dividerNum);
    if (dividerType < CY_SYSCLK_DIV_16_5_BIT)
    {
        Cy_SysClk_PeriPclkSetDivider(clk_dst, dividerType, dividerNum, dividerValue);
    }
    else
    {
        Cy_SysClk_PeriPclkSetFracDivider(clk_dst, dividerType, dividerNum, dividerValue,
                                         dividerFracValue);
    }
    Cy_SysClk_PeriPclkEnableDivider(clk_dst, dividerType, dividerNum);

    #elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2))

    Cy_SysClk_PeriphDisableDivider(dividerType, dividerNum);
    if (dividerType < CY_SYSCLK_DIV_16_5_BIT)
    {
        Cy_SysClk_PeriphSetDivider(dividerType, dividerNum, dividerValue);
    }
    else
    {
        Cy_SysClk_PeriphSetFracDivider(dividerType, dividerNum, dividerValue, dividerFracValue);
    }
    Cy_SysClk_PeriphEnableDivider(dividerType, dividerNum);

    #endif // if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined
    // (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)
    return CY_RSLT_SUCCESS;
}


/** Enable/Disable the peripheral clock */
cy_rslt_t mtb_hal_clock_set_peri_clock_enabled(const void* clk, bool enable)
{
    cy_en_divider_types_t dividerType;
    uint32_t              dividerNum;

    CY_ASSERT(NULL != clk);
    dividerType = ((mtb_hal_peri_div_t*)clk)->div_type;
    dividerNum  = ((mtb_hal_peri_div_t*)clk)->div_num;

    #if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined (CY_IP_MXS40SRSS) && \
    (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)
    en_clk_dst_t clk_dst = ((mtb_hal_peri_div_t*)clk)->clk_dst;
    if (enable)
    {
        Cy_SysClk_PeriPclkEnableDivider(clk_dst, dividerType, dividerNum);
    }
    else
    {
        Cy_SysClk_PeriPclkDisableDivider(clk_dst, dividerType, dividerNum);
    }
    #elif (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2))
    CY_UNUSED_PARAMETER(clk_dst);
    if (enable)
    {
        Cy_SysClk_PeriphEnableDivider(dividerType, dividerNum);
    }
    else
    {
        Cy_SysClk_PeriphDisableDivider(dividerType, dividerNum);
    }
    #endif // if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || (defined
    // (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || defined (CY_IP_MXS22SRSS)
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_clock_get_peri_src_clock_freq
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_clock_get_peri_src_clock_freq(const void* clk)
{
    CY_ASSERT(NULL != clk);
    en_clk_dst_t clk_dst = ((mtb_hal_peri_div_t*)clk)->clk_dst;

    uint32_t src_freq = Cy_SysClk_ClkHfGetFrequency(Cy_Sysclk_PeriPclkGetClkHfNum(clk_dst));
    #if defined(CY_IP_MXS40SRSS)
    // May have a PERI clock between the HF and the peri divider, if so adjust for its divider
    uint32_t peri_grpNum = (((uint32_t)clk_dst) & PERI_PCLK_GR_NUM_Msk) >> PERI_PCLK_GR_NUM_Pos;
    // CLK_PERI only sources Peri Clock Group 0.  Ignore the divider for other groups
    uint32_t peri_div = (peri_grpNum == 0UL) ? (1UL + (uint32_t)Cy_SysClk_ClkPeriGetDivider()) : 1U;
    src_freq = CY_SYSLIB_DIV_ROUND(src_freq, peri_div);
    #endif /* defined(CY_IP_MXS40SRSS) */
    return src_freq;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_clock_get_hf_clock_freq
//--------------------------------------------------------------------------------------------------
uint32_t mtb_hal_clock_get_hf_clock_freq(const void* clk)
{
    return Cy_SysClk_ClkHfGetFrequency(((mtb_hal_hf_clock_t*)clk)->inst_num);
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_clock_set_hf_clock_freq
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_clock_set_hf_clock_freq(const void* clk, uint32_t frequency,
                                          uint32_t tolerance_ppm)
{
    CY_UNUSED_PARAMETER(clk);
    CY_UNUSED_PARAMETER(frequency);
    CY_UNUSED_PARAMETER(tolerance_ppm);
    return MTB_HAL_CLOCK_RSLT_ERR_NOT_SUPPORTED;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_clock_set_hf_clock_enabled
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_clock_set_hf_clock_enabled(const void* clk, bool enable)
{
    if (enable)
    {
        return Cy_SysClk_ClkHfEnable(((mtb_hal_hf_clock_t*)clk)->inst_num);
    }
    else
    {
        return Cy_SysClk_ClkHfDisable(((mtb_hal_hf_clock_t*)clk)->inst_num);
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_clock_set_enabled
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_clock_set_enabled(mtb_hal_clock_t* clock, bool enabled, bool wait_for_lock)
{
    // API not implemented yet
    CY_UNUSED_PARAMETER(clock);
    CY_UNUSED_PARAMETER(enabled);
    CY_UNUSED_PARAMETER(wait_for_lock);
    return MTB_HAL_CLOCK_RSLT_ERR_NOT_SUPPORTED;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_clock_set_frequency
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_clock_set_frequency(mtb_hal_clock_t* clock, uint32_t hz,
                                      const mtb_hal_clock_tolerance_t* tolerance)
{
    // API not implemented yet
    CY_UNUSED_PARAMETER(clock);
    CY_UNUSED_PARAMETER(hz);
    CY_UNUSED_PARAMETER(tolerance);
    return MTB_HAL_CLOCK_RSLT_ERR_NOT_SUPPORTED;
}


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* MTB_HAL_DRIVER_AVAILABLE_CLOCK */

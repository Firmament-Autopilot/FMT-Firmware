/***************************************************************************//**
* \file mtb_hal_lptimer_common.c
*
* \brief
* Provides a high level interface for interacting with the Infineon Low-Power Timer.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation
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

#include "mtb_hal_lptimer.h"


// This file applies to M0S8WCO and MCWDT IPs
#if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && (defined(CY_IP_M0S8WCO) || \
    ((defined(CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) || \
    ((SRSS_NUM_MCWDT_B) == 0)) || \
    defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) || \
    defined(CY_IP_MXS22SRSS)) && \
    /* Exclude MCWDT_B: */ \
    !((defined (CY_IP_MXS40SRSS) && \
    (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0))

#if defined(__cplusplus)
extern "C" {
#endif

//--------------------------------------------------------------------------------------------------
// mtb_hal_lptimer_set_delay
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_lptimer_set_delay(mtb_hal_lptimer_t* obj, uint32_t delay)
{
    obj->clear_int_mask = true;
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER0)
                         || Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER1)
                         || Cy_MCWDT_GetEnabledStatus(obj->base,
                                                      CY_MCWDT_COUNTER2),
                         MTB_HAL_LPTIMER_RSLT_ERR_DISABLED);
    #else
    if ((Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER0) == 0UL)
        || (Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER1) == 0UL)
        || (Cy_MCWDT_GetEnabledStatus(obj->base, CY_MCWDT_COUNTER2) == 0UL))
    {
        return MTB_HAL_LPTIMER_RSLT_ERR_DISABLED;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    /**
     * - 16 bit Counter0 (C0) & Counter1 (C1) are cascaded to generated a 32 bit counter.
     * - Counter2 (C2) is a free running counter.
     * - C0 continues counting after reaching its match value.
     * - An interrupt is generated when C1 increments past the match value.
     *
     * EXAMPLE:
     * Supposed T=C0=C1=0, and we need to trigger an interrupt at T=0x18000.
     * We set C0_match to 0x8000 and C1 match to 1.
     * At T = 0x8000, C0_value matches C0_match so C1 get incremented. C1/C0=0x18000.
     * At T = 0x18000, C0_value matches C0_match again so C1 get incremented from 1 to 2.
     * When C1 get incremented from 1 to 2 the interrupt is generated.
     * At T = 0x18000, C1/C0 = 0x28000.
     */

    if (delay <= _MTB_HAL_LPTIMER_MIN_DELAY)
    {
        delay = _MTB_HAL_LPTIMER_MIN_DELAY;
    }
    if (delay > _MTB_HAL_LPTIMER_MAX_DELAY_TICKS)
    {
        delay = _MTB_HAL_LPTIMER_MAX_DELAY_TICKS;
    }

    Cy_MCWDT_ClearInterrupt(obj->base, CY_MCWDT_CTR1);
    uint16_t c0_old_match = (uint16_t)Cy_MCWDT_GetMatch(obj->base, CY_MCWDT_COUNTER0);

    uint32_t critical_section = Cy_SysLib_EnterCriticalSection();

    /* Cascading from C0 match into C1 is queued and can take 1 full LF clk cycle.
     * There are 3 cases:
     * Case 1: if c0 = match0 then the cascade into C1 will happen 1 cycle from now. The value
     * c1_current_ticks is 1 lower than expected.
     * Case 2: if c0 = match0 -1 then cascade may or not happen before new match value would occur.
     * Match occurs on rising clock edge.
     *          Synchronizing match value occurs on falling edge. Wait until c0 = match0 to ensure
     * cascade occurs.
     * Case 3: everything works as expected.
     *
     * Note: timeout is needed here just in case the LFCLK source gives out. This avoids device
     * lockup.
     *
     * ((2 * Cycles_LFClk) / Cycles_cpu_iteration) * (HFCLk_max / LFClk_min) = Iterations_required
     * Typical case: (2 / 100) * ((150x10^6)/33576) = 89 iterations
     * Worst case: (2 / 100) * ((150x10^6)/1) = 3x10^6 iterations
     * Compromise: (2 / 100) * ((150x10^6)/0xFFFF iterations) = 45 Hz = LFClk_min
     */
    const uint32_t DEFAULT_TIMEOUT = 0xFFFFUL;
    uint32_t timeout = DEFAULT_TIMEOUT;
    uint16_t c0_current_ticks = (uint16_t)Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER0);
    // Wait until the cascade has definitively happened. It takes a clock cycle for the cascade to
    // happen, and potentially another a full
    // LFCLK clock cycle for the cascade to propagate up to the HFCLK-domain registers that the CPU
    // reads.
    while (((((uint16_t)(c0_old_match - 1)) == c0_current_ticks) ||
            (c0_old_match == c0_current_ticks) ||
            (((uint16_t)(c0_old_match + 1)) == c0_current_ticks)) && (timeout != 0UL))
    {
        c0_current_ticks = (uint16_t)Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER0);
        timeout--;
    }
    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(timeout != 0, MTB_HAL_LPTIMER_RSLT_ERR_DISABLED);
    #else
    if (timeout == 0UL)
    {
        // Timeout has occurred. There could have been a clock failure while waiting for the count
        // value to update.
        Cy_SysLib_ExitCriticalSection(critical_section);
        return MTB_HAL_LPTIMER_RSLT_ERR_DISABLED;
    }
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)

    uint16_t c0_match = (uint16_t)(c0_current_ticks + delay);
    // Changes can take up to 2 clk_lf cycles to propagate. If we set the match within this window
    // of the current value, then it is nondeterministic whether the first cascade will trigger
    // immediately or after 2^16 cycles. Wait until c0 is in a more predictable state.
    timeout = DEFAULT_TIMEOUT;
    uint16_t c0_new_ticks = c0_current_ticks;
    while (((c0_new_ticks == c0_match) ||
            (c0_new_ticks == ((uint16_t)(c0_match + 1))) ||
            (c0_new_ticks == ((uint16_t)(c0_match + 2))))
           && (timeout != 0UL))
    {
        c0_new_ticks = (uint16_t)Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER0);
        timeout--;
    }

    delay -= (c0_new_ticks >= c0_current_ticks)
        ? (uint32_t)(c0_new_ticks - c0_current_ticks)
        : (uint32_t)((0xFFFFU - c0_current_ticks) + c0_new_ticks);

    c0_match = (uint16_t)(c0_current_ticks + delay);
    uint16_t c1_current_ticks = (uint16_t)Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER1);
    uint16_t c1_match = (uint16_t)(c1_current_ticks + (delay >> 16));

    // Adjust for rollover
    _mtb_hal_lptimer_set_delay_rollover(&c0_match, &c1_match);

    Cy_MCWDT_SetMatch(obj->base, CY_MCWDT_COUNTER0, c0_match, _MTB_HAL_LPTIMER_SETMATCH_TIME_US);
    Cy_MCWDT_SetMatch(obj->base, CY_MCWDT_COUNTER1, c1_match, _MTB_HAL_LPTIMER_SETMATCH_TIME_US);
    Cy_SysLib_ExitCriticalSection(critical_section);
    _mtb_hal_lptimer_set_delay_enable(obj);

    return CY_RSLT_SUCCESS;
}


#if defined(__cplusplus)
}
#endif

#endif \
    /* (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && (defined(CY_IP_M0S8WCO) ||
       ((defined(CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION < 2)) ||
       ((SRSS_NUM_MCWDT_B) == 0)) ||
       defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) ||
       defined(CY_IP_MXS22SRSS)) */

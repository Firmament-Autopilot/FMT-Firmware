/***************************************************************************//**
* \file mtb_hal_lptimer_mcwdt_resources.h
*
* \brief
* Provides common API declarations of the mcwdt driver when using all three
* MCWDT counters to implement LPTimer
*
********************************************************************************
* \copyright
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
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

/**
 * \addtogroup group_hal_impl_lptimer LPTimer (Low-Power Timer)
 * \ingroup group_hal_impl
 * \{
 *
 * The maximum number of ticks that can set to an LPTimer is 0xFFF0FFFF.  It is not recommended
 * to use 0xFFFFFFFF. This is to avoid overflowing both C0 and C1.
 *
 * \} group_hal_impl_lptimer
 */

#pragma once

#include "mtb_hal_lptimer.h"
#include <stdlib.h>
#include "cy_pdl.h"
#include "cy_mcwdt.h"


#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */

#if defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) || \
    defined(CY_IP_MXS22SRSS)

/*******************************************************************************
*                           Defines
*******************************************************************************/

/* ~36hours, Not set to 0xffffffff to avoid C0 and C1 both overflowing */
#define _MTB_HAL_LPTIMER_MAX_DELAY_TICKS                (0xfff0ffffUL)

/* Minimum amount of lfclk cycles that LPTIMER can delay for. */
#define _MTB_HAL_LPTIMER_MIN_DELAY                      (3U)

/* MCWDT Counter instances to clear during mtb_hal_lptimer_process_interrupt */
#define _MTB_HAL_LPTIMER_PROCESS_CLR_INTR_CNTR          \
    (CY_MCWDT_CTR0 | CY_MCWDT_CTR1 | CY_MCWDT_CTR2)

/* MCWDT Counter instances to use for LPTimer */
#define _MTB_HAL_LPTIMER_CNTR                           (CY_MCWDT_CTR1)

/*******************************************************************************
*                           Typedefs
*******************************************************************************/


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/


/*******************************************************************************
*                        Inlined Functions
*******************************************************************************/
//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_setup
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_lptimer_setup(mtb_hal_lptimer_t* obj)
{
    /* This IP needs no further configuration */
    CY_UNUSED_PARAMETER(obj);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_lptimer_read
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE uint32_t _mtb_hal_lptimer_read(const mtb_hal_lptimer_t* obj)
{
    return Cy_MCWDT_GetCount(obj->base, CY_MCWDT_COUNTER2);
}


#endif \
    /* defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS) || defined(CY_IP_MXS28SRSS) ||
       defined(CY_IP_MXS22SRSS) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

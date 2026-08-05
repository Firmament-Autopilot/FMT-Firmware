/***************************************************************************//**
* \file mtb_hal_hw_types_lptimer_mcwdt.h
*
*********************************************************************************
* \copyright
* Copyright(c) 2024-2025 Infineon Technologies AG or an affiliate of
* Infineon Technologies AG
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

#pragma once

#include "cy_pdl.h"

#if (defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS)) \
    && ((SRSS_NUM_MCWDT) > 0)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
/** Macro specifying whether the LPTimer driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_LPTIMER (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_LPTIMER)

/** \} group_hal_availability */


#if (defined (CY_IP_MXS40SRSS) && (CY_IP_MXS40SRSS_VERSION >= 2)) || ((SRSS_NUM_MCWDT_B) > 0)
#define _MTB_HAL_LPTIMER_MCWDT_B
#else
#define _MTB_HAL_LPTIMER_MCWDT_A
#endif

#define MTB_HAL_LPTIMER_CFG_LFCLK_FREQ

/**
 * @brief LPTIMER object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between platforms and/or HAL releases.
 */
typedef struct
{
    #if defined(_MTB_HAL_LPTIMER_MCWDT_B)
    MCWDT_Type*                         base;
    cy_en_mcwdtctr_t                    counter;
    volatile uint32_t                   final_time;
    #else // MCWDT A
    MCWDT_STRUCT_Type*                  base;
    #endif
    #if (defined(CY_IP_MXS22SRSS) && (SRSS_NUM_MCWDT == 1) && (SRSS_WDT_A_PRESENT == 0))
    volatile uint32_t                   offset;
    #endif /* (defined(CY_IP_MXS22SRSS) && (SRSS_NUM_MCWDT == 1) && (SRSS_WDT_A_PRESENT == 0)) */
    uint32_t                            lfclk_freqhz;
    _mtb_hal_event_callback_data_t      callback_data;
    bool                                clear_int_mask;
    uint8_t                             isr_instruction;
} mtb_hal_lptimer_t;

/**
 * @brief Lptimer configurator struct
 *
 * This struct allows a configurator to provide block configuration information
 * to the HAL. Because configurator-generated configurations are platform
 * specific, the contents of this struct is subject to change between platforms
 * and/or HAL releases.
 */
typedef struct
{
    #if defined(_MTB_HAL_LPTIMER_MCWDT_B)
    MCWDT_Type*                         base;
    #else // MCWDT A
    MCWDT_STRUCT_Type*                  base;
    #endif
    uint32_t                            lfclk_freqhz;
} mtb_hal_lptimer_configurator_t;
#endif // if (defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS40SRSS) || defined (CY_IP_MXS22SRSS))
// && ((SRSS_NUM_MCWDT) > 0)

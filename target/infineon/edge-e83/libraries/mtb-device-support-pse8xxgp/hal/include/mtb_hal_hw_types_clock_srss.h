/***************************************************************************//**
* \file mtb_hal_hw_types_clock_srss.h
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

#if defined(CY_IP_MXS22SRSS) || defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS)

 /**
 * \ingroup group_hal_availability
 * \{
 */

#if !defined(MTB_HAL_DRIVER_AVAILABLE_CLOCK)
/** Macro specifying whether the Clock driver is available for the current device */
#define MTB_HAL_DRIVER_AVAILABLE_CLOCK (1u)
#endif // !defined(MTB_HAL_DRIVER_AVAILABLE_CLOCK)

/** \} group_hal_availability */


/** Clock Reference Structure in case of peri divider */
typedef struct
{
    en_clk_dst_t          clk_dst;  /**< PDL uses the target IP to identify the peri group */
    cy_en_divider_types_t div_type; /**< Clock divider type */
    uint32_t              div_num;  /**< Clock divider number */
} mtb_hal_peri_div_t;

/** Clock Reference Structure in case of high frequency divider */
typedef struct
{
    uint32_t              inst_num;  /**< Clock number */
} mtb_hal_hf_clock_t;

/** Get the clock frequency */
typedef uint32_t (* mtb_hal_clock_get_frequency_hz_t)(const void* clock_ref);
/** Set the clock frequency */
typedef cy_rslt_t (* mtb_hal_clock_set_frequency_hz_t)(const void* clock_ref,
                                                       uint32_t desired_frequency_hz,
                                                       uint32_t tolerance_ppm);
/** Enable or Disable the clock */
typedef cy_rslt_t (* mtb_hal_clock_set_enabled_t)(const void* clock_ref, bool enabled);

/** Clock Interface structure for clocks */
typedef struct
{
    mtb_hal_clock_get_frequency_hz_t get_frequency_hz; /**< Get the clock frequency */
    mtb_hal_clock_set_frequency_hz_t set_frequency_hz; /**< Set the clock frequency */
    mtb_hal_clock_set_enabled_t      set_enabled;      /**< Enable or Disable the clock */
} mtb_hal_clock_interface_t;


/** @brief Clock object
 * Application shall provide implementations for the functions needed by the clock
 * object. They are considered an implementation detail which is subject to change
 * between platforms and/or devices. */
typedef struct
{
    /** Pointer that is passed to all interface functions. In a typical case, this points to
     * an instance of either mtb_hal_peri_div_t or mtb_hal_hf_clock_t */
    const void*                          clock_ref;
    /** Struct of interface functions that should be used with this clock */
    const mtb_hal_clock_interface_t*     interface;
} mtb_hal_clock_t;

#endif // defined(CY_IP_MXS22SRSS) || defined(CY_IP_MXS40SRSS) || defined(CY_IP_MXS40SSRSS)

/***************************************************************************//**
* \file mtb_hal_rtc.h
*
* \brief
* Provides a high level interface for interacting with the Real Time Clock on
* Cypress devices.  This interface abstracts out the chip specific details.
* If any chip specific functionality is necessary, or performance is critical
* the low level functions can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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
//" *SUSPEND-FORMATTING*"
/**
 * \addtogroup group_hal_rtc RTC (Real-Time Clock)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the real-time clock (RTC).
 *
 * The real time clock provides tracking of the current time and date, as
 * well as the ability to trigger a callback at a specific time in the future.
 *
 * \section section_rtc_features Features
 * * Read current time
 * * Write current time
 *
 * \section section_rtc_quickstart Quick Start
 *
 * Initialise the RTC using the PDL. Set the current time and date using \ref mtb_hal_rtc_write.
 * <br>
 * See \ref subsection_rtc_snippet_1 to initialize RTC, read and write current date and time to the
 * RTC peripheral.
 *
 * \section section_rtc_snippets Code snippets
 * \subsection subsection_rtc_snippet_1 Snippet 1: Initialize RTC, write and read current time and date
 * The following code sets the current date and time using \ref mtb_hal_rtc_write.
 * The current date and time is read from the RTC using \ref mtb_hal_rtc_read. The time structure
 * <b> tm </b>, contains the calendar date and time which
 * are broken down into its components. This structure is declared in standard C library time.h
 * which is included by HAL.
 * \snippet hal_rtc.c snippet_mtb_hal_rtc_read_write_data_time
 *
 */
//" *RESUME-FORMATTING*"
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_RTC)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_rtc RTC HAL Results
 *  RTC specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Bad argument */
#define MTB_HAL_RTC_RSLT_BAD_ARGUMENT                        \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_RTC, 0))
/** Unsupported feature */
#define MTB_HAL_RTC_RSLT_ERR_NOT_SUPPORTED      \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_RTC, 1))


/**
 * \}
 */

/*******************************************************************************
*       Typedefs
*******************************************************************************/

/** Get the current time and date from the RTC peripheral
 *
 * @param[in]  obj RTC object
 * @param[out] time The current time (see: https://en.cppreference.com/w/cpp/chrono/c/tm)
 * @return The status of the read request
 */
cy_rslt_t mtb_hal_rtc_read(mtb_hal_rtc_t* obj, struct tm* time);

/** Write the specified time and date to the RTC peripheral
 *
 * @param[in] obj  RTC object
 * @param[in] time The time to be set (see: https://en.cppreference.com/w/cpp/chrono/c/tm).
 * Specify the local time to set to the RTC.
 * @return The status of the write request
 */
cy_rslt_t mtb_hal_rtc_write(mtb_hal_rtc_t* obj, const struct tm* time);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_RTC_IMPL_HEADER
#include MTB_HAL_RTC_IMPL_HEADER
#endif /* MTB_HAL_RTC_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_RTC)

/** \} group_hal_rtc */

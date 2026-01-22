/***************************************************************************//**
* \file mtb_hal_general_types.h
*
* \brief
* Provides basic types that are used across different HAL drivers.
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

/**
 * \addtogroup group_hal_general_types General Types
 * \ingroup group_hal_types
 * \{
 * This section documents the basic types that are used by multiple HAL drivers.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * \addtogroup group_hal_results Result Codes
 * \ingroup group_hal_types
 * \{
 * HAL specific return codes definitions for all drivers. HAL drivers are generally
 * built on top of a lower level driver. In this case the errors returned from the
 * HAL could be one of the values below or a value from that lower level driver.
 * See the device specific documentation for details about the other error codes.
 * The HAL uses the same \ref CY_RSLT_CREATE macro to define result codes using
 * the standard \ref cy_rslt_t format. All HAL results use the module ID \ref
 * CY_RSLT_MODULE_ABSTRACTION_HAL. Driver distinction is done as part of the 16-bit
 * code field. The HAL splits this into individual bytes. The upper byte signifies
 * the HAL driver using values from the \ref mtb_hal_rslt_module_chip enum. The lower
 * byte is defined by each HAL driver.
 */


/**
 * Enum to specify module IDs for \ref cy_rslt_t values returned from the HAL.
 */
enum mtb_hal_rslt_module_chip
{
    MTB_HAL_RSLT_MODULE_ADC           = (0x01),  //!< An error occurred in ADC module
    MTB_HAL_RSLT_MODULE_CLOCK         = (0x02),  //!< An error occurred in Clock module
    MTB_HAL_RSLT_MODULE_COMP          = (0x03),  //!< An error occurred in comparator module
    MTB_HAL_RSLT_MODULE_CORDIC        = (0x04),  //!< An error occurred in CORDIC module
    MTB_HAL_RSLT_MODULE_DMA           = (0x05),  //!< An error occurred in DMA module
    MTB_HAL_RSLT_MODULE_GPIO          = (0x06),  //!< An error occurred in GPIO module
    MTB_HAL_RSLT_MODULE_I2C           = (0x07),  //!< An error occurred in I2C module
    MTB_HAL_RSLT_MODULE_IPC           = (0x08),  //!< An error occurred in IPC module
                                                 //!< module
    MTB_HAL_RSLT_MODULE_LPTIMER       = (0x09),  //!< An error occurred in LPTimer module
    MTB_HAL_RSLT_MODULE_MEMORYSPI     = (0x0A),  //!< An error occurred in MEMORYSPI module
    MTB_HAL_RSLT_MODULE_NPNZ          = (0x0B),  //!< An error occurred in Filter module
    MTB_HAL_RSLT_MODULE_NVM           = (0x0C),  //!< An error occurred in NVM module
    MTB_HAL_RSLT_MODULE_PWM           = (0x0D),  //!< An error occurred in PWM module
    MTB_HAL_RSLT_MODULE_RTC           = (0x0E),  //!< An error occurred in RTC module
    MTB_HAL_RSLT_MODULE_SDHC          = (0x0F),  //!< An error occurred in SDHC module
    MTB_HAL_RSLT_MODULE_SDIO          = (0x10),  //!< An error occurred in SDIO module
    MTB_HAL_RSLT_MODULE_SPI           = (0x11),  //!< An error occurred in SPI module
    MTB_HAL_RSLT_MODULE_SYSPM         = (0x12),  //!< An error occurred in SysPM module
    MTB_HAL_RSLT_MODULE_SYSTEM        = (0x13),  //!< An error occurred in System module
    MTB_HAL_RSLT_MODULE_TIMER         = (0x14),  //!< An error occurred in Timer module
    MTB_HAL_RSLT_MODULE_TRNG          = (0x15),  //!< An error occurred in TRNG module
    MTB_HAL_RSLT_MODULE_UART          = (0x16)   //!< An error occurred in UART module
};

/**
 * \} group_hal_results
 */

#if defined(__cplusplus)
}
#endif

/** \} group_hal_general_types */

/***************************************************************************//**
* \file mtb_hal_nvm_impl.h
*
* Description:
* Provides a high level interface for interacting with the Infineon NVM. This is
* a wrapper around the lower level PDL API.
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

#pragma once

#include "mtb_hal_nvm.h"
#include "cy_utils.h"
#include <string.h>

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */


/*******************************************************************************
*       Defines
*******************************************************************************/

#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)

typedef cy_en_flashdrv_status_t (* _mtb_hal_flash_operation)(uint32_t rowAddr,
                                                             const uint32_t* data);

#if defined(CPUSS_FLASHC_ECT)
#define _MTB_HAL_USES_ECT_FLASH (CPUSS_FLASHC_ECT == 1)
#if defined(CY_IP_M4CPUSS) && (CY_IP_M4CPUSS_VERSION == 2)
#include "mtb_hal_nvm_m4cpuss_ver2.h"
#else
#include "mtb_hal_nvm_m7cpuss_v1.h"
#endif /* defined(CY_IP_M4CPUSS) && (CY_IP_M4CPUSS_VERSION == 2) */
#else
#define _MTB_HAL_USES_ECT_FLASH (0u)
#include "mtb_hal_nvm_mxs40flashc_v1.h"
#endif /* defined(CPUSS_FLASHC_ECT) */

#if (_MTB_HAL_USES_ECT_FLASH)
#define _MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS (4u)
#elif (CY_EM_EEPROM_SIZE > 0)
#define _MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS (2u)
#else
#define _MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS (1u)
#endif

#endif /* #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) */
#if (CY_IP_MXS22RRAMC == 1)
#include "mtb_hal_nvm_mxs22rramc.h"
#endif /* #if (CY_IP_MXS22RRAMC == 1) */

/* Some devices only support one type of memory.  If so, we can skip all the unsupported code */
#if ((_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) && !(_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) && \
    !(_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM))
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH (1)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP   (0)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM  (0)
#elif (!(_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) && (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) && \
    !(_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM))
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH (0)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP   (1)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM  (0)
#elif (!(_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) && !(_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) && \
    (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM))
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH (0)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP   (0)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM  (1)
#else // if ((_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) && !(_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) &&
// !(_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM))
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH (0)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP   (0)
#define _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM  (0)
#endif // if ((_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) && !(_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) &&
// !(_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM))

#ifndef _MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS
#define _MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS     (0)
#endif /* (_MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS) */

#ifndef _MTB_HAL_INTERNAL_RRAM_MEMORY_BLOCKS
#define _MTB_HAL_INTERNAL_RRAM_MEMORY_BLOCKS      (0)
#endif /* (_MTB_HAL_INTERNAL_RRAM_MEMORY_BLOCKS) */

#ifndef _MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS
#define _MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS       (0)
#endif /* (_MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS) */


/*******************************************************************************
*       Functions
*******************************************************************************/

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj   The HAL driver instance object. The caller must allocate the
 *                   memory for this object, but the HAL will initialize its contents
 * @param[in] config The configurator-generated HAL config structure for this
 *                   peripheral instance
 * @return the status of the HAL setup
 */
__STATIC_INLINE cy_rslt_t mtb_hal_nvm_setup(mtb_hal_nvm_t* obj,
                                            const mtb_hal_nvm_configurator_t* config)
{
    CY_UNUSED_PARAMETER(obj);
    CY_UNUSED_PARAMETER(config);
    // This HAL implementation does not need to initialize any state
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_flash_get_mem_region_count
//--------------------------------------------------------------------------------------------------
uint8_t _mtb_hal_flash_get_mem_region_count(void);

//--------------------------------------------------------------------------------------------------
// _mtb_hal_flash_get_mem_region
//--------------------------------------------------------------------------------------------------
const mtb_hal_nvm_region_info_t* _mtb_hal_flash_get_mem_region(void);


#if defined(__cplusplus)
}
#endif /* __cplusplus */

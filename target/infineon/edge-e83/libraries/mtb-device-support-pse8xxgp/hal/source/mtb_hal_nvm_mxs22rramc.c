/***************************************************************************//**
* File Name: mtb_hal_nvm_mxs22rramc.c
*
* Description:
* Provides a high level interface for interacting with the Infineon embedded
* non-volatile memory (NVM). This is wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2018-2024 Cypress Semiconductor Corporation (an Infineon company) or
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
 * \addtogroup group_hal_impl_nvm NVM (Onboard Non-Volatile Memory)
 * \ingroup group_hal_impl
 * \{
 * On PSE84 the OTP region is accessible in Secure mode.
 *  That's why NVM APIs which working with OTP memory available only in Secure mode.
 *
 * \} group_hal_impl_nvm
 */

#include "mtb_hal_nvm_impl.h"
#include "mtb_hal_utils_impl.h"


#if (MTB_HAL_DRIVER_AVAILABLE_NVM)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#define _MTB_HAL_NVM_MEMORY_BLOCKS_COUNT  (_MTB_HAL_INTERNAL_FLASH_MEMORY_BLOCKS + \
                                         _MTB_HAL_INTERNAL_RRAM_MEMORY_BLOCKS + \
                                         _MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS)

static const mtb_hal_nvm_region_info_t _mtb_hal_nvm_mem_regions[_MTB_HAL_NVM_MEMORY_BLOCKS_COUNT] =
{
    #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
    #if (CY_RRAM_MAIN_REGION_SIZE > 0)
    // Main RRAM region, 8KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_RRAM,
        .start_address =
            #if defined(_MTB_HAL_IMAGE_TYPE_SECURE)
            CY_RRAM_MAIN_HOST_S_START_ADDRESS,
            #else
            CY_RRAM_MAIN_HOST_NS_START_ADDRESS,
        #endif
        .size = CY_RRAM_MAIN_REGION_SIZE,
        .sector_size = CY_RRAM_SECTOR_SIZE_KB * 1024,
        .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
        .is_erase_required = false,
        .erase_value = 0x00U,
    },
    #endif /* (CY_RRAM_MAIN_REGION_SIZE > 0) */
    #if (CY_RRAM_WORK_REGION_SIZE > 0)
    // Work RRAM region, 8KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_RRAM,
        .start_address =
            #if defined(_MTB_HAL_IMAGE_TYPE_SECURE)
            CY_RRAM_WORK_HOST_S_START_ADDRESS,
            #else
            CY_RRAM_WORK_HOST_NS_START_ADDRESS,
        #endif
        .size = CY_RRAM_WORK_REGION_SIZE,
        .sector_size = CY_RRAM_SECTOR_SIZE_KB * 1024,
        .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
        .is_erase_required = false,
        .erase_value = 0x00U,
    },
    #endif /* (CY_RRAM_WORK_REGION_SIZE > 0) */
    #if (CY_RRAM_SFLASH_REGION_SIZE > 0)
    // SFALSH RRAM region, 8KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_RRAM,
        .start_address =
            #if defined(_MTB_HAL_IMAGE_TYPE_SECURE)
            CY_RRAM_SFLASH_HOST_S_START_ADDRESS,
            #else
            CY_RRAM_SFLASH_HOST_NS_START_ADDRESS,
        #endif
        .size = CY_RRAM_SFLASH_REGION_SIZE,
        .sector_size = CY_RRAM_SECTOR_SIZE_KB * 1024,
        .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
        .is_erase_required = false,
        .erase_value = 0x00U,
    },
    #endif /* (CY_RRAM_SFLASH_REGION_SIZE > 0) */
    #if (CY_RRAM_PROTECTED_REGION_SIZE > 0)
    // SFALSH RRAM region, 8KB sectors
    {
        .nvm_type = MTB_HAL_NVM_TYPE_RRAM,
        .start_address =
            #if defined(_MTB_HAL_IMAGE_TYPE_SECURE)
            CY_RRAM_PROTECTED_HOST_S_START_ADDRESS,
            #else
            CY_RRAM_PROTECTED_HOST_NS_START_ADDRESS,
        #endif
        .size = CY_RRAM_PROTECTED_REGION_SIZE,
        .sector_size = CY_RRAM_SECTOR_SIZE_KB * 1024,
        .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
        .is_erase_required = false,
        .erase_value = 0x00U,
    },
    #endif /* (CY_RRAM_PROTECTED_REGION_SIZE > 0) */
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM) */

    #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
    #if (CY_RRAM_GENERAL_OTP_SIZE > 0)
    // General RRAM OTP region, 5.5KB sector
    {
        .nvm_type = MTB_HAL_NVM_TYPE_OTP,
        .start_address =
            #if defined(_MTB_HAL_IMAGE_TYPE_SECURE)
            CY_RRAM_GENERAL_OTP_MMIO_S_START_ADDRESS,
            #else
            CY_RRAM_GENERAL_OTP_MMIO_NS_START_ADDRESS,
        #endif
        .size = CY_RRAM_GENERAL_OTP_SIZE,
        .sector_size = CY_RRAM_GENERAL_OTP_SIZE,
        .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
        .is_erase_required = false,
        .erase_value = 0xFFU,
    },
    #endif /* (CY_RRAM_GENERAL_OTP_SIZE > 0) */
    #if (CY_RRAM_PROTECTED_OTP_SIZE > 0)
    // Protected RRAM OTP region, 8KB sector
    {
        .nvm_type = MTB_HAL_NVM_TYPE_OTP,
        .start_address =
            #if defined(_MTB_HAL_IMAGE_TYPE_SECURE)
            CY_RRAM_PROTECTED_OTP_PROTECTED_S_START_ADDRESS,
            #else
            CY_RRAM_PROTECTED_OTP_PROTECTED_NS_START_ADDRESS,
        #endif
        .size = CY_RRAM_PROTECTED_OTP_SIZE,
        .sector_size = CY_RRAM_SECTOR_SIZE_KB * 1024,
        .block_size = CY_RRAM_BLOCK_SIZE_BYTES,
        .is_erase_required = false,
        .erase_value = 0xFFU,
    },
    #endif /* (CY_RRAM_PROTECTED_OTP_SIZE > 0) */
    #endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) */
};

/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_flash_get_mem_region_count
//--------------------------------------------------------------------------------------------------
uint8_t _mtb_hal_flash_get_mem_region_count(void)
{
    return _MTB_HAL_NVM_MEMORY_BLOCKS_COUNT;
}


//--------------------------------------------------------------------------------------------------
// _mtb_hal_flash_get_mem_region
//--------------------------------------------------------------------------------------------------
const mtb_hal_nvm_region_info_t* _mtb_hal_flash_get_mem_region(void)
{
    return &_mtb_hal_nvm_mem_regions[0];
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* (MTB_HAL_DRIVER_AVAILABLE_NVM) */

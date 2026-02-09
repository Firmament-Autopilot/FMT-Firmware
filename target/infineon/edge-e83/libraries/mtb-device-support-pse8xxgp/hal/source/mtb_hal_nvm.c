/***************************************************************************//**
* File Name: mtb_hal_nvm.c
*
* Description:
* Provides a high level interface for interacting with the Infineon embedded
* non-volatile memory (NVM). This is wrapper around the lower level PDL API.
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


#include "mtb_hal_nvm_impl.h"
#include <string.h>


#if (MTB_HAL_DRIVER_AVAILABLE_NVM)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// mtb_hal_nvm_get_info
//--------------------------------------------------------------------------------------------------
void mtb_hal_nvm_get_info(mtb_hal_nvm_t* obj, mtb_hal_nvm_info_t* info)
{
    CY_ASSERT(NULL != obj);
    CY_ASSERT(NULL != info);
    CY_UNUSED_PARAMETER(obj);

    info->region_count = _mtb_hal_flash_get_mem_region_count();
    info->regions = _mtb_hal_flash_get_mem_region();
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_nvm_read
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_nvm_read(mtb_hal_nvm_t* obj, uint32_t address, uint8_t* data, size_t size)
{
    CY_ASSERT(NULL != obj);

    const mtb_hal_nvm_region_info_t* _mtb_hal_nvm_current_block_info;
    cy_rslt_t status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    _mtb_hal_nvm_current_block_info = mtb_hal_nvm_get_region_for_address(obj, address, size);

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != _mtb_hal_nvm_current_block_info, MTB_HAL_NVM_RSLT_ERR_ADDRESS);
    #else
    if (NULL == _mtb_hal_nvm_current_block_info)
    {
        status = MTB_HAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        #if (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH)
        status = _mtb_hal_nvm_read_helper_flash(address, data, size);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM)
        status = _mtb_hal_nvm_read_helper_rram(address, data, size);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP)
        status = _mtb_hal_nvm_read_helper_otp(address, data, size);
        #else
        if (MTB_HAL_NVM_TYPE_FLASH == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _mtb_hal_nvm_read_helper_flash(address, data, size);
            #endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (MTB_HAL_NVM_TYPE_RRAM == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = _mtb_hal_nvm_read_helper_rram(address, data, size);
            #endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM) */
        }
        else if (MTB_HAL_NVM_TYPE_OTP == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
            status = _mtb_hal_nvm_read_helper_otp(address, data, size);
            #endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) */
        }
        else
        {
            /* Not supported type of NVM */
            status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        #endif /* Not _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH, _RRAM, or _OTP */
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_nvm_erase
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_nvm_erase(mtb_hal_nvm_t* obj, uint32_t address)
{
    CY_ASSERT(NULL != obj);

    const mtb_hal_nvm_region_info_t* _mtb_hal_nvm_current_block_info;
    cy_rslt_t status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    _mtb_hal_nvm_current_block_info = mtb_hal_nvm_get_region_for_address(obj, address, 0);

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != _mtb_hal_nvm_current_block_info, MTB_HAL_NVM_RSLT_ERR_ADDRESS);
    #else
    if (NULL == _mtb_hal_nvm_current_block_info)
    {
        status = MTB_HAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        #if (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH)
        status = _mtb_hal_nvm_erase_helper_flash(address);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM)
        status = _mtb_hal_nvm_erase_helper_rram();
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP)
        status = _mtb_hal_nvm_erase_helper_otp();
        #else
        if (MTB_HAL_NVM_TYPE_FLASH == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _mtb_hal_nvm_erase_helper_flash(address);
            #endif /* #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (MTB_HAL_NVM_TYPE_RRAM == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
            status = _mtb_hal_nvm_erase_helper_rram();
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM */
        }
        else if (MTB_HAL_NVM_TYPE_OTP == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
            status = _mtb_hal_nvm_erase_helper_otp();
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_OTP */
        }
        else
        {
            /* Not supported type of NVM */
            status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        #endif /* Not _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH, _RRAM, or _OTP */
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_nvm_write
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_nvm_write(mtb_hal_nvm_t* obj, uint32_t address, const uint32_t* data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    const mtb_hal_nvm_region_info_t* _mtb_hal_nvm_current_block_info;
    cy_rslt_t status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    _mtb_hal_nvm_current_block_info = mtb_hal_nvm_get_region_for_address(obj, address, 0);

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != _mtb_hal_nvm_current_block_info, MTB_HAL_NVM_RSLT_ERR_ADDRESS);
    #else
    if (NULL == _mtb_hal_nvm_current_block_info)
    {
        status = MTB_HAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        #if (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH)
        status = _mtb_hal_nvm_write_helper_flash(address, data);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM)
        status = _mtb_hal_nvm_write_helper_rram(address, data);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP)
        status = _mtb_hal_nvm_write_helper_otp();
        #else
        if (MTB_HAL_NVM_TYPE_FLASH == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _mtb_hal_nvm_write_helper_flash(address, data);
            #endif /* #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH) */
        }
        else if (MTB_HAL_NVM_TYPE_RRAM == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
            #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
            SCB_CleanDCache_by_Addr((void*)data, _mtb_hal_nvm_current_block_info->block_size);
            #endif
            status = _mtb_hal_nvm_write_helper_rram(address, data);
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM */
        }
        else if (MTB_HAL_NVM_TYPE_OTP == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
            status = _mtb_hal_nvm_write_helper_otp();
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_OTP */
        }
        else
        {
            /* Not supported type of NVM */
            status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        #endif /* Not _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH, _RRAM, or _OTP */
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_nvm_program
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_hal_nvm_program(mtb_hal_nvm_t* obj, uint32_t address, const uint32_t* data)
{
    CY_ASSERT(NULL != obj);
    CY_UNUSED_PARAMETER(obj);

    const mtb_hal_nvm_region_info_t* _mtb_hal_nvm_current_block_info;
    cy_rslt_t status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;

    _mtb_hal_nvm_current_block_info = mtb_hal_nvm_get_region_for_address(obj, address, 0);

    #if defined(MTB_HAL_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(NULL != _mtb_hal_nvm_current_block_info, MTB_HAL_NVM_RSLT_ERR_ADDRESS);
    #else
    if (NULL == _mtb_hal_nvm_current_block_info)
    {
        status = MTB_HAL_NVM_RSLT_ERR_ADDRESS;
    }
    else
    #endif // defined(MTB_HAL_DISABLE_ERR_CHECK)
    {
        #if (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH)
        status = _mtb_hal_nvm_program_helper_flash(address, data);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_RRAM)
        status = _mtb_hal_nvm_program_helper_rram(address, data);
        #elif (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_OTP)
        status = _mtb_hal_nvm_program_helper_otp();
        #else // if (_MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH)
        if (MTB_HAL_NVM_TYPE_FLASH == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH)
            status = _mtb_hal_nvm_program_helper_flash(address, data);
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_FLASH */
        }
        else if (MTB_HAL_NVM_TYPE_RRAM == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
            #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
            SCB_CleanDCache_by_Addr((void*)data, _mtb_hal_nvm_current_block_info->block_size);
            #endif
            status = _mtb_hal_nvm_program_helper_rram(address, data);
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM */
        }
        else if (MTB_HAL_NVM_TYPE_OTP == _mtb_hal_nvm_current_block_info->nvm_type)
        {
            #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
            status = _mtb_hal_nvm_program_helper_otp();
            #endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_OTP */
        }
        else
        {
            /* Not supported type of NVM */
            status = MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
        }
        #endif /* Not _MTB_HAL_NVM_SINGLE_MEMORY_TYPE_FLASH, _RRAM, or _OTP */
    }
    return status;
}


//--------------------------------------------------------------------------------------------------
// mtb_hal_nvm_get_region_for_address
//--------------------------------------------------------------------------------------------------
const mtb_hal_nvm_region_info_t* mtb_hal_nvm_get_region_for_address(mtb_hal_nvm_t* obj,
                                                                    uint32_t addr, uint32_t length)
{
    mtb_hal_nvm_info_t nvm_info;
    mtb_hal_nvm_get_info(obj, &nvm_info);

    for (uint32_t region = 0; region < nvm_info.region_count; region++)
    {
        if (((addr >= nvm_info.regions[region].start_address) &&
             (addr < (nvm_info.regions[region].start_address + nvm_info.regions[region].size)) &&
             (addr + length <=
              (nvm_info.regions[region].start_address + nvm_info.regions[region].size)))
            #if defined(CY_FLASH_CBUS_BASE) && defined(SBUS_ALIAS_OFFSET)
            || ((addr >= FLASH_SBUS_ALIAS_ADDRESS(nvm_info.regions[region].start_address)) &&
                (addr < FLASH_SBUS_ALIAS_ADDRESS(nvm_info.regions[region].start_address) +
                 nvm_info.regions[region].size) &&
                (addr + length <=
                 (FLASH_SBUS_ALIAS_ADDRESS(nvm_info.regions[region].start_address) +
                  nvm_info.regions[region].size)))
            #endif
            )
        {
            return &nvm_info.regions[region];
        }
    }

    return NULL;
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* (MTB_HAL_DRIVER_AVAILABLE_NVM) */

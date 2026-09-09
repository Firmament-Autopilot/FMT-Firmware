/***************************************************************************//**
* File Name: mtb_hal_nvm_mxs22rramc.h
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

#include "mtb_hal_hw_types.h"
#include "mtb_hal_nvm.h"
#include "cy_utils.h"
#include "mtb_hal_utils_impl.h"
#include <string.h>


#if (MTB_HAL_DRIVER_AVAILABLE_NVM)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)

#if (CY_RRAM_PROTECTED_OTP_SIZE > 0) && (CY_RRAM_GENERAL_OTP_SIZE > 0)
#define _MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS  (2u)
#else
#define _MTB_HAL_INTERNAL_OTP_MEMORY_BLOCKS  (1u)
#endif

#endif /* #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) */

#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)

typedef enum
{
    #if (CY_RRAM_WORK_REGION_SIZE > 0)
    _MTB_HAL_RRAM_WORK_REGION,
    #endif
    #if (CY_RRAM_SFLASH_REGION_SIZE > 0)
    _MTB_HAL_RRAM_SFLASH_REGION,
    #endif
    #if (CY_RRAM_PROTECTED_REGION_SIZE > 0)
    _MTB_HAL_RRAM_PROTECTED_REGION,
    #endif
    #if (CY_RRAM_MAIN_REGION_SIZE > 0)
    _MTB_HAL_RRAM_MAIN_REGION,
    #endif
    _MTB_HAL_RRAM_REGION_COUNT
} _mtb_hal_rram_regions_count;

#define _MTB_HAL_INTERNAL_RRAM_MEMORY_BLOCKS      (_MTB_HAL_RRAM_REGION_COUNT)

#endif /* #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM) */

#define _MTB_HAL_NVM_SECURE_REGION_MASK           (CY_RRAM_S_OFFSET_MASK)


/*******************************************************************************
*       Functions
*******************************************************************************/

//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_is_operation_complete
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE bool _mtb_hal_nvm_is_operation_complete(void)
{
    bool complete = true;

    #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
    complete = !(Cy_RRAM_IsBusy(RRAMC0));
    #endif /* #if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM) */

    return complete;
}


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_read_helper_rram
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_read_helper_rram(uint32_t address, uint8_t* data,
                                                        size_t size)
{
    return (cy_rslt_t)Cy_RRAM_TSReadByteArray(RRAMC0, address, data, size);
}


#endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM) */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_read_helper_otp
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_read_helper_otp(uint32_t address, uint8_t* data, size_t size)
{
    return (cy_rslt_t)Cy_RRAM_TSReadByteArray(RRAMC0, address, data, size);
}


#endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP) */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_erase_helper_rram
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_erase_helper_rram(void)
{
    /* Erase operation not needed for RRAM */
    return CY_RSLT_SUCCESS;
}


#endif /* (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM) */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_erase_helper_otp
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_erase_helper_otp(void)
{
    /* Not supported for OTP */
    return MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
}


#endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_OTP */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_write_helper_rram
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_write_helper_rram(uint32_t address, const uint32_t* data)
{
    return (cy_rslt_t)Cy_RRAM_NvmWriteBlock(RRAMC0, address, (uint8_t*)data);
}


#endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_write_helper_otp
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_write_helper_otp(void)
{
    /* Not supported for OTP */
    return MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
}


#endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_OTP */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_program_helper_rram
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_program_helper_rram(uint32_t address, const uint32_t* data)
{
    return (cy_rslt_t)Cy_RRAM_NvmWriteBlock(RRAMC0, address, (uint8_t*)data);
}


#endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_RRAM */


#if (_MTB_HAL_DRIVER_AVAILABLE_NVM_OTP)
//--------------------------------------------------------------------------------------------------
// _mtb_hal_nvm_program_helper_otp
//--------------------------------------------------------------------------------------------------
__STATIC_INLINE cy_rslt_t _mtb_hal_nvm_program_helper_otp(void)
{
    /* Not supported for OTP */
    return MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED;
}


#endif /* _MTB_HAL_DRIVER_AVAILABLE_NVM_OTP */


#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* (MTB_HAL_DRIVER_AVAILABLE_NVM) */

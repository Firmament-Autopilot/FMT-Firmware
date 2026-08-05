/***************************************************************************//**
* \file mtb_hal_nvm.h
*
* \brief
* Provides a high level interface for interacting with the Infineon onboard
* NVM(Non-Volatile Memory).
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
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
 * \addtogroup group_hal_nvm NVM (Onboard Non-Volatile Memory)
 * \ingroup group_hal
 * \{
 * High level interface to the onboard Non-Volatile memory (Internal Flash, RRAM, OTP region).
 *
 * Onboard NVM provides non-volatile storage for factory settings, secure data,
 * user firmware, configuration, and bulk data.
 *
 * This driver allows data to be read from and written to NVM. It also provides the
 * ability to obtain information about the address and characteristics of the NVM
 * block(s) contained on the device. During NVM write time, the device should not be
 * reset (including XRES pin, software reset, and watchdog) or unexpected changes may
 * be made to portions of the NVM. Also, the low-voltage detect circuits should be
 * configured to generate an interrupt instead of a reset.
 *
 * \note A Read while Write violation may occur for some devices when a NVM Read
 * operation is initiated in the same or neighboring NVM sector/region where the NVM
 * Write, Erase(if applicable), or Program operation is working. Refer the device datasheet
 * for more information. This violation may cause a HardFault exception. To avoid the
 * Read while Write violation, the user must carefully split the Read and Write
 * operations on NVM sectors/regions which are not neighboring, considering all cores in
 * a multi-processor device. User may edit the linker script to place the code into
 * neighboring sectors/regions. For example, use sectors number 0 and 1 for code and sectors
 * 2 and 3 for data storage.
 *
 * \section hal_nvm_features Features
 * * NVM operations are performed on a per-block (program) or per-sector (erase if applicable) basis
 *   (Refer the device datasheet for more information on the block size)
 * * Supports Blocking or Non-Blocking erase(if applicable), program, and write
 * \section hal_nvm_code_snippet Code Snippets
 * \subsection subsection_nvm_use_case_1 Snippet 1: Get NVM Characteristics
 * Following code snippet demonstrates how to fetch NVM characteristics. Refer \ref
 * mtb_hal_nvm_info_t for more information.
 * \snippet hal_nvm.c snippet_mtb_hal_nvm_get_nvm_info
 *
 * \subsection subsection_nvm_use_case_2 Snippet 2: Blocking NVM Erase-Write and Read
 * Following code snippet demonstrates blocking NVM write.
 * It uses a constant array with a size equaling the size of one NVM row/block.
 * It uses blocking NVM write operation which blocks the caller until the write is
 * completed. It then verifies the NVM data by comparing the NVM data with the
 * written data.
 * \snippet hal_nvm.c snippet_mtb_hal_nvm_blocking_mode_nvmwrite
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "mtb_hal_general_types.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_NVM)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/

/** \addtogroup group_hal_results_nvm NVM HAL Results
 *  NVM specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */
/** Invalid argument */
#define MTB_HAL_NVM_RSLT_ERR_ADDRESS                    \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_NVM, 0))
/** API is not supported */
#define MTB_HAL_NVM_RSLT_ERR_NOT_SUPPORTED              \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_NVM, 1))

/**
 * \}
 */

/** Enum of Non-volatile memory (NVM) types */
typedef enum
{
    MTB_HAL_NVM_TYPE_INVALID = 0U,  //!< Invalid type of NVM
    MTB_HAL_NVM_TYPE_FLASH   = 1U,  //!< Internal Flash
    MTB_HAL_NVM_TYPE_RRAM    = 2U,  //!< RRAM
    MTB_HAL_NVM_TYPE_OTP     = 3U   //!< OTP
} mtb_hal_nvm_type_t;

/** @brief Information about a single region of NVM memory */
typedef struct
{
    mtb_hal_nvm_type_t  nvm_type;              //!< NVM type.
    uint32_t            start_address;         //!< Base address of the distinct NVM region.
    uint32_t            offset;                //!< Offset to the address in the distinct NVM
                                               //!< region.
    uint32_t            size;                  //!< Size of the distinct NVM region.
    uint32_t            sector_size;           //!< Sector size of the distinct NVM region.
    uint32_t            block_size;            //!< Block size (programming granularity) of the
                                               //!< distinct NVM region.
    bool                is_erase_required;     //!< true = erase required before program, false =
                                               //!< erase not required before program.
    uint8_t             erase_value;           //!< NVM erase value (if applicable).
} mtb_hal_nvm_region_info_t;

/** @brief Information about all of the regions of NVM memory */
typedef struct
{
    uint8_t region_count;                     //!< The number of distinct NVM regions.
    const mtb_hal_nvm_region_info_t* regions;   //!< Array of the distinct NVM regions.
} mtb_hal_nvm_info_t;


/*******************************************************************************
*       Functions
*******************************************************************************/

/** Get details about the NVM memory regions such as NVM type, start address, size,
   is_erase_required, and erase values etc.
 * Refer \ref mtb_hal_nvm_info_t, mtb_hal_nvm_region_info_t for more information.
 *
 * @param[in]  obj  The NVM object.
 * @param[out] info The NVM characteristic info.
 *
 * Refer \ref subsection_nvm_use_case_1 for more information.
 */
void mtb_hal_nvm_get_info(mtb_hal_nvm_t* obj, mtb_hal_nvm_info_t* info);

/** Read size amount of data starting from the given address of NVM.
 *
 * @param[in]  obj     The NVM object.
 * @param[in]  address Address to begin reading from.
 * @param[out] data    The buffer to read data into.
 * @param[in]  size    The number of bytes to read.
 * @return The status of the read request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 * Refer \ref subsection_nvm_use_case_2 for more information.
 *
 */
cy_rslt_t mtb_hal_nvm_read(mtb_hal_nvm_t* obj, uint32_t address, uint8_t* data, size_t size);

/** Erase one block of NVM starting at the given address. The address must be at block boundary.
 * This will block until the erase operation is complete.
 *
 * @see mtb_hal_nvm_get_info() to get the NVM characteristics for legal address values, is erase
 * required/applicable, and the erase block size(if applicable).
 *
 * @param[in] obj The NVM object
 * @param[in] address The block address to be erased
 * @return The status of the erase request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 * Refer \ref subsection_nvm_use_case_2 for more information.
 */
cy_rslt_t mtb_hal_nvm_erase(mtb_hal_nvm_t* obj, uint32_t address);

/** This function erases the block, if required, and writes the new data into the block starting
 * at the given address. The address must be at block boundary. This will block until the write
 * operation is complete.
 *
 * @see mtb_hal_nvm_get_info() to get the NVM characteristics for legal address values and
 * the write block size. The provided data buffer must be at least as large as the NVM
 * block_size.
 * @note Generally the \p data to be written must be located in the SRAM memory region.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be written
 * @param[in] data The data buffer to be written to the NVM block
 * @return The status of the write request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 *
 * Refer \ref subsection_nvm_use_case_2 for more information.
 */
cy_rslt_t mtb_hal_nvm_write(mtb_hal_nvm_t* obj, uint32_t address, const uint32_t* data);

/** Program one block with the provided data starting at the given address. The address must be
 * at block boundary. This will block until the write operation is complete.
 *
 * @note This function does not erase the block prior to writing. The block must be erased
 * first via a separate call to erase.
 * @see mtb_hal_nvm_get_info() to get the NVM characteristics for legal address values and
 * the total block size. The provided data buffer must be at least as large as the NVM
 * block_size.
 * @note Generally the \p data to be programmed must be located in the SRAM memory region.
 *
 * @param[in] obj The NVM object
 * @param[in] address The address of the block to be programmed
 * @param[in] data The data buffer to be programmed to the NVM block
 * @return The status of the program request. Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
cy_rslt_t mtb_hal_nvm_program(mtb_hal_nvm_t* obj, uint32_t address, const uint32_t* data);

/** Find the nvm region based on given address and length.
 * If "length is zero and address is not in any nvm region" or
 * if "length is not zero and address is not in any nvm region" or
 * if "length is not zero and address is one nvm region but address + length goes into another nvm
 * region",
 * the function will return Null.
 *
 * @param[in] obj The NVM object
 * @param[in] addr The start address of the block
 * @param[in] length The legnth to block
 * @return pointer, mtb_hal_nvm_region_info_t, to nvm region
 */
const mtb_hal_nvm_region_info_t* mtb_hal_nvm_get_region_for_address(mtb_hal_nvm_t* obj,
                                                                    uint32_t addr, uint32_t length);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_NVM_IMPL_HEADER
#include MTB_HAL_NVM_IMPL_HEADER
#endif /* MTB_HAL_NVM_IMPL_HEADER */

#endif //defined(MTB_HAL_DRIVER_AVAILABLE_NVM)

/** \} group_hal_nvm */

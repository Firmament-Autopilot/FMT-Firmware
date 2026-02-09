/***********************************************************************************************//**
 * \file mtb_serial_memory.h
 *
 * \brief
 * Provides APIs for interacting with an external memory connected to the SPI or
 * Serial Memory interface. Read is implemented as both blocking and non-blocking whereas
 * write, and erase are implemented as blocking functions.
 *
 ***************************************************************************************************
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
 **************************************************************************************************/

/**
 * \addtogroup group_board_libs Serial Memory
 * \ingroup group_lib_impl
 * \{
 *
 * \section section_qspi_configurator_to_smif QSPI configurator slave slot correlation with pins
 * In QSPI configurator Memory Parts are tied to a specific slave slot that is linked to the
 * actual slave select pin mappings of that specific device. So selecting a memory configuration for
 * slot 0 means that physically that external memory will be the connected to slave select 0 pin.
 * This is important for kits that have hardwired connections to external memories where the
 * memory configuration needs to be in the correct slot depending on what slave select pin is
 * hardwired to it.
 *
 * \section section_serial_memory_octal_ddr_handling Serial Memory handling for Octal DDR
 * For external memories that are configured in Octal DDR mode, read/write operations at odd
 * addresses and with length equal to 1 are not natively supported due to limitations in the
 * protocol that requires an even address and/or even lengths.
 * For this reason a special handling of these cases is present in \ref mtb_serial_memory_read
 * and \ref mtb_serial_memory_write to allow the use of odd addresses in a transparent way for
 * the user.
 *
 * For \ref mtb_serial_memory_read when selecting a read one byte at an odd address, the
 * function will instead perform a read at the even address preceding the specified address and
 * then discard the extra byte returning to the user only the data they requested.
 *
 * For \ref mtb_serial_memory_write the function needs to take into consideration all four
 * possible combination of even/odd addresses and lengths:
 *  - For even addresses, even lengths the function directly calls the PDL write function, this is
 * the standard use case
 *  - For even addresses, length equal to one byte the function first reads the memory for 2 bytes
 * and
 *  then creates a new write buffer copying the user's input buffer and making sure the last byte
 *  is not altered using the data it previously read
 *  WARNING: This will essentially write a byte past the intended one with its existing value that
 *  was previously read. Ensure that your memory can support this.
 *  - For even addresses, odd lengths greater than one the function will return an error as this is
 *  an unsupported use case
 *  - For odd addresses, even lengths the function will return an error as this is an unsupported
 *  use case
 *  - For odd addresses, length equal to one byte the function first reads the memory for 2 bytes
 *  starting at the even address preceding the specified address to and then creates a new write
 *  buffer copying the user's input buffer and making sure the first byte will not be altered using
 *  the data it previously read.
 *  WARNING: This will rewrite a location that has already been written (with its existing value).
 *  Ensure that your memory can support this.
 *  - For odd addresses, odd lengths greater than one the function will return an error as this is
 *  an unsupported use case.
 *
 *
 * This special handling needs to be enabled by setting  define in
 * _MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE
 * the application Makefile.
 *
 */

#pragma once

#include <stddef.h>
#include "cy_result.h"
#include "cy_pdl.h"
#include "mtb_hal.h"
#if defined(MTB_SERIAL_MEMORY_THREAD_SAFE)
#include <stdlib.h>
#include "cyabs_rtos.h"
#endif /* #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */

#ifdef DOXYGEN
/** Enables thread-safety for use with multi-threaded RTOS environment. */
#define MTB_SERIAL_MEMORY_THREAD_SAFE
/** The MXSMIF IP is available. */
#define CY_IP_MXSMIF
#endif /* #ifdef DOXYGEN */

#ifdef CY_IP_MXSMIF

#if defined(__cplusplus)
extern "C" {
#endif

/** The major version of the serial memory asset */
#define MTB_SERIAL_MEMORY_VERSION_MAJOR               (3U)

/** The function or operation is not supported on the target or the memory */
#define MTB_RSLT_SERIAL_MEMORY_ERR_UNSUPPORTED \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_MEMORY, 1))

/** Parameters passed to a function are invalid */
#define MTB_RSLT_SERIAL_MEMORY_ERR_BAD_PARAM \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_MEMORY, 2))

/** A previously initiated read operation is not yet complete */
#define MTB_RSLT_SERIAL_MEMORY_ERR_READ_BUSY \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_MEMORY, 3))

/** Setting octal enabled failed. */
#define MTB_RSLT_SERIAL_MEMORY_ERR_OCTAL_ENABLE \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_MEMORY, 4))

/** Setting rx capture mode failed. */
#define MTB_RSLT_SERIAL_MEMORY_ERR_RX_CAPTURE \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_BOARD_LIB_SERIAL_MEMORY, 5))

/**
 * Serial Memory Chip Select
 * Each chip select is represented by an enumeration that has the bit
 * corresponding to the chip select number set.
 */
typedef enum
{
    MTB_SERIAL_MEMORY_CHIP_SELECT_0 = 1u,      /**< The SMIF chip select 0  */
    MTB_SERIAL_MEMORY_CHIP_SELECT_1 = 1u << 1, /**< The SMIF chip select 1  */
    MTB_SERIAL_MEMORY_CHIP_SELECT_2 = 1u << 2, /**< The SMIF chip select 2  */
    MTB_SERIAL_MEMORY_CHIP_SELECT_3 = 1u << 3  /**< The SMIF chip select 3  */
} mtb_serial_memory_chip_select_t;


/**
 * Serial memory object
 *
 * Application code should not rely on the specific contents of this struct.
 * They are considered an implementation detail which is subject to change
 * between releases.
 */
typedef struct
{
    uint32_t smif_active_slot;
    SMIF_Type*                          base;
    const mtb_hal_clock_t*              clock;
    uint32_t configured_csel;
    uint32_t chip_select;
    uint32_t status_flags;
    cy_stc_smif_mem_context_t* mem_context;
    cy_stc_smif_mem_info_t* mem_info;

    #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE)
    cy_mutex_t mutex;
    #endif /* #if defined(MTB_SERIAL_MEMORY_THREAD_SAFE) */
} mtb_serial_memory_t;


/**
 * \brief Sets up the serial memory.
 *
 * \note The function will reset the memory controller when "Auto Detect SFDP"
 * is chosen in the "Memory Part Number" section of the QSPI Configurator.
 * However, if a specific part number is specified in the QSPI Configurator,
 * the responsibility falls to the application to reset the memory controller
 * using the Cy_SMIF_Reset_Memory() PDL function. This approach is adopted
 * because the mtb_serial_memory_setup() function might be executed from the
 * external memory itself, and resetting the memory controller could disrupt
 * the communication with the memory.
 * This function initializes the slots of the memory device in the SMIF configuration. It's security
 * aware and is a wrapper around Cy_SMIF_MemNumInit, and gather all information about the memory
 * size, erase and program size to be used in subsequent serial memory calls.
 * It can either be called in a secure partition or in the non-secure partition
 * if the peripheral itself is not secured.
 *
 * \param obj Pointer to the mtb_serial_memory_t object to setup
 * \param smif_active_chip The slave select line to configure as active
 * \param base Pointer to the SMIf base address
 * \param clock Pointer to the clock object
 * \param mem_context Pointer to the SMIF Device internal context data
 * \param mem_info Pointer to the SMIF memory info structure
 * \param block_config Pointer to the SMIF block configuration structure
 * \returns CY_RSLT_SUCCESS if the setup was successful, an error code
 *          otherwise.
 */
cy_rslt_t mtb_serial_memory_setup(
    mtb_serial_memory_t* obj,
    mtb_serial_memory_chip_select_t smif_active_chip,
    SMIF_Type* base,
    const mtb_hal_clock_t* clock,
    cy_stc_smif_mem_context_t* mem_context,
    cy_stc_smif_mem_info_t* mem_info,
    const cy_stc_smif_block_config_t* block_config);


#if !defined(COMPONENT_SECURE_DEVICE)
/**
 * \brief Sets up the serial memory on non-secure world if the peripheral is secure
 *
 * \note This function is to be called from the non secure partition in trustzone
 * devices (after the secure one has successfully called \ref mtb_serial_memory_setup )
 * to set up the context and gather all information about the memory size,
 * erase and program size to be used in subsequent serial memory calls.
 *
 * \param obj Pointer to the mtb_serial_memory_t object to setup
 * \param smif_active_chip The slave select line to configure as active
 * \param base Pointer to the SMIf base address
 * \param mem_context Pointer to the SMIF Device internal context data
 * \param mem_info Pointer to the SMIF memory info structure
 * \returns CY_RSLT_SUCCESS if the setup was successful, an error code
 *          otherwise.
 */
cy_rslt_t mtb_serial_memory_setup_nonsecure(
    mtb_serial_memory_t* obj,
    mtb_serial_memory_chip_select_t smif_active_chip,
    SMIF_Type* base,
    cy_stc_smif_mem_context_t* mem_context,
    cy_stc_smif_mem_info_t* mem_info);
#endif


/**
 * \brief Returns the size of the serial memory in bytes.
 * \param obj Pointer to the mtb_serial_memory_t object to obtain information from
 * \returns Memory size in bytes.
 */
size_t mtb_serial_memory_get_size(mtb_serial_memory_t* obj);

/**
 * \brief Returns the size of the erase sector to which the given address
 * belongs. Address is used only for a memory with hybrid sector size.
 * \param obj Pointer to the mtb_serial_memory_t object to obtain information from.
 * \param addr Address that belongs to the sector for which size is returned.
 * \returns Erase sector size in bytes.
 */
size_t mtb_serial_memory_get_erase_size(mtb_serial_memory_t* obj, uint32_t addr);

/**
 * \brief Returns the page size for programming of the sector to which the given
 * address belongs. Address is used only for a memory with hybrid sector size.
 * \param obj Pointer to the mtb_serial_memory_t object to obtain information from.
 * \param addr Address that belongs to the sector for which size is returned.
 * \returns Page size in bytes.
 */
size_t mtb_serial_memory_get_prog_size(mtb_serial_memory_t* obj, uint32_t addr);

/**
 * \brief Utility function to calculate the starting address of an erase sector
 * to which the given address belongs.
 * \param obj Pointer to the mtb_serial_memory_t object to obtain information from.
 * \param addr Address in the sector for which the starting address is returned.
 * \returns Starting address of the sector
 */
__STATIC_INLINE uint32_t mtb_serial_memory_get_sector_start_address(mtb_serial_memory_t* obj,
                                                                    uint32_t addr)
{
    return (addr & ~(mtb_serial_memory_get_erase_size(obj, addr) - 1U));
}


/**
 * \brief Reads data from the serial memory. This is a blocking
 * function. Returns error if (addr + length) exceeds the memory size.
 * If _MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE is set the function can
 * emulate byte addressable memories for Octal DDR memories and handle
 * one byte reads even at odd addresses.
 *
 * \param obj Pointer to the mtb_serial_memory_t object to obtain information from.
 * \param addr Starting address to read from
 * \param length Number of data bytes to read
 * \param buf Pointer to the buffer to store the data read from the memory
 * \returns CY_RSLT_SUCCESS if the read was successful, an error code otherwise.
 */
cy_rslt_t mtb_serial_memory_read(mtb_serial_memory_t* obj, uint32_t addr, size_t length,
                                 uint8_t* buf);

/**
 * \brief Writes the data to the serial memory. The program area
 * must have been erased prior to calling this API using
 * \ref mtb_serial_memory_erase() This is a blocking function. Returns error if
 * (addr + length) exceeds the memory size. If _MTB_SERIAL_MEMORY_EMULATE_BYTE_ADDRESSABLE
 * is set the function can emulate byte addressable memories for Octal DDR memories
 * and handle one byte writes even at odd addresses. This however actually writes starting from
 * the previous even address and will always write two bytes.
 * \param obj Pointer to the mtb_serial_memory_t object to write to.
 * \param addr Starting address to write to
 * \param length Number of bytes to write
 * \param buf Pointer to the buffer storing the data to be written
 * \returns CY_RSLT_SUCCESS if the write was successful, an error code
 *          otherwise.
 */
cy_rslt_t mtb_serial_memory_write(mtb_serial_memory_t* obj, uint32_t addr, size_t length,
                                  const uint8_t* buf);

/**
 * \brief Erases the serial memory, uses chip erase command when
 * addr = 0 and length = flash_size otherwise uses sector erase command. This is
 * a blocking function. Returns error if addr or (addr + length) is not aligned
 * to the sector size or if (addr + length) exceeds the memory size.
 * For memories with hybrid sectors, returns error if the end address
 * (=addr + length) is not aligned to the size of the sector in which the end
 * address is located.
 * Call \ref mtb_serial_memory_get_size() to get the flash size and
 * call \ref mtb_serial_memory_get_erase_size() to get the size of an erase
 * sector.
 * \param obj Pointer to the mtb_serial_memory_t object to erase.
 * \param addr Starting address to begin erasing
 * \param length Number of bytes to erase
 * \returns CY_RSLT_SUCCESS if the erase was successful, an error code
 *          otherwise.
 */
cy_rslt_t mtb_serial_memory_erase(mtb_serial_memory_t* obj, uint32_t addr, size_t length);

/**
 * \brief Enables Execute-in-Place (memory mapped) mode on the MCU. This
 * function does not send any command to the serial memory.
 * \param obj Pointer to the mtb_serial_memory_t object to enable XIP on.
 * \param enable true: XIP mode is set, false: normal mode is set
 * \returns CY_RSLT_SUCCESS if the operation was successful.
 */
cy_rslt_t mtb_serial_memory_enable_xip(mtb_serial_memory_t* obj, bool enable);

/**
 * \brief Sets the active memory device that the serial-flash functions perform
 * the operations on.
 * \param obj Pointer to the mtb_serial_memory_t object to set active chip for.
 * \param chip_select The chip select of the memory device to be set as active.
 * \returns The function will return an error if the device had not been setup
 * with \ref mtb_serial_memory_setup .
 */
cy_rslt_t mtb_serial_memory_set_active_chip(mtb_serial_memory_t* obj,
                                            mtb_serial_memory_chip_select_t chip_select);

/**
 * \brief Returns the number of memory devices successfully initialized.
 * \param obj Pointer to the mtb_serial_memory_t object to get chip count for.
 * \returns Number of memory devices successfully initialized.
 */
uint32_t mtb_serial_memory_get_chip_count(mtb_serial_memory_t* obj);

/**
 * \brief Returns the active chip select.
 * \param obj Pointer to the mtb_serial_memory_t object to get the active chip for.
 * \returns Returns the active memory chip.
 */
uint32_t mtb_serial_memory_get_active_chip(mtb_serial_memory_t* obj);


/** Send the Write Enable or Write Disable command to the external memory
 *
 * \param obj Pointer to the mtb_serial_memory_t object to send write
 *  enable/disable command to.
 * \param enable if true the command to be sent is Write Enable, if false the
 *  command to be sent is Write Disable.
 * \returns CY_RSLT_SUCCESS if the operation was successful, an error code
 * therwise.
 */
cy_rslt_t mtb_serial_memory_set_write_enable(mtb_serial_memory_t* obj, bool enable);

#if defined(__cplusplus)
}


#endif

#endif // CY_IP_MXSMIF

/** \} group_board_libs */

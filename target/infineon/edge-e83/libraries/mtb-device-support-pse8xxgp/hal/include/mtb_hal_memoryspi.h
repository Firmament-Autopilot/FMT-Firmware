/***************************************************************************//**
* \file mtb_hal_memoryspi.h
*
* \brief
* Provides a high level interface for interacting with the Infineon Quad-SPI.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
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
//" *SUSPEND-FORMATTING*"
/**
 *
 * \addtogroup group_hal_memoryspi MemorySPI (Memory Serial Peripheral Interface)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the Memory SPI interface.
 *
 * MemorySPI is an SPI-based communication interface, often used with external memory devices.
 * The MemorySPI driver supports sending and receiving commands to/from from another
 * device via a single, dual, quad, or octal SPI interface.
 *
 * \section subsection_memoryspi_features Features
 * * Standard SPI Master interface
 * * Supports Single/Dual/Quad/Octal SPI memories
 * * Supports Dual-Quad SPI mode
 * * Execute-In-Place (XIP) from external Quad SPI Flash
 * * Supports external serial memory initialization via Serial Flash Discoverable Parameters (SFDP)
 * standard
 *
 * \section subsection_memoryspi_code_snippets Code Snippets
 * \note The following snippets show commands specific to the
 * <a
 * href="https://www.cypress.com/documentation/datasheets/s25fl512s-512-mbit-64-mbyte-30v-spi-flash-memory">S25FL512S
 * Cypress NOR Flash device</a>.
 * Refer to the datasheet of the external memory device for device specific memory commands.
 * \subsection subsection_memoryspi_snippet_1 Code Snippet 1: Initializing the mtb_hal_memoryspi_command_t structure
 * The following code snip demonstrates an example for initializing the mtb_hal_memoryspi_command_t
 * structure for
 * any given flash command. The mtb_hal_memoryspi_command_t.mode_bits structure has several other
 * components which should
 * be set as per the command. Mode bits are not required for single SPI read command, hence,
 * mode_bits.disabled
 * is set to TRUE in the below example code.
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_structure_initialisation
 * \subsection subsection_memoryspi_snippet_2 Code Snippet 2: MemorySPI initialization and Reading Flash memory
 * This example function demonstrates the initialization of the MemorySPI component and use of the
 * mtb_hal_memoryspi_read() function
 * to complete the read operation and receive the read data in a buffer.
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_read
 * \subsection subsection_memoryspi_snippet_3 Code Snippet 3: Erasing Flash memory
 * The following code snippet demonstrates the use of mtb_hal_memoryspi_transfer() API for sending
 * single byte instruction that may or may not need any address or data bytes.
 * It also shows the usage of status register read command within a while loop to poll the WIP
 * bit status.
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_erase
 * \note Flash memories need erase operation before programming.
 * \subsection subsection_memoryspi_snippet_4 Code Snippet 4: Programming Flash memory
 * This code snippet demonstrates the usage mtb_hal_memoryspi_write() API for executing program
 * operation on flash memory.
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_program
 * \subsection subsection_memoryspi_snippet_5 Code Snippet 5: Configuring multiple memories
 * This code snippet demonstrates the usage and mtb_hal_memoryspi_select_active_csel() API for
 * switching between memories.
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_multiple_memories
 *
 * \section subsection_memoryspi_with_preinit_hw Usage of driver within devices with preinitialized hardware
 * Some devices execute code from external memory rather than internal memory and therefore at boot already
 * initialize the Hardware to correctly enable read, write, execute operations from the MCU to the external
 * memory.
 * In these cases, the MemorySPI interface can still be used to interact with the same external memory on which
 * code is executing from but special attention is needed to avoid impacting the normal code operation.
 * In these cases, the SMIF interface will have already been configured and set to XIP mode.
 * It is still possible to execute MMIO operations to other parts of the memory that are free.
 * In order to do so, the APIs in this driver need to be stored in a different storage
 * (either RAM or internal memory of the device) so that there is no risk of trying to access the external memory
 * while it's actively engaged in a different operation.
 * \note  The linker scripts of the devices for which this is true already handle this and users do not
 * need to perform additional changes to them, but should keep this information in mind for their own code.
 * Since the hardware is already initialized the MemorySPI initialization can be simplified a bit:
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_init_no_pdl
 * However, calling the PDL APIs for a second time as shown in
 * \snippet hal_memoryspi.c snippet_mtb_hal_memoryspi_read
 * will not create issues as long as the configuration matches the one that was used to initially configure the
 * hardware and there are no calls to Disable or Deinit the peripheral.
 * since XIP mode and MMIO mode can coexist on the board there is no special handling needed to successfully run
 * MMIO operations. For more details see SMIF XIP Initialization section of PDL documentation.
 * It's important to note that only blocking apis are allowed in this mode.
 *
 */
//" *RESUME-FORMATTING*"
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_memoryspi MemorySPI HAL Results
 *  MemorySPI specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Bus width Error. */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_BUS_WIDTH                   \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 0))
/** Waiting for certain event error. */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_TIMEOUT                     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 1))
/** Cannot switch to specified CSEL signal */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_CANNOT_SWITCH_CSEL          \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 2))
/** Data rate error. */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_DATARATE                    \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 3))
/** Instruction error. */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_INSTRUCTION                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 4))
/** Dummy cycles error. */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_DUMMY_CYCLES                \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 5))
/** Requested feature is not supported by this IP version. */
#define MTB_HAL_MEMORYSPI_RSLT_ERR_UNSUPPORTED                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_MEMORYSPI, 6))

/**
 * \}
 */

/** MemorySPI Bus width. Some parts of commands provide variable bus width. */

typedef enum mtb_hal_memoryspi_bus_width
{
    MTB_HAL_MEMORYSPI_CFG_BUS_SINGLE       = 1,            /**< Normal SPI Mode */
    MTB_HAL_MEMORYSPI_CFG_BUS_DUAL         = 2,            /**< Dual SPI Mode */
    MTB_HAL_MEMORYSPI_CFG_BUS_QUAD         = 4,            /**< Quad SPI Mode */
    MTB_HAL_MEMORYSPI_CFG_BUS_OCTAL        = 8             /**< Octal SPI Mode */
} mtb_hal_memoryspi_bus_width_t;

/** Address size in bits */
typedef enum mtb_hal_memoryspi_size
{
    MTB_HAL_MEMORYSPI_CFG_SIZE_8           = 8,            /**< 8 bits address */
    MTB_HAL_MEMORYSPI_CFG_SIZE_16          = 16,           /**< 16 bits address */
    MTB_HAL_MEMORYSPI_CFG_SIZE_24          = 24,           /**< 24 bits address */
    MTB_HAL_MEMORYSPI_CFG_SIZE_32          = 32            /**< 32 bits address */
} mtb_hal_memoryspi_size_t;

/** MemorySPI interrupt triggers */
typedef enum
{
    MTB_HAL_MEMORYSPI_EVENT_NONE           = 0,            /**< No event */
    MTB_HAL_MEMORYSPI_IRQ_TRANSMIT_DONE    = 1 << 0,       /**< Async transmit done */
    MTB_HAL_MEMORYSPI_IRQ_RECEIVE_DONE     = 1 << 1        /**< Async receive done */
} mtb_hal_memoryspi_event_t;

/** MemorySPI data rate */
typedef enum
{
    MTB_HAL_MEMORYSPI_DATARATE_SDR         = 0,            /**< Single data rate */
    MTB_HAL_MEMORYSPI_DATARATE_DDR         = 1             /**< Double data rate */
} mtb_hal_memoryspi_datarate_t;


/** @brief MemorySPI command settings */
typedef struct mtb_hal_memoryspi_command
{
    struct
    {
        mtb_hal_memoryspi_bus_width_t  bus_width;      /**< Bus width for the instruction */
        mtb_hal_memoryspi_datarate_t   data_rate;      /**< Data rate SDR/DDR */
        bool                      two_byte_cmd;        /**< Defines whether cmd is 2-byte value, or
                                                          1-byte (if false) */
        uint16_t                  value;               /**< Instruction value */
        bool                      disabled;            /**< Instruction phase skipped if disabled is
                                                          set to true */
    } instruction;                              /**< Instruction structure */
    struct
    {
        mtb_hal_memoryspi_bus_width_t  bus_width;      /**< Bus width for the address */
        mtb_hal_memoryspi_datarate_t   data_rate;      /**< Data rate SDR/DDR */
        mtb_hal_memoryspi_size_t       size;           /**< Address size */
        /* Address is specified as argument for write/read functions */
        bool                      disabled;            /**< Address phase skipped if disabled is set
                                                          to true */
    } address;                                  /**< Address structure */
    struct
    {
        mtb_hal_memoryspi_bus_width_t  bus_width;      /**< Bus width for mode bits  */
        mtb_hal_memoryspi_datarate_t   data_rate;      /**< Data rate SDR/DDR */
        mtb_hal_memoryspi_size_t       size;           /**< Mode bits size */
        uint32_t                  value;               /**< Mode bits value */
        bool                      disabled;            /**< Mode bits phase skipped if disabled is
                                                          set to true */
    } mode_bits;                                /**< Mode bits structure */
    struct
    {
        mtb_hal_memoryspi_bus_width_t  bus_width;      /**< Bus width for mode bits  */
        mtb_hal_memoryspi_datarate_t   data_rate;      /**< Data rate SDR/DDR */
        uint32_t                  dummy_count;         /**< Dummy cycles count */
    } dummy_cycles;                               /**< Dummy cycles structure */
    struct
    {
        mtb_hal_memoryspi_bus_width_t  bus_width;      /**< Bus width for data */
        mtb_hal_memoryspi_datarate_t   data_rate;      /**< Data rate SDR/DDR */
    } data;                                       /**< Data structure */
} mtb_hal_memoryspi_command_t;

/** MemorySPI Chip Select
 * Each chip select is represented by an enumeration that has the bit
 * corresponding to the chip select number set. */
typedef enum
{
    MTB_HAL_MEMORYSPI_CHIP_SELECT_0 = 1u, /**< The SMIF chip select 0  */
    MTB_HAL_MEMORYSPI_CHIP_SELECT_1 = 1u << 1, /**< The SMIF chip select 1  */
    MTB_HAL_MEMORYSPI_CHIP_SELECT_2 = 1u << 2, /**< The SMIF chip select 2  */
    MTB_HAL_MEMORYSPI_CHIP_SELECT_3 = 1u << 3  /**< The SMIF chip select 3  */
} mtb_hal_memoryspi_chip_select_t;

/** The data line-selection options for a chip device. */
typedef enum
{
    /**
     * smif.spi_data[0] = DATA0, smif.spi_data[1] = DATA1, ..., smif.spi_data[7] = DATA7.
     * This value is allowed for the SPI, DSPI, QSPI, dual QSPI, and octal SPI modes.
     */
    MTB_HAL_MEMORYSPI_DATA_SELECT_0       = 0,
    /**
     * smif.spi_data[2] = DATA0, smif.spi_data[3] = DATA1.
     * This value is only allowed for the SPI and DSPI modes.
     */
    MTB_HAL_MEMORYSPI_DATA_SELECT_1      = 1,
    /**
     * smif.spi_data[4] = DATA0, smif.spi_data[5] = DATA1, ..., smif.spi_data[7] = DATA3.
     * This value is only allowed for the SPI, DSPI, QSPI and dual QSPI modes.
     */
    MTB_HAL_MEMORYSPI_DATA_SELECT_2      = 2,
    /**
     * smif.spi_data[6] = DATA0, smif.spi_data[7] = DATA1.
     * This value is only allowed for the SPI and DSPI modes.
     */
    MTB_HAL_MEMORYSPI_DATA_SELECT_3      = 3
} mtb_hal_memoryspi_data_select_t;

/** Handler for MemorySPI callbacks */
typedef void (* mtb_hal_memoryspi_event_callback_t)(void* callback_arg,
                                                    mtb_hal_memoryspi_event_t event);

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * @param[out] obj     The HAL driver instance object. The caller must allocate the
 *                     memory for this object, but the HAL will initialize its contents
 * @param[in] config   The configurator-generated HAL config structure for this
 *                     peripheral instance
 * @param[in] context  The pointer to the context structure for the SMIF driver
 * @return the status of the HAL setup
 */
cy_rslt_t mtb_hal_memoryspi_setup(mtb_hal_memoryspi_t* obj,
                                  const mtb_hal_memoryspi_configurator_t* config,
                                  cy_stc_smif_context_t* context);


/** Get the actual frequency that MemorySPI is configured for
 *
 * @param[in] obj The MemorySPI object
 * @return Frequency in MHz
 */
uint32_t mtb_hal_memoryspi_get_frequency(mtb_hal_memoryspi_t* obj);

/** Configure data select pin for the specified memory.
 *
 * Multiple pins can be configured as MemorySPI chip select pins as well as IO pins may be (or may
 * not be) shared and used to service multiple connected memories. This function can be called
 * multiple times - each call for each additional memory.
 * Please refer to device datasheet for details.
 * Switching between configured chip select pins is done by \ref
 * mtb_hal_memoryspi_select_active_csel
 * function.
 * Unless modified with that function, the first CSEL pin provided as part of \ref
 * mtb_hal_memoryspi_setup is the default.
 * Please refer to \ref subsection_memoryspi_snippet_5 for example of configuration multiple memory
 * devices and switching between them.
 * \note IO pins can overlap between multiple memories.
 * @param[in] obj       The MemorySPI object to configure
 * @param[in] csel      CSEL pin for which we want to configure the data select
 * @param[in] data_select Data select value we want to set for the csel
 * @return The status of pin configuration
 */
cy_rslt_t mtb_hal_memoryspi_chip_configure(mtb_hal_memoryspi_t* obj,
                                           const mtb_hal_memoryspi_chip_select_t csel,
                                           mtb_hal_memoryspi_data_select_t data_select);

/** Selects an active chip select (CSEL) line from one of available and configured.
 *
 * Memories can be added with help of \ref mtb_hal_memoryspi_chip_configure function.
 * @param[in] obj   The MemorySPI object to configure
 * @param[in] csel  CSEL pin to be set as active
 * @return CY_RSLT_SUCCESS if slave select was switched successfully, otherwise -
 * MTB_HAL_MEMORYSPI_RSLT_ERR_CANNOT_SWITCH_CSEL
 */
cy_rslt_t mtb_hal_memoryspi_select_active_csel(mtb_hal_memoryspi_t* obj,
                                               mtb_hal_memoryspi_chip_select_t csel);

/** Sends a command to initiate a read, waits for the command to be accepted then reads a
 *  block of data in a blocking fashion.
 *
 * This will read either `length` bytes or the number of bytes that are currently available in the
 * receive buffer, whichever is less, then return. The value pointed to by `length` will be updated
 * to reflect the number of bytes that were actually read.
 *
 * @param[in]  obj      MemorySPI object
 * @param[in]  command  MemorySPI command
 * @param[in]  address  Address to access to
 * @param[out] data     RX buffer
 * @param[in]  length   RX buffer length in bytes
 * @return The status of the read request
 */
cy_rslt_t mtb_hal_memoryspi_read(mtb_hal_memoryspi_t* obj,
                                 const mtb_hal_memoryspi_command_t* command,
                                 uint32_t address, void* data, size_t* length);

/** Sends a command to initiate a read, waits for the command to be accepted then reads a
 *  block of data in a non-blocking fashion.
 *
 * This will transfer `length` bytes into the buffer pointed to by `data` in the background. When
 * the requested quantity of data has been read, the @ref MTB_HAL_MEMORYSPI_IRQ_RECEIVE_DONE
 * event will be raised.
 * See @ref mtb_hal_memoryspi_register_callback and @ref mtb_hal_memoryspi_enable_event.
 *
 * @param[in]  obj      MemorySPI object
 * @param[in]  command  MemorySPI command
 * @param[in]  address  Address to access to
 * @param[out] data     RX buffer
 * @param[in]  length   RX buffer length in bytes
 * @return The status of the read request
 */
cy_rslt_t mtb_hal_memoryspi_read_async(mtb_hal_memoryspi_t* obj,
                                       const mtb_hal_memoryspi_command_t* command,
                                       uint32_t address, void* data, size_t* length);

/** Sends a command to initiate a write, waits for the command to be accepted then writes a
 *  block of data in a blocking fashion.
 *
 * This will write either `length` bytes or until the write buffer is full, whichever is less,
 * then return. The value pointed to by `length` will be updated to reflect the number of bytes
 * that were actually written. If `length` is 0, the function simply returns and does not send
 * the command as for some memories the write commands has to be followed by at least one byte
 * of data and otherwise the memory will be stuck in a perpetual busy state.
 *
 * @param[in] obj      MemorySPI object
 * @param[in] command  MemorySPI command
 * @param[in] address  Address to access to
 * @param[in] data     TX buffer
 * @param[in] length   TX buffer length in bytes
 * @return The status of the write request
 */
cy_rslt_t mtb_hal_memoryspi_write(mtb_hal_memoryspi_t* obj,
                                  const mtb_hal_memoryspi_command_t* command,
                                  uint32_t address, const void* data, size_t* length);

/** Sends a command to initiate a write, waits for the command to be accepted then writes a
 *  block of data in a non-blocking fashion.
 *
 * This will transfer `length` bytes into the tx buffer in the background. When the requested
 * quantity of data has been queued in the transmit buffer, the @ref
 * MTB_HAL_MEMORYSPI_IRQ_TRANSMIT_DONE event will be raised.
 * See @ref mtb_hal_memoryspi_register_callback and @ref
 * mtb_hal_memoryspi_enable_event.
 * If `length` is 0, the function simply returns and does not send
 * the command as for some memories the write commands has to be followed by at least one byte
 * of data and otherwise the memory will be stuck in a perpetual busy state.
 *
 * @param[in] obj      MemorySPI object
 * @param[in] command  MemorySPI command
 * @param[in] address  Address to access to
 * @param[in] data     TX buffer
 * @param[in] length   TX buffer length in bytes
 * @return The status of the write request
 */
cy_rslt_t mtb_hal_memoryspi_write_async(mtb_hal_memoryspi_t* obj,
                                        const mtb_hal_memoryspi_command_t* command,
                                        uint32_t address, const void* data, size_t* length);

/** Send a command (and optionally data , if tx_buffer is specified) and get the response
 * (and optionally data if trx_buffer is specified). Can be used to send/receive device
 *  specific commands
 *
 * @param[in]  obj      MemorySPI object
 * @param[in]  command  MemorySPI command
 * @param[in]  address  Address to access to
 * @param[in]  tx_data  TX buffer
 * @param[in]  tx_size  TX buffer length in bytes
 * @param[out] rx_data  RX buffer
 * @param[in]  rx_size  RX buffer length in bytes
 * @return The status of the transfer request
 */
cy_rslt_t mtb_hal_memoryspi_transfer(
    mtb_hal_memoryspi_t* obj, const mtb_hal_memoryspi_command_t* command, uint32_t address,
    const void* tx_data, size_t tx_size,
    void* rx_data, size_t rx_size);

/** Register a MemorySPI event handler
 *
 * This function will be called when one of the events enabled by \ref
 * mtb_hal_memoryspi_enable_event occurs.
 *
 * @param[in] obj          The MemorySPI object
 * @param[in] callback     The callback handler which will be invoked when the interrupt fires
 * @param[in] callback_arg Generic argument that will be provided to the handler when called
 */
void mtb_hal_memoryspi_register_callback(mtb_hal_memoryspi_t* obj,
                                         mtb_hal_memoryspi_event_callback_t callback,
                                         void* callback_arg);

/** Configure MemorySPI interrupt enablement.
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_memoryspi_register_callback
 * will be called.
 *
 * @param[in] obj            The MemorySPI object
 * @param[in] event          The MemorySPI event type
 * @param[in] enable         True to turn on interrupts, False to turn off
 */
void mtb_hal_memoryspi_enable_event(mtb_hal_memoryspi_t* obj, mtb_hal_memoryspi_event_t event,
                                    bool enable);

/**
 * Process interrupts related related to a MemorySPI instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */

cy_rslt_t mtb_hal_memoryspi_process_interrupt(mtb_hal_memoryspi_t* obj);

/** Checks if an async operation is in progress
 *
 * @param[in] obj           The MemorySPI peripheral to check
 * @return Indication of whether a MemorySPI async operation is in progress
 */
bool mtb_hal_memoryspi_is_async_in_progress(mtb_hal_memoryspi_t* obj);

/** Checks if the specified MemorySPI peripheral is in use
 *
 * @param[in] obj           The MemorySPI peripheral to check
 * @return Indication of whether the MemorySPI is busy
 */
bool mtb_hal_memoryspi_is_busy(mtb_hal_memoryspi_t* obj);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_MEMORYSPI_IMPL_HEADER
#include MTB_HAL_MEMORYSPI_IMPL_HEADER
#endif /* MTB_HAL_MEMORYSPI_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_MEMORYSPI)

/** \} group_hal_memoryspi */

/***************************************************************************//**
* \file mtb_hal_sdio.h
*
* \brief
* Provides a high level interface for interacting with the Infineon SDIO interface.
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

/**
 * \addtogroup group_hal_sdio SDIO (Secure Digital Input Output)
 * \ingroup group_hal
 * \{
 * High level interface to the Secure Digital Input Output (SDIO).
 *
 * The SDIO protocol is an extension of the SD interface for general I/O functions.
 * Refer to the SD Specifications Part 1 SDIO Specifications Version 4.10 for more
 * information on the SDIO protocol and specifications.
 *
 * The host functionality of this driver allows commands to be sent over the SDIO bus;
 * the supported commands can be found in mtb_hal_sdio_host_command_t. Bulk data transfer
 * is supported via mtb_hal_sdio_bulk_transfer().
 *
 * The device functionality of this driver allows configuring the SDIO device for
 * receiving commands from the host. Data can be sent and received from/to application
 * buffers.
 *
 * \section subsection_sdio_features Features
 * * Supports 4-bit interface
 * * Supports Ultra High Speed (UHS-I) mode
 * * Supports Default Speed (DS), High Speed (HS), SDR12, SDR25 and SDR50 speed modes
 * * Supports SDIO card interrupts in both 1-bit SD and 4-bit SD modes
 * * Supports Standard capacity (SDSC), High capacity (SDHC) and Extended capacity (SDXC) memory
 *
 * \section subsection_sdio_quickstart Quick Start
 * Initialize SDIO by using the Device Configurator and selecting pins according to the target
 * device used.
 * Specify the SDIO configuration using the configuration structure (const \ref
 * mtb_hal_sdio_configurator_t * config). <br>
 *
 * \section subsection_sdio_code_snippets Code Snippets
 *
 * \subsection subsection_sdio_host_code_snippets Host Code Snippets
 *
 * \subsubsection subsection_sdio_host_use_case_1 Snippet1: Simple SDIO Host Initialization example
 * The following snippet shows how to initialize the SDIO host interface with a pre-defined
 * configuration
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_host_simple_init
 *
 * \subsubsection subsection_sdio_host_use_case_2 Snippet2: Configure Host Interrupt
 * The following snippet shows how to configure an interrupt to handle host specific events. Refer
 * \ref mtb_hal_sdio_event_t for different types of events.
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_host_interrupt_callback
 *
 * \subsubsection subsection_sdio_host_use_case_3 Snippet3: Sending Host Commands
 * The following snippet shows how to send a particular command. Some steps of the card
 * initialization have been provided for reference. Refer to mtb_hal_sdio_host_command_t for
 * different commands.
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_host_send_command
 *
 * \subsubsection subsection_sdio_host_use_case_4 Snippet4: Host Bulk Data Transfer
 * The following snippet shows how to start a bulk data transfer.
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_host_bulk_transfer
 *
 * \subsection subsection_sdio_dev_code_snippets Device Code Snippets
 *
 * \subsubsection subsection_sdio_dev_use_case_1 Snippet1: Simple SDIO Device Initialization example
 * The following snippet shows how to initialize the SDIO device interface with a pre-defined
 * configuration
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_dev_simple_init
 *
 * \subsubsection subsection_sdio_dev_use_case_2 Snippet2: Configure Device Interrupt
 * The following snippet shows how to configure an interrupt to handle device specific events. Refer
 * \ref mtb_hal_sdio_event_t for different types of events.
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_dev_interrupt_callback
 *
 * \subsubsection subsection_sdio_dev_use_case_3 Snippet3: Device Async Read
 * The following snippet shows how to start an async read.
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_dev_async_read
 *
 * \subsubsection subsection_sdio_dev_use_case_4 Snippet4: Device Mailbox Write
 * The following snippet shows how to write to the mailbox.
 *
 * \snippet hal_sdio.c snippet_mtb_hal_sdio_dev_write_mailbox
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_SDIO)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/

/* HAL return value defines */

/** \addtogroup group_hal_results_sdio SDIO HAL Results
 *  SDIO specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Incorrect parameter value define */
#define MTB_HAL_SDIO_RSLT_ERR_BAD_PARAM                   \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 0))
/** Requested feature is not supported on this hardware. */
#define MTB_HAL_SDIO_RSLT_ERR_UNSUPPORTED                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 1))
/** SDIO Configuration error. */
#define MTB_HAL_SDIO_RSLT_ERR_CONFIG                     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 2))
/** Error occured during I/O voltage switch sequence. */
#define MTB_HAL_SDIO_RSLT_ERR_IO_VOLT_SWITCH_SEQ          \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 3))

/** Failed to write SDIO Device data */
#define MTB_HAL_SDIO_DEV_RSLT_WRITE_ERROR                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 1 << 4))
/** Failed to read SDIO Device data */
#define MTB_HAL_SDIO_DEV_RSLT_READ_ERROR                  \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 2 << 4))
/** Failed to write SDIO Device mailbox data */
#define MTB_HAL_SDIO_DEV_RSLT_MAILBOX_WRITE_ERROR         \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 3 << 4))
/** Failed to read SDIO Device mailbox data */
#define MTB_HAL_SDIO_DEV_RSLT_MAILBOX_READ_ERROR          \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDIO, 4 << 4))

/**
 * \}
 */

/*******************************************************************************
*       Common Enumerations
*******************************************************************************/

/** Types of events that could be asserted by SDIO */
typedef enum
{
    #if (MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST)
    /* SDIO host events */
    MTB_HAL_SDIO_CMD_COMPLETE   = 0x00001,  //!< Command Complete
    MTB_HAL_SDIO_XFER_COMPLETE  = 0x00002,  //!< Host read/write transfer is complete
    MTB_HAL_SDIO_BGAP_EVENT     = 0x00004,  //!< Set when both read/write transaction is stopped
    MTB_HAL_SDIO_DMA_INTERRUPT  = 0x00008,  //!< Host controller detects an SDMA Buffer Boundary
                                            //!< during transfer
    MTB_HAL_SDIO_BUF_WR_READY   = 0x00010,  //!< Set if the Buffer Write Enable changes from 0 to 1
    MTB_HAL_SDIO_BUF_RD_READY   = 0x00020,  //!< Set if the Buffer Read Enable changes from 0 to 1
    MTB_HAL_SDIO_CARD_INSERTION = 0x00040,  //!< Set if the Card Inserted in the Present State
    MTB_HAL_SDIO_CARD_REMOVAL   = 0x00080,  //!< Set if the Card Inserted in the Present State
    MTB_HAL_SDIO_CARD_INTERRUPT = 0x00100,  //!< Synchronized value of the DAT[1] interrupt input
                                            //!< for SD mode
    MTB_HAL_SDIO_INT_A          = 0x00200,  //!< Reserved: set to 0
    MTB_HAL_SDIO_INT_B          = 0x00400,  //!< Reserved: set to 0
    MTB_HAL_SDIO_INT_C          = 0x00800,  //!< Reserved: set to 0
    MTB_HAL_SDIO_RE_TUNE_EVENT  = 0x01000,  //!< Reserved: set to 0
    MTB_HAL_SDIO_FX_EVENT       = 0x02000,  //!< Set when R[14] of response register is set to 1
    MTB_HAL_SDIO_CQE_EVENT      = 0x04000,  //!< Set if Command Queuing/Crypto event has occurred
    MTB_HAL_SDIO_ERR_INTERRUPT  = 0x08000,  //!< Set if any of the bits in the Error Interrupt
                                            //!< Status register are set
    #endif // if (MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST)
    #if (MTB_HAL_DRIVER_AVAILABLE_SDIO_DEV)
    /* SDIO device events */
    MTB_HAL_SDIO_DEV_HOST_INFO      = 0x80001,  /**< Info from host (e.g. mailbox) was received */
    MTB_HAL_SDIO_DEV_READ_COMPLETE  = 0x80002,  /**< Device read operation is complete */
    MTB_HAL_SDIO_DEV_WRITE_COMPLETE = 0x80004,  /**< Device write operation is complete */
    MTB_HAL_SDIO_DEV_READ_ERROR     = 0x80008,  /**< Device error while performing read */
    MTB_HAL_SDIO_DEV_WRITE_ERROR    = 0x80010,  /**< Device error while performing write */
    #endif
    MTB_HAL_SDIO_ALL_INTERRUPTS = 0x0E1FF   //!< Used to enable/disable all interrupts events
} mtb_hal_sdio_event_t;


/*******************************************************************************
*       Enumerations
*******************************************************************************/

#if (MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST)

/** Commands that can be issued */
typedef enum
{
    MTB_HAL_SDIO_CMD_GO_IDLE_STATE      =  0, //!< Go to idle state
    MTB_HAL_SDIO_CMD_SEND_RELATIVE_ADDR =  3, //!< Send a relative address
    MTB_HAL_SDIO_CMD_IO_SEND_OP_COND    =  5, //!< Send an OP IO
    MTB_HAL_SDIO_CMD_SELECT_CARD        =  7, //!< Send a card select
    MTB_HAL_SDIO_CMD_VOLTAGE_SWITCH     = 11, //!< Voltage switch
    MTB_HAL_SDIO_CMD_GO_INACTIVE_STATE  = 15, //!< Go to inactive state
    MTB_HAL_SDIO_CMD_IO_RW_DIRECT       = 52, //!< Perform a direct read/write
    MTB_HAL_SDIO_CMD_IO_RW_EXTENDED     = 53  //!< Perform an extended read/write
} mtb_hal_sdio_host_command_t;

/** Types of transfer that can be performed */
typedef enum
{
    MTB_HAL_SDIO_XFER_TYPE_READ, //!< Read from the card
    MTB_HAL_SDIO_XFER_TYPE_WRITE //!< Write to the card
} mtb_hal_sdio_host_transfer_type_t;

/** I/O voltage levels */
typedef enum
{
    MTB_HAL_SDIO_IO_VOLTAGE_3_3V                  = 0U,   //!< I/O voltage is 3.3V.
    MTB_HAL_SDIO_IO_VOLTAGE_1_8V                  = 1U    //!< I/O voltage is 1.8V.
} mtb_hal_sdio_host_io_voltage_t;

/** SDIO I/O voltage select principle */
typedef enum
{
    //! HAL driver performs switching sequence (if voltage is being switched to 1.8V) and changes
    //! io_volt_sel pin level accordingly. No commands are being send to the card in this mode.
    MTB_HAL_SDIO_IO_VOLT_ACTION_SWITCH_SEQ_ONLY   = 1U,
    //! I/O voltage is changed by changing io_volt_sel pin's level. No commands are being sent
    //! to the card in this mode.
    MTB_HAL_SDIO_IO_VOLT_ACTION_NONE              = 2U
} mtb_hal_sdio_host_io_volt_action_type_t;

#endif /* (MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST) */

/*******************************************************************************
*       Data Structures
*******************************************************************************/

/** @brief SDIO initial configuration struct */
typedef struct
{
    uint32_t frequencyhal_hz;           //!< Clock frequency in hertz (target SDIO frequency for
                                        //!< device mode)
    uint16_t block_size;                //!< Block size (max block size for device mode)
    bool     is_sdio_dev;               //!< 0 if SDIO host, 1 if SDIO device
} mtb_hal_sdio_cfg_t;

/** Callback for SDIO events */
typedef void (* mtb_hal_sdio_event_callback_t)(void* callback_arg, mtb_hal_sdio_event_t event);

/*******************************************************************************
*       Common functions
*******************************************************************************/

/**
 * Sets up a HAL instance to use the specified hardware resource. This hardware
 * resource must have already been configured via the PDL.
 *
 * \note It is required that after calling \ref mtb_hal_sdio_setup a User must call
 * Cy_SD_Host_SetHostBusWidth to set the bus width to 4 (CY_SD_HOST_BUS_WIDTH_4_BIT).
 *
 * @param[out] obj   The HAL driver instance object. The caller must allocate the
 *                   memory for this object, but the HAL will initialize its contents
 * @param[in] config The configurator-generated HAL config structure for this
 *                   peripheral instance
 * @param[in] clock  The HAL clock object that is connected to this peripheral instance
 * @param[in] sdio_context The context for the sdio instance allocated by the user
 * @return the status of the HAL setup
 */
cy_rslt_t mtb_hal_sdio_setup(mtb_hal_sdio_t* obj, const mtb_hal_sdio_configurator_t* config,
                             const mtb_hal_clock_t* clock, cy_stc_sd_host_context_t* sdio_context);

/** Configure the SDIO block
 *
 * SDIO is either a host or a device type. This function allows specifying the
 * features for either type. Refer to \ref mtb_hal_sdio_cfg_t for more information.
 *
 * @param[in,out] obj    The SDIO object
 * @param[in]     config The SDIO configuration to apply
 * @return The status of the configure request.
 *
 * Returns \ref CY_RSLT_SUCCESS on successful operation.
 */
cy_rslt_t mtb_hal_sdio_configure(mtb_hal_sdio_t* obj, const mtb_hal_sdio_cfg_t* config);

/** Register an SDIO event callback handler
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_sdio_enable_event
 * occurs.
 *
 * @param[in] obj          The SDIO object
 * @param[in] callback     The callback function which will be invoked when the event triggers
 * @param[in] callback_arg Generic argument that will be provided to the callback when executed
 *
 * Refer to \ref subsection_sdio_host_use_case_2 and \ref subsection_sdio_dev_use_case_2 for usage
 * information.
 */
void mtb_hal_sdio_register_callback(mtb_hal_sdio_t* obj, mtb_hal_sdio_event_callback_t callback,
                                    void* callback_arg);

/** Configure the callback event
 *
 * Callbacks will be triggered for the specified SDIO events.
 * Refer to \ref mtb_hal_sdio_event_t for the list of supported events.
 *
 * @param[in] obj           The SDIO object
 * @param[in] event         The SDIO event type
 * @param[in] enable        Set to true to enable events, or false to disable them
 *
 * Refer to \ref subsection_sdio_host_use_case_2 and \ref subsection_sdio_dev_use_case_2 for usage
 * information.
 */
void mtb_hal_sdio_enable_event(mtb_hal_sdio_t* obj, mtb_hal_sdio_event_t event, bool enable);

/**
 * Process interrupts related related to an SDIO instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_sdio_process_interrupt(mtb_hal_sdio_t* obj);

#if (MTB_HAL_DRIVER_AVAILABLE_SDIO_DEV)

/*******************************************************************************
*       Device-specific Functions
*******************************************************************************/

/* SDIO device is not supported by this version of the HAL */

#endif /* (MTB_HAL_DRIVER_AVAILABLE_SDIO_DEV) */

#if (MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST)

/*******************************************************************************
*       Host-specific Functions
*******************************************************************************/

/** Send command to the SDIO device
 *
 * See \ref mtb_hal_sdio_host_command_t for list of available commands.
 * This will block until the command is completed.
 *
 * @param[in,out] obj       The SDIO host object
 * @param[in]     direction The direction of transfer (read/write)
 * @param[in]     command   The command to send to the SDIO device
 * @param[in]     argument  The argument to the command
 * @param[out]    response  The response from the SDIO device
 * @return The status of the command transfer.
 *
 * Returns \ref CY_RSLT_SUCCESS on successful operation. Refer \ref subsection_sdio_host_use_case_3
 * for more information.
 */
cy_rslt_t mtb_hal_sdio_host_send_cmd(mtb_hal_sdio_t* obj,
                                     mtb_hal_sdio_host_transfer_type_t direction,
                                     mtb_hal_sdio_host_command_t command, uint32_t argument,
                                     uint32_t* response);

/** Perform a bulk data transfer
 *
 * Sends \ref MTB_HAL_SDIO_CMD_IO_RW_EXTENDED command (CMD=53) which allows writing and reading
 * of a large number of I/O registers with a single command.
 * This will block until the transfer is completed.
 *
 * If D-cache is enabled, the user needs to make sure that the data pointer passed
 * to the mtb_hal_sdio_host_bulk_transfer function points to a buffer which is
 * aligned to the cache line size (__SCB_DCACHE_LINE_SIZE).
 * The length of buffer data must be a multiple of the cache line size to ensure
 * cache coherency. CY_ALIGN(__SCB_DCACHE_LINE_SIZE) macro can be used for alignment.
 *
 * Refer to \ref DCACHE_Management for more information.
 *
 * @param[in,out] obj       The SDIO host object
 * @param[in]     direction The direction of transfer (read/write)
 * @param[in]     argument  The argument to the command
 * @param[in]     data      The data to send to the SDIO device. A bulk transfer is done in block
 *                          size (default: 64 bytes) chunks for better performance. Therefore,
 *                          the size of the data buffer passed into this function must be at least
 *                          `length` bytes, and if 'length' is greater than the configured block
 *                          size, it must also be a multiple of the block size.
 * @param[in]     length    The number of bytes to send. Must be less than the block size set up
 *                          by the user (default: 64 bytes) OR be aligned with the block size. For
 *                          example. the following lengths are legal for a block size of 64 bytes:
 *                          10, 29, 33, 64, 128, 192...
 * @param[out]    response  The response from the SDIO device
 * @return The status of the bulk transfer operation.
 *
 * Returns \ref CY_RSLT_SUCCESS on successful operation. Refer \ref subsection_sdio_host_use_case_4
 * for more information.
 */
cy_rslt_t mtb_hal_sdio_host_bulk_transfer(mtb_hal_sdio_t* obj,
                                          mtb_hal_sdio_host_transfer_type_t direction,
                                          uint32_t argument, const uint32_t* data, uint16_t length,
                                          uint32_t* response);

/** Set the voltage level of the I/O line
 *
 * This function changes the logic level on the io_volt_sel pin. It assumes that this
 * line is used to control a regulator connected to the VDDIO of the MCU.
 * This regulator allows for switching between the 3.3V and 1.8V signaling. High level on the pin
 * stands for
 * 1.8V signaling, while low - for 3.3V.
 *
 * @param[in]  obj                  The SDIO host object
 * @param[in]  io_voltage           I/O voltage to be set on lines
 * @param[in]  io_switch_type       Defines how I/O voltage will be switched
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdio_host_set_io_voltage(mtb_hal_sdio_t* obj,
                                           mtb_hal_sdio_host_io_voltage_t io_voltage,
                                           mtb_hal_sdio_host_io_volt_action_type_t io_switch_type);

#endif /* (MTB_HAL_DRIVER_AVAILABLE_SDIO_HOST) */

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_SDIO_IMPL_HEADER
#include MTB_HAL_SDIO_IMPL_HEADER
#endif /* MTB_HAL_SDIO_IMPL_HEADER */

#endif //defined(MTB_HAL_DRIVER_AVAILABLE_SDIO)

/** \} group_hal_sdio */

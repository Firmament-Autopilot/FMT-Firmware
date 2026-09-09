/***************************************************************************//**
* \file mtb_hal_sdhc.h
*
* \brief
* Provides a high level interface for interacting with the Infineon SDHC.
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
 * \addtogroup group_hal_sdhc SDHC (SD Host Controller)
 * \ingroup group_hal
 * \{
 * High level interface to the Secure Digital Host Controller (SDHC).
 *
 * The SDHC driver allows data to be read from and written to an SD Card using the SDHC block.
 * The data is transferred in blocks with a block size of 512 bytes.
 *
 * \section subsection_sdhc_features Features
 * * Supports the 4-bit interface
 * * Supports Ultra High Speed (UHS-I) mode
 * * Supports Default Speed (DS), High Speed (HS), SDR12, SDR25 and SDR50 speed modes
 *
 * \section subsection_sdhc_quickstart Quick Start
 * Initialize SDHC by using Device Configurator and selecting the pins according to the target
 * device used.
 * Specify the SDHC configuration using the configuration structure (const \ref
 * mtb_hal_sdhc_configurator_t * config). <br>
 * See \ref subsection_sdhc_snippet_1
 *
 * \section subsection_sdhc_code_snippets Code Snippets
 *
 * \subsection subsection_sdhc_snippet_1 Snippet 1: SDHC Initialization and configuration
 * The following snippet is used to initialize the SDHC block. SDHC object - \ref mtb_hal_sdhc_t,
 * SDHC card configuration structure (const \ref mtb_hal_sdhc_config_t * config). The pins connected
 * to the SDHC block needs to be provided by the design.modus file after using Device Configurator.
 * \snippet hal_sdhc.c snippet_mtb_hal_sdhc_setup
 *
 * \subsection subsection_sdhc_snippet_2 Snippet 2: Reading a block of data from an SD Card
 * The following snippet reads a block of data from the SD Card. The setup steps from \ref
 * subsection_sdhc_snippet_1 must be followed before reading.
 * \snippet hal_sdhc.c snippet_mtb_hal_sdhc_read_async

 * \subsection subsection_sdhc_snippet_3 Snippet 3: Writing a block of data to an SD Card
 * The following snippet writes a block of data to the SD Card. The setup steps from \ref
 * subsection_sdhc_snippet_1 must be followed before writing.
 * \snippet hal_sdhc.c snippet_mtb_hal_sdhc_write_async

 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_SDHC)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*       Defines
*******************************************************************************/

/** \addtogroup group_hal_results_sdhc SDHC HAL Results
 *  SDHC specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Requested feature is not supported on this hardware. */
#define MTB_HAL_SDHC_RSLT_ERR_UNSUPPORTED                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 0))
/** Timeout during waiting for erase complete. */
#define MTB_HAL_SDHC_RSLT_ERR_ERASE_CMPLT_TIMEOUT         \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 1))
/** Block count cannot be retrieved. */
#define MTB_HAL_SDHC_RSLT_ERR_BLOCK_COUNT_GET_FAILURE     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 2))
/** Cannot set desired SD bus frequency. */
#define MTB_HAL_SDHC_RSLT_ERR_SET_FREQ                    \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 3))
/** Incorrect function parameter. */
#define MTB_HAL_SDHC_RSLT_ERR_WRONG_PARAM                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 4))
/** Error occured during I/O voltage switch sequence. */
#define MTB_HAL_SDHC_RSLT_ERR_IO_VOLT_SWITCH_SEQ          \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 5))
/** Cannot configure data timeout. */
#define MTB_HAL_SDHC_RSLT_ERR_TOUT_CFG                    \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 6))
/** Cannot make changes in user provided clock configuration or provided clock is incorrect. */
#define MTB_HAL_SDHC_RSLT_ERR_CLOCK                       \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SDHC, 7))

/**
 * \}
 */

/*******************************************************************************
*       Enumerations
*******************************************************************************/

/** Card types */
typedef enum
{
    MTB_HAL_SDHC_SD,                              //!< Secure Digital card
    MTB_HAL_SDHC_SDIO,                            //!< SD Input Output card
    MTB_HAL_SDHC_EMMC,                            //!< Embedded Multimedia card
    MTB_HAL_SDHC_COMBO,                           //!< Combo Card (SD + SDIO)
    MTB_HAL_SDHC_UNUSABLE,                        //!< Unusable card or unsupported type
    MTB_HAL_SDHC_NOT_EMMC                         //!< Not an eMMC card
} mtb_hal_sdhc_card_type_t;

/** I/O voltage levels */
typedef enum
{
    MTB_HAL_SDHC_IO_VOLTAGE_3_3V                  = 0U,   //!< I/O voltage is 3.3V.
    MTB_HAL_SDHC_IO_VOLTAGE_1_8V                  = 1U    //!< I/O voltage is 1.8V.
} mtb_hal_sdhc_io_voltage_t;

/** SDHC I/O voltage select principle */
typedef enum
{
    //! (Recommended) HAL driver performs all steps, needed for switching I/O bus voltage to certain
    //! level: sends needed commands to prepare card, changes level of io_volt_sel pin and performs
    //! switching sequence according to SD specification.
    MTB_HAL_SDHC_IO_VOLT_ACTION_NEGOTIATE         = 0U,
    //! HAL driver performs switching sequence (if voltage is being switched to 1.8V) and changes
    //! io_volt_sel pin level accordingly. No commands are being send to the card in this mode.
    MTB_HAL_SDHC_IO_VOLT_ACTION_SWITCH_SEQ_ONLY   = 1U,
    //! I/O voltage is changed by changing io_volt_sel pin's level. No commands are being send to
    //! the card in this mode.
    MTB_HAL_SDHC_IO_VOLT_ACTION_NONE              = 2U
} mtb_hal_sdhc_io_volt_action_type_t;

/** SDHC response types */
typedef enum
{
    MTB_HAL_SDHC_RESPONSE_NONE        = 0U,       //!< No Response.
    MTB_HAL_SDHC_RESPONSE_LEN_136     = 1U,       //!< Response Length 136.
    MTB_HAL_SDHC_RESPONSE_LEN_48      = 2U,       //!< Response Length 48.
    MTB_HAL_SDHC_RESPONSE_LEN_48B     = 3U        //!< Response Length 48. Check Busy
                                                  //!< after response.
} mtb_hal_sdhc_cmd_response_type_t;

/** SDHC auto command enable selection. */
typedef enum
{
    MTB_HAL_SDHC_AUTO_CMD_NONE        = 0U,       //!< Auto command disable.
    MTB_HAL_SDHC_AUTO_CMD_12          = 1U,       //!< Auto command 12 enable.
    MTB_HAL_SDHC_AUTO_CMD_23          = 2U,       //!< Auto command 23 enable.
    MTB_HAL_SDHC_AUTO_CMD_AUTO        = 3U        //!< Auto command Auto enable.
} mtb_hal_sdhc_auto_cmd_t;

/** SDHC command types */
typedef enum
{
    MTB_HAL_SDHC_CMD_NORMAL           = 0U,       //!< Other commands.
    MTB_HAL_SDHC_CMD_SUSPEND          = 1U,       //!< CMD52 for writing "Bus Suspend" in CCCR.
    MTB_HAL_SDHC_CMD_RESUME           = 2U,       //!< CMD52 for writing "Function Select" in CCCR.
    MTB_HAL_SDHC_CMD_ABORT            = 3U        //!< CMD12, CMD52 for writing "I/O Abort" in CCCR.
} mtb_hal_sdhc_cmd_type_t;

/** SDHC command error states */
typedef enum
{
    /** Last operation did not cause any error status. */
    MTB_HAL_SDHC_NO_ERR               = 0x0000U,
    /** Command timeout error. In SD/eMMC Mode, this event is set only if no response is returned
     * within 64 SD clock cycles from the end bit of the command. If the Host Controller detects a
     * CMD line conflict, along with Command CRC Error bit, this event is set to 1, without waiting
     * for 64 SD/eMMC card clock cycles. */
    MTB_HAL_SDHC_CMD_TOUT_ERR         = 0x0001U,
    /** Command CRC error. A Command CRC Error is generated in SD/eMMC mode when:
     * 1. A response is returned and the Command Timeout Error is set to 0 (indicating no timeout),
     * this bit is set to 1 when detecting a CRC error in the command response.
     * 2. The Host Controller detects a CMD line conflict by monitoring the CMD line when a command
     * is issued. If the Host Controller drives the CMD line to level 1, but detects level 0 on the
     * CMD line at the next SD clock edge, then the Host Controller aborts the command (stop driving
     * CMD line) and sets this bit to 1. The Command Timeout Error is also set to 1 to distinguish a
     * CMD line conflict. */
    MTB_HAL_SDHC_CMD_CRC_ERR          = 0x0002U,
    /** Command End Bit error. This bit is set after detecting that the end bit of a command
       response is 0 in SD/eMMC mode. */
    MTB_HAL_SDHC_CMD_END_BIT_ERR      = 0x0004U,
    /** Command Index error. This bit is set if a Command Index error occurs in the command response
       in SD/eMMC mode. */
    MTB_HAL_SDHC_CMD_IDX_ERR          = 0x0008U,
    /** Data Timeout error. This bit is set in SD/eMMC mode when detecting one of the following
       timeout conditions:
     * *  Busy timeout for R1b, R5b type
     * *  Busy timeout after Write CRC status
     * *  Write CRC Status timeout
     * *  Read Data timeout. */
    MTB_HAL_SDHC_DATA_TOUT_ERR        = 0x0010U,
    /** Data CRC error. This error occurs in SD/eMMC mode after detecting a CRC error while
     * transferring read data that uses the DAT line, detecting the Write CRC status having
     * a value other than 010 or when writing a CRC status timeout. */
    MTB_HAL_SDHC_DATA_CRC_ERR         = 0x0020U,
    /** Data End Bit error. This error occurs in SD/eMMC mode either when detecting 0 at the end bit
       position of read data that uses the DAT line or at the end bit position of the CRC status. */
    MTB_HAL_SDHC_DATA_END_BIT_ERR     = 0x0040U,
    /** Current Limit error. */
    MTB_HAL_SDHC_CUR_LMT_ERR          = 0x0080U,
    /** Auto CMD error. This error status is used by Auto CMD12 and Auto CMD23 in SD/eMMC mode. This
    * bit is set after detecting that any of the bits D00 to D05 in the Auto CMD Error Status
    * register has changed from 0 to 1. D07 is effective in case for Auto CMD12. The Auto CMD Error
    * Status register is valid while this bit is set to 1 and may be cleared by clearing this bit.*/
    MTB_HAL_SDHC_AUTO_CMD_ERR         = 0x0100U,
    /** ADMA error. This bit is set when the Host Controller detects an error during an ADMA-based
       data transfer.
     * The possible reasons for an error:
     * * An error response is received from the System bus;
     * * ADMA3, ADMA2 Descriptors are invalid;
     * * CQE Task or Transfer descriptors are invalid.
     * When an error occurs, the state of the ADMA is saved in the ADMA Error Status register. */
    MTB_HAL_SDHC_ADMA_ERR             = 0x0200U,
    /** Tuning error. */
    MTB_HAL_SDHC_TUNNING_ERR          = 0x0400U,
    /** Response error. Host Controller Version 4.00 supports the response error check function to
     * avoid overhead of the response error check by Host Driver during DMA execution. If the
     * Response Error Check Enable is set to 1 in the Transfer Mode register, the Host Controller
     * checks R1 or R5 response. If an error is detected in a response, this bit is set to 1.
     * This is applicable in SD/eMMC mode. */
    MTB_HAL_SDHC_RESP_ERR             = 0x0800U,
    /** Boot Acknowledgement error. This bit is set when there is a timeout for boot acknowledgement
     * or after detecting the boot ACK status having a value other than 010. This is applicable only
     * when boot acknowledgement is expected in eMMC mode. */
    MTB_HAL_SDHC_BOOT_ACK_ERR         = 0x1000U
} mtb_hal_sdhc_error_type_t;

/*******************************************************************************
*       Typedefs
*******************************************************************************/

/*******************************************************************************
*       Data Structures
*******************************************************************************/

/** Defines configuration options for the SDHC block */
typedef struct
{
    //! Drive one IO to indicate when the card is being accessed
    bool                            enableLedControl;
    //! Whether 1.8V signaling is supported
    bool                            lowVoltageSignaling;
    //! true if eMMC card, otherwise false
    bool                            isEmmc;
    //! The desired bus width, 1-bit, 4-bit, 8-bit
    uint8_t                         busWidth;
} mtb_hal_sdhc_config_t;

/** Defines data configuration */
typedef struct
{
    //! The pointer to data for send/receive. Data will be transfered using DMA, which will be
    //! configured automaticaly by SDHC HAL driver.
    uint32_t*                       data_ptr;
    //! The size of the data block
    uint32_t                        block_size;
    //! The number of blocks with size block_size to send. Selects which auto commands are used if
    //! any.
    uint32_t                        number_of_blocks;
    mtb_hal_sdhc_auto_cmd_t         auto_command;
    //! true = Read from the card,false = Write to the card.
    bool                            is_read;
} mtb_hal_sdhc_data_config_t;

/** Defines command configuration for \ref mtb_hal_sdhc_send_cmd function */
typedef struct
{
    //! The index of the command.
    uint32_t                        command_index;
    //! The argument for the command.
    uint32_t                        command_argument;
    //! Enables the CRC check on the response.
    bool                            enable_crc_check;
    //! The response type.
    mtb_hal_sdhc_cmd_response_type_t  response_type;
    //! Checks the index of the response.
    bool                            enable_idx_check;
    //! The command type.
    mtb_hal_sdhc_cmd_type_t           command_type;
    //! Data transfer configuration, defined in \ref mtb_hal_sdhc_data_config_t. Should be NULL if
    //! data transfer is not expected for provided command.
    mtb_hal_sdhc_data_config_t* data_config;
} mtb_hal_sdhc_cmd_config_t;

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
 * @param[in] clock  The HAL clock object that is connected to this peripheral instance
 * @param[in] sdhc_host_context The context for the sdhc instance allocated by the user
 * @return the status of the HAL setup
 */
cy_rslt_t mtb_hal_sdhc_setup(mtb_hal_sdhc_t* obj, const mtb_hal_sdhc_configurator_t* config,
                             const mtb_hal_clock_t* clock,
                             cy_stc_sd_host_context_t* sdhc_host_context);

/** Erases a block of data over the SDHC peripheral
 *
 * @param[in] obj                   The SDHC object
 * @param[in] start_addr            Is the address of the first byte to erase
 * @param[in] length                Number of 512 byte blocks (starting at start_addr) to erase
 * @param[in] timeout_ms            Timeout value in ms for waiting/polling operations. If zero
 *                                  is provided for this parameter the default value will be used.
 *                                  See implementation specific documentation for timeout details.
 * @return The status of the erase request
 *
 */
cy_rslt_t mtb_hal_sdhc_erase(mtb_hal_sdhc_t* obj, uint32_t start_addr, size_t length,
                             uint32_t timeout_ms);

/** Start SDHC asynchronous read
 *
 * This will transfer `length` 512 byte blocks into the buffer pointed to by `data` in
 * the background.  When the requested quantity of data has been read, the
 * \ref mtb_hal_sdhc_wait_transfer_complete function returns true.
 *
 * @param[in]     obj               The SDHC object that holds the transfer information
 * @param[in]     address           The address to read data from
 * @param[out]    data              The receive buffer
 * @param[in,out] length            Number of 512 byte blocks to read, updated with the number
 *                                  actually read
 * @return The status of the read_async request
 */
cy_rslt_t mtb_hal_sdhc_read_async(mtb_hal_sdhc_t* obj, uint32_t address, uint8_t* data,
                                  size_t* length);

/** Start asynchronous SDHC write
 *
 * This will transfer `length` 512 byte blocks from the buffer pointed to by `data` in
 * the background. When the requested quantity of data has been written, the
 * \ref mtb_hal_sdhc_wait_transfer_complete function returns true.
 *
 * @param[in]     obj               The SDHC object that holds the transfer information
 * @param[in]     address           The address to write data to
 * @param[in]     data              The transmit buffer
 * @param[in,out] length            The number of 512 byte blocks to write, updated with the number
 *                                  actually written
 * @return The status of the write_async request
 */
cy_rslt_t mtb_hal_sdhc_write_async(mtb_hal_sdhc_t* obj, uint32_t address, const uint8_t* data,
                                   size_t* length);

/** Checks if SD card is inserted
 *
 * @param[in]  obj                  The SDHC peripheral to check
 * @return Indication of whether the card is inserted.
 */
bool mtb_hal_sdhc_is_card_inserted(const mtb_hal_sdhc_t* obj);

/** Checks if the inserted SD card is mechanically write protected
 *
 * @param[in]  obj                  The SDHC peripheral to check
 * @return Indication of whether the inserted SD card is mechanically write protected
 */
bool mtb_hal_sdhc_is_card_mech_write_protected(const mtb_hal_sdhc_t* obj);

/** Get block count of inserted SD card / eMMC
 * \note SDHC driver should be initialized prior to using this function.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  block_count          Pointer to variable where block count will be stored
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_get_block_count(mtb_hal_sdhc_t* obj, uint32_t* block_count);

/** Sets the SD bus frequency (frequency on which SD card / eMMC is accessed)
 * \note Actual frequency may differ from the desired frequency due to available dividers and the
 * frequency of source clock.
 * Function will set the closest possible (but not greater than) frequency to what was requested.
 * Use \ref mtb_hal_sdhc_get_frequency function to get actual frequency value that was achieved
 * and set.
 * \note If data timeout was configured by \ref mtb_hal_sdhc_set_data_read_timeout, it can be
 * automaticaly recalculated according to new SD bus frequency. For details, please refer to \ref
 * mtb_hal_sdhc_set_data_read_timeout function description.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  hz                   Desired SD bus frequency in Hz
 * @param[in]  negotiate            Whether new frequency value needs to be negotiated with card or
 *                                  not. true is recommended and it means that new frequency will be
 *                                  negotiated.
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_set_frequency(mtb_hal_sdhc_t* obj, uint32_t hz, bool negotiate);

/** Get the actual frequency that SD bus is configured for
 *
 * @param[in] obj                   The SDHC object
 * @return Frequency in Hz
 */
uint32_t mtb_hal_sdhc_get_frequency(mtb_hal_sdhc_t* obj);

/** Sets the maximum time to wait for data from the card. The time is specified in number of card
 *  clock cycles.
 * With SD bus frequency changed by \ref mtb_hal_sdhc_set_frequency, timeout can automaticaly be
 * recalculated according
 * to new clock frequency. This can be activated by 'auto_reconfigure' parameter.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  timeout              Time to wait for data from the card.
 * @param[in]  auto_reconfigure     Timeout value will be automaticaly reconfigured upon
 *                                  clock change
 *
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_set_data_read_timeout(mtb_hal_sdhc_t* obj, uint32_t timeout,
                                             bool auto_reconfigure);

/**  Initializes the SD block and DMA for a data transfer. It does not start a transfer.
 * \ref mtb_hal_sdhc_send_cmd needs to be called after this function in order to start
 * data transfer.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  data_config          Data transfer configuration
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_config_data_transfer(mtb_hal_sdhc_t* obj,
                                            mtb_hal_sdhc_data_config_t* data_config);

/** Sends a command to the card and wait until it is sent. If the command assumes data transfer via
 *  data lines,
 * \ref mtb_hal_sdhc_config_data_transfer function needs to be called prior to this one. The
 * response of issued command can be retrieved by using \ref mtb_hal_sdhc_get_response function.
 * \note Function does not wait until data (configured with \ref mtb_hal_sdhc_config_data_transfer)
 * transfer complete.
 * In order to do so, user can use the \ref mtb_hal_sdhc_wait_transfer_complete function
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  cmd_config           Command configuration
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_send_cmd(mtb_hal_sdhc_t* obj, mtb_hal_sdhc_cmd_config_t* cmd_config);

/** Returns a response of last issued by \ref mtb_hal_sdhc_send_cmd function command.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  response             Pointer to array where response will be stored
 * @param[in]  large_response       If true, the expected response is 136 bits, false - 48 bits,
 *                                  which correspond to 120 and 32 bits of useful for application
 *                                  data respectively. So for large_response a 4 uint32_t element
 *                                  array can be used while for not large_response 1 uint32_t value
 *                                  will be enough.
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_get_response(mtb_hal_sdhc_t* obj, uint32_t* response, bool large_response);

/** Wait for asynchronous data transfer to complete. Such data transfer can be triggered by \ref
   mtb_hal_sdhc_write_async,
 * \ref mtb_hal_sdhc_read_async or by \ref mtb_hal_sdhc_config_data_transfer + \ref
 * mtb_hal_sdhc_send_cmd functions.
 *
 * @param[in]  obj                  The SDHC object
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_wait_transfer_complete(mtb_hal_sdhc_t* obj);

/** Sets the voltage level of the I/O lines.
 * \note This function requires io_volt_sel and (for some cases) card_pwr_en pins to be assigned.
 * Please refer to the device datasheet and PDL documentation for details.
 * \note Switching from 1.8V to 3.3V can be done only via power cycle sequence (power down card,
 * wait, power up card),
 *  which is supported by HAL driver and performed only if MTB_HAL_SDHC_IO_VOLT_ACTION_NEGOTIATE
 * selected. card_pwr_en pin has to be assigned. Please refer to the PDL documentation for details.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  io_voltage           I/O voltage to be set on lines
 * @param[in]  io_switch_type       Defines how I/O voltage will be switched
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_set_io_voltage(mtb_hal_sdhc_t* obj, mtb_hal_sdhc_io_voltage_t io_voltage,
                                      mtb_hal_sdhc_io_volt_action_type_t io_switch_type);

/** Returns the current voltage level of the I/O lines
 *
 * @param[in]   obj                 The SDHC object
 * @return Current I/O voltage setting value
 */
mtb_hal_sdhc_io_voltage_t mtb_hal_sdhc_get_io_voltage(mtb_hal_sdhc_t* obj);

/** Configures data bus width on host side and (optionally) informs the card about new width
 *  configuration.
 *
 * @param[in]  obj                  The SDHC object
 * @param[in]  bus_width            The desired bus width, 1-bit, 4-bit, 8-bit
 * @param[in]  configure_card       Whether card needs to be configured with new bus width.
 *                                  true is recommended.
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_set_bus_width(mtb_hal_sdhc_t* obj, uint8_t bus_width, bool configure_card);

/** Returns currently configured data bus width
 *
 * @param[in]  obj                  The SDHC object
 * @return Currently configured bus width, 1-bit, 4-bit, 8-bit
 */
uint8_t mtb_hal_sdhc_get_bus_width(mtb_hal_sdhc_t* obj);

/** Returns last issued SD operation error states. This function can be used for error checking
 *  after any of cmd / data
 * transfer-related operations. For list of possible errors, that are being tracked, please refer to
 * \ref mtb_hal_sdhc_error_type_t.
 *
 * @param[in]   obj                 The SDHC object
 * @return Errors occurred during last command
 */
mtb_hal_sdhc_error_type_t mtb_hal_sdhc_get_last_command_errors(mtb_hal_sdhc_t* obj);

/** Clears SDHC hardware error states. Error statuses are indicated by \ref
 *  mtb_hal_sdhc_get_last_command_errors function.
 *
 * @param[in]   obj                 The SDHC object
 */
void mtb_hal_sdhc_clear_errors(mtb_hal_sdhc_t* obj);

/** Resets CMD and Data lines and corresponding circuits of SD Host.
 *
 * @param[in]   obj                 The SDHC object
 */
void mtb_hal_sdhc_software_reset(mtb_hal_sdhc_t* obj);

/** Powers up / down the card based on provided parameter. This function uses card_pwr_en pin to
 * change card power state. Please refer to the device datasheet for pin description.
 *
 * @param[in]  obj                  The SDHC peripheral to configure
 * @param[in]  enable               Card is powered if true, not powered if false.
 * @return The status of the operation
 */
cy_rslt_t mtb_hal_sdhc_enable_card_power(mtb_hal_sdhc_t* obj, bool enable);

/**
 * Process interrupts related to an SDHC instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_sdhc_process_interrupt(mtb_hal_sdhc_t* obj);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_SDHC_IMPL_HEADER
#include MTB_HAL_SDHC_IMPL_HEADER
#endif /* MTB_HAL_SDHC_IMPL_HEADER */

#endif //defined(MTB_HAL_DRIVER_AVAILABLE_SDHC)

/** \} group_hal_sdhc */

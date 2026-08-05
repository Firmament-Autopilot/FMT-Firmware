/***************************************************************************//**
* \file mtb_hal_i2c.h
*
* \brief
* Provides a high level interface for interacting with the Infineon I2C.
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
 * \addtogroup group_hal_i2c I2C (Inter-Integrated Circuit)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the I2C resource.
 *
 * The I2C protocol is a synchronous serial interface protocol. This driver supports
 * both controller and target mode of operation. The communication frequency and address (for target
 * operation) can be configured.
 *
 * \section section_i2c_features Features
 *
 * * Controller or target functionality
 * * Configurable target address
 * * Configurable data rates
 * * Configurable interrupt and callback assignment from I2C events - \ref mtb_hal_i2c_event_t
 *
 * \section section_i2c_quickstart Quick Start
 * Configure the behavior (controller/target) and the interface (bus frequency, target address)
 * using the \ref mtb_hal_i2c_configure function. <br>
 * See \ref subsection_i2c_snippet_1 for example initialization as controller or target.
 * \note The clock parameter (const mtb_hal_clock_divider_t *clk) is optional and can be set
 * to NULL to generate and use an available clock resource with a default frequency
 * (MTB_HAL_I2C_CONTROLLER_DEFAULT_FREQ).
 *
 * \section section_i2c_snippets Code Snippets
 *
 * \subsection subsection_i2c_snippet_1 Snippet 1: I2C Initialization and Configuration
 * This snippet initializes an I2C resource as controller or target and assigns
 * the <b>sda</b> and <b>scl</b> pins.
 *
 * Initializing as I2C controller
 * \snippet hal_i2c.c snippet_mtb_hal_i2c_controller_init
 *
 * Initializing as I2C target
 * \snippet hal_i2c.c snippet_mtb_hal_i2c_target_init
 *
 * \subsection subsection_i2c_snippet_2 Snippet 2: Handling events
 * This snippet shows how to enable and handle I2C events using \ref mtb_hal_i2c_enable_event and
 * \ref mtb_hal_i2c_register_callback.<br>
 * The <b>callback</b> parameter of \ref mtb_hal_i2c_register_callback is used to pass the callback
 * handler that will be invoked when an event occurs.<br>
 * The <b>event</b> parameter of \ref mtb_hal_i2c_enable_event is used to pass the bitmasks of
 * events ( \ref mtb_hal_i2c_event_t) to be enabled.
 *
 * \snippet hal_i2c.c snippet_mtb_hal_handle_i2c_events
 *
 * \section subsection_i2c_moreinformation More Information
 *
 * <b>Peripheral Driver Library (PDL)</b>
 * * <a
 * href="https://infineon.github.io/psoc6pdl/pdl_api_reference_manual/html/group__group__scb.html"><b>
   PSOC™ 6 PDL: SCB (Serial Communication Block)</b></a>
 *
 * <b>Code examples (Github)</b>
 * * <a href="https://github.com/infineon/mtb-example-psoc6-i2c-controller" ><b>
   PSOC™ 6 MCU: I2C Controller</b></a>
 * * <a href="https://github.com/infineon/mtb-example-psoc6-i2c-target-callback" ><b>
   PSOC™ 6 MCU: I2C Target Using Callbacks</b></a>
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_I2C)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_i2c I2C HAL Results
 *  I2C specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Can not reach desired data rate */
#define MTB_HAL_I2C_RSLT_ERR_CAN_NOT_REACH_DR             \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_I2C, 0))
/** Bad argument provided */
#define MTB_HAL_I2C_RSLT_ERR_BAD_ARGUMENT                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_I2C, 1))
/** Unsupported by this device */
#define MTB_HAL_I2C_RSLT_ERR_UNSUPPORTED                  \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_I2C, 2))
/** RX or TX Buffer is not initialized */
#define MTB_HAL_I2C_RSLT_ERR_BUFFERS_NULL_PTR             \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_I2C, 3))

/** Timeout warning */
#define MTB_HAL_I2C_RSLT_WARN_TIMEOUT                     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_WARNING, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_I2C, 20))
/** Other operation in progress */
#define MTB_HAL_I2C_RSLT_WARN_DEVICE_BUSY                 \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_WARNING, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_I2C, 21))

/**
 * \}
 */

/** Named define for Target mode for use when initializing the \ref mtb_hal_i2c_cfg_t structure. */
#define MTB_HAL_I2C_MODE_TARGET (true)
/** Named define for Controller mode for use when initializing the \ref mtb_hal_i2c_cfg_t structure.
 */
#define MTB_HAL_I2C_MODE_CONTROLLER (false)
/** Named define for default address mask for use when initializing the \ref mtb_hal_i2c_cfg_t
   structure. */
#define MTB_HAL_I2C_DEFAULT_ADDR_MASK (0xFE)

/** I2C enum to enable/disable/report event cause flags. */
typedef enum
{
    /** No event */
    MTB_HAL_I2C_EVENT_NONE               = 0,
    /** Indicates that the target was addressed and the controller wants to read data. */
    MTB_HAL_I2C_TARGET_READ_EVENT         = (MTB_HAL_MAP_I2C_TARGET_READ_EVENT),
    /** Indicates that the target was addressed and the controller wants to write data. */
    MTB_HAL_I2C_TARGET_WRITE_EVENT        = (MTB_HAL_MAP_I2C_TARGET_WRITE_EVENT),
    /** All target data from the configured Read buffer has been loaded into the TX FIFO. */
    MTB_HAL_I2C_TARGET_RD_IN_FIFO_EVENT   = (MTB_HAL_MAP_I2C_TARGET_RD_IN_FIFO_EVENT),
    /** The controller has read all data out of the configured Read buffer. */
    MTB_HAL_I2C_TARGET_RD_BUF_EMPTY_EVENT = (MTB_HAL_MAP_I2C_TARGET_RD_BUF_EMPTY_EVENT),
    /** Indicates the controller completed reading from the target
     * (set by the controller NAK or Stop) */
    MTB_HAL_I2C_TARGET_RD_CMPLT_EVENT     = (MTB_HAL_MAP_I2C_TARGET_RD_CMPLT_EVENT),
    /** Indicates the controller completed writing to the target
     * (set by the controller Stop or Restart)*/
    MTB_HAL_I2C_TARGET_WR_CMPLT_EVENT     = (MTB_HAL_MAP_I2C_TARGET_WR_CMPLT_EVENT),
    /** Indicates the I2C target detected an error. */
    MTB_HAL_I2C_TARGET_ERR_EVENT          = (MTB_HAL_MAP_I2C_TARGET_ERR_EVENT),
    /** Indicates that the target received a restart bit */
    MTB_HAL_I2C_TARGET_RESTART_EVENT      = (MTB_HAL_MAP_I2C_TARGET_RESTART_EVENT),
    /** Indicates that the target received a stop bit */
    MTB_HAL_I2C_TARGET_STOP_EVENT         = (MTB_HAL_MAP_I2C_TARGET_STOP_EVENT),
    /** Indicates that the target detected an arbitration lost event */
    MTB_HAL_I2C_TARGET_ARB_LOST_EVENT     = (MTB_HAL_MAP_I2C_TARGET_ARB_LOST_EVENT),
    /** Indicates that the target detected a timeout from counter 0 */
    MTB_HAL_I2C_TARGET_TIMEOUT0_EVENT     = (MTB_HAL_MAP_I2C_TARGET_TIMEOUT0_EVENT),
    /** Indicates that the target detected a timeout from counter 1 */
    MTB_HAL_I2C_TARGET_TIMEOUT1_EVENT     = (MTB_HAL_MAP_I2C_TARGET_TIMEOUT1_EVENT),
    /** Indicates that the target detected a timeout from counter 2 */
    MTB_HAL_I2C_TARGET_TIMEOUT2_EVENT     = (MTB_HAL_MAP_I2C_TARGET_TIMEOUT2_EVENT),
    /** Indicates the I2C controller detected an error. */
    MTB_HAL_I2C_CONTROLLER_ERR_EVENT      = (MTB_HAL_MAP_I2C_CONTROLLER_ERR_EVENT),
    /** Indicates that the controller detected an arbitration lost event */
    MTB_HAL_I2C_CONTROLLER_ARB_LOST_EVENT = (MTB_HAL_MAP_I2C_CONTROLLER_ARB_LOST_EVENT),
    /** Indicates that the controller detected a timeout from counter 0 */
    MTB_HAL_I2C_CONTROLLER_TIMEOUT0_EVENT = (MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT0_EVENT),
    /** Indicates that the controller detected a timeout from counter 1 */
    MTB_HAL_I2C_CONTROLLER_TIMEOUT1_EVENT = (MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT1_EVENT),
    /** Indicates that the controller detected a timeout from counter 2 */
    MTB_HAL_I2C_CONTROLLER_TIMEOUT2_EVENT = (MTB_HAL_MAP_I2C_CONTROLLER_TIMEOUT2_EVENT)
} mtb_hal_i2c_event_t;

/** I2C enum to enable/disable/report address interrupt cause flags. */
typedef enum
{
    /** No event */
    MTB_HAL_I2C_ADDR_EVENT_NONE    = 0,
    /** Indicates the target was addressed by the general call address. */
    MTB_HAL_I2C_GENERAL_CALL_EVENT = (MTB_HAL_MAP_I2C_GENERAL_CALL_EVENT),
    /** Indicates the target matching address received. */
    MTB_HAL_I2C_ADDR_MATCH_EVENT   = (MTB_HAL_MAP_I2C_ADDR_IN_FIFO_EVENT)
} mtb_hal_i2c_addr_event_t;

/** I2C FIFO type */
typedef enum
{
    MTB_HAL_I2C_FIFO_RX, //!< Set RX FIFO level
    MTB_HAL_I2C_FIFO_TX  //!< Set TX FIFO level
} mtb_hal_i2c_fifo_type_t;

/** I2C Command ACK / NAK */
typedef enum
{
    MTB_HAL_I2C_CMD_ACK, //!< Send ACK to current byte
    MTB_HAL_I2C_CMD_NAK  //!< Send NAK to current byte
} mtb_hal_i2c_command_rsp_t;

/** Enum of possible output signals from an I2C */
typedef enum
{
    MTB_HAL_I2C_OUTPUT_TRIGGER_RX_FIFO_LEVEL_REACHED, //!< Output the RX FIFO signal which is
                                                      //!< triggered when the receive FIFO has more
                                                      //!< entries than the configured level.
    MTB_HAL_I2C_OUTPUT_TRIGGER_TX_FIFO_LEVEL_REACHED  //!< Output the TX FIFO signal which is
                                                      //!< triggered when the transmit FIFO has less
                                                      //!< entries than the configured level.
} mtb_hal_i2c_output_t;

/** Handler for I2C events */
typedef void (* mtb_hal_i2c_event_callback_t)(void* callback_arg, mtb_hal_i2c_event_t event);
/** Handler for I2C address events */
typedef mtb_hal_i2c_command_rsp_t (* mtb_hal_i2c_address_callback_t)(void* callback_arg,
                                                                     mtb_hal_i2c_addr_event_t event,
                                                                     uint8_t address);
/** Handler for I2C byte received events */
typedef mtb_hal_i2c_command_rsp_t (* mtb_hal_i2c_byte_callback_t)(void* callback_arg,
                                                                  uint8_t byte_received);

/** @brief I2C configuration */
typedef struct
{
    bool     is_target;                 /**<  Operates as a target when set to (<b>true</b>), else
                                              as a controller (<b>false</b>). */
    uint16_t address;                   /**<  Address of this target resource (7-bit), should be set
                                              to 0 for controller */
    uint32_t frequency_hz;              /**<  Frequency that the I2C bus runs at (I2C data rate in
                                              bits per second) */
    uint8_t  address_mask;              /**<  Mask of the target resource. Not applicable for the
                                              controller. */
    bool     enable_address_callback;   /**<  Indicates address callback feature is enabled or
                                              disable. When it's true the address callback will be
                                              invoked. */
} mtb_hal_i2c_cfg_t;

/** Configure the I2C block.
 * \note Controller/Target specific functions only work when the block is configured
 * to be in that mode.<br>
 * See \ref subsection_i2c_snippet_1
 *
 * @param[in] obj     The I2C object
 * @param[in] cfg     Configuration settings to apply
 * @return The status of the configure request
 *
 */
cy_rslt_t mtb_hal_i2c_configure(mtb_hal_i2c_t* obj, const mtb_hal_i2c_cfg_t* cfg);

/**
 * I2C controller blocking write
 *
 * This will write `size` bytes of data from the buffer pointed to by `data`. It will not return
 * until either all of the data has been written, or the timeout has elapsed.
 *
 * @param[in]  obj        The I2C object
 * @param[in]  dev_addr   device address (7-bit)
 * @param[in]  data       I2C send data
 * @param[in]  size       I2C send data size
 * @param[in]  timeout    timeout in millisecond, set this value to 0 if you want to wait forever
 * @param[in]  send_stop  whether the stop should be send, used to support repeat start conditions
 *
 * @return The status of the controller_write request
 */
cy_rslt_t mtb_hal_i2c_controller_write(mtb_hal_i2c_t* obj, uint16_t dev_addr, const uint8_t* data,
                                       uint16_t size, uint32_t timeout, bool send_stop);

/**
 * I2C controller blocking read
 *
 * This will read `size` bytes of data into the buffer pointed to by `data`. It will not return
 * until either all of the data has been read, or the timeout has elapsed.
 *
 * @param[in]   obj        The I2C object
 * @param[in]   dev_addr   device address (7-bit)
 * @param[out]  data       I2C receive data
 * @param[in]   size       I2C receive data size
 * @param[in]   timeout    timeout in millisecond, set this value to 0 if you want to wait forever
 * @param[in]   send_stop  whether the stop should be send, used to support repeat start conditions
 *
 * @return The status of the controller_read request
 */
cy_rslt_t mtb_hal_i2c_controller_read(mtb_hal_i2c_t* obj, uint16_t dev_addr, uint8_t* data,
                                      uint16_t size, uint32_t timeout, bool send_stop);

/**
 * The function configures the read buffer on an I2C Target. This is the buffer that the target
 * recieves data into. The user needs to setup a new buffer every time (i.e. call \ref
 * mtb_hal_i2c_target_config_write_buffer and \ref mtb_hal_i2c_target_config_read_buffer
 * every time the buffer has been used up)<br>
 * See related code example: <a href="https://github.com/infineon/mtb-example-psoc6-i2c-controller"
 * ><b>PSOC™ 6 MCU: I2C Controller</b></a>
 *
 * @param[in]  obj      The I2C object
 * @param[in]  data     I2C target receive data buffer
 * @param[in]  size     I2C target receive data buffer size
 *
 * @return The status of the target_config_read_buffer request
 */
cy_rslt_t mtb_hal_i2c_target_config_read_buffer(mtb_hal_i2c_t* obj, const uint8_t* data,
                                                uint16_t size);

/**
 * The function configures the write buffer on an I2C Target. This is the buffer that stores data
 * to be written to the controller.
 * The user needs to setup a new buffer every time (i.e. call \ref
 * mtb_hal_i2c_target_config_write_buffer and \ref mtb_hal_i2c_target_config_read_buffer
 * every time the buffer has been used up)<br>
 * See related code example: <a href="https://github.com/infineon/mtb-example-psoc6-i2c-controller"
 * ><b>PSOC™ 6 MCU: I2C Controller</b></a>
 *
 * @param[in]   obj      The I2C object
 * @param[out]  data     I2C target write data buffer
 * @param[in]   size     I2C target write data buffer size
 *
 * @return The status of the target_config_write_buffer request
 */
cy_rslt_t mtb_hal_i2c_target_config_write_buffer(mtb_hal_i2c_t* obj, uint8_t* data, uint16_t size);

/** Register an I2C event callback handler<br>
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_i2c_enable_event
 * occurs.
 *
 * See \ref subsection_i2c_snippet_2
 *
 * @param[in] obj          The I2C object
 * @param[in] callback     The callback handler which will be invoked when an event triggers
 * @param[in] callback_arg Generic argument that will be provided to the callback when called
 *
 */
void mtb_hal_i2c_register_callback(mtb_hal_i2c_t* obj, mtb_hal_i2c_event_callback_t callback,
                                   void* callback_arg);

/** Register an I2C address callback handler<br>
 *
 * This function will be called when one of the events enabled by \ref
 * mtb_hal_i2c_enable_address_event occurs.
 * \note This function will not have an effect if enable_address_callback parameter of
 * \ref mtb_hal_i2c_cfg_t structure was false when \ref mtb_hal_i2c_configure was called.
 *
 * See \ref subsection_i2c_snippet_2
 *
 * @param[in] obj          The I2C object
 * @param[in] callback     The callback handler which will be invoked when an event triggers
 * @param[in] callback_arg Generic argument that will be provided to the callback when called
 *
 */
void mtb_hal_i2c_register_address_callback(mtb_hal_i2c_t* obj,
                                           mtb_hal_i2c_address_callback_t callback,
                                           void* callback_arg);

/** Register an I2C byte received callback handler<br>
 *
 * This function will be called when a byte is received. Either an ACK or a
 * NACK message will be sent depending on the returned value from the callback.
 *
 * @param[in] obj          The I2C object
 * @param[in] callback     The callback handler which will be invoked when the event triggers
 * @param[in] callback_arg Generic argument that will be provided to the callback when called
 *
 */
void mtb_hal_i2c_register_byte_received_callback(mtb_hal_i2c_t* obj,
                                                 mtb_hal_i2c_byte_callback_t callback,
                                                 void* callback_arg);

/** Configure and Enable or Disable I2C Interrupt.
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_i2c_register_callback will
 * be called.
 *
 * See \ref subsection_i2c_snippet_2
 *
 * @param[in] obj            The I2C object
 * @param[in] event          The I2C event type
 * @param[in] enable         True to turn on interrupts, False to turn off
 */
void mtb_hal_i2c_enable_event(mtb_hal_i2c_t* obj, mtb_hal_i2c_event_t event, bool enable);

/** Configure and Enable or Disable I2C Address Interrupt.
 *
 * When an enabled event occurs, the function specified by \ref
 * mtb_hal_i2c_register_address_callback will be called.
 *
 * See \ref subsection_i2c_snippet_2
 *
 * @param[in] obj            The I2C object
 * @param[in] event          The I2C address event type
 * @param[in] enable         True to turn on interrupts, False to turn off
 */
void mtb_hal_i2c_enable_address_event(mtb_hal_i2c_t* obj, mtb_hal_i2c_addr_event_t event,
                                      bool enable);

/** Returns the number of bytes written by the I2C controller.
 * Calling the \ref mtb_hal_i2c_target_config_read_buffer API will clear the counter of bytes sent
 * by controller
 *
 * @param[in]  obj          The I2C object
 * @return  The number of bytes written by the I2C controller.
 * */
uint32_t mtb_hal_i2c_target_readable(mtb_hal_i2c_t* obj);

/** Returns the number of bytes can be read by the I2C controller.
 * Calling the \ref mtb_hal_i2c_target_config_write_buffer API will clear the counter of bytes read
 * by controller
 *
 * @param[in]  obj          The I2C object
 * @return  The number of bytes can be read by the I2C controller.
 * */
uint32_t mtb_hal_i2c_target_writable(mtb_hal_i2c_t* obj);

/** Wait for controller send data to RX buffer and store them to the user-defined buffer.
 * \note If the read size requested is greater than the data available, the function only copies
 * the available data. The given buffer in dst_buff should match the one configured in
 * \ref mtb_hal_i2c_target_config_read_buffer to avoid additional copy operation.
 *
 * @param[in]     obj        The I2C object
 * @param[in]     dst_buff   Pointer on memory to store the data from the target RX buffer.
 * @param[in,out] size       [in] The number of bytes to read, [out] number actually read.
 * @param[in]     timeout    Timeout in millisecond, set this value to 0 if you don't want to wait
 * at all.
 * @return  The status of the read request
 * */
cy_rslt_t mtb_hal_i2c_target_read(mtb_hal_i2c_t* obj, uint8_t* dst_buff, uint16_t* size,
                                  uint32_t timeout);

/** Write data from the user-defined buffer to I2C TX buffer.
 * \note If the size of the data is greater than can fit the buffer, the function only copies data
 * that can fit. The given buffer in src_buff should match the one configured in
 * \ref mtb_hal_i2c_target_config_write_buffer to avoid additional copy operation.
 *
 * @param[in]     obj        The I2C object
 * @param[in]     src_buff   Pointer on memory to copy the data to the target TX buffer.
 * @param[in,out] size       [in] The number of bytes to send, [out] number actually sent.
 * @param[in]     timeout    Timeout in millisecond,  set this value to 0 if you don't want to wait
 * at all.
 * @return  The status of the write request
 * */
cy_rslt_t mtb_hal_i2c_target_write(mtb_hal_i2c_t* obj, const uint8_t* src_buff, uint16_t* size,
                                   uint32_t timeout);

/**
 * The function aborts the configured target read buffer to be read by the controller.
 * If the controller reads and "abort operation" is requested, the
 * \ref MTB_HAL_I2C_TARGET_RD_BUF_EMPTY_EVENT event occurs.
 *
 * @param[in]  obj                The I2C object
 *
 * @return The status of the target abort read request
 */
cy_rslt_t mtb_hal_i2c_target_abort_read(mtb_hal_i2c_t* obj);

/** Clear the I2C buffers
 *
 * @param[in]  obj        The I2C object
 * @return The status of the clear request
 * */
cy_rslt_t mtb_hal_i2c_clear(mtb_hal_i2c_t* obj);

/**
 * Process interrupts related related to an I2C instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_i2c_process_interrupt(mtb_hal_i2c_t* obj);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_I2C_IMPL_HEADER
#include MTB_HAL_I2C_IMPL_HEADER
#endif /* MTB_HAL_I2C_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_I2C)

/** \} group_hal_i2c */

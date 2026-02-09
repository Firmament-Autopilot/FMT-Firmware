/***************************************************************************//**
* \file mtb_hal_spi.h
*
* \brief
* Provides a high level interface for interacting with the Infineon SPI.
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
//" *SUSPEND-FORMATTING*"
/**
 * \addtogroup group_hal_spi SPI (Serial Peripheral Interface)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the Serial Peripheral Interface (SPI).
 *
 * The SPI protocol is a synchronous serial interface protocol. Devices operate
 * in either controller or target mode. The controller initiates the data transfer.
 *
 * \section section_spi_features Features
 * * Supports controller and target functionality.
 * * Controller supports up to four target select lines
 * * Configurable interrupt and callback assignment on SPI events:
 * Data transfer to FIFO complete, Transfer complete and Transmission error -
 * mtb_hal_spi_event_t
 * * Supports changing baud rate of the transaction in run time.
 * * Provides functions to send/receive a single byte or block of data.
 *
 * \section section_spi_quickstart Quick Start
 *
 * Initialise a SPI controller or target interface using the PDL.
 * The data rate can be set using \ref mtb_hal_spi_set_frequency(). <br>
 * See \ref section_spi_snippets for code snippets to send or receive the data.
 *
 * \section section_spi_snippets Code snippets
 *
 * \subsection subsection_spi_snippet_1 Snippet 1: SPI controller or target initialization
 * The following code snippet initializes an SPI Controller or Target interface using the PDL.
 * \snippet hal_spi.c snippet_mtb_hal_spi_initialization
 *
 * \subsection subsection_spi_snippet_2 Snippet 2: SPI controller - Single byte transfer operation (Read and Write)
 * The following code snippet initializes an SPI Controller interface using the PDL. The data rate
 * of transfer is set using \ref mtb_hal_spi_set_frequency(). The code snippet shows how to transfer
 * a single
 * byte of data using \ref mtb_hal_spi_put() and \ref mtb_hal_spi_get().
 * \snippet hal_spi.c snippet_mtb_hal_spi_controller_byte_operation
 *
 * \subsection subsection_spi_snippet_3 Snippet 3: SPI Target - Single byte transfer operation (Read and Write)
 * The following code snippet initializes an SPI Target interface using the PDL. The data rate of
 * transfer is set using \ref mtb_hal_spi_set_frequency. The code snippet shows how to transfer a
 * single byte of data using \ref mtb_hal_spi_put() and \ref mtb_hal_spi_get.
 * \snippet hal_spi.c snippet_mtb_hal_spi_target_byte_operation
 *
 * \subsection subsection_spi_snippet_4 Snippet 4: SPI Block Data transfer
 * The following snippet sends and receives an array of data in a single SPI transaction using \ref
 * mtb_hal_spi_transfer(). The example uses SPI controller to transmit 5 bytes of data and receive 5
 * bytes of data in a single transaction.
 * \snippet hal_spi.c snippet_mtb_hal_spi_block_data_transfer
 *
 * \subsection subsection_spi_snippet_5 Snippet 5: SPI Target - Write Block Data
 * The following snippet sends an array of data in a single SPI transaction using \ref
 * mtb_hal_spi_target_write(). The example uses SPI target to transmit 5 bytes of data in a single
 * transaction with 50 ms timeout values.
 * \snippet hal_spi.c snippet_mtb_hal_spi_target_write_block_data
 *
 * \subsection subsection_spi_snippet_6 Snippet 6: Interrupts on SPI events
 * SPI interrupt events (mtb_hal_spi_event_t) can be mapped to an interrupt and assigned to a
 * callback function. The callback function needs to be first registered and then the event needs to
 * be enabled. A callback function is registered using \ref mtb_hal_spi_register_callback to notify
 * whenever the SPI transfer is complete.
 * \snippet hal_spi.c snippet_mtb_hal_spi_interrupt_callback_events

 * \section subsection_spi_moreinfor More Information
 *
 * <a
 * href="https://github.com/infineon/mtb-example-psoc6-spi-controller"><b>mtb-example-psoc6-spi-controller</b></a>:
 * This example project demonstrates use of SPI (HAL) resource in PSOC® 6 MCU in Controller mode to
 * write data
 * to an SPI target.
 *
 */
//" *RESUME-FORMATTING*"
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_SPI)

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_hal_results_spi SPI HAL Results
 *  SPI specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */

/** Bad argument */
#define MTB_HAL_SPI_RSLT_BAD_ARGUMENT                     \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SPI, 0))
/** Failed to configure clock */
#define MTB_HAL_SPI_RSLT_CLOCK_ERROR                      \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SPI, 1))
/** Failed to Transfer SPI data */
#define MTB_HAL_SPI_RSLT_TRANSFER_ERROR                   \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_SPI, 2))

/**
 * \}
 */

/** SPI interrupt triggers */
typedef enum
{
    MTB_HAL_SPI_EVENT_NONE       = 0,                                  //!< No event
    MTB_HAL_SPI_IRQ_DATA_IN_FIFO = (MTB_HAL_MAP_SPI_IRQ_DATA_IN_FIFO), //!< All transfer data has
                                                                       //!< been moved into data
                                                                       //!< FIFO
    MTB_HAL_SPI_IRQ_DONE         = (MTB_HAL_MAP_SPI_IRQ_DONE),         //!< Transfer complete.
    MTB_HAL_SPI_IRQ_ERROR        = (MTB_HAL_MAP_SPI_IRQ_ERROR)         //!< An error occurred while
                                                                       //!< transferring data
} mtb_hal_spi_event_t;

/** Handler for SPI interrupts */
typedef void (* mtb_hal_spi_event_callback_t)(void* callback_arg, mtb_hal_spi_event_t event);

/** SPI FIFO type */
typedef enum
{
    MTB_HAL_SPI_FIFO_RX, //!< RX FIFO for incoming data
    MTB_HAL_SPI_FIFO_TX  //!< TX FIFO for outgoing datas
} mtb_hal_spi_fifo_type_t;

/** Enable/disable the SPI.
 *
 * The function returns without waiting for the enable to complete.
 *
 * @param[in] obj          The SPI object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_spi_enable(mtb_hal_spi_t* obj, bool enable);

/** Set the SPI baud rate
 *
 * Actual frequency may differ from the desired frequency due to available dividers and bus clock
 * Configures the SPI peripheral's baud rate
 * @param[in,out] obj The SPI object to configure
 * @param[in]     hz  The baud rate in Hz
 * @return The status of the set_frequency request
 */
cy_rslt_t mtb_hal_spi_set_frequency(mtb_hal_spi_t* obj, uint32_t hz);

/** Sets a threshold level for a FIFO that will generate an interrupt and a
 * trigger output. The RX FIFO interrupt and trigger will be activated when
 * the receive FIFO has more entries than the threshold. The TX FIFO interrupt
 * and trigger will be activated when the transmit FIFO has less entries than
 * the threshold.
 *
 * @param[in]  obj        The SPI object
 * @param[in]  type       FIFO type to set level for
 * @param[in]  level      Level threshold to set. See the device datasheet for valid range.
 * @return The status of the level set
 * */
cy_rslt_t mtb_hal_spi_set_fifo_level(mtb_hal_spi_t* obj, mtb_hal_spi_fifo_type_t type,
                                     uint16_t level);
/** Synchronously get a received value out of the SPI receive buffer
 *
 * In Controller mode - transmits fill-in value and read the data from RxFifo
 * In Target mode - Blocks until a value is available
 *
 * @param[in] obj   The SPI peripheral to read
 * @param[in] value The value received
 * @return The status of the read request
 * @note
 * - In Controller mode, CITO pin required to be non-NC for this API to operate
 * - In Target mode, COTI pin required to be non-NC for this API to operate
 */
cy_rslt_t mtb_hal_spi_get(mtb_hal_spi_t* obj, uint32_t* value);

/** Synchronously send a byte out
 *
 * In Controller mode transmits value to target and read/drop a value from the RxFifo.
 * In Target mode writes a value to TxFifo
 *
 * @param[in] obj   The SPI peripheral to use for sending
 * @param[in] value The value to send
 * @return The status of the write request
 * @note
 * - In Controller mode, COTI pin required to be non-NC for this API to operate
 * - In Target mode, CITO pin required to be non-NC for this API to operate
 */
cy_rslt_t mtb_hal_spi_put(mtb_hal_spi_t* obj, uint32_t value);

/** Write data from the user-defined buffer to the controller TX FIFO.
 * Performs non-blocking controller-mode transfer of an array of data.
 * NOTE: If the size of the actual data is less than the expected, the function will copy only the
 * available data and return.
 *
 * @param[in]     obj        The SPI object
 * @param[in]     src_buff   Pointer on memory to copy the data to the controller TX buffer.
 * @param[in,out] size       [in] The number of bytes to send, [out] number actually sent.
 * @return  The status of the write request
 * */
cy_rslt_t mtb_hal_spi_controller_write(mtb_hal_spi_t* obj, const uint8_t* src_buff, uint16_t* size);

/** Wait for controller send data to RX buffer and store them to the user-defined buffer.
 * NOTE: If size of actual data is less then expected the function copy only available data.
 *
 * @param[in]     obj        The SPI object
 * @param[in]     dst_buff   Pointer on memory to store the data from the target RX buffer.
 * @param[in,out] size       [in] The number of bytes to read, [out] number actually read.
 * @param[in]     timeout    Timeout in millisecond, set this value to 0 if you don't want to wait
 * at all.
 * @return  The status of the read request
 * */
cy_rslt_t mtb_hal_spi_target_read(mtb_hal_spi_t* obj, uint8_t* dst_buff, uint16_t* size,
                                  uint32_t timeout);

/** Write data from the user-defined buffer to TX buffer and wait until either all data has been
   read from
 * TX buffer and shift register, or timeout is hit.
 * The user needs to provide the interrupt handler and call \ref mtb_hal_spi_process_interrupt to
 * process the interrupt.
 *
 * NOTE: If size of actual data is less then expected the function copy only available data.
 *
 * @param[in]     obj        The SPI object
 * @param[in]     src_buff   Pointer on memory to copy the data to the target TX buffer.
 * @param[in,out] size       [in] The number of bytes to send, [out] number actually sent.
 * @param[in]     timeout    Timeout in millisecond,  set this value to 0 if you don't want to wait
 * at all.
 * @return  The status of the write request
 * */
cy_rslt_t mtb_hal_spi_target_write(mtb_hal_spi_t* obj, const uint8_t* src_buff, uint16_t* size,
                                   uint32_t timeout);

/** Synchronously Write a block out and receive a value
 *
 * The total number of bytes sent and received will be the maximum of tx_length
 * and rx_length. The bytes written will be padded (at the end) with the value
 * given by write_fill. Using this function will block for the duration of the transfer.
 * The user needs to provide the interrupt handler and call \ref mtb_hal_spi_process_interrupt to
 * process the interrupt.
 *
 * @param[in] obj           The SPI peripheral to use for sending
 * @param[in] tx            Pointer to the byte-array of data to write to the device
 * @param[in,out] tx_length Number of bytes to write, updated with the number actually written
 * @param[out] rx           Pointer to the byte-array of data to read from the device
 * @param[in,out] rx_length Number of bytes to read, updated with the number actually read
 * @param[in] write_fill    Default data transmitted while performing a read
 * @return The status of the transfer request
 * @note Both COTI and CITO pins required to be non-NC for this API to operate
 */
cy_rslt_t mtb_hal_spi_transfer(mtb_hal_spi_t* obj, const uint8_t* tx, size_t tx_length, uint8_t* rx,
                               size_t rx_length, uint8_t write_fill);

/** Clear the SPI buffers
 *
 * @param[in]  obj        The SPI object
 * @return The status of the clear request
 * */
cy_rslt_t mtb_hal_spi_clear(mtb_hal_spi_t* obj);


/** Register a SPI callback handler
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_spi_enable_event
 * occurs.
 *
 * @param[in] obj          The SPI object
 * @param[in] callback     The callback handler which will be invoked when the interrupt fires
 * @param[in] callback_arg Generic argument that will be provided to the callback when called
 */
void mtb_hal_spi_register_callback(mtb_hal_spi_t* obj, mtb_hal_spi_event_callback_t callback,
                                   void* callback_arg);

/** Configure SPI interrupt. This function is used for word-approach
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_spi_register_callback will
 * be called.
 *
 * @param[in] obj            The SPI object
 * @param[in] event          The SPI event type
 * @param[in] enable         True to turn on interrupts, False to turn off
 */
void mtb_hal_spi_enable_event(mtb_hal_spi_t* obj, mtb_hal_spi_event_t event, bool enable);

/**
 * Process interrupts related to a SPI instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_spi_process_interrupt(mtb_hal_spi_t* obj);

/** Wait for controller send data to RX buffer and store them to the user-defined buffer.
 * NOTE: If this function will returt on the timeout or all data was read or SS line is de-asserted.
 *
 * @param[in]     obj        The SPI object
 * @param[in]     dst_buff   Pointer on memory to store the data from the target RX buffer.
 * @param[in,out] size       [in] The number of bytes to read, [out] number actually read.
 * @param[in]     timeout    Timeout in millisecond, set this value to 0 if you don't want to wait
 * at all.
 * @return  The status of the read request
 * */
cy_rslt_t mtb_hal_spi_target_read_transaction(mtb_hal_spi_t* obj, uint8_t* dst_buff, uint16_t* size,
                                              uint32_t timeout);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_SPI_IMPL_HEADER
#include MTB_HAL_SPI_IMPL_HEADER
#endif /* MTB_HAL_SPI_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_SPI)

/** \} group_hal_spi */

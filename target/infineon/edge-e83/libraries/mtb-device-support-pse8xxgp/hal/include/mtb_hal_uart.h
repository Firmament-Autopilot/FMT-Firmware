/***************************************************************************//**
* \file mtb_hal_uart.h
*
* \brief
* Provides a high level interface for interacting with the Infineon UART.
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
 * \addtogroup group_hal_uart UART (Universal Asynchronous Receiver-Transmitter)
 * \ingroup group_hal
 * \{
 * High level interface for interacting with the Universal Asynchronous Receiver-Transmitter (UART).
 *
 * The Universal Asynchronous Receiver/Transmitter (UART) protocol is an
 * asynchronous serial interface protocol. UART communication is typically
 * point-to-point. The UART interface consists of two signals:
 * * TX: Transmitter output
 * * RX: Receiver input
 *
 * Additionally, two side-band signals are used to implement flow control in
 * UART. Note that the flow control applies only to TX functionality.
 * * Clear to Send (CTS): This is an input signal to the transmitter.
 *   When active, it indicates that the slave is ready for the master to
 *   transmit data.
 * * Ready to Send (RTS): This is an output signal from the receiver. When
 *   active, it indicates that the receiver is ready to receive data
 *
 * Flow control can be configured by providing cts / rts pins in the device configurator or
 * through manually generated structures.In case CTS flow control enablement status needs to be
 * changed, \ref mtb_hal_uart_enable_cts_flow_control function
 * can be used.
 *
 * \note RTS flow control line is deasserted by the receiver when the number of bytes in the
 * receiver RX FIFO reaches configured RTS RX FIFO level. RX FIFO on the receiver side could
 * end up having an extra byte depending on if the transmitter has begun the transmission of
 * the next byte when the RTS flow control line is deasserted by the receiver.
 *
 * The UART contains dedicated hardware buffers for transmit and receive. Optionally,
 * either of these can be augmented with a software buffer. This can be done using the PDL
 * functions
 *
 * \note For applications that require printing messages on a UART terminal using printf(),
 * the <a href="https://github.com/infineon/retarget-io">retarget-io</a> utility library can be used
 * directly.
 *
 ********************************************************************************
 * \section subsection_uart_features Features
 ********************************************************************************
 * * Configurable UART baud rate - mtb_hal_uart_set_baud*
 * * Configurable interrupts and callback on UART events - mtb_hal_uart_event_t
 ********************************************************************************
 * \section subsection_uart_interrupts Interrupts and callbacks
 ********************************************************************************
 * Interrupts are handled by callbacks based on events mtb_hal_uart_event_t
 * If an event is disabled, the underlying interrupt is still enabled. Enabling or disabling
 * an event only enables or disables the callback.
 * \note Care must be exercised when using the MTB_HAL_UART_IRQ_RX_NOT_EMPTY event.
 * The callback must read all available received data or the interrupt will not be cleared
 * leading to the callback being immediately retriggered.
 ********************************************************************************
 * \section subsection_uart_quickstart Quick Start
 ********************************************************************************
 *   1. Initialize the UART Hardware
 *   2. Enable the UART Hardware
 *   3. Allocate the memory for the HAL UART object
 *   4. Set up the HAL UART using mtb_hal_uart_setup by passing the HAL UART
 *      object and the pre-initialized UART Structures.
 *   5. Set up the interrupt handler and arrange for \ref mtb_hal_uart_process_interrupt
 *      to be invoked from the interrupt handler if UART events need to be handled
 *   6. Config the UART for async transfers using mtb_hal_uart_config_async if
 *      async transfers are needed. This needs to be done before invoking any
 *      async transfer functions
 *
 ********************************************************************************
 * \section subsection_uart_sample_snippets Code Snippets
 ********************************************************************************
 ********************************************************************************
 * \subsection subsection_uart_snippet_1 Snippet 1: Initialization
 ********************************************************************************
 * The following snippet sets up the UART block.
 *
 * The snippet also shows how to use \ref mtb_hal_uart_write, \ref mtb_hal_uart_put, \ref
 * mtb_hal_uart_read API.
 *
 * \snippet hal_uart.c snippet_mtb_hal_uart_init
 *
 ********************************************************************************
 * \subsection subsection_uart_snippet_2 Snippet 2: Interrupts on UART events
 ********************************************************************************
 *
 * In the following snippet, UART events are handled in a callback function.
 * The callback function has to be registered and then the events have to be enabled.
 *
 * \snippet hal_uart.c snippet_mtb_hal_uart_event
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_hal_hw_types.h"

#if defined(MTB_HAL_DRIVER_AVAILABLE_UART)

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
*                           Defines
*******************************************************************************/

/** \addtogroup group_hal_results_uart UART HAL Results
 *  UART specific return codes
 *  \ingroup group_hal_results
 *  \{ *//**
 */
/** The getc call timed out with no received data */
#define MTB_HAL_UART_RSLT_ERR_CSP_UART_GETC_TIMEOUT               \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_UART, 0))
/** The requested operation is not supported on the current hardware */
#define MTB_HAL_UART_RSLT_ERR_UNSUPPORTED_OPERATION       \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_UART, 1))
/** The actual clock tolerance is greater than the maximum allowed tolerance */
#define MTB_HAL_UART_RSLT_ERR_CLOCK_FREQ_TOLERANCE             \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_UART, 2))
/** Other operation in progress */
#define MTB_HAL_UART_RSLT_ERR_BUSY                         \
    (CY_RSLT_CREATE_EX(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_ABSTRACTION_HAL, MTB_HAL_RSLT_MODULE_UART, 3))
/**
 * \}
 */
/** The maximum allowable difference between baud requested and actual baud **/
#define MTB_HAL_UART_MAX_BAUD_PERCENT_DIFFERENCE 10
/** The maximum allowable tolerance in PPM on the UART clock frequency **/
#define MTB_HAL_UART_CLOCK_FREQ_MAX_TOLERANCE_PPM (20000UL)

/*******************************************************************************
*                           Enums
*******************************************************************************/
/** UART enum to enable/disable/report interrupt cause flags. */
typedef enum
{
    /** No interrupt */
    MTB_HAL_UART_IRQ_NONE                = 0,
    /** All TX data from transmit has been moved to the HW TX FIFO buffer */
    MTB_HAL_UART_IRQ_TX_TRANSMIT_IN_FIFO = (MTB_HAL_MAP_UART_IRQ_TX_TRANSMIT_IN_FIFO),
    /** All TX data has been transmitted (applicable only for mtb_hal_uart_write_async) */
    MTB_HAL_UART_IRQ_TX_DONE             = (MTB_HAL_MAP_UART_IRQ_TX_DONE),
    /** An error occurred during TX */
    MTB_HAL_UART_IRQ_RX_DONE             = (MTB_HAL_MAP_UART_IRQ_RX_DONE),
    /** The SW RX buffer (if used) is full. Additional data will be stored in the
     *  HW RX FIFO buffer */
    MTB_HAL_UART_IRQ_RX_FULL             = (MTB_HAL_MAP_UART_IRQ_RX_FULL),
    /** All RX data has been received (applicable only for mtb_hal_uart_read_async) */
    MTB_HAL_UART_IRQ_RX_ERROR            = (MTB_HAL_MAP_UART_IRQ_RX_ERROR),
    /** An error occurred during RX */
    MTB_HAL_UART_IRQ_TX_ERROR            = (MTB_HAL_MAP_UART_IRQ_TX_ERROR),
    /** The HW RX FIFO buffer is not empty */
    MTB_HAL_UART_IRQ_RX_NOT_EMPTY        = (MTB_HAL_MAP_UART_IRQ_RX_NOT_EMPTY),
    /** The HW TX FIFO buffer is empty */
    MTB_HAL_UART_IRQ_TX_EMPTY            = (MTB_HAL_MAP_UART_IRQ_TX_EMPTY),
    /** Number of entries in the HW TX FIFO is less than the TX FIFO trigger level */
    MTB_HAL_UART_IRQ_TX_FIFO             = (MTB_HAL_MAP_UART_IRQ_TX_FIFO),
    /** Number of entries in the HW RX FIFO is more than the RX FIFO trigger level */
    MTB_HAL_UART_IRQ_RX_FIFO             = (MTB_HAL_MAP_UART_IRQ_RX_FIFO)
} mtb_hal_uart_event_t;

/*******************************************************************************
*                          Function Pointers
*******************************************************************************/

/** UART callback function type */
typedef void (* mtb_hal_uart_event_callback_t)(void* callback_arg, mtb_hal_uart_event_t event);

/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/** Enable/disable the UART.
 *
 * The function returns without waiting for the enable to complete.
 *
 * @param[in] obj          The UART object
 * @param[in] enable       Enable/disable
 * @return The status of the enable request
 */
cy_rslt_t mtb_hal_uart_enable(mtb_hal_uart_t* obj, bool enable);

/** Configure the baud rate
 *
 * @param[in,out] obj           The UART object
 * @param[in]     baudrate      The baud rate to be configured
 * @param[out]    actualbaud    The actual baud rate achieved by the HAL
 * Specify NULL if you do not want this information.
 * @return The status of the set_baud request
 */
cy_rslt_t mtb_hal_uart_set_baud(mtb_hal_uart_t* obj, uint32_t baudrate, uint32_t* actualbaud);

/** Get a character. This is a blocking call which waits till a character is received.
 *
 * @param[in] obj               The UART object
 * @param[out] value            The value read from the serial port
 * @param[in] timeout           The time in ms to spend attempting to receive from serial port.
 * Zero is wait forever
 * @return The status of the getc request
 */
cy_rslt_t mtb_hal_uart_get(mtb_hal_uart_t* obj, uint8_t* value, uint32_t timeout);

/** Send a character. This is a blocking call which waits till the character is sent out from the
   UART completely.
 *
 * @param[in] obj               The UART object
 * @param[in] value             The character to be sent
 * @return The status of the putc request
 */
cy_rslt_t mtb_hal_uart_put(mtb_hal_uart_t* obj, uint32_t value);

/** Check the number of bytes available to read from the receive buffers
 *
 * @param[in]  obj              The UART object
 * @return The number of readable bytes
 */
uint32_t mtb_hal_uart_readable(mtb_hal_uart_t* obj);

/** Check the number of bytes than can be written to the transmit buffer
 *
 * @param[in]  obj              The UART object
 * @return The number of bytes that can be written
 */
uint32_t mtb_hal_uart_writable(mtb_hal_uart_t* obj);

/** Clear the UART buffers
 *
 * @param[in] obj               The UART object
 * @return The status of the clear request
 */
cy_rslt_t mtb_hal_uart_clear(mtb_hal_uart_t* obj);

/** Configure the UART CTS for flow control. It sets flow control in the hardware
 *  if a UART peripheral supports it, otherwise software emulation is used.
 *
 * @param[in,out] obj           The UART object
 * @param[in]     enable        Enable or disable the CTS flow control
 * @return The status of the enable_flow_control request
 */
cy_rslt_t mtb_hal_uart_enable_cts_flow_control(mtb_hal_uart_t* obj, bool enable);

/** Begin synchronous TX transfer.
 *
 * This will write either `length` bytes or until the write buffer is full, whichever is less,
 * then return. The value pointed to by `length` will be updated to reflect the number of bytes
 * that was actually written.
 *
 * @param[in]     obj           The UART object
 * @param[in]     tx            The transmit buffer
 * @param[in,out] tx_length     [in] The number of bytes to transmit, [out] number actually
 * transmitted
 * @return The status of the tx request
 */
cy_rslt_t mtb_hal_uart_write(mtb_hal_uart_t* obj, void* tx, size_t* tx_length);

/** Begin synchronous RX transfer (enable interrupt for data collecting)
 *
 * This will read either `length` bytes or the number of bytes that are currently available in the
 * receive buffer, whichever is less, then return. The value pointed to by `length` will be updated
 * to reflect the number of bytes that was actually read.
 *
 * @param[in]     obj           The UART object
 * @param[in]     rx            The receive buffer
 * @param[in,out] rx_length     [in] The number of bytes to receive, [out] number actually received
 * @return The status of the rx request
 */
cy_rslt_t mtb_hal_uart_read(mtb_hal_uart_t* obj, void* rx, size_t* rx_length);

/** Determines if the UART peripheral is currently in use for TX
 *
 * This checks if all the data in the UART TX FIFO is transmitted
 *
 * @param[in]  obj              The UART object
 * @return TX channel active status (active=true)
 */
bool mtb_hal_uart_is_tx_active(mtb_hal_uart_t* obj);

/** Determines if the UART peripheral is currently in use for RX
 *
 * This checks if all the data in the UART RX FIFO is received
 *
 * @param[in]  obj              The UART object
 * @return RX channel active status (active=true)
 */
bool mtb_hal_uart_is_rx_active(mtb_hal_uart_t* obj);

/** Register a uart callback handler
 *
 * This function will be called when one of the events enabled by \ref mtb_hal_uart_enable_event
 * occurs.
 *
 * @param[in] obj               The UART object
 * @param[in] callback          The callback handler which will be invoked when the interrupt fires
 * @param[in] callback_arg      Generic argument that will be provided to the callback when called
 */
void mtb_hal_uart_register_callback(mtb_hal_uart_t* obj, mtb_hal_uart_event_callback_t callback,
                                    void* callback_arg);

/** Enable or disable specified UART events.
 *
 * When an enabled event occurs, the function specified by \ref mtb_hal_uart_register_callback will
 * be called.
 *
 * @param[in] obj               The UART object
 * @param[in] event             The uart event type, this argument supports the bitwise-or of
 * multiple enum flag values
 * @param[in] enable            True to turn on interrupts, False to turn off
 */
void mtb_hal_uart_enable_event(mtb_hal_uart_t* obj, mtb_hal_uart_event_t event, bool enable);

#if defined(COMPONENT_MW_ASYNC_TRANSFER)

/**Configure the UART async transfer interface for CPU based transfer
 *
 * This facilitates the data transfer on the UART peripheral in the background once the
 * transfer is intiated without any application involvement.Users should set up the async
 * transfer interface before calling any async transfer functions. This function sets
 * up all the interfaces needed by  Async Transfer Library to perform the CPU copy based
 * background transfer.
 *
 * @param[in] obj               The UART object
 * @param[in] context           The context structure used by the async transfer library
 *                              to perform the data transfers
 * @return The status of the config request
 */
cy_rslt_t mtb_hal_uart_config_async(mtb_hal_uart_t* obj, mtb_async_transfer_context_t* context);

#if (MTB_HAL_DRIVER_AVAILABLE_DMA)
/**Configure the UART async transfer interface for DMA based transfer
 *
 * This facilitates the data transfer on the UART peripheral in the background using the
 * DMA once the transfer is intiated without any application involvement.Users should
 * set up the async transfer interface before calling any async transfer functions. This
 * function sets up all the interfaces needed by  Async Transfer Library to perform the
 * DMA based background transfer.
 *
 * @param[in] obj               The UART object
 * @param[in] dma_rx            RX DMA object set up for transfer from UART RX FIFO to memory
 * @param[in] dma_tx            TX DMA object set up for transfer from memory to UART TX FIFO
 * @param[in] context           The context structure used by the async transfer library
 *                              to perform the data transfers
 * @return The status of the config request
 */
cy_rslt_t mtb_hal_uart_config_async_dma(mtb_hal_uart_t* obj, mtb_hal_dma_t* dma_rx,
                                        mtb_hal_dma_t* dma_tx,
                                        mtb_async_transfer_context_t* context);
#endif /* (MTB_HAL_DRIVER_AVAILABLE_DMA) */

/** Begin asynchronous RX transfer.
 *
 * This will transfer `length` bytes into the buffer pointed to by `rx` in the background. When the
 * requested quantity of data has been transferred, the MTB_HAL_UART_IRQ_RX_DONE event will be
 * raised.
 * Received data is placed in the user specified buffer. The user must register a callback with
 * \ref mtb_hal_uart_register_callback. RX callback events can be enabled using \ref
 * mtb_hal_uart_enable_event with the appropriate events.
 *
 * \note This function modifies the RX FIFO level internally depending on the number of bytes
 * to receive. User is expected to set it back to the desired RX FIFO level after the read
 * is complete, if required.
 *
 * @param[in]  obj              The UART object
 * @param[out] rx               The user specified receive buffer
 * @param[in]  length           The number of bytes to receive
 * @return The status of the rx_async request
 */
cy_rslt_t mtb_hal_uart_read_async(mtb_hal_uart_t* obj, void* rx, size_t length);

/** Begin asynchronous TX transfer.
 *
 * This will transfer `length` bytes from the buffer pointed to by `tx` in the background. When the
 * requested quantity of data has been transferred, the MTB_HAL_UART_IRQ_TX_TRANSMIT_IN_FIFO event
 * will
 * be raised. The transmit buffer is a user defined buffer that will be sent on the UART. The user
 * must register a callback with \ref mtb_hal_uart_register_callback. If desired, TX callback
 * events can be enabled using \ref mtb_hal_uart_enable_event with the appropriate events.
 *
 * \note This function modifies the TX FIFO level internally. User is expected to set it back to
 * the desired TX FIFO level after the write is complete, if required.
 *
 * @param[in] obj               The UART object
 * @param[in] tx                The transmit buffer
 * @param[in] length            The number of bytes to transmit
 * @return The status of the tx_async request
 */
cy_rslt_t mtb_hal_uart_write_async(mtb_hal_uart_t* obj, void* tx, size_t length);

/** Abort the ongoing read transaction.
 *
 * Disables the RX interrupt and flushes the RX hardware buffer if RX FIFO is used.
 *
 * @param[in] obj               The UART object
 * @return The status of the read_abort request
 */
cy_rslt_t mtb_hal_uart_read_abort(mtb_hal_uart_t* obj);

/** Abort the ongoing TX transaction.
 *
 * Disables the TX interrupt and flushes the TX hardware buffer if TX FIFO is used.
 *
 * @param[in] obj               The UART object
 * @return The status of the tx_abort request
 */
cy_rslt_t mtb_hal_uart_write_abort(mtb_hal_uart_t* obj);

/** Checks whether the UART interface is available to start a read transfer
 * An instance is available to start a read transfer if there is no read transfer
 * currently waiting to complete
 *
 * @param[in] obj               The UART object
 * @return True if a read transfer can be started, false if there is a read
 *         transfer in progress
 */
bool mtb_hal_uart_is_async_rx_available(mtb_hal_uart_t* obj);

/** Checks whether the UART interface is available to start a write transfer
 * An instance is available to start a write transfer if there is no write transfer
 * currently waiting to complete
 *
 * @param[in] obj               The UART object
 * @return True if a write transfer can be started, false if there is a write
 *         transfer in progress
 */
bool mtb_hal_uart_is_async_tx_available(mtb_hal_uart_t* obj);

#endif /* defined(COMPONENT_MW_ASYNC_TRANSFER) */

/**
 * Process interrupts related related to a UART instance.
 *
 * @param obj HAL object for which the interrupt should be processed
 * @return CY_RSLT_SUCCESS if the interrupt was processed successfully; otherwise an error
 */
cy_rslt_t mtb_hal_uart_process_interrupt(mtb_hal_uart_t* obj);

/** Begin synchronous TX transfer of string
 *
 * @param[in]     obj           The UART object
 * @param[in]     tx            The null-terminated string to transfer
 * @return The status of the tx request
 */
cy_rslt_t mtb_hal_uart_write_string(mtb_hal_uart_t* obj, const char* tx);

#if defined(__cplusplus)
}
#endif

#ifdef MTB_HAL_UART_IMPL_HEADER
#include MTB_HAL_UART_IMPL_HEADER
#endif /* MTB_HAL_UART_IMPL_HEADER */

#endif // defined(MTB_HAL_DRIVER_AVAILABLE_UART)

/** \} group_hal_uart */

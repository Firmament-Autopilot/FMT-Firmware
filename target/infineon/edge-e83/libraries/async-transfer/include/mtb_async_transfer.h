/***************************************************************************//**
* \file mtb_async_transfer.h
*
* \brief
* Provides API declarations for the Async Transfer Utility Library that can be
* used to enable asynchronous data transfer on the underlying communication
* peripheral
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
 * \addtogroup group_mtb_async_transfer Async Transfer Utility Library
 * \{
 *
 * Async Transfer Utility Library provides an implementation of data transfer
 * functions in which the calling application initiates the data transfer on the
 * desired communication peripheral and then the data transfer happens in the
 * background without the application involvement.
 *
 * This library does not have direct knowledge of the underlying communication
 * peripheral being used and the users of the library shall set up the necessary
 * interface needed to support the background transfer on the specific communication
 * peripheral
 *
 * <b>Features:</b>
 * * Both read and write transfers can be performed.
 * * Transfers can performed via either CPU copy or DMA.
 * * One transfer in each of direction (read and write) can be pending at the same time.
 * * A callback can be invoked on completion of a transfer.
 * * It is possible to query whether an async-transfer instance is available in a given direction.
 * * An in-progress transfer can be aborted.
 * * Repeated transfers can be performed without re-initializing.
 * * Multiple instances of the async transfer library can co-exist, managing different
 * communications interfaces.
 *
 ********************************************************************************
 * \section group_mtb_async_transfer_prerequisites  Prerequisites
 ********************************************************************************
 * Setup the interfaces necessary to communicate to the underlying hardware.
 * \ref  mtb_async_transfer_interface_t.
 *
 * Allocate the memory for the context structure and set-up the underlying
 * communication inteface's using \ref mtb_async_transfer_init
 *
 * For CPU based transfers, the user of async transfer must arrange for
 * \ref mtb_async_transfer_process_fifo_level_event to be invoked,
 * (e.g. by registering an interrupt handler) when FIFO reaches the desired level
 * on the underlying communications interface.
 *
 * For DMA  based transfers, the user of async transfer must arrange for
 * \ref mtb_async_transfer_process_dma_complete to be invoked,
 * (e.g. by registering an interrupt handler) when FIFO reaches the desired level
 * on the underlying communications interface.
 *
 * Set up the callback to be invoked when the async transfer is complete using
 * \ref mtb_async_transfer_register_callback
 *
 *********************************************************************************
 * \section group_mtb_async_transfer_code_snippets  Code Snippets
 ********************************************************************************
 * Init sequence for configuring the async tranfer in CPU mode
 * \snippet async_transfer_snip.c snippet_async_transfer_init_cpu_mode
 *
 *  Init sequence for configuring the async tranfer in DMA mode
 * \snippet async_transfer_snip.c snippet_async_transfer_init_dma_mode
 *
 * Read operation
 * \snippet async_transfer_snip.c snippet_async_transfer_read
 *
 * Write operation
 * \snippet async_transfer_snip.c snippet_async_transfer_write
 *
 * \defgroup group_mtb_async_transfer_enums Enumerated Types
 * \defgroup group_mtb_async_transfer_function_pointers Function Pointers
 * \defgroup group_mtb_async_transfer_structures Data Structures

 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_result.h"

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Defines
*******************************************************************************/

/** An invalid parameter value is passed in. */
#define MTB_ASYNC_TRANSFER_BAD_PARAM_ERROR                \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ASYNC_TRANSFER, 0)
/** A read transfer is already in progress. */
#define MTB_ASYNC_TRANSFER_READ_BUSY                \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ASYNC_TRANSFER, 1)
/** A write transfer is already in progress. */
#define MTB_ASYNC_TRANSFER_WRITE_BUSY                \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ASYNC_TRANSFER, 2)
/** An error occurred when performing read transfer */
#define MTB_ASYNC_TRANSFER_READ_ERROR                \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ASYNC_TRANSFER, 3)
/** An error occurred when performing write transfer */
#define MTB_ASYNC_TRANSFER_WRITE_ERROR                \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ASYNC_TRANSFER, 4)
/** An error occurred when performing both read and write transfer */
#define MTB_ASYNC_TRANSFER_READ_WRITE_ERROR                \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_ASYNC_TRANSFER, 5)


/*******************************************************************************
*                           Enums
*******************************************************************************/

/**
 * \addtogroup group_mtb_async_transfer_enums
 * \{
 */

/** Async Transfer direction  */
typedef enum
{
    MTB_ASYNC_TRANSFER_DIRECTION_READ  = 1u, //!< Read Transfer
    MTB_ASYNC_TRANSFER_DIRECTION_WRITE = 2u  //!< Write Transfer
} mtb_async_transfer_direction_t;

/** \} group_mtb_async_transfer_enums */

/*******************************************************************************
*                          Function Pointers
*******************************************************************************/
/**
 * \addtogroup group_mtb_async_transfer_function_pointers
 * \{
 */

/** Function pointer for returning the number of elements that can be read from
 * the FIFO in case of rx or that can be written to the FIFO in case of tx
 *
 * @param[in]  inst_ref    Pointer to the peripheral instance base address
 *
 * @return the number of elements that can be read in case of RX or write in
 * case of TX
 */
typedef uint32_t (* mtb_async_transfer_get_num_fifo_t)(void* inst_ref);

/** Function pointer to set the fifo level for triggering an interrupt when the
 *  number of elements in the FIFO exceeds(for RX) or drops below (for TX)
 *  `level` number of elements.
 *
 * @param[in]  inst_ref     Pointer to the peripheral instance base address
 * @param[in]  level        FIFO level to set.
 */
typedef void (* mtb_async_transfer_set_fifo_level_t)(void* inst_ref, uint32_t level);

/** Function pointer for enabling/disabling an RX or TX FIFO level interrupt event.
 *
 * @param[in]  inst_ref     Pointer to the peripheral instance base address
 * @param[in]  enable       true to enable the interrupt. false to disable the interrupt
 */
typedef void (* mtb_async_transfer_set_enabled_t)(void* inst_ref, bool enable);

/** Function pointer for getting the RX/TX transfer length, i.e the number of elements
 *  recommended by the interface to tranmsit or receive over the peripheral in a single
 *  transfer
 *
 * In case of TX, this could be half of the FIFO width
 * In case of RX, this could be half of the FIFO width or receive flow control level if the
 * underlying communication peripheral specifies that,  for e.g. in case of UART,
 * rx transfer length could be UART RTS FIFO level if flow control is enabled
 *
 * @param[in]  inst_ref     Pointer to the peripheral instance base address
 *
 * return the RX/TX transfer length
 */
typedef uint32_t (* mtb_async_transfer_get_len_t)(void* inst_ref);

/** Function pointer to set an address associated with a DMA transfer.
 *
 * @param[in]  dma_ref      Pointer to the dma instance address
 * @param[in]  addr         Address associated with the DMA transfer
 */
typedef cy_rslt_t (* mtb_async_transfer_dma_set_addr_t)(void* dma_ref, void* addr);

/** Function pointer to set the length for a DMA transfer.
 *
 * @param[in]  dma_ref       Pointer to the dma instance address
 * @param[in]  len           Number of bytes to read or write
 */
typedef cy_rslt_t (* mtb_async_transfer_dma_set_len_t)(void* dma_ref, size_t len);

/** Async transfer callback function type
 *
 * @param[in] callback_arg  The argument pointer specified when the callback was registered via \ref
 * mtb_async_transfer_register_callback
 * @param[in] direction     The direction (read or write) in which the transfer completed. This is a
 * flags enum; both directions may be set at once
 */
typedef void (* mtb_async_transfer_event_callback_t)(void* callback_arg,
                                                     mtb_async_transfer_direction_t direction);

/** Function pointer to disable interrupts and returns a value indicating whether the interrupts
 * were previously enabled
 *
 * Returns the current interrupt status
 */
typedef uint32_t (* mtb_async_transfer_enter_critical_section_t)(void);

/** Function pointer to re-enables the interrupts if they were enabled before
 * mtb_async_transfer_enter_critical_section_t was called
 *
 * @param[in]  irq_status  The saved interrupts status returned by
 *                          the mtb_async_transfer_enter_critical_section_t
 */
typedef void (* mtb_async_transfer_exit_critical_section_t)(uint32_t irq_status);

/** \} group_mtb_async_transfer_function_pointers */

/*******************************************************************************
*                          Data Structures
*******************************************************************************/
/**
 * \addtogroup group_mtb_async_transfer_structures
 * \{
 */

/** Async Transfer interface data structure. Users of the async transfer
 *  library should set up this interface based on the peripheral being
 *  used for the async data transfer. This is used by the library to
 *  perform the read/write transfer on the specified peripheral.
 */
typedef struct
{
    /** The opaque pointer that is passed as the first argument to all non-DMA
     * functions. For e.g. this could be pointer to peripheral instance base
     * address */
    void*                                inst_ref;

    /**  Pointer to the read data source address */
    volatile uint32_t*                   rx_addr;

    /**  Pointer to the write data destination address */
    volatile uint32_t*                   tx_addr;

    /** Function to get the number of elements available in the RX FIFO */
    mtb_async_transfer_get_num_fifo_t    get_num_rx_fifo;

    /** Function to get the number of elements that can be written to the TX FIFO */
    mtb_async_transfer_get_num_fifo_t    get_num_tx_fifo;

    /** Function to set the RX FIFO level above which the interrupt is triggered */
    mtb_async_transfer_set_fifo_level_t  set_rx_fifo_level;

    /** Function to set the TX FIFO level below which the interrupt is triggered */
    mtb_async_transfer_set_fifo_level_t  set_tx_fifo_level;

    /** Function to enable/disable RX FIFO level interrupt event */
    mtb_async_transfer_set_enabled_t    enable_rx_event;

    /** Function to enable/disable TX FIFO level interrupt event */
    mtb_async_transfer_set_enabled_t    enable_tx_event;

    /** Function to enable/disable RX DMA event and RX DMA channel*/
    mtb_async_transfer_set_enabled_t    dma_enable_rx;

    /** Function to enable/disable TX DMA event and TX DMA channel*/
    mtb_async_transfer_set_enabled_t    dma_enable_tx;

    /** Number of elements that the peripheral interface can receive in a single transfer */
    mtb_async_transfer_get_len_t         get_rx_transfer_len;

    /** Number of elements that the peripheral interface can transmit in a single transfer */
    mtb_async_transfer_get_len_t         get_tx_transfer_len;

    /** Width, in bytes, of each FIFO element */
    uint32_t                             transfer_width;

    /** Opaque pointer that is passed as the first argument when operating on the RX DMA */
    void*                                dma_rx_ref;

    /** Opaque pointer that is passed as the first argument when operating on the TX DMA */
    void*                                dma_tx_ref;

    /** Function to set the DMA transfer length */
    mtb_async_transfer_dma_set_len_t     dma_set_length;

    /** Function to set the DMA source address */
    mtb_async_transfer_dma_set_addr_t    dma_set_src;

    /** Function to set the DMA destination address */
    mtb_async_transfer_dma_set_addr_t    dma_set_dest;

    /** Function to enter critical section */
    mtb_async_transfer_enter_critical_section_t enter_critical_section;

    /** Function to exit critical section */
    mtb_async_transfer_exit_critical_section_t  exit_critical_section;
} mtb_async_transfer_interface_t;

/**
 * Async Transfer context data structure. It is used to store the context
 * information that needs to be retained across function calls. The caller
 * must allocate the memory for the struct and should not modify the contents
 */
typedef struct
{
    /** Async Transfer interface that holds the information needed to perform the
     * data transfer on the peripheral */
    mtb_async_transfer_interface_t       interface;

    /**  Pointer to the source address from which the data is transferred in case
     *  of write */
    void*                                src_addr;

    /**  Number of bytes to be transferred from the source */
    uint32_t                             src_length;

    /**  Pointer to the destination address to which the data is transferred in case
     *  of read */
    void*                                dest_addr;

    /**  Number of bytes to be transferred to the destination */
    uint32_t                             dest_length;

    /** Callback function to be invoked once the read/write async transfer is complete */
    mtb_async_transfer_event_callback_t  callback;

    /** Argument to be provided to the transfer complete callback function when invoked */
    void*                                callback_arg;
} mtb_async_transfer_context_t;

/** \} group_mtb_async_transfer_structures */

/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

/** Initializes an async transfer library instance.
 *
 * @param[in,out] context Stores state that async-transfer needs to track between calls. The caller
 * must
 *                        allocate memory for this struct but should not depend on its contents.
 * @param[in]     iface   Defines the interaction between this async-transfer instance and the
 *                        peripheral that it is transferring data to/from.
 *
 * \note It *is* safe to free `iface` or let it go out of scope after this function returns
 * @return the status of the initialization
 */
cy_rslt_t mtb_async_transfer_init(mtb_async_transfer_context_t* context,
                                  const mtb_async_transfer_interface_t* iface);

/** Reads data from the peripheral to the memory in the background
 *
 * If D-cache is enabled and DMA is used, the user needs to make sure that the dest
 * pointer passed to the mtb_async_transfer_read function points to a buffer which is
 * aligned to the cache line size (__SCB_DCACHE_LINE_SIZE).
 * The length of buffer data must be a multiple of the cache line size to ensure
 * cache coherency. CY_ALIGN(__SCB_DCACHE_LINE_SIZE) macro can be used for alignment.
 *
 * Refer to \ref DCACHE_Management for more information.
 *
 * @param[in,out] context The context object for this peripheral that was populated by \ref
 *                        mtb_async_transfer_init
 * @param[in,out] dest    Pointer to the buffer to which the data read from the peripheral
 *                        should be stored. This buffer must remain valid for the duration
 *                        of the transfer, and its contents should not be accessed until the
 *                        read transfer is complete.
 * @param[in]     length  Length, in bytes, of the data that is to be read
 *
 * \note This function modifies the RX FIFO level depending on the number of bytes
 * to receive. User is expected to set it back to the original RX FIFO level after the
 * read is complete, if desired.
 *
 * @return the status of starting the read  */
cy_rslt_t mtb_async_transfer_read(mtb_async_transfer_context_t* context, void* dest, size_t length);

/** Writes data from memory to the peripheral in the background
 *
 * If D-cache is enabled and DMA is used, the user needs to make sure that the source
 * pointer passed to the mtb_async_transfer_write function points to a buffer which is
 * aligned to the cache line size (__SCB_DCACHE_LINE_SIZE).
 * The length of buffer data must be a multiple of the cache line size to ensure
 * cache coherency. CY_ALIGN(__SCB_DCACHE_LINE_SIZE) macro can be used for alignment.
 *
 * Refer to \ref DCACHE_Management for more information.
 *
 * @param[in,out] context The context object for this peripheral that was populated by \ref
 *                        mtb_async_transfer_init
 * @param[in]     source  Pointer to the data that is to be written to the peripheral
 *                        This buffer must remain valid for the duration of the transfer,
 *                        and its contents should not be accessed until the write transfer
 *                        is complete.
 * @param[in]     length  Length, in bytes, of the data that is to be written to the peripheral
 *
 * \note This function modifies the TX FIFO level depending on the number of bytes
 * to transmit. User is expected to set it back to the original TX FIFO level after the
 * write is complete, if desired.
 *
 * @return the status of starting the write
 */
cy_rslt_t mtb_async_transfer_write(mtb_async_transfer_context_t* context, void* source,
                                   uint32_t length);

/** Checks whether the async-transfer instance is available to start a read transfer.
 * An instance is available to start a read transfer if there is no read transfer
 * currently waiting to complete
 *
 * @param[in,out] context The context object for this peripheral that was populated by \ref
 *                        mtb_async_transfer_init
 *
 * @return True if a read transfer can be started, false if there is a read transfer in progress
 */
bool mtb_async_transfer_available_read(const mtb_async_transfer_context_t* context);

/** Checks whether the async-transfer instance is available to start a write transfer.
 * An instance is available to start a write transfer if there is no write transfer
 * currently waiting to complete
 *
 * @param[in,out] context The context object for this peripheral that was populated by \ref
 *                         mtb_async_transfer_init
 *
 * @return True if a write transfer can be started, false if there is a write transfer in progress
 */
bool mtb_async_transfer_available_write(const mtb_async_transfer_context_t* context);

/** Stops an in-progress read transfer.
 *
 * @param[in,out] context The context object for this peripheral that was populated by \ref
 *                         mtb_async_transfer_init
 *
 * @return the status of aborting the read
 */
cy_rslt_t mtb_async_transfer_abort_read(mtb_async_transfer_context_t* context);

/** Stops an in-progress write transfer.
 *
 * @param[in,out] context The context object for this peripheral that was populated by \ref
 *                         mtb_async_transfer_init
 * \note This only aborts the transfer of data into the hardware FIFO. Data which was already
 * written into the FIFO may still be written even after this function returns.
 *
 * @return the status of aborting the write
 */
cy_rslt_t mtb_async_transfer_abort_write(mtb_async_transfer_context_t* context);

/** Register a callback to be invoked when a transfer is complete.
 * \note For read, "complete" means that the requested amount of data has been copied into the
 * destination buffer.
 *       For write, "complete" means that the requested amount of data has been written into the
 * buffer in the peripheral.It does not mean that all of the data has been sent out over the
 * communications interface. Such a status should be checked via the driver for the underlying
 * peripheral.
 *
 * @param[in,out] context  The context object for this peripheral that was populated by \ref
 *                         mtb_async_transfer_init
 * @param[in]     callback The callback to register. This will replace any previously registered
 *                         callback. A value of `NULL` for this  parameter will result in no
 * callback
 *                         being registered.
 * @param[in,out] arg      An arbitrary pointer, which will be passed to the callback when it is
 * invoked.
 *
 * @return the status of registering the callback
 */
cy_rslt_t mtb_async_transfer_register_callback(mtb_async_transfer_context_t* context,
                                               mtb_async_transfer_event_callback_t callback,
                                               void* arg);

/** Handler for when the FIFO in the peripheral reaches the trigger level.
 * The user of async-transfer must arrange for this function to be invoked
 * (e.g. by registering an interrupt handler) when this event occurs
 *
 * @param[in,out] context   The context object for this peripheral that was populated by \ref
 *                          mtb_async_transfer_init
 * @param[in]     direction The direction (read or write) in which this event occurred
 *
 * @return the status of handling the event
 */
cy_rslt_t mtb_async_transfer_process_fifo_level_event(mtb_async_transfer_context_t* context,
                                                      mtb_async_transfer_direction_t direction);

/** Handler for when a DMA transfer is complete.
 * The user of async-transfer must arrange for this function to be invoked
 * (e.g. by registering an interrupt handler) when this event occurs
 *
 * @param[in,out] context   The context object for this peripheral that was populated by \ref
 *                          mtb_async_transfer_init
 * @param[in]     direction The direction (read or write) in which this event occurred
 *
 * @return the status of handling the event
 */
cy_rslt_t mtb_async_transfer_process_dma_complete(mtb_async_transfer_context_t* context,
                                                  mtb_async_transfer_direction_t direction);

/** \} group_mtb_async_transfer */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

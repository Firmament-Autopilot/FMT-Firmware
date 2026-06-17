/***************************************************************************//**
* \file mtb_ipc.h
*
* \brief
* Provides a high level interface for interacting with the Infineon IPC driver.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2025 Cypress Semiconductor Corporation (an Infineon company) or
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
 * \addtogroup group_mtb_ipc IPC (Inter-Processor Communication)
 * \{
 * High level interface for communicating between processors on a multi-core device.
 *
 * The IPC driver allows communication between multiple CPUs or between multiple tasks
 * operating in different domains within a single CPU. It supports binary semaphores
 * and message queues, similar to how they are used for task interactions in an RTOS envrionment.
 *
 * \section subsection_ipc_features Features
 * * Binary semaphore for resource access control and general signalling
 * * Message queue for passing data between tasks/cores
 *
 * \section subsection_ipc_quickstart Quick Start
 * To initialize the driver, call the mtb_ipc_init on the first task/CPU to boot and
 * mtb_ipc_get_handle
 * on other cores. Please see your device documentation to determine which core to start on.
 * This will setup shared memory and the binary semaphore for protecting internal
 * functionality.
 *
 * For binary semaphores, only one task/CPU may initialize ( \ref mtb_ipc_semaphore_init) a
 * semaphore.
 * Other tasks/CPUs
 * then get the handle ( \ref mtb_ipc_semaphore_get_handle) of the created semaphore. Then take/give
 * the
 * semaphore
 * ( \ref  mtb_ipc_semaphore_take/ \ref mtb_ipc_semaphore_give).
 *
 * For queues, only one task/CPU may initialize ( \ref mtb_ipc_queue_init) a queue. Other tasks/CPUs
 * then
 * get the handle
 * ( \ref mtb_ipc_queue_get_handle) of the created queue. Use the get/put functions to take out or
 * put in
 * items to the queue
 * ( \ref mtb_ipc_queue_put, \ref mtb_ipc_queue_get).
 *
 * \section section_impl_ipc_semaphore_idx_valid_range Valid range for IPC semaphore number
 * mtb_ipc_semaphore_init function semaphore_num parameter valid range is from 0 to (including)
 * CY_IPC_SEMA_COUNT - 2
 *
 * \section section_impl_ipc_shared_data_objects
 * For all IPC library constructs, some data must be put in the shared memory regions
 * so that all cores can access. This must satisfy a few requirements:
 * - Memory should be accessible from all cores (e.g. CY_SECTION_SHAREDMEM macro can be used)
 * - If used with a core where Data Cache is enabled, memory should be aligned to
 * __SCB_DCACHE_LINE_SIZE
 * The following sections outline the different data types and their requirements.
 * \subsection section_impl_ipc_shared_data_ Shared data memory allocation
 * Shared data memory allocation can be done with help of MTB_IPC_SHARED_DATA_ALLOC macro, but
 * using it is not mandatory,
 * so user can allocate memory for the shared memory in any convenient for them way. This struct
 * is necessary to store and keep track of all shared objects during operation.
 * \subsection section_impl_ipc_semaphore_data Semaphore data memory allocation
 * semaphore data memory allocation can be done with help of MTB_IPC_SEMAPHORE_DATA_ALLOC macro, but
 * using it is not mandatory,
 * so user can allocate memory for the semaphore data in any convenient for them way as long as such
 * allocation satisfies next parameters:
 * - Memory should be able to store mtb_ipc_semaphore_data_t type struct
 * - Each initialized semaphore must have its own semaphore data object. These cannot be shared
 * between semaphores
 * \subsection section_impl_ipc_mbox_data Mailbox data memory allocation
 * Mailbox data memory allocation can be done with help of
 * MTB_IPC_MBOX_DATA_ALLOC macro, but using it is not mandatory,
 * so user can allocate memory for the mailbox data in any way convenient for them
 * as long as such allocation satisfies next parameters:
 * - Memory should be able to store mtb_ipc_mbox_data_t type struct
 * - Each initialized mailbox must have its own mailbox data object. These cannot be shared
 * between mailboxes
 * \subsection section_impl_ipc_queue_pool_memory Queue pool memory allocation
 * Queue pool memory allocation can be done with help of MTB_IPC_QUEUE_POOL_ALLOC macro, but using
 * it is not mandatory,
 * so user can allocate memory for the queue pool in any convenient for them way as long as such
 * allocation satisfies next parameters:
 * - Memory should be able to store NUM_ITEMS x ITEM_SIZE bytes, where NUM_ITEMS - number of max.
 * elements the queue can store, and
 * ITEM_SIZE - size of each queue item in bytes
 * - Each queue must have its own queue pool
 * \subsection section_impl_ipc_queue_data Queue data memory allocation
 * Queue data memory allocation can be done with help of MTB_IPC_QUEUE_DATA_ALLOC macro, but
 * using it is not mandatory,
 * so user can allocate memory for the queue data in any convenient for them way as long as such
 * allocation satisfies next parameters:
 * - Memory should be able to store mtb_ipc_queue_data_t type struct
 * - Each queue must have its own data object. These cannot be shared between queues.
 *
 * \section section_impl_ipc_preemtable_sema Preemtable Semaphore parameter
 * If preemptable is enabled (true), the user must ensure that there are
 * no deadlocks in the system, which can be caused by an interrupt that occurs
 * after the IPC channel is locked. Unless the user is ready to handle IPC
 * channel locks correctly at the application level, set preemptable to
 * false.
 *
 * \section section_impl_ipc_interrupts_priorities IPC interrupts implementation
 * In current IPC library implementation, each core has two of its "own" IPC INTR structures, which
 * services
 * all possible IPC library
 * channels. One IRQ structure is for semaphores, and the other for queues.
 *
 * \section section_impl_ipc_operation_isr IPC operations in ISR context
 * Callbacks may execute in an ISR context, so IPC queue put/get operations cannot be performed in
 * callbacks with a timeout != 0
 * Such operations will result in \ref MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT.
 * IPC semaphore take/give operations cannot be performed in ISR context with a timeout != 0.
 * Such operations will result in \ref MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT.
 *
 *
 * \section section_initialization IPC initialization
 * On some devices (currently, Traveo, XMC72, and PSE84 devices), startup code does not initialize
 * IPC PDL driver semaphores,
 * so it is done by mtb_ipc_init(). In general, the init function should be called by the first core
 * to boot.
 * Please see your device datasheet for details. This core will do the
 * initialization
 * and set up a pointer using an IPC channel so that all Cores can read and use the same variables.
 * if it has not already been done on that core.
 *  The corresponding mtb_ipc_get_handle will be used on  other cores to receive this data.
 *
 * \section section_impl_ipc_get_handle_before_init Calling *_get_handle APIs before _init APIs
 * Calling mtb_ipc_semaphore_get_handle() before mtb_ipc_semaphore_init()
 * will result in \ref MTB_IPC_RSLT_ERR_NO_SEMA_AVAILABLE. The correct way of using
 * mtb_ipc_semaphore_get_handle() is to call mtb_ipc_semaphore_init() before using
 * mtb_ipc_semaphore_get_handle(), and pass the same semaphore number that
 * was used for the initialization. Semaphores can be initialized on any core and accessed from
 * any core.
 *
 * Calling mtb_ipc_queue_get_handle() before mtb_ipc_queue_init() will result in
 * \ref MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND. The correct way of using
 * mtb_ipc_queue_get_handle() is to call mtb_ipc_queue_init() before using
 * mtb_ipc_queue_get_handle(), and pass the same channel and queue number that
 * was used for the queue initialization. Queues can be initialized on any core and accessed from
 * any core.
 *
 * Calling \ref mtb_ipc_mbox_sender_get_handle() before \ref mtb_ipc_mbox_receiver_init() will
 * result in
 * \ref MTB_IPC_RSLT_ERR_MBOX_NOT_FOUND. The correct way of using
 * \ref mtb_ipc_mbox_sender_get_handle() is to call it after \ref mtb_ipc_mbox_receiver_init() , and
 * pass the same mailbox index that
 * was used for the mailbox initialization. Mailboxes can be initialized on any core and accessed
 * from any core, however initialization must be done on the
 * receiving core for that individual mailbox.
 *
 * \section section_queue_data_protection To protect queue data and also ensure minimal possibility
 * of deadlocks,
 * any modification of the Queue besides its notifications must be done using the queue's semaphore.
 * To ensure less arbitration in ISR context,
 * notifications are instead protected by the lock on the channel the queue is part of.
 *
 * \section section_ipc_snippets Code Snippets
 *
 * \subsection subsection_ipc_snippet1 Snippet 1: Binary semaphore example
 * \snippet main.c snippet_mtb_ipc_semaphore
 *
 * \subsection subsection_ipc_snippet2 Snippet 2: Message queue example
 * \snippet main.c snippet_mtb_ipc_queue
 *
 * \subsection subsection_ipc_snippet3 Snippet : Message mailbox example
 * \snippet main.c snippet_mtb_ipc_mbox
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "cy_result.h"
#include "mtb_ipc_impl.h"
#include "mtb_ipc_config.h"
#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
/* RTOS_AWARE is for semaphore usage so that in a multi-threaded system, we can allow other
 * threads to run if the current thread is blocked by a MTB IPC/PDL IPC Semaphore.
 */
#include "cyabs_rtos.h"
#endif \
    /* (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0) */

#if defined(__cplusplus)
extern "C" {
#endif

/** \addtogroup group_ipc_results IPC Results
 * \ingroup group_mtb_ipc
 *  IPC specific return codes
 *  \{ *//**
 */

/** IPC library Driver not initialized */
#define MTB_IPC_RSLT_ERR_NOT_INITIALIZED           \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 0))
/** Invalid parameter error */
#define MTB_IPC_RSLT_ERR_INVALID_PARAMETER           \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 1))
/** Timeout Occurred */
#define MTB_IPC_RSLT_ERR_TIMEOUT           \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 2))
/** Provided semaphore number already used */
#define MTB_IPC_RSLT_ERR_SEMA_NUM_IN_USE            \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 3))
/** Provided semaphore number already taken */
#define MTB_IPC_RSLT_ERR_SEMA_TAKEN            \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 4))
/** Failed to take the semaphore */
#define MTB_IPC_RSLT_ERR_SEMA_FAIL            \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 5))
/** Can't get the semaphore handle, possibly bad number */
#define MTB_IPC_RSLT_ERR_NO_SEMA_AVAILABLE           \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 6))
/** Provided queue number already used */
#define MTB_IPC_RSLT_ERR_QUEUE_NUM_IN_USE            \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 7))
/** Queue is full */
#define MTB_IPC_RSLT_ERR_QUEUE_FULL                  \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 8))
/** Queue is empty */
#define MTB_IPC_RSLT_ERR_QUEUE_EMPTY                 \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 9))
/** Queue object is not found */
#define MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND             \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 10))
/** Operation can't be performed in ISR context */
#define MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR         \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 11))
/** Operation can't be performed in ISR context with timeout != 0 */
#define MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT         \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 12))
/** IRQ is already being used by another core */
#define MTB_IPC_RSLT_ERR_INVALID_IRQ_CHANNEL         \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 13))
/** Provided mailbox index already used */
#define MTB_IPC_RSLT_ERR_MBOX_IDX_IN_USE            \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 14))
/** Mailbox is full. Cannot write to a mailbox that is full */
#define MTB_IPC_RSLT_ERR_MBOX_FULL                  \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 15))
/** Mailbox is empty. Cannot read from a mailbox that is empty */
#define MTB_IPC_RSLT_ERR_MBOX_EMPTY                 \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 16))
/** Mailbox object with specified index is not found */
#define MTB_IPC_RSLT_ERR_MBOX_NOT_FOUND             \
    (CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_IPC, 17))

/**
 * \}
 */


/** Flags enum of IPC Mailbox events. Multiple events can be enabled via \ref
 * mtb_ipc_mbox_receiver_enable_event
 * \ref mtb_ipc_mbox_sender_enable_event and
 * the callback from \ref mtb_ipc_mbox_receiver_register_callback or
 * \ref mtb_ipc_mbox_sender_register_callback will be run to notify. */
typedef enum
{
    MTB_IPC_MBOX_FULL        = 1 << 0UL, //!< Mailbox is full
    MTB_IPC_MBOX_EMPTY       = 1 << 1UL  //!< Mailbox is empty
} mtb_ipc_mbox_event_t;


/** Flags enum of IPC events. Multiple events can be enabled via \ref mtb_ipc_queue_enable_event and
 * the callback from \ref mtb_ipc_queue_register_callback will be run to notify. */
typedef enum
{
    MTB_IPC_NO_INTR           = 0UL,      //!< No interrupt
    MTB_IPC_QUEUE_WRITE       = 1 << 0UL, //!< New item was written to the queue
    MTB_IPC_QUEUE_READ        = 1 << 1UL, //!< New item was read from the queue
    MTB_IPC_QUEUE_FULL        = 1 << 2UL, //!< Queue is full
    MTB_IPC_QUEUE_EMPTY       = 1 << 3UL, //!< Queue is empty
    MTB_IPC_QUEUE_RESET       = 1 << 4UL  //!< Queue was reset
} mtb_ipc_queue_event_t;

/** Aggregate of all the Queue events */
#define MTB_IPC_QUEUE_ALL_EVENTS \
    ( MTB_IPC_QUEUE_WRITE | MTB_IPC_QUEUE_READ | MTB_IPC_QUEUE_FULL | MTB_IPC_QUEUE_EMPTY | MTB_IPC_QUEUE_RESET )

/** Queue Event handler for IPC interrupts */
typedef void (* mtb_ipc_queue_event_callback_t)(void* callback_arg, mtb_ipc_queue_event_t event);

/** Callback handler for IPC mailbox interrupts */
typedef void (* mtb_ipc_mbox_event_callback_t)(void* callback_arg, mtb_ipc_mbox_event_t event);

/** This define can be used as timeout argument for the IPC HAL driver functions, that take timeout
 * as input parameter, in order to make function never time out (wait forever) */
#define MTB_IPC_NEVER_TIMEOUT (0xFFFFFFFFFFFFFFFFUL)
/** This define can be used as timeout argument for the IPC driver functions, that take timeout
 * as input parameter, in order to make function never time out (wait forever) in functions that
 * take ms an an argument */
#define MTB_IPC_NEVER_TIMEOUT_MS (0xFFFFFFFFUL)
/**
 * @brief User Config Struct to set up a Semaphore
 * Items to be populated by caller before initialization
 * Semaphore number defines a specific semaphore and
 * should be less than _MTB_IPC_SEMA_COUNT.
 */
typedef struct mtb_ipc_semaphore_config_t
{
    /**Allows whether the semaphore can be preempted by another task.
     * If preemptable is enabled (true), the user must ensure that there are
     * no deadlocks in the system, which can be caused by an interrupt that occurs
     * after the IPC channel is locked. Unless the user is ready to handle IPC
     * channel locks correctly at the application level, set preemptable to
     * false.
     */
    bool                       preemptable;
    /** The semaphore number to initialize. Please refer to implementation
     * specific documentation for valid range for this parameter. */
    uint32_t                   semaphore_num;
} mtb_ipc_semaphore_config_t;

/**
 * @brief User Config Struct to set up a Mailbox
 * Items to be populated by caller before initialization
 * Read/Write Semaphore number defines a specific semaphore and
 * should be less than _MTB_IPC_SEMA_COUNT.
 * Mailbox index must be in range 0 - \ref MTB_IPC_MAX_MBOXES and must be unique.
 */
typedef struct mtb_ipc_mbox_config_t
{
    /** The index of the mailbox. This must be unique as to not clash with
     * other mailboxes. */
    uint32_t                   mailbox_idx;
    /** The semaphore number to use for guarding reads.
     * The semaphore with this number will be automatically initialized by the mailbox */
    uint32_t                   read_semaphore_num;
    /** The semaphore number to use for guarding writes.
     * The semaphore with this number will be automatically initialized by the mailbox. */
    uint32_t                   write_semaphore_num;
} mtb_ipc_mbox_config_t;

/**
 * @brief User Config Struct to set up a Queue
 * Items to be populated by caller before initialization
 * Combination of channel_num and queue_num uniquely defines a specific Queue.
 */
typedef struct mtb_ipc_queue_config_t
{
    /** IPC channel number (e.g. MTB_IPC_CHAN_0)
     * Please refer to implementation specific documentation for number
     * of available IPC channels for particular device. */
    mtb_ipc_channel_t    channel_num;
    /** Queue number, which must be unique for each queue in scope of one IPC channel. */
    uint32_t    queue_num;
    /** Maximum number of items (packets) allowed in the queue */
    uint32_t    max_num_items;
    /** Size of each packet (item) in the Queue */
    uint32_t    item_size;
    /** Pointer to the queue packets in shared memory.
     * This memory will be cleared by IPC library Queue Initialization.
     * Packet list is an array of packets of max_num_items.
     * It is used as a circular array, first_item is an index to first item stored.
     */
    void* queue_pool;
    /** Semaphore number to use with this queue */
    uint32_t                   semaphore_num;
} mtb_ipc_queue_config_t;

/**
 * @brief IPC object config struct. These must be provided values
 * for use in configuration of the driver.
 *
 */
typedef struct mtb_ipc_config_t
{
    /** IPC channel number (e.g. MTB_IPC_CHAN_0) Please refer to implementation specific
       documentation for number of available IPC channels for particular device.
     * This must match the IPC object initialized on the other core for this core to access the
     * shared memory.*/
    mtb_ipc_channel_t          internal_channel_index;
    /** User Defined IRQ for use on this core for all semaphores. A unique IRQ must be used for each
       core */
    uint32_t                   semaphore_irq;
    /** User Defined IRQ for use on this core for all queues. A unique IRQ must be used for each
       core */
    uint32_t                   queue_irq;
    /** User defined semaphore number to use for access to shared region and all MTB IPC operations
     */
    uint32_t                   semaphore_num;
} mtb_ipc_config_t;


/** Initialize IPC library Driver
 *
 * Call before any other IPC library functions.
 * Must be called before any other core calls mtb_ipc_get_handle.
 * The initialization of the semaphore must be done by the init core on startup
 * or during cybsp_init() as the IPC driver assumes it has already been done.
 * The MTB IPC has no way of ensuring it hasn't been already initialized on the channel,
 * so it is up to user to ensure that init is called once on one core and mtb_ipc_get_handle
 * is called on remaining core(s).
 *
 * @param  obj              - Object for the IPC library instance
 * @param  shared_data      - pointer to the allocated shared memory object. \ref
 * MTB_IPC_SHARED_DATA_ALLOC macro can (and not mandatory) be used in order to
 * allocate memory for shared data (mtb_ipc_shared_t) in shared section.
 * @param config            - The user-provided configuration.
 * Fields internal_channel_index, semaphore_irq, queue_irq, semaphore_num
 * are expected to be filled by user before initialization.
 * Please refer to \ref subsection_ipc_snippet1 for
 * initialization guidance.
 *
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_TIMEOUT
 */
cy_rslt_t mtb_ipc_init(mtb_ipc_t* obj, mtb_ipc_shared_t* shared_data,
                       const mtb_ipc_config_t* config);

/** Reinitialize IPC Hardware
 *
 * If the underlying IPC hardware is reset (for example, because its containing power domain
 * was powered off and then subsequently powered back on), this function must be called immediately
 * after the IPC hardware is powered back on, before any other IPC operations are performed by any
 * core.
 *
 * \note It is only valid to call this function if `mtb_ipc_init` was previously called.
 * This function may only be called from the core which originally called `mtb_ipc_init`.
 *
 * @param  obj              - Object for the IPC library instance
 *
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_NOT_INITIALIZED
 */
cy_rslt_t mtb_ipc_reinit_hw(const mtb_ipc_t* obj);

/** Get initialized IPC library Driver
 * Call before any other IPC library functions.
 * Call from Cores other than that which called mtb_ipc_init to initialize the system,
 * timeout_ms is the timeout for waiting the initializing core to finish initialization.
 * This function initializes the Shared Memory Data structures for IPC library Semaphore and IPC
 * library Queue usage.

 * IRQ channels provided must be different than those used in \ref mtb_ipc_init on the
 * initialization core.
 *
 * @param  obj          - Object for the IPC library instance
 * @param  timeout_ms   - time in milliseconds for non-initializing core to wait for initializing
 * core to complete initialization
 * @param config        - User provided configuration of the IPC library instance, whose fields
 * internal_ipc_channel, semaphore_num must match config on the core that initialized to
 * ensure compatibility. Please refer to \ref subsection_ipc_snippet1
 * for initialization guidance.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_TIMEOUT
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_INVALID_IRQ_CHANNEL
 */
cy_rslt_t mtb_ipc_get_handle(mtb_ipc_t* obj, const mtb_ipc_config_t* config, uint64_t timeout_ms);

/** Process IPC library interrupt for Semaphores
 * Place inside an ISR registered for the semaphore interrupt specified for this core during init.
 *
 * This function is used to perform interrupt functionality for instantiated semaphore objects.
 *
 * @param  obj - Object for the IPC library instance
 *
 */
void mtb_ipc_semaphore_process_interrupt(mtb_ipc_t* obj);

/** Process IPC library interrupt for Queues
 * Place inside an ISR registered for the queue interrupt specified for this core during init.
 *
 * This function is used to perform interrupt functionality for instantiated queue objects.
 *
 * @param  obj - Object for the IPC library instance
 *
 */
void mtb_ipc_queue_process_interrupt(const mtb_ipc_t* obj);

/** Creates a single semaphore based on a given number.
 *  The semaphore number range starts at 0.
 *  the max number depends on a few factors max = _MTB_IPC_SEMA_COUNT - 1 (IPC driver semaphore) -
 * num_queues - (num_queues * num_processes_per_queue)
 * \note MTB_IPC_SEMAPHORE_DATA_ALLOC macro can (and not mandatory) be used in order to
 * allocate memory for semaphore data (mtb_ipc_semaphore_data_t) in shared section.
 * This function must be called before accessing the semaphore.
 * Only one core must call this function. Other cores call mtb_ipc_semaphore_get_handle
 * to retrieve this information after initialization.
 * @param[out] obj                   Pointer to an IPC object. Must be initialized by \ref
 * mtb_ipc_init
 * before initializing a semaphore.
 * @param[out] semaphore             Handle to an IPC semaphore. This handle exists per core and is
 * for api access to the shared sema_obj.
 * @param[in] sema_obj               Semaphore data stored in shared memory.
 * @param[in] config                 The user-provided configuration. Please refer to \ref
 * subsection_ipc_snippet1 for
 * initialization guidance
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_NUM_IN_USE
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *
 */
cy_rslt_t mtb_ipc_semaphore_init(mtb_ipc_t* obj, mtb_ipc_semaphore_t* semaphore,
                                 mtb_ipc_semaphore_data_t* sema_obj,
                                 const mtb_ipc_semaphore_config_t* config);

/** Finds an already initialized semaphore based on a given number.
 *
 * This function must be called before accessing the semaphore from a different Core than it was
 * initialized on.
 * mtb_ipc_semaphore_init must be called on the initializing core before this function is called,
 * else it will timeout.
 * @param[out] obj              Handle to an IPC object pointer.
 * @param[out] semaphore        Handle to an IPC semaphore. This handle exists per core and is
 * for api access to the shared semaphore data.
 * @param[in] semaphore_num     The semaphore number to get a pointer for
 * @param[in] timeout_us        Timeout (in uSec) to wait while trying to get the handle
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_NO_SEMA_AVAILABLE
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *
 */
cy_rslt_t mtb_ipc_semaphore_get_handle(mtb_ipc_t* obj, mtb_ipc_semaphore_t* semaphore,
                                       uint32_t semaphore_num, uint64_t timeout_us);

/** Frees the IPC semaphore.
 *
 * This function frees the resources associated with the semaphore.
 * @param[in] semaphore          The semaphore object.
 */
void mtb_ipc_semaphore_free(const mtb_ipc_semaphore_t* semaphore);

/** Takes/acquires a semaphore.
 *
 * If the semaphore is available, it is acquired and this function returns.
 * This function has a timeout argument (in microseconds). If the semaphore is not available, it
 * blocks until it
 * times out or succeeds in acquiring it.
 * @param[in] semaphore         The semaphore object.
 * @param[in] timeout_us        Timeout in microseconds. Value 0 can be used if no timeout needed
 * while
 * \ref MTB_IPC_NEVER_TIMEOUT can be used to make function block until semaphore is successfully
 * taken.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 */
cy_rslt_t mtb_ipc_semaphore_take(const mtb_ipc_semaphore_t* semaphore,
                                 uint64_t timeout_us);

/** Gives/releases a semaphore.
 *
 * The semaphore is released allowing other tasks waiting on the semaphore to take it.
 * @param[in] semaphore          The semaphore object.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 */
cy_rslt_t mtb_ipc_semaphore_give(const mtb_ipc_semaphore_t* semaphore);

/** Creates a new queue for a given IPC channel based on the given queue number and other
   parameters.
 *
 * This function requires \ref mtb_ipc_queue_data_t (queue_obj) pointer to shared memory.
 * mtb_ipc_queue_data_t is used by other tasks/CPUs to refer to the queue. Note that this function
 * must be called only by one of the tasks/CPUs for the same IPC channel.
 * This CPU can call the function multiple times for the same IPC
 * channel, but with a different queue number.
 * The IPC channel index must be different from the
 * channel index used for \ref mtb_ipc_init because that channel is used internally by the
 * semaphores.
 * \note MTB_IPC_QUEUE_DATA_ALLOC and MTB_IPC_QUEUE_POOL_ALLOC macro can (and not mandatory) be used
 * in order to
 * allocate memory for (respectively) queue data (mtb_ipc_queue_data_t) and queue pool in shared
 * section.
 * Please refer to implementation specific documentation for the requirements for memory allocation
 * if macro is not used.
 * Please refer to \ref subsection_ipc_snippet2 for initialization guidance.
 * @param[out] obj           Pointer to an IPC object. Must be initialized by \ref mtb_ipc_init
 * before initializing a queue.
 * @param[out] queue         Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @param[in] queue_obj      Queue data object stored in shared memory.
 * @param[in] config         The user-provided configuration.
 * Please refer to \ref subsection_ipc_snippet2 for initialization guidance.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND
 */
cy_rslt_t mtb_ipc_queue_init(mtb_ipc_t* obj, mtb_ipc_queue_t* queue,
                             mtb_ipc_queue_data_t* queue_obj, const mtb_ipc_queue_config_t* config);

/** Frees the queue.
 *
 * This operation only removes the queue handle from the list of available queues. The queue pool
 * and the queue
 * handle allocated in the shared memory need to be freed (if dynamically allocated) by the
 * application.
 * @param[out] queue         Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 *
 */
void mtb_ipc_queue_free(mtb_ipc_queue_t* queue);

/** Gets a handle pointer for a given IPC channel and queue number.
 *
 * This function should be called by other tasks/CPUs that have not called the initialization
 * function.
 * Unpredicted behavior can happen if this function is called before \ref mtb_ipc_queue_init. Please
 * refer to implementation specific documentation for additional details.
 * @param[out] obj              The IPC object handle.
 * @param[in] queue             Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @param[in] channel_num       IPC channel to use for the queue messaging.
 * @param[in] queue_num         Queue number.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND
 */
cy_rslt_t mtb_ipc_queue_get_handle(mtb_ipc_t* obj, mtb_ipc_queue_t* queue, uint32_t channel_num,
                                   uint32_t queue_num);

/** Registers a callback to be executed when certain events occur.
 *
 * @param[in] queue             Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @param[in] callback          The callback handler which will be invoked when an event triggers.
 * @param[in] callback_arg      Generic argument that will be provided to the callback when called.
 */
void mtb_ipc_queue_register_callback(mtb_ipc_queue_t* queue,
                                     mtb_ipc_queue_event_callback_t callback, void* callback_arg);

/** Enables which events trigger the callback execution.
 *
 * It can trigger when a new item is written to the queue, read from the queue, when the queue
 * becomes full,
 * when the queue becomes empty or when there is a reset. Note that these events might execute
 * callbacks
 * associated to all queues that belong to an IPC channel.
 * @param[in] queue             Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @param[in] event             The IPC event type
 * @param[in] enable            True to turn on specified events, False to turn off
 */
void mtb_ipc_queue_enable_event(mtb_ipc_queue_t* queue, mtb_ipc_queue_event_t event,
                                bool enable);

/** Adds one item to the queue.
 *
 * This function can be called by any task/CPU. This function has a timeout argument (in
 * microseconds).
 * If the queue is full, it stays there until it times out or the queue is no longer full.
 * This function can be blocking or non-blocking (timeout set to ZERO).
 * @param[in] queue             Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @param[in] msg               Location of message queue item
 * @param[in] timeout_us        Timeout in microseconds.
 * Value 0 can be used if no timeout needed while \ref MTB_IPC_NEVER_TIMEOUT can be
 * used to make function block until element is successfully put into the queue.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND
 *         MTB_IPC_RSLT_ERR_QUEUE_FULL
 */
cy_rslt_t mtb_ipc_queue_put(mtb_ipc_queue_t* queue, void* msg, uint64_t timeout_us);

/** Removes one item from the queue.
 *
 * This function can be called by any task/CPU. This function has a timeout argument (in
 * microseconds).
 * If the queue is empty, it stays there until it times out or the queue receives a new item.
 * This function can be blocking or non-blocking (timeout set to ZERO).
 * @param[in] queue             Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @param[out] msg              Location to copy message queue item to
 * @param[in] timeout_us        Timeout in microseconds.
 * Value 0 can be used if no timeout needed while \ref MTB_IPC_NEVER_TIMEOUT can be used to
 * make function block until element is successfully taken from the queue.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND
 *         MTB_IPC_RSLT_ERR_QUEUE_EMPTY
 */
cy_rslt_t mtb_ipc_queue_get(mtb_ipc_queue_t* queue, void* msg, uint64_t timeout_us);

/** Returns how many items are in the queue.
 *
 * This function can be called by any task/CPU.
 * @param[in] queue         Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @return Number of items in the queue
 */
uint32_t mtb_ipc_queue_count(const mtb_ipc_queue_t* queue);

/** Clears all the items in the queue.
 *
 * This function can be called by the any task/CPU.
 * @param[in] queue         Queue handle used to reference queue_obj store in shared memory. The
 * queue acts as the per-core handle for the shared data.
 * @return CY_RSLT_SUCCESS
           MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 */
cy_rslt_t mtb_ipc_queue_reset(const mtb_ipc_queue_t* queue);


/** Creates a single mailbox based on a given number.
 *  The mailbox number range is 0- \ref MTB_IPC_MAX_MBOXES.
 * \note MTB_IPC_MBOX_DATA_ALLOC macro can (and not mandatory) be used in order to
 * allocate memory for mailbox data (mtb_ipc_mbox_data_t) in  the shared section.
 * This function must be called before accessing the mailbox.
 * Only one core must call this function. Other cores have to call \ref
 * mtb_ipc_mbox_sender_get_handle
 * to retrieve this information after initialization.
 * Do not call this in an interrupt service routine.
 * @param[in] obj              Pointer to an IPC object. Must be initialized by \ref mtb_ipc_init
 * before initializing a mailbox.
 * @param[out] receiver        Handle to the mailbox on the core intended to be the receiver.
 * @param[in] mbox_obj         Mailbox data stored in shared memory.
 * @param[in] config           The user-provided configuration.
 * Please refer to \ref subsection_ipc_snippet1 for initialization guidance
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_NUM_IN_USE
 *         MTB_IPC_RSLT_ERR_MBOX_IDX_IN_USE
 *         MTB_IPC_RSLT_ERR_SEMA_FAIL
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *
 */
cy_rslt_t mtb_ipc_mbox_receiver_init(mtb_ipc_t* obj, mtb_ipc_mbox_receiver_t* receiver,
                                     mtb_ipc_mbox_data_t* mbox_obj,
                                     const mtb_ipc_mbox_config_t* config);

/** Gets a handle pointer for a given mailbox index.
 *
 * This function should be called by the core intended to be the mailbox sender.
 * Unpredicted behavior can happen if this function is called before \ref
 * mtb_ipc_mbox_receiver_init. Do not call this in an interrupt service routine.
 * @param[in] obj              The IPC object handle.
 * @param[out] sender          Handle to the mailbox on the core intended to be the sender
 * @param[in] mbox_idx         Mailbox number in range 0 - \ref MTB_IPC_MAX_MBOXES.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_SEMA_TAKEN
 *         MTB_IPC_RSLT_ERR_MBOX_NOT_FOUND
 */
cy_rslt_t mtb_ipc_mbox_sender_get_handle(mtb_ipc_t* obj, mtb_ipc_mbox_sender_t* sender,
                                         uint32_t mbox_idx);

/** Frees the mailbox and disconnects the receiver handle.
 * This should be called after freeing the sender on the other core.
 *
 * This operation only removes the mailbox handle from the list of available mailboxes. The mailbox
 * object
 *  allocated in the shared memory needs to be freed (if dynamically allocated) by the
 * application.
 * @param[out] receiver         Mailbox handle used to reference mbox_object stored in shared
 * memory. The receiver acts as the per-core handle for the shared data.
 *
 */
void mtb_ipc_mbox_receiver_free(mtb_ipc_mbox_receiver_t* receiver);

/** Disconnects the sender handle from the shared mailbox object.
 * This must be done before \ref mtb_ipc_mbox_receiver_free.
 *
 * This operation only removes the mailbox handle from the list of available mailboxes. The mailbox
 * object
 *  allocated in the shared memory needs to be freed (if dynamically allocated) by the
 * application.
 * @param[out] sender         Mailbox handle used to reference mbox_object stored in shared memory.
 * The sender acts as the per-core handle for the shared data.
 *
 */
void mtb_ipc_mbox_sender_free(mtb_ipc_mbox_sender_t* sender);

/** Registers a callback to be executed on the receiver core when certain events occur.
 *
 * @param[in] receiver          Mailbox handle used to reference mbox_obj store in shared memory.
 * The
 * receiver acts as the per-core handle for the shared data.
 * @param[in] callback          The callback handler which will be invoked when an event triggers.
 * @param[in] callback_arg      Generic argument that will be provided to the callback when called.
 */
void mtb_ipc_mbox_receiver_register_callback(mtb_ipc_mbox_receiver_t* receiver,
                                             mtb_ipc_mbox_event_callback_t callback,
                                             void* callback_arg);

/** Registers a callback to be executed on the sender core when certain events occur.
 *
 * @param[in] sender            Mailbox handle used to reference mbox_obj store in shared memory.
 * The
 * sender acts as the per-core handle for the shared data.
 * @param[in] callback          The callback handler which will be invoked when an event triggers.
 * @param[in] callback_arg      Generic argument that will be provided to the callback when called.
 */
void mtb_ipc_mbox_sender_register_callback(mtb_ipc_mbox_sender_t* sender,
                                           mtb_ipc_mbox_event_callback_t callback,
                                           void* callback_arg);

/** Adds item to the mailbox.
 *
 * This function can only be called by the sender for this mailbox.
 * If the mailbox is full, it stays there until it times out or the mailbox is no longer full.
 * This function can be blocking or non-blocking (timeout set to ZERO).
 * @param[in] sender            Mailbox handle used to reference mailbox object store in shared
 * memory.
 * The
 * sender acts as the per-core handle for the shared data.
 * @param[in] payload           Location of payload item
 * @param[in] timeout_us        Timeout in microseconds. Value 0 can be used if no timeout needed
 * while \ref MTB_IPC_NEVER_TIMEOUT can be used to make function block until element is
 * successfully put into the mailbox.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_TIMEOUT
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_MBOX_FULL
 */
cy_rslt_t mtb_ipc_mbox_sender_put(mtb_ipc_mbox_sender_t* sender, void* payload,
                                  uint64_t timeout_us);

/** Removes one item from the mailbox.
 *
 * This function can be only called by a receiver handle. This function has a timeout argument (in
 * microseconds).
 * If the mailbox is empty, it stays there until it times out or the mailbox receives a new item.
 * This function can be blocking or non-blocking (timeout set to ZERO).
 * @param[in] receiver         Mailbox handle used to reference mbox_obj store in shared memory.
 * The receiver acts as the per-core handle
 * for the shared data.
 * @param[out] payload         Location to copy message mailbox item to
 * @param[in] timeout_us       Timeout in microseconds.
 * Value 0 can be used if no timeout needed while \ref MTB_IPC_NEVER_TIMEOUT
 * can be used to make  function block until element is successfully taken
 * from the mailbox.
 * @return CY_RSLT_SUCCESS
 *         MTB_IPC_RSLT_ERR_INVALID_PARAMETER
 *         MTB_IPC_RSLT_ERR_TIMEOUT
 *         MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT
 *         MTB_IPC_RSLT_ERR_MBOX_EMPTY
 */
cy_rslt_t mtb_ipc_mbox_receiver_get(mtb_ipc_mbox_receiver_t* receiver, void** payload,
                                    uint64_t timeout_us);

/** Enables which events trigger the callback execution for the receiver.
 *
 * It can trigger for these events \ref mtb_ipc_mbox_event_t.
 * @param[in] receiver          Mailbox handle used to reference mbox_obj stored in shared memory.
 * The receiver acts as the per-core handle
 * for the shared data.
 * @param[in] event             The IPC mailbox event type
 * @param[in] enable            True to turn on specified events, False to turn off
 */
void mtb_ipc_mbox_receiver_enable_event(mtb_ipc_mbox_receiver_t* receiver,
                                        mtb_ipc_mbox_event_t event,
                                        bool enable);

/** Enables which events trigger the callback execution for the sender.
 *
 * It can trigger for these events \ref mtb_ipc_mbox_event_t.
 * @param[in] sender            Mailbox handle used to reference mbox_obj stored in shared memory.
 * The sender acts as the per-core handle
 * for the shared data.
 * @param[in] event             The IPC mailbox event type
 * @param[in] enable            True to turn on specified events, False to turn off
 */
void mtb_ipc_mbox_sender_enable_event(mtb_ipc_mbox_sender_t* sender, mtb_ipc_mbox_event_t event,
                                      bool enable);
#if defined(__cplusplus)
}
#endif


/** \} group_mtb_ipc */

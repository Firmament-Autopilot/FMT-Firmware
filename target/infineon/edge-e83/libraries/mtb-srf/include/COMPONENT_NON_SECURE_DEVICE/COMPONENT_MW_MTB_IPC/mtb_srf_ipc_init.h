/*******************************************************************************
* \file mtb_srf_ipc_init.h
*
* \brief
* Provides API declarations for the Secure Request IPC integration
*
*******************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

/**
 * \addtogroup group_mtb_srf_ipc_init Secure Request IPC integration Initialization
 * \{
 *
 * This library provides support for sending requests from an alternative core to the core with the
 * secure paritition. The non-secure partition acts as a relay to unpack the request sent over
 * Infineon's interprocessor communication library (MTB-IPC) and submit it in the same way as other
 * non-secure requests. The library also provides functionality to signal completion so the
 * requesting core can view the results. This is accomplished through two roles: Client and Relay.
 * The Client owns a pool of requests that are tied to IPC semaphores that will signal completion.
 * The relay receives unpacks requests on the core containing the secure region before processing
 * and signalling. This requires each of the contexts to be set up to create the relay relationship
 * and begin submitting requests. Refer to SRF documentation \ref group_mtb_srf for more information
 * on secure requests and request pools. The APIs for submiting a request remain the same on all
 * cores, but a client context must be set up on the core that needs IPC in order for the request to
 * be sent correctly. Secure Request IPC integration provides an implementation of contexts and
 * structures used to store states and signal information over Infineon's interprocessor
 * communication library (MTB-IPC). These contexts signify the role each process plays in ensuring
 * requests are safely submitted to the secure world. The implementation also provides a request
 * struct for carrying necessary data and signalling back. These are stored in a pool, similar to
 * SRF requests from the same core.
 *
 * Refer to \ref group_mtb_srf_ipc_code_snippets for more information.
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_result.h"
#include "mtb_srf.h"
#if !defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN)
#include "mtb_ipc.h"
#include "mtb_srf_ipc.h"
#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
#include "cyabs_rtos.h"
#endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */


/*******************************************************************************
*                           Defines
*******************************************************************************/

/** Macro for requests array shared memory allocation. It is not mandatory to use it for data
   allocation, user can allocate the memory in the more convenient for them way. Please refer to MTB
   SRF library documentation for the requirements for memory allocation if macro is not used.
 *
 * Can be used only in function scope.
 * Params:
 * requests - mtb_srf_ipc_packet_t** , which will point to the shared memory
 */
#define MTB_SRF_IPC_REQUEST_DATA_ALLOC(requests) \
    do { CY_SECTION_SHAREDMEM static mtb_srf_ipc_packet_t _mtb_srf_ipc_request_arr[MTB_SRF_POOL_SIZE] _MTB_SRF_DATA_ALIGN; shared = &requests; } while (0)

/*******************************************************************************
*                          Data Structures
*******************************************************************************/
/**
 * \addtogroup group_mtb_srf_ipc_structures
 * \{
 */

/** Secure request pool data structure with IPC integration. Users of the secure request pool
 * library should set up this structure based on the allocated shared memory. This is used by the
 * library to perform allocation and free operation.
 *
 * \note Client code should never directly interact with this struct.  All access shold be performed
 * via pool functions.
 */
struct mtb_srf_ipc_pool_s
{
    /** Request pool to align with semaphores for signalling. */
    mtb_srf_ipc_packet_t*       request_pool;
    /** Number of requests */
    uint32_t                    num_requests;
    /** A bitmap where ach bit indicates request object is available or not. It implies a
        max secure request pool size of 32. */
    uint32_t                    request_available;
    /** List of semaphores to allocate to each request */
    mtb_ipc_semaphore_t*        request_semaphores;
    /** Numnber of semaphore */
    uint32_t                    num_semaphores;
    /** A bitmap where ach bit indicates semaphore object is available or not. It implies a
        max semaphore pool size of 32. */
    uint32_t                    semaphore_available;
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    /** The semaphore, which is used to protect secure request arry */
    cy_semaphore_t              ipc_pool_request_arr_semaphore;
    /** The semaphore, which is used to protect request semaphores array */
    cy_semaphore_t              ipc_pool_sem_arr_semaphore;
    #endif
};

/** Ringbuffer implementation for storing requests */
typedef struct
{
    /** Buffer for storing packets */
    mtb_srf_ipc_packet_t**      buffer;
    /** Buffer head */
    size_t                      head;
    /** Buffer tail */
    size_t                      tail;
    /** Number of elements the buffer can contain */
    size_t                      max;
    /** Status on if the buffer is full */
    bool                        full;
} mtb_srf_ipc_ringbuf_t;

/**
 * @brief A Relay context, used to receive requests over IPC and then submit them as SRF requests to
 * the secure environment.
 */
struct mtb_srf_ipc_relay_context_s
{
    /** Number of semaphores */
    uint32_t                    num_semaphores;
    /** Array of IPC semaphores for signalling back to the client process.
     *  These match up with the semaphores on the client's pool */
    mtb_ipc_semaphore_t*        request_semaphores;
    /** Pointer to mailbox handle for sending data over IPC */
    mtb_ipc_mbox_receiver_t*    mailbox_handle;
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    /** Pointer RTOS queue for storing requests as they come in */
    cy_queue_t*                 ipc_req_queue;
    #else
    /** Ringbuffer for storing requests as they come in */
    mtb_srf_ipc_ringbuf_t       ipc_req_buffer;
    #endif
};

/**
 * @brief A Client context which is used to track the state of a core sending requests to the secure
 * environment
 *
 */
struct mtb_srf_ipc_client_context_s
{
    /** Pool of memory and semaphores used to allocate for requests from a client process through
     *  the relay process to the secure server. */
    mtb_srf_ipc_pool_t*         pool;
    /** Pointer to the mailbox used to sed/receive data over IPC */
    mtb_ipc_mbox_sender_t*      mailbox_handle;
};

/*******************************************************************************
*                       Config Structures
*******************************************************************************/
/**
 * @brief IPC Pool config, used to setup an SRF IPC pool.
 *
 */
typedef struct
{
    /** Pointer to a section of memory allocated by the caller for the request pool.
     *  Recommend using MTB_SRF_IPC_REQUEST_DATA_ALLOC to allocate the memory.
     */
    mtb_srf_ipc_packet_t*       request_pool;
    /** Numnber of requests */
    uint32_t                    num_requests;
    /** Pointer to array of initialized IPC semaphore handles. This must be in same order as the
     *  array on the relay context */
    mtb_ipc_semaphore_t*        request_semaphores;
    /** Numnber of semaphore */
    uint32_t                    num_semaphores;
} mtb_srf_ipc_pool_cfg_t;

/**
 * @brief A Client context config used to configure a client context
 */
typedef struct
{
    /** Pool of memory and semaphores used to allocate for requests from a client process through
     *  the relay process to the secure server. */
    mtb_srf_ipc_pool_t*         pool;
    /** Pointer to the mailbox used to sed/receive data over IPC */
    mtb_ipc_mbox_sender_t*      mailbox_handle;
} mtb_srf_ipc_client_context_cfg_t;

/**
 * @brief Config to setup a relay context.
 */
typedef struct
{
    /** Mailbox object for receiving secure requests over IPC */
    mtb_ipc_mbox_receiver_t*    mailbox;
    /** Number of semaphores */
    uint32_t                    num_semaphores;
    /** Pointer to array of initialized IPC semaphore handles. This must match the ordering of those
     *  on the client's IPC pool */
    mtb_ipc_semaphore_t*        request_semaphores;
    /** Number of entries in the pool on the client core */
    uint32_t                    num_requests;
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    /** Pointer to an initialized RTOS queue for storing requests as they come in */
    cy_queue_t*                 ipc_req_queue;
    #else
    /** A buffer of length num_requests that is used for holding addresses of recieved mailbox
     *  packets */
    mtb_srf_ipc_packet_t**      buffer;
    #endif
} mtb_srf_ipc_relay_context_cfg_t;

/**
 * @brief Config struct to set up entire SRF system including IPC mailbox, semaphores
 * and Client context
 */
typedef struct
{
    /** MTB IPC Mailbox index to use for SRF */
    uint32_t                    mbox_idx;
    /** Pointer to requests array to be used by MTB SRF IPC */
    mtb_srf_ipc_packet_t*       srf_ipc_requests;
    /** Number of entries in the pool on the client core */
    uint32_t                    num_requests;
    /** Pointer to the initialized IPC instance */
    mtb_ipc_t*                  ipc_instance;
    /** Pointer to array of handles for semaphores to be used by MTB SRF IPC */
    mtb_ipc_semaphore_t*        semaphore_handles;
    /** Number of semaphores */
    uint32_t                    num_semaphores;
    /** Pointer to mailbox handle to set up IPC mailbox */
    mtb_ipc_mbox_sender_t*      mailbox_handle;
    /** Pointer to SRF IPC pool*/
    mtb_srf_ipc_pool_t*         srf_ipc_pool;
    /** Pointer to IPC semaphore indexes to be used by SRF */
    uint32_t*                   ipc_sem_indexes;
} mtb_srf_ipc_client_init_cfg_t;

/**
 * @brief Config struct to set up entire SRF system including IPC mailbox, semaphores
 * and Relay context.
 */
typedef struct
{
    /** MTB IPC Mailbox index to use for SRF */
    uint32_t                    mbox_idx;
    /** MTB IPC Mailbox read_semaphore index to use for SRF */
    uint32_t                    mbox_read_sema_idx;
    /** MTB IPC Mailbox write semaphore index to use for SRF */
    uint32_t                    mbox_write_sema_idx;
    /** Pointer to array of data for semaphores to be used by MTB SRF IPC */
    mtb_ipc_semaphore_data_t*   semaphore_data;
    /** Pointer to Mailbox data to set up IPC mailbox */
    mtb_ipc_mbox_data_t*        mailbox_data;
    /** Pointer to the initialized IPC instance */
    mtb_ipc_t*                  ipc_instance;
    /** Pointer to array of handles for semaphores to be used by MTB SRF IPC */
    mtb_ipc_semaphore_t*        semaphore_handles;
    /** Number of semaphores */
    uint32_t                    num_semaphores;
    /** Pointer to mailbox handle to set up IPC mailbox */
    mtb_ipc_mbox_receiver_t*    mailbox_handle;
    /** Pointer to IPC semaphore indexes to be used by SRF */
    uint32_t*                   ipc_sem_indexes;
    /** Number of entries in the pool on the client core */
    uint32_t                    num_requests;
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    /** Pointer to an initialized RTOS queue for storing requests as they come in */
    cy_queue_t*                 ipc_req_queue;
    #else
    /** A buffer of length num_requests that is used for holding addresses of recieved mailbox
     *  packets */
    mtb_srf_ipc_packet_t**      buffer;
    #endif
} mtb_srf_ipc_relay_init_cfg_t;

/** \} group_mtb_srf_ipc_structures */
/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/
#if defined(MTB_SRF_SUBMIT_USE_IPC) || defined(DOXYGEN)
/** Initializes an secure request pool instance.
 * See snippets for more details on how to configure an SRF IPC pool.
 *
 * @param[in,out]   pool            Stores state that secure request pool needs to track between
 *                                  calls. The caller must allocate shared memory for this struct
 *                                  but should not depend on its contents.
 * @param[in]       cfg             Config struct to set up IPC SRF pool. Please refer to code
 * @return the status of the initialization
 */
cy_rslt_t mtb_srf_ipc_pool_init(mtb_srf_ipc_pool_t* pool,
                                mtb_srf_ipc_pool_cfg_t* cfg);

/** Initializes an secure request pool instance.
 *
 * @param[in,out]   client_context  Stores state that client process needs to track between calls.
 * @param[in]       cfg             Config containing items necessary for client communication
 * @return the status of the initialization
 */
cy_rslt_t mtb_srf_setup_client_context(mtb_srf_ipc_client_context_t* client_context,
                                       mtb_srf_ipc_client_context_cfg_t* cfg);

/**
 * @brief Initializes Semaphores, Mailbox, and sets up Client context
 * This function requires that the IPC section of mtb_srf_config.h is populated and IPC
 * instance in config struct is initialized.
 *
 * @param[in,out]   context         Client context to store all relevant MTB SRF IPC information
 * @param[in]       cfg             Config struct containing allocated memory and data structures
 * @return cy_rslt_t
 */
cy_rslt_t mtb_srf_ipc_client_init(mtb_srf_ipc_client_context_t* context,
                                  mtb_srf_ipc_client_init_cfg_t* cfg);
#elif !defined(MTB_SRF_SUBMIT_USE_IPC) || defined(DOXYGEN)
/** Initializes an secure request pool instance.
 *
 * @param[in,out]   relay_context   Stores state that relay process needs to track between calls.
 * @param[in]       cfg             Config struct to setup the relay context. This contains
 *                                  information on the MTB-IPC constructs to hook into as well as
 *                                  the pool of SRF requests.
 * @return the status of the initialization
 */
cy_rslt_t mtb_srf_setup_relay_context(mtb_srf_ipc_relay_context_t* relay_context,
                                      mtb_srf_ipc_relay_context_cfg_t* cfg);

/**
 * @brief Initializes Semaphores, Mailbox, and sets up Relay context
 * This function requires that the IPC section of mtb_srf_config.h is populated and IPC
 * instance in config struct is initialized.
 *
 * @param[in,out]     context       Relay context to store all relevant MTB SRF IPC information
 * @param[in]         cfg           Config struct containing allocated memory and data structures
 * @return cy_rslt_t
 */
cy_rslt_t mtb_srf_ipc_relay_init(mtb_srf_ipc_relay_context_t* context,
                                 mtb_srf_ipc_relay_init_cfg_t* cfg);

/**
 * \addtogroup group_mtb_srf_rtos_functions
 * \{
 */
#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) || defined(DOXYGEN)

/**
 * @brief Thread function for receiving requests over IPC. This will block the thread until a
 * request is available to be read. It will then queue up the request for processing.
 *
 * @param[in]       arg             Pointer to the relay context
 */
void mtb_srf_ipc_receive_thread(void* arg);

/**
 * @brief Thread function for processing requests. This takes them out of the queue and sends them
 * to the secure environment. It then notifies the client using an IPC semaphore.
 *
 * @param[in]       arg             Pointer to the relay context
 */
void mtb_srf_ipc_process_thread(void* arg);
#endif
/** \} group_mtb_srf_rtos_functions */
#endif // defined(MTB_SRF_SUBMIT_USE_IPC)

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

/** \} group_mtb_srf_ipc_init */
#endif // !defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN)

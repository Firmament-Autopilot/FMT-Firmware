/*******************************************************************************
* \file mtb_srf_ipc.h
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
 * \addtogroup group_mtb_srf_ipc Secure Request IPC integration
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
 * be sent correctly.
 *
 * Refer to \ref group_mtb_srf_ipc_code_snippets for more information.
 *
 ********************************************************************************
 * \section group_mtb_srf_ipc_prerequisites  Prerequisites
 ********************************************************************************
 * The IPC components of the SRF IPC integration must be set up prior to transfer. Please refer to
 * MTB-IPC documentation on how to setup an IPC instance and a mailbox for request transfer. The MTB
 * SRF IPC will by default consume MTB_SRF_IPC_SEMA_COUNT + 3 semaphores for its own use.
 *
 * \section section_impl_srf_ipc_request_data_ Request pool data memory allocation
 * Request pool data memory allocation can be done with help of MTB_SRF_IPC_REQUEST_DATA_ALLOC
 * macro, but using it is not mandatory, so user can allocate memory for the shared memory in any
 * convenient for them way. This struct is necessary to store and keep track of all shared objects
 * during operation.
 ********************************************************************************
 * \section group_mtb_srf_ipc_custom_packet  Custom Packet
 ********************************************************************************
 * Many APIs can be overridden with macros to allow custom implementations. To support this, the
 * mtb_srf_ipc_packet_t type can be overriden via the define MTB_SRF_IPC_CUSTOM_PACKET_TYPE.
 * However, the various APIs have minimum requirements on what this type defines.
 *
 * mtb_srf_ipc_request_submit, overridden via MTB_SRF_CUSTOM_IPC_REQUEST_SUBMIT, requires all the
 * default packet struct members to operate.
 *
 * mtb_srf_ipc_process_request, overridden via MTB_SRF_CUSTOM_PROCESS_REQUEST, requires the ioVec
 * pointers and counts (inVec_ptr, inVec_cnt_ns, outVec_ptr, outVec_cnt_ns).
 *
 * mtb_srf_ipc_signal_complete, which cannot be overriden, requires the semaphore_idx member.
 *
 * All other APIs interact with the packet type as a pointer and aren't affected by the contents.
 *
 *********************************************************************************
 * \section group_mtb_srf_ipc_code_snippets  Code Snippets
 ********************************************************************************
 * Register a Client and transfer request
 * \snippet mtb_srf_snip.c snippet_mtb_srf_ipc_client
 *
 * Register a Relay
 * \snippet mtb_srf_snip.c snippet_mtb_srf_ipc_relay_setup
 * Start Relay (Non-RTOS)
 * \snippet mtb_srf_snip.c snippet_mtb_srf_ipc_relay_transfer_nonrtos
 * Start Relay (RTOS)
 * \snippet mtb_srf_snip.c snippet_mtb_srf_ipc_relay_transfer_rtos
 *
 * Quick init of Client
 * \snippet mtb_srf_snip.c snippet_mtb_srf_ipc_client_init
 * Quick init of Relay
 * \snippet mtb_srf_snip.c snippet_mtb_srf_ipc_relay_init
 *
 * \defgroup group_mtb_srf_ipc_structures Data Structures
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_result.h"
#include "mtb_srf.h"

/* MTB_SRF_IPC_CUSTOM_PACKET_TYPE allows to define a custom packet structure for
 * SRF IPC communication */
#ifdef MTB_SRF_IPC_CUSTOM_PACKET_TYPE
#include "mtb_srf_ipc_custom_packet.h"
#endif /* MTB_SRF_IPC_CUSTOM_PACKET_TYPE */

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

#if !defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN)
/*******************************************************************************
*                          Data Structures
*******************************************************************************/

#ifndef MTB_SRF_IPC_CUSTOM_PACKET_TYPE
/**
 * \addtogroup group_mtb_srf_ipc_structures
 * \{
 */
/**
 * @brief Default request structure for use in IPC-enabled SRF
 * This couples normal SRF data with an IPC semaphore index to provide cross-core signalling. This
 * acts as a packet that the relay can process. inVec_ns/outVec_ns must be allocated from a pool
 * before they are pointed to by inVec_ptr/outVec_ptr.
 *
 */
typedef struct _MTB_SRF_DATA_ALIGN
{
    mtb_srf_invec_ns_t* inVec_ptr;    //!< Pointer to vector for all operation and SRF input
    uint8_t inVec_cnt_ns;             //!< Number of input vectors in inVec_ns array
    mtb_srf_outvec_ns_t* outVec_ptr;  //!< Pointer to vector for all operation and SRF output
    uint8_t outVec_cnt_ns;            //!< Number of output vectors in outVec_ns array
    uint16_t semaphore_idx;           //!< Index in the semaphore array
                                      //!< for semaphore used to signal completion.
    cy_rslt_t request_rslt;           //!< Result of the SRF operation, which may not be success
                                      //!< even if the IPC request succeeded
} mtb_srf_ipc_packet_t;
/** \} group_mtb_srf_ipc_structures */
#endif /* MTB_SRF_IPC_CUSTOM_PACKET_TYPE */

/** \cond INTERNAL */
/**
 * Forward declaration for IPC Secure request pool data structure \ref mtb_srf_ipc_pool_s
 */
struct mtb_srf_ipc_pool_s;
/**
 * Forward declaration for IPC Client context \ref mtb_srf_ipc_client_context_s
 */
struct mtb_srf_ipc_client_context_s;
/**
 * Forward declaration for IPC Relay context \ref mtb_srf_ipc_relay_context_s
 */
struct mtb_srf_ipc_relay_context_s;

/**
 * Forward declaration for IPC Secure request pool data structure \ref mtb_srf_ipc_pool_t
 */
typedef struct mtb_srf_ipc_pool_s mtb_srf_ipc_pool_t;
/**
 * Forward declaration for IPC client context \ref mtb_srf_ipc_client_context_s
 */
typedef struct mtb_srf_ipc_client_context_s mtb_srf_ipc_client_context_t;
/**
 * Forward declaration for IPC Relay context \ref mtb_srf_ipc_relay_context_t
 */
typedef struct mtb_srf_ipc_relay_context_s mtb_srf_ipc_relay_context_t;
/** \endcond */

/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/
#if defined(MTB_SRF_SUBMIT_USE_IPC) || defined(DOXYGEN)

/** Submit a request from another core to a TrustZone enabled core
 *
 * \note Calling this API is handled internally.  When the IPC library is present, calling
 * \ref mtb_srf_request_submit from another core will redirect to this API.  If the default
 * \ref mtb_srf_request_submit is disabled via the Makefile define MTB_SRF_CUSTOM_REQUEST_SUBMIT,
 * it becomes the user's responsibility to call this on non-Trustzone cores.
 *
 * @param[in,out] client_context  Stores state that client process needs to track between
 *                                calls.
 * @param[in,out] inVec_ns        Vector for all operation and SRF input
 * @param[in]     inVec_cnt_ns    Number of input vectors in inVec_ns array
 * @param[in,out] outVec_ns       Vector for all operation and SRF output
 * @param[in]     outVec_cnt_ns   Number of output vectors in outVec_ns array
 *
 * @return the status of submission */
cy_rslt_t mtb_srf_ipc_request_submit(mtb_srf_ipc_client_context_t* client_context,
                                     mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                                     mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns);

/**
 * Allocate IPC semaphore to use in signalling
 *
 * @param[in,out] pool            The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in,out] sema_idx        Pointer to the semaphore index that will be allocated.
 * @param[in]     timeout_us      Timeout to wait in microsecond.  Set to 0 to perform no wait.
 *
 * @return the status of allocate request
 */
cy_rslt_t mtb_srf_ipc_pool_semaphore_alloc(mtb_srf_ipc_pool_t* pool, uint16_t* sema_idx,
                                           uint32_t timeout_us);

/** Allocate secure request object within an SRF IPC request pool to act as a packet.
 *
 * @param[in,out] pool            The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in,out] req             Pointer to an SRF IPC request object.
 * @param[in]     timeout_us      Timeout to wait in microsecond.  Set to 0 to perform no wait.
 *
 * \note The timeout_us must always be 0 if allocation is invoked from an interrupt context.
 * @return the status of allocate request
 */
cy_rslt_t mtb_srf_ipc_pool_req_alloc(mtb_srf_ipc_pool_t* pool, mtb_srf_ipc_packet_t** req,
                                     uint32_t timeout_us);

/** Deallocate an IPC semaphore
 *
 * @param[in,out] pool            The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in,out] sema_idx        Index of semaphore to be deallocated from the pool.
 *
 * @return the status of allocate request
 */
cy_rslt_t mtb_srf_ipc_pool_semaphore_free(mtb_srf_ipc_pool_t* pool, uint16_t sema_idx);

/** Free secure request object within an SRF IPC request pool.
 *
 * @param[in,out] pool            The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in]     req             Pointer to an MB SRF request for the pool to free
 *
 * @return the status of free request
 */
cy_rslt_t mtb_srf_ipc_pool_req_free(mtb_srf_ipc_pool_t* pool, const mtb_srf_ipc_packet_t* req);

/** Sends a request from the non-secure side to the secure and blocks for a timeout until request is
   processed.
 *
 * This is a function that should be added any implementation of \ref mtb_srf_request_submit,
 * either within the BSP or custom.
 *
 * @param[in,out] client_context  Stores state that client process needs to track between calls.
 * @param[in,out] request         Pointer to SRF IPC request object that will be sent by mailbox.
 *                                If this is of a type other than default \ref mtb_srf_ipc_packet_t,
 *                                then please override mtb_srf_ipc_process_request to handle
 *                                additional parameters.
 * @param[in]     timeout_us      Timeout (in uS) to attempt to send request over IPC and
 *                                subsequently wait for a response.
 *
 * @return the status of submission */
cy_rslt_t mtb_srf_ipc_request_send(mtb_srf_ipc_client_context_t* client_context,
                                   mtb_srf_ipc_packet_t* request, uint64_t timeout_us);

#endif // defined(MTB_SRF_SUBMIT_USE_IPC) || defined(DOXYGEN)

#if !defined(MTB_SRF_SUBMIT_USE_IPC) || defined(DOXYGEN)

/**
 * @brief Receives an SRF request over IPC and adds to either the queue if using an RTOS or the
 * ringbuffer.
 * @param[in,out] relay_context   Stores state that client process needs to track between calls.
 * @param[in]     timeout_us      Timeout (in uS) to attempt to receive request over IPC.
 * @return the status of the receive.
 */
cy_rslt_t mtb_srf_ipc_receive_request(mtb_srf_ipc_relay_context_t* relay_context,
                                      uint64_t timeout_us);
/**
 * @brief Process the SRF request from IPC.
 * @param[in,out] request         Secure request to prepare for processing. If this is of a type
 *                                other than default \ref mtb_srf_ipc_packet_t, please override this
 *                                function to handle additional parameters.
 * @return the status of the request submit.
 */
cy_rslt_t mtb_srf_ipc_process_request(mtb_srf_ipc_packet_t* request);

/**
 * @brief Process the SRF request pending in either the queue if using an RTOS or the ringbuffer.
 * @param[in,out] relay_context   Stores state that client process needs to track between calls.
 * @return the status of the request submit.
 */
cy_rslt_t mtb_srf_ipc_process_pending_request(mtb_srf_ipc_relay_context_t* relay_context);

/**
 * @brief Signals to client that secure request has been completed and output can be read.
 *
 * @param[in,out] relay_context   Stores state that client process needs to track between calls.
 * @param[in] request             Secure request to prepare for processing.
 * @return the status of the signalling
 */
cy_rslt_t mtb_srf_ipc_signal_complete(mtb_srf_ipc_relay_context_t* relay_context,
                                      mtb_srf_ipc_packet_t* request);

#endif // !defined(MTB_SRF_SUBMIT_USE_IPC) || defined(DOXYGEN)

#endif // !defined(COMPONENT_SECURE_DEVICE)
/** \} group_mtb_srf_ipc */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

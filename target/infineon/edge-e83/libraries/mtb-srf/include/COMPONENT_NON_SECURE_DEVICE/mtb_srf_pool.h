/*******************************************************************************
* \file mtb_srf_pool.h
*
* \brief
* Provides API declarations for the Secure Request Pool Library
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
 * \addtogroup group_mtb_srf_pool Secure Request Pool Library
 * \{
 *
 * Secure Request Pool Library provides an implementation of secure request pool
 * mtb_srf_pool_t, which is composed of multiple secure request objects mtb_srf_request_ns_t.
 * Secure request objects need to be accessible by both the secure and non-secure world. In
 * practice, this means that they should be allocated out of the "shared memory" region rather than
 * e.g. off the stack.
 * This, in turn, means that any RAM which is allocated for secure request pool description struct
 * mtb_srf_pool_t is statically allocated for the lifetime of the program. Therefore, it would
 * be inefficient for every secure request client to allocate its own secure request object. There
 * needs to be a means for sharing.
 * This need is satisfied by a secure request pool, which allows multiple secure request clients to
 * share a small number of pre-allocated secure request pool description struct.
 * A secure request pool is specific to a particular non-secure processing environment. I.e. in a
 * system where both the CM33_NS and the CM55 are making secure requests, there would be two secure
 * request pools, one for the CM33_NS and one for the CM55.
 * Usage of this mechanism is optional. If needed to satisfy some special case, a secure request
 * client can allocate their own custom secure request object and use that instead.
 *
 * <b>Features:</b>
 * * Secure request pool initialization can be performed.
 * * Secure reqest object can be allocated or freed.
 *
 ********************************************************************************
 * \section group_mtb_srf_pool_prerequisites  Prerequisites
 ********************************************************************************
 * There are three parameters which define a secure request pool:
 * * Maximum input argument count MTB_SRF_MAX_ARG_IN_SIZE: This will default to 5.
 * * Maximum output argument count MTB_SRF_MAX_ARG_OUT_SIZE: This will default to 1 because most
 * functions return only one value, but is left configurable for flexibility and future proofing.
 * * Number of requests allocated MTB_SRF_POOL_SIZE: This determines the number of requests
 * that can be pending in parallel (if the system is configured to permit non-secure threads or
 * interrupts to pre-empt secure processing). This will default to 3 in RTOS-aware usage, and 1
 * otherwise.
 * A default secure request pool is created during initialization of the secure request context, and
 * uses the values described in the previous section. These values can be overridden by defining the
 * corresponding macro in mtb_srf_config.h
 *
 * Pool initialization can be performed explicitly via the mtb_srf_pool_init function.
 *
 * A secure request pool consolidates three user-provided memory allocations:
 * * Array of pre-allocated secure request description structs
 * * Array that can be used to store input arguments
 * * Array that can be used to store output arguments.
 *
 * The input and output argument arrays are shared equally between all requests in the pool. For
 * example, if a secure reqest pool contains three entries and args_in_length is 12, then each
 * secure request would support up to 4 input arguments. The benefit is that the pool initialization
 * process is simpler because there are fewer allocations required
 *
 * A default pool is defined in the BSP and initialized as part of the non-secure application
 * initialization. This default pool is expected to be sufficient for the majority of uses cases, so
 * users should generally not need to do any manual allocation or management of pools.
 * \note the default secure request pool setup is only performed when we are not running in the
 * secure world. This is because the secure request pools are the means by which the non-secure
 * world submits requests to the secure world. There would be no reason for the secure world to
 * submit a request to itself.
 *
 * Secure request object allocation is performed via the mtb_srf_pool_allocate function.
 * Secure request object free is performed via the mtb_srf_pool_free function.
 *
 *********************************************************************************
 * \section group_mtb_srf_pool_code_snippets  Code Snippets
 ********************************************************************************
 * Init sequence for secure request pool
 * \snippet mtb_srf_snip.c snippet_mtb_srf_pool_init
 *
 * Allocation/Free operation
 * \snippet mtb_srf_snip.c snippet_mtb_srf_pool_allocate_free
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_result.h"
#include "mtb_srf.h"

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Defines
*******************************************************************************/
/** Round up */
#ifndef MTB_SRF_ROUND_UP
  #define MTB_SRF_ROUND_UP(N, S) ((((N) + (S) - 1UL) / (S)) * (S))
#endif

/** Address alignment value of pool in bytes */
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define MTB_SRF_POOL_ALIGNMENT    (__SCB_DCACHE_LINE_SIZE)
#else
#define MTB_SRF_POOL_ALIGNMENT    (4UL)
#endif
/*******************************************************************************
*                           Enums
*******************************************************************************/

/*******************************************************************************
*                          Data Structures
*******************************************************************************/
/**
 * Forward declaration for Secure request pool data structure mtb_srf_pool_s
 */
struct mtb_srf_pool_s;
/**
 * Forward declaration for Secure request pool data structure mtb_srf_pool_t
 */
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 1.1', 1, \
                             'mtb_srf_pool.h sshould not include any RTOS API, so intentionally declare same typedef mtb_srf_pool_t')
typedef struct mtb_srf_pool_s mtb_srf_pool_t;
CY_MISRA_BLOCK_END('MISRA C-2012 Rule 1.1')
/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/
/** Allocate secure request object within an secure request pool.
 *
 * @param[in,out] pool                  The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in,out] inVec                 Pointer to an array of input vectors for the pool to
 *                                      allocate
 * @param[in,out] outVec                Pointer to an array of output vectors for the pool to
 *                                      allocate
 * @param[in]     timeout_us            Timeout to wait in microsecond.  Set to 0 to perform no
 *                                      wait.
 *
 * \note The timeout_us must always be 0 if allocation is invoked from an interrupt context.
 * @return the status of allocate request
 */
cy_rslt_t mtb_srf_pool_allocate(mtb_srf_pool_t* pool, mtb_srf_invec_ns_t** inVec,
                                mtb_srf_outvec_ns_t** outVec, uint32_t timeout_us);

/** Free secure request object within an secure request pool.
 *
 * @param[in,out] pool                  The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in]     inVec                 Pointer to an input vectors for the pool to free
 * @param[in]     outVec                Pointer to an output vectors for the pool to free.
 *                                      This must belong to the same request as inVec
 *
 * @return the status of free request
 */
cy_rslt_t mtb_srf_pool_free(mtb_srf_pool_t* pool, const mtb_srf_invec_ns_t* inVec,
                            const mtb_srf_outvec_ns_t* outVec);

/** Get the input and output length per entry configuration of a pool that were set at
   initalization.
 *
 * @param[in,out] pool                  The pool object that was populated by \ref mtb_srf_pool_init
 * @param[in,out] input_len_per_entry   Value to store the input length per entry
 * @param[in,out] output_len_per_entry  Value to store the output length per entry
 *
 * @return the status of the initialization
 */
cy_rslt_t mtb_srf_pool_get_entry_len(mtb_srf_pool_t* pool, size_t* input_len_per_entry,
                                     size_t* output_len_per_entry);

/** \} group_mtb_srf_pool */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

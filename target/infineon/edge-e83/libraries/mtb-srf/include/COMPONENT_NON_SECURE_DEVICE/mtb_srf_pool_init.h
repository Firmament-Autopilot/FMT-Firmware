/*******************************************************************************
* \file mtb_srf_pool_init.h
*
* \brief
* Provides API declarations for the Secure Request Pool Init Library
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
 * \addtogroup group_mtb_srf_pool_init Secure Request Pool Init ibrary
 * \{
 *
 * Secure Request Pool Init Library provides an implementation of secure request pool
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
 * Refer to \ref group_mtb_srf_pool for more information.
 *
 * \defgroup group_mtb_srf_pool_structures Data Structures
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cy_result.h"
#include "mtb_srf.h"
#include "mtb_srf_pool.h"
#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
#include "cyabs_rtos.h"
#endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Defines
*******************************************************************************/

/** A tool to calculate how much memory to provide for a pool */
#define MTB_SRF_POOL_ENTRY_SIZE(input_values_length, output_values_length) \
        (MTB_SRF_ROUND_UP(sizeof(mtb_srf_input_ns_t) + input_values_length, MTB_SRF_POOL_ALIGNMENT) + \
        MTB_SRF_ROUND_UP(sizeof(mtb_srf_output_ns_t) + output_values_length, MTB_SRF_POOL_ALIGNMENT) + \
        MTB_SRF_ROUND_UP((sizeof(mtb_srf_invec_ns_t) * MTB_SRF_MAX_IOVEC), MTB_SRF_POOL_ALIGNMENT) + \
        MTB_SRF_ROUND_UP((sizeof(mtb_srf_outvec_ns_t) * MTB_SRF_MAX_IOVEC), MTB_SRF_POOL_ALIGNMENT))

#if (MTB_SRF_POOL_SIZE > 32UL)
#error A mixumum of 32 pool size are suppported
#endif

/*******************************************************************************
*                           Enums
*******************************************************************************/

/*******************************************************************************
*                          Data Structures
*******************************************************************************/
/**
 * \addtogroup group_mtb_srf_pool_structures
 * \{
 */

/** Secure request pool data structure. Users of the secure request pool library should set up this
   structure based on the allocated shared memory. This is used by the library to perform allocation
   and free operation.

   \note Client code should never directly interact with this struct.  All access shold be performed
   via pool functions.
 */
CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 1.1', 1, \
                             'mtb_srf_pool.h should not include any RTOS API, so intentionally declare same typedef mtb_srf_pool_t')
struct mtb_srf_pool_s
{
    /** Pointer to memory allocated for the pool to use */
    uint32_t* data;
    /** Indicates the number of secure request objects */
    size_t   num_entries;
    /* Length of a mtb_srf_input_ns_t.input_values array */
    size_t   input_len_per_entry;
    /* Length of a mtb_srf_output_ns_t.output_values array */
    size_t   output_len_per_entry;
    /** A bitmap where ach bit indicates secure request object is available or not. It implies a
        max secure request pool size of 32. */
    uint32_t avail_for_alloc;
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    /** The semaphore, which is used to protect secure request pool */
    cy_semaphore_t mtb_srf_pool_semaphore;
    #endif
};

CY_MISRA_BLOCK_END('MISRA C-2012 Rule 1.1')

/** \} group_mtb_srf_pool_structures */
/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/
/** Initializes an secure request pool instance.
 *
 * @param[in,out] pool                  Stores state that secure request pool needs to track between
 *                                      calls. The caller must allocate shared memory for this
 *                                      struct
 *                                      but should not depend on its contents.
 * @param[in]     allocated_mem         Pointer to a section of memory allocated by the caller for
 *                                      the pool to use.  Recommend using (MTB_SRF_POOL_ENTRY_SIZE
 *                                      * num_entries) to calculate for custom pools
 * @param[in]     num_entries           The number of secure request objects that should fit into
 *                                      the pool
 * @param[in]     input_len_per_entry   The length of input argument array. The default value is
 *                                      MTB_SRF_MAX_ARG_IN_SIZE
 * @param[in]     output_len_per_entry  The length of output argument array. The default value is
 *                                      MTB_SRF_MAX_ARG_OUT_SIZE
 *
 * @return the status of the initialization
 */
cy_rslt_t mtb_srf_pool_init(mtb_srf_pool_t* pool, uint32_t* allocated_mem,
                            size_t num_entries,
                            size_t input_len_per_entry,
                            size_t output_len_per_entry);

/** \} group_mtb_srf_pool_init */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

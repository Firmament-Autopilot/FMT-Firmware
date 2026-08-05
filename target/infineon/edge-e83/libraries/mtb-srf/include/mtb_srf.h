/*******************************************************************************
* \file mtb_srf.h
*
* \brief
* Provides API declarations for the Secure Request Framework Library
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
 * \addtogroup group_mtb_srf Secure Request Framework
 * \{
 * The Secure Request Framework (SRF) exists to provide a reusable infastructure for implementing
 * multiple secure operations via a single non-secure-callable entry point.  This framework is
 * designed to be generic with no dependency on or knowledge of any particular hardware operation.
 * It can be used directly by user code.
 *
 * Through the SRF, the secure world exposes one or more operations, which are roughly equivalent
 * to a function.  These operations can be combined into a module - a unit of integration between
 * different entities which wish to expose their operations.  For example, the Peripheral Driver
 * Library (PDL) would be one module.
 *
 * The non-secure world invokes an operation by submitting a secure request via the
 * \ref mtb_srf_request_submit API.  This request is then passed to the secure world, where its
 * memory addresses are validated, as are the permissions required to perform the operation.  A
 * default validation strategy is performed through \ref mtb_srf_memory_validate, and further
 * operation specific validation should be done inside the operation itself.  The default
 * \ref mtb_srf_memory_validate API checks that all memory passed in is accessible to the NS side,
 * ensured the minimum number of inVec and outVec are present, and that a legal number of ioVec
 * (input-output vectors) have been provided (discussed further below).  This API is defined weakly
 * to enable overriding with a custom implementation.
 *
 * The \ref mtb_srf_request_submit API accepts inVec and outVec arrays.  The max total number of
 * vectors cannot exceed #MTB_SRF_MAX_IOVEC.  That is, should the max ioVec be 4, legal
 * combinations could be one inVec and three outVec, two of each, or three inVec and one outVec.
 * Unused vectors should be set to NULL.
 *
 * \note It is possible to completely disable the SRF by adding a define for CY_SRF_DISABLE
 * in the cases where the SRF library is included as a default dependency but not used.
 *
 ********************************************************************************
 * \section group_mtb_srf_prerequisites  Prerequisites
 ********************************************************************************
 * This framework requires the user manage a mtb_srf_config.h file that contains macros for
 * the various modules that use the SRF.  The file comes with the default macros for user and
 * PDL module IDs.  Should a library be added to the project that uses SRF, that library should
 * generate a relevant error message requesting that its module ID is added to the
 * mtb_srf_config.h file.  The exact values of the module IDs do not matter, as long as they are
 * unique and unsigned integers.  The number of SRF modules should be defined as
 * MTB_SRF_MODULE_COUNT.  The SRF uses this macro internally to determine how many module IDs
 * exist in a given project.
 *
 *********************************************************************************
 * \section group_mtb_srf_code_snippets  Code Snippets
 ********************************************************************************
 * Register module operation
 * \snippet mtb_srf_snip.c snippet_mtb_srf_register_module
 *
 * Submit request operation
 * \snippet mtb_srf_snip.c snippet_mtb_srf_submit_request
 *
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "cmsis_compiler.h"
#include "cy_result.h"
#include "cy_utils.h"
#include "mtb_srf_config.h"
#include "mtb_srf_iovec.h"

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*******************************************************************************
*                           Defines
*******************************************************************************/

/** An invalid parameter value is passed in */
#define MTB_SRF_ERR_BAD_PARAM                 \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 0)
/** Unknown operation requested */
#define MTB_SRF_ERR_UNKNOWN_OPERATION         \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 1)
/** Unknown module requested */
#define MTB_SRF_ERR_UNKNOWN_MODULE            \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 2)
/** Request violates resource security permissions */
#define MTB_SRF_ERR_SECURITY_POLICY_VIOLATION \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 3)
/** Module index provided at registration is invalid */
#define MTB_SRF_ERR_MODULE_ID_INVALID \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 4)
/** Failed to allocate/free secure request */
#define MTB_SRF_ERR_ALLOCATE_FREE \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 5)
/** Ringbuffer is empty */
#define MTB_SRF_ERR_RINGBUF_EMPTY \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 6)
/** Ringbuffer is full */
#define MTB_SRF_ERR_RINGBUF_FULL \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 7)
/** No space left in secure argument buffer */
#define MTB_SRF_ERR_ARGBUFF_FULL \
    CY_RSLT_CREATE(CY_RSLT_TYPE_ERROR, CY_RSLT_MODULE_MIDDLEWARE_SRF, 8)

#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
/** This define can be used for aligning address of the data structures with enabled Data Cache */
#define _MTB_SRF_DATA_ALIGN       CY_ALIGN(__SCB_DCACHE_LINE_SIZE)
#else
/** This define can be used for aligning address of the data structures with enabled Data Cache */
#define _MTB_SRF_DATA_ALIGN
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
/** Indicates that an operation should wait indefinitely */
#define MTB_SRF_NEVER_TIMEOUT   (0xFFFFFFFFU)

/** Function pointer to the operation.  May perform custom validation, if any, before executing
   request
 * @param[in] inputs_ns                 Struct describing the operation and containing non-pointer
                                        input arguments
 * @param[in,out] outputs_ns            Struct containing the non-pointer output arguments
 * @param[in,out] inputs_ptr_ns         Array of InVec arguments.  InVec[0] is passed as input_ns,
 *                                      so this array starts at inVec[1].
 * @param[in]     inputs_ptr_cnt_ns     Number of entries in inputs_ptr_ns
 * @param[in,out] outputs_ptr_ns        Array of outVec arguments.  OutVec[0] is passed as
 *                                      output_ns, so this array starts at outVec[1].
 * @param[in]     outputs_ptr_cnt_ns    Number of entries in outputs_ptr_ns
 *
 * @return Result of validation check
 */
typedef cy_rslt_t (* mtb_srf_op_fn_t) (mtb_srf_input_ns_t* inputs_ns,
                                       mtb_srf_output_ns_t* outputs_ns,
                                       mtb_srf_invec_ns_t* inputs_ptr_ns,
                                       uint8_t inputs_ptr_cnt_ns,
                                       mtb_srf_outvec_ns_t* outputs_ptr_ns,
                                       uint8_t outputs_ptr_cnt_ns);

#if defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN)

/** Permission structure.  This is used to designate hardware resource permissions */
typedef struct
{
    void*                   base;               //!< Register base address for the hardware
                                                //!< resource. If not applicable, set to NULL
    uint16_t                sub_block;          //!< Sub-block index, if applicable. E.g. TCPWM
                                                //!< counter index. If not applicable, set to 0
    bool                    write_allowed;      //!< If true, operations that modify the hardware
                                                //!< state are allowed
} mtb_srf_permission_s_t;

/** Operation description structure. An operation is generally equivalent to a function that would
 * be called in a non-secure use case.
 */
typedef struct
{
    uint8_t                 module_id;          //!< Module ID for this operation. Must be unique
                                                //!< within this operation
    uint8_t                 submodule_id;       //!< Submodule ID for this operation.
    uint8_t                 op_id;              //!< ID for this operation.
    bool                    write_required;     //!< If this operation requires modifying the
                                                //!< hardware state
    mtb_srf_op_fn_t         impl;               //!< Function pointer to the operation.  May perform
                                                //!< custom validation, if any, before executing
                                                //!< request
    size_t                  input_values_len;   //!< Required size of input_values
    size_t                  output_values_len;  //!< Required size of output_values
    size_t                  input_len[MTB_SRF_MAX_IOVEC - 1];  //!< Minimum length of inVec pointer
                                                               //!< arguments needed (From First
                                                               //!< element)
    bool                    needs_copy[MTB_SRF_MAX_IOVEC - 1]; //!< Whether an input should be
                                                               //!< copied into secure memory before
                                                               //!< processing. This should be set
                                                               //!< to true if validation decisions
                                                               //!< are made based on data in this
                                                               //!< argument.
                                                               //!< inVec[0] is always copied.
    size_t                  output_len[MTB_SRF_MAX_IOVEC - 1]; //!< Minimum length of outVec pointer
                                                               //!< arguments needed (From First
                                                               //!< element)
    mtb_srf_permission_s_t* allowed_rsc;        //!< List of hardware resources on which non-secure
                                                //!< is permitted to perform this operation.
                                                //!< Permission validation will be bypassed if this
                                                //!< is null.
    size_t                  num_allowed;        //!< Length of the `allowed_rsc` array
} mtb_srf_op_s_t;

/** Module structure.  A module is a collection of operations, used to expose secure operations
 * between different entries in the system.
 *
 * A module is on the scale of PDL, whereas a submodule may be SysCLK.  All operations for the
 * submodule should be stores in an array in op_by_submod.  If there are no submodules, then
 * the array will only have one entry
 */
typedef struct
{
    uint8_t                 module_id;          //!< ID for this module. Must be globally unique
    mtb_srf_op_s_t**        op_by_submod;       //!< Array of operations in this module/submodule.
    size_t*                 num_op_by_submod;   //!< Length of each entry of the `op_by_submod`
                                                //!< array
    size_t                  num_submod;         //!< Length of the `num_op_by_submod` array
} mtb_srf_module_s_t;

/** Context structure.  Used only internally by the secure side. */
typedef struct
{
    mtb_srf_module_s_t*    modules[MTB_SRF_MODULE_COUNT];
} mtb_srf_context_s_t;

/** Structure to define if a range of memory is secure.  Generated by the device configurator. */
typedef struct
{
    void*                   start;              //!< Start of the memory range
    size_t                  length;             //!< Length of the memory range
    bool                    is_secure;          //!< If the range is Secure or Non-Secure accessible
} mtb_srf_protection_range_s_t;

/** Structure to contain all different memories security regions. Generated by device configurator
 */
typedef struct
{
    const mtb_srf_protection_range_s_t* ranges;    /**< Pointer to the settings array */
    uint8_t size;                                  /**< Array size */
} mtb_srf_memory_protection_s_t;


#endif /* defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN) */


/*******************************************************************************
*                        Public Function Prototypes
*******************************************************************************/

#if defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN)

/** Initialize the SRF
 *
 * @param[in,out] context_s     The context object for this asset
 *
 * @return the status of initialization */
cy_rslt_t mtb_srf_init(mtb_srf_context_s_t* context_s);

/** Register a module for use
 *
 * @param[in,out] context_s     The context object for this asset
 * @param[in]     module_s      The module to be registered
 *
 * @return the status of registration */
cy_rslt_t mtb_srf_module_register(mtb_srf_context_s_t* context_s, mtb_srf_module_s_t* module_s);

/** Validate invec/outvec memory address on non-secure's permission. This is a weak function with a
   default implementation so that TFM (where used) can override these checks via its own
   infrastructure
 *
 * @param[in]     inVec_ns       Vector for all operation and SRF input
 * @param[in]     inVec_cnt_ns   Number of inVecs passed in to validate
 * @param[in]     outVec_ns      Vector for all operation and SRF output
 * @param[in]     outVec_cnt_ns  Number of outVecs passed in to validate
 * @param[out]    inVec          Vector to store local copied inVec_ns
 * @param[out]    outVec         Vector to store local copied inVec_ns
 *
 * @return the status of validation */
cy_rslt_t mtb_srf_memory_validate(volatile mtb_srf_invec_ns_t* inVec_ns,
                                  uint8_t inVec_cnt_ns,
                                  volatile mtb_srf_outvec_ns_t* outVec_ns,
                                  uint8_t outVec_cnt_ns,
                                  mtb_srf_invec_ns_t* inVec,
                                  mtb_srf_outvec_ns_t* outVec);

/** Execute a request
 *
 * @param[in]     context_s     The context object for this asset
 * @param[in,out] inVec_ns      Vector for all operation and SRF input
 * @param[in]     inVec_cnt_ns  Number of input vectors in inVec_ns array
 * @param[in,out] outVec_ns     Vector for all operation and SRF output
 * @param[in]     outVec_cnt_ns Number of output vectors in outVec_ns array
 *
 * @return the status of execution */
cy_rslt_t mtb_srf_request_execute(mtb_srf_context_s_t* context_s,
                                  mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                                  mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns);

/** Check if an address is non secure accessible
 *
 * @param[in]     addr     The start address to check address for
 * @param[in]     size     The size of the area to check
 *
 * @return true if it is ns acccsible, false otherwise */
bool mtb_srf_is_memory_ns_accessible(uint32_t addr, size_t size);


/** Copy the operation defined structure value to input_values and validate the structure size
 * If size, which is defined in secure-side, is not eqaul to size of the input_values array,
 * it returns MTB_SRF_ERR_BAD_PARAM.
 *
 * @param[out]    input         Point to operation defined structure
 * @param[in]     size          The size of input to be copied and checked
 * @param[in]     inputs_ns     Struct describing the operation and containing non-pointer
                                input arguments
 *
 * @return the status of execution */
cy_rslt_t mtb_srf_copy_input_value(void* input, size_t size, mtb_srf_input_ns_t* inputs_ns);


/** Copy the operation defined structure value to input_values and validate the structure size
 * If size, which is defined in secure-side, is not eqaul to size of the output_values array,
 * it returns MTB_SRF_ERR_BAD_PARAM.
 *
 * @param[out]     outputs_ns    Struct containing the non-pointer output arguments
 * @param[in]      output        Point to operation defined structure
 * @param[in]      size          The size of output to be copied and checked
 *
 * @return the status of execution */
cy_rslt_t mtb_srf_copy_output_value(mtb_srf_output_ns_t* outputs_ns, void* output, size_t size);

#endif /* defined(COMPONENT_SECURE_DEVICE) || defined(DOXYGEN) */

/** Submit a request from the non-secure side to the secure
 *
 * This is a function with a default implementation within the BSP. The user may define
 * MTB_SRF_CUSTOM_REQUEST_SUBMIT and override this with their own implementation should they need
 * further action taken. However custom implementations must ultimately call \ref
 * mtb_srf_request_execute.
 *
 * When the IPC library is present, this function may be called from other cores without TrustZone.
 * The request will be passed to the non-secure side of the TrustZone enabled core, which will then
 * submit it to the secure side.
 *
 * On Cores which support DCache, it is the user's responsibility that all data pointed to by the
 * inVec[1-3] and outVec[1-3] base pointers is DCache aligned.  The input and output structures
 * (inVec[0] and outVec[0], respectively) as well as the ioVec structures themselves are already
 * DCache aligned when allocated from a pool.
 *
 * @param[in,out] inVec_ns      Vector for all operation and SRF input
 * @param[in]     inVec_cnt_ns  Number of input vectors in inVec_ns array
 * @param[in,out] outVec_ns     Vector for all operation and SRF output
 * @param[in]     outVec_cnt_ns Number of output vectors in outVec_ns array
 *
 * @return the status of submission */
cy_rslt_t mtb_srf_request_submit(mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                                 mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns);

/** \} group_mtb_srf */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

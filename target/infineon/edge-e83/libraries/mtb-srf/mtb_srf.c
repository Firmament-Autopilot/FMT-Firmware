/*******************************************************************************
* \file mtb_srf.c
*
* \brief
* Provides API implementation for the Secure Request Framework library.
*
********************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <assert.h>
#include <string.h>
#include <arm_cmse.h>
#include "mtb_srf.h"
#include "cy_syslib.h"
#include "cy_device.h"

#ifdef COMPONENT_NON_SECURE_DEVICE
// Only needed for _mrtb_srf_wait, which is only needed on the non-secure side
#include "mtb_hal_system.h"
#endif /* COMPONENT_NON_SECURE_DEVICE */
#include "mtb_srf_common.h"

#if defined(COMPONENT_NON_SECURE_DEVICE) && defined(MTB_SRF_SUBMIT_USE_IPC) && \
    defined(COMPONENT_MW_MTB_IPC)
#include "mtb_srf_ipc_init.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

#if !defined(CY_SRF_DISABLE)
/*******************************************************************************
*                           Private Defines
*******************************************************************************/

#if defined(COMPONENT_SECURE_DEVICE)

#if !defined(MTB_SRF_MODULE_COUNT)
/* In the off-chance a user deletes this, give a verbose error message */
#error Please define MTB_SRF_MODULE_COUNT in mtb_srf_config.h
#endif

#define _MTB_SRF_IS_MODULE_IDX_VALID(idx) ((idx) < MTB_SRF_MODULE_COUNT)

#if !defined(MTB_SRF_MAX_ARG_IN_SIZE)
// This is used to local copy first element of invec array, which is request + non-pointer
// input arguments. Make sure the size is sufficient to store all those data.
#error \
    Please define MTB_SRF_MAX_ARG_IN_SIZE, which is "input_values_length", in mtb_srf_config.h.
#endif

#if !defined(MTB_SRF_MAX_ARG_OUT_SIZE)
// This is used to local copy first element of outvec array, which is request + non-pointer
// output arguments. Make sure the size is sufficient to store all those data.
#error \
    Please define MTB_SRF_MAX_ARG_OUT_SIZE, which is "output_values_length", in mtb_srf_config.h.
#endif


#if !defined(MTB_SRF_SECURE_ARG_BUFFER_LEN)
#error "Please MTB_SRF_SECURE_ARG_BUFFER_LEN in mtb_srf_config.h"
#endif

#endif /* defined(COMPONENT_SECURE_DEVICE) */

#ifdef COMPONENT_NON_SECURE_DEVICE
/*******************************************************************************
*                       Private Function Definitions
*******************************************************************************/
//--------------------------------------------------------------------------------------------------
// _mtb_srf_wait
// Waits for the specified interval. Also decrements the timeout unless it is "never timeout"
//--------------------------------------------------------------------------------------------------
void _mtb_srf_wait(uint32_t* timeout_us, uint32_t interval_us)
{
    uint32_t us_wait_step = interval_us % 1000UL;
    uint32_t ms_wait_step = (interval_us - us_wait_step) / 1000UL;

    if ((us_wait_step + (ms_wait_step * 1000UL)) <= *timeout_us)
    {
        if (ms_wait_step != 0UL)
        {
            (void)mtb_hal_system_delay_ms(ms_wait_step);
            if (MTB_SRF_NEVER_TIMEOUT != *timeout_us)
            {
                *timeout_us -= (ms_wait_step * 1000UL);
            }
        }
        if (us_wait_step != 0UL)
        {
            mtb_hal_system_delay_us((uint16_t)us_wait_step);
            if (MTB_SRF_NEVER_TIMEOUT != *timeout_us)
            {
                *timeout_us -= us_wait_step;
            }
        }
    }
    else if (*timeout_us != 0UL)
    {
        mtb_hal_system_delay_us((uint16_t)*timeout_us);
        *timeout_us = 0UL;
    }
}


#endif /* COMPONENT_NON_SECURE_DEVICE */

#if defined(COMPONENT_SECURE_DEVICE)


extern const mtb_srf_memory_protection_s_t mtb_srf_memory_protection_s[];
extern uint8_t mtb_srf_protection_range_s_count;


//--------------------------------------------------------------------------------------------------
// _mtb_srf_check_permissions
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_srf_check_permissions(mtb_srf_op_s_t* op, mtb_srf_request_ns_t* req_ns)
{
    // Request is not volatile here as we're interacting with a copy owned by the secure side
    cy_rslt_t result = MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    if ((op->num_allowed == 0UL) && (op->allowed_rsc == NULL))
    {
        return CY_RSLT_SUCCESS;
    }
    else if (((op->num_allowed != 0UL) && (op->allowed_rsc == NULL)) ||
             ((op->num_allowed == 0UL) && (op->allowed_rsc != NULL)))
    {
        // num_allowed is inconsistent with allowed_rsc.
        CY_ASSERT(false);
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }

    for (uint32_t i = 0UL; i < (uint32_t)(op->num_allowed); ++i)
    {
        // Loop through until we find the matching base & sub_block, then check that either the
        // resource is Read-Write (allowed_write = true), or that the operation is Read-Only
        // (write_required = false)
        if ((op->allowed_rsc[i].base == req_ns->base) &&
            (op->allowed_rsc[i].sub_block == req_ns->sub_block))
        {
            if ((op->allowed_rsc[i].write_allowed == true) || (op->write_required == false))
            {
                result = CY_RSLT_SUCCESS;
            }
            break; // We don't allow duplicates with different permissions, so always stop after the
                   // first match
        }
    }
    return result;
}


#endif /* defined(COMPONENT_SECURE_DEVICE) */
/*******************************************************************************
*                        Public Function Definitions
*******************************************************************************/

#if defined(COMPONENT_SECURE_DEVICE)
cy_rslt_t mtb_srf_copy_input_value(void* input, size_t size, mtb_srf_input_ns_t* inputs_ns)
{
    if (inputs_ns->len != size)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    memcpy(input, inputs_ns->input_values, size);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_copy_output_value
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_copy_output_value(mtb_srf_output_ns_t* outputs_ns, void* output, size_t size)
{
    if (outputs_ns->len != size)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    memcpy(outputs_ns->output_values, output, size);
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_is_memory_ns_accessible
//--------------------------------------------------------------------------------------------------
bool mtb_srf_is_memory_ns_accessible(uint32_t addr, size_t size)
{
    // We treat non-secure memory access as all-or-nothing, and are not trying to handle read vs.
    // write permissions differently
    size_t length = size;
    uint8_t num_prot_memories = mtb_srf_protection_range_s_count;
    size_t start_addr = addr;

    // First check if we're CM55_DTCM_CM33.  This is a temporary workaround until this can be
    // generated by the device configurator.  The region is CY_CM55_DTCM_BASE, and is of size
    // CY_CM55_DTCM_INTERNAL_SIZE
    if ((start_addr >= (size_t)GET_NSALIAS_ADDRESS(CY_CM55_DTCM_BASE)) && (start_addr + length <
                                                                           (size_t)(
                                                                               GET_NSALIAS_ADDRESS(
                                                                                   CY_CM55_DTCM_BASE)
                                                                               +
                                                                               CY_CM55_DTCM_INTERNAL_SIZE)))
    {
        return true;
    }

    while (length > 0UL)
    {
        for (uint8_t i = 0UL; i < num_prot_memories; ++i)
        {
            for (uint8_t j = 0UL; j < mtb_srf_memory_protection_s[i].size; j++)
            {
                const mtb_srf_protection_range_s_t* ranges = mtb_srf_memory_protection_s[i].ranges;
                size_t end_addr = (size_t)(ranges[j].start) + ranges[j].length;
                if ((start_addr >= (size_t)(ranges[j].start)) &&
                    (start_addr < end_addr))
                {
                    if (ranges[j].is_secure)
                    {
                        return false;
                    }
                    if ((start_addr + length) > end_addr)
                    {
                        // Continue to check subsequent ranges for the portion of the data
                        // structure that extends beyond the end of this range
                        length = end_addr - start_addr;
                        start_addr = end_addr;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    // If we can't find the region, assume it's secure
    return false;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_init(mtb_srf_context_s_t* context_s)
{
    memset(context_s, 0x0, sizeof(mtb_srf_context_s_t));
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_module_register
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_module_register(mtb_srf_context_s_t* context_s, mtb_srf_module_s_t* module_s)
{
    if ((module_s == NULL) || (context_s == NULL))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    if (!_MTB_SRF_IS_MODULE_IDX_VALID(module_s->module_id) ||
        (context_s->modules[module_s->module_id] != NULL))
    {
        return MTB_SRF_ERR_MODULE_ID_INVALID;
    }

    context_s->modules[module_s->module_id] = module_s;
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_memory_validate
//--------------------------------------------------------------------------------------------------
__WEAK cy_rslt_t mtb_srf_memory_validate(volatile mtb_srf_invec_ns_t* inVec_ns,
                                         uint8_t inVec_cnt_ns,
                                         volatile mtb_srf_outvec_ns_t* outVec_ns,
                                         uint8_t outVec_cnt_ns,
                                         mtb_srf_invec_ns_t* inVec,
                                         mtb_srf_outvec_ns_t* outVec)
{
    CY_ASSERT(inVec_ns != NULL);
    CY_ASSERT(outVec_ns != NULL);
    CY_ASSERT(inVec != NULL);
    CY_ASSERT(outVec != NULL);

    if ((inVec_cnt_ns + outVec_cnt_ns) > MTB_SRF_MAX_IOVEC)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    // First Stage: Validate address of inVec_ns/outVec_ns
    if (!(mtb_srf_is_memory_ns_accessible((uint32_t)inVec_ns,
                                          inVec_cnt_ns * sizeof(mtb_srf_invec_ns_t))))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }
    if (!(mtb_srf_is_memory_ns_accessible((uint32_t)outVec_ns,
                                          outVec_cnt_ns * sizeof(mtb_srf_outvec_ns_t))))
    {
        return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
    }

    // Make local copies (inVec_ns/outVec_ns) to validate
    for (uint32_t i = 0UL; i < inVec_cnt_ns; ++i)
    {
        inVec[i].base = inVec_ns[i].base;
        inVec[i].len = inVec_ns[i].len;
    }
    for (uint32_t i = 0UL; i < outVec_cnt_ns; ++i)
    {
        outVec[i].base = outVec_ns[i].base;
        outVec[i].len = outVec_ns[i].len;
    }

    // Seconds Stage: Validate address, which inVec/outVec points to
    for (uint32_t i = 0UL; i < inVec_cnt_ns; ++i)
    {
        if (inVec[i].base != NULL)
        {
            if (!(mtb_srf_is_memory_ns_accessible((uint32_t)inVec[i].base, inVec[i].len)))
            {
                return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
            }
        }
    }
    for (uint32_t i = 0UL; i < outVec_cnt_ns; ++i)
    {
        if (outVec[i].base != NULL)
        {
            if (!(mtb_srf_is_memory_ns_accessible((uint32_t)outVec[i].base, outVec[i].len)))
            {
                return MTB_SRF_ERR_SECURITY_POLICY_VIOLATION;
            }
        }
    }

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// _mtb_srf_copy_arg
//
// Copy an argument from non-secure storage to secure storage, allocating out of a scratch buffer
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_srf_copy_arg(const void* base_ns, size_t length, uint8_t* arg_storage,
                            size_t* next_allocation, void** output_location)
{
    // Arguments need to be aligned to 4-byte boundaries
    size_t length_aligned = (length + 3) & (~0x3);
    // This needs to be separate from the check below to avoid false negatives in the face of
    // integer overflow
    if ((length_aligned > MTB_SRF_SECURE_ARG_BUFFER_LEN) /* Too long */ ||
        (length_aligned < length) /* Overflow */)
    {
        return MTB_SRF_ERR_ARGBUFF_FULL;
    }

    if (*next_allocation > MTB_SRF_SECURE_ARG_BUFFER_LEN - length_aligned)  // New allocation too
                                                                            // large
    {
        return MTB_SRF_ERR_ARGBUFF_FULL;
    }

    size_t new_next_allocation = *next_allocation + length_aligned;
    void* copy_dest = &(arg_storage[*next_allocation]);
    memcpy(copy_dest, base_ns, length);
    *output_location = copy_dest;
    *next_allocation = new_next_allocation;
    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_request_execute
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_request_execute(mtb_srf_context_s_t* context_s,
                                  mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                                  mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    mtb_srf_invec_ns_t invec[MTB_SRF_MAX_IOVEC];
    mtb_srf_outvec_ns_t outvec[MTB_SRF_MAX_IOVEC];
    _Static_assert(0u == (MTB_SRF_SECURE_ARG_BUFFER_LEN % 4u),
                   "Secure argument buffer must be aligned to a 4-byte boundary");

    CY_ALIGN(4) uint8_t arg_storage[MTB_SRF_SECURE_ARG_BUFFER_LEN];
    memset(arg_storage, 0, sizeof(arg_storage));
    size_t next_allocation = 0u;
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_srf_op_s_t* found_op = NULL;

    // Verify the request arrays are in non-secure memory.
    result = mtb_srf_memory_validate(inVec_ns, inVec_cnt_ns, outVec_ns, outVec_cnt_ns,
                                     invec, outvec);

    // Ensure we have the minimum arguments
    if ((result == CY_RSLT_SUCCESS) && ((invec[0].base == NULL) || (outvec[0].base == NULL)))
    {
        result = MTB_SRF_ERR_BAD_PARAM;
    }

    // Ensure our input & output structures fit into the invec[0] & outvec[0]
    if ((result == CY_RSLT_SUCCESS) &&
        (((uint32_t)(invec[0].len) < (uint32_t)(sizeof(mtb_srf_input_ns_t))) ||
         ((uint32_t)(outvec[0].len) < (uint32_t)(sizeof(mtb_srf_output_ns_t)))))
    {
        result = MTB_SRF_ERR_BAD_PARAM;
    }

    // Copy input and output struct
    mtb_srf_input_ns_t* input_struct;
    if (result == CY_RSLT_SUCCESS)
    {
        result =
            _mtb_srf_copy_arg(invec[0].base, invec[0].len, arg_storage, &next_allocation,
                              (void**)&input_struct);
    }
    mtb_srf_output_ns_t* output_struct;
    if (result == CY_RSLT_SUCCESS)
    {
        result =
            _mtb_srf_copy_arg(outvec[0].base, outvec[0].len, arg_storage, &next_allocation,
                              (void**)&output_struct);
    }

    // Find the request
    mtb_srf_request_ns_t* request_struct;
    if (result == CY_RSLT_SUCCESS)
    {
        request_struct = &(input_struct->request);

        // The passed in base address will be a NS address - convert it to a S address
        if (request_struct->base != NULL)
        {
            request_struct->base = (void*)(GET_ALIAS_ADDRESS(request_struct->base));
        }

        // Validate input/output sizes using local copies
        if ((sizeof(mtb_srf_input_ns_t) + input_struct->len != (uint32_t)(invec[0].len)) ||
            (sizeof(mtb_srf_output_ns_t) + output_struct->len != (uint32_t)(outvec[0].len)))
        {
            result = MTB_SRF_ERR_BAD_PARAM;
        }
    }

    // Find the operation and check permissions
    if (result == CY_RSLT_SUCCESS)
    {
        // If the requested module_id is out of bounds, or the submodule_id is out of bounds
        if (!_MTB_SRF_IS_MODULE_IDX_VALID(request_struct->module_id) ||
            (context_s->modules[request_struct->module_id] == NULL) ||
            (request_struct->submodule_id >=
             context_s->modules[request_struct->module_id]->num_submod))
        {
            result =  MTB_SRF_ERR_MODULE_ID_INVALID;
        }
        else
        {
            mtb_srf_module_s_t* found_module = context_s->modules[request_struct->module_id];
            uint32_t num_op_in_submod =
                found_module->num_op_by_submod[request_struct->submodule_id];

            if (request_struct->op_id < num_op_in_submod)
            {
                found_op =
                    &found_module->op_by_submod[request_struct->submodule_id][request_struct->
                                                                              op_id];
            }

            if (found_op == NULL)
            {
                result = MTB_SRF_ERR_UNKNOWN_OPERATION;
            }
            else
            {
                result = _mtb_srf_check_permissions(found_op, request_struct);
            }
        }
    }

    // Ensure the arrays passed in are big enough to hold all the arguments the operation needs
    if (result == CY_RSLT_SUCCESS)
    {
        if ((input_struct->len < found_op->input_values_len) ||
            (output_struct->len < found_op->output_values_len))
        {
            result = MTB_SRF_ERR_BAD_PARAM;
        }

        for (uint32_t i = 1UL; i < inVec_cnt_ns; ++i)
        {
            if (invec[i].len < found_op->input_len[i - 1UL])
            {
                result = MTB_SRF_ERR_BAD_PARAM;
            }
        }
        for (uint32_t i = 1UL; i < outVec_cnt_ns; ++i)
        {
            if (outvec[i].len < found_op->output_len[i - 1UL])
            {
                result = MTB_SRF_ERR_BAD_PARAM;
            }
        }
    }

    if (result == CY_RSLT_SUCCESS)
    {
        // Copy the rest of the invec entries if the operation says they need to be.
        // Skip input 0 because we already copied it above before we figured out what request to use
        for (size_t i = 1u; i < inVec_cnt_ns; ++i)
        {
            if (found_op->needs_copy[i - 1])
            {
                // By this point we already know that the non-secure world passed the correct number
                // and size of inputs
                void* new_input_ptr;
                result = _mtb_srf_copy_arg(invec[i].base, invec[i].len, arg_storage,
                                           &next_allocation, &new_input_ptr);
                if (result == CY_RSLT_SUCCESS)
                {
                    invec[i].base = new_input_ptr;
                }
                else
                {
                    break;
                }
            }
        }
    }

    // At this point we have a validated request and a matching operation with allowed
    // permissions
    if (result == CY_RSLT_SUCCESS)
    {
        // First element of invec/outvec is taken for input_struct/output_struct respectively.
        cy_rslt_t op_rslt =
            found_op->impl(input_struct, output_struct, &invec[1], (inVec_cnt_ns - 1),
                           &outvec[1], (outVec_cnt_ns - 1));
        output_struct->result = op_rslt;
        // Copy any output struct information back into outVec[0]
        memcpy(outvec[0].base, output_struct, outvec[0].len);
    }
    return result;
}


#endif /* defined(COMPONENT_SECURE_DEVICE) */

#endif /* !defined(CY_SRF_DISABLE) */

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

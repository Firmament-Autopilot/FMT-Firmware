/*******************************************************************************
* \file mtb_srf_pool.c
*
* \brief
* Provides API implementation for the Secure Request Pool library.
*
********************************************************************************
* \copyright
* (c) (2025), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <string.h>
#include <limits.h>
#include "cy_syslib.h"
#include "mtb_srf_pool_init.h"
#include "mtb_hal_system.h"
#include "mtb_srf_common.h"

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

#if !defined(CY_SRF_DISABLE)
/*******************************************************************************
*                           Private Defines
*******************************************************************************/
#ifndef MTB_SRF_INTERVAL_US
#define MTB_SRF_INTERVAL_US   (100UL)
#endif /* #ifndef MTB_SRF_INTERVAL_US */

//--------------------------------------------------------------------------------------------------
// _mtb_srf_pool_get_request
//--------------------------------------------------------------------------------------------------
static int32_t _mtb_srf_pool_get_request(mtb_srf_pool_t* pool)
{
    int32_t idx = 0L;
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    for (idx = 0L; idx < (int32_t)pool->num_entries; ++idx)
    {
        if ((pool->avail_for_alloc & (1UL << idx)) != 0UL)
        {
            pool->avail_for_alloc &= ~(1UL << idx);
            break;
        }
    }
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    if (idx == (int32_t)pool->num_entries)
    {
        return -1;
    }

    return idx;
}


/*******************************************************************************
*                        Public Function Definitions
*******************************************************************************/
/** Initializes an secure request pool */
cy_rslt_t mtb_srf_pool_init(mtb_srf_pool_t* pool, uint32_t* allocated_mem,
                            size_t num_entries,
                            size_t input_len_per_entry,
                            size_t output_len_per_entry)
{
    if ((NULL != pool) && (NULL != allocated_mem) && (0UL < num_entries) &&
        (num_entries <= (sizeof(pool->avail_for_alloc) * (size_t)(CHAR_BIT))))
    {
        (void)memset(pool, 0, sizeof(mtb_srf_pool_t));
        pool->data = allocated_mem;
        pool->num_entries = num_entries;
        pool->input_len_per_entry = input_len_per_entry;
        pool->output_len_per_entry = output_len_per_entry;

        for (uint32_t i = 0UL; i < (uint32_t)num_entries; ++i)
        {
            pool->avail_for_alloc |= (1UL << i);
        }

        #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
        return cy_rtos_semaphore_init(&pool->mtb_srf_pool_semaphore, num_entries, num_entries);
        #else
        return CY_RSLT_SUCCESS;
        #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */
    }

    return MTB_SRF_ERR_BAD_PARAM;
}


/** Allocate secure request object */
cy_rslt_t mtb_srf_pool_allocate(mtb_srf_pool_t* pool, mtb_srf_invec_ns_t** inVec,
                                mtb_srf_outvec_ns_t** outVec, uint32_t timeout_us)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    int32_t idx = 0;
    uint32_t timeout_us_left = timeout_us;
    if ((NULL == pool) || (NULL == inVec) || (NULL == outVec))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    result = cy_rtos_semaphore_get(&(pool->mtb_srf_pool_semaphore), timeout_us / 1000UL);
    if (CY_RSLT_SUCCESS != result)
    {
        return result;
    }
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

    do
    {
        idx = _mtb_srf_pool_get_request(pool);
        if (idx != -1)
        {
            break;
        }
        _mtb_srf_wait(&timeout_us_left, MTB_SRF_INTERVAL_US);
    } while (timeout_us_left != 0UL);

    if ((idx < 0) || (idx >= (int32_t)pool->num_entries))
    {
        #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
        // Should not go here in a RTOS context
        CY_ASSERT(false);
        #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */
        return MTB_SRF_ERR_ALLOCATE_FREE;
    }

    uint32_t entry_offset = (uint32_t)idx * MTB_SRF_POOL_ENTRY_SIZE(pool->input_len_per_entry,
                                                                    pool->output_len_per_entry);
    entry_offset = MTB_SRF_ROUND_UP(entry_offset, MTB_SRF_POOL_ALIGNMENT);
    uint32_t output_offset = entry_offset + sizeof(mtb_srf_input_ns_t) + pool->input_len_per_entry;
    output_offset = MTB_SRF_ROUND_UP(output_offset, MTB_SRF_POOL_ALIGNMENT);
    uint32_t invec_offset = output_offset + sizeof(mtb_srf_output_ns_t) +
                            pool->output_len_per_entry;
    invec_offset = MTB_SRF_ROUND_UP(invec_offset, MTB_SRF_POOL_ALIGNMENT);
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3', 'Suitable alignment manually ensured');
    (*inVec) = (mtb_srf_invec_ns_t*)(&pool->data[invec_offset / sizeof(uint32_t)]);
    (*inVec)[0].base = &pool->data[entry_offset / sizeof(uint32_t)];
    (*inVec)[0].len = sizeof(mtb_srf_input_ns_t) + pool->input_len_per_entry;
    for (uint32_t i = 1UL; i < (uint32_t)MTB_SRF_MAX_IOVEC; ++i)
    {
        (*inVec)[i].base = NULL;
        (*inVec)[i].len = 0UL;
    }

    uint32_t outvec_offset = invec_offset + (sizeof(mtb_srf_invec_ns_t) * MTB_SRF_MAX_IOVEC);
    outvec_offset = MTB_SRF_ROUND_UP(outvec_offset, MTB_SRF_POOL_ALIGNMENT);
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.3', 'Suitable alignment manually ensured');
    (*outVec) = (mtb_srf_outvec_ns_t*)(&pool->data[outvec_offset / sizeof(uint32_t)]);
    (*outVec)[0].base = &pool->data[output_offset / sizeof(uint32_t)];
    (*outVec)[0].len = sizeof(mtb_srf_output_ns_t) + pool->output_len_per_entry;
    for (uint32_t i = 1UL; i < (uint32_t)MTB_SRF_MAX_IOVEC; ++i)
    {
        (*outVec)[i].base = NULL;
        (*outVec)[i].len = 0UL;
    }

    return result;
}


/** Free secure request object */
cy_rslt_t mtb_srf_pool_free(mtb_srf_pool_t* pool, const mtb_srf_invec_ns_t* inVec,
                            const mtb_srf_outvec_ns_t* outVec)
{
    uint32_t idx = 0UL;
    if ((NULL == pool) || (NULL == inVec) || (NULL == outVec))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    for (idx = 0UL; idx < (uint32_t)pool->num_entries; ++idx)
    {
        uint32_t entry_offset = idx * MTB_SRF_POOL_ENTRY_SIZE(pool->input_len_per_entry,
                                                              pool->output_len_per_entry);
        entry_offset = MTB_SRF_ROUND_UP(entry_offset, MTB_SRF_POOL_ALIGNMENT);
        if (inVec->base == &pool->data[entry_offset / sizeof(uint32_t)])
        {
            CY_ASSERT((pool->avail_for_alloc & (1UL << idx)) == 0UL);
            pool->avail_for_alloc |= (1UL << idx);
            break;
        }
    }
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    if (idx == (uint32_t)pool->num_entries)
    {
        return MTB_SRF_ERR_ALLOCATE_FREE;
    }

    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    return cy_rtos_semaphore_set(&pool->mtb_srf_pool_semaphore);
    #else
    return CY_RSLT_SUCCESS;
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */
}


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1, \
                             'Pool will never be const in a normal use case');

/* Get the entry lengths of the pool */
cy_rslt_t mtb_srf_pool_get_entry_len(mtb_srf_pool_t* pool, size_t* input_len_per_entry,
                                     size_t* output_len_per_entry)
{
    if ((pool == NULL) || (input_len_per_entry == NULL) || (output_len_per_entry == NULL))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    *input_len_per_entry = pool->input_len_per_entry;
    *output_len_per_entry = pool->output_len_per_entry;
    return CY_RSLT_SUCCESS;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13');

#endif /* !defined(CY_SRF_DISABLE) */
#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

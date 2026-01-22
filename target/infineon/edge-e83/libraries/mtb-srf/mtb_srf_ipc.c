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
#include "mtb_srf.h"
#include "mtb_hal_system.h"
#if !defined(COMPONENT_SECURE_DEVICE)
#include "mtb_ipc.h"
#include "mtb_srf_ipc_init.h"
#include "mtb_hal_syspm.h"
#endif /* !defined(COMPONENT_SECURE_DEVICE) */
#include "mtb_srf_common.h"

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

#if !defined(CY_SRF_DISABLE)

#if !defined(COMPONENT_SECURE_DEVICE)
/*******************************************************************************
*                           Private Defines
*******************************************************************************/
/** Define 1ms interval time for operations */
#ifndef MTB_SRF_INTERVAL_US
#define MTB_SRF_INTERVAL_US   (100UL)
#endif /* #ifndef MTB_SRF_INTERVAL_US */

/* Helper define to error that config defines are not present */
#if !defined(MTB_SRF_POOL_SIZE)
#error "MTB_SRF_POOL_SIZE is not defined. Please add it to mtb_srf_config.h"
#endif

/* Shared memory is non-cachable memory. Currently we invalidate/clean all shared memory objects as
 * if they are cached.
 * Before Reading non-Shared Memory:
 *     SCB_InvalidateDCache_by_Addr(addr,size)  for invalidating the D-Cache (to Read RAM, updating
 * the cache)
 * After Writing to non-Shared Memory:
 *     SCB_CleanDCache_by_Addr(addr,size) for cleaning the D-Cache (writing the cache through to
 * RAM)
 */
#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
/* NOTES:
 *  D-Cache is invalidated starting from a 32 byte aligned address in 32 byte granularity.
 *  D-Cache memory blocks which are part of given address + given size are invalidated.
 */
#define MTB_SRF_INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(addr, \
                                                             size) \
    SCB_InvalidateDCache_by_Addr((volatile void*)addr, size)

//--------------------------------------------------------------------------------------------------
// clean_dcache
//--------------------------------------------------------------------------------------------------
#define MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(addr, \
                                                     size) \
    SCB_CleanDCache_by_Addr((volatile void*)addr, size)

#else // if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define MTB_SRF_INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(addr, size)
#define MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(addr, size)
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

/*******************************************************************************
*                        Private Function Prototypes
*******************************************************************************/
/* Used in alloc functions if there is not a bit avaliable in bitmap to alloc an item*/
#define _MTB_SRF_UNAVALIABLE_FOR_ALLOC (0xFFFFUL)
/* Used to find first free bit in a bitmap*/
uint32_t _mtb_srf_ipc_find_first_free_bit(uint32_t bitmap, uint32_t max_entries);
/*******************************************************************************
*                        Internal Variables
*******************************************************************************/
#if !(defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && !defined(MTB_SRF_SUBMIT_USE_IPC)
/* Put a request in the ring buffer */
cy_rslt_t _mtb_srf_ipc_put_req_in_buffer(mtb_srf_ipc_ringbuf_t* buff, mtb_srf_ipc_packet_t* data)
{
    if ((buff == NULL) || (buff->buffer == NULL))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    cy_rslt_t result = MTB_SRF_ERR_RINGBUF_FULL;
    if (!buff->full)
    {
        //add new addr
        buff->buffer[buff->head] = data;
        buff->head = (buff->head + 1) % (buff->max);
        buff->full = (buff->head == buff->tail);
        result = CY_RSLT_SUCCESS;
    }

    return result;
}


/* Get a request from the ring buffer */
cy_rslt_t _mtb_srf_ipc_get_req_from_buffer(mtb_srf_ipc_ringbuf_t* buff, mtb_srf_ipc_packet_t** data)
{
    if ((buff == NULL) || (buff->buffer == NULL))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    cy_rslt_t ret = MTB_SRF_ERR_RINGBUF_EMPTY;

    if (buff->full || (buff->head != buff->tail))
    {
        *data = buff->buffer[buff->tail];
        buff->full = false;
        buff->tail = (buff->tail + 1) % (buff->max);

        ret = CY_RSLT_SUCCESS;
    }

    return ret;
}


#endif \
    // (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && !defined(MTB_SRF_SUBMIT_USE_IPC)

//--------------------------------------------------------------------------------------------------
// _mtb_srf_ipc_find_first_free_bit
//--------------------------------------------------------------------------------------------------
uint32_t _mtb_srf_ipc_find_first_free_bit(uint32_t bitmap, uint32_t max_entries)
{
    for (uint32_t idx = 0UL; idx < max_entries; ++idx)
    {
        if ((bitmap & (1UL << idx)) != 0UL)
        {
            return idx;
        }
    }
    return _MTB_SRF_UNAVALIABLE_FOR_ALLOC;
}


#if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
/* Convert timeouts for use in RTOS APIs. Also convert
 * the "never timeout" sentinel value from SRF to RTOS. */
static cy_time_t _mtb_srf_timeout_for_rtos(uint32_t timeout_us)
{
    if (MTB_SRF_NEVER_TIMEOUT == timeout_us)
    {
        // In practice these two never timeout values are identical, so this mapping should
        // optimize away, but this way the SRF doesn't implicitly assume that the two are the same.
        return CY_RTOS_NEVER_TIMEOUT;
    }
    // RTOS timeout is in milliseconds
    return (cy_time_t)(timeout_us / 1000UL);
}


#endif // if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)

/*******************************************************************************
*                        Public Function Definitions
*******************************************************************************/
#if defined(MTB_SRF_SUBMIT_USE_IPC)

//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_request_submit
//--------------------------------------------------------------------------------------------------
#ifndef MTB_SRF_CUSTOM_IPC_REQUEST_SUBMIT
cy_rslt_t mtb_srf_ipc_request_submit(mtb_srf_ipc_client_context_t* client_context,
                                     mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
                                     mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    mtb_srf_ipc_packet_t* ipc_req = NULL;
    cy_rslt_t result = mtb_srf_ipc_pool_req_alloc(client_context->pool, &ipc_req,
                                                  MTB_SRF_IPC_SERVICE_TIMEOUT_US);
    if (result == CY_RSLT_SUCCESS)
    {
        uint16_t sema_idx = 0;
        result = mtb_srf_ipc_pool_semaphore_alloc(client_context->pool, &sema_idx,
                                                  MTB_SRF_IPC_SERVICE_TIMEOUT_US);
        if (result == CY_RSLT_SUCCESS)
        {
            // Pack ipc_req with data
            ipc_req->inVec_ptr = (mtb_srf_invec_ns_t*)cy_DTCMRemapAddr((void*)inVec_ns);
            MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY((uint32_t)(ipc_req->inVec_ptr),
                                                         sizeof(mtb_srf_invec_ns_t) * inVec_cnt_ns);
            ipc_req->outVec_ptr = (mtb_srf_outvec_ns_t*)cy_DTCMRemapAddr((void*)outVec_ns);
            MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY((uint32_t)(ipc_req->outVec_ptr),
                                                         sizeof(mtb_srf_outvec_ns_t) *
                                                         outVec_cnt_ns);
            ipc_req->inVec_cnt_ns = inVec_cnt_ns;
            ipc_req->outVec_cnt_ns = outVec_cnt_ns;
            ipc_req->semaphore_idx = sema_idx;
            ipc_req->request_rslt = CY_RSLT_SUCCESS;

            /* Remap all data passed in to CM33-accessible addresses */
            for (uint32_t i = 0; i < inVec_cnt_ns; ++i)
            {
                #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
                CY_ASSERT(((uint32_t)(inVec_ns[i].base) % (__SCB_DCACHE_LINE_SIZE)) == 0);
                #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
                inVec_ns[i].base = (void*)cy_DTCMRemapAddr(inVec_ns[i].base);
                CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 11.8', 'No Const needed for cache method');
                MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(inVec_ns[i].base, inVec_ns[i].len);
            }
            for (uint32_t i = 0; i < outVec_cnt_ns; ++i)
            {
                #if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
                CY_ASSERT(((uint32_t)(outVec_ns[i].base) % (__SCB_DCACHE_LINE_SIZE)) == 0);
                #endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */
                outVec_ns[i].base = (void*)cy_DTCMRemapAddr(outVec_ns[i].base);
                MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(outVec_ns[i].base, outVec_ns[i].len);
            }

            // Send ipc_req over IPC and wait for return
            result = mtb_srf_ipc_request_send(client_context, ipc_req,
                                              MTB_SRF_IPC_SERVICE_TIMEOUT_US);
            /** Get result from secure ipc_req and prep for reading */
            if (result == CY_RSLT_SUCCESS)
            {
                MTB_SRF_INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
                    (uint32_t)(ipc_req->outVec_ptr),
                    sizeof(mtb_srf_outvec_ns_t) * outVec_cnt_ns);
                for (uint32_t i = 0; i < outVec_cnt_ns; ++i)
                {
                    MTB_SRF_INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(outVec_ns[i].base,
                                                                         outVec_ns[i].len);
                }
                result = ipc_req->request_rslt;
            }
            // Free allocate ipc_req object and semaphore
            cy_rslt_t dealloc_rslt = mtb_srf_ipc_pool_semaphore_free(
                client_context->pool,
                sema_idx);
            // Return whichever error occured first.  We always want to free even if the IPC
            // ipc_req failed.
            if ((result == CY_RSLT_SUCCESS) && (dealloc_rslt != CY_RSLT_SUCCESS))
            {
                result = dealloc_rslt;
            }
            dealloc_rslt = mtb_srf_ipc_pool_req_free(client_context->pool, ipc_req);
            if ((result == CY_RSLT_SUCCESS) && (dealloc_rslt != CY_RSLT_SUCCESS))
            {
                result = dealloc_rslt;
            }
        }
        else
        {
            // Voided as result is already a failure to allocate/free */
            (void)mtb_srf_ipc_pool_req_free(client_context->pool, ipc_req);
        }
    }
    return result;
}


#endif /* MTB_SRF_CUSTOM_IPC_REQUEST_SUBMIT */


/** Initializes an secure request pool */
cy_rslt_t mtb_srf_ipc_pool_init(mtb_srf_ipc_pool_t* pool,
                                mtb_srf_ipc_pool_cfg_t* cfg)
{
    cy_rslt_t result = MTB_SRF_ERR_BAD_PARAM;
    if ((NULL != pool) && (NULL != cfg) && (NULL != cfg->request_pool) &&
        (NULL != cfg->request_semaphores))
    {
        if ((cfg->num_semaphores < 32UL) && (cfg->num_requests < 32UL) && (cfg->num_semaphores > 0))
        {
            result = CY_RSLT_SUCCESS;
            (void)memset(pool, 0, sizeof(mtb_srf_ipc_pool_t));
            pool->num_semaphores = cfg->num_semaphores;
            pool->num_requests = cfg->num_requests;
            pool->request_semaphores = cfg->request_semaphores;
            pool->request_pool = cfg->request_pool;
            for (uint32_t i = 0; i < pool->num_requests; i++)
            {
                pool->request_available |= (1UL << i);
            }
            for (uint32_t i = 0; i < pool->num_semaphores; i++)
            {
                pool->semaphore_available |= (1UL << i);
            }
            #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
            if (cfg->num_requests > 0)
            {
                result = cy_rtos_semaphore_init(&pool->ipc_pool_request_arr_semaphore,
                                                cfg->num_requests,
                                                cfg->num_requests);
            }
            if (result == CY_RSLT_SUCCESS)
            {
                /* Already checked that (cfg->num_semaphores > 0) */
                result = cy_rtos_semaphore_init(&pool->ipc_pool_sem_arr_semaphore,
                                                cfg->num_semaphores,
                                                cfg->num_semaphores);
                if (result != CY_RSLT_SUCCESS)
                {
                    /* Unconcerned with the return here, we're backing out of a failed init */
                    (void)cy_rtos_semaphore_deinit(&pool->ipc_pool_request_arr_semaphore);
                }
            }
            #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */
        }
    }

    return result;
}


/** Allocate semaphore */
cy_rslt_t mtb_srf_ipc_pool_semaphore_alloc(mtb_srf_ipc_pool_t* pool, uint16_t* sema_idx,
                                           uint32_t timeout_us)
{
    cy_rslt_t result = MTB_SRF_ERR_ALLOCATE_FREE;
    uint32_t timeout_us_left = timeout_us;
    uint32_t idx = 0;
    if ((NULL == pool) || (NULL == sema_idx))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    cy_time_t rtos_timeout = _mtb_srf_timeout_for_rtos(timeout_us);
    cy_rslt_t rtos_result = cy_rtos_semaphore_get(&pool->ipc_pool_sem_arr_semaphore,
                                                  rtos_timeout);
    if (CY_RSLT_SUCCESS != rtos_result)
    {
        return rtos_result;
    }
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

    //Alloc request
    do
    {
        uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
        idx =
            _mtb_srf_ipc_find_first_free_bit(pool->semaphore_available,
                                             pool->num_semaphores);
        if (idx != _MTB_SRF_UNAVALIABLE_FOR_ALLOC)
        {
            pool->semaphore_available &= ~(1UL << idx);
            *sema_idx = idx;
            result = CY_RSLT_SUCCESS;
            mtb_hal_system_critical_section_exit(savedIntrStatus);
            break;
        }
        mtb_hal_system_critical_section_exit(savedIntrStatus);
        _mtb_srf_wait(&timeout_us_left, MTB_SRF_INTERVAL_US);
    } while (timeout_us_left != 0UL);

    return result;
}


/** Allocate secure request object */
cy_rslt_t mtb_srf_ipc_pool_req_alloc(mtb_srf_ipc_pool_t* pool, mtb_srf_ipc_packet_t** request,
                                     uint32_t timeout_us)
{
    cy_rslt_t result = MTB_SRF_ERR_ALLOCATE_FREE;
    uint32_t idx = 0;
    uint32_t timeout_us_left = timeout_us;
    if ((NULL == pool) || (NULL == request))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    cy_time_t rtos_timeout = _mtb_srf_timeout_for_rtos(timeout_us);
    /* Declare own result here as to not clash with the pool find below */
    cy_rslt_t rtos_result = cy_rtos_semaphore_get(&pool->ipc_pool_request_arr_semaphore,
                                                  rtos_timeout);
    if (CY_RSLT_SUCCESS != rtos_result)
    {
        return rtos_result;
    }
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */
    //Alloc request
    do
    {
        uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
        idx =
            _mtb_srf_ipc_find_first_free_bit(pool->request_available,
                                             pool->num_requests);
        if (idx != _MTB_SRF_UNAVALIABLE_FOR_ALLOC)
        {
            pool->request_available &= ~(1UL << idx);
            (void)memset(&pool->request_pool[idx], 0x0, sizeof(mtb_srf_ipc_packet_t));
            *request = &pool->request_pool[idx];
            result = CY_RSLT_SUCCESS;
            mtb_hal_system_critical_section_exit(savedIntrStatus);
            break;
        }
        mtb_hal_system_critical_section_exit(savedIntrStatus);
        _mtb_srf_wait(&timeout_us_left, MTB_SRF_INTERVAL_US);
    } while (timeout_us_left != 0UL);

    return result;
}


/** Deallocate a semaphore */
cy_rslt_t mtb_srf_ipc_pool_semaphore_free(mtb_srf_ipc_pool_t* pool, uint16_t sema_idx)
{
    /* Max size is dictated by the size of the semaphore bitmap in mtb_srf_ipc_pool_t */
    if ((NULL == pool) || (sema_idx > 32UL))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    //Dealloc the semaphore
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    CY_ASSERT((pool->semaphore_available & (1UL << sema_idx)) == 0UL);
    pool->semaphore_available |= (1UL << sema_idx);
    mtb_hal_system_critical_section_exit(savedIntrStatus);
    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    return cy_rtos_semaphore_set(&pool->ipc_pool_sem_arr_semaphore);
    #else
    return CY_RSLT_SUCCESS;
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */
}


/** Free secure request object */
cy_rslt_t mtb_srf_ipc_pool_req_free(mtb_srf_ipc_pool_t* pool,
                                    const mtb_srf_ipc_packet_t* request)
{
    uint32_t idx = 0UL;
    if ((NULL == pool) || (NULL == request))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    // Dealloc request
    uint32_t savedIntrStatus = mtb_hal_system_critical_section_enter();
    for (idx = 0L; idx < pool->num_requests; ++idx)
    {
        if (request == &pool->request_pool[idx])
        {
            CY_ASSERT((pool->request_available & (1UL << idx)) == 0UL);
            pool->request_available |= (1UL << idx);
        }
    }
    mtb_hal_system_critical_section_exit(savedIntrStatus);

    #if defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)
    /* Need to release regardless of if the above failed */
    cy_rslt_t rtos_result = cy_rtos_semaphore_set(&pool->ipc_pool_request_arr_semaphore);
    if (CY_RSLT_SUCCESS != rtos_result)
    {
        return rtos_result;
    }
    #endif /* defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE) */

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_setup_client_context
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_setup_client_context(mtb_srf_ipc_client_context_t* client_context,
                                       mtb_srf_ipc_client_context_cfg_t* cfg)
{
    if ((NULL == cfg) || (NULL == cfg->pool) || (NULL == client_context) ||
        (NULL == cfg->mailbox_handle))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    client_context->mailbox_handle = cfg->mailbox_handle;
    client_context->pool = cfg->pool;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_request_send
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_ipc_request_send(mtb_srf_ipc_client_context_t* client_context,
                                   mtb_srf_ipc_packet_t* request,
                                   uint64_t timeout_us)
{
    cy_rslt_t result = MTB_SRF_ERR_BAD_PARAM;
    if ((NULL == request) || (NULL == client_context))
    {
        return result;
    }

    MTB_SRF_CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY((uint32_t)(request), sizeof(mtb_srf_ipc_packet_t));
    result = mtb_ipc_mbox_sender_put(client_context->mailbox_handle, request, timeout_us);

    if (result == CY_RSLT_SUCCESS)
    {
        /* Lock deepsleep because IPC1's IRQ is active on CM55 */
        mtb_hal_syspm_lock_deepsleep();
        result =
            mtb_ipc_semaphore_take(
                &(client_context->pool->request_semaphores[request->semaphore_idx]),
                timeout_us);
        mtb_hal_syspm_unlock_deepsleep();
    }

    /** Invalidate packet and outvec before getting ready to return */
    MTB_SRF_INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY((uint32_t)(request),
                                                         sizeof(mtb_srf_ipc_packet_t));
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_client_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_ipc_client_init(mtb_srf_ipc_client_context_t* context,
                                  mtb_srf_ipc_client_init_cfg_t* cfg)
{
    if ((NULL == context) || (NULL == cfg) || (cfg->num_semaphores < cfg->num_requests))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    cy_rslt_t result = CY_RSLT_SUCCESS;
    /* Initialize semaphore handles */
    (void)memset(context, 0, sizeof(mtb_srf_ipc_client_context_t));
    for (uint32_t i = 0UL; i < cfg->num_semaphores; ++i)
    {
        result = mtb_ipc_semaphore_get_handle(cfg->ipc_instance,
                                              &(cfg->semaphore_handles[i]),
                                              cfg->ipc_sem_indexes[i],
                                              MTB_SRF_IPC_SERVICE_TIMEOUT_US);
        if (result == CY_RSLT_SUCCESS)
        {
            // If we re-initialize the client, we need to give the semaphores
            // back from the prior initialization. Ignore the return value here
            // because the give might fail if this is our first initialization
            (void)mtb_ipc_semaphore_give(&(cfg->semaphore_handles[i]));
            result = mtb_ipc_semaphore_take(&(cfg->semaphore_handles[i]),
                                            MTB_SRF_IPC_SERVICE_TIMEOUT_US);
        }
        if (result != CY_RSLT_SUCCESS)
        {
            break;
        }
    }

    if (result == CY_RSLT_SUCCESS)
    {
        result = mtb_ipc_mbox_sender_get_handle(cfg->ipc_instance, cfg->mailbox_handle,
                                                cfg->mbox_idx);
        if (result == CY_RSLT_SUCCESS)
        {
            mtb_srf_ipc_pool_cfg_t pool_cfg;
            pool_cfg.request_pool = cfg->srf_ipc_requests;
            pool_cfg.num_requests = cfg->num_requests;
            pool_cfg.request_semaphores = cfg->semaphore_handles;
            pool_cfg.num_semaphores = cfg->num_semaphores;
            result = mtb_srf_ipc_pool_init(cfg->srf_ipc_pool, &pool_cfg);
            if (result == CY_RSLT_SUCCESS)
            {
                mtb_srf_ipc_client_context_cfg_t client_cfg;
                client_cfg.pool = cfg->srf_ipc_pool;
                client_cfg.mailbox_handle = cfg->mailbox_handle;
                result = mtb_srf_setup_client_context(context, &client_cfg);
            }
        }
    }
    return result;
}


#else // if defined(MTB_SRF_SUBMIT_USE_IPC)

//--------------------------------------------------------------------------------------------------
// mtb_srf_setup_relay_context
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_setup_relay_context(mtb_srf_ipc_relay_context_t* relay_context,
                                      mtb_srf_ipc_relay_context_cfg_t* cfg)
{
    if ((NULL == cfg) || (NULL == relay_context) || (cfg->num_semaphores > 32UL) ||
        (cfg->request_semaphores == NULL))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    if (cfg->ipc_req_queue == NULL)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    relay_context->ipc_req_queue = cfg->ipc_req_queue;
    #else
    relay_context->ipc_req_buffer.head   = 0;
    relay_context->ipc_req_buffer.tail   = 0;
    relay_context->ipc_req_buffer.full   = false;
    relay_context->ipc_req_buffer.max    = cfg->num_requests;
    relay_context->ipc_req_buffer.buffer = cfg->buffer;
    #endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    relay_context->request_semaphores = cfg->request_semaphores;
    relay_context->num_semaphores = cfg->num_semaphores;
    relay_context->mailbox_handle = cfg->mailbox;

    return CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_receive_request
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_ipc_receive_request(mtb_srf_ipc_relay_context_t* relay_context,
                                      uint64_t timeout_us)
{
    if (NULL == relay_context)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    uint32_t timeout_us_left = timeout_us;
    mtb_srf_ipc_packet_t* request_addr = NULL;

    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    cy_time_t rtos_timeout = _mtb_srf_timeout_for_rtos(timeout_us_left);
    cy_time_t time_start = 0;
    cy_time_t time_end = 0;

    cy_rtos_time_get(&time_start);
    #endif
    cy_rslt_t result = mtb_ipc_mbox_receiver_get(relay_context->mailbox_handle,
                                                 (void**)&request_addr, timeout_us);
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    if (CY_RTOS_NEVER_TIMEOUT != rtos_timeout)
    {
        cy_rtos_time_get(&time_end);
        if ((time_end - time_start) >= rtos_timeout)
        {
            rtos_timeout = 0;
        }
        else
        {
            rtos_timeout -= (time_end - time_start);
        }
    }
    if ((result == CY_RSLT_SUCCESS) && (request_addr != NULL))
    {
        result = cy_rtos_queue_put(relay_context->ipc_req_queue, &request_addr,
                                   rtos_timeout);
    }
    #else // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    /** No RTOS so we add to ring buffer */
    if ((result == CY_RSLT_SUCCESS) && (request_addr != NULL))
    {
        do
        {
            result =
                _mtb_srf_ipc_put_req_in_buffer(&(relay_context->ipc_req_buffer), request_addr);
            if (result == CY_RSLT_SUCCESS)
            {
                break;
            }
            _mtb_srf_wait(&timeout_us_left, MTB_SRF_INTERVAL_US);
        } while(timeout_us_left != 0UL);
    }
    #endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    return result;
}


// --------------------------------------------------------------------------------------------------
// mtb_srf_ipc_process_request
// --------------------------------------------------------------------------------------------------
#ifndef MTB_SRF_CUSTOM_PROCESS_REQUEST
cy_rslt_t mtb_srf_ipc_process_request(mtb_srf_ipc_packet_t* request)
{
    if (NULL == request)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }

    request->request_rslt =  mtb_srf_request_submit(request->inVec_ptr, request->inVec_cnt_ns,
                                                    request->outVec_ptr, request->outVec_cnt_ns);
    return CY_RSLT_SUCCESS;
}


#endif /* MTB_SRF_CUSTOM_PROCESS_REQUEST */

//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_process_pending_request
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_ipc_process_pending_request(mtb_srf_ipc_relay_context_t* relay_context)
{
    if (NULL == relay_context)
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    cy_rslt_t result = MTB_SRF_ERR_BAD_PARAM;
    mtb_srf_ipc_packet_t* request_addr;
    /* Get pending request from queue or buffer*/
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    result = cy_rtos_queue_get(relay_context->ipc_req_queue, &request_addr,
                               CY_RTOS_NEVER_TIMEOUT);
    #else
    result = _mtb_srf_ipc_get_req_from_buffer(&(relay_context->ipc_req_buffer), &request_addr);
    #endif

    if ((result == CY_RSLT_SUCCESS) && (request_addr != NULL))
    {
        result =  mtb_srf_ipc_process_request(request_addr);
        cy_rslt_t give_result = mtb_srf_ipc_signal_complete(relay_context, request_addr);
        if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
        {
            result = give_result;
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_signal_complete
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_ipc_signal_complete(mtb_srf_ipc_relay_context_t* relay_context,
                                      mtb_srf_ipc_packet_t* request)
{
    cy_rslt_t result = MTB_SRF_ERR_BAD_PARAM;
    if ((NULL != request) && (NULL != relay_context))
    {
        uint16_t sema_idx = request->semaphore_idx;
        if (sema_idx < relay_context->num_semaphores)
        {
            result =  mtb_ipc_semaphore_give(&(relay_context->request_semaphores)[sema_idx]);
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_relay_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_ipc_relay_init(mtb_srf_ipc_relay_context_t* context,
                                 mtb_srf_ipc_relay_init_cfg_t* cfg)
{
    if ((NULL == context) || (NULL == cfg) || (cfg->num_semaphores < cfg->num_requests))
    {
        return MTB_SRF_ERR_BAD_PARAM;
    }
    cy_rslt_t result = CY_RSLT_SUCCESS;
    /* Keep track of how many semaphores have been sucessfully initialized */
    uint32_t max_sema = 0;

    for (uint32_t i = 0UL; i < cfg->num_semaphores; ++i)
    {
        mtb_ipc_semaphore_config_t sema_cfg;
        sema_cfg.semaphore_num = cfg->ipc_sem_indexes[i];
        sema_cfg.preemptable = false;
        result = mtb_ipc_semaphore_init(cfg->ipc_instance, &(cfg->semaphore_handles[i]),
                                        &(cfg->semaphore_data[i]), &sema_cfg);
        if (result != CY_RSLT_SUCCESS)
        {
            break;
        }
        else
        {
            /* Track last successful init idx*/
            max_sema = i;
        }
    }
    if (result == CY_RSLT_SUCCESS)
    {
        mtb_ipc_mbox_config_t mbox_cfg;
        mbox_cfg.mailbox_idx = cfg->mbox_idx;
        mbox_cfg.read_semaphore_num = cfg->mbox_read_sema_idx;
        mbox_cfg.write_semaphore_num = cfg->mbox_write_sema_idx;
        result = mtb_ipc_mbox_receiver_init(cfg->ipc_instance, cfg->mailbox_handle,
                                            cfg->mailbox_data, &mbox_cfg);
        if (result == CY_RSLT_SUCCESS)
        {
            mtb_srf_ipc_relay_context_cfg_t relay_cfg;
            relay_cfg.num_semaphores = cfg->num_semaphores;
            relay_cfg.mailbox = cfg->mailbox_handle;
            relay_cfg.request_semaphores = cfg->semaphore_handles;
            relay_cfg.num_requests = cfg->num_requests;
            #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
            relay_cfg.ipc_req_queue = cfg->ipc_req_queue;
            #else
            relay_cfg.buffer = cfg->buffer;
            #endif
            result = mtb_srf_setup_relay_context(context, &relay_cfg);
        }
        else
        {
            mtb_ipc_mbox_receiver_free(cfg->mailbox_handle);
        }
    }
    if (result != CY_RSLT_SUCCESS)
    {
        // Free previously set up semaphores
        for (uint32_t j = 0UL; j < max_sema; ++j)
        {
            mtb_ipc_semaphore_free(&(cfg->semaphore_handles[j]));
        }
    }
    return result;
}


#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_receive_thread
//--------------------------------------------------------------------------------------------------
void mtb_srf_ipc_receive_thread(void* arg)
{
    mtb_srf_ipc_relay_context_t* relay = (mtb_srf_ipc_relay_context_t*)arg;
    cy_rslt_t result = CY_RSLT_SUCCESS;
    while (1)
    {
        result = mtb_srf_ipc_receive_request(relay, MTB_IPC_NEVER_TIMEOUT);
        if (result != CY_RSLT_SUCCESS)
        {
            CY_ASSERT(0);
        }
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_srf_ipc_process_thread
//--------------------------------------------------------------------------------------------------
void mtb_srf_ipc_process_thread(void* arg)
{
    mtb_srf_ipc_relay_context_t* relay = (mtb_srf_ipc_relay_context_t*)arg;
    cy_rslt_t result = CY_RSLT_SUCCESS;
    while (1)
    {
        result = mtb_srf_ipc_process_pending_request(relay);
        if (result != CY_RSLT_SUCCESS)
        {
            CY_ASSERT(0);
        }
    }
}


#endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))

#endif // defined(MTB_SRF_SUBMIT_USE_IPC)

#endif // !defined(COMPONENT_SECURE_DEVICE)

#endif // !defined(CY_SRF_DISABLE)

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

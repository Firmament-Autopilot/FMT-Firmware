/***************************************************************************//**
* \file mtb_ipc.c
*
* \brief
* Provides a high level interface for interacting with the Infineon Inter Processor Communication.
* This interface abstracts out the chip specific details. If any chip specific
* functionality is necessary, or performance is critical the low level functions
* can be used directly.
*
********************************************************************************
* \copyright
* Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company) or
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



/*
 * \section section_impl_ipc_number Number of IPC channels that are available
 * Number of IPC channels (MTB_IPC_CHAN_0 ... MTB_IPC_CHAN_N) can be determined via
 * MTB_IPC_USR_CHANNELS define.
 * Here is the list of currently supported devices and their IPC HAL available channels:
 * - POSC6 : 8, valid range is from MTB_IPC_CHAN_0 to (including) MTB_IPC_CHAN_7
 * - Traveo/XMC7XXX : 3, valid range is from MTB_IPC_CHAN_0 to (including) MTB_IPC_CHAN_2
 * - PSE84 : 14, valid range is from MTB_IPC_CHAN_0 to (including) MTB_IPC_CHAN_13
 *
 */
#include <string.h>
#include "cy_syslib.h"
#include "mtb_ipc.h"
#include "mtb_hal_system.h"
#include "mtb_hal_irq_impl.h"

#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
/* RTOS_AWARE is for semaphore usage so that in a multi-threaded system, we can allow other
 * threads to run if the current thread is blocked by a MTB IPC/PDL IPC Semaphore.
 */
#include "cyabs_rtos.h"
#endif \
    /* (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0) */


/* DEBUGGING: Enable to check that MTB IPC Semaphore "take" status is the same as the PDL "set"
 * state. To enable debugging define _IS_PRIMARY_CORE on main core and _IS_SECONDARY_CORE on other
 * core and ENABLE_MTB_IPC_DEBUG_PRINT on both.
 * This test happens before & after all Semaphore operations if enabled.
 */
#if defined(_IS_PRIMARY_CORE)
#define ENABLE_MTB_IPC_PDL_SEMAPHORE_CHECK    1
#endif


#if defined(ENABLE_MTB_IPC_DEBUG_PRINT)
#include <stdio.h>
#if defined(_IS_PRIMARY_CORE)
#warning DEBUG INFO: Building for _IS_PRIMARY_CORE
#endif
#if defined(CORE_NAME_CM0P_0)
#warning DEBUG INFO: Building for CORE_NAME_CM0P_0
#endif
#if defined(CORE_NAME_CM4_0)
#warning DEBUG INFO: Building for CORE_NAME_CM4_0
#endif
#if defined(CORE_NAME_CM33)
#warning DEBUG INFO: Building for CORE_NAME_CM33
#endif
#if defined(CORE_NAME_CM55)
#warning DEBUG INFO: Building for CORE_NAME_CM55
#endif
#if defined(CORE_NAME_CM7_0)
#warning DEBUG INFO: Building for CORE_NAME_CM7_0
#endif
#if defined(CORE_NAME_CM7_1)
#warning DEBUG INFO: Building for CORE_NAME_CM7_1
#endif

/* Enable this for printing on NON-INIT Core */
#if defined(_IS_SECONDARY_CORE)
#define _MTB_NON_INIT_CORE_PRINTF(arg)     printf arg
#else
#define _MTB_NON_INIT_CORE_PRINTF(arg)
#endif
/* Enable this for printing on INIT Core */
#if defined(_IS_PRIMARY_CORE)
#define _MTB_INIT_CORE_PRINTF(arg)     printf arg
#else
#define _MTB_INIT_CORE_PRINTF(arg)
#endif

#else // if defined(ENABLE_MTB_IPC_DEBUG_PRINT)

#define _MTB_INIT_CORE_PRINTF(arg)
#define _MTB_NON_INIT_CORE_PRINTF(arg)

#endif // ENABLE_MTB_IPC_DEBUG_PRINT

#if defined(__cplusplus)
extern "C" {
#endif


/* Shared memory is non-cacheable memory. Currently we invalidate/clean all shared memory objects as
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
#define INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(addr, size) \
{ \
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.6', 1, 'Intentional typecast of uint32_t to void volatile * for address clean/invalidate procedures') \
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1, 'Intentional typecast to uint32_t for address clean/invalidate procedures') \
    SCB_InvalidateDCache_by_Addr((volatile void*)((uint32_t)(addr) & ~(__SCB_DCACHE_LINE_SIZE - 1UL)), (int32_t)(((size) + (__SCB_DCACHE_LINE_SIZE - 1UL)) &  ~(__SCB_DCACHE_LINE_SIZE - 1UL))); \
    if(((uint32_t)(addr) % __SCB_DCACHE_LINE_SIZE)!= 0UL) \
    { \
        SCB_InvalidateDCache_by_Addr( (volatile void*)((((uint32_t)(addr) + (size)) & ~(__SCB_DCACHE_LINE_SIZE - 1UL))), (int32_t)(__SCB_DCACHE_LINE_SIZE)); \
    } \
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4') \
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.6') \
}

//--------------------------------------------------------------------------------------------------
// clean_dcache
//--------------------------------------------------------------------------------------------------
#define CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(addr, size) \
{ \
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.6', 1, 'Intentional typecast of uint32_t to void volatile * for address clean/invalidate procedures') \
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1, 'Intentional typecast to uint32_t for address clean/invalidate procedures') \
    SCB_CleanDCache_by_Addr((volatile void*)((uint32_t)(addr) & ~(__SCB_DCACHE_LINE_SIZE - 1UL)), (int32_t)(((size) + (__SCB_DCACHE_LINE_SIZE - 1UL)) & ~(__SCB_DCACHE_LINE_SIZE - 1UL))); \
    if(((uint32_t)(addr) % __SCB_DCACHE_LINE_SIZE)!= 0UL) \
    { \
        SCB_CleanDCache_by_Addr( (volatile void*)((((uint32_t)(addr) + (size)) & ~(__SCB_DCACHE_LINE_SIZE - 1UL))), (int32_t)(__SCB_DCACHE_LINE_SIZE)); \
    } \
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4') \
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.6') \
}

#else // if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
#define INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(addr, size)
#define CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(addr, size)
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

/* This is the define to be used when we add support for multiple processes per queue
 * in Phase 2 work.
 */
#if defined(MTB_IPC_MULTI_PROCESS_PER_QUEUE)
    #error "Code needed for Multiple Processes per Queue"
#endif

/* Number of times to retry acquiring IPC lock during process interrupt */
#define _MTB_IPC_LOCK_ACQUIRE_RETRY_COUNT  (3U)

/* IPC semaphore timeout when performing internal IPC service tasks NON_ISR */
#define _MTB_IPC_SERVICE_SEMA_TIMEOUT_US      (2000ULL)

/* IPC library uses the last available semaphore
 * Queue Semaphores and Queue Notification semaphores count down from there.
 * Application Semaphores count up from 1st semaphore.
 */
#define _MTB_IPC_LAST_USER_SEMA_NUM               (_MTB_IPC_SEMA_COUNT - 1U)

/* Macro used for determining if we are executing in an ISR at runtime */
#define _MTB_IPC_EXECUTING_IN_ISR()               ((SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0UL)


/* Use this macro for checking & returning if timeout is != 0 in an ISR */
#define _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(timeout)      \
        CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1, 'Reviewed and determined it is safe to cast SCB mask to SCB_Type * for macro')    \
        if (  _MTB_IPC_EXECUTING_IN_ISR() && ( (timeout) != 0UL) )    \
        CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4') \
        {                                                                           \
                return MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;            \
        }

/* Use this macro for setting timeout in an ISR to 0 if it isn't already */
#define _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout)      \
        CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1, 'Reviewed and determined it is safe to cast SCB mask to SCB_Type * for macro')    \
        if ( _MTB_IPC_EXECUTING_IN_ISR() && ( (timeout) != 0UL) )    \
        CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4') \
        {                               \
                (timeout) = 0UL;            \
        }

/* internal define used to specify microseconds in milliseconds */
#define _MTB_IPC_US_PER_MS                        (1000U)

/* Internal define to check that a trigger mask has not been computed yet */
#define _MTB_IPC_TRIGGER_MASK_UNDEFINED               (0xFFFFUL)

/************************************ FORWARD DECLARATIONS*************************************/
static bool _mtb_ipc_check_if_semaphore_allocated(const mtb_ipc_t* obj, uint32_t semaphore_number);
cy_rslt_t _mtb_ipc_semaphore_take_internal(const mtb_ipc_semaphore_t* semaphore,
                                           uint64_t* timeout_us);
cy_rslt_t _mtb_ipc_lock_with_timeout(uint32_t channel, uint64_t* timeout_us);
mtb_ipc_queue_event_t _mtb_ipc_queue_all_events_enabled(const mtb_ipc_t* obj, uint32_t channel);
bool _mtb_ipc_should_wait_for_irq(uint32_t mask, uint32_t* fired_events);
cy_rslt_t _mtb_ipc_put_get_internal(const mtb_ipc_queue_t* queue, void* msg,
                                    mtb_ipc_queue_event_t* triggered_events, bool put);
void _mtb_ipc_mbox_enable_irq(const mtb_ipc_mbox_t* mbox, bool enable);
void _mtb_ipc_mbox_signal_other_core(const mtb_ipc_mbox_t* mbox);
void _mtb_ipc_mbox_register_cb(mtb_ipc_mbox_t* mbox,
                               mtb_ipc_mbox_event_callback_t callback,
                               void* callback_arg);

/************************************SEMAPHORE Debug helper************************************/
/* Enable above for testing IPC lib & PDL "taken" status */
#if defined(ENABLE_MTB_IPC_PDL_SEMAPHORE_CHECK)

/* debugging */
void _mtb_ipc_semaphore_validate_status_with_PDL(uint32_t line, const char* func_name)
{
    CY_ASSERT(func_name != NULL);
    /* go through the semaphore list and check that the PDL has the same state as we do */
    mtb_ipc_semaphore_data_t* walker = obj->ipc_shared_vars->ipc_semaphore_list;
    /* step through the linked list */
    while (walker != NULL)
    {
        uint32_t sema_num;
        bool MTB_IPC_taken;
        bool PDL_taken;
        cy_en_ipcsema_status_t pdl_stat;
        bool MTB_bit_allocated;


        /* check if the semaphore is taken */
        do
        {
            uint32_t interruptState = mtb_hal_system_critical_section_enter();     // For Thread
                                                                                   // safety, PDL
                                                                                   // handles Core
                                                                                   // safety
            sema_num  = walker->sema_number;
            MTB_IPC_taken = walker->sema_taken;
            PDL_taken = false;
            MTB_bit_allocated  =
                _mtb_ipc_check_if_semaphore_allocated(sema_num);
            pdl_stat = Cy_IPC_Sema_Status(sema_num);
            mtb_hal_system_critical_section_exit(interruptState);

            switch (pdl_stat)
            {
                case CY_IPC_SEMA_STATUS_LOCKED:
                    PDL_taken  = true;
                    break;

                case CY_IPC_SEMA_STATUS_UNLOCKED:
                    PDL_taken  = false;
                    break;

                default:
                    PDL_taken  = false;
                    break;
            }

            mtb_hal_system_delay_us(MTB_IPC_POLLING_INTERVAL_uS);
        } while (pdl_stat == CY_IPC_SEMA_NOT_ACQUIRED);

        if (MTB_bit_allocated == true)
        {
            if (MTB_IPC_taken != PDL_taken)
            {
                _MTB_INIT_CORE_PRINTF((
                                          "%ld %s() Walker %p : sema: %ld MTB_IPC_taken: %d PDL_taken %d\n",
                                          line, func_name,
                                          walker, sema_num, MTB_IPC_taken, PDL_taken));
            }
        }
        else
        {
            _MTB_INIT_CORE_PRINTF((
                                      "%ld %s() Walker %p : sema: %ld NOT Allocated? %d     MTBIPC_in_use: %d PDL_in_use %d\n",
                                      line, func_name, walker, sema_num, MTB_bit_allocated,
                                      MTB_IPC_taken, PDL_taken));
        }
        walker = walker->next_sema;
    }
}


#else // if defined(ENABLE_MTB_IPC_PDL_SEMAPHORE_CHECK)
    #define _mtb_ipc_semaphore_validate_status_with_PDL(line, func)
#endif // if defined(ENABLE_MTB_IPC_PDL_SEMAPHORE_CHECK)

/**IRQ checker for valid ranges */
static bool _mtb_ipc_irq_legal(uint32_t semaphore_irq, uint32_t queue_irq)
{
    #if (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS))
    //Needs special handling as the first set of CY_IPC_INTERRUPTS_PER_INSTANCE are for IPC0
    if (((semaphore_irq - CY_IPC_INTERRUPTS_PER_INSTANCE) < CY_IPC_INTERRUPTS_PER_INSTANCE) &&
        ((queue_irq - CY_IPC_INTERRUPTS_PER_INSTANCE) < CY_IPC_INTERRUPTS_PER_INSTANCE) && \
        (semaphore_irq > CY_IPC_INTERRUPTS_PER_INSTANCE) &&
        (queue_irq > CY_IPC_INTERRUPTS_PER_INSTANCE) && \
        (semaphore_irq != queue_irq))
    #else
    if ((semaphore_irq < CY_IPC_INTERRUPTS_PER_INSTANCE) &&
        (queue_irq < CY_IPC_INTERRUPTS_PER_INSTANCE) && \
        (semaphore_irq != queue_irq))
    #endif
    {
        return true;
    }
    else
    {
        return false;
    }
}


/********************************************* SEMAPHORE HELPERS
 *******************************************************/

/* Get IPC-library-level Semaphore allocation usage bit. 0 = not allocated, 1 = allocated
 * Lock the IPC library Semaphore before calling this function:
 *  mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us)
 */
static bool _mtb_ipc_check_if_semaphore_allocated(const mtb_ipc_t* obj, uint32_t semaphore_number)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(semaphore_number < _MTB_IPC_SEMA_COUNT);
    mtb_ipc_semaphore_data_t* walker =
        obj->ipc_shared_vars->ipc_semaphore_list;
    while (walker != NULL)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(walker, sizeof(mtb_ipc_semaphore_data_t));
        if (walker->sema_number == semaphore_number)
        {
            return true;
        }
        walker = walker->next_sema;
    }

    return false;
}


/*
 * This sets up a semaphore and adds it to respective linked lists
 * obj and semaphore_num must be checked before calling this functions
 * Lock the IPC library Semaphore before calling this function:
 *  mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us)
 */
static cy_rslt_t _mtb_ipc_sema_inner_init(mtb_ipc_t* obj, mtb_ipc_semaphore_t* semaphore,
                                          mtb_ipc_semaphore_data_t* sema_obj,
                                          uint32_t semaphore_num, bool preemptable)
{
    cy_rslt_t   result = CY_RSLT_SUCCESS;
    CY_ASSERT(obj != NULL);
    CY_ASSERT(semaphore != NULL);
    CY_ASSERT(sema_obj != NULL);

    /* The PDL IPC Semaphores are not "allocated" on an individual basis.
     * Just make sure the IPC library Semaphore has not been already taken.
     */
    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(sema_obj, sizeof(mtb_ipc_semaphore_data_t));
    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars->ipc_semaphore_list,
                                                 sizeof(mtb_ipc_semaphore_data_t));
    /* Check if this sema has been allocated */
    if (_mtb_ipc_check_if_semaphore_allocated(obj, semaphore_num) == true)
    {
        /* Semaphore is already allocated (initialized) */
        result = MTB_IPC_RSLT_ERR_SEMA_NUM_IN_USE;
    }
    else
    {
        (void)memset(sema_obj, 0x00, sizeof(mtb_ipc_semaphore_data_t));
        sema_obj->sema_preemptable = preemptable;
        sema_obj->sema_number = semaphore_num;
        /* Add to our list of semaphores */
        sema_obj->next_sema = obj->ipc_shared_vars->ipc_semaphore_list;
        obj->ipc_shared_vars->ipc_semaphore_list = sema_obj;
        /* Point handle to data*/
        semaphore->sema_obj = sema_obj;
        semaphore->instance = obj;
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(sema_obj, sizeof(mtb_ipc_semaphore_data_t));
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars->ipc_semaphore_list,
                                             sizeof(mtb_ipc_semaphore_data_t));
    }

    return result;
}


/** Take a lock with a timeout while not successful */
cy_rslt_t _mtb_ipc_lock_with_timeout(uint32_t channel, uint64_t* timeout_us)
{
    cy_en_ipcdrv_status_t result = CY_IPC_DRV_SUCCESS;
    CY_ASSERT(timeout_us != NULL);

    const IPC_STRUCT_Type* ipc_base = Cy_IPC_Drv_GetIpcBaseAddress(channel);

    do
    {
        result = Cy_IPC_Drv_LockAcquire(ipc_base);
        if (*timeout_us > 0ULL)
        {
            *timeout_us -= 1ULL;
        }
    } while((*timeout_us > 0ULL) && (result != (cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS));

    if (result == (cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS)
    {
        return CY_RSLT_SUCCESS;
    }
    else
    {
        return MTB_IPC_RSLT_ERR_TIMEOUT;
    }
}


/** Initializes the list of RTOS semaphores or tracking index to block operations while waiting
 * for a semaphore until an interrupt is fired
 */
static void _mtb_ipc_initialize_sema_irq(mtb_ipc_t* obj, bool init_core)
{
    CY_ASSERT(obj != NULL);

    cy_rslt_t result = CY_RSLT_SUCCESS;
    /* Initialize the RTOS semaphores for the pre-allocated pool */
    for (uint32_t pool_idx = 0UL; pool_idx < MTB_IPC_RTOS_SEMA_NUM; ++pool_idx)
    {
        #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
        result = cy_rtos_init_semaphore(&obj->rtos_semaphore_base[pool_idx], 1,
                                        0);
        #endif \
        // (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
        if (CY_RSLT_SUCCESS == result)
        {
            if (init_core)
            {
                for (uint32_t core_num = 0UL; core_num < _MTB_IPC_CORE_NUM; core_num++)
                {
                    obj->ipc_shared_vars->rtos_semaphore_idx[core_num][pool_idx].sema_idx
                        = _MTB_IPC_UNUSED_SEMAPHORE;
                    obj->ipc_shared_vars->rtos_semaphore_idx[core_num][pool_idx].
                    active_count = 0UL;
                }
            }
        }
    }

    if (init_core)
    {
        for (uint32_t core_num = 0UL; core_num < _MTB_IPC_CORE_NUM; core_num++)
        {
            obj->ipc_shared_vars->wait_semaphore_idx[core_num] = _MTB_IPC_UNUSED_SEMAPHORE;
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
        }
        obj->wait_semaphore_idx = _MTB_IPC_UNUSED_SEMAPHORE;
    }
}


/************************* IPC library Queue Helpers************************************/
/** Gets the pointer from the shared memory linked list for the queue/index combination */
static mtb_ipc_queue_data_t* _mtb_ipc_queue_array_get_pointer(const mtb_ipc_t* obj,
                                                              uint32_t channel_num,
                                                              uint32_t queue_index)
{
    mtb_ipc_queue_data_t* queue = NULL;
    CY_ASSERT(obj != NULL);

    if (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel_num))
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars,
                                                     sizeof(mtb_ipc_shared_t));
        CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                     'uint8_t to uint32_t type conversion intentional.')
        mtb_ipc_queue_data_t* walker =
            obj->ipc_shared_vars->ipc_queue_array[_MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(channel_num)];
        CY_MISRA_BLOCK_END('MISRA_CAST')
        while (walker != NULL)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(walker,
                                                         sizeof(mtb_ipc_queue_data_t));
            if (walker->queue_num == queue_index)
            {
                queue = walker;
                break;
            }
            walker = walker->next;
        }
    }
    return queue;
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_queue_array_set_pointer
//--------------------------------------------------------------------------------------------------
/** Adds or removes the queue_data to the shared memory linked list for its channel depending on
 * whether queue is specified or NULL respectively. */
static cy_rslt_t _mtb_ipc_queue_array_set_pointer(const mtb_ipc_t* obj, uint32_t channel_num,
                                                  uint32_t queue_index, mtb_ipc_queue_data_t* queue)
{
    CY_UNUSED_PARAMETER(queue_index);
    cy_rslt_t result = MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND;
    CY_ASSERT(obj != NULL);
    if (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel_num))
    {
        CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                     'uint8_t to uint32_t type conversion intentional.')
        uint32_t local_num = _MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(channel_num);
        CY_MISRA_BLOCK_END('MISRA_CAST')
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars,
                                                     sizeof(mtb_ipc_shared_t));
        if (queue != NULL)
        {
            queue->next = obj->ipc_shared_vars->ipc_queue_array[local_num];
            obj->ipc_shared_vars->ipc_queue_array[local_num] = queue;
            result = CY_RSLT_SUCCESS;
        }
        else
        {
            /* remove from the linked list */
            mtb_ipc_queue_data_t* last = NULL;
            mtb_ipc_queue_data_t* walker = obj->ipc_shared_vars->ipc_queue_array[local_num];
            while (walker != NULL)
            {
                INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(walker,
                                                             sizeof(mtb_ipc_queue_data_t));
                if (walker->queue_num == queue_index)
                {
                    if (walker == obj->ipc_shared_vars->ipc_queue_array[local_num])
                    {
                        /* obj is the first queue in the list
                         * point list to the next one.
                         */
                        obj->ipc_shared_vars->ipc_queue_array[local_num] =
                            obj->ipc_shared_vars->ipc_queue_array[local_num]->next;
                    }
                    else
                    {
                        last->next = walker->next;
                    }
                    break;
                }
                else
                {
                    last = walker;
                    walker = walker->next;
                }
            }
            result = CY_RSLT_SUCCESS;
        }
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_queue_array_set_local
//--------------------------------------------------------------------------------------------------
/** Adds or removes the queue to the local ipc obj linked list for its channel depending on whether
 * queue is specified or NULL respectively. */
static cy_rslt_t _mtb_ipc_queue_array_set_local(mtb_ipc_t* obj, uint32_t channel_num,
                                                uint32_t queue_index, mtb_ipc_queue_t* queue)
{
    CY_UNUSED_PARAMETER(queue_index);
    cy_rslt_t result = MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND;
    CY_ASSERT(obj != NULL);
    if (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel_num))
    {
        CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                     'uint8_t to uint32_t type conversion intentional.')
        uint32_t local_num = _MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(channel_num);
        CY_MISRA_BLOCK_END('MISRA_CAST')
        if (queue != NULL)
        {
            bool found = false;
            const mtb_ipc_queue_t* walker = obj->queue_array[local_num];
            while (walker != NULL)
            {
                INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(walker->queue_obj,
                                                             sizeof(mtb_ipc_queue_data_t));
                if (walker->queue_obj->queue_num == queue_index)
                {
                    found = true;
                    break;
                }
                walker = walker->next;
            }
            if (!found)
            {
                queue->next = obj->queue_array[local_num];
                obj->queue_array[local_num] = queue;
            }
            result = CY_RSLT_SUCCESS;
        }
        else
        {
            /* remove from the linked list */
            mtb_ipc_queue_t* last = NULL;
            mtb_ipc_queue_t* walker = obj->queue_array[local_num];
            while (walker != NULL)
            {
                INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(walker->queue_obj,
                                                             sizeof(mtb_ipc_queue_data_t));
                if (walker->queue_obj->queue_num == queue_index)
                {
                    if (walker == obj->queue_array[local_num])
                    {
                        /* obj is the first queue in the list
                         * point list to the next one.
                         */
                        obj->queue_array[local_num] =
                            obj->queue_array[local_num]->next;
                    }
                    else
                    {
                        last->next = walker->next;
                    }
                    break;
                }
                else
                {
                    last = walker;
                    walker = walker->next;
                }
            }
            result = CY_RSLT_SUCCESS;
        }
    }
    return result;
}


/********************************* IPC library INTERRUPT HANDLER
 ********************************************/
/** Process a semaphore interrupt. It iterates through associated RTOS semaphores so it only is
 * looking for relevant semaphores instead of whole linked list.
 */
void mtb_ipc_semaphore_process_interrupt(mtb_ipc_t* obj)
{
    if (obj == NULL)
    {
        return;
    }

    IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(obj->semaphore_irq);
    /* We are interested in Release events for semaphores and Notify events for mailboxes*/
    uint32_t semaphore_status_masked = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_RELEASE, Cy_IPC_Drv_GetInterruptStatusMasked(
                                                    ipc_intr_base));
    uint32_t mbox_status_masked = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_NOTIFY, Cy_IPC_Drv_GetInterruptStatusMasked(
                                               ipc_intr_base));
    /* Debugging - enable at top of this file */
    _MTB_NON_INIT_CORE_PRINTF((
                                  "%ld %s() caller:%p, isr_channel(%lu), semaphore_status_masked(0x%lx)\n",
                                  __LINE__, __func__, __builtin_return_address(0), isr_channel,
                                  semaphore_status_masked));

    Cy_IPC_Drv_ClearInterrupt(ipc_intr_base, semaphore_status_masked, mbox_status_masked);
    if (semaphore_status_masked != 0UL)
    {
        #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
        for (uint32_t sema_idx = 0UL; sema_idx < MTB_IPC_RTOS_SEMA_NUM; sema_idx++)
        {
            uint32_t current_sema_mask = 1UL << sema_idx;
            if (semaphore_status_masked & current_sema_mask)
            {
                (void)cy_rtos_semaphore_set(
                    &obj->rtos_semaphore_base[sema_idx]);
            }
        }
        #else
        /** Set index to unused as the interrupt has signaled it was given */
        obj->wait_semaphore_idx = _MTB_IPC_UNUSED_SEMAPHORE;
        #endif \
        /* (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
         */
    }

    //Use notify bits for mailboxes
    if (mbox_status_masked != 0UL)
    {
        for (uint32_t mbox_idx = 0u; mbox_idx < MTB_IPC_MAX_MBOXES; mbox_idx++)
        {
            uint32_t mbox_mask = 1UL << mbox_idx;
            if ((mbox_status_masked & mbox_mask) != 0u)
            {
                CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.1', 1,
                                             'Reviewed: Cast is safe, it was cast from mtb_ipc_mbox_event_callback_t to cy_israddress when assigned to callback_data.callback')
                mtb_ipc_mbox_event_callback_t callback =
                    (mtb_ipc_mbox_event_callback_t)obj->mbox_array[mbox_idx]->callback_data.callback;
                CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.1')
                void* callback_arg = obj->mbox_array[mbox_idx]->callback_data.callback_arg;
                if ((obj->mbox_array[mbox_idx] != NULL) &&
                    (callback != NULL))
                {
                    //Fire both events as currently they only fire on opposite cores
                    callback(callback_arg,
                             (mtb_ipc_mbox_event_t)(MTB_IPC_MBOX_FULL | MTB_IPC_MBOX_EMPTY));
                }
            }
        }
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_process_queue_interrupt
//--------------------------------------------------------------------------------------------------
/** Searches through linked lists per channel to find relevant data and execute ISR */
void mtb_ipc_queue_process_interrupt(const mtb_ipc_t* obj)
{
    if (obj == NULL)
    {
        return;
    }

    IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(obj->queue_irq);
    /* We are interested only in Release events */
    uint32_t interrupt_status_masked_original = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_RELEASE, Cy_IPC_Drv_GetInterruptStatusMasked(
                                                             ipc_intr_base));
    uint32_t interrupt_status_masked = interrupt_status_masked_original;

    /* Debugging - enable at top of this file */
    _MTB_NON_INIT_CORE_PRINTF((
                                  "%ld %s() caller:%p, isr_channel(%lu), interrupt_status_masked(0x%lx)\n",
                                  __LINE__, __func__, __builtin_return_address(0), isr_channel,
                                  interrupt_status_masked));

    // We start iteration through channels from first valid channel
    uint32_t channel = (uint32_t)MTB_IPC_CHAN_0;

    while (interrupt_status_masked != 0UL)
    {
        CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                     'uint8_t to uint32_t type conversion intentional.')
        uint32_t channel_mask = (uint32_t)CY_IPC_CH_MASK(channel);
        CY_MISRA_BLOCK_END('MISRA_CAST')
        if ((interrupt_status_masked & channel_mask) != 0UL)
        {
            interrupt_status_masked &= ~channel_mask;

            /* This channel got an interrupt on this core
             * Check all queues in the channel to see if we have any callbacks to execute
             */
            CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                         'uint8_t to uint32_t type conversion intentional.')
            mtb_ipc_queue_t* queue = obj->queue_array[_MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(channel)];
            CY_MISRA_BLOCK_END('MISRA_CAST')
            while (queue != NULL)
            {
                mtb_ipc_queue_event_callback_t callback = NULL;
                void* callback_arg = NULL;
                mtb_ipc_queue_event_t flags = MTB_IPC_NO_INTR;
                mtb_ipc_queue_event_t callback_flags = MTB_IPC_NO_INTR;

                IPC_STRUCT_Type* ipc_base = Cy_IPC_Drv_GetIpcBaseAddress(channel);

                INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue->queue_obj,
                                                             sizeof(mtb_ipc_queue_data_t));
                if (queue->callback_data.callback != NULL)
                {
                    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.1', 1,
                                                 'Reviewed: Cast is safe, it was cast from mtb_ipc_queue_event_callback_t to cy_israddress when assigned to callback_data.callback')
                    callback =
                        (mtb_ipc_queue_event_callback_t)queue->callback_data.callback;
                    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.1')
                    callback_arg = queue->callback_data.callback_arg;
                }
                if (queue->queue_obj->notifications[_MTB_IPC_CUR_CORE_IDX].flags !=
                    (uint32_t)MTB_IPC_NO_INTR)
                {
                    flags =
                        (mtb_ipc_queue_event_t)queue->queue_obj->notifications[
                            _MTB_IPC_CUR_CORE_IDX].
                        flags;
                    callback_flags |=
                        (mtb_ipc_queue_event_t)(queue->events_enabled & (uint32_t)flags);

                    /* Any modification of a queue's notifications must be done inside a lock on
                     * its channel, due to timing issues try at most 3 times to acquire the lock */
                    uint8_t attempt_lock_acquire = 0U;
                    cy_en_ipcdrv_status_t lock_acquire = CY_IPC_DRV_ERROR;
                    do
                    {
                        lock_acquire = Cy_IPC_Drv_LockAcquire(ipc_base);
                        if ((cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS == lock_acquire)
                        {
                            /* clear flags */
                            queue->queue_obj->notifications[_MTB_IPC_CUR_CORE_IDX].flags =
                                (uint32_t)MTB_IPC_NO_INTR;

                            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj,
                                                                 sizeof(mtb_ipc_queue_data_t));

                            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
                        }
                        else
                        {
                            attempt_lock_acquire++;
                        }
                    } while ((attempt_lock_acquire < _MTB_IPC_LOCK_ACQUIRE_RETRY_COUNT) &&
                             ((cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS != lock_acquire));
                }
                /* Do not trigger an interrupt  */
                /* For any ongoing operations that are waiting*/
                queue->events_fired = (uint32_t)flags;
                /* Clear handled interrupt */
                Cy_IPC_Drv_ClearInterrupt(ipc_intr_base,
                                          (interrupt_status_masked_original & channel_mask),
                                          CY_IPC_NO_NOTIFICATION);

                #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
                /* Signal any RTOS tasks waiting on this queue event */
                if ((flags & MTB_IPC_QUEUE_WRITE) && (queue->rtos_event_waiting_count > 0U))
                {
                    (void)cy_rtos_event_setbits(&queue->queue_rtos_event, MTB_IPC_QUEUE_WRITE);
                    queue->rtos_event_waiting_count -= 1;
                }
                if ((flags & MTB_IPC_QUEUE_READ) && (queue->rtos_event_waiting_count > 0U))
                {
                    (void)cy_rtos_event_setbits(&queue->queue_rtos_event, MTB_IPC_QUEUE_READ);
                    queue->rtos_event_waiting_count -= 1;
                }
                #endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))

                if ((callback != NULL) &&
                    (callback_flags != (mtb_ipc_queue_event_t)MTB_IPC_NO_INTR))
                {
                    callback(callback_arg, callback_flags);
                }
                if (queue->next == NULL)
                {
                    break;
                }
                else
                {
                    queue = queue->next;
                }
            }
        }
        channel++;       /* For multiple channel interrupts on this core */
        if (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel) == false)
        {
            break;
        }
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_queue_update_mask
//--------------------------------------------------------------------------------------------------
/** Enables the event for this queue if not already done.
 * Uses counters in case of temporary enablement to clean up after function concludes */
static void _mtb_ipc_queue_update_mask(mtb_ipc_queue_t* queue,
                                       mtb_ipc_queue_event_t event,
                                       bool enable)
{
    CY_ASSERT(queue != NULL);
    uint32_t intr_status = mtb_hal_system_critical_section_enter();
    if ((event & (mtb_ipc_queue_event_t)queue->events_enabled) != 1UL)
    {
        if (enable)
        {
            // added temporarily for a put/get
            if (((queue->pending_reads == 0U) &&
                 (event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_WRITE)) ||
                ((queue->pending_writes == 0U) &&
                 (event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_READ)))
            {
                queue->queue_obj->notifications[_MTB_IPC_CUR_CORE_IDX].mask |= (uint32_t)event;
                CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj->notifications,
                                                     _MTB_IPC_MAX_PROCESSES_PER_QUEUE *
                                                     sizeof(_mtb_ipc_queue_process_info_t));
            }
            //This is already temporarily enabled, increment counter of entities waiting for
            // this event
            if (event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_READ)
            {
                queue->pending_writes += 1U;
            }
            if (event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_WRITE)
            {
                queue->pending_reads += 1U;
            }
        }
        else
        {
            //decrement counter of entities waiting for this event
            if ((event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_READ) && (queue->pending_writes > 0U))
            {
                queue->pending_writes -= 1U;
            }
            if ((event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_WRITE) && (queue->pending_reads > 0U))
            {
                queue->pending_reads -= 1U;
            }
            // Remove if only added temporarily for a put/get
            if (((queue->pending_reads == 0U) &&
                 (event & (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_WRITE)) ||
                ((queue->pending_writes == 0U) &&
                 (event == (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_READ)))
            {
                queue->queue_obj->notifications[_MTB_IPC_CUR_CORE_IDX].mask &= ~(uint32_t)event;
                CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj->notifications,
                                                     _MTB_IPC_MAX_PROCESSES_PER_QUEUE *
                                                     sizeof(_mtb_ipc_queue_process_info_t));
            }
        }
    }

    mtb_hal_system_critical_section_exit(intr_status);
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_enable_channel_interrupt
//--------------------------------------------------------------------------------------------------
/** Enables the interrupt for this channel */
static cy_rslt_t _mtb_ipc_enable_channel_interrupt(const mtb_ipc_t* obj, uint32_t channel,
                                                   bool enable, uint64_t* timeout_us)
{
    cy_rslt_t result;
    CY_ASSERT(obj != NULL);
    CY_ASSERT(timeout_us != NULL);
    IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(obj->queue_irq);
    CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                 'uint8_t to uint32_t type conversion intentional.')
    uint32_t channel_intr_mask = (uint32_t)CY_IPC_CH_MASK(channel);
    CY_MISRA_BLOCK_END('MISRA_CAST')

    /* We cannot allow interrupt to happen between taking and giving the internal semaphore
     * as interrupt will also attempt to acquire semaphore (which will obviously fail) */
    uint32_t intr_status = mtb_hal_system_critical_section_enter();
    result = _mtb_ipc_semaphore_take_internal(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        uint32_t current_ipc_interrupt_mask = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_RELEASE, Cy_IPC_Drv_GetInterruptMask(
                                                           ipc_intr_base));
        if (enable)
        {
            //Check that not already enabled
            if ((current_ipc_interrupt_mask & channel_intr_mask) == 0UL)
            {
                Cy_IPC_Drv_ClearInterrupt(ipc_intr_base, channel_intr_mask,
                                          CY_IPC_NO_NOTIFICATION);
                Cy_IPC_Drv_SetInterruptMask(ipc_intr_base,
                                            current_ipc_interrupt_mask | channel_intr_mask,
                                            CY_IPC_NO_NOTIFICATION);
            }
        }
        else
        {
            Cy_IPC_Drv_SetInterruptMask(ipc_intr_base,
                                        current_ipc_interrupt_mask & ~channel_intr_mask,
                                        CY_IPC_NO_NOTIFICATION);
        }
        result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
    }
    mtb_hal_system_critical_section_exit(intr_status);

    return result;
}


/** Get all events enabled on all cores */
mtb_ipc_queue_event_t _mtb_ipc_queue_all_events_enabled(const mtb_ipc_t* obj, uint32_t channel)
{
    mtb_ipc_queue_event_t events_enabled = MTB_IPC_NO_INTR;
    /* Go through the events for this channel and see if we have events to trigger the interrupt
     */
    CY_ASSERT(obj != NULL);

    CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                 'uint8_t to uint32_t type conversion intentional.')
    mtb_ipc_queue_data_t* current_queue = \
        obj->ipc_shared_vars->ipc_queue_array[_MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(
                                                  channel)];
    CY_MISRA_BLOCK_END('MISRA_CAST')
    while (current_queue != NULL)
    {
        #if defined(MTB_IPC_MULTI_PROCESS_PER_QUEUE)
        #error "Validate this code for Multiple Processes per Queue"
        #endif
        for (uint32_t process_idx = 0UL; process_idx < _MTB_IPC_MAX_PROCESSES_PER_QUEUE;
             process_idx++)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(current_queue,
                                                         sizeof(mtb_ipc_queue_data_t));
            events_enabled |= (mtb_ipc_queue_event_t)current_queue->notifications[process_idx].mask;
        }
        current_queue = current_queue->next;
    }
    return events_enabled;
}


//Calculate mask of channels when firing a release
static uint32_t _mtb_ipc_calculate_trigger_mask(mtb_ipc_t* obj, uint64_t* timeout_us)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    uint32_t mask = 0UL;
    CY_ASSERT(obj != NULL);
    CY_ASSERT(timeout_us != NULL);
    //Mask not calculated yet
    if (obj->trigger_mask == _MTB_IPC_TRIGGER_MASK_UNDEFINED)
    {
        result = _mtb_ipc_semaphore_take_internal(&obj->internal_ipc_semaphore, timeout_us);
        if (result == CY_RSLT_SUCCESS)
        {
            //Calculate mask
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars,
                                                         sizeof(mtb_ipc_shared_t));
            for (uint32_t i = 0UL; i < _MTB_IPC_MAX_PROCESSES_PER_QUEUE; i++)
            {
                CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                             'uint8_t to uint32_t type conversion intentional.')
                mask |= (uint32_t)CY_IPC_INTR_MASK(
                    obj->ipc_shared_vars->irq_channels[i].queue_irq);
                CY_MISRA_BLOCK_END('MISRA_CAST')
            }
            obj->trigger_mask = mask;
            result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
            CY_ASSERT(CY_RSLT_SUCCESS == result);
            CY_UNUSED_PARAMETER(result);
        }
    }
    return obj->trigger_mask;
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_trigger_interrupts_for_channel
//--------------------------------------------------------------------------------------------------
/** Creates a mask and then lock releases to trigger notifications on all cores */
static void _mtb_ipc_trigger_interrupts_for_channel(mtb_ipc_t* obj, uint32_t channel,
                                                    uint64_t* timeout_us)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(timeout_us != NULL);
    IPC_STRUCT_Type* ipc_base = Cy_IPC_Drv_GetIpcBaseAddress(channel);
    //Mask not calculated yet
    uint32_t mask = _mtb_ipc_calculate_trigger_mask(obj, timeout_us);
    //Send mask
    cy_rslt_t result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(channel, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        (void)Cy_IPC_Drv_LockRelease(ipc_base, mask);
    }
}


/** Check if we should be waiting for an event before continuing */
bool _mtb_ipc_should_wait_for_irq(uint32_t mask, uint32_t* fired_events)
{
    CY_ASSERT(fired_events != NULL);
    bool ret = true;
    uint32_t intr_status = mtb_hal_system_critical_section_enter();
    if (*fired_events & mask)
    {
        *fired_events &= ~mask;
        ret = false;
    }
    mtb_hal_system_critical_section_exit(intr_status);

    return ret;
}


/** Put or get into the queue, must be done while queue semaphore is taken */
cy_rslt_t _mtb_ipc_put_get_internal(const mtb_ipc_queue_t* queue, void* msg,
                                    mtb_ipc_queue_event_t* triggered_events, bool put)
{
    CY_ASSERT(msg != NULL);
    CY_ASSERT(queue != NULL);
    CY_ASSERT(triggered_events != NULL);
    cy_rslt_t result = MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    if (true == put)
    {
        result = MTB_IPC_RSLT_ERR_QUEUE_FULL;
        /* Try to Put the message into the queue */
        if (queue->queue_obj->curr_items < queue->queue_obj->max_num_items)
        {
            uint32_t item_index  =
                (queue->queue_obj->first_item + queue->queue_obj->curr_items) %
                queue->queue_obj->max_num_items;
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.4', 1,
                                         'Reviewed: Arithmetic is intentional for address calculation')
            uint8_t* queue_item =
                (uint8_t*)queue->queue_obj->queue_pool +
                (item_index * queue->queue_obj->item_size);
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.4')

                (void) memcpy((void*)queue_item, msg, queue->queue_obj->item_size);

            queue->queue_obj->curr_items++;

            CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                         'Conversion between unsigned to signed int32_t intentional.')
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue_item, queue->queue_obj->item_size);
            CY_MISRA_BLOCK_END('MISRA_CAST')
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj,
                                                 sizeof(mtb_ipc_queue_data_t));

            *triggered_events |= (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_WRITE;
            result = CY_RSLT_SUCCESS;

            /* Trigger interrupt when we are full, but not every time we call if it is
                already full */
            if (queue->queue_obj->curr_items == queue->queue_obj->max_num_items)
            {
                *triggered_events |= (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_FULL;
            }
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj,
                                                 sizeof(mtb_ipc_queue_data_t));
        }
    }
    else
    {
        /* Try to GET the message from the queue */
        result = MTB_IPC_RSLT_ERR_QUEUE_EMPTY;    /* assume failure */

        /* Get the message from the queue */
        if (queue->queue_obj->curr_items > 0UL)
        {
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 18.4', 1,
                                         'Reviewed: Arithmetic is intentional for address calculation')
            uint8_t* queue_item =
                (uint8_t*)queue->queue_obj->queue_pool +
                (queue->queue_obj->first_item * queue->queue_obj->item_size);
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 18.4')
            uint32_t next_item = (queue->queue_obj->first_item + 1UL) %
                                 queue->queue_obj->max_num_items;
            CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                         'Conversion between unsigned to signed int32_t intentional.')
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue_item,
                                                         queue->queue_obj->item_size);
            CY_MISRA_BLOCK_END('MISRA_CAST')

                (void) memcpy(msg, (void*)queue_item, queue->queue_obj->item_size);

            queue->queue_obj->first_item = next_item;
            queue->queue_obj->curr_items--;

            CY_MISRA_DEVIATE_BLOCK_START('MISRA_CAST', 1,
                                         'Conversion between unsigned to signed int32_t intentional.')
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(msg, queue->queue_obj->item_size);
            CY_MISRA_BLOCK_END('MISRA_CAST')
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj,
                                                 sizeof(mtb_ipc_queue_data_t));

            *triggered_events |= (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_READ;
            result = CY_RSLT_SUCCESS;

            /* Trigger interrupt when we empty, but not every time we call if it is already
                empty */
            if (queue->queue_obj->curr_items == 0UL)
            {
                *triggered_events |= (mtb_ipc_queue_event_t)MTB_IPC_QUEUE_EMPTY;
            }
        }
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_queue_put_get
//--------------------------------------------------------------------------------------------------
/** Helper function to use common parts of put/ get functions for adding and removing from the queue
 */
static cy_rslt_t _mtb_ipc_queue_put_get(mtb_ipc_queue_t* queue, void* msg,
                                        uint64_t timeout_us, bool put)
{
    CY_ASSERT(queue != NULL);
    CY_ASSERT(queue->queue_obj != NULL);
    CY_ASSERT(msg != NULL);

    uint32_t i;
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_ipc_queue_event_t triggered_events = MTB_IPC_NO_INTR;
    mtb_ipc_queue_event_t event_to_wait = MTB_IPC_NO_INTR;

    //Initialize as a non-existent channel so that it will fail if
    // not rewritten as correct channel
    uint32_t channel_num = 0xFFFFUL;
    IPC_STRUCT_Type* ipc_base = NULL;

    //Use never timeout if requested
    uint64_t timeout_us_left =
        (timeout_us == MTB_IPC_NEVER_TIMEOUT) ? MTB_IPC_NEVER_TIMEOUT : timeout_us;

    bool completed = false;
    /* We loop here if timeout_us > 0 */
    bool never_timeout = (timeout_us_left == MTB_IPC_NEVER_TIMEOUT) ? true : false;

    // Flag to use to avoid busy wait
    bool wait_for_irq = false;
    // Flag to use RTOS integration
    bool wait_irq_enabled = false;
    // Modified mask
    bool modified_mask = false;
    //Mask used to trigger IRQs. By default no notification
    uint32_t trigger_mask = CY_IPC_NO_NOTIFICATION;

    do
    {
        if (wait_irq_enabled)
        {
            wait_for_irq = _mtb_ipc_should_wait_for_irq((uint32_t)event_to_wait,
                                                        &queue->events_fired);
        }

        if (!wait_for_irq)
        {
            result = _mtb_ipc_semaphore_take_internal(&queue->semaphore_handle, &timeout_us_left);
            if (result == CY_RSLT_SUCCESS)
            {
                /* Invalidate cache each time so we get proper updates */
                INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue->queue_obj,
                                                             sizeof(mtb_ipc_queue_data_t));
                channel_num = queue->queue_obj->channel_num;

                //Set here for use in all PDL functions
                ipc_base = Cy_IPC_Drv_GetIpcBaseAddress(channel_num);
                bool locked = false;

                result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(channel_num, &timeout_us_left);
                if (result == CY_RSLT_SUCCESS)
                {
                    locked = true;
                    #if defined(MTB_IPC_MULTI_PROCESS_PER_QUEUE)
                    #error Need to handle multiple processes per core here
                    #endif
                    result = _mtb_ipc_put_get_internal(queue, msg, &triggered_events, put);
                    if (result == CY_RSLT_SUCCESS)
                    {
                        completed = true;
                    }

                    /* We send events even if the put/get fails for FULL or EMPTY */
                    /** Any modification of a queue's notifs must be done inside a lock on its
                       channel */
                    if (triggered_events != (mtb_ipc_queue_event_t)MTB_IPC_NO_INTR)
                    {
                        for (i = 0UL; i < _MTB_IPC_MAX_PROCESSES_PER_QUEUE; i++)
                        {
                            queue->queue_obj->notifications[i].flags |=
                                queue->queue_obj->notifications[i].mask &
                                (uint32_t)triggered_events;
                        }
                        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj->notifications,
                                                             _MTB_IPC_MAX_PROCESSES_PER_QUEUE *
                                                             sizeof(_mtb_ipc_queue_process_info_t));
                        //Calculate mask to trigger IRQ
                        if (completed)
                        {
                            trigger_mask = _mtb_ipc_calculate_trigger_mask(queue->instance,
                                                                           &timeout_us_left);
                        }
                    }

                    if (!completed && (timeout_us_left > 0ULL))
                    {
                        // We need to enable interrupts to wait on a write/read as queue is
                        //full/empty
                        event_to_wait = (put == true) ? MTB_IPC_QUEUE_READ : MTB_IPC_QUEUE_WRITE;

                        if ((queue->events_enabled & (uint32_t)event_to_wait) != 1UL)
                        {
                            // Add event to this core's mask
                            _mtb_ipc_queue_update_mask(queue, event_to_wait, true);
                            modified_mask = true;
                            //Enable channel interrupt if it has not been done so
                            (void)_mtb_ipc_enable_channel_interrupt(queue->instance, channel_num,
                                                                    true, &timeout_us_left);
                            wait_irq_enabled = true;
                        }
                    }
                }
                cy_rslt_t give_result = mtb_ipc_semaphore_give(&queue->semaphore_handle);
                if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
                {
                    result =give_result;
                }
                //Lock release here to avoid firing Interrupt when semaphore is still taken
                //We only release if the original lock was successful
                if (locked)
                {
                    (void)Cy_IPC_Drv_LockRelease(ipc_base, trigger_mask);
                }
            }
        }

        #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
        if ((completed == false) && (timeout_us_left >= _MTB_IPC_US_PER_MS))
        {
            if ((queue->events_enabled != MTB_IPC_NO_INTR) || wait_irq_enabled)
            {
                uint32_t bits = (put == true) ? MTB_IPC_QUEUE_READ : MTB_IPC_QUEUE_WRITE;
                //Track time delayed
                uint32_t timeout_ms =
                    (never_timeout == true) ? MTB_IPC_NEVER_TIMEOUT_MS : ((timeout_us_left) / 1000);
                uint32_t time_start = 0;
                uint32_t time_end = 0;
                // Increase count of RTOS tasks waiting on events
                queue->rtos_event_waiting_count += 1;

                cy_rtos_time_get(&time_start);
                cy_rtos_event_waitbits(&queue->queue_rtos_event, &bits, true, true, timeout_ms);
                cy_rtos_time_get(&time_end);
                if (timeout_us_left > 1000 * (time_end - time_start))
                {
                    timeout_us_left -= 1000 * (time_end - time_start);
                }
                else
                {
                    timeout_us_left = timeout_us_left % 1000;
                }
            }
        }
        #endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))

        if (timeout_us_left > 0ULL)
        {
            timeout_us_left -= 1ULL;
        }
    } while(((timeout_us_left > 0ULL) || never_timeout) && (completed == false));


    //Reset notification mask (and irq mask) to original state if they were modified
    if (modified_mask)
    {
        // We cannot reach this section unless we have already modified masks and interrupts
        uint32_t events_enabled = (uint32_t)MTB_IPC_NO_INTR;
        // Disable temporary events and check if any events remain
        cy_rslt_t lock_result =
            (cy_rslt_t)_mtb_ipc_lock_with_timeout(channel_num, &timeout_us_left);
        if (lock_result == CY_RSLT_SUCCESS)
        {
            _mtb_ipc_queue_update_mask(queue, event_to_wait, false);
            events_enabled = (uint32_t)_mtb_ipc_queue_all_events_enabled(queue->instance,
                                                                         channel_num);
            /* All channel-related queues have no events enabled, disabling interrupts */
            if (events_enabled == (uint32_t)MTB_IPC_NO_INTR)
            {
                (void)_mtb_ipc_enable_channel_interrupt(queue->instance, channel_num,
                                                        false, &timeout_us_left);
            }
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
    }

    return result;
}


/****************************************** INIT PUBLIC FUNCTIONS
 *****************************************************/
cy_rslt_t mtb_ipc_init(mtb_ipc_t* obj, mtb_ipc_shared_t* shared_data,
                       const mtb_ipc_config_t* config)
{
    cy_rslt_t                   result = CY_RSLT_SUCCESS;
    CY_ASSERT(obj != NULL);
    CY_ASSERT(shared_data != NULL);
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(!((config == NULL) ||
                           (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(config->internal_channel_index) ==
                            false) ||
                           (config->semaphore_num > _MTB_IPC_SEMA_COUNT) ||
                           (_mtb_ipc_irq_legal(config->semaphore_irq, config->queue_irq) == false)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((config == NULL) ||
        (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(config->internal_channel_index) == false) ||
        (config->semaphore_num > _MTB_IPC_SEMA_COUNT) ||
        (_mtb_ipc_irq_legal(config->semaphore_irq, config->queue_irq) == false))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // if defined(MTB_IPC_DISABLE_ERR_CHECK)
    obj->internal_channel_index = (uint32_t)config->internal_channel_index;
    IPC_STRUCT_Type* ipc_base =
        Cy_IPC_Drv_GetIpcBaseAddress(obj->internal_channel_index);

    /* INIT_CORE:
     *     Set obj->internal_channel_index data to 0x00
     *     This lets other cores know we are initializing, please wait.
     * OTHER CORE(s) will use the value to wait until INIT_CORE is done with initialization
     */
    if ((cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockAcquire(ipc_base))
    {
        /* Write 0x00 to start */
        Cy_IPC_Drv_WriteDataValue(ipc_base, 0UL);

        /* Release, but do not trigger a release event */
        (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
    }


    /* PDL-level Semaphores initialized, now we define and initialize the MTB IPC-level IPC
       variables */
    if (CY_RSLT_SUCCESS == result)
    {
        (void)memset(shared_data, 0x00, sizeof(mtb_ipc_shared_t));
        obj->ipc_shared_vars  = (mtb_ipc_shared_t*)shared_data;
        _mtb_ipc_initialize_sema_irq(obj, true);
        /* Init the IPC library Semaphore */
        result = _mtb_ipc_sema_inner_init(obj, &obj->internal_ipc_semaphore,
                                          &obj->ipc_shared_vars->ipc_driver_semaphore,
                                          config->semaphore_num, false);
        if (CY_RSLT_SUCCESS == result)
        {
            if ((cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockAcquire(ipc_base))
            {
                /* Provide IRQ data for this core*/
                obj->semaphore_irq = config->semaphore_irq;
                obj->queue_irq = config->queue_irq;
                obj->trigger_mask = _MTB_IPC_TRIGGER_MASK_UNDEFINED;
                obj->ipc_shared_vars->irq_channels[_MTB_IPC_CUR_CORE_IDX].sema_irq =
                    obj->semaphore_irq;
                obj->ipc_shared_vars->irq_channels[_MTB_IPC_CUR_CORE_IDX].queue_irq =
                    obj->queue_irq;
                CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars,
                                                     sizeof(mtb_ipc_shared_t));
                /* Set the actual shared variables value */
                CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1,
                                             'Reviewed: Safe to cast as it is casted back to mtb_ipc_shared_t * when retrieved by other cores.')
                Cy_IPC_Drv_WriteDataValue(ipc_base, (uint32_t)obj->ipc_shared_vars);
                CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4')

                /* Release, but do not trigger a release event */
                    (void) Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
            }
        }
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_reinit_hw
// * Reinitialized the hardware on the init core in case the secondary core(s) was/were reset
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_reinit_hw(const mtb_ipc_t* obj)
{
    CY_ASSERT(obj != NULL);

    IPC_STRUCT_Type* ipc_base =
        Cy_IPC_Drv_GetIpcBaseAddress(obj->internal_channel_index);

    if ((cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockAcquire(ipc_base))
    {
        CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1,
                                     'Reviewed: Cast back is safe, it is cast from mtb_ipc_shared_t * to uint32_t.')
        /* Set the shared variables value again to sync initialization */
        Cy_IPC_Drv_WriteDataValue(ipc_base, (uint32_t)obj->ipc_shared_vars);
        CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4')

        /* Release, but do not trigger a release event */
            (void) Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);

        return CY_RSLT_SUCCESS;
    }
    else
    {
        return MTB_IPC_RSLT_ERR_NOT_INITIALIZED;
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_get_handle
// * Gets already initialized information from the init core and assigns it to a pointer on this
// core
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_get_handle(mtb_ipc_t* obj, const mtb_ipc_config_t* config, uint64_t timeout_ms)
{
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(!((obj == NULL) || (config == NULL) || (shared_data == NULL) ||
                           (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(config->internal_channel_index) ==
                            false) ||
                           (config->semaphore_num > _MTB_IPC_SEMA_COUNT) ||
                           (_mtb_ipc_irq_legal(config->semaphore_irq, config->queue_irq) == false)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((obj == NULL) || (config == NULL) ||
        (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(config->internal_channel_index) == false) ||
        (config->semaphore_num > _MTB_IPC_SEMA_COUNT) ||
        (_mtb_ipc_irq_legal(config->semaphore_irq, config->queue_irq) == false))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // if defined(MTB_IPC_DISABLE_ERR_CHECK)
    cy_rslt_t                   result = CY_RSLT_SUCCESS;
    obj->internal_channel_index = (uint32_t)config->internal_channel_index;
    IPC_STRUCT_Type* ipc_base =
        Cy_IPC_Drv_GetIpcBaseAddress(obj->internal_channel_index);

    uint64_t timeout = timeout_ms;

    /* PDL-level Semaphores initialized, now we define and initialize the MTB IPC-level IPC
       variables */
    if (CY_RSLT_SUCCESS == result)
    {
        /* Other Core(s) wait for the INIT_CORE to set the Cy_IPC_Drv_ReadDataValue(ipc_base) to be
           non-0x00 */
        uint32_t init_state_shared_vars = 0UL;
        do
        {
            if ((cy_en_ipcdrv_status_t)CY_IPC_DRV_SUCCESS == Cy_IPC_Drv_LockAcquire(ipc_base))
            {
                /* read the obj->ipc_shared_vars value from the IPC */
                init_state_shared_vars = Cy_IPC_Drv_ReadDataValue(ipc_base);

                /* Release, but do not trigger a release event */
                (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
            }
            mtb_hal_system_delay_us(_MTB_IPC_US_PER_MS);

            if (timeout != MTB_IPC_NEVER_TIMEOUT)
            {
                timeout--;
            }
        } while ((init_state_shared_vars == 0UL) && (timeout > 0UL));

        if (timeout == 0UL)
        {
            result = MTB_IPC_RSLT_ERR_TIMEOUT;
        }

        if (CY_RSLT_SUCCESS == result)
        {
            /* Getting shared memory memory pointer to the first element of queues linked list */
            CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.4', 1,
                                         'Reviewed: Cast back is safe, it is originally cast from mtb_ipc_shared_t * to uint32_t.')
            obj->ipc_shared_vars = (mtb_ipc_shared_t*)init_state_shared_vars;
            CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.4')
            obj->internal_ipc_semaphore.instance = obj;
            obj->internal_ipc_semaphore.sema_obj = &obj->ipc_shared_vars->ipc_driver_semaphore;
            obj->trigger_mask = _MTB_IPC_TRIGGER_MASK_UNDEFINED;
            obj->semaphore_irq = config->semaphore_irq;
            obj->queue_irq = config->queue_irq;
        }
        result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_ms);
        if (CY_RSLT_SUCCESS == result)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars,
                                                         sizeof(mtb_ipc_shared_t));
            // Check if already used.
            if ((obj->ipc_shared_vars->irq_channels[_MTB_IPC_OTHER_CORE_IDX].sema_irq ==
                 obj->semaphore_irq) ||
                (obj->ipc_shared_vars->irq_channels[_MTB_IPC_OTHER_CORE_IDX].queue_irq ==
                 obj->queue_irq) ||
                (obj->ipc_shared_vars->irq_channels[_MTB_IPC_OTHER_CORE_IDX].sema_irq ==
                 obj->queue_irq) ||
                (obj->ipc_shared_vars->irq_channels[_MTB_IPC_OTHER_CORE_IDX].queue_irq ==
                 obj->semaphore_irq))
            {
                result =  MTB_IPC_RSLT_ERR_INVALID_IRQ_CHANNEL;
            }
            else
            {
                obj->ipc_shared_vars->irq_channels[_MTB_IPC_CUR_CORE_IDX].sema_irq =
                    obj->semaphore_irq;
                obj->ipc_shared_vars->irq_channels[_MTB_IPC_CUR_CORE_IDX].queue_irq =
                    obj->queue_irq;
                CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars->irq_channels,
                                                     _MTB_IPC_MAX_PROCESSES_PER_QUEUE *
                                                     sizeof(_mtb_ipc_core_irq_data));
                _mtb_ipc_initialize_sema_irq(obj, false);
            }
            cy_rslt_t give_result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
            if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
            {
                result = give_result;
            }
        }
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(obj->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
    }


    return result;
}


/**************************************** SEMAPHORE PUBLIC FUNCTIONS
 **************************************************/

/*
 * In the PDL IPC, all the semaphores allocated have been 'initialized' at startup in the "Boot
 * Core" file (or equivalent):
 *  CY8CPROTO-062-4343W system_psoc6_cm0plus.c SystemInit()  Cy_IPC_Sema_Init().
 * In IPC library, we only call Cy_IPC_Sema_Set() or Cy_IPC_Sema_Clear() for the Semaphores.
 * Here we can only check that MTB IPC-level doesn't have a record of it being allocated, and that
 * it isn't currently Set.
 *
 * To find a free MTB IPC-level semaphore number, call
 * _mtb_ipc_check_if_semaphore_allocated(mtb_ipc_t* obj, uint32_t
 * *sema_number)
 */
cy_rslt_t mtb_ipc_semaphore_init(mtb_ipc_t* obj, mtb_ipc_semaphore_t* semaphore,
                                 mtb_ipc_semaphore_data_t* sema_obj,
                                 const mtb_ipc_semaphore_config_t* config)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    CY_ASSERT(obj != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((semaphore != NULL) &&
                          (sema_obj != NULL) &&
                          (config != NULL) &&
                          (config->semaphore_num <= _MTB_IPC_LAST_USER_SEMA_NUM)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((semaphore == NULL) || (sema_obj == NULL) ||
        (config == NULL) || (config->semaphore_num > _MTB_IPC_LAST_USER_SEMA_NUM))
    {
        /* Semaphore index exceeds the number of allowed Semaphores */
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;

    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    /* Grab the PDL Driver Semaphore */
    result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        result = _mtb_ipc_sema_inner_init(obj, semaphore, sema_obj, config->semaphore_num,
                                          config->preemptable);
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
        if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
        {
            result = give_result;
        }
    }

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_semaphore_free
//--------------------------------------------------------------------------------------------------
/** Removes semaphore from linked lists */
void mtb_ipc_semaphore_free(const mtb_ipc_semaphore_t* semaphore)
{
    cy_rslt_t result;
    CY_ASSERT(semaphore != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN_VOID((semaphore->sema_obj != NULL) &&
                              (semaphore->instance ! = NULL));
    #else
    if ((semaphore->sema_obj == NULL) || (semaphore->instance == NULL))
    {
        return; // MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *  return MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    /* Grab the IPC library Semaphore when changing IPC library list of semaphores */
    result = mtb_ipc_semaphore_take(&semaphore->instance->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        /* Free our usage bit */
        if (semaphore->sema_obj->sema_number != _MTB_IPC_UNUSED_SEMAPHORE)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(semaphore->instance->ipc_shared_vars,
                                                         sizeof(mtb_ipc_shared_t));
            /* remove from the linked list */
            mtb_ipc_semaphore_data_t* last = NULL;
            mtb_ipc_semaphore_data_t* walker =
                semaphore->instance->ipc_shared_vars->ipc_semaphore_list;
            while (walker != NULL)
            {
                if (walker->sema_number == semaphore->sema_obj->sema_number)
                {
                    if (walker == semaphore->instance->ipc_shared_vars->ipc_semaphore_list)
                    {
                        /* obj is the first semaphore in the list
                         * point list to the next one.
                         */
                        semaphore->instance->ipc_shared_vars->ipc_semaphore_list =
                            semaphore->instance->ipc_shared_vars->ipc_semaphore_list->next_sema;
                    }
                    else
                    {
                        last->next_sema = walker->next_sema;
                    }
                    break;
                }
                else
                {
                    last = walker;
                    walker = walker->next_sema;
                }
            }
        }
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(semaphore->instance->ipc_shared_vars,
                                             sizeof(mtb_ipc_shared_t));
        /* We are done with the IPC library Semaphore */
        result = mtb_ipc_semaphore_give(&semaphore->instance->internal_ipc_semaphore);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        /* outside of gate for ipc_driver_semaphore
         * Semaphore might be taken, give it before returning.
         */
        cy_rslt_t give_result = mtb_ipc_semaphore_give(semaphore);
        CY_ASSERT(give_result == CY_RSLT_SUCCESS);
        CY_UNUSED_PARAMETER(give_result);
    }
    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    return; // CY_RSLT_SUCCESS;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_semaphore_get_handle
//--------------------------------------------------------------------------------------------------
/** Assigns the passed in semaphore pointer to the relevant already-initialized data in shared
   memory */
cy_rslt_t mtb_ipc_semaphore_get_handle(mtb_ipc_t* obj, mtb_ipc_semaphore_t* semaphore,
                                       uint32_t semaphore_num, uint64_t timeout_us)
{
    cy_rslt_t result = MTB_IPC_RSLT_ERR_NO_SEMA_AVAILABLE;
    CY_ASSERT(obj != NULL);
    CY_ASSERT(semaphore != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN((semaphore_num < _MTB_IPC_SEMA_COUNT),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((semaphore_num > _MTB_IPC_SEMA_COUNT))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     */
    _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(timeout_us);

    result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        result = MTB_IPC_RSLT_ERR_NO_SEMA_AVAILABLE;
        /* Walk the linked list looking for the semaphore number */
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(obj->ipc_shared_vars,
                                                     sizeof(mtb_ipc_shared_t));
        mtb_ipc_semaphore_data_t* walker = obj->ipc_shared_vars->ipc_semaphore_list;
        while (walker != NULL)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(walker,
                                                         sizeof(mtb_ipc_semaphore_data_t));
            if (walker->sema_number == semaphore_num)
            {
                result = CY_RSLT_SUCCESS;
                semaphore->sema_obj = walker;
                semaphore->instance = obj;
                break;
            }
            walker = walker->next_sema;
        }
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
        if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
        {
            result =give_result;
        }
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_semaphore_take
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_semaphore_take(const mtb_ipc_semaphore_t* semaphore,
                                 uint64_t timeout_us)
{
    CY_ASSERT(semaphore != NULL);
    uint64_t timeout = timeout_us;
    return _mtb_ipc_semaphore_take_internal(semaphore, &timeout);
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_semaphore_take_internal
//--------------------------------------------------------------------------------------------------
cy_rslt_t _mtb_ipc_semaphore_take_internal(const mtb_ipc_semaphore_t* semaphore,
                                           uint64_t* timeout_us)
{
    cy_rslt_t               result = MTB_IPC_RSLT_ERR_SEMA_FAIL;
    cy_en_ipcsema_status_t  pdl_ipc_sema_result = CY_IPC_SEMA_LOCKED;


    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((semaphore != NULL) &&
                          (semaphore->instance != NULL) &&
                          (semaphore->sema_obj->sema_number <= _MTB_IPC_LAST_USER_SEMA_NUM)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if (((semaphore == NULL) || (semaphore->instance == NULL) || (semaphore->sema_obj == NULL)) ||
        (semaphore->sema_obj->sema_number > _MTB_IPC_LAST_USER_SEMA_NUM))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }

    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    /* Check if we are executing during an ISR, timeout must be 0x00 */
    _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(*timeout_us);

    /* Debugging - enable at top of this file */
    _MTB_NON_INIT_CORE_PRINTF((
                                  "%ld %s() start, caller:%p, obj->sema_taken(%lu), timeout_us(0x%lx)\n",
                                  __LINE__, __func__, __builtin_return_address(0),
                                  semaphore->sema_obj->sema_taken,
                                  *timeout_us));
    IPC_STRUCT_Type* ipc_base =
        Cy_IPC_Drv_GetIpcBaseAddress(semaphore->instance->internal_channel_index);
    uint32_t semaphore_index = _MTB_IPC_UNUSED_SEMAPHORE;
    bool semaphore_preemptable = false;
    cy_rslt_t lock_result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(
        semaphore->instance->internal_channel_index,
        timeout_us);
    if (lock_result == CY_RSLT_SUCCESS)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(semaphore->sema_obj,
                                                     sizeof(mtb_ipc_semaphore_data_t));
        semaphore_index = semaphore->sema_obj->sema_number;
        semaphore_preemptable = semaphore->sema_obj->sema_preemptable;
        (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
    }
    else
    {
        return result;
    }

    bool     never_timeout = (*timeout_us == MTB_IPC_NEVER_TIMEOUT) ? true : false;

    /* Block busy wait until an interrupt fires to notify that the semaphore was given*/
    IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(
        semaphore->instance->semaphore_irq);
    uint32_t intr_status_masked = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_RELEASE, Cy_IPC_Drv_GetInterruptStatusMasked(
                                               ipc_intr_base));
    uint32_t interruptState;
    uint32_t current_sema_intr_mask = 0UL;
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
    //Attempt to use RTOS if available
    cy_rslt_t rtos_sema_result = CY_RSLT_SUCCESS;
    int32_t rtos_sema_idx = -1;     /* -1 means we did not find an rtos_semaphore */

    /* Only try using rtos sema if we have a chance of getting the PDL semaphore.
     * Since the minimum timeout for rtos semaphore is 1ms, don't use rtos semaphore unless the
     * timeout is > 1000 uSec
     * To ensure that this is not called in an ISR, timeout passed in in interrupt contexts should
     * be 0.
     */
    if ((*timeout_us >= _MTB_IPC_US_PER_MS) &&
        ((pdl_ipc_sema_result == CY_IPC_SEMA_LOCKED) ||
         (pdl_ipc_sema_result == CY_IPC_SEMA_NOT_ACQUIRED)))
    {
        /* Try to use an RTOS semaphore to allow other threads to run */
        interruptState = mtb_hal_system_critical_section_enter();
        /* Internal use channel */
        lock_result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(
            semaphore->instance->internal_channel_index,
            timeout_us);
        if (lock_result == CY_RSLT_SUCCESS)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(semaphore->instance->ipc_shared_vars,
                                                         sizeof(mtb_ipc_shared_t));

            /* find an unused rtos semaphore */
            int8_t first_free = -1;
            for (uint32_t index = 0; index < MTB_IPC_RTOS_SEMA_NUM; index++)
            {
                if (semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[_MTB_IPC_CUR_CORE_IDX][
                        index].sema_idx ==
                    semaphore_index)
                {
                    rtos_sema_idx = index;
                    break;
                }
                else if ((semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[
                              _MTB_IPC_CUR_CORE_IDX][index].sema_idx ==
                          _MTB_IPC_UNUSED_SEMAPHORE) && (first_free == -1))
                {
                    first_free = index;
                }
            }

            //Use the first free semaphore if another is not using it
            if (rtos_sema_idx == -1)
            {
                rtos_sema_idx = first_free;
                semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[_MTB_IPC_CUR_CORE_IDX][
                    rtos_sema_idx].sema_idx = semaphore_index;
            }

            // Increment counter of threads blocking on this semaphore
            semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[_MTB_IPC_CUR_CORE_IDX][
                rtos_sema_idx].active_count++;
            current_sema_intr_mask = 1 << rtos_sema_idx;

            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(semaphore->instance->ipc_shared_vars,
                                                 sizeof(mtb_ipc_shared_t));
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
        mtb_hal_system_critical_section_exit(interruptState);
    }
    #else // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM
    // > 0)

    /* Try to take the PDL semaphore once
     * If we get it, then we don't need to try the RTOS semaphore.
     */

    pdl_ipc_sema_result = Cy_IPC_Sema_Set(semaphore_index, semaphore_preemptable);
    if (pdl_ipc_sema_result == (cy_en_ipcsema_status_t)CY_IPC_SEMA_SUCCESS)
    {
        result = CY_RSLT_SUCCESS;
        /* debugging */
        _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);
        return result;
    }

    bool using_irq_resume = false;
    /* Only try using wait logic if we have a chance of getting the PDL semaphore.
     * To ensure that this is not called in an ISR, timeout passed in in interrupt contexts should
     * be 0.
     */
    if ((*timeout_us > 0ULL) &&
        ((pdl_ipc_sema_result == (cy_en_ipcsema_status_t)CY_IPC_SEMA_LOCKED) ||
         (pdl_ipc_sema_result == (cy_en_ipcsema_status_t)CY_IPC_SEMA_NOT_ACQUIRED)))
    {
        interruptState = mtb_hal_system_critical_section_enter();
        lock_result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(
            semaphore->instance->internal_channel_index,
            timeout_us);
        if (lock_result == CY_RSLT_SUCCESS)
        {
            current_sema_intr_mask = MTB_IPC_SEMAPHORE_WAIT_MASK;
            using_irq_resume = true;
            semaphore->instance->ipc_shared_vars->wait_semaphore_idx[_MTB_IPC_CUR_CORE_IDX] =
                semaphore_index;
            semaphore->instance->wait_semaphore_idx = semaphore_index;
            uint32_t current_mbox_interrupt_mask = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_NOTIFY, Cy_IPC_Drv_GetInterruptMask(
                                                                ipc_intr_base));
            Cy_IPC_Drv_SetInterruptMask(ipc_intr_base, current_sema_intr_mask,
                                        current_mbox_interrupt_mask);
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(semaphore->instance->ipc_shared_vars,
                                                 sizeof(mtb_ipc_shared_t));
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
        mtb_hal_system_critical_section_exit(interruptState);
    }
    #endif \
    // (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)

    if (result != CY_RSLT_SUCCESS)
    {
        bool wait_for_irq = false;
        do
        {
            #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && \
            (MTB_IPC_RTOS_SEMA_NUM > 0)
            if ((rtos_sema_idx >= 0) && (*timeout_us >= _MTB_IPC_US_PER_MS)
                && (pdl_ipc_sema_result != CY_IPC_SEMA_LOCKED))
            {
                uint32_t timeout_ms =
                    (never_timeout == true) ? MTB_IPC_NEVER_TIMEOUT_MS : ((*timeout_us) / 1000);
                interruptState = mtb_hal_system_critical_section_enter();
                uint32_t current_mbox_interrupt_mask = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_NOTIFY, Cy_IPC_Drv_GetInterruptMask(
                                                                    ipc_intr_base));
                /* Enable all possible interrupt bits for rtos sema interrupt.
                 * We set all of the possible bits so that we don't accidentally clear other needed
                 * bits.
                 */
                Cy_IPC_Drv_SetInterruptMask(ipc_intr_base, (1 << MTB_IPC_RTOS_SEMA_NUM) - 1,
                                            current_mbox_interrupt_mask);
                mtb_hal_system_critical_section_exit(interruptState);
                /* We purposely do not add a critical section after this point as it stops the rtos
                   semaphore interrupt from working*/

                /* Get for entire timeout (in ms) until timeout or semaphore is given by
                   other operation */

                uint32_t time_start = 0;
                uint32_t time_end = 0;
                cy_rtos_time_get(&time_start);
                rtos_sema_result = cy_rtos_semaphore_get(
                    &(semaphore->instance->rtos_semaphore_base[rtos_sema_idx]), timeout_ms);
                cy_rtos_time_get(&time_end);
                if (*timeout_us > _MTB_IPC_US_PER_MS * (time_end - time_start))
                {
                    *timeout_us -= _MTB_IPC_US_PER_MS * (time_end - time_start);
                }
                else
                {
                    *timeout_us = *timeout_us % _MTB_IPC_US_PER_MS;
                }
            }
            #endif // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) &&
            // (MTB_IPC_RTOS_SEMA_NUM > 0)
            if (wait_for_irq == false)
            {
                interruptState = mtb_hal_system_critical_section_enter();
                pdl_ipc_sema_result = Cy_IPC_Sema_Set(semaphore_index, semaphore_preemptable);
                switch (pdl_ipc_sema_result)
                {
                    case CY_IPC_SEMA_SUCCESS:
                        result = CY_RSLT_SUCCESS;
                        break;

                    case CY_IPC_SEMA_LOCKED:    /* IPC channel busy or locked,
                                                   wait a bit and try again */
                        result = MTB_IPC_RSLT_ERR_SEMA_FAIL;
                        break;

                    case CY_IPC_SEMA_NOT_ACQUIRED:  /* PDL IPC channel not initialized
                                                       (we init well before getting here)
                                                       -or- Semaphore is already taken */
                        #if !((defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && \
                        (MTB_IPC_RTOS_SEMA_NUM > 0))
                        semaphore->instance->wait_semaphore_idx = semaphore_index;
                        wait_for_irq = true;
                        #endif
                        result = MTB_IPC_RSLT_ERR_SEMA_TAKEN;
                        break;

                    case CY_IPC_SEMA_OUT_OF_RANGE:
                    default:
                        result = MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
                        break;
                }
                mtb_hal_system_critical_section_exit(interruptState);
            }
            else
            {
                Cy_SysLib_DelayUs(1U);
                #if !((defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && \
                (MTB_IPC_RTOS_SEMA_NUM > 0))
                wait_for_irq = (semaphore->instance->wait_semaphore_idx == semaphore_index);
                #endif /* !((defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && \
                          (MTB_IPC_RTOS_SEMA_NUM > 0)) */
            }

            if (*timeout_us > 0ULL)
            {
                *timeout_us -= 1ULL;
            }
        } while (((*timeout_us > 0ULL) || (never_timeout)) &&
                 ((result != CY_RSLT_SUCCESS) && (result != MTB_IPC_RSLT_ERR_INVALID_PARAMETER)));
    }

    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
    if ((rtos_sema_idx >= 0))
    {
        lock_result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(
            semaphore->instance->internal_channel_index,
            timeout_us);
        if (CY_RSLT_SUCCESS == lock_result)
        {
            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(semaphore->instance->ipc_shared_vars,
                                                         sizeof(mtb_ipc_shared_t));

            /* Decrement active threads allocating this rtos semaphore */
            semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[_MTB_IPC_CUR_CORE_IDX][
                rtos_sema_idx].active_count -= 1;

            /* We don't need the rtos semaphore, un-associate it with the semaphore */
            if (semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[_MTB_IPC_CUR_CORE_IDX][
                    rtos_sema_idx].active_count == 0)
            {
                semaphore->instance->ipc_shared_vars->rtos_semaphore_idx[_MTB_IPC_CUR_CORE_IDX][
                    rtos_sema_idx].sema_idx  =
                    _MTB_IPC_UNUSED_SEMAPHORE;
            }
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(semaphore->instance->ipc_shared_vars,
                                                 sizeof(mtb_ipc_shared_t));
            rtos_sema_idx = -1;
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
        else if ((result == CY_RSLT_SUCCESS) && (lock_result != CY_RSLT_SUCCESS))
        {
            result = lock_result;
        }
    }

    /* If IPC semaphore was not successfully got and unexpected result was returned by
       cy_rtos_get_semaphore,
     *  forward the RTOS result to the user. */
    if ((CY_RSLT_SUCCESS != result) &&
        ((CY_RSLT_SUCCESS != rtos_sema_result) && (CY_RTOS_TIMEOUT != rtos_sema_result)))
    {
        result = rtos_sema_result;
    }
    #else // if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM
    // > 0)
    if (using_irq_resume)
    {
        interruptState = mtb_hal_system_critical_section_enter();
        lock_result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(
            semaphore->instance->internal_channel_index,
            timeout_us);
        if (CY_RSLT_SUCCESS == lock_result)
        {
            semaphore->instance->ipc_shared_vars->wait_semaphore_idx[_MTB_IPC_CUR_CORE_IDX] =
                _MTB_IPC_UNUSED_SEMAPHORE;
            semaphore->instance->wait_semaphore_idx = _MTB_IPC_UNUSED_SEMAPHORE;
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(semaphore->instance->ipc_shared_vars,
                                                 sizeof(mtb_ipc_shared_t));
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
        mtb_hal_system_critical_section_exit(interruptState);
    }
    #endif \
    /* (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0) */

    /* update the interrupt status masked, clear if used */
    interruptState = mtb_hal_system_critical_section_enter();
    intr_status_masked = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_RELEASE, Cy_IPC_Drv_GetInterruptStatusMasked(
                                      ipc_intr_base));
    uint32_t current_mbox_interrupt_mask = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_NOTIFY, Cy_IPC_Drv_GetInterruptMask(
                                                        ipc_intr_base));
    if ((pdl_ipc_sema_result == (cy_en_ipcsema_status_t)CY_IPC_SEMA_SUCCESS) &&
        (intr_status_masked & current_sema_intr_mask))
    {
        /* If semaphore get was successful and interrupt was not cleared by IRQ handler (e.g.
           interrupts are disabled),
         *   clear pending interrupt, that is related to this semaphore number */
        Cy_IPC_Drv_ClearInterrupt(ipc_intr_base, current_sema_intr_mask,
                                  current_mbox_interrupt_mask);
    }
    mtb_hal_system_critical_section_exit(interruptState);

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);
    _MTB_NON_INIT_CORE_PRINTF(("%ld %s() end, caller:%p, obj->sema_taken(%lu)\n",
                               __LINE__, __func__, __builtin_return_address(0),
                               semaphore->sema_obj->sema_taken));
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_semaphore_give
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_semaphore_give(const mtb_ipc_semaphore_t* semaphore)
{
    CY_ASSERT(semaphore != NULL);

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    cy_rslt_t result = MTB_IPC_RSLT_ERR_SEMA_FAIL;
    cy_en_ipcsema_status_t pdl_ipc_sema_result = CY_IPC_SEMA_LOCKED;

    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((semaphore->instance != NULL) &&
                          (semaphore->sema_obj->sema_number < _MTB_IPC_LAST_USER_SEMA_NUM)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if (((semaphore->instance == NULL) ||
         (semaphore->sema_obj == NULL)) ||
        (semaphore->sema_obj->sema_number > _MTB_IPC_LAST_USER_SEMA_NUM))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    /* Check if we are executing during an ISR, timeout must be 0x00 */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    IPC_STRUCT_Type* ipc_base =
        Cy_IPC_Drv_GetIpcBaseAddress(semaphore->instance->internal_channel_index);
    uint32_t semaphore_index = _MTB_IPC_UNUSED_SEMAPHORE;
    bool semaphore_preemptable = false;
    cy_rslt_t lock_result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(
        semaphore->instance->internal_channel_index,
        &timeout_us);
    if (lock_result == CY_RSLT_SUCCESS)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(semaphore->sema_obj,
                                                     sizeof(mtb_ipc_semaphore_data_t));
        semaphore_index = semaphore->sema_obj->sema_number;
        semaphore_preemptable = semaphore->sema_obj->sema_preemptable;
        (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
    }
    else
    {
        return result;
    }

    do
    {
        pdl_ipc_sema_result = Cy_IPC_Sema_Clear(semaphore_index, semaphore_preemptable);

        switch (pdl_ipc_sema_result)
        {
            case CY_IPC_SEMA_SUCCESS:
                result = CY_RSLT_SUCCESS;
                break;

            case CY_IPC_SEMA_LOCKED: /* IPC channel busy or locked, wait a bit and try again */
                result = MTB_IPC_RSLT_ERR_SEMA_FAIL;
                break;

            case CY_IPC_SEMA_NOT_ACQUIRED:
                result = CY_RSLT_SUCCESS; /* We allow for semaphore give multiple times, like in an
                                             RTOS */
                break;

            case CY_IPC_SEMA_OUT_OF_RANGE:
                result = MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
                break;

            /* Other codes not returned by PDL IPC Semaphore Clear */
            default:
                result = MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
                break;
        }

        if (result != CY_RSLT_SUCCESS)
        {
            if (timeout_us > 1u)
            {
                mtb_hal_system_delay_us(1u);
                timeout_us -= 1u;
            }
            else
            {
                timeout_us  = 0ULL;
            }
        }
    } while  ((result != CY_RSLT_SUCCESS) && (timeout_us > 0ULL));


    //Delay 1us to allow taking in the case of a busy poll for the semaphore
    mtb_hal_system_delay_us(1U);
    if ((cy_en_ipcsema_status_t)CY_IPC_SEMA_SUCCESS == pdl_ipc_sema_result)
    {
        result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(semaphore->instance->internal_channel_index,
                                                       &timeout_us);
        if (result == CY_RSLT_SUCCESS)
        {
            /* we actually cleared the PDL semaphore, trigger IRQ */
            for (uint32_t core_num = 0UL; core_num < _MTB_IPC_CORE_NUM; core_num++)
            {
                INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
                    semaphore->instance->ipc_shared_vars, sizeof(mtb_ipc_shared_t));

                /* Check that the IRQ channels have been correctly configured for the cores
                   so that means that on the init core mtb_ipc_init has been called and on the
                   non init core mtb_ipc_get_handle has been called. If not, do not trigger
                   interrupts on that core as it would not have valid and dedicated irq structures
                 */
                if ((semaphore->instance->ipc_shared_vars->irq_channels[core_num].sema_irq !=
                     semaphore->instance->ipc_shared_vars->irq_channels[core_num].queue_irq))
                {
                    IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(
                        semaphore->instance->ipc_shared_vars->irq_channels[core_num].sema_irq);

                    Cy_IPC_Drv_SetInterrupt(ipc_intr_base,
                                            (uint32_t)((1 << MTB_IPC_RTOS_SEMA_NUM) -1), 0UL);
                }
            }

            INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
                semaphore->instance->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
            if (semaphore->instance->ipc_shared_vars->wait_semaphore_idx[_MTB_IPC_OTHER_CORE_IDX] ==
                semaphore_index)
            {
                IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(
                    semaphore->instance->ipc_shared_vars->irq_channels[_MTB_IPC_OTHER_CORE_IDX].sema_irq);

                Cy_IPC_Drv_SetInterrupt(ipc_intr_base, MTB_IPC_SEMAPHORE_WAIT_MASK, 0UL);
            }

            /* Release, but do not trigger a release event */
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
    }

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);
    _MTB_NON_INIT_CORE_PRINTF(("%ld %s() end, caller:%p, obj->sema_taken(%lu)\n",
                               __LINE__, __func__, __builtin_return_address(0),
                               semaphore->sema_obj->sema_taken));
    return result;
}


/***************************************** QUEUES PUBLIC FUNCTIONS
 ****************************************************/
cy_rslt_t mtb_ipc_queue_init(mtb_ipc_t* obj, mtb_ipc_queue_t* queue,
                             mtb_ipc_queue_data_t* queue_obj, const mtb_ipc_queue_config_t* config)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(queue != NULL);
    CY_ASSERT(queue_obj != NULL);
    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* Validate args */
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((config != NULL) &&
                          (config->semaphore_num < _MTB_IPC_SEMA_COUNT)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((config == NULL) || (config->semaphore_num > _MTB_IPC_SEMA_COUNT))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *  return MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    /*
     * Validate user-filled fields in queue structure
     * * queue is in local Memory
     * * queue_obj is in Shared Memory
     * * queue_pool is in Shared Memory
     * * 0 <= channel_num < MTB_IPC_USR_CHANNELS
     * * obj->ipc_shared_vars->ipc_queue_array[ _MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(channel_num) ][
     * queue_num ] == NULL
     * * obj->ipc_shared_vars->ipc_queue_array[channel_num][queue_num]
     *
     */
    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue_obj, sizeof(mtb_ipc_queue_data_t));

    if ((config->queue_pool == NULL) ||
        (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE((uint32_t)config->channel_num) == false) ||
        (config->max_num_items == 0UL) ||
        (config->item_size == 0UL) ||
        ((uint32_t)config->channel_num == obj->internal_channel_index))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }

    /* Initialize Caller's Object to store queue ptr
     * The caller always uses the obj ptr from now on.
     * They must not alter the data in queue_handle either!
     */

    /* initialize the Queue's Semaphore */
    result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        /* Check if Queue index has already been used */
        if (_mtb_ipc_queue_array_get_pointer(obj, (uint32_t)config->channel_num,
                                             config->queue_num) != NULL)
        {
            result = MTB_IPC_RSLT_ERR_QUEUE_NUM_IN_USE;
        }
        else
        {
            result = _mtb_ipc_sema_inner_init(obj, &queue->semaphore_handle,
                                              &queue_obj->queue_semaphore, config->semaphore_num,
                                              false);
            // we already have the driver semaphore
            if (CY_RSLT_SUCCESS == result)
            {
                queue_obj->queue_pool = config->queue_pool;
                queue_obj->channel_num = (uint32_t)config->channel_num;
                queue_obj->queue_num = config->queue_num;

                queue_obj->max_num_items = config->max_num_items;
                queue_obj->item_size = config->item_size;
                /* Initialize other Queue info */
                queue_obj->curr_items = 0UL;
                queue_obj->first_item = 0UL;

                //Local data
                queue->events_fired = (uint32_t)MTB_IPC_NO_INTR;
                queue->pending_reads = 0U;
                queue->pending_writes = 0U;

                for (uint32_t i = 0UL; i < _MTB_IPC_MAX_PROCESSES_PER_QUEUE; i++)
                {
                    queue_obj->notifications[i].mask = (uint32_t)MTB_IPC_NO_INTR;
                    queue_obj->notifications[i].flags = (uint32_t)MTB_IPC_NO_INTR;
                }
                queue->queue_obj = (void*)queue_obj;
                result = _mtb_ipc_queue_array_set_pointer(obj, queue_obj->channel_num,
                                                          queue_obj->queue_num,
                                                          queue_obj);
                if (CY_RSLT_SUCCESS == result)
                {
                    //Only locally set if we were able to set in shared memory
                    result = _mtb_ipc_queue_array_set_local(obj, queue_obj->channel_num,
                                                            queue_obj->queue_num,
                                                            queue);
                    queue->instance = obj;
                }

                #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
                //Enable RTOS event handler
                (void)cy_rtos_event_init(&queue->queue_rtos_event);
                #endif
            }
        }
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
        if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
        {
            result =give_result;
        }
    }

    CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue_obj, sizeof(mtb_ipc_queue_data_t));

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    return result;
}


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1,
                             'const qualifier is dropped later in call to cy_rtos_event_deinit')
//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_free
//--------------------------------------------------------------------------------------------------
void mtb_ipc_queue_free(mtb_ipc_queue_t* queue)
{
    CY_ASSERT(queue != NULL);
    cy_rslt_t result = CY_RSLT_SUCCESS;

    CY_ASSERT_AND_RETURN_VOID(((queue->instance != NULL) &&
                               (queue->queue_obj != NULL)));

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *   MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue->queue_obj, sizeof(mtb_ipc_queue_data_t));
    mtb_ipc_t* obj = queue->instance;
    uint32_t channel_num = queue->queue_obj->channel_num;
    uint32_t queue_num = queue->queue_obj->queue_num;
    cy_rslt_t sem_take = CY_RSLT_SUCCESS;
    sem_take = mtb_ipc_semaphore_take(&(obj->internal_ipc_semaphore), timeout_us);
    if (CY_RSLT_SUCCESS == sem_take)
    {
        if (_mtb_ipc_queue_array_get_pointer(obj, channel_num, queue_num) != queue->queue_obj)
        {
            result = MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND;
        }
        else
        {
            result = _mtb_ipc_queue_array_set_pointer(obj, channel_num, queue_num, NULL);
            if (CY_RSLT_SUCCESS == result)
            {
                result = _mtb_ipc_queue_array_set_local(obj, channel_num, queue_num, NULL);
            }
        }
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
        if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
        {
            result =give_result;
        }
    }
    if ((CY_RSLT_SUCCESS == result) && (sem_take == CY_RSLT_SUCCESS))
    {
        result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(channel_num, &timeout_us);
        if (CY_RSLT_SUCCESS == result)
        {
            /* release any notifications in the queue */
            uint32_t i;
            for (i = 0UL; i < _MTB_IPC_MAX_PROCESSES_PER_QUEUE; i++)
            {
                queue->queue_obj->notifications[i].mask = (uint32_t)MTB_IPC_NO_INTR;
                queue->queue_obj->notifications[i].flags = (uint32_t)MTB_IPC_NO_INTR;
            }
            IPC_STRUCT_Type* ipc_base =
                Cy_IPC_Drv_GetIpcBaseAddress(channel_num);
            (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
        }
        mtb_ipc_semaphore_free(&queue->semaphore_handle);
        #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
        (void)cy_rtos_event_deinit(&queue->queue_rtos_event);
        #endif
    }

    CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj, sizeof(mtb_ipc_queue_data_t));

    return; // result;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_get_handle
//--------------------------------------------------------------------------------------------------
/** Gets the queue data that is already initialized for use in functions on this core */
cy_rslt_t mtb_ipc_queue_get_handle(mtb_ipc_t* obj, mtb_ipc_queue_t* queue, uint32_t channel_num,
                                   uint32_t queue_num)
{
    CY_ASSERT(obj != NULL);
    CY_ASSERT(queue != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if  defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN((_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel_num) == true)
                         , MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    /* Queue IPC channel number check */
    if ((_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel_num) == false))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *   MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);


    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_ipc_queue_data_t* queue_obj = NULL;
    result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        queue_obj = _mtb_ipc_queue_array_get_pointer(obj, channel_num, queue_num);
        // Should never fail, so should assert on failure
        result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
    }
    if ((queue != NULL) && (queue_obj != NULL) && (result == CY_RSLT_SUCCESS))
    {
        queue->queue_obj = queue_obj;
        queue->instance = obj;
        queue->events_fired = (uint32_t)MTB_IPC_NO_INTR;
        queue->pending_reads = 0U;
        queue->pending_writes = 0U;
        result = _mtb_ipc_queue_array_set_local(obj, channel_num, queue_num, queue);
        if (result == CY_RSLT_SUCCESS)
        {
            uint64_t timeout = _MTB_IPC_SERVICE_SEMA_TIMEOUT_US;
            _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout);
            result =  mtb_ipc_semaphore_get_handle(obj, &queue->semaphore_handle,
                                                   queue_obj->queue_semaphore.sema_number,
                                                   timeout);
            #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
            (void)cy_rtos_event_init(&queue->queue_rtos_event);
            #endif
        }
    }
    else
    {
        result =  MTB_IPC_RSLT_ERR_QUEUE_NOT_FOUND;
    }
    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_ipc_queue_register_callback(mtb_ipc_queue_t* queue,
                                     mtb_ipc_queue_event_callback_t callback, void* callback_arg)
{
    /* reduce code and execution time if tested thoroughly */
    CY_ASSERT(queue != NULL);
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN_VOID(((queue->instance != NULL) &&
                               (queue->queue_obj != NULL)));
    #else
    if ((queue->instance == NULL) || (queue->queue_obj == NULL))
    {
        return;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    #if defined(MTB_IPC_MULTI_PROCESS_PER_QUEUE)
    #error "Code needed for Multiple Processes per Queue"
    #endif

    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.1', 1,
                                 'Reviewed: Cast is safe, it is cast back to original type when used.')
    queue->callback_data.callback  = (cy_israddress)callback;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.1')
    queue->callback_data.callback_arg = callback_arg;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_enable_event
//--------------------------------------------------------------------------------------------------
/** Enable events for interrupt functionality */
void mtb_ipc_queue_enable_event(mtb_ipc_queue_t* queue, mtb_ipc_queue_event_t event,
                                bool enable)
{
    CY_ASSERT(queue != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN_VOID(((queue->instance != NULL) &&
                               (queue->queue_obj != NULL)));
    #else
    if ((queue->instance == NULL) || (queue->queue_obj == NULL))
    {
        return;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)


    cy_rslt_t   result = CY_RSLT_SUCCESS;

    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue->queue_obj, sizeof(mtb_ipc_queue_data_t));

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *  return MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    uint32_t channel_num = queue->queue_obj->channel_num;
    uint32_t process_number = _MTB_IPC_CUR_CORE_IDX;
    #if defined(MTB_IPC_MULTI_PROCESS_PER_QUEUE)
    #error "Code needed for Multiple Processes per Queue"
    #endif

    mtb_ipc_queue_event_t events_enabled = MTB_IPC_NO_INTR;
    result = (cy_rslt_t)_mtb_ipc_lock_with_timeout(channel_num, &timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        if (enable == true)
        {
            queue->queue_obj->notifications[process_number].mask |= (uint32_t)event;
            queue->events_enabled |= (uint32_t)event;
        }
        else
        {
            queue->queue_obj->notifications[process_number].mask &= ~(uint32_t)event;
            queue->events_enabled &= ~(uint32_t)event;
        }
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue->queue_obj->notifications,
                                             _MTB_IPC_MAX_PROCESSES_PER_QUEUE *
                                             sizeof(_mtb_ipc_queue_process_info_t));

        /* Go through the events for this channel and see if we have events to trigger the interrupt
         */
        events_enabled =
            _mtb_ipc_queue_all_events_enabled(queue->instance, channel_num);
        IPC_STRUCT_Type* ipc_base =
            Cy_IPC_Drv_GetIpcBaseAddress(channel_num);
        (void)Cy_IPC_Drv_LockRelease(ipc_base, CY_IPC_NO_NOTIFICATION);
    }
    if (CY_RSLT_SUCCESS == result)
    {
        /* All channel-related queues have no events enabled, disabling interrupts */
        if (events_enabled == (mtb_ipc_queue_event_t)MTB_IPC_NO_INTR)
        {
            (void)_mtb_ipc_enable_channel_interrupt(queue->instance, channel_num,
                                                    false, &timeout_us);
        }
        else if ((CY_RSLT_SUCCESS == result) &&
                 (_MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel_num) == true) &&
                 (events_enabled != (mtb_ipc_queue_event_t)MTB_IPC_NO_INTR))
        {
            (void)_mtb_ipc_enable_channel_interrupt(queue->instance, channel_num,
                                                    true, &timeout_us);
        }
    }

    return;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_put
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_queue_put(mtb_ipc_queue_t* queue, void* msg, uint64_t timeout_us)
{
    /* reduce code and execution time if tested thoroughly */
    CY_ASSERT(queue != NULL);
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((queue->instance != NULL) && (msg != NULL) &&
                          (queue->queue_obj != NULL)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((queue->instance == NULL) || (msg == NULL) || (queue->queue_obj == NULL))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     */
    _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(timeout_us);

    return _mtb_ipc_queue_put_get(queue, msg, timeout_us, true);
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_get
//--------------------------------------------------------------------------------------------------
/** Read data from the queue */
cy_rslt_t mtb_ipc_queue_get(mtb_ipc_queue_t* queue, void* msg, uint64_t timeout_us)
{
    /* reduce code and execution time if tested thoroughly */
    CY_ASSERT(queue != NULL);
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((queue->instance != NULL) && (msg != NULL) &&
                          (queue->queue_obj != NULL)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((queue->instance == NULL) || (msg == NULL) || (queue->queue_obj == NULL))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif //defined(MTB_IPC_DISABLE_ERR_CHECK)

    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     */
    _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(timeout_us);

    return _mtb_ipc_queue_put_get(queue, msg, timeout_us, false);
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_count
//--------------------------------------------------------------------------------------------------
/** Returns current count of items */
uint32_t mtb_ipc_queue_count(const mtb_ipc_queue_t* queue)
{
    uint32_t max_num_items = 0UL;
    CY_ASSERT(queue != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(
        ((queue->instance != NULL) && (queue->queue_obj != NULL)),
        MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((queue == NULL) || (queue->instance == NULL) || (queue->queue_obj == NULL))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = _MTB_IPC_SERVICE_SEMA_TIMEOUT_US;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *  return MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    if (queue->queue_obj != NULL)
    {
        mtb_ipc_queue_data_t* queue_obj = (mtb_ipc_queue_data_t*)(queue->queue_obj);

        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue_obj, sizeof(mtb_ipc_queue_data_t));

        max_num_items = queue_obj->curr_items;
    }
    return max_num_items;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_queue_reset
//--------------------------------------------------------------------------------------------------
/** Resets the queue but does not de-initialize */
cy_rslt_t mtb_ipc_queue_reset(const mtb_ipc_queue_t* queue)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    CY_ASSERT(queue != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(
        ((queue->instance != NULL) && (queue->queue_obj != NULL)),
        MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((queue->instance == NULL) || (queue->queue_obj == NULL))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = _MTB_IPC_SERVICE_SEMA_TIMEOUT_US;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *  return MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    if (queue->queue_obj != NULL)
    {
        mtb_ipc_queue_data_t* queue_obj = (mtb_ipc_queue_data_t*)(queue->queue_obj);

        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(queue_obj, sizeof(mtb_ipc_queue_data_t));

        result = mtb_ipc_semaphore_take(&queue->semaphore_handle, timeout_us);
        if (CY_RSLT_SUCCESS == result)
        {
            queue_obj->first_item = 0UL;
            queue_obj->curr_items = 0UL;

            for (uint32_t i = 0UL; i < _MTB_IPC_MAX_PROCESSES_PER_QUEUE; i++)
            {
                // Trigger events MTB_IPC_QUEUE_RESET & MTB_IPC_QUEUE_EMPTY
                queue_obj->notifications[i].flags |= queue_obj->notifications[i].mask &
                                                     (uint32_t)MTB_IPC_QUEUE_RESET;
                queue_obj->notifications[i].flags |= queue_obj->notifications[i].mask &
                                                     (uint32_t)MTB_IPC_QUEUE_EMPTY;
            }
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(queue_obj, sizeof(mtb_ipc_queue_data_t));

            _mtb_ipc_trigger_interrupts_for_channel(queue->instance, queue_obj->channel_num,
                                                    &timeout_us);

            cy_rslt_t  give_result = mtb_ipc_semaphore_give(&queue->semaphore_handle);
            if ((give_result != CY_RSLT_SUCCESS) && (result == CY_RSLT_SUCCESS))
            {
                result = give_result;
            }
        }
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_receiver_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_mbox_receiver_init(mtb_ipc_t* obj, mtb_ipc_mbox_receiver_t* receiver,
                                     mtb_ipc_mbox_data_t* mbox_obj,
                                     const mtb_ipc_mbox_config_t* config)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    CY_ASSERT(obj != NULL);
    CY_ASSERT(receiver != NULL);
    CY_ASSERT(mbox_obj != NULL);
    /* Validate args */
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((config->write_semaphore_num < _MTB_IPC_SEMA_COUNT) &&
                          (config->read_semaphore_num < _MTB_IPC_SEMA_COUNT) &&
                          (config->mailbox_idx < MTB_IPC_MAX_MBOXES) &&
                          (config->read_semaphore_num != config->write_semaphore_num)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((config->write_semaphore_num >= _MTB_IPC_SEMA_COUNT) ||
        (config->read_semaphore_num >= _MTB_IPC_SEMA_COUNT) ||
        (config->mailbox_idx >= MTB_IPC_MAX_MBOXES) ||
        (config->read_semaphore_num == config->write_semaphore_num))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Should not be called in an ISR*/
    _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(timeout_us);


    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(mbox_obj, sizeof(mtb_ipc_mbox_data_t));


    /* Initialize Caller's Object to store mailbox ptr
     * The caller always uses the obj ptr from now on.
     * They must not alter the data in mailbox data either!
     */

    /* initialize the Mailboxes's Semaphores */
    result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        /* Check if mailbox index has already been used */
        if (obj->ipc_shared_vars->ipc_mailbox_array[config->mailbox_idx] != NULL)
        {
            result = MTB_IPC_RSLT_ERR_MBOX_IDX_IN_USE;
        }
        else
        {
            (void)memset(mbox_obj, 0x00, sizeof(mtb_ipc_mbox_data_t));
            receiver->mbox_obj = mbox_obj;
            receiver->instance = obj;

            result = _mtb_ipc_sema_inner_init(obj, &receiver->sema_read_handle,
                                              &mbox_obj->sema_read, config->read_semaphore_num,
                                              false);
            if (CY_RSLT_SUCCESS == result)
            {
                result = _mtb_ipc_sema_inner_init(obj, &receiver->sema_write_handle,
                                                  &mbox_obj->sema_write,
                                                  config->write_semaphore_num,
                                                  false);
                if (CY_RSLT_SUCCESS == result)
                {
                    //Take read semaphore to start
                    result = mtb_ipc_semaphore_take(&receiver->sema_read_handle, timeout_us);
                    if (CY_RSLT_SUCCESS == result)
                    {
                        //Set up mailbox
                        receiver->mbox_obj->mbox_idx = config->mailbox_idx;
                        receiver->mbox_obj->core_id_receiver = _MTB_IPC_CUR_CORE_IDX;
                        obj->ipc_shared_vars->ipc_mailbox_array[config->mailbox_idx] = mbox_obj;
                        obj->mbox_array[config->mailbox_idx] = receiver;
                    }
                    else
                    {
                        receiver->mbox_obj = NULL;
                        receiver->instance = NULL;
                        receiver->sema_write_handle.instance = NULL;
                        receiver->sema_read_handle.instance = NULL;
                        mtb_ipc_semaphore_free(&receiver->sema_write_handle);
                        mtb_ipc_semaphore_free(&receiver->sema_read_handle);
                    }
                }
                else
                {
                    mtb_ipc_semaphore_free(&receiver->sema_read_handle);
                }
            }
        }
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
        if ((result == CY_RSLT_SUCCESS) && (give_result != CY_RSLT_SUCCESS))
        {
            result = give_result;
        }
    }

    CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(mbox_obj, sizeof(mtb_ipc_mbox_data_t));

    /* debugging */
    _mtb_ipc_semaphore_validate_status_with_PDL(__LINE__, __func__);

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_sender_get_handle
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_mbox_sender_get_handle(mtb_ipc_t* obj, mtb_ipc_mbox_sender_t* sender,
                                         uint32_t mbox_idx)
{
    /* reduce code and execution time if tested thoroughly */
    /* Validate args */
    CY_ASSERT(obj != NULL);
    CY_ASSERT(sender != NULL);
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN((mbox_idx < MTB_IPC_MAX_MBOXES),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((mbox_idx >= MTB_IPC_MAX_MBOXES))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    cy_rslt_t result = CY_RSLT_SUCCESS;

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;

    /** THis function cannot be called in an ISR */
    _MTB_IPC_CHECK_TIMEOUT_AND_RETURN_IF_IN_ISR(timeout_us);

    mtb_ipc_mbox_data_t* mbox_obj = NULL;
    result = mtb_ipc_semaphore_take(&obj->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == result)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
            sender->instance->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
        mbox_obj = obj->ipc_shared_vars->ipc_mailbox_array[mbox_idx];
        result = mtb_ipc_semaphore_give(&obj->internal_ipc_semaphore);
    }
    if (CY_RSLT_SUCCESS == result)
    {
        if (mbox_obj == NULL)
        {
            result = MTB_IPC_RSLT_ERR_MBOX_NOT_FOUND;
        }
        else
        {
            result =  mtb_ipc_semaphore_get_handle(obj, &sender->sema_read_handle,
                                                   mbox_obj->sema_read.sema_number,
                                                   timeout_us);
            if (CY_RSLT_SUCCESS == result)
            {
                result =  mtb_ipc_semaphore_get_handle(obj, &sender->sema_write_handle,
                                                       mbox_obj->sema_write.sema_number,
                                                       timeout_us);
            }
            if (result != CY_RSLT_SUCCESS)
            {
                //One or both handles were not got successfully, unset
                (void)memset(&sender->sema_write_handle, 0x00, sizeof(mtb_ipc_semaphore_t));
                (void)memset(&sender->sema_read_handle, 0x00, sizeof(mtb_ipc_semaphore_t));
            }
            else
            {
                result = CY_RSLT_SUCCESS;
                obj->mbox_array[mbox_idx] = sender;
                sender->mbox_obj = mbox_obj;
                sender->instance = obj;
            }
        }
    }

    return result;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_receiver_free
//--------------------------------------------------------------------------------------------------
void mtb_ipc_mbox_receiver_free(mtb_ipc_mbox_receiver_t* receiver)
{
    /* Validate args */
    CY_ASSERT_AND_RETURN_VOID(((receiver != NULL) && (receiver->instance != NULL)));

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *   MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);


    cy_rslt_t sem_take = CY_RSLT_SUCCESS;
    const mtb_ipc_mbox_data_t* mbox_obj = NULL;
    sem_take = mtb_ipc_semaphore_take(&receiver->instance->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == sem_take)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
            receiver->instance->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
        mbox_obj =
            receiver->instance->ipc_shared_vars->ipc_mailbox_array[receiver->mbox_obj->mbox_idx];
        //We check if this handle points to the same mailbox for the index in the shared array
        // If they are not equal, it was already freed.
        CY_ASSERT(mbox_obj == receiver->mbox_obj);
        if ((mbox_obj != NULL))
        {
            receiver->instance->ipc_shared_vars->ipc_mailbox_array[receiver->mbox_obj->mbox_idx] =
                NULL;
            receiver->instance->mbox_array[receiver->mbox_obj->mbox_idx] = NULL;
            CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(receiver->instance->ipc_shared_vars,
                                                 sizeof(mtb_ipc_shared_t));
        }

        //We don't expect this to fail
        cy_rslt_t give_result =
            mtb_ipc_semaphore_give(&receiver->instance->internal_ipc_semaphore);
        CY_ASSERT(CY_RSLT_SUCCESS == give_result);
        CY_UNUSED_PARAMETER(give_result);
        // Disconnect from IPC instance
        receiver->instance = NULL;

        mtb_ipc_semaphore_free(&receiver->sema_read_handle);
        mtb_ipc_semaphore_free(&receiver->sema_write_handle);
    }
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_sender_free
//--------------------------------------------------------------------------------------------------
void mtb_ipc_mbox_sender_free(mtb_ipc_mbox_sender_t* sender)
{
    /* Validate args */
    CY_ASSERT_AND_RETURN_VOID((sender != NULL) && (sender->instance != NULL));

    uint64_t timeout_us = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *   MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout_us);

    cy_rslt_t sem_take = CY_RSLT_SUCCESS;
    sem_take = mtb_ipc_semaphore_take(&sender->instance->internal_ipc_semaphore, timeout_us);
    if (CY_RSLT_SUCCESS == sem_take)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(sender->mbox_obj,
                                                     sizeof(mtb_ipc_mbox_data_t))
        sender->instance->mbox_array[sender->mbox_obj->mbox_idx] = NULL;
        sender->mbox_obj = NULL;

        //We don't expect this to fail
        cy_rslt_t give_result =  mtb_ipc_semaphore_give(&sender->instance->internal_ipc_semaphore);
        CY_ASSERT(CY_RSLT_SUCCESS == give_result);
        CY_UNUSED_PARAMETER(give_result);
        // Disconnect IPC instance
        sender->instance = NULL;
    }
}


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_mbox_register_cb
//--------------------------------------------------------------------------------------------------
void _mtb_ipc_mbox_register_cb(mtb_ipc_mbox_t* mbox,
                               mtb_ipc_mbox_event_callback_t callback,
                               void* callback_arg)
{
    /* Validate args */
    CY_ASSERT_AND_RETURN_VOID(((mbox != NULL) && (mbox->instance != NULL)));
    CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 11.1', 1,
                                 'Reviewed: Cast is safe, it is cast back to original type when used.')
    mbox->callback_data.callback  = (cy_israddress)callback;
    CY_MISRA_BLOCK_END('MISRA C-2012 Rule 11.1')
    mbox->callback_data.callback_arg = callback_arg;
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_receiver_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_ipc_mbox_receiver_register_callback(mtb_ipc_mbox_receiver_t* receiver,
                                             mtb_ipc_mbox_event_callback_t callback,
                                             void* callback_arg)
{
    CY_ASSERT(receiver != NULL);
    _mtb_ipc_mbox_register_cb(receiver, callback, callback_arg);
}


//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_sender_register_callback
//--------------------------------------------------------------------------------------------------
void mtb_ipc_mbox_sender_register_callback(mtb_ipc_mbox_sender_t* sender,
                                           mtb_ipc_mbox_event_callback_t callback,
                                           void* callback_arg)
{
    CY_ASSERT(sender != NULL);
    _mtb_ipc_mbox_register_cb(sender, callback, callback_arg);
}


//Helper to fire interrupt
void _mtb_ipc_mbox_signal_other_core(const mtb_ipc_mbox_t* mbox)
{
    CY_ASSERT(mbox != NULL);

    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(mbox->mbox_obj,
                                                 sizeof(mtb_ipc_mbox_data_t))
    //Each mailbox has its own bit
    uint32_t mask = 1UL << mbox->mbox_obj->mbox_idx;

    INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
        mbox->instance->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
    IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(
        mbox->instance->ipc_shared_vars->irq_channels[_MTB_IPC_OTHER_CORE_IDX].sema_irq);
    //We use the semaphore irq's notify bits to avoid using another interrupt.
    Cy_IPC_Drv_SetInterrupt(ipc_intr_base, CY_IPC_NO_NOTIFICATION, mask);
}


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1,
                             'const qualifier is not viable here because of the cast on sender later on')
//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_sender_put
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_mbox_sender_put(mtb_ipc_mbox_sender_t* sender, void* payload,
                                  uint64_t timeout_us)
{
    /* Validate args */
    CY_ASSERT(sender != NULL);
    /* reduce code and execution time if tested thoroughly */
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((payload != NULL) && (sender->instance != NULL)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((payload == NULL) || (sender->instance == NULL))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout = timeout_us;
    cy_rslt_t result = _mtb_ipc_semaphore_take_internal(&sender->sema_write_handle, &timeout);
    if (CY_RSLT_SUCCESS == result)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(sender->mbox_obj,
                                                     sizeof(mtb_ipc_mbox_data_t));
        //Add payload to mailbox
        sender->mbox_obj->payload = payload;
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(sender->mbox_obj, sizeof(mtb_ipc_mbox_data_t));

        //We don't expect this to fail
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&sender->sema_read_handle);
        if (give_result != CY_RSLT_SUCCESS)
        {
            result = give_result;
        }
        else
        {
            _mtb_ipc_mbox_signal_other_core((mtb_ipc_mbox_t*)sender);
        }
    }
    else
    {
        result = MTB_IPC_RSLT_ERR_MBOX_FULL;
    }
    return result;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1,
                             'const qualifier is not viable here because of the cast on receiver later on')
//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_receiver_get
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_ipc_mbox_receiver_get(mtb_ipc_mbox_receiver_t* receiver, void** payload,
                                    uint64_t timeout_us)
{
    /* Validate args */
    /* reduce code and execution time if tested thoroughly */
    CY_ASSERT(receiver != NULL);
    #if defined(MTB_IPC_DISABLE_ERR_CHECK)
    CY_ASSERT_AND_RETURN(((payload != NULL) && (receiver->instance != NULL)),
                         MTB_IPC_RSLT_ERR_INVALID_PARAMETER);
    #else
    if ((payload == NULL) || (receiver->instance == NULL))
    {
        return MTB_IPC_RSLT_ERR_INVALID_PARAMETER;
    }
    #endif // defined(MTB_IPC_DISABLE_ERR_CHECK)

    uint64_t timeout = timeout_us;
    cy_rslt_t result = _mtb_ipc_semaphore_take_internal(&receiver->sema_read_handle, &timeout);
    if (CY_RSLT_SUCCESS == result)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(receiver->mbox_obj,
                                                     sizeof(mtb_ipc_mbox_data_t));
        //Take payload from mailbox
        *payload = receiver->mbox_obj->payload;
        receiver->mbox_obj->payload = NULL;
        CLEAN_DCACHE_AFTER_WRITING_TO_MEMORY(receiver->mbox_obj, sizeof(mtb_ipc_mbox_data_t));
        //We don't expect this to fail
        cy_rslt_t give_result = mtb_ipc_semaphore_give(&receiver->sema_write_handle);
        if (give_result != CY_RSLT_SUCCESS)
        {
            result = give_result;
        }
        else
        {
            _mtb_ipc_mbox_signal_other_core((mtb_ipc_mbox_t*)receiver);
        }
    }
    else
    {
        result = MTB_IPC_RSLT_ERR_MBOX_EMPTY;
    }
    return result;
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')


//--------------------------------------------------------------------------------------------------
// _mtb_ipc_mbox_enable_irq
//--------------------------------------------------------------------------------------------------
void _mtb_ipc_mbox_enable_irq(const mtb_ipc_mbox_t* mbox, bool enable)
{
    cy_rslt_t result;
    CY_ASSERT(mbox != NULL);

    uint64_t timeout = MTB_IPC_NEVER_TIMEOUT;
    /* Check if we are executing during an ISR, timeout must be 0x00
     * If we add the timeout as an argument, this should also check for
     * timeout !=0 and should fail if in ISR context.
     *   MTB_IPC_RSLT_ERR_CANT_OPERATE_IN_ISR_W_TIMEOUT;
     */
    _MTB_IPC_ZERO_TIMEOUT_IF_IN_ISR(timeout);

    uint32_t intr_status = mtb_hal_system_critical_section_enter();
    result = _mtb_ipc_semaphore_take_internal(&mbox->instance->internal_ipc_semaphore, &timeout);
    if (CY_RSLT_SUCCESS == result)
    {
        INVALIDATE_DCACHE_BEFORE_READING_FROM_MEMORY(
            mbox->instance->ipc_shared_vars, sizeof(mtb_ipc_shared_t));
        IPC_INTR_STRUCT_Type* ipc_intr_base = Cy_IPC_Drv_GetIntrBaseAddr(
            mbox->instance->semaphore_irq);
        uint32_t current_mbox_interrupt_mask = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_NOTIFY, Cy_IPC_Drv_GetInterruptMask(
                                                            ipc_intr_base));
        uint32_t mbox_intr_mask = 1UL << mbox->mbox_obj->mbox_idx;
        if (enable)
        {
            //Check that not already enabled
            if ((current_mbox_interrupt_mask & mbox_intr_mask) == 0UL)
            {
                uint32_t semaphore_interrupt_mask = _FLD2VAL(IPC_INTR_STRUCT_INTR_MASKED_RELEASE, Cy_IPC_Drv_GetInterruptMask(
                                                                 ipc_intr_base));
                Cy_IPC_Drv_ClearInterrupt(ipc_intr_base, semaphore_interrupt_mask,
                                          mbox_intr_mask);
                Cy_IPC_Drv_SetInterruptMask(ipc_intr_base, semaphore_interrupt_mask,
                                            current_mbox_interrupt_mask | mbox_intr_mask);
            }
        }
        else
        {
            Cy_IPC_Drv_SetInterruptMask(ipc_intr_base, CY_IPC_NO_NOTIFICATION,
                                        current_mbox_interrupt_mask & ~mbox_intr_mask);
        }
        cy_rslt_t give_result =  mtb_ipc_semaphore_give(&mbox->instance->internal_ipc_semaphore);
        //We don't expect this to fail
        if (give_result != CY_RSLT_SUCCESS)
        {
            CY_ASSERT(false);
        }
    }
    mtb_hal_system_critical_section_exit(intr_status);
}


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1,
                             'const qualifier is not viable here because of the cast on receiver later on')
//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_receiver_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_ipc_mbox_receiver_enable_event(mtb_ipc_mbox_receiver_t* receiver,
                                        mtb_ipc_mbox_event_t event,
                                        bool enable)
{
    //If there becomes a need for more than one event, this can be added upon here
    CY_UNUSED_PARAMETER(event);
    /* Validate args */
    CY_ASSERT_AND_RETURN_VOID(((receiver != NULL) && (receiver->instance != NULL) &&
                               (event == (mtb_ipc_mbox_event_t)MTB_IPC_MBOX_FULL)));
    _mtb_ipc_mbox_enable_irq((mtb_ipc_mbox_t*)receiver, enable);
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')


CY_MISRA_DEVIATE_BLOCK_START('MISRA C-2012 Rule 8.13', 1,
                             'const qualifier is not viable here because of the cast on sender later on')
//--------------------------------------------------------------------------------------------------
// mtb_ipc_mbox_sender_enable_event
//--------------------------------------------------------------------------------------------------
void mtb_ipc_mbox_sender_enable_event(mtb_ipc_mbox_sender_t* sender, mtb_ipc_mbox_event_t event,
                                      bool enable)
{
    //If there becomes a need for more than one event, this can be added upon here
    CY_UNUSED_PARAMETER(event);

    /* Validate args */
    CY_ASSERT_AND_RETURN_VOID(((sender != NULL) && (sender->instance != NULL) &&
                               (event == (mtb_ipc_mbox_event_t)MTB_IPC_MBOX_EMPTY)));

    _mtb_ipc_mbox_enable_irq((mtb_ipc_mbox_t*)sender, enable);
}


CY_MISRA_BLOCK_END('MISRA C-2012 Rule 8.13')


#if defined(__cplusplus)
}
#endif

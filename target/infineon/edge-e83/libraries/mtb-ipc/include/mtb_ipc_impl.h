/***************************************************************************//**
* \file mtb_ipc_impl.h
*
* \brief
* MTB IPC abstraction specific implementation for supported devices.
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

#pragma once
#include "cy_pdl.h"
#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
/* RTOS_AWARE is for semaphore usage so that in a multi-threaded system, we can allow other
 * threads to run if the current thread is blocked by a MTB IPC/PDL IPC Semaphore.
 */
#include "cyabs_rtos.h"
#include "cyabs_rtos_impl.h"
#endif
/* (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * \addtogroup group_mtb_impl_ipc IPC
 * \ingroup group_mtb_ipc
 * \{
 * Implementation specific interface for using the IPC library.
 *
 */

/**
 * \cond INTERNAL
 */

#if defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
/** This define can be used for aligning address of the data structures with enabled Data Cache */
#define _MTB_IPC_DATA_ALIGN       CY_ALIGN(__SCB_DCACHE_LINE_SIZE)
#else
/** This define can be used for aligning address of the data structures with enabled Data Cache */
#define _MTB_IPC_DATA_ALIGN
#endif /* defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U) */

/* This define will eventually be provided by PDL IPC header.
 *
 * CY_IPC_CHAN_USER_COUNT
 *
 * Until then, we determine the values here (MTB_IPC_USR_CHANNELS)
 */
#if defined(CY_IP_M4CPUSS)  //PSOC6 and Traveo devices
/* IPC starting channel */
    #if defined(CY_IPC_CHAN_USER)
        #define _MTB_IPC_CHAN_USER        (CY_IPC_CHAN_USER)
    #else
        #define _MTB_IPC_CHAN_USER        (CY_IPC_CHAN_DDFT + 1)
    #endif
/* On PSOC6/Traveo devices CY_IPC_CHANNELS is not available at compile time */
/* Most PSOC6/Traveo devices have 16 channels, except TVIIBE devices which have 8 channels. */
/* Available channels are those after _MTB_IPC_CHAN_USER.
 * Ex: 16 total channels - index of USR Channel (3) -1 (since user channel is 0-indexed)
 */
    #define MTB_IPC_USR_CHANNELS          (CPUSS_IPC_IPC_NR - _MTB_IPC_CHAN_USER - 1U)
#elif (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS)) // Explorer devices
/** On PSE84 device, there are two IPC instances (IPC0, IPC1),
 * with IPC1 intended for user application (CM33 <-> CM55 communication).
 * PDL driver handles instances by having one channel pool, 0 to 31.
 *   0 to 15 are IPC0
 *   16 to 31 are IPC1.
 *   First channel of IPC1 is reserved by PDL.
 *   We reserve the last channel of IPC1 for semaphores as one is not provided.
 *      32 total channel (IPC0 + IPC1) - index of USR channel (IPC0 + 1)
 *      -1 (since user channel is 0-indexed)
 *      -1 (last channel reserved for semaphores by IPC library)
 */
/*  IPC starting channel */
    #define _MTB_IPC_CHAN_USER            (CY_IPC_CHAN_USER)

    #define MTB_IPC_USR_CHANNELS          \
    ( ((CY_IPC_IP1_CH + CY_IPC_IP0_CH)- (_MTB_IPC_CHAN_USER+ 1U)) - 1U)
#elif defined(CPUSS_IPC_IPC_NR)
    #if defined(CY_IPC_CHAN_USER)
        #define _MTB_IPC_CHAN_USER        (CY_IPC_CHAN_USER)
    #else
        #define _MTB_IPC_CHAN_USER            (0u)
    #endif
/** PDL reserves channels before CY_IPC_CHAN_USER */
    #define MTB_IPC_USR_CHANNELS          (CPUSS_IPC_IPC_NR - _MTB_IPC_CHAN_USER - 1U)
#else // if defined(CY_IP_M4CPUSS)
    #error "Unhandled device"
#endif /* if defined(CY_IP_M4CPUSS) */

/* Channel & Interrupt Use on PSE84
 *  These defines are in mtb_ipc_impl.h
 *
 * PDL IPC Semaphore uses reserved channel to protect Semaphore operations
 * _MTB_IPC_PDL_SEMA_CHAN
 * IPC Library uses channel defined by init config.
 * We are adjust the channel for use with internal IPC library objects.
 * On PSE84 device, there are two IPC instances (IPC0, IPC1),
 * with IPC1 intended for user application (CM33 <-> CM55 communication).
 * PDL driver handles instances by having one channel pool - from 0  to 31,
 * where first 16 belong to IPC0 and second 16 channels belong to IPC1.
 */
#define _MTB_IPC_PDL_TO_IPC_LIB_CHAN_NUM(channel)                 ((channel) - _MTB_IPC_CHAN_USER)

/* Review _MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE define for PSOC6/Traveo: in the new implementation
 *  we are operating with this define with an internal MTB IPC objects.
 */
#if (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS))
#define _MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel)    \
    (((uint32_t)(channel) >= (uint32_t)MTB_IPC_CHAN_0) && ((uint32_t)(channel) < ((uint32_t)MTB_IPC_CHAN_0 + (uint32_t)MTB_IPC_USR_CHANNELS)))
#else
#define _MTB_IPC_IS_CHAN_IDX_IN_USER_RANGE(channel) \
    ((uint32_t)(channel) < (uint32_t)MTB_IPC_USR_CHANNELS)
#endif
// The INTR_RELEASE register of the IPC IP is 16 bits wide (IPC_STRUCT_RELEASE_INTR_RELEASE_Msk)
#define _MTB_IPC_RELEASE_BITS            (16)

/* Channel reserved for PDL semaphores  */
#ifdef CY_IPC_CHAN_SEMA
#define _MTB_IPC_PDL_SEMA_CHAN                (CY_IPC_CHAN_SEMA)
#elif (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS))
/* Reserve last available channel */
#define _MTB_IPC_PDL_SEMA_CHAN                (CY_IPC_IP0_CH + CY_IPC_IP1_CH - 1U)
#endif /* ifdef CY_IPC_CHAN_SEMA or other */

/** \endcond */

/** Number of IPC Channels available to Applications */
typedef enum
{
    /** User IPC channel 0 */
    MTB_IPC_CHAN_0 =   (_MTB_IPC_CHAN_USER),
    #if (MTB_IPC_USR_CHANNELS > 1)
    /** User IPC channel 1 */
    MTB_IPC_CHAN_1 =   (_MTB_IPC_CHAN_USER + 1),
    #endif /* MTB_IPC_USR_CHANNELS > 1 */
    #if (MTB_IPC_USR_CHANNELS > 2)
    /** User IPC channel 2 */
    MTB_IPC_CHAN_2 =   (_MTB_IPC_CHAN_USER + 2),
    #endif /* MTB_IPC_USR_CHANNELS > 2 */
    #if (MTB_IPC_USR_CHANNELS > 3)
    /** User IPC channel 3 */
    MTB_IPC_CHAN_3 =   (_MTB_IPC_CHAN_USER + 3),
    #endif /* MTB_IPC_USR_CHANNELS > 3 */
    #if (MTB_IPC_USR_CHANNELS > 4)
    /** User IPC channel 4 */
    MTB_IPC_CHAN_4 =   (_MTB_IPC_CHAN_USER + 4),
    #endif /* MTB_IPC_USR_CHANNELS > 4 */
    #if (MTB_IPC_USR_CHANNELS > 5)
    /** User IPC channel 5 */
    MTB_IPC_CHAN_5 =   (_MTB_IPC_CHAN_USER + 5),
    #endif /* MTB_IPC_USR_CHANNELS > 5 */
    #if (MTB_IPC_USR_CHANNELS > 6)
    /** User IPC channel 6 */
    MTB_IPC_CHAN_6 =   (_MTB_IPC_CHAN_USER + 6),
    #endif /* MTB_IPC_USR_CHANNELS > 6 */
    #if (MTB_IPC_USR_CHANNELS > 7)
    /** User IPC channel 7 */
    MTB_IPC_CHAN_7 =   (_MTB_IPC_CHAN_USER + 7),
    #endif /* MTB_IPC_USR_CHANNELS > 7 */
    #if (MTB_IPC_USR_CHANNELS > 8)
    /** User IPC channel 8 */
    MTB_IPC_CHAN_8 =   (_MTB_IPC_CHAN_USER + 8),
    #endif /* MTB_IPC_USR_CHANNELS > 8 */
    #if (MTB_IPC_USR_CHANNELS > 9)
    /** User IPC channel 9 */
    MTB_IPC_CHAN_9 =   (_MTB_IPC_CHAN_USER + 9),
    #endif /* MTB_IPC_USR_CHANNELS > 9 */
    #if (MTB_IPC_USR_CHANNELS > 10)
    /** User IPC channel 10 */
    MTB_IPC_CHAN_10 =    (_MTB_IPC_CHAN_USER + 10),
    #endif /* MTB_IPC_USR_CHANNELS > 10 */
    #if (MTB_IPC_USR_CHANNELS > 11)
    /** User IPC channel 11 */
    MTB_IPC_CHAN_11 =    (_MTB_IPC_CHAN_USER + 11),
    #endif /* MTB_IPC_USR_CHANNELS > 11 */
    #if (MTB_IPC_USR_CHANNELS > 12)
    /** User IPC channel 12 */
    MTB_IPC_CHAN_12 =    (_MTB_IPC_CHAN_USER + 12),
    #endif /* MTB_IPC_USR_CHANNELS > 12 */
    #if (MTB_IPC_USR_CHANNELS > 13)
    /** User IPC channel 13 */
    MTB_IPC_CHAN_13 =    (_MTB_IPC_CHAN_USER + 13),
    #endif /* MTB_IPC_USR_CHANNELS > 13 */
    #if (MTB_IPC_USR_CHANNELS > 14)
    /** User IPC channel 14 */
    MTB_IPC_CHAN_14 =    (_MTB_IPC_CHAN_USER + 14),
    #endif /* MTB_IPC_USR_CHANNELS > 14 */
    #if (MTB_IPC_USR_CHANNELS > 15)
    /** User IPC channel 15 */
    MTB_IPC_CHAN_15 =    (_MTB_IPC_CHAN_USER + 15)
    #endif /* MTB_IPC_USR_CHANNELS > 15 */
} mtb_ipc_channel_t;
#if (MTB_IPC_USR_CHANNELS > 16)
    #error "Unhandled number of free IPC channels"
#endif /* MTB_IPC_USR_CHANNELS > 16 */

/** Define the first available IRQ for use in MTB IPC */
#if !defined(CY_IPC_INTR_USER)
#define MTB_IPC_IRQ_USER  (0UL)
#else
#define MTB_IPC_IRQ_USER  (CY_IPC_INTR_USER)
#endif


/** Macro for semaphore data shared memory allocation. It is not mandatory to use it for data
 * allocation, user can allocate
 * the memory in the more convenient for them way. Please refer to MTB IPC library
 * documentation for the
 * requirements for memory allocation if macro is not used.
 *
 * Can be used only in function scope.
 * Params:
 * semaphore_data - pointer to mtb_ipc_semaphore_data_t data type, which will point to the shared
 * memory
 */
#define MTB_IPC_SEMAPHORE_DATA_ALLOC(semaphore_data) \
    do { CY_SECTION_SHAREDMEM static mtb_ipc_semaphore_data_t _mtb_ipc_semaphore_data _MTB_IPC_DATA_ALIGN; semaphore_data = &_mtb_ipc_semaphore_data; } while (0)


/** Macro for mailbox data shared memory allocation. It is not mandatory to use it for data
 * allocation, user can allocate
 * the memory in the more convenient for them way. Please refer to MTB IPC library
 * documentation for the
 * requirements for memory allocation if macro is not used.
 *
 * Can be used only in function scope.
 * Params:
 * mailbox_data - pointer to mtb_ipc_mbox_data_t data type, which will point to the shared
 * memory
 */
#define MTB_IPC_MBOX_DATA_ALLOC(mailbox_data) \
    do { CY_SECTION_SHAREDMEM static mtb_ipc_mbox_data_t _mtb_ipc_mailbox_data _MTB_IPC_DATA_ALIGN; mailbox_data = &_mtb_ipc_mailbox_data; } while (0)


/** Macro for Queue pool shared memory allocation. This macro can be used for the allocation of
 * queue pool for each queue being initialized, but used can allocate the memory in the most
 * convenient way for them. This macro can be used only in function scope.
 * Please refer to MTB IPC library documentation for the requirements for memory allocation
 * if macro is not used.
 * Params:
 * queue_pool - void pointer to point to the shared memory
 * NUM_ITEMS - number of items, that are expected to fit into the queue
 * ITEMSIZE - size of one queue item (in bytes)
 */
#define MTB_IPC_QUEUE_POOL_ALLOC(queue_pool, NUM_ITEMS, ITEMSIZE) \
    do { CY_SECTION_SHAREDMEM static uint8_t _mtb_ipc_queue_pool[ITEMSIZE * NUM_ITEMS] _MTB_IPC_DATA_ALIGN; queue_pool = (void*)&_mtb_ipc_queue_pool; } while (0)

/** Macro for Queue data shared memory allocation. It is not mandatory to use it for data
 * allocation, user can allocate
 * the memory in the more convenient for them way. Please refer to MTB IPC library
 * documentation for the
 * requirements for memory allocation if macro is not used.
 *
 * Can be used only in function scope.
 * Params:
 * queue_data - pointer to mtb_ipc_queue_data_t data type, which will point to the shared memory
 */
#define MTB_IPC_QUEUE_DATA_ALLOC(queue_data) \
    do { CY_SECTION_SHAREDMEM static mtb_ipc_queue_data_t _mtb_ipc_queue_data _MTB_IPC_DATA_ALIGN; queue_data = &_mtb_ipc_queue_data; } while (0)

/** Macro for Shared data region shared memory allocation. It is not mandatory to use it for data
   allocation, user can allocate
 * the memory in the more convenient for them way. Please refer to MTB IPC library
 * documentation for the
 * requirements for memory allocation if macro is not used.
 *
 * Can be used only in function scope.
 * Params:
 * shared - pointer to mtb_ipc_shared_t data type, which will point to the shared memory
 */
#define MTB_IPC_SHARED_DATA_ALLOC(shared) \
    do { CY_SECTION_SHAREDMEM static mtb_ipc_shared_t _mtb_ipc_shared_data _MTB_IPC_DATA_ALIGN; shared = &_mtb_ipc_shared_data; } while (0)

/** Polling interval, that will be used in blocking mtb_ipc_* functions.*/
#ifndef MTB_IPC_POLLING_INTERVAL_uS
#define MTB_IPC_POLLING_INTERVAL_uS   (1000u)
#endif /* #ifndef MTB_IPC_POLLING_INTERVAL_uS */

/** Number of RTOS semaphores that will be allocated and used by driver in RTOS environment
 * (CY_RTOS_AWARE or COMPONENT_RTOS_AWARE should be defined). Usage of RTOS semaphores in IPC
 * semaphores implementation
 * helps to utilize waiting for semaphores times in RTOS environment more effectively by allowing
 * other threads to run
 * while waiting for a semaphore. To achieve most effectiveness,
 * it is recommended to define MTB_IPC_RTOS_SEMA_NUM value to be greater-equal to the number of IPC
 * semaphores, that
 * are planned to be used. Only semaphores with `semaphore_num`, that is less than
 * _MTB_IPC_RELEASE_BITS can benefit from this feature.
 * Value of this define can be 0. In this case, IPC semaphores will not use RTOS semaphores.*/
#ifndef MTB_IPC_RTOS_SEMA_NUM
#define MTB_IPC_RTOS_SEMA_NUM         (10u)
#endif /* #ifndef MTB_IPC_RTOS_SEMA_NUM */

/**
 * Define a mask for signaling on NON-RTOS cores that a semaphore was given. This
 * is used in conjuction with the wait_semaphore_idx on the shared memory region
 * to signal that an ongoing operation may try again to take the semaphore.
 */
#define MTB_IPC_SEMAPHORE_WAIT_MASK    (0xFFUL)


/** Maximum number of mailboxes. This is determined by size of the notify section
 * of the IPC interrupt. 16 bits -> 16 mailboxes that can be signalled simultaneously.
 */
#define MTB_IPC_MAX_MBOXES (16UL)

#if (MTB_IPC_RTOS_SEMA_NUM > _MTB_IPC_RELEASE_BITS)
#error "Cannot handle selected amount of RTOS semaphores. Please fix MTB_IPC_RTOS_SEMA_NUM value"
#endif /* MTB_IPC_RTOS_SEMA_NUM > _MTB_IPC_RELEASE_BITS */

#if defined(CY_IP_M4CPUSS) || (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS))
#define _MTB_IPC_CORE_NUM                         (2U) //!< Number of cores being serviced by the
                                                       //!< driver

#if defined(CY_IP_M4CPUSS)
#define _MTB_IPC_CM0P_IDX                         (0U)     //!< Boot Core
#define _MTB_IPC_CM4_IDX                          (1U)     //!< Other Core
#else /* (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS)) */
#define _MTB_IPC_CM33_IDX                         (0U)     //!< Boot Core
#define _MTB_IPC_CM55_IDX                         (1U)     //!< Other Core
#endif


#if defined(CY_IP_M4CPUSS)
#if (CY_CPU_CORTEX_M0P)
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM0P_IDX)
#define _MTB_IPC_OTHER_CORE_IDX                   (_MTB_IPC_CM4_IDX)
#else /* CY_CPU_CORTEX_M4 */
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM4_IDX)
#define _MTB_IPC_OTHER_CORE_IDX                   (_MTB_IPC_CM0P_IDX)
#endif /* CY_CPU_CORTEX_M0P or CY_CPU_CORTEX_M4 */
#else
#if (CY_CPU_CORTEX_M33)
#define _MTP_IPC_CUR_CORE_CLOCK                   (0UL)
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM33_IDX)
#define _MTB_IPC_OTHER_CORE_IDX                   (_MTB_IPC_CM55_IDX)
#else /*CY_CPU_CORTEX_M55 */
#define _MTP_IPC_CUR_CORE_CLOCK                   (1UL)
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM55_IDX)
#define _MTB_IPC_OTHER_CORE_IDX                   (_MTB_IPC_CM33_IDX)
#endif /* CY_CPU_CORTEX_M33 or CY_CPU_CORTEX_M55 */
#endif \
    /* defined(CY_IP_M4CPUSS) */

#elif defined(CY_IP_M7CPUSS)
/* Number of cores being serviced by the driver */
#define _MTB_IPC_CORE_NUM                         (3)

#define _MTB_IPC_CM0P_IDX                         (0)      //!< Boot Core
#define _MTB_IPC_CM7_0_IDX                        (1)
#define _MTB_IPC_CM7_1_IDX                        (2)

//reevaluate these definitions for use in XMC: BSP-7395
#define _MTP_IPC_CUR_CORE_CLOCK                   (0UL)

#if (CY_CPU_CORTEX_M0P)
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM0P_IDX)
#if (CPUSS_CM7_1_PRESENT)
#define _MTB_IPC_OTHER_CORE_0_IDX                 (_MTB_IPC_CM7_0_IDX)
#define _MTB_IPC_OTHER_CORE_1_IDX                 (_MTB_IPC_CM7_1_IDX)
#else
#define _MTB_IPC_OTHER_CORE_IDX                   (_MTB_IPC_CM7_0_IDX)
#endif
#elif (CY_CPU_CORTEX_M7)
#if (CORE_NAME_CM7_0)
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM7_0_IDX)
#if (CPUSS_CM7_1_PRESENT)
#define _MTB_IPC_OTHER_CORE_0_IDX                 (_MTB_IPC_CM0P_IDX)
#define _MTB_IPC_OTHER_CORE_1_IDX                 (_MTB_IPC_CM7_1_IDX)
#else
#define _MTB_IPC_OTHER_CORE_IDX                   (_MTB_IPC_CM0P_IDX)
#endif
#elif (CORE_NAME_CM7_1)
#define _MTB_IPC_CUR_CORE_IDX                     (_MTB_IPC_CM7_1_IDX)
#define _MTB_IPC_OTHER_CORE_0_IDX                 (_MTB_IPC_CM0P_IDX)
#define _MTB_IPC_OTHER_CORE_1_IDX                 (_MTB_IPC_CM7_0_IDX)
#else // if (CORE_NAME_CM7_0)
#error "Unable to determine CM7 core index"
#endif /* defined (ACTIVE_CORE_CM7_0) or defined (ACTIVE_CORE_CM7_0) or error */
#endif /* CY_CPU_CORTEX_M0P or CY_CPU_CORTEX_M7 */

#else /* not PSOC6 / PSE84 / Traveo */
    #error "Unhandled device"
#endif \
    /* defined(CY_IP_M4CPUSS) or (defined(CY_IP_M33SYSCPUSS) && defined(CY_IP_M55APPCPUSS)) or
       defined(CY_IP_M7CPUSS) */

/** The maximum number of Processes per Queue.
 */
#if defined(CY_IP_M7CPUSS) && (CPUSS_CM7_1_PRESENT == 1u)
/* ex: XMC72xx has 3 processors */
#define _MTB_IPC_MAX_PROCESSES_PER_QUEUE          (3UL)
#else
#define _MTB_IPC_MAX_PROCESSES_PER_QUEUE          (2UL)
#endif /* defined(CY_IP_M7CPUSS) */

/** Number of semaphores, that can be used */
#ifdef CY_IPC_SEMA_COUNT
#define _MTB_IPC_SEMA_COUNT                       (CY_IPC_SEMA_COUNT)
#else
#define _MTB_IPC_SEMA_COUNT                       (128u)
#endif /* ifdef CY_IPC_SEMA_COUNT */

/** External variable of available semaphores */
#define MTB_IPC_USER_SEMA_COUNT                   (_MTB_IPC_SEMA_COUNT)

/** Indicate an unused semaphore that can be allocated */
#define _MTB_IPC_UNUSED_SEMAPHORE                 (0xFFFFUL)

/** @brief Event callback data object */
typedef struct
{
    cy_israddress                       callback;
    void*                               callback_arg;
} _mtb_ipc_event_callback_data_t;

/**
 * @brief IPC notification info
 *
 * IPC Notification and callback information per Process associated with one Queue.
 */
typedef struct
{
    uint32_t    mask;   //!< Process-specific notification mask for this Queue
    uint32_t    flags;  //!< Process-specific active notification flags for this Queue
} _mtb_ipc_queue_process_info_t;

/**
 * @brief IRQ channel storage struct for holding data relevant for all cores to know.
 */
typedef struct
{
    uint32_t sema_irq;  //!<Semaphore IRQ for this core
    uint32_t queue_irq; //!<Queue IRQ for this core
} _mtb_ipc_core_irq_data;


/** @brief IPC Semaphore Data
 * User should allocate but not modify anything in this struct.
 */
typedef struct mtb_ipc_semaphore_data_s
{
    bool                                sema_preemptable;   //!< if true, allow preemption
    uint32_t                            sema_number;        //!< semaphore number in IPC system
    struct mtb_ipc_semaphore_data_s*    next_sema;          //!< Next Semaphore in linked list
} mtb_ipc_semaphore_data_t;

/** @brief IPC Semaphore Handle
 * User should allocate but not modify anything in this struct.
 */
typedef struct mtb_ipc_semaphore_q
{
    /** Pointer to data in shared memory for this semaphore */
    mtb_ipc_semaphore_data_t*   sema_obj;
    /** Pointer to the IPC instance */
    struct mtb_ipc_t*           instance;
} mtb_ipc_semaphore_t;

/** @brief IPC mailbox data element
 * User should allocate but not modify anything in this struct.
 */
typedef struct
{
    uint32_t                    mbox_idx; //!< from 0-MTB_IPC_MAX_MBOXES
    void*                       payload; //!< Payload address that will be protected by mailbox
    mtb_ipc_semaphore_data_t    sema_read; //!< The semaphore for protecting read ops
    mtb_ipc_semaphore_data_t    sema_write; //!< The semaphore for protecting write ops
    uint8_t                     core_id_sender; //!< Core ID of the sender
    uint8_t                     core_id_receiver; //!< Core ID of the receiver
} mtb_ipc_mbox_data_t;

/** @brief IPC mailbox handle element
 * User should allocate but not modify anything in this struct.
 */
typedef struct
{
    mtb_ipc_mbox_data_t*            mbox_obj; //!< Pointer to mailbox shared data
    _mtb_ipc_event_callback_data_t  callback_data; //!< Pointer to callback data on this core
    mtb_ipc_semaphore_t             sema_read_handle; //!< Handle for the read semaphore
    mtb_ipc_semaphore_t             sema_write_handle; //!< Handle for write semaphore
    struct mtb_ipc_t*               instance; //!< Pointer to the IPC instance
} mtb_ipc_mbox_t;

/**
 * @brief IPC mailbox sender handle
 * We provide distinct type names to
 * distinguish which role can call which functions.
 * ex: Sender puts.
 */
typedef mtb_ipc_mbox_t mtb_ipc_mbox_sender_t;
/**
 * @brief IPC mailbox receiver handle
 * We provide distinct type names to
 * distinguish which role can call which functions. ex:
 * Receiver gets.
 */
typedef mtb_ipc_mbox_t mtb_ipc_mbox_receiver_t;


/** @brief IPC queue data element
 * User should allocate but not modify anything in this struct.
 */
typedef struct mtb_ipc_queue_data_t
{
    /** IPC channel number (e.g. MTB_IPC_CHAN_0)
     * Please refer to implementation specific documentation for number
     * of available IPC channels for particular device. */
    uint32_t                            channel_num;
    /** Queue number, which must be unique for each queue in scope of one IPC channel. */
    uint32_t                            queue_num;
    /** Maximum number of items (packets) allowed in the queue */
    uint32_t                            max_num_items;
    /** Size of each item (packet) in the Queue */
    uint32_t                            item_size;
    /** Pointer to the queue packets in shared memory.
     * This memory will be cleared by IPC library Queue Initialization.
     * Packet list is an array of packets of max_num_items.
     * It is used as a circular array, first_item is an index to first item stored. */
    void* queue_pool;
    /* Items populated by IPC library when calling mtb_ipc_queue_init() */
    /** Current number of items (packets) in the queue. Set to 0x00. */
    uint32_t                            curr_items;
    /** Index of the first item in the queue array, INVALID if curr_items is 0x00 */
    uint32_t                            first_item;
    /* Items populated by IPC library when calling \ref _mtb_ipc_queue_register_callback. */
    /** IPC Semaphore - covers all items in the queue EXCEPT for notifications, which use the
       channel of the queue's lock. */
    mtb_ipc_semaphore_data_t            queue_semaphore;
    /** Notification structure per Process. Changed when user calls  \ref mtb_ipc_queue_enable_event
     * and \ref
     * mtb_ipc_queue_register_callback. Modified by IPC library during execution
     * (not expected to be modified by user directly). */
    _mtb_ipc_queue_process_info_t       notifications[_MTB_IPC_MAX_PROCESSES_PER_QUEUE];
    /** Linked List is used to avoid excessive memory use. These are arranged per channel in the
     * shared struct.*/
    /** Pointer to next queue data element in per-channel linked-list*/
    struct mtb_ipc_queue_data_t*        next;
} mtb_ipc_queue_data_t;

/** @brief IPC Queue handle object
 * User should allocate but not modify anything in this struct.
 */
typedef struct mtb_ipc_queue_t
{
    /** Pointer to related callback data for this queue */
    _mtb_ipc_event_callback_data_t  callback_data;
    /** Pointer to the queue data for this handle */
    mtb_ipc_queue_data_t*           queue_obj;
    /** IPC Semaphore - covers all items in the queue EXCEPT for notifications,  which use the
     *  channel lock. */
    mtb_ipc_semaphore_t             semaphore_handle;
    /* We need a linked list to avoid excessive memory use. These are arranged per channel in the
     *  shared struct.*/
    /** Pointer to next node in linked list */
    struct mtb_ipc_queue_t*         next;
    /** Pointer to the IPC instance */
    struct mtb_ipc_t*               instance;
    /** Events fired to compare against events being waited for */
    uint32_t                        events_fired;
    /** Process-specific notification mask for this Queue */
    uint32_t                        events_enabled;
    /** # of pending reads */
    uint8_t                         pending_reads;
    /** # of pending writes */
    uint8_t                         pending_writes;
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
    /** RTOS event to sleep while queue is empty/full */
    cy_event_t                      queue_rtos_event;
    /** Counter of how many threads are waiting on RTOS events */
    uint32_t                        rtos_event_waiting_count;
    #endif
} mtb_ipc_queue_t;

/**
 * @brief RTOS/IPC semaphore linkage object to store info and
 * block all semaphores trying to take that same IPC semaphore
 * on same RTOS semaphore
 * If active_count is 0, sema_idk will be set back to _MTB_IPC_UNUSED_SEMAPHORE
 */
typedef struct
{
    uint32_t active_count;  //!< Counter for threads allocated to this semaphore.
    uint32_t sema_idx;      //!< Index of the IPC semaphore linked to this RTOS semaphore
} _mtb_ipc_rtos_semaphore_data;

/**
 * @brief IPC Shared Memory Object
 *
 * IPC shared memory object used to keep track of queues and semaphores across cores.
 * User should allocate but not modify anything in this struct.
 */
typedef struct
{
    /** Local data for the IPC library Semaphore for changing any IPC library variables*/
    mtb_ipc_semaphore_data_t        ipc_driver_semaphore;

    /** IPC library Semaphore linked list for lookup of already initialized semaphores*/
    mtb_ipc_semaphore_data_t*       ipc_semaphore_list;

    /** List of initialized array of IPC library Queue pointers -- protect with _mtb_ipc_semaphore
     * Arranged by Channel to efficiently scan through list when ISR occurs on a channel.
     * Some devices have first User Channel > 0.
     *  To access, use the function _mtb_ipc_queue_array_get_pointer(channel_num, queue_num);
     */
    mtb_ipc_queue_data_t*           ipc_queue_array[MTB_IPC_USR_CHANNELS];

    /** Shared data object to store all assigned interrupt channels for use in interrupt processing
     * These are used in correctly sending to all cores the required event(s)
     * Each \ref _mtb_ipc_core_irq_data is indexed to its respective core.
     */
    _mtb_ipc_core_irq_data          irq_channels[_MTB_IPC_MAX_PROCESSES_PER_QUEUE];
    /** Allocated memory for PDL semaphores. This is passed into PDL semaphore init on the boot core
     * for non-PSOC6 devices. PSOC6 devices instead handle this in their startup code.
     */
    uint32_t                        ipc_pdl_sema_array[_MTB_IPC_SEMA_COUNT / CY_IPC_SEMA_PER_WORD];

    /** Array to keep track of shared mailbox data */
    mtb_ipc_mbox_data_t*            ipc_mailbox_array[MTB_IPC_MAX_MBOXES];

    /**Associated RTOS semaphore list. Each entry is _MTB_IPC_UNUSED_SEMAPHORE until assigned to a
       semaphore. */
    _mtb_ipc_rtos_semaphore_data    rtos_semaphore_idx[_MTB_IPC_CORE_NUM][MTB_IPC_RTOS_SEMA_NUM];

    /** Value of semaphore (per core) that is currently waiting for a give. The value is
       _MTB_IPC_UNUSED_SEMAPHORE until assigned to a semaphore. */
    uint32_t                        wait_semaphore_idx[_MTB_IPC_CORE_NUM];
} mtb_ipc_shared_t;

/** @brief IPC Instance object
 * This is the per-core obj for tracking shared memory
 * and initialized queues/semaphores. It also handles the
 * corresponding RTOS semaphores.
 * User should allocate but not modify anything in this struct.
 */
typedef struct mtb_ipc_t
{
    /** IPC channel number (e.g. MTB_IPC_CHAN_0) Please refer to implementation specific
     * documentation for number of available IPC channels for particular device.
     * This must match the IPC object initialized on the other core for this core to access the
     * shared memory.*/
    uint32_t                    internal_channel_index;
    /** User Defined IRQ for use on this core for all semaphores. A different IRQ Struct Number must
       be used for other cores. */
    uint32_t                    semaphore_irq;
    /** User Defined IRQ for use on this core for all queues. A different IRQ Struct Number must be
     * used for other cores. */
    uint32_t                    queue_irq;
    /** User to trigger interrupts on all cores to then check notifications */
    uint32_t                    trigger_mask;
    /** Internal semaphore to block access to the  memory region. */
    mtb_ipc_semaphore_t         internal_ipc_semaphore;
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE)) && (MTB_IPC_RTOS_SEMA_NUM > 0)
    /**Associated RTOS semaphore list. Each is assigned to an IPC semaphore when it is taken. */
    cy_semaphore_t              rtos_semaphore_base[MTB_IPC_RTOS_SEMA_NUM];
    #endif
    /** Value of semaphore that is currently waiting for a give. The value is
       _MTB_IPC_UNUSED_SEMAPHORE until assigned to a semaphore. */
    volatile uint32_t           wait_semaphore_idx;
    mtb_ipc_shared_t*           ipc_shared_vars; //!< Shared memory region
    /** Local storage of all queue handles which each point to corresponding data in shared memory.
     * This is an array indexed by channel of linked lists.
     */
    mtb_ipc_queue_t*            queue_array[MTB_IPC_USR_CHANNELS];

    /** Local storage of all mailbox handles (sender or receiver) which each point to corresponding
     * data in shared memory. Index determined at initialization of mailbox.
     */
    mtb_ipc_mbox_t* mbox_array[MTB_IPC_MAX_MBOXES];
} mtb_ipc_t;


/** \} group_mtb_impl_ipc */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

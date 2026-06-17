/***************************************************************************//**
* \file cybsp.c
*
* Description:
* Provides initialization code for starting up the hardware contained on the
* Infineon board.
*
********************************************************************************
* \copyright
* Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
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

#include <stdlib.h>
#include "cy_syspm.h"
#include "cy_sysclk.h"
#include "cybsp.h"
#include "cycfg.h"
#if ((CY_SYSTEM_CPU_M33) && defined(COMPONENT_NON_SECURE_DEVICE)) || (CY_SYSTEM_CPU_M55)
#include "cycfg_protection.h"
#endif
#ifndef CYBSP_DISABLE_SRF_INIT
#if defined(COMPONENT_SECURE_DEVICE)
#include "mtb_srf.h"
#else
#include "mtb_srf_pool_init.h"
#if defined(COMPONENT_MW_MTB_IPC) && defined(COMPONENT_MW_MTB_SRF)
#include "mtb_ipc.h"
#include "mtb_srf_ipc_init.h"
#endif
#endif
#endif
#if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)
#include "partition_ARMCM33.h"
#endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(CYBSP_POST_CFG_INIT)
/* If this BSP requires a step immediately after init_cycfg_all, declare it */
cy_rslt_t cybsp_post_cfg_init();
#endif // defined(CYBSP_POST_CFG_INIT)

// The sysclk deep sleep callback is recommended to be the last callback that is executed before
// entry into deep sleep mode and the first one upon exit the deep sleep mode.
// Doing so minimizes the time spent on low power mode entry and exit.
#ifndef CYBSP_SYSCLK_PM_CALLBACK_ORDER
    #define CYBSP_SYSCLK_PM_CALLBACK_ORDER  (255u)
#endif

#if !defined(COMPONENT_MW_MTB_SRF) || defined(CY_SRF_DISABLE)
/* If the MTB-SRF library isn't present, disable its initialization */
#define CYBSP_DISABLE_SRF_INIT     (1)
#endif

#ifndef CYBSP_DISABLE_SRF_INIT
// Secure context and pool for use with the Secure Request Framework
#if defined(COMPONENT_SECURE_DEVICE)
#if !defined(MTB_SRF_SECURE_CONTEXT_SECTION)
// Optional macro to specify the linker section for the secure context
#define MTB_SRF_SECURE_CONTEXT_SECTION
#endif
MTB_SRF_SECURE_CONTEXT_SECTION mtb_srf_context_s_t cybsp_srf_context;
#else
mtb_srf_pool_t cy_pdl_srf_default_pool;
CY_SECTION_SHAREDMEM _MTB_SRF_DATA_ALIGN uint32_t cy_pdl_srf_default_pool_memory[(MTB_SRF_POOL_ENTRY_SIZE(
                                                                         MTB_SRF_MAX_ARG_IN_SIZE,
                                                                         MTB_SRF_MAX_ARG_OUT_SIZE)
                                                                     * MTB_SRF_POOL_SIZE) /
                                                                    sizeof(uint32_t)];

#if defined(COMPONENT_MW_MTB_IPC)
#define MTB_SRF_IPC_SEMA_COUNT (MTB_IPC_SEMA_NUM_SRF_REQ_END - MTB_IPC_SEMA_NUM_SRF_REQ_START + 1)
/* Error if the inclusive semaphore range defined in IPC does not match the semaphore number from SRF */
#if (MTB_SRF_IPC_SEMA_COUNT < MTB_SRF_POOL_SIZE)
#error "Semaphore region defined by mtb_ipc_config.h (MTB_IPC_SEMA_NUM_SRF_REQ_START to MTB_IPC_SEMA_NUM_SRF_REQ_END inclusive) is less than MTB_SRF_POOL_SIZE. \
Please adjust MTB_IPC_SEMA_NUM_SRF_REQ_END"
#endif
#if defined(MTB_SRF_SUBMIT_USE_IPC)
/** Context for the SRF client */
mtb_srf_ipc_client_context_t cybsp_mtb_srf_client_context;
/** Instance of MTB IPC on the CM55 setup by SRF */
mtb_ipc_t cybsp_cm55_ipc_instance;
/* Define variables for SRF IPC init. Shared memory variables must not be static otherwise the compiler
may store them incorrectly*/
CY_SECTION_SHAREDMEM _MTB_SRF_DATA_ALIGN mtb_srf_ipc_packet_t cybsp_srf_ipc_requests[MTB_SRF_POOL_SIZE];
mtb_ipc_semaphore_t cybsp_cm55_srf_ipc_semaphores[MTB_SRF_IPC_SEMA_COUNT];
mtb_ipc_mbox_sender_t cybsp_srf_ipc_sender;
mtb_srf_ipc_pool_t cybsp_srf_ipc_pool;
#define MTB_IPC_IRQ_SEMA_SRF                        (MTB_IPC_IRQ_SEMA_SRF_CLIENT)
#define MTB_IPC_IRQ_QUEUE_SRF                       (MTB_IPC_IRQ_QUEUE_SRF_CLIENT)
#else
/** Context for the SRF relay */
mtb_srf_ipc_relay_context_t cybsp_mtb_srf_relay_context;
/** Instance of MTB IPC on the CM33 setup by SRF. Shared memory variables must not be static otherwise the compiler
may store them incorrectly */
mtb_ipc_t cybsp_cm33_ipc_instance;
CY_SECTION_SHAREDMEM mtb_ipc_shared_t cybsp_srf_ipc_shared_data _MTB_IPC_DATA_ALIGN;
CY_SECTION_SHAREDMEM mtb_ipc_mbox_data_t cybsp_srf_ipc_mbox_data _MTB_IPC_DATA_ALIGN;
CY_SECTION_SHAREDMEM mtb_ipc_semaphore_data_t cybsp_ipc_sem_data[MTB_SRF_IPC_SEMA_COUNT] _MTB_IPC_DATA_ALIGN;
mtb_ipc_semaphore_t cybsp_cm33_srf_ipc_semaphores[MTB_SRF_IPC_SEMA_COUNT];
mtb_ipc_mbox_receiver_t cybsp_srf_ipc_receiver;
#define MTB_IPC_IRQ_SEMA_SRF                        (MTB_IPC_IRQ_SEMA_SRF_RELAY)
#define MTB_IPC_IRQ_QUEUE_SRF                       (MTB_IPC_IRQ_QUEUE_SRF_RELAY)
#if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
cy_queue_t cybsp_srf_request_queue;
cy_thread_t cybsp_srf_receive;
cy_thread_t cybsp_srf_process;
static uint64_t cybsp_srf_thread_stack_receive[500];
static uint64_t cybsp_srf_thread_stack_process[500];
#else
mtb_srf_ipc_packet_t* cybsp_srf_ring_buffer[MTB_SRF_POOL_SIZE];
#endif
#endif // defined(MTB_SRF_SUBMIT_USE_IPC)
#endif // defined(COMPONENT_MW_MTB_IPC)
#endif // defined(COMPONENT_SECURE_DEVICE)
#endif // ifndef CYBSP_DISABLE_SRF_INIT

#if (CY_SYSTEM_CPU_M33) && !defined(COMPONENT_SECURE_DEVICE)
/**
 * Place in normal shared memory for semaphore
 * This array holds the semaphore states in normal (non-secure) shared memory.
 */
CY_SECTION_SHAREDMEM static uint32_t cybsp_ipc_sema_array[CY_IPC_SEMA_COUNT /
                                                          CY_IPC_SEMA_PER_WORD];
/* IPC semaphore structure placed in normal shared memory */
CY_SECTION_SHAREDMEM cy_stc_ipc_sema_t cybsp_ipc_sema;
#endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)

#if defined(COMPONENT_MW_MTB_IPC) && !defined(COMPONENT_SECURE_DEVICE) && !defined(CYBSP_DISABLE_SRF_INIT)
void cybsp_srf_ipc_semaphore_interrupt_handler(void)
{
    #if defined(MTB_SRF_SUBMIT_USE_IPC)
    mtb_ipc_semaphore_process_interrupt(&cybsp_cm55_ipc_instance);
    #else
    mtb_ipc_semaphore_process_interrupt(&cybsp_cm33_ipc_instance);
    #endif
}
void cybsp_srf_ipc_queue_interrupt_handler(void)
{
    #if defined(MTB_SRF_SUBMIT_USE_IPC)
    mtb_ipc_queue_process_interrupt(&cybsp_cm55_ipc_instance);
    #else
    mtb_ipc_queue_process_interrupt(&cybsp_cm33_ipc_instance);
    #endif
}

cy_rslt_t _cybsp_ipc_srf_init()
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    mtb_ipc_config_t ipc_config =
    {
        .internal_channel_index = MTB_IPC_CHANNEL_SRF,
        .semaphore_irq          = MTB_IPC_IRQ_SEMA_SRF,
        .queue_irq              = MTB_IPC_IRQ_QUEUE_SRF,
        .semaphore_num          = MTB_IPC_SEMA_NUM_SRF
    };

    cy_stc_sysint_t intr_cfg_sema = {.intrSrc = (IRQn_Type)CY_IPC_INTR_MUX(ipc_config.semaphore_irq), .intrPriority = 7u};
    Cy_SysInt_Init(&intr_cfg_sema, cybsp_srf_ipc_semaphore_interrupt_handler);
    cy_stc_sysint_t intr_cfg_queue = {.intrSrc = (IRQn_Type)CY_IPC_INTR_MUX(ipc_config.queue_irq), .intrPriority = 7u};
    Cy_SysInt_Init(&intr_cfg_queue, cybsp_srf_ipc_queue_interrupt_handler);
    NVIC_EnableIRQ((IRQn_Type)CY_IPC_INTR_MUX(ipc_config.semaphore_irq));
    NVIC_EnableIRQ((IRQn_Type)CY_IPC_INTR_MUX(ipc_config.queue_irq));
    /** Setup IPC for use in secure requests */
    uint32_t mtb_srf_ipc_semaphore_idx_list[MTB_SRF_IPC_SEMA_COUNT];
    /* Initialize semaphore index list */
    for(uint32_t idx = 0; idx < MTB_SRF_IPC_SEMA_COUNT; idx++)
    {
        mtb_srf_ipc_semaphore_idx_list[idx] = idx + MTB_IPC_SEMA_NUM_SRF_REQ_START;
    }
    #if (CY_SYSTEM_CPU_M33)
    #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
    result = cy_rtos_queue_init(&cybsp_srf_request_queue, MTB_SRF_POOL_SIZE, sizeof(void*));
    #endif
    if (CY_RSLT_SUCCESS == result)
    {
        result = mtb_ipc_init(&cybsp_cm33_ipc_instance, &cybsp_srf_ipc_shared_data, &ipc_config);
        if (result == CY_RSLT_SUCCESS)
        {
            mtb_srf_ipc_relay_init_cfg_t relay_init_cfg =
            {
                .ipc_instance           = &cybsp_cm33_ipc_instance,
                .mailbox_handle         = &cybsp_srf_ipc_receiver,
                .ipc_sem_indexes        = mtb_srf_ipc_semaphore_idx_list,
                .mailbox_data           = &cybsp_srf_ipc_mbox_data,
                .semaphore_data         = cybsp_ipc_sem_data,
                .semaphore_handles      = cybsp_cm33_srf_ipc_semaphores,
                .mbox_idx               = MTB_IPC_MBOX_IDX_SRF,
                .mbox_read_sema_idx     = MTB_IPC_SEMA_NUM_SRF_MBOX_READ,
                .mbox_write_sema_idx    = MTB_IPC_SEMA_NUM_SRF_MBOX_WRITE,
                .num_semaphores         = MTB_SRF_IPC_SEMA_COUNT,
                .num_requests           = MTB_SRF_POOL_SIZE,
                #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
                .ipc_req_queue          = &cybsp_srf_request_queue
                #else
                .buffer                 = cybsp_srf_ring_buffer
                #endif
            };
            result = mtb_srf_ipc_relay_init(&cybsp_mtb_srf_relay_context, &relay_init_cfg);
            #if (defined(CY_RTOS_AWARE) || defined(COMPONENT_RTOS_AWARE))
            if (CY_RSLT_SUCCESS == result)
            {
                if (CY_RSLT_SUCCESS == result)
                {
                    result = cy_rtos_thread_create(&cybsp_srf_receive, &mtb_srf_ipc_receive_thread,
                                        "Receive Thread", &cybsp_srf_thread_stack_receive,
                                        sizeof(cybsp_srf_thread_stack_receive),
                                        CY_RTOS_PRIORITY_NORMAL, (cy_thread_arg_t)&cybsp_mtb_srf_relay_context);

                    if (CY_RSLT_SUCCESS == result)
                    {
                        result = cy_rtos_thread_create(&cybsp_srf_process, &mtb_srf_ipc_process_thread,
                                                    "Process Thread", &cybsp_srf_thread_stack_process,
                                                    sizeof(cybsp_srf_thread_stack_process),
                                                    CY_RTOS_PRIORITY_NORMAL, (cy_thread_arg_t)&cybsp_mtb_srf_relay_context);
                    }
                }
            }
            #endif
        }
    }
    #elif (CY_SYSTEM_CPU_M55)
    result = mtb_ipc_get_handle(&cybsp_cm55_ipc_instance, &ipc_config, 1000UL);
    if (result == CY_RSLT_SUCCESS)
    {
        mtb_srf_ipc_client_init_cfg_t client_init_cfg =
        {
            .ipc_instance       = &cybsp_cm55_ipc_instance,
            .mailbox_handle     = &cybsp_srf_ipc_sender,
            .ipc_sem_indexes    = mtb_srf_ipc_semaphore_idx_list,
            .srf_ipc_requests   = cybsp_srf_ipc_requests,
            .srf_ipc_pool       = &cybsp_srf_ipc_pool,
            .semaphore_handles  = cybsp_cm55_srf_ipc_semaphores,
            .mbox_idx           = MTB_IPC_MBOX_IDX_SRF,
            .num_semaphores     = MTB_SRF_IPC_SEMA_COUNT,
            .num_requests       = MTB_SRF_POOL_SIZE
        };
        result = mtb_srf_ipc_client_init(&cybsp_mtb_srf_client_context, &client_init_cfg);
    }
    #endif // (CY_SYSTEM_CPU_M33)
    return result;
}
#endif // defined(COMPONENT_MW_MTB_IPC) && !defined(COMPONENT_SECURE_DEVICE) && !defined(CYBSP_DISABLE_SRF_INIT)

/*****************************************************************************
* Function Name: _mtb_global_sema_init
******************************************************************************
* Summary:
* Initialize global semaphores for IPC usage in application
* Only called from secure-application setup, as it will take care
* of the semaphore setup for all of the cores to utilize
*
* Parameters:
* None
*
* Return:
* void
*****************************************************************************/
void _cybsp_global_sema_init(void)
{
    // Initialize the global semaphore data for the non-secure world CM33_NS. If needed on the CM33_S, this pointer must
    // be passed to CM33_S to initialize the IPC in the secure world.
    #if (CY_SYSTEM_CPU_M33) && !defined(COMPONENT_SECURE_DEVICE)
    cybsp_ipc_sema.maxSema = CY_IPC_SEMA_COUNT;
    cybsp_ipc_sema.arrayPtr = cybsp_ipc_sema_array;
    cybsp_ipc_sema.arrayPtr_sec = NULL;

    Cy_IPC_Sema_InitExt(IPC0_SEMA_CH_NUM, &cybsp_ipc_sema);
    #elif (CY_SYSTEM_CPU_M55)
    // Initialize the global semaphore in the non-secure context
    Cy_IPC_Sema_Init(IPC0_SEMA_CH_NUM, 0, NULL);
    #endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)
}

//--------------------------------------------------------------------------------------------------
// cybsp_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cybsp_init(void)
{
    // Setup hardware manager to track resource usage then initialize all system (clock/power) board
    // configuration
    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* Configure semaphore */
    _cybsp_global_sema_init();

    // CM33 secure is the first to boot. Initialize peripherals, SAU, any enabled MPCs, and the MPU
    // for this core
    #if (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)

    // Setup System Control Block
    SysCtrlBlk_Setup();
    // Setup NS NVIC interrupts
    NVIC_NS_Setup();

    #if defined (__FPU_USED) && (__FPU_USED == 1U) && \
    defined (TZ_FPU_NS_USAGE) && (TZ_FPU_NS_USAGE == 1U)
    /*FPU initialization*/
    initFPU();
    #endif

    // Initialize system clocks, peripheral clock dividers, pin configurations, routing, SAU, MPCs
    // and MPU for the core
    init_cycfg_all();

    #if defined(CYBSP_POST_CFG_INIT)
    /* Perform custom initialization step */
    result = cybsp_post_cfg_init();
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif


    #if !defined(CYBSP_DISABLE_SRF_INIT)
    // Set up the SRF and register the PDL module
    result = mtb_srf_init(&cybsp_srf_context);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #if defined(CY_PDL_ENABLE_SECURE_AWARE) && (CY_PDL_ENABLE_SECURE_AWARE)
    result = cy_pdl_srf_module_register(&cybsp_srf_context);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif // defined(CY_PDL_ENABLE_SECURE_AWARE) && (CY_PDL_ENABLE_SECURE_AWARE)
    #endif // !defined(CYBSP_DISABLE_SRF_INIT)

    #else // CM33 non-secure or CM55

    #if !defined(CYBSP_DISABLE_SRF_INIT)
    result = mtb_srf_pool_init(&cy_pdl_srf_default_pool,
                               &cy_pdl_srf_default_pool_memory[0], MTB_SRF_POOL_SIZE,
                               MTB_SRF_MAX_ARG_IN_SIZE, MTB_SRF_MAX_ARG_OUT_SIZE);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #if defined(COMPONENT_MW_MTB_IPC)
    /* IPC must be initialized after peripheral clocks*/
    result = _cybsp_ipc_srf_init();
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif // defined(COMPONENT_MW_MTB_IPC)
    #endif //!defined(CYBSP_DISABLE_SRF_INIT)

    // Initialize the peripheral-related data structures (but do not
    // re-initialize the peripherals themselves)
    init_cycfg_ns_clocks();
    init_cycfg_ns_power();
    cycfg_config_reservations();
    // Needs to happen on every core because MPU can only be
    // initialized from the core to which it applies
    init_cycfg_protection();

    #if defined(CYBSP_POST_CFG_INIT)
    /* Perform custom initialization step */
    result = cybsp_post_cfg_init();
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }
    #endif

    #endif // (CY_SYSTEM_CPU_M33) && defined(COMPONENT_SECURE_DEVICE)
    // Always initialize peripheral-related data structures

    if (CY_RSLT_SUCCESS == result)
    {
        #if defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
        result = cybsp_register_custom_sysclk_pm_callback();
        #endif
    }

    return result;
}

#if defined(COMPONENT_MW_MTB_SRF) && !defined(MTB_SRF_CUSTOM_REQUEST_SUBMIT) && !defined(CYBSP_DISABLE_SRF_INIT)
/* Cores with TrustZone enabled will use the NSC mtb_srf_request_submit.  Other cores must use the
 * IPC-based mtb_srf_request_submit to pass the request to the NonSecure TrustZone core, whcih will
 * then submit the request through the NSC. */
#if defined(COMPONENT_SECURE_DEVICE)
//--------------------------------------------------------------------------------------------------
// mtb_srf_request_submit
//--------------------------------------------------------------------------------------------------
cy_rslt_t __attribute__((cmse_nonsecure_entry)) mtb_srf_request_submit(
    mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
    mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    return mtb_srf_request_execute(&cybsp_srf_context, inVec_ns, inVec_cnt_ns, outVec_ns,
                                   outVec_cnt_ns);
}
#endif /* defined(COMPONENT_SECURE_DEVICE) */
#if defined(COMPONENT_NON_SECURE_DEVICE) && (CY_SYSTEM_CPU_M55)
//--------------------------------------------------------------------------------------------------
// mtb_srf_request_submit
//--------------------------------------------------------------------------------------------------
cy_rslt_t mtb_srf_request_submit(
    mtb_srf_invec_ns_t* inVec_ns, uint8_t inVec_cnt_ns,
    mtb_srf_outvec_ns_t* outVec_ns, uint8_t outVec_cnt_ns)
{
    #if defined(MTB_SRF_SUBMIT_USE_IPC) && defined(COMPONENT_MW_MTB_IPC)
    return mtb_srf_ipc_request_submit(&cybsp_mtb_srf_client_context, inVec_ns, inVec_cnt_ns, outVec_ns, outVec_cnt_ns);
    #else /* defined(MTB_SRF_SUBMIT_USE_IPC) && defined(COMPONENT_MW_MTB_IPC) */
    CY_UNUSED_PARAMETER(inVec_ns);
    CY_UNUSED_PARAMETER(inVec_cnt_ns);
    CY_UNUSED_PARAMETER(outVec_ns);
    CY_UNUSED_PARAMETER(outVec_cnt_ns);
    CY_ASSERT(false);
    return MTB_SRF_ERR_UNKNOWN_OPERATION;
    #endif /* if defined(MTB_SRF_SUBMIT_USE_IPC) && defined(COMPONENT_MW_MTB_IPC) */
}

#endif // if defined(COMPONENT_NON_SECURE_DEVICE) && (CY_SYSTEM_CPU_M55)
#endif /* defined(COMPONENT_MW_MTB_SRF) && !defined(MTB_SRF_CUSTOM_REQUEST_SUBMIT) && !defined(CYBSP_DISABLE_SRF_INIT) */


#if defined(__cplusplus)
}
#endif

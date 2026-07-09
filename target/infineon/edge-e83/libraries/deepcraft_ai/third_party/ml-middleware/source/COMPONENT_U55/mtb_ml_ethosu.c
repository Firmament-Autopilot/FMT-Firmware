/***************************************************************************//**
* \file mtb_ml_ethosu.c
*
* \brief
* The file contains application programming interface to the ModusToolbox ML
* middleware ethosu module
*
*******************************************************************************
* (c) 2025-2026, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/
#include "cy_pdl.h"
#include "mtb_ml.h"
#include "pmu_ethosu.h"

#if defined(CY_RTOS_AWARE)
#include "cyabs_rtos.h"
#include "cyabs_rtos_impl.h"
#endif

void u55_irq_handler(void);
/******************************************************************************
 * Public variables
******************************************************************************/
struct ethosu_driver *mtb_ml_ethosu_driver_handle = NULL;
struct ethosu_driver ethosu_drv;

/* Populate isr configuration structure */
cy_stc_sysint_t U55_SCB_IRQ_cfg;

/** Structure to maintain data cache states. */
typedef struct _cpu_cache_state {
    uint32_t dcache_invalidated : 1;
    uint32_t dcache_cleaned : 1;
} cpu_cache_state;

/** Static CPU cache state object.
 * @note This logic around flipping these states is based on the driver
 *       calling the functions in this sequence:
 *
 *       Cache flush (ethosu_flush_dcache)
 *                  \/
 *       Start inference (ethosu_inference_begin)
 *                  \/
 *       Inference (ethosu_dev_run_command_stream)
 *                  \/
 *       End inference (ethosu_inference_end)
 *                  \/
 *       Cache invalidate (ethosu_dcache_invalidate)
 **/
/******************************************************************************
 * Static variables
******************************************************************************/
static cpu_cache_state s_cache_state = {.dcache_cleaned = 0, .dcache_invalidated = 0};
static uint32_t mtb_ml_cache_mgmt_type = MTB_ML_ETHOSU_CACHE_MGMT_TYPE;

void mtb_ml_set_cache_mgmt_type(uint32_t type)
{
    mtb_ml_cache_mgmt_type = type;
}

uint32_t mtb_ml_get_cache_mgmt_type(void)
{
    return mtb_ml_cache_mgmt_type;
}
/**
 * @brief   Gets the current CPU cache state.
 * @return  Pointer to the CPU cache state object.
 */
static cpu_cache_state* ethosu_get_cpu_cache_state(void)
{
    return &s_cache_state;
}

void ethosu_clear_cache_states(void)
{
    cpu_cache_state* state = ethosu_get_cpu_cache_state();
    /* Clearing cache state members */
    state->dcache_invalidated = 0;
    state->dcache_cleaned     = 0;
}

/*******************************************************************************
 * Private Functions
*******************************************************************************/
/* This function initializes the Ethos-U driver. */
cy_rslt_t mtb_ml_ethosu_init(struct ethosu_driver *ethosu_drv, uint32_t priority)
{

    U55_SCB_IRQ_cfg.intrSrc      = mxu55_interrupt_npu_IRQn;
    U55_SCB_IRQ_cfg.intrPriority = priority;

    /* Register the EthosU IRQ handler in our vector table.
     * Note, handler will call actual handler from the EthosU driver */
    if (Cy_SysInt_Init(&U55_SCB_IRQ_cfg, u55_irq_handler) == CY_SYSINT_BAD_PARAM)
    {
        return MTB_ML_RESULT_BAD_ARG;
    }

    /* Enable the interrupt */
    NVIC_EnableIRQ(U55_SCB_IRQ_cfg.intrSrc);

    /* Must enable peripheral before initializing driver*/
    Cy_SysEnableU55(true);

    if (0 != ethosu_init(
                ethosu_drv,                     /* Ethos-U55 driver device pointer */
                (void * const)U550_BASE,        /* Ethos-U55's base address. */
                NULL,                           /* Pointer to fast mem area - NULL for U55. */
                0,                              /* Fast mem region size. */
                MTB_ML_ETHOSU_SECURITY_ENABLE,
                MTB_ML_ETHOSU_PRIVILEGE_ENABLE))
    {
        printf("Failed to initialize Ethos-U55 device\r\n");
        return MTB_ML_RESULT_NPU_INIT_ERROR;
    }

    if (ethosu_drv != NULL)
    {
        mtb_ml_ethosu_driver_handle = ethosu_drv;
    }
    else
    {
        return MTB_ML_RESULT_NPU_INIT_ERROR;
    }

    mtb_ml_npu_clk_freq = Cy_SysClk_ClkHfGetFrequency(Cy_Sysclk_PeriPclkGetClkHfNum(PCLK_MXU55_CLK_HF));
    return MTB_ML_RESULT_SUCCESS;
}

/* This function initializes the Ethos-U driver. */
cy_rslt_t mtb_ml_ethosu_deinit()
{
    if (mtb_ml_ethosu_driver_handle == NULL)
    {
        return MTB_ML_RESULT_NPU_INIT_ERROR;
    }
    else
    {
        /* Enable the interrupt */
        NVIC_DisableIRQ(U55_SCB_IRQ_cfg.intrSrc);

        /* Disable PMU block */
        ETHOSU_PMU_Disable(mtb_ml_ethosu_driver_handle);

        ethosu_soft_reset(mtb_ml_ethosu_driver_handle);
        ethosu_deinit(mtb_ml_ethosu_driver_handle /* Ethos-U55 driver device pointer */);
        Cy_SysEnableU55(false);

        mtb_ml_ethosu_driver_handle = NULL;
    }
    return MTB_ML_RESULT_SUCCESS;
}

/*******************************************************************************
 * Extern Functions
*******************************************************************************/
void u55_irq_handler(void)
{
    ethosu_irq_handler(&ethosu_drv);
}

/*******************************************************************************
 * Strongly defined functions
*******************************************************************************/
/**
 * \brief : Strong implementation for weakly defined ethosu driver prototype for
 *          inference begin callback
 *
 * \param[in]   drv         : pointer to ethosu_driver
 * \param[in]   bytes       : pointer to user arg
 */
void ethosu_inference_begin(struct ethosu_driver *drv, void *user_arg)
{
    /* Unused */
    ((void)user_arg);

    /* Enable cycle counter */
    ETHOSU_PMU_CNTR_Enable(drv, ETHOSU_PMU_CCNT_Msk);

    /* Reset cycle counter*/
    ETHOSU_PMU_CYCCNT_Reset(drv);
}

/**
 * \brief : Strong implementation for weakly defined ethosu driver prototype for
 *          inference end callback
 *
 * \param[in]   drv         : pointer to ethosu_driver
 * \param[in]   bytes       : pointer to user arg
 */
void ethosu_inference_end(struct ethosu_driver *drv, void *user_arg)
{
    /* Unused */
    ((void)user_arg);

    ETHOSU_PMU_CNTR_Disable(drv, ETHOSU_PMU_CCNT_Msk);
    if (ETHOSU_PMU_Get_CNTR_OVS(drv) & ETHOSU_PMU_CCNT_Msk)
    {
        mtb_ml_npu_cycles = 0;
    }
    else
    {
        mtb_ml_npu_cycles += ETHOSU_PMU_Get_CCNTR(drv);
    }
}

/**
 * \brief : Strong implementation for weakly defined ethosu driver prototype for flushing
 *          dcache by real cache management.
 *
 * \param[in]   p           : Cache address to flush. Passing NULL flushes whole cache
 * \param[in]   bytes       : Amount of bytes to flush at p if non-NULL
 */
void ethosu_flush_dcache(uint32_t *p, size_t bytes)
{
    cpu_cache_state* state;
    switch(mtb_ml_cache_mgmt_type)
    {
        case MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS:
            (void)p;
            (void)bytes;
            return;
        /* recommended for smaller models */
        case MTB_ML_ETHOSU_CACHE_MGMT_ALL_LAYERS:
            if (p != NULL) {
                SCB_CleanDCache_by_Addr((void *)p, bytes);
            }
            else {
                SCB_CleanDCache();
            }
            return;
        case MTB_ML_ETHOSU_CACHE_MGMT_CONDITIONAL:
            state = ethosu_get_cpu_cache_state();
            if (SCB->CCR & SCB_CCR_DC_Msk) /* D cache is enabled */
            {    /**
                 * @note We could choose to call the `SCB_CleanDCache_by_Addr` function
                 *       here, but the sizes which this function is called for, can
                 *       cause unnecessary delays. It's worth noting that this function
                 *       is called from the Arm Ethos-U NPU drive repeatedly for each
                 *       region it accesses. This could even be RO memory which does
                 *       not need cache maintenance, along with parts of the input and
                 *       output tensors which rightly need to be cleaned. Therefore, to
                 *       reduce overhead of repeated calls for large memory sizes, we
                 *       call the clean and invalidation functions for whole cache.
                 *
                 *       If the neural network to be executed is completely falling
                 *       onto the NPU, consider disabling the data cache altogether
                 *       for the duration of the inference to further reduce the cache
                 *       maintenance burden in these functions.
                 */
                /** Clean the cache if it hasn't been cleaned already  */
                if (!state->dcache_cleaned) {
                    SCB_CleanDCache();

                    /** Assert the cache cleaned state and clear the invalidation state. */
                    state->dcache_cleaned     = 1;
                    state->dcache_invalidated = 0;
                }
            }
            return;
        default:
            /* MTB_ML_ETHOSU_CACHE_MGMT_TYPE has incorrect value */
            CY_ASSERT(0);
    }
}

/**
 * \brief : Strong implementation for weakly defined ethosu driver prototype for invalidating
 *          dcache by real cache management.
 *
 * \param[in]   p           : Cache address to invalidate. Passing NULL invalidates whole cache
 * \param[in]   bytes       : Amount of bytes to invalidate at p if non-NULL
 */
void ethosu_invalidate_dcache(uint32_t *p, size_t bytes)
{
    cpu_cache_state* state;
    switch(mtb_ml_cache_mgmt_type)
    {
        case MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS:
            (void)p;
            (void)bytes;
            return;
        /* recommended for smaller models */
        case MTB_ML_ETHOSU_CACHE_MGMT_ALL_LAYERS:
            if (p != NULL) {
                SCB_InvalidateDCache_by_Addr((void *)p, bytes);
            }
            else {
                SCB_InvalidateDCache();
            }
            return;
        case MTB_ML_ETHOSU_CACHE_MGMT_CONDITIONAL:
            state = ethosu_get_cpu_cache_state();
            if (SCB->CCR & SCB_CCR_DC_Msk) /* D cache is enabled */
            {   /**
                 * See note in ethosu_flush_dcache function for why we clean the whole
                 * cache instead of calling it for specific addresses.
                 **/
                if (!state->dcache_invalidated) {
                    /* Invalidating data cache */
                    SCB_CleanInvalidateDCache();

                    /** Assert the cache invalidation state and clear the clean
                     *  state. */
                    state->dcache_invalidated = 1;
                    state->dcache_cleaned     = 0;
                }
            }
            return;
        default:
            /* MTB_ML_ETHOSU_CACHE_MGMT_TYPE has incorrect value */
            CY_ASSERT(0);
    }
}

#if defined(CY_RTOS_AWARE)

extern void *mtb_ml_mutex_create(void);
extern int mtb_ml_mutex_lock(void *mutex);
extern int mtb_ml_mutex_unlock(void *mutex);
extern void mtb_ml_mutex_destroy(void *mutex);
extern void *mtb_ml_sem_create(void);
extern int mtb_ml_sem_take(void *sem, uint64_t timeout);
extern void mtb_ml_sem_destroy(void *sem);
/******************************************************************************
 * Semaphore/Mutex function overrides for Ethos-U NPU
 *
 * Overwrite the weak default implementations for NPU driver
 * with real mutex and semaphore implementations.
 ******************************************************************************/
void *ethosu_mutex_create(void)         { return mtb_ml_mutex_create(); }
int ethosu_mutex_lock(void *mutex)     { return mtb_ml_mutex_lock(mutex); }
int ethosu_mutex_unlock(void *mutex)   { return mtb_ml_mutex_unlock(mutex); }
void ethosu_mutex_destroy(void *mutex)   { mtb_ml_mutex_destroy(mutex); }
void *ethosu_semaphore_create(void)     { return mtb_ml_sem_create(); }
int ethosu_semaphore_take(void *sem, uint64_t timeout)  {return mtb_ml_sem_take(sem, timeout); }
void ethosu_semaphore_destroy(void *sem) { mtb_ml_sem_destroy(sem); }

/**
 * \brief : Give Ethos-U semaphore using API of RTOS abstraction.
 *
 * \param[in]   sem  : Ethos-U semaphore handle to give
 */
int ethosu_semaphore_give(void *sem)
{
    cy_semaphore_t *handle = (cy_semaphore_t *)sem;

    return (int)cy_rtos_set_semaphore(handle, 0 != __get_IPSR());

    /* The ethosu_driver has the bad habit of using the ethosu_semaphore in an unusual way:
     *
     * When the ethosu driver is reserved, ethosu_semaphore does not maintain
     * the number of free EthosU hardware and software driver resources.
     * (This is done by ethosu_find_and_reserve_driver() which has its own list of drivers.)
     * Instead, taking ethosu_semaphore just yields to the RTOS in case there is no free driver (and hardware) available.
     *
     * When the driver is released, ethosu_semaphore is given irrespective of whether it was taken or not.
     * This leads to an overflow in the semaphore counter and an error return code from xSemaphoreGive() of FreeRTOS.
     * In their code example at
     * https://review.mlplatform.org/plugins/gitiles/ml/ethos-u/ethos-u-core-platform/+/refs/heads/master/applications/freertos/main.cpp
     * Arm ignores this error code with the justification that the overflow 'does not affect the application correctness.'
     *
     * If ethosu_semaphore was used according to its natural purpose of managing the resources,
     * the overflow would not occur. This would clearly be the better solution but it
     * requires changing the ethosu_driver implementation. So, we follow the Arm approach here...
     */
}
#endif /* defined(CY_RTOS_AWARE) */

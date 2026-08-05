/***************************************************************************//**
* \file mtb_ml.h
*
* \brief
* This is the header file of ModusToolbox ML  module
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
* indemnity Cypress against all liability.
*******************************************************************************/
#if !defined(__MTB_ML_H__)
#define __MTB_ML_H__

#include "mtb_ml_common.h"
#include "mtb_ml_dataset.h"
#include "mtb_ml_model.h"
#include "mtb_ml_stream.h"
#include "mtb_ml_utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(COMPONENT_U55)
#include "ethosu_driver.h"
#include "pmu_ethosu.h"

#define MTB_ML_ETHOSU_CACHE_MGMT_CONDITIONAL    (0)
#define MTB_ML_ETHOSU_CACHE_MGMT_ALL_LAYERS     (1)
#define MTB_ML_ETHOSU_CACHE_MGMT_OUTER_LAYERS   (2)

#ifndef MTB_ML_ETHOSU_CACHE_MGMT_TYPE
#define MTB_ML_ETHOSU_CACHE_MGMT_TYPE MTB_ML_ETHOSU_CACHE_MGMT_ALL_LAYERS
#endif

void mtb_ml_set_cache_mgmt_type(uint32_t type);
uint32_t mtb_ml_get_cache_mgmt_type(void);
#endif

#if defined(COMPONENT_NNLITE2)
uint32_t Cy_NNLite_Mutex_Create(void *mutex);
uint32_t Cy_NNLite_Mutex_Lock(void *mutex);
uint32_t Cy_NNLite_Mutex_Unlock(void *mutex);
uint32_t Cy_NNLite_Mutex_Delete(void *mutex);
uint32_t Cy_NNLite_Sem_Create(void *sem);
uint32_t Cy_NNLite_Sem_Wait(void *sem);
uint32_t Cy_NNLite_Sem_Give(void *sem);
uint32_t Cy_NNLite_Sem_Delete(void *sem);
void Cy_NNLite_Lpm_Lock(void);
void Cy_NNLite_Lpm_Unlock(void);
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/
#ifdef CY_RTOS_AWARE
#if defined(COMPONENT_U55) || \
    defined(COMPONENT_NNLITE2)
#ifndef ML_NPU_MUTEX_TIMEOUT
#define ML_NPU_MUTEX_TIMEOUT CY_RTOS_NEVER_TIMEOUT
#endif

#ifndef ML_NPU_SEMAPHORE_TIMEOUT
#define ML_NPU_SEMAPHORE_TIMEOUT CY_RTOS_NEVER_TIMEOUT
#endif

#if defined(COMPONENT_U55)
#define configNPU_COUNT CY_IP_MXU55_INSTANCES
#elif defined(COMPONENT_NNLITE2)
#define configNPU_COUNT CY_IP_MXNNLITE_INSTANCES
#endif

#endif /* defined(COMPONENT_U55) || defined(COMPONENT_NNLITE2) */
#endif /* CY_RTOS_AWARE */
/******************************************************************************
 * Defines
 *****************************************************************************/
#if defined(COMPONENT_U55)

#if !defined(MTB_ML_ETHOSU_SECURITY_ENABLE)
#define MTB_ML_ETHOSU_SECURITY_ENABLE   (0)
#endif

#if !defined(MTB_ML_ETHOSU_PRIVILEGE_ENABLE)
#define MTB_ML_ETHOSU_PRIVILEGE_ENABLE  (1)
#endif

#endif

/******************************************************************************
 * Typedefs
 *****************************************************************************/

/******************************************************************************
 * Public definitions
******************************************************************************/

/******************************************************************************
 * Public variables
******************************************************************************/
extern uint32_t mtb_ml_cpu_clk_freq;
#if defined(COMPONENT_U55) || \
    defined(COMPONENT_NNLITE2)
extern uint64_t mtb_ml_npu_cycles;          /** Profiling cycles */
extern uint32_t mtb_ml_npu_clk_freq;
extern float mtb_ml_norm_clk_freq;          /** NPU : CPU clock frequency */
#endif

/******************************************************************************
 * Static variables
******************************************************************************/

/******************************************************************************
 * Structures
******************************************************************************/

/*******************************************************************************
 * Function Prototypes
*******************************************************************************/
/**
 * \addtogroup MTB_ML_API
 * @{
 */

/**
 * \brief : Initializes MTB ML Middleware.
 *
 * \param[in]   priority    : Priority of NPU IRQHandler. Ignored if no NPU component defined
 *
 * \return                  : MTB_ML_RESULT_SUCCESS - success
 */
cy_rslt_t mtb_ml_init(uint32_t priority);

/**
 * \addtogroup MTB_ML_API
 * @{
 */

/**
 * \brief : Initializes MTB ML Middleware and an NPU in case of one present.
 *
 * \param[in]   priority    : Priority of NPU IRQHandler. Ignored if no NPU component defined
 *
 * \return                  : MTB_ML_RESULT_SUCCESS - success
 */
cy_rslt_t mtb_ml_init(uint32_t priority);

/**
 * \addtogroup MTB_ML_API
 * @{
 */

/**
 * \brief : De-initializes MTB ML Middleware and an NPU in case of one present.
 *
 * \return                  : MTB_ML_RESULT_SUCCESS - success
 */
cy_rslt_t mtb_ml_deinit(void);


/**
 * \brief : Informs user if mtb_ml_init was called already (!=0) and if following calls are not redundant
 *
 * \return                  : mtb_ml_init state
 */
 uint32_t mtb_ml_get_init_state(void);

/**
 * @} end of MTB_ML_API group
 */

#if defined(__cplusplus)
}
#endif

#endif /* __MTB_ML_H__ */

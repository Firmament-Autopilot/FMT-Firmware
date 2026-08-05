/***************************************************************************//**
* \file cy_nn_kernel_private.h
* \version 1.0
*
* \brief
* Provides NNLite kernel private header file .
*
********************************************************************************
* \copyright
* Copyright 2016-2022 Cypress Semiconductor Corporation
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


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#ifndef CY_NN_KERNEL_PRIV_H
#define CY_NN_KERNEL_PRIV_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cy_pdl.h"
#ifndef CY_NNLITE_DMA_DEVICE
/* value 1, enables DMA mode API's */
#define CY_NNLITE_DMA_DEVICE  (1)
#endif

#ifndef NNLITE_DMA_CHAN
#define NNLITE_DMA_CHAN 0
#endif
#define NNLITE_DESC_LENGTH (33u)
#define DESC_COUNT_PER_LAYER (1u)
#define DMA_DESC_SIZE (sizeof(cy_stc_dma_descriptor_t) + \
                        sizeof(cy_stc_dma_descriptor_config_t))
#define MEMIO_SIZE sizeof(NNLITE_Type)

#define CY_NNLITE_DMA_SCRATCH_BUFFER_SIZE (MEMIO_SIZE + (DMA_DESC_SIZE * DESC_COUNT_PER_LAYER))


/*****************************************************************************
 ** \brief nnlite kernel context structure
 *****************************************************************************/
typedef struct cy_kernel_context
{
  void *nnliteMutex; /** Mutex to be allocated in RTOS environment */
  void *nnliteSem; /** Semaphore to be allocated in RTOS environment */
  Cy_NNLite_CompletionCallback completionCbFunc; /**< Kernel completion called back
                        function, to filled by upper layer, should not
                        have/call blocking implementation*/
  Cy_NNLite_CompletionCallback suspendedCbFunc; /**< Kernel completion callback suspended
                        during execution of internal ops of multi-op kernel*/
  void *cbArg; /**< argument with which callback function will be called */
  Cy_NNLite_MutexCreate mutexCreateFunc; /**< Mutex Create function pointer */
  Cy_NNLite_MutexDelete mutexDeleteFunc; /**< Mutex Delete function pointer */
  Cy_NNLite_MutexLock mutexLockFunc; /**< Mutex Lock function pointer */
  Cy_NNLite_MutexUnlock mutexUnlockFunc; /**< Mutex Unlock function pointer */
  Cy_NNLite_SemCreate SemCreateFunc; /**< Sem Create function pointer */
  Cy_NNLite_SemDelete SemDeleteFunc; /**< Sem Delete function pointer */
  Cy_NNLite_SemWait SemWaitFunc; /**< Sem wait function pointer */
  Cy_NNLite_SemGive SemGiveFunc; /**< Sem give function pointer */
  Cy_NNLite_LpmLock LpmLockFunc; /**< LPM lock function pointer */
  Cy_NNLite_LpmUnlock LpmUnlockFunc; /**< LPM unlock function pointer */
  Cy_NNLite_ProfileStart profStart; /**< profiler start */
  Cy_NNLite_ProfileGetCount profGetCount; /**< get count intermediate profile points */
  Cy_NNLite_ProfileStop profStop; /**< profiler end */
  void *profArg; /**< argument with which profiler callback functions will be called */
  cy_nnlite_context_t pdlContext; /**< nnlite pdl context structure*/
} cy_kernel_context_t;

/**
 * @brief Start of execution of multi-operation kernel
 *
 * This forces each operation kernel to wait for completion before exiting.
 *
 */
void Cy_NNLite_StartMacroKernel(void);

/**
 * @brief End of execution of multi-operation kernel
 *
 * This restores original completion behaviour and calls completion callback
 * (if defined)
 *
 */

void Cy_NNLite_EndMacrokernel(void);

static inline void nop_lpm(void)
{
}

static inline void nop_prof(void *ptr) {
  (void)ptr;
}

static inline void nop_prof_getcount(void *ptr, uint32_t profilePoint)
{
  (void)ptr;
  (void)profilePoint;
}

/**
 *****************************************************************************
 ** \brief API will initialize DMA Channel with DMA descriptor
 **
 ** \param [in]  channelConfig DMA channel configuration
 ** \param [in]  desc dma descriptor
 **
 *****************************************************************************/
void Cy_NNLite_DMAChannelInit(cy_stc_dma_channel_config_t *channelConfig,
                               cy_stc_dma_descriptor_t *desc);

/**
 *****************************************************************************
 ** \brief API will Link DMA Descriptor in DMA Queue and will update
 ** prev and curr desc pointer in nnliteDMAQ structure
 **
 ** \param [in]  dmaQueue DMA channel queue configuration
 ** \param [in]  desc dma descriptor
 ** \param [in]  cfgDesc dma config descriptor
 ** \param [in]  descCount array count of desc to be linked
 **
 *****************************************************************************/
void Cy_NNLite_LinkDMADesc(cy_nnlite_dma_queue_config_t *dmaQueue,
         cy_stc_dma_descriptor_t *des,
         cy_stc_dma_descriptor_config_t *cfgDesc,
         uint8_t cnt);

/**
 *****************************************************************************
 ** \brief API will setup DMA Descriptors for kernel layer
 **
 ** \param [in]  nnliteMemio NNLite MEMIO structure for DMA mode
 ** \param [in]  dmaQueue DMA channel queue configuration
 ** \param [in]  cfgDesc dma config descriptor
 ** \param [in]  desc dma descriptor
 **
 ** \retval status value
 *****************************************************************************/
void Cy_NNLite_SetupNNLiteMemioDMADesc(
                                 NNLITE_Type *Memio,
                                 cy_nnlite_dma_queue_config_t *dmaQueue,
                                 cy_stc_dma_descriptor_config_t *cfgDesc,
                                 cy_stc_dma_descriptor_t *desc);

/**
 *****************************************************************************
 ** \brief API will Cleanup DMA Queue
 **
 ** \param [in]  nnliteDMAQ structure maintaining DMA Queue pointers
 **
 *****************************************************************************/
void Cy_NNlite_MarkDMAQueueEmpty(cy_nnlite_dma_queue_config_t *nnliteDMAQ);

#ifdef __cplusplus
}
#endif

#endif // CY_NN_KERNEL_PRIV_H


/***************************************************************************//**
* \file cy_nn_kernel_private_v1.h
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


/**Get Minimum of two value */
#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

#define NNLITE_DMA_CHAN 0
#define TOTAL_LENGTH (sizeof(cy_nnlite_memio_dma_t) / sizeof(uint32_t))
#define NNLITE_DESC_1_LENGTH (8u)
#define NNLITE_DESC_0_LENGTH (TOTAL_LENGTH - NNLITE_DESC_1_LENGTH)
#define DESC_COUNT_PER_LAYER (2u)
#define DMA_DESC_SIZE (sizeof(cy_stc_dma_descriptor_t) + \
                        sizeof(cy_stc_dma_descriptor_config_t))

/** All-ones weights for AvgPool execution. */
/** @note These  are best held in non-volatile "code" memory as the
 * NNLite's bus connectivity is optimized for this.  Held in SRAM banks will result in
 * heavy contention between the weight and activation streaming engines.
 */
static const int8_t weightPtrConstBuffer[] = \
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

/* nnlite kernel profiling macros place holders*/


/*****************************************************************************
 ** \brief DMA  Transpose MODE
 **
 *****************************************************************************/
typedef enum
{
  CY_NNLITE_DMA_HWC_TO_CHW = 0,
  CY_NNLITE_DMA_CHW_TO_HWC = 1,
} cy_nnlite_dma_xmode_t;

/*****************************************************************************
 ** \brief nnlite kernel context structure
 *****************************************************************************/
typedef struct cy_kernel_context
{
  void *nnliteMutex; /** Mutex to be allocated in RTOS environment */
  void *nnliteSem; /** Semaphore to be allocated in RTOS environment */
  bool waitForCompletion; /**< this flag is used by kernel for intermediate
                            operations where we need to wait for completion*/
  Cy_NNLite_CompletionCallback completionCbFunc; /**< Kernel completion called back
                        function, to filled by upper layer, should not
                        have/call blocking implementation*/
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

/*****************************************************************************
 ** \brief nnlite memio configuration structure to be used for DMA
 ** As INTERPOLATIONLUTADDR need to be programmed twice MXNNLITE_1_0_Type can
 **  not be used for DMA
 *****************************************************************************/
typedef struct cy_nnlite_memio_dma
{
  uint32_t WEIGHTSTREAMERBASEADDR;
  uint32_t WEIGHTSTREAMEROFFSET;
  uint32_t WEIGHTSTREAMERKERNELCHANNELTIMESHEIGHTTIMESWIDTH;
  uint32_t ACTIVATIONSTREAMERBASEADDR;
  uint32_t ACTIVATIONSTREAMEROFFSET;
  uint32_t ACTIVATIONSTREAMERKERNELCHANNELTIMESWIDTH;
  uint32_t ACTIVATIONSTREAMERKERNELHEIGHT;
  uint32_t ACTIVATIONSTREAMERREPEATS;
  uint32_t ACTIVATIONSTREAMERSTARTCOL;
  uint32_t ACTIVATIONSTREAMERSTARTROW;
  uint32_t ACTIVATIONSTREAMERCHANNELTIMESWIDTH;
  uint32_t ACTIVATIONSTREAMERHEIGHT;
  uint32_t ACTIVATIONSTREAMERPADDING;
  uint32_t ACTIVATIONSTREAMERSPARSITYMAPBASEADDR;
  uint32_t OUTSTREAMERBASEADDR;
  uint32_t OUTSTREAMEROUTPUTOFFSET;
  uint32_t OUTSTREAMERSCALINGFACTOR;
  uint32_t OUTSTREAMERCLIPPINGMASK;
  uint32_t BIASBASEADDR;
  uint32_t STREAMERMODES;
  uint32_t NONZEROWEIGHTSPOINTER;
  uint32_t OUTPUTWIDTH;
  uint32_t OUTPUTHEIGHT;
  uint32_t STRIDE;
  uint32_t INTERPOLATIONLUTADDR0;
  uint32_t INTERPOLATIONLUTWDATA0;
  uint32_t INTERPOLATIONLUTADDR1;
  uint32_t INTERPOLATIONLUTWDATA1;
  uint32_t NNLAYER_ACTIVATION_TYPE_CTL;
  uint32_t INTR;
  uint32_t INTR_SET;
  uint32_t INTR_MASK;
  uint32_t TRIG_MASK;
  uint32_t CMD;
} cy_nnlite_memio_dma_t;


/**
 *****************************************************************************
 ** \brief API will setup transpose DMA Descriptors
 **
 ** \param [in]  dmaQueue DMA channel queue configuration
 ** \param [in]  srcAddress source address
 ** \param [in]  dstAddress destination address
 ** \param [in]  heightTimeWidth height times width
 ** \param [in]  channel channel or output depth
 ** \param [in]  cfgDesc dma configuration descriptor
 ** \param [in]  desc dma descriptor
 ** \param [in]  descCnt count for pair of cfgDesc and desc
 ** \param [in]  transpose mode
 **
 *****************************************************************************/
void
Cy_NNLite_SetupTransposeDMADesc(cy_nnlite_dma_queue_config_t *dmaQueue,
                                int8_t *src, int8_t *dst,
                                uint32_t heightTimeWidth, uint32_t channel,
                                cy_stc_dma_descriptor_config_t *cfgDesc,
                                cy_stc_dma_descriptor_t *desc,
                                uint8_t descCnt, cy_nnlite_dma_xmode_t mode);

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
 ** \brief API will Trigger Transpose DMA, only used for CPU mode convolution,
 ** In pure DMA mode, transpose descriptor will be linked with
 ** convolution
 **
 ** \param [in]  channelConfig DMA channel configuration
 ** \param [in]  desc dma descriptor
 **
 *****************************************************************************/
void Cy_NNLite_TriggerTransposeDMA(cy_stc_dma_channel_config_t *channelConfig,
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
                                 cy_nnlite_memio_dma_t *nnliteMemio,
                                 cy_nnlite_dma_queue_config_t *dmaQueue,
                                 cy_stc_dma_descriptor_config_t *cfgDesc,
                                 cy_stc_dma_descriptor_t *desc);
/**
 *****************************************************************************
 ** \brief static API to get transpose descriptor count based on dimension
 **
 ** \param [in]  heightTimeWidth height times width
 ** \param [in]  channel channel or output depth
 **
 ** \retval transpose descriptor count
 *****************************************************************************/
static inline uint32_t
Cy_NNLite_GetTransposeDescCount(uint32_t heightTimeWidth, uint32_t channel)
{
  uint32_t transposeDesCount;
  /* need to split in multi 1D transfer when
   heightTimeWidth greater then max Loop increment */
  if (heightTimeWidth > CY_DMA_LOOP_INCREMENT_MAX)
  {
    transposeDesCount = ((heightTimeWidth + CY_DMA_LOOP_COUNT_MAX - 1) /
        CY_DMA_LOOP_COUNT_MAX) * channel;
  }
  else /* 2D DMA transfer for transpose */
  {
    transposeDesCount = (heightTimeWidth + (CY_DMA_LOOP_COUNT_MAX - 1)) /
      CY_DMA_LOOP_COUNT_MAX;
  }
  return transposeDesCount;
}

/**
 *****************************************************************************
 ** \brief API will Cleanup DMA Queue
 **
 ** \param [in]  nnliteDMAQ structure maintaining DMA Queue pointers
 **
 *****************************************************************************/
void Cy_NNlite_MarkDMAQueueEmpty(cy_nnlite_dma_queue_config_t *nnliteDMAQ);

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
#ifdef __cplusplus
}
#endif
#endif

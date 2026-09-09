/***************************************************************************//**
 * \file  cy_nn_kernel.c
 * \version 1.0
 *
 * \brief
 * Provides an Kernel API implementation of the nnlite accelerator.
 *
 ********************************************************************************
 * \copyright
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
#include "cy_nn_kernel.h"
#if CY_IP_MXNNLITE_VERSION == 1
#include "cy_nn_kernel_private_v1.h"
#include <string.h>
#include <stdlib.h>

/** RELU intercept for left quadrant */
#define CY_NN_KERNEL_RELU_INTERCEPT_0 (0U)
/** RELU intercept for right quadrant */
#define CY_NN_KERNEL_RELU_INTERCEPT_1 (0U)

/** RELU slope for left quadrant */
#define CY_NN_KERNEL_RELU_SLOPE_0 (0U)
/** RELU slope for right quadrant */
/** value (1) in float 32 bits (IEE754)
 * lower 16 bits needs to be dropped
 */
#define CY_NN_KERNEL_RELU_SLOPE_1 (0x3f80U)

/** Leaky RELU intercept for left quadrant */
#define CY_NN_KERNEL_LRELU_INTERCEPT_0 (0U)
/** Leaky RELU intercept for right quadrant */
#define CY_NN_KERNEL_LRELU_INTERCEPT_1 (0U)

/** Leaky RELU slope for left quadrant */
/** value (0.01) in float 32 bits (IEE754)
 * lower 16 bits needs to be dropped
 */
#define CY_NN_KERNEL_LRELU_SLOPE_0 (0x3c23U)
/** Leaky RELU slope for right quadrant */
/** value (1) in float 32 bits (IEE754)
 * lower 16 bits needs to be dropped
 */
#define CY_NN_KERNEL_LRELU_SLOPE_1 (0x3f80U)
#define MXNNLITE_REGS                            ((MXNNLITE_1_0_Type*) MXNNLITE_1_0_BASE)
static cy_nnlite_dma_queue_config_t nnliteDMAQ = {0};
static cy_nnlite_dma_queue_config_t *currDMAQ = &nnliteDMAQ;
static cy_kernel_context_t kernelContext = {0};
static int8_t *AvgPoolWeightArrayPtr;
static uint32_t AvgPoolWeightArraySize;

/**
 *****************************************************************************
 ** \brief  A function set "virtual-weights" array's pointer and size for
 ** average pooling cases when valid pointer and size is passed, in case of
 ** NULL pointer or 0 size array's pointer will be reset to default value
 ** pointer should not be freed until AvgPool weight pointer is reset to
 ** default by calling same API with NULL pointer value or 0 size in argument
 *****************************************************************************/
cy_en_nnlite_status_t  Cy_NNLite_SetAvgPoolKernelWeightArrayPtr(
                int8_t *weightsArrayPtr, uint32_t weightsArraySize)
{
  if (kernelContext.mutexLockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }

  if ((weightsArrayPtr != NULL) && (weightsArraySize != 0U))
  {
    AvgPoolWeightArrayPtr = (int8_t *)weightsArrayPtr;
    AvgPoolWeightArraySize = weightsArraySize;
  }
  else /* reset to default */
  {
    AvgPoolWeightArrayPtr = (int8_t *)weightPtrConstBuffer;
    AvgPoolWeightArraySize = sizeof(weightPtrConstBuffer)/sizeof(int8_t);
  }

  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    return  CY_NNLITE_EXTERN_API_ERR;
  }
  else
  {
    return CY_NNLITE_SUCCESS;
  }
}

/**
 *****************************************************************************
 ** \brief  A function which returns a "virtual-weights" array's size for
 ** average pooling cases
 *****************************************************************************/
uint32_t Cy_NNLite_GetAvgPoolKernelWeightSize(void)
{
  return AvgPoolWeightArraySize;
}

/**  ************************************************************************
** \brief  All-ones const weights array used by AvgPool
** Size is returned by \c Cy_NNLite_GetAvgPoolKernelWeightSize
** These  are best held in non-volatile "code" memory as the
** NNLite's bus connectivity is optimized for this.
** Held in SRAM banks will result in heavy contention
** between the weight and activation streaming engines.
*****************************************************************************/
int8_t *Cy_NNLite_GetAvgPoolKernelWeightPtr()
{
  return AvgPoolWeightArrayPtr;
}

/**
 *****************************************************************************
 ** \brief  NNLite ISR, Error or completion interrupt
 ** calls completion handles functions
 **
 *****************************************************************************/
static void Cy_NNLite_Isr(void)
{
  cy_en_nnlite_status_t status;
  if (currDMAQ->dmaQDepth &&
      (currDMAQ->dmaQState == CY_NNLITE_DMA_QUEUE_TRIGGERED) &&
       (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_STARTED))
  {
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_DMA_MODE_END);
    currDMAQ->dmaQState = CY_NNLITE_DMA_QUEUE_DONE;
    Cy_DMA_Channel_ClearInterrupt(DW0, NNLITE_DMA_CHAN);
  }
  else
  {
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_DONE);
  }
  Cy_NNLite_InterruptHandler(MXNNLITE_1_0, &kernelContext.pdlContext);
  if (kernelContext.waitForCompletion)
  {
    status = (cy_en_nnlite_status_t)kernelContext.SemGiveFunc(kernelContext.nnliteSem);
    if (status != CY_NNLITE_SUCCESS)
    {
      kernelContext.pdlContext.opStatus = CY_NNLITE_EXTERN_API_ERR;
    }
    kernelContext.LpmUnlockFunc();
  }
  else if (kernelContext.completionCbFunc)
  {
    kernelContext.completionCbFunc(
        kernelContext.cbArg,
        kernelContext.pdlContext.opStatus);
    kernelContext.LpmUnlockFunc();
  }
}

/**
 *****************************************************************************
 ** \brief  DMA ISR transpose  completion for CPU mode or
 ** full layer for DMA mode, calls completion handles functions
 **
 *****************************************************************************/
static void Cy_NNLite_DMAIsr(void)
{
  cy_en_nnlite_status_t status;
  Cy_DMA_Channel_ClearInterrupt(DW0,  NNLITE_DMA_CHAN);

  if (currDMAQ->dmaQDepth &&
      (currDMAQ->dmaQState == CY_NNLITE_DMA_QUEUE_TRIGGERED) &&
       (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_STARTED))
  {
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_DMA_MODE_END);
    currDMAQ->dmaQState = CY_NNLITE_DMA_QUEUE_DONE;
    /*
    this is case for DMA mode API and last operation is DMA transpose
    get nnlite operation status.
    */
    Cy_NNLite_InterruptHandler(MXNNLITE_1_0, &kernelContext.pdlContext);
    kernelContext.LpmUnlockFunc();
  }
  else /* this is case CPU mode, followed by DMA transpose */
  {
  kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_TRANSPOSE_DONE);
    kernelContext.pdlContext.nnliteState = CY_NNLITE_OP_DONE;
  }

  if (kernelContext.waitForCompletion)
  {
    status = (cy_en_nnlite_status_t)kernelContext.SemGiveFunc(kernelContext.nnliteSem);
    if (status != CY_NNLITE_SUCCESS)
    {
      kernelContext.pdlContext.opStatus = CY_NNLITE_EXTERN_API_ERR;
    }
  }
  else if (kernelContext.completionCbFunc)
  {
    kernelContext.profStop(kernelContext.profArg);
    kernelContext.completionCbFunc(
        kernelContext.cbArg,
        kernelContext.pdlContext.opStatus);
  }

}

/**
 *****************************************************************************
 ** \brief  Kernel Init API, initializes PDL driver and setup IRQ handler and
 ** setup function pointers from kernelConfig argument. KernelConfig should
 ** have valid pointer for Mutex variable and function pointers for
 ** mutexCreate, mutexDelete, mutexLock, mutexUnlock and and should have valid
 ** pointers for Semaphore variable and function pointers for SemCreate,
 ** SemDelete, SemWait and SemGive for synchronization primitives. This API will
 ** allocate mutex and semaphore by calling mutexCreate and SemCreate, and will
 ** use them in successive call to other kernel public API's. API needs to be
 ** called before calling any other kernel API, If any of the pointers in
 ** KernelConfig is not valid API will return error code ,return value of API
 ** should be check to confirm successful initialization.
 **
 ** [in]  kernelConfig kernel function pointers configuration structure
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_KernelInit(cy_kernel_config_t *kernelConfig)
{
  cy_en_nnlite_status_t status;

  /* Populate isr configuration structure */
  cy_stc_sysint_t NNLITE_IRQ_cfg =
  {
    .intrSrc      = mxnnlite_interrupt_mxnnlite_IRQn,
    .intrPriority = NNLITE_DEFAULT_ISR_PRIORITY,
  };
  cy_stc_sysint_t DMA_IRQ_cfg = {
  .intrSrc =
   ((IRQn_Type)(m33syscpuss_interrupts_dw0_0_IRQn + NNLITE_DMA_CHAN)),
  .intrPriority = NNLITE_DEFAULT_ISR_PRIORITY,
  };

  /* check for valid kernel context */

  if ((kernelConfig == NULL) || (kernelConfig->mutexCreateFunc == NULL) ||
      (kernelConfig->mutexLockFunc == NULL) || (kernelConfig->mutexUnlockFunc == NULL) ||
      (kernelConfig->SemCreateFunc == NULL) || (kernelConfig->SemWaitFunc == NULL) ||
      (kernelConfig->SemGiveFunc == NULL))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else
  {
    kernelContext.nnliteMutex = kernelConfig->nnliteMutex;
    kernelContext.mutexCreateFunc = kernelConfig->mutexCreateFunc;
    kernelContext.mutexDeleteFunc = kernelConfig->mutexDeleteFunc;
    kernelContext.mutexLockFunc = kernelConfig->mutexLockFunc;
    kernelContext.mutexUnlockFunc = kernelConfig->mutexUnlockFunc;

    kernelContext.nnliteSem = kernelConfig->nnliteSem;
    kernelContext.SemCreateFunc = kernelConfig->SemCreateFunc;
    kernelContext.SemDeleteFunc = kernelConfig->SemDeleteFunc;
    kernelContext.SemWaitFunc = kernelConfig->SemWaitFunc;
    kernelContext.SemGiveFunc = kernelConfig->SemGiveFunc;

    status = (cy_en_nnlite_status_t)kernelContext.mutexCreateFunc(kernelContext.nnliteMutex);
    if (status == CY_NNLITE_SUCCESS)
    {
      status = (cy_en_nnlite_status_t)kernelContext.SemCreateFunc(kernelContext.nnliteSem);
      if (status == CY_NNLITE_SUCCESS)
      {
        kernelContext.completionCbFunc = kernelConfig->completionCbFunc;
        kernelContext.cbArg = kernelConfig->cbArg;
        status = Cy_NNLite_Init(MXNNLITE_1_0, &kernelContext.pdlContext);
        if (status == CY_NNLITE_SUCCESS)
        {
          Cy_NNLite_SetInterruptMask(MXNNLITE_1_0, 0);
          Cy_DMA_Enable(DW0);
          Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
          Cy_TrigMux_Connect(PERI_0_TRIG_IN_MUX_0_MXNNLITE_TR_MXNNLITE,
                  PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN0 + NNLITE_DMA_CHAN,
                  false, TRIGGER_TYPE_LEVEL);
          if ((kernelConfig->intrPriority != 0) &&
                CY_SYSINT_IS_PRIORITY_VALID(kernelConfig->intrPriority))
          {
            NNLITE_IRQ_cfg.intrPriority = kernelConfig->intrPriority;
            DMA_IRQ_cfg.intrPriority = kernelConfig->intrPriority;
          }
          Cy_SysInt_Init(&NNLITE_IRQ_cfg, Cy_NNLite_Isr);
          Cy_SysInt_Init(&DMA_IRQ_cfg, Cy_NNLite_DMAIsr);
          /* Enable the interrupt */
          NVIC_EnableIRQ(NNLITE_IRQ_cfg.intrSrc);
          NVIC_EnableIRQ(DMA_IRQ_cfg.intrSrc);
          /* enable nnlite from SCTL */
          Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_MXNNLITE_PERI_NR,
            CY_MMIO_MXNNLITE_GROUP_NR, CY_MMIO_MXNNLITE_SLAVE_NR,
            CY_MMIO_MXNNLITE_CLK_HF_NR);
          AvgPoolWeightArrayPtr = (int8_t *)weightPtrConstBuffer;
          AvgPoolWeightArraySize = sizeof(weightPtrConstBuffer)/sizeof(int8_t);
        }
        else /* NNLite Init failed, delete sem and mutex created */
        {
          kernelContext.mutexDeleteFunc(kernelContext.nnliteMutex);
          kernelContext.SemDeleteFunc(kernelContext.nnliteSem);
        }
      }
      else /* sem create failed, delete mutex created earlier */
      {
        status = CY_NNLITE_EXTERN_API_ERR;
        kernelContext.mutexDeleteFunc(kernelContext.nnliteMutex);
      }

    if (kernelConfig->LpmLockFunc != NULL)
    {
      kernelContext.LpmLockFunc = kernelConfig->LpmLockFunc;
      kernelContext.LpmUnlockFunc = kernelConfig->LpmUnlockFunc;
    }
    else
    {
      kernelContext.LpmLockFunc = nop_lpm;
      kernelContext.LpmUnlockFunc = nop_lpm;
    }

    if (kernelConfig->profStart!= NULL)
    {
      kernelContext.profStart = kernelConfig->profStart;
      kernelContext.profGetCount = kernelConfig->profGetCount;
      kernelContext.profStop = kernelConfig->profStop;
      kernelContext.profArg = kernelConfig->profArg;
    }
    else
    {
      kernelContext.profStart = nop_prof;
      kernelContext.profStop = nop_prof;
      kernelContext.profGetCount = nop_prof_getcount;
    }

    }
    else
    {
      status = CY_NNLITE_EXTERN_API_ERR;
    }
  }

  return status;
}

/**
 *****************************************************************************
 ** \brief  Kernel Deinit API, de-initialize PDL driver and synchronization
 ** primitives. needs re initialization after this API is called. Should be
 ** called only at end of program
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_KernelDeInit(void)
{
  cy_en_nnlite_status_t status;
  status = Cy_NNLite_DeInit(MXNNLITE_1_0, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
    Cy_NNLite_SetInterruptMask(MXNNLITE_1_0, 0);
    /* Disable the interrupt */
    NVIC_DisableIRQ(mxnnlite_interrupt_mxnnlite_IRQn);
    NVIC_DisableIRQ((IRQn_Type)(m33syscpuss_interrupts_dw0_0_IRQn + NNLITE_DMA_CHAN));

    status |= kernelContext.mutexDeleteFunc(kernelContext.nnliteMutex);
    status |= kernelContext.SemDeleteFunc(kernelContext.nnliteSem);
    if (status != CY_NNLITE_SUCCESS)
    {
      status = CY_NNLITE_EXTERN_API_ERR;
    }
     /* disable nnlite from SCTL */
    Cy_SysClk_PeriGroupSlaveDeinit(CY_MMIO_MXNNLITE_PERI_NR,
       CY_MMIO_MXNNLITE_GROUP_NR, CY_MMIO_MXNNLITE_SLAVE_NR);
  }

  return status;
}

/**
 *****************************************************************************
 ** \brief  static function  to check if all scaling factors are equal
 **
 ** [in]  scalingFactor array pointer
 ** [in]  count number of scalingFactor
 *****************************************************************************/
static bool isScalingFactorEqual(float *scalingFactor, int count)
{
#if 0 /* Disable equal scaling factor optimization */
  float scaling;
  bool status;
  scaling = scalingFactor[0];
  status = true;
  for (int i = 1;  i < count; i++)
  {
    if (scaling != scalingFactor[i])
    {
      status = false;
      break;
    }
  }
  return status;
#else
  (void)scalingFactor;
  if (count > 1)
  {
    return false;
  }
  else
  {
    return true;
  }
#endif
}

/**
 *****************************************************************************
 ** \brief  parse and fill interpolation param based on activation type
 **
 ** [in]  actType activation  type
 ** [in]  inParam input interpolation param
 ** [out] outParam resultant interpolation param
 *****************************************************************************/
static void
Cy_NNLite_ParaseInterpolationParam(cy_en_nnlite_fused_activation_t actType,
                                 cy_nn_act_intrpl_param_t *inParam,
                                 cy_nn_act_intrpl_param_t *outParam)
{
  if(NULL != inParam)
  {
    outParam->intercept0 = inParam->intercept0;
    outParam->intercept1 = inParam->intercept1;
    outParam->slope0 = inParam->slope0;
    outParam->slope1 = inParam->slope1;
  }
  else if (actType == CY_NNLITE_ACTIVATION_RELU)
  {
    outParam->intercept0 = CY_NN_KERNEL_RELU_INTERCEPT_0;
    outParam->intercept1 = CY_NN_KERNEL_RELU_INTERCEPT_1;
    outParam->slope0 = CY_NN_KERNEL_RELU_SLOPE_0;
    outParam->slope1 = CY_NN_KERNEL_RELU_SLOPE_1;
  }
  else
  {
    outParam->intercept0 = CY_NN_KERNEL_LRELU_INTERCEPT_0;
    outParam->intercept1 = CY_NN_KERNEL_LRELU_INTERCEPT_1;
    outParam->slope0 = CY_NN_KERNEL_LRELU_SLOPE_0;
    outParam->slope1 = CY_NN_KERNEL_LRELU_SLOPE_1;
  }
}

/**
 *****************************************************************************
 ** \brief Transpose function for without using DMA
 **
 ** [in]  srcBuf source buffer
 ** [out] dstBuf destination buffer for transpose
 ** [in]  heightTimeWidth height times width of input
 ** [in]  channel/depth of input
 ** [in]  transpose mode
 *****************************************************************************/
static void Cy_NNLite_Transpose_Non_DMA(int8_t *srcBuf,
    int8_t *dstBuf, uint32_t heightTimeWidth,
    uint32_t channel, cy_nnlite_dma_xmode_t mode)
{
  size_t yIdx;
  size_t xIdx;
  size_t outMajorSize;
  size_t outMinorSize;
  switch(mode) {
    case CY_NNLITE_DMA_HWC_TO_CHW:
      outMajorSize = channel;
      outMinorSize = heightTimeWidth;
      break;
    case CY_NNLITE_DMA_CHW_TO_HWC:
      outMajorSize = heightTimeWidth;
      outMinorSize = channel;
      break;
    default:
      abort();
  }
  for (yIdx = 0; yIdx < outMajorSize; yIdx++) {
      for (xIdx = 0; xIdx < outMinorSize; xIdx++) {
        dstBuf[xIdx + yIdx * outMinorSize ] =
          srcBuf[xIdx * outMajorSize + yIdx];
      }
  }
  // Need to trigger completion callback!
  Cy_NNLite_DMAIsr();

}

/**
 *****************************************************************************
 ** \brief Transpose function for CPU mode convolution kernel
 **
 ** [in]  srcBuf source buffer
 ** [out] dstBuf destination buffer for transpose
 ** [in]  scratchBuf scratch buffer base for transpose
 ** [in]  heightTimeWidth height times width of input
 ** [in]  channel/depth of input
 ** [in]  transpose mode
 *****************************************************************************/
static void Cy_NNLite_Transpose(int8_t *srcBuf,
    int8_t *dstBuf, int8_t *scratchBuf, uint32_t heightTimeWidth,
    uint32_t channel, cy_nnlite_dma_xmode_t mode)
{
#ifdef USE_NON_DMA_XPOSE
  (void)scratchBuf;
 Cy_NNLite_Transpose_Non_DMA(srcBuf, dstBuf, heightTimeWidth, channel, mode);

#else
  uint8_t descCnt;
  int32_t outBufLen;
  cy_stc_dma_descriptor_t *desc;
  cy_stc_dma_descriptor_config_t *cfgDesc;

  if (channel > CY_DMA_LOOP_COUNT_MAX)
  {
    Cy_NNLite_Transpose_Non_DMA(srcBuf, dstBuf, heightTimeWidth, channel, mode);
  }
  else
  {
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_TRANSPOSE_START);
    outBufLen = ((heightTimeWidth * channel ) + 3) & (~3);
    /* get DMA descriptor count based on dimensions*/
    descCnt = Cy_NNLite_GetTransposeDescCount(heightTimeWidth, channel);
    cfgDesc = (cy_stc_dma_descriptor_config_t *)
          ((uint32_t)scratchBuf + outBufLen);
    desc = (cy_stc_dma_descriptor_t *)(cfgDesc + descCnt);
    /*
    setup DMA descriptor for transpose operation
    if heightTimeWidth < CY_DMA_LOOP_COUNT_MAX, it will be
    2D DMA transfer, else 1D DMA
    */
    Cy_NNLite_SetupTransposeDMADesc(&nnliteDMAQ, srcBuf,
                                    dstBuf, heightTimeWidth,
                                    channel, cfgDesc,
                                    desc, descCnt, mode);
    currDMAQ = &nnliteDMAQ;
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_TRANSPOSE_DMA_TRIGGER);
    /* Start DMA, completion callback will be called from DMA ISR */
    Cy_NNLite_TriggerTransposeDMA(&nnliteDMAQ.channelConfig, desc);
  }
#endif
}


/**
 *****************************************************************************
 ** \brief Transpose function for DMA mode convolution kernel
 **
 ** [in]  srcBuf source buffer and scratch buffer for transpose
 ** [out] dstBuf destination buffer for transpose
 ** [in]  scratchBuf scratch buffer base for transpose
 ** [in]  heightTimeWidth height times width of input
 ** [in]  channel/depth of input
 ** [in]  transpose mode
 *****************************************************************************/
static void Cy_NNLite_LinkTransposeDMA(int8_t *srcBuf,
    int8_t *dstBuf, int8_t *scratchBuf, uint32_t heightTimeWidth,
    uint32_t channel, cy_nnlite_dma_xmode_t mode)
{
  uint8_t descCnt;
  int32_t outBufLen;
  cy_stc_dma_descriptor_t *desc;
  cy_stc_dma_descriptor_config_t *cfgDesc;

  outBufLen = ((heightTimeWidth * channel ) + 3) & (~3);
  /* get DMA descriptor count based on dimensions*/
  descCnt = Cy_NNLite_GetTransposeDescCount(heightTimeWidth, channel);
  cfgDesc = (cy_stc_dma_descriptor_config_t *)
    ((uint32_t)scratchBuf + outBufLen);
  desc = (cy_stc_dma_descriptor_t *)(cfgDesc + descCnt);

  if (nnliteDMAQ.dmaQState == CY_NNLITE_DMA_QUEUE_DONE)
  {
    /* new queue setup*/
    Cy_NNlite_MarkDMAQueueEmpty(&nnliteDMAQ);
  }
  /*
   setup DMA descriptor for transpose operation
   if heightTimeWidth < CY_DMA_LOOP_COUNT_MAX, it will be
   2D DMA transfer, else 1D DMA
  */
  Cy_NNLite_SetupTransposeDMADesc(&nnliteDMAQ, srcBuf,
                                  dstBuf, heightTimeWidth,
                                  channel, cfgDesc,
                                  desc, descCnt, mode);
  nnliteDMAQ.currDescType = CY_NNLITE_DMA_DESC_TRANSPOSE;
  Cy_NNLite_LinkDMADesc(&nnliteDMAQ, desc, cfgDesc, descCnt);
}

/**
 *****************************************************************************
 ** \brief 2D Convolution CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 ** intrplParam can be passed as NULL for default behavior of activation,
 ** to parametrize activation pass valid  intrplParam.
 ** filterData points to weights if sparsityBaseAddr is NULL otherwise weights
 ** pointer will be derived from sparsityBaseAddr and filterData will
 ** not be used.
 ** Valid scratch buffer should be passed in convParam, scratch buffer will be
 ** used for transpose operation (transpose scratch buffer and transpose DMA
 ** descriptors)for per axis convolution implementation, size of scratch buffer
 ** should be derived by calling function Cy_NNLite_ConvolutionScratchBufSize.
 ** Scratch buffer can be freed after receiving completion callback of API.
 **
 ** [in]  inputData        activation buffer pointer
 **
 ** [in]  outData         output buffer pointer
 **
 ** [in]  inputDims        activation dimension pointer
 **
 ** [in]  outpututDims     output dimension pointer
 **
 ** [in]  filterDims       filter dimension pointer
 **
 ** [in]  filterData       filter pointer
 **
 ** [in]  biasData         bias pointer
 **
 ** [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** [in]  convParam        convolution parameter structure pointer
 **
 ** [in]  actType          output activation type
 **
 ** [in]  intrplParam      interpolation param for output activation
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Convolution(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData, const void *sparsityBaseAddr,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  uint32_t inputWidth, inputHeight, inputChannel;
  uint32_t weightPerNeuron, activationRepeats;
  uint32_t perFilterSparseBitMapSize = 0, filterSeq;
  uint32_t fullSparseBitMapSize;
  uint32_t weightOffset, iterationCount;
  cy_nn_act_intrpl_param_t intrplParamVal;
  uint32_t outputWidth, outputHeight;
  uint32_t filterWidth, filterHeight;
  cy_nnlite_sparsity_cfg_t sparCfg;
  int8_t *outScratchBuf, *weightPtr;
  uint32_t outBufOffset;
  bool actEn, equalScalingFactor;
  bool syncMode;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if(((NULL == filterData) && (NULL == sparsityBaseAddr)) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == convParam) ||
      (NULL == inputData) || (NULL == outData) ||
      (NULL == convParam->outScalingFactor))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  /* for multiscaling valid scratchBuf should be passed in convParam */
  else if ((!(equalScalingFactor =
    isScalingFactorEqual(convParam->outScalingFactor, filterDims->dims[0]) )) &&
    (NULL == convParam->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }

  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannel = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];

    /* compute weight per neuron,
    filter channel == input channel
    */
    weightPerNeuron = filterHeight * filterWidth * inputChannel;
     /* Blocking mode API */
    if (kernelContext.completionCbFunc == NULL)
    {
      syncMode = 1;
    }
    else /* Non Blocking mode API */
    {
      /* completion callback from ISR */
      syncMode = 0;
    }

    /*Add check for equal scaling factor */
    if (equalScalingFactor)
    {
      /* no need to split convolution */
      iterationCount = 1;
      /* activation repeat is equal to number of filters or output depth */
      activationRepeats = MIN(outputDims->dims[3], filterDims->dims[0]);
      outScratchBuf = outData;
    }
    else /* need to split N filter convolution of N convolutions */
    {
      iterationCount = MIN(outputDims->dims[3], filterDims->dims[0]);
      /* need to wait for completion of M-1,
         before starting for Mth filter
      */
      activationRepeats = 1;
    }
    if (iterationCount > 1)
    {
      /* use scratchBuf for N convolutions,
      transpose will be in outData
      */
      outScratchBuf = convParam->scratchBuf;
    }
    else
    {
      outScratchBuf = outData;
    }
    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeats, inputWidth,
        inputHeight, inputChannel,
        convParam->startCol, convParam->startRow,
        convParam->padValue, convParam->padWidth,
        convParam->padHeight, convParam->strideCol,
        convParam->strideRow, convParam->inputOffset);

    Cy_NNLite_WeightStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
        weightPerNeuron, convParam->filterOffset);

    if (actType == CY_NNLITE_ACTIVATION_NONE)
    {
      actEn = false;
    }
    else
    {
      actEn = true;
    }
    Cy_NNLite_ActivationTypeCtrl(MXNNLITE_1_0,
        CY_NNLITE_CONV_LAYER, actEn, CY_NNLITE_ACTIVATION_8BIT);

    if (actEn)
    {
      Cy_NNLite_ParaseInterpolationParam(actType, intrplParam, &intrplParamVal);
      /* set slope for "left from 0" */
      Cy_NNLite_SetInterpolationLUTAddr(MXNNLITE_1_0, 0);
      Cy_NNLite_SetInterpolationParam(MXNNLITE_1_0,
                                      intrplParamVal.slope0,
                                      intrplParamVal.intercept0);
      /* set slope for "right from 0" */
      Cy_NNLite_SetInterpolationLUTAddr(MXNNLITE_1_0, 1);
      Cy_NNLite_SetInterpolationParam(MXNNLITE_1_0,
                                      intrplParamVal.slope1,
                                      intrplParamVal.intercept1);
    }
    /* incase of valid sparsemap,
     * weight streamer basepointer will be derived from sparsemap
     * */
    if (NULL != sparsityBaseAddr)
    {
      if (iterationCount > 1)
      {
        /* perFilterSparseBitMapSize in bytes, Must be 8-bits aligned
         * for n filter total sparsity length will be
         * (n x perFilterSparseBitMapSize)
         */
        perFilterSparseBitMapSize = Cy_NNLite_SparsityMapSize(weightPerNeuron);
        fullSparseBitMapSize = perFilterSparseBitMapSize * filterDims->dims[0];
      }
      else
      {
        /* iterationCount==1, sparsity bit of all filters need to to be aligned
         * to 8 bits
         */
        fullSparseBitMapSize =
          Cy_NNLite_SparsityMapSize(weightPerNeuron * filterDims->dims[0]);
      }
      Cy_NNLite_ParseSparsity(MXNNLITE_1_0, sparsityBaseAddr,
              filterDims->dims[0], fullSparseBitMapSize, &sparCfg);
      /* sparCfg will be set in per axis for loop */
      Cy_NNLite_SparsityEnable(MXNNLITE_1_0, true);
      weightPtr = (int8_t *)sparCfg.wtAddr;
    }
    else
    {
      /* no sparsity case*/
      weightPtr = (int8_t *)filterData;
      Cy_NNLite_SparsityEnable(MXNNLITE_1_0, false);
    }

    if(NULL != biasData)
    {
      Cy_NNLite_BiasStreamerEnable(MXNNLITE_1_0, true);
    }
    else
    {
      Cy_NNLite_BiasStreamerEnable(MXNNLITE_1_0, false);
    }

    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
        CY_NNLITE_ACTIVATION_STREAMER, inputData);

    /* enable interrupt */
    Cy_NNLite_SetInterruptMask(MXNNLITE_1_0, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_1_0, false);
    /* length of output for per axis */
    outBufOffset = (outputWidth  * outputHeight);
    if ((iterationCount > 1) || syncMode)
    {
        kernelContext.waitForCompletion = 1;
    }
    else
    {
        kernelContext.waitForCompletion = 0;
    }
    /* per axis param loop */
    for (filterSeq = 0; filterSeq < iterationCount; filterSeq++)
    {
      Cy_NNLite_OutputStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
          convParam->outClippingMask, convParam->outputOffset,
          outputWidth, outputHeight,
          convParam->outScalingFactor[filterSeq]);

      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
          CY_NNLITE_WEIGHT_STREAMER,
          weightPtr);

      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
          CY_NNLITE_OUT_STREAMER,
          outScratchBuf + (filterSeq * outBufOffset));

      if (NULL != sparsityBaseAddr)
      {
        Cy_NNLite_SparsityCfg(MXNNLITE_1_0, &sparCfg);
      }
      if(NULL != biasData)
      {
        Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
            CY_NNLITE_BIAS_STREAMER, biasData + filterSeq);
      }
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      Cy_NNLite_Start(MXNNLITE_1_0, &kernelContext.pdlContext);
      if (iterationCount > 1)
      {
        /* prepare for next in loop */
        if (NULL != sparsityBaseAddr)
        {
          /* increment weightPtr by non zero weights */
          weightOffset = *((uint16_t *)sparCfg.nonZeroWtAddr);
          /* nonZeroWtAddr is 2 bytes per filter */
          sparCfg.nonZeroWtAddr += 2;
          sparCfg.sparsityBitMapAddr += perFilterSparseBitMapSize;
        }
        else
        {
          /* non sparsity case */
          weightOffset = weightPerNeuron;
        }
        weightPtr += weightOffset;
      }
      /* iterationCount > 1, split convolution case,
         wait for M-1, before starting Mth
      */
      if (kernelContext.waitForCompletion)
      {
        status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
        /* Semaphore API failed  abort and return */
        if (status != CY_NNLITE_SUCCESS)
        {
          kernelContext.waitForCompletion = 0;
          Cy_NNLite_Stop(MXNNLITE_1_0, &kernelContext.pdlContext);
          status = CY_NNLITE_EXTERN_API_ERR;
          break;
        }
        /* check for error in last operation */
        else if (kernelContext.pdlContext.opStatus != CY_NNLITE_SUCCESS)
        {
          status = kernelContext.pdlContext.opStatus;
          break;
        }
      }

    }

    /* transpose only when split convolutions with success status */
    if ((iterationCount > 1) && (status == CY_NNLITE_SUCCESS))
    {
      if (syncMode)
      {
        kernelContext.waitForCompletion = 1;
      }
      else
      {
        kernelContext.waitForCompletion = 0;
      }
      kernelContext.pdlContext.nnliteState = CY_NNLITE_OP_STARTED;
      Cy_NNLite_Transpose(outScratchBuf, outData, outScratchBuf,
                     outBufOffset, iterationCount, CY_NNLITE_DMA_CHW_TO_HWC);
      if (kernelContext.waitForCompletion)
      {
        /* Semaphore wait failed, disable DMA & interrupt */
        status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
        if (status != CY_NNLITE_SUCCESS)
        {
          status = CY_NNLITE_EXTERN_API_ERR;
          Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
          kernelContext.waitForCompletion = 0;
          Cy_DMA_Channel_Disable(DW0, NNLITE_DMA_CHAN);
        }
      }
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    status = CY_NNLITE_EXTERN_API_ERR;
  }
  return status;
}

/**
 *****************************************************************************
 ** \brief Fully connected CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 ** intrplParam can be passed as NULL for default behavior
 ** of activation, to parametrize activation pass valid  intrplParam.
 ** filterData points to weights If sparsityBaseAddr is NULL, otherwise
 ** weights pointer will be derived from sparsityBaseAddr and filterData
 ** will not be used.
 ** No scratch buffer is required in CPU mode fully connected
 **
 ** [in]  inputData        activation buffer pointer
 **
 ** [in]  outData         output buffer pointer
 **
 ** [in]  inputDims        activation dimension pointer
 **
 ** [in]  outpututDims     output dimension pointer
 **
 ** [in]  filterDims       filter dimension pointer
 **
 ** [in]  filterData       filter pointer
 **
 ** [in]  biasData         bias pointer
 **
 ** [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** [in]  fcParam          fully Connected parameter structure pointer
 **
 ** [in]  actType          output activation type
 **
 ** [in]  intrplParam      interpolation param for output activation
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnected(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData, const void *sparsityBaseAddr,
    cy_nn_fc_params_t *fcParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  cy_nn_act_intrpl_param_t intrplParamVal;
  uint32_t filterWidth, filterHeight;
  cy_nnlite_sparsity_cfg_t sparCfg;
  uint32_t inputWidth, inputHeight;
  uint32_t activationRepeats;
  uint32_t weightPerNeuron;
  uint32_t sparseBitMapSize;
  bool actEn, biasEn = false;
  bool syncMode;
  int8_t *weightPtr;
  cy_en_nnlite_status_t status;
  uint32_t outputHeight, outputWidth;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if((NULL == inputData) || (NULL == outData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == fcParam) ||
      ((NULL == filterData) && (NULL == sparsityBaseAddr)))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    if (kernelContext.completionCbFunc == NULL)
    {
      /* Blocking mode, completion callback from ISR */
      syncMode = 1;
    }
    else
    {
      /* Non blocking mode, completion callback from ISR */
      syncMode = 0;
    }
    kernelContext.waitForCompletion = syncMode;
    filterWidth = filterDims->dims[1];
    filterHeight = 1;
    inputWidth = inputDims->dims[1];
    inputHeight = 1;
    activationRepeats = MIN(filterDims->dims[0], outputDims->dims[1]);
    weightPerNeuron = filterWidth;
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];

    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeats, inputWidth,
        inputHeight, 1,/* input height, channel */
        0, 0, /* start col, row */
        0, 0, /* pad value, width */
        0, 0, /* pad height, stride col */
        0, fcParam->inputOffset /* stride row, input offset */
        );

    Cy_NNLite_WeightStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
        weightPerNeuron, fcParam->filterOffset);

    Cy_NNLite_OutputStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
        fcParam->outClippingMask, fcParam->outputOffset,
        outputWidth, outputHeight, fcParam->outScalingFactor);

    /* incase of valid sparsemap,
     * weight streamer basepointer will be derived from sparsemap
     * */
    if (NULL != sparsityBaseAddr)
    {
      sparseBitMapSize =
           Cy_NNLite_SparsityMapSize(filterWidth * filterHeight * activationRepeats);
      Cy_NNLite_ParseSparsity(MXNNLITE_1_0, sparsityBaseAddr,
                 filterDims->dims[0], sparseBitMapSize, &sparCfg);
      Cy_NNLite_SparsityCfg(MXNNLITE_1_0, &sparCfg);
      Cy_NNLite_SparsityEnable(MXNNLITE_1_0, true);
      weightPtr = (int8_t *)sparCfg.wtAddr;
    }
    else
    {
      weightPtr = (int8_t *)filterData;
      Cy_NNLite_SparsityEnable(MXNNLITE_1_0, false);
    }

    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
        CY_NNLITE_WEIGHT_STREAMER, weightPtr);

    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
        CY_NNLITE_ACTIVATION_STREAMER, inputData);
    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
        CY_NNLITE_OUT_STREAMER, outData);
    if(NULL != biasData)
    {
      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
          CY_NNLITE_BIAS_STREAMER, biasData);
      biasEn = true;
    }
    Cy_NNLite_BiasStreamerEnable(MXNNLITE_1_0, biasEn);

    if (actType == CY_NNLITE_ACTIVATION_NONE)
    {
      actEn = false;
    }
    else
    {
      actEn = true;
    }

    Cy_NNLite_ActivationTypeCtrl(MXNNLITE_1_0,
        CY_NNLITE_FC_LAYER, actEn, CY_NNLITE_ACTIVATION_8BIT);

    if (actEn)
    {
      Cy_NNLite_ParaseInterpolationParam(actType, intrplParam, &intrplParamVal);
      /* set slope for "left from 0" */
      Cy_NNLite_SetInterpolationLUTAddr(MXNNLITE_1_0, 0);
      Cy_NNLite_SetInterpolationParam(MXNNLITE_1_0,
                                      intrplParamVal.slope0,
                                      intrplParamVal.intercept0);
      /* set slope for "right from 0" */
      Cy_NNLite_SetInterpolationLUTAddr(MXNNLITE_1_0, 1);
      Cy_NNLite_SetInterpolationParam(MXNNLITE_1_0,
                                      intrplParamVal.slope1,
                                      intrplParamVal.intercept1);
    }

    Cy_NNLite_SetInterruptMask(MXNNLITE_1_0, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_1_0, false);
    kernelContext.LpmLockFunc();
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
    Cy_NNLite_Start(MXNNLITE_1_0, &kernelContext.pdlContext);

    status = CY_NNLITE_SUCCESS;
    if (kernelContext.waitForCompletion)
    {
      status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
      /* Semaphore API failed  abort and return */
      if (status != CY_NNLITE_SUCCESS)
      {
        kernelContext.waitForCompletion = 0;
        Cy_NNLite_Stop(MXNNLITE_1_0, &kernelContext.pdlContext);
        status = CY_NNLITE_EXTERN_API_ERR;
      }
      else /* update operation status */
      {
        status = kernelContext.pdlContext.opStatus;
      }
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    status = CY_NNLITE_EXTERN_API_ERR;
  }
  return status;
}

/**
 *****************************************************************************
 ** \brief Average pool CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation.Callback function from kernel config
 ** structure will be called after completion of layer.Kernel config structure
 ** should point to valid callback function.Implemented using convolution in
 ** nnlite.
 ** Valid scratch buffer should be allocated and passed in avgpoolParam. Size
 ** of scratch buffer should be calculated using API
 ** Cy_NNLite_AvgpoolScratchBufSize scratch buffer will memset to 1 and will
 ** be used as base address for weights streamer for  convolution operation.
 ** Scratch buffer can be freed after receiving completion callback of API.
 **
 ** [in]  inputData        activation buffer pointer
 **
 ** [in]  outData         output buffer pointer
 **
 ** [in]  inputDims        activation dimension pointer
 **
 ** [in]  outpututDims     output dimension pointer
 **
 ** [in]  filterDims       filter dimension pointer
 **
 ** [in]  avgpoolParam     average pool parameter structure pointer
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Avgpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_avgpool_params_t *avgpoolParam)
{
  uint32_t weightPerNeuron;
  uint32_t filterWidth, filterHeight;
  uint32_t inputWidth, inputHeight, inputChannel;
  uint32_t outputHeight, outputWidth;
  uint32_t inputTransposeDesCount;
  uint32_t activationRepeat, iteration;
  float fscaling;
  int8_t* scratchBufIn;
  int8_t* scratchBufOut;
  bool syncMode;
  uint32_t outBufOffset, inBufOffset;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  filterHeight = filterDims->dims[1];
  filterWidth = filterDims->dims[2];
  inputHeight = inputDims->dims[1];
  inputWidth = inputDims->dims[2];
  inputChannel = inputDims->dims[3];
  outputHeight = outputDims->dims[1];
  outputWidth = outputDims->dims[2];

  if((NULL == inputData) || (NULL == outData) ||
        (NULL == inputDims) || (NULL == outputDims) ||
        (NULL == filterDims) || (NULL == avgpoolParam))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((avgpoolParam->padWidth != 0) || \
          (avgpoolParam->padHeight != 0))
  {
    /* Unfortunately AvgPool "padding" is actual kernel footprint truncation
     NOT zero padding (which is what we have in NNLite HW).  So padding is no-go.*/
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {

    activationRepeat = 1;

    /* filter channel == iput channel */
    weightPerNeuron =  filterHeight * filterWidth;

    /* calculate float scaling value*/
    fscaling = (1.0 / weightPerNeuron);

    /* Blocking mode API */
    if (kernelContext.completionCbFunc == NULL)
    {
      syncMode = 1;
    }
    else /* Non Blocking mode API */
    {
      /* completion callback from ISR */
      syncMode = 0;
    }

    if (inputChannel > 1)
    {
      inBufOffset = inputHeight * inputWidth;
      outBufOffset = outputHeight * outputWidth;
      scratchBufIn = avgpoolParam->scratchBuf;
      inputTransposeDesCount = Cy_NNLite_GetTransposeDescCount(inBufOffset, inputChannel);
      /* align scratchBufOut for DMA */
      scratchBufOut = scratchBufIn + (((inBufOffset * inputChannel) + 3)  & (~3))+ (inputTransposeDesCount * DMA_DESC_SIZE);
      kernelContext.pdlContext.nnliteState = CY_NNLITE_OP_STARTED;
       /*  wait for transpose HWC == CHW */
      kernelContext.waitForCompletion = 1;
      Cy_NNLite_Transpose((int8_t *)cy_AhbRemapAddr(inputData), scratchBufIn, scratchBufIn,
                           inBufOffset, inputChannel, CY_NNLITE_DMA_HWC_TO_CHW);
      status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
      /* Semaphore wait failed, disable DMA & interrupt */
      if (status != CY_NNLITE_SUCCESS)
      {
        Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
        kernelContext.waitForCompletion = 0;
        Cy_DMA_Channel_Disable(DW0, NNLITE_DMA_CHAN);
        kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
        status = CY_NNLITE_EXTERN_API_ERR;
        return status;
      }
    }
    else
    {
      scratchBufIn =  (int8_t *)inputData;
      scratchBufOut = outData;
      inBufOffset = 0;
      outBufOffset = 0;
    }
    if ((inputChannel > 1) || syncMode)
    {
        kernelContext.waitForCompletion = 1;
    }
    else
    {
        kernelContext.waitForCompletion = 0;
    }
    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeat, inputWidth,
        inputHeight , 1,
        0, 0, /* start col, row*/
        0, avgpoolParam->padWidth, /* pad value, width */
        avgpoolParam->padHeight, avgpoolParam->strideCol,
        avgpoolParam->strideRow, 0 /* stride row, input offset */
        );

    Cy_NNLite_WeightStreamerCfg(MXNNLITE_1_0,
                          &kernelContext.pdlContext, weightPerNeuron, 0);

    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
                                CY_NNLITE_WEIGHT_STREAMER, Cy_NNLite_GetAvgPoolKernelWeightPtr());
    Cy_NNLite_BiasStreamerEnable(MXNNLITE_1_0, false);

    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_1_0, false);

    Cy_NNLite_SetInterruptMask(MXNNLITE_1_0, NNLITE_INTR_ENABLE_MASK);

    Cy_NNLite_ActivationTypeCtrl(MXNNLITE_1_0,
                            CY_NNLITE_CONV_LAYER, false, CY_NNLITE_ACTIVATION_8BIT);
    Cy_NNLite_SparsityEnable(MXNNLITE_1_0, false);
    for (iteration = 0 ; iteration < inputChannel ; iteration++)
    {
      Cy_NNLite_OutputStreamerCfg(MXNNLITE_1_0, &kernelContext.pdlContext,
                                avgpoolParam->outClippingMask, 0,
                                outputWidth, outputHeight,
                                fscaling);
      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
                                CY_NNLITE_ACTIVATION_STREAMER,
                                scratchBufIn + (iteration * inBufOffset));
      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_1_0,
                                CY_NNLITE_OUT_STREAMER,
                                scratchBufOut + (iteration * outBufOffset));
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      Cy_NNLite_Start(MXNNLITE_1_0, &kernelContext.pdlContext);
      if (kernelContext.waitForCompletion)
      {
        status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
                /* Semaphore API failed  abort and return */
        if (status != CY_NNLITE_SUCCESS)
        {
          kernelContext.waitForCompletion = 0;
          Cy_NNLite_Stop(MXNNLITE_1_0, &kernelContext.pdlContext);
          status = CY_NNLITE_EXTERN_API_ERR;
          break;
        }
        /* check for error in last operation */
        else if (kernelContext.pdlContext.opStatus & NNLITE_INTR_ERRORS_MASK)
        {
          status = kernelContext.pdlContext.opStatus;
          break;
        }
      }

    }
    /* transpose only when multi channels */
    if ((inputChannel > 1) && (status == CY_NNLITE_SUCCESS))
    {
      if (syncMode)
      {
        kernelContext.waitForCompletion = 1;
      }
      else
      {
        kernelContext.waitForCompletion = 0;
      }
      kernelContext.pdlContext.nnliteState = CY_NNLITE_OP_STARTED;
      Cy_NNLite_Transpose(scratchBufOut, outData, scratchBufOut,
                       outBufOffset, inputChannel, CY_NNLITE_DMA_CHW_TO_HWC);
      if (kernelContext.waitForCompletion)
      {
        status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
        /* Semaphore wait failed, disable DMA & interrupt */
        if (status != CY_NNLITE_SUCCESS)
        {
          Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
          kernelContext.waitForCompletion = 0;
          Cy_DMA_Channel_Disable(DW0, NNLITE_DMA_CHAN);
          status = CY_NNLITE_EXTERN_API_ERR;
        }
      }
    }

  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
     status = CY_NNLITE_EXTERN_API_ERR;
  }
  return status;
}

/**
 *****************************************************************************
 ** \brief 2D Convolution kernel DMA API, API will fill DMA descriptor
 ** pointing nnlite MEMIO configuration structure.
 ** intrplParam can be passed as NULL for default behavior of activation, to
 ** parametrize activation pass valid  intrplParam.
 ** filterData points to weights If sparsityBaseAddr is NULL otherwise weights
 ** pointer will be derived from sparsityBaseAddr and filterData will
 ** not be used.
 ** Valid scratch buffer should be passed in convParam, scratch buffer will be
 ** used for nnlite MEMIO configuration structure (per axis 1), and for
 ** transpose operation for per axis (transpose scratch buffer and transpose
 ** DMA descriptors) convolution implementation, size of scratch buffer should
 ** be derived by calling function Cy_NNLite_ConvolutionScratchBufSize.
 ** Scratch buffer can be freed after receiving completion callback.
 ** N convolutions Descriptors and Transpose Descriptors will be Queue in DMA
 ** together. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue.Callback function from kernel config
 ** structure will be called after completion of all queued layers
 ** kernel config structure should point to valid callback function.
 **
 ** [in]  inputData        activation buffer pointer
 **
 ** [in]  outData         output buffer pointer
 **
 ** [in]  inputDims        activation dimension pointer
 **
 ** [in]  outpututDims     output dimension pointer
 **
 ** [in]  filterDims       filter dimension pointer
 **
 ** [in]  filterData       filter pointer
 **
 ** [in]  biasData         bias pointer
 **
 ** [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** [in]  convParam        convolution parameter structure pointer
 **
 ** [in]  actType          output activation type
 **
 ** [in]  intrplParam      interpolation param for output activation
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_ConvolutionDMA(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData, const void *sparsityBaseAddr,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  uint32_t inputWidth, inputHeight, inputChannel;
  cy_nnlite_memio_dma_t *nnliteMemio;
  cy_nn_act_intrpl_param_t intrplParamVal;
  uint32_t outputWidth, outputHeight;
  uint32_t filterWidth, filterHeight;
  uint32_t filterChannelTimesWidth;
  cy_nnlite_sparsity_cfg_t sparCfg;
  uint32_t weightPerNeuron;
  uint32_t activationRepeats;
  int8_t *outScratchBuf;
  uint32_t outBufOffset;
  bool actEn;
  int8_t *weightPtr, weightOffset = 0;
  uint32_t filterSeq, iterationCount;
  uint32_t perFilterSparseBitMapSize = 0;
  uint32_t fullSparseBitMapSize = 0;
  cy_stc_dma_descriptor_config_t *cfgDesc;
  cy_stc_dma_descriptor_t *desc;
  uint32_t *outScalingFactorPtr;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if(((NULL == filterData) && (NULL == sparsityBaseAddr)) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == convParam) ||
      (NULL == inputData) || (NULL == outData) ||
      (NULL == convParam->outScalingFactor) ||
      (NULL == convParam->scratchBuf)
      )
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannel = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];
    filterChannelTimesWidth = filterWidth * inputChannel;

    /* filter channel == iput channel */
    weightPerNeuron = filterHeight * filterChannelTimesWidth;
    nnliteMemio = (cy_nnlite_memio_dma_t *)convParam->scratchBuf;

    /*Add check for equal scaling factor */
    if (isScalingFactorEqual(convParam->outScalingFactor, filterDims->dims[0]))
    {
      /* Single convolution, activation repeat is equal to number of
         filters or output depth
       */
      activationRepeats = MIN(outputDims->dims[3], filterDims->dims[0]);
      iterationCount = 1;
      outScratchBuf = outData;
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(nnliteMemio + 1);
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);
      /* fullSparseBitMapSize Must be 8-bits aligned */
      fullSparseBitMapSize = Cy_NNLite_SparsityMapSize(weightPerNeuron* filterDims->dims[0]);
    }
    else
    {
      cfgDesc = (cy_stc_dma_descriptor_config_t *)
                          (nnliteMemio + filterDims->dims[0]);
      desc = (cy_stc_dma_descriptor_t *)
                          (cfgDesc + (filterDims->dims[0] * DESC_COUNT_PER_LAYER));

      /* per axis convolution, all convolution will be queued in DMA Q */
      iterationCount = MIN(outputDims->dims[3], filterDims->dims[0]);
      activationRepeats = 1;
      /* use scratchBuf,after dma desc, for outbuf of N conv and then
         transpose in outData from scratch buf
      */
      outScratchBuf = (int8_t *)
                  (desc + (filterDims->dims[0] * DESC_COUNT_PER_LAYER));
      /* perFilterSparseBitMapSize Must be 8-bits aligned */
      perFilterSparseBitMapSize = Cy_NNLite_SparsityMapSize(weightPerNeuron);
      fullSparseBitMapSize = perFilterSparseBitMapSize * filterDims->dims[0];
    }

    if (actType == CY_NNLITE_ACTIVATION_NONE)
    {
      actEn = false;
    }
    else
    {
      actEn =  true;
    }
    if (actEn)
    {
      Cy_NNLite_ParaseInterpolationParam(actType, intrplParam, &intrplParamVal);
    }

    if (NULL != sparsityBaseAddr)
    {
      Cy_NNLite_ParseSparsity(MXNNLITE_1_0, sparsityBaseAddr,
                   filterDims->dims[0], fullSparseBitMapSize, &sparCfg);
      weightPtr = (int8_t *)sparCfg.wtAddr;
    }
    else
    {
        weightPtr = (int8_t *)filterData;
    }

    outBufOffset = (outputWidth  * outputHeight);
    for (filterSeq = 0 ; filterSeq < iterationCount; filterSeq++)
    {
      /* enable NNLite DMA Trigger */
      nnliteMemio->TRIG_MASK = 1;
      nnliteMemio->ACTIVATIONSTREAMEROFFSET = convParam->inputOffset;
      nnliteMemio->ACTIVATIONSTREAMERKERNELCHANNELTIMESWIDTH =
                                                     filterChannelTimesWidth;
      nnliteMemio->ACTIVATIONSTREAMERKERNELHEIGHT = filterHeight;
      /* is equal to number of filters for conv or equal to
        filer 2nd dimension for fc layer
      */
      nnliteMemio->ACTIVATIONSTREAMERREPEATS = activationRepeats;
      /* input dims */
      nnliteMemio->ACTIVATIONSTREAMERCHANNELTIMESWIDTH =
                                      (inputWidth * inputChannel);
      nnliteMemio->ACTIVATIONSTREAMERHEIGHT = inputHeight;

      nnliteMemio->ACTIVATIONSTREAMERSTARTCOL =
                    convParam->startCol - (convParam->padWidth * inputChannel);
      nnliteMemio->ACTIVATIONSTREAMERSTARTROW =
                                   convParam->startRow - convParam->padHeight;

      nnliteMemio->ACTIVATIONSTREAMERPADDING = _VAL2FLD(
            MXNNLITE_1_0_ACTIVATIONSTREAMERPADDING_ACTIVATIONSTREAMERPADVALUE,
            convParam->padValue);

      nnliteMemio->STRIDE =
       _VAL2FLD(MXNNLITE_1_0_STRIDE_STRIDECHANNELTIMESCOLUMN,
               convParam->strideCol * inputChannel) |
       _VAL2FLD(MXNNLITE_1_0_STRIDE_STRIDEROW, convParam->strideRow);

       nnliteMemio->NNLAYER_ACTIVATION_TYPE_CTL =
        _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_NNLAYER_TYPE_CTL,
              CY_NNLITE_CONV_LAYER) |
        _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_FUNC_EN,
              actEn) |
        _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_SIZE_CTL,
              CY_NNLITE_ACTIVATION_8BIT);

      if (actEn)
      {
        nnliteMemio->INTERPOLATIONLUTADDR0 = 0;
        nnliteMemio->INTERPOLATIONLUTWDATA0 =
        _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONSLOPE,
                  intrplParamVal.slope0) |
        _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONYINTERCEPT,
                  intrplParamVal.intercept0);

        nnliteMemio->INTERPOLATIONLUTADDR1 = 1;
        nnliteMemio->INTERPOLATIONLUTWDATA1 =
        _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONSLOPE,
                  intrplParamVal.slope1) |
        _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONYINTERCEPT,
                  intrplParamVal.intercept1);
      }

      nnliteMemio->WEIGHTSTREAMERKERNELCHANNELTIMESHEIGHTTIMESWIDTH =
                                                        weightPerNeuron;
      nnliteMemio->WEIGHTSTREAMEROFFSET = convParam->filterOffset;
      nnliteMemio->STREAMERMODES = MXNNLITE_1_0_STREAMERMODES_WEIGHTSTREAMERSIGNEDVALUES_Msk |
                                   MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSIGNEDVALUES_Msk |
                                   MXNNLITE_1_0_STREAMERMODES_OUTSTREAMERSIGNEDVALUES_Msk;
      if (NULL != sparsityBaseAddr)
      {
        /* sparCfg will be set in filterSeq loop */
        nnliteMemio->STREAMERMODES |=
           _VAL2FLD(MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1);
      }
      else
      {
        nnliteMemio->STREAMERMODES &=
         ~(_VAL2FLD(MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1));
      }

      if(NULL != biasData)
      {
        nnliteMemio->STREAMERMODES |=
                    _VAL2FLD(MXNNLITE_1_0_STREAMERMODES_BIASEN, 1);
      }

      nnliteMemio->ACTIVATIONSTREAMERBASEADDR = cy_AhbRemapAddr(inputData);

      /* enable interrupt only Error interrupts for DMA mode */
      nnliteMemio->INTR_MASK = NNLITE_INTR_ERRORS_MASK;
      nnliteMemio->INTR = MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_DONE_Msk;
      nnliteMemio->INTR_SET = 0;

      nnliteMemio->OUTSTREAMERCLIPPINGMASK = convParam->outClippingMask;
      nnliteMemio->OUTSTREAMEROUTPUTOFFSET = convParam->outputOffset;
      outScalingFactorPtr =
               (uint32_t *)&convParam->outScalingFactor[filterSeq];
      nnliteMemio->OUTSTREAMERSCALINGFACTOR = *outScalingFactorPtr;
      nnliteMemio->OUTPUTWIDTH = outputWidth;
      nnliteMemio->OUTPUTHEIGHT = outputHeight;
      nnliteMemio->WEIGHTSTREAMERBASEADDR = cy_CbusRemapAddr(weightPtr);

      nnliteMemio->OUTSTREAMERBASEADDR = (uint32_t)(
          outScratchBuf + (filterSeq * outBufOffset));

      if (NULL != sparsityBaseAddr)
      {
        nnliteMemio->NONZEROWEIGHTSPOINTER =
                        cy_CbusRemapAddr((const void *)sparCfg.nonZeroWtAddr);
        nnliteMemio->ACTIVATIONSTREAMERSPARSITYMAPBASEADDR =
                   cy_CbusRemapAddr((const void *)sparCfg.sparsityBitMapAddr);
        /* increment weightPtr by non zero weights */
        weightOffset = *((uint16_t *)sparCfg.nonZeroWtAddr);
        /* nonZeroWtAddr is 2 bytes per filter */
        sparCfg.nonZeroWtAddr += 2;
        sparCfg.sparsityBitMapAddr += perFilterSparseBitMapSize;
      }
      else
      {
        weightOffset = weightPerNeuron;
      }
      weightPtr += weightOffset;
      if(NULL != biasData)
      {
        nnliteMemio->BIASBASEADDR = cy_CbusRemapAddr(biasData + filterSeq);
      }

      nnliteMemio->CMD = _VAL2FLD(MXNNLITE_1_0_CMD_START_CMD, 1);
      /* Queue convolution in DMA Queue*/
      Cy_NNLite_SetupNNLiteMemioDMADesc(nnliteMemio,
                                &nnliteDMAQ, cfgDesc, desc);
      nnliteMemio++;
      cfgDesc += DESC_COUNT_PER_LAYER;
      desc += DESC_COUNT_PER_LAYER;
    }
    if (iterationCount > 1)
    {
        /* this will link transpose descriptors to convolution */
        Cy_NNLite_LinkTransposeDMA(outScratchBuf, outData, outScratchBuf,
                    outBufOffset, iterationCount, CY_NNLITE_DMA_CHW_TO_HWC);
    }
    if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
    {
      status = CY_NNLITE_EXTERN_API_ERR;
      Cy_NNlite_MarkDMAQueueEmpty(&nnliteDMAQ);
    }
    else
    {
        status = CY_NNLITE_OP_QUEUED;
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  return status;

}

/**
 *****************************************************************************
 ** \brief DMA based fully connected(Dense) kernel API, API will fill DMA
 ** descriptor pointing NNLite MEMIO configuration structure.
 ** intrplParam can be passed as NULL for default behavior of activation,
 ** to parametrize activation pass valid  intrplParam.
 ** filterData points to weights if sparsityBaseAddr is NULL otherwise weights
 ** pointer will be derived from sparsityBaseAddr and filterData will not be
 ** used.
 ** Valid scratch buffer should be passed in fcParam, scratch buffer will be
 ** used for DMA descriptors and for nnlite MEMIO configuration structure for
 ** DMA. Size of scratch buffer should be calculated using API
 ** Cy_NNLite_FullyConnectedDMAScratchBufSize
 ** API will setup DMA descriptor and will Queue DMA operation.
 ** CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue. Callback function from kernel config will
 ** be called after completion of all queued layers, kernel config
 ** structure should point to valid callback function.Scratch buffer can be
 ** freed after receiving completion callback.
 **
 ** [in]  inputData        activation buffer pointer
 **
 ** [in]  outData          output buffer pointer
 **
 ** [in]  inputDims        activation dimension pointer
 **
 ** [in]  outpututDims     output dimension pointer
 **
 ** [in]  filterDims       filter dimension pointer
 **
 ** [in]  filterData       filter pointer
 **
 ** [in]  biasData         bias pointer
 **
 ** [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** [in]  fcParam          fully Connected parameter structure pointer
 **
 ** [in]  actType          output activation type
 **
 ** [in]  intrplParam      interpolation param for output activation
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnectedDMA(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData, const void *sparsityBaseAddr,
    cy_nn_fc_params_t *fcParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  cy_nn_act_intrpl_param_t intrplParamVal;
  uint32_t filterWidth, filterHeight;
  cy_nnlite_sparsity_cfg_t sparCfg;
  uint32_t inputWidth, inputHeight;
  uint32_t activationRepeats;
  uint32_t weightPerNeuron;
  uint32_t sparseBitMapSize;
  bool actEn, biasEn = false;
  cy_nnlite_memio_dma_t *nnliteMemio;
  cy_stc_dma_descriptor_config_t *cfgDesc;
  cy_stc_dma_descriptor_t *desc;
  int8_t *weightPtr;
  cy_en_nnlite_status_t status;
  uint32_t *outScalingFactorPtr = (uint32_t *)&fcParam->outScalingFactor;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if((NULL == inputData) || (NULL == outData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == fcParam) ||
      (NULL == fcParam->scratchBuf) ||
      ((NULL == filterData) && (NULL == sparsityBaseAddr)))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    nnliteMemio = (cy_nnlite_memio_dma_t *)fcParam->scratchBuf;
    cfgDesc = (cy_stc_dma_descriptor_config_t *)(nnliteMemio + 1);
    desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);
    filterWidth = filterDims->dims[1];
    /* always 1 for FC */
    filterHeight = 1;

    inputWidth = inputDims->dims[1];
    /* always 1 for FC */
    inputHeight = 1;

    activationRepeats = MIN(filterDims->dims[0], outputDims->dims[1]);
    weightPerNeuron = filterWidth;

    nnliteMemio->ACTIVATIONSTREAMEROFFSET = fcParam->inputOffset;
    /* weights dims*/
    nnliteMemio->ACTIVATIONSTREAMERKERNELCHANNELTIMESWIDTH = filterWidth;
    nnliteMemio->ACTIVATIONSTREAMERKERNELHEIGHT = filterHeight;

    nnliteMemio->ACTIVATIONSTREAMERREPEATS = activationRepeats;

    /* input dims */
    nnliteMemio->ACTIVATIONSTREAMERCHANNELTIMESWIDTH = inputWidth;
    nnliteMemio->ACTIVATIONSTREAMERHEIGHT = inputHeight;

    nnliteMemio->ACTIVATIONSTREAMERSTARTCOL = 0;
    nnliteMemio->ACTIVATIONSTREAMERSTARTROW = 0;
    nnliteMemio->ACTIVATIONSTREAMERPADDING = 0;
    nnliteMemio->STRIDE = 0;

    nnliteMemio->WEIGHTSTREAMERKERNELCHANNELTIMESHEIGHTTIMESWIDTH =
                                                        weightPerNeuron;
    nnliteMemio->WEIGHTSTREAMEROFFSET = (uint32_t)fcParam->filterOffset;

    nnliteMemio->OUTSTREAMERCLIPPINGMASK = fcParam->outClippingMask;
    nnliteMemio->OUTSTREAMEROUTPUTOFFSET = fcParam->outputOffset;
    nnliteMemio->OUTSTREAMERSCALINGFACTOR = *outScalingFactorPtr;
    nnliteMemio->OUTPUTWIDTH = 0;
    nnliteMemio->OUTPUTHEIGHT = 0;
    nnliteMemio->STREAMERMODES = MXNNLITE_1_0_STREAMERMODES_WEIGHTSTREAMERSIGNEDVALUES_Msk |
                                   MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSIGNEDVALUES_Msk |
                                   MXNNLITE_1_0_STREAMERMODES_OUTSTREAMERSIGNEDVALUES_Msk;

    /* incase of valid sparsemap,
     * weight streamer basepointer will be derived from sparsemap
     * */
    if (NULL != sparsityBaseAddr)
    {
      sparseBitMapSize =
         Cy_NNLite_SparsityMapSize(filterWidth * filterHeight * activationRepeats);
      Cy_NNLite_ParseSparsity(MXNNLITE_1_0, sparsityBaseAddr,
                       filterDims->dims[0], sparseBitMapSize, &sparCfg);
      nnliteMemio->STREAMERMODES |=
          _VAL2FLD(MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1);
      nnliteMemio->NONZEROWEIGHTSPOINTER =
                       cy_CbusRemapAddr((const void *)sparCfg.nonZeroWtAddr);
      nnliteMemio->ACTIVATIONSTREAMERSPARSITYMAPBASEADDR =
                  cy_CbusRemapAddr((const void *)sparCfg.sparsityBitMapAddr);
      weightPtr = (int8_t *)sparCfg.wtAddr;
    }
    else
    {
      weightPtr = (int8_t *)filterData;
      nnliteMemio->STREAMERMODES &=
        ~(_VAL2FLD(MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1));
    }

    nnliteMemio->WEIGHTSTREAMERBASEADDR = cy_CbusRemapAddr(weightPtr);
    nnliteMemio->ACTIVATIONSTREAMERBASEADDR = cy_AhbRemapAddr(inputData);
    nnliteMemio->OUTSTREAMERBASEADDR = (uint32_t)outData;
    if(NULL != biasData)
    {
      biasEn = true;
      nnliteMemio->BIASBASEADDR = cy_CbusRemapAddr(biasData);
    }
    if (biasEn)
    {
        nnliteMemio->STREAMERMODES |=
                    _VAL2FLD(MXNNLITE_1_0_STREAMERMODES_BIASEN, 1);
    }
    else
    {
        nnliteMemio->STREAMERMODES &=
                    ~(_VAL2FLD(MXNNLITE_1_0_STREAMERMODES_BIASEN, 1));
    }

    if (actType == CY_NNLITE_ACTIVATION_NONE)
    {
      actEn = false;
    }
    else
    {
      actEn =  true;
    }

    if (actEn)
    {
      Cy_NNLite_ParaseInterpolationParam(actType, intrplParam, &intrplParamVal);

      nnliteMemio->INTERPOLATIONLUTADDR0 = 0;
      nnliteMemio->INTERPOLATIONLUTWDATA0 =
       _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONSLOPE,
                 intrplParamVal.slope0) |
       _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONYINTERCEPT,
                intrplParamVal.intercept0);

      nnliteMemio->INTERPOLATIONLUTADDR1 = 1;
      nnliteMemio->INTERPOLATIONLUTWDATA1 =
       _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONSLOPE,
                intrplParamVal.slope1) |
       _VAL2FLD(MXNNLITE_1_0_INTERPOLATIONLUTWDATA_INTERPOLATIONYINTERCEPT,
                intrplParamVal.intercept1);
    }

    nnliteMemio->NNLAYER_ACTIVATION_TYPE_CTL =
    _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_NNLAYER_TYPE_CTL,
              CY_NNLITE_FC_LAYER) |
    _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_FUNC_EN,
              actEn) |
    _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_SIZE_CTL,
              CY_NNLITE_ACTIVATION_8BIT);

    nnliteMemio->INTR_MASK = NNLITE_INTR_ERRORS_MASK;
    nnliteMemio->INTR = MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_DONE_Msk;
    nnliteMemio->INTR_SET = 0;
    /* enable NNLite DMA Trigger */
    nnliteMemio->TRIG_MASK = 1;

    nnliteMemio->CMD = _VAL2FLD(MXNNLITE_1_0_CMD_START_CMD, 1);

    Cy_NNLite_SetupNNLiteMemioDMADesc(nnliteMemio,
                                      &nnliteDMAQ, cfgDesc, desc);
    if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
    {
      status = CY_NNLITE_EXTERN_API_ERR;
      Cy_NNlite_MarkDMAQueueEmpty(&nnliteDMAQ);
    }
    else
    {
        status = CY_NNLITE_OP_QUEUED;
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  return status;
}

/**
 *****************************************************************************
 ** \brief Average pool kernel API DMA mode, API will fill DMA descriptor
 ** pointing NNLite MEMIO configuration structure.Implemented in nnlite using
 ** convolution.
 ** Valid scratch buffer should be allocated and passed in
 ** avgpoolParam. Size of scratch buffer should be calculated using API
 ** Cy_AvgPoolDMAScratchBufSize. Scratch buffer will be used for DMA
 ** descriptors and for MEMIO configuration structure and for creating
 ** weights for weights streamer for convolution operation.
 ** API will setup DMA descriptor and will Queue DMA operation.
 ** CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue.
 ** Callback function from kernel config will be called after completion of
 ** all queued layers,kernel config structure should point to valid
 ** callback function. Scratch buffer can be freed after receiving completion
 ** callback.
 **
 ** [in]  inputData        activation buffer pointer
 **
 ** [in]  outData         output buffer pointer
 **
 ** [in]  inputDims        activation dimension pointer
 **
 ** [in]  outpututDims     output dimension pointer
 **
 ** [in]  filterDims       filter dimension pointer
 **
 ** [in]  avgpoolParam     average pool parameter structure pointer
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_AvgpoolDMA(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims,
    cy_nn_avgpool_params_t *avgpoolParam)
{
  uint32_t weightPerNeuron;
  uint32_t filterWidth, filterHeight;
  uint32_t inputWidth, inputHeight, inputChannel;
  uint32_t outputHeight, outputWidth;
  uint32_t activationRepeats, iterationCount;
  float fscaling;
  int8_t *weightPtr;
  cy_nnlite_memio_dma_t *nnliteMemio;
  cy_stc_dma_descriptor_config_t *cfgDesc;
  cy_stc_dma_descriptor_t *desc;
  cy_en_nnlite_status_t status;
  void *outScalingFactorPtr;
  uint32_t outBufOffset, inBufOffset;
  uint32_t inputTransposeDesCount;
  int8_t *scratchBufIn, *scratchBufOut;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if((NULL == inputData) || (NULL == outData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == avgpoolParam) ||
      (NULL == avgpoolParam->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((avgpoolParam->padWidth != 0) || \
          (avgpoolParam->padHeight != 0))
  {
    /* Unfortunately AvgPool "padding" is actual kernel footprint truncation
     NOT zero padding (which is what we have in NNLite HW).  So padding is no-go.*/
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannel = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];
    nnliteMemio = (cy_nnlite_memio_dma_t *)avgpoolParam->scratchBuf;
    cfgDesc = (cy_stc_dma_descriptor_config_t *)(nnliteMemio + inputChannel);
    desc = (cy_stc_dma_descriptor_t *)(cfgDesc + (inputChannel * DESC_COUNT_PER_LAYER));
    weightPtr = (int8_t *)Cy_NNLite_GetAvgPoolKernelWeightPtr();

    if (inputChannel > 1)
    {
      inBufOffset = inputHeight * inputWidth;
      outBufOffset = outputHeight * outputWidth;
      scratchBufIn = (int8_t *)(desc + (inputChannel * DESC_COUNT_PER_LAYER));
      inputTransposeDesCount = Cy_NNLite_GetTransposeDescCount(inBufOffset, inputChannel);
      /* align scratchBufOut for DMA */
      scratchBufOut = scratchBufIn + (((inBufOffset * inputChannel) + 3)  & (~3))+ (inputTransposeDesCount * DMA_DESC_SIZE);
      Cy_NNLite_LinkTransposeDMA((int8_t *)cy_AhbRemapAddr(inputData), scratchBufIn, scratchBufIn,
                           inBufOffset, inputChannel, CY_NNLITE_DMA_HWC_TO_CHW);
    }
     else
    {
      scratchBufIn =  (int8_t *)inputData;
      scratchBufOut = outData;
      inBufOffset = 0;
      outBufOffset = 0;
    }

    weightPerNeuron = filterHeight * filterWidth;
    activationRepeats = 1;
     /* calculate float scaling value*/
    fscaling = 1.0 / (weightPerNeuron);
    outScalingFactorPtr = &fscaling;
    for (iterationCount = 0 ; iterationCount < inputChannel; iterationCount++)
    {
      nnliteMemio->ACTIVATIONSTREAMEROFFSET = 0;
      /* weights dims*/
      nnliteMemio->ACTIVATIONSTREAMERKERNELCHANNELTIMESWIDTH = filterWidth;
      nnliteMemio->ACTIVATIONSTREAMERKERNELHEIGHT = filterHeight;
      nnliteMemio->ACTIVATIONSTREAMERREPEATS = activationRepeats;
      /* input dims */
      nnliteMemio->ACTIVATIONSTREAMERCHANNELTIMESWIDTH = inputWidth;
      nnliteMemio->ACTIVATIONSTREAMERHEIGHT = (inputHeight);
      /* start col is 0*/
      nnliteMemio->ACTIVATIONSTREAMERSTARTCOL =
                                0 - (avgpoolParam->padWidth * 1);
      /* start row is 0 */
      nnliteMemio->ACTIVATIONSTREAMERSTARTROW =
                                0 - avgpoolParam->padHeight;
      nnliteMemio->ACTIVATIONSTREAMERPADDING = 0;
      nnliteMemio->STRIDE =
         _VAL2FLD(MXNNLITE_1_0_STRIDE_STRIDECHANNELTIMESCOLUMN,
                   avgpoolParam->strideCol * 1) |
        _VAL2FLD(MXNNLITE_1_0_STRIDE_STRIDEROW, avgpoolParam->strideRow);

      nnliteMemio->WEIGHTSTREAMERKERNELCHANNELTIMESHEIGHTTIMESWIDTH =
                                                          weightPerNeuron;
      nnliteMemio->WEIGHTSTREAMEROFFSET = 0;
      nnliteMemio->OUTSTREAMERCLIPPINGMASK = avgpoolParam->outClippingMask;
      nnliteMemio->OUTSTREAMEROUTPUTOFFSET = 0;
      nnliteMemio->OUTSTREAMERSCALINGFACTOR = *((uint32_t*)outScalingFactorPtr);
      nnliteMemio->OUTPUTWIDTH = outputWidth;
      nnliteMemio->OUTPUTHEIGHT = outputHeight;
      nnliteMemio->STREAMERMODES = MXNNLITE_1_0_STREAMERMODES_WEIGHTSTREAMERSIGNEDVALUES_Msk |
                                     MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSIGNEDVALUES_Msk |
                                     MXNNLITE_1_0_STREAMERMODES_OUTSTREAMERSIGNEDVALUES_Msk;
      /* incase of valid sparsemap,
       * weight streamer basepointer will be derived from sparsemap
       * */

      nnliteMemio->STREAMERMODES &=
          ~(_VAL2FLD(MXNNLITE_1_0_STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1));
      nnliteMemio->NONZEROWEIGHTSPOINTER = 0;
      nnliteMemio->WEIGHTSTREAMERBASEADDR = cy_CbusRemapAddr(weightPtr);
      nnliteMemio->ACTIVATIONSTREAMERBASEADDR = cy_AhbRemapAddr(scratchBufIn + (iterationCount * inBufOffset));
      nnliteMemio->OUTSTREAMERBASEADDR = (uint32_t)scratchBufOut + (iterationCount * outBufOffset);
      nnliteMemio->STREAMERMODES &=
                      ~(_VAL2FLD(MXNNLITE_1_0_STREAMERMODES_BIASEN, 1));
      nnliteMemio->NNLAYER_ACTIVATION_TYPE_CTL =
      _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_NNLAYER_TYPE_CTL,
                CY_NNLITE_CONV_LAYER) |
      _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_FUNC_EN,
                false) |
      _VAL2FLD(MXNNLITE_1_0_NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_SIZE_CTL,
                CY_NNLITE_ACTIVATION_8BIT);

      nnliteMemio->INTR_MASK = NNLITE_INTR_ERRORS_MASK;
      nnliteMemio->INTR = MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_DONE_Msk;
      nnliteMemio->INTR_SET = 0;

      /* enable NNLite DMA Trigger */
      nnliteMemio->TRIG_MASK = 1;
      nnliteMemio->CMD = _VAL2FLD(MXNNLITE_1_0_CMD_START_CMD, 1);

      Cy_NNLite_SetupNNLiteMemioDMADesc(nnliteMemio,
                                &nnliteDMAQ, cfgDesc, desc);
      nnliteMemio++;
      cfgDesc += DESC_COUNT_PER_LAYER;
      desc += DESC_COUNT_PER_LAYER;
    }
    if (inputChannel > 1)
    {
        /* this will link transpose descriptors to convolution */
        Cy_NNLite_LinkTransposeDMA(scratchBufOut, outData,
                           scratchBufOut, outBufOffset,
                           inputChannel, CY_NNLITE_DMA_CHW_TO_HWC);
    }
    if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
    {
      status = CY_NNLITE_EXTERN_API_ERR;
      Cy_NNlite_MarkDMAQueueEmpty(&nnliteDMAQ);
    }
    else
    {
        status = CY_NNLITE_OP_QUEUED;
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  return status;
}
/**
 *****************************************************************************
 ** \brief Cy_NNLite_TriggerDMAQueue will trigger DMA transfer of Queued layer
 ** starting from first queued layer, callback function will be called after
 ** completion of all the Queued layer.
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_TriggerDMAQueue(void)
{
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if (kernelContext.completionCbFunc == NULL)
  {
    /* Blocking mode, completion callback from ISR */
    kernelContext.waitForCompletion = 1;
  }
  else
  {
    /* Non blocking mode, completion callback from ISR */
    kernelContext.waitForCompletion = 0;
  }

  if(((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE)) &&
       nnliteDMAQ.dmaQDepth)
  {
     /* set current running queue */
    currDMAQ = &nnliteDMAQ;
    kernelContext.pdlContext.nnliteState = CY_NNLITE_CONFIG_STATE;

    Cy_NNLite_DMAChannelInit(&currDMAQ->channelConfig,
                               currDMAQ->headDesc);
  /* Disable DMA channel after chain */
    currDMAQ->currCfgDesc->channelState =
                                      CY_DMA_CHANNEL_DISABLED;

    currDMAQ->dmaQState = CY_NNLITE_DMA_QUEUE_TRIGGERED;
    if (currDMAQ->currDescType == CY_NNLITE_DMA_DESC_MEMIO)
    {
      /* MEMIO configuration is last dma desc,
         enable nnlite interrupt for last configuration
      */
      cy_nnlite_memio_dma_t *currMemio;
      cy_stc_dma_descriptor_config_t *firstCurrDesc;

      firstCurrDesc = currDMAQ->currCfgDesc - (DESC_COUNT_PER_LAYER - 1);
      currMemio = (cy_nnlite_memio_dma_t *)firstCurrDesc->srcAddress;
      currMemio->INTR_MASK = NNLITE_INTR_ENABLE_MASK;
    }
    else
    {
      Cy_DMA_Channel_ClearInterrupt(DW0, NNLITE_DMA_CHAN);
      /* Transpose is last dma desc, enable DMA chain interrupt */
      Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, CY_DMA_INTR_MASK);
    }

    Cy_DMA_Descriptor_Init(currDMAQ->currDesc,
                           currDMAQ->currCfgDesc);
    Cy_DMA_Channel_Enable(DW0, NNLITE_DMA_CHAN);
    kernelContext.pdlContext.nnliteState = CY_NNLITE_OP_STARTED;
    kernelContext.LpmLockFunc();
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_DMA_MODE_TRIGGER);
    Cy_TrigMux_SwTrigger(PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN0 +
                          NNLITE_DMA_CHAN,
                         CY_TRIGGER_TWO_CYCLES);
    status = CY_NNLITE_SUCCESS;
   if (kernelContext.waitForCompletion)
   {
     status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
     if (status !=  CY_NNLITE_SUCCESS)
     {
       kernelContext.waitForCompletion = 0;
       status = CY_NNLITE_EXTERN_API_ERR;
     }
     else
     {
       status = kernelContext.pdlContext.opStatus;
     }
   }

  }
  else
  {
    status =  CY_NNLITE_BAD_STATE;
  }
   kernelContext.profStop(kernelContext.profArg);
  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    status = CY_NNLITE_EXTERN_API_ERR;
    Cy_NNlite_MarkDMAQueueEmpty(currDMAQ);
  }

  return status;
}

/**
 *****************************************************************************
 ** \brief Cy_NNLite_GetCurrDMAQueue API will copy current dma queue in to
 ** dmaQueue pointer, valid dmaQueue pointer should be passed
 ** To get the runnable queue Cy_NNLite_GetCurrDMAQueue should be
 ** called after the created in Kernel DMA API such as Cy_NNLite_AvgpoolDMA
 ** and get executed by calling Cy_NNLite_TriggerDMAQueue
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_GetCurrDMAQueue(cy_nnlite_dma_queue_config_t *dmaQueue)
{
  cy_en_nnlite_status_t status;

  if (dmaQueue == NULL)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }

  dmaQueue->channelConfig = currDMAQ->channelConfig;
  dmaQueue->currCfgDesc = currDMAQ->currCfgDesc;
  dmaQueue->currDesc = currDMAQ->currDesc;
  dmaQueue->currDescType = currDMAQ->currDescType;
  dmaQueue->headDesc = currDMAQ->headDesc;
  dmaQueue->dmaQDepth = currDMAQ->dmaQDepth;
  dmaQueue->dmaQState = currDMAQ->dmaQState;

  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    status = CY_NNLITE_EXTERN_API_ERR;
  }

  return status;
}

/**
 *****************************************************************************
 ** \brief Cy_NNLite_RunDMAQueue API will Trigger DMA dmaQueue queue
 ** valid dmaQueue pointer should be passed, DMA queue should return
 ** from Cy_NNLite_GetCurrDMAQueue
 ** queue will be in  runnable state if Cy_NNLite_GetCurrDMAQueue
 ** called after queue created in Kernel DMA API such as Cy_NNLite_AvgpoolDMA
 ** and get executed by calling Cy_NNLite_TriggerDMAQueue
 ** API will work in blocking mode if callback function is passed as NULL
 ** in kernel context
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_RunDMAQueue(cy_nnlite_dma_queue_config_t *dmaQueue)
{
  cy_en_nnlite_status_t status;

  if (dmaQueue == NULL)
    return CY_NNLITE_BAD_PARAM;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  kernelContext.profStart(kernelContext.profArg);
  if(((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE)) &&
            (dmaQueue != NULL) && dmaQueue->dmaQDepth &&
            (dmaQueue->dmaQState == CY_NNLITE_DMA_QUEUE_DONE) &&
            (dmaQueue->headDesc != NULL) &&
            (dmaQueue->currDesc != NULL))
  {
    if (kernelContext.completionCbFunc == NULL)
    {
      /* Blocking mode, completion callback from ISR */
      kernelContext.waitForCompletion = 1;
    }
    else
    {
      /* Non blocking mode, completion callback from ISR */
      kernelContext.waitForCompletion = 0;
    }
    /* set current running queue */
    currDMAQ = dmaQueue;
    kernelContext.pdlContext.nnliteState = CY_NNLITE_CONFIG_STATE;

    Cy_NNLite_DMAChannelInit(&currDMAQ->channelConfig,
                               currDMAQ->headDesc);

   currDMAQ->currCfgDesc->channelState =
                                      CY_DMA_CHANNEL_DISABLED;

    currDMAQ->dmaQState = CY_NNLITE_DMA_QUEUE_TRIGGERED;
    if (currDMAQ->currDescType != CY_NNLITE_DMA_DESC_MEMIO)
    {
      Cy_DMA_Channel_ClearInterrupt(DW0, NNLITE_DMA_CHAN);
      /* Transpose is last dma desc, enable DMA chain interrupt */
      Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, CY_DMA_INTR_MASK);

    }
    else
    {
       Cy_DMA_Channel_ClearInterrupt(DW0, NNLITE_DMA_CHAN);
      /* Disable DMA chain interrupt */
      Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
    }

    Cy_DMA_Descriptor_Init(currDMAQ->currDesc,
                           currDMAQ->currCfgDesc);

    Cy_DMA_Channel_Enable(DW0, NNLITE_DMA_CHAN);
    kernelContext.pdlContext.nnliteState = CY_NNLITE_OP_STARTED;
    kernelContext.LpmLockFunc();
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_DMA_MODE_TRIGGER);
    Cy_TrigMux_SwTrigger(PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN0 +
                          NNLITE_DMA_CHAN,
                         CY_TRIGGER_TWO_CYCLES);
    if (kernelContext.waitForCompletion)
    {
      status = (cy_en_nnlite_status_t)kernelContext.SemWaitFunc(kernelContext.nnliteSem);
      if (status !=  CY_NNLITE_SUCCESS)
      {
        kernelContext.waitForCompletion = 0;
        status = CY_NNLITE_EXTERN_API_ERR;
      }
     else
     {
       status = kernelContext.pdlContext.opStatus;
     }
   }

  }
  else
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  kernelContext.profStop(kernelContext.profArg);
  if (kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex) != CY_NNLITE_SUCCESS)
  {
    status = CY_NNLITE_EXTERN_API_ERR;
  }

  return status;
}

/**
 *****************************************************************************
 ** \brief Cy_NNLite_GetQueuedLayerCount will return count of queued layer
 ** for DMA
 **
 *****************************************************************************/
uint32_t Cy_NNLite_QueuedLayerCount(void)
{
  uint32_t dmaQDepth;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }

  dmaQDepth = nnliteDMAQ.dmaQDepth;
  status = (cy_en_nnlite_status_t)kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex UnLock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  else
  {
    return dmaQDepth;
  }
}

/**
 *****************************************************************************
 ** \brief API will return return size of scratch buffer in bytes for Average
 ** pool kernel in non DMA mode, buffer size will be equal to filter
 ** dimensions
 **
 ** [in]  inputData  filter dimension
 **
 *****************************************************************************/
uint32_t Cy_NNLite_AvgpoolScratchBufSize(const cy_nn_dims_t *filterDims,
    const cy_nn_dims_t *inDims, const cy_nn_dims_t *outDims)
{
  uint32_t bufSize = 0;
  uint32_t inputTransposeDesCount;
  uint32_t outputTransposeDesCount;
  uint32_t inputHeightTimeWidth;
  uint32_t outputHeightTimeWidth;
  uint32_t channel;
  cy_en_nnlite_status_t status;
  (void)filterDims;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }

  if (inDims && outDims)/* scratchBuf  for transpose & DMA*/
  {
    if (inDims->dims[3]  > 1)
    {
      outputHeightTimeWidth = outDims->dims[1] * outDims->dims[2];
      inputHeightTimeWidth = inDims->dims[1] * inDims->dims[2];
      channel = outDims->dims[3];

      bufSize = ((inputHeightTimeWidth * channel) + 3) & (~3);
      bufSize += ((outputHeightTimeWidth * channel) + 3) & (~3);
      if (inDims->dims[3]  <= CY_DMA_LOOP_COUNT_MAX) // chan > CY_DMA_LOOP_COUNT_MAX, case of CPU based trasnpose
      {
        inputTransposeDesCount =
          Cy_NNLite_GetTransposeDescCount(inputHeightTimeWidth, channel);
        outputTransposeDesCount =
          Cy_NNLite_GetTransposeDescCount(outputHeightTimeWidth, channel);

        bufSize += inputTransposeDesCount * DMA_DESC_SIZE;
        bufSize += outputTransposeDesCount * DMA_DESC_SIZE;
      }
    }

  }
  status = (cy_en_nnlite_status_t)kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex UnLock Failed */
    return status;
  }
  else
  {
    return bufSize;
  }

}

/**
 *****************************************************************************
 ** \brief API will return return size of scratch buffer in bytes for Average
 ** pool kernel in DMA mode, buffer size will be equal to filter dimensions
 ** plus cy_nnlite_memio_dma_t and dma descriptors, cy_nnlite_memio_dma_t will
 ** be used as source pointer having nnlite MEMIO configuration
 **
 ** [in]  filterDims  filter dimension
 **
 *****************************************************************************/
uint32_t Cy_NNLite_AvgpoolDMAScratchBufSize(const cy_nn_dims_t *filterDims,
                      const cy_nn_dims_t *inDims, const cy_nn_dims_t *outDims)
{
  uint32_t bufSize = 0;
  uint32_t inputTransposeDesCount;
  uint32_t outputTransposeDesCount;
  uint32_t inputHeightTimeWidth;
  uint32_t outputHeightTimeWidth;
  uint32_t channel;
  cy_en_nnlite_status_t status;
  (void)filterDims;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }

  if (inDims && outDims)/* scratchBuf  for transpose & DMA*/
  {
    if (inDims->dims[3]  > 1)
    {
      outputHeightTimeWidth = outDims->dims[1] * outDims->dims[2];
      inputHeightTimeWidth = inDims->dims[1] * inDims->dims[2];
      channel = outDims->dims[3];

      bufSize = ((inputHeightTimeWidth * channel) + 3) & (~3);
      bufSize += ((outputHeightTimeWidth * channel) + 3) & (~3);

      inputTransposeDesCount =
        Cy_NNLite_GetTransposeDescCount(inputHeightTimeWidth, channel);
      outputTransposeDesCount =
        Cy_NNLite_GetTransposeDescCount(outputHeightTimeWidth, channel);

      bufSize += inputTransposeDesCount * DMA_DESC_SIZE;
      bufSize += outputTransposeDesCount * DMA_DESC_SIZE;
    }
    bufSize += (sizeof(cy_nnlite_memio_dma_t) * (inDims->dims[3]));
    bufSize += (inDims->dims[3] * DESC_COUNT_PER_LAYER * DMA_DESC_SIZE);

  }
  status = (cy_en_nnlite_status_t)kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex UNLock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  else
  {
    return bufSize;
  }

}

/**
 *****************************************************************************
 ** \brief ConvolutionScratchBufSize API will return scratch buffer size for
 ** convolution kernel CPU mode, buffer will be used for transpose function
 ** which will required scratch buffer equal to out buffer plus DMA
 ** descriptor, count of descriptors depends on size of output buffer
 ** if all scaling factor pointed by outScalingFactor are equal, transpose
 ** functionality will not be required and size return will be 0 bytes
 **
 ** [in]  filterDims  filter dimension
 ** [in]  outputDims  output dimension
 ** [in]  outScalingFactor scaling factor array pointer
 **
 *****************************************************************************/
uint32_t Cy_NNLite_ConvolutionScratchBufSize(const cy_nn_dims_t *filterDims,
                                             const cy_nn_dims_t *outputDims,
                                             float *outScalingFactor)
{
  uint32_t bufSize, transposeDesCount;
  uint32_t descBufSize, heightTimeWidth, channel;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }

  if ((NULL == filterDims) || (NULL == outputDims) || (NULL == outScalingFactor))
  {
    bufSize = 0;
  }
  else if (isScalingFactorEqual(outScalingFactor, filterDims->dims[0]))
  {
    bufSize = 0;
  }
  else
  {
    heightTimeWidth = outputDims->dims[1] * outputDims->dims[2];
    channel = outputDims->dims[3];
    /* outbuf size for transpose*/
    bufSize = ((heightTimeWidth * channel) + 3) & (~3);
    transposeDesCount =
      Cy_NNLite_GetTransposeDescCount(heightTimeWidth, channel);
    /* transpose DMA descriptor size */
    descBufSize = (transposeDesCount * DMA_DESC_SIZE);

    /* total size */
    bufSize +=  descBufSize;
  }
  status = (cy_en_nnlite_status_t)kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex UnLock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  else
  {
    return bufSize;
  }
}

/**
  *****************************************************************************
** \brief Cy_NNLite_ConvolutionDMAScratchBufSize API will return scratch
 ** buffer size for convolution kernel DMA mode, buffer will be used for
 ** cy_nnlite_memio_dma_t * number of filters plus transpose function which
 ** will required scratch buffer equal to out buffer plus DMA descriptors,
 ** count of descriptors depends on size of output buffer
 ** if all scaling factor pointed by outScalingFactor are equal, transpose
 ** functionality will not be required, buffer size will be only for DMA
 ** operation
 **
 ** [in]  filterDims  filter dimension
 ** [in]  outputDims  output dimension
 ** [in]  outScalingFactor scaling factor array pointer
 **
 *****************************************************************************/
uint32_t Cy_NNLite_ConvolutionDMAScratchBufSize(const cy_nn_dims_t *filterDims,
                                             const cy_nn_dims_t *outputDims,
                                             float *outScalingFactor)
{
  uint32_t bufSize, transposeDesCount;
  uint32_t heightTimeWidth, channel;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  if ((NULL == filterDims) || (NULL == outputDims) || (NULL == outScalingFactor))
  {
    bufSize = 0;
  }
  else if (isScalingFactorEqual(outScalingFactor, filterDims->dims[0]))
  {
    bufSize = sizeof(cy_nnlite_memio_dma_t) +
            (DMA_DESC_SIZE * DESC_COUNT_PER_LAYER);
  }
  else
  {
    heightTimeWidth = outputDims->dims[1] * outputDims->dims[2];
    channel = outputDims->dims[3];

    /* per axis convolution, we need per axis nnlite_memio_dma*/
    bufSize = (sizeof(cy_nnlite_memio_dma_t) * filterDims->dims[0]);
    /* outbuf for transpose */
    bufSize += ((heightTimeWidth * channel) + 3) & (~3);
    transposeDesCount = Cy_NNLite_GetTransposeDescCount(heightTimeWidth, channel);
    /* per axis convolution DMA descriptor size */
    bufSize += (filterDims->dims[0] * DESC_COUNT_PER_LAYER * DMA_DESC_SIZE);

    /* transpose DMA descriptor size */
    bufSize += transposeDesCount * DMA_DESC_SIZE;
  }
  status = (cy_en_nnlite_status_t)kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex UNLock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  else
  {
    return bufSize;
  }
}

/**
 *****************************************************************************
 ** API will return scratch buffer size for fully connected DMA mode kernel,
 ** buffer will be used for DMA descriptors and for MEMIO configuration
 ** structure of type cy_nnlite_memio_dma_t for DMA
 **
 *****************************************************************************/
uint32_t Cy_NNLite_FullyConnectedDMAScratchBufSize (void)
{
  uint32_t bufSize;
  cy_en_nnlite_status_t status;

  status = (cy_en_nnlite_status_t)kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex Lock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  bufSize = sizeof(cy_nnlite_memio_dma_t) +
            (DMA_DESC_SIZE * DESC_COUNT_PER_LAYER);

  status = (cy_en_nnlite_status_t)kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  if (status != CY_NNLITE_SUCCESS)
  {
     /* Mutex UnLock Failed */
    return CY_NNLITE_EXTERN_API_ERR;
  }
  else
  {
    return bufSize;
  }

}

#endif //CY_IP_MXNNLITE_VERSION

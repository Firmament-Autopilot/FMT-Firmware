/***************************************************************************//**
 * \file  cy_nn_kernel.c
 * \version 2.0
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
#include "cy_device.h"
#if CY_IP_MXNNLITE_VERSION == 2
#include "cy_nn_kernel.h"
#include "cy_nn_kernel_private.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#if defined(IFX_NNLITE_ZYNQ)
#include "xil_exception.h"
#include "xscugic.h"
#endif

#if !defined(__WEAK)

/* Not even every version of gcc implements working weak Linkage!  Notably
   windows-hosted x86_64 builds are broken and will segfault with weak symbols
   resolved as NULL.
*/
#ifndef __WIN32
#define __WEAK  __attribute__((weak))
#else

   /* Weak linkage broken on WIN32 / WIN64 targets */
#define __WEAK
#endif
#endif // !defined(__WEAK)



#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
/** Dummy NNLite register struct for PDL emulation */
static NNLITE_Type nnlite_regs;
static NNLITE_Type *MXNNLITE_REGS = &nnlite_regs;
#else
#define MXNNLITE_REGS                            ((MXNNLITE_2_0_Type*) MXNNLITE_2_0_BASE)
#endif


#ifdef IFX_USE_MXNNLITE_STREAM_EMU

/*
* Reasonable startup so pdl emulation works "out of the box" on
* host/hosted builds
*/

static uint32_t noopFunc() { return 0; }

static cy_kernel_context_t kernelContext =
{
  .nnliteMutex = 0,
  .nnliteSem = 0,
  .completionCbFunc = 0,
  .suspendedCbFunc = 0,
  .cbArg = 0,
  .mutexLockFunc = noopFunc,
  .mutexUnlockFunc = noopFunc,
  .SemGiveFunc = noopFunc,
  .SemWaitFunc = noopFunc,
  .pdlContext = {
    .nnliteState = CY_NNLITE_INIT,
    .opStatus = CY_NNLITE_SUCCESS
  }
};
#else
  /*
  * On real platform segfault if no sync primitive setup...
  */
  static cy_kernel_context_t kernelContext = {0};
  #if  CY_NNLITE_DMA_DEVICE
      static cy_nnlite_dma_queue_config_t nnliteDMAQ = {0};
      static cy_nnlite_dma_queue_config_t *currDMAQ = &nnliteDMAQ;
  #endif
#endif

#ifndef MIN
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif

/**
 *****************************************************************************
 ** \brief  NNLite ISR, Error or completion interrupt
 ** calls completion handles functions
 **
 *****************************************************************************/
void Cy_NNLite_Isr(void)
{
#if  CY_NNLITE_DMA_DEVICE
  if (currDMAQ->dmaQDepth &&
  (currDMAQ->dmaQState == CY_NNLITE_DMA_QUEUE_TRIGGERED) &&
  (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_STARTED))
  {
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_DMA_MODE_END);

    currDMAQ->dmaQState = CY_NNLITE_DMA_QUEUE_DONE;
    Cy_DMA_Channel_ClearInterrupt(DW0, NNLITE_DMA_CHAN);

  }
  else
#endif //CY_NNLITE_DMA_DEVICE
  {
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_DONE);
  }
  Cy_NNLite_InterruptHandler(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (kernelContext.completionCbFunc == NULL)
  {
    kernelContext.SemGiveFunc(kernelContext.nnliteSem);
  }
  else
  {
    kernelContext.profStop(kernelContext.profArg);
    kernelContext.LpmUnlockFunc();
    kernelContext.completionCbFunc(
        kernelContext.cbArg,
        kernelContext.pdlContext.opStatus);
  }

}
#if  CY_NNLITE_DMA_DEVICE
static void Cy_NNLite_DMAIsr(void)
{
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
    Cy_NNLite_InterruptHandler(MXNNLITE_REGS, &kernelContext.pdlContext);
    kernelContext.LpmUnlockFunc();
  }

}
#endif

static uint32_t totalElts( const cy_nn_dims_t *nn_dims) {
  return nn_dims->dims[0]*nn_dims->dims[1]*nn_dims->dims[2]*nn_dims->dims[3];
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
#if !defined(IFX_USE_MXNNLITE_STREAM_EMU) && !defined(IFX_NNLITE_ZYNQ) && !defined(ETISS_RISCV)
  /* Populate isr configuration structure */
  cy_stc_sysint_t NNLITE_IRQ_cfg =
  {
    .intrSrc      = mxnnlite_interrupt_mxnnlite_IRQn,
    .intrPriority = NNLITE_DEFAULT_ISR_PRIORITY,
  };
#if  CY_NNLITE_DMA_DEVICE
  cy_stc_sysint_t DMA_IRQ_cfg = {
  .intrSrc =
   ((IRQn_Type)(m33syscpuss_interrupts_dw0_0_IRQn + NNLITE_DMA_CHAN)),
  .intrPriority = NNLITE_DEFAULT_ISR_PRIORITY,
  };
#endif
#endif
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
#if !defined(IFX_USE_MXNNLITE_STREAM_EMU)
        status = Cy_NNLite_Init(MXNNLITE_REGS, &kernelContext.pdlContext);
#endif
        if (status == CY_NNLITE_SUCCESS)
        {
          Cy_NNLite_SetInterruptMask(MXNNLITE_REGS, 0);
#if !defined(IFX_USE_MXNNLITE_STREAM_EMU)
          if ((kernelConfig->intrPriority != 0) &&
                CY_SYSINT_IS_PRIORITY_VALID(kernelConfig->intrPriority))
          {
            NNLITE_IRQ_cfg.intrPriority = kernelConfig->intrPriority;
#if  CY_NNLITE_DMA_DEVICE
            DMA_IRQ_cfg.intrPriority = kernelConfig->intrPriority;
#endif
          }
          Cy_SysInt_Init(&NNLITE_IRQ_cfg, Cy_NNLite_Isr);
          /* Enable the interrupt */
          NVIC_EnableIRQ(NNLITE_IRQ_cfg.intrSrc);

#if  CY_NNLITE_DMA_DEVICE
          Cy_DMA_Enable(DW0);
          Cy_DMA_Channel_SetInterruptMask(DW0, NNLITE_DMA_CHAN, 0);
          Cy_TrigMux_Connect(PERI_0_TRIG_IN_MUX_0_MXNNLITE_TR_MXNNLITE,
                  PERI_0_TRIG_OUT_MUX_0_PDMA0_TR_IN0 + NNLITE_DMA_CHAN,
                  false, TRIGGER_TYPE_LEVEL);
          Cy_SysInt_Init(&DMA_IRQ_cfg, Cy_NNLite_DMAIsr);
                     /* Enable the interrupt */
          NVIC_EnableIRQ(DMA_IRQ_cfg.intrSrc);
#endif

          /* enable nnlite from SCTL */
          Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_MXNNLITE_PERI_NR,
            CY_MMIO_MXNNLITE_GROUP_NR, CY_MMIO_MXNNLITE_SLAVE_NR,
            CY_MMIO_MXNNLITE_CLK_HF_NR);

#elif defined(IFX_NNLITE_ZYNQ)
          Xil_ExceptionInit();
          /*
          * Initialize the interrupt controller driver so that it is ready to
          * use.
          */
          GicConfig = XScuGic_LookupConfig(XPAR_SCUGIC_SINGLE_DEVICE_ID);
          if (NULL == GicConfig) {
            return CY_NNLITE_BAD_STATE;
          }

          {
            int ret = XScuGic_CfgInitialize(&IntcInstance, GicConfig,
                  GicConfig->CpuBaseAddress);
            if (ret != XST_SUCCESS) {
              return CY_NNLITE_BAD_STATE;
            }
          }
          /*
          * Connect the interrupt controller interrupt handler to the hardware
          * interrupt handling logic in the processor.
          */
          Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_IRQ_INT,
              (Xil_ExceptionHandler)XScuGic_InterruptHandler,
              &IntcInstance);
          XScuGic_Connect(&IntcInstance, XPAR_FABRIC_MXNNLITE_TOP_WITH_BR_0_INTERRUPT_MXNNLITE_INTR, (Xil_InterruptHandler)Cy_NNLite_Isr, NULL);
          XScuGic_Enable(&IntcInstance, XPAR_FABRIC_MXNNLITE_TOP_WITH_BR_0_INTERRUPT_MXNNLITE_INTR);
          Xil_ExceptionEnable();
#elif defined(ETISS_RISCV)
        // sofar nothing todo for ETISS_RISCV IP-FW integration, the call to "Cy_NNLite_DMAIsr()" is hard wired in the wrapper code.
#endif
        }
        else /* NNLite Init failed, delete sem and mutex created */
        {
          kernelContext.mutexDeleteFunc(kernelContext.nnliteMutex);
          kernelContext.SemDeleteFunc(kernelContext.nnliteSem);
        }
      }
      else /* sem create failed, delete mutex created earlier */
      {
        kernelContext.mutexDeleteFunc(kernelContext.nnliteMutex);
      }
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
  status = Cy_NNLite_DeInit(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
    Cy_NNLite_SetInterruptMask(MXNNLITE_REGS, 0);
    /* Disable the interrupt */
    NVIC_DisableIRQ(mxnnlite_interrupt_mxnnlite_IRQn);
#if  CY_NNLITE_DMA_DEVICE
    NVIC_DisableIRQ((IRQn_Type)(m33syscpuss_interrupts_dw0_0_IRQn + NNLITE_DMA_CHAN));
#endif
    status |= kernelContext.mutexDeleteFunc(kernelContext.nnliteMutex);
    status |= kernelContext.SemDeleteFunc(kernelContext.nnliteSem);
#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
#elif defined(IFX_MXNNLITE_ZYNQ)
    #pragma GCC warning "Need Interrupt disabling code for PS on Zynq prototype"
#elif defined(ETISS_RISCV)
    // Nothing to be done for ETISS IP integration so far.
#else
     /* disable nnlite from SCTL */
    Cy_SysClk_PeriGroupSlaveDeinit(CY_MMIO_MXNNLITE_PERI_NR,
       CY_MMIO_MXNNLITE_GROUP_NR, CY_MMIO_MXNNLITE_SLAVE_NR);
#endif
  }
  return status;
}

/**
 * @brief Start of execution of multi-operation kernel
 *
 * This forces each operation kernel to wait for completion before exiting.
 *
 */
void Cy_NNLite_StartMacroKernel(void)
{
  kernelContext.suspendedCbFunc = kernelContext.completionCbFunc;
  kernelContext.completionCbFunc = 0;
}

/**
 * @brief End of execution of multi-operation kernel
 *
 * This restores original completion behaviour and calls completion callback
 * (if defined)
 *
 */

void Cy_NNLite_EndMacrokernel(void)
{
  kernelContext.completionCbFunc = kernelContext.suspendedCbFunc;
  if (kernelContext.completionCbFunc != 0) {
    kernelContext.completionCbFunc(
        kernelContext.cbArg,
        kernelContext.pdlContext.opStatus);
  }
}


/**
 *****************************************************************************
 ** \brief Set PWL interpolation parameters for LeakyRElU activation
 **
 ** [in]  alpha_scale    LeakyRelU  scale for alpha parameter (may fold in a rescaling factor)
 ** [in]  unit_scale    LeakyRelU  scale for unit gradient (may fold in a rescaling factor)
 ** [in]  inParam  Pointer to PWL activation struct to set for specified @c alpha
 *****************************************************************************/

void Cy_NNLite_LeakyRelUPWLActivation(float alpha_scale, float unit_scale, cy_nn_act_intrpl_param_t *leakyRelU)
{
    leakyRelU->segment[0] = unit_scale;  // [0,+inf]
    leakyRelU->segment[1] = alpha_scale; //[-inf,0)
}

/**
 *****************************************************************************
 ** \brief Setup scale factors for PWL and other activations for next NNLite operation
 **
 ** [in]  inParam  Pointer to PWL activation scale factors NULL indicates default
 **       unity scale factor should be set for non-PWL activation
 *****************************************************************************/

void Cy_NNLite_SetPWLActivation(NNLITE_Type *MMIO, cy_nn_act_intrpl_param_t *inParam)
{
  if (inParam != NULL) {
    Cy_NNLite_SetInterpolationParam(MMIO, 0, inParam->segment[0]);
    Cy_NNLite_SetInterpolationParam(MMIO, 1, inParam->segment[1]);
  }  else {
    Cy_NNLite_SetInterpolationParam(MMIO, 0, 1.0f);
    Cy_NNLite_SetInterpolationParam(MMIO, 1, 1.0f);
  }

}

/**
 * \brief Wait for completion of intermediate NNLite operations
 *

 * \return completion status of partial op
 */
static cy_en_nnlite_status_t
Cy_NNLite_WaitForCompletionPartialOp(void)
{
  /* Wait for filter operation to complete if there is no completion callback set. */
  if (kernelContext.completionCbFunc == 0)
  {
    kernelContext.SemWaitFunc(kernelContext.nnliteSem);
  }
  return kernelContext.pdlContext.opStatus;
}

/**
 *****************************************************************************
 ** @brief Set weight/activation fetch for a sparse weights structure
 **
 ** @note Only supported for non-depthwise sum-of-product operations
 **
 **  struct {
 **     uint16_t sopWeightCounts[activation_repeats];
 **     uint8_t  sparsityBitmap[sparsity_map_len_bytes]
 **     uint8_t  weights[\Sigma_{i} non_zero_weights[i]
 **   }
 **
 **  [in]  packedSparseWeights packed sparse weight structure (see above)
 **
 **  [in]  weightsPerSOP    Vector of number of weights for each individual sum-of-products
 **
 **  [in]  numSOP           Number of sums-of-products
 **
 *****************************************************************************/
static void
Cy_NNLite_SparseWeights(NNLITE_Type *Memio, const void *packedSparseWeights,
                        uint32_t weightsPerSOP, uint32_t numSOP)
{
  uint32_t numWeights = numSOP * weightsPerSOP;
  uint32_t sparsityMapSize = (numWeights +7u)/8u;

  /* nonzero wt pointer each of length 2 bytes */
  void *sopWeightCountsAddr = (void *)packedSparseWeights;
  void *sparsityBitmapAddr = (void *)(((int16_t *)packedSparseWeights) + numSOP);
  void *weights = (void *)(((int8_t *)sparsityBitmapAddr) + sparsityMapSize);


  (void)Cy_NNLite_StreamerBaseAddrSet(Memio, CY_NNLITE_WEIGHT_STREAMER, weights);
  (void)Cy_NNLite_StreamerBaseAddrSet(Memio, CY_NNLITE_WEIGHT_COUNT_STREAMER, sopWeightCountsAddr);
  (void)Cy_NNLite_StreamerBaseAddrSet(Memio, CY_NNLITE_SPARSITY_MAP_STREAMER, sparsityBitmapAddr);
}

/**
 *****************************************************************************
 ** \brief 2D Convolution CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 **
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
 ** [in]  intrplParam      interpolation param for PWL output activation , null = nothing set
 **
 *****************************************************************************/
cy_en_nnlite_status_t
__Cy_NNLite_Convolution(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam, bool dmaMode)
{
  uint32_t inputWidth, inputHeight, inputChannel;
  uint32_t weightPerNeuron, activationRepeats;
  uint32_t outputWidth, outputHeight, outputChannels;
  uint32_t numFilters, filterWidth, filterHeight;

  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);

  if( (NULL == filterData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == convParam) ||
      (NULL == inputData) || (NULL == outData) ||
      (NULL == convParam->outScalingFactor))

  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == convParam->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }

  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    bool biasEn = biasData != NULL;
    numFilters = filterDims->dims[0];
    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannel = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];
    outputChannels = outputDims->dims[3];

    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)convParam->scratchBuf : MXNNLITE_REGS ;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;
    /* compute weight per neuron,
    filter channel == input channel
    */
    weightPerNeuron = filterHeight * filterWidth * inputChannel;

    /* activation repeat is equal to number of filters or output depth */
    activationRepeats = MIN(outputChannels, numFilters);

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeats, inputWidth,
        inputHeight, inputChannel,
        convParam->padValue, convParam->padWidth,
        convParam->padHeight, convParam->strideCol,
        convParam->strideRow, convParam->inputOffset);

    Cy_NNLite_WeightStreamerCfg(Memio, &kernelContext.pdlContext,
        weightPerNeuron, convParam->filterOffset);

    Cy_NNLite_PipelineConfig(Memio,

        /* opType= */ CY_NNLITE_MUL,
        /* fetchMode = */ CY_NNLITE_ACT_WGT,
        /* repeatWeights = */ false,
        /* biasEn = */ biasEn,
        /* sparsityEn = */ (convParam->sparseWeights?1:0),
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_AXIS,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        actType,
        convParam->act_size,
        CY_NNLITE_ACTIVATION_8BIT,
        CY_NNLITE_ACT_AS_OUT_BW(convParam->act_size)
        );

    Cy_NNLite_SetPWLActivation(Memio, intrplParam);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_ACTIVATION_STREAMER, inputData);

    Cy_NNLite_SetInterruptMask(Memio, intrMask);

    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);


    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
        convParam->outClipping, convParam->outputOffset,
        outputWidth, outputHeight,
        1 /* was: outputChannels workaround NNLite V2.3.0 bug AIMLXLR8R-513 */);

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ 0.0f,
      /*postScalingFactors=*/convParam->outScalingFactor);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_OUT_STREAMER,
        outData);

    // If Sparse weights need to set act streamer sparsity map pointers to relevant fields
    // as well as weights pointer.
    if (convParam->sparseWeights)
    {
      uint32_t weightsPerSOP = filterHeight * filterWidth * inputChannel;
      Cy_NNLite_SparseWeights(Memio, filterData, weightsPerSOP, numFilters);
    }
    else
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_WEIGHT_STREAMER, filterData);
    }

    if(biasEn)
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_BIAS_STREAMER, biasData);
    }
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      if(status == CY_NNLITE_SUCCESS)
      {
        status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(convParam->scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;

    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);

  return status;
}

/**
 *****************************************************************************
 ** \brief Depthwise Convolution CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
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
 ** [in]  intrplParam      interpolation param for PWL output activation, null = nothing set
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Convolution(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  cy_en_nnlite_status_t status;
    status = __Cy_NNLite_Convolution(inputData, outData,
    inputDims, outputDims, filterDims, filterData,
    biasData, convParam, actType, intrplParam, false);

   return status;
}

#if  CY_NNLITE_DMA_DEVICE

cy_en_nnlite_status_t
Cy_NNLite_ConvolutionDMA(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  cy_en_nnlite_status_t status;
    status = __Cy_NNLite_Convolution(inputData, outData,
    inputDims, outputDims, filterDims, filterData,
    biasData, convParam, actType, intrplParam, 1);

   return status;
}

#endif

cy_en_nnlite_status_t
__Cy_NNLite_DepthwiseConvolution(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam, bool dmaMode)
{
  uint32_t inputWidth, inputHeight, inputChannels;
  uint32_t weightPerNeuron, activationRepeats;
  uint32_t outputWidth, outputHeight, outputChannels;
  uint32_t numFilters, filterWidth, filterHeight;
  uint32_t depthMultiplier;
  int8_t  *weightPtr;

  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if( (NULL == filterData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == convParam) ||
      (NULL == inputData) || (NULL == outData) ||
      (NULL == convParam->outScalingFactor))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == convParam->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (outputDims->dims[3] != filterDims->dims[3]) {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    bool biasEn = biasData != NULL;
    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    numFilters = filterDims->dims[3];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannels = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];
    outputChannels = outputDims->dims[3];

    depthMultiplier = numFilters/inputChannels;

    weightPerNeuron =  filterHeight * filterWidth;

    /* Need to fetch each footprint for each depth multiplication...
     */

    activationRepeats = depthMultiplier;

    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)convParam->scratchBuf : MXNNLITE_REGS;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;

    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeats, inputWidth,
        inputHeight, inputChannels,
        convParam->padValue, convParam->padWidth,
        convParam->padHeight, convParam->strideCol,
        convParam->strideRow, convParam->inputOffset);

    Cy_NNLite_SetPWLActivation(Memio, intrplParam);

    Cy_NNLite_WeightStreamerCfg(Memio, &kernelContext.pdlContext,
        weightPerNeuron*numFilters,
        convParam->filterOffset);

    Cy_NNLite_PipelineConfig(Memio,

        /* opType= */ CY_NNLITE_MUL,
        /* fetchMode = */ CY_NNLITE_DWACT_WGT,
        /* repeatWeights = */ false,
        /* biasEn = */ biasEn,
        /* sparsityEn = */ false,
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_AXIS,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        actType,
        convParam->act_size,
        CY_NNLITE_ACTIVATION_8BIT,
        CY_NNLITE_ACT_AS_OUT_BW(convParam->act_size)
    );

    weightPtr = (int8_t *)filterData;

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_ACTIVATION_STREAMER, inputData);

    Cy_NNLite_SetInterruptMask(Memio, intrMask);

    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
        convParam->outClipping, convParam->outputOffset,
        outputWidth, outputHeight, outputChannels);

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ 0.0f,
      /*postScalingFactors=*/convParam->outScalingFactor);


    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_WEIGHT_STREAMER,
        weightPtr);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_OUT_STREAMER,
        outData);

    if(biasEn)
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_BIAS_STREAMER, biasData);
    }
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);    /*Only await completion of final transpose if sync mode */
      if(status == CY_NNLITE_SUCCESS)
      {
        status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(convParam->scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;

    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);

  return status;
}


cy_en_nnlite_status_t
Cy_NNLite_DepthwiseConvolution(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  return __Cy_NNLite_DepthwiseConvolution(inputData, outData,
             inputDims, outputDims, filterDims, filterData,
             biasData,convParam, actType, intrplParam, false);
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_DepthwiseConvolutionDMA(const int8_t *inputData, int8_t *outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_conv_params_t *convParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
        return __Cy_NNLite_DepthwiseConvolution(inputData, outData,
             inputDims, outputDims, filterDims, filterData,
             biasData,convParam, actType, intrplParam, true);
}
#endif


cy_en_nnlite_status_t
__Cy_NNLite_FullyConnected(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_fc_params_t *fcParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam, bool dmaMode)
{
  uint32_t filterWidth, filterHeight;
  uint32_t inputWidth, inputHeight;
  uint32_t activationRepeats;
  uint32_t weightPerNeuron;
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);

  if((NULL == inputData) || (NULL == outData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == fcParam) ||
      (NULL == filterData))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == fcParam->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if(inputDims->dims[0] != outputDims->dims[0]) {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
            (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    bool biasEn = biasData != NULL;

    filterWidth = filterDims->dims[1];
    filterHeight = 1;
    inputWidth = inputDims->dims[1];
    inputHeight = inputDims->dims[0];
    activationRepeats = MIN(filterDims->dims[0], outputDims->dims[1]);
    weightPerNeuron = filterWidth;
    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)fcParam->scratchBuf : MXNNLITE_REGS;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeats,
        inputWidth, inputHeight, 1 /* input channels */,
        0, 0, 0, /* pad value, width, height */
        0, 1, /*  stride col, stride row  - batch dimension is "height" */
        fcParam->inputOffset /* input offset */
        );

    Cy_NNLite_SetPWLActivation(Memio, intrplParam);

    Cy_NNLite_WeightStreamerCfg(Memio, &kernelContext.pdlContext,
        weightPerNeuron, fcParam->filterOffset);

    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
        fcParam->outClipping, fcParam->outputOffset,
        1, inputHeight,
        1 /* was: activationRepeats workaround NNLite V2.3.0 bug AIMLXLR8R-513 */);

    // If Sparse weights need to set act streamer sparsity map pointers to relevant fields
    // as well as weights pointer.
    if (fcParam->sparseWeights)
    {
      Cy_NNLite_SparseWeights(Memio, filterData, filterDims->dims[1], filterDims->dims[0]);
    }
    else
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_WEIGHT_STREAMER, filterData);
    }

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_ACTIVATION_STREAMER, inputData);
    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_OUT_STREAMER, outData);
    if(biasEn)
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_BIAS_STREAMER, biasData);
    }

    Cy_NNLite_PipelineConfig(Memio,

        /* opType= */ CY_NNLITE_MUL,
        /* fetchMode = */ CY_NNLITE_ACT_WGT,
        /* repeatWeights = */ false,
        /* biasEn = */ biasEn,
        /* sparsityEn = */ (fcParam->sparseWeights?1:0),
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_TENSOR,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        actType,
        fcParam->inputSize,
        CY_NNLITE_ACTIVATION_8BIT,
        fcParam->outputSize
    );

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ 0.0f,
      /*postScalingFactors=*/&fcParam->outScalingFactor);

    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);
    Cy_NNLite_SetInterruptMask(Memio, intrMask);
    if (!dmaMode)
    {

        kernelContext.LpmLockFunc();
        kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
        status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
        if (status == CY_NNLITE_SUCCESS)
        {
            status = Cy_NNLite_WaitForCompletionPartialOp();
        }
        if (kernelContext.completionCbFunc == 0)
        {
          kernelContext.LpmUnlockFunc();
        }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
        cy_stc_dma_descriptor_config_t *cfgDesc;
        cy_stc_dma_descriptor_t *desc;
        Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
        cfgDesc = (cy_stc_dma_descriptor_config_t *)(fcParam->scratchBuf + sizeof(NNLITE_Type));
        desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

        Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
        status = CY_NNLITE_OP_QUEUED;
    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);

  return status;
}

cy_en_nnlite_status_t
__Cy_NNLite_FullyConnected_batch(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_fc_params_t *fcParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam, bool dmaMode)
{
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);

  if( (NULL == filterData) ||
      (NULL == inputDims) || (NULL == outputDims) ||
      (NULL == filterDims) || (NULL == fcParam) ||
      (NULL == inputData) || (NULL == outData) ||
      (NULL == fcParam->scratchBuf))

  {
    status = CY_NNLITE_BAD_PARAM;
  }

  else if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    bool biasEn = biasData != NULL;
    uint32_t inputWidth, inputHeight, inputChannel;
    uint32_t weightPerNeuron, activationRepeats;
    uint32_t outputWidth, outputHeight, outputChannels;
    uint32_t numFilters, filterWidth, filterHeight;

    numFilters = filterDims->dims[0];
    filterHeight = 1;
    filterWidth = 1;

    inputHeight = inputDims->dims[0];
    inputWidth = 1;
    inputChannel = inputDims->dims[1];

    outputHeight = outputDims->dims[0];
    outputWidth = 1;
    outputChannels = outputDims->dims[1];

    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)fcParam->scratchBuf : MXNNLITE_REGS ;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;
    float *scaling = dmaMode ? (float *)(fcParam->scratchBuf + CY_NNLITE_DMA_SCRATCH_BUFFER_SIZE): (float *)fcParam->scratchBuf;
    /* compute weight per neuron,
    filter channel == input channel
    */
    weightPerNeuron = filterHeight * filterWidth * inputChannel;

    /* activation repeat is equal to number of filters or output depth */
    activationRepeats = MIN(outputChannels, numFilters);

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeats, inputWidth,
        inputHeight, inputChannel,
        0, 0,
        0, 0,
        1, fcParam->inputOffset);

    Cy_NNLite_WeightStreamerCfg(Memio, &kernelContext.pdlContext,
        weightPerNeuron, fcParam->filterOffset);

    Cy_NNLite_PipelineConfig(Memio,

        /* opType= */ CY_NNLITE_MUL,
        /* fetchMode = */ CY_NNLITE_ACT_WGT,
        /* repeatWeights = */ false,
        /* biasEn = */ biasEn,
        /* sparsityEn = */ (fcParam->sparseWeights?1:0),
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_AXIS,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        actType,
        fcParam->inputSize,
        CY_NNLITE_ACTIVATION_8BIT,
        fcParam->outputSize
        );

    Cy_NNLite_SetPWLActivation(Memio, intrplParam);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_ACTIVATION_STREAMER, inputData);

    Cy_NNLite_SetInterruptMask(Memio, intrMask);

    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);


    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
        fcParam->outClipping, fcParam->outputOffset,
        outputWidth, outputHeight,
        outputChannels /* was: outputChannels workaround NNLite V2.3.0 bug AIMLXLR8R-513 */);
    for (uint32_t cnt = 0 ; cnt < outputDims->dims[1]; cnt++)
    {
      scaling[cnt] = fcParam->outScalingFactor;
    }

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ 0.0f,
      /*postScalingFactors=*/scaling);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_OUT_STREAMER,
        outData);

    // If Sparse weights need to set act streamer sparsity map pointers to relevant fields
    // as well as weights pointer.
    if (fcParam->sparseWeights)
    {
      uint32_t weightsPerSOP = filterHeight * filterWidth * inputChannel;
      Cy_NNLite_SparseWeights(Memio, filterData, weightsPerSOP, numFilters);
    }
    else
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_WEIGHT_STREAMER, filterData);
    }

    if(biasEn)
    {
      Cy_NNLite_StreamerBaseAddrSet(Memio,
          CY_NNLITE_BIAS_STREAMER, biasData);
    }
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      if(status == CY_NNLITE_SUCCESS)
      {
        status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(fcParam->scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;

    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);

  return status;
}

/**
 *****************************************************************************
 ** \brief Fully connected kernel API, API will configure nnlite and
 ** then start nnlite operation.Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 ** filterData points to weights If sparsityBaseAddr is NULL, otherwise
 ** weights pointer will be derived from sparsityBaseAddr and filterData
 ** will not be used.
 ** For case inputDims->dims[0] > 1,scratch buffer is required
 ** scratch buffer size in CPU should be calculated using Cy_NNLite_FC_ScratchBufSize API
 ** For DMA mode scratch is sum of Cy_NNLite_FC_ScratchBufSize & Cy_NNLite_DMAModeScratchBufSize
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
 ** [in]  intrplParam      interpolation param for PWL output activation , null = nothing set
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnected(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_fc_params_t *fcParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
  if ((inputDims != NULL) && (inputDims->dims[0] > 1))
  {
        return __Cy_NNLite_FullyConnected_batch(inputData, outData, inputDims,
              outputDims, filterDims, filterData, biasData, fcParam,
              actType, intrplParam, false);
  }
  else
  {
    return __Cy_NNLite_FullyConnected(inputData, outData, inputDims,
              outputDims, filterDims, filterData, biasData, fcParam,
              actType, intrplParam, false);
  }
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_FullyConnectedDMA(const int8_t* inputData, int8_t* outData,
    const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
    const cy_nn_dims_t *filterDims, const int8_t *filterData,
    const int32_t *biasData,
    cy_nn_fc_params_t *fcParam,
    cy_en_nnlite_fused_activation_t actType,
    cy_nn_act_intrpl_param_t *intrplParam)
{
 if ((inputDims != NULL) && (inputDims->dims[0] > 1))
  {
        return __Cy_NNLite_FullyConnected_batch(inputData, outData, inputDims,
              outputDims, filterDims, filterData, biasData, fcParam,
              actType, intrplParam, true);
  }
  else
  {
      return __Cy_NNLite_FullyConnected(inputData, outData, inputDims,
              outputDims, filterDims, filterData, biasData, fcParam,
              actType, intrplParam, true);
  }
}

#endif
cy_en_nnlite_status_t
__Cy_NNLite_Avgpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam, bool dmaMode)
{
  uint32_t weightPerNeuron;
  uint32_t filterWidth, filterHeight;
  uint32_t inputWidth, inputHeight, inputChannels;
  uint32_t outputHeight, outputWidth;
  uint32_t activationRepeat;
  static float fscaling;

  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if((NULL == inputData) || (NULL == outData) ||
        (NULL == inputDims) || (NULL == outputDims) ||
        (NULL == filterDims) || (NULL == poolParam))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == poolParam->scratchBuf)) {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (inputDims->dims[3] != outputDims->dims[3]) {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState != CY_NNLITE_INIT) &&
            (kernelContext.pdlContext.nnliteState != CY_NNLITE_OP_DONE))
  {
    status = CY_NNLITE_BAD_STATE;
  }
  else
  {
    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)poolParam->scratchBuf : MXNNLITE_REGS;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);

    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannels = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];

    /* filter channel == input channel */
    weightPerNeuron =  filterHeight * filterWidth;

    /* Each footprint activations fetched once Hence...
    */

    activationRepeat = 1;

    /* calculate float scaling value*/
    fscaling = (1.0 / weightPerNeuron);

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeat,
        inputWidth, inputHeight, inputChannels,
        0, 0, 0, /* tflite-style pooling Padding is not supported */
        poolParam->strideCol,poolParam->strideRow,  /* stride row, col */
        0 /* input offset */
        );

    Cy_NNLite_SetInterpolationParam(Memio, 0, 1.0f);

    // NO weight streamer config needed - not active...

    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
                                  poolParam->outClipping, 0,
                                  outputWidth, outputHeight, inputChannels);

    Cy_NNLite_PipelineConfig(Memio,

                                /* opType= */ CY_NNLITE_SUM_ACT,
                                /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
                                /* repeatWeights = */ false,
                                /* biasEn = */ false,
                                /* sparsityEn = */ false,
                                /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_TENSOR,
                                /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,

                                 CY_NNLITE_ACTIVATION_NONE,
                                poolParam->act_size,
                                CY_NNLITE_ACTIVATION_8BIT,
                                CY_NNLITE_ACT_AS_OUT_BW(poolParam->act_size));

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ 0.0f,
      /*postScalingFactors=*/&fscaling);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
                                  CY_NNLITE_ACTIVATION_STREAMER, inputData);
    Cy_NNLite_StreamerBaseAddrSet(Memio,
                                  CY_NNLITE_OUT_STREAMER, outData);
    Cy_NNLite_SetInterruptMask(Memio, intrMask);

    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      if (status == CY_NNLITE_SUCCESS)
      {
           status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(poolParam->scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;
    }
#endif
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;
}



cy_en_nnlite_status_t
Cy_NNLite_Avgpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam)
{
  return __Cy_NNLite_Avgpool(inputData, outData,inputDims,
                outputDims, filterDims, poolParam, false);
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_AvgpoolDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam)
{
  return __Cy_NNLite_Avgpool(inputData, outData,inputDims,
                outputDims, filterDims, poolParam, true);
}
#endif
/**
 *****************************************************************************
 ** \brief Max pool CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation.Callback function from kernel config
 ** structure will be called after completion of layer. Kernel config structure
 ** should point to valid callback function.
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
 ** [in]  poolParam     average pool parameter structure pointer
 **
 *****************************************************************************/
cy_en_nnlite_status_t
__Cy_NNLite_Maxpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam, bool dmaMode)
{
  uint32_t filterWidth, filterHeight;
  uint32_t inputWidth, inputHeight, inputChannels;
  uint32_t outputHeight, outputWidth;
  uint32_t activationRepeat;

  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if((NULL == inputData) || (NULL == outData) ||
        (NULL == inputDims) || (NULL == outputDims) ||
        (NULL == filterDims) || (NULL == poolParam))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == poolParam->scratchBuf)) {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (inputDims->dims[3] != outputDims->dims[3]) {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if((kernelContext.pdlContext.nnliteState != CY_NNLITE_INIT) &&
            (kernelContext.pdlContext.nnliteState != CY_NNLITE_OP_DONE))
  {
    status = CY_NNLITE_BAD_STATE;
  }
  else
  {

    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)poolParam->scratchBuf : MXNNLITE_REGS;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;

    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);

    filterHeight = filterDims->dims[1];
    filterWidth = filterDims->dims[2];
    inputHeight = inputDims->dims[1];
    inputWidth = inputDims->dims[2];
    inputChannels = inputDims->dims[3];
    outputHeight = outputDims->dims[1];
    outputWidth = outputDims->dims[2];

    /* Each footprint activations fetched once Hence...  */
    activationRepeat = 1;

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        filterWidth, filterHeight,
        activationRepeat,
        inputWidth, inputHeight, inputChannels,
        0, 0, 0, /* tflite-style pooling Padding is not supported */
        poolParam->strideCol,poolParam->strideRow,  /* stride row, col */
        0 /* input offset */
        );

    Cy_NNLite_SetInterpolationParam(Memio, 0, 1.0f);

    // No Cy_NNLite_WeightStreamerCfg - weight streamer inactive

    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
                                  poolParam->outClipping, 0,
                                  outputWidth, outputHeight, inputChannels);


    Cy_NNLite_PipelineConfig(Memio,

                                /* opType= */ CY_NNLITE_MAX_ACT,
                                /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
                                /* repeatWeights = */ false,
                                /* biasEn = */ false,
                                /* sparsityEn = */ false,
                                /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
                                /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
                                CY_NNLITE_ACTIVATION_NONE,
                                poolParam->act_size,
                                CY_NNLITE_ACTIVATION_8BIT,
                                CY_NNLITE_ACT_AS_OUT_BW(poolParam->act_size)
    );

    // No need for setting pre/post ALU scaling - both disabled...
    Cy_NNLite_SetInterruptMask(Memio, intrMask);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
                                  CY_NNLITE_ACTIVATION_STREAMER, inputData);
    Cy_NNLite_StreamerBaseAddrSet(Memio,
                                  CY_NNLITE_OUT_STREAMER, outData);
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      if (status == CY_NNLITE_SUCCESS)
      {
           status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(poolParam->scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;
    }
#endif
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}


cy_en_nnlite_status_t
Cy_NNLite_Maxpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam)
{
  return __Cy_NNLite_Maxpool(inputData, outData,
                    inputDims, outputDims,
                    filterDims, poolParam, false);
}
#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_MaxpoolDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam)
{
  return __Cy_NNLite_Maxpool(inputData, outData,
                    inputDims, outputDims,
                    filterDims, poolParam, true);
}
#endif
/**
 * @brief Bitwidth of input words specified by input size field setting
 *
 * @param size_code       Selected size (input size field code)
 * @return unsigned int   Width in bits
 */

static inline unsigned int Cy_NNLite_InwordBitwidth(cy_en_nnlite_activation_size_t size_code) {
  unsigned int bytes_minus_1 = size_code;
  return (bytes_minus_1+1u)*8u;
}


/**
 *****************************************************************************
 * @brief Precomputation of NPU scaling factor settings for NPU binary operations
 *
 * TODO Create some special-case "fast path" versions (e.g. for use inside LSTM)?
 * Support per-filter and per-row setup for Conv and fully connected ops
 */

cy_en_nnlite_status_t
Cy_NNLite_Scaling_Setup( cy_nn_scaling_t *ss,
                   float lhs_scale, float rhs_scale, float output_scale,
                   cy_en_nnlite_activation_size_t in_size,
                   cy_en_nnlite_op_t op_type,
                   cy_en_nnlite_fused_activation_t act_type)
{
    float post_mac_scale;
    int pre_shift;

    // Figure out rescaling to apply pre-mac and
    // resulting scaling at MAC output...
    switch (op_type) {
      case CY_NNLITE_ADD:
      case CY_NNLITE_SUB_LR:
      case CY_NNLITE_SUB_RL: {
        if (lhs_scale < rhs_scale) {
          ss->pre_mac_scaling_mode = CY_NNLITE_RESCALE_WGT;
          ss->pre_mac_scale = lhs_scale/rhs_scale;
          post_mac_scale = rhs_scale;
          pre_shift = -NNLITE_ADDSUB_PRESCALE_SHIFT_BITS;
        } else if (rhs_scale < lhs_scale) {
          ss->pre_mac_scaling_mode = CY_NNLITE_RESCALE_ACT;
          ss->pre_mac_scale = rhs_scale/lhs_scale;
          post_mac_scale = lhs_scale;
          pre_shift = -NNLITE_ADDSUB_PRESCALE_SHIFT_BITS;
        } else {
          ss->pre_mac_scaling_mode = CY_NNLITE_RESCALE_NONE;
          ss->pre_mac_scale = 1.0f;
          post_mac_scale = lhs_scale; /* == rhs_scale */
          pre_shift = 0;
        }
        break;
      }

      case CY_NNLITE_MUL: {
        ss->pre_mac_scaling_mode = CY_NNLITE_RESCALE_NONE;
        ss->pre_mac_scale = 1.0f;
        post_mac_scale = lhs_scale*rhs_scale;
        pre_shift = 0;
        break;
      }

      case CY_NNLITE_NOOP_ACT: {
        ss->pre_mac_scaling_mode = CY_NNLITE_RESCALE_NONE;
        ss->pre_mac_scale = 1.0f;
        post_mac_scale = rhs_scale;
        pre_shift = 0;
        break;
      }

      default:
        return CY_NNLITE_BAD_PARAM;
    }

    // Figure out pre-activation re-scaling and output re-scaling
    ss->pre_act_scaling_mode = CY_NNLITE_OUTSCALE_PER_TENSOR;
    switch (act_type) {

      case CY_NNLITE_ACTIVATION_NONE:
          ss->pre_act_scale = ldexpf(post_mac_scale / output_scale, pre_shift);
          ss->post_act_scale = 1.0f;
        break;

      case CY_NNLITE_ACTIVATION_RECIP_POW2:
      case CY_NNLITE_ACTIVATION_TANH:
        // AFU Input needs to be Qx.16 / Qx.8 for the non-linear functions.
        ss->pre_act_scale =
          ldexpf(post_mac_scale, Cy_NNLite_InwordBitwidth(in_size));
        // AFU output is Q.NNLITE_TANH_FRAC_BITS
        ss->post_act_scale =
          (float)(1.0f/(1<<(NNLITE_TANH_FRAC_BITS)))/output_scale;
        break;

      case CY_NNLITE_ACTIVATION_SIGMOID:

        // AFU Input needs to be Qx.16 / Qx.8 for the non-linear functions.
        // The function itself is actually sigma(2x) so we also need to halve input.
        ss->pre_act_scale =
          ldexpf(post_mac_scale, Cy_NNLite_InwordBitwidth(in_size)-1);
         ss->post_act_scale =
          (float)(1.0f/(1<<(NNLITE_SIGM_FRAC_BITS)))/output_scale;
        break;

      default:
        return CY_NNLITE_BAD_PARAM;
    }
    return CY_NNLITE_SUCCESS;
}

/**
 * @brief Set scaling configuration to "no scaling" (fast)
 *
 * @param ss Point to Scaling configuration to be
 */

void
Cy_NNLite_Scaling_NoScale_Setup( cy_nn_scaling_t *ss)
{
    ss->pre_mac_scaling_mode = CY_NNLITE_RESCALE_NONE;
    ss->pre_mac_scale = 1.0f;
    ss->pre_act_scaling_mode = CY_NNLITE_OUTSCALE_NONE;
    ss->pre_act_scale = 1.0f; // Ignored
    ss->post_act_scale = 1.0f;
}


/**
 *****************************************************************************
 ** \brief Pointwise binary op CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 **
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
 **
 **
 ** \param [in]  lhsData        lhs input tensor buffer pointer
 **
 ** \param [in]  rhsData        rhs input tensor pointer (elts repeated if less elts than lhs)
 **
 ** \param [in]  outData        output buffer pointer
 **
 ** \param [in]  lhsDims        dimensions of lhs argument (repeated if less elts than inputDims )
 **
 ** \param [in]  rhsOutDims        rhs argument  and output.
 **
 ** [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
__Cy_NNLite_AddSubMul(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams, cy_en_nnlite_op_t op_type,
              cy_en_nnlite_fused_activation_t act_type, bool dmaMode)
{
  uint32_t lhsElts, rhsOutElts;
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;

  if((NULL == rhsData) || (NULL == outData) || (NULL == lhsData) ||
      (NULL == lhsDims) || (NULL == rhsOutDims) ||
      (NULL == pwParams))
  {
    return CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == pwParams->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }

  // Only support broadcast 1 --> N for leading major dimensions.
  bool broadcast_needed = false;
  for( int i = 3; i >= 0; --i) {
    bool lhs_dim_1 = lhsDims->dims[i] == 1;
    if (lhsDims->dims[i] != rhsOutDims->dims[i]) {
      if( !lhs_dim_1) {
        return CY_NNLITE_BAD_PARAM;
      } else {
        broadcast_needed = true;
      }
    } else if( broadcast_needed && !lhs_dim_1) {
      return CY_NNLITE_BAD_PARAM;
    }
  }

  lhsElts = totalElts(lhsDims);
  rhsOutElts = totalElts(rhsOutDims);
  if (rhsOutElts%lhsElts!=0) {
    return CY_NNLITE_BAD_PARAM;
  }
  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    const cy_nn_scaling_t *ss = &pwParams->scaling;
    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)pwParams->scratchBuf : MXNNLITE_REGS;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        1, 1, /* Filter width, height */
        1,    /* Only fetch rhs once */
        1, 1, rhsOutElts, /* input width, input height, input channels == # filters*/
        0, 0, 0, /* pad value, width. height */
        1, 1, /* stride col, stride row*/
        pwParams->rhsOffset /* input offset */
        );

    Cy_NNLite_WeightStreamerCfg(Memio, &kernelContext.pdlContext,
        /* 1*1* */ lhsElts, pwParams->lhsOffset);

    // TODO Should allow this to be assigned to a specific linker section to allow
    // it to be mapped to the "right" memory
    static float output_scale_factor;
    output_scale_factor = ss->pre_act_scale;

    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
          pwParams->outClipping, pwParams->outputOffset,
          1, 1, rhsOutElts /* Output width and height (outputs are "channels") */);
    Cy_NNLite_SetInterpolationParam(Memio, 0, ss->post_act_scale);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_WEIGHT_STREAMER, lhsData);
    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_ACTIVATION_STREAMER, rhsData);
    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_OUT_STREAMER, outData);

    Cy_NNLite_PipelineConfig(Memio,

        /* opType= */ op_type,
        /* fetchMode = */ CY_NNLITE_DWACT_WGT,
        /* repeatWeights = */ true,   // "Broadcasting"
        /* biasEn = */ false,
        /* sparsityEn = */ false,
        /* outputRescaling= */ ss->pre_act_scaling_mode,
        /* inputRescaling= */ ss->pre_mac_scaling_mode,
        act_type,
        pwParams->inputSize,
        pwParams->inputSize,
        pwParams->outputSize
    );

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ ss->pre_mac_scale,
      /*postScalingFactors=*/&output_scale_factor);
    Cy_NNLite_SetInterruptMask(Memio, intrMask);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      if (status == CY_NNLITE_SUCCESS)
      {
          status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)(pwParams->scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;
    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}

cy_en_nnlite_status_t
Cy_NNLite_AddSubMul(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams, cy_en_nnlite_op_t op_type,
              cy_en_nnlite_fused_activation_t act_type)
{
   return __Cy_NNLite_AddSubMul(lhsData, rhsData, outData, lhsDims, rhsOutDims,
                                pwParams, op_type, act_type, false);
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_AddSubMulDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams, cy_en_nnlite_op_t op_type,
              cy_en_nnlite_fused_activation_t act_type)
{
   return __Cy_NNLite_AddSubMul(lhsData, rhsData, outData, lhsDims, rhsOutDims,
                                pwParams, op_type, act_type, true);
}

#endif
/**
 * @brief Pointwise addition with simple broadcast
 *
 * Delegates to  @c Cy_NNLite_AddSub
*/

cy_en_nnlite_status_t
Cy_NNLite_Add(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams)
{
    return Cy_NNLite_AddSubMul(lhsData, rhsData, outData, lhsDims, rhsOutDims, pwParams,
                                CY_NNLITE_ADD, CY_NNLITE_ACTIVATION_NONE);
}
#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_AddDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams)
{
    return Cy_NNLite_AddSubMulDMA(lhsData, rhsData, outData, lhsDims, rhsOutDims, pwParams,
                                CY_NNLITE_ADD, CY_NNLITE_ACTIVATION_NONE);
}
#endif
/**
 * @brief Pointwise subtraction with simple broadcast
 *
 * Delegates to  @c Cy_NNLite_AddSub
*/

cy_en_nnlite_status_t
Cy_NNLite_Sub(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams,
              bool left_from_right)
{
    return Cy_NNLite_AddSubMul(lhsData, rhsData, outData, lhsDims, rhsOutDims, pwParams,
                                left_from_right ? CY_NNLITE_SUB_LR : CY_NNLITE_SUB_RL,
                                CY_NNLITE_ACTIVATION_NONE);
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_SubDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams,
              bool left_from_right)
{
    return Cy_NNLite_AddSubMulDMA(lhsData, rhsData, outData, lhsDims, rhsOutDims, pwParams,
                                left_from_right ? CY_NNLITE_SUB_LR : CY_NNLITE_SUB_RL,
                                CY_NNLITE_ACTIVATION_NONE);
}
#endif

/**
 * @brief Pointwise multiplication with simple broadcast
 *
 * Delegates to  @c Cy_NNLite_AddSubMul
*/


cy_en_nnlite_status_t
Cy_NNLite_Mul(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams)
{
    // andrew.stevens@infineon.com: 2024-02-23
    // Unfortunately due to a HW design oversight and remultiplier inputs on the weight streamer side are only
    // 8/16 bits not 9/17(18) bits. Even for simple pointwise ops where for add/sub all 9/17 bits are used.
    //  This means mul works fine but a non-zero zero-point can provoke overflows.
    // In practice this is "usually" not a problem.  16-bit quantized values conventional have zero zero-point and
    // multiplication is usual used for masks and the like where a zero zero-point can be painless enforced.
    // The issue could also be partly worked around in production driver FW
    // by tweaking the driver to compute offset multiplication separately and adding.
    // (rhs+rhs_offset) * (lhs+lhs_offset)  = (rhs+rhs_offset)*lhs + (rhs+rhs_offset)*lhs_offset

    // Annoyingly: TFLM unit-tests turn out not to cover potential overflow conditions so this
    // defect in the design was noticed too late for a HW fix. Thanks google... classy open-source!
    // Time-permitting a decent directed-randomized TFLM test should be added as we did for the NN ops etc.

    if (pwParams->lhsOffset != 0) {
      return CY_NNLITE_BAD_PARAM;
    }
    return Cy_NNLite_AddSubMul(lhsData, rhsData, outData, lhsDims, rhsOutDims, pwParams,
                               CY_NNLITE_MUL, CY_NNLITE_ACTIVATION_NONE);
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_MulDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams)
{
    if (pwParams->lhsOffset != 0) {
      return CY_NNLITE_BAD_PARAM;
    }
    return Cy_NNLite_AddSubMulDMA(lhsData, rhsData, outData, lhsDims, rhsOutDims, pwParams,
                               CY_NNLITE_MUL, CY_NNLITE_ACTIVATION_NONE);
}
#endif
/**
 *****************************************************************************
 ** \brief API will return return size of scratch buffer for DMA mode API
 **
 **
 *****************************************************************************/

uint32_t Cy_NNLite_DMAModeScratchBufSize(void)
{
  return CY_NNLITE_DMA_SCRATCH_BUFFER_SIZE;
}

/**
 *****************************************************************************
 ** \brief Unfused Activation function CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 **
 ** Internally implemented as "depthwise" operation on 1x1xC input
 **
 **
 ** \param [in]  inData         rhs input tensor pointer (elts repeated if less elts than lhs)
 **
 ** \param [in]  outData        output buffer pointer
 **
 ** \param [in]  inoutDims      rhs argument  and output.
 **
 ** \param [in]  actParams      unfused activation op params (lhs and output rescaling factors)
 **
 ** \param [in] act_type        Activation function to apply.
 **
 ** \param [in]  intrplParam    interpolation param for PWL output activation , null = nothing set
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
__Cy_NNLite_Activation(const int8_t *inData, int8_t* outData,
                    const cy_nn_dims_t *inoutDims,
                    const cy_nn_pwise_unary_params_t *actParams,
                    cy_en_nnlite_fused_activation_t act_type,
                    cy_nn_act_intrpl_param_t *intrplParam, bool dmaMode)
{

  uint32_t inOutElts;
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;


  if((NULL == inData) || (NULL == outData)  ||
     (NULL == inoutDims) ||  (NULL == actParams) )
  {
    return CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == actParams->scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);

  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    cy_en_nnlite_input_rescaling_t mac_in_rescaling;
    cy_en_nnlite_output_rescaling_t mac_out_rescaling;

    inOutElts = totalElts(inoutDims);
    NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)actParams->scratchBuf : MXNNLITE_REGS;
    uint32_t intrMask = dmaMode ? NNLITE_INTR_ERRORS_MASK : NNLITE_INTR_ENABLE_MASK;

    Cy_NNLite_ActivationStreamerCfg(Memio, &kernelContext.pdlContext,
        1, 1, /* Filter width, height */
        1,    /* Only fetch rhs once */
        1, 1, inOutElts, /* input width, input height, input channels == # values*/
        0, 0, 0, /* pad value, width. height */
        1, 1, /* stride col, stride row*/
        actParams->inOffset /* input offset */
        );

    float mac_in_sf;
    // TODO Really this should support mapping to a suitable linker section
    static float afu_in_sf;
    const float *afu_in_sf_ptr;
    switch( act_type ) {
      case CY_NNLITE_ACTIVATION_PWL:
        mac_in_sf = 1.0f;
        afu_in_sf = actParams->inScale;
        afu_in_sf_ptr = &afu_in_sf;
        mac_out_rescaling = CY_NNLITE_OUTSCALE_PER_TENSOR;
        Cy_NNLite_SetPWLActivation(Memio, intrplParam);
        break;
      case CY_NNLITE_ACTIVATION_RECIP_POW2:
      case CY_NNLITE_ACTIVATION_TANH:
        mac_in_sf = 1.0f;
        // Input needs to be Qx.16 / Qx.8 for the non-linear functions.
        afu_in_sf = ldexpf(actParams->inScale, Cy_NNLite_InwordBitwidth(actParams->inputSize));
        afu_in_sf_ptr = &afu_in_sf;
        mac_out_rescaling = CY_NNLITE_OUTSCALE_PER_TENSOR;
        Cy_NNLite_SetInterpolationParam(Memio, 0, actParams->outScale);
        break;

      case CY_NNLITE_ACTIVATION_SIGMOID:
        mac_in_sf = 1.0f;
        // Input needs to be Qx.16 / Qx.8 for the non-linear functions.
        // The function itself is actually sigma(2x) so we also need to halve input.
        afu_in_sf = ldexpf(actParams->inScale, Cy_NNLite_InwordBitwidth(actParams->inputSize)-1);
        afu_in_sf_ptr = &afu_in_sf;
        mac_out_rescaling = CY_NNLITE_OUTSCALE_PER_TENSOR;
        Cy_NNLite_SetInterpolationParam(Memio, 0, actParams->outScale);
        break;

      default:
        mac_in_sf = actParams->inScale;
        afu_in_sf_ptr = NULL;
        mac_out_rescaling = CY_NNLITE_OUTSCALE_NONE;
        Cy_NNLite_SetInterpolationParam(Memio, 0, actParams->outScale);
        break;
    }


    if (mac_in_sf != 1.0f) {
      mac_in_rescaling = CY_NNLITE_RESCALE_ACT;
    } else {
      mac_in_rescaling = CY_NNLITE_RESCALE_NONE;
    }



    Cy_NNLite_OutputStreamerCfg(Memio, &kernelContext.pdlContext,
        actParams->outClipping, actParams->outOffset,
        1, 1, inOutElts /* Output width and height (outputs are "channels") */);

    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_ACTIVATION_STREAMER, inData);
    Cy_NNLite_StreamerBaseAddrSet(Memio,
        CY_NNLITE_OUT_STREAMER, outData);

    Cy_NNLite_PipelineConfig(Memio,

        /* opType= */ CY_NNLITE_NOOP_ACT,
        /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
        /* repeatWeights = */ false,   // Don't care Weight streamer inactive
        /* biasEn = */ false,
        /* sparsityEn = */ false,
        /* outputRescaling= */ mac_out_rescaling,
        /* inputRescaling= */ mac_in_rescaling,
        act_type,
        actParams->inputSize,
        CY_NNLITE_ACTIVATION_8BIT,
        actParams->outputSize
    );

    Cy_NNLite_SetPrePostScaling(Memio,
      /*preScalingFactor=*/ mac_in_sf,
      /*postScalingFactors=*/afu_in_sf_ptr);
    Cy_NNLite_SetInterruptMask(Memio, intrMask);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      if (status == CY_NNLITE_SUCCESS)
      {
          status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
        cy_stc_dma_descriptor_config_t *cfgDesc;
        cy_stc_dma_descriptor_t *desc;

        Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
        cfgDesc = (cy_stc_dma_descriptor_config_t *)(actParams->scratchBuf + sizeof(NNLITE_Type));
        desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

        Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
        status = CY_NNLITE_OP_QUEUED;
    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}


/**
 *****************************************************************************
 ** \brief Unfused Activation function CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 **
 ** Internally implemented as "depthwise" operation on 1x1xC input
 **
 **
 ** \param [in]  inData        rhs input tensor pointer (elts repeated if less elts than lhs)
 **
 ** \param [in]  outData        output buffer pointer
 **
 ** \param [in]  inoutDims        rhs argument  and output.
 **
 ** \param [in]  actParams      unfused activation op params (lhs and output rescaling factors)
 **
 ** \param [in] act_type        Activation function to apply.
 **
 ** \param [in]  intrplParam    interpolation param for PWL output activation , null = nothing set
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Activation(const int8_t *inData, int8_t* outData,
                    const cy_nn_dims_t *inoutDims,
                    const cy_nn_pwise_unary_params_t *actParams,
                    cy_en_nnlite_fused_activation_t act_type,
                    cy_nn_act_intrpl_param_t *intrplParam)

{
    return __Cy_NNLite_Activation(inData, outData, inoutDims,
                          actParams, act_type, intrplParam, false);

}

/**
 *****************************************************************************
 ** \brief Unfused Activation function CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 **
 ** Internally implemented as "depthwise" operation on 1x1xC input
 **
 **
 ** \param [in]  inData        rhs input tensor pointer (elts repeated if less elts than lhs)
 **
 ** \param [in]  outData        output buffer pointer
 **
 ** \param [in]  inoutDims        rhs argument  and output.
 **
 ** \param [in]  actParams      unfused activation op params (lhs and output rescaling factors)
 **
 ** \param [in] act_type        Activation function to apply.
 **
 ** \param [in]  intrplParam    interpolation param for PWL output activation , null = nothing set
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/
#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_ActivationDMA(const int8_t *inData, int8_t* outData,
                    const cy_nn_dims_t *inoutDims,
                    const cy_nn_pwise_unary_params_t *actParams,
                    cy_en_nnlite_fused_activation_t act_type,
                    cy_nn_act_intrpl_param_t *intrplParam)

{
    return __Cy_NNLite_Activation(inData, outData, inoutDims,
                          actParams, act_type, intrplParam, true);

}
#endif
/**
 *****************************************************************************
 ** \brief Byte block copy using NNLite
 **
 ** Internally implemented as "depthwise" operation on 1x1xC input
 **
 **
 ** \param [in]  inData         address start byte vector  to be copied
 **
 ** \param [in]  outData        destination start address
 **
 ** \param [in]  count          Number of bytes to be copied
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Byte_Copy(const int8_t *inData, int8_t* outData,
                    uint32_t count)
{
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;


  if((NULL == inData) || (NULL == outData))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {

    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
        1, 1, /* Filter width, height */
        1,    /* Only fetch rhs once */
        1, 1, count, /* input width, input height, input channels == # values*/
        0, 0, 0, /* pad value, width. height */
        1, 1, /* stride col, stride row*/
        0 /* input offset */
        );

    static cy_nnlite_clipping_t noop_clip = {
      /*min*/ -(1<<15),
      /*max*/ (1<<15)-1
    };

    Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
        noop_clip, 0,
        1, 1, count /* Output width and height (outputs are "channels") */);

    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
        CY_NNLITE_ACTIVATION_STREAMER, inData);
    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
        CY_NNLITE_OUT_STREAMER, outData);

    Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

        /* opType= */ CY_NNLITE_NOOP_ACT,
        /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
        /* repeatWeights = */ false,
        /* biasEn = */ false,
        /* sparsityEn = */ false,
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        CY_NNLITE_ACTIVATION_NONE,
        CY_NNLITE_ACTIVATION_8BIT,
        CY_NNLITE_ACTIVATION_8BIT,
        CY_NNLITE_OUTPUT_8BIT
    );

    // No need for setting pre/post ALU scaling - both disabled...

    Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, 1.0f);

    Cy_NNLite_SetInterruptMask(MXNNLITE_REGS, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_REGS, false);
    kernelContext.LpmLockFunc();
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
    status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
    if (status == CY_NNLITE_SUCCESS)
    {
        status = Cy_NNLite_WaitForCompletionPartialOp();
    }
    if (kernelContext.completionCbFunc == 0)
    {
      kernelContext.LpmUnlockFunc();
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}


/**
 *****************************************************************************
 ** \brief Float reciprocal of (sums of) unsigned Q.31 values CPU mode kernel API
 **
 **
 ** Internally implemented summing over the minor dimensions to produce
 ** W outputs from WxC inputs
 **
 **
 ** API will configure nnlite and
 ** then start nnlite operation. Callback function from kernel config structure
 ** will be called after completion of layer. Kernel config structure should
 ** point to valid callback function.
 **
 ** \param [in]  inData        rhs input tensor pointer
 **
 ** \param [in]  outData        output buffer pointer
 **
 ** \param [in]  inoutDims         input values dimensions
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Q31Reciprocal(const uint32_t *inData, float* outData,
                        const cy_nn_dims_t *inoutDims)
{
  uint32_t inoutWidth, inChannels;
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;


  if((NULL == inData) || (NULL == outData)  || (NULL == inoutDims)  )
  {
    return CY_NNLITE_BAD_PARAM;
  }

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {

    inoutWidth = inoutDims->dims[0];
    // "Trick mode" 32-bit inputs as 2*16 bit value
    // 32-bit Float values suitable for use as scale factor generated.
    inChannels = inoutDims->dims[1]*2;

    Cy_NNLite_WeightStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
                            inChannels /* 16-bit values */, 0);

    cy_nnlite_clipping_t dummyOutClipping = { 0, 0}; //32-bit mode ignores these...

    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
        1, 1, /* Filter width, height */
        1,    /* Only fetch rhs once */
        inoutWidth, 1, inChannels, /* input width, input height, input channels == # values*/
        0, 0, 0, /* pad value, width. height */
        1, 1, /* stride col, stride row*/
        0 /* input offset */
        );


    Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
        dummyOutClipping,  /* Dummy Clipping - no used  */
        0,                  /* Noop Output Offset         */
        inoutWidth, 1, 1   /* Output width, height, channels  */);

    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_ACTIVATION_STREAMER, inData);
    Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_OUT_STREAMER, outData);

    Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

        /* opType= */ CY_NNLITE_SUM_ACT32,
        /* fetchMode = */ CY_NNLITE_ACT_ONLY,
        /* repeatWeights = */ false,   // Don't care Weight streamer inactive
        /* biasEn = */ false,
        /* sparsityEn = */ false,
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        CY_NNLITE_ACTIVATION_RECIPROCAL,
        CY_NNLITE_ACTIVATION_16BIT,
        CY_NNLITE_ACTIVATION_16BIT,   // Ignored...
        CY_NNLITE_OUTPUT_32BIT
    );

    // No need for setting pre/post ALU scaling - both disabled...

    Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, 1.0f);

    Cy_NNLite_SetInterruptMask(MXNNLITE_REGS, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_REGS, false);
    kernelContext.LpmLockFunc();
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
    status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
    if (status == CY_NNLITE_SUCCESS)
    {
        status = Cy_NNLite_WaitForCompletionPartialOp();
    }
    if (kernelContext.completionCbFunc == 0)
    {
      kernelContext.LpmUnlockFunc();
    }
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}

/**
 * @brief Compute size scratch buffer required for FC op.
 * @param inDims input dimensions of FC operation
 * @param outDims Output dimensions of FC operation
 * @return uint32_t Size of scratch buffer required
 */
uint32_t Cy_NNLite_FC_ScratchBufSize(const cy_nn_dims_t *inDims, const cy_nn_dims_t *outDims)
{
  uint32_t size = 0;

  if ((inDims != NULL) && (outDims != NULL) && (inDims->dims[0] > 1))
  {
    size = (sizeof(float) * outDims->dims[1]);
  }

  return size;
}
/**
 * @brief Compute size scratch buffer required for SoftMax op.
 *
 * @param inoutDims Input dimensions of softmax operation
 * @param act_size  Size of input activation values
 * @return uint32_t Size of scratch buffer required
 */

uint32_t
Cy_NNLite_SoftMax_ScratchBufSize(const cy_nn_dims_t *inoutDims,
                                 const cy_en_nnlite_activation_size_t act_size)
{
  size_t elts = inoutDims->dims[0] * inoutDims->dims[1];
  size_t reciprocals = inoutDims->dims[0];
  switch (act_size) {
    case CY_NNLITE_ACTIVATION_8BIT:
      return (elts+reciprocals)*4;
    default:
      return (elts+reciprocals)*4;
  }
}

/**
 * @brief Row maximums step in SoftMax macro operation
 *
 * Compute num_rows row maximums of num_rows x row_size inputs --> MAX
 * This is actually semi inefficient as it is in effect scalar (Depthwise, depth 1)
 * but is necessary as HW does not support MIN/MAX for non depthwise operation.
 * @param x_in      num_rows x num_cols 2D input tensor
 * @param out       num_rows x num_cols output [max_in[i]-x_in[i,j] for i,j in num_rows x num-cols]
 * @param smParams  Input/output tensor quantization parameters bitwidths etc.
 * @return cy_en_nnlite_status_t
 */

static cy_en_nnlite_status_t
Cy_NNLite_SoftMax_RowMaxes(const int8_t* x_in,
                  int8_t *out,
                  uint32_t  num_rows,
                  uint32_t  row_size,
                  const cy_nn_pwise_unary_params_t *smParams)
{
    cy_en_nnlite_status_t status;
    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
        row_size, 1, /* Filter width  == # value, height */
        1,    /* Only fetch rhs once */
        row_size, num_rows, 1, /* input width == # values, input height, input channels */
        0, 0, 0, /* pad value, width. height */
        1, 1, /* stride col, stride row*/
        0 /* ignore input offset, we're going to work with differences... */
        );

      // No Cy_NNLite_WeightStreamerCfg - weight streamer inactive
      // Output is non-negative.
      cy_nnlite_clipping_t no_clip = {
          /*min=*/ -(1<<15),
          /*max=*/(1<<15)-1
      };
      Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
                                  no_clip, 0,
                                  1, num_rows, 1 /* output width, height, channels */);

      Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

                                  /* opType= */ CY_NNLITE_MAX_ACT,
                                  /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
                                  /* repeatWeights = */ false,
                                  /* biasEn = */ false,
                                  /* sparsityEn = */ false,
                                  /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
                                  /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
                                  CY_NNLITE_ACTIVATION_NONE,
                                  smParams->inputSize,
                                  CY_NNLITE_ACTIVATION_8BIT, // Ignored
                                  CY_NNLITE_ACT_AS_OUT_BW(smParams->inputSize)
      );

    // No need for setting pre/post ALU scaling - both disabled...

      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
          CY_NNLITE_ACTIVATION_STREAMER, x_in);
      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
          CY_NNLITE_OUT_STREAMER, out);
    kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
    status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
    if (status == CY_NNLITE_SUCCESS)
    {
        status = Cy_NNLite_WaitForCompletionPartialOp();
    }

    return status;
}



/**
 * @brief Subtract from maximum step in SoftMax macro operation
 *
 * Computes [MAX_i-in[i,j]] for i,j
 *
 * @param max_in    num_rows Row maximum values
 * @param x_in      num_rows x num_cols 2D input tensor
 * @param out       num_rows x num_cols output [max_in[i]-x_in[i,j] for i,j in num_rows x num-cols]
 * @param smParams  Input/output tensor quantization parameters bitwidths etc.
 * @return cy_en_nnlite_status_t row-wise differences from row maximum.
 */

static cy_en_nnlite_status_t
Cy_NNLite_SoftMax_SubFromRowMaxes(int8_t *max_in, const int8_t* x_in,
                  int8_t *out,
                  uint32_t  num_rows,
                  uint32_t  row_size,
                  cy_nnlite_clipping_t clip_diffs,
                  const cy_nn_pwise_unary_params_t *smParams)
{

  cy_en_nnlite_status_t status = CY_NNLITE_SUCCESS;
#if NNLITE_WITHOUT_HARDWIRED_ADD_SUB_HACK
  Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      row_size,    /* Fetch each MAX row_size times once */
      1, 1, num_rows, /* input width, input height, input channels == # filters*/
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      0 /* ignore input offset, we're going to work with differences... */
      );

  // Weight streamer set to x_i in order
  Cy_NNLite_WeightStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      /* 1* */ row_size*num_rows, 0);


  Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
                              clip_diffs,
                              /*outputOffset=*/ clip_diffs.min,
                              1, 1, num_rows*row_size /* output width, height, channels */);

  Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

                              /* opType= */ CY_NNLITE_SUB_LR, // CY_NNLITE_SUB_RL,
                              /* fetchMode = */ CY_NNLITE_DWACT_WGT,
                              /* repeatWeights = */ true,
                              /* biasEn = */ false,
                              /* sparsityEn = */ false,
                              /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
                              /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
                              CY_NNLITE_ACTIVATION_NONE,
                              smParams->inputSize,
                              smParams->inputSize,
                              smParams->outputSize
  );

  // No need for setting pre/post ALU scaling - both disabled...

  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_ACTIVATION_STREAMER, max_in);

  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_WEIGHT_STREAMER, x_in);

  // "Mis-use" output buffer to hold intermediate M-x values...
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_OUT_STREAMER, out);
  kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
  status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
      status = Cy_NNLite_WaitForCompletionPartialOp();
  }
#else

  // Step 1: workaround add/sub breaking depth multiplier mechanism by depth-multiplication
  // using a dummy DW convolution op... (summation with 1x1 kernel size)

  // We're writing far more than we read so we can't just over-write
  // to rely on caller allocating max_buf with having enough space..
  uint32_t max_values_len;
  switch (smParams->inputSize) {
    case CY_NNLITE_ACTIVATION_8BIT:
      max_values_len = num_rows;
      break;

    case CY_NNLITE_ACTIVATION_16BIT:
      max_values_len = num_rows*2u;
      break;

    default:
      return CY_NNLITE_BAD_PARAM;
  }

  int8_t *replicated_max = max_in + max_values_len;
  Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      row_size,    /* Fetch each MAX row_size times  */
      1, 1, num_rows, /* input width, input height, input channels == # filters*/
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      0 /* ignore input offset, we're going to work with differences... */
      );

    cy_nnlite_clipping_t no_clip = {
        /*min=*/ -(1<<15),
        /*max=*/(1<<15)-1
    };
  // No need to set weight streamer - not used...
  Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
                              no_clip,
                              /*outputOffset=*/ 0,
                              1, 1, num_rows*row_size /* output width, height, channels */);

  Cy_NNLite_PipelineConfig(MXNNLITE_REGS,
                              /* opType= */ CY_NNLITE_NOOP_ACT,
                              /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
                              /* repeatWeights = */ false,   // Don't care ... inactive
                              /* biasEn = */ false,
                              /* sparsityEn = */ false,
                              /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
                              /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
                              CY_NNLITE_ACTIVATION_NONE,
                              smParams->inputSize,
                              CY_NNLITE_ACTIVATION_8BIT,
                              CY_NNLITE_ACT_AS_OUT_BW(smParams->inputSize)
  );

  // No need for setting pre/post ALU scaling - both disabled...
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_ACTIVATION_STREAMER, max_in);

  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_OUT_STREAMER, replicated_max);

  status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
      status = Cy_NNLite_WaitForCompletionPartialOp();
  }
  if ( status != CY_NNLITE_SUCCESS)
      return status;

  // Step 2:
  // Not we just do a simple pointwise subtraction from the (replicated) max values

  Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      1,    /* each replicated MAX fetched  once */
      1, 1, row_size*num_rows, /* input width, input height, input channels == # values*/
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      0 /* ignore input offset, we're going to work with differences... */
      );

  // Weight streamer set to x_i in order
  Cy_NNLite_WeightStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      /* 1* */ row_size*num_rows, 0);


  Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
                              clip_diffs,
                              /*outputOffset=*/ clip_diffs.min,
                              1, 1, num_rows*row_size /* output width, height, channels */);

  Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

                              /* opType= */ CY_NNLITE_SUB_LR, // CY_NNLITE_SUB_RL,
                              /* fetchMode = */ CY_NNLITE_DWACT_WGT,
                              /* repeatWeights = */ false,
                              /* biasEn = */ false,
                              /* sparsityEn = */ false,
                              /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
                              /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
                              CY_NNLITE_ACTIVATION_NONE,
                              smParams->inputSize,
                              smParams->inputSize,
                              smParams->outputSize
  );

  // No need for setting pre/post ALU scaling - both disabled...

  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_ACTIVATION_STREAMER, replicated_max);

  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_WEIGHT_STREAMER, x_in);

  // "Mis-use" output buffer to hold intermediate M-x values...
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_OUT_STREAMER, out);
  kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
  status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
      status = Cy_NNLite_WaitForCompletionPartialOp();
  }
#endif
  return status;
}
    // Compute e-(MAX-x_i)  (32-bit intermediate precision)


/**
 * @brief Compute (non-positive) exponential step in SoftMax macro operation
 *
 * Computes [e^-(MAX_i-in[i,j])] for i,j
 *
 * @param x_in      num_rows x num_cols 2D input tensor
 * @param out       num_rows x num_cols Q31 output
 * @param smParams  Input/output tensor quantization parameters bitwidths etc.
 * @return cy_en_nnlite_status_t
 */

static cy_en_nnlite_status_t
Cy_NNLite_SoftMax_Exps(const int8_t* nonneg_x,
                  int8_t *out,
                  uint32_t  num_rows,
                  uint32_t  row_size,
                  cy_nnlite_clipping_t clip_diffs,
                  float lg2_e_folded_prescale,
                  const cy_nn_pwise_unary_params_t *smParams)
{
cy_en_nnlite_status_t status;
  // TODO this should really be mappable to a suitable linker section for efficiency...
  static float second_rescale_buf;
  static int8_t zero_value_buf[] = {0,0,0,0};

  Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      1,    /* Only fetch rhs once */
      num_rows, 1, row_size, /* input width, input height, input channels == # values*/
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      -clip_diffs.min /* input offset: inputs are all non-negative*/
      );

  // Limited exponent range in single scaling unit - split into two steps
  // if necessary.  Since lg2_e_folded_prescale is quite large (exp engine expected Q8/Q16 inputs
  // this is not a rare/exotic condition.
  float overall_rescale = smParams->inScale * lg2_e_folded_prescale;
  float first_rescale;
  int exponent;
  (void)frexpf(overall_rescale, &exponent);
  cy_en_nnlite_output_rescaling_t  second_rescale_mode;
  if (exponent > 8+NNLITE_ADDSUB_PRESCALE_SHIFT_BITS) {
    second_rescale_mode = CY_NNLITE_OUTSCALE_PER_TENSOR;
    second_rescale_buf = ldexpf(overall_rescale,-(NNLITE_ADDSUB_PRESCALE_SHIFT_BITS+8));
    first_rescale = ldexpf(1.0,8); // Pre-shift of 8+NNLITE_ADDSUB_PRESCALE_SHIFT_BITS bits
  } else {
    second_rescale_mode = CY_NNLITE_OUTSCALE_NONE;
    first_rescale = ldexpf(overall_rescale,-NNLITE_ADDSUB_PRESCALE_SHIFT_BITS);
  }

  //
  // Cannot use NOOP as HW design ooops means input rescaling is possible only for
  // ADD/SUB ops.  So we need to use addition of zero as an alternative ... Sigh...

  Cy_NNLite_WeightStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
    /* 1*1 */ 1, 0);

  Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

      /* opType= */ CY_NNLITE_ADD,
      /* fetchMode = */ CY_NNLITE_DWACT_WGT,
      /* repeatWeights = */ true,   //Keep repeating 0.0
      /* biasEn = */ false,
      /* sparsityEn = */ false,
      /* outputRescaling= */ second_rescale_mode,
      /* inputRescaling= */ CY_NNLITE_RESCALE_ACT,
      CY_NNLITE_ACTIVATION_RECIP_POW2,
      CY_NNLITE_OUT_AS_ACT_BW(smParams->outputSize),
      CY_NNLITE_OUT_AS_ACT_BW(smParams->outputSize),
      CY_NNLITE_OUTPUT_32BIT
  );

  // Output  Q31 exponential
  Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, (float)(1u<<(31u-NNLITE_RECIP_POW2_FRAC_BITS)));

  Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      clip_diffs,   // 32-bit output this is ignored
      0,                // No offset needed.
      num_rows, 1, row_size /* Output width and height (outputs are "channels") */
    );

  Cy_NNLite_SetPrePostScaling(MXNNLITE_REGS,
    /*preScalingFactor=*/ first_rescale,
    /*postScalingFactors=*/&second_rescale_buf);

  // MAX-x_i at this point...
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_ACTIVATION_STREAMER, nonneg_x);
  // Output into temporary buffer at 32-bit precision
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_OUT_STREAMER, out);
  // Zero summand...
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
      CY_NNLITE_WEIGHT_STREAMER, zero_value_buf);
  kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
  status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
      status = Cy_NNLite_WaitForCompletionPartialOp();
  }
  return status;
}



/**
 * @brief Construct a new Cy_NNLite_SoftMax_ReciprocalExpSum object
 *
 * Reciprocal of Sigma_i e-(MAX-x_i)  (32-bit float value from Q31 inputs)
 *
 * @param q31_exps      2D array (@c num_rows x @c row_size) Q31 e^-x (non-negative x) values
 * @param reciprocals   vector IEEE754 float reciprocal of row sums
 * @param num_rows
 * @param row_size
 * @param clip_diffs
 * @param smParams    Input/output tensor quantization parameters bitwidths etc.
 */

static cy_en_nnlite_status_t
Cy_NNLite_SoftMax_ReciprocalExpSum(const int32_t* q31_exps,
                  float *reciprocals,
                  uint32_t  num_rows,
                  uint32_t  row_size,
                  cy_nnlite_clipping_t clip_diffs,
                  const cy_nn_pwise_unary_params_t *smParams)
{
cy_en_nnlite_status_t status;
(void)smParams;
  Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      1,    /* Only fetch rhs once */
      num_rows, 1, row_size*2, /* input width, input height, (16-bit)input channels == 2* # values */
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      0 /* input offset */
      );


  Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      clip_diffs,         /* 32-bit output this is ignored */
      0,                  /* No-op Output Offset         */
      num_rows, 1, 1            /* Output width, height, channels  */);

  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_ACTIVATION_STREAMER, (int8_t *)q31_exps);
  Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_OUT_STREAMER, (int8_t *)reciprocals);

  Cy_NNLite_PipelineConfig(MXNNLITE_REGS,

      /* opType= */ CY_NNLITE_SUM_ACT32,
      /* fetchMode = */ CY_NNLITE_ACT_ONLY,
      /* repeatWeights = */ false,   // Don't care Weight streamer inactive
      /* biasEn = */ false,
      /* sparsityEn = */ false,
      /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
      /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
      CY_NNLITE_ACTIVATION_RECIPROCAL,
      CY_NNLITE_ACTIVATION_16BIT,    // SUM_ACT32 treats 32-bit values as pairs of 16-bit
      CY_NNLITE_ACTIVATION_16BIT,   // Ignored...
      CY_NNLITE_OUTPUT_32BIT
  );

  // No need for Cy_NNLite_SetPrePostScaling  pre and post ALU rescaling are both disabled.

  // No-op output scale-factor....
  Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, 1.0f);
  kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
  status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
  if (status == CY_NNLITE_SUCCESS)
  {
      status = Cy_NNLite_WaitForCompletionPartialOp();
  }
  return status;
}

/**
 * @brief Normalization step in Softmax computation
 *
 * Multiply each row of exponential by reciprocal of row sum
 *
 * @note NOT stand-alone - some NNLite setup is inherited from preceding SoftMax_Step functions
 *
 * @param q31_exps      2D array (@c num_rows x @c row_size) Q31 e^-x (non-negative x) values
 * @param reciprocals   vector IEEE754 float reciprocal of row sums
 * @param out           Quantized (8/16 bit)
 * @param num_rows
 * @param row_size
 * @param smParams  Input/output tensor quantization parameters bitwidths etc.
 * @return cy_en_nnlite_status_t
 */
static cy_en_nnlite_status_t
Cy_NNLite_SoftMax_Normalize(const int32_t* q31_exps,
                  float *reciprocals,
                  int8_t *out,
                  uint32_t  num_rows,
                  uint32_t  row_size,
                  const cy_nn_pwise_unary_params_t *smParams)
{
  cy_en_nnlite_status_t status = CY_NNLITE_SUCCESS;
    uint32_t out_row_stride;
    switch (smParams->outputSize) {
      case CY_NNLITE_OUTPUT_8BIT:
        out_row_stride = row_size;
        break;

      case CY_NNLITE_OUTPUT_16BIT:
        out_row_stride = row_size*2u;
        break;

      default:
        return CY_NNLITE_BAD_PARAM;
    }
    // Output rescale from Q31 to output scaling
    Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, (1.0f/(float)(1u<<31u))/smParams->outScale);

#if NNLITE_HAS_PER_ROW_SCALING_SUPPORT
    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      1,    /* Only fetch rhs once */
      row_size, num_rows, 2, /* input width = # values, input height, (16-bit)input channels == 2 */
      0, 0, /* start col, row */
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      0 /* input offset */
      );

    Cy_NNLite_PipelineConfig(MXNNLITE_REGS,
        /* opType= */ CY_NNLITE_SUM_ACT32,
        /* fetchMode = */ CY_NNLITE_ACT_ONLY,
        /* repeatWeights = */ false,   // Don't care Weight streamer inactive
        /* biasEn = */ false,
        /* sparsityEn = */ false,
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_ROW,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        /* inputRescalingFactor = */ 1.0f,

        CY_NNLITE_ACTIVATION_NONE,
        CY_NNLITE_ACTIVATION_16BIT,   // 32-bit e-(MAX-x_i) fetched as pairs 16-bit values...
        CY_NNLITE_ACTIVATION_16BIT,   // Ignored...
        smParams->outputSize,
        /* chunkingEn = */ false
    );

    Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
        smParams->outClipping,
        smParams->outOffset,      /* No-op Output Offset         */
        row_size, num_rows, 1     /* Output width, height, channels  */);


    Cy_NNLite_SetPrePostScaling(MXNNLITE_REGS,
      /*preScalingFactor=*/ 1.0f,
      /*postScalingFactors=*/reciprocals);


      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_ACTIVATION_STREAMER, (int8_t *)q31_exps);
      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_OUT_STREAMER, out);

      status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
      if (status == CY_NNLITE_SUCCESS)
      {
          status = Cy_NNLite_WaitForCompletionPartialOp();
      }
#else
    Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
      1, 1, /* Filter width, height */
      1,    /* Only fetch rhs once */
      row_size, 1, 2, /* input width = # values, input height, (16-bit)input channels == 2 */
      0, 0, 0, /* pad value, width. height */
      1, 1, /* stride col, stride row*/
      0 /* input offset */
      );

    Cy_NNLite_PipelineConfig(MXNNLITE_REGS,
        /* opType= */ CY_NNLITE_SUM_ACT32,
        /* fetchMode = */ CY_NNLITE_ACT_ONLY,
        /* repeatWeights = */ false,   // Don't care Weight streamer inactive
        /* biasEn = */ false,
        /* sparsityEn = */ false,
        /* outputRescaling= */ CY_NNLITE_OUTSCALE_PER_TENSOR,
        /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
        CY_NNLITE_ACTIVATION_NONE,
        CY_NNLITE_ACTIVATION_16BIT,
        CY_NNLITE_ACTIVATION_16BIT,   // Ignored...
        smParams->outputSize
    );


    // NNLite-2.0 can't use distinct scale-factors for different kernel footprints
    // so we have to rescale each row separately

    {
      int8_t *row = (int8_t *)q31_exps;
      int8_t *out_row = out;
      float *row_recip = reciprocals;

      for( uint32_t r = 0; r < num_rows; ++r) {

        Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
              smParams->outClipping,
              smParams->outOffset,      /* Final Output Offset         */
              row_size, 1, 1            /* Output width, height, channels  */);

      Cy_NNLite_SetPrePostScaling(MXNNLITE_REGS,
        /*preScalingFactor=*/ 1.0f /* ignored... */,
        /*postScalingFactors=*/row_recip);

        Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_ACTIVATION_STREAMER, row);
        Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS, CY_NNLITE_OUT_STREAMER, out_row);
        kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
        status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
        if (status == CY_NNLITE_SUCCESS)
        {
            status = Cy_NNLite_WaitForCompletionPartialOp();
        }
        if ( status != CY_NNLITE_SUCCESS)
          return status;
        row += row_size*sizeof(int32_t);
        out_row += out_row_stride;
        ++row_recip;
      }
    }
#endif
  return status;
}


/**
 * @brief Compute 2D row-wise SoftMax
 *
 * @note This is a "macro" kernel requiring multiple primitive NNLite operations to compute.
 *
 * @param inData      Input tensor data
 * @param outData     Output tensor data (MUST be distinct from @c inData)
 * @param scratchBuf  Scratch buffer for intermediate values (required size returned by @c Cy_NNLite_SoftMax_ScratchBufSize)
 *                    (should be word-aligned for performance)
 * @param inoutDims   Dimensions of 2D input tensors (Set dim[0]==1 for 1D case)
 * @param smParams    Input/output tensor quantization parameters bitwidths etc.
 * @return cy_en_nnlite_status_t
 */

cy_en_nnlite_status_t
Cy_NNLite_SoftMax(const int8_t *inData, int8_t* outData,
                  int8_t *scratchBuf,
                  const cy_nn_dims_t *inoutDims,
                  const cy_nn_pwise_unary_params_t *smParams)
{

  uint32_t row_size;
  uint32_t num_rows;
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;
  float *reciprocals_buf;


  if((NULL == inData) || (NULL == outData)  ||
     (NULL == inoutDims) ||  (NULL == smParams) )
  {
    return CY_NNLITE_BAD_PARAM;
  }

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  kernelContext.LpmLockFunc();
  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    Cy_NNLite_StartMacroKernel();

    row_size = inoutDims->dims[1];
    num_rows = inoutDims->dims[0];

    Cy_NNLite_SetInterruptMask(MXNNLITE_REGS, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_REGS, false);

    Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, 1.0f);

    // ****************************************************************************
    // Compute MAX: num_rows maximums of num_rows x row_size input
    status = Cy_NNLite_SoftMax_RowMaxes(inData, scratchBuf, num_rows, row_size, smParams);
    if ( status != CY_NNLITE_SUCCESS) goto failure_return;


    // ****************************************************************************
    // Compute MAX - x_i

    // Differences are non-negative...
    cy_nnlite_clipping_t clip_diffs;
    float lg2_e_folded_prescale;
    switch (smParams->outputSize) {
      case CY_NNLITE_OUTPUT_8BIT:
        clip_diffs.min = -(1<<7);
        clip_diffs.max = (1<<7)-1;
        // Q8 input for 2^-x when 8-bit input selected.
        lg2_e_folded_prescale = 1.4426950408889634073599246810019f * (float) (1<<8u);
        break;

      case CY_NNLITE_OUTPUT_16BIT:
        clip_diffs.min = -(1<<15);
        clip_diffs.max = (1<<15)-1;
        // Q16 input for 2^-x when 16-bit input selected.
        lg2_e_folded_prescale = 1.4426950408889634073599246810019f * (float) (1<<16u);
        break;

      default:
        status = CY_NNLITE_BAD_PARAM;
        goto failure_return;
    }

    // We "Mis-use" output buffer for exponent differences...
    status = Cy_NNLite_SoftMax_SubFromRowMaxes(scratchBuf, inData, outData, num_rows, row_size, clip_diffs, smParams);
    if ( status != CY_NNLITE_SUCCESS) goto failure_return;

    // ****************************************************************************
    // Compute e-(MAX-x_i)  (32-bit intermediate precision)
    // outData  holds MAX-x_i at this point.  Output goes into temporary buffer at 32-bit precision

    status = Cy_NNLite_SoftMax_Exps(outData, scratchBuf, num_rows, row_size, clip_diffs, lg2_e_folded_prescale, smParams);
    if ( status != CY_NNLITE_SUCCESS) goto failure_return;

    // ****************************************************************************
    // Compute Reciprocal of \Sigma_i e-(MAX-x_i)  (32-bit float value from Q31 inputs)

    reciprocals_buf = ((float*)scratchBuf)+num_rows*row_size;
    status = Cy_NNLite_SoftMax_ReciprocalExpSum( (int32_t*)scratchBuf, reciprocals_buf, num_rows, row_size, clip_diffs, smParams);
    if ( status != CY_NNLITE_SUCCESS) goto failure_return;

    // ****************************************************************************
    // Rescale 32-bit e-(MAX-x_i)  to target output size...

   status = Cy_NNLite_SoftMax_Normalize((int32_t*)scratchBuf, reciprocals_buf, outData, num_rows, row_size, smParams);


  // *************************************************************
  // Completion... jump to here to cleanly exit...
failure_return:
    Cy_NNLite_EndMacrokernel();
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.LpmUnlockFunc();
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}

static cy_en_nnlite_status_t Cy_NNLite_CheckOutScalerExp(float scalingFactor)
{
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_PARAM;
  typedef union {
    float float_repr;
      struct {
        uint32_t mantisa : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
      } float_parts;
  } float_cast;
  float_cast scalingFactorCast = { .float_repr = scalingFactor };
  uint32_t scalingFactorExp = scalingFactorCast.float_parts.exp;
  //As per MXNNLitev2 BROS, exponent for scaling factor should be in range [96,135]
  if ((scalingFactorExp >= OUT_SCALING_FACTOR_EXP_MIN) && \
  (scalingFactorExp <= OUT_SCALING_FACTOR_EXP_MAX))
  {
    status = CY_NNLITE_SUCCESS;
  }
  return status;
}

static cy_en_nnlite_status_t
__Cy_NNLite_LayerNorm_RowBroadcasting(int8_t *inputData,
                    const cy_nn_dims_t *inputDims,
                    const cy_nn_dims_t *outputDims,
                    const cy_nn_pwise_binary_params_t *lnParams)
{
    cy_en_nnlite_status_t status = CY_NNLITE_BAD_STATE;
    // Step 1: workaround add/sub breaking depth multiplier mechanism by depth-multiplication
    // using a dummy DW convolution op... (summation with 1x1 kernel size)
    uint32_t row_size = outputDims->dims[0] * outputDims->dims[1] * outputDims->dims[2] * outputDims->dims[3];
    uint32_t num_rows = inputDims->dims[0];
      // We're writing far more than we read so we can't just over-write
      // to rely on caller allocating max_buf with having enough space..
      uint32_t max_values_len;
      switch (lnParams->inputSize) {
        case CY_NNLITE_ACTIVATION_8BIT:
          max_values_len = num_rows;
          break;

        case CY_NNLITE_ACTIVATION_16BIT:
          max_values_len = num_rows*2u;
          break;

        default:
          return CY_NNLITE_BAD_PARAM;
      }

      int8_t *replicated_max = inputData + max_values_len;
      Cy_NNLite_ActivationStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
          1, 1, /* Filter width, height */
          row_size,    /* Fetch each MAX row_size times  */
          1, 1, num_rows, /* input width, input height, input channels == # filters*/
          0, 0, 0, /* pad value, width. height */
          1, 1, /* stride col, stride row*/
          0 /* ignore input offset, we're going to work with differences... */
          );

        cy_nnlite_clipping_t no_clip = {
            /*min=*/ -(1<<15),
            /*max=*/(1<<15)-1
        };
      // No need to set weight streamer - not used...
      Cy_NNLite_OutputStreamerCfg(MXNNLITE_REGS, &kernelContext.pdlContext,
                                  no_clip,
                                  /*outputOffset=*/ 0,
                                  1, 1, num_rows*row_size /* output width, height, channels */);

      Cy_NNLite_PipelineConfig(MXNNLITE_REGS,
                                  /* opType= */ CY_NNLITE_NOOP_ACT,
                                  /* fetchMode = */ CY_NNLITE_DWACT_ONLY,
                                  /* repeatWeights = */ false,   // Don't care ... inactive
                                  /* biasEn = */ false,
                                  /* sparsityEn = */ false,
                                  /* outputRescaling= */ CY_NNLITE_OUTSCALE_NONE,
                                  /* inputRescaling= */ CY_NNLITE_RESCALE_NONE,
                                  CY_NNLITE_ACTIVATION_NONE,
                                  lnParams->inputSize,
                                  CY_NNLITE_ACTIVATION_8BIT,
                                  CY_NNLITE_ACT_AS_OUT_BW(lnParams->inputSize)
      );

      // No need for setting pre/post ALU scaling - both disabled...
      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
          CY_NNLITE_ACTIVATION_STREAMER, inputData);

      Cy_NNLite_StreamerBaseAddrSet(MXNNLITE_REGS,
          CY_NNLITE_OUT_STREAMER, replicated_max);

      status = Cy_NNLite_Start(MXNNLITE_REGS, &kernelContext.pdlContext);
      if (status == CY_NNLITE_SUCCESS)
      {
          status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      return status;
}

static cy_en_nnlite_status_t
Cy_NNLite_PrepareRescaleMinMax(const int8_t *inputData,
                    const cy_nn_dims_t *inputDims,
                    const cy_nn_dims_t *outDimsMeanVar,
                    int8 *scratchBufMean, int32_t *min_val,
                    int32_t *max_val, cy_nn_pwise_binary_params_t *lnParams)
{
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_PARAM;
  cy_nn_pool_params_t poolParamsCommon = {0};
  uint32_t input_data_flat_size = (inputDims->dims[1] * inputDims->dims[2] * inputDims->dims[3]) * sizeof(int16_t);
  int8_t *scratchBufSubMax = scratchBufMean   + input_data_flat_size;       /* intermediate scratch buffer for (x-max) vector[input_data_flat_size] */
  int8_t *scratchBufMax    = scratchBufSubMax   + input_data_flat_size;  /* intermediate scratch buffer for (x-max) vector[input_data_flat_size] */
  poolParamsCommon.strideCol   = 1;
  poolParamsCommon.strideRow   = 1;
  poolParamsCommon.act_size    = lnParams->inputSize;
  poolParamsCommon.outClipping = lnParams->outClipping;
  /* Compute max_value of vector */
  status = __Cy_NNLite_Maxpool(inputData, scratchBufMax, inputDims, outDimsMeanVar, inputDims, &poolParamsCommon, false);
  if (status != CY_NNLITE_SUCCESS)
    return status;
  switch (lnParams->inputSize)
    {
      case CY_NNLITE_ACTIVATION_8BIT:
        *max_val = *scratchBufMax;
        break;
      case CY_NNLITE_ACTIVATION_16BIT:
        *max_val = *(int16_t*)scratchBufMax;
        break;
      default:
        status = CY_NNLITE_BAD_PARAM;
        return status;
    }
  /* Broadcast scalar to vector for sub operation */
  status = __Cy_NNLite_LayerNorm_RowBroadcasting(scratchBufMax,inputDims,inputDims,lnParams);
  if (status != CY_NNLITE_SUCCESS)
    return status;
  /* Compute rescaler min value */
  status = Cy_NNLite_Scaling_Setup(&lnParams->scaling, 1.0f, 1.0f, -1.0f,
                                    lnParams->inputSize, CY_NNLITE_SUB_RL,
                                    CY_NNLITE_ACTIVATION_NONE);
  if (status != CY_NNLITE_SUCCESS)
    return status;
  /* Compute -1 * (x-max) + max to compute min value */
  status = Cy_NNLite_Sub(inputData, scratchBufMax, scratchBufSubMax, inputDims, inputDims, lnParams, true);
  if (status != CY_NNLITE_SUCCESS)
    return status;
  poolParamsCommon.act_size        = CY_NNLITE_ACTIVATION_16BIT;
  status = __Cy_NNLite_Maxpool(scratchBufSubMax, scratchBufMax, inputDims, outDimsMeanVar, inputDims, &poolParamsCommon, false);
  if ( status != CY_NNLITE_SUCCESS)
    return status;
  switch (lnParams->inputSize)
  {
    case CY_NNLITE_ACTIVATION_8BIT:
      *min_val = - 1 * (*(int16_t*)scratchBufMax) + *max_val;
      break;
    case CY_NNLITE_ACTIVATION_16BIT:
      *min_val = - 1 * (*(int16_t*)scratchBufMax) + *max_val;
      break;
    default:
      status = CY_NNLITE_BAD_PARAM;
      return status;
  }
  status = CY_NNLITE_SUCCESS;
  return status;
}

/**
 * @brief Compute composite LayerNorm operation
 *
 * @note This is a "macro" kernel requiring multiple primitive NNLite operations to compute.
 *
 * @param inData      Input tensor data
 * @param outData     Output tensor data (MUST be distinct from @c inData)
 * @param inputDims   Input dimension pointer
 * @param outputDims  Output dimension pointer
 * @param lnParam     LayerNorm parameter structure pointer.
 * @return cy_en_nnlite_status_t
 */
cy_en_nnlite_status_t
Cy_NNLite_LayerNorm(const int8_t *inputData, int8_t* outputData,
                    const cy_nn_dims_t *inputDims,
                    const cy_nn_dims_t *outputDims,
                    const cy_nn_layernorm_params_t *lnParams)
{
  cy_en_nnlite_status_t status = CY_NNLITE_BAD_PARAM;
  float outputActivationScaler = 0.0;
  float variance_scaler = 0.0;
  int32_t offset_var_pow = 0;
  float scale_var_pow = 1.0;
  int32_t offset_var_sub = 0;
  float scale_var_sub = 1.0;
  int32_t min_val_sub = 0;
  int32_t max_val_sub = 0;
  if((NULL == inputDims) || (NULL == outputDims) ||
     (NULL == lnParams) || (NULL == inputData) ||
     (NULL == outputData) ||
     (NULL == lnParams->scratchBuf))
  {
    return CY_NNLITE_BAD_PARAM;
  }
  /* Unsupported mode for per-tensor mean value as per current AvgPool implementation */
  if (inputDims->dims[3] != 1) {
    return CY_NNLITE_BAD_PARAM;
  }
  /* United pool params for mean and variance calculation */
  cy_nn_pool_params_t poolParamsCommon = {0};
  cy_nn_pwise_binary_params_t pwiseBinaryParams = {0};
  cy_nn_pwise_unary_params_t pwiseUnaryParams = {0};
  cy_nn_act_intrpl_param_t intrplParam = {0};

  /* Output dims for mean and variance calculation */
  cy_nn_dims_t outDimsMeanVar;

  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  kernelContext.LpmLockFunc();
  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {
    uint32_t input_data_flat_size = (inputDims->dims[1] * inputDims->dims[2] * inputDims->dims[3]) * sizeof(int16_t);
    int8_t *scratchBufMean     = (int8_t *)lnParams->scratchBuf;             /* intermediate scratch buffer for mean values */
    int8_t *scratchBufSubMean  = scratchBufMean     + input_data_flat_size;  /* intermediate scratch buffer for (x-mean) vector[input_data_flat_size]    */
    int8_t *scratchBufVariance = scratchBufSubMean  + input_data_flat_size;  /* intermediate scratch buffer for variance value, single int16 value       */
    int8_t *scratchBufMulMean  = scratchBufVariance  + sizeof(int16_t);      /* intermediate scratch buffer for (x-mean)^2 vector[input_data_flat_size]  */
    poolParamsCommon.strideCol   = 1;
    poolParamsCommon.strideRow   = 1;
    poolParamsCommon.act_size    = lnParams->inputSize;
    poolParamsCommon.outClipping = lnParams->outClipping;

    pwiseBinaryParams.outClipping = lnParams->outClipping;
    pwiseBinaryParams.inputSize   = lnParams->inputSize;
    pwiseBinaryParams.outputSize  = lnParams->outputSize; /* set 16-bit intermediate tensor for pow2 vector values */
    status = Cy_NNLite_Scaling_Setup(&pwiseBinaryParams.scaling, 1.0f, 1.0f, 1.0f,
                                     pwiseBinaryParams.inputSize, CY_NNLITE_SUB_LR,
                                     CY_NNLITE_ACTIVATION_NONE);
    if ( status != CY_NNLITE_SUCCESS)
      goto failure_return;

    pwiseUnaryParams.inScale     = lnParams->inScale;
    pwiseUnaryParams.inOffset    = lnParams->inOffset;
    pwiseUnaryParams.outClipping = lnParams->outClipping;
    pwiseUnaryParams.inputSize   = lnParams->inputSize;
    pwiseUnaryParams.outputSize  = lnParams->outputSize;

    /* Output dims for mean and variance (always scalar values) */
    outDimsMeanVar.dims[0] = 1;
    outDimsMeanVar.dims[1] = 1;
    outDimsMeanVar.dims[2] = 1;
    outDimsMeanVar.dims[3] = 1;

    Cy_NNLite_StartMacroKernel();

    Cy_NNLite_SetInterruptMask(MXNNLITE_REGS, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(MXNNLITE_REGS, false);

    Cy_NNLite_SetInterpolationParam(MXNNLITE_REGS, 0, 1.0f);
    /* Step 1: Compute Mean value */
    status = __Cy_NNLite_Avgpool(inputData, scratchBufMean, inputDims, &outDimsMeanVar, inputDims, &poolParamsCommon, false);
    if (status != CY_NNLITE_SUCCESS)
      goto failure_return;
    /* Step 2: compute (x_1 - mean) values */
    status = __Cy_NNLite_LayerNorm_RowBroadcasting(scratchBufMean,inputDims,inputDims,&pwiseBinaryParams);
    if (status != CY_NNLITE_SUCCESS)
      goto failure_return;
    if (lnParams->inputSize == CY_NNLITE_ACTIVATION_16BIT)
    {
      status = Cy_NNLite_PrepareRescaleMinMax(inputData, inputDims,&outDimsMeanVar,
                                              scratchBufMulMean, &min_val_sub, &max_val_sub,  &pwiseBinaryParams);
      min_val_sub -= *scratchBufMean;
      max_val_sub -= *scratchBufMean;
      if (((int32_t) min_val_sub < INT16_MIN) || ((int32_t)(max_val_sub) >INT16_MAX))
      {
        scale_var_sub = (float)(lnParams->outClipping.max - lnParams->outClipping.min) /
                                   (float)(max_val_sub - min_val_sub);
        offset_var_sub = - (int32_t)(scale_var_sub * min_val_sub) + lnParams->outClipping.min;
      }
    }
    /*Setup re-scaling params to exclude overflow for 16-bits*/
    pwiseBinaryParams.outputOffset = offset_var_sub;
    pwiseBinaryParams.outputSize = CY_NNLITE_OUTPUT_16BIT;
    pwiseBinaryParams.outClipping.min = INT16_MIN;
    pwiseBinaryParams.outClipping.max = INT16_MAX;
    //pwiseBinaryParams.outClipping = lnParams->outClipping;
    status = Cy_NNLite_Scaling_Setup(&pwiseBinaryParams.scaling, 1.0f, 1.0f,  1.0f/scale_var_sub,
                                     pwiseBinaryParams.inputSize, CY_NNLITE_SUB_LR,
                                     CY_NNLITE_ACTIVATION_NONE);
    status = Cy_NNLite_Sub(inputData, scratchBufMean, scratchBufSubMean, inputDims, outputDims, &pwiseBinaryParams, false);
    if (status != CY_NNLITE_SUCCESS)
      goto failure_return;
    /* Step3: (x-mean)^2 */
    pwiseBinaryParams.outputOffset    = 0;
    pwiseBinaryParams.inputSize       = CY_NNLITE_ACTIVATION_16BIT;
    pwiseBinaryParams.outputSize      = CY_NNLITE_OUTPUT_16BIT;
    pwiseBinaryParams.outClipping.min = INT16_MIN;
    pwiseBinaryParams.outClipping.max = INT16_MAX;
    /* Start of re-scaling block (unused for 8 bits, as multiplication op do not overflow 16-bits).
     * Computes scaler and offset to 16-bits (symmetric quantization case)
     */
  pwiseBinaryParams.inputSize       = CY_NNLITE_ACTIVATION_16BIT;
  //TODO: modulus function. Should be replaced with Activation function with pwl activation, if supported
  for (uint32_t i=0;i < inputDims->dims[1] * inputDims->dims[2] * inputDims->dims[3]; i++)
  {
      *((int16_t*)scratchBufMean + i) = abs(*((int16_t*)scratchBufSubMean + i));
  }
  status = Cy_NNLite_PrepareRescaleMinMax(scratchBufMean, inputDims,&outDimsMeanVar,
                                          scratchBufMulMean, &min_val_sub, &max_val_sub, &pwiseBinaryParams);
  min_val_sub *= min_val_sub;
  max_val_sub *= max_val_sub;
  /* compute scalers for mul only if pow 2 max or min overflow 16-bits */
  if (((int32_t) min_val_sub < INT16_MIN) || ((int32_t)(max_val_sub) >INT16_MAX))
  {
    scale_var_pow = (float)(lnParams->outClipping.max - lnParams->outClipping.min) /
                           (float)(max_val_sub - min_val_sub);
    offset_var_pow = - (int32_t)(scale_var_pow * min_val_sub) + INT16_MIN;
    /*Setup re-scaling params to exclude overflow for 16-bits*/
    status = Cy_NNLite_Scaling_Setup(&pwiseBinaryParams.scaling, 1.0f, 1.0f, 1.0f/scale_var_pow,
                                     pwiseBinaryParams.inputSize, CY_NNLITE_MUL,
                                     CY_NNLITE_ACTIVATION_NONE);
    pwiseBinaryParams.outputOffset = offset_var_pow;
    if (status != CY_NNLITE_SUCCESS)
      goto failure_return;
  }

    status = Cy_NNLite_Mul(scratchBufSubMean, scratchBufSubMean, scratchBufMulMean, outputDims, outputDims, &pwiseBinaryParams);
    if (status != CY_NNLITE_SUCCESS)
      goto failure_return;
    /* Step 4: compute variance */
    poolParamsCommon.act_size    = CY_NNLITE_ACTIVATION_16BIT;
    poolParamsCommon.outClipping.min = INT16_MIN;
    poolParamsCommon.outClipping.max = INT16_MAX;
    status = __Cy_NNLite_Avgpool(scratchBufMulMean, scratchBufVariance, inputDims, &outDimsMeanVar, inputDims, &poolParamsCommon, false);
    if ( status != CY_NNLITE_SUCCESS)
      goto failure_return;
    /* Step 5: compute scaler */
    variance_scaler = (float)((*(int16_t*)scratchBufVariance) - (offset_var_pow + offset_var_sub)) / (scale_var_pow*scale_var_sub);
    outputActivationScaler = 1.0f / sqrtf(variance_scaler + lnParams->epsilon);
    /* Step5: use activation to apply scaler to all elements of input */
    pwiseUnaryParams.outScale        = outputActivationScaler * lnParams->outScale;
    status = Cy_NNLite_CheckOutScalerExp(pwiseUnaryParams.outScale);
    if ( status != CY_NNLITE_SUCCESS)
      goto failure_return;
    pwiseUnaryParams.outOffset       = lnParams->outOffset;
    pwiseUnaryParams.outClipping = lnParams->outClipping;
    pwiseUnaryParams.inputSize       = CY_NNLITE_ACTIVATION_16BIT;
    pwiseUnaryParams.outputSize      = lnParams->outputSize;
    status = __Cy_NNLite_Activation(scratchBufSubMean, outputData, outputDims, &pwiseUnaryParams, CY_NNLITE_ACTIVATION_NONE, &intrplParam, false);
failure_return:
    Cy_NNLite_EndMacrokernel();
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.LpmUnlockFunc();
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;

}

/**
 *****************************************************************************
 ** API will return scratch buffer size for LayerNorm kernel,
 ** buffer will be used for intermediate calculations
 **
 *****************************************************************************/
uint32_t Cy_NNLite_LayerNormScratchBufSize (const cy_nn_dims_t *inputDims, cy_en_nnlite_activation_size_t inputSize)
{
  uint32_t bufSize = 0;
  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  uint32_t input_data_flat_size =  inputDims->dims[1] * inputDims->dims[2] * inputDims->dims[3];
  if (inputSize == CY_NNLITE_ACTIVATION_8BIT)
  {
    bufSize = sizeof(uint16_t) * (3 * input_data_flat_size + 1);
  }
  else
  {
    bufSize = sizeof(uint16_t) * (5 * input_data_flat_size + 1);
  }
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return bufSize;
}

/**
 *****************************************************************************
*
 * @brief Compute Q1.15 complex FFT
 *
 * NNLite implements Decimation-in-Time  Radix-2 FFT
 *
 * @note FFT length =^= Number complex input values *2 = #
 * @param ppBuf0    Input / ping-pong buffer 0, Output (even stages/# values)
 * @param ppBuf1    ping-pong buffer 1, Output (odd stages/# values)
 * @param fftStages   log_2(FFT length)
 *
 * @return cy_en_nnlite_status_t
 *****************************************************************************
 */

cy_en_nnlite_status_t
__Cy_NNLite_FFT(int32_t *ppBuf0, int32_t* ppBuf1, unsigned int fftStages,
                void *scratchBuf, bool dmaMode)
{
  cy_en_nnlite_status_t status;

  if( (NULL == ppBuf0) || (NULL == ppBuf1))
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else if (fftStages < 4u || fftStages > 10u)
  {
  return CY_NNLITE_BAD_PARAM;
  }
  else if (dmaMode && (NULL == scratchBuf))
  {
    status = CY_NNLITE_BAD_PARAM;
  }


  kernelContext.mutexLockFunc(kernelContext.nnliteMutex);
  kernelContext.profStart(kernelContext.profArg);
  if((kernelContext.pdlContext.nnliteState == CY_NNLITE_INIT) ||
     (kernelContext.pdlContext.nnliteState == CY_NNLITE_OP_DONE))
  {

     NNLITE_Type *Memio = dmaMode ? (NNLITE_Type *)scratchBuf : MXNNLITE_REGS ;
    Cy_NNLite_SetInterruptMask(Memio, NNLITE_INTR_ENABLE_MASK);
    /* Disable DW trigger for CPU mode */
    Cy_NNLite_DatawireTriggerEnable(Memio, dmaMode);

    status = Cy_NNLite_FFTCfg(Memio, &kernelContext.pdlContext,
                              ppBuf0, ppBuf1, fftStages);
    if (!dmaMode)
    {
      kernelContext.LpmLockFunc();
      kernelContext.profGetCount(kernelContext.profArg, CY_NNLITE_PP_ACCELERATOR_START);
      if (status == CY_NNLITE_SUCCESS)
      {
        status = Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      }
      if (status == CY_NNLITE_SUCCESS)
      {
        status = Cy_NNLite_WaitForCompletionPartialOp();
      }
      if (kernelContext.completionCbFunc == 0)
      {
        kernelContext.LpmUnlockFunc();
      }
    }
#if  CY_NNLITE_DMA_DEVICE
    else
    {
      cy_stc_dma_descriptor_config_t *cfgDesc;
      cy_stc_dma_descriptor_t *desc;

      Cy_NNLite_Start(Memio, &kernelContext.pdlContext);
      cfgDesc = (cy_stc_dma_descriptor_config_t *)((size_t)scratchBuf + sizeof(NNLITE_Type));
      desc = (cy_stc_dma_descriptor_t *)(cfgDesc + DESC_COUNT_PER_LAYER);

      Cy_NNLite_SetupNNLiteMemioDMADesc(Memio, &nnliteDMAQ, cfgDesc, desc);
      status = CY_NNLITE_OP_QUEUED;
    }
#endif
  }
  else
  {
    status = CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
  return status;
}

cy_en_nnlite_status_t
Cy_NNLite_FFT(int32_t *ppBuf0, int32_t* ppBuf1,
              unsigned int fftStages)
{
  return __Cy_NNLite_FFT(ppBuf0, ppBuf1, fftStages, NULL, false);
}

#if  CY_NNLITE_DMA_DEVICE
cy_en_nnlite_status_t
Cy_NNLite_FFTDMA(int32_t *ppBuf0, int32_t* ppBuf1,
                 unsigned int fftStages, void *scratchBuf)
{
  return __Cy_NNLite_FFT(ppBuf0, ppBuf1, fftStages, scratchBuf, true);
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
      NNLITE_Type *currMemio;
      cy_stc_dma_descriptor_config_t *firstCurrDesc;

      firstCurrDesc = currDMAQ->currCfgDesc - (DESC_COUNT_PER_LAYER - 1);
      /* src address it pointing to offset 4, offset 0 is RESERVED */
      currMemio = (NNLITE_Type *)((size_t)firstCurrDesc->srcAddress - 4);
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
   if (kernelContext.completionCbFunc == NULL)
   {
     kernelContext.SemWaitFunc(kernelContext.nnliteSem);
     kernelContext.LpmUnlockFunc();
     status = kernelContext.pdlContext.opStatus;
   }
  }
  else
  {
    status =  CY_NNLITE_BAD_STATE;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);

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
    if (kernelContext.completionCbFunc == NULL)
    {
      kernelContext.SemWaitFunc(kernelContext.nnliteSem);
      kernelContext.LpmUnlockFunc();
      status = kernelContext.pdlContext.opStatus;
    }
  }
  else
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  kernelContext.profStop(kernelContext.profArg);
  kernelContext.mutexUnlockFunc(kernelContext.nnliteMutex);
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

#endif //CY_NNLITE_DMA_DEVICE

#endif //CY_IP_MXNNLITE_VERSION

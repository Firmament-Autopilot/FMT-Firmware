/***************************************************************************//**
* \file cy_nn_kernel.h
* \version 1.0
*
* \brief
* Provides NNLite accelerator driver API declarations.
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
*
*
* \section group_nn_kernel_changelog Changelog
*
* <table class="doxtable">
*   <tr><th>Version</th><th>Changes</th><th>Reason for Change</th></tr>
*   <tr>
*     <td>2.0</td>
*     <td>Initial version</td>
*     <td></td>
*   </tr>
*******************************************************************************/


/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#ifndef CY_NN_KERNEL_H
#define CY_NN_KERNEL_H

#if defined(__cplusplus)
extern "C" {
#endif
#include "cy_device.h"
#include "cy_pdl.h"

#define OUT_SCALING_FACTOR_EXP_MIN 96
#define OUT_SCALING_FACTOR_EXP_MAX 135

#if CY_IP_MXNNLITE_VERSION !=1
#include "cy_nn_types.h"
#endif

/**
* \defgroup group_nn_kernel NNLITE HW Accelerator KERNEL LIB
* \{
* This driver provides NN Kernel level defines and API function definitions for NNLITE Lite HW  accelerator.
* \defgroup group_nn_kernel_macros  Macros
* \defgroup group_nn_kernel_enums Enums
* \defgroup group_nn_kernel_data_structures  Structures
* \defgroup group_nn_kernel_functions functions
* \} */

/** \addtogroup group_nn_kernel_macros
* \{
*/
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/
#ifndef NNLITE_DEFAULT_ISR_PRIORITY
#define NNLITE_DEFAULT_ISR_PRIORITY (2U) /**< Default Interrupt Priority for NNLite */
#endif
#if CY_NNLITE_ACTIVATION_8BIT != CY_NNLITE_OUTPUT_8BIT || CY_NNLITE_ACTIVATION_16BIT != CY_NNLITE_OUTPUT_16BIT
#error Reinterpretation of activation bitwidth to output bitwidth not possible
#else
#define CY_NNLITE_ACT_AS_OUT_BW(act_bw) ((cy_en_nnlite_output_size_t)(act_bw)) /**< size control helper macro for output size */
#define CY_NNLITE_OUT_AS_ACT_BW(act_bw) ((cy_en_nnlite_activation_size_t)(act_bw)) /**< size control helper macro for input size */
#endif

/** \} group_nn_kernel_macros */

/** \addtogroup group_nn_kernel_enums
* \{
*/
#if CY_IP_MXNNLITE_VERSION==1
/** NNLite DMA descriptor types */
typedef enum
{
  CY_NNLITE_DMA_DESC_MEMIO = 0,/**< Descriptor is for MEMIO transfer */
  CY_NNLITE_DMA_DESC_TRANSPOSE,/**< Descriptor is for Transpose operation */
} cy_nnlite_current_dma_desc_type_t;

/** NNLite DMA queue states */
typedef enum
{
  CY_NNLITE_DMA_QUEUE_EMPTY = 0, /**< nnlite dma queue is empty */
  CY_NNLITE_DMA_OPERATION_QUEUED,/**< nnlite dma operation queued */
  CY_NNLITE_DMA_QUEUE_TRIGGERED, /**< nnlite dma is triggered */
  CY_NNLITE_DMA_QUEUE_DONE, /**< nnlite dma is executed */
} cy_nnlite_dma_queue_state_t;

/** NNLite Kernel API's intermediate Profile points types */
typedef enum
{
  CY_NNLITE_PP_ACCELERATOR_START = 0,/**< Profile point for NNLite IP start */
  CY_NNLITE_PP_TRANSPOSE_START,/**< Profile point for TRANSPOSE Operation*/
  CY_NNLITE_PP_TRANSPOSE_DMA_TRIGGER,/**< Profile point for TRANSPOSE DMA Trigger */
  CY_NNLITE_PP_TRANSPOSE_DONE,/**< Profile point for TRANSPOSE DMA Completion */
  CY_NNLITE_PP_DMA_MODE_TRIGGER,/**< Profile point for DMA Mode API DMA Trigger */
  CY_NNLITE_PP_DMA_MODE_END,/**< Profile point for DMA Mode Completion */
  CY_NNLITE_PP_ACCELERATOR_DONE,/**< Profile point for NNLite Completion */
  CY_NNLITE_PP_COUNT,/**< Profile point Count */
} cy_nnlite_profile_points_type_t;
#else

/** NNLite DMA queue states */
typedef enum
{
  CY_NNLITE_DMA_QUEUE_EMPTY = 0, /**< nnlite dma queue is empty */
  CY_NNLITE_DMA_OPERATION_QUEUED,/**< nnlite dma operation queued */
  CY_NNLITE_DMA_QUEUE_TRIGGERED, /**< nnlite dma is triggered */
  CY_NNLITE_DMA_QUEUE_DONE, /**< nnlite dma is executed */
} cy_nnlite_dma_queue_state_t;

/** NNLite DMA descriptor types */
typedef enum
{
  CY_NNLITE_DMA_DESC_MEMIO = 0,/**< Descriptor is for MEMIO transfer */
} cy_nnlite_current_dma_desc_type_t;

/** NNLite Kernel API's intermediate Profile points types */
typedef enum
{
  CY_NNLITE_PP_ACCELERATOR_START = 0,/**< Profile point for NNLite IP start */
  CY_NNLITE_PP_DMA_MODE_TRIGGER,/**< Profile point for DMA Mode API DMA Trigger */
  CY_NNLITE_PP_DMA_MODE_END,/**< Profile point for DMA Mode Completion */
  CY_NNLITE_PP_ACCELERATOR_DONE,/**< Profile point for NNLite Completion */
} cy_nnlite_profile_points_type_t;
#endif

/** \} group_nn_kernel_enums */

/**
* \addtogroup group_nn_kernel_data_structures
* \{
*/

/**
 *****************************************************************************
 ** \brief Convolution parameter structure
 *****************************************************************************/
typedef struct cy_nn_conv_params_s
{
#if CY_IP_MXNNLITE_VERSION==1
  int32_t startCol; /**< Activation start column */
  int32_t startRow; /**< Activation start Row */
#endif
  int16_t padValue; /**< padding value for activation */
  uint8_t padWidth; /**< padding width - padded columns before data start*/
  uint8_t padHeight; /**< padding height - padded rows before data start*/
  uint8_t strideCol; /**< stride column */
  uint8_t strideRow; /**< stride Row  */
  int32_t inputOffset; /**< activation value offset */
  int32_t outputOffset; /**< output offset value */
  int32_t filterOffset; /**< filter offset value */
#if CY_IP_MXNNLITE_VERSION==1
  int32_t outClippingMask; /**< output value saturated to max/min based on\
                            clippingMask value*/
  float *outScalingFactor; /**< per axis output scaling factor */
#else
  const float *outScalingFactor; /**< per axis output scaling factor */
  cy_nnlite_clipping_t outClipping; /**< output value clipping */
  cy_en_nnlite_activation_size_t  act_size; /**< Selection activation data-path width */
  bool sparseWeights;                         /**< Packed Sparse weights */
#endif
  int8_t *scratchBuf; /**< scratch buffer for convolution layer, will be used\
                       DMA descriptors in DMA mode */
} cy_nn_conv_params_t;

/**
 *****************************************************************************
 ** \brief FC parameter structure
 *****************************************************************************/
typedef struct cy_nn_fc_params_s
{
  int32_t inputOffset; /**< activation value offset */
  int32_t outputOffset; /**< output offset vaLUE */
  int32_t filterOffset; /**< Filter offset value */
  float outScalingFactor; /**< output scaling factor */
#if CY_IP_MXNNLITE_VERSION==1
  int32_t outClippingMask; /**< output value saturated to max/min based on\
                            clippingMask value*/
#else
  cy_nnlite_clipping_t outClipping; /**< output value clipping */
  cy_en_nnlite_activation_size_t inputSize;   /**< Input data precision */
  cy_en_nnlite_output_size_t     outputSize;  /**<  Output precision  */
  bool sparseWeights;                         /**< Packed Sparse weights */
#endif
  int8_t *scratchBuf; /**< scratch buffer for fc layer, will be used for for\
                       DMA descriptors and MEMIO configuration in DMA mode */
} cy_nn_fc_params_t;

#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 ** \brief Average pool parameter structure
 *****************************************************************************/
typedef struct
{
  uint8_t padWidth; /**< padding width */
  uint8_t padHeight; /**< padding height */
  uint8_t strideCol; /**< stride column */
  uint8_t strideRow; /**< stride row */
  int32_t outClippingMask; /**< output value saturated to max/min based on\
                           clippingMask value*/
  int8_t *scratchBuf;   /**< used for transpose operations,
                           DMA descriptors and MEMIO configuration in DMA mode */
} cy_nn_avgpool_params_t;
#else
/**
 *****************************************************************************
 ** \brief Average pool parameter structure
 *****************************************************************************/
typedef struct cy_nn_pool_params_s
{
  uint8_t strideCol; /**< stride column */
  uint8_t strideRow; /**< stride row */
  cy_nnlite_clipping_t outClipping; /**< output value clipping */
  cy_en_nnlite_activation_size_t  act_size; /**< Selection activation data-path width */
  int8_t *scratchBuf;   /**< DMA descriptors and MEMIO configuration in DMA mode */
} cy_nn_pool_params_t;
#endif

#if CY_IP_MXNNLITE_VERSION !=1
/**
 *****************************************************************************
 ** \brief Pointwise operation parameter structure
 *****************************************************************************/
typedef struct cy_nn_scaling_s
{
  /**  Scale factor to apply to (one) MAC input */
  float pre_mac_scale;
   /** Scale factor to apply prior to activation function (if any) */
  float pre_act_scale;
  /** Mode for MAC input scaling (off, weights, activations)*/
  cy_en_nnlite_input_rescaling_t  pre_mac_scaling_mode;
  /** Mode for pre-activation scaling (off, per-tensor, per-channels) */
  cy_en_nnlite_output_rescaling_t pre_act_scaling_mode;
  /** Scaling to apply to activation output ("output rescaling factor")*/
  float post_act_scale;
  int8_t *scratchBuf;   /**< DMA descriptors and MEMIO configuration in DMA mode */
} cy_nn_scaling_t;

/**
 *****************************************************************************
 ** \brief Pointwise binary operation parameter structure
 *****************************************************************************/
typedef struct cy_nn_pwise_binary_params_s
{
  int32_t   lhsOffset;  /**<  Zero-point for lhs values */
  int32_t   rhsOffset;  /**<  Zero-point for rhs values */
  int32_t   outputOffset;  /**<  Zero-point to use for output */
  cy_nnlite_clipping_t outClipping; /**< output value clipping */
  cy_en_nnlite_activation_size_t inputSize;   /**< Input data precision */
  cy_en_nnlite_output_size_t     outputSize;  /**<  Output precision  */
  cy_nn_scaling_t scaling; /**< Pointwise operation parameter */
  int8_t *scratchBuf;   /**< DMA descriptors and MEMIO configuration in DMA mode */
} cy_nn_pwise_binary_params_t;

/**
 *****************************************************************************
 ** \brief Pointwise unary operation parameter structure
 **
 *****************************************************************************/
typedef struct cy_nn_pwise_unary_params_s
{
  float     inScale;   /**< Pre-scaling to apply to lhs before op (must be 1.0 if rhsScale != 1.0)*/
  int32_t   inOffset;  /**<  Zero-point for lhs values */
  float     outScale;   /**<  Scale factor to apply to results of op values () */
  int32_t   outOffset;  /**<  Zero-point to use for output */
  cy_nnlite_clipping_t outClipping; /**< output value clipping */
  cy_en_nnlite_activation_size_t inputSize;   /**< Input data precision */
  cy_en_nnlite_output_size_t     outputSize;  /**<  Output precision  */
  int8_t *scratchBuf;   /**< DMA descriptors and MEMIO configuration in DMA mode */
} cy_nn_pwise_unary_params_t;

/**
 *****************************************************************************
 ** \brief Layer Normmalization operation parameter structure
 **
 *****************************************************************************/
typedef struct cy_nn_layernorm_params_s
{
  float     inScale;   /**< Pre-scaling to apply to input before op */
  int32_t   inOffset;  /**<  Zero-point for input values */
  float     outScale;   /**<  Scale factor to apply to results of op values */
  int32_t   outOffset;  /**<  Zero-point to use for output */
  float     epsilon;        /**<  Constant value, used for numeric stability */
  cy_nnlite_clipping_t outClipping; /**< output value clipping */
  cy_en_nnlite_activation_size_t inputSize;   /**< Input data precision */
  cy_en_nnlite_output_size_t     outputSize;  /**<  Output precision  */
  int8_t *scratchBuf;  /**<  Scratch buffer for intermediate tensors  */
} cy_nn_layernorm_params_t;

#endif

/**
 *****************************************************************************
 ** \brief dimension structure for input, output & filter
 ** dimension array of tensor, ordering of dimension should be same as
 ** TF model file, e.g. for convolution layer input height and width order
 ** should be input height = inputDims->dims[1],
 ** input width = inputDims->dims[2],
 ** filter dimension order should be filter_height = filterDims->dims[1],
 ** filter_width = filterDims->dims[2],filter_depth = filterDims->dims[3],
 ** output dimension order should be output_height = outputDims->dims[1],
 ** output_width = outputDims->dims[2]
 **
 *****************************************************************************/
typedef struct cy_nn_dims_s
{
  uint32_t dims[4];  /**<  dimension array of tensor */
} cy_nn_dims_t;

#if CY_IP_MXNNLITE_VERSION ==1
/**
 *****************************************************************************
 ** \brief activation parameter structure
 *****************************************************************************/
typedef struct
{
  uint16_t intercept0; /**< intercept value for interpolation,
                           x<0, LUTAddr = 0 */
  uint16_t intercept1; /**< intercept value for interpolation,
                           x>=0, LUTAddr = 1 */
  uint16_t slope0; /**< slope value for interpolation, x<0, LUTAddr = 0 */
  uint16_t slope1; /**< slope value for interpolation, x>=0, LUTAddr = 1 */
} cy_nn_act_intrpl_param_t;
#else
/**
 *****************************************************************************
 ** \brief activation parameter structure
 *****************************************************************************/
typedef struct
{
  float segment[2]; /**< Interpolation values index 0: x >= 0, index 0 1: x < 0 */
} cy_nn_act_intrpl_param_t;

#endif

/**
 *****************************************************************************
 ** \brief nnlite dma descriptor queue structure, use to maintain DMA
 ** channel info and DMA Queue Descriptor pointers
 *****************************************************************************/
typedef struct cy_nnlite_dma_queue_config
{
  cy_stc_dma_channel_config_t channelConfig; /**< DMA channel config */
  cy_stc_dma_descriptor_config_t *currCfgDesc; /**< DMA Queue config descriptor
                                                current pointer */
  cy_stc_dma_descriptor_t *currDesc; /**< DMA Queue descriptor
                                                current pointer */
  cy_nnlite_current_dma_desc_type_t currDescType;/**< DMA descriptor
                                                 MEMIO or Transpose type */
  cy_stc_dma_descriptor_t *headDesc; /**< DMA Queue descriptor
                                                head pointer */
  uint32_t dmaQDepth; /**< DMA Queue depth */
  cy_nnlite_dma_queue_state_t dmaQState; /**< DMA Q state */
} cy_nnlite_dma_queue_config_t;
/**
 *****************************************************************************
 ** \brief typedef for callback function, called from interrupt handler,
 ** to signal completion of layer, as called from  interrupt handler callback
 ** function should not call any blocking function and should have
 ** minimum code required for completion signal
 ** \param [in]  cbArg    argument with which callback function will be called
 **
 ** \param [in]  status   status of operation
 *****************************************************************************/
typedef void (*Cy_NNLite_CompletionCallback)(void *cbArg,
                                            cy_en_nnlite_status_t status);

/**
 *****************************************************************************
 ** \brief typedef for Mutex create function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_MutexCreate)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for Mutex delete function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_MutexDelete)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for mutex lock function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_MutexLock)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for mutex unlock function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_MutexUnlock)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for sem create function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_SemCreate)(void *ptr);
/**
 *****************************************************************************
 ** \brief typedef for sem delete function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_SemDelete)(void *ptr);
/**
 *****************************************************************************
 ** \brief typedef for sem wait function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_SemWait)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for sem give function
 *****************************************************************************/
typedef uint32_t (*Cy_NNLite_SemGive)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for LPM lock function
 *****************************************************************************/
typedef void (*Cy_NNLite_LpmLock)(void);

/**
 *****************************************************************************
 ** \brief typedef for LPM unlock function
 *****************************************************************************/
typedef void (*Cy_NNLite_LpmUnlock)(void);

/**
 *****************************************************************************
 ** \brief typedef for profile start function, called at start of API
 *****************************************************************************/
typedef void (*Cy_NNLite_ProfileStart)(void *ptr);

/**
 *****************************************************************************
 ** \brief typedef for profile get count at intermediate profile point
 *****************************************************************************/
typedef void (*Cy_NNLite_ProfileGetCount)(void *ptr, uint32_t profilePoint);

/**
 *****************************************************************************
 ** \brief typedef for profile end function called at end of API
 *****************************************************************************/
typedef void (*Cy_NNLite_ProfileStop)(void *ptr);



/**
 *****************************************************************************
 ** \brief nnlite kernel config structure, to be filled passed in kernel Init
 ** function to setup function pointers
 *****************************************************************************/
typedef struct cy_kernel_config
{
  Cy_NNLite_CompletionCallback completionCbFunc; /**< Kernel completion called back
                        function, to filled by upper layer, should not
                        have/call blocking implementation*/
  void *cbArg; /**< argument with which callback function will be called */

  void *nnliteMutex; /**< Mutex to be allocated in RTOS environment */
  void *nnliteSem; /**< Semaphore to be allocated in RTOS environment */
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
  uint32_t intrPriority; /**< NNLite and DMA Channel interrupt Priority */
} cy_kernel_config_t;


 /** \} group_nn_kernel_data_structures */

/*******************************************************************************
*                           Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_nn_kernel_functions
* \{
*/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/
#if CY_IP_MXNNLITE_VERSION ==1
/**
 *****************************************************************************
 ** \brief  A function which returns a "virtual-weights" array's size for
 ** average pooling cases
 ** \retval size of  AvgPool Kernel weights
 *****************************************************************************/
uint32_t Cy_NNLite_GetAvgPoolKernelWeightSize(void);
/**
*****************************************************************************
** \brief  return AvgPool Kernel weight pointer
** All-ones const weights array used by AvgPool
** Size is returned by Cy_NNLite_GetAvgPoolKernelWeightSize.
** These are best held in non-volatile "code" memory as the
** NNLite's bus connectivity is optimized for this.
** Held in SRAM banks will result in heavy contention
** between the weight and activation streaming engines.
**
** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
int8_t *Cy_NNLite_GetAvgPoolKernelWeightPtr(void);

/**
 *****************************************************************************
 ** \brief  A function set "virtual-weights" array's pointer and size for
 ** average pooling cases when valid pointer and size is passed, in case of
 ** NULL pointer or 0 size array's pointer will be reset to default value
 ** pointer should not be freed until AvgPool weight pointer is reset to
 ** default by calling same API with NULL pointer value or 0 size in argument
 **
 ** \param [in]  weightsArrayPtr   AvgPool Kernel weight array pointer
 **
 ** \param [in]  weightsArraySize  AvgPool Kernel weight array size

 *****************************************************************************/
cy_en_nnlite_status_t  Cy_NNLite_SetAvgPoolKernelWeightArrayPtr(
                int8_t *weightsArrayPtr, uint32_t weightsArraySize);

/**
 *****************************************************************************
 ** \brief 2D Convolution CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 ** intrplParam can be passed as NULL for default behavior of activation,
 ** to parametrize activation pass valid  intrplParam.
 ** filterData points to weights if sparsityBaseAddr is NULL otherwise weights
 ** pointer will be derived from sparsityBaseAddr and filterData will
 ** not be used.
 ** Valid scratch buffer should be passed in convParam, scratch buffer will be
 ** used for transpose operation (transpose scratch buffer and transpose DMA
 ** descriptors)for per axis convolution implementation, size of scratch buffer
 ** should be derived by calling function Cy_NNLite_ConvolutionScratchBufSize.
 ** Scratch buffer should be 4 byte aligned, and can be freed after receiving
 ** completion callback of API in case non blocking mode.
 ** For Multiscaling outData pointer should be 4 byte aligned for DMA transpose
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims       output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** \param [in]  convParam        convolution parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for output activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Convolution(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData, const void *sparsityBaseAddr,
                cy_nn_conv_params_t *convParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief Fully connected CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 ** intrplParam can be passed as NULL for default behavior
 ** of activation, to parametrize activation pass valid  intrplParam.
 ** filterData points to weights If sparsityBaseAddr is NULL, otherwise
 ** weights pointer will be derived from sparsityBaseAddr and filterData
 ** will not be used.
 ** No scratch buffer is required in CPU mode fully connected
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims       output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** \param [in]  fcParam          fully Connected parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for output activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnected(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData, const void *sparsityBaseAddr,
                cy_nn_fc_params_t *fcParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);
/**
 *****************************************************************************
 ** \brief Average pool CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 ** Valid scratch buffer should be allocated and passed in avgpoolParam and
 ** scratch buffer should be 4 byte aligned. Size of scratch buffer should be
 ** calculated using API Cy_NNLite_AvgpoolDMAScratchBufSize
 ** Scratch buffer can be freed after receiving completion callback of API.
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims       output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  avgpoolParam     average pool parameter structure pointer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Avgpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_avgpool_params_t *avgpoolParam);

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
 ** Scratch buffer should be 4 byte aligned and can be freed after receiving completion
 ** callback in case of Non blocking mode.
 ** N convolutions Descriptors and Transpose Descriptors will be Queue in DMA
 ** together. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue.Callback function from kernel config
 ** structure will be called after completion of all queued layers
 ** kernel config structure should point to valid callback function.
 ** For Multiscaling outData pointer should be 4 byte aligned for DMA transpose
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims       output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** \param [in]  convParam        convolution parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for output activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_ConvolutionDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData, const void *sparsityBaseAddr,
                cy_nn_conv_params_t *convParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

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
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims       output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  sparsityBaseAddr sparsity map base pointer
 **
 ** \param [in]  fcParam          fully Connected parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for output activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnectedDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData, const void *sparsityBaseAddr,
                cy_nn_fc_params_t *fcParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief Average pool kernel API DMA mode, API will fill DMA descriptor
 ** pointing NNLite MEMIO configuration structure.Implemented in nnlite using
 ** convolution.
 ** Valid scratch buffer should be allocated and passed in
 ** avgpoolParam. Scratch buffer should be 4 byte aligned and size of scratch buffer
 ** should be calculated using API
 ** Cy_NNLite_AvgPoolDMAScratchBufSize. Scratch buffer will be used for DMA
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
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims       output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  avgpoolParam     average pool parameter structure pointer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_AvgpoolDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims,
                const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_avgpool_params_t *avgpoolParam);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_TriggerDMAQueue will trigger DMA transfer of Queued layer
 ** starting from first queued layer, callback function will be called after
 ** completion of all the Queued layer if valid callback function is passed
 ** in kernel context, API will work in blocking mode if callback function is
 ** NULL
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_TriggerDMAQueue(void);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_GetQueuedLayerCount will return count of queued layer
 ** for DMA
 **
 ** \retval dmaQDepth number of layers in DMA Queue
 *****************************************************************************/
uint32_t Cy_NNLite_GetQueuedLayerCount(void);

/**
 *****************************************************************************
 ** \brief API will return return size of scratch buffer in bytes for Average
 ** pool kernel in CPU mode, buffer size will be equal to filter
 ** dimensions
 **
 ** \param [in]  filterDims  filter dimension
 ** \param [in]  inDims      input dimension
 ** \param [in]  outDims     output dimension
 ** \retval buffer size
 *****************************************************************************/
uint32_t Cy_NNLite_AvgpoolScratchBufSize(const cy_nn_dims_t *filterDims,
                      const cy_nn_dims_t *inDims, const cy_nn_dims_t *outDims);


/**
 *****************************************************************************
 ** \brief API will return return size of scratch buffer in bytes for Average
 ** pool kernel in DMA mode, buffer size will be equal to filter dimensions
 ** plus cy_nnlite_memio_dma_t and dma descriptors, cy_nnlite_memio_dma_t will
 ** be used as source pointer having nnlite MEMIO configuration
 **
 ** \param [in]  filterDims  filter dimension
 ** \param [in]  inDims  input dimension
 ** \param [in]  outDims  output dimension
 **
 ** \retval buffer size
 *****************************************************************************/
uint32_t Cy_NNLite_AvgpoolDMAScratchBufSize(const cy_nn_dims_t *filterDims,
                      const cy_nn_dims_t *inDims, const cy_nn_dims_t *outDims);

/**
 *****************************************************************************
 ** \brief ConvolutionScratchBufSize API will return scratch buffer size for
 ** convolution kernel CPU mode, buffer will be used for transpose function
 ** which will required scratch buffer equal to out buffer plus DMA
 ** descriptor, count of descriptors depends on size of output buffer
 ** if all scaling factor pointed by outScalingFactor are equal, transpose
 ** functionality will not be required and size return will be 0 bytes
 **
 ** \param [in]  filterDims  filter dimension
 ** \param [in]  outputDims  output dimension
 ** \param [in]  outScalingFactor scaling factor array pointer
 **
 ** \retval buffer size
 *****************************************************************************/
uint32_t Cy_NNLite_ConvolutionScratchBufSize(const cy_nn_dims_t *filterDims,
                                      const cy_nn_dims_t *outputDims,
                                      float *outScalingFactor);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_ConvolutionDMAScratchBufSize API will return scratch
 ** buffer size for convolution kernel DMA mode, buffer will be used for
 ** cy_nnlite_memio_dma_t * number of filters plus transpose function which
 ** will required scratch buffer equal to out buffer plus DMA descriptors,
 ** count of descriptors depends on size of output buffer
 ** if all scaling factor pointed by outScalingFactor are equal, transpose
 ** functionality will not be required, buffer size will be for only for DMA
 ** operation
 **
 ** \param [in]  filterDims  filter dimension
 ** \param [in]  outputDims  output dimension
 ** \param [in]  outScalingFactor scaling factor array pointer
 **
 ** \retval buffer size
 *****************************************************************************/
uint32_t
Cy_NNLite_ConvolutionDMAScratchBufSize(const cy_nn_dims_t *filterDims,
                                       const cy_nn_dims_t *outputDims,
                                       float *outScalingFactor);

/**
 *****************************************************************************
 ** \brief API will return scratch buffer size for fully connected DMA mode
 ** kernel, buffer will be used for DMA descriptors and for MEMIO
 ** configuration structure of type cy_nnlite_memio_dma_t for DMA
 **
 ** \retval buffer size
 *****************************************************************************/
uint32_t Cy_NNLite_FullyConnectedDMAScratchBufSize(void);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_GetCurrDMAQueue API will copy current dma queue in to
 ** dmaQueue pointer, valid dmaQueue pointer should be passed.
 ** To get the runnable queue Cy_NNLite_GetCurrDMAQueue should be
 ** called after the created in Kernel DMA API such as Cy_NNLite_AvgpoolDMA
 ** and get executed by calling Cy_NNLite_TriggerDMAQueue
 **
 ** \param [in] dmaQueue dma queue pointer in which dma queue will be copied
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
 cy_en_nnlite_status_t
 Cy_NNLite_GetCurrDMAQueue(cy_nnlite_dma_queue_config_t *dmaQueue);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_RunDMAQueue API will Trigger DMA dmaQueue queue
 ** valid dmaQueue pointer should be passed, DMA queue should return
 ** from Cy_NNLite_GetCurrDMAQueue
 ** queue will be in  runnable state if Cy_NNLite_GetCurrDMAQueue
 ** called after queue created in Kernel DMA API such as Cy_NNLite_AvgpoolDMA
 ** and get executed by calling Cy_NNLite_TriggerDMAQueue.
 ** API will work in blocking mode if callback function is passed as NULL
 ** in kernel context
 **
 ** \param [in] dmaQueue dma queue pointer in which dma queue will be copied
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
 cy_en_nnlite_status_t
 Cy_NNLite_RunDMAQueue(cy_nnlite_dma_queue_config_t *dmaQueue);

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
 ** \param [in]  kernelConfig  kernel configuration structure
 **
 ** \retval cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_KernelInit(cy_kernel_config_t *kernelConfig);

 /**
 *****************************************************************************
 ** \brief  Kernel Deinit API, de-initialize PDL driver and synchronization
 ** primitives. needs re initialization after this API is called. Should be
 ** called only at end of program
 **
 ** \retval cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_KernelDeInit(void);
#else
/**
 *****************************************************************************
 ** \brief Set PWL interpolation parameters for LeakyRElU activation
 **
 ** [in]  alpha_scale    LeakyRelU  scale for alpha parameter (may fold in a rescaling factor)
 ** [in]  unit_scale    LeakyRelU  scale for unit gradient (may fold in a rescaling factor)
 ** [in]  inParam  Pointer to PWL activation struct to set for specified @c alpha
 *****************************************************************************/

void Cy_NNLite_LeakyRelUPWLActivation(float alpha_scale, float unit_scale,
                                      cy_nn_act_intrpl_param_t *leakyRelU);

/**
 *****************************************************************************
 ** \brief 2D Convolution CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** filterData points to weights if sparse weight or non sparse based base on
 ** type of packing is used
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  convParam        convolution parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for PWL @c actType output activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Convolution(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData,
                cy_nn_conv_params_t *convParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief 2D Convolution DMA mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in convParam, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** filterData points to weights if sparse weight or non sparse based base on
 ** type of packing is used
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  convParam        convolution parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for PWL @c actType output activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_ConvolutionDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData,
                cy_nn_conv_params_t *convParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief Depthwise Convolution CPU mode kernel API, API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function.
 ** depth multiplier considers as additional stacked channels rather than separate
 ** filter channel = input_channel * depth.
 **  \note sparse weight data is not supported in depth-wise convolution operation
 ** instead of normal “NHWC” special layout is used for depth-wise
 ** the layout depends on the number of weights being processed in parallel 'P'
 ** (depthMultiplier) P maximum is 4.
 **  -  Bias buffer should be always 128 bit aligned, i.e. for 8-bit activations bias buffer
 ** should be allocated in multiple of 4 32 bit words and for 16-bit activations bias buffer
 ** should be allocated in mutiple of 2 64 bit words.
 **  - layout format will be **[N/P]×H×W×P  weights for the complete P-weight “stripes” weights, followed by
 ** 1×H×W×|N|p   array of weights for a final partial stripe < P weights (empty if |N|p≠0 )
 ** P maximum is 4 (2 for 16-bit activations), activation unit first fetches all
 ** activations for the sums-of-products for the first 4 (2 for 16 bit)filters
 ** then the activations, for the next 4 (2) and so on. Below mention picture show layout for
 ** 16 bit activations
 ** \image html depthwise_kernel_memory_layout.png
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  convParam        convolution parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for PWL @c actType activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_DepthwiseConvolution(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData,
                cy_nn_conv_params_t *convParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief Depthwise DMA  mode kernel API, API will configure DMA descriptor
** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in convParam, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 ** depth multiplier considers as additional stacked channels rather than separate
 ** filter channel = input_channel * depth
 **\note sparse weight data is not supported in depth-wise convolution operation
 ** instead of normal “NHWC” special layout is used for depth-wise
 **  -  Bias buffer should be always 128 bit aligned, i.e. for 8-bit activations bias buffer should be
 ** allocated in multiple of 4 32 bit words and for 16-bit activations bias buffer should be allocated
 ** in  mutiple of for 2 64 bit words.
 ** the layout depends on the number of weights being processed in parallel 'P'
 ** (depthMultiplier) layout format will be
 ** [N/P]×H×W×P  weights for the complete P-weight “stripes” weights, followed by
 ** 1×H×W×|N|p   array of weights for a final partial stripe < P weights (empty if |N|p≠0 )
 ** P 2-dimensional channel-specific filters in parallel, each called stripe is
 ** Pmax 4 for 8 bit activations (2 for 16-bit activations).
 ** For each 2D (HW) sampling position the activation unit first fetches all activations for
 ** the sums-of-products for the first 4 (2) filters (i.e. the first stripe), then the activations,
 ** for the next 4 (2) and so on. Below mentioned picture show layout with 16 bit activations
 **
 ** \image html depthwise_kernel_memory_layout.png
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter pointer
 **
 ** \param [in]  biasData         bias pointer
 **
 ** \param [in]  convParam        convolution parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for PWL @c actType activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_DepthwiseConvolutionDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData,
                cy_nn_conv_params_t *convParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief Fully connected CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.API will work in blocking mode
 ** For case inputDims->dims[0] > 1,scratch buffer is required
 ** scratch buffer size in CPU should be calculated using Cy_NNLite_FC_ScratchBufSize API
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter data (weights or packed weights structure) pointer
 **
 ** \param [in]  biasData         bias pointer  N.b. 64-bit per value fo r16-bit activations
 **
 ** \param [in]  fcParam          fully Connected parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for PWL @c actType activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnected(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData,
                cy_nn_fc_params_t *fcParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);

/**
 *****************************************************************************
 ** \brief Fully connected DMA mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in fcParam, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize + Cy_NNLite_FC_ScratchBufSize.
 ** Cy_NNLite_FC_ScratchBufSize is required for case inputDims->dims[0] > 1
 ** CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
  **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  filterData       filter data (weights or packed weights structure) pointer
 **
 ** \param [in]  biasData         bias pointer  N.b. 64-bit per value fo r16-bit activations
 **
 ** \param [in]  fcParam          fully Connected parameter structure pointer
 **
 ** \param [in]  actType          output activation type
 **
 ** \param [in]  intrplParam      interpolation param for PWL @c actType activation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_FullyConnectedDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims, const int8_t *filterData,
                const int32_t *biasData,
                cy_nn_fc_params_t *fcParam,
                cy_en_nnlite_fused_activation_t actType,
                cy_nn_act_intrpl_param_t *intrplParam);
/**
 *****************************************************************************
 ** \brief Average pool CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  avgpoolParam     average pool parameter structure pointer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Avgpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *avgpoolParam);

/**
 *****************************************************************************
 ** \brief Average pool CPU mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in avgpoolParam, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  avgpoolParam     average pool parameter structure pointer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_AvgpoolDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *avgpoolParam);


/**
 *****************************************************************************
 ** \brief Max pool CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  poolParam     average pool parameter structure pointer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Maxpool(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam);
/**
 *****************************************************************************
 ** \brief Max pool CPU mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in poolParam, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** \param [in]  inputData        activation buffer pointer
 **
 ** \param [in]  outData         output buffer pointer
 **
 ** \param [in]  inputDims        activation dimension pointer
 **
 ** \param [in]  outputDims     output dimension pointer
 **
 ** \param [in]  filterDims       filter dimension pointer
 **
 ** \param [in]  poolParam     average pool parameter structure pointer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_MaxpoolDMA(const int8_t* inputData, int8_t* outData,
                const cy_nn_dims_t *inputDims, const cy_nn_dims_t *outputDims,
                const cy_nn_dims_t *filterDims,
                cy_nn_pool_params_t *poolParam);

/**
 *****************************************************************************
 * @brief Precomputation of NPU scaling factor settings for NPU binary operations
 *
 * @param ss          Scaling factors NPU Operation
 * @param lhs_scale   Scale factor for "left hand side" input values
 * @param rhs_scale   Scale factor for "right hand side" input values
 * @param output_scale  Scale factor for final output values.
 * @param input_size  Bitwidth of (MAC) input values.
 * @param op_type     ALU Operation
 * @param act_type    Fused action function to be applied
 * @return cy_en_nnlite_status_t  Success status (checks for unsupported ops/activations)
 */

cy_en_nnlite_status_t
Cy_NNLite_Scaling_Setup( cy_nn_scaling_t *ss,
                          float lhs_scale, float rhs_scale, float output_scale,
                          cy_en_nnlite_activation_size_t input_size,
                          cy_en_nnlite_op_t op_type,
                          cy_en_nnlite_fused_activation_t act_type);

/**
 *****************************************************************************
 ** @brief Set scaling configuration to "no scaling" (fast)
 **
 ** @param ss Point to Scaling configuration to be
 */

void
Cy_NNLite_Scaling_Q_Setup( cy_nn_scaling_t *ss);

/**
 *****************************************************************************
 ** \brief Generic binary op CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
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
 ** \param [in]  rhsOutDims     dimensions of rhs argument  and output.
 **
 ** \param [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \param [in] op_type        MAC-unit operating mode to configure
 **
 ** \param [in] act_type       Activation function to configure
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_AddSubMul(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams, cy_en_nnlite_op_t op_type,
              cy_en_nnlite_fused_activation_t act_type
              );

/**
 *****************************************************************************
 ** \brief Generic binary op CPU mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in pwParams, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
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
 ** \param [in]  rhsOutDims     dimensions of rhs argument  and output.
 **
 ** \param [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \param [in] op_type        MAC-unit operating mode to configure
 **
 ** \param [in] act_type       Activation function to configure
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_AddSubMulDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams, cy_en_nnlite_op_t op_type,
              cy_en_nnlite_fused_activation_t act_type
              );


/**
 *****************************************************************************
 ** \brief Pointwise addition operation
 **
 ** Pointwise addition CPU mode kernel API, API will configure nnlite.
 ** and then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
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
 ** \param [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \retval Refer \ref cy_en_nnlite_status_t

 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Add(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams);

/**
 *****************************************************************************
 ** \brief Pointwise addition operation
 **
 ** Pointwise addition DMA mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in pwParams, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
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
 ** \param [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \retval Refer \ref cy_en_nnlite_status_t

 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_AddDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams);

/**
 *****************************************************************************
 ** \brief Pointwise addition operation
 **
 ** Pointwise addition CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation.API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
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
 ** \param [in]  pwParams       Pointwise op params (lhs and output rescaling factors)
**
 ** \param [in]  left_from_right   Compute rhsData - lhsData rather than lhsData - rhsData
 **
 ** \retval Refer \ref cy_en_nnlite_status_t

 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Sub(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams,
              bool left_from_right);

/**
 *****************************************************************************
 ** \brief Pointwise addition operation
 **
 ** Pointwise addition DMA mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in pwParams, scratch buffer will be used for nnlite MEMIO
 ** configuration structure, size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
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
 ** \param [in]  pwParams       Pointwise op params (lhs and output rescaling factors)
**
 ** \param [in]  left_from_right   Compute rhsData - lhsData rather than lhsData - rhsData
 **
 ** \retval Refer \ref cy_en_nnlite_status_t

 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_SubDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams,
              bool left_from_right);

/**
 *****************************************************************************
 ** \brief multiplication
 **
 ** Pointwise multiplication CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
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
 ** \param [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \retval Refer \ref cy_en_nnlite_status_t

 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Mul(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams);

/**
 *****************************************************************************
 ** \brief Pointwise multiplication with simple broadcast
 **
 ** Pointwise multiplication DMA mode kernel API, API will configure DMA descriptor
 ** pointing nnlite MEMIO configuration structure. Valid scratch buffer should be
 ** passed in pwParams, scratch buffer will be used for nnlite MEMIO
 ** configuration structure,size of scratch buffer should be value return from
 ** Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** Limited broadcasting is supported.  For
 ** rhsOuputDims [D_1,..,D_m,..,D_n] and lhsDims = [1,...,Dm,..Dn]
 ** lhsData is repeated for the [D_1,...,D_(m-1)] major coordinate positions in rhsData.
 ** Internally implemented as "depthwise" summation using 1x1 kernel.
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
 ** \param [in]  pwParams      Pointwise op params (lhs and output rescaling factors)
 **
 ** \retval Refer \ref cy_en_nnlite_status_t

 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_MulDMA(const int8_t* lhsData, const int8_t *rhsData, int8_t* outData,
              const cy_nn_dims_t *lhsDims, const cy_nn_dims_t *rhsOutDims,
              const cy_nn_pwise_binary_params_t *pwParams);

/**
 *****************************************************************************
 ** \brief Unfused Activation function CPU mode kernel API, API will configure nnlite and
 ** then start nnlite operation. API will work in blocking mode
 ** if callback function in  Kernel config structure is NULL,
 ** if valid callback function is passed in Kernel config, API will be non-blocking
 ** and callback function will be called after completion of layer, caller need to
 ** wait for callback function before calling another Kernel API, else error will be
 ** for other function
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
Cy_NNLite_Activation(const int8_t *inData, int8_t* outData,
                    const cy_nn_dims_t *inoutDims,
                    const cy_nn_pwise_unary_params_t *actParams,
                    cy_en_nnlite_fused_activation_t act_type,
                    cy_nn_act_intrpl_param_t *intrplParam);


/**
 *****************************************************************************
 ** \brief Unfused Activation function DMA mode kernel API,API will configure
 ** DMA descriptor pointing nnlite MEMIO configuration structure. Valid
 ** scratch buffer should be passed in actParams, scratch buffer will be used
 ** for nnlite MEMIO configuration structure,size of scratch buffer should be
 ** value return from Cy_NNLite_ScratchBufSize.
 ** CY_NNLITE_OP_QUEUED will be the return value on success
 ** After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
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
Cy_NNLite_ActivationDMA(const int8_t *inData, int8_t* outData,
                    const cy_nn_dims_t *inoutDims,
                    const cy_nn_pwise_unary_params_t *actParams,
                    cy_en_nnlite_fused_activation_t act_type,
                    cy_nn_act_intrpl_param_t *intrplParam);


/**
 * @brief Compute composite LayerNorm operation
 *
 * @note This is a "macro" kernel requiring multiple primitive NNLite operations to compute.
 *
 * @param inputData      Input tensor data
 * @param outputData     Output tensor data (MUST be distinct from @c inData)
 * @param inputDims   Input dimension pointer
 * @param outputDims  Output dimension pointer
 * @param lnParams    LayerNorm parameter structure pointer.
 * @return cy_en_nnlite_status_t
 */

cy_en_nnlite_status_t
Cy_NNLite_LayerNorm(const int8_t *inputData, int8_t* outputData,
                    const cy_nn_dims_t *inputDims,
                    const cy_nn_dims_t *outputDims,
                    const cy_nn_layernorm_params_t *lnParams);


/**
 *****************************************************************************
 ** API will return scratch buffer size for LayerNorm kernel,
 ** buffer will be used for intermediate calculations
 **
 *****************************************************************************/
uint32_t Cy_NNLite_LayerNormScratchBufSize (const cy_nn_dims_t *inputDims,
                                            cy_en_nnlite_activation_size_t inputSize);

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
                    uint32_t count);

/**
 *****************************************************************************
 ** \brief Float reciprocal of (sums of) unsigned Q.31 values CPU mode kernel API
 **
 **
 ** Internally implemented as summing  WxC input over the minor axis to produce
 ** W outputs
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
 ** \param [in]  inoutDims         input values
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_Q31Reciprocal(const uint32_t *inData, float* outData,
                        const cy_nn_dims_t *inoutDims);


/**
 ** @brief LSTM unidirectional function with 8 bit input and output and 16 bit gate output
 ** Peephole connections, projection, clipping, combined input/forget gate and layer normalization are not supported.
 **
 ** @param[in]   scratch_buffers                 Struct containing scratch buffers
 **                                              Expected size for each scratch buffer is
 **                                              lstm_dims->num_batches * lstm_dims->num_outputs.
 ** @param[in]   input_data                      Pointer to input data
 ** @param[in]   lstm_dims                       LSTM input parameters related to dimensions
 ** @param[in]   input_to_input_weights          Input to input weights
 ** @param[in]   input_to_forget_weights         Input to forget weights
 ** @param[in]   input_to_cell_weights           Input to cell weights
 ** @param[in]   input_to_output_weights         Input to output weights
 ** @param[in]   recurrent_to_input_weights      Recurrent to input weights
 ** @param[in]   recurrent_to_forget_weights     Recurrent to forget weights
 ** @param[in]   recurrent_to_cell_weights       Recurrent to cell weights
 ** @param[in]   recurrent_to_output_weights     Recurrent to output weights
 ** @param[in]   projection_weights              Projection weights. Not used.
 ** @param[in]   lstm                            LSTM parameters. See struct declaration
 ** @param[in]   output_state                    Pointer to (recurrent) output state
 ** @param[in]   cell_state                      Pointer to cell state
 ** @param[in]   output_data                     Pointer to output state
 **
 ** @note Derived from and API consistent with CMSIS-NN cy_nn_lstm_unidirectional_s16_s8 implementation for convenience.
 **       Following assumptions are done based on LSTM functionality as supported by
 **       Keras version 2.9.0 at the time of development. As stated here,
 **       https://github.com/tensorflow/community/blob/master/rfcs/20180920-unify-rnn-interface.md
 **       Keras's LSTMCell is equivalent to TensorFlow's BasicLSTMCell,
 **       which does not support peephole, clipping or projection.
 **       Layer normalization and combined input/forget gate are not supported either.
 **
 **       1 Input to input weight can not be nullptr. Otherwise nullptr for combined input/forgat gate.
 **       2 Cell weights are not used and should be nullptr. Otherwise needed for peephole connections.
 **       3 Projection weight is not used and should be nullptr. Otherwise needed for projection.
 **
 ** @return    cy_en_nnlite_status_t Exit status (CY_NNLITE_SUCCESS for successful execution)
 **
 **
 */
cy_en_nnlite_status_t Cy_NNLite_LSTM_Int8(cy_nn_lstm_context *scratch_buffers,
                                                   const int8_t *input_data,
                                                   const cy_nn_lstm_dims *lstm_dims,
                                                   const int8_t *input_to_input_weights,
                                                   const int8_t *input_to_forget_weights,
                                                   const int8_t *input_to_cell_weights,
                                                   const int8_t *input_to_output_weights,
                                                   const int8_t *recurrent_to_input_weights,
                                                   const int8_t *recurrent_to_forget_weights,
                                                   const int8_t *recurrent_to_cell_weights,
                                                   const int8_t *recurrent_to_output_weights,
                                                   const int8_t *projection_weights,
                                                   const cy_nn_lstm_params *lstm,
                                                   int8_t *output_state,
                                                   int16_t *cell_state,
                                                   int8_t *output_data);


/**
 ** @brief Compute scratch buffer size needed to compute row-wise softmax of 2D input tensor
 **
 ** @param[in] inoutDims   Input tensors dimensions (rows, cols)
 ** @param[in] act_size    Data element size of input
 ** @return uint32_t  Size of scratch buffer required in bytes
 */
uint32_t
Cy_NNLite_SoftMax_ScratchBufSize(const cy_nn_dims_t *inoutDims,
                                 const cy_en_nnlite_activation_size_t act_size);

/**
 * @brief Compute size scratch buffer required for FC op.
 * @param inDims input dimensions of FC operation
 * @param outDims Output dimensions of FC operation
 * @return uint32_t Size of scratch buffer required
 */
uint32_t Cy_NNLite_FC_ScratchBufSize(const cy_nn_dims_t *inDims, const cy_nn_dims_t *outDims);
/**
 ** @brief Compute scratch buffer size needed for DMA mode API
 ** @return uint32_t  Size of scratch buffer required in bytes
 */
uint32_t Cy_NNLite_DMAModeScratchBufSize(void);
/**
 *****************************************************************************
 ** \brief Cy_NNLite_TriggerDMAQueue will trigger DMA transfer of Queued layer
 ** starting from first queued layer, callback function will be called after
 ** completion of all the Queued layer if valid callback function is passed
 ** in kernel context, API will work in blocking mode if callback function is
 ** NULL
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_TriggerDMAQueue(void);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_GetQueuedLayerCount will return count of queued layer
 ** for DMA
 **
 ** \retval dmaQDepth number of layers in DMA Queue
 *****************************************************************************/
uint32_t Cy_NNLite_GetQueuedLayerCount(void);


/**
 *****************************************************************************
 ** \brief Cy_NNLite_GetCurrDMAQueue API will copy current dma queue in to
 ** dmaQueue pointer, valid dmaQueue pointer should be passed.
 ** To get the runnable queue Cy_NNLite_GetCurrDMAQueue should be
 ** called after the created in Kernel DMA API such as Cy_NNLite_AvgpoolDMA
 ** and get executed by calling Cy_NNLite_TriggerDMAQueue
 **
 ** \param [in] dmaQueue dma queue pointer in which dma queue will be copied
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
 cy_en_nnlite_status_t
 Cy_NNLite_GetCurrDMAQueue(cy_nnlite_dma_queue_config_t *dmaQueue);

/**
 *****************************************************************************
 ** \brief Cy_NNLite_RunDMAQueue API will Trigger DMA dmaQueue queue
 ** valid dmaQueue pointer should be passed, DMA queue should return
 ** from Cy_NNLite_GetCurrDMAQueue
 ** queue will be in  runnable state if Cy_NNLite_GetCurrDMAQueue
 ** called after queue created in Kernel DMA API such as Cy_NNLite_AvgpoolDMA
 ** and get executed by calling Cy_NNLite_TriggerDMAQueue.
 ** API will work in blocking mode if callback function is passed as NULL
 ** in kernel context
 **
 ** \param [in] dmaQueue dma queue pointer in which dma queue will be copied
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************/
 cy_en_nnlite_status_t
 Cy_NNLite_RunDMAQueue(cy_nnlite_dma_queue_config_t *dmaQueue);
/**
 *****************************************************************************
 **
 ** @brief Compute row-wise softmax of 2D input tensor
 **
 ** @param inData
 ** @param outData
 ** @param expTempBuf
 ** @param inoutDims
 ** @param smParams
 ** @return cy_en_nnlite_status_t
 *****************************************************************************
 */
cy_en_nnlite_status_t
Cy_NNLite_SoftMax(const int8_t *inData, int8_t* outData,
                  int8_t *expTempBuf,
                    const cy_nn_dims_t *inoutDims,
                    const cy_nn_pwise_unary_params_t *smParams);


/**
 *****************************************************************************
 **
 ** @brief Compute Q1.15 complex FFT
 **
 ** NNLite implements Decimation-in-Time  Radix-2 FFT
 ** for 16 bit input buffers should be allocated for 32 bit, buffers
 ** will be used in ping-pong mode final output will be in buf0 for even stage
 ** for odd stage buf1 will have final output
 ** @note FFT length =^= Number complex input values *2 = #
 ** @param ppBuf0    Input / ping-pong buffer 0, Output (even stages/# values)
 ** @param ppBuf1    ping-pong buffer 1, Output (odd stages/# values)
 ** @param fftStages   log_2(FFT length)
 **
 ** @return cy_en_nnlite_status_t
 *****************************************************************************
 */
cy_en_nnlite_status_t
Cy_NNLite_FFT(int32_t *ppBuf0, int32_t* ppBuf1,
              unsigned int fftStages);

/**
 *****************************************************************************
 **
 ** @brief Compute Q1.15 complex FFT DMA mode API
 ** API will configure DMA descriptor pointing nnlite MEMIO configuration structure.
 ** Valid scratchBuf should be passed in pParam, scratch buffer will be used for
 ** nnlite MEMIO  configuration structure, size of scratch buffer should be value
 ** return from Cy_NNLite_ScratchBufSize. CY_NNLITE_OP_QUEUED will be the return
 ** value on success After queuing kernel, DMA needs to be triggered by calling
 ** API Cy_TriggerNNLiteDMAQueue
 **
 ** NNLite implements Decimation-in-Time  Radix-2 FFT
 **
 ** @note FFT length =^= Number complex input values *2 = #
 ** @param ppBuf0    Input / ping-pong buffer 0, Output (even stages/# values)
 ** @param ppBuf1    ping-pong buffer 1, Output (odd stages/# values)
 ** @param fftStages   log_2(FFT length)
 ** @param scratchBuf  Scratch buffer for DMA mode
 **
 ** @return cy_en_nnlite_status_t
 *****************************************************************************
 */
cy_en_nnlite_status_t
Cy_NNLite_FFTDMA(int32_t *ppBuf0, int32_t* ppBuf1,
              unsigned int fftStages, void *scratchBuf);

/**
 *****************************************************************************
 ** \brief  Kernel Init API, initialize PDL driver and setup IRQ handler,
 ** setup function pointers from kernelConfig argument. This API needs to be
 ** called before calling any other kernel API
 **
 ** \param [in]  kernelConfig  kernel configuration structure
 **
 ** \retval cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_KernelInit(cy_kernel_config_t *kernelConfig);

 /**
 *****************************************************************************
 ** \brief  Kernel Deinit API, de-initialize PDL driver and synchronization
 ** primitives. needs re initialization after this API is called. Should be
 ** called only at end of program
 **
 ** \retval cy_en_nnlite_status_t
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_KernelDeInit(void);

#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
/**
 *****************************************************************************
 ** \brief  NNLite ISR, Error or completion interrupt
 ** calls completion handlers to notify op completion to API callee
 ** or internal (for ops requiring multiple internal operations).
 **
 *****************************************************************************/
void Cy_NNLite_Isr(void);
#endif

#endif
/** \} group_nn_kernel_functions */

#ifdef __cplusplus
}
#endif
#endif

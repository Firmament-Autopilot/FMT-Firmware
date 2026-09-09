/***************************************************************************//**
* \file cy_nnlite.h
* \version 1.0
*
* \brief
* Provides NNLite accelerator pdl API declarations.
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
*******************************************************************************/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#ifndef CY_NNLITE_PDL_H
#define CY_NNLITE_PDL_H

#include "cy_device.h"
#if defined (CY_IP_MXNNLITE)

/**
* \defgroup group_nnlite             NNLITE HW Accelerator (NNLITE)
* \{
* This driver provides NNLite accelerator pdl defines and API function definitions.
*
* \defgroup group_nnlite_macros Macro
* \defgroup group_nnlite_functions Functions
* \defgroup group_nnlite_data_structures Data structures
* \defgroup group_nnlite_enums Enumerated types
*/

#if defined(__cplusplus)
extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "cy_syslib.h"


/** \addtogroup group_nnlite_macros
* \{
*/

/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

/** NNLite driver ID */
#define CY_NNLITE_ID                              CY_PDL_DRV_ID(0x48U)

#if CY_IP_MXNNLITE_VERSION==1
/** NNLite type */
#define NNLITE_Type                               MXNNLITE_1_0_Type
#elif CY_IP_MXNNLITE_VERSION==2

/** NNLite type */
#define NNLITE_Type                               MXNNLITE_2_0_Type
#else
#error CY_IP_MXNNLITE_VERSION macro unset/unrecognized setting
#endif



/** Output Scaling 1 mask */
#define NNLITE_NO_SCALING                         (0x3F800000U)

#if CY_IP_MXNNLITE_VERSION==1

/** Output value Clipping mask */
#define NNLITE_BYTE_CLIPING                       (0xFFU)


/** Error Interrupt */
#define NNLITE_INTR_ERRORS_MASK                 (MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_MEM_ERR_SPARSITY_Msk | \
                                                 MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_MEM_ERR_ACTIVATIONSTREAMER_Msk | \
                                                 MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_MEM_ERR_WEIGHTSTREAMER_Msk | \
                                                 MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_MEM_ERR_BIASSTREAMER_Msk | \
                                                 MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_MEM_ERR_OUTPUTSTREAMER_Msk)

/** Interrupt Enable mask */
#define NNLITE_INTR_ENABLE_MASK                 (MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_DONE_Msk | \
                                                 MXNNLITE_1_0_INTR_MASKED_INTR_MASKED_SATURATION_Msk | \
                                                 NNLITE_INTR_ERRORS_MASK)
/** Interrupt mask for all interrupts */
#define NNLITE_INTR_MASK                        NNLITE_INTR_ENABLE_MASK

#else
 /** Read Error Interrupt */
#define NNLITE_INTR_READ_ERRORS_MASK           (MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_MEM_ERR_SPARSITY_Msk | \
                                                 MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_MEM_ERR_ACTIVATIONSTREAMER_Msk | \
                                                 MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_MEM_ERR_WEIGHTSTREAMER_Msk | \
                                                 MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_MEM_ERR_BIASSTREAMER_Msk)
 /** Write Error Interrupt */
#define NNLITE_INTR_WRITE_ERRORS_MASK           (MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_MEM_ERR_OUTPUTSTREAMER_Msk)
 /** Error Interrupt */
#define NNLITE_INTR_ERRORS_MASK               (NNLITE_INTR_WRITE_ERRORS_MASK|NNLITE_INTR_READ_ERRORS_MASK)
/** Saturation Interrupt */
#define NNLITE_SATURATION_MASK                (MXNNLITE_2_0_INTR_INTR_ACCUMULATION_SATURATION_Msk| \
                                               MXNNLITE_2_0_INTR_INTR_INPUT_PRESCALE_SATURATION_Msk| \
                                               MXNNLITE_2_0_INTR_INTR_OUTPUT_PRESCALE_SATURATION_Msk| \
                                               MXNNLITE_2_0_INTR_INTR_OUTPUT_POSTSCALE_SATURATION_Msk \
                                               )


/**
 *
 * @brief Interrupt Enable mask
 *
 * Memory error interrupts active and hence detected as error states. Saturation ignored (but accessible
 * via context structure)
 *
 *
 * Note: Needs some API to non-default interrupt/event masking.
 *
*/
#define NNLITE_INTR_ENABLE_MASK    (MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_DONE_Msk | NNLITE_INTR_ERRORS_MASK)

/** Interrupt mask for all interrupts */
#define NNLITE_INTR_MASK           (MXNNLITE_2_0_INTR_MASKED_INTR_MASKED_DONE_Msk | NNLITE_INTR_ERRORS_MASK | NNLITE_SATURATION_MASK)


/** Fractional bits produced by tanh  interpolation */
#define NNLITE_TANH_FRAC_BITS 24u
/** Fractional bits produced by sigmoid interpolation */
#define NNLITE_SIGM_FRAC_BITS 25u
/** Fractional bits produced by 2^-x interpolation */
#define NNLITE_RECIP_POW2_FRAC_BITS 24
/** Preshift of add/sub inputs when prescaling */
#define NNLITE_ADDSUB_PRESCALE_SHIFT_BITS 8

#endif

/** \} group_nnlite_macros */


/** \addtogroup group_nnlite_enums
* \{
*/
#if CY_IP_MXNNLITE_VERSION==1

/** NNLite pdl status codes */
typedef enum
{
    CY_NNLITE_SUCCESS = 0U, /**< Status successful  */

    CY_NNLITE_OP_QUEUED = 1U, /** Operation is Pending state */

    CY_NNLITE_MEM_ERR_SPARSITY = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR |
                                            MXNNLITE_1_0_INTR_INTR_MEM_ERR_SPARSITY_Msk), /**< Mem fetch Error for Sparsity */

    CY_NNLITE_MEM_ERR_ACTIVATION_STREAMER = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR |
                                            MXNNLITE_1_0_INTR_INTR_MEM_ERR_ACTIVATIONSTREAMER_Msk),  /**< Mem fetch Error for Activation pointer */

    CY_NNLITE_MEM_ERR_WEIGHT_STREAMER = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR |
                                            MXNNLITE_1_0_INTR_INTR_MEM_ERR_WEIGHTSTREAMER_Msk), /**< Mem fetch Error for Weight pointer */

    CY_NNLITE_MEM_ERR_BIAS_STREAMER = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR |
                                            MXNNLITE_1_0_INTR_INTR_MEM_ERR_BIASSTREAMER_Msk), /**< Mem fetch Error for Bias pointer */

    CY_NNLITE_MEM_ERR_OUTPUT_STREAMER = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR |
                                            MXNNLITE_1_0_INTR_INTR_MEM_ERR_OUTPUTSTREAMER_Msk),/**< Mem Error for Output pointer */

    CY_NNLITE_SATURATION = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR |
                                            MXNNLITE_1_0_INTR_INTR_SATURATION_Msk), /**< Saturation in output */

    CY_NNLITE_BAD_PARAM = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x41U),  /**< function call with invalid parameter*/

    CY_NNLITE_BAD_STATE = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x42U), /**< Invalid state, order */

    CY_NNLITE_EXTERN_API_ERR = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x43U), /**< Error code for system (RTOS) level API failure */

} cy_en_nnlite_status_t;

#else

/** NNLite pdl status codes */
typedef enum
{
    CY_NNLITE_SUCCESS = 0U, /**< Status successful  */

    CY_NNLITE_OP_QUEUED = 1U, /** Operation is Pending state */

    /**
     * @brief Mem read Error
     * Bus error response for a value read.  I.e. and invalid address for
     * for a nn-zero weight count, sparsity map, bias, scale-factor,
     * weights or activation fetch
    */
    CY_NNLITE_MEM_READ_ERR  = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x11),

    /**
     * @brief Mem write error
     * Bus error response for a value write - output is only writer at present
     *
     */
    CY_NNLITE_MEM_WRITE_ERR = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x12),

    /**
     * @brief Arithmetic saturation events.
     *
     * Arithmetic saturation was detected during processing of the operation.
     * @note Saturation does not halt operation process - this continues to completion or an
     * error event.
     * @note Currently saturation event interrupts are masked and hence ignored by the PDL.  However
     * their presence can be detected in the @c cy_nnlite_context_t structure @c opIntrStatus
     * structure.
     *
     */
    CY_NNLITE_SATURATION_EVENT = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x13),

    CY_NNLITE_BAD_PARAM = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x41U),  /**< function call with invalid parameter*/

    CY_NNLITE_BAD_STATE = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x42U), /**< Invalid state, order */

    CY_NNLITE_EXTERN_API_ERR = (CY_NNLITE_ID | CY_PDL_STATUS_ERROR | 0x43U), /**< Error code for system (RTOS) level API failure */
} cy_en_nnlite_status_t;

#endif


#if CY_IP_MXNNLITE_VERSION==1

/** NNLite nn layer type*/
typedef enum
{
  CY_NNLITE_FC_LAYER = 0U, /**< NN FC or Dense Layer */
  CY_NNLITE_CONV_LAYER = 1U, /**< NN Convolution Layer */
  CY_NNLITE_LAST_LAYER_CODE = 1u
} cy_en_nnlite_layer_t;


/** Out Activation type, includes some implement via PDL */
typedef enum
{
  CY_NNLITE_ACTIVATION_NONE = 0U, /**< Activation type none */
  CY_NNLITE_ACTIVATION_RELU = 1U, /**< Activation type RELU */
  CY_NNLITE_ACTIVATION_LEAKY_RELU = 2U, /**< Activation type leaky RELU */
} cy_en_nnlite_fused_activation_t;
#else
/** Out Activation type, includes some implement via PDL
*   @note For ReLU use clipping mask with ACTIVATION_NONE
*   For Leaky ReLU use ACTIVATION_PWL together with interpolation params
*/
typedef enum
{
  CY_NNLITE_ACTIVATION_NONE = 0U,         /**< No function applied    - Only re-scaling */
  CY_NNLITE_ACTIVATION_SIGMOID = 1U,      /**< Sigmoid: sigma(2x)    - Q1.25 result from Q8.16 / Q8.8 input */
  CY_NNLITE_ACTIVATION_TANH = 2U,         /**< Tanh: tanh(x)          - Q1.24 from Q8.8 / Q16.8 input */
  CY_NNLITE_ACTIVATION_PWL = 3U,          /**< No function applied    - Output re-scaling left / right 0 differently (used for leaky RELU) */
  CY_NNLITE_ACTIVATION_RECIP_POW2 = 4U,   /**< 2^-x                   - positive Q31 from  non-negative Q3.8 / Q3.16 input (saturating) */
  CY_NNLITE_ACTIVATION_RECIPROCAL = 5U,   /**< 1/x                    - 32-bit IEEE754 float from positive Qx.31 input */

} cy_en_nnlite_fused_activation_t;
#endif

/** Activation size */
typedef enum
{
  CY_NNLITE_ACTIVATION_8BIT = 0U, /**< 8 bits Activation  */
  CY_NNLITE_ACTIVATION_16BIT = 1U, /**< 16 bits Activation */
} cy_en_nnlite_activation_size_t;

/** Output size */
typedef enum
{
  CY_NNLITE_OUTPUT_8BIT = 0U, /**< 8 bit Output words */
  CY_NNLITE_OUTPUT_16BIT = 1U, /**< 16 bits Output words */
  CY_NNLITE_OUTPUT_32BIT = 2U /**< 32 bits Output words */
} cy_en_nnlite_output_size_t;


/** Input re-scaling mode */
typedef enum
{
  CY_NNLITE_RESCALE_NONE = 0U, /**< No re-scaling */
  CY_NNLITE_RESCALE_WGT = 1U,  /**< Rescale Weights */
  CY_NNLITE_RESCALE_ACT = 2U   /**< Rescale Activations */
} cy_en_nnlite_input_rescaling_t;

/** Output re-scaling mode */
typedef enum
{

  CY_NNLITE_OUTSCALE_NONE = 0U,        /**< No re-scaling (hard-wired 1.0 scale factor) */
  CY_NNLITE_OUTSCALE_PER_TENSOR = 1U,  /**< Per-tensor re-scaling      */
  CY_NNLITE_OUTSCALE_PER_AXIS = 2,     /**< Per-filter re-scaling       */
  CY_NNLITE_OUTSCALE_PER_ROW = 3,     /**< Per output row re-scaling   */
} cy_en_nnlite_output_rescaling_t;


/** NNLite nn operation type*/
typedef enum
{
  CY_NNLITE_NOOP_ACT = 0U, /**< Pass-through act stream (inputs left shifted 16) */
  CY_NNLITE_MUL = 1U, /**< NN Convolution Layer, pointwise mul */
  CY_NNLITE_ADD = 2U, /**< NN Pointwise addition (inputs left shifted 16) */
  CY_NNLITE_SUB_LR = 3U, /**< NN Pointwise subtraction activation/rhs - weights/lhs (inputs left shifted 16) */
  CY_NNLITE_SUB_RL = 4U, /**< NN Pointwise subtraction weights/lhs - activation/rhs (left shifted 16) */
  CY_NNLITE_SUM_ACT = 5U, /** NN Summation act stream */
  CY_NNLITE_MIN_ACT = 6U, /** Max of act stream */
  CY_NNLITE_MAX_ACT = 7U, /** Max of act stream */
  CY_NNLITE_SUM_ACT32 = 8U /** NN Summation act stream, shift inputs to treat as single 32-bit value*/
} cy_en_nnlite_op_t;


/** NNLite nn operating mode type*/
typedef enum
{
  CY_NNLITE_DWACT_WGT = 0U,   /**< "Depthwise"-striped channel activation + weights */
  CY_NNLITE_ACT_WGT = 1U,     /**< Channel-minor activation + weights */
  CY_NNLITE_DWACT_ONLY = 2U,  /**< "Depthwise"-striped channel activation only */
  CY_NNLITE_ACT_ONLY = 3U,  /**<  Channel-minor activation only */
} cy_en_nnlite_mode_t;

/** NNLite length of weight prefetch */
typedef enum
{
  CY_NNLITE_PREFETCH_WORD_1x128  = 0U,  /**< prefetch 1x128 weights */
  CY_NNLITE_PREFETCH_WORD_2x128  = 1U,  /**< prefetch 2x128 weights */
  CY_NNLITE_PREFETCH_WORD_3x128  = 2U,  /**< prefetch 3x128 weights */
  CY_NNLITE_PREFETCH_WORD_4x128  = 3U,  /**< prefetch 4x128 weights, default value */
} cy_en_nnlite_prefetch_length_t;


/** Streamer id's */
typedef enum
{
  CY_NNLITE_ACTIVATION_STREAMER = 0U, /**< Activation Streamer ID */
  CY_NNLITE_WEIGHT_STREAMER = 1U, /**< Weight Streamer ID */
  CY_NNLITE_BIAS_STREAMER = 2U, /**< Bias Streamer ID */
  CY_NNLITE_OUT_STREAMER = 3U, /**< Output Streamer ID */
#if CY_IP_MXNNLITE_VERSION==2
  CY_NNLITE_SCALE_STREAMER = 4U,  /**< Scale-factors (per-axis/per-row) */
  CY_NNLITE_WEIGHT_COUNT_STREAMER = 5U, /**<  Non-zero weight count for sparse weights */
  CY_NNLITE_SPARSITY_MAP_STREAMER = 6U, /**<  Sparsity map for sparse weights */
#endif
} cy_en_nnlite_streamer_id_t;

/** NNLite PDL Driver State Machine*/
typedef enum
{
  CY_NNLITE_DEINIT = 0U, /**< Deinitialized State */
  CY_NNLITE_INIT = 1U, /**< Init State */
  CY_NNLITE_CONFIG_STATE = 2U, /**< Configuration State */
  CY_NNLITE_OP_STARTED = 3U, /**< NN layer Operation Started */
  CY_NNLITE_OP_DONE = 4U, /**< Last NN operation completed */
} cy_en_nnlite_state_t;

/** \} group_nnlite_enums */

/**
* \addtogroup group_nnlite_data_structures
* \{
*/

/**
 *****************************************************************************
 ** \brief nnlite context structure
 *****************************************************************************/
typedef struct cy_nnlite_context
{
  volatile cy_en_nnlite_state_t nnliteState; /**< Current state of nnlite driver */
  volatile cy_en_nnlite_status_t opStatus; /**< Status of last operation */
  volatile uint32_t opIntrStatus; /**< Raw nnlite interrupt status of last operation */
} cy_nnlite_context_t;

/**
 *****************************************************************************
 ** \brief nnlite sparsity configuration
 *****************************************************************************/
typedef struct cy_nnlite_sparsity_cfg
{
    uintptr_t nonZeroWtAddr; /**< non zero weight address */
    uintptr_t sparsityBitMapAddr; /**< sparsity bit map address */
    uintptr_t wtAddr; /**< weight address */
} cy_nnlite_sparsity_cfg_t;


#if CY_IP_MXNNLITE_VERSION==1

/**
 *****************************************************************************
 ** \brief nnlite 1.0 clipping settings (simple bitmask)
 *****************************************************************************/
typedef uint32_t cy_nnlite_clipping_t;

#else
/**
 *****************************************************************************
 ** \brief nnlite 2.0 and later clipping settings signed min/max values
 *****************************************************************************/
typedef struct cy_nnlite_clipping_s
{
  int16_t min; /**< minimum value (signed) to clip in out streamer*/
  int16_t max; /**< maximum value (signed) to clip in out streamer */
} cy_nnlite_clipping_t;

#endif

 /** \} group_nnlite_data_structures */

/*******************************************************************************
*                           Function Prototypes
*******************************************************************************/

/**
* \addtogroup group_nnlite_functions
* \{
*/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

/**
 *****************************************************************************
 ** \brief  nnlite driver init function, validate context structure and
 ** set driver to init state
 **
 ** \param [in]  nnlite     base pointer of NNLite Register  Map.
 **
 ** \param [in]  context    pointer to the driver context structure.
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Init(NNLITE_Type *nnlite, cy_nnlite_context_t *context);

/**
 *****************************************************************************
 ** \brief  nnlite driver deinit function check's for pending or ongoing
 ** operation and set driver state to deinit
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure.
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_DeInit(NNLITE_Type *nnlite,
                                        cy_nnlite_context_t *context);

/**
 *****************************************************************************
 ** \brief nnlite start operation, streamer should should be configured before
 ** calling this function, this function will write to start bit in CMD MEMIO
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure.
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_Start(NNLITE_Type *nnlite,
                                      cy_nnlite_context_t *context);

/**
 *****************************************************************************
 ** \brief  nnlite stop/abort operation, can be used to stop/abort current
 ** operation or to reset all configuration, API write abort in CMD MEMIO
 ** which will reset all the registers
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure.
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_Stop(NNLITE_Type *nnlite,
                                      cy_nnlite_context_t *context);

#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 **  Compute size of sparsity map in bytes for given number of number of weights.
 **
 **
 **  \param [in]  num_weights    Number of weights.
 ** \retval Size in bytes.
 *****************************************************************************/
static inline uint32_t Cy_NNLite_SparsityMapSize(uint32_t num_weights)
{
  /* Start is byte aligned */
  return (num_weights + 7u ) / 8u;
}


/**
 *****************************************************************************
 **  parse sparsity map, API will  parse sparsity bit map and update non
 **  zero weight pointer, sparsity bit map address and weight pointer in
 **  sparCfg, sparsity configuration structure
 **
 **  \param [in]  sparsitybaseAddr sparsity map base address
 **
 **  \param [in]  sparseBitMapLen  Size of sparsity bitmap in bytes
 **
 **  \param [in]  activationRepeats  activation streamer repeat count
 **
 **  \param [out]  sparCfg sparsity configuration
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_ParseSparsity(NNLITE_Type *nnlite, const void *sparsitybaseAddr,
    uint32_t activationRepeats, uint32_t sparseBitMapLen, cy_nnlite_sparsity_cfg_t *sparCfg);

/**
 *****************************************************************************
 **  configure sparsity from valid cy_nnlite_sparsity_cfg
 **  write non zero wt pointer and sparsity bit map MEMIO and enable sparsity
 **  in streamer mode MEMIO
 **
 ** \param [in]  nnlite base pointer of register map.
 **
 ** \param [out]  sparCfg sparsity configuration
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SparsityCfg(NNLITE_Type *nnlite, cy_nnlite_sparsity_cfg_t *sparCfg);


/**
 *****************************************************************************
 ** \brief nnlite enable sparsity in streamer mode MEMIO
 **
 ** \param [in]  nnlite base pointer of register map.
 **
 ** \param [in]  sparsityEn sparsity enable
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SparsityEnable(NNLITE_Type *nnlite, bool sparsityEn);

/**
 *****************************************************************************
 ** \brief  nnlite activation streamer configuration set, API will configure
 ** parameters for activation streamer
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure
 **
 ** \param [in]  filterWidth  filter width
 **
 ** \param [in]  filterHeight  fFilter height
 **
 ** \param [in]  activationRepeats  activation streamer repeat count (how often each "kernel footprint" needs to be fetched)
 **
 ** \param [in]  inputWidth  input activation Width
 **
 ** \param [in]  inputHeight  input activation Height
 **
 ** \param [in]  inputChannel  input activation channels
 **
 ** \param [in]  inputChannel  channel depth multiplier (depthwise convolution only)
 **
 ** \param [in]  startCol  starting column for activation
 **
 ** \param [in]  startRow  starting row for activation
 **
 ** \param [in]  padVal  padding value
 **
 ** \param [in]  padHeight  padding Height
 **
 ** \param [in]  padWidth  padding Width
 **
 ** \param [in]  strideCol  Stride column
 **
 ** \param [in]  strideRow  Stride rows
 **
 ** \param [in]  inputOffset input offset value
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
#endif

/**
 *****************************************************************************
 ** \brief  nnlite activation streamer configuration set, API will configure
 ** parameters for activation streamer
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure
 **
 ** \param [in]  filterWidth  filter width
 **
 ** \param [in]  filterHeight  fFilter height
 **
 ** \param [in]  activationRepeats  activation streamer repeat count (how often each "kernel footprint" needs to be fetched)
 **
 ** \param [in]  inputWidth  input activation Width
 **
 ** \param [in]  inputHeight  input activation Height
 **
 ** \param [in]  inputChannel  input activation channels
 **
 ** \param [in]  inputChannel  channel depth multiplier (depthwise convolution only)
 **
 ** \param [in]  padVal  padding value
 **
 ** \param [in]  padHeight  padding Height
 **
 ** \param [in]  padWidth  padding Width
 **
 ** \param [in]  strideCol  Stride column
 **
 ** \param [in]  strideRow  Stride rows
 **
 ** \param [in]  inputOffset input offset value
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_ActivationStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                        uint32_t filterWidth, uint32_t filterHeight,
                        uint32_t activationRepeats, uint32_t inputWidth,
                        uint32_t inputHeight, uint32_t inputChannel,
#if CY_IP_MXNNLITE_VERSION==1
                        uint32_t startCol, uint32_t startRow,
#endif
                        int16_t padVal, uint8_t padWidth,
                        uint8_t padHeight, uint8_t strideCol,
                        uint8_t strideRow, int32_t inputOffset);

/**
 *****************************************************************************
 ** \brief  nnlite weight streamer configuration set, API will configure offset
 ** for weight streamer and weights per neuron parameter*
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure
 **
 ** \param [in]  weightPerNeuron  weight/filter elements count per neuron
 **
 ** \param [in]  filterOffset  weight/filter elements offset value
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_WeightStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                          uint32_t weightPerNeuron, int32_t filterOffset);

#if CY_IP_MXNNLITE_VERSION !=1

/**
 *****************************************************************************
 ** \brief  nnlite out streamer configuration set, API will set clipping mask,
 **  offset, width, height  and channel for output streamer
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure
 **
 ** \param [in]  clipping    output clipping setting
 **
 ** \param [in]  outputOffset  output elements offset value
 **
 ** \param [in]  outputWidth  output width
 **
 ** \param [in]  outputHeight  output height
 **
 ** \param [in]  outputChannels  output Channels
 **
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_OutputStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                        cy_nnlite_clipping_t clipping, int32_t outputOffset,
                        uint32_t outputWidth, uint32_t outputHeight,
                        uint32_t outputChannels);


#else

/**
 *****************************************************************************
 ** \brief  nnlite out streamer configuration set, API will set clipping mask,
 **  offset, scaling factor ,width and height for output streamer
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure
 **
 ** \param [in]  clipping    output clipping setting
 **
 ** \param [in]  outputOffset  output elements offset value
 **
 ** \param [in]  outputWidth  output width
 **
 ** \param [in]  outputHeight  output height
 **
 ** \param [in]  outputScalingFactor  output scaling factor
 **
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_OutputStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                        cy_nnlite_clipping_t clipping, int32_t outputOffset,
                        uint32_t outputWidth, uint32_t outputHeight,
                        float outputScalingFactor);
/**
 *****************************************************************************
 ** \brief nnlite bias streamer enable
 **
 ** \param [in]  nnlite base pointer of register map.
 **
 ** \param [in]  biasEn bias streamer enable
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_BiasStreamerEnable(NNLITE_Type *nnlite, bool biasEn);
#endif

/**
 *****************************************************************************
 ** \brief  set nnlite streamer base address
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  strmId     streamer id
 **
 ** \param [in]  baseAddr   base address of buffer
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_StreamerBaseAddrSet(NNLITE_Type *nnlite,
                        cy_en_nnlite_streamer_id_t strmId, const void *baseAddr);


#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 ** \brief  set activation type control
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  nnLayer    NN Layer operation type
 **
 ** \param [in]  actEn      Output Activation enable
 **
 ** \param [in]  actDataSize    Activation size

 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 ** Note:  Should be set to inline as usually called with constant valued-arguments
 ** and there are is no significant checking code.
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_ActivationTypeCtrl(NNLITE_Type *nnlite,

                        cy_en_nnlite_layer_t nnLayer,
                        bool actEn,
                        cy_en_nnlite_activation_size_t actDataSize

);

#else


/**
 *****************************************************************************
 ** \brief Set NNLiteV2 pipeline configuration
 **
 ** \param [in] nnlite base pointer of NNLIte register map.
 ** \param [in] opType       ALU (Arithmetic accumulation) stage operation
 ** \param [in] fetchMode    Activation fetch mode (depthwise, tensorwise)
 ** \param [in] repeatWeights Enable weight repetition
 ** \param [in] biasEn         Enable bias
 ** \param [in] sparsityEn     Enable packed sparse weights
 ** \param [in] outputRescaling ALU stage scaling mode
 ** \param [in] inputRescaling   ALU prescaling  mode
 ** \param [in] actType        Activation stage activation function
 ** \param [in] inputSize      Activation.rhs input bit width
 ** \param [in] weightSize     Weight/lhs input bit width
 ** \param [in] outputSize     Output bit width.
 ** \return cy_en_nnlite_status_t
 **
 ** @note inline as typical most parameters are constants
 *****************************************************************************/
static inline cy_en_nnlite_status_t
Cy_NNLite_PipelineConfig(NNLITE_Type *nnlite,
                        cy_en_nnlite_op_t opType,
                        cy_en_nnlite_mode_t fetchMode,
                        bool repeatWeights,
                        bool biasEn,
                        bool sparsityEn,
                        cy_en_nnlite_output_rescaling_t outputRescaling,
                        cy_en_nnlite_input_rescaling_t inputRescaling,
                        cy_en_nnlite_fused_activation_t actType,
                        cy_en_nnlite_activation_size_t inputSize,
                        cy_en_nnlite_activation_size_t weightSize,
                        cy_en_nnlite_output_size_t outputSize
)
{
  cy_en_nnlite_status_t status;
  if ((NULL == nnlite) )
  {
    status = CY_NNLITE_BAD_PARAM;
  }
  else
  {
    nnlite->NNLAYER_CTL =
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_OPTYPE, opType) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_FETCH_MODE, fetchMode) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_REPEAT_WEIGHTS, repeatWeights) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_BIAS_EN, biasEn) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_SPARSE_EN, sparsityEn) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_SCALEFACTOR_CTL, outputRescaling) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_INPUT_RESCALE, inputRescaling) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_ACTTYPE, actType) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_INPUT_SIZE_CTL, inputSize) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_WEIGHT_SIZE_CTL, weightSize) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_OUTPUT_SIZE_CTL, outputSize) |
      _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_WPREFETCH_LEN, CY_NNLITE_PREFETCH_WORD_4x128);
    status = CY_NNLITE_SUCCESS;
  }

  return status;

}

#endif

#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 ** \brief  nnlite set Interpolation lookup table to be used along
 **  with Cy_NNLite_SetinterpolationParam. For lut 0 and lut 1 both,
 **  Cy_NNLite_SetinterpolationParam need to be set.
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  lut        lookup table
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterpolationLUTAddr(NNLITE_Type *nnlite, bool lut);


/**
 *****************************************************************************
 ** \brief  set interpolation parameter
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  slope      slope value for interpolation
 **
 ** \param [in]  intercept  Y-intercept value for calculation of interpolation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterpolationParam(NNLITE_Type *nnlite,
                                        uint16_t slope, uint16_t intercept);

#else

/**
 *****************************************************************************
 ** \brief  Set pre/post arithmetic/accumulation scaling
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  preScalingFactor Pre-scaling factor to input prior to arithmetic/accumulation operation
 **
 ** \param [in]  postScalingFactors   Post-scaling factor(s) to be applied after arithmetic/accumulation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 ** @note Scale factors are restricted IEEE754 float values.  For NNLite V2.0
 ** supported exponents [8,-24] are supported.   Mantissa is rounded to 16-bits.  Non Nan etc.
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_SetPrePostScaling(NNLITE_Type *nnlite, float preScalingFactor, const float *postScalingFactors);

/**
 *****************************************************************************
 ** \brief  set interpolation parameter
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  segment    lookup segment table  addr (0: [-inf..0], 1: [0..inf] )
 **
 ** \param [in]  gradient     slope value for interpolation (IEEE 32-bit
 ** float mantissa will be rounded to 7 bits)
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterpolationParam(NNLITE_Type *nnlite,
                                uint32_t segment,
                                float gradient);

/**
 *****************************************************************************
*
 * @brief Configure NNLite for Q1.15 complex FFT
 *
 * NNLite implements Decimation-in-Time  Radix-2 FFT
 *
 * @note FFT length =^= Number complex input values *2 = #
 * @param context   pointer to the driver context structure.
 * @param ppBuf0    Input / ping-pong buffer 0, Output (even stages/# values)
 * @param ppBuf1    ping-pong buffer 1, Output (odd stages/# values)
 * @param fftStages   log_2(FFT length)
 *
 * @return cy_en_nnlite_status_t
 *****************************************************************************
 */

cy_en_nnlite_status_t
Cy_NNLite_FFTCfg(NNLITE_Type *nnlite,
                cy_nnlite_context_t *context,
                void *ppBuf0, void *ppBuf1,
                unsigned int fftStages);

#endif
/**
 *****************************************************************************
 ** \brief  nnlite set interrupt mask, available interrupt are operation STATUS Done,
 **   MEM Fetch Error different streamers, Output Saturation interrupt
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  intrMask    nnlite interrupt mask register
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_SetInterruptMask(NNLITE_Type *nnlite,
                                                    uint32_t intrMask);
/**
 *****************************************************************************
 ** \brief  nnlite set datawire trigger control, trigger datawire for next layer
 **  when trigger is 1
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  trigEn  datawire trigger mask
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_DatawireTriggerEnable(NNLITE_Type *nnlite,
                                                          bool trigEn);

/**
 *****************************************************************************
 ** \brief  nnlite get nnlite operation status, can be used to poll operation status
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [out]  opStatus    nnlite last operation status
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_GetOperationStatus(NNLITE_Type *nnlite, uint32_t *opStatus);

/**
 *****************************************************************************
 ** \brief  get nnlite interrupt status
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [out]  intrStatus    nnlite interrupt status register
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_GetInterruptStatus(NNLITE_Type *nnlite,
                                                      uint32_t *intrStatus);

/**
 *****************************************************************************
 ** \brief  get nnlite interrupt mask
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [out] intrMask   interrupt mask value
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_GetInterruptMask(NNLITE_Type *nnlite, uint32_t *intrMask);

/**
 *****************************************************************************
 ** \brief  get nnlite driver state
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    pointer to the driver context structure
 **
 ** \param [out] nnliteState   driver current state
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_GetDriverState(NNLITE_Type *nnlite,
                                     cy_nnlite_context_t *context,
                                     cy_en_nnlite_state_t *nnliteState);

/**
 *****************************************************************************
 ** \brief  clear nnlite interrupts
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  intrMask    nnlite interrupts to be cleared
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t Cy_NNLite_InterruptClear(NNLITE_Type *nnlite,
                                                uint32_t intrMask);

/**
 *****************************************************************************
 ** \brief  nnlite ISR handler
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    nnlite context structure pointer
 **
 *****************************************************************************/
void Cy_NNLite_InterruptHandler(NNLITE_Type *nnlite,
                                  cy_nnlite_context_t *context);

/**
 *****************************************************************************
 ** \brief  wait for completion of operation in busy loop
 **
 ** \param [in]  nnlite     base pointer of NNLIte register map.
 **
 ** \param [in]  context    nnlite context structure pointer
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_WaitForCompletion(NNLITE_Type *nnlite, cy_nnlite_context_t *context);
/** \} group_nnlite_functions */
#ifdef __cplusplus
}
#endif
#endif /* CY_IP_MXNNLITE */

/** \} group_nnlite */
#endif /* CY_NNLITE_PDL_H */

/* [] END OF FILE */

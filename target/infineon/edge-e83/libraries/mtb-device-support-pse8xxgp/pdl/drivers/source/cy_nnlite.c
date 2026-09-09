/***************************************************************************//**
* \file   cy_nnlite.c
* \version 1.0
*
*
* Provides an API implementation of the nn lite accelerator driver.
*
*
*  Patched to support PDL emulation (including on 64-bit hosts)
*
********************************************************************************
* \copyright
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
#include "cy_device.h"
#if defined (CY_IP_MXNNLITE)

#include "cy_nnlite.h"

#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
#include "cy_nnlite_pdl_emu.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif


#if CY_IP_MXNNLITE_VERSION==1
#define   STATUS_REG_MASK (MXNNLITE_1_0_STATUS_BUSY_STATUS_Msk | \
       MXNNLITE_1_0_STATUS_ACTIVATIONSTREAMERDONE_Msk)

#define NNLITE_VAL2FLD(field, value) _VAL2FLD(MXNNLITE_1_0_##field, value)
 #define MXNNLITE_REGS      ((MXNNLITE_1_0_Type*) MXNNLITE_1_0_BASE)
#else
#define   STATUS_REG_MASK (MXNNLITE_2_0_STATUS_BUSY_STATUS_Msk | \
       MXNNLITE_2_0_STATUS_ACTIVATIONSTREAMERDONE_Msk)

#define NNLITE_VAL2FLD(field, value) _VAL2FLD(MXNNLITE_2_0_##field, value)
#define MXNNLITE_REGS        ((MXNNLITE_2_0_Type*) MXNNLITE_2_0_BASE)
#endif
#define NNLITE_MIN_FFT_STAGES          4u
#define NNLITE_MAX_FFT_STAGES          10u

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')       */
/*****************************************************************************/

/**
 *****************************************************************************
 ** nnlite driver init function, validate context structure and
 ** set driver to init state
 **
 ** [in]  context    pointer to the driver context structure
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Init(NNLITE_Type *nnlite, cy_nnlite_context_t *context)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if (context->nnliteState != CY_NNLITE_DEINIT)
  {
    return CY_NNLITE_BAD_STATE;
  }

  context->nnliteState = CY_NNLITE_INIT;
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 ** nnlite driver deinit function check's for pending or ongoing
 ** operation and set driver state to deinit
 **
 **
 ** [in]  nnlite    base pointer of register map.
 **
 ** [in]  context    pointer to the driver context structure
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_DeInit(NNLITE_Type *nnlite, cy_nnlite_context_t *context)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if ((context->nnliteState == CY_NNLITE_OP_STARTED) ||
      (context->nnliteState == CY_NNLITE_DEINIT))
  {
    return CY_NNLITE_BAD_STATE;
  }

  context->nnliteState = CY_NNLITE_DEINIT;
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 ** nnlite start operation, streamer should should be configured before
 ** calling this function, this function will write to start bit in CMD MEMIO
 **
 **
 ** [in]  nnlite    base pointer of register map.
 **
 ** [in]  context    pointer to the driver context structure
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Start(NNLITE_Type *nnlite, cy_nnlite_context_t *context)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  bool is_valid_state = (context->nnliteState == CY_NNLITE_CONFIG_STATE ||
                         context->nnliteState == CY_NNLITE_OP_DONE);
#if !defined(IFX_USE_MXNNLITE_STREAM_EMU)
  bool is_memio_instance = (nnlite == MXNNLITE_REGS);
  if (!is_valid_state && is_memio_instance)
#else
  if (!is_valid_state)
#endif
  {
    return CY_NNLITE_BAD_STATE;
  }

  context->opStatus = CY_NNLITE_SUCCESS;
#if !defined(IFX_USE_MXNNLITE_STREAM_EMU)
  if (nnlite == MXNNLITE_REGS)
  {
    context->nnliteState = CY_NNLITE_OP_STARTED;
  }
#endif
  nnlite->CMD = NNLITE_VAL2FLD(CMD_START_CMD, 1);

#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
  // Emulate execution on NNlite immediately,
  // includes triggering of ISR
  NNLite_Emu_Run(nnlite);
#endif
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 ** nnlite stop/abort operation, can be used to stop/abort current operation
 ** or to reset all configuration, API write abort in CMD MEMIO which will
 ** reset all the registers
 **
 ** [in]  nnlite    base pointer of register map.
 **
 ** [in]  context    pointer to the driver context structure
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_Stop(NNLITE_Type *nnlite, cy_nnlite_context_t *context)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->CMD |= NNLITE_VAL2FLD(CMD_ABORT_CMD, 1);
  context->nnliteState = CY_NNLITE_INIT;
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 ** nnlite get nnlite operation status, can be used to poll operation status
 **
 ** [in]  nnlite  base pointer of register map.
 **
 ** [out] opStatus    nnlite last operation status
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_GetOperationStatus(NNLITE_Type *nnlite, uint32_t *opStatus)
{
  if ((NULL == nnlite) || (NULL == opStatus))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  *opStatus = (nnlite->STATUS & STATUS_REG_MASK);
  return CY_NNLITE_SUCCESS;
}

#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 **   nnlite set Activation Type Control
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  nnLayer    NN Layer operation type
 **
 **   [in]  actEn    Output Activation enable
 **
 **   [in]  actDataSize    Activation size
 **
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_ActivationTypeCtrl(NNLITE_Type *nnlite,
                             cy_en_nnlite_layer_t nnLayer,
                             bool actEn,
                             cy_en_nnlite_activation_size_t actDataSize)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if (nnLayer > CY_NNLITE_LAST_LAYER_CODE)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->NNLAYER_ACTIVATION_TYPE_CTL =
    NNLITE_VAL2FLD(NNLAYER_ACTIVATION_TYPE_CTL_NNLAYER_TYPE_CTL, nnLayer) |
    NNLITE_VAL2FLD(NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_FUNC_EN, actEn) |
    NNLITE_VAL2FLD(NNLAYER_ACTIVATION_TYPE_CTL_ACTIVATION_SIZE_CTL, actDataSize);

  return CY_NNLITE_SUCCESS;
}
#endif


/**
 *****************************************************************************
 **   nnlite streamer buffer base set
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  strmId    streamer id
 **
 **   [in]  baseAddr    base address of buffer
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_StreamerBaseAddrSet(NNLITE_Type *nnlite,
                              cy_en_nnlite_streamer_id_t strmId,
                              const void *baseAddr)
{
  if ((NULL == nnlite) || (NULL == baseAddr))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  cy_en_nnlite_status_t status = CY_NNLITE_SUCCESS;
  switch(strmId)
  {
     // Agents connected via RW bus-master connected to "EXP" (aka Ahb) bus.
    case CY_NNLITE_ACTIVATION_STREAMER:
      nnlite->ACTIVATIONSTREAMERBASEADDR = (uintptr_t)cy_AhbRemapAddr(baseAddr);
      break;
    case CY_NNLITE_OUT_STREAMER:
      nnlite->OUTSTREAMERBASEADDR = (uintptr_t)cy_AhbRemapAddr(baseAddr);
      break;
    // Agents connected via (RO bus-master) connected to "CODE" bus.
    case CY_NNLITE_WEIGHT_STREAMER:
      nnlite->WEIGHTSTREAMERBASEADDR = (uintptr_t)cy_CbusRemapAddr(baseAddr);
      break;
    case CY_NNLITE_BIAS_STREAMER:
      nnlite->BIASBASEADDR = (uintptr_t)cy_CbusRemapAddr(baseAddr);
      break;
#if CY_IP_MXNNLITE_VERSION==2
    case CY_NNLITE_SCALE_STREAMER:
      nnlite->SCALINGFACTORBASEADDR = (uintptr_t)cy_CbusRemapAddr(baseAddr);
      break;
    case CY_NNLITE_WEIGHT_COUNT_STREAMER:
      nnlite->NONZEROWEIGHTSPOINTER = (uintptr_t)cy_CbusRemapAddr(baseAddr);
      break;
    case CY_NNLITE_SPARSITY_MAP_STREAMER:
      nnlite->ACTIVATIONSTREAMERSPARSITYMAPBASEADDR = (uintptr_t)cy_CbusRemapAddr(baseAddr);
      break;
#endif
    default:
      status = CY_NNLITE_BAD_PARAM;
      break;
  }

  return status;
}

#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 **   parse sparsity map, API will  parse sparsity bit map and update non
 **   zero weight pointer, sparsity bit map address and weight pointer in
 **   sparCfg, sparsity configuration structure

 **   [in]  sparsitybaseAddr sparsity map base address
 **
 **   [in]  sparseBitMapLen  Size of sparsity bitmap in bytes
 **
 **   [in]  activationRepeats  activation streamer repeat count
 **
 **   [out]  sparCfg sparsity configuration
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_ParseSparsity(NNLITE_Type *nnlite, const void *sparsitybaseAddr,
                        uint32_t activationRepeats, uint32_t sparseBitMapLen,
                        cy_nnlite_sparsity_cfg_t *sparCfg)
{
  if ((NULL == nnlite) || (NULL == sparCfg) || (NULL == sparsitybaseAddr))
  {
    return CY_NNLITE_BAD_PARAM;
  }
  /* nonzero wt pointer each of length 2 bytes */
  uint32_t nonZeroWtLen = activationRepeats * 2UL;
  sparCfg->nonZeroWtAddr = (uintptr_t)sparsitybaseAddr;
  sparCfg->sparsityBitMapAddr = (uintptr_t)sparsitybaseAddr + nonZeroWtLen;
  /* wt pointer == sparsebase + non zero wt pointer len +
   * len of sparse bit map
   * */
  sparCfg->wtAddr = (uintptr_t)sparsitybaseAddr + nonZeroWtLen + sparseBitMapLen;

  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **   configure sparsity from valid cy_nnlite_sparsity_cfg
 **   write non zero wt pointer and sparsity bit map MEMIO and enable sparsity
 **   in streamer mode MEMIO
 **
 **   [in]  nnlite base pointer of register map.
 **
 **   [in]  cy_nnlite_sparsity_cfg_t sparsity configuration
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SparsityCfg(NNLITE_Type *nnlite, cy_nnlite_sparsity_cfg_t *sparCfg)
{
  if ((NULL == nnlite) || (NULL == sparCfg))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->NONZEROWEIGHTSPOINTER = cy_CbusRemapAddr((uint32_t *)sparCfg->nonZeroWtAddr);
  nnlite->ACTIVATIONSTREAMERSPARSITYMAPBASEADDR = cy_CbusRemapAddr((uint32_t *)sparCfg->sparsityBitMapAddr);

  return CY_NNLITE_SUCCESS;
}


/**
 *****************************************************************************
 ** nnlite enable sparsity in streamer mode MEMIO
 **
 **   [in]  nnlite base pointer of register map.
 **
 **   [in] sparsityEn sparsity enable
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SparsityEnable(NNLITE_Type *nnlite, bool sparsityEn)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if (sparsityEn)
  {
    nnlite->STREAMERMODES |= NNLITE_VAL2FLD(STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1);
  }
  else
  {
    nnlite->STREAMERMODES &= ~(NNLITE_VAL2FLD(STREAMERMODES_ACTIVATIONSTREAMERSPARSEEN, 1));
  }

  return CY_NNLITE_SUCCESS;
}
#endif

#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 **   nnlite activation streamer configuration set, API will configure
 **   parameters for activation streamer
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  context     pointer to the driver context structure
 **
 **   [in]  filterWidth  filter width
 **
 **   [in]  filterHeight   filter height
 **
 **   [in]  activationRepeats  activation streamer repeat count
 **
 **   [in]  inputWidth  input activation Width
 **
 **   [in]  inputHeight  input activation Height
 **
 **   [in]  inputChannel   input activation channels
 **
 **   [in]  startCol   starting column for activation
 **
 **   [in]  startRow   starting row for activation
 **
 **   [in]  padVal  padding value
 **
 **   [in]  padHeight  padding Height
 **
 **   [in]  padWidth   padding Width
 **
 **   [in]  strideCol  Stride column
 **
 **   [in]  strideRow  Stride rows
 **
 **   [in]  inputOffset input offset value
 *****************************************************************************/
#else
/**
 *****************************************************************************
 **   nnlite activation streamer configuration set, API will configure
 **   parameters for activation streamer
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  context     pointer to the driver context structure
 **
 **   [in]  filterWidth  filter width
 **
 **   [in]  filterHeight   filter height
 **
 **   [in]  activationRepeats  activation streamer repeat count
 **
 **   [in]  inputWidth  input activation Width
 **
 **   [in]  inputHeight  input activation Height
 **
 **   [in]  inputChannel   input activation channels
 **
 **   [in]  padVal  padding value
 **
 **   [in]  padHeight  padding Height
 **
 **   [in]  padWidth   padding Width
 **
 **   [in]  strideCol  Stride column
 **
 **   [in]  strideRow  Stride rows
 **
 **   [in]  inputOffset input offset value
 *****************************************************************************/
#endif
cy_en_nnlite_status_t
Cy_NNLite_ActivationStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                                uint32_t filterWidth, uint32_t filterHeight,
                                uint32_t activationRepeats, uint32_t inputWidth,
                                uint32_t inputHeight, uint32_t inputChannel,
#if CY_IP_MXNNLITE_VERSION==1
                                uint32_t startCol, uint32_t startRow,
#endif
                                int16_t padVal, uint8_t padWidth, uint8_t padHeight,
                                uint8_t strideCol, uint8_t strideRow,
                                int32_t inputOffset)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if ((context->nnliteState != CY_NNLITE_INIT) &&
      (context->nnliteState != CY_NNLITE_OP_DONE))
  {
    return CY_NNLITE_BAD_STATE;
  }

#if CY_IP_MXNNLITE_VERSION!=1
  static const int32_t startCol = 0;
  static const int32_t startRow = 0;
#endif

  uint32_t padWidthTimesChannel = padWidth * inputChannel;
  uint32_t startColChannelTimesPadWidth = startCol - padWidthTimesChannel;
  uint32_t startRowPadHeight = startRow - padHeight;

  nnlite->ACTIVATIONSTREAMEROFFSET = (uint32_t)inputOffset;
  /* weights dims*/
  nnlite->ACTIVATIONSTREAMERKERNELCHANNELTIMESWIDTH = (filterWidth * inputChannel);
  nnlite->ACTIVATIONSTREAMERKERNELHEIGHT = filterHeight;
  /* is equal to number of filters for conv or equal to filer 2nd dimension for fc layer */
  nnlite->ACTIVATIONSTREAMERREPEATS = activationRepeats;
  /* input dims */
  nnlite->ACTIVATIONSTREAMERCHANNELTIMESWIDTH = (inputWidth * inputChannel);
  nnlite->ACTIVATIONSTREAMERHEIGHT = inputHeight;
  nnlite->ACTIVATIONSTREAMERSTARTCOL = startColChannelTimesPadWidth;
  nnlite->ACTIVATIONSTREAMERSTARTROW = startRowPadHeight;
  nnlite->ACTIVATIONSTREAMERPADDING =
    NNLITE_VAL2FLD(ACTIVATIONSTREAMERPADDING_ACTIVATIONSTREAMERPADVALUE, padVal);
  nnlite->STRIDE =
    NNLITE_VAL2FLD(STRIDE_STRIDECHANNELTIMESCOLUMN, strideCol * inputChannel) |
    NNLITE_VAL2FLD(STRIDE_STRIDEROW, strideRow);
#if CY_IP_MXNNLITE_VERSION!=1
  nnlite->ACTIVATIONSTREAMERCHANNEL = inputChannel;
#endif

  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **   nnlite weight streamer configuration set, API will configure offset
 **   for weight streamer and weights per neuron parameter
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  context    pointer to the driver context structure
 **
 **   [in]  weightPerNeuron  wight/filter elements count per neuron
 **
 **   [in]  filterOffset   wight/filter elements offset value
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_WeightStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                            uint32_t weightPerNeuron, int32_t filterOffset)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->WEIGHTSTREAMERKERNELCHANNELTIMESHEIGHTTIMESWIDTH = weightPerNeuron;
  nnlite->WEIGHTSTREAMEROFFSET = (uint32_t)filterOffset;

  return CY_NNLITE_SUCCESS;
}
#if CY_IP_MXNNLITE_VERSION==1
/**
 *****************************************************************************
 **   nnlite out streamer configuration set, API will set clipping mask,
 **   offset, scaling factor ,width and height for output streamer
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  context    pointer to the driver context structure
 **
 **   [in]  clipping     output clipping setting mask or  max/min values
 **
 **   [in]  outputOffset   output elements offset value
 **
 **   [in]  outputScalingFactor  pointer output scaling factor(s)
 **
 *****************************************************************************/
#else
/**
 *****************************************************************************
 **   nnlite out streamer configuration set, API will set clipping mask,
 **   offset, scaling factor ,width and height for output streamer
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  context    pointer to the driver context structure
 **
 **   [in]  clipping     output clipping setting mask or  max/min values
 **
 **   [in]  outputOffset   output elements offset value
 **
 **   [in]  outputChannels  output Channels
 **
 *****************************************************************************/
#endif
cy_en_nnlite_status_t
Cy_NNLite_OutputStreamerCfg(NNLITE_Type *nnlite, cy_nnlite_context_t *context,
                            cy_nnlite_clipping_t clipping, int32_t outputOffset,
                            uint32_t outputWidth, uint32_t outputHeight,
#if CY_IP_MXNNLITE_VERSION==1
                            float outputScalingFactor
#else
                            uint32_t outputChannels
#endif
                            )
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }

#if CY_IP_MXNNLITE_VERSION==1
  // Improved float handling using union instead of pointer casting
  union {
    float f_val;
    uint32_t u32_val;
  } scaling_factor_union;
  scaling_factor_union.f_val = outputScalingFactor;

  nnlite->OUTSTREAMERCLIPPINGMASK = clipping;
  nnlite->OUTSTREAMERSCALINGFACTOR = scaling_factor_union.u32_val;
#else
  nnlite->OUTSTREAMERCLIPPING =
    NNLITE_VAL2FLD(OUTSTREAMERCLIPPING_OUTSTREAMERCLIPPINGVALUEMIN, clipping.min) |
    NNLITE_VAL2FLD(OUTSTREAMERCLIPPING_OUTSTREAMERCLIPPINGVALUEMAX, clipping.max);
  nnlite->OUTPUTCHANNELS = outputChannels;
#endif
  nnlite->OUTPUTWIDTH = outputWidth;
  nnlite->OUTPUTHEIGHT = outputHeight;
  nnlite->OUTSTREAMEROUTPUTOFFSET = (uint32_t)outputOffset;

#if !defined(IFX_USE_MXNNLITE_STREAM_EMU)
  if (nnlite == MXNNLITE_REGS)
  {
    context->nnliteState = CY_NNLITE_CONFIG_STATE;
  }
#endif

  return CY_NNLITE_SUCCESS;
}

#if CY_IP_MXNNLITE_VERSION==1
// Fix Cy_NNLite_BiasStreamerEnable function - convert to early return
cy_en_nnlite_status_t
Cy_NNLite_BiasStreamerEnable(NNLITE_Type *nnlite, bool biasEn)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if (biasEn)
  {
    nnlite->STREAMERMODES |= NNLITE_VAL2FLD(STREAMERMODES_BIASEN, 1);
  }
  else
  {
    nnlite->STREAMERMODES &= ~(NNLITE_VAL2FLD(STREAMERMODES_BIASEN, 1));
  }

  return CY_NNLITE_SUCCESS;
}


/**
 *****************************************************************************
 **   nnlite set Interpolation lookup table to be used along
 **   with Cy_NNLite_SetinterpolationParam. For lut 0 and lut 1 both,
 **   Cy_NNLite_SetinterpolationParam need to be set.
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  lut      lookup table
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterpolationLUTAddr(NNLITE_Type *nnlite, bool lut)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->INTERPOLATIONLUTADDR = lut ? 1U : 0U;
  return CY_NNLITE_SUCCESS;
}


/**
 *****************************************************************************
 ** Set interpolation parameters.
 **
 ** [in]  nnlite  nnlite base pointer.
 **
 ** [in] slope    number of elements.
 **
 ** [in] intercept  intercept value.
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterpolationParam(NNLITE_Type *nnlite,
                                uint16_t slope, uint16_t intercept)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
  nnlite->INTERPOLATIONLUTWDATA[nnlite->INTERPOLATIONLUTADDR] =
    NNLITE_VAL2FLD(INTERPOLATIONLUTWDATA_INTERPOLATIONSLOPE, slope) |
    NNLITE_VAL2FLD(INTERPOLATIONLUTWDATA_INTERPOLATIONYINTERCEPT, intercept);
#else
  nnlite->INTERPOLATIONLUTWDATA =
    NNLITE_VAL2FLD(INTERPOLATIONLUTWDATA_INTERPOLATIONSLOPE, slope) |
    NNLITE_VAL2FLD(INTERPOLATIONLUTWDATA_INTERPOLATIONYINTERCEPT, intercept);
#endif

  return CY_NNLITE_SUCCESS;
}

#else

/**
 * @brief Raw bits representing IEEE754 float value
 *;
 * @param x
 * @return raw bits representation of input.
 */
static inline uint32_t Cy_NNLite_Float_Rawbits(float x) {
  union float_bits { float fval;  uint32_t rawbits; }   mush;
    mush.fval = x;
  return mush.rawbits;
}

/**
 *****************************************************************************
 ** \brief  Set pre/post arithmetic/accumulation scaling
 **
 ** \param [in]   nnlite    base pointer of NNLIte register map.
 **
 ** \param [in]   preScalingFactor Pre-scaling factor to input prior to arithmetic/accumulation operation
 **
 ** \param [in]   postScalingFactors    Post-scaling factor(s) to be applied after arithmetic/accumulation
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 ** @note Scale factors are restricted IEEE754 float values.  For NNLite V2.0
 ** supported exponents [8,-24] are supported.   Mantissa is rounded to 16-bits.  Non Nan etc.
 **
 **
 *****************************************************************************/

cy_en_nnlite_status_t
Cy_NNLite_SetPrePostScaling(NNLITE_Type *nnlite, float preScalingFactor, const float *postScalingFactors)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->SCALINGFACTORBASEADDR = (uintptr_t)cy_CbusRemapAddr((void *)postScalingFactors);
  nnlite->INPUTRESCALINGFACTOR = Cy_NNLite_Float_Rawbits(preScalingFactor);

  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 ** \brief  set interpolation parameters
 **
 ** \param [in]   nnlite    base pointer of NNLIte register map.
 **
 ** \param [in]   segment  lookup segment table  addr (0: [-inf..0], 1: [0..inf] )
 **
 ** \param [in]   gradient     slope value for interpolation (IEEE 32-bit
 ** float mantissa will be rounded to 7 bits)
 **
 **
 ** \retval Refer \ref cy_en_nnlite_status_t
 **
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterpolationParam(NNLITE_Type *nnlite,
                                uint32_t segment,
                                float gradient)
{
  if ((NULL == nnlite) || (segment > 1))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  uint32_t *lut_regs_base = (uint32_t*)&nnlite->INTERPOLATIONLUTDATA0;
  uint32_t slope_bits = Cy_NNLite_Float_Rawbits(gradient);
  lut_regs_base[segment] = slope_bits;

  return CY_NNLITE_SUCCESS;

}

/**
 *****************************************************************************
 *
 * @brief Configure NNLite for Q1.15 complex FFT
 *
 * NNLite implements Decimation-in-Time   Radix-2 FFT
 *
 * @note FFT length =^= Number complex input values *2 = #
 * @param [in]  nnlite  base pointer of NNLIte register map.
 * @param [in] context  pointer to the driver context structure.
 * @param [in] ppBuf0   Input / ping-pong buffer 0, Output (even stages/# values)
 * @param [in] ppBuf1   ping-pong buffer 1, Output (odd stages/# values)
 * @param [in] fftStages   log_2(FFT length)
 *
 * @retval Refer \ref cy_en_nnlite_status_t
 *****************************************************************************
 */

cy_en_nnlite_status_t
Cy_NNLite_FFTCfg(NNLITE_Type *nnlite,
                 cy_nnlite_context_t *context,
                 void *ppBuf0, void *ppBuf1,
                 unsigned int fftStages)
{
  if ((NULL == ppBuf0) || (NULL == ppBuf1))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  if ((fftStages < NNLITE_MIN_FFT_STAGES) || (fftStages > NNLITE_MAX_FFT_STAGES))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  cy_en_nnlite_status_t status = Cy_NNLite_StreamerBaseAddrSet(nnlite, CY_NNLITE_ACTIVATION_STREAMER, ppBuf0);
  if (status != CY_NNLITE_SUCCESS)
  {
    return status;
  }

  status = Cy_NNLite_StreamerBaseAddrSet(nnlite, CY_NNLITE_WEIGHT_STREAMER, ppBuf0);
  if (status != CY_NNLITE_SUCCESS)
  {
    return status;
  }

  status = Cy_NNLite_StreamerBaseAddrSet(nnlite, CY_NNLITE_OUT_STREAMER, ppBuf1);
  if (status != CY_NNLITE_SUCCESS)
  {
    return status;
  }

  status = Cy_NNLite_StreamerBaseAddrSet(nnlite, CY_NNLITE_BIAS_STREAMER, ppBuf1);
  if (status != CY_NNLITE_SUCCESS)
  {
    return status;
  }

  nnlite->WEIGHTSTREAMERKERNELCHANNELTIMESHEIGHTTIMESWIDTH = 1<<(1+fftStages);
  nnlite->OUTPUTWIDTH = fftStages;
  nnlite->NNLAYER_CTL =
    _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_INPUT_SIZE_CTL, CY_NNLITE_ACTIVATION_16BIT) |
    _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_WEIGHT_SIZE_CTL, CY_NNLITE_ACTIVATION_16BIT) |
    _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_OUTPUT_SIZE_CTL, CY_NNLITE_OUTPUT_32BIT) |
    _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_FETCH_MODE, CY_NNLITE_ACT_WGT) |
    _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_WPREFETCH_LEN, CY_NNLITE_PREFETCH_WORD_4x128) |
    _VAL2FLD(MXNNLITE_2_0_NNLAYER_CTL_FFT_EN, 1);

#if !defined(IFX_USE_MXNNLITE_STREAM_EMU)
  if (nnlite == MXNNLITE_REGS)
  {
    context->nnliteState = CY_NNLITE_CONFIG_STATE;
  }
#endif

  return CY_NNLITE_SUCCESS;
}
#endif

/**
 *****************************************************************************
 **   nnlite get nnlite interrupt status
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [out]  intrStatus    nnlite interrupt status register
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_GetInterruptStatus(NNLITE_Type *nnlite, uint32_t *intrStatus)
{
  if ((NULL == nnlite) || (NULL == intrStatus))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  *intrStatus = nnlite->INTR;
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **   get nnlite interrupt mask
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [out]  intrMask  nnlite interrupt mask
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_GetInterruptMask(NNLITE_Type *nnlite, uint32_t *intrMask)
{
  if ((NULL == nnlite) || (NULL == intrMask))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  *intrMask = nnlite->INTR_MASK;
  return CY_NNLITE_SUCCESS;
}

/*****************************************************************************
 **   nnlite get driver state
 **
 **   [in]  nnlite base pointer of register map.
 **
 **   [in]  context    pointer to the driver context structure
 **
 **   [out]  nnliteState nnlite driver state
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_GetDriverState(NNLITE_Type *nnlite,
                         cy_nnlite_context_t *context,
                         cy_en_nnlite_state_t *nnliteState)
{
  if ((NULL == nnlite) || (NULL == nnliteState))
  {
    return CY_NNLITE_BAD_PARAM;
  }

  *nnliteState = context->nnliteState;
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **    nnlite set datawire trigger control, trigger datawire for next layer
 **   when trigger is 1
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  trigEn  datawire trigger enable
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_DatawireTriggerEnable(NNLITE_Type *nnlite, bool trigEn)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->TRIG_MASK = (uint32_t)trigEn;
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **    nnlite set interrupt mask, available interrupt are operation STATUS Done,
 **    MEM Fetch Error different streamers, Output Saturation interrupt
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  intrMask      interrupt mask value
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_SetInterruptMask(NNLITE_Type *nnlite, uint32_t intrMask)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

  nnlite->INTR_MASK = (intrMask & NNLITE_INTR_MASK);
  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **    clear nnlite interrupts
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  intrMask     nnlite interrupts to be cleared
 *****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_InterruptClear(NNLITE_Type *nnlite, uint32_t intrMask)
{
  if (NULL == nnlite)
  {
    return CY_NNLITE_BAD_PARAM;
  }

#if defined(IFX_USE_MXNNLITE_STREAM_EMU)
  nnlite->INTR &= ~(intrMask & NNLITE_INTR_MASK);
#else
  nnlite->INTR &= (intrMask & NNLITE_INTR_MASK);
#endif

  return CY_NNLITE_SUCCESS;
}

/**
 *****************************************************************************
 **    interrupt mask to status mapping
 **
 **   [in]  intrStatus interrupt status
 *****************************************************************************/

#if CY_IP_MXNNLITE_VERSION==1
static cy_en_nnlite_status_t
Cy_NNLite_InterruptStatusToErrMap(uint32_t intrStatus)
{
  cy_en_nnlite_status_t status;
  switch(intrStatus)
  {
  case MXNNLITE_1_0_INTR_INTR_DONE_Msk:
    status = CY_NNLITE_SUCCESS;
    break;
  case MXNNLITE_1_0_INTR_INTR_MEM_ERR_SPARSITY_Msk:
    status = CY_NNLITE_MEM_ERR_SPARSITY;
    break;
  case MXNNLITE_1_0_INTR_INTR_MEM_ERR_ACTIVATIONSTREAMER_Msk:
    status = CY_NNLITE_MEM_ERR_ACTIVATION_STREAMER;
    break;
  case MXNNLITE_1_0_INTR_INTR_MEM_ERR_WEIGHTSTREAMER_Msk:
    status = CY_NNLITE_MEM_ERR_WEIGHT_STREAMER;
    break;
  case MXNNLITE_1_0_INTR_INTR_MEM_ERR_BIASSTREAMER_Msk:
    status = CY_NNLITE_MEM_ERR_BIAS_STREAMER;
    break;
  case MXNNLITE_1_0_INTR_INTR_MEM_ERR_OUTPUTSTREAMER_Msk:
    status = CY_NNLITE_MEM_ERR_OUTPUT_STREAMER;
    break;
  case MXNNLITE_1_0_INTR_INTR_SATURATION_Msk:/* fall through for saturation */
  case (MXNNLITE_1_0_INTR_INTR_DONE_Msk | MXNNLITE_1_0_INTR_INTR_SATURATION_Msk) :
    status = CY_NNLITE_SATURATION;
    break;
  default :
    status = CY_NNLITE_SUCCESS;
    break;

  }
  return status;
}
#else
static cy_en_nnlite_status_t
Cy_NNLite_InterruptStatusToErrMap(uint32_t intrStatus)
{
  cy_en_nnlite_status_t status;
  if (intrStatus & NNLITE_INTR_READ_ERRORS_MASK) {
    status = CY_NNLITE_MEM_READ_ERR;
    } else if (intrStatus & NNLITE_INTR_WRITE_ERRORS_MASK) {
    status = CY_NNLITE_MEM_WRITE_ERR;
    } else if (intrStatus & NNLITE_SATURATION_MASK) {
    status = CY_NNLITE_SATURATION_EVENT;
    } else {
    status = CY_NNLITE_SUCCESS;
  }
  return status;
}
#endif

/**
 *****************************************************************************
 ** wait for completion of operation, will wait for BUSY_STATUS to go low,
 ** in busy loop
 **
 ** [in]  nnlite    base pointer of register map.
 **
 ** [in]  context    pointer to the driver context structure
*****************************************************************************/
cy_en_nnlite_status_t
Cy_NNLite_WaitForCompletion(NNLITE_Type *nnlite,
    cy_nnlite_context_t *context)
{
  if ((NULL == nnlite) || (NULL == context))
  {
    return CY_NNLITE_BAD_PARAM;
  }
  uint32_t interruptStatus;
  cy_en_nnlite_status_t status;
  /* poll for Busy bit */
  do {
  } while (1U == (nnlite->STATUS & STATUS_REG_MASK));

  (void)Cy_NNLite_GetInterruptStatus(nnlite, &interruptStatus);
  status = Cy_NNLite_InterruptStatusToErrMap(interruptStatus);
  (void)Cy_NNLite_InterruptClear(nnlite, interruptStatus);

  if (context->nnliteState == CY_NNLITE_OP_STARTED)
  {
    context->nnliteState = CY_NNLITE_OP_DONE;
  }

  return status;
}

/**
 *****************************************************************************
 **    nnlite  ISR handler
 **
 **   [in]  nnlite    base pointer of register map.
 **
 **   [in]  context    nnlite context structure pointer
 *****************************************************************************/
void Cy_NNLite_InterruptHandler(NNLITE_Type *nnlite,
              cy_nnlite_context_t *context)
{
  uint32_t intrStatus = 0;

  (void)Cy_NNLite_GetInterruptStatus(nnlite, &intrStatus);
  if (context->nnliteState == CY_NNLITE_OP_STARTED)
  {
    context->opStatus = Cy_NNLite_InterruptStatusToErrMap(intrStatus);
    context->opIntrStatus = intrStatus;
    context->nnliteState = CY_NNLITE_OP_DONE;
  }

  (void)Cy_NNLite_InterruptClear(nnlite, intrStatus);
}


#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXNNLITE */

/* [] END OF FILE */

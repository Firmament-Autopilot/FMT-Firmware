/**
  ******************************************************************************
  * @file    py32e407_ll_dma.c
  * @author  MCU Application Team
  * @brief   DMA LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_dma.h"
#ifdef  USE_FULL_ASSERT
  #include "py32_assert.h"
#else
  #define assert_param(expr) ((void)0U)
#endif

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (DMA1)

/** @defgroup DMA_LL DMA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup DMA_LL_Private_Macros
  * @{
  */
#define IS_LL_DMA_DIRECTION(_DIRECTION_)        (((_DIRECTION_) == LL_DMA_DIRECTION_PERIPH_TO_MEMORY) || \
                                                 ((_DIRECTION_) == LL_DMA_DIRECTION_MEMORY_TO_PERIPH) || \
                                                 ((_DIRECTION_) == LL_DMA_DIRECTION_MEMORY_TO_MEMORY)  || \
                                                 ((_DIRECTION_) == LL_DMA_DIRECTION_PERIPH_TO_PERIPH))

#define IS_LL_DMA_SRC_INC_MODE(__MODE__)         (((__MODE__) == LL_DMA_SRC_ADDR_INC) || \
                                                 ((__MODE__) == LL_DMA_SRC_ADDR_DEC) || \
                                                 ((__MODE__) == LL_DMA_SRC_ADDR_FIX))
  
#define IS_LL_DMA_DST_INC_MODE(__MODE__)         (((__MODE__) == LL_DMA_DST_ADDR_INC) || \
                                                 ((__MODE__) == LL_DMA_DST_ADDR_DEC) || \
                                                 ((__MODE__) == LL_DMA_DST_ADDR_FIX))

#define IS_LL_DMA_SRC_WIDTH(__WIDTH__)           (((__WIDTH__) == LL_DMA_SRC_WIDTH_BYTE)      || \
                                                 ((__WIDTH__) == LL_DMA_SRC_WIDTH_HALFWORD)  || \
                                                 ((__WIDTH__) == LL_DMA_SRC_WIDTH_WORD))

#define IS_LL_DMA_DST_WIDTH(__WIDTH__)           (((__WIDTH__) == LL_DMA_DST_WIDTH_BYTE)      || \
                                                 ((__WIDTH__) == LL_DMA_DST_WIDTH_HALFWORD)  || \
                                                 ((__WIDTH__) == LL_DMA_DST_WIDTH_WORD))

#define IS_LL_DMA_PRIORITY(__PRIORITY__)        (((__PRIORITY__) == LL_DMA_PRIORITY_0)    || \
                                                 ((__PRIORITY__) == LL_DMA_PRIORITY_1)    || \
                                                 ((__PRIORITY__) == LL_DMA_PRIORITY_2)    || \
                                                 ((__PRIORITY__) == LL_DMA_PRIORITY_3)    || \
                                                 ((__PRIORITY__) == LL_DMA_PRIORITY_4)    || \
                                                 ((__PRIORITY__) == LL_DMA_PRIORITY_5))
                                                        
#define IS_LL_DMA_SRC_BURST_LEN(_LEN_) (((_LEN_) == LL_DMA_SRC_BURST_LEN_1) || \
                                        ((_LEN_) == LL_DMA_SRC_BURST_LEN_4) || \
                                        ((_LEN_) == LL_DMA_SRC_BURST_LEN_8) || \
                                        ((_LEN_) == LL_DMA_SRC_BURST_LEN_16) || \
                                        ((_LEN_) == LL_DMA_SRC_BURST_LEN_32) || \
                                        ((_LEN_) == LL_DMA_SRC_BURST_LEN_64) || \
                                        ((_LEN_) == LL_DMA_SRC_BURST_LEN_128))

#define IS_LL_DMA_DST_BURST_LEN(_LEN_) (((_LEN_) == LL_DMA_DST_BURST_LEN_1) || \
                                        ((_LEN_) == LL_DMA_DST_BURST_LEN_4) || \
                                        ((_LEN_) == LL_DMA_DST_BURST_LEN_8) || \
                                        ((_LEN_) == LL_DMA_DST_BURST_LEN_16) || \
                                        ((_LEN_) == LL_DMA_DST_BURST_LEN_32) || \
                                        ((_LEN_) == LL_DMA_DST_BURST_LEN_64) || \
                                        ((_LEN_) == LL_DMA_DST_BURST_LEN_128))

#define IS_LL_DMA_SRC_HS(_HS_) (((_HS_) == LL_DMA_SRC_HANDSHAKE_TYPE_HARD) || \
                                ((_HS_) == LL_DMA_SRC_HANDSHAKE_TYPE_SOFT))

#define IS_LL_DMA_DST_HS(_HS_) (((_HS_) == LL_DMA_DST_HANDSHAKE_TYPE_HARD) || \
                                ((_HS_) == LL_DMA_DST_HANDSHAKE_TYPE_SOFT))



#if defined (DMA2)
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, CHANNEL)  ((((INSTANCE) == DMA1) && \
                                                            (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_6))) || \
                                                            (((INSTANCE) == DMA2) && \
                                                            (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_6))))
#else
#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, CHANNEL)  ((((INSTANCE) == DMA1) && \
                                                            (((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_6))))
#endif


/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup DMA_LL_Exported_Functions
  * @{
  */

/** @addtogroup DMA_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize the DMA registers to their default reset values.
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DMA registers are de-initialized
  *          - ERROR: DMA registers are not de-initialized
  */
uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel)
{
  DMA_Channel_TypeDef *tmp = (DMA_Channel_TypeDef *)DMA1_Channel1;
  ErrorStatus status = SUCCESS;

  /* Check the DMA Instance DMAx and Channel parameters*/
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

  tmp = (DMA_Channel_TypeDef *)(__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel));

  /* Disable the selected DMAx_Channely */
  LL_DMA_DisableChannel(DMAx,Channel);

  /* Reset register */
  LL_DMA_WriteReg(tmp, CH_CTRLL, 0x00304801U);
  LL_DMA_WriteReg(tmp, CH_CTRLH, 0x00000002U);
  LL_DMA_WriteReg(tmp, CH_CFGL, 0x00000e10U | ((Channel - 1) << DMA_CH_CFGL_CH_PRIOR_Pos));
  LL_DMA_WriteReg(tmp, CH_CFGH, 0x00000004U);
  LL_DMA_WriteReg(tmp, SA, 0x00000000U);
  LL_DMA_WriteReg(tmp, DA, 0x00000000U);

  /* Reset interrupt */
  LL_DMA_DisableIT_TFR(DMAx,Channel);
  LL_DMA_DisableIT_BLOCK(DMAx,Channel);
  LL_DMA_DisableIT_HALFBLOCK(DMAx,Channel);
  LL_DMA_DisableIT_ERR(DMAx,Channel);
  LL_DMA_DisableIT_DSTTRAN(DMAx,Channel);
  LL_DMA_DisableIT_SRCTRAN(DMAx,Channel);
  
  if (Channel == LL_DMA_CHANNEL_1)
  {
    /* Reset Channel1 Flag */
    LL_DMA_ClearFlag_TFR1(DMAx);
    LL_DMA_ClearFlag_BLOCK1(DMAx);
    LL_DMA_ClearFlag_HALFBLOCK1(DMAx);
    LL_DMA_ClearFlag_ERR1(DMAx);
    LL_DMA_ClearFlag_DSTTRAN1(DMAx);
    LL_DMA_ClearFlag_SRCTRAN1(DMAx);
  }
  else if (Channel == LL_DMA_CHANNEL_2)
  {
    /* Reset Channel2 Flag */
    LL_DMA_ClearFlag_TFR2(DMAx);
    LL_DMA_ClearFlag_BLOCK2(DMAx);
    LL_DMA_ClearFlag_HALFBLOCK2(DMAx);
    LL_DMA_ClearFlag_ERR2(DMAx);
    LL_DMA_ClearFlag_DSTTRAN2(DMAx);
    LL_DMA_ClearFlag_SRCTRAN2(DMAx);
  }
  else if (Channel == LL_DMA_CHANNEL_3)
  {
    /* Reset Channel3 Flag */
    LL_DMA_ClearFlag_TFR3(DMAx);
    LL_DMA_ClearFlag_BLOCK3(DMAx);
    LL_DMA_ClearFlag_HALFBLOCK3(DMAx);
    LL_DMA_ClearFlag_ERR3(DMAx);
    LL_DMA_ClearFlag_DSTTRAN3(DMAx);
    LL_DMA_ClearFlag_SRCTRAN3(DMAx);
  }
  else if (Channel == LL_DMA_CHANNEL_4)
  {
    /* Reset Channel4 Flag */
    LL_DMA_ClearFlag_TFR4(DMAx);
    LL_DMA_ClearFlag_BLOCK4(DMAx);
    LL_DMA_ClearFlag_HALFBLOCK4(DMAx);
    LL_DMA_ClearFlag_ERR4(DMAx);
    LL_DMA_ClearFlag_DSTTRAN4(DMAx);
    LL_DMA_ClearFlag_SRCTRAN4(DMAx);
  }
  else if (Channel == LL_DMA_CHANNEL_5)
  {
    /* Reset Channel5 Flag */
    LL_DMA_ClearFlag_TFR5(DMAx);
    LL_DMA_ClearFlag_BLOCK5(DMAx);
    LL_DMA_ClearFlag_HALFBLOCK5(DMAx);
    LL_DMA_ClearFlag_ERR5(DMAx);
    LL_DMA_ClearFlag_DSTTRAN5(DMAx);
    LL_DMA_ClearFlag_SRCTRAN5(DMAx);
  } 
  else if (Channel == LL_DMA_CHANNEL_6)
  {
    /* Reset Channel6 Flag */
    LL_DMA_ClearFlag_TFR6(DMAx);
    LL_DMA_ClearFlag_BLOCK6(DMAx);
    LL_DMA_ClearFlag_HALFBLOCK6(DMAx);
    LL_DMA_ClearFlag_ERR6(DMAx);
    LL_DMA_ClearFlag_DSTTRAN6(DMAx);
    LL_DMA_ClearFlag_SRCTRAN6(DMAx);
  }
  else
  {
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Initialize the DMA registers according to the specified parameters in DMA_InitStruct.
  * @note   To convert DMAx_Channely Instance to DMAx Instance and Channely, use helper macros :
  *         @arg @ref __LL_DMA_GET_INSTANCE
  *         @arg @ref __LL_DMA_GET_CHANNEL
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  DMA_InitStruct pointer to a @ref LL_DMA_InitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DMA registers are initialized
  *          - ERROR: Not applicable
  */
uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct)
{
  DMA_Channel_TypeDef *ChannelInstance;
  
  ChannelInstance = ((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])));

  /* Check the DMA Instance DMAx and Channel parameters*/
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

  /* Check the DMA parameters from DMA_InitStruct */
  assert_param(IS_LL_DMA_DIRECTION(DMA_InitStruct->Direction));
  assert_param(IS_LL_DMA_SRC_INC_MODE(DMA_InitStruct->SrcIncMode));
  assert_param(IS_LL_DMA_DST_INC_MODE(DMA_InitStruct->DstIncMode));
  assert_param(IS_LL_DMA_SRC_WIDTH(DMA_InitStruct->SrcWidth));
  assert_param(IS_LL_DMA_DST_WIDTH(DMA_InitStruct->DstWidth));
  assert_param(IS_LL_DMA_PRIORITY(DMA_InitStruct->Priority));

  /*---------------------------- DMAx CCR Configuration ------------------------
   * Configure DMAx_Channely: data transfer direction,
   *                          peripheral and memory increment mode,
   *                          data size alignment and  priority level with parameters :
   * - Direction:      DMA_CH_CTRLL_TT bits
   * - SrcIncMode:     DMA_CH_CTRLL_SINC bit
   * - DstIncMode:     DMA_CH_CTRLL_DINC bit
   * - SrcWidth:       DMA_CH_CTRLL_SRC_TR_WIDTH bits
   * - DstWidth:       DMA_CH_CTRLL_DST_TR_WIDTH bits
   */
  LL_DMA_ConfigTransfer(DMAx, Channel, DMA_InitStruct->Direction | \
                        DMA_InitStruct->DstIncMode  | \
                        DMA_InitStruct->SrcIncMode  | \
                        DMA_InitStruct->SrcWidth | \
                        DMA_InitStruct->DstWidth);

  /* configuration DMA_CH_CFGL_CH_PRIOR register */
  MODIFY_REG(ChannelInstance->CH_CFGL, DMA_CH_CFGL_CH_PRIOR, DMA_InitStruct->Priority);

  /* Configure burst transaction length and handshake */
  if (DMA_InitStruct->Direction == LL_DMA_DIRECTION_PERIPH_TO_PERIPH)
  {
    /* Check the parameters */
    assert_param(IS_LL_DMA_SRC_BURST_LEN(DMA_InitStruct->SrcBurstLen));
    assert_param(IS_LL_DMA_DST_BURST_LEN(DMA_InitStruct->DstBurstLen));
    
    assert_param(IS_LL_DMA_SRC_HS(DMA_InitStruct->SrcHandshakeType));
    assert_param(IS_LL_DMA_DST_HS(DMA_InitStruct->DstHandshakeType));
    
    MODIFY_REG(ChannelInstance->CH_CTRLL, \
                 (DMA_CH_CTRLL_SRC_MSIZE | DMA_CH_CTRLL_DST_MSIZE), (DMA_InitStruct->SrcBurstLen | DMA_InitStruct->DstBurstLen));
    
    MODIFY_REG(ChannelInstance->CH_CFGL, (DMA_CH_CFGL_HS_SEL_SRC | DMA_CH_CFGL_HS_SEL_DST), \
                                      (DMA_InitStruct->SrcHandshakeType | DMA_InitStruct->DstHandshakeType));
  }
  else if (DMA_InitStruct->Direction == LL_DMA_DIRECTION_PERIPH_TO_MEMORY)
  {
    /* Check the parameters */
    assert_param(IS_LL_DMA_SRC_BURST_LEN(DMA_InitStruct->SrcBurstLen));
    
    assert_param(IS_LL_DMA_SRC_HS(DMA_InitStruct->SrcHandshakeType));
    
    MODIFY_REG(ChannelInstance->CH_CTRLL, DMA_CH_CTRLL_SRC_MSIZE, DMA_InitStruct->SrcBurstLen);
    
    MODIFY_REG(ChannelInstance->CH_CFGL, DMA_CH_CFGL_HS_SEL_SRC, DMA_InitStruct->SrcHandshakeType);
  }
  else if (DMA_InitStruct->Direction == LL_DMA_DIRECTION_MEMORY_TO_PERIPH)
  {
    /* Check the parameters */
    assert_param(IS_LL_DMA_DST_BURST_LEN(DMA_InitStruct->DstBurstLen));
    
    assert_param(IS_LL_DMA_DST_HS(DMA_InitStruct->DstHandshakeType));
    
    MODIFY_REG(ChannelInstance->CH_CTRLL, DMA_CH_CTRLL_DST_MSIZE, DMA_InitStruct->DstBurstLen);
    
    MODIFY_REG(ChannelInstance->CH_CFGL, DMA_CH_CFGL_HS_SEL_DST, DMA_InitStruct->DstHandshakeType);
  }

  LL_DMA_SetSrcAddress(DMAx, Channel, DMA_InitStruct->SrcAddress);
  LL_DMA_SetDstAddress(DMAx, Channel, DMA_InitStruct->DstAddress);

  return SUCCESS;
}

/**
  * @brief  Set each @ref LL_DMA_InitTypeDef field to default value.
  * @param  DMA_InitStruct Pointer to a @ref LL_DMA_InitTypeDef structure.
  * @retval None
  */
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct)
{
  /* Set DMA_InitStruct fields to default values */
  DMA_InitStruct->SrcAddress        = 0x00000000U;
  DMA_InitStruct->DstAddress        = 0x00000000U;
  DMA_InitStruct->Direction         = LL_DMA_DIRECTION_MEMORY_TO_MEMORY;
  DMA_InitStruct->SrcIncMode        = LL_DMA_SRC_ADDR_FIX;
  DMA_InitStruct->DstIncMode        = LL_DMA_DST_ADDR_FIX;
  DMA_InitStruct->SrcWidth          = LL_DMA_SRC_WIDTH_BYTE;
  DMA_InitStruct->DstWidth          = LL_DMA_DST_WIDTH_BYTE;
  DMA_InitStruct->SrcBurstLen       = LL_DMA_SRC_BURST_LEN_1;
  DMA_InitStruct->DstBurstLen       = LL_DMA_SRC_BURST_LEN_1;
  DMA_InitStruct->SrcHandshakeType  = LL_DMA_SRC_HANDSHAKE_TYPE_SOFT;
  DMA_InitStruct->DstHandshakeType  = LL_DMA_DST_HANDSHAKE_TYPE_SOFT;
  DMA_InitStruct->Priority          = LL_DMA_PRIORITY_0;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* DMA1 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

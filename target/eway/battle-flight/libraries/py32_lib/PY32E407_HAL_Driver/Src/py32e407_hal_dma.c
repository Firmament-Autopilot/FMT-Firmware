/**
  ******************************************************************************
  * @file    py32e407_hal_dma.c
  * @author  MCU Application Team
  * @brief   DMA HAL module driver.
  *         This file provides firmware functions to manage the following
  *         functionalities of the Direct Memory Access (DMA) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral State and errors functions
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

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx_hal.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup DMA DMA
  * @brief DMA HAL module driver
  * @{
  */

#ifdef HAL_DMA_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup DMA_Private_Define DMA Private Define
  * @{
  */
#define DMA_ABORT_TIMEOUT     2000U  /* DMA abort timeout */
/**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup DMA_Private_Functions DMA Private Functions
  * @{
  */
static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
static void DMA_BlockTransferComplete(DMA_HandleTypeDef *hdma);
/**
  * @}
  */
/* Exported functions ---------------------------------------------------------*/

/** @defgroup DMA_Exported_Functions DMA Exported Functions
  * @{
  */

/** @defgroup DMA_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief   Initialization and de-initialization functions 
  *
@verbatim
 ===============================================================================
             ##### Initialization and de-initialization functions  #####
 ===============================================================================
    [..]
    This section provides functions allowing to initialize the DMA Channel source
    and destination addresses, incrementation and data sizes, transfer direction, 
    transfer type, Channel priority value.
    [..]
    The HAL_DMA_Init() function follows the DMA configuration procedures as described in
    reference manual.  

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the DMA according to the specified
  *         parameters in the DMA_InitTypeDef and initialize the associated handle.
  * @param  hdma: Pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma)
{
  /* Check the DMA handle allocation */
  if(hdma == NULL)
  {
    return HAL_ERROR;
  }
  
  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
  assert_param(IS_DMA_DIRECTION(hdma->Init.Direction));
  assert_param(IS_DMA_SRC_WIDTH(hdma->Init.SrcWidth));
  assert_param(IS_DMA_DST_WIDTH(hdma->Init.DstWidth));
  assert_param(IS_DMA_SRC_INC(hdma->Init.SrcInc));
  assert_param(IS_DMA_DST_INC(hdma->Init.DstInc));
  assert_param(IS_DMA_MODE(hdma->Init.Mode));
  assert_param(IS_DMA_PRIORITY(hdma->Init.Priority));
  assert_param(IS_DMA_BLOCK_MAX_LEN(hdma->Init.BlockMaxLen));
  
  #if defined (DMA2)
  /* calculation of the channel index */
  if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel1))
  {
    /* DMA1 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1));
    hdma->DmaBaseAddress = DMA1;
  }
  else 
  {
    /* DMA2 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA2_Channel1) / ((uint32_t)DMA2_Channel2 - (uint32_t)DMA2_Channel1));
    hdma->DmaBaseAddress = DMA2;
  }
#else
  /* DMA1 */
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1));
  hdma->DmaBaseAddress = DMA1;
#endif /* DMA2 */
  
  /* Change DMA peripheral state */
  hdma->State = HAL_DMA_STATE_BUSY;
  
  /* configuration DMA_CH_CTRLLx register */
  MODIFY_REG(hdma->Instance->CH_CTRLL, (DMA_CH_CTRLL_TT | DMA_CH_CTRLL_SINC | DMA_CH_CTRLL_DINC | DMA_CH_CTRLL_SRC_TR_WIDTH | DMA_CH_CTRLL_DST_TR_WIDTH), \
                                       (hdma->Init.Direction | hdma->Init.SrcInc | hdma->Init.DstInc | hdma->Init.SrcWidth | hdma->Init.DstWidth));
  
  /* configuration DMA_CH_CFGLx register */
  MODIFY_REG(hdma->Instance->CH_CFGL, DMA_CH_CFGL_CH_PRIOR, hdma->Init.Priority);
  
  if (hdma->Init.Mode == DMA_CIRCULAR)
  {
    assert_param(IS_DMA_SRC_RELOAD(hdma->Init.SrcReload));
    assert_param(IS_DMA_DST_RELOAD(hdma->Init.DstReload));
    
    MODIFY_REG(hdma->Instance->CH_CFGL, (DMA_CH_CFGL_RELOAD_DST | DMA_CH_CFGL_RELOAD_SRC), \
                                      (hdma->Init.DstReload | hdma->Init.SrcReload));
  }
  
  /* Configure burst transaction length and handshake */
  if (hdma->Init.Direction == DMA_PERIPH_TO_PERIPH)
  {
    /* Check the parameters */
    assert_param(IS_DMA_SRC_BURST_LEN(hdma->Init.SrcBurstLen));
    assert_param(IS_DMA_DST_BURST_LEN(hdma->Init.DstBurstLen));
    
    assert_param(IS_DMA_SRC_HS(hdma->Init.SrcHandshakeType));
    assert_param(IS_DMA_DST_HS(hdma->Init.DstHandshakeType));
    
    MODIFY_REG(hdma->Instance->CH_CTRLL, (DMA_CH_CTRLL_SRC_MSIZE | DMA_CH_CTRLL_DST_MSIZE), (hdma->Init.SrcBurstLen | hdma->Init.DstBurstLen));
    
    MODIFY_REG(hdma->Instance->CH_CFGL, (DMA_CH_CFGL_HS_SEL_SRC | DMA_CH_CFGL_HS_SEL_DST), \
                                      (hdma->Init.SrcHandshakeType | hdma->Init.DstHandshakeType));
  }
  else if (hdma->Init.Direction == DMA_PERIPH_TO_MEMORY)
  {
    /* Check the parameters */
    assert_param(IS_DMA_SRC_BURST_LEN(hdma->Init.SrcBurstLen));
    
    assert_param(IS_DMA_SRC_HS(hdma->Init.SrcHandshakeType));
    
    MODIFY_REG(hdma->Instance->CH_CTRLL, DMA_CH_CTRLL_SRC_MSIZE, hdma->Init.SrcBurstLen);
    
    MODIFY_REG(hdma->Instance->CH_CFGL, DMA_CH_CFGL_HS_SEL_SRC, hdma->Init.SrcHandshakeType);
  }
  else if (hdma->Init.Direction == DMA_MEMORY_TO_PERIPH)
  {
    /* Check the parameters */
    assert_param(IS_DMA_DST_BURST_LEN(hdma->Init.DstBurstLen));
    
    assert_param(IS_DMA_DST_HS(hdma->Init.DstHandshakeType));
    
    MODIFY_REG(hdma->Instance->CH_CTRLL, DMA_CH_CTRLL_DST_MSIZE, hdma->Init.DstBurstLen);
    
    MODIFY_REG(hdma->Instance->CH_CFGL, DMA_CH_CFGL_HS_SEL_DST, hdma->Init.DstHandshakeType);
  }
  
  /* Initialise the error code */
  hdma->ErrorCode = HAL_DMA_ERROR_NONE;

  /* Initialize the DMA state*/
  hdma->State = HAL_DMA_STATE_READY;
  /* Allocate lock resource and initialize it */
  hdma->Lock = HAL_UNLOCKED;

  return HAL_OK;
}

/**
  * @brief  DeInitialize the DMA peripheral.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma)
{
  /* Check the DMA handle allocation */
  if(hdma == NULL)
  {
    return HAL_ERROR;
  }
  
  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
  
  #if defined (DMA2)
  /* calculation of the channel index */
  if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel1))
  {
    /* DMA1 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1));
    hdma->DmaBaseAddress = DMA1;
  }
  else 
  {
    /* DMA2 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA2_Channel1) / ((uint32_t)DMA2_Channel2 - (uint32_t)DMA2_Channel1));
    hdma->DmaBaseAddress = DMA2;
  }
#else
  /* DMA1 */
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1));
  hdma->DmaBaseAddress = DMA1;
#endif /* DMA2 */
  
  /* Disable the specified DMA Channel */
  MODIFY_REG(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << hdma->ChannelIndex), (DMA_CH_EN_CH_EN_WE_0 << hdma->ChannelIndex));
  
  /* Reset register */
  hdma->Instance->CH_CTRLL  = 0x00304801U;
  hdma->Instance->CH_CTRLH  = 0x00000002U;
  hdma->Instance->CH_CFGL   = 0x00000e10U | (hdma->ChannelIndex << DMA_CH_CFGL_CH_PRIOR_Pos);
  hdma->Instance->CH_CFGH  = 0x00000004U;
  hdma->Instance->SA        = 0x00000000U;
  hdma->Instance->DA        = 0x00000000U;
  
  MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKTFR_INT_MASK_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKSRCTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKDSTTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKERR_INT_MASK_WE_0 << hdma->ChannelIndex));

  hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARTFR       = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARBLOCK     = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARSRCTRAN   = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARDSTTRAN   = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARERR       = (DMA_CLEARERR_CLEAR_0 << hdma->ChannelIndex);
  
  MODIFY_REG(hdma->DmaBaseAddress->REQSRC, ((DMA_REQSRC_SRC_REQ_0 | DMA_REQSRC_SRC_REQ_WE_0) << hdma->ChannelIndex), \
             (DMA_REQSRC_SRC_REQ_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->REQDST, ((DMA_REQDST_DST_REQ_0 | DMA_REQDST_DST_REQ_WE_0) << hdma->ChannelIndex), \
             (DMA_REQDST_DST_REQ_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->SGLRQSRC, ((DMA_SGLRQSRC_SRC_SGLREQ_0 | DMA_SGLRQSRC_SRC_SGLREQ_WE_0) << hdma->ChannelIndex), \
             (DMA_SGLRQSRC_SRC_SGLREQ_WE_0 << hdma->ChannelIndex));
  MODIFY_REG(hdma->DmaBaseAddress->SGLRQDST, ((DMA_SGLRQDST_DST_SGLREQ_0 | DMA_SGLRQDST_DST_SGLREQ_WE_0) << hdma->ChannelIndex), \
             (DMA_SGLRQDST_DST_SGLREQ_WE_0 << hdma->ChannelIndex));
  
  /* Clean all callbacks */
  hdma->XferCpltCallback = NULL;
  hdma->XferBlockCpltCallback = NULL;
  hdma->XferHalfBlockCpltCallback = NULL;
  hdma->XferSrcTranCpltCallback = NULL;
  hdma->XferDstTranCpltCallback = NULL;
  hdma->XferErrorCallback = NULL;
  hdma->XferAbortCallback = NULL;

  /* Reset the error code */
  hdma->ErrorCode = HAL_DMA_ERROR_NONE;

  /* Reset the DMA state */
  hdma->State = HAL_DMA_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return HAL_OK;
}


/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   Input and Output operation functions
  *
@verbatim
 ===============================================================================
                      #####  IO operation functions  #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Configure the source, destination address and data length and Start DMA transfer
      (+) Configure the source, destination address and data length and
          Start DMA transfer with interrupt
      (+) Abort DMA transfer
      (+) Poll for transfer complete
      (+) Handle DMA interrupt request

@endverbatim
  * @{
  */
/**
  * @brief  Start the DMA Transfer.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @param  SrcAddress: The source memory Buffer address
  * @param  DstAddress: The destination memory Buffer address
  * @param  DataLength: The length of data to be transferred from source to destination
  * @note   In circular mode, the maximum circular transfer length does not exceed 4095.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  if(HAL_DMA_STATE_READY == hdma->State)
  {
    /* Change DMA peripheral state */
    hdma->State = HAL_DMA_STATE_BUSY;
    hdma->ErrorCode = HAL_DMA_ERROR_NONE;
            
    /* Disable the specified DMA Channel */
    MODIFY_REG(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << hdma->ChannelIndex), (DMA_CH_EN_CH_EN_WE_0 << hdma->ChannelIndex));
    
    /* Configure the source, destination address and the data length & clear flags*/
    DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);
    
    /* DMA transfer from the source is not suspended */
    CLEAR_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_CH_SUSP);
    
    /* To set the flag bit, enable interrupt */
    SET_BIT(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_WE_0 | DMA_MASKHALFBLOCK_INT_MASK_0) << hdma->ChannelIndex));
    
    SET_BIT(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_WE_0 | DMA_MASKBLOCK_INT_MASK_0) << hdma->ChannelIndex));
    SET_BIT(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_WE_0 | DMA_MASKSRCTRAN_INT_MASK_0) << hdma->ChannelIndex));
    SET_BIT(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_WE_0 | DMA_MASKDSTTRAN_INT_MASK_0) << hdma->ChannelIndex));
    SET_BIT(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_WE_0 | DMA_MASKERR_INT_MASK_0) << hdma->ChannelIndex));
    
    __HAL_DMA_ENABLE_IT(hdma);
    
    /* Enable the specified DMA */
    __HAL_DMA_ENABLE(hdma);
    
    /* Enable the specified DMA Channel */
    SET_BIT(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_WE_0 | DMA_CH_EN_CH_EN_0) << hdma->ChannelIndex));
  }
  else
  {
   /* Process Unlocked */
   __HAL_UNLOCK(hdma);  
   status = HAL_BUSY;
  }  
  return status;
}
/**
  * @brief  Start the DMA Transfer with interrupt enabled.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @param  SrcAddress: The source memory Buffer address
  * @param  DstAddress: The destination memory Buffer address
  * @param  DataLength: The length of data to be transferred from source to destination
  * @note   In circular mode, the maximum circular transfer length does not exceed 4095.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);
  
  if(HAL_DMA_STATE_READY == hdma->State)
  {
    /* Change DMA peripheral state */
    hdma->State = HAL_DMA_STATE_BUSY;
    hdma->ErrorCode = HAL_DMA_ERROR_NONE;
    
    /* Disable the specified DMA Channel */
    MODIFY_REG(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << hdma->ChannelIndex), (DMA_CH_EN_CH_EN_WE_0 << hdma->ChannelIndex));
    
    /* Configure the source, destination address and the data length & clear flags*/
    DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);
    
    /* DMA transfer from the source is not suspended */
    CLEAR_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_CH_SUSP);
    
    /* Enable the interrupt */
    if(NULL != hdma->XferHalfBlockCpltCallback)
    {
      /* Enable the Half transfer complete interrupt as well */
      SET_BIT(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_WE_0 | DMA_MASKHALFBLOCK_INT_MASK_0) << hdma->ChannelIndex));
      
      SET_BIT(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_WE_0 | DMA_MASKBLOCK_INT_MASK_0) << hdma->ChannelIndex));
      SET_BIT(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_WE_0 | DMA_MASKSRCTRAN_INT_MASK_0) << hdma->ChannelIndex));
      SET_BIT(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_WE_0 | DMA_MASKDSTTRAN_INT_MASK_0) << hdma->ChannelIndex));
      SET_BIT(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_WE_0 | DMA_MASKERR_INT_MASK_0) << hdma->ChannelIndex));
    }
    else
    {
      MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
      
      SET_BIT(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_WE_0 | DMA_MASKBLOCK_INT_MASK_0) << hdma->ChannelIndex));
      SET_BIT(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_WE_0 | DMA_MASKSRCTRAN_INT_MASK_0) << hdma->ChannelIndex));
      SET_BIT(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_WE_0 | DMA_MASKDSTTRAN_INT_MASK_0) << hdma->ChannelIndex));
      SET_BIT(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_WE_0 | DMA_MASKERR_INT_MASK_0) << hdma->ChannelIndex));
    }
    
    __HAL_DMA_ENABLE_IT(hdma);
    
    /* Enable the specified DMA */
    __HAL_DMA_ENABLE(hdma);
    
    /* Enable the specified DMA Channel */
    SET_BIT(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_WE_0 | DMA_CH_EN_CH_EN_0) << hdma->ChannelIndex));
  }
  else
  {      
    /* Process Unlocked */
    __HAL_UNLOCK(hdma); 

    /* Remain BUSY */
    status = HAL_BUSY;
  }    
  return status;
}

/**
  * @brief  Abort the DMA Transfer.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma)
{
  uint32_t tickstart;
  HAL_StatusTypeDef status = HAL_OK;
  
  if(hdma->State != HAL_DMA_STATE_BUSY)
  {
    /* no transfer ongoing */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
    
    /* Process Unlocked */
    __HAL_UNLOCK(hdma);
    
    return HAL_ERROR;
  }
  else
  {
    /* DMA transfer from the source is suspended */
    SET_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_CH_SUSP);
    
    tickstart = HAL_GetTick();
    
    /* Wait for FIFO to empty */
    while(READ_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_FIFO_EMPTY) == RESET)
    {
      /* Timeout management */
      if ((HAL_GetTick() - tickstart) >=  DMA_ABORT_TIMEOUT)
      {
        return HAL_ERROR;
      }
    }
    
    /* Disable DMA IT */
    MODIFY_REG(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKTFR_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKSRCTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKDSTTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKERR_INT_MASK_WE_0 << hdma->ChannelIndex));
    
    __HAL_DMA_DISABLE_IT(hdma);
      
    /* Disable the channel */
    MODIFY_REG(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << hdma->ChannelIndex), \
               (DMA_CH_EN_CH_EN_WE_0 << hdma->ChannelIndex));
      
    /* Clear all flags */
    hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARSRCTRAN = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARDSTTRAN = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARERR = (DMA_CLEARERR_CLEAR_0 << hdma->ChannelIndex);
  }
  /* Change the DMA state */
  hdma->State = HAL_DMA_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hdma);      
  
  return status; 
}

/**
  * @brief  Aborts the DMA Transfer in Interrupt mode.
  * @param  hdma  : pointer to a DMA_HandleTypeDef structure that contains
  *                 the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma)
{
  uint32_t tickstart;
  HAL_StatusTypeDef status = HAL_OK;
  
  if(HAL_DMA_STATE_BUSY != hdma->State)
  {
    /* no transfer ongoing */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
        
    status = HAL_ERROR;
  }
  else
  { 
    /* DMA transfer from the source is suspended */
    SET_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_CH_SUSP);
    
    tickstart = HAL_GetTick();
    
    /* Wait for FIFO to empty */
    while(READ_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_FIFO_EMPTY) == RESET)
    {
      /* Timeout management */
      if ((HAL_GetTick() - tickstart) >=  DMA_ABORT_TIMEOUT)
      {
        return HAL_ERROR;
      }
    }
    
    /* Disable DMA IT */
    MODIFY_REG(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKTFR_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKSRCTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKDSTTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKERR_INT_MASK_WE_0 << hdma->ChannelIndex));
    
    __HAL_DMA_DISABLE_IT(hdma);

    /* Disable the channel */
    MODIFY_REG(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << hdma->ChannelIndex), \
               (DMA_CH_EN_CH_EN_WE_0 << hdma->ChannelIndex));

    /* Clear all flags */
    hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARSRCTRAN = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARDSTTRAN = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARERR = (DMA_CLEARERR_CLEAR_0 << hdma->ChannelIndex);

    /* Change the DMA state */
    hdma->State = HAL_DMA_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    /* Call User Abort callback */
    if(hdma->XferAbortCallback != NULL)
    {
      hdma->XferAbortCallback(hdma);
    } 
  }
  return status;
}

/**
  * @brief  Polling for transfer complete.
  * @param  hdma:    pointer to a DMA_HandleTypeDef structure that contains
  *                  the configuration information for the specified DMA Channel.
  * @param  CompleteLevel: Specifies the DMA level complete.
  * @param  Timeout:       Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout)
{
  __IO uint32_t *statusReg = NULL;
  uint32_t temp = 0;
  uint32_t tickstart = 0U;

  if(HAL_DMA_STATE_BUSY != hdma->State)
  {
    /* no transfer ongoing */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
    __HAL_UNLOCK(hdma);
    return HAL_ERROR;
  }
  
  /* Polling mode not supported in circular mode */
  if (hdma->Init.Mode == DMA_CIRCULAR)
  {
    hdma->ErrorCode = HAL_DMA_ERROR_NOT_SUPPORTED;
    return HAL_ERROR;
  }

  /* Get the level transfer complete flag */
  if(CompleteLevel == HAL_DMA_FULL_TRANSFER)
  {
    statusReg = &(hdma->DmaBaseAddress->STATUSTFR);
    
    /* Transfer Complete flag */
    temp = (DMA_STATUSTFR_STATUS_0 << hdma->ChannelIndex);
  }
  else
  {
    statusReg = &(hdma->DmaBaseAddress->STATUSHALFBLOCK);
    
    /* Half block Transfer Complete flag */
    temp = (DMA_STATUSHALFBLOCK_STATUS_0 << hdma->ChannelIndex);
  }
  
  /* Get tick */
  tickstart = HAL_GetTick();
  
  while(((*statusReg) & temp) == RESET)
  {
    if(CompleteLevel == HAL_DMA_FULL_TRANSFER)
    {
      if ((hdma->DmaBaseAddress->STATUSBLOCK & (DMA_STATUSBLOCK_STATUS_0 << hdma->ChannelIndex)) != RESET)
      {
        /* Block transfer completion processing*/
        DMA_BlockTransferComplete(hdma);
      }
    }
    
    if ((hdma->DmaBaseAddress->STATUSERR & (DMA_STATUSERR_STATUS_0 << hdma->ChannelIndex)) != RESET)
    {
      /* When a DMA transfer error occurs */
      /* A hardware clear of its CH_EN bits is performed */
      /* Clear all flags */
      hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
      hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
      hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
      hdma->DmaBaseAddress->CLEARSRCTRAN = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
      hdma->DmaBaseAddress->CLEARDSTTRAN = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
      hdma->DmaBaseAddress->CLEARERR = (DMA_CLEARERR_CLEAR_0 << hdma->ChannelIndex);
      
      /* Update error code */
      SET_BIT(hdma->ErrorCode, HAL_DMA_ERROR_TE);

      /* Change the DMA state */
      hdma->State= HAL_DMA_STATE_READY;

      /* Process Unlocked */
      __HAL_UNLOCK(hdma);

      return HAL_ERROR;
    }
    
    /* Check for the Timeout */
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
      {
        /* Update error code */
        SET_BIT(hdma->ErrorCode, HAL_DMA_ERROR_TIMEOUT);

        /* Change the DMA state */
        hdma->State = HAL_DMA_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(hdma);

        return HAL_ERROR;
      }
    }
  }
  
  if(CompleteLevel == HAL_DMA_FULL_TRANSFER)
  {
    /* To do not set the flag bit, disable interrupt */
    MODIFY_REG(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKTFR_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKSRCTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKDSTTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKERR_INT_MASK_WE_0 << hdma->ChannelIndex));
    
    __HAL_DMA_DISABLE_IT(hdma);
    
    /* Clear the transfer complete flag */
    hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);

    /* The selected Channelx CH_EN bit is cleared (DMA is disabled and
    all transfers are complete) */
    hdma->State = HAL_DMA_STATE_READY;
  }
  else
  {
    /* Clear the half block transfer complete flag */
    hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hdma);

  return HAL_OK;
}

/**
  * @brief  Handles DMA interrupt request.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.  
  * @retval None
  */
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma)
{
  /* Source transaction completion interrupt management ******************************/
  if (((hdma->DmaBaseAddress->STATUSSRCTRAN & (DMA_STATUSSRCTRAN_STATUS_0 << hdma->ChannelIndex)) != RESET) && \
      ((hdma->DmaBaseAddress->MASKSRCTRAN & (DMA_MASKSRCTRAN_INT_MASK_0 << hdma->ChannelIndex)) != RESET))
  {
    /* Clear source transaction completion interrupt flag */
    hdma->DmaBaseAddress->CLEARSRCTRAN = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
    
    if (hdma->XferSrcTranCpltCallback != NULL)
    {
      /* DMA source transaction complete callback */
      hdma->XferSrcTranCpltCallback(hdma);
    }
  }
  /* Destination transaction completion interrupt management ******************************/
  else if (((hdma->DmaBaseAddress->STATUSDSTTRAN & (DMA_STATUSDSTTRAN_STATUS_0 << hdma->ChannelIndex)) != RESET) && \
      ((hdma->DmaBaseAddress->MASKDSTTRAN & (DMA_MASKDSTTRAN_INT_MASK_0 << hdma->ChannelIndex)) != RESET))
  {
    /* Clear Destination transaction completion interrupt flag */
    hdma->DmaBaseAddress->CLEARDSTTRAN = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
    
    if (hdma->XferDstTranCpltCallback != NULL)
    {
      /* DMA  destination  transaction complete callback */
      hdma->XferDstTranCpltCallback(hdma);
    }
  }
  /* Half-block transfer completion interrupt management ******************************/
  else if (((hdma->DmaBaseAddress->STATUSHALFBLOCK & (DMA_STATUSHALFBLOCK_STATUS_0 << hdma->ChannelIndex)) != RESET) && \
      ((hdma->DmaBaseAddress->MASKHALFBLOCK & (DMA_MASKHALFBLOCK_INT_MASK_0 << hdma->ChannelIndex)) != RESET))
  {
    /* Clear Half-block transfer completion interrupt flag */
    hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
    
    if (hdma->XferHalfBlockCpltCallback != NULL)
    {
      /* DMA half block transfer complete callback */
      hdma->XferHalfBlockCpltCallback(hdma);
    }
  }
  /* Block transfer completion interrupt management ******************************/
  else if (((hdma->DmaBaseAddress->STATUSBLOCK & (DMA_STATUSBLOCK_STATUS_0 << hdma->ChannelIndex)) != RESET) && \
      ((hdma->DmaBaseAddress->MASKBLOCK & (DMA_MASKBLOCK_INT_MASK_0 << hdma->ChannelIndex)) != RESET))
  {
    DMA_BlockTransferComplete(hdma);
  }
  /* Transfer Complete Interrupt management ******************************/
  else if (((hdma->DmaBaseAddress->STATUSTFR & (DMA_STATUSTFR_STATUS_0 << hdma->ChannelIndex)) != RESET) && \
      ((hdma->DmaBaseAddress->MASKTFR & (DMA_MASKTFR_INT_MASK_0 << hdma->ChannelIndex)) != RESET))
  {
    /* Disable interrupts */
    MODIFY_REG(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKTFR_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKSRCTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKDSTTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKERR_INT_MASK_WE_0 << hdma->ChannelIndex));
    
    __HAL_DMA_DISABLE_IT(hdma);
    
    /* Change the DMA state */
    hdma->State = HAL_DMA_STATE_READY;
    
    /* Clear the transfer complete flag */
    hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
    
    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    if(hdma->XferCpltCallback != NULL)
    {
      /* Transfer complete callback */
      hdma->XferCpltCallback(hdma);
    }
  }
  /* Transfer Error Interrupt management ******************************/
  else if (((hdma->DmaBaseAddress->STATUSERR & (DMA_STATUSERR_STATUS_0 << hdma->ChannelIndex)) != RESET) && \
      ((hdma->DmaBaseAddress->MASKERR & (DMA_MASKERR_INT_MASK_0 << hdma->ChannelIndex)) != RESET))
  {
    /* When a DMA transfer error occurs */
    /* A hardware clear of its CH_EN bits is performed */
    /* Disable ALL DMA IT */
    MODIFY_REG(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKTFR_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKBLOCK, ((DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKHALFBLOCK, ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << hdma->ChannelIndex), \
             (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKSRCTRAN, ((DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKSRCTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKDSTTRAN, ((DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKDSTTRAN_INT_MASK_WE_0 << hdma->ChannelIndex));
    MODIFY_REG(hdma->DmaBaseAddress->MASKERR, ((DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << hdma->ChannelIndex), \
               (DMA_MASKERR_INT_MASK_WE_0 << hdma->ChannelIndex));
    
    __HAL_DMA_DISABLE_IT(hdma);

    /* Clear all flags */
    hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARSRCTRAN = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARDSTTRAN = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
    hdma->DmaBaseAddress->CLEARERR = (DMA_CLEARERR_CLEAR_0 << hdma->ChannelIndex);

    /* Update error code */
    hdma->ErrorCode = HAL_DMA_ERROR_TE;

    /* Change the DMA state */
    hdma->State = HAL_DMA_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    if (hdma->XferErrorCallback != NULL)
    {
      /* Transfer error callback */
      hdma->XferErrorCallback(hdma);
    }
  }
  return;
}

/**
  * @brief Register callbacks
  * @param hdma: pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA Channel.
  * @param CallbackID: User Callback identifer
  *                    a HAL_DMA_CallbackIDTypeDef ENUM as parameter.
  * @param pCallback: pointer to private callbacsk function which has pointer to 
  *                   a DMA_HandleTypeDef structure as parameter.
  * @retval HAL status
  */                          
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma))
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* Process locked */
  __HAL_LOCK(hdma);
  
  if(HAL_DMA_STATE_READY == hdma->State)
  {
    switch (CallbackID)
    {
    case  HAL_DMA_XFER_CPLT_CB_ID:
      hdma->XferCpltCallback = pCallback;
      break;
      
    case  HAL_DMA_XFER_BLOCK_CPLT_CB_ID:
      hdma->XferBlockCpltCallback = pCallback;
      break;
    
    case  HAL_DMA_XFER_HALFBLOCK_CPLT_CB_ID:
      hdma->XferHalfBlockCpltCallback = pCallback;
      break;
    
    case  HAL_DMA_XFER_SRCTRAN_CPLT_CB_ID:
      hdma->XferSrcTranCpltCallback = pCallback;
      break;
    
    case  HAL_DMA_XFER_DSTTRAN_CPLT_CB_ID:
      hdma->XferDstTranCpltCallback = pCallback;
      break;

    case  HAL_DMA_XFER_ERROR_CB_ID:
      hdma->XferErrorCallback = pCallback;
      break;         
      
    case  HAL_DMA_XFER_ABORT_CB_ID:
      hdma->XferAbortCallback = pCallback;
      break; 
      
    default:
      status = HAL_ERROR;
      break;
    }
  }
  else
  {
    status = HAL_ERROR;
  } 
  
  /* Release Lock */
  __HAL_UNLOCK(hdma);
  
  return status;
}

/**
  * @brief UnRegister callbacks
  * @param hdma: pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA Channel.
  * @param CallbackID: User Callback identifer
  *                    a HAL_DMA_CallbackIDTypeDef ENUM as parameter.
  * @retval HAL status
  */              
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);
  
  if(HAL_DMA_STATE_READY == hdma->State)
  {
    switch (CallbackID)
    {
    case  HAL_DMA_XFER_CPLT_CB_ID:
      hdma->XferCpltCallback = NULL;
      break;
      
    case  HAL_DMA_XFER_BLOCK_CPLT_CB_ID:
      hdma->XferBlockCpltCallback = NULL;
      break;
    
    case  HAL_DMA_XFER_HALFBLOCK_CPLT_CB_ID:
      hdma->XferHalfBlockCpltCallback = NULL;
      break;
    
    case  HAL_DMA_XFER_SRCTRAN_CPLT_CB_ID:
      hdma->XferSrcTranCpltCallback = NULL;
      break;
    
    case  HAL_DMA_XFER_DSTTRAN_CPLT_CB_ID:
      hdma->XferDstTranCpltCallback = NULL;
      break;

    case  HAL_DMA_XFER_ERROR_CB_ID:
      hdma->XferErrorCallback = NULL;
      break;         

    case  HAL_DMA_XFER_ABORT_CB_ID:
      hdma->XferAbortCallback = NULL;
      break; 

    case   HAL_DMA_XFER_ALL_CB_ID:
      hdma->XferCpltCallback = NULL;
      hdma->XferBlockCpltCallback = NULL;
      hdma->XferHalfBlockCpltCallback = NULL;
      hdma->XferSrcTranCpltCallback = NULL;
      hdma->XferDstTranCpltCallback = NULL;
      hdma->XferErrorCallback = NULL;
      hdma->XferAbortCallback = NULL;
      break; 

    default:
      status = HAL_ERROR;
      break;
    }
  }
  else
  {
    status = HAL_ERROR;
  } 
  
  /* Release Lock */
  __HAL_UNLOCK(hdma);
  
  return status;
}

/**
  * @brief  Set DMA Channel Request.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @param  ReqType: DMA request type
            This parameter can be a value of @arg DMA_Req_Tpye.
  * @param  ReqNum: DMA request number
            This parameter can be a value of @arg DMA_Req_Num.
  * @param  ReqFunc: DMA request function
            This parameter can be a value of @arg DMA_Req_Func.
  * @note   This function needs to be called to configure DMA requests 
  *         only when the peripheral (non memory) is configured as hardware handshake.
  * @retval None
  */
void HAL_DMA_ChannelReq(DMA_HandleTypeDef *hdma, uint32_t ReqType, uint32_t ReqNum, uint32_t ReqFunc)
{
  uint32_t position = 0;
  
  assert_param(IS_DMA_REQ_TYPE(ReqType));
  assert_param(IS_DMA_REQ_NUM(ReqNum));
  assert_param(IS_DMA_REQ_FUNC(ReqFunc));
  
  /* Configuration request number */
  if(ReqType == DMA_REQ_TYPE_SRC)
  {
    MODIFY_REG(hdma->Instance->CH_CFGH, DMA_CH_CFGH_SRC_PER, (ReqNum << DMA_CH_CFGH_SRC_PER_Pos));
  }
  else
  {
    MODIFY_REG(hdma->Instance->CH_CFGH, DMA_CH_CFGH_DST_PER, (ReqNum << DMA_CH_CFGH_DST_PER_Pos));
  }
  
  /* Configure the requested functionality */
  if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel1))
  {
    position = ReqNum;
  }
  else 
  {
    position = ReqNum + 6;
  }
  
  __HAL_RCC_SYSCFG_CLK_ENABLE();
  
  MODIFY_REG((SYSCFG->CFGR[2 + (position >> 2)]), (0x7F << (8u * (position & 0x03u))), (ReqFunc << (8u * (position & 0x03u))));
}



/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Group3 Peripheral State and Errors functions
  *  @brief    Peripheral State and Errors functions
  *
@verbatim
 ===============================================================================
            ##### Peripheral State and Errors functions #####
 ===============================================================================  
    [..]
    This subsection provides functions allowing to
      (+) Check the DMA state
      (+) Get error code

@endverbatim
  * @{
  */

/**
  * @brief  Return the DMA hande state.
  * @param  hdma: pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA Channel.
  * @retval HAL state
  */
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma)
{
  /* Return DMA handle state */
  return hdma->State;
}

/**
  * @brief  Return the DMA error code.
  * @param  hdma : pointer to a DMA_HandleTypeDef structure that contains
  *              the configuration information for the specified DMA Channel.
  * @retval DMA Error Code
  */
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma)
{
  return hdma->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup DMA_Private_Functions
  * @{
  */

/**
  * @brief  Sets the DMA Transfer parameter.
  * @param  hdma:       pointer to a DMA_HandleTypeDef structure that contains
  *                     the configuration information for the specified DMA Channel.
  * @param  SrcAddress: The source memory Buffer address
  * @param  DstAddress: The destination memory Buffer address
  * @param  DataLength: The length of data to be transferred from source to destination
  * @retval None
  */
static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  /* Clear all flags */
  hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARHALFBLOCK = (DMA_CLEARHALFBLOCK_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARSRCTRAN = (DMA_CLEARSRCTRAN_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARDSTTRAN = (DMA_CLEARDSTTRAN_CLEAR_0 << hdma->ChannelIndex);
  hdma->DmaBaseAddress->CLEARERR = (DMA_CLEARERR_CLEAR_0 << hdma->ChannelIndex);

  if (hdma->Init.Mode == DMA_CIRCULAR)
  {
    MODIFY_REG(hdma->Instance->CH_CTRLH, DMA_CH_CTRLH_BLOCK_TS, DataLength); /* Set block length */
  }
  else
  {
    /* Transferred in 1 single block */
    if (DataLength <= hdma->Init.BlockMaxLen)
    {
      CLEAR_BIT(hdma->Instance->CH_CFGL, (DMA_CH_CFGL_RELOAD_DST | DMA_CH_CFGL_RELOAD_SRC));
      
      MODIFY_REG(hdma->Instance->CH_CTRLH, DMA_CH_CTRLH_BLOCK_TS, DataLength); /* Set block length */
      hdma->BlockNum = 1;  /* Number of blocks to be transfered */
      hdma->RemainLen = 0; /* Length remaining to be transfered (not enough for one block length) */
    }
    /* Transferred in 2 single blocks */
    else if (DataLength < (hdma->Init.BlockMaxLen * 2))
    {
      CLEAR_BIT(hdma->Instance->CH_CFGL, (DMA_CH_CFGL_RELOAD_DST | DMA_CH_CFGL_RELOAD_SRC));
      
      MODIFY_REG(hdma->Instance->CH_CTRLH, DMA_CH_CTRLH_BLOCK_TS, hdma->Init.BlockMaxLen); /* Set block length */
      hdma->BlockNum = 1;                                    /* Number of blocks to be transfered */
      hdma->RemainLen = DataLength % hdma->Init.BlockMaxLen;  /* Length remaining to be transfered (not enough for one block length) */
    }
    else
    {
      /* If the source address increment and the destination address increment are not fixed,
            the transfer is carried out according to multiple single blocks. */
      if ((hdma->Init.SrcInc != DMA_SRC_ADDR_FIX) && (hdma->Init.DstInc != DMA_DST_ADDR_FIX))
      {
        CLEAR_BIT(hdma->Instance->CH_CFGL, (DMA_CH_CFGL_RELOAD_DST | DMA_CH_CFGL_RELOAD_SRC));
      }
      /*  Transferred in multiple blocks  */
      else
      {
        if (hdma->Init.SrcInc != DMA_SRC_ADDR_FIX)
        {
          /* Address increment is not fixed, address configuration is continuous */
          CLEAR_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_RELOAD_SRC);
        }
        else
        {
          /* Address increment is fixed, address configuration is reloaded */
          SET_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_RELOAD_SRC);
        }
        
        if (hdma->Init.DstInc != DMA_DST_ADDR_FIX)
        {
          /* Address increment is not fixed, address configuration is continuous */
          CLEAR_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_RELOAD_DST);
        }
        else
        {
          /* Address increment is fixed, address configuration is reloaded */
          SET_BIT(hdma->Instance->CH_CFGL, DMA_CH_CFGL_RELOAD_DST);
        }
      }
      
      
      MODIFY_REG(hdma->Instance->CH_CTRLH, DMA_CH_CTRLH_BLOCK_TS, hdma->Init.BlockMaxLen); /* Set block length */
      hdma->BlockNum = DataLength / hdma->Init.BlockMaxLen;   /* Number of blocks to be transfered */
      hdma->RemainLen = DataLength % hdma->Init.BlockMaxLen;  /* Length remaining to be transfered (not enough for one block length) */
    }
  }
  
  /* Configure DMA Channel source and destination address */
  hdma->Instance->SA = SrcAddress;
  hdma->Instance->DA = DstAddress;
}

/**
  * @brief  Handle block transfer complete.
  * @param  hdma:       pointer to a DMA_HandleTypeDef structure that contains
  *                     the configuration information for the specified DMA Channel.
  * @retval None
  */
static void DMA_BlockTransferComplete(DMA_HandleTypeDef *hdma)
{
  uint32_t temp = 0;
  if (hdma->Init.Mode != DMA_CIRCULAR)
  {
    hdma->BlockNum--;
    
    /* At least two blocks(block size: hdma->Init.BlockMaxLen) need to be transferred */
    if (hdma->BlockNum >= 1)
    {
      /* If the source address increment and the destination address increment are not fixed,
            the transfer is carried out according to multiple single blocks. */
      if ((hdma->Init.SrcInc != DMA_SRC_ADDR_FIX) && (hdma->Init.DstInc != DMA_DST_ADDR_FIX))
      {
          /* Clear DMA transfer complete flag */
          hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
          
          /*  Clear DMA block transfer complete flag  */
          hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
          
          if(hdma->XferBlockCpltCallback != NULL)  
          {
            /* DMA block transfer complete callback */
            hdma->XferBlockCpltCallback(hdma);
          }
          
          SET_BIT(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_WE_0 | DMA_CH_EN_CH_EN_0) << hdma->ChannelIndex)); /* Enable CHANNEL */
          return;
      }
      else
      {
        if (hdma->BlockNum == 1)
        {
          /*  The next block is the last block of the multiblock transfer,so disable automatic reload of
              source address and destination address. */
          CLEAR_BIT(hdma->Instance->CH_CFGL, (DMA_CH_CFGL_RELOAD_SRC | DMA_CH_CFGL_RELOAD_DST));
        }
      }
    }
    
    if ((hdma->BlockNum == 0) && (hdma->RemainLen != 0))
    {
      /* Clear DMA transfer complete flag */
      hdma->DmaBaseAddress->CLEARTFR = (DMA_CLEARTFR_CLEAR_0 << hdma->ChannelIndex);
      
      /*  Clear DMA block transfer complete flag  */
      hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
      
      if(hdma->XferBlockCpltCallback != NULL)  
      {
        /* DMA block transfer complete callback */
        hdma->XferBlockCpltCallback(hdma);
      }
      
      /* Adjust the block length to the remaining length and transfer as a single block */
      temp =  hdma->RemainLen;
      MODIFY_REG(hdma->Instance->CH_CTRLH, DMA_CH_CTRLH_BLOCK_TS, temp); /* Set block length */
      hdma->BlockNum = 1;  /* Number of blocks to be transfered */
      hdma->RemainLen = 0; /* Length remaining to be transfered */
      SET_BIT(hdma->DmaBaseAddress->CH_EN, ((DMA_CH_EN_CH_EN_WE_0 | DMA_CH_EN_CH_EN_0) << hdma->ChannelIndex)); /* Enable CHANNEL */
      return;
    }
    
    if ((hdma->BlockNum == 0) && (hdma->RemainLen == 0))
    {
      /* Data transfer complete, final processing at DMA transfer completion interrupt */
      SET_BIT(hdma->DmaBaseAddress->MASKTFR, ((DMA_MASKTFR_INT_MASK_WE_0 | DMA_MASKTFR_INT_MASK_0) << hdma->ChannelIndex));
    }
  }
  
  /*  Clear DMA block transfer complete flag  */
  hdma->DmaBaseAddress->CLEARBLOCK = (DMA_CLEARBLOCK_CLEAR_0 << hdma->ChannelIndex);
  
  if(hdma->XferBlockCpltCallback != NULL)  
  {
    /* DMA block transfer complete callback */
    hdma->XferBlockCpltCallback(hdma);
  }
}


/**
  * @}
  */

#endif /* HAL_DMA_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

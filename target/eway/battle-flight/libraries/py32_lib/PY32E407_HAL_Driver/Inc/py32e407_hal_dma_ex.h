/**
  ******************************************************************************
  * @file    py32e407_hal_dma_ex.h
  * @author  MCU Application Team
  * @brief   Header file of DMA HAL extension module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PY32E407_HAL_DMA_EX_H
#define __PY32E407_HAL_DMA_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup DMAEx DMAEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/ 
/* Exported constants --------------------------------------------------------*/
/** @defgroup DMA_interrupt_enable_definitions DMA interrupt enable definitions
  * @{
  */
#define DMA_IT_HALFBLOCK                  MASKHALFBLOCK
#define DMA_IT_TFR                        MASKTFR
#define DMA_IT_BLOCK                      MASKBLOCK
#define DMA_IT_SRCTRAN                    MASKSRCTRAN
#define DMA_IT_DSTTRAN                    MASKDSTTRAN
#define DMA_IT_ERR                        MASKERR
/**
  * @}
  */

/** @defgroup DMA_flag_definitions DMA flag definitions
  * @{
  */
#define DMA_FLAG_HALFBLOCK                STATUSHALFBLOCK
#define DMA_FLAG_TFR                      STATUSTFR
#define DMA_FLAG_BLOCK                    STATUSBLOCK
#define DMA_FLAG_SRCTRAN                  STATUSSRCTRAN
#define DMA_FLAG_DSTTRAN                  STATUSDSTTRAN
#define DMA_FLAG_ERR                      STATUSERR
/**
  * @}
  */

/** @defgroup DMA_clear_flag_definitions  Clear DMA flag definition 
  * @{
  */
#define DMA_CLEAR_FLAG_HALFBLOCK          CLEARHALFBLOCK
#define DMA_CLEAR_FLAG_TFR                CLEARTFR
#define DMA_CLEAR_FLAG_BLOCK              CLEARBLOCK
#define DMA_CLEAR_FLAG_SRCTRAN            CLEARSRCTRAN
#define DMA_CLEAR_FLAG_DSTTRAN            CLEARDSTTRAN
#define DMA_CLEAR_FLAG_ERR                CLEARERR
/**
  * @}
  */

/** @defgroup DMA_all_channel_flag_definitions   All DMA channels’ flag definition
  * @{
  */
#define DMA_ALL_CH_FLAG_HALFBLOCK         DMA_STATUSINT_HALFBLOCK
#define DMA_ALL_CH_FLAG_TFR               DMA_STATUSINT_TFR
#define DMA_ALL_CH_FLAG_BLOCK             DMA_STATUSINT_BLOCK
#define DMA_ALL_CH_FLAG_SRCTRAN           DMA_STATUSINT_SRCT
#define DMA_ALL_CH_FLAG_DSTTRAN           DMA_STATUSINT_DSTT
#define DMA_ALL_CH_FLAG_ERR               DMA_STATUSINT_ERR
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DMAEx_Exported_Macros DMA Extended Exported Macros
  * @{
  */

/**
  * @brief  Return the current DMA Channel base address.
  * @param  __HANDLE__: DMA handle
  * @retval The current DMA Channel base address.
  */
#define __HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel1))? DMA1 : DMA2)

/**
  * @brief  Return the current DMA Channel index.
  * @param  __HANDLE__: DMA handle
  * @retval The current DMA Channel index.
  */
#define __HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel1))? \
 (((uint32_t)(__HANDLE__)->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) : \
 (((uint32_t)(__HANDLE__)->Instance - (uint32_t)DMA2_Channel1) / ((uint32_t)DMA2_Channel2 - (uint32_t)DMA2_Channel1)))

/**
  * @brief  Enable the specified DMA.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE(__HANDLE__)       (((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel1))? \
                                            (SET_BIT(DMA1->EN, DMA_EN_DMA_EN)) : \
                                            (SET_BIT(DMA2->EN, DMA_EN_DMA_EN)))

/**
  * @brief  Disable the specified DMA.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE(__HANDLE__)      (((uint32_t)((__HANDLE__)->Instance) < (uint32_t)(DMA2_Channel1))? \
                                            (CLEAR_BIT(DMA1->EN, DMA_EN_DMA_EN)) : \
                                            (CLEAR_BIT(DMA2->EN, DMA_EN_DMA_EN)))

/**
  * @brief  Enable the specified DMA Channel.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_CHANNEL(__HANDLE__)    SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->CH_EN, \
                                                        ((DMA_CH_EN_CH_EN_WE_0 | DMA_CH_EN_CH_EN_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Disable the specified DMA Channel.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_CHANNEL(__HANDLE__)   MODIFY_REG((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->CH_EN, \
                                                           ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                           (DMA_CH_EN_CH_EN_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))));

/** @brief  Enable DMA Channel interrupt.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_IT(__HANDLE__)          SET_BIT((__HANDLE__)->Instance->CH_CTRLL, DMA_CH_CTRLL_INT_EN)

/** @brief  Disable DMA Channel interrupt.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_IT(__HANDLE__)         CLEAR_BIT((__HANDLE__)->Instance->CH_CTRLL, DMA_CH_CTRLL_INT_EN)

/**
  * @brief  Enables the specified DMA Channel interrupts mask.
  * @param  __HANDLE__: DMA handle
  * @param __INTERRUPT__: specifies the DMA interrupt sources to be enabled.
  *          This parameter can be one of the following values:
  *            @arg DMA_IT_HALFBLOCK  Half-block transfer completion interrupt
  *            @arg DMA_IT_TFR        Transfer Complete Interrupt
  *            @arg DMA_IT_BLOCK      Block transfer completion interrupt
  *            @arg DMA_IT_SRCTRAN    Source transaction completion interrupt
  *            @arg DMA_IT_DSTTRAN    Destination transaction completion interrupt
  *            @arg DMA_IT_ERR        Transfer Error Interrupt
  * @retval None
  */
#define __HAL_DMA_ENABLE_IT_MASK(__HANDLE__, __INTERRUPT__)   SET_BIT(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->__INTERRUPT__), \
                                                                      ((DMA_MASKHALFBLOCK_INT_MASK_WE_0 | DMA_MASKHALFBLOCK_INT_MASK_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Disables the specified DMA Channel interrupts mask.
  * @param  __HANDLE__: DMA handle
  * @param __INTERRUPT__: specifies the DMA interrupt sources to be disabled.
  *          This parameter can be one of the following values:
  *            @arg DMA_IT_HALFBLOCK  Half-block transfer completion interrupt
  *            @arg DMA_IT_TFR        Transfer Complete Interrupt
  *            @arg DMA_IT_BLOCK      Block transfer completion interrupt
  *            @arg DMA_IT_SRCTRAN    Source transaction completion interrupt
  *            @arg DMA_IT_DSTTRAN    Destination transaction completion interrupt
  *            @arg DMA_IT_ERR        Transfer Error Interrupt
  * @retval None
  */
#define __HAL_DMA_DISABLE_IT_MASK(__HANDLE__, __INTERRUPT__)   MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->__INTERRUPT__), \
                                                                          ((DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                                          (DMA_MASKHALFBLOCK_INT_MASK_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Check whether the specified DMA Channel interrupt mask is enabled or not.
  * @param  __HANDLE__: DMA handle
  * @param  __INTERRUPT__: specifies the DMA interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg DMA_IT_HALFBLOCK  Half-block transfer completion interrupt
  *            @arg DMA_IT_TFR        Transfer Complete Interrupt
  *            @arg DMA_IT_BLOCK      Block transfer completion interrupt
  *            @arg DMA_IT_SRCTRAN    Source transaction completion interrupt
  *            @arg DMA_IT_DSTTRAN    Destination transaction completion interrupt
  *            @arg DMA_IT_ERR        Transfer Error Interrupt
  * @retval The state of DMA_IT (SET or RESET).
  */
#define __HAL_DMA_GET_IT_SOURCE_MASK(__HANDLE__, __INTERRUPT__)  (READ_BIT(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->__INTERRUPT__), \
                                                                      (DMA_MASKHALFBLOCK_INT_MASK_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))) == (DMA_MASKHALFBLOCK_INT_MASK_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Get the specified DMA Channel pending flags.
  * @param  __HANDLE__: DMA handle
  * @param  __FLAG__: Get the specified flag.
  *          This parameter can be one of the following values:
  *            @arg DMA_FLAG_HALFBLOCK  Half-block transfer completion interrupt flag
  *            @arg DMA_FLAG_TFR        Transfer Complete Interrupt flag
  *            @arg DMA_FLAG_BLOCK      Block transfer completion interrupt flag
  *            @arg DMA_FLAG_SRCTRAN    Source transaction completion interrupt flag
  *            @arg DMA_FLAG_DSTTRAN    Destination transaction completion interrupt flag
  *            @arg DMA_FLAG_ERR        Transfer Error Interrupt flag
  * @retval The state of FLAG (SET or RESET).
  */
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (READ_BIT(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->__FLAG__), \
                                                       ((DMA_STATUSHALFBLOCK_STATUS_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))) == ((DMA_STATUSHALFBLOCK_STATUS_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))))

/**
  * @brief  Clears the specified DMA Channel pending flags.
  * @param  __HANDLE__: DMA handle
  * @param  __CLEAR_FLAG__: specifies the flag to clear.
  *          This parameter can be one of the following values:
  *            @arg DMA_CLEAR_FLAG_HALFBLOCK  Clear Half-block transfer completion interrupt flag
  *            @arg DMA_CLEAR_FLAG_TFR        Clear Transfer Complete Interrupt flag
  *            @arg DMA_CLEAR_FLAG_BLOCK      Clear Block transfer completion interrupt flag
  *            @arg DMA_CLEAR_FLAG_SRCTRAN    Clear Source transaction completion interrupt flag
  *            @arg DMA_CLEAR_FLAG_DSTTRAN    Clear Destination transaction completion interrupt flag
  *            @arg DMA_CLEAR_FLAG_ERR        Clear Transfer Error Interrupt flag
  *         Where x can be 1_7 or 1_5 (depending on DMA1 or DMA2) to select the DMA Channel flag.   
  * @retval None
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __CLEAR_FLAG__)  ((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->__CLEAR_FLAG__ = (DMA_CLEARHALFBLOCK_CLEAR_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Get all DMA channels’ pending flags.
  * @param  __HANDLE__: DMA handle
  * @param  __FLAG__: Get the specified flag.
  *          This parameter can be one of the following values:
  *            @arg DMA_ALL_CH_FLAG_HALFBLOCK  OR of all channels' half block Transfer complete interrupt flag
  *            @arg DMA_ALL_CH_FLAG_TFR        OR of all channels' transfer Complete Interrupt flag
  *            @arg DMA_ALL_CH_FLAG_BLOCK      OR of all channels' block transfer completion interrupt flag
  *            @arg DMA_ALL_CH_FLAG_SRCTRAN    OR of all channels' source transaction completion interrupt flag
  *            @arg DMA_ALL_CH_FLAG_DSTTRAN    OR of all channels' destination transaction completion interrupt flag
  *            @arg DMA_ALL_CH_FLAG_ERR        OR of all channels' transfer Error Interrupt flag
  * @retval The state of FLAG (SET or RESET).
  */
#define __HAL_DMA_GET_ALL_CHANNELS_FLAG(__HANDLE__, __FLAG__) (READ_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->STATUSINT, __FLAG__) == (__FLAG__))



/**
  * @brief  Enable the specified DMA Channel Source Software Busrt Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_SRC_BUSRT_REQ(__HANDLE__)  do{                                                        \
                                                    SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->REQSRC, \
                                                        ((DMA_REQSRC_SRC_REQ_WE_0 | DMA_REQSRC_SRC_REQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                    SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQSRC, \
                                                        ((DMA_SGLRQSRC_SRC_SGLREQ_WE_0 | DMA_SGLRQSRC_SRC_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                  }while(0U) \

/**
  * @brief  Disable the specified DMA Channel Source Software Busrt Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_SRC_BUSRT_REQ(__HANDLE__)  do{                                                        \
                                                    MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQSRC), \
                                                               ((DMA_SGLRQSRC_SRC_SGLREQ_WE_0 | DMA_SGLRQSRC_SRC_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                               (DMA_SGLRQSRC_SRC_SGLREQ_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                    MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->REQSRC), \
                                                               ((DMA_REQSRC_SRC_REQ_WE_0 | DMA_REQSRC_SRC_REQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                               (DMA_REQSRC_SRC_REQ_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                  }while(0U) \

/**
  * @brief  Enable the specified DMA Channel Destination Software Busrt Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_DST_BUSRT_REQ(__HANDLE__)  do{                                                        \
                                                    SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->REQDST, \
                                                        ((DMA_REQDST_DST_REQ_WE_0 | DMA_REQDST_DST_REQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                    SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQDST, \
                                                        ((DMA_SGLRQDST_DST_SGLREQ_WE_0 | DMA_SGLRQDST_DST_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                  }while(0U) \

/**
  * @brief  Disable the specified DMA Channel Destination Software Busrt Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_DST_BUSRT_REQ(__HANDLE__)  do{                                                        \
                                                    MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQDST), \
                                                               ((DMA_SGLRQDST_DST_SGLREQ_WE_0 | DMA_SGLRQDST_DST_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                               (DMA_SGLRQDST_DST_SGLREQ_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                    MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->REQDST), \
                                                               ((DMA_REQDST_DST_REQ_WE_0 | DMA_REQDST_DST_REQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                               (DMA_REQDST_DST_REQ_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__)))); \
                                                  }while(0U) \

/**
  * @brief  Enable the specified DMA Channel Source Software Single Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_SRC_SINGLE_REQ(__HANDLE__) SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQSRC, \
                                                            ((DMA_SGLRQSRC_SRC_SGLREQ_WE_0 | DMA_SGLRQSRC_SRC_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Disable the specified DMA Channel Source Software Single Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_SRC_SINGLE_REQ(__HANDLE__)  MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQSRC), \
                                                                 ((DMA_SGLRQSRC_SRC_SGLREQ_WE_0 | DMA_SGLRQSRC_SRC_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                                 (DMA_SGLRQSRC_SRC_SGLREQ_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Enable the specified DMA Channel Destination Software Single Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_DST_SINGLE_REQ(__HANDLE__)  SET_BIT((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQDST, \
                                                        ((DMA_SGLRQDST_DST_SGLREQ_WE_0 | DMA_SGLRQDST_DST_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))

/**
  * @brief  Disable the specified DMA Channel Destination Software Single Transaction Request.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_DST_SINGLE_REQ(__HANDLE__)  MODIFY_REG(((__HAL_DMA_GET_CHANNEL_BASE_ADDR(__HANDLE__))->SGLRQDST), \
                                                                 ((DMA_SGLRQDST_DST_SGLREQ_WE_0 | DMA_SGLRQDST_DST_SGLREQ_0) << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))), \
                                                                 (DMA_SGLRQDST_DST_SGLREQ_WE_0 << (__HAL_DMA_GET_CHANNEL_INDEX(__HANDLE__))))
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif 

#endif /* __PY32E407_HAL_DMA_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

/**
  ******************************************************************************
  * @file    py32e407_hal_dma.h
  * @author  MCU Application Team
  * @brief   Header file of DMA HAL module.
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
#ifndef __PY32E407_HAL_DMA_H
#define __PY32E407_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup DMA_Exported_Types DMA Exported Types
  * @{
  */

/**
  * @brief  DMA Configuration Structure definition
  */
typedef struct
{
  uint32_t Direction;                 /*!< Specifies transfer direction.
                                           This parameter can be a value of @ref DMA_Data_transfer_direction */
  
  uint32_t SrcWidth;                  /*!< Specifies source transfer width.
                                           This parameter can be a value of @ref DMA_Source_Transfer_Width */
  
  uint32_t DstWidth;                  /*!< Specifies destination transfer width.
                                           This parameter can be a value of @ref DMA_Destination_Transfer_Width */
  
  uint32_t SrcBurstLen;               /*!< Specifies source burst transaction length.
                                           This parameter can be a value of @ref DMA_Source_Burst_Transaction_Length
                                           @note This configuration is for peripheral，not for memory */
  
  uint32_t DstBurstLen;               /*!< Specifies destination burst transaction length.
                                           This parameter can be a value of @ref DMA_Destination_Burst_Transaction_Length 
                                           @note This configuration is for peripheral，not for memory */
  
  uint32_t SrcInc;                    /*!< Specifies source address increment.
                                           This parameter can be a value of @ref DMA_Source_Address_Increment */
  
  uint32_t DstInc;                   /*!< Specifies destination address increment.
                                           This parameter can be a value of @ref DMA_Destination_Address_Increment */
  
  uint32_t Mode;                      /*!< Specifies the operation mode of the DMA Channelx.
                                           This parameter can be a value of @ref DMA_mode 
                                           @note In circular mode, the maximum circular transfer length does not exceed 4095.*/
  
  uint32_t SrcReload;                 /*!< Specifies whether source reload is enabled.
                                           This parameter can be a value of @ref DMA_Source_Reload
                                           @note This configuration is used for DMA_CIRCULAR mode and not for DMA_NORMAL mode, 
                                                 SrcReload and DstReload Cannot be configured to disable at the same time  */
  
  uint32_t DstReload;                 /*!< Specifies whether destination reload is enabled.
                                           This parameter can be a value of @ref DMA_Destination_Reload
                                           @note This configuration is used for DMA_CIRCULAR mode and not for DMA_NORMAL mode, 
                                                 SrcReload and DstReload Cannot be configured to disable at the same time  */
  
  uint32_t SrcHandshakeType;          /*!< Specifies source handshake type.
                                           This parameter can be a value of @ref DMA_Source_Handshake_Type
                                           @note This configuration is for peripheral，not for memory */
  
  uint32_t DstHandshakeType;          /*!< Specifies destination handshake type.
                                           This parameter can be a value of @ref DMA_Destination_Handshake_Type
                                           @note This configuration is for peripheral，not for memory */
  
  uint32_t Priority;                  /*!< Specifies channel priority.
                                           This parameter can be a value of @ref DMA_Priority_level */
  
  uint32_t BlockMaxLen;               /*!<  Specifies the maximum length of a block.
                                            This parameter must be a number between Min_Data = 1 and Max_Data = 4095.
                                            Macro DMA_BLOCK_DEFAULT_MAX_LEN is the default maximum length of a block. */

} DMA_InitTypeDef;

/**
  * @brief  HAL DMA State structures definition
  */
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled    */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use      */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing                 */
  HAL_DMA_STATE_TIMEOUT           = 0x03U   /*!< DMA timeout state                      */
}HAL_DMA_StateTypeDef;

/**
  * @brief  HAL DMA Error Code structure definition
  */
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,    /*!< Full transfer     */
  HAL_DMA_HALF_BLOCK_TRANSFER     = 0x01U     /*!< Half block Transfer     */
}HAL_DMA_LevelCompleteTypeDef;

/** 
  * @brief  HAL DMA Callback ID structure definition
  */
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID            = 0x00U,    /*!< DMA transfer complete     */
  HAL_DMA_XFER_BLOCK_CPLT_CB_ID      = 0x01U,    /*!< DMA block transfer complete     */
  HAL_DMA_XFER_HALFBLOCK_CPLT_CB_ID  = 0x02U,    /*!< DMA half block transfer complete     */
  HAL_DMA_XFER_SRCTRAN_CPLT_CB_ID    = 0x03U,    /*!< DMA source transaction complete     */
  HAL_DMA_XFER_DSTTRAN_CPLT_CB_ID    = 0x04U,    /*!< DMA destination transaction complete     */
  HAL_DMA_XFER_ERROR_CB_ID           = 0x05U,    /*!< Error             */
  HAL_DMA_XFER_ABORT_CB_ID           = 0x06U,    /*!< Abort             */
  HAL_DMA_XFER_ALL_CB_ID             = 0x07U     /*!< All               */
    
}HAL_DMA_CallbackIDTypeDef;

/** 
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef   *Instance;                       /*!< Register base address                  */
  
  DMA_InitTypeDef       Init;                            /*!< DMA communication parameters           */ 
  
  HAL_LockTypeDef       Lock;                            /*!< DMA locking object                     */  
  
  HAL_DMA_StateTypeDef  State;                           /*!< DMA transfer state                     */
  
  void                  *Parent;                                                      /*!< Parent object state                    */  
  
  void                  (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);          /*!< DMA transfer complete callback         */
  
  void                  (* XferBlockCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA block transfer complete callback         */
  
  void                  (* XferHalfBlockCpltCallback)( struct __DMA_HandleTypeDef * hdma); /*!< DMA half block transfer complete callback         */
  
  void                  (* XferSrcTranCpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA source transaction complete callback         */
  
  void                  (* XferDstTranCpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA destination transaction complete callback         */
  
  void                  (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);         /*!< DMA transfer error callback            */

  void                  (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);         /*!< DMA transfer abort callback            */  
  
  __IO uint32_t         ErrorCode;                                                    /*!< DMA Error code                         */

  DMA_TypeDef            *DmaBaseAddress;                                             /*!< DMA Channel Base Address               */
  
  uint32_t               ChannelIndex;                                                /*!< DMA Channel Index                      */  
  
  __IO uint32_t          BlockNum;                                                    /* Number of blocks to be transfered */
  
  __IO uint32_t          RemainLen;                                                   /* Length remaining to be transfered (not enough for one block length) */

} DMA_HandleTypeDef;    
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_Error_Code DMA Error Code
  * @{
  */
#define HAL_DMA_ERROR_NONE                     0x00000000U    /*!< No error             */
#define HAL_DMA_ERROR_TE                       0x00000001U    /*!< Transfer error       */
#define HAL_DMA_ERROR_NO_XFER                  0x00000004U    /*!< no ongoing transfer  */
#define HAL_DMA_ERROR_TIMEOUT                  0x00000020U    /*!< Timeout error        */
#define HAL_DMA_ERROR_NOT_SUPPORTED            0x00000100U    /*!< Not supported mode   */ 
/**
  * @}
  */

/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @{
  */
#define DMA_MEMORY_TO_MEMORY         0x00000000U                       /*!< Memory to memory direction     */
#define DMA_MEMORY_TO_PERIPH         ((uint32_t)DMA_CH_CTRLL_TT_0)     /*!< Memory to peripheral direction */
#define DMA_PERIPH_TO_MEMORY         ((uint32_t)DMA_CH_CTRLL_TT_1)     /*!< Peripheral to memory direction */
#define DMA_PERIPH_TO_PERIPH         ((uint32_t)DMA_CH_CTRLL_TT)       /*!< Peripheral to Peripheral direction */
/**
  * @}
  */

/** @defgroup DMA_Source_Transfer_Width DMA Source Transfer Width
  * @{
  */
#define DMA_SRC_WIDTH_BYTE         0x00000000U                                 /*!< Source transfer width is 8 bits     */
#define DMA_SRC_WIDTH_HALFWORD     ((uint32_t)DMA_CH_CTRLL_SRC_TR_WIDTH_0)     /*!< Source transfer width is 16 bits     */
#define DMA_SRC_WIDTH_WORD         ((uint32_t)DMA_CH_CTRLL_SRC_TR_WIDTH_1)     /*!< Source transfer width is 32 bits     */
/**
  * @}
  */

/** @defgroup DMA_Destination_Transfer_Width DMA Destination Transfer Width
  * @{
  */
#define DMA_DST_WIDTH_BYTE         0x00000000U                                 /*!< Destination transfer width is 8 bits     */
#define DMA_DST_WIDTH_HALFWORD     ((uint32_t)DMA_CH_CTRLL_DST_TR_WIDTH_0)     /*!< Destination transfer width is 16 bits     */
#define DMA_DST_WIDTH_WORD         ((uint32_t)DMA_CH_CTRLL_DST_TR_WIDTH_1)     /*!< Destination transfer width is 32 bits     */
/**
  * @}
  */

/** @defgroup DMA_Source_Burst_Transaction_Length DMA Source Burst Transaction Length
  * @{
  */
#define DMA_SRC_BURST_LEN_1         0x00000000U                                                           /*!< Number of data items to be transferred is 1     */
#define DMA_SRC_BURST_LEN_4         ((uint32_t)DMA_CH_CTRLL_SRC_MSIZE_0)                                  /*!< Number of data items to be transferred is 4     */
#define DMA_SRC_BURST_LEN_8         ((uint32_t)DMA_CH_CTRLL_SRC_MSIZE_1)                                  /*!< Number of data items to be transferred is 8     */
#define DMA_SRC_BURST_LEN_16        ((uint32_t)(DMA_CH_CTRLL_SRC_MSIZE_1 | DMA_CH_CTRLL_SRC_MSIZE_0))     /*!< Number of data items to be transferred is 16     */
#define DMA_SRC_BURST_LEN_32        ((uint32_t)DMA_CH_CTRLL_SRC_MSIZE_2)                                  /*!< Number of data items to be transferred is 32     */
#define DMA_SRC_BURST_LEN_64        ((uint32_t)(DMA_CH_CTRLL_SRC_MSIZE_2 | DMA_CH_CTRLL_SRC_MSIZE_0))     /*!< Number of data items to be transferred is 64     */
#define DMA_SRC_BURST_LEN_128       ((uint32_t)(DMA_CH_CTRLL_SRC_MSIZE_2 | DMA_CH_CTRLL_SRC_MSIZE_1))     /*!< Number of data items to be transferred is 128     */
/**
  * @}
  */

/** @defgroup DMA_Destination_Burst_Transaction_Length DMA Destination Burst Transaction Length
  * @{
  */
#define DMA_DST_BURST_LEN_1         0x00000000U                                                           /*!< Number of data items to be transferred is 1     */
#define DMA_DST_BURST_LEN_4         ((uint32_t)DMA_CH_CTRLL_DST_MSIZE_0)                                  /*!< Number of data items to be transferred is 4     */
#define DMA_DST_BURST_LEN_8         ((uint32_t)DMA_CH_CTRLL_DST_MSIZE_1)                                  /*!< Number of data items to be transferred is 8     */
#define DMA_DST_BURST_LEN_16        ((uint32_t)(DMA_CH_CTRLL_DST_MSIZE_1 | DMA_CH_CTRLL_DST_MSIZE_0))     /*!< Number of data items to be transferred is 16     */
#define DMA_DST_BURST_LEN_32        ((uint32_t)DMA_CH_CTRLL_DST_MSIZE_2)                                  /*!< Number of data items to be transferred is 32     */
#define DMA_DST_BURST_LEN_64        ((uint32_t)(DMA_CH_CTRLL_DST_MSIZE_2 | DMA_CH_CTRLL_DST_MSIZE_0))     /*!< Number of data items to be transferred is 64     */
#define DMA_DST_BURST_LEN_128       ((uint32_t)(DMA_CH_CTRLL_DST_MSIZE_2 | DMA_CH_CTRLL_DST_MSIZE_1))     /*!< Number of data items to be transferred is 128     */
/**
  * @}
  */

/** @defgroup DMA_Source_Address_Increment Source Address Increment
  * @{
  */
#define DMA_SRC_ADDR_INC            0x00000000U                       /*!< Increments the source address     */
#define DMA_SRC_ADDR_DEC            ((uint32_t)DMA_CH_CTRLL_SINC_0)   /*!< Decrements the source address     */
#define DMA_SRC_ADDR_FIX            ((uint32_t)DMA_CH_CTRLL_SINC_1)   /*!< No change in the source address     */
/**
  * @}
  */

/** @defgroup DMA_Destination_Address_Increment Destination Address Increment
  * @{
  */
#define DMA_DST_ADDR_INC            0x00000000U                       /*!< Increments the destination address     */
#define DMA_DST_ADDR_DEC            ((uint32_t)DMA_CH_CTRLL_DINC_0)   /*!< Decrements the destination address     */
#define DMA_DST_ADDR_FIX            ((uint32_t)DMA_CH_CTRLL_DINC_1)   /*!< No change in the destination address     */
/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @{
  */
#define DMA_NORMAL         0x00000000U                  /*!< Normal mode   */
#define DMA_CIRCULAR       0x00000001U                  /*!< Circular mode */
/**
  * @}
  */

/** @defgroup DMA_Source_Reload Source Reload
  * @{
  */
#define DMA_SRC_RELOAD_DISABLE      0x00000000U                         /*!< source reload is disabled     */
#define DMA_SRC_RELOAD_ENABLE       ((uint32_t)DMA_CH_CFGL_RELOAD_SRC)  /*!< source reload is enabled     */
/**
  * @}
  */

/** @defgroup DMA_Destination_Reload Destination Reload
  * @{
  */
#define DMA_DST_RELOAD_DISABLE      0x00000000U                         /*!< Destination reload is disabled     */
#define DMA_DST_RELOAD_ENABLE       ((uint32_t)DMA_CH_CFGL_RELOAD_DST)  /*!< Destination reload is enabled     */
/**
  * @}
  */

/** @defgroup DMA_Source_Handshake_Type Source Handshake Type
  * @{
  */
#define DMA_SRC_HS_TYPE_HARD         0x00000000U                         /*!< Select hardware handshake for source    */
#define DMA_SRC_HS_TYPE_SOFT         ((uint32_t)DMA_CH_CFGL_HS_SEL_SRC)  /*!< Select software handshake for source    */
/**
  * @}
  */

/** @defgroup DMA_Destination_Handshake_Type Destination Handshake Type
  * @{
  */
#define DMA_DST_HS_TYPE_HARD         0x00000000U                         /*!< Select hardware handshake for destination    */
#define DMA_DST_HS_TYPE_SOFT         ((uint32_t)DMA_CH_CFGL_HS_SEL_DST)  /*!< Select software handshake for destination    */
/**
  * @}
  */

/** @defgroup DMA_Priority_level DMA Priority level
  * @{
  */
#define DMA_PRIORITY_0             0x00000000U
#define DMA_PRIORITY_1             ((uint32_t)DMA_CH_CFGL_CH_PRIOR_0)
#define DMA_PRIORITY_2             ((uint32_t)DMA_CH_CFGL_CH_PRIOR_1)
#define DMA_PRIORITY_3             ((uint32_t)(DMA_CH_CFGL_CH_PRIOR_1 | DMA_CH_CFGL_CH_PRIOR_0))
#define DMA_PRIORITY_4             ((uint32_t)DMA_CH_CFGL_CH_PRIOR_2)
#define DMA_PRIORITY_5             ((uint32_t)(DMA_CH_CFGL_CH_PRIOR_2 | DMA_CH_CFGL_CH_PRIOR_0))
/**
  * @}
  */

/** @defgroup DMA_FIFO_Mode DMA FIFO mode
  * @{
  */
#define DMA_FIFO_MODE_0             0x00000000U                        /*!< Space/data available for single
                                                                            AHB transfer of the specified transfer width    */
#define DMA_FIFO_MODE_1             ((uint32_t)DMA_CH_CFGH_FIFO_MODE)  /*!< Data available is greater than or
                                                                            equal to half the FIFO depth for destination transfers and
                                                                            space available is greater than half the fifo depth for
                                                                            source transfers.     */
/**
  * @}
  */

/** @defgroup DMA_Req_Tpye DMA request type
  * @{
  */
#define DMA_REQ_TYPE_SRC  0x0U     /* DMA request from source peripheral */
#define DMA_REQ_TYPE_DST  0x1U     /* DMA request for destination peripheral */
/**
  * @}
  */

/** @defgroup DMA_Req_Num DMA request number
  * @{
  */
#define DMA_REQ_NUM_0  0U
#define DMA_REQ_NUM_1  1U
#define DMA_REQ_NUM_2  2U
#define DMA_REQ_NUM_3  3U
#define DMA_REQ_NUM_4  4U
#define DMA_REQ_NUM_5  5U
/**
  * @}
  */

/** @defgroup DMA_Req_Func DMA request function
  * @{
  */
#define DMA_REQ_FUNC_ADC1              0U
#define DMA_REQ_FUNC_ADC2              1U
#define DMA_REQ_FUNC_ADC3              2U
#define DMA_REQ_FUNC_DAC1              3U
#define DMA_REQ_FUNC_DAC2              4U
#define DMA_REQ_FUNC_SPI1_RX           5U
#define DMA_REQ_FUNC_SPI1_TX           6U
#define DMA_REQ_FUNC_SPI2_RX           7U
#define DMA_REQ_FUNC_SPI2_TX           8U
#define DMA_REQ_FUNC_SPI3_RX           9U
#define DMA_REQ_FUNC_SPI3_TX           10U
#define DMA_REQ_FUNC_USART1_RX         11U
#define DMA_REQ_FUNC_USART1_TX         12U
#define DMA_REQ_FUNC_USART2_RX         13U
#define DMA_REQ_FUNC_USART2_TX         14U
#define DMA_REQ_FUNC_USART3_RX         15U
#define DMA_REQ_FUNC_USART3_TX         16U
#define DMA_REQ_FUNC_LPUART1_RX        17U
#define DMA_REQ_FUNC_LPUART1_TX        18U
#define DMA_REQ_FUNC_I2C1_RX           19U
#define DMA_REQ_FUNC_I2C1_TX           20U
#define DMA_REQ_FUNC_I2C2_RX           21U
#define DMA_REQ_FUNC_I2C2_TX           22U
#define DMA_REQ_FUNC_I2C3_RX           23U
#define DMA_REQ_FUNC_I2C3_TX           24U
#define DMA_REQ_FUNC_I2C4_RX           25U
#define DMA_REQ_FUNC_I2C4_TX           26U
#define DMA_REQ_FUNC_TIM1_CH1          27U
#define DMA_REQ_FUNC_TIM1_CH2          28U
#define DMA_REQ_FUNC_TIM1_CH3          29U
#define DMA_REQ_FUNC_TIM1_CH4          30U
#define DMA_REQ_FUNC_TIM1_UP           31U
#define DMA_REQ_FUNC_TIM1_TRIG         32U
#define DMA_REQ_FUNC_TIM1_COM          33U
#define DMA_REQ_FUNC_TIM8_CH1          34U
#define DMA_REQ_FUNC_TIM8_CH2          35U
#define DMA_REQ_FUNC_TIM8_CH3          36U
#define DMA_REQ_FUNC_TIM8_CH4          37U
#define DMA_REQ_FUNC_TIM8_UP           38U
#define DMA_REQ_FUNC_TIM8_TRIG         39U
#define DMA_REQ_FUNC_TIM8_COM          40U
#define DMA_REQ_FUNC_TIM6_UP           41U
#define DMA_REQ_FUNC_TIM7_UP           42U
#define DMA_REQ_FUNC_TIM2_CH1          43U
#define DMA_REQ_FUNC_TIM2_CH2          44U
#define DMA_REQ_FUNC_TIM2_CH3          45U
#define DMA_REQ_FUNC_TIM2_CH4          46U
#define DMA_REQ_FUNC_TIM2_UP           47U
#define DMA_REQ_FUNC_TIM2_TRIG         48U
#define DMA_REQ_FUNC_TIM3_CH1          49U
#define DMA_REQ_FUNC_TIM3_CH2          50U
#define DMA_REQ_FUNC_TIM3_CH3          51U
#define DMA_REQ_FUNC_TIM3_CH4          52U
#define DMA_REQ_FUNC_TIM3_UP           53U
#define DMA_REQ_FUNC_TIM3_TRIG         54U
#define DMA_REQ_FUNC_TIM4_CH1          55U
#define DMA_REQ_FUNC_TIM4_CH2          56U
#define DMA_REQ_FUNC_TIM4_CH3          57U
#define DMA_REQ_FUNC_TIM4_CH4          58U
#define DMA_REQ_FUNC_TIM4_UP           59U
#define DMA_REQ_FUNC_TIM4_TRIG         60U
#define DMA_REQ_FUNC_TIM5_CH1          61U
#define DMA_REQ_FUNC_TIM5_CH2          62U
#define DMA_REQ_FUNC_TIM5_CH3          63U
#define DMA_REQ_FUNC_TIM5_CH4          64U
#define DMA_REQ_FUNC_TIM5_UP           65U
#define DMA_REQ_FUNC_TIM5_TRIG         66U
#define DMA_REQ_FUNC_TIM18_CH1         67U
#define DMA_REQ_FUNC_TIM18_CH2         68U
#define DMA_REQ_FUNC_TIM18_CH3         69U
#define DMA_REQ_FUNC_TIM18_CH4         70U
#define DMA_REQ_FUNC_TIM18_UP          71U
#define DMA_REQ_FUNC_TIM18_TRIG        72U
#define DMA_REQ_FUNC_TIM15_CH1         73U

#define DMA_REQ_FUNC_TIM15_UP          75U
#define DMA_REQ_FUNC_TIM15_TRIG        76U
#define DMA_REQ_FUNC_TIM15_COM         77U
#define DMA_REQ_FUNC_TIM16_CH1         78U
#define DMA_REQ_FUNC_TIM16_UP          79U
#define DMA_REQ_FUNC_TIM17_CH1         80U
#define DMA_REQ_FUNC_TIM17_UP          81U
#define DMA_REQ_FUNC_AES_IN            82U
#define DMA_REQ_FUNC_AES_OUT           83U
#define DMA_REQ_FUNC_CORDIC_RD         84U
#define DMA_REQ_FUNC_CORDIC_WR         85U
#define DMA_REQ_FUNC_ESMC_RX           86U
#define DMA_REQ_FUNC_ESMC_TX           87U
#define DMA_REQ_FUNC_SDIO              88U
#define DMA_REQ_FUNC_UART1_RX          89U
#define DMA_REQ_FUNC_UART1_TX          90U
#define DMA_REQ_FUNC_UART2_RX          91U
#define DMA_REQ_FUNC_UART2_TX          92U
#define DMA_REQ_FUNC_UART3_RX          93U
#define DMA_REQ_FUNC_UART3_TX          94U
#define DMA_REQ_FUNC_LCDC_TX           95U

#define DMA_REQ_FUNC_END               96U

/**
  * @}
  */

/** @defgroup DMA_Block_Default_Max_Len The default maximum length of a block
  * @{
  */
#define DMA_BLOCK_DEFAULT_MAX_LEN  4095U     /*!< The default maximum length of a block    */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup DMA_Exported_Macros DMA Exported Macros
  * @{
  */

/** @brief  Reset DMA handle state.
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)

/**
  * @brief  Set maximum AMBA burst length that is used for DMA transfers on this channel.
  * @param  __HANDLE__: DMA handle
  * @param  __LEN__   : Maximum AMBA burst length
  * @retval None
  */
#define __HAL_DMA_SET_MAX_ABRST_LEN(__HANDLE__, __LEN__)  MODIFY_REG((__HANDLE__)->Instance->CH_CFGL, DMA_CH_CFGL_MAX_ABRST, (__LEN__ << DMA_CH_CFGL_MAX_ABRST_Pos))

/**
  * @brief  Get maximum AMBA burst length that is used for DMA transfers on this channel.
  * @param  __HANDLE__: DMA handle
  * @retval maximum AMBA burst length that is used for DMA transfers on this channel.
  */
#define __HAL_DMA_GET_MAX_ABRST_LEN(__HANDLE__)          (READ_BIT((__HANDLE__)->Instance->CH_CFGL, DMA_CH_CFGL_MAX_ABRST) >> DMA_CH_CFGL_MAX_ABRST_Pos)

/**
  * @brief  Enable the specified DMA Channel block interrupt pending(multiblock transfer).
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_BLOCK_INT_SUSPEND(__HANDLE__)    SET_BIT((__HANDLE__)->Instance->CH_CFGL, DMA_CH_CFGL_INT_SUSP)

/**
  * @brief  Disable the specified DMA Channel block interrupt pending(multiblock transfer).
  * @param  __HANDLE__: DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_BLOCK_INT_SUSPEND(__HANDLE__)   CLEAR_BIT((__HANDLE__)->Instance->CH_CFGL, DMA_CH_CFGL_INT_SUSP)

/**
  * @brief  Set the specified DMA Channel DMA FIFO mode.
  * @param  __HANDLE__: DMA handle
  * @param  __MODE__   : FIFO mode
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FIFO_MODE_0:  Space/data available for single AHB transfer of the
  *                                   specified transfer width.
  *            @arg DMA_FIFO_MODE_1:  Data available is greater than or equal to half the FIFO
  *                                   depth for destination transfers and space available is
  *                                   greater than half the fifo depth for source transfers.
  * @retval None
  */
#define __HAL_DMA_SET_FIFO_MODE(__HANDLE__, __MODE__)  MODIFY_REG((__HANDLE__)->Instance->CH_CFGH, DMA_CH_CFGH_FIFO_MODE, __MODE__)

/**
  * @brief  Get the specified DMA Channel DMA FIFO mode.
  * @param  __HANDLE__: DMA handle
  * @retval Returned value can be one of the following values:
  *         @arg @ref DMA_FIFO_MODE_0
  *         @arg @ref DMA_FIFO_MODE_1
  */
#define __HAL_DMA_GET_FIFO_MODE(__HANDLE__)  READ_BIT((__HANDLE__)->Instance->CH_CFGH, DMA_CH_CFGH_FIFO_MODE)

/**
  * @brief  Whether the specified DMA Channel FIFO is empty.
  * @retval State of bit (1 or 0).
  */
#define __HAL_DMA_IS_FIFO_EMPTY(__HANDLE__)  (READ_BIT((__HANDLE__)->Instance->CH_CFGL, DMA_CH_CFGL_FIFO_EMPTY) == (DMA_CH_CFGL_FIFO_EMPTY))
/**
  * @}
  */

/* Include DMA HAL Extension module */
#include "py32e407_hal_dma_ex.h"   

/* Exported functions --------------------------------------------------------*/
/** @addtogroup DMA_Exported_Functions
  * @{
  */

/** @addtogroup DMA_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);
void HAL_DMA_ChannelReq(DMA_HandleTypeDef *hdma, uint32_t ReqType, uint32_t ReqNum, uint32_t ReqFunc);

/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup DMA_Private_Macros DMA Private Macros
  * @{
  */

#define IS_DMA_DIRECTION(DIRECTION) (((DIRECTION) == DMA_PERIPH_TO_MEMORY) || \
                                     ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                     ((DIRECTION) == DMA_MEMORY_TO_MEMORY)  || \
                                     ((DIRECTION) == DMA_PERIPH_TO_PERIPH))

#define IS_DMA_SRC_WIDTH(WIDTH)      (((WIDTH) == DMA_SRC_WIDTH_BYTE) || \
                                      ((WIDTH) == DMA_SRC_WIDTH_HALFWORD) || \
                                      ((WIDTH) == DMA_SRC_WIDTH_WORD))
                                     
#define IS_DMA_DST_WIDTH(WIDTH)      (((WIDTH) == DMA_DST_WIDTH_BYTE) || \
                                      ((WIDTH) == DMA_DST_WIDTH_HALFWORD) || \
                                      ((WIDTH) == DMA_DST_WIDTH_WORD))

#define IS_DMA_SRC_BURST_LEN(LEN)    (((LEN) == DMA_SRC_BURST_LEN_1) || \
                                      ((LEN) == DMA_SRC_BURST_LEN_4) || \
                                      ((LEN) == DMA_SRC_BURST_LEN_8) || \
                                      ((LEN) == DMA_SRC_BURST_LEN_16) || \
                                      ((LEN) == DMA_SRC_BURST_LEN_32) || \
                                      ((LEN) == DMA_SRC_BURST_LEN_64) || \
                                      ((LEN) == DMA_SRC_BURST_LEN_128))
                                      
#define IS_DMA_DST_BURST_LEN(LEN)    (((LEN) == DMA_DST_BURST_LEN_1) || \
                                      ((LEN) == DMA_DST_BURST_LEN_4) || \
                                      ((LEN) == DMA_DST_BURST_LEN_8) || \
                                      ((LEN) == DMA_DST_BURST_LEN_16) || \
                                      ((LEN) == DMA_DST_BURST_LEN_32) || \
                                      ((LEN) == DMA_DST_BURST_LEN_64) || \
                                      ((LEN) == DMA_DST_BURST_LEN_128))

#define IS_DMA_SRC_INC(INC)          (((INC) == DMA_SRC_ADDR_INC) || \
                                      ((INC) == DMA_SRC_ADDR_DEC) || \
                                      ((INC) == DMA_SRC_ADDR_FIX))

#define IS_DMA_DST_INC(INC)          (((INC) == DMA_DST_ADDR_INC) || \
                                      ((INC) == DMA_DST_ADDR_DEC) || \
                                      ((INC) == DMA_DST_ADDR_FIX))

#define IS_DMA_MODE(MODE)            (((MODE) == DMA_NORMAL ) || \
                                      ((MODE) == DMA_CIRCULAR))

#define IS_DMA_SRC_RELOAD(VALUE)      (((VALUE) == DMA_SRC_RELOAD_DISABLE) || \
                                       ((VALUE) == DMA_SRC_RELOAD_ENABLE))

#define IS_DMA_DST_RELOAD(VALUE)      (((VALUE) == DMA_DST_RELOAD_DISABLE) || \
                                       ((VALUE) == DMA_DST_RELOAD_ENABLE))

#define IS_DMA_SRC_HS(TYPE)          (((TYPE) == DMA_SRC_HS_TYPE_HARD) || \
                                      ((TYPE) == DMA_SRC_HS_TYPE_SOFT))

#define IS_DMA_DST_HS(TYPE)          (((TYPE) == DMA_DST_HS_TYPE_HARD) || \
                                      ((TYPE) == DMA_DST_HS_TYPE_SOFT))

#define IS_DMA_PRIORITY(PRIORITY)      (((PRIORITY) == DMA_PRIORITY_0 ) || \
                                        ((PRIORITY) == DMA_PRIORITY_1)  || \
                                        ((PRIORITY) == DMA_PRIORITY_2)  || \
                                        ((PRIORITY) == DMA_PRIORITY_3)  || \
                                        ((PRIORITY) == DMA_PRIORITY_4)  || \
                                        ((PRIORITY) == DMA_PRIORITY_5))

#define IS_DMA_REQ_TYPE(VALUE)        (((VALUE) == DMA_REQ_TYPE_SRC ) || \
                                        ((VALUE) == DMA_REQ_TYPE_DST))

#define IS_DMA_REQ_NUM(VALUE)          (((VALUE) == DMA_REQ_NUM_0) || \
                                        ((VALUE) == DMA_REQ_NUM_1)  || \
                                        ((VALUE) == DMA_REQ_NUM_2)  || \
                                        ((VALUE) == DMA_REQ_NUM_3)  || \
                                        ((VALUE) == DMA_REQ_NUM_4)  || \
                                        ((VALUE) == DMA_REQ_NUM_5))

#define IS_DMA_REQ_FUNC(VALUE)         (((VALUE) <  DMA_REQ_FUNC_END) && ((VALUE) != 74U))

#define IS_DMA_BLOCK_MAX_LEN(VALUE)    (((VALUE) >=  1U) && ((VALUE) <= 4095U))

/**
  * @}
  */ 

/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_HAL_DMA_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

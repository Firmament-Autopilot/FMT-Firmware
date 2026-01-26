/**
  ******************************************************************************
  * @file    py32e407_ll_dma.h
  * @author  MCU Application Team
  * @brief   Header file of DMA LL module.
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
#ifndef __PY32E407_LL_DMA_H
#define __PY32E407_LL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */
#if defined (DMA1) || defined (DMA2)

/** @defgroup DMA_LL DMA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup DMA_LL_Private_Variables DMA Private Variables
  * @{
  */
/* Array used to get the DMA channel register offset versus channel index LL_DMA_CHANNEL_x */
static const uint32_t CHANNEL_OFFSET_TAB[] =
{
  (uint32_t)(DMA1_Channel1_BASE - DMA1_BASE),
  (uint32_t)(DMA1_Channel2_BASE - DMA1_BASE),
  (uint32_t)(DMA1_Channel3_BASE - DMA1_BASE),
  (uint32_t)(DMA1_Channel4_BASE - DMA1_BASE),
  (uint32_t)(DMA1_Channel5_BASE - DMA1_BASE),
  (uint32_t)(DMA1_Channel6_BASE - DMA1_BASE)
};
/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_ES_INIT DMA Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t SrcAddress;                /*!< Specifies the source address for DMA transfer.
                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t DstAddress;                /*!< Specifies the destination address for DMA transfer.
                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */
  
  uint32_t Direction;                 /*!< Specifies transfer direction.
                                           This parameter can be a value of @ref DMA_LL_EC_Data_transfer_direction */

  uint32_t SrcIncMode;                /*!< Specifies source address increment.
                                           This parameter can be a value of @ref DMA_LL_EC_Source_Address_Increment */
  
  uint32_t DstIncMode;                /*!< Specifies destination address increment.
                                           This parameter can be a value of @ref DMA_LL_EC_Destination_Address_Increment */
  
  uint32_t SrcWidth;                  /*!< Specifies source transfer width.
                                           This parameter can be a value of @ref DMA_LL_EC_Source_Transfer_Width */
  
  uint32_t DstWidth;                  /*!< Specifies destination transfer width.
                                           This parameter can be a value of @ref DMA_LL_EC_Destination_Transfer_Width */
  
  uint32_t SrcBurstLen;               /*!< Specifies source burst transaction length.
                                           This parameter can be a value of @ref DMA_LL_EC_Source_Burst_Transaction_Length */
  
  uint32_t DstBurstLen;               /*!< Specifies destination burst transaction length.
                                           This parameter can be a value of @ref DMA_LL_EC_Destination_Burst_Transaction_Length  */

  uint32_t SrcHandshakeType;          /*!< Specifies source handshake type.
                                           This parameter can be a value of @ref DMA_LL_EC_Source_Handshake_Type */
  
  uint32_t DstHandshakeType;          /*!< Specifies destination handshake type.
                                           This parameter can be a value of @ref DMA_LL_EC_Destination_Handshake_Type */
    
  uint32_t Priority;                  /*!< Specifies channel priority.
                                           This parameter can be a value of @ref DMA_LL_EC_Priority_level */

} LL_DMA_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_LL_EC_CHANNEL CHANNEL
  * @{
  */
#define LL_DMA_CHANNEL_1                  0x00000001U /*!< DMA Channel 1 */
#define LL_DMA_CHANNEL_2                  0x00000002U /*!< DMA Channel 2 */
#define LL_DMA_CHANNEL_3                  0x00000003U /*!< DMA Channel 3 */
#define LL_DMA_CHANNEL_4                  0x00000004U /*!< DMA Channel 4 */
#define LL_DMA_CHANNEL_5                  0x00000005U /*!< DMA Channel 5 */
#define LL_DMA_CHANNEL_6                  0x00000006U /*!< DMA Channel 6 */
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_ALL                0xFFFF0000U /*!< DMA Channel all (used only for function @ref LL_DMA_DeInit(). */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_EC_DMA_PERIPH DMA PERIPH
  * @{
  */
#define LL_SYSCFG_DMA_PERIPH_MAP_1       0x00000001U
#define LL_SYSCFG_DMA_PERIPH_MAP_2       0x00000002U
#define LL_SYSCFG_DMA_PERIPH_MAP_3       0x00000003U
#define LL_SYSCFG_DMA_PERIPH_MAP_4       0x00000004U
#define LL_SYSCFG_DMA_PERIPH_MAP_5       0x00000005U
#define LL_SYSCFG_DMA_PERIPH_MAP_6       0x00000006U
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_DMA_MAP DMA MAP
  * @{
  */
#define LL_SYSCFG_DMA_MAP_ADC1           0x00000000U
#define LL_SYSCFG_DMA_MAP_ADC2           0x00000001U
#define LL_SYSCFG_DMA_MAP_ADC3           0x00000002U
#define LL_SYSCFG_DMA_MAP_DAC1           0x00000003U
#define LL_SYSCFG_DMA_MAP_DAC2           0x00000004U
#define LL_SYSCFG_DMA_MAP_SPI1_RX        0x00000005U
#define LL_SYSCFG_DMA_MAP_SPI1_TX        0x00000006U
#define LL_SYSCFG_DMA_MAP_SPI2_RX        0x00000007U
#define LL_SYSCFG_DMA_MAP_SPI2_TX        0x00000008U
#define LL_SYSCFG_DMA_MAP_SPI3_RX        0x00000009U
#define LL_SYSCFG_DMA_MAP_SPI3_TX        0x0000000AU
#define LL_SYSCFG_DMA_MAP_USART1_RX      0x0000000BU
#define LL_SYSCFG_DMA_MAP_USART1_TX      0x0000000CU
#define LL_SYSCFG_DMA_MAP_USART2_RX      0x0000000DU
#define LL_SYSCFG_DMA_MAP_USART2_TX      0x0000000EU
#define LL_SYSCFG_DMA_MAP_USART3_RX      0x0000000FU
#define LL_SYSCFG_DMA_MAP_USART3_TX      0x00000010U
#define LL_SYSCFG_DMA_MAP_LPUART1_RX     0x00000011U
#define LL_SYSCFG_DMA_MAP_LPUART1_TX     0x00000012U
#define LL_SYSCFG_DMA_MAP_I2C1_RX        0x00000013U
#define LL_SYSCFG_DMA_MAP_I2C1_TX        0x00000014U
#define LL_SYSCFG_DMA_MAP_I2C2_RX        0x00000015U
#define LL_SYSCFG_DMA_MAP_I2C2_TX        0x00000016U
#define LL_SYSCFG_DMA_MAP_I2C3_RX        0x00000017U
#define LL_SYSCFG_DMA_MAP_I2C3_TX        0x00000018U
#define LL_SYSCFG_DMA_MAP_I2C4_RX        0x00000019U
#define LL_SYSCFG_DMA_MAP_I2C4_TX        0x0000001AU
#define LL_SYSCFG_DMA_MAP_TIM1_CH1       0x0000001BU
#define LL_SYSCFG_DMA_MAP_TIM1_CH2       0x0000001CU
#define LL_SYSCFG_DMA_MAP_TIM1_CH3       0x0000001DU
#define LL_SYSCFG_DMA_MAP_TIM1_CH4       0x0000001EU
#define LL_SYSCFG_DMA_MAP_TIM1_UP        0x0000001FU
#define LL_SYSCFG_DMA_MAP_TIM1_TRIG      0x00000020U
#define LL_SYSCFG_DMA_MAP_TIM1_COM       0x00000021U
#define LL_SYSCFG_DMA_MAP_TIM8_CH1       0x00000022U
#define LL_SYSCFG_DMA_MAP_TIM8_CH2       0x00000023U
#define LL_SYSCFG_DMA_MAP_TIM8_CH3       0x00000024U
#define LL_SYSCFG_DMA_MAP_TIM8_CH4       0x00000025U
#define LL_SYSCFG_DMA_MAP_TIM8_UP        0x00000026U
#define LL_SYSCFG_DMA_MAP_TIM8_TRIG      0x00000027U
#define LL_SYSCFG_DMA_MAP_TIM8_COM       0x00000028U
#define LL_SYSCFG_DMA_MAP_TIM6_UP        0x00000029U
#define LL_SYSCFG_DMA_MAP_TIM7_UP        0x0000002AU
#define LL_SYSCFG_DMA_MAP_TIM2_CH1       0x0000002BU
#define LL_SYSCFG_DMA_MAP_TIM2_CH2       0x0000002CU
#define LL_SYSCFG_DMA_MAP_TIM2_CH3       0x0000002DU
#define LL_SYSCFG_DMA_MAP_TIM2_CH4       0x0000002EU
#define LL_SYSCFG_DMA_MAP_TIM2_UP        0x0000002FU
#define LL_SYSCFG_DMA_MAP_TIM2_TRIG      0x00000030U
#define LL_SYSCFG_DMA_MAP_TIM3_CH1       0x00000031U
#define LL_SYSCFG_DMA_MAP_TIM3_CH2       0x00000032U
#define LL_SYSCFG_DMA_MAP_TIM3_CH3       0x00000033U
#define LL_SYSCFG_DMA_MAP_TIM3_CH4       0x00000034U
#define LL_SYSCFG_DMA_MAP_TIM3_UP        0x00000035U
#define LL_SYSCFG_DMA_MAP_TIM3_TRIG      0x00000036U
#define LL_SYSCFG_DMA_MAP_TIM4_CH1       0x00000037U
#define LL_SYSCFG_DMA_MAP_TIM4_CH2       0x00000038U
#define LL_SYSCFG_DMA_MAP_TIM4_CH3       0x00000039U
#define LL_SYSCFG_DMA_MAP_TIM4_CH4       0x0000003AU
#define LL_SYSCFG_DMA_MAP_TIM4_UP        0x0000003BU
#define LL_SYSCFG_DMA_MAP_TIM4_TRIG      0x0000003CU
#define LL_SYSCFG_DMA_MAP_TIM5_CH1       0x0000003DU
#define LL_SYSCFG_DMA_MAP_TIM5_CH2       0x0000003EU
#define LL_SYSCFG_DMA_MAP_TIM5_CH3       0x0000003FU
#define LL_SYSCFG_DMA_MAP_TIM5_CH4       0x00000040U
#define LL_SYSCFG_DMA_MAP_TIM5_UP        0x00000041U
#define LL_SYSCFG_DMA_MAP_TIM5_TRIG      0x00000042U
#define LL_SYSCFG_DMA_MAP_TIM18_CH1      0x00000043U
#define LL_SYSCFG_DMA_MAP_TIM18_CH2      0x00000044U
#define LL_SYSCFG_DMA_MAP_TIM18_CH3      0x00000045U
#define LL_SYSCFG_DMA_MAP_TIM18_CH4      0x00000046U
#define LL_SYSCFG_DMA_MAP_TIM18_UP       0x00000047U
#define LL_SYSCFG_DMA_MAP_TIM18_TRIG     0x00000048U
#define LL_SYSCFG_DMA_MAP_TIM15_CH1      0x00000049U
#define LL_SYSCFG_DMA_MAP_TIM15_UP       0x0000004BU
#define LL_SYSCFG_DMA_MAP_TIM15_TRIG     0x0000004CU
#define LL_SYSCFG_DMA_MAP_TIM15_COM      0x0000004DU
#define LL_SYSCFG_DMA_MAP_TIM16_CH1      0x0000004EU
#define LL_SYSCFG_DMA_MAP_TIM16_UP       0x0000004FU
#define LL_SYSCFG_DMA_MAP_TIM17_CH1      0x00000050U
#define LL_SYSCFG_DMA_MAP_TIM17_UP       0x00000051U
#define LL_SYSCFG_DMA_MAP_AES_IN         0x00000052U
#define LL_SYSCFG_DMA_MAP_AES_OUT        0x00000053U
#define LL_SYSCFG_DMA_MAP_Cordic_Read    0x00000054U
#define LL_SYSCFG_DMA_MAP_Cordic_Write   0x00000055U
#define LL_SYSCFG_DMA_MAP_ESMC_RX        0x00000056U
#define LL_SYSCFG_DMA_MAP_ESMC_TX        0x00000057U
#define LL_SYSCFG_DMA_MAP_SDIO           0x00000058U
#define LL_SYSCFG_DMA_MAP_UART1_RX       0x00000059U
#define LL_SYSCFG_DMA_MAP_UART1_TX       0x0000005AU
#define LL_SYSCFG_DMA_MAP_UART2_RX       0x0000005BU
#define LL_SYSCFG_DMA_MAP_UART2_TX       0x0000005CU
#define LL_SYSCFG_DMA_MAP_UART3_RX       0x0000005DU
#define LL_SYSCFG_DMA_MAP_UART3_TX       0x0000005EU
#define LL_SYSCFG_DMA_MAP_LCDC_TX        0x0000005FU

/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @{
  */
#define LL_DMA_MODE_NORMAL         0x00000000U                  /*!< Normal mode   */
#define LL_DMA_MODE_CIRCULAR       0x00000001U                  /*!< Circular mode */
/**
  * @}
  */



/** @defgroup DMA_LL_EC_Data_transfer_direction DMA Data transfer direction
  * @{
  */
#define LL_DMA_DIRECTION_MEMORY_TO_MEMORY         0x00000000U                       /*!< Memory to memory direction     */
#define LL_DMA_DIRECTION_MEMORY_TO_PERIPH         ((uint32_t)DMA_CH_CTRLL_TT_0)     /*!< Memory to peripheral direction */
#define LL_DMA_DIRECTION_PERIPH_TO_MEMORY         ((uint32_t)DMA_CH_CTRLL_TT_1)     /*!< Peripheral to memory direction */
#define LL_DMA_DIRECTION_PERIPH_TO_PERIPH         ((uint32_t)DMA_CH_CTRLL_TT)       /*!< Peripheral to Peripheral direction */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Source_Transfer_Width DMA Source Transfer Width
  * @{
  */
#define LL_DMA_SRC_WIDTH_BYTE         0x00000000U                                 /*!< Source transfer width is 8 bits     */
#define LL_DMA_SRC_WIDTH_HALFWORD     ((uint32_t)DMA_CH_CTRLL_SRC_TR_WIDTH_0)     /*!< Source transfer width is 16 bits     */
#define LL_DMA_SRC_WIDTH_WORD         ((uint32_t)DMA_CH_CTRLL_SRC_TR_WIDTH_1)     /*!< Source transfer width is 32 bits     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Destination_Transfer_Width DMA Destination Transfer Width
  * @{
  */
#define LL_DMA_DST_WIDTH_BYTE         0x00000000U                                 /*!< Destination transfer width is 8 bits     */
#define LL_DMA_DST_WIDTH_HALFWORD     ((uint32_t)DMA_CH_CTRLL_DST_TR_WIDTH_0)     /*!< Destination transfer width is 16 bits     */
#define LL_DMA_DST_WIDTH_WORD         ((uint32_t)DMA_CH_CTRLL_DST_TR_WIDTH_1)     /*!< Destination transfer width is 32 bits     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Source_Burst_Transaction_Length DMA Source Burst Transaction Length
  * @{
  */
#define LL_DMA_SRC_BURST_LEN_1         0x00000000U                                                           /*!< Number of data items to be transferred is 1     */
#define LL_DMA_SRC_BURST_LEN_4         ((uint32_t)DMA_CH_CTRLL_SRC_MSIZE_0)                                  /*!< Number of data items to be transferred is 4     */
#define LL_DMA_SRC_BURST_LEN_8         ((uint32_t)DMA_CH_CTRLL_SRC_MSIZE_1)                                  /*!< Number of data items to be transferred is 8     */
#define LL_DMA_SRC_BURST_LEN_16        ((uint32_t)(DMA_CH_CTRLL_SRC_MSIZE_1 | DMA_CH_CTRLL_SRC_MSIZE_0))     /*!< Number of data items to be transferred is 16     */
#define LL_DMA_SRC_BURST_LEN_32        ((uint32_t)DMA_CH_CTRLL_SRC_MSIZE_2)                                  /*!< Number of data items to be transferred is 32     */
#define LL_DMA_SRC_BURST_LEN_64        ((uint32_t)(DMA_CH_CTRLL_SRC_MSIZE_2 | DMA_CH_CTRLL_SRC_MSIZE_0))     /*!< Number of data items to be transferred is 64     */
#define LL_DMA_SRC_BURST_LEN_128       ((uint32_t)(DMA_CH_CTRLL_SRC_MSIZE_2 | DMA_CH_CTRLL_SRC_MSIZE_1))     /*!< Number of data items to be transferred is 128     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Destination_Burst_Transaction_Length DMA Destination Burst Transaction Length
  * @{
  */
#define LL_DMA_DST_BURST_LEN_1         0x00000000U                                                           /*!< Number of data items to be transferred is 1     */
#define LL_DMA_DST_BURST_LEN_4         ((uint32_t)DMA_CH_CTRLL_DST_MSIZE_0)                                  /*!< Number of data items to be transferred is 4     */
#define LL_DMA_DST_BURST_LEN_8         ((uint32_t)DMA_CH_CTRLL_DST_MSIZE_1)                                  /*!< Number of data items to be transferred is 8     */
#define LL_DMA_DST_BURST_LEN_16        ((uint32_t)(DMA_CH_CTRLL_DST_MSIZE_1 | DMA_CH_CTRLL_DST_MSIZE_0))     /*!< Number of data items to be transferred is 16     */
#define LL_DMA_DST_BURST_LEN_32        ((uint32_t)DMA_CH_CTRLL_DST_MSIZE_2)                                  /*!< Number of data items to be transferred is 32     */
#define LL_DMA_DST_BURST_LEN_64        ((uint32_t)(DMA_CH_CTRLL_DST_MSIZE_2 | DMA_CH_CTRLL_DST_MSIZE_0))     /*!< Number of data items to be transferred is 64     */
#define LL_DMA_DST_BURST_LEN_128       ((uint32_t)(DMA_CH_CTRLL_DST_MSIZE_2 | DMA_CH_CTRLL_DST_MSIZE_1))     /*!< Number of data items to be transferred is 128     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Source_Address_Increment Source Address Increment
  * @{
  */
#define LL_DMA_SRC_ADDR_INC            0x00000000U                       /*!< Increments the source address     */
#define LL_DMA_SRC_ADDR_DEC            ((uint32_t)DMA_CH_CTRLL_SINC_0)   /*!< Decrements the source address     */
#define LL_DMA_SRC_ADDR_FIX            ((uint32_t)DMA_CH_CTRLL_SINC_1)   /*!< No change in the source address     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Destination_Address_Increment Destination Address Increment
  * @{
  */
#define LL_DMA_DST_ADDR_INC            0x00000000U                       /*!< Increments the destination address     */
#define LL_DMA_DST_ADDR_DEC            ((uint32_t)DMA_CH_CTRLL_DINC_0)   /*!< Decrements the destination address     */
#define LL_DMA_DST_ADDR_FIX            ((uint32_t)DMA_CH_CTRLL_DINC_1)   /*!< No change in the destination address     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Source_Handshake_Type Source Handshake Type
  * @{
  */
#define LL_DMA_SRC_HANDSHAKE_TYPE_HARD         0x00000000U                         /*!< Select hardware handshake for source    */
#define LL_DMA_SRC_HANDSHAKE_TYPE_SOFT         ((uint32_t)DMA_CH_CFGL_HS_SEL_SRC)  /*!< Select software handshake for source    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Destination_Handshake_Type Destination Handshake Type
  * @{
  */
#define LL_DMA_DST_HANDSHAKE_TYPE_HARD         0x00000000U                         /*!< Select hardware handshake for destination    */
#define LL_DMA_DST_HANDSHAKE_TYPE_SOFT         ((uint32_t)DMA_CH_CFGL_HS_SEL_DST)  /*!< Select software handshake for destination    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_Priority_level DMA Priority level
  * @{
  */
#define LL_DMA_PRIORITY_0             0x00000000U
#define LL_DMA_PRIORITY_1             ((uint32_t)DMA_CH_CFGL_CH_PRIOR_0)
#define LL_DMA_PRIORITY_2             ((uint32_t)DMA_CH_CFGL_CH_PRIOR_1)
#define LL_DMA_PRIORITY_3             ((uint32_t)(DMA_CH_CFGL_CH_PRIOR_1 | DMA_CH_CFGL_CH_PRIOR_0))
#define LL_DMA_PRIORITY_4             ((uint32_t)DMA_CH_CFGL_CH_PRIOR_2)
#define LL_DMA_PRIORITY_5             ((uint32_t)(DMA_CH_CFGL_CH_PRIOR_2 | DMA_CH_CFGL_CH_PRIOR_0))
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DST_PERIPH Destination Periph
  * @{
  */
#define LL_DMA_DST_PERIPH_MAP_1          0x00000000U                                                    /*!< Destination hardware interface to requst 0    */
#define LL_DMA_DST_PERIPH_MAP_2         ((uint32_t)DMA_CH_CFGH_DST_PER_0)                               /*!< Destination hardware interface to requst 1    */
#define LL_DMA_DST_PERIPH_MAP_3         ((uint32_t)DMA_CH_CFGH_DST_PER_1)                               /*!< Destination hardware interface to requst 2    */
#define LL_DMA_DST_PERIPH_MAP_4         ((uint32_t)(DMA_CH_CFGH_DST_PER_1 | DMA_CH_CFGH_DST_PER_0))     /*!< Destination hardware interface to requst 3    */
#define LL_DMA_DST_PERIPH_MAP_5         ((uint32_t)DMA_CH_CFGH_DST_PER_2)                               /*!< Destination hardware interface to requst 4    */
#define LL_DMA_DST_PERIPH_MAP_6         ((uint32_t)(DMA_CH_CFGH_DST_PER_2 | DMA_CH_CFGH_DST_PER_0))     /*!< Destination hardware interface to requst 5    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_SRC_PERIPH Source Periph
  * @{
  */
#define LL_DMA_SRC_PERIPH_MAP_1          0x00000000U                                                    /*!< Source hardware interface to requst 0   */
#define LL_DMA_SRC_PERIPH_MAP_2         ((uint32_t)DMA_CH_CFGH_SRC_PER_0)                               /*!< Source hardware interface to requst 1   */
#define LL_DMA_SRC_PERIPH_MAP_3         ((uint32_t)DMA_CH_CFGH_SRC_PER_1)                               /*!< Source hardware interface to requst 2    */
#define LL_DMA_SRC_PERIPH_MAP_4         ((uint32_t)(DMA_CH_CFGH_SRC_PER_1 | DMA_CH_CFGH_SRC_PER_0))     /*!< Source hardware interface to requst 3   */
#define LL_DMA_SRC_PERIPH_MAP_5         ((uint32_t)DMA_CH_CFGH_SRC_PER_2)                               /*!< Source hardware interface to requst 4   */
#define LL_DMA_SRC_PERIPH_MAP_6         ((uint32_t)(DMA_CH_CFGH_SRC_PER_2 | DMA_CH_CFGH_SRC_PER_0))     /*!< Source hardware interface to requst 5   */
/**
  * @}
  */



/** @defgroup DMA_LL_EC_FIFO_Mode DMA FIFO mode
  * @{
  */
#define LL_DMA_FIFO_MODE_0             0x00000000U                        /*!< Space/data available for single
                                                                            AHB transfer of the specified transfer width    */
#define LL_DMA_FIFO_MODE_1             ((uint32_t)DMA_CH_CFGH_FIFO_MODE)  /*!< Data available is greater than or
                                                                            equal to half the FIFO depth for destination transfers and
                                                                            space available is greater than half the fifo depth for
                                                                            source transfers.     */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Macros DMA Exported Macros
  * @{
  */

/** @defgroup DMA_LL_EM_WRITE_READ Common Write and read registers macros
  * @{
  */
/**
  * @brief  Write a value in DMA register
  * @param  __INSTANCE__ DMA Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_DMA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in DMA register
  * @param  __INSTANCE__ DMA Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_DMA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup DMA_LL_EM_CONVERT_DMAxCHANNELy Convert DMAxChannely
  * @{
  */

/**
  * @brief  Convert DMAx_Channely into DMAx
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval DMAx
  */
#if defined(DMA2)
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) > ((uint32_t)DMA1_Channel6)) ?  DMA2 : DMA1)
#else
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)  (DMA1)
#endif

/**
  * @brief  Convert DMAx_Channely into LL_DMA_CHANNEL_y
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval LL_DMA_CHANNEL_y
  */
#if defined (DMA2)
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel5)) ? LL_DMA_CHANNEL_5 : \
 LL_DMA_CHANNEL_6)
#else
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
 LL_DMA_CHANNEL_6)
#endif

/**
  * @brief  Convert DMA Instance DMAx and LL_DMA_CHANNEL_y into DMAx_Channely
  * @param  __DMA_INSTANCE__ DMAx
  * @param  __CHANNEL__ LL_DMA_CHANNEL_y
  * @retval DMAx_Channely
  */
#if defined (DMA2)
#define __LL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA1_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA2_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA1_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA2_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA1_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA2_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA1_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA2_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA1_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA2_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_6))) ? DMA1_Channel6 : \
 DMA2_Channel6)
#else
#define __LL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA1_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA1_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA1_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA1_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA1_Channel5 : \
 DMA1_Channel6)
#endif

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Functions DMA Exported Functions
 * @{
 */

/** @defgroup DMA_LL_EF_Configuration Configuration
  * @{
  */
/**
  * @brief  Enable DMA.
  * @rmtoll EN          DMA_EN            LL_DMA_Enable
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_Enable(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->EN, DMA_EN_DMA_EN);
}

/**
  * @brief  Disable DMA.
  * @rmtoll EN          DMA_EN            LL_DMA_Disable
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_Disable(DMA_TypeDef *DMAx)
{
  CLEAR_BIT(DMAx->EN, DMA_EN_DMA_EN);
}

/**
  * @brief  Check if DMA is enabled or disabled.
  * @rmtoll EN          DMA_EN            LL_DMA_IsEnabled
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabled(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->EN, DMA_EN_DMA_EN) == (DMA_EN_DMA_EN));
}

/**
  * @brief  Enable DMA channel.
  * @rmtoll CH_EN         CH_EN            LL_DMA_EnableChannel
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->CH_EN, ((DMA_CH_EN_CH_EN_WE_0 | DMA_CH_EN_CH_EN_0) << (Channel - 1U)));
}

/**
  * @brief  Disable DMA channel.
  * @rmtoll CH_EN          CH_EN            LL_DMA_DisableChannel
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->CH_EN, ((DMA_CH_EN_CH_EN_0 | DMA_CH_EN_CH_EN_WE_0) << (Channel - 1U)), \
                                                           (DMA_CH_EN_CH_EN_WE_0 << (Channel - 1U)));
}

/**
  * @brief  Check if DMA channel is enabled or disabled.
  * @rmtoll CH_EN          CH_EN            LL_DMA_IsEnabledChannel
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->CH_EN, (DMA_CH_EN_CH_EN_0 << (Channel - 1U))) == (DMA_CH_EN_CH_EN_0 << (Channel - 1U)));
}

/**
  * @brief  Configure all parameters link to DMA transfer.
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Configuration This parameter must be a combination of all the following values:
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY or @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH or @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY
  *         @arg @ref LL_DMA_DST_ADDR_INC or @ref LL_DMA_DST_ADDR_DEC or @ref LL_DMA_DST_ADDR_FIX
  *         @arg @ref LL_DMA_SRC_ADDR_INC or @ref LL_DMA_SRC_ADDR_DEC or @ref LL_DMA_SRC_ADDR_FIX
  *         @arg @ref LL_DMA_DST_WIDTH_BYTE or @ref LL_DMA_DST_WIDTH_HALFWORD or @ref LL_DMA_DST_WIDTH_WORD
  *         @arg @ref LL_DMA_SRC_WIDTH_BYTE or @ref LL_DMA_SRC_WIDTH_HALFWORD or @ref LL_DMA_SRC_WIDTH_WORD
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ConfigTransfer(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Configuration)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_TT | DMA_CH_CTRLL_SINC | DMA_CH_CTRLL_DINC | DMA_CH_CTRLL_SRC_TR_WIDTH | DMA_CH_CTRLL_DST_TR_WIDTH ,
             Configuration);
}

/**
  * @brief  Set Data transfer direction.
  * @rmtoll CH_CTRLL         TT            LL_DMA_SetDataTransferDirection
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_PERIPH
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDataTransferDirection(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Direction)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_TT, Direction);
}

/**
  * @brief  Get Data transfer direction.
  * @rmtoll CH_CTRLL         TT            LL_DMA_GetDataTransferDirection
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_PERIPH
  */
__STATIC_INLINE uint32_t LL_DMA_GetDataTransferDirection(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_TT));
}

/**
  * @brief  Set source burst transaction length.
  * @rmtoll CH_CTRLL         SRC_MSIZE            LL_DMA_SetSrcBurstLen
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Length This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_BURST_LEN_1  
  *         @arg @ref LL_DMA_SRC_BURST_LEN_4  
  *         @arg @ref LL_DMA_SRC_BURST_LEN_8  
  *         @arg @ref LL_DMA_SRC_BURST_LEN_16 
  *         @arg @ref LL_DMA_SRC_BURST_LEN_32 
  *         @arg @ref LL_DMA_SRC_BURST_LEN_64 
  *         @arg @ref LL_DMA_SRC_BURST_LEN_128
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetSrcBurstLen(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Length)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_SRC_MSIZE, Length);
}

/**
  * @brief  Get source burst transaction length.
  * @rmtoll CH_CTRLL         SRC_MSIZE            LL_DMA_GetSrcBurstLen
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_BURST_LEN_1  
  *         @arg @ref LL_DMA_SRC_BURST_LEN_4  
  *         @arg @ref LL_DMA_SRC_BURST_LEN_8  
  *         @arg @ref LL_DMA_SRC_BURST_LEN_16 
  *         @arg @ref LL_DMA_SRC_BURST_LEN_32 
  *         @arg @ref LL_DMA_SRC_BURST_LEN_64 
  *         @arg @ref LL_DMA_SRC_BURST_LEN_128
  */
__STATIC_INLINE uint32_t LL_DMA_GetSrcBurstLen(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_SRC_MSIZE));
}

/**
  * @brief  Set destination burst transaction length.
  * @rmtoll CH_CTRLL         DST_MSIZE            LL_DMA_SetDstBurstLen
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Length This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_BURST_LEN_1  
  *         @arg @ref LL_DMA_DST_BURST_LEN_4  
  *         @arg @ref LL_DMA_DST_BURST_LEN_8  
  *         @arg @ref LL_DMA_DST_BURST_LEN_16 
  *         @arg @ref LL_DMA_DST_BURST_LEN_32 
  *         @arg @ref LL_DMA_DST_BURST_LEN_64 
  *         @arg @ref LL_DMA_DST_BURST_LEN_128
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDstBurstLen(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Length)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_DST_MSIZE, Length);
}

/**
  * @brief  Get destination burst transaction length.
  * @rmtoll CH_CTRLL         DST_MSIZE            LL_DMA_GetDstcBurstLen
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_BURST_LEN_1  
  *         @arg @ref LL_DMA_DST_BURST_LEN_4  
  *         @arg @ref LL_DMA_DST_BURST_LEN_8  
  *         @arg @ref LL_DMA_DST_BURST_LEN_16 
  *         @arg @ref LL_DMA_DST_BURST_LEN_32 
  *         @arg @ref LL_DMA_DST_BURST_LEN_64 
  *         @arg @ref LL_DMA_DST_BURST_LEN_128
  */
__STATIC_INLINE uint32_t LL_DMA_GetDstBurstLen(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
             DMA_CH_CTRLL_DST_MSIZE));
}

/**
  * @brief  Set source increment mode.
  * @rmtoll CH_CTRLL         CTRLL_SINC            LL_DMA_SetSrcIncMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  IncMode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_ADDR_INC
  *         @arg @ref LL_DMA_SRC_ADDR_DEC
  *         @arg @ref LL_DMA_SRC_ADDR_FIX
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetSrcIncMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t IncMode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL, DMA_CH_CTRLL_SINC,
             IncMode);
}

/**
  * @brief  Get source increment mode.
  * @rmtoll CH_CTRLL         CTRLL_SINC            LL_DMA_GetSrcIncMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_ADDR_INC
  *         @arg @ref LL_DMA_SRC_ADDR_DEC
  *         @arg @ref LL_DMA_SRC_ADDR_FIX
  */
__STATIC_INLINE uint32_t LL_DMA_GetSrcIncMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
                   DMA_CH_CTRLL_SINC));
}

/**
  * @brief  Set destination increment mode.
  * @rmtoll CH_CTRLL         DINC            LL_DMA_SetDstIncMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  IncMode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_ADDR_INC
  *         @arg @ref LL_DMA_DST_ADDR_DEC
  *         @arg @ref LL_DMA_DST_ADDR_FIX
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDstIncMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t IncMode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL, DMA_CH_CTRLL_DINC,
             IncMode);
}

/**
  * @brief  Get destination increment mode.
  * @rmtoll CH_CTRLL         DINC            LL_DMA_GetDstIncMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_ADDR_INC
  *         @arg @ref LL_DMA_DST_ADDR_DEC
  *         @arg @ref LL_DMA_DST_ADDR_FIX
  */
__STATIC_INLINE uint32_t LL_DMA_GetDstIncMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
                   DMA_CH_CTRLL_DINC));
}

/**
  * @brief  Set Source transfer bit width.
  * @rmtoll CH_CTRLL         SRC_TR_WIDTH            LL_DMA_SetSrcWidth
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Width This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_WIDTH_BYTE    
  *         @arg @ref LL_DMA_SRC_WIDTH_HALFWORD
  *         @arg @ref LL_DMA_SRC_WIDTH_WORD    
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetSrcWidth(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Width)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL, DMA_CH_CTRLL_SRC_TR_WIDTH,
             Width);
}

/**
  * @brief  Get Source transfer bit width.
  * @rmtoll CH_CTRLL         SRC_TR_WIDTH            LL_DMA_GetSrcWidth
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_WIDTH_BYTE    
  *         @arg @ref LL_DMA_SRC_WIDTH_HALFWORD
  *         @arg @ref LL_DMA_SRC_WIDTH_WORD  
  */
__STATIC_INLINE uint32_t LL_DMA_GetSrcWidth(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
                   DMA_CH_CTRLL_SRC_TR_WIDTH));
}

/**
  * @brief  Set destination transfer bit width.
  * @rmtoll CH_CTRLL         DST_TR_WIDTH            LL_DMA_SetDstWidth
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Width This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_WIDTH_BYTE    
  *         @arg @ref LL_DMA_DST_WIDTH_HALFWORD
  *         @arg @ref LL_DMA_DST_WIDTH_WORD    
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDstWidth(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Width)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL, DMA_CH_CTRLL_DST_TR_WIDTH,
             Width);
}

/**
  * @brief  Get destination transfer bit width.
  * @rmtoll CH_CTRLL         DST_TR_WIDTH            LL_DMA_GetDstWidth
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_WIDTH_BYTE    
  *         @arg @ref LL_DMA_DST_WIDTH_HALFWORD
  *         @arg @ref LL_DMA_DST_WIDTH_WORD    
  */
__STATIC_INLINE uint32_t LL_DMA_GetDstWidth(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
                   DMA_CH_CTRLL_DST_TR_WIDTH));
}

/**
  * @brief  Set the Block length.
  * @rmtoll CH_CTRLH         CH_CTRLH            LL_DMA_SetBlockLength
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  BlockLength Between Min_Data = 0 and Max_Data = 0xFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetBlockLength(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t BlockLength)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLH, BlockLength);
}

/**
  * @brief  Get the Block length.
  * @rmtoll CH_CTRLH         CH_CTRLH            LL_DMA_GetBlockLength
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Between Min_Data = 0 and Max_Data = 0xFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetBlockLength(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLH));
}


/**
  * @brief  Enable destination Reload.
  * @rmtoll CH_CFGL         RELOAD_DST            LL_DMA_EnableDstReload
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableDstReload(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_RELOAD_DST);
}

/**
  * @brief  Disable destination Reload.
  * @rmtoll CH_CFGL         RELOAD_DST            LL_DMA_DisableDstReload
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  */
__STATIC_INLINE void LL_DMA_DisableDstReload(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_RELOAD_DST);
}

/**
  * @brief  Check if destination reload is enabled.
  * @rmtoll CH_CFGL          RELOAD_DST          LL_DMA_IsEnabledDstReload
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledDstReload(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
             DMA_CH_CFGL_RELOAD_DST) == DMA_CH_CFGL_RELOAD_DST );
}

/**
  * @brief  Enable source Reload.
  * @rmtoll CH_CFGL         RELOAD_SRC            LL_DMA_EnableSrcReload
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableSrcReload(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_RELOAD_SRC);
}

/**
  * @brief  Disable source Reload.
  * @rmtoll CH_CFGL         RELOAD_SRC            LL_DMA_DisableSrcReload
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  */
__STATIC_INLINE void LL_DMA_DisableSrcReload(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_RELOAD_SRC);
}

/**
  * @brief  Check if source reload is enabled.
  * @rmtoll CH_CFGL          RELOAD_SRC          LL_DMA_IsEnabledSrcReload
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledSrcReload(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
             DMA_CH_CFGL_RELOAD_SRC) == DMA_CH_CFGL_RELOAD_SRC );
}

/**
  * @brief  Set Max AMBA Burst Length.
  * @rmtoll CH_CFGL         MAX_ABRST            LL_DMA_SetMaxAMBABurstLength
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Length Between Min_Data = 0 and Max_Data = 0xFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetMaxAMBABurstLength(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Length)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,DMA_CH_CFGL_MAX_ABRST, Length<<DMA_CH_CFGL_MAX_ABRST_Pos);
}

/**
  * @brief  Get Max AMBA Burst Length.
  * @rmtoll CH_CFGL         MAX_ABRST            LL_DMA_GetMaxAMBABurstLength
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Between Min_Data = 0 and Max_Data = 0xFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetMaxAMBABurstLength(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,DMA_CH_CFGL_MAX_ABRST);
}

/**
  * @brief  Set source Handshake Type.
  * @rmtoll CH_CFGL         HS_SEL_SRC            LL_DMA_SetSrcHandshakeType
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Type This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_HANDSHAKE_TYPE_HARD   
  *         @arg @ref LL_DMA_SRC_HANDSHAKE_TYPE_SOFT
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetSrcHandshakeType(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Type)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_HS_SEL_SRC,
             Type);
}

/**
  * @brief  Get source Handshake Type.
  * @rmtoll CH_CFGL         HS_SEL_SRC            LL_DMA_GetSrcHandshakeType
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_HANDSHAKE_TYPE_HARD   
  *         @arg @ref LL_DMA_SRC_HANDSHAKE_TYPE_SOFT 
  */
__STATIC_INLINE uint32_t LL_DMA_GetSrcHandshakeType(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
                   DMA_CH_CFGL_HS_SEL_SRC);
}


/**
  * @brief  Set dest Handshake Type.
  * @rmtoll CH_CFGL         HS_SEL_DST            LL_DMA_SetDstHandshakeType
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Type This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_HANDSHAKE_TYPE_HARD   
  *         @arg @ref LL_DMA_DST_HANDSHAKE_TYPE_SOFT
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDstHandshakeType(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Type)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_HS_SEL_DST,
             Type);
}

/**
  * @brief  Get dest Handshake Type.
  * @rmtoll CH_CFGL         HS_SEL_DST            LL_DMA_GetDstHandshakeType
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_HANDSHAKE_TYPE_HARD   
  *         @arg @ref LL_DMA_DST_HANDSHAKE_TYPE_SOFT
  */
__STATIC_INLINE uint32_t LL_DMA_GetDstHandshakeType(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
                   DMA_CH_CFGL_HS_SEL_DST));
}

/**
  * @brief  Enable Channel Suspend.
  * @rmtoll CH_CFGL         CH_SUSP            LL_DMA_EnableChannelSuspend
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableChannelSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_CH_SUSP);
}

/**
  * @brief  Disable Channel Suspend.
  * @rmtoll CH_CFGL         CH_SUSP            LL_DMA_DisableChannelSuspend
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  */
__STATIC_INLINE void LL_DMA_DisableChannelSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_CH_SUSP);
}


/**
  * @brief  Check if Channel Suspend is enabled.
  * @rmtoll CH_CFGL          CH_SUSP          LL_DMA_IsEnabledChannelSuspend
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledChannelSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
             DMA_CH_CFGL_CH_SUSP) == DMA_CH_CFGL_CH_SUSP );
}

/**
  * @brief  Set Channel priority level.
  * @rmtoll CH_CFGL          CH_PRIOR            LL_DMA_SetChannelPriorityLevel
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Priority This parameter can be one of the following values:
  *         @arg @ref LL_DMA_PRIORITY_0
  *         @arg @ref LL_DMA_PRIORITY_1
  *         @arg @ref LL_DMA_PRIORITY_2
  *         @arg @ref LL_DMA_PRIORITY_3
  *         @arg @ref LL_DMA_PRIORITY_4
  *         @arg @ref LL_DMA_PRIORITY_5
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Priority)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_CH_PRIOR,
             Priority);
}

/**
  * @brief  Get Channel priority level.
  * @rmtoll CH_CFGL          CH_PRIOR            LL_DMA_GetChannelPriorityLevel
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_PRIORITY_0
  *         @arg @ref LL_DMA_PRIORITY_1
  *         @arg @ref LL_DMA_PRIORITY_2
  *         @arg @ref LL_DMA_PRIORITY_3
  *         @arg @ref LL_DMA_PRIORITY_4
  *         @arg @ref LL_DMA_PRIORITY_5
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
                   DMA_CH_CFGL_CH_PRIOR));
}

/**
  * @brief  Enable Interrupt Suspend.
  * @rmtoll CH_CFGL         INT_SUSP            LL_DMA_EnableInterruptSuspend
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  */
__STATIC_INLINE void LL_DMA_EnableInterruptSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_INT_SUSP);
}

/**
  * @brief  Disable Interrupt Suspend.
  * @rmtoll CH_CFGL         INT_SUSP            LL_DMA_DisableInterruptSuspend
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  */
__STATIC_INLINE void LL_DMA_DisableInterruptSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL, DMA_CH_CFGL_INT_SUSP);
}

/**
  * @brief  Check if Interrupt Suspend is enabled.
  * @rmtoll CH_CFGL          INT_SUSP          LL_DMA_IsEnabledInterruptSuspend
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledInterruptSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGL,
             DMA_CH_CFGL_INT_SUSP) == DMA_CH_CFGL_INT_SUSP );
}

/**
  * @brief  Set FIFO Mode .
  * @rmtoll CH_CFGH         FIFO_MODE            LL_DMA_SetFIFOMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_FIFO_MODE_0   
  *         @arg @ref LL_DMA_FIFO_MODE_1
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetFIFOMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Mode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGH, DMA_CH_CFGH_FIFO_MODE,
             Mode);
}

/**
  * @brief  Get FIFO Mode.
  * @rmtoll CH_CFGH         FIFO_MODE            LL_DMA_GetFIFOMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_FIFO_MODE_0   
  *         @arg @ref LL_DMA_FIFO_MODE_1  
  */
__STATIC_INLINE uint32_t LL_DMA_GetFIFOMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGH,
                   DMA_CH_CFGH_FIFO_MODE));
}

/**
  * @brief  Set DST Periph Map.
  * @rmtoll CH_CFGH         DST_PER            LL_DMA_SetDstPeriphMap
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  PeriphMap This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_1   
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_2  
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_3  
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_4  
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_5 
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_6 
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDstPeriphMap(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphMap)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGH, DMA_CH_CFGH_DST_PER,
             PeriphMap);
}

/**
  * @brief  Get DST Periph Map.
  * @rmtoll CH_CFGH         DST_PER            LL_DMA_GetDstPeriphMap
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_1   
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_2  
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_3  
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_4  
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_5 
  *         @arg @ref LL_DMA_DST_PERIPH_MAP_6 
  */
__STATIC_INLINE uint32_t LL_DMA_GetDstPeriphMap(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGH,
                   DMA_CH_CFGH_DST_PER));
}


/**
  * @brief  Set SRC Periph Map.
  * @rmtoll CH_CFGH         SRC_PER            LL_DMA_SetSrcPeriphMap
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  PeriphMap This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_1   
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_2  
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_3  
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_4  
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_5 
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_6 
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetSrcPeriphMap(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphMap)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGH, DMA_CH_CFGH_SRC_PER,
             PeriphMap);
}

/**
  * @brief  Get SRC Periph Map.
  * @rmtoll CH_CFGH         SRC_PER            LL_DMA_GetSrcPeriphMap
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_1   
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_2  
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_3  
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_4  
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_5 
  *         @arg @ref LL_DMA_SRC_PERIPH_MAP_6 
  */
__STATIC_INLINE uint32_t LL_DMA_GetSrcPeriphMap(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CFGH,
                   DMA_CH_CFGH_SRC_PER));
}

/**
  * @brief  Configure the Source and Destination addresses.
  * @note   This API must not be called when the DMA channel is enabled.
  * @note   Each IP using DMA provides an API to get directly the register adress (LL_PPP_DMA_GetRegAddr).
  * @rmtoll SA         SA            LL_DMA_ConfigAddresses\n
  *         DA         DA            LL_DMA_ConfigAddresses
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  SrcAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @param  DstAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ConfigAddresses(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress,
                                            uint32_t DstAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->SA, SrcAddress);
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->DA, DstAddress);
}

/**
  * @brief  Set the Src address.
  * @rmtoll SA         SA            LL_DMA_SetSRCAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  SrcAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->SA, SrcAddress);
}

/**
  * @brief  Set the Dst address.
  * @rmtoll DA         DA            LL_DMA_SetDSTAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @param  DstAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDstAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t DstAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->DA, DstAddress);
}

/**
  * @brief  Get Src address.
  * @rmtoll SA         SA            LL_DMA_GetSrcAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->SA));
}

/**
  * @brief  Get Dst address.
  * @rmtoll DA         DA            LL_DMA_GetDstAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetDstAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->DA));
}

/**
  * @brief  Enable Src Request.
  * @rmtoll REQSRC          SRC_REQ          LL_DMA_EnableSrcRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableSrcRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->REQSRC, (DMA_REQSRC_SRC_REQ_0 | DMA_REQSRC_SRC_REQ_WE_0) << (Channel-1) );
}

/**
  * @brief  Disable Src Request.
  * @rmtoll REQSRC          SRC_REQ          LL_DMA_DisableSrcRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableSrcRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->REQSRC,(DMA_REQSRC_SRC_REQ_0 | DMA_REQSRC_SRC_REQ_WE_0)<<(Channel-1),DMA_REQSRC_SRC_REQ_WE_0<<(Channel-1));
}

/**
  * @brief  Check if Src Request is enabled.
  * @rmtoll REQSRC          SRC_REQ          LL_DMA_IsEnabledSrcRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledSrcRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->REQSRC, DMA_REQSRC_SRC_REQ_0<<(Channel-1)) == (DMA_REQSRC_SRC_REQ_0<<(Channel-1)));
}

/**
  * @brief  Enable Dst Request.
  * @rmtoll REQDST          DST_REQ          LL_DMA_EnableDstRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableDstRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->REQDST, (DMA_REQDST_DST_REQ_0 | DMA_REQDST_DST_REQ_WE_0) << (Channel-1));
}

/**
  * @brief  Disable Dst request.
  * @rmtoll REQDST          DST_REQ          LL_DMA_DisableDstRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableDstRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->REQDST,(DMA_REQDST_DST_REQ_0 | DMA_REQDST_DST_REQ_WE_0)<<(Channel-1),DMA_REQDST_DST_REQ_WE_0<<(Channel-1));
}

/**
  * @brief  Check if Dest Request is enabled.
  * @rmtoll REQDST          DST_REQ          LL_DMA_IsEnabledDstRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledDstRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->REQDST, DMA_REQDST_DST_REQ_0<<(Channel-1)) == (DMA_REQDST_DST_REQ_0<<(Channel-1)));
}

/**
  * @brief  Enable Src Single Request.
  * @rmtoll SGLRQSRC          SRC_SGLREQ          LL_DMA_EnableSrcSingleRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableSrcSingleRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->SGLRQSRC, (DMA_SGLRQSRC_SRC_SGLREQ_0 | DMA_SGLRQSRC_SRC_SGLREQ_WE_0) << (Channel-1) );
}

/**
  * @brief  Disable Src Single Request.
  * @rmtoll SGLRQSRC          SRC_SGLREQ          LL_DMA_DisableSrcSingleRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableSrcSingleRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->SGLRQSRC,(DMA_SGLRQSRC_SRC_SGLREQ_0 | DMA_SGLRQSRC_SRC_SGLREQ_WE_0)<<(Channel-1),DMA_SGLRQSRC_SRC_SGLREQ_WE_0<<(Channel-1));
}

/**
  * @brief  Check if Src Single Request is enabled.
  * @rmtoll SGLRQSRC          SRC_SGLREQ          LL_DMA_IsEnabledSrcSingleRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledSrcSingleRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->SGLRQSRC, DMA_SGLRQSRC_SRC_SGLREQ_0<<(Channel-1)) == (DMA_SGLRQSRC_SRC_SGLREQ_0<<(Channel-1)));
}

/**
  * @brief  Enable Dst Single Request.
  * @rmtoll SGLRQDST          DST_SGLREQ          LL_DMA_EnableDstSingleRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableDstSingleRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->SGLRQDST, (DMA_SGLRQDST_DST_SGLREQ_0 | DMA_SGLRQDST_DST_SGLREQ_WE_0) << (Channel-1) );
}

/**
  * @brief  Disable Dst Single Request.
  * @rmtoll SGLRQDST          DST_SGLREQ          LL_DMA_DisableDstSingleRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableDstSingleRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->SGLRQDST,(DMA_SGLRQDST_DST_SGLREQ_0 | DMA_SGLRQDST_DST_SGLREQ_WE_0)<<(Channel-1),DMA_SGLRQDST_DST_SGLREQ_WE_0<<(Channel-1));
}

/**
  * @brief  Check if Dst TSingle Request is enabled.
  * @rmtoll SGLRQDST          DST_SGLREQ          LL_DMA_IsEnabledDstSingleRequest
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledDstSingleRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->SGLRQDST, DMA_SGLRQDST_DST_SGLREQ_0<<(Channel-1)) == (DMA_SGLRQDST_DST_SGLREQ_0<<(Channel-1)));
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_FLAG_Management FLAG Management
  * @{
  */

/**
  * @brief  Get Channel 1 transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSTFR, DMA_STATUSTFR_STATUS_0) == DMA_STATUSTFR_STATUS_0);
}

/**
  * @brief  Get Channel 2 transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSTFR, DMA_STATUSTFR_STATUS_1) == DMA_STATUSTFR_STATUS_1);
}

/**
  * @brief  Get Channel 3 transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSTFR, DMA_STATUSTFR_STATUS_2) == DMA_STATUSTFR_STATUS_2);
}

/**
  * @brief  Get Channel 4 transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSTFR, DMA_STATUSTFR_STATUS_3) == DMA_STATUSTFR_STATUS_3);
}

/**
  * @brief  Get Channel 5 transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSTFR, DMA_STATUSTFR_STATUS_4) == DMA_STATUSTFR_STATUS_4);
}

/**
  * @brief  Get Channel 6 transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSTFR, DMA_STATUSTFR_STATUS_5) == DMA_STATUSTFR_STATUS_5);
}

/**
  * @brief  Get one of channls transfer complete flag.
  * @rmtoll STATUSTFR          STATUS         LL_DMA_IsActiveFlag_TFR6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TFR(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSINT, DMA_STATUSINT_TFR) == DMA_STATUSINT_TFR);
}

/**
  * @brief  Get Channel 1 block transfer complete flag.
  * @rmtoll STATUSBLOCK          STATUS         LL_DMA_IsActiveFlag_BLOCK1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSBLOCK, DMA_STATUSBLOCK_STATUS_0) == DMA_STATUSBLOCK_STATUS_0);
}

/**
  * @brief  Get Channel 2 block transfer complete flag.
  * @rmtoll STATUSBLOCK          STATUS         LL_DMA_IsActiveFlag_BLOCK2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSBLOCK, DMA_STATUSBLOCK_STATUS_1) == DMA_STATUSBLOCK_STATUS_1);
}

/**
  * @brief  Get Channel 3 block transfer complete flag.
  * @rmtoll STATUSBLOCK          STATUS         LL_DMA_IsActiveFlag_BLOCK3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSBLOCK, DMA_STATUSBLOCK_STATUS_2) == DMA_STATUSBLOCK_STATUS_2);
}

/**
  * @brief  Get Channel 4 block transfer complete flag.
  * @rmtoll STATUSBLOCK          STATUS         LL_DMA_IsActiveFlag_BLOCK4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSBLOCK, DMA_STATUSBLOCK_STATUS_3) == DMA_STATUSBLOCK_STATUS_3);
}

/**
  * @brief  Get Channel 5 block transfer complete flag.
  * @rmtoll STATUSBLOCK          STATUS         LL_DMA_IsActiveFlag_BLOCK5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSBLOCK, DMA_STATUSBLOCK_STATUS_4) == DMA_STATUSBLOCK_STATUS_4);
}

/**
  * @brief  Get Channel 6 block transfer complete flag.
  * @rmtoll STATUSBLOCK          STATUS         LL_DMA_IsActiveFlag_BLOCK6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSBLOCK, DMA_STATUSBLOCK_STATUS_5) == DMA_STATUSBLOCK_STATUS_5);
}

/**
  * @brief  Get one of channls block complete flag.
  * @rmtoll STATUSINT          BLOCK         LL_DMA_IsActiveFlag_BLOCK
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_BLOCK(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSINT, DMA_STATUSINT_BLOCK) == DMA_STATUSINT_BLOCK);
}

/**
  * @brief  Get Channel 1 block half transfer flag.
  * @rmtoll STATUSHALFBLOCK          STATUS         LL_DMA_IsActiveFlag_HALFBLOCK1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSHALFBLOCK, DMA_STATUSHALFBLOCK_STATUS_0) == DMA_STATUSBLOCK_STATUS_0);
}

/**
  * @brief  Get Channel 2 block half transfer flag.
  * @rmtoll STATUSHALFBLOCK          STATUS         LL_DMA_IsActiveFlag_HALFBLOCK2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSHALFBLOCK, DMA_STATUSHALFBLOCK_STATUS_1) == DMA_STATUSBLOCK_STATUS_1);
}

/**
  * @brief  Get Channel 3 block half transfer flag.
  * @rmtoll STATUSHALFBLOCK          STATUS         LL_DMA_IsActiveFlag_HALFBLOCK3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSHALFBLOCK, DMA_STATUSHALFBLOCK_STATUS_2) == DMA_STATUSBLOCK_STATUS_2);
}

/**
  * @brief  Get Channel 4 block half transfer flag.
  * @rmtoll STATUSHALFBLOCK          STATUS         LL_DMA_IsActiveFlag_HALFBLOCK4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSHALFBLOCK, DMA_STATUSHALFBLOCK_STATUS_3) == DMA_STATUSBLOCK_STATUS_3);
}

/**
  * @brief  Get Channel 5 block half transfer flag.
  * @rmtoll STATUSHALFBLOCK          STATUS         LL_DMA_IsActiveFlag_HALFBLOCK5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSHALFBLOCK, DMA_STATUSHALFBLOCK_STATUS_4) == DMA_STATUSBLOCK_STATUS_4);
}

/**
  * @brief  Get Channel 6 block half transfer flag.
  * @rmtoll STATUSHALFBLOCK          STATUS         LL_DMA_IsActiveFlag_HALFBLOCK6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSHALFBLOCK, DMA_STATUSHALFBLOCK_STATUS_5) == DMA_STATUSBLOCK_STATUS_5);
}

/**
  * @brief  Get one of channls half block transfer complete flag.
  * @rmtoll STATUSINT          HALFBLOCK         LL_DMA_IsActiveFlag_HALFBLOCK
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HALFBLOCK(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSINT, DMA_STATUSINT_HALFBLOCK) == DMA_STATUSINT_HALFBLOCK);
}

/**
  * @brief  Get Channel 1 source transfer flag.
  * @rmtoll STATUSSRCTRAN          STATUS         LL_DMA_IsActiveFlag_SRCTRAN1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSSRCTRAN, DMA_STATUSSRCTRAN_STATUS_0) == DMA_STATUSSRCTRAN_STATUS_0);
}

/**
  * @brief  Get Channel 2 source transfer flag.
  * @rmtoll STATUSSRCTRAN          STATUS         LL_DMA_IsActiveFlag_SRCTRAN2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSSRCTRAN, DMA_STATUSSRCTRAN_STATUS_1) == DMA_STATUSSRCTRAN_STATUS_1);
}

/**
  * @brief  Get Channel 3 source transfer flag.
  * @rmtoll STATUSSRCTRAN          STATUS         LL_DMA_IsActiveFlag_SRCTRAN3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSSRCTRAN, DMA_STATUSSRCTRAN_STATUS_2) == DMA_STATUSSRCTRAN_STATUS_2);
}

/**
  * @brief  Get Channel 4 source transfer flag.
  * @rmtoll STATUSSRCTRAN          STATUS         LL_DMA_IsActiveFlag_SRCTRAN4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSSRCTRAN, DMA_STATUSSRCTRAN_STATUS_3) == DMA_STATUSSRCTRAN_STATUS_3);
}

/**
  * @brief  Get Channel 5 source transfer flag.
  * @rmtoll STATUSSRCTRAN          STATUS         LL_DMA_IsActiveFlag_SRCTRAN5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSSRCTRAN, DMA_STATUSSRCTRAN_STATUS_4) == DMA_STATUSSRCTRAN_STATUS_4);
}

/**
  * @brief  Get Channel 6 source transfer flag.
  * @rmtoll STATUSSRCTRAN          STATUS         LL_DMA_IsActiveFlag_SRCTRAN6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSSRCTRAN, DMA_STATUSSRCTRAN_STATUS_5) == DMA_STATUSSRCTRAN_STATUS_5);
}

/**
  * @brief  Get one of channls srctran complete flag.
  * @rmtoll STATUSINT          SRCT         LL_DMA_IsActiveFlag_SRCTRAN
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SRCTRAN(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSINT, DMA_STATUSINT_SRCT) == DMA_STATUSINT_SRCT);
}

/**
  * @brief  Get Channel 1 dest transfer flag.
  * @rmtoll STATUSDSTTRAN          STATUS         LL_DMA_IsActiveFlag_DSTTRAN1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSDSTTRAN, DMA_STATUSDSTTRAN_STATUS_0) == DMA_STATUSDSTTRAN_STATUS_0);
}

/**
  * @brief  Get Channel 2 dest transfer flag.
  * @rmtoll STATUSDSTTRAN          STATUS         LL_DMA_IsActiveFlag_DSTTRAN2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSDSTTRAN, DMA_STATUSDSTTRAN_STATUS_1) == DMA_STATUSDSTTRAN_STATUS_1);
}

/**
  * @brief  Get Channel 3 dest transfer flag.
  * @rmtoll STATUSDSTTRAN          STATUS         LL_DMA_IsActiveFlag_DSTTRAN3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSDSTTRAN, DMA_STATUSDSTTRAN_STATUS_2) == DMA_STATUSDSTTRAN_STATUS_2);
}

/**
  * @brief  Get Channel 4 dest transfer flag.
  * @rmtoll STATUSDSTTRAN          STATUS         LL_DMA_IsActiveFlag_DSTTRAN4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSDSTTRAN, DMA_STATUSDSTTRAN_STATUS_3) == DMA_STATUSDSTTRAN_STATUS_3);
}

/**
  * @brief  Get Channel 5 dest transfer flag.
  * @rmtoll STATUSDSTTRAN          STATUS         LL_DMA_IsActiveFlag_DSTTRAN5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSDSTTRAN, DMA_STATUSDSTTRAN_STATUS_4) == DMA_STATUSDSTTRAN_STATUS_4);
}

/**
  * @brief  Get Channel 6 dest transfer flag.
  * @rmtoll STATUSDSTTRAN          STATUS         LL_DMA_IsActiveFlag_DSTTRAN6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSDSTTRAN, DMA_STATUSDSTTRAN_STATUS_5) == DMA_STATUSDSTTRAN_STATUS_5);
}

/**
  * @brief  Get one of channls dsttran complete flag.
  * @rmtoll STATUSINT          DSTT         LL_DMA_IsActiveFlag_DSTTRAN
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DSTTRAN(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSINT, DMA_STATUSINT_DSTT) == DMA_STATUSINT_DSTT);
}

/**
  * @brief  Get Channel 1 transfer error flag.
  * @rmtoll STATUSERR          STATUS         LL_DMA_IsActiveFlag_ERR1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSERR, DMA_STATUSERR_STATUS_0) == DMA_STATUSERR_STATUS_0);
}

/**
  * @brief  Get Channel 2 transfer error flag.
  * @rmtoll STATUSERR          STATUS         LL_DMA_IsActiveFlag_ERR2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSERR, DMA_STATUSERR_STATUS_1) == DMA_STATUSERR_STATUS_1);
}

/**
  * @brief  Get Channel 3 transfer error flag.
  * @rmtoll STATUSERR          STATUS         LL_DMA_IsActiveFlag_ERR3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSERR, DMA_STATUSERR_STATUS_2) == DMA_STATUSERR_STATUS_2);
}

/**
  * @brief  Get Channel 4 transfer error flag.
  * @rmtoll STATUSERR          STATUS         LL_DMA_IsActiveFlag_ERR4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSERR, DMA_STATUSERR_STATUS_3) == DMA_STATUSERR_STATUS_3);
}

/**
  * @brief  Get Channel 5 transfer error flag.
  * @rmtoll STATUSERR          STATUS         LL_DMA_IsActiveFlag_ERR5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSERR, DMA_STATUSERR_STATUS_4) == DMA_STATUSERR_STATUS_4);
}

/**
  * @brief  Get Channel 6 transfer error flag.
  * @rmtoll STATUSERR          STATUS         LL_DMA_IsActiveFlag_ERR6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSERR, DMA_STATUSERR_STATUS_5) == DMA_STATUSERR_STATUS_5);
}

/**
  * @brief  Get one of channls error flag.
  * @rmtoll STATUSINT          ERR         LL_DMA_IsActiveFlag_ERR
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_ERR(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->STATUSINT, DMA_STATUSINT_ERR) == DMA_STATUSINT_ERR);
}

/**
  * @brief  Clear Channel 1 transfer complete flag.
  * @rmtoll CLEARTFR         CLEAR        LL_DMA_ClearFlag_TFR1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TFR1(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARTFR,DMA_CLEARTFR_CLEAR_0);
}

/**
  * @brief  Clear Channel 2  transfer complete flag.
  * @rmtoll CLEARTFR         CLEAR        LL_DMA_ClearFlag_TFR2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TFR2(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARTFR,DMA_CLEARTFR_CLEAR_1);
}

/**
  * @brief  Clear Channel 3  transfer complete flag.
  * @rmtoll CLEARTFR         CLEAR        LL_DMA_ClearFlag_TFR3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TFR3(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARTFR,DMA_CLEARTFR_CLEAR_2);
}

/**
  * @brief  Clear Channel 4  transfer complete flag.
  * @rmtoll CLEARTFR         CLEAR        LL_DMA_ClearFlag_TFR4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TFR4(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARTFR,DMA_CLEARTFR_CLEAR_3);
}

/**
  * @brief  Clear Channel 5  transfer complete flag.
  * @rmtoll CLEARTFR         CLEAR        LL_DMA_ClearFlag_TFR5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TFR5(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARTFR,DMA_CLEARTFR_CLEAR_4);
}

/**
  * @brief  Clear Channel 6  transfer complete flag.
  * @rmtoll CLEARTFR         CLEAR        LL_DMA_ClearFlag_TFR6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TFR6(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARTFR,DMA_CLEARTFR_CLEAR_5);
}


/**
  * @brief  Clear Channel 1 block transfer complete flag.
  * @rmtoll CLEARBLOCK         CLEAR        LL_DMA_ClearFlag_BLOCK1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_BLOCK1(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARBLOCK,DMA_CLEARBLOCK_CLEAR_0);
}

/**
  * @brief  Clear Channel 2 block transfer complete flag.
  * @rmtoll CLEARBLOCK         CLEAR        LL_DMA_ClearFlag_BLOCK2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_BLOCK2(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARBLOCK,DMA_CLEARBLOCK_CLEAR_1);
}

/**
  * @brief  Clear Channel 3 block transfer complete flag.
  * @rmtoll CLEARBLOCK         CLEAR        LL_DMA_ClearFlag_BLOCK3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_BLOCK3(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARBLOCK,DMA_CLEARBLOCK_CLEAR_2);
}

/**
  * @brief  Clear Channel 4 block transfer complete flag.
  * @rmtoll CLEARBLOCK         CLEAR        LL_DMA_ClearFlag_BLOCK4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_BLOCK4(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARBLOCK,DMA_CLEARBLOCK_CLEAR_3);
}

/**
  * @brief  Clear Channel 5 block transfer complete flag.
  * @rmtoll CLEARBLOCK         CLEAR        LL_DMA_ClearFlag_BLOCK5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_BLOCK5(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARBLOCK,DMA_CLEARBLOCK_CLEAR_4);
}

/**
  * @brief  Clear Channel 6 block transfer complete flag.
  * @rmtoll CLEARBLOCK         CLEAR        LL_DMA_ClearFlag_BLOCK6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_BLOCK6(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARBLOCK,DMA_CLEARBLOCK_CLEAR_5);
}


/**
  * @brief  Clear Channel 1 block half transfer flag.
  * @rmtoll CLEARHALFBLOCK         CLEAR        LL_DMA_ClearFlag_HALFBLOCK1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HALFBLOCK1(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARHALFBLOCK,DMA_CLEARHALFBLOCK_CLEAR_0);
}

/**
  * @brief  Clear Channel 2 block half transfer flag.
  * @rmtoll CLEARHALFBLOCK         CLEAR        LL_DMA_ClearFlag_HALFBLOCK2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HALFBLOCK2(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARHALFBLOCK,DMA_CLEARHALFBLOCK_CLEAR_1);
}

/**
  * @brief  Clear Channel 3 block half transfer flag.
  * @rmtoll CLEARHALFBLOCK         CLEAR        LL_DMA_ClearFlag_HALFBLOCK3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HALFBLOCK3(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARHALFBLOCK,DMA_CLEARHALFBLOCK_CLEAR_2);
}

/**
  * @brief  Clear Channel 4 block half transfer flag.
  * @rmtoll CLEARHALFBLOCK         CLEAR        LL_DMA_ClearFlag_HALFBLOCK4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HALFBLOCK4(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARHALFBLOCK,DMA_CLEARHALFBLOCK_CLEAR_3);
}

/**
  * @brief  Clear Channel 5 block half transfer flag.
  * @rmtoll CLEARHALFBLOCK         CLEAR        LL_DMA_ClearFlag_HALFBLOCK5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HALFBLOCK5(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARHALFBLOCK,DMA_CLEARHALFBLOCK_CLEAR_4);
}

/**
  * @brief  Clear Channel 6 block half transfer flag.
  * @rmtoll CLEARHALFBLOCK         CLEAR        LL_DMA_ClearFlag_HALFBLOCK6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HALFBLOCK6(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARHALFBLOCK,DMA_CLEARHALFBLOCK_CLEAR_5);
}

/**
  * @brief  Clear Channel 1 transfer error flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_ERR1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ERR1(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARERR,DMA_CLEARERR_CLEAR_0);
}

/**
  * @brief  Clear Channel 2 transfer error flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_ERR2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ERR2(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARERR,DMA_CLEARERR_CLEAR_1);
}

/**
  * @brief  Clear Channel 3 transfer error flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_ERR3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ERR3(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARERR,DMA_CLEARERR_CLEAR_2);
}

/**
  * @brief  Clear Channel 4 transfer error flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_ERR4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ERR4(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARERR,DMA_CLEARERR_CLEAR_3);
}

/**
  * @brief  Clear Channel 5 transfer error flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_ERR5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ERR5(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARERR,DMA_CLEARERR_CLEAR_4);
}

/**
  * @brief  Clear Channel 6 transfer error flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_ERR6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_ERR6(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARERR,DMA_CLEARERR_CLEAR_5);
}

/**
  * @brief  Clear Channel 1 source transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_SRCTRAN1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SRCTRAN1(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARSRCTRAN,DMA_CLEARERR_CLEAR_0);
}

/**
  * @brief  Clear Channel 2 source transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_SRCTRAN2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SRCTRAN2(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARSRCTRAN,DMA_CLEARERR_CLEAR_1);
}

/**
  * @brief  Clear Channel 3 source transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_SRCTRAN3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SRCTRAN3(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARSRCTRAN,DMA_CLEARERR_CLEAR_2);
}

/**
  * @brief  Clear Channel 4 source transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_SRCTRAN4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SRCTRAN4(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARSRCTRAN,DMA_CLEARERR_CLEAR_3);
}

/**
  * @brief  Clear Channel 5 source transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_SRCTRAN5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SRCTRAN5(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARSRCTRAN,DMA_CLEARERR_CLEAR_4);
}

/**
  * @brief  Clear Channel 6 source transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_SRCTRAN6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SRCTRAN6(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARSRCTRAN,DMA_CLEARERR_CLEAR_5);
}
/**
  * @brief  Clear Channel 1 dest transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_DSTTRAN1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DSTTRAN1(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARDSTTRAN,DMA_CLEARERR_CLEAR_0);
}

/**
  * @brief  Clear Channel 2 dest transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_DSTTRAN2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DSTTRAN2(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARDSTTRAN,DMA_CLEARERR_CLEAR_1);
}

/**
  * @brief  Clear Channel 3 dest transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_DSTTRAN3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DSTTRAN3(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARDSTTRAN,DMA_CLEARERR_CLEAR_2);
}

/**
  * @brief  Clear Channel 4 dest transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_DSTTRAN4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DSTTRAN4(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARDSTTRAN,DMA_CLEARERR_CLEAR_3);
}

/**
  * @brief  Clear Channel 5 dest transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_DSTTRAN5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DSTTRAN5(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARDSTTRAN,DMA_CLEARERR_CLEAR_4);
}

/**
  * @brief  Clear Channel 6 dest transfer completely flag.
  * @rmtoll CLEARERR         CLEAR        LL_DMA_ClearFlag_DSTTRAN6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DSTTRAN6(DMA_TypeDef *DMAx)
{
  SET_BIT(DMAx->CLEARDSTTRAN,DMA_CLEARERR_CLEAR_5);
}
/**
  * @}
  */

/** @defgroup DMA_LL_EF_IT_Management IT Management
  * @{
  */

/**
  * @brief  Enable DMA interrupt.
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL, DMA_CH_CTRLL_INT_EN);
}

/**
  * @brief  Disable DMA interrupt.
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL, DMA_CH_CTRLL_INT_EN);
}

/**
  * @brief  Check if DMA Interrupt is enabled.
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CH_CTRLL,
                   DMA_CH_CTRLL_INT_EN) == (DMA_CH_CTRLL_INT_EN));
}

/**
  * @brief  Enable Transfer complete interrupt.
  * @rmtoll MASKTFR          INT_MASK          LL_DMA_EnableIT_TFR
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6

  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_TFR(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->MASKTFR, (DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0) << (Channel-1) );
}

/**
  * @brief  Enable block transfer complete interrupt.
  * @rmtoll MASKBLOCK          INT_MASK          LL_DMA_EnableIT_BLOCK
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_BLOCK(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->MASKBLOCK, (DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0) << (Channel-1) );
}

/**
  * @brief  Enable Half transfer interrupt.
  * @rmtoll MASKHALFBLOCK          INT_MASK          LL_DMA_EnableIT_HALFBLOCK
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_HALFBLOCK(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->MASKHALFBLOCK, (DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0) << (Channel-1) );
}

/**
  * @brief  Enable Transfer error interrupt.
  * @rmtoll MASKERR          INT_MASK          LL_DMA_EnableIT_ERR
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_ERR(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->MASKERR, (DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0) << (Channel-1) );
}

/**
  * @brief  Enable Src Transfer interrupt.
  * @rmtoll MASKSRCTRAN          INT_MASK          LL_DMA_EnableIT_SRCTRAN
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_SRCTRAN(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->MASKSRCTRAN, (DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0) << (Channel-1) );
}

/**
  * @brief  Enable Dst Transfer interrupt.
  * @rmtoll MASKDSTTRAN          INT_MASK          LL_DMA_EnableIT_DSTTRAN
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_DSTTRAN(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(DMAx->MASKDSTTRAN, (DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0) << (Channel-1) );
}

/**
  * @brief  Disable Transfer complete interrupt.
  * @rmtoll MASKTFR          INT_MASK          LL_DMA_DisableIT_TFR
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_TFR(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->MASKTFR,(DMA_MASKTFR_INT_MASK_0 | DMA_MASKTFR_INT_MASK_WE_0)<<(Channel-1),DMA_MASKTFR_INT_MASK_WE_0<<(Channel-1));
}

/**
  * @brief  Disable Block Transfer complete interrupt.
  * @rmtoll MASKBLOCK          INT_MASK          LL_DMA_DisableIT_BLOCK
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_BLOCK(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->MASKBLOCK,(DMA_MASKBLOCK_INT_MASK_0 | DMA_MASKBLOCK_INT_MASK_WE_0)<<(Channel-1),DMA_MASKBLOCK_INT_MASK_WE_0<<(Channel-1));
}

/**
  * @brief  Disable Block Half transfer interrupt.
  * @rmtoll MASKHALFBLOCK          INT_MASK          LL_DMA_DisableIT_HALFBLOCK
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_HALFBLOCK(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->MASKHALFBLOCK,(DMA_MASKHALFBLOCK_INT_MASK_0 | DMA_MASKHALFBLOCK_INT_MASK_WE_0)<<(Channel-1),DMA_MASKHALFBLOCK_INT_MASK_WE_0<<(Channel-1));
}

/**
  * @brief  Disable Transfer error interrupt.
  * @rmtoll MASKERR          INT_MASK          LL_DMA_DisableIT_ERR
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_ERR(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->MASKERR,(DMA_MASKERR_INT_MASK_0 | DMA_MASKERR_INT_MASK_WE_0)<<(Channel-1),DMA_MASKERR_INT_MASK_WE_0<<(Channel-1));
}

/**
  * @brief  Disable Src Transfer interrupt.
  * @rmtoll MASKSRCTRAN          INT_MASK          LL_DMA_DisableIT_SRCTRAN
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_SRCTRAN(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->MASKSRCTRAN,(DMA_MASKSRCTRAN_INT_MASK_0 | DMA_MASKSRCTRAN_INT_MASK_WE_0)<<(Channel-1),DMA_MASKSRCTRAN_INT_MASK_WE_0<<(Channel-1));
}

/**
  * @brief  Disable Transfer error interrupt.
  * @rmtoll MASKDSTTRAN          INT_MASK          LL_DMA_DisableIT_DSTTRAN
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_DSTTRAN(DMA_TypeDef *DMAx, uint32_t Channel)
{
  MODIFY_REG(DMAx->MASKDSTTRAN,(DMA_MASKDSTTRAN_INT_MASK_0 | DMA_MASKDSTTRAN_INT_MASK_WE_0)<<(Channel-1),DMA_MASKDSTTRAN_INT_MASK_WE_0<<(Channel-1));
}

/**
  * @brief  Check if Transfer complete Interrupt is enabled.
  * @rmtoll MASKTFR          INT_MASK          LL_DMA_IsEnabledIT_TFR
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TFR(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->MASKTFR, DMA_MASKTFR_INT_MASK_0<<(Channel-1)) == (DMA_MASKTFR_INT_MASK_0<<(Channel-1)));
}

/**
  * @brief  Check if block Transfer complete Interrupt is enabled.
  * @rmtoll MASKBLOCK          INT_MASK          LL_DMA_IsEnabledIT_BLOCK
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_BLOCK(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->MASKBLOCK, DMA_MASKBLOCK_INT_MASK_0<<(Channel-1)) == (DMA_MASKBLOCK_INT_MASK_0<<(Channel-1)));
}

/**
  * @brief  Check if Block Half transfer Interrupt is enabled.
  * @rmtoll MASKHALFBLOCK          INT_MASK          LL_DMA_IsEnabledIT_HALFBLOCK
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_HALFBLOCK(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->MASKHALFBLOCK, DMA_MASKHALFBLOCK_INT_MASK_0<<(Channel-1)) == (DMA_MASKHALFBLOCK_INT_MASK_0<<(Channel-1)));
}

/**
  * @brief  Check if Transfer error Interrupt is enabled.
  * @rmtoll MASKERR          INT_MASK          LL_DMA_IsEnabledIT_ERR
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_ERR(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->MASKERR, DMA_MASKERR_INT_MASK_0<<(Channel-1)) == (DMA_MASKERR_INT_MASK_0<<(Channel-1)));
}

/**
  * @brief  Check if Src Transfer Interrupt is enabled.
  * @rmtoll MASKSRCTRAN          INT_MASK          LL_DMA_IsEnabledIT_SRCTRAN
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_SRCTRAN(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->MASKSRCTRAN, DMA_MASKSRCTRAN_INT_MASK_0<<(Channel-1)) == (DMA_MASKSRCTRAN_INT_MASK_0<<(Channel-1)));
}

/**
  * @brief  Check if Dest Transfer Interrupt is enabled.
  * @rmtoll MASKDSTTRAN          INT_MASK          LL_DMA_IsEnabledIT_DSTTRAN
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_DSTTRAN(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(DMAx->MASKDSTTRAN, DMA_MASKDSTTRAN_INT_MASK_0<<(Channel-1)) == (DMA_MASKDSTTRAN_INT_MASK_0<<(Channel-1)));
}
/**
  * @}
  */

/** @defgroup DMA_REMAP DMA Remap
  * @{
  */

/**
  * @brief  Set the DMA Remap
  * @param  DMAx DMAx Instance
  * @param  DMAPeriphMap This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_1
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_2
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_3
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_4
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_5
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_6
  * @param  MapReqNum This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_DMA_MAP_ADC1           
  *         @arg @ref LL_SYSCFG_DMA_MAP_ADC2          
  *         @arg @ref LL_SYSCFG_DMA_MAP_ADC3          
  *         @arg @ref LL_SYSCFG_DMA_MAP_DAC1           
  *         @arg @ref LL_SYSCFG_DMA_MAP_DAC2           
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI1_RX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI1_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI2_RX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI2_TX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI3_RX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI3_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART1_RX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART1_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART2_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART2_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART3_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART3_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_LPUART1_RX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_LPUART1_TX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C1_RX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C1_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C2_RX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C2_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C3_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C3_TX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C4_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C4_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH2      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH3       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH4     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_TRIG    
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_COM      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH1     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH2     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH3      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH4      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_COM      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM6_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM7_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH3      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH4      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_TRIG      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH3     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH4      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH3       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH4     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH3       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH4       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_TRIG      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH2      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH3    
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH4      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_CH1     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_COM     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM16_CH1     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM16_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM17_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM17_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_AES_IN         
  *         @arg @ref LL_SYSCFG_DMA_MAP_AES_OUT        
  *         @arg @ref LL_SYSCFG_DMA_MAP_Cordic_Read    
  *         @arg @ref LL_SYSCFG_DMA_MAP_Cordic_Write   
  *         @arg @ref LL_SYSCFG_DMA_MAP_ESMC_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_ESMC_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_SDIO           
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART1_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART1_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART2_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART2_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART3_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART3_TX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_LCDC_TX        
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetDMARemap(DMA_TypeDef *DMAx, uint32_t DMAPeriphMap, uint32_t MapReqNum)
{
  uint32_t position = 0;

  /* Configure the requested functionality */
  if (DMAx == DMA1)
  {
    position = DMAPeriphMap - 1;
  }
  else 
  {
    position = DMAPeriphMap -1 + 6;
  }

  MODIFY_REG((SYSCFG->CFGR[2 + (position >> 2)]), (0x7F << (8u * (position & 0x03u))), (MapReqNum << (8u * (position & 0x03u))));
}

/**
  * @brief  Get the DMA Remap
  * @param  DMAx DMAx Instance
  * @param  DMAPeriphMap This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_1
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_2
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_3
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_4
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_5
  *         @arg @ref LL_SYSCFG_DMA_PERIPH_MAP_6
  * @return  MapReqNum This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_DMA_MAP_ADC1          
  *         @arg @ref LL_SYSCFG_DMA_MAP_ADC2           
  *         @arg @ref LL_SYSCFG_DMA_MAP_ADC3         
  *         @arg @ref LL_SYSCFG_DMA_MAP_DAC1        
  *         @arg @ref LL_SYSCFG_DMA_MAP_DAC2          
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI1_RX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI1_TX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI2_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI2_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI3_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_SPI3_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART1_RX    
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART1_TX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART2_RX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART2_TX    
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART3_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_USART3_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_LPUART1_RX     
  *         @arg @ref LL_SYSCFG_DMA_MAP_LPUART1_TX    
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C1_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C1_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C2_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C2_TX        
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C3_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C3_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C4_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_I2C4_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH3      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_CH4     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_TRIG    
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM1_COM      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH3       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_CH4       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM8_COM     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM6_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM7_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH3     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_CH4    
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_UP        
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM2_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH3       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_CH4      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM3_TRIG      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH3       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_CH4       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_UP     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM4_TRIG      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH1       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH2       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH3      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_CH4       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM5_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH1     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH2     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH3      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_CH4      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM18_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_CH1     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_TRIG     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM15_COM     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM16_CH1      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM16_UP      
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM17_CH1     
  *         @arg @ref LL_SYSCFG_DMA_MAP_TIM17_UP       
  *         @arg @ref LL_SYSCFG_DMA_MAP_AES_IN         
  *         @arg @ref LL_SYSCFG_DMA_MAP_AES_OUT       
  *         @arg @ref LL_SYSCFG_DMA_MAP_Cordic_Read   
  *         @arg @ref LL_SYSCFG_DMA_MAP_Cordic_Write   
  *         @arg @ref LL_SYSCFG_DMA_MAP_ESMC_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_ESMC_TX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_SDIO          
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART1_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART1_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART2_RX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART2_TX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART3_RX       
  *         @arg @ref LL_SYSCFG_DMA_MAP_UART3_TX      
  *         @arg @ref LL_SYSCFG_DMA_MAP_LCDC_TX       
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetDMARemap(DMA_TypeDef *DMAx,uint32_t DMAPeriphMap)
{
  uint32_t position;

  /* Configure the requested functionality */
  if (DMAx == DMA1)
  {
    position = DMAPeriphMap - 1;
  }
  else 
  {
    position = DMAPeriphMap -1 + 6;
  }

  return (READ_BIT((SYSCFG->CFGR[2 + (position >> 2)]), (0x7F << (8u * (position & 0x03u)))) >>(8u * (position & 0x03u)));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct);
uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel);
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* DMA1 || DMA2 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_LL_DMA_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

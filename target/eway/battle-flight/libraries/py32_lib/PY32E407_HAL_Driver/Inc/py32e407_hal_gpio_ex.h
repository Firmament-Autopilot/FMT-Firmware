/**
  ******************************************************************************
  * @file    py32e407_hal_gpio_ex.h
  * @author  MCU Application Team
  * @brief   Header file of GPIO HAL Extended module.
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
#ifndef __PY32E407_HAL_GPIO_EX_H
#define __PY32E407_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
  * @brief GPIO Extended HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIOEx_Exported_Constants GPIOEx Exported Constants
  * @{
  */

/** @defgroup GPIOEx_Alternate_function_selection GPIOEx Alternate function selection
  * @{
  */

/*------------------------- PY32E407 ------------------------*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_MCO           ((uint8_t)0x00)  /*!< MCO Alternate Function mapping */
#define GPIO_AF0_SWJ           ((uint8_t)0x00)  /*!< SWJ (SWD/JTAG) Alternate Function mapping */
#define GPIO_AF0_TRACE         ((uint8_t)0x00)  /*!< TRACE Alternate Function mapping */

/**
* @brief   AF 1 selection
*/
#define GPIO_AF1_TIM2          ((uint8_t)0x01)  /*!< TIM2 Alternate Function mapping */
#define GPIO_AF1_TIM5          ((uint8_t)0x01)  /*!< TIM5 Alternate Function mapping */
#define GPIO_AF1_TIM14         ((uint8_t)0x01)  /*!< TIM14 Alternate Function mapping */
#define GPIO_AF1_TIM15         ((uint8_t)0x01)  /*!< TIM15 Alternate Function mapping */
#define GPIO_AF1_TIM16         ((uint8_t)0x01)  /*!< TIM16 Alternate Function mapping */
#define GPIO_AF1_TIM17         ((uint8_t)0x01)  /*!< TIM17 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01)  /*!< LPTIM1 Alternate Function mapping */

/**
* @brief   AF 2 selection
*/
#define GPIO_AF2_TIM1          ((uint8_t)0x02)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02)  /*!< TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02)  /*!< TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          ((uint8_t)0x02)  /*!< TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          ((uint8_t)0x02)  /*!< TIM5 Alternate Function mapping */
#define GPIO_AF2_TIM8          ((uint8_t)0x02)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF2_TIM9          ((uint8_t)0x02)  /*!< TIM9 Alternate Function mapping */
#define GPIO_AF2_TIM15         ((uint8_t)0x02)  /*!< TIM15 Alternate Function mapping */
#define GPIO_AF2_I2C3          ((uint8_t)0x02)  /*!< I2C3 Alternate Function mapping */

/**
* @brief   AF 3 selection
*/
#define GPIO_AF3_TIM8          ((uint8_t)0x03)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF3_TIM9          ((uint8_t)0x03)  /*!< TIM9 Alternate Function mapping */
#define GPIO_AF3_TIM10         ((uint8_t)0x03)  /*!< TIM10 Alternate Function mapping */
#define GPIO_AF3_TIM11         ((uint8_t)0x03)  /*!< TIM11 Alternate Function mapping */
#define GPIO_AF3_TIM12         ((uint8_t)0x03)  /*!< TIM12 Alternate Function mapping */
#define GPIO_AF3_TIM13         ((uint8_t)0x03)  /*!< TIM13 Alternate Function mapping */
#define GPIO_AF3_TIM14         ((uint8_t)0x03)  /*!< TIM14 Alternate Function mapping */
#define GPIO_AF3_TIM15         ((uint8_t)0x03)  /*!< TIM15 Alternate Function mapping */
#define GPIO_AF3_TIM18         ((uint8_t)0x03)  /*!< TIM18 Alternate Function mapping */
#define GPIO_AF3_I2C4          ((uint8_t)0x03)  /*!< I2C4 Alternate Function mapping */
#define GPIO_AF3_CTC           ((uint8_t)0x03)  /*!< CTC Alternate Function mapping */
#define GPIO_AF3_COMP3         ((uint8_t)0x03)  /*!< COMP3 Alternate Function mapping */

/**
* @brief   AF 4 selection
*/
#define GPIO_AF4_TIM1          ((uint8_t)0x04)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF4_TIM8          ((uint8_t)0x04)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF4_TIM16         ((uint8_t)0x04)  /*!< TIM16 Alternate Function mapping */
#define GPIO_AF4_TIM17         ((uint8_t)0x04)  /*!< TIM17 Alternate Function mapping */
#define GPIO_AF4_TIM18         ((uint8_t)0x04)  /*!< TIM18 Alternate Function mapping */
#define GPIO_AF4_TIM19         ((uint8_t)0x04)  /*!< TIM19 Alternate Function mapping */
#define GPIO_AF4_I2C1          ((uint8_t)0x04)  /*!< I2C1 Alternate Function mapping */
#define GPIO_AF4_I2C2          ((uint8_t)0x04)  /*!< I2C2 Alternate Function mapping */
#define GPIO_AF4_I2C3          ((uint8_t)0x04)  /*!< I2C3 Alternate Function mapping */
#define GPIO_AF4_I2C4          ((uint8_t)0x04)  /*!< I2C4 Alternate Function mapping */

/**
* @brief   AF 5 selection
*/
#define GPIO_AF5_SPI1          ((uint8_t)0x05)  /*!< SPI1 Alternate Function mapping */
#define GPIO_AF5_SPI2          ((uint8_t)0x05)  /*!< SPI2 Alternate Function mapping */
#define GPIO_AF5_I2S1          ((uint8_t)0x05)  /*!< I2S Alternate Function mapping */
#define GPIO_AF5_I2S2          ((uint8_t)0x05)  /*!< I2S2 Alternate Function mapping */
#define GPIO_AF5_I2S3          ((uint8_t)0x05)  /*!< I2S3 Alternate Function mapping */
#define GPIO_AF5_TIM8          ((uint8_t)0x05)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF5_UART1         ((uint8_t)0x05)  /*!< UART1 Alternate Function mapping */
#define GPIO_AF5_UART2         ((uint8_t)0x05)  /*!< UART2 Alternate Function mapping */
#define GPIO_AF5_IR            ((uint8_t)0x05)  /*!< IR Alternate Function mapping */

/**
* @brief   AF 6 selection
*/
#define GPIO_AF6_TIM1          ((uint8_t)0x06)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF6_TIM5          ((uint8_t)0x06)  /*!< TIM5 Alternate Function mapping */
#define GPIO_AF6_TIM8          ((uint8_t)0x06)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF6_IR            ((uint8_t)0x06)  /*!< IR Alternate Function mapping */
#define GPIO_AF6_I2S2          ((uint8_t)0x06)  /*!< I2S2 Alternate Function mapping */
#define GPIO_AF6_I2S3          ((uint8_t)0x06)  /*!< I2S3 Alternate Function mapping */
#define GPIO_AF6_SPI2          ((uint8_t)0x06)  /*!< SPI2 Alternate Function mapping */
#define GPIO_AF6_SPI3          ((uint8_t)0x06)  /*!< SPI3 Alternate Function mapping */
#define GPIO_AF6_LCDC          ((uint8_t)0x06)  /*!< LCDC Alternate Function mapping */  

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF7_USART2        ((uint8_t)0x07)  /*!< USART2 Alternate Function mapping */
#define GPIO_AF7_USART3        ((uint8_t)0x07)  /*!< USART3 Alternate Function mapping */
#define GPIO_AF7_TIM12         ((uint8_t)0x07)  /*!< TIM12 Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_COMP1         ((uint8_t)0x08U)  /*!< COMP1  Alternate Function mapping */
#define GPIO_AF8_COMP2         ((uint8_t)0x08U)  /*!< COMP2 Alternate Function mapping */
#define GPIO_AF8_COMP3         ((uint8_t)0x08U)  /*!< COMP3 Alternate Function mapping */
#define GPIO_AF8_COMP4         ((uint8_t)0x08U)  /*!< COMP4 Alternate Function mapping */
#define GPIO_AF8_TIM18         ((uint8_t)0x08U)  /*!< TIM18 Alternate Function mapping */
#define GPIO_AF8_I2C3          ((uint8_t)0x08U)  /*!< I2C3 Alternate Function mapping */
#define GPIO_AF8_I2C4          ((uint8_t)0x08U)  /*!< I2C4 Alternate Function mapping */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF8_CTC           ((uint8_t)0x08U)  /*!< CTC Alternate Function mapping */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_FDCAN1        ((uint8_t)0x09U)  /*!< FDCAN1  Alternate Function mapping */
#define GPIO_AF9_FDCAN2        ((uint8_t)0x09U)  /*!< FDCAN2 Alternate Function mapping */
#define GPIO_AF9_TIM1          ((uint8_t)0x09U)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF9_TIM8          ((uint8_t)0x09U)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF9_TIM15         ((uint8_t)0x09U)  /*!< TIM15 Alternate Function mapping */
#define GPIO_AF9_ESMC          ((uint8_t)0x09U)  /*!< ESMC Alternate Function mapping */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_ESMC         ((uint8_t)0x0A)  /*!< ESMC  Alternate Function mapping */
#define GPIO_AF10_TIM2         ((uint8_t)0x0A)  /*!< TIM2  Alternate Function mapping */
#define GPIO_AF10_TIM3         ((uint8_t)0x0A)  /*!< TIM3 Alternate Function mapping */
#define GPIO_AF10_TIM4         ((uint8_t)0x0A)  /*!< TIM4 Alternate Function mapping */
#define GPIO_AF10_TIM8         ((uint8_t)0x0A)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF10_TIM17        ((uint8_t)0x0A)  /*!< TIM17 Alternate Function mapping */

/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_SDIO         ((uint8_t)0x0B)  /*!< SDIO Alternate Function mapping */
#define GPIO_AF11_LPTIM1       ((uint8_t)0x0B)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF11_TIM1         ((uint8_t)0x0B)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF11_TIM8         ((uint8_t)0x0B)  /*!< TIM8 Alternate Function mapping */
#define GPIO_AF11_TIM19        ((uint8_t)0x0B)  /*!< TIM19 Alternate Function mapping */
#define GPIO_AF11_LCDC         ((uint8_t)0x0B)  /*!< LCDC Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_TIM11        ((uint8_t)0x0C)  /*!< TIM11 Alternate Function mapping */  
#define GPIO_AF12_LPUART1      ((uint8_t)0x0C)  /*!< LPUART1 Alternate Function mapping */ 
#define GPIO_AF12_TIM1         ((uint8_t)0x0C)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF12_LCDC         ((uint8_t)0x0C)  /*!< LCDC Alternate Function mapping */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_TIM19        ((uint8_t)0x0D)  /*!< TIM19 Alternate Function mapping */
#define GPIO_AF13_ETH          ((uint8_t)0x0D)  /*!< ETH Alternate Function mapping */
#define GPIO_AF13_LCDC         ((uint8_t)0x0D)  /*!< LCDC Alternate Function mapping */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0E)  /*!< TIM2 Alternate Function mapping */
#define GPIO_AF14_UART3        ((uint8_t)0x0E)  /*!< UART3 Alternate Function mapping */
#define GPIO_AF14_USB1         ((uint8_t)0x0E)  /*!< USB1 Alternate Function mapping */
#define GPIO_AF14_USB2         ((uint8_t)0x0E)  /*!< USB2 Alternate Function mapping */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENT        ((uint8_t)0x0fU) /*!< EVENT Alternate Function mapping */
#define IS_GPIO_AF(AF)         ((AF) <= (uint8_t)0x0f)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIOEx_Exported_Macros GPIOEx Exported Macros
  * @{
  */

/** @defgroup GPIOEx_Get_Port_Index GPIOEx Get Port Index
  * @{
  */
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA))? 0UL :\
                                      ((__GPIOx__) == (GPIOB))? 1UL :\
                                      ((__GPIOx__) == (GPIOC))? 2UL :\
                                      ((__GPIOx__) == (GPIOD))? 3UL :\
                                      ((__GPIOx__) == (GPIOE))? 4UL : 5)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_HAL_GPIO_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

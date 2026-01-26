/**
  ******************************************************************************
  * @file    py32e407_ll_gpio.h
  * @author  MCU Application Team
  * @brief   Header file of GPIO LL module.
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
#ifndef __PY32E407_LL_GPIO_H
#define __PY32E407_LL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"
/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF)

/** @defgroup GPIO_LL GPIO
  * @{
  */
/** MISRA C:2012 deviation rule has been granted for following rules:
  * Rule-18.1_d - Medium: Array pointer `GPIOx' is accessed with index [..,..]
  * which may be out of array bounds [..,UNKNOWN] in following APIs:
  * LL_GPIO_GetAFPin_0_7
  * LL_GPIO_SetAFPin_0_7
  * LL_GPIO_SetAFPin_8_15
  * LL_GPIO_GetAFPin_8_15
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_Private_Macros GPIO Private Macros
  * @{
  */

/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_ES_INIT GPIO Exported Init structures
  * @{
  */

/**
  * @brief LL GPIO Init Structure definition
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_LL_EC_PIN */

  uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_MODE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinMode().*/

  uint32_t Speed;        /*!< Specifies the speed for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_SPEED.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinSpeed().*/

  uint32_t OutputType;   /*!< Specifies the operating output type for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_OUTPUT.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinOutputType().*/

  uint32_t Pull;         /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_PULL.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinPull().*/

  uint32_t Alternate;    /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_AF.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetAFPin_0_7() and LL_GPIO_SetAFPin_8_15().*/
} LL_GPIO_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Constants GPIO Exported Constants
  * @{
  */
#define LL_GPIO_LCKR_LCKK                  0x00030000U

/** @defgroup GPIO_LL_EC_PIN PIN
  * @{
  */
#define LL_GPIO_PIN_0                      GPIO_BSRR_BS0  /*!< Select pin 0 */
#define LL_GPIO_PIN_1                      GPIO_BSRR_BS1  /*!< Select pin 1 */
#define LL_GPIO_PIN_2                      GPIO_BSRR_BS2  /*!< Select pin 2 */
#define LL_GPIO_PIN_3                      GPIO_BSRR_BS3  /*!< Select pin 3 */
#define LL_GPIO_PIN_4                      GPIO_BSRR_BS4  /*!< Select pin 4 */
#define LL_GPIO_PIN_5                      GPIO_BSRR_BS5  /*!< Select pin 5 */
#define LL_GPIO_PIN_6                      GPIO_BSRR_BS6  /*!< Select pin 6 */
#define LL_GPIO_PIN_7                      GPIO_BSRR_BS7  /*!< Select pin 7 */
#define LL_GPIO_PIN_8                      GPIO_BSRR_BS8  /*!< Select pin 8 */
#define LL_GPIO_PIN_9                      GPIO_BSRR_BS9  /*!< Select pin 9 */
#define LL_GPIO_PIN_10                     GPIO_BSRR_BS10 /*!< Select pin 10 */
#define LL_GPIO_PIN_11                     GPIO_BSRR_BS11 /*!< Select pin 11 */
#define LL_GPIO_PIN_12                     GPIO_BSRR_BS12 /*!< Select pin 12 */
#define LL_GPIO_PIN_13                     GPIO_BSRR_BS13 /*!< Select pin 13 */
#define LL_GPIO_PIN_14                     GPIO_BSRR_BS14 /*!< Select pin 14 */
#define LL_GPIO_PIN_15                     GPIO_BSRR_BS15 /*!< Select pin 15 */
#define LL_GPIO_PIN_ALL                    (GPIO_BSRR_BS0 | GPIO_BSRR_BS1  | GPIO_BSRR_BS2  | \
                                           GPIO_BSRR_BS3  | GPIO_BSRR_BS4  | GPIO_BSRR_BS5  | \
                                           GPIO_BSRR_BS6  | GPIO_BSRR_BS7  | GPIO_BSRR_BS8  | \
                                           GPIO_BSRR_BS9  | GPIO_BSRR_BS10 | GPIO_BSRR_BS11 | \
                                           GPIO_BSRR_BS12 | GPIO_BSRR_BS13 | GPIO_BSRR_BS14 | \
                                           GPIO_BSRR_BS15) /*!< Select all pins */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_MODE Mode
  * @{
  */
#define LL_GPIO_MODE_INPUT                 (0x00000000U)       /*!< Select input mode */
#define LL_GPIO_MODE_OUTPUT                GPIO_MODER_MODE0_0  /*!< Select output mode */
#define LL_GPIO_MODE_ALTERNATE             GPIO_MODER_MODE0_1  /*!< Select alternate function mode */
#define LL_GPIO_MODE_ANALOG                GPIO_MODER_MODE0    /*!< Select analog mode */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_OUTPUT Output Type
  * @{
  */
#define LL_GPIO_OUTPUT_PUSHPULL            (0x00000000U)   /*!< Select push-pull as output type */
#define LL_GPIO_OUTPUT_OPENDRAIN           GPIO_OTYPER_OT0 /*!< Select open-drain as output type */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_SPEED Output Speed
  * @{
  */
#define LL_GPIO_SPEED_FREQ_LOW             (0x00000000U)          /*!< Select I/O low output speed    */
#define LL_GPIO_SPEED_FREQ_MEDIUM          GPIO_OSPEEDR_OSPEED0_0 /*!< Select I/O medium output speed */
#define LL_GPIO_SPEED_FREQ_HIGH            GPIO_OSPEEDR_OSPEED0_1 /*!< Select I/O high output speed   */
#define LL_GPIO_SPEED_FREQ_VERY_HIGH       GPIO_OSPEEDR_OSPEED0   /*!< Select I/O very high output speed   */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_PULL Pull Up Pull Down
  * @{
  */
#define LL_GPIO_PULL_NO                    (0x00000000U)      /*!< Select I/O no pull */
#define LL_GPIO_PULL_UP                    GPIO_PUPDR_PUPD0_0 /*!< Select I/O pull up */
#define LL_GPIO_PULL_DOWN                  GPIO_PUPDR_PUPD0_1 /*!< Select I/O pull down */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_AF Alternate Function
  * @{
  */
#define LL_GPIO_AF_0                       (0x0000000U) /*!< Select alternate function 0 */
#define LL_GPIO_AF_1                       (0x0000001U) /*!< Select alternate function 1 */
#define LL_GPIO_AF_2                       (0x0000002U) /*!< Select alternate function 2 */
#define LL_GPIO_AF_3                       (0x0000003U) /*!< Select alternate function 3 */
#define LL_GPIO_AF_4                       (0x0000004U) /*!< Select alternate function 4 */
#define LL_GPIO_AF_5                       (0x0000005U) /*!< Select alternate function 5 */
#define LL_GPIO_AF_6                       (0x0000006U) /*!< Select alternate function 6 */
#define LL_GPIO_AF_7                       (0x0000007U) /*!< Select alternate function 7 */
#define LL_GPIO_AF_8                       (0x0000008U) /*!< Select alternate function 8 */
#define LL_GPIO_AF_9                       (0x0000009U) /*!< Select alternate function 9 */
#define LL_GPIO_AF_10                      (0x000000AU) /*!< Select alternate function 10 */
#define LL_GPIO_AF_11                      (0x000000BU) /*!< Select alternate function 11 */
#define LL_GPIO_AF_12                      (0x000000CU) /*!< Select alternate function 12 */
#define LL_GPIO_AF_13                      (0x000000DU) /*!< Select alternate function 13 */
#define LL_GPIO_AF_14                      (0x000000EU) /*!< Select alternate function 14 */
#define LL_GPIO_AF_15                      (0x000000FU) /*!< Select alternate function 15 */

/**
  * @}
  */

/** @defgroup GPIO_LL_Alternate_function_selection Alternate function selection
  * @{
  */

/**
  * @brief   AF 0 selection
  */

#define LL_GPIO_AF0_SWJ           LL_GPIO_AF_0   /*!< SWJ (SWD) Alternate Function mapping */
#define LL_GPIO_AF0_MCO           LL_GPIO_AF_0   /*!< MCO Alternate Function mapping */
#define LL_GPIO_AF0_TRACE         LL_GPIO_AF_0   /*!< TRACE Alternate Function mapping */

/**
  * @brief   AF 1 selection
  */
#define LL_GPIO_AF1_LPTIM1        LL_GPIO_AF_1   /*!< LPTIM1 Alternate Function mapping */
#define LL_GPIO_AF1_TIM2          LL_GPIO_AF_1   /*!< TIM2 Alternate Function mapping */
#define LL_GPIO_AF1_TIM5          LL_GPIO_AF_1   /*!< TIM5 Alternate Function mapping */
#define LL_GPIO_AF1_TIM14         LL_GPIO_AF_1   /*!< TIM14 Alternate Function mapping */
#define LL_GPIO_AF1_TIM15         LL_GPIO_AF_1   /*!< TIM15 Alternate Function mapping */
#define LL_GPIO_AF1_TIM16         LL_GPIO_AF_1   /*!< TIM16 Alternate Function mapping */
#define LL_GPIO_AF1_TIM17         LL_GPIO_AF_1   /*!< TIM17 Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define LL_GPIO_AF2_TIM1          LL_GPIO_AF_2   /*!< TIM1 Alternate Function mapping */
#define LL_GPIO_AF2_TIM2          LL_GPIO_AF_2   /*!< TIM2 Alternate Function mapping */
#define LL_GPIO_AF2_TIM3          LL_GPIO_AF_2   /*!< TIM3 Alternate Function mapping */
#define LL_GPIO_AF2_TIM4          LL_GPIO_AF_2   /*!< TIM4 Alternate Function mapping */
#define LL_GPIO_AF2_TIM5          LL_GPIO_AF_2   /*!< TIM5 Alternate Function mapping */
#define LL_GPIO_AF2_TIM8          LL_GPIO_AF_2   /*!< TIM8 Alternate Function mapping */
#define LL_GPIO_AF2_TIM9          LL_GPIO_AF_2   /*!< TIM9 Alternate Function mapping */
#define LL_GPIO_AF2_TIM15         LL_GPIO_AF_2   /*!< TIM15 Alternate Function mapping */
#define LL_GPIO_AF2_I2C3          LL_GPIO_AF_2   /*!< I2C3 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define LL_GPIO_AF3_TIM8          LL_GPIO_AF_3   /*!< TIM8 Alternate Function mapping */
#define LL_GPIO_AF3_TIM9          LL_GPIO_AF_3   /*!< TIM9 Alternate Function mapping */
#define LL_GPIO_AF3_TIM10         LL_GPIO_AF_3   /*!< TIM10 Alternate Function mapping */
#define LL_GPIO_AF3_TIM11         LL_GPIO_AF_3   /*!< TIM11 Alternate Function mapping */
#define LL_GPIO_AF3_TIM12         LL_GPIO_AF_3   /*!< TIM12 Alternate Function mapping */
#define LL_GPIO_AF3_TIM13         LL_GPIO_AF_3   /*!< TIM13 Alternate Function mapping */
#define LL_GPIO_AF3_TIM14         LL_GPIO_AF_3   /*!< TIM14 Alternate Function mapping */
#define LL_GPIO_AF3_TIM15         LL_GPIO_AF_3   /*!< TIM15 Alternate Function mapping */
#define LL_GPIO_AF3_TIM18         LL_GPIO_AF_3   /*!< TIM18 Alternate Function mapping */
#define LL_GPIO_AF3_COMP3         LL_GPIO_AF_3   /*!< COMP3 Alternate Function mapping */
#define LL_GPIO_AF3_CTC           LL_GPIO_AF_3   /*!< CTC Alternate Function mapping */
#define LL_GPIO_AF3_I2C4          LL_GPIO_AF_3   /*!< I2C4 Alternate Function mapping */

/**
  * @brief   AF 4 selection
  */
#define LL_GPIO_AF4_TIM1          LL_GPIO_AF_4   /*!< TIM1 Alternate Function mapping*/
#define LL_GPIO_AF4_TIM8          LL_GPIO_AF_4   /*!< TIM8 Alternate Function mapping*/
#define LL_GPIO_AF4_TIM16         LL_GPIO_AF_4   /*!< TIM16 Alternate Function mapping*/
#define LL_GPIO_AF4_TIM17         LL_GPIO_AF_4   /*!< TIM17 Alternate Function mapping*/
#define LL_GPIO_AF4_TIM18         LL_GPIO_AF_4   /*!< TIM18 Alternate Function mapping*/
#define LL_GPIO_AF4_TIM19         LL_GPIO_AF_4   /*!< TIM19 Alternate Function mapping*/
#define LL_GPIO_AF4_I2C1          LL_GPIO_AF_4   /*!< I2C1 Alternate Function mapping*/
#define LL_GPIO_AF4_I2C2          LL_GPIO_AF_4   /*!< I2C2 Alternate Function mapping*/
#define LL_GPIO_AF4_I2C3          LL_GPIO_AF_4   /*!< I2C3 Alternate Function mapping*/
#define LL_GPIO_AF4_I2C4          LL_GPIO_AF_4   /*!< I2C4 Alternate Function mapping*/

/**
  * @brief   AF 5 selection
  */
#define LL_GPIO_AF5_TIM8          LL_GPIO_AF_5   /*!< TIM8 Alternate Function mapping*/
#define LL_GPIO_AF5_SPI1          LL_GPIO_AF_5   /*!< SPI1 Alternate Function mapping*/
#define LL_GPIO_AF5_SPI2          LL_GPIO_AF_5   /*!< SPI2 Alternate Function mapping*/
#define LL_GPIO_AF5_I2S1          LL_GPIO_AF_5   /*!< I2S1 Alternate Function mapping*/
#define LL_GPIO_AF5_I2S2          LL_GPIO_AF_5   /*!< I2S2 Alternate Function mapping*/
#define LL_GPIO_AF5_I2S3          LL_GPIO_AF_5   /*!< I2S3 Alternate Function mapping*/
#define LL_GPIO_AF5_IR            LL_GPIO_AF_5   /*!< IR Alternate Function mapping*/
#define LL_GPIO_AF5_UART1         LL_GPIO_AF_5   /*!< UART1 Alternate Function mapping*/
#define LL_GPIO_AF5_UART2         LL_GPIO_AF_5   /*!< UART2 Alternate Function mapping*/

/**
  * @brief   AF 6 selection
  */
#define LL_GPIO_AF6_TIM1          LL_GPIO_AF_6   /*!< TIM1 Alternate Function mapping */
#define LL_GPIO_AF6_TIM5          LL_GPIO_AF_6   /*!< TIM5 Alternate Function mapping */
#define LL_GPIO_AF6_TIM8          LL_GPIO_AF_6   /*!< TIM8 Alternate Function mapping */
#define LL_GPIO_AF6_SPI2          LL_GPIO_AF_6   /*!< SPI2 Alternate Function mapping */
#define LL_GPIO_AF6_SPI3          LL_GPIO_AF_6   /*!< SPI3 Alternate Function mapping */
#define LL_GPIO_AF6_I2S2          LL_GPIO_AF_6   /*!< I2S2 Alternate Function mapping */
#define LL_GPIO_AF6_I2S3          LL_GPIO_AF_6   /*!< I2S3 Alternate Function mapping */
#define LL_GPIO_AF6_LCDC          LL_GPIO_AF_6   /*!< LCDC Alternate Function mapping */
#define LL_GPIO_AF6_IR            LL_GPIO_AF_6   /*!< IR Alternate Function mapping */

/**
  * @brief   AF 7 selection
  */
#define LL_GPIO_AF7_TIM12          LL_GPIO_AF_7   /*!< TIM12 Alternate Function mapping */
#define LL_GPIO_AF7_USART1         LL_GPIO_AF_7   /*!< USART1 Alternate Function mapping */
#define LL_GPIO_AF7_USART2         LL_GPIO_AF_7   /*!< USART2 Alternate Function mapping */
#define LL_GPIO_AF7_USART3         LL_GPIO_AF_7   /*!< USART3 Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define LL_GPIO_AF8_TIM18          LL_GPIO_AF_8   /*!< TIM18 Alternate Function mapping*/
#define LL_GPIO_AF8_LPUART1        LL_GPIO_AF_8   /*!< LPUART1 Alternate Function mapping*/
#define LL_GPIO_AF8_COMP1          LL_GPIO_AF_8   /*!< COMP1 Alternate Function mapping*/
#define LL_GPIO_AF8_COMP2          LL_GPIO_AF_8   /*!< COMP2 Alternate Function mapping*/
#define LL_GPIO_AF8_COMP3          LL_GPIO_AF_8   /*!< COMP3 Alternate Function mapping*/
#define LL_GPIO_AF8_COMP4          LL_GPIO_AF_8   /*!< COMP4 Alternate Function mapping*/
#define LL_GPIO_AF8_I2C3           LL_GPIO_AF_8   /*!< I2C3 Alternate Function mapping*/
#define LL_GPIO_AF8_I2C4           LL_GPIO_AF_8   /*!< I2C4 Alternate Function mapping*/
#define LL_GPIO_AF8_CTC            LL_GPIO_AF_8   /*!< CTC Alternate Function mapping*/

/**
  * @brief   AF 9 selection
  */
#define LL_GPIO_AF9_TIM1           LL_GPIO_AF_9   /*!< TIM1 Alternate Function mapping*/
#define LL_GPIO_AF9_TIM8           LL_GPIO_AF_9   /*!< TIM8 Alternate Function mapping*/
#define LL_GPIO_AF9_TIM15          LL_GPIO_AF_9   /*!< TIM15 Alternate Function mapping*/
#define LL_GPIO_AF9_FDCAN1         LL_GPIO_AF_9   /*!< FDCAN1 Alternate Function mapping*/
#define LL_GPIO_AF9_FDCAN2         LL_GPIO_AF_9   /*!< FDCAN2 Alternate Function mapping*/
#define LL_GPIO_AF9_ESMC           LL_GPIO_AF_9   /*!< ESMC Alternate Function mapping*/

/**
  * @brief   AF 10 selection
  */
#define LL_GPIO_AF10_TIM2          LL_GPIO_AF_10  /*!< TIM2 Alternate Function mapping*/
#define LL_GPIO_AF10_TIM3          LL_GPIO_AF_10  /*!< TIM3 Alternate Function mapping*/
#define LL_GPIO_AF10_TIM4          LL_GPIO_AF_10  /*!< TIM4 Alternate Function mapping*/
#define LL_GPIO_AF10_TIM8          LL_GPIO_AF_10  /*!< TIM8 Alternate Function mapping*/
#define LL_GPIO_AF10_TIM17         LL_GPIO_AF_10  /*!< TIM17 Alternate Function mapping*/
#define LL_GPIO_AF10_ESMC          LL_GPIO_AF_10  /*!< ESMC Alternate Function mapping*/

/**
  * @brief   AF 11 selection
  */
#define LL_GPIO_AF11_LPTIM1        LL_GPIO_AF_11  /*!< LPTIM1 Alternate Function mapping*/
#define LL_GPIO_AF11_TIM1          LL_GPIO_AF_11  /*!< TIM1 Alternate Function mapping*/
#define LL_GPIO_AF11_TIM8          LL_GPIO_AF_11  /*!< TIM8 Alternate Function mapping*/
#define LL_GPIO_AF11_TIM19         LL_GPIO_AF_11  /*!< TIM19 Alternate Function mapping*/
#define LL_GPIO_AF11_SDIO          LL_GPIO_AF_11  /*!< SDIO Alternate Function mapping*/
#define LL_GPIO_AF11_LCDC          LL_GPIO_AF_11  /*!< LCDC Alternate Function mapping*/

/**
  * @brief   AF 12 selection
  */
#define LL_GPIO_AF12_TIM1          LL_GPIO_AF_12  /*!< TIM1 Alternate Function mapping*/
#define LL_GPIO_AF12_TIM11         LL_GPIO_AF_12  /*!< TIM11 Alternate Function mapping*/
#define LL_GPIO_AF12_LCDC          LL_GPIO_AF_12  /*!< LCDC Alternate Function mapping*/
#define LL_GPIO_AF12_LPUART1       LL_GPIO_AF_12  /*!< LPUART1 Alternate Function mapping*/

/**
  * @brief   AF 13 selection
  */
#define LL_GPIO_AF13_TIM19         LL_GPIO_AF_13  /*!< TIM19 Alternate Function mapping*/
#define LL_GPIO_AF13_ETH           LL_GPIO_AF_13  /*!< ETH Alternate Function mapping*/
#define LL_GPIO_AF13_LCDC          LL_GPIO_AF_13  /*!< LCDC Alternate Function mapping*/

/**
  * @brief   AF 14 selection
  */
#define LL_GPIO_AF14_TIM2          LL_GPIO_AF_14  /*!< TIM2 Alternate Function mapping*/
#define LL_GPIO_AF14_UART3         LL_GPIO_AF_14  /*!< UART3 Alternate Function mapping*/
#define LL_GPIO_AF14_USB1          LL_GPIO_AF_14  /*!< USB1 Alternate Function mapping*/
#define LL_GPIO_AF14_USB2          LL_GPIO_AF_14  /*!< USB2 Alternate Function mapping*/

/**
  * @brief   AF 15 selection
  */
#define LL_GPIO_AF15_EVENT         LL_GPIO_AF_15  /*!< EVENT Alternate Function mapping*/

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Macros GPIO Exported Macros
  * @{
  */

/** @defgroup GPIO_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_GPIO_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_GPIO_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_LL_EF_Port_Configuration Port Configuration
  * @{
  */

/**
  * @brief  Configure gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll MODER        MODEy         LL_GPIO_SetPinMode
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  *         @arg @ref LL_GPIO_MODE_ALTERNATE
  *         @arg @ref LL_GPIO_MODE_ANALOG
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
  MODIFY_REG(GPIOx->MODER, ((Pin * Pin) * GPIO_MODER_MODE0), ((Pin * Pin) * Mode));
}

/**
  * @brief  Return gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll MODER        MODEy         LL_GPIO_GetPinMode
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  *         @arg @ref LL_GPIO_MODE_ALTERNATE
  *         @arg @ref LL_GPIO_MODE_ANALOG
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->MODER, ((Pin * Pin) * GPIO_MODER_MODE0)) / (Pin * Pin));
}

/**
  * @brief  Configure gpio output type for several pins on dedicated port.
  * @note   Output type as to be set when gpio pin is in output or
  *         alternate modes. Possible type are Push-pull or Open-drain.
  * @rmtoll OTYPER       OTy           LL_GPIO_SetPinOutputType
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @param  OutputType This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref LL_GPIO_OUTPUT_OPENDRAIN
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t PinMask, uint32_t OutputType)
{
  MODIFY_REG(GPIOx->OTYPER, PinMask, (PinMask * OutputType));
}

/**
  * @brief  Return gpio output type for several pins on dedicated port.
  * @note   Output type as to be set when gpio pin is in output or
  *         alternate modes. Possible type are Push-pull or Open-drain.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll OTYPER       OTy           LL_GPIO_GetPinOutputType
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref LL_GPIO_OUTPUT_OPENDRAIN
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->OTYPER, Pin) / Pin);
}

/**
  * @brief  Configure gpio speed for a dedicated pin on dedicated port.
  * @note   I/O speed can be Low, Medium, High or Very High speed.
  * @note   Warning: only one pin can be passed as parameter.
  * @note   Refer to datasheet for frequency specifications and the power
  *         supply and load conditions for each speed.
  * @rmtoll OSPEEDR      OSPEEDy       LL_GPIO_SetPinSpeed
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Speed This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref LL_GPIO_SPEED_FREQ_HIGH
  *         @arg @ref LL_GPIO_SPEED_FREQ_VERY_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetPinSpeed(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t  Speed)
{
  MODIFY_REG(GPIOx->OSPEEDR, ((Pin * Pin) * GPIO_OSPEEDR_OSPEED0), ((Pin * Pin) * Speed));
}

/**
  * @brief  Return gpio speed for a dedicated pin on dedicated port.
  * @note   I/O speed can be Low, Medium, High or Very High speed.
  * @note   Warning: only one pin can be passed as parameter.
  * @note   Refer to datasheet for frequency specifications and the power
  *         supply and load conditions for each speed.
  * @rmtoll OSPEEDR      OSPEEDy       LL_GPIO_GetPinSpeed
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref LL_GPIO_SPEED_FREQ_HIGH
  *         @arg @ref LL_GPIO_SPEED_FREQ_VERY_HIGH
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinSpeed(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->OSPEEDR, ((Pin * Pin) * GPIO_OSPEEDR_OSPEED0)) / (Pin * Pin));
}

/**
  * @brief  Configure gpio pull-up or pull-down for a dedicated pin on a dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll PUPDR        PUPDy         LL_GPIO_SetPinPull
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Pull This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PULL_NO
  *         @arg @ref LL_GPIO_PULL_UP
  *         @arg @ref LL_GPIO_PULL_DOWN
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Pull)
{
  MODIFY_REG(GPIOx->PUPDR, ((Pin * Pin) * GPIO_PUPDR_PUPD0), ((Pin * Pin) * Pull));
}

/**
  * @brief  Return gpio pull-up or pull-down for a dedicated pin on a dedicated port
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll PUPDR        PUPDy         LL_GPIO_GetPinPull
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_PULL_NO
  *         @arg @ref LL_GPIO_PULL_UP
  *         @arg @ref LL_GPIO_PULL_DOWN
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->PUPDR, ((Pin * Pin) * GPIO_PUPDR_PUPD0)) / (Pin * Pin));
}

/**
  * @brief  Configure gpio alternate function of a dedicated pin from 0 to 7 for a dedicated port.
  * @note   Possible values are from AF0 to AF15 depending on target.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll AFRL         AFSELy        LL_GPIO_SetAFPin_0_7
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  * @param  Alternate This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_AF_0
  *         @arg @ref LL_GPIO_AF_1
  *         @arg @ref LL_GPIO_AF_2
  *         @arg @ref LL_GPIO_AF_3
  *         @arg @ref LL_GPIO_AF_4
  *         @arg @ref LL_GPIO_AF_5
  *         @arg @ref LL_GPIO_AF_6
  *         @arg @ref LL_GPIO_AF_7
  *         @arg @ref LL_GPIO_AF_8
  *         @arg @ref LL_GPIO_AF_9
  *         @arg @ref LL_GPIO_AF_10
  *         @arg @ref LL_GPIO_AF_11
  *         @arg @ref LL_GPIO_AF_12
  *         @arg @ref LL_GPIO_AF_13
  *         @arg @ref LL_GPIO_AF_14
  *         @arg @ref LL_GPIO_AF_15
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetAFPin_0_7(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Alternate)
{
  MODIFY_REG(GPIOx->AFR[0], ((((Pin * Pin) * Pin) * Pin) * GPIO_AFRL_AFSEL0),
             ((((Pin * Pin) * Pin) * Pin) * Alternate));
}

/**
  * @brief  Return gpio alternate function of a dedicated pin from 0 to 7 for a dedicated port.
  * @rmtoll AFRL         AFSELy        LL_GPIO_GetAFPin_0_7
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_AF_0
  *         @arg @ref LL_GPIO_AF_1
  *         @arg @ref LL_GPIO_AF_2
  *         @arg @ref LL_GPIO_AF_3
  *         @arg @ref LL_GPIO_AF_4
  *         @arg @ref LL_GPIO_AF_5
  *         @arg @ref LL_GPIO_AF_6
  *         @arg @ref LL_GPIO_AF_7
  *         @arg @ref LL_GPIO_AF_8
  *         @arg @ref LL_GPIO_AF_9
  *         @arg @ref LL_GPIO_AF_10
  *         @arg @ref LL_GPIO_AF_11
  *         @arg @ref LL_GPIO_AF_12
  *         @arg @ref LL_GPIO_AF_13
  *         @arg @ref LL_GPIO_AF_14
  *         @arg @ref LL_GPIO_AF_15
  */
__STATIC_INLINE uint32_t LL_GPIO_GetAFPin_0_7(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->AFR[0],
                             ((((Pin * Pin) * Pin) * Pin) * GPIO_AFRL_AFSEL0)) / (((Pin * Pin) * Pin) * Pin));
}

/**
  * @brief  Configure gpio alternate function of a dedicated pin from 8 to 15 for a dedicated port.
  * @note   Possible values are from AF0 to AF15 depending on target.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll AFRH         AFSELy        LL_GPIO_SetAFPin_8_15
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Alternate This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_AF_0
  *         @arg @ref LL_GPIO_AF_1
  *         @arg @ref LL_GPIO_AF_2
  *         @arg @ref LL_GPIO_AF_3
  *         @arg @ref LL_GPIO_AF_4
  *         @arg @ref LL_GPIO_AF_5
  *         @arg @ref LL_GPIO_AF_6
  *         @arg @ref LL_GPIO_AF_7
  *         @arg @ref LL_GPIO_AF_8
  *         @arg @ref LL_GPIO_AF_9
  *         @arg @ref LL_GPIO_AF_10
  *         @arg @ref LL_GPIO_AF_11
  *         @arg @ref LL_GPIO_AF_12
  *         @arg @ref LL_GPIO_AF_13
  *         @arg @ref LL_GPIO_AF_14
  *         @arg @ref LL_GPIO_AF_15
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetAFPin_8_15(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Alternate)
{
  MODIFY_REG(GPIOx->AFR[1], (((((Pin >> 8U) * (Pin >> 8U)) * (Pin >> 8U)) * (Pin >> 8U)) * GPIO_AFRH_AFSEL8),
             (((((Pin >> 8U) * (Pin >> 8U)) * (Pin >> 8U)) * (Pin >> 8U)) * Alternate));
}

/**
  * @brief  Return gpio alternate function of a dedicated pin from 8 to 15 for a dedicated port.
  * @note   Possible values are from AF0 to AF15 depending on target.
  * @rmtoll AFRH         AFSELy        LL_GPIO_GetAFPin_8_15
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_AF_0
  *         @arg @ref LL_GPIO_AF_1
  *         @arg @ref LL_GPIO_AF_2
  *         @arg @ref LL_GPIO_AF_3
  *         @arg @ref LL_GPIO_AF_4
  *         @arg @ref LL_GPIO_AF_5
  *         @arg @ref LL_GPIO_AF_6
  *         @arg @ref LL_GPIO_AF_7
  *         @arg @ref LL_GPIO_AF_8
  *         @arg @ref LL_GPIO_AF_9
  *         @arg @ref LL_GPIO_AF_10
  *         @arg @ref LL_GPIO_AF_11
  *         @arg @ref LL_GPIO_AF_12
  *         @arg @ref LL_GPIO_AF_13
  *         @arg @ref LL_GPIO_AF_14
  *         @arg @ref LL_GPIO_AF_15
  */
__STATIC_INLINE uint32_t LL_GPIO_GetAFPin_8_15(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)(READ_BIT(GPIOx->AFR[1],
                             (((((Pin >> 8U) * (Pin >> 8U)) * (Pin >> 8U)) * (Pin >> 8U)) * GPIO_AFRH_AFSEL8)) /
                             ((((Pin >> 8U) * (Pin >> 8U)) * (Pin >> 8U)) * (Pin >> 8U)));
}


/**
  * @brief  Lock configuration of several pins for a dedicated port.
  * @note   When the lock sequence has been applied on a port bit, the
  *         value of this port bit can no longer be modified until the
  *         next reset.
  * @note   Each lock bit freezes a specific configuration register
  *         (control and alternate function registers).
  * @rmtoll LCKR         LCKK          LL_GPIO_LockPin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  __IO uint32_t temp;
  WRITE_REG(GPIOx->LCKR, GPIO_LCKR_LCKK | PinMask);
  WRITE_REG(GPIOx->LCKR, PinMask);
  WRITE_REG(GPIOx->LCKR, GPIO_LCKR_LCKK | PinMask);
  /* Read LCKK register. This read is mandatory to complete key lock sequence */
  temp = READ_REG(GPIOx->LCKR);
  (void) temp;
}

/**
  * @brief  Return 1 if all pins passed as parameter, of a dedicated port, are locked. else Return 0.
  * @rmtoll LCKR         LCKy          LL_GPIO_IsPinLocked
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsPinLocked(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  return (READ_BIT(GPIOx->LCKR, PinMask) == (PinMask));
}

/**
  * @brief  Return 1 if one of the pin of a dedicated port is locked. else return 0.
  * @rmtoll LCKR         LCKK          LL_GPIO_IsAnyPinLocked
  * @param  GPIOx GPIO Port
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsAnyPinLocked(GPIO_TypeDef *GPIOx)
{
  return (READ_BIT(GPIOx->LCKR, LL_GPIO_LCKR_LCKK) != 0U);
}

/**
  * @}
  */

/** @defgroup GPIO_LL_EF_Data_Access Data Access
  * @{
  */

/**
  * @brief  Return full input data register value for a dedicated port.
  * @rmtoll IDR          IDy           LL_GPIO_ReadInputPort
  * @param  GPIOx GPIO Port
  * @retval Input data register value of port
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadInputPort(GPIO_TypeDef *GPIOx)
{
  return (uint32_t)(READ_REG(GPIOx->IDR));
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @rmtoll IDR          IDy           LL_GPIO_IsInputPinSet
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsInputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  return (READ_BIT(GPIOx->IDR, PinMask) == (PinMask));
}

/**
  * @brief  Write output data register for the port.
  * @rmtoll ODR          ODy           LL_GPIO_WriteOutputPort
  * @param  GPIOx GPIO Port
  * @param  PortValue Level value for each pin of the port
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_WriteOutputPort(GPIO_TypeDef *GPIOx, uint32_t PortValue)
{
  WRITE_REG(GPIOx->ODR, PortValue);
}

/**
  * @brief  Return full output data register value for a dedicated port.
  * @rmtoll ODR          ODy           LL_GPIO_ReadOutputPort
  * @param  GPIOx GPIO Port
  * @retval Output data register value of port
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadOutputPort(GPIO_TypeDef *GPIOx)
{
  return (uint32_t)(READ_REG(GPIOx->ODR));
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @rmtoll ODR          ODy           LL_GPIO_IsOutputPinSet
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsOutputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  return (READ_BIT(GPIOx->ODR, PinMask) == (PinMask));
}

/**
  * @brief  Set several pins to high level on dedicated gpio port.
  * @rmtoll BSRR         BSy           LL_GPIO_SetOutputPin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  WRITE_REG(GPIOx->BSRR, PinMask);
}

/**
  * @brief  Set several pins to low level on dedicated gpio port.
  * @rmtoll BRR          BRy           LL_GPIO_ResetOutputPin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_ResetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  WRITE_REG(GPIOx->BRR, PinMask);
}

/**
  * @brief  Toggle data value for several pin of dedicated port.
  * @rmtoll ODR          ODy           LL_GPIO_TogglePin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  WRITE_REG(GPIOx->ODR, READ_REG(GPIOx->ODR) ^ PinMask);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct);
void        LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct);

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

#endif /* defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOE) || defined (GPIOF)*/
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_LL_GPIO_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

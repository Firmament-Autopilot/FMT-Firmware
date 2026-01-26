/**
  ******************************************************************************
  * @file    py32e407_hal_rcc_ex.h
  * @author  MCU Application Team
  * @brief   Header file of RCC HAL Extended module.
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
#ifndef __PY32E407_HAL_RCC_EX_H
#define __PY32E407_HAL_RCC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup RCCEx
  * @{
  */

/* Private Constants ---------------------------------------------------------*/
/** @addtogroup RCCEx_Private_Constants
 * @{
 */

/**
  * @}
  */

/* Private Macros ------------------------------------------------------------*/
/** @addtogroup RCCEx_Private_Macros
 * @{
 */

#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) >= 2U) && ((__MUL__) <= 257U))

#define IS_RCC_MCOSOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCOSOURCE_NOCLOCK)  || ((__SOURCE__) == RCC_MCOSOURCE_LSE)    || \
                                       ((__SOURCE__) == RCC_MCOSOURCE_LSI)      || ((__SOURCE__) == RCC_MCOSOURCE_HSI48M) || \
                                       ((__SOURCE__) == RCC_MCOSOURCE_SYSCLK)   || ((__SOURCE__) == RCC_MCOSOURCE_HSI16M) || \
                                       ((__SOURCE__) == RCC_MCOSOURCE_HSE)      || ((__SOURCE__) == RCC_MCOSOURCE_PLLCLK) || \
                                       ((__SOURCE__) == RCC_MCOSOURCE_HCLK)     || ((__SOURCE__) == RCC_MCOSOURCE_PCLK1)  || \
                                       ((__SOURCE__) == RCC_MCOSOURCE_PCLK2)    || ((__SOURCE__) == RCC_MCOSOURCE_HSI10M))

#define IS_RCC_ADCPLLCLK_DIV(__ADCCLK__) (((__ADCCLK__) == RCC_ADCPCLK2_DIV2)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV4)   || \
                                          ((__ADCCLK__) == RCC_ADCPCLK2_DIV6)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV8)   || \
                                          ((__ADCCLK__) == RCC_ADCPCLK2_DIV12) || ((__ADCCLK__) == RCC_ADCPCLK2_DIV16))

#define IS_RCC_USBCLKSOURCE(__USBCLK__)  (((__USBCLK__) == RCC_USBCLKSOURCE_PLL)      || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV1_5)   || \
                                          ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV2) || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV2_5)   || \
                                          ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV3) || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV3_5)   || \
                                          ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV4) || ((__USBCLK__) == RCC_USBCLKSOURCE_HSI48M))

#define IS_RCC_SRAM2CLK_DIV(_SRAM2CLK__) (((_SRAM2CLK__) == RCC_SRAM2HCLK_DIV1)  || ((_SRAM2CLK__) == RCC_SRAM2HCLK_DIV2))





#define IS_RCC_CANCLKSOURCE(__CANCLK__)  (((__CANCLK__) == RCC_CANCLKSOURCE_PLL)      || ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV2)   || \
                                          ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV3) || ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV4)   || \
                                          ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV5) || ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV6)   || \
                                          ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV7) || ((__CANCLK__) == RCC_CANCLKSOURCE_PLL_DIV8)   || \
                                          ((__CANCLK__) == RCC_CANCLKSOURCE_HSE))

#define IS_RCC_PVDFILTERCLK(__PVDFILTERCLK__) (((__PVDFILTERCLK__) == RCC_PVDFILTERCLK_LSI)  || ((__PVDFILTERCLK__) == RCC_PVDFILTERCLK_LSE)  || \
                                               ((__PVDFILTERCLK__) == RCC_PVDFILTERCLK_PCLK1))

#define IS_RCC_USART1CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_USART1CLKSOURCE_PCLK2)  || ((__SOURCE__) == RCC_USART1CLKSOURCE_SYSCLK) || \
                                            ((__SOURCE__) == RCC_USART1CLKSOURCE_LSE)    || ((__SOURCE__) == RCC_USART1CLKSOURCE_HSI))

#define IS_RCC_USART2CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_USART2CLKSOURCE_PCLK1)  || ((__SOURCE__) == RCC_USART2CLKSOURCE_SYSCLK) || \
                                            ((__SOURCE__) == RCC_USART2CLKSOURCE_LSE)    || ((__SOURCE__) == RCC_USART2CLKSOURCE_HSI))

#define IS_RCC_USART3CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_USART3CLKSOURCE_PCLK1)  || ((__SOURCE__) == RCC_USART3CLKSOURCE_SYSCLK) || \
                                            ((__SOURCE__) == RCC_USART3CLKSOURCE_LSE)    || ((__SOURCE__) == RCC_USART3CLKSOURCE_HSI))

#define IS_RCC_LPUART1CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_LPUART1CLKSOURCE_PCLK1)  || ((__SOURCE__) == RCC_LPUART1CLKSOURCE_SYSCLK) || \
                                             ((__SOURCE__) == RCC_LPUART1CLKSOURCE_LSE)    || ((__SOURCE__) == RCC_LPUART1CLKSOURCE_HSI))

#define IS_RCC_LPTIM1CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_LPTIM1CLKSOURCE_PCLK1) || ((__SOURCE__) == RCC_LPTIM1CLKSOURCE_LSI)   || \
                                            ((__SOURCE__) == RCC_LPTIM1CLKSOURCE_HSI)   || ((__SOURCE__) == RCC_LPTIM1CLKSOURCE_LSE))

#define IS_RCC_COMP1CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_COMP1CLKSOURCE_PCLK2) || ((__SOURCE__) == RCC_COMP1CLKSOURCE_LSI)   || \
                                           ((__SOURCE__) == RCC_COMP1CLKSOURCE_LSE))

#define IS_RCC_COMP2CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_COMP2CLKSOURCE_PCLK2) || ((__SOURCE__) == RCC_COMP2CLKSOURCE_LSI)   || \
                                           ((__SOURCE__) == RCC_COMP2CLKSOURCE_LSE))

#define IS_RCC_COMP3CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_COMP3CLKSOURCE_PCLK2) || ((__SOURCE__) == RCC_COMP3CLKSOURCE_LSI)   || \
                                           ((__SOURCE__) == RCC_COMP3CLKSOURCE_LSE))

#define IS_RCC_COMP4CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_COMP4CLKSOURCE_PCLK2) || ((__SOURCE__) == RCC_COMP4CLKSOURCE_LSI)   || \
                                           ((__SOURCE__) == RCC_COMP4CLKSOURCE_LSE))

#define IS_RCC_PERIPHCLOCK(PERIPHCLOCK)  ((PERIPHCLOCK) <= RCC_PERIPHCLK_MASK)

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Types RCCEx Exported Types
  * @{
  */

/**
  * @brief  RCC extended clocks structure definition
  */
typedef struct
{
  uint32_t PeriphClockSelection;            /*!< The Extended Clock to be configured.
                                            This parameter can be a value of @ref RCCEx_Periph_Clock_Selection */

  uint32_t RtcClockSelection;              /*!< specifies the RTC clock source.
                                             This parameter can be a value of @ref RCC_RTC_Clock_Source */
  
  uint32_t AdcClockSelection;              /*!< ADC clock source
                                            This parameter can be a value of @ref RCCEx_ADC_Prescaler */

  uint32_t UsbClockSelection;              /*!< USB clock source
                                            This parameter can be a value of @ref RCCEx_USB_Prescaler */

  uint32_t Sram2ClockSelection;            /*!< SRAM2 clock source
                                            This parameter can be a value of @ref RCCEx_SRAM2_Prescaler */

  uint32_t CanClockSelection;              /*!< CAN clock source
                                            This parameter can be a value of @ref RCCEx_CAN_Clock_Source */
  
  uint32_t PvdFilterClockSelection;        /*!< PVD filter clock source
                                            This parameter can be a value of @ref RCCEx_PVD_Filter_Clock_Source */
  
  uint32_t Usart1ClockSelection;           /*!< Specifies USART1 clock source.
                                            This parameter can be a value of @ref RCCEx_USART1_Clock_Source */

  uint32_t Usart2ClockSelection;           /*!< Specifies USART2 clock source.
                                            This parameter can be a value of @ref RCCEx_USART2_Clock_Source */

  uint32_t Usart3ClockSelection;           /*!< Specifies USART3 clock source.
                                            This parameter can be a value of @ref RCCEx_USART3_Clock_Source */

  uint32_t Lpuart1ClockSelection;          /*!< Specifies LPUART1 clock source.
                                            This parameter can be a value of @ref RCCEx_LPUART1_Clock_Source */

  uint32_t Lptim1ClockSelection;           /*!< Specifies LPTIM1 clock source.
                                            This parameter can be a value of @ref RCCEx_LPTIM1_Clock_Source */
  
  uint32_t Comp1ClockSelection;            /*!< Specifies COMP1 clock source.
                                            This parameter can be a value of @ref RCCEx_COMP1_Clock_Source */
  
  uint32_t Comp2ClockSelection;            /*!< Specifies COMP2 clock source.
                                            This parameter can be a value of @ref RCCEx_COMP2_Clock_Source */
  
  uint32_t Comp3ClockSelection;            /*!< Specifies COMP3 clock source.
                                            This parameter can be a value of @ref RCCEx_COMP3_Clock_Source */
  
  uint32_t Comp4ClockSelection;            /*!< Specifies COMP4 clock source.
                                            This parameter can be a value of @ref RCCEx_COMP4_Clock_Source */
  
} RCC_PeriphCLKInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCCEx_Exported_Constants RCCEx Exported Constants
  * @{
  */

/** @defgroup RCCEx_Periph_Clock_Selection Periph Clock Selection
  * @{
  */
#define RCC_PERIPHCLK_RTC           0x00000001U
#define RCC_PERIPHCLK_ADC           0x00000002U
#define RCC_PERIPHCLK_USB           0x00000004U
#define RCC_PERIPHCLK_SRAM2         0x00000008U
#define RCC_PERIPHCLK_CAN           0x00000010U
#define RCC_PERIPHCLK_PVD           0x00000020U
#define RCC_PERIPHCLK_USART1        0x00000040U
#define RCC_PERIPHCLK_USART2        0x00000080U
#define RCC_PERIPHCLK_USART3        0x00000100U
#define RCC_PERIPHCLK_LPUART1       0x00000200U
#define RCC_PERIPHCLK_LPTIM1        0x00000400U
#define RCC_PERIPHCLK_COMP1         0x00000800U
#define RCC_PERIPHCLK_COMP2         0x00001000U
#define RCC_PERIPHCLK_COMP3         0x00002000U
#define RCC_PERIPHCLK_COMP4         0x00004000U

#define RCC_PERIPHCLK_MASK          0x00007FFFU
/**
  * @}
  */

/** @defgroup RCCEx_ADC_Prescaler ADC Prescaler
  * @{
  */
#define RCC_ADCPCLK2_DIV2              RCC_CFGR_ADCPRE_DIV2
#define RCC_ADCPCLK2_DIV4              RCC_CFGR_ADCPRE_DIV4
#define RCC_ADCPCLK2_DIV6              RCC_CFGR_ADCPRE_DIV6
#define RCC_ADCPCLK2_DIV8              RCC_CFGR_ADCPRE_DIV8
#define RCC_ADCPCLK2_DIV12             RCC_CFGR_ADCPRE_DIV12
#define RCC_ADCPCLK2_DIV16             RCC_CFGR_ADCPRE_DIV16
/**
  * @}
  */

/** @defgroup RCCEx_USB_Prescaler USB Clock Source
  * @{
  */
#define RCC_USBCLKSOURCE_PLL              RCC_CFGR_USBPRE_0
#define RCC_USBCLKSOURCE_PLL_DIV1_5       0x00000000U
#define RCC_USBCLKSOURCE_PLL_DIV2         (RCC_CFGR_USBPRE_1 | RCC_CFGR_USBPRE_0)
#define RCC_USBCLKSOURCE_PLL_DIV2_5       (RCC_CFGR_USBPRE_1)
#define RCC_USBCLKSOURCE_PLL_DIV3         (RCC_CFGR_USBPRE_2)
#define RCC_USBCLKSOURCE_PLL_DIV3_5       (RCC_CFGR_USBPRE_2 | RCC_CFGR_USBPRE_0)
#define RCC_USBCLKSOURCE_PLL_DIV4         (RCC_CFGR_USBPRE_2 | RCC_CFGR_USBPRE_1)
#define RCC_USBCLKSOURCE_HSI48M           RCC_CFGR1_USBSELHSI48
/**
  * @}
  */

/** @defgroup RCCEx_SRAM2_Prescaler SRAM2 Prescaler
  * @{
  */
#define RCC_SRAM2HCLK_DIV1              0x00000000
#define RCC_SRAM2HCLK_DIV2              RCC_CFGR_SRAM2PRE
/**
  * @}
  */

/** @defgroup RCCEx_CAN_Clock_Source CAN Clock Source
  * @{
  */
#define RCC_CANCLKSOURCE_PLL           0x00000000U
#define RCC_CANCLKSOURCE_PLL_DIV2      RCC_CFGR2_CANCKSEL_0
#define RCC_CANCLKSOURCE_PLL_DIV3      RCC_CFGR2_CANCKSEL_1
#define RCC_CANCLKSOURCE_PLL_DIV4      (RCC_CFGR2_CANCKSEL_1 | RCC_CFGR2_CANCKSEL_0)
#define RCC_CANCLKSOURCE_PLL_DIV5      RCC_CFGR2_CANCKSEL_2
#define RCC_CANCLKSOURCE_PLL_DIV6      (RCC_CFGR2_CANCKSEL_2 | RCC_CFGR2_CANCKSEL_0)
#define RCC_CANCLKSOURCE_PLL_DIV7      (RCC_CFGR2_CANCKSEL_2 | RCC_CFGR2_CANCKSEL_1)
#define RCC_CANCLKSOURCE_PLL_DIV8      (RCC_CFGR2_CANCKSEL_2 | RCC_CFGR2_CANCKSEL_1 | RCC_CFGR2_CANCKSEL_0)
#define RCC_CANCLKSOURCE_HSE           RCC_CFGR2_CANCKSEL_3
/**
  * @}
  */

/** @defgroup RCCEx_PVD_Filter_Clock_Source PVD Filter Clock Source
  * @{
  */
#define RCC_PVDFILTERCLK_LSI            0x00000000
#define RCC_PVDFILTERCLK_LSE            RCC_CFGR1_PVDSEL_0
#define RCC_PVDFILTERCLK_PCLK1          RCC_CFGR1_PVDSEL_1
/**
  * @}
  */

/** @defgroup RCCEx_USART1_Clock_Source USART1 Clock Source
  * @{
  */
#define RCC_USART1CLKSOURCE_PCLK2      0x00000000U
#define RCC_USART1CLKSOURCE_SYSCLK     RCC_CCIPR_USART1SEL_0
#define RCC_USART1CLKSOURCE_HSI        RCC_CCIPR_USART1SEL_1
#define RCC_USART1CLKSOURCE_LSE        (RCC_CCIPR_USART1SEL_0 | RCC_CCIPR_USART1SEL_1)
/**
  * @}
  */

/** @defgroup RCCEx_USART2_Clock_Source USART2 Clock Source
  * @{
  */
#define RCC_USART2CLKSOURCE_PCLK1      0x00000000U
#define RCC_USART2CLKSOURCE_SYSCLK     RCC_CCIPR_USART2SEL_0
#define RCC_USART2CLKSOURCE_HSI        RCC_CCIPR_USART2SEL_1
#define RCC_USART2CLKSOURCE_LSE        (RCC_CCIPR_USART2SEL_0 | RCC_CCIPR_USART2SEL_1)
/**
  * @}
  */

/** @defgroup RCCEx_USART3_Clock_Source USART3 Clock Source
  * @{
  */
#define RCC_USART3CLKSOURCE_PCLK1      0x00000000U
#define RCC_USART3CLKSOURCE_SYSCLK     RCC_CCIPR_USART3SEL_0
#define RCC_USART3CLKSOURCE_HSI        RCC_CCIPR_USART3SEL_1
#define RCC_USART3CLKSOURCE_LSE        (RCC_CCIPR_USART3SEL_0 | RCC_CCIPR_USART3SEL_1)
/**
  * @}
  */

/** @defgroup RCCEx_LPUART1_Clock_Source LPUART1 Clock Source
  * @{
  */
#define RCC_LPUART1CLKSOURCE_PCLK1     0x00000000U
#define RCC_LPUART1CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART1SEL_0
#define RCC_LPUART1CLKSOURCE_HSI       RCC_CCIPR_LPUART1SEL_1
#define RCC_LPUART1CLKSOURCE_LSE       (RCC_CCIPR_LPUART1SEL_0 | RCC_CCIPR_LPUART1SEL_1)
/**
  * @}
  */

/** @defgroup RCCEx_LPTIM1_Clock_Source LPTIM1 Clock Source
  * @{
  */
#define RCC_LPTIM1CLKSOURCE_PCLK1      0x00000000U
#define RCC_LPTIM1CLKSOURCE_LSI        RCC_CCIPR_LPTIM1SEL_0
#define RCC_LPTIM1CLKSOURCE_HSI        RCC_CCIPR_LPTIM1SEL_1
#define RCC_LPTIM1CLKSOURCE_LSE        RCC_CCIPR_LPTIM1SEL
/**
  * @}
  */

/** @defgroup RCCEx_COMP1_Clock_Source COMP1 Clock Source
  * @{
  */
#define RCC_COMP1CLKSOURCE_PCLK2      0x00000000U
#define RCC_COMP1CLKSOURCE_LSI        RCC_CCIPR_COMP1SEL_0
#define RCC_COMP1CLKSOURCE_LSE        RCC_CCIPR_COMP1SEL_1
/**
  * @}
  */

/** @defgroup RCCEx_COMP2_Clock_Source COMP2 Clock Source
  * @{
  */
#define RCC_COMP2CLKSOURCE_PCLK2      0x00000000U
#define RCC_COMP2CLKSOURCE_LSI        RCC_CCIPR_COMP2SEL_0
#define RCC_COMP2CLKSOURCE_LSE        RCC_CCIPR_COMP2SEL_1
/**
  * @}
  */

/** @defgroup RCCEx_COMP3_Clock_Source COMP3 Clock Source
  * @{
  */
#define RCC_COMP3CLKSOURCE_PCLK2      0x00000000U
#define RCC_COMP3CLKSOURCE_LSI        RCC_CCIPR_COMP3SEL_0
#define RCC_COMP3CLKSOURCE_LSE        RCC_CCIPR_COMP3SEL_1
/**
  * @}
  */

/** @defgroup RCCEx_COMP4_Clock_Source COMP4 Clock Source
  * @{
  */
#define RCC_COMP4CLKSOURCE_PCLK2      0x00000000U
#define RCC_COMP4CLKSOURCE_LSI        RCC_CCIPR_COMP4SEL_0
#define RCC_COMP4CLKSOURCE_LSE        RCC_CCIPR_COMP4SEL_1
/**
  * @}
  */

/** @defgroup RCCEx_Prediv1_Factor HSE Prediv1 Factor
  * @{
  */

#define RCC_HSE_PREDIV_DIV1              0x00000000U
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR3_PLLXTPRE

/**
  * @}
  */

/** @defgroup RCCEx_PLL_Prediv_Factor PLL Prediv Factor
  * @{
  */
#define RCC_PLL_PREDIV_DIV1             RCC_CFGR3_PLLPREDIV1
#define RCC_PLL_PREDIV_DIV2             RCC_CFGR3_PLLPREDIV2
#define RCC_PLL_PREDIV_DIV4             RCC_CFGR3_PLLPREDIV4
#define RCC_PLL_PREDIV_DIV8             RCC_CFGR3_PLLPREDIV8
/**
  * @}
  */

/** @defgroup RCCEx_PLL_Postdiv_Factor PLL Postdiv Factor
  * @{
  */
#define RCC_PLL_POSTDIV_DIV1            RCC_CFGR3_PLLPOSTDIV1
#define RCC_PLL_POSTDIV_DIV2            RCC_CFGR3_PLLPOSTDIV2
#define RCC_PLL_POSTDIV_DIV4            RCC_CFGR3_PLLPOSTDIV4
#define RCC_PLL_POSTDIV_DIV8            RCC_CFGR3_PLLPOSTDIV8
/**
  * @}
  */

/** @defgroup RCC_MCO_Index MCO Index
  * @{
  */
#define RCC_MCO1                       0x00000000U
#define RCC_MCO                        RCC_MCO1               /*!< MCO1 to be compliant with other families with 2 MCOs*/
#define RCC_MCO2                       0x00000001U

/**
  * @}
  */

/** @defgroup RCCEx_MCO1_Clock_Source MCO1 Clock Source
  * @{
  */
#define RCC_MCOSOURCE_NOCLOCK           ((uint32_t)RCC_CFGR_MCO_NOCLOCK)
#define RCC_MCOSOURCE_SYSCLK            ((uint32_t)RCC_CFGR_MCO_SYSCLK)
#define RCC_MCOSOURCE_HSI16M            ((uint32_t)RCC_CFGR_MCO_HSI16M)
#define RCC_MCOSOURCE_LSI               ((uint32_t)RCC_CFGR_MCO_LSI)
#define RCC_MCOSOURCE_HSE               ((uint32_t)RCC_CFGR_MCO_HSE)
#define RCC_MCOSOURCE_LSE               ((uint32_t)RCC_CFGR_MCO_LSE)
#define RCC_MCOSOURCE_PLLCLK            ((uint32_t)RCC_CFGR_MCO_PLL)
#define RCC_MCOSOURCE_HSI48M            ((uint32_t)RCC_CFGR_MCO_HSI48M)
#define RCC_MCOSOURCE_HCLK              ((uint32_t)RCC_CFGR_MCO_HCLK)
#define RCC_MCOSOURCE_PCLK1             ((uint32_t)RCC_CFGR_MCO_PCLK1)
#define RCC_MCOSOURCE_PCLK2             ((uint32_t)RCC_CFGR_MCO_PCLK2)
#define RCC_MCOSOURCE_HSI10M            ((uint32_t)RCC_CFGR_MCO_HSI10M)
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCCEx_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @brief  Macro to configure the External High Speed oscillator (HSE) Predivision factor for PLL.
  * @note   Predivision factor can not be changed if PLL is used as system clock
  *         In this case, you have to select another source of the system clock, disable the PLL and
  *         then change the HSE predivision factor.
  * @param  __HSE_PREDIV_VALUE__ specifies the division value applied to HSE.
  *         This parameter must be a number between RCC_HSE_PREDIV_DIV1 and RCC_HSE_PREDIV_DIV2.
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR3,RCC_CFGR3_PLLXTPRE, (uint32_t)(__HSE_PREDIV_VALUE__))

/**
  * @brief  Macro to get prediv1 factor for PLL.
  */
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLXTPRE)


/**
  * @}
  */

/** @defgroup RCCEx_Peripheral_Configuration Peripheral Configuration
  * @brief  Macros to configure clock source of different peripherals.
  * @{
  */

/** @brief  Macro to configure the ADCx clock (x=1 to 3 depending on devices).
  * @param  __ADCCLKSOURCE__ specifies the ADC clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2  PCLK2 clock divided by 2  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4  PCLK2 clock divided by 4  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6  PCLK2 clock divided by 6  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8  PCLK2 clock divided by 8  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV12 PCLK2 clock divided by 12 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV16 PCLK2 clock divided by 16 selected as ADC clock
  */
#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

/** @brief  Macro to get the ADC clock (ADCxCLK, x=1 to 3 depending on devices).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2  PCLK2 clock divided by 2  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4  PCLK2 clock divided by 4  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6  PCLK2 clock divided by 6  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8  PCLK2 clock divided by 8  selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV12 PCLK2 clock divided by 12 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV16 PCLK2 clock divided by 16 selected as ADC clock
  */
#define __HAL_RCC_GET_ADC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE)))

/** @brief  Macro to configure the USB clock.
  * @param  __USBCLKSOURCE__ specifies the USB clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL clock divided by 1 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL clock divided by 1.5 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2   PLL clock divided by 2 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2_5 PLL clock divided by 2.5 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3   PLL clock divided by 3 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3_5 PLL clock divided by 3.5 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV4   PLL clock divided by 4 selected as USB clock
*/
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  Macro to get the USB clock.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL clock divided by 1 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL clock divided by 1.5 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2   PLL clock divided by 2 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2_5 PLL clock divided by 2.5 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3   PLL clock divided by 3 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3_5 PLL clock divided by 3.5 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV4   PLL clock divided by 4 selected as USB clock
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

/** @brief  Macro to configure the SRAM2 clock.
  * @param  __SRAM2CLKSOURCE__ specifies the SRAM2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_SRAM2HCLK_DIV1  HCLK clock divided by 1  selected as SRAM2 clock
  *            @arg @ref RCC_SRAM2HCLK_DIV2  HCLK clock divided by 2  selected as SRAM2 clock
  */
#define __HAL_RCC_SRAM2_CONFIG(__SRAM2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SRAM2PRE, (uint32_t)(__SRAM2CLKSOURCE__))

/** @brief  Macro to get the SRAM2 clock.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_SRAM2HCLK_DIV1  HCLK clock divided by 1  selected as SRAM2 clock
  *            @arg @ref RCC_SRAM2HCLK_DIV2  HCLK clock divided by 2  selected as SRAM2 clock
  */
#define __HAL_RCC_GET_SRAM2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SRAM2PRE)))

/** @brief  Macro to configure the CAN clock.
  * @param  __CANCLKSOURCE__ specifies the CAN clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_CANCLKSOURCE_PLL      PLL clock divided by 1 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV4 PLL clock divided by 4 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV5 PLL clock divided by 5 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV6 PLL clock divided by 6 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV7 PLL clock divided by 7 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV8 PLL clock divided by 8 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_HSE      HSE selected as CAN clock
*/
#define __HAL_RCC_CAN_CONFIG(__CANCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_CANCKSEL, (uint32_t)(__CANCLKSOURCE__))

/** @brief  Macro to get the CAN clock.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_CANCLKSOURCE_PLL      PLL clock divided by 1 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV4 PLL clock divided by 4 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV5 PLL clock divided by 5 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV6 PLL clock divided by 6 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV7 PLL clock divided by 7 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_PLL_DIV8 PLL clock divided by 8 selected as CAN clock
  *            @arg @ref RCC_CANCLKSOURCE_HSE      HSE selected as CAN clock
  */
#define __HAL_RCC_GET_CAN_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_CANCKSEL)))

/** @brief  Macro to configure the PVD filter clock.
  * @param  __PVDFILTERCLK__ specifies the SRAM2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_PVDFILTERCLK_LSI  LSI oscillator clock used as PVD filter clock
  *            @arg @ref RCC_PVDFILTERCLK_LSE  LSE oscillator clock used as PVD filter clock
  *            @arg @ref RCC_PVDFILTERCLK_PCLK1 PCLK  used as PVD filter clock
  */
#define __HAL_RCC_PVD_CONFIG(__PVDFILTERCLK__) \
                  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_PVDSEL, (uint32_t)(__PVDFILTERCLK__))

/** @brief  Macro to get the PVD filter clock.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_PVDFILTERCLK_LSI  LSI oscillator clock used as PVD filter clock
  *            @arg @ref RCC_PVDFILTERCLK_LSE  LSE oscillator clock used as PVD filter clock
  *            @arg @ref RCC_PVDFILTERCLK_PCLK1 PCLK  used as PVD filter clock
  */
#define __HAL_RCC_GET_PVD_FILTER_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR1, RCC_CFGR1_PVDSEL)))

/** @brief  Macro to configure the USART1 clock (USART1CLK).
  *
  * @param  __USART1_CLKSOURCE__ specifies the USART1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USART1CLKSOURCE_PCLK2  PCLK2 selected as USART1 clock
  *            @arg @ref RCC_USART1CLKSOURCE_HSI  HSI selected as USART1 clock
  *            @arg @ref RCC_USART1CLKSOURCE_SYSCLK  System Clock selected as USART1 clock
  *            @arg @ref RCC_USART1CLKSOURCE_LSE  LSE selected as USART1 clock
  * @retval None
  */
#define __HAL_RCC_USART1_CONFIG(__USART1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART1SEL, (__USART1_CLKSOURCE__))

/** @brief  Macro to get the USART1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USART1CLKSOURCE_PCLK2  PCLK2 selected as USART1 clock
  *            @arg @ref RCC_USART1CLKSOURCE_HSI  HSI selected as USART1 clock
  *            @arg @ref RCC_USART1CLKSOURCE_SYSCLK  System Clock selected as USART1 clock
  *            @arg @ref RCC_USART1CLKSOURCE_LSE  LSE selected as USART1 clock
  */
#define __HAL_RCC_GET_USART1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_USART1SEL))

/** @brief  Macro to configure the USART2 clock (USART2CLK).
  *
  * @param  __USART2_CLKSOURCE__ specifies the USART2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USART2CLKSOURCE_PCLK1  PCLK1 selected as USART2 clock
  *            @arg @ref RCC_USART2CLKSOURCE_HSI  HSI selected as USART2 clock
  *            @arg @ref RCC_USART2CLKSOURCE_SYSCLK  System Clock selected as USART2 clock
  *            @arg @ref RCC_USART2CLKSOURCE_LSE  LSE selected as USART2 clock
  * @retval None
  */
#define __HAL_RCC_USART2_CONFIG(__USART2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART2SEL, (__USART2_CLKSOURCE__))

/** @brief  Macro to get the USART2 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USART2CLKSOURCE_PCLK1  PCLK1 selected as USART2 clock
  *            @arg @ref RCC_USART2CLKSOURCE_HSI  HSI selected as USART2 clock
  *            @arg @ref RCC_USART2CLKSOURCE_SYSCLK  System Clock selected as USART2 clock
  *            @arg @ref RCC_USART2CLKSOURCE_LSE  LSE selected as USART2 clock
  */
#define __HAL_RCC_GET_USART2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_USART2SEL))

/** @brief  Macro to configure the USART3 clock (USART3CLK).
  *
  * @param  __USART3_CLKSOURCE__ specifies the USART3 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USART3CLKSOURCE_PCLK1  PCLK1 selected as USART3 clock
  *            @arg @ref RCC_USART3CLKSOURCE_HSI  HSI selected as USART3 clock
  *            @arg @ref RCC_USART3CLKSOURCE_SYSCLK  System Clock selected as USART3 clock
  *            @arg @ref RCC_USART3CLKSOURCE_LSE  LSE selected as USART3 clock
  * @retval None
  */
#define __HAL_RCC_USART3_CONFIG(__USART3_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART3SEL, (__USART3_CLKSOURCE__))

/** @brief  Macro to get the USART3 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USART3CLKSOURCE_PCLK1  PCLK1 selected as USART3 clock
  *            @arg @ref RCC_USART3CLKSOURCE_HSI  HSI selected as USART3 clock
  *            @arg @ref RCC_USART3CLKSOURCE_SYSCLK  System Clock selected as USART3 clock
  *            @arg @ref RCC_USART3CLKSOURCE_LSE  LSE selected as USART3 clock
  */
#define __HAL_RCC_GET_USART3_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_USART3SEL))

/** @brief  Macro to configure the LPUART1 clock (LPUART1CLK).
  *
  * @param  __LPUART1_CLKSOURCE__ specifies the LPUART1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LPUART1CLKSOURCE_PCLK1  PCLK1 selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_HSI  HSI selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_SYSCLK  System Clock selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_LSE  LSE selected as LPUART1 clock
  * @retval None
  */
#define __HAL_RCC_LPUART1_CONFIG(__LPUART1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPUART1SEL, (__LPUART1_CLKSOURCE__))

/** @brief  Macro to get the LPUART1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_LPUART1CLKSOURCE_PCLK1  PCLK1 selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_HSI  HSI selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_SYSCLK  System Clock selected as LPUART1 clock
  *            @arg @ref RCC_LPUART1CLKSOURCE_LSE  LSE selected as LPUART1 clock
  */
#define __HAL_RCC_GET_LPUART1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPUART1SEL))

/** @brief  Macro to configure the LPTIM1 clock (LPTIM1CLK).
  *
  * @param  __LPTIM1_CLKSOURCE__ specifies the LPTIM1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LPTIM1CLKSOURCE_PCLK1  PCLK1 selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSI  LSI selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_HSI  HSI selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSE  LSE selected as LPTIM1 clock
  * @retval None
  */
#define __HAL_RCC_LPTIM1_CONFIG(__LPTIM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL, (__LPTIM1_CLKSOURCE__))

/** @brief  Macro to get the LPTIM1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_LPTIM1CLKSOURCE_PCLK1  PCLK1 selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSI  LSI selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_HSI  HSI selected as LPTIM1 clock
  *            @arg @ref RCC_LPTIM1CLKSOURCE_LSE  LSE selected as LPTIM1 clock
  */
#define __HAL_RCC_GET_LPTIM1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL))

/** @brief  Macro to configure the COMP1 clock (COMP1CLK).
  *
  * @param  __COMP1_CLKSOURCE__ specifies the COMP1 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_COMP1CLKSOURCE_PCLK2  PCLK1 selected as COMP1 clock
  *            @arg @ref RCC_COMP1CLKSOURCE_LSI    HSI selected as COMP1 clock
  *            @arg @ref RCC_COMP1CLKSOURCE_LSE    LSE selected as COMP1 clock
  * @retval None
  */
#define __HAL_RCC_COMP1_CONFIG(__COMP1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP1SEL, (__COMP1_CLKSOURCE__))

/** @brief  Macro to get the COMP1 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_COMP1CLKSOURCE_PCLK2  PCLK1 selected as COMP1 clock
  *            @arg @ref RCC_COMP1CLKSOURCE_LSI    HSI selected as COMP1 clock
  *            @arg @ref RCC_COMP1CLKSOURCE_LSE    LSE selected as COMP1 clock
  */
#define __HAL_RCC_GET_COMP1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP1SEL))

/** @brief  Macro to configure the COMP1 clock (COMP1CLK).
  *
  * @param  __COMP2_CLKSOURCE__ specifies the COMP2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_COMP2CLKSOURCE_PCLK2  PCLK1 selected as COMP2 clock
  *            @arg @ref RCC_COMP2CLKSOURCE_LSI    HSI selected as COMP2 clock
  *            @arg @ref RCC_COMP2CLKSOURCE_LSE    LSE selected as COMP2 clock
  * @retval None
  */
#define __HAL_RCC_COMP2_CONFIG(__COMP2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP2SEL, (__COMP2_CLKSOURCE__))

/** @brief  Macro to get the COMP2 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_COMP2CLKSOURCE_PCLK2  PCLK1 selected as COMP2 clock
  *            @arg @ref RCC_COMP2CLKSOURCE_LSI    HSI selected as COMP2 clock
  *            @arg @ref RCC_COMP2CLKSOURCE_LSE    LSE selected as COMP2 clock
  */
#define __HAL_RCC_GET_COMP2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP2SEL))

/** @brief  Macro to configure the COMP3 clock (COMP3CLK).
  *
  * @param  __COMP3_CLKSOURCE__ specifies the COMP3 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_COMP3CLKSOURCE_PCLK2  PCLK1 selected as COMP3 clock
  *            @arg @ref RCC_COMP3CLKSOURCE_LSI    HSI selected as COMP3 clock
  *            @arg @ref RCC_COMP3CLKSOURCE_LSE    LSE selected as COMP3 clock
  * @retval None
  */
#define __HAL_RCC_COMP3_CONFIG(__COMP3_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP3SEL, (__COMP3_CLKSOURCE__))

/** @brief  Macro to get the COMP3 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_COMP3CLKSOURCE_PCLK2  PCLK1 selected as COMP3 clock
  *            @arg @ref RCC_COMP3CLKSOURCE_LSI    HSI selected as COMP3 clock
  *            @arg @ref RCC_COMP3CLKSOURCE_LSE    LSE selected as COMP3 clock
  */
#define __HAL_RCC_GET_COMP3_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP3SEL))

/** @brief  Macro to configure the COMP4 clock (COMP4CLK).
  *
  * @param  __COMP4_CLKSOURCE__ specifies the COMP4 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_COMP4CLKSOURCE_PCLK2  PCLK1 selected as COMP4 clock
  *            @arg @ref RCC_COMP4CLKSOURCE_LSI    HSI selected as COMP4 clock
  *            @arg @ref RCC_COMP4CLKSOURCE_LSE    LSE selected as COMP4 clock
  * @retval None
  */
#define __HAL_RCC_COMP4_CONFIG(__COMP4_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP4SEL, (__COMP4_CLKSOURCE__))

/** @brief  Macro to get the COMP4 clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_COMP4CLKSOURCE_PCLK2  PCLK1 selected as COMP4 clock
  *            @arg @ref RCC_COMP4CLKSOURCE_LSI    HSI selected as COMP4 clock
  *            @arg @ref RCC_COMP4CLKSOURCE_LSE    LSE selected as COMP4 clock
  */
#define __HAL_RCC_GET_COMP4_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP4SEL))

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

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

#endif /* __PY32E407_HAL_RCC_EX_H */


/************************ (C) COPYRIGHT Puya *****END OF FILE******************/


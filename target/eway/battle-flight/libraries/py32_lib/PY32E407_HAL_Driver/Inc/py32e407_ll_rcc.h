/**
  ******************************************************************************
  * @file    py32e407_ll_rcc.h
  * @author  MCU Application Team
  * @brief   Header file of RCC LL module.
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
#ifndef __PY32E407_LL_RCC_H
#define __PY32E407_LL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined(RCC)

/** @defgroup RCC_LL RCC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup RCC_LL_Private_Variables RCC Private Variables
  * @{
  */


/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_Private_Macros RCC Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_Exported_Types RCC Exported Types
  * @{
  */

/** @defgroup LL_ES_CLOCK_FREQ Clocks Frequency Structure
  * @{
  */

/**
  * @brief  RCC Clocks Frequency Structure
  */
typedef struct
{
  uint32_t SYSCLK_Frequency;        /*!< SYSCLK clock frequency */
  uint32_t HCLK_Frequency;          /*!< HCLK clock frequency */
  uint32_t PCLK1_Frequency;         /*!< PCLK1 clock frequency */
  uint32_t PCLK2_Frequency;         /*!< PCLK2 clock frequency */
} LL_RCC_ClocksTypeDef;

/**
  * @}
  */

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_LL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */
#if !defined  (HSE_VALUE)
#define HSE_VALUE    24000000U   /*!< Value of the HSE oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
#define HSI_VALUE    16000000U  /*!< Value of the HSI oscillator in Hz */
#endif /* HSI_VALUE */

#if defined(RCC_LSE_SUPPORT)
#if !defined  (LSE_VALUE)
#define LSE_VALUE    32768U     /*!< Value of the LSE oscillator in Hz */
#endif /* LSE_VALUE */
#endif

#if !defined  (LSI_VALUE)
#define LSI_VALUE    40000U     /*!< Value of the LSI oscillator in Hz */
#endif /* LSI_VALUE */

#if !defined  (HSI48_VALUE)
#define HSI48_VALUE  48000000U  /*!< Value of the HSI48 oscillator in Hz */
#endif /* HSI48_VALUE */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_RCC_WriteReg function
  * @{
  */
#define LL_RCC_CIR_LSIRDYC                RCC_CIR_LSIRDYC     /*!< LSI Ready Interrupt Clear */
#define LL_RCC_CIR_HSIRDYC                RCC_CIR_HSIRDYC     /*!< HSI Ready Interrupt Clear */
#define LL_RCC_CIR_HSERDYC                RCC_CIR_HSERDYC     /*!< HSE Ready Interrupt Clear */
#if defined(RCC_PLL_SUPPORT)
#define LL_RCC_CIR_PLLRDYC                RCC_CIR_PLLRDYC     /*!< PLL Ready Interrupt Clear */
#endif
#if defined(RCC_LSE_SUPPORT)
#define LL_RCC_CIR_LSERDYC                RCC_CIR_LSERDYC     /*!< LSE Ready Interrupt Clear */
#endif
#define LL_RCC_CIR_HSI48RDYC              RCC_CIR_HSI48RDYC   /*!< HSI48M Ready Interrupt Clear */
#define LL_RCC_CIR_CSSC                   RCC_CIR_CSSC        /*!< Clock Security System Interrupt Clear */

/**
  * @}
  */

/** @defgroup RCC_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_RCC_ReadReg function
  * @{
  */
#define LL_RCC_CIR_LSIRDYF                RCC_CIR_LSIRDYF     /*!< LSI Ready Interrupt flag */
#define LL_RCC_CIR_HSIRDYF                RCC_CIR_HSIRDYF     /*!< HSI Ready Interrupt flag */
#define LL_RCC_CIR_HSERDYF                RCC_CIR_HSERDYF     /*!< HSE Ready Interrupt flag */
#if defined(RCC_PLL_SUPPORT)
#define LL_RCC_CIR_PLLRDYF                RCC_CIR_PLLRDYF     /*!< PLL Ready Interrupt flag */
#endif
#if defined(RCC_LSE_SUPPORT)
#define LL_RCC_CIR_LSERDYF                RCC_CIR_LSERDYF     /*!< LSE Ready Interrupt flag */
#endif
#define LL_RCC_CIR_HSI48RDYF              RCC_CIR_HSI48RDYF   /*!< HSI48M Ready Interrupt flag */
#define LL_RCC_CIR_CSSF                   RCC_CIR_CSSF        /*!< Clock Security System Interrupt flag */

#define LL_RCC_CSR_OBLRSTF                RCC_CSR_OBLRSTF    /*!< OBL reset flag */
#define LL_RCC_CSR_PINRSTF                RCC_CSR_PINRSTF    /*!< PIN reset flag */
#define LL_RCC_CSR_SFTRSTF                RCC_CSR_SFTRSTF    /*!< Software Reset flag */
#define LL_RCC_CSR_IWDGRSTF               RCC_CSR_IWDGRSTF   /*!< Independent Watchdog reset flag */
#if defined(WWDG)
#define LL_RCC_CSR_WWDGRSTF               RCC_CSR_WWDGRSTF   /*!< Window watchdog reset flag */
#endif
#define LL_RCC_CSR_PWRRSTF                RCC_CSR_PWRRSTF    /*!< POR/PDR reset flag */
#define LL_RCC_CSR_LPWRRSTF               RCC_CSR_LPWRRSTF   /*!< Low Power reset flag */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_RCC_ReadReg and  LL_RCC_WriteReg functions
  * @{
  */
#define LL_RCC_CIR_LSIRDYIE               RCC_CIR_LSIRDYIE      /*!< LSI Ready Interrupt Enable */
#if defined(RCC_LSE_SUPPORT)
#define LL_RCC_CIR_LSERDYIE               RCC_CIR_LSERDYIE      /*!< LSE Ready Interrupt Enable */
#endif
#define LL_RCC_CIR_HSIRDYIE               RCC_CIR_HSIRDYIE      /*!< HSI Ready Interrupt Enable */
#define LL_RCC_CIR_HSERDYIE               RCC_CIR_HSERDYIE      /*!< HSE Ready Interrupt Enable */
#if defined(RCC_PLL_SUPPORT)
#define LL_RCC_CIR_PLLRDYIE               RCC_CIR_PLLRDYIE      /*!< PLL Ready Interrupt Enable */
#define LL_RCC_CIR_HSI48RDYIE             RCC_CIR_HSI48RDYIE    /*!< HSI48 Ready Interrupt Enable */
#endif
/**
  * @}
  */
  
#if defined(RCC_LSE_SUPPORT)
/** @defgroup RCC_LL_EC_LSEDRIVE  LSE oscillator drive capability
  * @{
  */
#define LL_RCC_LSEDRIVE_LOW                0x00000000                         /*!< Xtal mode low driving capability */
#define LL_RCC_LSEDRIVE_MEDIUM             RCC_BDCR_LSEDRV_0                  /*!< Xtal mode medium driving capability */
#define LL_RCC_LSEDRIVE_HIGH               RCC_BDCR_LSEDRV_1                  /*!< Xtal mode high driving capability */
#define LL_RCC_LSEDRIVE_VERY_HIGH          RCC_BDCR_LSEDRV                    /*!< Xtal mode very high driving capability */
/**
  * @}
  */

#endif

/** @defgroup RCC_LL_EC_SYS_CLKSOURCE  System clock switch
  * @{
  */
#define LL_RCC_SYS_CLKSOURCE_HSI           RCC_CFGR_SW_HSI                    /*!< HSI selection as system clock */
#define LL_RCC_SYS_CLKSOURCE_HSE           RCC_CFGR_SW_HSE                    /*!< HSE selection as system clock */
#if defined(RCC_PLL_SUPPORT)
#define LL_RCC_SYS_CLKSOURCE_PLL           RCC_CFGR_SW_PLL                    /*!< PLL selection as system clock */
#endif
/**
  * @}
  */

/** @defgroup RCC_LL_EC_SYS_CLKSOURCE_STATUS  System clock switch status
  * @{
  */
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSI    RCC_CFGR_SWS_HSI                    /*!< HSI used as system clock */
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSE    RCC_CFGR_SWS_HSE                    /*!< HSE used as system clock */
#if defined(RCC_PLL_SUPPORT)
#define LL_RCC_SYS_CLKSOURCE_STATUS_PLL    RCC_CFGR_SWS_PLL                    /*!< PLL used as system clock */
#endif
/**
  * @}
  */

/** @defgroup RCC_LL_EC_SYSCLK_DIV  AHB prescaler
  * @{
  */
#define LL_RCC_SYSCLK_DIV_1                0x00000000U                                                             /*!< SYSCLK not divided */
#define LL_RCC_SYSCLK_DIV_2                RCC_CFGR_HPRE_3                                                         /*!< SYSCLK divided by 2 */
#define LL_RCC_SYSCLK_DIV_4                (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_0)                                     /*!< SYSCLK divided by 4 */
#define LL_RCC_SYSCLK_DIV_8                (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_1)                                     /*!< SYSCLK divided by 8 */
#define LL_RCC_SYSCLK_DIV_16               (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_1 | RCC_CFGR_HPRE_0)                   /*!< SYSCLK divided by 16 */
#define LL_RCC_SYSCLK_DIV_64               (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2)                                     /*!< SYSCLK divided by 64 */
#define LL_RCC_SYSCLK_DIV_128              (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_0)                   /*!< SYSCLK divided by 128 */
#define LL_RCC_SYSCLK_DIV_256              (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_1)                   /*!< SYSCLK divided by 256 */
#define LL_RCC_SYSCLK_DIV_512              (RCC_CFGR_HPRE_3 | RCC_CFGR_HPRE_2 | RCC_CFGR_HPRE_1 | RCC_CFGR_HPRE_0) /*!< SYSCLK divided by 512 */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_APB1_DIV  APB1 low-speed prescaler (APB1)
  * @{
  */
#define LL_RCC_APB1_DIV_1                  0x00000000U                                              /*!< HCLK not divided */
#define LL_RCC_APB1_DIV_2                  RCC_CFGR_PPRE1_2                                         /*!< HCLK divided by 2 */
#define LL_RCC_APB1_DIV_4                  (RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_0)                    /*!< HCLK divided by 4 */
#define LL_RCC_APB1_DIV_8                  (RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_1)                    /*!< HCLK divided by 8 */
#define LL_RCC_APB1_DIV_16                 (RCC_CFGR_PPRE1_2 | RCC_CFGR_PPRE1_1 | RCC_CFGR_PPRE1_0) /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_APB2_DIV  APB2 low-speed prescaler (APB2)
  * @{
  */
#define LL_RCC_APB2_DIV_1                  0x00000000U                                              /*!< HCLK not divided */
#define LL_RCC_APB2_DIV_2                  RCC_CFGR_PPRE2_2                                         /*!< HCLK divided by 2 */
#define LL_RCC_APB2_DIV_4                  (RCC_CFGR_PPRE2_2 | RCC_CFGR_PPRE2_0)                    /*!< HCLK divided by 4 */
#define LL_RCC_APB2_DIV_8                  (RCC_CFGR_PPRE2_2 | RCC_CFGR_PPRE2_1)                    /*!< HCLK divided by 8 */
#define LL_RCC_APB2_DIV_16                 (RCC_CFGR_PPRE2_2 | RCC_CFGR_PPRE2_1 | RCC_CFGR_PPRE2_0) /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_MCOSOURCE  MCO SOURCE selection
  * @{
  */
#define LL_RCC_MCOSOURCE_NOCLOCK         0x00000000U                                                 /*!< MCO output disabled, no clock on MCO */
#if defined(RCC_LSE_SUPPORT)
#define LL_RCC_MCOSOURCE_LSE             RCC_CFGR_MCO_0                                              /*!< LSE selection as MCO source */
#endif /* RCC_LSE_SUPPORT */
#define LL_RCC_MCOSOURCE_LSI             RCC_CFGR_MCO_1                                              /*!< LSI selection as MCO source */
#define LL_RCC_MCOSOURCE_HSI48M          (RCC_CFGR_MCO_1 | RCC_CFGR_MCO_0)                           /*!< HSI48M selection as MCO source */
#define LL_RCC_MCOSOURCE_SYSCLK          RCC_CFGR_MCO_2                                              /*!< SYSCLK selection as MCO source */
#define LL_RCC_MCOSOURCE_HSI             (RCC_CFGR_MCO_2 | RCC_CFGR_MCO_0)                           /*!< HSI selection as MCO source */
#define LL_RCC_MCOSOURCE_HSE             (RCC_CFGR_MCO_2 | RCC_CFGR_MCO_1)                           /*!< HSE selection as MCO source */
#if defined(RCC_PLL_SUPPORT)
#define LL_RCC_MCOSOURCE_PLL             (RCC_CFGR_MCO_2 | RCC_CFGR_MCO_1 | RCC_CFGR_MCO_0)          /*!< PLLCLK selection as MCO source */
#endif /* RCC_PLL_SUPPORT */
#define LL_RCC_MCOSOURCE_HCLK            RCC_CFGR_MCO_3                                              /*!< HCLK selection as MCO source */
#define LL_RCC_MCOSOURCE_PCLK1           (RCC_CFGR_MCO_3 | RCC_CFGR_MCO_0)                           /*!< PCLK1 selection as MCO source */
#define LL_RCC_MCOSOURCE_PCLK2           (RCC_CFGR_MCO_3 | RCC_CFGR_MCO_1)                           /*!< PCLK2 selection as MCO source */
#define LL_RCC_MCOSOURCE_HSI10M          (RCC_CFGR_MCO_3 | RCC_CFGR_MCO_1 | RCC_CFGR_MCO_0)          /*!< HSI10M selection as MCO source */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_MCO Peripheral MCO get clock source
  * @{
  */
#define LL_RCC_MCO_CLKSOURCE             RCC_CFGR_MCO /*!< MCO Clock source selection */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_MCO_DIV  MCO prescaler
  * @{
  */
#define LL_RCC_MCO_DIV_1                  0x00000000U                                                    /*!< MCO not divided */
#define LL_RCC_MCO_DIV_2                  RCC_CFGR1_MCOPRE_0                                             /*!< MCO divided by 2 */
#define LL_RCC_MCO_DIV_4                  RCC_CFGR1_MCOPRE_1                                             /*!< MCO divided by 4 */
#define LL_RCC_MCO_DIV_8                  (RCC_CFGR1_MCOPRE_1 | RCC_CFGR1_MCOPRE_0)                      /*!< MCO divided by 8 */
#define LL_RCC_MCO_DIV_16                 RCC_CFGR1_MCOPRE_2                                             /*!< MCO divided by 16 */
#define LL_RCC_MCO_DIV_32                 (RCC_CFGR1_MCOPRE_2 | RCC_CFGR1_MCOPRE_0)                      /*!< MCO divided by 32 */
#define LL_RCC_MCO_DIV_64                 (RCC_CFGR1_MCOPRE_2 | RCC_CFGR1_MCOPRE_1)                      /*!< MCO divided by 64 */
#define LL_RCC_MCO_DIV_128                (RCC_CFGR1_MCOPRE_2 | RCC_CFGR1_MCOPRE_1 | RCC_CFGR1_MCOPRE_0) /*!< MCO divided by 128 */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_EC_PERIPH_FREQUENCY Peripheral clock frequency
  * @{
  */
#define LL_RCC_PERIPH_FREQUENCY_NO        0x00000000U                 /*!< No clock enabled for the peripheral            */
#define LL_RCC_PERIPH_FREQUENCY_NA        0xFFFFFFFFU                 /*!< Frequency cannot be provided as external clock */
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

#if defined(CANFD)
/** @defgroup RCC_LL_EC_CANFD_CLKSOURCE Peripheral CANFD clock source selection
  * @{
  */
#define LL_RCC_CANFD_CLKSOURCE_PLL       0x00000000U                                                           /*!< PLL clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV2  RCC_CFGR2_CANCKSEL_0                                                  /*!< PLL/2 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV3  RCC_CFGR2_CANCKSEL_1                                                  /*!< PLL/3 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV4  (RCC_CFGR2_CANCKSEL_1 | RCC_CFGR2_CANCKSEL_0)                         /*!< PLL/4 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV5  RCC_CFGR2_CANCKSEL_2                                                  /*!< PLL/5 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV6  (RCC_CFGR2_CANCKSEL_2 | RCC_CFGR2_CANCKSEL_0)                         /*!< PLL/6 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV7  (RCC_CFGR2_CANCKSEL_2 | RCC_CFGR2_CANCKSEL_1)                         /*!< PLL/7 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_PLL_DIV8  (RCC_CFGR2_CANCKSEL_2 | RCC_CFGR2_CANCKSEL_1 | RCC_CFGR2_CANCKSEL_0)  /*!< PLL/8 clock selected as CANFD clock */
#define LL_RCC_CANFD_CLKSOURCE_HSE       RCC_CFGR2_CANCKSEL_3                                                  /*!< HSE clock selected as CANFD clock */
/**
  * @}
  */
#endif /* CANFD */

#if defined(RCC_BDCR_RTCSEL)
/** @defgroup RCC_LL_EC_RTC_CLKSOURCE  RTC clock source selection
  * @{
  */
#define LL_RCC_RTC_CLKSOURCE_NONE          0x00000000U             /*!< No clock used as RTC clock */
#if defined(RCC_LSE_SUPPORT)
#define LL_RCC_RTC_CLKSOURCE_LSE           RCC_BDCR_RTCSEL_0       /*!< LSE oscillator clock used as RTC clock */
#endif
#define LL_RCC_RTC_CLKSOURCE_LSI           RCC_BDCR_RTCSEL_1       /*!< LSI oscillator clock used as RTC clock */
#define LL_RCC_RTC_CLKSOURCE_HSE_DIV128    RCC_BDCR_RTCSEL         /*!< HSE oscillator clock divided by 128 used as RTC clock */
/**
  * @}
  */
#endif

/** @defgroup RCC_LL_EC_PVD_Filter_CLKSOURCE  Peripheral PVD Filter clock source selection
  * @{
  */
#define LL_RCC_PVD_FILTERCLK_LSI            0x00000000
#define LL_RCC_PVD_FILTERCLK_LSE            RCC_CFGR1_PVDSEL_0
#define LL_RCC_PVD_FILTERCLK_PCLK           RCC_CFGR1_PVDSEL_1
/**
  * @}
  */

/** @defgroup RCC_LL_EC_USB_CLKSOURCE  Peripheral USB clock source selection
  * @{
  */
#define LL_RCC_USB_CLKSOURCE_PLL           0x00000000U            /*!< PLL clock used as USB clock source */
#define LL_RCC_USB_CLKSOURCE_HSI48         RCC_CFGR1_USBSELHSI48  /*!< HSI48 clock used as USB clock source */
/**
  * @}
  */
  
/** @defgroup RCC_LL_EC_USB_Prediv  Peripheral USB clock prescaler
  * @{
  */
#define LL_RCC_USB_DIV_1P5            0x00000000U                              /*!< USB divided by 1.5 */
#define LL_RCC_USB_DIV_1              RCC_CFGR_USBPRE_0                        /*!< USB divided by 1   */
#define LL_RCC_USB_DIV_2P5            RCC_CFGR_USBPRE_1                        /*!< USB divided by 2.5 */
#define LL_RCC_USB_DIV_2              (RCC_CFGR_USBPRE_1 | RCC_CFGR_USBPRE_0)  /*!< USB divided by 2 */
#define LL_RCC_USB_DIV_3              RCC_CFGR_USBPRE_2                        /*!< USB divided by 3 */
#define LL_RCC_USB_DIV_3P5            (RCC_CFGR_USBPRE_2 | RCC_CFGR_USBPRE_0)  /*!< USB divided by 3.5 */
#define LL_RCC_USB_DIV_4              (RCC_CFGR_USBPRE_2 | RCC_CFGR_USBPRE_1)  /*!< USB divided by 4 */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_ADC_CLKSOURCE  Peripheral ADC clock source selection
  * @{
  */
#define LL_RCC_ADC_CLKSOURCE_PCLK2_DIV2       RCC_CFGR_ADCPRE_DIV2                    /*!< PCLK/2 clock selected as ADC clock */
#define LL_RCC_ADC_CLKSOURCE_PCLK2_DIV4       RCC_CFGR_ADCPRE_DIV4                    /*!< PCLK/4 clock selected as ADC clock */
#define LL_RCC_ADC_CLKSOURCE_PCLK2_DIV6       RCC_CFGR_ADCPRE_DIV6                    /*!< PCLK/6 clock selected as ADC clock */
#define LL_RCC_ADC_CLKSOURCE_PCLK2_DIV8       RCC_CFGR_ADCPRE_DIV8                    /*!< PCLK/8 clock selected as ADC clock */
#define LL_RCC_ADC_CLKSOURCE_PCLK2_DIV12      RCC_CFGR_ADCPRE_DIV12                   /*!< PCLK/12 clock selected as ADC clock */
#define LL_RCC_ADC_CLKSOURCE_PCLK2_DIV16      RCC_CFGR_ADCPRE_DIV16                   /*!< PCLK/16 clock selected as ADC clock */
/**
  * @}
  */
/** @defgroup RCC_LL_EC_USART1_CLKSOURCE  Peripheral USART1 clock source selection
  * @{
  */
#define LL_RCC_USART1_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_USART1_CLKSOURCE_SYSCLK     RCC_CCIPR_USART1SEL_0
#define LL_RCC_USART1_CLKSOURCE_HSI        RCC_CCIPR_USART1SEL_1
#define LL_RCC_USART1_CLKSOURCE_LSE        (RCC_CCIPR_USART1SEL_0 | RCC_CCIPR_USART1SEL_1)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_USART2_CLKSOURCE  Peripheral USART2 clock source selection
  * @{
  */
#define LL_RCC_USART2_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_USART2_CLKSOURCE_SYSCLK     RCC_CCIPR_USART2SEL_0
#define LL_RCC_USART2_CLKSOURCE_HSI        RCC_CCIPR_USART2SEL_1
#define LL_RCC_USART2_CLKSOURCE_LSE        (RCC_CCIPR_USART2SEL_0 | RCC_CCIPR_USART2SEL_1)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_USART3_CLKSOURCE  Peripheral USART3 clock source selection
  * @{
  */
#define LL_RCC_USART3_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_USART3_CLKSOURCE_SYSCLK     RCC_CCIPR_USART3SEL_0
#define LL_RCC_USART3_CLKSOURCE_HSI        RCC_CCIPR_USART3SEL_1
#define LL_RCC_USART3_CLKSOURCE_LSE        (RCC_CCIPR_USART3SEL_0 | RCC_CCIPR_USART3SEL_1)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_LPUART1_CLKSOURCE  Peripheral LPUART1 clock source selection
  * @{
  */
#define LL_RCC_LPUART1_CLKSOURCE_PCLK      0x00000000U
#define LL_RCC_LPUART1_CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART1SEL_0
#define LL_RCC_LPUART1_CLKSOURCE_HSI       RCC_CCIPR_LPUART1SEL_1
#define LL_RCC_LPUART1_CLKSOURCE_LSE       (RCC_CCIPR_LPUART1SEL_0 | RCC_CCIPR_LPUART1SEL_1)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_LPTIM1_CLKSOURCE  Peripheral LPTIM1 clock source selection
  * @{
  */
#define LL_RCC_LPTIM1_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_LPTIM1_CLKSOURCE_LSI        RCC_CCIPR_LPTIM1SEL_0
#define LL_RCC_LPTIM1_CLKSOURCE_HSI        RCC_CCIPR_LPTIM1SEL_1
#define LL_RCC_LPTIM1_CLKSOURCE_LSE        RCC_CCIPR_LPTIM1SEL
/**
  * @}
  */

/** @defgroup RCC_LL_EC_COMP1_CLKSOURCE  Peripheral COMP1 clock source selection
  * @{
  */
#define LL_RCC_COMP1_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_COMP1_CLKSOURCE_LSI        RCC_CCIPR_COMP1SEL_0
#define LL_RCC_COMP1_CLKSOURCE_LSE        RCC_CCIPR_COMP1SEL_1
/**
  * @}
  */

/** @defgroup RCC_LL_EC_COMP2_CLKSOURCE  Peripheral COMP2 clock source selection
  * @{
  */
#define LL_RCC_COMP2_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_COMP2_CLKSOURCE_LSI        RCC_CCIPR_COMP2SEL_0
#define LL_RCC_COMP2_CLKSOURCE_LSE        RCC_CCIPR_COMP2SEL_1
/**
  * @}
  */

/** @defgroup RCC_LL_EC_COMP3_CLKSOURCE  Peripheral COMP3 clock source selection
  * @{
  */
#define LL_RCC_COMP3_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_COMP3_CLKSOURCE_LSI        RCC_CCIPR_COMP3SEL_0
#define LL_RCC_COMP3_CLKSOURCE_LSE        RCC_CCIPR_COMP3SEL_1
/**
  * @}
  */

/** @defgroup RCC_LL_EC_COMP4_CLKSOURCE  Peripheral COMP4 clock source selection
  * @{
  */
#define LL_RCC_COMP4_CLKSOURCE_PCLK       0x00000000U
#define LL_RCC_COMP4_CLKSOURCE_LSI        RCC_CCIPR_COMP4SEL_0
#define LL_RCC_COMP4_CLKSOURCE_LSE        RCC_CCIPR_COMP4SEL_1
/**
  * @}
  */

#if defined(RCC_PLL_SUPPORT)
/** @defgroup RCC_LL_EC_PLLSOURCE  PLL entry clock source
  * @{
  */
#define LL_RCC_PLLSOURCE_HSI_DIV2          0x00000000U                  /*!< HSI/2 clock selected as PLL entry clock source */
#define LL_RCC_PLLSOURCE_HSE               RCC_CFGR3_PLLSRC             /*!< HSE clock selected as PLL entry clock source */
/**
  * @}
  */
  
/** @defgroup RCC_LL_EC_HSE_PREDIV_DIV HSE PREDIV Division factor
  * @{
  */
#define LL_RCC_HSE_PREDIV_DIV_1                0x00000000U              /*!< HSE divider clock clock not divided */
#define LL_RCC_HSE_PREDIV_DIV_2                RCC_CFGR3_PLLXTPRE        /*!< HSE divider clock divided by 2 for PLL entry */
/**
  * @}
  */
  
/** @defgroup RCC_LL_EC_PREDIV_DIV PREDIV Division factor
  * @{
  */
#define LL_RCC_PREDIV_DIV_1                RCC_CFGR3_PLLPREDIV1         /*!< PLL postdivider clock not divided */
#define LL_RCC_PREDIV_DIV_2                RCC_CFGR3_PLLPREDIV2         /*!< PLL postdivider clock by 2 */
#define LL_RCC_PREDIV_DIV_4                RCC_CFGR3_PLLPREDIV4         /*!< PLL postdivider clock by 4 */
#define LL_RCC_PREDIV_DIV_8                RCC_CFGR3_PLLPREDIV8         /*!< PLL postdivider clock by 8 */
/**
  * @}
  */
  
/** @defgroup RCC_LL_EC_POSTDIV_DIV POSTDIV Division factor
  * @{
  */
#define LL_RCC_POSTDIV_DIV_1                RCC_CFGR3_PLLPOSTDIV1         /*!< PLL predivider clock not divided */
#define LL_RCC_POSTDIV_DIV_2                RCC_CFGR3_PLLPOSTDIV2         /*!< PLL predivider clock by 2 */
#define LL_RCC_POSTDIV_DIV_4                RCC_CFGR3_PLLPOSTDIV4         /*!< PLL predivider clock by 4 */
#define LL_RCC_POSTDIV_DIV_8                RCC_CFGR3_PLLPOSTDIV8         /*!< PLL predivider clock by 8 */
/**
  * @}
  */
#endif

/** @defgroup RCC_HSE_EC_Freq HSE Config
  * @{
  */
#define LL_RCC_HSE_4_8MHz                 0x00000000U
#define LL_RCC_HSE_8_16MHz                RCC_CFGR2_HSEDRV_0
#define LL_RCC_HSE_16_32MHz               RCC_CFGR2_HSEDRV_1
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RCC register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_RCC_WriteReg(__REG__, __VALUE__) WRITE_REG((RCC->__REG__), (__VALUE__))

/**
  * @brief  Read a value in RCC register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_RCC_ReadReg(__REG__) READ_REG(RCC->__REG__)
/**
  * @}
  */

/** @defgroup RCC_LL_EM_CALC_FREQ Calculate frequencies
  * @{
  */
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Helper macro to calculate the PLLCLK frequency on system domain
  * @param __INPUTFREQ__ PLL input frequency source, which can be:
  *                       - HSE clock predivided by 1 or 2
  *                       - HSI clock predivided by 2
  * @param  __PREDIV__: This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PREDIV_DIV_1
  *         @arg @ref LL_RCC_PREDIV_DIV_2
  *         @arg @ref LL_RCC_PREDIV_DIV_4
  *         @arg @ref LL_RCC_PREDIV_DIV_8
  * @param  __PLLMUL__: This parameter must be a number between Min_Data = 2 and Max_Data = 257
  * @param  __POSTDIV__: This parameter can be one of the following values:
  *         @arg @ref LL_RCC_POSTDIV_DIV_1
  *         @arg @ref LL_RCC_POSTDIV_DIV_2
  *         @arg @ref LL_RCC_POSTDIV_DIV_4
  *         @arg @ref LL_RCC_POSTDIV_DIV_8
  * @retval PLL clock frequency (in Hz)
  */
#define __LL_RCC_CALC_PLLCLK_FREQ(__INPUTFREQ__, __PREDIV__, __PLLMUL__, __POSTDIV__) \
                                 ((((__INPUTFREQ__) >> ((__PREDIV__) >> RCC_CFGR3_PLLPREDIV_Pos)) * (__PLLMUL__)) >> ((__POSTDIV__) >> RCC_CFGR3_PLLPOSTDIV_Pos))
#endif

/**
  * @brief  Helper macro to calculate the HCLK frequency
  * @param  __SYSCLKFREQ__ SYSCLK frequency
  * @param  __AHBPRESCALER__ This parameter can be one of the following values:
  *         @arg @ref LL_RCC_SYSCLK_DIV_1
  *         @arg @ref LL_RCC_SYSCLK_DIV_2
  *         @arg @ref LL_RCC_SYSCLK_DIV_4
  *         @arg @ref LL_RCC_SYSCLK_DIV_8
  *         @arg @ref LL_RCC_SYSCLK_DIV_16
  *         @arg @ref LL_RCC_SYSCLK_DIV_64
  *         @arg @ref LL_RCC_SYSCLK_DIV_128
  *         @arg @ref LL_RCC_SYSCLK_DIV_256
  *         @arg @ref LL_RCC_SYSCLK_DIV_512
  * @retval HCLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_HCLK_FREQ(__SYSCLKFREQ__,__AHBPRESCALER__)  \
  ((__SYSCLKFREQ__) >> (AHBPrescTable[((__AHBPRESCALER__) & RCC_CFGR_HPRE) >>  RCC_CFGR_HPRE_Pos] & 0x1FU))

/**
  * @brief  Helper macro to calculate the PCLK1 frequency (APB1)
  * @param  __HCLKFREQ__ HCLK frequency
  * @param  __APB1PRESCALER__ This parameter can be one of the following values:
  *         @arg @ref LL_RCC_APB1_DIV_1
  *         @arg @ref LL_RCC_APB1_DIV_2
  *         @arg @ref LL_RCC_APB1_DIV_4
  *         @arg @ref LL_RCC_APB1_DIV_8
  *         @arg @ref LL_RCC_APB1_DIV_16
  * @retval PCLK1 clock frequency (in Hz)
  */
#define __LL_RCC_CALC_PCLK1_FREQ(__HCLKFREQ__, __APB1PRESCALER__)  \
  ((__HCLKFREQ__) >> (APBPrescTable[(__APB1PRESCALER__) >>  RCC_CFGR_PPRE1_Pos] & 0x1FU))

/**
  * @brief  Helper macro to calculate the PCLK2 frequency (APB2)
  * @param  __HCLKFREQ__ HCLK frequency
  * @param  __APB2PRESCALER__ This parameter can be one of the following values:
  *         @arg @ref LL_RCC_APB2_DIV_1
  *         @arg @ref LL_RCC_APB2_DIV_2
  *         @arg @ref LL_RCC_APB2_DIV_4
  *         @arg @ref LL_RCC_APB2_DIV_8
  *         @arg @ref LL_RCC_APB2_DIV_16
  * @retval PCLK2 clock frequency (in Hz)
  */
#define __LL_RCC_CALC_PCLK2_FREQ(__HCLKFREQ__, __APB2PRESCALER__)  \
  ((__HCLKFREQ__) >> (APBPrescTable[(__APB2PRESCALER__) >>  RCC_CFGR_PPRE2_Pos] & 0x1FU))

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_LL_EF_HSE HSE
  * @{
  */

/**
  * @brief  Enable the Clock Security System.
  * @rmtoll CR           CSSON         LL_RCC_HSE_EnableCSS
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSE_EnableCSS(void)
{
  SET_BIT(RCC->CR, RCC_CR_CSSON);
}

/**
  * @brief  Enable HSE external oscillator (HSE Bypass)
  * @rmtoll CR           HSEBYP        LL_RCC_HSE_EnableBypass
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSE_EnableBypass(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSEBYP);
}

/**
  * @brief  Disable HSE external oscillator (HSE Bypass)
  * @rmtoll CR           HSEBYP        LL_RCC_HSE_DisableBypass
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSE_DisableBypass(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);
}

/**
  * @brief  Enable HSE crystal oscillator (HSE ON)
  * @rmtoll CR           HSEON         LL_RCC_HSE_Enable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSE_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSEON);
}

/**
  * @brief  Disable HSE crystal oscillator (HSE ON)
  * @rmtoll CR           HSEON         LL_RCC_HSE_Disable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSE_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSEON);
}

/**
  * @brief  Check if HSE oscillator Ready
  * @rmtoll CR           HSERDY        LL_RCC_HSE_IsReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_HSE_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_HSERDY) == (RCC_CR_HSERDY)) ? 1UL : 0UL);
}

/**
  * @brief  Set HSE Crystal working frequency
  * @param  HSEFreq This parameter can be one of the following values:
  *         @arg @ref LL_RCC_HSE_4_8MHz  
  *         @arg @ref LL_RCC_HSE_8_16MHz 
  *         @arg @ref LL_RCC_HSE_16_32MHz
  * @note   The maximum working frequency varies depending on the devices.
  *         Refer to the devices data sheet for the maximum working frequency.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSE_SetFreqRegion(uint32_t HSEFreq)
{
  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_HSEDRV, HSEFreq);
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_HSI HSI
  * @{
  */

/**
  * @brief  Enable HSI oscillator
  * @rmtoll CR           HSION         LL_RCC_HSI_Enable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSI_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSION);
}

/**
  * @brief  Disable HSI oscillator
  * @rmtoll CR           HSION         LL_RCC_HSI_Disable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSI_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSION);
}

/**
  * @brief  Check if HSI clock is ready
  * @rmtoll CR           HSIRDY        LL_RCC_HSI_IsReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_HSI_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_HSIRDY) == (RCC_CR_HSIRDY)) ? 1UL : 0UL);
}

/**
  * @brief  Get HSI Calibration value
  * @note When HSITRIM is written, HSICAL is updated with the sum of
  *       HSITRIM and the factory trim value
  * @rmtoll CR        HSICAL        LL_RCC_HSI_GetCalibration
  * @retval Between Min_Data = 0x000 and Max_Data = 0x7FF
  */
__STATIC_INLINE uint32_t LL_RCC_HSI_GetCalibration(void)
{
  uint32_t calibration_low = 0, calibration_high = 0;
  
  calibration_low  = (READ_BIT(RCC->CR, RCC_CR_HSICAL) >> RCC_CR_HSICAL_Pos) & 0x00FF;
  calibration_high = (READ_BIT(RCC->CR, RCC_CR_HSICAL) >> RCC_CR_HSICAL_Pos) & 0xE000;
  
  return (calibration_high >> 5U | calibration_low);
}

/**
  * @brief  Set HSI Calibration trimming
  * @param  Value Between Min_Data = 0 and Max_Data = 31
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSI_SetCalibTrimming(uint32_t Value)
{
  MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, Value << RCC_CR_HSITRIM_Pos);
}

/**
  * @brief  Get HSI Calibration trimming
  * @rmtoll CR        HSITRIM       LL_RCC_HSI_GetCalibTrimming
  * @retval Between Min_Data = 0 and Max_Data = 31
  */
__STATIC_INLINE uint32_t LL_RCC_HSI_GetCalibTrimming(void)
{
  return (uint32_t)(READ_BIT(RCC->CR, RCC_CR_HSITRIM) >> RCC_CR_HSITRIM_Pos);
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_HSI48 HSI48
  * @{
  */

/**
  * @brief  Enable HSI48
  * @rmtoll CFGR1          HSI48ON       LL_RCC_HSI48_Enable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSI48_Enable(void)
{
  SET_BIT(RCC->CFGR1, RCC_CFGR1_HSI48ON);
}

/**
  * @brief  Disable HSI48
  * @rmtoll CFGR1          HSI48ON       LL_RCC_HSI48_Disable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSI48_Disable(void)
{
  CLEAR_BIT(RCC->CFGR1, RCC_CFGR1_HSI48ON);
}

/**
  * @brief  Check if HSI48 oscillator Ready
  * @rmtoll CFGR1          HSI48RDY      LL_RCC_HSI48_IsReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_HSI48_IsReady(void)
{
  return ((READ_BIT(RCC->CFGR1, RCC_CFGR1_HSI48RDY) == (RCC_CFGR1_HSI48RDY)) ? 1UL : 0UL);
}

/**
  * @brief  Get HSI48 Calibration value
  * @rmtoll CFGR1          HSI48CAL      LL_RCC_HSI48_GetCalibration
  * @retval Between Min_Data = 0x00 and Max_Data = 0x1FFF
  */
__STATIC_INLINE uint32_t LL_RCC_HSI48_GetCalibration(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR1, RCC_CFGR1_HSI48CAL) >> RCC_CFGR1_HSI48CAL_Pos);
}

/**
  * @brief  Set HSI48 Calibration trimming
  * @param  Value Between Min_Data = 0 and Max_Data = 127
  * @retval None
  */
__STATIC_INLINE void LL_RCC_HSI48_SetCalibTrimming(uint32_t Value)
{
  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_HSI48TRIM, Value << RCC_CFGR1_HSI48TRIM_Pos);
}

/**
  * @brief  Get HSI48 Calibration trimming
  * @rmtoll CFGR1        HSI48TRIM       LL_RCC_HSI48_GetCalibTrimming
  * @retval Between Min_Data = 0 and Max_Data = 127
  */
__STATIC_INLINE uint32_t LL_RCC_HSI48_GetCalibTrimming(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR1, RCC_CFGR1_HSI48TRIM) >> RCC_CFGR1_HSI48TRIM_Pos);
}

/**
  * @}
  */

#if defined(RCC_LSE_SUPPORT)
/** @defgroup RCC_LL_EF_LSE LSE
  * @{
  */

/**
  * @brief  Enable  Low Speed External (LSE) crystal.
  * @rmtoll BDCR         LSEON         LL_RCC_LSE_Enable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSE_Enable(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);
}

/**
  * @brief  Disable  Low Speed External (LSE) crystal.
  * @rmtoll BDCR         LSEON         LL_RCC_LSE_Disable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSE_Disable(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);
}

/**
  * @brief  Enable external clock source (LSE bypass).
  * @rmtoll BDCR         LSEBYP        LL_RCC_LSE_EnableBypass
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSE_EnableBypass(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
}

/**
  * @brief  Disable external clock source (LSE bypass).
  * @rmtoll BDCR         LSEBYP        LL_RCC_LSE_DisableBypass
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSE_DisableBypass(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
}

/**
  * @brief  Set LSE oscillator drive capability
  * @note The oscillator is in Xtal mode when it is not in bypass mode.
  * @param  LSEDrive This parameter can be one of the following values:
  *         @arg @ref LL_RCC_LSEDRIVE_LOW
  *         @arg @ref LL_RCC_LSEDRIVE_MEDIUM
  *         @arg @ref LL_RCC_LSEDRIVE_HIGH
  *         @arg @ref LL_RCC_LSEDRIVE_VERY_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSE_SetDriveCapability(uint32_t LSEDrive)
{
  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, LSEDrive);
}

/**
  * @brief  Get LSE oscillator drive capability
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_LSEDRIVE_LOW
  *         @arg @ref LL_RCC_LSEDRIVE_MEDIUM
  *         @arg @ref LL_RCC_LSEDRIVE_HIGH
  *         @arg @ref LL_RCC_LSEDRIVE_VERY_HIGH
  */
__STATIC_INLINE uint32_t LL_RCC_LSE_GetDriveCapability(void)
{
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_LSEDRV));
}

/**
  * @brief  Check if LSE oscillator Ready
  * @rmtoll BDCR         LSERDY        LL_RCC_LSE_IsReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_LSE_IsReady(void)
{
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == (RCC_BDCR_LSERDY)) ? 1UL : 0UL);
}

/**
  * @}
  */
#endif

/** @defgroup RCC_LL_EF_LSI LSI
  * @{
  */

/**
  * @brief  Enable LSI Oscillator
  * @rmtoll CSR          LSION         LL_RCC_LSI_Enable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSI_Enable(void)
{
  SET_BIT(RCC->CSR, RCC_CSR_LSION);
}

/**
  * @brief  Disable LSI Oscillator
  * @rmtoll CSR          LSION         LL_RCC_LSI_Disable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_LSI_Disable(void)
{
  CLEAR_BIT(RCC->CSR, RCC_CSR_LSION);
}

/**
  * @brief  Check if LSI is Ready
  * @rmtoll CSR          LSIRDY        LL_RCC_LSI_IsReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_LSI_IsReady(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_LSIRDY) == (RCC_CSR_LSIRDY)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_System System
  * @{
  */

/**
  * @brief  Configure the system clock source
  * @rmtoll CFGR         SW            LL_RCC_SetSysClkSource
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_SYS_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_SYS_CLKSOURCE_HSE
  *         @arg @ref LL_RCC_SYS_CLKSOURCE_PLL
  * @note   Depending on devices and packages, some clocks may not be available.
  *         Refer to device datasheet for clocks availability.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetSysClkSource(uint32_t Source)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, Source);
}

/**
  * @brief  Get the system clock source
  * @rmtoll CFGR         SWS           LL_RCC_GetSysClkSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_HSI
  *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_HSE
  *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_PLL
  * @note   Depending on devices and packages, some clocks may not be available.
  *         Refer to device datasheet for clocks availability.
  */
__STATIC_INLINE uint32_t LL_RCC_GetSysClkSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SWS));
}

/**
  * @brief  Set AHB prescaler
  * @rmtoll CFGR         HPRE          LL_RCC_SetAHBPrescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref LL_RCC_SYSCLK_DIV_1
  *         @arg @ref LL_RCC_SYSCLK_DIV_2
  *         @arg @ref LL_RCC_SYSCLK_DIV_4
  *         @arg @ref LL_RCC_SYSCLK_DIV_8
  *         @arg @ref LL_RCC_SYSCLK_DIV_16
  *         @arg @ref LL_RCC_SYSCLK_DIV_64
  *         @arg @ref LL_RCC_SYSCLK_DIV_128
  *         @arg @ref LL_RCC_SYSCLK_DIV_256
  *         @arg @ref LL_RCC_SYSCLK_DIV_512
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetAHBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, Prescaler);
}

/**
  * @brief  Set APB1 prescaler
  * @rmtoll CFGR         PPRE1         LL_RCC_SetAPB1Prescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref LL_RCC_APB1_DIV_1
  *         @arg @ref LL_RCC_APB1_DIV_2
  *         @arg @ref LL_RCC_APB1_DIV_4
  *         @arg @ref LL_RCC_APB1_DIV_8
  *         @arg @ref LL_RCC_APB1_DIV_16
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetAPB1Prescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, Prescaler);
}

/**
  * @brief  Set APB2 prescaler
  * @rmtoll CFGR         PPRE2         LL_RCC_SetAPB2Prescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref LL_RCC_APB2_DIV_1
  *         @arg @ref LL_RCC_APB2_DIV_2
  *         @arg @ref LL_RCC_APB2_DIV_4
  *         @arg @ref LL_RCC_APB2_DIV_8
  *         @arg @ref LL_RCC_APB2_DIV_16
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetAPB2Prescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, Prescaler);
}

/**
  * @brief  Get AHB prescaler
  * @rmtoll CFGR         HPRE          LL_RCC_GetAHBPrescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_SYSCLK_DIV_1
  *         @arg @ref LL_RCC_SYSCLK_DIV_2
  *         @arg @ref LL_RCC_SYSCLK_DIV_4
  *         @arg @ref LL_RCC_SYSCLK_DIV_8
  *         @arg @ref LL_RCC_SYSCLK_DIV_16
  *         @arg @ref LL_RCC_SYSCLK_DIV_64
  *         @arg @ref LL_RCC_SYSCLK_DIV_128
  *         @arg @ref LL_RCC_SYSCLK_DIV_256
  *         @arg @ref LL_RCC_SYSCLK_DIV_512
  */
__STATIC_INLINE uint32_t LL_RCC_GetAHBPrescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_HPRE));
}

/**
  * @brief  Get APB1 prescaler
  * @rmtoll CFGR         PPRE1         LL_RCC_GetAPB1Prescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_APB1_DIV_1
  *         @arg @ref LL_RCC_APB1_DIV_2
  *         @arg @ref LL_RCC_APB1_DIV_4
  *         @arg @ref LL_RCC_APB1_DIV_8
  *         @arg @ref LL_RCC_APB1_DIV_16
  */
__STATIC_INLINE uint32_t LL_RCC_GetAPB1Prescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PPRE1));
}

/**
  * @brief  Get APB2 prescaler
  * @rmtoll CFGR         PPRE2         LL_RCC_GetAPB2Prescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_APB2_DIV_1
  *         @arg @ref LL_RCC_APB2_DIV_2
  *         @arg @ref LL_RCC_APB2_DIV_4
  *         @arg @ref LL_RCC_APB2_DIV_8
  *         @arg @ref LL_RCC_APB2_DIV_16
  */
__STATIC_INLINE uint32_t LL_RCC_GetAPB2Prescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PPRE2));
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_MCO MCO
  * @{
  */

/**
  * @brief  Configure MCOx
  * @rmtoll CFGR         MCOSEL        LL_RCC_ConfigMCO\n
  *         CFGR1        MCOPRE        LL_RCC_ConfigMCO
  * @param  MCOxSource This parameter can be one of the following values:
  *         @arg @ref LL_RCC_MCOSOURCE_NOCLOCK
  *         @arg @ref LL_RCC_MCOSOURCE_LSE
  *         @arg @ref LL_RCC_MCOSOURCE_LSI
  *         @arg @ref LL_RCC_MCOSOURCE_HSI48M
  *         @arg @ref LL_RCC_MCOSOURCE_SYSCLK
  *         @arg @ref LL_RCC_MCOSOURCE_HSI
  *         @arg @ref LL_RCC_MCOSOURCE_HSE
  *         @arg @ref LL_RCC_MCOSOURCE_PLL
  *         @arg @ref LL_RCC_MCOSOURCE_HCLK
  *         @arg @ref LL_RCC_MCOSOURCE_PCLK1
  *         @arg @ref LL_RCC_MCOSOURCE_PCLK2
  *         @arg @ref LL_RCC_MCOSOURCE_HSI10M
  * @note   Depending on devices and packages, some clocks may not be available.
  *         Refer to device datasheet for clocks availability.
  * @param  MCOxPrescaler This parameter can be one of the following values:
  *         @arg @ref LL_RCC_MCO_DIV_1
  *         @arg @ref LL_RCC_MCO_DIV_2
  *         @arg @ref LL_RCC_MCO_DIV_4
  *         @arg @ref LL_RCC_MCO_DIV_8
  *         @arg @ref LL_RCC_MCO_DIV_16
  *         @arg @ref LL_RCC_MCO_DIV_32
  *         @arg @ref LL_RCC_MCO_DIV_64
  *         @arg @ref LL_RCC_MCO_DIV_128
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ConfigMCO(uint32_t MCOxSource, uint32_t MCOxPrescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, MCOxSource);
  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_MCOPRE,  MCOxPrescaler);
}

/**
  * @brief  Get MCO clock source
  * @rmtoll CFGR         MCOSEL       LL_RCC_GetMCOClockSource
  * @param  MCOx This parameter can be one of the following values:
  *         @arg @ref LL_RCC_MCO_CLKSOURCE
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_MCOSOURCE_NOCLOCK
  *         @arg @ref LL_RCC_MCOSOURCE_LSE
  *         @arg @ref LL_RCC_MCOSOURCE_LSI
  *         @arg @ref LL_RCC_MCOSOURCE_HSI48M
  *         @arg @ref LL_RCC_MCOSOURCE_SYSCLK
  *         @arg @ref LL_RCC_MCOSOURCE_HSI
  *         @arg @ref LL_RCC_MCOSOURCE_HSE
  *         @arg @ref LL_RCC_MCOSOURCE_PLL
  *         @arg @ref LL_RCC_MCOSOURCE_HCLK
  *         @arg @ref LL_RCC_MCOSOURCE_PCLK1
  *         @arg @ref LL_RCC_MCOSOURCE_PCLK2
  *         @arg @ref LL_RCC_MCOSOURCE_HSI10M
  * @note   Depending on devices and packages, some clocks may not be available.
  *         Refer to device datasheet for clocks availability.
  */
__STATIC_INLINE uint32_t LL_RCC_GetMCOClockSource(uint32_t MCOx)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, MCOx));
}

/**
  * @brief  Get MCO division factor
  * @rmtoll CFGR         MCOPRE        LL_RCC_GetMCODiv
  * @param  MCOx This parameter can be one of the following values:
  *         @arg @ref LL_RCC_MCO_CLKSOURCE
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_MCO_DIV_1
  *         @arg @ref LL_RCC_MCO_DIV_2
  *         @arg @ref LL_RCC_MCO_DIV_4
  *         @arg @ref LL_RCC_MCO_DIV_8
  *         @arg @ref LL_RCC_MCO_DIV_16
  *         @arg @ref LL_RCC_MCO_DIV_32
  *         @arg @ref LL_RCC_MCO_DIV_64
  *         @arg @ref LL_RCC_MCO_DIV_128
  */
__STATIC_INLINE uint32_t LL_RCC_GetMCODiv(uint32_t MCOx)
{
  return (uint32_t)(READ_BIT(RCC->CFGR1, RCC_CFGR1_MCOPRE));
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_Peripheral_Clock_Source Peripheral Clock Source
  * @{
  */

#if defined(CANFD)
/**
  * @brief  Configure CANFD clock source
  * @param  CANFDSource This parameter can be one of the following values:
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV2
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV3
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV4
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV5
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV6
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV7
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV8
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_HSE
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetCANFDClockSource(uint32_t CANFDSource)
{
  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_CANCKSEL, CANFDSource);
}

/**
  * @brief  Get CANFD clock source
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV2
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV3
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV4
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV5
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV6
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV7
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_PLL_DIV8
  *         @arg @ref LL_RCC_CANFD_CLKSOURCE_HSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetCANFDClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_CANCKSEL));
}
#endif /* CANFD */

/**
  * @brief  Set ADC Clock Source
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV2
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV4
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV6
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV8
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV12
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV16
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetADCClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, Source);
}

/**
  * @brief  Get ADC Clock Source
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV2
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV4
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV6
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV8
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV12
  *         @arg @ref LL_RCC_ADC_CLKSOURCE_PCLK2_DIV16
  */
__STATIC_INLINE uint32_t LL_RCC_GetADCClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE));
}

/**
  * @brief  Set PVD Filter Clock Source
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PVD_FILTERCLK_LSI  
  *         @arg @ref LL_RCC_PVD_FILTERCLK_LSE  
  *         @arg @ref LL_RCC_PVD_FILTERCLK_PCLK
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetPVDClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_PVDSEL, Source);
}

/**
  * @brief  Get PVD Filter Clock Source
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_PVD_FILTERCLK_LSI  
  *         @arg @ref LL_RCC_PVD_FILTERCLK_LSE  
  *         @arg @ref LL_RCC_PVD_FILTERCLK_PCLK
  */
__STATIC_INLINE uint32_t LL_RCC_GetPVDClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR1, RCC_CFGR1_PVDSEL));
}

/**
  * @brief  Configure USB clock source
  * @rmtoll CFGR1        USBSELHSI48      LL_RCC_SetUSBClockSource
  * @param  USBxSource This parameter can be one of the following values:
  *         @arg @ref LL_RCC_USB_CLKSOURCE_HSI48
  *         @arg @ref LL_RCC_USB_CLKSOURCE_PLL
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetUSBClockSource(uint32_t USBxSource)
{
  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_USBSELHSI48, USBxSource);
}

/**
  * @brief  Get USB clock source
  * @rmtoll CFGR1        USBSELHSI48        LL_RCC_GetUSBClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_USB_CLKSOURCE_HSI48
  *         @arg @ref LL_RCC_USB_CLKSOURCE_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetUSBClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR1, RCC_CFGR1_USBSELHSI48));
}

/**
  * @brief  Configure USB clock Prescaler
  * @rmtoll CFGR        USBPRE      LL_RCC_SetUSBPrescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref LL_RCC_USB_DIV_1P5
  *         @arg @ref LL_RCC_USB_DIV_1
  *         @arg @ref LL_RCC_USB_DIV_2P5
  *         @arg @ref LL_RCC_USB_DIV_2
  *         @arg @ref LL_RCC_USB_DIV_3
  *         @arg @ref LL_RCC_USB_DIV_3P5
  *         @arg @ref LL_RCC_USB_DIV_4
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetUSBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, Prescaler);
}

/**
  * @brief  Get USB clock Prescaler
  * @rmtoll CFGR        USBPRE      LL_RCC_SetUSBPrescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_USB_DIV_1P5
  *         @arg @ref LL_RCC_USB_DIV_1
  *         @arg @ref LL_RCC_USB_DIV_2P5
  *         @arg @ref LL_RCC_USB_DIV_2
  *         @arg @ref LL_RCC_USB_DIV_3
  *         @arg @ref LL_RCC_USB_DIV_3P5
  *         @arg @ref LL_RCC_USB_DIV_4
  * @retval None
  */
__STATIC_INLINE uint32_t LL_RCC_GetUSBPrescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE));
}

/**
  * @brief  Set USART1 clock source
  * @rmtoll CCIPR        USART1SEL      LL_RCC_SetUSART1ClockSource
  * @param  USART1Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetUSART1ClockSource(uint32_t USART1Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART1SEL, USART1Source);
}

/**
  * @brief  Get USART1 clock source
  * @rmtoll CCIPR        USART1SEL        LL_RCC_GetUSART1ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_USART1_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetUSART1ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_USART1SEL));
}

/**
  * @brief  Set USART2 clock source
  * @rmtoll CCIPR        USART2SEL      LL_RCC_SetUSART2ClockSource
  * @param  USART2Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetUSART2ClockSource(uint32_t USART2Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART2SEL, USART2Source);
}

/**
  * @brief  Get USART2 clock source
  * @rmtoll CCIPR        USART2SEL        LL_RCC_GetUSART2ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_USART2_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetUSART2ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_USART2SEL));
}

/**
  * @brief  Set USART3 clock source
  * @rmtoll CCIPR        USART3SEL      LL_RCC_SetUSART3ClockSource
  * @param  USART3Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetUSART3ClockSource(uint32_t USART3Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART3SEL, USART3Source);
}

/**
  * @brief  Get USART3 clock source
  * @rmtoll CCIPR        USART3SEL        LL_RCC_GetUSART3ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_USART3_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetUSART3ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_USART3SEL));
}

/**
  * @brief  Set LPUART1 clock source
  * @rmtoll CCIPR        LPUART1SEL      LL_RCC_SetLPUART1ClockSource
  * @param  LPUART1Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetLPUART1ClockSource(uint32_t LPUART1Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPUART1SEL, LPUART1Source);
}

/**
  * @brief  Get LPUART1 clock source
  * @rmtoll CCIPR        LPUART1SEL        LL_RCC_GetLPUART1ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_SYSCLK
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetLPUART1ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_LPUART1SEL));
}

/**
  * @brief  Set LPTIM1 clock source
  * @rmtoll CCIPR        LPTIM1SEL      LL_RCC_SetLPTIM1ClockSource
  * @param  LPTIM1Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetLPTIM1ClockSource(uint32_t LPTIM1Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL, LPTIM1Source);
}

/**
  * @brief  Get LPTIM1 clock source
  * @rmtoll CCIPR        LPTIM1SEL        LL_RCC_GetLPTIM1ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_HSI
  *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetLPTIM1ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL));
}

/**
  * @brief  Set COMP1 clock source
  * @rmtoll CCIPR        COMP1SEL      LL_RCC_SetCOMP1ClockSource
  * @param  COMP1Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_COMP1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP1_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP1_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetCOMP1ClockSource(uint32_t COMP1Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP1SEL, COMP1Source);
}

/**
  * @brief  Get COMP1 clock source
  * @rmtoll CCIPR        COMP1SEL        LL_RCC_GetCOMP1ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_COMP1_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP1_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP1_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetCOMP1ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP1SEL));
}

/**
  * @brief  Set COMP2 clock source
  * @rmtoll CCIPR        COMP2SEL      LL_RCC_SetCOMP2ClockSource
  * @param  COMP2Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_COMP2_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP2_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP2_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetCOMP2ClockSource(uint32_t COMP2Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP2SEL, COMP2Source);
}

/**
  * @brief  Get COMP2 clock source
  * @rmtoll CCIPR        COMP2SEL        LL_RCC_GetCOMP2ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_COMP2_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP2_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP2_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetCOMP2ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP2SEL));
}

/**
  * @brief  Set COMP3 clock source
  * @rmtoll CCIPR        COMP3SEL      LL_RCC_SetCOMP3ClockSource
  * @param  COMP3Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_COMP3_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP3_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP3_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetCOMP3ClockSource(uint32_t COMP3Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP3SEL, COMP3Source);
}

/**
  * @brief  Get COMP3 clock source
  * @rmtoll CCIPR        COMP3SEL        LL_RCC_GetCOMP3ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_COMP3_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP3_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP3_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetCOMP3ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP3SEL));
}

/**
  * @brief  Set COMP4 clock source
  * @rmtoll CCIPR        COMP4SEL      LL_RCC_SetCOMP4ClockSource
  * @param  COMP4Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_COMP4_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP4_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP4_CLKSOURCE_LSE
  *
  *         (*) value not defined in all devices.
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetCOMP4ClockSource(uint32_t COMP4Source)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_COMP4SEL, COMP4Source);
}

/**
  * @brief  Get COMP4 clock source
  * @rmtoll CCIPR        COMP4SEL        LL_RCC_GetCOMP4ClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_COMP4_CLKSOURCE_PCLK
  *         @arg @ref LL_RCC_COMP4_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_COMP4_CLKSOURCE_LSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetCOMP4ClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RCC_CCIPR_COMP4SEL));
}
/**
  * @}
  */
#if defined(RTC)
#if defined(RCC_BDCR_RTCSEL)
/** @defgroup RCC_LL_EF_RTC RTC
  * @{
  */

/**
  * @brief  Set RTC Clock Source
  * @note Once the RTC clock source has been selected, it cannot be changed anymore unless
  *       the Backup domain is reset, or unless a failure is detected on LSE (LSECSSD is
  *       set). The BDRST bit can be used to reset them.
  * @rmtoll BDCR         RTCSEL        LL_RCC_SetRTCClockSource
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_NONE
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSE
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_HSE_DIV128
  * @retval None
  */
__STATIC_INLINE void LL_RCC_SetRTCClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, Source);
}

/**
  * @brief  Get RTC Clock Source
  * @rmtoll BDCR         RTCSEL        LL_RCC_GetRTCClockSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_NONE
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSE
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSI
  *         @arg @ref LL_RCC_RTC_CLKSOURCE_HSE_DIV128
  */
__STATIC_INLINE uint32_t LL_RCC_GetRTCClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL));
}
#endif
/**
  * @brief  Enable RTC
  * @rmtoll BDCR         RTCEN         LL_RCC_EnableRTC
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableRTC(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
}

/**
  * @brief  Disable RTC
  * @rmtoll BDCR         RTCEN         LL_RCC_DisableRTC
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableRTC(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
}

/**
  * @brief  Check if RTC has been enabled or not
  * @rmtoll BDCR         RTCEN         LL_RCC_IsEnabledRTC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledRTC(void)
{
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_RTCEN) == (RCC_BDCR_RTCEN)) ? 1UL : 0UL);
}

/**
  * @brief  Force the Backup domain reset
  * @rmtoll BDCR         BDRST         LL_RCC_ForceBackupDomainReset
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ForceBackupDomainReset(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_BDRST);
}

/**
  * @brief  Release the Backup domain reset
  * @rmtoll BDCR         BDRST         LL_RCC_ReleaseBackupDomainReset
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ReleaseBackupDomainReset(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST);
}

/**
  * @}
  */
#endif

#if defined(RCC_PLL_SUPPORT)
/** @defgroup RCC_LL_EF_PLL PLL
  * @{
  */

/**
  * @brief  Enable PLL
  * @rmtoll CR           PLLON         LL_RCC_PLL_Enable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_PLLON);
}

/**
  * @brief  Disable PLL
  * @note Cannot be disabled if the PLL clock is used as the system clock
  * @rmtoll CR           PLLON         LL_RCC_PLL_Disable
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
}

/**
  * @brief  Check if PLL Ready
  * @rmtoll CR           PLLRDY        LL_RCC_PLL_IsReady
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_PLLRDY) == (RCC_CR_PLLRDY)) ? 1UL : 0UL);
}

/**
  * @brief  Configure PLL used for SYSCLK Domain
  * @rmtoll CFGR         PLLSRC        LL_RCC_PLL_ConfigDomain_SYS\n
  *         CFGR         PLLXTPRE      LL_RCC_PLL_ConfigDomain_SYS\n
  *         CFGR         PLLMULL       LL_RCC_PLL_ConfigDomain_SYS\n
  * @param  PLLSource This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PLLSOURCE_HSI_DIV2
  *         @arg @ref LL_RCC_PLLSOURCE_HSE
  * @param  PLLPrediv This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PREDIV_DIV_1
  *         @arg @ref LL_RCC_PREDIV_DIV_2
  *         @arg @ref LL_RCC_PREDIV_DIV_4
  *         @arg @ref LL_RCC_PREDIV_DIV_8
  * @param  PLLMul This parameter must be a number between Min_Data = 2 and Max_Data = 257
  * @param  PLLPostdiv This parameter can be one of the following values:
  *         @arg @ref LL_RCC_POSTDIV_DIV_1
  *         @arg @ref LL_RCC_POSTDIV_DIV_2
  *         @arg @ref LL_RCC_POSTDIV_DIV_4
  *         @arg @ref LL_RCC_POSTDIV_DIV_8
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_ConfigDomain_SYS(uint32_t PLLSource, uint32_t PLLPrediv, uint32_t PLLMul, uint32_t PLLPostdiv)
{
  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE | RCC_CFGR3_PLLPREDIV | RCC_CFGR3_PLLPOSTDIV |
                         RCC_CFGR3_PLLFBDIV, PLLSource | PLLPrediv | ((PLLMul -2U) << RCC_CFGR3_PLLFBDIV_Pos) | PLLPostdiv);
}

/**
  * @brief  Configure PLL clock source
  * @rmtoll CFGR      PLLSRC        LL_RCC_PLL_SetMainSource
  * @param PLLSource This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PLLSOURCE_HSI_DIV2
  *         @arg @ref LL_RCC_PLLSOURCE_HSE
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_SetMainSource(uint32_t PLLSource)
{
  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLSRC , PLLSource);
}

/**
  * @brief  Get the oscillator used as PLL clock source.
  * @rmtoll CFGR      PLLSRC        LL_RCC_PLL_GetMainSource
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_PLLSOURCE_HSI_DIV2
  *         @arg @ref LL_RCC_PLLSOURCE_HSE
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_GetMainSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLSRC));
}

/**
  * @brief  Configure PLL Multiplication Factor.
  * @param This parameter must be a number between Min_Data = 2 and Max_Data = 257
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_SetMulFactor(uint32_t PLLMul)
{
  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLFBDIV, ((PLLMul - 2U) << RCC_CFGR3_PLLFBDIV_Pos));
}

/**
  * @brief  Get the PLL Multiplication Factor.
  * @retval Returned value is a number between Min_Data = 2 and Max_Data = 257
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_GetMulFactor(void)
{
  return (uint32_t)((READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U);
}

/**
  * @brief  Set HSE PREDIV division factor for the main PLL
  * @note They can be written only when the PLL is disabled
  * @rmtoll CFGR3        PLLXTPRE      LL_RCC_PLL_SetHSEPrediv
  * @param HSEPrediv This parameter can be one of the following values:
  *         @arg @ref LL_RCC_HSE_PREDIV_DIV_1
  *         @arg @ref LL_RCC_HSE_PREDIV_DIV_2
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_SetHSEPrediv(uint32_t HSEPrediv)
{
  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLXTPRE, HSEPrediv);
}

/**
  * @brief  Get HSE PREDIV division factor for the main PLL
  * @note They can be written only when the PLL is disabled
  * @rmtoll CFGR3        PLLXTPRE      LL_RCC_PLL_GetHSEPrediv
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_HSE_PREDIV_DIV_1
  *         @arg @ref LL_RCC_HSE_PREDIV_DIV_2
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_GetHSEPrediv(void)
{
  return (uint32_t)READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLXTPRE);
}

/**
  * @brief  Set PREDIV division factor for the main PLL
  * @note They can be written only when the PLL is disabled
  * @rmtoll CFGR3        PLLPREDIV      LL_RCC_PLL_SetPrediv
  * @param Prediv This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PREDIV_DIV_1
  *         @arg @ref LL_RCC_PREDIV_DIV_2
  *         @arg @ref LL_RCC_PREDIV_DIV_4
  *         @arg @ref LL_RCC_PREDIV_DIV_8
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_SetPrediv(uint32_t Prediv)
{
  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLPREDIV, Prediv);
}

/**
  * @brief  Get PREDIV division factor for the main PLL
  * @note They can be written only when the PLL is disabled
  * @rmtoll CFGR3        PLLPREDIV      LL_RCC_PLL_GetPrediv
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_PREDIV_DIV_1
  *         @arg @ref LL_RCC_PREDIV_DIV_2
  *         @arg @ref LL_RCC_PREDIV_DIV_4
  *         @arg @ref LL_RCC_PREDIV_DIV_8
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_GetPrediv(void)
{
  return (uint32_t)READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLPREDIV);
}

/**
  * @brief  Set POSTDIV division factor for the main PLL
  * @note They can be written only when the PLL is disabled
  * @rmtoll CFGR3        PLLPOSTDIV      LL_RCC_PLL_SetPostdiv
  * @param Postdiv This parameter can be one of the following values:
  *         @arg @ref LL_RCC_POSTDIV_DIV_1
  *         @arg @ref LL_RCC_POSTDIV_DIV_2
  *         @arg @ref LL_RCC_POSTDIV_DIV_4
  *         @arg @ref LL_RCC_POSTDIV_DIV_8
  * @retval None
  */
__STATIC_INLINE void LL_RCC_PLL_SetPostdiv(uint32_t Postdiv)
{
  MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLPOSTDIV, Postdiv);
}

/**
  * @brief  Get POSTDIV division factor for the main PLL
  * @note They can be written only when the PLL is disabled
  * @rmtoll CFGR3        PLLPOSTDIV      LL_RCC_PLL_GetPostdiv
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RCC_POSTDIV_DIV_1
  *         @arg @ref LL_RCC_POSTDIV_DIV_2
  *         @arg @ref LL_RCC_POSTDIV_DIV_4
  *         @arg @ref LL_RCC_POSTDIV_DIV_8
  */
__STATIC_INLINE uint32_t LL_RCC_PLL_GetPostdiv(void)
{
  return (uint32_t)READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLPOSTDIV);
}
/**
  * @}
  */
#endif


/** @defgroup RCC_LL_EF_FLAG_Management FLAG Management
  * @{
  */

/**
  * @brief  Clear LSI ready interrupt flag
  * @rmtoll CIR         LSIRDYC       LL_RCC_ClearFlag_LSIRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_LSIRDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_LSIRDYC);
}
#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  Clear LSE ready interrupt flag
  * @rmtoll CIR         LSERDYC       LL_RCC_ClearFlag_LSERDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_LSERDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_LSERDYC);
}
#endif
/**
  * @brief  Clear HSI ready interrupt flag
  * @rmtoll CIR         HSIRDYC       LL_RCC_ClearFlag_HSIRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_HSIRDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_HSIRDYC);
}

/**
  * @brief  Clear HSE ready interrupt flag
  * @rmtoll CIR         HSERDYC       LL_RCC_ClearFlag_HSERDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_HSERDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_HSERDYC);
}
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Clear PLL ready interrupt flag
  * @rmtoll CIR         PLLRDYC       LL_RCC_ClearFlag_PLLRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_PLLRDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_PLLRDYC);
}
#endif

/**
  * @brief  Clear PLL ready interrupt flag
  * @rmtoll CIR         HSI48RDYC       LL_RCC_ClearFlag_HSI48RDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_HSI48RDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_HSI48RDYC);
}

/**
  * @brief  Clear Clock security system interrupt flag
  * @rmtoll CIR         CSSC          LL_RCC_ClearFlag_HSECSS
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearFlag_HSECSS(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_CSSC);
}

/**
  * @brief  Check if LSI ready interrupt occurred or not
  * @rmtoll CIR         LSIRDYF       LL_RCC_IsActiveFlag_LSIRDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSIRDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_LSIRDYF) == (RCC_CIR_LSIRDYF)) ? 1UL : 0UL);
}
#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  Check if LSE ready interrupt occurred or not
  * @rmtoll CIR         LSERDYF       LL_RCC_IsActiveFlag_LSERDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSERDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_LSERDYF) == (RCC_CIR_LSERDYF)) ? 1UL : 0UL);
}
#endif
/**
  * @brief  Check if HSI ready interrupt occurred or not
  * @rmtoll CIR         HSIRDYF       LL_RCC_IsActiveFlag_HSIRDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSIRDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_HSIRDYF) == (RCC_CIR_HSIRDYF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if HSE ready interrupt occurred or not
  * @rmtoll CIR         HSERDYF       LL_RCC_IsActiveFlag_HSERDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSERDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_HSERDYF) == (RCC_CIR_HSERDYF)) ? 1UL : 0UL);
}
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Check if PLL ready interrupt occurred or not
  * @rmtoll CIR         PLLRDYF       LL_RCC_IsActiveFlag_PLLRDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLLRDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_PLLRDYF) == (RCC_CIR_PLLRDYF)) ? 1UL : 0UL);
}
#endif
/**
  * @brief  Check if Clock security system interrupt occurred or not
  * @rmtoll CIR         CSSF          LL_RCC_IsActiveFlag_HSECSS
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSECSS(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_CSSF) == (RCC_CIR_CSSF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if RCC flag Independent Watchdog reset is set or not.
  * @rmtoll CSR          IWDGRSTF      LL_RCC_IsActiveFlag_IWDGRST
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_IWDGRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_IWDGRSTF) == (RCC_CSR_IWDGRSTF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if RCC flag Option byte reset is set or not.
  * @rmtoll CSR          OBLRSTF       LL_RCC_IsActiveFlag_OBLRST
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_OBLRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_OBLRSTF) == (RCC_CSR_OBLRSTF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if RCC flag Pin reset is set or not.
  * @rmtoll CSR          PINRSTF       LL_RCC_IsActiveFlag_PINRST
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PINRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_PINRSTF) == (RCC_CSR_PINRSTF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if RCC flag Software reset is set or not.
  * @rmtoll CSR          SFTRSTF       LL_RCC_IsActiveFlag_SFTRST
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_SFTRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_SFTRSTF) == (RCC_CSR_SFTRSTF)) ? 1UL : 0UL);
}

#if defined(WWDG)
/**
  * @brief  Check if RCC flag Window Watchdog reset is set or not.
  * @rmtoll CSR          WWDGRSTF      LL_RCC_IsActiveFlag_WWDGRST
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_WWDGRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_WWDGRSTF) == (RCC_CSR_WWDGRSTF)) ? 1UL : 0UL);
}
#endif

/**
  * @brief  Check if RCC flag BOR or POR/PDR reset is set or not.
  * @rmtoll CSR          PWRRSTF       LL_RCC_IsActiveFlag_PWRRST
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PWRRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_PWRRSTF) == (RCC_CSR_PWRRSTF)) ? 1UL : 0UL);
}

/**
  * @brief  Set RMVF bit to clear the reset flags.
  * @rmtoll CSR          RMVF          LL_RCC_ClearResetFlags
  * @retval None
  */
__STATIC_INLINE void LL_RCC_ClearResetFlags(void)
{
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);
}

/**
  * @}
  */

/** @defgroup RCC_LL_EF_IT_Management IT Management
  * @{
  */

/**
  * @brief  Enable LSI ready interrupt
  * @rmtoll CIR         LSIRDYIE      LL_RCC_EnableIT_LSIRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableIT_LSIRDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_LSIRDYIE);
}
#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  Enable LSE ready interrupt
  * @rmtoll CIR         LSERDYIE      LL_RCC_EnableIT_LSERDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableIT_LSERDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_LSERDYIE);
}
#endif
/**
  * @brief  Enable HSI ready interrupt
  * @rmtoll CIR         HSIRDYIE      LL_RCC_EnableIT_HSIRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableIT_HSIRDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_HSIRDYIE);
}

/**
  * @brief  Enable HSE ready interrupt
  * @rmtoll CIR         HSERDYIE      LL_RCC_EnableIT_HSERDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableIT_HSERDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_HSERDYIE);
}
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Enable PLL ready interrupt
  * @rmtoll CIR         PLLRDYIE      LL_RCC_EnableIT_PLLRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableIT_PLLRDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_PLLRDYIE);
}
#endif

/**
  * @brief  Enable HSI48 ready interrupt
  * @rmtoll CIER          HSI48RDYIE    LL_RCC_EnableIT_HSI48RDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_EnableIT_HSI48RDY(void)
{
  SET_BIT(RCC->CIR, RCC_CIR_HSI48RDYIE);
}

/**
  * @brief  Disable LSI ready interrupt
  * @rmtoll CIR         LSIRDYIE      LL_RCC_DisableIT_LSIRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableIT_LSIRDY(void)
{
  CLEAR_BIT(RCC->CIR, RCC_CIR_LSIRDYIE);
}
#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  Disable LSE ready interrupt
  * @rmtoll CIR         LSERDYIE      LL_RCC_DisableIT_LSERDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableIT_LSERDY(void)
{
  CLEAR_BIT(RCC->CIR, RCC_CIR_LSERDYIE);
}
#endif
/**
  * @brief  Disable HSI ready interrupt
  * @rmtoll CIR         HSIRDYIE      LL_RCC_DisableIT_HSIRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableIT_HSIRDY(void)
{
  CLEAR_BIT(RCC->CIR, RCC_CIR_HSIRDYIE);
}

/**
  * @brief  Disable HSE ready interrupt
  * @rmtoll CIR         HSERDYIE      LL_RCC_DisableIT_HSERDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableIT_HSERDY(void)
{
  CLEAR_BIT(RCC->CIR, RCC_CIR_HSERDYIE);
}
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Disable PLL ready interrupt
  * @rmtoll CIR         PLLRDYIE      LL_RCC_DisableIT_PLLRDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableIT_PLLRDY(void)
{
  CLEAR_BIT(RCC->CIR, RCC_CIR_PLLRDYIE);
}
#endif

/**
  * @brief  Disable HSI48 ready interrupt
  * @rmtoll CIR          HSI48RDYIE    LL_RCC_DisableIT_HSI48RDY
  * @retval None
  */
__STATIC_INLINE void LL_RCC_DisableIT_HSI48RDY(void)
{
  CLEAR_BIT(RCC->CIR, RCC_CIR_HSI48RDYIE);
}

/**
  * @brief  Checks if LSI ready interrupt source is enabled or disabled.
  * @rmtoll CIR         LSIRDYIE      LL_RCC_IsEnabledIT_LSIRDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_LSIRDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_LSIRDYIE) == (RCC_CIR_LSIRDYIE)) ? 1UL : 0UL);
}
#if defined(RCC_LSE_SUPPORT)
/**
  * @brief  Checks if LSE ready interrupt source is enabled or disabled.
  * @rmtoll CIR         LSERDYIE      LL_RCC_IsEnabledIT_LSERDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_LSERDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_LSERDYIE) == (RCC_CIR_LSERDYIE)) ? 1UL : 0UL);
}
#endif
/**
  * @brief  Checks if HSI ready interrupt source is enabled or disabled.
  * @rmtoll CIR         HSIRDYIE      LL_RCC_IsEnabledIT_HSIRDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_HSIRDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_HSIRDYIE) == (RCC_CIR_HSIRDYIE)) ? 1UL : 0UL);
}

/**
  * @brief  Checks if HSE ready interrupt source is enabled or disabled.
  * @rmtoll CIR         HSERDYIE      LL_RCC_IsEnabledIT_HSERDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_HSERDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_HSERDYIE) == (RCC_CIR_HSERDYIE)) ? 1UL : 0UL);
}
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Checks if PLL ready interrupt source is enabled or disabled.
  * @rmtoll CIR         PLLRDYIE      LL_RCC_IsEnabledIT_PLLRDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_PLLRDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_PLLRDYIE) == (RCC_CIR_PLLRDYIE)) ? 1UL : 0UL);
}
#endif

/**
  * @brief  Checks if HSI48 ready interrupt source is enabled or disabled.
  * @rmtoll CIR         HSI48RDYIE      LL_RCC_IsEnabledIT_HSI48RDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_HSI48RDY(void)
{
  return ((READ_BIT(RCC->CIR, RCC_CIR_HSI48RDYIE) == (RCC_CIR_HSI48RDYIE)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_EF_Init De-initialization function
  * @{
  */
ErrorStatus LL_RCC_DeInit(void);
/**
  * @}
  */

/** @defgroup RCC_LL_EF_Get_Freq Get system and peripherals clocks frequency functions
  * @{
  */
void        LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef *RCC_Clocks);
uint32_t    LL_RCC_GetMCOClockFreq(uint32_t MCOx);
#if defined(RTC)
uint32_t    LL_RCC_GetRTCClockFreq(void);
#endif

uint32_t    LL_RCC_GetUSBClockFreq(void);

#if defined(CANFD)
uint32_t LL_RCC_GetCANFDClockFreq(void);
#endif /* CANFD */
uint32_t LL_RCC_GetADCClockFreq(void);
uint32_t LL_RCC_GetLPUART1ClockFreq(void);
uint32_t LL_RCC_GetUSART1ClockFreq(void);
uint32_t LL_RCC_GetUSART2ClockFreq(void);
uint32_t LL_RCC_GetUSART3ClockFreq(void);
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

#endif /* defined(RCC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PY32E407_LL_RCC_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

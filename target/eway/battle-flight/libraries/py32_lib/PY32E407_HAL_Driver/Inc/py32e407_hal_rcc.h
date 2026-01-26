/**
  ******************************************************************************
  * @file    py32e407_hal_rcc.h
  * @author  MCU Application Team
  * @brief   Header file of RCC HAL module.
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
#ifndef __PY32E407_HAL_RCC_H
#define __PY32E407_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"


/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup RCC_Exported_Types RCC Exported Types
  * @{
  */
  
/**
  * @brief  RCC PLL configuration structure definition
  */
typedef struct
{
  uint32_t PLLState;      /*!< PLLState: The new state of the PLL.
                              This parameter can be a value of @ref RCC_PLL_Config */

  uint32_t PLLSource;     /*!< PLLSource: PLL entry clock source.
                              This parameter must be a value of @ref RCC_PLL_Clock_Source */

  uint32_t PLLMUL;        /*!< PLLMUL: Multiplication factor for PLL VCO input clock
                              This parameter must be a number between Min_Data = 2 and Max_Data = 257 */

  uint32_t PLLPrediv;     /*!< The PLL Prediv factor value.
                               This parameter can be a value of @ref RCCEx_PLL_Prediv_Factor */

  uint32_t PLLPostdiv;    /*!< The PLL Postdiv factor value.
                               This parameter can be a value of @ref RCCEx_PLL_Postdiv_Factor */
} RCC_PLLInitTypeDef;

/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition
  */
typedef struct
{
  uint32_t OscillatorType;        /*!< The oscillators to be configured.
                                        This parameter can be a value of @ref RCC_Oscillator_Type */

  uint32_t HSEState;              /*!< The new state of the HSE.
                                       This parameter can be a value of @ref RCC_HSE_Config */

  uint32_t HSEFreq;               /*!< The frequency range of the HSE.
                                       This parameter can be a value of @ref RCC_HSE_Freq*/

  uint32_t LSEState;              /*!<  The new state of the LSE.
                                        This parameter can be a value of @ref RCC_LSE_Config */

  uint32_t LSEDriver;             /*!< The driver factor of the LSE.
                                       This parameter can be a value of @ref RCC_LSE_Driver*/

  uint32_t HSIState;              /*!< The new state of the HSI.
                                       This parameter can be a value of @ref RCC_HSI_Config */

  uint32_t HSI48MState;           /*!< The new state of the HSI48M.
                                       This parameter can be a value of @ref RCC_HSI48M_Config */

  uint32_t LSIState;              /*!<  The new state of the LSI.
                                        This parameter can be a value of @ref RCC_LSI_Config */

  RCC_PLLInitTypeDef PLL;         /*!< PLL structure parameters */

} RCC_OscInitTypeDef;

/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  */
typedef struct
{
  uint32_t ClockType;             /*!< The clock to be configured.
                                       This parameter can be a value of @ref RCC_System_Clock_Type */

  uint32_t SYSCLKSource;          /*!< The clock source (SYSCLKS) used as system clock.
                                       This parameter can be a value of @ref RCC_System_Clock_Source */

  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */
} RCC_ClkInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_PLL_Clock_Source PLL Clock Source
  * @{
  */

#define RCC_PLLSOURCE_HSI_DIV2      0x00000000U                              /*!< The half-frequency division of HSI clock selected as PLL entry clock source */
#define RCC_PLLSOURCE_HSE           RCC_CFGR3_PLLSRC                         /*!< HSE clock selected as PLL entry clock source */
#define RCC_PLLSOURCE_HSE_DIV2      (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)  /*!< The half-frequency division of HSE clock selected as PLL entry clock source */

/**
  * @}
  */

/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE            0x00000000U
#define RCC_OSCILLATORTYPE_HSE             0x00000001U
#define RCC_OSCILLATORTYPE_HSI             0x00000002U
#define RCC_OSCILLATORTYPE_LSE             0x00000004U
#define RCC_OSCILLATORTYPE_LSI             0x00000008U
#define RCC_OSCILLATORTYPE_HSI48M          0x00000010U
/**
  * @}
  */

/** @defgroup RCC_HSE_Config HSE Config
  * @{
  */
#define RCC_HSE_OFF                      0x00000000U                                /*!< HSE clock deactivation */
#define RCC_HSE_ON                       RCC_CR_HSEON                               /*!< HSE clock activation */
#define RCC_HSE_BYPASS                   ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON)) /*!< External clock source for HSE clock */
/**
  * @}
  */

/** @defgroup RCC_HSE_Freq HSE Config
  * @{
  */
#define RCC_HSE_4_8MHz                 0x00000000U                                 /*!< HSE low drive capability */
#define RCC_HSE_8_16MHz                RCC_CFGR2_HSEDRV_0                          /*!< HSE medium drive capability */
#define RCC_HSE_16_32MHz               RCC_CFGR2_HSEDRV_1                          /*!< HSE high drive capability */
/**
  * @}
  */


/** @defgroup RCC_LSE_Config LSE Config
  * @{
  */
#define RCC_LSE_OFF                      0x00000000U                                     /*!< LSE clock deactivation */
#define RCC_LSE_ON                       RCC_BDCR_LSEON                                  /*!< LSE clock activation */
#define RCC_LSE_BYPASS                   ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))  /*!< External clock source for LSE clock */
/**
  * @}
  */

/** @defgroup RCC_LSE_Driver LSE Config
  * @{
  */
#define RCC_LSEDRIVE_LOW                 0x00000000U                              /*!< LSE low drive capability */
#define RCC_LSEDRIVE_MEDIUM              RCC_BDCR_LSEDRV_0                        /*!< LSE medium drive capability */
#define RCC_LSEDRIVE_HIGH                RCC_BDCR_LSEDRV_1                        /*!< LSE high drive capability */
#define RCC_LSEDRIVE_VERY_HIGH           (RCC_BDCR_LSEDRV_1 | RCC_BDCR_LSEDRV_0)  /*!< LSE vrey high drive capability */
/**
  * @}
  */

/** @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF                      0x00000000U                      /*!< HSI clock deactivation */
#define RCC_HSI_ON                       RCC_CR_HSION                     /*!< HSI clock activation */

#define RCC_HSICALIBRATION_DEFAULT       0x10U                            /* Default HSI calibration trimming value */
/**
  * @}
  */

/** @defgroup RCC_HSI48M_Config HSI48M Config
  * @{
  */
#define RCC_HSI48M_OFF                   0x00000000U                      /*!< HSI48M clock deactivation */
#define RCC_HSI48M_ON                    RCC_CFGR1_HSI48ON                /*!< HSI48M clock activation */

#define RCC_HSI48MCALIBRATION_DEFAULT    0x40U                            /* Default HSI48 calibration trimming value */
/**
  * @}
  */

/** @defgroup RCC_LSI_Config LSI Config
  * @{
  */
#define RCC_LSI_OFF                      0x00000000U              /*!< LSI clock deactivation */
#define RCC_LSI_ON                       RCC_CSR_LSION            /*!< LSI clock activation */
/**
  * @}
  */

/** @defgroup RCC_PLL_Config PLL Config
  * @{
  */
#define RCC_PLL_NONE                      0x00000000U  /*!< PLL is not configured */
#define RCC_PLL_OFF                       0x00000001U  /*!< PLL deactivation */
#define RCC_PLL_ON                        0x00000002U  /*!< PLL activation */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK             0x00000001U /*!< SYSCLK to configure */
#define RCC_CLOCKTYPE_HCLK               0x00000002U /*!< HCLK to configure */
#define RCC_CLOCKTYPE_PCLK1              0x00000004U /*!< PCLK1 to configure */
#define RCC_CLOCKTYPE_PCLK2              0x00000008U /*!< PCLK2 to configure */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source System Clock Source
  * @{
  */
#define RCC_SYSCLKSOURCE_HSI             RCC_CFGR_SW_HSI /*!< HSI selected as system clock */
#define RCC_SYSCLKSOURCE_HSE             RCC_CFGR_SW_HSE /*!< HSE selected as system clock */
#define RCC_SYSCLKSOURCE_PLLCLK          RCC_CFGR_SW_PLL /*!< PLL selected as system clock */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source_Status System Clock Source Status
  * @{
  */
#define RCC_SYSCLKSOURCE_STATUS_HSI      RCC_CFGR_SWS_HSI            /*!< HSI used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_HSE      RCC_CFGR_SWS_HSE            /*!< HSE used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK   RCC_CFGR_SWS_PLL            /*!< PLL used as system clock */
/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1   /*!< SYSCLK not divided */
#define RCC_SYSCLK_DIV2                  RCC_CFGR_HPRE_DIV2   /*!< SYSCLK divided by 2 */
#define RCC_SYSCLK_DIV4                  RCC_CFGR_HPRE_DIV4   /*!< SYSCLK divided by 4 */
#define RCC_SYSCLK_DIV8                  RCC_CFGR_HPRE_DIV8   /*!< SYSCLK divided by 8 */
#define RCC_SYSCLK_DIV16                 RCC_CFGR_HPRE_DIV16  /*!< SYSCLK divided by 16 */
#define RCC_SYSCLK_DIV64                 RCC_CFGR_HPRE_DIV64  /*!< SYSCLK divided by 64 */
#define RCC_SYSCLK_DIV128                RCC_CFGR_HPRE_DIV128 /*!< SYSCLK divided by 128 */
#define RCC_SYSCLK_DIV256                RCC_CFGR_HPRE_DIV256 /*!< SYSCLK divided by 256 */
#define RCC_SYSCLK_DIV512                RCC_CFGR_HPRE_DIV512 /*!< SYSCLK divided by 512 */
/**
  * @}
  */

/** @defgroup RCC_APB1_APB2_Clock_Source APB1 APB2 Clock Source
  * @{
  */
#define RCC_HCLK_DIV1                    RCC_CFGR_PPRE1_DIV1  /*!< HCLK not divided */
#define RCC_HCLK_DIV2                    RCC_CFGR_PPRE1_DIV2  /*!< HCLK divided by 2 */
#define RCC_HCLK_DIV4                    RCC_CFGR_PPRE1_DIV4  /*!< HCLK divided by 4 */
#define RCC_HCLK_DIV8                    RCC_CFGR_PPRE1_DIV8  /*!< HCLK divided by 8 */
#define RCC_HCLK_DIV16                   RCC_CFGR_PPRE1_DIV16 /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Source RTC Clock Source
  * @{
  */
#define RCC_RTCCLKSOURCE_NO_CLK          0x00000000U                /*!< No clock */
#define RCC_RTCCLKSOURCE_LSE             RCC_BDCR_RTCSEL_LSE        /*!< LSE oscillator clock used as RTC clock */
#define RCC_RTCCLKSOURCE_LSI             RCC_BDCR_RTCSEL_LSI        /*!< LSI oscillator clock used as RTC clock */
#define RCC_RTCCLKSOURCE_HSE_DIV128      RCC_BDCR_RTCSEL_HSE_DIV128 /*!< HSE oscillator clock divided by 128 used as RTC clock */
/**
  * @}
  */

/** @defgroup RCC_MCOx_Clock_Prescaler MCO1 Clock Prescaler
  * @{
  */
#define RCC_MCODIV_1                   0x00000000U                                                     /*!< MCO not divided */
#define RCC_MCODIV_2                   RCC_CFGR1_MCOPRE_0                                              /*!< MCO divided by 2 */
#define RCC_MCODIV_4                   RCC_CFGR1_MCOPRE_1                                              /*!< MCO divided by 4 */
#define RCC_MCODIV_8                   (RCC_CFGR1_MCOPRE_1 | RCC_CFGR1_MCOPRE_0)                       /*!< MCO divided by 8 */
#define RCC_MCODIV_16                  RCC_CFGR1_MCOPRE_2                                              /*!< MCO divided by 16 */
#define RCC_MCODIV_32                  (RCC_CFGR1_MCOPRE_2 | RCC_CFGR1_MCOPRE_0)                       /*!< MCO divided by 32 */
#define RCC_MCODIV_64                  (RCC_CFGR1_MCOPRE_2 | RCC_CFGR1_MCOPRE_1)                       /*!< MCO divided by 64 */
#define RCC_MCODIV_128                 (RCC_CFGR1_MCOPRE_2 | RCC_CFGR1_MCOPRE_1 | RCC_CFGR1_MCOPRE_0)  /*!< MCO divided by 128 */
/**
  * @}
  */

/** @defgroup RCC_Interrupt Interrupts
  * @{
  */
#define RCC_IT_LSIRDY                    ((uint8_t)RCC_CIR_LSIRDYF)   /*!< LSI Ready Interrupt flag */
#define RCC_IT_LSERDY                    ((uint8_t)RCC_CIR_LSERDYF)   /*!< LSE Ready Interrupt flag */
#define RCC_IT_HSIRDY                    ((uint8_t)RCC_CIR_HSIRDYF)   /*!< HSI Ready Interrupt flag */
#define RCC_IT_HSERDY                    ((uint8_t)RCC_CIR_HSERDYF)   /*!< HSE Ready Interrupt flag */
#define RCC_IT_PLLRDY                    ((uint8_t)RCC_CIR_PLLRDYF)   /*!< PLL Ready Interrupt flag */
#define RCC_IT_HSI48MRDY                 ((uint8_t)RCC_CIR_HSI48RDYF) /*!< HSI48 Ready Interrupt flag */
#define RCC_IT_CSS                       ((uint8_t)RCC_CIR_CSSF)      /*!< Clock Security System Interrupt flag */
/**
  * @}
  */

/** @defgroup RCC_Flag Flags
  *        Elements values convention: XXXYYYYYb
  *           - YYYYY  : Flag position in the register
  *           - XXX  : Register index
  *                 - 001: CR register
  *                 - 010: BDCR register
  *                 - 011: CSR register
  *                 - 100: CFGR1 register
  * @{
  */
/* Flags in the CR register */
#define RCC_FLAG_HSIRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSIRDY_Pos)) /*!< Internal High Speed clock ready flag */
#define RCC_FLAG_HSERDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos)) /*!< External High Speed clock ready flag */
#define RCC_FLAG_PLLRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLLRDY_Pos)) /*!< PLL clock ready flag */

/* Flags in the CSR register */
#define RCC_FLAG_LSIRDY                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LSIRDY_Pos))   /*!< Internal Low Speed oscillator Ready */
#define RCC_FLAG_OBLRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_OBLRSTF_Pos))  /*!< Option byte loader reset flag */
#define RCC_FLAG_PINRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PINRSTF_Pos))  /*!< PIN reset flag reset flag*/
#define RCC_FLAG_PWRRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PWRRSTF_Pos))  /*!< POR/PDR reset flag */
#define RCC_FLAG_SFTRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_SFTRSTF_Pos))  /*!< Software Reset flag */
#define RCC_FLAG_IWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_IWDGRSTF_Pos)) /*!< Independent Watchdog reset flag */
#define RCC_FLAG_WWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_WWDGRSTF_Pos)) /*!< Window watchdog reset flag */
#define RCC_FLAG_LPWRRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LPWRRSTF_Pos)) /*!< Low-Power reset flag */

/* Flags in the BDCR register */
#define RCC_FLAG_LSERDY                  ((uint8_t)((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSERDY_Pos)) /*!< External Low Speed oscillator Ready */

/* Flags in the CFGR1 register */
#define RCC_FLAG_HSI48MRDY               ((uint8_t)((CFGR1_REG_INDEX << 5U) | RCC_CFGR1_HSI48RDY_Pos)) /*!< Internal High Speed clock ready flag */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup RCC_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_Peripheral_Clock_Enable_Disable Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_DMA1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SRAM_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_SRAMEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_SRAMEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_FMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FMCEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CORDIC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CORDICEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CORDICEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_CRC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ESMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ESMCEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_ESMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DMA1_CLK_DISABLE()      (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA1EN))
#define __HAL_RCC_DMA2_CLK_DISABLE()      (RCC->AHB1ENR &= ~(RCC_AHB1ENR_DMA2EN))
#define __HAL_RCC_SRAM_CLK_DISABLE()      (RCC->AHB1ENR &= ~(RCC_AHB1ENR_SRAMEN))
#define __HAL_RCC_FMC_CLK_DISABLE()       (RCC->AHB1ENR &= ~(RCC_AHB1ENR_FMCEN))
#define __HAL_RCC_CORDIC_CLK_DISABLE()    (RCC->AHB1ENR &= ~(RCC_AHB1ENR_CORDICEN))
#define __HAL_RCC_CRC_CLK_DISABLE()       (RCC->AHB1ENR &= ~(RCC_AHB1ENR_CRCEN))
#define __HAL_RCC_ESMC_CLK_DISABLE()      (RCC->AHB1ENR &= ~(RCC_AHB1ENR_ESMCEN))
/**
  * @}
  */

/** @defgroup RCC_AHB_Peripheral_Clock_Enable_Disable_Status AHB Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the AHB peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_DMA1_IS_CLK_ENABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA1EN)) != RESET)
#define __HAL_RCC_DMA1_IS_CLK_DISABLED()      ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA1EN)) == RESET)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA2EN)) != RESET)
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()      ((RCC->AHB1ENR & (RCC_AHB1ENR_DMA2EN)) == RESET)
#define __HAL_RCC_SRAM_IS_CLK_ENABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_SRAMEN)) != RESET)
#define __HAL_RCC_SRAM_IS_CLK_DISABLED()      ((RCC->AHB1ENR & (RCC_AHB1ENR_SRAMEN)) == RESET)
#define __HAL_RCC_FMC_IS_CLK_ENABLED()        ((RCC->AHB1ENR & (RCC_AHB1ENR_FMCEN)) != RESET)
#define __HAL_RCC_FMC_IS_CLK_DISABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_FMCEN)) == RESET)
#define __HAL_RCC_CORDIC_IS_CLK_ENABLED()     ((RCC->AHB1ENR & (RCC_AHB1ENR_CORDICEN)) != RESET)
#define __HAL_RCC_CORDIC_IS_CLK_DISABLED()    ((RCC->AHB1ENR & (RCC_AHB1ENR_CORDICEN)) == RESET)
#define __HAL_RCC_CRC_IS_CLK_ENABLED()        ((RCC->AHB1ENR & (RCC_AHB1ENR_CRCEN)) != RESET)
#define __HAL_RCC_CRC_IS_CLK_DISABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_CRCEN)) == RESET)
#define __HAL_RCC_ESMC_IS_CLK_ENABLED()       ((RCC->AHB1ENR & (RCC_AHB1ENR_ESMCEN)) != RESET)
#define __HAL_RCC_ESMC_IS_CLK_DISABLED()      ((RCC->AHB1ENR & (RCC_AHB1ENR_ESMCEN)) == RESET)
/**
  * @}
  */

/** @defgroup RCC_AHB2_Clock_Enable_Disable AHB2 Clock Enable Disable
  * @brief  Enable or disable the IO Ports clock.
  * @note   After reset, the IO ports clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_GPIOA_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPAEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPAEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_GPIOB_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPBEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPBEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_GPIOC_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_GPIOD_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPDEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPDEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_GPIOE_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPEEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPEEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_GPIOF_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPFEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPFEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)
#define __HAL_RCC_SDIO_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDIOEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDIOEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_AES_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_USB1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_USB2_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_ETH_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_ETHTX_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHTXEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHTXEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_ETHRX_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHRXEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHRXEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0U)

#define __HAL_RCC_GPIOA_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPAEN)
#define __HAL_RCC_GPIOB_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPBEN)
#define __HAL_RCC_GPIOC_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPCEN)
#define __HAL_RCC_GPIOD_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPDEN)
#define __HAL_RCC_GPIOE_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPEEN)
#define __HAL_RCC_GPIOF_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPFEN) 
#define __HAL_RCC_SDIO_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDIOEN)
#define __HAL_RCC_AES_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN)
#define __HAL_RCC_USB1_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB1EN)
#define __HAL_RCC_USB2_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB2EN)
#define __HAL_RCC_ETH_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHEN)
#define __HAL_RCC_ETHTX_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHTXEN)
#define __HAL_RCC_ETHRX_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHRXEN)
/**
  * @}
  */

/** @defgroup RCC_AHB2_Clock_Enable_Disable_Status AHB2 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the AHB2 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPAEN) != RESET)
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPBEN) != RESET)
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPCEN) != RESET)
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPDEN) != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPEEN) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPFEN) != RESET)
#define __HAL_RCC_SDIO_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDIOEN) != RESET)
#define __HAL_RCC_AES_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN) != RESET)
#define __HAL_RCC_USB1_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB1EN) != RESET)
#define __HAL_RCC_USB2_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB2EN) != RESET)
#define __HAL_RCC_ETH_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHEN) != RESET)
#define __HAL_RCC_ETHTX_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHTXEN) != RESET)
#define __HAL_RCC_ETHRX_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHRXEN) != RESET)

#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPAEN) == RESET)
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPBEN) == RESET)
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPCEN) == RESET)
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPDEN) == RESET)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPEEN) == RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_IOPFEN) == RESET)
#define __HAL_RCC_SDIO_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDIOEN) == RESET)
#define __HAL_RCC_AES_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN) == RESET)
#define __HAL_RCC_USB1_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB1EN) == RESET)
#define __HAL_RCC_USB2_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USB2EN) == RESET)
#define __HAL_RCC_ETH_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHEN) == RESET)
#define __HAL_RCC_ETHTX_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHTXEN) == RESET)
#define __HAL_RCC_ETHRX_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ETHRXEN) == RESET)
/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Enable_Disable APB1 Clock Enable Disable
  * @brief  Enable or disable the Low Speed APB (APB1) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_TIM2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM12EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM13EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM14EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM18_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM18EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM18EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_WWDG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_USART2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
                                      
#define __HAL_RCC_I2C1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART3EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U) 

#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)  
#define __HAL_RCC_CAN2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_BKP_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_BKPEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_BKPEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_PWR_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

                                      
                                      
#define __HAL_RCC_I2C3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_CTC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CTCEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CTCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
                                      

#define __HAL_RCC_TIM2_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM2EN))
#define __HAL_RCC_TIM3_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM3EN))
#define __HAL_RCC_TIM4_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM4EN))
#define __HAL_RCC_TIM5_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM5EN))
#define __HAL_RCC_TIM6_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM6EN))
#define __HAL_RCC_TIM7_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM7EN))
#define __HAL_RCC_TIM12_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM14EN))
#define __HAL_RCC_TIM18_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_TIM18EN))
#define __HAL_RCC_WWDG_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_WWDGEN))
#define __HAL_RCC_SPI2_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_SPI2EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_SPI3EN))
#define __HAL_RCC_USART2_CLK_DISABLE()    (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_USART2EN))
#define __HAL_RCC_USART3_CLK_DISABLE()    (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_USART3EN))
#define __HAL_RCC_UART1_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_UART1EN))
#define __HAL_RCC_UART2_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_UART2EN))
#define __HAL_RCC_I2C1_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_I2C1EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_I2C2EN))
#define __HAL_RCC_UART3_CLK_DISABLE()     (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_UART3EN))
#define __HAL_RCC_CAN1_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_CAN1EN))
#define __HAL_RCC_CAN2_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_CAN2EN))
#define __HAL_RCC_BKP_CLK_DISABLE()       (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_BKPEN))
#define __HAL_RCC_PWR_CLK_DISABLE()       (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_PWREN))
#define __HAL_RCC_DAC_CLK_DISABLE()       (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_DACEN))
#define __HAL_RCC_I2C3_CLK_DISABLE()      (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_I2C3EN))
#define __HAL_RCC_CTC_CLK_DISABLE()       (RCC->APB1ENR1 &= ~(RCC_APB1ENR1_CTCEN))
/**
  * @}
  */

/** @defgroup RCC_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_TIM2_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM2EN)) != RESET)
#define __HAL_RCC_TIM2_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM2EN)) == RESET)
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM3EN)) != RESET)
#define __HAL_RCC_TIM3_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM3EN)) == RESET)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM4EN)) != RESET)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM4EN)) == RESET)
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM5EN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM5EN)) == RESET)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM6EN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM6EN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM7EN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM7EN)) == RESET)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM12EN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM12EN)) == RESET)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM13EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM14EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM14EN)) == RESET)
#define __HAL_RCC_TIM18_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM18EN)) != RESET)
#define __HAL_RCC_TIM18_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_TIM18EN)) == RESET)
#define __HAL_RCC_WWDG_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_WWDGEN)) != RESET)
#define __HAL_RCC_WWDG_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_WWDGEN)) == RESET)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_SPI2EN)) != RESET)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_SPI2EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_SPI3EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_SPI3EN)) == RESET)
#define __HAL_RCC_USART2_IS_CLK_ENABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_USART2EN)) != RESET)
#define __HAL_RCC_USART2_IS_CLK_DISABLED()    ((RCC->APB1ENR1 & (RCC_APB1ENR1_USART2EN)) == RESET)
#define __HAL_RCC_USART3_IS_CLK_ENABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_USART3EN)) != RESET)
#define __HAL_RCC_USART3_IS_CLK_DISABLED()    ((RCC->APB1ENR1 & (RCC_APB1ENR1_USART3EN)) == RESET)
#define __HAL_RCC_UART1_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_UART1EN)) != RESET)
#define __HAL_RCC_UART1_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_UART1EN)) == RESET)
#define __HAL_RCC_UART2_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_UART2EN)) != RESET)
#define __HAL_RCC_UART2_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_UART2EN)) == RESET)
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_I2C1EN)) != RESET)
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_I2C1EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_I2C2EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_I2C2EN)) == RESET)
#define __HAL_RCC_UART3_IS_CLK_ENABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_UART3EN)) != RESET)
#define __HAL_RCC_UART3_IS_CLK_DISABLED()     ((RCC->APB1ENR1 & (RCC_APB1ENR1_UART3EN)) == RESET)
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_CAN1EN)) != RESET)
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_CAN1EN)) == RESET)
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_CAN2EN)) != RESET)
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_CAN2EN)) == RESET)
#define __HAL_RCC_BKP_IS_CLK_ENABLED()        ((RCC->APB1ENR1 & (RCC_APB1ENR1_BKPEN)) != RESET)
#define __HAL_RCC_BKP_IS_CLK_DISABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_BKPEN)) == RESET)
#define __HAL_RCC_PWR_IS_CLK_ENABLED()        ((RCC->APB1ENR1 & (RCC_APB1ENR1_PWREN)) != RESET)
#define __HAL_RCC_PWR_IS_CLK_DISABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_PWREN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_ENABLED()        ((RCC->APB1ENR1 & (RCC_APB1ENR1_DACEN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_DISABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_DACEN)) == RESET)
#define __HAL_RCC_I2C3_IS_CLK_ENABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_I2C3EN)) != RESET)
#define __HAL_RCC_I2C3_IS_CLK_DISABLED()      ((RCC->APB1ENR1 & (RCC_APB1ENR1_I2C3EN)) == RESET)
#define __HAL_RCC_CTC_IS_CLK_ENABLED()        ((RCC->APB1ENR1 & (RCC_APB1ENR1_CTCEN)) != RESET)
#define __HAL_RCC_CTC_IS_CLK_DISABLED()       ((RCC->APB1ENR1 & (RCC_APB1ENR1_CTCEN)) == RESET)

#define __HAL_RCC_LPTIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_LPUART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_I2C4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_LPTIM1_CLK_DISABLE()       (RCC->APB1ENR2 &= ~(RCC_APB1ENR2_LPTIM1EN))
#define __HAL_RCC_LPUART1_CLK_DISABLE()      (RCC->APB1ENR2 &= ~(RCC_APB1ENR2_LPUART1EN))
#define __HAL_RCC_I2C4_CLK_DISABLE()         (RCC->APB1ENR2 &= ~(RCC_APB1ENR2_I2C4EN))

#define __HAL_RCC_LPTIM1_IS_CLK_ENABLED()    ((RCC->APB1ENR2 & (RCC_APB1ENR2_LPTIM1EN)) != RESET)
#define __HAL_RCC_LPTIM1_IS_CLK_DISABLED()   ((RCC->APB1ENR2 & (RCC_APB1ENR2_LPTIM1EN)) == RESET)
#define __HAL_RCC_LPUART1_IS_CLK_ENABLED()   ((RCC->APB1ENR2 & (RCC_APB1ENR2_LPUART1EN)) != RESET)
#define __HAL_RCC_LPUART1_IS_CLK_DISABLED()  ((RCC->APB1ENR2 & (RCC_APB1ENR2_LPUART1EN)) == RESET)
#define __HAL_RCC_I2C4_IS_CLK_ENABLED()      ((RCC->APB1ENR2 & (RCC_APB1ENR2_I2C4EN)) != RESET)
#define __HAL_RCC_I2C4_IS_CLK_DISABLED()     ((RCC->APB1ENR2 & (RCC_APB1ENR2_I2C4EN)) == RESET)                                      
/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Enable_Disable APB2 Clock Enable Disable
  * @brief  Enable or disable the High Speed APB (APB2) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_ADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
                                      
#define __HAL_RCC_USART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_ADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM9_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM10_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM11_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM15_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM16_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM17_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_TIM19_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM19EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM19EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
                                      
#define __HAL_RCC_RNG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_RNGEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_RNGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_COMP_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_COMPEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_COMPEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_OPA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_OPAEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_OPAEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
#define __HAL_RCC_LCDC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_LCDCEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LCDCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)
                                      
#define __HAL_RCC_SYSCFG_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_SYSCFGEN))
#define __HAL_RCC_ADC1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN))
#define __HAL_RCC_ADC2_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC2EN))
#define __HAL_RCC_TIM1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN))
#define __HAL_RCC_SPI1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
#define __HAL_RCC_TIM8_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
#define __HAL_RCC_USART1_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN))
#define __HAL_RCC_ADC3_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC3EN))
#define __HAL_RCC_TIM9_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
#define __HAL_RCC_TIM10_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM10EN))
#define __HAL_RCC_TIM11_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
#define __HAL_RCC_TIM15_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15EN))
#define __HAL_RCC_TIM16_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16EN))
#define __HAL_RCC_TIM17_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17EN))
#define __HAL_RCC_TIM19_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM19EN)) 
#define __HAL_RCC_RNG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_RNGEN))
#define __HAL_RCC_COMP_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_COMPEN))
#define __HAL_RCC_OPA_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_OPAEN))
#define __HAL_RCC_LCDC_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_LCDCEN))
/**
  * @}
  */

/** @defgroup RCC_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_SYSCFG_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_SYSCFGEN)) != RESET)
#define __HAL_RCC_SYSCFG_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_SYSCFGEN)) == RESET)
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) != RESET)
#define __HAL_RCC_ADC1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) == RESET)
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
#define __HAL_RCC_ADC2_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) == RESET)
#define __HAL_RCC_TIM1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET)
#define __HAL_RCC_TIM1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET)
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
#define __HAL_RCC_USART1_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) != RESET)
#define __HAL_RCC_USART1_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) == RESET)
#define __HAL_RCC_ADC3_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) != RESET)
#define __HAL_RCC_ADC3_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) == RESET)
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
#define __HAL_RCC_TIM10_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) != RESET)
#define __HAL_RCC_TIM10_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) == RESET)
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)
#define __HAL_RCC_TIM11_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) == RESET)
#define __HAL_RCC_TIM15_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) != RESET)
#define __HAL_RCC_TIM15_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) == RESET)
#define __HAL_RCC_TIM16_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) != RESET)
#define __HAL_RCC_TIM16_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) == RESET)
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) != RESET)
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) == RESET)
#define __HAL_RCC_TIM19_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM19EN)) != RESET)
#define __HAL_RCC_TIM19_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_TIM19EN)) == RESET)
#define __HAL_RCC_RNG_IS_CLK_ENABLED()        ((RCC->APB2ENR & (RCC_APB2ENR_RNGEN)) != RESET)
#define __HAL_RCC_RNG_IS_CLK_DISABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_RNGEN)) == RESET)
#define __HAL_RCC_COMP_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_COMPEN)) != RESET)
#define __HAL_RCC_COMP_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_COMPEN)) == RESET)
#define __HAL_RCC_OPA_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_OPAEN)) != RESET)
#define __HAL_RCC_OPA_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_OPAEN)) == RESET)
#define __HAL_RCC_LCDC_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_LCDCEN)) != RESET)
#define __HAL_RCC_LCDC_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_LCDCEN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  Force or release APB1 peripheral reset.
  * @{
  */
#define __HAL_RCC_APB1_1_FORCE_RESET()       (RCC->APB1RSTR1 = 0xFFFFFFFFU)
#define __HAL_RCC_TIM2_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM2RST))
#define __HAL_RCC_TIM3_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM3RST))
#define __HAL_RCC_TIM4_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM4RST))
#define __HAL_RCC_TIM5_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM5RST))
#define __HAL_RCC_TIM6_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM6RST))
#define __HAL_RCC_TIM7_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM7RST))
#define __HAL_RCC_TIM12_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM14RST))
#define __HAL_RCC_TIM18_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_TIM18RST))
#define __HAL_RCC_WWDG_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_WWDGRST))
#define __HAL_RCC_SPI2_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_SPI2RST))
#define __HAL_RCC_SPI3_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_SPI3RST))
#define __HAL_RCC_USART2_FORCE_RESET()       (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_USART2RST))
#define __HAL_RCC_USART3_FORCE_RESET()       (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_USART3RST))
#define __HAL_RCC_UART1_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_UART1RST))
#define __HAL_RCC_UART2_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_UART2RST))
#define __HAL_RCC_I2C1_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_I2C1RST))
#define __HAL_RCC_I2C2_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_I2C2RST))
#define __HAL_RCC_UART3_FORCE_RESET()        (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_UART3RST))
#define __HAL_RCC_CAN1_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_CAN1RST))
#define __HAL_RCC_CAN2_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_CAN2RST))
#define __HAL_RCC_PWR_FORCE_RESET()          (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_PWRRST))
#define __HAL_RCC_DAC_FORCE_RESET()          (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_DACRST))
#define __HAL_RCC_I2C3_FORCE_RESET()         (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_I2C3RST))
#define __HAL_RCC_CTC_FORCE_RESET()          (RCC->APB1RSTR1 |= (RCC_APB1RSTR1_CTCRST))

#define __HAL_RCC_APB1_1_RELEASE_RESET()     (RCC->APB1RSTR1 = 0x00)
#define __HAL_RCC_TIM2_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM2RST))
#define __HAL_RCC_TIM3_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM3RST))
#define __HAL_RCC_TIM4_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM4RST))
#define __HAL_RCC_TIM5_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM5RST))
#define __HAL_RCC_TIM6_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM6RST))
#define __HAL_RCC_TIM7_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM7RST))
#define __HAL_RCC_TIM12_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM14RST))
#define __HAL_RCC_TIM18_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_TIM18RST))
#define __HAL_RCC_WWDG_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_WWDGRST))
#define __HAL_RCC_SPI2_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_SPI2RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_SPI3RST))
#define __HAL_RCC_USART2_RELEASE_RESET()     (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_USART2RST))
#define __HAL_RCC_USART3_RELEASE_RESET()     (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_USART3RST))
#define __HAL_RCC_UART1_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_UART1RST))
#define __HAL_RCC_UART2_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_UART2RST))
#define __HAL_RCC_I2C1_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_I2C1RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_I2C2RST))
#define __HAL_RCC_UART3_RELEASE_RESET()      (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_UART3RST))
#define __HAL_RCC_CAN1_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_CAN1RST))
#define __HAL_RCC_CAN2_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_CAN2RST))
#define __HAL_RCC_PWR_RELEASE_RESET()        (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_PWRRST))
#define __HAL_RCC_DAC_RELEASE_RESET()        (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_DACRST))
#define __HAL_RCC_I2C3_RELEASE_RESET()       (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_I2C3RST))
#define __HAL_RCC_CTC_RELEASE_RESET()        (RCC->APB1RSTR1 &= ~(RCC_APB1RSTR1_CTCRST))

#define __HAL_RCC_APB1_2_FORCE_RESET()       (RCC->APB1RSTR2 = 0xFFFFFFFFU)
#define __HAL_RCC_LPTIM1_FORCE_RESET()       (RCC->APB1RSTR2 |= (RCC_APB1RSTR2_LPTIM1RST))
#define __HAL_RCC_LPUART1_FORCE_RESET()      (RCC->APB1RSTR2 |= (RCC_APB1RSTR2_LPUART1RST))
#define __HAL_RCC_I2C4_FORCE_RESET()         (RCC->APB1RSTR2 |= (RCC_APB1RSTR2_I2C4RST))

#define __HAL_RCC_APB1_2_RELEASE_RESET()     (RCC->APB1RSTR2 = 0x00)
#define __HAL_RCC_LPTIM1_RELEASE_RESET()     (RCC->APB1RSTR2 &= ~(RCC_APB1RSTR2_LPTIM1RST))
#define __HAL_RCC_LPUART1_RELEASE_RESET()    (RCC->APB1RSTR2 &= ~(RCC_APB1RSTR2_LPUART1RST))
#define __HAL_RCC_I2C4_RELEASE_RESET()       (RCC->APB1RSTR2 &= ~(RCC_APB1RSTR2_I2C4RST))
/**
  * @}
  */

/** @defgroup RCC_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  Force or release APB2 peripheral reset.
  * @{
  */
#define __HAL_RCC_APB2_FORCE_RESET()         (RCC->APB2RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_SYSCFG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_SYSCFGRST))
#define __HAL_RCC_ADC1_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC1RST))
#define __HAL_RCC_ADC2_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC2RST))
#define __HAL_RCC_TIM1_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST))
#define __HAL_RCC_SPI1_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_TIM8_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_USART1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST))
#define __HAL_RCC_ADC3_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC3RST))
#define __HAL_RCC_TIM9_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))
#define __HAL_RCC_TIM15_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM17RST))
#define __HAL_RCC_TIM19_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM19RST))
#define __HAL_RCC_RNG_FORCE_RESET()          (RCC->APB2RSTR |= (RCC_APB2RSTR_RNGRST))
#define __HAL_RCC_COMP_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_COMPRST))
#define __HAL_RCC_OPA_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_OPARST))
#define __HAL_RCC_LCDC_FORCE_RESET()         (RCC->APB2RSTR |= (RCC_APB2RSTR_LCDCRST))

#define __HAL_RCC_APB2_RELEASE_RESET()       (RCC->APB2RSTR = 0x00)
#define __HAL_RCC_SYSCFG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SYSCFGRST))
#define __HAL_RCC_ADC1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC1RST))
#define __HAL_RCC_ADC2_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC2RST))
#define __HAL_RCC_TIM1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST))
#define __HAL_RCC_SPI1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
#define __HAL_RCC_TIM8_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_USART1_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST))
#define __HAL_RCC_ADC3_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC3RST))
#define __HAL_RCC_TIM9_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM11RST))
#define __HAL_RCC_TIM15_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM17RST))
#define __HAL_RCC_TIM19_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM19RST))
#define __HAL_RCC_RNG_RELEASE_RESET()        (RCC->APB2RSTR &= ~(RCC_APB2RSTR_RNGRST))
#define __HAL_RCC_COMP_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_COMPRST))
#define __HAL_RCC_OPA_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_OPARST))
#define __HAL_RCC_LCDC_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_LCDCRST))
/**
  * @}
  */

/** @defgroup RCC_AHB1_Force_Release_Reset AHB1 Peripheral Force Release Reset
  * @brief  Force or release AHB1 peripheral reset.
  * @{
  */
#define __HAL_RCC_AHB1_FORCE_RESET()         (RCC->AHB1RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_DMA1_FORCE_RESET()         (RCC->AHB1RSTR |= (RCC_AHB1RSTR_DMA1RST))
#define __HAL_RCC_DMA2_FORCE_RESET()         (RCC->AHB1RSTR |= (RCC_AHB1RSTR_DMA2RST))
#define __HAL_RCC_CORDIC_FORCE_RESET()       (RCC->AHB1RSTR |= (RCC_AHB1RSTR_CORDICRST))
#define __HAL_RCC_CRC_FORCE_RESET()          (RCC->AHB1RSTR |= (RCC_AHB1RSTR_CRCRST))
#define __HAL_RCC_ESMC_FORCE_RESET()         (RCC->AHB1RSTR |= (RCC_AHB1RSTR_ESMCRST))

#define __HAL_RCC_AHB1_RELEASE_RESET()       (RCC->AHB1RSTR = 0x00)
#define __HAL_RCC_DMA1_RELEASE_RESET()       (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_DMA1RST))
#define __HAL_RCC_DMA2_RELEASE_RESET()       (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_DMA2RST))
#define __HAL_RCC_CORDIC_RELEASE_RESET()     (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_CORDICRST))
#define __HAL_RCC_CRC_RELEASE_RESET()        (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_CRCRST))
#define __HAL_RCC_ESMC_RELEASE_RESET()       (RCC->AHB1RSTR &= ~(RCC_AHB1RSTR_ESMCRST))
/**
  * @}
  */

/** @defgroup RCC_AHB2_Force_Release_Reset AHB2 Force Release Reset
  * @brief  Force or release APB2 peripheral reset.
  * @{
  */
#define __HAL_RCC_AHB2_FORCE_RESET()        (RCC->AHB2RSTR = 0xFFFFFFFFU)
#define __HAL_RCC_GPIOA_FORCE_RESET()       (RCC->AHB2RSTR |= (RCC_AHB2RSTR_IOPARST))
#define __HAL_RCC_GPIOB_FORCE_RESET()       (RCC->AHB2RSTR |= (RCC_AHB2RSTR_IOPBRST))
#define __HAL_RCC_GPIOC_FORCE_RESET()       (RCC->AHB2RSTR |= (RCC_AHB2RSTR_IOPCRST))
#define __HAL_RCC_GPIOD_FORCE_RESET()       (RCC->AHB2RSTR |= (RCC_AHB2RSTR_IOPDRST))
#define __HAL_RCC_GPIOE_FORCE_RESET()       (RCC->AHB2RSTR |= (RCC_AHB2RSTR_IOPERST))
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->AHB2RSTR |= (RCC_AHB2RSTR_IOPFRST))
#define __HAL_RCC_SDIO_FORCE_RESET()        (RCC->AHB2RSTR |= (RCC_AHB2RSTR_SDIORST))
#define __HAL_RCC_AES_FORCE_RESET()         (RCC->AHB2RSTR |= (RCC_AHB2RSTR_AESRST))
#define __HAL_RCC_USB1_FORCE_RESET()        (RCC->AHB2RSTR |= (RCC_AHB2RSTR_USB1RST))
#define __HAL_RCC_USB2_FORCE_RESET()        (RCC->AHB2RSTR |= (RCC_AHB2RSTR_USB2RST))
#define __HAL_RCC_ETH_FORCE_RESET()         (RCC->AHB2RSTR |= (RCC_AHB2RSTR_ETHRST))

#define __HAL_RCC_AHB2_RELEASE_RESET()      (RCC->AHB2RSTR = 0x00)
#define __HAL_RCC_GPIOA_RELEASE_RESET()     (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_IOPARST))
#define __HAL_RCC_GPIOB_RELEASE_RESET()     (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_IOPBRST))
#define __HAL_RCC_GPIOC_RELEASE_RESET()     (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_IOPCRST))
#define __HAL_RCC_GPIOD_RELEASE_RESET()     (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_IOPDRST))
#define __HAL_RCC_GPIOE_RELEASE_RESET()     (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_IOPERST))
#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_IOPFRST))
#define __HAL_RCC_SDIO_RELEASE_RESET()      (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_SDIORST))
#define __HAL_RCC_AES_RELEASE_RESET()       (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_AESRST))
#define __HAL_RCC_USB1_RELEASE_RESET()      (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_USB1RST))
#define __HAL_RCC_USB2_RELEASE_RESET()      (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_USB2RST))
#define __HAL_RCC_ETH_RELEASE_RESET()       (RCC->AHB2RSTR &= ~(RCC_AHB2RSTR_ETHRST))
/**
  * @}
  */

/** @defgroup RCC_HSI_Configuration HSI Configuration
  * @{
  */

/** @brief  Macros to enable or disable the Internal High Speed oscillator (HSI).
  * @note   The HSI is stopped by hardware when entering STOP and STANDBY modes.
  * @note   HSI can not be stopped if it is used as system clock source. In this case,
  *         you have to select another source of the system clock then stop the HSI.
  * @note   After enabling the HSI, the application software should wait on HSIRDY
  *         flag to be set indicating that HSI clock is stable and can be used as
  *         system clock source.
  * @note   When the HSI is stopped, HSIRDY flag goes low after 6 HSI oscillator
  *         clock cycles.
  */
#define __HAL_RCC_HSI_ENABLE()  SET_BIT(RCC->CR, RCC_CR_HSION)
#define __HAL_RCC_HSI_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_HSION)

/** @brief  Macros to enable or disable the Internal 48MHz High Speed oscillator (HSI48M).
  */
#define __HAL_RCC_HSI48M_ENABLE()  SET_BIT(RCC->CFGR1, RCC_CFGR1_HSI48ON)
#define __HAL_RCC_HSI48M_DISABLE() CLEAR_BIT(RCC->CFGR1, RCC_CFGR1_HSI48ON)

/** @brief  Macro to adjust the Internal High Speed oscillator (HSI) calibration value.
  * @note   The calibration is used to compensate for the variations in voltage
  *         and temperature that influence the frequency of the internal HSI RC.
  * @param  _HSICALIBRATIONVALUE_ specifies the calibration trimming value.
  *         (default is RCC_HSICALIBRATION_DEFAULT).
  *         This parameter must be a number between 0 and 0x1F.
  */
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(_HSICALIBRATIONVALUE_) \
          (MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, (uint32_t)(_HSICALIBRATIONVALUE_) << RCC_CR_HSITRIM_Pos))

/** @brief  Macro to adjust the Internal 48MHz High Speed oscillator (HSI48M) calibration value.
  * @param  _HSICALIBRATIONVALUE_ specifies the calibration trimming value.
  *         (default is RCC_HSI48MCALIBRATION_DEFAULT).
  *         This parameter must be a number between 0 and 0x7F.
  */
#define __HAL_RCC_HSI48M_CALIBRATIONVALUE_ADJUST(_HSICALIBRATIONVALUE_) \
          (MODIFY_REG(RCC->CFGR1, RCC_CFGR1_HSI48TRIM, (uint32_t)(_HSICALIBRATIONVALUE_) << RCC_CFGR1_HSI48TRIM_Pos))

/**
  * @brief    Macros to enable or disable the force of the Internal High Speed oscillator (HSI)
  *           in STOP mode to be quickly available as kernel clock for USARTs and I2Cs.
  * @note     Keeping the HSI ON in STOP mode allows to avoid slowing down the communication
  *           speed because of the HSI startup time.
  * @note     The enable of this function has not effect on the HSION bit.
  *           This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
#define __HAL_RCC_HSISTOP_ENABLE()     SET_BIT(RCC->CR, RCC_CR_HSIKERON)

#define __HAL_RCC_HSISTOP_DISABLE()    CLEAR_BIT(RCC->CR, RCC_CR_HSIKERON)
/**
  * @}
  */

/** @defgroup RCC_LSI_Configuration  LSI Configuration
  * @{
  */

/** @brief Macro to enable the Internal Low Speed oscillator (LSI).
  * @note   After enabling the LSI, the application software should wait on
  *         LSIRDY flag to be set indicating that LSI clock is stable and can
  *         be used to clock the IWDG and/or the RTC.
  */
#define __HAL_RCC_LSI_ENABLE()  SET_BIT(RCC->CSR, RCC_CSR_LSION)

/** @brief Macro to disable the Internal Low Speed oscillator (LSI).
  * @note   LSI can not be disabled if the IWDG is running.
  * @note   When the LSI is stopped, LSIRDY flag goes low after 6 LSI oscillator
  *         clock cycles.
  */
#define __HAL_RCC_LSI_DISABLE() CLEAR_BIT(RCC->CSR, RCC_CSR_LSION)

/**
  * @}
  */

/** @defgroup RCC_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @brief  Macro to configure the External High Speed oscillator (HSE).
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this macro. User should request a transition to HSE Off
  *         first and then HSE On or HSE Bypass.
  * @note   After enabling the HSE (RCC_HSE_ON or RCC_HSE_Bypass), the application
  *         software should wait on HSERDY flag to be set indicating that HSE clock
  *         is stable and can be used to clock the PLL and/or system clock.
  * @note   HSE state can not be changed if it is used directly or through the
  *         PLL as system clock. In this case, you have to select another source
  *         of the system clock then change the HSE state (ex. disable it).
  * @note   The HSE is stopped by hardware when entering STOP and STANDBY modes.
  * @note   This function reset the CSSON bit, so if the clock security system(CSS)
  *         was previously enabled you have to enable it again after calling this
  *         function.
  * @param  __STATE__ specifies the new state of the HSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_HSE_OFF turn OFF the HSE oscillator, HSERDY flag goes low after
  *                              6 HSE oscillator clock cycles.
  *            @arg @ref RCC_HSE_ON turn ON the HSE oscillator
  *            @arg @ref RCC_HSE_BYPASS HSE oscillator bypassed with external clock
  */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_HSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);                    \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                    }while(0U)

/**
  * @brief  Macro to configure the HSE frequency range.
  * @param  __FREQ__ specifies the HSE frequency range.
  *          This parameter can be one of the following values:
  *              @arg @ref RCC_HSE_4_8MHz
  *              @arg @ref RCC_HSE_8_16MHz
  *              @arg @ref RCC_HSE_16_32MHz
  */
#define __HAL_RCC_HSE_FREQ_CONFIG(__FREQ__)    MODIFY_REG(RCC->CFGR2, RCC_CFGR2_HSEDRV, (__FREQ__))

/** 
  * @}
  */

/** @defgroup RCC_LSE_Configuration LSE Configuration
  * @{
  */

/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE).
  * @note Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not supported by this macro.
  * @note   As the LSE is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         @ref HAL_PWR_EnableBkUpAccess() function before to configure the LSE
  *         (to be done once after reset).
  * @note   After enabling the LSE (RCC_LSE_ON or RCC_LSE_BYPASS), the application
  *         software should wait on LSERDY flag to be set indicating that LSE clock
  *         is stable and can be used to clock the RTC.
  * @param  __STATE__ specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSE_OFF turn OFF the LSE oscillator, LSERDY flag goes low after
  *                              6 LSE oscillator clock cycles.
  *            @arg @ref RCC_LSE_ON turn ON the LSE oscillator.
  *            @arg @ref RCC_LSE_BYPASS LSE oscillator bypassed with external clock.
  */
#define __HAL_RCC_LSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_LSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                  \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                    }while(0U)

/**
  * @brief  Macro to configure the LSE drive capability.
  * @param  __DRIVER__ specifies the LSE drive capability.
  *          This parameter can be one of the following values:
  *              @arg @ref RCC_LSEDRIVE_LOW
  *              @arg @ref RCC_LSEDRIVE_MEDIUM
  *              @arg @ref RCC_LSEDRIVE_HIGH
  *              @arg @ref RCC_LSEDRIVE_VERY_HIGH
  */
#define __HAL_RCC_LSE_DRIVER_CONFIG(__DRIVER__)   MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, (__DRIVER__))
                    
/**
  * @}
  */

/** @defgroup RCC_PLL_Configuration PLL Configuration
  * @{
  */

/** @brief Macro to enable the main PLL.
  * @note   After enabling the main PLL, the application software should wait on
  *         PLLRDY flag to be set indicating that PLL clock is stable and can
  *         be used as system clock source.
  * @note   The main PLL is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLL_ENABLE()          SET_BIT(RCC->CR, RCC_CR_PLLON)

/** @brief Macro to disable the main PLL.
  * @note   The main PLL can not be disabled if it is used as system clock source
  */
#define __HAL_RCC_PLL_DISABLE()         CLEAR_BIT(RCC->CR, RCC_CR_PLLON)

/** @brief Macro to configure the main PLL clock source and multiplication factors.
  * @note   This function must be used only when the main PLL is disabled.
  *
  * @param  __RCC_PLLSOURCE__ specifies the PLL entry clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI/2 oscillator clock selected as PLL clock entry
  *            @arg @ref RCC_PLLSOURCE_HSE HSE oscillator clock selected as PLL clock entry
  *            @arg @ref RCC_PLLSOURCE_HSE_DIV2 HSE/2 oscillator clock selected as PLL clock entry
  * @param  __PLLMUL__ specifies the multiplication factor for PLL VCO output clock
  *          This parameter must be a number between 2 and 257.
  * @param  __PLLPrediv__ specifies the division factor for PLL
  *          This parameter must be a value of @ref RCCEx_PLL_Prediv_Factor
  * @param  __PLLPostdiv__ specifies the division factor for PLL
  *          This parameter must be a value of @ref RCCEx_PLL_Postdiv_Factor
  */
#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSOURCE__, __PLLMUL__,__PLLPrediv__,__PLLPostdiv__)\
                  MODIFY_REG(RCC->CFGR3, \
                             (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLFBDIV | RCC_CFGR3_PLLXTPRE | \
                              RCC_CFGR3_PLLPREDIV | RCC_CFGR3_PLLPOSTDIV), \
                             ((__RCC_PLLSOURCE__) | (__PLLPrediv__) | (__PLLPostdiv__) | \
                              (((__PLLMUL__) - 2U) << RCC_CFGR3_PLLFBDIV_Pos)))

/** @brief  Get oscillator clock selected as PLL input clock
  * @retval The clock source used for PLL entry. The returned value can be one
  *         of the following:
  *             @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI/2 oscillator clock selected as PLL input clock
  *             @arg @ref RCC_PLLSOURCE_HSE HSE oscillator clock selected as PLL input clock
  *             @arg @ref RCC_PLLSOURCE_HSE_DIV2 HSE/2 oscillator clock selected as PLL input clock
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)))

/**
  * @}
  */

/** @defgroup RCC_Get_Clock_source Get Clock source
  * @{
  */

/**
  * @brief  Macro to configure the system clock source.
  * @param  __SYSCLKSOURCE__ specifies the system clock source.
  *          This parameter can be one of the following values:
  *              @arg @ref RCC_SYSCLKSOURCE_HSI HSI oscillator is used as system clock source.
  *              @arg @ref RCC_SYSCLKSOURCE_HSE HSE oscillator is used as system clock source.
  *              @arg @ref RCC_SYSCLKSOURCE_PLLCLK PLL output is used as system clock source.
  */
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))

/** @brief  Macro to get the clock source used as system clock.
  * @retval The clock source used as system clock. The returned value can be one
  *         of the following:
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSI HSI used as system clock
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSE HSE used as system clock
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_PLLCLK PLL used as system clock
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR,RCC_CFGR_SWS)))

/**
  * @}
  */

/** @defgroup RCCEx_MCOx_Clock_Config RCC Extended MCOx Clock Config
  * @{
  */

/** @brief  Macro to configure the MCO clock.
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_MCOSOURCE_NOCLOCK  MCO output disabled, no clock on MCO
  *            @arg @ref RCC_MCOSOURCE_SYSCLK  system  clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSI16M  HSI16M clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_LSI  LSI clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSE  HSE clock selected as MCO sourcee
  *            @arg @ref RCC_MCOSOURCE_LSE  LSE clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_PLLCLK  main PLL clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSI48M  HSI48M clock selected as MCO source for devices with HSI48M
  *            @arg @ref RCC_MCOSOURCE_HCLK  HCLK clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_PCLK1  APB1 clock selected as MCO sourcee
  *            @arg @ref RCC_MCOSOURCE_PCLK2  APB2 clock selected as MCO source
  *            @arg @ref RCC_MCOSOURCE_HSI10M  HSI10M clock selected as MCO source
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1  no division applied to MCO clock
  *            @arg @ref RCC_MCODIV_2  division by 2 applied to MCO clock
  *            @arg @ref RCC_MCODIV_4  division by 4 applied to MCO clock
  *            @arg @ref RCC_MCODIV_8  division by 8 applied to MCO clock
  *            @arg @ref RCC_MCODIV_16  division by 16 applied to MCO clock
  *            @arg @ref RCC_MCODIV_32  division by 32 applied to MCO clock
  *            @arg @ref RCC_MCODIV_64  division by 64 applied to MCO clock
  *            @arg @ref RCC_MCODIV_128  division by 128 applied to MCO clock
  */

#define __HAL_RCC_MCO_CONFIG(__MCOCLKSOURCE__, __MCODIV__)                 \
                 do{                                                        \
                   MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, (__MCOCLKSOURCE__)); \
                   MODIFY_REG(RCC->CFGR1, RCC_CFGR1_MCOPRE, (__MCODIV__));  \
                 }while(0U)

/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Configuration RCC RTC Clock Configuration
* @{
*/

/** @brief Macro to configure the RTC clock (RTCCLK).
  * @note   As the RTC clock configuration bits are in the Backup domain and write
  *         access is denied to this domain after reset, you have to enable write
  *         access using the Power Backup Access macro before to configure
  *         the RTC clock source (to be done once after reset).
  * @note   Once the RTC clock is configured it can't be changed unless the
  *         Backup domain is reset using @ref __HAL_RCC_BACKUPRESET_FORCE() macro, or by
  *         a Power On Reset (POR).
  *
  * @param  __RTC_CLKSOURCE__ specifies the RTC clock source.
  *          This parameter can be one of the following values:
  *             @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *             @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *             @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *             @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE divided by 128 selected as RTC clock
  * @note   If the LSE or LSI is used as RTC clock source, the RTC continues to
  *         work in STOP and STANDBY modes, and can be used as wakeup source.
  *         However, when the HSE clock is used as RTC clock source, the RTC
  *         cannot be used in STOP and STANDBY modes.
  * @note   The maximum input clock frequency for RTC is 1MHz (when using HSE as
  *         RTC clock source).
  */
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__) MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))

/** @brief Macro to get the RTC clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE divided by 128 selected as RTC clock
  */
#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

/** @brief Macro to enable the RTC clock.
  * @note   These macros must be used only after the RTC clock source was selected.
  */
#define __HAL_RCC_RTC_ENABLE()          SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN)

/** @brief Macro to disable the RTC clock.
  * @note  These macros must be used only after the RTC clock source was selected.
  */
#define __HAL_RCC_RTC_DISABLE()         CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN)

/** @brief  Macro to force the Backup domain reset.
  * @note   This function resets the RTC peripheral (including the backup registers)
  *         and the RTC clock source selection in RCC_BDCR register.
  */
#define __HAL_RCC_BACKUPRESET_FORCE()   SET_BIT(RCC->BDCR, RCC_BDCR_BDRST)

/** @brief  Macros to release the Backup domain reset.
  */
#define __HAL_RCC_BACKUPRESET_RELEASE() CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST)

/**
  * @}
  */

/** @defgroup RCC_Flags_Interrupts_Management Flags Interrupts Management
  * @brief macros to manage the specified RCC Flags and interrupts.
  * @{
  */

/** @brief Enable RCC interrupt.
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be enabled.
  *          This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  *            @arg @ref RCC_IT_HSI48MRDY HSI48M ready interrupt
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))

/** @brief Disable RCC interrupt.
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be disabled.
  *          This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  *            @arg @ref RCC_IT_HSI48MRDY HSI48M ready interrupt
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))

/** @brief Clear the RCC's interrupt pending bits.
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *          This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  *            @arg @ref RCC_IT_HSI48MRDY HSI48M ready interrupt
  *            @arg @ref RCC_IT_CSS Clock Security System interrupt
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))

/** @brief Check the RCC's interrupt has occurred or not.
  * @param  __INTERRUPT__ specifies the RCC interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  *            @arg @ref RCC_IT_HSI48MRDY HSI48M ready interrupt
  *            @arg @ref RCC_IT_CSS Clock Security System interrupt
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief Set RMVF bit to clear the reset flags.
  *         The reset flags are RCC_FLAG_OBLRST, RCC_FLAG_PINRST, RCC_FLAG_PWRRST, RCC_FLAG_SFTRST,
  *         RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST, RCC_FLAG_LPWRRST
  */
#define __HAL_RCC_CLEAR_RESET_FLAGS()     do{ \
                                            SET_BIT(RCC->CSR, RCC_CSR_RMVF); \
                                            CLEAR_BIT(RCC->CSR, RCC_CSR_RMVF); \
                                          }while(0)

/** @brief  Check RCC flag is set or not.
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_FLAG_HSIRDY HSI oscillator clock ready.
  *            @arg @ref RCC_FLAG_HSERDY HSE oscillator clock ready.
  *            @arg @ref RCC_FLAG_PLLRDY Main PLL clock ready.
  *            @arg @ref RCC_FLAG_LSERDY LSE oscillator clock ready.
  *            @arg @ref RCC_FLAG_LSIRDY LSI oscillator clock ready.
  *            @arg @ref RCC_FLAG_HSI48MRDY HSI48M oscillator clock ready.
               @arg @ref RCC_FLAG_OBLRST Option byte loader reset flag
  *            @arg @ref RCC_FLAG_PINRST  Pin reset.
  *            @arg @ref RCC_FLAG_PWRRST  POR/PDR reset.
  *            @arg @ref RCC_FLAG_SFTRST  Software reset.
  *            @arg @ref RCC_FLAG_IWDGRST Independent Watchdog reset.
  *            @arg @ref RCC_FLAG_WWDGRST Window Watchdog reset.
  *            @arg @ref RCC_FLAG_LPWRRST Low Power reset.
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((((__FLAG__) >> 5U) == CR_REG_INDEX)?   RCC->CR  : \
                                        ((((__FLAG__) >> 5U) == BDCR_REG_INDEX)? RCC->BDCR : \
                                        ((((__FLAG__) >> 5U) == CFGR1_REG_INDEX)? RCC->CFGR1 : RCC->CSR))) & \
                                       (1U << ((__FLAG__) & RCC_FLAG_MASK))) != RESET) ? 1U : 0U)

/**
  * @}
  */

/**
  * @}
  */

/* Include RCC HAL Extension module */
#include "py32e407_hal_rcc_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* Peripheral Control functions  ************************************************/
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

/* CSS NMI IRQ handler */
void              HAL_RCC_NMI_IRQHandler(void);

/* User Callbacks in non blocking mode (IT mode) */
void              HAL_RCC_CSSCallback(void);

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCC_Private_Constants
  * @{
  */

/** @defgroup RCC_Timeout RCC Timeout
  * @{
  */
/* Disable Backup domain write protection state change timeout */
#define RCC_DBP_TIMEOUT_VALUE          100U    /* 100 ms */
/* LSE state change timeout */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
#define CLOCKSWITCH_TIMEOUT_VALUE      5000    /* 5 s    */
#define HSE_TIMEOUT_VALUE              HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */
#define HSI48M_TIMEOUT_VALUE           2U      /* 2 ms (minimum Tick + 1) */
#define LSI_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */
#define PLL_TIMEOUT_VALUE              3U      /* 3 ms (minimum Tick + 1) */
/**
  * @}
  */

/** @defgroup RCC_Register_Offset Register offsets
  * @{
  */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)
#define RCC_CR_OFFSET             0x00U
#define RCC_CFGR_OFFSET           0x04U
#define RCC_CIR_OFFSET            0x08U
#define RCC_BDCR_OFFSET           0x20U
#define RCC_CSR_OFFSET            0x24U
/**
  * @}
  */

/* CR register byte 2 (Bits[23:16]) base address */
#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))

/* CIR register byte 1 (Bits[15:8]) base address */
#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))

/* CIR register byte 2 (Bits[23:16]) base address */
#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))

/* Defines used for Flags */
#define CR_REG_INDEX                     ((uint8_t)1)
#define BDCR_REG_INDEX                   ((uint8_t)2)
#define CSR_REG_INDEX                    ((uint8_t)3)
#define CFGR1_REG_INDEX                  ((uint8_t)4)

#define RCC_FLAG_MASK                    ((uint8_t)0x1F)

/**
  * @}
  */

/** @addtogroup RCC_Private_Macros
  * @{
  */

#define IS_RCC_PLLSOURCE(__SOURCE__)                  (((__SOURCE__) == RCC_PLLSOURCE_HSI_DIV2) || \
                                                       ((__SOURCE__) == RCC_PLLSOURCE_HSE_DIV2) || \
                                                       ((__SOURCE__) == RCC_PLLSOURCE_HSE))

#define IS_RCC_PLL_PREDIV(__PLLPREDIV__)              (((__PLLPREDIV__) == RCC_PLL_PREDIV_DIV1) || \
                                                       ((__PLLPREDIV__) == RCC_PLL_PREDIV_DIV2) || \
                                                       ((__PLLPREDIV__) == RCC_PLL_PREDIV_DIV4) || \
                                                       ((__PLLPREDIV__) == RCC_PLL_PREDIV_DIV8))

#define IS_RCC_PLL_POSTDIV(__PLLPOSTDIV__)            (((__PLLPOSTDIV__) == RCC_PLL_POSTDIV_DIV1) || \
                                                       ((__PLLPOSTDIV__) == RCC_PLL_POSTDIV_DIV2) || \
                                                       ((__PLLPOSTDIV__) == RCC_PLL_POSTDIV_DIV4) || \
                                                       ((__PLLPOSTDIV__) == RCC_PLL_POSTDIV_DIV8))

#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__)         (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                                       (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                                       (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                                       (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                                       (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE) || \
                                                       (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI48M) == RCC_OSCILLATORTYPE_HSI48M))
                                               
#define IS_RCC_HSE(__HSE__)                           (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                                                       ((__HSE__) == RCC_HSE_BYPASS))
                             
#define IS_RCC_LSE(__LSE__)                           (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                                                       ((__LSE__) == RCC_LSE_BYPASS))
                             
#define IS_RCC_HSI(__HSI__)                           (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))

#define IS_RCC_HSI48M(__HSI__)                        (((__HSI__) == RCC_HSI48M_OFF) || ((__HSI__) == RCC_HSI48M_ON))

#define IS_RCC_CALIBRATION_VALUE(__VALUE__)           ((__VALUE__) <= 0x1FU)

#define IS_RCC_HSI48M_CALIBRATION_VALUE(__VALUE__)    ((__VALUE__) <= 0x7FU)

#define IS_RCC_LSI(__LSI__)                           (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON))

#define IS_RCC_PLL(__PLL__)                           (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                                                       ((__PLL__) == RCC_PLL_ON))

#define IS_RCC_CLOCKTYPE(CLK)                         ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                                                       (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                                                       (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                                                       (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2))
                               
#define IS_RCC_SYSCLKSOURCE(__SOURCE__)               (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                                       ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                                       ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK))
                                         
#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__)        (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                       ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                       ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK))
                                                
#define IS_RCC_HCLK(__HCLK__)                         (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                                                       ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                                                       ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                                                       ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                                                       ((__HCLK__) == RCC_SYSCLK_DIV512))
                               
#define IS_RCC_PCLK(__PCLK__)                         (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                                                       ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                                                       ((__PCLK__) == RCC_HCLK_DIV16))
                               
#define IS_RCC_MCO(__MCO__)                           (((__MCO__) == RCC_MCO1) || ((__MCO__) == RCC_MCO2))

#define IS_RCC_MCODIV(__DIV__)                        (((__DIV__) == RCC_MCODIV_1) || ((__DIV__) == RCC_MCODIV_2) || \
                                                       ((__DIV__) == RCC_MCODIV_4) || ((__DIV__) == RCC_MCODIV_8) || \
                                                       ((__DIV__) == RCC_MCODIV_16) || ((__DIV__) == RCC_MCODIV_32) || \
                                                       ((__DIV__) == RCC_MCODIV_64) || ((__DIV__) == RCC_MCODIV_128))

#define IS_RCC_RTCCLKSOURCE(__SOURCE__)               (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                                       ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE) || \
                                                       ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI) || \
                                                       ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV128))

#define IS_RCC_HSE_FREQ(__DRIVER__)                   ((__DRIVER__) == RCC_HSE_4_8MHz)

/* #define IS_RCC_HSE_FREQ(__DRIVER__)                (((__DRIVER__) == RCC_HSE_4_8MHz)  || \
                                                       ((__DRIVER__) == RCC_HSE_8_16MHz) || \
                                                       ((__DRIVER__) == RCC_HSE_16_32MHz)) */
                                                       
#define IS_RCC_LSE_DRIVER(__DRIVER__)                 (((__DRIVER__) == RCC_LSEDRIVE_LOW)    || \
                                                       ((__DRIVER__) == RCC_LSEDRIVE_MEDIUM) || \
                                                       ((__DRIVER__) == RCC_LSEDRIVE_HIGH)   || \
                                                       ((__DRIVER__) == RCC_LSEDRIVE_VERY_HIGH ))
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

#endif /* __PY32E407_HAL_RCC_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

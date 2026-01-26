/**
  ******************************************************************************
  * @file    py32e407_ll_system.h
  * @author  MCU Application Team
  * @brief   Header file of SYSTEM LL module.
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
#ifndef PY32E407_LL_SYSTEM_H
#define PY32E407_LL_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (FLASH) || defined (SYSCFG) || defined (DBGMCU)

/** @defgroup SYSTEM_LL SYSTEM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Private_Constants SYSTEM Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Constants SYSTEM Exported Constants
  * @{
  */

/** @defgroup SYSTEM_LL_EC_REMAP SYSCFG REMAP
  * @{
  */
#define LL_SYSCFG_REMAP_FLASH               0x00000000U                                           /*!< Main Flash memory mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_SYSTEMFLASH         SYSCFG_CFGR1_MEM_MODE_0                               /*!< System Flash memory mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_ESMC                SYSCFG_CFGR1_MEM_MODE_1                               /*!< ESMC mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_SRAM                (SYSCFG_CFGR1_MEM_MODE_1 | SYSCFG_CFGR1_MEM_MODE_0)   /*!< Embedded SRAM mapped at 0x00000000 */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_ETH_PHY_Interface ETH PHY Interface
  * @{
  */
#define LL_SYSCFG_ETH_PHY_MII             0x00000000U
#define LL_SYSCFG_ETH_PHY_RMII            SYSCFG_CFGR1_ETH_PHYSEL
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_I2C_ANF I2C Analog Filter
  * @{
  */
#define LL_SYSCFG_I2C_ANF_PA8            SYSCFG_CFGR1_I2C_EIIC_0
#define LL_SYSCFG_I2C_ANF_PA9            SYSCFG_CFGR1_I2C_EIIC_1
#define LL_SYSCFG_I2C_ANF_PA13           SYSCFG_CFGR1_I2C_EIIC_2
#define LL_SYSCFG_I2C_ANF_PA14           SYSCFG_CFGR1_I2C_EIIC_3
#define LL_SYSCFG_I2C_ANF_PA15           SYSCFG_CFGR1_I2C_EIIC_4
#define LL_SYSCFG_I2C_ANF_PB5            SYSCFG_CFGR1_I2C_EIIC_5
#define LL_SYSCFG_I2C_ANF_PB7            SYSCFG_CFGR1_I2C_EIIC_6
#define LL_SYSCFG_I2C_ANF_PB8            SYSCFG_CFGR1_I2C_EIIC_7
#define LL_SYSCFG_I2C_ANF_PB9            SYSCFG_CFGR1_I2C_EIIC_8
#define LL_SYSCFG_I2C_ANF_PC3            SYSCFG_CFGR1_I2C_EIIC_9
#define LL_SYSCFG_I2C_ANF_PC6            SYSCFG_CFGR1_I2C_EIIC_10
#define LL_SYSCFG_I2C_ANF_PC7            SYSCFG_CFGR1_I2C_EIIC_11
#define LL_SYSCFG_I2C_ANF_PC8            SYSCFG_CFGR1_I2C_EIIC_12
#define LL_SYSCFG_I2C_ANF_PC9            SYSCFG_CFGR1_I2C_EIIC_13
#define LL_SYSCFG_I2C_ANF_PC11           SYSCFG_CFGR1_I2C_EIIC_14
#define LL_SYSCFG_I2C_ANF_PF0            SYSCFG_CFGR1_I2C_EIIC_15
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIM2_INTERNAL_TRIGGER1_REMAP TIM2 internal trigger1 remap
  * @{
  */
#define LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_NONE          0x00000000U
#define LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF      SYSCFG_CFGR1_TIM2ITR1_REMAP_0  /*!< TIM2ITR1 remaps to USB1_SOF */
#define LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF      SYSCFG_CFGR1_TIM2ITR1_REMAP_1  /*!< TIM2ITR1 remaps to USB2_SOF */
#define LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR  SYSCFG_CFGR1_TIM2ITR1_REMAP    /*!< TIM2ITR1 remaps to ETH_PTP_INTR */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_CTC_SOF_FROM SYSCFG CTC SOF FROM
  * @{
  */
#define LL_SYSCFG_CTC_SOF_FROM_USB1    0x00000000U              /*!< USB SOF for configuring CTC comes from USB1 */
#define LL_SYSCFG_CTC_SOF_FROM_USB2    SYSCFG_CFGR1_CTC_SOF_SEL /*!< USB SOF for configuring CTC comes from USB2 */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_I2C_FASTMODEPLUS SYSCFG I2C FASTMODEPLUS
  * @{
  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C1    SYSCFG_CFGR1_I2C1_FMP /*!< Enable I2C1 Fast mode Plus  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C2    SYSCFG_CFGR1_I2C2_FMP /*!< Enable I2C2 Fast mode plus  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C3    SYSCFG_CFGR1_I2C3_FMP /*!< Enable I2C3 Fast mode Plus  */
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C4    SYSCFG_CFGR1_I2C4_FMP /*!< Enable I2C4 Fast mode plus  */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIMBREAK TIMER BREAK INPUT
  * @{
  */
#if defined(SYSCFG_CFGR2_CLL)
#define LL_SYSCFG_TIMBREAK_LOCKUP       SYSCFG_CFGR2_CLL
#endif
#if defined(SYSCFG_CFGR2_SPL)
#define LL_SYSCFG_TIMBREAK_SRAM_PARITY  SYSCFG_CFGR2_SPL
#endif
#if defined(SYSCFG_CFGR2_PVDL)
#define LL_SYSCFG_TIMBREAK_PVD          SYSCFG_CFGR2_PVDL
#endif
#if defined(SYSCFG_CFGR2_ECCL)
#define LL_SYSCFG_TIMBREAK_ECC          SYSCFG_CFGR2_ECCL
#endif
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_EXTI_PORT EXTI PORT
  * @{
  */
#define LL_SYSCFG_EXTI_PORTA            0U   /*!< EXTI PORT A */
#define LL_SYSCFG_EXTI_PORTB            1U   /*!< EXTI PORT B */
#define LL_SYSCFG_EXTI_PORTC            2U   /*!< EXTI PORT C */
#define LL_SYSCFG_EXTI_PORTD            3U   /*!< EXTI PORT D */
#define LL_SYSCFG_EXTI_PORTE            4U   /*!< EXTI PORT E */
#define LL_SYSCFG_EXTI_PORTF            5U   /*!< EXTI PORT F */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_EXTI_LINE EXTI LINE
  * @{
  */
#define LL_SYSCFG_EXTI_LINE0            (0x000FU << 16U | 0U)  /*!< EXTI_POSITION_0  | EXTICR[0] */
#define LL_SYSCFG_EXTI_LINE1            (0x00F0U << 16U | 0U)  /*!< EXTI_POSITION_4  | EXTICR[0] */
#define LL_SYSCFG_EXTI_LINE2            (0x0F00U << 16U | 0U)  /*!< EXTI_POSITION_8  | EXTICR[0] */
#define LL_SYSCFG_EXTI_LINE3            (0xF000U << 16U | 0U)  /*!< EXTI_POSITION_12 | EXTICR[0] */
#define LL_SYSCFG_EXTI_LINE4            (0x000FU << 16U | 1U)  /*!< EXTI_POSITION_0  | EXTICR[1] */
#define LL_SYSCFG_EXTI_LINE5            (0x00F0U << 16U | 1U)  /*!< EXTI_POSITION_4  | EXTICR[1] */
#define LL_SYSCFG_EXTI_LINE6            (0x0F00U << 16U | 1U)  /*!< EXTI_POSITION_8  | EXTICR[1] */
#define LL_SYSCFG_EXTI_LINE7            (0xF000U << 16U | 1U)  /*!< EXTI_POSITION_12 | EXTICR[1] */
#define LL_SYSCFG_EXTI_LINE8            (0x000FU << 16U | 2U)  /*!< EXTI_POSITION_0  | EXTICR[2] */
#define LL_SYSCFG_EXTI_LINE9            (0x00F0U << 16U | 2U)  /*!< EXTI_POSITION_4  | EXTICR[2] */
#define LL_SYSCFG_EXTI_LINE10           (0x0F00U << 16U | 2U)  /*!< EXTI_POSITION_8  | EXTICR[2] */
#define LL_SYSCFG_EXTI_LINE11           (0xF000U << 16U | 2U)  /*!< EXTI_POSITION_12 | EXTICR[2] */
#define LL_SYSCFG_EXTI_LINE12           (0x000FU << 16U | 3U)  /*!< EXTI_POSITION_0  | EXTICR[3] */
#define LL_SYSCFG_EXTI_LINE13           (0x00F0U << 16U | 3U)  /*!< EXTI_POSITION_4  | EXTICR[3] */
#define LL_SYSCFG_EXTI_LINE14           (0x0F00U << 16U | 3U)  /*!< EXTI_POSITION_8  | EXTICR[3] */
#define LL_SYSCFG_EXTI_LINE15           (0xF000U << 16U | 3U)  /*!< EXTI_POSITION_12 | EXTICR[3] */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_GPIO_PORT GPIO PORT
  * @{
  */
#define LL_SYSCFG_GPIO_PORTA              0x00000000U
#define LL_SYSCFG_GPIO_PORTB              0x00000001U
#define LL_SYSCFG_GPIO_PORTC              0x00000002U
#define LL_SYSCFG_GPIO_PORTD              0x00000003U
#define LL_SYSCFG_GPIO_PORTE              0x00000004U
#define LL_SYSCFG_GPIO_PORTF              0x00000005U
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_EC_GPIO_PIN GPIO PIN
  * @{
  */
#define LL_SYSCFG_GPIO_PIN_0              0x00000001U
#define LL_SYSCFG_GPIO_PIN_1              0x00000002U
#define LL_SYSCFG_GPIO_PIN_2              0x00000004U
#define LL_SYSCFG_GPIO_PIN_3              0x00000008U
#define LL_SYSCFG_GPIO_PIN_4              0x00000010U
#define LL_SYSCFG_GPIO_PIN_5              0x00000020U
#define LL_SYSCFG_GPIO_PIN_6              0x00000040U
#define LL_SYSCFG_GPIO_PIN_7              0x00000080U
#define LL_SYSCFG_GPIO_PIN_8              0x00000100U
#define LL_SYSCFG_GPIO_PIN_9              0x00000200U
#define LL_SYSCFG_GPIO_PIN_10             0x00000400U
#define LL_SYSCFG_GPIO_PIN_11             0x00000800U
#define LL_SYSCFG_GPIO_PIN_12             0x00001000U
#define LL_SYSCFG_GPIO_PIN_13             0x00002000U
#define LL_SYSCFG_GPIO_PIN_14             0x00004000U
#define LL_SYSCFG_GPIO_PIN_15             0x00008000U
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_GPIO_ANA2 GPIO Enable Analog2 Mode
  * @{
  */
#define LL_SYSCFG_GPIOA_PIN_0                    SYSCFG_PAANA2ENR_PA0_ENA2
#define LL_SYSCFG_GPIOA_PIN_1                    SYSCFG_PAANA2ENR_PA1_ENA2
#define LL_SYSCFG_GPIOA_PIN_2                    SYSCFG_PAANA2ENR_PA2_ENA2
#define LL_SYSCFG_GPIOA_PIN_3                    SYSCFG_PAANA2ENR_PA3_ENA2
#define LL_SYSCFG_GPIOA_PIN_4                    SYSCFG_PAANA2ENR_PA4_ENA2
#define LL_SYSCFG_GPIOA_PIN_5                    SYSCFG_PAANA2ENR_PA5_ENA2
#define LL_SYSCFG_GPIOA_PIN_7                    SYSCFG_PAANA2ENR_PA7_ENA2
#define LL_SYSCFG_GPIOA_PIN_10                   SYSCFG_PAANA2ENR_PA10_ENA2

#define LL_SYSCFG_GPIOB_PIN_0                    SYSCFG_PBANA2ENR_PB0_ENA2
#define LL_SYSCFG_GPIOB_PIN_1                    SYSCFG_PBANA2ENR_PB1_ENA2
#define LL_SYSCFG_GPIOB_PIN_2                    SYSCFG_PBANA2ENR_PB2_ENA2

#define LL_SYSCFG_GPIOC_PIN_0                    SYSCFG_PCANA2ENR_PC0_ENA2
#define LL_SYSCFG_GPIOC_PIN_1                    SYSCFG_PCANA2ENR_PC1_ENA2
#define LL_SYSCFG_GPIOC_PIN_2                    SYSCFG_PCANA2ENR_PC2_ENA2
#define LL_SYSCFG_GPIOC_PIN_3                    SYSCFG_PCANA2ENR_PC3_ENA2
#define LL_SYSCFG_GPIOC_PIN_14                   SYSCFG_PCANA2ENR_PC14_ENA2
#define LL_SYSCFG_GPIOC_PIN_15                   SYSCFG_PCANA2ENR_PC15_ENA2

#define LL_SYSCFG_GPIOD_PIN_10                   SYSCFG_PDANA2ENR_PD10_ENA2
#define LL_SYSCFG_GPIOD_PIN_11                   SYSCFG_PDANA2ENR_PD11_ENA2
#define LL_SYSCFG_GPIOD_PIN_12                   SYSCFG_PDANA2ENR_PD12_ENA2
#define LL_SYSCFG_GPIOD_PIN_13                   SYSCFG_PDANA2ENR_PD13_ENA2

#define LL_SYSCFG_GPIOE_PIN_7                    SYSCFG_PEANA2ENR_PE7_ENA2
#define LL_SYSCFG_GPIOE_PIN_10                   SYSCFG_PEANA2ENR_PE10_ENA2
#define LL_SYSCFG_GPIOE_PIN_11                   SYSCFG_PEANA2ENR_PE11_ENA2
#define LL_SYSCFG_GPIOE_PIN_12                   SYSCFG_PEANA2ENR_PE12_ENA2
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_CCMSRAMWRP CCM Write protection
  * @{
  */
#define LL_SYSCFG_CCMSRAMWRP_PAGE0          SYSCFG_SWPR_P0WP  /*!< CCMSRAM Write protection page 0 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE1          SYSCFG_SWPR_P1WP  /*!< CCMSRAM Write protection page 1 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE2          SYSCFG_SWPR_P2WP  /*!< CCMSRAM Write protection page 2 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE3          SYSCFG_SWPR_P3WP  /*!< CCMSRAM Write protection page 3 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE4          SYSCFG_SWPR_P4WP  /*!< CCMSRAM Write protection page 4 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE5          SYSCFG_SWPR_P5WP  /*!< CCMSRAM Write protection page 5 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE6          SYSCFG_SWPR_P6WP  /*!< CCMSRAM Write protection page 6 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE7          SYSCFG_SWPR_P7WP  /*!< CCMSRAM Write protection page 7 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE8          SYSCFG_SWPR_P8WP  /*!< CCMSRAM Write protection page 8 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE9          SYSCFG_SWPR_P9WP  /*!< CCMSRAM Write protection page 9 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE10         SYSCFG_SWPR_P10WP /*!< CCMSRAM Write protection page 10 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE11         SYSCFG_SWPR_P11WP /*!< CCMSRAM Write protection page 11 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE12         SYSCFG_SWPR_P12WP /*!< CCMSRAM Write protection page 12 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE13         SYSCFG_SWPR_P13WP /*!< CCMSRAM Write protection page 13 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE14         SYSCFG_SWPR_P14WP /*!< CCMSRAM Write protection page 14 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE15         SYSCFG_SWPR_P15WP /*!< CCMSRAM Write protection page 15 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE16         SYSCFG_SWPR_P16WP /*!< CCMSRAM Write protection page 16 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE17         SYSCFG_SWPR_P17WP /*!< CCMSRAM Write protection page 17 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE18         SYSCFG_SWPR_P18WP /*!< CCMSRAM Write protection page 18 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE19         SYSCFG_SWPR_P19WP /*!< CCMSRAM Write protection page 19 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE20         SYSCFG_SWPR_P20WP /*!< CCMSRAM Write protection page 20 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE21         SYSCFG_SWPR_P21WP /*!< CCMSRAM Write protection page 21 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE22         SYSCFG_SWPR_P22WP /*!< CCMSRAM Write protection page 22 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE23         SYSCFG_SWPR_P23WP /*!< CCMSRAM Write protection page 23 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE24         SYSCFG_SWPR_P24WP /*!< CCMSRAM Write protection page 24 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE25         SYSCFG_SWPR_P25WP /*!< CCMSRAM Write protection page 25 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE26         SYSCFG_SWPR_P26WP /*!< CCMSRAM Write protection page 26 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE27         SYSCFG_SWPR_P27WP /*!< CCMSRAM Write protection page 27 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE28         SYSCFG_SWPR_P28WP /*!< CCMSRAM Write protection page 28 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE29         SYSCFG_SWPR_P29WP /*!< CCMSRAM Write protection page 29 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE30         SYSCFG_SWPR_P30WP /*!< CCMSRAM Write protection page 30 */
#define LL_SYSCFG_CCMSRAMWRP_PAGE31         SYSCFG_SWPR_P31WP /*!< CCMSRAM Write protection page 31 */

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_LATENCY FLASH LATENCY
  * @{
  */
#define LL_FLASH_LATENCY_0                 0x00000000UL                                                        /*!< FLASH Zero wait state */
#define LL_FLASH_LATENCY_1                 FLASH_ACR_LATENCY_0                                                 /*!< FLASH One wait state */
#define LL_FLASH_LATENCY_3                 (FLASH_ACR_LATENCY_0 | FLASH_ACR_LATENCY_1)                         /*!< FLASH Three wait state */
#define LL_FLASH_LATENCY_4                 FLASH_ACR_LATENCY_2                                                 /*!< FLASH Four wait state */
#define LL_FLASH_LATENCY_5                 (FLASH_ACR_LATENCY_0 | FLASH_ACR_LATENCY_2)                         /*!< FLASH Five wait state */
#define LL_FLASH_LATENCY_6                 (FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_2)                         /*!< FLASH Six wait state */
#define LL_FLASH_LATENCY_7                 (FLASH_ACR_LATENCY_0 | FLASH_ACR_LATENCY_1 | FLASH_ACR_LATENCY_2)   /*!< FLASH Seven wait state */
/**
  * @}
  */
  
/** @defgroup SYSTEM_LL_EC_STOP_IP  DBGMCU STOP IP
  * @{
  */
#if defined(DBGMCU_CR1_DBG_IWDG_STOP)
#define LL_DBGMCU_IWDG_STOP                  DBGMCU_CR1_DBG_IWDG_STOP
#endif

#if defined(DBGMCU_CR1_DBG_WWDG_STOP)
#define LL_DBGMCU_WWDG_STOP                  DBGMCU_CR1_DBG_WWDG_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM1_STOP)
#define LL_DBGMCU_TIM1_STOP                  DBGMCU_CR1_DBG_TIM1_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM2_STOP)
#define LL_DBGMCU_TIM2_STOP                  DBGMCU_CR1_DBG_TIM2_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM3_STOP)
#define LL_DBGMCU_TIM3_STOP                  DBGMCU_CR1_DBG_TIM3_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM4_STOP)
#define LL_DBGMCU_TIM4_STOP                  DBGMCU_CR1_DBG_TIM4_STOP
#endif

#if defined(DBGMCU_CR1_DBG_CAN1_STOP)
#define LL_DBGMCU_CAN1_STOP                  DBGMCU_CR1_DBG_CAN1_STOP
#endif

#if defined(DBGMCU_CR1_DBG_I2C1_SMBUS_TIMEOUT)
#define LL_DBGMCU_I2C1_SMBUS_TIMEOUT         DBGMCU_CR1_DBG_I2C1_SMBUS_TIMEOUT
#endif

#if defined(DBGMCU_CR1_DBG_I2C2_SMBUS_TIMEOUT)
#define LL_DBGMCU_I2C2_SMBUS_TIMEOUT         DBGMCU_CR1_DBG_I2C2_SMBUS_TIMEOUT
#endif

#if defined(DBGMCU_CR1_DBG_TIM5_STOP)
#define LL_DBGMCU_TIM5_STOP                  DBGMCU_CR1_DBG_TIM5_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM6_STOP)
#define LL_DBGMCU_TIM6_STOP                  DBGMCU_CR1_DBG_TIM6_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM7_STOP)
#define LL_DBGMCU_TIM7_STOP                  DBGMCU_CR1_DBG_TIM7_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM8_STOP)
#define LL_DBGMCU_TIM8_STOP                  DBGMCU_CR1_DBG_TIM8_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM9_STOP)
#define LL_DBGMCU_TIM9_STOP                  DBGMCU_CR1_DBG_TIM9_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM10_STOP)
#define LL_DBGMCU_TIM10_STOP                 DBGMCU_CR1_DBG_TIM10_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM11_STOP)
#define LL_DBGMCU_TIM11_STOP                 DBGMCU_CR1_DBG_TIM11_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM12_STOP)
#define LL_DBGMCU_TIM12_STOP                 DBGMCU_CR1_DBG_TIM12_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM13_STOP)
#define LL_DBGMCU_TIM13_STOP                 DBGMCU_CR1_DBG_TIM13_STOP
#endif

#if defined(DBGMCU_CR1_DBG_TIM14_STOP)
#define LL_DBGMCU_TIM14_STOP                 DBGMCU_CR1_DBG_TIM14_STOP
#endif

#if defined(DBGMCU_CR2_DBG_I2C3_SMBUS_TIMEOUT)
#define LL_DBGMCU_I2C3_SMBUS_TIMEOUT         DBGMCU_CR2_DBG_I2C3_SMBUS_TIMEOUT
#endif

#if defined(DBGMCU_CR2_DBG_I2C4_SMBUS_TIMEOUT)
#define LL_DBGMCU_I2C4_SMBUS_TIMEOUT         DBGMCU_CR2_DBG_I2C4_SMBUS_TIMEOUT
#endif

#if defined(DBGMCU_CR2_DBG_CAN2_STOP)
#define LL_DBGMCU_CAN2_STOP                  DBGMCU_CR2_DBG_CAN2_STOP
#endif

#if defined(DBGMCU_CR2_DBG_TIM15_STOP)
#define LL_DBGMCU_TIM15_STOP                 DBGMCU_CR2_DBG_TIM15_STOP
#endif

#if defined(DBGMCU_CR2_DBG_TIM16_STOP)
#define LL_DBGMCU_TIM16_STOP                 DBGMCU_CR2_DBG_TIM16_STOP
#endif

#if defined(DBGMCU_CR2_DBG_TIM17_STOP)
#define LL_DBGMCU_TIM17_STOP                 DBGMCU_CR2_DBG_TIM17_STOP
#endif

#if defined(DBGMCU_CR2_DBG_TIM18_STOP)
#define LL_DBGMCU_TIM18_STOP                 DBGMCU_CR2_DBG_TIM18_STOP
#endif

#if defined(DBGMCU_CR2_DBG_TIM19_STOP)
#define LL_DBGMCU_TIM19_STOP                 DBGMCU_CR2_DBG_TIM19_STOP
#endif

#if defined(DBGMCU_CR2_DBG_LPTIM_STOP)
#define LL_DBGMCU_LPTIM_STOP                 DBGMCU_CR2_DBG_LPTIM_STOP
#endif

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Functions SYSTEM Exported Functions
  * @{
  */

/** @defgroup SYSTEM_LL_EF_SYSCFG SYSCFG
  * @{
  */

/**
  * @brief  Set memory mapping at address 0x00000000
  * @rmtoll SYSCFG_CFGR1 MEM_MODE      LL_SYSCFG_SetRemapMemory
  * @param  Memory This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_REMAP_FLASH
  *         @arg @ref LL_SYSCFG_REMAP_SYSTEMFLASH
  *         @arg @ref LL_SYSCFG_REMAP_ESMC
  *         @arg @ref LL_SYSCFG_REMAP_SRAM
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetRemapMemory(uint32_t Memory)
{
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_MEM_MODE, Memory);
}

/**
  * @brief  Get memory mapping at address 0x00000000
  * @rmtoll SYSCFG_CFGR1 MEM_MODE      LL_SYSCFG_GetRemapMemory
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_REMAP_FLASH
  *         @arg @ref LL_SYSCFG_REMAP_SYSTEMFLASH
  *         @arg @ref LL_SYSCFG_REMAP_ESMC
  *         @arg @ref LL_SYSCFG_REMAP_SRAM
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetRemapMemory(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_MEM_MODE));
}

/**
  * @brief  Set Ethernet physical interface.
  * @rmtoll SYSCFG_CFGR1 ETH_PHYSEL      LL_SYSCFG_SetETHPhysicalInterface
  * @param  Interface This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_ETH_PHY_MII
  *         @arg @ref LL_SYSCFG_ETH_PHY_RMII
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetETHPhysicalInterface(uint32_t Interface)
{
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_ETH_PHYSEL, Interface);
}

/**
  * @brief  Get Ethernet physical interface.
  * @rmtoll SYSCFG_CFGR1 ETH_PHYSEL      LL_SYSCFG_GetETHPhysicalInterface
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_ETH_PHY_MII
  *         @arg @ref LL_SYSCFG_ETH_PHY_RMII
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetETHPhysicalInterface(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_ETH_PHYSEL));
}

/**
  * @brief  Set remap TIM2 internal trigger1
  * @rmtoll SYSCFG_CFGR1 TIM2ITR1_REMAP      LL_SYSCFG_SetRemapTIM2InternalTrigger1
  * @param  TIM2IneternalTrigger1 This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_NONE
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetRemapTIM2InternalTrigger1(uint32_t TIM2IneternalTrigger1)
{
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_TIM2ITR1_REMAP, TIM2IneternalTrigger1);
}

/**
  * @brief  Get remapping of TIM2 internal trigger1
  * @rmtoll SYSCFG_CFGR1 TIM2ITR1_REMAP      LL_SYSCFG_GetRemapTIM2InternalTrigger1
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_NONE
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF
  *         @arg @ref LL_SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetRemapTIM2InternalTrigger1(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_TIM2ITR1_REMAP));
}

/**
  * @brief  Enable the remapping of ETH_PTP_PPS.
  * @rmtoll SYSCFG_CFGR1 PTP_PPS_REMAP        LL_SYSCFG_EnableEthernetPtpPpsRemap
  * @note  ENABLE: PTP_PPS is output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableEthernetPtpPpsRemap(void)
{
  SET_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_PTP_PPS_REMAP);
}

/**
  * @brief  Disable the remapping of ETH_PTP_PPS.
  * @rmtoll SYSCFG_CFGR1 PTP_PPS_REMAP        LL_SYSCFG_DisableEthernetPtpPpsRemap
  * @note  DISABLE: PTP_PPS not output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableEthernetPtpPpsRemap(void)
{
  CLEAR_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_PTP_PPS_REMAP);
}

/**
  * @brief  Indicate if enable the remapping of ETH_PTP_PPS.
  * @rmtoll SYSCFG_CFGR1 PTP_PPS_REMAP        LL_SYSCFG_IsEnabledEthernetPtpPpsRemap
  * @note  PTP_PPS output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledEthernetPtpPpsRemap(void)
{
  return ((READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_PTP_PPS_REMAP) == (SYSCFG_CFGR1_PTP_PPS_REMAP)) ? 1UL : 0UL);
}

/**
  * @brief  Set USB SOF for configuring CTC comes from.
  * @rmtoll SYSCFG_CFGR1 CTC_SOF_SEL      LL_SYSCFG_SetCtcUsbsof
  * @param  Usbsof This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_CTC_SOF_FROM_USB1
  *         @arg @ref LL_SYSCFG_CTC_SOF_FROM_USB2
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetCtcUsbsof(uint32_t Usbsof)
{
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_CTC_SOF_SEL, Usbsof);
}

/**
  * @brief  Get USB SOF for configuring CTC comes from.
  * @rmtoll SYSCFG_CFGR1 CTC_SOF_SEL      LL_SYSCFG_GetCtcUsbsof
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_CTC_SOF_FROM_USB1
  *         @arg @ref LL_SYSCFG_CTC_SOF_FROM_USB2
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetCtcUsbsof(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_CTC_SOF_SEL));
}

/**
  * @brief  Enable the I2C fast mode plus driving capability.
  * @rmtoll SYSCFG_CFGR1 I2C_FMP_I2C1  LL_SYSCFG_EnableFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C2  LL_SYSCFG_EnableFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C3  LL_SYSCFG_EnableFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C4  LL_SYSCFG_EnableFastModePlus
  * @param  ConfigFastModePlus This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C1
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C2
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C3
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C4
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableFastModePlus(uint32_t ConfigFastModePlus)
{
  SET_BIT(SYSCFG->CFGR[0], ConfigFastModePlus);
}

/**
  * @brief  Disable the I2C fast mode plus driving capability.
  * @rmtoll SYSCFG_CFGR1 I2C_FMP_I2C1  LL_SYSCFG_DisableFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C2  LL_SYSCFG_DisableFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C3  LL_SYSCFG_DisableFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C4  LL_SYSCFG_DisableFastModePlus
  * @param  ConfigFastModePlus This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C1
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C2
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C3
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C4
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableFastModePlus(uint32_t ConfigFastModePlus)
{
  CLEAR_BIT(SYSCFG->CFGR[0], ConfigFastModePlus);
}

/**
  * @brief  Indicate if enable the I2C fast mode plus driving capability.
  * @rmtoll SYSCFG_CFGR1 I2C_FMP_I2C1  LL_SYSCFG_IsEnabledFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C2  LL_SYSCFG_IsEnabledFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C3  LL_SYSCFG_IsEnabledFastModePlus\n
  *         SYSCFG_CFGR1 I2C_FMP_I2C4  LL_SYSCFG_IsEnabledFastModePlus
  * @param  ConfigFastModePlus This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C1
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C2
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C3
  *         @arg @ref LL_SYSCFG_I2C_FASTMODEPLUS_I2C4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledFastModePlus(uint32_t ConfigFastModePlus)
{
  return ((READ_BIT(SYSCFG->CFGR[0], ConfigFastModePlus) == (ConfigFastModePlus)) ? 1UL : 0UL);
}

/**
  * @brief  Enable analog filter of I2C related IO
  * @rmtoll SYSCFG_CFGR1 I2C_EIIC  LL_SYSCFG_EnableI2CAnalogFilter\n
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA13
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA14
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA15
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB5
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB7
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC3
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC6
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC7
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC11
  *         @arg @ref LL_SYSCFG_I2C_ANF_PF0
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  SET_BIT(SYSCFG->CFGR[0],I2CAnalogFilter);
}

/**
  * @brief  Disable analog filter of I2C related IO
  * @rmtoll SYSCFG_CFGR1 I2C_EIIC  LL_SYSCFG_DisableI2CAnalogFilter\n
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA13
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA14
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA15
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB5
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB7
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC3
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC6
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC7
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC11
  *         @arg @ref LL_SYSCFG_I2C_ANF_PF0
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  CLEAR_BIT(SYSCFG->CFGR[0],I2CAnalogFilter);
}

/**
  * @brief  Indicate if enable the analog filter of I2C related IO.
  * @rmtoll SYSCFG_CFGR1 I2C_EIIC  LL_SYSCFG_IsEnabledI2CAnalogFilter\n
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA13
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA14
  *         @arg @ref LL_SYSCFG_I2C_ANF_PA15
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB5
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB7
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PB9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC3
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC6
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC7
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC8
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC9
  *         @arg @ref LL_SYSCFG_I2C_ANF_PC11
  *         @arg @ref LL_SYSCFG_I2C_ANF_PF0
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  return ((READ_BIT(SYSCFG->CFGR[0], I2CAnalogFilter) == (I2CAnalogFilter)) ? 1UL : 0UL);
}

/**
  * @brief  Set connections to TIM1/8/15/16/17 Break inputs
  * @rmtoll SYSCFG_CFGR2 CLL           LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 SPL           LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 PVDL          LL_SYSCFG_SetTIMBreakInputs\n
  *         SYSCFG_CFGR2 ECCL          LL_SYSCFG_SetTIMBreakInputs
  * @param  Break This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_TIMBREAK_LOCKUP
  *         @arg @ref LL_SYSCFG_TIMBREAK_SRAM_PARITY
  *         @arg @ref LL_SYSCFG_TIMBREAK_PVD
  *         @arg @ref LL_SYSCFG_TIMBREAK_ECC
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetTIMBreakInputs(uint32_t Break)
{
  MODIFY_REG(SYSCFG->CFGR[1], SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL, Break);
}

/**
  * @brief  Get connections to TIM1/8/15/16/17 Break inputs
  * @rmtoll SYSCFG_CFGR2 CLL           LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 SPL           LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 PVDL          LL_SYSCFG_GetTIMBreakInputs\n
  *         SYSCFG_CFGR2 ECCL          LL_SYSCFG_GetTIMBreakInputs
  * @retval Returned value can be can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_TIMBREAK_ECC
  *         @arg @ref LL_SYSCFG_TIMBREAK_PVD
  *         @arg @ref LL_SYSCFG_TIMBREAK_SRAM_PARITY
  *         @arg @ref LL_SYSCFG_TIMBREAK_LOCKUP
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetTIMBreakInputs(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL));
}

/**
  * @brief  Configure source input for the EXTI external interrupt.
  * @rmtoll SYSCFG_EXTICR1 EXTIx         LL_SYSCFG_SetEXTISource\n
  *         SYSCFG_EXTICR2 EXTIx         LL_SYSCFG_SetEXTISource\n
  *         SYSCFG_EXTICR3 EXTIx         LL_SYSCFG_SetEXTISource\n
  *         SYSCFG_EXTICR4 EXTIx         LL_SYSCFG_SetEXTISource
  * @param  Port This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_EXTI_PORTA
  *         @arg @ref LL_SYSCFG_EXTI_PORTB
  *         @arg @ref LL_SYSCFG_EXTI_PORTC
  *         @arg @ref LL_SYSCFG_EXTI_PORTD
  *         @arg @ref LL_SYSCFG_EXTI_PORTE
  *         @arg @ref LL_SYSCFG_EXTI_PORTF
  * @param  Line This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_EXTI_LINE0 
  *         @arg @ref LL_SYSCFG_EXTI_LINE1 
  *         @arg @ref LL_SYSCFG_EXTI_LINE2 
  *         @arg @ref LL_SYSCFG_EXTI_LINE3 
  *         @arg @ref LL_SYSCFG_EXTI_LINE4 
  *         @arg @ref LL_SYSCFG_EXTI_LINE5 
  *         @arg @ref LL_SYSCFG_EXTI_LINE6 
  *         @arg @ref LL_SYSCFG_EXTI_LINE7 
  *         @arg @ref LL_SYSCFG_EXTI_LINE8 
  *         @arg @ref LL_SYSCFG_EXTI_LINE9 
  *         @arg @ref LL_SYSCFG_EXTI_LINE10
  *         @arg @ref LL_SYSCFG_EXTI_LINE11
  *         @arg @ref LL_SYSCFG_EXTI_LINE12
  *         @arg @ref LL_SYSCFG_EXTI_LINE13
  *         @arg @ref LL_SYSCFG_EXTI_LINE14
  *         @arg @ref LL_SYSCFG_EXTI_LINE15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_SetEXTISource(uint32_t Port, uint32_t Line)
{
  MODIFY_REG(SYSCFG->EXTICR[Line & 0xFF], (Line >> 16), Port << POSITION_VAL((Line >> 16)));
}

/**
  * @brief  Get the configured defined for specific EXTI Line
  * @rmtoll SYSCFG_EXTICR1 EXTIx         LL_SYSCFG_GetEXTISource\n
  *         SYSCFG_EXTICR2 EXTIx         LL_SYSCFG_GetEXTISource\n
  *         SYSCFG_EXTICR3 EXTIx         LL_SYSCFG_GetEXTISource\n
  *         SYSCFG_EXTICR4 EXTIx         LL_SYSCFG_GetEXTISource
  * @param  Line This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_EXTI_LINE0 
  *         @arg @ref LL_SYSCFG_EXTI_LINE1 
  *         @arg @ref LL_SYSCFG_EXTI_LINE2 
  *         @arg @ref LL_SYSCFG_EXTI_LINE3 
  *         @arg @ref LL_SYSCFG_EXTI_LINE4 
  *         @arg @ref LL_SYSCFG_EXTI_LINE5 
  *         @arg @ref LL_SYSCFG_EXTI_LINE6 
  *         @arg @ref LL_SYSCFG_EXTI_LINE7 
  *         @arg @ref LL_SYSCFG_EXTI_LINE8 
  *         @arg @ref LL_SYSCFG_EXTI_LINE9 
  *         @arg @ref LL_SYSCFG_EXTI_LINE10
  *         @arg @ref LL_SYSCFG_EXTI_LINE11
  *         @arg @ref LL_SYSCFG_EXTI_LINE12
  *         @arg @ref LL_SYSCFG_EXTI_LINE13
  *         @arg @ref LL_SYSCFG_EXTI_LINE14
  *         @arg @ref LL_SYSCFG_EXTI_LINE15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SYSCFG_EXTI_PORTA
  *         @arg @ref LL_SYSCFG_EXTI_PORTB
  *         @arg @ref LL_SYSCFG_EXTI_PORTC
  *         @arg @ref LL_SYSCFG_EXTI_PORTD
  *         @arg @ref LL_SYSCFG_EXTI_PORTE
  *         @arg @ref LL_SYSCFG_EXTI_PORTF
  */
__STATIC_INLINE uint32_t LL_SYSCFG_GetEXTISource(uint32_t Line)
{
  return (uint32_t)(READ_BIT(SYSCFG->EXTICR[Line & 0xFF], (Line >> 16)) >> POSITION_VAL(Line >> 16));
}

/**
  * @brief  Enable GPIO Filter
  * @rmtoll SYSCFG_PAENS PA_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PBENS PB_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PCENS PC_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PDENS PD_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PEENS PE_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PFENS PF_ENS         LL_SYSCFG_EnableGPIOFilter
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  *         @arg @ref LL_SYSCFG_GPIO_PORTE
  *         @arg @ref LL_SYSCFG_GPIO_PORTF
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOFilter(uint32_t GPIOPort, uint32_t GPIOPin)
{
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    SET_BIT(SYSCFG->PAENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    SET_BIT(SYSCFG->PBENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {
    SET_BIT(SYSCFG->PCENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {
    SET_BIT(SYSCFG->PDENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTE)
  {
    SET_BIT(SYSCFG->PEENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTF)
  {
    SET_BIT(SYSCFG->PFENS, GPIOPin);
  }
  else
  {
    
  }
}

/**
  * @brief  Disable GPIO Filter
  * @rmtoll SYSCFG_PAENS PA_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PBENS PB_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PCENS PC_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PDENS PD_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PEENS PE_ENS         LL_SYSCFG_EnableGPIOFilter\n
  *         SYSCFG_PFENS PF_ENS         LL_SYSCFG_EnableGPIOFilter
  * @param  GPIOPort This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PORTA
  *         @arg @ref LL_SYSCFG_GPIO_PORTB
  *         @arg @ref LL_SYSCFG_GPIO_PORTC
  *         @arg @ref LL_SYSCFG_GPIO_PORTD
  *         @arg @ref LL_SYSCFG_GPIO_PORTE
  *         @arg @ref LL_SYSCFG_GPIO_PORTF
  * @param  GPIOPin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIO_PIN_0
  *         @arg @ref LL_SYSCFG_GPIO_PIN_1
  *         @arg @ref LL_SYSCFG_GPIO_PIN_2
  *         @arg @ref LL_SYSCFG_GPIO_PIN_3
  *         @arg @ref LL_SYSCFG_GPIO_PIN_4
  *         @arg @ref LL_SYSCFG_GPIO_PIN_5
  *         @arg @ref LL_SYSCFG_GPIO_PIN_6
  *         @arg @ref LL_SYSCFG_GPIO_PIN_7
  *         @arg @ref LL_SYSCFG_GPIO_PIN_8
  *         @arg @ref LL_SYSCFG_GPIO_PIN_9
  *         @arg @ref LL_SYSCFG_GPIO_PIN_10
  *         @arg @ref LL_SYSCFG_GPIO_PIN_11
  *         @arg @ref LL_SYSCFG_GPIO_PIN_12
  *         @arg @ref LL_SYSCFG_GPIO_PIN_13
  *         @arg @ref LL_SYSCFG_GPIO_PIN_14
  *         @arg @ref LL_SYSCFG_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOFilter(uint32_t GPIOPort, uint32_t GPIOPin)
{
  if(GPIOPort == LL_SYSCFG_GPIO_PORTA)
  {
    CLEAR_BIT(SYSCFG->PAENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTB)
  {
    CLEAR_BIT(SYSCFG->PBENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTC)
  {
    CLEAR_BIT(SYSCFG->PCENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTD)
  {
    CLEAR_BIT(SYSCFG->PDENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTE)
  {
    CLEAR_BIT(SYSCFG->PEENS, GPIOPin);
  }
  else if(GPIOPort == LL_SYSCFG_GPIO_PORTF)
  {
    CLEAR_BIT(SYSCFG->PFENS, GPIOPin);
  }
  else
  {
    
  }
}

/**
  * @brief  Enable GPIOA Analog2
  * @rmtoll SYSCFG_PA_ANA2ENR PA0_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA1_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA2_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA3_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA4_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA5_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA7_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA10_ENA2        LL_SYSCFG_EnableGPIOAAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_0
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_1
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_2
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_3
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_4
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_5
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_7
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_10
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOAAnalog2(uint32_t GPIOx_Pin)
{
  SET_BIT(SYSCFG->PAANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Disable GPIOA Analog2
  * @rmtoll SYSCFG_PA_ANA2ENR PA0_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA1_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA2_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA3_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA4_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA5_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA7_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA10_ENA2        LL_SYSCFG_EnableGPIOAAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_0
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_1
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_2
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_3
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_4
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_5
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_7
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_10
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOAAnalog2(uint32_t GPIOx_Pin)
{
  CLEAR_BIT(SYSCFG->PAANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Indicate if enable the GPIO State in GPIOA Analog2
  * @rmtoll SYSCFG_PA_ANA2ENR PA0_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA1_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA2_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA3_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA4_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA5_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA7_ENA2         LL_SYSCFG_EnableGPIOAAnalog2\n
  * @rmtoll SYSCFG_PA_ANA2ENR PA10_ENA2        LL_SYSCFG_EnableGPIOAAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_0
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_1
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_2
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_3
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_4
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_5
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_7
  *         @arg @ref LL_SYSCFG_GPIOA_PIN_10
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOAAnalog2(uint32_t GPIOx_Pin)
{
  return ((READ_BIT(SYSCFG->PAANA2ENR, GPIOx_Pin) == (GPIOx_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIOB Analog2
  * @rmtoll SYSCFG_PB_ANA2ENR PB0_ENA2         LL_SYSCFG_EnableGPIOBAnalog2\n
  * @rmtoll SYSCFG_PB_ANA2ENR PB1_ENA2         LL_SYSCFG_EnableGPIOBAnalog2\n
  * @rmtoll SYSCFG_PB_ANA2ENR PB2_ENA2         LL_SYSCFG_EnableGPIOBAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_0
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_1
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_2
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOBAnalog2(uint32_t GPIOx_Pin)
{
  SET_BIT(SYSCFG->PBANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Disable GPIOB Analog2
  * @rmtoll SYSCFG_PB_ANA2ENR PB0_ENA2         LL_SYSCFG_EnableGPIOBAnalog2\n
  * @rmtoll SYSCFG_PB_ANA2ENR PB1_ENA2         LL_SYSCFG_EnableGPIOBAnalog2\n
  * @rmtoll SYSCFG_PB_ANA2ENR PB2_ENA2         LL_SYSCFG_EnableGPIOBAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_0
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_1
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_2
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOBAnalog2(uint32_t GPIOx_Pin)
{
  CLEAR_BIT(SYSCFG->PBANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Indicate if enable the GPIO State in GPIOB Analog2
  * @rmtoll SYSCFG_PB_ANA2ENR PB0_ENA2         LL_SYSCFG_EnableGPIOBAnalog2\n
  * @rmtoll SYSCFG_PB_ANA2ENR PB1_ENA2         LL_SYSCFG_EnableGPIOBAnalog2\n
  * @rmtoll SYSCFG_PB_ANA2ENR PB2_ENA2         LL_SYSCFG_EnableGPIOBAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_0
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_1
  *         @arg @ref LL_SYSCFG_GPIOB_PIN_2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOBAnalog2(uint32_t GPIOx_Pin)
{
  return ((READ_BIT(SYSCFG->PBANA2ENR, GPIOx_Pin) == (GPIOx_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIOC Analog2
  * @rmtoll SYSCFG_PC_ANA2ENR PC0_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC1_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC2_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC3_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC14_ENA2        LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC15_ENA2        LL_SYSCFG_EnableGPIOCAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_0 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_1 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_2 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_3 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_14
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOCAnalog2(uint32_t GPIOx_Pin)
{
  SET_BIT(SYSCFG->PCANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Disable GPIOC Analog2
  * @rmtoll SYSCFG_PC_ANA2ENR PC0_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC1_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC2_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC3_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC14_ENA2        LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC15_ENA2        LL_SYSCFG_EnableGPIOCAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_0 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_1 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_2 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_3 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_14
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_15
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOCAnalog2(uint32_t GPIOx_Pin)
{
  CLEAR_BIT(SYSCFG->PCANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Indicate if enable the GPIO State in GPIOC Analog2
  * @rmtoll SYSCFG_PC_ANA2ENR PC0_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC1_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC2_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC3_ENA2         LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC14_ENA2        LL_SYSCFG_EnableGPIOCAnalog2\n
  * @rmtoll SYSCFG_PC_ANA2ENR PC15_ENA2        LL_SYSCFG_EnableGPIOCAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_0 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_1 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_2 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_3 
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_14
  *         @arg @ref LL_SYSCFG_GPIOC_PIN_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOCAnalog2(uint32_t GPIOx_Pin)
{
  return ((READ_BIT(SYSCFG->PCANA2ENR, GPIOx_Pin) == (GPIOx_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIOD Analog2
  * @rmtoll SYSCFG_PD_ANA2ENR PD10_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD11_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD12_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD13_ENA2         LL_SYSCFG_EnableGPIODAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_10 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_11 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_12 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_13 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIODAnalog2(uint32_t GPIOx_Pin)
{
  SET_BIT(SYSCFG->PDANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Disable GPIOD Analog2
  * @rmtoll SYSCFG_PD_ANA2ENR PD10_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD11_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD12_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD13_ENA2         LL_SYSCFG_EnableGPIODAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_10 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_11 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_12 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_13 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIODAnalog2(uint32_t GPIOx_Pin)
{
  CLEAR_BIT(SYSCFG->PDANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Indicate if enable the GPIO State in GPIOD Analog2
  * @rmtoll SYSCFG_PD_ANA2ENR PD10_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD11_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD12_ENA2         LL_SYSCFG_EnableGPIODAnalog2\n
  * @rmtoll SYSCFG_PD_ANA2ENR PD13_ENA2         LL_SYSCFG_EnableGPIODAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_10 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_11 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_12 
  *         @arg @ref LL_SYSCFG_GPIOD_PIN_13 
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIODAnalog2(uint32_t GPIOx_Pin)
{
  return ((READ_BIT(SYSCFG->PDANA2ENR, GPIOx_Pin) == (GPIOx_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable GPIOE Analog2
  * @rmtoll SYSCFG_PE_ANA2ENR PE7_ENA2          LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE10_ENA2         LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE11_ENA2         LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE12_ENA2         LL_SYSCFG_EnableGPIOEAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_7  
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_10 
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_11 
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_12 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableGPIOEAnalog2(uint32_t GPIOx_Pin)
{
  SET_BIT(SYSCFG->PEANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Disable GPIOE Analog2
  * @rmtoll SYSCFG_PE_ANA2ENR PE7_ENA2          LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE10_ENA2         LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE11_ENA2         LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE12_ENA2         LL_SYSCFG_EnableGPIOEAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_7  
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_10 
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_11 
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_12 
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisableGPIOEAnalog2(uint32_t GPIOx_Pin)
{
  CLEAR_BIT(SYSCFG->PEANA2ENR,GPIOx_Pin);
}

/**
  * @brief  Indicate if enable the GPIO State in GPIOE Analog2
  * @rmtoll SYSCFG_PE_ANA2ENR PE7_ENA2          LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE10_ENA2         LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE11_ENA2         LL_SYSCFG_EnableGPIOEAnalog2\n
  * @rmtoll SYSCFG_PE_ANA2ENR PE12_ENA2         LL_SYSCFG_EnableGPIOEAnalog2
  * @param  GPIOx_Pin This parameter can be a combination of the following values:
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_7  
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_10 
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_11 
  *         @arg @ref LL_SYSCFG_GPIOE_PIN_12 
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledGPIOEAnalog2(uint32_t GPIOx_Pin)
{
  return ((READ_BIT(SYSCFG->PEANA2ENR, GPIOx_Pin) == (GPIOx_Pin)) ? 1UL : 0UL);
}

/**
  * @brief  Enable PVD_IN Analog2
  * @rmtoll SYSCFG_PVDIN_ANA2ENR PVDIN_ENA2          LL_SYSCFG_EnablePVDINAnalog2\n
  * @param  None
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnablePVDINAnalog2(void)
{
  SET_BIT(SYSCFG->PVDINANA2ENR,SYSCFG_PVDINANA2ENR_PVDIN_ENA2);
}

/**
  * @brief  Disable PVD_IN Analog2
  * @rmtoll SYSCFG_PVDIN_ANA2ENR PVDIN_ENA2          LL_SYSCFG_EnablePVDINAnalog2\n
  * @param  None
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_DisablePVDINAnalog2(void)
{
  CLEAR_BIT(SYSCFG->PVDINANA2ENR,SYSCFG_PVDINANA2ENR_PVDIN_ENA2);
}

/**
  * @brief  Indicate if enable the PVDIN State in PVDIN Analog2
  * @rmtoll SYSCFG_PVDIN_ANA2ENR PVDIN_ENA2          LL_SYSCFG_EnablePVDINAnalog2\n
  * @param  None
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledPVDINAnalog2(void)
{
  return ((READ_BIT(SYSCFG->PVDINANA2ENR, SYSCFG_PVDINANA2ENR_PVDIN_ENA2) == (SYSCFG_PVDINANA2ENR_PVDIN_ENA2)) ? 1UL : 0UL);
}

/**
  * @brief  Enable CCMSRAM page write protection
  * @rmtoll SYSCFG_SWPR  PAGEx         LL_SYSCFG_EnableCCMSRAMPageWRP
  * @param  CCMSRAMWRP This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE0 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE1 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE2 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE3 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE4 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE5 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE6 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE7 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE8 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE9 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE10
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE11
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE12
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE13
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE14
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE15
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE16
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE17
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE18
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE19
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE20
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE21
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE22
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE23
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE24
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE25
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE26
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE27
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE28
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE29
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE30
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE31
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableCCMSRAMPageWRP(uint32_t CCMSRAMWRP)
{
  SET_BIT(SYSCFG->SWPR, CCMSRAMWRP);
}

/**
  * @brief  Indicate if enable the CCMSRAM page write protection
  * @rmtoll SYSCFG_SWPR  PAGEx         LL_SYSCFG_IsEnabledCCMSRAMPageWRP
  * @param  CCMSRAMWRP This parameter can be one of the following values:
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE0 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE1 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE2 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE3 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE4 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE5 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE6 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE7 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE8 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE9 
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE10
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE11
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE12
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE13
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE14
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE15
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE16
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE17
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE18
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE19
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE20
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE21
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE22
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE23
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE24
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE25
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE26
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE27
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE28
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE29
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE30
  *         @arg @ref LL_SYSCFG_CCMSRAMWRP_PAGE31
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledCCMSRAMPageWRP(uint32_t CCMSRAMWRP)
{
  return ((READ_BIT(SYSCFG->SWPR, CCMSRAMWRP) == (CCMSRAMWRP)) ? 1UL : 0UL);
}

/**
  * @brief  CCMSRAM page write protection lock prior to erase
  * @rmtoll SYSCFG_SKR   KEY           LL_SYSCFG_LockCCMSRAMWRP
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_LockCCMSRAMWRP(void)
{
  /* Writing a wrong key reactivates the write protection */
  WRITE_REG(SYSCFG->SKR, 0x00);
}

/**
  * @brief  CCMSRAM page write protection unlock prior to erase
  * @rmtoll SYSCFG_SKR   KEY           LL_SYSCFG_UnlockCCMSRAMWRP
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_UnlockCCMSRAMWRP(void)
{
  /* unlock the write protection of the CCMER bit */
  WRITE_REG(SYSCFG->SKR, 0xCA);
  WRITE_REG(SYSCFG->SKR, 0x53);
}

/**
  * @brief  Enable CCMSRAM Erase (starts a hardware CCMSRAM erase operation. This bit is
  * automatically cleared at the end of the CCMSRAM erase operation.)
  * @note This bit is write-protected: setting this bit is possible only after the
  *       correct key sequence is written in the SYSCFG_SKR register as described in
  *       the Reference Manual.
  * @rmtoll SYSCFG_SCSR  CCMER       LL_SYSCFG_EnableCCMSRAMErase
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_EnableCCMSRAMErase(void)
{
  /* Starts a hardware CCMSRAM erase operation*/
  SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_CCMER);
}

/**
  * @brief  Check if CCMSRAM erase operation is on going
  * @rmtoll SYSCFG_SCSR  CCMBSY      LL_SYSCFG_IsCCMSRAMEraseOngoing
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsCCMSRAMEraseOngoing(void)
{
  return ((READ_BIT(SYSCFG->SCSR, SYSCFG_SCSR_CCMBSY) == (SYSCFG_SCSR_CCMBSY)) ? 1UL : 0UL);
}

/**
  * @brief  Check if SRAM parity error detected
  * @rmtoll SYSCFG_CFGR2 SPF           LL_SYSCFG_IsActiveFlag_SP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SYSCFG_IsActiveFlag_SP(void)
{
  return ((READ_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_SPF) == (SYSCFG_CFGR2_SPF)) ? 1UL : 0UL);
}

/**
  * @brief  Clear SRAM parity error flag
  * @rmtoll SYSCFG_CFGR2 SPF           LL_SYSCFG_ClearFlag_SP
  * @retval None
  */
__STATIC_INLINE void LL_SYSCFG_ClearFlag_SP(void)
{
  SET_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_SPF);
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_FLASH FLASH
  * @{
  */

/**
  * @brief  Set FLASH Latency
  * @rmtoll FLASH_ACR    LATENCY       LL_FLASH_SetLatency
  * @param  Latency This parameter can be one of the following values:
  *         @arg @ref LL_FLASH_LATENCY_0
  *         @arg @ref LL_FLASH_LATENCY_1
  *         @arg @ref LL_FLASH_LATENCY_3
  *         @arg @ref LL_FLASH_LATENCY_4
  *         @arg @ref LL_FLASH_LATENCY_5
  *         @arg @ref LL_FLASH_LATENCY_6
  *         @arg @ref LL_FLASH_LATENCY_7
  * @retval None
  */
__STATIC_INLINE void LL_FLASH_SetLatency(uint32_t Latency)
{
  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, Latency);
}

/**
  * @brief  Get FLASH Latency
  * @rmtoll FLASH_ACR    LATENCY       LL_FLASH_GetLatency
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_FLASH_LATENCY_0
  *         @arg @ref LL_FLASH_LATENCY_1
  *         @arg @ref LL_FLASH_LATENCY_3
  *         @arg @ref LL_FLASH_LATENCY_4
  *         @arg @ref LL_FLASH_LATENCY_5
  *         @arg @ref LL_FLASH_LATENCY_6
  *         @arg @ref LL_FLASH_LATENCY_7
  */
__STATIC_INLINE uint32_t LL_FLASH_GetLatency(void)
{
  return (uint32_t)(READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY));
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EF_DBGMCU DBGMCU
  * @{
  */

/**
  * @brief  Return the device revision identifier
  * @retval Values between Min_Data=0x00 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DBGMCU_GetRevisionID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_REV_ID) >> DBGMCU_IDCODE_REV_ID_Pos);
}

/**
  * @brief  Enable the Debug Module during SLEEP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_SLEEP);
}

/**
  * @brief  Disable the Debug Module during SLEEP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_SLEEP);
}

/**
  * @brief  Indicate if enable the Debug Module during SLEEP mode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_IsEnabledDBGSleepMode(void)
{
  return ((READ_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_SLEEP) == (DBGMCU_CR1_DBG_SLEEP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the Debug Module during STOP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STOP);
}

/**
  * @brief  Disable the Debug Module during STOP mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STOP);
}

/**
  * @brief  Indicate if enable the Debug Module during STOP mode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_IsEnabledDBGStopMode(void)
{
  return ((READ_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STOP) == (DBGMCU_CR1_DBG_STOP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable the Debug Module during Standby mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STDBY);
}

/**
  * @brief  Disable the Debug Module during Standby mode
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STDBY);
}

/**
  * @brief  Indicate if enable the Debug Module during Standby mode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_IsEnabledDBGStandbyMode(void)
{
  return ((READ_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STDBY) == (DBGMCU_CR1_DBG_STDBY)) ? 1UL : 0UL);
}

/**
  * @brief  Freeze peripherals.
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_IWDG_STOP
  *         @arg @ref LL_DBGMCU_WWDG_STOP
  *         @arg @ref LL_DBGMCU_TIM1_STOP
  *         @arg @ref LL_DBGMCU_TIM2_STOP
  *         @arg @ref LL_DBGMCU_TIM3_STOP
  *         @arg @ref LL_DBGMCU_TIM4_STOP
  *         @arg @ref LL_DBGMCU_CAN1_STOP
  *         @arg @ref LL_DBGMCU_I2C1_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_I2C2_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_TIM5_STOP
  *         @arg @ref LL_DBGMCU_TIM6_STOP
  *         @arg @ref LL_DBGMCU_TIM7_STOP
  *         @arg @ref LL_DBGMCU_TIM8_STOP
  *         @arg @ref LL_DBGMCU_TIM9_STOP
  *         @arg @ref LL_DBGMCU_TIM10_STOP
  *         @arg @ref LL_DBGMCU_TIM11_STOP
  *         @arg @ref LL_DBGMCU_TIM12_STOP
  *         @arg @ref LL_DBGMCU_TIM13_STOP
  *         @arg @ref LL_DBGMCU_TIM14_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->CR1, Periphs);
}

/**
  * @brief  Unfreeze peripherals.D
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_IWDG_STOP
  *         @arg @ref LL_DBGMCU_WWDG_STOP
  *         @arg @ref LL_DBGMCU_TIM1_STOP
  *         @arg @ref LL_DBGMCU_TIM2_STOP
  *         @arg @ref LL_DBGMCU_TIM3_STOP
  *         @arg @ref LL_DBGMCU_TIM4_STOP
  *         @arg @ref LL_DBGMCU_CAN1_STOP
  *         @arg @ref LL_DBGMCU_I2C1_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_I2C2_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_TIM5_STOP
  *         @arg @ref LL_DBGMCU_TIM6_STOP
  *         @arg @ref LL_DBGMCU_TIM7_STOP
  *         @arg @ref LL_DBGMCU_TIM8_STOP
  *         @arg @ref LL_DBGMCU_TIM9_STOP
  *         @arg @ref LL_DBGMCU_TIM10_STOP
  *         @arg @ref LL_DBGMCU_TIM11_STOP
  *         @arg @ref LL_DBGMCU_TIM12_STOP
  *         @arg @ref LL_DBGMCU_TIM13_STOP
  *         @arg @ref LL_DBGMCU_TIM14_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->CR1, Periphs);
}

/**
  * @brief  Indicate if Freeze peripherals.
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be one of the following values:
  *         @arg @ref LL_DBGMCU_IWDG_STOP
  *         @arg @ref LL_DBGMCU_WWDG_STOP
  *         @arg @ref LL_DBGMCU_TIM1_STOP
  *         @arg @ref LL_DBGMCU_TIM2_STOP
  *         @arg @ref LL_DBGMCU_TIM3_STOP
  *         @arg @ref LL_DBGMCU_TIM4_STOP
  *         @arg @ref LL_DBGMCU_CAN1_STOP
  *         @arg @ref LL_DBGMCU_I2C1_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_I2C2_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_TIM5_STOP
  *         @arg @ref LL_DBGMCU_TIM6_STOP
  *         @arg @ref LL_DBGMCU_TIM7_STOP
  *         @arg @ref LL_DBGMCU_TIM8_STOP
  *         @arg @ref LL_DBGMCU_TIM9_STOP
  *         @arg @ref LL_DBGMCU_TIM10_STOP
  *         @arg @ref LL_DBGMCU_TIM11_STOP
  *         @arg @ref LL_DBGMCU_TIM12_STOP
  *         @arg @ref LL_DBGMCU_TIM13_STOP
  *         @arg @ref LL_DBGMCU_TIM14_STOP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_APB_GRP1_IsFreezePeriph(uint32_t Periphs)
{
  return ((READ_BIT(DBGMCU->CR1, Periphs) == (Periphs)) ? 1UL : 0UL);
}

/**
  * @brief  Freeze peripherals.
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_I2C3_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_I2C4_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_CAN2_STOP
  *         @arg @ref LL_DBGMCU_TIM15_STOP
  *         @arg @ref LL_DBGMCU_TIM16_STOP
  *         @arg @ref LL_DBGMCU_TIM17_STOP
  *         @arg @ref LL_DBGMCU_TIM18_STOP
  *         @arg @ref LL_DBGMCU_TIM19_STOP
  *         @arg @ref LL_DBGMCU_LPTIM_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB_GRP2_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->CR2, Periphs);
}

/**
  * @brief  Unfreeze peripherals.D
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_DBGMCU_I2C3_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_I2C4_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_CAN2_STOP
  *         @arg @ref LL_DBGMCU_TIM15_STOP
  *         @arg @ref LL_DBGMCU_TIM16_STOP
  *         @arg @ref LL_DBGMCU_TIM17_STOP
  *         @arg @ref LL_DBGMCU_TIM18_STOP
  *         @arg @ref LL_DBGMCU_TIM19_STOP
  *         @arg @ref LL_DBGMCU_LPTIM_STOP
  * @retval None
  */
__STATIC_INLINE void LL_DBGMCU_APB_GRP2_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->CR2, Periphs);
}

/**
  * @brief  Indicate if Freeze peripherals.
  * @note   Depending on devices and packages, some Peripherals may not be available.
  *         Refer to device datasheet for Peripherals availability.
  * @param  Periphs This parameter can be one of the following values:
  *         @arg @ref LL_DBGMCU_I2C3_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_I2C4_SMBUS_TIMEOUT
  *         @arg @ref LL_DBGMCU_CAN2_STOP
  *         @arg @ref LL_DBGMCU_TIM15_STOP
  *         @arg @ref LL_DBGMCU_TIM16_STOP
  *         @arg @ref LL_DBGMCU_TIM17_STOP
  *         @arg @ref LL_DBGMCU_TIM18_STOP
  *         @arg @ref LL_DBGMCU_TIM19_STOP
  *         @arg @ref LL_DBGMCU_LPTIM_STOP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DBGMCU_APB_GRP2_IsFreezePeriph(uint32_t Periphs)
{
  return ((READ_BIT(DBGMCU->CR2, Periphs) == (Periphs)) ? 1UL : 0UL);
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



#endif /* defined (FLASH) || defined (SYSCFG) || defined (DBGMCU) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_LL_SYSTEM_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

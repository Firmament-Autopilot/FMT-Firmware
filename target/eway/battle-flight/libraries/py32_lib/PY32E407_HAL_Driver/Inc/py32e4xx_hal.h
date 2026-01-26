/**
  ******************************************************************************
  * @file    py32e4xx_hal.h
  * @author  MCU Application Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
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
#ifndef __PY32E4xx_HAL_H
#define __PY32E4xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_conf.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup HAL
  * @{
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup HAL_Exported_Constants HAL Exported Constants
  * @{
  */

/** @defgroup HAL_TICK_FREQ Tick Frequency
  * @{
  */
#define HAL_TICK_FREQ_10HZ          100U
#define HAL_TICK_FREQ_100HZ         10U
#define HAL_TICK_FREQ_1KHZ          1U
#define HAL_TICK_FREQ_DEFAULT       HAL_TICK_FREQ_1KHZ
  
/**
  * @}
  */
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
/** @addtogroup HAL_Exported_Variables
  * @{
  */
extern uint32_t uwTickPrio;
extern uint32_t uwTickFreq;
/**
  * @}
  */

/* SYSCFG Exported Constants -------------------------------------------------*/
/** @defgroup SYSCFG_Exported_Constants SYSCFG Exported Constants
  * @{
  */

/** @defgroup SYSCFG_BootMode Boot Mode
  * @{
  */
#define SYSCFG_BOOT_MAINFLASH          0x00000000U
#define SYSCFG_BOOT_SYSTEMFLASH        SYSCFG_CFGR1_MEM_MODE_0
#define SYSCFG_BOOT_ESMC               SYSCFG_CFGR1_MEM_MODE_1
#define SYSCFG_BOOT_SRAM               (SYSCFG_CFGR1_MEM_MODE_1 | SYSCFG_CFGR1_MEM_MODE_0)
/**
  * @}
  */

/** @defgroup SYSCFG_ETH_PHY_Interface ETH PHY Interface
  * @{
  */
#define SYSCFG_ETH_PHY_MII             0x00000000U
#define SYSCFG_ETH_PHY_RMII            SYSCFG_CFGR1_ETH_PHYSEL
/**
  * @}
  */

/** @defgroup SYSCFG_I2C_ANF I2C Analog Filter
  * @{
  */
#define SYSCFG_I2C_ANF_PA8            SYSCFG_CFGR1_I2C_EIIC_0
#define SYSCFG_I2C_ANF_PA9            SYSCFG_CFGR1_I2C_EIIC_1
#define SYSCFG_I2C_ANF_PA13           SYSCFG_CFGR1_I2C_EIIC_2
#define SYSCFG_I2C_ANF_PA14           SYSCFG_CFGR1_I2C_EIIC_3
#define SYSCFG_I2C_ANF_PA15           SYSCFG_CFGR1_I2C_EIIC_4
#define SYSCFG_I2C_ANF_PB5            SYSCFG_CFGR1_I2C_EIIC_5
#define SYSCFG_I2C_ANF_PB7            SYSCFG_CFGR1_I2C_EIIC_6
#define SYSCFG_I2C_ANF_PB8            SYSCFG_CFGR1_I2C_EIIC_7
#define SYSCFG_I2C_ANF_PB9            SYSCFG_CFGR1_I2C_EIIC_8
#define SYSCFG_I2C_ANF_PC3            SYSCFG_CFGR1_I2C_EIIC_9
#define SYSCFG_I2C_ANF_PC6            SYSCFG_CFGR1_I2C_EIIC_10
#define SYSCFG_I2C_ANF_PC7            SYSCFG_CFGR1_I2C_EIIC_11
#define SYSCFG_I2C_ANF_PC8            SYSCFG_CFGR1_I2C_EIIC_12
#define SYSCFG_I2C_ANF_PC9            SYSCFG_CFGR1_I2C_EIIC_13
#define SYSCFG_I2C_ANF_PC11           SYSCFG_CFGR1_I2C_EIIC_14
#define SYSCFG_I2C_ANF_PF0            SYSCFG_CFGR1_I2C_EIIC_15
/**
  * @}
  */

/** @defgroup SYSCFG_TIM2_INTERNAL_TRIGGER1_REMAP TIM2 internal trigger1 remap
  * @{
  */
#define SYSCFG_TIM2_INTERNAL_TRIGGER1_NONE          0x00000000U
#define SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF      SYSCFG_CFGR1_TIM2ITR1_REMAP_0  /*!< TIM2ITR1 remaps to USB1_SOF */
#define SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF      SYSCFG_CFGR1_TIM2ITR1_REMAP_1  /*!< TIM2ITR1 remaps to USB2_SOF */
#define SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR  SYSCFG_CFGR1_TIM2ITR1_REMAP    /*!< TIM2ITR1 remaps to ETH_PTP_INTR */
/**
  * @}
  */

/** @defgroup SYSCFG_flags_definition Flags
  * @{
  */
#define SYSCFG_FLAG_SRAM_PE             SYSCFG_CFGR2_SPF       /*!< SRAM parity error (first 32kB of SRAM1 + CCM SRAM) */
#define SYSCFG_FLAG_CCMSRAM_BUSY        SYSCFG_SCSR_CCMBSY     /*!< CCMSRAM busy by erase operation */
/**
  * @}
  */

/** @defgroup SYSCFG_CCMSRAMWRP CCM Write protection
  * @{
  */
#define SYSCFG_CCMSRAMWRP_PAGE0          SYSCFG_SWPR_P0WP  /*!< CCMSRAM Write protection page 0 */
#define SYSCFG_CCMSRAMWRP_PAGE1          SYSCFG_SWPR_P1WP  /*!< CCMSRAM Write protection page 1 */
#define SYSCFG_CCMSRAMWRP_PAGE2          SYSCFG_SWPR_P2WP  /*!< CCMSRAM Write protection page 2 */
#define SYSCFG_CCMSRAMWRP_PAGE3          SYSCFG_SWPR_P3WP  /*!< CCMSRAM Write protection page 3 */
#define SYSCFG_CCMSRAMWRP_PAGE4          SYSCFG_SWPR_P4WP  /*!< CCMSRAM Write protection page 4 */
#define SYSCFG_CCMSRAMWRP_PAGE5          SYSCFG_SWPR_P5WP  /*!< CCMSRAM Write protection page 5 */
#define SYSCFG_CCMSRAMWRP_PAGE6          SYSCFG_SWPR_P6WP  /*!< CCMSRAM Write protection page 6 */
#define SYSCFG_CCMSRAMWRP_PAGE7          SYSCFG_SWPR_P7WP  /*!< CCMSRAM Write protection page 7 */
#define SYSCFG_CCMSRAMWRP_PAGE8          SYSCFG_SWPR_P8WP  /*!< CCMSRAM Write protection page 8 */
#define SYSCFG_CCMSRAMWRP_PAGE9          SYSCFG_SWPR_P9WP  /*!< CCMSRAM Write protection page 9 */
#define SYSCFG_CCMSRAMWRP_PAGE10         SYSCFG_SWPR_P10WP /*!< CCMSRAM Write protection page 10 */
#define SYSCFG_CCMSRAMWRP_PAGE11         SYSCFG_SWPR_P11WP /*!< CCMSRAM Write protection page 11 */
#define SYSCFG_CCMSRAMWRP_PAGE12         SYSCFG_SWPR_P12WP /*!< CCMSRAM Write protection page 12 */
#define SYSCFG_CCMSRAMWRP_PAGE13         SYSCFG_SWPR_P13WP /*!< CCMSRAM Write protection page 13 */
#define SYSCFG_CCMSRAMWRP_PAGE14         SYSCFG_SWPR_P14WP /*!< CCMSRAM Write protection page 14 */
#define SYSCFG_CCMSRAMWRP_PAGE15         SYSCFG_SWPR_P15WP /*!< CCMSRAM Write protection page 15 */
#define SYSCFG_CCMSRAMWRP_PAGE16         SYSCFG_SWPR_P16WP /*!< CCMSRAM Write protection page 16 */
#define SYSCFG_CCMSRAMWRP_PAGE17         SYSCFG_SWPR_P17WP /*!< CCMSRAM Write protection page 17 */
#define SYSCFG_CCMSRAMWRP_PAGE18         SYSCFG_SWPR_P18WP /*!< CCMSRAM Write protection page 18 */
#define SYSCFG_CCMSRAMWRP_PAGE19         SYSCFG_SWPR_P19WP /*!< CCMSRAM Write protection page 19 */
#define SYSCFG_CCMSRAMWRP_PAGE20         SYSCFG_SWPR_P20WP /*!< CCMSRAM Write protection page 20 */
#define SYSCFG_CCMSRAMWRP_PAGE21         SYSCFG_SWPR_P21WP /*!< CCMSRAM Write protection page 21 */
#define SYSCFG_CCMSRAMWRP_PAGE22         SYSCFG_SWPR_P22WP /*!< CCMSRAM Write protection page 22 */
#define SYSCFG_CCMSRAMWRP_PAGE23         SYSCFG_SWPR_P23WP /*!< CCMSRAM Write protection page 23 */
#define SYSCFG_CCMSRAMWRP_PAGE24         SYSCFG_SWPR_P24WP /*!< CCMSRAM Write protection page 24 */
#define SYSCFG_CCMSRAMWRP_PAGE25         SYSCFG_SWPR_P25WP /*!< CCMSRAM Write protection page 25 */
#define SYSCFG_CCMSRAMWRP_PAGE26         SYSCFG_SWPR_P26WP /*!< CCMSRAM Write protection page 26 */
#define SYSCFG_CCMSRAMWRP_PAGE27         SYSCFG_SWPR_P27WP /*!< CCMSRAM Write protection page 27 */
#define SYSCFG_CCMSRAMWRP_PAGE28         SYSCFG_SWPR_P28WP /*!< CCMSRAM Write protection page 28 */
#define SYSCFG_CCMSRAMWRP_PAGE29         SYSCFG_SWPR_P29WP /*!< CCMSRAM Write protection page 29 */
#define SYSCFG_CCMSRAMWRP_PAGE30         SYSCFG_SWPR_P30WP /*!< CCMSRAM Write protection page 30 */
#define SYSCFG_CCMSRAMWRP_PAGE31         SYSCFG_SWPR_P31WP /*!< CCMSRAM Write protection page 31 */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup HAL_Exported_Macros HAL Exported Macros
  * @{
  */

/** @defgroup DBGMCU_Freeze_Unfreeze Freeze Unfreeze Peripherals in Debug mode
  * @brief   Freeze/Unfreeze Peripherals in Debug mode
  * Note: On devices PY32E4xx
  *       Debug registers DBGMCU_IDCODE and DBGMCU_CR are accessible only in
  *       debug mode (not accessible by the user software in normal mode).
  *       Refer to errata sheet of these devices for more details.
  * @{
  */

/**
  * @brief  IWDG Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_IWDG_STOP)
#define __HAL_DBGMCU_FREEZE_IWDG()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_IWDG_STOP)
#define __HAL_DBGMCU_UNFREEZE_IWDG()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_IWDG_STOP)
#endif

/**
  * @brief  WWDG Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_WWDG_STOP)
#define __HAL_DBGMCU_FREEZE_WWDG()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_WWDG_STOP)
#define __HAL_DBGMCU_UNFREEZE_WWDG()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_WWDG_STOP)
#endif

/**
  * @brief  TIM1 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM1_STOP)
#define __HAL_DBGMCU_FREEZE_TIM1()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM1_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM1()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM1_STOP)
#endif

/**
  * @brief  TIM2 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM2_STOP)
#define __HAL_DBGMCU_FREEZE_TIM2()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM2_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM2()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM2_STOP)
#endif

/**
  * @brief  TIM3 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM3_STOP)
#define __HAL_DBGMCU_FREEZE_TIM3()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM3_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM3()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM3_STOP)
#endif

/**
  * @brief  TIM4 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM4_STOP)
#define __HAL_DBGMCU_FREEZE_TIM4()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM4_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM4()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM4_STOP)
#endif

/**
  * @brief  CAN Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_CAN1_STOP)
#define __HAL_DBGMCU_FREEZE_CAN1()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_CAN1_STOP)
#define __HAL_DBGMCU_UNFREEZE_CAN1()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_CAN1_STOP)
#endif

/**
  * @brief  I2C1 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_I2C1_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT()    SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_I2C1_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT()  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_I2C1_SMBUS_TIMEOUT)
#endif

/**
  * @brief  I2C2 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_I2C2_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT()    SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_I2C2_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT()  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_I2C2_SMBUS_TIMEOUT)
#endif

/**
  * @brief  TIM8 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM8_STOP)
#define __HAL_DBGMCU_FREEZE_TIM8()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM8_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM8()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM8_STOP)
#endif

/**
  * @brief  TIM5 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM5_STOP)
#define __HAL_DBGMCU_FREEZE_TIM5()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM5_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM5()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM5_STOP)
#endif

/**
  * @brief  TIM6 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM6_STOP)
#define __HAL_DBGMCU_FREEZE_TIM6()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM6_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM6()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM6_STOP)
#endif

/**
  * @brief  TIM7 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM7_STOP)
#define __HAL_DBGMCU_FREEZE_TIM7()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM7_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM7()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM7_STOP)
#endif

/**
  * @brief  TIM12 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM12_STOP)
#define __HAL_DBGMCU_FREEZE_TIM12()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM12_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM12()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM12_STOP)
#endif

/**
  * @brief  TIM13 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM13_STOP)
#define __HAL_DBGMCU_FREEZE_TIM13()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM13_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM13()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM13_STOP)
#endif

/**
  * @brief  TIM14 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM14_STOP)
#define __HAL_DBGMCU_FREEZE_TIM14()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM14_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM14()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM14_STOP)
#endif

/**
  * @brief  TIM9 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM9_STOP)
#define __HAL_DBGMCU_FREEZE_TIM9()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM9_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM9()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM9_STOP)
#endif

/**
  * @brief  TIM10 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM10_STOP)
#define __HAL_DBGMCU_FREEZE_TIM10()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM10_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM10()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM10_STOP)
#endif

/**
  * @brief  TIM11 Peripherals Debug mode
  */
#if defined (DBGMCU_CR1_DBG_TIM11_STOP)
#define __HAL_DBGMCU_FREEZE_TIM11()            SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM11_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM11()          CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_TIM11_STOP)
#endif

/**
  * @brief  I2C3 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_I2C3_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_I2C3_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_I2C3_SMBUS_TIMEOUT)
#endif

/**
  * @brief  I2C4 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_I2C4_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_FREEZE_I2C4_TIMEOUT()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_I2C4_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_UNFREEZE_I2C4_TIMEOUT()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_I2C4_SMBUS_TIMEOUT)
#endif

/**
  * @brief  CAN2 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_CAN2_STOP)
#define __HAL_DBGMCU_FREEZE_CAN2()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_CAN2_STOP)
#define __HAL_DBGMCU_UNFREEZE_CAN2()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_CAN2_STOP)
#endif

/**
  * @brief  TIM15 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_TIM15_STOP)
#define __HAL_DBGMCU_FREEZE_TIM15()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM15_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM15()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM15_STOP)
#endif

/**
  * @brief  TIM16 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_TIM16_STOP)
#define __HAL_DBGMCU_FREEZE_TIM16()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM16_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM16()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM16_STOP)
#endif

/**
  * @brief  TIM17 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_TIM17_STOP)
#define __HAL_DBGMCU_FREEZE_TIM17()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM17_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM17()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM17_STOP)
#endif

/**
  * @brief  TIM18 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_TIM18_STOP)
#define __HAL_DBGMCU_FREEZE_TIM18()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM18_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM18()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM18_STOP)
#endif

/**
  * @brief  TIM19 Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_TIM19_STOP)
#define __HAL_DBGMCU_FREEZE_TIM19()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM19_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM19()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_TIM19_STOP)
#endif

/**
  * @brief  LPTIM Peripherals Debug mode
  */
#if defined (DBGMCU_CR2_DBG_LPTIM_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM()            SET_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_LPTIM_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM()          CLEAR_BIT(DBGMCU->CR2, DBGMCU_CR2_DBG_LPTIM_STOP)
#endif

/**
  * @}
  */

/** @defgroup SYSCFG_Exported_Macros SYSCFG Exported Macros
  * @{
  */

/**
  * @brief Enable the remapping of ETH_PTP_PPS.
  * @note  ENABLE: PTP_PPS is output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
#define __HAL_SYSCFG_ETH_PTP_PPS_ENABLE()                SET_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_PTP_PPS_REMAP)

/**
  * @brief Disable the remapping of ETH_PTP_PPS.
  * @note  DISABLE: PTP_PPS not output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
#define __HAL_SYSCFG_ETH_PTP_PPS_DISABLE()               CLEAR_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_PTP_PPS_REMAP)

/**
  * @brief The USB SOF for configuring CTC comes from USB1.
  * @retval None
  */
#define __HAL_SYSCFG_CTC_SOF_FROM_USB1()                 CLEAR_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_CTC_SOF_SEL)

/**
  * @brief The USB SOF for configuring CTC comes from USB2.
  * @retval None
  */
#define __HAL_SYSCFG_CTC_SOF_FROM_USB2()                 SET_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_CTC_SOF_SEL)

/** @brief  CCMSRAM page write protection enable macro
  * @param __CCMSRAMWRP__: This parameter can be a value of @ref SYSCFG_CCMSRAMWRP
  * @note   write protection can only be disabled by a system reset
  * @retval None
  */
/* Legacy define */
#define __HAL_SYSCFG_CCMSRAM_WRP_1_31_ENABLE   __HAL_SYSCFG_CCMSRAM_WRP_0_31_ENABLE
#define __HAL_SYSCFG_CCMSRAM_WRP_0_31_ENABLE(__CCMSRAMWRP__)    do {assert_param(IS_SYSCFG_CCMSRAMWRP_PAGE((__CCMSRAMWRP__)));\
                                                                     SET_BIT(SYSCFG->SWPR,(__CCMSRAMWRP__));\
                                                                   }while(0)

/** @brief  CCMSRAM page write protection unlock prior to erase
  * @note   Writing a wrong key reactivates the write protection
  */
#define __HAL_SYSCFG_CCMSRAM_WRP_UNLOCK()    do {SYSCFG->SKR = 0xCA;\
                                                  SYSCFG->SKR = 0x53;\
                                                }while(0)

/** @brief  CCMSRAM erase
  * @note   __SYSCFG_GET_FLAG(SYSCFG_FLAG_CCMSRAM_BUSY) may be used to check end of erase
  */
#define __HAL_SYSCFG_CCMSRAM_ERASE()         SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_CCMER)

/** @brief  SYSCFG Break ECC lock.
  *         Enable and lock the connection of Flash ECC error connection to TIM1/8/15/16/17 Break input.
  * @note   The selected configuration is locked and can be unlocked only by system reset.
  */
#define __HAL_SYSCFG_BREAK_ECC_LOCK()        SET_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_ECCL)

/** @brief  SYSCFG Break Cortex-M4 Lockup lock.
  *         Enable and lock the connection of Cortex-M4 LOCKUP (Hardfault) output to TIM1/8/15/16/17 Break input.
  * @note   The selected configuration is locked and can be unlocked only by system reset.
  */
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK()     SET_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_CLL)

/** @brief  SYSCFG Break PVD lock.
  *         Enable and lock the PVD connection to Timer1/8/15/16/17 Break input, as well as the PVDE and PLS[2:0] in the PWR_CR2 register.
  * @note   The selected configuration is locked and can be unlocked only by system reset.
  */
#define __HAL_SYSCFG_BREAK_PVD_LOCK()        SET_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_PVDL)

/** @brief  SYSCFG Break SRAM parity lock.
  *         Enable and lock the SRAM parity error (first 32kB of SRAM1 + CCM SRAM) signal connection to TIM1/8/15/16/17 Break input.
  * @note   The selected configuration is locked and can be unlocked by system reset.
  */
#define __HAL_SYSCFG_BREAK_SRAMPARITY_LOCK() SET_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_SPL)

/** @brief  Check SYSCFG flag is set or not.
  * @param  __FLAG__: specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg @ref SYSCFG_FLAG_SRAM_PE   SRAM Parity Error Flag
  *            @arg @ref SYSCFG_FLAG_CCMSRAM_BUSY CCMSRAM Erase Ongoing
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_SYSCFG_GET_FLAG(__FLAG__)      ((((((__FLAG__) == SYSCFG_SCSR_CCMBSY) ? SYSCFG->SCSR : SYSCFG->CFGR[1]) \
                                                & (__FLAG__)) != 0U) ? 1U : 0U)

/** @brief  Set the SPF bit to clear the SRAM Parity Error Flag.
  */
#define __HAL_SYSCFG_CLEAR_FLAG()            SET_BIT(SYSCFG->CFGR[1], SYSCFG_CFGR2_SPF)

/**
  * @}
  */

/**
  * @}
  */
/* Private macros ------------------------------------------------------------*/
/** @defgroup HAL_Private_Macros HAL Private Macros
  * @{
  */
#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))
                           
/**
  * @}
  */

/* SYSCFG Private macros -----------------------------------------------------*/
/** @defgroup SYSCFG_Private_Macros SYSCFG Private Macros
  * @{
  */
#define IS_SYSCFG_I2C_ANF_IO(IO) (((IO) == SYSCFG_I2C_ANF_PA8)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PA9)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PA13) || \
                                  ((IO) == SYSCFG_I2C_ANF_PA14) || \
                                  ((IO) == SYSCFG_I2C_ANF_PA15) || \
                                  ((IO) == SYSCFG_I2C_ANF_PB5)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PB7)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PB8)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PB9)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PC3)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PC6)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PC7)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PC8)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PC9)  || \
                                  ((IO) == SYSCFG_I2C_ANF_PC11) || \
                                  ((IO) == SYSCFG_I2C_ANF_PF0 ))

#define IS_SYSCFG_TIM2_INTERNAL_TRIGGER1(TIM2_INTERNAL_TRIGGER1)  (((TIM2_INTERNAL_TRIGGER1) == SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF)  || \
                                                                   ((TIM2_INTERNAL_TRIGGER1) == SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF)  || \
                                                                   ((TIM2_INTERNAL_TRIGGER1) == SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR ))

#if (CCMSRAM_SIZE == 0x00008000UL) || (CCMSRAM_SIZE == 0x00004000UL)
#define IS_SYSCFG_CCMSRAMWRP_PAGE(__PAGE__)  ((__PAGE__) > 0U)
#elif (CCMSRAM_SIZE == 0x00002800UL)
#define IS_SYSCFG_CCMSRAMWRP_PAGE(__PAGE__)  (((__PAGE__) > 0U) && ((__PAGE__) <= 0x000003FFU))
#endif /* CCMSRAM_SIZE */

/**
  * @}
  */

/* DBGMCU Private macros -----------------------------------------------------*/
/** @defgroup DBGMCU_Private_Macros DBGMCU Private Macros
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup HAL_Exported_Functions
  * @{
  */
/** @addtogroup HAL_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
/**
  * @}
  */

/** @addtogroup HAL_Exported_Functions_Group2
  * @{
  */
/* Peripheral Control functions  ************************************************/
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(uint32_t Freq);
uint32_t HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
uint32_t HAL_GetUID(uint8_t WordNumber);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);
/**
  * @}
  */
  
/** @addtogroup HAL_Exported_Functions_Group3
  * @{
  */
void HAL_DBGMCU_EnableDBGSleepMode(void);
void HAL_DBGMCU_DisableDBGSleepMode(void);
void HAL_DBGMCU_EnableDBGStopMode(void);
void HAL_DBGMCU_DisableDBGStopMode(void);
void HAL_DBGMCU_EnableDBGStandbyMode(void);
void HAL_DBGMCU_DisableDBGStandbyMode(void);
/**
  * @}
  */
  
/** @addtogroup HAL_Exported_Functions_Group4
  * @{
  */
void HAL_SYSCFG_SetRemapMemory(uint32_t Memory);
uint32_t HAL_SYSCFG_GetRemapMemory(void);
void HAL_SYSCFG_SetETHPhysicalInterface(uint32_t Interface);
uint32_t HAL_SYSCFG_GetETHPhysicalInterface(void);
void HAL_SYSCFG_SetRemapTIM2InternalTrigger1(uint32_t TIM2IneternalTrigger1);
uint32_t HAL_SYSCFG_GetRemapTIM2InternalTrigger1(void);
void HAL_SYSCFG_EnableI2CAnalogFilter(uint32_t I2CAnalogFilter);
void HAL_SYSCFG_DisableI2CAnalogFilter(uint32_t I2CAnalogFilter);
void HAL_SYSCFG_EnableGPIONoiseFilter(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_SYSCFG_DisableGPIONoiseFilter(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_SYSCFG_EnableGPIOAnalogMode(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_SYSCFG_DisableGPIOAnalogMode(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
void HAL_SYSCFG_EnablePVD_IN_AnalogMode(void);
void HAL_SYSCFG_DisablePVD_IN_AnalogMode(void);
void HAL_SYSCFG_CCMSRAMErase(void);
void HAL_SYSCFG_CCMSRAM_WriteProtectionEnable(uint32_t Page);
/**
  * @}
  */

/**
  * @}
  */
/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup HAL_Private_Constants HAL Private Constants
  * @{
  */
/**
  * @}
  */
/* Private macros ------------------------------------------------------------*/
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

#endif /* __PY32E4xx_HAL_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

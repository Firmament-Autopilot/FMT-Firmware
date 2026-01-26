/**
  ******************************************************************************
  * @file    py32e407_hal_pwr_ex.h
  * @author  MCU Application Team
  * @brief   Header file of PWR HAL Extension module.
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
#ifndef __PY32E407_HAL_PWR_EX_H
#define __PY32E407_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup PWREx
  * @{
  */


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup PWREx_Exported_Constants  PWR Extended Exported Constants
  * @{
  */

/** @defgroup PWREx_WUP_Polarity Shift to apply to retrieve polarity information from PWR_WAKEUP_PINy_xxx constants
  * @{
  */
#define PWR_WUP_POLARITY_SHIFT                  0x05U   /*!< Internal constant used to retrieve wakeup pin polariry */
/**
  * @}
  */


/** @defgroup PWREx_WakeUp_Pins  PWR wake-up pins
  * @{
  */
#define PWR_WAKEUP_PIN1                 PWR_CR3_EWUP1  /*!< Wakeup pin 1 (with high level polarity) */
#define PWR_WAKEUP_PIN2                 PWR_CR3_EWUP2  /*!< Wakeup pin 2 (with high level polarity) */
#define PWR_WAKEUP_PIN3                 PWR_CR3_EWUP3  /*!< Wakeup pin 3 (with high level polarity) */
#define PWR_WAKEUP_PIN4                 PWR_CR3_EWUP4  /*!< Wakeup pin 4 (with high level polarity) */
#define PWR_WAKEUP_PIN5                 PWR_CR3_EWUP5  /*!< Wakeup pin 5 (with high level polarity) */
#define PWR_WAKEUP_PIN1_HIGH            PWR_CR3_EWUP1  /*!< Wakeup pin 1 (with high level polarity) */
#define PWR_WAKEUP_PIN2_HIGH            PWR_CR3_EWUP2  /*!< Wakeup pin 2 (with high level polarity) */
#define PWR_WAKEUP_PIN3_HIGH            PWR_CR3_EWUP3  /*!< Wakeup pin 3 (with high level polarity) */
#define PWR_WAKEUP_PIN4_HIGH            PWR_CR3_EWUP4  /*!< Wakeup pin 4 (with high level polarity) */
#define PWR_WAKEUP_PIN5_HIGH            PWR_CR3_EWUP5  /*!< Wakeup pin 5 (with high level polarity) */
/* #define PWR_WAKEUP_PIN1_LOW             (uint32_t)((PWR_CR4_WP1<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP1) */ /*!< Wakeup pin 1 (with low level polarity) */
/* #define PWR_WAKEUP_PIN2_LOW             (uint32_t)((PWR_CR4_WP2<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP2) */ /*!< Wakeup pin 2 (with low level polarity) */
/* #define PWR_WAKEUP_PIN3_LOW             (uint32_t)((PWR_CR4_WP3<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP3) */ /*!< Wakeup pin 3 (with low level polarity) */
/* #define PWR_WAKEUP_PIN4_LOW             (uint32_t)((PWR_CR4_WP4<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP4) */ /*!< Wakeup pin 4 (with low level polarity) */
/* #define PWR_WAKEUP_PIN5_LOW             (uint32_t)((PWR_CR4_WP5<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP5) */ /*!< Wakeup pin 5 (with low level polarity) */
/**
  * @}
  */

/** @defgroup PWREx_Regulator_Voltage_Scale  PWR Regulator voltage scale
  * @{
  */
/* Legacy defines */
#define PWR_REGULATOR_VOLTAGE_SCALE1         0x00000000U             /* High voltage. */
#define PWR_REGULATOR_VOLTAGE_SCALE2         PWR_CR1_VOS_0           /* Medium voltage */
#define PWR_REGULATOR_VOLTAGE_SCALE3         PWR_CR1_VOS_1           /* Mddium low voltage */
#define PWR_REGULATOR_VOLTAGE_SCALE4         PWR_CR1_VOS             /* Low voltage */

#define PWR_REGULATOR_VOLTAGE_HIGH           PWR_REGULATOR_VOLTAGE_SCALE1           /* High voltage. */
#define PWR_REGULATOR_VOLTAGE_MEDIUM         PWR_REGULATOR_VOLTAGE_SCALE2           /* Medium voltage */
#define PWR_REGULATOR_VOLTAGE_MEDIUM_LOW     PWR_REGULATOR_VOLTAGE_SCALE3           /* Mddium low voltage */
#define PWR_REGULATOR_VOLTAGE_LOW            PWR_REGULATOR_VOLTAGE_SCALE4           /* Low voltage */

/**
  * @}
  */

/** @defgroup PWREx_SRAM2_VOLTAGE_SCALE PWREx SRAM2 Voltage Scale
  * @{
  */  
/* Legacy defines */
#define PWR_SRAM2_VOLTAGE_SCALE1            0x00000000U             /* High voltage. */
#define PWR_SRAM2_VOLTAGE_SCALE2            PWR_CR1_SRAM_RETV_0     /* Medium voltage */
#define PWR_SRAM2_VOLTAGE_SCALE3            PWR_CR1_SRAM_RETV_1     /* Mddium low voltage */
#define PWR_SRAM2_VOLTAGE_SCALE4            PWR_CR1_SRAM_RETV       /* Low voltage */

#define PWR_SRAM2_VOLTAGE_HIGH              PWR_SRAM2_VOLTAGE_SCALE1     /* High voltage. */
#define PWR_SRAM2_VOLTAGE_MEDIUM            PWR_SRAM2_VOLTAGE_SCALE2     /* Medium voltage */
#define PWR_SRAM2_VOLTAGE_MEDIUM_LOW        PWR_SRAM2_VOLTAGE_SCALE3     /* Mddium low voltage */
#define PWR_SRAM2_VOLTAGE_LOW               PWR_SRAM2_VOLTAGE_SCALE4     /* Low voltage */
/**
  * @}
  */

/** @defgroup PWREx_Flag  PWR Status Flags
  *        The only exception is PWR_FLAG_WU, encompassing all
  *        wake-up flags and set to PWR_SR_WUF.
  * @{
  */
#define PWR_FLAG_WUF1                       PWR_SR_WUF1          /*!< Wakeup event on wakeup pin 1 */
#define PWR_FLAG_WUF2                       PWR_SR_WUF2          /*!< Wakeup event on wakeup pin 2 */
#define PWR_FLAG_WUF3                       PWR_SR_WUF3          /*!< Wakeup event on wakeup pin 3 */
#define PWR_FLAG_WUF4                       PWR_SR_WUF4          /*!< Wakeup event on wakeup pin 4 */
#define PWR_FLAG_WUF5                       PWR_SR_WUF5          /*!< Wakeup event on wakeup pin 5 */
#define PWR_FLAG_WU                         PWR_SR_WUF           /*!< Encompass wakeup event on all wakeup pins */
#define PWR_FLAG_SB                         PWR_SR_SBF           /*!< Standby flag */
#define PWR_FLAG_MR_RDY                     PWR_SR_MR_RDY        /*!< Main Regulator ready flag */
#define PWR_FLAG_PVDO                       PWR_SR_PVDO          /*!< Power Voltage Detector output flag */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup PWREx_Exported_Macros PWR Extended Exported Macros
 * @{
 */

/** @brief  macros configure the main internal regulator output voltage.
  * @param  __REGULATOR__ specifies the regulator output voltage to achieve
  *         a tradeoff between performance and power consumption when the device does
  *         not operate at the maximum frequency (refer to the datasheets for more details).
  *          This parameter can be one of the following values:
  *            @arg PWR_REGULATOR_VOLTAGE_HIGH       : Regulator High voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_MEDIUM     : Regulator Medium voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_MEDIUM_LOW : Regulator Mddium low voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_LOW        : Regulator Low voltage mode
  * @retval None
  */
#define __HAL_PWR_VOLTAGESCALING_CONFIG(__REGULATOR__) do {                                                     \
                                                            __IO uint32_t tmpreg;                               \
                                                            MODIFY_REG(PWR->CR1, PWR_CR1_VOS, (__REGULATOR__)); \
                                                            /* Delay after an RCC peripheral clock enabling */  \
                                                            tmpreg = READ_BIT(PWR->CR1, PWR_CR1_VOS);           \
                                                            UNUSED(tmpreg);                                     \
                                                          } while(0)

/** @brief  macros configure the voltage of VR in STANDBY Mode.
  * @param  __REGULATOR__ specifies the SRAM2 voltage to achieve
  *          This parameter can be one of the following values:
  *            @arg PWR_SRAM2_VOLTAGE_HIGH       : SRAM2 High voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_MEDIUM     : SRAM2 Medium voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_MEDIUM_LOW : SRAM2 Mddium low voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_LOW        : SRAM2 Low voltage mode,
  * @retval None
  */
#define __HAL_PWR_SRAM2VOLTAGESCALING_CONFIG(__REGULATOR__) do {                                                     \
                                                            __IO uint32_t tmpreg = 0x00U;                        \
                                                            MODIFY_REG(PWR->CR1, PWR_CR1_SRAM_RETV, (__REGULATOR__));   \
                                                            /* Delay after an RCC peripheral clock enabling */  \
                                                            tmpreg = READ_BIT(PWR->CR1, PWR_CR1_SRAM_RETV);             \
                                                            UNUSED(tmpreg);                                     \
                                                          } while(0U)

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup PWREx_Private_Constants PWREx Private Constants
  * @{
  */

/** @defgroup PWR_FLASH_WAKEUP_DELAY Flash wakeup delay time
  * @{
  */  
#define PWR_WAKEUP_FLASH_DELAY_3US  0x00000000U
#define PWR_WAKEUP_FLASH_DELAY_5US  PWR_CR1_FLS_WUPT_0
#define PWR_WAKEUP_FLASH_DELAY_2US  PWR_CR1_FLS_WUPT_1
#define PWR_WAKEUP_FLASH_DELAY_0US  (PWR_CR1_FLS_WUPT_0 | PWR_CR1_FLS_WUPT_1)
 /**
  * @}
  */

/** @defgroup PWR_MRREADY_WAKEUP_DELAY standby wakeup MR ready delay time
  * @{
  */  
#define PWR_WAKEUP_MRREADY_DELAY_3US   0x00000000U
#define PWR_WAKEUP_MRREADY_DELAY_5US  PWR_CR1_STDBY_MRRDY_WAIT_0
#define PWR_WAKEUP_MRREADY_DELAY_10US  PWR_CR1_STDBY_MRRDY_WAIT_1
#define PWR_WAKEUP_MRREADY_DELAY_20US  (PWR_CR1_STDBY_MRRDY_WAIT_0 | PWR_CR1_STDBY_MRRDY_WAIT_1)
 /**
  * @}
  */


/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/** @addtogroup  PWREx_Private_Macros   PWR Extended Private Macros
  * @{
  */

#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN1) || \
                                ((PIN) == PWR_WAKEUP_PIN2) || \
                                ((PIN) == PWR_WAKEUP_PIN3) || \
                                ((PIN) == PWR_WAKEUP_PIN4) || \
                                ((PIN) == PWR_WAKEUP_PIN5) || \
                                ((PIN) == PWR_WAKEUP_PIN1_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN2_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN3_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN4_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN5_HIGH))
/* 
#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN1) || \
                                ((PIN) == PWR_WAKEUP_PIN2) || \
                                ((PIN) == PWR_WAKEUP_PIN3) || \
                                ((PIN) == PWR_WAKEUP_PIN4) || \
                                ((PIN) == PWR_WAKEUP_PIN5) || \
                                ((PIN) == PWR_WAKEUP_PIN1_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN2_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN3_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN4_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN5_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN1_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN2_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN3_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN4_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN5_LOW))
 */
#define IS_PWR_VOLTAGE_SCALING_RANGE(RANGE) (((RANGE) == PWR_REGULATOR_VOLTAGE_HIGH       ) || \
                                             ((RANGE) == PWR_REGULATOR_VOLTAGE_MEDIUM     ) || \
                                             ((RANGE) == PWR_REGULATOR_VOLTAGE_MEDIUM_LOW ) || \
                                             ((RANGE) == PWR_REGULATOR_VOLTAGE_LOW        ))

#define IS_PWR_SRAM2VOLTAGE_SCALING_RANGE(RANGE) (((RANGE) == PWR_SRAM2_VOLTAGE_HIGH      ) || \
                                                  ((RANGE) == PWR_SRAM2_VOLTAGE_MEDIUM    ) || \
                                                  ((RANGE) == PWR_SRAM2_VOLTAGE_MEDIUM_LOW) || \
                                                  ((RANGE) == PWR_SRAM2_VOLTAGE_LOW       ))
/**
  * @}
  */


/** @addtogroup PWREx_Exported_Functions PWR Extended Exported Functions
  * @{
  */

/** @addtogroup PWREx_Exported_Functions_Group1 Extended Peripheral Control functions
  * @{
  */


/* Peripheral Control functions  **********************************************/
void HAL_PWREx_SetWakeupFlashDelay(uint32_t DelayTime);
uint32_t HAL_PWREx_GetWakeupFlashDelay(void);
void HAL_PWREx_SetWakeupMrReadyDelay(uint32_t DelayTime);
uint32_t HAL_PWREx_GetWakeupMrReadyDelay(void);
void HAL_PWREx_DisableHSIWakeupWait(void);
void HAL_PWREx_EnableHSIWakeupWait(void);
void HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);
uint32_t HAL_PWREx_GetVoltageRange(void);
void HAL_PWREx_ControlSRAM2VoltageScaling(uint32_t VoltageScaling);
uint32_t HAL_PWREx_GetSRAM2VoltageRange(void);
void HAL_PWREx_EnableSRAM2ContentRetention(void);
void HAL_PWREx_DisableSRAM2ContentRetention(void);

/* Low Power modes configuration functions ************************************/
void HAL_PWREx_EnableLowPowerRunMode(void);
HAL_StatusTypeDef HAL_PWREx_DisableLowPowerRunMode(void);
void HAL_PWREx_EnterSTOP0Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP1Mode(uint8_t STOPEntry);

/**
  * @}
  */

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


#endif /* __PY32E407_HAL_PWR_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

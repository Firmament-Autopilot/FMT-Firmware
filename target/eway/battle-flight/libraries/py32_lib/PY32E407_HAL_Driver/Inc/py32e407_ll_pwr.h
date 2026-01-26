/**
  ******************************************************************************
  * @file    py32e407_ll_pwr.h
  * @author  MCU Application Team
  * @brief   Header file of PWR LL module.
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
#ifndef PY32E407_LL_PWR_H
#define PY32E407_LL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined(PWR)

/** @defgroup PWR_LL PWR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Constants PWR Exported Constants
  * @{
  */
/** @defgroup PWR_LL_EC_WAKEUP_HSION_MODE WAKEUP HSI ON MODE
  * @{
  */
#define LL_PWR_STOPWAKEUP_HSION_AFTER_MR       0x00000000U         /* Wake up from the STOP mode, After the MR becomes stable, enable HSI */
#define LL_PWR_STOPWAKEUP_HSION_IMMEDIATE      PWR_CR1_HSION_CTRL  /* Wake up from the STOP mode, Enable HSI immediately */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_PROGRAMMA_FLASH_DELAY WAKEUP PROGRAMMA FLASH DELAY
  * @{
  */          
#define LL_PWR_STOPWAKEUP_FLASH_DELAY_3US      (0x00000000U)                              /* Wake up from the STOP mode, Delay 3us enable flash*/
#define LL_PWR_STOPWAKEUP_FLASH_DELAY_5US      (                     PWR_CR1_FLS_WUPT_0)  /* Wake up from the STOP mode, Delay 5us enable flash*/
#define LL_PWR_STOPWAKEUP_FLASH_DELAY_2US      (PWR_CR1_FLS_WUPT_1                     )  /* Wake up from the STOP mode, Delay 2us enable flash*/
#define LL_PWR_STOPWAKEUP_FLASH_DELAY_0US      (PWR_CR1_FLS_WUPT_1 | PWR_CR1_FLS_WUPT_0)  /* Wake up from the STOP mode, Delay 0us enable flash*/
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_STANDBY_MRREAD_DELAY WAKEUP STANDBY MRREAD DELAY
  * @{
  */          
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_3US      (0x00000000U)                                             /* Wake up from the STANDBY mode, MR ready wait 3us*/
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_5US      (                             PWR_CR1_STDBY_MRRDY_WAIT_0) /* Wake up from the STANDBY mode, MR ready wait 5us*/
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_10US     (PWR_CR1_STDBY_MRRDY_WAIT_1                             ) /* Wake up from the STANDBY mode, MR ready wait 10us*/
#define LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_20US     (PWR_CR1_STDBY_MRRDY_WAIT_1 | PWR_CR1_STDBY_MRRDY_WAIT_0) /* Wake up from the STANDBY mode, MR ready wait 20us*/
/**
  * @}
  */

/** @defgroup PWR_LL_EC_SELECT_VR_OUTPUT_VOLTAGE_LEVEL SELECT VR OUTPUT VOLTAGE LEVEL
  * @{
  */
#define LL_PWR_REGU_VOLTAGE_SCALE1               0x00000000U          /* High voltage.      */
#define LL_PWR_REGU_VOLTAGE_SCALE2               PWR_CR1_VOS_0        /* Medium voltage     */
#define LL_PWR_REGU_VOLTAGE_SCALE3               PWR_CR1_VOS_1        /* Mddium low voltage */
#define LL_PWR_REGU_VOLTAGE_SCALE4               PWR_CR1_VOS          /* Low voltage        */

#define LL_PWR_REGU_VOLTAGE_HIGH                 LL_PWR_REGU_VOLTAGE_SCALE1
#define LL_PWR_REGU_VOLTAGE_MEDIUM               LL_PWR_REGU_VOLTAGE_SCALE2
#define LL_PWR_REGU_VOLTAGE_MEDIUM_LOW           LL_PWR_REGU_VOLTAGE_SCALE3
#define LL_PWR_REGU_VOLTAGE_LOW                  LL_PWR_REGU_VOLTAGE_SCALE4

/**
  * @}
  */

/** @defgroup PWR_LL_EC_CONTROL_SRAM2_VOLTAGE_IN_STANDBY CONTROL SRAM2 VOLTAGE IN STANDBY MODE
  * @{
  */          
#define LL_PWR_SRAM2_VOLTAGE_HIGH                0x00000000U          /* High voltage.      */
#define LL_PWR_SRAM2_VOLTAGE_MEDIUM              PWR_CR1_SRAM_RETV_0  /* Medium voltage     */
#define LL_PWR_SRAM2_VOLTAGE_MEDIUM_LOW          PWR_CR1_SRAM_RETV_1  /* Mddium low voltage */
#define LL_PWR_SRAM2_VOLTAGE_LOW                 PWR_CR1_SRAM_RETV    /* Low voltage        */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_PWR_WriteReg function
  * @{
  */
#define LL_PWR_SCR_CSBF                    PWR_SCR_CSBF
#define LL_PWR_SCR_CWUF                    PWR_SCR_CWUF
#define LL_PWR_SCR_CWUF5                   PWR_SCR_CWUF5
#define LL_PWR_SCR_CWUF4                   PWR_SCR_CWUF4
#define LL_PWR_SCR_CWUF3                   PWR_SCR_CWUF3
#define LL_PWR_SCR_CWUF2                   PWR_SCR_CWUF2
#define LL_PWR_SCR_CWUF1                   PWR_SCR_CWUF1
/**
  * @}
  */

/** @defgroup PWR_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_PWR_ReadReg function
  * @{
  */
#define LL_PWR_SR_PVDO                     PWR_SR_PVDO
#define LL_PWR_SR_MR_RDY                   PWR_SR_MR_RDY
#define LL_PWR_SR_SBF                      PWR_SR_SBF
#define LL_PWR_SR_WUF                      PWR_SR_WUF
#define LL_PWR_SR_EWUP1                    PWR_SR_WUF1
#define LL_PWR_SR_EWUP2                    PWR_SR_WUF2
#define LL_PWR_SR_EWUP3                    PWR_SR_WUF3
#define LL_PWR_SR_EWUP4                    PWR_SR_WUF4
#define LL_PWR_SR_EWUP5                    PWR_SR_WUF5
/**
  * @}
  */

/** @defgroup PWR_LL_EC_MODE_PWR MODE PWR
  * @{
  */
#define LL_PWR_MODE_STOP0                  (0x00000000U)  /*!< Stop0:   Work in MR mode  */
#define LL_PWR_MODE_STOP1                  PWR_CR1_LPMS_0 /*!< Stop1:   Work in LPR mode */
#define LL_PWR_MODE_STANDBY                PWR_CR1_LPMS   /*!< Standby: VR close mode    */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_PVDLEVEL Power Voltage Detector Level
  * @{
  */
/* #define LL_PWR_PVDLEVEL_0                  (PWR_CR2_PLS_LEV0) */     /*!< Voltage threshold detected by PVD 1.8 V */
/* #define LL_PWR_PVDLEVEL_1                  (PWR_CR2_PLS_LEV1) */     /*!< Voltage threshold detected by PVD 2.0 V */
/* #define LL_PWR_PVDLEVEL_2                  (PWR_CR2_PLS_LEV2) */     /*!< Voltage threshold detected by PVD 2.2 V */
#define LL_PWR_PVDLEVEL_3                  (PWR_CR2_PLS_LEV3)      /*!< Voltage threshold detected by PVD 2.4 V */
#define LL_PWR_PVDLEVEL_4                  (PWR_CR2_PLS_LEV4)      /*!< Voltage threshold detected by PVD 2.6 V */
#define LL_PWR_PVDLEVEL_5                  (PWR_CR2_PLS_LEV5)      /*!< Voltage threshold detected by PVD 2.8 V */
#define LL_PWR_PVDLEVEL_6                  (PWR_CR2_PLS_LEV6)      /*!< Voltage threshold detected by PVD 3.0 V */
#define LL_PWR_PVDLEVEL_7                  (PWR_CR2_PLS_LEV7)      /*!< Voltage threshold detected by extern IO input */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_PVDFILTER PVDFILTER
  * @{
  */
#define LL_PWR_PVD_FILTER_1CLOCK          (0x00000000u)                                                   /*!< PVD filter 1    clock */
#define LL_PWR_PVD_FILTER_2CLOCK          (                                          PWR_CR2_FLT_CTRL_0)  /*!< PVD filter 2    clock */
#define LL_PWR_PVD_FILTER_4CLOCK          (                     PWR_CR2_FLT_CTRL_1                     )  /*!< PVD filter 4    clock */
#define LL_PWR_PVD_FILTER_16CLOCK         (                     PWR_CR2_FLT_CTRL_1 | PWR_CR2_FLT_CTRL_0)  /*!< PVD filter 16   clock */
#define LL_PWR_PVD_FILTER_64CLOCK         (PWR_CR2_FLT_CTRL_2                                          )  /*!< PVD filter 64   clock */
#define LL_PWR_PVD_FILTER_128CLOCK        (PWR_CR2_FLT_CTRL_2                      | PWR_CR2_FLT_CTRL_0)  /*!< PVD filter 128  clock */
#define LL_PWR_PVD_FILTER_1024CLOCK       (PWR_CR2_FLT_CTRL_2 | PWR_CR2_FLT_CTRL_1                     )  /*!< PVD filter 1024 clock */
/**
  * @}
  */

/** @defgroup PWR_LL_EC_WAKEUP_PIN  Wakeup Pins
  * @{
  */
#define LL_PWR_WAKEUP_PIN1                 (PWR_CR3_EWUP1)         /*!< WKUP pin 1 */
#define LL_PWR_WAKEUP_PIN2                 (PWR_CR3_EWUP2)         /*!< WKUP pin 2 */
#define LL_PWR_WAKEUP_PIN3                 (PWR_CR3_EWUP3)         /*!< WKUP pin 3 */
#define LL_PWR_WAKEUP_PIN4                 (PWR_CR3_EWUP4)         /*!< WKUP pin 4 */
#define LL_PWR_WAKEUP_PIN5                 (PWR_CR3_EWUP5)         /*!< WKUP pin 5 */
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Macros PWR Exported Macros
  * @{
  */

/** @defgroup PWR_LL_EM_WRITE_READ Common write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in PWR register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_PWR_WriteReg(__REG__, __VALUE__) WRITE_REG(PWR->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PWR register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_PWR_ReadReg(__REG__) READ_REG(PWR->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PWR_LL_Exported_Functions PWR Exported Functions
  * @{
  */

/** @defgroup PWR_LL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Set the HSI turn on mode after wake up 
  * @rmtoll CR1           HSION_CTRL          LL_PWR_SetStopWakeUpHSIOnMode
  * @param  HsiOnMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_AFTER_MR
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_IMMEDIATE
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStopWakeUpHSIOnMode(uint32_t HsiOnMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_HSION_CTRL, HsiOnMode);
}

/**
  * @brief  Get the HSI turn on mode after wake up
  * @rmtoll CR1          HSION_CTRL          LL_PWR_GetStopWakeUpHSIOnMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_AFTER_MR
  *         @arg @ref LL_PWR_STOPWAKEUP_HSION_IMMEDIATE
  */
__STATIC_INLINE uint32_t LL_PWR_GetStopWakeUpHSIOnMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_HSION_CTRL));
}

/**
  * @brief  Set waiting time required after the standby mode is awakened and MR ready
  * @rmtoll CR1          STDBY_MRRDY_WAIT          LL_PWR_SetStandbyWakeUpMRReadyDelay
  * @param  WaitDelayTime This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_3US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_5US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_10US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_20US
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStandbyWakeUpMRReadyDelay(uint32_t WaitDelayTime)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_STDBY_MRRDY_WAIT, WaitDelayTime);
}

/**
  * @brief  Get waiting time required after the standby mode is awakened and MR ready
  * @rmtoll CR1          STDBY_MRRDY_WAIT          LL_PWR_GetStandbyWakeUpMRReadyDelay
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_3US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_5US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_10US
  *         @arg @ref LL_PWR_STANDBYWAKEUP_MRREADY_DELAY_20US
  */
__STATIC_INLINE uint32_t LL_PWR_GetStandbyWakeUpMRReadyDelay(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_STDBY_MRRDY_WAIT));
}

/**
  * @brief  Set the flash delay time after wake up 
  * @rmtoll CR1          FLS_WUPT          LL_PWR_SetStopWakeUpFlashDelay
  * @param  WaitDelayTime This parameter can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_3US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_5US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_2US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_0US
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetStopWakeUpFlashDelay(uint32_t WaitDelayTime)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_FLS_WUPT, WaitDelayTime);
}

/**
  * @brief  Get the flash delay time after wake up 
  * @rmtoll CR1          FLS_WUPT          LL_PWR_GetStopWakeUpFlashDelay
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_3US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_5US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_2US
  *         @arg @ref LL_PWR_STOPWAKEUP_FLASH_DELAY_0US
  */
__STATIC_INLINE uint32_t LL_PWR_GetStopWakeUpFlashDelay(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_FLS_WUPT));
}

/**
  * @brief  Set the voltage of SRAM2 in standby mode
  * @rmtoll CR1          SRAM_RETV         LL_PWR_SetSramVoltageInStandby
  * @param  VoltageLevel This parameter can be one of the following values:
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_HIGH
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_MEDIUM
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_MEDIUM_LOW
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_LOW
  */
__STATIC_INLINE void LL_PWR_SetSramVoltageInStandby(uint32_t VoltageLevel)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_SRAM_RETV, VoltageLevel);
}

/**
  * @brief  Get the voltage of SRAM2 in standby mode
  * @rmtoll CR1          SRAM_RETV         LL_PWR_GetSramVoltageInStandby
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_HIGH
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_MEDIUM
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_MEDIUM_LOW
  *         @arg @ref LL_PWR_SRAM2_VOLTAGE_LOW
  */
__STATIC_INLINE uint32_t LL_PWR_GetSramVoltageInStandby(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_SRAM_RETV));
}

/**
  * @brief  Set the VR output voltage level
  * @rmtoll CR1          VOS               LL_PWR_SetVrOutputVoltage
  * @param  VoltageLevel This parameter can be one of the following values:
  *         @arg @ref LL_PWR_REGU_VOLTAGE_HIGH
  *         @arg @ref LL_PWR_REGU_VOLTAGE_MEDIUM
  *         @arg @ref LL_PWR_REGU_VOLTAGE_MEDIUM_LOW
  *         @arg @ref LL_PWR_REGU_VOLTAGE_LOW
  */
__STATIC_INLINE void LL_PWR_SetRegulVoltageScaling(uint32_t VoltageLevel)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_VOS, VoltageLevel);
}

/**
  * @brief  Get the VR output voltage level
  * @rmtoll CR1          VOS               LL_PWR_GetVrOutputVoltage
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_REGU_VOLTAGE_HIGH
  *         @arg @ref LL_PWR_REGU_VOLTAGE_MEDIUM
  *         @arg @ref LL_PWR_REGU_VOLTAGE_MEDIUM_LOW
  *         @arg @ref LL_PWR_REGU_VOLTAGE_LOW
  */
__STATIC_INLINE uint32_t LL_PWR_GetRegulVoltageScaling(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_VOS));
}

/**
  * @brief  Enable the regulator from main mode to low-power mode
  * @rmtoll CR1          LPR           LL_PWR_EnableLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableLowPowerRunMode(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_LPR);
}

/**
  * @brief  Disable the regulator from low-power mode to main mode
  * @rmtoll CR1          LPR           LL_PWR_DisableLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableLowPowerRunMode(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_LPR);
}

/**
  * @brief  Check if the regulator is in low-power mode
  * @rmtoll CR1          LPR           LL_PWR_IsEnabledLowPowerRunMode
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledLowPowerRunMode(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_LPR)) ? 1U : 0U);
}

/**
  * @brief  Switch from run main mode to run low-power mode.
  * @rmtoll CR1          LPR           LL_PWR_EnterLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnterLowPowerRunMode(void)
{
  LL_PWR_EnableLowPowerRunMode();
}

/**
  * @brief  Switch from run main mode to low-power mode.
  * @rmtoll CR1          LPR           LL_PWR_ExitLowPowerRunMode
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ExitLowPowerRunMode(void)
{
  LL_PWR_DisableLowPowerRunMode();
}

/**
 * @brief  Enable access to the backup domain
 * @rmtoll CR1    DBP       LL_PWR_EnableBkUpAccess
 * @retval None
 */
__STATIC_INLINE void LL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Disable access to the backup domain
  * @rmtoll CR1    DBP       LL_PWR_DisableBkUpAccess
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
}

/**
  * @brief  Check if the backup domain is enabled
  * @rmtoll CR1    DBP       LL_PWR_IsEnabledBkUpAccess
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBkUpAccess(void)
{
  return (READ_BIT(PWR->CR1, PWR_CR1_DBP) == (PWR_CR1_DBP));
}

/**
  * @brief  Set Low-Power mode
  * @rmtoll CR1          LPMS          LL_PWR_SetPowerMode
  * @param  LowPowerMode This parameter can be one of the following values:
  *         @arg @ref LL_PWR_MODE_STOP0
  *         @arg @ref LL_PWR_MODE_STOP1
  *         @arg @ref LL_PWR_MODE_STANDBY
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPowerMode(uint32_t LowPowerMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, LowPowerMode);
}

/**
  * @brief  Get Low-Power mode
  * @rmtoll CR1          LPMS          LL_PWR_GetPowerMode
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_MODE_STOP0
  *         @arg @ref LL_PWR_MODE_STOP1
  *         @arg @ref LL_PWR_MODE_STANDBY
  */
__STATIC_INLINE uint32_t LL_PWR_GetPowerMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_LPMS));
}

/**
  * @brief  Enable SRAM content retention in Standby mode
  * @rmtoll CR3          RRS           LL_PWR_EnableSRAMRetention
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableSRAMRetention(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_RRS);
}

/**
  * @brief  Disable SRAM content retention in Standby mode
  * @rmtoll CR3          RRS           LL_PWR_DisableSRAMRetention
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableSRAMRetention(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_RRS);
}

/**
  * @brief  Check if SRAM content retention in Standby mode  is enabled
  * @rmtoll CR3          RRS           LL_PWR_IsEnabledSRAMRetention
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledSRAMRetention(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_RRS)) ? 1U : 0U);
}

/**
  * @brief  Enable the WakeUp PINx functionality
  * @rmtoll CR3   EWUP       LL_PWR_EnableWakeUpPin
  * @param  WakeUpPin This parameter can be a combination of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnableWakeUpPin(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR3, WakeUpPin);
}

/**
  * @brief  Disable the WakeUp PINx functionality
  * @rmtoll CR3   EWUP       LL_PWR_DisableWakeUpPin
  * @param  WakeUpPin This parameter can be a combination of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisableWakeUpPin(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR3, WakeUpPin);
}

/**
  * @brief  Check if the WakeUp PINx functionality is enabled
  * @rmtoll CR3   EWUP       LL_PWR_IsEnabledWakeUpPin
  * @param  WakeUpPin This parameter can be a combination of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledWakeUpPin(uint32_t WakeUpPin)
{
  return (READ_BIT(PWR->CR3, WakeUpPin) == (WakeUpPin));
}

/**
  * @brief  Set the Wake-Up pin polarity low for the event detection
  * @rmtoll CR4          WP1           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP2           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP3           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP4           LL_PWR_SetWakeUpPinPolarityLow\n
  *         CR4          WP5           LL_PWR_SetWakeUpPinPolarityLow
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  * @retval None
  */
/**
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR4, WakeUpPin);
}
  */

/**
  * @brief  Set the Wake-Up pin polarity high for the event detection
  * @rmtoll CR4          WP1           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP2           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP3           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP4           LL_PWR_SetWakeUpPinPolarityHigh\n
  *         CR4          WP5           LL_PWR_SetWakeUpPinPolarityHigh
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityHigh(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR4, WakeUpPin);
}

/**
  * @brief  Get the Wake-Up pin polarity for the event detection
  * @rmtoll CR4          WP1           LL_PWR_IsWakeUpPinPolarity\n
  *         CR4          WP2           LL_PWR_IsWakeUpPinPolarity\n
  *         CR4          WP3           LL_PWR_IsWakeUpPinPolarity\n
  *         CR4          WP4           LL_PWR_IsWakeUpPinPolarity\n
  *         CR4          WP5           LL_PWR_IsWakeUpPinPolarity
  * @param  WakeUpPin This parameter can be one of the following values:
  *         @arg @ref LL_PWR_WAKEUP_PIN1
  *         @arg @ref LL_PWR_WAKEUP_PIN2
  *         @arg @ref LL_PWR_WAKEUP_PIN3
  *         @arg @ref LL_PWR_WAKEUP_PIN4
  *         @arg @ref LL_PWR_WAKEUP_PIN5
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsWakeUpPinPolarity(uint32_t WakeUpPin)
{
  return ((READ_BIT(PWR->CR4, WakeUpPin)) ? 1U : 0U);
}

/**
  * @}
  */


/** @defgroup PWR_LL_EF_PVD_Management PVD_Management
  * @{
  */

/**
  * @brief  Set the voltage threshold detected by the Power Voltage Detector
  * @rmtoll CR2    PLS       LL_PWR_SetPVDLevel
  * @param  PVDLevel This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVDLEVEL_3
  *         @arg @ref LL_PWR_PVDLEVEL_4
  *         @arg @ref LL_PWR_PVDLEVEL_5
  *         @arg @ref LL_PWR_PVDLEVEL_6
  *         @arg @ref LL_PWR_PVDLEVEL_7
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPVDLevel(uint32_t PVDLevel)
{
  MODIFY_REG(PWR->CR2, PWR_CR2_PLS, PVDLevel);
}

/**
  * @brief  Get the voltage threshold detection
  * @rmtoll CR2    PLS       LL_PWR_GetPVDLevel
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_PVDLEVEL_3
  *         @arg @ref LL_PWR_PVDLEVEL_4
  *         @arg @ref LL_PWR_PVDLEVEL_5
  *         @arg @ref LL_PWR_PVDLEVEL_6
  *         @arg @ref LL_PWR_PVDLEVEL_7
  */
__STATIC_INLINE uint32_t LL_PWR_GetPVDLevel(void)
{
  return (uint32_t)(READ_BIT(PWR->CR2, PWR_CR2_PLS));
}

/**
  * @brief  Enable Power Voltage Detector
  * @rmtoll CR2    PVDE       LL_PWR_EnablePVD
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Disable Power Voltage Detector
  * @rmtoll CR2    PVDE       LL_PWR_DisablePVD
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_PVDE);
}

/**
  * @brief  Check if Power Voltage Detector is enabled
  * @rmtoll CR2    PVDE       LL_PWR_IsEnabledPVD
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVD(void)
{
  return (READ_BIT(PWR->CR2, PWR_CR2_PVDE) == (PWR_CR2_PVDE));
}

/**
  * @brief  Enable PVD Filter
  * @rmtoll CR2          FLTEN          LL_PWR_EnablePVDFilter
  * @retval None
  */
__STATIC_INLINE void LL_PWR_EnablePVDFilter(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_FLTEN);
}

/**
  * @brief  Disable PVD Filter
  * @rmtoll CR2          FLTEN          LL_PWR_DisablePVDFilter
  * @retval None
  */
__STATIC_INLINE void LL_PWR_DisablePVDFilter(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_FLTEN);
}

/**
  * @brief  Check if PVD Filter is enabled
  * @rmtoll CR2          FLTEN          LL_PWR_IsEnabledPVDFilter
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVDFilter(void)
{
  return (READ_BIT(PWR->CR2, PWR_CR2_FLTEN) == (PWR_CR2_FLTEN));
}

/**
  * @brief  Set PVD detection power supply selection
  * @rmtoll CR2          FLT_CTRL          LL_PWR_SetPVDFilter
  * @param  PVDFilter This parameter can be one of the following values:
  *         @arg @ref LL_PWR_PVD_FILTER_1CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_2CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_4CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_16CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_64CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_128CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_1024CLOCK
  * @retval None
  */
__STATIC_INLINE void LL_PWR_SetPVDFilter(uint32_t PVDFilter)
{
  MODIFY_REG(PWR->CR2, PWR_CR2_FLT_CTRL, PVDFilter);
}

/**
  * @brief  Get PVD detection power supply 
  * @rmtoll CR2          FLT_CTRL          LL_PWR_GetPVDFilter
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_PWR_PVD_FILTER_1CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_2CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_4CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_16CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_64CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_128CLOCK
  *         @arg @ref LL_PWR_PVD_FILTER_1024CLOCK
  */
__STATIC_INLINE uint32_t LL_PWR_GetPVDFilter(void)
{
  return (uint32_t)(READ_BIT(PWR->CR2, PWR_CR2_FLT_CTRL));
}
/**
  * @}
  */

/** @defgroup PWR_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Stand-By Flag
  * @rmtoll SR          SBF           LL_PWR_IsActiveFlag_SB
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_SB(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_SBF)) ? 1U : 0U);
}

/**
  * @brief  Get Wake-up Flag 5
  * @rmtoll SR          WUF5          LL_PWR_IsActiveFlag_WU5
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU5(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_WUF5)) ? 1U : 0U);
}

/**
  * @brief  Get Wake-up Flag 4
  * @rmtoll SR          WUF4          LL_PWR_IsActiveFlag_WU4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU4(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_WUF4)) ? 1U : 0U);
}

/**
  * @brief  Get Wake-up Flag 3
  * @rmtoll SR          WUF3          LL_PWR_IsActiveFlag_WU3
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU3(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_WUF3)) ? 1U : 0U);
}

/**
  * @brief  Get Wake-up Flag 2
  * @rmtoll SR          WUF2          LL_PWR_IsActiveFlag_WU2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU2(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_WUF2)) ? 1U : 0U);
}

/**
  * @brief  Get Wake-up Flag 1
  * @rmtoll SR          WUF1          LL_PWR_IsActiveFlag_WU1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU1(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_WUF1)) ? 1U : 0U);
}

/**
  * @brief  Indicate whether the regulator is ready in main mode or is in low-power mode
  * @note: Take care, return value "1" means the main regulator is ready. Return value "0" means the main regulator is not ready.
  * @rmtoll SR          MR_RDY        LL_PWR_IsActiveFlag_MR_RDY
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_MR_RDY(void)
{
  return ((READ_BIT(PWR->SR, PWR_SR_MR_RDY)) ? 1U : 0U);
}

/**
  * @brief  Indicate whether VDD voltage is below or above the selected PVD threshold
  * @rmtoll SR          PVDO          LL_PWR_IsActiveFlag_PVDO
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVDO(void)
{
 return ((READ_BIT(PWR->SR, PWR_SR_PVDO)) ? 1U : 0U);
}

/**
  * @brief  Clear Stand-By Flag
  * @rmtoll SCR          CSBF          LL_PWR_ClearFlag_SB
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_SB(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CSBF);
}

/**
  * @brief  Clear Wake-up Flags
  * @rmtoll SCR          CWUF          LL_PWR_ClearFlag_WU
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF);
}

/**
  * @brief  Clear Wake-up Flag 5
  * @rmtoll SCR          CWUF5         LL_PWR_ClearFlag_WU5
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU5(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF5);
}

/**
  * @brief  Clear Wake-up Flag 4
  * @rmtoll SCR          CWUF4         LL_PWR_ClearFlag_WU4
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU4(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF4);
}

/**
  * @brief  Clear Wake-up Flag 3
  * @rmtoll SCR          CWUF3         LL_PWR_ClearFlag_WU3
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU3(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF3);
}

/**
  * @brief  Clear Wake-up Flag 2
  * @rmtoll SCR          CWUF2         LL_PWR_ClearFlag_WU2
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU2(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF2);
}

/**
  * @brief  Clear Wake-up Flag 1
  * @rmtoll SCR          CWUF1         LL_PWR_ClearFlag_WU1
  * @retval None
  */
__STATIC_INLINE void LL_PWR_ClearFlag_WU1(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF1);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PWR_LL_EF_Init De-initialization function
  * @{
  */
ErrorStatus LL_PWR_DeInit(void);
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

#endif /* defined(PWR) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_LL_PWR_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

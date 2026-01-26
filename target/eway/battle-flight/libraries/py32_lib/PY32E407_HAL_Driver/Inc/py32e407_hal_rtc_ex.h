/**
  ******************************************************************************
  * @file    py32e407_hal_rtc_ex.h
  * @author  MCU Application Team
  * @brief   Header file of RTC HAL Extension module.
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
#ifndef __PY32E407_HAL_RTC_EX_H
#define __PY32E407_HAL_RTC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup RTCEx
  * @{
  */

/** @addtogroup RTCEx_Private_Macros
  * @{
  */
/** @defgroup RTCEx_IS_RTC_Definitions Private macros to check input parameters
  * @{
  */
#define IS_RTC_TAMPER(__TAMPER__) ((__TAMPER__) == RTC_TAMPER_1)

#define IS_RTC_TAMPER_TRIGGER(__TRIGGER__)  (((__TRIGGER__) == RTC_TAMPERTRIGGER_LOWLEVEL) || \
                                             ((__TRIGGER__) == RTC_TAMPERTRIGGER_HIGHLEVEL))

#define IS_RTC_BKP(BKP)                   ((BKP) <= (uint32_t)RTC_BKP_DR31)
#define IS_RTC_SMOOTH_CALIB_MINUS(__VALUE__) ((__VALUE__) <= 0x0000007FU)

/**
  * @}
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup RTCEx_Exported_Types RTCEx Exported Types
  * @{
  */
/**
  * @brief  RTC Tamper structure definition
  */
typedef struct
{
  uint32_t Tamper;                      /*!< Specifies the Tamper Pin.
                                             This parameter can be a value of @ref  RTCEx_Tamper_Pins_Definitions */

  uint32_t Trigger;                     /*!< Specifies the Tamper Trigger.
                                             This parameter can be a value of @ref  RTCEx_Tamper_Trigger_Definitions */

} RTC_TamperTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RTCEx_Exported_Constants RTCEx Exported Constants
  * @{
  */

/** @defgroup RTCEx_Tamper_Pins_Definitions Tamper Pins Definitions
  * @{
  */
#define RTC_TAMPER_1                        BKP_CR_TPE            /*!< Select tamper to be enabled */

/**
  * @}
  */

/** @defgroup RTCEx_Tamper_Trigger_Definitions Tamper Trigger Definitions
  * @{
  */
#define RTC_TAMPERTRIGGER_LOWLEVEL          BKP_CR_TPAL           /*!< A low level on the TAMPER pin resets all data backup registers (if TPE bit is set) */
#define RTC_TAMPERTRIGGER_HIGHLEVEL         0x00000000U           /*!< A high level on the TAMPER pin resets all data backup registers (if TPE bit is set) */

/**
  * @}
  */

/** @defgroup RTCEx_Backup_Registers_Definitions Backup Registers Definitions
  * @{
  */
#define RTC_BKP_DR0                         0x00000000U
#define RTC_BKP_DR1                         0x00000001U
#define RTC_BKP_DR2                         0x00000002U
#define RTC_BKP_DR3                         0x00000003U
#define RTC_BKP_DR4                         0x00000004U
#define RTC_BKP_DR5                         0x00000005U
#define RTC_BKP_DR6                         0x00000006U
#define RTC_BKP_DR7                         0x00000007U
#define RTC_BKP_DR8                         0x00000008U
#define RTC_BKP_DR9                         0x00000009U
#define RTC_BKP_DR10                        0x0000000AU
#define RTC_BKP_DR11                        0x0000000BU
#define RTC_BKP_DR12                        0x0000000CU
#define RTC_BKP_DR13                        0x0000000DU
#define RTC_BKP_DR14                        0x0000000EU
#define RTC_BKP_DR15                        0x0000000FU
#define RTC_BKP_DR16                        0x00000010U
#define RTC_BKP_DR17                        0x00000011U
#define RTC_BKP_DR18                        0x00000012U
#define RTC_BKP_DR19                        0x00000013U
#define RTC_BKP_DR20                        0x00000014U
#define RTC_BKP_DR21                        0x00000015U
#define RTC_BKP_DR22                        0x00000016U
#define RTC_BKP_DR23                        0x00000017U
#define RTC_BKP_DR24                        0x00000018U
#define RTC_BKP_DR25                        0x00000019U
#define RTC_BKP_DR26                        0x0000001AU
#define RTC_BKP_DR27                        0x0000001BU
#define RTC_BKP_DR28                        0x0000001CU
#define RTC_BKP_DR29                        0x0000001DU
#define RTC_BKP_DR30                        0x0000001EU
#define RTC_BKP_DR31                        0x0000001FU

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RTCEx_Exported_Macros RTCEx Exported Macros
  * @{
  */

/**
  * @brief  Enable the RTC Tamper interrupt.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Tamper interrupt sources to be enabled
  *          This parameter can be any combination of the following values:
  *            @arg RTC_IT_TAMP1: Tamper A interrupt
  * @retval None
  */
#define __HAL_RTC_TAMPER_ENABLE_IT(__HANDLE__, __INTERRUPT__) SET_BIT(BKP->CSR, (__INTERRUPT__))

/**
  * @brief  Disable the RTC Tamper interrupt.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Tamper interrupt sources to be disabled.
  *         This parameter can be any combination of the following values:
  *            @arg RTC_IT_TAMP1: Tamper A interrupt
  * @retval None
  */
#define __HAL_RTC_TAMPER_DISABLE_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT(BKP->CSR, (__INTERRUPT__))

/**
  * @brief  Check whether the specified RTC Tamper interrupt has been enabled or not.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Tamper interrupt sources to be checked.
  *         This parameter can be:
  *            @arg  RTC_IT_TAMP1
  * @retval None
  */
#define __HAL_RTC_TAMPER_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)    ((((BKP->CSR) & ((__INTERRUPT__))) != RESET)? SET : RESET)

/**
  * @brief  Get the selected RTC Tamper's flag status.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __FLAG__: specifies the RTC Tamper Flag sources to be enabled or disabled.
  *         This parameter can be:
  *            @arg RTC_FLAG_TAMP1F
  * @retval None
  */
#define __HAL_RTC_TAMPER_GET_FLAG(__HANDLE__, __FLAG__)       ((((BKP->CSR) & (__FLAG__)) != RESET)? SET : RESET)

/**
  * @brief  Get the selected RTC Tamper's flag status.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Tamper interrupt sources to be checked.
  *         This parameter can be:
  *            @arg  RTC_IT_TAMP1
  * @retval None
  */
#define __HAL_RTC_TAMPER_GET_IT(__HANDLE__, __INTERRUPT__)       ((((BKP->CSR) & (BKP_CSR_TEF)) != RESET)? SET : RESET)

/**
  * @brief  Clear the RTC Tamper's pending flags.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __FLAG__: specifies the RTC Tamper Flag sources to be enabled or disabled.
  *         This parameter can be:
  *            @arg RTC_FLAG_TAMP1F
  * @retval None
  */
#define __HAL_RTC_TAMPER_CLEAR_FLAG(__HANDLE__, __FLAG__)     SET_BIT(BKP->CSR, BKP_CSR_CTE | BKP_CSR_CTI)

/**
  * @brief  Enable the RTC Second interrupt.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Second interrupt sources to be enabled
  *          This parameter can be any combination of the following values:
  *            @arg RTC_IT_SEC: Second A interrupt
  * @retval None
  */
#define __HAL_RTC_SECOND_ENABLE_IT(__HANDLE__, __INTERRUPT__)  SET_BIT((__HANDLE__)->Instance->CRH, (__INTERRUPT__))

/**
  * @brief  Disable the RTC Second interrupt.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Second interrupt sources to be disabled.
  *         This parameter can be any combination of the following values:
  *            @arg RTC_IT_SEC: Second A interrupt
  * @retval None
  */
#define __HAL_RTC_SECOND_DISABLE_IT(__HANDLE__, __INTERRUPT__) CLEAR_BIT((__HANDLE__)->Instance->CRH, (__INTERRUPT__))

/**
  * @brief  Check whether the specified RTC Second interrupt has occurred or not.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Second interrupt sources to be enabled or disabled.
  *         This parameter can be:
  *            @arg RTC_IT_SEC: Second A interrupt
  * @retval None
  */
#define __HAL_RTC_SECOND_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->CRH, \
                                                                        (((((__HANDLE__)->Instance->CRH)& ((__INTERRUPT__)))) != RESET)? SET : RESET)

/**
  * @brief  Get the selected RTC Second's flag status.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __FLAG__: specifies the RTC Second Flag sources to be enabled or disabled.
  *          This parameter can be:
  *            @arg RTC_FLAG_SEC
  * @retval None
  */
#define __HAL_RTC_SECOND_GET_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->CRL, \
                                                                ((((__HANDLE__)->Instance->CRL) & (__FLAG__)) != RESET)? SET : RESET)

/**
  * @brief  Clear the RTC Second's pending flags.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __FLAG__: specifies the RTC Second Flag sources to be enabled or disabled.
  *         This parameter can be:
  *            @arg RTC_FLAG_SEC
  * @retval None
  */
#define __HAL_RTC_SECOND_CLEAR_FLAG(__HANDLE__, __FLAG__)      ((__HANDLE__)->Instance->CRL) = ~(__FLAG__)

/**
  * @brief  Enable the RTC Overflow interrupt.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Overflow interrupt sources to be enabled
  *          This parameter can be any combination of the following values:
  *            @arg RTC_IT_OW: Overflow A interrupt
  * @retval None
  */
#define __HAL_RTC_OVERFLOW_ENABLE_IT(__HANDLE__, __INTERRUPT__)  SET_BIT((__HANDLE__)->Instance->CRH, (__INTERRUPT__))

/**
  * @brief  Disable the RTC Overflow interrupt.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Overflow interrupt sources to be disabled.
  *         This parameter can be any combination of the following values:
  *            @arg RTC_IT_OW: Overflow A interrupt
  * @retval None
  */
#define __HAL_RTC_OVERFLOW_DISABLE_IT(__HANDLE__, __INTERRUPT__) CLEAR_BIT((__HANDLE__)->Instance->CRH, (__INTERRUPT__))

/**
  * @brief  Check whether the specified RTC Overflow interrupt has occurred or not.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __INTERRUPT__: specifies the RTC Overflow interrupt sources to be enabled or disabled.
  *         This parameter can be:
  *            @arg RTC_IT_OW: Overflow A interrupt
  * @retval None
  */
#define __HAL_RTC_OVERFLOW_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->CRH, \
                                                                        (((((__HANDLE__)->Instance->CRH)& ((__INTERRUPT__))) ) != RESET)? SET : RESET)

/**
  * @brief  Get the selected RTC Overflow's flag status.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __FLAG__: specifies the RTC Overflow Flag sources to be enabled or disabled.
  *          This parameter can be:
  *            @arg RTC_FLAG_OW
  * @retval None
  */
#define __HAL_RTC_OVERFLOW_GET_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->CRL, \
                                                                  ((((__HANDLE__)->Instance->CRL) & (__FLAG__)) != RESET)? SET : RESET)

/**
  * @brief  Clear the RTC Overflow's pending flags.
  * @param  __HANDLE__: specifies the RTC handle.
  * @param  __FLAG__: specifies the RTC Overflow Flag sources to be enabled or disabled.
  *         This parameter can be:
  *            @arg RTC_FLAG_OW
  * @retval None
  */
#define __HAL_RTC_OVERFLOW_CLEAR_FLAG(__HANDLE__, __FLAG__)      ((__HANDLE__)->Instance->CRL) = ~(__FLAG__)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RTCEx_Exported_Functions
  * @{
  */

/* RTC Tamper functions *****************************************/
/** @addtogroup RTCEx_Exported_Functions_Group1
  * @{
  */
HAL_StatusTypeDef HAL_RTCEx_SetTamper(RTC_HandleTypeDef *hrtc, RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_SetTamper_IT(RTC_HandleTypeDef *hrtc, RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTamper(RTC_HandleTypeDef *hrtc, uint32_t Tamper);
void              HAL_RTCEx_TamperIRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_Tamper1EventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForTamper1Event(RTC_HandleTypeDef *hrtc, uint32_t Timeout);

/**
  * @}
  */

/* RTC Second functions *****************************************/
/** @addtogroup RTCEx_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef HAL_RTCEx_SetSecond_IT(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateSecond(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_RTCIRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_RTCEventCallback(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_RTCEventErrorCallback(RTC_HandleTypeDef *hrtc);

/**
  * @}
  */

/* Extension Control functions ************************************************/
/** @addtogroup RTCEx_Exported_Functions_Group3
  * @{
  */
void              HAL_RTCEx_BKUPWrite(RTC_HandleTypeDef *hrtc, uint32_t BackupRegister, uint32_t Data);
uint32_t          HAL_RTCEx_BKUPRead(RTC_HandleTypeDef *hrtc, uint32_t BackupRegister);

HAL_StatusTypeDef HAL_RTCEx_SetSmoothCalib(RTC_HandleTypeDef *hrtc, uint32_t SmoothCalibPeriod, uint32_t SmoothCalibPlusPulses, uint32_t SmouthCalibMinusPulsesValue);
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

#endif /* __PY32E407_HAL_RTC_EX_H */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

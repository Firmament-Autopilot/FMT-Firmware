/**
  ******************************************************************************
  * @file    py32e407_hal_opa.h
  * @author  MCU Application Team
  * @brief   Header file of OPA HAL module.
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
#ifndef PY32E407_HAL_OPA_H
#define PY32E407_HAL_OPA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e407_hal_def.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @addtogroup OPA
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup OPA_Exported_Types OPA Exported Types
  * @{
  */

/**
  * @brief  OPA Init structure definition
  */

typedef struct
{
  uint32_t PowerMode;                   /*!< Specifies the power mode Normal or High Speed.
                                             This parameter must be a value of @ref OPA_PowerMode */

  uint32_t Mode;                        /*!< Specifies the OPA mode
                                             This parameter must be a value of @ref OPA_Mode
                                             mode is either Standalone, Follower or PGA */

  uint32_t InvertingInput;              /*!< Specifies the inverting input in Standalone & Pga modes
                                               - In Standalone mode:   i.e when mode is OPA_STANDALONE_MODE
                                                 This parameter must be a value of @ref OPA_InvertingInput
                                                 InvertingInput is either VINM0 or VINM1
                                               - In PGA mode:          i.e when mode is OPA_PGA_MODE
                                                 & in Follower mode    i.e when mode is OPA_FOLLOWER_MODE
                                                 This parameter is Not Applicable */

  uint32_t NonInvertingInput;           /*!< Specifies the non inverting input of the opa:
                                             This parameter must be a value of @ref OPA_NonInvertingInput
                                             NonInvertingInput is either VINP0, VINP1, VINP2 or VINP3 */

  FunctionalState InternalOutput;       /*!< Specifies the configuration of the internal output from OPA to ADC.
                                             This parameter can be ENABLE or DISABLE
                                             Note: When this output is enabled, regular output to I/O is disabled */

  uint32_t TimerControlledMuxmode;      /*!< Specifies if the Timer controlled Mux mode is enabled or disabled
                                             This parameter must be a single value of @ref OPA_TimerControlledMuxmode
                                             or a combination of them to build a more complex switch scheme by
                                             using different timers */

  uint32_t InvertingInputSecondary;     /*!< Specifies the inverting input (secondary) of the opa when
                                             TimerControlledMuxmode is enabled
                                             i.e. when TimerControlledMuxmode is OPA_TIMERCONTROLLEDMUXMODE_ENABLE
                                               - In Standalone mode:   i.e when mode is OPA_STANDALONE_MODE
                                                 This parameter must be a value of @ref OPA_InvertingInputSecondary
                                                 InvertingInputSecondary is either VINM0 or VINM1
                                               - In PGA mode:          i.e when mode is OPA_PGA_MODE
                                                 & in Follower mode    i.e when mode is OPA_FOLLOWER_MODE
                                                 This parameter must be a value of @ref OPA_InvertingInputSecondary
                                                 and is used to choose secondary mode (PGA or follower) */

  uint32_t NonInvertingInputSecondary;  /*!< Specifies the non inverting input (secondary) of the opa when
                                             TimerControlledMuxmode is enabled
                                             i.e. when TimerControlledMuxmode is OPA_TIMERCONTROLLEDMUXMODE_ENABLE
                                             This parameter must be a value of @ref OPA_NonInvertingInputSecondary
                                             NonInvertingInput is either VINP0, VINP1, VINP2 or VINP3 */

  uint32_t PgaConnect;                  /*!< Specifies the inverting pin in PGA mode
                                             i.e. when mode is OPA_PGA_MODE
                                             This parameter must be a value of @ref OPA_PgaConnect
                                             Either: not connected, connected to VINM0
                                             In this last case, VINM0 can then be used to input signal (negative gain case
                                             with or without bias on VINPx) or to input bias (positive gain case with bias) */

  uint32_t PgaGain;                     /*!< Specifies the gain in PGA mode
                                             i.e. when mode is OPA_PGA_MODE.
                                             This parameter must be a value of @ref OPA_PgaGain
                                             (2, 4, 8, 16, 32 or 64) for positive gain & (-1, -3 ,-7, -15, -31 or -63) for negative gain */


  uint32_t VoltageBuildIn;             /*!< Specifies the Voltage Build In   
                                            This parameter must be a value of @ref OPA_VoltageBuildIn */


} OPA_InitTypeDef;

/**
  * @brief  HAL State structures definition
  */

typedef enum
{
  HAL_OPA_STATE_RESET               = 0x00000000UL, /*!< OPA is not yet Initialized          */

  HAL_OPA_STATE_READY               = 0x00000001UL, /*!< OPA is initialized and ready for use */
  HAL_OPA_STATE_CALIBBUSY           = 0x00000002UL, /*!< OPA is enabled in auto calibration mode */

  HAL_OPA_STATE_BUSY                = 0x00000004UL, /*!< OPA is enabled and running in normal mode */
  HAL_OPA_STATE_BUSYLOCKED          = 0x00000005UL, /*!< OPA control register is locked
                                                         only system reset allows reconfiguring the opa. */

} HAL_OPA_StateTypeDef;

/**
  * @brief OPA Handle Structure definition
  */
#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
typedef struct __OPA_HandleTypeDef
#else
typedef struct
#endif
{
  OPA_TypeDef       *Instance;                    /*!< OPA instance's registers base address   */
  OPA_InitTypeDef   Init;                         /*!< OPA required parameters */
  HAL_StatusTypeDef Status;                         /*!< OPA peripheral status   */
  HAL_LockTypeDef   Lock;                           /*!< Locking object          */
  __IO HAL_OPA_StateTypeDef  State;               /*!< OPA communication state */

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __OPA_HandleTypeDef *hopa);
  void (* MspDeInitCallback)(struct __OPA_HandleTypeDef *hopa);
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

} OPA_HandleTypeDef;

#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL OPA Callback ID enumeration definition
  */
typedef enum
{
  HAL_OPA_MSPINIT_CB_ID                     = 0x01UL,  /*!< OPA MspInit Callback ID           */
  HAL_OPA_MSPDEINIT_CB_ID                   = 0x02UL,  /*!< OPA MspDeInit Callback ID         */
  HAL_OPA_ALL_CB_ID                          = 0x03UL   /*!< OPA All ID                        */
} HAL_OPA_CallbackIDTypeDef;

/**
  * @brief  HAL OPA Callback pointer definition
  */
typedef void (*pOPA_CallbackTypeDef)(OPA_HandleTypeDef *hopa);
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup OPA_Exported_Constants OPA Exported Constants
  * @{
  */
/** @defgroup OPA_Mode OPA Mode
  * @{
  */
#define OPA_STANDALONE_MODE            (0x00000000UL)        /*!< standalone mode */
#define OPA_CURRENTSAMPLE_MODE         (0x00000001UL)        /*!< current sample mode */
#define OPA_PGA_MODE                   OPA_CSR_VM_SEL_1      /*!< PGA mode */
/* #define OPA_FOLLOWER_MODE              OPA_CSR_VM_SEL    */    /*!< follower mode */
/**
  * @}
  */

/** @defgroup OPA_NonInvertingInput OPA Non Inverting Input
  * @{
  */
#define OPA_NONINVERTINGINPUT_IO0         (0x00000000UL)        /*!< Non inverting input connected to I/O VINP0
                                                                       (PA1  for OPA1, PA7  for OPA2, PB0  for OPA3) */

#define OPA_NONINVERTINGINPUT_IO1         OPA_CSR_VP_SEL_0     /*!< Non inverting input connected to I/O VINP1
                                                                       (PA3  for OPA1, PB14 for OPA2, PB13 for OPA3) */

#define OPA_NONINVERTINGINPUT_IO2         OPA_CSR_VP_SEL_1     /*!< Non inverting input connected to I/O VINP2
                                                                       (PA7  for OPA1, PB0  for OPA2, PA1  for OPA3) */
 
#define OPA_NONINVERTINGINPUT_IO3         OPA_CSR_VP_SEL       /*!< Non inverting input connected to I/O VINP3
                                                                       (PD14 for OPA2) */
#define OPA_NONINVERTINGINPUT_DAC         OPA_CSR_VP_SEL       /*!< Non inverting input connected internally to DAC channel
                                                                       (DAC1_CH1 for OPA1, DAC2_CH1  for OPA3)*/
/**
  * @}
  */

/** @defgroup OPA_InvertingInput OPA Inverting Input
  * @{
  */
#define OPA_INVERTINGINPUT_IO0       (0x00000000UL)              /*!< Inverting input connected to I/O VINM0
                                                                       (PA3  for OPA1, PA5  for OPA2, PB2  for OPA3) */
                                                                    
#define OPA_INVERTINGINPUT_IO1       OPA_CSR_VM_SEL_0           /*!< Inverting input connected to I/0 VINM1
                                                                       (PC5  for OPA1, PC5  for OPA2, PB10 for OPA3) */                                     
/**
  * @}
  */

/** @defgroup OPA_VoltageBuildIn OPA Voltage Build In
  * @{
  */
#define OPA_VOLTAGEBUILDIN_VCC_DIV2       (OPA_CSR_OPA_VBIAS_0 )              
                                                                    
#define OPA_VOLTAGEBUILDIN_VCC_DIV5       (OPA_CSR_OPA_VBIAS_1 )     

#define OPA_VOLTAGEBUILDIN_DISABLE        (0x00000000)    
/**
  * @}
  */

/** @defgroup OPA_TimerControlledMuxmode OPA Timer Controlled Mux mode
  * @note The switch can be controlled either by a single timer or a combination of them,
  *       in this case application has to 'ORed' the values below
  *       ex OPA_TIMERCONTROLLEDMUXMODE_TIM1_CH6 
  * @{
  */
#define OPA_TIMERCONTROLLEDMUXMODE_DISABLE    (0x00000000UL)      /*!< Timer controlled Mux mode disabled */
#define OPA_TIMERCONTROLLEDMUXMODE_TIM1_CH6   OPA_TCMR_T1CM_EN    /*!< Timer controlled Mux mode enabled using TIM1 OC6 */
#define OPA_TIMERCONTROLLEDMUXMODE_TIM8_CH6   OPA_TCMR_T8CM_EN    /*!< Timer controlled Mux mode enabled using TIM8 OC6 */
/**
  * @}
  */

/** @defgroup OPA_NonInvertingInputSecondary OPA Non Inverting Input Secondary
  * @{
  */
#define OPA_SEC_NONINVERTINGINPUT_IO0         (0x00000000UL)       /*!< Secondary non inverting input connected to I/O VINP0
                                                                           (PA1  for OPA1, PA7  for OPA2, PB0  for OPA3)*/

#define OPA_SEC_NONINVERTINGINPUT_IO1         OPA_TCMR_VPS_SEL_0   /*!< Secondary non inverting input connected to I/O VINP1
                                                                           (PA3  for OPA1, PB14 for OPA2, PB13 for OPA3) */

#define OPA_SEC_NONINVERTINGINPUT_IO2         OPA_TCMR_VPS_SEL_1   /*!< Secondary non inverting input connected to I/O VINP2
                                                                           (PA7  for OPA1, PB0  for OPA2, PA1  for OPA3) */

#define OPA_SEC_NONINVERTINGINPUT_IO3         OPA_TCMR_VPS_SEL     /*!< Secondary non inverting input connected to I/O VINP3
                                                                           (PD14 for OPA2) */
#define OPA_SEC_NONINVERTINGINPUT_DAC         OPA_TCMR_VPS_SEL     /*!< Secondary non inverting input connected internally to DAC channel
                                                                           (DAC1_CH1 for OPA1, DAC2_CH1  for OPA3) */
/**
  * @}
  */

/** @defgroup OPA_InvertingInputSecondary OPA Inverting Input Secondary
  * @{
  */
#define OPA_SEC_INVERTINGINPUT_IO0       (0x00000000UL)              /*!< OPA secondary mode is standalone mode - Only applicable if @ref OPA_STANDALONE_MODE
                                                                            has been configured by call to @ref HAL_OPA_Init().
                                                                            Secondary inverting input connected to I/O VINM0
                                                                            (PA3  for OPA1, PA5  for OPA2, PB2  for OPA3) */

#define OPA_SEC_INVERTINGINPUT_IO1       OPA_TCMR_VMS_SEL           /*!< OPA secondary mode is standalone mode - Only applicable if @ref OPA_STANDALONE_MODE
                                                                            has been configured by call to @ref HAL_OPA_Init().
                                                                            Secondary inverting input connected to I/0 VINM1
                                                                            (PC5  for OPA1, PC5  for OPA2, PB10 for OPA3) */

#define OPA_SEC_INVERTINGINPUT_PGA       (0x00000000UL)              /*!< OPA secondary mode is PGA mode - Only applicable if configured mode through call to @ref HAL_OPA_Init()
                                                                           is @ref OPA_PGA_MODE or @ref OPA_FOLLOWER_MODE.
                                                                           OPA secondary inverting input is:
                                                                             - Not connected if configured mode is @ref OPA_FOLLOWER_MODE
                                                                             - Not connected if configured mode is @ref OPA_PGA_MODE and PGA connect mode is @ref OPA_PGA_CONNECT_INVERTINGINPUT_NO
                                                                             - Connected to VINM0 and possibly VINM1 if any of the other modes as been configured
                                                                           (see @ref OPA_PgaConnect description for more details on PGA connection modes) */
/* #define OPA_SEC_INVERTINGINPUT_FOLLOWER  OPA_TCMR_VMS_SEL     */      /*!< OPA secondary mode is Follower mode - Only applicable if configured mode through call to @ref HAL_OPA_Init()
                                                                           is @ref OPA_PGA_MODE or @ref OPA_FOLLOWER_MODE.
                                                                           OPA secondary inverting input is not connected. */
/**
  * @}
  */

/** @defgroup OPA_PgaConnect OPA Pga Connect
  * @{
  */
#define OPA_PGA_CONNECT_INVERTINGINPUT_NO               (0x00000000UL)                            /*!< In PGA mode, the inverting input is not connected */
#define OPA_PGA_CONNECT_INVERTINGINPUT_IO0              OPA_CSR_PGA_GAIN_4                        /*!< In PGA mode, the inverting input is connected to VINM0 for filtering */
#define OPA_PGA_CONNECT_INVERTINGINPUT_IO0_BIAS         OPA_CSR_PGA_GAIN_3                        /*!< In PGA mode, the inverting input is connected to VINM0
                                                                                                      - Input signal on VINM0, bias on VINPx: negative gain
                                                                                                      - Bias on VINM0, input signal on VINPx: positive gain */
#define OPA_PGA_CONNECT_INVERTINGINPUT_IO0_IO1_BIAS     (OPA_CSR_PGA_GAIN_4|OPA_CSR_PGA_GAIN_3)   /*!< In PGA mode, the inverting input is connected to VINM0
                                                                                                      - Input signal on VINM0, bias on VINPx: negative gain
                                                                                                      - Bias on VINM0, input signal on VINPx: positive gain
                                                                                                      And VINM1 is connected too for filtering */
/**
  * @}
  */

/** @defgroup OPA_PgaGain OPA Pga Gain
  * @note Gain sign:
  *         - is positive if the @ref OPA_PgaConnect configuration is
  *           @ref OPA_PGA_CONNECT_INVERTINGINPUT_NO or OPA_PGA_CONNECT_INVERTINGINPUT_IO0
  *         - may be positive or negative if the @ref OPA_PgaConnect configuration is
  *           @ref OPA_PGA_CONNECT_INVERTINGINPUT_IO0_BIAS or OPA_PGA_CONNECT_INVERTINGINPUT_IO0_IO1_BIAS
  *       see @ref OPA_PgaConnect for more details
  * @{
  */
#define OPA_PGA_GAIN_2_OR_MINUS_1          (0x00000000UL)                                                      /*!< PGA gain could be 2  or -1  */
#define OPA_PGA_GAIN_4_OR_MINUS_3          (                                          OPA_CSR_PGA_GAIN_0)      /*!< PGA gain could be 4  or -3  */
#define OPA_PGA_GAIN_8_OR_MINUS_7          (                     OPA_CSR_PGA_GAIN_1                     )      /*!< PGA gain could be 8  or -7  */
#define OPA_PGA_GAIN_16_OR_MINUS_15        (                     OPA_CSR_PGA_GAIN_1 | OPA_CSR_PGA_GAIN_0)      /*!< PGA gain could be 16 or -15 */
#define OPA_PGA_GAIN_32_OR_MINUS_31        (OPA_CSR_PGA_GAIN_2                                          )      /*!< PGA gain could be 32 or -31 */
/* #define OPA_PGA_GAIN_64_OR_MINUS_63        (OPA_CSR_PGA_GAIN_2 |                      OPA_CSR_PGA_GAIN_0) */   /*!< PGA gain could be 64 or -63 */
/**
  * @}
  */

/** @defgroup OPA_PowerMode OPA PowerMode
  * @{
  */
#define OPA_POWERMODE_NORMALSPEED   (0x00000000UL)         /*!< Output in normal mode */
#define OPA_POWERMODE_HIGHSPEED     OPA_CSR_OPAHSM         /*!< Output in highspeed mode */
/**
  * @}
  */

/**
  * @}
  */



/* Private constants ---------------------------------------------------------*/
/** @defgroup OPA_Private_Constants OPA Private Constants
  * @brief   OPA Private constants and defines
  * @{
  */
/** @defgroup OPA_Input OPA Input
  * @{
  */
#define OPA_INPUT_INVERTING                 ( 24UL) /*!< Inverting input */
#define OPA_INPUT_NONINVERTING              ( 19UL) /*!< Non inverting input */

#define IS_OPA_INPUT(INPUT) (((INPUT) == OPA_INPUT_INVERTING) || \
                               ((INPUT) == OPA_INPUT_NONINVERTING))
/**
  * @}
  */

/**
  * @}
  */


/* Private macro -------------------------------------------------------------*/

/** @defgroup OPA_Private_Macros OPA Private Macros
  * @{
  */

#if defined(OPA_FOLLOWER_MODE)
#define IS_OPA_FUNCTIONAL_NORMALMODE(INPUT) (((INPUT) == OPA_STANDALONE_MODE) || \
                                               ((INPUT) == OPA_PGA_MODE) || \
                                               ((INPUT) == OPA_CURRENTSAMPLE_MODE) || \
                                               ((INPUT) == OPA_FOLLOWER_MODE))
#else
#define IS_OPA_FUNCTIONAL_NORMALMODE(INPUT) (((INPUT) == OPA_STANDALONE_MODE) || \
                                               ((INPUT) == OPA_PGA_MODE) || \
                                               ((INPUT) == OPA_CURRENTSAMPLE_MODE))
#endif

#define IS_OPA_NONINVERTING_INPUT(INPUT) (((INPUT) == OPA_NONINVERTINGINPUT_IO0) || \
                                            ((INPUT) == OPA_NONINVERTINGINPUT_IO1) || \
                                            ((INPUT) == OPA_NONINVERTINGINPUT_IO2) || \
                                            ((INPUT) == OPA_NONINVERTINGINPUT_IO3) || \
                                            ((INPUT) == OPA_NONINVERTINGINPUT_DAC))

#define IS_OPA_INVERTING_INPUT(INPUT) (((INPUT) == OPA_INVERTINGINPUT_IO0) || \
                                         ((INPUT) == OPA_INVERTINGINPUT_IO1))


#define IS_OPA_TIMERCONTROLLED_MUXMODE(MUXMODE)  \
  ((MUXMODE) <= (OPA_TIMERCONTROLLEDMUXMODE_TIM1_CH6 |    \
                 OPA_TIMERCONTROLLEDMUXMODE_TIM8_CH6))

#define IS_OPA_SEC_NONINVERTING_INPUT(INPUT) (((INPUT) == OPA_SEC_NONINVERTINGINPUT_IO0) || \
                                                ((INPUT) == OPA_SEC_NONINVERTINGINPUT_IO1) || \
                                                ((INPUT) == OPA_SEC_NONINVERTINGINPUT_IO2) || \
                                                ((INPUT) == OPA_SEC_NONINVERTINGINPUT_IO3) || \
                                                ((INPUT) == OPA_SEC_NONINVERTINGINPUT_DAC))

#if defined(OPA_FOLLOWER_MODE)
#define IS_OPA_SEC_INVERTING_INPUT(INPUT) (((INPUT) == OPA_SEC_INVERTINGINPUT_IO0) || \
                                             ((INPUT) == OPA_SEC_INVERTINGINPUT_IO1) || \
                                             ((INPUT) == OPA_SEC_INVERTINGINPUT_PGA) || \
                                             ((INPUT) == OPA_SEC_INVERTINGINPUT_FOLLOWER))
#else
#define IS_OPA_SEC_INVERTING_INPUT(INPUT) (((INPUT) == OPA_SEC_INVERTINGINPUT_IO0) || \
                                             ((INPUT) == OPA_SEC_INVERTINGINPUT_IO1) || \
                                             ((INPUT) == OPA_SEC_INVERTINGINPUT_PGA))
#endif

#define IS_OPA_PGACONNECT(CONNECT) (((CONNECT) == OPA_PGA_CONNECT_INVERTINGINPUT_NO)            || \
                                      ((CONNECT) == OPA_PGA_CONNECT_INVERTINGINPUT_IO0)           || \
                                      ((CONNECT) == OPA_PGA_CONNECT_INVERTINGINPUT_IO0_BIAS)      || \
                                      ((CONNECT) == OPA_PGA_CONNECT_INVERTINGINPUT_IO0_IO1_BIAS))

#ifdef OPA_PGA_GAIN_64_OR_MINUS_63
#define IS_OPA_PGA_GAIN(GAIN) (((GAIN) == OPA_PGA_GAIN_2_OR_MINUS_1)   || \
                                 ((GAIN) == OPA_PGA_GAIN_4_OR_MINUS_3)   || \
                                 ((GAIN) == OPA_PGA_GAIN_8_OR_MINUS_7)   || \
                                 ((GAIN) == OPA_PGA_GAIN_16_OR_MINUS_15) || \
                                 ((GAIN) == OPA_PGA_GAIN_32_OR_MINUS_31) || \
                                 ((GAIN) == OPA_PGA_GAIN_64_OR_MINUS_63))
#else
#define IS_OPA_PGA_GAIN(GAIN) (((GAIN) == OPA_PGA_GAIN_2_OR_MINUS_1)   || \
                                 ((GAIN) == OPA_PGA_GAIN_4_OR_MINUS_3)   || \
                                 ((GAIN) == OPA_PGA_GAIN_8_OR_MINUS_7)   || \
                                 ((GAIN) == OPA_PGA_GAIN_16_OR_MINUS_15) || \
                                 ((GAIN) == OPA_PGA_GAIN_32_OR_MINUS_31))
#endif

#define IS_OPA_POWERMODE(POWERMODE) (((POWERMODE) == OPA_POWERMODE_NORMALSPEED) || \
                                       ((POWERMODE) == OPA_POWERMODE_HIGHSPEED) )


/**
  * @}
  */


/* Exported macros -----------------------------------------------------------*/
/** @defgroup OPA_Exported_Macros OPA Exported Macros
  * @{
  */

/** @brief Reset OPA handle state
  * @param  __HANDLE__ OPA handle.
  * @retval None
  */
#define __HAL_OPA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_OPA_STATE_RESET)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup OPA_Exported_Functions OPA Exported Functions
  * @{
  */

/** @defgroup OPA_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization/de-initialization functions  **********************************/
HAL_StatusTypeDef HAL_OPA_Init(OPA_HandleTypeDef *hopa);
HAL_StatusTypeDef HAL_OPA_DeInit(OPA_HandleTypeDef *hopa);
void HAL_OPA_MspInit(OPA_HandleTypeDef *hopa);
void HAL_OPA_MspDeInit(OPA_HandleTypeDef *hopa);
/**
  * @}
  */


/** @defgroup OPA_Exported_Functions_Group2 Input and Output operation functions
  * @{
  */

/* I/O operation functions  *****************************************************/
HAL_StatusTypeDef HAL_OPA_Start(OPA_HandleTypeDef *hopa);
HAL_StatusTypeDef HAL_OPA_Stop(OPA_HandleTypeDef *hopa);


/**
  * @}
  */

/** @defgroup OPA_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */

/* Peripheral Control functions  ************************************************/
#if (USE_HAL_OPA_REGISTER_CALLBACKS == 1)
/* OPA callback registering/unregistering */
HAL_StatusTypeDef HAL_OPA_RegisterCallback(OPA_HandleTypeDef *hopa, HAL_OPA_CallbackIDTypeDef CallbackId,
                                             pOPA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_OPA_UnRegisterCallback(OPA_HandleTypeDef *hopa, HAL_OPA_CallbackIDTypeDef CallbackId);
#endif /* USE_HAL_OPA_REGISTER_CALLBACKS */

HAL_StatusTypeDef HAL_OPA_Lock(OPA_HandleTypeDef *hopa);
HAL_StatusTypeDef HAL_OPA_LockTimerMux(OPA_HandleTypeDef *hopa);

/**
  * @}
  */

/** @defgroup OPA_Exported_Functions_Group4 Peripheral State functions
  * @{
  */

/* Peripheral State functions  **************************************************/
HAL_OPA_StateTypeDef HAL_OPA_GetState(OPA_HandleTypeDef *hopa);

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

#endif /* PY32E407_HAL_OPA_H */


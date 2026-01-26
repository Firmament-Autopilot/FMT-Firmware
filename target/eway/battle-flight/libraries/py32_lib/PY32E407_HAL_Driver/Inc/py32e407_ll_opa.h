/**
  ******************************************************************************
  * @file    py32e407_ll_opa.h
  * @author  MCU Application Team
  * @brief   Header file of OPA LL module.
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
#ifndef PY32E407_LL_OPA_H
#define PY32E407_LL_OPA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (OPA1) || defined (OPA2) || defined (OPA3)

/** @defgroup OPA_LL OPA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup OPA_LL_Private_Constants OPA Private Constants
  * @{
  */

/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @defgroup OPA_LL_Private_Macros OPA Private Macros
  * @{
  */

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  * @param  __REG__ Register basis from which the offset is applied.
  * @param  __REG_OFFSET__ Offset to be applied (unit: number of registers).
  * @retval Register address
  */
#define __OPA_PTR_REG_OFFSET(__REG__, __REG_OFFSET__)                        \
  ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFSET__) << 2))))




/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup OPA_LL_ES_INIT OPA Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of OPA instance.
  */
typedef struct
{
  uint32_t PowerMode;                   /*!< Set OPA power mode.
                                             This parameter can be a value of @ref OPA_LL_EC_POWERMODE

                                             This feature can be modified afterwards using unitary function @ref LL_OPA_SetPowerMode(). */


  uint32_t FunctionalMode;              /*!< Set OPA functional mode by setting internal connections: OPA operation in standalone, follower, ...
                                             This parameter can be a value of @ref OPA_LL_EC_FUNCTIONAL_MODE
                                             @note If OPA is configured in mode PGA, the gain can be configured using function @ref LL_OPA_SetPGAGain().

                                             This feature can be modified afterwards using unitary function @ref LL_OPA_SetFunctionalMode(). */

  uint32_t InputNonInverting;           /*!< Set OPA input non-inverting connection.
                                             This parameter can be a value of @ref OPA_LL_EC_INPUT_NONINVERTING

                                             This feature can be modified afterwards using unitary function @ref LL_OPA_SetInputNonInverting(). */

  uint32_t InputInverting;              /*!< Set OPA inverting input connection.
                                             This parameter can be a value of @ref OPA_LL_EC_INPUT_INVERTING
                                             @note OPA inverting input is used with OPA in mode standalone or PGA with external capacitors for filtering circuit.

                                             This feature can be modified afterwards using unitary function @ref LL_OPA_SetInputInverting(). */

} LL_OPA_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup OPA_LL_Exported_Constants OPA Exported Constants
  * @{
  */

/** @defgroup OPA_LL_EC_FUNCTIONAL_MODE OPA functional mode
  * @{
  */
#define LL_OPA_MODE_STANDALONE        (0x00000000UL)                                              /*!< OPA functional mode, OPA operation in standalone */
/* #define LL_OPA_MODE_FOLLOWER          (OPA_CSR_VM_SEL_1 | OPA_CSR_VM_SEL_0)  */                 /*!< OPA functional mode, OPA operation in follower */
#define LL_OPA_MODE_PGA               (OPA_CSR_VM_SEL_1)                                           /*!< OPA functional mode, OPA operation in PGA */
#define LL_OPA_MODE_PGA_IO0           (OPA_CSR_PGA_GAIN_4 | OPA_CSR_VM_SEL_1)                          /*!< In PGA mode, the inverting input is connected to VINM0 for filtering */
#define LL_OPA_MODE_PGA_IO0_BIAS      (OPA_CSR_PGA_GAIN_3 | OPA_CSR_VM_SEL_1)                          /*!< In PGA mode, the inverting input is connected to VINM0
                                                                                                          - Input signal on VINM0, bias on VINPx: negative gain
                                                                                                          - Bias on VINM0, input signal on VINPx: positive gain */
#define LL_OPA_MODE_PGA_IO0_IO1_BIAS  (OPA_CSR_PGA_GAIN_4 | OPA_CSR_PGA_GAIN_3 | OPA_CSR_VM_SEL_1)         /*!< In PGA mode, the inverting input is connected to VINM0
                                                                                                          - Input signal on VINM0, bias on VINPx: negative gain
                                                                                                          - Bias on VINM0, input signal on VINPx: positive gain
                                                                                                          And VINM1 is connected too for filtering */

/**
  * @}
  */

/** @defgroup OPA_LL_EC_MODE_PGA_GAIN OPA PGA gain (relevant when OPA is in functional mode PGA)
  * @note Gain sign:
  *         - is positive if the @ref OPA_LL_EC_FUNCTIONAL_MODE configuration is
  *           @ref LL_OPA_MODE_PGA or LL_OPA_MODE_PGA_IO0
  *         - may be positive or negative if the @ref OPA_LL_EC_FUNCTIONAL_MODE configuration is
  *           @ref LL_OPA_MODE_PGA_IO0_BIAS or LL_OPA_MODE_PGA_IO0_IO1_BIAS
  *       see @ref OPA_LL_EC_FUNCTIONAL_MODE for more details
  * @{
  */
#define LL_OPA_PGA_GAIN_2_OR_MINUS_1             (0x00000000UL)                                                      /*!< OPA PGA gain 2  or -1  */
#define LL_OPA_PGA_GAIN_4_OR_MINUS_3             (                                          OPA_CSR_PGA_GAIN_0)      /*!< OPA PGA gain 4  or -3  */
#define LL_OPA_PGA_GAIN_8_OR_MINUS_7             (                     OPA_CSR_PGA_GAIN_1                     )      /*!< OPA PGA gain 8  or -7  */
#define LL_OPA_PGA_GAIN_16_OR_MINUS_15           (                     OPA_CSR_PGA_GAIN_1 | OPA_CSR_PGA_GAIN_0)      /*!< OPA PGA gain 16 or -15 */
#define LL_OPA_PGA_GAIN_32_OR_MINUS_31           (OPA_CSR_PGA_GAIN_2                                          )      /*!< OPA PGA gain 32 or -31 */
/* #define LL_OPA_PGA_GAIN_64_OR_MINUS_63        (OPA_CSR_PGA_GAIN_2 |                      OPA_CSR_PGA_GAIN_0) */   /*!< OPA PGA gain 64 or -63 */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INPUT_NONINVERTING OPA input non-inverting
  * @{
  */
#define LL_OPA_INPUT_NONINVERT_IO0         (0x00000000UL)      /*!< OPA non inverting input connected to I/O VINP0
                                                                        (PA1  for OPA1, PA7  for OPA2, PB0  for OPA3)  */
#define LL_OPA_INPUT_NONINVERT_IO1         OPA_CSR_VP_SEL_0     /*!< OPA non inverting input connected to I/O VINP1
                                                                        (PA3  for OPA1, PB14 for OPA2, PB13 for OPA3)  */
#define LL_OPA_INPUT_NONINVERT_IO2         OPA_CSR_VP_SEL_1     /*!< OPA non inverting input connected to I/O VINP2
                                                                        (PA7  for OPA1, PB0  for OPA2, PA1  for OPA3)  */
#define LL_OPA_INPUT_NONINVERT_IO3         OPA_CSR_VP_SEL       /*!< OPA non inverting input connected to I/O VINP3
                                                                        (PD14 for OPA2) */
#define LL_OPA_INPUT_NONINVERT_DAC         OPA_CSR_VP_SEL       /*!< OPA non inverting input connected internally to DAC channel
                                                                       (DAC1_CH1 for OPA1, DAC2_CH1  for OPA3)  */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INPUT_INVERTING OPA input inverting
  * @note OPA inverting input is used with OPA in mode standalone or PGA with negative gain or bias.
  *       Otherwise (OPA in mode follower), OPA inverting input is not used (not connected to GPIO pin).
  * @{
  */
#define LL_OPA_INPUT_INVERT_IO0         (0x00000000UL)         /*!< OPA inverting input connected to I/O VINM0
                                                                        (PA3  for OPA1, PA5  for OPA2, PB2  for OPA3) */
#define LL_OPA_INPUT_INVERT_IO1         OPA_CSR_VM_SEL_0        /*!< OPA inverting input connected to I/0 VINM1
                                                                        (PC5  for OPA1, PC5  for OPA2, PB10 for OPA3) */
#define LL_OPA_INPUT_INVERT_CONNECT_NO  OPA_CSR_VM_SEL_1        /*!< OPA inverting input not externally connected (intended for OPA in mode follower or PGA with positive gain without bias). */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INPUT_NONINVERTING_SECONDARY OPA input non-inverting secondary
  * @{
  */
#define LL_OPA_INPUT_NONINVERT_IO0_SEC         (0x00000000UL)       /*!< OPA secondary non inverting input connected to I/O VINP0
                                                                           (PA1  for OPA1, PA7  for OPA2, PB0  for OPA3) */
#define LL_OPA_INPUT_NONINVERT_IO1_SEC         OPA_TCMR_VPS_SEL_0  /*!< OPA secondary non inverting input connected to I/O VINP1
                                                                           (PA3  for OPA1, PB14 for OPA2, PB13 for OPA3)*/
#define LL_OPA_INPUT_NONINVERT_IO2_SEC         OPA_TCMR_VPS_SEL_1  /*!< OPA secondary non inverting input connected to I/O VINP2
                                                                           (PA7  for OPA1, PB0  for OPA2, PA1  for OPA3) */
#define LL_OPA_INPUT_NONINVERT_IO3_SEC         OPA_TCMR_VPS_SEL    /*!< OPA secondary non inverting input connected to I/O VINP3
                                                                           (PD14 for OPA2) */
#define LL_OPA_INPUT_NONINVERT_DAC_SEC         OPA_TCMR_VPS_SEL    /*!< OPA secondary non inverting input connected internally to DAC channel
                                                                           (DAC1_CH1 for OPA1, DAC2_CH1  for OPA3)*/
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INPUT_INVERTING_SECONDARY OPA input inverting secondary
  * @note OPA inverting input is used with OPA in mode standalone or PGA with negative gain or bias.
  *       Otherwise (OPA in mode follower), OPA inverting input is not used (not connected to GPIO pin).
  * @{
  */
#define LL_OPA_INPUT_INVERT_IO0_SEC         (0x00000000UL)          /*!< OPA secondary mode is standalone mode - Only applicable if @ref LL_OPA_MODE_STANDALONE
                                                                           has been configured by call to @ref LL_OPA_Init() or @ref LL_OPA_SetFunctionalMode().
                                                                           OPA secondary inverting input connected to I/O VINM0.
                                                                           (PA3  for OPA1, PA5  for OPA2, PB2  for OPA3) */
#define LL_OPA_INPUT_INVERT_IO1_SEC         OPA_TCMR_VMS_SEL       /*!< OPA secondary mode is standalone mode - Only applicable if @ref LL_OPA_MODE_STANDALONE
                                                                           has been configured by call to @ref LL_OPA_Init() or @ref LL_OPA_SetFunctionalMode().
                                                                           OPA secondary inverting input connected to I/0 VINM1
                                                                           (PC5  for OPA1, PC5  for OPA2, PB10 for OPA3) */
#define LL_OPA_INPUT_INVERT_PGA_SEC         (0x00000000UL)          /*!< OPA secondary mode is PGA mode - Only applicable if configured mode through call to @ref LL_OPA_Init()
                                                                           or @ref LL_OPA_SetFunctionalMode() is NOT @ref LL_OPA_MODE_STANDALONE.
                                                                           OPA secondary inverting input is:
                                                                             - Not connected if configured mode is @ref LL_OPA_MODE_FOLLOWER or @ref LL_OPA_MODE_PGA
                                                                             - Connected to VINM0 and possibly VINM1 if any of the other modes as been configured
                                                                           (see @ref OPA_LL_EC_FUNCTIONAL_MODE description for more details on PGA connection modes) */
/* #define LL_OPA_INPUT_INVERT_FOLLOWER_SEC    OPA_TCMR_VMS_SEL */    /*!< OPA secondary mode is Follower mode - Only applicable if configured mode through call to @ref LL_OPA_Init()
                                                                           or @ref LL_OPA_SetFunctionalMode() is NOT @ref LL_OPA_MODE_STANDALONE.
                                                                           OPA secondary inverting input is not connected. */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INTERNAL_OUPUT_MODE OPA internal output mode
  * @{
  */
#define LL_OPA_INTERNAL_OUPUT_DISABLED       (0x00000000UL)         /*!< OPA internal output to ADC disabled. */
#define LL_OPA_INTERNAL_OUPUT_ENABLED        OPA_CSR_OPAINTOEN      /*!< OPA internal output to ADC enabled. */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_INPUT_MUX_MODE OPA inputs multiplexer mode
  * @note The switch can be controlled either by a single timer or a combination of them,
  *       in this case application has to 'ORed' the values below
  *       ex LL_OPA_INPUT_MUX_TIM1_CH6 
  * @{
  */
#define LL_OPA_INPUT_MUX_DISABLE       (0x00000000UL)         /*!< OPA inputs timer controlled multiplexer mode disabled. */
#define LL_OPA_INPUT_MUX_TIM1_CH6      OPA_TCMR_T1CM_EN        /*!< OPA inputs timer controlled multiplexer mode enabled, controlled by TIM1 OC6. */
#define LL_OPA_INPUT_MUX_TIM8_CH6      OPA_TCMR_T8CM_EN        /*!< OPA inputs timer controlled multiplexer mode enabled, controlled by TIM8 OC6. */
/**
  * @}
  */

/** @defgroup OPA_LL_EC_POWERMODE OPA PowerMode
  * @{
  */
#define LL_OPA_POWERMODE_NORMALSPEED   (0x00000000UL)         /*!< OPA output in normal mode */
#define LL_OPA_POWERMODE_HIGHSPEED     OPA_CSR_OPAHSM         /*!< OPA output in highspeed mode */

/**
  * @}
  */

/** @defgroup OPA_LL_EC_VOLTAGEBUILD_MODE OPA VoltageBuild
  * @{
  */
#define LL_OPA_VOLTAGEBUILDIN_VCC_DIV2    OPA_CSR_OPA_VBIAS_0         /*!< OPA Voltagge VCCA DIV2 */
#define LL_OPA_VOLTAGEBUILDIN_VCC_DIV5    OPA_CSR_OPA_VBIAS_1         /*!< OPA Voltagge VCCA DIV5 */

/**
  * @}
  */

/** @defgroup OPA_LL_EC_HW_DELAYS  Definitions of OPA hardware constraints delays
  * @note   Only OPA peripheral HW delays are defined in OPA LL driver driver,
  *         not timeout values.
  *         For details on delays values, refer to descriptions in source code
  *         above each literal definition.
  * @{
  */

/* Delay for OPA startup time (transition from state disable to enable).    */
/* Note: OPA startup time depends on board application environment:         */
/*       impedance connected to OPA output.                                 */
/*       The delay below is specified under conditions:                       */
/*        - OPA in functional mode follower                                 */
/*        - load impedance of 4kOhm (min), 50pF (max)                         */
/* Literal set to maximum value (refer to device datasheet,                   */
/* parameter "tWAKEUP").                                                      */
/* Unit: us                                                                   */
#define LL_OPA_DELAY_STARTUP_US         (6)  /*!< Delay for OPA startup time */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup OPA_LL_Exported_Macros OPA Exported Macros
  * @{
  */
/** @defgroup OPA_LL_EM_WRITE_READ Common write and read registers macro
  * @{
  */
/**
  * @brief  Write a value in OPA register
  * @param  __INSTANCE__ OPA Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_OPA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in OPA register
  * @param  __INSTANCE__ OPA Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_OPA_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup OPA_LL_Exported_Functions OPA Exported Functions
  * @{
  */

/** @defgroup OPA_LL_EF_CONFIGURATION_OPA_INSTANCE Configuration of OPA hierarchical scope: OPA instance
  * @{
  */

/**
  * @brief  Set OPA functional mode by setting internal connections.
  *         OPA operation in standalone, follower, ...
  * @note   This function reset bit of calibration mode to ensure
  *         to be in functional mode, in order to have OPA parameters
  *         (inputs selection, ...) set with the corresponding OPA mode
  *         to be effective.
  * @rmtoll CSR      VMSEL          LL_OPA_SetFunctionalMode
  * @param  OPAx OPA instance
  * @param  FunctionalMode This parameter can be one of the following values:
  *         @arg @ref LL_OPA_MODE_STANDALONE
  *         @arg @ref LL_OPA_MODE_FOLLOWER
  *         @arg @ref LL_OPA_MODE_PGA
  *         @arg @ref LL_OPA_MODE_PGA_IO0
  *         @arg @ref LL_OPA_MODE_PGA_IO0_BIAS
  *         @arg @ref LL_OPA_MODE_PGA_IO0_IO1_BIAS
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetFunctionalMode(OPA_TypeDef *OPAx, uint32_t FunctionalMode)
{
  MODIFY_REG(OPAx->CSR, OPA_CSR_PGA_GAIN_4 | OPA_CSR_PGA_GAIN_3 | OPA_CSR_VM_SEL, FunctionalMode);
}

/**
  * @brief  Get OPA functional mode from setting of internal connections.
  *         OPA operation in standalone, follower, ...
  * @rmtoll CSR      VMSEL          LL_OPA_GetFunctionalMode
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_MODE_STANDALONE
  *         @arg @ref LL_OPA_MODE_FOLLOWER
  *         @arg @ref LL_OPA_MODE_PGA
  *         @arg @ref LL_OPA_MODE_PGA_IO0
  *         @arg @ref LL_OPA_MODE_PGA_IO0_BIAS
  *         @arg @ref LL_OPA_MODE_PGA_IO0_IO1_BIAS
  */
__STATIC_INLINE uint32_t LL_OPA_GetFunctionalMode(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->CSR, OPA_CSR_PGA_GAIN_4 | OPA_CSR_PGA_GAIN_3 | OPA_CSR_VM_SEL));
}

/**
  * @brief  Set OPA PGA gain.
  * @note   Preliminarily, OPA must be set in mode PGA
  *         using function @ref LL_OPA_SetFunctionalMode().
  * @rmtoll CSR      PGGAIN         LL_OPA_SetPGAGain
  * @param  OPAx OPA instance
  * @param  PGAGain This parameter can be one of the following values:
  *         @arg @ref LL_OPA_PGA_GAIN_2_OR_MINUS_1
  *         @arg @ref LL_OPA_PGA_GAIN_4_OR_MINUS_3
  *         @arg @ref LL_OPA_PGA_GAIN_8_OR_MINUS_7
  *         @arg @ref LL_OPA_PGA_GAIN_16_OR_MINUS_15
  *         @arg @ref LL_OPA_PGA_GAIN_32_OR_MINUS_31
  *         @arg @ref LL_OPA_PGA_GAIN_64_OR_MINUS_63
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetPGAGain(OPA_TypeDef *OPAx, uint32_t PGAGain)
{
  MODIFY_REG(OPAx->CSR, OPA_CSR_PGA_GAIN_2 | OPA_CSR_PGA_GAIN_1 | OPA_CSR_PGA_GAIN_0, PGAGain);
}

/**
  * @brief  Get OPA PGA gain.
  * @note   Preliminarily, OPA must be set in mode PGA
  *         using function @ref LL_OPA_SetFunctionalMode().
  * @rmtoll CSR      PGGAIN         LL_OPA_GetPGAGain
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_PGA_GAIN_2_OR_MINUS_1
  *         @arg @ref LL_OPA_PGA_GAIN_4_OR_MINUS_3
  *         @arg @ref LL_OPA_PGA_GAIN_8_OR_MINUS_7
  *         @arg @ref LL_OPA_PGA_GAIN_16_OR_MINUS_15
  *         @arg @ref LL_OPA_PGA_GAIN_32_OR_MINUS_31
  *         @arg @ref LL_OPA_PGA_GAIN_64_OR_MINUS_63
  */
__STATIC_INLINE uint32_t LL_OPA_GetPGAGain(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->CSR, OPA_CSR_PGA_GAIN_2 | OPA_CSR_PGA_GAIN_1 | OPA_CSR_PGA_GAIN_0));
}

/**
  * @brief  Set OPA power mode normal or highspeed.
  * @note   OPA highspeed mode allows output stage to have a better slew rate.
  * @rmtoll CSR      HIGHSPEEDEN     LL_OPA_SetPowerMode
  * @param  OPAx OPA instance
  * @param  PowerMode This parameter can be one of the following values:
  *         @arg @ref LL_OPA_POWERMODE_NORMALSPEED
  *         @arg @ref LL_OPA_POWERMODE_HIGHSPEED
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetPowerMode(OPA_TypeDef *OPAx, uint32_t PowerMode)
{
  MODIFY_REG(OPAx->CSR, OPA_CSR_OPAHSM, PowerMode);
}

/**
  * @brief  Get OPA power mode normal or highspeed.
  * @note   OPA highspeed mode allows output stage to have a better slew rate.
  * @rmtoll CSR      HIGHSPEEDEN     LL_OPA_GetPowerMode
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_POWERMODE_NORMALSPEED
  *         @arg @ref LL_OPA_POWERMODE_HIGHSPEED
  */
__STATIC_INLINE uint32_t LL_OPA_GetPowerMode(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->CSR, OPA_CSR_OPAHSM));
}
/**
  * @}
  */


/** @defgroup OPA_LL_EF_CONFIGURATION_INPUTS Configuration of OPA inputs
  * @{
  */

/**
  * @brief  Set OPA non-inverting input connection.
  * @rmtoll CSR      VPSEL          LL_OPA_SetInputNonInverting
  * @param  OPAx OPA instance
  * @param  InputNonInverting This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO0
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO1
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO2
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO3
  *         @arg @ref LL_OPA_INPUT_NONINVERT_DAC
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputNonInverting(OPA_TypeDef *OPAx, uint32_t InputNonInverting)
{
  MODIFY_REG(OPAx->CSR, OPA_CSR_VP_SEL, InputNonInverting);
}

/**
  * @brief  Get OPA non-inverting input connection.
  * @rmtoll CSR      VPSEL          LL_OPA_GetInputNonInverting
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO0
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO1
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO2
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO3
  *         @arg @ref LL_OPA_INPUT_NONINVERT_DAC
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputNonInverting(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->CSR, OPA_CSR_VP_SEL));
}

/**
  * @brief  Set OPA inverting input connection.
  * @note   OPA inverting input is used with OPA in mode standalone
  *         or PGA with external capacitors for filtering circuit.
  *         Otherwise (OPA in mode follower), OPA inverting input
  *         is not used (not connected to GPIO pin).
  * @rmtoll CSR      VMSEL          LL_OPA_SetInputInverting
  * @param  OPAx OPA instance
  * @param  InputInverting This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_INVERT_IO0
  *         @arg @ref LL_OPA_INPUT_INVERT_IO1
  *         @arg @ref LL_OPA_INPUT_INVERT_CONNECT_NO
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputInverting(OPA_TypeDef *OPAx, uint32_t InputInverting)
{
  /* Manage cases of OPA inverting input not connected (0x10 and 0x11)      */
  /* to not modify OPA mode follower or PGA.                                */
  /* Bit OPA_CSR_VMSEL_1 is set by OPA mode (follower, PGA). */
  MODIFY_REG(OPAx->CSR, (~(InputInverting >> 1)) & OPA_CSR_VM_SEL_0, InputInverting);
}

/**
  * @brief  Get OPA inverting input connection.
  * @rmtoll CSR      VMSEL          LL_OPA_GetInputInverting
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_INVERT_IO0
  *         @arg @ref LL_OPA_INPUT_INVERT_IO1
  *         @arg @ref LL_OPA_INPUT_INVERT_CONNECT_NO
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputInverting(OPA_TypeDef *OPAx)
{
  uint32_t input_inverting = READ_BIT(OPAx->CSR, OPA_CSR_VM_SEL);

  /* Manage cases 0x10 and 0x11 to return the same value: OPA inverting     */
  /* input not connected.                                                     */
  return (input_inverting & ~((input_inverting >> 1) & OPA_CSR_VM_SEL_0));
}

/**
  * @brief  Set OPA non-inverting input secondary connection.
  * @rmtoll TCMR     VPSSEL         LL_OPA_SetInputNonInvertingSecondary
  * @param  OPAx OPA instance
  * @param  InputNonInverting This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO0_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO1_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO2_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO3_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_DAC_SEC
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputNonInvertingSecondary(OPA_TypeDef *OPAx, uint32_t InputNonInverting)
{
  MODIFY_REG(OPAx->TCMR, OPA_TCMR_VPS_SEL, InputNonInverting);
}

/**
  * @brief  Get OPA non-inverting input secondary connection.
  * @rmtoll TCMR     VPSSEL         LL_OPA_GetInputNonInvertingSecondary
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO0_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO1_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO2_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_IO3_SEC
  *         @arg @ref LL_OPA_INPUT_NONINVERT_DAC_SEC
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputNonInvertingSecondary(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->TCMR, OPA_TCMR_VPS_SEL));
}

/**
  * @brief  Set OPA inverting input secondary connection.
  * @note   OPA inverting input is used with OPA in mode standalone
  *         or PGA with external capacitors for filtering circuit.
  *         Otherwise (OPA in mode follower), OPA inverting input
  *         is not used (not connected to GPIO pin).
  * @rmtoll TCMR     VMSSEL         LL_OPA_SetInputInvertingSecondary
  * @param  OPAx OPA instance
  * @param  InputInverting This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_INVERT_IO0_SEC
  *         @arg @ref LL_OPA_INPUT_INVERT_IO1_SEC
  *         @arg @ref LL_OPA_INPUT_INVERT_PGA_SEC
  *         @arg @ref LL_OPA_INPUT_INVERT_FOLLOWER_SEC
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputInvertingSecondary(OPA_TypeDef *OPAx, uint32_t InputInverting)
{
  MODIFY_REG(OPAx->TCMR, OPA_TCMR_VMS_SEL, InputInverting);
}

/**
  * @brief  Get OPA inverting input secondary connection.
  * @rmtoll TCMR     VMSSEL         LL_OPA_GetInputInvertingSecondary
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_INVERT_IO0_SEC
  *         @arg @ref LL_OPA_INPUT_INVERT_IO1_SEC
  *         @arg @ref LL_OPA_INPUT_INVERT_PGA_SEC
  *         @arg @ref LL_OPA_INPUT_INVERT_FOLLOWER_SEC
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputInvertingSecondary(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->TCMR, OPA_TCMR_VMS_SEL));
}

/**
  * @brief  Set OPA inputs multiplexer mode.
  * @rmtoll TCMR     TCMEN          LL_OPA_SetInputsMuxMode
  * @param  OPAx OPA instance
  * @param  InputsMuxMode This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_MUX_DISABLE
  *         @arg @ref LL_OPA_INPUT_MUX_TIM1_CH6
  *         @arg @ref LL_OPA_INPUT_MUX_TIM8_CH6
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInputsMuxMode(OPA_TypeDef *OPAx, uint32_t InputsMuxMode)
{
  MODIFY_REG(OPAx->TCMR, OPA_TCMR_T1CM_EN | OPA_TCMR_T8CM_EN, InputsMuxMode);
}

/**
  * @brief  Get OPA inputs multiplexer mode.
  * @rmtoll TCMR     TCMEN          LL_OPA_GetInputsMuxMode
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INPUT_MUX_DISABLE
  *         @arg @ref LL_OPA_INPUT_MUX_TIM1_CH6
  *         @arg @ref LL_OPA_INPUT_MUX_TIM8_CH6
  */
__STATIC_INLINE uint32_t LL_OPA_GetInputsMuxMode(OPA_TypeDef *OPAx)
{
  return (uint32_t)(READ_BIT(OPAx->TCMR, OPA_TCMR_T1CM_EN | OPA_TCMR_T8CM_EN));
}

/**
  * @brief  Set OPA internal output.
  * @note   OPA internal output is used to link OPA output to ADC input internally.
  * @rmtoll CSR      OPAINTEN     LL_OPA_SetInternalOutput
  * @param  OPAx OPA instance
  * @param  InternalOutput This parameter can be one of the following values:
  *         @arg @ref LL_OPA_INTERNAL_OUPUT_DISABLED
  *         @arg @ref LL_OPA_INTERNAL_OUPUT_ENABLED
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetInternalOutput(OPA_TypeDef *OPAx, uint32_t InternalOutput)
{
  MODIFY_REG(OPAx->CSR, OPA_CSR_OPAINTOEN, InternalOutput);
}

/**
  * @brief  Get OPA internal output state.
  * @rmtoll CSR      OPAINTEN     LL_OPA_GetInternalOutput
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_INTERNAL_OUPUT_DISABLED
  *         @arg @ref LL_OPA_INTERNAL_OUPUT_ENABLED
  */
__STATIC_INLINE uint32_t LL_OPA_GetInternalOutput(OPA_TypeDef *OPAx)
{
  return READ_BIT(OPAx->CSR, OPA_CSR_OPAINTOEN);
}

/**
  * @brief  Set OPA Voltage Build in.
  * @rmtoll CSR      OPA_VBIAS     LL_OPA_SetVoltageBuildIn
  * @param  OPAx OPA instance
  * @param  VccDiv This parameter can be one of the following values:
  *         @arg @ref LL_OPA_VOLTAGEBUILDIN_VCC_DIV2
  *         @arg @ref LL_OPA_VOLTAGEBUILDIN_VCC_DIV5
  * @retval None
  */
__STATIC_INLINE void LL_OPA_SetVoltageBuildIn(OPA_TypeDef *OPAx, uint32_t VccDiv)
{
  MODIFY_REG(OPAx->CSR, OPA_CSR_OPA_VBIAS, VccDiv);
}

/**
  * @brief  Get OPA Voltage Build in
  * @rmtoll CSR      OPA_VBIAS     LL_OPA_GetVoltageBuildIn
  * @param  OPAx OPA instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_OPA_VOLTAGEBUILDIN_VCC_DIV2
  *         @arg @ref LL_OPA_VOLTAGEBUILDIN_VCC_DIV5
  */
__STATIC_INLINE uint32_t LL_OPA_GetVoltageBuildIn(OPA_TypeDef *OPAx)
{
  return READ_BIT(OPAx->CSR, OPA_CSR_OPA_VBIAS);
}

/**
  * @brief  Enable OPA Voltage BuildIn.
  * @rmtoll CSR      OPA_VBSEL       LL_OPA_EnableVoltageBuildIn
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_EnableVoltageBuildIn(OPA_TypeDef *OPAx)
{
  SET_BIT(OPAx->CSR, OPA_CSR_OPA_VBSEL);
}

/**
  * @brief  Disable OPA Voltage BuildIn.
  * @rmtoll CSR      OPA_VBSEL       LL_OPA_DisableVoltageBuildIn
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_DisableVoltageBuildIn(OPA_TypeDef *OPAx)
{
  CLEAR_BIT(OPAx->CSR, OPA_CSR_OPA_VBSEL);
}

/**
  * @brief  Get OPAVoltage BuildIn enable state
  * @rmtoll CSR      OPA_VBSEL       LL_OPA_IsEnabledVoltageBuildIn
  * @param  OPAx OPA instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_OPA_IsEnabledVoltageBuildIn(OPA_TypeDef *OPAx)
{
  return ((READ_BIT(OPAx->CSR, OPA_CSR_OPA_VBSEL) == (OPA_CSR_OPA_VBSEL)) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup OPA_LL_EF_OPERATION Operation on OPA instance
  * @{
  */
/**
  * @brief  Enable OPA instance.
  * @note   After enable from off state, OPA requires a delay
  *         to fulfill wake up time specification.
  *         Refer to device datasheet, parameter "tWAKEUP".
  * @rmtoll CSR      OPAEN       LL_OPA_Enable
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_Enable(OPA_TypeDef *OPAx)
{
  SET_BIT(OPAx->CSR, OPA_CSR_OPAEN);
}

/**
  * @brief  Disable OPA instance.
  * @rmtoll CSR      OPAEN       LL_OPA_Disable
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_Disable(OPA_TypeDef *OPAx)
{
  CLEAR_BIT(OPAx->CSR, OPA_CSR_OPAEN);
}

/**
  * @brief  Get OPA instance enable state
  *         (0: OPA is disabled, 1: OPA is enabled)
  * @rmtoll CSR      OPAEN       LL_OPA_IsEnabled
  * @param  OPAx OPA instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_OPA_IsEnabled(OPA_TypeDef *OPAx)
{
  return ((READ_BIT(OPAx->CSR, OPA_CSR_OPAEN) == (OPA_CSR_OPAEN)) ? 1UL : 0UL);
}

/**
  * @brief  Lock OPA instance.
  * @note   Once locked, OPA configuration can be accessed in read-only.
  * @note   The only way to unlock the OPA is a device hardware reset.
  * @rmtoll CSR      LOCK           LL_OPA_Lock
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_Lock(OPA_TypeDef *OPAx)
{
  SET_BIT(OPAx->CSR, OPA_CSR_LOCK);
}

/**
  * @brief  Get OPA lock state
  *         (0: OPA is unlocked, 1: OPA is locked).
  * @note   Once locked, OPA configuration can be accessed in read-only.
  * @note   The only way to unlock the OPA is a device hardware reset.
  * @rmtoll CSR      LOCK           LL_OPA_IsLocked
  * @param  OPAx OPA instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_OPA_IsLocked(OPA_TypeDef *OPAx)
{
  return ((READ_BIT(OPAx->CSR, OPA_CSR_LOCK) == (OPA_CSR_LOCK)) ? 1UL : 0UL);
}

/**
  * @brief  Lock OPA instance timer controlled mux
  * @note   Once locked, OPA timer controlled mux configuration can be accessed in read-only.
  * @note   The only way to unlock the OPA timer controlled mux is a device hardware reset.
  * @rmtoll TCMR     LOCK           LL_OPA_LockTimerMux
  * @param  OPAx OPA instance
  * @retval None
  */
__STATIC_INLINE void LL_OPA_LockTimerMux(OPA_TypeDef *OPAx)
{
  SET_BIT(OPAx->TCMR, OPA_TCMR_LOCK);
}

/**
  * @brief  Get OPA timer controlled mux lock state
  *         (0: OPA timer controlled mux is unlocked, 1: OPA timer controlled mux is locked).
  * @note   Once locked, OPA timer controlled mux configuration can be accessed in read-only.
  * @note   The only way to unlock the OPA timer controlled mux is a device hardware reset.
  * @rmtoll TCMR     LOCK           LL_OPA_IsTimerMuxLocked
  * @param  OPAx OPA instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_OPA_IsTimerMuxLocked(OPA_TypeDef *OPAx)
{
  return ((READ_BIT(OPAx->TCMR, OPA_TCMR_LOCK) == (OPA_TCMR_LOCK)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup OPA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_OPA_DeInit(OPA_TypeDef *OPAx);
ErrorStatus LL_OPA_Init(OPA_TypeDef *OPAx, LL_OPA_InitTypeDef *OPA_InitStruct);
void        LL_OPA_StructInit(LL_OPA_InitTypeDef *OPA_InitStruct);

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

#endif /* OPA1 || OPA2 || OPA3  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32E407_LL_OPA_H */


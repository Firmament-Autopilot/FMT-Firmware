/**
  ******************************************************************************
  * @file    py32e407_hal_pwr_ex.c
  * @author  MCU Application Team
  * @brief   Extended PWR HAL module driver.
  *          This file provides firmware functions to manage the following 
  *          functionalities of PWR extension peripheral:           
  *           + Peripheral Extended features functions
  *         
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

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx_hal.h"

/** @addtogroup PY32E407_HAL_Driver
  * @{
  */

/** @defgroup PWREx PWREx
  * @brief PWR HAL module driver
  * @{
  */

#ifdef HAL_PWR_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup PWR_Extended_Private_Defines PWR Extended Private Defines
  * @{
  */

/** @defgroup PWREx_PVM_Mode_Mask PWR PVM Mode Mask
  * @{
  */
#define PVM_MODE_IT               0x00010000U    /*!< Mask for interruption yielded by PVM threshold crossing */
#define PVM_MODE_EVT              0x00020000U    /*!< Mask for event yielded by PVM threshold crossing        */
#define PVM_RISING_EDGE           0x00000001U    /*!< Mask for rising edge set as PVM trigger                 */
#define PVM_FALLING_EDGE          0x00000002U    /*!< Mask for falling edge set as PVM trigger                */
/**
  * @}
  */

/** @defgroup PWREx_TimeOut_Value PWR Extended Flag Setting Time Out Value
  * @{
  */
#define PWR_FLAG_SETTING_DELAY_US                      50UL   /*!< Time out value for MR_RDY and VOSF flags setting */
/**
  * @}
  */

/**
  * @}
  */



/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup PWREx_Exported_Functions PWR Extended Exported Functions
  * @{
  */

/** @defgroup PWREx_Exported_Functions_Group1 Extended Peripheral Control functions
  *  @brief   Extended Peripheral Control functions
  *
@verbatim
 ===============================================================================
              ##### Extended Peripheral Initialization and de-initialization functions #####
 ===============================================================================
    [..]

@endverbatim
  * @{
  */
/**
  * @brief Config wakeup from stop mode, enable flash delay time.
  * @param  DelayTime: Specifies the delay time before FLASH control
  *          This parameter can be one of the following values:
  *            - @arg PWR_WAKEUP_FLASH_DELAY_3US: Wake up from the STOP mode, Delay 3us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_5US: Wake up from the STOP mode, Delay 5us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_2US: Wake up from the STOP mode, Delay 2us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_0US: Wake up from the STOP mode, Enable flash immediately
  * @retval None
  */
void HAL_PWREx_SetWakeupFlashDelay(uint32_t DelayTime)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_FLS_WUPT, DelayTime);
}

/**
  * @brief Get wakeup from stop mode, enable flash delay time.
  * @retval Config Flash wakeup delay time.
  *            - @arg PWR_WAKEUP_FLASH_DELAY_3US: Wake up from the STOP mode, Delay 3us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_5US: Wake up from the STOP mode, Delay 5us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_2US: Wake up from the STOP mode, Delay 2us enable flash
  *            - @arg PWR_WAKEUP_FLASH_DELAY_0US: Wake up from the STOP mode, Enable flash immediately
  */
uint32_t HAL_PWREx_GetWakeupFlashDelay(void)
{
  return (PWR->CR1 & PWR_CR1_FLS_WUPT);
}

/**
  * @brief Config wakeup from STANDBY mode MR Ready delay time.
  * @param  DelayTime: Specifies the delay time afte MR Ready.
  *          This parameter can be one of the following values:
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_3US:   Wake up from the STANDY mode, MR Ready Delay 3us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_5US:  Wake up from the STANDY mode, MR Ready Delay 5us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_10US:  Wake up from the STANDY mode, MR Ready Delay 10us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_20US:  Wake up from the STANDY mode, MR Ready Delay 20us
  * @retval None
  */
void HAL_PWREx_SetWakeupMrReadyDelay(uint32_t DelayTime)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_STDBY_MRRDY_WAIT, DelayTime);
}

/**
  * @brief Get wakeup from STANDBY mode MR Ready delay time.
  * @retval Get STANDBY wakeup MR Ready delay time.
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_3US:   Wake up from the STANDY mode, MR Ready Delay 3us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_5US:  Wake up from the STANDY mode, MR Ready Delay 5us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_10US:  Wake up from the STANDY mode, MR Ready Delay 10us
  *            - @arg PWR_WAKEUP_MRREADY_DELAY_20US:  Wake up from the STANDY mode, MR Ready Delay 20us
  */
uint32_t HAL_PWREx_GetWakeupMrReadyDelay(void)
{
  return (PWR->CR1 & PWR_CR1_STDBY_MRRDY_WAIT);
}

/**
  * @brief When wakeup from stop mode,HSI and Main Regulator start at the same time.
  * @retval None
  */
void HAL_PWREx_DisableHSIWakeupWait(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_HSION_CTRL);
}

/**
  * @brief When wakeup from stop mode,HSI enable After Main Regulator stable.
  * @retval None
  */
void HAL_PWREx_EnableHSIWakeupWait(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_HSION_CTRL);
}

/**
  * @brief Configures the main internal regulator output voltage.
  * @param  VoltageScaling specifies the regulator output voltage to achieve
  *         a tradeoff between performance and power consumption.
  *          This parameter can be one of the following values:
  *            @arg PWR_REGULATOR_VOLTAGE_HIGH       : Regulator High voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_MEDIUM     : Regulator Medium voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_MEDIUM_LOW : Regulator Mddium low voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_LOW        : Regulator Low voltage mode
  * @retval None
  */
void HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling)
{  
  assert_param(IS_PWR_VOLTAGE_SCALING_RANGE(VoltageScaling));
  
  /* Set Range */
  __HAL_PWR_VOLTAGESCALING_CONFIG(VoltageScaling);
}

/**
  * @brief Return Voltage Scaling Range.
  * @retval The configured scale for the regulator voltage(VOS bit field).
  *         The returned value can be one of the following:
  *            @arg PWR_REGULATOR_VOLTAGE_HIGH       : Regulator High voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_MEDIUM     : Regulator Medium voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_MEDIUM_LOW : Regulator Mddium low voltage mode
  *            @arg PWR_REGULATOR_VOLTAGE_LOW        : Regulator Low voltage mode
  */  
uint32_t HAL_PWREx_GetVoltageRange(void)
{
  return (PWR->CR1 & PWR_CR1_VOS);
}

/**
  * @brief Configures the backup output voltage.
  * @param  VoltageScaling specifies the backup voltage.
  *          This parameter can be one of the following values:
  *            @arg PWR_SRAM2_VOLTAGE_HIGH       : SRAM2 High voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_MEDIUM     : SRAM2 Medium voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_MEDIUM_LOW : SRAM2 Mddium low voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_LOW        : SRAM2 Low voltage mode,
  * @retval None
  */
void HAL_PWREx_ControlSRAM2VoltageScaling(uint32_t VoltageScaling)
{  
  assert_param(IS_PWR_SRAM2VOLTAGE_SCALING_RANGE(VoltageScaling));
  
  /* Set Range */
  __HAL_PWR_SRAM2VOLTAGESCALING_CONFIG(VoltageScaling);  
}

/**
  * @brief Return Backup Voltage Scaling Range.
  * @retval The configured scale for the Backup voltage.
  *         The returned value can be one of the following:
  *            @arg PWR_SRAM2_VOLTAGE_HIGH       : SRAM2 High voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_MEDIUM     : SRAM2 Medium voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_MEDIUM_LOW : SRAM2 Mddium low voltage mode,
  *            @arg PWR_SRAM2_VOLTAGE_LOW        : SRAM2 Low voltage mode,
  */  
uint32_t HAL_PWREx_GetSRAM2VoltageRange(void)
{
  return (PWR->CR1 & PWR_CR1_SRAM_RETV);
}

/**
  * @brief Enable SRAM2 content retention in Standby mode.
  * @note  When RRS bit is set, SRAM2 is powered by the low-power regulator in
  *         Standby mode and its content is kept.
  * @retval None
  */
void HAL_PWREx_EnableSRAM2ContentRetention(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_RRS);
}

/**
  * @brief Disable SRAM2 content retention in Standby mode.
  * @note  When RRS bit is reset, SRAM2 is powered off in Standby mode
  *        and its content is lost.
  * @retval None
  */
void HAL_PWREx_DisableSRAM2ContentRetention(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_RRS);
}

/**
  * @brief Enter Low-power Run mode
  * @note  In Low-power Run mode, all I/O pins keep the same state as in Run mode.
  * @note  the clock frequency must be reduced below 2 MHz.
  *        The clock frequency must be appropriately reduced before calling 
  *        the HAL_PWREx_EnableLowPowerRunMode() API.
  * @retval None
  */
void HAL_PWREx_EnableLowPowerRunMode(void)
{
  /* Set Regulator parameter */
  SET_BIT(PWR->CR1, PWR_CR1_LPR);
}

/**
  * @brief Exit Low-power Run mode.
  * @note  Before HAL_PWREx_DisableLowPowerRunMode() completion, the function checks that
  *        MR_RDY has been properly set (otherwise, HAL_PWREx_DisableLowPowerRunMode
  *        returns HAL_TIMEOUT status). The system clock frequency can then be
  *        increased above 2 MHz.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_PWREx_DisableLowPowerRunMode(void)
{
  uint32_t wait_loop_index;

  /* Clear LPR bit */
  CLEAR_BIT(PWR->CR1, PWR_CR1_LPR);

  /* Wait until MR_RDY is set */
  wait_loop_index = (PWR_FLAG_SETTING_DELAY_US * (SystemCoreClock / 1000000U));
  while ((HAL_IS_BIT_SET(PWR->SR, PWR_SR_MR_RDY) == 0U) && (wait_loop_index != 0U))
  {
    wait_loop_index--;
  }
  if (HAL_IS_BIT_SET(PWR->SR, PWR_SR_MR_RDY) == 0U)
  {
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}

/**
  * @brief Enter Stop 0 mode.
  * @note  In Stop 0 mode, main and low voltage regulators are ON.
  * @note  In Stop 0 mode, all I/O pins keep the same state as in Run mode.
  * @note  All clocks in the VCORE domain are stopped; the PLL, the HSI
  *        and the HSE oscillators are disabled. Some peripherals with the wakeup capability
  *        (I2Cx, LPUART) can switch on the HSI to receive a frame, and switch off the HSI
  *        after receiving the frame if it is not a wakeup frame. In this case, the HSI clock is propagated
  *        only to the peripheral requesting it.
  *        SRAM1, SRAM2 and register contents are preserved.
  *        The BOR is available.
  * @note  When exiting Stop 0 mode by issuing an interrupt or a wakeup event,
  *         the HSI RC oscillator is selected as system clock.
  * @note  By keeping the internal regulator ON during Stop 0 mode, the consumption
  *         is higher although the startup time is reduced.
  * @param STOPEntry  specifies if Stop mode in entered with WFI or WFE instruction.
  *          This parameter can be one of the following values:
  *            @arg @ref PWR_STOPENTRY_WFI  Enter Stop mode with WFI instruction
  *            @arg @ref PWR_STOPENTRY_WFE  Enter Stop mode with WFE instruction
  * @retval None
  */
void HAL_PWREx_EnterSTOP0Mode(uint8_t STOPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

  /* Stop 0 mode with Main Regulator */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP0);

  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select Stop mode entry --------------------------------------------------*/
  if(STOPEntry == PWR_STOPENTRY_WFI)
  {
    /* Request Wait For Interrupt */
    __WFI();
  }
  else
  {
    /* Request Wait For Event */
    __SEV();
    __WFE();
    __WFE();
  }

  /* Reset SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @brief Enter Stop 1 mode.
  * @note  In Stop 1 mode, only low power voltage regulator is ON.
  * @note  In Stop 1 mode, all I/O pins keep the same state as in Run mode.
  * @note  All clocks in the VCORE domain are stopped; the PLL, the HSI
  *        and the HSE oscillators are disabled. Some peripherals with the wakeup capability
  *        (I2Cx, LPUART) can switch on the HSI to receive a frame, and switch off the HSI
  *        after receiving the frame if it is not a wakeup frame. In this case, the HSI clock is propagated
  *        only to the peripheral requesting it.
  *        SRAM1, SRAM2 and register contents are preserved.
  *        The BOR is available.
  * @note  When exiting Stop 1 mode by issuing an interrupt or a wakeup event,
  *         the HSI RC oscillator is selected as system clock.
  * @note  Due to low power mode, an additional startup delay is incurred when waking up from Stop 1 mode.
  * @param STOPEntry  specifies if Stop mode in entered with WFI or WFE instruction.
  *          This parameter can be one of the following values:
  *            @arg @ref PWR_STOPENTRY_WFI  Enter Stop mode with WFI instruction
  *            @arg @ref PWR_STOPENTRY_WFE  Enter Stop mode with WFE instruction
  * @retval None
  */
void HAL_PWREx_EnterSTOP1Mode(uint8_t STOPEntry)
{
  /* Check the parameters */
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

  /* Stop 1 mode with Low-Power Regulator */
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP1);

  /* Set SLEEPDEEP bit of Cortex System Control Register */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

  /* Select Stop mode entry --------------------------------------------------*/
  if(STOPEntry == PWR_STOPENTRY_WFI)
  {
    /* Request Wait For Interrupt */
    __WFI();
  }
  else
  {
    /* Request Wait For Event */
    __SEV();
    __WFE();
    __WFE();
  }

  /* Reset SLEEPDEEP bit of Cortex System Control Register */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_PWR_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

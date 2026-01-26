/**
  ******************************************************************************
  * @file    py32e407_hal.c
  * @author  MCU Application Team
  * @brief   HAL module driver.
  *          This is the common part of the HAL initialization
  *
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The common HAL driver contains a set of generic and common APIs that can be
    used by the PPP peripheral drivers and the user to start using the HAL.
    [..]
    The HAL contains two APIs' categories:
         (+) Common HAL APIs
         (+) Services HAL APIs

  @endverbatim
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

/** @defgroup HAL HAL
  * @brief HAL module driver.
  * @{
  */

#ifdef HAL_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup HAL_Private_Constants HAL Private Constants
  * @{
  */
/**
 * @brief PY32E407 HAL Driver version number V0.0.1
   */
#define __PY32E407_HAL_VERSION_MAIN   (0x00U) /*!< [31:24] main version */
#define __PY32E407_HAL_VERSION_SUB1   (0x00U) /*!< [23:16] sub1 version */
#define __PY32E407_HAL_VERSION_SUB2   (0x01U) /*!< [15:8]  sub2 version */
#define __PY32E407_HAL_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __PY32E407_HAL_VERSION         ((__PY32E407_HAL_VERSION_MAIN << 24)\
                                        |(__PY32E407_HAL_VERSION_SUB1 << 16)\
                                        |(__PY32E407_HAL_VERSION_SUB2 << 8 )\
                                        |(__PY32E407_HAL_VERSION_RC))

#define IDCODE_DEVID_MASK    0x00000FFFU

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/** @defgroup HAL_Exported_Variables  HAL Exported Variables
  * @{
  */
__IO uint32_t uwTick;
uint32_t uwTickPrio = (1UL << __NVIC_PRIO_BITS); /* Invalid PRIO */
uint32_t uwTickFreq = HAL_TICK_FREQ_DEFAULT;  /* 1KHz */
/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/
/* Exported functions ---------------------------------------------------------*/

/** @defgroup HAL_Exported_Functions HAL Exported Functions
  * @{
  */

/** @defgroup HAL_Exported_Functions_Group1 Initialization and de-initialization Functions
 *  @brief    Initialization and de-initialization functions
 *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
   [..]  This section provides functions allowing to:
      (+) Initializes the Flash interface, the NVIC allocation and initial clock
          configuration. It initializes the systick also when timeout is needed
          and the backup domain when enabled.
      (+) de-Initializes common part of the HAL.
      (+) Configure The time base source to have 1ms time base with a dedicated
          Tick interrupt priority.
        (++) SysTick timer is used by default as source of time base, but user
             can eventually implement his proper time base source (a general purpose
             timer for example or other time source), keeping in mind that Time base
             duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and
             handled in milliseconds basis.
        (++) Time base configuration function (HAL_InitTick ()) is called automatically
             at the beginning of the program after reset by HAL_Init() or at any time
             when clock is configured, by HAL_RCC_ClockConfig().
        (++) Source of time base is configured  to generate interrupts at regular
             time intervals. Care must be taken if HAL_Delay() is called from a
             peripheral ISR process, the Tick interrupt line must have higher priority
            (numerically lower) than the peripheral interrupt. Otherwise the caller
            ISR process will be blocked.
       (++) functions affecting time base configurations are declared as __weak
             to make  override possible  in case of other  implementations in user file.
@endverbatim
  * @{
  */

/**
  * @brief  This function is used to initialize the HAL Library; it must be the first
  *         instruction to be executed in the main program (before to call any other
  *         HAL function), it performs the following:
  *           Configure the Flash prefetch.
  *           Configures the SysTick to generate an interrupt each 1 millisecond,
  *           which is clocked by the HSI (at this stage, the clock is not yet
  *           configured and thus the system is running from the internal HSI at 16 MHz).
  *           Set NVIC Group Priority to 3.
  *           Calls the HAL_MspInit() callback function defined in user file
  *           "py32e407_hal_msp.c" to do the global low level hardware initialization
  *
  * @note   SysTick is used as time base for the HAL_Delay() function, the application
  *         need to ensure that the SysTick time base is always set to 1 millisecond
  *         to have correct HAL operation.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_Init(void)
{
  HAL_StatusTypeDef  status = HAL_OK;
  /* Set Interrupt Group Priority */
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_3);
  
  /* Use SysTick as time base source and configure 1ms tick (default clock after Reset is HSI) */
  if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Init the low level hardware */
    HAL_MspInit();
  }

  /* Return function status */
  return status;
}

/**
  * @brief This function de-Initializes common part of the HAL and stops the systick.
  *        of time base.
  * @note This function is optional.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DeInit(void)
{
  /* Reset of all peripherals */
  __HAL_RCC_APB1_1_FORCE_RESET();
  __HAL_RCC_APB1_1_RELEASE_RESET();
  
  __HAL_RCC_APB1_2_FORCE_RESET();
  __HAL_RCC_APB1_2_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();
  
  __HAL_RCC_AHB1_FORCE_RESET();
  __HAL_RCC_AHB1_RELEASE_RESET();
  
  __HAL_RCC_AHB2_FORCE_RESET();
  __HAL_RCC_AHB2_RELEASE_RESET();

  /* De-Init the low level hardware */
  HAL_MspDeInit();

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initialize the MSP.
  * @retval None
  */
__weak void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes the MSP.
  * @retval None
  */
__weak void HAL_MspDeInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief This function configures the source of the time base.
  *        The time source is configured  to have 1ms time base with a dedicated
  *        Tick interrupt priority.
  * @note This function is called  automatically at the beginning of program after
  *       reset by HAL_Init() or at any time when clock is reconfigured  by HAL_RCC_ClockConfig().
  * @note In the default implementation, SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals.
  *       Care must be taken if HAL_Delay() is called from a peripheral ISR process,
  *       The SysTick interrupt must have higher priority (numerically lower)
  *       than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
  *       The function is declared as __weak  to be overwritten  in case of other
  *       implementation  in user file.
  * @param TickPriority Tick interrupt priority.
  * @retval HAL status
  */
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  /* Configure the SysTick to have interrupt in 1ms time basis*/
  if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
  {
    return HAL_ERROR;
  }

  /* Configure the SysTick IRQ priority */
  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
  {
    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
    uwTickPrio = TickPriority;
  }
  else
  {
    return HAL_ERROR;
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group2 HAL Control functions
  *  @brief    HAL Control functions
  *
@verbatim
 ===============================================================================
                      ##### HAL Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Provide a tick value in millisecond
      (+) Provide a blocking delay in millisecond
      (+) Suspend the time base source interrupt
      (+) Resume the time base source interrupt
      (+) Get the HAL API driver version
      (+) Get the device identifier
      (+) Get the device revision identifier
@endverbatim
  * @{
  */

/**
  * @brief This function is called to increment  a global variable "uwTick"
  *        used as application time base.
  * @note In the default implementation, this variable is incremented each 1ms
  *       in SysTick ISR.
  * @note This function is declared as __weak to be overwritten in case of other
  *      implementations in user file.
  * @retval None
  */
__weak void HAL_IncTick(void)
{
  uwTick += uwTickFreq;
}

/**
  * @brief Provides a tick value in millisecond.
  * @note  This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval tick value
  */
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}

/**
  * @brief This function returns a tick priority.
  * @retval tick priority
  */
uint32_t HAL_GetTickPrio(void)
{
  return uwTickPrio;
}

/**
  * @brief Set new tick Freq.
  * @retval status
  */
HAL_StatusTypeDef HAL_SetTickFreq(uint32_t Freq)
{
  HAL_StatusTypeDef status  = HAL_OK;
  uint32_t prevTickFreq;

  assert_param(IS_TICKFREQ(Freq));

  if (uwTickFreq != Freq)
  {
    /* Back up uwTickFreq frequency */
    prevTickFreq = uwTickFreq;

    /* Update uwTickFreq global variable used by HAL_InitTick() */
    uwTickFreq = Freq;

    /* Apply the new tick Freq  */
    status = HAL_InitTick(uwTickPrio);

    if (status != HAL_OK)
    {
      /* Restore previous tick frequency */
      uwTickFreq = prevTickFreq;
    }
  }

  return status;
}
/**
  * @brief Return tick frequency.
  * @retval tick period in Hz
  */
uint32_t HAL_GetTickFreq(void)
{
  return uwTickFreq;
}

/**
  * @brief This function provides minimum delay (in milliseconds) based
  *        on variable incremented.
  * @note In the default implementation , SysTick timer is the source of time base.
  *       It is used to generate interrupts at regular time intervals where uwTick
  *       is incremented.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @param Delay specifies the delay time length, in milliseconds.
  * @retval None
  */
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
}

/**
  * @brief Suspend Tick increment.
  * @note In the default implementation , SysTick timer is the source of time base. It is
  *       used to generate interrupts at regular time intervals. Once HAL_SuspendTick()
  *       is called, the SysTick interrupt will be disabled and so Tick increment
  *       is suspended.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval None
  */
__weak void HAL_SuspendTick(void)
{
  /* Disable SysTick Interrupt */
  CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief Resume Tick increment.
  * @note In the default implementation , SysTick timer is the source of time base. It is
  *       used to generate interrupts at regular time intervals. Once HAL_ResumeTick()
  *       is called, the SysTick interrupt will be enabled and so Tick increment
  *       is resumed.
  * @note This function is declared as __weak to be overwritten in case of other
  *       implementations in user file.
  * @retval None
  */
__weak void HAL_ResumeTick(void)
{
  /* Enable SysTick Interrupt */
  SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  Returns the HAL revision
  * @retval version 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t HAL_GetHalVersion(void)
{
  return __PY32E407_HAL_VERSION;
}

/**
  * @brief Returns the device revision identifier.
  * Note: On devices PY32E407
  *       Debug registers DBGMCU_IDCODE and DBGMCU_CR are accessible only in
  *       debug mode (not accessible by the user software in normal mode).
  *       Refer to errata sheet of these devices for more details.
  * @retval Device revision identifier
  */
uint32_t HAL_GetREVID(void)
{
  return ((DBGMCU->IDCODE) >> DBGMCU_IDCODE_REV_ID_Pos);
}

/**
  * @brief  Returns the device identifier.
  * Note: On devices PY32E407
  *       Debug registers DBGMCU_IDCODE and DBGMCU_CR are accessible only in
  *       debug mode (not accessible by the user software in normal mode).
  *       Refer to errata sheet of these devices for more details.
  * @retval Device identifier
  */
uint32_t HAL_GetDEVID(void)
{
  return ((DBGMCU->IDCODE) & IDCODE_DEVID_MASK);
}

/**
  * @brief  Returns first word of the unique device identifier (UID based on 512 Bytes)
  * @param  WordNumber Word number to read, this parameter must be a number between 
            Min_Data = 0 and Max_Data = 127
  * @retval Device identifier
  */
uint32_t HAL_GetUID(uint8_t WordNumber)
{
   return(READ_REG(*((uint32_t *)(UID_BASE + WordNumber * 4U))));
}

/**
  * @brief  Returns first word of the unique device identifier
  * @retval Device identifier
  */
uint32_t HAL_GetUIDw0(void)
{
  return (READ_REG(*((uint32_t *)UID_BASE)));
}

/**
  * @brief  Returns second word of the unique device identifier
  * @retval Device identifier
  */
uint32_t HAL_GetUIDw1(void)
{
  return (READ_REG(*((uint32_t *)(UID_BASE + 4U))));
}

/**
  * @brief  Returns third word of the unique device identifier
  * @retval Device identifier
  */
uint32_t HAL_GetUIDw2(void)
{
  return (READ_REG(*((uint32_t *)(UID_BASE + 8U))));
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group3 HAL Debug functions
  *  @brief    HAL Debug functions
  *
@verbatim
 ===============================================================================
                      ##### HAL Debug functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Enable/Disable Debug module during SLEEP mode
      (+) Enable/Disable Debug module during STOP0/STOP1 modes
      (+) Enable/Disable Debug module during STANDBY mode

@endverbatim
  * @{
  */

/**
  * @brief  Enable the Debug Module during SLEEP mode
  * @retval None
  */
void HAL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_SLEEP);
}

/**
  * @brief  Disable the Debug Module during SLEEP mode
  * @retval None
  */
void HAL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_SLEEP);
}

/**
  * @brief  Enable the Debug Module during STOP mode
  * @retval None
  */
void HAL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STOP);
}

/**
  * @brief  Disable the Debug Module during STOP mode
  * @retval None
  */
void HAL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STOP);
}

/**
  * @brief  Enable the Debug Module during STANDBY mode
  * @retval None
  */
void HAL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STDBY);
}

/**
  * @brief  Disable the Debug Module during STANDBY mode
  * @retval None
  */
void HAL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR1, DBGMCU_CR1_DBG_STDBY);
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group4 HAL SYSCFG configuration functions
  *  @brief    HAL SYSCFG configuration functions
  *
@verbatim
 ===============================================================================
                      ##### HAL SYSCFG configuration functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Set/Get memory mapping at address 0x00000000
      (+) Set/Get Ethernet physical interface
      (+) Set/Get remapping of TIM2 internal trigger1
      (+) Enable/Disable analog filter of I2C related IO
      (+) Enable/Disable GPIO Noise Filter
      (+) Enable/Disable GPIO Analog Mode
      (+) Start a hardware CCMSRAM erase operation
      (+) Enable CCMSRAM page write protection

@endverbatim
  * @{
  */

/**
  * @brief  Set memory mapping at address 0x00000000
  * @param  Memory This parameter can be one of the following values:
  *         @arg @ref SYSCFG_BOOT_MAINFLASH
  *         @arg @ref SYSCFG_BOOT_SYSTEMFLASH
  *         @arg @ref SYSCFG_BOOT_ESMC
  *         @arg @ref SYSCFG_BOOT_SRAM
  * @retval None
  */
void HAL_SYSCFG_SetRemapMemory(uint32_t Memory)
{
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_MEM_MODE, Memory);
}

/**
  * @brief  Get memory mapping at address 0x00000000
  * @retval Returned value can be one of the following values:
  *         @arg @ref SYSCFG_BOOT_MAINFLASH
  *         @arg @ref SYSCFG_BOOT_SYSTEMFLASH
  *         @arg @ref SYSCFG_BOOT_ESMC
  *         @arg @ref SYSCFG_BOOT_SRAM
  */
uint32_t HAL_SYSCFG_GetRemapMemory(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_MEM_MODE));
}

/**
  * @brief  Set Ethernet physical interface.
  * @param  Interface This parameter can be one of the following values:
  *         @arg @ref SYSCFG_ETH_PHY_MII
  *         @arg @ref SYSCFG_ETH_PHY_RMII
  * @retval None
  */
void HAL_SYSCFG_SetETHPhysicalInterface(uint32_t Interface)
{
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_ETH_PHYSEL, Interface);
}

/**
  * @brief  Get Ethernet physical interface.
  * @retval Returned value can be one of the following values:
  *         @arg @ref SYSCFG_ETH_PHY_MII
  *         @arg @ref SYSCFG_ETH_PHY_RMII
  */
uint32_t HAL_SYSCFG_GetETHPhysicalInterface(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_ETH_PHYSEL));
}

/**
  * @brief  Remap TIM2 internal trigger1
  * @note   Depending on devices and packages, some timers may not be available.
  *         Refer to device datasheet for timers availability.
  * @param  TIM2IneternalTrigger1 This parameter can be one of the following values:
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_NONE
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR
  * @retval None
  */
void HAL_SYSCFG_SetRemapTIM2InternalTrigger1(uint32_t TIM2IneternalTrigger1)
{    
  /* Check the parameters */
  assert_param(IS_SYSCFG_TIM2_INTERNAL_TRIGGER1(TIM2IneternalTrigger1));
  MODIFY_REG(SYSCFG->CFGR[0], SYSCFG_CFGR1_TIM2ITR1_REMAP, TIM2IneternalTrigger1);
}

/**
  * @brief  Get remapping of TIM2 internal trigger1
  * @note   Depending on devices and packages, some timers may not be available.
  *         Refer to device datasheet for timers availability.
  * @retval Returned value can be one of the following values:
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_NONE
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_USB1_SOF
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_USB2_SOF
  *         @arg @ref SYSCFG_TIM2_INTERNAL_TRIGGER1_ETH_PTP_INTR
  */
uint32_t HAL_SYSCFG_GetRemapTIM2InternalTrigger1(void)
{
  return (READ_BIT(SYSCFG->CFGR[0], SYSCFG_CFGR1_TIM2ITR1_REMAP));
}

/**
  * @brief  Enable analog filter of I2C related IO
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref SYSCFG_I2C_ANF_PA8
  *         @arg @ref SYSCFG_I2C_ANF_PA9
  *         @arg @ref SYSCFG_I2C_ANF_PA13
  *         @arg @ref SYSCFG_I2C_ANF_PA14
  *         @arg @ref SYSCFG_I2C_ANF_PA15
  *         @arg @ref SYSCFG_I2C_ANF_PB5
  *         @arg @ref SYSCFG_I2C_ANF_PB7
  *         @arg @ref SYSCFG_I2C_ANF_PB8
  *         @arg @ref SYSCFG_I2C_ANF_PB9
  *         @arg @ref SYSCFG_I2C_ANF_PC3
  *         @arg @ref SYSCFG_I2C_ANF_PC6
  *         @arg @ref SYSCFG_I2C_ANF_PC7
  *         @arg @ref SYSCFG_I2C_ANF_PC8
  *         @arg @ref SYSCFG_I2C_ANF_PC9
  *         @arg @ref SYSCFG_I2C_ANF_PC11
  *         @arg @ref SYSCFG_I2C_ANF_PF0
  * @retval None
  */
void HAL_SYSCFG_EnableI2CAnalogFilter(uint32_t I2CAnalogFilter)
{    
  /* Check the parameters */
  assert_param(IS_SYSCFG_I2C_ANF_IO(I2CAnalogFilter));
  SET_BIT(SYSCFG->CFGR[0],I2CAnalogFilter);
}

/**
  * @brief  Disable analog filter of I2C related IO
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  I2CAnalogFilter This parameter can be a combination of the following values:
  *         @arg @ref SYSCFG_I2C_ANF_PA8
  *         @arg @ref SYSCFG_I2C_ANF_PA9
  *         @arg @ref SYSCFG_I2C_ANF_PA13
  *         @arg @ref SYSCFG_I2C_ANF_PA14
  *         @arg @ref SYSCFG_I2C_ANF_PA15
  *         @arg @ref SYSCFG_I2C_ANF_PB5
  *         @arg @ref SYSCFG_I2C_ANF_PB7
  *         @arg @ref SYSCFG_I2C_ANF_PB8
  *         @arg @ref SYSCFG_I2C_ANF_PB9
  *         @arg @ref SYSCFG_I2C_ANF_PC3
  *         @arg @ref SYSCFG_I2C_ANF_PC6
  *         @arg @ref SYSCFG_I2C_ANF_PC7
  *         @arg @ref SYSCFG_I2C_ANF_PC8
  *         @arg @ref SYSCFG_I2C_ANF_PC9
  *         @arg @ref SYSCFG_I2C_ANF_PC11
  *         @arg @ref SYSCFG_I2C_ANF_PF0
  * @retval None
  */
void HAL_SYSCFG_DisableI2CAnalogFilter(uint32_t I2CAnalogFilter)
{
  /* Check the parameters */
  assert_param(IS_SYSCFG_I2C_ANF_IO(I2CAnalogFilter)); 
  CLEAR_BIT(SYSCFG->CFGR[0],I2CAnalogFilter);
}

/**
  * @brief  Enable GPIO Noise Filter
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for PY32E4 family
  * @param  GPIO_Pin specifies the pin to be Noise Filter
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void HAL_SYSCFG_EnableGPIONoiseFilter(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  if(GPIOx==GPIOA)
  {    
    SET_BIT(SYSCFG->PAENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOB)
  {
    SET_BIT(SYSCFG->PBENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOC)
  {
    SET_BIT(SYSCFG->PCENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOD)
  {
    SET_BIT(SYSCFG->PDENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOE)
  {
    SET_BIT(SYSCFG->PEENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOF)
  {
    SET_BIT(SYSCFG->PFENS,GPIO_Pin);
  }
  else
  {
    
  }
}

/**
  * @brief  Disable GPIO Noise Filter
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for PY32E4 family
  * @param  GPIO_Pin specifies the pin to be Noise Filter
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void HAL_SYSCFG_DisableGPIONoiseFilter(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  if(GPIOx==GPIOA)
  {    
    CLEAR_BIT(SYSCFG->PAENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOB)
  {
    CLEAR_BIT(SYSCFG->PBENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOC)
  {
    CLEAR_BIT(SYSCFG->PCENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOD)
  {
    CLEAR_BIT(SYSCFG->PDENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOE)
  {
    CLEAR_BIT(SYSCFG->PEENS,GPIO_Pin);
  }
  else if(GPIOx==GPIOF)
  {
    CLEAR_BIT(SYSCFG->PFENS,GPIO_Pin);
  }
  else
  {
    
  }
}

/**
  * @brief  Enable GPIO Analog Mode
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOx where x can be (A..E) to select the GPIO peripheral for PY32E4 family
  * @param  GPIO_Pin specifies the pin to be Analog Mode
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void HAL_SYSCFG_EnableGPIOAnalogMode(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  if(GPIOx==GPIOA)
  {    
    SET_BIT(SYSCFG->PAANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOB)
  {
    SET_BIT(SYSCFG->PBANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOC)
  {
    SET_BIT(SYSCFG->PCANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOD)
  {
    SET_BIT(SYSCFG->PDANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOE)
  {
    SET_BIT(SYSCFG->PEANA2ENR,GPIO_Pin);
  }
  else
  {
    
  }
}

/**
  * @brief  Disable GPIO Analog Mode
  * @note   Depending on devices and packages, some IOs may not be available.
  *         Refer to device datasheet for IOs availability.
  * @param  GPIOx where x can be (A..E) to select the GPIO peripheral for PY32E4 family
  * @param  GPIO_Pin specifies the pin to be Analog Mode
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void HAL_SYSCFG_DisableGPIOAnalogMode(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));
 if(GPIOx==GPIOA)
  {    
    CLEAR_BIT(SYSCFG->PAANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOB)
  {
    CLEAR_BIT(SYSCFG->PBANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOC)
  {
    CLEAR_BIT(SYSCFG->PCANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOD)
  {
    CLEAR_BIT(SYSCFG->PDANA2ENR,GPIO_Pin);
  }
  else if(GPIOx==GPIOE)
  {
    CLEAR_BIT(SYSCFG->PEANA2ENR,GPIO_Pin);
  }
  else
  {
    
  }
}

/**
  * @brief  Enable PVD_IN Analog Mode
  * @retval None
  */
void HAL_SYSCFG_EnablePVD_IN_AnalogMode(void)
{
  SET_BIT(SYSCFG->PVDINANA2ENR, SYSCFG_PVDINANA2ENR_PVDIN_ENA2);
}

/**
  * @brief  Disable PVD_IN Analog Mode
  * @retval None
  */
void HAL_SYSCFG_DisablePVD_IN_AnalogMode(void)
{
  CLEAR_BIT(SYSCFG->PVDINANA2ENR, SYSCFG_PVDINANA2ENR_PVDIN_ENA2);
}

/**
  * @brief  Start a hardware CCMSRAM erase operation.
  * @note   As long as CCMSRAM is not erased the CCMER bit will be set.
  *         This bit is automatically reset at the end of the CCMSRAM erase operation.
  * @retval None
  */
void HAL_SYSCFG_CCMSRAMErase(void)
{
  /* unlock the write protection of the CCMER bit */
  SYSCFG->SKR = 0xCA;
  SYSCFG->SKR = 0x53;
  /* Starts a hardware CCMSRAM erase operation*/
  SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_CCMER);
}

/** @brief  CCMSRAM page write protection enable
  * @param Page: This parameter is a long 32bit value and can be a value of @ref SYSCFG_CCMSRAMWRP
  * @note   write protection can only be disabled by a system reset
  * @retval None
  */
void HAL_SYSCFG_CCMSRAM_WriteProtectionEnable(uint32_t Page)
{
  assert_param(IS_SYSCFG_CCMSRAMWRP_PAGE(Page));

  SET_BIT(SYSCFG->SWPR, (uint32_t)(Page));
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

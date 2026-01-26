/**
  ******************************************************************************
  * @file    py32e407_hal_rcc.c
  * @author  MCU Application Team
  * @brief   RCC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and Clock Control (RCC) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *
  @verbatim
  ==============================================================================
                      ##### RCC specific features #####
  ==============================================================================
    [..]
      After reset the device is running from Internal High Speed oscillator
      (HSI 16MHz) with Flash 0 wait state, Flash prefetch buffer is enabled,
      and all peripherals are off except internal SRAM, Flash and JTAG.
      (+) There is no prescaler on High speed (AHB) and Low speed (APB) buses;
          all peripherals mapped on these buses are running at HSI speed.
      (+) The clock for all peripherals is switched off, except the SRAM and FLASH.
      (+) All GPIOs are in input floating state, except the JTAG pins which
          are assigned to be used for debug purpose.
    [..] Once the device started from reset, the user application has to:
      (+) Configure the clock source to be used to drive the System clock
          (if the application needs higher frequency/performance)
      (+) Configure the System clock frequency and Flash settings
      (+) Configure the AHB and APB buses prescalers
      (+) Enable the clock for the peripheral(s) to be used
      (+) Configure the clock source(s) for peripherals whose clocks are not
          derived from the System clock ( RTC, ADC, PVD, USB, CAN )

                      ##### RCC Limitations #####
  ==============================================================================
    [..]
      A delay between an RCC peripheral clock enable and the effective peripheral
      enabling should be taken into account in order to manage the peripheral read/write
      from/to registers.
      (+) This delay depends on the peripheral mapping.
        (++) AHB & APB peripherals, 1 dummy read is necessary

    [..]
      Workarounds:
      (#) For AHB & APB peripherals, a dummy read to the peripheral register has been
          inserted in each __HAL_RCC_PPP_CLK_ENABLE() macro.

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

/** @defgroup RCC RCC
* @brief RCC HAL module driver
  * @{
  */
#ifdef HAL_RCC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup RCC_Private_Constants RCC Private Constants
 * @{
 */
/**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/** @defgroup RCC_Private_Functions RCC Private Functions
  * @{
  */
static uint32_t          RCC_GetSysClockFreqFromPLLSource(void);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup RCC_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  @verbatim
  ===============================================================================
           ##### Initialization and de-initialization functions #####
  ===============================================================================
    [..]
      This section provides functions allowing to configure the internal/external oscillators
      (HSE, HSI, LSE, LSI, PLL, CSS and MCO) and the System buses clocks (SYSCLK, AHB, APB1
      and APB2).

    [..] Internal/external clock and PLL configuration
      (#) HSI (high-speed internal), 16 MHz factory-trimmed RC used directly or through
          the PLL as System clock source.
      (#) LSI (low-speed internal), ~40 KHz low consumption RC used as IWDG and/or RTC
          clock source.

      (#) HSE (high-speed external), 4 to 32 MHz (PY32E407) crystal oscillator used directly or
          through the PLL as System clock source. Can be used also as RTC clock source.

      (#) LSE (low-speed external), 32 KHz oscillator used as RTC clock source.

      (#) PLL (clocked by HSI or HSE), featuring different output clocks:
        (++) The first output is used to generate the high speed system clock 
        (++) The second output is used to generate the clock for the USB (48 MHz)

      (#) CSS (Clock security system), once enable using the function HAL_RCC_EnableCSS()
          and if a HSE clock failure occurs(HSE used directly or through PLL as System
          clock source), the System clocks automatically switched to HSI and an interrupt
          is generated if enabled. The interrupt is linked to the Cortex-M4 NMI
          (Non-Maskable Interrupt) exception vector.

      (#) MCO (microcontroller clock output), used to output SYSCLK, HSI,
          HSE or PLL clock (divided by 2) on PA8 pin

    [..] System, AHB and APB buses clocks configuration
      (#) Several clock sources can be used to drive the System clock (SYSCLK): HSI,
          HSE and PLL.
          The AHB clock (HCLK) is derived from System clock through configurable
          prescaler and used to clock the CPU, memory and peripherals mapped
          on AHB bus (DMA, GPIO...). APB1 (PCLK1) and APB2 (PCLK2) clocks are derived
          from AHB clock through configurable prescalers and used to clock
          the peripherals mapped on these buses. You can use
          "@ref HAL_RCC_GetSysClockFreq()" function to retrieve the frequencies of these clocks.

      -@- All the peripheral clocks are derived from the System clock (SYSCLK) except:
          (+@) RTC: RTC clock can be derived either from the LSI, LSE or HSE clock
              divided by 128.
          (+@) USB : USB require a frequency equal to 48 MHz
              to work correctly. This clock is derived of the main PLL through PLL Multiplier.
          (+@) IWDG clock which is always the LSI clock.
  @endverbatim
  * @{
  */

/*
  Additional consideration on the SYSCLK based on Latency settings:
        +-----------------------------------------------+
        | Latency       | SYSCLK clock frequency (MHz)  |
        |---------------|-------------------------------|
        |0WS(1CPU cycle)|       0 < SYSCLK <= 25        |
        |---------------|-------------------------------|
        |1WS(2CPU cycle)|      25 < SYSCLK <= 50        |
        |---------------|-------------------------------|
        |3WS(4CPU cycle)|      50 < SYSCLK <= 75        |
        |---------------|-------------------------------|
        |4WS(5CPU cycle)|      75 < SYSCLK <= 100       |
        |---------------|-------------------------------|
        |5WS(6CPU cycle)|     100 < SYSCLK <= 125       |
        |---------------|-------------------------------|
        |6WS(7CPU cycle)|     125 < SYSCLK <= 150       |
        |---------------|-------------------------------|
        |7WS(8CPU cycle)|     150 < SYSCLK <= 170       |
        +-----------------------------------------------+
  */

/**
  * @brief  Resets the RCC clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *            - HSI ON and used as system clock source
  *            - HSE, PLL are OFF
  *            - AHB, APB1 and APB2 prescaler set to 1.
  *            - CSS and MCO1 OFF
  *            - All interrupts disabled
  *            - All flags are cleared
  * @note   This function does not modify the configuration of the
  *            - Peripheral clocks
  *            - LSI, LSE and RTC clocks
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_RCC_DeInit(void)
{
  uint32_t tickstart;

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Set HSION bit */
  SET_BIT(RCC->CR, RCC_CR_HSION);

  /* Wait till HSI is ready */
  while (READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RESET)
  {
    if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* HSI used as system clock source. Reset AHB, APB1, APB2 prescaler and the output clock of MCO */
  RCC->CFGR = (RCC->CFGR & 0x00FF0000);

  /* Reset the division coefficients of MCO */
  RCC->CFGR1 = (RCC->CFGR1 & 0xFFFFFFF8);

  /* Wait till clock switch is ready */
  while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
  {
    if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HSI_VALUE;

  /* Adapt Systick interrupt period */
  if (HAL_InitTick(uwTickPrio) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Second step is to clear PLLON bit */
  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);

  /* Wait till PLL is disabled */
  while (READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Ensure to reset PLLSRC and PLLMUL bits */
  CLEAR_REG(RCC->CFGR3);

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Reset HSEON & CSSON bits */
  CLEAR_BIT(RCC->CR, RCC_CR_HSEON | RCC_CR_CSSON);

  /* Wait till HSE is disabled */
  while (READ_BIT(RCC->CR, RCC_CR_HSERDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Reset HSEBYP bit */
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);

  /* Reset HSE drive capability */
  RCC->CFGR2 = (RCC->CFGR2 & 0x0000000F);

  /* Disable all interrupts */
  CLEAR_REG(RCC->CIR);

  /* Clear all interrupt flags */
  WRITE_REG(RCC->CIR, 0x00BF0000U);

  /* Reset all CSR flags */
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);

  return HAL_OK;
}

/**
  * @brief  Initializes the RCC Oscillators according to the specified parameters in the
  *         RCC_OscInitTypeDef.
  * @param  RCC_OscInitStruct pointer to an RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC Oscillators.
  * @note   The PLL is not disabled when used as system clock.
  * @note   The PLL is not disabled when USB clock is enabled (specific to devices with USB )
  * @note   Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not
  *         supported by this macro. User should request a transition to LSE Off
  *         first and then LSE On or LSE Bypass.
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this macro. User should request a transition to HSE Off
  *         first and then HSE On or HSE Bypass.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  uint32_t tickstart;
  uint32_t pll_config;

  /* Check Null pointer */
  if (RCC_OscInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_OSCILLATORTYPE(RCC_OscInitStruct->OscillatorType));

  /*------------------------------- HSE Configuration ------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSE(RCC_OscInitStruct->HSEState));
    assert_param(IS_RCC_HSE_FREQ(RCC_OscInitStruct->HSEFreq));

    /* When the HSE is used as system clock or clock source for PLL in these cases it is not allowed to be disabled */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSE) \
        || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) \
            && ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE) || (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE_DIV2))))
    {
      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET) && (RCC_OscInitStruct->HSEState == RCC_HSE_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {
      if (RCC_OscInitStruct->HSEState == RCC_HSE_ON)
      {
        __HAL_RCC_HSE_CONFIG(RCC_HSE_OFF);
        
        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSE is off */
        while (READ_BIT(RCC->CR, RCC_CR_HSERDY) == SET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
        
        /*Set HSE Driver*/
        __HAL_RCC_HSE_FREQ_CONFIG(RCC_OscInitStruct->HSEFreq);
      }
      
      /* Set the new HSE configuration ---------------------------------------*/
      __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);

      /* Check the HSE State */
      if (RCC_OscInitStruct->HSEState != RCC_HSE_OFF)
      {
#ifndef RCC_NO_DETECT_HSE_READY
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSE is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
#endif
      }
      else
      {
        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSE is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  /*----------------------------- HSI Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI(RCC_OscInitStruct->HSIState));

    /* Check if HSI is used as system clock or as PLL source when PLL is selected as system clock */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_HSI) \
        || ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_SYSCLKSOURCE_STATUS_PLLCLK) \
            && ((__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSI_DIV2))))
    {
      /* When HSI is used as system clock it will not disabled */
      if ((__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET) && (RCC_OscInitStruct->HSIState != RCC_HSI_ON))
      {
        return HAL_ERROR;
      }
    }
    else
    {
      /* Check the HSI State */
      if (RCC_OscInitStruct->HSIState != RCC_HSI_OFF)
      {
        /* Enable the Internal High Speed oscillator (HSI). */
        __HAL_RCC_HSI_ENABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSI is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Disable the Internal High Speed oscillator (HSI). */
        __HAL_RCC_HSI_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till HSI is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  /*----------------------------- HSI48M Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI48M) == RCC_OSCILLATORTYPE_HSI48M)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI48M(RCC_OscInitStruct->HSI48MState));
    
    /* Check the HSI State */
    if (RCC_OscInitStruct->HSI48MState != RCC_HSI48M_OFF)
    {
      /* Enable the Internal High Speed oscillator (HSI). */
      __HAL_RCC_HSI48M_ENABLE();

      /* Get Start Tick */
      tickstart = HAL_GetTick();

      /* Wait till HSI48M is ready */
      while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSI48MRDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > HSI48M_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Disable the Internal 48MHz High Speed oscillator (HSI48MHz). */
      __HAL_RCC_HSI48M_DISABLE();

      /* Get Start Tick */
      tickstart = HAL_GetTick();

      /* Wait till HSI48M is disabled */
      while (__HAL_RCC_GET_FLAG(RCC_FLAG_HSI48MRDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > HSI48M_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }
  /*------------------------------ LSI Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LSI(RCC_OscInitStruct->LSIState));

    /* Check the LSI State */
    if (RCC_OscInitStruct->LSIState != RCC_LSI_OFF)
    {
      /* Enable the Internal Low Speed oscillator (LSI). */
      __HAL_RCC_LSI_ENABLE();

      /* Get Start Tick */
      tickstart = HAL_GetTick();

      /* Wait till LSI is ready */
      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Disable the Internal Low Speed oscillator (LSI). */
      __HAL_RCC_LSI_DISABLE();

      /* Get Start Tick */
      tickstart = HAL_GetTick();

      /* Wait till LSI is disabled */
      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSIRDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }
  /*------------------------------ LSE Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)
  {
    FlagStatus       pwrclkchanged = RESET;

    /* Check the parameters */
    assert_param(IS_RCC_LSE(RCC_OscInitStruct->LSEState));
    assert_param(IS_RCC_LSE_DRIVER(RCC_OscInitStruct->LSEDriver));

    /* Update LSE configuration in Backup Domain control register    */
    /* Requires to enable write access to Backup Domain of necessary */
    if (__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
     {
      /* Enable write access to Backup domain */
      SET_BIT(PWR->CR1, PWR_CR1_DBP);

      /* Wait for Backup domain Write protection disable */
      tickstart = HAL_GetTick();

      while (HAL_IS_BIT_CLR(PWR->CR1, PWR_CR1_DBP))
      {
        if ((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    
    if (RCC_OscInitStruct->LSEState == RCC_LSE_ON)
    {
      __HAL_RCC_LSE_CONFIG(RCC_LSE_OFF);
      
      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till LSE is off */
      while (READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == SET)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
      /*Set LSE Driver*/
      __HAL_RCC_LSE_DRIVER_CONFIG(RCC_OscInitStruct->LSEDriver);
    }

    /* Set the new LSE configuration -----------------------------------------*/
    __HAL_RCC_LSE_CONFIG(RCC_OscInitStruct->LSEState);
    /* Check the LSE State */
    if (RCC_OscInitStruct->LSEState != RCC_LSE_OFF)
    {
      /* Get Start Tick */
      tickstart = HAL_GetTick();

      /* Wait till LSE is ready */
      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Get Start Tick */
      tickstart = HAL_GetTick();

      /* Wait till LSE is disabled */
      while (__HAL_RCC_GET_FLAG(RCC_FLAG_LSERDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }

    /* Require to disable power clock if necessary */
    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }

  /*-------------------------------- PLL Configuration -----------------------*/
  /* Check the parameters */
  assert_param(IS_RCC_PLL(RCC_OscInitStruct->PLL.PLLState));
  if ((RCC_OscInitStruct->PLL.PLLState) != RCC_PLL_NONE)
  {
    /* Check if the PLL is used as system clock or not */
    if (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_SYSCLKSOURCE_STATUS_PLLCLK)
    {
      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_ON)
      {
        /* Check the parameters */
        assert_param(IS_RCC_PLLSOURCE(RCC_OscInitStruct->PLL.PLLSource));
        assert_param(IS_RCC_PLL_MUL(RCC_OscInitStruct->PLL.PLLMUL));
        assert_param(IS_RCC_PLL_PREDIV(RCC_OscInitStruct->PLL.PLLPrediv));
        assert_param(IS_RCC_PLL_POSTDIV(RCC_OscInitStruct->PLL.PLLPostdiv));

        /* Disable the main PLL. */
        __HAL_RCC_PLL_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till PLL is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        /* Configure the main PLL clock source, prediv factor, postdiv factor, and multiplication factors. */
        __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLSource,
                             RCC_OscInitStruct->PLL.PLLMUL,
                             RCC_OscInitStruct->PLL.PLLPrediv,
                             RCC_OscInitStruct->PLL.PLLPostdiv);
        /* Enable the main PLL. */
        __HAL_RCC_PLL_ENABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till PLL is ready */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  == RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Disable the main PLL. */
        __HAL_RCC_PLL_DISABLE();

        /* Get Start Tick */
        tickstart = HAL_GetTick();

        /* Wait till PLL is disabled */
        while (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY)  != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    else
    {
      /* Check if there is a request to disable the PLL used as System clock source */
      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_OFF)
      {
        return HAL_ERROR;
      }
      else
      {
        /* Do not return HAL_ERROR if request repeats the current configuration */
        pll_config = RCC->CFGR3;
        if ((READ_BIT(pll_config, (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) != RCC_OscInitStruct->PLL.PLLSource) ||
            (READ_BIT(pll_config, RCC_CFGR3_PLLPREDIV) != RCC_OscInitStruct->PLL.PLLPrediv) ||
            (((READ_BIT(pll_config, RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U) != RCC_OscInitStruct->PLL.PLLMUL) ||
            (READ_BIT(pll_config, RCC_CFGR3_PLLPOSTDIV) != RCC_OscInitStruct->PLL.PLLPostdiv))
        {
          return HAL_ERROR;
        }
      }
    }
  }

  return HAL_OK;
}

/**
  * @brief  Initializes the CPU, AHB and APB buses clocks according to the specified
  *         parameters in the RCC_ClkInitStruct.
  * @param  RCC_ClkInitStruct pointer to an RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC peripheral.
  * @param  FLatency FLASH Latency
  *          The value of this parameter depend on device used within the same series
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency
  *         and updated by @ref HAL_RCC_GetHCLKFreq() function called within this function
  *
  * @note   The HSI is used (enabled by hardware) as system clock source after
  *         start-up from Reset, wake-up from STOP and STANDBY mode, or in case
  *         of failure of the HSE used directly or indirectly as system clock
  *         (if the Clock Security System CSS is enabled).
  *
  * @note   A switch from one clock source to another occurs only if the target
  *         clock source is ready (clock stable after start-up delay or PLL locked).
  *         If a clock source which is not yet ready is selected, the switch will
  *         occur when the clock source will be ready.
  *         You can use @ref HAL_RCC_GetClockConfig() function to know which clock is
  *         currently used as system clock source.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency)
{
  uint32_t tickstart;
  uint32_t pllfreq;
  uint32_t hpre = RCC_SYSCLK_DIV1;

  /* Check Null pointer */
  if (RCC_ClkInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_CLOCKTYPE(RCC_ClkInitStruct->ClockType));
  assert_param(IS_FLASH_LATENCY(FLatency));

  /* To correctly read data from FLASH memory, the number of wait states (LATENCY)
  must be correctly programmed according to the frequency of the CPU clock
    (HCLK) and the supply voltage of the device. */

#if defined(FLASH_ACR_LATENCY)
  /* Increasing the number of wait states because of higher CPU frequency */
  if (FLatency > __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLatency);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by reading the FLASH_ACR register */
    if (__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      return HAL_ERROR;
    }
  }

#endif /* FLASH_ACR_LATENCY */

  /*-------------------------- HCLK Configuration --------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_HCLK) == RCC_CLOCKTYPE_HCLK)
  {
    /* Set the highest APB divider in order to ensure that we do not go through
       a non-spec phase whatever we decrease or increase HCLK. */
    if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
    {
      MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_HCLK_DIV16);
    }
    if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
    {
      MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_HCLK_DIV16 << 3U);
    }

    /* Set the new HCLK clock divider */
    assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_ClkInitStruct->AHBCLKDivider);
  }
  
  /*------------------------- SYSCLK Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK)
  {
    assert_param(IS_RCC_SYSCLKSOURCE(RCC_ClkInitStruct->SYSCLKSource));

    /* PLL is selected as System Clock Source */
    if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {
      /* Check the PLL ready flag */
      if (__HAL_RCC_GET_FLAG(RCC_FLAG_PLLRDY) == RESET)
      {
        return HAL_ERROR;
      }
      /* Undershoot management when selection PLL as SYSCLK source and frequency above 80Mhz */
      /* Compute target PLL output frequency */
      pllfreq = RCC_GetSysClockFreqFromPLLSource();
    }
    else
    {
      /* HSE is selected as System Clock Source */
      if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_HSE)
      {
        /* Check the HSE ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_HSERDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
      /* HSI is selected as System Clock Source */
      else
      {
        /* Check the HSI ready flag */
        if(__HAL_RCC_GET_FLAG(RCC_FLAG_HSIRDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
      /* Overshoot management when going down from PLL as SYSCLK source and frequency above 80Mhz */
      pllfreq = HAL_RCC_GetSysClockFreq();
    }
    
    /* Before reducing the HCLK frequency below 80MHz or increasing it above 80MHz, 
    it is necessary to use 2 as an intermediate step for the prescaler */
    if(pllfreq > 80000000U)
    {
      if (READ_BIT(RCC->CFGR, RCC_CFGR_HPRE) == RCC_SYSCLK_DIV1)
      {
        MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_SYSCLK_DIV2);
        hpre = RCC_SYSCLK_DIV2;
      }
    }
    
    __HAL_RCC_SYSCLK_CONFIG(RCC_ClkInitStruct->SYSCLKSource);

    /* Get Start Tick */
    tickstart = HAL_GetTick();

    while (__HAL_RCC_GET_SYSCLK_SOURCE() != (RCC_ClkInitStruct->SYSCLKSource << RCC_CFGR_SWS_Pos))
    {
      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }

  /*-------------------------- HCLK Configuration --------------------------*/
  /* Is intermediate HCLK prescaler 2 applied internally, complete with HCLK prescaler 1 */
  if(hpre == RCC_SYSCLK_DIV2)
  {
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_SYSCLK_DIV1);
  }

#if defined(FLASH_ACR_LATENCY)
  /* Decreasing the number of wait states because of lower CPU frequency */
  if (FLatency < __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLatency);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by polling the FLASH_ACR register */
    tickstart = HAL_GetTick();

    while (__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
      {
        return HAL_TIMEOUT;
      }
    }
  }
#endif /* FLASH_ACR_LATENCY */

/*-------------------------- PCLK1 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB1CLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_ClkInitStruct->APB1CLKDivider);
  }

  /*-------------------------- PCLK2 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
  {
    assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB2CLKDivider));
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, ((RCC_ClkInitStruct->APB2CLKDivider) << 3U));
  }

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR & RCC_CFGR_HPRE) >> RCC_CFGR_HPRE_Pos];

  /* Configure the source of time base considering new system clocks settings*/
  return HAL_InitTick(uwTickPrio);
}

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions_Group2 Peripheral Control functions
  *  @brief   RCC clocks control functions
  *
  @verbatim
  ===============================================================================
                  ##### Peripheral Control functions #####
  ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the RCC Clocks
    frequencies.

  @endverbatim
  * @{
  */

/**
  * @brief  Select the clock source to output on MCO pin(PA8/PF5).
  * @note   PA8/PF5 should be configured in alternate function mode.
  * @note   The default configuration of the GPIOF pin 5 (PF5) is set to reset mode (NRST pin)
  *         and user shall set the NRST_MODE Bit in the FLASH OPTR register to be able to use it 
  *         as an MCO pin.
  *         The @ref HAL_FLASH_OBProgram() API can be used to configure the NRST_MODE Bit value.
  * @param  RCC_MCOx  specifies the output direction for the clock source.
  *          For PY32E407xx family this parameter can have only one value:
  *            @arg @ref RCC_MCO1  Clock source to output on MCO1 pin(PA8).
  *            @arg @ref RCC_MCO2  Clock source to output on MCO1 pin(PF5).
  * @param  RCC_MCOSource  specifies the clock source to output.
  *          This parameter can be one of the following values:
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
  * @param  RCC_MCODiv  specifies the MCO prescaler.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1  no division applied to MCO clock
  *            @arg @ref RCC_MCODIV_2  division by 2 applied to MCO clock
  *            @arg @ref RCC_MCODIV_4  division by 4 applied to MCO clock
  *            @arg @ref RCC_MCODIV_8  division by 8 applied to MCO clock
  *            @arg @ref RCC_MCODIV_16  division by 16 applied to MCO clock
  *            @arg @ref RCC_MCODIV_32  division by 32 applied to MCO clock
  *            @arg @ref RCC_MCODIV_64  division by 64 applied to MCO clock
  *            @arg @ref RCC_MCODIV_128  division by 128 applied to MCO clock
  * @retval None
  */
void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Check the parameters */
  assert_param(IS_RCC_MCO(RCC_MCOx));
  assert_param(IS_RCC_MCODIV(RCC_MCODiv));
  assert_param(IS_RCC_MCOSOURCE(RCC_MCOSource));

  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  switch(RCC_MCOx)
  {
    case RCC_MCO2 :  /* Configure PF05 as the clock output */
      __HAL_RCC_GPIOF_CLK_ENABLE();
      GPIO_InitStruct.Pin = GPIO_PIN_5;
      GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
      HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
      break;
    case RCC_MCO1 :  /* PA08 */
    default :
      __HAL_RCC_GPIOA_CLK_ENABLE();
      GPIO_InitStruct.Pin = GPIO_PIN_8;
      GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
      break;
  }

    /* Mask MCO[] and MCOPRE[] bits then set MCO clock source and prescaler */
    MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, RCC_MCOSource);
    MODIFY_REG(RCC->CFGR1, RCC_CFGR1_MCOPRE, RCC_MCODiv);
}

/**
  * @brief  Enables the Clock Security System.
  * @note   If a failure is detected on the HSE oscillator clock, this oscillator
  *         is automatically disabled and an interrupt is generated to inform the
  *         software about the failure (Clock Security System Interrupt, CSSI),
  *         allowing the MCU to perform rescue operations. The CSSI is linked to
  *         the Cortex-M4 NMI (Non-Maskable Interrupt) exception vector.
  * @retval None
  */
void HAL_RCC_EnableCSS(void)
{
  SET_BIT(RCC->CR, RCC_CR_CSSON);
}

/**
  * @brief  Returns the SYSCLK frequency
  * @note   The system frequency computed by this function is not the real
  *         frequency in the chip. It is calculated based on the predefined
  *         constant and the selected clock source:
  * @note     If SYSCLK source is HSI, function returns values based on HSI_VALUE(*)
  * @note     If SYSCLK source is HSE, function returns a value based on HSE_VALUE(**)
  * @note     If SYSCLK source is PLL, function returns values based on HSE_VALUE(**),
  *           HSI_VALUE(*) Value multiplied/divided by the PLL factors.
  * @note     (*) HSI_VALUE is a constant defined in py32e407_hal_conf.h file,
  *               but the real value may vary depending on the variations
  *               in voltage and temperature.
  * @note     (**) HSE_VALUE is a constant defined in py32e407_hal_conf.h file,
  *                user has to ensure that HSE_VALUE is same as the real
  *                frequency of the crystal used. Otherwise, this function may
  *                have wrong result.
  *
  * @note   The result of this function could be not correct when using fractional
  *         value for HSE crystal.
  *
  * @note   This function can be used by the user application to compute the
  *         baud-rate for the communication peripherals or configure other parameters.
  *
  * @note   Each time SYSCLK changes, this function must be called to update the
  *         right SYSCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  * @retval SYSCLK frequency
  */
uint32_t HAL_RCC_GetSysClockFreq(void)
{
  const uint8_t aDivFactorTable[4] = {1, 2, 4, 8};
  const uint8_t aXTPredivFactorTable[2] = {1, 2};

  uint32_t tmpreg = 0U, tmppllreg=0, pllxtprediv = 0U, pllclk = 0U, pllmul = 0U, pllprediv = 0U, pllpostdiv = 0U;
  uint32_t sysclockfreq = 0U;

  tmpreg = RCC->CFGR;
  
  tmppllreg = RCC->CFGR3;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (tmpreg & RCC_CFGR_SWS)
  {
    case RCC_SYSCLKSOURCE_STATUS_HSE:  /* HSE used as system clock */
    {
      sysclockfreq = HSE_VALUE;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_PLLCLK:  /* PLL used as system clock */
    {
      pllprediv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPREDIV) >> RCC_CFGR3_PLLPREDIV_Pos];
      pllpostdiv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPOSTDIV) >> RCC_CFGR3_PLLPOSTDIV_Pos];
      pllmul = (READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U;
      if (((tmppllreg & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) == RCC_PLLSOURCE_HSE) || \
          ((tmppllreg & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) == RCC_PLLSOURCE_HSE_DIV2))
      {
        pllxtprediv = aXTPredivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLXTPRE) >> RCC_CFGR3_PLLXTPRE_Pos];
        
        /* HSE used as PLL clock source : PLLCLK = (HSE / PLLXTPREDIV) / PLLPREDIV * PLLMUL / PLLLPOSTDIV */
        pllclk = (uint32_t)((HSE_VALUE / pllxtprediv) / pllprediv * pllmul / pllpostdiv);
      }
      else
      {
        /* HSI used as PLL clock source : PLLCLK = HSI/2 / PLLPREDIV * PLLMUL / PLLLPOSTDIV */
        pllclk = (uint32_t)((HSI_VALUE >> 1U) / pllprediv * pllmul / pllpostdiv);
      }
      sysclockfreq = pllclk;
      break;
    }
    case RCC_SYSCLKSOURCE_STATUS_HSI:  /* HSI used as system clock source */
    default: /* HSI used as system clock */
    {
      sysclockfreq = HSI_VALUE;
      break;
    }
  }
  return sysclockfreq;
}

/**
  * @brief  Returns the HCLK frequency
  * @note   Each time HCLK changes, this function must be called to update the
  *         right HCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency
  *         and updated within this function
  * @retval HCLK frequency
  */
uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return SystemCoreClock;
}

/**
  * @brief  Returns the PCLK1 frequency
  * @note   Each time PCLK1 changes, this function must be called to update the
  *         right PCLK1 value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK1 frequency
  */
uint32_t HAL_RCC_GetPCLK1Freq(void)
{
  /* Get HCLK source and Compute PCLK1 frequency ---------------------------*/
  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos]);
}

/**
  * @brief  Returns the PCLK2 frequency
  * @note   Each time PCLK2 changes, this function must be called to update the
  *         right PCLK2 value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK2 frequency
  */
uint32_t HAL_RCC_GetPCLK2Freq(void)
{
  /* Get HCLK source and Compute PCLK2 frequency ---------------------------*/
  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos]);
}

/**
  * @brief  Configures the RCC_OscInitStruct according to the internal
  * RCC configuration registers.
  * @param  RCC_OscInitStruct pointer to an RCC_OscInitTypeDef structure that
  * will be configured.
  * @retval None
  */
void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  /* Check the parameters */
  assert_param(RCC_OscInitStruct != NULL);

  /* Set all possible values for the Oscillator type parameter ---------------*/
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI  \
                                      | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI  \
                                      | RCC_OSCILLATORTYPE_HSI48M;

  /* Get the HSE configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSEBYP) == RCC_CR_HSEBYP)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_BYPASS;
  }
  else if ((RCC->CR & RCC_CR_HSEON) == RCC_CR_HSEON)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_ON;
  }
  else
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_OFF;
  }
  RCC_OscInitStruct->HSEFreq = (uint32_t)(RCC->CFGR2 & RCC_CFGR2_HSEDRV);
  
  /* Get the HSI configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSION) == RCC_CR_HSION)
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_ON;
  }
  else
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_OFF;
  }

  /* Get the HSI48M configuration -----------------------------------------------*/
  if ((RCC->CFGR1 & RCC_CFGR1_HSI48ON) == RCC_CFGR1_HSI48ON)
  {
    RCC_OscInitStruct->HSI48MState = RCC_HSI48M_ON;
  }
  else
  {
    RCC_OscInitStruct->HSI48MState = RCC_HSI48M_OFF;
  }

  /* Get the LSE configuration -----------------------------------------------*/
  if ((RCC->BDCR & RCC_BDCR_LSEBYP) == RCC_BDCR_LSEBYP)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_BYPASS;
  }
  else if ((RCC->BDCR & RCC_BDCR_LSEON) == RCC_BDCR_LSEON)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_ON;
  }
  else
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_OFF;
  }
  RCC_OscInitStruct->LSEDriver = (uint32_t)(RCC->BDCR & RCC_BDCR_LSEDRV);

  /* Get the LSI configuration -----------------------------------------------*/
  if ((RCC->CSR & RCC_CSR_LSION) == RCC_CSR_LSION)
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_ON;
  }
  else
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_OFF;
  }
  
  /* Get the PLL configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_PLLON) == RCC_CR_PLLON)
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_OFF;
  }
  RCC_OscInitStruct->PLL.PLLSource = (uint32_t)(RCC->CFGR3 & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE));
  RCC_OscInitStruct->PLL.PLLMUL = (uint32_t)(((RCC->CFGR3 & RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U);
  RCC_OscInitStruct->PLL.PLLPrediv = (uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPREDIV);
  RCC_OscInitStruct->PLL.PLLPostdiv = (uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPOSTDIV);
}

/**
  * @brief  Get the RCC_ClkInitStruct according to the internal
  *         RCC configuration registers.
  * @param  RCC_ClkInitStruct pointer to an RCC_ClkInitTypeDef structure that
  *         contains the current clock configuration.
  * @param  pFLatency Pointer on the Flash Latency.
  * @retval None
  */
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
{
  /* Check the parameters */
  assert_param(RCC_ClkInitStruct != NULL);
  assert_param(pFLatency != NULL);

  /* Set all possible values for the Clock type parameter --------------------*/
  RCC_ClkInitStruct->ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;

  /* Get the SYSCLK configuration --------------------------------------------*/
  RCC_ClkInitStruct->SYSCLKSource = (uint32_t)(RCC->CFGR & RCC_CFGR_SW);

  /* Get the HCLK configuration ----------------------------------------------*/
  RCC_ClkInitStruct->AHBCLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_HPRE);

  /* Get the APB1 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APB1CLKDivider = (uint32_t)(RCC->CFGR & RCC_CFGR_PPRE1);

  /* Get the APB2 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APB2CLKDivider = (uint32_t)((RCC->CFGR & RCC_CFGR_PPRE2) >> 3);

#if   defined(FLASH_ACR_LATENCY)
  /* Get the Flash Wait State (Latency) configuration ------------------------*/
  *pFLatency = (uint32_t)(FLASH->ACR & FLASH_ACR_LATENCY);
#else
  /* For VALUE lines devices, only LATENCY_0 can be set*/
  *pFLatency = (uint32_t)FLASH_LATENCY_0;
#endif
}

/**
  * @brief This function handles the RCC CSS interrupt request.
  * @note This API should be called under the NMI_Handler().
  * @retval None
  */
void HAL_RCC_NMI_IRQHandler(void)
{
  /* Check RCC CSSF flag  */
  if (__HAL_RCC_GET_IT(RCC_IT_CSS))
  {
    /* RCC Clock Security System interrupt user callback */
    HAL_RCC_CSSCallback();

    /* Clear RCC CSS pending bit */
    __HAL_RCC_CLEAR_IT(RCC_IT_CSS);
  }
}

/**
  * @brief  RCC Clock Security System interrupt callback
  * @retval none
  */
__weak void HAL_RCC_CSSCallback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
    the HAL_RCC_CSSCallback could be implemented in the user file
    */
}

/**
  * @}
  */

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup RCC_Private_Functions
  * @{
  */

/**
  * @brief  Compute SYSCLK frequency based on PLL SYSCLK source.
  * @retval SYSCLK frequency
  */
static uint32_t RCC_GetSysClockFreqFromPLLSource(void)
{
  const uint8_t aDivFactorTable[4] = {1, 2, 4, 8};

  uint32_t pllsource = 0U, pllmul = 0U, pllprediv = 0U, pllpostdiv = 0U, sysclockfreq = 0U;
  
  /* SYSCLK = (HSE_VALUE, HSE_VALUE/2 or HSI_VALUE/2) / PLLPREDIV * PLLMUL / PLLLPOSTDIV */
  pllsource = READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE);
  pllprediv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPREDIV) >> RCC_CFGR3_PLLPREDIV_Pos];
  pllpostdiv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPOSTDIV) >> RCC_CFGR3_PLLPOSTDIV_Pos];
  pllmul = (READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U;

  switch (pllsource)
  {
  case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
    sysclockfreq = (HSE_VALUE) / pllprediv * pllmul / pllpostdiv;
    break;
  
  case RCC_PLLSOURCE_HSE_DIV2:  /* HSE/2 used as PLL clock source */
    sysclockfreq = (HSE_VALUE / 2U) / pllprediv * pllmul / pllpostdiv;
    break;
  
  case RCC_PLLSOURCE_HSI_DIV2:  /* HSI/2 used as PLL clock source */
  default:
    sysclockfreq = (HSI_VALUE / 2U) / pllprediv * pllmul / pllpostdiv;
    break;
  }

  return sysclockfreq;
}

/**
  * @}
  */

#endif /* HAL_RCC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

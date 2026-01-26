/**
  ******************************************************************************
  * @file    py32e407_hal_rcc_ex.c
  * @author  MCU Application Team
  * @brief   Extended RCC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities RCC extended peripheral:
  *           + Extended Peripheral Control functions
  *           + Extended Clock management functions
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

#ifdef HAL_RCC_MODULE_ENABLED

/** @defgroup RCCEx RCCEx
  * @brief RCC Extension HAL module driver.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup RCCEx_Private_Constants RCCEx Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup RCCEx_Private_Macros RCCEx Private Macros
  * @{
  */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Functions RCCEx Exported Functions
  * @{
  */

/** @defgroup RCCEx_Exported_Functions_Group1 Peripheral Control functions
  *  @brief  Extended Peripheral Control functions
  *
@verbatim
 ===============================================================================
                ##### Extended Peripheral Control functions  #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the RCC Clocks
    frequencies.
    [..]
    (@) Important note: Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to
        select the RTC clock source; in this case the Backup domain will be reset in
        order to modify the RTC Clock source, as consequence RTC registers (including
        the backup registers) are set to their reset values.

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the RCC extended peripherals clocks according to the specified parameters in the
  *         RCC_PeriphCLKInitTypeDef.
  * @param  PeriphClkInit pointer to an RCC_PeriphCLKInitTypeDef structure that
  *         contains the configuration information for the Extended Peripherals clocks.
  *
  * @note   Care must be taken when HAL_RCCEx_PeriphCLKConfig() is used to select
  *         the RTC clock source; in this case the Backup domain will be reset in
  *         order to modify the RTC Clock source, as consequence RTC registers (including
  *         the backup registers) are set to their reset values.
  *
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  uint32_t tickstart = 0U, temp_reg = 0U;

  /* Check the parameters */
  assert_param(IS_RCC_PERIPHCLOCK(PeriphClkInit->PeriphClockSelection));

  /*------------------------------- RTC Configuration ------------------------*/
  if ((((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC))
  {
    /* check for RTC Parameters used to output RTCCLK */
    assert_param(IS_RCC_RTCCLKSOURCE(PeriphClkInit->RtcClockSelection));

    FlagStatus       pwrclkchanged = RESET;

    /* As soon as function is called to change RTC clock source, activation of the
       power domain is done. */
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

    /* Reset the Backup domain only if the RTC Clock source selection is modified from reset value */
    temp_reg = (RCC->BDCR & RCC_BDCR_RTCSEL);
    if ((temp_reg != 0x00000000U) && (temp_reg != (PeriphClkInit->RtcClockSelection & RCC_BDCR_RTCSEL)))
    {
      /* Store the content of BDCR register before the reset of Backup Domain */
      temp_reg = (RCC->BDCR & ~(RCC_BDCR_RTCSEL));
      /* RTC Clock selection can be changed only if the Backup Domain is reset */
      __HAL_RCC_BACKUPRESET_FORCE();
      __HAL_RCC_BACKUPRESET_RELEASE();
      /* Restore the Content of BDCR register */
      RCC->BDCR = temp_reg;

      /* Wait for LSERDY if LSE was enabled */
      if (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSEON))
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
    }
    __HAL_RCC_RTC_CONFIG(PeriphClkInit->RtcClockSelection);

    /* Require to disable power clock if necessary */
    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }

  /*------------------------------ ADC clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)
  {
    /* Check the parameters */
    assert_param(IS_RCC_ADCPLLCLK_DIV(PeriphClkInit->AdcClockSelection));

    /* Configure the ADC clock source */
    __HAL_RCC_ADC_CONFIG(PeriphClkInit->AdcClockSelection);
  }
  
  /*------------------------------ USB clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USB) == RCC_PERIPHCLK_USB)
  {
    /* Check the parameters */
    assert_param(IS_RCC_USBCLKSOURCE(PeriphClkInit->UsbClockSelection));
    
    if((PeriphClkInit->UsbClockSelection) != RCC_USBCLKSOURCE_HSI48M)
    {
      /* Set USB clock source as PLL frequency */
      CLEAR_BIT(RCC->CFGR1,RCC_CFGR1_USBSELHSI48);
      
      /* Configure the USB clock source */
      __HAL_RCC_USB_CONFIG(PeriphClkInit->UsbClockSelection);
    }
    else
    {
      /* Set USB clock source as HSI48M */
      SET_BIT(RCC->CFGR1,RCC_CFGR1_USBSELHSI48);
    }
  }
  
  /*------------------------------ SRAM2 clock Configuration ----------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_SRAM2) == RCC_PERIPHCLK_SRAM2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_SRAM2CLK_DIV(PeriphClkInit->Sram2ClockSelection));

    /* Configure the SRAM2 clock source */
    __HAL_RCC_SRAM2_CONFIG(PeriphClkInit->Sram2ClockSelection);
  }
  
  /*------------------------------ CAN clock Configuration ------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_CAN) == RCC_PERIPHCLK_CAN)
  {
    /* Check the parameters */
    assert_param(IS_RCC_CANCLKSOURCE(PeriphClkInit->CanClockSelection));

    /* Configure the CAN clock source */
    __HAL_RCC_CAN_CONFIG(PeriphClkInit->CanClockSelection);
  }
  
  /*------------------------------ PVD filter  clock Configuration ----------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_PVD) == RCC_PERIPHCLK_PVD)
  {
    /* Check the parameters */
    assert_param(IS_RCC_PVDFILTERCLK(PeriphClkInit->PvdFilterClockSelection));

    /* Configure the PVD filter clock */
    __HAL_RCC_PVD_CONFIG(PeriphClkInit->PvdFilterClockSelection);
  }
  
  /*-------------------------- USART1 clock source configuration -------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USART1) == RCC_PERIPHCLK_USART1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_USART1CLKSOURCE(PeriphClkInit->Usart1ClockSelection));

    /* Configure the USART1 clock source */
    __HAL_RCC_USART1_CONFIG(PeriphClkInit->Usart1ClockSelection);
  }

  /*-------------------------- USART2 clock source configuration -------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USART2) == RCC_PERIPHCLK_USART2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_USART2CLKSOURCE(PeriphClkInit->Usart2ClockSelection));

    /* Configure the USART2 clock source */
    __HAL_RCC_USART2_CONFIG(PeriphClkInit->Usart2ClockSelection);
  }

  /*-------------------------- USART3 clock source configuration -------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_USART3) == RCC_PERIPHCLK_USART3)
  {
    /* Check the parameters */
    assert_param(IS_RCC_USART3CLKSOURCE(PeriphClkInit->Usart3ClockSelection));

    /* Configure the USART3 clock source */
    __HAL_RCC_USART3_CONFIG(PeriphClkInit->Usart3ClockSelection);
  }

  /*-------------------------- LPUART1 clock source configuration ------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_LPUART1) == RCC_PERIPHCLK_LPUART1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LPUART1CLKSOURCE(PeriphClkInit->Lpuart1ClockSelection));

    /* Configure the LPUAR1 clock source */
    __HAL_RCC_LPUART1_CONFIG(PeriphClkInit->Lpuart1ClockSelection);
  }
  
  /*-------------------------- LPTIM1 clock source configuration ---------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_LPTIM1) == RCC_PERIPHCLK_LPTIM1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LPTIM1CLKSOURCE(PeriphClkInit->Lptim1ClockSelection));

    /* Configure the LPTIM1 clock source */
    __HAL_RCC_LPTIM1_CONFIG(PeriphClkInit->Lptim1ClockSelection);
  }
  
  /*-------------------------- COMP1 clock source configuration ---------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_COMP1) == RCC_PERIPHCLK_COMP1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_COMP1CLKSOURCE(PeriphClkInit->Comp1ClockSelection));

    /* Configure the COMP1 clock source */
    __HAL_RCC_COMP1_CONFIG(PeriphClkInit->Comp1ClockSelection);
  }
  
  /*-------------------------- COMP2 clock source configuration ---------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_COMP2) == RCC_PERIPHCLK_COMP2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_COMP2CLKSOURCE(PeriphClkInit->Comp2ClockSelection));

    /* Configure the COMP2 clock source */
    __HAL_RCC_COMP2_CONFIG(PeriphClkInit->Comp2ClockSelection);
  }
  
  /*-------------------------- COMP3 clock source configuration ---------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_COMP3) == RCC_PERIPHCLK_COMP3)
  {
    /* Check the parameters */
    assert_param(IS_RCC_COMP3CLKSOURCE(PeriphClkInit->Comp3ClockSelection));

    /* Configure the COMP3 clock source */
    __HAL_RCC_COMP3_CONFIG(PeriphClkInit->Comp3ClockSelection);
  }
  
  /*-------------------------- COMP4 clock source configuration ---------------------*/
  if(((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_COMP4) == RCC_PERIPHCLK_COMP4)
  {
    /* Check the parameters */
    assert_param(IS_RCC_COMP4CLKSOURCE(PeriphClkInit->Comp4ClockSelection));

    /* Configure the COMP4 clock source */
    __HAL_RCC_COMP4_CONFIG(PeriphClkInit->Comp4ClockSelection);
  }
  
  return HAL_OK;
}

/**
  * @brief  Get the PeriphClkInit according to the internal
  * RCC configuration registers.
  * @param  PeriphClkInit pointer to an RCC_PeriphCLKInitTypeDef structure that
  *         returns the configuration information for the Extended Peripherals clocks(RTC, ADC... clocks).
  * @retval None
  */
void HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  /* Get the RTC configuration -----------------------------------------------*/
  PeriphClkInit->PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit->RtcClockSelection = __HAL_RCC_GET_RTC_SOURCE();

  /* Get the ADC clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_ADC;
  PeriphClkInit->AdcClockSelection = __HAL_RCC_GET_ADC_SOURCE();

  /* Get the USB clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_USB;
  if(READ_BIT(RCC->CFGR1,RCC_USBCLKSOURCE_HSI48M) != RCC_USBCLKSOURCE_HSI48M)
  {
    PeriphClkInit->UsbClockSelection = __HAL_RCC_GET_USB_SOURCE();
  }
  else
  {
    PeriphClkInit->UsbClockSelection = RCC_USBCLKSOURCE_HSI48M;
  }

  /* Get the SRAM2 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_SRAM2;
  PeriphClkInit->Sram2ClockSelection = __HAL_RCC_GET_SRAM2_SOURCE();

  /* Get the CAN clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_CAN;
  PeriphClkInit->CanClockSelection = __HAL_RCC_GET_CAN_SOURCE();
  
  /* Get the PVD filter clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_PVD;
  PeriphClkInit->PvdFilterClockSelection = __HAL_RCC_GET_PVD_FILTER_SOURCE();
  
  /* Get the USART1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_USART1;
  PeriphClkInit->Usart1ClockSelection = __HAL_RCC_GET_USART1_SOURCE();
  
  /* Get the USART2 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_USART2;
  PeriphClkInit->Usart2ClockSelection = __HAL_RCC_GET_USART2_SOURCE();
  
  /* Get the USART3 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_USART3;
  PeriphClkInit->Usart3ClockSelection = __HAL_RCC_GET_USART3_SOURCE();
  
  /* Get the LPUART1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_LPUART1;
  PeriphClkInit->Lpuart1ClockSelection = __HAL_RCC_GET_LPUART1_SOURCE();
  
  /* Get the LPTIM1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_LPTIM1;
  PeriphClkInit->Lptim1ClockSelection = __HAL_RCC_GET_LPTIM1_SOURCE();
  
  /* Get the COMP1 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_COMP1;
  PeriphClkInit->Comp1ClockSelection = __HAL_RCC_GET_COMP1_SOURCE();
  
  /* Get the COMP2 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_COMP2;
  PeriphClkInit->Comp2ClockSelection = __HAL_RCC_GET_COMP2_SOURCE();
  
  /* Get the COMP3 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_COMP3;
  PeriphClkInit->Comp3ClockSelection = __HAL_RCC_GET_COMP3_SOURCE();
  
  /* Get the COMP4 clock configuration -----------------------------------------*/
  PeriphClkInit->PeriphClockSelection |= RCC_PERIPHCLK_COMP4;
  PeriphClkInit->Comp4ClockSelection = __HAL_RCC_GET_COMP4_SOURCE();
}

/**
  * @brief  Returns the peripheral clock frequency
  * @note   Returns 0 if peripheral clock is unknown
  * @param  PeriphClk Peripheral clock identifier
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_PERIPHCLK_RTC      RTC peripheral clock
  *            @arg @ref RCC_PERIPHCLK_ADC      ADC peripheral clock
  *            @arg @ref RCC_PERIPHCLK_USB      USB peripheral clock
  *            @arg @ref RCC_PERIPHCLK_SRAM2    SRAM2 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_CAN      CAN peripheral clock
  *            @arg @ref RCC_PERIPHCLK_PVD      PVD peripheral clock
  *            @arg @ref RCC_PERIPHCLK_USART1   USART1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_USART2   USART2 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_USART3   USART3 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_LPUART1  LPUART1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_LPTIM1   LPTIM1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_COMP1    COMP1 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_COMP2    COMP2 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_COMP3    COMP3 peripheral clock
  *            @arg @ref RCC_PERIPHCLK_COMP4    COMP4 peripheral clock
  * @retval Frequency in Hz (0: means that no available frequency for the peripheral)
  */
uint32_t HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk)
{
  const uint8_t aDivFactorTable[4] = {1, 2, 4, 8};
  const uint8_t aXTPredivFactorTable[2] = {1, 2};

  uint32_t tmpreg = 0U, pllxtprediv = 0U, pllclk = 0U, pllmul = 0U, srcclk = 0U, pllprediv = 0U, pllpostdiv = 0U;

  uint32_t usbprediv = 0U;
  uint32_t temp_reg = 0U, frequency = 0U;

  /* Check the parameters */
  assert_param(IS_RCC_PERIPHCLOCK(PeriphClk));

  switch (PeriphClk)
  {
    case RCC_PERIPHCLK_RTC:
    {
      /* Get RCC BDCR configuration ------------------------------------------------------*/
      temp_reg = RCC->BDCR;

      /* Check if LSE is ready if RTC clock selection is LSE */
      if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_LSE) && (HAL_IS_BIT_SET(temp_reg, RCC_BDCR_LSERDY)))
      {
        frequency = LSE_VALUE;
      }
      /* Check if LSI is ready if RTC clock selection is LSI */
      else if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_LSI) && (HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)))
      {
        frequency = LSI_VALUE;
      }
      else if (((temp_reg & RCC_BDCR_RTCSEL) == RCC_RTCCLKSOURCE_HSE_DIV128) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSERDY)))
      {
        frequency = HSE_VALUE / 128U;
      }
      /* Clock not enabled for RTC*/
      else
      {
        /* nothing to do: frequency already initialized to 0U */
      }
      break;
    }
    case RCC_PERIPHCLK_ADC:
    {
      switch(__HAL_RCC_GET_ADC_SOURCE())
      {
        case RCC_ADCPCLK2_DIV2:
        {
          frequency = HAL_RCC_GetPCLK2Freq() / 2U;
          break;
        }
        case RCC_ADCPCLK2_DIV4:
        {
          frequency = HAL_RCC_GetPCLK2Freq() / 4U;
          break;
        }
        case RCC_ADCPCLK2_DIV6:
        {
          frequency = HAL_RCC_GetPCLK2Freq() / 6U;
          break;
        }
        case RCC_ADCPCLK2_DIV8:
        {
          frequency = HAL_RCC_GetPCLK2Freq() / 8U;
          break;
        }
        case RCC_ADCPCLK2_DIV12:
        {
          frequency = HAL_RCC_GetPCLK2Freq() / 12U;
          break;
        }
        case RCC_ADCPCLK2_DIV16:
        {
          frequency = HAL_RCC_GetPCLK2Freq() / 16U;
          break;
        }
        default:
        {
          break;
        }
      }
      break;
    }
    
    case RCC_PERIPHCLK_USB:
    {
      /* Get RCC CFGR1 configuration ------------------------------------------------------*/
      temp_reg = RCC->CFGR1;
      
      if(((temp_reg & RCC_USBCLKSOURCE_HSI48M) == RCC_USBCLKSOURCE_HSI48M) && (HAL_IS_BIT_SET(RCC->CFGR1, RCC_CFGR1_HSI48RDY)))
      {
        frequency = HSI48_VALUE;
      }
      else if(((temp_reg & RCC_USBCLKSOURCE_HSI48M) != RCC_USBCLKSOURCE_HSI48M) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY)))
      {
        tmpreg = RCC->CFGR3;
        pllprediv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPREDIV) >> RCC_CFGR3_PLLPREDIV_Pos];
        pllpostdiv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPOSTDIV) >> RCC_CFGR3_PLLPOSTDIV_Pos];
        pllmul = (READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U;
        if(((tmpreg & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) == RCC_PLLSOURCE_HSE) || \
           ((tmpreg & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) == RCC_PLLSOURCE_HSE_DIV2))
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

        usbprediv = __HAL_RCC_GET_USB_SOURCE();
        switch(usbprediv)
        {
          case RCC_USBCLKSOURCE_PLL:
          {
            frequency = pllclk;
            break;
          }
          case RCC_USBCLKSOURCE_PLL_DIV1_5:
          {
            frequency = (pllclk * 2U) / 3U;
            break;
          }
          case RCC_USBCLKSOURCE_PLL_DIV2:
          {
            frequency = pllclk / 2U;
            break;
          }
          case RCC_USBCLKSOURCE_PLL_DIV2_5:
          {
            frequency = (pllclk * 2U) / 5U;
            break;
          }
          case RCC_USBCLKSOURCE_PLL_DIV3:
          {
            frequency = pllclk / 3U;
            break;
          }
          case RCC_USBCLKSOURCE_PLL_DIV3_5:
          {
            frequency = (pllclk * 2U) / 7U;
            break;
          }
          case RCC_USBCLKSOURCE_PLL_DIV4:
          {
            frequency = pllclk / 4U;
            break;
          }
          default:
          {
            break;
          }
        }
      }
      else
      {
        /* nothing to do: frequency already initialized to 0U */
      }
      break;
    }
    
    case RCC_PERIPHCLK_SRAM2:
    {
      switch(__HAL_RCC_GET_SRAM2_SOURCE())
      {
        case RCC_SRAM2HCLK_DIV1:
        {
          frequency = HAL_RCC_GetHCLKFreq();
          break;
        }
        case RCC_SRAM2HCLK_DIV2:
        {
          frequency = HAL_RCC_GetHCLKFreq() / 2;
          break;
        }
        default:
        {
          break;
        }
      }
      break;
    }
    
    case RCC_PERIPHCLK_CAN:
    {
      /* Get RCC CFGR2 configuration ------------------------------------------------------*/
      temp_reg = RCC->CFGR2;
      
      if(((temp_reg & RCC_CFGR2_CANCKSEL) != RCC_CANCLKSOURCE_HSE) && ((temp_reg & RCC_CANCLKSOURCE_HSE) == RCC_CANCLKSOURCE_HSE))
      {
        /* No clock */
      }
      else if(((temp_reg & RCC_CFGR2_CANCKSEL) == RCC_CANCLKSOURCE_HSE) && (HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSERDY)))
      {
        frequency = HSE_VALUE;
      }
      else
      {
        if(HAL_IS_BIT_SET(RCC->CR, RCC_CR_PLLRDY))
        {
          /* PLL / CANPLLDIV */
          tmpreg = RCC->CFGR3;
          pllprediv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPREDIV) >> RCC_CFGR3_PLLPREDIV_Pos];
          pllpostdiv = aDivFactorTable[(uint32_t)(RCC->CFGR3 & RCC_CFGR3_PLLPOSTDIV) >> RCC_CFGR3_PLLPOSTDIV_Pos];
          pllmul = (READ_BIT(RCC->CFGR3, RCC_CFGR3_PLLFBDIV) >> RCC_CFGR3_PLLFBDIV_Pos) + 2U;
          if(((tmpreg & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) == RCC_PLLSOURCE_HSE) || \
             ((tmpreg & (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE)) == RCC_PLLSOURCE_HSE_DIV2))
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
          
          frequency = (pllclk / ((__HAL_RCC_GET_CAN_SOURCE() >> RCC_CFGR2_CANCKSEL_Pos) + 1U));
        }
      }
      break;
    }
    
    case RCC_PERIPHCLK_PVD:
    {
      /* Get the current PVD filter source */
      srcclk = __HAL_RCC_GET_PVD_FILTER_SOURCE();

      if((HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)) && (srcclk == RCC_PVDFILTERCLK_LSI))
      {
        frequency = LSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_PVDFILTERCLK_LSE))
      {
        frequency = LSE_VALUE;
      }
      else if(srcclk == RCC_PVDFILTERCLK_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }
      /* Clock not enabled for PVD */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_USART1:
    {
      /* Get the current USART1 source */
      srcclk = __HAL_RCC_GET_USART1_SOURCE();

      if(srcclk == RCC_USART1CLKSOURCE_PCLK2)
      {
        frequency = HAL_RCC_GetPCLK2Freq();
      }
      else if(srcclk == RCC_USART1CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)) && (srcclk == RCC_USART1CLKSOURCE_HSI) )
      {
        frequency = HSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_USART1CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for USART1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }

    case RCC_PERIPHCLK_USART2:
    {
      /* Get the current USART2 source */
      srcclk = __HAL_RCC_GET_USART2_SOURCE();

      if(srcclk == RCC_USART2CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }
      else if(srcclk == RCC_USART2CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)) && (srcclk == RCC_USART2CLKSOURCE_HSI))
      {
        frequency = HSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY))  && (srcclk == RCC_USART2CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for USART2 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }

    case RCC_PERIPHCLK_USART3:
    {
      /* Get the current USART3 source */
      srcclk = __HAL_RCC_GET_USART3_SOURCE();

      if(srcclk == RCC_USART3CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }
      else if(srcclk == RCC_USART3CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)) && (srcclk == RCC_USART3CLKSOURCE_HSI))
      {
        frequency = HSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_USART3CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for USART3 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_LPUART1:
    {
      /* Get the current LPUART1 source */
      srcclk = __HAL_RCC_GET_LPUART1_SOURCE();

      if(srcclk == RCC_LPUART1CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }
      else if(srcclk == RCC_LPUART1CLKSOURCE_SYSCLK)
      {
        frequency = HAL_RCC_GetSysClockFreq();
      }
      else if((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)) && (srcclk == RCC_LPUART1CLKSOURCE_HSI))
      {
        frequency = HSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_LPUART1CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for LPUART1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_LPTIM1:
    {
      /* Get the current LPTIM1 source */
      srcclk = __HAL_RCC_GET_LPTIM1_SOURCE();

      if(srcclk == RCC_LPTIM1CLKSOURCE_PCLK1)
      {
        frequency = HAL_RCC_GetPCLK1Freq();
      }
      else if((HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)) && (srcclk == RCC_LPTIM1CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->CR, RCC_CR_HSIRDY)) && (srcclk == RCC_LPTIM1CLKSOURCE_HSI))
      {
        frequency = HSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_LPTIM1CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for LPTIM1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_COMP1:
    {
      /* Get the current COMP1 source */
      srcclk = __HAL_RCC_GET_COMP1_SOURCE();

      if(srcclk == RCC_COMP1CLKSOURCE_PCLK2)
      {
        frequency = HAL_RCC_GetPCLK2Freq();
      }
      else if((HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)) && (srcclk == RCC_COMP1CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_COMP1CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for COMP1 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_COMP2:
    {
      /* Get the current COMP2 source */
      srcclk = __HAL_RCC_GET_COMP2_SOURCE();

      if(srcclk == RCC_COMP2CLKSOURCE_PCLK2)
      {
        frequency = HAL_RCC_GetPCLK2Freq();
      }
      else if((HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)) && (srcclk == RCC_COMP2CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_COMP2CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for COMP2 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_COMP3:
    {
      /* Get the current COMP3 source */
      srcclk = __HAL_RCC_GET_COMP3_SOURCE();

      if(srcclk == RCC_COMP3CLKSOURCE_PCLK2)
      {
        frequency = HAL_RCC_GetPCLK2Freq();
      }
      else if((HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)) && (srcclk == RCC_COMP3CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_COMP3CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for COMP3 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    case RCC_PERIPHCLK_COMP4:
    {
      /* Get the current COMP4 source */
      srcclk = __HAL_RCC_GET_COMP4_SOURCE();

      if(srcclk == RCC_COMP4CLKSOURCE_PCLK2)
      {
        frequency = HAL_RCC_GetPCLK2Freq();
      }
      else if((HAL_IS_BIT_SET(RCC->CSR, RCC_CSR_LSIRDY)) && (srcclk == RCC_COMP4CLKSOURCE_LSI))
      {
        frequency = LSI_VALUE;
      }
      else if((HAL_IS_BIT_SET(RCC->BDCR, RCC_BDCR_LSERDY)) && (srcclk == RCC_COMP4CLKSOURCE_LSE))
      {
        frequency = LSE_VALUE;
      }
      /* Clock not enabled for COMP4 */
      else
      {
        /* nothing to do: frequency already initialized to 0 */
      }
      break;
    }
    
    default:
    {
      break;
    }
  }
  
  return (frequency);
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

#endif /* HAL_RCC_MODULE_ENABLED */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/


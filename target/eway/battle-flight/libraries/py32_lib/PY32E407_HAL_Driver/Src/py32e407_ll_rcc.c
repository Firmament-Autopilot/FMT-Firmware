/**
  ******************************************************************************
  * @file    py32e407_ll_rcc.c
  * @author  MCU Application Team
  * @brief   RCC LL module driver.
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
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "py32e407_ll_rcc.h"
#ifdef  USE_FULL_ASSERT
  #include "py32_assert.h"
#else
  #define assert_param(expr) ((void)0U)
#endif
/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined(RCC)

/** @addtogroup RCC_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup RCC_LL_Private_Macros
  * @{
  */
#define IS_LL_RCC_MCO_CLKSOURCE(__VALUE__)  (((__VALUE__) == LL_RCC_MCO_CLKSOURCE))
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup RCC_LL_Private_Functions RCC Private functions
  * @{
  */
uint32_t RCC_GetSystemClockFreq(void);
uint32_t RCC_GetHCLKClockFreq(uint32_t SYSCLK_Frequency);
uint32_t RCC_GetPCLK1ClockFreq(uint32_t HCLK_Frequency);
uint32_t RCC_GetPCLK2ClockFreq(uint32_t HCLK_Frequency);
#if defined(RCC_PLL_SUPPORT)
  uint32_t RCC_PLL_GetFreqDomain_SYS(void);
#endif
/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCC_LL_Exported_Functions
  * @{
  */

/** @addtogroup RCC_LL_EF_Init
  * @{
  */

/**
  * @brief  Reset the RCC clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *         - HSI ON and used as system clock source
  *         - HSE and PLL OFF
  *         - AHB and APB1 prescaler set to 1.
  *         - CSS, MCO OFF
  *         - All interrupts disabled
  * @note   This function does not modify the configuration of the
  *         - Peripheral clocks
  *         - LSI, LSE and RTC clocks
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RCC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_RCC_DeInit(void)
{
  uint32_t vl_mask;
  
  /* Set HSION bit and wait for HSI READY bit */
  LL_RCC_HSI_Enable();
  while (LL_RCC_HSI_IsReady() != 1U)
  {}

  /* Set HSITRIM bits to reset value*/
  LL_RCC_HSI_SetCalibTrimming(0x10U);

  /* Reset whole CFGR register, but keep HSI as the system clock source and 
     do not modify the clock configuration of SRAM2, ADC, and USB */
  CLEAR_BIT(RCC->CFGR, ~(RCC_CFGR_ADCPRE | RCC_CFGR_USBPRE | RCC_CFGR_SRAM2PRE));

  /* Wait till SYSCLK is HSI */
  while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {}

  /* Reset whole CR register but HSI in 2 steps in case HSEBYP is set */
  LL_RCC_WriteReg(CR, RCC_CR_HSION);
  while (LL_RCC_HSE_IsReady() != 0U)
  {}
  LL_RCC_WriteReg(CR, RCC_CR_HSION);
#if defined(RCC_PLL_SUPPORT)
  /* Wait for PLL READY bit to be reset */
  while (LL_RCC_PLL_IsReady() != 0U)
  {}

  /* Reset configuration of PLL */
  CLEAR_BIT(RCC->CFGR3, (RCC_CFGR3_PLLSRC | RCC_CFGR3_PLLXTPRE | RCC_CFGR3_PLLPREDIV | RCC_CFGR3_PLLFBDIV | RCC_CFGR3_PLLPOSTDIV));
#endif
  /* Disable all interrupts */
  LL_RCC_WriteReg(CIR, 0x00000000U);

  /* Clear all interrupts flags */
  vl_mask = RCC_CIR_LSIRDYC | RCC_CIR_LSERDYC | RCC_CIR_HSIRDYC | RCC_CIR_HSERDYC | \
            RCC_CIR_PLLRDYC | RCC_CIR_HSI48RDYC | RCC_CIR_CSSC;
  
  LL_RCC_WriteReg(CIR, vl_mask);
  
  /* Clear reset flags */
  LL_RCC_ClearResetFlags();

  return SUCCESS;
}

/**
  * @}
  */

/** @addtogroup RCC_LL_EF_Get_Freq
  * @brief  Return the frequencies of different on chip clocks;  System, AHB, APB1 and APB2 buses clocks
  *         and different peripheral clocks available on the device.
  * @note   If SYSCLK source is HSI, function returns values based on HSI_VALUE(**)
  * @note   If SYSCLK source is HSE, function returns values based on HSE_VALUE(***)
  * @note   If SYSCLK source is PLL, function returns values based on HSE_VALUE(***)
  *         or HSI_VALUE(**) multiplied/divided by the PLL factors.
  * @note   (**) HSI_VALUE is a constant defined in this file (default value
  *              16 MHz) but the real value may vary depending on the variations
  *              in voltage and temperature.
  * @note   (***) HSE_VALUE is a constant defined in this file (default value
  *               24 MHz), user has to ensure that HSE_VALUE is same as the real
  *               frequency of the crystal used. Otherwise, this function may
  *               have wrong result.
  * @note   The result of this function could be incorrect when using fractional
  *         value for HSE crystal.
  * @note   This function can be used by the user application to compute the
  *         baud-rate for the communication peripherals or configure other parameters.
  * @{
  */

/**
  * @brief  Return the frequencies of different on chip clocks;  System, AHB, APB1 and APB2 buses clocks
  * @note   Each time SYSCLK, HCLK, PCLK1 and/or PCLK2 clock changes, this function
  *         must be called to update structure fields. Otherwise, any
  *         configuration based on this function will be incorrect.
  * @param  RCC_Clocks pointer to a @ref LL_RCC_ClocksTypeDef structure which will hold the clocks frequencies
  * @retval None
  */
void LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef *RCC_Clocks)
{
  /* Get SYSCLK frequency */
  RCC_Clocks->SYSCLK_Frequency = RCC_GetSystemClockFreq();

  /* HCLK clock frequency */
  RCC_Clocks->HCLK_Frequency   = RCC_GetHCLKClockFreq(RCC_Clocks->SYSCLK_Frequency);

  /* PCLK1 clock frequency */
  RCC_Clocks->PCLK1_Frequency  = RCC_GetPCLK1ClockFreq(RCC_Clocks->HCLK_Frequency);
  
  /* PCLK2 clock frequency */
  RCC_Clocks->PCLK2_Frequency  = RCC_GetPCLK2ClockFreq(RCC_Clocks->HCLK_Frequency);
}

/**
  * @brief  Return MCO clock frequency
  * @param  MCOx This parameter can be one of the following values:
  *         @arg @ref LL_RCC_MCO_CLKSOURCE
  * @retval MCO clock frequency (in Hz)
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NO indicates that oscillator (HSI48M, PLL, HSE, LSI or LSE) is not ready
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NA indicates that no clock source selected
  */
uint32_t LL_RCC_GetMCOClockFreq(uint32_t MCOx)
{
  uint32_t mco_frequency = LL_RCC_PERIPH_FREQUENCY_NO;

  /* Check parameter */
  assert_param(IS_LL_RCC_MCO_CLKSOURCE(MCOx));

  switch (LL_RCC_GetMCOClockSource(MCOx))
  {
#if defined(RCC_LSE_SUPPORT)
    case LL_RCC_MCOSOURCE_LSE:         /* MCO Clock is LSE */
      if (LL_RCC_LSE_IsReady() == 1U)
      {
        mco_frequency = LSE_VALUE;
      }
      break;
#endif
    case LL_RCC_MCOSOURCE_LSI:         /* MCO Clock is LSI */
      if (LL_RCC_LSI_IsReady() == 1U)
      {
        mco_frequency = LSI_VALUE;
      }
      break;
    case LL_RCC_MCOSOURCE_HSI48M:      /* MCO Clock is HSI48M */
      if (LL_RCC_HSI48_IsReady() == 1U)
      {
        mco_frequency = HSI48_VALUE;
      }
      break;
    case LL_RCC_MCOSOURCE_SYSCLK:      /* MCO Clock is SYSCLK */
      mco_frequency = SystemCoreClock;
      break;
    case LL_RCC_MCOSOURCE_HSI:         /* MCO Clock is HSI */
      if (LL_RCC_HSI_IsReady() == 1U)
      {
        mco_frequency = HSI_VALUE;
      }
      break;
    case LL_RCC_MCOSOURCE_HSE:         /* MCO Clock is HSE */
      if (LL_RCC_HSE_IsReady() == 1U)
      {
        mco_frequency = HSE_VALUE;
      }
      break;
#if defined(RCC_PLL_SUPPORT)
    case LL_RCC_MCOSOURCE_PLL:      /* MCO Clock is PLLCLK */
      if (LL_RCC_PLL_IsReady() == 1U)
      {
        mco_frequency = RCC_PLL_GetFreqDomain_SYS();
      }
      break;
#endif
    case LL_RCC_MCOSOURCE_NOCLOCK:     /* No clock used as MCO clock source */
    default:
      mco_frequency = LL_RCC_PERIPH_FREQUENCY_NA;
      return mco_frequency;
    }

    mco_frequency = mco_frequency / (1U << (LL_RCC_GetMCODiv(MCOx) >> RCC_CFGR1_MCOPRE_Pos));

    return mco_frequency;
}

#if defined(RCC_BDCR_RTCSEL)
/**
  * @brief  Return RTC clock frequency
  * @retval RTC clock frequency (in Hz)
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NO indicates that oscillators (LSI, LSE or HSE) are not ready
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NA indicates that no clock source selected
  */
uint32_t LL_RCC_GetRTCClockFreq(void)
{
  uint32_t rtc_frequency = LL_RCC_PERIPH_FREQUENCY_NO;

  /* RTCCLK clock frequency */
  switch (LL_RCC_GetRTCClockSource())
  {
#if defined(RCC_LSE_SUPPORT)
  case LL_RCC_RTC_CLKSOURCE_LSE:              /* LSE clock used as RTC clock source */
    if (LL_RCC_LSE_IsReady() == 1U)
    {
      rtc_frequency = LSE_VALUE;
    }
    break;
#endif
  case LL_RCC_RTC_CLKSOURCE_LSI:              /* LSI clock used as RTC clock source */
    if (LL_RCC_LSI_IsReady() == 1U)
    {
      rtc_frequency = LSI_VALUE;
    }
    break;

  case LL_RCC_RTC_CLKSOURCE_HSE_DIV128:       /* HSE/128 clock used as RTC clock source */
    if (LL_RCC_HSE_IsReady() == 1U)
    {
      rtc_frequency = HSE_VALUE / 128U;
    }

    break;

  case LL_RCC_RTC_CLKSOURCE_NONE:             /* No clock used as RTC clock source */
  default:
    rtc_frequency = LL_RCC_PERIPH_FREQUENCY_NA;
    break;
  }
  return rtc_frequency;
}
#endif


/**
  * @brief  Return USB clock frequency
  * @retval USB clock frequency (in Hz)
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NO indicates that oscillators (PLL or HSI48) are not ready
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NA indicates that no clock source selected
  */
uint32_t LL_RCC_GetUSBClockFreq(void)
{
  uint32_t usb_frequency = LL_RCC_PERIPH_FREQUENCY_NO;

  /* RTCCLK clock frequency */
  switch (LL_RCC_GetUSBClockSource())
  {
    #if defined(RCC_PLL_SUPPORT)
    case LL_RCC_USB_CLKSOURCE_PLL:              /* PLL used as USB clock source */
      if (LL_RCC_PLL_IsReady() == 1U)
      {
        switch (LL_RCC_GetUSBPrescaler())
        {
          case LL_RCC_USB_DIV_1P5:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS() * 2U / 3U;
            break;
          
          case LL_RCC_USB_DIV_1:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS();
            break;
          
          case LL_RCC_USB_DIV_2P5:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS() * 2U / 5U;
            break;
          
          case LL_RCC_USB_DIV_2:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS() / 2U;
            break;
          
          case LL_RCC_USB_DIV_3:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS() / 3U;
            break;
          
          case LL_RCC_USB_DIV_3P5:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS() * 2U / 7U;
            break;
          
          case LL_RCC_USB_DIV_4:
            usb_frequency = RCC_PLL_GetFreqDomain_SYS() / 4U;
            break;
          default:
          {
            break;
          }
        }
      }
      break;
    #endif
    
    case LL_RCC_USB_CLKSOURCE_HSI48:             /* HSI48 used as USB clock source */
      if (LL_RCC_HSI48_IsReady() == 1U)
      {
        usb_frequency = HSI48_VALUE;
      }
      break;
    
    default:
      usb_frequency = LL_RCC_PERIPH_FREQUENCY_NA;
      break;
  }
  return usb_frequency;
}

#if defined(CANFD)
/**
  * @brief  Return CANFD clock frequency
  * @retval CANFD clock frequency (in Hz)
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NO indicates that oscillators (PLL or HSE) are not ready
  *         - @ref  LL_RCC_PERIPH_FREQUENCY_NA indicates that no clock source selected
  */
uint32_t LL_RCC_GetCANFDClockFreq(void)
{
  uint32_t canfd_frequency = LL_RCC_PERIPH_FREQUENCY_NO;
  uint32_t pll_state = 0;
  
  pll_state = LL_RCC_PLL_IsReady();

  /* CANFD clock frequency */
  switch (LL_RCC_GetCANFDClockSource())
  {
    case LL_RCC_CANFD_CLKSOURCE_HSE:       /* HSE clock used as CANFD clock source */
      if (LL_RCC_HSE_IsReady() == 1U)
      {
        canfd_frequency = HSE_VALUE;
      }
      break;
    
    #if defined(RCC_PLL_SUPPORT)
    case LL_RCC_CANFD_CLKSOURCE_PLL:            /* PLL used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS();
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV2:       /* PLL/2 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 2U;
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV3:       /* PLL/3 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 3U;
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV4:       /* PLL/4 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 4U;
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV5:       /* PLL/5 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 5U;
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV6:       /* PLL/6 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 6U;
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV7:       /* PLL/7 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 7U;
      }
      break;
      
    case LL_RCC_CANFD_CLKSOURCE_PLL_DIV8:       /* PLL/8 clock used as CANFD clock source */
      if (pll_state == 1U)
      {
        canfd_frequency = RCC_PLL_GetFreqDomain_SYS() / 8U;
      }
      break;
    #endif
    

      
    default:
      canfd_frequency = LL_RCC_PERIPH_FREQUENCY_NA;
      break;
  }
  return canfd_frequency;
}
#endif /* CANFD */

/**
  * @brief  Return ADC clock frequency
  * @retval ADC clock frequency (in Hz)
  */
uint32_t LL_RCC_GetADCClockFreq(void)
{
  uint32_t adc_frequency = 0U;

  /* ADCCLK clock frequency */
  switch (LL_RCC_GetADCClockSource())
  {
    case LL_RCC_ADC_CLKSOURCE_PCLK2_DIV4:       /* PCLK/4 clock selected as ADC clock */
      adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq())) / 4;
      break;
    
    case LL_RCC_ADC_CLKSOURCE_PCLK2_DIV6:       /* PCLK/6 clock selected as ADC clock */
      adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq())) / 6;
      break;
    
    case LL_RCC_ADC_CLKSOURCE_PCLK2_DIV8:       /* PCLK/8 clock selected as ADC clock */
      adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq())) / 8;
      break;
    
    case LL_RCC_ADC_CLKSOURCE_PCLK2_DIV12:       /* PCLK/12 clock selected as ADC clock */
      adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq())) / 12;
      break;
    
    case LL_RCC_ADC_CLKSOURCE_PCLK2_DIV16:       /* PCLK/16 clock selected as ADC clock */
      adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq())) / 16;
      break;

    case LL_RCC_ADC_CLKSOURCE_PCLK2_DIV2:       /* PCLK/2 clock selected as ADC clock */
    default:
      adc_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq())) / 2;
      break;
  }
  return adc_frequency;
}

/**
  * @brief  Return LPUART1 clock frequency
  * @retval LPUART1 clock frequency (in Hz)
  */
uint32_t LL_RCC_GetLPUART1ClockFreq(void)
{
  uint32_t lpuart1_frequency = 0U;

  /* LPUART1CLK clock frequency */
  switch (LL_RCC_GetLPUART1ClockSource())
  {
    case LL_RCC_LPUART1_CLKSOURCE_SYSCLK:
      lpuart1_frequency = RCC_GetSystemClockFreq();
      break;
    
    case LL_RCC_LPUART1_CLKSOURCE_HSI:
      lpuart1_frequency = HSI_VALUE;
      break;
    
    case LL_RCC_LPUART1_CLKSOURCE_LSE:
      lpuart1_frequency = LSE_VALUE;
      break;

    case LL_RCC_LPUART1_CLKSOURCE_PCLK:
    default:
      lpuart1_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
      break;
  }
  return lpuart1_frequency;
}

/**
  * @brief  Return USART1 clock frequency
  * @retval USART1 clock frequency (in Hz)
  */
uint32_t LL_RCC_GetUSART1ClockFreq(void)
{
  uint32_t usart1_frequency = 0U;

  /* USART1CLK clock frequency */
  switch (LL_RCC_GetUSART1ClockSource())
  {
    case LL_RCC_USART1_CLKSOURCE_SYSCLK:
      usart1_frequency = RCC_GetSystemClockFreq();
      break;
    
    case LL_RCC_USART1_CLKSOURCE_HSI:
      usart1_frequency = HSI_VALUE;
      break;
    
    case LL_RCC_USART1_CLKSOURCE_LSE:
      usart1_frequency = LSE_VALUE;
      break;

    case LL_RCC_USART1_CLKSOURCE_PCLK:
    default:
      usart1_frequency = RCC_GetPCLK2ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
      break;
  }
  return usart1_frequency;
}

/**
  * @brief  Return USART2 clock frequency
  * @retval USART2 clock frequency (in Hz)
  */
uint32_t LL_RCC_GetUSART2ClockFreq(void)
{
  uint32_t usart2_frequency = 0U;

  /* USART2CLK clock frequency */
  switch (LL_RCC_GetUSART2ClockSource())
  {
    case LL_RCC_USART2_CLKSOURCE_SYSCLK:
      usart2_frequency = RCC_GetSystemClockFreq();
      break;
    
    case LL_RCC_USART2_CLKSOURCE_HSI:
      usart2_frequency = HSI_VALUE;
      break;
    
    case LL_RCC_USART2_CLKSOURCE_LSE:
      usart2_frequency = LSE_VALUE;
      break;

    case LL_RCC_USART2_CLKSOURCE_PCLK:
    default:
      usart2_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
      break;
  }
  return usart2_frequency;
}

/**
  * @brief  Return USART3 clock frequency
  * @retval USART3 clock frequency (in Hz)
  */
uint32_t LL_RCC_GetUSART3ClockFreq(void)
{
  uint32_t usart3_frequency = 0U;

  /* USART3CLK clock frequency */
  switch (LL_RCC_GetUSART3ClockSource())
  {
    case LL_RCC_USART3_CLKSOURCE_SYSCLK:
      usart3_frequency = RCC_GetSystemClockFreq();
      break;
    
    case LL_RCC_USART3_CLKSOURCE_HSI:
      usart3_frequency = HSI_VALUE;
      break;
    
    case LL_RCC_USART3_CLKSOURCE_LSE:
      usart3_frequency = LSE_VALUE;
      break;

    case LL_RCC_USART3_CLKSOURCE_PCLK:
    default:
      usart3_frequency = RCC_GetPCLK1ClockFreq(RCC_GetHCLKClockFreq(RCC_GetSystemClockFreq()));
      break;
  }
  return usart3_frequency;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCC_LL_Private_Functions
  * @{
  */

/**
  * @brief  Return SYSTEM clock frequency
  * @retval SYSTEM clock frequency (in Hz)
  */
uint32_t RCC_GetSystemClockFreq(void)
{
  uint32_t frequency;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (LL_RCC_GetSysClkSource())
  {
  case LL_RCC_SYS_CLKSOURCE_STATUS_HSE:  /* HSE used as system clock  source */
    frequency = HSE_VALUE;
    break;
#if defined(RCC_PLL_SUPPORT)
  case LL_RCC_SYS_CLKSOURCE_STATUS_PLL:  /* PLL used as system clock  source */
    frequency = RCC_PLL_GetFreqDomain_SYS();
    break;
#endif
  case LL_RCC_SYS_CLKSOURCE_STATUS_HSI:  /* HSI used as system clock  source */
  default:
    frequency = HSI_VALUE;
    break;
  }

  return frequency;
}

/**
  * @brief  Return HCLK clock frequency
  * @param  SYSCLK_Frequency SYSCLK clock frequency
  * @retval HCLK clock frequency (in Hz)
  */
uint32_t RCC_GetHCLKClockFreq(uint32_t SYSCLK_Frequency)
{
  /* HCLK clock frequency */
  return __LL_RCC_CALC_HCLK_FREQ(SYSCLK_Frequency, LL_RCC_GetAHBPrescaler());
}

/**
  * @brief  Return PCLK1 clock frequency
  * @param  HCLK_Frequency HCLK clock frequency
  * @retval PCLK1 clock frequency (in Hz)
  */
uint32_t RCC_GetPCLK1ClockFreq(uint32_t HCLK_Frequency)
{
  /* PCLK1 clock frequency */
  return __LL_RCC_CALC_PCLK1_FREQ(HCLK_Frequency, LL_RCC_GetAPB1Prescaler());
}

/**
  * @brief  Return PCLK2 clock frequency
  * @param  HCLK_Frequency HCLK clock frequency
  * @retval PCLK2 clock frequency (in Hz)
  */
uint32_t RCC_GetPCLK2ClockFreq(uint32_t HCLK_Frequency)
{
  /* PCLK2 clock frequency */
  return __LL_RCC_CALC_PCLK2_FREQ(HCLK_Frequency, LL_RCC_GetAPB2Prescaler());
}
#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  Return PLL clock frequency used for system domain
  * @retval PLL clock frequency (in Hz)
  */
uint32_t RCC_PLL_GetFreqDomain_SYS(void)
{
  uint32_t pllinputfreq;
  uint32_t pllsource;

  pllsource = LL_RCC_PLL_GetMainSource();

  switch (pllsource)
  {
    case LL_RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
      pllinputfreq = HSE_VALUE / ((LL_RCC_PLL_GetHSEPrediv() >> RCC_CFGR3_PLLXTPRE_Pos) + 1U);
      break;

    case LL_RCC_PLLSOURCE_HSI_DIV2:  /* HSI/2 used as PLL clock source */
    default:
      pllinputfreq = HSI_VALUE / 2;
      break;
  }
  return __LL_RCC_CALC_PLLCLK_FREQ(pllinputfreq, LL_RCC_PLL_GetPrediv(), LL_RCC_PLL_GetMulFactor(), LL_RCC_PLL_GetPostdiv());
}
#endif
/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RCC) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT Puya*****END OF FILE****/

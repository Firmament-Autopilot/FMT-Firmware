/**
  ******************************************************************************
  * @file    py32e407_ll_utils.c
  * @author  MCU Application Team
  * @brief   UTILS LL module driver.
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
#include "py32e407_ll_utils.h"
#include "py32e407_ll_rcc.h"
#include "py32e407_ll_system.h"
#ifdef  USE_FULL_ASSERT
  #include "py32_assert.h"
#else
  #define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

/** @addtogroup UTILS_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup UTILS_LL_Private_Constants
  * @{
  */
#if defined(RCC_PLL_SUPPORT)

#define UTILS_PLL_OUTPUT_MIN         24000000U      /*!< Frequency max for PLL output, in Hz  */
#define UTILS_PLL_OUTPUT_MAX         170000000U     /*!< Frequency max for PLL output, in Hz  */  
  
/* Defines used for HSE range */
#define UTILS_HSE_FREQUENCY_MIN      4000000U      /*!< Frequency min for HSE frequency, in Hz   */
#define UTILS_HSE_FREQUENCY_MAX      32000000U     /*!< Frequency max for HSE frequency, in Hz   */

/* Defines used for PLL input range */
#define LL_RCC_PLLINPUT_FREQ_MIN     2000000U      /*!< Frequency min for PLL input frequency, in Hz   */
#define LL_RCC_PLLINPUT_FREQ_MAX     32000000U     /*!< Frequency max for PLL input frequency, in Hz   */
#endif

/* Defines used for FLASH latency according to HCLK Frequency */
#define UTILS_SCALE1_LATENCY1_FREQ   25000000U     /*!< HCLK frequency to set FLASH latency 1 */
#define UTILS_SCALE1_LATENCY2_FREQ   50000000U     /*!< HCLK frequency to set FLASH latency 2 */
#define UTILS_SCALE1_LATENCY3_FREQ   75000000U     /*!< HCLK frequency to set FLASH latency 3 */
#define UTILS_SCALE1_LATENCY4_FREQ   100000000U    /*!< HCLK frequency to set FLASH latency 4 */
#define UTILS_SCALE1_LATENCY5_FREQ   125000000U    /*!< HCLK frequency to set FLASH latency 5 */
#define UTILS_SCALE1_LATENCY6_FREQ   150000000U    /*!< HCLK frequency to set FLASH latency 6 */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup UTILS_LL_Private_Macros
  * @{
  */
#define IS_LL_UTILS_SYSCLK_DIV(__VALUE__) (((__VALUE__) == LL_RCC_SYSCLK_DIV_1)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_2)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_4)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_8)   \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_16)  \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_64)  \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_128) \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_256) \
                                        || ((__VALUE__) == LL_RCC_SYSCLK_DIV_512))

#define IS_LL_UTILS_APB1_DIV(__VALUE__) (((__VALUE__) == LL_RCC_APB1_DIV_1) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_2) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_4) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_8) \
                                      || ((__VALUE__) == LL_RCC_APB1_DIV_16))

#define IS_LL_UTILS_APB2_DIV(__VALUE__) (((__VALUE__) == LL_RCC_APB2_DIV_1) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_2) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_4) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_8) \
                                      || ((__VALUE__) == LL_RCC_APB2_DIV_16))


#define IS_LL_UTILS_HSE_BYPASS(__STATE__) (((__STATE__) == LL_UTILS_HSEBYPASS_ON) \
                                        || ((__STATE__) == LL_UTILS_HSEBYPASS_OFF))

#if defined(RCC_PLL_SUPPORT)
#define IS_LL_UTILS_HSE_FREQUENCY(__FREQUENCY__) (((__FREQUENCY__) >= UTILS_HSE_FREQUENCY_MIN) && ((__FREQUENCY__) <= UTILS_HSE_FREQUENCY_MAX))

#define IS_LL_UTILS_PLL_INPUT_FREQUENCY(__FREQUENCY__) (((__FREQUENCY__) >= LL_RCC_PLLINPUT_FREQ_MIN) && ((__FREQUENCY__) <= LL_RCC_PLLINPUT_FREQ_MAX))

#define IS_LL_UTILS_PLL_FREQUENCY(__VALUE__) (((__VALUE__) >= UTILS_PLL_OUTPUT_MIN) && ((__VALUE__) <= UTILS_PLL_OUTPUT_MAX))

#define IS_LL_UTILS_PLLMUL_VALUE(__VALUE__) (((__VALUE__) >= 2) && ((__VALUE__) <= 257))

#define IS_LL_UTILS_PREDIV_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PREDIV_DIV_1) || ((__VALUE__) == LL_RCC_PREDIV_DIV_2) || ((__VALUE__) == LL_RCC_PREDIV_DIV_4) || ((__VALUE__) == LL_RCC_PREDIV_DIV_8))

#endif


/**
  * @}
  */
#if defined(RCC_PLL_SUPPORT)
  /* Private function prototypes -----------------------------------------------*/
  /** @defgroup UTILS_LL_Private_Functions UTILS Private functions
  * @{
  */
  static ErrorStatus UTILS_EnablePLLAndSwitchSystem(uint32_t SYSCLK_Frequency, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
  static ErrorStatus UTILS_PLL_IsBusy(void);
  /**
  * @}
  */
#endif
/* Exported functions --------------------------------------------------------*/
/** @addtogroup UTILS_LL_Exported_Functions
  * @{
  */

/** @addtogroup UTILS_LL_EF_DELAY
  * @{
  */

/**
  * @brief  This function configures the Cortex-M SysTick source to have 1ms time base.
  * @note   When a RTOS is used, it is recommended to avoid changing the Systick
  *         configuration by calling this function, for a delay use rather osDelay RTOS service.
  * @param  HCLKFrequency HCLK frequency in Hz
  * @note   HCLK frequency can be calculated thanks to RCC helper macro or function @ref LL_RCC_GetSystemClocksFreq
  * @retval None
  */
void LL_Init1msTick(uint32_t HCLKFrequency)
{
  /* Use frequency provided in argument */
  LL_InitTick(HCLKFrequency, 1000U);
}

/**
  * @brief  This function provides accurate delay (in milliseconds) based
  *         on SysTick counter flag
  * @note   When a RTOS is used, it is recommended to avoid using blocking delay
  *         and use rather osDelay service.
  * @note   To respect 1ms timebase, user should call @ref LL_Init1msTick function which
  *         will configure Systick to 1ms
  * @param  Delay specifies the delay time length, in milliseconds.
  * @retval None
  */
void LL_mDelay(uint32_t Delay)
{
  __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
  uint32_t tmpDelay; /* MISRAC2012-Rule-17.8 */
  /* Add this code to indicate that local variable is not used */
  ((void)tmp);
  tmpDelay  = Delay;
  /* Add a period to guaranty minimum wait */
  if (tmpDelay  < LL_MAX_DELAY)
  {
    tmpDelay ++;
  }

  while (tmpDelay  != 0U)
  {
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
    {
      tmpDelay --;
    }
  }
}

/**
  * @}
  */

/** @addtogroup UTILS_EF_SYSTEM
  *  @brief    System Configuration functions
  *
  @verbatim
 ===============================================================================
           ##### System Configuration functions #####
 ===============================================================================
    [..]
         System, AHB and APB1 buses clocks configuration

  @endverbatim
  @internal
             Depending on the device voltage range, the maximum frequency should be
             adapted accordingly:

             (++)  Table 1. HCLK clock frequency.
             (++) +-----------------------------------------------+
             (++) | Latency       | HCLK clock frequency (MHz)    |
             (++) |---------------|-------------------------------|
             (++) |0WS(1CPU cycle)|           HCLK <= 25          |
             (++) |---------------|-------------------------------|
             (++) |1WS(2CPU cycle)|      25 < HCLK <= 50          |
             (++) |---------------|-------------------------------|
             (++) |3WS(4CPU cycle)|      50 < HCLK <= 75          |
             (++) |---------------|-------------------------------|
             (++) |4WS(5CPU cycle)|      75 < HCLK <= 100         |
             (++) |---------------|-------------------------------|
             (++) |5WS(6CPU cycle)|     100 < HCLK <= 125         |
             (++) |---------------|-------------------------------|
             (++) |6WS(7CPU cycle)|     125 < HCLK <= 150         |
             (++) |---------------|-------------------------------|
             (++) |7WS(8CPU cycle)|     150 < HCLK <= 170         |
             (++) +-----------------------------------------------+

  @endinternal
  * @{
  */

/**
  * @brief  This function sets directly SystemCoreClock CMSIS variable.
  * @note   Variable can be calculated also through SystemCoreClockUpdate function.
  * @param  HCLKFrequency HCLK frequency in Hz (can be calculated thanks to RCC helper macro)
  * @retval None
  */
void LL_SetSystemCoreClock(uint32_t HCLKFrequency)
{
  /* HCLK clock frequency */
  SystemCoreClock = HCLKFrequency;
}

#if defined(RCC_PLL_SUPPORT)
/**
  * @brief  This function configures system clock with HSI as clock source of the PLL
  * @note   The application need to ensure that PLL is disabled.
  * @param  UTILS_PLLInitStruct pointer to a @ref LL_UTILS_PLLInitTypeDef structure that contains
  *                             the configuration information for the PLL.
  * @param  UTILS_ClkInitStruct pointer to a @ref LL_UTILS_ClkInitTypeDef structure that contains
  *                             the configuration information for the BUS prescalers.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: frequency configuration done
  *          - ERROR: frequency configuration not done
  */
ErrorStatus LL_PLL_ConfigSystemClock_HSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t pllfreq = 0U;
  uint32_t hpre = LL_RCC_SYSCLK_DIV_1;
  
  /* Check if one of the PLL is enabled */
  if (UTILS_PLL_IsBusy() == SUCCESS)
  {
    /* Check the parameters */
    assert_param(IS_LL_UTILS_PLLMUL_VALUE(UTILS_PLLInitStruct->PLLMul));
    
    pllfreq = __LL_RCC_CALC_PLLCLK_FREQ(HSI_VALUE / 2, UTILS_PLLInitStruct->Prediv, UTILS_PLLInitStruct->PLLMul, UTILS_PLLInitStruct->Postdiv);

    assert_param(IS_LL_UTILS_PLL_FREQUENCY(pllfreq));
        
    /* Enable HSI if not enabled */
    if (LL_RCC_HSI_IsReady() != 1U)
    {
      LL_RCC_HSI_Enable();
      while (LL_RCC_HSI_IsReady() != 1U)
      {
        /* Wait for HSI ready */
      }
    }

    /* Configure PLL */
    LL_RCC_PLL_SetMainSource(LL_RCC_PLLSOURCE_HSI_DIV2);
    
    /* Configure Prediv */
    LL_RCC_PLL_SetPrediv(UTILS_PLLInitStruct->Prediv);
    
    /* Configure PLLMUL */
    LL_RCC_PLL_SetMulFactor(UTILS_PLLInitStruct->PLLMul);
    
    /* Configure Postdiv */
    LL_RCC_PLL_SetPostdiv(UTILS_PLLInitStruct->Postdiv);
    
    /* Prevent undershoot at highest frequency by applying intermediate AHB prescaler 2 */
    if(pllfreq > 80000000U)
    {
      if (UTILS_ClkInitStruct->AHBCLKDivider == LL_RCC_SYSCLK_DIV_1)
      {
        UTILS_ClkInitStruct->AHBCLKDivider = LL_RCC_SYSCLK_DIV_2;
        hpre = LL_RCC_SYSCLK_DIV_2;
      }
    }
    
    /* Enable PLL and switch system clock to PLL */
    status = UTILS_EnablePLLAndSwitchSystem(pllfreq, UTILS_ClkInitStruct);
    
    /* Apply definitive AHB prescaler value if necessary */
    if ((status == SUCCESS) && (hpre != LL_RCC_SYSCLK_DIV_1))
    {
      /* Set FLASH latency to highest latency */
      status = LL_SetFlashLatency(pllfreq);
      if (status == SUCCESS)
      {
        UTILS_ClkInitStruct->AHBCLKDivider = LL_RCC_SYSCLK_DIV_1;
        LL_RCC_SetAHBPrescaler(UTILS_ClkInitStruct->AHBCLKDivider);
        LL_SetSystemCoreClock(pllfreq);
      }
    }
  }
  else
  {
    /* Current PLL configuration cannot be modified */
    status = ERROR;
  }

  return status;
}

/**
  * @brief  This function configures system clock with HSE as clock source of the PLL
  * @note   The application need to ensure that PLL is disabled.
  * @param  HSEFrequency HSE frequency
  * @param  HSEBypass This parameter can be one of the following values:
  *         @arg @ref LL_UTILS_HSEBYPASS_ON
  *         @arg @ref LL_UTILS_HSEBYPASS_OFF
  * @param  UTILS_PLLInitStruct pointer to a @ref LL_UTILS_PLLInitTypeDef structure that contains
  *                             the configuration information for the PLL.
  * @param  UTILS_ClkInitStruct pointer to a @ref LL_UTILS_ClkInitTypeDef structure that contains
  *                             the configuration information for the BUS prescalers.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: frequency configuration done
  *          - ERROR: frequency configuration not done
  */
ErrorStatus LL_PLL_ConfigSystemClock_HSE(uint32_t HSEFrequency, uint32_t HSEBypass, 
                                         LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t pllfreq = 0U;
  uint32_t hpre = LL_RCC_SYSCLK_DIV_1;

  /* Check the parameters */
  assert_param(IS_LL_UTILS_HSE_FREQUENCY(HSEFrequency));
  assert_param(IS_LL_UTILS_HSE_BYPASS(HSEBypass));
  
  /* Check if one of the PLL is enabled */
  if (UTILS_PLL_IsBusy() == SUCCESS)
  {
    assert_param(IS_LL_UTILS_PREDIV_VALUE(UTILS_PLLInitStruct->HSEPrediv));
    assert_param(IS_LL_UTILS_PLL_INPUT_FREQUENCY(HSEFrequency / ((UTILS_PLLInitStruct->HSEPrediv >> RCC_CFGR3_PLLXTPRE_Pos) + 1U)));
    
    assert_param(IS_LL_UTILS_PLLMUL_VALUE(UTILS_PLLInitStruct->PLLMul));
    pllfreq = __LL_RCC_CALC_PLLCLK_FREQ(HSEFrequency / ((UTILS_PLLInitStruct->HSEPrediv >> RCC_CFGR3_PLLXTPRE_Pos) + 1U), UTILS_PLLInitStruct->Prediv, UTILS_PLLInitStruct->PLLMul, UTILS_PLLInitStruct->Postdiv);
    
    assert_param(IS_LL_UTILS_PLL_FREQUENCY(pllfreq));
    
    /* Enable HSE if not enabled */
    if (LL_RCC_HSE_IsReady() != 1U)
    {
      /* Check if need to enable HSE bypass feature or not */
      if (HSEBypass == LL_UTILS_HSEBYPASS_ON)
      {
        LL_RCC_HSE_EnableBypass();
      }
      else
      {
        LL_RCC_HSE_DisableBypass();
        
        if(HSEFrequency < 8000000U)
        {
          /* Set frequency range of the HSE */
          LL_RCC_HSE_SetFreqRegion(LL_RCC_HSE_4_8MHz);
        }
        else if(HSEFrequency < 16000000U)
        {
          /* Set frequency range of the HSE */
          LL_RCC_HSE_SetFreqRegion(LL_RCC_HSE_8_16MHz);
        }
        else
        {
          /* Set frequency range of the HSE */
          LL_RCC_HSE_SetFreqRegion(LL_RCC_HSE_16_32MHz);
        }
      }

      /* Enable HSE */
      LL_RCC_HSE_Enable();
      while (LL_RCC_HSE_IsReady() != 1U)
      {
        /* Wait for HSE ready */
      }
    }

    /* Configure PLL */
    MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PLLXTPRE, UTILS_PLLInitStruct->HSEPrediv);
    LL_RCC_PLL_SetMainSource(LL_RCC_PLLSOURCE_HSE);
    
    /* Configure Prediv */
    LL_RCC_PLL_SetPrediv(UTILS_PLLInitStruct->Prediv);
    
    /* Configure PLLMUL */
    LL_RCC_PLL_SetMulFactor(UTILS_PLLInitStruct->PLLMul);
    
    /* Configure Postdiv */
    LL_RCC_PLL_SetPostdiv(UTILS_PLLInitStruct->Postdiv);
    
    /* Prevent undershoot at highest frequency by applying intermediate AHB prescaler 2 */
    if(pllfreq > 80000000U)
    {
      if (UTILS_ClkInitStruct->AHBCLKDivider == LL_RCC_SYSCLK_DIV_1)
      {
        UTILS_ClkInitStruct->AHBCLKDivider = LL_RCC_SYSCLK_DIV_2;
        hpre = LL_RCC_SYSCLK_DIV_2;
      }
    }

    /* Enable PLL and switch system clock to PLL */
    status = UTILS_EnablePLLAndSwitchSystem(pllfreq, UTILS_ClkInitStruct);
    
    /* Apply definitive AHB prescaler value if necessary */
    if ((status == SUCCESS) && (hpre != LL_RCC_SYSCLK_DIV_1))
    {
      /* Set FLASH latency to highest latency */
      status = LL_SetFlashLatency(pllfreq);
      if (status == SUCCESS)
      {
        UTILS_ClkInitStruct->AHBCLKDivider = LL_RCC_SYSCLK_DIV_1;
        LL_RCC_SetAHBPrescaler(UTILS_ClkInitStruct->AHBCLKDivider);
        LL_SetSystemCoreClock(pllfreq);
      }
    }
  }
  else
  {
    /* Current PLL configuration cannot be modified */
    status = ERROR;
  }

  return status;
}
#endif

/**
  * @brief  Update number of Flash wait states in line with new frequency and current
  *         voltage range.
  * @param  HCLKFrequency  HCLK frequency
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Latency has been modified
  *          - ERROR: Latency cannot be modified
  */
ErrorStatus LL_SetFlashLatency(uint32_t HCLKFrequency)
{
  uint32_t timeout;
  uint32_t getlatency;
  uint32_t latency;
  ErrorStatus status;

  /* Frequency cannot be equal to 0 or greater than max clock */
  if (HCLKFrequency == 0U)
  {
    status = ERROR;
    return status;
  }
  else
  {
    if (HCLKFrequency > UTILS_SCALE1_LATENCY6_FREQ)
    {
      /* 150 < HCLK    => 7WS (8 CPU cycles) */
      latency = LL_FLASH_LATENCY_7;
    }
    else if (HCLKFrequency > UTILS_SCALE1_LATENCY5_FREQ)
    {
      /* 125 < HCLK <= 150   => 6WS (7 CPU cycles) */
      latency = LL_FLASH_LATENCY_6;
    }
    else if (HCLKFrequency > UTILS_SCALE1_LATENCY4_FREQ)
    {
      /* 100 < HCLK <= 125   => 5WS (6 CPU cycles) */
      latency = LL_FLASH_LATENCY_5;
    }
    else if (HCLKFrequency > UTILS_SCALE1_LATENCY3_FREQ)
    {
      /* 75 < HCLK <= 100   => 4WS (5 CPU cycles) */
      latency = LL_FLASH_LATENCY_4;
    }
    else if (HCLKFrequency > UTILS_SCALE1_LATENCY2_FREQ)
    {
      /* 50 < HCLK <= 75   => 3WS (4 CPU cycles) */
      latency = LL_FLASH_LATENCY_3;
    }
    else if (HCLKFrequency > UTILS_SCALE1_LATENCY1_FREQ)
    {
      /* 25 < HCLK <= 50   => 1WS (2 CPU cycles) */
      latency = LL_FLASH_LATENCY_1;
    }
    else
    {
      /* HCLK <= 25   => 0WS (1 CPU cycles) */
      latency = LL_FLASH_LATENCY_0;
    }
  }

  LL_FLASH_SetLatency(latency);

  /* Check that the new number of wait states is taken into account to access the Flash
     memory by reading the FLASH_ACR register */
  timeout = 2u;
  do
  {
    /* Wait for Flash latency to be updated */
    getlatency = LL_FLASH_GetLatency();
    timeout--;
  }
  while ((getlatency != latency) && (timeout > 0u));

  if (getlatency != latency)
  {
    status = ERROR;
  }
  else
  {
    status = SUCCESS;
  }

  return status;
}

/**
  * @}
  */

/**
  * @}
  */
#if defined(RCC_PLL_SUPPORT)
/** @addtogroup UTILS_LL_Private_Functions
  * @{
  */

/**
  * @brief  Function to check that PLL can be modified
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PLL modification can be done
  *          - ERROR: PLL is busy
  */
static ErrorStatus UTILS_PLL_IsBusy(void)
{
  ErrorStatus status = SUCCESS;

  /* Check if PLL is busy*/
  if (LL_RCC_PLL_IsReady() != 0U)
  {
    /* PLL configuration cannot be modified */
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Function to enable PLL and switch system clock to PLL
  * @param  SYSCLK_Frequency SYSCLK frequency
  * @param  UTILS_ClkInitStruct pointer to a @ref LL_UTILS_ClkInitTypeDef structure that contains
  *                             the configuration information for the BUS prescalers.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: No problem to switch system to PLL
  *          - ERROR: Problem to switch system to PLL
  */
static ErrorStatus UTILS_EnablePLLAndSwitchSystem(uint32_t SYSCLK_Frequency, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t hclk_frequency = 0U;

  assert_param(IS_LL_UTILS_SYSCLK_DIV(UTILS_ClkInitStruct->AHBCLKDivider));
  assert_param(IS_LL_UTILS_APB1_DIV(UTILS_ClkInitStruct->APB1CLKDivider));
  assert_param(IS_LL_UTILS_APB2_DIV(UTILS_ClkInitStruct->APB2CLKDivider));

  /* Calculate HCLK frequency */
  hclk_frequency = __LL_RCC_CALC_HCLK_FREQ(SYSCLK_Frequency, UTILS_ClkInitStruct->AHBCLKDivider);

  /* Increasing the number of wait states because of higher CPU frequency */
  if (SystemCoreClock < hclk_frequency)
  {
    /* Set FLASH latency to highest latency */
    status = LL_SetFlashLatency(hclk_frequency);
  }

  /* Update system clock configuration */
  if (status == SUCCESS)
  {
    /* Enable PLL */
    LL_RCC_PLL_Enable();
    while (LL_RCC_PLL_IsReady() != 1U)
    {
      /* Wait for PLL ready */
    }

    /* Sysclk activation on the main PLL */
    LL_RCC_SetAHBPrescaler(UTILS_ClkInitStruct->AHBCLKDivider);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
    {
      /* Wait for system clock switch to PLL */
    }

    /* Set APB1 prescaler*/
    LL_RCC_SetAPB1Prescaler(UTILS_ClkInitStruct->APB1CLKDivider);
    
    /* Set APB2 prescaler*/
    LL_RCC_SetAPB2Prescaler(UTILS_ClkInitStruct->APB2CLKDivider);
  }

  /* Decreasing the number of wait states because of lower CPU frequency */
  if (SystemCoreClock > hclk_frequency)
  {
    /* Set FLASH latency to lowest latency */
    status = LL_SetFlashLatency(hclk_frequency);
  }

  /* Update SystemCoreClock variable */
  if (status == SUCCESS)
  {
    LL_SetSystemCoreClock(hclk_frequency);
  }

  return status;
}
/**
  * @}
  */
#endif
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Puya *****END OF FILE****/

/**
  ******************************************************************************
  * @file    py32e407_hal_adc.c
  * @author  MCU Application Team
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of the Analog to Digital Converter (ADC)
  *          peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *          Other functions (extended functions) are available in file
  *          "py32e407_hal_adc_ex.c".
  *
  @verbatim
  ==============================================================================
                     ##### ADC peripheral features #####
  ==============================================================================
  [..]
  (+) 12-bit, 10-bit, 8-bit or 6-bit configurable resolution.

  (+) Interrupt generation at the end of regular conversion and in case of
      analog watchdog .

  (+) Single and continuous conversion modes.

  (+) Scan mode for conversion of several channels sequentially.

  (+) Data alignment with in-built data coherency.

  (+) Programmable sampling time (channel wise)

  (+) External trigger (timer or EXTI) with configurable polarity

  (+) DMA request generation for transfer of conversions data of regular group.

  (+) Configurable delay between conversions in Dual interleaved mode.

  (+) ADC channels selectable single/differential input.

  (+) ADC offset shared on 4 offset instances.
  (+) ADC gain compensation

  (+) ADC calibration

  (+) ADC conversion of regular group.

  (+) ADC supply requirements: 1.62 V to 3.6 V.

  (+) ADC input range: from Vref- (connected to Vssa) to Vref+ (connected to
      Vdda or to an external voltage reference).


                     ##### How to use this driver #####
  ==============================================================================
    [..]

     *** Configuration of top level parameters related to ADC ***
     ============================================================
     [..]

    (#) Enable the ADC interface
        (++) As prerequisite, ADC clock must be configured at RCC top level.

        (++) Two clock settings are mandatory:
             (+++) ADC clock (core clock, also possibly conversion clock).

             (+++) ADC clock (conversions clock).
                   Two possible clock sources: synchronous clock derived from AHB clock
                   or asynchronous clock derived from system clock or PLL (output divider P)
                   running up to 75MHz.

             (+++) Example:
                   Into HAL_ADC_MspInit() (recommended code location) or with
                   other device clock parameters configuration:
               (+++) __HAL_RCC_ADC_CLK_ENABLE();                  (mandatory)

               RCC_ADCCLKSOURCE_PLL enable:                       (optional: if asynchronous clock selected)
               (+++) RCC_PeriphClkInitTypeDef   RCC_PeriphClkInit;
               (+++) PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
               (+++) PeriphClkInit.AdcClockSelection    = RCC_ADCCLKSOURCE_PLL;
               (+++) HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

        (++) ADC clock source and clock prescaler are configured at ADC level with
             parameter "ClockPrescaler" using function HAL_ADC_Init().

    (#) ADC pins configuration
         (++) Enable the clock for the ADC GPIOs
              using macro __HAL_RCC_GPIOx_CLK_ENABLE()
         (++) Configure these ADC pins in analog mode
              using function HAL_GPIO_Init()

    (#) Optionally, in case of usage of ADC with interruptions:
         (++) Configure the NVIC for ADC
              using function HAL_NVIC_EnableIRQ(ADCx_IRQn)
         (++) Insert the ADC interruption handler function HAL_ADC_IRQHandler()
              into the function of corresponding ADC interruption vector
              ADCx_IRQHandler().

    (#) Optionally, in case of usage of DMA:
         (++) Configure the DMA (DMA channel, mode normal or circular, ...)
              using function HAL_DMA_Init().
         (++) Configure the NVIC for DMA
              using function HAL_NVIC_EnableIRQ(DMAx_Channelx_IRQn)
         (++) Insert the ADC interruption handler function HAL_ADC_IRQHandler()
              into the function of corresponding DMA interruption vector
              DMAx_Channelx_IRQHandler().

     *** Configuration of ADC, group regular, channels parameters ***
     ================================================================
     [..]

    (#) Configure the ADC parameters (resolution, data alignment, ...)
        and regular group parameters (conversion trigger, sequencer, ...)
        using function HAL_ADC_Init().

    (#) Configure the channels for regular group parameters (channel number,
        channel rank into sequencer, ..., into regular group)
        using function HAL_ADC_ConfigChannel().

    (#) Optionally, configure the analog watchdog parameters (channels
        monitored, thresholds, ...)
        using function HAL_ADC_AnalogWDGConfig().

     *** Execution of ADC conversions ***
     ====================================
     [..]

    (#) Optionally, perform an automatic ADC calibration to improve the
        conversion accuracy
        using function HAL_ADCEx_Calibration_Start().

    (#) ADC driver can be used among three modes: polling, interruption,
        transfer by DMA.

        (++) ADC conversion by polling:
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start()
          (+++) Wait for ADC conversion completion
                using function HAL_ADC_PollForConversion()
          (+++) Retrieve conversion results
                using function HAL_ADC_GetValue()
          (+++) Stop conversion and disable the ADC peripheral
                using function HAL_ADC_Stop()

        (++) ADC conversion by interruption:
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start_IT()
          (+++) Wait for ADC conversion completion by call of function
                HAL_ADC_ConvCpltCallback()
                (this function must be implemented in user program)
          (+++) Retrieve conversion results
                using function HAL_ADC_GetValue()
          (+++) Stop conversion and disable the ADC peripheral
                using function HAL_ADC_Stop_IT()

        (++) ADC conversion with transfer by DMA:
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start_DMA()
          (+++) Wait for ADC conversion completion by call of function
                HAL_ADC_ConvCpltCallback() or HAL_ADC_ConvHalfBlockCpltCallback()
                (these functions must be implemented in user program)
          (+++) Conversion results are automatically transferred by DMA into
                destination variable address.
          (+++) Stop conversion and disable the ADC peripheral
                using function HAL_ADC_Stop_DMA()

     [..]

    (@) Callback functions must be implemented in user program:
      (+@) HAL_ADC_ErrorCallback()
      (+@) HAL_ADC_LevelOutOfWindowCallback() (callback of analog watchdog)
      (+@) HAL_ADC_ConvCpltCallback()
      (+@) HAL_ADC_ConvHalfBlockCpltCallback

     *** Deinitialization of ADC ***
     ============================================================
     [..]

    (#) Disable the ADC interface
      (++) ADC clock can be hard reset and disabled at RCC top level.
        (++) Hard reset of ADC peripherals
             using macro __ADCx_FORCE_RESET(), __ADCx_RELEASE_RESET().
        (++) ADC clock disable
             using the equivalent macro/functions as configuration step.
             (+++) Example:
                   Into HAL_ADC_MspDeInit() (recommended code location) or with
                   other device clock parameters configuration:
               (+++) RCC_OscInitStructure.OscillatorType = RCC_OSCILLATORTYPE_HSI14;
               (+++) RCC_OscInitStructure.HSI14State = RCC_HSI14_OFF; (if not used for system clock)
               (+++) HAL_RCC_OscConfig(&RCC_OscInitStructure);

    (#) ADC pins configuration
         (++) Disable the clock for the ADC GPIOs
              using macro __HAL_RCC_GPIOx_CLK_DISABLE()

    (#) Optionally, in case of usage of ADC with interruptions:
         (++) Disable the NVIC for ADC
              using function HAL_NVIC_EnableIRQ(ADCx_IRQn)

    (#) Optionally, in case of usage of DMA:
         (++) Deinitialize the DMA
              using function HAL_DMA_Init().
         (++) Disable the NVIC for DMA
              using function HAL_NVIC_EnableIRQ(DMAx_Channelx_IRQn)

    [..]

    *** Callback registration ***
    =============================================
    [..]

     The compilation flag USE_HAL_ADC_REGISTER_CALLBACKS, when set to 1,
     allows the user to configure dynamically the driver callbacks.
     Use Functions @ref HAL_ADC_RegisterCallback()
     to register an interrupt callback.
    [..]

     Function @ref HAL_ADC_RegisterCallback() allows to register following callbacks:
       (+) ConvCpltCallback               : ADC conversion complete callback
       (+) ConvHalfBlockCpltCallback      : ADC conversion DMA halfblock-transfer callback
       (+) LevelOutOfWindowCallback       : ADC analog watchdog 1 callback
       (+) ErrorCallback                  : ADC error callback
       (+) InjectedConvCpltCallback       : ADC group injected conversion complete callback
       (+) LevelOutOfWindow2Callback      : ADC analog watchdog 2 callback
       (+) LevelOutOfWindow3Callback      : ADC analog watchdog 3 callback
       (+) EndOfSamplingCallback          : ADC end of sampling callback
       (+) MspInitCallback                : ADC Msp Init callback
       (+) MspDeInitCallback              : ADC Msp DeInit callback
     This function takes as parameters the HAL peripheral handle, the Callback ID
     and a pointer to the user callback function.
    [..]

     Use function @ref HAL_ADC_UnRegisterCallback to reset a callback to the default
     weak function.
    [..]

     @ref HAL_ADC_UnRegisterCallback takes as parameters the HAL peripheral handle,
     and the Callback ID.
     This function allows to reset following callbacks:
       (+) ConvCpltCallback               : ADC conversion complete callback
       (+) ConvHalfBlockCpltCallback      : ADC conversion DMA halfblock-transfer callback
       (+) LevelOutOfWindowCallback       : ADC analog watchdog 1 callback
       (+) ErrorCallback                  : ADC error callback
       (+) InjectedConvCpltCallback       : ADC group injected conversion complete callback
       (+) LevelOutOfWindow2Callback      : ADC analog watchdog 2 callback
       (+) LevelOutOfWindow3Callback      : ADC analog watchdog 3 callback
       (+) EndOfSamplingCallback          : ADC end of sampling callback
       (+) MspInitCallback                : ADC Msp Init callback
       (+) MspDeInitCallback              : ADC Msp DeInit callback
     [..]

     By default, after the @ref HAL_ADC_Init() and when the state is @ref HAL_ADC_STATE_RESET
     all callbacks are set to the corresponding weak functions:
     examples @ref HAL_ADC_ConvCpltCallback(), @ref HAL_ADC_ErrorCallback().
     Exception done for MspInit and MspDeInit functions that are
     reset to the legacy weak functions in the @ref HAL_ADC_Init()/ @ref HAL_ADC_DeInit() only when
     these callbacks are null (not registered beforehand).
    [..]

     If MspInit or MspDeInit are not null, the @ref HAL_ADC_Init()/ @ref HAL_ADC_DeInit()
     keep and use the user MspInit/MspDeInit callbacks (registered beforehand) whatever the state.
     [..]

     Callbacks can be registered/unregistered in @ref HAL_ADC_STATE_READY state only.
     Exception done MspInit/MspDeInit functions that can be registered/unregistered
     in @ref HAL_ADC_STATE_READY or @ref HAL_ADC_STATE_RESET state,
     thus registered (user) MspInit/DeInit callbacks can be used during the Init/DeInit.
    [..]

     Then, the user first registers the MspInit/MspDeInit user callbacks
     using @ref HAL_ADC_RegisterCallback() before calling @ref HAL_ADC_DeInit()
     or @ref HAL_ADC_Init() function.
     [..]

     When the compilation flag USE_HAL_ADC_REGISTER_CALLBACKS is set to 0 or
     not defined, the callback registration feature is not available and all callbacks
     are set to the corresponding weak functions.

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

/** @defgroup ADC ADC
  * @brief ADC HAL module driver
  * @{
  */

#ifdef HAL_ADC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup ADC_Private_Constants ADC Private Constants
  * @{
  */

#define ADC_CFGR_FIELDS_1 (ADC_CFGR_RES    | ADC_CFGR_ALIGN   |\
                           ADC_CFGR_CONT   | ADC_CFGR_SCAN    |\
                           ADC_CFGR_DISCEN | ADC_CFGR_DISCNUM |\
                           ADC_CFGR_EXTEN  | ADC_CFGR_EXTSEL)              /*!< ADC_CFGR fields of parameters that can
                          be updated when no regular conversion is on-going */

/* Timeout values for ADC operations (enable settling time,                   */
/*   disable settling time, ...).                                             */
/*   Values defined to be higher than worst cases: low clock frequency,       */
/*   maximum prescalers.                                                      */
#define ADC_ENABLE_TIMEOUT              (2UL)    /*!< ADC enable time-out value  */
#define ADC_DISABLE_TIMEOUT             (2UL)    /*!< ADC disable time-out value */

/* Delay for ADC stabilization time.                                        */
/* Maximum delay is 1us (refer to device datasheet, parameter tSTAB).       */
/* Unit: us                                                                 */
#define ADC_STAB_DELAY_US               1U                      

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

/** @defgroup ADC_Exported_Functions_Group1 Initialization and de-initialization functions
  * @brief    ADC Initialization and Configuration functions
  *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize and configure the ADC.
      (+) De-initialize the ADC.
@endverbatim
  * @{
  */

/**
  * @brief  Initialize the ADC peripheral and regular group according to
  *         parameters specified in structure "ADC_InitTypeDef".
  * @note   As prerequisite, ADC clock must be configured at RCC top level
  *         (refer to description of RCC configuration for ADC
  *         in header of this file).
  * @note   Possibility to update parameters on the fly:
  *         This function initializes the ADC MSP (HAL_ADC_MspInit()) only when
  *         coming from ADC state reset. Following calls to this function can
  *         be used to reconfigure some parameters of ADC_InitTypeDef
  *         structure on the fly, without modifying MSP configuration. If ADC
  *         MSP has to be modified again, HAL_ADC_DeInit() must be called
  *         before HAL_ADC_Init().
  *         The setting of these parameters is conditioned to ADC state.
  *         For parameters constraints, see comments of structure
  *         "ADC_InitTypeDef".
  * @note   This function configures the ADC within 2 scopes: scope of entire
  *         ADC and scope of regular group. For parameters details, see comments
  *         of structure "ADC_InitTypeDef".
  * @note   Parameters related to common ADC registers (ADC clock mode) are set
  *         only if all ADCs are disabled.
  *         If this is not the case, these common parameters setting are
  *         bypassed without error reporting: it can be the intended behaviour in
  *         case of update of a parameter of ADC_InitTypeDef on the fly,
  *         without  disabling the other ADCs.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  uint32_t tmp_cfgr;
  uint32_t tmp_adc_is_conversion_on_going_regular;
  uint32_t tmp_adc_is_conversion_on_going_injected;

  /* Check ADC handle */
  if (hadc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_RESOLUTION(hadc->Init.Resolution));
  assert_param(IS_ADC_DATA_ALIGN(hadc->Init.DataAlign));
  assert_param(IS_ADC_GAIN_COMPENSATION(hadc->Init.GainCompensation));
  assert_param(IS_ADC_SCAN_MODE(hadc->Init.ScanConvMode));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  assert_param(IS_ADC_EXTTRIG_EDGE(hadc->Init.ExternalTrigConvEdge));
  assert_param(IS_ADC_EXTTRIG(hadc, hadc->Init.ExternalTrigConv));
  assert_param(IS_ADC_EOC_SELECTION(hadc->Init.EOCSelection));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.LowPowerAutoWait));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.OversamplingMode));

  if (hadc->Init.ScanConvMode != ADC_SCAN_DISABLE)
  {
    assert_param(IS_ADC_REGULAR_NB_CONV(hadc->Init.NbrOfConversion));
    assert_param(IS_FUNCTIONAL_STATE(hadc->Init.DiscontinuousConvMode));

    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      assert_param(IS_ADC_REGULAR_DISCONT_NUMBER(hadc->Init.NbrOfDiscConversion));
    }
  }

  /* DISCEN and CONT bits cannot be set at the same time */
  assert_param(!((hadc->Init.DiscontinuousConvMode == ENABLE) && (hadc->Init.ContinuousConvMode == ENABLE)));

  /* Actions performed only if ADC is coming from state reset:                */
  /* - Initialization of ADC MSP                                              */
  if (hadc->State == HAL_ADC_STATE_RESET)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* Init the ADC Callback settings */
    hadc->ConvCpltCallback              = HAL_ADC_ConvCpltCallback;                 /* Legacy weak callback */
    hadc->ConvHalfBlockCpltCallback     = HAL_ADC_ConvHalfBlockCpltCallback;        /* Legacy weak callback */
    hadc->LevelOutOfWindowCallback      = HAL_ADC_LevelOutOfWindowCallback;         /* Legacy weak callback */
    hadc->ErrorCallback                 = HAL_ADC_ErrorCallback;                    /* Legacy weak callback */
    hadc->InjectedConvCpltCallback      = HAL_ADCEx_InjectedConvCpltCallback;       /* Legacy weak callback */
    hadc->LevelOutOfWindow2Callback     = HAL_ADCEx_LevelOutOfWindow2Callback;      /* Legacy weak callback */
    hadc->LevelOutOfWindow3Callback     = HAL_ADCEx_LevelOutOfWindow3Callback;      /* Legacy weak callback */
    hadc->EndOfSamplingCallback         = HAL_ADCEx_EndOfSamplingCallback;          /* Legacy weak callback */

    if (hadc->MspInitCallback == NULL)
    {
      hadc->MspInitCallback = HAL_ADC_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware */
    hadc->MspInitCallback(hadc);
#else
    /* Init the low level hardware */
    HAL_ADC_MspInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Set ADC error code to none */
    ADC_CLEAR_ERRORCODE(hadc);

    /* Initialize Lock */
    hadc->Lock = HAL_UNLOCKED;
  }

  /* Configuration of ADC parameters if previous preliminary actions are      */
  /* correctly completed and if there is no conversion on going on regular    */
  /* group (ADC may already be enabled at this point if HAL_ADC_Init() is     */
  /* called to update a parameter on the fly).                                */
  tmp_adc_is_conversion_on_going_regular = LL_ADC_REG_IsConversionOngoing(hadc->Instance);

  if (((hadc->State & HAL_ADC_STATE_ERROR_INTERNAL) == 0UL)
      && (tmp_adc_is_conversion_on_going_regular == 0UL)
     )
  {
    /* Set ADC state */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY,
                      HAL_ADC_STATE_BUSY_INTERNAL);

    /* Configuration of common ADC parameters                                 */
    /* Parameters update conditioned to ADC state:                            */
    /* Parameters that can be updated only when ADC is disabled:              */
    /* Configuration of ADC:                                                  */
    /*  - resolution                               Init.Resolution            */
    /*  - data alignment                           Init.DataAlign             */
    /*  - external trigger to start conversion     Init.ExternalTrigConv      */
    /*  - external trigger polarity                Init.ExternalTrigConvEdge  */
    /*  - continuous conversion mode               Init.ContinuousConvMode    */
    /*  - discontinuous mode                       Init.DiscontinuousConvMode */
    /*  - discontinuous mode channel count         Init.NbrOfDiscConversion   */
    tmp_cfgr  = (ADC_CFGR_CONTINUOUS((uint32_t)hadc->Init.ContinuousConvMode)           |
                 hadc->Init.DataAlign                                                   |
                 hadc->Init.Resolution                                                  |
                 hadc->Init.ScanConvMode                                                |
                 ADC_CFGR_REG_DISCONTINUOUS((uint32_t)hadc->Init.DiscontinuousConvMode));

    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      tmp_cfgr |= ADC_CFGR_DISCONTINUOUS_NUM(hadc->Init.NbrOfDiscConversion);
    }

    /* Enable external trigger if trigger selection is different of software  */
    /* start.                                                                 */
    /* Note: This configuration keeps the hardware feature of parameter       */
    /*       ExternalTrigConvEdge "trigger edge none" equivalent to           */
    /*       software start.                                                  */
    if (hadc->Init.ExternalTrigConv != ADC_SOFTWARE_START)
    {
      tmp_cfgr |= ((hadc->Init.ExternalTrigConv & ADC_CFGR_EXTSEL)
                   | hadc->Init.ExternalTrigConvEdge
                  );
    }

    /* Update Configuration Register CFGR */
    MODIFY_REG(hadc->Instance->CFGR, ADC_CFGR_FIELDS_1, tmp_cfgr);

    /* Parameters update conditioned to ADC state:                            */
    /* Parameters that can be updated when ADC is disabled or enabled without */
    /* conversion on going on regular and injected groups:                    */
    /*  - Gain Compensation               Init.GainCompensation               */
    /*  - LowPowerAutoWait feature        Init.LowPowerAutoWait               */
    /*  - Oversampling parameters         Init.Oversampling                   */
    tmp_adc_is_conversion_on_going_injected = LL_ADC_INJ_IsConversionOngoing(hadc->Instance);
    if ((tmp_adc_is_conversion_on_going_regular == 0UL)
        && (tmp_adc_is_conversion_on_going_injected == 0UL)
       )
    {
      tmp_cfgr = ADC_CFGR_AUTOWAIT((uint32_t)hadc->Init.LowPowerAutoWait);

      MODIFY_REG(hadc->Instance->CFGR, ADC_CFGR_FIELDS_2, tmp_cfgr);

      if (hadc->Init.GainCompensation != 0UL)
      {
        SET_BIT(hadc->Instance->CFGR2, ADC_CFGR2_GCOMP);
        MODIFY_REG(hadc->Instance->GCOMP, ADC_GCOMP_GCOMPCOEFF, hadc->Init.GainCompensation);
      }
      else
      {
        CLEAR_BIT(hadc->Instance->CFGR2, ADC_CFGR2_GCOMP);
        MODIFY_REG(hadc->Instance->GCOMP, ADC_GCOMP_GCOMPCOEFF, 0UL);
      }

      if (hadc->Init.OversamplingMode == ENABLE)
      {
        assert_param(IS_ADC_OVERSAMPLING_RATIO(hadc->Init.Oversampling.Ratio));
        assert_param(IS_ADC_RIGHT_BIT_SHIFT(hadc->Init.Oversampling.RightBitShift));
        assert_param(IS_ADC_TRIGGERED_OVERSAMPLING_MODE(hadc->Init.Oversampling.TriggeredMode));
        assert_param(IS_ADC_REGOVERSAMPLING_MODE(hadc->Init.Oversampling.OversamplingStopReset));

        /* Configuration of Oversampler:                                      */
        /*  - Oversampling Ratio                                              */
        /*  - Right bit shift                                                 */
        /*  - Triggered mode                                                  */
        /*  - Oversampling mode (continued/resumed)                           */
        MODIFY_REG(hadc->Instance->CFGR2,
                   ADC_CFGR2_OVSR  |
                   ADC_CFGR2_OVSS  |
                   ADC_CFGR2_TROVS |
                   ADC_CFGR2_ROVSM,
                   ADC_CFGR2_ROVSE                       |
                   hadc->Init.Oversampling.Ratio         |
                   hadc->Init.Oversampling.RightBitShift |
                   hadc->Init.Oversampling.TriggeredMode |
                   hadc->Init.Oversampling.OversamplingStopReset
                  );
      }
      else
      {
        /* Disable ADC oversampling scope on ADC group regular */
        CLEAR_BIT(hadc->Instance->CFGR2, ADC_CFGR2_ROVSE);
      }

    }

    /* Configuration of regular group sequencer:                              */
    /* - if scan mode is disabled, regular channels sequence length is set to */
    /*   0x00: 1 channel converted (channel on regular rank 1)                */
    /*   Parameter "NbrOfConversion" is discarded.                            */
    /* - if scan mode is enabled, regular channels sequence length is set to  */
    /*   parameter "NbrOfConversion".                                         */

    if (hadc->Init.ScanConvMode == ADC_SCAN_ENABLE)
    {
      /* Set number of ranks in regular group sequencer */
      MODIFY_REG(hadc->Instance->SQR1, ADC_SQR1_L, (hadc->Init.NbrOfConversion - (uint8_t)1));
    }
    else
    {
      CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L);
    }

    /* Initialize the ADC state */
    /* Clear HAL_ADC_STATE_BUSY_INTERNAL bit, set HAL_ADC_STATE_READY bit */
    ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_BUSY_INTERNAL, HAL_ADC_STATE_READY);
  }
  else
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

    tmp_hal_status = HAL_ERROR;
  }

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Deinitialize the ADC peripheral registers to their default reset
  *         values, with deinitialization of the ADC MSP.
  * @note   For devices with several ADCs: reset of ADC common registers is done
  *         only if all ADCs sharing the same common group are disabled.
  *         (function "HAL_ADC_MspDeInit()" is also called under the same conditions:
  *         all ADC instances use the same core clock at RCC level, disabling
  *         the core clock reset all ADC instances).
  *         If this is not the case, reset of these common parameters reset is
  *         bypassed without error reporting: it can be the intended behavior in
  *         case of reset of a single ADC while the other ADCs sharing the same
  *         common group is still running.
  * @note   By default, HAL_ADC_DeInit() set ADC in mode deep power-down:
  *         this saves more power by reducing leakage currents
  *         and is particularly interesting before entering MCU low-power modes.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status;
  FlagStatus adcclkchanged = RESET;

  /* Check ADC handle */
  if (hadc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Set ADC state */
  SET_BIT(hadc->State, HAL_ADC_STATE_BUSY_INTERNAL);

  /* Stop potential conversion on going */
  tmp_hal_status = ADC_ConversionStop(hadc);

  /* Disable ADC peripheral if conversions are effectively stopped */
  if (tmp_hal_status == HAL_OK)
  {
    /* Disable the ADC peripheral */
    tmp_hal_status = ADC_Disable(hadc);

    /* Check if ADC is effectively disabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Change ADC state */
      hadc->State = HAL_ADC_STATE_READY;
    }
  }

  /* Note: HAL ADC deInit is done independently of ADC conversion stop        */
  /*       and disable return status. In case of status fail, attempt to      */
  /*       perform deinitialization anyway and it is up user code in          */
  /*       in HAL_ADC_MspDeInit() to reset the ADC peripheral using           */
  /*       system RCC hard reset.                                             */

  /* ========== Reset ADC registers ========== */
  /* Reset register IER */
  __HAL_ADC_DISABLE_IT(hadc, (ADC_IT_AWD3  | ADC_IT_AWD2 | ADC_IT_AWD1 |
                              ADC_IT_JEOS  | ADC_IT_JEOC |
                              ADC_IT_EOS   | ADC_IT_EOC  |
                              ADC_IT_EOSMP ));

  /* Reset register ISR */
  __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_AWD3  | ADC_FLAG_AWD2 | ADC_FLAG_AWD1 |
                              ADC_FLAG_JEOS  | ADC_FLAG_JEOC |
                              ADC_FLAG_EOS   | ADC_FLAG_EOC  |
                              ADC_FLAG_EOSMP ));

  /* Reset register CFGR */
  CLEAR_BIT(hadc->Instance->CFGR, ADC_CFGR_FIELDS);

  /* Reset register CFGR2 */
  CLEAR_BIT(hadc->Instance->CFGR2, ADC_CFGR2_CALNUM | ADC_CFGR2_GCOMP | ADC_CFGR2_ROVSM | ADC_CFGR2_TROVS | ADC_CFGR2_OVSS |
            ADC_CFGR2_OVSR  | ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSE );

  /* Reset register SMPR1 */
  CLEAR_BIT(hadc->Instance->SMPR1, ADC_SMPR1_FIELDS);

  /* Reset register SMPR2 */
  CLEAR_BIT(hadc->Instance->SMPR2, ADC_SMPR2_SMP19 | ADC_SMPR2_SMP18 | ADC_SMPR2_SMP17 | ADC_SMPR2_SMP16 |
            ADC_SMPR2_SMP15 | ADC_SMPR2_SMP14 | ADC_SMPR2_SMP13 |
            ADC_SMPR2_SMP12 | ADC_SMPR2_SMP11 | ADC_SMPR2_SMP10);

  /* Reset register TR1 */
  CLEAR_BIT(hadc->Instance->TR1, ADC_TR1_HT1 | ADC_TR1_LT1);

  /* Reset register TR2 */
  CLEAR_BIT(hadc->Instance->TR2, ADC_TR2_HT2 | ADC_TR2_LT2);

  /* Reset register TR3 */
  CLEAR_BIT(hadc->Instance->TR3, ADC_TR3_HT3 | ADC_TR3_LT3);

  /* Reset register SQR1 */
  CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_SQ4 | ADC_SQR1_SQ3 | ADC_SQR1_SQ2 |
            ADC_SQR1_SQ1 | ADC_SQR1_L);

  /* Reset register SQR2 */
  CLEAR_BIT(hadc->Instance->SQR2, ADC_SQR2_SQ9 | ADC_SQR2_SQ8 | ADC_SQR2_SQ7 |
            ADC_SQR2_SQ6 | ADC_SQR2_SQ5);

  /* Reset register SQR3 */
  CLEAR_BIT(hadc->Instance->SQR3, ADC_SQR3_SQ14 | ADC_SQR3_SQ13 | ADC_SQR3_SQ12 |
            ADC_SQR3_SQ11 | ADC_SQR3_SQ10);

  /* Reset register SQR4 */
  CLEAR_BIT(hadc->Instance->SQR4, ADC_SQR4_SQ16 | ADC_SQR4_SQ15);

  /* Reset register DR */
  /* bits in access mode read only, no direct reset applicable*/

  /* Reset register JSQR */
  CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL | ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN | ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1 );

  /* Reset register OFR1 */
  CLEAR_BIT(hadc->Instance->OFR1, ADC_OFR1_OFFSET1_EN | ADC_OFR1_OFFSET1_CH | ADC_OFR1_OFFSET1);
  /* Reset register OFR2 */
  CLEAR_BIT(hadc->Instance->OFR2, ADC_OFR2_OFFSET2_EN | ADC_OFR2_OFFSET2_CH | ADC_OFR2_OFFSET2);
  /* Reset register OFR3 */
  CLEAR_BIT(hadc->Instance->OFR3, ADC_OFR3_OFFSET3_EN | ADC_OFR3_OFFSET3_CH | ADC_OFR3_OFFSET3);
  /* Reset register OFR4 */
  CLEAR_BIT(hadc->Instance->OFR4, ADC_OFR4_OFFSET4_EN | ADC_OFR4_OFFSET4_CH | ADC_OFR4_OFFSET4);

  /* Reset registers JDR1, JDR2, JDR3, JDR4 */
  /* bits in access mode read only, no direct reset applicable*/

  /* Reset register AWD2CR */
  CLEAR_BIT(hadc->Instance->AWD2CR, ADC_AWD2CR_AWD2CH);

  /* Reset register AWD3CR */
  CLEAR_BIT(hadc->Instance->AWD3CR, ADC_AWD3CR_AWD3CH);

  /* Reset register GCOMP */
  hadc->Instance->GCOMP = 0;

  /* Reset register DIFSEL */
  CLEAR_BIT(hadc->Instance->DIFSEL, ADC_DIFSEL_DIFSEL);


  /* ========== Reset common ADC registers ========== */

  /* Software is allowed to change common parameters only when all the other
     ADCs are disabled.   */
  if (__LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__LL_ADC_COMMON_INSTANCE(hadc->Instance)) == 0UL)
  {
    /* Reset configuration of ADC common register CCR:
      - clock mode: CKMODE, PRESCEN
      - multimode related parameters (when this feature is available): MDMA,
        DMACFG, DELAY, DUAL (set by HAL_ADCEx_MultiModeConfigChannel() API)
      - internal measurement paths: Vbat, temperature sensor, Vref (set into
        HAL_ADC_ConfigChannel() or HAL_ADCEx_InjectedConfigChannel() )
    */
    if (__HAL_RCC_ADC1_IS_CLK_DISABLED() != 0U)
    {
      __HAL_RCC_ADC1_CLK_ENABLE();
      adcclkchanged = SET;
    }

    ADC_CLEAR_COMMON_CONTROL_REGISTER(hadc);

    /* Restore clock configuration if changed */
    if (adcclkchanged == SET)
    {
      __HAL_RCC_ADC1_CLK_DISABLE();
    }

    /* ========== Hard reset ADC peripheral ========== */
    /* Performs a global reset of the entire ADC peripherals instances        */
    /* sharing the same common ADC instance: ADC state is forced to           */
    /* a similar state as after device power-on.                              */
    /* Note: A possible implementation is to add RCC bus reset of ADC         */
    /* (for example, using macro                                              */
    /*  __HAL_RCC_ADC..._FORCE_RESET()/..._RELEASE_RESET()/..._CLK_DISABLE()) */
    /* in function "void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)":         */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    if (hadc->MspDeInitCallback == NULL)
    {
      hadc->MspDeInitCallback = HAL_ADC_MspDeInit; /* Legacy weak MspDeInit  */
    }

    /* DeInit the low level hardware */
    hadc->MspDeInitCallback(hadc);
#else
    /* DeInit the low level hardware */
    HAL_ADC_MspDeInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }

  /* Set ADC error code to none */
  ADC_CLEAR_ERRORCODE(hadc);

  /* Reset injected channel configuration parameters */
  hadc->InjectionConfig.ContextQueue = 0;
  hadc->InjectionConfig.ChannelCount = 0;

  /* Set ADC state */
  hadc->State = HAL_ADC_STATE_RESET;

  /* Process unlocked */
  __HAL_UNLOCK(hadc);

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Initialize the ADC MSP.
  * @param hadc ADC handle
  * @retval None
  */
__weak void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_MspInit must be implemented in the user file.
   */
}

/**
  * @brief  DeInitialize the ADC MSP.
  * @param hadc ADC handle
  * @note   All ADC instances use the same core clock at RCC level, disabling
  *         the core clock reset all ADC instances).
  * @retval None
  */
__weak void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_MspDeInit must be implemented in the user file.
   */
}

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User ADC Callback
  *         To be used instead of the weak predefined callback
  * @param  hadc Pointer to a ADC_HandleTypeDef structure that contains
  *                the configuration information for the specified ADC.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC conversion complete callback ID
  *          @arg @ref HAL_ADC_CONVERSION_HALFBLOCK_CB_ID     ADC conversion DMA halfblock-transfer callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC analog watchdog 1 callback ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC error callback ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC group injected conversion complete callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_2_CB_ID    ADC analog watchdog 2 callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_3_CB_ID    ADC analog watchdog 3 callback ID
  *          @arg @ref HAL_ADC_END_OF_SAMPLING_CB_ID          ADC end of sampling callback ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp Init callback ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp DeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID,
                                           pADC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  if ((hadc->State & HAL_ADC_STATE_READY) != 0UL)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        hadc->ConvCpltCallback = pCallback;
        break;

      case HAL_ADC_CONVERSION_HALFBLOCK_CB_ID :
        hadc->ConvHalfBlockCpltCallback = pCallback;
        break;

      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        hadc->LevelOutOfWindowCallback = pCallback;
        break;

      case HAL_ADC_ERROR_CB_ID :
        hadc->ErrorCallback = pCallback;
        break;

      case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        hadc->InjectedConvCpltCallback = pCallback;
        break;

      case HAL_ADC_LEVEL_OUT_OF_WINDOW_2_CB_ID :
        hadc->LevelOutOfWindow2Callback = pCallback;
        break;

      case HAL_ADC_LEVEL_OUT_OF_WINDOW_3_CB_ID :
        hadc->LevelOutOfWindow3Callback = pCallback;
        break;

      case HAL_ADC_END_OF_SAMPLING_CB_ID :
        hadc->EndOfSamplingCallback = pCallback;
        break;

      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = pCallback;
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = pCallback;
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Unregister a ADC Callback
  *         ADC callback is redirected to the weak predefined callback
  * @param  hadc Pointer to a ADC_HandleTypeDef structure that contains
  *                the configuration information for the specified ADC.
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC conversion complete callback ID
  *          @arg @ref HAL_ADC_CONVERSION_HALFBLOCK_CB_ID     ADC conversion DMA halfblock-transfer callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC analog watchdog 1 callback ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC error callback ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC group injected conversion complete callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_2_CB_ID    ADC analog watchdog 2 callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_3_CB_ID    ADC analog watchdog 3 callback ID
  *          @arg @ref HAL_ADC_END_OF_SAMPLING_CB_ID          ADC end of sampling callback ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp Init callback ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp DeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  if ((hadc->State & HAL_ADC_STATE_READY) != 0UL)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        hadc->ConvCpltCallback = HAL_ADC_ConvCpltCallback;
        break;

      case HAL_ADC_CONVERSION_HALFBLOCK_CB_ID :
        hadc->ConvHalfBlockCpltCallback = HAL_ADC_ConvHalfBlockCpltCallback;
        break;

      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        hadc->LevelOutOfWindowCallback = HAL_ADC_LevelOutOfWindowCallback;
        break;

      case HAL_ADC_ERROR_CB_ID :
        hadc->ErrorCallback = HAL_ADC_ErrorCallback;
        break;

      case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        hadc->InjectedConvCpltCallback = HAL_ADCEx_InjectedConvCpltCallback;
        break;

      case HAL_ADC_LEVEL_OUT_OF_WINDOW_2_CB_ID :
        hadc->LevelOutOfWindow2Callback = HAL_ADCEx_LevelOutOfWindow2Callback;
        break;

      case HAL_ADC_LEVEL_OUT_OF_WINDOW_3_CB_ID :
        hadc->LevelOutOfWindow3Callback = HAL_ADCEx_LevelOutOfWindow3Callback;
        break;

      case HAL_ADC_END_OF_SAMPLING_CB_ID :
        hadc->EndOfSamplingCallback = HAL_ADCEx_EndOfSamplingCallback;
        break;

      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit; /* Legacy weak MspInit              */
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit; /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group2 ADC Input and Output operation functions
  * @brief    ADC IO operation functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Start conversion of regular group.
      (+) Stop conversion of regular group.
      (+) Poll for conversion complete on regular group.
      (+) Poll for conversion event.
      (+) Get result of regular channel conversion.
      (+) Start conversion of regular group and enable interruptions.
      (+) Stop conversion of regular group and disable interruptions.
      (+) Handle ADC interrupt request
      (+) Start conversion of regular group and enable DMA transfer.
      (+) Stop conversion of regular group and disable ADC DMA transfer.
@endverbatim
  * @{
  */

/**
  * @brief  Enable ADC, start conversion of regular group.
  * @note   Interruptions enabled in this function: None.
  * @note   Case of multimode enabled (when multimode feature is available):
  *           if ADC is Slave, ADC is enabled but conversion is not started,
  *           if ADC is master, ADC is enabled and multimode conversion is started.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status;
#if defined(ADC_MULTIMODE_SUPPORT)
  const ADC_TypeDef *tmpADC_Master;
  uint32_t tmp_multimode_config = LL_ADC_GetMultimode(__LL_ADC_COMMON_INSTANCE(hadc->Instance));
#endif /* ADC_MULTIMODE_SUPPORT */

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Perform ADC enable and conversion start if no conversion is on going */
  if (LL_ADC_REG_IsConversionOngoing(hadc->Instance) == 0UL)
  {
    /* Process locked */
    __HAL_LOCK(hadc);

    /* Enable the ADC peripheral */
    tmp_hal_status = ADC_Enable(hadc);

    /* Start conversion if ADC is effectively enabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state                                                        */
      /* - Clear state bitfield related to regular group conversion results   */
      /* - Set state bitfield related to regular operation                    */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_EOSMP,
                        HAL_ADC_STATE_REG_BUSY);

#if defined(ADC_MULTIMODE_SUPPORT)
      /* Reset HAL_ADC_STATE_MULTIMODE_SLAVE bit
        - if ADC instance is master or if multimode feature is not available
        - if multimode setting is disabled (ADC instance slave in independent mode) */
      if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
          || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
         )
      {
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      }
#endif /* ADC_MULTIMODE_SUPPORT */

      /* Set ADC error code */
      /* Check if a conversion is on going on ADC group injected */
      if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
      {
        /* Reset ADC error code fields related to regular conversions only */
        CLEAR_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);
      }
      else
      {
        /* Reset all ADC error code fields */
        ADC_CLEAR_ERRORCODE(hadc);
      }

      /* Clear ADC group regular conversion flag */
      /* (To ensure of no unknown state from potential previous ADC operations) */
      __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_EOC | ADC_FLAG_EOS));

      /* Process unlocked */
      /* Unlock before starting ADC conversions: in case of potential         */
      /* interruption, to let the process to ADC IRQ Handler.                 */
      __HAL_UNLOCK(hadc);

      /* Enable conversion of regular group.                                  */
      /* If software start has been selected, conversion starts immediately.  */
      /* If external trigger has been selected, conversion will start at next */
      /* trigger event.                                                       */
      /* Case of multimode enabled (when multimode feature is available):     */
      /*  - if ADC is slave and dual regular conversions are enabled, ADC is  */
      /*    enabled only (conversion is not started),                         */
      /*  - if ADC is master, ADC is enabled and conversion is started.       */
#if defined(ADC_MULTIMODE_SUPPORT)
      if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
          || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
          || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_SIMULT)
          || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_ALTERN)
         )
      {
        /* ADC instance is not a multimode slave instance with multimode regular conversions enabled */
        if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_JAUTO) != 0UL)
        {
          ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
        }

        /* Start ADC group regular conversion */
        LL_ADC_REG_StartConversion(hadc->Instance);
      }
      else
      {
        /* ADC instance is a multimode slave instance with multimode regular conversions enabled */
        SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
        /* if Master ADC JAUTO bit is set, update Slave State in setting
           HAL_ADC_STATE_INJ_BUSY bit and in resetting HAL_ADC_STATE_INJ_EOC bit */
        tmpADC_Master = __LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance);
        if (READ_BIT(tmpADC_Master->CFGR, ADC_CFGR_JAUTO) != 0UL)
        {
          ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
        }

      }
#else
      if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_JAUTO) != 0UL)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }

      /* Start ADC group regular conversion */
      LL_ADC_REG_StartConversion(hadc->Instance);
#endif /* ADC_MULTIMODE_SUPPORT */
    }
    else
    {
      /* Process unlocked */
      __HAL_UNLOCK(hadc);
    }
  }
  else
  {
    tmp_hal_status = HAL_BUSY;
  }

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected channels in
  *         case of auto_injection mode), disable ADC peripheral.
  * @note:  ADC peripheral disable is forcing stop of potential
  *         conversion on injected group. If injected group is under use, it
  *         should be preliminarily stopped using HAL_ADCEx_InjectedStop function.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Process locked */
  __HAL_LOCK(hadc);

  /* 1. Stop potential conversion on going */
  tmp_hal_status = ADC_ConversionStop(hadc);

  /* Disable ADC peripheral if conversions are effectively stopped */
  if (tmp_hal_status == HAL_OK)
  {
    /* 2. Disable the ADC peripheral */
    tmp_hal_status = ADC_Disable(hadc);

    /* Check if ADC is effectively disabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }

  /* Process unlocked */
  __HAL_UNLOCK(hadc);

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Wait for regular group conversion to be completed.
  * @note   ADC conversion flags EOS (end of sequence) and EOC (end of
  *         conversion) are cleared by this function, with an exception:
  *         if low power feature "LowPowerAutoWait" is enabled, flags are
  *         not cleared to not interfere with this feature until data register
  *         is read using function HAL_ADC_GetValue().
  * @note   This function cannot be used in a particular setup: ADC configured
  *         in DMA mode and polling for end of each conversion (ADC init
  *         parameter "EOCSelection" set to ADC_EOC_SINGLE_CONV).
  *         In this case, DMA resets the flag EOC and polling cannot be
  *         performed on each conversion. Nevertheless, polling can still
  *         be performed on the complete sequence (ADC init
  *         parameter "EOCSelection" set to ADC_EOC_SEQ_CONV).
  * @param hadc ADC handle
  * @param Timeout Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout)
{
  uint32_t tickstart;
  uint32_t tmp_Flag_End;
  uint32_t tmp_cfgr;
#if defined(ADC_MULTIMODE_SUPPORT)
  const ADC_TypeDef *tmpADC_Master;
  uint32_t tmp_multimode_config = LL_ADC_GetMultimode(__LL_ADC_COMMON_INSTANCE(hadc->Instance));
#endif /* ADC_MULTIMODE_SUPPORT */

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* If end of conversion selected to end of sequence conversions */
  if (hadc->Init.EOCSelection == ADC_EOC_SEQ_CONV)
  {
    tmp_Flag_End = ADC_FLAG_EOS;
  }
  /* If end of conversion selected to end of unitary conversion */
  else /* ADC_EOC_SINGLE_CONV */
  {
    /* Verification that ADC configuration is compliant with polling for      */
    /* each conversion:                                                       */
    /* Particular case is ADC configured in DMA mode and ADC sequencer with   */
    /* several ranks and polling for end of each conversion.                  */
    /* For code simplicity sake, this particular case is generalized to       */
    /* ADC configured in DMA mode and and polling for end of each conversion. */
#if defined(ADC_MULTIMODE_SUPPORT)
    if ((tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_SIMULT)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_ALTERN)
       )
    {
      /* Check ADC DMA mode in independent mode on ADC group regular */
      if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_DMAEN) != 0UL)
      {
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        return HAL_ERROR;
      }
      else
      {
        tmp_Flag_End = (ADC_FLAG_EOC);
      }
    }
    else
    {
      tmp_Flag_End = (ADC_FLAG_EOC);
    }
#else
    /* Check ADC DMA mode */
    if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_DMAEN) != 0UL)
    {
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      return HAL_ERROR;
    }
    else
    {
      tmp_Flag_End = (ADC_FLAG_EOC);
    }
#endif /* ADC_MULTIMODE_SUPPORT */
  }

  /* Get tick count */
  tickstart = HAL_GetTick();

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while ((hadc->Instance->ISR & tmp_Flag_End) == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* New check to avoid false timeout detection in case of preemption */
        if ((hadc->Instance->ISR & tmp_Flag_End) == 0UL)
        {
          /* Update ADC state machine to timeout */
          SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

          /* Process unlocked */
          __HAL_UNLOCK(hadc);

          return HAL_TIMEOUT;
        }
      }
    }
  }

  /* Update ADC state machine */
  SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);

  /* Determine whether any further conversion upcoming on group regular       */
  /* by external trigger, continuous mode or scan sequence on going.          */
  if ((LL_ADC_REG_IsTriggerSourceSWStart(hadc->Instance) != 0UL)
      && (hadc->Init.ContinuousConvMode == DISABLE)
     )
  {
    /* Check whether end of sequence is reached */
    if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOS))
    {
      /* Set ADC state */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);

      if ((hadc->State & HAL_ADC_STATE_INJ_BUSY) == 0UL)
      {
        SET_BIT(hadc->State, HAL_ADC_STATE_READY);
      }
    }
  }

  /* Get relevant register CFGR in ADC instance of ADC master or slave        */
  /* in function of multimode state (for devices with multimode               */
  /* available).                                                              */
#if defined(ADC_MULTIMODE_SUPPORT)
  if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
      || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
      || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_SIMULT)
      || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_ALTERN)
     )
  {
    /* Retrieve handle ADC CFGR register */
    tmp_cfgr = READ_REG(hadc->Instance->CFGR);
  }
  else
  {
    /* Retrieve Master ADC CFGR register */
    tmpADC_Master = __LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance);
    tmp_cfgr = READ_REG(tmpADC_Master->CFGR);
  }
#else
  /* Retrieve handle ADC CFGR register */
  tmp_cfgr = READ_REG(hadc->Instance->CFGR);
#endif /* ADC_MULTIMODE_SUPPORT */

  /* Clear polled flag */
  if (tmp_Flag_End == ADC_FLAG_EOS)
  {
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOS);
  }
  else
  {
    /* Clear end of conversion EOC flag of regular group if low power feature */
    /* "LowPowerAutoWait " is disabled, to not interfere with this feature    */
    /* until data register is read using function HAL_ADC_GetValue().         */
    if (READ_BIT(tmp_cfgr, ADC_CFGR_AUTDLY) == 0UL)
    {
      __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_EOC | ADC_FLAG_EOS));
    }
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Poll for ADC event.
  * @param hadc ADC handle
  * @param EventType the ADC event type.
  *          This parameter can be one of the following values:
  *            @arg @ref ADC_EOSMP_EVENT  ADC End of Sampling event
  *            @arg @ref ADC_AWD1_EVENT   ADC Analog watchdog 1 event (main analog watchdog, present on
  *                                       all series)
  *            @arg @ref ADC_AWD2_EVENT   ADC Analog watchdog 2 event (additional analog watchdog, not present on
  *                                       all series)
  *            @arg @ref ADC_AWD3_EVENT   ADC Analog watchdog 3 event (additional analog watchdog, not present on
  *                                       all series)
  * @param Timeout Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_PollForEvent(ADC_HandleTypeDef *hadc, uint32_t EventType, uint32_t Timeout)
{
  uint32_t tickstart;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_EVENT_TYPE(EventType));

  /* Get tick count */
  tickstart = HAL_GetTick();

  /* Check selected event flag */
  while (__HAL_ADC_GET_FLAG(hadc, EventType) == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* New check to avoid false timeout detection in case of preemption */
        if (__HAL_ADC_GET_FLAG(hadc, EventType) == 0UL)
        {
          /* Update ADC state machine to timeout */
          SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

          /* Process unlocked */
          __HAL_UNLOCK(hadc);

          return HAL_TIMEOUT;
        }
      }
    }
  }

  switch (EventType)
  {
    /* End Of Sampling event */
    case ADC_EOSMP_EVENT:
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOSMP);

      /* Clear the End Of Sampling flag */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOSMP);

      break;

    /* Analog watchdog (level out of window) event */
    /* Note: In case of several analog watchdog enabled, if needed to know      */
    /* which one triggered and on which ADCx, test ADC state of analog watchdog */
    /* flags HAL_ADC_STATE_AWD1/2/3 using function "HAL_ADC_GetState()".        */
    /* For example:                                                             */
    /*  " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_AWD1) != 0UL) "          */
    /*  " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_AWD2) != 0UL) "          */
    /*  " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_AWD3) != 0UL) "          */

    /* Check analog watchdog 1 flag */
    case ADC_AWD_EVENT:
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);

      /* Clear ADC analog watchdog flag */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD1);

      break;

    /* Check analog watchdog 2 flag */
    case ADC_AWD2_EVENT:
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_AWD2);

      /* Clear ADC analog watchdog flag */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD2);

      break;

    /* Check analog watchdog 3 flag */
    case ADC_AWD3_EVENT:
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_AWD3);

      /* Clear ADC analog watchdog flag */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD3);

      break;

    default: 
      break;
  }

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Enable ADC, start conversion of regular group with interruption.
  * @note   Interruptions enabled in this function according to initialization
  *         setting : EOC (end of conversion), EOS (end of sequence)
  *         Each of these interruptions has its dedicated callback function.
  * @note   Case of multimode enabled (when multimode feature is available):
  *         HAL_ADC_Start_IT() must be called for ADC Slave first, then for
  *         ADC Master.
  *         For ADC Slave, ADC is enabled only (conversion is not started).
  *         For ADC Master, ADC is enabled and multimode conversion is started.
  * @note   To guarantee a proper reset of all interruptions once all the needed
  *         conversions are obtained, HAL_ADC_Stop_IT() must be called to ensure
  *         a correct stop of the IT-based conversions.
  * @note   By default, HAL_ADC_Start_IT() does not enable the End Of Sampling
  *         interruption. If required (e.g. in case of oversampling with trigger
  *         mode), the user must:
  *          1. first clear the EOSMP flag if set with macro __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOSMP)
  *          2. then enable the EOSMP interrupt with macro __HAL_ADC_ENABLE_IT(hadc, ADC_IT_EOSMP)
  *          before calling HAL_ADC_Start_IT().
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status;
#if defined(ADC_MULTIMODE_SUPPORT)
  const ADC_TypeDef *tmpADC_Master;
  uint32_t tmp_multimode_config = LL_ADC_GetMultimode(__LL_ADC_COMMON_INSTANCE(hadc->Instance));
#endif /* ADC_MULTIMODE_SUPPORT */

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Perform ADC enable and conversion start if no conversion is on going */
  if (LL_ADC_REG_IsConversionOngoing(hadc->Instance) == 0UL)
  {
    /* Process locked */
    __HAL_LOCK(hadc);

    /* Enable the ADC peripheral */
    tmp_hal_status = ADC_Enable(hadc);

    /* Start conversion if ADC is effectively enabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state                                                        */
      /* - Clear state bitfield related to regular group conversion results   */
      /* - Set state bitfield related to regular operation                    */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_EOSMP,
                        HAL_ADC_STATE_REG_BUSY);

#if defined(ADC_MULTIMODE_SUPPORT)
      /* Reset HAL_ADC_STATE_MULTIMODE_SLAVE bit
        - if ADC instance is master or if multimode feature is not available
        - if multimode setting is disabled (ADC instance slave in independent mode) */
      if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
          || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
         )
      {
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      }
#endif /* ADC_MULTIMODE_SUPPORT */

      /* Set ADC error code */
      /* Check if a conversion is on going on ADC group injected */
      if ((hadc->State & HAL_ADC_STATE_INJ_BUSY) != 0UL)
      {
        /* Reset ADC error code fields related to regular conversions only */
        CLEAR_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);
      }
      else
      {
        /* Reset all ADC error code fields */
        ADC_CLEAR_ERRORCODE(hadc);
      }

      /* Clear ADC group regular conversion flag */
      /* (To ensure of no unknown state from potential previous ADC operations) */
      __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_EOC | ADC_FLAG_EOS));

      /* Process unlocked */
      /* Unlock before starting ADC conversions: in case of potential         */
      /* interruption, to let the process to ADC IRQ Handler.                 */
      __HAL_UNLOCK(hadc);

      /* Disable all interruptions before enabling the desired ones */
      __HAL_ADC_DISABLE_IT(hadc, (ADC_IT_EOC | ADC_IT_EOS));

      /* Enable ADC end of conversion interrupt */
      switch (hadc->Init.EOCSelection)
      {
        case ADC_EOC_SEQ_CONV:
          __HAL_ADC_ENABLE_IT(hadc, ADC_IT_EOS);
          break;
        /* case ADC_EOC_SINGLE_CONV */
        default:
          __HAL_ADC_ENABLE_IT(hadc, ADC_IT_EOC);
          break;
      }

      /* Enable conversion of regular group.                                  */
      /* If software start has been selected, conversion starts immediately.  */
      /* If external trigger has been selected, conversion will start at next */
      /* trigger event.                                                       */
      /* Case of multimode enabled (when multimode feature is available):     */
      /*  - if ADC is slave and dual regular conversions are enabled, ADC is  */
      /*    enabled only (conversion is not started),                         */
      /*  - if ADC is master, ADC is enabled and conversion is started.       */
#if defined(ADC_MULTIMODE_SUPPORT)
      if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
          || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
          || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_SIMULT)
          || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_ALTERN)
         )
      {
        /* ADC instance is not a multimode slave instance with multimode regular conversions enabled */
        if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_JAUTO) != 0UL)
        {
          ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);

          /* Enable as well injected interruptions in case
           HAL_ADCEx_InjectedStart_IT() has not been called beforehand. This
           allows to start regular and injected conversions when JAUTO is
           set with a single call to HAL_ADC_Start_IT() */
          switch (hadc->Init.EOCSelection)
          {
            case ADC_EOC_SEQ_CONV:
              __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
              __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOS);
              break;
            /* case ADC_EOC_SINGLE_CONV */
            default:
              __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOS);
              __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOC);
              break;
          }
        }

        /* Start ADC group regular conversion */
        LL_ADC_REG_StartConversion(hadc->Instance);
      }
      else
      {
        /* ADC instance is a multimode slave instance with multimode regular conversions enabled */
        SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
        /* if Master ADC JAUTO bit is set, Slave injected interruptions
           are enabled nevertheless (for same reason as above) */
        tmpADC_Master = __LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance);
        if (READ_BIT(tmpADC_Master->CFGR, ADC_CFGR_JAUTO) != 0UL)
        {
          /* First, update Slave State in setting HAL_ADC_STATE_INJ_BUSY bit
             and in resetting HAL_ADC_STATE_INJ_EOC bit */
          ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
          /* Next, set Slave injected interruptions */
          switch (hadc->Init.EOCSelection)
          {
            case ADC_EOC_SEQ_CONV:
              __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
              __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOS);
              break;
            /* case ADC_EOC_SINGLE_CONV */
            default:
              __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOS);
              __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOC);
              break;
          }
        }
      }
#else
      /* ADC instance is not a multimode slave instance with multimode regular conversions enabled */
      if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_JAUTO) != 0UL)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);

        /* Enable as well injected interruptions in case
         HAL_ADCEx_InjectedStart_IT() has not been called beforehand. This
         allows to start regular and injected conversions when JAUTO is
         set with a single call to HAL_ADC_Start_IT() */
        switch (hadc->Init.EOCSelection)
        {
          case ADC_EOC_SEQ_CONV:
            __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
            __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOS);
            break;
          /* case ADC_EOC_SINGLE_CONV */
          default:
            __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOS);
            __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOC);
            break;
        }
      }

      /* Start ADC group regular conversion */
      LL_ADC_REG_StartConversion(hadc->Instance);
#endif /* ADC_MULTIMODE_SUPPORT */
    }
    else
    {
      /* Process unlocked */
      __HAL_UNLOCK(hadc);
    }

  }
  else
  {
    tmp_hal_status = HAL_BUSY;
  }

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected group in
  *         case of auto_injection mode), disable interrution of
  *         end-of-conversion, disable ADC peripheral.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Process locked */
  __HAL_LOCK(hadc);

  /* 1. Stop potential conversion on going */
  tmp_hal_status = ADC_ConversionStop(hadc);

  /* Disable ADC peripheral if conversions are effectively stopped */
  if (tmp_hal_status == HAL_OK)
  {
    /* Disable ADC end of conversion interrupt for regular group */
    __HAL_ADC_DISABLE_IT(hadc, (ADC_IT_EOC | ADC_IT_EOS));

    /* 2. Disable the ADC peripheral */
    tmp_hal_status = ADC_Disable(hadc);

    /* Check if ADC is effectively disabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }

  /* Process unlocked */
  __HAL_UNLOCK(hadc);

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Enable ADC, start conversion of regular group and transfer result through DMA.
  * @note   Interruptions enabled in this function:
  *         DMA half block transfer, DMA transfer complete.
  *         Each of these interruptions has its dedicated callback function.
  * @note   Case of multimode enabled (when multimode feature is available): HAL_ADC_Start_DMA()
  *         is designed for single-ADC mode only. For multimode, the dedicated
  *         HAL_ADCEx_MultiModeStart_DMA() function must be used.
  * @param hadc ADC handle
  * @param pData Destination Buffer address.
  * @param Length Number of data to be transferred from ADC peripheral to memory
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status;
#if defined(ADC_MULTIMODE_SUPPORT)
  uint32_t tmp_multimode_config = LL_ADC_GetMultimode(__LL_ADC_COMMON_INSTANCE(hadc->Instance));
#endif /* ADC_MULTIMODE_SUPPORT */

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Perform ADC enable and conversion start if no conversion is on going */
  if (LL_ADC_REG_IsConversionOngoing(hadc->Instance) == 0UL)
  {
    /* Process locked */
    __HAL_LOCK(hadc);

#if defined(ADC_MULTIMODE_SUPPORT)
    /* Ensure that multimode regular conversions are not enabled.   */
    /* Otherwise, dedicated API HAL_ADCEx_MultiModeStart_DMA() must be used.  */
    if ((ADC_IS_INDEPENDENT(hadc) != RESET)
        || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_SIMULT)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_ALTERN)
       )
#endif /* ADC_MULTIMODE_SUPPORT */
    {
      /* Enable the ADC peripheral */
      tmp_hal_status = ADC_Enable(hadc);

      /* Start conversion if ADC is effectively enabled */
      if (tmp_hal_status == HAL_OK)
      {
        /* Set ADC state                                                        */
        /* - Clear state bitfield related to regular group conversion results   */
        /* - Set state bitfield related to regular operation                    */
        ADC_STATE_CLR_SET(hadc->State,
                          HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_EOSMP,
                          HAL_ADC_STATE_REG_BUSY);

#if defined(ADC_MULTIMODE_SUPPORT)
        /* Reset HAL_ADC_STATE_MULTIMODE_SLAVE bit
          - if ADC instance is master or if multimode feature is not available
          - if multimode setting is disabled (ADC instance slave in independent mode) */
        if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
            || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
           )
        {
          CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
        }
#endif /* ADC_MULTIMODE_SUPPORT */

        /* Check if a conversion is on going on ADC group injected */
        if ((hadc->State & HAL_ADC_STATE_INJ_BUSY) != 0UL)
        {
          /* Reset ADC error code fields related to regular conversions only */
          CLEAR_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);
        }
        else
        {
          /* Reset all ADC error code fields */
          ADC_CLEAR_ERRORCODE(hadc);
        }

        /* Set the DMA transfer complete callback */
        hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;

        /* Set the DMA half block transfer complete callback */
        hadc->DMA_Handle->XferHalfBlockCpltCallback = ADC_DMAHalfBlockConvCplt;

        /* Set the DMA error callback */
        hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;


        /* Manage ADC and DMA start: start,     */
        /* ADC start (in case of SW start):                                   */

        /* Clear regular group conversion flag */
        /* (To ensure of no unknown state from potential previous ADC         */
        /* operations)                                                        */
        __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_EOC | ADC_FLAG_EOS));

        /* Process unlocked */
        /* Unlock before starting ADC conversions: in case of potential         */
        /* interruption, to let the process to ADC IRQ Handler.                 */
        __HAL_UNLOCK(hadc);

        /* Enable ADC DMA mode */
        SET_BIT(hadc->Instance->CFGR, ADC_CFGR_DMAEN);

        /* Start the DMA channel */
        tmp_hal_status = HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);

        /* Enable conversion of regular group.                                  */
        /* If software start has been selected, conversion starts immediately.  */
        /* If external trigger has been selected, conversion will start at next */
        /* trigger event.                                                       */
        /* Start ADC group regular conversion */
        LL_ADC_REG_StartConversion(hadc->Instance);
      }
      else
      {
        /* Process unlocked */
        __HAL_UNLOCK(hadc);
      }

    }
#if defined(ADC_MULTIMODE_SUPPORT)
    else
    {
      tmp_hal_status = HAL_ERROR;
      /* Process unlocked */
      __HAL_UNLOCK(hadc);
    }
#endif /* ADC_MULTIMODE_SUPPORT */
  }
  else
  {
    tmp_hal_status = HAL_BUSY;
  }

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected group in
  *         case of auto_injection mode), disable ADC DMA transfer, disable
  *         ADC peripheral.
  * @note:  ADC peripheral disable is forcing stop of potential
  *         conversion on ADC group injected. If ADC group injected is under use, it
  *         should be preliminarily stopped using HAL_ADCEx_InjectedStop function.
  * @note   Case of multimode enabled (when multimode feature is available):
  *         HAL_ADC_Stop_DMA() function is dedicated to single-ADC mode only.
  *         For multimode, the dedicated HAL_ADCEx_MultiModeStop_DMA() API must be used.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Process locked */
  __HAL_LOCK(hadc);

  /* 1. Stop potential ADC conversion on going */
  tmp_hal_status = ADC_ConversionStop(hadc);

  /* Disable ADC peripheral if conversions are effectively stopped */
  if (tmp_hal_status == HAL_OK)
  {
    /* Disable the DMA channel (in case of DMA in circular mode or stop       */
    /* while DMA transfer is on going)                                        */
    if (hadc->DMA_Handle->State == HAL_DMA_STATE_BUSY)
    {
      tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);

      /* Check if DMA channel effectively disabled */
      if (tmp_hal_status != HAL_OK)
      {
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
      }
    }

    /* Disable ADC DMA (ADC DMA configuration of continuous requests is kept) */
    CLEAR_BIT(hadc->Instance->CFGR, ADC_CFGR_DMAEN);

    /* 2. Disable the ADC peripheral */
    /* Update "tmp_hal_status" only if DMA channel disabling passed,          */
    /* to keep in memory a potential failing status.                          */
    if (tmp_hal_status == HAL_OK)
    {
      tmp_hal_status = ADC_Disable(hadc);
    }
    else
    {
      (void)ADC_Disable(hadc);
    }

    /* Check if ADC is effectively disabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }

  }

  /* Process unlocked */
  __HAL_UNLOCK(hadc);

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Get ADC regular group conversion result.
  * @note   Reading register DR automatically clears ADC flag EOC
  *         (ADC group regular end of unitary conversion).
  * @note   This function does not clear ADC flag EOS
  *         (ADC group regular end of sequence conversion).
  *         Occurrence of flag EOS rising:
  *          - If sequencer is composed of 1 rank, flag EOS is equivalent
  *            to flag EOC.
  *          - If sequencer is composed of several ranks, during the scan
  *            sequence flag EOC only is raised, at the end of the scan sequence
  *            both flags EOC and EOS are raised.
  *         To clear this flag, either use function:
  *         in programming model IT: @ref HAL_ADC_IRQHandler(), in programming
  *         model polling: @ref HAL_ADC_PollForConversion()
  *         or @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOS).
  * @param hadc ADC handle
  * @retval ADC group regular conversion data
  */
uint32_t HAL_ADC_GetValue(const ADC_HandleTypeDef *hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Note: EOC flag is not cleared here by software because automatically     */
  /*       cleared by hardware when reading register DR.                      */

  /* Return ADC converted value */
  return hadc->Instance->DR;
}

/**
  * @brief  Handle ADC interrupt request.
  * @param hadc ADC handle
  * @retval None
  */
void HAL_ADC_IRQHandler(ADC_HandleTypeDef *hadc)
{
  uint32_t tmp_isr = hadc->Instance->ISR;
  uint32_t tmp_ier = hadc->Instance->IER;
  uint32_t tmp_adc_inj_is_trigger_source_sw_start;
  uint32_t tmp_adc_reg_is_trigger_source_sw_start;
  uint32_t tmp_cfgr;
#if defined(ADC_MULTIMODE_SUPPORT)
  const ADC_TypeDef *tmpADC_Master;
  uint32_t tmp_multimode_config = LL_ADC_GetMultimode(__LL_ADC_COMMON_INSTANCE(hadc->Instance));
#endif /* ADC_MULTIMODE_SUPPORT */

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_EOC_SELECTION(hadc->Init.EOCSelection));

  /* ========== Check End of Sampling flag for ADC group regular ========== */
  if (((tmp_isr & ADC_FLAG_EOSMP) == ADC_FLAG_EOSMP) && ((tmp_ier & ADC_IT_EOSMP) == ADC_IT_EOSMP))
  {
    /* Update state machine on end of sampling status if not in error state */
    if ((hadc->State & HAL_ADC_STATE_ERROR_INTERNAL) == 0UL)
    {
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOSMP);
    }

    /* End Of Sampling callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->EndOfSamplingCallback(hadc);
#else
    HAL_ADCEx_EndOfSamplingCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Clear regular group conversion flag */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOSMP);
  }

  /* ====== Check ADC group regular end of unitary conversion sequence conversions ===== */
  if ((((tmp_isr & ADC_FLAG_EOC) == ADC_FLAG_EOC) && ((tmp_ier & ADC_IT_EOC) == ADC_IT_EOC)) ||
      (((tmp_isr & ADC_FLAG_EOS) == ADC_FLAG_EOS) && ((tmp_ier & ADC_IT_EOS) == ADC_IT_EOS)))
  {
    /* Update state machine on conversion status if not in error state */
    if ((hadc->State & HAL_ADC_STATE_ERROR_INTERNAL) == 0UL)
    {
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
    }

    /* Determine whether any further conversion upcoming on group regular     */
    /* by external trigger, continuous mode or scan sequence on going         */
    /* to disable interruption.                                               */
    if (LL_ADC_REG_IsTriggerSourceSWStart(hadc->Instance) != 0UL)
    {
      /* Get relevant register CFGR in ADC instance of ADC master or slave    */
      /* in function of multimode state (for devices with multimode           */
      /* available).                                                          */
#if defined(ADC_MULTIMODE_SUPPORT)
      if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
          || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
          || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_SIMULT)
          || (tmp_multimode_config == LL_ADC_MULTI_DUAL_INJ_ALTERN)
         )
      {
        /* check CONT bit directly in handle ADC CFGR register */
        tmp_cfgr = READ_REG(hadc->Instance->CFGR);
      }
      else
      {
        /* else need to check Master ADC CONT bit */
        tmpADC_Master = __LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance);
        tmp_cfgr = READ_REG(tmpADC_Master->CFGR);
      }
#else
      tmp_cfgr = READ_REG(hadc->Instance->CFGR);
#endif /* ADC_MULTIMODE_SUPPORT */

      /* Carry on if continuous mode is disabled */
      if (READ_BIT(tmp_cfgr, ADC_CFGR_CONT) != ADC_CFGR_CONT)
      {
        /* If End of Sequence is reached, disable interrupts */
        if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOS))
        {
          /* Allowed to modify bits ADC_IT_EOC/ADC_IT_EOS only if bit         */
          /* ADSTART==0 (no conversion on going)                              */
          if (LL_ADC_REG_IsConversionOngoing(hadc->Instance) == 0UL)
          {
            /* Disable ADC end of sequence conversion interrupt */
            __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC | ADC_IT_EOS);

            /* Set ADC state */
            CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);

            if ((hadc->State & HAL_ADC_STATE_INJ_BUSY) == 0UL)
            {
              SET_BIT(hadc->State, HAL_ADC_STATE_READY);
            }
          }
          else
          {
            /* Change ADC state to error state */
            SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

            /* Set ADC error code to ADC peripheral internal error */
            SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
          }
        }
      }
    }

    /* Conversion complete callback */
    /* Note: Into callback function "HAL_ADC_ConvCpltCallback()",             */
    /*       to determine if conversion has been triggered from EOC or EOS,   */
    /*       possibility to use:                                              */
    /*        " if ( __HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_EOS)) "               */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvCpltCallback(hadc);
#else
    HAL_ADC_ConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Clear regular group conversion flag */
    __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_EOC | ADC_FLAG_EOS));
  }

  /* ====== Check ADC group injected end of unitary conversion sequence conversions ===== */
  if ((((tmp_isr & ADC_FLAG_JEOC) == ADC_FLAG_JEOC) && ((tmp_ier & ADC_IT_JEOC) == ADC_IT_JEOC)) ||
      (((tmp_isr & ADC_FLAG_JEOS) == ADC_FLAG_JEOS) && ((tmp_ier & ADC_IT_JEOS) == ADC_IT_JEOS)))
  {
    /* Update state machine on conversion status if not in error state */
    if ((hadc->State & HAL_ADC_STATE_ERROR_INTERNAL) == 0UL)
    {
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_INJ_EOC);
    }

    /* Retrieve ADC configuration */
    tmp_adc_inj_is_trigger_source_sw_start = LL_ADC_INJ_IsTriggerSourceSWStart(hadc->Instance);
    tmp_adc_reg_is_trigger_source_sw_start = LL_ADC_REG_IsTriggerSourceSWStart(hadc->Instance);
    /* Get relevant register CFGR in ADC instance of ADC master or slave  */
    /* in function of multimode state (for devices with multimode         */
    /* available).                                                        */
#if defined(ADC_MULTIMODE_SUPPORT)
    if ((__LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance) == hadc->Instance)
        || (tmp_multimode_config == LL_ADC_MULTI_INDEPENDENT)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_REG_SIMULT)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_REG_SLOWINTERL)
        || (tmp_multimode_config == LL_ADC_MULTI_DUAL_REG_FASTINTERL)
       )
    {
      tmp_cfgr = READ_REG(hadc->Instance->CFGR);
    }
    else
    {
      tmpADC_Master = __LL_ADC_MULTI_INSTANCE_MASTER(hadc->Instance);
      tmp_cfgr = READ_REG(tmpADC_Master->CFGR);
    }
#else
    tmp_cfgr = READ_REG(hadc->Instance->CFGR);
#endif /* ADC_MULTIMODE_SUPPORT */

    /* Disable interruption if no further conversion upcoming by injected     */
    /* external trigger or by automatic injected conversion with regular      */
    /* group having no further conversion upcoming (same conditions as        */
    /* regular group interruption disabling above),                           */
    /* and if injected scan sequence is completed.                            */
    if (tmp_adc_inj_is_trigger_source_sw_start != 0UL)
    {
      if ((READ_BIT(tmp_cfgr, ADC_CFGR_JAUTO) == 0UL) ||
          ((tmp_adc_reg_is_trigger_source_sw_start != 0UL) &&
           (READ_BIT(tmp_cfgr, ADC_CFGR_CONT) == 0UL)))
      {
        /* If End of Sequence is reached, disable interrupts */
        if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_JEOS))
        {
          /* Allowed to modify bits ADC_IT_JEOC/ADC_IT_JEOS only if bit       */
          /* JADSTART==0 (no conversion on going)                             */
          if (LL_ADC_INJ_IsConversionOngoing(hadc->Instance) == 0UL)
          {
            /* Disable ADC end of sequence conversion interrupt  */
            __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC | ADC_IT_JEOS);

            /* Set ADC state */
            CLEAR_BIT(hadc->State, HAL_ADC_STATE_INJ_BUSY);

            if ((hadc->State & HAL_ADC_STATE_REG_BUSY) == 0UL)
            {
              SET_BIT(hadc->State, HAL_ADC_STATE_READY);
            }
          }
          else
          {
            /* Update ADC state machine to error */
            SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

            /* Set ADC error code to ADC peripheral internal error */
            SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
          }
        }
      }
    }

    /* Injected Conversion complete callback */
    /* Note:  HAL_ADCEx_InjectedConvCpltCallback can resort to
              if (__HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_JEOS)) or
              if (__HAL_ADC_GET_FLAG(&hadc, ADC_FLAG_JEOC)) to determine whether
              interruption has been triggered by end of conversion or end of
              sequence.    */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->InjectedConvCpltCallback(hadc);
#else
    HAL_ADCEx_InjectedConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Clear injected group conversion flag */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JEOC | ADC_FLAG_JEOS);
  }

  /* ========== Check Analog watchdog 1 flag ========== */
  if (((tmp_isr & ADC_FLAG_AWD1) == ADC_FLAG_AWD1) && ((tmp_ier & ADC_IT_AWD1) == ADC_IT_AWD1))
  {
    /* Set ADC state */
    SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);

    /* Level out of window 1 callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->LevelOutOfWindowCallback(hadc);
#else
    HAL_ADC_LevelOutOfWindowCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Clear ADC analog watchdog flag */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD1);
  }

  /* ========== Check analog watchdog 2 flag ========== */
  if (((tmp_isr & ADC_FLAG_AWD2) == ADC_FLAG_AWD2) && ((tmp_ier & ADC_IT_AWD2) == ADC_IT_AWD2))
  {
    /* Set ADC state */
    SET_BIT(hadc->State, HAL_ADC_STATE_AWD2);

    /* Level out of window 2 callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->LevelOutOfWindow2Callback(hadc);
#else
    HAL_ADCEx_LevelOutOfWindow2Callback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Clear ADC analog watchdog flag */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD2);
  }

  /* ========== Check analog watchdog 3 flag ========== */
  if (((tmp_isr & ADC_FLAG_AWD3) == ADC_FLAG_AWD3) && ((tmp_ier & ADC_IT_AWD3) == ADC_IT_AWD3))
  {
    /* Set ADC state */
    SET_BIT(hadc->State, HAL_ADC_STATE_AWD3);

    /* Level out of window 3 callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->LevelOutOfWindow3Callback(hadc);
#else
    HAL_ADCEx_LevelOutOfWindow3Callback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Clear ADC analog watchdog flag */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD3);
  }

}

/**
  * @brief  Conversion complete callback in non-blocking mode.
  * @param hadc ADC handle
  * @retval None
  */
__weak void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvCpltCallback must be implemented in the user file.
   */
}

/**
  * @brief  Conversion DMA halfblock-transfer callback in non-blocking mode.
  * @param hadc ADC handle
  * @retval None
  */
__weak void HAL_ADC_ConvHalfBlockCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvHalfBlockCpltCallback must be implemented in the user file.
  */
}

/**
  * @brief  Analog watchdog 1 callback in non-blocking mode.
  * @param hadc ADC handle
  * @retval None
  */
__weak void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_LevelOutOfWindowCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC error callback in non-blocking mode
  *         (ADC conversion with interruption or transfer by DMA).
  * @param hadc ADC handle
  * @retval None
  */
__weak void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ErrorCallback must be implemented in the user file.
  */
}

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group3 Peripheral Control functions
  * @brief    Peripheral Control functions
  *
@verbatim
 ===============================================================================
             ##### Peripheral Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Configure channels on regular group
      (+) Configure the analog watchdog

@endverbatim
  * @{
  */

/**
  * @brief  Configure a channel to be assigned to ADC group regular.
  * @note   In case of usage of internal measurement channels:
  *         Vbat/VrefInt/TempSensor.
  *         These internal paths can be disabled using function
  *         HAL_ADC_DeInit().
  * @note   Possibility to update parameters on the fly:
  *         This function initializes channel into ADC group regular,
  *         following calls to this function can be used to reconfigure
  *         some parameters of structure "ADC_ChannelConfTypeDef" on the fly,
  *         without resetting the ADC.
  *         The setting of these parameters is conditioned to ADC state:
  *         Refer to comments of structure "ADC_ChannelConfTypeDef".
  * @param hadc ADC handle
  * @param pConfig Structure of ADC channel assigned to ADC group regular.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef *hadc, const ADC_ChannelConfTypeDef *pConfig)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  uint32_t tmpOffsetShifted;
  uint32_t tmp_config_internal_channel;
  __IO uint32_t wait_loop_index = 0UL;
  uint32_t tmp_adc_is_conversion_on_going_regular;
  uint32_t tmp_adc_is_conversion_on_going_injected;
  FlagStatus adcclkchanged = RESET;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_REGULAR_RANK(pConfig->Rank));
  assert_param(IS_ADC_SAMPLE_TIME(pConfig->SamplingTime));
  assert_param(IS_ADC_SINGLE_DIFFERENTIAL(pConfig->SingleDiff));
  assert_param(IS_ADC_OFFSET_NUMBER(pConfig->OffsetNumber));
  assert_param(IS_ADC_RANGE(ADC_GET_RESOLUTION(hadc), pConfig->Offset));

  /* if ROVSE is set, the value of the OFFSETy_EN bit in ADCx_OFRy register is
     ignored (considered as reset) */
  assert_param(!((pConfig->OffsetNumber != ADC_OFFSET_NONE) && (hadc->Init.OversamplingMode == ENABLE)));

  /* Verification of channel number */
  if (pConfig->SingleDiff != ADC_DIFFERENTIAL_ENDED)
  {
    assert_param(IS_ADC_CHANNEL(hadc, pConfig->Channel));
  }
  else
  {
    assert_param(IS_ADC_DIFF_CHANNEL(hadc, pConfig->Channel));
  }

  /* Process locked */
  __HAL_LOCK(hadc);

  /* Parameters update conditioned to ADC state:                              */
  /* Parameters that can be updated when ADC is disabled or enabled without   */
  /* conversion on going on regular group:                                    */
  /*  - Channel number                                                        */
  /*  - Channel rank                                                          */
  if (LL_ADC_REG_IsConversionOngoing(hadc->Instance) == 0UL)
  {
    /* Set ADC group regular sequence: channel on the selected scan sequence rank */
    LL_ADC_REG_SetSequencerRanks(hadc->Instance, pConfig->Rank, pConfig->Channel);

    /* Parameters update conditioned to ADC state:                              */
    /* Parameters that can be updated when ADC is disabled or enabled without   */
    /* conversion on going on regular group:                                    */
    /*  - Channel sampling time                                                 */
    /*  - Channel offset                                                        */
    tmp_adc_is_conversion_on_going_regular = LL_ADC_REG_IsConversionOngoing(hadc->Instance);
    tmp_adc_is_conversion_on_going_injected = LL_ADC_INJ_IsConversionOngoing(hadc->Instance);
    if ((tmp_adc_is_conversion_on_going_regular == 0UL)
        && (tmp_adc_is_conversion_on_going_injected == 0UL)
       )
    {
      /* Manage specific case of sampling time 3.5 cycles replacing 2.5 cyles */
      if (pConfig->SamplingTime == ADC_SAMPLETIME_3CYCLES_5)
      {
        /* Set sampling time of the selected ADC channel */
        LL_ADC_SetChannelSamplingTime(hadc->Instance, pConfig->Channel, LL_ADC_SAMPLINGTIME_2CYCLES_5);

        /* Set ADC sampling time common configuration */
        LL_ADC_SetSamplingTimeCommonConfig(hadc->Instance, LL_ADC_SAMPLINGTIME_COMMON_3C5_REPL_2C5);
      }
      else
      {
        /* Set sampling time of the selected ADC channel */
        LL_ADC_SetChannelSamplingTime(hadc->Instance, pConfig->Channel, pConfig->SamplingTime);

        /* Set ADC sampling time common configuration */
        LL_ADC_SetSamplingTimeCommonConfig(hadc->Instance, LL_ADC_SAMPLINGTIME_COMMON_DEFAULT);
      }

      /* Configure the offset: offset enable/disable, channel, offset value */

      /* Shift the offset with respect to the selected ADC resolution. */
      /* Offset has to be left-aligned on bit 11, the LSB (right bits) are set to 0 */
      tmpOffsetShifted = ADC_OFFSET_SHIFT_RESOLUTION(hadc, (uint32_t)pConfig->Offset);

      if (pConfig->OffsetNumber != ADC_OFFSET_NONE)
      {
        /* Set ADC selected offset number */
        LL_ADC_SetOffset(hadc->Instance, pConfig->OffsetNumber, pConfig->Channel, tmpOffsetShifted);

        assert_param(IS_ADC_OFFSET_SIGN(pConfig->OffsetSign));
        assert_param(IS_FUNCTIONAL_STATE(pConfig->OffsetSaturation));
        /* Set ADC selected offset sign & saturation */
        LL_ADC_SetOffsetSign(hadc->Instance, pConfig->OffsetSign);
        LL_ADC_SetOffsetSaturation(hadc->Instance, 
                                   (pConfig->OffsetSaturation == ENABLE) ?
                                   LL_ADC_OFFSET_SATURATION_ENABLE : LL_ADC_OFFSET_SATURATION_DISABLE);
      }
      else
      {
        /* Scan each offset register to check if the selected channel is targeted. */
        /* If this is the case, the corresponding offset number is disabled.       */
        if (__LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_GetOffsetChannel(hadc->Instance, LL_ADC_OFFSET_1))
            == __LL_ADC_CHANNEL_TO_DECIMAL_NB(pConfig->Channel))
        {
          LL_ADC_SetOffsetState(hadc->Instance, LL_ADC_OFFSET_1, LL_ADC_OFFSET_DISABLE);
        }
        if (__LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_GetOffsetChannel(hadc->Instance, LL_ADC_OFFSET_2))
            == __LL_ADC_CHANNEL_TO_DECIMAL_NB(pConfig->Channel))
        {
          LL_ADC_SetOffsetState(hadc->Instance, LL_ADC_OFFSET_2, LL_ADC_OFFSET_DISABLE);
        }
        if (__LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_GetOffsetChannel(hadc->Instance, LL_ADC_OFFSET_3))
            == __LL_ADC_CHANNEL_TO_DECIMAL_NB(pConfig->Channel))
        {
          LL_ADC_SetOffsetState(hadc->Instance, LL_ADC_OFFSET_3, LL_ADC_OFFSET_DISABLE);
        }
        if (__LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_GetOffsetChannel(hadc->Instance, LL_ADC_OFFSET_4))
            == __LL_ADC_CHANNEL_TO_DECIMAL_NB(pConfig->Channel))
        {
          LL_ADC_SetOffsetState(hadc->Instance, LL_ADC_OFFSET_4, LL_ADC_OFFSET_DISABLE);
        }
      }
    }

    /* Parameters update conditioned to ADC state:                              */
    /* Parameters that can be updated only when ADC is disabled:                */
    /*  - Single or differential mode                                           */
    if (LL_ADC_IsEnabled(hadc->Instance) == 0UL)
    {
      /* Set mode single-ended or differential input of the selected ADC channel */
      LL_ADC_SetChannelSingleDiff(hadc->Instance, pConfig->Channel, pConfig->SingleDiff);

      /* Configuration of differential mode */
      if (pConfig->SingleDiff == ADC_DIFFERENTIAL_ENDED)
      {
        /* Set sampling time of the selected ADC channel */
        /* Note: ADC channel number masked with value "0x1F" to ensure shift value within 32 bits range */
        LL_ADC_SetChannelSamplingTime(hadc->Instance,
                                      (uint32_t)(__LL_ADC_DECIMAL_NB_TO_CHANNEL(
                                                   (__LL_ADC_CHANNEL_TO_DECIMAL_NB((uint32_t)pConfig->Channel)
                                                    + 1UL) & 0x1FUL)),
                                      pConfig->SamplingTime);
      }

    }

    /* Management of internal measurement channels: Vbat/VrefInt/TempSensor.  */
    /* If internal channel selected, enable dedicated internal buffers and    */
    /* paths.                                                                 */
    /* Note: these internal measurement paths can be disabled using           */
    /* HAL_ADC_DeInit().                                                      */

    if (__LL_ADC_IS_CHANNEL_INTERNAL(pConfig->Channel))
    {
      if (__HAL_RCC_ADC1_IS_CLK_DISABLED() != 0U)
      {
        __HAL_RCC_ADC1_CLK_ENABLE();
        adcclkchanged = SET;
      }

      tmp_config_internal_channel = LL_ADC_GetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(hadc->Instance));

      /* If the requested internal measurement path has already been enabled, */
      /* bypass the configuration processing.                                 */
      if ((pConfig->Channel == ADC_CHANNEL_TEMPSENSOR)
          && ((tmp_config_internal_channel & LL_ADC_PATH_INTERNAL_TEMPSENSOR) == 0UL))
      {
        if (ADC_TEMPERATURE_SENSOR_INSTANCE(hadc))
        {
          LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(hadc->Instance),
                                         LL_ADC_PATH_INTERNAL_TEMPSENSOR | tmp_config_internal_channel);

          /* Delay for temperature sensor stabilization time */
          /* Wait loop initialization and execution */
          /* Note: Variable divided by 2 to compensate partially              */
          /*       CPU processing cycles, scaling in us split to not          */
          /*       exceed 32 bits register capacity and handle low frequency. */
          wait_loop_index = ((LL_ADC_DELAY_TEMPSENSOR_STAB_US / 10UL) * ((SystemCoreClock / (100000UL * 2UL)) + 1UL));
          while (wait_loop_index != 0UL)
          {
            wait_loop_index--;
          }
        }
      }
      else if ((pConfig->Channel == ADC_CHANNEL_VBAT)
               && ((tmp_config_internal_channel & LL_ADC_PATH_INTERNAL_VBAT) == 0UL))
      {
        if (ADC_BATTERY_VOLTAGE_INSTANCE(hadc))
        {
          LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(hadc->Instance),
                                         LL_ADC_PATH_INTERNAL_VBAT | tmp_config_internal_channel);
        }
      }
      else if ((pConfig->Channel == ADC_CHANNEL_VREFINT)
               && ((tmp_config_internal_channel & LL_ADC_PATH_INTERNAL_VREFINT) == 0UL))
      {
        if (ADC_VREFINT_INSTANCE(hadc))
        {
          LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(hadc->Instance),
                                         LL_ADC_PATH_INTERNAL_VREFINT | tmp_config_internal_channel);
        }
      }
      else
      {
        /* nothing to do */
      }

      /* Restore clock configuration if changed */
      if (adcclkchanged == SET)
      {
        __HAL_RCC_ADC1_CLK_DISABLE();
      }
    }
  }

  /* If a conversion is on going on regular group, no update on regular       */
  /* channel could be done on neither of the channel configuration structure  */
  /* parameters.                                                              */
  else
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);

    tmp_hal_status = HAL_ERROR;
  }

  /* Process unlocked */
  __HAL_UNLOCK(hadc);

  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Configure the analog watchdog.
  * @note   Possibility to update parameters on the fly:
  *         This function initializes the selected analog watchdog, successive
  *         calls to this function can be used to reconfigure some parameters
  *         of structure "ADC_AnalogWDGConfTypeDef" on the fly, without resetting
  *         the ADC.
  *         The setting of these parameters is conditioned to ADC state.
  *         For parameters constraints, see comments of structure
  *         "ADC_AnalogWDGConfTypeDef".
  * @note   On this mcu series, analog watchdog thresholds can be modified
  *         while ADC conversion is on going.
  *         In this case, some constraints must be taken into account:
  *         the programmed threshold values are effective from the next
  *         ADC EOC (end of unitary conversion).
  *         Considering that registers write delay may happen due to
  *         bus activity, this might cause an uncertainty on the
  *         effective timing of the new programmed threshold values.
  * @param hadc ADC handle
  * @param pAnalogWDGConfig Structure of ADC analog watchdog configuration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef *hadc, const ADC_AnalogWDGConfTypeDef *pAnalogWDGConfig)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  uint32_t tmp_awd_high_threshold_shifted;
  uint32_t tmp_awd_low_threshold_shifted;
  uint32_t tmp_adc_is_conversion_on_going_regular;
  uint32_t tmp_adc_is_conversion_on_going_injected;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_ANALOG_WATCHDOG_NUMBER(pAnalogWDGConfig->WatchdogNumber));
  assert_param(IS_ADC_ANALOG_WATCHDOG_MODE(pAnalogWDGConfig->WatchdogMode));
  assert_param(IS_ADC_ANALOG_WATCHDOG_FILTERING_MODE(pAnalogWDGConfig->FilteringConfig));
  assert_param(IS_FUNCTIONAL_STATE(pAnalogWDGConfig->ITMode));

  if ((pAnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REG)     ||
      (pAnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_INJEC)   ||
      (pAnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC))
  {
    assert_param(IS_ADC_CHANNEL(hadc, pAnalogWDGConfig->Channel));
  }

  /* Verify thresholds range */
  if (hadc->Init.OversamplingMode == ENABLE)
  {
    /* Case of oversampling enabled: depending on ratio and shift configuration,
       analog watchdog thresholds can be higher than ADC resolution.
       Verify if thresholds are within maximum thresholds range. */
    assert_param(IS_ADC_RANGE(ADC_RESOLUTION_12B, pAnalogWDGConfig->HighThreshold));
    assert_param(IS_ADC_RANGE(ADC_RESOLUTION_12B, pAnalogWDGConfig->LowThreshold));
  }
  else
  {
    /* Verify if thresholds are within the selected ADC resolution */
    assert_param(IS_ADC_RANGE(ADC_GET_RESOLUTION(hadc), pAnalogWDGConfig->HighThreshold));
    assert_param(IS_ADC_RANGE(ADC_GET_RESOLUTION(hadc), pAnalogWDGConfig->LowThreshold));
  }

  /* Process locked */
  __HAL_LOCK(hadc);

  /* Parameters update conditioned to ADC state:                              */
  /* Parameters that can be updated when ADC is disabled or enabled without   */
  /* conversion on going on ADC groups regular and injected:                  */
  /*  - Analog watchdog channels                                              */
  tmp_adc_is_conversion_on_going_regular = LL_ADC_REG_IsConversionOngoing(hadc->Instance);
  tmp_adc_is_conversion_on_going_injected = LL_ADC_INJ_IsConversionOngoing(hadc->Instance);
  if ((tmp_adc_is_conversion_on_going_regular == 0UL)
      && (tmp_adc_is_conversion_on_going_injected == 0UL)
     )
  {
    /* Analog watchdog configuration */
    if (pAnalogWDGConfig->WatchdogNumber == ADC_ANALOGWATCHDOG_1)
    {
      /* Configuration of analog watchdog:                                    */
      /*  - Set the analog watchdog enable mode: one or overall group of      */
      /*    channels, on groups regular and-or injected.                      */
      switch (pAnalogWDGConfig->WatchdogMode)
      {
        case ADC_ANALOGWATCHDOG_SINGLE_REG:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1,
                                          __LL_ADC_ANALOGWD_CHANNEL_GROUP(pAnalogWDGConfig->Channel,
                                                                          LL_ADC_GROUP_REGULAR));
          break;

        case ADC_ANALOGWATCHDOG_SINGLE_INJEC:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1,
                                          __LL_ADC_ANALOGWD_CHANNEL_GROUP(pAnalogWDGConfig->Channel,
                                                                          LL_ADC_GROUP_INJECTED));
          break;

        case ADC_ANALOGWATCHDOG_SINGLE_REGINJEC:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1,
                                          __LL_ADC_ANALOGWD_CHANNEL_GROUP(pAnalogWDGConfig->Channel,
                                                                          LL_ADC_GROUP_REGULAR_INJECTED));
          break;

        case ADC_ANALOGWATCHDOG_ALL_REG:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1, LL_ADC_AWD_ALL_CHANNELS_REG);
          break;

        case ADC_ANALOGWATCHDOG_ALL_INJEC:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1, LL_ADC_AWD_ALL_CHANNELS_INJ);
          break;

        case ADC_ANALOGWATCHDOG_ALL_REGINJEC:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1, LL_ADC_AWD_ALL_CHANNELS_REG_INJ);
          break;

        default: /* ADC_ANALOGWATCHDOG_NONE */
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, LL_ADC_AWD1, LL_ADC_AWD_DISABLE);
          break;
      }

      /* Set the filtering configuration */
      MODIFY_REG(hadc->Instance->TR1,
                 ADC_TR1_AWDFILT,
                 pAnalogWDGConfig->FilteringConfig);

      /* Update state, clear previous result related to AWD1 */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_AWD1);

      /* Clear flag ADC analog watchdog */
      /* Note: Flag cleared Clear the ADC Analog watchdog flag to be ready  */
      /* to use for HAL_ADC_IRQHandler() or HAL_ADC_PollForEvent()          */
      /* (in case left enabled by previous ADC operations).                 */
      LL_ADC_ClearFlag_AWD1(hadc->Instance);

      /* Configure ADC analog watchdog interrupt */
      if (pAnalogWDGConfig->ITMode == ENABLE)
      {
        LL_ADC_EnableIT_AWD1(hadc->Instance);
      }
      else
      {
        LL_ADC_DisableIT_AWD1(hadc->Instance);
      }
    }
    /* Case of ADC_ANALOGWATCHDOG_2 or ADC_ANALOGWATCHDOG_3 */
    else
    {
      switch (pAnalogWDGConfig->WatchdogMode)
      {
        case ADC_ANALOGWATCHDOG_SINGLE_REG:
        case ADC_ANALOGWATCHDOG_SINGLE_INJEC:
        case ADC_ANALOGWATCHDOG_SINGLE_REGINJEC:
          /* Update AWD by bitfield to keep the possibility to monitor        */
          /* several channels by successive calls of this function.           */
          if (pAnalogWDGConfig->WatchdogNumber == ADC_ANALOGWATCHDOG_2)
          {
            SET_BIT(hadc->Instance->AWD2CR,
                    (1UL << (__LL_ADC_CHANNEL_TO_DECIMAL_NB(pAnalogWDGConfig->Channel) & 0x1FUL)));
          }
          else
          {
            SET_BIT(hadc->Instance->AWD3CR,
                    (1UL << (__LL_ADC_CHANNEL_TO_DECIMAL_NB(pAnalogWDGConfig->Channel) & 0x1FUL)));
          }
          break;

        case ADC_ANALOGWATCHDOG_ALL_REG:
        case ADC_ANALOGWATCHDOG_ALL_INJEC:
        case ADC_ANALOGWATCHDOG_ALL_REGINJEC:
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance,
                                          pAnalogWDGConfig->WatchdogNumber, LL_ADC_AWD_ALL_CHANNELS_REG_INJ);
          break;

        default: /* ADC_ANALOGWATCHDOG_NONE */
          LL_ADC_SetAnalogWDMonitChannels(hadc->Instance, pAnalogWDGConfig->WatchdogNumber, LL_ADC_AWD_DISABLE);
          break;
      }

      if (pAnalogWDGConfig->WatchdogNumber == ADC_ANALOGWATCHDOG_2)
      {
        /* Update state, clear previous result related to AWD2 */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_AWD2);

        /* Clear flag ADC analog watchdog */
        /* Note: Flag cleared Clear the ADC Analog watchdog flag to be ready  */
        /* to use for HAL_ADC_IRQHandler() or HAL_ADC_PollForEvent()          */
        /* (in case left enabled by previous ADC operations).                 */
        LL_ADC_ClearFlag_AWD2(hadc->Instance);

        /* Configure ADC analog watchdog interrupt */
        if (pAnalogWDGConfig->ITMode == ENABLE)
        {
          LL_ADC_EnableIT_AWD2(hadc->Instance);
        }
        else
        {
          LL_ADC_DisableIT_AWD2(hadc->Instance);
        }
      }
      /* (pAnalogWDGConfig->WatchdogNumber == ADC_ANALOGWATCHDOG_3) */
      else
      {
        /* Update state, clear previous result related to AWD3 */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_AWD3);

        /* Clear flag ADC analog watchdog */
        /* Note: Flag cleared Clear the ADC Analog watchdog flag to be ready  */
        /* to use for HAL_ADC_IRQHandler() or HAL_ADC_PollForEvent()          */
        /* (in case left enabled by previous ADC operations).                 */
        LL_ADC_ClearFlag_AWD3(hadc->Instance);

        /* Configure ADC analog watchdog interrupt */
        if (pAnalogWDGConfig->ITMode == ENABLE)
        {
          LL_ADC_EnableIT_AWD3(hadc->Instance);
        }
        else
        {
          LL_ADC_DisableIT_AWD3(hadc->Instance);
        }
      }
    }

  }

  /* Analog watchdog thresholds configuration */
  if (pAnalogWDGConfig->WatchdogNumber == ADC_ANALOGWATCHDOG_1)
  {
    /* Shift the offset with respect to the selected ADC resolution:        */
    /* Thresholds have to be left-aligned on bit 11, the LSB (right bits)   */
    /* are set to 0.                                                        */
    tmp_awd_high_threshold_shifted = ADC_AWD1THRESHOLD_SHIFT_RESOLUTION(hadc, pAnalogWDGConfig->HighThreshold);
    tmp_awd_low_threshold_shifted  = ADC_AWD1THRESHOLD_SHIFT_RESOLUTION(hadc, pAnalogWDGConfig->LowThreshold);
  }
  /* Case of ADC_ANALOGWATCHDOG_2 and ADC_ANALOGWATCHDOG_3 */
  else
  {
    /* Shift the offset with respect to the selected ADC resolution:        */
    /* Thresholds have to be left-aligned on bit 7, the LSB (right bits)    */
    /* are set to 0.                                                        */
    tmp_awd_high_threshold_shifted = ADC_AWD23THRESHOLD_SHIFT_RESOLUTION(hadc, pAnalogWDGConfig->HighThreshold);
    tmp_awd_low_threshold_shifted  = ADC_AWD23THRESHOLD_SHIFT_RESOLUTION(hadc, pAnalogWDGConfig->LowThreshold);
  }

  /* Set ADC analog watchdog thresholds value of both thresholds high and low */
  LL_ADC_ConfigAnalogWDThresholds(hadc->Instance, pAnalogWDGConfig->WatchdogNumber, tmp_awd_high_threshold_shifted,
                                  tmp_awd_low_threshold_shifted);

  /* Process unlocked */
  __HAL_UNLOCK(hadc);

  /* Return function status */
  return tmp_hal_status;
}


/**
  * @brief  Configures the the ADC VrefBuf
  * @param  hadc: ADC handle
  * @param  VrefBuf the ADC VrefBuf.
  *          This parameter can be one of the following values:
  *            @arg ADC_VREFBUF_VCCA
  *            @arg ADC_VREFBUF_1P08V
  *            @arg ADC_VREFBUF_2P048V
  *            @arg ADC_VREFBUF_2P5V  
  *            @arg ADC_VREFBUF_2P9V  
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ConfigVrefBuf(ADC_HandleTypeDef* hadc, uint32_t VrefBuf)
{ 
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_Common_TypeDef *tmpADC_Common;
  FlagStatus adcclkchanged = RESET;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_VREFBUF(VrefBuf));
 
  /* Process locked */
  __HAL_LOCK(hadc);
  
  if (__HAL_RCC_ADC1_IS_CLK_DISABLED() != 0U)
  {
    __HAL_RCC_ADC1_CLK_ENABLE();
    adcclkchanged = SET;
  }

  /* Pointer to the common control register */
  tmpADC_Common = __LL_ADC_COMMON_INSTANCE(hadc->Instance);

  if(VrefBuf != ADC_VREFBUF_VCCA)
  {
    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR, FLASH_KEY2);

    if (READ_BIT(FLASH->CR, FLASH_CR_LOCK) != 0U)
    {
      return HAL_ERROR;
    }

    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY1);
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY2);

    if (READ_BIT(FLASH->CR, FLASH_CR_OPTLOCK) != 0U)
    {
      return HAL_ERROR;
    }

    *(uint32_t *)0x4002228C = 0x5D7F4051;
    *(uint32_t *)0x4002228C = 0x46CE2763;

    switch (VrefBuf)
    {
      case ADC_VREFBUF_1P08V:
      *(uint32_t *)0x4002222C = ((*(uint32_t *)0x4002222C) & 0xFFFF00FF) | (((*(uint32_t *)0x1FFF76B0) << 8) & 0xFF00);
        break;

      case ADC_VREFBUF_2P048V:
      *(uint32_t *)0x4002222C = ((*(uint32_t *)0x4002222C) & 0xFFFF00FF) | (((*(uint32_t *)0x1FFF76B4) << 8) & 0xFF00);
        break;

      case ADC_VREFBUF_2P5V:
      *(uint32_t *)0x4002222C = ((*(uint32_t *)0x4002222C) & 0xFFFF00FF) | (((*(uint32_t *)0x1FFF76B8) << 8) & 0xFF00);
        break;

      default:
      *(uint32_t *)0x4002222C = ((*(uint32_t *)0x4002222C) & 0xFFFF00FF) | (((*(uint32_t *)0x1FFF76BC) << 8) & 0xFF00);
        break;
    }

    SET_BIT(FLASH->CR, FLASH_CR_LOCK);
  }

  if (__LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__LL_ADC_COMMON_INSTANCE(hadc->Instance)) == 0UL)
  {
    MODIFY_REG(tmpADC_Common->CCR, ADC_CCR_VREFSEL | ADC_CCR_VREFBUFEN | ADC_CCR_VREFBUFSEL ,VrefBuf);
  }

  /* Restore clock configuration if changed */
  if (adcclkchanged == SET)
  {
    __HAL_RCC_ADC1_CLK_DISABLE();
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group4 Peripheral State functions
  *  @brief    ADC Peripheral State functions
  *
@verbatim
 ===============================================================================
            ##### Peripheral state and errors functions #####
 ===============================================================================
    [..]
    This subsection provides functions to get in run-time the status of the
    peripheral.
      (+) Check the ADC state
      (+) Check the ADC error code

@endverbatim
  * @{
  */

/**
  * @brief  Return the ADC handle state.
  * @note   ADC state machine is managed by bitfields, ADC status must be
  *         compared with states bits.
  *         For example:
  *           " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_REG_BUSY) != 0UL) "
  *           " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_AWD1) != 0UL) "
  * @param hadc ADC handle
  * @retval ADC handle state (bitfield on 32 bits)
  */
uint32_t HAL_ADC_GetState(const ADC_HandleTypeDef *hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Return ADC handle state */
  return hadc->State;
}

/**
  * @brief  Return the ADC error code.
  * @param hadc ADC handle
  * @retval ADC error code (bitfield on 32 bits)
  */
uint32_t HAL_ADC_GetError(const ADC_HandleTypeDef *hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  return hadc->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */

/**
  * @brief  Stop ADC conversion.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef ADC_ConversionStop(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U;
  uint32_t tmp_adc_is_conversion_on_going_regular;
  uint32_t tmp_adc_is_conversion_on_going_injected;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Verification if ADC is not already stopped (on regular and injected      */
  /* groups) to bypass this function if not needed.                           */
  tmp_adc_is_conversion_on_going_regular = LL_ADC_REG_IsConversionOngoing(hadc->Instance);
  tmp_adc_is_conversion_on_going_injected = LL_ADC_INJ_IsConversionOngoing(hadc->Instance);
  if ((tmp_adc_is_conversion_on_going_regular != 0UL)
      || (tmp_adc_is_conversion_on_going_injected != 0UL)
     )
  {
    /* Stop conversions on regular group */
    hadc->Instance->CR |= ADC_CR_ADSTP;

    /* Get tick count */
    tickstart = HAL_GetTick();
        
    while(HAL_IS_BIT_SET(hadc->Instance->CR, ADC_CR_ADSTP) )
    {
      if((HAL_GetTick() - tickstart) > ADC_STOP_CONVERSION_TIMEOUT)
      {
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);
        
        /* Set ADC error code to ADC IP internal error */
        SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
          
        return HAL_ERROR;
      }
    }   
  }
   
  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  Enable the selected ADC.
  * @note   Prerequisite condition to use this function: ADC must be disabled
  *         and voltage regulator must be enabled (done into HAL_ADC_Init()).
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef *hadc)
{
  uint32_t tickstart;
  __IO uint32_t wait_loop_index = 0UL;

  /* Timeout implemented to not be stuck if ADC cannot be enabled (possible   */
  /* causes: ADC clock not running, ...).                                     */
  if (LL_ADC_IsEnabled(hadc->Instance) == 0UL)
  {
    /* Check if conditions to enable the ADC are fulfilled */
    if ((hadc->Instance->CR & (ADC_CR_ADCAL | ADC_CR_ADSTP | ADC_CR_JADSTART | ADC_CR_ADSTART | ADC_CR_RSTCAL
                                | ADC_CR_ADEN)) != 0UL)
    {
      /* Update ADC state machine to error */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

      /* Set ADC error code to ADC peripheral internal error */
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

      return HAL_ERROR;
    }

    /* Enable the ADC peripheral */
    LL_ADC_Enable(hadc->Instance);

    if ((LL_ADC_GetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(hadc->Instance))
         & LL_ADC_PATH_INTERNAL_TEMPSENSOR) != 0UL)
    {
      /* Delay for temperature sensor buffer stabilization time */
      /* Note: Value LL_ADC_DELAY_TEMPSENSOR_STAB_US used instead of      */
      /*       LL_ADC_DELAY_TEMPSENSOR_BUFFER_STAB_US because needed      */
      /*       in case of ADC enable after a system wake up               */
      /*       from low power mode.                                       */

      /* Wait loop initialization and execution */
      /* Note: Variable divided by 2 to compensate partially              */
      /*       CPU processing cycles, scaling in us split to not          */
      /*       exceed 32 bits register capacity and handle low frequency. */
      wait_loop_index = ((LL_ADC_DELAY_TEMPSENSOR_STAB_US / 10UL) * ((SystemCoreClock / (100000UL * 2UL)) + 1UL));
      while (wait_loop_index != 0UL)
      {
        wait_loop_index--;
      }
    }

    /* Wait for ADC effectively enabled */
    tickstart = HAL_GetTick();

    while (LL_ADC_IsEnabled(hadc->Instance) == 0UL)
    {
      /*  If ADEN bit is set less than 4 ADC clock cycles after the ADCAL bit
          has been cleared (after a calibration), ADEN bit is reset by the
          calibration logic.
          The workaround is to continue setting ADEN until ADEN is becomes 1.
          Additionally, ADC_ENABLE_TIMEOUT is defined to encompass this
          4 ADC clock cycle duration */
      /* Note: Test of ADC enabled required due to hardware constraint to     */
      /*       not enable ADC if already enabled.                             */
      LL_ADC_Enable(hadc->Instance);

      if ((HAL_GetTick() - tickstart) > ADC_ENABLE_TIMEOUT)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if (LL_ADC_IsEnabled(hadc->Instance) == 0UL)
        {
          /* Update ADC state machine to error */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* Set ADC error code to ADC peripheral internal error */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          return HAL_ERROR;
        }
      }
    }

    /* Delay for ADC stabilization time */
    /* Compute number of CPU cycles to wait for */
    wait_loop_index = (ADC_STAB_DELAY_US * (SystemCoreClock / 1000000U));
    while(wait_loop_index != 0U)
    {
      wait_loop_index--;
    }
  }

  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  Disable the selected ADC.
  * @note   Prerequisite condition to use this function: ADC conversions must be
  *         stopped.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef ADC_Disable(ADC_HandleTypeDef *hadc)
{
  uint32_t tickstart;

  /* Verification if ADC is not already disabled */
  if (LL_ADC_IsEnabled(hadc->Instance) != 0UL)
  {
    /* Check if conditions to disable the ADC are fulfilled */
    if ((hadc->Instance->CR & (ADC_CR_JADSTART | ADC_CR_ADSTART | ADC_CR_ADEN)) == ADC_CR_ADEN)
    {
      /* Disable the ADC peripheral */
      LL_ADC_Disable(hadc->Instance);
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOSMP);
    }
    else
    {
      /* Update ADC state machine to error */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

      /* Set ADC error code to ADC peripheral internal error */
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

      return HAL_ERROR;
    }

    /* Wait for ADC effectively disabled */
    /* Get tick count */
    tickstart = HAL_GetTick();

    while ((hadc->Instance->CR & ADC_CR_ADEN) != 0UL)
    {
      if ((HAL_GetTick() - tickstart) > ADC_DISABLE_TIMEOUT)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if ((hadc->Instance->CR & ADC_CR_ADEN) != 0UL)
        {
          /* Update ADC state machine to error */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* Set ADC error code to ADC peripheral internal error */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          return HAL_ERROR;
        }
      }
    }
  }

  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  DMA transfer complete callback.
  * @param hdma pointer to DMA handle.
  * @retval None
  */
void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  /* Update state machine on conversion status if not in error state */
  if ((hadc->State & (HAL_ADC_STATE_ERROR_INTERNAL | HAL_ADC_STATE_ERROR_DMA)) == 0UL)
  {
    /* Set ADC state */
    SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);

    /* Determine whether any further conversion upcoming on group regular     */
    /* by external trigger, continuous mode or scan sequence on going         */
    /* to disable interruption.                                               */
    /* Are conversions software-triggered ? */
    if (LL_ADC_REG_IsTriggerSourceSWStart(hadc->Instance) != 0UL)
    {
      /* Is CONT bit set ? */
      if (READ_BIT(hadc->Instance->CFGR, ADC_CFGR_CONT) == 0UL)
      {
        /* CONT bit is not set, no more conversions expected */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);
        if ((hadc->State & HAL_ADC_STATE_INJ_BUSY) == 0UL)
        {
          SET_BIT(hadc->State, HAL_ADC_STATE_READY);
        }
      }
    }

    /* Conversion complete callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvCpltCallback(hadc);
#else
    HAL_ADC_ConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }
  else /* DMA and-or internal error occurred */
  {
    if ((hadc->State & HAL_ADC_STATE_ERROR_INTERNAL) != 0UL)
    {
      /* Call HAL ADC Error Callback function */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->ErrorCallback(hadc);
#else
      HAL_ADC_ErrorCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
    }
    else
    {
      /* Call ADC DMA error callback */
      hadc->DMA_Handle->XferErrorCallback(hdma);
    }
  }
}

/**
  * @brief  DMA half block transfer complete callback.
  * @param hdma pointer to DMA handle.
  * @retval None
  */
void ADC_DMAHalfBlockConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  /* Half block conversion callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  hadc->ConvHalfBlockCpltCallback(hadc);
#else
  HAL_ADC_ConvHalfBlockCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA error callback.
  * @param hdma pointer to DMA handle.
  * @retval None
  */
void ADC_DMAError(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  /* Set ADC state */
  SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);

  /* Set ADC error code to DMA error */
  SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);

  /* Error callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  hadc->ErrorCallback(hadc);
#else
  HAL_ADC_ErrorCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @}
  */

#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

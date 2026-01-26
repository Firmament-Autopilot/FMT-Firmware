/**
  ******************************************************************************
  * @file    py32e407_ll_comp.h
  * @author  MCU Application Team
  * @brief   Header file of COMP LL module.
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
#ifndef __PY32E407_LL_COMP_H
#define __PY32E407_LL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "py32e4xx.h"

/** @addtogroup PY32E407_LL_Driver
  * @{
  */

#if defined (COMP1) || defined (COMP2) || defined(COMP3) || defined(COMP4)

/** @defgroup COMP_LL COMP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup COMP_LL_Private_Constants COMP Private Constants
  * @{
  */

/* Internal mask for pair of comparators instances window mode:               */
/* To select into literals LL_COMP_WINDOWMODE_COMPx_INPUT_PLUS_COMMON         */
/* the relevant bits for:                                                     */
/* (concatenation of multiple bits used in different registers)               */
/* - Comparator instance selected as master for window mode : register offset */
/* - Window mode enable or disable: bit value */
#define LL_COMP_WINDOWMODE_COMP_ODD_REGOFFSET_MASK  (0x00000000U) /* Register of COMP instance odd (COMP1_CSR, ...) defined as reference register */
#define LL_COMP_WINDOWMODE_COMP_EVEN_REGOFFSET_MASK (0x00000004U) /* Register of COMP instance even (COMP2_CSR, ...) offset vs register of COMP instance odd */
#define LL_COMP_WINDOWMODE_COMPX_REGOFFSET_MASK     (LL_COMP_WINDOWMODE_COMP_ODD_REGOFFSET_MASK | LL_COMP_WINDOWMODE_COMP_EVEN_REGOFFSET_MASK)
#define LL_COMP_WINDOWMODE_COMPX_SETTING_MASK       (COMP_CSR_WINMODE)
#define LL_COMP_WINDOWOUTPUT_BOTH_POS_VS_WINDOW     (1U)

/* COMP registers bits positions */
#define LL_COMP_WINDOWMODE_BITOFFSET_POS   (11U) /* Value equivalent to POSITION_VAL(COMP_CSR_WINMODE) */
#define LL_COMP_OUTPUT_LEVEL_BITOFFSET_POS (30U) /* Value equivalent to POSITION_VAL(COMP_CSR_COMP_OUT) */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup COMP_LL_Private_Macros COMP Private Macros
  * @{
  */

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  * @param  __REG__ Register basis from which the offset is applied.
  * @param  __REG_OFFFSET__ Offset to be applied (unit: number of registers).
  * @retval Pointer to register address
  */
#define __COMP_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                        \
  ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2U))))

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup COMP_LL_ES_INIT COMP Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of COMP instance.
  */
typedef struct
{
  uint32_t PowerMode;                   /*!< Set comparator operating mode to adjust power and speed.
                                             This parameter can be a value of @ref COMP_LL_EC_POWERMODE
  
                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetPowerMode(). */
  
  uint32_t InputPlus;                   /*!< Set comparator input plus (non-inverting input).
                                             This parameter can be a value of @ref COMP_LL_EC_INPUT_PLUS

                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetInputPlus(). */

  uint32_t InputMinus;                  /*!< Set comparator input minus (inverting input).
                                             This parameter can be a value of @ref COMP_LL_EC_INPUT_MINUS
   
                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetInputMinus(). */
  
  uint32_t InputHysteresis;             /*!< Set comparator hysteresis mode of the input minus.
                                             This parameter can be a value of @ref COMP_LL_EC_INPUT_HYSTERESIS

                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetInputHysteresis(). */

  uint32_t OutputPolarity;              /*!< Set comparator output polarity.
                                             This parameter can be a value of @ref COMP_LL_EC_OUTPUT_POLARITY

                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetOutputPolarity(). */

  uint32_t OutputBlankingSource;        /*!< Set comparator blanking source.
                                             This parameter can be a value of @ref COMP_LL_EC_OUTPUT_BLANKING_SOURCE

                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetOutputBlankingSource(). */

  uint32_t DigitalFilter;               /*!< Specifies the digital filter. 
                                             This parameter must be a number between 0 and 0xFFFF 

                                             The filter is prohibited,when the value is zero. 
                                             This feature can be modified afterwards using unitary function @ref LL_COMP_SetDigitalFilter(). */

} LL_COMP_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_LL_EC_COMMON_WINDOWMODE Comparator common modes - Window mode
  * @{
  */
#define LL_COMP_WINDOWMODE_DISABLE                 (0x00000000U)                                                    /*!< Window mode disable: Comparators 1 and 2 are independent */
#define LL_COMP_WINDOWMODE_COMP2_INPUT_PLUS_COMMON (COMP_CSR_WINMODE | LL_COMP_WINDOWMODE_COMP_ODD_REGOFFSET_MASK)  /*!< Window mode enable: if used from COMP1 or COMP2 instance, comparators instances pair COMP1 and COMP2 have their input plus connected together, the common input is COMP2 input plus (COMP1 input plus is no more accessible). */
#define LL_COMP_WINDOWMODE_COMP4_INPUT_PLUS_COMMON (COMP_CSR_WINMODE | LL_COMP_WINDOWMODE_COMP_ODD_REGOFFSET_MASK)  /*!< Window mode enable: if used from COMP1 or COMP2 instance, comparators instances pair COMP3 and COMP4 have their input plus connected together, the common input is COMP2 input plus (COMP1 input plus is no more accessible). */

/**
  * @}
  */

/** @defgroup COMP_LL_EC_INPUT_PLUS Comparator inputs - Input plus (input non-inverting) selection
  * @{
  */
#define LL_COMP_INPUT_PLUS_IO0  (0x00000000U)       /*!< Comparator input plus connected to IO0(pin PA1 for COMP1, pin PA3 for COMP2, pin PA0 for COMP3, pin PB0 for COMP4) */
#define LL_COMP_INPUT_PLUS_IO1  (COMP_CSR_INPSEL)   /*!< Comparator input plus connected to IO1(pin PB1 for COMP1, pin PA7 for COMP2, pin PC1 for COMP3, pin PE7 for COMP4) */

/**
  * @}
  */

/** @defgroup COMP_LL_EC_INPUT_MINUS Comparator inputs - Input minus (input inverting) selection
  * @{
  */
#define LL_COMP_INPUT_MINUS_IO0      (0x00000000U)                                               /*!< Comparator input minus connected to IO0(pin PA0 for COMP1, pin PA2 for COMP2, pin PC0 for COMP3, pin PB2 for COMP4) */
#define LL_COMP_INPUT_MINUS_IO1      (                                        COMP_CSR_INNSEL_0) /*!< Comparator input minus connected to IO1(pin PA4 for COMP1, pin PA5 for COMP2, pin PF1 for COMP3, pin PE8 for COMP4) */
#define LL_COMP_INPUT_MINUS_DAC1_CH1 (                    COMP_CSR_INNSEL_1                    ) /*!< Comparator input minus connected to IO2(DAC1_CH1 for all) */ 
#define LL_COMP_INPUT_MINUS_DAC1_CH2 (                    COMP_CSR_INNSEL_1 | COMP_CSR_INNSEL_0) /*!< Comparator input minus connected to IO3(DAC1_CH2 for all) */
#define LL_COMP_INPUT_MINUS_VREFCMP  (COMP_CSR_INNSEL_2                                        ) /*!< Comparator input minus connected to IO4(VREFCMP for all) */ 
#define LL_COMP_INPUT_MINUS_TS_VIN   (COMP_CSR_INNSEL_2                     | COMP_CSR_INNSEL_0) /*!< Comparator input minus connected to IO5(TS_VIN for all) */ 

/**
  * @}
  */
  
/** @defgroup COMP_LL_EC_VREFCMP_DIV Comparator Vrefcmp Div
  * @{
  */
#define LL_COMP_VREFCMP_DIV_1_64VREFCMP     (0x00000000U)     
#define LL_COMP_VREFCMP_DIV_2_64VREFCMP     (                                                                                               COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_3_64VREFCMP     (                                                                            COMP_CSR_VCDIV_1                   )
#define LL_COMP_VREFCMP_DIV_4_64VREFCMP     (                                                                            COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_5_64VREFCMP     (                                                         COMP_CSR_VCDIV_2                                      ) 
#define LL_COMP_VREFCMP_DIV_6_64VREFCMP     (                                                         COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_7_64VREFCMP     (                                                         COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_8_64VREFCMP     (                                                         COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_9_64VREFCMP     (                                      COMP_CSR_VCDIV_3                                                         )
#define LL_COMP_VREFCMP_DIV_10_64VREFCMP    (                                      COMP_CSR_VCDIV_3                                       | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_11_64VREFCMP    (                                      COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1                   )  
#define LL_COMP_VREFCMP_DIV_12_64VREFCMP    (                                      COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_13_64VREFCMP    (                                      COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                                      ) 
#define LL_COMP_VREFCMP_DIV_14_64VREFCMP    (                                      COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_15_64VREFCMP    (                                      COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_16_64VREFCMP    (                                      COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0)      
#define LL_COMP_VREFCMP_DIV_17_64VREFCMP    (                   COMP_CSR_VCDIV_4                                                                            ) 
#define LL_COMP_VREFCMP_DIV_18_64VREFCMP    (                   COMP_CSR_VCDIV_4                                                          | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_19_64VREFCMP    (                   COMP_CSR_VCDIV_4                                       | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_20_64VREFCMP    (                   COMP_CSR_VCDIV_4                                       | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_21_64VREFCMP    (                   COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2                                      ) 
#define LL_COMP_VREFCMP_DIV_22_64VREFCMP    (                   COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_23_64VREFCMP    (                   COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   )
#define LL_COMP_VREFCMP_DIV_24_64VREFCMP    (                   COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_25_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                                                         ) 
#define LL_COMP_VREFCMP_DIV_26_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                                       | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_27_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_28_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_29_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                                      )  
#define LL_COMP_VREFCMP_DIV_30_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0)   
#define LL_COMP_VREFCMP_DIV_31_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   )      
#define LL_COMP_VREFCMP_DIV_32_64VREFCMP    (                   COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_33_64VREFCMP    (COMP_CSR_VCDIV_5                                                                                               ) 
#define LL_COMP_VREFCMP_DIV_34_64VREFCMP    (COMP_CSR_VCDIV_5                                                                             | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_35_64VREFCMP    (COMP_CSR_VCDIV_5                                                          | COMP_CSR_VCDIV_1                   )  
#define LL_COMP_VREFCMP_DIV_36_64VREFCMP    (COMP_CSR_VCDIV_5                                                          | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_37_64VREFCMP    (COMP_CSR_VCDIV_5                                       | COMP_CSR_VCDIV_2                                      ) 
#define LL_COMP_VREFCMP_DIV_38_64VREFCMP    (COMP_CSR_VCDIV_5                                       | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_39_64VREFCMP    (COMP_CSR_VCDIV_5                                       | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_40_64VREFCMP    (COMP_CSR_VCDIV_5                                       | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_41_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3                                                         )   
#define LL_COMP_VREFCMP_DIV_42_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3                                       | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_43_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_44_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_45_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                                      )  
#define LL_COMP_VREFCMP_DIV_46_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_47_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_48_64VREFCMP    (COMP_CSR_VCDIV_5                    | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_49_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                                                                            )   
#define LL_COMP_VREFCMP_DIV_50_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                                                          | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_51_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                                       | COMP_CSR_VCDIV_1                   )     
#define LL_COMP_VREFCMP_DIV_52_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                                       | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_53_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2                                      )  
#define LL_COMP_VREFCMP_DIV_54_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_55_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_56_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4                    | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_57_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                                                         ) 
#define LL_COMP_VREFCMP_DIV_58_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                                       | COMP_CSR_VCDIV_0)  
#define LL_COMP_VREFCMP_DIV_59_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1                   ) 
#define LL_COMP_VREFCMP_DIV_60_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3                    | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0)   
#define LL_COMP_VREFCMP_DIV_61_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                                      )     
#define LL_COMP_VREFCMP_DIV_62_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2                    | COMP_CSR_VCDIV_0) 
#define LL_COMP_VREFCMP_DIV_63_64VREFCMP    (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1                   )  
#define LL_COMP_VREFCMP_DIV_VREFCMP         (COMP_CSR_VCDIV_5 | COMP_CSR_VCDIV_4 | COMP_CSR_VCDIV_3 | COMP_CSR_VCDIV_2 | COMP_CSR_VCDIV_1 | COMP_CSR_VCDIV_0) 
/**
  * @}
  */  
 
/** @defgroup COMP_LL_EC_VREFCMP_SOURCE Comparator Vrefcmp Source
  * @{
  */  
#define LL_COMP_VREFCMP_SOURCE_VCC          (COMP_CSR_VCSEL)
#define LL_COMP_VREFCMP_SOURCE_VREFINT      (0x00000000)
/**
  * @}
  */   
/** @defgroup COMP_LL_EC_VREFINT_VOLTAGE  Comparator Vrefint voltage
  * @{
  */  
#define LL_COMP_VREFINT_VOLTAGE_0P6V      (0x00000000)
#define LL_COMP_VREFINT_VOLTAGE_1P5V      (COMP_CSR_VSEL_0)
#define LL_COMP_VREFINT_VOLTAGE_2P048V    (COMP_CSR_VSEL_1)
#define LL_COMP_VREFINT_VOLTAGE_2P5V      (COMP_CSR_VSEL)
/**
  * @}
  */   

/** @defgroup COMP_LL_EC_OUTPUT_POLARITY Comparator output - Output polarity
  * @{
  */
#define LL_COMP_OUTPUTPOL_NONINVERTED       (0x00000000U)           /*!< COMP output polarity is not inverted: comparator output is high when the plus (non-inverting) input is at a higher voltage than the minus (inverting) input */
#define LL_COMP_OUTPUTPOL_INVERTED          (COMP_CSR_POLARITY)     /*!< COMP output polarity is inverted: comparator output is low when the plus (non-inverting) input is at a lower voltage than the minus (inverting) input */
/**
  * @}
  */

/** @defgroup COMP_LL_EC_OUTPUT_BLANKING_SOURCE Comparator output - Blanking source
  * @{
  */
#define LL_COMP_BLANKINGSRC_NONE             (0x00000000UL)          /*!<Comparator output without blanking */
#define LL_COMP_BLANKINGSRC_TIM1_OC5_COMP1   (                                            COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM1 OC5 (specific to COMP instance: COMP1). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM1_OC5_COMP2   (                                            COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM1 OC5 (specific to COMP instance: COMP2). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM1_OC5_COMP3   (                                            COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM1 OC5 (specific to COMP instance: COMP3). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM3_OC4_COMP4   (                                            COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM3 OC4 (specific to COMP instance: COMP4). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM2_OC3_COMP1   (                      COMP_CSR_BLANKSEL_1                      )   /*!< Comparator output blanking source TIM2 OC3 (specific to COMP instance: COMP1). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM2_OC3_COMP2   (                      COMP_CSR_BLANKSEL_1                      )   /*!< Comparator output blanking source TIM2 OC3 (specific to COMP instance: COMP2). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM3_OC3_COMP3   (                      COMP_CSR_BLANKSEL_1                      )   /*!< Comparator output blanking source TIM3 OC3 (specific to COMP instance: COMP3). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM8_OC5_COMP4   (                      COMP_CSR_BLANKSEL_1                      )   /*!< Comparator output blanking source TIM8 OC5 (specific to COMP instance: COMP4). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM3_OC3_COMP1   (                      COMP_CSR_BLANKSEL_1 | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM3 OC3 (specific to COMP instance: COMP1). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM3_OC3_COMP2   (                      COMP_CSR_BLANKSEL_1 | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM3 OC3 (specific to COMP instance: COMP2). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM2_OC4_COMP3   (                      COMP_CSR_BLANKSEL_1 | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM2 OC4 (specific to COMP instance: COMP3). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM15_OC2_COMP4  (                      COMP_CSR_BLANKSEL_1 | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM15 OC2 (specific to COMP instance: COMP4). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM8_OC5_COMP1   (COMP_CSR_BLANKSEL_2                                            )   /*!< Comparator output blanking source TIM8 OC5 (specific to COMP instance: COMP1). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM8_OC5_COMP2   (COMP_CSR_BLANKSEL_2                                            )   /*!< Comparator output blanking source TIM8 OC5 (specific to COMP instance: COMP2). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM8_OC5_COMP3   (COMP_CSR_BLANKSEL_2                                            )   /*!< Comparator output blanking source TIM8 OC5 (specific to COMP instance: COMP3). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM1_OC5_COMP4   (COMP_CSR_BLANKSEL_2                                            )   /*!< Comparator output blanking source TIM1 OC5 (specific to COMP instance: COMP4). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM18_OC3_COMP1  (COMP_CSR_BLANKSEL_2                       | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM18 OC3 (specific to COMP instance: COMP1). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM18_OC3_COMP2  (COMP_CSR_BLANKSEL_2                       | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM18 OC3 (specific to COMP instance: COMP2). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM18_OC4_COMP3  (COMP_CSR_BLANKSEL_2                       | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM18 OC4 (specific to COMP instance: COMP3). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM18_OC4_COMP4  (COMP_CSR_BLANKSEL_2                       | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM18 OC4 (specific to COMP instance: COMP4). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM15_OC1        (COMP_CSR_BLANKSEL_2 | COMP_CSR_BLANKSEL_1                      )   /*!< Comparator output blanking source TIM15 OC1 (specific to COMP instance: ALL). Note: For COMPx & TIMx instances availability, please refer to datasheet */
#define LL_COMP_BLANKINGSRC_TIM4_OC3         (COMP_CSR_BLANKSEL_2 | COMP_CSR_BLANKSEL_1 | COMP_CSR_BLANKSEL_0)   /*!< Comparator output blanking source TIM4 OC3 (specific to COMP instance: ALL). Note: For COMPx & TIMx instances availability, please refer to datasheet */

/**
  * @}
  */

/** @defgroup COMP_LL_EC_OUTPUT_LEVEL Comparator output - Output level
  * @{
  */
#define LL_COMP_OUTPUT_LEVEL_LOW            (0x00000000U)          /*!< Comparator output level low (if the polarity is not inverted, otherwise to be complemented) */
#define LL_COMP_OUTPUT_LEVEL_HIGH           (0x00000001U)          /*!< Comparator output level high (if the polarity is not inverted, otherwise to be complemented) */

/**
  * @}
  */

/** @defgroup COMP_LL_EC_INPUT_HYSTERESIS Comparator Hysteresis
  * @{
  */
#define LL_COMP_HYSTERESIS_ENABLE           (0x00000001U)          /*!< Comparator Hysteresis Enable */
#define LL_COMP_HYSTERESIS_DISABLE          (0x00000000U)          /*!< Comparator Hysteresis Disable */
/**
  * @}
  */

/** @defgroup COMP_LL_EC_POWERMODE Comparator modes - Power mode
  * @{
  */
#define LL_COMP_POWERMODE_HIGHSPEED         ((uint32_t)0x00000000U)                       /*!< COMP power mode to high speed */
#define LL_COMP_POWERMODE_MEDIUMSPEED       (COMP_CSR_PWRMODE_0)                          /*!< COMP power mode to medium speed */
/**
  * @}
  */

/** @defgroup COMP_LL_EC_TIM_EXTI_Out_Sel COMP TIM EXTI Output Selection
  * @{
  */
#define LL_COMP_TIM_EXTI_OUT_NOFILTER                 (0x00000000U)                       /*!< The comparator output to TIM or EXTI is no filtered */
#define LL_COMP_TIM_EXTI_OUT_FILTER                   (COMP_CSR_TIM_EXTI_OUT_SEL)         /*!< The comparator output to TIM or EXTI is filtered */
/**
  * @} 
  */   

/** @defgroup COMP_LL_EC_HW_DELAYS  Definitions of COMP hardware constraints delays
  * @note   Only COMP peripheral HW delays are defined in COMP LL driver driver,
  *         not timeout values.
  *         For details on delays values, refer to descriptions in source code
  *         above each literal definition.
  * @{
  */

/* Delay for comparator startup time.                                         */
/* Note: Delay required to reach propagation delay specification.             */
/* Literal set to maximum value (refer to device datasheet,                   */
/* parameter "tSTART").                                                       */
/* Unit: us                                                                   */
#define LL_COMP_DELAY_STARTUP_US          ( 80U) /*!< Delay for COMP startup time */

/* Delay for comparator voltage scaler stabilization time.                    */
/* Note: Voltage scaler is used when selecting comparator input               */
/*       based on VrefInt: VrefInt or subdivision of VrefInt.                 */
/* Literal set to maximum value (refer to device datasheet,                   */
/* parameter "tSTART_SCALER").                                                */
/* Unit: us                                                                   */
#define LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US ( 200U) /*!< Delay for COMP voltage scaler stabilization time */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Macros COMP Exported Macros
  * @{
  */
/** @defgroup COMP_LL_EM_WRITE_READ Common write and read registers macro
  * @{
  */

/**
  * @brief  Write a value in COMP register
  * @param  __INSTANCE__ comparator instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_COMP_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in COMP register
  * @param  __INSTANCE__ comparator instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_COMP_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
/**
  * @}
  */

/** @defgroup COMP_LL_EM_HELPER_MACRO COMP helper macro
  * @{
  */

/**
  * @brief  Helper macro to select the COMP common instance
  *         to which is belonging the selected COMP instance.
  * @note   COMP common register instance can be used to
  *         set parameters common to several COMP instances.
  *         Refer to functions having argument "COMPxy_COMMON" as parameter.
  * @param  __COMPx__ COMP instance
  * @retval COMP common instance or value "0" if there is no COMP common instance.
  */
#define __LL_COMP_COMMON_INSTANCE(__COMPx__)     ((((__COMPx__) == COMP1) || ((__COMPx__) == COMP2)) ? COMP12_COMMON : COMP34_COMMON)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Functions COMP Exported Functions
  * @{
  */

/** @defgroup COMP_LL_EF_Configuration_comparator_common Configuration of COMP hierarchical scope: common to several COMP instances
  * @{
  */

/**
  * @brief  Set window mode of a pair of comparators instances
  * @rmtoll CSR      WINMODE        LL_COMP_SetCommonWindowMode
  * @param  COMPxy_COMMON Comparator common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_COMP_COMMON_INSTANCE() )
  * @param  WindowMode This parameter can be one of the following values:
  *         @arg @ref LL_COMP_WINDOWMODE_DISABLE
  *         @arg @ref LL_COMP_WINDOWMODE_COMP2_INPUT_PLUS_COMMON 
  *         @arg @ref LL_COMP_WINDOWMODE_COMP4_INPUT_PLUS_COMMON 
  * @retval None  
  */
__STATIC_INLINE void LL_COMP_SetCommonWindowMode(COMP_Common_TypeDef *COMPxy_COMMON, uint32_t WindowMode)
{
  uint32_t window_mode_tmp = WindowMode;

  __IO uint32_t *preg = __COMP_PTR_REG_OFFSET(COMPxy_COMMON->CSR_ODD, (window_mode_tmp & LL_COMP_WINDOWMODE_COMPX_REGOFFSET_MASK));

  /* Clear the potential previous setting of window mode */
  __IO uint32_t *preg_clear = __COMP_PTR_REG_OFFSET(COMPxy_COMMON->CSR_ODD, (~(window_mode_tmp & LL_COMP_WINDOWMODE_COMPX_REGOFFSET_MASK) & LL_COMP_WINDOWMODE_COMP_EVEN_REGOFFSET_MASK));
  CLEAR_BIT(*preg_clear,COMP_CSR_WINMODE);

  /* Set window mode */
  MODIFY_REG(*preg, COMP_CSR_WINMODE,(window_mode_tmp & LL_COMP_WINDOWMODE_COMPX_SETTING_MASK));
}

/**
  * @brief  Get window mode of a pair of comparators instances
  * @rmtoll CSR      WINMODE        LL_COMP_GetCommonWindowMode
  * @param  COMPxy_COMMON Comparator common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_COMP_COMMON_INSTANCE() )
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_WINDOWMODE_DISABLE 
  *         @arg @ref LL_COMP_WINDOWMODE_COMP2_INPUT_PLUS_COMMON 
  *         @arg @ref LL_COMP_WINDOWMODE_COMP4_INPUT_PLUS_COMMON 
  *
  */
__STATIC_INLINE uint32_t LL_COMP_GetCommonWindowMode(COMP_Common_TypeDef *COMPxy_COMMON)
{
   const uint32_t window_mode_comp_odd = (uint32_t)READ_BIT(COMPxy_COMMON->CSR_ODD, COMP_CSR_WINMODE);
   const uint32_t window_mode_comp_even = (uint32_t)READ_BIT(COMPxy_COMMON->CSR_EVEN, COMP_CSR_WINMODE);

   return (uint32_t)(window_mode_comp_odd | window_mode_comp_even
                    | ((window_mode_comp_even >> LL_COMP_WINDOWMODE_BITOFFSET_POS) * LL_COMP_WINDOWMODE_COMP_EVEN_REGOFFSET_MASK));
}
/**
  * @}
  */

/** @defgroup COMP_LL_EF_Configuration_comparator_inputs Configuration of comparator inputs
  * @{
  */

/**
  * @brief  Set comparator inputs minus (inverting) and plus (non-inverting).
  * @note   In case of comparator input selected to be connected to IO:
  *         GPIO pins are specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @rmtoll CSR      INNSEL         LL_COMP_ConfigInputs\n
  *         CSR      INPSEL         LL_COMP_ConfigInputs
  * @param  COMPx Comparator instance
  * @param  InputMinus This parameter can be one of the following values:
  *         @arg @ref LL_COMP_INPUT_MINUS_IO0
  *         @arg @ref LL_COMP_INPUT_MINUS_IO1
  *         @arg @ref LL_COMP_INPUT_MINUS_DAC1_CH1
  *         @arg @ref LL_COMP_INPUT_MINUS_DAC1_CH2
  *         @arg @ref LL_COMP_INPUT_MINUS_VREFCMP
  *         @arg @ref LL_COMP_INPUT_MINUS_TS_VIN
  * @param  InputPlus This parameter can be one of the following values:
  *         @arg @ref LL_COMP_INPUT_PLUS_IO0
  *         @arg @ref LL_COMP_INPUT_PLUS_IO1
  * @retval None
  */
__STATIC_INLINE void LL_COMP_ConfigInputs(COMP_TypeDef *COMPx, uint32_t InputMinus, uint32_t InputPlus)
{
  MODIFY_REG(COMPx->CSR,COMP_CSR_INNSEL | COMP_CSR_INPSEL,InputMinus | InputPlus);
}

/**
  * @brief  Set comparator input plus (non-inverting).
  * @note   In case of comparator input selected to be connected to IO:
  *         GPIO pins are specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @rmtoll CSR      INPSEL         LL_COMP_SetInputPlus
  * @param  COMPx Comparator instance
  * @param  InputPlus This parameter can be one of the following values:
  *         @arg @ref LL_COMP_INPUT_PLUS_IO0
  *         @arg @ref LL_COMP_INPUT_PLUS_IO1
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetInputPlus(COMP_TypeDef *COMPx, uint32_t InputPlus)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_INPSEL, InputPlus);
}

/**
  * @brief  Get comparator input plus (non-inverting).
  * @note   In case of comparator input selected to be connected to IO:
  *         GPIO pins are specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @rmtoll CSR      INPSEL         LL_COMP_GetInputPlus
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_INPUT_PLUS_IO0
  *         @arg @ref LL_COMP_INPUT_PLUS_IO1
  */
__STATIC_INLINE uint32_t LL_COMP_GetInputPlus(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_INPSEL));
}

/**
  * @brief  Set comparator input minus (inverting).
  * @note   In case of comparator input selected to be connected to IO:
  *         GPIO pins are specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @rmtoll CSR      INMSEL         LL_COMP_SetInputMinus
  * @param  COMPx Comparator instance
  * @param  InputMinus This parameter can be one of the following values:
  *         @arg @ref LL_COMP_INPUT_MINUS_IO0
  *         @arg @ref LL_COMP_INPUT_MINUS_IO1
  *         @arg @ref LL_COMP_INPUT_MINUS_DAC1_CH1
  *         @arg @ref LL_COMP_INPUT_MINUS_DAC1_CH2
  *         @arg @ref LL_COMP_INPUT_MINUS_VREFCMP
  *         @arg @ref LL_COMP_INPUT_MINUS_TS_VIN
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetInputMinus(COMP_TypeDef *COMPx, uint32_t InputMinus)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_INNSEL, InputMinus);
}

/**
  * @brief  Get comparator input minus (inverting).
  * @note   In case of comparator input selected to be connected to IO:
  *         GPIO pins are specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @rmtoll CSR      INMSEL         LL_COMP_GetInputMinus
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_INPUT_MINUS_IO0
  *         @arg @ref LL_COMP_INPUT_MINUS_IO1
  *         @arg @ref LL_COMP_INPUT_MINUS_DAC1_CH1
  *         @arg @ref LL_COMP_INPUT_MINUS_DAC1_CH2
  *         @arg @ref LL_COMP_INPUT_MINUS_VREFCMP
  *         @arg @ref LL_COMP_INPUT_MINUS_TS_VIN
  */
__STATIC_INLINE uint32_t LL_COMP_GetInputMinus(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_INNSEL));
}

/**
  * @}
  */


/** @defgroup COMP_LL_EF_Configuration_comparator_vref Configuration of comparator Vref
  * @{
  */


/**
  * @brief  Enable comparator VrefCmp Divider
  * @rmtoll CSR      VCDIV_EN      LL_COMP_EnableVrefCmpDivider
  * @param  COMPx Comparator instance       
  * @retval None
  */
__STATIC_INLINE void LL_COMP_EnableVrefCmpDivider(COMP_TypeDef *COMPx)
{
  SET_BIT(COMP1->CSR, COMP_CSR_VCDIV_EN);
}

/**
  * @brief  Disable comparator VrefCmp Divider
  * @rmtoll CSR      VCDIV_EN      LL_COMP_DisableVrefCmpDivider
  * @param  COMPx Comparator instance       
  * @retval None
  */
__STATIC_INLINE void LL_COMP_DisableVrefCmpDivider(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMP1->CSR, COMP_CSR_VCDIV_EN);
}

/**
  * @brief  Get comparator VrefCmp Divider enable state
  *         (0: VrefCmp Divider is disabled, 1: VrefCmp Divider is enabled)
  * @rmtoll CSR      VCDIV_EN      LL_COMP_IsEnabledVrefCmpDivider
  * @param  COMPx Comparator instance       
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabledVrefCmpDivider(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMP1->CSR, COMP_CSR_VCDIV_EN) == (COMP_CSR_VCDIV_EN)) ? 1U : 0U);
}

/**
  * @brief Set comparator VrefCmp voltage divider configuration.  
  * @rmtoll CSR      COMP_CSR_COMP_VCDIV      LL_COMP_SetVrefCmpDivider
  * @param  COMPx Comparator instance    
  * @param  VrefCmpDiv can be one of the following values:
  *         @arg @ref LL_COMP_VREFCMP_DIV_1_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_2_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_3_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_4_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_5_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_6_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_7_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_8_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_9_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_10_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_11_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_12_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_13_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_14_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_15_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_17_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_18_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_19_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_20_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_21_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_22_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_23_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_24_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_25_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_26_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_27_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_28_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_29_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_30_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_31_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_32_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_33_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_34_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_35_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_36_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_37_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_38_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_39_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_40_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_41_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_42_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_43_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_44_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_45_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_46_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_47_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_48_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_49_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_50_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_51_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_52_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_53_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_54_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_55_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_56_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_57_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_58_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_59_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_60_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_61_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_62_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_63_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_VREFCMP
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetVrefCmpDivider(COMP_TypeDef *COMPx, uint32_t VrefCmpDiv)
{
  MODIFY_REG(COMP1->CSR, COMP_CSR_VCDIV, VrefCmpDiv);
}

/**
  * @brief Get comparator VREFCMP voltage divider configuration.
  * @rmtoll CSR      VCDIV      LL_COMP_GetVrefCmpDivider
  * @param  COMPx Comparator instance       
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_VREFCMP_DIV_1_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_2_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_3_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_4_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_5_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_6_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_7_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_8_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_9_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_10_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_11_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_12_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_13_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_14_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_15_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_17_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_18_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_19_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_20_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_21_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_22_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_23_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_24_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_25_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_26_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_27_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_28_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_29_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_30_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_31_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_32_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_33_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_34_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_35_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_36_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_37_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_38_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_39_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_40_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_41_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_42_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_43_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_44_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_45_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_46_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_47_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_48_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_49_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_50_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_51_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_52_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_53_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_54_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_55_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_56_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_57_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_58_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_59_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_60_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_61_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_62_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_63_64VREFCMP
  *         @arg @ref LL_COMP_VREFCMP_DIV_VREFCMP
  */
__STATIC_INLINE uint32_t LL_COMP_GetVrefCmpDivider(COMP_TypeDef *COMPx)
{
   return (uint32_t)(READ_BIT(COMP1->CSR, COMP_CSR_VCDIV));
}

/**
  * @brief  Set comparator VrefCmp reference source selection. 
  * @rmtoll CSR      VCSEL      LL_COMP_SetVrefCmpSource
  * @param  COMPx Comparator instance       
  * @param  VrefCmpSource can be one of the following values:
  *         @arg @ref LL_COMP_VREFCMP_SOURCE_VREFINT
  *         @arg @ref LL_COMP_VREFCMP_SOURCE_VCC
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetVrefCmpSource(COMP_TypeDef *COMPx, uint32_t VrefCmpSource)
{
  MODIFY_REG(COMP1->CSR, COMP_CSR_VCSEL, VrefCmpSource);
}

/**
  * @brief  Get comparator VrefCmp reference source selection.
  * @rmtoll CSR      VCSEL      LL_COMP_GetVrefCmpSource
  * @param  COMPx Comparator instance       
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_VREFCMP_SOURCE_VREFINT
  *         @arg @ref LL_COMP_VREFCMP_SOURCE_VCC
  */
__STATIC_INLINE uint32_t LL_COMP_GetVrefCmpSource(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMP1->CSR, COMP_CSR_VCSEL));
}

/**
  * @brief  Set comparator Vrefint voltage
  * @rmtoll CSR      VSEL      LL_COMP_SetVrefintVoltage
  * @param  COMPx Comparator instance       
  * @param  VrefintVoltage can be one of the following values:
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_0P6V
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_1P5V
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_2P048V
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_2P5V
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetVrefintVoltage(COMP_TypeDef *COMPx, uint32_t VrefintVoltage)
{
  __IO uint32_t tempdata = 0 ;

  MODIFY_REG(COMP1->CSR, COMP_CSR_VSEL, VrefintVoltage);
  WRITE_REG(FLASH->KEYR, FLASH_KEY1);
  WRITE_REG(FLASH->KEYR, FLASH_KEY2);

  WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY1);
  WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY2);

  *(uint32_t *)0x4002228C = 0x5D7F4051;
  *(uint32_t *)0x4002228C = 0x46CE2763;
  switch (VrefintVoltage)
  {
    case LL_COMP_VREFINT_VOLTAGE_0P6V:
      tempdata = (((*(uint32_t *)0x40022208) & 0xFFE0FFFF) | (((*(uint32_t *)0x1FFF76C0) << 16) & 0x1F0000));
      *(uint32_t *)0x40022208 = tempdata;
      break;

    case LL_COMP_VREFINT_VOLTAGE_1P5V:
       tempdata = (((*(uint32_t *)0x40022208) & 0xFFE0FFFF) | (((*(uint32_t *)0x1FFF76C4) << 16) & 0x1F0000));
       *(uint32_t *)0x40022208 = tempdata;
      break;

    case LL_COMP_VREFINT_VOLTAGE_2P048V:
       tempdata = (((*(uint32_t *)0x40022208) & 0xFFE0FFFF) | (((*(uint32_t *)0x1FFF76C8) << 16) & 0x1F0000));
       *(uint32_t *)0x40022208 = tempdata;
      break;

    default:
       tempdata = (((*(uint32_t *)0x40022208) & 0xFFE0FFFF) | (((*(uint32_t *)0x1FFF76CC) << 16) & 0x1F0000));
       *(uint32_t *)0x40022208 = tempdata;
      break;
  }
  SET_BIT(FLASH->CR, FLASH_CR_LOCK);
}

/**
  * @brief  Get comparator Vrefint voltage
  * @rmtoll CSR      VSEL      LL_COMP_GetVrefintVoltage
  * @param  COMPx Comparator instance       
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_0P6V
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_1P5V
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_2P048V
  *         @arg @ref LL_COMP_VREFINT_VOLTAGE_2P5V
  */
__STATIC_INLINE uint32_t LL_COMP_GetVrefintVoltage(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMP1->CSR, COMP_CSR_VSEL));
}
/**
  * @}
  */


/** @defgroup COMP_LL_EF_Configuration_comparator_Hysteresis Configuration of comparator Hysteresis
  * @{
  */
/**
  * @brief  Set comparator instance hysteresis mode of the input minus (inverting input).
  * @rmtoll CSR      HYST           LL_COMP_SetInputHysteresis
  * @param  COMPx Comparator instance
  * @param  InputHysteresis This parameter can be one of the following values:
  *         @arg @ref LL_COMP_HYSTERESIS_DISABLE
  *         @arg @ref LL_COMP_HYSTERESIS_ENABLE
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetInputHysteresis(COMP_TypeDef *COMPx, uint32_t InputHysteresis)
{
  if(InputHysteresis == LL_COMP_HYSTERESIS_ENABLE)
  {
    if(COMPx == COMP1)
    {
      SET_BIT(COMPx->CSR, COMP1_CSR_HYST);
    }
    else
    {
      SET_BIT(COMPx->CSR, COMP2_CSR_HYST);
    }
  }
  else
  {
    if(COMPx == COMP1)
    {
      CLEAR_BIT(COMPx->CSR, COMP1_CSR_HYST);
    }
    else
    {
      CLEAR_BIT(COMPx->CSR, COMP2_CSR_HYST);
    }    
  }
}

/**
  * @brief  Get comparator instance hysteresis mode of the minus (inverting) input.
  * @rmtoll CSR      HYST           LL_COMP_GetInputHysteresis
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_HYSTERESIS_DISABLE
  *         @arg @ref LL_COMP_HYSTERESIS_ENABLE
  */
__STATIC_INLINE uint32_t LL_COMP_GetInputHysteresis(COMP_TypeDef *COMPx)
{ 
  if(COMPx==COMP1)
  {
    return ((READ_BIT(COMPx->CSR, COMP1_CSR_HYST)==COMP1_CSR_HYST) ? LL_COMP_HYSTERESIS_ENABLE : LL_COMP_HYSTERESIS_DISABLE);
  }
  else
  {
    return ((READ_BIT(COMPx->CSR, COMP2_CSR_HYST)==COMP2_CSR_HYST) ? LL_COMP_HYSTERESIS_ENABLE : LL_COMP_HYSTERESIS_DISABLE);
  }      
}
/**
  * @}
  */


/** @defgroup COMP_LL_EF_Configuration_comparator_modes Configuration of comparator modes
  * @{
  */

/**
  * @brief  Set comparator instance operating mode to adjust power and speed.
  * @rmtoll CSR      PWRMODE        LL_COMP_SetPowerMode
  * @param  COMPx Comparator instance
  * @param  PowerMode This parameter can be one of the following values:
  *         @arg @ref LL_COMP_POWERMODE_HIGHSPEED
  *         @arg @ref LL_COMP_POWERMODE_MEDIUMSPEED
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetPowerMode(COMP_TypeDef *COMPx, uint32_t PowerMode)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_PWRMODE, PowerMode);
}

/**
  * @brief  Get comparator instance operating mode to adjust power and speed.
  * @rmtoll CSR      PWRMODE        LL_COMP_GetPowerMode
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_POWERMODE_HIGHSPEED
  *         @arg @ref LL_COMP_POWERMODE_MEDIUMSPEED
  */
__STATIC_INLINE uint32_t LL_COMP_GetPowerMode(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_PWRMODE));
}

/**
  * @}
  */

/** @defgroup COMP_LL_EF_Configuration_comparator_output Configuration of comparator output
  * @{
  */

/**
  * @brief  Set comparator instance output polarity.
  * @rmtoll CSR      POLARITY       LL_COMP_SetOutputPolarity
  * @param  COMPx Comparator instance
  * @param  OutputPolarity This parameter can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUTPOL_NONINVERTED
  *         @arg @ref LL_COMP_OUTPUTPOL_INVERTED
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetOutputPolarity(COMP_TypeDef *COMPx, uint32_t OutputPolarity)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_POLARITY, OutputPolarity);
}

/**
  * @brief  Get comparator instance output polarity.
  * @rmtoll CSR      POLARITY       LL_COMP_GetOutputPolarity
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUTPOL_NONINVERTED
  *         @arg @ref LL_COMP_OUTPUTPOL_INVERTED
  */
__STATIC_INLINE uint32_t LL_COMP_GetOutputPolarity(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_POLARITY));
}

/**
  * @brief  Set comparator instance blanking source.
  * @note   Blanking source may be specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @note   Availability of parameters of blanking source from timer
  *         depends on timers availability on the selected device.
  * @rmtoll CSR      BLANKSEL       LL_COMP_SetOutputBlankingSource
  * @param  COMPx Comparator instance
  * @param  BlankingSource This parameter can be one of the following values:
  *         @arg @ref LL_COMP_BLANKINGSRC_NONE
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC4_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM2_OC3_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM2_OC3_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC3_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC3_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC3_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM2_OC4_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM15_OC2_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC3_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC3_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC4_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC4_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM15_OC1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM4_OC3
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetOutputBlankingSource(COMP_TypeDef *COMPx, uint32_t BlankingSource)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_BLANKSEL, BlankingSource);
}

/**
  * @brief  Get comparator instance blanking source.
  * @note   Availability of parameters of blanking source from timer
  *         depends on timers availability on the selected device.
  * @note   Blanking source may be specific to each comparator instance.
  *         Refer to description of parameters or to reference manual.
  * @rmtoll CSR      BLANKSEL       LL_COMP_GetOutputBlankingSource
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_BLANKINGSRC_NONE
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC4_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM2_OC3_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM2_OC3_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC3_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC3_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM3_OC3_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM2_OC4_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM15_OC2_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM8_OC5_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM1_OC5_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC3_COMP1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC3_COMP2
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC4_COMP3
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM18_OC4_COMP4
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM15_OC1
  *         @arg @ref LL_COMP_BLANKINGSRC_TIM4_OC3
  */
__STATIC_INLINE uint32_t LL_COMP_GetOutputBlankingSource(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_BLANKSEL));
}

/**
  * @}
  */

/** @defgroup COMP_LL_EF_Operation Operation on comparator instance
  * @{
  */

/**
  * @brief  Enable comparator instance.
  * @note   After enable from off state, comparator requires a delay
  *         to reach reach propagation delay specification.
  *         Refer to device datasheet, parameter "tSTART".
  * @rmtoll CSR      EN             LL_COMP_Enable
  * @param  COMPx Comparator instance
  * @retval None
  */
__STATIC_INLINE void LL_COMP_Enable(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSR, COMP_CSR_EN);
}


/**
  * @brief  Disable comparator instance.
  * @rmtoll CSR      EN             LL_COMP_Disable
  * @param  COMPx Comparator instance
  * @retval None
  */
__STATIC_INLINE void LL_COMP_Disable(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->CSR, COMP_CSR_EN);
}

/**
  * @brief  Get comparator enable state
  *         (0: COMP is disabled, 1: COMP is enabled)
  * @rmtoll CSR      EN             LL_COMP_IsEnabled
  * @param  COMPx Comparator instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabled(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSR, COMP_CSR_EN) == (COMP_CSR_EN)) ? 1U : 0U);
}

/**
  * @brief  Read comparator instance output level.
  * @note   The comparator output level depends on the selected polarity
  *         (Refer to function @ref LL_COMP_SetOutputPolarity()).
  *         If the comparator polarity is not inverted:
  *          - Comparator output is low when the input plus
  *            is at a lower voltage than the input minus
  *          - Comparator output is high when the input plus
  *            is at a higher voltage than the input minus
  *         If the comparator polarity is inverted:
  *          - Comparator output is high when the input plus
  *            is at a lower voltage than the input minus
  *          - Comparator output is low when the input plus
  *            is at a higher voltage than the input minus
  * @rmtoll CSR      COMP_CSR_COMP_OUT       LL_COMP_ReadOutputLevel
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUT_LEVEL_LOW
  *         @arg @ref LL_COMP_OUTPUT_LEVEL_HIGH   
  */
__STATIC_INLINE uint32_t LL_COMP_ReadOutputLevel(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_COMP_OUT)>> LL_COMP_OUTPUT_LEVEL_BITOFFSET_POS);
}

/**
  * @brief  Set whether the comparator output is filtered to TIM or EXTI.
  * @rmtoll CSR      TIM_EXTI_OUT_SEL     LL_COMP_SetTimExtiOutSelection
  * @param  COMPx Comparator instance
  * @param  OutputSelection value can be one of the following values:
  *         @arg @ref LL_COMP_TIM_EXTI_OUT_NOFILTER
  *         @arg @ref LL_COMP_TIM_EXTI_OUT_FILTER
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetTimExtiOutSelection(COMP_TypeDef *COMPx, uint32_t OutputSelection)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_TIM_EXTI_OUT_SEL, OutputSelection);
}   

/**
  * @brief  Get whether the comparator output is filtered to TIM or EXTI.
  * @rmtoll CSR      TIM_EXTI_OUT_SEL     LL_COMP_GetTimExtiOutSelection
  * @param  COMPx Comparator instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_COMP_TIM_EXTI_OUT_NOFILTER
  *         @arg @ref LL_COMP_TIM_EXTI_OUT_FILTER
  */
__STATIC_INLINE uint32_t LL_COMP_GetTimExtiOutSelection(COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_TIM_EXTI_OUT_SEL));
}   

/**
  * @}
  */

/** @defgroup COMP_LL_EF_DigitalFilter DigitalFilter on comparator instance
  * @{
  */
/**
  * @brief  Enable comparator DigitalFilter.
  * @rmtoll FR       FLTEN          LL_COMP_EnableDigitalFilter
  * @param  COMPx Comparator instance   
  * @retval None
  */
__STATIC_INLINE void LL_COMP_EnableDigitalFilter(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->FR, COMP_FR_FLTEN);
}

/**
  * @brief  Disable comparator DigitalFilter.
  * @rmtoll FR       FLTEN          LL_COMP_DisableDigitalFilter
  * @param  COMPx Comparator instance   
  * @retval None
  */
__STATIC_INLINE void LL_COMP_DisableDigitalFilter(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->FR, COMP_FR_FLTEN);
}

/**
  * @brief  Get comparator DigitalFilter state
  *         (0: Filter is Disabled, 1: Filter is Enabled).
  * @rmtoll FR       FLTEN          LL_COMP_IsEnabledDigitalFilter
  * @param  COMPx Comparator instance    
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_COMP_IsEnabledDigitalFilter(COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->FR, COMP_FR_FLTEN) == (COMP_FR_FLTEN)) ? 1U : 0U);
}

/**
  * @brief  Set comparator DigitalFilter Value.
  * @rmtoll FR       FLTCNT         LL_COMP_SetDigitalFilter
  * @param  COMPx Comparator instance      
  * @param  FLTCNTValue Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void LL_COMP_SetDigitalFilter(COMP_TypeDef *COMPx,uint32_t FLTCNTValue)
{
  MODIFY_REG(COMPx->FR,COMP_FR_FLTCNT,FLTCNTValue << COMP_FR_FLTCNT_Pos);
}

/**
  * @brief  Get comparator DigitalFilter Value
  * @rmtoll FR       FLTCNT         LL_COMP_GetDigitalFilter
  * @param  COMPx Comparator instance          
  * @retval DigitalFilter Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_COMP_GetDigitalFilter(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_REG(COMPx->FR)>>COMP_FR_FLTCNT_Pos);
}


/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup COMP_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_COMP_DeInit(COMP_TypeDef *COMPx);
ErrorStatus LL_COMP_Init(COMP_TypeDef *COMPx, LL_COMP_InitTypeDef *COMP_InitStruct);
void        LL_COMP_StructInit(LL_COMP_InitTypeDef *COMP_InitStruct);

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

#endif /* COMP1 || COMP2 || COMP3 || COMP4*/

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* PY32F072_LL_COMP_H */


/************************ (C) COPYRIGHT Puya *****END OF FILE****/

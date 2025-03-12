/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

#include "stm32h7xx_ll_adc.h"
#include "stm32h7xx_ll_bdma.h"
#include "stm32h7xx_ll_dma.h"
#include "stm32h7xx_ll_i2c.h"
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_crs.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_system.h"
#include "stm32h7xx_ll_exti.h"
#include "stm32h7xx_ll_cortex.h"
#include "stm32h7xx_ll_utils.h"
#include "stm32h7xx_ll_pwr.h"
#include "stm32h7xx_ll_rtc.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_tim.h"
#include "stm32h7xx_ll_usart.h"
#include "stm32h7xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_RED_Pin LL_GPIO_PIN_3
#define LED_RED_GPIO_Port GPIOE
#define GPIO_CAN1_SILENT_Pin LL_GPIO_PIN_2
#define GPIO_CAN1_SILENT_GPIO_Port GPIOE
#define GPS2_TX_Pin LL_GPIO_PIN_1
#define GPS2_TX_GPIO_Port GPIOE
#define GPS2_RX_Pin LL_GPIO_PIN_0
#define GPS2_RX_GPIO_Port GPIOE
#define TELEM2_TX_Pin LL_GPIO_PIN_12
#define TELEM2_TX_GPIO_Port GPIOC
#define LED_GREEN_Pin LL_GPIO_PIN_4
#define LED_GREEN_GPIO_Port GPIOE
#define LED_BLUE_Pin LL_GPIO_PIN_5
#define LED_BLUE_GPIO_Port GPIOE
#define PWM_12_Pin LL_GPIO_PIN_6
#define PWM_12_GPIO_Port GPIOE
#define GPS1_RX_Pin LL_GPIO_PIN_7
#define GPS1_RX_GPIO_Port GPIOB
#define GPS1_TX_Pin LL_GPIO_PIN_6
#define GPS1_TX_GPIO_Port GPIOB
#define ETHERNET_PWR_EN_Pin LL_GPIO_PIN_15
#define ETHERNET_PWR_EN_GPIO_Port GPIOG
#define VDD_5V_HIPOWER_EN_Pin LL_GPIO_PIN_10
#define VDD_5V_HIPOWER_EN_GPIO_Port GPIOG
#define CAN1_RX_Pin LL_GPIO_PIN_0
#define CAN1_RX_GPIO_Port GPIOD
#define PWM_10_Pin LL_GPIO_PIN_7
#define PWM_10_GPIO_Port GPIOI
#define PWM_9_Pin LL_GPIO_PIN_6
#define PWM_9_GPIO_Port GPIOI
#define PWM_11_Pin LL_GPIO_PIN_5
#define PWM_11_GPIO_Port GPIOI
#define CAN1_TX_Pin LL_GPIO_PIN_1
#define CAN1_TX_GPIO_Port GPIOD
#define VDD_3V3_SD_CARD_EN_Pin LL_GPIO_PIN_13
#define VDD_3V3_SD_CARD_EN_GPIO_Port GPIOC
#define GPIO_CAN2_SILENT_Pin LL_GPIO_PIN_8
#define GPIO_CAN2_SILENT_GPIO_Port GPIOI
#define IIM42652_CS_Pin LL_GPIO_PIN_9
#define IIM42652_CS_GPIO_Port GPIOI
#define TELEM2_RX_Pin LL_GPIO_PIN_2
#define TELEM2_RX_GPIO_Port GPIOD
#define BMI088_DRDY_ACC_Pin LL_GPIO_PIN_10
#define BMI088_DRDY_ACC_GPIO_Port GPIOA
#define VDD_3V3_SENSORS1_EN_Pin LL_GPIO_PIN_11
#define VDD_3V3_SENSORS1_EN_GPIO_Port GPIOI
#define PWM_1_Pin LL_GPIO_PIN_0
#define PWM_1_GPIO_Port GPIOI
#define VBUS_INPUT_Pin LL_GPIO_PIN_9
#define VBUS_INPUT_GPIO_Port GPIOA
#define VDD_3V3_SENSORS3_EN_Pin LL_GPIO_PIN_2
#define VDD_3V3_SENSORS3_EN_GPIO_Port GPIOH
#define TELEM2_CTS_Pin LL_GPIO_PIN_9
#define TELEM2_CTS_GPIO_Port GPIOC
#define TELEM2_RTS_Pin LL_GPIO_PIN_8
#define TELEM2_RTS_GPIO_Port GPIOC
#define RC_Pin LL_GPIO_PIN_7
#define RC_GPIO_Port GPIOC
#define IIM42652_DRDY_Pin LL_GPIO_PIN_2
#define IIM42652_DRDY_GPIO_Port GPIOF
#define PWM_VOLT_SEL_Pin LL_GPIO_PIN_8
#define PWM_VOLT_SEL_GPIO_Port GPIOG
#define RC_INPUT_Pin LL_GPIO_PIN_6
#define RC_INPUT_GPIO_Port GPIOC
#define ADC3_6V6_Pin LL_GPIO_PIN_3
#define ADC3_6V6_GPIO_Port GPIOF
#define VDD_3V3_SENSORS2_EN_Pin LL_GPIO_PIN_4
#define VDD_3V3_SENSORS2_EN_GPIO_Port GPIOF
#define BMI088_A_CS_Pin LL_GPIO_PIN_5
#define BMI088_A_CS_GPIO_Port GPIOH
#define FRAM_CS_Pin LL_GPIO_PIN_7
#define FRAM_CS_GPIO_Port GPIOG
#define TELEM1_RX_Pin LL_GPIO_PIN_6
#define TELEM1_RX_GPIO_Port GPIOF
#define SAFETY_IN_Pin LL_GPIO_PIN_5
#define SAFETY_IN_GPIO_Port GPIOF
#define PWM_2_Pin LL_GPIO_PIN_12
#define PWM_2_GPIO_Port GPIOH
#define ICP20100_DRDY1_Pin LL_GPIO_PIN_5
#define ICP20100_DRDY1_GPIO_Port GPIOG
#define VDD_5V_PERIPH_EN_Pin LL_GPIO_PIN_4
#define VDD_5V_PERIPH_EN_GPIO_Port GPIOG
#define BMI088_DRDY_GYRO_Pin LL_GPIO_PIN_3
#define BMI088_DRDY_GYRO_GPIO_Port GPIOG
#define BUZZER_Pin LL_GPIO_PIN_9
#define BUZZER_GPIO_Port GPIOF
#define TELEM1_RTS_Pin LL_GPIO_PIN_8
#define TELEM1_RTS_GPIO_Port GPIOF
#define PWM_3_Pin LL_GPIO_PIN_11
#define PWM_3_GPIO_Port GPIOH
#define PWM_4_Pin LL_GPIO_PIN_10
#define PWM_4_GPIO_Port GPIOH
#define BMP581_CS_Pin LL_GPIO_PIN_15
#define BMP581_CS_GPIO_Port GPIOD
#define BMI088_G_CS_Pin LL_GPIO_PIN_2
#define BMI088_G_CS_GPIO_Port GPIOG
#define RSSI_IN_Pin LL_GPIO_PIN_0
#define RSSI_IN_GPIO_Port GPIOC
#define BATT_VOLTAGE_SENS_Pin LL_GPIO_PIN_2
#define BATT_VOLTAGE_SENS_GPIO_Port GPIOC
#define ADC1_3V3_Pin LL_GPIO_PIN_3
#define ADC1_3V3_GPIO_Port GPIOC
#define BMP581_DRDY_Pin LL_GPIO_PIN_1
#define BMP581_DRDY_GPIO_Port GPIOG
#define PWM_13_Pin LL_GPIO_PIN_6
#define PWM_13_GPIO_Port GPIOH
#define PWM_14_Pin LL_GPIO_PIN_9
#define PWM_14_GPIO_Port GPIOH
#define PWM_6_Pin LL_GPIO_PIN_14
#define PWM_6_GPIO_Port GPIOD
#define PWM_5_Pin LL_GPIO_PIN_13
#define PWM_5_GPIO_Port GPIOD
#define SCALED1_V3V3_Pin LL_GPIO_PIN_0
#define SCALED1_V3V3_GPIO_Port GPIOA
#define SCALED2_V3V3_Pin LL_GPIO_PIN_4
#define SCALED2_V3V3_GPIO_Port GPIOA
#define VDD_5V_HIPOWER_nOC_Pin LL_GPIO_PIN_13
#define VDD_5V_HIPOWER_nOC_GPIO_Port GPIOF
#define HW_VER_REV_DRIVE_Pin LL_GPIO_PIN_0
#define HW_VER_REV_DRIVE_GPIO_Port GPIOG
#define LED_SAFETY_Pin LL_GPIO_PIN_10
#define LED_SAFETY_GPIO_Port GPIOD
#define FMU_SERVORAIL_VCC_SENS_Pin LL_GPIO_PIN_12
#define FMU_SERVORAIL_VCC_SENS_GPIO_Port GPIOF
#define TELEM1_TX_Pin LL_GPIO_PIN_8
#define TELEM1_TX_GPIO_Port GPIOE
#define PWM_8_Pin LL_GPIO_PIN_9
#define PWM_8_GPIO_Port GPIOE
#define PWM_7_Pin LL_GPIO_PIN_11
#define PWM_7_GPIO_Port GPIOE
#define CAN2_RX_Pin LL_GPIO_PIN_12
#define CAN2_RX_GPIO_Port GPIOB
#define CAN2_TX_Pin LL_GPIO_PIN_13
#define CAN2_TX_GPIO_Port GPIOB
#define DEBUG_RX_Pin LL_GPIO_PIN_9
#define DEBUG_RX_GPIO_Port GPIOD
#define DEBUG_TX_Pin LL_GPIO_PIN_8
#define DEBUG_TX_GPIO_Port GPIOD
#define VDD_5V_SENS_Pin LL_GPIO_PIN_1
#define VDD_5V_SENS_GPIO_Port GPIOB
#define BATT_CURRENT_SENS_Pin LL_GPIO_PIN_0
#define BATT_CURRENT_SENS_GPIO_Port GPIOB
#define nARMED_Pin LL_GPIO_PIN_7
#define nARMED_GPIO_Port GPIOE
#define TELEM1_CTS_Pin LL_GPIO_PIN_10
#define TELEM1_CTS_GPIO_Port GPIOE
#define VDD_5V_PERIPH_nOC_Pin LL_GPIO_PIN_15
#define VDD_5V_PERIPH_nOC_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

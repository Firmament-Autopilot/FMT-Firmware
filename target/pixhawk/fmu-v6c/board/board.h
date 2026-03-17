/******************************************************************************
 * Copyright 2023 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef FMT_BSP_H__
#define FMT_BSP_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

// Board Information
#define TARGET_NAME           "Pixhawk 6C"

// Internal SRAM memory size[Kbytes]
#define SYSTEM_TOTAL_MEM_SIZE (512 * 1024) // 512K

// Internal Free SRAM memory used by kernel (e.g, rt_malloc)
#ifdef __ICCARM__
// Use *.icf ram symbal, to avoid hardcode.
extern char __ICFEDIT_region_RAM_end__;
    #define SYSTEM_FREE_MEM_END &__ICFEDIT_region_RAM_end__
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
/* the size of heap is defined in startup.s, the address can be found in .map file */
extern int __heap_base;
extern int __heap_limit;
    #define SYSTEM_FREE_MEM_BEGIN (&__heap_base)
    #define SYSTEM_FREE_MEM_END   (&__heap_limit)
#else
extern int __bss_end;
    #define SYSTEM_FREE_MEM_BEGIN (&__bss_end)
    #define SYSTEM_FREE_MEM_END   (0x24000000 + SYSTEM_TOTAL_MEM_SIZE)
#endif

#ifndef NVIC_PRIORITYGROUP_0
    #define NVIC_PRIORITYGROUP_0 ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority, \
                                                             4 bits for subpriority */
    #define NVIC_PRIORITYGROUP_1 ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority, \
                                                             3 bits for subpriority */
    #define NVIC_PRIORITYGROUP_2 ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority, \
                                                             2 bits for subpriority */
    #define NVIC_PRIORITYGROUP_3 ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority, \
                                                             1 bit  for subpriority */
    #define NVIC_PRIORITYGROUP_4 ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority, \
                                                             0 bit  for subpriority */
#endif

/* HSE Clock Frequency */
// #define HSE_VALUE           16000000U /* 16MHz */

/* Console Device */
#define CONSOLE_UART                       "serial3"

/* I2C Device */
#define I2C_ENABLE                         1
#define I2C_DEVICE_EXT1                    "i2c1"
#define I2C_DEVICE_EXT2                    "i2c2"
#define I2C_DEVICE_INT                     "i2c4"

/* SPI Device */
// SPI1: Sensors (BMI088, ICM42688)
// SPI2: FRAM

/* SPI Definitions */
/* Map logical SPI1 CS entries to CubeMX FMU pin definitions */
#define SPI1_CS1_GPIO                      FMU_SPI1_CS1_BMI055_ACC_GPIO_Port
#define SPI1_CS1_PIN                       FMU_SPI1_CS1_BMI055_ACC_Pin /* BMI055 Accel (spi1_dev1) */
#define SPI1_CS2_GPIO                      FMU_SPI1_CS2_BMI055_GYRO_GPIO_Port
#define SPI1_CS2_PIN                       FMU_SPI1_CS2_BMI055_GYRO_Pin /* BMI055 Gyro (spi1_dev2) */
#define SPI1_CS3_GPIO                      FMU_SPI1_CS3_ICM42688_GPIO_Port
#define SPI1_CS3_PIN                       FMU_SPI1_CS3_ICM42688_Pin /* ICM42688 (spi1_dev3) */

#define SPI2_CS1_GPIO                      GPIOD
#define SPI2_CS1_PIN                       GPIO_PIN_4 // FRAM

/* CubeMX Generated Definitions */
#define FMU_SPI1_CS2_BMI055_GYRO_Pin       GPIO_PIN_14
#define FMU_SPI1_CS2_BMI055_GYRO_GPIO_Port GPIOC
#define FMU_SPI1_CS3_ICM42688_Pin          GPIO_PIN_13
#define FMU_SPI1_CS3_ICM42688_GPIO_Port    GPIOC
#define N_VDD_5V_PERIPH_EN_Pin             GPIO_PIN_2
#define N_VDD_5V_PERIPH_EN_GPIO_Port       GPIOE
#define N_BRICK1_VALID_Pin                 GPIO_PIN_15
#define N_BRICK1_VALID_GPIO_Port           GPIOA
#define FMU_SPI1_CS1_BMI055_ACC_Pin        GPIO_PIN_15
#define FMU_SPI1_CS1_BMI055_ACC_GPIO_Port  GPIOC
#define N_VDD_5V_HIPOWER_EN_Pin            GPIO_PIN_10
#define N_VDD_5V_HIPOWER_EN_GPIO_Port      GPIOC
#define SPI1_DRDY1_BMI055_ACC_Pin          GPIO_PIN_4
#define SPI1_DRDY1_BMI055_ACC_GPIO_Port    GPIOE
#define SPI1_DRDY1_BMI055_ACC_EXTI_IRQn    EXTI4_IRQn
#define SPI1_DRDY2_BMI055_GYRO_Pin         GPIO_PIN_5
#define SPI1_DRDY2_BMI055_GYRO_GPIO_Port   GPIOE
#define SPI1_DRDY2_BMI055_GYRO_EXTI_IRQn   EXTI9_5_IRQn
#define FMU_SPI2_CS_FRAM_Pin               GPIO_PIN_4
#define FMU_SPI2_CS_FRAM_GPIO_Port         GPIOD
#define SPI1_DRDY3_ICM42688_Pin            GPIO_PIN_6
#define SPI1_DRDY3_ICM42688_GPIO_Port      GPIOE
#define SPI1_DRDY3_ICM42688_EXTI_IRQn      EXTI9_5_IRQn
#define VDD_3V3_SENSORS_EN_Pin             GPIO_PIN_2
#define VDD_3V3_SENSORS_EN_GPIO_Port       GPIOB
#define N_FMU_LED_BLUE_Pin                 GPIO_PIN_11
#define N_FMU_LED_BLUE_GPIO_Port           GPIOD
#define N_USB_VBUS_VALID_Pin               GPIO_PIN_15
#define N_USB_VBUS_VALID_GPIO_Port         GPIOE
#define N_FMU_LED_RED_Pin                  GPIO_PIN_10
#define N_FMU_LED_RED_GPIO_Port            GPIOD
#define HW_VER_REV_DRIVE_Pin               GPIO_PIN_12
#define HW_VER_REV_DRIVE_GPIO_Port         GPIOE
#define N_BRICK2_VALID_Pin                 GPIO_PIN_12
#define N_BRICK2_VALID_GPIO_Port           GPIOB

void SystemClock_Config(void);
void Error_Handler(void);

void rt_hw_board_init(void);
void bsp_early_initialize(void);
void bsp_initialize(void);
void bsp_post_initialize(void);

#ifdef __cplusplus
}
#endif

#endif

/**
 ******************************************************************************
 * @file    stm32h7xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 */

#include <firmament.h>
#include "board.h"
#include "stm32h7xx_hal.h"

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;
extern FDCAN_HandleTypeDef hfdcan1;
extern FDCAN_HandleTypeDef hfdcan2;
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern I2C_HandleTypeDef hi2c4;
extern SD_HandleTypeDef hsd2;
extern DMA_HandleTypeDef hdma_spi1_rx;
extern DMA_HandleTypeDef hdma_spi1_tx;
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim17;
extern DMA_HandleTypeDef hdma_uart7_rx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart7;
extern UART_HandleTypeDef huart8;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
extern TIM_HandleTypeDef htim6;

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief   This function handles NMI exception.
 */
void NMI_Handler(void)
{
    while (1) {
    }
}

/**
 * @brief  This function handles Hard Fault exception.
 */
// void HardFault_Handler(void)
// {
//   while (1) { }
// }

/**
 * @brief  This function handles Memory Manage exception.
 */
void MemManage_Handler(void)
{
    while (1) {
    }
}

/**
 * @brief  This function handles Bus Fault exception.
 */
void BusFault_Handler(void)
{
    while (1) {
    }
}

/**
 * @brief  This function handles Usage Fault exception.
 */
void UsageFault_Handler(void)
{
    while (1) {
    }
}

/**
 * @brief  This function handles SVCall exception.
 */
void SVC_Handler(void)
{
}

/**
 * @brief  This function handles Debug Monitor exception.
 */
void DebugMon_Handler(void)
{
}

/**
 * @brief  This function handles PendSVC exception.
 */
// void PendSV_Handler(void)
// {
// }

/**
 * @brief  This function handles SysTick Handler.
 */
// void SysTick_Handler(void)
// {
// }

/******************************************************************************/
/*                 STM32H7xx Peripherals Interrupt Handlers                   */
/******************************************************************************/

// void EXTI4_IRQHandler(void)
// {
//   HAL_GPIO_EXTI_IRQHandler(SPI1_DRDY1_BMI055_ACC_Pin);
// }

// void DMA1_Stream0_IRQHandler(void)
// {
//   HAL_DMA_IRQHandler(&hdma_spi1_rx);
// }

// void DMA1_Stream1_IRQHandler(void)
// {
//   HAL_DMA_IRQHandler(&hdma_spi1_tx);
// }

// void DMA1_Stream2_IRQHandler(void)
// {
//   HAL_DMA_IRQHandler(&hdma_usart1_rx);
// }

// void DMA1_Stream3_IRQHandler(void)
// {
//   HAL_DMA_IRQHandler(&hdma_uart7_rx);
// }

// void ADC_IRQHandler(void)
// {
//   HAL_ADC_IRQHandler(&hadc1);
// }

// void FDCAN1_IT0_IRQHandler(void)
// {
//   HAL_FDCAN_IRQHandler(&hfdcan1);
// }

// void FDCAN2_IT0_IRQHandler(void)
// {
//   HAL_FDCAN_IRQHandler(&hfdcan2);
// }

// void EXTI9_5_IRQHandler(void)
// {
//   HAL_GPIO_EXTI_IRQHandler(SPI1_DRDY2_BMI055_GYRO_Pin);
//   HAL_GPIO_EXTI_IRQHandler(SPI1_DRDY3_ICM42688_Pin);
// }

// void TIM1_UP_IRQHandler(void)
// {
//   HAL_TIM_IRQHandler(&htim1);
// }

// void TIM3_IRQHandler(void)
// {
//   HAL_TIM_IRQHandler(&htim3);
// }

// void TIM4_IRQHandler(void)
// {
//   HAL_TIM_IRQHandler(&htim4);
// }

// void I2C1_EV_IRQHandler(void)
// {
//   HAL_I2C_EV_IRQHandler(&hi2c1);
// }

// void I2C2_EV_IRQHandler(void)
// {
//   HAL_I2C_EV_IRQHandler(&hi2c2);
// }

// void SPI1_IRQHandler(void)
// {
//   HAL_SPI_IRQHandler(&hspi1);
// }

// void SPI2_IRQHandler(void)
// {
//   HAL_SPI_IRQHandler(&hspi2);
// }

// void USART1_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart1);
// }

// void USART2_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart2);
// }

// void USART3_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart3);
// }

// void TIM5_IRQHandler(void)
// {
//   HAL_TIM_IRQHandler(&htim5);
// }

// void UART5_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart5);
// }

// void TIM6_DAC_IRQHandler(void)
// {
//   HAL_TIM_IRQHandler(&htim6);
// }

// void DMA2_Stream0_IRQHandler(void)
// {
//   HAL_DMA_IRQHandler(&hdma_adc1);
// }

// void USART6_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart6);
// }

// void UART7_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart7);
// }

// void UART8_IRQHandler(void)
// {
//   HAL_UART_IRQHandler(&huart8);
// }

// void I2C4_EV_IRQHandler(void)
// {
//   HAL_I2C_EV_IRQHandler(&hi2c4);
// }

// void OTG_FS_IRQHandler(void)
// {
//   HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
// }

// void TIM17_IRQHandler(void)
// {
//   HAL_TIM_IRQHandler(&htim17);
// }

void SDMMC2_IRQHandler(void)
{
  HAL_SD_IRQHandler(&hsd2);
}

// void ADC3_IRQHandler(void)
// {
//   HAL_ADC_IRQHandler(&hadc3);
// }

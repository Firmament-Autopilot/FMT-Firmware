/**
  ******************************************************************************
  * @file    stm32h7xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32H7xx_IT_H
#define __STM32H7xx_IT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported functions prototypes ---------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI4_IRQHandler(void);
void DMA1_Stream0_IRQHandler(void);
void DMA1_Stream1_IRQHandler(void);
void DMA1_Stream2_IRQHandler(void);
void DMA1_Stream3_IRQHandler(void);
void ADC_IRQHandler(void);
void FDCAN1_IT0_IRQHandler(void);
void FDCAN2_IT0_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void TIM1_UP_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void I2C1_EV_IRQHandler(void);
void I2C2_EV_IRQHandler(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void TIM5_IRQHandler(void);
void UART5_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void DMA2_Stream0_IRQHandler(void);
void USART6_IRQHandler(void);
void UART7_IRQHandler(void);
void UART8_IRQHandler(void);
void I2C4_EV_IRQHandler(void);
void OTG_FS_IRQHandler(void);
void TIM17_IRQHandler(void);
void SDMMC2_IRQHandler(void);
void ADC3_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32H7xx_IT_H */

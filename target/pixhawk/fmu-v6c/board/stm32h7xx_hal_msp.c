
#include <firmament.h>
#include "board.h"
#include "stm32h7xx_hal.h"

/**
  * @brief UART MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  *           - NVIC configuration for UART interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* Console UART (USART3) */
  if(huart->Instance == USART3)
  {
    /* Enable GPIO TX/RX clock */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    
    /* Enable USART3 clock */
    __HAL_RCC_USART3_CLK_ENABLE();

    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_8; // PD8
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_9; // PD9
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* NVIC for USART, to support Interrupt mode */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 1);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  }
  
  /* GPS1 UART (USART1) */
  else if(huart->Instance == USART1)
  {
    /* Enable GPIO TX/RX clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    /* Enable USART1 clock */
    __HAL_RCC_USART1_CLK_ENABLE();

    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_9; // PA9
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_10; // PA10
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* NVIC for USART */
    HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  }
  // Add other UARTs (UART7, UART8, UART5) as needed
}

/**
  * @brief SPI MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param hspi: SPI handle pointer
  * @retval None
  */
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* SPI1 (Sensors) */
  if(hspi->Instance == SPI1)
  {
    /* Enable GPIO clock */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    /* Enable SPI1 clock */
    __HAL_RCC_SPI1_CLK_ENABLE();

    /* SPI1 GPIO Configuration 
       PA5     ------> SPI1_SCK
       PA6     ------> SPI1_MISO
       PA7     ------> SPI1_MOSI 
    */
    GPIO_InitStruct.Pin       = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  }
  /* SPI2 (FRAM) */
  else if(hspi->Instance == SPI2)
  {
    /* Enable GPIO clock */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    /* Enable SPI2 clock */
    __HAL_RCC_SPI2_CLK_ENABLE();

    /* SPI2 GPIO Configuration 
       PB13     ------> SPI2_SCK
       PB14     ------> SPI2_MISO
       PB15     ------> SPI2_MOSI 
       (Compatible with typical H7 pinout, assuming standard unless defined otherwise)
    */
    GPIO_InitStruct.Pin       = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  }
}

/**
  * @brief I2C MSP Initialization 
  *        This function configures the hardware resources used in this example: 
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration  
  * @param hi2c: I2C handle pointer
  * @retval None
  */
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /* I2C4 (Baro/Mag) */
  if(hi2c->Instance == I2C4)
  {
    /* Enable GPIO clock */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    
    /* Enable I2C4 clock */
    __HAL_RCC_I2C4_CLK_ENABLE();

    /* I2C4 GPIO Configuration 
       PD12     ------> I2C4_SCL
       PD13     ------> I2C4_SDA 
    */
    GPIO_InitStruct.Pin       = GPIO_PIN_12 | GPIO_PIN_13;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C4;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
  }
}

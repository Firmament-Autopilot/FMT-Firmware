/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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
#include <firmament.h>

#include "driver/usart.h"
#include "hal/serial.h"

void Error_Handler(void);

/* STM32 uart driver */
struct stm32_uart {
    USART_TypeDef* uart_device;
    IRQn_Type irq;
    struct stm32_uart_dma {
        /* rx dma stream */
        DMA_Stream_TypeDef* rx_stream;
        /* dma channel */
        uint32_t rx_ch;
        /* dma flag */
        uint32_t rx_flag;
        /* dma irq channel */
        uint8_t rx_irq_ch;
        /* setting receive len */
        rt_size_t setting_recv_len;
        /* last receive index */
        rt_size_t last_recv_index;
        /* tx dma stream */
        DMA_Stream_TypeDef* tx_stream;
        /* dma channel */
        uint32_t tx_ch;
        /* dma flag */
        uint32_t tx_flag;
        /* dma irq channel */
        uint8_t tx_irq_ch;
    } dma;
};

static rt_err_t usart_configure(struct serial_device* serial, struct serial_configure* cfg)
{
    return RT_EOK;
}

static rt_err_t usart_control(struct serial_device* serial, int cmd, void* arg)
{
    return RT_EOK;
}

static int usart_putc(struct serial_device* serial, char c)
{
    struct stm32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    /* wait transmit register become empty */
    while (!(uart->uart_device->ISR & USART_FLAG_TXE))
        ;

    uart->uart_device->TDR = c;

    return 1;
}

static int usart_getc(struct serial_device* serial)
{
    int ch = -1;
    struct stm32_uart* uart;

    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart*)serial->parent.user_data;

    /* check if read data register is not empty */
    if (uart->uart_device->ISR & USART_FLAG_RXNE) {
        /* read DR will clear RXNE */
        ch = uart->uart_device->RDR & 0xff;
    }

    return ch;
}

/* usart driver operations */
// static const struct usart_ops _usart_ops = {
//     usart_configure,
//     usart_control,
//     usart_putc,
//     usart_getc,
//     RT_NULL
// };

UART_HandleTypeDef huart7;
UART_HandleTypeDef huart2;

/* UART7 init function */
void MX_UART7_Init(void)
{

    huart7.Instance = UART7;
    huart7.Init.BaudRate = 115200;
    huart7.Init.WordLength = UART_WORDLENGTH_8B;
    huart7.Init.StopBits = UART_STOPBITS_1;
    huart7.Init.Parity = UART_PARITY_NONE;
    huart7.Init.Mode = UART_MODE_TX_RX;
    huart7.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart7.Init.OverSampling = UART_OVERSAMPLING_16;
    huart7.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart7.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_DMADISABLEONERROR_INIT;
    huart7.AdvancedInit.DMADisableonRxError = UART_ADVFEATURE_DMA_DISABLEONRXERROR;
    if (HAL_UART_Init(&huart7) != HAL_OK) {
        Error_Handler();
    }
}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&huart2) != HAL_OK) {
        Error_Handler();
    }
}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = { 0 };
    if (uartHandle->Instance == UART7) {
        /* USER CODE BEGIN UART7_MspInit 0 */

        /* USER CODE END UART7_MspInit 0 */
        /* UART7 clock enable */
        __HAL_RCC_UART7_CLK_ENABLE();

        __HAL_RCC_GPIOF_CLK_ENABLE();
        __HAL_RCC_GPIOE_CLK_ENABLE();
        /**UART7 GPIO Configuration
    PF6     ------> UART7_RX
    PE8     ------> UART7_TX
    */
        GPIO_InitStruct.Pin = GPIO_PIN_6;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
        HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_8;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
        HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

        /* UART7 interrupt Init */
        HAL_NVIC_SetPriority(UART7_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(UART7_IRQn);
        /* USER CODE BEGIN UART7_MspInit 1 */

        /* USER CODE END UART7_MspInit 1 */
    } else if (uartHandle->Instance == USART2) {
        /* USER CODE BEGIN USART2_MspInit 0 */

        /* USER CODE END USART2_MspInit 0 */
        /* USART2 clock enable */
        __HAL_RCC_USART2_CLK_ENABLE();

        __HAL_RCC_GPIOD_CLK_ENABLE();
        /**USART2 GPIO Configuration
    PD6     ------> USART2_RX
    PD5     ------> USART2_TX
    */
        GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_5;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /* USER CODE BEGIN USART2_MspInit 1 */

        /* USER CODE END USART2_MspInit 1 */
    }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

    if (uartHandle->Instance == UART7) {
        /* USER CODE BEGIN UART7_MspDeInit 0 */

        /* USER CODE END UART7_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_UART7_CLK_DISABLE();

        /**UART7 GPIO Configuration
    PF6     ------> UART7_RX
    PE8     ------> UART7_TX
    */
        HAL_GPIO_DeInit(GPIOF, GPIO_PIN_6);

        HAL_GPIO_DeInit(GPIOE, GPIO_PIN_8);

        /* UART7 interrupt Deinit */
        HAL_NVIC_DisableIRQ(UART7_IRQn);
        /* USER CODE BEGIN UART7_MspDeInit 1 */

        /* USER CODE END UART7_MspDeInit 1 */
    } else if (uartHandle->Instance == USART2) {
        /* USER CODE BEGIN USART2_MspDeInit 0 */

        /* USER CODE END USART2_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_USART2_CLK_DISABLE();

        /**USART2 GPIO Configuration
    PD6     ------> USART2_RX
    PD5     ------> USART2_TX
    */
        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_6 | GPIO_PIN_5);

        /* USER CODE BEGIN USART2_MspDeInit 1 */

        /* USER CODE END USART2_MspDeInit 1 */
    }
}

rt_err_t usart_drv_init(void)
{
    rt_err_t rt_err = RT_EOK;
    // struct serial_configure config = SERIAL_DEFAULT_CONFIG;
    // rt_uint32_t flag = RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_STANDALONE | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_DMA_RX | RT_DEVICE_FLAG_DMA_TX;

    MX_UART7_Init();
    MX_USART2_UART_Init();

    /* register UART1 device */
    // serial1.ops = &_usart_ops;
    // serial1.config = config;
    // rt_err |= hal_serial_register(&serial1,
    //     "serial1",
    //     flag,
    //     &uart2);

    return rt_err;
}
// INIT_BOARD_EXPORT(usart_drv_init);

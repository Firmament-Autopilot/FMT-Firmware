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

#include "usart.h"
#include "debug.h"
#include <stdio.h>

RING_BUFFER_Def rb;

uint8_t send_ch(uint8_t ch)
{
    USART_SendData(USART2, (uint8_t)ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
        ;

    return ch;
}

uint16_t send(uint8_t* data, uint16_t len)
{
    uint16_t i;

    for (i = 0; i < len; i++) {
        send_ch(data[i]);
    }

    return len;
}

uint8_t read_ch(uint8_t* ch)
{
    if (rb.head != rb.tail) {
        *ch = rb.buff[rb.tail];
        rb.tail = (rb.tail + 1) % RING_BUFFER_SIZE;
        return 1;
    }

    return 0;
}

uint8_t usart_config_baud_rate(USART_TypeDef* USARTx, uint32_t baud_rate)
{
    USART_InitTypeDef USART_InitStructure;

    USART_InitStructure.USART_BaudRate = baud_rate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USARTx, &USART_InitStructure);

    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);

    /* Enable USART */
    USART_Cmd(USARTx, ENABLE);
}

uint8_t usart_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /*init ring budder*/
    rb.head = rb.tail = 0;

    /* Enable Clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    /* Configure the NVIC Preemption Priority Bits */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    /* Enable the USART2 Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* Configure USART Rx as input floating */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 230400;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART2, &USART_InitStructure);

    /* Enable USART2 Receive interrupts */
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

    /* Enable USART */
    USART_Cmd(USART2, ENABLE);

    /* Config USART1 for debug */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* Configure USART Rx as input pull up, 
     * because input floating will result in unstable voltage level if sbus cable is not connected */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);

    /* Enable USART */
    USART_Cmd(USART1, ENABLE);

    return 1;
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
int fputc(int ch, FILE* f)
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the USART */
    USART_SendData(USART1, (uint8_t)ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) { }

    return ch;
}

void console_putc(uint8_t ch)
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the USART */
    USART_SendData(USART1, (uint8_t)ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) { }
}

void USART2_irq_event_handler(void)
{
    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) {
        rb.buff[rb.head] = USART_ReceiveData(USART2); /* this process will clear EXNE flag */
        rb.head = (rb.head + 1) % RING_BUFFER_SIZE;

        // if(rb.head == rb.tail)
        // 	debug("ring buffer is full\n");
    }
}

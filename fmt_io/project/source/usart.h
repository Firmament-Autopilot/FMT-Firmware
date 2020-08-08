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

#ifndef _USART_H_
#define _USART_H_

#include "stm32f10x.h"

#define RING_BUFFER_SIZE 2048

typedef struct {
    uint16_t head;
    uint16_t tail;
    uint8_t buff[RING_BUFFER_SIZE];
} RING_BUFFER_Def;

uint8_t usart_config_baud_rate(USART_TypeDef* USARTx, uint32_t baud_rate);
uint8_t usart_init(void);
uint8_t read_ch(uint8_t* ch);
uint8_t send_ch(uint8_t ch);
uint16_t send(uint8_t* data, uint16_t len);
void console_putc(uint8_t ch);

#endif

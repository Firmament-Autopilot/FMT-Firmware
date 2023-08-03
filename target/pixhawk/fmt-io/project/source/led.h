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

#ifndef  _LED_H_
#define  _LED_H_

#include "stm32f10x.h"
#include "board_config.h"

#ifdef CUBEPILOT

#define LED_PORT		GPIOB
#define LED_BLUE_PIN	GPIO_Pin_13
#define LED_RED_PIN		GPIO_Pin_15
#define LED_RCC			RCC_APB2Periph_GPIOB

#else 

#define LED_PORT		GPIOB
#define LED_BLUE_PIN	GPIO_Pin_14
#define LED_RED_PIN		GPIO_Pin_15
#define LED_RCC			RCC_APB2Periph_GPIOB

#endif
typedef enum {
	LED_RED = 0,
	LED_BLUE
} LED_Type;

void led_on(LED_Type led);
void led_off(LED_Type led);
void led_toggle(LED_Type led);
void led_init(void);

#endif

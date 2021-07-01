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

#include "led.h"

uint8_t led_status[2];

void led_on(LED_Type led)
{
	if(led == LED_RED) {
		GPIO_ResetBits(LED_PORT, LED_RED_PIN);
		led_status[LED_RED] = 1;
	} else {
		GPIO_ResetBits(LED_PORT, LED_BLUE_PIN);
		led_status[LED_BLUE] = 1;
	}
}

void led_off(LED_Type led)
{
	if(led == LED_RED) {
		GPIO_SetBits(LED_PORT, LED_RED_PIN);
		led_status[LED_RED] = 0;
	} else {
		GPIO_SetBits(LED_PORT, LED_BLUE_PIN);
		led_status[LED_BLUE] = 0;
	}
}

void led_toggle(LED_Type led)
{
	if(led_status[led])
		led_off(led);
	else
		led_on(led);
}

void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOD Periph clock enable */
	RCC_APB2PeriphClockCmd(LED_RCC, ENABLE);

	/* Configure PD0 and PD2 in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = LED_RED_PIN | LED_BLUE_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);

	led_off(LED_RED);
	led_off(LED_BLUE);
}

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

#include "lidar_lite.h"
#include "protocol.h"

static float _lidar_max_measured_alt = 5.0f;

typedef enum {
	Edge_Rising = 0,
	Edge_Falling,
} WaitingEdge;

/* 1us accuracy */
#define LIDAR_LITE_FREQ 		1000000

uint16_t IC_RisingVal;
uint16_t IC_FallingVal;
WaitingEdge _wait;
static uint8_t _received;
static float distance;	// meter

void TIM3_irq_event_handler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_CC1) == SET) {
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);

		IC_RisingVal = TIM_GetCapture1(TIM3);

		_wait = Edge_Falling;
	}

	if(TIM_GetITStatus(TIM3, TIM_IT_CC2) == SET) {
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);

		if(_wait != Edge_Falling)
			return;

		IC_FallingVal = TIM_GetCapture2(TIM3);

		/* pulse width in us */
		uint16_t pulse_width = IC_FallingVal > IC_RisingVal ? (IC_FallingVal - IC_RisingVal) : (0xFFFF - IC_RisingVal + IC_FallingVal);
		/* round to 10us */
		pulse_width = (pulse_width + 5) / 10 * 10;
		/* calculate distance in meter, 10us/cm */
		distance = (float)pulse_width * 0.001f;

		_wait = Edge_Rising;

		if(distance < _lidar_max_measured_alt)
			_received = 1;
	}
}

uint8_t lidar_lite_ready(void)
{
	return _received;
}

void lidar_lite_clear_ready(void)
{
	_received = 0;
}

uint8_t send_lidar_distance(void)
{
	__set_PRIMASK(1); //disable interrupt
	float dis = distance;
	__set_PRIMASK(0); //enable interrupt

	//return send_package(CMD_LIDAR_DIS , (uint8_t*)&dis , sizeof(dis));
	return 0;
}

uint8_t lidar_lite_init(void)
{
	/* TIM3 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/* GPIOB clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	/* TIM3 channel 1 pin (PA.06) configuration */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	NVIC_InitTypeDef NVIC_InitStructure;
	/* Enable the TIM3 global Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	/* highest priority */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* TIM3 configuration: Input Capture mode ---------------------
	 The external signal is connected to TIM3 CH4 pin (PB.01)
	 The Rising edge is used as active edge,
	 The TIM3 CCR4 is used to compute the frequency value
	------------------------------------------------------------ */
	TIM_ICInitTypeDef  TIM_ICInitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

	/* Time Base configuration */
	TIM_TimeBaseStructure.TIM_Prescaler = SystemCoreClock / LIDAR_LITE_FREQ;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 0xFFFF;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICFilter = 0x1;	/* do filter */
	/* only channel 1 and channel 2 of Timer can be configured as PWM input mode */
	/* if channel 1 is configured as rising capture, then channel 2 will be configured as falling capture automatically */
	TIM_PWMIConfig(TIM3, &TIM_ICInitStructure);

	/* TIM enable counter */
	TIM_Cmd(TIM3, ENABLE);
	/* Enable the CC2 Interrupt Request */
	TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);

	_wait = Edge_Rising;
	_received = 0;

	return 1;
}

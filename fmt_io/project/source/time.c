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

#include "time.h"
#include <stdio.h>

static struct {
	volatile uint32_t msPeriod;    // 整周期的时间，ms。
	uint32_t ticksPerUs;  // 每us等于的tick数。
	uint32_t ticksPerMs;  // 每ms等于的tick数。
	uint32_t msPerPeriod; // 每周期的ms数。
} time;

// 初始化时间。
void time_init(void)
{
	time.msPeriod = 0;  // 整周期的时间，ms。
	time.ticksPerUs = SystemCoreClock / 1e6;    // 每us等于的tick数。24M/10e6=24
	time.ticksPerMs = SystemCoreClock / 1e3;    //24000
	time.msPerPeriod = 10;  //每周期ms数为10
	//
	//Systick中断优先级较低，所以在优先级比Systick高的中断中获取时间时，可能Systick时间还未更新
	SysTick_Config(SystemCoreClock / (1000 / time.msPerPeriod)); //初始化systick周期为msPerPeriod
}

//SysTick中断。
void SysTick_Handler(void)
{
//    printf("systick_IRQ\r\n");
	time.msPeriod += time.msPerPeriod;
}

// 获取当前时间，us。
uint64_t time_nowUs(void)
{
	return time.msPeriod * (uint64_t)1000 + (SysTick->LOAD - SysTick->VAL) / time.ticksPerUs;
}

// 获取当前时间，ms。
uint32_t time_nowMs(void)
{
	return time.msPeriod + (SysTick->LOAD - SysTick->VAL) / time.ticksPerMs;
}

// 延时delay us，delay>=4时才准确。
void time_waitUs(uint32_t delay)
{
	uint64_t target = time_nowUs() + delay - 2;

	while(time_nowUs() <= target)
		; // 空循环。
}

// 延时delay ms。
void time_waitMs(uint32_t delay)
{
	time_waitUs(delay * 1000);
}

uint8_t check_timetag(TimeTag* timetag)
{
	uint32_t now = time_nowMs();

	if(now - timetag->tag >= timetag->period) {
		timetag->tag = now;

		return 1;
	}

	return 0;
}

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

#include "module/system/systime.h"
#include "hal/systick.h"

typedef struct {
	volatile uint32_t msPeriod;		/* current time in ms */
	uint32_t msPerPeriod; 			/* ms count for each period (SysTick_Handler fire) */
} systime_t;

static systime_t _systime;
static rt_device_t _systick_dev;

static void systick_isr_cb(void)
{
	_systime.msPeriod += _systime.msPerPeriod;
}

uint8_t check_timetag(TimeTag* timetag)
{
	uint32_t now = systime_now_ms();

	if(now - timetag->tag >= timetag->period) {
		timetag->tag = now;

		return 1;
	}

	return 0;
}

uint8_t check_timetag2(TimeTag* timetag, uint32_t now)
{
	if(now - timetag->tag >= timetag->period) {
		timetag->tag = now;

		return 1;
	}

	return 0;
}

uint8_t check_timetag3(TimeTag* timetag, uint32_t now, uint32_t period)
{
	if(now - timetag->tag >= period) {
		timetag->tag = now;

		return 1;
	}

	return 0;
}

uint64_t systime_now_us(void)
{
	uint32_t systick_us;

	rt_device_read(_systick_dev, SYSTICK_RD_TIME_US, &systick_us, sizeof(uint32_t));

	return _systime.msPeriod * (uint64_t)1000 + systick_us;
}

uint32_t systime_now_ms(void)
{
	uint32_t systick_us;

	rt_device_read(_systick_dev, SYSTICK_RD_TIME_US, &systick_us, sizeof(uint32_t));

	return _systime.msPeriod + systick_us / 1e3;
}

void systime_delay_us(uint32_t time_us)
{
	uint64_t target = systime_now_us() + time_us;

	while(systime_now_us() < target)
		;
}

void systime_delay_ms(uint32_t time_ms)
{
	systime_delay_us(time_ms * 1000);
}

uint8_t systime_init(void)
{
	systick_dev_t systick_device;

	_systick_dev = rt_device_find("systick");

	if(_systick_dev == RT_NULL) {
		return FMT_ERROR;
	}

	rt_device_open(_systick_dev, RT_DEVICE_FLAG_RDONLY);

	systick_device = (systick_dev_t)_systick_dev;

	_systime.msPeriod = 0;
	_systime.msPerPeriod = systick_device->ticks_per_isr / systick_device->ticks_per_us / 1e3;

	systick_device->systick_isr_cb = systick_isr_cb;

	return FMT_EOK;
}

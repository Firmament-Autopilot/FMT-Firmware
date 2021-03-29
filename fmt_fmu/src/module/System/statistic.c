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

#include "module/system/statistic.h"
#include "module/system/systime.h"
#include "module/console/console.h"

#define CPU_USAGE_CALC_TICK		10
#define CPU_USAGE_LOOP			100

static float _cpu_usage = 0;
static rt_uint32_t total_count = 0;

static void cpu_usage_idle_hook()
{
	rt_tick_t tick;
	rt_uint32_t count;
	volatile rt_uint32_t loop;

	if (total_count == 0)
	{
		loop = 0;
		
		/* get total count */
		rt_enter_critical();
		tick = rt_tick_get();
		while(rt_tick_get() - tick < CPU_USAGE_CALC_TICK)
		{
			total_count ++;
			while (loop < CPU_USAGE_LOOP) loop ++;
		}
		rt_exit_critical();
	}

	count = 0;
	loop  = 0;
	/* get CPU usage */
	tick = rt_tick_get();
	while (rt_tick_get() - tick < CPU_USAGE_CALC_TICK)
	{
		count ++;
		while (loop < CPU_USAGE_LOOP) loop ++;
	}

	/* calculate major and minor */
	if (count < total_count)
	{
		_cpu_usage = 100.0f - ((float)count / (float)total_count) * 100.0f;
	}
	else
	{
		total_count = count;
	}
}

float sysstat_get_cpu_usage(void)
{
	return _cpu_usage;
}

rt_err_t sys_stat_init(void)
{
	rt_thread_idle_sethook(cpu_usage_idle_hook);

	return FMT_EOK;
}
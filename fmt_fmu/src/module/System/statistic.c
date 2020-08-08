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

/* calculate CPU usage each 500ms */
#define OS_STATISTIC_INTERVAL		500

static uint64_t _os_idle_ctr = 0;
static uint64_t _os_ctr_max = 1;
static float _cpu_usage = 0;

static struct rt_timer timer_sta;

void _thread_idle_hook_func(void)
{
	OS_ENTER_CRITICAL;
	_os_idle_ctr++;
	OS_EXIT_CRITICAL;
}

static void timer_stat_entry(void* parameter)
{
	/* calculate cpu usage */
	OS_ENTER_CRITICAL;
	float usage = 100.0 * (1.0 - ((double)_os_idle_ctr) / _os_ctr_max);

	/* some time the timer could be not accurate, which will generate some wrong usage. so filter it */
	if(usage > 0.0f && usage < 100.0f)
		_cpu_usage = usage;

	_os_idle_ctr = 0;
	OS_EXIT_CRITICAL;
}

float sysstat_get_cpu_usage(void)
{
	return _cpu_usage;
}

void sys_stat_init(void)
{
	_os_idle_ctr = 0;

	/* we increment idle counter in idle thread */
	rt_thread_idle_sethook(_thread_idle_hook_func);

	/* suspend current thread and let idle thread wakeup to count the maximal value of counter */
	rt_thread_delay(OS_STATISTIC_INTERVAL);
	_os_ctr_max = _os_idle_ctr;
	_os_idle_ctr = 0;

	/* register a timer event to calculate CPU usage */
	rt_timer_init(&timer_sta, "timer_sta",
	              timer_stat_entry,
	              RT_NULL,
	              OS_STATISTIC_INTERVAL,
	              RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);
	rt_timer_start(&timer_sta);
}

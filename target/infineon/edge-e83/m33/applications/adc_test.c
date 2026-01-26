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

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define ADC_DEV_NAME "adc1"
#define ADC_DEV_CHANNEL 0

rt_adc_device_t adc_dev;
rt_uint32_t value, mv, v, mv_frac;

static rt_thread_t adc_test_tid = RT_NULL;

static void adc_test_entry(void* parameter) {
  adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
  if (adc_dev == RT_NULL) {
    rt_kprintf("adc sample run failed! can't find %s device!\n", ADC_DEV_NAME);
    return;
  }

  rt_adc_enable(adc_dev, ADC_DEV_CHANNEL);
  while (1) {
    value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);
    rt_kprintf("Value is: %d \n", value);
    rt_thread_mdelay(1000);
  }
}

static int adc_test_entry_init(void) {
  adc_test_tid = rt_thread_create("adc_test_thread", adc_test_entry,
                                  (void*)0x01,  // Default parameter
                                  2048,         // Stack size
                                  15,           // Priority
                                  5             // Time slice
  );

  if (RT_NULL == adc_test_tid) {
    rt_kprintf("[%s] Create failed!\n", __FUNCTION__);
    return -RT_ENOMEM;
  }

  if (RT_EOK != rt_thread_startup(adc_test_tid)) {
    rt_kprintf("[%s] Startup failed!\n", __FUNCTION__);
    return -RT_ERROR;
  }

  rt_kprintf("[%s] Created successfully\n", __FUNCTION__);
  return RT_EOK;
}

MSH_CMD_EXPORT(adc_test_entry_init, adc_test thread demo);
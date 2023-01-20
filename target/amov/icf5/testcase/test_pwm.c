/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
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
#include <utest.h>

MCN_DECLARE(control_output);

static void test_unit_1(void)
{
    rt_device_t dev = NULL;
    uint16_t chan_val[10] = { 0 };
    uint16_t pwm_value = 0;
    uint16_t inc_value;

    dev = rt_device_find("main_out");
    uassert_not_null(dev);

    for (int i = 0; i < 10; i++) {
        chan_val[i] = 1000;
    }

    while (1) {
        if (pwm_value == 0) {
            pwm_value = 1000;
            inc_value = 50;
        }

        if (pwm_value >= 2000) {
            inc_value = -50;
        }

        for (int i = 0; i < 10; i++) {
            chan_val[i] = pwm_value;
        }

        uassert_true(rt_device_write(dev, 0x3FF, chan_val, 10) == 10);

        pwm_value += inc_value;

        if (pwm_value <= 1000) {
            break;
        }

        systime_msleep(100);
    }
}

static rt_err_t testcase_init(void)
{
    mcn_suspend(MCN_HUB(control_output));
    return RT_EOK;
}

static rt_err_t testcase_cleanup(void)
{
    mcn_resume(MCN_HUB(control_output));
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_unit_1);
}
UTEST_TC_EXPORT(testcase, "utest.interface.pwm", testcase_init, testcase_cleanup, 50000);
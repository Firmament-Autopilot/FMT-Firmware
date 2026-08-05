#include "hal/actuator/actuator.h"
#include <rtdevice.h>
#include <rtthread.h>
#include <stdlib.h>

#ifdef RT_USING_FINSH
    #include <finsh.h>
#endif

#define PWM_TEST_MAIN_CHAN 8U
#define PWM_TEST_AUX_CHAN  8U
#define PWM_TEST_TOTAL_CHAN (PWM_TEST_MAIN_CHAN + PWM_TEST_AUX_CHAN)
#define PWM_TEST_MIN_US    1000U
#define PWM_TEST_MAX_US    2000U
#define PWM_TEST_PATTERN_STEP_US 60U

static rt_device_t pwm_main_dev = RT_NULL;
static rt_device_t pwm_aux_dev = RT_NULL;
static rt_bool_t pwm_test_opened = RT_FALSE;

static rt_bool_t pwm_test_is_pulse_valid(rt_uint16_t pulse_us)
{
    return (pulse_us >= PWM_TEST_MIN_US) && (pulse_us <= PWM_TEST_MAX_US);
}

static rt_uint16_t pwm_test_pattern_us(uint8_t pwm_ch)
{
    /* Give each channel a unique pulse width so scope checks can spot coupling easily. */
    return (rt_uint16_t)(PWM_TEST_MIN_US + (rt_uint16_t)pwm_ch * PWM_TEST_PATTERN_STEP_US);
}

static rt_err_t pwm_test_open_devices(void)
{
    rt_bool_t has_device = RT_FALSE;

    if (pwm_test_opened) {
        return RT_EOK;
    }

    pwm_main_dev = rt_device_find("main_out");
    pwm_aux_dev = rt_device_find("aux_out");

    if (pwm_main_dev == RT_NULL && pwm_aux_dev == RT_NULL) {
        rt_kprintf("PWM device not found: main_out=%p aux_out=%p\n", pwm_main_dev, pwm_aux_dev);
        pwm_main_dev = RT_NULL;
        pwm_aux_dev = RT_NULL;
        return -RT_ERROR;
    }

    if (pwm_main_dev != RT_NULL) {
        if (rt_device_open(pwm_main_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
            rt_kprintf("open main_out failed\n");
            pwm_main_dev = RT_NULL;
        } else {
            has_device = RT_TRUE;
        }
    }

    if (pwm_aux_dev != RT_NULL) {
        if (rt_device_open(pwm_aux_dev, RT_DEVICE_OFLAG_RDWR) != RT_EOK) {
            rt_kprintf("open aux_out failed\n");
            pwm_aux_dev = RT_NULL;
        } else {
            has_device = RT_TRUE;
        }
    }

    if (!has_device) {
        if (pwm_main_dev != RT_NULL) {
            rt_device_close(pwm_main_dev);
        }
        if (pwm_aux_dev != RT_NULL) {
            rt_device_close(pwm_aux_dev);
        }
        pwm_main_dev = RT_NULL;
        pwm_aux_dev = RT_NULL;
        return -RT_ERROR;
    }

    pwm_test_opened = RT_TRUE;
    rt_kprintf("PWM devices opened: main_out=%s aux_out=%s\n",
               (pwm_main_dev != RT_NULL) ? "ready(1-8)" : "not-ready",
               (pwm_aux_dev != RT_NULL) ? "ready(9-16)" : "not-ready");

    return RT_EOK;
}

void pwm_test_stop(void)
{
    if (!pwm_test_opened) {
        rt_kprintf("PWM test is not running\n");
        return;
    }

    if (pwm_main_dev != RT_NULL) {
        rt_device_close(pwm_main_dev);
    }
    if (pwm_aux_dev != RT_NULL) {
        rt_device_close(pwm_aux_dev);
    }

    pwm_main_dev = RT_NULL;
    pwm_aux_dev = RT_NULL;
    pwm_test_opened = RT_FALSE;

    rt_kprintf("PWM devices closed\n");
}

static rt_err_t pwm_test_write_all(rt_uint16_t pulse_us)
{
    rt_uint16_t main_vals[PWM_TEST_MAIN_CHAN];
    rt_uint16_t aux_vals[PWM_TEST_AUX_CHAN];

    if (!pwm_test_is_pulse_valid(pulse_us)) {
        rt_kprintf("invalid pulse: %u us, range %u-%u us\n", pulse_us, PWM_TEST_MIN_US, PWM_TEST_MAX_US);
        return -RT_EINVAL;
    }

    for (uint8_t i = 0; i < PWM_TEST_MAIN_CHAN; i++) {
        main_vals[i] = pulse_us;
    }
    for (uint8_t i = 0; i < PWM_TEST_AUX_CHAN; i++) {
        aux_vals[i] = pulse_us;
    }

    if (pwm_main_dev != RT_NULL) {
        if (rt_device_write(pwm_main_dev, 0x00FFU, main_vals, PWM_TEST_MAIN_CHAN) != PWM_TEST_MAIN_CHAN) {
            rt_kprintf("write main_out failed\n");
            return -RT_ERROR;
        }
    }

    if (pwm_aux_dev != RT_NULL) {
        if (rt_device_write(pwm_aux_dev, 0x00FFU, aux_vals, PWM_TEST_AUX_CHAN) != PWM_TEST_AUX_CHAN) {
            rt_kprintf("write aux_out failed\n");
            return -RT_ERROR;
        }
    }

    return RT_EOK;
}

static rt_err_t pwm_test_write_one(uint8_t pwm_ch, rt_uint16_t pulse_us)
{
    rt_uint16_t val = pulse_us;

    if (pwm_ch < 1U || pwm_ch > PWM_TEST_TOTAL_CHAN) {
        rt_kprintf("invalid channel: %u (valid 1-16)\n", pwm_ch);
        return -RT_EINVAL;
    }

    if (!pwm_test_is_pulse_valid(pulse_us)) {
        rt_kprintf("invalid pulse: %u us, range %u-%u us\n", pulse_us, PWM_TEST_MIN_US, PWM_TEST_MAX_US);
        return -RT_EINVAL;
    }

    if (pwm_ch <= PWM_TEST_MAIN_CHAN) {
        uint8_t local_ch = (uint8_t)(pwm_ch - 1U);
        rt_uint16_t mask = (rt_uint16_t)(1U << local_ch);

        if (pwm_main_dev == RT_NULL) {
            rt_kprintf("main_out is not available on this core\n");
            return -RT_ERROR;
        }

        if (rt_device_write(pwm_main_dev, mask, &val, 1) != 1) {
            rt_kprintf("write main_out ch%u failed\n", pwm_ch);
            return -RT_ERROR;
        }
    } else {
        uint8_t local_ch = (uint8_t)(pwm_ch - 1U - PWM_TEST_MAIN_CHAN);
        rt_uint16_t mask = (rt_uint16_t)(1U << local_ch);

        if (pwm_aux_dev == RT_NULL) {
            rt_kprintf("aux_out is not available on this core\n");
            return -RT_ERROR;
        }

        if (rt_device_write(pwm_aux_dev, mask, &val, 1) != 1) {
            rt_kprintf("write aux_out ch%u failed\n", pwm_ch);
            return -RT_ERROR;
        }
    }

    return RT_EOK;
}

void pwm_test(void)
{
    rt_uint16_t main_vals[PWM_TEST_MAIN_CHAN];
    rt_uint16_t aux_vals[PWM_TEST_AUX_CHAN];

    if (pwm_test_open_devices() != RT_EOK) {
        return;
    }

    for (uint8_t i = 0; i < PWM_TEST_MAIN_CHAN; i++) {
        main_vals[i] = pwm_test_pattern_us((uint8_t)(i + 1U));
    }
    for (uint8_t i = 0; i < PWM_TEST_AUX_CHAN; i++) {
        aux_vals[i] = pwm_test_pattern_us((uint8_t)(i + 1U + PWM_TEST_MAIN_CHAN));
    }

    if (pwm_main_dev != RT_NULL) {
        if (rt_device_write(pwm_main_dev, 0x00FFU, main_vals, PWM_TEST_MAIN_CHAN) != PWM_TEST_MAIN_CHAN) {
            rt_kprintf("write main_out failed\n");
            return;
        }
    }
    if (pwm_aux_dev != RT_NULL) {
        if (rt_device_write(pwm_aux_dev, 0x00FFU, aux_vals, PWM_TEST_AUX_CHAN) != PWM_TEST_AUX_CHAN) {
            rt_kprintf("write aux_out failed\n");
            return;
        }
    }

    rt_kprintf("=== PWM test started ===\n");
    if (pwm_main_dev != RT_NULL) {
        for (uint8_t i = 0; i < PWM_TEST_MAIN_CHAN; i++) {
            rt_kprintf("  PWM_CH%-2u -> %u us\n", (unsigned)(i + 1U), (unsigned)main_vals[i]);
        }
    }
    if (pwm_aux_dev != RT_NULL) {
        for (uint8_t i = 0; i < PWM_TEST_AUX_CHAN; i++) {
            rt_kprintf("  PWM_CH%-2u -> %u us\n", (unsigned)(i + 1U + PWM_TEST_MAIN_CHAN), (unsigned)aux_vals[i]);
        }
    }
    rt_kprintf("Each channel uses a different pulse width for independence verification.\n");
    rt_kprintf("Use pwm_all <us> / pwm_set <ch> <us> for debug, pwm_test_stop to close.\n");
}

static void pwm_all(int argc, char** argv)
{
    rt_uint16_t pulse_us;

    if (argc < 2) {
        rt_kprintf("Usage: pwm_all <pulse_us>\n");
        rt_kprintf("  pulse_us range: %u-%u\n", PWM_TEST_MIN_US, PWM_TEST_MAX_US);
        return;
    }

    if (pwm_test_open_devices() != RT_EOK) {
        return;
    }

    pulse_us = (rt_uint16_t)atoi(argv[1]);
    if (pwm_test_write_all(pulse_us) == RT_EOK) {
        rt_kprintf("all PWM channels set to %u us\n", pulse_us);
    }
}

static void pwm_set(int argc, char** argv)
{
    uint8_t pwm_ch;
    rt_uint16_t pulse_us;

    if (argc < 3) {
        rt_kprintf("Usage: pwm_set <channel(1-16)> <pulse_us>\n");
        rt_kprintf("  pulse_us range: %u-%u\n", PWM_TEST_MIN_US, PWM_TEST_MAX_US);
        return;
    }

    if (pwm_test_open_devices() != RT_EOK) {
        return;
    }

    pwm_ch = (uint8_t)atoi(argv[1]);
    pulse_us = (rt_uint16_t)atoi(argv[2]);

    if (pwm_test_write_one(pwm_ch, pulse_us) == RT_EOK) {
        rt_kprintf("PWM_CH%u set to %u us\n", pwm_ch, pulse_us);
    }
}

#ifdef RT_USING_FINSH
MSH_CMD_EXPORT(pwm_test, Start PWM test on available channels and write a debug pattern);
MSH_CMD_EXPORT(pwm_all, Set all PWM channels: pwm_all <pulse_us>);
MSH_CMD_EXPORT(pwm_set, Set one PWM channel: pwm_set <1-16> <pulse_us>);
MSH_CMD_EXPORT(pwm_test_stop, Stop PWM test and close devices);
#endif

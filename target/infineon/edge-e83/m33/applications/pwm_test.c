#include "drv_pwm.h"
#define PWM_DEV_NAME "pwm5"
#define PWM_DEV_CHANNEL 1

struct rt_device_pwm *pwm_dev;

static int pwm_sample(int argc, char *argv[])
{
    rt_uint32_t period, pulse, dir;

    period = 5000000;
    dir = 1;
    pulse = 0;
    struct rt_pwm_configuration config = {0};
    pwm_dev = (struct rt_device_pwm *)rt_device_find(PWM_DEV_NAME);

    if (pwm_dev == RT_NULL)
    {
        rt_kprintf("pwm sample run failed! can't find %s device!\n", PWM_DEV_NAME);
        return -RT_ERROR;
    }

    rt_pwm_set(pwm_dev, PWM_DEV_CHANNEL, period, pulse);
    rt_pwm_enable(pwm_dev, PWM_DEV_CHANNEL);
//    rt_pwm_disable(pwm_dev, PWM_DEV_CHANNEL);
    rt_kprintf("Now PWM[%s] Channel[%d] Period[%d] Pulse[%d]\n", PWM_DEV_NAME, PWM_DEV_CHANNEL, period, pulse);

    while (1)
    {
        rt_thread_mdelay(80);

        if (dir)
        {
            pulse += 50000;
        }
        else
        {
            pulse -= 50000;
        }

        if (pulse >= period)
        {
            dir = 0;
        }

        if (0 == pulse)
        {
            dir = 1;
        }

        rt_pwm_set(pwm_dev, PWM_DEV_CHANNEL, period, pulse);
        rt_device_control((rt_device_t)pwm_dev, PWM_CMD_GET, &config);
        rt_kprintf("period %d pulse %d \r\n", config.period, config.pulse);
    }
}
MSH_CMD_EXPORT(pwm_sample, <pwm0> channel5 sample);

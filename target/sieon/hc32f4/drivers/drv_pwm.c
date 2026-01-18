/******************************************************************************
 * Copyright 2020-2021 The Firmament Authors. All Rights Reserved.
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

#include "hal/actuator/actuator.h"

#define TMRA_UNIT          (CM_TMRA_1)
#define TMRA_PERIPH_CLK    (FCG2_PERIPH_TMRA_1)
#define TMRA_PWMX_CH       (TMRA_CH1)
#define TMRA_PWMY_CH       (TMRA_CH2)

#define TMRA_PWMX_PORT     (GPIO_PORT_A)
#define TMRA_PWMX_PIN      (GPIO_PIN_08)
#define TMRA_PWMX_PIN_FUNC (GPIO_FUNC_4)
#define TMRA_PWMY_PORT     (GPIO_PORT_A)
#define TMRA_PWMY_PIN      (GPIO_PIN_09)
#define TMRA_PWMY_PIN_FUNC (GPIO_FUNC_4)

#define TMRA_MD            (TMRA_MD_SAWTOOTH)
#define TMRA_DIR           (TMRA_DIR_UP)
#define TMRA_PERIOD_VAL    (80U - 1U)
#define TMRA_PWMX_CMP_VAL  (24U - 1U)
#define TMRA_PWMY_CMP_VAL  (44U - 1U)

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define PWM_FREQ_50HZ         (50)
#define PWM_FREQ_125HZ        (125)
#define PWM_FREQ_250HZ        (250)
#define PWM_FREQ_400HZ        (400)

#define PWM_CLK_DIV           TMRA_CLK_DIV32
#define TIMER_FREQUENCY       (3750000) // Timer frequency: 3.75M, PCLK0=240M, PCLK1=120M
// #define TIMER_FREQUENCY        3000000       // Timer frequency: 3M

#define MAX_PWM_OUT_CHAN      10            // Main Out has 10 pwm channel
#define PWM_DEFAULT_FREQUENCY PWM_FREQ_50HZ // pwm default frequqncy
#define VAL_TO_DC(_val)       ((float)(_val * __pwm_freq) / 1000000.0f)
#define DC_TO_VAL(_dc)        (1000000.0f / __pwm_freq * _dc)

#define PWM_ARR(freq)         (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = TIMER_FREQUENCY/(PWM_ARR+1)

static rt_err_t pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg);
static rt_err_t pwm_control(actuator_dev_t dev, int cmd, void* arg);
static rt_size_t pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);
static rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);

const static struct actuator_ops __act_ops = {
    .act_config = pwm_config,
    .act_control = pwm_control,
    .act_read = pwm_read,
    .act_write = pwm_write
};

static struct actuator_device act_dev = {
    .chan_mask = 0x3FF,
    .range = { 1000, 2000 },
    .config = {
        .protocol = ACT_PROTOCOL_PWM,
        .chan_num = MAX_PWM_OUT_CHAN,
        .pwm_config = { .pwm_freq = 50 },
        .dshot_config = { 0 } },
    .ops = &__act_ops
};

static uint32_t __pwm_freq = PWM_DEFAULT_FREQUENCY;
static float __pwm_dc[MAX_PWM_OUT_CHAN];

static void pwm_timer_init(void)
{
    stc_tmra_init_t stcTmraInit;
    stc_tmra_pwm_init_t stcPwmInit;

    /* 1. Enable TimerA peripheral clock. */
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_5, ENABLE);

    /* 2. Set a default initialization value for stcTmraInit. */
    (void)TMRA_StructInit(&stcTmraInit);

    /* 3. Modifies the initialization values depends on the application. */
    /* TIMA-1 ~ TIMA-4 use PCL0, TIMA-5 ~ TIMA-12 use PCLK1 */
    stcTmraInit.sw_count.u8ClockDiv = TMRA_CLK_DIV32;
    stcTmraInit.sw_count.u8CountMode = TMRA_MD_SAWTOOTH;
    stcTmraInit.sw_count.u8CountDir = TMRA_DIR_UP;
    stcTmraInit.u32PeriodValue = TMRA_PERIOD_VAL;
    (void)TMRA_Init(CM_TMRA_5, &stcTmraInit);

    /* 4. Set the comparison reference value. */
    (void)TMRA_PWM_StructInit(&stcPwmInit);
    stcPwmInit.u32CompareValue = TMRA_PWMX_CMP_VAL;
    stcPwmInit.u16StartPolarity = TMRA_PWM_LOW;
    stcPwmInit.u16StopPolarity = TMRA_PWM_LOW;
    stcPwmInit.u16PeriodMatchPolarity = TMRA_PWM_HIGH;

    // GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_10, GPIO_FUNC_5);
    // GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_11, GPIO_FUNC_5);
    // GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_12, GPIO_FUNC_5);
    // GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_00, GPIO_FUNC_5);
    GPIO_SetFunc(GPIO_PORT_A, GPIO_PIN_00, GPIO_FUNC_6); // TIMA-5-PWM1/TIMA-5-CLKA
    GPIO_SetFunc(GPIO_PORT_A, GPIO_PIN_01, GPIO_FUNC_6); // TIMA-5-PWM2/TIMA-5-CLKB
    GPIO_SetFunc(GPIO_PORT_A, GPIO_PIN_02, GPIO_FUNC_6); // TIMA-5-PWM3
    GPIO_SetFunc(GPIO_PORT_A, GPIO_PIN_03, GPIO_FUNC_6); // TIMA-5-PWM4
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH1, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH2, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH3, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH4, &stcPwmInit);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH1, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH2, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH3, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH4, ENABLE);
}

rt_inline void __read_pwm(uint8_t chan_id, float* dc)
{
    *dc = __pwm_dc[chan_id];
}

rt_inline void __write_pwm(uint8_t chan_id, float dc)
{
    __pwm_dc[chan_id] = dc;

    switch (chan_id) {
    case 0:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH1, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 1:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH2, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 2:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH3, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    case 3:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH4, PWM_ARR(__pwm_freq) * dc - 1);
        break;
    default:
        return;
    }
    __pwm_dc[chan_id] = dc;
}

static rt_err_t __set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    __pwm_freq = freq;

    TMRA_SetPeriodValue(CM_TMRA_5, PWM_ARR(__pwm_freq) - 1);
    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        __write_pwm(i, __pwm_dc[i]);
    }

    return RT_EOK;
}

static rt_err_t pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (__set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }
    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
            __write_pwm(i, VAL_TO_DC(act_dev.range[0]));
        }
        TMRA_Start(CM_TMRA_5);
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        TMRA_Stop(CM_TMRA_5);
        break;
    case ACT_CMD_SET_PROTOCOL:
        /* TODO: Support dshot */
        ret = RT_EINVAL;
        break;
    default:
        ret = RT_EINVAL;
        break;
    }

    return ret;
}

static rt_size_t pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            __read_pwm(i, &dc);
            *index = DC_TO_VAL(dc);
            index++;
        }
    }

    return size;
}

static rt_size_t pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    for (uint8_t i = 0; i < MAX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            val = *index;
            /* calculate pwm duty cycle */
            dc = VAL_TO_DC(val);
            /* update pwm signal */
            __write_pwm(i, dc);

            index++;
        }
    }

    return size;
}

rt_err_t drv_pwm_init(void)
{
    // LL_PERIPH_WE(LL_PERIPH_GPIO | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU);

    /* init pwm timer, pwm output mode */
    pwm_timer_init();

    // LL_PERIPH_WP(LL_PERIPH_GPIO | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU);

    TMRA_Start(CM_TMRA_5);
    /* register actuator hal device */
    return hal_actuator_register(&act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL);
}

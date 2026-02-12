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
#include <board_bsp.h>
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

#define PWM_FREQ_50HZ          (50)
#define PWM_FREQ_125HZ         (125)
#define PWM_FREQ_250HZ         (250)
#define PWM_FREQ_400HZ         (400)

#define TIMER_FREQUENCY        (5250000) // Timer frequency: 5.25M, PCLK0=336M, PCLK1=168M
#define MAIN_PWM_OUT_CHAN      (12)
#define AUX_PWM_OUT_CHAN       (4)
#define PWM_DEFAULT_FREQUENCY  PWM_FREQ_50HZ
#define VAL_TO_DC(_val, _freq) ((float)(_val * _freq) / 1000000.0f)
#define DC_TO_VAL(_dc, _freq)  (1000000.0f / _freq * _dc)

#define PWM_ARR(freq)          (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = TIMER_FREQUENCY/(PWM_ARR+1)

static rt_err_t main_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg);
static rt_err_t main_pwm_control(actuator_dev_t dev, int cmd, void* arg);
static rt_size_t main_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);
static rt_size_t main_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);

static rt_err_t aux_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg);
static rt_err_t aux_pwm_control(actuator_dev_t dev, int cmd, void* arg);
static rt_size_t aux_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size);
static rt_size_t aux_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size);

const static struct actuator_ops _main_out_ops = {
    .act_config = main_pwm_config,
    .act_control = main_pwm_control,
    .act_read = main_pwm_read,
    .act_write = main_pwm_write
};

static struct actuator_device main_out_dev = {
    .chan_mask = 0xFFF,
    .range = { 1000, 2000 },
    .config = {
        .protocol = ACT_PROTOCOL_PWM,
        .chan_num = MAIN_PWM_OUT_CHAN,
        .pwm_config = { .pwm_freq = 50 },
        .dshot_config = { 0 } },
    .ops = &_main_out_ops
};

const static struct actuator_ops _aux_out_ops = {
    .act_config = aux_pwm_config,
    .act_control = aux_pwm_control,
    .act_read = aux_pwm_read,
    .act_write = aux_pwm_write
};

static struct actuator_device aux_out_dev = {
    .chan_mask = 0xF,
    .range = { 1000, 2000 },
    .config = {
        .protocol = ACT_PROTOCOL_PWM,
        .chan_num = MAIN_PWM_OUT_CHAN,
        .pwm_config = { .pwm_freq = 50 },
        .dshot_config = { 0 } },
    .ops = &_aux_out_ops
};

static uint32_t main_pwm_freq = PWM_DEFAULT_FREQUENCY;
static float main_pwm_dc[MAIN_PWM_OUT_CHAN];
static uint32_t aux_pwm_freq = PWM_DEFAULT_FREQUENCY;
static float aux_pwm_dc[AUX_PWM_OUT_CHAN];

static void pwm_timer_init(void)
{
    stc_tmra_init_t stcTmraInit;
    stc_tmra_pwm_init_t stcPwmInit;

    /* 1. Enable TimerA peripheral clock. */
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_1, ENABLE);
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_4, ENABLE);
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_5, ENABLE);
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_8, ENABLE);

    /* 2. Set a default initialization value for stcTmraInit. */
    (void)TMRA_StructInit(&stcTmraInit);

    /* 3. Modifies the initialization values depends on the application. */
    /* TIMA-1 ~ TIMA-4 use PCLK0 */
    stcTmraInit.sw_count.u8ClockDiv = TMRA_CLK_DIV64;
    stcTmraInit.sw_count.u8CountMode = TMRA_MD_SAWTOOTH;
    stcTmraInit.sw_count.u8CountDir = TMRA_DIR_UP;
    stcTmraInit.u32PeriodValue = PWM_ARR(main_pwm_freq) - 1;
    (void)TMRA_Init(CM_TMRA_1, &stcTmraInit);
    (void)TMRA_Init(CM_TMRA_4, &stcTmraInit);
    /* TIMA-5 ~ TIMA-12 use PCLK1 */
    stcTmraInit.sw_count.u8ClockDiv = TMRA_CLK_DIV32;
    (void)TMRA_Init(CM_TMRA_5, &stcTmraInit);
    (void)TMRA_Init(CM_TMRA_8, &stcTmraInit);

    /* 4. Set the comparison reference value. */
    (void)TMRA_PWM_StructInit(&stcPwmInit);
    stcPwmInit.u32CompareValue = 0;
    stcPwmInit.u16StartPolarity = TMRA_PWM_LOW;
    stcPwmInit.u16StopPolarity = TMRA_PWM_LOW;
    stcPwmInit.u16PeriodMatchPolarity = TMRA_PWM_HIGH;

    // GPIO_SetFunc(GPIO_PORT_I, GPIO_PIN_04, GPIO_FUNC_4); // TIMA-1-PWM1/TIMA-1-CLKA
    GPIO_SetFunc(GPIO_PORT_I, GPIO_PIN_05, GPIO_FUNC_4); // TIMA-1-PWM2/TIMA-1-CLKB
    GPIO_SetFunc(GPIO_PORT_I, GPIO_PIN_06, GPIO_FUNC_4); // TIMA-1-PWM3
    GPIO_SetFunc(GPIO_PORT_I, GPIO_PIN_07, GPIO_FUNC_4); // TIMA-1-PWM4

    // (void)TMRA_PWM_Init(CM_TMRA_1, TMRA_CH1, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_1, TMRA_CH2, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_1, TMRA_CH3, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_1, TMRA_CH4, &stcPwmInit);
    // TMRA_PWM_OutputCmd(CM_TMRA_1, TMRA_CH1, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_1, TMRA_CH2, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_1, TMRA_CH3, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_1, TMRA_CH4, ENABLE);

    GPIO_SetFunc(GPIO_PORT_F, GPIO_PIN_11, GPIO_FUNC_4); // TIMA-4-PWM1/TIMA-4-CLKA
    GPIO_SetFunc(GPIO_PORT_F, GPIO_PIN_12, GPIO_FUNC_4); // TIMA-4-PWM2/TIMA-4-CLKB
    GPIO_SetFunc(GPIO_PORT_F, GPIO_PIN_13, GPIO_FUNC_4); // TIMA-4-PWM3
    GPIO_SetFunc(GPIO_PORT_F, GPIO_PIN_14, GPIO_FUNC_4); // TIMA-4-PWM4
    (void)TMRA_PWM_Init(CM_TMRA_4, TMRA_CH1, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_4, TMRA_CH2, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_4, TMRA_CH3, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_4, TMRA_CH4, &stcPwmInit);
    TMRA_PWM_OutputCmd(CM_TMRA_4, TMRA_CH1, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_4, TMRA_CH2, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_4, TMRA_CH3, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_4, TMRA_CH4, ENABLE);

    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_10, GPIO_FUNC_5); // TIMA-5-PWM1/TIMA-5-CLKA
    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_11, GPIO_FUNC_5); // TIMA-5-PWM2/TIMA-5-CLKB
    GPIO_SetFunc(GPIO_PORT_C, GPIO_PIN_12, GPIO_FUNC_5); // TIMA-5-PWM3
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_00, GPIO_FUNC_5); // TIMA-5-PWM4
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH1, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH2, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH3, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_5, TMRA_CH4, &stcPwmInit);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH1, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH2, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH3, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_5, TMRA_CH4, ENABLE);

    GPIO_SetFunc(GPIO_PORT_G, GPIO_PIN_11, GPIO_FUNC_4); // TIMA-8-PWM1/TIMA-8-CLKA
    GPIO_SetFunc(GPIO_PORT_G, GPIO_PIN_12, GPIO_FUNC_4); // TIMA-8-PWM2/TIMA-8-CLKB
    GPIO_SetFunc(GPIO_PORT_G, GPIO_PIN_13, GPIO_FUNC_4); // TIMA-8-PWM3
    GPIO_SetFunc(GPIO_PORT_G, GPIO_PIN_14, GPIO_FUNC_4); // TIMA-8-PWM4
    (void)TMRA_PWM_Init(CM_TMRA_8, TMRA_CH1, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_8, TMRA_CH2, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_8, TMRA_CH3, &stcPwmInit);
    (void)TMRA_PWM_Init(CM_TMRA_8, TMRA_CH4, &stcPwmInit);
    TMRA_PWM_OutputCmd(CM_TMRA_8, TMRA_CH1, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_8, TMRA_CH2, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_8, TMRA_CH3, ENABLE);
    TMRA_PWM_OutputCmd(CM_TMRA_8, TMRA_CH4, ENABLE);

    /* 5. Start Timer. */
    TMRA_Start(CM_TMRA_1);
    TMRA_Start(CM_TMRA_4);
    TMRA_Start(CM_TMRA_5);
    TMRA_Start(CM_TMRA_8);
}

rt_inline float _main_read_pwm(uint8_t chan_id)
{
    return main_pwm_dc[chan_id];
}

rt_inline void _main_write_pwm(uint8_t chan_id, float dc)
{
    switch (chan_id) {
    case 0:
        TMRA_SetCompareValue(CM_TMRA_1, TMRA_CH1, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 1:
        TMRA_SetCompareValue(CM_TMRA_1, TMRA_CH2, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 2:
        TMRA_SetCompareValue(CM_TMRA_1, TMRA_CH3, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 3:
        TMRA_SetCompareValue(CM_TMRA_1, TMRA_CH4, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 4:
        TMRA_SetCompareValue(CM_TMRA_4, TMRA_CH1, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 5:
        TMRA_SetCompareValue(CM_TMRA_4, TMRA_CH2, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 6:
        TMRA_SetCompareValue(CM_TMRA_4, TMRA_CH3, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 7:
        TMRA_SetCompareValue(CM_TMRA_4, TMRA_CH4, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 8:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH1, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 9:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH2, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 10:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH3, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    case 11:
        TMRA_SetCompareValue(CM_TMRA_5, TMRA_CH4, PWM_ARR(main_pwm_freq) * dc - 1);
        break;
    default:
        return;
    }

    main_pwm_dc[chan_id] = dc;
}

rt_inline rt_err_t _main_set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    TMRA_SetPeriodValue(CM_TMRA_1, PWM_ARR(main_pwm_freq) - 1);
    TMRA_SetPeriodValue(CM_TMRA_4, PWM_ARR(main_pwm_freq) - 1);
    TMRA_SetPeriodValue(CM_TMRA_5, PWM_ARR(main_pwm_freq) - 1);

    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < MAIN_PWM_OUT_CHAN; i++) {
        _main_write_pwm(i, main_pwm_dc[i]);
    }

    main_pwm_freq = freq;

    return RT_EOK;
}

static rt_err_t main_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("main out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (_main_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }

    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t main_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < MAIN_PWM_OUT_CHAN; i++) {
            _main_write_pwm(i, VAL_TO_DC(1000, main_pwm_freq));
        }

        TMRA_Start(CM_TMRA_1);
        TMRA_Start(CM_TMRA_4);
        TMRA_Start(CM_TMRA_5);
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        TMRA_Stop(CM_TMRA_1);
        TMRA_Stop(CM_TMRA_4);
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

static rt_size_t main_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < MAIN_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            dc = _main_read_pwm(i);
            *index = DC_TO_VAL(dc, main_pwm_freq);
            index++;
        }
    }

    return size;
}

static rt_size_t main_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    for (uint8_t i = 0; i < MAIN_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            val = *index;
            /* calculate pwm duty cycle */
            dc = VAL_TO_DC(val, main_pwm_freq);
            /* update pwm signal */
            _main_write_pwm(i, dc);

            index++;
        }
    }

    return size;
}

rt_inline float _aux_read_pwm(uint8_t chan_id)
{
    return aux_pwm_dc[chan_id];
}

rt_inline void _aux_write_pwm(uint8_t chan_id, float dc)
{
    switch (chan_id) {
    case 0:
        TMRA_SetCompareValue(CM_TMRA_8, TMRA_CH1, PWM_ARR(aux_pwm_freq) * dc - 1);
        break;
    case 1:
        TMRA_SetCompareValue(CM_TMRA_8, TMRA_CH2, PWM_ARR(aux_pwm_freq) * dc - 1);
        break;
    case 2:
        TMRA_SetCompareValue(CM_TMRA_8, TMRA_CH3, PWM_ARR(aux_pwm_freq) * dc - 1);
        break;
    case 3:
        TMRA_SetCompareValue(CM_TMRA_8, TMRA_CH4, PWM_ARR(aux_pwm_freq) * dc - 1);
        break;
    default:
        return;
    }

    aux_pwm_dc[chan_id] = dc;
}

rt_inline rt_err_t _aux_set_pwm_frequency(uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        /* invalid frequency */
        return RT_EINVAL;
    }

    TMRA_SetPeriodValue(CM_TMRA_8, PWM_ARR(aux_pwm_freq) - 1);

    /* the timer compare value should be re-configured */
    for (uint8_t i = 0; i < AUX_PWM_OUT_CHAN; i++) {
        _aux_write_pwm(i, aux_pwm_dc[i]);
    }

    aux_pwm_freq = freq;

    return RT_EOK;
}

static rt_err_t aux_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);

    if (_aux_set_pwm_frequency(cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }

    /* update device configuration */
    dev->config = *cfg;

    return RT_EOK;
}

static rt_err_t aux_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        /* set to lowest pwm before open */
        for (uint8_t i = 0; i < AUX_PWM_OUT_CHAN; i++) {
            _aux_write_pwm(i, VAL_TO_DC(1000, aux_pwm_freq));
        }

        TMRA_Start(CM_TMRA_8);
        break;
    case ACT_CMD_CHANNEL_DISABLE:
        TMRA_Stop(CM_TMRA_8);
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

static rt_size_t aux_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < AUX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            dc = _aux_read_pwm(i);
            *index = DC_TO_VAL(dc, aux_pwm_freq);
            index++;
        }
    }

    return size;
}

static rt_size_t aux_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    const rt_uint16_t* index = chan_val;
    rt_uint16_t val;
    float dc;

    for (uint8_t i = 0; i < AUX_PWM_OUT_CHAN; i++) {
        if (chan_sel & (1 << i)) {
            val = *index;
            /* calculate pwm duty cycle */
            dc = VAL_TO_DC(val, aux_pwm_freq);
            /* update pwm signal */
            _aux_write_pwm(i, dc);

            index++;
        }
    }

    return size;
}

rt_err_t drv_pwm_init(void)
{
    /* init pwm timer, pwm output mode */
    pwm_timer_init();

    /* register actuator hal device */
    RT_TRY(hal_actuator_register(&main_out_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL));
    RT_TRY(hal_actuator_register(&aux_out_dev, "aux_out", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}

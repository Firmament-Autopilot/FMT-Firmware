/****************************************************************************
 * Copyright 2020-2026 The Firmament Authors. All Rights Reserved.
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

#include "cy_sysclk.h"
#include "cy_tcpwm.h"
#include "cycfg_peripheral_clocks.h"
#include "cycfg_peripherals.h"
#include "hal/actuator/actuator.h"

// #define DRV_DBG(...)          console_printf(__VA_ARGS__)
#define DRV_DBG(...)

#define PWM_FREQ_50HZ          (50U)
#define PWM_FREQ_125HZ         (125U)
#define PWM_FREQ_250HZ         (250U)
#define PWM_FREQ_400HZ         (400U)

#define MAIN_PWM_CHAN          (8U)
#define AUX_PWM_CHAN           (8U)
#define PWM_DEFAULT_FREQUENCY  PWM_FREQ_400HZ

#if defined(COMPONENT_CM55) || defined(CORE_NAME_CM55_0)
#define PWM_USE_MAIN_OUT       (1U)
#define PWM_USE_AUX_OUT        (0U)
#elif defined(COMPONENT_CM33) || defined(CORE_NAME_CM33_0)
#define PWM_USE_MAIN_OUT       (0U)
#define PWM_USE_AUX_OUT        (1U)
#else
#define PWM_USE_MAIN_OUT       (1U)
#define PWM_USE_AUX_OUT        (1U)
#endif

/* TCPWM clock configured by CYBSP_PWM_CLK_DIV is 10MHz. */
#define TIMER_FREQUENCY_HZ     (10000000U)

#define PWM_MAIN_CH1_CNT       (271U)
#define PWM_MAIN_CH2_CNT       (264U)
#define PWM_MAIN_CH3_CNT       (265U)
#define PWM_MAIN_CH4_CNT       (266U)
#define PWM_MAIN_CH5_CNT       (267U)
#define PWM_MAIN_CH6_CNT       (269U)
#define PWM_MAIN_CH7_CNT       (273U)
#define PWM_MAIN_CH8_CNT       (275U)

#define PWM_AUX_CH9_CNT        (258U)
#define PWM_AUX_CH10_CNT       (259U)
#define PWM_AUX_CH11_CNT       (260U)
#define PWM_AUX_CH12_CNT       (5U)
#define PWM_AUX_CH13_CNT       (278U)
#define PWM_AUX_CH14_CNT       (279U)
#define PWM_AUX_CH15_CNT       (4U)
#define PWM_AUX_CH16_CNT       (261U)

#define PWM_CH_MASK(n) ((rt_uint16_t)(((n) >= 16U) ? 0xFFFFU : ((1UL << (n)) - 1UL)))

struct pwm_channel {
    TCPWM_Type* base;
    uint32_t cnt_num;
    const cy_stc_tcpwm_pwm_config_t* pwm_config;
};

struct pwm_group {
    const struct pwm_channel* channels;
    uint8_t num_channels;
    uint32_t* freq_hz;
    float* dc_cache;
};

static uint32_t main_pwm_freq = PWM_DEFAULT_FREQUENCY;
static uint32_t aux_pwm_freq = PWM_DEFAULT_FREQUENCY;
static float main_pwm_dc[MAIN_PWM_CHAN];
static float aux_pwm_dc[AUX_PWM_CHAN];

static const struct pwm_channel main_pwm_channels[MAIN_PWM_CHAN] = {
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH1_CNT, .pwm_config = &tcpwm_0_group_1_cnt_15_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH2_CNT, .pwm_config = &tcpwm_0_group_1_cnt_8_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH3_CNT, .pwm_config = &tcpwm_0_group_1_cnt_9_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH4_CNT, .pwm_config = &tcpwm_0_group_1_cnt_10_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH5_CNT, .pwm_config = &tcpwm_0_group_1_cnt_11_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH6_CNT, .pwm_config = &tcpwm_0_group_1_cnt_13_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH7_CNT, .pwm_config = &tcpwm_0_group_1_cnt_17_config },
    { .base = TCPWM0, .cnt_num = PWM_MAIN_CH8_CNT, .pwm_config = &tcpwm_0_group_1_cnt_19_config },
};

static const struct pwm_channel aux_pwm_channels[AUX_PWM_CHAN] = {
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH9_CNT, .pwm_config = &tcpwm_0_group_1_cnt_2_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH10_CNT, .pwm_config = &tcpwm_0_group_1_cnt_3_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH11_CNT, .pwm_config = &tcpwm_0_group_1_cnt_4_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH12_CNT, .pwm_config = &tcpwm_0_group_0_cnt_5_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH13_CNT, .pwm_config = &tcpwm_0_group_1_cnt_22_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH14_CNT, .pwm_config = &tcpwm_0_group_1_cnt_23_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH15_CNT, .pwm_config = &tcpwm_0_group_0_cnt_4_config },
    { .base = TCPWM0, .cnt_num = PWM_AUX_CH16_CNT, .pwm_config = &tcpwm_0_group_1_cnt_5_config },
};

static struct pwm_group main_pwm_group = {
    .channels = main_pwm_channels,
    .num_channels = MAIN_PWM_CHAN,
    .freq_hz = &main_pwm_freq,
    .dc_cache = main_pwm_dc,
};

static struct pwm_group aux_pwm_group = {
    .channels = aux_pwm_channels,
    .num_channels = AUX_PWM_CHAN,
    .freq_hz = &aux_pwm_freq,
    .dc_cache = aux_pwm_dc,
};

static rt_err_t pwm_get_clk_dst(uint32_t cnt_num, en_clk_dst_t* clk_dst)
{
    switch (cnt_num) {
    case 2U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN2;
        break;
    case 3U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN3;
        break;
    case 4U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN4;
        break;
    case 5U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN5;
        break;
    case 6U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN6;
        break;
    case 7U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN7;
        break;
    case 260U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN260;
        break;
    case 261U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN261;
        break;
    case 258U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN258;
        break;
    case 259U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN259;
        break;
    case 264U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN264;
        break;
    case 265U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN265;
        break;
    case 266U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN266;
        break;
    case 267U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN267;
        break;
    case 269U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN269;
        break;
    case 271U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN271;
        break;
    case 273U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN273;
        break;
    case 275U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN275;
        break;
    case 278U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN278;
        break;
    case 279U:
        *clk_dst = (en_clk_dst_t)PCLK_TCPWM0_CLOCK_COUNTER_EN279;
        break;
    default:
        return RT_EINVAL;
    }

    return RT_EOK;
}

static rt_err_t pwm_assign_clock(uint32_t cnt_num)
{
    en_clk_dst_t clk_dst;
    cy_en_sysclk_status_t clk_ret;

    if (pwm_get_clk_dst(cnt_num, &clk_dst) != RT_EOK) {
        DRV_DBG("unsupported tcpwm counter: %u\n", cnt_num);
        return RT_EINVAL;
    }

    clk_ret = Cy_SysClk_PeriPclkAssignDivider(clk_dst, CY_SYSCLK_DIV_16_5_BIT, CYBSP_PWM_CLK_DIV_NUM);
    if (clk_ret != CY_SYSCLK_SUCCESS) {
        DRV_DBG("assign clock divider failed for tcpwm counter: %u\n", cnt_num);
        return RT_ERROR;
    }

    return RT_EOK;
}

static void pwm_fix_compl_waveform(const struct pwm_channel* pwm)
{
#if (CY_IP_MXTCPWM_VERSION >= 2U)
    if ((pwm->cnt_num == PWM_AUX_CH15_CNT) || (pwm->cnt_num == PWM_AUX_CH16_CNT)) {
        /* CH15/CH16 pins are routed to LINE_COMPLx, so drive that path with normal PWM. */
        Cy_TCPWM_PWM_Configure_LineSelect(pwm->base,
                                          pwm->cnt_num,
                                          CY_TCPWM_OUTPUT_PWM_SIGNAL,
                                          CY_TCPWM_OUTPUT_PWM_SIGNAL);
        Cy_TCPWM_PWM_Configure_LineSelectBuff(pwm->base,
                                              pwm->cnt_num,
                                              CY_TCPWM_OUTPUT_PWM_SIGNAL,
                                              CY_TCPWM_OUTPUT_PWM_SIGNAL);
    }
#else
    (void)pwm;
#endif
}

static rt_bool_t pwm_counter_seen(const uint32_t* list, uint8_t used, uint32_t cnt_num)
{
    for (uint8_t i = 0; i < used; i++) {
        if (list[i] == cnt_num) {
            return RT_TRUE;
        }
    }

    return RT_FALSE;
}

static uint32_t pwm_arr_by_freq(uint32_t freq_hz)
{
    if (freq_hz == 0U) {
        return 1U;
    }

    return TIMER_FREQUENCY_HZ / freq_hz;
}

static float pwm_val_to_dc(uint16_t pulse_us, uint32_t freq_hz)
{
    return (float)pulse_us / (1000000.0f / (float)freq_hz);
}

static uint16_t pwm_dc_to_val(float dc, uint32_t freq_hz)
{
    float pulse_us = (1000000.0f / (float)freq_hz) * dc;

    if (pulse_us < 0.0f) {
        pulse_us = 0.0f;
    }
    if (pulse_us > 65535.0f) {
        pulse_us = 65535.0f;
    }

    return (uint16_t)(pulse_us + 0.5f);
}

static void pwm_read_channel(struct pwm_group* group, uint8_t chan_id, float* dc)
{
    *dc = group->dc_cache[chan_id];
}

static void pwm_write_channel(struct pwm_group* group, uint8_t chan_id, float dc)
{
    const struct pwm_channel* pwm;
    uint32_t arr;
    uint32_t compare;

    if (chan_id >= group->num_channels) {
        return;
    }

    if (dc < 0.0f) {
        dc = 0.0f;
    }
    if (dc > 1.0f) {
        dc = 1.0f;
    }

    pwm = &group->channels[chan_id];
    arr = pwm_arr_by_freq(*group->freq_hz);
    compare = (uint32_t)((float)arr * dc);

    if (compare > arr) {
        compare = arr;
    }

    Cy_TCPWM_PWM_SetPeriod0(pwm->base, pwm->cnt_num, arr);
    Cy_TCPWM_PWM_SetCompare0Val(pwm->base, pwm->cnt_num, compare);

    group->dc_cache[chan_id] = dc;
}

static rt_err_t pwm_set_frequency(struct pwm_group* group, uint16_t freq)
{
    if (freq < PWM_FREQ_50HZ || freq > PWM_FREQ_400HZ) {
        return RT_EINVAL;
    }

    *group->freq_hz = freq;

    for (uint8_t i = 0; i < group->num_channels; i++) {
        pwm_write_channel(group, i, group->dc_cache[i]);
    }

    return RT_EOK;
}

static rt_err_t pwm_config_group(actuator_dev_t dev, const struct actuator_configure* cfg, struct pwm_group* group)
{
    if (pwm_set_frequency(group, cfg->pwm_config.pwm_freq) != RT_EOK) {
        return RT_ERROR;
    }

    dev->config = *cfg;
    return RT_EOK;
}

static void pwm_enable_group(struct pwm_group* group)
{
    uint32_t enabled_cnt[MAIN_PWM_CHAN + AUX_PWM_CHAN];
    uint8_t enabled_num = 0;

    for (uint8_t i = 0; i < group->num_channels; i++) {
        const struct pwm_channel* pwm = &group->channels[i];

        if (pwm_counter_seen(enabled_cnt, enabled_num, pwm->cnt_num)) {
            continue;
        }

        Cy_TCPWM_PWM_Enable(pwm->base, pwm->cnt_num);
        Cy_TCPWM_TriggerStart_Single(pwm->base, pwm->cnt_num);

        enabled_cnt[enabled_num++] = pwm->cnt_num;
    }
}

static void pwm_disable_group(struct pwm_group* group)
{
    uint32_t disabled_cnt[MAIN_PWM_CHAN + AUX_PWM_CHAN];
    uint8_t disabled_num = 0;

    for (uint8_t i = 0; i < group->num_channels; i++) {
        const struct pwm_channel* pwm = &group->channels[i];

        if (pwm_counter_seen(disabled_cnt, disabled_num, pwm->cnt_num)) {
            continue;
        }

        Cy_TCPWM_PWM_Disable(pwm->base, pwm->cnt_num);
        disabled_cnt[disabled_num++] = pwm->cnt_num;
    }
}

static rt_err_t pwm_control_group(int cmd, struct pwm_group* group)
{
    switch (cmd) {
    case ACT_CMD_CHANNEL_ENABLE:
        pwm_enable_group(group);
        return RT_EOK;
    case ACT_CMD_CHANNEL_DISABLE:
        pwm_disable_group(group);
        return RT_EOK;
    case ACT_CMD_SET_PROTOCOL:
    default:
        return RT_EINVAL;
    }
}

static rt_size_t pwm_read_group(rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size, struct pwm_group* group)
{
    rt_uint16_t* index = chan_val;
    float dc;

    for (uint8_t i = 0; i < group->num_channels; i++) {
        if ((chan_sel & (rt_uint16_t)(1U << i)) == 0U) {
            continue;
        }

        pwm_read_channel(group, i, &dc);
        *index++ = pwm_dc_to_val(dc, *group->freq_hz);
    }

    return size;
}

static rt_size_t pwm_write_group(rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size, struct pwm_group* group)
{
    const rt_uint16_t* index = chan_val;

    for (uint8_t i = 0; i < group->num_channels; i++) {
        rt_uint16_t val;
        float dc;

        if ((chan_sel & (rt_uint16_t)(1U << i)) == 0U) {
            continue;
        }

        val = *index++;
        dc = pwm_val_to_dc(val, *group->freq_hz);
        pwm_write_channel(group, i, dc);
    }

    return size;
}

static rt_err_t main_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("main out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);
    return pwm_config_group(dev, cfg, &main_pwm_group);
}

static rt_err_t aux_pwm_config(actuator_dev_t dev, const struct actuator_configure* cfg)
{
    DRV_DBG("aux out configured: pwm frequency:%d\n", cfg->pwm_config.pwm_freq);
    return pwm_config_group(dev, cfg, &aux_pwm_group);
}

static rt_err_t main_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    (void)dev;
    (void)arg;

    return pwm_control_group(cmd, &main_pwm_group);
}

static rt_err_t aux_pwm_control(actuator_dev_t dev, int cmd, void* arg)
{
    (void)dev;
    (void)arg;

    return pwm_control_group(cmd, &aux_pwm_group);
}

static rt_size_t main_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    (void)dev;

    return pwm_read_group(chan_sel, chan_val, size, &main_pwm_group);
}

static rt_size_t aux_pwm_read(actuator_dev_t dev, rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    (void)dev;

    return pwm_read_group(chan_sel, chan_val, size, &aux_pwm_group);
}

static rt_size_t main_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    (void)dev;

    return pwm_write_group(chan_sel, chan_val, size, &main_pwm_group);
}

static rt_size_t aux_pwm_write(actuator_dev_t dev, rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    (void)dev;

    return pwm_write_group(chan_sel, chan_val, size, &aux_pwm_group);
}

const static struct actuator_ops main_act_ops = {
    .act_config = main_pwm_config,
    .act_control = main_pwm_control,
    .act_read = main_pwm_read,
    .act_write = main_pwm_write,
};

const static struct actuator_ops aux_act_ops = {
    .act_config = aux_pwm_config,
    .act_control = aux_pwm_control,
    .act_read = aux_pwm_read,
    .act_write = aux_pwm_write,
};

static struct actuator_device main_act_dev = {
    .chan_mask = PWM_CH_MASK(MAIN_PWM_CHAN),
    .range = { 1000, 2000 },
    .config = { .protocol = ACT_PROTOCOL_PWM,
                .chan_num = MAIN_PWM_CHAN,
                .pwm_config = { .pwm_freq = PWM_DEFAULT_FREQUENCY },
                .dshot_config = { 0 } },
    .ops = &main_act_ops,
};

static struct actuator_device aux_act_dev = {
    .chan_mask = PWM_CH_MASK(AUX_PWM_CHAN),
    .range = { 1000, 2000 },
    .config = { .protocol = ACT_PROTOCOL_PWM,
                .chan_num = AUX_PWM_CHAN,
                .pwm_config = { .pwm_freq = PWM_DEFAULT_FREQUENCY },
                .dshot_config = { 0 } },
    .ops = &aux_act_ops,
};

rt_err_t drv_pwm_init(void)
{
    uint32_t initialized_cnt[MAIN_PWM_CHAN + AUX_PWM_CHAN];
    uint8_t initialized_num = 0;
    const struct pwm_group* groups[2];
    uint8_t groups_num = 0;

#if PWM_USE_MAIN_OUT
    groups[groups_num++] = &main_pwm_group;
#endif
#if PWM_USE_AUX_OUT
    groups[groups_num++] = &aux_pwm_group;
#endif

    for (uint8_t g = 0; g < groups_num; g++) {
        const struct pwm_group* group = groups[g];

        for (uint8_t i = 0; i < group->num_channels; i++) {
            const struct pwm_channel* pwm = &group->channels[i];
            cy_en_tcpwm_status_t status;

            if (pwm_counter_seen(initialized_cnt, initialized_num, pwm->cnt_num)) {
                continue;
            }

            if (pwm_assign_clock(pwm->cnt_num) != RT_EOK) {
                return RT_ERROR;
            }

            status = Cy_TCPWM_PWM_Init(pwm->base, pwm->cnt_num, pwm->pwm_config);
            if (status != CY_TCPWM_SUCCESS) {
                DRV_DBG("Initialize TCPWM PWM counter %u failed\n", pwm->cnt_num);
                return RT_ERROR;
            }

            initialized_cnt[initialized_num++] = pwm->cnt_num;
        }
    }

    for (uint8_t i = 0; i < MAIN_PWM_CHAN; i++) {
        main_pwm_dc[i] = 0.0f;
    }

    for (uint8_t i = 0; i < AUX_PWM_CHAN; i++) {
        aux_pwm_dc[i] = 0.0f;
    }

#if !PWM_USE_MAIN_OUT
    (void)&main_act_dev;
#endif
#if !PWM_USE_AUX_OUT
    (void)&aux_act_dev;
#endif

#if PWM_USE_MAIN_OUT
    RT_TRY(hal_actuator_register(&main_act_dev, "main_out", RT_DEVICE_FLAG_RDWR, NULL));
#endif
#if PWM_USE_AUX_OUT
    RT_TRY(hal_actuator_register(&aux_act_dev, "aux_out", RT_DEVICE_FLAG_RDWR, NULL));
#endif

    DRV_DBG("E83 PWM driver initialized (register main:%u aux:%u)\n", PWM_USE_MAIN_OUT, PWM_USE_AUX_OUT);
    return RT_EOK;
}

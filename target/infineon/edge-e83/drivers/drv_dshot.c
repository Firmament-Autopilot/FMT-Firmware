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
#include "drv_dshot.h"

#include <stddef.h>

#include "cy_dma.h"
#include "cy_sysclk.h"
#include "cy_sysint.h"
#include "cy_tcpwm_pwm.h"
#include "cy_trigmux.h"
#include "cycfg_peripheral_clocks.h"
#include "cycfg_peripherals.h"
#include "module/system/systime.h"

#define DSHOT_BIT_RATE      (300000U)
#define DSHOT_FRAME_BITS    (16U)
#define DSHOT_DMA_WORDS     (17U)
#define DSHOT_MIN_FRAME_US  (110U)

/* PERI0 group 1 has no spare dividers. Reuse the generated /1 clock without
 * changing it; the other PWM outputs keep their original 16.5-bit divider. */
#define DSHOT_CLOCK_TYPE    CY_SYSCLK_DIV_8_BIT
#define DSHOT_CLOCK_DIVIDER CYBSP_USB_OS_TIMER_CLK_DIV_NUM

struct dshot_channel {
    uint32_t counter;
    en_clk_dst_t clock;
    uint32_t trigger_in;
    uint32_t trigger_out;
    const cy_stc_tcpwm_pwm_config_t* pwm_config;
};

static const struct dshot_channel channels[E83_DSHOT_CHANNELS] = {
    { 271U, PCLK_TCPWM0_CLOCK_COUNTER_EN271, PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0271, PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN0, &tcpwm_0_group_1_cnt_15_config },
    { 264U, PCLK_TCPWM0_CLOCK_COUNTER_EN264, PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0264, PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN1, &tcpwm_0_group_1_cnt_8_config },
    { 265U, PCLK_TCPWM0_CLOCK_COUNTER_EN265, PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0265, PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN2, &tcpwm_0_group_1_cnt_9_config },
    { 266U, PCLK_TCPWM0_CLOCK_COUNTER_EN266, PERI_0_TRIG_IN_MUX_0_TCPWM0_TR_OUT0266, PERI_0_TRIG_OUT_MUX_0_PDMA1_TR_IN3, &tcpwm_0_group_1_cnt_10_config },
};

static const IRQn_Type dma_irqs[E83_DSHOT_CHANNELS] = {
    m33syscpuss_interrupts_dw1_0_IRQn,
    m33syscpuss_interrupts_dw1_1_IRQn,
    m33syscpuss_interrupts_dw1_2_IRQn,
    m33syscpuss_interrupts_dw1_3_IRQn,
};

/* Each descriptor and each channel occupies whole 32-byte cache lines. The
 * SoCMEM section keeps DMA data out of DTCM and the small IPC shared region.
 * Startup zeroes it; configure also resets all 768 bytes before DMA setup. */
struct dshot_dma_data {
    cy_stc_dma_descriptor_t frame;
    uint32_t reserved0[2];
    cy_stc_dma_descriptor_t stop;
    uint32_t reserved1[2];
    uint32_t compare[24];
    uint32_t stop_control[8];
};

_Static_assert(sizeof(cy_stc_dma_descriptor_t) == 24U, "DMA descriptor padding must match the PDL");
_Static_assert(sizeof(struct dshot_dma_data) % 32U == 0U, "DMA channels must use whole cache lines");
_Static_assert(offsetof(struct dshot_dma_data, frame) % 32U == 0U, "Frame descriptor must be cache aligned");
_Static_assert(offsetof(struct dshot_dma_data, stop) % 32U == 0U, "Stop descriptor must be cache aligned");
_Static_assert(offsetof(struct dshot_dma_data, compare) % 32U == 0U, "Waveform buffer must be cache aligned");
_Static_assert(offsetof(struct dshot_dma_data, stop_control) % 32U == 0U, "Stop data must be cache aligned");

CY_SECTION(".cy_socmem_bss")
CY_ALIGN(32)
static struct dshot_dma_data dma_data[E83_DSHOT_CHANNELS];

static uint16_t last_value[E83_DSHOT_CHANNELS];
static uint64_t last_start_us[E83_DSHOT_CHANNELS];
static uint64_t stopped_us;
static uint16_t configured_mask;
static uint16_t sent_mask;
static uint32_t period_ticks;
static uint32_t zero_ticks;
static uint32_t one_ticks;
static rt_bool_t configured;
static rt_bool_t stopped_after_frame;
static volatile rt_bool_t enabled;
static volatile uint16_t completed_mask;
static void dshot_clean_cache(void* address, uint32_t size)
{
#if defined(__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
    SCB_CleanDCache_by_Addr(address, (int32_t)size);
#else
    (void)address;
    (void)size;
#endif
    __DSB();
}

/* Interrupts are held by callers. Do not touch DMA source memory here: a bus
 * transaction already in flight may finish after the channel is disabled. */
static void dshot_stop_all(void)
{
    enabled = RT_FALSE;
    completed_mask = 0U;
    if (sent_mask != 0U) {
        stopped_us = systime_now_us();
        stopped_after_frame = RT_TRUE;
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        uint32_t counter = channels[i].counter;
        uint32_t group = TCPWM_GRP_CNT_GET_GRP(counter);
        uint32_t control;

        Cy_DMA_Channel_Disable(DW1, i);
        Cy_TCPWM_TriggerStopOrKill_Single(TCPWM0, counter);
        /* Also cover a configure failure before PWM_Init reached this channel. */
        control = TCPWM_GRP_CNT_CTRL(TCPWM0, group, counter);
        control &= ~(TCPWM_GRP_CNT_V2_CTRL_ENABLED_Msk | TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE_Msk);
        control |= _VAL2FLD(TCPWM_GRP_CNT_V2_CTRL_PWM_DISABLE_MODE, CY_TCPWM_PWM_OUTPUT_LOW);
        TCPWM_GRP_CNT_CTRL(TCPWM0, group, counter) = control;
        Cy_DMA_Channel_ClearInterrupt(DW1, i);
        NVIC_ClearPendingIRQ(dma_irqs[i]);
        last_value[i] = 1000U;
    }
    __DSB();
}

static void dshot_dma_isr(uint32_t channel)
{
    cy_en_dma_intr_cause_t status;

    rt_interrupt_enter();
    status = Cy_DMA_Channel_GetStatus(DW1, channel);
    if (enabled && status == CY_DMA_INTR_CAUSE_COMPLETION) {
        completed_mask |= (uint16_t)(1U << channel);
    } else if (enabled) {
        /* Bus/descriptor errors stop the outputs even if no further actuator
         * write occurs. Recovery requires an explicit enable or reboot. */
        dshot_stop_all();
    }
    Cy_DMA_Channel_ClearInterrupt(DW1, channel);
    __DSB();
    rt_interrupt_leave();
}

static void dshot_dma0_isr(void) { dshot_dma_isr(0U); }
static void dshot_dma1_isr(void) { dshot_dma_isr(1U); }
static void dshot_dma2_isr(void) { dshot_dma_isr(2U); }
static void dshot_dma3_isr(void) { dshot_dma_isr(3U); }

static const cy_israddress dma_handlers[E83_DSHOT_CHANNELS] = {
    dshot_dma0_isr,
    dshot_dma1_isr,
    dshot_dma2_isr,
    dshot_dma3_isr,
};

static rt_bool_t dshot_dma_active(uint32_t channel)
{
    return Cy_DMA_Channel_IsEnabled(DW1, channel)
        || ((Cy_DMA_GetActiveChannel(DW1) & (1UL << channel)) != 0U)
        || (Cy_DMA_GetActiveChannelIndex(DW1) == channel);
}

static rt_bool_t dshot_valid_selection(uint16_t mask, rt_size_t size)
{
    rt_size_t count = 0U;

    if (mask == 0U || (mask & ~configured_mask) != 0U) {
        return RT_FALSE;
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        count += (mask >> i) & 1U;
    }
    /* Actuator HAL sizes count uint16_t channel values, not bytes. */
    return size == count;
}

/* 1000 is an explicit motor stop. Ordinary actuator writes never send ESC
 * commands 1..47; 1001 and 2000 map to the endpoints of the throttle range. */
static uint16_t dshot_encode_value(uint16_t value)
{
    if (value <= 1000U) {
        return DSHOT_CMD_MOTOR_STOP;
    }
    if (value >= 2000U) {
        return DSHOT_MAX_THROTTLE;
    }
    return (uint16_t)(DSHOT_MIN_THROTTLE
                      + ((uint32_t)(value - 1001U) * DSHOT_RANGE) / 999U);
}

static rt_err_t dshot_init_dma(uint32_t channel)
{
    const uint32_t counter = channels[channel].counter;
    const uint32_t group = TCPWM_GRP_CNT_GET_GRP(counter);
    struct dshot_dma_data* data = &dma_data[channel];
    cy_stc_dma_descriptor_config_t descriptor = {
        .retrigger = CY_DMA_RETRIG_IM,
        .interruptType = CY_DMA_DESCR_CHAIN,
        .triggerOutType = CY_DMA_DESCR,
        .channelState = CY_DMA_CHANNEL_ENABLED,
        .triggerInType = CY_DMA_1ELEMENT,
        .dataSize = CY_DMA_WORD,
        .srcTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
        .dstTransferSize = CY_DMA_TRANSFER_SIZE_WORD,
        .descriptorType = CY_DMA_1D_TRANSFER,
        .srcAddress = &data->compare[1],
        .dstAddress = (void*)&TCPWM_GRP_CNT_CC0_BUFF(TCPWM0, group, counter),
        .srcXincrement = 1,
        .dstXincrement = 0,
        .xCount = DSHOT_DMA_WORDS,
        .srcYincrement = 0,
        .dstYincrement = 0,
        .yCount = 1,
        .nextDescriptor = &data->stop,
    };
    cy_stc_dma_channel_config_t channel_config = {
        .descriptor = &data->frame,
        .preemptable = false,
        .priority = 0,
        .enable = false,
        .bufferable = false,
    };

    if (Cy_DMA_Descriptor_Init(&data->frame, &descriptor) != CY_DMA_SUCCESS) {
        return RT_ERROR;
    }

    /* At the TC following both zero entries, stop the PWM in hardware. The
     * output does not depend on ISR latency or a repeated frame to stay low. */
    data->stop_control[0] = TCPWM_GRP_CNT_CTRL(TCPWM0, group, counter)
        & ~TCPWM_GRP_CNT_V2_CTRL_ENABLED_Msk;
    descriptor.channelState = CY_DMA_CHANNEL_DISABLED;
    descriptor.descriptorType = CY_DMA_SINGLE_TRANSFER;
    descriptor.srcAddress = &data->stop_control[0];
    descriptor.dstAddress = (void*)&TCPWM_GRP_CNT_CTRL(TCPWM0, group, counter);
    descriptor.srcXincrement = 0;
    descriptor.xCount = 1;
    descriptor.nextDescriptor = NULL;
    if (Cy_DMA_Descriptor_Init(&data->stop, &descriptor) != CY_DMA_SUCCESS
        || Cy_DMA_Channel_Init(DW1, channel, &channel_config) != CY_DMA_SUCCESS) {
        return RT_ERROR;
    }
    Cy_DMA_Channel_SetInterruptMask(DW1, channel, 0U);
    Cy_DMA_Channel_ClearInterrupt(DW1, channel);
    dshot_clean_cache(data, sizeof(*data));

    return Cy_TrigMux_Connect(channels[channel].trigger_in,
                              channels[channel].trigger_out,
                              false,
                              TRIGGER_TYPE_EDGE)
            == CY_TRIGMUX_SUCCESS
        ? RT_EOK
        : RT_ERROR;
}

rt_err_t drv_dshot_configure(const struct actuator_configure* cfg)
{
    rt_base_t level;
    uint32_t clock_hz;
    rt_err_t result = RT_ERROR;

    if (cfg == NULL || cfg->protocol != ACT_PROTOCOL_DSHOT
        || cfg->chan_num == 0U || cfg->chan_num > E83_DSHOT_CHANNELS
        || cfg->dshot_config.speed != 300U || cfg->dshot_config.telem_req) {
        return RT_EINVAL;
    }

    level = rt_hw_interrupt_disable();
    if (enabled) {
        rt_hw_interrupt_enable(level);
        return RT_EBUSY;
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        if (dshot_dma_active(i)) {
            rt_hw_interrupt_enable(level);
            return RT_EBUSY;
        }
    }

    configured = RT_FALSE;
    configured_mask = 0U;
    sent_mask = 0U;
    completed_mask = 0U;
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        NVIC_DisableIRQ(dma_irqs[i]);
        NVIC_ClearPendingIRQ(dma_irqs[i]);
        Cy_DMA_Channel_SetInterruptMask(DW1, i, 0U);
    }
    rt_memset(dma_data, 0, sizeof(dma_data));

    clock_hz = Cy_SysClk_PeriPclkGetFrequency(channels[0].clock,
                                              DSHOT_CLOCK_TYPE,
                                              DSHOT_CLOCK_DIVIDER);
    period_ticks = (clock_hz + DSHOT_BIT_RATE / 2U) / DSHOT_BIT_RATE;
    if (!Cy_SysClk_PeriPclkGetDividerEnabled(channels[0].clock,
                                             DSHOT_CLOCK_TYPE,
                                             DSHOT_CLOCK_DIVIDER)
        || period_ticks < 16U || period_ticks > 65536U) {
        goto out;
    }
    /* Reject a changed clock tree that cannot approximate DShot300 to 1%. */
    if ((uint64_t)clock_hz < (uint64_t)period_ticks * (DSHOT_BIT_RATE - DSHOT_BIT_RATE / 100U)
        || (uint64_t)clock_hz > (uint64_t)period_ticks * (DSHOT_BIT_RATE + DSHOT_BIT_RATE / 100U)) {
        goto out;
    }
    zero_ticks = (period_ticks * 3U + 4U) / 8U;
    one_ticks = (period_ticks * 3U + 2U) / 4U;

    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        cy_stc_tcpwm_pwm_config_t pwm = *channels[i].pwm_config;
        uint32_t counter = channels[i].counter;

        Cy_TCPWM_TriggerStopOrKill_Single(TCPWM0, counter);
        Cy_TCPWM_PWM_Disable(TCPWM0, counter);
        pwm.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1;
        pwm.runMode = CY_TCPWM_PWM_CONTINUOUS;
        pwm.period0 = period_ticks - 1U;
        pwm.period1 = period_ticks - 1U;
        pwm.compare0 = 0U;
        pwm.compare1 = 0U;
        pwm.enableCompareSwap = true;
        pwm.swapInput = CY_TCPWM_INPUT_1;
        pwm.swapInputMode = CY_TCPWM_INPUT_LEVEL;
        pwm.interruptSources = 0U;
        pwm.pwmOnDisable = CY_TCPWM_PWM_OUTPUT_LOW;
        pwm.trigger0Event = CY_TCPWM_CNT_TRIGGER_ON_TC;
        pwm.trigger1Event = CY_TCPWM_CNT_TRIGGER_ON_DISABLED;

        if (Cy_TCPWM_PWM_Init(TCPWM0, counter, &pwm) != CY_TCPWM_SUCCESS
            || Cy_SysClk_PeriPclkAssignDivider(channels[i].clock,
                                               DSHOT_CLOCK_TYPE,
                                               DSHOT_CLOCK_DIVIDER)
                != CY_SYSCLK_SUCCESS
            || dshot_init_dma(i) != RT_EOK) {
            goto out;
        }
        last_value[i] = 1000U;
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        cy_stc_sysint_t irq_config = {
            .intrSrc = dma_irqs[i],
            .intrPriority = 6U,
        };
        if (Cy_SysInt_Init(&irq_config, dma_handlers[i]) != CY_SYSINT_SUCCESS) {
            goto out;
        }
    }
    Cy_DMA_Enable(DW1);
    configured_mask = (uint16_t)((1UL << cfg->chan_num) - 1UL);
    configured = RT_TRUE;
    result = RT_EOK;

out:
    dshot_stop_all();
    if (result == RT_EOK) {
        for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
            Cy_DMA_Channel_SetInterruptMask(DW1, i, CY_DMA_INTR_MASK);
            NVIC_EnableIRQ(dma_irqs[i]);
        }
    }
    rt_hw_interrupt_enable(level);
    return result;
}

/* Caller has checked all selected channels before any source buffer changes.
 * TC0 sends bit15 from the preloaded compare. At each TC the buffer is swapped
 * first, then DMA loads the next compare for the following TC. The last two
 * words are zero so neither compare register can replay the final data bit. */
static void dshot_start_channel(uint32_t channel, uint16_t value)
{
    struct dshot_dma_data* data = &dma_data[channel];
    uint32_t counter = channels[channel].counter;
    uint16_t frame = dshot_pack_frame(dshot_encode_value(value), false);

    for (uint32_t bit = 0; bit < DSHOT_FRAME_BITS; bit++) {
        data->compare[bit] = (frame & (0x8000U >> bit)) ? one_ticks : zero_ticks;
    }
    data->compare[16] = 0U;
    data->compare[17] = 0U;
    dshot_clean_cache(data, sizeof(*data));

    Cy_TCPWM_TriggerStopOrKill_Single(TCPWM0, counter);
    Cy_TCPWM_PWM_Disable(TCPWM0, counter);
    Cy_TCPWM_PWM_SetCompare0Val(TCPWM0, counter, data->compare[0]);
    Cy_TCPWM_PWM_SetCompare0BufVal(TCPWM0, counter, data->compare[0]);
    Cy_TCPWM_PWM_SetCounter(TCPWM0, counter, period_ticks - 1U);
    Cy_DMA_Channel_ClearInterrupt(DW1, channel);
    NVIC_ClearPendingIRQ(dma_irqs[channel]);
    completed_mask &= (uint16_t) ~(1U << channel);
    Cy_DMA_Channel_SetDescriptor(DW1, channel, &data->frame);
    Cy_DMA_Channel_Enable(DW1, channel);
    Cy_TCPWM_PWM_Enable(TCPWM0, counter);
    Cy_TCPWM_TriggerStart_Single(TCPWM0, counter);
    last_start_us[channel] = systime_now_us();
    last_value[channel] = value;
    sent_mask |= (uint16_t)(1U << channel);
}

rt_err_t drv_dshot_enable(void)
{
    rt_base_t level = rt_hw_interrupt_disable();
    uint64_t now = systime_now_us();

    if (!configured) {
        rt_hw_interrupt_enable(level);
        return RT_ERROR;
    }
    if (enabled) {
        rt_hw_interrupt_enable(level);
        return RT_EOK;
    }
    if (stopped_after_frame && now - stopped_us < DSHOT_MIN_FRAME_US) {
        rt_hw_interrupt_enable(level);
        return RT_EBUSY;
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        if (dshot_dma_active(i)
            || ((sent_mask & (1U << i)) && now - last_start_us[i] < DSHOT_MIN_FRAME_US)) {
            rt_hw_interrupt_enable(level);
            return RT_EBUSY;
        }
    }
    enabled = RT_TRUE;
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        if (configured_mask & (1U << i)) {
            dshot_start_channel(i, 1000U);
        }
    }
    rt_hw_interrupt_enable(level);
    return RT_EOK;
}

rt_err_t drv_dshot_disable(void)
{
    rt_base_t level = rt_hw_interrupt_disable();

    if (configured) {
        dshot_stop_all();
    }
    rt_hw_interrupt_enable(level);
    return RT_EOK;
}

rt_size_t drv_dshot_write(rt_uint16_t chan_sel, const rt_uint16_t* chan_val, rt_size_t size)
{
    rt_base_t level = rt_hw_interrupt_disable();
    uint64_t now = systime_now_us();
    uint32_t index = 0U;

    if (!configured || !enabled || chan_val == NULL || !dshot_valid_selection(chan_sel, size)) {
        goto rejected;
    }
    /* All-or-nothing: a busy channel must not partially update another motor,
     * nor overwrite a waveform/descriptor still being read by the DMA. */
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        cy_en_dma_intr_cause_t status;

        if ((chan_sel & (1U << i)) == 0U) {
            continue;
        }
        if ((sent_mask & (1U << i)) && now - last_start_us[i] < DSHOT_MIN_FRAME_US) {
            goto rejected;
        }
        status = Cy_DMA_Channel_GetStatus(DW1, i);
        if (dshot_dma_active(i)
            || ((sent_mask & (1U << i)) && !(completed_mask & (1U << i))
                && status != CY_DMA_INTR_CAUSE_COMPLETION)) {
            /* A frame must finish in under 60us. Missing triggers and DMA bus
             * faults therefore fail low instead of reusing stale data. */
            dshot_stop_all();
            goto rejected;
        }
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        if (chan_sel & (1U << i)) {
            uint16_t value = constrain_uint16(chan_val[index++], 1000U, 2000U);
            dshot_start_channel(i, value);
        }
    }
    rt_hw_interrupt_enable(level);
    return size;

rejected:
    rt_hw_interrupt_enable(level);
    return 0U;
}

rt_size_t drv_dshot_read(rt_uint16_t chan_sel, rt_uint16_t* chan_val, rt_size_t size)
{
    rt_base_t level = rt_hw_interrupt_disable();
    uint32_t index = 0U;

    if (!configured || chan_val == NULL || !dshot_valid_selection(chan_sel, size)) {
        rt_hw_interrupt_enable(level);
        return 0U;
    }
    for (uint32_t i = 0; i < E83_DSHOT_CHANNELS; i++) {
        if (chan_sel & (1U << i)) {
            chan_val[index++] = last_value[i];
        }
    }
    rt_hw_interrupt_enable(level);
    return size;
}

/******************************************************************************
 * Copyright 2024 The Firmament Authors. All Rights Reserved.
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

#include "hal/rc/ppm.h"
#include "hal/rc/rc.h"
#include "hal/rc/sbus.h"
#include "board/interface.h"
#include "board/protocol.h"

#include "cy_pdl.h"
#include "cycfg_peripherals.h"
#include "drv_rc.h"

#ifndef min // mod by prife
    #define min(x, y) (x < y ? x : y)
#endif

#define TIMER_FREQ_FALLBACK_HZ 1000000UL

#define RC_CONFIG_DEFAULT                      \
    {                                          \
        RC_PROTOCOL_AUTO, /* auto */           \
            6,            /* 6 channel */      \
            0.05f,        /* sample time */    \
            1000,         /* minimal 1000us */ \
            2000,         /* maximal 2000us */ \
    }

static ppm_decoder_t ppm_decoder;
static sbus_decoder_t sbus_decoder;

static uint32_t rc_get_timer_freq_hz(void)
{
    uint32_t timer_freq_hz = TIMER_FREQ_FALLBACK_HZ;
    uint32_t prescaler_div = (1UL << (RC_TIMER_config.clockPrescaler & 0x7UL));

#if defined(COMPONENT_MTB_HAL)
    if (RC_TIMER_hal_clock.interface != NULL &&
        RC_TIMER_hal_clock.interface->get_frequency_hz != NULL &&
        RC_TIMER_hal_clock.clock_ref != NULL) {
        timer_freq_hz = RC_TIMER_hal_clock.interface->get_frequency_hz(RC_TIMER_hal_clock.clock_ref);
    }
#endif

    if (prescaler_div == 0U || timer_freq_hz < prescaler_div) {
        return TIMER_FREQ_FALLBACK_HZ;
    }

    timer_freq_hz /= prescaler_div;

    return timer_freq_hz ? timer_freq_hz : TIMER_FREQ_FALLBACK_HZ;
}


#define TIMER_COUNT_MAX  UINT32_MAX
#define SYNC_GAP_THRESHOLD  40000

#define RC_THREAD_STACK_SIZE  2048
#define RC_THREAD_PRIORITY    3
#define RC_THREAD_TIMESLICE   5

static rt_thread_t rc_thread = RT_NULL;
static volatile uint32_t timer_tick_count;
static rc_capture_t rc_capture_buf[RC_CAPTURE_BUF_SIZE];
static volatile uint32_t rc_capture_index = 0;
static volatile uint8_t rc_capture_ready = 0;
static volatile uint8_t rc_capture_started = 0;

static uint8_t _ppm_recv = 0;
static uint8_t _ppm_sending = 0;

static uint32_t cc0_capture = 0;
static uint32_t last_cc0_capture = 0;

// RC运行状态标志
static volatile uint8_t rc_running = 0;

void RC_TIMER_IRQHandler(void)
{
    rt_interrupt_enter();

    uint32_t int_source = Cy_TCPWM_GetInterruptStatusMasked(RC_TIMER_HW, RC_TIMER_NUM);

    if (int_source & CY_TCPWM_INT_ON_CC0) {
        uint32_t capture = Cy_TCPWM_Counter_GetCapture0Val(RC_TIMER_HW, RC_TIMER_NUM);
        cc0_capture = capture;
        if (!rc_capture_ready) {
            uint32_t gap = 0;
            if (last_cc0_capture != 0) {
                if (capture > last_cc0_capture) {
                    gap = capture - last_cc0_capture;
                } else {
                    gap = capture + (TIMER_COUNT_MAX - last_cc0_capture + 1);
                }
            }
            last_cc0_capture = capture;
            if (gap > SYNC_GAP_THRESHOLD) {
                rc_capture_started = 1;
                rc_capture_index = 0;
                last_cc0_capture = capture;
                Cy_TCPWM_ClearInterrupt(RC_TIMER_HW, RC_TIMER_NUM, CY_TCPWM_INT_ON_CC0);
                rt_interrupt_leave();
                return;
            }

            if (rc_capture_started) {
                if (gap >= 4100) {
                    rc_capture_buf[rc_capture_index].capture = capture;
                    rc_capture_buf[rc_capture_index].gap = gap;
                    rc_capture_buf[rc_capture_index].type = 0;
                    rc_capture_index++;

                    if (rc_capture_index >= 8) {
                        rc_capture_ready = 1;
                        rc_capture_started = 0;
                    }
                }
            }
        }
        Cy_TCPWM_ClearInterrupt(RC_TIMER_HW, RC_TIMER_NUM, CY_TCPWM_INT_ON_CC0);
    }
    rt_interrupt_leave();
}
typedef struct {
    uint8_t chan_id;
    uint8_t total_chan;
    uint16_t last_ic;
    uint16_t ppm_val[16];  // 32字节
} ppm_encoder_t;
static ppm_encoder_t ppm_param;

rt_err_t rc_init(void)
{

    RT_TRY(ppm_decoder_init(&ppm_decoder, rc_get_timer_freq_hz()));

    ppm_param.chan_id = 0;
    ppm_param.total_chan = 0;
    ppm_param.last_ic = 0;
    memset(ppm_param.ppm_val, 0, sizeof(ppm_param.ppm_val));
    if (CY_TCPWM_SUCCESS != Cy_TCPWM_Counter_Init(RC_TIMER_HW, RC_TIMER_NUM, &RC_TIMER_config)) {
        return RT_ERROR;
    }

     Cy_TCPWM_Counter_Enable(RC_TIMER_HW, RC_TIMER_NUM);

    uint32_t saved_intr_status = mtb_hal_system_critical_section_enter();
    cy_stc_sysint_t intr_cfg;
    intr_cfg.intrSrc = (IRQn_Type)RC_TIMER_IRQ;
    intr_cfg.intrPriority = 6U;

    mtb_hal_system_critical_section_exit(saved_intr_status);

    Cy_TCPWM_TriggerStart_Single(RC_TIMER_HW, RC_TIMER_NUM);

    Cy_TCPWM_SetInterruptMask(RC_TIMER_HW, RC_TIMER_NUM, CY_TCPWM_INT_ON_CC0);

    if (CY_SYSINT_SUCCESS != Cy_SysInt_Init(&intr_cfg, RC_TIMER_IRQHandler)) {
        return RT_ERROR;
    }
    NVIC_EnableIRQ((IRQn_Type)RC_TIMER_IRQ);

    return RT_EOK;
}

static rt_err_t rc_control(rc_dev_t rc, int cmd, void* arg)
{
    switch (cmd) {
    case RC_CMD_CHECK_UPDATE: {
        uint8_t updated = 0;

        if (rc->config.protocol == RC_PROTOCOL_SBUS) {
            updated = sbus_data_ready(&sbus_decoder);
        } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
            updated = ppm_data_ready(&ppm_decoder);
        }

        *(uint8_t*)arg = updated;
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_uint16_t rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val)
{
    uint16_t* index = chan_val;
    rt_uint16_t rb = 0;
    uint8_t i;

    if (rc->config.protocol == RC_PROTOCOL_SBUS) {
        if (sbus_data_ready(&sbus_decoder) == 0) {
            return 0;
        }

        sbus_lock(&sbus_decoder);

        for (i = 0; i < min(rc->config.channel_num, sbus_decoder.rc_count); i++) {
            *(index++) = sbus_decoder.sbus_val[i];
            rb += 2;
        }
        sbus_data_clear(&sbus_decoder);

        sbus_unlock(&sbus_decoder);
    } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
        if (ppm_data_ready(&ppm_decoder) == 0) {
            return 0;
        }

        ppm_lock(&ppm_decoder);

        for (i = 0; i < min(rc->config.channel_num, ppm_decoder.total_chan); i++) {
            if (chan_mask & (1 << i)) {
                *(index++) = ppm_decoder.ppm_val[i];
                rb += 2;
            }
        }
        ppm_data_clear(&ppm_decoder);

        ppm_unlock(&ppm_decoder);
    }

    return rb;
}

const static struct rc_ops rc_ops = {
    .rc_init = NULL,
    .rc_config = NULL,
    .rc_control = rc_control,
    .rc_read = rc_read,
};

static struct rc_device rc_dev = {
    .config = RC_CONFIG_DEFAULT,
    .ops = &rc_ops,
};

rt_err_t drv_rc_init(void)
{
    RT_TRY(rc_init());
    RT_TRY(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}

void drv_rc_raw_gaps(void)
{
    if (!rc_capture_ready) {
        return;
    }
    static uint32_t last_val[8] = {0};
    #define DEADZONE_THRESHOLD 2

    for (uint32_t i = 0; i < rc_capture_index && i < 8; i++) {
        uint32_t val = rc_capture_buf[i].gap;

        uint32_t last_digit = val % 10;
        if (last_digit >= 5) {
            val = val + (10 - last_digit);
        }
        val = val / 10;
        if (last_val[i] != 0) {
            if (val > last_val[i]) {
                if (val - last_val[i] < DEADZONE_THRESHOLD) {
                    val = last_val[i];
                }
            } else {
                if (last_val[i] - val < DEADZONE_THRESHOLD) {
                    val = last_val[i];
                }
            }
        }
        last_val[i] = val;
    }
    ppm_param.total_chan = 8;
    for (uint8_t i = 0; i < 8; i++) {
        ppm_param.ppm_val[i] = last_val[i];
    }

    _ppm_recv = 1;

    uint32_t saved_intr_status = mtb_hal_system_critical_section_enter();
    rc_capture_index = 0;
    rc_capture_ready = 0;
    rc_capture_started = 0;
    last_cc0_capture = 0;
    mtb_hal_system_critical_section_exit(saved_intr_status);
}

static void rc_thread_entry(void* parameter)
{
    while (rc_running) {
        drv_rc_raw_gaps();

        // drv_rc_send_ppm();

        rt_thread_mdelay(10);
    }
}

void drv_rc_start_capture(void)
{
    uint32_t saved_intr_status = mtb_hal_system_critical_section_enter();
    rc_capture_index = 0;
    rc_capture_ready = 0;
    rc_capture_started = 0;
    last_cc0_capture = 0;
    mtb_hal_system_critical_section_exit(saved_intr_status);
}

rt_err_t drv_rc_thread_start(void)
{
    if (rc_running) {
        return RT_EOK;  // 已经在运行
    }

    rc_thread = rt_thread_create("rc_thread",
                                 rc_thread_entry,
                                 RT_NULL,
                                 RC_THREAD_STACK_SIZE,
                                 RC_THREAD_PRIORITY,
                                 RC_THREAD_TIMESLICE);
    if (rc_thread == RT_NULL) {
        return RT_ERROR;
    }
    rc_running = 1;
    rt_thread_startup(rc_thread);
    drv_rc_start_capture();
    return RT_EOK;
}

uint8_t drv_rc_send_ppm(void)
{
    if (!_ppm_recv) {
        return 0;
    }
    if (rc_signal_ready()) {
        _ppm_sending = 1;
        send_io_cmd(IO_CODE_RC_DATA, ppm_param.ppm_val, 32);
        _ppm_recv = 0;
        _ppm_sending = 0;

        return 1;
    }
    return 0;
}

void drv_rc_print_raw_gaps(void)
{
    rt_kprintf("rc_capture_ready=%d, rc_capture_started=%d, index=%d\n",
                 rc_capture_ready, rc_capture_started, rc_capture_index);
    if (!rc_capture_ready) {
        return;
    }

    static uint32_t last_val[8] = {0};
    #define DEADZONE_THRESHOLD 2

    rt_kprintf("\033[2J\033[H");
    rt_kprintf("========== PPM 8通道数据 ==========\n");

    for (uint32_t i = 0; i < rc_capture_index && i < 8; i++) {
        uint32_t val = rc_capture_buf[i].gap;

        uint32_t last_digit = val % 10;
        if (last_digit >= 5) {
            val = val + (10 - last_digit);
        }
        val = val / 10;
        if (last_val[i] != 0) {
            if (val > last_val[i]) {
                if (val - last_val[i] < DEADZONE_THRESHOLD) {
                    val = last_val[i];
                }
            } else {
                if (last_val[i] - val < DEADZONE_THRESHOLD) {
                    val = last_val[i];
                }
            }
        }
        last_val[i] = val;

        rt_kprintf("CH%u: %u\n", i + 1, val);
    }
    rt_kprintf("=====================================\n");

    uint32_t saved_intr_status = mtb_hal_system_critical_section_enter();
    rc_capture_index = 0;
    rc_capture_ready = 0;
    rc_capture_started = 0;
    last_cc0_capture = 0;
    mtb_hal_system_critical_section_exit(saved_intr_status);
}

rt_err_t drv_rc_deinit(void)
{
    if (!rc_running && rc_thread == RT_NULL) {
        return RT_EOK; 
    }
    rc_running = 0;
    if (rc_thread != RT_NULL) {
        for (int i = 0; i < 50; i++) {
            if (rc_thread->stat & RT_THREAD_STAT_MASK) {
                if ((rc_thread->stat & RT_THREAD_STAT_MASK) != RT_THREAD_RUNNING &&
                    (rc_thread->stat & RT_THREAD_STAT_MASK) != RT_THREAD_READY) {
                    break;
                }
            }
            rt_thread_mdelay(10);
        }
        rt_thread_delete(rc_thread);
        rc_thread = RT_NULL;
    }

    NVIC_DisableIRQ((IRQn_Type)RC_TIMER_IRQ);
    Cy_TCPWM_SetInterruptMask(RC_TIMER_HW, RC_TIMER_NUM, 0);
    Cy_TCPWM_ClearInterrupt(RC_TIMER_HW, RC_TIMER_NUM, CY_TCPWM_INT_ON_CC0);

    Cy_TCPWM_TriggerStopOrKill_Single(RC_TIMER_HW, RC_TIMER_NUM);
    Cy_TCPWM_Counter_Disable(RC_TIMER_HW, RC_TIMER_NUM);

    rc_capture_index = 0;
    rc_capture_ready = 0;
    rc_capture_started = 0;
    last_cc0_capture = 0;
    cc0_capture = 0;
    _ppm_recv = 0;
    _ppm_sending = 0;

    return RT_EOK;
}

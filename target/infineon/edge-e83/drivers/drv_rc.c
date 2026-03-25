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

#include "cy_pdl.h"
#include "cycfg_peripherals.h"

#ifndef min // mod by prife
    #define min(x, y) (x < y ? x : y)
#endif

#define TIMER_FREQ_HZ 1000000UL

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

void RC_TIMER_IRQHandler(void)
{
    rt_interrupt_enter();

    uint32_t int_source = Cy_TCPWM_GetInterruptStatusMasked(RC_TIMER_HW, RC_TIMER_NUM);

    if (int_source & CY_TCPWM_INT_ON_CC0) {
        uint32_t capture = Cy_TCPWM_Counter_GetCapture0Val(RC_TIMER_HW, RC_TIMER_NUM) + 1;
        ppm_update(&ppm_decoder, capture);
    }
    Cy_TCPWM_ClearInterrupt(RC_TIMER_HW, RC_TIMER_NUM, CY_TCPWM_INT_ON_CC0);

    rt_interrupt_leave();
}

static rt_err_t rc_init(rc_dev_t dev)
{
    (void)dev;

    RT_TRY(ppm_decoder_init(&ppm_decoder, TIMER_FREQ_HZ));

    if (CY_TCPWM_SUCCESS != Cy_TCPWM_Counter_Init(RC_TIMER_HW, RC_TIMER_NUM, &RC_TIMER_config)) {
        return RT_ERROR;
    }

    Cy_TCPWM_Counter_Enable(RC_TIMER_HW, RC_TIMER_NUM);
    Cy_TCPWM_TriggerStart_Single(RC_TIMER_HW, RC_TIMER_NUM);

    Cy_TCPWM_SetInterruptMask(RC_TIMER_HW, RC_TIMER_NUM, CY_TCPWM_INT_ON_CC0);

    cy_stc_sysint_t intr_cfg = {
        .intrSrc = RC_TIMER_IRQ,
        .intrPriority = 3U,
    };

    if (CY_SYSINT_SUCCESS != Cy_SysInt_Init(&intr_cfg, RC_TIMER_IRQHandler)) {
        return RT_ERROR;
    }

    NVIC_EnableIRQ(RC_TIMER_IRQ);

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
    .rc_init = rc_init,
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
    RT_TRY(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));
    return RT_EOK;
}
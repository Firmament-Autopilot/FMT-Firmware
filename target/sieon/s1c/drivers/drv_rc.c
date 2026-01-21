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

#include "hal/rc/ppm.h"
#include "hal/rc/rc.h"
#include "hal/rc/sbus.h"

#ifndef min // mod by prife
    #define min(x, y) (x < y ? x : y)
#endif

/* capture accuracy is 0.001ms */
#define PPM_DECODER_FREQUENCY 1000000

/* default config for rc device */
#define RC_CONFIG_DEFAULT                      \
    {                                          \
        RC_PROTOCOL_AUTO, /* auto */           \
            6,            /* 6 channel */      \
            0.05f,        /* sample time */    \
            1000,         /* minimal 1000us */ \
            2000,         /* maximal 2000us */ \
    }

static ppm_decoder_t  ppm_decoder;
static sbus_decoder_t sbus_decoder;

// #define TMRA_UNIT                       (CM_TMRA_4)
// #define TMRA_CH                         (TMRA_CH1)
// #define TMRA_PERIPH_CLK                 (FCG2_PERIPH_TMRA_4)
// #define TMRA_AOS_CAPT_REG               (AOS_TMRA_4)
// #define TMRA_CAPT_COND                  (TMRA_CAPT_COND_PWM_RISING)
// #define TMRA_CAPT_PWM_PORT              (GPIO_PORT_B)
// #define TMRA_CAPT_PWM_PIN               (GPIO_PIN_06)
// #define TMRA_CAPT_PWM_PIN_FUNC          (GPIO_FUNC_4)
// #define TMRA_CLK_DIV                    (TMRA_CLK_DIV64)	//(TMRA_CLK_DIV4)

/* Definitions of interrupt. */
// #define TMRA_INT_IRQn                   (INT082_IRQn)
// #define TMRA_INT_SRC                   (INT_SRC_TMRA_4_CMP)
// #define TMRA_INT_PRIO                   (DDL_IRQ_PRIO_03)
// #define TMRA_INT_TYPE                  (TMRA_INT_CMP_CH1)
// #define TMRA_INT_FLAG                   (TMRA_FLAG_CMP_CH1)

uint8_t ppmov = 0; 
uint16_t ppm_timex = 0;
uint16_t *rc_change_tmp = NULL;
uint16_t tmp_data_nums[10] = {0};
uint8_t nums_cnt = 0;
uint16_t tmp_data_nums_dex[10] = {0};
uint8_t nums_cnt_dex = 0;
uint16_t tmp_data_last =0;
void send_rc_channe(void)
{
    uint8_t i;
    if(rc_change_tmp != NULL)
    {
        for(i = 0; i< 10; i++)
            printf("%d ",rc_change_tmp[i]);
        printf("\n");
        for(i = 0; i< 9; i++)
            printf("%d ",tmp_data_nums[i]);
        printf("\n");
        for(i = 0; i< 9; i++)
            printf("%d ",tmp_data_nums_dex[i]);
        printf("\n\n");
    }

}

#define GET_GAP(x, y) (x > y ? (x - y) : (0xFFFF - y + x))
static void TMRA_IrqCallback(void)
{
    rt_interrupt_enter();
    ppm_timex = (TMRA_GetCompareValue(CM_TMRA_2, TMRA_CH4)/1.3125f)+1;
    ppm_update(&ppm_decoder, ppm_timex);
    TMRA_ClearStatus(CM_TMRA_2, TMRA_FLAG_CMP_CH4);
    rt_interrupt_leave();
}

void time4_test_init(void)
{
	stc_tmra_init_t stcTmraInit;
    // stc_clock_xtal_init_t stcXtalInit;
    stc_irq_signin_config_t stcIrq;
    LL_PERIPH_WE(LL_PERIPH_GPIO | LL_PERIPH_FCG | LL_PERIPH_PWC_CLK_RMU);


    /* 1. Enable TimerA peripheral clock. */
    FCG_Fcg2PeriphClockCmd(FCG2_PERIPH_TMRA_2, ENABLE);

    /* 2. Set a default initialization value for stcTmraInit. */
    (void)TMRA_StructInit(&stcTmraInit);

    /* 3. Modifies the initialization values depends on the application. */
    stcTmraInit.sw_count.u8ClockDiv = TMRA_CLK_DIV256;//TMRA_CLK_DIV128;//TMRA_CLK_DIV64;//TMRA_CLK_DIV4;
    // stcTmraInit.u32PeriodValue = 0xffff;
    // stcTmraInit.sw_count.u8CountMode = TMRA_MD_SAWTOOTH;
    // stcTmraInit.sw_count.u8CountDir  = TMRA_DIR_UP;
    (void)TMRA_Init(CM_TMRA_2, &stcTmraInit);

    /* 4. Set function mode as capturing mode. */
    TMRA_SetFunc(CM_TMRA_2, TMRA_CH4, TMRA_FUNC_CAPT);

    /* 5. Configures the capture condition. */
    GPIO_SetFunc(GPIO_PORT_D, GPIO_PIN_02, GPIO_FUNC_4);
    TMRA_HWCaptureCondCmd(CM_TMRA_2, TMRA_CH4, TMRA_CAPT_COND_PWM_RISING, ENABLE);

    /* 6. Configures IRQ if needed. */

    stcIrq.enIntSrc    = INT_SRC_TMRA_2_CMP;
    stcIrq.enIRQn      = INT078_IRQn;
    stcIrq.pfnCallback = &TMRA_IrqCallback;
    (void)INTC_IrqSignIn(&stcIrq);

    NVIC_ClearPendingIRQ(stcIrq.enIRQn);
    NVIC_SetPriority(stcIrq.enIRQn, DDL_IRQ_PRIO_03);
    NVIC_EnableIRQ(stcIrq.enIRQn);

    /* Enable the specified interrupts of TimerA. */
    TMRA_IntCmd(CM_TMRA_2, TMRA_INT_CMP_CH4, ENABLE);
	
    TMRA_Start(CM_TMRA_2);
}

static rt_err_t ppm_lowlevel_init(void)
{
    time4_test_init();
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
    uint16_t*   index = chan_val;
    rt_uint16_t rb    = 0;

    if (rc->config.protocol == RC_PROTOCOL_SBUS) {
        if (sbus_data_ready(&sbus_decoder) == 0) {
            /* no data received, just return */
            return 0;
        }

        sbus_lock(&sbus_decoder);

        for (uint8_t i = 0; i < min(rc->config.channel_num, sbus_decoder.rc_count); i++) {
            *(index++) = sbus_decoder.sbus_val[i];
            rb += 2;
        }
        sbus_data_clear(&sbus_decoder);

        sbus_unlock(&sbus_decoder);
    } else if (rc->config.protocol == RC_PROTOCOL_PPM) {
        if (ppm_data_ready(&ppm_decoder) == 0) {
            /* no data received, just return */
            return 0;
        }

        ppm_lock(&ppm_decoder);

        for (uint8_t i = 0; i < min(rc->config.channel_num, ppm_decoder.total_chan); i++) {
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
    .rc_config  = NULL,
    .rc_control = rc_control,
    .rc_read    = rc_read,
};

static struct rc_device rc_dev = {
    .config = RC_CONFIG_DEFAULT,
    .ops    = &rc_ops,
};

rt_err_t drv_rc_init(void)
{
    /* init ppm driver */
    RT_TRY(ppm_lowlevel_init());
    /* init ppm decoder */
    RT_TRY(ppm_decoder_init(&ppm_decoder, PPM_DECODER_FREQUENCY));

    // RT_TRY(sbus_lowlevel_init());
    RT_TRY(sbus_decoder_init(&sbus_decoder));

    RT_CHECK(hal_rc_register(&rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}
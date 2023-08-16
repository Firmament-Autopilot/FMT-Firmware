/******************************************************************************
 * Copyright 2021 The Firmament Authors. All Rights Reserved.
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

#include "module/task_manager/task_manager.h"
#include "module/workqueue/workqueue_manager.h"

#include "debuglog.h"
#include "hal/rc/rc.h"
#include "sys_event.h"

#include "ar1002_hal.h"
#include "board_device.h"

#include "local_task.h"
#include "sky_sbus.h"

cf_rc_s   sky_rc;
cf_sbus_s sky_sbus;

static rt_err_t    ar_rc_configure(rc_dev_t rc, struct rc_configure* cfg);
static rt_err_t    ar_rc_control(rc_dev_t rc, int cmd, void* arg);
static rt_uint16_t ar_rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val);

/* default config for rc device */
#define AR_RC_CONFIG_DEFAULT            \
    {                                   \
        1,         /* sbus */           \
            16,    /* 6 channel */      \
            0.05f, /* sample time */    \
            1000,  /* minimal 1000us */ \
            2000,  /* maximal 2000us */ \
    }

const static struct rc_ops _ar_rc_ops = {
    ar_rc_configure,
    ar_rc_control,
    ar_rc_read,
};

static struct rc_device ar_rc_dev = {
    .config = AR_RC_CONFIG_DEFAULT,
    .ops    = &_ar_rc_ops
};

typedef struct {
    uint32_t timestamp_ms;
    uint16_t rc_chan_val[16];
} ar_rc_data_t;

static ar_rc_data_t rc_data;
static uint8_t      rc_updated;

static rt_err_t ar_rc_configure(rc_dev_t rc, struct rc_configure* cfg)
{
    return RT_EOK;
}

static rt_err_t ar_rc_control(rc_dev_t rc, int cmd, void* arg)
{
    switch (cmd) {
    case RC_CMD_CHECK_UPDATE: {
        *(uint8_t*)arg = rc_updated;
    } break;

    default:
        break;
    }

    return RT_EOK;
}

static rt_uint16_t ar_rc_read(rc_dev_t rc, rt_uint16_t chan_mask, rt_uint16_t* chan_val)
{
    uint16_t* index = chan_val;

    if (!rc_updated)
        return 0;

    for (uint8_t i = 0; i < 16; i++) {
        if (chan_mask & (1 << i)) {
            *(index++) = rc_data.rc_chan_val[i];
        }
    }

    rc_updated = 0;

    return chan_mask;
}

rt_err_t register_ar_rc(void)
{
    /* register rc hal device */
    RT_CHECK(hal_rc_register(&ar_rc_dev, "rc", RT_DEVICE_FLAG_RDWR, NULL));

    return RT_EOK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

// void debug_sbus(void)
// {
//     static uint64_t t_last;
//     uint64_t t = HAL_GetSysUsTick();

//     // this task is 20hz = 50ms;
//     if (t - t_last < 1000000) {
//         return;
//     }

//     t_last = t;

//     DLOG_Critical("---------sky_rc----------");
//     DLOG_Critical("%d %d %d %d %d %d %d %d",
//                   rc_data.rc_chan_val[0],
//                   rc_data.rc_chan_val[1],
//                   rc_data.rc_chan_val[2],
//                   rc_data.rc_chan_val[3],
//                   rc_data.rc_chan_val[4],
//                   rc_data.rc_chan_val[5],
//                   rc_data.rc_chan_val[6],
//                   rc_data.rc_chan_val[7]);

//     DLOG_Critical("%d %d %d %d %d %d %d %d",
//                   rc_data.rc_chan_val[8],
//                   rc_data.rc_chan_val[9],
//                   rc_data.rc_chan_val[10],
//                   rc_data.rc_chan_val[11],
//                   rc_data.rc_chan_val[12],
//                   rc_data.rc_chan_val[13],
//                   rc_data.rc_chan_val[14],
//                   rc_data.rc_chan_val[15]);
// }

static void cf_sbus_parse(void) // just for test
{
    uint32_t ch_sbus[16];
    // check the head & end
    if ((sky_sbus.sbus_buff[0] != 0x0F) || (sky_sbus.sbus_buff[24] != 0x00)) {
        return;
    }

    // parse the sbus
    ch_sbus[0]  = ((uint32_t)sky_sbus.sbus_buff[1] >> 0 | ((uint32_t)sky_sbus.sbus_buff[2] << 8)) & 0x07FF;
    ch_sbus[1]  = ((uint32_t)sky_sbus.sbus_buff[2] >> 3 | ((uint32_t)sky_sbus.sbus_buff[3] << 5)) & 0x07FF;
    ch_sbus[2]  = ((uint32_t)sky_sbus.sbus_buff[3] >> 6 | ((uint32_t)sky_sbus.sbus_buff[4] << 2) | (uint32_t)sky_sbus.sbus_buff[5] << 10) & 0x07FF;
    ch_sbus[3]  = ((uint32_t)sky_sbus.sbus_buff[5] >> 1 | ((uint32_t)sky_sbus.sbus_buff[6] << 7)) & 0x07FF;
    ch_sbus[4]  = ((uint32_t)sky_sbus.sbus_buff[6] >> 4 | ((uint32_t)sky_sbus.sbus_buff[7] << 4)) & 0x07FF;
    ch_sbus[5]  = ((uint32_t)sky_sbus.sbus_buff[7] >> 7 | ((uint32_t)sky_sbus.sbus_buff[8] << 1) | (uint32_t)sky_sbus.sbus_buff[9] << 9) & 0x07FF;
    ch_sbus[6]  = ((uint32_t)sky_sbus.sbus_buff[9] >> 2 | ((uint32_t)sky_sbus.sbus_buff[10] << 6)) & 0x07FF;
    ch_sbus[7]  = ((uint32_t)sky_sbus.sbus_buff[10] >> 5 | ((uint32_t)sky_sbus.sbus_buff[11] << 3)) & 0x07FF;
    ch_sbus[8]  = ((uint32_t)sky_sbus.sbus_buff[12] << 0 | ((uint32_t)sky_sbus.sbus_buff[13] << 8)) & 0x07FF;
    ch_sbus[9]  = ((uint32_t)sky_sbus.sbus_buff[13] >> 3 | ((uint32_t)sky_sbus.sbus_buff[14] << 5)) & 0x07FF;
    ch_sbus[10] = ((uint32_t)sky_sbus.sbus_buff[14] >> 6 | ((uint32_t)sky_sbus.sbus_buff[15] << 2) | (uint32_t)sky_sbus.sbus_buff[16] << 10) & 0x07FF;
    ch_sbus[11] = ((uint32_t)sky_sbus.sbus_buff[16] >> 1 | ((uint32_t)sky_sbus.sbus_buff[17] << 7)) & 0x07FF;
    ch_sbus[12] = ((uint32_t)sky_sbus.sbus_buff[17] >> 4 | ((uint32_t)sky_sbus.sbus_buff[18] << 4)) & 0x07FF;
    ch_sbus[13] = ((uint32_t)sky_sbus.sbus_buff[18] >> 7 | ((uint32_t)sky_sbus.sbus_buff[19] << 1) | (uint32_t)sky_sbus.sbus_buff[20] << 9) & 0x07FF;
    ch_sbus[14] = ((uint32_t)sky_sbus.sbus_buff[20] >> 2 | ((uint32_t)sky_sbus.sbus_buff[21] << 6)) & 0x07FF;
    ch_sbus[15] = ((uint32_t)sky_sbus.sbus_buff[21] >> 5 | ((uint32_t)sky_sbus.sbus_buff[22] << 3)) & 0x07FF;

    for (int i = 0; i < 16; i++) {
        rc_data.rc_chan_val[i] = (uint16_t)(ch_sbus[i] * 1000 / 2048 + 1000);
    }

    rc_data.timestamp_ms = (uint32_t)(sky_sbus.timestamp / 1000);

    rc_updated = 1;
}

/**
 * @brief  read BaseBand data,then Output from Hal uart.
 * @param  data and data len
 * @retval date len
 * @note   This function only called by sky
 */

void sky_bb_spi_irq_handler(void* p)
{

#define BB_READ_MAX_LEN 32
    uint32_t  cnt;
    uint8_t   buffer[BB_READ_MAX_LEN];
    HAL_RET_T ret;
    uint8_t   i;

    cnt = 0;
    ret = HAL_BB_ComReceiveMsg(BB_COM_SESSION_SPI, buffer, BB_READ_MAX_LEN, &cnt);

    if (ret != HAL_OK && cnt != 0) {
        // DLOG_Error("failed read bbcom %02lx, %ld", ret, cnt);
        return;
    }

    if (cnt > 0 && cnt <= BB_READ_MAX_LEN) {

        if (cnt != 25) {
            // DLOG_Error("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7], buffer[8], buffer[9]);
        }

        for (i = 0; i < 25; i++) {
            sky_sbus.sbus_buff[i] = buffer[i];
        }

        sky_sbus.timestamp = HAL_GetSysUsTick();
        cf_sbus_parse();

    } else {
        // DLOG_Info("bb read %ld", cnt);
    }
}

static void run_sbus_init(void* parameter)
{
    HAL_RET_T ret;

    // init BaseBand rt-uart function
    ret = HAL_BB_SpiDataTransInit(25);

    if (ret != HAL_OK) {
        DLOG_Error("BB SPI init failed");
    }

    // register BaseBand rt-uart session, will malloc a special session to rt-uart function
    ret = HAL_BB_ComRegisterSession(BB_COM_SESSION_SPI,
                                    BB_COM_SESSION_PRIORITY_HIGH,
                                    BB_COM_SESSION_DATA_NORMAL,
                                    sky_bb_spi_irq_handler);

    if (ret != HAL_OK) {
        DLOG_Error("BB ComRegister failed");
    }
}

static struct WorkItem sbus_init_item = {
    .name          = "sbus_init",
    .period        = 0,
    .schedule_time = 3000,
    .run           = run_sbus_init
};

void sbus_start(void)
{
    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");

    RT_ASSERT(lp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(lp_wq, &sbus_init_item));
}

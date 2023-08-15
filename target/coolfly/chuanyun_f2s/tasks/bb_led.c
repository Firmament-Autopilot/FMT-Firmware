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

#include "ar1002_hal.h"
#include "bb_match_id.h"
#include "board.h"
#include "board_device.h"
#include "debuglog.h"
#include "sys_event.h"

#include "bb_led.h"

LINK_LED_STATUS _link_led_status;

_EXT_DTCM1
static void link_led_fasttoggle(void)
{
    static uint8_t toggle_flag = 0;

    if (toggle_flag) {
        toggle_flag = 0;
        HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_SET);
    } else {
        toggle_flag = 1;
        HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_RESET);
    }
}

_EXT_DTCM1
static void link_led_slowtoggle(void)
{
    static uint8_t cnt = 0;
    cnt++;
    if (cnt % 4 == 0) {
        link_led_fasttoggle();
    }
}

_EXT_DTCM1
static void link_led_on(void)
{
    HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_RESET);
}

_EXT_DTCM1
static void link_led_off(void)
{
    HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_SET);
}

/////////////////////////////////////////////////////

_EXT_DTCM1
void set_link_led_status_searchid(void)
{
    _link_led_status = LINK_SEARCH_ID;
}

_EXT_DTCM1
void set_link_led_status_lock(void)
{
    _link_led_status = LINK_LOCK;
}

_EXT_DTCM1
void set_link_led_status_unlock(void)
{
    _link_led_status = LINK_UNLOCK;
}

_EXT_DTCM1
void set_link_led_status_notmatch(void)
{
    _link_led_status = LINK_ID_NO_MATCH;
}

_EXT_DTCM1
LINK_LED_STATUS get_link_led_status(void)
{
    return _link_led_status;
}

/////////////////////////////////////////////////////

_EXT_DTCM1
void bb_led_status_EventHandler(void* p)
{
    STRU_SysEvent_DEV_BB_STATUS* pstru_status = (STRU_SysEvent_DEV_BB_STATUS*)p;

    if (pstru_status->pid == BB_LOCK_STATUS) {
        if (pstru_status->lockstatus == 3) {
            set_link_led_status_lock();
        } else {
            if (get_link_led_status() != LINK_SEARCH_ID) {
                set_link_led_status_unlock();
            }
        }
    } else if (pstru_status->pid == BB_GOT_ERR_CONNNECT) {
        if (pstru_status->lockstatus) {
            if (get_link_led_status() != LINK_SEARCH_ID) {
                set_link_led_status_notmatch();
            }
        } else {
            DLOG_Info("not got signal");
        }
    }
}

/////////////////////////////////////////////////////

_EXT_DTCM1
float GndSnr2Score(float snr)
{
    return (3.52 * snr + 19.057);
}

_EXT_DTCM1
float SkySnr2Score(float snr)
{
    return (7.7 * snr + 27);
}

_EXT_DTCM1
int GndErrCnt2Score(int errCnt)
{
    if (errCnt < 5) {
        return 2;
    } else if (errCnt < 10) {
        return 5;
    } else if (errCnt < 20) {
        return 10;
    } else if (errCnt < 30) {
        return 20;
    } else if (errCnt < 40) {
        return 30;
    } else if (errCnt < 50) {
        return 40;
    } else if (errCnt < 55) {
        return 50;
    } else {
        return 55;
    }
}

_EXT_DTCM1
uint8_t GndSigQuality(int errCnt, float snr)
{
    float score, snr_db;

    snr_db = log10(snr / 64) * 10;

    score = GndSnr2Score(snr_db) - GndErrCnt2Score(errCnt);
    if (score <= 0) {
        return 0;
    } else if (score >= 100) {
        return 100;
    } else {
        return (uint8_t)score;
    }
}

_EXT_DTCM1
uint8_t SkySigQuality(int lockCnt, float snr)
{
    float score, snr_db;

    snr_db = log10(snr / 64) * 10;
    score  = SkySnr2Score(snr_db) * lockCnt / 100;
    if (score <= 0) {
        return 0;
    } else if (score >= 100) {
        return 100;
    } else {
        return (uint8_t)score;
    }
}

int g_rssi[2];

double g_snr_sky;
int    g_connect_status[4] = { 0, 0, 0, 0 };
double g_ldpc_error;

_EXT_DTCM1
static void run_bb_led(void* parameter)
{
    // ////////////////////////////////
    // STRU_DEVICE_INFO p;
    // STRU_DEVICE_INFO       *pstDeviceInfo =(STRU_DEVICE_INFO*) &p;

    // DLOG_Critical("_link_led_status = %d ",_link_led_status);
    // if(HAL_BB_GetDeviceInfo(&pstDeviceInfo) != HAL_OK)
    // {
    //     DLOG_Critical("failed");
    //     return;
    // }

    // if(pstDeviceInfo->inSearching) //0,un search, 1 , searching
    // {
    //     link_led_fasttoggle();
    //     return;
    // }

    // link_status = _link_led_status;
    if (_link_led_status == LINK_UNLOCK) {
        link_led_off();
    } else if (_link_led_status == LINK_LOCK) {
        link_led_on();
    } else if (_link_led_status == LINK_SEARCH_ID) {
        link_led_fasttoggle();
    } else if (_link_led_status == LINK_ID_NO_MATCH) {
        link_led_slowtoggle();
    }

    if (LINK_LOCK == _link_led_status) {
        g_connect_status[0] = 1;

    } else {
        g_connect_status[0] = 0;
    }

    ////////////////////////////////////////////////////
    uint8_t*                    p;
    HAL_RET_T                   ret;
    STRU_WIRELESS_INFO_DISPLAY* pst_bbInfoAddr = (STRU_WIRELESS_INFO_DISPLAY*)&p;
    ;
    uint8_t sky_sig;
    ret = HAL_BB_GetInfo(&pst_bbInfoAddr);

    if ((pst_bbInfoAddr == NULL)) {
        printf("failed %lx", ret);
    }

    sky_sig = GndSigQuality(pst_bbInfoAddr->errcnt1, pst_bbInfoAddr->snr_vlaue[1]);

    g_snr_sky = sky_sig * 1.0f;

    g_rssi[0] = pst_bbInfoAddr->agc_value[0]; // rssia
    g_rssi[1] = pst_bbInfoAddr->agc_value[1]; // rssib

    // printf("gnd_sig = %d SNR= %d sky_sig = %d SNR= %d\r\n", gnd_sig, pst_bbInfoAddr->snr_vlaue[1], sky_sig,
    // 	      pst_bbInfoAddr->sky_snr);

    // printf("g_snr_sky = %f \r\n", (float)g_snr_sky);

    g_ldpc_error = pst_bbInfoAddr->ldpc_error * 1.0f;

    if (g_connect_status[0] == 0) {
        g_snr_sky = 0;

        g_rssi[0] = 0;
        g_rssi[1] = 0;

        g_ldpc_error = 0;
    }
}

_EXT_DTCM1_BSS
static struct WorkItem bb_led_item = {
    .name          = "bb_led",
    .period        = 50,
    .schedule_time = 1000,
    .run           = run_bb_led
};

_EXT_DTCM1
void bb_led_start(void)
{
    WorkQueue_t hp_wq = workqueue_find("wq:hp_work");

    RT_ASSERT(hp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(hp_wq, &bb_led_item));
}

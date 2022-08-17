/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: test_search_id
Description: 
Author: Artosy Software Team
Version: 0.0.1
Date: 2017/12/14
History:
         0.0.1    2017/12/14    test_search_id
*****************************************************************************/

#include <firmament.h>

#include "module/task_manager/task_manager.h"
#include "module/workqueue/workqueue_manager.h"

#include "debuglog.h"
#include "sys_event.h"
#include "bb_match_id.h"
#include "ar1002_hal.h"
#include "board_device.h"
#include "board.h"

#include "bb_led.h"

uint32_t flag_searchIdTimerStart = 0;
uint8_t vt_id_timer_start_flag = 0;

_EXT_DTCM1 void BB_skyRcIdEventHandler(void* p)
{
    STRU_SysEvent_DEV_BB_STATUS* pstru_status = (STRU_SysEvent_DEV_BB_STATUS*)p;
    uint8_t id[7];

    if (pstru_status->pid == BB_GET_RCID) {
        DLOG_Critical("Get rcid: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x,rssi_a %d, rssi_b %d", pstru_status->rcid[0], pstru_status->rcid[1],
                                                                       pstru_status->rcid[2], pstru_status->rcid[3], pstru_status->rcid[4],
                                                                       pstru_status->agc1,pstru_status->agc2);
    }

    if (pstru_status->pid == BB_SKY_SEARCHING_STATES_CHAGE) {
        if (SKY_WAIT_VT_ID_MSG == pstru_status->e_sky_searchState) {
            DLOG_Warning("search id: SKY_WAIT_VT_ID_MSG");
        } else if (SKY_WAIT_RC_ID_MATCH == pstru_status->e_sky_searchState) {
            memcpy(id, pstru_status->vtid, 2);
            memcpy(id + 2, pstru_status->rcid, 5);
            add_dev_info(id, pstru_status->agc1, pstru_status->agc2);

            if (!vt_id_timer_start_flag) {
                vt_id_timer_start_flag = 1;
                HAL_TIMER_Start(GET_VT_ID_TIMER);
                DLOG_Warning("got vtid: %dus timer start",GET_VT_ID_TIMEOUT);
            }
            DLOG_Warning("search id: SKY_WAIT_RC_ID_MATCH");
        } else if (SKY_RC_SEARCH_END == pstru_status->e_sky_searchState) {
             DLOG_Warning("search id: SKY_RC_SEARCH_END rc id: %x %x %x %x %x; vt id: %x %x",
                           pstru_status->rcid[0], pstru_status->rcid[1], pstru_status->rcid[2], pstru_status->rcid[3], pstru_status->rcid[4],
                           pstru_status->vtid[0], pstru_status->vtid[1]);

            if (flag_searchIdTimerStart) {
                HAL_TIMER_Stop(SEARCH_ID_TIMER);
                flag_searchIdTimerStart = 0;
                vt_id_timer_start_flag = 0;
            }
        }
    }
}

uint8_t timeout_loop = 0;
_EXT_DTCM1 void TIMHAL_IRQSearchIdHandler(uint32_t u32_vectorNum)
{
    if (timeout_loop++ > 6) {
        DLOG_Warning("search time out %d us", SEARCH_ID_TIMEOUT*timeout_loop);
        HAL_TIMER_Stop(SEARCH_ID_TIMER);
        flag_searchIdTimerStart = 0;
        HAL_BB_StopSearchRcId();
        timeout_loop = 0;
        vt_id_timer_start_flag = 0;

        set_link_led_status_unlock();
    }
}

_EXT_DTCM1 void TIMHAL_IRQGetVtIdHandler(uint32_t u32_vectorNum)
{
    uint8_t id[7];

    get_nearest_dev_info(id);
    HAL_BB_SetObjRcVtId(id + 2, id);
    HAL_TIMER_Stop(GET_VT_ID_TIMER);
}

_EXT_DTCM1 void BB_Sky_SearchIdHandler(void* p)
{
    if (flag_searchIdTimerStart) {
        HAL_TIMER_Stop(SEARCH_ID_TIMER);
        flag_searchIdTimerStart = 0;
    }

    if (HAL_OK == HAL_TIMER_RegisterTimer(SEARCH_ID_TIMER, SEARCH_ID_TIMEOUT, TIMHAL_IRQSearchIdHandler)) {
        flag_searchIdTimerStart = 1;
    } else {
        DLOG_Critical("HAL_TIMER_RegisterTimer fail");
    }

    if (vt_id_timer_start_flag) {
        HAL_TIMER_Stop(GET_VT_ID_TIMER);
        vt_id_timer_start_flag = 0;
    }
    if (HAL_OK == HAL_TIMER_RegisterTimer(GET_VT_ID_TIMER, GET_VT_ID_TIMEOUT, TIMHAL_IRQGetVtIdHandler)) {
        //flag_searchIdTimerStart = 1;
        HAL_TIMER_Stop(GET_VT_ID_TIMER);
        vt_id_timer_start_flag = 0;
    } else {
        DLOG_Critical("HAL_TIMER_RegisterTimer fail1");
    }

    timeout_loop = 0;

    reset_dev_info();

    HAL_TIMER_Start(SEARCH_ID_TIMER);
    HAL_BB_EnableSearchRcIdByRssi();

    HAL_BB_SearchRcId(1);

    set_link_led_status_searchid();
    DLOG_Critical("search id enter");
}

//////////////////////////////////////////////////////////////////////

#define MAX_SEARCH_DEV_ID_NUM (8)
#define DEV_ID_LEN            (7)

#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct
{
    uint8_t id[DEV_ID_LEN]; //head 2 byte vt id, tail 5 byte rc id
    uint16_t rssi_a;
    uint16_t rssi_b;
} STRU_ID_AND_RSSI;

typedef struct
{
    STRU_ID_AND_RSSI dev_info[MAX_SEARCH_DEV_ID_NUM];
    uint8_t index;
} STRU_DEV_INFO_LIST;

static STRU_DEV_INFO_LIST st_DevInfoList;

_EXT_DTCM1
void print_dev_list_info(void)
{
    uint8_t i;

    for (i = 0; i < st_DevInfoList.index; i++) {
        DLOG_Warning("vt:%02x,%02x,rc:%02x %02x %02x %02x %02x,rssi %d,%d",
                     st_DevInfoList.dev_info[i].id[0],
                     st_DevInfoList.dev_info[i].id[1],
                     st_DevInfoList.dev_info[i].id[2],
                     st_DevInfoList.dev_info[i].id[3],
                     st_DevInfoList.dev_info[i].id[4],
                     st_DevInfoList.dev_info[i].id[5],
                     st_DevInfoList.dev_info[i].id[6],
                     st_DevInfoList.dev_info[i].rssi_a,
                     st_DevInfoList.dev_info[i].rssi_b);
    }
}

_EXT_DTCM1
uint8_t find_farthest_dev(void)
{
    uint8_t i;
    uint8_t rssi, farthest_dev;

    rssi = 0;
    farthest_dev = 0;
    for (i = 0; i < MAX_SEARCH_DEV_ID_NUM; i++) {
        uint8_t avg_rssi;
        avg_rssi = (st_DevInfoList.dev_info[i].rssi_a + st_DevInfoList.dev_info[i].rssi_b) / 2;
        if (avg_rssi > rssi) {
            rssi = avg_rssi;
            farthest_dev = i;
        }
    }

    return farthest_dev;
}

_EXT_DTCM1
uint8_t select_nearest_dev(void)
{
    uint8_t i, rssi, nearest_dev;

    nearest_dev = 0;

    if (st_DevInfoList.index == 1) {
        return nearest_dev;
    }

    rssi = MIN(st_DevInfoList.dev_info[nearest_dev].rssi_a, st_DevInfoList.dev_info[nearest_dev].rssi_b);

    for (i = 1; i < st_DevInfoList.index; i++) {
        uint8_t min_rssi;
        min_rssi = MIN(st_DevInfoList.dev_info[i].rssi_a, st_DevInfoList.dev_info[i].rssi_b);
        if (min_rssi < rssi) {
            rssi = min_rssi;
            nearest_dev = i;
        }
    }

    return nearest_dev;
}

_EXT_DTCM1
void add_dev_info(uint8_t* pid, uint8_t rssi_a, uint8_t rssi_b)
{
    uint8_t i, j;
    uint8_t bFind, bIsOverMaxSupportDevNum, cnt;

    bFind = false;
    bIsOverMaxSupportDevNum = false;

    for (i = 0; i < st_DevInfoList.index; i++) {
        cnt = 0;
        for (j = 0; j < DEV_ID_LEN; j++) {
            if (st_DevInfoList.dev_info[i].id[j] == pid[j]) {
                cnt++;
            }
        }

        if (cnt == DEV_ID_LEN) {
            bFind = true;
            break;
        }
    }

    if (bFind) {
        st_DevInfoList.dev_info[i].rssi_a += rssi_a;
        st_DevInfoList.dev_info[i].rssi_a /= 2;
        st_DevInfoList.dev_info[i].rssi_b += rssi_b;
        st_DevInfoList.dev_info[i].rssi_b /= 2;
        return;
    }

    if (st_DevInfoList.index >= MAX_SEARCH_DEV_ID_NUM) {
        DLOG_Critical("over max %d support search dev num",MAX_SEARCH_DEV_ID_NUM);
        bIsOverMaxSupportDevNum = true;
    }

    if (bIsOverMaxSupportDevNum) {
        uint8_t farthest_dev;
        farthest_dev = find_farthest_dev();

        if ((st_DevInfoList.dev_info[farthest_dev].rssi_a + st_DevInfoList.dev_info[farthest_dev].rssi_b)
            < (rssi_a + rssi_b)) {
            return;
        }

        for (i = 0; i < DEV_ID_LEN; i++)
            st_DevInfoList.dev_info[farthest_dev].id[i] = pid[i];

        st_DevInfoList.dev_info[farthest_dev].rssi_a = rssi_a;
        st_DevInfoList.dev_info[farthest_dev].rssi_b = rssi_b;
        return;
    }

    for (i = 0; i < DEV_ID_LEN; i++)
        st_DevInfoList.dev_info[st_DevInfoList.index].id[i] = pid[i];

    st_DevInfoList.dev_info[st_DevInfoList.index].rssi_a = rssi_a;
    st_DevInfoList.dev_info[st_DevInfoList.index].rssi_b = rssi_b;
    st_DevInfoList.index++;
    DLOG_Warning("add vt:%02x,%02x,rc:%02x,%02x,%02x,%02x,%02x,rssi:%d %d", pid[0], pid[1], pid[2], pid[3], pid[4], pid[5], pid[6], rssi_a, rssi_b);
    return;
}

_EXT_DTCM1
void get_nearest_dev_info(uint8_t* pid)
{
    uint8_t pos;

    print_dev_list_info();
    pos = select_nearest_dev();
    memcpy(pid, st_DevInfoList.dev_info[pos].id, DEV_ID_LEN);
    DLOG_Warning("select %02x,%02x,%02x,%02x,%02x,%02x,%02x,rssi:%d %d", pid[0], pid[1], pid[2], pid[3], pid[4], pid[5], pid[6], st_DevInfoList.dev_info[pos].rssi_a, st_DevInfoList.dev_info[pos].rssi_b);
}

_EXT_DTCM1
void reset_dev_info(void)
{
    memset(&st_DevInfoList, 0, sizeof(st_DevInfoList));
}

///////////////////////////////////////////////////////////////////////
//      bb_match
///////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
_EXT_DTCM1
static void run_bb_match_id(void* parameter)
{
    static uint8_t cnt = 0;
    static uint32_t pin_value;

    HAL_GPIO_GetPin(EXTERN_SEARCH_ID_PIN, &pin_value);
    if (pin_value == 0) {
        cnt++;
        if (cnt >= 10) {
            cnt = 0;
            DLOG_Warning("pin search id start");
            BB_Sky_SearchIdHandler(NULL);
            set_link_led_status_searchid();
        }
    } else {
        cnt = 0;
    }
}

_EXT_DTCM1_BSS
static struct WorkItem bb_match_id_item = {
    .name = "bb_match_id",
    .period = 200,
    .schedule_time = 1000,
    .run = run_bb_match_id
};

_EXT_DTCM1
void bb_match_id_start(void)
{
    HAL_GPIO_InPut(EXTERN_SEARCH_ID_PIN);

    SYS_EVENT_RegisterHandler(SYS_EVENT_ID_BB_EVENT, BB_skyRcIdEventHandler);

    WorkQueue_t lp_wq = workqueue_find("wq:lp_work");

    RT_ASSERT(lp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(lp_wq, &bb_match_id_item));
}
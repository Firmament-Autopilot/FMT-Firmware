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
#include "sys_event.h"
#include "bb_match_id.h"
#include "ar1002_hal.h"
#include "board_device.h"
#include "board.h"

#include "bb_led.h"

LINK_LED_STATUS _link_led_status;


_EXT_DTCM1 
static void link_led_fasttoggle(void)
{
    static uint8_t toggle_flag = 0;

    if(toggle_flag)
    {
        toggle_flag = 0;
        HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_SET);
    }
    else
    {
        toggle_flag = 1;
        HAL_GPIO_SetPin(LINK_LED_GPIO, HAL_GPIO_PIN_RESET);
    }
}

_EXT_DTCM1 
static void link_led_slowtoggle(void)
{
    static uint8_t cnt = 0;
    cnt++;
    if(cnt%4 == 0)
    {
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
void bb_led_status_EventHandler(void *p)
{
    STRU_SysEvent_DEV_BB_STATUS *pstru_status = (STRU_SysEvent_DEV_BB_STATUS *)p;

    if (pstru_status->pid == BB_LOCK_STATUS)
    {
        if (pstru_status->lockstatus == 3)
        {
            set_link_led_status_lock();
        }
        else
        {
            if(get_link_led_status() != LINK_SEARCH_ID)
            {
                set_link_led_status_unlock();
            }
        }
    }
    else if(pstru_status->pid == BB_GOT_ERR_CONNNECT)
    {        
        if (pstru_status->lockstatus)        
        {           
            if(get_link_led_status() != LINK_SEARCH_ID)
            {
                set_link_led_status_notmatch();
            }
        }       
        else        
        {            
            DLOG_Info("not got signal");     
        }    
    }
}

/////////////////////////////////////////////////////

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
    if(_link_led_status == LINK_UNLOCK)
    {
        link_led_off();
    }
    else if(_link_led_status == LINK_LOCK)
    {
        link_led_on();
    }
    else if(_link_led_status == LINK_SEARCH_ID)
    {
        link_led_fasttoggle();
    }
    else if(_link_led_status == LINK_ID_NO_MATCH)
    {
        link_led_slowtoggle();
    }

    // DLOG_Critical("_link_led_status = %d ",_link_led_status);
}


_EXT_DTCM1_BSS 
static struct WorkItem bb_led_item = {
    .name = "bb_led",
    .period = 50,
    .schedule_time = 1000,
    .run = run_bb_led
};

_EXT_DTCM1 
void bb_led_start(void)
{
    SYS_EVENT_RegisterHandler(SYS_EVENT_ID_BB_EVENT, bb_led_status_EventHandler);

    WorkQueue_t hp_wq = workqueue_find("wq:hp_work");
    
    RT_ASSERT(hp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(hp_wq, &bb_led_item));
}


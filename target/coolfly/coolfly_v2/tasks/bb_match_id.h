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

#ifndef BB_MATCH_ID_H__
#define BB_MATCH_ID_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SEARCH_ID_TIMER   (HAL_TIMER_NUM16)
#define SEARCH_ID_TIMEOUT (10 * 1000 * 1000) //10 second

#define EXTERN_SEARCH_ID_PIN (HAL_GPIO_NUM39)
#define KEY_LONG_PRESS       (1000)
#define READ_INTERVAL        (200)
#define GET_VT_ID_TIMER      (HAL_TIMER_NUM17)
#define GET_VT_ID_TIMEOUT    (10 * 1000 * 1000) //10 second

void BB_Sky_SearchIdHandler(void* p);

void BB_skyRcIdEventHandler(void* p);

void add_dev_info(uint8_t* pid, uint8_t rssi_a, uint8_t rssi_b);

void get_nearest_dev_info(uint8_t* pid);

void reset_dev_info(void);

void set_link_led_status_searchid(void);
void set_link_led_status_unlock(void);

void bb_match_id_start(void);

#ifdef __cplusplus
}
#endif

#endif

#ifndef __BB_LED_H__
#define __BB_LED_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    LINK_UNLOCK = 0,
    LINK_LOCK,
    LINK_SEARCH_ID,
    LINK_ID_NO_MATCH,
    LINK_INVALID
} LINK_LED_STATUS;

void            set_link_led_status_searchid(void);
LINK_LED_STATUS get_link_led_status(void);
void            bb_led_start(void);

void bb_led_status_EventHandler(void* p);

#ifdef __cplusplus
}
#endif

#endif

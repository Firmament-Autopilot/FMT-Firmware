/*
 * Copyright (c) 2018-2020, Firmament Autopilot Team. All rights reserved.
 *
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-05-29     yangjian     the first version
 */

#ifndef BUZZER_H__
#define BUZZER_H__

#ifdef __cplusplus
extern "C" {
#endif

void tone_play_startup(void);
int buzzer_on(void);
int buzzer_off(void);
int buzzer_init(void);
void buzzer_start_note(unsigned frequency);

#ifdef __cplusplus
}
#endif

#endif /* BUZZER_H__ */

/*
 * Copyright (c) 2018-2020, Firmament Autopilot Team. All rights reserved.
 *
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-05-29     yangjian     the first version
 */


#ifndef __TONE_H__
#define __TONE_H__

void tone_play_startup(void);
int buzzer_on(void);
int buzzer_off(void);
int buzzer_init(void);
void buzzer_start_note(unsigned frequency);

#endif /* __TONE_H__ */

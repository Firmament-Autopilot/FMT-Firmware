/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
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

#ifndef BUZZER_TUNE_H__
#define BUZZER_TUNE_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TUNE_STARTUP  0
#define TUNE_ERROR    1
#define TUNE_SD_ERROR 2

int buzzer_tune_init(void);
int buzzer_tune_play(int tune);

void tone_play_startup(void);
int  buzzer_on(void);
int  buzzer_off(void);
int  buzzer_init(void);
void buzzer_start_note(unsigned frequency);

#ifdef __cplusplus
}
#endif

#endif

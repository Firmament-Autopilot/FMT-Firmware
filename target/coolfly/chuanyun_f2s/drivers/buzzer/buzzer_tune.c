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

#include "decode.h"
#include "player.h"
#include "song_data.h"
#include <firmament.h>

#include "buzzer_tune.h"

struct buzzer_tune_s {
    int                       index;
    const char*               name;
    const struct buzzer_song* p_song;
};

const struct buzzer_tune_s tunes_all[] = {
    {
        .index  = 0,
        .name   = "startup",
        .p_song = &song1,
    },
    {
        .index  = 1,
        .name   = "error",
        .p_song = &song2,
    },
    {
        .index  = 1,
        .name   = "sd_error",
        .p_song = &song3,
    }
};

struct player     player;
struct audio_ops  audio;
struct decode_ops decode;

uint8_t buzzer_volume = 3;

/* 解码器的读操作接口 */
int decode_read(void* song, int index, void* buffer, int size)
{
    buzzer_song_get_data(song, index, buffer);
    /* 返回歌曲进度的增量 */
    return 1;
}
/* 解码器的控制操作接口 */
int decode_control(void* song, int cmd, void* arg)
{
    if (cmd == DECODE_OPS_CMD_GET_NAME)
        buzzer_song_get_name(song, arg);
    else if (cmd == DECODE_OPS_CMD_GET_LEN)
        *(uint16_t*)arg = buzzer_song_get_len(song);

    return 0;
}
int audio_init(void)
{
    buzzer_init();
    return 0;
}
int audio_open(void)
{
    buzzer_on();
    return 0;
}
int audio_close(void)
{
    buzzer_off();
    return 0;
}
int audio_control(int cmd, void* arg)
{
    if (cmd == AUDIO_OPS_CMD_SET_VOL)
        buzzer_volume = *(uint8_t*)arg;

    return buzzer_volume;
}
int audio_write(void* buffer, int size)
{
    struct buzzer_song_data* data = buffer;
    // buzzer_on();
    // buzzer_set(data->freq, buzzer_volume);
    buzzer_start_note(data->freq);
    rt_thread_mdelay(data->sound_len);
    buzzer_off();
    rt_thread_mdelay(data->nosound_len);

    return size;
}

int player_init(void)
{
    decode.init    = buzzer_song_decode_init;
    decode.control = decode_control;
    decode.read    = decode_read;

    audio.init    = audio_init;
    audio.open    = audio_open;
    audio.close   = audio_close;
    audio.control = audio_control;
    audio.write   = audio_write;

    player.decode = &decode;
    player.audio  = &audio;

    // player_add_song(&player, (void *)&song_startup);
    // player_add_song(&player, (void *)&song_error);
    // player_start(&player);

    // player_control(&player, PLAYER_CMD_PLAY, RT_NULL);
    // player_show(&player);

    return 0;
}

int buzzer_tune_init(void)
{
    player_init();
    return 0;
}

int buzzer_tune_play(int tune)
{

    const struct buzzer_tune_s* ptune = &tunes_all[tune];

    player_control(&player, PLAYER_CMD_STOP, RT_NULL);

    while (player.playing) {
        rt_thread_mdelay(1);
    }

    player_add_song(&player, (void*)ptune->p_song);
    // player_add_song(&player,(void *)&song3);

    player_start(&player);
    player_control(&player, PLAYER_CMD_PLAY, RT_NULL);
    return 0;
}

int buzzer_tune_add_play(int tune)
{

    const struct buzzer_tune_s* ptune = &tunes_all[tune];

    player_add_song(&player, (void*)ptune->p_song);

    player_start(&player);
    player_control(&player, PLAYER_CMD_PLAY, RT_NULL);
    return 0;
}

int cmd_test_buzzer_play(void)
{

    buzzer_tune_add_play(1);
    return 0;
}

FINSH_FUNCTION_EXPORT_ALIAS(cmd_test_buzzer_play, __cmd_test_buzzer_play, user test buzzer play command);
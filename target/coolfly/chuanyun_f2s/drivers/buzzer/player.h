/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-10-17     flybreak      the first version
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <rtthread.h>

#define PLAYER_SOUND_SIZE_DEFAULT 3 // 1-99
#define PLAYER_SONG_NUM_MAX       10
#define PLAYER_SONG_NAME_LEN_MAX  20
#define PLAYER_BUFFER_SIZE        20

enum PLAYER_STATUS {
    PLAYER_RUNNING, // 正在播放
    PLAYER_STOP     // 播放停止
};
enum PLAYER_CMD {
    PLAYER_CMD_PLAY,
    PLAYER_CMD_STOP,
    PLAYER_CMD_LAST,
    PLAYER_CMD_NEXT,
    PLAYER_CMD_SET_VOL,
    PLAYER_CMD_GET_VOL,
    PLAYER_CMD_GET_STATUS
};
enum AUDIO_OPS_CMD {
    AUDIO_OPS_CMD_SET_VOL
};
enum DECODE_OPS_CMD {
    DECODE_OPS_CMD_GET_NAME,
    DECODE_OPS_CMD_GET_LEN
};

struct audio_ops {
    int (*init)(void);
    int (*open)(void);
    int (*close)(void);
    int (*control)(int cmd, void* arg);
    int (*write)(void* buffer, int size);
};

struct decode_ops {
    int (*init)(void);
    int (*control)(void* song, int cmd, void* arg);
    int (*read)(void* song, int index, void* buffer, int size);
};

struct player {
    enum PLAYER_STATUS status;                          // 当前播放状态
    uint8_t            volume;                          // 声音大小
    uint8_t            song_current;                    // 正在播放的歌曲
    uint8_t            song_num;                        // 歌曲总数
    uint16_t           song_time_pass;                  // 已经播放的时间
    uint16_t           song_time_all;                   // 总播放时间
    void*              song_sheet[PLAYER_SONG_NUM_MAX]; // 歌曲列表

    uint8_t     playing;
    rt_sem_t    sem_play;    // 用于播放状态控制的信号量
    rt_thread_t play_thread; // 播放的线程

    struct audio_ops*  audio;
    struct decode_ops* decode;
};
typedef struct player* player_t;

int player_add_song(player_t player, void* song); // 添加歌曲到歌曲列表
int player_start(player_t player);                // 初始化
int player_control(player_t player, int cmd, void* arg);
int player_show(player_t player); // 打印歌单和当前进度

#endif

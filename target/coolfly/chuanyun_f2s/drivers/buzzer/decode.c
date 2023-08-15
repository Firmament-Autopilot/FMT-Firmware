/*

- Copyright (c) 2006-2018, RT-Thread Development Team
  *
- SPDX-License-Identifier: Apache-2.0
  *
- Change Logs:
- Date           Author       Notes
- 2018-10-17     flybreak      the first version
  */

#include "decode.h"
// 原始频率表 CDEFGAB
static const uint16_t freq_tab[12] = { 262, 277, 294, 311, 330, 349, 369, 392, 415, 440, 466, 494 };
// 1~7在频率表中的位置
static const uint8_t sign_tab[7] = { 0, 2, 4, 5, 7, 9, 11 };
// 几分音符 2^0,2^1,2^2,2^3...
static const uint8_t length_tab[7] = { 1, 2, 4, 8, 16, 32, 64 };
// 新的频率表
static rt_uint16_t freq_tab_new[12];

// signature|调号(0-11)       :  是指乐曲升多少个半音演奏;
// octachord|升降八度(-2到+2) :  < 0 降几个八度; > 0 升几个八度
static int buzzer_song_decode_new_freq(rt_uint8_t signature, rt_int8_t octachord)
{
    uint8_t i, j;

    for (i = 0; i < 12; i++) { // 根据调号及升降八度来生成新的频率表
        j = i + signature;

        if (j > 11) { // 升完之后超出本组基本音级，就跳到下一组音级
            j               = j - 12;
            freq_tab_new[i] = freq_tab[j] * 2;
        } else {
            freq_tab_new[i] = freq_tab[j];
        }

        /* 升降八度 */
        if (octachord < 0) {
            freq_tab_new[i] >>= (-octachord);
        } else if (octachord > 0) {
            freq_tab_new[i] <<= octachord; // 每升一个八度 频率就翻一倍
        }
    }

    return 0;
}

static int buzzer_song_decode(rt_uint16_t tone, rt_uint16_t length, rt_uint16_t* freq, rt_uint16_t* sound_len, rt_uint16_t* nosound_len)
{
    static const rt_uint16_t div0_len = SEMIBREVE_LEN; // 全音符的长度(ms)
    rt_uint16_t              note_len, note_sound_len, current_freq;
    rt_uint8_t               note, sharp, range, note_div, effect, dotted;

    note  = tone % 10;      // 计算出音符
    range = tone / 10 % 10; // 计算出高低音
    sharp = tone / 100;     // 计算出是否升半

    current_freq = freq_tab_new[sign_tab[note - 1] + sharp]; // 查出对应音符的频率

    if (note != 0) {
        if (range == 1)
            current_freq >>= 1; // 低音 降八度

        if (range == 3)
            current_freq <<= 1; // 高音 升八度

        *freq = current_freq;
    } else {
        *freq = 0;
    }

    note_div = length_tab[length % 10]; // 算出是几分音符

    effect = length / 10 % 10; // 算出音符类型(0普通1连音2顿音)
    dotted = length / 100;     // 算出是否附点

    note_len = div0_len / note_div; // 算出音符的时长

    if (dotted == 1)
        note_len = note_len + note_len / 2;

    if (effect != 1) {
        if (effect == 0) { // 算出普通音符的演奏长度
            note_sound_len = note_len * SOUND_SPACE;
        } else { // 算出顿音的演奏长度
            note_sound_len = note_len / 2;
        }
    } else { // 算出连音的演奏长度
        note_sound_len = note_len;
    }

    if (note == 0) {
        note_sound_len = 0;
    }

    *sound_len = note_sound_len;

    *nosound_len = note_len - note_sound_len; // 算出不发音的长度

    return 0;
}

uint16_t buzzer_song_get_len(const struct buzzer_song* song)
{
    uint16_t cnt = 0;

    /* 歌曲以0x00 0x00结尾 检测结束标志*/
    while (song->data[cnt]) {
        cnt += 2;
    }

    return cnt / 2;
}

int buzzer_song_get_name(const struct buzzer_song* song, char* name)
{
    int i = 0;

    while (song->name[i]) {
        name[i] = song->name[i];
        i++;
    }

    name[i] = '\0';
    return 0;
}

uint16_t buzzer_song_get_data(const struct buzzer_song* song, uint16_t index, struct buzzer_song_data* data)
{
    buzzer_song_decode(song->data[index * 2], song->data[index * 2 + 1], &data->freq, &data->sound_len, &data->nosound_len);
    return 2;
}

int buzzer_song_decode_init(void)
{
    buzzer_song_decode_new_freq(SOUND_SIGNATURE, SOUND_OCTACHORD);
    return 0;
}
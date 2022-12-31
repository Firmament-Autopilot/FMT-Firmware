

#include "tone_alarm.h"

// #include "FreeRTOS.h"
// #include "task.h"
// #include "cmsis_os.h"

#include "ctype.h"
#include "hal.h"
#include "hal_gpio.h"
#include "hal_pwm.h"

#include "module/workqueue/workqueue_manager.h"
#include <math.h>
#include <stdbool.h>

#define CH_PWM_BEEPER 9

static void start_note(void)
{
    HAL_PWM_Start(CH_PWM_BEEPER);
}

static void stop_note(void)
{
    HAL_PWM_Stop(CH_PWM_BEEPER);
}

#define MODE_NORMAL   1
#define MODE_LEGATO   2
#define MODE_STACCATO 3

uint8_t g_next = 0;

uint32_t g_tempo = 120;

uint32_t g_note_length = 0;
uint32_t _octave = 0;
uint32_t g_note_mode = MODE_NORMAL;
bool _repeat = false;
uint32_t g_silence;
uint32_t g_frequency;
uint32_t g_duration;

tone_alarm_t g_tone_alarm;
uint32_t tone_flag = 0;

void set_tone_flag(uint32_t tone)
{
    tone_flag = tone;
}

static const uint8_t g_note_tab[] = {
    9, 11, 0, 2, 4, 5, 7
};

/* Notes in Frequency */

// static const uint16_t g_notes_freq[84] = {
// 	0x0041, 0x0045, 0x0049, 0x004d, 0x0052, 0x0057, 0x005c,
// 	0x0061, 0x0067, 0x006e, 0x0074, 0x007b, 0x0082, 0x008a,
// 	0x0092, 0x009b, 0x00a4, 0x00ae, 0x00b8, 0x00c3, 0x00cf,
// 	0x00dc, 0x00e9, 0x00f6, 0x0105, 0x0115, 0x0125, 0x0137,
// 	0x0149, 0x015d, 0x0171, 0x0187, 0x019f, 0x01b8, 0x01d2,
// 	0x01ed, 0x020b, 0x022a, 0x024b, 0x026e, 0x0293, 0x02ba,
// 	0x02e3, 0x030f, 0x033e, 0x0370, 0x03a4, 0x03db, 0x0416,
// 	0x0454, 0x0496, 0x04dc, 0x0526, 0x0574, 0x05c7, 0x061f,
// 	0x067d, 0x06e0, 0x0748, 0x07b7, 0x082d, 0x08a9, 0x092d,
// 	0x09b9, 0x0a4d, 0x0ae9, 0x0b8f, 0x0c3f, 0x0cfa, 0x0dc0,
// 	0x0e91, 0x0f6f, 0x105a, 0x1152, 0x125a, 0x1372, 0x149a,
// 	0x15d3, 0x171f, 0x187f, 0x19f4, 0x1b80, 0x1d22, 0x1ede
// };

uint8_t next_char(void)
{
    uint8_t ret = g_tone_alarm.buff[g_next];
    return ret;
}

static uint8_t next_dots(void)
{
    uint8_t dots = 0;

    while (next_char() == '.') {
        g_next++;
        dots++;
    }

    return dots;
}

static uint8_t next_number(void)
{
    uint8_t number = 0;
    int c;

    for (;;) {
        c = next_char();

        if (!isdigit(c)) {
            return number;
        }

        g_next++;
        number = (number * 10) + (c - '0');
    }

    return number;
}

/****************************************************************************
 * Name: note_duration
 *
 * Description:
 *   This function calculates the duration in microseconds of play and
 *   silence for a note given the current tempo, length and mode and the
 *   number of dots following in the play string.
 *
 ****************************************************************************/

static uint32_t note_duration(uint32_t* silence, uint32_t note_length,
                              uint32_t dots)
{
    uint32_t whole_note_period = (60 * 1000000 * 4) / g_tempo;
    uint32_t note_period;
    uint32_t dot_extension;

    if (note_length == 0) {
        note_length = 1;
    }

    note_period = whole_note_period / note_length;

    switch (g_note_mode) {
    case MODE_NORMAL:
        *silence = note_period / 8;
        break;

    case MODE_STACCATO:
        *silence = note_period / 4;
        break;

    case MODE_LEGATO:
        *silence = 0;
        break;

    default:
        //DLOG_Critical("Mode undefined!\n");
        break;
    }

    note_period -= *silence;
    dot_extension = note_period / 2;

    while (dots--) {
        note_period += dot_extension;
        dot_extension /= 2;
    }

    return note_period;
}

/****************************************************************************
 * Name: rest_duration
 *
 * Description:
 *   This function calculates the duration in microseconds of a rest
 *   corresponding to a given note length.
 *
 ****************************************************************************/

static uint32_t rest_duration(uint32_t rest_length, uint32_t dots)
{
    uint32_t whole_note_period = (60 * 1000000 * 4) / g_tempo;
    uint32_t rest_period;
    uint32_t dot_extension;

    if (rest_length == 0) {
        rest_length = 1;
    }

    rest_period = whole_note_period / rest_length;

    dot_extension = rest_period / 2;

    while (dots--) {
        rest_period += dot_extension;
        dot_extension /= 2;
    }

    return rest_period;
}

uint32_t note_to_frequency(unsigned note)
{
    // Compute the frequency (Hz).
    return (unsigned)(880.0f * powf(2.0f, ((int)note - 46) / 12.0f));
}

bool check_flag_and_load_tone_buff(void)
{
    if (tone_flag == 0) {
        return false;
    }

    memset(&g_tone_alarm, 0, sizeof(g_tone_alarm));

    switch (tone_flag) {
    case TONE_STARTUP:
        memcpy(g_tone_alarm.buff, &STARTUP, sizeof(STARTUP));
        break;
    case TONE_ERROR_TUNE:
        memcpy(g_tone_alarm.buff, &ERROR_TUNE, sizeof(ERROR_TUNE));
        break;
    case TONE_NOTIFY_POSITIVE:
        memcpy(g_tone_alarm.buff, &NOTIFY_POSITIVE, sizeof(NOTIFY_POSITIVE));
        break;
    case TONE_NOTIFY_NEUTRAL:
        memcpy(g_tone_alarm.buff, &NOTIFY_NEUTRAL, sizeof(NOTIFY_NEUTRAL));
        break;
    case TONE_NOTIFY_NEGATIVE:
        memcpy(g_tone_alarm.buff, &NOTIFY_NEGATIVE, sizeof(NOTIFY_NEGATIVE));
        break;
    case TONE_ARMING_WARNING:
        memcpy(g_tone_alarm.buff, &ARMING_WARNING, sizeof(ARMING_WARNING));
        break;
    case TONE_BATTERY_WARNING_SLOW:
        memcpy(g_tone_alarm.buff, &BATTERY_WARNING_SLOW, sizeof(BATTERY_WARNING_SLOW));
        break;
    case TONE_BATTERY_WARNING_FAST:
        memcpy(g_tone_alarm.buff, &BATTERY_WARNING_FAST, sizeof(BATTERY_WARNING_FAST));
        break;
    case TONE_GPS_WARNING:
        memcpy(g_tone_alarm.buff, &GPS_WARNING, sizeof(GPS_WARNING));
        break;
    case TONE_ARMING_FAILURE:
        memcpy(g_tone_alarm.buff, &ARMING_FAILURE, sizeof(ARMING_FAILURE));
        break;
    case TONE_PARACHUTE_RELEASE:
        memcpy(g_tone_alarm.buff, &PARACHUTE_RELEASE, sizeof(PARACHUTE_RELEASE));
        break;
    case TONE_SINGLE_BEEP:
        memcpy(g_tone_alarm.buff, &SINGLE_BEEP, sizeof(SINGLE_BEEP));
        break;
    case TONE_HOME_SET:
        memcpy(g_tone_alarm.buff, &HOME_SET, sizeof(HOME_SET));
        break;
    case TONE_SD_INIT:
        memcpy(g_tone_alarm.buff, &SD_INIT, sizeof(SD_INIT));
        break;
    case TONE_SD_ERROR:
        memcpy(g_tone_alarm.buff, &SD_ERROR, sizeof(SD_ERROR));
        break;
    case TONE_PROG_PX4IO:
        memcpy(g_tone_alarm.buff, &PROG_PX4IO, sizeof(PROG_PX4IO));
        break;
    case TONE_PROG_PX4IO_OK:
        memcpy(g_tone_alarm.buff, &PROG_PX4IO_OK, sizeof(PROG_PX4IO_OK));
        break;
    case TONE_PROG_PX4IO_ERR:
        memcpy(g_tone_alarm.buff, &PROG_PX4IO_ERR, sizeof(PROG_PX4IO_ERR));
        break;
    case TONE_SINGLE_BEEP2:
        memcpy(g_tone_alarm.buff, &SINGLE_BEEP2, sizeof(SINGLE_BEEP2));
        break;
    case TONE_SINGLE_BEEP3:
        memcpy(g_tone_alarm.buff, &SINGLE_BEEP3, sizeof(SINGLE_BEEP3));
        break;

    default:
        break;
    }

    return true;
}

static void run_alarm_item(void* parameter)
{

    static uint32_t note;
    static uint32_t note_length;
    static int c;

    if (check_flag_and_load_tone_buff()) {

        g_next = 0;

        do {
            c = next_char();

            ////DLOG_Info("c = %c -- %d", c, c);

            if (c == '\0') {

                break;
            }

            c = (c == 'a') ? 'A' : c;
            c = (c == 'b') ? 'B' : c;
            c = (c == 'c') ? 'C' : c;
            c = (c == 'd') ? 'D' : c;
            c = (c == 'e') ? 'E' : c;
            c = (c == 'f') ? 'F' : c;
            c = (c == 'g') ? 'G' : c;

            g_next++;

            switch (c) {
            case 'L': // select note length
                g_note_length = next_number();

                ////DLOG_Info("set L = %d", g_note_length);

                if (g_note_length < 1) {
                    //DLOG_Critical("TONE_ERROR1");
                    c = '\0'; //  离开循环
                }

                break;

            case 'O': // select octave
                _octave = next_number();

                //DLOG_Info("_octave = %d", _octave);

                if (_octave > 6) {
                    _octave = 6;
                }

                break;

            case '<': // decrease octave
                if (_octave > 0) {
                    _octave--;
                }

                break;

            case '>': // increase octave
                if (_octave < 6) {
                    _octave++;
                }

                break;

            case 'M': // select inter-note gap
                c = next_char();

                if (c == 0) {
                    //DLOG_Critical("TONE_ERROR2");
                }

                //DLOG_Info("set M");

                g_next++;

                switch (c) {
                case 'N':
                    g_note_mode = MODE_NORMAL;
                    break;

                case 'L':
                    g_note_mode = MODE_LEGATO;
                    break;

                case 'S':
                    g_note_mode = MODE_STACCATO;
                    break;

                case 'F':
                    _repeat = false;
                    //DLOG_Info("set M-F");
                    break;

                case 'B':
                    _repeat = true;
                    break;

                default:
                    //DLOG_Critical("TONE_ERROR3");
                    c = '\0'; //  离开循环
                }

                break;

            case 'P': { // pause for a note length
                // stop_note();

                uint32_t t = rest_duration(next_number(), next_dots());

                sys_msleep(t / 10000);

                stop_note();

                break;
            }

            case 'T': { // change tempo
                unsigned nt = next_number();

                ////DLOG_Info("set T = %D", nt);

                if ((nt >= 32) && (nt <= 255)) {
                    g_tempo = nt;

                } else {
                    //DLOG_Critical("TONE_ERROR4");
                    c = '\0'; //  离开循环
                }

                break;
            }

            case 'N': // play an arbitrary note
                note = next_number();

                if (note > 84) {
                    //DLOG_Critical("TONE_ERROR5");
                    c = '\0'; //  离开循环
                }

                if (note == 0) {
                    uint64_t t = rest_duration(g_note_length, next_dots());
                    sys_msleep(t / 1000);
                    break;
                }

                break;

            case 'A': // play a note in the current octave
            case 'B': // play a note in the current octave
            case 'C': // play a note in the current octave
            case 'D': // play a note in the current octave
            case 'E': // play a note in the current octave
            case 'F': // play a note in the current octave
            case 'G': // play a note in the current octave
                note = g_note_tab[c - 'A'] + (_octave * 12) + 1;
                c = next_char();

                switch (c) {
                case '#': // up a semitone
                case '+':
                    if (note < 84) {
                        note++;
                    }

                    g_next++;
                    break;

                case '-': // down a semitone
                    if (note > 1) {
                        note--;
                    }

                    g_next++;
                    break;

                default:
                    // 0 / no next char here is OK
                    break;
                }

                // shorthand length notation
                note_length = next_number();

                if (note_length == 0) {
                    note_length = g_note_length;
                }

                // Compute the duration of the note and the following silence (if any).
                note_length = note_duration(&g_silence, note_length, next_dots());

                // Compute the note frequency.
                g_frequency = note_to_frequency(note);
                HAL_PWM_DynamicModifyPwmDutyCycleByIntr(CH_PWM_BEEPER, 1000000 / (2 * g_frequency), 1000000 / (2 * g_frequency));
                ////DLOG_Info("note_length = %d", note_length);
                ////DLOG_Info("g_frequency = %d", g_frequency);
                start_note();
                sys_msleep(note_length / 1000);
                stop_note();
                break;

            case 32:

                break;

            default:
                //DLOG_Critical("TONE_ERROR6");
                c = '\0'; //  离开循环
            }

        } while (c != '\0');

        set_tone_flag(0);
    }
}

static struct WorkItem tone_alarm_item = {
    .name = "tone_alarm",
    .period = 10,
    .schedule_time = 0,
    .run = run_alarm_item
};

fmt_err_t tone_alarm_init(void)
{

    HAL_PWM_RegisterPwmWithIntr(CH_PWM_BEEPER, 1000, 1000);

    tone_alarm_t alarm;
    memset(&alarm, 0, sizeof(alarm));
    set_tone_flag(TONE_STARTUP);
    WorkQueue_t hp_wq = workqueue_find("wq:hp_work");
    RT_ASSERT(hp_wq != NULL);

    FMT_CHECK(workqueue_schedule_work(hp_wq, &tone_alarm_item));
    return FMT_EOK;
}
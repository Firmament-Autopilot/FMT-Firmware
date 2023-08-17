#ifndef _TONE_ALARM_H
#define _TONE_ALARM_H

#include <stdint.h>
#include <string.h>

typedef struct {
    uint64_t timestamp;
    char     buff[128];
} tone_alarm_t;

// //           ordinal name                  tune                                        interruptable*     hint
// //  * Repeated tunes should always be defined as interruptable, if not an explict 'tone_control stop' is needed
// PX4_DEFINE_TUNE(0,  CUSTOM,                "",                                              true  /*  empty to align with the index */)
// PX4_DEFINE_TUNE(1,  ,               "MFT240L8 O4aO5dc O4aO5dc O4aO5dc L16dcdcdcdc",  true  /*  startup tune */)
// PX4_DEFINE_TUNE(2,  ERROR_TUNE,            "MBT200a8a8a8PaaaP",                             true  /*  ERROR tone */)
// PX4_DEFINE_TUNE(3,  NOTIFY_POSITIVE,       "MFT200e8a8a",                                   true  /*  Notify Positive tone */)
// PX4_DEFINE_TUNE(4,  NOTIFY_NEUTRAL,        "MFT200e8e",                                     true  /*  Notify Neutral tone */)
// PX4_DEFINE_TUNE(5,  NOTIFY_NEGATIVE,       "MFT200e8c8e8c8e8c8",                            true  /*  Notify Negative tone */)
// PX4_DEFINE_TUNE(6,  ARMING_WARNING,        "MNT75L1O2G",                                    false /*  arming warning */)
// PX4_DEFINE_TUNE(7,  BATTERY_WARNING_SLOW,  "MBNT100a8",                                     true  /*  battery warning slow */)
// PX4_DEFINE_TUNE(8,  BATTERY_WARNING_FAST,  "MBNT255a8a8a8a8a8a8a8a8a8a8a8a8a8a8a8a8",       true  /*  battery warning fast */)
// PX4_DEFINE_TUNE(9,  GPS_WARNING,           "MFT255L4AAAL1F#",                               false /*  gps warning slow */)
// PX4_DEFINE_TUNE(10, ARMING_FAILURE,        "MFT255L4<<<BAP",                                false /*  arming failure tune */)
// PX4_DEFINE_TUNE(11, PARACHUTE_RELEASE,     "MFT255L16agagagag",                             false /*  parachute release */)
// PX4_DEFINE_TUNE(12, SINGLE_BEEP,           "MFT100a8",                                      false /*  single beep */)
// PX4_DEFINE_TUNE(13, HOME_SET,              "MFT100L4>G#6A#6B#4",                            false /*  home set tune */)
// PX4_DEFINE_TUNE(14, SD_INIT,               "MFAGPAG",                                       false /*  Make FS */)
// PX4_DEFINE_TUNE(15, SD_ERROR,              "MNBG",                                          false /*  format failed */)
// PX4_DEFINE_TUNE(16, PROG_PX4IO,            "MLL32CP8MB",                                    false /*  Program PX4IO */)
// PX4_DEFINE_TUNE(17, PROG_PX4IO_OK,         "MLL8CDE",                                       false /*  Program PX4IO success */)
// PX4_DEFINE_TUNE(18, PROG_PX4IO_ERR,        "ML<<CP4CP4CP4CP4CP4",                           true  /*  Program PX4IO fail */)

#define STARTUP                   "MFT240L8 O4aO5dc O4aO5dc O4aO5dc L16dcdcdcdc"
#define ERROR_TUNE                "MBT200a8a8a8PaaaP"
#define NOTIFY_POSITIVE           "MFT200e8a8a"
#define NOTIFY_NEUTRAL            "MFT200e8e"
#define NOTIFY_NEGATIVE           "MFT200e8c8e8c8e8c8"
#define ARMING_WARNING            "MNT75L1O2G"
#define BATTERY_WARNING_SLOW      "MBNT100a8"
#define BATTERY_WARNING_FAST      "MBNT255a8a8a8a8a8a8a8a8a8a8a8a8a8a8a8a8"
#define GPS_WARNING               "MFT255L4AAAL1F#"
#define ARMING_FAILURE            "MFT255L4<<<BAP"
#define PARACHUTE_RELEASE         "MFT255L16agagagag"
#define SINGLE_BEEP               "MFT100a8"
#define HOME_SET                  "MFT100L4>G#6A#6B#4"
#define SD_INIT                   "MFAGPAG"
#define SD_ERROR                  "MNBG"
#define PROG_PX4IO                "MLL32CP8MB"
#define PROG_PX4IO_OK             "MLL8CDE"
#define PROG_PX4IO_ERR            "ML<<CP4CP4CP4CP4CP4"
#define SINGLE_BEEP2              "MFT100a8g"
#define SINGLE_BEEP3              "MFT100a8gf"

#define TONE_STARTUP              1
#define TONE_ERROR_TUNE           2
#define TONE_NOTIFY_POSITIVE      3
#define TONE_NOTIFY_NEUTRAL       4
#define TONE_NOTIFY_NEGATIVE      5
#define TONE_ARMING_WARNING       6
#define TONE_BATTERY_WARNING_SLOW 7
#define TONE_BATTERY_WARNING_FAST 8
#define TONE_GPS_WARNING          9
#define TONE_ARMING_FAILURE       10
#define TONE_PARACHUTE_RELEASE    11
#define TONE_SINGLE_BEEP          12
#define TONE_HOME_SET             13
#define TONE_SD_INIT              14
#define TONE_SD_ERROR             15
#define TONE_PROG_PX4IO           16
#define TONE_PROG_PX4IO_OK        17
#define TONE_PROG_PX4IO_ERR       18
#define TONE_SINGLE_BEEP2         19
#define TONE_SINGLE_BEEP3         20
#define TONE_SONG_NUM_MAX         (TONE_SINGLE_BEEP3 + 1)

int  tone_alarm_init(const char* dev_name);
void tone_alarm_write(uint32_t tone);

#endif
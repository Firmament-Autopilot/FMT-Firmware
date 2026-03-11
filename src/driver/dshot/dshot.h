#ifndef DSHOT_H__
#define DSHOT_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DSHOT_MIN_THROTTLE         48
#define DSHOT_MAX_THROTTLE         2047
#define DSHOT_RANGE                (DSHOT_MAX_THROTTLE - DSHOT_MIN_THROTTLE)

/* DShot commands, valid in range 0..47. */
#define DSHOT_CMD_MOTOR_STOP       0
#define DSHOT_CMD_BEEP1            1
#define DSHOT_CMD_BEEP2            2
#define DSHOT_CMD_BEEP3            3
#define DSHOT_CMD_BEEP4            4
#define DSHOT_CMD_BEEP5            5
#define DSHOT_CMD_ESC_INFO         6
#define DSHOT_CMD_SPIN_DIRECTION_1 7
#define DSHOT_CMD_SPIN_DIRECTION_2 8
#define DSHOT_CMD_3D_MODE_OFF      9
#define DSHOT_CMD_3D_MODE_ON       10
#define DSHOT_CMD_SETTINGS_REQUEST 11
#define DSHOT_CMD_SAVE_SETTINGS    12

#define DSHOT_CMD_MAX              47

uint16_t dshot_pack_frame(uint16_t value, bool telemetry);

uint16_t dshot_throttle_to_value(float norm_throttle);

#ifdef __cplusplus
}
#endif

#endif /* DSHOT_H__ */
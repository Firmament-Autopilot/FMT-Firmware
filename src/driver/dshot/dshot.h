/**
 * @file dshot.h
 * @brief DShot protocol definitions and utility functions
 * @author Chenliang Pan
 */

#ifndef DSHOT_H__
#define DSHOT_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DSHOT_MIN_THROTTLE         48
#define DSHOT_MAX_THROTTLE         2047
#define DSHOT_RANGE                (DSHOT_MAX_THROTTLE - DSHOT_MIN_THROTTLE)

/* Common DShot Commands */
#define DSHOT_CMD_MOTOR_STOP       0
#define DSHOT_CMD_BEACON1          1
#define DSHOT_CMD_BEACON2          2
#define DSHOT_CMD_BEACON3          3
#define DSHOT_CMD_BEACON4          4
#define DSHOT_CMD_BEACON5          5
#define DSHOT_CMD_ESC_INFO         6 // V2 includes Firmware
#define DSHOT_CMD_SPIN_DIRECTION_1 7
#define DSHOT_CMD_SPIN_DIRECTION_2 8
#define DSHOT_CMD_3D_MODE_OFF      9
#define DSHOT_CMD_3D_MODE_ON       10
#define DSHOT_CMD_SETTINGS_REQUEST 11
#define DSHOT_CMD_SAVE_SETTINGS    12

/* Pack an 11-bit value + telemetry flag into a 16-bit DShot frame (CRC appended). */
uint16_t dshot_pack_frame(uint16_t value, bool telemetry);

/* Map normalized throttle [0.0, 1.0] to DShot throttle range [48, 2047]. */
uint16_t dshot_throttle_to_value(float norm_throttle);

#ifdef __cplusplus
}
#endif

#endif /* DSHOT_H__ */
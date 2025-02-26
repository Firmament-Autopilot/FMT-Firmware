#ifndef NLINK_LINKTRACK_TAGFRAME0_H
#define NLINK_LINKTRACK_TAGFRAME0_H
#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  float pos_3d[3];
  float eop_3d[3];
  float vel_3d[3];
  float dis_arr[8];
  float imu_gyro_3d[3];
  float imu_acc_3d[3];
  float angle_3d[3];
  float quaternion[4];
  uint32_t local_time;
  uint32_t system_time;
  float voltage;
} nlt_tagframe0_result_t;

typedef struct {
  const size_t fixed_part_size;
  const uint8_t frame_header;
  const uint8_t function_mark;
  nlt_tagframe0_result_t result;

  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);
} nlt_tagframe0_t;

extern nlt_tagframe0_t g_nlt_tagframe0;

#ifdef __cplusplus
}
#endif
#endif // NLINK_LINKTRACK_TAGFRAME0_H

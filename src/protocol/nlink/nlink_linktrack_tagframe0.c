#include "nlink_linktrack_tagframe0.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t header[2];
  uint8_t id;
  uint8_t role;
  nint24_t pos_3d[3];
  nint24_t vel_3d[3];
  nint24_t dis_arr[8];
  float imu_gyro_3d[3];
  float imu_acc_3d[3];
  uint8_t reserved1[12];
  int16_t angle_3d[3];
  float quaternion[4];
  uint8_t reserved2[4];
  uint32_t local_time;
  uint32_t system_time;
  uint8_t reserved3[1];
  uint8_t eop_3d[3];
  uint16_t voltage;
  uint8_t reserved4[5];
  uint8_t check_sum;
} nlt_tagframe0_raw_t;
#pragma pack()

static nlt_tagframe0_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nlt_tagframe0.fixed_part_size ||
      data[0] != g_nlt_tagframe0.frame_header ||
      data[1] != g_nlt_tagframe0.function_mark)
    return 0;
  if (!NLINK_VerifyCheckSum(data, g_nlt_tagframe0.fixed_part_size))
    return 0;

  memcpy(&g_frame, data, g_nlt_tagframe0.fixed_part_size);
  g_nlt_tagframe0.result.role = g_frame.role;
  g_nlt_tagframe0.result.id = g_frame.id;
  g_nlt_tagframe0.result.local_time = g_frame.local_time;
  g_nlt_tagframe0.result.system_time = g_frame.system_time;
  g_nlt_tagframe0.result.voltage = g_frame.voltage / MULTIPLY_VOLTAGE;

  NLINK_TRANSFORM_ARRAY_INT24(g_nlt_tagframe0.result.pos_3d, g_frame.pos_3d,
                              MULTIPLY_POS)
  NLINK_TRANSFORM_ARRAY_INT24(g_nlt_tagframe0.result.vel_3d, g_frame.vel_3d,
                              MULTIPLY_VEL)
  NLINK_TRANSFORM_ARRAY_INT24(g_nlt_tagframe0.result.dis_arr, g_frame.dis_arr,
                              MULTIPLY_DIS)
  NLINK_TRANSFORM_ARRAY(g_nlt_tagframe0.result.imu_gyro_3d, g_frame.imu_gyro_3d,
                        1)
  NLINK_TRANSFORM_ARRAY(g_nlt_tagframe0.result.imu_acc_3d, g_frame.imu_acc_3d,
                        1)
  NLINK_TRANSFORM_ARRAY(g_nlt_tagframe0.result.quaternion, g_frame.quaternion,
                        1)
  NLINK_TRANSFORM_ARRAY(g_nlt_tagframe0.result.angle_3d, g_frame.angle_3d,
                        MULTIPLY_ANGLE)
  NLINK_TRANSFORM_ARRAY(g_nlt_tagframe0.result.eop_3d, g_frame.eop_3d,
                        MULTIPLY_EOP)

  return 1;
}

nlt_tagframe0_t g_nlt_tagframe0 = {.fixed_part_size = 128,
                                   .frame_header = 0x55,
                                   .function_mark = 0x01,
                                   .UnpackData = UnpackData};

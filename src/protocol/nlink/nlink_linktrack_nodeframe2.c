#include "nlink_linktrack_nodeframe2.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t role;
  uint8_t id;
  nint24_t dis;
  uint8_t fp_rssi;
  uint8_t rx_rssi;
  uint32_t system_time;
  uint8_t reserved[2];
} nlt_nodeframe2_node_raw_t;

typedef struct {
  uint8_t header[2];
  uint16_t frame_length;
  uint8_t role;
  uint8_t id;
  uint32_t system_time;
  uint8_t eop_3d[3];
  nint24_t pos_3d[3];
  nint24_t vel_3d[3];
  uint8_t reserved1[9];
  float imu_gyro_3d[3];
  float imu_acc_3d[3];
  uint8_t reserved2[12];
  int16_t angle_3d[3];
  float quaternion[4];
  uint8_t reserved3[4];
  uint32_t local_time;
  uint8_t reserved4[10];
  uint16_t voltage;
  uint8_t valid_node_count;
  // nodes...
  // uint8_t checkSum;
} nlt_nodeframe2_raw_t;
#pragma pack()

static nlt_nodeframe2_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nlt_nodeframe2.fixed_part_size ||
      data[0] != g_nlt_nodeframe2.frame_header ||
      data[1] != g_nlt_nodeframe2.function_mark)
    return 0;
  size_t frame_length = NLINK_PROTOCOL_LENGTH(data);
  if (data_length < frame_length)
    return 0;
  if (!NLINK_VerifyCheckSum(data, frame_length))
    return 0;

  static uint8_t initNeeded = 1;
  if (initNeeded) {
    memset(g_nlt_nodeframe2.result.nodes, 0,
           sizeof(g_nlt_nodeframe2.result.nodes));
    initNeeded = 0;
  }

  memcpy(&g_frame, data, g_nlt_nodeframe2.fixed_part_size);
  g_nlt_nodeframe2.result.role = g_frame.role;
  g_nlt_nodeframe2.result.id = g_frame.id;
  g_nlt_nodeframe2.result.local_time = g_frame.local_time;
  g_nlt_nodeframe2.result.system_time = g_frame.system_time;
  g_nlt_nodeframe2.result.voltage = g_frame.voltage / MULTIPLY_VOLTAGE;
  NLINK_TRANSFORM_ARRAY_INT24(g_nlt_nodeframe2.result.pos_3d, g_frame.pos_3d,
                              MULTIPLY_POS)
  NLINK_TRANSFORM_ARRAY_INT24(g_nlt_nodeframe2.result.vel_3d, g_frame.vel_3d,
                              MULTIPLY_VEL)
  NLINK_TRANSFORM_ARRAY(g_nlt_nodeframe2.result.imu_gyro_3d,
                        g_frame.imu_gyro_3d, 1)
  NLINK_TRANSFORM_ARRAY(g_nlt_nodeframe2.result.imu_acc_3d, g_frame.imu_acc_3d,
                        1)
  NLINK_TRANSFORM_ARRAY(g_nlt_nodeframe2.result.quaternion, g_frame.quaternion,
                        1)
  NLINK_TRANSFORM_ARRAY(g_nlt_nodeframe2.result.angle_3d, g_frame.angle_3d,
                        MULTIPLY_ANGLE)
  NLINK_TRANSFORM_ARRAY(g_nlt_nodeframe2.result.eop_3d, g_frame.eop_3d,
                        MULTIPLY_EOP)

  g_nlt_nodeframe2.result.valid_node_count = g_frame.valid_node_count;
  nlt_nodeframe2_node_raw_t rawNode;
  for (size_t i = 0; i < g_frame.valid_node_count; ++i) {
    TRY_MALLOC_NEW_NODE(g_nlt_nodeframe2.result.nodes[i], nlt_nodeframe2_node_t)

    memcpy(&rawNode,
           data + g_nlt_nodeframe2.fixed_part_size +
               i * sizeof(nlt_nodeframe2_node_raw_t),
           sizeof(nlt_nodeframe2_node_raw_t));

    nlt_nodeframe2_node_t *node = g_nlt_nodeframe2.result.nodes[i];
    node->role = rawNode.role;
    node->id = rawNode.id;
    node->dis = NLINK_ParseInt24(rawNode.dis) / MULTIPLY_DIS;
    node->fp_rssi = rawNode.fp_rssi / MULTIPLY_RSSI;
    node->rx_rssi = rawNode.rx_rssi / MULTIPLY_RSSI;
  }
  return 1;
}

nlt_nodeframe2_t g_nlt_nodeframe2 = {.fixed_part_size = 119,
                                     .frame_header = 0x55,
                                     .function_mark = 0x04,
                                     .UnpackData = UnpackData};

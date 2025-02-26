#include "nlink_iot_frame0.h"
#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint32_t uid;
  nint24_t dis;
  int16_t aoa_angle_horizontal;
  int16_t aoa_angle_vertical;
  uint8_t fp_rssi;
  uint8_t rx_rssi;
  struct {
    uint8_t user_data_len : 4;
  };
  uint8_t user_data[16];
} iot_frame0_raw_node_t;

typedef struct {
  uint8_t frame_header;
  uint8_t function_mark;
  uint16_t frame_length;
  uint32_t uid;
  uint32_t system_time;
  struct {
    uint8_t io0 : 1;
    uint8_t io1 : 1;
    uint8_t io2 : 1;
    uint8_t io3 : 1;
    uint8_t io4 : 1;
    uint8_t io5 : 1;
    uint8_t io6 : 1;
    uint8_t io7 : 1;
  } io_status;
  uint8_t node_count;
  // nodes
  // sum check
} iot_frame0_raw_head_t;
#pragma pack()

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  const iot_frame0_raw_head_t *raw_head = (const iot_frame0_raw_head_t *)data;
  if (raw_head->frame_header != g_iot_frame0.frame_header ||
      raw_head->function_mark != g_iot_frame0.function_mark ||
      data_length < g_iot_frame0.fixed_part_size) {
    return 0;
  }

  size_t frame_length = NLINK_PROTOCOL_LENGTH(data);
  if (data_length < frame_length)
    return 0;
  if (!NLINK_VerifyCheckSum(data, frame_length))
    return 0;

  g_iot_frame0.uid = raw_head->uid;
  g_iot_frame0.system_time = raw_head->system_time;
  *(uint8_t *)&(g_iot_frame0.io_status) = *(uint8_t *)&(raw_head->io_status);

  uint8_t node_count = raw_head->node_count;
  if (node_count > IOT_FRAME0_NODE_COUNT_MAX) {
    node_count = IOT_FRAME0_NODE_COUNT_MAX;
  }
  g_iot_frame0.node_count = node_count;

  for (int i = 0, addr = sizeof(*raw_head); i < node_count; ++i) {
    const iot_frame0_raw_node_t *raw_node =
        (const iot_frame0_raw_node_t *)(data + addr);
    addr += sizeof(*raw_node) - sizeof(raw_node->user_data) +
            raw_node->user_data_len;
    iot_frame0_node_t *node = &g_iot_frame0.nodes[i];
    node->uid = raw_node->uid;
    node->dis = NLINK_ParseInt24(raw_node->dis) / 1000.0f;
    node->aoa_angle_horizontal = raw_node->aoa_angle_horizontal / 100.0f;
    node->aoa_angle_vertical = raw_node->aoa_angle_vertical / 100.0f;
    node->fp_rssi = raw_node->fp_rssi / -2.0f;
    node->rx_rssi = raw_node->rx_rssi / -2.0f;
    node->user_data_len = raw_node->user_data_len;
    memcpy(node->user_data, raw_node->user_data, raw_node->user_data_len);
  }
  return 1;
}

iot_frame0_t g_iot_frame0 = {.fixed_part_size = 14,
                             .frame_header = 0x6a,
                             .function_mark = 0x00,
                             .UnpackData = UnpackData};

#include "nlink_linktrack_nodeframe5.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t role;
  id_t id;
  nint24_t dis;
  uint8_t fp_rssi;
  uint8_t rx_rssi;
} nlt_nodeframe5_node_raw_t;

typedef struct {
  uint8_t header[2];
  uint16_t frame_length;
  uint8_t role;
  id_t id;
  uint32_t local_time;
  uint32_t system_time;
  uint8_t reserved0[4];
  uint16_t voltage;
  uint8_t valid_node_count;
  // nodes...
  // uint8_t checkSum;
} nlt_nodeframe5_raw_t;
#pragma pack()

static nlt_nodeframe5_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nlt_nodeframe5.fixed_part_size ||
      data[0] != g_nlt_nodeframe5.frame_header ||
      data[1] != g_nlt_nodeframe5.function_mark)
    return 0;
  size_t frame_length = NLINK_PROTOCOL_LENGTH(data);
  if (data_length < frame_length)
    return 0;
  if (!NLINK_VerifyCheckSum(data, frame_length))
    return 0;

  static uint8_t init_needed = 1;
  if (init_needed) {
    memset(g_nlt_nodeframe5.result.nodes, 0,
           sizeof(g_nlt_nodeframe5.result.nodes));
    init_needed = 0;
  }

  memcpy(&g_frame, data, g_nlt_nodeframe5.fixed_part_size);
  g_nlt_nodeframe5.result.role = g_frame.role;
  g_nlt_nodeframe5.result.id = g_frame.id;
  g_nlt_nodeframe5.result.local_time = g_frame.local_time;
  g_nlt_nodeframe5.result.system_time = g_frame.system_time;
  g_nlt_nodeframe5.result.voltage = g_frame.voltage / MULTIPLY_VOLTAGE;

  g_nlt_nodeframe5.result.valid_node_count = g_frame.valid_node_count;
  nlt_nodeframe5_node_raw_t raw_node;
  for (size_t i = 0; i < g_frame.valid_node_count; ++i) {
    TRY_MALLOC_NEW_NODE(g_nlt_nodeframe5.result.nodes[i], nlt_nodeframe5_node_t)

    memcpy(&raw_node,
           data + g_nlt_nodeframe5.fixed_part_size +
               i * sizeof(nlt_nodeframe5_node_raw_t),
           sizeof(nlt_nodeframe5_node_raw_t));

    nlt_nodeframe5_node_t *node = g_nlt_nodeframe5.result.nodes[i];
    node->role = raw_node.role;
    node->id = raw_node.id;
    node->dis = NLINK_ParseInt24(raw_node.dis) / MULTIPLY_DIS;
    node->fp_rssi = raw_node.fp_rssi / MULTIPLY_RSSI;
    node->rx_rssi = raw_node.rx_rssi / MULTIPLY_RSSI;
  }
  return 1;
}

nlt_nodeframe5_t g_nlt_nodeframe5 = {.fixed_part_size = 24,
                                     .frame_header = 0x55,
                                     .function_mark = 0x08,
                                     .UnpackData = UnpackData};

#include "nlink_linktrack_nodeframe1.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t role;
  uint8_t id;
  nint24_t pos_3d[3];
  uint8_t reserved[9];
} nlt_nodeframe1_node_raw_t;

typedef struct {
  uint8_t header[2];
  uint16_t frame_length;
  uint8_t role;
  uint8_t id;
  uint32_t system_time;
  uint32_t local_time;
  uint8_t reserved0[10];
  uint16_t voltage;

  uint8_t valid_node_count;
  // nodes...
  // uint8_t checkSum;
} nlt_nodeframe1_raw_t;
#pragma pack()

static nlt_nodeframe1_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nlt_nodeframe1.fixed_part_size ||
      data[0] != g_nlt_nodeframe1.frame_header ||
      data[1] != g_nlt_nodeframe1.function_mark)
    return 0;
  size_t frame_length = NLINK_PROTOCOL_LENGTH(data);
  if (data_length < frame_length)
    return 0;
  if (!NLINK_VerifyCheckSum(data, frame_length))
    return 0;

  static uint8_t init_needed = 1;
  if (init_needed) {
    memset(g_nlt_nodeframe1.result.nodes, 0,
           sizeof(g_nlt_nodeframe1.result.nodes));
    init_needed = 0;
  }

  memcpy(&g_frame, data, g_nlt_nodeframe1.fixed_part_size);

  g_nlt_nodeframe1.result.id = g_frame.id;
  g_nlt_nodeframe1.result.local_time = g_frame.local_time;
  g_nlt_nodeframe1.result.system_time = g_frame.system_time;
  g_nlt_nodeframe1.result.voltage = g_frame.voltage / MULTIPLY_VOLTAGE;

  g_nlt_nodeframe1.result.valid_node_count = g_frame.valid_node_count;
  nlt_nodeframe1_node_raw_t raw_node;
  for (size_t i = 0; i < g_frame.valid_node_count; ++i) {
    TRY_MALLOC_NEW_NODE(g_nlt_nodeframe1.result.nodes[i], nlt_nodeframe1_node_t)

    memcpy(&raw_node,
           data + g_nlt_nodeframe1.fixed_part_size +
               i * sizeof(nlt_nodeframe1_node_raw_t),
           sizeof(nlt_nodeframe1_node_raw_t));

    nlt_nodeframe1_node_t *node = g_nlt_nodeframe1.result.nodes[i];
    node->role = raw_node.role;
    node->id = raw_node.id;
    NLINK_TRANSFORM_ARRAY_INT24(node->pos_3d, raw_node.pos_3d, MULTIPLY_POS)
  }
  return 1;
}

nlt_nodeframe1_t g_nlt_nodeframe1 = {.fixed_part_size = 27,
                                     .frame_header = 0x55,
                                     .function_mark = 0x03,
                                     .UnpackData = UnpackData};

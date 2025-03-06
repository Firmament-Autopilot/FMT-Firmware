#include "nlink_linktrack_nodeframe0.h"

#include <stdio.h>

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t header[2];
  uint16_t frame_length;
  uint8_t role;
  uint8_t id;
  uint8_t reserved[4];
  uint8_t valid_node_count;
  // nodes...
  // uint8_t checkSum;
} nlt_nodeframe0_raw_t;
#pragma pack()
static nlt_nodeframe0_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nlt_nodeframe0.fixed_part_size ||
      data[0] != g_nlt_nodeframe0.frame_header ||
      data[1] != g_nlt_nodeframe0.function_mark)
    return 0;
  size_t frame_length = NLINK_PROTOCOL_LENGTH(data);
  if (data_length < frame_length)
    return 0;
  if (!NLINK_VerifyCheckSum(data, frame_length))
    return 0;

  static uint8_t init_needed = 1;
  if (init_needed) {
    memset(g_nlt_nodeframe0.result.nodes, 0,
           sizeof(g_nlt_nodeframe0.result.nodes));
    init_needed = 0;
  }

  memcpy(&g_frame, data, g_nlt_nodeframe0.fixed_part_size);
  g_nlt_nodeframe0.result.role = g_frame.role;
  g_nlt_nodeframe0.result.id = g_frame.id;
  g_nlt_nodeframe0.result.valid_node_count = g_frame.valid_node_count;

  for (size_t i = 0, address = g_nlt_nodeframe0.fixed_part_size;
       i < g_frame.valid_node_count; ++i) {
    const uint8_t *begin = data + address;
    size_t data_length = (size_t)(begin[2] | begin[3] << 8);
    size_t current_node_size = 4 + data_length;
    if (address + current_node_size > frame_length - 1) {
      printf("warning: address(%zu) + current_node_size(%zu) > "
             "frame_length(%zu)-1",
             address, current_node_size, frame_length);
      return 0;
    }

    TRY_MALLOC_NEW_NODE(g_nlt_nodeframe0.result.nodes[i], nlt_nodeframe0_node_t)
    nlt_nodeframe0_node_t *node = g_nlt_nodeframe0.result.nodes[i];
    node->role = begin[0];
    node->id = begin[1];
    node->data_length = data_length;
    memcpy(node->data, begin + 4, data_length);

    address += current_node_size;
  }

  return 1;
}

nlt_nodeframe0_t g_nlt_nodeframe0 = {.fixed_part_size = 11,
                                     .frame_header = 0x55,
                                     .function_mark = 0x02,
                                     .UnpackData = UnpackData};

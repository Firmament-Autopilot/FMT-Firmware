#include "nlink_linktrack_anchorframe0.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t id;
  uint8_t role;
  nint24_t pos_3d[3];
  uint16_t dis_arr[8];
} nlt_anchorframe0_tag_raw_t;

typedef struct {
  uint8_t header[2];
  nlt_anchorframe0_tag_raw_t nodes[30];
  uint8_t reserved0[67];
  uint32_t local_time;
  uint8_t reserved1[4];
  uint16_t voltage;
  uint32_t system_time;
  uint8_t id;
  uint8_t role;
  uint8_t tail_check;
} nlt_anchorframe0_raw_t;
#pragma pack()

static nlt_anchorframe0_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < nlt_anchorframe0_.fixed_part_size ||
      data[0] != nlt_anchorframe0_.frame_header ||
      data[1] != nlt_anchorframe0_.function_mark ||
      data[nlt_anchorframe0_.fixed_part_size - 1] !=
          nlt_anchorframe0_.tail_check)
    return 0;

  static uint8_t init_needed = 1;
  if (init_needed) {
    memset(nlt_anchorframe0_.result.nodes, 0,
           sizeof(nlt_anchorframe0_.result.nodes));
    init_needed = 0;
  }

  memcpy(&g_frame, data, nlt_anchorframe0_.fixed_part_size);
  nlt_anchorframe0_.result.role = g_frame.role;
  nlt_anchorframe0_.result.id = g_frame.id;
  nlt_anchorframe0_.result.local_time = g_frame.local_time;
  nlt_anchorframe0_.result.system_time = g_frame.system_time;
  nlt_anchorframe0_.result.voltage = g_frame.voltage / MULTIPLY_VOLTAGE;

  nlt_anchorframe0_.result.valid_node_count = 0;
  for (size_t i = 0, count = ARRAY_LENGTH(nlt_anchorframe0_.result.nodes);
       i < count; ++i) {
    if (g_frame.nodes[i].id == 0xff)
      continue;

    uint8_t index = nlt_anchorframe0_.result.valid_node_count;
    TRY_MALLOC_NEW_NODE(nlt_anchorframe0_.result.nodes[index],
                        nlt_anchorframe0_node_t)

    nlt_anchorframe0_.result.nodes[index]->role =
        (linktrack_role_e)g_frame.nodes[i].role;
    nlt_anchorframe0_.result.nodes[index]->id = g_frame.nodes[i].id;
    NLINK_TRANSFORM_ARRAY_INT24(nlt_anchorframe0_.result.nodes[index]->pos_3d,
                                g_frame.nodes[i].pos_3d, MULTIPLY_POS)
    NLINK_TRANSFORM_ARRAY(nlt_anchorframe0_.result.nodes[index]->dis_arr,
                          g_frame.nodes[i].dis_arr, 100.0f)

    ++nlt_anchorframe0_.result.valid_node_count;
  }
  return 1;
}

nlt_anchorframe0_t nlt_anchorframe0_ = {.fixed_part_size = 896,
                                        .frame_header = 0x55,
                                        .function_mark = 0x00,
                                        .tail_check = 0xee,
                                        .UnpackData = UnpackData};

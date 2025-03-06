#include "nlink_linktrack_nodeframe4.h"

#include "nlink_utils.h"

#pragma pack(1)

typedef struct {
  uint8_t id;
  nint24_t dis;
} nlt_nodeframe4_raw_anchor_t;

typedef struct {
  uint8_t id;
  uint8_t reserved[2];
  uint8_t voltage;
  uint8_t anchor_count;
  nlt_nodeframe4_raw_anchor_t anchors[MAX_ANCHOR_COUNT];
} nlt_nodeframe4_raw_tag_t;
int nlt_nodeframe4_raw_tag_size(const nlt_nodeframe4_raw_tag_t *data) {
  return sizeof(*data) - sizeof(data->anchors) +
         sizeof(data->anchors[0]) * data->anchor_count;
}

typedef struct {
  uint8_t header[2];
  uint16_t frame_length;
  uint8_t role;
  uint8_t id;
  uint32_t local_time;
  uint32_t system_time;
  uint8_t reserved0[4];
  uint16_t voltage;
  uint8_t tag_count;
  // nodes...
  // uint8_t checkSum;
} nlt_nodeframe4_raw_t;
#pragma pack()

static nlt_nodeframe4_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nlt_nodeframe4.fixed_part_size ||
      data[0] != g_nlt_nodeframe4.frame_header ||
      data[1] != g_nlt_nodeframe4.function_mark)
    return 0;
  size_t frame_length = NLINK_PROTOCOL_LENGTH(data);
  if (data_length < frame_length)
    return 0;
  if (!NLINK_VerifyCheckSum(data, frame_length))
    return 0;

  memcpy(&g_frame, data, g_nlt_nodeframe4.fixed_part_size);
  g_nlt_nodeframe4.result.role = g_frame.role;
  g_nlt_nodeframe4.result.id = g_frame.id;
  g_nlt_nodeframe4.result.local_time = g_frame.local_time;
  g_nlt_nodeframe4.result.system_time = g_frame.system_time;
  g_nlt_nodeframe4.result.voltage = g_frame.voltage / MULTIPLY_VOLTAGE;

  g_nlt_nodeframe4.result.tag_count = g_frame.tag_count;

  int addr = g_nlt_nodeframe4.fixed_part_size;
  for (int i = 0; i < g_frame.tag_count; ++i) {
    const nlt_nodeframe4_raw_tag_t *raw_tag =
        (const nlt_nodeframe4_raw_tag_t *)&data[addr];

    TRY_MALLOC_NEW_NODE(g_nlt_nodeframe4.result.tags[i], nlt_nodeframe4_tag_t)
    nlt_nodeframe4_tag_t *tag = g_nlt_nodeframe4.result.tags[i];
    tag->id = raw_tag->id;
    tag->voltage = raw_tag->voltage / 20.0f;
    tag->anchor_count = raw_tag->anchor_count;
    for (int j = 0; j < raw_tag->anchor_count; ++j) {
      TRY_MALLOC_NEW_NODE(tag->anchors[j], nlt_nodeframe4_anchor_t)
      tag->anchors[j]->id = raw_tag->anchors[j].id;
      tag->anchors[j]->dis =
          NLINK_ParseInt24(raw_tag->anchors[j].dis) / MULTIPLY_DIS;
    }

    addr += nlt_nodeframe4_raw_tag_size(raw_tag);
  }
  return 1;
}

nlt_nodeframe4_t g_nlt_nodeframe4 = {.fixed_part_size = 21,
                                     .frame_header = 0x55,
                                     .function_mark = 0x06,
                                     .UnpackData = UnpackData};

#ifndef NLINK_LINKTRACK_NODEFRAME4_H
#define NLINK_LINKTRACK_NODEFRAME4_H

#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"

typedef struct {
  uint8_t id;
  float dis;
} nlt_nodeframe4_anchor_t;

typedef struct {
  uint8_t id;
  float voltage;
  uint8_t anchor_count;
  nlt_nodeframe4_anchor_t *anchors[MAX_ANCHOR_COUNT];
} nlt_nodeframe4_tag_t;

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  uint32_t local_time;
  uint32_t system_time;
  float voltage;
  uint8_t tag_count;
  nlt_nodeframe4_tag_t *tags[MAX_TAG_COUNT];
} nlt_nodeframe4_result_t;

typedef struct {
  const size_t fixed_part_size;
  const uint8_t frame_header;
  const uint8_t function_mark;
  nlt_nodeframe4_result_t result;

  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);
} nlt_nodeframe4_t;

extern nlt_nodeframe4_t g_nlt_nodeframe4;

#ifdef __cplusplus
}
#endif
#endif // NLINK_LINKTRACK_NODEFRAME3_H

#ifndef NLINK_LINKTRACK_NODEFRAME1_H
#define NLINK_LINKTRACK_NODEFRAME1_H
#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  float pos_3d[3];
} nlt_nodeframe1_node_t;

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  uint32_t system_time;
  uint32_t local_time;
  float voltage;
  uint8_t valid_node_count;
  nlt_nodeframe1_node_t *nodes[256];
} nlt_nodeframe1_result_t;

typedef struct {
  const size_t fixed_part_size;
  const uint8_t frame_header;
  const uint8_t function_mark;
  nlt_nodeframe1_result_t result;
  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);
} nlt_nodeframe1_t;

extern nlt_nodeframe1_t g_nlt_nodeframe1;

#ifdef __cplusplus
}
#endif
#endif // NLINK_LINKTRACK_NODEFRAME1_H

#ifndef NLINK_LINKTRACK_ANCHORFRAME0_H
#define NLINK_LINKTRACK_ANCHORFRAME0_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nlink_typedef.h"

typedef struct {
  uint8_t id;
  linktrack_role_e role;
  float pos_3d[3];
  float dis_arr[8];
} nlt_anchorframe0_node_t;

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  uint32_t local_time;
  uint32_t system_time;
  float voltage;
  uint8_t valid_node_count;
  nlt_anchorframe0_node_t *nodes[30];
} nlt_anchorframe0_result_t;

typedef struct {
  const size_t fixed_part_size;
  const uint8_t frame_header;
  const uint8_t function_mark;
  const uint8_t tail_check;
  nlt_anchorframe0_result_t result;

  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);
} nlt_anchorframe0_t;

extern nlt_anchorframe0_t nlt_anchorframe0_;

#ifdef __cplusplus
}
#endif

#endif // NLINK_LINKTRACK_ANCHORFRAME0_H

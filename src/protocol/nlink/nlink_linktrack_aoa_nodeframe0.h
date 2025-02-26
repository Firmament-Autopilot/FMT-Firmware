#ifndef NLINK_LINKTRACK_AOA_NODEFRAME0_H
#define NLINK_LINKTRACK_AOA_NODEFRAME0_H
#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  float dis;
  float angle;
  float fp_rssi;
  float rx_rssi;
} nltaoa_nodeframe0_node_t;

typedef struct {
  linktrack_role_e role;
  uint8_t id;
  uint32_t local_time;
  uint32_t system_time;
  float voltage;
  uint8_t valid_node_count;
  nltaoa_nodeframe0_node_t *nodes[256];
} nltaoa_nodeframe0_result_t;

typedef struct {
  const uint8_t frame_header;
  const uint8_t function_mark;
  const size_t fixed_part_size;
  nltaoa_nodeframe0_result_t result;

  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);

} nltaoa_nodeframe0_t;

extern nltaoa_nodeframe0_t g_nltaoa_nodeframe0;

#ifdef __cplusplus
}
#endif

#endif // NLINK_LINKTRACK_AOA_NODEFRAME0_H

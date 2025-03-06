#ifndef NLINK_IOT_FRAME0_H
#define NLINK_IOT_FRAME0_H
#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"

#define IOT_FRAME0_NODE_COUNT_MAX 10
typedef struct {
  uint32_t uid;
  float dis;
  float aoa_angle_horizontal;
  float aoa_angle_vertical;
  float fp_rssi;
  float rx_rssi;
  uint8_t user_data_len;
  uint8_t user_data[16];
} iot_frame0_node_t;

typedef struct {
  const size_t fixed_part_size;
  const uint8_t frame_header;
  const uint8_t function_mark;
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
  iot_frame0_node_t nodes[IOT_FRAME0_NODE_COUNT_MAX];
  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);
} iot_frame0_t;

extern iot_frame0_t g_iot_frame0;

#ifdef __cplusplus
}
#endif
#endif // NLINK_IOT_FRAME0_H

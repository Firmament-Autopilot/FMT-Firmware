#ifndef NLINK_TOFSENSEM_FRAME0_H
#define NLINK_TOFSENSEM_FRAME0_H
#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"

typedef struct {
  float dis;
  uint8_t dis_status;
  uint16_t signal_strength;
} ntsm_frame0_pixel_t;

typedef struct {
  const size_t fixed_part_size;
  const uint8_t frame_header;
  const uint8_t function_mark;
  uint8_t id;
  uint32_t system_time;
  uint8_t pixel_count; // use pixel_count to judge valid pixels
  ntsm_frame0_pixel_t pixels[64];
  uint8_t (*const UnpackData)(const uint8_t *data, size_t data_length);
} ntsm_frame0_t;

extern ntsm_frame0_t g_ntsm_frame0;

int tofm_frame0_size(const void *data);

#ifdef __cplusplus
}
#endif
#endif // NLINK_TOFSENSEM_FRAME0_H

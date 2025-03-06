#include "nlink_tofsensem_frame0.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  nint24_t dis;
  uint8_t dis_status;
  uint16_t signal_strength;
} ntsm_frame0_pixel_raw_t;

typedef struct {
  uint8_t frame_header;
  uint8_t function_mark;
  uint8_t reserved;
  uint8_t id;
  uint32_t system_time;
  uint8_t pixel_count;
  ntsm_frame0_pixel_raw_t pixels[64];
  uint8_t reserved1[6];
  uint8_t sum;
} ntsm_frame0_raw_t;
#pragma pack()

int tofm_frame0_size(const void *data) {
  const ntsm_frame0_raw_t *raw = (const ntsm_frame0_raw_t *)data;
  return sizeof(*raw) - sizeof(raw->pixels) +
         sizeof(raw->pixels[0]) * raw->pixel_count;
}

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  const ntsm_frame0_raw_t *frame0 = (const ntsm_frame0_raw_t *)data;
  if (frame0->frame_header != g_ntsm_frame0.frame_header ||
      frame0->function_mark != g_ntsm_frame0.function_mark ||
      data_length < g_ntsm_frame0.fixed_part_size) {
    return 0;
  }

  if (frame0->pixel_count != 16 && frame0->pixel_count != 64) {
    return 0;
  }

  if (tofm_frame0_size(data) != data_length) {
    return 0;
  }

  if (!NLINK_VerifyCheckSum(data, data_length)) {
    return 0;
  }

  g_ntsm_frame0.id = frame0->id;
  g_ntsm_frame0.system_time = frame0->system_time;
  g_ntsm_frame0.pixel_count = frame0->pixel_count;
  for (int i = 0; i < frame0->pixel_count; i++) {
    g_ntsm_frame0.pixels[i].dis_status = frame0->pixels[i].dis_status;
    g_ntsm_frame0.pixels[i].signal_strength = frame0->pixels[i].signal_strength;
    g_ntsm_frame0.pixels[i].dis =
        NLINK_ParseInt24(frame0->pixels[i].dis) / 1000.0f;
  }
  return 1;
}

ntsm_frame0_t g_ntsm_frame0 = {.fixed_part_size = 9,
                               .frame_header = 0x57,
                               .function_mark = 0x01,
                               .UnpackData = UnpackData};

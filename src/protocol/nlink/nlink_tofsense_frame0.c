#include "nlink_tofsense_frame0.h"

#include "nlink_utils.h"

#pragma pack(1)
typedef struct {
  uint8_t header[2];
  uint8_t reserved0;
  uint8_t id;
  uint32_t system_time;
  nint24_t dis;
  uint8_t dis_status;
  uint16_t signal_strength;
  uint8_t range_precision;
  uint8_t check_sum;
} nts_frame0_raw_t;
#pragma pack()

static nts_frame0_raw_t g_frame;

static uint8_t UnpackData(const uint8_t *data, size_t data_length) {
  if (data_length < g_nts_frame0.fixed_part_size ||
      data[0] != g_nts_frame0.frame_header ||
      data[1] != g_nts_frame0.function_mark)
    return 0;
  if (!NLINK_VerifyCheckSum(data, g_nts_frame0.fixed_part_size))
    return 0;

  memcpy(&g_frame, data, g_nts_frame0.fixed_part_size);
  g_nts_frame0.result.id = g_frame.id;
  g_nts_frame0.result.system_time = g_frame.system_time;
  g_nts_frame0.result.dis_status = g_frame.dis_status;
  g_nts_frame0.result.signal_strength = g_frame.signal_strength;
  g_nts_frame0.result.range_precision = g_frame.range_precision;
  g_nts_frame0.result.dis = NLINK_ParseInt24(g_frame.dis) / 1000.0f;

  return 1;
}

nts_frame0_t g_nts_frame0 = {.fixed_part_size = 16,
                             .frame_header = 0x57,
                             .function_mark = 0x00,
                             .UnpackData = UnpackData};

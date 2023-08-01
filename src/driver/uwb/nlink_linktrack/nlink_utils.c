#include "nlink_utils.h"

int32_t NLINK_ParseInt24(nint24_t data) {
  uint8_t *byte = (uint8_t *)(&data);
  return (int32_t)(byte[0] << 8 | byte[1] << 16 | byte[2] << 24) / 256;
}
uint32_t NLINK_ParseUint24(nuint24_t data) {
  uint8_t *byte = (uint8_t *)(&data);
  return byte[0] | byte[1] << 8 | byte[2] << 16;
}

uint8_t NLINK_VerifyCheckSum(const void *data, size_t data_length) {
  const uint8_t *byte = (uint8_t *)data;
  uint8_t sum = 0;
  for (size_t i = 0; i < data_length - 1; ++i) {
    sum += byte[i];
  }
  return sum == byte[data_length - 1];
}

size_t NLink_StringToHex(const char *str, uint8_t *out) {
  size_t outLength = 0;
  size_t cnt = 0;
  uint8_t high = 0, low = 0;
  uint8_t current = 0;
  uint8_t value = 0;
  uint8_t isHighValid = 0;
  while ((current = str[cnt])) {
    ++cnt;
    if (current >= '0' && current <= '9') {
      value = (uint8_t)(current - '0');
    } else if (current >= 'a' && current <= 'f') {
      value = (uint8_t)(current - 'a' + 10);
    } else if (current >= 'A' && current <= 'F') {
      value = (uint8_t)(current - 'A' + 10);
    } else {
      continue;
    }
    if (!isHighValid) {
      high = value;
      isHighValid = 1;
    } else {
      low = value;
      out[outLength] = (uint8_t)(high << 4 | low);
      ++outLength;
      isHighValid = 0;
    }
  }
  return outLength;
}

void NLink_UpdateCheckSum(uint8_t *data, size_t data_length) {
  uint8_t sum = 0;
  for (size_t i = 0; i < data_length - 1; ++i) {
    sum += data[i];
  }
  data[data_length - 1] = sum;
}

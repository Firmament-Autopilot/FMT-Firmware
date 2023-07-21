#ifndef NLINK_UTILS_H
#define NLINK_UTILS_H
#ifdef __cplusplus
extern "C" {
#endif
#include "nlink_typedef.h"
/*
// Macro to define packed structures
#ifndef _MSC_VER
#define #pragma pack(1)
 __Declaration__) __Declaration__ __attribute__((packed))
#else
#define #pragma pack(1)
 __Declaration__) \
    __pragma(pack(push, 1)) __Declaration__ __pragma(pack(pop))
#endif
*/
#define ARRAY_LENGTH(X) (sizeof(X) / sizeof(X[0]))

#define NLINK_PROTOCOL_LENGTH(X) ((size_t)(X[2] | X[3] << 8))

#define NLINK_TRANSFORM_ARRAY(DEST, SRC, MULTIPLY)                             \
  for (size_t _CNT = 0; _CNT < sizeof(SRC) / sizeof(SRC[0]); ++_CNT) {         \
    DEST[_CNT] = SRC[_CNT] / MULTIPLY;                                         \
  }

#define NLINK_TRANSFORM_ARRAY_INT24(DEST, SRC, MULTIPLY)                       \
  for (size_t _CNT = 0; _CNT < sizeof(SRC) / sizeof(SRC[0]); ++_CNT) {         \
    DEST[_CNT] = NLINK_ParseInt24(SRC[_CNT]) / MULTIPLY;                       \
  }

#define TRY_MALLOC_NEW_NODE(NODE_POINTER, NODE_TYPE)                           \
  if (!NODE_POINTER) {                                                         \
    void *p = malloc(sizeof(NODE_TYPE));                                       \
    if (p != NULL) {                                                           \
      NODE_POINTER = (NODE_TYPE *)p;                                           \
      memset(p, 0, sizeof(NODE_TYPE));                                         \
    } else {                                                                   \
      printf("Memory allocation failed, please increase heap size to support " \
             "protocol unpack.\r\n");                                          \
      return 0;                                                                \
    }                                                                          \
  }

#pragma pack(1)
typedef struct {
  uint8_t byteArray[3];
} nint24_t;

typedef struct {
  uint8_t byteArray[3];
} nuint24_t;
#pragma pack()

int32_t NLINK_ParseInt24(nint24_t data);

uint32_t NLINK_ParseUint24(nuint24_t data);

uint8_t NLINK_VerifyCheckSum(const void *data, size_t data_length);

void NLink_UpdateCheckSum(uint8_t *data, size_t data_length);

size_t NLink_StringToHex(const char *str, uint8_t *out);

#define MULTIPLY_VOLTAGE 1000.0f
#define MULTIPLY_POS 1000.0f
#define MULTIPLY_DIS 1000.0f
#define MULTIPLY_VEL 10000.0f
#define MULTIPLY_ANGLE 100.0f
#define MULTIPLY_RSSI -2.0f
#define MULTIPLY_EOP 100.0f

#ifdef __cplusplus
}
#endif
#endif // NLINK_UTILS_H

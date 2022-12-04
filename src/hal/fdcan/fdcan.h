#ifndef FDCAN_H_
#define FDCAN_H_

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FDCAN_BAUD_RATE_5000K 5000 /* 5000 kBit/sec */
#define FDCAN_BAUD_RATE_2000K 2000 /* 2000 kBit/sec */
#define FDCAN_BAUD_RATE_1000K 1000 /* 1000 kBit/sec */
#define FDCAN_BAUD_RATE_800K  800  /* 800 kBit/sec */
#define FDCAN_BAUD_RATE_500K  500  /* 500 kBit/sec */

/* Default config for serial_configure structure */
#define FDCAN_DEFAULT_CONFIG                       \
    {                                              \
        FDCAN_BAUD_RATE_1000K, /* 1000 kBit/sec */ \
    }

typedef struct {
    uint32_t id;
    uint8_t data[8];
    uint8_t len;
} fdcan_msg, *fdcan_msg_t;

struct fdcan_configure {
    rt_uint32_t baud_rate;

    // rt_uint32_t frame_classic; //数据传输模式 1：Class CAN 2：FDCAN

    // rt_uint32_t mode; //模式

    // rt_uint32_t elmt_size; //传输元素大小
};

typedef struct {
    struct rt_device parent;

    const struct fdcan_ops* ops;

    struct fdcan_configure config;

    struct rt_event event;
} fdcan_device, *fdcan_dev_t;

/**
 * uart operators
 */
struct fdcan_ops {
    rt_err_t (*configure)(fdcan_dev_t can, struct fdcan_configure* cfg);
    rt_err_t (*control)(fdcan_dev_t can, int cmd, void* arg);
    int (*sendmsg)(fdcan_dev_t can, const void* buf);
    int (*recvmsg)(fdcan_dev_t can, void* buf);
};

rt_err_t rt_hw_can_register(fdcan_dev_t fdcan, const char* name, rt_uint32_t flag, void* data);

void rt_hw_can_isr(fdcan_dev_t fdcan, int event);

#ifdef __cplusplus
}
#endif

#endif
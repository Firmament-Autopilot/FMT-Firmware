#ifndef CAN_H_
#define CAN_H_

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CAN_BAUD_RATE_5000K 5000 /* 5000 kBit/sec */
#define CAN_BAUD_RATE_2000K 2000 /* 2000 kBit/sec */
#define CAN_BAUD_RATE_1000K 1000 /* 1000 kBit/sec */
#define CAN_BAUD_RATE_800K  800  /* 800 kBit/sec */
#define CAN_BAUD_RATE_500K  500  /* 500 kBit/sec */

/* Default config for serial_configure structure */
#define CAN_DEFAULT_CONFIG                       \
    {                                            \
        CAN_BAUD_RATE_1000K, /* 1000 kBit/sec */ \
    }

typedef struct {
    uint32_t id;
    uint8_t data[8];
    uint8_t len;
    uint8_t extid;
} can_msg, *can_msg_t;

struct can_configure {
    rt_uint32_t baud_rate;

    // rt_uint32_t frame_classic; //数据传输模式 1：Class CAN 2：CAN

    // rt_uint32_t mode; //模式

    // rt_uint32_t elmt_size; //传输元素大小
};

typedef struct {
    struct rt_device parent;

    const struct can_ops* ops;

    struct can_configure config;

    struct rt_event event;
} can_device, *can_dev_t;

/**
 * uart operators
 */
struct can_ops {
    rt_err_t (*configure)(can_dev_t can, struct can_configure* cfg);
    rt_err_t (*control)(can_dev_t can, int cmd, void* arg);
    int (*sendmsg)(can_dev_t can, const void* buf);
    int (*recvmsg)(can_dev_t can, void* buf);
};

rt_err_t hw_can_register(can_dev_t can, const char* name, rt_uint32_t flag, void* data);

#ifdef __cplusplus
}
#endif

#endif
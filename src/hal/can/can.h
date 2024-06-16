#ifndef CAN_H_
#define CAN_H_

#include <firmament.h>

#include "module/utils/ringbuffer.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CAN_MSG_LEN         sizeof(can_msg)
#define CAN_RX_FIFO_SIZE    8

#define CAN_BAUD_RATE_5000K 5000 /* 5000 kBit/sec */
#define CAN_BAUD_RATE_2000K 2000 /* 2000 kBit/sec */
#define CAN_BAUD_RATE_1000K 1000 /* 1000 kBit/sec */
#define CAN_BAUD_RATE_800K  800  /* 800 kBit/sec */
#define CAN_BAUD_RATE_500K  500  /* 500 kBit/sec */

/* can device command */
#define CAN_OPEN_DEVICE     1000
#define CAN_CLOSE_DEVICE    1001

/* serial isr event */
#define CAN_EVENT_RX_IND    0x01 /* Rx indication */
#define CAN_EVENT_TX_DONE   0x02 /* Tx complete   */

#define CAN_RES_TX_OK       0x1000
#define CAN_RES_TX_FAIL     0x1001

/* Default config for serial_configure structure */
#define CAN_DEFAULT_CONFIG                       \
    {                                            \
        CAN_BAUD_RATE_1000K, /* 1000 kBit/sec */ \
    }

typedef struct
{
    uint32_t std_id; /*!< Specifies the standard identifier.
                         This parameter must be a number between Min_Data = 0 and Max_Data = 0x7FF */
    uint32_t ext_id; /*!< Specifies the extended identifier.
                         This parameter must be a number between Min_Data = 0 and Max_Data = 0x1FFFFFFF */
    uint32_t IDE;    /*!< Specifies the type of identifier for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_Identifier_Type */
    uint32_t RTR;    /*!< Specifies the type of frame for the message that will be transmitted.
                          This parameter can be a value of @ref CAN_remote_transmission_request */
    uint32_t DLC;    /*!< Specifies the length of the frame that will be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 8 */
    uint8_t data[8]; /*!< Contains the data to be transmitted.
                          This parameter must be a number between Min_Data = 0 and Max_Data = 0xFF */
} can_msg, *can_msg_t;

struct can_configure {
    uint32_t baud_rate;
};

typedef struct {
    struct rt_device      parent;
    const struct can_ops* ops;
    struct can_configure  config;
    ringbuffer*           rx_fifo;
    rt_sem_t              tx_lock;
    struct rt_completion  tx_cplt;
    struct rt_completion  rx_cplt;
} can_device, *can_dev_t;

/**
 * uart operators
 */
struct can_ops {
    rt_err_t (*configure)(can_dev_t can, struct can_configure* cfg);
    rt_err_t (*control)(can_dev_t can, int cmd, void* arg);
    int (*sendmsg)(can_dev_t can, const can_msg_t msg);
    int (*recvmsg)(can_dev_t can, can_msg_t msg);
};

rt_err_t hal_can_register(can_dev_t can, const char* name, rt_uint32_t flag, void* data);
void     hal_can_notify(can_device* can, int event, void* data);

#ifdef __cplusplus
}
#endif

#endif
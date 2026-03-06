#ifndef EDGE_IPC_COMMON_H
#define EDGE_IPC_COMMON_H

#include "cy_ipc_pipe.h"

#define CY_IPC_MAX_ENDPOINTS            (5UL)
#define CY_IPC_CYPIPE_CLIENT_CNT        (8UL)

#define CY_IPC_CHAN_CYPIPE_EP1          (4UL)
#define CY_IPC_INTR_CYPIPE_EP1          (4UL)
#define CY_IPC_CHAN_CYPIPE_EP2          (15UL)
#define CY_IPC_INTR_CYPIPE_EP2          (5UL)

#define CY_IPC_CYPIPE_CHAN_MASK_EP1     CY_IPC_CH_MASK(CY_IPC_CHAN_CYPIPE_EP1)
#define CY_IPC_CYPIPE_INTR_MASK_EP1     CY_IPC_INTR_MASK(CY_IPC_INTR_CYPIPE_EP1)
#define CY_IPC_INTR_CYPIPE_PRIOR_EP1    (1UL)
#define CY_IPC_INTR_CYPIPE_MUX_EP1      (CY_IPC0_INTR_MUX(CY_IPC_INTR_CYPIPE_EP1))
#define CM33_IPC_PIPE_EP_ADDR           (1UL)
#define CM33_IPC_PIPE_CLIENT_ID         (3UL)

#define CY_IPC_CYPIPE_CHAN_MASK_EP2     CY_IPC_CH_MASK(CY_IPC_CHAN_CYPIPE_EP2)
#define CY_IPC_CYPIPE_INTR_MASK_EP2     CY_IPC_INTR_MASK(CY_IPC_INTR_CYPIPE_EP2)
#define CY_IPC_INTR_CYPIPE_PRIOR_EP2    (1UL)
#define CY_IPC_INTR_CYPIPE_MUX_EP2      (CY_IPC0_INTR_MUX(CY_IPC_INTR_CYPIPE_EP2))
#define CM55_IPC_PIPE_EP_ADDR           (2UL)
#define CM55_IPC_PIPE_CLIENT_ID         (5UL)

#define CY_IPC_CYPIPE_INTR_MASK         (CY_IPC_CYPIPE_CHAN_MASK_EP1 | CY_IPC_CYPIPE_CHAN_MASK_EP2)
#define IPC_DEMO_SEMA_NUM               (48UL)

#define RC_CHANNEL_COUNT                (8U)
#define RC_MAGIC_WORD                   (0x5243444DU)
#define RC_ROLE_M33                     (0x33U)
#define RC_ROLE_M55_ECHO                (0x55U)

/* Stress-test tuning knobs */
#define EDGE_IPC_FRAME_POOL_SIZE        (64U)
#define EDGE_IPC_ECHO_QUEUE_SIZE        (64U)
#define EDGE_IPC_STRESS_HZ              (1000U)
#define EDGE_IPC_STRESS_BURST           (4U)
#define EDGE_IPC_SEMA_RETRY_MAX         (2U)
#define EDGE_IPC_PRINT_INTERVAL_MS      (1000U)

typedef struct
{
    uint8_t client_id;
    uint16_t intr_mask;
    uint8_t role;
    uint32_t magic;
    uint32_t seq;
    uint16_t channel[RC_CHANNEL_COUNT];
    uint32_t checksum;
} edge_rc_frame_t;

static inline uint32_t edge_rc_checksum(const edge_rc_frame_t* frame)
{
    uint32_t sum = frame->magic ^ frame->role ^ frame->seq;
    uint32_t i;

    for (i = 0; i < RC_CHANNEL_COUNT; i++)
    {
        sum ^= ((uint32_t)frame->channel[i] << (i & 0x7));
        sum = (sum << 3) | (sum >> 29);
    }

    return sum;
}

#endif

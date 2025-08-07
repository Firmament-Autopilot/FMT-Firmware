/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */
#ifndef __DRV_ETH_H__
#define __DRV_ETH_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ETH_RESET_PIN               GPIO_PIN_4
#define ETH_RESET_GPIO_PORT         GPIOE

/* The PHY basic control register */
#define PHY_BASIC_CONTROL_REG       0x00U
#define PHY_RESET_MASK              (1 << 15)
#define PHY_AUTO_NEGOTIATION_MASK   (1 << 12)

/* The PHY basic status register */
#define PHY_BASIC_STATUS_REG        0x01U
#define PHY_LINKED_STATUS_MASK      (1 << 2)
#define PHY_AUTONEGO_COMPLETE_MASK  (1 << 5)

/* The PHY ID one register */
#define PHY_ID1_REG                 0x02U

/* The PHY ID two register */
#define PHY_ID2_REG                 0x03U

/* The PHY SPECIAL MODES REGISTER */
#define PHY_SPECIAL_MODES_REG       0x12U

/* The PHY auto-negotiate advertise register */
#define PHY_AUTONEG_ADVERTISE_REG   0x04U

#define PHY_Status_REG              0x1FU
#define PHY_FULL_DUPLEX_MASK        (1 << 4)
#define PHY_Status_SPEED_10M(sr)    ((sr)&PHY_10M_MASK)
#define PHY_Status_SPEED_100M(sr)   ((sr)&PHY_100M_MASK)
#define PHY_Status_FULL_DUPLEX(sr)  ((sr)&PHY_FULL_DUPLEX_MASK)

/*  The PHY interrupt source flag register. */
#define PHY_INTERRUPT_FLAG_REG      0x1DU
/*  The PHY interrupt mask register. */
#define PHY_INTERRUPT_MASK_REG      0x1EU
#define PHY_LINK_DOWN_MASK          (1 << 4)
#define PHY_AUTO_NEGO_COMPLETE_MASK (1 << 6)

/*  The PHY status register. */
#define PHY_Status_REG              0x1FU
#define PHY_10M_MASK                (1 << 2)
#define PHY_100M_MASK               (1 << 3)
#define PHY_FULL_DUPLEX_MASK        (1 << 4)

rt_err_t drv_eth_init(void);

#ifdef __cplusplus
}
#endif

#endif
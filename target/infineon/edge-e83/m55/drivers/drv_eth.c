/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Ethernet driver for PSOC Edge E83
 * Adapted for RT-Thread netdev/lwIP framework
 */

#include "drv_eth.h"

#include <lwip/pbuf.h>
#include <netif/ethernetif.h>

#include "cy_device_headers.h"
#include "cy_ethif.h"
#include "cy_gpio.h"
#include "cy_sysclk.h"
#include "cy_sysint.h"
#include "cycfg_pins.h"

#undef LOG_TAG
#undef LOG_LVL
#define LOG_TAG "drv.eth"
#define LOG_LVL LOG_LVL_INFO
#include "module/log/ulog.h"

/* ======================== Configuration ======================== */

/* Debug shell commands switch (default: disabled) */
#ifndef ETH_DRV_DEBUG
#define ETH_DRV_DEBUG 0
#endif

/*
 * Force CM55 ETH IRQ numbers - the header file conditional compilation
 */
#ifndef BSP_ETH_PHY_ADDR
#define BSP_ETH_PHY_ADDR 0U
#endif

#define BSP_ETH_RX_BUF_SIZE  1536U
#define BSP_ETH_TX_BUF_SIZE  1536U

#define BSP_ETH_QUEUE_ID     0U

/* PHY Register Definitions */
#define PHY_REG_BMCR         0x00U
#define PHY_REG_BMSR         0x01U
#define PHY_REG_PHYID1       0x02U
#define PHY_REG_PHYID2       0x03U

#define PHY_BMCR_RESET       (1U << 15)
#define PHY_BMCR_AN_ENABLE   (1U << 12)
#define PHY_BMCR_RESTART_AN  (1U << 9)

#define PHY_BMSR_LINK        (1U << 2)
#define PHY_BMSR_AN_COMPLETE (1U << 5)

/* Maximum RX frames to queue */
#define ETH_RX_QUEUE_SIZE    8U

/* ======================== Data Structures ======================== */

/* RX frame descriptor */
struct eth_rx_frame
{
    uint8_t *data;
    uint32_t len;
};

struct rt_psoc_eth
{
    struct eth_device parent;
#ifndef PHY_USING_INTERRUPT_MODE
    rt_timer_t poll_link_timer;
#endif
    rt_uint8_t dev_addr[6];
    rt_bool_t link_up;
    rt_uint8_t phy_addr;

    /* RX frame queue */
    struct eth_rx_frame rx_queue[ETH_RX_QUEUE_SIZE];
    volatile uint32_t rx_queue_head;
    volatile uint32_t rx_queue_tail;

    /* RX buffer index for DMA */
    volatile uint32_t rx_buf_idx;

    rt_mutex_t tx_lock;
};

/* Use CM55-specific IRQ numbers (171, 172, 173) */
const cy_stc_sysint_t intr_cfg_0 =
{
    .intrSrc = eth_interrupt_eth_0_IRQn,
    .intrPriority = 7U,
};
const cy_stc_sysint_t intr_cfg_1 =
{
    .intrSrc = eth_interrupt_eth_1_IRQn,
    .intrPriority = 7U,
};
const cy_stc_sysint_t intr_cfg_2 =
{
    .intrSrc = eth_interrupt_eth_2_IRQn,
    .intrPriority = 7U,
};

/* ======================== Static Variables ======================== */

static struct rt_psoc_eth psoc_eth;

/* RX buffer pool - must be aligned for DMA and in SOCMEM */
CY_SECTION(".cy_socmem_data")
CY_ALIGN(32)
static uint8_t psoc_eth_rx_buf[CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE][BSP_ETH_RX_BUF_SIZE];
/* TX buffer - must be aligned for DMA and in SOCMEM */
CY_SECTION(".cy_socmem_data")
CY_ALIGN(32)
static uint8_t psoc_eth_tx_buf[BSP_ETH_TX_BUF_SIZE];

/* Buffer pool pointer array for ETHIF driver - must be in SOCMEM for DMA access */
CY_SECTION(".cy_socmem_data")
static cy_ethif_buffpool_t psoc_eth_rx_pool;

/* Configuration structures */
static cy_stc_ethif_wrapper_config_t psoc_eth_wrapper_cfg;
static cy_stc_ethif_mac_config_t psoc_eth_mac_cfg;
static cy_stc_ethif_intr_config_t psoc_eth_intr_cfg;
static cy_stc_ethif_cb_t psoc_eth_cb;

/* ======================== IRQ Handlers (Forward Declaration) ======================== */

void eth_interrupt_eth_0_IRQHandler(void);
void eth_interrupt_eth_1_IRQHandler(void);
void eth_interrupt_eth_2_IRQHandler(void);

#define __is_print(ch) ((unsigned int)((ch) - ' ') < 127u - ' ')
static void dump_hex(const rt_uint8_t *ptr, rt_size_t buflen)
{
#if (ETH_DRV_DEBUG == 1)
    unsigned char *buf = (unsigned char *)ptr;
    int i, j;

    for (i = 0; i < buflen; i += 16)
    {
        rt_kprintf("%08X: ", i);

        for (j = 0; j < 16; j++)
            if (i + j < buflen)
                rt_kprintf("%02X ", buf[i + j]);
            else
                rt_kprintf("   ");
        rt_kprintf(" ");

        for (j = 0; j < 16; j++)
            if (i + j < buflen)
                rt_kprintf("%c", __is_print(buf[i + j]) ? buf[i + j] : '.');
        rt_kprintf("\n");
    }
#endif
}
/* ======================== RX Queue Helpers ======================== */

static inline rt_bool_t rx_queue_is_full(void)
{
    uint32_t next = (psoc_eth.rx_queue_head + 1U) % ETH_RX_QUEUE_SIZE;
    return (next == psoc_eth.rx_queue_tail);
}

static inline rt_bool_t rx_queue_is_empty(void)
{
    return (psoc_eth.rx_queue_head == psoc_eth.rx_queue_tail);
}

static inline void rx_queue_push(uint8_t *data, uint32_t len)
{
    if (!rx_queue_is_full())
    {
        psoc_eth.rx_queue[psoc_eth.rx_queue_head].data = data;
        psoc_eth.rx_queue[psoc_eth.rx_queue_head].len = len;
        psoc_eth.rx_queue_head = (psoc_eth.rx_queue_head + 1U) % ETH_RX_QUEUE_SIZE;
    }
}

static inline struct eth_rx_frame *rx_queue_pop(void)
{
    struct eth_rx_frame *frame = RT_NULL;
    if (!rx_queue_is_empty())
    {
        frame = &psoc_eth.rx_queue[psoc_eth.rx_queue_tail];
        psoc_eth.rx_queue_tail = (psoc_eth.rx_queue_tail + 1U) % ETH_RX_QUEUE_SIZE;
    }
    return frame;
}

/* ======================== Static Functions ======================== */

/**
 * @brief Generate MAC address from chip unique ID
 */
static void psoc_eth_set_default_mac(void)
{
    uint64_t uid = Cy_SysLib_GetUniqueId();

    /* Set locally administered bit */
    psoc_eth.dev_addr[0] = 0x02;
    psoc_eth.dev_addr[1] = (uid >> 40) & 0xFF;
    psoc_eth.dev_addr[2] = (uid >> 32) & 0xFF;
    psoc_eth.dev_addr[3] = (uid >> 24) & 0xFF;
    psoc_eth.dev_addr[4] = (uid >> 16) & 0xFF;
    psoc_eth.dev_addr[5] = (uid >> 8) & 0xFF;
}

/**
 * @brief Initialize RMII pins for Ethernet
 *
 * RMII Data (output to PHY):
 * - TXD0:   P11.2 (CYBSP_BT_DEV_WAKE)
 * - TXD1:   P11.3 (CYBSP_SMART_IO_OUTPUT)
 *
 * RMII Control (output to PHY):
 * - TX_EN:  P11.4 (CYBSP_WIFI_HOST_WAKE)
 *
 * RMII Reference Clock (input from PHY or output to PHY):
 * - REF_CLK: P11.7 (CYBSP_ARD_D4)
 *
 * RMII Data (input from PHY):
 * - RXD0:   P10.6 (CYBSP_BT_DEVICE_WAKE)
 * - RXD1:   P10.7 (CYBSP_ARD_D9)
 *
 * RMII Control (input from PHY):
 * - RX_DV:  P10.5 (CYBSP_ARD_D6)
 *
 * MDIO:
 * - MDC:    P13.1 (output)
 * - MDIO:   P13.6 (open-drain bidirectional)
 */
static void psoc_eth_pin_init(void)
{
    /* RMII TX Data pins (output to PHY) */
    Cy_GPIO_Pin_Init(GPIO_PRT11, 2U, &CYBSP_ETH_TXD_0_config); /* TXD0 - P11.2 */
    Cy_GPIO_Pin_Init(GPIO_PRT11, 3U, &CYBSP_ETH_TXD_1_config); /* TXD1 - P11.3 */

    /* RMII TX Control pin */
    Cy_GPIO_Pin_Init(GPIO_PRT11, 4U, &CYBSP_ETH_TX_CTL_config); /* TX_CTL - P11.4 */

    /* RMII Reference Clock (input from PHY for 100Mbps) */
    Cy_GPIO_Pin_Init(GPIO_PRT11, 7U, &CYBSP_ETH_REF_CLK_config); /* REF_CLK - P11.7 */

    /* RMII RX Data pins (input from PHY) */
    Cy_GPIO_Pin_Init(GPIO_PRT10, 6U, &CYBSP_ETH_RXD_0_config); /* RXD0 - P10.6 */
    Cy_GPIO_Pin_Init(GPIO_PRT10, 7U, &CYBSP_ETH_RXD_1_config); /* RXD1 - P10.7 */

    /* RMII RX Control pin */
    Cy_GPIO_Pin_Init(GPIO_PRT10, 5U, &CYBSP_ETH_RX_CTL_config); /* RX_DV - P10.5 */

    /* MDIO pins */
    Cy_GPIO_Pin_Init(GPIO_PRT13, 1U, &CYBSP_ETH_MDC_config); /* MDC - P13.1 */
    Cy_GPIO_Pin_Init(GPIO_PRT13, 6U, &CYBSP_ETH_MDIO_config);  /* MDIO - P13.6 */
}

/**
 * @brief Initialize ETH peripheral clock
 */
static void psoc_eth_clock_init(void)
{
    if (!Cy_SysClk_IsPeriGroupSlaveEnabled(CY_MMIO_ETH0_PERI_NR, CY_MMIO_ETH0_GROUP_NR, CY_MMIO_ETH0_SLAVE_NR))
    {
        Cy_SysClk_PeriGroupSlaveInit(CY_MMIO_ETH0_PERI_NR, CY_MMIO_ETH0_GROUP_NR, CY_MMIO_ETH0_SLAVE_NR, CY_MMIO_ETH0_CLK_HF_NR);
    }
}

/**
 * @brief Initialize RX buffer pool
 */
static void psoc_eth_rx_pool_init(void)
{
    for (rt_uint32_t i = 0; i < CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE; i++)
    {
        psoc_eth_rx_pool[i] = psoc_eth_rx_buf[i];
    }
}

/**
 * @brief Initialize interrupts
 */
static void psoc_eth_intr_init(void)
{
    (void)Cy_SysInt_Init(&intr_cfg_0, &eth_interrupt_eth_0_IRQHandler);
    (void)Cy_SysInt_Init(&intr_cfg_1, &eth_interrupt_eth_1_IRQHandler);
    (void)Cy_SysInt_Init(&intr_cfg_2, &eth_interrupt_eth_2_IRQHandler);

    NVIC_EnableIRQ((IRQn_Type)intr_cfg_0.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)intr_cfg_1.intrSrc);
    NVIC_EnableIRQ((IRQn_Type)intr_cfg_2.intrSrc);
}

/**
 * @brief RX frame callback from ETHIF driver (called in ISR context)
 *        This is called when a complete frame is received
 */
static void psoc_eth_rx_frame_cb(ETH_Type *base, uint8_t *rxbuf, uint32_t len)
{
    (void)base;

    dump_hex(&rxbuf[0], len);

    if (len == 0 || rxbuf == RT_NULL)
    {
        return;
    }

    /* Invalidate cache for received data */
    SCB_InvalidateDCache_by_Addr((void *)rxbuf, (int32_t)len);

    /* Push frame to queue */
    rx_queue_push(rxbuf, len);

    /* Notify RT-Thread ethernet framework */
    eth_device_ready(&psoc_eth.parent);
}

/**
 * @brief RX get buffer callback - provides new buffer for DMA
 */
static void psoc_eth_rx_getbuff_cb(ETH_Type *base, uint8_t **buf, uint32_t *len)
{
    (void)base;

    *buf = psoc_eth_rx_buf[psoc_eth.rx_buf_idx];
    *len = BSP_ETH_RX_BUF_SIZE;
    psoc_eth.rx_buf_idx = (psoc_eth.rx_buf_idx + 1U) % CY_ETH_DEFINE_TOTAL_BD_PER_RXQUEUE;
}

/**
 * @brief TX complete callback (called in ISR context)
 */
static void psoc_eth_tx_complete_cb(ETH_Type *base, uint8_t queue)
{
    (void)base;
    (void)queue;
}

/**
 * @brief TX error callback (called in ISR context)
 */
static void psoc_eth_tx_error_cb(ETH_Type *base, uint8_t queue)
{
    (void)base;
    (void)queue;
}

/**
 * @brief Detect PHY address by scanning
 */
static rt_uint8_t psoc_phy_detect(ETH_Type *base)
{
    for (rt_uint8_t addr = 0; addr < 32U; addr++)
    {
        uint32_t id1 = Cy_ETHIF_PhyRegRead(base, PHY_REG_PHYID1, addr);
        uint32_t id2 = Cy_ETHIF_PhyRegRead(base, PHY_REG_PHYID2, addr);

        if (id1 != 0xFFFFU && id1 != 0x0000U && id2 != 0xFFFFU && id2 != 0x0000U)
        {
            rt_kprintf("PHY detected at addr %u, ID: 0x%04X:0x%04X\n", addr, id1, id2);
            return addr;
        }
    }

    rt_kprintf("PHY not detected, using default addr %u\n", BSP_ETH_PHY_ADDR);
    return BSP_ETH_PHY_ADDR;
}

/* Additional PHY register definitions for LAN8710AI */
#define PHY_REG_ANAR            0x04U /* Auto-Negotiation Advertisement Register */
#define PHY_REG_ANLPAR          0x05U /* Auto-Negotiation Link Partner Ability Register */
#define PHY_REG_ANER            0x06U /* Auto-Negotiation Expansion Register */
#define PHY_REG_SPECIAL         0x1FU /* Special Control/Status Register (LAN8710AI specific) */

#define PHY_BMCR_SPEED_100      (1U << 13)
#define PHY_BMCR_FULL_DUPLEX    (1U << 8)

/* LAN8710AI Special Control/Status Register bits */
#define PHY_SPECIAL_AUTODONE    (1U << 12) /* Auto-negotiation done */
#define PHY_SPECIAL_SPEED_MASK  (0x001CU)  /* Speed indication */
#define PHY_SPECIAL_SPEED_10HD  (0x0004U)  /* 10 Mbps Half-duplex */
#define PHY_SPECIAL_SPEED_10FD  (0x0014U)  /* 10 Mbps Full-duplex */
#define PHY_SPECIAL_SPEED_100HD (0x0008U)  /* 100 Mbps Half-duplex */
#define PHY_SPECIAL_SPEED_100FD (0x0018U)  /* 100 Mbps Full-duplex */

/**
 * @brief Initialize PHY and wait for auto-negotiation
 * @return RT_EOK on success, -RT_ERROR on failure
 */
static rt_err_t psoc_phy_init(ETH_Type *base)
{
    uint32_t reg;
    int timeout;

    psoc_eth.phy_addr = psoc_phy_detect(base);

    /* Software reset PHY */
    (void)Cy_ETHIF_PhyRegWrite(base, PHY_REG_BMCR, PHY_BMCR_RESET, psoc_eth.phy_addr);

    /* Wait for reset to complete (bit 15 self-clears) */
    timeout = 50;
    while (timeout-- > 0)
    {
        rt_thread_mdelay(50);
        reg = Cy_ETHIF_PhyRegRead(base, PHY_REG_BMCR, psoc_eth.phy_addr);
        if ((reg & PHY_BMCR_RESET) == 0)
        {
            break;
        }
    }
    if (timeout <= 0)
    {
        rt_kprintf("[ETH] PHY reset timeout\n");
    }

    /* Wait additional time for PHY to be ready */
    rt_thread_mdelay(100);

    /* Configure auto-negotiation advertisement - all capabilities */
    reg = (1U << 8)  /* 100BASE-TX Full Duplex */
          | (1U << 7)  /* 100BASE-TX Half Duplex */
          | (1U << 6)  /* 10BASE-T Full Duplex */
          | (1U << 5)  /* 10BASE-T Half Duplex */
          | (1U << 0); /* Selector field: 802.3 */
    (void)Cy_ETHIF_PhyRegWrite(base, PHY_REG_ANAR, (uint16_t)reg, psoc_eth.phy_addr);

    /* Enable and restart auto-negotiation */
    reg = Cy_ETHIF_PhyRegRead(base, PHY_REG_BMCR, psoc_eth.phy_addr);
    reg |= PHY_BMCR_AN_ENABLE | PHY_BMCR_RESTART_AN;
    (void)Cy_ETHIF_PhyRegWrite(base, PHY_REG_BMCR, (uint16_t)reg, psoc_eth.phy_addr);

    /* Wait for auto-negotiation to complete */
    timeout = 50; /* 5 seconds max */
    while (timeout-- > 0)
    {
        rt_thread_mdelay(100);
        reg = Cy_ETHIF_PhyRegRead(base, PHY_REG_BMSR, psoc_eth.phy_addr);
        if (reg & PHY_BMSR_AN_COMPLETE)
        {
            break;
        }
    }
    if (timeout <= 0)
    {
        rt_kprintf("[ETH] PHY auto-negotiation timeout\n");
    }

    /* Read negotiated speed from Special Control/Status Register (LAN8710AI) */
    reg = Cy_ETHIF_PhyRegRead(base, PHY_REG_SPECIAL, psoc_eth.phy_addr);

    uint32_t speed_bits = reg & PHY_SPECIAL_SPEED_MASK;
    const char *speed_str = "Unknown";
    switch (speed_bits)
    {
    case PHY_SPECIAL_SPEED_100FD:
        speed_str = "100Mbps Full";
        break;
    case PHY_SPECIAL_SPEED_100HD:
        speed_str = "100Mbps Half";
        break;
    case PHY_SPECIAL_SPEED_10FD:
        speed_str = "10Mbps Full";
        break;
    case PHY_SPECIAL_SPEED_10HD:
        speed_str = "10Mbps Half";
        break;
    }
    rt_kprintf("[ETH] PHY negotiated: %s\n", speed_str);

    return RT_EOK;
}

/**
 * @brief Check if PHY link is up
 */
static rt_bool_t psoc_phy_is_link_up(ETH_Type *base)
{
    uint32_t bmsr = Cy_ETHIF_PhyRegRead(base, PHY_REG_BMSR, psoc_eth.phy_addr);
    return ((bmsr & PHY_BMSR_LINK) != 0U) ? RT_TRUE : RT_FALSE;
}

/**
 * @brief PHY link status polling timer callback
 */
static void psoc_phy_poll_link(void *parameter)
{
    rt_bool_t link_up;

    (void)parameter;

    link_up = psoc_phy_is_link_up(ETH0);
    if (link_up != psoc_eth.link_up)
    {
        psoc_eth.link_up = link_up;
        rt_kprintf("[ETH] ETH link %s\n", link_up ? "UP" : "DOWN");
        eth_device_linkchange(&psoc_eth.parent, link_up);
    }
}

/**
 * @brief Hardware initialization
 *
 * Following Infineon's official initialization sequence:
 * 1. Configure GPIO pins and clocks
 * 2. Initialize MDIO interface first (for PHY communication)
 * 3. Initialize and configure PHY with auto-negotiation
 * 4. Initialize full MAC with matching speed settings
 * 5. Register callbacks and enable interrupts
 */
static rt_err_t psoc_eth_hw_init(void)
{
    cy_en_ethif_status_t status;
    cy_stc_ethif_filter_config_t filter_cfg;

    psoc_eth_pin_init();
    psoc_eth_clock_init();
    psoc_eth_rx_pool_init();

    /*
     * Wrapper configuration for RMII 100Mbps
     * Keep this aligned with Infineon ECM reference (eth_internal.c):
     * - RMII 100M uses divider = 1
     */
    psoc_eth_wrapper_cfg.stcInterfaceSel = CY_ETHIF_CTL_RMII_100;
    psoc_eth_wrapper_cfg.bRefClockSource = CY_ETHIF_EXTERNAL_HSIO;
    psoc_eth_wrapper_cfg.u8RefClkDiv = 1U;

    /* MAC configuration */
    rt_memset(&psoc_eth_mac_cfg, 0, sizeof(psoc_eth_mac_cfg));
    psoc_eth_mac_cfg.bintrEnable = true;
    psoc_eth_mac_cfg.dmaDataBurstLen = CY_ETHIF_DMA_DBUR_LEN_4;
    psoc_eth_mac_cfg.u8dmaCfgFlags = CY_ETHIF_CFG_DMA_FRCE_TX_BRST; /* Force TX burst like official example */
    /* For PSOC E84, source clock is 200 MHz, MDC must be less than 2.5MHz: 200/96 = 2.08MHz */
    psoc_eth_mac_cfg.mdcPclkDiv = CY_ETHIF_MDC_DIV_BY_96;
    psoc_eth_mac_cfg.u8rxLenErrDisc = 0U;
    psoc_eth_mac_cfg.u8disCopyPause = 0U;
    psoc_eth_mac_cfg.u8chkSumOffEn = 0U;
    psoc_eth_mac_cfg.u8rx1536ByteEn = 1U;
    psoc_eth_mac_cfg.u8rxJumboFrEn = 0U;
    psoc_eth_mac_cfg.u8enRxBadPreamble = 1U; /* Match official example */
    psoc_eth_mac_cfg.u8ignoreIpgRxEr = 0U;
    psoc_eth_mac_cfg.u8storeUdpTcpOffset = 0U;
    psoc_eth_mac_cfg.u8aw2wMaxPipeline = 2U;
    psoc_eth_mac_cfg.u8ar2rMaxPipeline = 2U;
    psoc_eth_mac_cfg.u8pfcMultiQuantum = 0U;
    psoc_eth_mac_cfg.pstcWrapperConfig = &psoc_eth_wrapper_cfg;
    psoc_eth_mac_cfg.pstcTSUConfig = RT_NULL;

    /* Enable only TX/RX queue 0 */
    psoc_eth_mac_cfg.btxq0enable = true;
    psoc_eth_mac_cfg.btxq1enable = false;
    psoc_eth_mac_cfg.btxq2enable = false;
    psoc_eth_mac_cfg.brxq0enable = true;
    psoc_eth_mac_cfg.brxq1enable = false;
    psoc_eth_mac_cfg.brxq2enable = false;

    /* Set RX buffer pool */
    psoc_eth_mac_cfg.pRxQbuffPool[0] = &psoc_eth_rx_pool;
    psoc_eth_mac_cfg.pRxQbuffPool[1] = RT_NULL;

    rt_kprintf("[ETH] pRxQbuffPool[0]: 0x%08X\n", (uint32_t)psoc_eth_mac_cfg.pRxQbuffPool[0]);
    rt_kprintf("[ETH] RX pool[0]: 0x%08X\n", (uint32_t)psoc_eth_rx_pool[0]);

    /* Initialize MDIO interface first (for PHY communication) */
    status = Cy_ETHIF_MdioInit(ETH0, &psoc_eth_mac_cfg);
    if (status != CY_ETHIF_SUCCESS)
    {
        rt_kprintf("[ETH] MDIO init failed: %d\n", status);
        return -RT_ERROR;
    }

    /* Initialize PHY and run auto-negotiation */
    psoc_phy_init(ETH0);

    /* Check if link is up after PHY init */
    psoc_eth.link_up = psoc_phy_is_link_up(ETH0);

    /* Interrupt configuration - keep essential events */
    rt_memset(&psoc_eth_intr_cfg, 0, sizeof(psoc_eth_intr_cfg));
    psoc_eth_intr_cfg.brx_complete = true;
    psoc_eth_intr_cfg.brx_overrun = true;
    psoc_eth_intr_cfg.btx_complete = true;
    psoc_eth_intr_cfg.btx_underrun = true;
    psoc_eth_intr_cfg.btx_retry_ex_late_coll = true;

    /* Callback configuration - must be done BEFORE Cy_ETHIF_Init */
    rt_memset(&psoc_eth_cb, 0, sizeof(psoc_eth_cb));
    psoc_eth_cb.rxframecb = psoc_eth_rx_frame_cb;
    psoc_eth_cb.rxgetbuff = psoc_eth_rx_getbuff_cb;
    psoc_eth_cb.txcompletecb = psoc_eth_tx_complete_cb;
    psoc_eth_cb.txerrorcb = psoc_eth_tx_error_cb;
    psoc_eth_cb.tsuSecondInccb = RT_NULL;

    /* Initialize full ETHIF (MAC + DMA) */
    status = Cy_ETHIF_Init(ETH0, &psoc_eth_mac_cfg, &psoc_eth_intr_cfg);
    if (status != CY_ETHIF_SUCCESS)
    {
        rt_kprintf("[ETH] ETHIF init failed: %d\n", status);
        return -RT_ERROR;
    }

    /* Register callbacks AFTER Cy_ETHIF_Init */
    (void)Cy_ETHIF_RegisterCallbacks(ETH0, &psoc_eth_cb);

    /* Configure MAC address filter */
    filter_cfg.typeFilter = CY_ETHIF_FILTER_TYPE_DESTINATION;
    filter_cfg.ignoreBytes = 0U;
    rt_memcpy(filter_cfg.filterAddr.byte, psoc_eth.dev_addr, sizeof(psoc_eth.dev_addr));
    (void)Cy_ETHIF_SetFilterAddress(ETH0, CY_ETHIF_FILTER_NUM_1, &filter_cfg);

    /* Initialize interrupts */
    psoc_eth_intr_init();

    return RT_EOK;
}

/* ======================== Device Interface ======================== */

/**
 * @brief Device init callback
 */
static rt_err_t psoc_eth_init(rt_device_t dev)
{
    (void)dev;
    return psoc_eth_hw_init();
}

/**
 * @brief Device open callback
 */
static rt_err_t psoc_eth_open(rt_device_t dev, rt_uint16_t oflag)
{
    (void)dev;
    (void)oflag;
    return RT_EOK;
}

/**
 * @brief Device close callback
 */
static rt_err_t psoc_eth_close(rt_device_t dev)
{
    (void)dev;
    return RT_EOK;
}

/**
 * @brief Device read callback (not used for ethernet)
 */
static rt_size_t psoc_eth_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    (void)dev;
    (void)pos;
    (void)buffer;
    (void)size;

    rt_set_errno(-RT_ENOSYS);
    return 0;
}

/**
 * @brief Device write callback (not used for ethernet)
 */
static rt_size_t psoc_eth_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    (void)dev;
    (void)pos;
    (void)buffer;
    (void)size;

    rt_set_errno(-RT_ENOSYS);
    return 0;
}

/**
 * @brief Device control callback
 */
static rt_err_t psoc_eth_control(rt_device_t dev, int cmd, void *args)
{
    (void)dev;

    switch (cmd)
    {
    case NIOCTL_GADDR:
        if (args != RT_NULL)
        {
            rt_memcpy(args, psoc_eth.dev_addr, sizeof(psoc_eth.dev_addr));
        }
        else
        {
            return -RT_ERROR;
        }
        break;

    default:
        break;
    }

    return RT_EOK;
}

/**
 * @brief Ethernet RX callback - called by erx thread to get received packet
 *        This function is called in a loop until it returns RT_NULL
 */
static struct pbuf *psoc_eth_rx(rt_device_t dev)
{
    struct pbuf *p = RT_NULL;
    struct eth_rx_frame *frame;

    (void)dev;

    frame = rx_queue_pop();
    if (frame != RT_NULL && frame->len > 0)
    {
        /* Allocate pbuf */
        p = pbuf_alloc(PBUF_RAW, (u16_t)frame->len, PBUF_RAM);
        if (p != RT_NULL)
        {
            /* Copy data to pbuf */
            pbuf_take(p, frame->data, (u16_t)frame->len);
        }
    }

    return p;
}

/**
 * @brief Ethernet TX callback - called to transmit packet
 */
static rt_err_t psoc_eth_tx(rt_device_t dev, struct pbuf *p)
{
    cy_en_ethif_status_t status;

    (void)dev;

    if (p == RT_NULL || p->tot_len == 0)
    {
        return -RT_ERROR;
    }

    if (p->tot_len > BSP_ETH_TX_BUF_SIZE)
    {
        return -RT_ERROR;
    }

    /* Check link status before sending */
    if (!psoc_eth.link_up)
    {
        return -RT_ERROR;
    }

    /* Take TX lock */
    rt_mutex_take(psoc_eth.tx_lock, RT_WAITING_FOREVER);

    /* Copy pbuf chain to TX buffer */
    pbuf_copy_partial(p, psoc_eth_tx_buf, p->tot_len, 0);

    /* Clean cache for TX data */
    SCB_CleanDCache_by_Addr((void *)psoc_eth_tx_buf, (int32_t)p->tot_len);

    /* Transmit frame */
    status = Cy_ETHIF_TransmitFrame(ETH0, psoc_eth_tx_buf, (uint16_t)p->tot_len, BSP_ETH_QUEUE_ID, true);

    rt_mutex_release(psoc_eth.tx_lock);

    if (status != CY_ETHIF_SUCCESS)
    {
        rt_kprintf("[ETH] TX failed: status=%d\n", status);
        return -RT_ERROR;
    }

    return RT_EOK;
}

/* ======================== Interrupt Handlers ======================== */

void eth_interrupt_eth_0_IRQHandler(void)
{
    rt_interrupt_enter();
    Cy_ETHIF_DecodeEvent(ETH0);
    rt_interrupt_leave();
}

void eth_interrupt_eth_1_IRQHandler(void)
{
    rt_interrupt_enter();
    Cy_ETHIF_DecodeEvent(ETH0);
    rt_interrupt_leave();
}

void eth_interrupt_eth_2_IRQHandler(void)
{
    rt_interrupt_enter();
    Cy_ETHIF_DecodeEvent(ETH0);
    rt_interrupt_leave();
}

/* ======================== Driver Init ======================== */

/**
 * @brief Initialize ethernet driver
 */
rt_err_t drv_eth_init(void)
{
    rt_err_t ret;

    /* Initialize device state */
    rt_memset(&psoc_eth, 0, sizeof(psoc_eth));
    psoc_eth.link_up = RT_FALSE;
    psoc_eth.rx_queue_head = 0;
    psoc_eth.rx_queue_tail = 0;
    psoc_eth.rx_buf_idx = 0;

    /* Set MAC address */
    psoc_eth_set_default_mac();

    /* Create TX mutex */
    psoc_eth.tx_lock = rt_mutex_create("ethtx", RT_IPC_FLAG_PRIO);
    if (psoc_eth.tx_lock == RT_NULL)
    {
        rt_kprintf("[ETH] Failed to create TX mutex\n");
        return -RT_ERROR;
    }

    /* Set device callbacks */
    psoc_eth.parent.parent.init = psoc_eth_init;
    psoc_eth.parent.parent.open = psoc_eth_open;
    psoc_eth.parent.parent.close = psoc_eth_close;
    psoc_eth.parent.parent.read = psoc_eth_read;
    psoc_eth.parent.parent.write = psoc_eth_write;
    psoc_eth.parent.parent.control = psoc_eth_control;

    /* Set ethernet callbacks */
    psoc_eth.parent.eth_rx = psoc_eth_rx;
    psoc_eth.parent.eth_tx = psoc_eth_tx;

    /* Register ethernet device */
    ret = eth_device_init(&psoc_eth.parent, "e0");
    if (ret != RT_EOK)
    {
        rt_kprintf("[ETH] eth_device_init failed: %d\n", ret);
        rt_mutex_delete(psoc_eth.tx_lock);
        return ret;
    }

    rt_kprintf("ETH device registered: e0, MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
               psoc_eth.dev_addr[0],
               psoc_eth.dev_addr[1],
               psoc_eth.dev_addr[2],
               psoc_eth.dev_addr[3],
               psoc_eth.dev_addr[4],
               psoc_eth.dev_addr[5]);

    /* Notify link status after device is fully registered */
    if (psoc_eth.link_up)
    {
        eth_device_linkchange(&psoc_eth.parent, RT_TRUE);
    }

#ifndef PHY_USING_INTERRUPT_MODE
    /* Create PHY link polling timer */
    psoc_eth.poll_link_timer = rt_timer_create("phylnk",
                               psoc_phy_poll_link,
                               RT_NULL,
                               RT_TICK_PER_SECOND,
                               RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_SOFT_TIMER);
    if (psoc_eth.poll_link_timer != RT_NULL)
    {
        rt_timer_start(psoc_eth.poll_link_timer);
    }
#endif

    return RT_EOK;
}

/* ======================== Debug Shell Commands ======================== */

#if defined(RT_USING_FINSH) && (ETH_DRV_DEBUG)
#include <finsh.h>

/**
 * @brief Check NVIC pending status for ETH IRQs
 */
static int eth_nvic(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    rt_kprintf("===== NVIC Status for ETH IRQs =====\n");
    rt_kprintf("IRQ %d: Enabled=%d, Pending=%d\n",
               (int)intr_cfg_0.intrSrc,
               NVIC_GetEnableIRQ(intr_cfg_0.intrSrc),
               NVIC_GetPendingIRQ(intr_cfg_0.intrSrc));
    rt_kprintf("IRQ %d: Enabled=%d, Pending=%d\n",
               (int)intr_cfg_1.intrSrc,
               NVIC_GetEnableIRQ(intr_cfg_1.intrSrc),
               NVIC_GetPendingIRQ(intr_cfg_1.intrSrc));
    rt_kprintf("IRQ %d: Enabled=%d, Pending=%d\n",
               (int)intr_cfg_2.intrSrc,
               NVIC_GetEnableIRQ(intr_cfg_2.intrSrc),
               NVIC_GetPendingIRQ(intr_cfg_2.intrSrc));
    rt_kprintf("=====================================\n");

    return 0;
}
MSH_CMD_EXPORT(eth_nvic, Check NVIC status for ETH IRQs);

/**
 * @brief Dump ETH MAC registers for debugging
 */
static int eth_regs(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    rt_kprintf("===== ETH0 MAC Registers =====\n");
    rt_kprintf("NETWORK_CONTROL:      0x%08lX\n", ETH0->NETWORK_CONTROL);
    rt_kprintf("NETWORK_CONFIG:       0x%08lX\n", ETH0->NETWORK_CONFIG);
    rt_kprintf("NETWORK_STATUS:       0x%08lX\n", ETH0->NETWORK_STATUS);
    rt_kprintf("TRANSMIT_STATUS:      0x%08lX\n", ETH0->TRANSMIT_STATUS);
    rt_kprintf("RECEIVE_STATUS:       0x%08lX\n", ETH0->RECEIVE_STATUS);
    rt_kprintf("  RX buf avail: %lu\n", (ETH0->RECEIVE_STATUS >> 0) & 0x1);
    rt_kprintf("  RX frame rx: %lu\n", (ETH0->RECEIVE_STATUS >> 1) & 0x1);
    rt_kprintf("INT_STATUS:           0x%08lX\n", ETH0->INT_STATUS);
    rt_kprintf("  RX complete: %lu\n", (ETH0->INT_STATUS >> 1) & 0x1);
    rt_kprintf("INT_MASK:             0x%08lX\n", ETH0->INT_MASK);
    rt_kprintf("INT_ENABLE:           0x%08lX\n", ETH0->INT_ENABLE);
    rt_kprintf("INT_DISABLE:          0x%08lX\n", ETH0->INT_DISABLE);
    rt_kprintf("PHY_MANAGEMENT:       0x%08lX\n", ETH0->PHY_MANAGEMENT);
    rt_kprintf("TX_QBAR:              0x%08lX\n", ETH0->TRANSMIT_Q_PTR);
    rt_kprintf("RX_QBAR:              0x%08lX\n", ETH0->RECEIVE_Q_PTR);
    rt_kprintf("RX queue ptr:        0x%08lX\n", ETH0->RECEIVE_Q_PTR);
    rt_kprintf("DMA_CONFIG:           0x%08lX\n", ETH0->DMA_CONFIG);
    rt_kprintf("CTL:                  0x%08lX\n", ETH0->CTL);
    rt_kprintf("==============================\n");

    /* Check specific bits */
    rt_kprintf("TX Enable: %s\n", (ETH0->NETWORK_CONTROL & (1UL << 3)) ? "YES" : "NO");
    rt_kprintf("RX Enable: %s\n", (ETH0->NETWORK_CONTROL & (1UL << 2)) ? "YES" : "NO");
    rt_kprintf("ETH Mode (CTL): %lu (0=MII, 3=RMII)\n", (ETH0->CTL >> 0) & 0x3);
    rt_kprintf("REFCLK Source (CTL): %lu (0=HSIO, 1=PLL)\n", (ETH0->CTL >> 2) & 0x1);
    rt_kprintf("REFCLK DIV (CTL): %lu\n", (ETH0->CTL >> 8) & 0xFF);

    return 0;
}
MSH_CMD_EXPORT(eth_regs, Dump ETH MAC registers);

#endif /* RT_USING_FINSH && ETH_DRV_DEBUG */

#ifndef __R8152__H
#define __R8152__H

#include "usbh_def.h"


#define PKTSIZE                 1522
#define PKTSIZE_ALIGN           1536

#define EINVAL                  22
// #define ETIMEDOUT               110

#define ETH_ALEN                6

#define R8152_VERSION_NUM       7

#define CR_RST                  0x10


#define ADVERTISE_PAUSE_CAP	    0x0400	/* Try for pause               */
#define ADVERTISE_PAUSE_ASYM    0x0800	/* Try for asymetric pause     */


/* Basic mode control register. */
#define BMCR_RESV		0x003f	/* Unused...		       */
#define BMCR_SPEED1000		0x0040	/* MSB of Speed (1000)	       */
#define BMCR_CTST		0x0080	/* Collision test	       */
#define BMCR_FULLDPLX		0x0100	/* Full duplex		       */
#define BMCR_ANRESTART		0x0200	/* Auto negotiation restart    */
#define BMCR_ISOLATE		0x0400	/* Disconnect DP83840 from MII */
#define BMCR_PDOWN		0x0800	/* Powerdown the DP83840       */
#define BMCR_ANENABLE		0x1000	/* Enable auto negotiation     */
#define BMCR_SPEED100		0x2000	/* Select 100Mbps	       */
#define BMCR_LOOPBACK		0x4000	/* TXD loopback bits	       */
#define BMCR_RESET		0x8000	/* Reset the DP83840	       */

/* Basic mode status register. */
#define BMSR_ERCAP		0x0001	/* Ext-reg capability	       */
#define BMSR_JCD		0x0002	/* Jabber detected	       */
#define BMSR_LSTATUS		0x0004	/* Link status		       */
#define BMSR_ANEGCAPABLE	0x0008	/* Able to do auto-negotiation */
#define BMSR_RFAULT		0x0010	/* Remote fault detected       */
#define BMSR_ANEGCOMPLETE	0x0020	/* Auto-negotiation complete   */
#define BMSR_RESV		0x00c0	/* Unused...		       */
#define BMSR_ESTATEN		0x0100	/* Extended Status in R15 */
#define BMSR_100HALF2		0x0200	/* Can do 100BASE-T2 HDX */
#define BMSR_100FULL2		0x0400	/* Can do 100BASE-T2 FDX */
#define BMSR_10HALF		0x0800	/* Can do 10mbps, half-duplex  */
#define BMSR_10FULL		0x1000	/* Can do 10mbps, full-duplex  */
#define BMSR_100HALF		0x2000	/* Can do 100mbps, half-duplex */
#define BMSR_100FULL		0x4000	/* Can do 100mbps, full-duplex */
#define BMSR_100BASE4		0x8000	/* Can do 100mbps, 4k packets  */

/* Advertisement control register. */
#define ADVERTISE_SLCT		0x001f	/* Selector bits	       */
#define ADVERTISE_CSMA		0x0001	/* Only selector supported     */
#define ADVERTISE_10HALF	0x0020	/* Try for 10mbps half-duplex  */
#define ADVERTISE_1000XFULL	0x0020	/* Try for 1000BASE-X full-duplex */
#define ADVERTISE_10FULL	0x0040	/* Try for 10mbps full-duplex  */
#define ADVERTISE_1000XHALF	0x0040	/* Try for 1000BASE-X half-duplex */
#define ADVERTISE_100HALF	0x0080	/* Try for 100mbps half-duplex */
#define ADVERTISE_1000XPAUSE	0x0080	/* Try for 1000BASE-X pause    */
#define ADVERTISE_100FULL	0x0100	/* Try for 100mbps full-duplex */
#define ADVERTISE_1000XPSE_ASYM 0x0100	/* Try for 1000BASE-X asym pause */
#define ADVERTISE_100BASE4	0x0200	/* Try for 100mbps 4k packets  */
#define ADVERTISE_PAUSE_CAP	0x0400	/* Try for pause	       */
#define ADVERTISE_PAUSE_ASYM	0x0800	/* Try for asymetric pause     */
#define ADVERTISE_RESV		0x1000	/* Unused...		       */
#define ADVERTISE_RFAULT	0x2000	/* Say we can detect faults    */
#define ADVERTISE_LPACK		0x4000	/* Ack link partners response  */
#define ADVERTISE_NPAGE		0x8000	/* Next page bit	       */

#define ADVERTISE_FULL (ADVERTISE_100FULL | ADVERTISE_10FULL | \
			ADVERTISE_CSMA)
#define ADVERTISE_ALL (ADVERTISE_10HALF | ADVERTISE_10FULL | \
		       ADVERTISE_100HALF | ADVERTISE_100FULL)


/* 1000BASE-T Control register */
#define ADVERTISE_1000FULL	0x0200	/* Advertise 1000BASE-T full duplex */
#define ADVERTISE_1000HALF	0x0100	/* Advertise 1000BASE-T half duplex */

/* 1000BASE-T Status register */
#define LPA_1000LOCALRXOK	0x2000	/* Link partner local receiver status */
#define LPA_1000REMRXOK		0x1000	/* Link partner remote receiver status */
#define LPA_1000FULL		0x0800	/* Link partner 1000BASE-T full duplex */
#define LPA_1000HALF		0x0400	/* Link partner 1000BASE-T half duplex */



#define R8152_BASE_NAME		"r8152"

#define PLA_IDR			0xc000
#define PLA_RCR			0xc010
#define PLA_RMS			0xc016
#define PLA_RXFIFO_CTRL0	0xc0a0
#define PLA_RXFIFO_CTRL1	0xc0a4
#define PLA_RXFIFO_CTRL2	0xc0a8
#define PLA_DMY_REG0		0xc0b0
#define PLA_FMC			0xc0b4
#define PLA_CFG_WOL		0xc0b6
#define PLA_TEREDO_CFG		0xc0bc
#define PLA_MAR			0xcd00
#define PLA_BACKUP		0xd000
#define PAL_BDC_CR		0xd1a0
#define PLA_TEREDO_TIMER	0xd2cc
#define PLA_REALWOW_TIMER	0xd2e8
#define PLA_LEDSEL		0xdd90
#define PLA_LED_FEATURE		0xdd92
#define PLA_PHYAR		0xde00
#define PLA_BOOT_CTRL		0xe004
#define PLA_GPHY_INTR_IMR	0xe022
#define PLA_EEE_CR		0xe040
#define PLA_EEEP_CR		0xe080
#define PLA_MAC_PWR_CTRL	0xe0c0
#define PLA_MAC_PWR_CTRL2	0xe0ca
#define PLA_MAC_PWR_CTRL3	0xe0cc
#define PLA_MAC_PWR_CTRL4	0xe0ce
#define PLA_WDT6_CTRL		0xe428
#define PLA_TCR0		0xe610
#define PLA_TCR1		0xe612
#define PLA_MTPS		0xe615
#define PLA_TXFIFO_CTRL		0xe618
#define PLA_RSTTALLY		0xe800
#define BIST_CTRL		0xe810
#define PLA_CR			0xe813
#define PLA_CRWECR		0xe81c
#define PLA_CONFIG12		0xe81e	/* CONFIG1, CONFIG2 */
#define PLA_CONFIG34		0xe820	/* CONFIG3, CONFIG4 */
#define PLA_CONFIG5		0xe822
#define PLA_PHY_PWR		0xe84c
#define PLA_OOB_CTRL		0xe84f
#define PLA_CPCR		0xe854
#define PLA_MISC_0		0xe858
#define PLA_MISC_1		0xe85a
#define PLA_OCP_GPHY_BASE	0xe86c
#define PLA_TALLYCNT		0xe890
#define PLA_SFF_STS_7		0xe8de
#define PLA_PHYSTATUS		0xe908
#define PLA_BP_BA		0xfc26
#define PLA_BP_0		0xfc28
#define PLA_BP_1		0xfc2a
#define PLA_BP_2		0xfc2c
#define PLA_BP_3		0xfc2e
#define PLA_BP_4		0xfc30
#define PLA_BP_5		0xfc32
#define PLA_BP_6		0xfc34
#define PLA_BP_7		0xfc36
#define PLA_BP_EN		0xfc38

#define USB_USB2PHY		0xb41e
#define USB_SSPHYLINK2		0xb428
#define USB_U2P3_CTRL		0xb460
#define USB_CSR_DUMMY1		0xb464
#define USB_CSR_DUMMY2		0xb466
#define USB_DEV_STAT		0xb808
#define USB_CONNECT_TIMER	0xcbf8
#define USB_BURST_SIZE		0xcfc0
#define USB_USB_CTRL		0xd406
#define USB_PHY_CTRL		0xd408
#define USB_TX_AGG		0xd40a
#define USB_RX_BUF_TH		0xd40c
#define USB_USB_TIMER		0xd428
#define USB_RX_EARLY_TIMEOUT	0xd42c
#define USB_RX_EARLY_SIZE	0xd42e
#define USB_PM_CTRL_STATUS	0xd432
#define USB_TX_DMA		0xd434
#define USB_TOLERANCE		0xd490
#define USB_LPM_CTRL		0xd41a
#define USB_UPS_CTRL		0xd800
#define USB_MISC_0		0xd81a
#define USB_POWER_CUT		0xd80a
#define USB_AFE_CTRL2		0xd824
#define USB_WDT11_CTRL		0xe43c
#define USB_BP_BA		0xfc26
#define USB_BP_0		0xfc28
#define USB_BP_1		0xfc2a
#define USB_BP_2		0xfc2c
#define USB_BP_3		0xfc2e
#define USB_BP_4		0xfc30
#define USB_BP_5		0xfc32
#define USB_BP_6		0xfc34
#define USB_BP_7		0xfc36
#define USB_BP_EN		0xfc38

/* OCP Registers */
#define OCP_ALDPS_CONFIG	0x2010
#define OCP_EEE_CONFIG1		0x2080
#define OCP_EEE_CONFIG2		0x2092
#define OCP_EEE_CONFIG3		0x2094
#define OCP_BASE_MII		0xa400
#define OCP_EEE_AR		0xa41a
#define OCP_EEE_DATA		0xa41c
#define OCP_PHY_STATUS		0xa420
#define OCP_POWER_CFG		0xa430
#define OCP_EEE_CFG		0xa432
#define OCP_SRAM_ADDR		0xa436
#define OCP_SRAM_DATA		0xa438
#define OCP_DOWN_SPEED		0xa442
#define OCP_EEE_ABLE		0xa5c4
#define OCP_EEE_ADV		0xa5d0
#define OCP_EEE_LPABLE		0xa5d2
#define OCP_PHY_STATE		0xa708		/* nway state for 8153 */
#define OCP_ADC_CFG		0xbc06

/* SRAM Register */
#define SRAM_LPF_CFG		0x8012
#define SRAM_10M_AMP1		0x8080
#define SRAM_10M_AMP2		0x8082
#define SRAM_IMPEDANCE		0x8084

/* PLA_RCR */
#define RCR_AAP			0x00000001
#define RCR_APM			0x00000002
#define RCR_AM			0x00000004
#define RCR_AB			0x00000008
#define RCR_ACPT_ALL		(RCR_AAP | RCR_APM | RCR_AM | RCR_AB)

/* PLA_RXFIFO_CTRL0 */
#define RXFIFO_THR1_NORMAL	0x00080002
#define RXFIFO_THR1_OOB		0x01800003

/* PLA_RXFIFO_CTRL1 */
#define RXFIFO_THR2_FULL	0x00000060
#define RXFIFO_THR2_HIGH	0x00000038
#define RXFIFO_THR2_OOB		0x0000004a
#define RXFIFO_THR2_NORMAL	0x00a0

/* PLA_RXFIFO_CTRL2 */
#define RXFIFO_THR3_FULL	0x00000078
#define RXFIFO_THR3_HIGH	0x00000048
#define RXFIFO_THR3_OOB		0x0000005a
#define RXFIFO_THR3_NORMAL	0x0110

/* PLA_TXFIFO_CTRL */
#define TXFIFO_THR_NORMAL	0x00400008
#define TXFIFO_THR_NORMAL2	0x01000008

/* PLA_DMY_REG0 */
#define ECM_ALDPS		0x0002

/* PLA_FMC */
#define FMC_FCR_MCU_EN		0x0001

/* PLA_EEEP_CR */
#define EEEP_CR_EEEP_TX		0x0002

/* PLA_WDT6_CTRL */
#define WDT6_SET_MODE		0x0010

/* PLA_TCR0 */
#define TCR0_TX_EMPTY		0x0800
#define TCR0_AUTO_FIFO		0x0080

/* PLA_TCR1 */
#define VERSION_MASK		0x7cf0

/* PLA_MTPS */
#define MTPS_JUMBO		(12 * 1024 / 64)
#define MTPS_DEFAULT		(6 * 1024 / 64)

/* PLA_RSTTALLY */
#define TALLY_RESET		0x0001

/* PLA_CR */
#define PLA_CR_RST		0x10
#define PLA_CR_RE		0x08
#define PLA_CR_TE		0x04

/* PLA_BIST_CTRL */
#define BIST_CTRL_SW_RESET (0x10 << 24)

/* PLA_CRWECR */
#define CRWECR_NORAML		0x00
#define CRWECR_CONFIG		0xc0

/* PLA_OOB_CTRL */
#define NOW_IS_OOB		0x80
#define TXFIFO_EMPTY		0x20
#define RXFIFO_EMPTY		0x10
#define LINK_LIST_READY		0x02
#define DIS_MCU_CLROOB		0x01
#define FIFO_EMPTY		(TXFIFO_EMPTY | RXFIFO_EMPTY)

/* PLA_PHY_PWR */
#define PLA_PHY_PWR_LLR	(LINK_LIST_READY << 24)
#define PLA_PHY_PWR_TXEMP	(TXFIFO_EMPTY << 24)

/* PLA_MISC_1 */
#define RXDY_GATED_EN		0x0008

/* PLA_SFF_STS_7 */
#define RE_INIT_LL		0x8000
#define MCU_BORW_EN		0x4000

/* PLA_CPCR */
#define CPCR_RX_VLAN		0x0040

/* PLA_CFG_WOL */
#define MAGIC_EN		0x0001

/* PLA_TEREDO_CFG */
#define TEREDO_SEL		0x8000
#define TEREDO_WAKE_MASK	0x7f00
#define TEREDO_RS_EVENT_MASK	0x00fe
#define OOB_TEREDO_EN		0x0001

/* PAL_BDC_CR */
#define ALDPS_PROXY_MODE	0x0001

/* PLA_CONFIG34 */
#define LINK_ON_WAKE_EN		0x0010
#define LINK_OFF_WAKE_EN	0x0008

/* PLA_CONFIG5 */
#define BWF_EN			0x0040
#define MWF_EN			0x0020
#define UWF_EN			0x0010
#define LAN_WAKE_EN		0x0002

/* PLA_LED_FEATURE */
#define LED_MODE_MASK		0x0700

/* PLA_PHY_PWR */
#define TX_10M_IDLE_EN		0x0080
#define PFM_PWM_SWITCH		0x0040

/* PLA_MAC_PWR_CTRL */
#define D3_CLK_GATED_EN		0x00004000
#define MCU_CLK_RATIO		0x07010f07
#define MCU_CLK_RATIO_MASK	0x0f0f0f0f
#define ALDPS_SPDWN_RATIO	0x0f87

/* PLA_MAC_PWR_CTRL2 */
#define EEE_SPDWN_RATIO		0x8007

/* PLA_MAC_PWR_CTRL3 */
#define PKT_AVAIL_SPDWN_EN	0x0100
#define SUSPEND_SPDWN_EN	0x0004
#define U1U2_SPDWN_EN		0x0002
#define L1_SPDWN_EN		0x0001

/* PLA_MAC_PWR_CTRL4 */
#define PWRSAVE_SPDWN_EN	0x1000
#define RXDV_SPDWN_EN		0x0800
#define TX10MIDLE_EN		0x0100
#define TP100_SPDWN_EN		0x0020
#define TP500_SPDWN_EN		0x0010
#define TP1000_SPDWN_EN		0x0008
#define EEE_SPDWN_EN		0x0001

/* PLA_GPHY_INTR_IMR */
#define GPHY_STS_MSK		0x0001
#define SPEED_DOWN_MSK		0x0002
#define SPDWN_RXDV_MSK		0x0004
#define SPDWN_LINKCHG_MSK	0x0008

/* PLA_PHYAR */
#define PHYAR_FLAG		0x80000000

/* PLA_EEE_CR */
#define EEE_RX_EN		0x0001
#define EEE_TX_EN		0x0002

/* PLA_BOOT_CTRL */
#define AUTOLOAD_DONE		0x0002

/* USB_USB2PHY */
#define USB2PHY_SUSPEND		0x0001
#define USB2PHY_L1		0x0002

/* USB_SSPHYLINK2 */
#define pwd_dn_scale_mask	0x3ffe
#define pwd_dn_scale(x)		((x) << 1)

/* USB_CSR_DUMMY1 */
#define DYNAMIC_BURST		0x0001

/* USB_CSR_DUMMY2 */
#define EP4_FULL_FC		0x0001

/* USB_DEV_STAT */
#define STAT_SPEED_MASK		0x0006
#define STAT_SPEED_HIGH		0x0000
#define STAT_SPEED_FULL		0x0002

/* USB_TX_AGG */
#define TX_AGG_MAX_THRESHOLD	0x03

/* USB_RX_BUF_TH */
#define RX_THR_SUPPER		0x0c350180
#define RX_THR_HIGH		0x7a120180
#define RX_THR_SLOW		0xffff0180

/* USB_TX_DMA */
#define TEST_MODE_DISABLE	0x00000001
#define TX_SIZE_ADJUST1		0x00000100

/* USB_UPS_CTRL */
#define POWER_CUT		0x0100

/* USB_PM_CTRL_STATUS */
#define RESUME_INDICATE		0x0001

/* USB_USB_CTRL */
#define RX_AGG_DISABLE		0x0010
#define RX_ZERO_EN		0x0080

/* USB_U2P3_CTRL */
#define U2P3_ENABLE		0x0001

/* USB_POWER_CUT */
#define PWR_EN			0x0001
#define PHASE2_EN		0x0008

/* USB_MISC_0 */
#define PCUT_STATUS		0x0001

/* USB_RX_EARLY_TIMEOUT */
#define COALESCE_SUPER		 85000U
#define COALESCE_HIGH		250000U
#define COALESCE_SLOW		524280U

/* USB_WDT11_CTRL */
#define TIMER11_EN		0x0001

/* USB_LPM_CTRL */
/* bit 4 ~ 5: fifo empty boundary */
#define FIFO_EMPTY_1FB		0x30	/* 0x1fb * 64 = 32448 bytes */
/* bit 2 ~ 3: LMP timer */
#define LPM_TIMER_MASK		0x0c
#define LPM_TIMER_500MS		0x04	/* 500 ms */
#define LPM_TIMER_500US		0x0c	/* 500 us */
#define ROK_EXIT_LPM		0x02

/* USB_AFE_CTRL2 */
#define SEN_VAL_MASK		0xf800
#define SEN_VAL_NORMAL		0xa000
#define SEL_RXIDLE		0x0100

/* OCP_ALDPS_CONFIG */
#define ENPWRSAVE		0x8000
#define ENPDNPS			0x0200
#define LINKENA			0x0100
#define DIS_SDSAVE		0x0010

/* OCP_PHY_STATUS */
#define PHY_STAT_MASK		0x0007
#define PHY_STAT_LAN_ON		3
#define PHY_STAT_PWRDN		5

/* OCP_POWER_CFG */
#define EEE_CLKDIV_EN		0x8000
#define EN_ALDPS		0x0004
#define EN_10M_PLLOFF		0x0001

/* OCP_EEE_CONFIG1 */
#define RG_TXLPI_MSK_HFDUP	0x8000
#define RG_MATCLR_EN		0x4000
#define EEE_10_CAP		0x2000
#define EEE_NWAY_EN		0x1000
#define TX_QUIET_EN		0x0200
#define RX_QUIET_EN		0x0100
#define sd_rise_time_mask	0x0070
#define sd_rise_time(x)		(MIN((x), 7) << 4)	/* bit 4 ~ 6 */
#define RG_RXLPI_MSK_HFDUP	0x0008
#define SDFALLTIME		0x0007	/* bit 0 ~ 2 */

/* OCP_EEE_CONFIG2 */
#define RG_LPIHYS_NUM		0x7000	/* bit 12 ~ 15 */
#define RG_DACQUIET_EN		0x0400
#define RG_LDVQUIET_EN		0x0200
#define RG_CKRSEL		0x0020
#define RG_EEEPRG_EN		0x0010

/* OCP_EEE_CONFIG3 */
#define fast_snr_mask		0xff80
#define fast_snr(x)		(MIN((x), 0x1ff) << 7)	/* bit 7 ~ 15 */
#define RG_LFS_SEL		0x0060	/* bit 6 ~ 5 */
#define MSK_PH			0x0006	/* bit 0 ~ 3 */

/* OCP_EEE_AR */
/* bit[15:14] function */
#define FUN_ADDR		0x0000
#define FUN_DATA		0x4000
/* bit[4:0] device addr */

/* OCP_EEE_CFG */
#define CTAP_SHORT_EN		0x0040
#define EEE10_EN		0x0010

/* OCP_DOWN_SPEED */
#define EN_10M_BGOFF		0x0080

/* OCP_PHY_STATE */
#define TXDIS_STATE		0x01
#define ABD_STATE		0x02

/* OCP_ADC_CFG */
#define CKADSEL_L		0x0100
#define ADC_EN			0x0080
#define EN_EMI_L		0x0040

/* SRAM_LPF_CFG */
#define LPF_AUTO_TUNE		0x8000

/* SRAM_10M_AMP1 */
#define GDAC_IB_UPALL		0x0008

/* SRAM_10M_AMP2 */
#define AMP_DN			0x0200

/* SRAM_IMPEDANCE */
#define RX_DRIVING_MASK		0x6000

#define RTL8152_MAX_TX		4
#define RTL8152_MAX_RX		10
#define INTBUFSIZE		2
#define CRC_SIZE		4
#define TX_ALIGN		4
#define RX_ALIGN		8

#define INTR_LINK		0x0004

#define RTL8152_REQT_READ	0xc0
#define RTL8152_REQT_WRITE	0x40
#define RTL8152_REQ_GET_REGS	0x05
#define RTL8152_REQ_SET_REGS	0x05

#define BYTE_EN_DWORD		0xff
#define BYTE_EN_WORD		0x33
#define BYTE_EN_BYTE		0x11
#define BYTE_EN_SIX_BYTES	0x3f
#define BYTE_EN_START_MASK	0x0f
#define BYTE_EN_END_MASK	0xf0

#define RTL8152_ETH_FRAME_LEN	1518
#define RTL8152_AGG_BUF_SZ	2048

#define RTL8152_RMS		(RTL8152_ETH_FRAME_LEN + CRC_SIZE)
#define RTL8153_RMS		(RTL8152_ETH_FRAME_LEN + CRC_SIZE)
#define RTL8152_TX_TIMEOUT	(5 * HZ)

#define MCU_TYPE_PLA			0x0100
#define MCU_TYPE_USB			0x0000

/* The forced speed, 10Mb, 100Mb, gigabit. */
#define SPEED_10                10
#define SPEED_100               100
#define SPEED_1000              1000

#define SPEED_UNKNOWN           -1

/* Duplex, half or full. */
#define DUPLEX_HALF             0x00
#define DUPLEX_FULL             0x01
#define DUPLEX_UNKNOWN          0xff

/* Enable or disable autonegotiation. */
#define AUTONEG_DISABLE         0x00
#define AUTONEG_ENABLE          0x01

/* Generic MII registers. */
#define MII_BMCR                0x00    /* Basic mode control register */
#define MII_BMSR                0x01    /* Basic mode status register  */
#define MII_PHYSID1             0x02    /* PHYS ID 1                   */
#define MII_PHYSID2             0x03    /* PHYS ID 2                   */
#define MII_ADVERTISE           0x04    /* Advertisement control reg   */
#define MII_LPA                 0x05    /* Link partner ability reg    */
#define MII_EXPANSION           0x06    /* Expansion register          */
#define MII_CTRL1000            0x09    /* 1000BASE-T control          */
#define MII_STAT1000            0x0a    /* 1000BASE-T status           */
#define MII_MMD_CTRL            0x0d    /* MMD Access Control Register */
#define MII_MMD_DATA            0x0e    /* MMD Access Data Register */
#define MII_ESTATUS             0x0f    /* Extended Status             */
#define MII_DCOUNTER            0x12    /* Disconnect counter          */
#define MII_FCSCOUNTER          0x13    /* False carrier counter       */
#define MII_NWAYTEST            0x14    /* N-way auto-neg test reg     */
#define MII_RERRCOUNTER         0x15    /* Receive error counter       */
#define MII_SREVISION           0x16    /* Silicon revision            */
#define MII_RESV1               0x17    /* Reserved...                 */
#define MII_LBRERROR            0x18    /* Lpback, rx, bypass error    */
#define MII_PHYADDR             0x19    /* PHY address                 */
#define MII_RESV2               0x1a    /* Reserved...                 */
#define MII_TPISTATUS           0x1b    /* TPI status for 10mbps       */
#define MII_NCONFIG             0x1c    /* Network interface config    */

#define TIMEOUT_RESOLUTION	50
#define PHY_CONNECT_TIMEOUT     5000
#define USB_BULK_SEND_TIMEOUT   5000
#define USB_BULK_RECV_TIMEOUT   5000
#define R8152_WAIT_TIMEOUT	20


#define RD_CRC				((uint32_t)1 << 15)
#define RX_LEN_MASK			0x7fff

#define RD_UDP_CS			((uint32_t)1 << 23)
#define RD_TCP_CS			((uint32_t)1 << 22)
#define RD_IPV6_CS			((uint32_t)1 << 20)
#define RD_IPV4_CS			((uint32_t)1 << 19)

#define IPF				    ((uint32_t)1 << 23) /* IP checksum fail */
#define UDPF				((uint32_t)1 << 22) /* UDP checksum fail */
#define TCPF				((uint32_t)1 << 21) /* TCP checksum fail */
#define RX_VLAN_TAG			((uint32_t)1 << 16)





/* MDIO Manageable Devices (MMDs). */
#define MDIO_MMD_PMAPMD		1	/* Physical Medium Attachment/
					 * Physical Medium Dependent */
#define MDIO_MMD_WIS		2	/* WAN Interface Sublayer */
#define MDIO_MMD_PCS		3	/* Physical Coding Sublayer */
#define MDIO_MMD_PHYXS		4	/* PHY Extender Sublayer */
#define MDIO_MMD_DTEXS		5	/* DTE Extender Sublayer */
#define MDIO_MMD_TC		6	/* Transmission Convergence */
#define MDIO_MMD_AN		7	/* Auto-Negotiation */
#define MDIO_MMD_C22EXT		29	/* Clause 22 extension */
#define MDIO_MMD_VEND1		30	/* Vendor specific 1 */
#define MDIO_MMD_VEND2		31	/* Vendor specific 2 */

/* Generic MDIO registers. */
#define MDIO_CTRL1		MII_BMCR
#define MDIO_STAT1		MII_BMSR
#define MDIO_DEVID1		MII_PHYSID1
#define MDIO_DEVID2		MII_PHYSID2
#define MDIO_SPEED		4	/* Speed ability */
#define MDIO_DEVS1		5	/* Devices in package */
#define MDIO_DEVS2		6
#define MDIO_CTRL2		7	/* 10G control 2 */
#define MDIO_STAT2		8	/* 10G status 2 */
#define MDIO_PMA_TXDIS		9	/* 10G PMA/PMD transmit disable */
#define MDIO_PMA_RXDET		10	/* 10G PMA/PMD receive signal detect */
#define MDIO_PMA_EXTABLE	11	/* 10G PMA/PMD extended ability */
#define MDIO_PKGID1		14	/* Package identifier */
#define MDIO_PKGID2		15
#define MDIO_AN_ADVERTISE	16	/* AN advertising (base page) */
#define MDIO_AN_LPA		19	/* AN LP abilities (base page) */
#define MDIO_PCS_EEE_ABLE	20	/* EEE Capability register */
#define MDIO_PCS_EEE_WK_ERR	22	/* EEE wake error counter */
#define MDIO_PHYXS_LNSTAT	24	/* PHY XGXS lane state */
#define MDIO_AN_EEE_ADV		60	/* EEE advertisement */
#define MDIO_AN_EEE_LPABLE	61	/* EEE link partner ability */

/* Media-dependent registers. */
#define MDIO_PMA_10GBT_SWAPPOL	130	/* 10GBASE-T pair swap & polarity */
#define MDIO_PMA_10GBT_TXPWR	131	/* 10GBASE-T TX power control */
#define MDIO_PMA_10GBT_SNR	133	/* 10GBASE-T SNR margin, lane A.
					 * Lanes B-D are numbered 134-136. */
#define MDIO_PMA_10GBR_FECABLE	170	/* 10GBASE-R FEC ability */
#define MDIO_PCS_10GBX_STAT1	24	/* 10GBASE-X PCS status 1 */
#define MDIO_PCS_10GBRT_STAT1	32	/* 10GBASE-R/-T PCS status 1 */
#define MDIO_PCS_10GBRT_STAT2	33	/* 10GBASE-R/-T PCS status 2 */
#define MDIO_AN_10GBT_CTRL	32	/* 10GBASE-T auto-negotiation control */
#define MDIO_AN_10GBT_STAT	33	/* 10GBASE-T auto-negotiation status */

/* LASI (Link Alarm Status Interrupt) registers, defined by XENPAK MSA. */
#define MDIO_PMA_LASI_RXCTRL	0x9000	/* RX_ALARM control */
#define MDIO_PMA_LASI_TXCTRL	0x9001	/* TX_ALARM control */
#define MDIO_PMA_LASI_CTRL	0x9002	/* LASI control */
#define MDIO_PMA_LASI_RXSTAT	0x9003	/* RX_ALARM status */
#define MDIO_PMA_LASI_TXSTAT	0x9004	/* TX_ALARM status */
#define MDIO_PMA_LASI_STAT	0x9005	/* LASI status */

/* Control register 1. */
/* Enable extended speed selection */
#define MDIO_CTRL1_SPEEDSELEXT		(BMCR_SPEED1000 | BMCR_SPEED100)
/* All speed selection bits */
#define MDIO_CTRL1_SPEEDSEL		(MDIO_CTRL1_SPEEDSELEXT | 0x003c)
#define MDIO_CTRL1_FULLDPLX		BMCR_FULLDPLX
#define MDIO_CTRL1_LPOWER		BMCR_PDOWN
#define MDIO_CTRL1_RESET		BMCR_RESET
#define MDIO_PMA_CTRL1_LOOPBACK		0x0001
#define MDIO_PMA_CTRL1_SPEED1000	BMCR_SPEED1000
#define MDIO_PMA_CTRL1_SPEED100		BMCR_SPEED100
#define MDIO_PCS_CTRL1_LOOPBACK		BMCR_LOOPBACK
#define MDIO_PHYXS_CTRL1_LOOPBACK	BMCR_LOOPBACK
#define MDIO_AN_CTRL1_RESTART		BMCR_ANRESTART
#define MDIO_AN_CTRL1_ENABLE		BMCR_ANENABLE
#define MDIO_AN_CTRL1_XNP		0x2000	/* Enable extended next page */
#define MDIO_PCS_CTRL1_CLKSTOP_EN	0x400	/* Stop the clock during LPI */

/* 10 Gb/s */
#define MDIO_CTRL1_SPEED10G		(MDIO_CTRL1_SPEEDSELEXT | 0x00)
/* 10PASS-TS/2BASE-TL */
#define MDIO_CTRL1_SPEED10P2B		(MDIO_CTRL1_SPEEDSELEXT | 0x04)

/* Status register 1. */
#define MDIO_STAT1_LPOWERABLE		0x0002	/* Low-power ability */
#define MDIO_STAT1_LSTATUS		BMSR_LSTATUS
#define MDIO_STAT1_FAULT		0x0080	/* Fault */
#define MDIO_AN_STAT1_LPABLE		0x0001	/* Link partner AN ability */
#define MDIO_AN_STAT1_ABLE		BMSR_ANEGCAPABLE
#define MDIO_AN_STAT1_RFAULT		BMSR_RFAULT
#define MDIO_AN_STAT1_COMPLETE		BMSR_ANEGCOMPLETE
#define MDIO_AN_STAT1_PAGE		0x0040	/* Page received */
#define MDIO_AN_STAT1_XNP		0x0080	/* Extended next page status */

/* Speed register. */
#define MDIO_SPEED_10G			0x0001	/* 10G capable */
#define MDIO_PMA_SPEED_2B		0x0002	/* 2BASE-TL capable */
#define MDIO_PMA_SPEED_10P		0x0004	/* 10PASS-TS capable */
#define MDIO_PMA_SPEED_1000		0x0010	/* 1000M capable */
#define MDIO_PMA_SPEED_100		0x0020	/* 100M capable */
#define MDIO_PMA_SPEED_10		0x0040	/* 10M capable */
#define MDIO_PCS_SPEED_10P2B		0x0002	/* 10PASS-TS/2BASE-TL capable */

/* Device present registers. */
#define MDIO_DEVS_PRESENT(devad)	(1 << (devad))
#define MDIO_DEVS_PMAPMD		MDIO_DEVS_PRESENT(MDIO_MMD_PMAPMD)
#define MDIO_DEVS_WIS			MDIO_DEVS_PRESENT(MDIO_MMD_WIS)
#define MDIO_DEVS_PCS			MDIO_DEVS_PRESENT(MDIO_MMD_PCS)
#define MDIO_DEVS_PHYXS			MDIO_DEVS_PRESENT(MDIO_MMD_PHYXS)
#define MDIO_DEVS_DTEXS			MDIO_DEVS_PRESENT(MDIO_MMD_DTEXS)
#define MDIO_DEVS_TC			MDIO_DEVS_PRESENT(MDIO_MMD_TC)
#define MDIO_DEVS_AN			MDIO_DEVS_PRESENT(MDIO_MMD_AN)
#define MDIO_DEVS_C22EXT		MDIO_DEVS_PRESENT(MDIO_MMD_C22EXT)

/* Control register 2. */
#define MDIO_PMA_CTRL2_TYPE		0x000f	/* PMA/PMD type selection */
#define MDIO_PMA_CTRL2_10GBCX4		0x0000	/* 10GBASE-CX4 type */
#define MDIO_PMA_CTRL2_10GBEW		0x0001	/* 10GBASE-EW type */
#define MDIO_PMA_CTRL2_10GBLW		0x0002	/* 10GBASE-LW type */
#define MDIO_PMA_CTRL2_10GBSW		0x0003	/* 10GBASE-SW type */
#define MDIO_PMA_CTRL2_10GBLX4		0x0004	/* 10GBASE-LX4 type */
#define MDIO_PMA_CTRL2_10GBER		0x0005	/* 10GBASE-ER type */
#define MDIO_PMA_CTRL2_10GBLR		0x0006	/* 10GBASE-LR type */
#define MDIO_PMA_CTRL2_10GBSR		0x0007	/* 10GBASE-SR type */
#define MDIO_PMA_CTRL2_10GBLRM		0x0008	/* 10GBASE-LRM type */
#define MDIO_PMA_CTRL2_10GBT		0x0009	/* 10GBASE-T type */
#define MDIO_PMA_CTRL2_10GBKX4		0x000a	/* 10GBASE-KX4 type */
#define MDIO_PMA_CTRL2_10GBKR		0x000b	/* 10GBASE-KR type */
#define MDIO_PMA_CTRL2_1000BT		0x000c	/* 1000BASE-T type */
#define MDIO_PMA_CTRL2_1000BKX		0x000d	/* 1000BASE-KX type */
#define MDIO_PMA_CTRL2_100BTX		0x000e	/* 100BASE-TX type */
#define MDIO_PMA_CTRL2_10BT		0x000f	/* 10BASE-T type */
#define MDIO_PCS_CTRL2_TYPE		0x0003	/* PCS type selection */
#define MDIO_PCS_CTRL2_10GBR		0x0000	/* 10GBASE-R type */
#define MDIO_PCS_CTRL2_10GBX		0x0001	/* 10GBASE-X type */
#define MDIO_PCS_CTRL2_10GBW		0x0002	/* 10GBASE-W type */
#define MDIO_PCS_CTRL2_10GBT		0x0003	/* 10GBASE-T type */

/* Status register 2. */
#define MDIO_STAT2_RXFAULT		0x0400	/* Receive fault */
#define MDIO_STAT2_TXFAULT		0x0800	/* Transmit fault */
#define MDIO_STAT2_DEVPRST		0xc000	/* Device present */
#define MDIO_STAT2_DEVPRST_VAL		0x8000	/* Device present value */
#define MDIO_PMA_STAT2_LBABLE		0x0001	/* PMA loopback ability */
#define MDIO_PMA_STAT2_10GBEW		0x0002	/* 10GBASE-EW ability */
#define MDIO_PMA_STAT2_10GBLW		0x0004	/* 10GBASE-LW ability */
#define MDIO_PMA_STAT2_10GBSW		0x0008	/* 10GBASE-SW ability */
#define MDIO_PMA_STAT2_10GBLX4		0x0010	/* 10GBASE-LX4 ability */
#define MDIO_PMA_STAT2_10GBER		0x0020	/* 10GBASE-ER ability */
#define MDIO_PMA_STAT2_10GBLR		0x0040	/* 10GBASE-LR ability */
#define MDIO_PMA_STAT2_10GBSR		0x0080	/* 10GBASE-SR ability */
#define MDIO_PMD_STAT2_TXDISAB		0x0100	/* PMD TX disable ability */
#define MDIO_PMA_STAT2_EXTABLE		0x0200	/* Extended abilities */
#define MDIO_PMA_STAT2_RXFLTABLE	0x1000	/* Receive fault ability */
#define MDIO_PMA_STAT2_TXFLTABLE	0x2000	/* Transmit fault ability */
#define MDIO_PCS_STAT2_10GBR		0x0001	/* 10GBASE-R capable */
#define MDIO_PCS_STAT2_10GBX		0x0002	/* 10GBASE-X capable */
#define MDIO_PCS_STAT2_10GBW		0x0004	/* 10GBASE-W capable */
#define MDIO_PCS_STAT2_RXFLTABLE	0x1000	/* Receive fault ability */
#define MDIO_PCS_STAT2_TXFLTABLE	0x2000	/* Transmit fault ability */

/* Transmit disable register. */
#define MDIO_PMD_TXDIS_GLOBAL		0x0001	/* Global PMD TX disable */
#define MDIO_PMD_TXDIS_0		0x0002	/* PMD TX disable 0 */
#define MDIO_PMD_TXDIS_1		0x0004	/* PMD TX disable 1 */
#define MDIO_PMD_TXDIS_2		0x0008	/* PMD TX disable 2 */
#define MDIO_PMD_TXDIS_3		0x0010	/* PMD TX disable 3 */

/* Receive signal detect register. */
#define MDIO_PMD_RXDET_GLOBAL		0x0001	/* Global PMD RX signal detect */
#define MDIO_PMD_RXDET_0		0x0002	/* PMD RX signal detect 0 */
#define MDIO_PMD_RXDET_1		0x0004	/* PMD RX signal detect 1 */
#define MDIO_PMD_RXDET_2		0x0008	/* PMD RX signal detect 2 */
#define MDIO_PMD_RXDET_3		0x0010	/* PMD RX signal detect 3 */

/* Extended abilities register. */
#define MDIO_PMA_EXTABLE_10GCX4		0x0001	/* 10GBASE-CX4 ability */
#define MDIO_PMA_EXTABLE_10GBLRM	0x0002	/* 10GBASE-LRM ability */
#define MDIO_PMA_EXTABLE_10GBT		0x0004	/* 10GBASE-T ability */
#define MDIO_PMA_EXTABLE_10GBKX4	0x0008	/* 10GBASE-KX4 ability */
#define MDIO_PMA_EXTABLE_10GBKR		0x0010	/* 10GBASE-KR ability */
#define MDIO_PMA_EXTABLE_1000BT		0x0020	/* 1000BASE-T ability */
#define MDIO_PMA_EXTABLE_1000BKX	0x0040	/* 1000BASE-KX ability */
#define MDIO_PMA_EXTABLE_100BTX		0x0080	/* 100BASE-TX ability */
#define MDIO_PMA_EXTABLE_10BT		0x0100	/* 10BASE-T ability */

/* PHY XGXS lane state register. */
#define MDIO_PHYXS_LNSTAT_SYNC0		0x0001
#define MDIO_PHYXS_LNSTAT_SYNC1		0x0002
#define MDIO_PHYXS_LNSTAT_SYNC2		0x0004
#define MDIO_PHYXS_LNSTAT_SYNC3		0x0008
#define MDIO_PHYXS_LNSTAT_ALIGN		0x1000

/* PMA 10GBASE-T pair swap & polarity */
#define MDIO_PMA_10GBT_SWAPPOL_ABNX	0x0001	/* Pair A/B uncrossed */
#define MDIO_PMA_10GBT_SWAPPOL_CDNX	0x0002	/* Pair C/D uncrossed */
#define MDIO_PMA_10GBT_SWAPPOL_AREV	0x0100	/* Pair A polarity reversed */
#define MDIO_PMA_10GBT_SWAPPOL_BREV	0x0200	/* Pair B polarity reversed */
#define MDIO_PMA_10GBT_SWAPPOL_CREV	0x0400	/* Pair C polarity reversed */
#define MDIO_PMA_10GBT_SWAPPOL_DREV	0x0800	/* Pair D polarity reversed */

/* PMA 10GBASE-T TX power register. */
#define MDIO_PMA_10GBT_TXPWR_SHORT	0x0001	/* Short-reach mode */

/* PMA 10GBASE-T SNR registers. */
/* Value is SNR margin in dB, clamped to range [-127, 127], plus 0x8000. */
#define MDIO_PMA_10GBT_SNR_BIAS		0x8000
#define MDIO_PMA_10GBT_SNR_MAX		127

/* PMA 10GBASE-R FEC ability register. */
#define MDIO_PMA_10GBR_FECABLE_ABLE	0x0001	/* FEC ability */
#define MDIO_PMA_10GBR_FECABLE_ERRABLE	0x0002	/* FEC error indic. ability */

/* PCS 10GBASE-R/-T status register 1. */
#define MDIO_PCS_10GBRT_STAT1_BLKLK	0x0001	/* Block lock attained */

/* PCS 10GBASE-R/-T status register 2. */
#define MDIO_PCS_10GBRT_STAT2_ERR	0x00ff
#define MDIO_PCS_10GBRT_STAT2_BER	0x3f00

/* AN 10GBASE-T control register. */
#define MDIO_AN_10GBT_CTRL_ADV10G	0x1000	/* Advertise 10GBASE-T */

/* AN 10GBASE-T status register. */
#define MDIO_AN_10GBT_STAT_LPTRR	0x0200	/* LP training reset req. */
#define MDIO_AN_10GBT_STAT_LPLTABLE	0x0400	/* LP loop timing ability */
#define MDIO_AN_10GBT_STAT_LP10G	0x0800	/* LP is 10GBT capable */
#define MDIO_AN_10GBT_STAT_REMOK	0x1000	/* Remote OK */
#define MDIO_AN_10GBT_STAT_LOCOK	0x2000	/* Local OK */
#define MDIO_AN_10GBT_STAT_MS		0x4000	/* Master/slave config */
#define MDIO_AN_10GBT_STAT_MSFLT	0x8000	/* Master/slave config fault */

/* EEE Supported/Advertisement/LP Advertisement registers.
 *
 * EEE capability Register (3.20), Advertisement (7.60) and
 * Link partner ability (7.61) registers have and can use the same identical
 * bit masks.
 */
#define MDIO_AN_EEE_ADV_100TX	0x0002	/* Advertise 100TX EEE cap */
#define MDIO_AN_EEE_ADV_1000T	0x0004	/* Advertise 1000T EEE cap */
/* Note: the two defines above can be potentially used by the user-land
 * and cannot remove them now.
 * So, we define the new generic MDIO_EEE_100TX and MDIO_EEE_1000T macros
 * using the previous ones (that can be considered obsolete).
 */
#define MDIO_EEE_100TX		MDIO_AN_EEE_ADV_100TX	/* 100TX EEE cap */
#define MDIO_EEE_1000T		MDIO_AN_EEE_ADV_1000T	/* 1000T EEE cap */
#define MDIO_EEE_10GT		0x0008	/* 10GT EEE cap */
#define MDIO_EEE_1000KX		0x0010	/* 1000KX EEE cap */
#define MDIO_EEE_10GKX4		0x0020	/* 10G KX4 EEE cap */
#define MDIO_EEE_10GKR		0x0040	/* 10G KR EEE cap */

/* LASI RX_ALARM control/status registers. */
#define MDIO_PMA_LASI_RX_PHYXSLFLT	0x0001	/* PHY XS RX local fault */
#define MDIO_PMA_LASI_RX_PCSLFLT	0x0008	/* PCS RX local fault */
#define MDIO_PMA_LASI_RX_PMALFLT	0x0010	/* PMA/PMD RX local fault */
#define MDIO_PMA_LASI_RX_OPTICPOWERFLT	0x0020	/* RX optical power fault */
#define MDIO_PMA_LASI_RX_WISLFLT	0x0200	/* WIS local fault */

/* LASI TX_ALARM control/status registers. */
#define MDIO_PMA_LASI_TX_PHYXSLFLT	0x0001	/* PHY XS TX local fault */
#define MDIO_PMA_LASI_TX_PCSLFLT	0x0008	/* PCS TX local fault */
#define MDIO_PMA_LASI_TX_PMALFLT	0x0010	/* PMA/PMD TX local fault */
#define MDIO_PMA_LASI_TX_LASERPOWERFLT	0x0080	/* Laser output power fault */
#define MDIO_PMA_LASI_TX_LASERTEMPFLT	0x0100	/* Laser temperature fault */
#define MDIO_PMA_LASI_TX_LASERBICURRFLT	0x0200	/* Laser bias current fault */

/* LASI control/status registers. */
#define MDIO_PMA_LASI_LSALARM		0x0001	/* LS_ALARM enable/status */
#define MDIO_PMA_LASI_TXALARM		0x0002	/* TX_ALARM enable/status */
#define MDIO_PMA_LASI_RXALARM		0x0004	/* RX_ALARM enable/status */

/* Mapping between MDIO PRTAD/DEVAD and mii_ioctl_data::phy_id */

#define MDIO_PHY_ID_C45			0x8000
#define MDIO_PHY_ID_PRTAD		0x03e0
#define MDIO_PHY_ID_DEVAD		0x001f
#define MDIO_PHY_ID_C45_MASK						\
	(MDIO_PHY_ID_C45 | MDIO_PHY_ID_PRTAD | MDIO_PHY_ID_DEVAD)



typedef struct rx_desc {
	uint32_t opts1;
	uint32_t opts2;
	uint32_t opts3;
	uint32_t opts4;
	uint32_t opts5;
	uint32_t opts6;
} R8152_RX_DESC;

#define TX_FS			((uint32_t)1 << 31) /* First segment of a packet */
#define TX_LS			((uint32_t)1 << 30) /* Final segment of a packet */
#define LGSEND			((uint32_t)1 << 29)
#define GTSENDV4		((uint32_t)1 << 28)
#define GTSENDV6		((uint32_t)1 << 27)
#define GTTCPHO_SHIFT		18
#define GTTCPHO_MAX		0x7fU
#define TX_LEN_MAX		0x3ffffU

#define UDP_CS			((uint32_t)1 << 31) /* Calculate UDP/IP checksum */
#define TCP_CS			((uint32_t)1 << 30) /* Calculate TCP/IP checksum */
#define IPV4_CS			((uint32_t)1 << 29) /* Calculate IPv4 checksum */
#define IPV6_CS			((uint32_t)1 << 28) /* Calculate IPv6 checksum */
#define MSS_SHIFT		17
#define MSS_MAX			0x7ffU
#define TCPHO_SHIFT		17
#define TCPHO_MAX		0x7ffU
#define TX_VLAN_TAG		((uint32_t)1 << 16)

typedef struct tx_desc {
	uint32_t opts1;
	uint32_t opts2;
} R8152_TX_DESC;

enum rtl_version {
	RTL_VER_UNKNOWN = 0,
	RTL_VER_01,
	RTL_VER_02,
	RTL_VER_03,
	RTL_VER_04,
	RTL_VER_05,
	RTL_VER_06,
	RTL_VER_07,
	RTL_VER_MAX
};

enum rtl_register_content {
	_1000bps	= 0x10,
	_100bps		= 0x08,
	_10bps		= 0x04,
	LINK_STATUS	= 0x02,
	FULL_DUP	= 0x01,
};


enum usb_device_speed {
	USB_SPEED_UNKNOWN = 0,			/* enumerating */
	USB_SPEED_LOW, USB_SPEED_FULL,		/* usb 1.1 */
	USB_SPEED_HIGH,				/* usb 2.0 */
	USB_SPEED_WIRELESS,			/* wireless (usb 2.5) */
	USB_SPEED_SUPER,			/* usb 3.0 */
	USB_SPEED_SUPER_PLUS,			/* usb 3.1 */
};


typedef struct r8152 {
	uint32_t    ocp_base;
	uint8_t     supports_gmii;
	uint8_t     version;
    uint8_t     mac_addr[8] __attribute__ ((aligned (4)));
    uint8_t     *net_send_buff;
    uint8_t     *net_recv_buf;
} STRU_R8152_DEF;

struct r8152_version {
    uint16_t    tcr;
    uint16_t    version;
	uint8_t     gmii;
};


static USBH_StatusTypeDef get_registers(USBH_HandleTypeDef *phost, uint16_t value, uint16_t index, uint16_t size, void *data);
static USBH_StatusTypeDef set_registers(USBH_HandleTypeDef *phost, uint16_t value, uint16_t index, uint16_t size, void *data);
void generic_ocp_read(USBH_HandleTypeDef *phost, uint16_t index, uint16_t size, void *data, uint16_t type);
void generic_ocp_write(USBH_HandleTypeDef *phost, uint16_t index, uint16_t byteen, uint16_t size, void *data, uint16_t type);
void pla_ocp_read(USBH_HandleTypeDef *phost, uint16_t index, uint16_t size, void *data);
void pla_ocp_write(USBH_HandleTypeDef *phost, uint16_t index, uint16_t byteen, uint16_t size, void *data);
void usb_ocp_read(USBH_HandleTypeDef *phost, uint16_t index, uint16_t size, void *data);
void usb_ocp_write(USBH_HandleTypeDef *phost, uint16_t index, uint16_t byteen, uint16_t size, void *data);
void ocp_read_dword(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data);
void ocp_write_dword(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data);
void ocp_read_word(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data);
void ocp_write_word(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data);
void ocp_read_byte(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data);
void ocp_write_byte(USBH_HandleTypeDef *phost, uint16_t type, uint16_t index, uint32_t *data);
void ocp_reg_read(USBH_HandleTypeDef *phost, uint16_t addr, uint32_t *data);
void ocp_reg_write(USBH_HandleTypeDef *phost, uint16_t addr, uint32_t *data);
static void r8152_mdio_write(USBH_HandleTypeDef *phost, uint32_t reg_addr, uint32_t *value);
static void r8152_mdio_read(USBH_HandleTypeDef *phost, uint32_t reg_addr, uint32_t *value);
USBH_StatusTypeDef r8152_wait_for_bit(USBH_HandleTypeDef *phost, uint8_t ocp_reg, uint16_t type, uint16_t index, const uint32_t mask, uint8_t set, uint32_t timeout);
static void r8152b_reset_packet_filter(USBH_HandleTypeDef *phost);
static void rtl8152_wait_fifo_empty(USBH_HandleTypeDef *phost);
static void rtl8152_nic_reset(USBH_HandleTypeDef *phost);
static void rtl8152_get_speed(USBH_HandleTypeDef *phost, uint32_t *get_speed);
static void rtl_set_eee_plus(USBH_HandleTypeDef *phost);
static void rxdy_gated_en(USBH_HandleTypeDef *phost, uint8_t enable);
static void rtl8152_set_rx_mode(USBH_HandleTypeDef *phost);
static void rtl_enable(USBH_HandleTypeDef *phost);
static void rtl8152_enable(USBH_HandleTypeDef *phost);
static void rtl_disable(USBH_HandleTypeDef *phost);
static void r8152_power_cut_en(USBH_HandleTypeDef *phost, uint8_t enable);
static void rtl_rx_vlan_en(USBH_HandleTypeDef *phost, uint8_t enable);
static void r8152_read_mac(USBH_HandleTypeDef *phost);
void r8152_set_mac(USBH_HandleTypeDef *phost, void *p);
static void r8152b_disable_aldps(USBH_HandleTypeDef *phost);
static void r8152b_enable_aldps(USBH_HandleTypeDef *phost);
static void rtl8152_disable(USBH_HandleTypeDef *phost);
static void r8152b_hw_phy_cfg(USBH_HandleTypeDef *phost);
static void rtl8152_reinit_ll(USBH_HandleTypeDef *phost);
static void r8152b_exit_oob(USBH_HandleTypeDef *phost);
static void r8152b_enter_oob(USBH_HandleTypeDef *phost);
static void rtl8152_set_speed(USBH_HandleTypeDef *phost, uint8_t autoneg, uint16_t speed, uint8_t duplex);
void rtl8152_up(USBH_HandleTypeDef *phost);
void rtl8152_down(USBH_HandleTypeDef *phost);
static void r8152b_get_version(USBH_HandleTypeDef *phost);
static void rtl_tally_reset(USBH_HandleTypeDef *phost);
void r8152b_init(USBH_HandleTypeDef *phost);
static void rtl8152_unload(USBH_HandleTypeDef *phost);
static void r8152_init_common(USBH_HandleTypeDef *phost);
void r8152_init(USBH_HandleTypeDef *phost);
static void r8152_write_hwaddr(USBH_HandleTypeDef *phost);
void r8152_eth_probe(USBH_HandleTypeDef *phost);
uint32_t r8152_send_process(uint8_t *send_buff, uint8_t *raw_data, uint32_t data_len);
uint8_t *r8152_parse_header(uint8_t *recv_buff, uint32_t *total_size, uint32_t *data_len, uint32_t *header_size);
uint8_t *r8152_parse_header_no_agg(uint8_t *recv_buff, uint32_t *total_size, uint32_t *data_len, uint32_t *header_size);
uint8_t *r8152_get_rx_buff(void);
uint8_t *r8152_get_tx_buff(void);
void r8152_buff_init(void);


extern STRU_R8152_DEF  g_stR8152;
extern uint8_t net_send_buff[PKTSIZE_ALIGN];
extern uint8_t net_recv_buf[RTL8152_AGG_BUF_SZ];

#endif


/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_sd.h
Description: The external HAL APIs to use the SDMMC controller.
Author: Artosyn Software Team
Version: 0.0.1
Date: 2017/1/14
History: 
        0.0.1    2017/1/14    The initial version of dma.h
*****************************************************************************/
#ifndef __DMA_H__
#define __DMA_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#define DW_DMA_MAX_NR_CHANNELS	8

// #define DMA_DEBUG 
#define DMA_LOWEST_PRIORITY 7
#define DMA_HIGHEST_PRIORITY 0


/* flow controller */
typedef enum {
	DW_DMA_FC_D_M2M,
	DW_DMA_FC_D_M2P,
	DW_DMA_FC_D_P2M,
	DW_DMA_FC_D_P2P,
	DW_DMA_FC_P_P2M,
	DW_DMA_FC_SP_P2P,
	DW_DMA_FC_P_M2P,
	DW_DMA_FC_DP_P2P,
} ENUM_FlowControl;

/*
 * Redefine this macro to handle differences between 32- and 64-bit
 * addressing, big vs. little endian, etc.
 */
#define DW_REG(name)		volatile uint32_t name; volatile uint32_t __pad_##name

/* Hardware register definitions. */
typedef struct {
	DW_REG(SAR);		/* Source Address Register */
	DW_REG(DAR);		/* Destination Address Register */
	DW_REG(LLP);		/* Linked List Pointer */
	volatile uint32_t	CTL_LO;		/* Control Register Low */
	volatile uint32_t	CTL_HI;		/* Control Register High */
	DW_REG(SSTAT);
	DW_REG(DSTAT);
	DW_REG(SSTATAR);
	DW_REG(DSTATAR);
	volatile uint32_t	CFG_LO;		/* Configuration Register Low */
	volatile uint32_t	CFG_HI;		/* Configuration Register High */
	DW_REG(SGR);
	DW_REG(DSR);
} STRU_DmaChanRegs;

typedef struct {
	DW_REG(TFR);
	DW_REG(BLOCK);
	DW_REG(SRCTRAN);
	DW_REG(DSTTRAN);
	DW_REG(ERROR);
}  STRU_DmaIrqRegs ;

typedef struct {
	/* per-channel registers */
	STRU_DmaChanRegs CHAN[DW_DMA_MAX_NR_CHANNELS];

	/* irq handling */
	STRU_DmaIrqRegs	RAW;		/* r */
	STRU_DmaIrqRegs	STATUS;		/* r (raw & mask) */
	STRU_DmaIrqRegs	MASK;		/* rw (set = irq enabled) */
	STRU_DmaIrqRegs	CLEAR;		/* w (ack, affects "raw") */

	DW_REG(STATUS_INT);			/* r */

	/* software handshaking */
	DW_REG(REQ_SRC);
	DW_REG(REQ_DST);
	DW_REG(SGL_REQ_SRC);
	DW_REG(SGL_REQ_DST);
	DW_REG(LAST_SRC);
	DW_REG(LAST_DST);

	/* miscellaneous */
	DW_REG(DMA_CFG);
	DW_REG(CH_EN);
	DW_REG(ID);
	DW_REG(TEST);

	/* reserved */
	DW_REG(__reserved0);
	DW_REG(__reserved1);

	/* per-channel configuration registers */
	DW_REG(PARAMS_6);
	DW_REG(PARAMS_5);
	DW_REG(PARAMS_4);
	DW_REG(PARAMS_3);
	DW_REG(PARAMS_2);
	DW_REG(PARAMS_1);

}  STRU_DmaRegs;

/* Bitfields in DW_PARAMS */
#define DW_PARAMS_NR_CHAN	8		/* number of channels */
#define DW_PARAMS_NR_MASTER	4		/* number of AHB masters */
#define DW_PARAMS_CHX_MAX_MULT_SIZE 4 /* Maximum value of burst transaction size */
#define DW_PARAMS_DATA_WIDTH1	32		/* master 1 data width */
#define DW_PARAMS_DATA_WIDTH2	32		/* master 2 data width */
#define DW_PARAMS_DATA_WIDTH3	32		/* master 3 data width */
#define DW_PARAMS_DATA_WIDTH4	32		/* master 4 data width */
#define DW_PARAMS_EN		28		/* encoded parameters */
#define DW_PARAMS_NUM_MASTER_INT 2
#define DW_CH_MAX_BLK_SIZE 4095
#define AR_DW_CH_MAX_BLK_SIZE 16380	/* DW_CH_MAX_BLK_SIZE x 4 */
#define DW_MABRST 0                 /*Allow the AMBA burst length to be limited to a programmable maximum value */


/* Bitfields in DWC_PARAMS */
#define DWC_PARAMS_MBLK_EN	11		/* multi block transfer */

/* bursts size */
typedef enum {
	DW_DMA_MSIZE_1,
	DW_DMA_MSIZE_4,
	DW_DMA_MSIZE_8,
	DW_DMA_MSIZE_16,
	DW_DMA_MSIZE_32,
	DW_DMA_MSIZE_64,
	DW_DMA_MSIZE_128,
	DW_DMA_MSIZE_256,
} STRU_Msize;


/* Bitfields in CTL_LO */
#define DWC_CTLL_INT_EN		(1 << 0)	/* irqs enabled? */
#define DWC_CTLL_DST_WIDTH(n)	((n)<<1)	/* bytes per element */
#define DWC_CTLL_SRC_WIDTH(n)	((n)<<4)
#define DWC_CTLL_DST_INC	(0<<7)		/* DAR update/not */
#define DWC_CTLL_DST_DEC	(1<<7)
#define DWC_CTLL_DST_FIX	(2<<7)
#define DWC_CTLL_SRC_INC	(0<<9)		/* SAR update/not */
#define DWC_CTLL_SRC_DEC	(1<<9)
#define DWC_CTLL_SRC_FIX	(2<<9)
#define DWC_CTLL_DST_MSIZE(n)	((n)<<11)	/* burst, #elements */
#define DWC_CTLL_SRC_MSIZE(n)	((n)<<14)
#define DWC_CTLL_S_GATH_EN	(1 << 17)	/* src gather, !FIX */
#define DWC_CTLL_D_SCAT_EN	(1 << 18)	/* dst scatter, !FIX */
#define DWC_CTLL_FC(n)		((n) << 20)
#define DWC_CTLL_FC_M2M		(0 << 20)	/* mem-to-mem */
#define DWC_CTLL_FC_M2P		(1 << 20)	/* mem-to-periph */
#define DWC_CTLL_FC_P2M		(2 << 20)	/* periph-to-mem */
#define DWC_CTLL_FC_P2P		(3 << 20)	/* periph-to-periph */
/* plus 4 transfer types for peripheral-as-flow-controller */
#define DWC_CTLL_DMS(n)		((n)<<23)	/* dst master select */
#define DWC_CTLL_SMS(n)		((n)<<25)	/* src master select */
#define DWC_CTLL_LLP_D_EN	(1 << 27)	/* dest block chain */
#define DWC_CTLL_LLP_S_EN	(1 << 28)	/* src block chain */

/* Bitfields in CTL_HI */
#define DWC_CTLH_DONE		0x00001000
#define DWC_CTLH_BLOCK_TS_MASK	0x00000fff

/* Bitfields in CFG_LO */
#define DWC_CFGL_CH_PRIOR_MASK	(0x7 << 5)	/* priority mask */
#define DWC_CFGL_CH_PRIOR(x)	((x) << 5)	/* priority */
#define DWC_CFGL_CH_SUSP	(1 << 8)	/* pause xfer */
#define DWC_CFGL_FIFO_EMPTY	(1 << 9)	/* pause xfer */
#define DWC_CFGL_HS_DST		(1 << 10)	/* handshake w/dst */
#define DWC_CFGL_HS_SRC		(1 << 11)	/* handshake w/src */
#define DWC_CFGL_LOCK_CH_XFER	(0 << 12)	/* scope of LOCK_CH */
#define DWC_CFGL_LOCK_CH_BLOCK	(1 << 12)
#define DWC_CFGL_LOCK_CH_XACT	(2 << 12)
#define DWC_CFGL_LOCK_BUS_XFER	(0 << 14)	/* scope of LOCK_BUS */
#define DWC_CFGL_LOCK_BUS_BLOCK	(1 << 14)
#define DWC_CFGL_LOCK_BUS_XACT	(2 << 14)
#define DWC_CFGL_LOCK_CH	(1 << 15)	/* channel lockout */
#define DWC_CFGL_LOCK_BUS	(1 << 16)	/* busmaster lockout */
#define DWC_CFGL_HS_DST_POL	(1 << 18)	/* dst handshake active low */
#define DWC_CFGL_HS_SRC_POL	(1 << 19)	/* src handshake active low */
#define DWC_CFGL_MAX_BURST(x)	((x) << 20)
#define DWC_CFGL_RELOAD_SAR	(1 << 30)
#define DWC_CFGL_RELOAD_DAR	(1 << 31)

/* Bitfields in CFG_HI */
#define DWC_CFGH_FCMODE		(1 << 0)
#define DWC_CFGH_FIFO_MODE	(1 << 1)
#define DWC_CFGH_PROTCTL(x)	((x) << 2)
#define DWC_CFGH_DS_UPD_EN	(1 << 5)
#define DWC_CFGH_SS_UPD_EN	(1 << 6)
#define DWC_CFGH_SRC_PER(x)	((x) << 7)
#define DWC_CFGH_DST_PER(x)	((x) << 11)

/* Bitfields in SGR */
#define DWC_SGR_SGI(x)		((x) << 0)
#define DWC_SGR_SGC(x)		((x) << 20)

/* Bitfields in DSR */
#define DWC_DSR_DSI(x)		((x) << 0)
#define DWC_DSR_DSC(x)		((x) << 20)

/* Bitfields in ChEnReg */
#define DWC_CH_EN(x)		(1 << (x))
#define DWC_CH_EN_WE(x)		(1 << (x+8))

/* Bitfields in DmaCfgReg */
#define DW_CFG_DMA_EN		(1 << 0)

/* Use MALLoc to store the LLI */
#define USE_MALLOC_DESC


/* LLI == Linked List Item; a.k.a. DMA block descriptor */
typedef struct {
	/* values that are not changed by hardware */
	volatile uint32_t		sar;
	volatile uint32_t		dar;
	volatile uint32_t		llp;		/* chain to next lli */
	volatile uint32_t		ctllo;
	/* values that may get written back: */
	volatile uint32_t		ctlhi;
}  STRU_LinkListItem;

/* Flag to identify which channel to be used */
typedef enum {
	CHAN0 = 0,
	CHAN1,
	CHAN2,
	CHAN3,
	CHAN4,
	CHAN5,
	CHAN6,
	CHAN7,
	CHAN_AUTO
} ENUM_Chan;

/* Transfer types */
typedef enum {
	LINK_LIST_ITEM,
	AUTO_RELOAD,
	SINGLE_BLOCK
} ENUM_TransferType;

/* identify the channel is active */
typedef enum {
	NON_ACTIVE,
	ACTIVE
} ENUM_ChanActive;

typedef enum {
	DMA_blocked = 0,
	DMA_noneBlocked,
	DMA_blockTimer
} ENUM_blockMode;


typedef struct {
	volatile uint32_t u32_transNum;
	volatile uint32_t u32_srcTranAddr;
	volatile uint32_t u32_dstTranAddr;
	volatile uint32_t u32_blkSize;
	STRU_LinkListItem *pst_lliMalloc; 
	ENUM_TransferType e_transferType;
	ENUM_ChanActive e_transActive;
	volatile uint8_t trans_complete;
} STRU_transStatus;

#define IS_CHANNAL_PRIORITY(x) ((x) >= 0 && (x) <= 7)
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
// void assert_failed(uint8_t* file, uint32_t line);

#define DMA_OK                                      (0)
#define DMA_TIME_OUT                                (0xFF)
#define DMA_BUSY                                    (0xFE)


void DMA_init();

int32_t DMA_CheckChAvail(ENUM_Chan u8_channel, uint8_t u8_chanPriority);
uint32_t DMA_transfer(uint32_t u32_srcAddr, uint32_t u32_dstAddr, uint32_t u32_transByteNum, uint8_t u8_chanIndex, ENUM_TransferType e_transType);
uint32_t DMA_getStatus(uint8_t u8_chanIndex);
uint32_t DMA_forDriverTransfer(uint32_t u32_srcAddr, uint32_t u32_dstAddr, uint32_t u32_transByteNum, 
											ENUM_blockMode e_blockMode, uint32_t u32_ms);

#endif

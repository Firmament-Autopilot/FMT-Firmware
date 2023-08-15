#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>

#define SPI_BASE_0 (0x40100000) //ssi_0
#define SPI_BASE_1 (0x40120000) //ssi_1
#define SPI_BASE_2 (0x40140000) //ssi_2
#define SPI_BASE_3 (0x40160000) //ssi_3
#define SPI_BASE_4 (0x40180000) //ssi_4
#define SPI_BASE_5 (0x401a0000) //ssi_5
#define SPI_BASE_6 (0x401c0000) //ssi_6
#define SPI_BASE_7 (0xa0040000) //ssi_7

//=== SPI as Master Register Mapping ===//
#define SPI_CTRLR0       (0x00) //Control Register0
#define SPI_CTRLR1       (0x04) //Control Register1
#define SPI_SSIENR       (0x08) //SSI Enable Reg
#define SPI_MWCR         (0x0C) //Microwire Control Reg
#define SPI_SLAVE_EN     (0x10) //Slave Enable Reg
#define SPI_BAUDR        (0x14) //Buad Rate Select
#define SPI_TXFTLR       (0x18) //Transmit FIFO Threshold Level
#define SPI_RXFTLR       (0x1c) //Receive FIFO Threshold Level
#define SPI_TXFLR        (0x20) //Transmit FIFO Level Register
#define SPI_RXFLR        (0x24) //Receive FIFO Level Register
#define SPI_SR           (0x28) //Status Register
#define SPI_IMR          (0x2C) //Interrupt Mask Register
#define SPI_ISR          (0x30) //Interrupt Status Register
#define SPI_RISR         (0x34) //Raw Interrupt Status Register
#define SPI_TXOICR       (0x38) //Transmit FIFO Overflow Interrupt Clear Register
#define SPI_RXOICR       (0x3c) //Receive FIFO OVerflow Interrupt Clear Register
#define SPI_RXUICR       (0x40) //Receive FIFO Underflow interrupt Clear register
#define SPI_MSTICR       (0x44) //Multi-master Interrupt Clear Register
#define SPI_ICR          (0x48) //Interrupt Clear Register
#define SPI_DMACR        (0x4C) //DMA Control Register
#define SPI_DMATDLR      (0x50) //DMA Transmit Data Level
#define SPI_DMARDLR      (0x54) //DMA Receive Data Level
#define SPI_IDR          (0x58) //Identification Register
#define SPI_COMP_VERSION (0x5C) //
#define SPI_DR           (0x60) //Data Register

#define SPI_BASE_CLK_MHZ (200)
#define SPI_TXFLR_MAX    (8)
#define SPI_RXFLR_MAX    (8)
#define SPI_MAX_CHANNEL  (8)

#define SPI_CTRL0_DEF_VALUE  (0x347)
#define SPI_TXFTLR_DEF_VALUE (0x04)
#define SPI_RXFTLR_DEF_VALUE (0x03)
#define SPI_SSIENR_DEF_VALUE (0x01)

#define SPI_ISR_MASK  (0x3F) //
#define SPI_ISR_MSTIS (0x20) // Multi-Master Contention Interrupt Status
#define SPI_ISR_RXFIS (0x10) // Receive FIFO Full Interrupt Status
#define SPI_ISR_RXOIS (0x08) // Receive FIFO Overflow Interrupt Status
#define SPI_ISR_RXUIS (0x04) // Receive FIFO Underflow Interrupt Status
#define SPI_ISR_TXOIS (0x02) // Transmit FIFO Overflow Interrupt Status
#define SPI_ISR_TXEIS (0x01) // Transmit FIFO Empty Interrupt Status

#define SPI_CTRLR0_TMOD_MASK (0x03 << 8) //
#define SPI_CTRLR0_TMOD_TR   (0x00 << 8) //Transmit & Receive
#define SPI_CTRLR0_TMOD_TO   (0x01 << 8) //Transmit Only
#define SPI_CTRLR0_TMOD_RO   (0x02 << 8) //Receive Only
#define SPI_CTRLR0_TMOD_EE   (0x03 << 8) //EEPROM Read

#define SPI_CTRLR0_DFS_MASK  (0x0F) //
#define SPI_CTRLR0_DFS_8BIT  (0x07) // 8 bit
#define SPI_CTRLR0_DFS_16BIT (0x0F) // 16 bit

#define SPI_IMR_MASK  (0x3F) //
#define SPI_IMR_MSTIM (0x20) // Multi-Master Contention Interrupt Mask
#define SPI_IMR_RXFIM (0x10) // Receive FIFO Full Interrupt Mask
#define SPI_IMR_RXOIM (0x08) // Receive FIFO Overflow Interrupt Mask
#define SPI_IMR_RXUIM (0x04) // Receive FIFO Underflow Interrupt Mask
#define SPI_IMR_TXOIM (0x02) // Transmit FIFO Overflow Interrupt Mask
#define SPI_IMR_TXEIM (0x01) // Transmit FIFO Empty Interrupt Mask

#define SPI_SR_DCOL (0x40) // Data Collision Error.
#define SPI_SR_TXE  (0x20) // Transmission Error
#define SPI_SR_RFF  (0x10) // Receive FIFO Full.
#define SPI_SR_RFNE (0x08) // Receive FIFO Not Empty
#define SPI_SR_TFE  (0x04) // Transmit FIFO Empty
#define SPI_SR_TFNF (0x02) // Transmit FIFO Not Full
#define SPI_SR_BUSY (0x01) // SSI Busy Flag

typedef enum {
    SPI_0 = 0,
    SPI_1,
    SPI_2,
    SPI_3,
    SPI_4,
    SPI_5,
    SPI_6,
    SPI_7
} ENUM_SPI_COMPONENT;

typedef struct
{
    uint32_t ctrl0;   //
    uint32_t ctrl2;   //
    uint32_t clk_hz;  //clockrate (Hz)  -- change to Hz by cb
    uint32_t Tx_Fthr; //TX FiFO threshhold
    uint32_t Rx_Ftlr; //
    uint32_t SER;     //
} STRU_SPI_InitTypes;

typedef struct
{
    uint32_t txLen;     //
    uint32_t txAlrLen;  //
    uint8_t* txBuf;     //
    uint32_t txLenLast; //
    uint32_t rxLen;     //
    uint32_t rxAlrLen;  //
    uint8_t* rxBuf;     //
    uint32_t dfl;       //0:8bit,1:16bit
} STRU_SPI_INT_DATA;

void SPI_master_init(ENUM_SPI_COMPONENT en_id, STRU_SPI_InitTypes* st_settings);

int32_t SPI_write_read(ENUM_SPI_COMPONENT en_id,
                       uint8_t* ptr_wbuf, uint32_t u32_wsize,
                       uint8_t* ptr_rbuf, uint32_t u32_rsize);

int32_t SPI_write_read_dbg(ENUM_SPI_COMPONENT en_id,
                       uint8_t* ptr_wbuf, uint32_t u32_wsize,
                       uint8_t* ptr_rbuf, uint32_t u32_rsize);

int32_t CF_SPI_write_read(ENUM_SPI_COMPONENT en_id,
                          uint8_t* ptr_wbuf, uint32_t u32_wsize,
                          uint8_t* ptr_rbuf, uint32_t u32_rsize);

void SPI_IntrSrvc(uint32_t u32_vectorNum);
void SPI_IntrSrvc_dbg(uint32_t u32_vectorNum);

int SPI_GetBusyStatus(ENUM_SPI_COMPONENT en_id);

int SPI_WaitIdle(ENUM_SPI_COMPONENT en_id, uint32_t timeOut);

int32_t SPI_DisEnableInt(ENUM_SPI_COMPONENT en_id, uint32_t data);

#endif

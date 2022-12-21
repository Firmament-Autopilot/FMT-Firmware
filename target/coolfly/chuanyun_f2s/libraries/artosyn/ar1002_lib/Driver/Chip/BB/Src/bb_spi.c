#include <stdint.h>
#include "bb_spi.h"
#include "debuglog.h"
#include "interrupt.h"
#include "spi.h"


#define DEF_CLKRATE_HZ (9 * 1000000)

int BB_SPI_init(void)
{
    STRU_SPI_InitTypes init = {
        .ctrl0 = SPI_CTRL0_DEF_VALUE,    // [15:12]: Control Frame Size ;[11]: Shift Register Loop 0: Normal Mode, 1: test mode;[10] Slave Output Enable;
                                         // [9:8]: Transfer_mode,2'b00:Trans and Receive;[7:6] SCPOL,SCPH (SPI Oper_Mode),2'b0: mode0 ; 2'b3: mode3 ;
                                         // [5:4] FRF=2'b00: SPI Protocal; [3:0]=0x7:data frame size = 8bit;
        .clk_hz = DEF_CLKRATE_HZ,        //
        .Tx_Fthr = SPI_TXFTLR_DEF_VALUE, // transmit FIFO Threshold Level <=4
        .Rx_Ftlr = SPI_RXFTLR_DEF_VALUE, // receive FIFO Threshold Level  >=3
        .SER = SPI_SSIENR_DEF_VALUE      // slave enbale
    };

    SPI_master_init(BB_SPI_BASE_IDX, &init);
    NVIC_SetPriority(VIDEO_SPI_INTR_BB_VECTOR_NUM, NVIC_EncodePriority(NVIC_PRIORITYGROUP_5, INTR_NVIC_PRIORITY_SPI_DEFAULT, 0));
    reg_IrqHandle(VIDEO_SPI_INTR_BB_VECTOR_NUM, SPI_IntrSrvc, NULL);
    NVIC_EnableIRQ(VIDEO_SPI_INTR_BB_VECTOR_NUM);

    return 0;
}

int BB_SPI_curPageWriteByte(uint8_t addr, uint8_t data)
{
    uint8_t wdata[] = { 0x0e, addr, data };

    SPI_write_read(BB_SPI_BASE_IDX, wdata, sizeof(wdata), 0, 0);
    return SPI_WaitIdle(BB_SPI_BASE_IDX, BB_SPI_MAX_DELAY);
}

uint8_t BB_SPI_curPageReadByte(uint8_t addr)
{
    uint8_t rxdata;
    uint8_t wdata[] = { 0x0f, addr };

    SPI_write_read(BB_SPI_BASE_IDX, wdata, sizeof(wdata), &rxdata, 1);
    SPI_WaitIdle(BB_SPI_BASE_IDX, BB_SPI_MAX_DELAY);

    return rxdata;
}

int BB_SPI_WriteByte(ENUM_REG_PAGES page, uint8_t addr, uint8_t data)
{
    uint8_t dat = BB_SPI_curPageReadByte(0x00);
    BB_SPI_curPageWriteByte(0x00, (dat & 0x3F) | page);

    return BB_SPI_curPageWriteByte(addr, data);
}

uint8_t BB_SPI_ReadByte(ENUM_REG_PAGES page, uint8_t addr)
{
    uint8_t dat = BB_SPI_curPageReadByte(0x00);
    BB_SPI_curPageWriteByte(0x00, (dat & 0x3F) | page);

    return BB_SPI_curPageReadByte(addr);
}

int BB_SPI_WriteByteMask(ENUM_REG_PAGES page, uint8_t addr, uint8_t data, uint8_t mask)
{
    uint8_t ori = BB_SPI_ReadByte(page, addr);
    data = (ori & (~mask)) | data;
    return BB_SPI_curPageWriteByte(addr, data);
}

int BB_SPI_ReadByteMask(ENUM_REG_PAGES page, uint8_t addr, uint8_t mask)
{
    return BB_SPI_ReadByte(page, addr) & mask;
}

void BB_SPI_DisableEnable(uint8_t u8_flag)
{
    if (0 == u8_flag) {
        NVIC_DisableIRQ(VIDEO_SPI_INTR_BB_VECTOR_NUM);
    } else {
        BB_SPI_init();
    }
}

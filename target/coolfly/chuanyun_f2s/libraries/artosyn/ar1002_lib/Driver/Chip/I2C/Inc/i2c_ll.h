#ifndef I2C_LL_H
#define I2C_LL_H

#include <stddef.h>
#include <stdint.h>
#include "i2c.h"

#define MAX_I2C_CONTOLLER_NUMBER 6

#define BASE_ADDR_I2C0 (0x40200000)
#define BASE_ADDR_I2C1 (0x40240000)
#define BASE_ADDR_I2C2 (0x40280000)
#define BASE_ADDR_I2C3 (0x402c0000)
#define BASE_ADDR_I2C4 (0x40900000)
#define BASE_ADDR_I2C5 (0xA0080000)

// I2C Interrupt Mask Register
#define IC_INTR_M_MASK             (0xFFF)
#define IC_INTR_M_GEN_CALL         (1 << 11)
#define IC_INTR_M_START_DET        (1 << 10)
#define IC_INTR_M_STOP_DET         (1 << 9)
#define IC_INTR_M_ACTIVITY         (1 << 8)
#define IC_INTR_M_RX_DONE          (1 << 7)
#define IC_INTR_M_TX_ABRT          (1 << 6)
#define IC_INTR_M_RD_REQ           (1 << 5)
#define IC_INTR_M_TX_EMPTY         (1 << 4)
#define IC_INTR_M_TX_OVER          (1 << 3)
#define IC_INTR_M_RX_FULL          (1 << 2)
#define IC_INTR_M_RX_OVER          (1 << 1)
#define IC_INTR_M_RX_UNDER         (1 << 0)

// I2C Interrupt Status Register
#define IC_INTR_R_MASK             (0xFFF)
#define IC_INTR_R_GEN_CALL         (1 << 11)
#define IC_INTR_R_START_DET        (1 << 10)
#define IC_INTR_R_STOP_DET         (1 << 9)
#define IC_INTR_R_ACTIVITY         (1 << 8)
#define IC_INTR_R_RX_DONE          (1 << 7)
#define IC_INTR_R_TX_ABRT          (1 << 6)
#define IC_INTR_R_RD_REQ           (1 << 5)
#define IC_INTR_R_TX_EMPTY         (1 << 4)
#define IC_INTR_R_TX_OVER          (1 << 3)
#define IC_INTR_R_RX_FULL          (1 << 2)
#define IC_INTR_R_RX_OVER          (1 << 1)
#define IC_INTR_R_RX_UNDER         (1 << 0)

// I2C Transmit Abort Source Register
#define IC_TX_ABRT_7B_ADDR_NOACK    (1 << 0)


#define I2C_TX_FIFO_BUFFER_DEPTH (8)
#define I2C_RX_FIFO_BUFFER_DEPTH (8)

#define IC_RX_TL_DEF_VALUE       (4)
#define IC_TX_TL_DEF_VALUE       (4)



#define I2C_CMD_ID_START (0x10000)

#define ROUNDUP_DIVISION(a, b) ((a % b) ? ((a / b) + 1) : (a / b))

typedef enum
{
    I2C_CMD_SET_MODE = I2C_CMD_ID_START,
    I2C_CMD_SET_M_SPEED,
    I2C_CMD_SET_M_TARGET_ADDRESS,
    I2C_CMD_SET_S_SLAVE_ADDRESS,
    I2C_CMD_SET_M_WRITE_DATA,
    I2C_CMD_SET_M_READ_LAUNCH,
    I2C_CMD_SET_RX_TL,
    I2C_CMD_SET_INTR_ENABLE,
    I2C_CMD_SET_INTR_DISENABLE,
    I2C_CMD_GET_M_TX_FIFO_LENGTH,
    I2C_CMD_GET_M_RX_FIFO_LENGTH,
    I2C_CMD_GET_M_RX_FIFO_DATA,
    I2C_CMD_GET_M_IDLE,
    I2C_CMD_GET_INTR_STAT,
	I2C_CMD_GET_IC_CLR_TX_ABRT,
    I2C_CMD_GET_IC_TX_ABRT_SOURCE,
    I2C_CMD_SET_M_HCNT,
    I2C_CMD_SET_M_LCNT,
    I2C_CMD_SET_M_FS_SPKLEN
} ENUM_I2C_CMD_ID;

typedef enum
{
    I2C_MASTER_IDLE = 1,
    I2C_MASTER_ACTIVE,
} ENUM_I2C_MASTER_ACTIVITY;

typedef struct
{
    unsigned int    IC_CON      ;       // 0x00
    unsigned int    IC_TAR      ;       // 0x04
    unsigned int    IC_SAR      ;       // 0x08
    unsigned int    IC_HS_MADDR ;       // 0x0c
    unsigned int    IC_DATA_CMD ;       // 0x10
    unsigned int    IC_SS_SCL_HCNT;     // 0x14
    unsigned int    IC_SS_SCL_LCNT;     // 0x18
    unsigned int    IC_FS_SCL_HCNT;     // 0x1c
    unsigned int    IC_FS_SCL_LCNT;     // 0x20
    unsigned int    IC_HS_SCL_HCNT;     // 0x24
    unsigned int    IC_HS_SCL_LCNT;     // 0x28
    unsigned int    IC_INTR_STAT;       // 0x2c
    unsigned int    IC_INTR_MASK;       // 0x30
    unsigned int    IC_RAW_INTR_STAT;   // 0x34
    unsigned int    IC_RX_TL    ;       // 0x38
    unsigned int    IC_TX_TL    ;       // 0x3c
    unsigned int    IC_CLR_INTR ;       // 0x40
    unsigned int    IC_CLR_RX_UNDER;    // 0x44
    unsigned int    IC_CLR_RX_OVER;     // 0x48
    unsigned int    IC_CLR_TX_OVER;     // 0x4c
    unsigned int    IC_CLR_RD_REQ;      // 0x50
    unsigned int    IC_CLR_TX_ABRT;     // 0x54
    unsigned int    IC_CLR_RX_DONE;     // 0x58
    unsigned int    IC_CLR_ACTIVITY;    // 0x5c
    unsigned int    IC_CLR_STOP_DET;    // 0x60
    unsigned int    IC_CLR_START_DET;   // 0x64
    unsigned int    IC_CLR_GEN_GALL;    // 0x68
    unsigned int    IC_ENABLE   ;       // 0x6c
    unsigned int    IC_STATUS   ;       // 0x70
    unsigned int    IC_TXFLR    ;       // 0x74
    unsigned int    IC_RXFLR    ;       // 0x78
    unsigned int    IC_SDA_HOLD ;       // 0x7c
    unsigned int    IC_TX_ABRT_SOURCE;  // 0x80
    unsigned int    IC_SLV_DATA_NACK_ONLY;// 0x84
    unsigned int    IC_DMA_CR   ;       // 0x88
    unsigned int    IC_DMA_TDLR ;       // 0x8c
    unsigned int    IC_DMA_RDLR ;       // 0x90
    unsigned int    IC_SDA_SETUP;       // 0x94
    unsigned int    IC_ACK_GENERAL_CALL;// 0x98
    unsigned int    IC_ENABLE_STATUS;   // 0x9c
    unsigned int    IC_FS_SPKLEN;       // 0xa0
    unsigned int    IC_HS_SPKLEN;       // 0xa4
    unsigned int    reserved[19];       // 0xa8 ~ 0xf0
    unsigned int    IC_COMP_PARAM_1;    // 0xf4
    unsigned int    IC_COMP_VERSION;    // 0xf8
    unsigned int    IC_COMP_TYPE;       // 0xfc
} STRU_I2C_Type;

typedef struct
{
    const uint32_t u32_i2cRegBaseAddr;
    ENUM_I2C_Mode  en_i2cMode;
    union
    {
        struct
        {
            uint16_t addr;
            ENUM_I2C_Speed  speed;
            uint16_t hcnt_percent;
            uint16_t lcnt_percent;
            uint8_t  fs_spklen;
        } master;
        struct
        {
            uint16_t addr;
        } slave;
    } parameter;
} STRU_I2C_Controller;

void I2C_LL_Delay(unsigned int delay);
STRU_I2C_Controller* I2C_LL_GetI2CController(EN_I2C_COMPONENT en_i2cComponent);
uint8_t I2C_LL_IOCtl(STRU_I2C_Controller* ptr_i2cController, ENUM_I2C_CMD_ID en_CommandID, uint32_t* ptr_CommandVal);

#endif


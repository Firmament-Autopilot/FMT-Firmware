#include <stdlib.h>
#include <string.h>
#include "data_type.h"
#include "i2c.h"
#include "i2c_ll.h"
#include "debuglog.h"
#include "reg_rw.h"
#include "interrupt.h"
#include "drv_systick.h"
#include "driver_buffer.h"


static STRU_I2C_INT_DATA s_st_i2cIntrData[MAX_I2C_CONTOLLER_NUMBER] = {0};

static int32_t I2C_Master_SetIntrData(EN_I2C_COMPONENT en_component,
                                      uint8_t *ptr_wbuf, uint32_t u32_wsize,
                                      uint8_t *ptr_rbuf, uint32_t u32_rsize,
                                      uint32_t u32_rlanch) ;
static int8_t I2C_Master_EnableIntr(EN_I2C_COMPONENT en_component, uint32_t data);
static int8_t I2C_Master_DisEnableIntr(EN_I2C_COMPONENT en_component, uint32_t data);
static uint8_t I2C_Master_GetTxFifoLength(EN_I2C_COMPONENT en_component);
static uint8_t I2C_Master_GetRxFifoLength(EN_I2C_COMPONENT en_component);
static uint32_t I2C_Master_GetIntrStatus(EN_I2C_COMPONENT en_component);
static int8_t I2C_Master_SetRxTl(EN_I2C_COMPONENT en_component, uint8_t tl);


static uint8_t I2C_Master_UpdateTargetAddress(EN_I2C_COMPONENT en_component, uint16_t i2cAddr)
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value_tmp = i2cAddr;
       
        if (I2C_LL_IOCtl(dev, I2C_CMD_SET_M_TARGET_ADDRESS, &value_tmp) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_SET_M_TARGET_ADDRESS error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}

static uint8_t I2C_Master_WriteByte(EN_I2C_COMPONENT en_component, uint8_t value)
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value_tmp = value;
        if (I2C_LL_IOCtl(dev, I2C_CMD_SET_M_WRITE_DATA, &value_tmp) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_SET_M_WRITE_DATA error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}

static uint8_t I2C_Master_ReadLaunch(EN_I2C_COMPONENT en_component)
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value;
        if (I2C_LL_IOCtl(dev, I2C_CMD_SET_M_READ_LAUNCH, &value) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_SET_M_READ_DATA_LAUNCH error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}

static uint8_t I2C_Master_ReadByte(EN_I2C_COMPONENT en_component)
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value;
        if (I2C_LL_IOCtl(dev, I2C_CMD_GET_M_RX_FIFO_DATA, &value) == TRUE)
        {
            return (uint8_t)value;
        }
        else
        {
            DLOG_Error("I2C_CMD_GET_M_RX_FIFO_DATA error!");
            return 0;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return 0;
}

int32_t I2C_Master_WaitTillIdle(EN_I2C_COMPONENT en_component, uint32_t timeOut)
{
    uint32_t start;
    
    if (0 != timeOut)
    {
        start = SysTicks_GetTickCount();
        I2C_LL_Delay(1000); // Need some time to get the real activity status
        while (I2C_Master_GetBusyStatus(en_component))
        {
            if ((SysTicks_GetDiff(start, SysTicks_GetTickCount())) >= timeOut)
            {
                return -1;
            }
        }
    }

    return 0;
}

static uint8_t I2C_Master_GetTxFifoLength(EN_I2C_COMPONENT en_component)
{
    uint32_t u32_FiFoLength;
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    if (dev)
    {
        I2C_LL_IOCtl(dev, I2C_CMD_GET_M_TX_FIFO_LENGTH, &u32_FiFoLength);
        return (uint8_t)u32_FiFoLength;
    }
    else
    {
        
        DLOG_Error("Can not get right i2c controller!");
        return 0;
    }
}

static uint8_t I2C_Master_GetRxFifoLength(EN_I2C_COMPONENT en_component)
{
    uint32_t u32_FiFoLength;
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    if (dev)
    {
        I2C_LL_IOCtl(dev, I2C_CMD_GET_M_RX_FIFO_LENGTH, &u32_FiFoLength);
        return (uint8_t)u32_FiFoLength;
    }
    else
    {
        
        DLOG_Error("Can not get right i2c controller!");
        return 0;
    }
}

static uint32_t I2C_Master_GetIntrStatus(EN_I2C_COMPONENT en_component)
{
    uint32_t u32_IntrStatus;
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    if (dev)
    {
        I2C_LL_IOCtl(dev, I2C_CMD_GET_INTR_STAT, &u32_IntrStatus);
        return (u32_IntrStatus & IC_INTR_R_MASK);
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
        return 0;
    }

    
}


/************************************************************************************
 * I2C APIs
 ************************************************************************************/

uint8_t I2C_Init(EN_I2C_COMPONENT en_component, ENUM_I2C_Mode en_i2cMode, uint16_t u16_i2cAddr, ENUM_I2C_Speed en_i2cSpeed)
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    // IO MUX
    if (en_component == I2C_Component_2)
    {
        Reg_Write32_Mask(SFR_PAD_CTRL7_REG, 0, BIT(14) | BIT(15) | BIT(16) | BIT(17));
    }
    else if (en_component == I2C_Component_5)
    {
        Reg_Write32_Mask(SFR_PAD_CTRL7_REG, BIT(14) | BIT(16), BIT(14) | BIT(15) | BIT(16) | BIT(17));
    }

    if (dev)
    {
        uint32_t tmpValue;
        if (en_i2cMode == I2C_Master_Mode)
        {           
            tmpValue = u16_i2cAddr;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_TARGET_ADDRESS, &tmpValue);
            tmpValue = en_i2cSpeed;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_SPEED, &tmpValue);
            tmpValue = en_i2cMode;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_MODE, &tmpValue);
        }
        else if (en_i2cMode == I2C_Slave_Mode)
        {
            tmpValue = u16_i2cAddr;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_S_SLAVE_ADDRESS, &tmpValue);
            tmpValue = en_i2cMode;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_MODE, &tmpValue);
        }
        
        return TRUE;
    }
    
    return FALSE;
}

uint8_t I2C_Init_Ex(EN_I2C_COMPONENT en_component, ENUM_I2C_Mode en_i2cMode, uint16_t u16_i2cAddr, ENUM_I2C_Speed en_i2cSpeed,
                       uint16_t low_count, uint16_t high_count, uint8_t fs_spk)
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    // IO MUX
    if (en_component == I2C_Component_2)
    {
        Reg_Write32_Mask(SFR_PAD_CTRL7_REG, 0, BIT(14) | BIT(15) | BIT(16) | BIT(17));
    }
    else if (en_component == I2C_Component_5)
    {
        Reg_Write32_Mask(SFR_PAD_CTRL7_REG, BIT(14) | BIT(16), BIT(14) | BIT(15) | BIT(16) | BIT(17));
    }

    if (dev)
    {
        uint32_t tmpValue;
        if (en_i2cMode == I2C_Master_Mode)
        {
            tmpValue = u16_i2cAddr;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_TARGET_ADDRESS, &tmpValue);
            tmpValue = en_i2cSpeed;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_SPEED, &tmpValue);
            tmpValue = high_count;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_HCNT, &tmpValue);
            tmpValue = low_count;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_LCNT, &tmpValue);
            tmpValue = fs_spk;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_M_FS_SPKLEN, &tmpValue);
            tmpValue = en_i2cMode;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_MODE, &tmpValue);
        }
        else if (en_i2cMode == I2C_Slave_Mode)
        {
            tmpValue = u16_i2cAddr;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_S_SLAVE_ADDRESS, &tmpValue);
            tmpValue = en_i2cMode;
            I2C_LL_IOCtl(dev, I2C_CMD_SET_MODE, &tmpValue);
        }

        return TRUE;
    }

    return FALSE;
}


uint8_t I2C_Master_WriteData(EN_I2C_COMPONENT en_component, uint16_t u16_i2cAddr, uint8_t* ptr_data, uint32_t u32_dataSize)
{
    uint32_t u32_tmpLen = 0;
    
    u32_tmpLen = ((u32_dataSize < I2C_TX_FIFO_BUFFER_DEPTH)? u32_dataSize:(I2C_TX_FIFO_BUFFER_DEPTH));
    I2C_Master_SetIntrData(en_component, ptr_data + u32_tmpLen, u32_dataSize-u32_tmpLen, 0, 0, 0);
    
    I2C_Master_UpdateTargetAddress(en_component, u16_i2cAddr);

    if (ptr_data)
    {
        uint32_t i = 0;
        while (i < u32_tmpLen)
        {
            I2C_Master_WriteByte(en_component, ptr_data[i]);
            i++;
        }
        
        if (u32_dataSize > I2C_TX_FIFO_BUFFER_DEPTH)
        {
            I2C_Master_EnableIntr(en_component, IC_INTR_M_TX_EMPTY);
        }

        return TRUE;
    }

    return FALSE;
}

uint8_t I2C_Master_ReadData(EN_I2C_COMPONENT en_component, uint16_t u16_i2cAddr, uint8_t* ptr_subAddr, uint8_t u8_subAddrSize, uint8_t* ptr_data, uint32_t u32_dataSize)
{
    uint8_t u8_i = 0;
    uint32_t u32_LaunchNumber = 0;
    uint32_t u32_tmpLen;
    
    u32_tmpLen = ((u32_dataSize < I2C_RX_FIFO_BUFFER_DEPTH)? u32_dataSize:(I2C_RX_FIFO_BUFFER_DEPTH - 1));
    I2C_Master_SetIntrData(en_component, 0, 0, ptr_data, u32_dataSize, u32_tmpLen);
    
    I2C_Master_UpdateTargetAddress(en_component, u16_i2cAddr);
    
    if (ptr_subAddr)
    {
        while (u8_i < u8_subAddrSize)
        {
            // The sub address size should be less than I2C_TX_FIFO_BUFFER_DEPTH, so no check here.
            I2C_Master_WriteByte(en_component, ptr_subAddr[u8_i++]); // High address first
        }
    }
    
    if (ptr_data)
    {
        if (u32_dataSize <= IC_RX_TL_DEF_VALUE)
        {
            I2C_Master_SetRxTl(en_component, 0);
        }
        else
        {
            I2C_Master_SetRxTl(en_component, IC_RX_TL_DEF_VALUE);
        }

        I2C_Master_EnableIntr(en_component, IC_INTR_M_RX_FULL);
            
        while (u32_LaunchNumber < u32_tmpLen)
        {
            I2C_Master_ReadLaunch(en_component);
            u32_LaunchNumber++;
        }

        return TRUE;
    }

    return FALSE;
}

void I2C_Master_IntrSrvc(uint32_t u32_vectorNum)
{
    uint8_t u8_i2cCh;
    uint32_t u32_i2cIsr;
    uint8_t u8_cnt = 0;
    uint8_t tmpLen;

    if (VIDEO_I2C_INTR_VIDEO_VECTOR_NUM == u32_vectorNum)
    {
        u8_i2cCh = 5;
    }
    else if (I2C_SLV_INTR_VECTOR_NUM == u32_vectorNum)
    {
        u8_i2cCh = 4;
    }
    else
    {
        u8_i2cCh = u32_vectorNum - I2C_INTR0_VECTOR_NUM;
    }

    u32_i2cIsr = I2C_Master_GetIntrStatus(u8_i2cCh);

    if (u32_i2cIsr & IC_INTR_R_TX_EMPTY) // TX INT
    {
        u8_cnt = 0;
        tmpLen = I2C_Master_GetTxFifoLength(u8_i2cCh);
        tmpLen = I2C_TX_FIFO_BUFFER_DEPTH - tmpLen;
        while ((s_st_i2cIntrData[u8_i2cCh].txAlrLen) < (s_st_i2cIntrData[u8_i2cCh].txLen))
        {
            I2C_Master_WriteByte(u8_i2cCh, s_st_i2cIntrData[u8_i2cCh].txBuf[s_st_i2cIntrData[u8_i2cCh].txAlrLen]); 
            s_st_i2cIntrData[u8_i2cCh].txAlrLen += 1;
            u8_cnt += 1;
            if (u8_cnt >= tmpLen)
            {
                break;
            }
        }
        if((s_st_i2cIntrData[u8_i2cCh].txAlrLen) >= (s_st_i2cIntrData[u8_i2cCh].txLen))
        {
            I2C_Master_DisEnableIntr(u8_i2cCh, IC_INTR_M_TX_EMPTY);
        }
    }
    
    if (u32_i2cIsr & IC_INTR_R_RX_FULL) // RX INT
    {
        u8_cnt = 0;
        tmpLen = I2C_Master_GetRxFifoLength(u8_i2cCh);
        while ((s_st_i2cIntrData[u8_i2cCh].rxAlrLen) < (s_st_i2cIntrData[u8_i2cCh].rxLen))
        {
            s_st_i2cIntrData[u8_i2cCh].rxBuf[s_st_i2cIntrData[u8_i2cCh].rxAlrLen] = I2C_Master_ReadByte(u8_i2cCh);
            s_st_i2cIntrData[u8_i2cCh].rxAlrLen += 1;
            u8_cnt += 1;
            if (u8_cnt >= tmpLen)
            {
                break;
            }
        }

        u8_cnt = 0;
        while ((s_st_i2cIntrData[u8_i2cCh].rxAlrLanNum) < (s_st_i2cIntrData[u8_i2cCh].rxLen))
        {
            I2C_Master_ReadLaunch(u8_i2cCh);
            s_st_i2cIntrData[u8_i2cCh].rxAlrLanNum += 1;
            u8_cnt += 1;
            if (u8_cnt >= tmpLen)
            {
                break;
            }
        }
        
        if((s_st_i2cIntrData[u8_i2cCh].rxAlrLen) >= (s_st_i2cIntrData[u8_i2cCh].rxLen))
        {
            I2C_Master_DisEnableIntr(u8_i2cCh, IC_INTR_M_RX_FULL);
        }

        if (((s_st_i2cIntrData[u8_i2cCh].rxLen) - (s_st_i2cIntrData[u8_i2cCh].rxAlrLen)) <= IC_RX_TL_DEF_VALUE)
        {
            I2C_Master_SetRxTl(u8_i2cCh, 0);
        }
    }

    if (u32_i2cIsr & (~(IC_INTR_R_TX_EMPTY | IC_INTR_R_RX_FULL))) // some error happpened.
    {
        I2C_Master_DisEnableIntr(u8_i2cCh, IC_INTR_M_MASK);
        DLOG_Error("i2c %d intr error!", u8_i2cCh);
    }
}

int I2C_Master_GetBusyStatus(EN_I2C_COMPONENT en_component)
{
    uint32_t value = 0;

    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    if (dev)
    {
        I2C_LL_IOCtl(dev, I2C_CMD_GET_M_IDLE, &value);
        if (I2C_MASTER_IDLE == ((ENUM_I2C_MASTER_ACTIVITY)(value)))
        {
            value = 0;
        }
        else
        {
            value = 1;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return value;
}

int I2C_Master_GetTxAbrtSource(EN_I2C_COMPONENT en_component)
{
    uint32_t value = 0;

    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);

    if (dev)
    {
        I2C_LL_IOCtl(dev, I2C_CMD_GET_IC_TX_ABRT_SOURCE, &value);
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return value;
}


static int32_t I2C_Master_SetIntrData(EN_I2C_COMPONENT en_component,
                                      uint8_t *ptr_wbuf, uint32_t u32_wsize,
                                      uint8_t *ptr_rbuf, uint32_t u32_rsize,
                                      uint32_t u32_rAlrLanNum) 
{

    if (en_component < MAX_I2C_CONTOLLER_NUMBER)
    {
        s_st_i2cIntrData[en_component].txLen = u32_wsize;     
        s_st_i2cIntrData[en_component].txAlrLen = 0;  
        if ((ptr_wbuf != NULL) && (u32_wsize != 0))         // write
        {
            if(0 != COMMON_getNewBuffer(&s_st_i2cIntrData[en_component].txBuf,
                                   ptr_wbuf,
                                   &s_st_i2cIntrData[en_component].txLenLast, 
                                   u32_wsize))
            {
                DLOG_Info("fail");                
            }
        }
        else                                                // read
        {

        }
        s_st_i2cIntrData[en_component].rxLen = u32_rsize;     
        s_st_i2cIntrData[en_component].rxAlrLen = 0;  
        s_st_i2cIntrData[en_component].rxBuf = ptr_rbuf;  
        s_st_i2cIntrData[en_component].rxAlrLanNum = u32_rAlrLanNum;

        return 0;
    }
    else
    {
        return -1;
    }
}

static int8_t I2C_Master_EnableIntr(EN_I2C_COMPONENT en_component, uint32_t data) 
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value = data & IC_INTR_M_MASK;
        if (I2C_LL_IOCtl(dev, I2C_CMD_SET_INTR_ENABLE, &value) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_SET_INTR_ENABLE error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}

static int8_t I2C_Master_DisEnableIntr(EN_I2C_COMPONENT en_component, uint32_t data) 
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value = data & IC_INTR_M_MASK;
        if (I2C_LL_IOCtl(dev, I2C_CMD_SET_INTR_DISENABLE, &value) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_SET_INTR_DISENABLE error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}

static int8_t I2C_Master_SetRxTl(EN_I2C_COMPONENT en_component, uint8_t tl) 
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value = tl;
        if (I2C_LL_IOCtl(dev, I2C_CMD_SET_RX_TL, &value) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_SET_RX_TL error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}

int8_t I2C_Master_ClrTxAbrt(EN_I2C_COMPONENT en_component) 
{
    STRU_I2C_Controller* dev = I2C_LL_GetI2CController(en_component);
    
    if (dev)
    {
        uint32_t value;
        if (I2C_LL_IOCtl(dev, I2C_CMD_GET_IC_CLR_TX_ABRT, &value) == TRUE)
        {
            return TRUE;
        }
        else
        {
            DLOG_Error("I2C_CMD_GET_IC_CLR_TX_ABRT error!");
            return FALSE;
        }
    }
    else
    {
        DLOG_Error("Can not get right i2c controller!");
    }

    return FALSE;
}


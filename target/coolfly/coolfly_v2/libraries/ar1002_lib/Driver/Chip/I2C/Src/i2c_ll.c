#include <stddef.h>
#include <stdint.h>
#include "data_type.h"
#include "reg_rw.h"
#include "i2c_ll.h"
#include "i2c.h"
#include "debuglog.h"
#include "pll_ctrl.h"
#include "cpu_info.h"
#include "drv_systick.h"

static STRU_I2C_Controller stru_i2cControllerArray[MAX_I2C_CONTOLLER_NUMBER] = 
{
    {
        .u32_i2cRegBaseAddr = BASE_ADDR_I2C0,
        .en_i2cMode = I2C_Unknown_Mode,
        .parameter.master.speed = I2C_Unknown_Speed,
        .parameter.master.addr = 0,
        .parameter.master.hcnt_percent = 0,
        .parameter.master.lcnt_percent = 0,
        .parameter.master.fs_spklen = 0,
    },
    {
        .u32_i2cRegBaseAddr = BASE_ADDR_I2C1,
        .en_i2cMode = I2C_Unknown_Mode,
        .parameter.master.speed = I2C_Unknown_Speed,
        .parameter.master.addr = 0,
        .parameter.master.hcnt_percent = 0,
        .parameter.master.lcnt_percent = 0,
        .parameter.master.fs_spklen = 0,
    },
    {
        .u32_i2cRegBaseAddr = BASE_ADDR_I2C2,
        .en_i2cMode = I2C_Unknown_Mode,
        .parameter.master.speed = I2C_Unknown_Speed,
        .parameter.master.addr = 0,
        .parameter.master.hcnt_percent = 0,
        .parameter.master.lcnt_percent = 0,
        .parameter.master.fs_spklen = 0,
    },
    {
        .u32_i2cRegBaseAddr = BASE_ADDR_I2C3,
        .en_i2cMode = I2C_Unknown_Mode,
        .parameter.master.speed = I2C_Unknown_Speed,
        .parameter.master.addr = 0,
        .parameter.master.hcnt_percent = 0,
        .parameter.master.lcnt_percent = 0,
        .parameter.master.fs_spklen = 0,
    },
    {
        .u32_i2cRegBaseAddr = BASE_ADDR_I2C4,
        .en_i2cMode = I2C_Unknown_Mode,
        .parameter.master.speed = I2C_Unknown_Speed,
        .parameter.master.addr = 0,
        .parameter.master.hcnt_percent = 0,
        .parameter.master.lcnt_percent = 0,
        .parameter.master.fs_spklen = 0,
    },
    {
        .u32_i2cRegBaseAddr = BASE_ADDR_I2C5,
        .en_i2cMode = I2C_Unknown_Mode,
        .parameter.master.speed = I2C_Unknown_Speed,
        .parameter.master.addr = 0,
        .parameter.master.hcnt_percent = 0,
        .parameter.master.lcnt_percent = 0,
        .parameter.master.fs_spklen = 0,
    },
};

static uint32_t I2C_LL_GetInputClockByRegBaseAddr(uint32_t u32_i2cRegBaseAddr)
{
    uint16_t u16_pllClk = 64;

    switch (u32_i2cRegBaseAddr)
    {
    case BASE_ADDR_I2C0:
    case BASE_ADDR_I2C1:
    case BASE_ADDR_I2C2:
    case BASE_ADDR_I2C3:
    case BASE_ADDR_I2C4:
        PLLCTRL_GetCoreClk((uint16_t *)&u16_pllClk, ENUM_CPU0_ID);
        u16_pllClk = u16_pllClk >> 1;
        break;
    case BASE_ADDR_I2C5:
        PLLCTRL_GetCoreClk((uint16_t *)&u16_pllClk, ENUM_CPU2_ID);
        break;
    default:
        break;
    }

    return (uint32_t)u16_pllClk;
}

static void I2C_LL_RefreshConfigRegisters(STRU_I2C_Controller* ptr_i2cController)
{
    if (ptr_i2cController != NULL)
    {
        volatile STRU_I2C_Type* i2c_reg = (volatile STRU_I2C_Type*)ptr_i2cController->u32_i2cRegBaseAddr;

        uint32_t i2c_clock = I2C_LL_GetInputClockByRegBaseAddr(ptr_i2cController->u32_i2cRegBaseAddr);
        
        if (ptr_i2cController->en_i2cMode == I2C_Master_Mode)
        {
            /* i2c master initialization */

            i2c_reg->IC_ENABLE &= ~(0x1);               // disbale i2c

            if (ptr_i2cController->parameter.master.speed == I2C_Standard_Speed)  // stardard speed
            {
/*
                i2c_reg->IC_CON &= ~((3<<3)|(3<<1));             // [4]:addr_mst in 7-bit; [3]:addr_slv in 7-bit; [2:1]=01,standard mode;
                i2c_reg->IC_CON |= (3<<0 | 3<<5);       // [1]; [0]:enable master-mode;[6]:disbale i2c slave-only mode; [5]:enable ic_restart
*/
                
                i2c_reg->IC_SDA_HOLD = 0xf0; 
                i2c_reg->IC_SDA_SETUP = 0xf0;
                i2c_reg->IC_FS_SPKLEN = 0x30;
                i2c_reg->IC_CON = 0x63;

                if(0 != ptr_i2cController->parameter.master.hcnt_percent && 0 != ptr_i2cController->parameter.master.lcnt_percent)
                {
                    uint32_t tmp_hcnt_per = ptr_i2cController->parameter.master.hcnt_percent;
                    uint32_t tmp_lcnt_per = ptr_i2cController->parameter.master.lcnt_percent;
                    uint32_t tmp_total = ptr_i2cController->parameter.master.hcnt_percent + ptr_i2cController->parameter.master.lcnt_percent;
                    i2c_reg->IC_SS_SCL_HCNT = ROUNDUP_DIVISION(8700 * 2 * i2c_clock, 1000) * tmp_hcnt_per / tmp_total;
                    i2c_reg->IC_SS_SCL_LCNT = ROUNDUP_DIVISION(8700 * 2 * i2c_clock, 1000) * tmp_lcnt_per / tmp_total;
                }
                else
                {
                    i2c_reg->IC_SS_SCL_HCNT = ROUNDUP_DIVISION(4000 * 2 * i2c_clock, 1000);    // set high period of SCL 4000 * 2 ns
                    i2c_reg->IC_SS_SCL_LCNT = ROUNDUP_DIVISION(4700 * 2 * i2c_clock, 1000);    // set low period of SCL 4700 * 2 ns
                }

            }
            else if (ptr_i2cController->parameter.master.speed == I2C_Fast_Speed)  // fast speed
            {

                i2c_reg->IC_SDA_HOLD = 0x30; 
                i2c_reg->IC_SDA_SETUP = 0x30;
                i2c_reg->IC_FS_SPKLEN = 0x10;
/*
                i2c_reg->IC_CON &= ~((3<<3) | (3<<1));      // [4]:addr_mst in 7-bit; [3]:addr_slv in 7-bit; [2:1]=2,fast mode;
                i2c_reg->IC_CON |= (5<<0 | 3<<5);       // [2]; [0]:enable master-mode;[6]:disbale i2c slave-only mode; [5]:enable ic_restart
*/
		        i2c_reg->IC_CON = 0x65;

                if(0 != ptr_i2cController->parameter.master.hcnt_percent && 0 != ptr_i2cController->parameter.master.lcnt_percent)
                {
                    uint32_t tmp_hcnt_per = ptr_i2cController->parameter.master.hcnt_percent;
                    uint32_t tmp_lcnt_per = ptr_i2cController->parameter.master.lcnt_percent;
                    uint32_t tmp_total = ptr_i2cController->parameter.master.hcnt_percent + ptr_i2cController->parameter.master.lcnt_percent;
                    i2c_reg->IC_FS_SCL_HCNT = ROUNDUP_DIVISION(1900 * 2 * i2c_clock, 1000) * tmp_hcnt_per / tmp_total;
                    i2c_reg->IC_FS_SCL_LCNT = ROUNDUP_DIVISION(1900 * 2 * i2c_clock, 1000) * tmp_lcnt_per / tmp_total;
                }
                else
                {
                    i2c_reg->IC_FS_SCL_HCNT = ROUNDUP_DIVISION(600 * 2 * i2c_clock, 1000);         // set high period of SCL 600 * 2 ns
                    i2c_reg->IC_FS_SCL_LCNT = ROUNDUP_DIVISION(600 * 2 * i2c_clock, 1000);        // set low period of SCL 1300 * 2 ns
                }
            }
            else if (ptr_i2cController->parameter.master.speed == I2C_High_Speed)  // high mode
            {
                i2c_reg->IC_SDA_HOLD = 0x5;
                i2c_reg->IC_SDA_SETUP = 0x5;
                i2c_reg->IC_FS_SPKLEN = 0x1;
/*
                i2c_reg->IC_CON &= ~((3<<3) | (3<<1));             // [4]:addr_mst in 7-bit; [3]:addr_slv in 7-bit; [2:1]=11,high speed mode;
                i2c_reg->IC_CON |= (7<<0 | 3<<5);       // [2:1]=0x11; [0]:enable master-mode;[6]:disbale i2c slave-only mode; [5]:enable ic_restart
*/
		        i2c_reg->IC_CON = 0x67;

                if(0 != ptr_i2cController->parameter.master.hcnt_percent && 0 != ptr_i2cController->parameter.master.lcnt_percent)
                {
                    uint32_t tmp_hcnt_per = ptr_i2cController->parameter.master.hcnt_percent;
                    uint32_t tmp_lcnt_per = ptr_i2cController->parameter.master.lcnt_percent;
                    uint32_t tmp_total = ptr_i2cController->parameter.master.hcnt_percent + ptr_i2cController->parameter.master.lcnt_percent;
                    i2c_reg->IC_HS_SCL_HCNT = ROUNDUP_DIVISION(480 * 2 * i2c_clock, 1000) * tmp_hcnt_per / tmp_total;
                    i2c_reg->IC_HS_SCL_LCNT = ROUNDUP_DIVISION(480 * 2 * i2c_clock, 1000) * tmp_lcnt_per / tmp_total;
                }
                else
                {
                    i2c_reg->IC_HS_SCL_HCNT = ROUNDUP_DIVISION(160 * 2 * i2c_clock, 1000);         // set high period of SCL 160 * 2 ns
                    i2c_reg->IC_HS_SCL_LCNT = ROUNDUP_DIVISION(320 * 2 * i2c_clock, 1000);         // set low period of SCL 320 * 2 ns
                }

            }
            else if (ptr_i2cController->parameter.master.speed == I2C_Custom_Fast_Speed)
            {

/*
                i2c_reg->IC_CON &= ~(3<<3 | 1<<1);      // [4]:addr_mst in 7-bit; [3]:addr_slv in 7-bit; [2:1]=2,fast mode;
                i2c_reg->IC_CON |= (5<<0 | 3<<5);       // [2]; [0]:enable master-mode;[6]:disbale i2c slave-only mode; [5]:enable ic_restart
*/

                i2c_reg->IC_SDA_HOLD = 0x30; 
                i2c_reg->IC_SDA_SETUP = 0x30;
                i2c_reg->IC_FS_SPKLEN = 0x10;
		        i2c_reg->IC_CON = 0x65;

                i2c_reg->IC_FS_SCL_HCNT = ptr_i2cController->parameter.master.hcnt_percent;
                i2c_reg->IC_FS_SCL_LCNT = ptr_i2cController->parameter.master.lcnt_percent;
            }

            i2c_reg->IC_TAR = ptr_i2cController->parameter.master.addr;  // set address of target slave

            if(0 != ptr_i2cController->parameter.master.fs_spklen)
            {
                i2c_reg->IC_FS_SPKLEN = ptr_i2cController->parameter.master.fs_spklen;
            }
            else
            {
                i2c_reg->IC_FS_SPKLEN = 0x1;                // set the min spike suppression limit
            }

            i2c_reg->IC_INTR_MASK = 0; // mask all i2c interrupt.
            i2c_reg->IC_TX_TL = IC_TX_TL_DEF_VALUE;                   // set TX fifo threshold level
            i2c_reg->IC_RX_TL = IC_RX_TL_DEF_VALUE;                   // set RX fifo threshold level --for as a receiver

            i2c_reg->IC_ENABLE |= 0x01;                 // enable the i2c
        }
        else if (ptr_i2cController->en_i2cMode == I2C_Slave_Mode)
        {
            /* i2c slave initialization */
            
            i2c_reg->IC_ENABLE &= ~(0x1);                              // disable i2c

            i2c_reg->IC_SAR  = ptr_i2cController->parameter.slave.addr;   // set the slave address
            i2c_reg->IC_FS_SPKLEN = 0x1;                // set the min spike suppression limit
            i2c_reg->IC_CON &= ~(3<<3 | 1<<6 | 3<<0);   // [4],[3]:support 7-bit address; [6]:enbale i2c slave-only mode; [0]:disable master-mode
            i2c_reg->IC_CON |= (1<<2 | 1<<5);           // [5]:enable the restart mode; [2:1]=2, fast mode

            // i2c slave config
            i2c_reg->IC_INTR_MASK = 0; // mask all i2c interrupt.

            i2c_reg->IC_ENABLE |= 0x1;                  // enable i2c
        }
    }
    //SysTicks_DelayUS(500);
}

STRU_I2C_Controller* I2C_LL_GetI2CController(EN_I2C_COMPONENT en_i2cComponent)
{
    STRU_I2C_Controller* ptr_i2cController = NULL;

    if (en_i2cComponent < sizeof(stru_i2cControllerArray)/sizeof(stru_i2cControllerArray[0]))
    {
        ptr_i2cController = &stru_i2cControllerArray[en_i2cComponent];
    }
    
    return ptr_i2cController;
}

uint8_t I2C_LL_IOCtl(STRU_I2C_Controller* ptr_i2cController, ENUM_I2C_CMD_ID en_i2cCommandID, uint32_t* ptr_i2cCommandVal)
{
    uint32_t u32_value;
    
    if (ptr_i2cController == NULL)
    {
        DLOG_Error("ptr_i2cController = %p\n", ptr_i2cController);
        return FALSE;
    }

    if (ptr_i2cCommandVal == NULL)
    {
        DLOG_Error("ptr_i2cCommandVal = %p\n", ptr_i2cCommandVal);
        return FALSE;
    }
    
    volatile STRU_I2C_Type* i2c_reg = (volatile STRU_I2C_Type*)ptr_i2cController->u32_i2cRegBaseAddr;

    if (i2c_reg == NULL)
    {
        DLOG_Error("i2c_reg = %p\n", i2c_reg);
        return FALSE;
    }

    switch(en_i2cCommandID)
    {
        case I2C_CMD_SET_MODE:
            ptr_i2cController->en_i2cMode = (ENUM_I2C_Mode)(*ptr_i2cCommandVal);
            I2C_LL_RefreshConfigRegisters(ptr_i2cController);
            break;
        case I2C_CMD_SET_M_SPEED:
            ptr_i2cController->parameter.master.speed = (ENUM_I2C_Speed)(*ptr_i2cCommandVal);
            break;
        case I2C_CMD_SET_M_TARGET_ADDRESS:
            if (ptr_i2cController->parameter.master.addr != (uint16_t)(*ptr_i2cCommandVal))
            {
                uint16_t u16_tmpCommandVal = (uint16_t)(*ptr_i2cCommandVal);
                if (ptr_i2cController->parameter.master.addr != 0)    // Run-time target address change
                {
                    ptr_i2cController->parameter.master.addr = u16_tmpCommandVal;
                    I2C_LL_RefreshConfigRegisters(ptr_i2cController);
                }
                else    // Initial target address change
                {
                    ptr_i2cController->parameter.master.addr = u16_tmpCommandVal;
                }
            }
            break;
        case I2C_CMD_SET_M_WRITE_DATA:
            if (ptr_i2cController->en_i2cMode == I2C_Master_Mode)
            {
                unsigned int pre_rd;
                unsigned int data = (*ptr_i2cCommandVal) & 0xFF;
                pre_rd = i2c_reg->IC_DATA_CMD;
                pre_rd = pre_rd & 0xfe000;              // Write enable, IC_DATA_CMD[8]=0x0
                data |= pre_rd;
                i2c_reg->IC_DATA_CMD = data;
            }
            else
            {
                // DLOG_Warning("Error: Write data in slave I2C mode!");
                return FALSE;
            }
            break;
        case I2C_CMD_SET_M_READ_LAUNCH:
            if (ptr_i2cController->en_i2cMode == I2C_Master_Mode)
            {
                i2c_reg->IC_DATA_CMD |= (1<<8);         // Read enable, IC_DATA_CMD[8]=0x1
            }
            else
            {
                // DLOG_Warning("Error: Read data in slave I2C mode!");
                return FALSE;
            }
            break;
        case I2C_CMD_SET_RX_TL:
            i2c_reg->IC_RX_TL = (*ptr_i2cCommandVal);
            break;
        case I2C_CMD_SET_INTR_ENABLE:
            u32_value = i2c_reg->IC_INTR_MASK;
            i2c_reg->IC_INTR_MASK = (u32_value | (*ptr_i2cCommandVal));
            break;
        case I2C_CMD_SET_INTR_DISENABLE:
            u32_value = i2c_reg->IC_INTR_MASK;
            i2c_reg->IC_INTR_MASK = (u32_value & (~(*ptr_i2cCommandVal)));
            break;
        case I2C_CMD_SET_M_HCNT:
            ptr_i2cController->parameter.master.hcnt_percent = (*ptr_i2cCommandVal) & 0xffff;
            break;
        case I2C_CMD_SET_M_LCNT:
            ptr_i2cController->parameter.master.lcnt_percent = (*ptr_i2cCommandVal) & 0xffff;
            break;
        case I2C_CMD_SET_M_FS_SPKLEN:
            ptr_i2cController->parameter.master.fs_spklen = (*ptr_i2cCommandVal) & 0xff;
            break;
        case I2C_CMD_GET_M_TX_FIFO_LENGTH:
            if (ptr_i2cController->en_i2cMode == I2C_Master_Mode)
            {
                /* Read data */
                *ptr_i2cCommandVal = i2c_reg->IC_TXFLR;
            }
            else
            {
                // DLOG_Warning("Error: Read TX fifo length in slave I2C mode!");
                return FALSE;
            }
            break;
        case I2C_CMD_GET_M_RX_FIFO_LENGTH:
            if (ptr_i2cController->en_i2cMode == I2C_Master_Mode)
            {
                /* Read data */
                *ptr_i2cCommandVal = i2c_reg->IC_RXFLR;
            }
            else
            {
                // DLOG_Warning("Error: Read RX fifo length in slave I2C mode!");
                return FALSE;
            }
            break;
        case I2C_CMD_GET_M_RX_FIFO_DATA:
            if (ptr_i2cController->en_i2cMode == I2C_Master_Mode)
            {
                /* Read data */
                *ptr_i2cCommandVal = i2c_reg->IC_DATA_CMD & 0xFF;
            }
            else
            {
                // DLOG_Warning("Error: Read data in slave I2C mode!");
                return FALSE;
            }
            break;
        case I2C_CMD_GET_M_IDLE:
            *ptr_i2cCommandVal =  i2c_reg->IC_STATUS & (1 << 5) ? I2C_MASTER_ACTIVE : I2C_MASTER_IDLE; 
            break;
        case I2C_CMD_GET_INTR_STAT:
            *ptr_i2cCommandVal = i2c_reg->IC_INTR_STAT; 
            break;
        case I2C_CMD_SET_S_SLAVE_ADDRESS:
            ptr_i2cController->parameter.slave.addr = (uint16_t)(*ptr_i2cCommandVal);
            break;
        case I2C_CMD_GET_IC_CLR_TX_ABRT:
            *ptr_i2cCommandVal = i2c_reg->IC_CLR_TX_ABRT; // Clear TX_ABRT Interrupt Register
            break;
        case I2C_CMD_GET_IC_TX_ABRT_SOURCE:
            *ptr_i2cCommandVal = i2c_reg->IC_TX_ABRT_SOURCE; // I2C Transmit Abort Source Register
            break;
        default:
            return FALSE;
    }
    
    return TRUE;
}

void I2C_LL_Delay(unsigned int delay)
{
    volatile int i = delay;
    while(i > 0)
    {
        i--;
    }
}



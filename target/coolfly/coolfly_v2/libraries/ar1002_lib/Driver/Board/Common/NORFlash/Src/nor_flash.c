#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "data_type.h"
#include "quad_spi_ctrl.h"
#include "nor_flash.h"
#include "debuglog.h"
#include "mpu.h"
#include "image_struct.h"
#include "hal_gpio.h"
#include "hal.h"

#define             BOOT_UPGRADE_OPEN           1
#define             BOOT_UPGRADE_CLOSE          0

#define WP_CTRL_GPIO_NUM 105 // no used

struct spi_flash    g_norflash;
uint32_t            g_protect_size = MIN_PROTECT_SIZE;
uint8_t             u8_WP_Disable_Flag = 0;
volatile uint8_t    u8_Boot_Upgrade_Flag = BOOT_UPGRADE_CLOSE;

extern const struct spi_flash_info spi_flash_ids[];

void NOR_FLASH_SetFlashDisableFlag(uint8_t flag)
{
    u8_WP_Disable_Flag = flag;
}

uint8_t NOR_FLASH_GetFlashDisableFlag()
{
    return u8_WP_Disable_Flag;
}

void NOR_FLASH_BootUpgradeEnable()
{
    u8_Boot_Upgrade_Flag = BOOT_UPGRADE_OPEN;
}

void NOR_FLASH_BootUpgradeDisable()
{
    u8_Boot_Upgrade_Flag = BOOT_UPGRADE_CLOSE;
}

static const struct spi_flash_info * NOR_FLASH_ReadId(void)
{
    uint8_t                         id[SPI_FLASH_MAX_ID_LEN];
    const struct spi_flash_info    *info;

    QUAD_SPI_ReadJEDECID(id, SPI_FLASH_MAX_ID_LEN);

    info = spi_flash_ids;
    for (; info->name != NULL; info++)
    {
        if (info->id_len)
        {
            if (!memcmp(info->id, id, info->id_len))
                return info;
        }
    }

     DLOG_Error("SF: unrecognized JEDEC id bytes: %02x, %02x, %02x",
                  id[0], id[1], id[2]);

    return NULL;
}



/*Winbond, GIGADEVICE*/
static void NOR_FLASH_Common_WPEnable(struct spi_flash flash_status, uint8_t enable_flag)
{
    uint32_t u32_reg = 0;

    /////////////////////////Write S1//////////////////////
    if(0 != flash_status.s1_map)
    {
        QUAD_SPI_WriteEnable();
        QUAD_SPI_CheckBusy();

        u32_reg =  QUAD_SPI_ReadStatusReg1();
        if(1 == enable_flag)
        {
            u32_reg |= flash_status.s1_map;
        }
        else
        {
            u32_reg &= (~flash_status.s1_wp_map);
        }
        QUAD_SPI_SetStatusReg1(u32_reg);

        QUAD_SPI_CheckBusy();
    }

    /////////////////////////Write S2///////////////////////
    if(0 != flash_status.s2_map)
    {
        QUAD_SPI_WriteEnable();
        QUAD_SPI_CheckBusy();

        u32_reg =  QUAD_SPI_ReadStatusReg2();
        if(1 == enable_flag)
        {
            u32_reg |= flash_status.s2_map;
        }
        else
        {
            u32_reg &= (~flash_status.s2_wp_map);
        }
        QUAD_SPI_SetStatusReg2(u32_reg);

        QUAD_SPI_CheckBusy();
    }
}

/* Macronix */
static void NOR_FLASH_Macrnix_WPEnable(struct spi_flash flash_status, uint8_t enable_flag)
{
    uint32_t u32_reg1 = 0;
    uint32_t u32_reg2 = 0;

    /////////////////////////Only Write S1//////////////////////
    if(0 != flash_status.s1_map && 0 == flash_status.s2_map)
    {
        QUAD_SPI_WriteEnable();
        QUAD_SPI_CheckBusy();

        u32_reg1 =  QUAD_SPI_ReadStatusReg1();
        if(1 == enable_flag)
        {
            u32_reg1 |= flash_status.s1_map;
        }
        else
        {
            u32_reg1 &= (~flash_status.s1_wp_map);
        }
        QUAD_SPI_SetStatusReg1(u32_reg1);

        QUAD_SPI_CheckBusy();
    }
    else if(0 != flash_status.s1_map || 0 != flash_status.s2_map)
    {
        /////////////////////////Write S1 or Write S2///////////////////////
        QUAD_SPI_WriteEnable();
        QUAD_SPI_CheckBusy();

        u32_reg1 =  QUAD_SPI_ReadStatusReg1();
        if(1 == enable_flag)
        {
            u32_reg1 |= flash_status.s1_map;
        }
        else
        {
            u32_reg1 &= (~flash_status.s1_wp_map);
        }

        u32_reg2 =  QUAD_SPI_ReadStatusReg2();
        if(1 == enable_flag)
        {
            u32_reg2 |= flash_status.s2_map;
        }
        else
        {
            u32_reg2 &= (~flash_status.s2_wp_map);
        }

        QUAD_SPI_SetStatusReg2(u32_reg2 << 8 | u32_reg1);

        QUAD_SPI_CheckBusy();
    }
}

uint8_t NOR_FLASH_WP_Enable(struct spi_flash flash_status, uint8_t enable_flag, uint32_t start_addr, uint32_t size)
{
    if(1 == enable_flag && 1 == u8_WP_Disable_Flag)
    {
        return 1;// Can't enable WP
    }

    if((NULL == flash_status.name) || (0 == g_norflash.protect_end))
    {
        return 0;// Because cannot unrecognized flash, so no protect
    }

    if((start_addr > flash_status.protect_end) || (start_addr + size < flash_status.protect_start))
    {
        //DLOG_Info("Out of protect zone");
        return 0;// Out of protection zone
    }

    switch(flash_status.id[0])
    {
        case SPI_FLASH_MFR_GIGADEVICE:
            NOR_FLASH_Common_WPEnable(flash_status, enable_flag);
            break;

        case SPI_FLASH_MFR_XD:
            NOR_FLASH_Common_WPEnable(flash_status, enable_flag);
            break;

        case SPI_FLASH_MFR_MACRONIX:
            NOR_FLASH_Macrnix_WPEnable(flash_status, enable_flag);
            break;

        case SPI_FLASH_MFR_WINBOND:
            NOR_FLASH_Common_WPEnable(flash_status, enable_flag);
            break;

        case SPI_FLASH_PUYA_SEMI:
            NOR_FLASH_Common_WPEnable(flash_status, enable_flag);
            break;

        default:
            DLOG_Error("Not support Manufacturer id:%d", flash_status.id[0]);
            return 1;
    }

    return 0;
}

void NOR_FLASH_Init(void)
{
    const struct spi_flash_info * info;
    MPU_QuadspiProtectDisable();

    memset(&g_norflash, 0, sizeof(struct spi_flash));

    //05h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_0, 0x001c14, 0x700);
    //35h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_1, 0x001cd4, 0x700);
    //15h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_2, 0x001c54, 0x700);
    //01h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_3, 0x609c04, 0x700);
    //31h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_4, 0x609cc4, 0x700);
    //11h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_5, 0x609c44, 0x700);
    //04h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_6, 0x609c10, 0x0);
    //06h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_7, 0x609c18, 0x0);
    //50h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_8, 0x609d40, 0x0);
    //90h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_9, 0x401e40, 0x3c1700);
    //9Fh
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_10, 0x401e7c, 0x1700);
    //C7h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_11, 0x409f1c, 0x0);
    //20h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_16, 0x609c80, 0x17);
    //D8h
    QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_17, 0x609f60, 0x17);
    //4Bh
    //QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_12, 0x601D2C, 0xf83f00);

    info = NOR_FLASH_ReadId();
    if(info != NULL)
    {
	//MACRONIX read S2 cmd 15h, write S2 cmd 01h + s1 + s2
        if(SPI_FLASH_MFR_MACRONIX == info->id[0])//MFR:MACRONIX
        {
            //15h(read S2)
            QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_1, 0x001c54, 0x700);//replace read S2 cmd form 35h to 15h
            //01h + S1 + S2(write S2)
            QUAD_SPI_UpdateInstruct(QUAD_SPI_INSTR_4, 0x609c04, 0xf00);//replace write S2 cmd form 31h to 01h + S1 + S2
        }

        g_norflash.name = info->name;
        memcpy(g_norflash.id, info->id, SPI_FLASH_MAX_ID_LEN);
        g_norflash.size = info->sector_size * info->n_sectors;
		
        if(g_norflash.size >= g_protect_size)
        {	
            uint32_t s1_tmp, s2_tmp;
            g_norflash.protect_start = info->protect_start;
#ifndef UPGRADE_DUAL_APP_DESIGN_EN	    
            g_norflash.protect_end = info->protect_end;
#else
	    //g_norflash.protect_end = info->protect_end;
            g_norflash.protect_end = (g_norflash.size >= 0x800000) ? (0x7fffff) : info->protect_end;             
#endif
            g_norflash.flags = info->flags;
            g_norflash.s1_map = info->s1_map;
            g_norflash.s2_map = info->s2_map;
            g_norflash.s1_wp_map = info->s1_wp_map;
            g_norflash.s2_wp_map = info->s2_wp_map;

            s1_tmp = NOR_FLASH_ReadStatusReg1();
            s2_tmp = NOR_FLASH_ReadStatusReg2();

            if((s1_tmp != 0 && (s1_tmp & g_norflash.s1_wp_map) != g_norflash.s1_map) ||
                (s2_tmp != 0 && (s2_tmp & g_norflash.s2_wp_map) != g_norflash.s2_map))
            {
                HAL_GPIO_SetMode(WP_CTRL_GPIO_NUM,HAL_GPIO_PIN_MODE2);
                HAL_GPIO_OutPut(WP_CTRL_GPIO_NUM);
                HAL_GPIO_SetPin(WP_CTRL_GPIO_NUM, 1);
                NOR_FLASH_SetStatusReg1(g_norflash.s1_map);
                NOR_FLASH_SetStatusReg2(g_norflash.s2_map);
                HAL_GPIO_SetPin(WP_CTRL_GPIO_NUM, 0);

                MPU_QuadspiProtectDisable();
                DLOG_Critical("WP register no match reset all WP register! S1_REG:%lx,S2_REG:%lx",s1_tmp,s2_tmp);
            }
            
            if(0 == NOR_FLASH_WP_Enable(g_norflash, 1, g_norflash.protect_start, 0))
            {
                DLOG_Critical("*********************************************");
                DLOG_Critical("WP Enable");
                DLOG_Critical("Flash JEDEC ID:0x%02x 0x%02x 0x%02x, Name:%s",
                              g_norflash.id[0], g_norflash.id[1], g_norflash.id[2], g_norflash.name);
                DLOG_Critical("Protect Zone:0x%02lx - 0x%02lx", g_norflash.protect_start, g_norflash.protect_end);
                DLOG_Critical("S1 MAP:0x%02x, S2 MAP:0x%02x", g_norflash.s1_map, g_norflash.s2_map);
                DLOG_Critical("WP MAP:0x%02x, WP MAP:0x%02x", g_norflash.s1_wp_map, g_norflash.s2_wp_map);
                DLOG_Critical("*********************************************");
            }
            else
            {
                NOR_FLASH_SetFlashDisableFlag(1);
                DLOG_Critical("WP Enable fail");
            }
        }
    }
    else
    {
        NOR_FLASH_SetFlashDisableFlag(1);
        DLOG_Error("Can't Protect the flash");
    }

    MPU_QuadspiProtectEnable();


}

static int8_t NOR_FLASH_Assert(uint32_t flash_start_addr, uint32_t size)
{
    if (flash_start_addr < BOOT_INFO_OFFSET && BOOT_UPGRADE_CLOSE == u8_Boot_Upgrade_Flag)
    {
        DLOG_Error("flash protect sector");
        return FALSE;
    }
    /*else if ((flash_start_addr < APP_ADDR_OFFSET) && (flash_start_addr > (BOOT_ADDR1-FLASH_BASE_ADDR)))
    {
        DLOG_Error("flash protect sector");
        return FALSE;
    }*/
    else if(g_norflash.name != NULL && (flash_start_addr + size >= g_norflash.size))
    {
        DLOG_Error("flash address out of flash size");
        return FALSE;
    }
    return TRUE;
}

void NOR_FLASH_WriteEnable(uint32_t start_addr, uint32_t size)
{
    MPU_QuadspiProtectDisable();

    NOR_FLASH_WP_Enable(g_norflash, 0, start_addr, size);

    QUAD_SPI_WriteEnable();
    QUAD_SPI_CheckBusy();
    return;
}

void NOR_FLASH_WriteDisable(uint32_t start_addr, uint32_t size)
{
    QUAD_SPI_CheckBusy();

    NOR_FLASH_WP_Enable(g_norflash, 1, start_addr, size);

    QUAD_SPI_WriteDisable();
    QUAD_SPI_CheckBusy();
    MPU_QuadspiProtectEnable();
    return;
}



uint8_t NOR_FLASH_EraseSector(uint32_t flash_start_addr)
{
    uint32_t sector_size = 0x1000;

    if (FALSE == NOR_FLASH_Assert(flash_start_addr, sector_size))
    {
        return FALSE;
    }
    if ((flash_start_addr % sector_size) != 0)
    {
        DLOG_Error("The w25q128 sector erase address is not sector aligned!");
        return FALSE;
    }

    NOR_FLASH_WriteEnable(flash_start_addr, sector_size);
    QUAD_SPI_SectorErase(flash_start_addr);
    NOR_FLASH_WriteDisable(flash_start_addr, sector_size);

    return TRUE;
}

uint8_t NOR_FLASH_EraseBlock(uint32_t flash_start_addr)
{
    uint32_t sector_size = 0x10000;

    if (FALSE == NOR_FLASH_Assert(flash_start_addr, sector_size))
    {
        return FALSE;
    }
    if ((flash_start_addr % sector_size) != 0)
    {
        DLOG_Error("The w25q128 block erase address is not block aligned!");
        return FALSE;
    }

    NOR_FLASH_WriteEnable(flash_start_addr, sector_size);
    QUAD_SPI_BlockErase(flash_start_addr);
    NOR_FLASH_WriteDisable(flash_start_addr, sector_size);

    return TRUE;
}

uint8_t NOR_FLASH_EraseChip(void)
{

    NOR_FLASH_WriteEnable(g_norflash.protect_start, 0);
    QUAD_SPI_ChipErase();
    NOR_FLASH_WriteDisable(g_norflash.protect_start, 0);

    return TRUE;
}



void NOR_FLASH_WriteByteBuffer(uint32_t start_addr, uint8_t* data_buf, uint32_t size)
{
    if (FALSE == NOR_FLASH_Assert(start_addr, size))
    {
        return ;
    }

    NOR_FLASH_WriteEnable(start_addr, size);

    QUAD_SPI_WriteBlockByByte(start_addr, data_buf, size);

    NOR_FLASH_WriteDisable(start_addr, size);
}

void NOR_FLASH_WriteHalfWordBuffer(uint32_t start_addr, uint16_t* data_buf, uint32_t size)
{
    if (FALSE == NOR_FLASH_Assert(start_addr, size))
    {
        return ;
    }

    NOR_FLASH_WriteEnable(start_addr, size);

    QUAD_SPI_WriteBlockByHalfWord(start_addr, data_buf, size);

    NOR_FLASH_WriteDisable(start_addr, size);
}

void NOR_FLASH_WriteWordBuffer(uint32_t start_addr, uint32_t* data_buf, uint32_t size)
{
    if (FALSE == NOR_FLASH_Assert(start_addr, size))
    {
        return ;
    }

    NOR_FLASH_WriteEnable(start_addr, size);

    QUAD_SPI_WriteBlockByWord(start_addr, data_buf, size);

    NOR_FLASH_WriteDisable(start_addr, size);
}



void NOR_FLASH_ReadByteBuffer(uint32_t start_addr, uint8_t* data_buf, uint32_t size)
{

    QUAD_SPI_ReadBlockByByte(start_addr, data_buf, size);
}



uint32_t NOR_FLASH_ReadStatusReg1(void)
{
    return QUAD_SPI_ReadStatusReg1();
}

uint32_t NOR_FLASH_ReadStatusReg2(void)
{
    return QUAD_SPI_ReadStatusReg2();
}



void NOR_FLASH_SetStatusReg1(uint8_t flag)
{
    MPU_QuadspiProtectDisable();
    QUAD_SPI_WriteEnable();
    QUAD_SPI_CheckBusy();

    QUAD_SPI_SetStatusReg1(flag);

    QUAD_SPI_CheckBusy();
    QUAD_SPI_WriteDisable();
    MPU_QuadspiProtectEnable();
}

void NOR_FLASH_SetStatusReg2(uint8_t flag)
{
    MPU_QuadspiProtectDisable();
    QUAD_SPI_WriteEnable();
    QUAD_SPI_CheckBusy();

    if(SPI_FLASH_MFR_MACRONIX == g_norflash.id[0])//MFR:MACRONIX
    {
        uint16_t s1 = QUAD_SPI_ReadStatusReg1();
        uint16_t s2 = flag;
        QUAD_SPI_SetStatusReg2(s2 << 8 | s1);
    }
    else
    {
        QUAD_SPI_SetStatusReg2(flag);
    }   

    QUAD_SPI_CheckBusy();
    QUAD_SPI_WriteDisable();
    MPU_QuadspiProtectEnable();
}



void NOR_FLASH_ReadManuDeviceID(uint8_t* data_buf, uint8_t buflen)
{
    QUAD_SPI_ReadManuDeviceID(data_buf, buflen);

}

void NOR_FLASH_ReadJEDECID(uint8_t* data_buf, uint8_t buflen)
{
    QUAD_SPI_ReadJEDECID(data_buf, buflen);
}

/*void NOR_FLASH_ReadProductID(uint8_t* data_buf)
{
    QUAD_SPI_ReadProductID(data_buf);
}*/


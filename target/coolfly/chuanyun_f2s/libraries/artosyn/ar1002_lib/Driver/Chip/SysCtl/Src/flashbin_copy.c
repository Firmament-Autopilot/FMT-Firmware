#include "inter_core.h"
#include "debuglog.h"
#include "interrupt.h"
#include "string.h"
#include "ar8020.h"
#include "sys_event.h"
#include "lock.h"
#include "cpu_info.h"
#include "mpu.h"
#include "cfg_parser.h"
#include "timer.h"
#include "reg_rw.h"
#include "image_struct.h"
#include "core_cm7.h"
#include "factory.h"
#include "quad_spi_ctrl.h"


void InterCore_CopyConfigureFormFlashToSRAM(void)
{
    if (CPUINFO_GetLocalCpuId() != ENUM_CPU0_ID)
    {
        return;
    }
    uint32_t u32_appStartAddr = 0;
    uint8_t* p8_sizeAddr   = NULL;
    uint32_t u32_imageSize = 0;
    STRU_Boot_Info st_bootInfo;
    QUAD_SPI_ReadBlockByByte(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),sizeof(st_bootInfo));
    if ((st_bootInfo.checkSum == (st_bootInfo.success_boot + st_bootInfo.success_app)) && (st_bootInfo.success_app == 0))
    {
        //sky mode
        p8_sizeAddr   = (uint8_t*)(APPLICATION_IMAGE_START0+IMAGE_HAER_IMAGE_SIZE_OFFSET);
        u32_imageSize = GET_WORD_FROM_ANY_ADDR(p8_sizeAddr)-IMAGE_HAER_LENGTH;
        uint32_t u32_cpu2Mode = Reg_Read32(0x40B00068); 
        if (0x01 == (u32_cpu2Mode & 0x3))
        {
            u32_appStartAddr = APPLICATION_IMAGE_START0;
        }
        else if (0x03 == (u32_cpu2Mode & 0x3))//ground mode
        {
            u32_appStartAddr = APPLICATION_IMAGE_START0+IMAGE_HAER_LENGTH+u32_imageSize;
        } 
    }
    else
    {
#ifndef UPGRADE_DUAL_APP_DESIGN_EN
        u32_appStartAddr = APPLICATION_IMAGE_START1;
#else
        //sky mode
        p8_sizeAddr   = (uint8_t*)(APPLICATION_IMAGE_START1+IMAGE_HAER_IMAGE_SIZE_OFFSET);
        u32_imageSize = GET_WORD_FROM_ANY_ADDR(p8_sizeAddr)-IMAGE_HAER_LENGTH;
        uint32_t u32_cpu2Mode = Reg_Read32(0x40B00068); 
        if (0x01 == (u32_cpu2Mode & 0x3))
        {
            u32_appStartAddr = APPLICATION_IMAGE_START1;
        }
        else if (0x03 == (u32_cpu2Mode & 0x3))//ground mode
        {
            u32_appStartAddr = APPLICATION_IMAGE_START1+IMAGE_HAER_LENGTH+u32_imageSize;
        } 
#endif
    }

    uint8_t* cpu0_app_size_addr = (uint8_t*)(u32_appStartAddr + IMAGE_HAER_LENGTH);
    uint32_t cpu0_app_size = GET_WORD_FROM_ANY_ADDR(cpu0_app_size_addr);    
    uint32_t cpu0_app_start_addr = u32_appStartAddr + IMAGE_HAER_LENGTH + 4;

    uint8_t* cpu1_app_size_addr = (uint8_t*)(cpu0_app_start_addr + cpu0_app_size);
    uint32_t cpu1_app_size = GET_WORD_FROM_ANY_ADDR(cpu1_app_size_addr);
    
    uint32_t cpu1_app_start_addr = cpu0_app_start_addr + cpu0_app_size + 4;

    uint8_t* cpu2_app_size_addr = (uint8_t*)(cpu1_app_start_addr + cpu1_app_size);
    uint32_t cpu2_app_size = GET_WORD_FROM_ANY_ADDR(cpu2_app_size_addr);
    uint32_t cpu2_app_start_addr = cpu1_app_start_addr + cpu1_app_size + 4;

    //itcm extension size = 0x6000,
    uint32_t itcm2_extension_flash_start_addr = cpu2_app_start_addr + cpu2_app_size;  //flash start address
    uint32_t dtcm2_addr = 0xB008A000;
    uint32_t itcm2_extension_section_size = 0x6000;
    memcpy((void *)dtcm2_addr, (void *)itcm2_extension_flash_start_addr, itcm2_extension_section_size);
    
    //clean cache: write cache datum to DTCM2
    SCB_CleanDCache_by_Addr((uint32_t *)0xB008A000, itcm2_extension_section_size);

    //copy cfg data to sram
    uint32_t configure_start_addr = (itcm2_extension_flash_start_addr + itcm2_extension_section_size + (4-(cpu2_app_start_addr + cpu2_app_size)%4));
    CFGBIN_LoadFromFlash(SRAM_CONFIGURE_MEMORY_ST_ADDR, configure_start_addr);

    FCT_Load2Sram();
}

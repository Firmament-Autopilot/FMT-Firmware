#include <stdint.h>
#include <string.h>

#include "interrupt.h"
#include "debuglog.h"

#include "hal_ret_type.h"
#include "hal_nvic.h"
#include "hal_norflash.h"
#include "hal_uart.h"

#include "md5.h"
#include "efuse.h"
 
#include "image_struct.h"

static uint32_t s_u32_imageSize = 0;
static uint8_t s_u8_imageMd5sumArray[2][MD5_SIZE] = {0};

int8_t UPGRADE_MD5SUM(uint32_t u32_addr, uint8_t u8_flag)
{
    uint32_t i=0;
    // uint32_t j=0;
    uint8_t  md5_value[MD5_SIZE];
    MD5_CTX md5;
    MD5Init(&md5);

    uint8_t  *p8_data;
    uint8_t* p8_sizeAddr;
    // uint32_t u32_RecCountTmp;
    uint8_t* p8_md5Addr;
    uint8_t* p8_encryptMd5Addr;

    // int8_t ret = -1;
    if (1 == u8_flag)
    {
        //encrypt
        p8_sizeAddr = (uint8_t*)(u32_addr);
        if(0 == GET_WORD_FROM_ANY_ADDR(p8_sizeAddr))
        {
            DLOG_Error("image size is zero\n");
            return -1;
        }
        s_u32_imageSize=GET_WORD_FROM_ANY_ADDR(p8_sizeAddr) - IMAGE_HEAD;
        p8_data = (uint8_t *)(u32_addr+IMAGE_HEAD);
        p8_md5Addr = (uint8_t*)(u32_addr+IMAGE_MD5SUMOFFSET);
        memcpy(&s_u8_imageMd5sumArray[1], p8_md5Addr, MD5_SIZE);
        p8_encryptMd5Addr = (uint8_t*)(u32_addr+IMAGE_ENCRYPTMD5SUMOFFSET);
        memcpy(&s_u8_imageMd5sumArray[0], p8_encryptMd5Addr, MD5_SIZE);
    }
    else
    {
        //decrypt
        p8_data = (uint8_t *)(u32_addr);
    }

     
    MD5Update(&md5, p8_data, s_u32_imageSize);
     

    MD5Final(&md5, md5_value);

    if (0 != memcmp(md5_value, &s_u8_imageMd5sumArray[u8_flag], MD5_SIZE))
    {
        for(i=0;i<MD5_SIZE;i++)
        {
            DLOG_Error("cmp %02x %02x\n",md5_value[i],s_u8_imageMd5sumArray[u8_flag][i]);
        }
        DLOG_Error("checksum......fail\n");
        return -1;

    }
    else
    {
        DLOG_Critical("checksum......ok\n");
        DLOG_Output(100);
        return 0;
    }

    //DLOG_Output(100);
    return 0;
}

void UPGRADE_EraseWriteFlash(uint32_t u32_flashAddress, uint32_t u32_upgradeDataAddress, uint32_t u32_imageSize)
{
    uint8_t *pu8_upgradeDataAddr = (uint8_t *)u32_upgradeDataAddress;
    // uint32_t i=0;
    uint32_t u32_dataSize = u32_imageSize;
    uint32_t u32_flashAddr = u32_flashAddress;

    //wirte HAL_NORFLASH_Sector data for aligned  HAL_NORFLASH_Block
    do
    {
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, u32_flashAddr);
        HAL_NORFLASH_WriteByteBuffer((u32_flashAddr),(pu8_upgradeDataAddr),RDWR_SECTOR_SIZE);
        if (u32_dataSize < RDWR_SECTOR_SIZE)
        {
            DLOG_Critical("upgrade  finish 100%%\n");
            DLOG_Output(100);
            return ;
        }
        u32_dataSize -= RDWR_SECTOR_SIZE;
        u32_flashAddr += RDWR_SECTOR_SIZE;
        pu8_upgradeDataAddr += RDWR_SECTOR_SIZE;
        DLOG_Critical("upgrade data %ld%%\n",(u32_imageSize-u32_dataSize)*100/u32_imageSize);
         
        DLOG_Output(100);
    }while(((u32_flashAddr % RDWR_BLOCK_SIZE) != 0) || u32_flashAddr < APPLICATION_IMAGE_START0 - FLASH_BASE_ADDR);// boot upgrade too small

    do
    {
         
        HAL_NORFLASH_Erase(HAL_NORFLASH_Block, u32_flashAddr);
         
        HAL_NORFLASH_WriteByteBuffer((u32_flashAddr),(pu8_upgradeDataAddr), RDWR_BLOCK_SIZE/4);
         
        HAL_NORFLASH_WriteByteBuffer((u32_flashAddr+RDWR_BLOCK_SIZE/4), (pu8_upgradeDataAddr+RDWR_BLOCK_SIZE/4), RDWR_BLOCK_SIZE / 4);
         
        HAL_NORFLASH_WriteByteBuffer((u32_flashAddr+RDWR_BLOCK_SIZE/2), (pu8_upgradeDataAddr + RDWR_BLOCK_SIZE/2), RDWR_BLOCK_SIZE/4);
         
        HAL_NORFLASH_WriteByteBuffer((u32_flashAddr+RDWR_BLOCK_SIZE*3/4), (pu8_upgradeDataAddr + RDWR_BLOCK_SIZE * 3/4), RDWR_BLOCK_SIZE/4);
         
        if (u32_dataSize < RDWR_BLOCK_SIZE)
        {
            DLOG_Critical("upgrade  finish 100%%\n");
            DLOG_Output(100);
            return ;
        }
        u32_dataSize -= RDWR_BLOCK_SIZE;
        u32_flashAddr += RDWR_BLOCK_SIZE;
        pu8_upgradeDataAddr += RDWR_BLOCK_SIZE;
        DLOG_Critical("upgrade data %ld%%\n",(u32_imageSize-u32_dataSize)*100/u32_imageSize);
         
        DLOG_Output(100);
    }while(1);
}

extern HAL_RET_T HAL_NV_enterintoUpgrade(void);

#ifndef UPGRADE_DUAL_APP_DESIGN_EN

int8_t UPGRADE_ModifyBootInfo(uint32_t u32_addr)
{
    DLOG_Critical("start checksum receive data 2\n");
    int8_t ret = 0;
    STRU_Boot_Info st_bootInfo;
    memset(&st_bootInfo,0xff,sizeof(st_bootInfo));

    HAL_NV_enterintoUpgrade();
    HAL_NORFLASH_Init();

    HAL_NOR_FLASH_SetFlashDisableFlag(1);// disable WP

    HAL_NORFLASH_ReadByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),sizeof(st_bootInfo));
    if (APPLICATION_IMAGE_START0 == u32_addr)
    {
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, BOOT_INFO_OFFSET);
        st_bootInfo.success_app = 1;	
        st_bootInfo.checkSum = st_bootInfo.success_app + st_bootInfo.success_boot;
        HAL_NORFLASH_WriteByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),RDWR_SECTOR_SIZE);

    }
    else if(BOOT_ADDR0 == u32_addr)
    {
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, BOOT_INFO_OFFSET);
        st_bootInfo.success_boot = 1;
        st_bootInfo.checkSum = st_bootInfo.success_app + st_bootInfo.success_boot;
        HAL_NORFLASH_WriteByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),RDWR_SECTOR_SIZE);
    }

    //write image to flash
    if (1 == EFUSE_GetEfuseEnable())
    {
        DLOG_Critical("cpu efuse");
        EFUSE_CtrFlashWriteEfuse(0);
    }

    if(FLASH_BASE_ADDR == u32_addr)
    {
        UPGRADE_EraseWriteFlash(u32_addr-FLASH_BASE_ADDR, RECEIVE_ADDR + IMAGE_HEAD + BOOT_EXTRA_UPGRADE_HEADER_LEN, s_u32_imageSize - BOOT_EXTRA_UPGRADE_HEADER_LEN);
    }
    else
    {
        UPGRADE_EraseWriteFlash(u32_addr-FLASH_BASE_ADDR, RECEIVE_ADDR + IMAGE_HEAD, s_u32_imageSize);
    }



    DLOG_Critical("start checksum nor flash\n");DLOG_Output(100);

    //check flash image
    if(FLASH_BASE_ADDR == u32_addr)// boot md5 check
    {
        uint8_t * p8_data = (uint8_t *)(u32_addr);
        uint8_t * p8_tar = (uint8_t *)RECEIVE_ADDR + IMAGE_HEAD + BOOT_EXTRA_UPGRADE_HEADER_LEN;

         

        memcpy(p8_tar, p8_data , s_u32_imageSize);

        if (-1 == UPGRADE_MD5SUM(RECEIVE_ADDR, 1))
        {
            ret = -1;
        }
    }
    else
    {
        if (-1 != UPGRADE_MD5SUM(u32_addr, 0))
        {
            if (APPLICATION_IMAGE_START0 == u32_addr)
            {    
                st_bootInfo.success_app = 0;
            }
            else if(BOOT_ADDR0 == u32_addr)
            {
                st_bootInfo.success_boot = 0;
            }
        }
        else
        {
            if (APPLICATION_IMAGE_START0 == u32_addr)
            {
		        st_bootInfo.success_app = 1;
            }
            else if(BOOT_ADDR0 == u32_addr)
            {
                st_bootInfo.success_boot = 1;
            }
            ret = -1;
        }
    }


    if (1 == EFUSE_GetEfuseEnable())
    {
        DLOG_Critical("cpu efuse");
        EFUSE_CtrFlashWriteEfuse(1);
    }

    if(APPLICATION_IMAGE_START0 == u32_addr || BOOT_ADDR0 == u32_addr)
    {
        st_bootInfo.checkSum = st_bootInfo.success_app + st_bootInfo.success_boot;
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, BOOT_INFO_OFFSET);
        HAL_NORFLASH_WriteByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),RDWR_SECTOR_SIZE);
    }

    HAL_NOR_FLASH_SetFlashDisableFlag(0);// enable WP
    HAL_NORFLASH_Init();

    DLOG_Critical("into upgrade %x %x %x\r\n",st_bootInfo.success_boot,st_bootInfo.success_app,st_bootInfo.checkSum);

    DLOG_Critical("flash s1:%02x, s2:%02x", (uint8_t)HAL_NOR_FLASH_ReadStatusReg1(), (uint8_t)HAL_NOR_FLASH_ReadStatusReg2());
    DLOG_Output(100);
    return ret;
}


#else
int8_t UPGRADE_ModifyBootInfo(uint32_t u32_addr)
{
    DLOG_Critical("start checksum receive data 3\n");
    int8_t ret = 0;
    STRU_Boot_Info st_bootInfo;
    memset(&st_bootInfo,0xff,sizeof(st_bootInfo));

    HAL_NV_enterintoUpgrade();
    HAL_NORFLASH_Init();

    HAL_NOR_FLASH_SetFlashDisableFlag(1);// disable WP

    HAL_NORFLASH_ReadByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),sizeof(st_bootInfo));

    if((st_bootInfo.success_app == 0) && ((st_bootInfo.success_app + st_bootInfo.success_boot) == st_bootInfo.checkSum)){
	if(u32_addr == APPLICATION_IMAGE_START0){
		DLOG_Critical("start addr app1\n");
    		u32_addr = APPLICATION_IMAGE_START1;
	}
    }
    else if((st_bootInfo.success_app == 1) && ((st_bootInfo.success_app + st_bootInfo.success_boot) == st_bootInfo.checkSum)){
    	if(u32_addr == APPLICATION_IMAGE_START0){
    		DLOG_Critical("start addr app0\n");
    	}
    }
    
    if ((APPLICATION_IMAGE_START0 == u32_addr) || (APPLICATION_IMAGE_START1 == u32_addr))
    {
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, BOOT_INFO_OFFSET);
        st_bootInfo.checkSum = st_bootInfo.success_app + st_bootInfo.success_boot;
        HAL_NORFLASH_WriteByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),RDWR_SECTOR_SIZE);

    }
    else if(BOOT_ADDR0 == u32_addr)
    {
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, BOOT_INFO_OFFSET);
        st_bootInfo.success_boot = 1;
        st_bootInfo.checkSum = st_bootInfo.success_app + st_bootInfo.success_boot;
        HAL_NORFLASH_WriteByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),RDWR_SECTOR_SIZE);
    }

    //write image to flash
    if (1 == EFUSE_GetEfuseEnable())
    {
        DLOG_Critical("cpu efuse");
        EFUSE_CtrFlashWriteEfuse(0);
    }

    if(FLASH_BASE_ADDR == u32_addr)
    {
        UPGRADE_EraseWriteFlash(u32_addr-FLASH_BASE_ADDR, RECEIVE_ADDR + IMAGE_HEAD + BOOT_EXTRA_UPGRADE_HEADER_LEN, s_u32_imageSize - BOOT_EXTRA_UPGRADE_HEADER_LEN);
    }
    else
    {
        UPGRADE_EraseWriteFlash(u32_addr-FLASH_BASE_ADDR, RECEIVE_ADDR + IMAGE_HEAD, s_u32_imageSize);
    }



    DLOG_Critical("start checksum nor flash\n");

    //check flash image
    if(FLASH_BASE_ADDR == u32_addr)// boot md5 check
    {
        uint8_t * p8_data = (uint8_t *)(u32_addr);
        uint8_t * p8_tar = (uint8_t *)RECEIVE_ADDR + IMAGE_HEAD + BOOT_EXTRA_UPGRADE_HEADER_LEN;

         

        memcpy(p8_tar, p8_data , s_u32_imageSize);

        if (-1 == UPGRADE_MD5SUM(RECEIVE_ADDR, 1))
        {
            ret = -1;
        }
    }
    else
    {
        if (-1 != UPGRADE_MD5SUM(u32_addr, 0))
        {
            if (APPLICATION_IMAGE_START0 == u32_addr || APPLICATION_IMAGE_START1 == u32_addr)
	    {
	    	st_bootInfo.success_app ^= 1; 
            }
            else if(BOOT_ADDR0 == u32_addr)
            {
                st_bootInfo.success_boot = 0;
            }
        }
        else
        {
            if (APPLICATION_IMAGE_START0 == u32_addr || APPLICATION_IMAGE_START1 == u32_addr)
            {
      		st_bootInfo.success_app = 0;          
            }
            else if(BOOT_ADDR0 == u32_addr)
            {
                st_bootInfo.success_boot = 1;
            }
            ret = -1;
        }
    }


    if (1 == EFUSE_GetEfuseEnable())
    {
        DLOG_Critical("cpu efuse");
        EFUSE_CtrFlashWriteEfuse(1);
    }

    if(APPLICATION_IMAGE_START1 == u32_addr || APPLICATION_IMAGE_START0 == u32_addr || BOOT_ADDR0 == u32_addr)
    {
        st_bootInfo.checkSum = st_bootInfo.success_app + st_bootInfo.success_boot;
        HAL_NORFLASH_Erase(HAL_NORFLASH_Sector, BOOT_INFO_OFFSET);
        HAL_NORFLASH_WriteByteBuffer(BOOT_INFO_OFFSET,(uint8_t *)(&st_bootInfo),RDWR_SECTOR_SIZE);
    }

    HAL_NOR_FLASH_SetFlashDisableFlag(0);// enable WP
    HAL_NORFLASH_Init();

    DLOG_Critical("into upgrade %x %x %x\r\n",st_bootInfo.success_boot,st_bootInfo.success_app,st_bootInfo.checkSum);

    DLOG_Critical("flash s1:%02x, s2:%02x", (uint8_t)HAL_NOR_FLASH_ReadStatusReg1(), (uint8_t)HAL_NOR_FLASH_ReadStatusReg2());

    return ret;
}
#endif


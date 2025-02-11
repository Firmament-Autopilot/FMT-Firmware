/** 
 * @brief USB-读卡器配置
 * @author WeiXuan <2020302121154@whu.edu.cn
 * @file usbd_storage.C
 * @addtogroup USB
 * @signature: 热爱漫无边际，生活自有分寸
 */

#include "usbd_storage_if.h"
#include "stm32h743xx.h"
#include <string.h>
#include "bsp_driver_sd.h"

// 默认超时时间 30S
#define SD_TIMEOUT 30 * 1000

/* USB状态寄存器 
 * bit0:表示电脑正在向SD卡写入数据
 * bit1:表示电脑正从SD卡读出数据
 * bit2:SD卡写数据错误标志位
 * bit3:SD卡读数据错误标志位
 * bit4:1,表示电脑有轮询操作(表明连接还保持着)
 */ 
volatile uint8_t USB_STATUS_REG = 0;

#define STORAGE_LUN_NBR                  3
#define STORAGE_BLK_NBR                  0x10000
#define STORAGE_BLK_SIZ                  0x200

// SD卡句柄   
extern SD_HandleTypeDef hsd1;	
extern void mscDiskWritten(void);

// USB Mass storage 标准查询数据(每个lun占36字节)
const int8_t  STORAGE_Inquirydata[] = { 
	
	/* LUN 0 */
		0x00,
		0x80,		
		0x02,		
		0x02,
		(STANDARD_INQUIRY_DATA_LEN - 4),
		0x00,
		0x00,	
		0x00,
		/* Vendor Identification */
		'B', 'Y', 'H', 'U', 'A', 'V', ' ', ' ' ,' ',	// 9字节
		/* Product Identification */				
		'S', 'D', ' ', 'F', 'l', 'a', 's', 'h', ' ',	// 15字节
		'D', 'i', 's', 'k', ' ', ' ',  
			/* Product Revision Level */
		'1', '.', '0' ,' ',                      			// 4字节

}; 

extern USBD_HandleTypeDef hUsbDevice;

// USBD_Storage 回调函数
static int8_t STORAGE_Init(uint8_t lun);
static int8_t STORAGE_GetCapacity(uint8_t lun, uint32_t *block_num, uint16_t *block_size);
static int8_t STORAGE_IsReady(uint8_t lun);
static int8_t STORAGE_IsWriteProtected(uint8_t lun);
static int8_t STORAGE_Read(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len);
static int8_t STORAGE_Write(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len);
static int8_t STORAGE_GetMaxLun(void);

USBD_StorageTypeDef USBD_Storage_Interface_fops =
{
  STORAGE_Init,
  STORAGE_GetCapacity,
  STORAGE_IsReady,
  STORAGE_IsWriteProtected,
  STORAGE_Read,
  STORAGE_Write,
  STORAGE_GetMaxLun,
  (int8_t *)STORAGE_Inquirydata
};

/**
 * @author WeiXuan
 * @brief 初始化存储设备 
 * @param lun 逻辑单元编号,0,SPI FLASH;1,SD卡;
 * @returns 0,成功;
 */
int8_t STORAGE_Init(uint8_t lun)
{
  uint8_t res=0;
	switch(lun)
	{
		case 0:
			break;
	}  
	return res; 
}

/**
 * @author WeiXuan
 * @brief 获取存储设备的容量和块大小
 * @param lun 逻辑单元编号,0,SPI FLASH;1,SD卡;
 * @param *block_num 块数量(扇区数)
 * @param *block_size 块大小(扇区大小)
 * @returns 0,成功;
 */
int8_t STORAGE_GetCapacity (uint8_t lun, uint32_t *block_num, uint16_t *block_size)
{  
	HAL_SD_CardInfoTypeDef info;    
	switch(lun)
	{
		/* SD CARD */
		case 0:
			HAL_SD_GetCardInfo(&hsd1,&info);
			*block_num = info.LogBlockNbr - 1;
			*block_size = info.LogBlockSize;
		break; 
	}  	
	return 0; 
} 

/**
 * @author WeiXuan
 * @brief 查看存储设备是否就绪
 * @param lun 逻辑单元编号,0,SPI FLASH;1,SD卡;
 * @returns 0,就绪;
 */
int8_t  STORAGE_IsReady (uint8_t lun)
{ 
	int8_t ret = -1;
	switch (lun)
	{
		/* SD CARD */
		case 0:
			if(BSP_SD_IsDetected() != SD_NOT_PRESENT)
			{
				if(BSP_SD_GetCardState() == SD_TRANSFER_OK)
				{
					ret = 0;
				}
			}
		break; 
	}
	// 标记轮询
	USB_STATUS_REG|=0X10;
	return ret;
} 

/**
 * @author WeiXuan
 * @brief 查看存储设备是否写保护
 * @param lun 逻辑单元编号,0,SPI FLASH;1,SD卡;
 * @returns 0,没有写保护;其他,写保护(只读)
 */
int8_t  STORAGE_IsWriteProtected (uint8_t lun)
{
	return  0;
} 

/**
 * @author WeiXuan
 * @brief 从存储设备读取数据
 * @param lun 逻辑单元编号,0,SPI FLASH;1,SD卡;
 * @param *buf 数据存储区首地址指针
 * @param blk_addr 要读取的地址(扇区地址)
 * @param blk_len 要读取的块数(扇区数) 
 * @returns 0,成功;其他,错误代码 
 */
int8_t STORAGE_Read (uint8_t lun,uint8_t *buf,uint32_t blk_addr,uint16_t blk_len)
{
	int8_t res=0;
	// 标记正在读数据 
	USB_STATUS_REG|=0X02;
	switch(lun)
	{
		case 0:
			if (BSP_SD_IsDetected() != SD_NOT_PRESENT)
			{
				BSP_SD_ReadBlocks((uint32_t *) buf, blk_addr, blk_len, 1000);
				while (BSP_SD_GetCardState() != SD_TRANSFER_OK);
				res = 0;
			}
			break;
	} 
	if(res)
	{
		// 读错误
		USB_STATUS_REG|=0X08;
	}  
	return res;
}

/**
 * @author WeiXuan
 * @brief 向存储设备写数据
 * @param lun 逻辑单元编号,0,SD卡;1,SPI FLASH
 * @param *buf 数据存储区首地址指针
 * @param blk_addr 要写入的地址(扇区地址)
 * @param blk_len 要写入的块数(扇区数) 
 * @returns 0,成功;其他,错误代码 
 */
int8_t STORAGE_Write (uint8_t lun,uint8_t *buf,uint32_t blk_addr,uint16_t blk_len) 
{
	int8_t res=0;
	// 标记正在写数据 
	USB_STATUS_REG|=0X01;
	switch(lun)
	{
		case 0:
			if (BSP_SD_IsDetected() != SD_NOT_PRESENT)
			{
				BSP_SD_WriteBlocks((uint32_t *) buf, blk_addr, blk_len, 1000);
				while (BSP_SD_GetCardState() != SD_TRANSFER_OK);
				res = 0;
			}
			break;
	}  
	if(res)
	{
		// 写错误	 
		USB_STATUS_REG|=0X04;
	} 
	return res; 
}

/**
 * @author WeiXuan
 * @brief 获取支持的最大逻辑单元个数
 * @returns 支持的逻辑单元个数-1
 */
int8_t STORAGE_GetMaxLun (void)
{
	HAL_SD_CardInfoTypeDef info;
	HAL_SD_GetCardInfo(&hsd1,&info);
	/* 如果SD卡正常, 则支持2个磁盘 */
	if(info.LogBlockNbr)
		return STORAGE_LUN_NBR-2;
	/* SD卡不正常, 则只支持1个磁盘 */
	else 
		return STORAGE_LUN_NBR-3;
}
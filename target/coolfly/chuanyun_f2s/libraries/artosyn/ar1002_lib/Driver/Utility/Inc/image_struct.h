#ifndef IMAGE_STRUCT_H
#define IMAGE_STRUCT_H



#define MCU1_CPU_WAIT                       (0x40B000CC)  /* ENABLE CPU1 */
#define MCU2_CPU_WAIT                       (0xA0030088)  /* ENABLE CPU2 */
#define MCU0_VECTOR_TABLE_REG               (0xE000ED08)
#define ITCM0_START                         (0x00000000)
#define ITCM1_START                         (0x44100000)
#define ITCM2_START                         (0xB0000000)



#define RDWR_SECTOR_SIZE                    (0x1000)
#define RDWR_BLOCK_SIZE                     (0x10000)
#define MD5_SIZE                            (16)


#define FLASH_BASE_ADDR                     (0x10000000)
#define RECEIVE_ADDR                        (0x81000000)
#define APPLICATION_IMAGE_START0            (0x10028000)
#ifndef UPGRADE_DUAL_APP_DESIGN_EN
#define APPLICATION_IMAGE_START1            (0x10300000)
#else //APP1
#define APPLICATION_IMAGE_START1            (0x10428000)

#endif
#define APP_ADDR_OFFSET                     (0x28000)
#define BOOT_ADDR0                          (0x10008000)
#define BOOT_ADDR1                          (0x10018000)
#define BOOT_SIZE                           (1024*60)
#define BOOT_INFO_OFFSET                    (0x7000)
#define BOOT_EXTRA_UPGRADE_HEADER_LEN       (256)

#define IMAGE_HEAD                          (36)
#define IMAGE_IMAGESIZEOFFSET               (0)
#define IMAGE_MD5SUMOFFSET                  (4)
#define IMAGE_ENCRYPTMD5SUMOFFSET           (20)

#define IMAGE_HAER_LENGTH                   (256)
#define IMAGE_HAER_DATE_OFFSET              (0)
#define IMAGE_HAER_VERSION_OFFSET           (8)
#define IMAGE_HAER_IMAGE_SIZE_OFFSET        (14)
#define IMAGE_HAER_MD5_OFFSET               (18)
#define UPGRADE_ADDR_OFFSET                 (256)
#define DATEY_OFFSET                        (1)
#define DATEm_OFFSET                        (3)
#define DATEd_OFFSET                        (4)
#define DATEH_OFFSET                        (5)
#define DATEM_OFFSET                        (6)
#define DATES_OFFSET                        (7)
#define VERSION_MIAN_OFFSET                 (9)
#define VERSION_MAJOR_OFFSET                (10)
#define VERSION_MINOR_OFFSET                (11)
#define VERSION_MODE_SWITCH                 (12)
#define VERSION_MODE_GPIO                   (13)

#define BOOT_MODE_SKY                       (1)
#define BOOT_MODE_GND                       (0)

#define UPGRADE_DELAY                       (50)

#define GET_WORD_FROM_ANY_ADDR(any_addr) ((uint32_t)(*any_addr) | \
                                         (((uint32_t)(*(any_addr+1))) << 8) | \
                                         (((uint32_t)(*(any_addr+2))) << 16) | \
                                         ((uint32_t)((*(any_addr+3))) << 24))
typedef struct
{
    unsigned char success_boot;
    unsigned char success_app;
    unsigned char checkSum ;
}STRU_Boot_Info;

int8_t UPGRADE_MD5SUM(uint32_t u32_addr, uint8_t u8_flag);
void UPGRADE_EraseWriteFlash(uint32_t u32_flashAddress, uint32_t u32_upgradeDataAddress, uint32_t u32_imageSize);
int8_t UPGRADE_ModifyBootInfo(uint32_t u32_addr);

#endif

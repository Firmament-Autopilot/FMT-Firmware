#ifndef NOR_FLASH_H
#define NOR_FLASH_H

#define MIN_PROTECT_SIZE                    (3584 *1024) // 3.5MB

#define NORFLASH_SIZE_4MB                   (4 * 1024 *1024)
#define NORFLASH_SIZE_8MB                   (8 * 1024 *1024)
#define NORFLASH_SIZE_16MB                  (16 * 1024 *1024)
#define NORFLASH_SIZE_32MB                  (32 * 1024 *1024)
#define NORFLASH_SIZE_64MB                  (64 * 1024 *1024)

/*Manufacturer*/
/*#ifndef CONFIG_SPI_FLASH_ATMEL
#define CONFIG_SPI_FLASH_ATMEL
#define SPI_FLASH_MFR_ATMEL                 0x1f
#endif

#ifndef CONFIG_SPI_FLASH_EON
#define CONFIG_SPI_FLASH_EON
#define SPI_FLASH_MFR_EON                   0x1c
#endif*/

#ifndef CONFIG_SPI_FLASH_GIGADEVICE
#define CONFIG_SPI_FLASH_GIGADEVICE
#define SPI_FLASH_MFR_GIGADEVICE            0xC8
#endif

#ifndef CONFIG_SPI_FLASH_XD
#define CONFIG_SPI_FLASH_XD
#define SPI_FLASH_MFR_XD                    0xD8
#endif


/*#ifndef CONFIG_SPI_FLASH_ISSI
#define CONFIG_SPI_FLASH_ISSI
#define SPI_FLASH_MFR_ISSI                  0x9d
#endif*/

#ifndef CONFIG_SPI_FLASH_MACRONIX
#define CONFIG_SPI_FLASH_MACRONIX
#define SPI_FLASH_MFR_MACRONIX              0xc2
#endif

#define SPI_FLASH_PUYA_SEMI                 0x85

/*#ifndef CONFIG_SPI_FLASH_SPANSION
#define CONFIG_SPI_FLASH_SPANSION
#define SPI_FLASH_MFR_SPANSION              0x01
#endif

#ifndef CONFIG_SPI_FLASH_STMICRO
#define CONFIG_SPI_FLASH_STMICRO
#define SPI_FLASH_MFR_STMICRO               0x20
#endif

#ifndef CONFIG_SPI_FLASH_SST
#define CONFIG_SPI_FLASH_SST
#define SPI_FLASH_MFR_SST                   0xbf
#endif*/

#ifndef CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SPI_FLASH_WINBOND
#define SPI_FLASH_MFR_WINBOND               0xef
#endif


#define SPI_FLASH_3B_ADDR_LEN               3
#define SPI_FLASH_CMD_LEN                   (1 + SPI_FLASH_3B_ADDR_LEN)
#define SPI_FLASH_16MB_BOUN                 0x1000000

/* Common status */
#define STATUS_WIP                          BIT(0)
#define STATUS_QEB_WINSPAN                  BIT(1)
#define STATUS_QEB_MXIC                     BIT(6)
#define STATUS_PEC                          BIT(7)
#define SR_BP0                              BIT(2)  /* Block protect 0 */
#define SR_BP1                              BIT(3)  /* Block protect 1 */
#define SR_BP2                              BIT(4)  /* Block protect 2 */

/* Flash timeout values */
#define SPI_FLASH_PROG_TIMEOUT              (2)
#define SPI_FLASH_PAGE_ERASE_TIMEOUT        (5)
#define SPI_FLASH_SECTOR_ERASE_TIMEOUT      (10)


#define JEDEC_MFR(info)                     ((info)->id[0])
#define JEDEC_ID(info)                      (((info)->id[1]) << 8 | ((info)->id[2]))
#define SPI_FLASH_MAX_ID_LEN                3

/*spi_flash_info flag*/
#define SECT_4K                             BIT(0)  /* CMD_ERASE_4K works uniformly */
#define E_FSR                               BIT(1)  /* use flag status register for */
#define SST_WR                              BIT(2)  /* use SST byte/word programming */
#define WR_QPP                              BIT(3)  /* use Quad Page Program */
#define RD_QUAD                             BIT(4)  /* use Quad Read */
#define RD_DUAL                             BIT(5)  /* use Dual Read */
#define RD_QUADIO                           BIT(6)  /* use Quad IO Read */
#define RD_DUALIO                           BIT(7)  /* use Dual IO Read */
#define RD_FULL                             (RD_QUAD | RD_DUAL | RD_QUADIO | RD_DUALIO)

/*Status Register 1*/
#define BP0                                 BIT(2)  /* BP0 */
#define BP1                                 BIT(3)  /* BP1 */
#define BP2                                 BIT(4)  /* BP2 */
#define BP3                                 BIT(5)  /* BP3 */
#define BP4                                 BIT(6)  /* BP4 */
#define TB                                  BIT(5)  /* TB */
#define TB_1                                BIT(6)  /* TB_1 */
#define SEC                                 BIT(6)  /* SEC */
#define SRP0                                BIT(7)  /* STATUS REGISTER PROTECT 0 */
#define SRWD                                BIT(7)  /* STATUS REGISTER PROTECT 0 */


/*Status Register 2*/
#define TB_2                                BIT(3)  /* TOP/BOTTOM */
#define CMP                                 BIT(6)  /* CMP */

struct spi_flash
{
    const char *  name;
    uint8_t         id[SPI_FLASH_MAX_ID_LEN];
    uint8_t         dual_flash;
    uint8_t         shift;
    uint16_t        flags;

    uint32_t        size;
    uint32_t        page_size;
    uint32_t        sector_size;
    uint32_t        erase_size;
    uint32_t        protect_start;
    uint32_t        protect_end;
    uint8_t         s1_map;
    uint8_t         s2_map;
    uint8_t         s1_wp_map;
    uint8_t         s2_wp_map;
};

struct spi_flash_info
{
    /* Device name ([MANUFLETTER][DEVTYPE][DENSITY][EXTRAINFO]) */
    const char    *name;

    /*
     * This array stores the ID bytes.
     * The first three bytes are the JEDIC ID.
     * JEDEC ID zero means "no ID" (mostly older chips).
     */
    uint8_t         id[SPI_FLASH_MAX_ID_LEN];
    uint8_t         id_len;

    /*
     * The size listed here is what works with SPINOR_OP_SE, which isn't
     * necessarily called a "sector" by the vendor.
     */
    uint32_t        sector_size;
    uint32_t        n_sectors;
    uint32_t        protect_start;// start address of protect
    uint32_t        protect_end;// end address of protect

    uint16_t        page_size;

    uint16_t        flags;

    uint8_t         s1_map;// Status register1
    uint8_t         s2_map;// Status register2

    uint8_t         s1_wp_map;// Status register1
    uint8_t         s2_wp_map;// Status register2
};

extern const struct spi_flash_info spi_flash_ids[];

void    NOR_FLASH_SetFlashDisableFlag(uint8_t flag);
uint8_t NOR_FLASH_GetFlashDisableFlag();
uint8_t NOR_FLASH_WP_Enable(struct spi_flash flash_status, uint8_t enable_flag, uint32_t start_addr, uint32_t size);
void NOR_FLASH_BootUpgradeEnable();
void NOR_FLASH_BootUpgradeDisable();

void NOR_FLASH_Init(void);

uint8_t NOR_FLASH_EraseSector(uint32_t flash_start_addr);
uint8_t NOR_FLASH_EraseBlock(uint32_t flash_start_addr);
uint8_t NOR_FLASH_EraseChip(void);

void NOR_FLASH_WriteByteBuffer(uint32_t start_addr, uint8_t* data_buf, uint32_t size);
void NOR_FLASH_WriteHalfWordBuffer(uint32_t start_addr, uint16_t* data_buf, uint32_t size);
void NOR_FLASH_WriteWordBuffer(uint32_t start_addr, uint32_t* data_buf, uint32_t size);

void NOR_FLASH_ReadByteBuffer(uint32_t start_addr, uint8_t* data_buf, uint32_t size);

uint32_t NOR_FLASH_ReadStatusReg1(void);
uint32_t NOR_FLASH_ReadStatusReg2(void);

void NOR_FLASH_SetStatusReg1(uint8_t flag);
void NOR_FLASH_SetStatusReg2(uint8_t flag);

void NOR_FLASH_ReadManuDeviceID(uint8_t* data_buf, uint8_t buflen);
void NOR_FLASH_ReadJEDECID(uint8_t* data_buf, uint8_t buflen);
//void NOR_FLASH_ReadProductID(uint8_t* data_buf);
#endif


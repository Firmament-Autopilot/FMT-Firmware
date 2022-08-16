#include "bb_ctrl_internal.h"
#include "bb_regs.h"
#include "bb_sky_ctrl.h"
#include "bb_spi.h"
#include "bb_uart_com.h"
#include "boardParameters.h"
#include "cfg_parser.h"
#include "debuglog.h"
#include "drv_systick.h"
#include "factory.h"
#include "memory_config.h"
#include "pwr_ctrl.h"
#include "reg_rw.h"
#include "sys_event.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#define BB_SPI_TEST (0)
#define RF_SPI_TEST (0)

#define VSOC_GLOBAL2_BASE (0xA0030000)
#define BB_SPI_UART_SEL   (0x9c)

#define SKY_PATTEN_SIZE_5G 4

#define PRECIESE 100

pfun pfun_lna_open = NULL, pfun_lna_bypass = NULL;
pfun_fem pfun_fem_open = NULL, pfun_fem_close = NULL;
pfun pfun_f2g_open = NULL, pfun_f5g_open = NULL;

static int BB_before_RF_cali(void);
static void BB_GetRcIdVtIdFromFlash(uint8_t* pu8_rcid, uint8_t* pu8_vtid);
static void BB_after_RF_cali(ENUM_BB_MODE en_mode);
static void BB_RF_start_cali(void);
static void BB_HandleEventsCallback(void* p);
static void BB_SendRmoteEvent(void* p);
static void BB_AocInit(void);


typedef struct _STRU_cmds {
    uint8_t avail; /*command is using*/
    STRU_WIRELESS_CONFIG_CHANGE config;
} STRU_cmds;

typedef struct _STRU_AGC2LNA {
    uint8_t u8_agcaBuf[1000];
    uint8_t u8_agcbBuf[1000];
    uint32_t sum_a;
    uint32_t sum_b;
    uint16_t mindex; //move avg index
    uint8_t isFull;
} STRU_AGC2LNA;

volatile CONTEXT context;
static volatile ENUM_REG_PAGES en_curPage;

uint8_t* p_bbRegs = NULL;

STRU_BOARD_BB_PARA* pstru_bb_boardcfg = NULL;

STRU_BB_REG* p_bb_reg_beforeCali = NULL;
STRU_BB_REG* p_bb_reg_afterCali = NULL;

STRU_BB_AOC* pstru_bb_aoc_boardcfg = NULL;
STRU_BB_AES* pstru_bb_aes_cfg = NULL;
STRU_AGC_SET* pstru_agc_set_cfg = NULL;
STRU_PWR_CTRL* pstru_pwr_ctrl_cfg = NULL;
STRU_RF_BAND_MCS_OPT* pstru_mcs_opt = NULL;
STRU_BB_LAN_AUTO* pstru_lna_auto = NULL;

STRU_RF_POWER_CTRL* pst_powercfg = NULL;

STRU_DT_HEAD g_dtLen[] = {
    { 0, 0, 1, 2, DT_NUM_RC_CH_MODE },
    { 0, 0, 1, 1, DT_NUM_IT_CH_MODE },
    { 0, 0, 1, 8, DT_NUM_RF_BAND_CHANGE },
    { 0, 0, 1, 1, DT_NUM_RF_CH_BW_CHANGE },
    { 0, 0, 1, 1, DT_NUM_MCS_MODE_SELECT },
    { 0, 0, 1, 1, DT_NUM_ENCODER_BRC_CHAGE_CH1 },
    { 0, 0, 1, 1, DT_NUM_ENCODER_BRC_CHAGE_CH2 },
    { 0, 0, 1, 1, DT_NUM_RF_CH_LDPC_CHANGE },
    { 0, 0, 1, 1, DT_NUM_RF_CH_QAM_CHANGE },
    { 0, 0, 0, 1, DT_NUM_GRD_MASK_CODE },
    { 0, 0, 1, 6, DT_NUM_RC_FRQ },
    { 0, 0, 1, 5, DT_NUM_IT_FRQ },
    { 0, 0, 1, 2, DT_NUM_RC_RATE },
    { 0, 0, 1, 7, DT_NUM_GRD_SEND_VT_ID },
    //                            {0, 0, 1, 5, DT_NUM_GROUND_SYNC_RC_ID},
    { 0, 0, 1, 1, DT_NUM_RF_BAND_MODE },
    //                            {0, 0, 1, SYS_EVENT_HANDLER_PARAMETER_LENGTH+1, DT_NUM_REMOTE_EVENT},
    { 0, 0, 0, sizeof(int), DT_NUM_AOC_ADJUST },
    { 0, 0, 1, 2, DT_NUM_FILTER_CHG },
    { 0, 0, 1, 2, DT_NUM_TAKE_PICTURE },
    { 0, 0, 1, 2, DT_NUM_PICTURE_QUALITY_SET },
    { 0, 0, 1, 2, DT_NUM_BAND_MODE_CHG },
    { 0, 0, 1, 1, DT_NUM_LNA_STATUS_CHG },
    //{0, 0, 1, 1, DT_NUM_NON_LBT_ENABLE},
    { 0, 0, 1, 1, DT_NUM_NON_LBT_NOTICE_OPTCH },
    { 0, 0, 1, 1, DT_NUM_SKY_RC_PATTEN },
    { 0, 0, 1, 1, DT_NUM_GRD_RC_CHPATTEN },
};

static uint8_t u8_session0RecvBuf[256] = { 0 };
static uint16_t u16_session0DataSize = 0;


STRU_PURE_VT_INFO vt_info = { 0, 0, AUTO };
uint8_t wake_up_flag = 0;
static STRU_AGC2LNA stru_agc2lna;

#define RF_8003X

#if (defined RF_9363) && (defined RF_8003X)
    #error "RF_9363 and RF_8003X only choose one"
#elif (!defined RF_9363) && (!defined RF_8003X)
    #error "RF_9363 and RF_8003X must choose one"
#endif

static const uint16_t crc16tab[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6, 0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d, 0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823, 0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a, 0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41, 0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70, 0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067, 0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d, 0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634, 0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a, 0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1, 0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8, 0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

uint16_t crc16(const char* buf, int len)
{
    int counter;
    uint16_t crc = 0;
    for (counter = 0; counter < len; counter++)
        crc = (crc << 8) ^ crc16tab[((crc >> 8) ^ *buf++) & 0x00FF];
    return crc;
}
static uint32_t crc32_tab[] = {
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L, 0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L, 0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L, 0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL, 0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L, 0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L, 0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L, 0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL, 0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L, 0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL, 0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L, 0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L, 0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L, 0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL, 0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL, 0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L, 0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL, 0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L, 0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L, 0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L, 0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL, 0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L, 0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L, 0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL, 0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L, 0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L, 0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L, 0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L, 0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L, 0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL, 0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL, 0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L, 0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L, 0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL, 0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL, 0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L, 0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL, 0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L, 0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL, 0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L, 0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL, 0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L, 0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L, 0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL, 0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L, 0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L, 0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L, 0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L, 0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L, 0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L, 0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL, 0x2d02ef8dL
};

signed char int2char(int data)
{
    signed char value = 0;
    if (data < 0) {
        uint8_t temp = abs(data);
        if (temp > 127)
            temp = 127;
        value = 0 - temp;
    } else
        value = (data & 0x7F);

    return value;
}
/* crc32 hash */
uint32_t crc32(const char* s, int len)
{
    int i;
    uint32_t crc32val = 0;
    crc32val ^= 0xFFFFFFFF;

    for (i = 0; i < len; i++) {
        crc32val = crc32_tab[(crc32val ^ s[i]) & 0xFF] ^ ((crc32val >> 8) & 0x00FFFFFF);
    }

    return labs(crc32val ^ 0xFFFFFFFF);
}



STRU_CUSTOMER_CFG stru_defualtCfg = {
    .itHopMode = AUTO,
    .rcHopMode = AUTO,
    .qam_skip_mode = AUTO,
};

const uint8_t mcs_idx_bitrate_map_10m[] = {
    1,  //0.6Mbps BPSK 1/2
    2,  //1.2     BPSK 1/2
    3,  //2.4     QPSK 1/2
    8,  //5.0     16QAM 1/2
    11, //7.5     64QAM 1/2
    13, //10      64QAM 2/3
};

const uint8_t mcs_idx_bitrate_map_20m[] = {
    2,  //1.2Mbps BPSK 1/2
    3,  //2.4     BPSK 1/2
    8,  //5.0     QPSK 1/2
    11, //7.5     16QAM 1/2
    13, //10      16QAM 2/3
};

static void BB_SendRmoteEvent(void* p)
{
    BB_Session0SendMsg(DT_NUM_REMOTE_EVENT, (uint8_t*)p, SYS_EVENT_HANDLER_PARAMETER_LENGTH);
}

void BB_handle_misc_cmds(STRU_WIRELESS_CONFIG_CHANGE* pcmd)
{
    uint8_t class = pcmd->u8_configClass;
    uint8_t item = pcmd->u8_configItem;

    uint8_t value = (uint8_t)(pcmd->u32_configValue);
    uint8_t value1 = (uint8_t)(pcmd->u32_configValue >> 8);
    uint8_t value2 = (uint8_t)(pcmd->u32_configValue >> 16);
    uint8_t value3 = (uint8_t)(pcmd->u32_configValue >> 24);

    if (class == WIRELESS_MISC) {
        switch (item) {
        case MISC_READ_RF_REG: {
            uint8_t v;
            BB_SPI_curPageWriteByte(0x01, (value == 0) ? 0x01 : 0x03); //value2==0: write RF8003-0
                                                                       //value2==1: write RF8003-1
            RF_SPI_ReadReg((value1 << 8) | value2, &v);
            BB_SPI_curPageWriteByte(0x01, 0x02);
            //DLOG_Info("RF read %d addrH=0x%0.2x addrL:%0.2x out:0x%0.2x", value, value1, value2, v);
            break;
        }

        case MISC_WRITE_RF_REG: {
            BB_SPI_curPageWriteByte(0x01, (value == 0) ? 0x01 : 0x03); //value2==0: write RF8003-0
                                                                       //value2==1: write RF8003-1
            RF_SPI_WriteReg((value1 << 8) | value2, value3);
            BB_SPI_curPageWriteByte(0x01, 0x02);

            //DLOG_Info("RF write %d addr=0x%0.2x value=0x%0.2x", value, (value1 << 8) | value2, value3);
            break;
        }

        case MISC_READ_BB_REG: {
            volatile uint8_t v = BB_ReadReg((ENUM_REG_PAGES)value, (uint8_t)value1);
            DLOG_Info("BB read PAGE=0x%02x addr=0x%02x value=0x%02x", value, value1, v);
            break;
        }

        case MISC_WRITE_BB_REG: {
            BB_WriteReg((ENUM_REG_PAGES)value, (uint8_t)value1, (uint8_t)value2);
            //DLOG_Info("BB write PAGE=0x%0.2x addr=0x%0.2x value=0x%0.2x", value, value1, value2);
            break;
        }

        case MICS_IT_ONLY_MODE: {
            BB_WriteReg(PAGE2, 0x02, 0x06);
            break;
        }
        }
    }
}

static void BB_GetRcIdVtIdFromFlash(uint8_t* pu8_rcid, uint8_t* pu8_vtid)
{
    uint32_t loop = 0;
    uint8_t flag_found = 0;
    volatile STRU_NV* pst_nv = (volatile STRU_NV*)SRAM_NV_MEMORY_ST_ADDR;

    while (loop++ < 500 && 0 == flag_found) {
        if (0x23178546 != pst_nv->st_nvMng.u32_nvInitFlag) {
            SysTicks_DelayMS(20);
        } else {
            flag_found = 1;
        }
    }

    if (flag_found) {
        memcpy((void*)pu8_rcid, (void*)(pst_nv->st_nvDataUpd.u8_nvBbRcId), RC_ID_SIZE);
        memcpy((void*)pu8_vtid, (void*)(pst_nv->st_nvDataUpd.u8_nvBbVtId), VT_ID_SIZE);
        memcpy((void*)context.chipid, (void*)(pst_nv->st_nvDataUpd.u8_nvChipId), RC_ID_SIZE);

        if (pst_nv->st_nvMng.u8_nvVld != TRUE) {
            DLOG_Warning("rcid null");
        }

        /*if(BB_SKY_MODE == context.en_bbmode)
        {
            memcpy((void *)pu8_rcid, (void *)context.chipid, RC_ID_SIZE);
        }*/

        DLOG_Critical("rc: 0x%x 0x%x 0x%x 0x%x 0x%x vt: 0x%x 0x%x", pu8_rcid[0], pu8_rcid[1], pu8_rcid[2], pu8_rcid[3], pu8_rcid[4], pu8_vtid[0], pu8_vtid[1]);
    }
}

/** 
 * @brief       
 * @param   
 * @retval      
 * @note      
 */
int BB_GetDevInfo(void)
{
    uint8_t u8_data;
    STRU_DEVICE_INFO* pst_devInfo = (STRU_DEVICE_INFO*)(DEVICE_INFO_SHM_ADDR);

    pst_devInfo->msg_id = 0x19;
    pst_devInfo->msg_len = sizeof(STRU_DEVICE_INFO) - sizeof(STRU_WIRELESS_MSG_HEADER);

    pst_devInfo->skyGround = context.en_bbmode;
    pst_devInfo->band = context.e_curBand;

    //pst_devInfo->bandWidth = context.CH_bandwidth;
    pst_devInfo->itHopMode = context.itHopMode;
    pst_devInfo->rcHopping = context.rcHopMode;
    pst_devInfo->adapterBitrate = context.qam_skip_mode;
    u8_data = BB_ReadReg(PAGE1, 0x8D);
    pst_devInfo->channel1_on = (u8_data >> 6) & 0x01;
    pst_devInfo->channel2_on = (u8_data >> 7) & 0x01;
    pst_devInfo->isDebug = context.u8_debugMode;
    if (BB_GRD_MODE == context.en_bbmode) {
        u8_data = BB_ReadReg(PAGE2, GRD_FEC_QAM_CR_TLV);
        pst_devInfo->itQAM = u8_data & 0x03;
        pst_devInfo->itCodeRate = ((u8_data >> 2) & 0x07);
        u8_data = BB_ReadReg(PAGE2, RX_MODULATION);
        pst_devInfo->bandWidth = (u8_data >> 0) & 0x07;

        u8_data = BB_ReadReg(PAGE2, TX_2);
        pst_devInfo->rcQAM = (u8_data >> 6) & 0x01;
        pst_devInfo->rcCodeRate = (u8_data >> 0) & 0x01;
    } else {
        u8_data = BB_ReadReg(PAGE2, TX_2);
        pst_devInfo->itQAM = (u8_data >> 6) & 0x03;
        pst_devInfo->bandWidth = (u8_data >> 3) & 0x07;
        pst_devInfo->itCodeRate = ((u8_data >> 0) & 0x07);

        u8_data = BB_ReadReg(PAGE2, 0x09);
        pst_devInfo->rcQAM = (u8_data >> 0) & 0x01;
        pst_devInfo->rcCodeRate = (u8_data >> 2) & 0x01;
    }

    if (context.brc_mode == AUTO) {
        pst_devInfo->ch1Bitrates = context.qam_ldpc;
        pst_devInfo->ch2Bitrates = context.qam_ldpc;
    } else {
        pst_devInfo->ch1Bitrates = context.brc_bps[0];
        pst_devInfo->ch2Bitrates = context.brc_bps[1];
    }

#ifdef RF_9363
    //if (context.e_curBand == RF_600M)
    {
        pst_devInfo->u8_itRegs[0] = context.stru_itRegs.frq1;
        pst_devInfo->u8_itRegs[1] = context.stru_itRegs.frq3;
        pst_devInfo->u8_itRegs[2] = context.stru_itRegs.frq4;
        pst_devInfo->u8_itRegs[3] = context.stru_itRegs.frq5;

        pst_devInfo->u8_rcRegs[0] = context.stru_rcRegs.frq1;
        pst_devInfo->u8_rcRegs[1] = context.stru_rcRegs.frq3;
        pst_devInfo->u8_rcRegs[2] = context.stru_rcRegs.frq4;
        pst_devInfo->u8_rcRegs[3] = context.stru_rcRegs.frq5;
    }
#endif

#ifdef RF_8003X
    //else
    {
        pst_devInfo->u8_itRegs[0] = context.stru_itRegs.frq4;
        pst_devInfo->u8_itRegs[1] = context.stru_itRegs.frq3;
        pst_devInfo->u8_itRegs[2] = context.stru_itRegs.frq2;
        pst_devInfo->u8_itRegs[3] = context.stru_itRegs.frq1;

        pst_devInfo->u8_rcRegs[0] = context.stru_rcRegs.frq4;
        pst_devInfo->u8_rcRegs[1] = context.stru_rcRegs.frq3;
        pst_devInfo->u8_rcRegs[2] = context.stru_rcRegs.frq2;
        pst_devInfo->u8_rcRegs[3] = context.stru_rcRegs.frq1;
    }
#endif

    pst_devInfo->switch_mode_2g_5g = context.st_bandMcsOpt.e_rfbandMode;
    pst_devInfo->pure_vt_valid = vt_info.valid;

    /*STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;    
    memcpy((void *)pst_devInfo->rcId, (void *)(pst_nv->st_nvDataUpd.u8_nvBbRcId), RC_ID_SIZE);
    memcpy((void *)pst_devInfo->vtid, (void *)(pst_nv->st_nvDataUpd.u8_nvBbVtId), VT_ID_SIZE);
    memcpy((void *)pst_devInfo->chipId, (void *)(pst_nv->st_nvDataUpd.u8_nvChipId), RC_ID_SIZE);*/

    memcpy((void*)pst_devInfo->rcId, (void*)(context.rcid), RC_ID_SIZE);
    memcpy((void*)pst_devInfo->vtid, (void*)(context.vtid), VT_ID_SIZE);
    memcpy((void*)pst_devInfo->chipId, (void*)(context.chipid), RC_ID_SIZE);
    pst_devInfo->inSearching = context.inSearching;
    pst_devInfo->en_realtime = context.realtime_mode | (context.enable_non_lbt << 1);
    pst_devInfo->lna_status = context.lna_status | (context.st_mimo_mode.enum_lna_mode << 1)
        | (context.bandedge_enable << 7) | (context.low_power_db << 3);
    pst_devInfo->reserved[0] = context.pwr;
    pst_devInfo->sleep_level = context.sleep_level;

    //pst_devInfo->u8_startWrite = 0;
    //pst_devInfo->u8_endWrite = 1;

    return 0;
}

/** 
 * @brief       
 * @param   
 * @retval      
 * @note      
 */
int BB_SwtichOnOffCh(uint8_t u8_ch, uint8_t u8_data)
{
    uint8_t u8_regVal;

    u8_regVal = BB_ReadReg(PAGE1, 0x8D);
    if ((0 == u8_ch) && (0 == u8_data)) {
        u8_regVal &= ~(0x40); // channel1
        BB_WriteReg(PAGE1, 0x8D, u8_regVal);
    } else if ((0 == u8_ch) && (1 == u8_data)) {
        u8_regVal |= (0x40); // channel1
        BB_WriteReg(PAGE1, 0x8D, u8_regVal);
    } else if ((1 == u8_ch) && (0 == u8_data)) {
        u8_regVal &= ~(0x80); // channel2
        BB_WriteReg(PAGE1, 0x8D, u8_regVal);
    } else if ((1 == u8_ch) && (1 == u8_data)) {
        u8_regVal |= (0x80); // channel2
        BB_WriteReg(PAGE1, 0x8D, u8_regVal);
    } else {
    }

    return 0;
}

int BB_GetRcId(uint8_t* pu8_rcId, uint8_t bufsize)
{
    if (bufsize < RC_ID_SIZE) {
        return 1;
    } else {
        memcpy((void*)pu8_rcId, (uint8_t*)(SRAM_SHARE_FLAG_ST_ADDR + SHARE_FLAG_RC_ID_OFFSET), RC_ID_SIZE);
    }

    return 0;
}

/** 
 * @brief       get rc rate
 * @param       none
 * @retval      1: BPSK 1/2, uart max 32bytes
 *              2: QPSK 2/3, uart max 208bytes
 *              0: unknow qam/code_rate
 * @note        None
 */
uint32_t BB_GetRcRate(ENUM_BB_MODE en_mode)
{
    uint32_t ret = 0;
    uint8_t rate = 0;

    if (BB_SKY_MODE == en_mode) {
        rate = BB_ReadReg(PAGE2, 0x09) & 0x05;

        if (0 == rate) {
            ret = 1; // BPSK 1/2
        } else if (0x05 == rate) {
            ret = 2; // QPSK 2/3
        } else if (0x01 == rate) {
            ret = 3; // QPSK 1/2
        } else if (0x04 == rate) {
            ret = 4; // BPSK 2/3
        }
    } else if (BB_GRD_MODE == en_mode) {
        rate = BB_ReadReg(PAGE2, 0x04) & 0x41;

        if (0 == rate) {
            ret = 1; // BPSK 1/2
        } else if (0x41 == rate) {
            ret = 2; // QPSK 2/3
        } else if (0x40 == rate) {
            ret = 3; // QPSK 1/2
        } else if (0x1 == rate) {
            ret = 4; // BPSK 2/3
        }
    }

    return ret;
}

static void BB_AocInit(void)
{
    if (NULL != pstru_bb_aoc_boardcfg) {
        context.aoc.u16_snrThdL = pstru_bb_aoc_boardcfg->u16_snrThdL;
        context.aoc.u16_snrThdH = pstru_bb_aoc_boardcfg->u16_snrThdH;
        context.aoc.u8_agcThdL = pstru_bb_aoc_boardcfg->u8_agcThdL;
        context.aoc.u8_agcThdH = pstru_bb_aoc_boardcfg->u8_agcThdH;
        context.aoc.u8_PwrThdMin = pstru_bb_aoc_boardcfg->u8_PwrThdMin;
        context.aoc.u8_agcAvgCnt = pstru_bb_aoc_boardcfg->u8_agcAvgCnt;
        context.aoc.u8_snrAvgCnt = pstru_bb_aoc_boardcfg->u8_snrAvgCnt;
        context.aoc.u16_ldpcStacCnt = pstru_bb_aoc_boardcfg->u16_ldpcStacCnt;
        context.aoc.u16_ldpcThd = pstru_bb_aoc_boardcfg->u16_ldpcThd;
    } else {
        context.aoc.u16_snrThdL = 0x1900; // 20db
        context.aoc.u16_snrThdH = 0x279F; // 22db
        context.aoc.u8_agcThdL = 60;      //
        context.aoc.u8_agcThdH = 70;      //
        context.aoc.u8_PwrThdMin = 15;    // -3.25dB
        context.aoc.u8_agcAvgCnt = 64;
        context.aoc.u8_snrAvgCnt = 16;
        context.aoc.u16_ldpcStacCnt = 100;
        context.aoc.u16_ldpcThd = 100;
    }
}




int BB_Session0SendMsg(uint8_t id, uint8_t* data_buf, uint16_t len)
{
    uint8_t data[256];
    // uint8_t  i = 0;

    if (len + 3 > sizeof(data)) {
        DLOG_Error("size flow");
    }

    data[0] = 0xa5;
    data[1] = len + 1; //len = id + size(data)
    data[2] = id;

    if (len > 0) {
        memcpy(data + 3, data_buf, len);
    }

    //return 0;
    BB_ComSendMsg(BB_COM_SESSION_0, data, len + 3);

    return 0;
}





void BB_Register_lna(pfun open_lna_function, pfun bypass_lna_function)
{
    pfun_lna_open = open_lna_function;
    pfun_lna_bypass = bypass_lna_function;
}
void BB_Register_freq2g5g_switch(pfun open_2g_function, pfun open_5g_function)
{
    pfun_f2g_open = open_2g_function;
    pfun_f5g_open = open_5g_function;
}

void BB_Register_fem_cb(pfun_fem fem_cb_open, pfun_fem fem_cb_close)
{
    pfun_fem_open = fem_cb_open;
    pfun_fem_close = fem_cb_close;
}

void BB_Enable_RcRandomSkipPatten(void)
{
    context.enable_rc_random_skip_patten = 1;
}

void BB_config_uplink_qam_mode(uint8_t val)
{
    context.uplink_qam_mode = val;
}


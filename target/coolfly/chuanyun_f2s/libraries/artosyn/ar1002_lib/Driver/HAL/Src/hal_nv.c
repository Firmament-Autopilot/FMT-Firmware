#include <stdint.h>
#include <string.h>
#include "hal_nv.h"
#include "data_type.h"
#include "nor_flash.h"
#include "debuglog.h"
#include "bb_ctrl.h"
#include "memory_config.h"
#include "sys_event.h"
#include "inter_core.h"
#include "hal_norflash.h"
#include "efuse.h"
#include "driver_mutex.h"
#include "driver_module_init.h"

#define NV_UPD_MAX_DELAY     (2000)

static int32_t NV_WriteToFlash(uint32_t u32_nvFlashAddr, STRU_NV_DATA *pst_nvDataPrc);

static int32_t NV_WriteFlashProc(void);

static int32_t NV_UpdateBbRcId(uint8_t *u8_bbRcId, uint8_t *u8_bbVtId);

static int32_t NV_UpdateChipId(uint8_t *chipId);

static int32_t NV_Update(void *par);

static void NV_Save(void *par);


static int32_t NV_SetDefaultValue(void);

static int32_t NV_ReadFromFlash(uint32_t u32_nvFlashAddr, STRU_NV_DATA *pst_nvDataPrc);

static int32_t NV_Get(void);

static int32_t NV_SetDefaultValueBbRcId(STRU_NV_DATA *pst_nvDataUpd);

static int32_t NV_CalChk(STRU_NV_DATA *pst_nvData, uint8_t *u8_chk);

static int32_t NV_CheckValidity(STRU_NV_DATA *pst_nvData);

static void NV_GetInit(void);

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_WriteToFlash(uint32_t u32_nvFlashAddr, STRU_NV_DATA *pst_nvDataPrc)
{
    NV_CalChk(pst_nvDataPrc, &(pst_nvDataPrc->u8_nvChk));

    // write to flash
    NOR_FLASH_WriteByteBuffer(u32_nvFlashAddr, 
                             (uint8_t *)pst_nvDataPrc, 
                             sizeof(STRU_NV_DATA));

    return 0;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_WriteFlashProc(void)
{
    int32_t s32_result = -1;
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;

    if ( (TRUE == (pst_nv->st_nvMng.u8_nvChg)) && 
         (TRUE != (pst_nv->st_nvMng.u8_nvUpd)) )
    {
        NOR_FLASH_EraseSector(NV_FLASH_ADDR1);

        pst_nv->st_nvMng.u8_nvPrc = TRUE;           
        memcpy((uint8_t *)(&(pst_nv->st_nvDataPrc)), 
               (uint8_t *)(&(pst_nv->st_nvDataUpd)), 
               sizeof(STRU_NV_DATA));
        pst_nv->st_nvMng.u8_nvPrc = FALSE;

        pst_nv->st_nvMng.u8_nvChg = FALSE;

        NV_WriteToFlash(NV_FLASH_ADDR1, &(pst_nv->st_nvDataPrc));
        DLOG_Warning("flash 1 write finished.");

        // write backup
        NOR_FLASH_EraseSector(NV_FLASH_ADDR2);
        NV_WriteToFlash(NV_FLASH_ADDR2, &(pst_nv->st_nvDataPrc));
        DLOG_Warning("flash 2 write finished.");
        
        s32_result = 0; 
    }
    else
    {
        ;
    }
    
    return s32_result;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_UpdateBbRcId(uint8_t *u8_bbRcId, uint8_t *u8_bbVtId)
{
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;

    memcpy(pst_nv->st_nvDataUpd.u8_nvBbRcId, u8_bbRcId, 5);
    memcpy(pst_nv->st_nvDataUpd.u8_nvBbVtId, u8_bbVtId, 2);

    NV_CalChk(&(pst_nv->st_nvDataUpd), &(pst_nv->st_nvDataUpd.u8_nvChk));
    pst_nv->st_nvMng.u8_nvChg = TRUE;

    DLOG_Info("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
               pst_nv->st_nvDataUpd.u8_nvBbRcId[0],
               pst_nv->st_nvDataUpd.u8_nvBbRcId[1],
               pst_nv->st_nvDataUpd.u8_nvBbRcId[2],
               pst_nv->st_nvDataUpd.u8_nvBbRcId[3],
               pst_nv->st_nvDataUpd.u8_nvBbRcId[4], 
               pst_nv->st_nvDataUpd.u8_nvChk);


    return 0;
}

static int32_t NV_UpdateChipId(uint8_t *chipId)
{
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;

    memcpy(pst_nv->st_nvDataUpd.u8_nvChipId, chipId, 5);

    NV_CalChk(&(pst_nv->st_nvDataUpd), &(pst_nv->st_nvDataUpd.u8_nvChk));
    pst_nv->st_nvMng.u8_nvChg = TRUE;

    DLOG_Warning("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
               pst_nv->st_nvDataUpd.u8_nvChipId[0],
               pst_nv->st_nvDataUpd.u8_nvChipId[1],
               pst_nv->st_nvDataUpd.u8_nvChipId[2],
               pst_nv->st_nvDataUpd.u8_nvChipId[3],
               pst_nv->st_nvDataUpd.u8_nvChipId[4], 
               pst_nv->st_nvDataUpd.u8_nvChk);


    return 0;
}



/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_Update(void *par)
{
    uint32_t u32_delay = 0;
    // uint8_t *u8_pdata = (uint8_t *)par;
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;
    STRU_SysEvent_NvMsg *pst_nvMsg = (STRU_SysEvent_NvMsg *)par;

    while ((TRUE == (pst_nv->st_nvMng.u8_nvPrc)) && (u32_delay < NV_UPD_MAX_DELAY))
    {
        u32_delay += 1;
    }
    
    if (u32_delay >= NV_UPD_MAX_DELAY)
    {
        return -1;
    }

    if( INTER_CORE_CPU0_ID == (pst_nvMsg->u8_nvDst)) // dst:cpu0
    {
        if(NV_NUM_RCID == (pst_nvMsg->e_nvNum))
        {
            NV_UpdateBbRcId(&(pst_nvMsg->u8_nvPar[1]), &(pst_nvMsg->u8_nvPar[6]));
        }
        else if(NV_NUM_CHIPID == (pst_nvMsg->e_nvNum))
        {
            NV_UpdateChipId(&(pst_nvMsg->u8_nvPar[0]));
        }
        else
        {
            ;
        }
    }

    return 0;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static void NV_Save(void *par)
{
    NV_Update(par);

    NV_WriteFlashProc();
}

HAL_RET_T HAL_NV_SaveChipId(void *par)
{
    STRU_SysEvent_NvMsg st_nvMsg;

    // src:cpu0 dst:cpu0
    st_nvMsg.u8_nvSrc = INTER_CORE_CPU0_ID;
    st_nvMsg.u8_nvDst = INTER_CORE_CPU0_ID;

    // parament number
    st_nvMsg.e_nvNum = NV_NUM_CHIPID;

    // parament set
    memcpy(&(st_nvMsg.u8_nvPar[0]), par, 5);
    
    // send msg
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_NV_MSG, (void *)(&(st_nvMsg)));
    
    return HAL_OK;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_SetDefaultValue(void)
{
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;

    pst_nv->st_nvMng.u8_nvUpd = TRUE;

    // set baseband rc default id
    NV_SetDefaultValueBbRcId(&(pst_nv->st_nvDataUpd));
 
    // update checksum.
    NV_CalChk(&(pst_nv->st_nvDataUpd), &(pst_nv->st_nvDataUpd.u8_nvChk));

    // default value is not stored in flash,only update to sram
    //pst_nv->st_nvMng.u8_nvChg = TRUE;

    pst_nv->st_nvMng.u8_nvUpd = FALSE;

    return 0;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_ReadFromFlash(uint32_t u32_nvFlashAddr, STRU_NV_DATA *pst_nvDataPrc)
{
    NOR_FLASH_ReadByteBuffer(u32_nvFlashAddr, 
                            (uint8_t *)pst_nvDataPrc, 
                            sizeof(STRU_NV_DATA));
    
    return 0;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_Get(void)
{
    // uint8_t u8_checkSum;
    int32_t result = -1;
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;

    NV_ReadFromFlash(NV_FLASH_ADDR1, &(pst_nv->st_nvDataPrc));

    if (0 == NV_CheckValidity(&(pst_nv->st_nvDataPrc)))
    {
        memcpy((uint8_t *)(&(pst_nv->st_nvDataUpd)), 
               (uint8_t *)(&(pst_nv->st_nvDataPrc)), 
               sizeof(STRU_NV_DATA));
        DLOG_Info("flash1 chk ok");
        result = 0;
    }
    else
    {
        DLOG_Error("flash1 chk error");
    }
    
    if (0 != result)
    {
        NV_ReadFromFlash(NV_FLASH_ADDR2, &(pst_nv->st_nvDataPrc));

        if (0 == NV_CheckValidity(&(pst_nv->st_nvDataPrc)))
        {
            DLOG_Info("flash2 chk ok");
            result = 0;
        }
        else
        {
            DLOG_Error("flash2 chk error");
        }
        memcpy((uint8_t *)(&(pst_nv->st_nvDataUpd)), 
               (uint8_t *)(&(pst_nv->st_nvDataPrc)), 
               sizeof(STRU_NV_DATA));
    }
    
    memcpy((uint8_t *)(SRAM_SHARE_FLAG_ST_ADDR + SHARE_FLAG_CHIP_ID_OFFSET), pst_nv->st_nvDataUpd.u8_nvChipId, 5);

    DLOG_Warning("rc id:%x %x %x %x %x, vt id:%x %x, chip id:%x %x %x %x %x",
                pst_nv->st_nvDataUpd.u8_nvBbRcId[0],pst_nv->st_nvDataUpd.u8_nvBbRcId[1],pst_nv->st_nvDataUpd.u8_nvBbRcId[2],pst_nv->st_nvDataUpd.u8_nvBbRcId[3],pst_nv->st_nvDataUpd.u8_nvBbRcId[4],
                pst_nv->st_nvDataUpd.u8_nvBbVtId[0],pst_nv->st_nvDataUpd.u8_nvBbVtId[1],
                pst_nv->st_nvDataUpd.u8_nvChipId[0],pst_nv->st_nvDataUpd.u8_nvChipId[1],pst_nv->st_nvDataUpd.u8_nvChipId[2],pst_nv->st_nvDataUpd.u8_nvChipId[3],pst_nv->st_nvDataUpd.u8_nvChipId[4]);

    return result;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_SetDefaultValueBbRcId(STRU_NV_DATA *pst_nvDataUpd)
{
    memcpy(pst_nvDataUpd->u8_nvBbRcId, (uint8_t *)(SRAM_SHARE_FLAG_ST_ADDR + SHARE_FLAG_CHIP_ID_OFFSET), 5);
    pst_nvDataUpd->u8_nvChk = 0; // set to check error

    return 0;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_CalChk(STRU_NV_DATA *pst_nvData, uint8_t *u8_chk)
{
    uint32_t u32_nvDataLen;
    uint32_t u32_i;
    uint8_t u8_checkSum = 0;
    uint8_t *p_u8Addr;

    u32_nvDataLen = sizeof(STRU_NV_DATA);
    u32_i = sizeof(pst_nvData->u8_nvChk);
    p_u8Addr = (uint8_t *)pst_nvData;

    uint32_t i;
    //calculate checkSum
    for ( i = u32_i; i < u32_nvDataLen; i++)
    {
        u8_checkSum += *(p_u8Addr + i);
    }

    *u8_chk = u8_checkSum;

    return 0;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static int32_t NV_CheckValidity(STRU_NV_DATA *pst_nvData)
{
    uint8_t u8_checkSum;
    uint32_t u32_nvDataLen;
    uint32_t u32_i = 0;
    uint8_t *p_u8Addr;

    u32_nvDataLen = sizeof(STRU_NV_DATA);
    p_u8Addr = (uint8_t *)pst_nvData;
    while (u32_i < u32_nvDataLen)
    {
        if (0xFF != p_u8Addr[u32_i])
        {
            break;
        }
        u32_i += 1;
    }

    NV_CalChk(pst_nvData, &u8_checkSum);

    if (((pst_nvData->u8_nvChk) == u8_checkSum) && (u32_i < u32_nvDataLen))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
static void NV_GetInit(void)
{
    STRU_NV *pst_nv = (STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;

    if (-1 == NV_Get())
    {
        pst_nv->st_nvMng.u8_nvVld = FALSE;
    }    
    else
    {
        pst_nv->st_nvMng.u8_nvVld = TRUE;
    }
}


HAL_RET_T NV_DataWrite(uint32_t addr, uint8_t *wdata, uint32_t wlen);
HAL_RET_T NV_DataRead(uint32_t addr, uint8_t *rdata, uint32_t rlen);

/**
* @brief      
* @param    
* @retval   
* @note   
*/
HAL_RET_T HAL_NV_Init(void)
{
    // uint8_t pwr[32];
    // HAL_RET_T ret;
    volatile STRU_NV *pst_nv = (volatile STRU_NV *)SRAM_NV_MEMORY_ST_ADDR;
    memset((void *)pst_nv, 0, SRAM_NV_MEMORY_SIZE);
    if (1 == EFUSE_GetEfuseEnable())
    {
        EFUSE_CtrFlashWriteEfuse(1);
    }
    HAL_NORFLASH_Init();
   
    NV_GetInit();

    SYS_EVENT_RegisterHandler(SYS_EVENT_ID_NV_MSG, NV_Save);

    memset((uint8_t *)SRAM_USR_NV_MEMORY_ST_ADDR, 0x00, SRAM_USR_NV_MEMORY_SIZE);

    pst_nv->st_nvMng.u32_nvInitFlag = 0x23178546;

    return HAL_OK;
}

/**
* @brief      
* @param    
* @retval   
* @note   
*/
HAL_RET_T HAL_NV_ResetBbRcId(void)
{
    STRU_SysEvent_NvMsg st_nvMsg;

    // src:cpu0 dst:cpu2
    st_nvMsg.u8_nvSrc = INTER_CORE_CPU0_ID;
    st_nvMsg.u8_nvDst = INTER_CORE_CPU0_ID;

    // parament number
    st_nvMsg.e_nvNum = NV_NUM_RCID;

    // parament set
    st_nvMsg.u8_nvPar[0] = 1;
    memset(&(st_nvMsg.u8_nvPar[1]), 0xFF, RC_ID_SIZE + VT_ID_SIZE);

    // send msg
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_NV_MSG, (void *)(&(st_nvMsg)));

    return HAL_OK;
}


#define             USR_STORAGE_ST_ADDR     NV_FLASH_USR_ADDR1
#define             USR_STORAGE_LEN         (60*1024)
#define             FLASH_SEC_LEN           (4096)
#define             USR_SEC_LEN             (4092)
#define             BACKUP_OFFSET           NV_FLASH_USR_SIZE

#define             CHECK_INTERVAL          (512)
#define             CHECK_ADD_INFO          (0)


static int32_t NV_UsrAddr2FlashAddr(uint32_t uAddr, uint32_t *fAddr);
static int32_t NV_GetSecInfoByAddr(uint32_t fAddr, uint32_t *secStartAddr, uint32_t *secOffsetAddr);
static int32_t NV_ReadOneSec(uint32_t secStartAddr, uint8_t *buff);
static int32_t NV_WriteOneSec(uint32_t secStartAddr, uint8_t *buff);
static int32_t NV_CheckSecValid(uint32_t secStartAddr);
static int32_t NV_UsrDataWriteToFlash(uint32_t uAddr, uint32_t addrOffset, uint8_t *wData, uint32_t wLen);
static int32_t NV_UsrDataWrite(uint32_t uAddr, uint8_t *wData, uint32_t wLen);


static int32_t NV_UsrAddr2FlashAddr(uint32_t uAddr, uint32_t *fAddr)
{
    uint32_t align;
    uint32_t unAlign;

    align = uAddr / USR_SEC_LEN;
    unAlign = uAddr % USR_SEC_LEN;

    *fAddr = USR_STORAGE_ST_ADDR + align * FLASH_SEC_LEN + unAlign;

    return 0;
}

static int32_t NV_GetSecInfoByAddr(uint32_t fAddr, uint32_t *secStartAddr, uint32_t *secOffsetAddr)
{
    *secStartAddr = (fAddr / FLASH_SEC_LEN) * FLASH_SEC_LEN;
    *secOffsetAddr = fAddr % FLASH_SEC_LEN;
    
    return 0;
}

static int32_t NV_ReadOneSec(uint32_t secStartAddr, uint8_t *buff)
{
    NOR_FLASH_ReadByteBuffer(secStartAddr, buff, FLASH_SEC_LEN);

    return 0;
}

static int32_t NV_WriteOneSec(uint32_t secStartAddr, uint8_t *buff)
{
    uint32_t offset = 0;
    uint32_t check = 0;

    while(offset < USR_SEC_LEN)
    {
        check += *(uint32_t *)(&buff[offset]);
        offset += CHECK_INTERVAL;
    }
    check += CHECK_ADD_INFO;

    *(uint32_t *)(&buff[USR_SEC_LEN]) = check;

    NOR_FLASH_WriteByteBuffer(secStartAddr, buff, FLASH_SEC_LEN);
    
    return 0;
}

static int32_t NV_CheckSecValid(uint32_t secStartAddr)
{
    uint8_t data[4];
    uint32_t offset = 0;
    uint32_t calcCheck = 0;
    uint32_t flashCheck = 0;

    while(offset < USR_SEC_LEN)
    {
        NOR_FLASH_ReadByteBuffer(secStartAddr + offset, data, 4);
        calcCheck += *(uint32_t *)(&data[0]);
        offset += CHECK_INTERVAL;
    }
    calcCheck += CHECK_ADD_INFO;

    NOR_FLASH_ReadByteBuffer(secStartAddr + USR_SEC_LEN, data, 4);
    flashCheck = *(uint32_t *)(&data[0]);

    if(calcCheck == flashCheck)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
static uint8_t g_secBuffer[FLASH_SEC_LEN];
static int32_t NV_UsrDataWriteToFlash(uint32_t uAddr, uint32_t addrOffset, uint8_t *wData, uint32_t wLen)
{
    uint32_t writedLen = 0;
    uint32_t fAddr;
    uint32_t secStartAddr;
    uint32_t secResLen;
    uint32_t secOffsetAddr;

    while(writedLen < wLen)
    {
        NV_UsrAddr2FlashAddr(uAddr + writedLen, &fAddr);
        fAddr += addrOffset;
        
        NV_GetSecInfoByAddr(fAddr, &secStartAddr, &secOffsetAddr);
        secResLen = USR_SEC_LEN - secOffsetAddr;
        secResLen = ((wLen - writedLen) > secResLen) ? (secResLen) : (wLen - writedLen);
        if((0 != secOffsetAddr) || (USR_SEC_LEN != secResLen))
        {
            NV_ReadOneSec(secStartAddr, g_secBuffer);
        }
        
        NOR_FLASH_EraseSector(secStartAddr);
        
        memcpy(&g_secBuffer[secOffsetAddr], &wData[writedLen], secResLen);
        
        NV_WriteOneSec(secStartAddr, g_secBuffer);

        writedLen += secResLen;
    }

    return 0;
}

static int32_t NV_UsrDataWrite(uint32_t uAddr, uint8_t *wData, uint32_t wLen)
{
    if ((uAddr + wLen) > USR_STORAGE_LEN)
    {
        DLOG_Error("range overrun");
        return HAL_NV_ERR;
    }

    NV_UsrDataWriteToFlash(uAddr, 0, wData, wLen);

    // backup
    NV_UsrDataWriteToFlash(uAddr, BACKUP_OFFSET, wData, wLen);

    return HAL_OK;
}

HAL_RET_T NV_DataWrite(uint32_t uAddr, uint8_t *wData, uint32_t wLen)
{
	HAL_RET_T ret;

    if (-1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0))
    {
        DLOG_Critical("fail, MUTEX_NOR_FLASH = %d", 0);
        return HAL_OCCUPIED;
    }


	COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);

    ret = NV_UsrDataWrite(uAddr, wData, wLen);    

	COMMON_driverMutexFree(MUTEX_NOR_FLASH, 0);


	return ret;    
}

#ifdef AR8020_MP_INFO_RECORD
#define NV_FLASH_BORAD_MP_OFFSET				(4 * 1024)
#else
#define NV_FLASH_BORAD_MP_OFFSET				(0)
#endif

HAL_RET_T HAL_NV_UsrDataWrite(uint32_t uAddr, uint8_t *wData, uint32_t wLen)
{
	HAL_RET_T ret;

	ret = NV_DataWrite(uAddr + NV_FLASH_BORAD_MP_OFFSET, wData, wLen);

	return ret;
}

HAL_RET_T NV_DataRead(uint32_t uAddr, uint8_t *rData, uint32_t rLen)
{
    uint32_t readLen = 0;
    uint32_t fAddr;
    uint32_t secStartAddr;
    uint32_t secResLen;
    uint32_t secOffsetAddr;
	HAL_RET_T ret = HAL_OK;

    if ((uAddr + rLen) > USR_STORAGE_LEN)
    {
        DLOG_Error("range overrun");
        return HAL_NV_ERR;
    }

    if (-1 == COMMON_driverMutexGet(MUTEX_NOR_FLASH, 0))
    {
        DLOG_Error("fail, MUTEX_NOR_FLASH = %d", 0);
        return HAL_OCCUPIED;
    }

    COMMON_driverMutexSet(MUTEX_NOR_FLASH, 0);

    while(readLen < rLen)
    {
        NV_UsrAddr2FlashAddr(uAddr + readLen, &fAddr);
        
        NV_GetSecInfoByAddr(fAddr, &secStartAddr, &secOffsetAddr);
        secResLen = USR_SEC_LEN - secOffsetAddr;
        secResLen = ((rLen - readLen) > secResLen) ? (secResLen) : (rLen - readLen);

        if(1 == NV_CheckSecValid(secStartAddr))
        {
            NOR_FLASH_ReadByteBuffer(secStartAddr + secOffsetAddr, &rData[readLen], secResLen);
        }
        else
        {
            DLOG_Error("1 err - 0x%lx", secStartAddr);
            if(1 == NV_CheckSecValid(secStartAddr+ BACKUP_OFFSET))
            {
                NOR_FLASH_ReadByteBuffer(secStartAddr + secOffsetAddr + BACKUP_OFFSET, &rData[readLen], secResLen);
            }
            else
            {
                DLOG_Error("2 err - 0x%lx", secStartAddr+ BACKUP_OFFSET);
                ret = HAL_NV_ERR;
                break;
            }
        }
        
        readLen += secResLen;
    }

	COMMON_driverMutexFree(MUTEX_NOR_FLASH, 0);

    return ret;
}

HAL_RET_T HAL_NV_UsrDataRead(uint32_t uAddr, uint8_t *rData, uint32_t rLen)
{

	HAL_RET_T ret = HAL_OK;

	ret = NV_DataRead(uAddr + NV_FLASH_BORAD_MP_OFFSET, rData, rLen);

	return ret;
}



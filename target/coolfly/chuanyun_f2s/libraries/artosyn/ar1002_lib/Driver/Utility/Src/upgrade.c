#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "upgrade.h"
#include "bb_ctrl_internal.h"
#include "debuglog.h"
#include "md5.h"
#include "ff.h"
#include "hal_bb.h"
#include "hal.h"
#include "hal_norflash.h"
#include "hal_usb_host.h"
#include "efuse.h"
#include "reg_rw.h"
 
#include "image_struct.h"
#include "hal_sram_sky.h"
#include "hal_hdmi_rx.h"

#include "drv_systick.h"


#define UPGRADE_SESSION         BB_COM_SESSION_2

static uint32_t s_u32_imageAddr = RECEIVE_ADDR;
// static uint8_t s_u8EncryptFlag = 0;

typedef struct _STRU_upgardeMsg
{
    uint8_t pid;
    union
    {
        struct
        {
            uint8_t  u8_opt;
            uint8_t  u8_md5[16];
            uint16_t u16_data[3];
        }upgradeDataPack;
    } par;
} STRU_upgardeMsg;


void UPGRADE_GNDInit(void);

static uint8_t s_u8_upgradeStatus = 0;
//next data block number
static uint16_t s_u16_dataBlockNum = 0;
//lose data block number
static uint16_t s_u16_lostDataBlockArray[UPGRADE_MAX_BLOCKARRAYSIZE];
//lose data block number count
static uint16_t s_u16_lostDataBlockCount = 0;
//receive data length
static uint32_t s_u32_upgradeRecDataLen = 0;
//file size
static uint32_t s_u32_upgradeTotalDataLen = 0;
//sky :total data block count
//ground :present send data block number
static uint16_t s_u16_upgradeReturnStatus = 0;

int8_t UpgradeState_Reset(void)
{
    s_u8_upgradeStatus = 0;
    return 0;
}

int8_t UpgradeGndState_Clear(ENUM_UPGRADE_GROUND_STATE e_state)
{
    s_u8_upgradeStatus &= (~(1 << e_state));
    return 0;
}

int8_t UpgradeSkyState_Clear(ENUM_UPGRADE_SKY_STATE e_state)
{
    s_u8_upgradeStatus &= (~(1 << e_state));
    return 0;
}

int8_t UpgradeGndState_Set(ENUM_UPGRADE_GROUND_STATE e_state)
{
    s_u8_upgradeStatus |= 1 << e_state;
    return 0;
}

int8_t UpgradeSkyState_Set(ENUM_UPGRADE_SKY_STATE e_state)
{
    s_u8_upgradeStatus |= 1 << e_state;
    return 0;
}

int8_t UpgradeGndStatus_Get(ENUM_UPGRADE_GROUND_STATE e_state)
{
    if (1 == ((s_u8_upgradeStatus >> e_state) & 1))
    {
        UpgradeGndState_Clear(UPGRADE_ACK_LOSTDATA);
        return 1;
    }
    else
    {
        return ((s_u8_upgradeStatus >> e_state) & 1);
    }
}

int8_t UpgradeSkyState_Get(ENUM_UPGRADE_SKY_STATE state)
{
    return ((s_u8_upgradeStatus >> state) & 1);
}

void UPGRADE_GetStatus(STRU_UPGRADE_STATUS * pst_status)
{
    pst_status->u16_lostDataBlockCount = s_u16_lostDataBlockCount;
    memcpy(pst_status->u16_lostDataBlockArray, s_u16_lostDataBlockArray, s_u16_lostDataBlockCount*sizeof(uint16_t));
}

static void insertion_sort_u16(uint16_t *buff, uint16_t Length)
{
    uint16_t temp = 0;
    uint16_t i =0, j = 0;
    for (i = 1; i < Length; i++)
    {
        if (buff[i - 1] > buff[i])
        {
            temp = buff[i];
            j = i;
            while (j > 0 && buff[j - 1] > temp)
            {
                buff[j] = buff[j - 1];
                j--;
            }
            buff[j] = temp;
        }
    }
}



// osSemaphoreId bb_send_semaphore_id;

// session_4 send data 
static uint32_t UPGRADE_SendMsg(const STRU_upgardeMsg *pst_pack, const uint8_t *pu8_buff, uint16_t u16_dataLen)
{
    uint8_t u8_msgArray[1024];
    // uint8_t  md5_value[MD5_SIZE];
    uint32_t u32_count = sizeof(STRU_upgardeMsg);
    HAL_RET_T ret;
    if (u16_dataLen + u32_count > 1024)
    {
        DLOG_Error("send data overflow, sizeof(STRU_upgardeMsg) + u16_dataLen > 1024");
        return 1;
    }

    memcpy(u8_msgArray, pst_pack, u32_count);
 
    if ((NULL != pu8_buff) && (0 != u16_dataLen))
    {
        memcpy(&u8_msgArray[u32_count], pu8_buff, u16_dataLen);
        u32_count += u16_dataLen;
    } 
    
    // osSemaphoreWait(bb_send_semaphore_id, 0);
    ret = HAL_BB_ComSendMsg(UPGRADE_SESSION, u8_msgArray, u32_count);
    // osSemaphoreRelease(bb_send_semaphore_id);

    return ret;
}

static int8_t MD5SUM_Generate(uint8_t *pu8_addr, uint32_t u32_dataLen, uint8_t *pu8_md5)
{
    uint8_t  md5_value[MD5_SIZE] = {0};

    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5, pu8_addr, u32_dataLen);
    MD5Final(&md5, md5_value);

    
    if (NULL != pu8_md5)
    {
        memcpy(pu8_md5, md5_value, MD5_SIZE);
    }

    return 0; 
    
}

int8_t UPGRADE_CheckUpgradeLocalFile(const uint8_t *fileName)
{
    FRESULT    fileResult;
    FIL        MyFile;
    uint32_t   u32_bytesRead = UPGRADE_DATACHUNK_SIZE;
    uint8_t  u8_sendDataArray[UPGRADE_DATACHUNK_SIZE];
    uint32_t  i = 0;
    STRU_SysEvent_H264InputFormatChangeParameter  st_formatChange;

    //swtich sky mode
    Reg_Write32(0x40B00068, 0x01);


    // close view 0
    st_formatChange.index = 0;
    st_formatChange.width = 0;
    st_formatChange.hight = 0;
    st_formatChange.framerate = 0;
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange);
    
    // close view 1
    st_formatChange.index = 1;
    st_formatChange.width = 0;
    st_formatChange.hight = 0;
    st_formatChange.framerate = 0;
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange);

    HAL_Delay(20);

    fileResult = f_open(&MyFile, (char *)fileName, FA_READ);
    if (FR_OK != fileResult)
    {
        DLOG_Error("open or create file error: %d\n", fileResult);
        return -1;
    }
    
    //MD5Init(&md5);
    u32_bytesRead = UPGRADE_DATACHUNK_SIZE;
    
    DLOG_Critical("read image from U-Disk");

    while(UPGRADE_DATACHUNK_SIZE == u32_bytesRead)
    {            
        do
        {
            u32_bytesRead = 0;

            fileResult = f_read(&MyFile, (void *)u8_sendDataArray, UPGRADE_DATACHUNK_SIZE, (void *)&u32_bytesRead);

            if (fileResult != FR_OK)
            {
                DLOG_Critical("read image fail");
            }

            HAL_Delay(1);
        } while (FR_OK != fileResult);

        memcpy((uint8_t *)(s_u32_imageAddr + UPGRADE_DATACHUNK_SIZE * i), u8_sendDataArray, u32_bytesRead);        
        s_u32_upgradeTotalDataLen += u32_bytesRead;
        i++;         
    }
    s_u32_upgradeTotalDataLen -= IMAGE_HEAD;
    f_close(&MyFile);

    return UPGRADE_MD5SUM(s_u32_imageAddr, 1);

}

int8_t UPGRADE_CheckUpgradeRemoteFile(const uint8_t *fileName)
{
    FRESULT    fileResult;
    FIL        MyFile;
    uint32_t   u32_bytesRead = UPGRADE_DATACHUNK_SIZE;
    uint8_t  u8_sendDataArray[UPGRADE_DATACHUNK_SIZE];
    uint32_t i = 0;
    MD5_CTX  md5;
    uint8_t  md5_value[MD5_SIZE];
    uint8_t  u8Amd5Sum[MD5_SIZE];


    fileResult = f_open(&MyFile, (char *)fileName, FA_READ);
    if (FR_OK != fileResult)
    {
        DLOG_Error("open or create file error: %d\n", fileResult);
        return -1;
    }
    
    MD5Init(&md5);
    u32_bytesRead = UPGRADE_DATACHUNK_SIZE;
    
    while(UPGRADE_DATACHUNK_SIZE == u32_bytesRead)
    {            
        fileResult = f_read(&MyFile, (void *)u8_sendDataArray, UPGRADE_DATACHUNK_SIZE, (void *)&u32_bytesRead);
        if((fileResult != FR_OK))
        {
            DLOG_Error("Cannot Read from the file \n");
            f_close(&MyFile);
            
        }
        if(s_u32_upgradeTotalDataLen != 0)
        {               
           MD5Update(&md5, u8_sendDataArray, u32_bytesRead);
        }
        else
        {                
            memcpy(u8Amd5Sum, &u8_sendDataArray[IMAGE_MD5SUMOFFSET], MD5_SIZE);
            MD5Update(&md5, &(u8_sendDataArray[IMAGE_HEAD]), (u32_bytesRead-IMAGE_HEAD));
        }        
        s_u32_upgradeTotalDataLen += u32_bytesRead;         
    }

    MD5Final(&md5, md5_value);  
    if (0 != memcmp(md5_value, u8Amd5Sum, MD5_SIZE))
    {
        DLOG_Info("file checksum ..fail\n");
        for(i=0;i<MD5_SIZE;i++)
        {
            DLOG_Error(" md5 %02x %02x",md5_value[i], u8Amd5Sum[i]);
        }
        return -1;
    }
    else
    {
        DLOG_Critical("file checksum .ok\n");
        return 0;
    }
    f_close(&MyFile);

}



unsigned long u32_mask;
uint32_t UPGRADE_SendDataBlock(uint8_t u8_opt, uint8_t *pu8_dataBuff, uint16_t u16_dataLen, uint16_t u16_dataBlockNum)
{
    STRU_upgardeMsg st_upgrade;
    st_upgrade.pid = DT_NUM_SKY_UPGRADE;
    st_upgrade.par.upgradeDataPack.u8_opt = u8_opt;
    st_upgrade.par.upgradeDataPack.u16_data[0] = u16_dataBlockNum;
    st_upgrade.par.upgradeDataPack.u16_data[1] = u16_dataLen;
    st_upgrade.par.upgradeDataPack.u16_data[2] = 0;

    MD5SUM_Generate(pu8_dataBuff, u16_dataLen, st_upgrade.par.upgradeDataPack.u8_md5);


    return UPGRADE_SendMsg(&st_upgrade, pu8_dataBuff, u16_dataLen);    
}

static void UPGRADE_rcvFailed_proc(STRU_upgardeMsg *st)
{
	st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_FAIL;
	while (0 != UPGRADE_SendMsg(st, NULL, 0))
	{
	    HAL_Delay(UPGRADE_DELAY);
	}
	DLOG_Error("lose data count overflow %d", s_u16_lostDataBlockCount);
}



static void UPGRADE_rcvInit_proc(STRU_upgardeMsg *st)
{

    s_u16_dataBlockNum = 0;
    s_u16_lostDataBlockCount = 0;
    memset(s_u16_lostDataBlockArray, 0xff, sizeof(s_u16_lostDataBlockArray));

    STRU_SysEvent_H264InputFormatChangeParameter  st_formatChange = {0};
    
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange); // close view 0
    st_formatChange.index = 1;
    SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_H264_INPUT_FORMAT_CHANGE, (void*)&st_formatChange); // close view 1

    HAL_SRAM_DisableSkyBypassVideo(0);
    HAL_SRAM_DisableSkyBypassVideo(1);
    (*(volatile uint32_t *)0xA0030078) = 0;
    (*(volatile uint32_t *)0xA0030078) = 1;
    //check sdram init ok
    while(!((*(volatile uint32_t *)0xA0030024)) & 0x01)
    {
    ;
    }
    HAL_HDMI_RX_UnInit(HAL_HDMI_RX_1);
    UpgradeSkyState_Set(UPGRADE_DATA_INIT);


    st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_INIT;
    s_u16_upgradeReturnStatus = st->par.upgradeDataPack.u16_data[0];
    // reply ground init ok
    while (0 != UPGRADE_SendMsg(st, NULL, 0))
    {
		HAL_Delay(UPGRADE_DELAY);
    }
    DLOG_Critical("UPGRADE_DATA_INIT %d",s_u16_upgradeReturnStatus);	
}

static void UPGRADE_rcvPacket_proc(STRU_upgardeMsg *st, uint8_t *u8_recDataArray, uint16_t u16_dataBlockNum, uint16_t u16_dataLen)
{
    uint8_t  md5_value[MD5_SIZE];
    uint16_t i = 0;
    //receive data
    u16_dataBlockNum = st->par.upgradeDataPack.u16_data[0];
    u16_dataLen = st->par.upgradeDataPack.u16_data[1];
    

    MD5SUM_Generate(&u8_recDataArray[sizeof(STRU_upgardeMsg)], u16_dataLen, md5_value);

    //check md5
    if (0 != memcmp(md5_value, st->par.upgradeDataPack.u8_md5, MD5_SIZE))
    {
        DLOG_Error("md5 fail %x %x %x %x %x %x", st->pid, st->par.upgradeDataPack.u8_opt, st->par.upgradeDataPack.u16_data[0], 
    			st->par.upgradeDataPack.u16_data[1], st->par.upgradeDataPack.u16_data[2], u8_recDataArray[sizeof(STRU_upgardeMsg)]);
    }
    else
    {	       
        memcpy((uint8_t *)(s_u32_imageAddr + UPGRADE_DATACHUNK_SIZE * u16_dataBlockNum), &u8_recDataArray[sizeof(STRU_upgardeMsg)],u16_dataLen);
        if (UPGRADE_DATA_DATA == st->par.upgradeDataPack.u8_opt)
        {
    	    //if receive data number lose, storage lose num.
    	    // DLOG_Critical("UPGRADE_DATA_DATA %d %d %d%%\n", u16_dataBlockNum, u16_dataLen, (s_u16_dataBlockNum*100/s_u16_upgradeReturnStatus));
    	    if (s_u16_dataBlockNum != st->par.upgradeDataPack.u16_data[0])
    	    {
    	       for (i = s_u16_dataBlockNum; i < st->par.upgradeDataPack.u16_data[0]; i++)
    	       {
    	           if (s_u16_lostDataBlockCount < UPGRADE_MAX_BLOCKARRAYSIZE)
    		        s_u16_lostDataBlockArray[s_u16_lostDataBlockCount] = i;
    	           if(++s_u16_lostDataBlockCount >= UPGRADE_MAX_BLOCKARRAYSIZE)
    		        UPGRADE_rcvFailed_proc(st);	//Notify the ground side, the upgrade failed
    	       
    	           DLOG_Error("lose block %d ,u16_data[0] = %d", i, st->par.upgradeDataPack.u16_data[0]);
    	       }
    	    }
    	    s_u32_upgradeRecDataLen += u16_dataLen; 	
    	    s_u16_dataBlockNum = u16_dataBlockNum + 1;	
        }
        else
        {
            for (i = 0; i < s_u16_lostDataBlockCount; i++)
            {
                if (u16_dataBlockNum == s_u16_lostDataBlockArray[i])
	        	{
	        	    s_u16_lostDataBlockArray[i] = 0xffff;
	        	    s_u32_upgradeRecDataLen += u16_dataLen;
	        	    insertion_sort_u16(s_u16_lostDataBlockArray, s_u16_lostDataBlockCount); 			       
	        	    s_u16_lostDataBlockCount--;
	        	    DLOG_Critical("rec lost data match %d", u16_dataBlockNum);
	        	    continue;
	        	}
            }
        }
    }
}


__attribute__((weak)) void board_reset_all(void)
{

}


static void UPGRADE_rcvEnd_proc(STRU_upgardeMsg *st)
{
    DLOG_Critical("UPGRADE_DATA_END %d",s_u16_lostDataBlockCount);
  
    if(s_u16_lostDataBlockCount == 0)	    //successful
    {
	    st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_CHECK;
	    while (0 != UPGRADE_SendMsg(st, NULL, 0))
	    {
	        HAL_Delay(UPGRADE_DELAY);
	    }
	    UpgradeSkyState_Set(UPGRADE_UPGRADE_CHECK);
	    s_u32_upgradeTotalDataLen = s_u32_upgradeRecDataLen - IMAGE_HEAD;
        if (-1 == UPGRADE_MD5SUM(s_u32_imageAddr, 1))
        {
            st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_FAIL;
            DLOG_Error("Md5 check fail");
            return;
        }
        else
        {
            if (0 == UpgradeSkyState_Get(UPGRADE_UPGRADE_END))
            {			    
                if (0 == UPGRADE_ModifyBootInfo(APPLICATION_IMAGE_START0))   
                {
                    DLOG_Critical("upgrade ok"); DLOG_Output(100);
                    st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_END_CF_SUCCESS;
                }
                else
                {
                    DLOG_Critical("upgrade fail"); DLOG_Output(100);
                    st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_FAIL;
                }			 
            }
            UpgradeSkyState_Set(UPGRADE_UPGRADE_END);	     
        }
        while(1)
        {
            while (0 != UPGRADE_SendMsg(st, NULL, 0))
            {
                HAL_Delay(UPGRADE_DELAY);
            }
            DLOG_Critical("send upgrade status1"); DLOG_Output(100);
            while (0 != UPGRADE_SendMsg(st, NULL, 0))
            {
                HAL_Delay(UPGRADE_DELAY);
            }
            DLOG_Critical("send upgrade status2"); DLOG_Output(100);
            HAL_Delay(1000);
            while (0 != UPGRADE_SendMsg(st, NULL, 0))
            {
                HAL_Delay(UPGRADE_DELAY);
            }
            DLOG_Critical("send upgrade status3"); DLOG_Output(100);

            board_reset_all();
        }
    }
    else if ( (s_u16_lostDataBlockCount > 0) && (s_u16_lostDataBlockCount <= UPGRADE_MAX_BLOCKARRAYSIZE)) //Lost packet
    {
		insertion_sort_u16(s_u16_lostDataBlockArray, UPGRADE_MAX_BLOCKARRAYSIZE);
		if (s_u16_lostDataBlockCount > 100)
		{
		    st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_LOSTDATA;
		    st->par.upgradeDataPack.u16_data[0] = 100;
		    while (0 != UPGRADE_SendMsg(st, (uint8_t *)(&s_u16_lostDataBlockArray[0]), 200))
		    {
			HAL_Delay(UPGRADE_DELAY);
		    }
		}
		else
		{
		    st->par.upgradeDataPack.u8_opt = UPGRADE_ACK_LOSTDATA;
		    st->par.upgradeDataPack.u16_data[0] = s_u16_lostDataBlockCount;
		    while (0 != UPGRADE_SendMsg(st, (uint8_t *)(&s_u16_lostDataBlockArray[0]), s_u16_lostDataBlockCount*sizeof(uint16_t)))
		    {
			HAL_Delay(UPGRADE_DELAY);
		    }
	        DLOG_Critical("lost data block list:\n");
	        for(int m = 0 ; m < s_u16_lostDataBlockCount;m++)
	        {
	            
	            DLOG_Critical("%04x ", s_u16_lostDataBlockArray[m]);
	        }
	        DLOG_Critical("lost data block list done.\n");
	    }
        
		DLOG_Critical("send lose data block %d", st->par.upgradeDataPack.u16_data[0]);
    }
    else{
		UPGRADE_rcvFailed_proc(st);
    }
}



void UPGRADE_rcvHandleSky(void *p)
{

    uint16_t u16_dataLen = 0;
    uint16_t u16_dataBlockNum = 0;
    uint8_t  u8_recDataArray[1024];

    STRU_upgardeMsg st;
    
    uint32_t u32_rcvLen = BB_ComReceiveMsg(UPGRADE_SESSION, u8_recDataArray, 1024);
    if ( (u32_rcvLen < sizeof(STRU_upgardeMsg)) || (DT_NUM_SKY_UPGRADE != u8_recDataArray[0]))
    {
        DLOG_Error("recv error");
        return;
    }
    
    memcpy(&st, u8_recDataArray, sizeof(STRU_upgardeMsg));    
    switch(st.par.upgradeDataPack.u8_opt)
    {
        case UPGRADE_DATA_INIT:
            UPGRADE_rcvInit_proc(&st);
            break;
        case UPGRADE_DATA_DATA:
        case UPGRADE_LOSTBLOCK_DATA:
    	    UPGRADE_rcvPacket_proc(&st, u8_recDataArray, u16_dataBlockNum, u16_dataLen);
            break;
        case UPGRADE_DATA_END:
            UPGRADE_rcvEnd_proc(&st);
    	    break;
        default :
            break;
    }

}

static void UPGRADE_rcvHandleGnd(void *p)
{
    uint32_t i = 0;
    uint32_t u32_rcvLen = 0;
    uint8_t rec_data[1024];
    
    STRU_upgardeMsg st_session;
    HAL_BB_ComReceiveMsg(UPGRADE_SESSION, (uint8_t *)&rec_data, 1024, &u32_rcvLen);
    memcpy(&st_session, rec_data, sizeof(STRU_upgardeMsg));
    switch (st_session.par.upgradeDataPack.u8_opt)
    {
        case UPGRADE_ACK_INIT: 
        {
            memset(s_u16_lostDataBlockArray, 0xff, sizeof(s_u16_lostDataBlockArray));
            s_u16_lostDataBlockCount  = 0;
            s_u16_upgradeReturnStatus = st_session.par.upgradeDataPack.u16_data[0];
            UpgradeGndState_Set(UPGRADE_ACK_INIT); 
            DLOG_Critical("rec sky UPGRADE_ACK_INIT total packet: %d", s_u16_upgradeReturnStatus);
            break;
        }
        case UPGRADE_ACK_LOSTDATA: 
        {
            //storage lose data block number
            uint16_t loseblockCount = st_session.par.upgradeDataPack.u16_data[0];
            memcpy(s_u16_lostDataBlockArray, &rec_data[sizeof(STRU_upgardeMsg)], loseblockCount*sizeof(uint16_t));
            DLOG_Critical("rec sky UPGRADE_ACK_LOSTDATA %d", loseblockCount);
            s_u16_lostDataBlockCount = loseblockCount;
            for (i = 0; i < loseblockCount; i++)
            {
                DLOG_Critical("lose data block num %d", s_u16_lostDataBlockArray[i]);
            }
            
            UpgradeGndState_Set(UPGRADE_ACK_LOSTDATA); 
            DLOG_Critical("enable re-send data");

            break;
        }
        case UPGRADE_ACK_END: 
        case UPGRADE_ACK_END_CF_SUCCESS: 
        case UPGRADE_ACK_FAIL:
        case UPGRADE_ACK_CHECK:
            UpgradeGndState_Set(st_session.par.upgradeDataPack.u8_opt);
            break;            
        default :
            DLOG_Error("rec sky ack error");
            break;
    }


}


int8_t UPGRADE_GndSendInit(void)
{
    STRU_upgardeMsg st_upgrade;
    uint32_t u32_dataChunk = 0;
    uint32_t u32_upgradeChunk = 0;

    st_upgrade.pid = DT_NUM_SKY_UPGRADE;
    st_upgrade.par.upgradeDataPack.u8_opt = UPGRADE_DATA_INIT;
    u32_dataChunk = s_u32_upgradeTotalDataLen%UPGRADE_DATACHUNK_SIZE;
    u32_upgradeChunk = s_u32_upgradeTotalDataLen/UPGRADE_DATACHUNK_SIZE;
    if (0 != u32_dataChunk)
    {
        st_upgrade.par.upgradeDataPack.u16_data[0] = u32_upgradeChunk + 1;
    }
    else
    {
        st_upgrade.par.upgradeDataPack.u16_data[0] = u32_upgradeChunk;
    }

    st_upgrade.par.upgradeDataPack.u16_data[1] = (APPLICATION_IMAGE_START0 & 0xffff0000) >> 16;
    st_upgrade.par.upgradeDataPack.u16_data[2] = (APPLICATION_IMAGE_START0 & 0xffff);
    UPGRADE_SendMsg(&st_upgrade, NULL, 0);
    return UpgradeGndStatus_Get(UPGRADE_ACK_INIT);
}

int8_t UPGRADE_WirelessGndSendInit(uint32_t u32_dataLen)
{
    STRU_upgardeMsg st_upgrade;

    st_upgrade.pid = DT_NUM_SKY_UPGRADE;
    st_upgrade.par.upgradeDataPack.u8_opt = UPGRADE_DATA_INIT;
    
    st_upgrade.par.upgradeDataPack.u16_data[0] = u32_dataLen;

    st_upgrade.par.upgradeDataPack.u16_data[1] = (APPLICATION_IMAGE_START0 & 0xffff0000) >> 16;
    st_upgrade.par.upgradeDataPack.u16_data[2] = (APPLICATION_IMAGE_START0 & 0xffff);
    UPGRADE_SendMsg(&st_upgrade, NULL, 0);

    DLOG_Warning("st_upgrade total packet = %ld", u32_dataLen);
    return UpgradeGndStatus_Get(UPGRADE_ACK_INIT);
}


static bool update_task_flag = false;

bool get_update_task_flag(void)
{
    return update_task_flag;
}

// void UPGRADE_End(void)
// {

//     update_task_flag = false;
//     UpgradeState_Reset();
//     if (0x01 != UPGRADE_GndAndSkyLockStatus())
//     {
//         DLOG_Error("unlock");
//         return;
//     }

//     HAL_BB_UpgradeMode(0);
//     HAL_Delay(500);
// }



void UPGRADE_Start(void)
{

    update_task_flag = true;

    UpgradeState_Reset();

    if (0x01 != UPGRADE_GndAndSkyLockStatus())
    {
        DLOG_Error("unlock");
        return;
    }

    HAL_BB_UpgradeMode(2);
    HAL_Delay(500);
}

int8_t UPGRADE_UseUsbUpgrade(const uint8_t *fileName, uint8_t u8_flag)
{
    uint32_t i = 0;
    i = HAL_USB_GetMSCPort();
    char path[128];
    

    if (i < HAL_USB_PORT_NUM)
    {
        DLOG_Info("usb port %ld is valid", i);
    }
    else
    {
        DLOG_Error("usb port is not valid");
        return -1;
    }

    
    memcpy(path, fileName, strlen((char *)fileName));
    if (1 == u8_flag)
    {
        return UPGRADE_CheckUpgradeRemoteFile((uint8_t *)path);
    }
    else
    {
        return UPGRADE_CheckUpgradeLocalFile((uint8_t *)path);
    }
}


uint32_t UPGRADE_GndSendEnd(void)
{
    STRU_upgardeMsg st_upgrade;
    // uint32_t u32_dataChunk = 0;
    // uint32_t u32_upgradeChunk = 0;
    
    st_upgrade.pid = DT_NUM_SKY_UPGRADE;
    st_upgrade.par.upgradeDataPack.u8_opt = UPGRADE_DATA_END;
    return UPGRADE_SendMsg(&st_upgrade, NULL, 0);
}


void UPGRADE_SKYInit(void)
{
    HAL_BB_ComRegisterSession(UPGRADE_SESSION,
                              BB_COM_SESSION_PRIORITY_HIGH,
                              BB_COM_SESSION_DATA_NORMAL,
                              UPGRADE_rcvHandleSky);
}

void UPGRADE_GNDInit(void)
{
    HAL_BB_ComRegisterSession(UPGRADE_SESSION,
                              BB_COM_SESSION_PRIORITY_HIGH,
                              BB_COM_SESSION_DATA_NORMAL,
                              UPGRADE_rcvHandleGnd);
}




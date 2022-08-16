/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_bb.c
Description: The external HAL APIs to use the I2C controller.
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/20
History:
        0.0.1    2016/12/20    The initial version of hal_bb.c
*****************************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "sys_event.h"
#include "bb_ctrl.h"
// #include "rf_if.h"
#include "hal_bb.h"
#include "debuglog.h"
#include "bb_customerctx.h"
#include "memory_config.h"
#include "bb_ctrl_internal.h"


static HAL_RET_T HAL_BB_SpiSkyReceiveMsg(uint8_t  *pu8_dataBuf, uint32_t u32_lengthMax,uint32_t *pu32_dataLen);
static HAL_RET_T HAL_BB_SpiGrdSendMsg(uint8_t  *pu8_dataBuf, uint32_t u32_length);


/** 
 * @brief       Set the encoder bitrate Unit:Mbps
 * @param[in]   u8_brcidx                means h264 encoder bitrate index
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note   None.
 */
HAL_RET_T HAL_BB_SetEncoderBitrateProxy(uint8_t u8_ch, uint8_t u8_brcidx)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_ENCODER_CHANGE;
    if (0 == u8_ch)
    {
        st_cmd.u8_configItem   = ENCODER_DYNAMIC_BIT_RATE_SELECT_CH1;
    }
    else
    {
        st_cmd.u8_configItem   = ENCODER_DYNAMIC_BIT_RATE_SELECT_CH2;
    }
    st_cmd.u32_configValue = u8_brcidx;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}


/** 
 * @brief   register one uart session for send or receive message
 * @param   e_sessionId:                    the session id to request
 * @param   sessionEventHandler             the handler for uart session
 * @return  HAL_OK:                         means register session OK
 *          HAL_BB_ERR_SESSION_OCCUPIED:    session ID is already occupied
 */
HAL_RET_T HAL_BB_ComRegisterSession(ENUM_BB_COM_SESSION_ID e_sessionId,
                                   ENUM_BB_COM_SESSION_PRIORITY e_sessionPriority,
                                   ENUM_BB_COM_SESSION_DATA_TYPE e_sessionDataType,
                                   SYS_Event_Handler rcvDataEventHandler)
{
    uint8_t u8_ret;

    if(BB_COM_SESSION_SPI == e_sessionId)
    {
        SYS_EVENT_RegisterHandler(SYS_EVENT_ID_SPI_DATA_TRANS, rcvDataEventHandler);
        return HAL_OK;
    }

    u8_ret = BB_ComRegisterSession(e_sessionId,
                                   e_sessionPriority,
                                   e_sessionDataType);

    if ( u8_ret == 1 )
    {
        uint32_t u32_rcv_event;
        // uint32_t u32_snd_event;

        if ( get_session_eventid(e_sessionId, &u32_rcv_event))
        {
            if ( rcvDataEventHandler )
            {
                SYS_EVENT_RegisterHandler(u32_rcv_event, rcvDataEventHandler);
            }

            return HAL_OK;        
        }
    }

    return HAL_BB_ERR_SESSION_OCCUPIED;
}


/** 
 * @brief   unregister one uart session
 * @param   e_sessionId:                    the session id has already requested.
 * @return  HAL_OK:                         means unrequest session OK 
 *          HAL_BB_ERR_UNREGISTER_SESSION:  means some error happens in unregister session
 */
HAL_RET_T HAL_BB_ComUnRegisterSession(ENUM_BB_COM_SESSION_ID e_sessionId, SYS_Event_Handler rcvDataEventHandler)
{
    uint32_t u32_rcv_event;
    // uint32_t u32_snd_event;
    
    if(BB_COM_SESSION_SPI == e_sessionId)
    {
        SYS_EVENT_UnRegisterHandler(SYS_EVENT_ID_SPI_DATA_TRANS, rcvDataEventHandler);
        return HAL_OK;
    }

    BB_ComUnRegisterSession( e_sessionId );

    if ( get_session_eventid(e_sessionId, &u32_rcv_event))
    {
        if ( rcvDataEventHandler )
        {
            SYS_EVENT_UnRegisterHandler(u32_rcv_event, rcvDataEventHandler);
        }

        return HAL_OK;        
    }

    return HAL_BB_ERR_UNREGISTER_SESSION;
}


/** 
 * @brief   send out messages from uart session
 * @param   e_sessionId:                    the session id has already requested.
 *          pu8_dataBuf:                    buffer pointer to the data to be sent
 *          u32_length:                     data size to be sent
 *
 * @return  HAL_OK:                         means ungister session OK 
 *          HAL_BB_ERR_UNREGISTER_SESSION:  means some error happens in unregister session 
 */
HAL_RET_T HAL_BB_ComSendMsg(ENUM_BB_COM_SESSION_ID e_sessionId, 
                             uint8_t  *pu8_dataBuf, 
                             uint32_t u32_length)
{
    uint8_t u8_ret = 0;

    if(BB_COM_SESSION_SPI == e_sessionId)
    {
        return HAL_BB_SpiGrdSendMsg(pu8_dataBuf, u32_length);
    }

    if (BB_COM_SESSION_0 == e_sessionId)
    {
        // DLOG_Error("session 0 can not be used");


        return HAL_BB_ERR_SESSION_SEND;
    }

    u8_ret = BB_ComSendMsg(e_sessionId, pu8_dataBuf, u32_length);

    if ( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_SESSION_SEND;
    }
}


/** 
 * @brief   receive messages from uart session
 * @param   e_sessionId:                    the session id has already requested.
 *          pu8_dataBuf:                    buffer pointer to the data to be stored
 *          u32_lengthMax:                  maximum data size for store session uart data
 *          pu32_dataLen:                   actual data len has received from session
 * @return  HAL_OK:                         means unrequest session OK 
 *          HAL_BB_ERR_SESSION_RCV:         means some error happens in receving data from session
 */
HAL_RET_T HAL_BB_ComReceiveMsg(ENUM_BB_COM_SESSION_ID e_sessionId, 
                                   uint8_t  *pu8_dataBuf, 
                                   uint32_t u32_lengthMax,
                                   uint32_t *pu32_dataLen)
{
    uint32_t u32_rcvCnt;

    
    if(BB_COM_SESSION_SPI == e_sessionId)
    {
        return HAL_BB_SpiSkyReceiveMsg(pu8_dataBuf, u32_lengthMax, pu32_dataLen);
    }

    u32_rcvCnt = BB_ComReceiveMsg(e_sessionId, pu8_dataBuf, u32_lengthMax);
    *pu32_dataLen = u32_rcvCnt;

    return HAL_OK;
}


HAL_RET_T HAL_BB_GroundConnectToSkyByRcId(uint8_t *pu8_rcId, uint8_t *pu8_vtId)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = RCID_CONNECT_ID;
    st_cmd.u32_configValue  = (pu8_rcId[0] << 24) | (pu8_rcId[1] << 16) | (pu8_rcId[2] << 8) | pu8_rcId[3];
    st_cmd.u32_configValue1 = pu8_rcId[4] | (pu8_vtId[0] << 8) | (pu8_vtId[1] << 16);

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}


/*
 *  set device enter into searching rc id mode
*/
HAL_RET_T HAL_BB_SearchRcId(uint8_t flag_groundAutoSaveRcIdVtId)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = RCID_AUTO_SEARCH;
    st_cmd.u32_configValue  = flag_groundAutoSaveRcIdVtId;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

/*
 *  set device enter into searching rc id mode
*/
HAL_RET_T HAL_BB_StopSearchRcId(void)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = RCID_STOP_SEARCH;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

/*
 *  set rc id, and save to flash
*/
HAL_RET_T HAL_BB_SaveRcId(uint8_t *pu8_rcId, uint8_t *pu8_vtId)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = RCID_SAVE_RCID;
    st_cmd.u32_configValue  = (pu8_rcId[0] << 24) | (pu8_rcId[1] << 16) | (pu8_rcId[2] << 8) | pu8_rcId[3];
    st_cmd.u32_configValue1 = (pu8_rcId[4] << 0)  | (pu8_vtId[0] << 8)  | (pu8_vtId[1] << 16);

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

HAL_RET_T HAL_BB_SetTmpRcVtId(uint8_t *pu8_rcId, uint8_t *pu8_vtId)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = SET_TMP_RC_VT_ID;
    st_cmd.u32_configValue  = (pu8_rcId[0] << 24) | (pu8_rcId[1] << 16) | (pu8_rcId[2] << 8) | pu8_rcId[3];
    st_cmd.u32_configValue1 = (pu8_rcId[4] << 0)  | (pu8_vtId[0] << 8)  | (pu8_vtId[1] << 16);

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}


HAL_RET_T HAL_BB_SetObjRcVtId(uint8_t *pu8_rcId, uint8_t *pu8_vtId)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = GET_OBJ_VT_ID;
    st_cmd.u32_configValue  = (pu8_rcId[0] << 24) | (pu8_rcId[1] << 16) | (pu8_rcId[2] << 8) | pu8_rcId[3];
    st_cmd.u32_configValue1 = (pu8_rcId[4] << 0)  | (pu8_vtId[0] << 8)  | (pu8_vtId[1] << 16);

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}
HAL_RET_T HAL_BB_EnableSearchRcIdByRssi(void)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass   = WIRELESS_AUTO_SEARCH_ID;
    st_cmd.u8_configItem    = ENABLE_SEARCH_ID_BY_RSSI;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

HAL_RET_T HAL_BB_GetRcId(uint8_t *pu8_rcId, uint8_t bufsize)
{
    if (0 == BB_GetRcId(pu8_rcId, bufsize))
    {
        return HAL_OK;
    }

    return HAL_BB_ERR_MEM_NOT_ENOUGH;
}

/** 
 * @brief       get baseband info storage address, details refer to structrue 
 *              STRU_WIRELESS_INFO_DISPLAY, in header file bb_types.h 
 * @param       pu8_bbInfoAddr: the pointer to baseband info storage address
 * @retval      HAL_OK:     means get baseband info sucessfully. 
 * @retval      HAL_BUSY:   means baseband info is updating.
 * @note        None
 */
HAL_RET_T HAL_BB_GetInfo(STRU_WIRELESS_INFO_DISPLAY **ppst_bbInfoAddr)
{
    if (NULL != ppst_bbInfoAddr && NULL != *ppst_bbInfoAddr)
    {
        *ppst_bbInfoAddr = (STRU_WIRELESS_INFO_DISPLAY *)(SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR);     
    }

    if (((*ppst_bbInfoAddr)->head != 0x00) || ((*ppst_bbInfoAddr)->tail != 0xFF))
    {
        return HAL_BUSY;
    }
    else
    {
        return HAL_OK;
    }
}

HAL_RET_T HAL_BB_GetDeviceInfo(STRU_DEVICE_INFO **ppst_bbInfoAddr)
{
    if (NULL != ppst_bbInfoAddr && NULL != *ppst_bbInfoAddr)
    {
        *ppst_bbInfoAddr = (STRU_DEVICE_INFO *)(DEVICE_INFO_SHM_ADDR);
        return HAL_OK;
    }

    return HAL_BUSY;
}

HAL_RET_T HAL_BB_SetPower(uint8_t u8_target2gPower,uint8_t u8_target5gPower)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_RF_POWER_CTRL;
    st_cmd.u8_configItem   = RF_POWER_CTRL_OUTPUT_LEVEL;
    st_cmd.u32_configValue = ((u8_target2gPower << 8) | u8_target5gPower);

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

HAL_RET_T HAL_BB_SetPowerWorkMode(ENUM_RF_POWER_WORK_MODE e_powerWorkMode)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_RF_POWER_CTRL;
    st_cmd.u8_configItem   = RF_POWER_CTRL_STANDARD; 
    st_cmd.u32_configValue = e_powerWorkMode;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

static uint8_t pwrCtrlLevel = 0;

HAL_RET_T HAL_PwrCtrlSet(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    pwrCtrlLevel = value;
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = PWR_CTRL_SET;
    st_cmd.u32_configValue = value;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

HAL_RET_T HAL_PA_modeCtrlSet(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = WIRELESS_RF_PA_MODE;
    st_cmd.u32_configValue = value;
    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

uint8_t HAL_GetPwrCtrlLevel(void)
{
    return pwrCtrlLevel;
}

HAL_RET_T HAL_BB_SpiDataTransInit(uint8_t u8_maxLength)
{
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);

    memset((void*)pst_spiDSave, 0x00, sizeof(STRU_SPI_DATA_SAVE_FORMAT));
    pst_spiDSave->max_len = ((u8_maxLength <= SPI_DATA_TRANS_MAX_LEN) ? u8_maxLength : SPI_DATA_TRANS_MAX_LEN);
    pst_spiDSave->real_len = pst_spiDSave->max_len;
    pst_spiDSave->init = 1;

    return HAL_OK;
}

static HAL_RET_T HAL_BB_SpiSkyReceiveMsg(uint8_t  *pu8_dataBuf, uint32_t u32_lengthMax, uint32_t *pu32_dataLen)
{
    uint8_t i = 0;
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);

    if((BB_SpiChkDataTransChValid()) && \
        (pst_spiDSave->real_len <= pst_spiDSave->max_len) && \
        (pst_spiDSave->real_len > 0) && \
        (0 == pst_spiDSave->busy) && \
        (1 == pst_spiDSave->valid) && \
        (pu8_dataBuf != NULL))
    {
        pst_spiDSave->busy = 1;
        u32_lengthMax = ((uint8_t)u32_lengthMax <= pst_spiDSave->real_len) ? (uint8_t)u32_lengthMax : pst_spiDSave->real_len;

        for(i = 0; i < (uint8_t)u32_lengthMax; i++)
        {
            pu8_dataBuf[i] = pst_spiDSave->data[i];
        }

        if(pu32_dataLen != NULL)
        {
            *pu32_dataLen = (uint32_t)i;
        }
        pst_spiDSave->valid = 0;
        pst_spiDSave->real_len = 0;
        pst_spiDSave->busy = 0;

        return HAL_OK;
    }
    else
    {
        if(pu32_dataLen != NULL)
        {
            *pu32_dataLen = 0;
        }
    }
    
    return HAL_BB_ERR_NO_DATA;
}

static HAL_RET_T HAL_BB_SpiGrdSendMsg(uint8_t  *pu8_dataBuf, uint32_t u32_length)
{
    uint8_t len;
    STRU_SPI_DATA_SAVE_FORMAT *pst_spiDSave = (STRU_SPI_DATA_SAVE_FORMAT *)(SRAM_SPI_DATA_TRANS_ST_ADDR);

    if(0 == pst_spiDSave->init)
    {
        return HAL_NOT_INITED;
    }

    
    if(1 == pst_spiDSave->busy)
    {
        uint16_t delay = 200;
        while(delay--);
    }

    if(1 == pst_spiDSave->busy)
    {
        return HAL_BUSY;
    }

    pst_spiDSave->busy = 1;
    len = ((uint8_t)u32_length <= (pst_spiDSave->max_len)) ? (uint8_t)u32_length : pst_spiDSave->max_len;
    memcpy(pst_spiDSave->data, pu8_dataBuf, len);
    pst_spiDSave->real_len = len;
    pst_spiDSave->valid = 1;
    pst_spiDSave->busy = 0;

    return HAL_OK;
}


HAL_RET_T HAL_TakePicture(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    pwrCtrlLevel = value;
    st_cmd.u8_configClass  = WIRELESS_ENCODER_CHANGE;
    st_cmd.u8_configItem   = ENCODER_TAKE_PICTURE;
    st_cmd.u32_configValue = value;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}

HAL_RET_T HAL_PictureQualitySet(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    pwrCtrlLevel = value;
    st_cmd.u8_configClass  = WIRELESS_ENCODER_CHANGE;
    st_cmd.u8_configItem   = ENCODER_PICTURE_QUALITY_SET;
    st_cmd.u32_configValue = value;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}
HAL_RET_T HAL_BB_SubBandSetCH(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = SUB_BAND_SET_CH;
    st_cmd.u32_configValue = value;

    u8_ret = SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
    if( u8_ret )
    {
        return HAL_OK;
    }
    else
    {
        return HAL_BB_ERR_EVENT_NOTIFY;
    }
}
/** 
 * @brief   register lna open or bypass operation function
 * @param   null
 * @return  void
 * @notes   only called by cpu2
 */
void HAL_BB_RegisterLnaFuntion(pfun open_lna_function, pfun bypass_lna_function)
{
    BB_Register_lna(open_lna_function,bypass_lna_function);
}
/** 
 * @brief   enable or disable rc random skip freq functions
 * @param   null
 * @return  void
 * @notes   default rc random skip freq is off, call this functions to enable, only called by cpu2
 */
void HAL_BB_Enable_RcRandomSkipFreq(void)
{
    BB_Enable_RcRandomSkipPatten();
}
/** 
 * @brief   config uplink qam mode
 * @param   uint8_t, 0->bspk1/2 (default) 1->qpsk2/3 2->qpsk1/2 3->bpsk2/3  
 * @return  void
 * @notes   
 */
void HAL_BB_ConfigUplinkQamMode(uint8_t val)
{
    BB_config_uplink_qam_mode(val);
}
/** 
 * @brief   register FEM open or close operation function
 * @param   null
 * @return  void
 * @notes   only called by cpu2
 */
void HAL_BB_RegisterFemFuntion(pfun_fem fem_cb_open,pfun_fem fem_cb_close)
{
    BB_Register_fem_cb(fem_cb_open,fem_cb_close);
}

/** 
 * @brief   register freq-band 2.4G and 5.8G switch operation function
 * @param   null
 * @return  void
 * @notes   only called by cpu2
 */
void HAL_BB_RegisterFreq2g5gSwitchFuntion(pfun freq2g_cb_func, pfun freq5g_cb_func)
{
    BB_Register_freq2g5g_switch(freq2g_cb_func,freq5g_cb_func);
}


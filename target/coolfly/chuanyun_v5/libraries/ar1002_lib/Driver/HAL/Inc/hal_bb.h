/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: hal_i2c.h
Description: The external HAL APIs to use the I2C controller.
Author: Artosy Software Team
Version: 0.0.1
Date: 2016/12/20
History: 
        0.0.1    2016/12/20    The initial version of hal_i2c.h
*****************************************************************************/


#ifndef __HAL_BB___
#define __HAL_BB___

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "bb_types.h"
#include "bb_uart_com.h"
#include "bb_customerctx.h"
#include "hal_ret_type.h"
#include "bb_ctrl.h"


/**
 * @brief   init baseband to ground mode
 * @param   NONE
 * @return  HAL_OK:                         means init baseband 
 *          HAL_BB_ERR_INIT:                means some error happens in init session 
 */
HAL_RET_T HAL_BB_InitGround( STRU_CUSTOMER_CFG *stru_customerCfg );


/** 
 * @brief   init baseband to sky mode
 * @param   NONE
 * @return  HAL_OK:                         means init baseband 
 *          HAL_BB_ERR_INIT:                means some error happens in init session 
 */
HAL_RET_T HAL_BB_InitSky( STRU_CUSTOMER_CFG *stru_customerCfg );



/** 
 * @brief       Set the encoder bitrate Unit:Mbps
 * @param[in]   u8_ch: channel, 0:ch1 1:ch2
 * @param[in]   u8_brcidx:               select the encoder bitrate index
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetEncoderBitrateProxy(uint8_t u8_ch, uint8_t u8_brcidx);


/** 
 * @brief   register one uart session for send or receive message
 * @param   e_sessionId:                    the session id to request
 * @return  HAL_OK:                         means request session OK
 *          HAL_BB_ERR_SESSION_OCCUPIED:    session ID is already occupied
 * @note    None
 */
HAL_RET_T HAL_BB_ComRegisterSession(ENUM_BB_COM_SESSION_ID e_sessionId,
                                   ENUM_BB_COM_SESSION_PRIORITY e_sessionPriority,
                                   ENUM_BB_COM_SESSION_DATA_TYPE e_sessionDataType,
                                   SYS_Event_Handler rcvDataEventHandler);


/** 
 * @brief   unregister one uart session
 * @param   e_sessionId:                    the session id has already requested.
 * @return  HAL_OK:                         means unrequest session OK 
 *          HAL_BB_ERR_UNREGISTER_SESSION:  means some error happens in unregister session
 * @note    None
 */
HAL_RET_T HAL_BB_ComUnRegisterSession(ENUM_BB_COM_SESSION_ID e_sessionId, SYS_Event_Handler sessionEventHandler);



/** 
 * @brief   send out messages from uart session
 * @param   e_sessionId:                    the session id has already requested.
 *          pu8_dataBuf:                    buffer pointer to the data to be sent
 *          u32_length:                     data size to be sent
 *
 * @return  HAL_OK:                         means unrequest session OK 
 *          HAL_BB_ERR_UNREGISTER_SESSION:  means some error happens in unregister session 
 */
HAL_RET_T HAL_BB_ComSendMsg(ENUM_BB_COM_SESSION_ID e_sessionId, 
                              uint8_t  *pu8_dataBuf, 
                              uint32_t u32_length);


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
                                uint32_t *pu32_dataLen);


/** 
 * @brief       force baseband calculation distance zero calibration.
 * @param       none.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_CalcDistZeroCalibration(void);

/** 
 * @brief       set baseband calculation distance zero point.
 * @param       none.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetCalcDistZeroPoint(uint32_t value);


/** 
 * @brief       request ground to disconnect from the sky by rcid in searching mode
 * @param       pu8_rcid:                sky rc id request to disconnect
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_GroundDisConnectSkyByRcId(uint8_t * pu8_rcid);


/** 
 * @brief       request ground to connect with the sky by rcid
 * @param       pu8_rcid:                sky rc id request to connect
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_GroundConnectToSkyByRcId(uint8_t *pu8_rcId, uint8_t *pu8_vtId);


/** 
 * @brief       request ground to search rc id
 * @param       flag_followGroundInSearching:  not usefull for ground. For sky, it means sky will follow ground in rc id searching mode until ground request disconnect
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SearchRcId(uint8_t flag_groundAutoSaveRcIdVtId);


/** 
 * @brief       request to save and use the rc id
 * @param       pu8_rcId: rc id setting, size is Five
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SaveRcId(uint8_t *pu8_rcId, uint8_t *pu8_vtId);

HAL_RET_T HAL_BB_SetTmpRcVtId(uint8_t *pu8_rcId, uint8_t *pu8_vtId);

/** 
 * @brief       get the current rc id
 * @param       pu8_rcId: the pointer to save the rc id
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_GetRcId(uint8_t *pu8_rcId, uint8_t bufsize);


/** 
 * @brief       get baseband info storage address, details refer to structrue 
 *              STRU_WIRELESS_INFO_DISPLAY, in header file bb_types.h 
 * @param       pst_bbInfoAddr: the pointer to baseband info storage address
 * @retval      HAL_OK:     means get baseband info sucessfully. 
 * @retval      HAL_BUSY:   means baseband info is updating.
 * @note        None
 */
HAL_RET_T HAL_BB_GetInfo(STRU_WIRELESS_INFO_DISPLAY **pst_bbInfoAddr);


/**
 * @brief       get baseband device info storage address, details refer to structrue
 *              STRU_DEVICE_INFO, in header file bb_types.h
 * @param       pst_bbInfoAddr: the pointer to device info storage address
 * @retval      HAL_OK:     means get device info sucessfully.
 * @retval      HAL_BUSY:   means get device info fail.
 * @note        None
 */
HAL_RET_T HAL_BB_GetDeviceInfo(STRU_DEVICE_INFO **ppst_bbInfoAddr);


/** 
 ** @brief       HAL_BB_UpgradeMode
 ** @param       1: enter into upgrade    0: exit upgrade
 ** @retval      HAL_OK,                  means command is sent sucessfully. 
 ** @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 **/
HAL_RET_T HAL_BB_UpgradeMode(uint8_t u8_flag);

/** 
 * @brief       force baseband reset.
 * @param       none.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SoftResetProxy(void);

/** 
 * @brief       
 * @param       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetPureVtMode(uint8_t value);

/** 
 ** @brief       HAL_BB_SetPower
 ** @param       2.4G power and 5.8G power
 ** @retval      HAL_OK,                  means command is sent sucessfully. 
 ** @retval      
 **/
HAL_RET_T HAL_BB_SetPower(uint8_t u8_target2gPower,uint8_t u8_target5gPower);

/** 
 ** @brief       HAL_BB_SetPowerWorkMode
 ** @param     FCC,CE,SRRC,OTHER, please select one
 ** @retval      HAL_OK,                  means command is sent sucessfully. 
 ** @retval      
 **/
HAL_RET_T HAL_BB_SetPowerWorkMode(ENUM_RF_POWER_WORK_MODE e_powerWorkMode);


HAL_RET_T HAL_PwrCtrlSet(uint8_t value);

HAL_RET_T HAL_PA_modeCtrlSet(uint8_t value);


uint8_t HAL_GetPwrCtrlLevel(void);

HAL_RET_T HAL_BB_StopSearchRcId(void);

HAL_RET_T HAL_BB_CmdVtSweep(uint8_t value);

HAL_RET_T HAL_BB_CmdSelectFilter(uint8_t value);

HAL_RET_T HAL_BB_SetSweepMode(uint8_t mode);

HAL_RET_T HAL_BB_SpiDataTransInit(uint8_t u8_maxLength);

HAL_RET_T HAL_TakePicture(uint8_t value);

HAL_RET_T HAL_PictureQualitySet(uint8_t value);
HAL_RET_T HAL_BB_SubBandSetCH(uint8_t value);

HAL_RET_T HAL_BB_SetObjRcVtId(uint8_t *pu8_rcId, uint8_t *pu8_vtId);
HAL_RET_T HAL_BB_EnableSearchRcIdByRssi(void);

/** 
 ** @brief     HAL_BB_SetUnlockCnt
 ** @param     Set Lock status to unlock status continous cycle count.
 ** @note      Call this function on CPU2, not work on CPU0,1      
 **/
void HAL_BB_SetUnlockCnt(uint8_t u8_lock2unlockCnt);


void HAL_BB_RegisterLnaFuntion(pfun open_lna_function, pfun bypass_lna_function);

/** 
 * @brief   enable or disable rc random skip freq functions
 * @param   null
 * @return  void
 * @notes   default rc random skip freq is off, call this functions to enable, only called by cpu2
 */
void HAL_BB_Enable_RcRandomSkipFreq(void);

/** 
 * @brief   register FEM open or close operation function
 * @param   null
 * @return  void
 * @notes   only called by cpu2
 */
void HAL_BB_RegisterFemFuntion(pfun_fem fem_cb_open,pfun_fem fem_cb_close);


/** 
 * @brief   config uplink qam mode
 * @param   uint8_t, 0->bspk1/2 (default) 1->qpsk2/3 2->qpsk1/2 3->bpsk2/3  
 * @return  void
 * @notes   
 */
void HAL_BB_ConfigUplinkQamMode(uint8_t val);

/** 
 * @brief   register freq-band 2.4G and 5.8G switch operation function
 * @param   null
 * @return  void
 * @notes   only called by cpu2
 */
void HAL_BB_RegisterFreq2g5gSwitchFuntion(pfun freq2g_cb_func, pfun freq5g_cb_func);

/** 
 * @brief       HAL_BB_SetUplinkQamMode
 * @param       0:bpsk 1/2(default)    2: qpsk 1/2
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        The function can only be called by cpu0,1         
 */
HAL_RET_T HAL_BB_SetUplinkQamMode( uint8_t u8_qam_v );

#ifdef __cplusplus
}
#endif

#endif

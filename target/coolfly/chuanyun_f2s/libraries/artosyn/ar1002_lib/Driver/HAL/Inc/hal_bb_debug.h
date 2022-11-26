/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: 
Description: 
Author: Artosy Software Team
Version: 
Date: 
History: 
        
*****************************************************************************/


#ifndef __HAL_BB_DEBUG___
#define __HAL_BB_DEBUG___

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "bb_types.h"
#include "bb_customerctx.h"
#include "hal_ret_type.h"


/** 
 * @brief       Set the encoder bitrate control mode
 * @param[in]   e_mode: auto or manual selection.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        The function can only be called by cpu0,1  
 */
HAL_RET_T HAL_BB_SetEncoderBrcModeProxy(ENUM_RUN_MODE e_mode);

/** 
 * @brief       set channel Bandwidth 10M/20M
 * @param[in]   e_bandwidth              channel bandwidth setting 10M/20M
 * @retval      HAL_OK                   means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetFreqBandwidthSelectionProxy(ENUM_CH_BW e_bandwidth);


/** 
 * @brief       Set frequency band (2G/5G) selection mode (ATUO / Manual)
 * @param[in]   e_mode:                  selection mode (ATUO / Manual)
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None 
 */
HAL_RET_T HAL_BB_SetFreqBandSelectionModeProxy(ENUM_RUN_MODE e_mode);


/**
 * @brief       Set frequency band (2G/5G)
 * @param[in]   e_band:                  RF band selection
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None  
 */
HAL_RET_T HAL_BB_SetFreqBandProxy(ENUM_RF_BAND e_band);


/** 
 * @brief       Set It(image transmit) channel selection RUN mode(AUTO/Manual)
 * @param[in]   e_mode:                  the modulation QAM mode for image transmit.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None 
 */
HAL_RET_T HAL_BB_SetItChannelSelectionModeProxy(ENUM_RUN_MODE e_mode);


/** 
 * @brief       API for set IT(image transmit) channel Number
 * @param[in]   u8_channelNum:           the current channel number int current Frequency band(2G/5G)
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetItChannelProxy(uint8_t u8_channelNum);


/** 
 * @brief       Set MCS(modulation, coderate scheme) mode, the function can only be called by cpu0,1
 * @param[in]   e_mode:                  auto or manual selection.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None  
 */
HAL_RET_T HAL_BB_SetMcsModeProxy(ENUM_RUN_MODE e_mode);


/** 
 * @brief       Set the image transmit QAM mode
 * @param[in]   e_qam:                   modulation qam mode
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None  
 */
HAL_RET_T HAL_BB_SetItQamProxy(ENUM_BB_QAM e_qam);


/** 
 * @brief       Set the image transmit LDPC coderate
 * @param[in]   e_ldpc:                  ldpc coderate 
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None  
 */
HAL_RET_T HAL_BB_SetItLdpcProxy(ENUM_BB_LDPC e_ldpc);

/** 
 * @brief       Set the rc transmit LDPC coderate
 * @param[in]   e_ldpc:                  ldpc coderate 
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None  
 */
HAL_RET_T HAL_BB_SetRcLdpcProxy(ENUM_BB_LDPC e_ldpc);

/** 
 * @brief   Set board enter or out debug mode
 * @param   mode	    0:  set Baseband to enter debug mode, 
                        1:  set Baseband to out debug mode.
 * @note    None
 */
HAL_RET_T HAL_BB_SetBoardDebugModeProxy(uint8_t mode);

/** 
 * @brief   set Baseband to It only mode
 * @param   mode                            1: enter It only mode
 * @retval  HAL_OK,                         means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY         means error happens in sending the command to cpu2                        
 * @note    The function can only be called by cpu0,1, and only call for debug.
 */
HAL_RET_T HAL_BB_SetItOnlyFreqProxy(uint8_t mode);

/** 
 * @brief       Set It(image transmit) QAM
 * @param[in]   e_qam:                  the modulation QAM mode for image transmit.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetFreqBandQamSelectionProxy(ENUM_BB_QAM e_qam);

/** 
 * @brief       Set rc QAM
 * @param[in]   e_qam:                  the modulation QAM mode for image transmit.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetRcQamSelectionProxy(ENUM_BB_QAM e_qam);

/** 
 * @brief       switch encoder channel on/off
 * @param[in]   u8_ch:   channel,0:ch1,1:ch2
 * @param[in]   u8_data: 0:off, 1:on 
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SwitchOnOffChProxy(uint8_t u8_ch, uint8_t u8_data);


/** 
 * @brief   set Baseband Rc frequency setting registers
 * @param   u32_freqSetting:                the registers 
 * @retval  HAL_OK,                         means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY         means error happens in sending the command to cpu2                        
 * @note    None
 */
HAL_RET_T HAL_BB_SetRcFreqProxy(uint32_t u32_freqSetting);



/** 
 * @brief   set Baseband It frequency setting registers
 * @param   u32_freqSetting:                the registers setting
 * @retval  HAL_OK,                         means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY         means error happens in sending the command to cpu2                        
 * @note    None
 */
HAL_RET_T HAL_BB_SetItFreqProxy(uint32_t u32_freqSetting);



/** 
 * @brief       Set RC channel selection RUN mode(AUTO/Manual)
 * @param[in]   e_mode:                  the modulation QAM mode for rc.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetRcChannelSelectionModeProxy(ENUM_RUN_MODE e_mode);

/** 
 * @brief       
 * @param       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_RwBbRfReg(uint8_t *value);

/** 
 * @brief       
 * @param       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetGrdSlaveMode(uint8_t *pu8_rcId, uint8_t *pu8_vtId);

/** 
 * @brief sky enter find beside device mode       
 * @param 0 : stop find device, 1 : start find device       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetSkyFindBesideDevMode(uint8_t start);
/** 
 * @brief       set HW LNA status
 * @param[in]   LNA status value
 * @retval      HAL_OK                   means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 */
HAL_RET_T HAL_BB_SetLnaStatusProxy(uint8_t lna_value);
/** 
 * @brief enable or disable NON-LBT(CE and SRRC need enable, FCC need disable, default FCC)       
 * @param 0 : disable, 1 enable       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetNonLbt(uint8_t value);
/** 
 * @brief enable or disable need low bandedge power       
 * @param  enable, 0 : disable, 1 enable 
           value, need lower value dbm  bandedge freq then center freq; (only enable == 1 is valid)
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetBandedge(uint8_t enable, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif

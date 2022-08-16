/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: 
Description: 
Author: Artosy Software Team
Version: 
Date: 
History:
        
*****************************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sys_event.h"
#include "bb_spi.h"
#include "bb_ctrl.h"
#include "bb_sky_ctrl.h"
#include "hal_bb_debug.h"
#include "debuglog.h"
#include "bb_customerctx.h"


/** 
 * @brief       Set the encoder bitrate control mode
 * @param[in]   e_mode: auto or manual selection.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        The function can only be called by cpu0,1  
 */
HAL_RET_T HAL_BB_SetEncoderBrcModeProxy(ENUM_RUN_MODE e_mode)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_ENCODER_CHANGE;
    st_cmd.u8_configItem   = ENCODER_DYNAMIC_BIT_RATE_MODE;
    st_cmd.u32_configValue = (uint32_t)e_mode;

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
 * @brief       set channel Bandwidth 10M/20M
 * @param[in]   e_bandwidth              channel bandwidth setting 10M/20M
 * @retval      HAL_OK                   means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 */
HAL_RET_T HAL_BB_SetFreqBandwidthSelectionProxy(ENUM_CH_BW e_bandwidth)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = FREQ_BAND_WIDTH_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_bandwidth;

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
 * @brief       Set frequency band (2G/5G) selection mode (ATUO / Manual)
 * @param[in]   e_mode:                  selection mode (ATUO / Manual)
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 */
HAL_RET_T HAL_BB_SetFreqBandSelectionModeProxy(ENUM_RUN_MODE e_mode)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = FREQ_BAND_MODE;
    st_cmd.u32_configValue = (uint32_t)e_mode;

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
 * @brief       Set the image transmit QAM mode
 * @param[in]   e_qam:                   modulation qam mode
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetItQamProxy(ENUM_BB_QAM e_qam)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_MCS_CHANGE;
    st_cmd.u8_configItem   = MCS_MODULATION_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_qam;

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
 * @brief       Set frequency band (2G/5G)
 * @param[in]   e_band:                  RF band selection
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetFreqBandProxy(ENUM_RF_BAND e_band)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = FREQ_BAND_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_band;

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
 * @brief       Set It(image transmit) channel selection RUN mode(AUTO/Manual)
 * @param[in]   e_mode:                  the modulation QAM mode for image transmit.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetItChannelSelectionModeProxy(ENUM_RUN_MODE e_mode)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = FREQ_CHANNEL_MODE;
    st_cmd.u32_configValue = (uint32_t)e_mode;

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
 * @brief       API for set IT(image transmit) channel Number
 * @param[in]   u8_channelNum:           the current channel number int current Frequency band(2G/5G)
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetItChannelProxy(uint8_t u8_channelNum)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = FREQ_CHANNEL_SELECT;
    st_cmd.u32_configValue = u8_channelNum;

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
 * @brief   set Baseband Rc frequency setting registers
 * @param   u32_freqSetting:                the registers 
 * @retval  HAL_OK,                         means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY         means error happens in sending the command to cpu2                        
 * @note    None
 */
HAL_RET_T HAL_BB_SetRcFreqProxy(uint32_t u32_freqSetting)
{
    STRU_WIRELESS_CONFIG_CHANGE cmd;

    cmd.u8_configClass   = WIRELESS_FREQ_CHANGE;
    cmd.u8_configItem    = RC_CHANNEL_FREQ;
    cmd.u32_configValue  = u32_freqSetting;

    return SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&cmd);
}


/** 
 * @brief   set Baseband It frequency setting registers
 * @param   u32_freqSetting:                the registers setting
 * @retval  HAL_OK,                         means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY         means error happens in sending the command to cpu2                        
 * @note    None
 */
HAL_RET_T HAL_BB_SetItFreqProxy(uint32_t u32_freqSetting)
{
    STRU_WIRELESS_CONFIG_CHANGE cmd;

    cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    cmd.u8_configItem   = IT_CHANNEL_FREQ;
    cmd.u32_configValue  = u32_freqSetting;

    return SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&cmd);
}


/** 
 * @brief       Set MCS(modulation, coderate scheme) mode, the function can only be called by cpu0,1
 * @param[in]   e_mode:                  auto or manual selection.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetMcsModeProxy(ENUM_RUN_MODE e_mode)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_MCS_CHANGE;
    st_cmd.u8_configItem   = MCS_MODE_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_mode;

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
 * @brief       Set RC channel selection RUN mode(AUTO/Manual)
 * @param[in]   e_mode:                  the modulation QAM mode for rc.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetRcChannelSelectionModeProxy(ENUM_RUN_MODE e_mode)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = RC_CHANNEL_MODE;
    st_cmd.u32_configValue = (uint32_t)e_mode;

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
 * @brief       Set the image transmit LDPC coderate
 * @param[in]   e_ldpc:                  ldpc coderate 
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetItLdpcProxy(ENUM_BB_LDPC e_ldpc)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_MCS_CHANGE;
    st_cmd.u8_configItem   = MCS_IT_CODE_RATE_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_ldpc;

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
 * @brief       Set the rc transmit LDPC coderate
 * @param[in]   e_ldpc:                  ldpc coderate 
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetRcLdpcProxy(ENUM_BB_LDPC e_ldpc)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_MCS_CHANGE;
    st_cmd.u8_configItem   = MCS_RC_CODE_RATE_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_ldpc;

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
 * @brief   Set board enter or out debug mode
 * @param   u8_mode	    0:  set Baseband to enter debug mode, 
                        1:  set Baseband to out debug mode.
 * @retval  HAL_OK,                  means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2                        
 * @note    The function can only be called by cpu0,1, and only call for debug.
 */
HAL_RET_T HAL_BB_SetBoardDebugModeProxy(uint8_t u8_mode)
{
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;

    st_cmd.u8_configClass  = WIRELESS_DEBUG_CHANGE;
    st_cmd.u8_configItem   = 0;
    st_cmd.u32_configValue = (u8_mode & 1);

    return SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&st_cmd);
}

/** 
 * @brief   set Baseband to It only mode
 * @param   mode                            1: enter It only mode  0: exit from the debug mode
 * @retval  HAL_OK,                         means command is sent sucessfully. 
 * @retval  HAL_BB_ERR_EVENT_NOTIFY         means error happens in sending the command to cpu2                        
 * @note    The function can only be called by cpu0,1, and only call for debug.
 */
HAL_RET_T HAL_BB_SetItOnlyFreqProxy(uint8_t mode)
{
    STRU_WIRELESS_CONFIG_CHANGE cmd;

    cmd.u8_configClass  = WIRELESS_MISC;
    cmd.u8_configItem   = MICS_IT_ONLY_MODE;
    cmd.u32_configValue = mode;

    return SYS_EVENT_NotifyInterCore(SYS_EVENT_ID_USER_CFG_CHANGE, (void *)&cmd);
}

/** 
 * @brief       Set It(image transmit) QAM
 * @param[in]   e_qam:                  the modulation QAM mode for image transmit.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetFreqBandQamSelectionProxy(ENUM_BB_QAM e_qam)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_MCS_CHANGE;
    st_cmd.u8_configItem   = MCS_IT_QAM_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_qam;

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
 * @brief       Set rc QAM
 * @param[in]   e_qam:                  the modulation QAM mode for image transmit.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SetRcQamSelectionProxy(ENUM_BB_QAM e_qam)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_MCS_CHANGE;
    st_cmd.u8_configItem   = MCS_RC_QAM_SELECT;
    st_cmd.u32_configValue = (uint32_t)e_qam;

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
 * @brief       switch encoder channel on/off
 * @param[in]   u8_ch:   channel,0:ch1,1:ch2
 * @param[in]   u8_data: 0:off, 1:on 
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        None
 */
HAL_RET_T HAL_BB_SwitchOnOffChProxy(uint8_t u8_ch, uint8_t u8_data)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    if (0 == u8_ch)
    {
        st_cmd.u8_configItem   = SWITCH_ON_OFF_CH1;
    }
    else
    {
        st_cmd.u8_configItem   = SWITCH_ON_OFF_CH2;
    }

    st_cmd.u32_configValue = u8_data;

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
 * @brief       force baseband reset.
 * @param       none.
 * @retval      HAL_OK,                  means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 * @note        The function can only be called by cpu0,1         
 */
HAL_RET_T HAL_BB_SoftResetProxy(void)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = BB_SOFT_RESET;
    st_cmd.u32_configValue = 0;

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
 * @brief       
 * @param       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetPureVtMode(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = SET_PURE_VT_MODE;
    st_cmd.u32_configValue = (uint32_t)value;

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
 * @brief       
 * @param       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_RwBbRfReg(uint8_t *value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = RW_BB_RF_REG;
    memcpy((uint8_t *)(&st_cmd.u32_configValue), value, sizeof(STRU_BB_REG_CMD));

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
 * @brief ground go to slave mode       
 * @param object vt id device       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetGrdSlaveMode(uint8_t *pu8_rcId, uint8_t *pu8_vtId)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = SET_GRD_SLAVE_MODE;
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


/** 
 * @brief sky enter find beside device mode       
 * @param 0 : stop find device, 1 : start find device       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetSkyFindBesideDevMode(uint8_t start)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = SET_FIND_BESIDE_DEV;
    st_cmd.u32_configValue = (uint32_t)start;

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
 * @brief       set HW LNA status
 * @param[in]   LNA status value
 * @retval      HAL_OK                   means command is sent sucessfully. 
 * @retval      HAL_BB_ERR_EVENT_NOTIFY  means error happens in sending the command to cpu2
 */
HAL_RET_T HAL_BB_SetLnaStatusProxy(uint8_t lna_value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_FREQ_CHANGE;
    st_cmd.u8_configItem   = SET_LNA_STATUS;
    st_cmd.u32_configValue = (uint32_t)lna_value;

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
 * @brief enable or disable NON-LBT(CE and SRRC need enable, FCC need disable, default FCC)       
 * @param 0 : disable, 1 enable       
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetNonLbt(uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = SET_NON_LBT;
    st_cmd.u32_configValue  = value;

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
 * @brief enable or disable need low bandedge power       
 * @param  enable, 0 : disable, 1 enable 
           value, need lower value dbm  bandedge freq then center freq; (only enable == 1 is valid)
 * @retval      
 * @retval      
 * @note        
 */
HAL_RET_T HAL_BB_SetBandedge(uint8_t enable, uint8_t value)
{
    uint8_t u8_ret;
    STRU_WIRELESS_CONFIG_CHANGE st_cmd;
    
    st_cmd.u8_configClass  = WIRELESS_OTHER;
    st_cmd.u8_configItem   = SET_BANDEDGE;
    st_cmd.u32_configValue  = enable;
    st_cmd.u32_configValue1  = value;

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


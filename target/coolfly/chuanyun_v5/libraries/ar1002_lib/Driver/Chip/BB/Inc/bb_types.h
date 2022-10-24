#ifndef __BB_TYPES_H_
#define __BB_TYPES_H_


typedef enum
{
    AUTO,
    MANUAL
}ENUM_RUN_MODE;

typedef enum
{
    FULL_BAND_HOPING = 0,
	RANDOM_HOPING=1,	
    SELECTION_BAND_HOPING   = 2,
} ENUM_RC_HOPE_PATTEN_MODE;


typedef enum
{
    BB_SKY_MODE     = 0x00,
    BB_GRD_MODE     = 0x01,
    BB_MODE_UNKNOWN = 0xFF
} ENUM_BB_MODE;


typedef enum
{
    IT_ONLY_MODE    = 0x00,     //iamge transmit only
    IT_RC_MODE      = 0x01,     //iamge transmit and RC mode
    IT_MAX_TRX_CTRL = 0xff
} ENUM_TRX_CTRL;


typedef enum _ENUM_RF_BAND
{
    RF_2G           = 0x01,     //support only 2G 
    RF_5G           = 0x02,     //support only 5G 
    RF_2G_5G        = (RF_2G | RF_5G),
    RF_600M         = 0x04
}ENUM_RF_BAND;


typedef enum _ENUM_BB_QAM
{
    MOD_BPSK    = 0x00,
    MOD_4QAM    = 0x01,
    MOD_16QAM   = 0x02,
    MOD_64QAM   = 0x03,
    MOD_MAX     = 0xff,
}ENUM_BB_QAM;


typedef enum ENUM_BB_LDPC
{
    LDPC_1_2    = 0x00,
    LDPC_2_3    = 0x01,
    LDPC_3_4    = 0x02,
    LDPC_5_6    = 0x03,
}ENUM_BB_LDPC;


typedef enum _ENUM_CH_BW
{
    BW_10M      = 0x02,
    BW_20M      = 0x00,
}ENUM_CH_BW;



typedef struct
{
    ENUM_BB_QAM                     e_rcQam;
    ENUM_BB_LDPC                    e_rcLdpc;
} STRU_RC_MODE;


typedef enum
{
    WIRELESS_FREQ_CHANGE,
    WIRELESS_MCS_CHANGE,
    WIRELESS_ENCODER_CHANGE,
    WIRELESS_DEBUG_CHANGE,
    WIRELESS_MISC,
    WIRELESS_AUTO_SEARCH_ID,
    WIRELESS_RF_POWER_CTRL,
    WIRELESS_RF_PA_CTRL,
    WIRELESS_RF_REMOTE_UPGRADE,
    WIRELESS_OTHER,
} ENUM_WIRELESS_CONFIG_CHANGE;


typedef enum
{
    FREQ_BAND_WIDTH_SELECT,
    FREQ_BAND_SELECT,
    FREQ_BAND_MODE,
    FREQ_CHANNEL_MODE,
    FREQ_CHANNEL_SELECT,
    RC_CHANNEL_MODE,
    RC_CHANNEL_SELECT,
    RC_CHANNEL_FREQ,
    IT_CHANNEL_FREQ,
    MICS_IT_ONLY_MODE,
    GET_DEV_INFO,
    SWITCH_ON_OFF_CH1,
    SWITCH_ON_OFF_CH2,
    BB_SOFT_RESET,
    CALC_DIST_ZERO_CALI,
    SET_CALC_DIST_ZERO_POINT,
    SET_RC_FRQ_MASK,
    SET_PURE_VT_MODE,
    RW_BB_RF_REG,
    AGC_GEAR_CHG,
    IT_CHANNEL_SELECT,
    PWR_CTRL_SET,
    WIRELESS_RF_PA_MODE,
    WIRELESS_RF_PA_ON_CTRL,
    SET_RC_PATTEN,
    RF_POWER_CTRL_STANDARD,
    RF_POWER_CTRL_OUTPUT_LEVEL,
    CMD_VT_SWEEP,
    CMD_SELECT_FILTER,
    SET_SWEEP_MODE,
    MISC_CHECK_LOCK_TIME,
    MISC_RC_FILTER_FUNC,
    SUB_BAND_SET_CH,
    SET_GRD_SLAVE_MODE,
    SET_FIND_BESIDE_DEV,
    SET_LNA_STATUS,
    SET_NON_LBT,
    SET_BANDEDGE,
    AUTTO_BW_CHANGE,
} ENUM_WIRELESS_FREQ_CHANGE_ITEM;


typedef enum
{
    MCS_MODE_SELECT,
    MCS_MODULATION_SELECT,
    MCS_CODE_RATE_SELECT,
    MCS_IT_QAM_SELECT,
    MCS_IT_CODE_RATE_SELECT,
    MCS_RC_QAM_SELECT,
    MCS_RC_CODE_RATE_SELECT,
    MCS_CHG_RC_RATE,
} ENUM_WIRELESS_MCS_CHANGE_ITEM;

typedef enum
{
    RCID_AUTO_SEARCH,   //set rc id in auto search
    RCID_CONNECT_ID,    //connect to one rc id
    RCID_DISCONNECT,    //Disconnect to one rc id
    RCID_SAVE_RCID,
    RCID_STOP_SEARCH,
    SET_TMP_RC_VT_ID,
    GET_OBJ_VT_ID,
    ENABLE_SEARCH_ID_BY_RSSI, //search id and select rssi max value
} ENUM_WIRELESS_RCID_ITEM;


typedef enum
{
    ENCODER_DYNAMIC_BIT_RATE_MODE,
    ENCODER_DYNAMIC_BIT_RATE_SELECT_CH1,
    ENCODER_DYNAMIC_BIT_RATE_SELECT_CH2,
    ENCODER_TAKE_PICTURE,
    ENCODER_PICTURE_QUALITY_SET,
} ENUM_WIRELESS_ENCODER_CHANGE_ITEM;

typedef enum
{
    FULL_BAND,
    SUB_BAND,
}ENUM_BAND_MODE;

typedef struct
{
    uint8_t                 u8_configClass;
    uint8_t                 u8_configItem;
    uint32_t                u32_configValue;
    uint32_t                u32_configValue1;
	uint32_t				u32_configValue2;
} STRU_WIRELESS_CONFIG_CHANGE;


typedef enum
{
    BB_COM_SESSION_0 = 0,
    BB_COM_SESSION_1,
    BB_COM_SESSION_2,
    BB_COM_SESSION_3,
    BB_COM_SESSION_4,
    BB_COM_SESSION_MAX,
    BB_COM_SESSION_SPI,
} ENUM_BB_COM_SESSION_ID;


typedef enum
{
    BB_COM_SESSION_PRIORITY_HIGH = 0,
    BB_COM_SESSION_PRIORITY_LOW  = 1,
    BB_COM_SESSION_PRIORITY_MAX  = 2
} ENUM_BB_COM_SESSION_PRIORITY;


typedef enum
{
    BB_COM_SESSION_DATA_RT      = 0,
    BB_COM_SESSION_DATA_NORMAL  = 1
} ENUM_BB_COM_SESSION_DATA_TYPE;
typedef enum
{
    BB_COM_TYPE_UART = 0,
    BB_COM_TYPE_SPI  = 1
} ENUM_BB_COM_TYPE;

typedef enum
{
    RF_POWER_OPEN   = 0,    //open mode
    RF_POWER_CLOSE  = 1     //close mode
} ENUM_RF_POWER_MODE;


typedef enum
{
    FCC   = 0,  
    CE    = 1 ,
    SRRC  = 2,
    OTHER = 3
} ENUM_RF_POWER_WORK_MODE;

typedef enum
{
    MIMO_1T1R   = 0,
    MIMO_1T2R   = 1,
    MIMO_2T2R   = 2
} ENUM_MIMO_MODE;

typedef enum
{
    LNA_OPEN = 0,
    LNA_BYPASS = 1,
    LNA_AUTO = 2
}ENUM_LNA_MODE;

typedef enum
{
    OPEN_LNA = 0,
    BYPASS_LNA = 1,
    INVALID_LNA = 2
}ENUM_LNA_STATUS;

typedef struct
{
    ENUM_RF_POWER_MODE mode;            //mode:  open or close
    uint8_t powerAutoCtrl;              //Enable or disable open power control
    uint8_t tssi_update_time;

    ENUM_RF_POWER_WORK_MODE power_work_mode;

    uint8_t rcPowerFcc[2];           //close power FCC  for band0, band1
    uint8_t rcPowerCe[2];            //close power CE   for band0, band1
    uint8_t rcPowerSrrc[2];          //close power srrc for band0, band1
    uint8_t rcPowerOther[2];          //close power srrc for band0, band1
    uint8_t vtPowerFcc[2];           //close power FCC  for band0, band1
    uint8_t vtPowerCe[2];            //close power CE   for band0, band1
    uint8_t vtPowerSrrc[2];          //close power srrc for band0, band1
    uint8_t vtPowerOther[2];          //close power srrc for band0, band1
} STRU_RF_POWER_CTRL;


typedef enum
{
    PAGE0 = 0x00,
    PAGE1 = 0x40,
    PAGE2 = 0x80,
    PAGE3 = 0xc0,
    PAGE_UNKNOW = 0xFF,
} ENUM_REG_PAGES;


typedef struct
{
    uint8_t         magic_header[2];
    uint16_t        msg_id;
    uint8_t         packet_num;
    uint8_t         packet_cur;
    uint16_t        msg_len;
    uint16_t        chk_sum;
} STRU_WIRELESS_MSG_HEADER;

typedef struct
{
    uint32_t        magic_header;
    uint32_t        sky_or_grd;
    uint32_t        rsv[6];
} STRU_WIRELESS_RESET_DATA_RSV;

/* To PC or PAD, display wireless info */
/*if head == 0x00 && tail == 0xff, the sram data is valid*/
typedef struct
{
    uint8_t         magic_header[2];
    uint16_t        msg_id;
    uint8_t         packet_num;
    uint8_t         packet_cur;
    uint16_t        msg_len;
    uint16_t        msg_chksum;
    uint16_t        snr_vlaue[2];           //0,1 3,2
    uint16_t        u16_afterErr;           //5,4  masoic
    uint8_t         u8_optCh;               //6 current optional channel
    uint8_t         u8_mcs;                 //7
    int16_t         sweep_energy[21*8];     //Max channel: 21
    uint16_t        ldpc_error;             //9,8 error after Harq
    uint8_t         agc_value[4];           //13 12 11 10
    uint8_t         harq_count;             //14
    uint8_t         modulation_mode;        //15
    uint8_t         e_bandwidth;            //16
    uint8_t         code_rate;              //17
    uint8_t         osd_enable;             //18
    uint8_t         IT_channel;             //19
    uint8_t         head;                   //20
    uint8_t         tail;                   //21
    uint8_t         in_debug;               //22
    uint8_t         lock_status;            //23
    uint16_t        video_width[2];         //27,26 25,24
    uint16_t        video_height[2];        //31,30 29,28
    uint8_t         frameRate[2];           //33,32
    uint8_t         encoder_bitrate[2];     //35,34
    uint8_t         rc_modulation_mode;     //36
    uint8_t         rc_code_rate;           //37
    uint8_t         encoder_status;         //38
    uint8_t         errcnt1;                //39
    uint8_t         errcnt2;                //40
    uint8_t         u8_rclock;              //41
    uint8_t         u8_nrlock;              //42
    uint8_t         sky_agc[4];             //43,44,45,46
    uint8_t         reserved0;              //47
    uint16_t        dist_zero;              //49,48
    uint16_t        dist_value;             //50,51
    uint16_t        sky_snr;                //52~53
    uint16_t        enc_running_cnt;        //54~55
    uint32_t        sdram_buf_size[2];      //56~63
    uint8_t         find_beside_dev_finish; //64
    uint8_t         find_beside_dev_num;    //65, sky start, search how many the same device type beside(default function is off , need app open)
    uint8_t		    current_pwr			;   //66,
    //uint32_t		sweep_avr[40]		;	//67~227
    
} STRU_WIRELESS_INFO_DISPLAY;


typedef struct
{
    uint8_t         magic_header[2];
    uint16_t        msg_id;
    uint8_t         packet_num;
    uint8_t         packet_cur;
    uint16_t        msg_len;
    uint16_t        msg_chksum;
    uint8_t         skyGround;
    uint8_t         band;
    uint8_t         bandWidth;
    uint8_t         itHopMode;
    uint8_t         rcHopping;
    uint8_t         adapterBitrate;
    uint8_t         channel1_on;
    uint8_t         channel2_on;
    uint8_t         isDebug;
    uint8_t         itQAM;
    uint8_t         itCodeRate;
    uint8_t         rcQAM;
    uint8_t         rcCodeRate;
    uint8_t         ch1Bitrates;
    uint8_t         ch2Bitrates;
    uint8_t         reserved[1];//define to display power value
    uint8_t         u8_itRegs[4];
    uint8_t         u8_rcRegs[4];    
    uint8_t         rvc                 :   4;
    uint8_t         sleep_level         :   2;
    uint8_t         switch_mode_2g_5g   :   1; 
    uint8_t         pure_vt_valid       :   1;
    uint8_t         rcId[5];
    uint8_t         chipId[5];

    uint8_t         vtid[2];
    uint8_t         en_realtime;
    uint8_t         inSearching;
    //lna_status define
    //bit[0] : 0,lna open , 1 lna close ( lna bypass).   
    //bit[2:1] : 0,always lna open mode, 1, alway lna close mode, 2 lna auto mode
    //bit[6:3] : bandedge lower power value; range value [0,15]
    //bit[7] : bandedge enable flag, 1 enable, 0 disable 
    uint8_t         lna_status;
    uint8_t         u8_startWrite;  //u8_startWrite: cpu2 start update the flag
    uint8_t         u8_endWrite;    //u8_endWrite:   cpu2 end update the flag
} STRU_DEVICE_INFO;

typedef struct
{
     uint8_t en_flag; //0,default, 1,switch qam mode,2,wait lock,if timeout not lock, goto default qam
     uint8_t value;
     uint8_t cnt;
     uint32_t timeout_cnt;
     uint8_t default_qam_value;
     uint8_t en_reset;
} STRU_RCRATE_CMD;

typedef struct
{
	 uint8_t patten[10];
	 uint8_t common_patten[10];
	 uint8_t valid;
     uint8_t en_flag; 
     uint8_t timeout_cnt;
	 uint8_t wait_reconnect_time_cnt;
	 
	 uint8_t patten_grd[10];
	 uint8_t en_flag_grd; 
	 uint8_t valid_grd;
	 uint8_t timeout_cnt_grd;
} STRU_RCPATTEN_CMD;

typedef struct
{
	 uint8_t bw;
	 uint8_t ldpc;
	 uint8_t valid;
     uint8_t en_flag; 
     uint8_t timeout_cnt;
	 uint8_t autobw;
	 
} STRU_RFBW_CMD;


typedef struct
{
     uint8_t id; 
     signed char value;
} STRU_RF_DATA;




typedef struct
{
    uint8_t     subType     :   2;
    uint8_t     rsv         :   3;
    uint8_t     rfCh        :   1;
    uint8_t     type        :   1;
    uint8_t     dir         :   1;
}STRU_REG_FLAG;

typedef struct
{
    STRU_REG_FLAG   flag;
    uint8_t         page;
    uint8_t         addr;
    uint8_t         value;
}STRU_BB_REG_CMD;

typedef struct
{
    STRU_REG_FLAG   flag;
    uint8_t         addr_h;
    uint8_t         addr_l;
    uint8_t         value;
}STRU_RF_REG_CMD;


typedef struct
{
    uint8_t u8_upLinkSwitch;        //0:disable 1:enable
    uint8_t u8_upLinkKeyArray[32];
    uint8_t u8_downLinkSwitch;      //0:disable 1:enable
    uint8_t u8_downLinkKeyArray[32];
    uint8_t reserve[2];
} STRU_BB_AES;

typedef     int (*BBCallBack)(void *p);

typedef enum
{
    FLAG_VALID,
    FLAG_INVALID,
} ENUM_VALID_FLAG;

typedef enum
{
    AGC_GEAR_2,
    AGC_GEAR_1,
} ENUM_AGC_GEAR;

typedef struct
{
    ENUM_AGC_GEAR e_gear;
    uint8_t u8_agcSwitchThresh;
    uint8_t reserve[2];
}STRU_AGC_SET;

typedef enum
{
    PWR_LEVEL0,        
    PWR_LEVEL1,        
    PWR_LEVEL2,       
    PWR_LEVEL3, 
    PWR_LEVEL4,
} ENUM_PWR_CTRL;

typedef struct
{
    uint16_t mod_status_update_time;
    uint8_t mod_status_update_enable;
    ENUM_PWR_CTRL pwr_ctrl;
}STRU_PWR_CTRL;


typedef enum
{
    GRD_RC_SEARCH_END     = 0,
    GRD_WAIT_SKY_RC_ID    = 1,
    GRD_WAIT_SKY_VT_MATCH = 2,
    GRD_WAIT_SKY_VT_MATCH_DELAY14MS = 3,
} ENUM_GRD_SEARCH_STATES;


typedef enum
{
    SKY_RC_SEARCH_END    = 0,
    SKY_WAIT_VT_ID_MSG   = 1,
    SKY_WAIT_RC_ID_MATCH = 2,
} ENUM_SKY_SEARCH_STATE;



#define BB_LOCK_STATUS                  (0)

#define BB_GET_RCID                     (1)
#define BB_GRD_SEARCHING_STATES_CHAGE   (2)
#define BB_SKY_SEARCHING_STATES_CHAGE   (3)
#define BB_GOT_ERR_CONNNECT             (4)

#define RC_ID_SIZE                      (5)
#define VT_ID_SIZE                      (2)

#endif

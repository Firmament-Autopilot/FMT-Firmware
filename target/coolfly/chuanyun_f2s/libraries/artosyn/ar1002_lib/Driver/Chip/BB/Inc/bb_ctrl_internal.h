#ifndef __BB_INTERNAL_CTRL_
#define __BB_INTERNAL_CTRL_

#include <stdint.h>
#include "bb_customerctx.h"
#include "bb_ctrl.h"
#include "bb_spi.h"
//#include "rf_if.h"
#include "bb_regs.h"
#include "memory_config.h"
#include "boardParameters.h"
#include "factory.h"

#define NON_LBT_RELEASE //normal user , if authentication, note it

#define VT_CONTINUE_UNLOCK_NUM      (36)

#define SWEEP_FREQ_BLOCK_ROWS           (10)

#define SWEEP_FREQ_STATISTICS_ROWS           (100)
#define SKY_PATTEN_MAX_Dynamic_SIZE_2G	(6)


#define MAX_RC_FRQ_SIZE             (40)
#define MAX_IT_FRQ_SIZE             (40)
#define MAX_IT_PWR_STATICS          (10)

#define RC_FRQ_MAX_MASK_NUM         (10)
#define RC_FRQ_MASK_THRESHOLD       (5)

#define BACK_TO_2G_UNLOCK_CNT       (285)

#define GRD_SWEEP_LNA_SWITCH_THRESHOLD (-55)
#define SKY_SWEEP_LNA_SWITCH_THRESHOLD (-60)
#define SWEEP_LNA_SWITCH_THRESHOLD_nper100 (10)
#define SWEEP_LNA_SWITCH_THRESHOLD_nper1000 (50)
#define NON_LBT_VT_CH_SKIP_INTERVAL (1010)

#define OTHER_BAND(band)    ( (band == RF_2G)?  RF_5G : RF_2G )
#define BAND_CHANGE_DELAY   (40)
// CPU0 and CPU2 share memory for osd status info, offset in SRAM: 16K + 512Byte
// last 16 bytes is for DEVICE INFO
#define DEVICE_INFO_SHM_SIZE             (sizeof(STRU_DEVICE_INFO))
#define DEVICE_INFO_SHM_ADDR             ((SRAM_BB_STATUS_SHARE_MEMORY_ST_ADDR + SRAM_BB_STATUS_SHARE_MEMORY_SIZE) - DEVICE_INFO_SHM_SIZE)
typedef enum
{
    IDLE,
    INIT_DATA,
    FEC_UNLOCK,
    FEC_LOCK,
    DELAY_14MS,
    CHECK_FEC_LOCK,
    LOCK,
    SEARCH_ID,
    CHECK_LOCK,
    WAIT_VT_LOCK,
    FIND_SAME_DEV,
}DEVICE_STATE;


#define FALSE   (0)
#define TRUE    (1)

#define FREQ_SUB_BAND_10M_RC_NUM 4
#define FREQ_SUB_BAND_20M_RC_NUM 8

#define DEFAULT_IT_CH 1



typedef struct _STRU_FRQ_CHANNEL           //  Remote Controller Freq Channnel
{
    uint8_t frq1;
    uint8_t frq2;
    uint8_t frq3;
    uint8_t frq4;
    uint8_t frq5;
} STRU_FRQ_CHANNEL;


typedef enum
{
    EQUAL_2G_5G = 0,
    BETTER_2G   = 1,
    BETTER_5G   = 2,
    UNKNOWN_BETTER = 3,
} ENUM_RF_select;



typedef enum
{
    MISC_READ_RF_REG,
    MISC_WRITE_RF_REG,
    MISC_READ_BB_REG,
    MISC_WRITE_BB_REG,
} ENUM_WIRELESS_MISC_ITEM;

typedef struct
{
    uint8_t u8_rcNrLockCnt;
    uint8_t u8_rcCrcLockCnt;
} STRU_rcLockCnt;

typedef struct
{
    uint8_t u8_skyagc1;
    uint8_t u8_skyagc2;
    uint16_t snr;
	uint8_t	u8_tx_pwr;
} STRU_skyAgc;

typedef struct
{
    uint8_t u8_skyRcIdArray[RC_ID_SIZE];
    uint8_t u8_grdRcIdArray[RC_ID_SIZE];
} STRU_SyncrcId;

typedef struct
{
    uint8_t  u8_opt;
    uint8_t  u8_md5[16];
    uint16_t u16_data[3];
}STRU_upgradeDataPack;


#define         MAXSCORE                    (100)
#define         MINSCORE                    (-100)
#define         MAXUSECOUNT                 (2)

#define         RC_CH_BYTES_CNT             (100)
#define         INVALIDE_SUB_BAND_VALUE     (255)

typedef struct
{
    uint8_t u8_rcNrLockCnt;
    uint8_t u8_rcCrcLockCnt;
    uint8_t u8_skyagc1;
    uint8_t u8_skyagc2;
    uint16_t snr;
	uint8_t tx_pwr;
} STRU_SkyStatus;


#define QAM_CHANGE_THRESHOLD_COUNT (6)

typedef struct _STRU_BandChange
{
    uint8_t             flag_bandchange;
    uint8_t             u8_eqCntChg;
    uint8_t             u8_ItCh;
    uint8_t             u8_optCh;
    uint8_t             e_toBand;
	uint8_t				chg_mcs;
    uint16_t            u16_unlockLoopCnt;
}STRU_BandChange;


typedef union 
{
    STRU_SKY_BAND_SWITCH_PARAM sky_bandSwitchParm;
    STRU_GRD_BAND_SWITCH_PARM grd_bandSwitchParm;    
} UNION_BandSwitchParm;


typedef struct
{
    uint8_t u8_bandSwitchAfterUnlock;
    int8_t  i8_skyPower0;
    int8_t  i8_skyPower1;
} STRU_BAND_SWITCH_PARAM;
typedef enum
{
    RF_SIGNAL_UNBLOCK_MODE  = 0,
    RF_SIGNAL_BLOCK_MODE    = 1,
    RF_SIGNAL_UNKNOWN_MODE  = 2
} ENUM_RF_SIGNAL_BLOCK;


typedef struct
{


	STRU_RF_DATA sweep_pwr_table[SWEEP_FREQ_BLOCK_ROWS][MAX_RC_FRQ_SIZE];
	//STRU_RF_DATA work_snr_table[SWEEP_FREQ_BLOCK_ROWS][MAX_RC_FRQ_SIZE];
	STRU_RF_DATA work_rc_unlock_table[SWEEP_FREQ_BLOCK_ROWS][MAX_RC_FRQ_SIZE];
	
	STRU_RF_DATA sweep_pwr_avrg_value[MAX_RC_FRQ_SIZE];
	//STRU_RF_DATA work_snr_avrg_value[MAX_RC_FRQ_SIZE];
	STRU_RF_DATA sweep_pwr_fluct_value[MAX_RC_FRQ_SIZE];
	//STRU_RF_DATA work_snr_fluct_value[MAX_RC_FRQ_SIZE];
	STRU_RF_DATA work_rc_error_value[MAX_RC_FRQ_SIZE];
	
	int32_t i32_working_times[MAX_RC_FRQ_SIZE];//

	uint8_t   rc_ch_working_patten[MAX_RC_FRQ_SIZE];
	uint8_t	  rc_ch_working_patten_size; /// the number of rc channels
	uint8_t   rc_ch_patten_need_id_size;///the size of the representative for patten 
	uint8_t	  rc_ch_working_patten_len;///the len for working patten channel numbers
	uint8_t   rc_ch_dynamic_working_patten_max_len; 
	uint8_t   sweep_noise_thd;
	uint8_t   sweep_patten_size;
	uint32_t   rc_patten_nextchg_delay;//
	uint8_t	  rc_avr_sweep_result_size;

	uint8_t rc_patten_set_by_usr;
	uint8_t curSweepCh;
	uint8_t bandCnt;
	uint8_t curBandIdx;
	ENUM_CH_BW   e_bw;
	ENUM_RF_BAND sweepBand[2]; 
	uint8_t isFull;
	uint8_t curRowCnt;
	uint8_t sweep_cycle;
	uint8_t currc_statistics_Row;
	uint8_t currc_statistics_ch;
	uint8_t sweep_freqsize;
	//uint8_t f5g_freqsize;

	//caculation
	uint8_t sweep_finished;
	uint8_t lock_sweep;
	uint8_t fine_sweep_id;
	uint8_t fine_sweep_row;
	uint8_t fine_sweep_size;
	uint8_t error_ch_record[MAX_RC_FRQ_SIZE];
	STRU_RF_DATA sort_result_list[MAX_RC_FRQ_SIZE];
	STRU_RF_DATA pre_selection_list[MAX_RC_FRQ_SIZE];
	STRU_RF_DATA prelist[MAX_RC_FRQ_SIZE];	

	STRU_BOARD_RF_BW_CHG rf_bw_cg_info;

	uint16_t it_unlock_timeout_cnt;
	uint16_t rc_unlock_timeout_cnt;
	uint8_t rc_sweep_log_open;
	uint8_t	 skyp0;
	uint8_t	 skyp1;
	uint8_t  skytxp;
	//vt
	ENUM_RF_BAND e_bandsupport;
	uint8_t    u8_mainCh; 		 //current VT channel
	uint8_t	   u8_mainSweepRow;
	uint8_t	   u8_mainSweepCh;
	
	uint8_t	   u8_optCh;		   //optional VT channel
	uint8_t	   u8_optSweepRow;
	uint8_t	   u8_optSweepCh;
	uint8_t	   u8_bestBb1ChCnt[MAX_IT_FRQ_SIZE];
	uint8_t	   u8_bestBb2ChCnt[MAX_IT_FRQ_SIZE];
    uint32_t   working_pwr[MAX_IT_PWR_STATICS];
	uint32_t   working_pwr_avrg;
	uint8_t    u8_spareSweepCh;       //channel number
    uint8_t    u8_optBandSweepCh;     //use to sweep another band channel.

    uint8_t      u8_curBb1Row;
    uint8_t      u8_curBb2Row;
    ENUM_RF_BAND e_prevSweepBand;       //previous sweep band
    uint8_t      u8_prevSweepCh;        //previous sweep channel, main channel and optional channel may change

    uint8_t      u8_cycleCnt;
    uint8_t      u8_totalCyc;
    uint8_t      u8_preMainCh;
    uint16_t     u16_preMainCount;      //if cycle >= u16_preMainCount, clear the u8_preMainCh

    ENUM_RF_select band_sel[15];
    uint8_t      u8_bandSelCnt;
    uint8_t      u8_isFull;
    uint8_t      u8_bb1ItFrqSize;
    uint8_t      u8_bb2ItFrqSize;

    uint8_t      u8_cmdSweep;

    ENUM_RF_SIGNAL_BLOCK    flag_signalBlock;
	
}RF_INFO;


typedef struct
{
    uint8_t             cur_IT_ch;
    uint8_t             next_IT_ch;
    uint8_t             it_manual_ch;
    ENUM_RUN_MODE       e_rfbandMode;
    uint16_t             fec_unlock_cnt;
    uint16_t            rc_unlock_cnt;
	uint16_t 			it_fec_unlock_cnt;

    ENUM_RUN_MODE       itHopMode;
    ENUM_RUN_MODE       rcHopMode;
    ENUM_RUN_MODE       qam_skip_mode;
    ENUM_RUN_MODE       brc_mode;
    ENUM_TRX_CTRL       trx_ctrl;
    uint8_t             brc_bps[2];             //unit: Mbps

    ENUM_RF_BAND        e_curBand;              //current band: 2.4G, 5.8G
    ENUM_BB_QAM         qam_mode;
    ENUM_BB_QAM         rc_qam_mode;
    ENUM_BB_LDPC        ldpc;
    ENUM_BB_LDPC        rc_ldpc;

    uint8_t             qam_ldpc;
    uint8_t             enable_plot;
    uint8_t             rcid[RC_ID_SIZE];
    uint8_t             vtid[VT_ID_SIZE];
    uint8_t             chipid[RC_ID_SIZE];

    uint8_t             need_write_flash;
    uint8_t             pwr;

    uint8_t             locked;     //[0]:vt lock  [1]: vt id match
    uint8_t             rc_status;

    uint16_t            mosaic;
    uint8_t             default_fac_setting;
    uint8_t             search_id_enable;
    uint8_t             bb_power;    
    ENUM_RUN_MODE       rf_power_mode;
    uint8_t             enable_freq_offset;
    uint8_t             flag_mrc;
    uint8_t             flag_updateRc; //need to update Remote controller frequency

    uint16_t            cycle_count; 

    uint8_t             u8_rcValue[5];
    uint32_t            qam_switch_time;
	uint16_t			ldpc_error_cnt; 

    uint8_t             ldpc_error_move_cnt;
    DEVICE_STATE        dev_state;

    uint8_t             u8_debugMode;
    uint8_t             u8_flagdebugRequest;
    STRU_FRQ_CHANNEL    stru_rcRegs;
    STRU_FRQ_CHANNEL    stru_itRegs;
    ENUM_BB_MODE        en_bbmode;
    uint8_t             agclevel;

    uint8_t             u8_bbStartMcs;
    uint8_t             u8_harqcnt_lock;
    STRU_BandChange     stru_bandChange;
    STRU_CUSTOMER_CFG   *pcustomer_cfg;

    uint8_t             sky_rc_channel;
	uint8_t				sky_rc_record_row;
	uint8_t				grd_rc_channel;
	ENUM_RC_HOPE_PATTEN_MODE	rc_hoping_patten_mode;
    uint8_t             sync_cnt;
	
    //aoc parameter
    STRU_BB_AOC         aoc;

    uint8_t   rc_ch_map[MAX_RC_FRQ_SIZE + 2];
	
	RF_INFO rf_info;
	
	uint8_t  read_ch_id;
	uint8_t	  rc_eq_channel;
	uint8_t   rc_have_update_list;
	uint8_t	  rc_unlocked_channel;
	uint8_t	  grd_get_rc_sweep_ch_cnt;
	uint32_t   it_chg_gap_delay;//
    STRU_BB_RC_CH_SELECTION st_chSelectionParam;
    uint8_t             u8_TargetPower[2];
    ENUM_RF_POWER_MODE  e_powerMode;            //open close mode
    ENUM_RF_POWER_WORK_MODE e_powerWorkMode;    //FCC,CE,,
    
    ENUM_RF_select         e_bandSelFromSweep;     //band selection from sweep
    UNION_BandSwitchParm  *u_bandSwitchParam;

    STRU_BAND_SWITCH_PARAM stru_bandSwitchParam;

    STRU_RF_BAND_MCS_OPT   st_bandMcsOpt;
	uint8_t            u8_aocAdjustPwr;
	STRU_MIMO_MODE       st_mimo_mode;
	
	uint8_t     rc_start;
    uint8_t     rc_end;
    uint8_t     vt_start;
    uint8_t     vt_end;
    ENUM_BAND_MODE freq_band_mode;
    uint8_t    sub_band_value;
    uint8_t    sub_rc_start;
    uint8_t    sub_rc_end;
    uint8_t    sub_bb_locked;
    uint8_t    select_obj_vt_ok;
    uint8_t    sub_band_main_ch;
    uint8_t    sub_band_opt_ch;
    uint32_t   sub_band_main_opt_ch_time;
    uint8_t    slave_flag;//0 grd master mode, 1 grd slave mode
    uint32_t   wimax_irq_time;
    ENUM_LNA_STATUS lna_status;
    uint8_t    need_lna_open;
    uint8_t    hashRcid[RC_ID_SIZE];
    uint8_t    hashVtid[VT_ID_SIZE];
    uint8_t    inSearching;
    uint8_t    mcs_delay_cnt;
    uint8_t    mcs_switch_state;
    uint8_t    mcs_empty_pack_cnt;
    uint8_t    realtime_mode;
    //uint8_t    enable_rc_skip_patten;
    //uint8_t    rc_skip_patten;
    uint8_t    enable_rc_random_skip_patten;
    uint8_t    command_lna_switch_flag;
    uint8_t    command_lna_switch_value;
    uint8_t    swp_bypass;/////1 need bypass, 2 can open
    ENUM_LNA_MODE factory_lna_mode;
    uint8_t    enable_non_lbt;//CE mode
    uint8_t    sky_sel_vt_ch;
    uint8_t    sky_sel_vt_ch_flag;
    uint32_t   vtFreqTime[40];
    uint8_t    fem_close;
	uint8_t	   sky_tx_only_flag;
	uint8_t	   flag_in_upgrade;
    uint8_t    vtskip_stat;
    uint8_t    delay_it_flag;
    uint8_t    delay_it_ch;
    uint8_t    low_power_db;
    uint8_t    bandedge_enable;
    uint8_t    sleep_level;
    uint8_t    uplink_qam_mode;
    STRU_RCRATE_CMD RcChgRate;
	STRU_RCPATTEN_CMD rcChgPatten;
	STRU_RFBW_CMD rf_bw;
	
    uint8_t    aes_off;
}CONTEXT;


typedef struct param
{
    ENUM_RUN_MODE   itHopMode;
    ENUM_RUN_MODE   rcHopMode;
    ENUM_RUN_MODE   qam_skip_mode;
    uint16_t        qam_change_threshold[QAM_CHANGE_THRESHOLD_COUNT][2];
}PARAM;


#define CALC_DIST_RAW_DATA_MAX_RECORD    (100)

typedef enum
{
    INVALID,
    CALI_ZERO,
    CALC_DIST_PREPARE,
    CALC_DIST
}ENUM_CALC_DIST_STATUS;


typedef struct
{
    ENUM_CALC_DIST_STATUS e_status;
    uint8_t     u8_rawData[CALC_DIST_RAW_DATA_MAX_RECORD][3];
    uint32_t    u32_calcDistValue;
    uint32_t    u32_calcDistZero;
    uint32_t    u32_cnt;
    uint32_t    u32_lockCnt;
} STRU_CALC_DIST_DATA;


typedef struct
{
    uint64_t    u64_mask; // bit0 <-> freq0  ... bit63 <-> freq63
    uint64_t    u64_rcvGrdMask; // received mask from spi, send by grd
    uint8_t     u8_unLock[MAX_RC_FRQ_SIZE]; // continue unlock cnt 
    uint8_t     u8_maskOrderIndex;
    uint8_t     u8_maskOrder[RC_FRQ_MAX_MASK_NUM]; // u8_maskOrder[0] earlist masked frq's channel                                      
} STRU_RC_FRQ_MASK;


extern volatile CONTEXT context;
extern volatile DEVICE_STATE dev_state;

typedef struct _STRU_GRD_STATUS
{
    uint16_t             u16_grd_snr;
    uint8_t              agc_value1;
    uint8_t              agc_value2;
}STRU_GRD_STATUS;


#define DT_ADDR     SRAM_BB_DT_ST_ADDR

typedef enum
{
    DT_NUM_MIN,                     //
    DT_NUM_SKY_LOCK_STATUS,         //1
    DT_NUM_RC_MASK_CODE,            //2
    DT_NUM_SKY_AGC_STATUS,          //3
    DT_NUM_RC_ID_SYNC,              //4
    DT_NUM_SKY_UPGRADE,             //5
    DT_NUM_REMOTE_EVENT,            //6
    DT_NUM_RC_CH_MODE,              //7
    DT_NUM_IT_CH_MODE,              //8
    DT_NUM_RF_BAND_CHANGE,          //9
    DT_NUM_RF_CH_BW_CHANGE,         //10
    DT_NUM_MCS_MODE_SELECT,         //11
    DT_NUM_ENCODER_BRC_CHAGE_CH1,   //12
    DT_NUM_ENCODER_BRC_CHAGE_CH2,   //13
    DT_NUM_RF_CH_LDPC_CHANGE,       //14
    DT_NUM_RF_CH_QAM_CHANGE,        //15
    DT_NUM_GRD_MASK_CODE,           //16
    DT_NUM_RC_FRQ,                  //17
    DT_NUM_IT_FRQ,                  //18
    DT_NUM_FRE_OFFSET,              //19
    DT_NUM_RC_RATE,                 //20
    DT_NUM_GRD_SEND_VT_ID,           //21
    DT_NUM_GROUND_SYNC_RC_ID,       //22
    DT_NUM_RF_BAND_MODE,            //23
    DT_NUM_SKY_STATUS,              //24
    DT_NUM_CH_MAP,                  //25
    DT_NUM_SYNC_STATUS,             //26
    DT_NUM_AOC_ADJUST,              //27
    DT_NUM_BANDSWITCH_ENABLE,       //28
    DT_NUM_FILTER_CHG,              //29
    DT_NUM_TAKE_PICTURE,            //30
    DT_NUM_PICTURE_QUALITY_SET,     //31
    DT_NUM_BAND_MODE_CHG,           //32
    DT_NUM_LNA_STATUS_CHG,          //33
    DT_NUM_NON_LBT_ENABLE,          //34
    DT_NUM_NON_LBT_NOTICE_OPTCH,    //35
    DT_NUM_SKY_SWEEP_NOISE,			//36
    DT_NUM_SKY_RC_PATTEN,			//37
    DT_NUM_GRD_RC_CHPATTEN,			//38
    DT_NUM_AUTO_CH_BW_CHANGE,       //39
    DT_NUM_MAX,                     //
}ENUM_DT_NUM;

typedef struct
{
    uint8_t flag        : 1;
    uint8_t priority    : 1;
    uint8_t ack         : 1;
    uint8_t len         : 5;
    ENUM_DT_NUM num     : 8;
} STRU_DT_HEAD;

typedef struct
{
    uint8_t         valid;
    uint8_t         step;
    ENUM_RUN_MODE   itHopMode;
}STRU_PURE_VT_INFO;

typedef enum
{
    BB_TRANSMIT_ONLY_MODE  = 0,     // 00: transmit only
    BB_RECEIVE_ONLY_MODE   = 1,     // 01: receive only
    BB_NORMAL_MODE         = 2,     // 10: normal mode
}ENUM_BB_TRX_MODE;


typedef enum
{
    SKY_MUST_SWITCH_2G,
    SKY_MUST_SWITCH_5G,
    SKY_MUST_NOT_SWITCH,
    SKY_EQUAL_2G_5G,
} ENUM_BAND_SWITCH_OPTION;





#define     STATUS_CHG_DELAY        (64)
typedef struct
{
    uint8_t     valid;
    uint8_t     cnt;
} STRU_DELAY_CNT;

// #define MAX(a,b) (((a) > (b)) ?  (a) :  (b) )

void BB_uart10_spi_sel(uint32_t sel_dat);


int BB_softTxReset(ENUM_BB_MODE en_mode);

int BB_softRxReset(ENUM_BB_MODE en_mode);

uint8_t BB_ReadReg(ENUM_REG_PAGES page, uint8_t addr);

uint8_t BB_WriteReg(ENUM_REG_PAGES page, uint8_t addr, uint8_t data);

int BB_WriteRegMask(ENUM_REG_PAGES page, uint8_t addr, uint8_t data, uint8_t mask);

int BB_ReadRegMask(ENUM_REG_PAGES page, uint8_t addr, uint8_t mask);


void BB_set_RF_Band(ENUM_BB_MODE sky_ground, ENUM_RF_BAND rf_band);

void BB_set_RF_bandwitdh(ENUM_BB_MODE sky_ground, ENUM_CH_BW rf_bw);

int BB_GetCmd(uint8_t type, STRU_WIRELESS_CONFIG_CHANGE *pconfig);


void BB_handle_misc_cmds(STRU_WIRELESS_CONFIG_CHANGE* pcmd);

int BB_add_cmds(uint8_t type, uint32_t param0, uint32_t param1, uint32_t param2, uint32_t param3);

void BB_set_QAM(ENUM_BB_QAM mod);

void BB_set_LDPC(ENUM_BB_LDPC ldpc);

void BB_write_ItRegs(uint8_t *u8_it);

int BB_WriteRegMask(ENUM_REG_PAGES page, uint8_t addr, uint8_t data, uint8_t mask);

int grd_GetDistAverage(int *pDist);

void BB_saveRcid(uint8_t *u8_rcIdArray, uint8_t *u8_vtIdArray);

int BB_GetDtInfo(ENUM_DT_NUM e_num, uint8_t *len, uint32_t *addr, uint8_t *idx);

int BB_DtSendToBuf(ENUM_DT_NUM e_num, uint8_t *arg);
int BB_DtStopSend(ENUM_DT_NUM e_num);
void BB_DtSentToSession(void);



int BB_Session0SendMsg(uint8_t id, uint8_t* data_buf, uint16_t len);

int BB_Session0RecvMsg(uint8_t* data_buf, uint16_t buflen);


void BB_RcSelectionInit(void);

void sky_rcFrqStatusStatistics600m(void);

uint8_t sky_checkRcLock(uint8_t u8_lockStatus);

void sky_rcHopFreq(void);

void sky_rcHopFreq600m(uint8_t div);

uint8_t sky_rcUnLockHopBand(void);

void BB_SetTrxMode(ENUM_BB_TRX_MODE mode);

void bubble_sort(int * data, int datasize, int round);

void sky_handle_RF_band_cmd(uint8_t *arg);

void grd_requestRfBandSwitch(ENUM_RF_BAND e_band);

uint8_t grd_snr_forBandChange(void);

void sky_soft_reset(void);

void sky_switchSetPower(ENUM_RF_BAND band);

void sky_doRfBandChange(uint8_t u8_lockStatus);

void sky_handle_RF_band_cmd_pure_vt( ENUM_RF_BAND rf_band);

void BB_ResetRcMap(void);

//void BB_RcSelectionInit(void);


//bb_grd_search.c

void grd_SetRCId(uint8_t *pu8_id);

void BB_grd_handleRcSearchCmd(STRU_WIRELESS_CONFIG_CHANGE* pcmd);

void BB_grd_checkSearchEnd(void);

void BB_grd_ackSkyRcIdSendVtId(uint8_t *pu8_rcid);

void BB_grd_setConnectRcId(uint8_t *pu8_rcId, uint8_t * pu8_vtid);

uint8_t BB_grd_isSearching(void);

uint8_t BB_grd_checkVtIdMatch(void);


//bb_sky_search.c

void BB_sky_requestStartSearch(void);

void BB_sky_requestStopSearch(void);

void BB_sky_ackVtidMessage(uint8_t *pu8_vtid);

void BB_sky_handleRcSearchCmd(void);

void BB_sky_checkSearchEnd(uint8_t u8_lockStatus);

uint8_t BB_sky_inSearching(void);

void BB_sky_vtId(uint8_t *pu8_vtid);

uint8_t BB_sky_isSearching(void);

uint8_t BB_sky_isErrorConnectInSearching(uint8_t status);

uint8_t sky_check_all_mask(uint32_t ch1, uint32_t ch2);

uint32_t sky_get_best_ch(uint32_t ch1, uint32_t ch2);

int sky_reset_ch(uint32_t ch);

int sky_send_rc_map(void);

void selectionSortBy(STRU_RF_DATA *a,int len,STRU_RF_DATA *b,int by);//b is the org list,and a is the result list

signed char vector_1xn_nx1_caculate(uint8_t *a,signed char *b,uint8_t len,uint8_t precision);


#endif

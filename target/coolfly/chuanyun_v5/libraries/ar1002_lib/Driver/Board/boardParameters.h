#ifndef _BOARD_PARAMETERS_H
#define _BOARD_PARAMETERS_H

#include <stdint.h>

#include "bb_types.h"

typedef struct
{
    uint8_t page;       //page: 0,1,2,3
    uint8_t addr;
    uint8_t value;
}STRU_BB_REG;


typedef struct
{
    uint8_t addr_h;
    uint8_t addr_l;
    uint8_t value;
}STRU_RF_REG;


typedef struct 
{
    //before calibration
    uint8_t           u8_bbSkyRegsCnt;

    uint8_t           u8_bbGrdRegsCnt;

    //registers count after calibration
    uint8_t           u8_bbSkyRegsCntAfterCali;

    uint8_t           u8_bbGrdRegsCntAfterCali;

}STRU_BOARD_BB_PARA;




typedef struct
{
    //registers before calibration
    STRU_BB_REG  *pstru_bbSkyRegs;

    STRU_BB_REG  *pstru_bbGrdRegs;    

    //registers after calibration
    STRU_BB_REG  *pstru_bbSkyRegsAfterCali;

    STRU_BB_REG  *pstru_bbGrdRegsAfterCali;
}STRU_BOARD_BB_REG;



typedef struct 
{
    //before calibration

    uint8_t           u8_rfCnt;                 //1: only enable 1 RF8003s
                                                //2: enable 2 RF8003s
    uint8_t           u8_rf0SkyRegsCnt;
                                                    
    uint8_t           u8_rf0GrdRegsCnt;
    
    uint8_t           u8_rf1GrdRegsCnt;

    //registers count after calibration

    uint8_t           u8_rf0SkyRegsCntAfterCali;
                                                    
    uint8_t           u8_rf0GrdRegsCntAfterCali;
    
    uint8_t           u8_rf1GrdRegsCntAfterCali;

    uint8_t           boardCfgName[16];

}STRU_BOARD_RF_PARA;




typedef struct 
{
    STRU_RF_REG  *pstru_rf1SkyRegs;

    STRU_RF_REG  *pstru_rf1GrdRegs;

    STRU_RF_REG  *pstru_rf2GrdRegs;

    STRU_RF_REG  *pstru_rf1SkyRegsAfterCali;

    STRU_RF_REG  *pstru_rf1GrdRegsAfterCali;

    STRU_RF_REG  *pstru_rf2GrdRegsAfterCali;
}STRU_BOARD_RF_REG;

typedef struct 
{
    uint8_t  en_auto;
    uint8_t  thd_10;
    uint8_t  thd_20;
	uint8_t  en_it_hoping_quickly;
	uint8_t	 max_rc_len;
	uint8_t  sweep_noise_thd;
	uint8_t  sweep_patten_size;
	uint8_t  rc_fine_sweep_size;
	uint8_t  it_fine_sweep_size;
	uint8_t  rc_common_ch_size;
	uint8_t  rc_common_ch[50];
	uint16_t it_unlock_timeout_cnt;
	uint16_t rc_unlock_timeout_cnt;
	uint8_t  rc_sweep_log_open;
}STRU_BOARD_RF_BW_CHG;


typedef struct
{
    uint8_t u8_aocEnable;     //0:disable 1:enable
    uint16_t u16_snrThdL;      //
    uint16_t u16_snrThdH;      //
    uint8_t u8_agcThdL;       //
    uint8_t u8_agcThdH;       //
    uint8_t u8_PwrThdMin;     //
    uint8_t u8_snrAvgCnt;     //
    uint8_t u8_agcAvgCnt;     //
    uint16_t u16_ldpcStacCnt;
	uint16_t u16_ldpcThd;
} STRU_BB_AOC;

typedef struct
{
    uint16_t u16_avgCnt; //max 1000
    uint8_t u8_2g_agcThdL;       //
    uint8_t u8_2g_agcThdH;       //
    uint8_t u8_5g_agcThdL;       //
    uint8_t u8_5g_agcThdH;       //
    uint8_t u8_2g_lna;       //
    uint8_t u8_5g_lna;       //
} STRU_BB_LAN_AUTO;


typedef struct
{
    uint8_t u8_rcChSelectionEnable;     //1: enable  0 : disable
    uint8_t u8_rcChReplaceMaxCnt;       //count of the rc channels can be Replaced
    uint16_t u16_rcChReplaceCycles;     //the 14ms cycle for 1 channel replacement
} STRU_BB_RC_CH_SELECTION;

/*
 * structure for sky sweep
*/
typedef struct
{
    uint8_t  u8_band0SweepChannelCnt;
    uint16_t u16_band0SweepFrq[50];

    uint8_t  u8_band1SweepChannelCnt;
    uint16_t u16_band1SweepFrq[50];

    int8_t   i8_SkyBand0SwitchBand1SweepBase;      //the diff for 2.4G switch to 5.8G,  int(7.66 + sensitivity diff) 
    int8_t   i8_diffBand1SwitchBand0;              //the diff for 5.8G switch to 2.4G    
} STRU_SKYSWEEPFRQ;


typedef struct
{
    uint8_t   u8_autoEnable;                                //1: enable auto
    uint8_t   u8_lockPercent;                               //lock percentage for band switch
    uint16_t  u16_skyRcTotalCnt;                            //sky total count

    int8_t    i8_SkyBand0_2_Band1SweepAverUnblock;          //the sweep diff for 2.4G switch to 5.8G in unblock
    int8_t    i8_SkyBand1_2_Band0SweepAverUnblock;          //the sweep diff for 5.8G switch to 2.4G in unblock

    int8_t    i8_SkyBand0_2_Band1SweepAverBlock;            //the sweep diff for 2.4G switch to 5.8G in block
    int8_t    i8_SkyBand1_2_Band0SweepAverBlock;            //the sweep diff for 5.8G switch to 2.4G in block    
} STRU_SKY_BAND_SWITCH_PARAM;


typedef struct
{
    uint8_t   u8_autoEnable;                                //1: enable auto 

    int8_t    i8_GrdBand0_2_Band1SweepAverUnblock;          //the sweep diff for 2.4G switch to 5.8G in unblock
    int8_t    i8_GrdBand1_2_Band0SweepAverUnblock;          //the sweep diff for 5.8G switch to 2.4G in unblock

    int8_t    i8_GrdBand0_2_Band1SweepAverBlock;            //the sweep diff for 2.4G switch to 5.8G in block
    int8_t    i8_GrdBand1_2_Band0SweepAverBlock;            //the sweep diff for 5.8G switch to 2.4G in block

    int8_t    u8_GrdBand0CmpChannelCnt;                     //band0 best channel count for compare
    int8_t    u8_GrdBand1CmpChannelCnt;                     //band1 best channel count for compare

    uint8_t   u8_minMcsForBandSwitch;                       // if mcs < u8_minMcsForBandSwitch, check sweep for band switch

    uint8_t   u8_BlockAgcThresh;
    uint16_t  u16_BlockDistThresh;

} STRU_GRD_BAND_SWITCH_PARM;


#endif

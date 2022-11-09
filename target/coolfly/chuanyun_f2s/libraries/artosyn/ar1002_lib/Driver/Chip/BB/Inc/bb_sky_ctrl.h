#ifndef __SKY_CONTROLLER_H
#define __SKY_CONTROLLER_H

#include <stdint.h>
#include "bb_ctrl_internal.h"
#include "timer.h"

//aes off , uart output data size, include uart_len + uart_data + dummy_data
#define BPSK1_2_LEN 34
#define QPSK1_2_LEN 142
#define BPSK2_3_LEN 70
#define QPSK2_3_LEN 214
#define SKY_PATTEN_SIZE_2G	4


enum EN_AGC_MODE
{
    FAR_AGC     = 0,
    NEAR_AGC    = 1,
    UNKOWN_AGC  = 0xff,
};

#define     SKY_RC_ERR(status)          ((status & 0x80) == 0x80)
#define     SKY_CRC_OK(status)          ((status & 0x02) ? 1 : 0)
#define     SKY_ID_CRC_MATCH(status)    ((status & 0x03) == 0x03)


typedef struct _STRU_SKY_STATUS
{
    init_timer_st        sky_timer2_6;

    STRU_RC_FRQ_MASK     s_st_rcFrqMask;
    enum EN_AGC_MODE     en_agcmode;

    uint8_t              u8_rcStatus;

    uint8_t              cur_groundRcid[5];           //the current ground rc id in searching following mode
    uint16_t             u16_rcUnlockCntBandSwitch;

    uint16_t             u16_sky_snr[1];
    uint8_t              u8_snr_idx;

    uint8_t              agc_value1[50];
    uint8_t              agc_value2[50];

	uint8_t				 keep_far_agc;
	uint8_t 			 sky_ready_check_agc;

    uint8_t              agc_curValue1;
    uint8_t              agc_curValue2;

    uint8_t              agc_idx;
    uint8_t              agc_full;

    uint8_t              flag_errorConnect;             //ground in Lock mode, ground rc id [0x84 ~ 0x87] not match sky rc id

    uint8_t              flag_groundInSearching;        //
    uint8_t              flag_groundVtMatch;
    uint8_t              u8_syncRcId[5];

    uint8_t              u8_userRequestRcSearch;           //u8_userRequestRcSearch: request to search rc id

    uint32_t             u32_cyclecnt;

    ENUM_VALID_FLAG      agc_auto_chg_flag;         //
    ENUM_AGC_GEAR        fct_agc_gear;              //
    uint8_t              fct_agc_thresh;            //
    uint8_t              u8_followingRcId[5];

	uint8_t 			 check_lock_times;
	uint32_t 			 rst_start_time;

	uint8_t 			 ground_LockStatus;			//0xff: unknow status  0: unlock  1: Lock
 }STRU_SKY_STATUS;

typedef struct
{
    uint8_t   idx;
    uint16_t  u16_lock_cnt;
    uint16_t  u16_check_cnt;
    uint8_t   flag_bandSwitch;
} STRU_SKY_LOCK_CNT;
 

void sky_SetSaveRCId(uint8_t *pu8_id, uint8_t *pu8_vtId, uint8_t flag);

//void sky_CalAverSweepResult(uint8_t max_ch_num);
void sky_CalAverSweepResult(uint8_t start, uint8_t end);

int sky_GetAverSweepResult(uint8_t ch);
int sky_Get_statistic_rc_error_Result(uint8_t ch);


int sky_get_rc_current_sweep_ch();
int sky_get_rc_current_sweep_row();

//int sky_GetAverSweepResult600m(uint8_t ch);

int sky_get_rc_total_channel();

void sky_GetSweepNoise(int16_t *ptr_noise_power, uint32_t max);

uint8_t sky_CheckRcJudgeBandSwitch(void);

void sky_agcGainToggle(void);

void sky_set_unlockCnt(uint8_t count);

void sky_sub_band_excute(uint8_t value);

void sky_setRcId(uint8_t *pu8_rcId);

void sky_statistics_rc_ch_error(uint8_t locked);

uint16_t sky_get_rc_snr( void );

void sky_statistics_rc_snr(uint8_t locked);

void sky_gen_rc_working_patten(void);

void sky_handle_mcs_mode_cmd(uint8_t *arg);

void reset_table_for_5g();

#endif

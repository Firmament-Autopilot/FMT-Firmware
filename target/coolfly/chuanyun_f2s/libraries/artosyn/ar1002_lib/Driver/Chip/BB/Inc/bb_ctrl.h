#ifndef __BB_API_
#define __BB_API_

#include "bb_types.h"
#include "bb_customerctx.h"

typedef void (*pfun)(void);
typedef void (*pfun_fem)(uint8_t);


extern uint8_t BB_grd_regs[4][256];
extern uint8_t BB_sky_regs[4][256];

#define RC_SKIP_PATTEN_NUM  68
#define RC_SKIP_CNT  18
#define SELECTION_RC_PATTEN 10



/** 
 * @brief       API for Baseband initialize.
 * @param[in]   en_mode: brief @ENUM_BB_MODE
 */
void BB_init(ENUM_BB_MODE en_mode, STRU_CUSTOMER_CFG *pstru_customerCfg, uint8_t *bb_reg);

/** 
 * @brief       API for Baseband rc hoping mode.
 * @param[mode]   FULL_BAND_HOPING,RANDOM_HOPING, SELECTION_BAND_HOPING,3 types hoping mode
 */
void  BB_rc_hope_mode_set(ENUM_RC_HOPE_PATTEN_MODE mode);


/** 
 * @brief       API for set the encoder bitrate Unit:Mbps
 * @param[in]   bitrate_Mbps: select the bitrate unit: Mbps
 * @retval      TURE:  success to add command
 * @retval      FALSE, Fail to add command
 */
void BB_uart10_spi_sel(uint32_t sel_dat);

/** 
 * @brief       
 * @param   
 * @retval      
 * @note      
 */
int BB_GetDevInfo(void);

/** 
 * @brief       
 * @param   
 * @retval      
 * @note      
 */


void BB_grd_notify_rc_skip_freq(uint8_t *u8_rcfrq);

uint8_t BB_get_bitrateByMcs(ENUM_CH_BW bw, uint8_t u8_mcs);

int BB_InsertCmd(uint8_t type, STRU_WIRELESS_CONFIG_CHANGE *p);

int BB_GetRcId(uint8_t *pu8_rcId, uint8_t bufsize);

/** 
 * @brief       get rc rate
 * @param       none
 * @retval      1: BPSK 1/2, uart max 32bytes
 *              2: QPSK 2/3, uart max 208bytes
 *              0: unknow qam/code_rate
 * @note        None
 */
uint32_t BB_GetRcRate(ENUM_BB_MODE en_mode);

int BB_NormalModePcRwReg(void *p);

int BB_SetTargetPower(uint8_t u8_2g_power,uint8_t u8_5g_power);
int BB_SetTargetPowerWorkMode(ENUM_RF_POWER_WORK_MODE e_power_work_mode);
void BB_set_power(ENUM_RF_BAND band,uint8_t power);


uint8_t BB_get_band_power(ENUM_RF_BAND band);

void BB_SetPowerCloseMode(ENUM_RF_BAND band);

void BB_SetPowerOpenMode(ENUM_RF_BAND band);

void sky_startSweep(ENUM_RF_BAND band);

void sky_SweepProcess(void);

//void sky_requestRfBandSwitch(ENUM_RF_BAND e_band);
void BB_Register_lna(pfun open_lna_function, pfun bypass_lna_function);
void BB_open_lna(void);
void BB_bypass_lna(void);
void BB_Lna_AddAgc(uint8_t agca, uint8_t agcb);
void BB_Lna_reset(void);
ENUM_LNA_STATUS BB_Lna_isNeedSwitch(ENUM_RF_BAND band);
uint8_t BB_RssiOffset(uint8_t rssi);
uint32_t crc32(const char* s, int len);
uint16_t crc16(const char *buf, int len);
void BB_GenHashId(uint8_t *rcid, uint8_t *vtid,ENUM_BB_MODE en_mode);
void BB_WriteRcPatten(uint8_t patten);
//uint8_t BB_ReadRcPatten(void);
//uint8_t BB_RcPattenMap(uint8_t patten,uint8_t rc_ch);
//uint8_t BB_RcPattenUnMap(uint8_t patten,uint8_t rc_ch);
void BB_Enable_RcRandomSkipPatten(void);
void BB_Register_fem_cb(pfun_fem fem_cb_open,pfun_fem fem_cb_close);
void BB_fem_open(uint8_t ch);
void BB_fem_close(uint8_t ch);
void BB_config_uplink_qam_mode(uint8_t val);
void BB_Register_freq2g5g_switch(pfun open_2g_function, pfun open_5g_function);
void rc_update_working_patten(void);
void rc_set_unlock_patten(uint8_t chg_bw);
void bb_get_rc_channel();
void bb_update_rc_patten_size();
void sky_notify_grd_goto_unlock_patten();
// uint8_t dec2bit_index(uint8_t d);
signed char int2char(int data);
void sky_setRcpatten(uint8_t *msg);
void GetSweepCh_normalsweep(uint8_t u8_bandidx, uint8_t u8_ch,signed char data,ENUM_BB_MODE mode);
void GetSweepCh_finesweep(uint8_t u8_bandidx, uint8_t u8_ch,signed char data);
void CalcAverageSweepPower(uint8_t ch);
void begin_lock_sweep_noise_for_selection();
void end_lock_sweep_noise_for_selection();
void reset_sweep_table(ENUM_RF_BAND cur_band);


#endif

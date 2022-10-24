#ifndef __FACTORY_SETTING_H
#define __FACTORY_SETTING_H

#include "bb_types.h"
#include "cfg_parser.h"
#include "hal_uart.h"

#ifdef __cplusplus
extern "C"
{
#endif


#define     MAX_FCT_NODE    (32)
typedef struct
{
    uint32_t    nodecnt;
    uint32_t    nodeid[MAX_FCT_NODE];
    uint32_t    offset_to_fct_node[MAX_FCT_NODE];
} STRU_NODE_LIST;

#define     MAX_CH_COUNT        (40)

typedef struct
{
    uint32_t                        u32_rfChCount;                  //valid channel count
    int16_t                         u16_rfChFrqList  [MAX_CH_COUNT];     //channel frq(MHz)
} STRU_RF_CHANNEL;


typedef struct
{
    uint32_t                        u32_band0DistZero;
    uint32_t                        u32_band1DistZero;
} STRU_DIST_ZERO;


typedef struct
{
    uint8_t u8_centralGain;//BB 
    uint16_t u16_regPwr;
    uint16_t real_power;
} STRU_BB_POWER_CLOSE_MEAS_VALUE;

typedef struct
{
    uint16_t freq;
    uint16_t real_power;//power 19.5,you should input 195
}STRU_OPEN_POWER_MEAS_VALUE;

#define MAX_OPEN_POWER_REF_VALUE (10)
typedef struct
{
    uint8_t u8_powerOpenMakeupEnable;
    uint8_t u8_bbPwr[2];            //pathA: u8_bbPwr[0]  pathB: u8_bbPwr[1]
    uint8_t u8_2p4g_rfPwr[2]; //2a/2e
    uint8_t u8_5p8g_rfPwr[2]; //66/67
    uint8_t u8_2p4g_ref_power;
    uint8_t u8_5p8g_ref_power;
    uint8_t u8_2p4g_ref_point_num_a;
    STRU_OPEN_POWER_MEAS_VALUE st_2p4g_real_power_value_a[MAX_OPEN_POWER_REF_VALUE];
    uint8_t u8_2p4g_ref_point_num_b;
    STRU_OPEN_POWER_MEAS_VALUE st_2p4g_real_power_value_b[MAX_OPEN_POWER_REF_VALUE];
    uint8_t u8_5p8g_ref_point_num_a;
    STRU_OPEN_POWER_MEAS_VALUE st_5p8g_real_power_value_a[MAX_OPEN_POWER_REF_VALUE];
    uint8_t u8_5p8g_ref_point_num_b;
    STRU_OPEN_POWER_MEAS_VALUE st_5p8g_real_power_value_b[MAX_OPEN_POWER_REF_VALUE];    
} STRU_BB_CH_OPEN_POWER_REF_VALUE;


typedef struct
{
    uint16_t u16_2g_ref_frq;
    STRU_BB_POWER_CLOSE_MEAS_VALUE st_2g_chPowerClose[40]; //for power setting 0~30dbm
    uint16_t u16_5g_ref_frq;
    STRU_BB_POWER_CLOSE_MEAS_VALUE st_5g_chPowerClose[40]; //for power setting 0~30dbm
} STRU_BB_POWER_CLOSE;


typedef struct
{
    ENUM_RF_BAND                 e_bandsupport;
    uint8_t                      u8_bbStartMcs10M;
    uint8_t                      u8_bbStartMcs20M;
    ENUM_CH_BW                   e_bandwidth;
    ENUM_RUN_MODE                e_rfbandMode;
    uint8_t                      bypass_ch_mode;
    ENUM_BAND_MODE               frq_band_mode;
    uint8_t                      rsv[1];
} STRU_RF_BAND_MCS_OPT;


typedef struct
{
    ENUM_MIMO_MODE st_skyMimoMode;
    ENUM_MIMO_MODE st_grdMimoMode;
    ENUM_LNA_MODE  enum_lna_mode;
    uint8_t spi_num;
}STRU_MIMO_MODE;

typedef struct
{
       ENUM_HAL_UART_BAUDR st_uartBaudr[4];
} STRU_UART_BAUDR;


typedef struct
{
    //AES
    STRU_cfgNode                    st_aesNode;
    STRU_BB_AES                     st_aesData;                                 //AES: must enable

    //RF power setting
    STRU_cfgNode                    st_rfPowerNode;
    STRU_RF_POWER_CTRL              st_rfPowerData;

    //rc & 10M vt channel, max 40 channel
    STRU_cfgNode                    st_band0_rcChNode;      //2.4G or 600 ~ 800MHz rc channel setting for 10M 20M
    STRU_RF_CHANNEL                 st_band0_rcChData;

    STRU_cfgNode                    st_band1_10M_rcChNode;  //5.8G rc channel setting for 10M 20M
    STRU_RF_CHANNEL                 st_band1_10M_rcChData;

    STRU_cfgNode                    st_band0_10M_vtChNode;  //2.4G 10M vt channel setting
    STRU_RF_CHANNEL                 st_band0_10M_vtChData;

    STRU_cfgNode                    st_band1_10M_vtChNode;  //5.8G 10M it channel setting
    STRU_RF_CHANNEL                 st_band1_10M_vtChData;    

    //20M vt channel
    STRU_cfgNode                    st_band0_20M_vtChNode;  //2.4G 20M vt channel setting
    STRU_RF_CHANNEL                 st_band0_20M_vtChData;

    STRU_cfgNode                    st_band1_20M_vtChNode;  //5.8G 20M vt channel setting
    STRU_RF_CHANNEL                 st_band1_20M_vtChData;

    //agc switch
    STRU_cfgNode                    st_agcSetNode;
    STRU_AGC_SET                    st_agcSetData; 

    //open power
    STRU_cfgNode                    st_powerOpen_vtNode;
    STRU_BB_CH_OPEN_POWER_REF_VALUE             st_powerOpen_vtData;

    STRU_cfgNode                    st_powerOpen_rcNode;
    STRU_BB_CH_OPEN_POWER_REF_VALUE             st_powerOpen_rcData;

    //close power
    STRU_cfgNode                    st_powerClose_vtNode;
    STRU_BB_POWER_CLOSE                st_powerClose_vtData;

    STRU_cfgNode                    st_powerClose_rcNode;
    STRU_BB_POWER_CLOSE             st_powerClose_rcData;
    
    //pwr ctrl
    STRU_cfgNode                    st_pwrCtrlNode;
    STRU_PWR_CTRL                   st_pwrCtrlData; 

    //band Mcs option
    STRU_cfgNode                    st_rfBandMcsNode;
    STRU_RF_BAND_MCS_OPT            st_rfBandMcsData;
    
    STRU_cfgNode                    st_mimoModeNode;
    STRU_MIMO_MODE                  st_mimoModeData;

	STRU_cfgNode                    st_uartBaundNode;
	STRU_UART_BAUDR                 st_uartBaudData;
} STRU_FACTORY_SETTING_DATA;


typedef struct
{
    STRU_cfgNode                    st_factoryNode;
    STRU_FACTORY_SETTING_DATA       st_factorySetting;
} STRU_FACTORY_SETTING;

/*
 * return < 0, Fail
*/
int FCT_Load2Sram(void);

/*
 * return 0
*/
int FCT_Save2Flash(STRU_FACTORY_SETTING * fct);

int FCT_CopySetting(void *pdata, uint32_t size);

void FCT_SaveToFlashTest(void);

void * FCT_GetNodeAndData(uint32_t u32_nodeId, STRU_cfgNode **pp_node);

void FCT_Reset(void);

#ifdef __cplusplus
}
#endif

#endif

#include "bb_types.h"
#include "boardParameters.h"
#include "cfg_parser.h"
#include "factory.h"
#include "hal_uart.h"
#include <string.h>

// 禾启 天8227D  地 8227D

////////////////////////////////////////////////
extern STRU_BOARD_BB_PARA stru_TEST8003_bb_boardCfg;

STRU_cfgNode TEST8003_bbcfg_nodeInfo = {
    .nodeId       = BB_BOARDCFG_PARA_ID,
    .nodeElemCnt  = 1,
    .nodeDataSize = sizeof(stru_TEST8003_bb_boardCfg)
};

STRU_BOARD_BB_PARA stru_TEST8003_bb_boardCfg __attribute__((aligned(4))) = {
    .u8_bbSkyRegsCnt = 3,

    .u8_bbGrdRegsCnt = 3,

    // after calibration
    .u8_bbSkyRegsCntAfterCali = 2,

    .u8_bbGrdRegsCntAfterCali = 3,
};

extern STRU_BB_REG stru_TEST8003_bb_reg[11];

STRU_cfgNode TEST8003_bbdata_nodeInfo = {
    .nodeId       = BB_BOARDCFG_DATA_ID,
    .nodeElemCnt  = 11,
    .nodeDataSize = sizeof(stru_TEST8003_bb_reg)
};

STRU_BB_REG stru_TEST8003_bb_reg[11] __attribute__((aligned(4))) = {
    { 1, 0x09, 0x85 },
    { 1, 0x0a, 0x85 },
    { 2, 0x21, 0x20 },

    { 1, 0x09, 0x85 },
    { 1, 0x0a, 0x85 },
    { 2, 0x21, 0x20 }, // default 8003s -> 8003

    // ek2T2R_bb_skyregsAfterCali
    { 1, 0x90, 0xFF }, // for 2TX
    { 1, 0x91, 0x78 }, // 2RX

    // ek2T2R_bb_grdregsAfterCali
    { 1, 0x90, 0xF7 }, // turn off DAC_B for 1TX
    { 1, 0x91, 0x78 }, // 2RX
    { 1, 0x80, 0x50 }, // change grd auto reset time
};

////////////////////////////////////////////////

extern STRU_BOARD_RF_PARA stru_TEST8003_rf_boardCfg;

STRU_cfgNode TEST8003_rfcfg_nodeInfo = {
    .nodeId       = RF_BOARDCFG_PARA_ID,
    .nodeElemCnt  = 1,
    .nodeDataSize = sizeof(stru_TEST8003_rf_boardCfg)
};

STRU_BOARD_RF_PARA stru_TEST8003_rf_boardCfg __attribute__((aligned(4))) = {
    .u8_rfCnt = 1,

    .u8_rf0SkyRegsCnt = 4,

    .u8_rf0GrdRegsCnt = 4,

    .u8_rf1GrdRegsCnt = 0,

    // after calibration

    .u8_rf0SkyRegsCntAfterCali = 1,

    .u8_rf0GrdRegsCntAfterCali = 4,

    .u8_rf1GrdRegsCntAfterCali = 0,

    .boardCfgName = "HEQ_V1",
};

extern STRU_RF_REG TEST8003_rf_boardReg[13];

STRU_cfgNode TEST8003_nodeInfo = {
    .nodeId       = RF_BOARDCFG_DATA_ID,
    .nodeElemCnt  = 13,
    .nodeDataSize = sizeof(TEST8003_rf_boardReg)
};

STRU_RF_REG TEST8003_rf_boardReg[13] __attribute__((aligned(4))) = {
    // pstru_rf1SkyRegs
    { 0, 0x01, 0x00 },
    { 0, 0x04, 0x00 },
    { 0, 0x05, 0x02 },
    { 0, 0x06, 0x00 },

    // pstru_rf2SkyRegs

    // pstru_rf1GrdRegs
    { 0, 0x01, 0x00 },
    { 0, 0x04, 0x00 },
    { 0, 0x05, 0x02 },
    { 0, 0x06, 0x00 },

    // pstru_rf2GrdRegs

    // ek2T2R_rf1_skyregs_afterCali
    { 0, 0x35, 0x70 },

    // ek2T2R_rf1_grdregs_afterCali
    { 0, 0x35, 0x70 },
    { 0, 0x00, 0x74 }, // 1Tx only
    { 0, 0x2D, 0xF6 },
    { 0, 0x37, 0xE0 },
};
extern STRU_BB_LAN_AUTO stru_TEST8003_bb_lna_boardCfg;

STRU_cfgNode TEST8003_bb_lna_cfg_nodeInfo = {
    .nodeId       = BB_LNA_AUTO_CFG_ID,
    .nodeElemCnt  = 1,
    .nodeDataSize = sizeof(stru_TEST8003_bb_lna_boardCfg)
};

STRU_BB_LAN_AUTO stru_TEST8003_bb_lna_boardCfg __attribute__((aligned(4))) = {
    .u16_avgCnt    = 1000, // max value 1000
    .u8_2g_agcThdL = 40,   // < u8_agcThdL , LNA bypass
    .u8_2g_agcThdH = 45,   // > u8_agcThdH, LNA open
    .u8_5g_agcThdL = 34,   // < u8_agcThdL , LNA bypass
    .u8_5g_agcThdH = 39,   // > u8_agcThdH, LNA open
    .u8_2g_lna     = 20,   // lna gain (dbm)
    .u8_5g_lna     = 20,   // lna gain (dbm)
};

extern STRU_BOARD_RF_BW_CHG stru_rf_bw_chg__boardCfg;

STRU_cfgNode rf_bw_chg_nodeInfo = {
    .nodeId       = BB_BW_AUTO_CHG_ID,
    .nodeElemCnt  = 1,
    .nodeDataSize = sizeof(stru_rf_bw_chg__boardCfg)
};

STRU_BOARD_RF_BW_CHG stru_rf_bw_chg__boardCfg __attribute__((aligned(4))) = {
    .en_auto               = 0,  // enbale
    .thd_10                = 78, // > u8_agcThdL, select_10MHz
    .thd_20                = 73, // < u8_agcThdH, select_20MHz
    .en_it_hoping_quickly  = 1,
    .max_rc_len            = 6,
    .sweep_noise_thd       = 5,
    .sweep_patten_size     = 4,
    .rc_fine_sweep_size    = 8,
    .it_fine_sweep_size    = 4,
    .rc_common_ch_size     = 4,
    .rc_common_ch          = { 0, 4, 30, 37 },
    .it_unlock_timeout_cnt = 64,
    .rc_unlock_timeout_cnt = 64,
    .rc_sweep_log_open     = 0,

};

extern STRU_BB_AOC stru_TEST8003_bb_aoc_boardCfg;

STRU_cfgNode TEST8003_bb_aoc_cfg_nodeInfo = {
    .nodeId       = BB_AOC_BOARDCFG_ID,
    .nodeElemCnt  = 1,
    .nodeDataSize = sizeof(stru_TEST8003_bb_aoc_boardCfg)
};

STRU_BB_AOC stru_TEST8003_bb_aoc_boardCfg __attribute__((aligned(4))) = {
    // 10*lg10(x/64)
    // 13dbm->0x4fc,14dbm->0x647,15dbm->0x7e7,16dbm->0x9f3
    // 17dbm->0xc87,18dbm->0xfc6,19dbm->0x13db,20db->0x1900,
    // 21->0x1f79,22dbm->0x279F
    .u16_snrThdL     = 0x7e7, //
    .u16_snrThdH     = 0xc87, //
    .u8_agcThdL      = 60,    //
    .u8_agcThdH      = 70,    //
    .u8_PwrThdMin    = 15,    // min adjust power 15dbm
    .u8_snrAvgCnt    = 16,    // snr average num, MAX Average Count value is 64
    .u8_agcAvgCnt    = 64,    // rssi average num,MAX Average Count value is 128
    .u16_ldpcStacCnt = 100,   // statistics ldpc err count
    .u16_ldpcThd     = 50,    // ldpc err threshold
};

STRU_cfgNode stru_TEST8003_sky_band_switch_nodeInfo = {
    .nodeId       = RF_SKY_BAND_SWITCH_CFG_ID,
    .nodeElemCnt  = 0,
    .nodeDataSize = 0
};

STRU_cfgNode stru_TEST8003_grd_band_switch_nodeInfo = {
    .nodeId       = RF_GRD_BAND_SWITCH_CFG_ID,
    .nodeElemCnt  = 0,
    .nodeDataSize = 0
};

extern STRU_BB_RC_CH_SELECTION RF8003_rc_selection;

STRU_cfgNode RF8003_Rc_selection_nodeInfo = {
    .nodeId       = BB_RC_CH_SELECTION,
    .nodeElemCnt  = 1,
    .nodeDataSize = sizeof(RF8003_rc_selection)
};

STRU_BB_RC_CH_SELECTION RF8003_rc_selection = {
    .u8_rcChSelectionEnable = 1,
    .u8_rcChReplaceMaxCnt   = 9, // suggest no more than 1/2 * (RC channel)
    .u16_rcChReplaceCycles  = 1000
};

STRU_FACTORY_SETTING st_Factory_TEST8003_2t2r_cfg __attribute__((aligned(4))) = {
    // FACTORY_SETTING NODE
    .st_factoryNode = {
        .nodeId       = FACTORY_SETTING_NODE_ID,
        .nodeElemCnt  = 1,
        .nodeDataSize = sizeof(STRU_FACTORY_SETTING_DATA) },

    // FACTORY_SETTING DATA
    .st_factorySetting = {
        // AES node and data
        .st_aesNode = { .nodeId = FACTORY_SUBNODE_BB_AES_CFG_NODE_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_BB_AES) },

        .st_aesData = {
            .u8_upLinkSwitch   = 1,
            .u8_downLinkSwitch = 1,

            .u8_upLinkKeyArray   = { 0x5B, 0xA1, 0x23, 0x70, 0x69, 0x07, 0x7E, 0xAF, 0x4D, 0xD9, 0x8C, 0x77, 0x0E, 0x2A, 0x38, 0xCB, 0xB6, 0x54, 0x85, 0x31, 0xBD, 0x46, 0x3F, 0xE0, 0xA8, 0x1C, 0x15, 0x9A, 0xC4, 0x93, 0xD2, 0x62 },
            .u8_downLinkKeyArray = { 0x5B, 0xA1, 0x23, 0x70, 0x69, 0x07, 0x7E, 0xAF, 0x4D, 0xD9, 0x8C, 0x77, 0x0E, 0x2A, 0x38, 0xCB, 0xB6, 0x54, 0x85, 0x31, 0xBD, 0x46, 0x3F, 0xE0, 0xA8, 0x1C, 0x15, 0x9A, 0xC4, 0x93, 0xD2, 0x62 },
        },

        // RF power node and data
        .st_rfPowerNode = { .nodeId = FACTORY_SUBNODE_POWER_NODE_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_POWER_CTRL) },

        .st_rfPowerData = {
            .mode             = RF_POWER_CLOSE,
            .powerAutoCtrl    = 0,
            .tssi_update_time = 2, // 0:14ms, 1:112ms, 2:896ms, 3:7S
            .power_work_mode  = SRRC,

            // 2.4G, 5.8G
            .vtPowerFcc   = { 25, 20 },
            .vtPowerCe    = { 14, 14 },
            .vtPowerSrrc  = { 15, 15 },
            .vtPowerOther = { 22, 22 },

            // 2.4G, 5.8G
            .rcPowerFcc   = { 27, 20 },
            .rcPowerCe    = { 14, 14 },
            .rcPowerSrrc  = { 15, 15 },
            .rcPowerOther = { 22, 22 },
        },

        /////////////////////////////////////////////////
        // 2.4G 10M rc channel, max 40 channel
        .st_band0_rcChNode = { .nodeId = FACTORY_SUBNODE_BAND0_RC_10M_FRQ_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_CHANNEL) },

        .st_band0_rcChData = {
            .u32_rfChCount   = 20,
            .u16_rfChFrqList = {
                2423,
                2425,
                2427,
                2429,
                2431,
                2433,
                2435,
                2437,
                2439,
                2441,
                2443,
                2445,
                2447,
                2449,
                2451,
                2453,
                2455,
                2457,
                2459,
                2461,
            },

        },
        // .st_band0_rcChData =
        // {
        // 	.u32_rfChCount              =  40,
        // 	.u16_rfChFrqList            =  {
        // 		2300, 2310, 2320, 2330, 2340, 2350, 2360, 2370, 2380, 2390,
        // 		2400, 2410, 2420, 2430, 2440, 2450, 2460, 2470, 2480, 2490,
        // 		2500, 2510, 2520, 2530, 2540, 2550, 2560, 2570, 2580, 2590,
        // 		2600, 2610, 2620, 2630, 2640, 2650, 2660, 2670, 2680, 2690
        // 	},

        // },

        // 5.8G 10M rc channel, max 40 channel
        .st_band1_10M_rcChNode = { .nodeId = FACTORY_SUBNODE_BAND1_RC_10M_FRQ_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_CHANNEL) },

        .st_band1_10M_rcChData = {},

        // 2.4G 10M vt channel, max 40 channel
        .st_band0_10M_vtChNode = { .nodeId = FACTORY_SUBNODE_BAND0_VT_10M_FRQ_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_CHANNEL) },

        // .st_band0_10M_vtChData =
        // {
        // 	.u32_rfChCount              = 40,
        // 	.u16_rfChFrqList            = {
        // 		2300, 2310, 2320, 2330, 2340, 2350, 2360, 2370, 2380, 2390,
        // 		2400, 2410, 2420, 2430, 2440, 2450, 2460, 2470, 2480, 2490,
        // 		2500, 2510, 2520, 2530, 2540, 2550, 2560, 2570, 2580, 2590,
        // 		2600, 2610, 2620, 2630, 2640, 2650, 2660, 2670, 2680, 2690
        // 	},
        // },

        .st_band0_10M_vtChData = {
            .u32_rfChCount   = 20,
            .u16_rfChFrqList = {
                2423,
                2425,
                2427,
                2429,
                2431,
                2433,
                2435,
                2437,
                2439,
                2441,
                2443,
                2445,
                2447,
                2449,
                2451,
                2453,
                2455,
                2457,
                2459,
                2461,
            },
        },

        // 5.8G 10M vt channel, max 40 channel
        .st_band1_10M_vtChNode = { .nodeId = FACTORY_SUBNODE_BAND1_VT_10M_FRQ_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_CHANNEL) },

        .st_band1_10M_vtChData = {},

        /////////////////////////////////////////////////
        // 20MHz
        // 2.4G 20M vt channel, max 40 channel
        .st_band0_20M_vtChNode = { .nodeId = FACTORY_SUBNODE_BAND0_VT_20M_FRQ_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_CHANNEL) },

        .st_band0_20M_vtChData = {
            .u32_rfChCount   = 20,
            .u16_rfChFrqList = {
                2423,
                2425,
                2427,
                2429,
                2431,
                2433,
                2435,
                2437,
                2439,
                2441,
                2443,
                2445,
                2447,
                2449,
                2451,
                2453,
                2455,
                2457,
                2459,
                2461,
            },
        },

        // 5.8G 20M vt channel, max 40 channel
        .st_band1_20M_vtChNode = { .nodeId = FACTORY_SUBNODE_BAND1_VT_20M_FRQ_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_CHANNEL) },

        .st_band1_20M_vtChData = {},

        // agc set
        .st_agcSetNode = { .nodeId = FACTORY_SUBNODE_AGC_SET, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_AGC_SET) },

        .st_agcSetData = {
            .e_gear             = AGC_GEAR_2,
            .u8_agcSwitchThresh = 0x4B,
        },

        // vt open power makeup value
        .st_powerOpen_vtNode = { .nodeId = FACTORY_SUBNODE_POWEROPEN_VT_SET_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_BB_CH_OPEN_POWER_REF_VALUE) },

        .st_powerOpen_vtData = {
            .u8_powerOpenMakeupEnable   = 0,
            .u8_bbPwr                   = { 0x30, 0x30 },
            .u8_2p4g_rfPwr              = { 0x0A, 0x0A },
            .u8_5p8g_rfPwr              = { 0x08, 0x08 },
            .u8_2p4g_ref_power          = 22,
            .u8_5p8g_ref_power          = 22,
            .u8_2p4g_ref_point_num_a    = 2,
            .st_2p4g_real_power_value_a = { { .freq = 2406, .real_power = 199 }, { .freq = 2470, .real_power = 192 } },
            .u8_2p4g_ref_point_num_b    = 2,
            .st_2p4g_real_power_value_b = { { .freq = 2406, .real_power = 205 }, { .freq = 2470, .real_power = 197 } },
            .u8_5p8g_ref_point_num_a    = 4,
            .st_5p8g_real_power_value_a = { { .freq = 5740, .real_power = 161 }, { .freq = 5756, .real_power = 155 }, { .freq = 5764, .real_power = 177 }, { .freq = 5828, .real_power = 155 } },
            .u8_5p8g_ref_point_num_b    = 4,
            .st_5p8g_real_power_value_b = { { .freq = 5740, .real_power = 165 }, { .freq = 5756, .real_power = 143 }, { .freq = 5764, .real_power = 165 }, { .freq = 5828, .real_power = 142 } },
        },

        // rc open power makeup value
        .st_powerOpen_rcNode = { .nodeId = FACTORY_SUBNODE_POWEROPEN_RC_SET_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_BB_CH_OPEN_POWER_REF_VALUE) },

        .st_powerOpen_rcData = {
            .u8_powerOpenMakeupEnable = 0,
            .u8_bbPwr                 = { 0x30, 0x00 },

            .u8_2p4g_rfPwr = { 0x0A, 0x0A },
            .u8_5p8g_rfPwr = { 0x08, 0x08 },

            .u8_2p4g_ref_power          = 22,
            .u8_5p8g_ref_power          = 22,
            .u8_2p4g_ref_point_num_a    = 2,
            .st_2p4g_real_power_value_a = { { .freq = 2405, .real_power = 184 }, { .freq = 2475, .real_power = 177 } },
            .u8_2p4g_ref_point_num_b    = 0,
            .u8_5p8g_ref_point_num_a    = 4,
            .st_5p8g_real_power_value_a = { { .freq = 5731, .real_power = 207 }, { .freq = 5759, .real_power = 198 }, { .freq = 5761, .real_power = 216 }, { .freq = 5801, .real_power = 206 } },
            .u8_5p8g_ref_point_num_b    = 0,
        },

        // vt close power makeup value
        .st_powerClose_vtNode = { .nodeId = FACTORY_SUBNODE_POWERCLOSE_VT_SET_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_BB_POWER_CLOSE) },

        .st_powerClose_vtData = {
            .u16_2g_ref_frq     = 2406,
            .st_2g_chPowerClose = {
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1900, .real_power = 200 }, // 0dbm
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1a00, .real_power = 200 }, // 1
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1b00, .real_power = 200 }, // 2
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1c00, .real_power = 200 }, // 3
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1d00, .real_power = 200 }, // 4
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2000, .real_power = 200 }, // 5
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2100, .real_power = 200 }, // 6
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2400, .real_power = 200 }, // 7
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2500, .real_power = 200 }, // 8
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2800, .real_power = 200 }, // 9
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2a00, .real_power = 200 }, // 10
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2d00, .real_power = 200 }, // 11
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2f00, .real_power = 200 }, // 12
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3200, .real_power = 200 }, // 13
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3500, .real_power = 200 }, // 14
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3700, .real_power = 150 }, // 15
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x3a00, .real_power = 158 }, // 16
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x3d00, .real_power = 200 }, // 17
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x3f00, .real_power = 200 }, // 18
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4200, .real_power = 200 }, // 19
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4500, .real_power = 200 }, // 20
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4700, .real_power = 200 }, // 21
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4a00, .real_power = 200 }, // 22
                { .u8_centralGain = 0x08, .u16_regPwr = 0x4d00, .real_power = 200 }, // 23
                { .u8_centralGain = 0x08, .u16_regPwr = 0x4f00, .real_power = 200 }, // 24
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5300, .real_power = 200 }, // 25
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5700, .real_power = 200 }, // 26
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5900, .real_power = 200 }, // 27
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5B00, .real_power = 200 }, // 28
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5F00, .real_power = 200 }, // 29
                { .u8_centralGain = 0x08, .u16_regPwr = 0x6700, .real_power = 200 }  /// 30
            },
        },

        // rc close power makeup value
        .st_powerClose_rcNode = { .nodeId = FACTORY_SUBNODE_POWERCLOSE_RC_SET_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_BB_POWER_CLOSE) },

        .st_powerClose_rcData = {
            .u16_2g_ref_frq     = 2405,
            .st_2g_chPowerClose = {
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x0000, .real_power = 200 }, // 0dbm
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x0400, .real_power = 200 }, // 1
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x0700, .real_power = 200 }, // 2
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x0a00, .real_power = 200 }, // 3
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x0d00, .real_power = 200 }, // 4
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1000, .real_power = 200 }, // 5
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x1200, .real_power = 200 }, // 6
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2000, .real_power = 200 }, // 7
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2200, .real_power = 200 }, // 8
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2400, .real_power = 200 }, // 9
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2700, .real_power = 200 }, // 10
                { .u8_centralGain = 0x1a, .u16_regPwr = 0x2900, .real_power = 200 }, // 11
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2C00, .real_power = 200 }, // 12
                { .u8_centralGain = 0x12, .u16_regPwr = 0x2F00, .real_power = 200 }, // 13
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3200, .real_power = 200 }, // 14
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3500, .real_power = 150 }, // 15
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3700, .real_power = 158 }, // 16
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3a00, .real_power = 200 }, // 17
                { .u8_centralGain = 0x12, .u16_regPwr = 0x3d00, .real_power = 200 }, // 18
                { .u8_centralGain = 0x12, .u16_regPwr = 0x4000, .real_power = 200 }, // 19
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4200, .real_power = 200 }, // 20
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4500, .real_power = 200 }, // 21
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4800, .real_power = 200 }, // 22
                { .u8_centralGain = 0x0a, .u16_regPwr = 0x4c00, .real_power = 200 }, // 23
                { .u8_centralGain = 0x08, .u16_regPwr = 0x4e00, .real_power = 200 }, // 24
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5100, .real_power = 200 }, // 25
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5500, .real_power = 200 }, // 26
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5a00, .real_power = 200 }, // 27
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5d00, .real_power = 200 }, // 28
                { .u8_centralGain = 0x08, .u16_regPwr = 0x5f00, .real_power = 200 }, // 29
                { .u8_centralGain = 0x08, .u16_regPwr = 0x6400, .real_power = 200 }  /// 30
            },
        },

        // pwr ctrl
        .st_pwrCtrlNode = { .nodeId = FACTORY_SUBNODE_PWR_CTRL, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_PWR_CTRL) },

        .st_pwrCtrlData = {
            .mod_status_update_time   = 100,
            .mod_status_update_enable = 1,
            .pwr_ctrl                 = PWR_LEVEL0,
        },

        //
        .st_rfBandMcsNode = { .nodeId = FACTORY_SUBNODE_BAND_MCS_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_RF_BAND_MCS_OPT) },

        .st_rfBandMcsData = {
            .e_bandsupport    = RF_2G,
            .u8_bbStartMcs10M = 0,
            .u8_bbStartMcs20M = 0,
            .e_rfbandMode     = AUTO, // 0
            .e_bandwidth      = BW_10M,
            .bypass_ch_mode   = 1, // 1. UART->UART,   5. UART->USB
            .frq_band_mode    = FULL_BAND,

        },

        .st_mimoModeNode = { .nodeId = FACTORY_SUBNODE_MIMO_MODE_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_MIMO_MODE) },

        .st_mimoModeData = {
            .st_skyMimoMode = MIMO_2T2R,
            .st_grdMimoMode = MIMO_1T2R,
            .enum_lna_mode  = LNA_OPEN,
            .spi_num        = 25,
        },

        .st_uartBaundNode = { .nodeId = FACTORY_SUBNODE_UART_BAUDR_ID, .nodeElemCnt = 1, .nodeDataSize = sizeof(STRU_UART_BAUDR) },

        .st_uartBaudData = {
            .st_uartBaudr = { HAL_UART_BAUDR_115200, HAL_UART_BAUDR_57600, HAL_UART_BAUDR_115200, HAL_UART_BAUDR_115200 },
        },

    },
};

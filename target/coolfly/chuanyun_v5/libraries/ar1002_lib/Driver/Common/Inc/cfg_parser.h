#ifndef _CONFIG_BIN_H_
#define _CONFIG_BIN_H_

#include <stdint.h>


//HDMI
#define HDMI_EDID_CFG_ID                                (0)


//Baseband

#define RF_INIT_REG_NODE_ID_0                           (3)
#define RF_INIT_REG_NODE_ID_1                           (4)


#define RF_SKY_INIT_REG_ID_0                            (5)
#define RF_GRD_INIT_REG_ID_0                            (6)




//board config
#define BB_BOARDCFG_PARA_ID                             (17)
#define BB_BOARDCFG_DATA_ID                             (18)

#define RF_BOARDCFG_PARA_ID                             (19)
#define RF_BOARDCFG_DATA_ID                             (20)


#define VSOC_ENC_INIT_ID                                (21)
#define VSOC_ENC_VIEW_ID_0                              (22)
#define VSOC_ENC_VIEW_ID_1                              (23)

#define BB_AOC_BOARDCFG_ID                              (24)

#define BB_SKY_SWEEP_FRQ_CFG_ID                         (25)

#define BB_RC_CH_SELECTION                              (26)

#define RF_SKY_BAND_SWITCH_CFG_ID                       (27)

#define RF_GRD_BAND_SWITCH_CFG_ID                       (28)

#define BB_LNA_AUTO_CFG_ID                              (29)

#define BB_BW_AUTO_CHG_ID                               (30)


//////Factory setting node id
#define FACTORY_NODE_ID_MASK                            (0xa5000000)
#define FACTORY_SETTING_NODE_ID                         (0x1b | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_POWER_NODE_ID                   (0x1c | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_RC_MODE_NODE_ID                 (0x1e | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND0_10M_RC_NODE_ID            (0x1f | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND1_10M_RC_NODE_ID            (0x20 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND0_10M_VT_NODE_ID            (0x21 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND1_10M_VT_NODE_ID            (0x22 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_DIST_ZERO_NODE_ID               (0x23 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND0_20M_RC_NODE_ID            (0x24 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND1_20M_RC_NODE_ID            (0x25 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND0_20M_VT_NODE_ID            (0x26 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND1_20M_VT_NODE_ID            (0x27 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BB_AES_CFG_NODE_ID              (0x28 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND0_RC_10M_FRQ_ID             (0x29 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND0_VT_10M_FRQ_ID             (0x30 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND1_RC_10M_FRQ_ID             (0x31 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND1_VT_10M_FRQ_ID             (0x32 | FACTORY_NODE_ID_MASK)


//#define FACTORY_SUBNODE_BAND0_RC_20M_FRQ_ID             (0x33 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND0_VT_20M_FRQ_ID             (0x33 | FACTORY_NODE_ID_MASK)

//#define FACTORY_SUBNODE_BAND1_RC_20M_FRQ_ID             (0x35 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_BAND1_VT_20M_FRQ_ID             (0x36 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_AGC_SET                         (0x37 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_POWEROPEN_VT_SET_ID             (0x38 | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_POWEROPEN_RC_SET_ID             (0x39 | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_POWERCLOSE_VT_SET_ID            (0x3A | FACTORY_NODE_ID_MASK)
#define FACTORY_SUBNODE_POWERCLOSE_RC_SET_ID            (0x3B | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_PWR_CTRL                        (0x3C | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_BAND_MCS_ID                     (0x3D | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_MIMO_MODE_ID                    (0x3E | FACTORY_NODE_ID_MASK)

#define FACTORY_SUBNODE_UART_BAUDR_ID                   (0x3F | FACTORY_NODE_ID_MASK)

#define CFG_DATA_HEAD_FLAG                              (0x3553F708)


typedef struct
{
    uint32_t nodeId;
    uint32_t nodeElemCnt;
    uint32_t nodeDataSize;
}STRU_cfgNode;


typedef struct
{
    uint32_t headflag;      //
    uint32_t version;       //
    uint32_t dataSize;      //sum of the elemSizes
    uint8_t  dataMd5[16];   //
}STRU_cfgBin;


void CFGBIN_LoadFromFlash(uint32_t dstAddr, uint32_t srcAddr);

STRU_cfgNode *CFGBIN_GetNode(STRU_cfgBin *ptr_cfg, uint32_t u32_nodeId);

void * CFGBIN_GetNodeData(STRU_cfgBin *ptr_cfg, uint32_t u32_nodeId);

void * CFGBIN_GetNodeAndData(STRU_cfgBin *ptr_cfg, uint32_t u32_nodeId, STRU_cfgNode **pp_node);

#endif // _CONFIG_BIN_H_

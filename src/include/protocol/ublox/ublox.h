/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef UBLOX_H__
#define UBLOX_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UBX_SYNC1 0xB5
#define UBX_SYNC2 0x62

/* Message Classes */
#define UBX_CLASS_NAV 0x01
#define UBX_CLASS_ACK 0x05
#define UBX_CLASS_CFG 0x06
#define UBX_CLASS_MON 0x0A

/* Message IDs */
#define UBX_ID_NAV_POSLLH  0x02
#define UBX_ID_NAV_DOP     0x04
#define UBX_ID_NAV_SOL     0x06
#define UBX_ID_NAV_PVT     0x07
#define UBX_ID_NAV_VELNED  0x12
#define UBX_ID_NAV_TIMEUTC 0x21
#define UBX_ID_NAV_SVINFO  0x30
#define UBX_ID_ACK_NAK     0x00
#define UBX_ID_ACK_ACK     0x01
#define UBX_ID_CFG_PRT     0x00
#define UBX_ID_CFG_MSG     0x01
#define UBX_ID_CFG_RATE    0x08
#define UBX_ID_CFG_NAV5    0x24
#define UBX_ID_CFG_SBAS    0x16
#define UBX_ID_MON_VER     0x04
#define UBX_ID_MON_HW      0x09

/* Message Classes & IDs */
#define UBX_MSG_NAV_POSLLH  ((UBX_CLASS_NAV) | UBX_ID_NAV_POSLLH << 8)
#define UBX_MSG_NAV_SOL     ((UBX_CLASS_NAV) | UBX_ID_NAV_SOL << 8)
#define UBX_MSG_NAV_DOP     ((UBX_CLASS_NAV) | UBX_ID_NAV_DOP << 8)
#define UBX_MSG_NAV_PVT     ((UBX_CLASS_NAV) | UBX_ID_NAV_PVT << 8)
#define UBX_MSG_NAV_VELNED  ((UBX_CLASS_NAV) | UBX_ID_NAV_VELNED << 8)
#define UBX_MSG_NAV_TIMEUTC ((UBX_CLASS_NAV) | UBX_ID_NAV_TIMEUTC << 8)
#define UBX_MSG_NAV_SVINFO  ((UBX_CLASS_NAV) | UBX_ID_NAV_SVINFO << 8)
#define UBX_MSG_ACK_NAK     ((UBX_CLASS_ACK) | UBX_ID_ACK_NAK << 8)
#define UBX_MSG_ACK_ACK     ((UBX_CLASS_ACK) | UBX_ID_ACK_ACK << 8)
#define UBX_MSG_CFG_PRT     ((UBX_CLASS_CFG) | UBX_ID_CFG_PRT << 8)
#define UBX_MSG_CFG_MSG     ((UBX_CLASS_CFG) | UBX_ID_CFG_MSG << 8)
#define UBX_MSG_CFG_RATE    ((UBX_CLASS_CFG) | UBX_ID_CFG_RATE << 8)
#define UBX_MSG_CFG_NAV5    ((UBX_CLASS_CFG) | UBX_ID_CFG_NAV5 << 8)
#define UBX_MSG_CFG_SBAS    ((UBX_CLASS_CFG) | UBX_ID_CFG_SBAS << 8)
#define UBX_MSG_MON_HW      ((UBX_CLASS_MON) | UBX_ID_MON_HW << 8)
#define UBX_MSG_MON_VER     ((UBX_CLASS_MON) | UBX_ID_MON_VER << 8)

/* RX NAV-PVT message content details */
/*   Bitfield "valid" masks */
#define UBX_RX_NAV_PVT_VALID_VALIDDATE     0x01 /**< validDate (Valid UTC Date) */
#define UBX_RX_NAV_PVT_VALID_VALIDTIME     0x02 /**< validTime (Valid UTC Time) */
#define UBX_RX_NAV_PVT_VALID_FULLYRESOLVED 0x04 /**< fullyResolved (1 = UTC Time of Day has been fully resolved (no seconds uncertainty)) */

/*   Bitfield "flags" masks */
#define UBX_RX_NAV_PVT_FLAGS_GNSSFIXOK    0x01 /**< gnssFixOK (A valid fix (i.e within DOP & accuracy masks)) */
#define UBX_RX_NAV_PVT_FLAGS_DIFFSOLN     0x02 /**< diffSoln (1 if differential corrections were applied) */
#define UBX_RX_NAV_PVT_FLAGS_PSMSTATE     0x1C /**< psmState (Power Save Mode state (see Power Management)) */
#define UBX_RX_NAV_PVT_FLAGS_HEADVEHVALID 0x20 /**< headVehValid (Heading of vehicle is valid) */

/* RX NAV-TIMEUTC message content details */
/*   Bitfield "valid" masks */
#define UBX_RX_NAV_TIMEUTC_VALID_VALIDTOW    0x01 /**< validTOW (1 = Valid Time of Week) */
#define UBX_RX_NAV_TIMEUTC_VALID_VALIDKWN    0x02 /**< validWKN (1 = Valid Week Number) */
#define UBX_RX_NAV_TIMEUTC_VALID_VALIDUTC    0x04 /**< validUTC (1 = Valid UTC Time) */
#define UBX_RX_NAV_TIMEUTC_VALID_UTCSTANDARD 0xF0 /**< utcStandard (0..15 = UTC standard identifier) */

/* TX CFG-PRT message contents */
#define UBX_TX_CFG_PRT_PORTID       0x01       /**< UART1 */
#define UBX_TX_CFG_PRT_MODE         0x000008D0 /**< 0b0000100011010000: 8N1 */
#define UBX_TX_CFG_PRT_BAUDRATE     57600      /**< choose 38400 as GPS baudrate */
#define UBX_TX_CFG_PRT_INPROTOMASK  0x01       /**< UBX in */
#define UBX_TX_CFG_PRT_OUTPROTOMASK 0x01       /**< UBX out */

/* TX CFG-RATE message contents */
#define UBX_TX_CFG_RATE_MEASINTERVAL 100 /**< 100ms for 10Hz */
#define UBX_TX_CFG_RATE_NAVRATE      1   /**< cannot be changed */
#define UBX_TX_CFG_RATE_TIMEREF      0   /**< 0: UTC, 1: GPS time */

/* TX CFG-NAV5 message contents */
#define UBX_TX_CFG_NAV5_MASK     0x0005 /**< Only update dynamic model and fix mode */
#define UBX_TX_CFG_NAV5_DYNMODEL 7      /**< 0 Portable, 2 Stationary, 3 Pedestrian, 4 Automotive, 5 Sea, 6 Airborne <1g, 7 Airborne <2g, 8 Airborne <4g */
#define UBX_TX_CFG_NAV5_FIXMODE  2      /**< 1 2D only, 2 3D only, 3 Auto 2D/3D */

/* TX CFG-SBAS message contents */
#define UBX_TX_CFG_SBAS_MODE_ENABLED  1                             /**< SBAS enabled */
#define UBX_TX_CFG_SBAS_MODE_DISABLED 0                             /**< SBAS disabled */
#define UBX_TX_CFG_SBAS_MODE          UBX_TX_CFG_SBAS_MODE_DISABLED /**< SBAS enabled or disabled */

/* TX CFG-MSG message contents */
#define UBX_TX_CFG_MSG_RATE1_5HZ  0x01 /**< {0x00, 0x01, 0x00, 0x00, 0x00, 0x00} the second entry is for UART1 */
#define UBX_TX_CFG_MSG_RATE1_1HZ  0x05 /**< {0x00, 0x05, 0x00, 0x00, 0x00, 0x00} the second entry is for UART1 */
#define UBX_TX_CFG_MSG_RATE1_05HZ 10

#define UBX_CONFIG_TIMEOUT 100 // ms, timeout for waiting ACK
// #define UBX_CONFIG_TIMEOUT	20		// ms, timeout for waiting ACK

/*** u-blox protocol binary message and payload definitions ***/
#pragma pack(push, 1)

/* General: Header */
typedef struct {
    uint8_t sync1;
    uint8_t sync2;
    uint16_t msg;
    uint16_t length;
} ubx_header_t;

/* General: Checksum */
typedef struct {
    uint8_t ck_a;
    uint8_t ck_b;
} ubx_checksum_t;

/* Rx NAV-POSLLH */
typedef struct {
    uint32_t iTOW;  /**< GPS Time of Week [ms] */
    int32_t lon;    /**< Longitude [1e-7 deg] */
    int32_t lat;    /**< Latitude [1e-7 deg] */
    int32_t height; /**< Height above ellipsoid [mm] */
    int32_t hMSL;   /**< Height above mean sea level [mm] */
    uint32_t hAcc;  /**< Horizontal accuracy estimate [mm] */
    uint32_t vAcc;  /**< Vertical accuracy estimate [mm] */
} ubx_payload_rx_nav_posllh_t;

/* Rx NAV-DOP */
typedef struct {
    uint32_t iTOW; /**< GPS Time of Week [ms] */
    uint16_t gDOP; /**< Geometric DOP [0.01] */
    uint16_t pDOP; /**< Position DOP [0.01] */
    uint16_t tDOP; /**< Time DOP [0.01] */
    uint16_t vDOP; /**< Vertical DOP [0.01] */
    uint16_t hDOP; /**< Horizontal DOP [0.01] */
    uint16_t nDOP; /**< Northing DOP [0.01] */
    uint16_t eDOP; /**< Easting DOP [0.01] */
} ubx_payload_rx_nav_dop_t;

/* Rx NAV-SOL */
typedef struct {
    uint32_t iTOW;  /**< GPS Time of Week [ms] */
    int32_t fTOW;   /**< Fractional part of iTOW (range: +/-500000) [ns] */
    int16_t week;   /**< GPS week */
    uint8_t gpsFix; /**< GPSfix type: 0 = No fix, 1 = Dead Reckoning only, 2 = 2D fix, 3 = 3d-fix, 4 = GPS + dead reckoning, 5 = time only fix */
    uint8_t flags;
    int32_t ecefX;
    int32_t ecefY;
    int32_t ecefZ;
    uint32_t pAcc;
    int32_t ecefVX;
    int32_t ecefVY;
    int32_t ecefVZ;
    uint32_t sAcc;
    uint16_t pDOP; /**< Position DOP [0.01] */
    uint8_t reserved1;
    uint8_t numSV; /**< Number of SVs used in Nav Solution */
    uint32_t reserved2;
} ubx_payload_rx_nav_sol_t;

/* Rx NAV-PVT (ubx8) */
typedef struct {
    uint32_t iTOW;   /**< GPS Time of Week [ms] */
    uint16_t year;   /**< Year (UTC)*/
    uint8_t month;   /**< Month, range 1..12 (UTC) */
    uint8_t day;     /**< Day of month, range 1..31 (UTC) */
    uint8_t hour;    /**< Hour of day, range 0..23 (UTC) */
    uint8_t min;     /**< Minute of hour, range 0..59 (UTC) */
    uint8_t sec;     /**< Seconds of minute, range 0..60 (UTC) */
    uint8_t valid;   /**< Validity flags (see UBX_RX_NAV_PVT_VALID_...) */
    uint32_t tAcc;   /**< Time accuracy estimate (UTC) [ns] */
    int32_t nano;    /**< Fraction of second (UTC) [-1e9...1e9 ns] */
    uint8_t fixType; /**< GNSSfix type: 0 = No fix, 1 = Dead Reckoning only, 2 = 2D fix, 3 = 3d-fix, 4 = GNSS + dead reckoning, 5 = time only fix */
    uint8_t flags;   /**< Fix Status Flags (see UBX_RX_NAV_PVT_FLAGS_...) */
    uint8_t reserved1;
    uint8_t numSV;    /**< Number of SVs used in Nav Solution */
    int32_t lon;      /**< Longitude [1e-7 deg] */
    int32_t lat;      /**< Latitude [1e-7 deg] */
    int32_t height;   /**< Height above ellipsoid [mm] */
    int32_t hMSL;     /**< Height above mean sea level [mm] */
    uint32_t hAcc;    /**< Horizontal accuracy estimate [mm] */
    uint32_t vAcc;    /**< Vertical accuracy estimate [mm] */
    int32_t velN;     /**< NED north velocity [mm/s]*/
    int32_t velE;     /**< NED east velocity [mm/s]*/
    int32_t velD;     /**< NED down velocity [mm/s]*/
    int32_t gSpeed;   /**< Ground Speed (2-D) [mm/s] */
    int32_t headMot;  /**< Heading of motion (2-D) [1e-5 deg] */
    uint32_t sAcc;    /**< Speed accuracy estimate [mm/s] */
    uint32_t headAcc; /**< Heading accuracy estimate (motion and vehicle) [1e-5 deg] */
    uint16_t pDOP;    /**< Position DOP [0.01] */
    uint16_t reserved2;
    uint32_t reserved3;
    int32_t headVeh;    /**< (ubx8+ only) Heading of vehicle (2-D) [1e-5 deg] */
    uint32_t reserved4; /**< (ubx8+ only) */
} ubx_payload_rx_nav_pvt_t;
#define UBX_PAYLOAD_RX_NAV_PVT_SIZE_UBX7 (sizeof(ubx_payload_rx_nav_pvt_t) - 8)
#define UBX_PAYLOAD_RX_NAV_PVT_SIZE_UBX8 (sizeof(ubx_payload_rx_nav_pvt_t))

/* Rx NAV-TIMEUTC */
typedef struct {
    uint32_t iTOW; /**< GPS Time of Week [ms] */
    uint32_t tAcc; /**< Time accuracy estimate (UTC) [ns] */
    int32_t nano;  /**< Fraction of second, range -1e9 .. 1e9 (UTC) [ns] */
    uint16_t year; /**< Year, range 1999..2099 (UTC) */
    uint8_t month; /**< Month, range 1..12 (UTC) */
    uint8_t day;   /**< Day of month, range 1..31 (UTC) */
    uint8_t hour;  /**< Hour of day, range 0..23 (UTC) */
    uint8_t min;   /**< Minute of hour, range 0..59 (UTC) */
    uint8_t sec;   /**< Seconds of minute, range 0..60 (UTC) */
    uint8_t valid; /**< Validity Flags (see UBX_RX_NAV_TIMEUTC_VALID_...) */
} ubx_payload_rx_nav_timeutc_t;

/* Rx NAV-SVINFO Part 1 */
typedef struct {
    uint32_t iTOW; /**< GPS Time of Week [ms] */
    uint8_t numCh; /**< Number of channels */
    uint8_t globalFlags;
    uint16_t reserved2;
} ubx_payload_rx_nav_svinfo_part1_t;

/* Rx NAV-SVINFO Part 2 (repeated) */
typedef struct {
    uint8_t chn;  /**< Channel number, 255 for SVs not assigned to a channel */
    uint8_t svid; /**< Satellite ID */
    uint8_t flags;
    uint8_t quality;
    uint8_t cno;   /**< Carrier to Noise Ratio (Signal Strength) [dbHz] */
    int8_t elev;   /**< Elevation [deg] */
    int16_t azim;  /**< Azimuth [deg] */
    int32_t prRes; /**< Pseudo range residual [cm] */
} ubx_payload_rx_nav_svinfo_part2_t;

/* Rx NAV-VELNED */
typedef struct {
    uint32_t iTOW;   /**< GPS Time of Week [ms] */
    int32_t velN;    /**< North velocity component [cm/s]*/
    int32_t velE;    /**< East velocity component [cm/s]*/
    int32_t velD;    /**< Down velocity component [cm/s]*/
    uint32_t speed;  /**< Speed (3-D) [cm/s] */
    uint32_t gSpeed; /**< Ground speed (2-D) [cm/s] */
    int32_t heading; /**< Heading of motion 2-D [1e-5 deg] */
    uint32_t sAcc;   /**< Speed accuracy estimate [cm/s] */
    uint32_t cAcc;   /**< Course / Heading accuracy estimate [1e-5 deg] */
} ubx_payload_rx_nav_velned_t;

/* Rx MON-HW (ubx6) */
typedef struct {
    uint32_t pinSel;
    uint32_t pinBank;
    uint32_t pinDir;
    uint32_t pinVal;
    uint16_t noisePerMS;
    uint16_t agcCnt;
    uint8_t aStatus;
    uint8_t aPower;
    uint8_t flags;
    uint8_t reserved1;
    uint32_t usedMask;
    uint8_t VP[25];
    uint8_t jamInd;
    uint16_t reserved3;
    uint32_t pinIrq;
    uint32_t pullH;
    uint32_t pullL;
} ubx_payload_rx_mon_hw_ubx6_t;

/* Rx MON-HW (ubx7+) */
typedef struct {
    uint32_t pinSel;
    uint32_t pinBank;
    uint32_t pinDir;
    uint32_t pinVal;
    uint16_t noisePerMS;
    uint16_t agcCnt;
    uint8_t aStatus;
    uint8_t aPower;
    uint8_t flags;
    uint8_t reserved1;
    uint32_t usedMask;
    uint8_t VP[17];
    uint8_t jamInd;
    uint16_t reserved3;
    uint32_t pinIrq;
    uint32_t pullH;
    uint32_t pullL;
} ubx_payload_rx_mon_hw_ubx7_t;

/* Rx MON-VER Part 1 */
typedef struct {
    uint8_t swVersion[30];
    uint8_t hwVersion[10];
} ubx_payload_rx_mon_ver_part1_t;

/* Rx MON-VER Part 2 (repeated) */
typedef struct {
    uint8_t extension[30];
} ubx_payload_rx_mon_ver_part2_t;

/* Rx ACK-ACK */
typedef union {
    uint16_t msg;
    struct {
        uint8_t clsID;
        uint8_t msgID;
    };
} ubx_payload_rx_ack_ack_t;

/* Rx ACK-NAK */
typedef union {
    uint16_t msg;
    struct {
        uint8_t clsID;
        uint8_t msgID;
    };
} ubx_payload_rx_ack_nak_t;

/* Tx CFG-PRT */
typedef struct {
    uint8_t portID;
    uint8_t reserved0;
    uint16_t txReady;
    uint32_t mode;
    uint32_t baudRate;
    uint16_t inProtoMask;
    uint16_t outProtoMask;
    uint16_t flags;
    uint16_t reserved5;
} ubx_payload_tx_cfg_prt_t;

/* Tx CFG-RATE */
typedef struct {
    uint16_t measRate; /**< Measurement Rate, GPS measurements are taken every measRate milliseconds */
    uint16_t navRate;  /**< Navigation Rate, in number of measurement cycles. This parameter cannot be changed, and must be set to 1 */
    uint16_t timeRef;  /**< Alignment to reference time: 0 = UTC time, 1 = GPS time */
} ubx_payload_tx_cfg_rate_t;

/* Tx CFG-NAV5 */
typedef struct {
    uint16_t mask;
    uint8_t dynModel; /**< Dynamic Platform model: 0 Portable, 2 Stationary, 3 Pedestrian, 4 Automotive, 5 Sea, 6 Airborne <1g, 7 Airborne <2g, 8 Airborne <4g */
    uint8_t fixMode;  /**< Position Fixing Mode: 1 2D only, 2 3D only, 3 Auto 2D/3D */
    int32_t fixedAlt;
    uint32_t fixedAltVar;
    int8_t minElev;
    uint8_t drLimit;
    uint16_t pDop;
    uint16_t tDop;
    uint16_t pAcc;
    uint16_t tAcc;
    uint8_t staticHoldThresh;
    uint8_t dgpsTimeOut;
    uint8_t cnoThreshNumSVs; /**< (ubx7+ only, else 0) */
    uint8_t cnoThresh;       /**< (ubx7+ only, else 0) */
    uint16_t reserved;
    uint16_t staticHoldMaxDist; /**< (ubx8+ only, else 0) */
    uint8_t utcStandard;        /**< (ubx8+ only, else 0) */
    uint8_t reserved3;
    uint32_t reserved4;
} ubx_payload_tx_cfg_nav5_t;

/* tx cfg-sbas */
typedef struct {
    uint8_t mode;
    uint8_t usage;
    uint8_t maxSBAS;
    uint8_t scanmode2;
    uint32_t scanmode1;
} ubx_payload_tx_cfg_sbas_t;

/* Tx CFG-MSG */
typedef struct {
    union {
        uint16_t msg;
        struct {
            uint8_t msgClass;
            uint8_t msgID;
        };
    };
    uint8_t rate;
} ubx_payload_tx_cfg_msg_t;

/* General message and payload buffer union */
typedef union {
    ubx_payload_rx_nav_pvt_t payload_rx_nav_pvt;
    ubx_payload_rx_nav_posllh_t payload_rx_nav_posllh;
    ubx_payload_rx_nav_sol_t payload_rx_nav_sol;
    ubx_payload_rx_nav_dop_t payload_rx_nav_dop;
    ubx_payload_rx_nav_timeutc_t payload_rx_nav_timeutc;
    ubx_payload_rx_nav_svinfo_part1_t payload_rx_nav_svinfo_part1;
    ubx_payload_rx_nav_svinfo_part2_t payload_rx_nav_svinfo_part2;
    ubx_payload_rx_nav_velned_t payload_rx_nav_velned;
    ubx_payload_rx_mon_hw_ubx6_t payload_rx_mon_hw_ubx6;
    ubx_payload_rx_mon_hw_ubx7_t payload_rx_mon_hw_ubx7;
    ubx_payload_rx_mon_ver_part1_t payload_rx_mon_ver_part1;
    ubx_payload_rx_mon_ver_part2_t payload_rx_mon_ver_part2;
    ubx_payload_rx_ack_ack_t payload_rx_ack_ack;
    ubx_payload_rx_ack_nak_t payload_rx_ack_nak;
    ubx_payload_tx_cfg_prt_t payload_tx_cfg_prt;
    ubx_payload_tx_cfg_rate_t payload_tx_cfg_rate;
    ubx_payload_tx_cfg_nav5_t payload_tx_cfg_nav5;
    ubx_payload_tx_cfg_sbas_t payload_tx_cfg_sbas;
    ubx_payload_tx_cfg_msg_t payload_tx_cfg_msg;

    uint8_t raw[256];
} ubx_buf_t;

#pragma pack(pop)
/*** END OF u-blox protocol binary message and payload definitions ***/

/* Decoder state */
typedef enum {
    UBX_DECODE_SYNC1 = 0,
    UBX_DECODE_SYNC2,
    UBX_DECODE_CLASS,
    UBX_DECODE_ID,
    UBX_DECODE_LENGTH1,
    UBX_DECODE_LENGTH2,
    UBX_DECODE_PAYLOAD,
    UBX_DECODE_CHKSUM1,
    UBX_DECODE_CHKSUM2
} ubx_decode_state_t;

/* Rx message state */
typedef enum {
    UBX_RXMSG_IGNORE = 0,
    UBX_RXMSG_HANDLE,
    UBX_RXMSG_DISABLE,
    UBX_RXMSG_ERROR_LENGTH
} ubx_rxmsg_state_t;

/* ACK state */
typedef enum {
    UBX_ACK_IDLE = 0,
    UBX_ACK_WAITING,
    UBX_ACK_GOT_ACK,
    UBX_ACK_GOT_NAK
} ubx_ack_state_t;

#define SAT_INFO_MAX_SATELLITES 20

struct satellite_info_s {
    uint64_t timestamp;                         /**< Timestamp of satellite info */
    uint8_t count;                              /**< Number of satellites in satellite info */
    uint8_t svid[SAT_INFO_MAX_SATELLITES];      /**< Space vehicle ID [1..255], see scheme below  */
    uint8_t used[SAT_INFO_MAX_SATELLITES];      /**< 0: Satellite not used, 1: used for navigation */
    uint8_t elevation[SAT_INFO_MAX_SATELLITES]; /**< Elevation (0: right on top of receiver, 90: on the horizon) of satellite */
    uint8_t azimuth[SAT_INFO_MAX_SATELLITES];   /**< Direction of satellite, 0: 0 deg, 255: 360 deg. */
    uint8_t snr[SAT_INFO_MAX_SATELLITES];       /**< dBHz, Signal to noise ratio of satellite C/N0, range 0..99, zero when not tracking this satellite. */
};

struct gps_tm {
    int tm_sec;                                                     /* second (0-61, allows for leap seconds) */
    int tm_min;                                                     /* minute (0-59) */
    int tm_hour;                                                    /* hour (0-23) */
    int tm_mday;                                                    /* day of the month (1-31) */
    int tm_mon;                                                     /* month (0-11) */
    int tm_year;                                                    /* years since 1900 */
    int tm_wday; /* day of the week (0-6) */                        /*not supported by NuttX*/
    int tm_yday; /* day of the year (0-365) */                      /*not supported by NuttX*/
    int tm_isdst; /* non-0 if daylight savings time is in effect */ /*not supported by NuttX*/
};

typedef int (*ubx_rx_handle_ptr)(void);
typedef struct {
    rt_device_t ubx_dev;
    ubx_decode_state_t decode_state;
    ubx_rxmsg_state_t rx_state;
    ubx_ack_state_t ack_state;
    ubx_buf_t buf;
    struct satellite_info_s satellite_info;
    ubx_rx_handle_ptr ubx_rx_handle;
    uint16_t rx_payload_length;
    uint16_t rx_payload_index;
    uint8_t rx_ck_a;
    uint8_t rx_ck_b;
    uint16_t rx_msg;
    uint16_t ack_waiting_msg;
    uint32_t ubx_version;
    bool got_posllh;
    bool got_velned;
    bool got_svinfo;
    bool configured;
    bool use_nav_pvt;
} ubx_decoder_t;

void reset_ubx_decoder(ubx_decoder_t* ubx_decoder);
fmt_err_t init_ubx_decoder(ubx_decoder_t* ubx_decoder, rt_device_t ubx_dev, ubx_rx_handle_ptr ubx_rx_handle);
int parse_ubx_char(ubx_decoder_t* ubx_decoder, const uint8_t c);

fmt_err_t send_ubx_msg(ubx_decoder_t* ubx_decoder, const uint16_t msg, const uint8_t* payload, const uint16_t length);
fmt_err_t configure_ubx_msg_rate(ubx_decoder_t* ubx_decoder, const uint16_t msg, const uint8_t rate);

#ifdef __cplusplus
}
#endif

#endif /* UBLOX_H__ */

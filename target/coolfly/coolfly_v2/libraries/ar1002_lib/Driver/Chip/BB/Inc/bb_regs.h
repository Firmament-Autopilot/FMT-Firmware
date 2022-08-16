#ifndef __CONFIG_BASEBAND_REGISTER_H
#define __CONFIG_BASEBAND_REGISTER_H


#define     FSM_0                           (0x00)              /*  [7]page_sel 1: TRX FSM and TX, page1  0: RX, page2
                                                                    [6]fec_reset_en
                                                                    [5]fch_reset_en
                                                                    [4]pkd_reset_en
                                                                    [3]force to 1
                                                                    [2]manual_reset_tx_en  1'b1: reset TX on  1'b0: off
                                                                    [1]manual_reset_rx_en  1'b1: reset RX on  1'b0: off
                                                                    [0]manual_reset_trx_en 1'b1: reset TX/RX on 1'b0: off
                                                                */

#define     TX_2                            (0x04)              /*  page 2
                                                                    QAM_mode        RW  [7:6] 2 0x2
                                                                    BandWidth       RW  [5:3] 3 0x2
                                                                    code_rate_enum  RW  [2:0] 3 0x0
                                                                */

#define     RX_MODULATION                   (0x08)              /*  page 2 
                                                                    BandWidth       RW  [5:3] 3 0x2
                                                                */

#define     TX_3                            (0x5b)              //RC_id_bits[39:32]
#define     TX_4                            (0x5c)              //RC_id_bits[31:24]
#define     TX_5                            (0x5d)              //RC_id_bits[23:16]
#define     TX_6                            (0x5e)              //RC_id_bits[15:8]
#define     TX_7                            (0x5f)              //RC_id_bits[7:0]

/****start of ground - > sky registers From 0x60 -> 0x9F */

#define     SEARCH_STATUS_MASK              (0x80)
#define     LOCK_STATUS_MASK                (0x02)
#define     SPI_DT_HEAD_REGISTER            (0x60)
#define     SPI_DT_END_ADDR                 (0x9F)



#define     GRD_SKY_RC_RSV_BIT_MASK         (0x80)  //use for check valid
#define     GRD_SKY_RC_CH_MASK              (0x3F)  //use for sync the rc channel
#define     GRD_SKY_BAND_SWITCH_MASK        (0x40)  //use for sync the band switch option: enable or disable

#define     GRD_SKY_RC_CH_SYNC              (0x61)


#define     GRD_SKY_IT_CH_MASK              (0x3F)
#define     GRD_SKY_BLOCK_MODE_MASK         (0xC0)

#define     GRD_SKY_IT_CH_SYNC              (0x62)  //use for vt channel sync[5:0]
                                                    //signal block mode sync[7:6]

#define     MCS_INDEX_MODE                  (0x63) //bit[7] : encode-rt-mode, bit[6] non-lbt-enable, bit[3:0] mcs value


#define     GROUND_SEARCH_REGS_CNT          (6)

#define     GRD_SEARCHING                   (0x64)     //1: in searching mode


/****end of ground - > sky registers Fro    m 0x60 -> 0x9F */

#define     SWEEP_ENERGY_HIGH               (0xa2)
#define     SWEEP_ENERGY_MID                (0xa3)
#define     SWEEP_ENERGY_LOW                (0xa4)

#define     FSM_2                           (0x02)          /*  
                                                            [7]  s_rec_time_decision
                                                            [6]  s_send_time_decision
                                                            [5]  g_rec_time_decision
                                                            [4]  g_send_time_decision
                                                            [3]  reg_rd_freeze
                                                            [2]  send_inside_en
                                                            [1]  it_en
                                                            [0]  rc_en
                                                            */

#define     MCS_0                           (0x09)          
									 /*  [7]  mcs_auto_switch_on
                                                                [6]  one_mcs_reset_en
                                                                [5]  mcs5_on
                                                                [4]  mcs4_on
                                                                [3]  mcs3_on
                                                                [2]  mcs2_on
                                                                [1]  mcs1_on
                                                                [0]  mcs0_on
                                                            */

#define     MCS_1                           (0x0A)          /*  [7:2]Reserved
                                                                [1]  mcs_ldpc_judge_on
                                                                [0]  mcs_rssi_judge_on
                                                            */

#define     MCS_2                           (0x0B)          // [7:0]mcs_rssi_th1 (mcs5->mcs4)
#define     MCS_3                           (0x0C)          // [7:0]mcs_rssi_th2 (mcs4->mcs5)
#define     MCS_4                           (0x0D)          /* [7:4]  mcs_rssi_diff
                                                            [3:0]  mcs_gain_diff
                                                            */

#define     MCS_5                           (0x0E)          //Mcs_ldpc_period[7:0]

#define     FSM_5                           (0x0F)          //pkd_times

#define     AGC_0                           (0x10)          /*PAGE2
                                                            [7]   reg_power_diff_fix 
                                                                    1:fix; 0:auto
                                                            [6]   reg_aagc_fix.
                                                                    1:fix AGC gain; 0:auto
                                                            [5]   iq_exchange_1
                                                            [4]   iq_exchange_2
                                                            [3]   reg_enable_fre_hop
                                                                    1:enable fre hop; 0:disable
                                                            [2]   reg_8x_switch_en
                                                                    1:switch; 0:not switch
                                                            [1]   bypass_dgain
                                                                    1:bypass digital gain; 0:use digital gain
                                                            [0]   rx_din_ori
                                                                    0:2's complement; 1:ori code
                                                            */

#define     AGC_2                           (0x92)          //reg_aagc_fix_gain1 0x00  RW  [7:0]
#define     AGC_3                           (0x93)          //reg_aagc_fix_gain2 0x01  RW  [7:0]

#define     AGC_5G_GAIN1                    (0xc6)
#define     AGC_5G_GAIN2                    (0xc7)

#define     FEC_7                           (0x50)          //PAGE2_rc_id[39:32]  0x00 RW  [7:0]
#define     FEC_8                           (0x51)          //PAGE2_rc_id[31:24]  0x01 RW  [7:0]
#define     FEC_9                           (0x52)          //PAGE2_rc_id[23:16]  0x02 RW  [7:0]
#define     FEC_10                          (0x53)          //PAGE2_rc_id[15:8]   0x03 RW  [7:0]
#define     FEC_11                          (0x54)          //PAGE2_rc_id[7:0]    0x04 RW  [7:0]

#define     AGC3_0                          (0x10)          //reg_aggc_work_frequency[7:0].
#define     AGC3_1                          (0x11)          //reg_aggc_work_frequency[15:8].
#define     AGC3_2                          (0x12)          //reg_aggc_work_frequency[23:16].
#define     AGC3_3                          (0x13)          //reg_aggc_work_frequency[31:24].

#define     AGC3_6                          (0x14)          //reg_aggc_sweep_frequency[15:8].
#define     AGC3_7                          (0x15)          //reg_aggc_sweep_frequency[23:16].
#define     AGC3_8                          (0x16)          //reg_aggc_sweep_frequency[31:24].
#define     AGC3_9                          (0x17)          //reg_aggc_sweep_frequency[39:32].

//page2     0x10                                
#define     AGC3_a                          (0x18)          //reg_aggc_rc_frequency[7:0].    0x0b    RW  [7:0] 
#define     AGC3_b                          (0x19)          //reg_aggc_rc_frequency[15:8].   0x0a    RW  [7:0]  
#define     AGC3_c                          (0x1a)          //reg_aggc_rc_frequency[23:16].  0x09    RW  [7:0]  
#define     AGC3_d                          (0x1b)          //reg_aggc_rc_frequency[31:24].  0x08    RW  [7:0]   
#define     AGC3_e                          (0x1e)          //reg_aggc_rc_frequency[39:32].

//page2 
#define     AAGC_0_RD                       (0x02)          //Lowest byte of channel power
#define     AAGC_4_RD                       (0x03)          //Middle byte of channel power
#define     AAGC_1_RD                       (0x04)          //Highest byte of channel power

//page2 
#define     AAGC_2_RD                       (0xA0)          //rx1_gain_all_r  RW  [7:0]
#define     AAGC_3_RD                       (0xA1)          //rx2_gain_all_r  RW  [7:0]

#define     RX3_GAIN_ALL_R                  (0xA5)          //rx3_gain_all_r  RW  [7:0]
#define     RX4_GAIN_ALL_R                  (0xA6)          //rx4_gain_all_r  RW  [7:0]

#define     FEC_0_RD                        (0xE0)          /*
                                                            [7]  Rc_rev_ok_inwimax
                                                            [6]  Retx_pkg_req_curr
                                                            [5]  Retx_flg
                                                            [4:2]Ldpc_rate_in
                                                            [1:0]Qam_mode_in
                                                            */

#define     GRD_FEC_QAM_CR_TLV              (0xD0)          /*
                                                            [6:5] TLV mode
                                                            [2:4] coderate
                                                            [0:1] QAM
                                                            */

#define     FEC_1_RD                        (0xD2)          //[7:0]Dec_rc_id[39:32]
#define     FEC_2_RD_1                      (0xD3)          //[7:0]Dec_rc_id[31:24]
#define     FEC_2_RD_2                      (0xD4)          //[7:0]Dec_rc_id[23:16]
#define     FEC_2_RD_3                      (0xD5)          //[7:0]Dec_rc_id[15:8]
#define     FEC_2_RD_4                      (0xD6)          //[7:0]Dec_rc_id[7:0]

#define     LDPC_ERR_AFTER_HARQ_HIGH_8      (0xDE)          //Harq ldpc error num[15:8]
#define     LDPC_ERR_AFTER_HARQ_LOW_8       (0xDF)          //Ldpc_err_num_rd[7:0]

#define     LDPC_ERR_HIGH_8                 (0xD7)          //Ldpc_err_num_rd[15:8]
#define     LDPC_ERR_LOW_8                  (0xD8)          //Ldpc_err_num_rd[7:0]

#define     FEC_4_RD                        (0xD9)          /*PAGE2
                                                            rc_err_flg  RO  [7:7]   
                                                            nr_check_ok_hold  RO  [2:2]
                                                            crc_check_ok  RO  [1:1]
                                                            id_match  RO  [0:0]
                                                            */

#define     FEC_5_RD                        (0xDA)          /*[7:4]Harq_times_out
                                                            [3:0]Debug_fec_sel:rdout_sclr_cnt:{1'b0, Scale_reg_out }
                                                            */

#define     FEC_6_RD                        (0xEB)          /*  [7]  1'b0
                                                                [6]  Fch_err_flg
                                                                [5]  Dat_err_flg_frame
                                                                [4]  1'b0
                                                                [3:1]pkg_index_fch
                                                                [0]  Fec_lock
                                                            */

#define     CE_9_RD                         (0xD9)          //SNR_DOUT [15:8]
#define     CE_A_RD                         (0xDA)          //SNR_DOUT [7:0]

#define     GRD_RC_ID_BIT07_00_REG          (0x5f)
#define     GRD_RC_ID_BIT15_08_REG          (0x5e)
#define     GRD_RC_ID_BIT23_16_REG          (0x5d)
#define     GRD_RC_ID_BIT31_24_REG          (0x5c)
#define     GRD_RC_ID_BIT39_32_REG          (0x5b)

#define     SWEEP_FREQ_0                    (0x14)
#define     SWEEP_FREQ_1                    (0x15)
#define     SWEEP_FREQ_2                    (0x16)
#define     SWEEP_FREQ_3                    (0x17)

#define     SNR_REG_0                       (0xc0)
#define     SNR_REG_1                       (0xc1)

#define     LDPC_ERR_HIGH_REG               (0xde)
#define     LDPC_ERR_LOW_REG                (0xdf)

#define     TX_CALI_ENABLE                  (0x61)

#define     POWER_GATE                      (0x45)

#define     SDRAM_BLOCK_SIZE                (0xcc)
#define     USB_BYPASS_MODE                 (0x56)

#define    INTEGER_OFFSET                   (0xc5)

#define    FRACTION_OFFSET_0                (0xbf)
#define    FRACTION_OFFSET_1                (0xbe)
#define    FRACTION_OFFSET_2                (0xbd)
#define    FRACTION_OFFSET_3                (0xbc)

#define    TRACK_OFFSET_0                   (0xbb)
#define    TRACK_OFFSET_1                   (0xba)
#define    TRACK_OFFSET_2                   (0xb9)
#define    TRACK_OFFSET_3                   (0xb8)


#define    HW_OFFSET_0                      (0xb3)
#define    HW_OFFSET_1                      (0xb2)
#define    HW_OFFSET_2                      (0xb1)


#define   SW_OFFSET_0                       (0x1d)
#define   SW_OFFSET_1                       (0x1c)
#define   SW_OFFSET_2                       (0x1b)

#define     SYNC_CNT                        (0x5F)

#define  GRD_NON_LBT_VT_CH                   (0xd5) //bit[7:6], notice seq, bit[5:0], sky select vt ch
#define  SKY_NON_LBT_VT_CH                   (0x5d) //bit[7:6], notice seq, bit[5:0], sky select vt ch

#define BB_POWER_A                            (0x09)
#define BB_POWER_B                            (0x16)
#define BB_POWER_DEFAULT_VALUE              (0x30)
#endif

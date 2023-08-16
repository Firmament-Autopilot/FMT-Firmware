#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "usr_wir_core.h"
#include "hal_bb.h"
#include "debuglog.h"
#include "bb_types.h"
#include "wireless_interface.h"

WIR_INFO wir_info;

int get_buf_info(void)
{
    int ret;
    unsigned char *p;

    STRU_WIRELESS_INFO_DISPLAY *pst_bb_info =(STRU_WIRELESS_INFO_DISPLAY *)&p;

    ret = HAL_BB_GetInfo(&pst_bb_info);

    if (pst_bb_info == NULL)
    {
        DLOG_Info("failed");
        return -1;
    }
    
    /*if (pst_bb_info->osd_enable != 1)
    {
        pst_bb_info->osd_enable = 1;
        DLOG_Info("enable osd");
        return -1;
    }*/

    //if(HAL_OK == ret)
    {
        *(int *)(wir_info.vedio_space) = pst_bb_info->sdram_buf_size[1];
        *(int *)(wir_info.vedio_space1) = pst_bb_info->sdram_buf_size[0];
		 wir_info.taget_Power = pst_bb_info->current_pwr;
        if((pst_bb_info->lock_status & 0x07) == 0x07)
            wir_info.match_state = 1;
        else
            wir_info.match_state = 2;
        return 0;
    }

    return -1;
}

int get_vedio_deep(int *len)
{
    if(get_buf_info() < 0)
        return -1;

    *len = *(int *)(wir_info.vedio_space);
    // DLOG_Info("len = %x",*len);

    return 0;
}
int get_vedio_deep1(int *len)
{
    *len = *(int *)(wir_info.vedio_space1);
    // DLOG_Info("len = %x",*len);
    return 0;
}

uint8_t get_mcs(void)
{
	switch(wir_info.encoder_brcidx)
	{
		
	case 1:
		return 0;
	break;
	case 2:
		return 1;
	break;
	case 3:
		return 2;
	break;
	case 8:
		return 3;
	break;
	case 11:
		return 4;
	break;
	case 13:
		return 5;
	break;

	defaut:
		return 1;

	}

}

uint8_t get_bw(void){
	return  wir_info.bandwidth;
}

uint8_t get_taget_pwr(void){
	return  wir_info.taget_Power;
}

void enc_brcidx_change(uint8_t enc_brcidx,uint8_t bw)
{
    wir_info.encoder_brcidx = enc_brcidx;
    wir_info.bandwidth = bw;
    wir_info.freq_range = 0;
    wir_info.freq_mode = 0;
    wir_info.freq_chanl = 0;

}

int Wir_Info_Handler(WIR_INFO *usrbuf)
{
    int ret;
    ret = get_buf_info();

    *usrbuf = wir_info;

    if(ret < 0)
        return -1;

    return 0;

}

int Wir_Freq_Range_Handler(char mode)
{
    STRU_WIRELESS_PARAM_CONFIG_MESSAGE usr_cfg;

    if(mode == 2)//auto
    {
        usr_cfg.paramData[0] = AUTO;
        PAD_FREQUENCY_BAND_OPERATION_MODE_Handler(&usr_cfg,0);
    }
    else//manual
    {
        usr_cfg.paramData[0] = MANUAL;
        PAD_FREQUENCY_BAND_OPERATION_MODE_Handler(&usr_cfg,0);
	    if(mode == 0)
        {
            usr_cfg.paramData[0] = 0;
        }
        else if(mode == 1)
        {
            usr_cfg.paramData[0] = 1;
        }
        WIRELESS_INTERFACE_SWITCH_WORKING_FREQ_BAND_Handler(&usr_cfg,0);
    }
    return 0;

}

int Wir_Set_Freq_Handler(char *param,char *ret_data)
{
    DLOG_Critical("param[0] = %d  param[1] = %d param[2] = %d",param[0],param[1],param[2]);
    return 0;
}

int Wir_Set_Pwr_Handler(char *param)
{
    HAL_RET_T ret;
    int err = 0;
    //DLOG_Critical("0- %d  1- %d 2- %d 3- %d 4- %d",param[0],param[1],param[2],param[3],param[4]);
    
    if(HAL_BB_SetPower(param[3],param[4]) != HAL_OK)
        err ++;
    
    if(HAL_BB_SetPowerWorkMode(param[2]) != HAL_OK)
        err ++;
    
    if(HAL_PwrCtrlSet(param[1]) != HAL_OK)
        err ++;

    if(err > 0)
        return -1;
    else
        return 0;
}




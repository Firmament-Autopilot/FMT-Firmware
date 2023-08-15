#ifndef __USR_WIR_CORE__
#define __USR_WIR_CORE__

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct WIR_INFO{

        volatile uint8_t    encoder_brcidx;
        volatile uint8_t    match_state;
        volatile uint8_t    bandwidth;
        volatile uint8_t    freq_range;
        volatile uint8_t    freq_mode;
        volatile uint8_t    freq_chanl;
        volatile uint8_t    vedio_space[4];
        volatile uint8_t    vedio_space1[4];
		volatile uint8_t	taget_Power;
    }WIR_INFO;

    void enc_brcidx_change(uint8_t enc_brcidx,uint8_t bw);
    int Wir_Info_Handler(WIR_INFO *usrbuf);
    int Wir_Freq_Range_Handler(char mode);
    int Wir_Set_Freq_Handler(char *param,char *ret_data);
    int Wir_Set_Pwr_Handler(char *param);
    int get_vedio_deep(int *len);
    uint8_t get_mcs(void);
	uint8_t get_bw(void);
	uint8_t get_taget_pwr(void);
    int get_vedio_deep1(int *len);

#ifdef __cplusplus
}
#endif

#endif


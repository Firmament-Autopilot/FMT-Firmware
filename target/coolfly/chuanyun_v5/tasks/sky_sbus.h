#ifndef __SKY_SBUS_H__
#define __SKY_SBUS_H__


#ifdef __cplusplus
extern "C"
{
#endif


typedef struct {
	uint32_t ch[16];
	uint64_t timestamp;
} cf_rc_s;

typedef struct  {
	uint8_t sbus_buff[25];
	uint64_t timestamp;
} cf_sbus_s;

rt_err_t register_ar_rc(void);

void sbus_start(void);


#ifdef __cplusplus
}
#endif

#endif


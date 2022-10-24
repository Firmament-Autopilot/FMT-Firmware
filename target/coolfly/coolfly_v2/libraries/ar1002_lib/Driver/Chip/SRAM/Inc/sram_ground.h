#ifndef __SRAM_GROUND_H__
#define __SRAM_GROUND_H__

#include "memory_config.h"

/*
  *******************************************************
  ****************             GROUND         *******************
  *******************************************************
  */

/* these register is for SRAM configuration */
#define DMA_READY_0                     0x40B00038
#define DMA_READY_1                     0x40B0003C


#define SRAM_CHANNEL_NUM                0x2


#define SRAM_DMA_READY_LEN              0x750           /* threshold for BaseBand to trigger READY_IRQ:128 word or others */
#define SRAM_WR_ADDR_OFFSET_0           0x40B00028
#define SRAM_WR_ADDR_OFFSET_1           0x40B0002C     /* this value should not smaller than SRAM_WR_MAX_LEN_0 */
#define SRAM_WR_MAX_LEN_0               0x40B00030     /* unit: 1 word = 4 byte */
#define SRAM_WR_MAX_LEN_1               0x40B00034
#define SRAM_DATA_VALID_LEN_0           (*((volatile unsigned int *)0x40B00040))
#define SRAM_DATA_VALID_LEN_1           (*((volatile unsigned int *)0x40B00044))

#define SRAM_DATA_RESERVED_LEN          16

#define SRAM_BB_BYPASS_OFFSET_0         (((SRAM_BB_VIDEO_BUFFER_0_ST_ADDRESS - SRAM_BASE_ADDRESS) + SRAM_DATA_RESERVED_LEN) >> 2)     /* BB bypass channel 0 to the address in SRAM */
#define SRAM_BB_BYPASS_OFFSET_1         (((SRAM_BB_VIDEO_BUFFER_1_ST_ADDRESS - SRAM_BASE_ADDRESS) + SRAM_DATA_RESERVED_LEN) >> 2)     /* BB bypass channel 1 to the address in SRAM */
#define SRAM_BUFF_0_ADDRESS             SRAM_BB_VIDEO_BUFFER_0_ST_ADDRESS
#define SRAM_BUFF_1_ADDRESS             SRAM_BB_VIDEO_BUFFER_1_ST_ADDRESS

#define SRAM_TIMEOUT_THRESHOLD          50

#ifdef ARCAST
#define SRAM_MP3_DECODE_BUFF_SIZE       0x400
#endif


typedef struct
{
    uint8_t     u8_usbEp;
    uint8_t     u8_usbPort;
    uint8_t     u8_rtspEnable;
} STRU_CHANNEL_PORT_CONFIG;

void SRAM_Ready0IRQHandler(uint32_t u32_vectorNum);
void SRAM_Ready1IRQHandler(uint32_t u32_vectorNum);
void SRAM_Ready0Confirm(void);
void SRAM_Ready1Confirm(void);
void SRAM_GROUND_ReceiveVideoConfig(void);
void SRAM_GetReceivedDataSize(uint32_t* p_sram0Size, uint32_t* p_sram1Size);

void SRAM_CheckTimeout(void);
#ifdef ARCAST
uint32_t SRAM_GetMp3BufferLength(void);
void SRAM_InsertMp3Buffer(uint32_t dataLen, uint8_t *data);
uint32_t SRAM_GetMp3Data(uint32_t dataLen, uint8_t *dataBuff);
#endif


extern volatile uint32_t  sramReady0;
extern volatile uint32_t  sramReady1;
extern STRU_CHANNEL_PORT_CONFIG  g_stChannelPortConfig[SRAM_CHANNEL_NUM];



void SRAM_EnableRTSPBypass(uint32_t channel);
void SRAM_InsertRTSPBuffer(uint32_t dataLen, uint8_t *data);


#endif


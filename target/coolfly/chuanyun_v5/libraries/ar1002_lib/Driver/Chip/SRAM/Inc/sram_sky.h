#ifndef __SRAM_SKY_H__
#define __SRAM_SKY_H__


/*
  *******************************************************
  ****************              SKY              *******************
  *******************************************************
  */

#define SRAM_VIEW0_ENABLE_ADDR          0xA003008C
#define SRAM_VIEW1_ENABLE_ADDR          0xA003004C
#define SRAM_VIEW0_ENABLE               0x00000001
#define SRAM_VIEW1_ENABLE               0x00000004


#define SRAM_SKY_MASTER_ID_ADDR         0xA0030090
#define SRAM_SKY_MASTER_ID_MASK_ADDR    0xA0030094


#define SRAM_SKY_MASTER_ID_VALUE        0x000
#define SRAM_SKY_MASTER_ID_MASK_VALUE   0x000

#define VIDEO_BYPASS_CHANNEL_0_DEST_ADDR    (0xB1000000)
#define VIDEO_BYPASS_CHANNEL_1_DEST_ADDR    (0xB1800000)


#define SRAM_BYPASS_ENCODER_MASTER_ADDR     (0xA0010000)  // master


void SRAM_SKY_EnableBypassVideoConfig(uint32_t channel);
void SRAM_SKY_DisableBypassVideoConfig(uint32_t channel);


#endif


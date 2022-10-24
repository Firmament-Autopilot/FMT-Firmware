///*****************************************
//  Copyright (C) 2009-2014
//  ITE Tech. Inc. All Rights Reserved
//  Proprietary and Confidential
///*****************************************
//   @file   <config.h>
//   @author Max.Kao@ite.com.tw
//   @date   2014/09/11
//   @fileversion: ITE_MHLRX_SAMPLE_V1.01
//******************************************/
#ifndef _CONFIG_H_
#define _CONFIG_H_

#define _MCU_8051_

#ifndef _MCU_8051_
#include "platform.h"
#endif

#define _IT66021_
#ifndef _IT66023_
#ifndef _IT6602_
#ifndef _IT66021_
#define _IT6602_
#endif
#endif
#endif

#ifdef _IT66023_
#pragma message("defined _IT66023_")
//#define ENABLE_IT66023	// only for IT66023 Usage
#endif


#ifdef _IT6602_
#pragma message("defined _IT6602_")
#endif

#ifdef _IT66021_
#pragma message("defined _IT66021_")
#endif

//#define SUPPORT_I2C_SLAVE
#ifdef SUPPORT_I2C_SLAVE
#pragma message ("SUPPORT_I2C_SLAVE defined")
#endif

#define _EN_DUAL_PIXEL_CTRL_

#define _EN_BLOCK_PWRDN_

#define SUPPORT_OUTPUTRGB

#define SUPPORT_INPUTYUV


//#define SUPPORT_UART_CMD

//#define       Enable_IT6602_CEC       //for ARC and HEAC Function

#ifdef Enable_IT6602_CEC

    #ifdef Enable_IT6602_CEC
        #include "it6602_cec.h"
    #endif

    #define DEBUG_IT6602_CEC
    #define IT6602CECGPIOid     0       // for identife IT6602_CEC use Pin 1.0 & 1.1
#endif



/****************************************************************************/

/****************************************************************************/

#define IT6602A0_HDMI_ADDR 0x94 //Hardware Fixed I2C address of IT6602 HDMI
#define IT6602B0_HDMI_ADDR 0x92 //Hardware Fixed I2C address of IT6602 HDMI
#define MHL_ADDR 0xE0   //Software programmable I2C address of IT6602 MHL
#define EDID_ADDR 0xA8  //Software programmable I2C address of IT6602 EDID RAM
#define CEC_ADDR 0xC8   //Software programmable I2C address of IT6602 CEC


#define DP_ADDR 0x90
#define ADC_ADDR 0x90



#define HDMI_DEV  0
#define DP_DEV    0

#define RXDEV           0
#define MAXRXDEV        1
/****************************************************************************/

/****************************************************************************/
#define HDMI_DEV        0
#define SWADR       0x96
#define EDID_HEAD   0xA0

#define DELAY_TIME        1
#define IDLE_TIME        100

#define HIGH            1
#define LOW                0
#define ACTIVE          1
#define DISABLE         0

#endif // _CONFIG_H_

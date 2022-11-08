/* ----------------------------------------------------------------------
 * $Date:        2016.12.10
 * $Revision:    V0.01
 *
 * Project:      
 * Title:        
 *
 * Version 0.01
 *       
 *  
 *----------------------------------------------------------------------------
 *
 * 
 *---------------------------------------------------------------------------*/

 /**
  ******************************************************************************
  * @file   BB_SPI_Operate.h
  * @author  
  * @date    
  * @brief   
  ******************************************************************************
  * @attention
  *
  *
  *
  ******************************************************************************
  */


#ifndef  BB_SPI_OPERATE_H
#define  BB_SPI_OPERATE_H

#include <stdint.h>
#include "debuglog.h"

#define	BB_SPI_OPR_BASE_ADDR	(0x74)
#define	BB_SPI_OPR_BASE_PAGE	(0x80)

typedef struct
{
	uint8_t		u8_arCnt[2]; 
	uint8_t		u8_checkSum;

	uint8_t		u8_itFreqTx;
	uint8_t		u8_rcFreqTx;
	uint8_t		u8_qamAutoManual;
	uint8_t		u8_qamChange;
	uint8_t		u8_rcChChange;
	uint8_t		u8_rcChMode;
	uint8_t		u8_rfBandChange;
	uint8_t		u8_rfChBwChange;
	uint8_t		u8_encoderBrcMode;
	uint8_t		u8_encoderBrcChange;
	
	uint8_t		rsrv[3];	
}BB_SPI_Opr;



/**
* @brief	  
* @param  	
* @retval 	
* @note   
*/
int32_t BB_SPI_Write(BB_SPI_Opr *p_stWrite);

/**
* @brief	  
* @param  	
* @retval 	
* @note   
*/
int32_t BB_SPI_Read(BB_SPI_Opr *p_stRead);



#endif

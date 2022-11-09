#ifndef __UPGREAD_SKY__
#define __UPGREAD_SKY__

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define UPGRADE_MAX_BLOCKARRAYSIZE           (2000)
#define APPLICATION_IMAGE_START              (0x10028000)
#define UPGRADE_DATACHUNK_SIZE               (496)

typedef enum
{
    UPGRADE_DATA_INIT = 0, //ground notify sky upgarde 
    UPGRADE_DATA_DATA,     //send data
    UPGRADE_LOSTBLOCK_DATA,// send lose data
    UPGRADE_DATA_END, //data end
    UPGRADE_UPGRADE_END,// upgrade ok
    UPGRADE_UPGRADE_CHECK,// check data
} ENUM_UPGRADE_SKY_STATE;

typedef enum
{
    UPGRADE_ACK_INIT = 0, //sky  init ok
    UPGRADE_ACK_END,      // sky upgrade ok
    UPGRADE_ACK_LOSTDATA, // sky send lose data block num
    UPGRADE_ACK_FAIL, // sky upgrade fail
    UPGRADE_ACK_CHECK,// sky check data
    UPGRADE_ACK_END_CF_SUCCESS,// sky upgrade end success
} ENUM_UPGRADE_GROUND_STATE;


typedef enum
{
    UPGRADE_USB = 0, 
} ENUM_UPGRADE_TRANSFERTYPE;

typedef struct
{
    uint16_t u16_lostDataBlockArray[UPGRADE_MAX_BLOCKARRAYSIZE];
    uint16_t u16_lostDataBlockCount;
} STRU_UPGRADE_STATUS;


typedef struct
{
    uint32_t u32_fileLength;
    uint8_t *filePath;
    ENUM_UPGRADE_TRANSFERTYPE  e_upgradeTransferType;
} STRU_UPGRADE_PARAMTER;


void UPGRADE_SKYInit(void);

/**
* @brief  ground send data status.
* @param  STRU_UPGRADE_STATUS.ENUM_UPGRADE_STATUS UPGRADE_OK upgrade ok.
                                                  UPGRADE_FAIL  upgrade fail.
                                                  UPGRADE_UPGRADING  upgrading.
          STRU_UPGRADE_STATUS.u32_fileSize upgrade file size.
          STRU_UPGRADE_STATUS.u32_sentFileSize sent upgrade file size.
          STRU_UPGRADE_STATUS.s_u16_lostDataBlockArray lose data block number.
          STRU_UPGRADE_STATUS.s_u8_lostDataBlockCount lose data block number count.
* @retval none.
* @note   none.
*/
void UPGRADE_GetStatus(STRU_UPGRADE_STATUS * pst_status);
/**
* @brief  ground send init for sky.
* @param  u32_recDataAddress   receive data address.
* @retval 1        sky receive init command.
* @retval 0        error.
* @note   None.
*/
int8_t UPGRADE_GndSendInit(void);
void UPGRADE_GNDInit(void);
/**
* @brief  ground send end for sky.
* @param  none.
* @retval 1        sky receive init command.
* @retval 0        error.
* @note   none.
*/
uint32_t UPGRADE_GndSendEnd(void);
int8_t UPGRADE_GndAndSkyLockStatus(void);

int8_t UpgradeGndStatus_Get(ENUM_UPGRADE_GROUND_STATE e_state);

/**
* @brief  ground send data to sky.
* @param  u8_opt UPGRADE_DATA_DATA send data.
                 UPGRADE_LOSTBLOCK_DATA send lose data.
          pu8_dataBuff data buff.
          u16_dataLen data length.
          u16_dataBlockNum data block Number
* @retval 0     send ok.
          !=0   send fail.
* @note   ground use UPGRADE_DATA_DATA send data.if sky lose data , sky notify ground lose data block number in s_u16_lostDataBlockArray.
*/
uint32_t UPGRADE_SendDataBlock(uint8_t u8_opt, uint8_t *pu8_dataBuff, uint16_t u16_dataLen, uint16_t u16_dataBlockNum);

/**
* @brief  check mass storage and file.
* @param  none.
* @retval 0     file data ok.
          !=0   file data error.
* @note   none.
*/
int8_t UPGRADE_UseUsbUpgrade(const uint8_t *fileName, uint8_t u8_flag);
/**
* @brief  upgrade start.
* @param  none.
* @retval none.
* @note   none.
*/
void UPGRADE_Start(void);
/**
* @brief  check flash data.
* @param  none.
* @retval -1            upgrade fail.
* @retval -0            upgrade ok.
* @note   none.
*/
 int8_t UPGRADE_ModifyBootInfo(uint32_t u32_addr);


bool get_update_task_flag(void);


#ifdef __cplusplus
}
#endif

#endif

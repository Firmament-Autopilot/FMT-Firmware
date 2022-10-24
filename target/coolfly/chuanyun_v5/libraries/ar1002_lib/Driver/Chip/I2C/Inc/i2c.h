#ifndef I2C_H
#define I2C_H

#include <stddef.h>
#include <stdint.h>

typedef enum
{
    I2C_Component_0 = 0,
    I2C_Component_1,
    I2C_Component_2,
    I2C_Component_3,
    I2C_Component_4,
    I2C_Component_5
} EN_I2C_COMPONENT;

typedef enum
{
    I2C_Master_Mode = 0,
    I2C_Slave_Mode,
    I2C_Unknown_Mode,
} ENUM_I2C_Mode;

typedef enum
{
    I2C_Standard_Speed = 1,
    I2C_Fast_Speed,
    I2C_High_Speed,
    I2C_Unknown_Speed,
    I2C_Custom_Fast_Speed
} ENUM_I2C_Speed;

typedef struct
{
    uint32_t txLen;         //
    uint32_t txAlrLen;      //
    uint8_t *txBuf;         //
    uint32_t txLenLast;     //
    uint32_t rxLen;         //
    uint32_t rxAlrLen;      //
    uint8_t *rxBuf;         //
    uint32_t rxAlrLanNum;
} STRU_I2C_INT_DATA;


#define SFR_PAD_CTRL7_REG (0x40B00098)


uint8_t I2C_Init(EN_I2C_COMPONENT en_component, ENUM_I2C_Mode en_i2cMode, uint16_t u16_i2cAddr, ENUM_I2C_Speed en_i2cSpeed);
uint8_t I2C_Init_Ex(EN_I2C_COMPONENT en_component, ENUM_I2C_Mode en_i2cMode, uint16_t u16_i2cAddr, ENUM_I2C_Speed en_i2cSpeed,
                       uint16_t low_count, uint16_t high_count, uint8_t fs_spk);


uint8_t I2C_Master_WriteData(EN_I2C_COMPONENT en_component, uint16_t u16_i2cAddr, uint8_t* ptr_data, uint32_t u32_dataSize);
uint8_t I2C_Master_ReadData(EN_I2C_COMPONENT en_component, uint16_t u16_i2cAddr, uint8_t* ptr_subAddr, uint8_t u8_subAddrSize, uint8_t* ptr_data, uint32_t u32_dataSize);

void I2C_Master_IntrSrvc(uint32_t u32_vectorNum);
int I2C_Master_GetBusyStatus(EN_I2C_COMPONENT en_component);
int I2C_Master_GetTxAbrtSource(EN_I2C_COMPONENT en_component);
int32_t I2C_Master_WaitTillIdle(EN_I2C_COMPONENT en_component, uint32_t timeOut);
int8_t I2C_Master_ClrTxAbrt(EN_I2C_COMPONENT en_component);

#endif



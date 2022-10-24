#ifndef QUAD_SPI_CONTROLLER_H
#define QUAD_SPI_CONTROLLER_H

//--------------------------------------------------------------------
// memory address space define here
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// memory address space define here
//--------------------------------------------------------------------
#define HP_SPI_BASE_ADDR      0x40C00000
#define HP_SPI_CMD_BASE       ( 0   )*4
#define HP_SPI_AW_MEM_BASE    ( 32  )*4
#define HP_SPI_CODE_MEM_BASE  ( 48  )*4
#define HP_SPI_CONFIG_REG     ( 112 )*4
#define HP_SPI_INIT_REG       ( 113 )*4
#define HP_SPI_RD_HW_REG      ( 114 )*4
#define HP_SPI_RD_LW_REG      ( 115 )*4
#define HP_SPI_WR_HW_REG      ( 116 )*4
#define HP_SPI_WR_LW_REG      ( 117 )*4
#define HP_SPI_UPDATE_RD_REG  ( 118 )*4
#define HP_SPI_UPDATE_WR_REG  ( 119 )*4

//-------------------------------------------------------------------
// spansion instruction address mapping
//-------------------------------------------------------------------
#define INSTRUCT_05_ADDR  ( 0 )*4
#define INSTRUCT_35_ADDR  ( 1 )*4
#define INSTRUCT_33_ADDR  ( 2 )*4
#define INSTRUCT_04_ADDR  ( 3 )*4
#define INSTRUCT_01_ADDR  ( 4 )*4
#define INSTRUCT_ab_ADDR  ( 5 )*4
#define INSTRUCT_90_ADDR  ( 6 )*4
#define INSTRUCT_9f_ADDR  ( 7 )*4
#define INSTRUCT_77_ADDR  ( 8 )*4
#define INSTRUCT_C7_ADDR  ( 9 )*4
#define INSTRUCT_75_ADDR  ( 10 )*4
#define INSTRUCT_7a_ADDR  ( 11 )*4
#define INSTRUCT_66_ADDR  ( 12 )*4
#define INSTRUCT_99_ADDR  ( 13 )*4
#define INSTRUCT_ff_ADDR  ( 14 )*4
#define INSTRUCT_b9_ADDR  ( 15 )*4
#define INSTRUCT_06_ADDR  ( 16 )*4
#define INSTRUCT_50_ADDR  ( 17 )*4
#define INSTRUCT_18_ADDR  ( 18 )*4
#define INSTRUCT_19_ADDR  ( 19 )*4
#define INSTRUCT_20_ADDR  ( 20 )*4
#define INSTRUCT_d8_ADDR  ( 21 )*4
#define INSTRUCT_5a_ADDR  ( 22 )*4
#define INSTRUCT_48_ADDR  ( 23 )*4
#define INSTRUCT_44_ADDR  ( 24 )*4
#define INSTRUCT_42_ADDR  ( 25 )*4
#define INSTRUCT_MEM_OFFSET  ( 16 )*4

#define HP_SPI_BASE_ADDR    0x40C00000
#define FLASH_APB_BASE_ADDR 0x10000000
//-------------------------------------------------------------------
// spansion instruction address mapping
//-------------------------------------------------------------------
#define CMD0                    (0*4)          //read SR1                       05h
#define CMD1                    (1*4)          //read SR2                       35h
#define CMD2                    (2*4)          //read SR3                       15h
#define CMD3                    (3*4)          //write SR1                      01h
#define CMD4                    (4*4)          //write SR2                      31h
#define CMD5                    (5*4)          //write SR3                      11h
#define CMD6                    (6*4)          //write disable                  04h
#define CMD7                    (7*4)          //write enable                   06h
#define CMD8                    (8*4)          //write enable for volatile regs 50h
#define CMD9                    (9*4)          //read Manufacturer/Device ID    90h
#define CMD10                   (10*4)         //read JEDEC ID                  9Fh
#define CMD11                   (11*4)         //chip erase                     C7h
#define CMD12                   (12*4)
#define CMD13                   (13*4)
#define CMD14                   (14*4)
#define CMD15                   (15*4)
#define CMD16                   (16*4)         //sector erase(4KB)              20h
#define CMD17                   (17*4)         //block erase(64KB)              D8h
#define CMD18                   (18*4)
#define CMD19                   (19*4)
#define CMD20                   (20*4)
#define CMD21                   (21*4)
#define CMD22                   (22*4)
#define CMD23                   (23*4)
#define CMD24                   (24*4)
#define CMD25                   (25*4)
#define CMD26                   (26*4)
#define CMD27                   (27*4)
#define CMD28                   (28*4)
#define CMD29                   (29*4)
#define CMD30                   (30*4)
#define CMD31                   (31*4)

// Addr for cmd
#define CMD16_ADDR              (32*4)
#define CMD17_ADDR              (33*4)
#define CMD18_ADDR              (34*4)
#define CMD19_ADDR              (35*4)
#define CMD20_ADDR              (36*4)
#define CMD21_ADDR              (37*4)
#define CMD22_ADDR              (38*4)
#define CMD23_ADDR              (39*4)
#define CMD24_ADDR              (40*4)
#define CMD25_ADDR              (41*4)
#define CMD26_ADDR              (42*4)
#define CMD27_ADDR              (43*4)
#define CMD28_ADDR              (44*4)
#define CMD29_ADDR              (45*4)
#define CMD30_ADDR              (46*4)
#define CMD31_ADDR              (47*4)

// Instruction
#define INSTR0_L                (48*4)
#define INSTR0_H                (49*4)
#define INSTR1_L                (50*4)
#define INSTR1_H                (51*4)
#define INSTR2_L                (52*4)
#define INSTR2_H                (53*4)
#define INSTR3_L                (54*4)
#define INSTR3_H                (55*4)
#define INSTR4_L                (56*4)
#define INSTR4_H                (57*4)
#define INSTR5_L                (58*4)
#define INSTR5_H                (59*4)
#define INSTR6_L                (60*4)
#define INSTR6_H                (61*4)
#define INSTR7_L                (62*4)
#define INSTR7_H                (63*4)
#define INSTR8_L                (64*4)
#define INSTR8_H                (65*4)
#define INSTR9_L                (66*4)
#define INSTR9_H                (67*4)
#define INSTR10_L               (68*4)
#define INSTR10_H               (69*4)
#define INSTR11_L               (70*4)
#define INSTR11_H               (71*4)
#define INSTR12_L               (72*4)
#define INSTR12_H               (73*4)
#define INSTR13_L               (74*4)
#define INSTR13_H               (75*4)
#define INSTR14_L               (76*4)
#define INSTR14_H               (77*4)
#define INSTR15_L               (78*4)
#define INSTR15_H               (79*4)
#define INSTR16_L               (80*4)
#define INSTR16_H               (81*4)
#define INSTR17_L               (82*4)
#define INSTR17_H               (83*4)
#define INSTR18_L               (84*4)
#define INSTR18_H               (85*4)
#define INSTR19_L               (86*4)
#define INSTR19_H               (87*4)
#define INSTR20_L               (88*4)
#define INSTR20_H               (89*4)
#define INSTR21_L               (90*4)
#define INSTR21_H               (91*4)
#define INSTR22_L               (92*4)
#define INSTR22_H               (93*4)
#define INSTR23_L               (94*4)
#define INSTR23_H               (95*4)
#define INSTR24_L               (96*4)
#define INSTR24_H               (97*4)
#define INSTR25_L               (98*4)
#define INSTR25_H               (99*4)
#define INSTR26_L               (100*4)
#define INSTR26_H               (101*4)
#define INSTR27_L               (102*4)
#define INSTR27_H               (103*4)
#define INSTR28_L               (104*4)
#define INSTR28_H               (105*4)
#define INSTR29_L               (106*4)
#define INSTR29_H               (107*4)
#define INSTR30_L               (108*4)
#define INSTR30_H               (109*4)
#define INSTR31_L               (110*4)
#define INSTR31_H               (111*4)


typedef enum
{
    QUAD_SPI_INSTR_0 = 0,
    QUAD_SPI_INSTR_1,
    QUAD_SPI_INSTR_2,
    QUAD_SPI_INSTR_3,
    QUAD_SPI_INSTR_4,
    QUAD_SPI_INSTR_5,
    QUAD_SPI_INSTR_6,
    QUAD_SPI_INSTR_7,
    QUAD_SPI_INSTR_8,
    QUAD_SPI_INSTR_9,
    QUAD_SPI_INSTR_10,
    QUAD_SPI_INSTR_11,
    QUAD_SPI_INSTR_12,
    QUAD_SPI_INSTR_13,
    QUAD_SPI_INSTR_14,
    QUAD_SPI_INSTR_15,
    QUAD_SPI_INSTR_16,
    QUAD_SPI_INSTR_17,
    QUAD_SPI_INSTR_18,
    QUAD_SPI_INSTR_19,
    QUAD_SPI_INSTR_20,
    QUAD_SPI_INSTR_21,
    QUAD_SPI_INSTR_22,
    QUAD_SPI_INSTR_23,
    QUAD_SPI_INSTR_24,
    QUAD_SPI_INSTR_25,
    QUAD_SPI_INSTR_26,
    QUAD_SPI_INSTR_27,
    QUAD_SPI_INSTR_28,
    QUAD_SPI_INSTR_29,
    QUAD_SPI_INSTR_30,
    QUAD_SPI_INSTR_31,
    QUAD_SPI_INSTR_UNKNOWN,
} ENUM_QUAD_SPI_INSTR_ID;

typedef enum
{
    QUAD_SPI_SPEED_25M = 0,
    QUAD_SPI_SPEED_50M,
    QUAD_SPI_SPEED_100M,
    QUAD_SPI_SPEED_25M_ENCRYPT,
    QUAD_SPI_SPEED_50M_ENCRYPT,
    QUAD_SPI_SPEED_100M_ENCRYPT,
    QUAD_SPI_SPEED_UNKNOWN,
} ENUM_QUAD_SPI_SPEED;

void QUAD_SPI_EnableDefaultInstruct(void);
uint8_t QUAD_SPI_UpdateInstruct(ENUM_QUAD_SPI_INSTR_ID instr_id, uint32_t cmd_h, uint32_t cmd_l);
uint8_t QUAD_SPI_ReadInstruct(ENUM_QUAD_SPI_INSTR_ID instr_id, uint32_t * cmd_h, uint32_t * cmd_l);

uint8_t QUAD_SPI_WriteEnable(void);
uint8_t QUAD_SPI_WriteDisable(void);

void QUAD_SPI_CheckBusy(void);

uint8_t QUAD_SPI_BlockErase(uint32_t flash_blk_st_addr);
uint8_t QUAD_SPI_SectorErase(uint32_t flash_sect_st_addr);
uint8_t QUAD_SPI_ChipErase(void);

uint8_t QUAD_SPI_WriteByte(uint32_t flash_addr, uint8_t value);
uint8_t QUAD_SPI_WriteHalfWord(uint32_t flash_addr, uint16_t value);
uint8_t QUAD_SPI_WriteWord(uint32_t flash_addr, uint32_t value);
uint8_t QUAD_SPI_WriteBlockByByte(uint32_t flash_blk_st_addr, uint8_t* blk_val_table, uint32_t byte_size);
uint8_t QUAD_SPI_WriteBlockByHalfWord(uint32_t flash_blk_st_addr, uint16_t* blk_val_table, uint32_t halfword_size);
uint8_t QUAD_SPI_WriteBlockByWord(uint32_t flash_blk_st_addr, uint32_t* blk_val_table, uint32_t word_size);

uint8_t QUAD_SPI_ReadByte(uint32_t flash_addr, uint8_t* value_ptr);
uint8_t QUAD_SPI_ReadHalfWord(uint32_t flash_addr, uint16_t* value_ptr);
uint8_t QUAD_SPI_ReadWord(uint32_t flash_addr, uint32_t* value_ptr);
void QUAD_SPI_ReadBlockByByte(uint32_t flash_blk_st_addr, uint8_t* blk_val_table, uint32_t byte_size);

uint8_t QUAD_SPI_SetSpeed(ENUM_QUAD_SPI_SPEED speed);

uint32_t QUAD_SPI_ReadStatusReg1(void);
uint32_t QUAD_SPI_ReadStatusReg2(void);

void QUAD_SPI_SetStatusReg1(uint8_t flag);
void QUAD_SPI_SetStatusReg2(uint16_t flag);

void QUAD_SPI_ReadManuDeviceID(uint8_t* data_buf, uint8_t buflen);
void QUAD_SPI_ReadJEDECID(uint8_t* data_buf, uint8_t buflen);
//void QUAD_SPI_ReadProductID(uint8_t* data_buf);

#endif


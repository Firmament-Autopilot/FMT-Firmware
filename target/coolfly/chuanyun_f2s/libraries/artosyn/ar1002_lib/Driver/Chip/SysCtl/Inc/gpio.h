//==================================================
// GPIO Driver
//==================================================

#ifndef _GPIO_H
#define _GPIO_H
#define GPIO_NUM_PINS      				(128)
#define MULTIPLE           				(0)   

#define GPIO_MODE_0     				(0x0)
#define GPIO_MODE_1                     (0x1)
#define GPIO_MODE_2     				(0x2)


#define GPIO0_BASE_ADDR                 0x40400000
#define GPIO1_BASE_ADDR                 0x40440000
#define GPIO2_BASE_ADDR                 0x40480000
#define GPIO3_BASE_ADDR                 0x404C0000

#define GPIO_MODE0_ADDR    			    0x40B0007C //0 -15
#define GPIO_MODE1_ADDR    			    0x40B00080 //16-31
#define GPIO_MODE2_ADDR    			    0x40B00084 //32-47
#define GPIO_MODE3_ADDR    			    0x40B00088 //48-63
#define GPIO_MODE4_ADDR    			    0x40B0008C //64-79
#define GPIO_MODE5_ADDR    			    0x40B00090 //80-95
#define GPIO_MODE6_ADDR    			    0x40B00094 //96-111
#define GPIO_MODE7_ADDR    			    0x40B00098 //112-127

#define GPIO_DATA_A_OFFSET              0x00
#define GPIO_DATA_B_OFFSET              0x0C
#define GPIO_DATA_C_OFFSET              0x18
#define GPIO_DATA_D_OFFSET              0x24

#define GPIO_DATA_DIRECT_A_OFFSET       0x04
#define GPIO_DATA_DIRECT_B_OFFSET       0x10
#define GPIO_DATA_DIRECT_C_OFFSET       0x1C
#define GPIO_DATA_DIRECT_D_OFFSET       0x28

#define GPIO_DATA_DIRECT_INPUT          (0)
#define GPIO_DATA_DIRECT_OUTPUT         (1)

#define GPIO_CTRL_A_OFFSET              0x08
#define GPIO_CTRL_B_OFFSET              0x14
#define GPIO_CTRL_C_OFFSET              0x20
#define GPIO_CTRL_D_OFFSET              0x2C

#define GPIO_CTRL_SOFTWARE				(0)
#define GPIO_CTRL_HARDWARE              (1)
  
#define GPIO_EXT_PORT_A_OFFSET          0x50
#define GPIO_EXT_PORT_B_OFFSET          0x54
#define GPIO_EXT_PORT_C_OFFSET          0x58
#define GPIO_EXT_PORT_D_OFFSET          0x5C
  
#define GPIO_INTEN_OFFSET               0x30
#define GPIO_INTEN_NORMAL               (0)
#define GPIO_INTEN_INTERRUPT            (1)

#define GPIO_MASK_OFFSET                0x34
#define GPIO_MASK_MASK                  (0)
#define GPIO_MASK_UNMASK                (1)
  
#define GPIO_INTTYPE_OFFSET             0x38
#define GPIO_INTTYPE_LEVEL              (0)
#define GPIO_INTTYPE_EDGE               (1)
  
#define GPIO_INTPOL_OFFSET              0x3C
#define GPIO_INTPOL_LOW                 (0)
#define GPIO_INTPOL_HIGH                (1)
  
#define GPIO_DEBOUNCE_OFFSET            0x48
#define GPIO_DEBOUNCE_OFF               (0)
#define GPIO_DEBOUNCE_ON                (1)
  
#define GPIO_INTSTATUS_OFFSET           0x40
#define GPIO_RAW_INTSTATUS_OFFSET       0x44
#define GPIO_CLEARINT_OFFSET            0x4C

void GPIO_SetPin(uint32_t gpioNum, uint32_t value);
uint32_t GPIO_GetPin(uint32_t gpioNum);

void GPIO_SetPinHi(uint32_t gpioNum);
void GPIO_SetPinLo(uint32_t gpioNum);
void GPIO_SetMode(uint32_t gpioNum, uint32_t mode);
#if MULTIPLE
void GPIO_SetPinListList(uint32_t *pList, uint32_t size, uint32_t *mode);
void GPIO_SetPinListVal(uint32_t *pList, uint32_t size, uint32_t mode);
void GPIO_SetPinRange(uint32_t gpioNum1, uint32_t gpioNum2, uint32_t mode);

void GPIO_ModeRange(uint32_t gpioNum1, uint32_t gpioNum2,uint32_t mode);
void GPIO_ModeListVal(uint32_t *pList, uint32_t size, uint32_t mode);
void GPIO_ModeListList(uint32_t *gpioList, uint32_t size, uint32_t *modeList);
#endif
void GPIO_SetPinDirect(uint32_t gpioNum, uint32_t mode);
void GPIO_SetPinCtrl(uint32_t gpioNum, uint32_t mode);
void GPIO_Intr_SetPinIntrEn(uint32_t gpioNum, uint32_t mode);
void GPIO_Intr_SetPinIntrMask(uint32_t gpioNum, uint32_t mode);
void GPIO_Intr_SetPinIntrType(uint32_t gpioNum, uint32_t mode);
void GPIO_Intr_SetPinIntrPol(uint32_t gpioNum, uint32_t mode);
uint32_t GPIO_Intr_GetIntrStatus(uint32_t gpioNum);
uint32_t GPIO_Intr_GetRawIntrStatus(uint32_t gpioNum);
void GPIO_Intr_ClearIntr(uint32_t gpioNum);
uint32_t GPIO_Intr_GetIntrGroupStatus(uint32_t u32_vectorNum);
void GPIO_Intr_ClearIntrGroup(uint32_t u32_vectorNum, uint8_t u8_flag);

#endif

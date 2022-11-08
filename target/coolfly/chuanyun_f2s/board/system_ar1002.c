


// #include  "ar1002_hal.h"
#include  "ar8020.h"
#include  "core_cm7.h"

/************************* Miscellaneous Configuration ************************/

/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x0000 /*!< Vector Table base offset field. 
                                   This value must be a multiple of 0x200. */
/******************************************************************************/


/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the 
  *         SystemFrequency variable.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  SCB->VTOR = 0x00000000UL; /* Vector Table Relocation in Internal FLASH */
}


void SystemCoreClockUpdate(void)
{

}

/************************ (C) COPYRIGHT chuanyun *****END OF FILE****/

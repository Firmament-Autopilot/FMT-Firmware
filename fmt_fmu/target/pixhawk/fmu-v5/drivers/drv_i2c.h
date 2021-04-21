#ifndef __DRV_I2C_H__
#define __DRV_I2C_H__

#include <firmament.h>
#include "bsp.h"

#ifdef __cplusplus
extern "C" {
#endif

/* i2c slave device addresses */
#define IST8310_ADDRESS                 0x1C

int rt_i2c_hw_init(void);


#ifdef __cplusplus
}
#endif

#endif

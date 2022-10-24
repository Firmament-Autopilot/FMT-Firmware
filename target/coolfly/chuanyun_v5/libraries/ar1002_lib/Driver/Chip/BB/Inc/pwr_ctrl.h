#ifndef __PWR_CTRL_H__
#define __PWR_CTRL_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "debuglog.h"
#include "bb_types.h"


int PWR_CTRL_Init(STRU_PWR_CTRL *ctrl);

void PWR_CTRL_ModeSet(STRU_PWR_CTRL *ctrl);


#ifdef __cplusplus
}
#endif 

#endif

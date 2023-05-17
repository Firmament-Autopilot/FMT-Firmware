/*
 * Author: Pedro Pereira
 */

#ifndef CANARD_STM32_FDCAN_H
#define CANARD_STM32_FDCAN_H

#include <stm32h7xx.h> // TODO: substitute include for independent variable and macro declaration

typedef FDCAN_GlobalTypeDef FdCANType;

/**
 * CANx register sets
 */
#define FDCAN_1 ((volatile FdCANType*)0x4000A000UL)
#define FDCAN_2 ((volatile FdCANType*)0x4000A400UL)

#define FDCAN_IDE       (0x40000000UL) // Identifier Extension
#define FDCAN_STID_MASK (0x1FFC0000UL) // Standard Identifier Mask
#define FDCAN_EXID_MASK (0x1FFFFFFFUL) // Extended Identifier Mask
#define FDCAN_RTR       (0x20000000UL) // Remote Transmission Request
#define FDCAN_DLC_MASK  (0x000F0000UL) // Data Length Code

#endif                                 // CANARD_STM32_FDCAN_H

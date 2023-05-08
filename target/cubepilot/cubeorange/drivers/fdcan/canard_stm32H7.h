/*
 * Copyright (c) 2017 UAVCAN Team
 *
 * Distributed under the MIT License, available in the file LICENSE.
 *
 * Author: Pavel Kirienko <pavel.kirienko@zubax.com>
 */

#ifndef CANARD_STM32_H
#define CANARD_STM32_H

#include <canard.h>
#include <string.h> // NOLINT

#include "_internal_fdcan.h"

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------------------------------User Config Macros-------------------------------------------*/

// Set this build config macro to 1 if using FreeRTOS
#if !defined(UAVCAN_STM32_FREERTOS)
    #define UAVCAN_STM32_FREERTOS 0
#endif

// Set this build config macro to 1 if app not using any OS
#if !defined(UAVCAN_STM32_BAREMETAL)
    #define UAVCAN_STM32_BAREMETAL 1
#endif

// Define number of CAN interfaces to use (1 (only FDCAN1) or 2 (FDCAN1 and FDCAN2))
#define FDCAN_NUM_IFACES 1

#define FDCAN_NUM_RXFIFO0_SIZE    104U // 26 Frames
#define FDCAN_TX_FIFO_BUFFER_SIZE 128U // 32 Frames

/*---------------------------------------------------------------------------------------------------------*/

// Buffer size for 8 bytes data field
#define FDCAN_FRAME_BUFFER_SIZE 4U

// FDCan Memory RAM has 10KB of available dynamic memory use starting at 0x4000AC00
#define MESSAGE_RAM_END_ADDR (0x4000D3FCUL)

// This is defined by the fdCAN hardware.
// Each FDCAN instance can have up to 128 element Standard Filter List elements or 64 element Extended Filter List
#define MAX_FILTER_LIST_SIZE 128U

// if it takes longer than 100ms for setting a register we have failed
#define REG_SET_TIMEOUT 100U

// Number of TX mailboxes for each fdCAN instance
#define NUM_TX_MAILBOXES 32U

/**
 * Driver error codes.
 * These values are returned negated from API functions that return int.
 */
#define CANARD_STM32_ERROR_UNSUPPORTED_BIT_RATE     1000
#define CANARD_STM32_ERROR_LOGIC                    1001
#define CANARD_STM32_ERROR_UNSUPPORTED_FRAME_FORMAT 1002
#define CANARD_STM32_ERROR_FILTER_NUM_CONFIGS       1003
#define CANARD_STM32_ERROR_SET_REG_TIMEOUT          1004

// Definition of minimum function with safe type feature
#define MIN(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct
{
    uint32_t StandardFilterSA;
    uint32_t ExtendedFilterSA;
    uint32_t RxFIFO0SA;
    uint32_t RxFIFO1SA;
    uint32_t TxFIFOQSA;
    uint32_t EndAddress;
} FdCANMessageRAM;

/**
 * ID and Mask of a hardware acceptance filter.
 * The ID and Mask fields support flags @ref CANARD_CAN_FRAME_EFF and @ref CANARD_CAN_FRAME_RTR.
 */
typedef struct
{
    uint32_t id;
    uint32_t mask;
} FdCANFilterConfig;

/**
 * These parameters define the timings of the CAN controller.
 * Please refer to the documentation of the CAN macrocell for explanation.
 * These values can be computed by the developed beforehand if ROM size is of a concern,
 * or they can be computed at run time using the function defined below.
 */
typedef struct
{
    uint16_t bit_rate_prescaler;              /// [1, 1024]
    uint8_t bit_segment_1;                    /// [1, 16]
    uint8_t bit_segment_2;                    /// [1, 8]
    uint8_t max_resynchronization_jump_width; /// [1, 4] (recommended value is 1)
} FdCANTimings;

typedef struct
{
    volatile FdCANType* fdcan_base;
    FdCANMessageRAM MessageRam;
    uint64_t error_cnt;
    uint32_t served_aborts_cnt;
    uint64_t rx_overflow_count;
    uint64_t TxItem_deadline[NUM_TX_MAILBOXES];
    bool TxItem_abort_on_error[NUM_TX_MAILBOXES];
} FdCANIface;

typedef enum {
    can1 = 0,
    can2 = 1
} FDCanID;

/**
 * Initializes the CAN controller at the specified bit rate.
 * The auto abort mode is needed for dynamic node ID allocation procedure; please refer to the UAVCAN specification
 * for more information about this topic.
 *
 * This function can be invoked any number of times; every invocation re-initializes everything from scratch.
 *
 * WARNING: The clock of the CAN module must be enabled before this function is invoked!
 *          If CAN2 is used, CAN1 must be also enabled!
 *
 * WARNING: The driver is not thread-safe!
 *          It does not use IRQ or critical sections though, so it is safe to invoke its API functions from the
 *          IRQ context from the application.
 *
 * @retval      0               Success
 * @retval      negative        Error
 */
int16_t fdCANInit(const FdCANTimings timings, //
                  const FDCanID iface);

/**
 * Pushes one frame into the TX buffer, if there is space.
 * Note that proper care is taken to ensure that no inner priority inversion is taking place.
 * This function does never block.
 *
 * @retval      1               Transmitted successfully
 * @retval      0               No space in the buffer
 * @retval      negative        Error
 */
int16_t fdCANTransmit(const FDCanID iface,               //
                      const uint64_t current_time,       //
                      const uint64_t deadline,           //
                      const CanardCANFrame* const frame, //
                      bool abort_on_error);

/**
 * Reads one frame from the hardware RX FIFO, unless all FIFO are empty.
 * This function does never block.
 *
 * @retval      1               Read successfully
 * @retval      0               The buffer is empty
 * @retval      negative        Error
 */
int16_t fdCANReceive(const FDCanID iface, //
                     CanardCANFrame* const out_frame);

/**
 * Sets up acceptance filters according to the provided list of ID and masks.
 * Note that when the interface is reinitialized, hardware acceptance filters are reset.
 * Also note that during filter reconfiguration, some RX frames may be lost.
 *
 * Setting zero filters will result in rejection of all frames.
 * In order to accept all frames, set one filter with ID = Mask = 0, which is also the default configuration.
 *
 * @retval      0               Success
 * @retval      negative        Error
 */
int16_t fdCANConfigureFilters(const uint8_t iface_index, //
                              const FdCANFilterConfig filter_configs[MAX_FILTER_LIST_SIZE]);

/**
 * Returns the error count of CAN msgs.
 */
uint64_t fdCANGetErrorCount(const FDCanID iface);

/**
 * Given the rate of the clock supplied to the fdCAN macrocell and the desired bit rate,
 * this function iteratively solves for the best possible timing settings. The CAN bus timing parameters,
 * such as the sample point location, the number of time quantas per bit, etc., are optimized according to the
 * recommendations provided in the specifications of UAVCAN, DeviceNet, and CANOpen.
 *
 * Unless noted otherwise, all units are SI units; particularly, frequency is specified in hertz.
 *
 * The implementation is adapted from libuavcan.
 *
 * This function is defined in the header in order to encourage the linker to discard it if it is not used.
 *
 * @retval 0            Success
 * @retval negative     Solution could not be found for the provided inputs.
 */
int16_t fdCANComputeTimings(const uint32_t peripheral_clock_rate, //
                            const uint32_t target_bitrate,        //
                            FdCANTimings* const out_timings);

#ifdef __cplusplus
}
#endif
#endif

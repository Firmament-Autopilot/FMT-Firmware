/*
 * canard_stm32_fdcan.c
 *
 *  Created on: 11 Jan 2022
 *      Author: Pedro Pereira
 */

#include "canard_stm32H7.h"

#include <assert.h>

// Configure the maximum interface index for the fdCAN hardware available in your MCU.
// Must be set to either 0 (only FDCAN1) or 1 (FDCAN1 and FDCAN2).
#if !(FDCAN_NUM_IFACES == 1) && !(FDCAN_NUM_IFACES == 2)
    #error "Please set FDCAN_NUM_IFACES to either 1 (only FDCAN1) or 2 (FDCAN1 and FDCAN2)." //NOLINT
#endif

// Configure the maximum interface index for the fdCAN hardware available in your MCU.
// Must be set to either 0 (only FDCAN1) or 1 (FDCAN1 and FDCAN2).
#if (UAVCAN_STM32_BAREMETAL == 1) == (UAVCAN_STM32_FREERTOS == 1)
    #error "Please set to 1 UAVCAN_STM32_BAREMETAL or UAVCAN_STM32_FREERTOS." //NOLINT
#endif

#if UAVCAN_STM32_FREERTOS
    #include <cmsis_os2.h>
#endif

#if UAVCAN_STM32_FREERTOS
    #define CAN_TIMEOUT (REG_SET_TIMEOUT * osKernelGetSysTimerFreq() / 1000000U)
    #define SYS_TIMER   osKernelGetSysTimerCount()
#elif UAVCAN_STM32_BAREMETAL
    #define CAN_TIMEOUT REG_SET_TIMEOUT
    #define SYS_TIMER   HAL_GetTick()
#endif

// By default, this macro resolves to the standard assert(). The user can redefine this if necessary.
// To disable assertion checks completely, make it expand into `(void)(0)`.
#ifndef CANARD_ASSERT
    // Intentional violation of MISRA: assertion macro cannot be replaced with a function definition.
    #define CANARD_ASSERT(x) assert(x)
#endif

static FdCANIface canIface_[FDCAN_NUM_IFACES];

static uint32_t FDCANMessageRAMOffset = 0;

/// Converts libcanard ID value into the fdCAN TX ID register format.
static uint32_t convertFrameIDToRegister(const uint32_t id)
{
    uint32_t out = 0;

    if (id & CANARD_CAN_FRAME_EFF)
        out = (FDCAN_IDE | id);
    else
        out = (id << 18U);

    if (id & CANARD_CAN_FRAME_RTR)
        out |= FDCAN_RTR;

    return out;
}

/// Converts fdCAN TX/RX ID register value into the libcanard ID format.
static uint32_t convertFrameIDRegisterToCanard(const uint32_t id)
{
    uint32_t out = 0;

    if (!(id & FDCAN_IDE))
        out = ((id & FDCAN_STID_MASK) >> 18) & CANARD_CAN_STD_ID_MASK;
    else
        out = ((id & FDCAN_EXID_MASK) & CANARD_CAN_EXT_ID_MASK) | CANARD_CAN_FRAME_EFF;

    if (id & FDCAN_RTR)
        out |= CANARD_CAN_FRAME_RTR;

    return out;
}

/// Handle TX/RX errors. Also abort pending TX buffers while in bus-off mode. Errors are reported.
static void processErrorStatus(const uint8_t iface_index)
{
    CANARD_ASSERT(iface_index < FDCAN_NUM_IFACES); // Valid fdcan base index.

    // Aborting TX transmissions if abort on error was requested
    // Updating error counter
    const uint8_t cel = (uint8_t)(canIface_[iface_index].fdcan_base->ECR >> 16);

    if (cel != 0) {
        for (uint8_t i = 0U; i < NUM_TX_MAILBOXES; i++) {
            // Abort pending transmissions if auto abort on error is enabled, or if we're in bus off mode
            // Also reset the TX mailbox timeouts for the selected interface.
            if (!(canIface_[iface_index].TxItem_abort_on_error[i]) && !(canIface_[iface_index].fdcan_base->PSR & FDCAN_PSR_BO))
                continue;
            if (((1 << i) & canIface_[iface_index].fdcan_base->TXBRP)) {
                canIface_[iface_index].fdcan_base->TXBCR = 1 << i;
                canIface_[iface_index].error_cnt++;
                canIface_[iface_index].served_aborts_cnt++;
                canIface_[iface_index].TxItem_deadline[i] = UINT64_MAX;
            }
        }
    }
}

/// Detect TX mailbox slots that have expired and abort them.
static void abortExpiredTxMailboxes(const uint8_t iface_index, //
                                    const uint64_t current_time)
{
    CANARD_ASSERT(iface_index < FDCAN_NUM_IFACES); // Valid fdcan base index.

    // Check the deadline for each active mailbox.
    for (uint8_t i = 0U; i < NUM_TX_MAILBOXES; i++) {
        // Abort the selected mailbox if it is busy and its deadline has expired. This frees-up stale
        // slots and the timeout error is reported.
        // However, if the slot was not busy, we only reset the deadline to UINT64_MAX, as this only indicates
        // a previously-sent, idle slot that needs its old deadline cleared. This is not an error.
        if (current_time > canIface_[iface_index].TxItem_deadline[i]) {
            canIface_[iface_index].TxItem_deadline[i] = UINT64_MAX; // Clear the TX deadline for the selected mailbox.

            // If the slot is pending, abort the transmission and report a time-out error.
            if ((1 << i) & canIface_[iface_index].fdcan_base->TXBRP) {
                canIface_[iface_index].fdcan_base->TXBCR |= (1 << i); // Abort the selected mailbox.
                canIface_[iface_index].error_cnt++;                   // TX timeout error occurred.
            }
        }
    }
}

/// Setup RAM for FDCan. This reserved RAM space makes the CPU more efficient.
static void setupMessageRam(const uint8_t iface_index)
{
    CANARD_ASSERT(iface_index < FDCAN_NUM_IFACES); // Valid fdcan base index.

    uint32_t num_elements = 0;

    // Rx FIFO 0 start address and element count
    num_elements = MIN((FDCAN_NUM_RXFIFO0_SIZE / FDCAN_FRAME_BUFFER_SIZE), 64U);
    if (num_elements) {
        canIface_[iface_index].fdcan_base->RXF0C = (((canIface_[iface_index].fdcan_base->RXF0C) & (~(FDCAN_RXF0C_F0SA))) | (FDCANMessageRAMOffset << FDCAN_RXF0C_F0SA_Pos));
        canIface_[iface_index].fdcan_base->RXF0C = (((canIface_[iface_index].fdcan_base->RXF0C) & (~(FDCAN_RXF0C_F0S))) | (num_elements << FDCAN_RXF0C_F0S_Pos));
        canIface_[iface_index].MessageRam.RxFIFO0SA = SRAMCAN_BASE + (FDCANMessageRAMOffset * 4U);
        FDCANMessageRAMOffset += num_elements * FDCAN_FRAME_BUFFER_SIZE;
    }
    // Tx FIFO/queue start address and element count
    num_elements = MIN((FDCAN_TX_FIFO_BUFFER_SIZE / FDCAN_FRAME_BUFFER_SIZE), 32U);
    if (num_elements) {
        canIface_[iface_index].fdcan_base->TXBC = (((canIface_[iface_index].fdcan_base->TXBC) & (~(FDCAN_TXBC_TBSA))) | (FDCANMessageRAMOffset << FDCAN_TXBC_TBSA_Pos));
        canIface_[iface_index].fdcan_base->TXBC = (((canIface_[iface_index].fdcan_base->TXBC) & (~(FDCAN_TXBC_TFQS))) | (num_elements << FDCAN_TXBC_TFQS_Pos));
        canIface_[iface_index].MessageRam.TxFIFOQSA = SRAMCAN_BASE + (FDCANMessageRAMOffset * 4U);
        FDCANMessageRAMOffset += num_elements * FDCAN_FRAME_BUFFER_SIZE;
    }
    canIface_[iface_index].MessageRam.EndAddress = SRAMCAN_BASE + (FDCANMessageRAMOffset * 4U);
    if (canIface_[iface_index].MessageRam.EndAddress > MESSAGE_RAM_END_ADDR) {
        // We are overflowing the limit of Allocated Message RAM
        __ASM volatile("BKPT #10");
        return;
    }
}

uint64_t fdCANGetErrorCount(const FDCanID iface)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.

    return canIface_[iface].error_cnt + canIface_[iface].rx_overflow_count;
}

int16_t fdCANComputeTimings(const uint32_t peripheral_clock_rate, //
                            const uint32_t target_bitrate,        //
                            FdCANTimings* const out_timings)
{
    if (target_bitrate < 1000)
        return -CANARD_STM32_ERROR_UNSUPPORTED_BIT_RATE;

    CANARD_ASSERT(out_timings != NULL);           // NOLINT
    memset(out_timings, 0, sizeof(*out_timings)); // NOLINT

    // Hardware configuration
    static const uint8_t MaxBS1 = 16U;
    static const uint8_t MaxBS2 = 8U;

    /*
     * Ref. "Automatic Baudrate Detection in CANopen Networks", U. Koppe, MicroControl GmbH & Co. KG
     *      CAN in Automation, 2003
     *
     * According to the source, optimal quanta per bit are:
     *   Bitrate        Optimal Maximum
     *   1000 kbps      8       10
     *   500  kbps      16      17
     *   250  kbps      16      17
     *   125  kbps      16      17
     */
    const uint8_t max_quanta_per_bit = (uint8_t)((target_bitrate >= 1000000) ? 10 : 17); // NOLINT
    CANARD_ASSERT(max_quanta_per_bit <= (MaxBS1 + MaxBS2));

    static const uint16_t MaxSamplePointLocationPermill = 900;

    /*
     * Computing (prescaler * BS):
     *   BITRATE = 1 / (PRESCALER * (1 / PCLK) * (1 + BS1 + BS2))       -- See the Reference Manual
     *   BITRATE = PCLK / (PRESCALER * (1 + BS1 + BS2))                 -- Simplified
     * let:
     *   BS = 1 + BS1 + BS2                                             -- Number of time quanta per bit
     *   PRESCALER_BS = PRESCALER * BS
     * ==>
     *   PRESCALER_BS = PCLK / BITRATE
     */
    const uint32_t prescaler_bs = peripheral_clock_rate / target_bitrate;

    /*
     * Searching for such prescaler value so that the number of quanta per bit is highest.
     */
    uint8_t bs1_bs2_sum = (uint8_t)(max_quanta_per_bit - 1); // NOLINT

    while ((prescaler_bs % (1U + bs1_bs2_sum)) != 0) {
        if (bs1_bs2_sum <= 2)
            return -CANARD_STM32_ERROR_UNSUPPORTED_BIT_RATE; // No solution

        bs1_bs2_sum--;
    }

    const uint32_t prescaler = prescaler_bs / (1U + bs1_bs2_sum);
    if ((prescaler < 1U) || (prescaler > 1024U))
        return -CANARD_STM32_ERROR_UNSUPPORTED_BIT_RATE; // No solution

    /*
     * Now we have a constraint: (BS1 + BS2) == bs1_bs2_sum.
     * We need to find such values so that the sample point is as close as possible to the optimal value,
     * which is 87.5%, which is 7/8.
     *
     *   Solve[(1 + bs1)/(1 + bs1 + bs2) == 7/8, bs2]  (* Where 7/8 is 0.875, the recommended sample point location *)
     *   {{bs2 -> (1 + bs1)/7}}
     *
     * Hence:
     *   bs2 = (1 + bs1) / 7
     *   bs1 = (7 * bs1_bs2_sum - 1) / 8
     *
     * Sample point location can be computed as follows:
     *   Sample point location = (1 + bs1) / (1 + bs1 + bs2)
     *
     * Since the optimal solution is so close to the maximum, we prepare two solutions, and then pick the best one:
     *   - With rounding to nearest
     *   - With rounding to zero
     */
    uint8_t bs1 = (uint8_t)(((7 * bs1_bs2_sum - 1) + 4) / 8); // Trying rounding to nearest first  // NOLINT
    uint8_t bs2 = (uint8_t)(bs1_bs2_sum - bs1);               // NOLINT
    CANARD_ASSERT(bs1_bs2_sum > bs1);

    {
        const uint16_t sample_point_permill = (uint16_t)(1000U * (1U + bs1) / (1U + bs1 + bs2)); // NOLINT

        if (sample_point_permill > MaxSamplePointLocationPermill)                                // Strictly more!
        {
            bs1 = (uint8_t)((7 * bs1_bs2_sum - 1) / 8);                                          // Nope, too far; now rounding to zero
            bs2 = (uint8_t)(bs1_bs2_sum - bs1);
        }
    }

    const bool valid = (bs1 >= 1) && (bs1 <= MaxBS1) && (bs2 >= 1) && (bs2 <= MaxBS2);

    /*
     * Final validation
     * Helpful Python:
     * def sample_point_from_btr(x):
     *     assert 0b0011110010000000111111000000000 & x == 0
     *     ts2,ts1,brp = (x>>20)&7, (x>>16)&15, x&511
     *     return (1+ts1+1)/(1+ts1+1+ts2+1)
     */
    if ((target_bitrate != (peripheral_clock_rate / (prescaler * (1U + bs1 + bs2)))) || !valid) {
        // This actually means that the algorithm has a logic error, hence assert(0).
        CANARD_ASSERT(0); // NOLINT
        return -CANARD_STM32_ERROR_LOGIC;
    }

    out_timings->bit_rate_prescaler = (uint16_t)prescaler;
    out_timings->max_resynchronization_jump_width = 1; // One is recommended by UAVCAN, CANOpen, and DeviceNet
    out_timings->bit_segment_1 = bs1;
    out_timings->bit_segment_2 = bs2;

    return 0;
}

// #include <firmament.h>

int16_t fdCANTransmit(const FDCanID iface,               //
                      const uint64_t current_time,       //
                      const uint64_t deadline,           //
                      const CanardCANFrame* const frame, //
                      bool abort_on_error)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.

    // Registers any error states for the selected CAN interface. It also handles the requirement
    // to automatically abort all pending transmissions if the CAN controller enters the bus-off state.
    processErrorStatus(iface);

    // Validate the other inputs.
    if (frame == NULL)
        return -CANARD_ERROR_INVALID_ARGUMENT;

    // printf("frame->data_len=%d\n",frame->data_len);

    if (frame->data_len > CANARD_CAN_FRAME_MAX_DATA_LEN)
        return -CANARD_STM32_ERROR_UNSUPPORTED_FRAME_FORMAT; // Payload size for classic CAN must be <= 8 bytes.

    // printf("2");

    if ((frame->data_len > 0U) && (frame->data == NULL))
        return -CANARD_STM32_ERROR_UNSUPPORTED_FRAME_FORMAT; // NULL pointer payload with non-zero payload size.

    // printf("3");

    if (frame->id & CANARD_CAN_FRAME_ERR)
        return -CANARD_STM32_ERROR_UNSUPPORTED_FRAME_FORMAT;
        

    // When the frame that should be transmitted is already expired (current_time > deadline), discard it. It would
    // be rejected at reception, and thus causes undue overhead and bus load. When an expired frame is discarded,
    // the TX timeout error is registered, and true is returned (the frame is considered sent).
    if (current_time > deadline) {
        canIface_[iface].error_cnt++; // TX timeout error occurred.
        return 1;                     // We must return 1 when discarding the frame. It is considered sent.
    }

    // Abort mailboxes with an expired deadline. This frees-up stale slots.
    abortExpiredTxMailboxes(iface, current_time);

    // Checking if we can accept new TX Frame
    if (!(canIface_[iface].fdcan_base->TXBC & FDCAN_TXBC_TFQS))
        return 0; // Tx FIFO is not allocated

    if ((canIface_[iface].fdcan_base->TXFQS & FDCAN_TXFQS_TFQF))
        return 0; // we don't have free space

    // Seeking an empty slot
    uint8_t index = ((canIface_[iface].fdcan_base->TXFQS & FDCAN_TXFQS_TFQPI) >> FDCAN_TXFQS_TFQF_Pos);

    CANARD_ASSERT(index < NUM_TX_MAILBOXES); // Index check - the value must be correct here

    // Copy Frame to RAM
    // Calculate Tx element address
    uint32_t* buffer = (uint32_t*)(canIface_[iface].MessageRam.TxFIFOQSA + (index * FDCAN_FRAME_BUFFER_SIZE * 4));

    // Set the TX deadline for the selected memory index.
    canIface_[iface].TxItem_deadline[index] = deadline;
    canIface_[iface].TxItem_abort_on_error[index] = abort_on_error;

    // Setup Frame ID
    buffer[0] = convertFrameIDToRegister(frame->id);

    // Write Data Length Code, and Message Marker
    buffer[1] = frame->data_len << 16U | index << 24U;

    // Write Frame to the message RAM
    buffer[2] = (((uint32_t)frame->data[3]) << 24U) | (((uint32_t)frame->data[2]) << 16U) | (((uint32_t)frame->data[1]) << 8U) | (((uint32_t)frame->data[0]) << 0U);
    buffer[3] = (((uint32_t)frame->data[7]) << 24U) | (((uint32_t)frame->data[6]) << 16U) | (((uint32_t)frame->data[5]) << 8U) | (((uint32_t)frame->data[4]) << 0U);

    // Set Add Request
    canIface_[iface].fdcan_base->TXBAR = (1 << index);

    // The frame is now enqueued and pending transmission.
    return 1;
}

int16_t fdCANConfigureFilters(const FDCanID iface, //
                              const FdCANFilterConfig filter_configs[MAX_FILTER_LIST_SIZE])
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.

    if (filter_configs == NULL)
        return -CANARD_ERROR_INVALID_ARGUMENT;

    uint32_t num_extid = 0, num_stdid = 0;
    uint32_t total_available_list_size = MAX_FILTER_LIST_SIZE;
    // count number of frames of each type
    for (uint8_t i = 0U; i < MAX_FILTER_LIST_SIZE; i++) {
        const FdCANFilterConfig* const cfg = filter_configs + i;
        if ((cfg->id & CANARD_CAN_FRAME_EFF) || !(cfg->mask & CANARD_CAN_FRAME_EFF))
            num_extid++;
        else
            num_stdid++;
    }

    const uint32_t timeout = CAN_TIMEOUT;

    // Allocate Message RAM for Standard ID Filter List
    if (!num_stdid) {                            // No Frame with Standard ID is to be accepted
        canIface_[iface].fdcan_base->GFC |= 0x2; // Reject All Standard ID Frames
    } else if ((num_stdid < total_available_list_size) && (num_stdid <= 128U)) {
        canIface_[iface].fdcan_base->SIDFC = (FDCANMessageRAMOffset << 2) | (num_stdid << 16);
        canIface_[iface].MessageRam.StandardFilterSA = SRAMCAN_BASE + (FDCANMessageRAMOffset * 4U);
        FDCANMessageRAMOffset += num_stdid;
        total_available_list_size -= num_stdid;
        canIface_[iface].fdcan_base->GFC |= (0x3U << 4);       // Reject non matching Standard frames
    } else {                                                   // The List is too big, return fail
        canIface_[iface].fdcan_base->CCCR &= ~FDCAN_CCCR_INIT; // Leave init mode
        uint32_t while_start_tick = SYS_TIMER;
        while (canIface_[iface].fdcan_base->CCCR & FDCAN_CCCR_INIT) {
            if ((SYS_TIMER - while_start_tick) > timeout)
                return -CANARD_STM32_ERROR_SET_REG_TIMEOUT;
        }
        return -CANARD_STM32_ERROR_FILTER_NUM_CONFIGS;
    }

    if (num_stdid) {
        uint32_t* filter_ptr = (uint32_t*)canIface_[iface].MessageRam.StandardFilterSA;
        // Run through the filter list and setup standard id filter list
        for (uint8_t i = 0U; i < MAX_FILTER_LIST_SIZE; i++) {
            const FdCANFilterConfig* const cfg = filter_configs + i;
            if (!((cfg->id & CANARD_CAN_FRAME_EFF) || !(cfg->mask & CANARD_CAN_FRAME_EFF))) {
                filter_ptr[num_stdid] = 0x2U << 30 | // Classic CAN Filter
                    0x1U << 27 |                     // Store in Rx FIFO0 if filter matches
                    (cfg->id & CANARD_CAN_STD_ID_MASK) << 16 | (cfg->mask & 0x7F);
            }
        }
    }

    // Allocate Message RAM for Extended ID Filter List
    if (!num_extid) {                            // No Frame with Extended ID is to be accepted
        canIface_[iface].fdcan_base->GFC |= 0x1; // Reject All Extended ID Frames
    } else if ((num_extid < (total_available_list_size / 2)) && (num_extid <= 64)) {
        canIface_[iface].fdcan_base->XIDFC = (FDCANMessageRAMOffset << 2) | (num_extid << 16);
        canIface_[iface].MessageRam.ExtendedFilterSA = SRAMCAN_BASE + (FDCANMessageRAMOffset * 4U);
        FDCANMessageRAMOffset += num_extid * 2;
        canIface_[iface].fdcan_base->GFC = (0x3U << 2);        // Reject non matching Extended frames
    } else {                                                   // The List is too big, return fail
        canIface_[iface].fdcan_base->CCCR &= ~FDCAN_CCCR_INIT; // Leave init mode
        uint32_t while_start_tick = SYS_TIMER;
        while (canIface_[iface].fdcan_base->CCCR & FDCAN_CCCR_INIT) {
            if ((SYS_TIMER - while_start_tick) > timeout)
                return -CANARD_STM32_ERROR_SET_REG_TIMEOUT;
        }
        return -CANARD_STM32_ERROR_FILTER_NUM_CONFIGS;
    }

    if (num_extid) {
        uint32_t* filter_ptr = (uint32_t*)canIface_[iface].MessageRam.ExtendedFilterSA;
        // Run through the filter list and setup extended id filter list
        for (uint8_t i = 0U; i < MAX_FILTER_LIST_SIZE; i++) {
            const FdCANFilterConfig* const cfg = filter_configs + i;
            if ((cfg->id & CANARD_CAN_FRAME_EFF) || !(cfg->mask & CANARD_CAN_FRAME_EFF)) {
                filter_ptr[num_extid * 2] = 0x1U << 29 | (cfg->id & CANARD_CAN_EXT_ID_MASK);       // Classic CAN Filter
                filter_ptr[num_extid * 2 + 1] = 0x2U << 30 | (cfg->mask & CANARD_CAN_EXT_ID_MASK); // Store in Rx FIFO0 if filter matches
            }
        }
    }

    canIface_[iface].MessageRam.EndAddress = SRAMCAN_BASE + (FDCANMessageRAMOffset * 4U);
    if (canIface_[iface].MessageRam.EndAddress > MESSAGE_RAM_END_ADDR) {
        // We are overflowing the limit of Allocated Message RAM
        __ASM volatile("BKPT #01");
    }

    canIface_[iface].fdcan_base->CCCR &= ~FDCAN_CCCR_INIT; // Leave init mode
    uint32_t while_start_tick = SYS_TIMER;
    while (canIface_[iface].fdcan_base->CCCR & FDCAN_CCCR_INIT) {
        if ((SYS_TIMER - while_start_tick) > timeout)
            return -CANARD_STM32_ERROR_SET_REG_TIMEOUT;
    }

    return 0;
}

int16_t fdCANInit(const FdCANTimings timings, //
                  const FDCanID iface)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.

    // In order to use CAN2, CAN1 must first be initialized as the former depends
    // on the latter. Test if CAN1 is already configured if CAN2 is selected.
    if ((iface == can2) && (FDCAN_1->CCCR & FDCAN_CCCR_CSR))
        return -CANARD_ERROR_INVALID_ARGUMENT; // CAN1 must be initialized before initializing CAN2.

                                               // Validate the rest of the inputs.
    if ((timings.bit_rate_prescaler < 1U) || (timings.bit_rate_prescaler > 1024U) || (timings.max_resynchronization_jump_width < 1U) || (timings.max_resynchronization_jump_width > 4U) || (timings.bit_segment_1 < 1U) || (timings.bit_segment_1 > 16U) || (timings.bit_segment_2 < 1U) || (timings.bit_segment_2 > 8U)) {
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid timings.
    }

    if (iface == can1)
        canIface_[iface].fdcan_base = FDCAN_1;
    else if (iface == can2)
        canIface_[iface].fdcan_base = FDCAN_2;

    canIface_[iface].error_cnt = 0;
    canIface_[iface].served_aborts_cnt = 0;
    canIface_[iface].rx_overflow_count = 0;
    for (uint8_t i = 0; i < NUM_TX_MAILBOXES; i++) {
        canIface_[iface].TxItem_abort_on_error[i] = false;
        canIface_[iface].TxItem_deadline[i] = UINT64_MAX;
    }

    // Initial setup
    const uint32_t timeout = CAN_TIMEOUT;

    canIface_[iface].fdcan_base->CCCR &= ~FDCAN_CCCR_CSR; // Exit sleep mode
    uint32_t while_start_tick = SYS_TIMER;
    while ((canIface_[iface].fdcan_base->CCCR & FDCAN_CCCR_CSA) == FDCAN_CCCR_CSA) {
        if ((SYS_TIMER - while_start_tick) > timeout)
            return -CANARD_STM32_ERROR_SET_REG_TIMEOUT;
    }                                                     // Wait for wake up ack
    canIface_[iface].fdcan_base->CCCR |= FDCAN_CCCR_INIT; // Request init
    while (!(canIface_[iface].fdcan_base->CCCR & FDCAN_CCCR_INIT)) {
        if ((SYS_TIMER - while_start_tick) > timeout)
            return -CANARD_STM32_ERROR_SET_REG_TIMEOUT;
    }                                                    // Wait for wake up ack
    canIface_[iface].fdcan_base->CCCR |= FDCAN_CCCR_CCE; // Enable Config change
    while (!(canIface_[iface].fdcan_base->CCCR & FDCAN_CCCR_INIT)) {
        if ((SYS_TIMER - while_start_tick) > timeout)
            return -CANARD_STM32_ERROR_SET_REG_TIMEOUT;
    }                                    // Wait for wake up ack
    canIface_[iface].fdcan_base->IE = 0; // We need no interrupts.

    /* Set FDCAN Frame Format */
    canIface_[iface].fdcan_base->CCCR &= ~FDCAN_FRAME_FD_BRS;

    /* Reset FDCAN Operation Mode */
    canIface_[iface].fdcan_base->CCCR &= ~(FDCAN_CCCR_TEST | FDCAN_CCCR_MON | FDCAN_CCCR_ASM);
    canIface_[iface].fdcan_base->TEST &= ~FDCAN_TEST_LBCK;

    // setup timing register
    // TODO: Do timing calculations for FDCAN
    canIface_[iface].fdcan_base->NBTP = (((timings.max_resynchronization_jump_width - 1U) << FDCAN_NBTP_NSJW_Pos) | ((timings.bit_segment_1 - 1U) << FDCAN_NBTP_NTSEG1_Pos) | ((timings.bit_segment_2 - 1U) << FDCAN_NBTP_NTSEG2_Pos) | ((timings.bit_rate_prescaler - 1U) << FDCAN_NBTP_NBRP_Pos));

    canIface_[iface].fdcan_base->DBTP = (((timings.bit_segment_1 - 1U) << FDCAN_DBTP_DTSEG1_Pos) | ((timings.bit_segment_2 - 1U) << FDCAN_DBTP_DTSEG2_Pos) | ((timings.bit_rate_prescaler - 1U) << FDCAN_DBTP_DBRP_Pos));
    // RX Config
    canIface_[iface].fdcan_base->RXESC = 0; // Set for 8Byte Frames

                                            // Setup Message RAM
    setupMessageRam(iface);
    // Clear all Interrupts
    // canIface_[iface].fdcan_base->IR = 0x3FFFFFFF;

    // Leave Init
    canIface_[iface].fdcan_base->CCCR &= ~FDCAN_CCCR_INIT; // Leave init mode
    return -CANARD_OK;
}

int16_t fdCANReceive(const FDCanID iface, //
                     CanardCANFrame* const out_frame)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.

    // This function must be polled periodically, so we use this opportunity to do it.
    processErrorStatus(iface);

    // Reading the TX FIFO
    for (uint_fast8_t i = 0U; i < 2U; i++) {
        uint32_t* frame_ptr;
        uint32_t index;
        if (i == 0U) {
            if (!(canIface_[iface].fdcan_base->RXF0C & FDCAN_RXF0C_F0S))
                continue; // Check if RAM allocated to RX FIFO

            if (canIface_[iface].fdcan_base->RXF0S & FDCAN_RXF0S_RF0L)
                canIface_[iface].error_cnt++; // Register Message Lost as a hardware error

            if (!(canIface_[iface].fdcan_base->RXF0S & FDCAN_RXF0S_F0FL))
                continue; // No More messages in FIFO
            else {
                index = ((canIface_[iface].fdcan_base->RXF0S & FDCAN_RXF0S_F0GI) >> 8);
                frame_ptr = (uint32_t*)(canIface_[iface].MessageRam.RxFIFO0SA + (index * FDCAN_FRAME_BUFFER_SIZE * 4));
            }
        } else {
            if (!(canIface_[iface].fdcan_base->RXF1C & FDCAN_RXF1C_F1S))
                continue; // Check if RAM allocated to RX FIFO

            if (canIface_[iface].fdcan_base->RXF1S & FDCAN_RXF1S_RF1L)
                canIface_[iface].error_cnt++; // Register Message Lost as a hardware error

            if (!(canIface_[iface].fdcan_base->RXF1S & FDCAN_RXF1S_F1FL))
                continue; // No More messages in FIFO
            else {
                index = ((canIface_[iface].fdcan_base->RXF1S & FDCAN_RXF1S_F1GI) >> 8);
                frame_ptr = (uint32_t*)(canIface_[iface].MessageRam.RxFIFO1SA + (index * FDCAN_FRAME_BUFFER_SIZE * 4));
            }
        }

        // Read the frame contents
        out_frame->id = convertFrameIDRegisterToCanard(frame_ptr[0]);

        out_frame->data_len = (uint8_t)((frame_ptr[1] & FDCAN_DLC_MASK) >> 16);

        uint8_t* data = (uint8_t*)&frame_ptr[2];
        // We only handle Data Length of 8 Bytes for now
        for (uint8_t j = 0U; j < 8U; j++)
            out_frame->data[j] = data[j];

        // Acknowledge the FIFO entry we just read
        if (i == 0)
            canIface_[iface].fdcan_base->RXF0A = index;
        else
            canIface_[iface].fdcan_base->RXF1A = index;

        // Reading successful
        return 1;
    }

    // No frames to read
    return 0;
}

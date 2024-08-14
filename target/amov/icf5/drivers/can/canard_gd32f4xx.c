/*
 * canardGD32F4xx.c
 *
 */

#include "canard_gd32f4xx.h"

#include <assert.h>
#include <firmament.h>
/*
 * State variables
 */
static CanardGD32Stats g_stats;

static bool g_abort_tx_on_error = false;

static FdCANIface canIface[FDCAN_NUM_IFACES];

/**
 * Mailbox instances
 */
volatile CanardGD32MailboxType *BXMaibox[2] = { (CanardGD32MailboxType*)0x40006580, (CanardGD32MailboxType*)0x40006980}; 
/**
 * RxFIFO instances
 */
volatile CanardGD32RxFIFOType *RFxR[2] = { (CanardGD32RxFIFOType*)0x4000640C, (CanardGD32RxFIFOType*)0x4000680C};

static bool isFramePriorityHigher(uint32_t a, uint32_t b)
{
    const uint32_t clean_a = a & CANARD_CAN_EXT_ID_MASK;
    const uint32_t clean_b = b & CANARD_CAN_EXT_ID_MASK;

    /*
     * STD vs EXT - if 11 most significant bits are the same, EXT loses.
     */
    const bool ext_a = (a & CANARD_CAN_FRAME_EFF) != 0;
    const bool ext_b = (b & CANARD_CAN_FRAME_EFF) != 0;
    if (ext_a != ext_b)
    {
        const uint32_t arb11_a = ext_a ? (clean_a >> 18) : clean_a;
        const uint32_t arb11_b = ext_b ? (clean_b >> 18) : clean_b;
        if (arb11_a != arb11_b)
        {
            return arb11_a < arb11_b;
        }
        else
        {
            return ext_b;
        }
    }

    /*
     * RTR vs Data frame - if frame identifiers and frame types are the same, RTR loses.
     */
    const bool rtr_a = (a & CANARD_CAN_FRAME_RTR) != 0;
    const bool rtr_b = (b & CANARD_CAN_FRAME_RTR) != 0;
    if ((clean_a == clean_b) && (rtr_a != rtr_b))
    {
        return rtr_b;
    }

    /*
     * Plain ID arbitration - greater value loses.
     */
    return clean_a < clean_b;
}

/// Converts libcanard ID value into the bxCAN TX ID register format.
static uint32_t convertFrameIDCanardToRegister(const uint32_t id)
{
    uint32_t out = 0;

    if (id & CANARD_CAN_FRAME_EFF)
    {
        out = ((id & CANARD_CAN_EXT_ID_MASK) << 3) | CAN_TSTAT_MAL0;
    }
    else
    {
        out = ((id & CANARD_CAN_STD_ID_MASK) << 21);
    }

    if (id & CANARD_CAN_FRAME_RTR)
    {
        out |= CAN_TSTAT_MTFNERR0;
    }

    return out;
}

/// Converts fdCAN TX/RX ID register value into the libcanard ID format.
static uint32_t convertFrameIDRegisterToCanard(const uint32_t id)
{
    uint32_t out = 0;

    if ((id & CAN_RFIFOMI_FF) == 0)
    {
        out = (CANARD_CAN_STD_ID_MASK & (id >> 21));
    }
    else
    {
        out = (CANARD_CAN_EXT_ID_MASK & (id >> 3)) | CANARD_CAN_FRAME_EFF;
    }

    if ((id & CAN_RFIFOMI_FT) != 0)
    {
        out |= CANARD_CAN_FRAME_RTR;
    }

    return out;
}

static bool waitMSRINAKBitStateChange(const uint8_t iface, const bool target_state)
{
    /**
     * A properly functioning bus will exhibit 11 consecutive recessive bits at the end of every correct transmission,
     * or while the bus is idle. The 11 consecutive recessive bits are made up of:
     *  1 bit - acknowledgement delimiter
     *  7 bit - end of frame bits
     *  3 bit - inter frame space
     * This adds up to 11; therefore, it is not really necessary to wait longer than a few frame TX intervals.
     */
    static const unsigned TimeoutMilliseconds = 1000;

    for (unsigned wait_ack = 0; wait_ack < TimeoutMilliseconds; wait_ack++)
    {
        const bool state = (CAN_TSTAT(canIface[iface].fdcan_base) & CAN_TSTAT_MTF0) != 0;
        if (state == target_state)
        {
            return true;
        }
        
        for(uint16_t i= 0; i< 0xFFF0;i++){}

    }

    return false;
}

/// Handle TX/RX errors. Also abort pending TX buffers while in bus-off mode. Errors are reported.
static void processErrorStatus(const uint8_t iface)
{
    CANARD_ASSERT(iface < FDCAN_NUM_IFACES); // Valid fdcan base index.

    // Aborting TX transmissions if abort on error was requested
    // Updating error counter
    const uint8_t cel =  (uint8_t)( (CAN_ERR(canIface[iface].fdcan_base) & CAN_ERR_ERRN) >> 4);
    if (cel != 0) 
    {
        CAN_ERR(canIface[iface].fdcan_base) = 0;                 // This action does only affect the ERRN bits, other bits are read only!
        g_stats.error_count++;

        // Abort pending transmissions if auto abort on error is enabled, or if we're in bus off mode
        if (g_abort_tx_on_error || (CAN_ERR(canIface[iface].fdcan_base) & CAN_ERR_BOERR))
        {
            CAN_TSTAT(canIface[iface].fdcan_base) = CAN_TSTAT_MST0 | CAN_TSTAT_MST1 | CAN_TSTAT_MST2;
        }
    }
}


int16_t fdCANComputeTimings(const uint32_t peripheral_clock_rate, //
                            const uint32_t target_bitrate,        //
                            FdCANTimings* const out_timings)
{
    if (target_bitrate < 1000)
        return -CANARD_GD32F4XX_ERROR_UNSUPPORTED_BIT_RATE;

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
            return -CANARD_GD32F4XX_ERROR_UNSUPPORTED_BIT_RATE; // No solution

        bs1_bs2_sum--;
    }

    const uint32_t prescaler = prescaler_bs / (1U + bs1_bs2_sum);
    if ((prescaler < 1U) || (prescaler > 1024U))
        return -CANARD_GD32F4XX_ERROR_UNSUPPORTED_BIT_RATE; // No solution

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
        return -1;
    }

    out_timings->bit_rate_prescaler = (uint16_t)prescaler;
    out_timings->max_resynchronization_jump_width = 1; // One is recommended by UAVCAN, CANOpen, and DeviceNet
    out_timings->bit_segment_1 = bs1;
    out_timings->bit_segment_2 = bs2;

    return 0;
}

int canardGD32Transmit(const FDCanID iface, const CanardCANFrame* const frame)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
    {
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.
    }

    if (frame == NULL)
    {
        return -CANARD_ERROR_INVALID_ARGUMENT;
    }

    if (frame->id & CANARD_CAN_FRAME_ERR)
    {
        return -CANARD_GD32F4XX_ERROR_UNSUPPORTED_FRAME_FORMAT;
    }
    
    can_trasnmit_message_struct transmit_message;

    transmit_message.tx_sfid = 0x00;
    transmit_message.tx_efid = frame->id;
    transmit_message.tx_ft = CAN_FT_DATA;
    transmit_message.tx_ff = CAN_FF_EXTENDED;
    transmit_message.tx_dlen = frame->data_len;
    memcpy(transmit_message.tx_data, frame->data, frame->data_len);

    can_message_transmit(CAN0, &transmit_message);

    // The frame is now enqueued and pending transmission.
    return 1;
}

int canardGD32Init(const FdCANTimings timings, const FDCanID iface)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.

    // Validate the rest of the inputs.
    if ((timings.bit_rate_prescaler < 1U) || (timings.bit_rate_prescaler > 1024U) || (timings.max_resynchronization_jump_width < 1U) || (timings.max_resynchronization_jump_width > 4U) || (timings.bit_segment_1 < 1U) || (timings.bit_segment_1 > 16U) || (timings.bit_segment_2 < 1U) || (timings.bit_segment_2 > 8U)) {
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid timings.
    }
    /*
     * Initial setup
     */
    memset(&g_stats, 0, sizeof(g_stats));

    if (iface == can1)
        canIface[iface].fdcan_base = CAN0;
    else if (iface == can2)
        canIface[iface].fdcan_base = CAN1;

    return CANARD_OK;
}

int canardGD32Receive(const FDCanID iface, CanardCANFrame* const out_frame)
{
    // If the interface number is invalid, return with an error.
    if (iface >= FDCAN_NUM_IFACES)
        return -CANARD_ERROR_INVALID_ARGUMENT; // Invalid CAN interface number.
    
    if (out_frame == NULL)
    {
        return -CANARD_ERROR_INVALID_ARGUMENT;
    }

    // This function must be polled periodically, so we use this opportunity to do it.
    processErrorStatus(iface);

    // Reading the RX FIFO
    // for (uint8_t i = 0; i < FDCAN_NUM_IFACES; i++)
    // {
    //     volatile CanardGD32RxMailboxType* const mb = &BXMaibox[iface]->RxMailbox[i];

    //     if ((RFxR[iface]->RFIFO[i] & CAN_RFIFO0_RFL0) != 0)
    //     {
    //         if (RFxR[iface]->RFIFO[i] & CAN_RFIFO0_RFO0)
    //         {
    //             g_stats.rx_overflow_count++;
    //         }

    //         out_frame->id = convertFrameIDRegisterToCanard(mb->RFIFOMI0);

    //         out_frame->data_len = (uint8_t)(mb->RFIFOMP0 & CAN_RFIFOMP_DLENC);

    //         // Caching to regular (non volatile) memory for faster reads
    //         const uint32_t rdlr = mb->RFIFOMDATA00;
    //         const uint32_t rdhr = mb->RFIFOMDATA10;

    //         out_frame->data[0] = (uint8_t)(0xFF & (rdlr >>  0));
    //         out_frame->data[1] = (uint8_t)(0xFF & (rdlr >>  8));
    //         out_frame->data[2] = (uint8_t)(0xFF & (rdlr >> 16));
    //         out_frame->data[3] = (uint8_t)(0xFF & (rdlr >> 24));
    //         out_frame->data[4] = (uint8_t)(0xFF & (rdhr >>  0));
    //         out_frame->data[5] = (uint8_t)(0xFF & (rdhr >>  8));
    //         out_frame->data[6] = (uint8_t)(0xFF & (rdhr >> 16));
    //         out_frame->data[7] = (uint8_t)(0xFF & (rdhr >> 24));

    //         // Release FIFO entry we just read
    //         // *RFxR[i] = CAN_RFIFO0_RFD0 | CAN_RFIFO0_RFO0 | CAN_RFIFO0_RFF0;

    //         // Reading successful
    //         return 1;
    //     }
    // }
    can_receive_message_struct receive_message;

    can_message_receive(CAN0, CAN_FIFO0, &receive_message);
    g_stats.rx_overflow_count++;
    out_frame->id = receive_message.rx_efid | CANARD_CAN_FRAME_EFF;
    out_frame->data_len = receive_message.rx_dlen;
    memcpy(out_frame->data, receive_message.rx_data, receive_message.rx_dlen);

    return 1;
    // No frames to read
    // return 0;
}

CanardGD32Stats canardGD32GetStats(void)
{
    return g_stats;
}
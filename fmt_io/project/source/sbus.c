/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <stdbool.h>
#include <stdio.h>

#include "debug.h"
#include "interface.h"
#include "protocol.h"
#include "sbus.h"
#include "time.h"
#include "usart.h"

static RING_BUFFER_Def sbus_rb;

#define RC_INPUT_CHANNELS 16

#define SBUS_START_SYMBOL 0x0f

#define SBUS_INPUT_CHANNELS 16
#define SBUS_FLAGS_BYTE     23
#define SBUS_FAILSAFE_BIT   3
#define SBUS_FRAMELOST_BIT  2

// this is the rate of the old code
#define SBUS_DEFAULT_RATE_HZ 72

/*
  Measured values with Futaba FX-30/R6108SB:
    -+100% on TX:  PCM 1.100/1.520/1.950ms -> SBus raw values: 350/1024/1700  (100% ATV)
    -+140% on TX:  PCM 0.930/1.520/2.112ms -> SBus raw values:  78/1024/1964  (140% ATV)
    -+152% on TX:  PCM 0.884/1.520/2.160ms -> SBus raw values:   1/1024/2047  (140% ATV plus dirty tricks)
*/

/* define range mapping here, -+100% -> 1000..2000 */
#define SBUS_RANGE_MIN 200.0f
#define SBUS_RANGE_MAX 1800.0f

#define SBUS_TARGET_MIN 1000.0f
#define SBUS_TARGET_MAX 2000.0f

/* pre-calculate the floating point stuff as far as possible at compile time */
#define SBUS_SCALE_FACTOR ((SBUS_TARGET_MAX - SBUS_TARGET_MIN) / (SBUS_RANGE_MAX - SBUS_RANGE_MIN))
#define SBUS_SCALE_OFFSET (int)(SBUS_TARGET_MIN - (SBUS_SCALE_FACTOR * SBUS_RANGE_MIN + 0.5f))

#define SBUS_FRAME_SIZE_RX_VOLTAGE 3
#define SBUS_FRAME_SIZE_GPS_DIGIT  3

static enum SBUS_DECODE_STATE {
    SBUS_DECODE_STATE_DESYNC = 0xFFF,
    SBUS_DECODE_STATE_SBUS_START = 0x2FF,
    SBUS_DECODE_STATE_SBUS1_SYNC = 0x00,
    SBUS_DECODE_STATE_SBUS2_SYNC = 0x1FF,
    SBUS_DECODE_STATE_SBUS2_RX_VOLTAGE = 0x04,
    SBUS_DECODE_STATE_SBUS2_GPS = 0x14,
    SBUS_DECODE_STATE_SBUS2_DATA1 = 0x24,
    SBUS_DECODE_STATE_SBUS2_DATA2 = 0x34
} sbus_decode_state
    = SBUS_DECODE_STATE_DESYNC;

#define SBUS_FRAME_SIZE  25
#define SBUS_BUFFER_SIZE (SBUS_FRAME_SIZE + SBUS_FRAME_SIZE / 2)

static uint8_t sbus_frame[SBUS_FRAME_SIZE + (SBUS_FRAME_SIZE / 2)];

static unsigned partial_frame_count;
static unsigned sbus1_frame_delay = (1000U * 1000U) / SBUS_DEFAULT_RATE_HZ;

static uint64_t last_rx_time;
static uint64_t last_frame_time;
static uint64_t last_txframe_time = 0;

static unsigned sbus_frame_drops;

static uint16_t _rc_values[RC_INPUT_CHANNELS];

uint16_t sbus_send(uint8_t* data, uint16_t len);
uint16_t sbus_read(uint8_t* buf, uint16_t size);

unsigned sbus_dropped_frames(void)
{
    return sbus_frame_drops;
}

void sbus1_output(uint16_t* values, uint16_t num_values)
{
    uint8_t byteindex = 1; /*Data starts one byte into the sbus frame. */
    uint8_t offset = 0;
    uint16_t value;
    uint64_t now;

    now = time_nowUs();

    if ((now - last_txframe_time) > sbus1_frame_delay) {
        last_txframe_time = now;
        uint8_t oframe[SBUS_FRAME_SIZE] = { 0x0f };

        /* 16 is sbus number of servos/channels minus 2 single bit channels.
		* currently ignoring single bit channels.  */

        for (unsigned i = 0; (i < num_values) && (i < 16); ++i) {
            value = (uint16_t)(((values[i] - SBUS_SCALE_OFFSET) / SBUS_SCALE_FACTOR) + .5f);

            /*protect from out of bounds values and limit to 11 bits*/
            if (value > 0x07ff) {
                value = 0x07ff;
            }

            while (offset >= 8) {
                ++byteindex;
                offset -= 8;
            }

            oframe[byteindex] |= (value << (offset)) & 0xff;
            oframe[byteindex + 1] |= (value >> (8 - offset)) & 0xff;
            oframe[byteindex + 2] |= (value >> (16 - offset)) & 0xff;
            offset += 11;
        }

        sbus_send(oframe, SBUS_FRAME_SIZE);
    }
}
void sbus2_output(uint16_t* values, uint16_t num_values)
{
    sbus1_output(values, num_values);
}

/*
 * S.bus decoder matrix.
 *
 * Each channel value can come from up to 3 input bytes. Each row in the
 * matrix describes up to three bytes, and each entry gives:
 *
 * - byte offset in the data portion of the frame
 * - right shift applied to the data byte
 * - mask for the data byte
 * - left shift applied to the result into the channel value
 */
struct sbus_bit_pick {
    uint8_t byte;
    uint8_t rshift;
    uint8_t mask;
    uint8_t lshift;
};
static const struct sbus_bit_pick sbus_decoder[SBUS_INPUT_CHANNELS][3] = {
    /*  0 */ { { 0, 0, 0xff, 0 }, { 1, 0, 0x07, 8 }, { 0, 0, 0x00, 0 } },
    /*  1 */ { { 1, 3, 0x1f, 0 }, { 2, 0, 0x3f, 5 }, { 0, 0, 0x00, 0 } },
    /*  2 */ { { 2, 6, 0x03, 0 }, { 3, 0, 0xff, 2 }, { 4, 0, 0x01, 10 } },
    /*  3 */ { { 4, 1, 0x7f, 0 }, { 5, 0, 0x0f, 7 }, { 0, 0, 0x00, 0 } },
    /*  4 */ { { 5, 4, 0x0f, 0 }, { 6, 0, 0x7f, 4 }, { 0, 0, 0x00, 0 } },
    /*  5 */ { { 6, 7, 0x01, 0 }, { 7, 0, 0xff, 1 }, { 8, 0, 0x03, 9 } },
    /*  6 */ { { 8, 2, 0x3f, 0 }, { 9, 0, 0x1f, 6 }, { 0, 0, 0x00, 0 } },
    /*  7 */ { { 9, 5, 0x07, 0 }, { 10, 0, 0xff, 3 }, { 0, 0, 0x00, 0 } },
    /*  8 */ { { 11, 0, 0xff, 0 }, { 12, 0, 0x07, 8 }, { 0, 0, 0x00, 0 } },
    /*  9 */ { { 12, 3, 0x1f, 0 }, { 13, 0, 0x3f, 5 }, { 0, 0, 0x00, 0 } },
    /* 10 */ { { 13, 6, 0x03, 0 }, { 14, 0, 0xff, 2 }, { 15, 0, 0x01, 10 } },
    /* 11 */ { { 15, 1, 0x7f, 0 }, { 16, 0, 0x0f, 7 }, { 0, 0, 0x00, 0 } },
    /* 12 */ { { 16, 4, 0x0f, 0 }, { 17, 0, 0x7f, 4 }, { 0, 0, 0x00, 0 } },
    /* 13 */ { { 17, 7, 0x01, 0 }, { 18, 0, 0xff, 1 }, { 19, 0, 0x03, 9 } },
    /* 14 */ { { 19, 2, 0x3f, 0 }, { 20, 0, 0x1f, 6 }, { 0, 0, 0x00, 0 } },
    /* 15 */ { { 20, 5, 0x07, 0 }, { 21, 0, 0xff, 3 }, { 0, 0, 0x00, 0 } }
};

bool sbus_decode(uint64_t frame_time, uint8_t* frame, uint16_t* values, uint16_t* num_values,
    bool* sbus_failsafe, bool* sbus_frame_drop, uint16_t max_values)
{
    //unsigned i;
    /* check frame boundary markers to avoid out-of-sync cases */
    if ((frame[0] != SBUS_START_SYMBOL)) {
        sbus_frame_drops++;
#ifdef SBUS_DEBUG
        printf("DECODE FAIL: ");

        for (i = 0; i < SBUS_FRAME_SIZE; i++) {
            printf("%0x ", frame[i]);
        }

        printf("\n");
#endif
        sbus_decode_state = SBUS_DECODE_STATE_DESYNC;
        return false;
    }

    switch (frame[24]) {
    case 0x00:
        /* this is S.BUS 1 */
        sbus_decode_state = SBUS_DECODE_STATE_SBUS1_SYNC;
        break;

    case 0x04:
        /* receiver voltage */
        sbus_decode_state = SBUS_DECODE_STATE_SBUS2_RX_VOLTAGE;
        break;

    case 0x14:
        /* GPS / baro */
        sbus_decode_state = SBUS_DECODE_STATE_SBUS2_GPS;
        break;

    case 0x24:
        /* Unknown SBUS2 data */
        sbus_decode_state = SBUS_DECODE_STATE_SBUS2_SYNC;
        break;

    case 0x34:
        /* Unknown SBUS2 data */
        sbus_decode_state = SBUS_DECODE_STATE_SBUS2_SYNC;
        break;

    default:
#ifdef SBUS_DEBUG
        printf("DECODE FAIL: END MARKER\n");
#endif
        sbus_decode_state = SBUS_DECODE_STATE_DESYNC;
        return false;
    }

    /* we have received something we think is a frame */
    last_frame_time = frame_time;

    unsigned chancount = (max_values > SBUS_INPUT_CHANNELS) ? SBUS_INPUT_CHANNELS : max_values;

    /* use the decoder matrix to extract channel data */
    for (unsigned channel = 0; channel < chancount; channel++) {
        unsigned value = 0;

        for (unsigned pick = 0; pick < 3; pick++) {
            const struct sbus_bit_pick* decode = &sbus_decoder[channel][pick];

            if (decode->mask != 0) {
                unsigned piece = frame[1 + decode->byte];
                piece >>= decode->rshift;
                piece &= decode->mask;
                piece <<= decode->lshift;

                value |= piece;
            }
        }

        /* convert 0-2048 values to 1000-2000 ppm encoding in a not too sloppy fashion */
        values[channel] = (uint16_t)(value * SBUS_SCALE_FACTOR + .5f) + SBUS_SCALE_OFFSET;
    }

    /* decode switch channels if data fields are wide enough */
    if (max_values > 17 && chancount > 15) {
        chancount = 18;

        /* channel 17 (index 16) */
        values[16] = (frame[SBUS_FLAGS_BYTE] & (1 << 0)) * 1000 + 998;
        /* channel 18 (index 17) */
        values[17] = (frame[SBUS_FLAGS_BYTE] & (1 << 1)) * 1000 + 998;
    }

    /* note the number of channels decoded */
    *num_values = chancount;

    /* decode and handle failsafe and frame-lost flags */
    if (frame[SBUS_FLAGS_BYTE] & (1 << SBUS_FAILSAFE_BIT)) { /* failsafe */
        /* report that we failed to read anything valid off the receiver */
        *sbus_failsafe = true;
        *sbus_frame_drop = true;

    } else if (frame[SBUS_FLAGS_BYTE] & (1 << SBUS_FRAMELOST_BIT)) { /* a frame was lost */
        /* set a special warning flag
		 *
		 * Attention! This flag indicates a skipped frame only, not a total link loss! Handling this
		 * condition as fail-safe greatly reduces the reliability and range of the radio link,
		 * e.g. by prematurely issuing return-to-launch!!! */

        *sbus_failsafe = false;
        *sbus_frame_drop = true;

    } else {
        *sbus_failsafe = false;
        *sbus_frame_drop = false;
    }

    return true;
}

bool sbus_parse(uint64_t now, uint8_t* frame, unsigned len, uint16_t* values,
    uint16_t* num_values, bool* sbus_failsafe, bool* sbus_frame_drop, unsigned* frame_drops, uint16_t max_channels)
{
    unsigned i;
    last_rx_time = now;

    /* this is set by the decoding state machine and will default to false
	 * once everything that was decodable has been decoded.
	 */
    bool decode_ret = false;

    /* keep decoding until we have consumed the buffer */
    for (i = 0; i < len; i++) {

        /* overflow check */
        if (partial_frame_count == sizeof(sbus_frame) / sizeof(sbus_frame[0])) {
            partial_frame_count = 0;
            sbus_decode_state = SBUS_DECODE_STATE_DESYNC;
#ifdef SBUS_DEBUG
            printf("SBUS2: RESET (BUF LIM)\n");
#endif
        }

        if (partial_frame_count == SBUS_FRAME_SIZE) {
            partial_frame_count = 0;
            sbus_decode_state = SBUS_DECODE_STATE_DESYNC;
#ifdef SBUS_DEBUG
            printf("SBUS2: RESET (PACKET LIM)\n");
#endif
        }

        switch (sbus_decode_state) {
        case SBUS_DECODE_STATE_DESYNC:

            /* we are de-synced and only interested in the frame marker */
            if (frame[i] == SBUS_START_SYMBOL) {
                sbus_decode_state = SBUS_DECODE_STATE_SBUS_START;
                partial_frame_count = 0;
                sbus_frame[partial_frame_count++] = frame[i];
            }

            break;

        case SBUS_DECODE_STATE_SBUS_START:
        case SBUS_DECODE_STATE_SBUS1_SYNC:
        case SBUS_DECODE_STATE_SBUS2_SYNC: {
            sbus_frame[partial_frame_count++] = frame[i];

            /* decode whatever we got and expect */
            if (partial_frame_count < SBUS_FRAME_SIZE) {
                break;
            }

            /*
				 * Great, it looks like we might have a frame.  Go ahead and
				 * decode it.
				 */
            decode_ret = sbus_decode(now, sbus_frame, values, num_values, sbus_failsafe, sbus_frame_drop, max_channels);

            /*
				 * Offset recovery: If decoding failed, check if there is a second
				 * start marker in the packet.
				 */
            unsigned start_index = 0;

            if (!decode_ret && sbus_decode_state == SBUS_DECODE_STATE_DESYNC) {

                for (unsigned i = 1; i < partial_frame_count; i++) {
                    if (sbus_frame[i] == SBUS_START_SYMBOL) {
                        start_index = i;
                        break;
                    }
                }

                /* we found a second start marker */
                if (start_index != 0) {
                    /* shift everything in the buffer and reset the state machine */
                    for (unsigned i = 0; i < partial_frame_count - start_index; i++) {
                        sbus_frame[i] = sbus_frame[i + start_index];
                    }

                    partial_frame_count -= start_index;
                    sbus_decode_state = SBUS_DECODE_STATE_SBUS_START;

#ifdef SBUS_DEBUG
                    printf("DECODE RECOVERY: %d\n", start_index);
#endif
                }
            }

            /* if there has been no successful attempt at saving a failed
				 * decoding run, reset the frame count for successful and
				 * unsuccessful decode runs.
				 */
            if (start_index == 0) {
                partial_frame_count = 0;
            }

        } break;

        case SBUS_DECODE_STATE_SBUS2_RX_VOLTAGE: {
            sbus_frame[partial_frame_count++] = frame[i];

            if (partial_frame_count == 1 && sbus_frame[0] == SBUS_START_SYMBOL) {
                /* this slot is unused and in fact S.BUS2 sync */
                sbus_decode_state = SBUS_DECODE_STATE_SBUS2_SYNC;
            }

            if (partial_frame_count < SBUS_FRAME_SIZE_RX_VOLTAGE) {
                break;
            }

            /* find out which payload we're dealing with in this slot */
            switch (sbus_frame[0]) {
            case 0x03: {
                // Observed values:
                // (frame[0] == 0x3 && frame[1] == 0x84 && frame[2] == 0x0)
                // (frame[0] == 0x3 && frame[1] == 0xc4 && frame[2] == 0x0)
                // (frame[0] == 0x3 && frame[1] == 0x80 && frame[2] == 0x2f)
                // (frame[0] == 0x3 && frame[1] == 0xc0 && frame[2] == 0x2f)
#ifdef SBUS_DEBUG
                //uint16_t rx_voltage = (sbus_frame[1] << 8) | sbus_frame[2];
                //printf("rx_voltage %d\n", (int)rx_voltage);
#endif
            }

                partial_frame_count = 0;
                break;

            default:
                /* this is not what we expect it to be, go back to sync */
                sbus_decode_state = SBUS_DECODE_STATE_DESYNC;
                sbus_frame_drops++;
            }

        } break;

        case SBUS_DECODE_STATE_SBUS2_GPS: {
            sbus_frame[partial_frame_count++] = frame[i];

            if (partial_frame_count == 1 && sbus_frame[0] == SBUS_START_SYMBOL) {
                /* this slot is unused and in fact S.BUS2 sync */
                sbus_decode_state = SBUS_DECODE_STATE_SBUS2_SYNC;
            }

            if (partial_frame_count < 24) {
                break;
            }

            /* find out which payload we're dealing with in this slot */
            switch (sbus_frame[0]) {
            case 0x13: {
#ifdef SBUS_DEBUG
                uint16_t gps_something = (frame[1] << 8) | frame[2];
                printf("gps_something %d\n", (int)gps_something);
#endif
            }

                partial_frame_count = 0;
                break;

            default:
                /* this is not what we expect it to be, go back to sync */
                sbus_decode_state = SBUS_DECODE_STATE_DESYNC;
                sbus_frame_drops++;
                /* throw unknown bytes away */
            }
        } break;

        /* fall through */
        default:
#ifdef SBUS_DEBUG
            printf("UNKNOWN PROTO STATE");
#endif
            decode_ret = false;
        }
    }

    if (frame_drops) {
        *frame_drops = sbus_frame_drops;
    }

    /* return false as default */
    return decode_ret;
}

bool sbus_input(uint16_t* values, uint16_t* num_values, bool* sbus_failsafe,
    bool* sbus_frame_drop, uint16_t max_channels)
{
    int ret = 1;
    uint64_t now;

    /*
	 * The S.BUS protocol doesn't provide reliable framing,
	 * so we detect frame boundaries by the inter-frame delay.
	 *
	 * The minimum frame spacing is 7ms; with 25 bytes at 100000bps
	 * frame transmission time is ~2ms.
	 *
	 * We expect to only be called when bytes arrive for processing,
	 * and if an interval of more than 3ms passes between calls,
	 * the first byte we read will be the first byte of a frame.
	 *
	 * In the case where byte(s) are dropped from a frame, this also
	 * provides a degree of protection. Of course, it would be better
	 * if we didn't drop bytes...
	 */
    now = time_nowUs();

    /*
	 * Fetch bytes, but no more than we would need to complete
	 * a complete frame.
	 */
    uint8_t buf[SBUS_FRAME_SIZE * 2];
    bool sbus_decoded = false;

    ret = sbus_read(&buf[0], SBUS_FRAME_SIZE);

    /* if the read failed for any reason, just give up here */
    if (ret < 1) {
        return false;
    }

    /*
	 * Try to decode something with what we got
	 */
    if (sbus_parse(now, &buf[0], ret, values, num_values, sbus_failsafe,
            sbus_frame_drop, &sbus_frame_drops, max_channels)) {

        sbus_decoded = true;
    }

    return sbus_decoded;
}

uint8_t send_sbus_value(void)
{
    int ret = 0;
    int i = 0;
    uint16_t rc_count = 0;
    bool sbus_failsafe, sbus_frame_drop;

    bool sbus_updated = sbus_input(_rc_values, &rc_count, &sbus_failsafe, &sbus_frame_drop,
        RC_INPUT_CHANNELS);

    if (sbus_updated && !sbus_failsafe && !sbus_frame_drop) {
        if (rc_signal_ready()) {
            send_io_cmd(IO_CODE_RC_DATA, _rc_values, 32);
            ret = 0;
        }
    } else {
        ret = 1;
    }

    return ret;
}

uint8_t sbus_send_ch(uint8_t ch)
{
    USART_SendData(USART3, (uint8_t)ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
        ;

    return ch;
}

uint16_t sbus_send(uint8_t* data, uint16_t len)
{
    uint16_t i;

    for (i = 0; i < len; i++) {
        sbus_send_ch(data[i]);
    }

    return len;
}

uint16_t sbus_read(uint8_t* buf, uint16_t size)
{
    int cnt = 0;

    while ((sbus_rb.head != sbus_rb.tail) && (size--)) {
        buf[cnt++] = sbus_rb.buff[sbus_rb.tail];
        sbus_rb.tail++;

        if (sbus_rb.tail >= RING_BUFFER_SIZE)
            sbus_rb.tail = 0;
    }

    return cnt;
}

void USART3_IRQHandler(void)
{
    if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) {
        sbus_rb.buff[sbus_rb.head] = USART_ReceiveData(USART3); /* this process will clear EXNE flag */
        sbus_rb.head++;

        if (sbus_rb.head >= RING_BUFFER_SIZE)
            sbus_rb.head = 0;

        // if (sbus_rb.head == sbus_rb.tail) {
        //     printf("sbus rb is full\n");
        // }
    }
}

uint8_t sbus_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /*init ring budder*/
    sbus_rb.head = sbus_rb.tail = 0;

    /* Enable Clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

    /* Configure the NVIC Preemption Priority Bits */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    /* Enable the USART3 Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    /* Configure USART Rx as input floating */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /* 100000bps, even parity, two stop bits */
    USART_InitStructure.USART_BaudRate = 100000;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_2;
    USART_InitStructure.USART_Parity = USART_Parity_Even;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART3, &USART_InitStructure);

    /* Enable USART3 Receive interrupts */
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

    /* Enable USART */
    USART_Cmd(USART3, ENABLE);

    /* initialise the decoder */
    partial_frame_count = 0;
    last_rx_time = time_nowUs();
    last_frame_time = last_rx_time;
    sbus_frame_drops = 0;

    return 0;
}

void sbus_deinit(void)
{
    USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
    USART_Cmd(USART3, DISABLE);
}

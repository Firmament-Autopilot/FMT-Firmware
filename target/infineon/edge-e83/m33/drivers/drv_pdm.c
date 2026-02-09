#include <rtthread.h>
#include <rtdevice.h>


#include "cy_pdl.h"
#include "cybsp.h"

#include "drv_pdm.h"

#include <math.h>

#define DBG_TAG              "drv.mic"
#define DBG_LVL              DBG_INFO
#include <rtdbg.h>

/*******************************************************************************
* Macros
*******************************************************************************/
#ifdef ENABLE_STEREO_INPUT_FEED
#define MIC_MODE                         (2u)
#else
#define MIC_MODE                         (1u)
#endif /* ENABLE_STEREO_INPUT_FEED */
rt_device_t device_sound;

#define PDM_PCM_HW_FIFO_SIZE             (64u)
#define PDM_PCM_FRAME_INTR_CNT           (5u)
#define MIC_RX_SAMPLES_COUNT             (160*MIC_MODE)

#define PDM_FIR1_GAIN_CONST              (13921L)
#define PDM_FIR_MAX_SCALE_VALUE          (31)
#define PDM_GAIN_DB_STEPS_CONST          (0.5f)
#define PDM_GAIN_CONVERT_CONST_2         (2)
#define PDM_GAIN_CONVERT_CONST_10        (10)
#define PDM_GAIN_CONVERT_CONST_20        (20)
#define PDM_SET_GAIN_ERROR               (-1)

/* The number of interrupts to get frame of 10 msec samples.
    5 interrupts of 2msec makes 10msec frame */
/* 10msec data is 320 samples in STEREO mode*/
/* 10msec data is 160 samples in STEREO mode*/
#ifdef ENABLE_STEREO_INPUT_FEED
#define HALF_FIFO_SIZE              (PDM_PCM_HW_FIFO_SIZE)
#else
#define HALF_FIFO_SIZE              (PDM_PCM_HW_FIFO_SIZE/2)
#endif /* ENABLE_STEREO_INPUT_FEED */

/*******************************************************************************
* Global Variables
*******************************************************************************/

int16_t mic_audio_app_buffer_ping[MIC_RX_SAMPLES_COUNT] = {0};
int16_t mic_audio_app_buffer_pong[MIC_RX_SAMPLES_COUNT] = {0};

volatile uint8_t pdm_pcm_intr_cnt = 0;

int16_t *ping_pong_local_pointer = NULL;
int16_t *ping_pong_buffer_pointer = NULL;

const cy_stc_sysint_t PDM_IRQ_cfg =
{
    .intrSrc = (IRQn_Type)CYBSP_PDM_CHANNEL_3_IRQ,
    .intrPriority = PDM_PCM_INTR_PRIORITY
};
static inline int32_t convert_pdm_pcm_gain_to_scale(int16_t gain_val);

#define RX_FIFO_SIZE (MIC_RX_SAMPLES_COUNT*2)

struct mic_device
{
    struct rt_audio_device audio;           /* RT-Thread audio device */
    struct rt_audio_configure record_config;/* Audio configuration */
    rt_uint8_t *rx_fifo;                    /* Receive FIFO buffer */
    rt_uint8_t volume;                      /* Volume level */
    rt_bool_t is_running;                   /* Running state */
};

/* Static device instance */
static struct mic_device mic_dev = {0};
void pdm_interrupt_handler(void)
{
    static bool ping_pong = false;
    volatile uint32_t int_stat;

    rt_interrupt_enter();

    if (pdm_pcm_intr_cnt == 0)
    {
        if (ping_pong)
        {
            ping_pong_local_pointer = mic_audio_app_buffer_ping;
        }
        else
        {
            ping_pong_local_pointer = mic_audio_app_buffer_pong;
        }
        ping_pong_buffer_pointer = ping_pong_local_pointer;
    }

    int_stat = Cy_PDM_PCM_Channel_GetInterruptStatusMasked(PDM0, RIGHT_CH_INDEX);
    if (CY_PDM_PCM_INTR_RX_TRIGGER & int_stat)
    {
        for (uint8_t i = 0; i < RX_FIFO_TRIG_LEVEL; i++)
        {
#ifdef ENABLE_STEREO_INPUT_FEED
            int32_t data = (int32_t)Cy_PDM_PCM_Channel_ReadFifo(PDM0, LEFT_CH_INDEX);
            *(ping_pong_buffer_pointer) = (int16_t)(data);
            ping_pong_buffer_pointer++;

            data = (int32_t)Cy_PDM_PCM_Channel_ReadFifo(PDM0, RIGHT_CH_INDEX);
            *(ping_pong_buffer_pointer) = (int16_t)(data);
            ping_pong_buffer_pointer++;
#else
            int32_t data = (int32_t)Cy_PDM_PCM_Channel_ReadFifo(PDM0, LEFT_CH_INDEX);
            data = (int32_t)Cy_PDM_PCM_Channel_ReadFifo(PDM0, RIGHT_CH_INDEX);
            *(ping_pong_buffer_pointer) = (int16_t)(data);
            ping_pong_buffer_pointer++;
#endif
        }

        if (pdm_pcm_intr_cnt < PDM_PCM_FRAME_INTR_CNT)
        {
            pdm_pcm_intr_cnt++;
        }

        if (PDM_PCM_FRAME_INTR_CNT == pdm_pcm_intr_cnt)
        {
            pdm_pcm_intr_cnt = 0;
            rt_memcpy(mic_dev.rx_fifo, ping_pong_local_pointer, RX_FIFO_SIZE);
            rt_audio_rx_done(&mic_dev.audio, mic_dev.rx_fifo, RX_FIFO_SIZE);
            ping_pong = !ping_pong;
            if (ping_pong)
            {
                ping_pong_local_pointer = mic_audio_app_buffer_ping;
            }
            else
            {
                ping_pong_local_pointer = mic_audio_app_buffer_pong;
            }
            ping_pong_buffer_pointer = ping_pong_local_pointer;
        }

        Cy_PDM_PCM_Channel_ClearInterrupt(PDM0, RIGHT_CH_INDEX, CY_PDM_PCM_INTR_RX_TRIGGER);
    }

    if ((CY_PDM_PCM_INTR_RX_FIR_OVERFLOW | CY_PDM_PCM_INTR_RX_OVERFLOW |
            CY_PDM_PCM_INTR_RX_IF_OVERFLOW | CY_PDM_PCM_INTR_RX_UNDERFLOW) & int_stat)
    {
        Cy_PDM_PCM_Channel_ClearInterrupt(PDM0, RIGHT_CH_INDEX, CY_PDM_PCM_INTR_MASK);
    }

    rt_interrupt_leave();
}

cy_rslt_t pdm_mic_interface_deinit(void)
{
    return CY_RSLT_SUCCESS;
}

void app_pdm_pcm_activate(void)
{
    /* Activate recording from channel after init Activate Channel */
    Cy_PDM_PCM_Activate_Channel(PDM0, LEFT_CH_INDEX);
    Cy_PDM_PCM_Activate_Channel(PDM0, RIGHT_CH_INDEX);
}

void app_pdm_pcm_deactivate(void)
{
    Cy_PDM_PCM_DeActivate_Channel(PDM0, LEFT_CH_INDEX);
    Cy_PDM_PCM_DeActivate_Channel(PDM0, RIGHT_CH_INDEX);
}

static inline int32_t convert_pdm_pcm_gain_to_scale(int16_t gain_val)
{
    /* The formula for gain in db is db = 20 * log_10(FIR1_GAIN / 2^scale),
    *  where FIR1_GAIN = 13921.
     * Solving for scale, we get: scale = log_2(FIR1_GAIN / 10^(db / 20))
     */

    /* Cmath only provides ln and log10, need to compute log_2 in terms of those */
    /* Gain is specified in 0.5 db steps in the interface */
    float desired_gain = ((float)gain_val) * PDM_GAIN_DB_STEPS_CONST;
    float inner_value = PDM_FIR1_GAIN_CONST / (powf(PDM_GAIN_CONVERT_CONST_10,
                        (desired_gain / PDM_GAIN_CONVERT_CONST_20)));
    float scale = logf(inner_value) / logf(PDM_GAIN_CONVERT_CONST_2);
    int32_t scale_rounded = (uint8_t)(scale + PDM_GAIN_DB_STEPS_CONST);
    return scale_rounded;
}

cy_rslt_t set_pdm_pcm_gain(int16_t gain)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    cy_en_pdm_pcm_ch_fir1_decimcode_t decim_code;
    int32_t fir1_scale_value;

    if (gain < PDM_PCM_MIN_GAIN || gain > PDM_PCM_MAX_GAIN)
    {
        result = PDM_SET_GAIN_ERROR;
    }

    if (CY_RSLT_SUCCESS == result)
    {
        fir1_scale_value = convert_pdm_pcm_gain_to_scale(gain);
        if ((fir1_scale_value < 0) || (fir1_scale_value > PDM_FIR_MAX_SCALE_VALUE))
        {
            result = PDM_SET_GAIN_ERROR;
        }
    }

    if (CY_RSLT_SUCCESS == result)
    {
        decim_code = (cy_en_pdm_pcm_ch_fir1_decimcode_t) CY_PDM_PCM_CHAN_FIR1_DECIM_3;

        Cy_PDM_PCM_Channel_Set_Fir1(PDM0, LEFT_CH_INDEX, decim_code,
                                    fir1_scale_value);
        Cy_PDM_PCM_Channel_Set_Fir1(PDM0, RIGHT_CH_INDEX, decim_code,
                                    fir1_scale_value);
    }

    return result;
}

static rt_err_t mic_getcaps(struct rt_audio_device *audio, struct rt_audio_caps *caps)
{
    rt_err_t result = RT_EOK;
    struct mic_device *mic_dev = (struct mic_device *)audio->parent.user_data;

    switch (caps->main_type)
    {
    case AUDIO_TYPE_QUERY:
        switch (caps->sub_type)
        {
        case AUDIO_TYPE_QUERY:
            caps->udata.mask = AUDIO_TYPE_INPUT | AUDIO_TYPE_MIXER;
            break;
        default:
            result = -RT_ERROR;
            break;
        }
        break;

    case AUDIO_TYPE_INPUT:
        switch (caps->sub_type)
        {
        case AUDIO_DSP_PARAM:
            caps->udata.config.samplerate = mic_dev->record_config.samplerate;
            caps->udata.config.channels   = mic_dev->record_config.channels;
            caps->udata.config.samplebits = mic_dev->record_config.samplebits;
            break;
        case AUDIO_DSP_SAMPLERATE:
            caps->udata.config.samplerate = mic_dev->record_config.samplerate;
            break;
        case AUDIO_DSP_CHANNELS:
            caps->udata.config.channels   = mic_dev->record_config.channels;
            break;
        case AUDIO_DSP_SAMPLEBITS:
            caps->udata.config.samplebits = mic_dev->record_config.samplebits;
            break;
        default:
            result = -RT_ERROR;
            break;
        }
        break;

    case AUDIO_TYPE_MIXER:
        switch (caps->sub_type)
        {
        case AUDIO_MIXER_VOLUME:
            caps->udata.value = mic_dev->volume;
            break;
        default:
            result = -RT_ERROR;
            break;
        }
        break;

    default:
        result = -RT_ERROR;
        break;
    }

    return result;
}

static rt_err_t mic_configure(struct rt_audio_device *audio, struct rt_audio_caps *caps)
{
    rt_err_t result = RT_EOK;
    struct mic_device *mic_dev = (struct mic_device *)audio->parent.user_data;
    switch (caps->main_type)
    {
    case AUDIO_TYPE_INPUT:
        switch (caps->sub_type)
        {
        case AUDIO_DSP_PARAM:
            /* Save configuration */
            mic_dev->record_config.samplerate = caps->udata.config.samplerate;
            mic_dev->record_config.channels   = caps->udata.config.channels;
            mic_dev->record_config.samplebits = caps->udata.config.samplebits;

            LOG_D("Set samplerate: %d, channels: %d, samplebits: %d",
                  mic_dev->record_config.samplerate, mic_dev->record_config.channels,
                  mic_dev->record_config.samplebits);
            break;

        default:
            result = -RT_ERROR;
            break;
        }
        break;

    case AUDIO_TYPE_MIXER:
        switch (caps->sub_type)
        {
        case AUDIO_MIXER_VOLUME:
            mic_dev->volume = caps->udata.value;
            set_pdm_pcm_gain(mic_dev->volume);
            LOG_D("Set volume: %d\r\n", mic_dev->volume);
            break;
        default:
            result = -RT_ERROR;
            break;
        }
        break;

    default:
        result = -RT_ERROR;
        break;
    }

    return result;
}

static rt_err_t mic_init(struct rt_audio_device *audio)
{
    /* Initialize PDM/PCM block */
    Cy_PDM_PCM_Init(PDM0, &CYBSP_PDM_config);

    /* Enable PDM channel, we will activate channel for record later */
    Cy_PDM_PCM_Channel_Enable(PDM0, LEFT_CH_INDEX);
    Cy_PDM_PCM_Channel_Enable(PDM0, RIGHT_CH_INDEX);

    /* Initialize PDM/PCM channel 0 -Left, 1 -Right */
    Cy_PDM_PCM_Channel_Init(PDM0, &LEFT_CH_CONFIG, (uint8_t)LEFT_CH_INDEX);
    Cy_PDM_PCM_Channel_Init(PDM0, &RIGHT_CH_CONFIG, (uint8_t)RIGHT_CH_INDEX);

    /* Set the gain for both left and right channels. */
    set_pdm_pcm_gain(mic_dev.volume);

    /* As registred for right channel, clear and set maks for it. */
    Cy_PDM_PCM_Channel_ClearInterrupt(PDM0, RIGHT_CH_INDEX, CY_PDM_PCM_INTR_MASK);
    Cy_PDM_PCM_Channel_SetInterruptMask(PDM0, RIGHT_CH_INDEX, CY_PDM_PCM_INTR_MASK);

    /* Register the PDM/PCM hardware block IRQ handler */
    if (CY_SYSINT_SUCCESS != Cy_SysInt_Init(&PDM_IRQ_cfg, &pdm_interrupt_handler))
    {
        LOG_D("PDM/PCM Initialization has failed! \r\n");
        CY_ASSERT(0);
    }

    LOG_D("PDM/PCM Initialization Successful \r\n");
    NVIC_ClearPendingIRQ(PDM_IRQ_cfg.intrSrc);
    NVIC_EnableIRQ(PDM_IRQ_cfg.intrSrc);

    return RT_EOK;
}


static rt_err_t mic_start(struct rt_audio_device *audio, int stream)
{
    struct mic_device *mic_dev = (struct mic_device *)audio->parent.user_data;

    if (stream == AUDIO_STREAM_RECORD && !mic_dev->is_running)
    {
        app_pdm_pcm_activate();
        rt_audio_rx_done(&mic_dev->audio, mic_dev->rx_fifo, 0);
        mic_dev->is_running = RT_TRUE;
        LOG_D("Microphone started");
    }

    return RT_EOK;
}

static rt_err_t mic_stop(struct rt_audio_device *audio, int stream)
{
    struct mic_device *mic_dev = (struct mic_device *)audio->parent.user_data;

    if (stream == AUDIO_STREAM_RECORD && mic_dev->is_running)
    {
        app_pdm_pcm_deactivate();
        mic_dev->is_running = RT_FALSE;
        LOG_D("Microphone stopped");
    }

    return RT_EOK;
}

static struct rt_audio_ops mic_ops =
{
    .getcaps     = mic_getcaps,
    .configure   = mic_configure,
    .init        = mic_init,
    .start       = mic_start,
    .stop        = mic_stop,
    .transmit    = RT_NULL,
    .buffer_info = RT_NULL,
};

int rt_hw_pdm_init(void)
{
    rt_uint8_t *rx_fifo;

    rx_fifo = rt_malloc(RX_FIFO_SIZE);
    if (rx_fifo == RT_NULL)
    {
        LOG_E("Failed to allocate RX FIFO");
        return -RT_ENOMEM;
    }

    rt_memset(rx_fifo, 0, RX_FIFO_SIZE);

    mic_dev.rx_fifo = rx_fifo;

    /* Set default configuration */
    mic_dev.record_config.samplerate = 16000;
    mic_dev.record_config.channels   = 2;
    mic_dev.record_config.samplebits = 16;
    mic_dev.volume                   = 40; /* gain */
    mic_dev.is_running               = RT_FALSE;

    mic_dev.audio.ops = &mic_ops;
    LOG_I("audio pdm registered.\n");
    LOG_I("!!!Note: pdm depends on i2s0, they share clock.\n");
    rt_audio_register(&mic_dev.audio, "mic0", RT_DEVICE_FLAG_RDONLY, &mic_dev);

    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_hw_pdm_init);
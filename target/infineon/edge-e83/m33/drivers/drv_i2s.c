#include <rtthread.h>
#include <rtdevice.h>
#include "drv_i2s.h"
#include "cy_pdl.h"
#include "mtb_hal.h"
#include "cybsp.h"
#include "IFX_asrc.h"
#include "drv_es8388.h"
#include <rthw.h>
#include <rtdevice.h>
#define DBG_TAG              "i2s"
#define DBG_LVL              DBG_INFO
#include <rtdbg.h>

typedef enum
{
    i2s_state_stop,
    i2s_state_read,
    i2s_state_write,
} ifx_i2s_state_t;

typedef struct
{
    rt_uint32_t data_len;
    rt_int16_t *data;
} i2s_playback_q_data_t;

static int16_t i2s_stereo_playback_buffer1[PLAYBACK_DATA_FRAME_SIZE] __attribute__((section(".cy_socmem_data"))) = { 0 };
static int16_t i2s_stereo_playback_buffer2[PLAYBACK_DATA_FRAME_SIZE] __attribute__((section(".cy_socmem_data"))) = { 0 };

static int16_t *active_i2s_playback_buffer_ptr = NULL;
static int16_t *inactive_i2s_playback_buffer_ptr = NULL;

bool first_frame = true;
bool i2s_deinit_flag = false;
bool i2s_skip_frame = false;

#define TX_FIFO_SIZE         (4096)

static volatile bool i2s_data_ready_flag = false;

uint8_t i2s_playback_volume = DEFAULT_VOLUME;
/* ASRC variables for down-sampling audio to 16000Hz */
IFX_ASRC_STRUCT_t asrc_mem_down_sampling;
#if SAMPLING_RATE_44_1kHz == SAMPLING_RATE
/* ASRC variables for up-sampling 44100Hz to 48000Hz */
IFX_ASRC_STRUCT_t asrc_mem_up_sampling;
#endif /* SAMPLING_RATE_44_1kHz */

// static rt_uint32_t input_sampling_freq = 0;
// static rt_uint32_t output_sampling_freq = 0;
// static uint16_t asrc_out_len = 0;

/* Definition of buffers for ASRC, AEC and I2S */
// static int32_t asrc_in_i2s_playback_buffer_32bit[FRAME_SIZE]           __attribute__ ((section(".cy_socmem_data"))) = { 0 };
// static int32_t asrc_out_aec_ref_buffer_32bit[ASRC_OUTPUT_BUFFER_SIZE]  __attribute__ ((section(".cy_socmem_data"))) = { 0 };
// static int16_t asrc_out_aec_ref_buffer_16bit[AEC_REF_FRAME_SIZE]       __attribute__ ((section(".cy_socmem_data"))) = { 0 };
#if SAMPLING_RATE_44_1kHz == SAMPLING_RATE
static int16_t asrc_out_up_sampled_buffer_16bit[PLAYBACK_DATA_FRAME_SIZE / 2]  __attribute__((section(".cy_socmem_data"))) = { 0 };
#endif /* SAMPLING_RATE_44_1kHz */
static int16_t i2s_stereo_zero_buffer[PLAYBACK_DATA_FRAME_SIZE]        __attribute__((section(".cy_socmem_data"))) = { 0 };
static int16_t aec_ref_zero_buffer[AEC_REF_FRAME_SIZE]                 __attribute__((section(".cy_socmem_data"))) = { 0 };
int16_t *i2s_playback_ptr = i2s_stereo_zero_buffer;

/* Pointer declarations for AEC Reference ASRC implementation */
// static int16_t* frame_in_buffer;
// static int16_t* frame_out_buffer;
static int16_t *aec_ref_cb_ptr = NULL;

uint8_t i2s_32_samples_frame_count = 0;

const cy_stc_sysint_t i2s_isr_txcfg =
{
    .intrSrc = (IRQn_Type) tdm_0_interrupts_tx_0_IRQn,
    .intrPriority = I2S_INTR_PRIORITY,
};

struct sound_device
{
    struct rt_audio_device audio;
    struct rt_audio_configure audio_config;
    char *dev_name;

    rt_uint8_t *tx_buff;
    rt_mq_t tx_mq;
    rt_sem_t tx_sem;

    rt_uint8_t *rx_buff;
    ifx_i2s_state_t i2s_state;
    rt_uint8_t volume;

    rt_thread_t playback_thread;
};
static struct sound_device snd_dev = {0};

static char msg_pool[512];

bool music_player_active = false;
bool music_player_pause = false;

typedef struct
{
    rt_uint32_t data_len;
    uint8_t *data;
} music_player_q_data_t;

void i2s_playback_task(void *arg);

void ifx_i2s_init(void)
{
    /* Initialize the I2S interrupt */
    Cy_SysInt_Init(&i2s_isr_txcfg, i2s_tx_interrupt_handler);
    NVIC_EnableIRQ(i2s_isr_txcfg.intrSrc);

    /* Initialize the I2S */
    cy_en_tdm_status_t volatile return_status = Cy_AudioTDM_Init(TDM_STRUCT0, &CYBSP_TDM_CONTROLLER_0_config);
    if (CY_TDM_SUCCESS != return_status)
    {
        RT_ASSERT(0);
    }

    /* Clear TX interrupts */
    Cy_AudioTDM_ClearTxInterrupt(TDM_STRUCT0_TX, CY_TDM_INTR_TX_MASK);
    Cy_AudioTDM_SetTxInterruptMask(TDM_STRUCT0_TX, CY_TDM_INTR_TX_MASK);
}
void ifx_i2s_deinit()
{
    i2s_deinit_flag = true;

    if (!first_frame)
    {
        Cy_AudioTDM_DeActivateTx(TDM_STRUCT0_TX);
        Cy_AudioI2S_DisableTx(TDM_STRUCT0_TX);

        // Cy_AudioTDM_DeInit(TDM_STRUCT0_TX);
        first_frame = true;
    }
}

void ifx_set_samplerate(struct rt_audio_configure audio_config)
{
    Cy_SysClk_PeriPclkDisableDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U);
    if (audio_config.channels == 1)
    {
        switch (audio_config.samplerate)
        {
            case 16000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 24U, 0U);
                break;
            case 24000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 16U, 0U);
                break;
            case 48000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 8U, 0U);
                break;
            case 96000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 3U, 0U);
                break;
            default:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 24U, 0U);
                break;
        }
    }
    else
    {
        switch (audio_config.samplerate)
        {
            case 16000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 11U, 0U);
                break;
            case 24000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 7U, 0U);
                break;
            case 48000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 3U, 0U);
                break;
            case 96000:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 1U, 0U);
                break;
            default:
                Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 11U, 0U);
                break;
        }
    }
    #if defined(BSP_USING_XiaoZhi)
        Cy_SysClk_PeriPclkSetFracDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U, 15U, 0U);
    #endif
    Cy_SysClk_PeriPclkEnableDivider((en_clk_dst_t)CYBSP_TDM_CONTROLLER_0_CLK_DIV_GRP_NUM, CY_SYSCLK_DIV_16_5_BIT, 0U);
}

void app_i2s_clear_tx_fifo(void)
{
    /* To clear FIFO there is no direct way so Disable and Enable Tx, FIFO will be cleared as a side effect */
    Cy_AudioI2S_DisableTx(TDM_STRUCT0_TX);
    Cy_AudioI2S_EnableTx(TDM_STRUCT0_TX);
    Cy_AudioI2S_DisableTx(TDM_STRUCT0_TX);
}

void app_i2s_activate(void)
{
    /* Activate and enable I2S TX interrupts */
    Cy_AudioTDM_ActivateTx(TDM_STRUCT0_TX);
}

void app_i2s_enable(void)
{
    /* Clear TX interrupts */
    Cy_AudioTDM_ClearTxInterrupt(TDM_STRUCT0_TX, CY_TDM_INTR_TX_MASK);
    Cy_AudioTDM_SetTxInterruptMask(TDM_STRUCT0_TX, CY_TDM_INTR_TX_MASK);

    /* Start the I2S TX */
    Cy_AudioTDM_EnableTx(TDM_STRUCT0_TX);
}

void app_i2s_deactivate(void)
{
    /* Deactivate and enable I2S TX interrupts */
    Cy_AudioTDM_DeActivateTx(TDM_STRUCT0_TX);
}

/**
 * RT-Thread Audio Device Driver Interface
 */
static rt_err_t sound_getcaps(struct rt_audio_device *audio, struct rt_audio_caps *caps)
{
    rt_err_t result = RT_EOK;
    struct sound_device *snd_dev;

    RT_ASSERT(audio != RT_NULL);
    snd_dev = (struct sound_device *)audio->parent.user_data;

    switch (caps->main_type)
    {
    case AUDIO_TYPE_QUERY: /* qurey the types of hw_codec device */
    {
        switch (caps->sub_type)
        {
        case AUDIO_TYPE_QUERY:
            // caps->udata.mask = AUDIO_TYPE_OUTPUT | AUDIO_TYPE_MIXER;
            break;

        default:
            result = -RT_ERROR;
            break;
        }

        break;
    }

    case AUDIO_TYPE_OUTPUT: /* Provide capabilities of OUTPUT unit */
    {
        switch (caps->sub_type)
        {
        case AUDIO_DSP_PARAM:
            caps->udata.config.samplerate   = snd_dev->audio_config.samplerate;
            caps->udata.config.channels     = snd_dev->audio_config.channels;
            caps->udata.config.samplebits   = snd_dev->audio_config.samplebits;
            break;

        case AUDIO_DSP_SAMPLERATE:
            caps->udata.config.samplerate   = snd_dev->audio_config.samplerate;
            break;

        case AUDIO_DSP_CHANNELS:
            caps->udata.config.channels     = snd_dev->audio_config.channels;
            break;

        case AUDIO_DSP_SAMPLEBITS:
            caps->udata.config.samplebits   = snd_dev->audio_config.samplebits;
            break;

        default:
            result = -RT_ERROR;
            break;
        }

        break;
    }

    case AUDIO_TYPE_MIXER: /* report the Mixer Units */
    {
        switch (caps->sub_type)
        {
        case AUDIO_MIXER_QUERY:
            caps->udata.mask = AUDIO_MIXER_VOLUME;
            break;

        case AUDIO_MIXER_VOLUME:
            // caps->udata.value =  es8388_volume_get();
            break;

        default:
            result = -RT_ERROR;
            break;
        }

        break;
    }

    default:
        result = -RT_ERROR;
        break;
    }

    return result;
}

static rt_err_t sound_configure(struct rt_audio_device *audio, struct rt_audio_caps *caps)
{
    rt_err_t result = RT_EOK;
    struct sound_device *snd_dev;

    RT_ASSERT(audio != RT_NULL);
    snd_dev = (struct sound_device *)audio->parent.user_data;

    switch (caps->main_type)
    {
    case AUDIO_TYPE_MIXER:
    {
        switch (caps->sub_type)
        {
        case AUDIO_MIXER_VOLUME:
        {
            rt_uint8_t volume = caps->udata.value;
            snd_dev->volume = volume;
            es8388_volume_set(snd_dev->volume);
            LOG_D("set volume %d", volume);
            break;
        }

        default:
            result = -RT_ERROR;
            break;
        }

        break;
    }

    case AUDIO_TYPE_OUTPUT:
    {
        switch (caps->sub_type)
        {
        case AUDIO_DSP_PARAM:
        {
            /* save configs */
            snd_dev->audio_config.samplerate = caps->udata.config.samplerate;
            snd_dev->audio_config.channels   = caps->udata.config.channels;
            snd_dev->audio_config.samplebits = caps->udata.config.samplebits;
            ifx_set_samplerate(snd_dev->audio_config);
            LOG_D("set samplerate %d", snd_dev->audio_config.samplerate);
            break;
        }

        case AUDIO_DSP_SAMPLERATE:
        {
            snd_dev->audio_config.samplerate = caps->udata.config.samplerate;
            ifx_set_samplerate(snd_dev->audio_config);
            LOG_D("set samplerate %d", snd_dev->audio_config.samplerate);
            break;
        }

        case AUDIO_DSP_CHANNELS:
        {
            // SAIA_Channels_Set(caps->udata.config.channels);
            // snd_dev->audio_config.channels   = caps->udata.config.channels;
            // LOG_D("set channels %d", snd_dev->audio_config.channels);
            break;
        }

        case AUDIO_DSP_SAMPLEBITS:
        {
            /* not support */
            // snd_dev->audio_config.samplebits = caps->udata.config.samplebits;
            break;
        }

        default:
            result = -RT_ERROR;
            break;
        }

        break;
    }

    default:
        break;
    }

    return result;
}

static rt_err_t sound_init(struct rt_audio_device *audio)
{
    rt_err_t result = RT_EOK;

    struct sound_device *snd_dev;

    RT_ASSERT(audio != RT_NULL);

    snd_dev = (struct sound_device *)audio->parent.user_data;

    ifx_i2s_init();

    if (es8388_init("i2c0", RT_NULL) != RT_EOK)
    {
        LOG_E("ES8388 init failed.");
        RT_ASSERT(0);
    }

    es8388_start(ES_MODE_DAC);

    es8388_volume_set(20);
    ifx_set_samplerate(snd_dev->audio_config);

    rt_thread_startup(snd_dev->playback_thread);

    LOG_I("ES8388 init success.");
    return result;
}

static rt_err_t sound_start(struct rt_audio_device *audio, int stream)
{
    RT_ASSERT(audio != RT_NULL);

    if (stream == AUDIO_STREAM_REPLAY)
    {
        music_player_active = true;
        LOG_I("Ready for I2S output \r\n");
        rt_audio_tx_complete(audio);
    }

    return RT_EOK;
}

static rt_ssize_t sound_transmit(struct rt_audio_device *audio, const void *writeBuf, void *readBuf, rt_size_t size)
{
    struct sound_device *snd_dev;
    RT_ASSERT(audio != RT_NULL);
    snd_dev = (struct sound_device *)audio->parent.user_data;
    if (size > 0)
    {
        i2s_playback_q_data_t i2s_playback_q_data;
        i2s_playback_q_data.data_len = size >> 1;
        i2s_playback_q_data.data = (rt_int16_t *) writeBuf;
        rt_mq_send(snd_dev->tx_mq, &i2s_playback_q_data, sizeof(i2s_playback_q_data_t));
    }
    return size;
}

static rt_err_t sound_stop(struct rt_audio_device *audio, int stream)
{
    RT_ASSERT(audio != RT_NULL);
    if (stream == AUDIO_STREAM_REPLAY)
    {
//        music_player_active = false;
//        first_frame=true;
//        app_i2s_deactivate();
//        rt_thread_detach(snd_dev->playback_thread);
//        while(audio->replay->queue.is_empty==0)
//        rt_data_queue_reset(&audio->replay->queue);
//        audio->replay->write_index = 0;
//        audio->replay->read_index = 0;
//        audio->replay->pos = 0;
//        i2s_data_ready_flag = false;

//            rt_audio_tx_complete(audio);
        LOG_D("Sound Stop.");
    }

    return RT_EOK;
}

static void sound_buffer_info(struct rt_audio_device *audio, struct rt_audio_buf_info *info)
{
    struct sound_device *snd_dev;
    RT_ASSERT(audio != RT_NULL);
    snd_dev = (struct sound_device *)audio->parent.user_data;

    /**
     *               TX_FIFO
     * +----------------+----------------+
     * |     block1     |     block2     |
     * +----------------+----------------+
     *  \  block_size  /
     */
    info->buffer      = snd_dev->tx_buff;
    info->total_size  = TX_FIFO_SIZE;
    info->block_size  = TX_FIFO_SIZE / 2;
    info->block_count = 2;
}



static struct rt_audio_ops snd_ops =
{
    .getcaps     = sound_getcaps,
    .configure   = sound_configure,
    .init        = sound_init,
    .start       = sound_start,
    .stop        = sound_stop,
    .transmit    = sound_transmit,
    .buffer_info = sound_buffer_info,
};

int rt_hw_sound_init(void)
{
    rt_err_t ret = RT_EOK;
    rt_uint8_t *tx_buff;

    tx_buff = (rt_uint8_t *)rt_malloc(TX_FIFO_SIZE);

    rt_memset(tx_buff, 0, TX_FIFO_SIZE);
    if (tx_buff == RT_NULL)
        return -RT_ENOMEM;
    snd_dev.tx_buff = tx_buff;
    /* init default configuration */
    snd_dev.audio_config.samplerate = 16000;
    snd_dev.audio_config.channels   = 2;
    snd_dev.audio_config.samplebits = 16;
    snd_dev.volume                   = 70;

    snd_dev.audio.ops = &snd_ops;

    snd_dev.tx_mq = rt_mq_create(
                        "sound_tx_mq",
                        sizeof(i2s_playback_q_data_t),
                        sizeof(msg_pool),
                        RT_IPC_FLAG_FIFO);

    snd_dev.tx_sem = rt_sem_create("sound_tx_sem", 0, RT_IPC_FLAG_FIFO);
    if (snd_dev.tx_sem == RT_NULL)
    {
        LOG_E("create sound tx_sem failed.\n");
        return -RT_ERROR;
    }


    snd_dev.playback_thread = rt_thread_create("sound_thread", i2s_playback_task, (void *)&snd_dev.audio, I2S_PLAYBACK_TASK_STACK_SIZE, I2S_PLAYBACK_TASK_PRIORITY, 10);
    if (snd_dev.playback_thread == RT_NULL)
    {
        LOG_E("Error in I2S playback task \r\n");
        RT_ASSERT(snd_dev.playback_thread != RT_NULL);
    }

    ret = rt_audio_register(&snd_dev.audio, "sound0", RT_DEVICE_FLAG_WRONLY, &snd_dev);

    if (ret != RT_EOK)
    {
        LOG_E("rt_audio %s register failed, status=%d\n", "sound0", ret);
        return -RT_ERROR;
    }

    return RT_EOK;
}
INIT_DEVICE_EXPORT(rt_hw_sound_init);

void i2s_write_32_samples(void)
{
    i2s_32_samples_frame_count = 1;
    for (int i = 0; i < HW_FIFO_SIZE; i++)
    {
        /* Write same data for L,R channels(dual mono) in FIFO */
        Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) * ((i2s_playback_ptr + (HW_FIFO_SIZE * (i2s_32_samples_frame_count - 1))) + i));
        i++;
        Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) * ((i2s_playback_ptr + (HW_FIFO_SIZE * (i2s_32_samples_frame_count - 1))) + i));
    }
    i2s_32_samples_frame_count = 2;
}

void convert_mono_to_stereo(int16_t *mono_data, rt_uint32_t mono_data_num_samples,
                            int16_t *stereo_data)
{
    for (rt_uint32_t i = 0; i < mono_data_num_samples; i++)
    {
        *stereo_data++ = *mono_data;  // Copy the mono sample to the left channel
        *stereo_data++ = *mono_data;  // Copy the same mono sample to the right channel
        mono_data++;  // Move to the next mono sample
    }
}

void i2s_playback_task(void *arg)
{
    struct rt_audio_device *audio = (struct rt_audio_device *)arg;
    struct sound_device *snd_dev;
    RT_ASSERT(audio != RT_NULL);
    snd_dev = (struct sound_device *)audio->parent.user_data;
    static int count = 0;
    int16_t *temp_buffer_ptr;

    // int32_t* asrc_out_ptr = NULL;

    i2s_playback_q_data_t i2s_playback_q_data;

    active_i2s_playback_buffer_ptr = i2s_stereo_playback_buffer1;
    inactive_i2s_playback_buffer_ptr = i2s_stereo_playback_buffer2;

    while (1)
    {
        rt_mq_recv(snd_dev->tx_mq, &i2s_playback_q_data, sizeof(i2s_playback_q_data_t), RT_WAITING_FOREVER);

        /* Clear the flags, queues and notifications in case of I2S de-init.
         * This occurs when the "Stop Music" command is given.
         */
        if (i2s_deinit_flag)
        {
            i2s_deinit_flag = false;
            first_frame = true;
            rt_memset(&msg_pool[0], 0, sizeof(msg_pool));
            continue;
        }

#if SAMPLING_RATE_44_1kHz == SAMPLING_RATE
        /* The 'first_frame' flag is set only during the 1st frame of
        * playback for a new file.
        */
        if (first_frame)
        {

            /* Initialize ASRC for up sampling 44.1KHz to 48kHz playback data */
            input_sampling_freq = SAMPLING_RATE_44_1kHz;
            output_sampling_freq = SAMPLING_RATE_48kHz;

            init_IFX_asrc(&asrc_mem_up_sampling, input_sampling_freq, output_sampling_freq);
            IFX_SetClockDrift(&asrc_mem_up_sampling, 0);
        }

        frame_in_buffer = (int16_t *) i2s_playback_q_data.data;
        for (rt_uint32_t i = 0; i < FRAME_SIZE; i++)
        {
            asrc_in_i2s_playback_buffer_32bit[i] = (int32_t)
                                                   (*(int16_t *)frame_in_buffer);
            frame_in_buffer ++;
        }
        asrc_out_len = ASRC_OUTPUT_BUFFER_SIZE;
        asrc_out_ptr = asrc_out_aec_ref_buffer_32bit;
        frame_out_buffer = asrc_out_up_sampled_buffer_16bit;
        /* IFX_asrc() called 2 times to pass 441 samples, 240 and 201 in each call.*/
        for (rt_uint32_t i = 0; i < ASRC_NUM_ITERATIONS_PER_FRAME; i++)
        {
            if ((ASRC_NUM_ITERATIONS_PER_FRAME - 1) != i)
            {
                IFX_asrc(asrc_in_i2s_playback_buffer_32bit +
                         ASRC_INPUT_SAMPLES * i, ASRC_INPUT_SAMPLES,
                         asrc_out_ptr, &asrc_out_len, &asrc_mem_up_sampling);
            }
            else
            {
                IFX_asrc(asrc_in_i2s_playback_buffer_32bit +
                         ASRC_INPUT_SAMPLES * i, 201,
                         asrc_out_ptr, &asrc_out_len, &asrc_mem_up_sampling);
            }
            /* Convert int32_t to int16_t */
            for (rt_uint32_t j = 0; j < asrc_out_len; j++)
            {
                *(frame_out_buffer++) = (int16_t)(*(asrc_out_ptr + j));
            }
            asrc_out_ptr += asrc_out_len;
        }
#endif

        /* Convert the input mono channel audio to stereo by appropriate zero
            * padding for playback over I2S.
            */
#if SAMPLING_RATE_44_1kHz == SAMPLING_RATE
        convert_mono_to_stereo((int16_t *)asrc_out_up_sampled_buffer_16bit,
                               (PLAYBACK_DATA_FRAME_SIZE / 2),
                               inactive_i2s_playback_buffer_ptr);
#else
        convert_mono_to_stereo((int16_t *)i2s_playback_q_data.data,
                               (i2s_playback_q_data.data_len),
                               inactive_i2s_playback_buffer_ptr);
#endif

        temp_buffer_ptr = active_i2s_playback_buffer_ptr;
        active_i2s_playback_buffer_ptr = inactive_i2s_playback_buffer_ptr;
        inactive_i2s_playback_buffer_ptr = temp_buffer_ptr;
        i2s_data_ready_flag = true;

        /* The 'first_frame' flag is set only during the 1st frame of
         * playback for a new file.
         */
        if (first_frame)
        {
#if SAMPLING_RATE_16kHz != SAMPLING_RATE
            /* Initialize ASRC for 16kHz AEC reference */
            input_sampling_freq = SAMPLING_RATE;
            output_sampling_freq = AEC_REF_SAMPLING_RATE;

            /* ASRC for 16KHz aec ref from 44.1KHz/48KHz playback data */
            init_IFX_asrc(&asrc_mem_down_sampling, input_sampling_freq, output_sampling_freq);
            IFX_SetClockDrift(&asrc_mem_down_sampling, 0);
#endif
            /* Only for the first frame, the I2S write happens from this task. */
            if (!i2s_deinit_flag)
            {
                app_i2s_enable();

                for (int i = 0; i < HW_FIFO_SIZE; i++)
                {
                    /* Write same data for L,R channels(dual mono) in FIFO */
                    Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) 0);
                    i++;
                    Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) 0);
                }
                app_i2s_activate();
                es8388_volume_set(snd_dev->volume);
            }
            i2s_data_ready_flag = false;
        }

        /* Perform ASRC for sampling rates apart from 16kHz and enqueue the
         * AEC reference data in a circular buffer.
         */
#if SAMPLING_RATE_16kHz != SAMPLING_RATE
        frame_in_buffer = (int16_t *) i2s_playback_q_data.data;
        for (rt_uint32_t i = 0; i < FRAME_SIZE; i++)
        {
            asrc_in_i2s_playback_buffer_32bit[i] = (int32_t)
                                                   (*(int16_t *)frame_in_buffer);
            frame_in_buffer ++;
        }

        asrc_out_len = ASRC_OUTPUT_BUFFER_SIZE;
        asrc_out_ptr = asrc_out_aec_ref_buffer_32bit;
        frame_out_buffer = asrc_out_aec_ref_buffer_16bit;
        /* IFX_asrc() called 2 times to pass the samples */
        for (rt_uint32_t i = 0; i < ASRC_NUM_ITERATIONS_PER_FRAME; i++)
        {
            if (SAMPLING_RATE_48kHz == SAMPLING_RATE)
            {
                IFX_asrc(asrc_in_i2s_playback_buffer_32bit +
                         ASRC_INPUT_SAMPLES * i, ASRC_INPUT_SAMPLES,
                         asrc_out_ptr, &asrc_out_len, &asrc_mem_down_sampling);
            }
            if (SAMPLING_RATE_44_1kHz == SAMPLING_RATE)
            {
                if ((ASRC_NUM_ITERATIONS_PER_FRAME - 1) != i)
                {
                    IFX_asrc(asrc_in_i2s_playback_buffer_32bit +
                             ASRC_INPUT_SAMPLES * i, ASRC_INPUT_SAMPLES,
                             asrc_out_ptr, &asrc_out_len, &asrc_mem_down_sampling);
                }
                else
                {
                    IFX_asrc(asrc_in_i2s_playback_buffer_32bit +
                             ASRC_INPUT_SAMPLES * i, (FRAME_SIZE - ASRC_INPUT_SAMPLES),
                             asrc_out_ptr, &asrc_out_len, &asrc_mem_down_sampling);
                }
            }
            /* Convert int32_t to int16_t */
            for (rt_uint32_t j = 0; j < asrc_out_len; j++)
            {
                *(frame_out_buffer++) = (int16_t)(*(asrc_out_ptr + j));
            }
            asrc_out_ptr += asrc_out_len;
        }

#endif

        /* Only for the first frame, push the AEC reference data from the task. */

        /* Wait for notification from I2S ISR for completion of previous
         * audio frame playback.
         */
        if (!first_frame && !i2s_deinit_flag)
        {
            rt_sem_take(snd_dev->tx_sem, RT_WAITING_FOREVER);
        }

        /* Reset first frame flag. */
        first_frame = false;
        while (audio->replay->queue.is_empty == 1)
        {
            rt_thread_mdelay(1);
#if defined(PKG_USING_WAVPLAYER) && !defined(BSP_USING_XiaoZhi)
            if(count>=50){
                rt_completion_done(&audio->replay->cmp);
                count=0;
            }
            count++;
#endif
        }
        rt_audio_tx_complete(audio);
    }
}


bool is_music_player_active(void)
{
    return music_player_active;
}

bool is_music_player_paused(void)
{
    return music_player_pause;
}

void i2s_tx_interrupt_handler(void)
{
    rt_interrupt_enter();

    /* Get interrupt status and check for tigger interrupt and errors */
    rt_uint32_t intr_status = Cy_AudioTDM_GetTxInterruptStatusMasked(TDM_STRUCT0_TX);

    if (CY_TDM_INTR_TX_FIFO_TRIGGER & intr_status)
    {
        if (((PLAYBACK_DATA_FRAME_SIZE / HW_FIFO_SIZE) + 1) == i2s_32_samples_frame_count)
        {
            /* When 5 frames of the data is written into I2S call 10msec frame handlling() */
            {
                // music_player_q_data_t music_player_q_data;

                /* Initially, set the I2S playback and AEC reference to zero buffers. */
                int16_t *aec_ref_temp_ptr = aec_ref_cb_ptr;
                aec_ref_cb_ptr = aec_ref_zero_buffer;

                /* Set the I2S playback and AEC reference pointers to actual data in case
                * the data is ready and audio playback is active.
                */
                if ((!i2s_deinit_flag && i2s_data_ready_flag) ||
                        (first_frame))
                {
                    i2s_data_ready_flag = false;
                    i2s_playback_ptr = active_i2s_playback_buffer_ptr;
                    aec_ref_cb_ptr = aec_ref_temp_ptr;
                }

                /* Unless deinitialized, play the data over I2S and send the corresponding
                * AEC reference pointer to the AEC reference queue.
                */
                if (!i2s_deinit_flag)
                {
                    i2s_write_32_samples();
                }

                /* If the non-zero data is played, notify the I2S task for processing of
                * playback data of next frames.
                */
                if ((i2s_playback_ptr == active_i2s_playback_buffer_ptr))
                {
                    rt_sem_release(snd_dev.tx_sem);
                }
            }
        }
        else
        {
            if (is_music_player_paused() || i2s_data_ready_flag == false)
            {
                for (int i = 0; i < HW_FIFO_SIZE; i++)
                {
                    /* Write same data for L,R channels(dual mono) in FIFO */
                    Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) 0);
                    i++;
                    Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) 0);
                }
            }
            else
            {
                for (int i = 0; i < HW_FIFO_SIZE; i++)
                {
                    /* Write same data for L,R channels(dual mono) in FIFO */
                    Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) * ((i2s_playback_ptr + (HW_FIFO_SIZE * (i2s_32_samples_frame_count - 1))) + i));
                    i++;
                    Cy_AudioTDM_WriteTxData(TDM_STRUCT0_TX, (rt_uint32_t) * ((i2s_playback_ptr + (HW_FIFO_SIZE * (i2s_32_samples_frame_count - 1))) + i));
                }
                i2s_32_samples_frame_count++;
            }

        }
    }
    else if (CY_TDM_INTR_TX_FIFO_UNDERFLOW & intr_status)
    {
        rt_kprintf("Error: I2S transmit underflowed\r\n");
    }

    /* Clear all Tx I2S Interrupt */
    Cy_AudioTDM_ClearTxInterrupt(TDM_STRUCT0_TX, CY_TDM_INTR_TX_MASK);

    rt_interrupt_leave();
}


/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 2003 - 2025     SEGGER Microcontroller GmbH              *
*                                                                    *
*       www.segger.com     Support: www.segger.com/ticket            *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device * USB Device stack for embedded applications    *
*                                                                    *
*       Please note: Knowledge of this file may under no             *
*       circumstances be used to write a similar product.            *
*       Thank you for your fairness !                                *
*                                                                    *
**********************************************************************
*                                                                    *
*       emUSB-Device version: V3.66.5                                *
*                                                                    *
**********************************************************************
----------------------------------------------------------------------
All Intellectual Property rights in the software belongs to SEGGER.
emUSB Device is protected by international copyright laws. This file
may only be used in accordance with the following terms:

The source code of the emUSB Device software has been licensed to Cypress
Semiconductor Corporation, whose registered office is 198 Champion
Court, San Jose, CA 95134, USA including the 
right to create and distribute the object code version of 
the emUSB Device software for its Cortex M0, M0+, M4, M33 and M55 based devices.
The object code version can be used by Cypress customers under the 
terms and conditions of the associated End User License Agreement.
Support for the object code version is provided by Cypress, 
full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Microcontroller Systems LLC
Licensed to:              Cypress Semiconductor Corp, 198 Champion Ct., San Jose, CA 95134, USA
Licensed SEGGER software: emUSB-Device
License number:           USBD-00500
License model:            Cypress Services and License Agreement, signed November 17th/18th, 2010
                          and Amendment Number One, signed December 28th, 2020 and February 10th, 2021
                          and Amendment Number Three, signed May 2nd, 2022 and May 5th, 2022 and Amendment Number Four, signed August 28th, 2023
Licensed platform:        Cypress devices containing ARM Cortex M cores: M0, M0+, M4, M33 and M55
----------------------------------------------------------------------
Support and Update Agreement (SUA)
SUA period:               2022-05-12 - 2026-05-19
Contact to extend SUA:    sales@segger.com
----------------------------------------------------------------------
Purpose : Implementation of the new generation USB Audio Class.
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_AC_H          /* Avoid multiple inclusion */
#define USBD_AC_H

#include "SEGGER.h"
#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

/*********************************************************************
*
*       Defines, fixed
*
**********************************************************************
*/
//
// Audio Class-Specific Request Codes for callback functions (Audio 1.0)
//
#define USB_AC_REQ_CUR                        0x01u
#define USB_AC_REQ_MIN                        0x02u
#define USB_AC_REQ_MAX                        0x03u
#define USB_AC_REQ_RES                        0x04u
#define USB_AC_REQ_MEM                        0x05u
#define USB_AC_REQ_STAT                       0x7Fu
//
// Audio Class-Specific Request Codes for callback functions (Audio 2.0)
//
//      USB_AC_REQ_CUR                        0x01u
#define USB_AC_REQ_RANGE                      0x02u

//
// Audio Control Selectors
//
#define USB_AC_CS_SAM_FREQ_CONTROL            0x01u
#define USB_AC_CS_CLOCK_VALID_CONTROL         0x02u

#define USB_AC_CX_CLOCK_SELECTOR_CONTROL      0x01u

#define USB_AC_CM_NUMERATOR_CONTROL           0x01u
#define USB_AC_CM_DENOMINATOR_CONTROL         0x02u

#define USB_AC_TE_COPY_PROTECT_CONTROL        0x01u
#define USB_AC_TE_CONNECTOR_CONTROL           0x02u
#define USB_AC_TE_OVERLOAD_CONTROL            0x03u
#define USB_AC_TE_CLUSTER_CONTROL             0x04u
#define USB_AC_TE_UNDERFLOW_CONTROL           0x05u
#define USB_AC_TE_OVERFLOW_CONTROL            0x06u
#define USB_AC_TE_LATENCY_CONTROL             0x07u

#define USB_AC_MU_MIXER_CONTROL               0x01u
#define USB_AC_MU_CLUSTER_CONTROL             0x02u
#define USB_AC_MU_UNDERFLOW_CONTROL           0x03u
#define USB_AC_MU_OVERFLOW_CONTROL            0x04u
#define USB_AC_MU_LATENCY_CONTROL             0x05u

#define USB_AC_SU_SELECTOR_CONTROL            0x01u
#define USB_AC_SU_LATENCY_CONTROL             0x02u

#define USB_AC_FU_MUTE_CONTROL                0x01u
#define USB_AC_FU_VOLUME_CONTROL              0x02u
#define USB_AC_FU_BASS_CONTROL                0x03u
#define USB_AC_FU_MID_CONTROL                 0x04u
#define USB_AC_FU_TREBLE_CONTROL              0x05u
#define USB_AC_FU_GRAPHIC_EQUALIZER_CONTROL   0x06u
#define USB_AC_FU_AUTOMATIC_GAIN_CONTROL      0x07u
#define USB_AC_FU_DELAY_CONTROL               0x08u
#define USB_AC_FU_BASS_BOOST_CONTROL          0x09u
#define USB_AC_FU_LOUDNESS_CONTROL            0x0Au
#define USB_AC_FU_INPUT_GAIN_CONTROL          0x0Bu
#define USB_AC_FU_INPUT_GAIN_PAD_CONTROL      0x0Cu
#define USB_AC_FU_PHASE_INVERTER_CONTROL      0x0Du
#define USB_AC_FU_UNDERFLOW_CONTROL           0x0Eu
#define USB_AC_FU_OVERFLOW_CONTROL            0x0Fu
#define USB_AC_FU_LATENCY_CONTROL             0x10u

#define USB_AC_PE_ENABLE_CONTROL              0x01u
#define USB_AC_PE_CENTERFREQ_CONTROL          0x02u
#define USB_AC_PE_QFACTOR_CONTROL             0x03u
#define USB_AC_PE_GAIN_CONTROL                0x04u
#define USB_AC_PE_UNDERFLOW_CONTROL           0x05u
#define USB_AC_PE_OVERFLOW_CONTROL            0x06u
#define USB_AC_PE_LATENCY_CONTROL             0x07u

#define USB_AC_RV_ENABLE_CONTROL              0x01u
#define USB_AC_RV_TYPE_CONTROL                0x02u
#define USB_AC_RV_LEVEL_CONTROL               0x03u
#define USB_AC_RV_TIME_CONTROL                0x04u
#define USB_AC_RV_FEEDBACK_CONTROL            0x05u
#define USB_AC_RV_PREDELAY_CONTROL            0x06u
#define USB_AC_RV_DENSITY_CONTROL             0x07u
#define USB_AC_RV_HIFREQ_ROLLOFF_CONTROLL     0x08u
#define USB_AC_RV_UNDERFLOW_CONTROL           0x09u
#define USB_AC_RV_OVERFLOW_CONTROL            0x0Au
#define USB_AC_RV_LATENCY_CONTROL             0x0Bu

#define USB_AC_MD_ENABLE_CONTROL              0x01u
#define USB_AC_MD_BALANCE_CONTROL             0x02u
#define USB_AC_MD_RATE_CONTROL                0x03u
#define USB_AC_MD_DEPTH_CONTROL               0x04u
#define USB_AC_MD_TIME_CONTROL                0x05u
#define USB_AC_MD_FEEDBACK_CONTROL            0x06u
#define USB_AC_MD_UNDERFLOW_CONTROL           0x07u
#define USB_AC_MD_OVERFLOW_CONTROL            0x08u
#define USB_AC_MD_LATENCY_CONTROL             0x09u

#define USB_AC_DR_ENABLE_CONTROL              0x01u
#define USB_AC_DR_COMPRESSION_RATE_CONTROL    0x02u
#define USB_AC_DR_MAXAMPL_CONTROL             0x03u
#define USB_AC_DR_THRESHOLD_CONTROL           0x04u
#define USB_AC_DR_ATTACK_TIME_CONTROL         0x05u
#define USB_AC_DR_RELEASE_TIME_CONTROL        0x06u
#define USB_AC_DR_UNDERFLOW_CONTROL           0x07u
#define USB_AC_DR_OVERFLOW_CONTROL            0x08u
#define USB_AC_DR_LATENCY_CONTROL             0x09u

#define USB_AC_UD_ENABLE_CONTROL              0x01u
#define USB_AC_UD_MODE_SELECT_CONTROL         0x02u
#define USB_AC_UD_CLUSTER_CONTROL             0x03u
#define USB_AC_UD_UNDERFLOW_CONTROL           0x04u
#define USB_AC_UD_OVERFLOW_CONTROL            0x05u
#define USB_AC_UD_LATENCY_CONTROL             0x06u

#define USB_AC_DP_ENABLE_CONTROL              0x01u
#define USB_AC_DP_MODE_SELECT_CONTROL         0x02u
#define USB_AC_DP_CLUSTER_CONTROL             0x03u
#define USB_AC_DP_UNDERFLOW_CONTROL           0x04u
#define USB_AC_DP_OVERFLOW_CONTROL            0x05u
#define USB_AC_DP_LATENCY_CONTROL             0x06u

#define USB_AC_ST_EXT_ENABLE_CONTROL          0x01u
#define USB_AC_ST_EXT_WIDTH_CONTROL           0x02u
#define USB_AC_ST_EXT_UNDERFLOW_CONTROL       0x03u
#define USB_AC_ST_EXT_OVERFLOW_CONTROL        0x04u
#define USB_AC_ST_EXT_LATENCY_CONTROL         0x05u

#define USB_AC_XU_ENABLE_CONTROL              0x01u
#define USB_AC_XU_CLUSTER_CONTROL             0x02u
#define USB_AC_XU_UNDERFLOW_CONTROL           0x03u
#define USB_AC_XU_OVERFLOW_CONTROL            0x04u
#define USB_AC_XU_LATENCY_CONTROL             0x05u

#define USB_AC_AS_ACT_ALT_SETTING_CONTROL     0x01u
#define USB_AC_AS_VAL_ALT_SETTINGS_CONTROL    0x02u
#define USB_AC_AS_AUDIO_DATA_FORMAT_CONTROL   0x03u

#define USB_AC_EN_BIT_RATE_CONTROL            0x01u
#define USB_AC_EN_QUALITY_CONTROL             0x02u
#define USB_AC_EN_VBR_CONTROL                 0x03u
#define USB_AC_EN_TYPE_CONTROL                0x04u
#define USB_AC_EN_UNDERFLOW_CONTROL           0x05u
#define USB_AC_EN_OVERFLOW_CONTROL            0x06u
#define USB_AC_EN_ENCODER_ERROR_CONTROL       0x07u
#define USB_AC_EN_PARAM1_CONTROL              0x08u
#define USB_AC_EN_PARAM2_CONTROL              0x09u
#define USB_AC_EN_PARAM3_CONTROL              0x0Au
#define USB_AC_EN_PARAM4_CONTROL              0x0Bu
#define USB_AC_EN_PARAM5_CONTROL              0x0Cu
#define USB_AC_EN_PARAM6_CONTROL              0x0Du
#define USB_AC_EN_PARAM7_CONTROL              0x0Eu
#define USB_AC_EN_PARAM8_CONTROL              0x0Fu

#define USB_AC_MP_DUAL_CHANNEL_CONTROL        0x01u
#define USB_AC_MP_SECOND_STEREO_CONTROL       0x02u
#define USB_AC_MP_MULTILANGUAL_CONTROL        0x03u
#define USB_AC_MP_DYN_RANGE_CONTROL           0x04u
#define USB_AC_MP_SCALING_CONTROL             0x05u
#define USB_AC_MP_HILO_SCALING_CONTROL        0x06u
#define USB_AC_MP_UNDERFLOW_CONTROL           0x07u
#define USB_AC_MP_OVERFLOW_CONTROL            0x08u
#define USB_AC_MP_DECODER_ERROR_CONTROL       0x09u

#define USB_AC_AD_MODE_CONTROL                0x01u
#define USB_AC_AD_DYN_RANGE_CONTROL           0x02u
#define USB_AC_AD_SCALING_CONTROL             0x03u
#define USB_AC_AD_HILO_SCALING_CONTROL        0x04u
#define USB_AC_AD_UNDERFLOW_CONTROL           0x05u
#define USB_AC_AD_OVERFLOW_CONTROL            0x06u
#define USB_AC_AD_DECODER_ERROR_CONTROL       0x07u

#define USB_AC_WD_UNDERFLOW_CONTROL           0x01u
#define USB_AC_WD_OVERFLOW_CONTROL            0x02u
#define USB_AC_WD_DECODER_ERROR_CONTROL       0x03u

#define USB_AC_DD_UNDERFLOW_CONTROL           0x01u
#define USB_AC_DD_OVERFLOW_CONTROL            0x02u
#define USB_AC_DD_DECODER_ERROR_CONTROL       0x03u

#define USB_AC_EP_PITCH_CONTROL               0x01u
#define USB_AC_EP_DATA_OVERRUN_CONTROL        0x02u
#define USB_AC_EP_DATA_UNDERRUN_CONTROL       0x03u
//
// Audio 1.0 only Control Selectors
//
#define USB_AC_SAMPLING_FREQ_CONTROL          0x01u
#define USB_AC_PITCH_CONTROL                  0x02u

//
// Supported data format from the emUSBD Audio Device Generator tool
//
#define USBD_AC_GENERATOR_FORMAT               1

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
/*********************************************************************
*
*       USBD_AC_CONTROL_INFO
*
*   Description
*     This structure contains information about the type of a control request.
*/
typedef struct {
  U32   ID;               // Request ID:
                          // Bits 20..16 contain the interface index (0 = control interface, 1,... = streaming interfaces)
                          // Bits 15..8 contain the unit / terminal / entity ID. Is set to 0xFF if recipient is the endpoint.
                          // Bits 7..0 contain the control selector.
  U8    bRequest;         // Audio Class-Specific Request Code, see USB_AC_REQ... defines.
  U8    ChannelNumber;
} USBD_AC_CONTROL_INFO;

/*********************************************************************
*
*       USBD_AC_CONTROL_GET_FUNC
*
*  Description
*    Definition of the callback which is called when an audio control get requests is received.
*    This callback is called in interrupt context and must not block.
*
*  Parameters
*    pReqInfo     : Contains information about the type of the control request.
*    pBuffer      : Pointer to a buffer into which the callback should write the reply (max. 64 bytes).
*
*  Return value
*    >= 0:          Audio control request was handled by the callback and response data was put into pBuffer.
*                   The callback function must return the length of the response data which will be send to the host.
*    < 0 :          Audio control request was not handled by the callback (i.e. illegal request or parameters).
*                   The stack will STALL the request.
*/
typedef int USBD_AC_CONTROL_GET_FUNC(const USBD_AC_CONTROL_INFO *pReqInfo, U8 * pBuffer);

/*********************************************************************
*
*       USBD_AC_CONTROL_SET_FUNC
*
*  Description
*    Definition of the callback which is called when an audio control set requests is received.
*    This callback is called in interrupt context and must not block.
*
*  Parameters
*    pReqInfo     : Contains information about the type of the control request.
*    NumBytes     : Number of bytes in pBuffer.
*    pBuffer      : Pointer to a buffer containing the request data.
*
*  Return value
*    == 0:          Audio control request was handled by the callback.
*    != 0:          Audio control request was not handled by the callback (i.e. illegal request or parameters).
*                   The stack will STALL the request.
*/
typedef int USBD_AC_CONTROL_SET_FUNC(const USBD_AC_CONTROL_INFO *pReqInfo, U32 NumBytes, const U8 * pBuffer);

/*********************************************************************
*
*       USBD_AC_SET_ALT_INTERFACE
*
*  Description
*    Definition of the callback which is called when the hosts sets an alternate setting on an audio interface.
*    This callback is called in interrupt context and must not block.
*
*  Parameters
*    InterfaceNo  : Number of the audio streaming interface. Corresponds to the USBD_AC_INTERFACE_... defines.
*    NewAltSetting: Alternate setting selected by the host.
*/
typedef void USBD_AC_SET_ALT_INTERFACE(unsigned InterfaceNo, unsigned NewAltSetting);

/*********************************************************************
*
*       USBD_AC_GET_ALT_INTERFACE
*
*  Description
*    Definition of the callback which is called when the hosts asks for the current alternate setting on an audio interface.
*    This callback is called in interrupt context and must not block.
*
*  Parameters
*    InterfaceNo  : Number of the audio streaming interface. Corresponds to the USBD_AC_INTERFACE_... defines.
*/
typedef void USBD_AC_GET_ALT_INTERFACE(unsigned InterfaceNo);

/*********************************************************************
*
*       USBD_AC_STREAM_INTF_INFO
*
*   Description
*     This structure contains information about an audio streaming interface.
*/
typedef struct {
  U16   MaxPacketSize;            // Maximum packet size of the endpoint.
  U8    IntervalExp;              // Specifies the interval of the endpoint in micro frames (125us):
                                  // Interval = 2^IntervalExp
  U8    NrChannels;               // Number of audio channels. If not specified in the audio description file, contains 0.
  U8    SubframeSize;             // Number of byte for a single audio sample (one channel).
                                  // If not specified in the audio description file, contains 0.
  U8    BitResolution;            // Number of relevant bits in a single audio sample.
                                  // If not specified in the audio description file, contains 0.
} USBD_AC_STREAM_INTF_INFO;

/*********************************************************************
*
*       USB_AC_INTF_INFO
*
*   Description
*     This structure contains information about an audio streaming interface.
*/
typedef struct {
        U8    StringIndex;        // Index of string descriptor.
        I8    EPIndex_Data;       // Index of the data EP (into the audio endpoint table) or -1, if no EP.
        I8    EPIndex_Feedback;   // Index of the feedback EP (into the audio endpoint table) or -1, if no feedback EP.
        U8    EPDescSize;         // Size of Audio Data Endpoint Descriptor in bytes.
  const U8  * pEPDesc;            // Pointer to the Audio Data Endpoint Descriptor.
  const U8  * pASDesc;            // Pointer to the Audio Class-Specific AS Interface Descriptor
        U16   ASDescSize;         // Size of Audio Class-Specific AS Interface Descriptor in bytes.
  USBD_AC_STREAM_INTF_INFO Info;
} USBD_AC_INTF_INFO;

/*********************************************************************
*
*       USB_AC_INTF_LIST
*
*   Description
*     Contains a list of USB_AC_INTF_INFO's for all alternate settings.
*/
typedef struct {
  U8 NumAlternateSettings;            // Number of entries in pIntfInfoList. First is AltSetting == 0.
  I8 isTX;                            // 0: Receive interface, 1: Send Interface
  const USBD_AC_INTF_INFO *pIntfInfo;
} USBD_AC_INTF_LIST;

/*********************************************************************
*
*       USB_AC_EP_INFO
*
*  Description
*    Structure contains information for each audio endpoint.
*/
typedef struct {
  U8               InterfaceNo;   // Number of the interface the EP belongs to.
  U8               Res2;
  USB_ADD_EP_INFO  EPInfo;
} USBD_AC_EP_INFO;

/*********************************************************************
*
*       USBD_AC_CONFIG
*
*   Description
*     Configuration data for the Audio class instance.
*/
typedef struct {
  I8                        GeneratorFormat;  // Major version of the generator tool.
  U8                        ProtocolVersion;  // USB audio protocol version (0x00 or 0x20).
  U8                        NumInterfaces;    // Number of streaming interfaces (entries in pIntfList).
  U8                        NumEndpoints;     // Number of entries in pEPList.
  U8                        FirstStringIdx;   // Index of first string in pStringTab.
  U8                        NumStrings;       // Number of strings in pStringTab.
  U8                        StringIndex;      // Index of string descriptor for control interface.
  U16                       ControlDescSize;  // Size of Control interface descriptor in bytes.
  const U8                * pControlDesc;     // Control interface descriptor.
  const USBD_AC_INTF_LIST * pIntfList;        // List of USB_AC_INTF_INFO's.
  const USBD_AC_EP_INFO   * pEPList;          // List of all endpoints.
  const char * const      * pStringTab;       // List of strings.
} USBD_AC_CONFIG;

/*********************************************************************
*
*       USBD_AC_INIT_DATA
*
*   Description
*     Initialization data for the Audio class instance.
*/
typedef struct {
  const USBD_AC_CONFIG      * pACConfig;           // Pointer to configuration data created by the generator.
  USBD_AC_CONTROL_GET_FUNC  * pfControlGet;        // Callback function to handle audio control get requests.
  USBD_AC_CONTROL_SET_FUNC  * pfControlSet;        // Callback function to handle audio control set requests.
  USBD_AC_SET_ALT_INTERFACE * pfSetAlternate;      // Callback to inform the application about Set Interface control requests.
#if USB_SUPPORT_GET_INTERFACE_CB
  USBD_AC_GET_ALT_INTERFACE * pfGetInterfaceInfo;  // Callback to inform the application about Get Interface control requests.
#endif
  U8                          IntEP;               // Optional interrupt EP. If used, it must be allocated by calling
                                                   // USBD_AddEP(1, USB_TRANSFER_TYPE_INT, Interval, NULL, PacketSize),
                                                   // where PacketSize must be 2 for audio 1.0 devices and 6 for audio 2.0 devices.
} USBD_AC_INIT_DATA;

/*********************************************************************
*
*       USBD_AC_EVENT
*
*  Description
*    Event types for RX / TX callback functions.
*/
typedef enum {
  USBD_AC_EVENT_DATA_RECEIVED,       // Data was read from the host.
  USBD_AC_EVENT_DATA_SEND,           // Data was send to the host.
  USBD_AC_EVENT_TIMOUT,              // Timeout on read or write.
  USBD_AC_EVENT_CLOSED               // Interface was closed by the host.
} USBD_AC_EVENT;

/*********************************************************************
*
*       USBD_AC_TX_CALLBACK
*
*  Description
*    Definition of the callback which is called when audio data was send to the host.
*    The function should initiate to send more data.
*
*  Parameters
*    Event:    Event occurred on the audio stream.
*    pData:    Pointer to the data send, that was provided to the USBD_AC_Send() function.
*    pContext: Pointer from the USBD_AC_RX_CTX structure.
*/
typedef void USBD_AC_TX_CALLBACK(USBD_AC_EVENT Event, const void *pData, void *pUserContext);

/*********************************************************************
*
*       USBD_AC_RX_DATA
*
*   Description
*     This structure is used to forward audio data to the application.
*/
typedef struct {
  void                * pBuffer;        // Pointer to the buffer which is used to receive audio data.
                                        // The buffer must be provided by the application and must have a size of at least
                                        // the maximum packet size of the currently selected audio stream endpoint,
                                        // rounded up to a multiple of 4 or a multiple of the cache line size of the system.
                                        // To achieve best performance the buffer should be word aligned or
                                        // cache aligned if the system is using a data cache.
                                        // Must be initialized before calling USBD_AC_OpenRXStream() (within USBD_AC_RX_CTX)
                                        // and in the pfCallback function before it returns.
  U32                   NumBytes;       // Must be initialized by the application to the size of the buffer 'pBuffer'.
                                        // When the function pfCallback is called, it contains the number of bytes actually received.
  U16                   NumPackets;     // Must be initialized by the application to the maximum number of audio packets that are read into
                                        // the buffer before the application is notified via the callback function.
                                        // When the function pfCallback is called, it contains the number of packets actually received.
  U16                   Timeout;        // Timeout in units of SOFs (1ms for full-speed / 125us in high-speed).
                                        // If no packets were received within the specified time, the application is notified
                                        // with a USBD_AC_EVENT_TIMOUT event. A value of 0 means no timeout.
  void                * pUserContext;   // Can be arbitrarily used by the application.
} USBD_AC_RX_DATA;

/*********************************************************************
*
*       USBD_AC_RX_CALLBACK
*
*  Description
*    Definition of the callback which is called when audio data was received from the host.
*    pRxData->Numbytes bytes of data were received into pRxData->pBuffer.
*    The function must reinitialize the members pBuffer, NumBytes and MaxPackets before it returns.
*    This callback is called in interrupt context and must not block. The audio data must not be processed
*    inside this function, instead a task should be triggered that does the audio processing and this function
*    should return as fast as possible. After this function has returned, the next USB transfer is started
*    immediately. Therefore the member 'pBuffer' should be initialized to point to a different buffer to avoid
*    overwriting the data just received (double buffering mechanism is recommended).
*
*  Parameters
*    Event:    Event occurred on the audio stream.
*    pRxData:  Pointer to a USBD_AC_RX_DATA structure. The contents is valid only, if Event == USBD_AC_EVENT_DATA_RECEIVED.
*/
typedef void USBD_AC_RX_CALLBACK(USBD_AC_EVENT Event, USBD_AC_RX_DATA * pRxData);

/*********************************************************************
*
*       USBD_AC_RX_CTX
*
*   Description
*     Contains all information about an active interface receiving audio data.
*     The public part of this structure must be initialized by the application before passed to the
*     function USBD_AC_OpenRXStream(). The data must remain valid and must not
*     be modified by the application while the stream is open and used.
*/
typedef struct {
  U16    Interface;                  // Index of the audio interface, see generated USBD_AC_INTERFACE_... defines.
  U16    Flags;                      // Reserved for future extensions, must be set to 0.
  void (*pfSOFCallback)(void *pCtx); // Function that is called every 'Interval' SOFs received from the host (optional).
                                     // May be used to to calculate the data rate for explicit feedback.
                                     // The function takes a pointer to the USBD_AC_RX_CTX structure as parameter
                                     // (need to be cast to USBD_AC_RX_CTX * inside the function, if used).
  U16 FeedbackInterval;              // Interval (Number of SOFs) used for calling pfSOFCallback.
                                     // Measured in units of 1ms for full-speed / 125us in high-speed.
  USBD_AC_RX_CALLBACK * pfCallback;  // Function that is called when data was received from the host
                                     // or a 'close' event or timeout has occurred on the stream.
  USBD_AC_RX_DATA RxData;            // Data transfer information.
  struct {
    //
    // This members are private to the USB audio class implementation.
    // They do not need to be initialized and must never be modified by the application.
    //
    U8  DataEPIndex;       // Index of the data endpoint
    U8  FeedbackEPIndex;   // Index of the feedback endpoint (or 0, if none).
    U8  Speed;             // Actual USB speed: 0 = full-speed, 1 = high-speed.
    U8  CurrentAltSetting;
    I8  isOpen;
    U16 MaxPacketSize;
    U16 MaxPackets;        // Max. number of packets to read.
    U8  *pBuffer;
    U32 NumBytesToRead;
    union {
      U32  Dummy;          // For alignment
      U8   DataRate[5];    // Data rate value to be send to the host.
    } Feedback;
    USB_SOF_CALLBACK_HOOK  TimeoutSOFHook;     // To monitor timeouts.
    USB_SOF_CALLBACK_HOOK  FeedbackSOFHook;    // To register the pfSOFCallback function.
    USB_EVENT_CALLBACK     DataEPHook;         // To catch data EP events.
    USB_EVENT_CALLBACK     FeedbackEPHook;     // To catch feedback EP events.
  } Private;
} USBD_AC_RX_CTX;

/*********************************************************************
*
*       USBD_AC_WRITE_QUEUE
*
*   Description
*     Internal use.
*/
typedef struct {
  U16               NumPackets;      // Total number of packets for this entry
  U16               NumLargePackets; // Number of Packets with one more sample
  U16               PacketSize;      // Size of 'small' packets
  U32               Factor;          // Distribution of small and large packets
  const U8        * pData;
  const void      * pBuffer;         // Pointer saved for user callback
} USBD_AC_WRITE_QUEUE;

/*********************************************************************
*
*       USBD_AC_TX_CTX
*
*   Description
*     Contains all information about an active interface for sending audio data.
*     The public part of this structure must be initialized by the application before passed to the
*     function USBD_AC_OpenTXStream(). The data must remain valid and must not
*     be modified by the application while the stream is open and used.
*/
typedef struct {
  U16                   Interface;      // Index of the audio interface, see generated USBD_AC_INTERFACE_... defines.
  U16                   Flags;          // Reserved for future extensions, must be set to 0.
  U16                   SampleSize;     // Number of bytes for a single audio sample (all channels).
                                        // The value is not required (and is ignored) if only single audio packets is
                                        // send via USBD_AD_Send().
  U16                   Timeout;        // Timeout in units of SOFs (1ms for full-speed / 125us in high-speed).
                                        // If no packets were send within the specified time, the application is notified
                                        // with a USBD_AC_EVENT_TIMOUT event. A value of 0 means no timeout.
  USBD_AC_TX_CALLBACK * pfCallback;     // Function that is called when data was send to the host
                                        // or a 'close' event or timeout has occurred on the stream.
  void                * pUserContext;   // Can be arbitrarily used by the application.
  struct {
    //
    // This members are private to the USB audio class implementation.
    // They do not need to be initialized and must never be modified by the application.
    //
    U8  DataEPIndex;                // Index of the data endpoint
    U8  FeedbackEPIndex;            // Index of the feedback endpoint (or 0, if none).
    U8  Speed;                      // Actual USB speed: 0 = full-speed, 1 = high-speed.
    U8  CurrentAltSetting;
    U16 MaxPacketSize;
    I8  isOpen;
    U8  NumEntries;                 // Number of active entries in Queue.
    USBD_AC_WRITE_QUEUE Queue[2];
    union {
      U32  Dummy;                   // For alignment
      U8   DataRateU[5];            // Data rate value to be send to host.
                                    // Only bytes [1..4] are used, first byte to force unalignment.
    } Feedback;
    USB_SOF_CALLBACK_HOOK  TimeoutSOFHook;     // To monitor timeouts.
    USB_EVENT_CALLBACK     DataEPHook;         // To catch data EP events.
    USB_EVENT_CALLBACK     FeedbackEPHook;     // To catch feedback EP events.
  } Private;
} USBD_AC_TX_CTX;

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
int      USBD_AC_Add                    (const USBD_AC_INIT_DATA * pInitData);
unsigned USBD_AC_GetCurrentAltSetting   (unsigned Interface);
int      USBD_AC_SendInterruptMessage   (unsigned Interface, U32 ID, U8 ChannelNumber, int ms);
int      USBD_AC_OpenRXStream           (USBD_AC_RX_CTX *pCtx);
void     USBD_AC_CloseRXStream          (USBD_AC_RX_CTX *pCtx);
void     USBD_AC_SetFeedbackDataRate    (USBD_AC_RX_CTX *pCtx, U32 DataRate);
int      USBD_AC_OpenTXStream           (USBD_AC_TX_CTX *pCtx);
void     USBD_AC_CloseTXStream          (USBD_AC_TX_CTX *pCtx);
U32      USBD_AC_GetFeedbackDataRate    (USBD_AC_TX_CTX *pCtx);
int      USBD_AC_Send                   (USBD_AC_TX_CTX *pCtx, U16 NumFrames, U32 NumBytes, const void *pData);

const USBD_AC_STREAM_INTF_INFO * USBD_AC_GetStreamInfo(unsigned Interface, int AltSetting);


#if defined(__cplusplus)
  }
#endif

#endif  /* USBD_AC_H */

/*************************** End of file ****************************/

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
Purpose : Public header of audio device class
-------------------------- END-OF-HEADER -----------------------------
*/

#ifndef USBD_AUDIO_H          /* Avoid multiple inclusion */
#define USBD_AUDIO_H

#include "SEGGER.h"
#include "USB.h"

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Config defaults
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
// emUSB-Device-Audio command codes
//
#define USB_AUDIO_PLAYBACK_START              0xA1
#define USB_AUDIO_PLAYBACK_STOP               0xA2
#define USB_AUDIO_RECORD_START                0xA3
#define USB_AUDIO_RECORD_STOP                 0xA4

//
// Processing Unit Process Types
//
#define USB_AUDIO_PROCESS_UNDEFINED           0x00
#define USB_AUDIO_UP_DOWNMIX_PROCESS          0x01
#define USB_AUDIO_DOLBY_PROLOGIC_PROCESS      0x02
#define USB_AUDIO_3D_STEREO_EXTENDER_PROCESS  0x03
#define USB_AUDIO_REVERBERATION_PROCESS       0x04
#define USB_AUDIO_CHORUS_PROCESS              0x05
#define USB_AUDIO_DYN_RANGE_COMP_PROCESS      0x06

//
// Audio Class-Specific Request Codes
//
#define USB_AUDIO_REQUEST_CODE_UNDEFINED      0x00
#define USB_AUDIO_SET_CUR                     0x01
#define USB_AUDIO_GET_CUR                     0x81
#define USB_AUDIO_SET_MIN                     0x02
#define USB_AUDIO_GET_MIN                     0x82
#define USB_AUDIO_SET_MAX                     0x03
#define USB_AUDIO_GET_MAX                     0x83
#define USB_AUDIO_SET_RES                     0x04
#define USB_AUDIO_GET_RES                     0x84
#define USB_AUDIO_SET_MEM                     0x05
#define USB_AUDIO_GET_MEM                     0x85
#define USB_AUDIO_GET_STAT                    0xFF

//
// Terminal Control Selectors
//
#define USB_AUDIO_TE_CONTROL_UNDEFINED        0x00
#define USB_AUDIO_COPY_PROTECT_CONTROL        0x01

//
// Feature Unit Control Selectors
//
#define USB_AUDIO_FU_CONTROL_UNDEFINED        0x00
#define USB_AUDIO_MUTE_CONTROL                0x01
#define USB_AUDIO_VOLUME_CONTROL              0x02
#define USB_AUDIO_BASS_CONTROL                0x03
#define USB_AUDIO_MID_CONTROL                 0x04
#define USB_AUDIO_TREBLE_CONTROL              0x05
#define USB_AUDIO_GRAPHIC_EQUALIZER_CONTROL   0x06
#define USB_AUDIO_AUTOMATIC_GAIN_CONTROL      0x07
#define USB_AUDIO_DELAY_CONTROL               0x08
#define USB_AUDIO_BASS_BOOST_CONTROL          0x09
#define USB_AUDIO_LOUDNESS_CONTROL            0x0A

//
// Terminal Types
//
#define USB_AUDIO_TERMTYPE_USB_STREAMING                        0x0101u // A Terminal dealing with a signal carried over an endpoint in an AudioStreaming interface.

#define USB_AUDIO_TERMTYPE_INPUT_UNDEFINED                      0x0200u // Input Terminal, undefined Type.
#define USB_AUDIO_TERMTYPE_INPUT_MICROPHONE                     0x0201u // A generic microphone that does not fit under any of the other classifications.
#define USB_AUDIO_TERMTYPE_INPUT_DESKTOP_MICROPHONE             0x0202u // A microphone normally placed on the desktop or integrated into the monitor.
#define USB_AUDIO_TERMTYPE_INPUT_PERSONAL_MICROPHONE            0x0203u // A head-mounted or clip-on microphone.
#define USB_AUDIO_TERMTYPE_INPUT_OMNI_DIRECTIONAL_MICROPHONE    0x0204u // A microphone designed to pick up voice from more than one speaker at relatively long ranges.
#define USB_AUDIO_TERMTYPE_INPUT_MICROPHONE_ARRAY               0x0205u // An array of microphones designed for directional processing using host-based signal processing algorithms.
#define USB_AUDIO_TERMTYPE_INPUT_PROCESSING_MICROPHONE_ARRAY    0x0206u // An array of microphones with an embedded signal processor.

#define USB_AUDIO_TERMTYPE_OUTPUT_UNDEFINED                     0x0300u // Output Terminal, undefined Type.
#define USB_AUDIO_TERMTYPE_OUTPUT_SPEAKER                       0x0301u // A generic speaker or set of speakers that does not fit under any of the other classifications.
#define USB_AUDIO_TERMTYPE_OUTPUT_HEADPHONES                    0x0302u // A head-mounted audio output device.
#define USB_AUDIO_TERMTYPE_OUTPUT_HEAD_MOUNTED_DISPLAY_AUDIO    0x0303u // The audio part of a VR head mounted display. The Associated Interfaces descriptor can be used to reference the HID interface used to report the position and orientation of the HMD.
#define USB_AUDIO_TERMTYPE_OUTPUT_DESKTOP_SPEAKER               0x0304u // Relatively small speaker or set of speakers normally placed on the desktop or integrated into the monitor. These speakers are close to the user and have limited stereo separation.
#define USB_AUDIO_TERMTYPE_OUTPUT_ROOM_SPEAKER                  0x0305u // Larger speaker or set of speakers that are heard well anywhere in the room.
#define USB_AUDIO_TERMTYPE_OUTPUT_COMMUNICATION_SPEAKER         0x0306u // Speaker or set of speakers designed for voice communication.
#define USB_AUDIO_TERMTYPE_OUTPUT_LOW_FREQUENCY_EFFECTS_SPEAKER 0x0307u // Speaker designed for low frequencies (subwoofer). Not capable of reproducing speech or music.

//
// Endpoint Control Selectors
// The EP_CS offset is used to differenciate
// Feature Unit events from Endpoint events.
//
#define USB_AUDIO_EP_CS_OFFSET                0x0Fu
#define USB_AUDIO_SAMPLING_FREQ_CONTROL       (0x01u + USB_AUDIO_EP_CS_OFFSET)
#define USB_AUDIO_PITCH_CONTROL               (0x02u + USB_AUDIO_EP_CS_OFFSET)

//
// Descriptor sizes
//
#define USB_AUDIO_AC_HEADER_SIZE(a)           (8u + (a))
#define USB_AUDIO_AC_IN_TER_SIZE              0x0Cu
#define USB_AUDIO_AC_FE_UNIT_SIZE(a)          (0x08u + (a))
#define USB_AUDIO_AC_OUT_TER_SIZE             0x09u
#define USB_AUDIO_AS_GEN_IF_SIZE              0x07u
#define USB_AUDIO_AS_FORMAT_SIZE(a)           (8u + (a) * 3u)

/*********************************************************************
*
*       Types
*
**********************************************************************
*/
typedef int USBD_AUDIO_HANDLE;

/*********************************************************************
*
*       USBD_AUDIO_RX_FUNC
*
*  Description
*    Definition of the callback which is called when audio data is received.
*    This callback is called in the context of USBD_AUDIO_Read_Task().
*    The default timeout is 50 milliseconds.
*
*  Parameters
*    pUserContext     : User context which is passed to the callback.
*    NumBytesReceived : The number of bytes which have been read in this transaction.
*    ppNextBuffer     : Buffer containing audio samples which should match the configuration from speaker USBD_AUDIO_IF_CONF.
*                       Initially this points to the pBufOut from the USBD_AUDIO_INIT_DATA structure.
*                       The user can change this pointer to a different buffer which will be used in the next transaction
*                       or leave it as it is and copy the data from this buffer elsewhere.
*    pNextBufferSize  : Size of the next buffer.
*/
typedef void USBD_AUDIO_RX_FUNC(void * pUserContext, int NumBytesReceived, U8 ** ppNextBuffer, U32 * pNextBufferSize);

/*********************************************************************
*
*       USBD_AUDIO_TX_FUNC
*
*  Description
*   Definition of the callback which is called when audio data is sent. This callback is called in the context of USBD_AUDIO_Write_Task()
*
*  Parameters
*    pUserContext     : User context which is passed to the callback.
*    ppNextBuffer     : Buffer containing audio samples which should match the configuration from microphone USBD_AUDIO_IF_CONF.
*                       Initially this points to the pBufIn from the call to USBD_AUDIO_Start_Play function.
*                       The user can change this pointer to a different buffer which will be used
*                       in the next transaction or fill the same buffer with new data.
*    pNextBufferSize  : Size of the next buffer.
*/
typedef void USBD_AUDIO_TX_FUNC(void * pUserContext, const U8 ** ppNextBuffer, U32 * pNextPacketSize);

/*********************************************************************
*
*       USBD_AUDIO_CONTROL_FUNC
*
*  Description
*    Definition of the callback which is called when audio commands are received. This callback is called in an interrupt context.
*
*  Parameters
*    pUserContext     : User context which is passed to the callback.
*    Event            : Audio event ID.
*    Unit             : ID of the feature unit.
*                       In case of USB_AUDIO_PLAYBACK_* and USB_AUDIO_RECORD_*: 0.
*    ControlSelector  : ID of the control.
*                       In case of USB_AUDIO_PLAYBACK_* and USB_AUDIO_RECORD_*: 0.
*    pBuffer          : In case of GET events: pointer to a buffer into which the callback should write the reply.
*                       In case of SET events: pointer to a buffer containing the command value.
*                       In case of USB_AUDIO_PLAYBACK_* and USB_AUDIO_RECORD_*: NULL.
*    NumBytes         : In case of GET events: requested size of the reply in bytes.
*                       In case of SET events: number of bytes in pBuffer.
*                       In case of USB_AUDIO_PLAYBACK_* and USB_AUDIO_RECORD_*: 0.
*    InterfaceNo      : The number of the USB interface for which the event was issued.
*    AltSetting       : The alternative setting number of the USB interface for which the event was issued.
*  Return value
*    == 0:              Audio command was handled by the callback. The stack will send the reply.
*    != 0:              Audio command was not handled by the callback. The stack will STALL the request.
*
*  Additional information
*    USB_AUDIO_PLAYBACK_* & USB_AUDIO_RECORD_* events are sent upon receiving a Set Interface USB request
*    for Alternate Setting 1 for the respective interface (microphone or speaker).
*    By default an Audio interface is set to Alternative Setting 0 in which it can not send or receive anything.
*    The host switches the Alternative Setting to 1 when it has to send data to the device,
*    this can be e.g. triggered by pressing "play" in your music player.
*    Normally the host should switch the device back to Alternative Interface 0 when it has stopped sending audio data.
*    This works well on Linux and OS X, but does not work reliably on Windows.
*    When using Windows as a host it seems to depend on the application whether these events are generated or not.
*    E.g. with some applications you will receive USB_AUDIO_PLAYBACK_START when "play" is pressed,
*    but USB_AUDIO_PLAYBACK_STOP will not be sent when "pause" or "stop" is pressed. Relying on these events
*    to check when the host has stopped sending data is not advised, instead set timeouts
*    via USBD_AUDIO_Set_Timeouts and check for timeouts inside your USBD_AUDIO_RX_FUNC and USBD_AUDIO_TX_FUNC .
*/
typedef int USBD_AUDIO_CONTROL_FUNC(void * pUserContext, U8 Event, U8 Unit, U8 ControlSelector, U8 * pBuffer, U32 NumBytes, U8 InterfaceNo, U8 AltSetting);

/*********************************************************************
*
*       USBD_AUDIO_UNITS
*
*   Description
*     This structure contains IDs used for a particular audio interface.
*     The application should leave those values at zero,
*     they are set by the stack after USBD_AUDIO_Add() has been called.
*/
typedef struct _USBD_AUDIO_UNITS {
  U8 Flags;           // Reserved. Set to zero.
  U8 InterfaceNo;     // USB Interface number of the audio interface. Set by the emUSB-Device stack.
  U8 AltInterfaceNo;  // Alternate setting number of the USB interface. Set by the emUSB-Device stack.
  U8 InputTerminalID; // ID of the input terminal. Set by the emUSB-Device stack.
  U8 OutputTerminalID;// ID of the output terminal. Set by the emUSB-Device stack.
  U8 FeatureUnitID;   // ID of the feature unit. Set by the emUSB-Device stack.
} USBD_AUDIO_UNITS;

/*********************************************************************
*
*       USBD_AUDIO_FORMAT
*
*   Description
*     Initialization data for a single audio format.
*/
typedef struct _USBD_AUDIO_FORMAT {
  U8  Flags;          // Reserved. Set to zero.
  U8  NrChannels;     // Number of channels in this format. Muster never be greater than USBD_AUDIO_IF_CONF->TotalNrChannels
                      // While it is possible to configure less then the total number of channels
                      // for a format most host operating systems do not support such configurations.
  U8  SubFrameSize;   // Size of an audio frame in bytes. Must be able to hold BitResolution bits.
  U8  BitResolution;  // Number of bits inside the audio frame dedicated to audio data. (Any remaining bits are padding.)
  U32 SamFreq;        // Supported sample frequency in Hz.
} USBD_AUDIO_FORMAT;

/*********************************************************************
*
*       USBD_AUDIO_IF_CONF
*
*   Description
*     Initialization structure for an audio microphone/speaker interface.
*     Only one speaker and one microphone is supported.
*/
typedef struct _USBD_AUDIO_IF_CONF {
  U8 Flags;                           // Reserved. Set to zero.
  U8 Controls;                        // Bitmask, a bit set to 1 indicates that the mentioned Control is supported:
                                      // * b0: Mute
                                      // * b1: Volume
                                      // * b2: Bass
                                      // * b3: Mid
                                      // * b4: Treble
                                      // * b5: Graphic Equalizer
                                      // * b6: Automatic Gain
                                      // * b7: Delay
  U8 TotalNrChannels;                 // Number of audio channels for this interface.
  U8 NumFormats;                      // Number of elements inside the paFormats array.
  const USBD_AUDIO_FORMAT * paFormats;// Pointer to any array of USBD_AUDIO_FORMAT structures.
  U16 bmChannelConfig;                // Bit map indicating the spatial locations of channels.
                                      // Important: this value should not be left at 0 to avoid an issue with Windows.
                                      // The bits correspond to the following locations:
                                      // * b0: Left Front (L)
                                      // * b1: Right Front (R)
                                      // * b2: Center Front (C)
                                      // * b3: Low Frequency Enhancement (LFE)
                                      // * b4: Left Surround (LS)
                                      // * b5: Right Surround (RS)
                                      // * b6: Left of Center (LC)
                                      // * b7: Right of Center (RC)
                                      // * b8: Surround (S)
                                      // * b9: Side Left (SL)
                                      // * b10: Side Right (SR)
                                      // * b11: Top (T)
                                      // * b15..12: Reserved
                                      // Channels are assigned to locations in ascending oder.
                                      // E.g. if b6 and b11 are set and the other bits are zero
                                      // channel 0 will be "LC" and channel 1 will be "T".
                                      // Having more channels than bits set in this bit map is valid,
                                      // the channels which do not have a bit set will
                                      // be considered to have a non-predefined spatial position.
  U16 TerminalType;                   // Defines the type of speaker/microphone for this interface.
                                      // Only one speaker and one microphone is supported!
                                      // The following defines can be used:
                                      // * USB_AUDIO_TERMTYPE_INPUT_UNDEFINED
                                      // * USB_AUDIO_TERMTYPE_INPUT_MICROPHONE
                                      // * USB_AUDIO_TERMTYPE_INPUT_DESKTOP_MICROPHONE
                                      // * USB_AUDIO_TERMTYPE_INPUT_PERSONAL_MICROPHONE
                                      // * USB_AUDIO_TERMTYPE_INPUT_OMNI_DIRECTIONAL_MICROPHONE
                                      // * USB_AUDIO_TERMTYPE_INPUT_MICROPHONE_ARRAY
                                      // * USB_AUDIO_TERMTYPE_INPUT_PROCESSING_MICROPHONE_ARRAY
                                      //
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_UNDEFINED
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_SPEAKER
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_HEADPHONES
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_HEAD_MOUNTED_DISPLAY_AUDIO
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_DESKTOP_SPEAKER
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_ROOM_SPEAKER
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_COMMUNICATION_SPEAKER
                                      // * USB_AUDIO_TERMTYPE_OUTPUT_LOW_FREQUENCY_EFFECTS_SPEAKER
  USBD_AUDIO_UNITS * pUnits;          // Pointer to a structure of type USBD_AUDIO_UNITS.
                                      // This structure is filled by the emUSB-Device Audio class during initialization.
} USBD_AUDIO_IF_CONF;

/*********************************************************************
*
*       USBD_AUDIO_INIT_DATA
*
*   Description
*     Initialization data for the Audio class instance.
*/
typedef struct {                                  // NOLINT(clang-analyzer-optin.performance.Padding)
  U8                         EPIn;                // Isochronous IN endpoint for sending data to the host. If microphone functionality is not desired set this to 0.
  U8                         EPOut;               // Isochronous OUT endpoint for receiving data from the host. If speaker functionality is not desired set this to 0.
  unsigned                   OutPacketSize;       // Size of a single audio OUT packet. Must be calculated as follows: (highest used) SampleRate * NumChannels * BitsPerSample / 8 / 1000
  USBD_AUDIO_RX_FUNC       * pfOnOut;             // Pointer to a function of type USBD_AUDIO_RX_FUNC which handles incoming audio data. Needs to be set when the speaker interface is used.
  USBD_AUDIO_TX_FUNC       * pfOnIn;              // Pointer to a function of type USBD_AUDIO_TX_FUNC which handles outgoing audio data. Needs to be set when the microphone interface is used.
  USBD_AUDIO_CONTROL_FUNC  * pfOnControl;         // Pointer to a function of type USBD_AUDIO_CONTROL_FUNC which handles audio commands. Always needs to be set.
  void                     * pControlUserContext; // Pointer to a user context which is passed to the pfOnControl function. Optional, can be NULL.
  U8                         NumInterfaces;       // Number of elements in the paInterfaces array.
  const USBD_AUDIO_IF_CONF * paInterfaces;        // Pointer to an array of structures of type USBD_AUDIO_IF_CONF which contain configuration data for the audio interfaces.
  void                     * pOutUserContext;     // Pointer to a user context which is passed to the pfOnOut function. Optional, can be NULL.
  void                     * pInUserContext;      // Pointer to a user context which is passed to the pfOnIn function. Optional, can be NULL.
} USBD_AUDIO_INIT_DATA;

/*********************************************************************
*
*       API functions
*
**********************************************************************
*/
USBD_AUDIO_HANDLE USBD_AUDIO_Add          (const USBD_AUDIO_INIT_DATA * pInitData);
void              USBD_AUDIO_Read_Task    (void);
void              USBD_AUDIO_Write_Task   (void);
int               USBD_AUDIO_Start_Play   (USBD_AUDIO_HANDLE hInst, const U8 * pBufIn);
void              USBD_AUDIO_Stop_Play    (USBD_AUDIO_HANDLE hInst);
int               USBD_AUDIO_Start_Listen (USBD_AUDIO_HANDLE hInst, U8 * pBufOut);
void              USBD_AUDIO_Stop_Listen  (USBD_AUDIO_HANDLE hInst);
void              USBD_AUDIO_Set_Timeouts (USBD_AUDIO_HANDLE hInst, unsigned ReadTimeout, unsigned WriteTimeout);
#if defined(__cplusplus)
  }              /* Make sure we have C-declarations in C++ programs */
#endif

#endif                 /* Avoid multiple inclusion */

/*************************** End of file ****************************/

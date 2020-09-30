# FMT IO Protocol Command

Command Definition. The package format is shown below:

|head      |cmd     |len     |content |alloc   |checksum|end    |
|----------|--------|--------|--------|--------|--------|-------|
|`uint8[2]`|`uint16`|`uint16`|`uint8*`|`uint8` |`uint16`|`uint8`|

## PROTO_CMD_SYNC
command for synchronization. server send this command to client
- `cmd`: 1 
- `content`: *NULL*

## PROTO_ACK_SYNC
ack for synchronize command. client send this ack to server after it receives `PROTO_CMD_SYNC` from server
- `cmd`: 2
- `content`: *NULL*

## PROTO_CMD_REBOOT
server send this command to request client to reboot
- `cmd`: 3
- `content`: *NULL*

## PROTO_DBG_TEXT
client send this package to server, which contains debug information, similar to printf() 
- `cmd`: 4
- `len`: data length in content, it should not larger than `(MAX_PACKAGE_SIZE-10)`, where 10 is size of `PackageStruct` except `content`. It is recommended len is not larger than 100.
- `content`: content include debug information

## PROTO_DATA_RC
RC data sent from client to server (maximal 16 channels). 
- `cmd`: 5
- `len`: 32
- `content`: uint16 chan_val[16]

## PROTO_CMD_MOTOR
motor command for main pwm output. Each channel has a value between 1000 and 2000.
- `cmd`: 6
- `len`: 2+channel_num*2
- `content`: chan_mask is used to indicate the channel id, followed by chan_val of which chan_mask bit is 1

|motor_mask |chan_val |
|-----------|---------|
|`uint16`|`uint16[(len-2)/2]`|

## PROTO_GET_MOTOR_VAL
get current motor output value. Each channel has a value between 1000 and 2000.
- `cmd`: 7
- `len`: 2
- `content`: uint16 motor_mask: motor_mask is used to indicate which channel value to read

## PROTO_ACK_MOTOR_VAL
the current motor output value. Each channel has a value between 1000 and 2000.
- `cmd`: 8
- `len`: 2+channel_num*2
- `content`: motor_mask is used to indicate the channel id, followed by chan_val of which motor_mask bit is 1

|motor_mask |chan_val |
|-----------|---------|
|`uint16`|`uint16[(len-2)/2]`|

## PROTO_CMD_PWM_SWITCH
Enable/Disable pwm output.
- `cmd`: 9
- `len`: 1
- `content`: uint8_t enable

## PROTO_CMD_PWM_FREQ
Set pwm output frequency in Hz
- `cmd`: 10
- `len`: 2
- `content`: uint16_t frequency

## PROTO_CMD_CONFIG
Set fmt io configuration
- `cmd`: 10
- `len`: 2
- `content`: uint16_t frequency

|baud_rate|pwm_freq|rc_proto|
|-----------|---------|---------|
|`uint32`|`uint16`|`uint16`|

rc_proto: `1`: sbus `2`:ppm

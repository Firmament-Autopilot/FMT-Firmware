#ifndef __XC7027__
#define __XC7027__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    XC7027_MODE_1080P_30FPS = 0,
    XC7027_MODE_720P_50FPS = 1,
    XC7027_MODE_720P_30FPS = 2,
} ENUM_XC7027_MODE;

void XC7027_Reset(void);
int XC7027_ENC_Config();
void XC7027_SENSOR_Config(ENUM_XC7027_MODE SensorFormat);
void XC7027_Sensor_Start(void);
void XC7027_SENSOR_LoopCallBack(void);

int xc7027_init(void);
void xc7027_start(void);

#ifdef __cplusplus
}
#endif

#endif

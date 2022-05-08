#ifndef PX4_ECL_INTERFACE_H
#define PX4_ECL_INTERFACE_H

#include "module/log/mlog.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"

fmt_model_info_t px4_ecl_model_info;

typedef struct {
  uint32_t timestamp;
  float phi;
  float theta;
  float psi;
  float quat[4];
  float p;
  float q;
  float r;
  float ax;
  float ay;
  float az;
  float vn;
  float ve;
  float vd;
  float reserved;
  double lon;
  double lat;
  double alt;
  float x_R;
  float y_R;
  float h_R;
  float h_AGL;
  uint32_t flag;
  uint32_t status;
} PX4_ECL_Out_Bus;

void px4_ecl_interface_init(void);
void px4_ecl_interface_step(uint32_t timestamp);

#endif
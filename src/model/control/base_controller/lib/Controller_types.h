/*
 * File: Controller_types.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.877
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Mar 22 09:47:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_types_h_
    #define RTW_HEADER_Controller_types_h_
    #include "rtwtypes.h"
    #ifndef DEFINED_TYPEDEF_FOR_FMS_Out_Bus_
        #define DEFINED_TYPEDEF_FOR_FMS_Out_Bus_

typedef struct {
    uint32_T timestamp;

    /* rate x command in body frame */
    real32_T p_cmd;

    /* rate y command in body frame */
    real32_T q_cmd;

    /* rate z command in body frame */
    real32_T r_cmd;

    /* roll command */
    real32_T phi_cmd;

    /* pitch command */
    real32_T theta_cmd;

    /* yaw rate command */
    real32_T psi_rate_cmd;

    /* velocity x command in control frame */
    real32_T u_cmd;

    /* velocity y command in control frame */
    real32_T v_cmd;

    /* velocity z command in control frame */
    real32_T w_cmd;

    /* throttle command */
    uint32_T throttle_cmd;

    /* actuator command, e.g, pwm command for motors */
    uint16_T actuator_cmd[16];

    /* enum of VehicleStatus */
    uint8_T status;

    /* enum of VehicleState */
    uint8_T state;
    uint8_T ctrl_mode;

    /* reset the controller */
    uint8_T reset;

    /* enum of PilotMode */
    uint8_T mode;

    /* enum of PilotMode */
    uint8_T reserved1;

    /* enum of PilotMode */
    uint8_T wp_consume;

    /* enum of PilotMode */
    uint8_T wp_current;
} FMS_Out_Bus;

    #endif

    #ifndef DEFINED_TYPEDEF_FOR_INS_Out_Bus_
        #define DEFINED_TYPEDEF_FOR_INS_Out_Bus_

typedef struct {
    uint32_T timestamp;
    real32_T phi;
    real32_T theta;
    real32_T psi;
    real32_T quat[4];
    real32_T p;
    real32_T q;
    real32_T r;
    real32_T ax;
    real32_T ay;
    real32_T az;
    real32_T vn;
    real32_T ve;
    real32_T vd;
    real32_T reserved;
    real_T lat;
    real_T lon;
    real_T alt;
    real_T lat_0;
    real_T lon_0;
    real_T alt_0;
    real32_T x_R;
    real32_T y_R;
    real32_T h_R;
    real32_T h_AGL;
    uint32_T flag;
    uint32_T status;
} INS_Out_Bus;

    #endif

    #ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
        #define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
    uint32_T timestamp;
    uint16_T actuator_cmd[16];
} Control_Out_Bus;

    #endif

    #ifndef DEFINED_TYPEDEF_FOR_struct_biZzOMrg0u3lxrb7POOubF_
        #define DEFINED_TYPEDEF_FOR_struct_biZzOMrg0u3lxrb7POOubF_

typedef struct {
    uint32_T period;
    int8_T model_info[23];
} struct_biZzOMrg0u3lxrb7POOubF;

    #endif

    #ifndef DEFINED_TYPEDEF_FOR_struct_Ae52N6uY2eO0jd5TMQiCYB_
        #define DEFINED_TYPEDEF_FOR_struct_Ae52N6uY2eO0jd5TMQiCYB_

typedef struct {
    real32_T VEL_XY_P;
    real32_T VEL_XY_I;
    real32_T VEL_XY_D;
    real32_T VEL_Z_P;
    real32_T VEL_Z_I;
    real32_T VEL_Z_D;
    real32_T VEL_XY_I_MIN;
    real32_T VEL_XY_I_MAX;
    real32_T VEL_XY_D_MIN;
    real32_T VEL_XY_D_MAX;
    real32_T VEL_Z_I_MIN;
    real32_T VEL_Z_I_MAX;
    real32_T VEL_Z_D_MIN;
    real32_T VEL_Z_D_MAX;
    real32_T ROLL_P;
    real32_T PITCH_P;
    real32_T ROLL_PITCH_CMD_LIM;
    real32_T ROLL_RATE_P;
    real32_T PITCH_RATE_P;
    real32_T YAW_RATE_P;
    real32_T ROLL_RATE_I;
    real32_T PITCH_RATE_I;
    real32_T YAW_RATE_I;
    real32_T ROLL_RATE_D;
    real32_T PITCH_RATE_D;
    real32_T YAW_RATE_D;
    real32_T RATE_I_MIN;
    real32_T RATE_I_MAX;
    real32_T RATE_D_MIN;
    real32_T RATE_D_MAX;
    real32_T P_Q_CMD_LIM;
    real32_T R_CMD_LIM;
} struct_Ae52N6uY2eO0jd5TMQiCYB;

    #endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif /* RTW_HEADER_Controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

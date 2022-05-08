#include <firmament.h>

#include <stdint.h>
#include <string.h>

#include "px4_ecl_interface.h"
#include "px4_ecl_CppToC.h"

#include "module/log/mlog.h"
#include "module/param/param.h"
#include "module/sensor/sensor_hub.h"

#define ISFINITE(x) __builtin_isfinite(x)

/* define log data */
static mlog_elem_t PX4_ECL_Out_Elems[] = {
    MLOG_ELEMENT(timestamp, MLOG_UINT32),
    MLOG_ELEMENT(phi, MLOG_FLOAT),
    MLOG_ELEMENT(theta, MLOG_FLOAT),
    MLOG_ELEMENT(psi, MLOG_FLOAT),
    MLOG_ELEMENT_VEC(quat, MLOG_FLOAT, 4),
    MLOG_ELEMENT(p, MLOG_FLOAT),
    MLOG_ELEMENT(q, MLOG_FLOAT),
    MLOG_ELEMENT(r, MLOG_FLOAT),
    MLOG_ELEMENT(ax, MLOG_FLOAT),
    MLOG_ELEMENT(ay, MLOG_FLOAT),
    MLOG_ELEMENT(az, MLOG_FLOAT),
    MLOG_ELEMENT(vn, MLOG_FLOAT),
    MLOG_ELEMENT(ve, MLOG_FLOAT),
    MLOG_ELEMENT(vd, MLOG_FLOAT),
    MLOG_ELEMENT(reserved, MLOG_FLOAT),
    MLOG_ELEMENT(lat, MLOG_DOUBLE),
    MLOG_ELEMENT(lon, MLOG_DOUBLE),
    MLOG_ELEMENT(alt, MLOG_DOUBLE),
    MLOG_ELEMENT(x_R, MLOG_FLOAT),
    MLOG_ELEMENT(y_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_R, MLOG_FLOAT),
    MLOG_ELEMENT(h_AGL, MLOG_FLOAT),
    MLOG_ELEMENT(flag, MLOG_UINT32),
    MLOG_ELEMENT(status, MLOG_UINT32),
};
MLOG_BUS_DEFINE(PX4_ECL_Out, PX4_ECL_Out_Elems);
DEFINE_TIMETAG(px4_ecl_output, 100);
static int PX4_ECL_Out_ID;

/* PX4_ECL input bus */
MCN_DECLARE(sensor_imu0);
MCN_DECLARE(sensor_mag0);
MCN_DECLARE(sensor_baro);
MCN_DECLARE(sensor_gps);
MCN_DECLARE(sensor_rangefinder);
MCN_DECLARE(sensor_optflow);

/* PX4_ECL output bus */
MCN_DEFINE(px4_ecl_output, sizeof(PX4_ECL_Out_Bus));

// Bit locations for mag_declination_source
#define MASK_USE_GEO_DECL   (1<<0)  ///< set to true to use the declination from the geo library when the GPS position becomes available, set to false to always use the EKF2_MAG_DECL value
#define MASK_SAVE_GEO_DECL  (1<<1)  ///< set to true to set the EKF2_MAG_DECL parameter to the value returned by the geo library
#define MASK_FUSE_DECL      (1<<2)  ///< set to true if the declination is always fused as an observation to constrain drift when 3-axis fusion is performed


// Integer definitions for mag_fusion_type
#define MAG_FUSE_TYPE_AUTO      0	///< The selection of either heading or 3D magnetometer fusion will be automatic
#define MAG_FUSE_TYPE_HEADING   1	///< Simple yaw angle fusion will always be used. This is less accurate, but less affected by earth field distortions. It should not be used for pitch angles outside the range from -60 to +60 deg
#define MAG_FUSE_TYPE_3D        2	///< Magnetometer 3-axis fusion will always be used. This is more accurate, but more affected by localised earth field distortions
#define MAG_FUSE_TYPE_UNUSED    3	///< Not implemented
#define MAG_FUSE_TYPE_INDOOR    4	///< The same as option 0, but magnetometer or yaw fusion will not be used unless earth frame external aiding (GPS or External Vision) is being used. This prevents inconsistent magnetic fields associated with indoor operation degrading state estimates.
#define MAG_FUSE_TYPE_NONE	    5	///< Do not use magnetometer under any circumstance. Other sources of yaw may be used if selected via the EKF2_AID_MASK parameter.

// GPS pre-flight check bit locations
#define MASK_GPS_NSATS  (1<<0)
#define MASK_GPS_PDOP   (1<<1)
#define MASK_GPS_HACC   (1<<2)
#define MASK_GPS_VACC   (1<<3)
#define MASK_GPS_SACC   (1<<4)
#define MASK_GPS_HDRIFT (1<<5)
#define MASK_GPS_VDRIFT (1<<6)
#define MASK_GPS_HSPD   (1<<7)
#define MASK_GPS_VSPD   (1<<8)

// Bit locations for fusion_mode
#define MASK_USE_GPS    (1<<0)		///< set to true to use GPS data
#define MASK_USE_OF     (1<<1)		///< set to true to use optical flow data
#define MASK_INHIBIT_ACC_BIAS (1<<2)	///< set to true to inhibit estimation of accelerometer delta velocity bias
#define MASK_USE_EVPOS	(1<<3)		///< set to true to use external vision position data
#define MASK_USE_EVYAW  (1<<4)		///< set to true to use external vision quaternion data for yaw
#define MASK_USE_DRAG   (1<<5)		///< set to true to use the multi-rotor drag model to estimate wind
#define MASK_ROTATE_EV  (1<<6)		///< set to true to if the EV observations are in a non NED reference frame and need to be rotated before being used
#define MASK_USE_GPSYAW (1<<7)		///< set to true to use GPS yaw data if available
#define MASK_USE_EVVEL  (1<<8)		///< set to true to use external vision velocity data

// Integer definitions for vdist_sensor_type
#define VDIST_SENSOR_BARO  0	///< Use baro height
#define VDIST_SENSOR_GPS   1	///< Use GPS height
#define VDIST_SENSOR_RANGE 2	///< Use range finder height
#define VDIST_SENSOR_EV    3    ///< Use external vision


#define	TERRAIN_FUSE_RANGEFINDER  (1 << 0)
#define	TERRAIN_FUSE_OPTICALFLOW  (1 << 1)

// Integer determine source of vision observation noise
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_X_VARIANCE 0
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_Y_VARIANCE 6
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_Z_VARIANCE 11
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_ROLL_VARIANCE 15
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_PITCH_VARIANCE 18
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_YAW_VARIANCE 20
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_VX_VARIANCE 0
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_VY_VARIANCE 6
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_VZ_VARIANCE 11
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_ROLLRATE_VARIANCE 15
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_PITCHRATE_VARIANCE 18
#define VEHICLE_ODOMETRY_COVARIANCE_MATRIX_YAWRATE_VARIANCE 20
#define VEHICLE_ODOMETRY_LOCAL_FRAME_NED 0
#define VEHICLE_ODOMETRY_LOCAL_FRAME_FRD 1
#define VEHICLE_ODOMETRY_LOCAL_FRAME_OTHER 2
#define VEHICLE_ODOMETRY_BODY_FRAME_FRD 3

/* define parameters */
static param_t __param_list[] = {

        // 影响 1.imu降采样的采样个数 2.ekf滤波器的更新时间 3.间接用于观测时间向ekf更新的中心时间对齐
        // note：ekf最终的滤波间隔时间不严格等于_param_ekf2_predict_us，取决于降采样判断是否输出
        // 此次参数在 ECL 库函数中默认为10ms
		// PARAM_INT32(_param_ekf2_predict_us,10000),   ///< ekf update period PX4_ECL 规定为10ms 

        // ekf 预测更新时的输入噪声(imu var) 根据传感器输出
        // "x(k+1|k) = F · x(k|k) + G · Nk" 中的 Nk
		PARAM_FLOAT(_param_ekf2_gyr_noise,1.5e-2f),	    ///< IMU angular rate noise used for covariance prediction (rad/sec)
		PARAM_FLOAT(_param_ekf2_acc_noise,3.5e-1f),	    ///< IMU acceleration noise use for covariance prediction (m/sec**2)

		// ekf 过程噪声
        // ekf 协方差 "P(k+1|k) = F P(k|k) F^T + Q + N_process" 中的 N_process
		PARAM_FLOAT(_param_ekf2_gyr_b_noise,1.0e-3f),	///< process noise for IMU rate gyro bias prediction (rad/sec**2)
		PARAM_FLOAT(_param_ekf2_acc_b_noise,1.0e-2f),   ///< process noise for IMU accelerometer bias prediction (m/sec**3)
		PARAM_FLOAT(_param_ekf2_mag_e_noise,1.0e-3f),	///< process noise for earth magnetic field prediction (Gauss/sec)
		PARAM_FLOAT(_param_ekf2_mag_b_noise,1.0e-4f),	///< process noise for body magnetic field prediction (Gauss/sec)
		PARAM_FLOAT(_param_ekf2_wind_noise,1.0e-1f),	///< process noise for wind velocity prediction (m/sec**2)

        // baro 地面效应门限值
		PARAM_FLOAT(_param_ekf2_gnd_eff_dz,5.0f),	    ///< barometric deadzone range for negative innovations (m)
		PARAM_FLOAT(_param_ekf2_gnd_max_hgt,0.5f),	    ///< maximum height above the ground level for expected negative baro innovations (m)

		// control of magnetometer fusion
        // S = H · Pk+1|k· H^T + R 中的 R （标准差）
		PARAM_FLOAT(_param_ekf2_head_noise,3.0e-1f),	///< measurement noise used for simple heading fusion (rad)
		PARAM_FLOAT(_param_ekf2_mag_noise,5.0e-2f),		///< measurement noise used for 3-axis magnetoemeter fusion (Gauss)
		PARAM_FLOAT(_param_ekf2_eas_noise,1.4f),		///< measurement noise used for airspeed fusion (m/sec)
		PARAM_FLOAT(_param_ekf2_beta_noise,0.3f),	    ///< synthetic sideslip noise (rad)

        PARAM_FLOAT(_param_ekf2_noaid_noise,10.0f),		///< observation noise for non-aiding position fusion (m)
        PARAM_FLOAT(_param_ekf2_baro_noise,2.0f),        ///< observation noise for barometric height fusion (m)
        
        
        // 当地的磁偏角
		PARAM_FLOAT(_param_ekf2_mag_decl,0.0f),         ///< magnetic declination (degrees)

        // 磁偏角来源
		PARAM_INT32(_param_ekf2_decl_type, MASK_USE_GEO_DECL | MASK_SAVE_GEO_DECL | MASK_FUSE_DECL),    ///< bitmask used to control the handling of declination data

        // mag 融合的方式选择
		PARAM_INT32(_param_ekf2_mag_type,MAG_FUSE_TYPE_HEADING),   ///< integer used to specify the type of magnetometer fusion used

        // gps 采样数据检查项
		PARAM_INT32(_param_ekf2_gps_check, MASK_GPS_SACC | MASK_GPS_HACC | MASK_GPS_NSATS),  ///< bitmask used to control which GPS quality checks are used

		// measurement source control
		PARAM_INT32(_param_ekf2_aid_mask, MASK_USE_GPS),	    ///< bitmasked integer that selects which of the GPS and optical flow aiding sources will be used
		PARAM_INT32(_param_ekf2_hgt_mode, VDIST_SENSOR_BARO),   ///< selects the primary source for height data
		PARAM_INT32(_param_ekf2_terr_mask, TERRAIN_FUSE_RANGEFINDER | TERRAIN_FUSE_OPTICALFLOW),       ///< bitmasked integer that selects which of range finder and optical flow aiding sources will be used for terrain estimation

		// range finder fusion
        // range finder R
		PARAM_FLOAT(_param_ekf2_rng_noise,0.1f),	///< observation noise for range finder measurements (m)
		PARAM_INT32(_param_ekf2_rng_aid, 0),		///< enables use of a range finder even if primary height source is not range finder

		// vision estimate fusion
        // extern vision R 以及 R 的来源控制
        PARAM_INT32(_param_ekf2_ev_noise_md, VEHICLE_ODOMETRY_COVARIANCE_MATRIX_X_VARIANCE),	///< determine source of vision observation noise
		PARAM_FLOAT(_param_ekf2_evp_noise, 0.1f),	///< default position observation noise for exernal vision measurements (m)
		PARAM_FLOAT(_param_ekf2_evv_noise, 0.1f),	///< default velocity observation noise for exernal vision measurements (m/s)
		PARAM_FLOAT(_param_ekf2_eva_noise, 0.05f),	///< default angular observation noise for exernal vision measurements (rad)

		// optical flow fusion
        // optical flow 根据最好/最差的图像质量 差值计算 R
		PARAM_FLOAT(_param_ekf2_of_n_min,0.15f),	///< best quality observation noise for optical flow LOS rate measurements (rad/sec)
		PARAM_FLOAT(_param_ekf2_of_n_max,0.5f),	    ///< worst quality observation noise for optical flow LOS rate measurements (rad/sec)


		// control of airspeed and sideslip fusion
		PARAM_FLOAT(_param_ekf2_arsp_thr,2.0f), 	///< A value of zero will disabled airspeed fusion. Any positive value sets the minimum airspeed which will be used (m/sec)
		PARAM_INT32(_param_ekf2_fuse_beta, 0),		///< Controls synthetic sideslip fusion, 0 disables, 1 enables

		// Multi-rotor drag specific force fusion
        // drag fusion R 
		PARAM_FLOAT(_param_ekf2_drag_noise,2.5f),	    ///< observation noise variance for drag specific force measurements (m/sec**2)**2

        // mag 磁场总强度检查过滤 
		PARAM_INT32(_param_ekf2_mag_check, 0),          ///< Mag field strength check

        // mag 垂直分量是否参与观测
		PARAM_INT32(_param_ekf2_synthetic_mag_z, 0),     ///< Enables the use of a synthetic value for the Z axis of the magnetometer calculated from the 3D magnetic field vector at the location of the drone.

        //需求的 GPS health 的最小时间 （s）
        PARAM_FLOAT(_param_ekf2_req_gps_h, 10.0f)       ///< Required GPS health time

};
PARAM_GROUP_DEFINE(PX4_ECL, __param_list);

static struct PX4_ECL_Handler {

    McnNode_t imu_sub_node_t;
    McnNode_t mag_sub_node_t;
    McnNode_t baro_sub_node_t;
    McnNode_t gps_sub_node_t;
    McnNode_t rf_sub_node_t;
    McnNode_t optflow_sub_node_t;

    imu_data_t imu_report;
    uint64_t imu_report_last_time_ms;
    mag_data_t mag_report;
    baro_data_t baro_report;
    gps_data_t gps_report;
    rf_data_t rf_report;
    optflow_data_t optflow_report;
    uint64_t optflow_report_last_time_ms;

}px4_ecl_handle;

static struct{

    // int32_t _param_ekf2_predict_us; ///< ekf update period PX4_ECL 规定为10ms 

    float _param_ekf2_gyr_noise;	///< IMU angular rate noise used for covariance prediction (rad/sec)
    float _param_ekf2_acc_noise;	///< IMU acceleration noise use for covariance prediction (m/sec**2)

    // process noise
    float _param_ekf2_gyr_b_noise;	///< process noise for IMU rate gyro bias prediction (rad/sec**2)
    float _param_ekf2_acc_b_noise;  ///< process noise for IMU accelerometer bias prediction (m/sec**3)
    float _param_ekf2_mag_e_noise;	///< process noise for earth magnetic field prediction (Gauss/sec)
    float _param_ekf2_mag_b_noise;	///< process noise for body magnetic field prediction (Gauss/sec)
    float _param_ekf2_wind_noise;	///< process noise for wind velocity prediction (m/sec**2)

    float _param_ekf2_noaid_noise;	    ///< observation noise for non-aiding position fusion (m)
    float _param_ekf2_baro_noise;	    ///< observation noise for barometric height fusion (m)

    float _param_ekf2_gnd_eff_dz;	    ///< barometric deadzone range for negative innovations (m)
    float _param_ekf2_gnd_max_hgt;	    ///< maximum height above the ground level for expected negative baro innovations (m)

    // control of magnetometer fusion
    float _param_ekf2_head_noise;	    ///< measurement noise used for simple heading fusion (rad)
    float _param_ekf2_mag_noise;		///< measurement noise used for 3-axis magnetoemeter fusion (Gauss)
    float _param_ekf2_eas_noise;		///< measurement noise used for airspeed fusion (m/sec)
    float _param_ekf2_beta_noise;	    ///< synthetic sideslip noise (rad)

    float _param_ekf2_mag_decl;         ///< magnetic declination (degrees)
    int32_t _param_ekf2_decl_type;	    ///< bitmask used to control the handling of declination data

    int32_t _param_ekf2_mag_type;	    ///< integer used to specify the type of magnetometer fusion used

    int32_t _param_ekf2_gps_check;	///< bitmask used to control which GPS quality checks are used

    // measurement source control
    int32_t _param_ekf2_aid_mask;		///< bitmasked integer that selects which of the GPS and optical flow aiding sources will be used
    int32_t _param_ekf2_hgt_mode;	    ///< selects the primary source for height data
    int32_t _param_ekf2_terr_mask;      ///< bitmasked integer that selects which of range finder and optical flow aiding sources will be used for terrain estimation

    // range finder fusion
    float _param_ekf2_rng_noise;	///< observation noise for range finder measurements (m)
    int32_t _param_ekf2_rng_aid;    ///< enables use of a range finder even if primary height source is not range finder

    // vision estimate fusion
    // No initial value
    int32_t _param_ekf2_ev_noise_md;	///< determine source of vision observation noise
    float _param_ekf2_evp_noise;	    ///< default position observation noise for exernal vision measurements (m)
    float _param_ekf2_evv_noise;	    ///< default velocity observation noise for exernal vision measurements (m/s)
    float _param_ekf2_eva_noise;	    ///< default angular observation noise for exernal vision measurements (rad)

    // optical flow fusion
    float _param_ekf2_of_n_min;	    ///< best quality observation noise for optical flow LOS rate measurements (rad/sec)
    float _param_ekf2_of_n_max;	    ///< worst quality observation noise for optical flow LOS rate measurements (rad/sec)

    // control of airspeed and sideslip fusion
    float _param_ekf2_arsp_thr; 	    ///< A value of zero will disabled airspeed fusion. Any positive value sets the minimum airspeed which will be used (m/sec)
    int32_t _param_ekf2_fuse_beta;		///< Controls synthetic sideslip fusion, 0 disables, 1 enables

    // Multi-rotor drag specific force fusion
    float _param_ekf2_drag_noise;	///< observation noise variance for drag specific force measurements (m/sec**2)**2

    int32_t _param_ekf2_mag_check;          ///< Mag field strength check
    int32_t _param_ekf2_synthetic_mag_z;    ///< Enables the use of a synthetic value for the Z axis of the magnetometer calculated from the 3D magnetic field vector at the location of the drone.

    float _param_ekf2_req_gps_h;            ///< Required GPS health time

} px4_ecl_params;

static void * _ekf_parameters;

static void init_parameter(void){

    // FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_predict_us), &px4_ecl_params._param_ekf2_predict_us));

    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_gyr_noise), &px4_ecl_params._param_ekf2_gyr_noise));	///< IMU angular rate noise used for covariance prediction (rad/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_acc_noise), &px4_ecl_params._param_ekf2_acc_noise));	///< IMU acceleration noise use for covariance prediction (m/sec**2)

    // process noise
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_gyr_b_noise), &px4_ecl_params._param_ekf2_gyr_b_noise));	///< process noise for IMU rate gyro bias prediction (rad/sec**2)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_acc_b_noise), &px4_ecl_params._param_ekf2_acc_b_noise));   ///< process noise for IMU accelerometer bias prediction (m/sec**3)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_mag_e_noise), &px4_ecl_params._param_ekf2_mag_e_noise));	///< process noise for earth magnetic field prediction (Gauss/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_mag_b_noise), &px4_ecl_params._param_ekf2_mag_b_noise));	///< process noise for body magnetic field prediction (Gauss/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_wind_noise), &px4_ecl_params._param_ekf2_wind_noise));	    ///< process noise for wind velocity prediction (m/sec**2)

    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_noaid_noise), &px4_ecl_params._param_ekf2_noaid_noise));	///< observation noise for non-aiding position fusion (m)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_baro_noise), &px4_ecl_params._param_ekf2_baro_noise));	    ///< observation noise for barometric height fusion (m)
    
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_gnd_eff_dz), &px4_ecl_params._param_ekf2_gnd_eff_dz));	    ///< barometric deadzone range for negative innovations (m)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_gnd_max_hgt), &px4_ecl_params._param_ekf2_gnd_max_hgt));	///< maximum height above the ground level for expected negative baro innovations (m)

    // control of magnetometer fusion
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_head_noise), &px4_ecl_params._param_ekf2_head_noise));	    ///< measurement noise used for simple heading fusion (rad)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_mag_noise), &px4_ecl_params._param_ekf2_mag_noise));		///< measurement noise used for 3-axis magnetoemeter fusion (Gauss)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_eas_noise), &px4_ecl_params._param_ekf2_eas_noise));		///< measurement noise used for airspeed fusion (m/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_beta_noise), &px4_ecl_params._param_ekf2_beta_noise));	    ///< synthetic sideslip noise (rad)
    
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_mag_decl), &px4_ecl_params._param_ekf2_mag_decl));         ///< magnetic declination (degrees)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_decl_type), &px4_ecl_params._param_ekf2_decl_type));	    ///< bitmask used to control the handling of declination data
    
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_mag_type), &px4_ecl_params._param_ekf2_mag_type));	        ///< integer used to specify the type of magnetometer fusion used

    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_gps_check), &px4_ecl_params._param_ekf2_gps_check));	    ///< bitmask used to control which GPS quality checks are used

    // measurement source control
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_aid_mask), &px4_ecl_params._param_ekf2_aid_mask));		    ///< bitmasked integer that selects which of the GPS and optical flow aiding sources will be used
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_hgt_mode), &px4_ecl_params._param_ekf2_hgt_mode));	        ///< selects the primary source for height data
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_terr_mask), &px4_ecl_params._param_ekf2_terr_mask));      ///< bitmasked integer that selects which of range finder and optical flow aiding sources will be used for terrain estimation

    // range finder fusion
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_rng_noise), &px4_ecl_params._param_ekf2_rng_noise));	    ///< observation noise for range finder measurements (m)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_rng_aid), &px4_ecl_params._param_ekf2_rng_aid));		    ///< enables use of a range finder even if primary height source is not range finder

    // vision estimate fusion
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_ev_noise_md), &px4_ecl_params._param_ekf2_ev_noise_md));	///< determine source of vision observation noise
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_evp_noise), &px4_ecl_params._param_ekf2_evp_noise));	    ///< default position observation noise for exernal vision measurements (m)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_evv_noise), &px4_ecl_params._param_ekf2_evv_noise));	    ///< default velocity observation noise for exernal vision measurements (m/s)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_eva_noise), &px4_ecl_params._param_ekf2_eva_noise));	    ///< default angular observation noise for exernal vision measurements (rad)

    // optical flow fusion
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_of_n_min), &px4_ecl_params._param_ekf2_of_n_min));	        ///< best quality observation noise for optical flow LOS rate measurements (rad/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_of_n_max), &px4_ecl_params._param_ekf2_of_n_max));	        ///< worst quality observation noise for optical flow LOS rate measurements (rad/sec)

    // control of airspeed and sideslip fusion
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_arsp_thr), &px4_ecl_params._param_ekf2_arsp_thr)); 	    ///< A value of zero will disabled airspeed fusion. Any positive value sets the minimum airspeed which will be used (m/sec)
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_fuse_beta), &px4_ecl_params._param_ekf2_fuse_beta));		///< Controls synthetic sideslip fusion, 0 disables, 1 enables

    // Multi-rotor drag specific force fusion
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_drag_noise), &px4_ecl_params._param_ekf2_drag_noise));	    ///< observation noise variance for drag specific force measurements (m/sec**2)**2

    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_mag_check), &px4_ecl_params._param_ekf2_mag_check));              ///< Mag field strength check
    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_synthetic_mag_z), &px4_ecl_params._param_ekf2_synthetic_mag_z));  ///< Enables the use of a synthetic value for the Z axis of the magnetometer calculated from the 3D magnetic field vector at the location of the drone.

    FMT_CHECK(param_link_variable(PARAM_GET(PX4_ECL, _param_ekf2_req_gps_h), &px4_ecl_params._param_ekf2_req_gps_h));      ///< Required GPS health time
}


static void px4_ecl_init(void)
{
    // 新建 Ekf 类 (Ekf *_ekf)
    Ekf_new();

    // used pointer 
    _ekf_parameters = Ekf_getParamHandle();

    //*************************** set params ***************************//
    Ekf_set_param_ekf2_gyr_noise(px4_ecl_params._param_ekf2_gyr_noise);
    Ekf_set_param_ekf2_acc_noise(px4_ecl_params._param_ekf2_acc_noise);
    Ekf_set_param_ekf2_gyr_b_noise(px4_ecl_params._param_ekf2_gyr_b_noise);
    Ekf_set_param_ekf2_acc_b_noise(px4_ecl_params._param_ekf2_acc_b_noise);
    Ekf_set_param_ekf2_mag_e_noise(px4_ecl_params._param_ekf2_mag_e_noise);
    Ekf_set_param_ekf2_mag_b_noise(px4_ecl_params._param_ekf2_mag_b_noise);
    Ekf_set_param_ekf2_wind_noise(px4_ecl_params._param_ekf2_wind_noise);
    Ekf_set_param_ekf2_noaid_noise(px4_ecl_params._param_ekf2_noaid_noise);
    Ekf_set_param_ekf2_baro_noise(px4_ecl_params._param_ekf2_baro_noise);
    Ekf_set_param_ekf2_gnd_eff_dz(px4_ecl_params._param_ekf2_gnd_eff_dz);
    Ekf_set_param_ekf2_gnd_max_hgt(px4_ecl_params._param_ekf2_gnd_max_hgt);
    Ekf_set_param_ekf2_head_noise(px4_ecl_params._param_ekf2_head_noise);
    Ekf_set_param_ekf2_mag_noise(px4_ecl_params._param_ekf2_mag_noise);
    Ekf_set_param_ekf2_eas_noise(px4_ecl_params._param_ekf2_eas_noise);
    Ekf_set_param_ekf2_beta_noise(px4_ecl_params._param_ekf2_beta_noise);
    Ekf_set_param_ekf2_mag_decl(px4_ecl_params._param_ekf2_mag_decl);
    Ekf_set_param_ekf2_decl_type(px4_ecl_params._param_ekf2_decl_type);
    Ekf_set_param_ekf2_mag_type(px4_ecl_params._param_ekf2_mag_type);
    Ekf_set_param_ekf2_gps_check(px4_ecl_params._param_ekf2_gps_check);
    Ekf_set_param_ekf2_aid_mask(px4_ecl_params._param_ekf2_aid_mask);
    Ekf_set_param_ekf2_hgt_mode(px4_ecl_params._param_ekf2_hgt_mode);
    Ekf_set_param_ekf2_terr_mask(px4_ecl_params._param_ekf2_terr_mask);
    Ekf_set_param_ekf2_rng_noise(px4_ecl_params._param_ekf2_rng_noise);
    Ekf_set_param_ekf2_rng_aid(px4_ecl_params._param_ekf2_rng_aid);
    Ekf_set_param_ekf2_of_n_min(px4_ecl_params._param_ekf2_of_n_min);
    Ekf_set_param_ekf2_of_n_max(px4_ecl_params._param_ekf2_of_n_max);
    Ekf_set_param_ekf2_arsp_thr(px4_ecl_params._param_ekf2_arsp_thr);
    Ekf_set_param_ekf2_drag_noise(px4_ecl_params._param_ekf2_drag_noise);
    Ekf_set_param_ekf2_mag_check(px4_ecl_params._param_ekf2_mag_check);
    Ekf_set_param_ekf2_synthetic_mag_z(px4_ecl_params._param_ekf2_synthetic_mag_z);
    //*************************** set params ***************************//

    // 设置 ekf gps 最低需求的间隔时间
    Ekf_set_min_required_gps_health_time(px4_ecl_params._param_ekf2_req_gps_h * 1.0e6f);

    bool is_fixed_wing = false;
    Ekf_set_fuse_beta_flag(is_fixed_wing && (px4_ecl_params._param_ekf2_fuse_beta == 1));
    Ekf_set_is_fixed_wing(is_fixed_wing);


    Ekf_set_gnd_effect_flag(false);
    Ekf_set_in_air_status(true);

}

fmt_model_info_t px4_ecl_model_info;
void px4_ecl_interface_init(void){

    px4_ecl_model_info.period = 2;
    px4_ecl_model_info.info = NULL;

    mcn_advertise(MCN_HUB(px4_ecl_output), NULL);

    px4_ecl_handle.imu_sub_node_t = mcn_subscribe(MCN_HUB(sensor_imu0), NULL, NULL);
    px4_ecl_handle.mag_sub_node_t = mcn_subscribe(MCN_HUB(sensor_mag0), NULL, NULL);
    px4_ecl_handle.baro_sub_node_t = mcn_subscribe(MCN_HUB(sensor_baro), NULL, NULL);
    px4_ecl_handle.gps_sub_node_t = mcn_subscribe(MCN_HUB(sensor_gps), NULL, NULL);
    px4_ecl_handle.rf_sub_node_t = mcn_subscribe(MCN_HUB(sensor_rangefinder), NULL, NULL);
    px4_ecl_handle.optflow_sub_node_t = mcn_subscribe(MCN_HUB(sensor_optflow), NULL, NULL);

    PX4_ECL_Out_ID = mlog_get_bus_id("PX4_ECL_Out");
    FMT_ASSERT(PX4_ECL_Out_ID >= 0);

    init_parameter();

    px4_ecl_init();

}

PX4_ECL_Out_Bus px4_ecl_out_bus;
void px4_ecl_interface_step(uint32_t timestamp){
 
    memset(&px4_ecl_out_bus.flag,0,sizeof(px4_ecl_out_bus.flag));
    memset(&px4_ecl_out_bus.status,0,sizeof(px4_ecl_out_bus.flag));

    /* get sensor data */
    if (mcn_poll(px4_ecl_handle.imu_sub_node_t)) {

        mcn_copy(MCN_HUB(sensor_imu0), px4_ecl_handle.imu_sub_node_t, &px4_ecl_handle.imu_report);

        px4_ecl_out_bus.timestamp = (uint32_t)px4_ecl_handle.imu_report.timestamp_ms;

        bool clipping[3] = {false,false,false};

        uint32_t dt_imu = px4_ecl_handle.imu_report.timestamp_ms - (uint32_t)px4_ecl_handle.imu_report_last_time_ms;

        px4_ecl_handle.imu_report_last_time_ms = px4_ecl_handle.imu_report.timestamp_ms;

        Ekf_IMU_update(true, px4_ecl_handle.imu_report.timestamp_ms, dt_imu, px4_ecl_handle.imu_report.gyr_B_radDs, px4_ecl_handle.imu_report.acc_B_mDs2, clipping);

        px4_ecl_out_bus.status |= 1<<0;
        // px4_ecl_out_bus.status |= 1<<1;  ??

        Ekf_get_estimator_quaternion();
        Ekf_get_estimator_angrate();

        if (mcn_poll(px4_ecl_handle.mag_sub_node_t)) {

            mcn_copy(MCN_HUB(sensor_mag0), px4_ecl_handle.mag_sub_node_t, &px4_ecl_handle.mag_report);

            Ekf_MAG_update(true, px4_ecl_handle.mag_report.timestamp_ms, px4_ecl_handle.mag_report.mag_B_gauss);

            px4_ecl_out_bus.status |= 1<<2;

        }

        if (mcn_poll(px4_ecl_handle.baro_sub_node_t)) {

            mcn_copy(MCN_HUB(sensor_baro), px4_ecl_handle.baro_sub_node_t, &px4_ecl_handle.baro_report);

            Ekf_BARO_update(true, px4_ecl_handle.baro_report.timestamp_ms, px4_ecl_handle.baro_report.altitude_m);

            px4_ecl_out_bus.status |= 1<<3;
        }

        if(mcn_poll(px4_ecl_handle.gps_sub_node_t)){

            mcn_copy(MCN_HUB(sensor_gps), px4_ecl_handle.gps_sub_node_t, &px4_ecl_handle.gps_report);

            Ekf_GPS_update(true, px4_ecl_handle.gps_report.timestamp_ms, px4_ecl_handle.gps_report.lon, px4_ecl_handle.gps_report.lat,
                            px4_ecl_handle.gps_report.height, px4_ecl_handle.gps_report.hAcc, px4_ecl_handle.gps_report.vAcc,
                            px4_ecl_handle.gps_report.velN, px4_ecl_handle.gps_report.velE, px4_ecl_handle.gps_report.velD,
                            px4_ecl_handle.gps_report.vel, px4_ecl_handle.gps_report.cog,px4_ecl_handle.gps_report.sAcc,
                            px4_ecl_handle.gps_report.fixType,px4_ecl_handle.gps_report.numSV);

            px4_ecl_out_bus.status |= 1<<4;
        }

        if(Ekf_step()){  

            Ekf_get_estimator_angrate();
            Ekf_get_estimator_acc();
            Ekf_get_estimator_vel();
            Ekf_get_estimator_position();
            Ekf_get_estimator_global_position();
            Ekf_get_estimator_TerrainVertPos();
            
        }
        
        mcn_publish(MCN_HUB(px4_ecl_output), &px4_ecl_out_bus);

        if (check_timetag(TIMETAG(px4_ecl_output))) {
            /* Log PX4 ECL out data */
            mlog_push_msg((uint8_t*)&px4_ecl_out_bus, PX4_ECL_Out_ID, sizeof(px4_ecl_out_bus));
        }



    }
}

#ifndef BATTERY_H
#define BATTERY_H
#include <firmament.h>

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// #define USING_KALMAN_FILTER

#define LITHIUM_BATTERY_RECOGNITION_VOLTAGE 4.0f
#define OCV_DEFAULT 4.2f
#define OCV_COVARIANCE  0.05f
#define R_COVARIANCE 0.005f

// #define FLT_EPSILON 1.1920929e-07F 


typedef struct {
    float v_empty;
    float v_charged;
    int n_cells;
    float capacity;
    float r_internal;
    float low_thr;
    float crit_thr;
    float emergen_thr;
    // float bat_avrg_current;
} battery_params_t;

typedef struct {
    float x_hat;       // State estimate (SOC)
    float P;           // Error covariance
    float Q;           // Process noise covariance
    float R;           // Observation noise covariance
    float Q_base;      // Base value of Q
    float residual_mean_sq; // Residual mean square (exponential smoothing)
    float alpha;       // Smoothing factor (0.9~0.99)
    float beta;        // Q adjustment factor (0.5~1.0)
    float threshold;   // Residual threshold (set based on actual data)
} AdaptiveKalmanFilter;

typedef struct {
    uint32_t timestamp;
    battery_params_t params;
    bool connected;
    float voltage_v;
    float current_a;
    float internal_resistance;
    float temperature_c;
    float discharged_mah;
    float discharged_mah_loop;
    float state_of_charge_volt_based;
    float state_of_charge;
    float state_of_charge_init;
    float state_of_charge_current_based;
    float state_of_health;
    float scale;
    uint8_t warning;
    bool battery_initialized;
    bool internal_resistance_initialized;
    bool armed;
    uint32_t last_timestamp;
    uint32_t last_unconnected_timestamp;

    float cell_voltage;
    float cell_voltage_origin;

    AdaptiveKalmanFilter kalman_filter;

} Battery;

typedef enum {
    BATTERY_WARNING_NONE = 0,
    BATTERY_WARNING_LOW_VOLTAGE,
    BATTERY_WARNING_CRITICAL_VOLTAGE,
    BATTERY_WARNING_EMERGENCY_VOLTAGE
} battery_warning_t;


 void battery_init(Battery *battery, battery_params_t *params, uint8_t source, uint32_t timestamp);
 void battery_update_voltage(Battery *battery, float voltage_v);
 void battery_update_current(Battery *battery, float current_a);
 void battery_update_temperature(Battery *battery, float temperature_c);
 void battery_update_state_of_charge(Battery *battery, uint32_t timestamp);
 void sumDischarged(Battery *battery, uint32_t timestamp);
 float battery_calculate_soc_voltage_based(Battery *batterya);
 void battery_update_internal_resistance(Battery *battery);
 void battery_reset_internal_resistance(Battery *batterya);
 void battery_estimate_state_of_charge(Battery *battery);
 battery_warning_t battery_SOC_warning(Battery *battery);
 float estimate_soc_from_ocv(Battery *battery);
 void battery_update_state_of_health(Battery *battery);

 float Alpha_filter(float alpha, float x, float x_last);

 void AdaptiveKalmanFilter_Init(AdaptiveKalmanFilter *kf, float initial_soc, float initial_P, float initial_Q, float initial_R);
 float AdaptiveKalmanFilter_Update(AdaptiveKalmanFilter *kf, float z_coulomb, float z_voltage);


#endif // BATTERY_H
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <float.h>

#include "battery.h"


// Variable definitions
static float _RLS_est[2] = {0.0f, 0.0f};
static float _estimation_covariance[2][2] = {{1.0f, 0.0f}, {0.0f, 1.0f}}; // 需要初始值，否则可能未定义行为
static float dt = 0.0f;
static float cell_voltage = 0.0f;
static float _estimation_covariance_norm = 0.0f;
static float running_error_mean = 0.0f; // 用于平滑预测误差的绝对值
static float R_DEFAULT = 0.005f;

typedef struct {
    float ocv;  // Open Circuit Voltage (V)
    float soc;  // State of Charge (%)
} OCV_SOC_Map;
const OCV_SOC_Map ocv_soc_table[] = {
    {4.200, 100.0},  // Fully charged state
    {4.150, 95.0},   // Near full charge
    {4.100, 90.0},   // High SOC region
    {4.050, 85.0},
    {4.000, 80.0},
    {3.950, 70.0},   // Entering flat region
    {3.900, 60.0},   // Midpoint of flat region
    {3.850, 50.0},   // Nominal midpoint
    {3.800, 40.0},   // End of flat region
    {3.750, 30.0},   // Entering steep drop region
    {3.700, 20.0},   // Low battery warning
    {3.650, 15.0},
    {3.600, 10.0},   // Approaching discharge cutoff
    {3.500, 5.0},    // Deep discharge risk region
    {3.000, 0.0}     // Fully discharged cutoff
};


#define TABLE_SIZE (sizeof(ocv_soc_table) / sizeof(ocv_soc_table[0]))

void battery_init(Battery *battery, battery_params_t *battery_params, uint8_t source, uint32_t timestamp) {
    //need to read from PARAM List
    while (!PARAM_GET_FLOAT(POWER, VOLTAGE_EMPTY)) {
        rt_thread_mdelay(10);
    }
    battery_params->v_empty = PARAM_GET_FLOAT(POWER, VOLTAGE_EMPTY);
    battery_params->v_charged = PARAM_GET_FLOAT(POWER, VOLTAGE_CHARGED);
    battery_params->n_cells = PARAM_GET_UINT8(POWER, BAT_N_CELLS);
    battery_params->capacity = PARAM_GET_FLOAT(POWER, CAPACITY_OF_BAT);
    battery_params->r_internal = PARAM_GET_FLOAT(POWER, R_INTERNAL_CONST);
    battery_params->low_thr = PARAM_GET_FLOAT(POWER, LOW_THR);
    battery_params->crit_thr = PARAM_GET_FLOAT(POWER, CRIT_THR);
    battery_params->emergen_thr = PARAM_GET_FLOAT(POWER, EMERGEN_THR);
    // battery_params->bat_avrg_current = 0.0f;

    R_DEFAULT = PARAM_GET_FLOAT(POWER, R_INTERNAL);

    battery->timestamp = timestamp;
    battery->params = *battery_params;
    battery->connected = true;
    battery->voltage_v = 0.0f;
    battery->current_a = 0.0f;
    battery->internal_resistance = R_DEFAULT;
    battery->temperature_c = 0.0f;
    battery->discharged_mah = 0.0f;
    battery->discharged_mah_loop = 0.0f;
    battery->state_of_charge_volt_based = 0.0f;
    battery->state_of_charge = 0.0f;
    battery->state_of_charge_init = 0.0f;
    battery->state_of_health = 100.0f;
    battery->scale = 1.0f;
    battery->warning = BATTERY_WARNING_NONE;
    battery->battery_initialized = false;
    battery->internal_resistance_initialized = false;
    battery->armed = false;
    battery->last_timestamp = 0;
    battery->last_unconnected_timestamp = 0;
    

    
    _RLS_est[0] = battery->voltage_v;
    _RLS_est[1] = battery->internal_resistance * battery->params.n_cells;
    _estimation_covariance[0][0] = OCV_COVARIANCE * battery->params.n_cells;
    _estimation_covariance[1][1] = R_COVARIANCE * battery->params.n_cells;
    _estimation_covariance[0][1] = 0.0f;
    _estimation_covariance[1][0] = 0.0f;

}


/**
 * @brief Estimates the State of Charge (SOC) of a battery based on its open-circuit voltage (OCV).
 *
 * This function uses a predefined OCV-SOC lookup table to estimate the SOC of a battery.
 * If the voltage is outside the range of the table, it returns the boundary values (0% or 100%).
 * For voltages within the table range, it performs a linear interpolation to calculate the SOC.
 *
 * @param battery Pointer to the Battery structure containing the cell voltage.
 * @return Estimated SOC as a percentage (0.0 to 100.0).
 */
float estimate_soc_from_ocv(Battery *battery) {
    // If the voltage is outside the table range, return boundary values

    float voltage = battery->cell_voltage;

    if (voltage >= ocv_soc_table[0].ocv) {
        return 100.0;
    }
    if (voltage <= ocv_soc_table[TABLE_SIZE - 1].ocv) {
        return 0.0;
    }

    // Traverse the lookup table to find the voltage range
    for (int i = 0; i < TABLE_SIZE - 1; i++) {
        if (voltage <= ocv_soc_table[i].ocv && voltage > ocv_soc_table[i + 1].ocv) {
            // Perform linear interpolation to calculate SOC
            float v1 = ocv_soc_table[i].ocv;
            float v2 = ocv_soc_table[i + 1].ocv;
            float soc1 = ocv_soc_table[i].soc;
            float soc2 = ocv_soc_table[i + 1].soc;
            
            // Linear interpolation formula
            float soc = soc1 + (soc2 - soc1) * (voltage - v1) / (v2 - v1);
            return soc;
        }
    }

    return 0.0;  // Should not reach here
}


/**
 * @brief Updates the battery voltage.
 *
 * This function sets the battery's voltage value to the specified value.
 *
 * @param battery Pointer to the Battery structure.
 * @param voltage_v The new voltage value in volts.
 */
void battery_update_voltage(Battery *battery, float voltage_v) {
    battery->voltage_v = voltage_v;
}

/**
 * @brief Updates the battery current.
 *
 * This function sets the battery's current value to the specified value.
 *
 * @param battery Pointer to the Battery structure.
 * @param current_a The new current value in amperes.
 */
void battery_update_current(Battery *battery, float current_a) {
    battery->current_a = current_a;
}

/**
 * @brief Updates the battery temperature.
 *
 * This function sets the battery's temperature value to the specified value.
 *
 * @param battery Pointer to the Battery structure.
 * @param temperature_c The new temperature value in degrees Celsius.
 */
void battery_update_temperature(Battery *battery, float temperature_c) {
    battery->temperature_c = temperature_c;
}

/**
 * @brief Updates the state of charge (SOC) of the battery.
 *
 * This function calculates and updates the battery's state of charge based on its voltage,
 * connection status, and other parameters. It also handles the initialization of the battery
 * and updates warnings based on SOC thresholds.
 *
 * @param battery Pointer to the Battery structure.
 * @param timestamp Current timestamp in milliseconds.
 */
void battery_update_state_of_charge(Battery *battery, uint32_t timestamp) {
    
    if (battery->voltage_v < LITHIUM_BATTERY_RECOGNITION_VOLTAGE) {
        battery->connected = false;
    } else {
        battery->connected = true;
    }

    if (!battery->connected || (battery->last_unconnected_timestamp == 0)) {
        battery->last_unconnected_timestamp = timestamp;
        battery->state_of_charge_init = 0.0f;
    }

    battery->battery_initialized = battery->connected && (timestamp > battery->last_unconnected_timestamp + 3500);

    if (battery->connected && !battery->battery_initialized && battery->params.n_cells > 0) {
        battery_reset_internal_resistance(battery);
    }

    sumDischarged(battery, timestamp);
    battery->state_of_charge_volt_based = battery_calculate_soc_voltage_based(battery);

    if (battery->state_of_charge_init == 0 && (timestamp > battery->last_unconnected_timestamp + 2500)) {
        battery->state_of_charge_init = estimate_soc_from_ocv(battery);
    }

    battery_estimate_state_of_charge(battery);

    if (battery->connected && battery->battery_initialized) {
        battery->warning = battery_SOC_warning(battery);
    }

}
/**
 * @brief Calculates the discharged capacity of the battery in milliampere-hours (mAh).
 *
 * This function updates the discharged capacity of the battery based on the current
 * and the elapsed time since the last update. It skips the calculation if the current
 * is negative or if the last timestamp is not set.
 *
 * @param battery Pointer to the Battery structure.
 * @param timestamp Current timestamp in milliseconds.
 */
void sumDischarged(Battery *battery, uint32_t timestamp) {
    if (battery->current_a < 0.0f) {
        battery->last_timestamp = 0;
        return;   
    }

    if (battery->last_timestamp != 0) {
        dt = (timestamp - battery->last_timestamp);
        battery->discharged_mah_loop = (battery->current_a * dt / 1000) * (1000 / 3600.0f); // mAh
        battery->discharged_mah += battery->discharged_mah_loop;
    }
    battery->last_timestamp = timestamp;
}
/**
 * @brief Calculates the State of Charge (SOC) of the battery based on its voltage.
 *
 * This function calculates the SOC using the battery's voltage and internal resistance.
 * It applies filtering to smooth the cell voltage and adjusts the voltage based on the
 * battery's internal resistance and current. The SOC is then estimated using the OCV-SOC
 * lookup table.
 *
 * @param battery Pointer to the Battery structure.
 * @return SOC as a percentage (0.0 to 100.0), or -1.0 if the number of cells is zero.
 */
float battery_calculate_soc_voltage_based(Battery *battery) {

    if (battery->params.n_cells == 0) {
        return -1.0f;
    }

    cell_voltage = battery->voltage_v / battery->params.n_cells;
    battery->cell_voltage_origin = cell_voltage;
    if (battery->current_a > FLT_EPSILON) {
        battery_update_internal_resistance(battery);

        if (battery->params.r_internal > 0) {
            cell_voltage += battery->current_a * battery->params.r_internal;
        } else {
            cell_voltage += battery->internal_resistance * battery->current_a;
        }
    }
    // Apply filtering to cell_voltage
    battery->cell_voltage = Alpha_filter(0.4f, cell_voltage, battery->cell_voltage);
    if (cell_voltage <= battery->params.v_empty) {
        return 0.0f;
    } else if (cell_voltage >= battery->params.v_charged) {
        return 100.0f;
    } else {
        return estimate_soc_from_ocv(battery);
    }
}
/**
 * @brief Updates the internal resistance of the battery using Recursive Least Squares (RLS) estimation.
 *
 * This function dynamically adjusts the internal resistance of the battery based on the current and voltage measurements.
 * It uses a Recursive Least Squares (RLS) algorithm with dynamic error thresholds and forgetting factors to ensure stability
 * and robustness. The function also applies low-pass filtering to smooth the internal resistance updates.
 *
 * @param battery Pointer to the Battery structure.
 */
void battery_update_internal_resistance(Battery *battery) {
    // Define the x vector, where x[0] corresponds to OCV, and x[1] corresponds to the effect of internal resistance on current
    float x[2] = {1.0f, -battery->current_a};

    // Calculate the predicted voltage: OCV - (internal resistance * current)
    float voltage_prediction = x[0] * _RLS_est[0] + x[1] * _RLS_est[1];

    // Calculate the prediction error
    float prediction_error = battery->voltage_v - voltage_prediction;

    // ---------------------------
    // Dynamically adjust error threshold and forgetting factor
    // ---------------------------
    const float alpha_error = 0.3f;  
    running_error_mean = alpha_error * fabsf(prediction_error) + (1.0f - alpha_error) * running_error_mean;
    
    // Dynamic threshold is set to 3 times the smoothed mean
    float dynamic_threshold = 3.0f * running_error_mean;

    // Dynamically select forgetting factor: use a lower value for large errors to emphasize new data, and a higher value for small errors to maintain smoothness
    float lambda_dynamic = (fabsf(prediction_error) > dynamic_threshold) ? 0.9f : 0.98f;
    
    // ---------------------------
    // Introduce a regularization term to prevent the denominator from becoming too small
    const float epsilon = 1e-3f;

    // Calculate intermediate variables: temp0 and temp1
    float temp0 = _estimation_covariance[0][0] * x[0] + _estimation_covariance[0][1] * x[1];
    float temp1 = _estimation_covariance[1][0] * x[0] + _estimation_covariance[1][1] * x[1];
    float denom = lambda_dynamic + x[0] * temp0 + x[1] * temp1 + epsilon;
    
    if (fabsf(denom) < 1e-6f) {
        _RLS_est[0] = battery->voltage_v + _RLS_est[1] * battery->current_a;
        return;
    }

    // Calculate the gain vector gamma = P * x / denom
    float gamma[2] = { temp0 / denom, temp1 / denom };

    // Calculate the new RLS estimates
    float RLS_est_temp[2] = {
        _RLS_est[0] + gamma[0] * prediction_error,
        _RLS_est[1] + gamma[1] * prediction_error
    };

    // ---------------------------
    // Update the covariance matrix using the Joseph form to ensure stability
    // P_new = (I - gamma * x^T) * P * (I - gamma * x^T)^T / lambda_dynamic + gamma*gamma^T * R
    // where R is the measurement noise variance, set to a small constant
    // ---------------------------
    const float measurement_noise_var = 1e-3f;

    // Calculate the elements of I - gamma * x^T
    float a = 1.0f - gamma[0] * x[0];
    float b =       - gamma[0] * x[1];
    float c =       - gamma[1] * x[0];
    float d = 1.0f - gamma[1] * x[1];

    // Let the original covariance matrix P be:
    float p00 = _estimation_covariance[0][0];
    float p01 = _estimation_covariance[0][1];
    float p10 = _estimation_covariance[1][0];
    float p11 = _estimation_covariance[1][1];

    // First calculate M = (I - gamma * x^T) * P
    float M[2][2];
    M[0][0] = a * p00 + b * p10;
    M[0][1] = a * p01 + b * p11;
    M[1][0] = c * p00 + d * p10;
    M[1][1] = c * p01 + d * p11;

    // Then calculate P_new = M * (I - gamma * x^T)^T
    float P_new[2][2];
    P_new[0][0] = M[0][0] * a + M[0][1] * b;
    P_new[0][1] = M[0][0] * c + M[0][1] * d;
    P_new[1][0] = M[1][0] * a + M[1][1] * b;
    P_new[1][1] = M[1][0] * c + M[1][1] * d;

    // Divide by lambda_dynamic
    P_new[0][0] /= lambda_dynamic;
    P_new[0][1] /= lambda_dynamic;
    P_new[1][0] /= lambda_dynamic;
    P_new[1][1] /= lambda_dynamic;

    // Add the regularization term: gamma*gamma^T * measurement_noise_var
    P_new[0][0] += gamma[0] * gamma[0] * measurement_noise_var;
    P_new[0][1] += gamma[0] * gamma[1] * measurement_noise_var;
    P_new[1][0] += gamma[1] * gamma[0] * measurement_noise_var;
    P_new[1][1] += gamma[1] * gamma[1] * measurement_noise_var;

    // Ensure the covariance matrix is symmetric: take the average
    float avg01 = (P_new[0][1] + P_new[1][0]) / 2.0f;
    P_new[0][1] = avg01;
    P_new[1][0] = avg01;

    // Calculate the new covariance matrix norm (Frobenius norm)
    float new_cov_norm = sqrtf(P_new[0][0] * P_new[0][0] +
                                 2.0f * avg01 * avg01 +
                                 P_new[1][1] * P_new[1][1]);

    // If the prediction error exceeds the dynamic threshold, only update OCV (to prevent abnormal data from affecting internal resistance estimation)
    if (fabsf(prediction_error) > dynamic_threshold) {
        _RLS_est[0] = battery->voltage_v + _RLS_est[1] * battery->current_a;
        return;
    }

    // If the new covariance norm is better, update the RLS estimates and covariance
    if (new_cov_norm < _estimation_covariance_norm) {
        _RLS_est[0] = RLS_est_temp[0];
        _RLS_est[1] = RLS_est_temp[1];

        _estimation_covariance[0][0] = P_new[0][0];
        _estimation_covariance[0][1] = P_new[0][1];
        _estimation_covariance[1][0] = P_new[1][0];
        _estimation_covariance[1][1] = P_new[1][1];
        _estimation_covariance_norm = new_cov_norm;
    } else {
        _RLS_est[0] = battery->voltage_v + _RLS_est[1] * battery->current_a;
    }

    battery->internal_resistance = fmaxf(_RLS_est[1] / battery->params.n_cells, 0.f);
    
}

/**
 * @brief Resets the internal resistance estimation of the battery.
 *
 * This function initializes the Recursive Least Squares (RLS) estimation parameters
 * and updates the battery's internal resistance and voltage based on the current and
 * predefined resistance values.
 *
 * @param battery Pointer to the Battery structure.
 */
void battery_reset_internal_resistance(Battery *battery) {
    _RLS_est[0] = battery->voltage_v;
    _RLS_est[1] = R_DEFAULT * battery->params.n_cells;
    _estimation_covariance[0][0] = OCV_COVARIANCE * battery->params.n_cells;
    _estimation_covariance[1][1] = R_COVARIANCE * battery->params.n_cells;
    _estimation_covariance_norm = sqrtf(powf(_estimation_covariance[0][0], 2.f) + 2.f * powf(_estimation_covariance[1][0], 2.f) + powf(_estimation_covariance[1][1], 2.f));
    battery->internal_resistance = R_DEFAULT;

    if (battery->params.r_internal > 0.0f) {
        battery->voltage_v = battery->voltage_v + battery->current_a * battery->params.r_internal * battery->params.n_cells;
    } else {
        battery->voltage_v = battery->voltage_v + battery->current_a * battery->internal_resistance * battery->params.n_cells;
    }
}

/**
 * @brief Estimates the state of charge (SOC) of the battery.
 *
 * This function calculates the SOC using a combination of voltage-based estimation,
 * Coulomb counting, and dynamic weighting. It applies smoothing and constraints to
 * ensure stability and accuracy of the SOC estimation.
 *
 * @param battery Pointer to the Battery structure.
 */
void battery_estimate_state_of_charge(Battery *battery) {
    if ((battery->params.capacity > 0) && (battery->battery_initialized)) {
        float state_of_charge_volt_based = battery->state_of_charge_volt_based;
        float state_of_charge = battery->state_of_charge;

        // Optimization 1: Dynamically adjust weight
        // - Lower SOC increases voltage SOC error -> increase weight
        // - During charging, voltage rises quickly -> decrease weight
        float weight = 0.02f + 0.03f * expf(-state_of_charge_volt_based / 20.0f);

        // Optimization 2: Exponential smoothing for voltage SOC
        state_of_charge = (1 - weight) * state_of_charge + weight * state_of_charge_volt_based;

        // Optimization 3: Coulomb counting correction
        float delta_soc = (battery->discharged_mah_loop / battery->params.capacity) * 100.0;
        state_of_charge -= delta_soc;

        // Optimization 4: Improved SOC upper and lower bounds
        // Calculate current-based SOC
        float state_of_charge_current_based = battery->state_of_charge_init - (battery->discharged_mah / (battery->params.capacity * battery->state_of_health)) * 100.0;

        state_of_charge_current_based = fmaxf(0.0f, state_of_charge_current_based);
        battery->state_of_charge_current_based = state_of_charge_current_based;

        // Constrain SOC within bounds
        state_of_charge = fminf(fmaxf(state_of_charge, 0.0f), state_of_charge_current_based);
        battery_update_state_of_health(battery);

        // Optimization 5: Exponential smoothing for final SOC to reduce sudden changes
        battery->state_of_charge = Alpha_filter(0.4f, state_of_charge, battery->state_of_charge);
    } else {
        battery->state_of_charge = battery->state_of_charge_volt_based;
    }
}


/**
 * @brief Determines the battery warning level based on the state of charge (SOC).
 *
 * This function evaluates the SOC of the battery and returns a warning level
 * based on predefined thresholds for low, critical, and emergency voltage levels.
 *
 * @param battery Pointer to the Battery structure.
 * @return Warning level as a uint8_t value.
 */
uint8_t battery_SOC_warning(Battery *battery) {
    if (battery->state_of_charge < battery->params.low_thr) {
        return BATTERY_WARNING_LOW_VOLTAGE;
    } else if (battery->state_of_charge < battery->params.crit_thr) {
        return BATTERY_WARNING_CRITICAL_VOLTAGE;
    } else if (battery->state_of_charge < battery->params.emergen_thr) {
        return BATTERY_WARNING_EMERGENCY_VOLTAGE;
    } else {
        return BATTERY_WARNING_NONE;
    }
}

/**
 * @brief Updates the state of health (SOH) of the battery.
 *
 * This function calculates the SOH of the battery based on the difference
 * between the voltage-based SOC and the current-based SOC. The SOH is expressed
 * as a percentage, with larger differences reducing the SOH.
 *
 * @param battery Pointer to the Battery structure.
 */
void battery_update_state_of_health(Battery *battery) {
    float diff = fabs(battery->state_of_charge_volt_based - battery->state_of_charge_current_based);
    battery->state_of_health = 100.0f - diff * 1.5f;
}// the estimation of SOH is remained to be supported in the future

/**
 * @brief Applies an alpha filter for smoothing data.
 *
 * This function performs exponential smoothing on the input data using the given alpha value.
 * The alpha parameter determines the weight of the current value versus the previous value.
 *
 * @param alpha Smoothing factor (0.0 to 1.0). Higher values give more weight to the current value.
 * @param x Current value to be smoothed.
 * @param x_last Previous smoothed value.
 * @return Smoothed value after applying the alpha filter.
 */
float Alpha_filter(float alpha, float x, float x_last) {
    return alpha * x + (1.0f - alpha) * x_last;
}
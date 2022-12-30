/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <INS.h>
#include <firmament.h>

#include "ecl_wrapper.h"

INS_Out_Bus px4_ecl_out_bus = { 0 };
INS_Params px4_ecl_params = { 0 };

void px4_ecl_init(void)
{
    /* create EKF instance */
    Ekf_create();

    /* creat land detector instance*/
    ld_creat();

    /* set EKF parameter */
    Ekf_set_param_ekf2_gyr_noise(px4_ecl_params.ekf2_gyr_noise);
    Ekf_set_param_ekf2_acc_noise(px4_ecl_params.ekf2_acc_noise);
    Ekf_set_param_ekf2_gyr_b_noise(px4_ecl_params.ekf2_gyr_b_noise);
    Ekf_set_param_ekf2_acc_b_noise(px4_ecl_params.ekf2_acc_b_noise);
    Ekf_set_param_ekf2_mag_e_noise(px4_ecl_params.ekf2_mag_e_noise);
    Ekf_set_param_ekf2_mag_b_noise(px4_ecl_params.ekf2_mag_b_noise);
    Ekf_set_param_ekf2_wind_noise(px4_ecl_params.ekf2_wind_noise);
    Ekf_set_param_ekf2_noaid_noise(px4_ecl_params.ekf2_noaid_noise);
    Ekf_set_param_ekf2_baro_noise(px4_ecl_params.ekf2_baro_noise);
    Ekf_set_param_ekf2_gnd_eff_dz(px4_ecl_params.ekf2_gnd_eff_dz);
    Ekf_set_param_ekf2_gnd_max_hgt(px4_ecl_params.ekf2_gnd_max_hgt);
    Ekf_set_param_ekf2_head_noise(px4_ecl_params.ekf2_head_noise);
    Ekf_set_param_ekf2_mag_noise(px4_ecl_params.ekf2_mag_noise);
    Ekf_set_param_ekf2_eas_noise(px4_ecl_params.ekf2_eas_noise);
    Ekf_set_param_ekf2_beta_noise(px4_ecl_params.ekf2_beta_noise);
    Ekf_set_param_ekf2_mag_decl(px4_ecl_params.ekf2_mag_decl);
    Ekf_set_param_ekf2_decl_type(px4_ecl_params.ekf2_decl_type);
    Ekf_set_param_ekf2_mag_type(px4_ecl_params.ekf2_mag_type);
    Ekf_set_param_ekf2_gps_check(px4_ecl_params.ekf2_gps_check);
    Ekf_set_param_ekf2_aid_mask(px4_ecl_params.ekf2_aid_mask);
    Ekf_set_param_ekf2_hgt_mode(px4_ecl_params.ekf2_hgt_mode);
    Ekf_set_param_ekf2_terr_mask(px4_ecl_params.ekf2_terr_mask);
    Ekf_set_param_ekf2_rng_noise(px4_ecl_params.ekf2_rng_noise);
    Ekf_set_param_ekf2_rng_aid(px4_ecl_params.ekf2_rng_aid);
    Ekf_set_param_ekf2_of_n_min(px4_ecl_params.ekf2_of_n_min);
    Ekf_set_param_ekf2_of_n_max(px4_ecl_params.ekf2_of_n_max);
    Ekf_set_param_ekf2_arsp_thr(px4_ecl_params.ekf2_arsp_thr);
    Ekf_set_param_ekf2_drag_noise(px4_ecl_params.ekf2_drag_noise);
    Ekf_set_param_ekf2_mag_check(px4_ecl_params.ekf2_mag_check);
    Ekf_set_param_ekf2_synthetic_mag_z(px4_ecl_params.ekf2_synthetic_mag_z);

    /* set EKF gps minimum required period */
    Ekf_set_min_required_gps_health_time(px4_ecl_params.ekf2_req_gps_h * 1.0e6f);

    /*
     * The first time running Ekf_IMU_update() will trigger Ekf::init(uint64_t timestamp)
     * which causing some initialization options to fail. So run it once when FMT initializes PX4-EKF.
     */
    extern fmt_model_info_t ins_model_info;
    uint32_t timestamp_ms = systime_now_ms();
    uint32_t dt_ms = ins_model_info.period;
    float gyr_B_radDs[3] = { 0, 0, 0 };
    float acc_B_mDs2[3] = { 0, 0, -9.80665f };
    bool clipping[3] = { false, false, false };
    Ekf_IMU_update(timestamp_ms, dt_ms, gyr_B_radDs, acc_B_mDs2, clipping);

#ifdef VEHICLE_TYPE_QUADCOPTER
    bool is_fixed_wing = false;
#endif

#ifdef VEHICLE_TYPE_FIXWING
    bool is_fixed_wing = true;
#endif

    Ekf_set_fuse_beta_flag(is_fixed_wing && (px4_ecl_params.ekf2_fuse_beta == 1));
    Ekf_set_is_fixed_wing(is_fixed_wing);

    Ekf_set_gnd_effect_flag(false);
    Ekf_set_in_air_status(false);

    px4_ecl_out_bus.flag |= 1 << 0;
}

void px4_ecl_step(void)
{
    if(ld_IsUpdated()){
        Ekf_set_gnd_effect_flag(ld_get_gnd_effect());
        Ekf_set_in_air_status(!ld_get_landed_state());
    }

    if (Ekf_step()) {
        Ekf_get_attitude();
        Ekf_get_acc();
        Ekf_get_local_position();
        Ekf_get_global_position();
        Ekf_get_TerrainVertPos();

        /* run land detector*/
        ld_step();

    } else {
        Ekf_get_attitude();
    }
}

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

INS_Out_Bus px4_ecl_out_bus = {0};
INS_Params px4_ecl_params = {0};

void px4_ecl_init(void)
{
    // 新建 Ekf 类 (Ekf *_ekf)
    Ekf_create();

    //*************************** set params ***************************//
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
    //*************************** set params ***************************//

    // 设置 ekf gps 最低需求的间隔时间
    Ekf_set_min_required_gps_health_time(px4_ecl_params.ekf2_req_gps_h * 1.0e6f);

    bool is_fixed_wing = false;
    Ekf_set_fuse_beta_flag(is_fixed_wing && (px4_ecl_params.ekf2_fuse_beta == 1));
    Ekf_set_is_fixed_wing(is_fixed_wing);

    Ekf_set_gnd_effect_flag(false);
    Ekf_set_in_air_status(true);
}

void px4_ecl_step(void)
{
    if (Ekf_step()) {
        Ekf_get_estimator_quaternion();
        Ekf_get_estimator_angrate();
        Ekf_get_estimator_acc();
        Ekf_get_estimator_vel();
        Ekf_get_estimator_position();
        Ekf_get_estimator_global_position();
        Ekf_get_estimator_TerrainVertPos();
    }
}

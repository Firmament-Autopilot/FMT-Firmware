"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""
from ...common.mxs40sv2.nv_counter_calc import NvCounterCalculator
from ....core.key_helper import get_key_bytearray, calc_key_hash


class AssetMapCYW20829:
    """Asset map for CYW20829"""

    @staticmethod
    def get(p, **kwargs):
        """
        RAM applications asset map
        @params p: Policy parser
        @return: Initialized asset map

        Map fields description:
        size  - asset size in bytes
        shift - represents asset bits number that store a parameter. It says about
                the number of bits the value should be shifted to the left
        mask  - the number of bits used to store the asset item
        value - integer value of the bits.
        """
        assets = {
            "target_lcs": {
                "size": 4,
                "data": [
                    {
                        "name": "TARGET_LCS",
                        "shift": 0,
                        "value": p.get_target_lcs().value
                    },
                ],
            },
            "control_word": {
                "size": 4,
                "data": [
                    {
                        "name": "CONTROL_WORD",
                        "shift": 0,
                        "value": p.get_control_word()
                    },
                ],
            },
            "access_restrict": {
                "size": 4,
                "data": [
                    {
                        "name": "S_NS_AP_CTL_CM33",
                        "shift": 0,
                        "mask": 0x03,
                        "value": p.get_cm33_permission().value
                    },
                    {
                        "name": "S_NS_AP_CTL_SYS",
                        "shift": 2,
                        "mask": 0x03,
                        "value": p.get_sys_permission().value
                    },
                    {
                        "name": "S_NS_AP_CTL_DBG",
                        "shift": 4,
                        "mask": 0x03,
                        "value": p.get_cm33_dbg().value
                    },
                    {
                        "name": "S_NS_AP_CTL_NID",
                        "shift": 6,
                        "mask": 0x03,
                        "value": p.get_cm33_nid().value
                    },
                    {
                        "name": "S_NS_SYS_AP_MPC_PPC_ENABLE",
                        "shift": 8,
                        "mask": 0x01,
                        "value": p.get_mpc_ppc_permission().value
                    },
                    {
                        "name": "S_NS_SRAM",
                        "shift": 9,
                        "mask": 0x07,
                        "value": p.get_sram_region().value
                    },
                    {
                        "name": "S_NS_MMIO",
                        "shift": 12,
                        "mask": 0x03,
                        "value": p.get_mmio_region().value
                    },
                    {
                        "name": "DEAD_AP_CTL_CM33",
                        "shift": 14,
                        "mask": 0x03,
                        "value": p.get_dead_cm33_permission().value
                    },
                    {
                        "name": "DEAD_AP_CTL_SYS",
                        "shift": 16,
                        "mask": 0x03,
                        "value": p.get_dead_sys_permission().value
                    },
                    {
                        "name": "DEAD_AP_CTL_DBG",
                        "shift": 18,
                        "mask": 0x03,
                        "value": p.get_dead_cm33_dbg().value
                    },
                    {
                        "name": "DEAD_AP_CTL_NID",
                        "shift": 20,
                        "mask": 0x03,
                        "value": p.get_dead_cm33_nid().value
                    },
                    {
                        "name": "DEAD_SYS_AP_MPC_PPC_ENABLE",
                        "shift": 22,
                        "mask": 0x01,
                        "value": p.get_dead_mpc_ppc_permission().value
                    },
                    {
                        "name": "DEAD_SRAM",
                        "shift": 23,
                        "mask": 0x07,
                        "value": p.get_dead_sram_region().value
                    },
                    {
                        "name": "DEAD_MMIO",
                        "shift": 26,
                        "mask": 0x03,
                        "value": p.get_dead_mmio_region().value
                    },
                ],
            },
            "wounding": {
                "size": 4,
                "data": [
                    {
                        "name": "LISTEN_WINDOW",
                        "shift": 4,
                        "mask": 0x03,
                        "value": p.get_listen_window().value
                    },
                ]
            },
            "oem_config": {
                "size": 4,
                "data": [
                    {
                        "name": "CHIP_SELECT",
                        "shift": 0,
                        "mask": 0x01,
                        "value": p.get_chip_select().value
                    },
                    {
                        "name": "DATA_WIDTH",
                        "shift": 1,
                        "mask": 0x03,
                        "value": p.get_data_width().value
                    },
                    {
                        "name": "DATA_SELECT",
                        "shift": 3,
                        "mask": 0x03,
                        "value": p.get_data_select().value
                    },
                    {
                        "name": "ADDRESSING_MODE",
                        "shift": 5,
                        "mask": 0x01,
                        "value": p.get_addressing_mode().value
                    },
                    {
                        "name": "SMIF_CRYPTO_ENABLED",
                        "shift": 6,
                        "mask": 0x01,
                        "value": int(p.get_encryption())
                    },
                    {
                        "name": "SMIF_CONFIGURATION",
                        "shift": 8,
                        "mask": 0x0F,
                        "value": p.get_smif_configuration().value
                    },
                ],
            },
            "nv_counter": {
                "size": 4,
                "data": [
                    {
                        "name": "ANTI_ROLLBACK",
                        "shift": 0,
                        "value": NvCounterCalculator.calculate(
                            p.get_nv_counter(), p.get_bits_per_cnt(),
                            kwargs.get('image_id'))
                    },
                ],
            },
            "oem_key_0_hash": {
                "size": 16,
                "data": [
                    {
                        "name": "KEY_MANAGEMENT_0",
                        "shift": 0,
                        "value": calc_key_hash(p.get_pub_key_0_path()
                                               if p.get_program_oem_key_0_hash()
                                               else None)
                    },
                ],
            },
            "oem_key_1_hash": {
                "size": 16,
                "data": [
                    {
                        "name": "KEY_MANAGEMENT_1",
                        "shift": 0,
                        "value": (calc_key_hash(p.get_pub_key_1_path())
                                  if p.get_program_oem_key_1_hash()
                                  else get_key_bytearray(p.get_encrypt_key_path())
                                  if p.get_encryption()
                                  else calc_key_hash(None))
                    },
                ],
            },
            "pubkey": {
                "size": 516,
                "data": [
                    {
                        "name": "PUBLIC_KEY",
                        "shift": 0,
                        "value": get_key_bytearray(kwargs.get('pubkey'))
                    },
                ],
            },
        }

        return assets

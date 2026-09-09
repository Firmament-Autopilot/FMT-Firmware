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
import os
import json
from pathlib import Path

from ..common.mxs40sv2 import asset_enums as enums


class PolicyParser:
    """
    Provides functionality for searching data in the package policy.
    """
    def __init__(self, policy_file):
        """
        Creates instance of policy parser.
        :param policy_file: Path to policy file.
        """
        self.json = None
        self.policy_dir = None
        self.policy_file = None

        if policy_file is not None:
            self.initialize(policy_file)

    def initialize(self, policy_file):
        """Initializes parser"""
        self.policy_file = Path(policy_file).absolute()
        self.json = self.get_json(policy_file)
        self.policy_dir = os.path.dirname(policy_file)

    @staticmethod
    def get_json(filename):
        """
        Gets JSON file as a dictionary.
        :param filename: The JSON file.
        :return: JSON file as a dictionary.
        """
        with open(filename, encoding='utf-8') as f:
            file_content = f.read()
            try:
                data = json.loads(file_content)
            except json.decoder.JSONDecodeError as e:
                msg = f"Failed to parse policy '{filename}': {e.args[0]}"
                raise json.decoder.JSONDecodeError(msg, e.doc, e.pos)
        return data

    def policy_type(self):
        try:
            return self.json['policy']['type']
        except KeyError as e:
            raise KeyError(
                f'Policy type not specified ({self.policy_file})') from e

    def get_pub_key_0_path(self):
        try:
            path = self.json['pre_build']['keys']['oem_pub_key_0']['value']
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))
        except KeyError:
            return None
        return path

    def get_pub_key_1_path(self):
        try:
            path = self.json['pre_build']['keys']['oem_pub_key_1']['value']
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))
        except KeyError:
            return None
        return path

    def get_priv_key_0_path(self):
        try:
            path = self.json['post_build']['keys']['oem_priv_key_0']['value']
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))
        except KeyError:
            return None
        return path

    def get_priv_key_1_path(self):
        try:
            path = self.json['post_build']['keys']['oem_priv_key_1']['value']
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))
        except KeyError:
            return None
        return path

    def get_encrypt_key_path(self):
        try:
            path = self.json['pre_build']['keys']['encrypt_key']['value']
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))
        except KeyError:
            return None
        return path

    def get_cm33_permission(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['ap_cm33']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_listen_window(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['listen_window']['value']
            listen_window = enums.ListenWindow[value]
        except KeyError:
            listen_window = enums.ListenWindow['None']
        return listen_window

    def get_dead_cm33_permission(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['dead_ap_cm33']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_sys_permission(self):
        try:
            value = self.json['device_policy']['debug']['system']['ap']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_cm33_dbg(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['cm33_dbg']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_cm33_nid(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['cm33_nid']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_dead_cm33_dbg(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['dead_cm33_dbg']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_dead_cm33_nid(self):
        try:
            value = self.json['device_policy']['debug']['cpu']['dead_cm33_nid']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_dead_sys_permission(self):
        try:
            value = self.json['device_policy']['debug']['system']['dead_ap']['value']
            permission = enums.ApPermission[value]
        except KeyError:
            permission = enums.ApPermission['None']
        return permission

    def get_mpc_ppc_permission(self):
        try:
            value = self.json['device_policy']['debug']['system']['mpc/ppc']['value']
            permission = enums.MpcPpcPermission[value]
        except KeyError:
            permission = enums.MpcPpcPermission['None']
        return permission

    def get_dead_mpc_ppc_permission(self):
        try:
            value = self.json['device_policy']['debug']['system']['dead_mpc/ppc']['value']
            permission = enums.MpcPpcPermission[value]
        except KeyError:
            permission = enums.MpcPpcPermission['None']
        return permission

    def get_sram_region(self):
        try:
            value = self.json['device_policy']['debug']['system']['sram']['value']
            region = enums.SRAMPart[value]
        except KeyError:
            region = enums.SRAMPart['None']
        return region

    def get_dead_sram_region(self):
        try:
            value = self.json['device_policy']['debug']['system']['dead_sram']['value']
            region = enums.SRAMPart[value]
        except KeyError:
            region = enums.SRAMPart['None']
        return region

    def get_mmio_region(self):
        try:
            value = self.json['device_policy']['debug']['system']['mmio']['value']
            region = enums.MMIOPart[value]
        except KeyError:
            region = enums.MMIOPart['None']
        return region

    def get_dead_mmio_region(self):
        try:
            value = self.json['device_policy']['debug']['system']['dead_mmio']['value']
            region = enums.MMIOPart[value]
        except KeyError:
            region = enums.MMIOPart['None']
        return region

    def get_nv_counter(self):
        try:
            value = self.json['device_policy']['reprovisioning']['nv_counter']['value']
        except KeyError:
            value = 0
        return value

    def get_bits_per_cnt(self):
        try:
            value = self.json['device_policy']['reprovisioning']['nv_counter']['bits_per_cnt']
        except KeyError:
            value = [32]
        return value

    def get_complete_provisioning(self):
        try:
            value = self.json['device_policy']['misc']['complete_provisioning']['value']
        except KeyError:
            value = False
        return value

    def get_sys_reset_req(self):
        try:
            value = self.json['device_policy']['flow_control']['sys_reset_req']['value']
        except KeyError:
            value = False
        return value

    def get_revoke_icv_pubkey_0(self):
        try:
            value = self.json['device_policy']['reprovisioning']['revoke_icv_pubkey_0']['value']
        except KeyError:
            value = False
        return value

    def get_revoke_oem_pubkey_0(self):
        try:
            value = self.json['device_policy']['reprovisioning']['revoke_oem_pubkey_0']['value']
        except KeyError:
            value = False
        return value

    def get_smif_configuration(self):
        try:
            value = self.json['device_policy']['smif_config']['smif_configuration']['value']
            smif_config = enums.SMIFConfiguation[value]
        except KeyError:
            smif_config = enums.SMIFConfiguation['None']
        return smif_config

    def get_chip_select(self):
        try:
            value = self.json['device_policy']['smif_config']['chip_select']['value']
            chip_select = enums.ChipSelect[value]
        except KeyError:
            chip_select = enums.ChipSelect['None']
        return chip_select

    def get_data_width(self):
        try:
            value = self.json['device_policy']['smif_config']['data_width']['value']
            data_width = enums.DataWidth[value]
        except KeyError:
            data_width = enums.DataWidth['None']
        return data_width

    def get_data_select(self):
        try:
            value = self.json['device_policy']['smif_config']['data_select']['value']
            data_select = enums.DataSelect[value]
        except KeyError:
            data_select = enums.DataSelect['None']
        return data_select

    def get_addressing_mode(self):
        try:
            value = self.json['device_policy']['smif_config']['addressing_mode']['value']
            mode = enums.AddressingMode[value]
        except KeyError:
            mode = enums.AddressingMode["None"]
        return mode

    def get_encryption(self):
        try:
            value = self.json['device_policy']['smif_config']['encryption']['value']
        except KeyError:
            value = False
        return value

    def get_target_lcs(self):
        try:
            value = self.json['device_policy']['flow_control']['target_lcs']['value']
            target_lcs = enums.LifecycleStage[value]
        except KeyError:
            target_lcs = enums.LifecycleStage['None']
        return target_lcs

    def get_program_oem_assets(self):
        try:
            value = self.json['device_policy']['flow_control']['program_oem_assets']['value']
        except KeyError:
            value = False
        return value

    def get_program_oem_key_0_hash(self):
        try:
            value = self.json['device_policy']['flow_control']['program_oem_key_0_hash']['value']
        except KeyError:
            value = False
        return value

    def get_program_oem_key_1_hash(self):
        try:
            value = self.json['device_policy']['flow_control']['program_oem_key_1_hash']['value']
        except KeyError:
            value = False
        return value

    def get_control_word(self):
        value = 0
        if self.get_program_oem_assets():
            value |= enums.ControlWord.PROGRAM_OEM_ASSETS_MSK
        if self.get_program_oem_key_0_hash():
            value |= enums.ControlWord.PROGRAM_OEM_KEY_0_HASH_MSK
        if self.get_program_oem_key_1_hash():
            value |= enums.ControlWord.PROGRAM_OEM_KEY_1_HASH_MSK
        if self.get_encryption():
            value |= enums.ControlWord.PROGRAM_ENCRYPT_KEY_MSK
        if self.get_revoke_icv_pubkey_0():
            value |= enums.ControlWord.REVOKE_ICV_PUBKEY_MSK
        if self.get_revoke_oem_pubkey_0():
            value |= enums.ControlWord.REVOKE_OEM_PUBKEY_MSK
        if self.get_sys_reset_req():
            value |= enums.ControlWord.RESET_DEVICE_MSK
        return value

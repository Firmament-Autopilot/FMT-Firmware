"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import hashlib
import os.path
from typing import Union

from ....core.key_handlers import load_key
from ...common.policy_parser_primitives import PolicyParserPrimitives
from ...common.mxs40sv2.asset_enums import LifecycleStage, ApPermission
from ..asset_enums import (
    ControlWord, SecBool, ListenWindow, BootCfgId, BootAuthL1,
    BootAuthL2, MMIORestrictions, DebugPins, BootOdClk
)
from ....core.key_handlers.ec_handler import ECHandler


class PolicyParserOemProvisioning(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def target_lcs(self, ret_value=False) -> Union[LifecycleStage, int]:
        """Gets a value of the device_policy.target_lcs property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(LifecycleStage, ret_value, 'device_policy',
                               'target_lcs', 'value')

    def control_word(self) -> int:
        """Gets a control word that is a combination of
        program_sflash_assets, program_iak, and program_hash properties
        """
        value = 0
        if self.program_sflash_assets():
            value |= ControlWord.PROG_SFLASH_ASSETS
        if self.program_iak():
            value |= ControlWord.PROG_IAK
        if self.program_hash():
            value |= ControlWord.PROG_HASH_EN
        return value

    def program_sflash_assets(self) -> bool:
        """Gets a value of the device_policy.program_sflash_assets property"""
        value = self.field('device_policy', 'program_sflash_assets', 'value')
        return value is True

    def program_iak(self) -> bool:
        """Gets a value of the device_policy.program_iak property"""
        value = self.field('device_policy', 'program_iak', 'value')
        return value is True

    def program_hash(self) -> bool:
        """Gets a value of the device_policy.program_hash property"""
        value = self.field('device_policy', 'program_hash', 'value')
        return value is True

    def nv_counter_l1(self) -> int:
        """Gets a value of the device_policy.nv_counter_l1 property"""
        nv_counter_l1 = self.field('device_policy', 'nv_counter_l1', 'value')
        return int(str(nv_counter_l1), 0) if nv_counter_l1 else 0

    def nv_counter_l2(self) -> int:
        """Gets a value of the device_policy.nv_counter_l2 property"""
        nv_counter_l2 = self.field('device_policy', 'nv_counter_l2', 'value')
        return int(str(nv_counter_l2), 0) if nv_counter_l2 else 0

    def prov_oem_complete(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the device_policy.prov_oem_complete property"""
        complete = self.field('device_policy', 'prov_oem_complete', 'value')
        if ret_value:
            return SecBool.SEC_TRUE if complete else SecBool.SEC_FALSE
        return complete

    def debug_ap_cm33(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.ap_cm33 property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'cpu', 'ap_cm33', 'value')

    def debug_listen_window(self, ret_value=False) -> Union[ListenWindow, int]:
        """Gets a value of the device_policy.debug.cpu.listen_window property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ListenWindow, ret_value, 'device_policy',
                               'debug', 'cpu', 'listen_window', 'value')

    def debug_cm33_dbg(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.cm33_dbg property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'cpu', 'cm33_dbg', 'value')

    def debug_cm33_nid(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.cm33_nid property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'cpu', 'cm33_nid', 'value')

    def debug_cm33_spid(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.cm33_spid property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'cpu', 'cm33_spid', 'value')

    def debug_cm33_spnid(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.cm33_spnid property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'cpu', 'cm33_spnid', 'value')

    def debug_cm33_secure(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.cm33_secure property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'cpu', 'cm33_secure', 'value')

    def debug_ap_system(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.system.ap property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'system', 'ap', 'value')

    def debug_sys_secure(self, ret_value=False) -> Union[ApPermission, int]:
        """Gets a value of the device_policy.debug.cpu.secure property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(ApPermission, ret_value, 'device_policy',
                               'debug', 'system', 'secure', 'value')

    def debug_mmio_restrictions(self, ret_value=False) -> Union[
            MMIORestrictions, int]:
        """Gets a value of the device_policy.debug.system.mmio_restrictions
        property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(MMIORestrictions, ret_value, 'device_policy',
                               'debug', 'system', 'mmio_restrictions', 'value')

    def debug_debug_pins(self, ret_value=False) -> Union[
            MMIORestrictions, int]:
        """Gets a value of the device_policy.debug.system.debug_pins
        property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(DebugPins, ret_value, 'device_policy',
                               'debug', 'system', 'debug_pins', 'value')

    def boot_cfg_id(self, ret_value=False) -> Union[BootCfgId, int]:
        """Gets a value of the device_policy.boot.boot_cfg_id property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(BootCfgId, ret_value, 'device_policy', 'boot',
                               'boot_cfg_id', 'value')

    def boot_dual_bank_enable(self) -> bool:
        """Gets a value of the device_policy.boot.boot_dual_bank_enable
        property
        """
        enable = self.field('device_policy', 'boot', 'boot_dual_bank_enable',
                            'value')
        return enable

    def boot_bank_ctr_offset(self) -> int:
        """Gets a value of the device_policy.boot.boot_bank_ctr_offset
        property
        """
        if self.boot_dual_bank_enable() is False:
            return SecBool.SEC_TRUE

        offset = self.field('device_policy', 'boot', 'boot_bank_ctr_offset',
                            'value')
        return int(str(offset), 0) if offset else 0

    def boot_auth_l1(self, ret_value=False) -> Union[BootAuthL1, int]:
        """Gets a value of the device_policy.boot.boot_auth_l1 property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(BootAuthL1, ret_value, 'device_policy', 'boot',
                               'boot_auth_l1', 'value')

    def boot_auth_l2(self, ret_value=False) -> Union[BootAuthL2, int]:
        """Gets a value of the device_policy.boot.boot_auth_l2 property
        @param ret_value: Returns value if True, otherwise enum object
        @return: The enum object or its value
        """
        return self.enum_field(BootAuthL2, ret_value, 'device_policy', 'boot',
                               'boot_auth_l2', 'value')

    def boot_auth(self) -> int:
        """Gets a combination of the device_policy.boot.boot_auth_l1 and
        device_policy.boot.boot_auth_l1 properties
        """
        return self.boot_auth_l1(ret_value=True) + self.boot_auth_l2(
            ret_value=True)

    def boot_auth_l2_enable(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the device_policy.boot.boot_auth_l2_enable
        property
        """
        enable = self.field('device_policy', 'boot', 'boot_auth_l2_enable',
                            'value')
        if ret_value:
            return SecBool.SEC_TRUE if enable else SecBool.SEC_FALSE
        return enable

    def boot_move_app(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the device_policy.boot.boot_move_app property"""
        move = self.field('device_policy', 'boot', 'boot_move_app', 'value')
        if ret_value:
            return SecBool.SEC_TRUE if move else SecBool.SEC_FALSE
        return move

    def boot_app_layout(self, ret_value=False) -> Union[list, bytes]:
        """Gets a value of the device_policy.boot.app_layout property"""
        app_layout = self.field('device_policy', 'boot', 'boot_app_layout',
                                'value')
        if ret_value:
            val = b''
            for item in app_layout:
                val += int(str(item['address']), 0).to_bytes(4,
                                                             byteorder='little')
                val += int(str(item['size']), 0).to_bytes(4, byteorder='little')
            return val
        return app_layout

    def boot_od_clk(self, ret_value=False) -> Union[BootOdClk, int]:
        """Gets a value of the device_policy.boot_od_clk property"""
        return self.enum_field(BootOdClk, ret_value, 'device_policy',
                               'boot_od_clk', 'value')

    def pc1_ctl_valid(self):
        """Gets a value of the device_policy.pc1_ctl_valid property"""
        return self.field('device_policy', 'pc1_ctl_valid', 'value')

    def pc2_ctl_valid(self):
        """Gets a value of the device_policy.pc2_ctl_valid property"""
        return self.field('device_policy', 'pc2_ctl_valid', 'value')

    def pc3_ctl_valid(self):
        """Gets a value of the device_policy.pc3_ctl_valid property"""
        return self.field('device_policy', 'pc3_ctl_valid', 'value')

    def pc_ctl_valid(self):
        """Gets a value that is a combination of the
        pc1_ctl_valid, pc2_ctl_valid, and pc3_ctl_valid properties
        """
        pc1 = 1 if self.pc1_ctl_valid() is True else 0
        pc2 = 1 if self.pc2_ctl_valid() is True else 0
        pc3 = 1 if self.pc3_ctl_valid() is True else 0
        return (pc1 << 1) | (pc2 << 2) | (pc3 << 3)

    def pc1_handler(self) -> int:
        """Gets a value of the device_policy.pc1_handler property"""
        addr = self.field('device_policy', 'pc1_handler', 'value')
        return int(str(addr), 0) if addr else 0xFFFFFFFF

    def pc2_handler(self) -> int:
        """Gets a value of the device_policy.pc2_handler property"""
        addr = self.field('device_policy', 'pc2_handler', 'value')
        return int(str(addr), 0) if addr else 0xFFFFFFFF

    def pc3_handler(self) -> int:
        """Gets a value of the device_policy.pc3_handler property"""
        addr = self.field('device_policy', 'pc3_handler', 'value')
        return int(str(addr), 0) if addr else 0xFFFFFFFF

    def dfu_enable(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the device_policy.dfu.dfu_enable property"""
        enable = self.field('device_policy', 'dfu', 'dfu_enable', 'value')
        if ret_value:
            return SecBool.SEC_TRUE if enable else SecBool.SEC_FALSE
        return enable is True

    def dfu_l1_update(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the device_policy.dfu.dfu_l1_update property"""
        update = self.field('device_policy', 'dfu', 'dfu_l1_update', 'value')
        if ret_value:
            return SecBool.SEC_TRUE if update else SecBool.SEC_FALSE
        return update is True

    def mpc_struct_ram(self, ret_value=False) -> Union[list, bytes]:
        """Gets a value of the device_policy.mpc.mpc_struct_ram property"""
        mpc_struct = self.field('device_policy', 'mpc', 'mpc_struct_ram',
                                'value')
        if ret_value:
            return self._mpc_struct(mpc_struct)
        return mpc_struct

    def mpc_struct_flash(self, ret_value=False) -> Union[list, bytes]:
        """Gets a value of the device_policy.mpc.mpc_struct_flash property"""
        mpc_struct = self.field('device_policy', 'mpc', 'mpc_struct_flash',
                                'value')
        if ret_value:
            return self._mpc_struct(mpc_struct)
        return mpc_struct

    def mpc_structs_bytes(self) -> bytes:
        """Gets a combined value of the device_policy.mpc.mpc_struct_ram
        and device_policy.mpc.mpc_struct_flash properties padded up to
        128 bytes
        """
        mpc_structs = self.mpc_struct_ram(
            ret_value=True) + self.mpc_struct_flash(ret_value=True)
        padding = bytes(256 - len(mpc_structs))
        return mpc_structs + padding

    def n_ram_mpc(self) -> int:
        """Gets number of RAM MPC structures"""
        mpc = self.mpc_struct_ram()
        return len(mpc) if mpc else 0

    def n_flash_mpc(self) -> int:
        """Gets number of Flash MPC structures"""
        mpc = self.mpc_struct_flash()
        return len(mpc) if mpc else 0

    @staticmethod
    def _mpc_struct(mpc_struct) -> bytes:
        """Gets MPC structure bytes"""
        val = b''
        for item in mpc_struct:
            offset_kb = int(item['offset'].upper().replace('KB', ''), 0)
            size_kb = int(item['size'].upper().replace('KB', ''), 0)
            val += int(offset_kb / 2).to_bytes(2, byteorder='little')
            val += int(size_kb / 2).to_bytes(2, byteorder='little')
            attr_value = 0
            cnt = 0
            for pc in item['attr']['value'].values():
                pc = pc.replace(' ', '')
                if pc[2] == 'N':
                    attr_value |= 1 << cnt
                cnt += 1
                if pc[1] == 'R':
                    attr_value |= 1 << cnt
                cnt += 1
                if pc[0] == 'W':
                    attr_value |= 1 << cnt
                cnt += 2  # skip the fourth bit
            val += attr_value.to_bytes(4, byteorder='little')
        return val

    def oem_rot_public_key_0(self, ret_hash=False):
        """Gets a value of the pre_build.keys.oem_rot_public_key_0 property
        @param ret_hash: Returns the key hash if True, otherwise the key path
        @return: The key path or key hash
        """
        path = self.field('pre_build', 'keys', 'oem_rot_public_key_0', 'value')
        value = self._oem_rot_public_key(path, ret_hash)
        return value

    def oem_rot_public_key_1(self, ret_hash=False):
        """Gets a value of the pre_build.keys.oem_rot_public_key_1 property
        @param ret_hash: Returns the key hash if True, otherwise the key path
        @return: The key path or key hash
        """
        path = self.field('pre_build', 'keys', 'oem_rot_public_key_1', 'value')
        value = self._oem_rot_public_key(path, ret_hash)
        return value

    def _oem_rot_public_key(self, path, ret_hash):
        """Gets either a key path or a key hash.
        For a simple app, the OEM keys are not used, and
        may not exist or may not be specified. In this case,
        a key hash is 16 null bytes.
        """
        if path:
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))

        if ret_hash:
            if path and os.path.isfile(path):
                return self._key_hash(path)
            if self.boot_cfg_id() == BootCfgId.BOOT_SIMPLE_APP:
                return b'\x00' * 16
        return path

    @staticmethod
    def _key_hash(key_path):
        """Gets hash or the key"""
        key = load_key(key_path)
        sha = hashlib.sha256()
        raw = ECHandler.raw_format(key)
        sha.update(raw[1:])
        return sha.digest()

    def raw_data_pc012(self):
        """Gets a value of the raw_data_pc012 property"""
        try:
            data = self.bin_file_field('raw_data_pc012', 'value')
            return data + b'\x00' * (256 - len(data))
        except (FileNotFoundError, TypeError):
            return b'\x00' * 256

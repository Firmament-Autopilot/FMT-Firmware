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
import os
from typing import Union

from ..asset_enums import SecBool, ProtFwAuthMethod, ProtFwAuthNextApp
from ....core.key_handlers import load_key
from ...common.policy_parser_primitives import PolicyParserPrimitives
from ....core.key_handlers.ec_handler import ECHandler


class PolicyParserProtectedFw(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def prot_fw_encrypt_enable(self) -> bool:
        """Gets a value of encrypt.enable property"""
        enable = self.field('encrypt', 'enable')
        return enable

    def prot_fw_encrypt_iv(self, ret_value=False) -> Union[str, bytes]:
        """Gets a value of encrypt.iv property"""
        iv = self.field('encrypt', 'iv')
        if ret_value:
            if iv == 'random':
                return os.urandom(16)
            else:
                return bytes.fromhex(iv) if iv else b''
        return iv

    def prot_fw_enable(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the prot_fw_enable property"""
        enable = self.field('prot_fw_enable', 'value')
        if ret_value:
            return SecBool.SEC_TRUE if enable else SecBool.SEC_FALSE
        return enable

    def prot_fw_auth_method(self, ret_value=False) -> Union[ProtFwAuthMethod,
                                                            int]:
        """Gets a value of the prot_fw_auth_method property"""
        return self.enum_field(ProtFwAuthMethod, ret_value,
                               'prot_fw_auth_method', 'value')

    def prot_fw_auth_next_app(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the prot_fw_auth_next_app property"""
        auth = self.field('prot_fw_auth_next_app', 'value')
        if ret_value:
            return ProtFwAuthNextApp[
                'AuthNext'].value if auth else ProtFwAuthNextApp['Skip'].value
        return auth

    def prot_fw_auth_ctl(self) -> int:
        """Gets a combination of the prot_fw_auth_method and
        prot_fw_auth_next_app properties
        """
        return self.prot_fw_auth_method(
            ret_value=True) + self.prot_fw_auth_next_app(ret_value=True)

    def prot_fw_rot_public_key_0(self, ret_hash=False) -> Union[str, bytes]:
        """Gets a value of the prot_fw_rot_public_key_0 property
        @param ret_hash: Returns the key hash if True, otherwise the key path
        @return: The key path or key hash
        """
        path = self.field('prot_fw_rot_public_key_0', 'value')
        value = self._prot_fw_rot_public_key(path, ret_hash)
        return value

    def prot_fw_rot_public_key_1(self, ret_hash=False) -> Union[str, bytes]:
        """Gets a value of the prot_fw_public_key_1 property
        @param ret_hash: Returns the key hash if True, otherwise the key path
        @return: The key path or key hash
        """
        path = self.field('prot_fw_rot_public_key_1', 'value')
        value = self._prot_fw_rot_public_key(path, ret_hash)
        return value

    def prot_fw_key(self, ret_value=True) -> Union[str, bytes]:
        """Gets a value of the prot_fw_key property"""
        if ret_value:
            return self.bin_file_field('prot_fw_key', 'value')
        else:
            return self.field('prot_fw_key', 'value')

    def prot_fw_addr(self) -> int:
        """Gets a value of the prot_fw_addr property"""
        addr = self.field('prot_fw_addr', 'value')
        return int(str(addr), 0) if addr else 0

    def prot_fw_size(self) -> int:
        """Gets a value of the prot_fw_size property"""
        size = self.field('prot_fw_size', 'value')
        return int(str(size), 0) if size else 0

    def prot_fw_rw_addr(self) -> int:
        """Gets a value of the prot_fw_rw_addr property"""
        addr = self.field('prot_fw_rw_addr', 'value')
        return int(str(addr), 0) if addr else 0

    def prot_fw_rw_size(self) -> int:
        """Gets a value of the prot_fw_rw_size property"""
        size = self.field('prot_fw_rw_size', 'value')
        return int(str(size), 0) if size else 0

    def prot_fw_ram_addr(self) -> int:
        """Gets a value of the prot_fw_ram_addr property"""
        addr = self.field('prot_fw_ram_addr', 'value')
        return int(str(addr), 0) if addr else 0

    def prot_fw_ram_size(self) -> int:
        """Gets a value of the prot_fw_ram_size property"""
        size = self.field('prot_fw_ram_size', 'value')
        return int(str(size), 0) if size else 0

    def prot_fw_nv_counter(self):
        """Gets a value of the prot_fw_nv_counter property"""
        nv_counter = self.field('prot_fw_nv_counter', 'value')
        return int(str(nv_counter), 0)

    def prot_fw_pc_ctl_valid(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the prot_fw_pc_ctl_valid property"""
        enable = self.field('prot_fw_pc_ctl_valid', 'value')
        if ret_value:
            return 1 if enable else 0
        return enable

    def prot_fw_pc1_handler(self) -> int:
        """Gets a value of the prot_fw_pc1_handler property"""
        addr = self.field('prot_fw_pc1_handler', 'value')
        return int(str(addr), 0) if addr else 0

    def prot_fw_complete(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of the prot_fw_complete property"""
        enable = self.field('prot_fw_complete', 'value')
        if ret_value:
            return SecBool.SEC_TRUE if enable else SecBool.SEC_FALSE
        return enable

    def _prot_fw_rot_public_key(self, path, ret_hash):
        """Gets either a key path or a key hash"""
        if path:
            if not os.path.isabs(path):
                path = os.path.abspath(os.path.join(self.policy_dir, path))

        if ret_hash:
            if path and os.path.isfile(path):
                return self._key_hash_prot_fw(path)
        return path

    @staticmethod
    def _key_hash_prot_fw(key_path):
        """Gets hash or the key"""
        key = load_key(key_path)
        sha = hashlib.sha256()
        raw = ECHandler.raw_format(key)
        sha.update(raw[1:])
        return sha.digest()

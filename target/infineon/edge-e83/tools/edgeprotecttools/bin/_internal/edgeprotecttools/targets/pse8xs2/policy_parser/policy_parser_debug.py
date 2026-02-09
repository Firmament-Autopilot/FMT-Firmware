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
import logging
import os

from ...common.policy_parser_primitives import PolicyParserPrimitives
from ...common.mxs22 import asset_enums as enums
from ....core.key_handlers import load_public_key
from ....core.key_handlers.ec_handler import ECHandler

logger = logging.getLogger(__name__)


class PolicyParserDebug(PolicyParserPrimitives):
    """Provides functionality for searching data in the policy file"""

    def __init__(self, json, policy_dir):
        """Provides access to the main policy parser class members"""
        self.json = json
        self.policy_dir = policy_dir
        PolicyParserPrimitives.__init__(self, self.json, self.policy_dir)

    def debug_cm33_cpu(self, ret_value=False):
        """Gets a value of debug.cm33.cpu property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.ApPermission, ret_value,
                               'debug', 'cm33', 'cpu', 'value')

    def debug_cm33_allowed(self, ret_value=False):
        """Gets a value of debug.cm33.allowed property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.CpuControlType, ret_value,
                               'debug', 'cm33', 'allowed', 'value')

    def debug_cm33_dbgen(self):
        """Gets a value of debug.cm33.dbgen property"""
        return self.field('debug', 'cm33', 'dbgen', 'value')

    def debug_cm33_niden(self):
        """Gets a value of debug.cm33.niden property"""
        return self.field('debug', 'cm33', 'niden', 'value')

    def debug_cm33_spiden(self):
        """Gets a value of debug.cm33.spiden property"""
        return self.field('debug', 'cm33', 'spiden', 'value')

    def debug_cm33_spniden(self):
        """Gets a value of debug.cm33.spniden property"""
        return self.field('debug', 'cm33', 'spniden', 'value')

    def debug_cm33_secure(self):
        """Gets a value of debug.cm33.secure property"""
        return self.field('debug', 'cm33', 'secure', 'value')

    def debug_system_ap(self, ret_value=False):
        """Gets a value of debug.system.ap property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.ApPermission, ret_value,
                               'debug', 'system', 'ap', 'value')

    def debug_system_allowed(self, ret_value=False):
        """Gets a value of debug.system.allowed property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.CpuControlType, ret_value,
                               'debug', 'system', 'allowed', 'value')

    def debug_system_mpc_ppc_enable(self):
        """Gets a value of debug.system.mpc_ppc_enable property"""
        return self.field('debug', 'system', 'mpc_ppc_enable', 'value')

    def debug_system_rram_otp_enable(self, ret_value=False):
        """Gets a value of debug.system.rram_otp_enable property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.RRamOtpPart, ret_value,
                               'debug', 'system', 'rram_otp_enable', 'value')

    def debug_system_rram_nvm_enable(self, ret_value=False):
        """Gets a value of debug.system.rram_nvm_enable property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.RamPart, ret_value,
                               'debug', 'system', 'rram_nvm_enable', 'value')

    def debug_system_ram_enable(self, ret_value=False):
        """Gets a value of debug.system.ram_enable property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.RamPart, ret_value,
                               'debug', 'system', 'ram_enable', 'value')

    def debug_system_mmio_enable(self, ret_value=False):
        """Gets a value of debug.system.mmio_enable property
        @param ret_value: Returns value if True, otherwise enum object
        @return: Enum object or its value
        """
        return self.enum_field(enums.MMIOPart, ret_value,
                               'debug', 'system', 'mmio_enable', 'value')

    def debug_system_secure(self):
        """Gets a value of debug.system.secure property"""
        return None if self.debug_system_ap() is None else \
            self.debug_system_ap() == enums.ApPermission.Enabled

    def debug_rma_permission(self):
        """Gets a value of debug.rma.permission property"""
        return self.field('debug', 'rma', 'permission', 'value')

    def debug_debug_key(self):
        """Gets a value of debug.debug_key property
        @return: debug key as raw bytes
        """
        key_value = self.field('debug', 'debug_key', 'value')

        if not key_value:
            return bytes(65)
        if os.path.isabs(key_value):
            key_path = key_value
        else:
            key_path = os.path.join(self.policy_dir, key_value)

        if os.path.isfile(key_path):
            key_value = ECHandler.raw_format(load_public_key(key_path))
        else:
            try:
                key_value = bytes.fromhex(key_value)
            except ValueError as e:
                raise ValueError("Neither an existing file nor a valid "
                                 "hexadecimal number was found in the policy "
                                 "'debug_key' property") from e

        return key_value

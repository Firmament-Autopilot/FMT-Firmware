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
import binascii

from .asset_map import AssetMapCYW20829
from ...common.mxs40sv2 import asset_enums as enums


class ReverseAssetMap:

    def __init__(self, policy_parser):
        self.policy_parser = policy_parser
        self.asset_map = AssetMapCYW20829
        self.encryption_enabled = None

    def reverse_asset(self, asset_name, asset_value):
        """
        Gets policy field path and value from the asset bytes
        @param asset_name: The name of the asset
        @param asset_value: The asset bytes
        @return: List of the tuples containing policy field path and value
        """
        pl = list()
        if 'target_lcs' == asset_name:
            pl.extend(self._target_lcs(asset_value))
        elif 'control_word' == asset_name:
            pl.extend(self._control_word(asset_value))
        elif 'access_restrict' == asset_name:
            pl.extend(self._access_restrict(asset_value))
        elif 'wounding' == asset_name:
            pl.extend(self._wounding(asset_value))
        elif 'oem_config' == asset_name:
            pl.extend(self._oem_config(asset_value))
        elif 'nv_counter' == asset_name:
            pl.extend(self._nv_counter(asset_value))
        elif 'oem_key_0_hash' == asset_name:
            pl.extend(self._oem_key_0_hash(asset_value))
        elif 'oem_key_1_hash' == asset_name:
            pl.extend(self._oem_key_1_hash(asset_value))
        return pl

    @staticmethod
    def _target_lcs(asset_value):
        return [('device_policy.flow_control.target_lcs.value',
                 enums.LifecycleStage(asset_value).name)]

    def _control_word(self, asset_value):
        lst = list()
        lst.append((
            'device_policy.flow_control.program_oem_assets.value',
            bool(asset_value & enums.ControlWord.PROGRAM_OEM_ASSETS_MSK)))
        lst.append((
            'device_policy.flow_control.program_oem_key_0_hash.value',
            bool(asset_value & enums.ControlWord.PROGRAM_OEM_KEY_0_HASH_MSK)))
        lst.append((
            'device_policy.flow_control.program_oem_key_1_hash.value',
            bool(asset_value & enums.ControlWord.PROGRAM_OEM_KEY_1_HASH_MSK)))
        lst.append((
            'device_policy.smif_config.encryption.value',
            bool(asset_value & enums.ControlWord.PROGRAM_ENCRYPT_KEY_MSK)))
        lst.append((
            'device_policy.reprovisioning.revoke_icv_pubkey_0.value',
            bool(asset_value & enums.ControlWord.REVOKE_ICV_PUBKEY_MSK)))
        lst.append((
            'device_policy.reprovisioning.revoke_oem_pubkey_0.value',
            bool(asset_value & enums.ControlWord.REVOKE_OEM_PUBKEY_MSK)))
        lst.append((
            'device_policy.flow_control.sys_reset_req.value',
            bool(asset_value & enums.ControlWord.RESET_DEVICE_MSK)))
        return lst

    def _access_restrict(self, asset_value):
        p = self.policy_parser
        lst = list()
        shift, mask = self.asset_item_data(p, 'access_restrict', 'S_NS_AP_CTL_CM33')
        lst.append((
            'device_policy.debug.cpu.ap_cm33.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'S_NS_AP_CTL_SYS')
        lst.append((
            'device_policy.debug.system.ap.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(
            p, 'access_restrict', 'S_NS_SYS_AP_MPC_PPC_ENABLE')
        lst.append((
            'device_policy.debug.system.mpc/ppc.value',
            enums.MpcPpcPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'S_NS_SRAM')
        lst.append((
            'device_policy.debug.system.sram.value',
            enums.SRAMPart((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'S_NS_MMIO')
        lst.append((
            'device_policy.debug.system.mmio.value',
            enums.MMIOPart((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'DEAD_AP_CTL_CM33')
        lst.append((
            'device_policy.debug.cpu.dead_ap_cm33.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'S_NS_AP_CTL_DBG')
        lst.append((
            'device_policy.debug.cpu.cm33_dbg.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'S_NS_AP_CTL_NID')
        lst.append((
            'device_policy.debug.cpu.cm33_nid.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'DEAD_AP_CTL_SYS')
        lst.append((
            'device_policy.debug.system.dead_ap.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'DEAD_AP_CTL_DBG')
        lst.append((
            'device_policy.debug.cpu.dead_cm33_dbg.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'DEAD_AP_CTL_NID')
        lst.append((
            'device_policy.debug.cpu.dead_cm33_nid.value',
            enums.ApPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(
            p, 'access_restrict', 'DEAD_SYS_AP_MPC_PPC_ENABLE')
        lst.append((
            'device_policy.debug.system.dead_mpc/ppc.value',
            enums.MpcPpcPermission((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'DEAD_SRAM')
        lst.append((
            'device_policy.debug.system.dead_sram.value',
            enums.SRAMPart((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'access_restrict', 'DEAD_MMIO')
        lst.append((
            'device_policy.debug.system.dead_mmio.value',
            enums.MMIOPart((asset_value >> shift) & mask).name))
        return lst

    def _wounding(self, asset_value):
        shift, mask = self.asset_item_data(
            self.policy_parser, 'wounding', 'LISTEN_WINDOW')
        return [('device_policy.debug.cpu.listen_window.value',
                 enums.ListenWindow((asset_value >> shift) & mask).name)]

    def _oem_config(self, asset_value):
        p = self.policy_parser
        lst = list()
        shift, mask = self.asset_item_data(p, 'oem_config', 'CHIP_SELECT')
        lst.append((
            'device_policy.smif_config.chip_select.value',
            enums.ChipSelect((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'oem_config', 'DATA_WIDTH')
        lst.append((
            'device_policy.smif_config.data_width.value',
            enums.DataWidth((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'oem_config', 'DATA_SELECT')
        lst.append((
            'device_policy.smif_config.data_select.value',
            enums.DataSelect((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'oem_config', 'ADDRESSING_MODE')
        lst.append((
            'device_policy.smif_config.addressing_mode.value',
            enums.AddressingMode((asset_value >> shift) & mask).name))
        shift, mask = self.asset_item_data(p, 'oem_config', 'SMIF_CRYPTO_ENABLED')
        self.encryption_enabled = bool((asset_value >> shift) & mask)
        lst.append((
            'device_policy.smif_config.encryption.value',
            self.encryption_enabled))
        shift, mask = self.asset_item_data(p, 'oem_config', 'SMIF_CONFIGURATION')
        lst.append((
            'device_policy.smif_config.smif_configuration.value',
            enums.SMIFConfiguation((asset_value >> shift) & mask).name))
        return lst

    @staticmethod
    def _nv_counter(asset_value):
        def nv_counter_to_int(value):
            res = 0
            while (value & 1) == 1:
                res += 1
                value >>= 1
            return res

        return [('device_policy.reprovisioning.nv_counter.value',
                 nv_counter_to_int(asset_value))]

    @staticmethod
    def _oem_key_0_hash(asset_value):
        return [('pre_build.keys.oem_pub_key_0.value',
                 binascii.hexlify(asset_value).decode())]

    def _oem_key_1_hash(self, asset_value):
        if self.encryption_enabled:
            field = 'pre_build.keys.encrypt_key.value'
        else:
            field = 'pre_build.keys.oem_pub_key_1.value'
        return [(field, binascii.hexlify(asset_value).decode())]

    def asset_item_data(self, p, asset_name, asset_item_name):
        """ Gets a tuple with the asset item size and mask """
        shift = None
        mask = None
        assets = self.asset_map.get(p)
        for item in assets[asset_name]['data']:
            if item['name'] == asset_item_name:
                shift = item['shift']
                mask = item['mask']
                break
        return shift, mask

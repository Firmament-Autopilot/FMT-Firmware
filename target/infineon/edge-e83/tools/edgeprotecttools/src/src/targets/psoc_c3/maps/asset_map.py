"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import json
import logging
import os
import time

from ...common.mxs40sv2.asset_enums import ApPermission, DeviceIntegrity
from ...common.mxs40sv2.enums import CoseSign1Packet

logger = logging.getLogger(__name__)


class AssetMapPsocC3:
    """Asset map for PSoC C3"""

    @staticmethod
    def get(p, **kwargs):
        """
        RAM applications asset map
        @params p: Policy parser
        @return: Initialized asset map

        Map fields description:
        size  - asset size in bytes
        shift - represents asset bits number that store a parameter. It says
                about the number of bits the value should be shifted to the left
        mask  - the number of bits used to store the asset item
        value - integer value of the bits.
        """
        policy_type = kwargs.get('policy_type')
        if not policy_type:
            policy_type = p.policy_type()

        if policy_type == 'oem_provisioning':
            return AssetMapPsocC3.oem_provisioning_assets(p)
        if policy_type == 'reprovisioning':
            return AssetMapPsocC3.reprovisioning_assets(p)
        if policy_type == 'prot_fw_policy':
            return AssetMapPsocC3.prot_fw_assets(p)
        if policy_type == 'prot_fw_dfu':
            return AssetMapPsocC3.prot_fw_dfu_assets(p)
        if policy_type == 'device_integrity_exam':
            return AssetMapPsocC3.device_integrity_exam_assets(p, **kwargs)
        if policy_type == 'provisioned':
            return AssetMapPsocC3.device_identity(p)
        if policy_type == 'normal_provisioned':
            return AssetMapPsocC3.prov_icv(p)

        raise ValueError(f"Unknown policy type '{policy_type}'")

    @staticmethod
    def device_integrity_exam_assets(_, **kwargs):
        """Gets device integrity exam assets"""
        cert_path = kwargs.get('integrity_cert')

        cert_data = AssetMapPsocC3._integrity_cert_data(cert_path)

        assets = {
            'nonce': {
                'id': DeviceIntegrity.NONCE,
                'value': nonce()
            },
            'cert': {
                'id': CoseSign1Packet.COSE_PACKET_ID,
                'value': cert_data
            }
        }

        return assets

    @staticmethod
    def oem_provisioning_assets(p):
        """Gets bytes for OEM provisioning assets"""
        assets = {
            'target_lcs': {
                'size': 4,
                'data': [
                    {
                        'name': 'TARGET_LCS',
                        'shift': 0,
                        'value': p.target_lcs(ret_value=True)
                    },
                ],
            },
            'control_word': {
                'size': 4,
                'data': [
                    {
                        'name': 'CONTROL_WORD',
                        'shift': 0,
                        'value': p.control_word()
                    },
                ],
            },
            'reserved_1': {
                'size': 1,
                'data': [
                    {
                        'name': 'Reserved',
                        'shift': 0,
                        'value': 0
                    },
                ],
            },
            'nv_counter_l1': {
                'size': 1,
                'data': [
                    {
                        'name': 'NV_COUNTER_L1',
                        'shift': 0,
                        'value': p.nv_counter_l1()
                    },
                ],
            },
            'nv_counter_l2': {
                'size': 1,
                'data': [
                    {
                        'name': 'NV_COUNTER_L2',
                        'shift': 0,
                        'value': p.nv_counter_l2()
                    },
                ],
            },
            'reserved_2': {
                'size': 1,
                'data': [
                    {
                        'name': 'Reserved',
                        'shift': 0,
                        'value': 0
                    },
                ],
            },
            'prov_oem_complete': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROV_OEM_COMPLETE',
                        'shift': 0,
                        'value': p.prov_oem_complete(ret_value=True)
                    },
                ],
            },
            'access_restrict': {
                'size': 4,
                'data': [
                    {
                        'name': 'CM33_0_ENABLE',
                        'shift': 0,
                        'mask': 0x01,
                        'value': int(
                            p.debug_ap_cm33() == ApPermission['Enable'])
                    },
                    {
                        'name': 'SYS_ENABLE',
                        'shift': 2,
                        'mask': 0x01,
                        'value': int(
                            p.debug_ap_system() == ApPermission['Enable'])
                    },
                    {
                        'name': 'CM33_0_DBG_ENABLE',
                        'shift': 4,
                        'mask': 0x01,
                        'value': int(
                            p.debug_cm33_dbg() == ApPermission['Enable'])
                    },
                    {
                        'name': 'CM33_0_NID_ENABLE',
                        'shift': 5,
                        'mask': 0x01,
                        'value': int(
                            p.debug_cm33_nid() == ApPermission['Enable'])
                    },
                    {
                        'name': 'CM33_0_SPID_ENABLE',
                        'shift': 6,
                        'mask': 0x01,
                        'value': int(
                            p.debug_cm33_spid() == ApPermission['Enable'])
                    },
                    {
                        'name': 'CM33_0_SPNID_ENABLE',
                        'shift': 7,
                        'mask': 0x01,
                        'value': int(
                            p.debug_cm33_spnid() == ApPermission['Enable'])
                    },
                    {
                        'name': 'CM33_0_SECURE_ENABLE',
                        'shift': 12,
                        'mask': 0x01,
                        'value': int(
                            p.debug_cm33_secure() == ApPermission['Enable'])
                    },
                    {
                        'name': 'SYS_SECURE_ENABLE',
                        'shift': 14,
                        'mask': 0x01,
                        'value': int(
                            p.debug_sys_secure() == ApPermission['Enable'])
                    },
                    {
                        'name': 'CM33_0_DISABLE',
                        'shift': 16,
                        'mask': 0x01,
                        'value': int(p.debug_ap_cm33() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'SYS_DISABLE',
                        'shift': 18,
                        'mask': 0x01,
                        'value': int(p.debug_ap_system() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'CM33_0_DBG_DISABLE',
                        'shift': 20,
                        'mask': 0x01,
                        'value': int(p.debug_cm33_dbg() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'CM33_0_NID_DISABLE',
                        'shift': 21,
                        'mask': 0x01,
                        'value': int(p.debug_cm33_nid() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'CM33_0_SPID_DISABLE',
                        'shift': 22,
                        'mask': 0x01,
                        'value': int(p.debug_cm33_spid() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'CM33_0_SPNID_DISABLE',
                        'shift': 23,
                        'mask': 0x01,
                        'value': int(p.debug_cm33_spnid() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'CM33_0_SECURE_DISABLE',
                        'shift': 28,
                        'mask': 0x01,
                        'value': int(p.debug_cm33_secure() == ApPermission[
                            'Permanently Disable'])
                    },
                    {
                        'name': 'SYS_SECURE_DISABLE',
                        'shift': 30,
                        'mask': 0x01,
                        'value': int(p.debug_sys_secure() == ApPermission[
                            'Permanently Disable'])
                    },
                ],
            },
            'access_restrict_2': {
                'size': 4,
                'data': [
                    {
                        'name': 'SYS_AP_MMIO',
                        'shift': 0,
                        'mask': 0x03,
                        'value': p.debug_mmio_restrictions(ret_value=True)
                    },
                    {
                        'name': 'DEBUG_PINS',
                        'shift': 4,
                        'mask': 0x0F,
                        'value': p.debug_debug_pins(ret_value=True)
                    },
                    {
                        'name': 'TAG',
                        'shift': 24,
                        'mask': 0xFF,
                        'value': 0xA3
                    }
                ],
            },
            'listen_window': {
                'size': 4,
                'data': [
                    {
                        'name': 'LISTEN_WINDOW',
                        'shift': 0,
                        'value': p.debug_listen_window(ret_value=True)
                    },
                ],
            },
            'boot_cfg_id': {
                'size': 4,
                'data': [
                    {
                        'name': 'BOOT_CFG_ID',
                        'shift': 0,
                        'value': p.boot_cfg_id(ret_value=True)
                    },
                ],
            },
            'boot_bank_ctr_offset': {
                'size': 4,
                'data': [
                    {
                        'name': 'BOOT_BANK_CTR_ADDR',
                        'shift': 0,
                        'value': p.boot_bank_ctr_offset()
                    },
                ],
            },
            'boot_fast_auth': {
                'size': 4,
                'data': [
                    {
                        'name': 'BOOT_FAST_AUTH',
                        'shift': 0,
                        'value': p.boot_auth()
                    },
                ],
            },
            'boot_auth_l2': {
                'size': 4,
                'data': [
                    {
                        'name': 'BOOT_AUTH_L2',
                        'shift': 0,
                        'value': p.boot_auth_l2_enable(ret_value=True)
                    },
                ],
            },
            'boot_move_app': {
                'size': 4,
                'data': [
                    {
                        'name': 'boot_move_app',
                        'shift': 0,
                        'value': p.boot_move_app(ret_value=True)
                    },
                ],
            },
            'boot_app_layout': {
                'size': 24,
                'data': [
                    {
                        'name': 'boot_app_layout',
                        'shift': 0,
                        'value': p.boot_app_layout(ret_value=True)
                    },
                ],
            },
            'oem_rot_key_0_hash': {
                'size': 16,
                'data': [
                    {
                        'name': 'OEM_ROT_KEY_0_HASH',
                        'shift': 0,
                        'value': p.oem_rot_public_key_0(ret_hash=True)[:16]
                    },
                ],
            },
            'oem_rot_key_1_hash': {
                'size': 16,
                'data': [
                    {
                        'name': 'OEM_ROT_KEY_1_HASH',
                        'shift': 0,
                        'value': p.oem_rot_public_key_1(ret_hash=True)[:16]
                    },
                ],
            },
            'dfu_enable': {
                'size': 4,
                'data': [
                    {
                        'name': 'DFU_ENABLE',
                        'shift': 0,
                        'value': p.dfu_enable(ret_value=True)
                    },
                ],
            },
            'dfu_l1_update': {
                'size': 4,
                'data': [
                    {
                        'name': 'DFU_L1_UPDATE',
                        'shift': 0,
                        'value': p.dfu_l1_update(ret_value=True)
                    },
                ],
            },
            'boot_od_clk': {
                'size': 1,
                'data': [
                    {
                        'name': 'BOOT_OD_CLK',
                        'shift': 0,
                        'value': p.boot_od_clk(ret_value=True)
                    },
                ],
            },
            'pc_ctl_valid': {
                'size': 1,
                'data': [
                    {
                        'name': 'PC_CTL_VALID',
                        'shift': 0,
                        'value': p.pc_ctl_valid()
                    },
                ],
            },
            'reserved_3': {
                'size': 2,
                'data': [
                    {
                        'name': 'Reserved',
                        'shift': 0,
                        'value': 0
                    },
                ],
            },
            'pc1_handler': {
                'size': 4,
                'data': [
                    {
                        'name': 'PC1_HANDLER',
                        'shift': 0,
                        'value': p.pc1_handler()
                    },
                ],
            },
            'pc2_handler': {
                'size': 4,
                'data': [
                    {
                        'name': 'PC2_HANDLER',
                        'shift': 0,
                        'value': p.pc2_handler()
                    },
                ],
            },
            'pc3_handler': {
                'size': 4,
                'data': [
                    {
                        'name': 'PC3_HANDLER',
                        'shift': 0,
                        'value': p.pc3_handler()
                    },
                ],
            },
            'n_ram_mpc': {
                'size': 1,
                'data': [
                    {
                        'name': 'N_RAM_MPC',
                        'shift': 0,
                        'value': p.n_ram_mpc()
                    },
                ],
            },
            'n_flash_mpc': {
                'size': 1,
                'data': [
                    {
                        'name': 'N_FLASH_MPC',
                        'shift': 0,
                        'value': p.n_flash_mpc()
                    },
                ],
            },
            'padding_1': {
                'size': 2,
                'data': [
                    {
                        'name': 'Padding',
                        'shift': 0,
                        'value': 0
                    },
                ],
            },
            'mpc_struct': {
                'size': 128,
                'data': [
                    {
                        'name': 'MPC_STRUCT',
                        'shift': 0,
                        'value': p.mpc_structs_bytes()
                    },
                ],
            },
            'raw_data_pc012': {
                'size': 256,
                'data': [
                    {
                        'name': 'OEM_RAW_DATA',
                        'shift': 0,
                        'value': p.raw_data_pc012()
                    },
                ],
            }
        }
        return assets

    @staticmethod
    def reprovisioning_assets(p):
        """Gets bytes for reprovisioning assets"""
        assets = {
            'revocation_flag': {
                'size': 4,
                'data': [
                    {
                        'name': 'flag',
                        'shift': 0,
                        'value': p.revoke(ret_value=True)
                    },
                ],
            },
            'public_key': {
                'size': 65,
                'data': [
                    {
                        'name': 'PUBLIC_KEY',
                        'shift': 0,
                        'value': p.public_key(ret_value=True)
                    },
                ],
            },
            'padding': {
                'size': 3,
                'data': [
                    {
                        'name': 'padding',
                        'shift': 0,
                        'value': bytes(3)
                    },
                ],
            }
        }
        return assets

    @staticmethod
    def prot_fw_assets(p):
        """Gets bytes for Protected FW assets"""
        assets = {
            'prot_fw_nv_counter': {
                'size': 1,
                'data': [
                    {
                        'name': 'PROT_FW_NV_COUNTER',
                        'shift': 0,
                        'value': p.prot_fw_nv_counter()
                    },
                ],
            },
            'padding_3': {
                'size': 3,
                'data': [
                    {
                        'name': 'padding',
                        'shift': 0,
                        'value': bytes(3)
                    },
                ],
            },
            'prot_fw_enable': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_ENABLED',
                        'shift': 0,
                        'value': p.prot_fw_enable(ret_value=True)
                    },
                ],
            },
            'prot_fw_auth_ctl': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_AUTH_CTL',
                        'shift': 0,
                        'value': p.prot_fw_auth_ctl()
                    },
                ],
            },
            'prot_fw_rot_key_0_hash': {
                'size': 16,
                'data': [
                    {
                        'name': 'PROT_FW_ROT_KEY_0_HASH',
                        'shift': 0,
                        'value': p.prot_fw_rot_public_key_0(ret_hash=True)[:16]
                    },
                ],
            },
            'prot_fw_rot_key_1_hash': {
                'size': 16,
                'data': [
                    {
                        'name': 'PROT_FW_ROT_KEY_1_HASH',
                        'shift': 0,
                        'value': p.prot_fw_rot_public_key_1(ret_hash=True)[:16]
                    },
                ],
            },
            'prot_fw_key': {
                'size': 16,
                'data': [
                    {
                        'name': 'PROT_FW_KEY',
                        'shift': 0,
                        'value': p.prot_fw_key()
                    },
                ],
            },
            'prot_fw_addr': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_ADDR',
                        'shift': 0,
                        'value': p.prot_fw_addr()
                    },
                ],
            },
            'prot_fw_size': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_SIZE',
                        'shift': 0,
                        'value': p.prot_fw_size()
                    },
                ],
            },
            'prot_fw_rw_addr': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_RW_ADDR',
                        'shift': 0,
                        'value': p.prot_fw_rw_addr()
                    },
                ],
            },
            'prot_fw_rw_size': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_RW_SIZE',
                        'shift': 0,
                        'value': p.prot_fw_rw_size()
                    },
                ],
            },
            'prot_fw_ram_addr': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_RAM_ADDR',
                        'shift': 0,
                        'value': p.prot_fw_ram_addr()
                    },
                ],
            },
            'prot_fw_ram_size': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_RAM_SIZE',
                        'shift': 0,
                        'value': p.prot_fw_ram_size()
                    },
                ],
            },
            'prot_fw_pc_ctl_valid': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_PC_CTL_VALID',
                        'shift': 0,
                        'value': p.prot_fw_pc_ctl_valid(
                            ret_value=True)
                    },
                ],
            },
            'prot_fw_pc1_handler': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_PC1_HANDLER',
                        'shift': 0,
                        'value': p.prot_fw_pc1_handler()
                    },
                ],
            },
            'prot_fw_complete': {
                'size': 4,
                'data': [
                    {
                        'name': 'PROT_FW_COMPLETE',
                        'shift': 0,
                        'value': p.prot_fw_complete(ret_value=True)
                    },
                ],
            }
        }
        return assets

    @staticmethod
    def prot_fw_dfu_assets(p):
        """Gets bytes for Protected FW assets"""
        assets = {
            'interface': {
                'size': 4,
                'data': [
                    {
                        'name': 'interface',
                        'shift': 0,
                        'value': p.interface(ret_value=True)
                    },
                ],
            },
            'iv': {
                'size': 16,
                'data': [
                    {
                        'name': 'iv',
                        'shift': 0,
                        'value': p.iv()
                    },
                ],
            }
        }
        return assets

    @staticmethod
    def device_identity(p):
        """Gets bytes for device_identity assets"""
        assets = {
            'nonce': {
                'size': 16,
                'data': [
                    {
                        'name': 'nonce',
                        'shift': 0,
                        'value': nonce(
                            p.dev_id_incremental_counter(ret_value=True),
                            p.dev_id_initial_value(ret_value=True)
                        )
                    },
                ],
            }
        }
        return assets

    @staticmethod
    def prov_icv(p):
        """Gets bytes for prov_icv assets"""
        assets = {
            'control_word': {
                'size': 4,
                'data': [
                    {
                        'name': 'CONTROL_WORD',
                        'shift': 0,
                        'value': p.prov_icv_control_word(ret_value=True)
                    },
                ],
            },
            'wounding': {
                'size': 4,
                'data': [
                    {
                        'name': 'CAN_WOUND',
                        'shift': 0,
                        'mask': 0x01,
                        'value': p.wound_can(ret_value=True)
                    },
                    {
                        'name': 'FLASH_WOUND',
                        'shift': 1,
                        'mask': 0x03,
                        'value': p.wound_flash(ret_value=True)
                    },
                    {
                        'name': 'SRAM_WOUND',
                        'shift': 3,
                        'mask': 0x03,
                        'value': p.wound_sram(ret_value=True)
                    },
                    {
                        'name': 'TCPWM',
                        'shift': 5,
                        'mask': 0x03,
                        'value': p.wound_tcpwm(ret_value=True)
                    },
                    {
                        'name': 'PASS',
                        'shift': 7,
                        'mask': 0x01,
                        'value': p.wound_pass(ret_value=True)
                    },
                    {
                        'name': 'CORDIC',
                        'shift': 8,
                        'mask': 0x01,
                        'value': p.wound_cordic(ret_value=True)
                    },
                    {
                        'name': 'SRAM_REPAIRED',
                        'shift': 9,
                        'mask': 0x01,
                        'value': p.wound_sram_repaired(ret_value=True)
                    },
                    {
                        'name': 'SPEED_WOUND',
                        'shift': 10,
                        'mask': 0x01,
                        'value': p.wound_speed(ret_value=True)
                    }
                ]
            },
            'padding': {
                'size': 4,
                'data': [
                    {
                        'name': 'padding',
                        'shift': 0,
                        'value': bytes(8)
                    },
                ],
            }
        }
        return assets

    @staticmethod
    def _integrity_cert_data(cert_path):
        """Returns Device Integrity cert data
        @param cert_path: Path to the IFX Device Integrity cert
        @return: Device Integrity certificate data
        """
        try:
            with open(cert_path, encoding="utf-8") as f:
                cert_data = json.load(f)
            logger.debug("JSON cert used to create integrity_exam in_params "
                         "'%s'", cert_path)
            cert_hex_data = cert_data.get('certificate')
            cert = bytes.fromhex(cert_hex_data)
        except UnicodeDecodeError:
            with open(os.path.abspath(cert_path), 'rb') as fp:
                cert = fp.read()
            logger.debug("CBOR cert used to create integrity_exam in_params "
                         "'%s'", cert_path)
        return cert


def asset_item_data(p, asset_name, asset_item_name):
    """ Gets a tuple with the asset item size and mask """
    shift = None
    mask = None
    assets = AssetMapPsocC3.get(p)
    for item in assets[asset_name]['data']:
        if item['name'] == asset_item_name:
            shift = item['shift']
            mask = item['mask']
            break
    return shift, mask


def nonce(incremental_counter=None, initial_value=None):
    """Gets a value in the following format:
      - bits 0...31 - incremental counter
      - bits 32...63 - initial value
      - bits 64...127 - Unix timestamp
    Custom values are used for the incremental counter and initial value
    if specified. Otherwise, the random values are generated.
    """
    ic = incremental_counter or os.urandom(4)
    iv = initial_value or os.urandom(4)
    ts = unix_timestamp_bytes()
    return ic + iv + ts


def unix_timestamp_bytes():
    """Gets 64-bit Unix timestamp"""
    return int.to_bytes(int(time.time()), length=8, byteorder='big')

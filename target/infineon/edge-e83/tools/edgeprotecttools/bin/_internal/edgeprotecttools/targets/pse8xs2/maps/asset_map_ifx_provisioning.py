"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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
IFX_CHAIN_OF_TRUST_ID = 0x10010022


def ifx_provisioning_asset_map(parser):
    """Gets protected and unprotected parts of the IFX
    provisioning packet
    @param parser: Policy parser object
    @return: Unprotected data, protected data, list of IDs that have to
    be represented as a CBOR blob
    """
    unprotected = {
        'base_se_rt_services_hash': {
            'id': 0x1001001E,
            'value': parser.base_se_rt_services_hash()
        },
        'se_rt_services_hash': {
            'id': 0x1001001F,
            'value': parser.se_rt_services_hash()
        },
        'rram_se_boot_hash': {
            'id': 0x10010020,
            'value': parser.rram_se_boot_hash()
        }
    }
    protected = {
        'ifx_device_cert.value': {
            'id': 0x10010010,
            'value': parser.ifx_device_cert()
        },
        'ifx_se_rt_services_nv_counter.value': {
            'id': 0x10010001,
            'value': parser.ifx_se_rt_services_nv_counter()
        },
        'asset_hash.value': {
            'id': 0x10010003,
            'value': parser.asset_hash()
        },
        'basic_trims.value': {
            'id': 0x10010004,
            'value': parser.basic_trims()
        },
        'ram_app_nv_counter.value': {
            'id': 0x10010005,
            'value': parser.ram_app_nv_counter()
        },
        'ifx_policy.value': {
            'id': 0x10010006,
            'value': parser.ifx_policy()
        },
        'protected_nvm_lockable.value': {
            'id': 0x10010007,
            'value': parser.protected_nvm_lockable()
        },
        'oem_nv_counter.value': {
            'id': 0x10010008,
            'value': parser.oem_nv_counter()
        },
        'ifx_fw_integrity_key_01.value': {
            'id': 0x10010009,
            'value': parser.ifx_fw_integrity_key_01()
        },
        'ifx_oem_rot_master_key.value': {
            'id': 0x10010016,
            'value': parser.ifx_oem_rot_master_key()
        },
        'ifx_rma_master_key_01.value': {
            'id': 0x10010017,
            'value': parser.ifx_rma_master_key_01()
        },
        'ifx_revocation_key.value': {
            'id': 0x1001001B,
            'value': parser.ifx_revocation_key()
        },
        'die_id': {
            'id': 0x1001000B,
            'value': parser.die_id()
        },
        'device_id_to': {
            'id': 0x1001000C,
            'value': parser.device_id_to()
        },
        'factory_hash.value': {
            'id': 0x1001000D,
            'value': parser.factory_hash()
        },
        'full_trims.value': {
            'id': 0x1001000E,
            'value': parser.full_trims()
        },
        'ifx_fw_encryption_key_01.value': {
            'id': 0x1001000F,
            'value': parser.ifx_fw_encryption_key_01()
        },
        'toc1.value': {
            'id': 0x10010011,
            'value': parser.toc1()
        },
        'toc2.value': {
            'id': 0x10010012,
            'value': parser.toc2()
        },
        'rma_trial_counter.value': {
            'id': 0x10010013,
            'value': parser.rma_trial_counter()
        },
        'target_lcs.value': {
            'id': 0x10010014,
            'value': parser.target_lcs()
        },
        'device_rt_cfg_public.value': {
            'id': 0x1001001C,
            'value': parser.device_rt_cfg_public()
        },
        'boot_device_cfg.value': {
            'id': 0x1001001D,
            'value': parser.boot_device_cfg()
        },
        'ifx_rot_key_rev.value': {
            'id': 0x10010002,
            'value': parser.ifx_rot_key_rev()
        },
        'ifx_fw_integrity_key_rev.value': {
            'id': 0x1001001A,
            'value': parser.ifx_fw_integrity_key_rev()
        },
        'ifx_oem_rot_master_key_rev.value': {
            'id': 0x10010018,
            'value': parser.ifx_oem_rot_master_key_rev()
        },
        'ifx_rma_master_key_rev.value': {
            'id': 0x10010019,
            'value': parser.ifx_rma_master_key_rev()
        },
        'ifx_fw_encryption_key_rev.value': {
            'id': 0x10010015,
            'value': parser.ifx_fw_encryption_key_rev()
        },
        'device_id_mpn': {
            'id': 0x10010021,
            'value': parser.device_id_mpn()
        },
        'ifx_chain_of_trust.value': {
            'id': 0x10010022,
            'value': parser.ifx_chain_of_trust()
        },
        'disable_cert_validation': {
            'id': 0x10010023,
            'value': parser.disable_cert_validation()
        }
    }
    cbor_blobs = [IFX_CHAIN_OF_TRUST_ID]

    return unprotected, protected, cbor_blobs

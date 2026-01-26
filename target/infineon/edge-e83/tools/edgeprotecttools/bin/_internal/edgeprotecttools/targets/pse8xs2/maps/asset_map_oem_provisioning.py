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
from ...common.mxs22.enums import CoseSign1Packet


def oem_provisioning_asset_map(parser, **kwargs):
    """Gets protected and unprotected parts of the IFX
    provisioning packet
    @param parser: Policy parser object
    @param kwargs:
        :revoke: IFX key revocation certificate
    @return: Unprotected data, protected data, list of IDs that have to
    be represented as a CBOR blob
    """
    unprotected = {
        'extended_boot_image.value': {
            'id': 0x11010009,
            'value': parser.extended_boot_image()
        },
        'ifx_oem_cert.value': {
            'id': 0x11010007,
            'value': _read_cert(kwargs.get('ifx_oem_cert'))
        },
        'ifx_key_revocation': {
            'id': 0x11010005,
            'value': _read_cert(kwargs.get('revoke'))
        }
    }
    protected = {
        'user_certificate.value': {
            'id': CoseSign1Packet.USER_CERTIFICATE_ID,
            'value': parser.user_certificate()
        },
        'debug.cm33.cpu.value': {
            'id': CoseSign1Packet.CM33_AP_ID,
            'value': parser.debug_cm33_cpu(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.cm33.allowed.value': {
            'id': 0x21000002,
            'value': parser.debug_cm33_allowed(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.cm33.dbgen.value': {
            'id': 0x21000003,
            'value': parser.debug_cm33_dbgen(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.cm33.niden.value': {
            'id': 0x21000004,
            'value': parser.debug_cm33_niden(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.cm33.spiden.value': {
            'id': 0x21000005,
            'value': parser.debug_cm33_spiden(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.cm33.spniden.value': {
            'id': 0x21000006,
            'value': parser.debug_cm33_spniden(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.cm33.secure.value': {
            'id': 0x21000007,
            'value': parser.debug_cm33_secure(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.ap.value': {
            'id': CoseSign1Packet.SYS_AP_ID,
            'value': parser.debug_system_ap(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.allowed.value': {
            'id': 0x21020002,
            'value': parser.debug_system_allowed(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.mpc_ppc_enable.value': {
            'id': 0x21020003,
            'value': parser.debug_system_mpc_ppc_enable(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.rram_otp_enable.value': {
            'id': 0x21020004,
            'value': parser.debug_system_rram_otp_enable(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.rram_nvm_enable.value': {
            'id': 0x21020005,
            'value': parser.debug_system_rram_nvm_enable(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.ram_enable.value': {
            'id': 0x21020006,
            'value': parser.debug_system_ram_enable(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.mmio_enable.value': {
            'id': 0x21020007,
            'value': parser.debug_system_mmio_enable(ret_value=True),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.system.secure.value': {
            'id': 0x21020008,
            'value': parser.debug_system_secure(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.rma.permission.value': {
            'id': 0x21030001,
            'value': parser.debug_rma_permission(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'debug.debug_key.value': {
            'id': 0x21040001,
            'value': parser.debug_debug_key(),
            'parent': CoseSign1Packet.DEBUG_ID
        },
        'reprovisioning.debug.cm33': {
            'id': 0x20000001,
            'value': parser.reprovisioning_debug_cm33(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'reprovisioning.debug.system': {
            'id': 0x20000003,
            'value': parser.reprovisioning_debug_system(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'reprovisioning.debug.rma': {
            'id': 0x20000004,
            'value': parser.reprovisioning_debug_rma(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'reprovisioning.debug.debug_key': {
            'id': 0x20000005,
            'value': parser.reprovisioning_debug_debug_key(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'reprovisioning.extended_boot_policy': {
            'id': 0x20000006,
            'value': parser.reprovisioning_extended_boot_policy(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'reprovisioning.user_keys': {
            'id': 0x20000007,
            'value': parser.reprovisioning_user_keys(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'reprovisioning.user_certificate': {
            'id': 0x20000008,
            'value': parser.reprovisioning_user_certificate(),
            'parent': CoseSign1Packet.REPROVISIONING_ID
        },
        'user_keys.value': {
            'id': CoseSign1Packet.USER_KEYS_ID,
            'value': parser.user_keys(),
        },
        'extended_boot_policy.secure_boot.value': {
            'id': 0x40000000,
            'value': parser.extended_boot_policy_secure_boot(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.clock.value': {
            'id': 0x40000001,
            'value': parser.extended_boot_policy_clock(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.listen_window.value': {
            'id': 0x40000002,
            'value': parser.extended_boot_policy_listen_window(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.enable_alt_serial.value': {
            'id': 0x40000003,
            'value': parser.extended_boot_policy_enable_alt_serial(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.cm33_ram_app.enable.value': {
            'id': 0x40000004,
            'value': parser.extended_boot_policy_cm33_ram_app_enable(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.cm33_ram_app.address.value': {
            'id': 0x40000005,
            'value': parser.extended_boot_policy_cm33_ram_app_address(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.cm33_rram_app.address.value': {
            'id': 0x40000007,
            'value': parser.extended_boot_policy_cm33_rram_app_address(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.cm33_rram_app.size.value': {
            'id': 0x40000008,
            'value': parser.extended_boot_policy_cm33_rram_app_size(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.oem_app_address.value': {
            'id': 0x40000009,
            'value': parser.extended_boot_policy_oem_app_address(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.oem_alt_boot.value': {
            'id': 0x4000000A,
            'value': parser.extended_boot_policy_oem_alt_boot(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.oem_alt_app_start.value': {
            'id': 0x4000000B,
            'value': parser.extended_boot_policy_oem_alt_app_address(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.external_flash.smif_exflash.value': {
            'id': 0x4000000C,
            'value': parser.extended_boot_policy_external_flash_smif_exflash(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.external_flash.smif_chip_select.value': {
            'id': 0x4000000E,
            'value': parser.extended_boot_policy_external_flash_smif_chip_select(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.external_flash.smif_data_width.value': {
            'id': 0x4000000F,
            'value': parser.extended_boot_policy_external_flash_smif_data_width(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.external_flash.smif_data_select.value': {
            'id': 0x40000010,
            'value': parser.extended_boot_policy_external_flash_smif_data_select(),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'extended_boot_policy.external_flash.smif_mode.value': {
            'id': 0x40000011,
            'value': parser.extended_boot_policy_external_flash_smif_mode(ret_value=True),
            'parent': CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
        },
        'oem_key_revocation.value': {
            'id': 0x11010006,
            'value': parser.oem_key_revocation()
        },
        'boundary_scan.value': {
            'id': 0x1101000a,
            'value': parser.boundary_scan()
        }
    }
    cbor_blobs = [
        CoseSign1Packet.USER_CERTIFICATE_ID,
        CoseSign1Packet.USER_KEYS_ID,
        CoseSign1Packet.CM33_L1_BOOT_POLICY_ID
    ]

    return unprotected, protected, cbor_blobs


def _read_cert(cert):
    if cert:
        with open(cert, 'rb') as fp:
            return fp.read()
    return None

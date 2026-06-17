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
import json
import logging
import os.path

from .asset_map_ifx_provisioning import ifx_provisioning_asset_map
from .asset_map_oem_provisioning import oem_provisioning_asset_map
from .asset_map_entrance_exam import device_identity_asset_map
from ...common.mxs22.enums import DeviceIntegrity, CoseSign1Packet

logger = logging.getLogger(__name__)


class AssetMapPse8x:
    """Asset map for PSoC Edge E8x"""

    @staticmethod
    def get(parser, **kwargs):
        """Gets protected and unprotected parts of the CBOR packet.
        The items represent policy fields as a key-value pairs where
        the key is a field ID
        @param parser: Policy parser object
        @return: CBOR map ID, unprotected data, protected data
        """
        policy_type = kwargs.get('flow_name')
        if not policy_type:
            policy_type = parser.policy_type()
        if policy_type in (
                'prov_icv_provisioned', 'prov_icv_normal_provisioned',
                'device_identity', 'prov_icv_sort'
        ):
            cbor_map_id = CoseSign1Packet.IFX_PROV_PACKET
            unprotected, protected, cbor_blobs = ifx_provisioning_asset_map(
                parser)
        elif policy_type in ('prov_oem', 'prov_oem_L2', 'prov_oem_L4'):
            cbor_map_id = CoseSign1Packet.OEM_PROV_PACKET
            unprotected, protected, cbor_blobs = oem_provisioning_asset_map(
                parser, **kwargs)
        elif policy_type == 'device_integrity_exam':
            cert_path = kwargs.get('integrity_cert')
            cert_data = AssetMapPse8x._integrity_cert_data(cert_path)
            cbor_map_id = DeviceIntegrity.ENTR_EXAM_CMD
            unprotected, protected, cbor_blobs = device_identity_asset_map(
                ifx_integrity_cert=cert_data, **kwargs)
        else:
            raise ValueError(f"Invalid policy type '{policy_type}'")

        return cbor_map_id, unprotected, protected, cbor_blobs

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

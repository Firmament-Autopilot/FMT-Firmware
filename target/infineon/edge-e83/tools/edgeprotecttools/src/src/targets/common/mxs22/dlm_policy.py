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
import logging

from cbor import cbor

from .enums import CoseSign1Packet
from .oem_cert import OEMCert

logger = logging.getLogger(__name__)


class DLMPolicy:
    """Extracts configuration data from the DLM packet"""

    def __init__(self, dlm_params):
        """
        @param dlm_params: The provisioning_package data
        """
        self.dlm_params = dlm_params
        self.oem_packet = None
        self.policy = None
        self.oem_cert = None
        self._debug = None

        self.oem_packet = self.dlm_params.get(CoseSign1Packet.OEM_PROV_PACKET)
        if self.oem_packet:
            self.packet_type = CoseSign1Packet.OEM_PROV_PACKET
            packet_data = self.oem_packet.get(CoseSign1Packet.COSE_PACKET_ID)
            oem_cert = self.oem_packet.get(CoseSign1Packet.IFX_OEM_CERT)
            if packet_data:
                self.policy = self.load_policy(packet_data)
                self._debug = self.policy.get(CoseSign1Packet.DEBUG_ID)
            if oem_cert:
                self.oem_cert = OEMCert(oem_cert)

    @staticmethod
    def load_policy(packet_data):
        """DLM in_params from cbor to dictionary"""
        if packet_data:
            data = cbor.loads(packet_data)
            try:
                return cbor.loads(data.value[2])
            except Exception:  # pylint: disable=broad-except
                pass
        return None

    @property
    def debug_system_ap(self):
        """System AP configuration"""
        if self._debug:
            return self._debug.get(CoseSign1Packet.SYS_AP_ID)
        return None

    @property
    def debug_cm33_ap(self):
        """CM33 ap configuration"""
        if self._debug:
            return self._debug.get(CoseSign1Packet.CM33_AP_ID)
        return None

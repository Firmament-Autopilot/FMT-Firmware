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

logger = logging.getLogger(__name__)


class OEMCert:
    """A class representing the RAM application package"""

    def __init__(self, cert):
        """
        @param cert: The ifx-oem-cert data
        """
        self.cert = self.oem_cert(cert)

    @staticmethod
    def oem_cert(cert):
        """Load cert data from cbor"""
        data = cbor.loads(cert)
        try:
            return cbor.loads(data.value[2])
        except Exception:  # pylint: disable=broad-except
            return None

    @property
    def cert_type(self):
        """Certificate type"""
        cert_type = self.cert.get('TYPE')
        if not cert_type:
            cert_type = self.cert.get('certificate_type')
        return cert_type.upper() if cert_type else None

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

from .key_validator import KeyValidatorPsocC3
from ...core.certificate_strategy import CertificateStrategyV1

logger = logging.getLogger(__name__)


class CertificateStrategyPsocC3(CertificateStrategyV1):
    """Create certificates for PSoC C3 platform"""

    def __init__(self):
        super().__init__()
        self.key_validator = KeyValidatorPsocC3()

    def create_certificate(self, filename, encoding, overwrite, **kwargs):
        """Creates certificate in CBOR format"""
        private_key = kwargs.get('key')
        if private_key:
            self.key_validator.validate_private_key(private_key)

        dev_cert = kwargs.get('dev_cert').lower()
        if dev_cert == 'device_integrity':
            return self._device_integrity_cert(output=filename, **kwargs)
        raise ValueError(f"Invalid type of ifx certificate '{dev_cert}'")

    def create_csr(self, output, key_path, **kwargs):
        raise NotImplementedError("N/A for PSOC C3 platform")

    def default_certificate_data(self, tool, target, probe_id):
        raise NotImplementedError("N/A for PSOC C3 platform")

    def verify_certificate(self, cert_path, root_cert_path=None, key_path=None):
        raise NotImplementedError("N/A for PSOC C3 platform")

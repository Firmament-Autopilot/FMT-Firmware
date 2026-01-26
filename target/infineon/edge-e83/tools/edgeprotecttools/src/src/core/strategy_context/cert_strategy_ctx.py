"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from abc import ABC, abstractmethod


class CertificateStrategy(ABC):
    """
    The Strategy interface declares operations common to all supported versions
    of some algorithm.
    """
    @abstractmethod
    def create_certificate(self, filename, encoding, overwrite, **kwargs):
        """Create certificate"""

    @abstractmethod
    def create_csr(self, output, key_path, **kwargs):
        """Creates CSR"""

    @abstractmethod
    def default_certificate_data(self, tool, target, probe_id):
        """Adds default data to the certificate"""

    @abstractmethod
    def verify_certificate(self, cert_path, root_cert_path, key_path):
        """Verifies certificate"""


class CertificateContext:
    """
    The Context defines the interface of interest to clients.
    """
    def __init__(self, strategy: CertificateStrategy):
        self._strategy = strategy

    @property
    def strategy(self) -> CertificateStrategy:
        """
        The Context maintains a reference to one of the Strategy objects.
        """
        return self._strategy

    @strategy.setter
    def strategy(self, strategy: CertificateStrategy):
        """
        Allows replacing a Strategy object at runtime.
        """
        self._strategy = strategy

    def create_certificate(self, filename, encoding, overwrite, **kwargs):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.create_certificate(filename, encoding, overwrite,
                                                 **kwargs)

    def verify_certificate(self, cert_path, root_cert_path, key_path):
        """Verifies certificate"""
        return self._strategy.verify_certificate(
            cert_path, root_cert_path, key_path)

    def default_certificate_data(self, tool, target, probe_id):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.default_certificate_data(tool, target, probe_id)

    def create_csr(self, output, key_path, **kwargs):
        """
        Delegates work to the Strategy object.
        """
        return self._strategy.create_csr(output, key_path, **kwargs)

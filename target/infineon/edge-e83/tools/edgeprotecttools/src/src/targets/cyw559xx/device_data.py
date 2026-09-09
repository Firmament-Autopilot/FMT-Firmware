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
import os.path

from cryptography import x509
from cryptography.hazmat.primitives import serialization

from .silicon_data_reader_cyw559xx import SiliconDataReaderCYW559xx

logger = logging.getLogger(__name__)


class DeviceData:
    """Provides functionality to retrieve device data"""
    def __init__(self, tool):
        self.tool = tool

    def create_csr(self, csr_path, csr_id):
        """Creates CSR"""
        data_reader = SiliconDataReaderCYW559xx(self.tool)
        csr_data = data_reader.get_csr(int(csr_id, 0))
        if csr_data is None:
            logger.error('Unable to read CSR')
            return None
        if csr_data:
            self._print_command(
                csr_data.get('command_name'), csr_data.get('opcode'))
            payload = csr_data.get('payload')
            csr_fields = x509.load_der_x509_csr(payload)
            self._print_csr_subject(csr_fields.subject)
            self._print_public_key(csr_fields.public_key())

            if csr_path:
                abspath = self._save(payload, csr_path)
                logger.info("Created CSR: '%s'", abspath)
        return csr_data

    def read_soc_id(self, soc_id_path):
        """Read SOC ID"""
        data_reader = SiliconDataReaderCYW559xx(self.tool)
        soc_id = data_reader.read_soc_id()
        if soc_id is None:
            logger.error('Unable to read SOC ID')
            return None
        self._print_command(soc_id.get('command_name'), soc_id.get('opcode'))
        payload = soc_id.get('payload')
        logger.info('SOC ID: %s', payload.hex())
        if soc_id_path:
            abspath = self._save(payload, soc_id_path)
            logger.info("Created SOC ID info: '%s'", abspath)
        return soc_id

    @staticmethod
    def _print_csr_subject(subject):
        for itm in subject:
            logger.info('%s: %s', itm.rfc4514_attribute_name, itm.value)

    @staticmethod
    def _print_public_key(key):
        """Prints device public key"""
        logger.info('Public key: %s', key.public_bytes(
            encoding=serialization.Encoding.X962,
            format=serialization.PublicFormat.UncompressedPoint
        ).hex())

    @staticmethod
    def _print_command(command_name, opcode):
        """Print command info"""
        logger.info('Command: %s', command_name)
        logger.info('Opcode: %s', hex(opcode))

    @staticmethod
    def _save(payload, output):
        """Save data into a file"""
        abspath = os.path.abspath(output)
        with open(abspath, 'wb') as f:
            f.write(payload)
        return abspath

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

from .hci_response_parser import HCIResponseParser
from ...execute.programmer.hci_commands import OPCode

logger = logging.getLogger(__name__)


class SiliconDataReaderCYW559xx:
    """Implements reading data from CYW559xx device"""

    def __init__(self, tool):
        """Initializes the SiliconDataReaderCYW559xx instance"""
        self.tool = tool

    def get_csr(self, csr_id: int = 0):
        """Gets CSR data from device"""
        if not 0 <= csr_id < 3:
            logger.error('CSR ID out of range')
            return None

        id_value = bytes([csr_id])
        command = bytes.fromhex(OPCode.GET_CSR + '01') + id_value
        response = self.tool.hci_command(command, timeout=0.75)
        csr_data = HCIResponseParser()
        return csr_data.parse(response)

    def read_soc_id(self):
        """Reads device SOC ID"""
        command = bytes.fromhex(OPCode.READ_SOC_ID)
        response = self.tool.hci_command(command, timeout=0.25)
        csr_data = HCIResponseParser()
        return csr_data.parse(response)

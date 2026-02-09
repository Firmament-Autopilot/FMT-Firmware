"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from intelhex import IntelHex

logger = logging.getLogger(__name__)


def bin_dump(data, output):
    """Converts a hex string to bytes and saves to a binary file
    @param data: Hex string to dump
    @param output: Output file
    """
    if isinstance(data, bytes):
        binary_data = data
    else:
        binary_data = bytes.fromhex(data)

    with open(output, 'wb') as file:
        file.write(binary_data)


def hex_dump(image, address, size, output=None, padding=0) -> bytes:
    """Extracts data from the specified address
    @param image: Hex file path
    @param address: Data start address
    @param size: Data size
    @param output: Bin file path where to save the data
    @param padding: Padding value
    @return: Binary data
    """
    ih = IntelHex(image)
    ih.padding = padding

    if output:
        ih.tobinfile(output, start=address, size=size)

    return ih.tobinstr(start=address, size=size)

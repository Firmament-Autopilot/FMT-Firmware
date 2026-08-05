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
import os
import logging
import struct
from typing import Union

from intelhex import IntelHex

from ...execute.image_signing import MergeTool, SplitTool

logger = logging.getLogger(__name__)


class SignToolCYW559xx:
    """A class for signing CYW559xx images"""

    next_cert_size = 4
    cert_size_info = 4

    @staticmethod
    def sign(image, certs, output=None, **kwargs) -> Union[
        IntelHex, bytes, None]:
        """Signs firmware image by adding key and content
        certificates to it
        @param image: The image to sign
        @param certs: A list of certificates to add
        @param output: The output path
        @return: Image with added certificates
        """
        cons_cert_bytes = SignToolCYW559xx.consolidated_cert(certs)

        if kwargs.get('ota'):
            return SignToolCYW559xx._ota_patch(image, cons_cert_bytes, output)
        elif kwargs.get('ram'):
            return SignToolCYW559xx._ram_patch(image, cons_cert_bytes, output)
        else:
            return SignToolCYW559xx._flash_patch(image, cons_cert_bytes, output)

    @staticmethod
    def consolidated_cert(certs):
        """Consolidates certificates into a single bytes object
        @param certs: A list of certificates to consolidate
        @return: Consolidated certificates bytes
        """
        certs_size = 0
        cons_cert_bytes = b''

        for cert in certs:
            if not os.path.exists(cert):
                logger.error("Certificate '%s' not found", cert)
                return None
            with open(cert, 'rb') as file:
                cons_cert_bytes += file.read()
            cert_size = os.path.getsize(cert)
            certs_size += cert_size
            logger.debug("Processing certificate '%s'", cert)
            logger.debug("Certificate size: %d bytes", cert_size)

        header = struct.pack('<I', certs_size + SignToolCYW559xx.cert_size_info)
        cons_cert_bytes = (
                header +
                cons_cert_bytes +
                b'\x00' * SignToolCYW559xx.next_cert_size
        )

        logger.debug("Total certificates size: %d bytes (including size info)",
                     certs_size)
        return cons_cert_bytes


    @staticmethod
    def _ram_patch(image, cons_cert_bytes, output) -> IntelHex:
        """Patches the image for RAM
        @param image: The image to patch
        @param cons_cert_bytes: Consolidated certificates to add
        @param output: The output path
        @return: The patched image object
        """
        segments = SplitTool.split(image)
        consolidated_certs = IntelHex()
        consolidated_certs.frombytes(cons_cert_bytes)

        fw_cert_segment = segments[0]
        fw_cert_end_addr = (fw_cert_segment.maxaddr() -
                            SignToolCYW559xx.next_cert_size + 1)
        certificates = MergeTool.append_hex(fw_cert_segment, consolidated_certs,
                                            first_end_addr=fw_cert_end_addr)
        final = MergeTool.merge_hex([certificates] + segments[1:])
        final.write_hex_file(output)
        return final

    @staticmethod
    def _flash_patch(image, cons_cert_bytes, output) -> IntelHex:
        """Patches the image for flash
        @param image: The image to patch
        @param cons_cert_bytes: Consolidated certificates to add
        @param output: The output path
        @return: The patched image object
        """
        ih_image = IntelHex(image)
        image_end_addr = (ih_image.maxaddr() -
                          SignToolCYW559xx.next_cert_size + 1)
        consolidated_certs = IntelHex()
        consolidated_certs.frombytes(cons_cert_bytes)
        final = MergeTool.append_hex(image, consolidated_certs,
                                     first_end_addr=image_end_addr)
        final.write_hex_file(output)
        with open(output, 'r', encoding='utf-8') as file:
            final_lines = file.readlines()
        final_lines = final_lines[1:]
        with open(output, 'w', encoding='utf-8') as file:
            file.writelines(final_lines)
        return final

    @staticmethod
    def _ota_patch(image, cons_cert_bytes, output) -> bytes:
        """Patches the image for OTA
        @param image: The image to patch
        @param cons_cert_bytes: Consolidated certificates to add
        @param output: The output path
        @return: The patched image object
        """
        if isinstance(image, str):
            with open(image, 'rb') as file:
                image_bytes = file.read()
        elif isinstance(image, bytes):
            image_bytes = image
        else:
            raise TypeError(
                'Expected str or bytes, got %s' % type(image).__name__)

        image_bytes = (
                image_bytes[:-SignToolCYW559xx.cert_size_info] +
                cons_cert_bytes
        )

        if output:
            with open(output, 'wb') as file:
                file.write(image_bytes)

        return image_bytes

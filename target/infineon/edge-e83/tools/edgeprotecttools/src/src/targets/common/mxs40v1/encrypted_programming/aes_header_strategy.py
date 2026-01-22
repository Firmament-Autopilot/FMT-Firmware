"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from intelhex import IntelHex

from . import encrypted_programming
from .aes_header import AesHeader
from .aes_cipher import AESCipherCBC, read_key_from_file
from .....core.strategy_context import EncryptedProgrammingStrategy


logger = logging.getLogger(__name__)

FLASH_ROW_SIZE = 512
MAIN_FLASH_START_ADDR = 0x10000000


class AesHeaderStrategy(EncryptedProgrammingStrategy):
    @staticmethod
    def chunks_list(in_list, n):
        """
        Yield successive n-sized chunks from in_list.
        :param in_list: input list
        :param n: maximum size of each chunk
        :return: list of chunks
        """
        for i in range(0, len(in_list), n):
            yield in_list[i:i + n]

    @staticmethod
    def hex_str_wo_header(data):
        return "%02X" % data

    def create_header(self, host_key, dev_pub_key, key_to_encrypt, key_length):
        return AesHeader.create(host_key, dev_pub_key, key_to_encrypt,
                                key_length)

    def create_encrypted_image(self, hex_file, aes_key_file, aes_header,
                               host_key_id, dev_key_id, out_file_encrypt,
                               padding_value=0):
        """
        Creates encrypted image for encrypted programming
        Format:
        Row 1 - keys ID (byte 1 - host key ID, byte 2 - dev key ID)
        Row 2 - AES header
        Other - encrypted image data
        """
        # Write keys ID and AES header
        out_file_path = os.path.abspath(out_file_encrypt)
        with open(out_file_path, 'w', encoding='utf-8') as f:
            f.write(str(host_key_id).zfill(2))
            f.write(str(dev_key_id).zfill(2) + '\n')
            f.write(aes_header + '\n')

        ih = IntelHex(hex_file)
        hex_data_dict = ih.todict()
        if 'start_addr' in hex_data_dict:
            del hex_data_dict['start_addr']
        logger.debug('hex_data_dict=%s', hex_data_dict)

        # Add padding
        ih.padding = padding_value
        data_to_program = dict()
        file_len = ih.maxaddr() - ih.minaddr()
        if file_len % FLASH_ROW_SIZE != 0:
            address_offset = (file_len // FLASH_ROW_SIZE + 1) * FLASH_ROW_SIZE
            max_address = ih.minaddr() + address_offset
        else:
            max_address = ih.maxaddr()
        for i in range(ih.minaddr(), max_address):
            data_to_program[i] = ih[i]

        sorted_address_keys = sorted(data_to_program)
        for key in sorted_address_keys:
            logger.debug('0x%08X: %02X', key, data_to_program[key])

        logger.debug('Data bytes length: %d', len(sorted_address_keys))
        if len(sorted_address_keys) % FLASH_ROW_SIZE != 0:
            logger.error('Data bytes length is not multiple '
                         'by FLASH_ROW_SIZE (%d)', FLASH_ROW_SIZE)
            return

        sorted_bytes_values = []
        for key in sorted_address_keys:
            sorted_bytes_values.append(data_to_program[key])

        logger.debug('%s Virgin rows %s', '-' * 30, '-' * 30)
        address_row_bytes_dict = {}
        rows_of_bytes = list(AesHeaderStrategy.chunks_list(sorted_bytes_values,
                                                           FLASH_ROW_SIZE))
        flash_addresses = list(AesHeaderStrategy.chunks_list(
            sorted_address_keys, FLASH_ROW_SIZE))
        for i in range(len(flash_addresses)):
            flash_addresses[i] = flash_addresses[i][0]
            address_row_bytes_dict[flash_addresses[i]] = rows_of_bytes[i]
            out_data = '0x%08X %s' % (flash_addresses[i], ''.join(
                map(AesHeaderStrategy.hex_str_wo_header, rows_of_bytes[i])))
            logger.debug(out_data)

        logger.debug('%s Encrypted rows %s', '-' * 30, '-' * 30)
        addr_rows_bin = {}
        aes_key, aes_iv = read_key_from_file(aes_key_file)
        aes = AESCipherCBC(aes_key, aes_iv)
        with open(out_file_path, 'a', encoding='utf-8') as encrypted_rows_out:
            for i in range(len(flash_addresses)):
                rows_in_binary_format = bytes(rows_of_bytes[i])
                encrypted_row = aes.encrypt(rows_in_binary_format)
                encrypted_row = bytes(list(encrypted_row))

                addr_rows_bin[flash_addresses[i]] = encrypted_row
                out_data = '%08X%s' % (flash_addresses[i],
                                       addr_rows_bin[flash_addresses[i]].hex())
                logger.debug(out_data)
                encrypted_rows_out.write(out_data + '\n')
        logger.info("Created encrypted image '%s'", out_file_path)

    def program(self, tool, target, encrypted_image):
        return encrypted_programming.program(tool, target, encrypted_image)

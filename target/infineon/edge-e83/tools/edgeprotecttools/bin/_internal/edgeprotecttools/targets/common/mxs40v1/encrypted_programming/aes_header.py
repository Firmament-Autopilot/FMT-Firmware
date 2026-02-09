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
import copy
import logging

from .aes_cipher import AESCipherCBC, read_key_from_file
from .ecc_kdf import EcdhKdf

logger = logging.getLogger(__name__)

AES_HEADER_AES_KEYDATA_SIZE = 64


class AesHeader:
    @staticmethod
    def create(host_key, dev_pub_key, key_to_encrypt, key_length=16,
               salt=b'0000000000000000',
               info=b'0000000000000000'):
        """
        Generates encrypted header file.
        :param host_key: Host key pair file.
        :param dev_pub_key: Device public key.
        :param key_length: Derived key (AES) length.
        :param salt: Salt for KDF.
        :param info: Info data for KDF
        :param key_to_encrypt: AES key filename (key and iv are
               used for image encryption), should be AES encrypted,
               using derived key.
        """
        kdf_object = EcdhKdf(host_key, dev_pub_key, key_length, salt, info)
        aes_header = AesHeader._get_header_info(kdf_object, key_to_encrypt)
        aes_header_hex = aes_header.hex()
        logger.debug('aes_header=%s', aes_header_hex)

        return aes_header_hex

    @staticmethod
    def _get_header_info(kdf_object, key_to_encrypt_file):

        aes = AESCipherCBC(kdf_object.aes_key, kdf_object.iv)

        key_to_enc, iv_to_enc = read_key_from_file(key_to_encrypt_file)
        key_encrypted = aes.encrypt(key_to_enc + iv_to_enc)
        key_encrypted += bytearray([ord('0')] * (
                AES_HEADER_AES_KEYDATA_SIZE - (len(key_encrypted))))

        if kdf_object.salt is None or kdf_object.info is None:
            raise ValueError('Salt and info should be presented...')
        if len(kdf_object.salt) != 16 or len(kdf_object.info) != 16:
            raise ValueError('Salt and info fields length should be 16 bytes')

        aes_key_iv_padding = AesHeader._split_list_to_bytes(key_encrypted, 16)
        aes_key_iv_padding.append(copy.copy(list(kdf_object.salt)))
        aes_key_iv_padding.append(copy.copy(list(kdf_object.info)))

        for i in range(len(aes_key_iv_padding)):
            aes_key_iv_padding[i] = aes_key_iv_padding[i]

        logger.debug(
            'Key  (%2d): %s', len(key_encrypted), list(key_encrypted))
        logger.debug(
            'Salt (%2d): %s', len(kdf_object.salt), list(kdf_object.salt))
        logger.debug(
            'Info (%2d): %s', len(kdf_object.info), list(kdf_object.info))

        key_len = len(key_to_enc).to_bytes(1, 'little')
        aes_header = key_len + key_encrypted + kdf_object.salt + kdf_object.info

        return aes_header

    @staticmethod
    def _split_list_to_bytes(in_list, num_of_bytes_to_split):
        res_list = []
        cnt = 0
        tmp_list = []
        logger.debug(len(in_list))
        for i in range(len(in_list)):
            if cnt < num_of_bytes_to_split:
                tmp_list.append(in_list[i])
                cnt += 1
            else:
                res_list.append(copy.copy(tmp_list))
                tmp_list.clear()
                cnt = 1
                tmp_list.append(in_list[i])
        if len(tmp_list) > 0:
            res_list.append(tmp_list)
        return res_list

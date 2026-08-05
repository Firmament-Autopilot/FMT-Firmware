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
from .cert_enums import CertificateType


class CertificateHeader:
    """Class to generate Key or Content certificate header"""

    def __init__(self, config_parser, image_count=None):
        """Initializes the certificate header
        @param config_parser: Key or Content certificate config file parser
        """
        self.cert_type = config_parser.cert_type()
        self.cert_version = config_parser.cert_version()
        self.cert_keypair = config_parser.cert_keypair(ret_value=True)
        self.hbk_id = config_parser.hbk_id()

        if self.cert_type == CertificateType.KEY_CERT:
            self.image_count = 0
            self.cert_flags = self.get_cert_flags(0, 0, 0, 0)
        elif self.cert_type == CertificateType.CONTENT_CERT:
            if image_count is None:
                raise ValueError(
                    'Image count must be provided for Content certificate')
            self.image_count = image_count
            self.cert_flags = self.get_cert_flags(
                config_parser.encrypted(ret_value=True),
                config_parser.load_verify_scheme(ret_value=True),
                config_parser.crypto_type(ret_value=True),
                self.image_count)
        else:
            raise ValueError(f'Invalid certificate type {self.cert_type}')
        self.cert_size = self.get_cert_size()

    def header_bytes(self):
        """Gets the certificate header bytes"""
        return (self.cert_type.value.to_bytes(4, 'little') +
                self.get_cert_version().to_bytes(4, 'little') +
                self.cert_size.to_bytes(4, 'little') +
                self.cert_flags.to_bytes(4, 'little'))

    def get_cert_flags(self, is_encrypted, load_verify_scheme, crypto_type,
                       img_count):
        """Gets the certificate flags
        @param is_encrypted: Indicates whether the image is encrypted
        @param load_verify_scheme: SW load and verify scheme
        @param crypto_type: SW image cryptographic type
        @param img_count: Number of images in the certificate
        """
        code_encryption_support_bit_pos = 4
        load_verify_scheme_bit_pos = 8
        crypto_type_bit_pos = 12
        num_of_sw_comps_bit_pos = 16
        flag = self.hbk_id
        flag = flag | (is_encrypted << code_encryption_support_bit_pos)
        flag = flag | (load_verify_scheme << load_verify_scheme_bit_pos)
        flag = flag | (crypto_type << crypto_type_bit_pos)
        flag = flag | img_count << num_of_sw_comps_bit_pos
        return flag

    def get_cert_version(self):
        """Gets the certificate version"""
        major, minor = str(self.cert_version).split('.')
        major = int(major)
        minor = int(minor)
        cert_version = major << 16 | minor
        return cert_version

    def get_cert_size(self):
        """Gets the certificate size
        Calculate the offset to the signature (in words):
        Header size = 4 words
        RSA N = 96 words
        RSA Np = 5 words
        SW version = 1 word
        HASH of pubkey = HASH size
        Set the number of components (images) in the appropriate field
        """
        bytes_within_word = 4

        header_size_bytes = 4 * bytes_within_word
        header_size_words = header_size_bytes // bytes_within_word

        pubkey_size_bytes = self.cert_keypair.public_key().key_size // 8
        pubkey_size_words = pubkey_size_bytes // bytes_within_word

        np_size_bytes = 20
        np_size_words = np_size_bytes // bytes_within_word

        hash_size_bytes = 32
        hash_size_words = hash_size_bytes // bytes_within_word

        sw_version_obj_size_words = 1
        nonce_size_words = 2
        sw_rec_addr32_signed_data_size_words = 3

        cert_size = (header_size_words + sw_version_obj_size_words +
                     pubkey_size_words + np_size_words)

        if self.cert_type == CertificateType.KEY_CERT:
            cert_size += hash_size_words
        else:
            cert_size += nonce_size_words + self.image_count * (
                        hash_size_words + sw_rec_addr32_signed_data_size_words)
        return cert_size

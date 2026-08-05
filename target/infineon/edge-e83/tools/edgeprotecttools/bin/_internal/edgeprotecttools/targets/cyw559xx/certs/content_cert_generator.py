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
import hashlib
import os
import struct
from random import randrange

from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import padding

from .cert_header import CertificateHeader
from .content_cert_config_parser import ContentCertConfigParser
from .tbl_file import TblFile
from ....core.key_handlers.rsa_handler import RSAHandler
from ....execute.x509 import X509CertificateGenerator


class ContentCertificateGenerator:
    """Class to generate content certificates from a JSON configuration file"""

    def __init__(self, cert_config):
        self._generator = None
        self.certificate = None
        self.config_parser = ContentCertConfigParser(cert_config)
        self.tbl = TblFile(self.config_parser.image_table())
        self.cert_trailer = b''

    def generate(self):
        """Generates a key certificate"""
        header = CertificateHeader(self.config_parser,
                                   image_count=self.tbl.image_count)
        header_ext = header.header_bytes()
        pubkey_np_ext = self.pubkey_np_extension_data()
        cert_body_ext = self.cert_body_extension_data()
        signing_key = self.config_parser.cert_keypair(ret_value=True)
        if signing_key.key_size != 3072:
            raise ValueError('Signing key size must be 3072 bits')

        self._generator = X509CertificateGenerator(
            {
                "serial_number": "1000000000",
                "issuer": {
                    "common_name": "ARM",
                },
                "subject": {
                    "common_name": "CntCert"
                },
                "subject_public_key": signing_key.public_key(),
                "validity": {
                    "not_before": "",
                    "not_after": "2160-10-05T16:52:44"
                },
                "extensions": [
                    {
                        "name": "",
                        "oid": "2.20.2.1",
                        "critical": True,
                        "data_format": "hex",
                        "value": header_ext.hex()
                    },
                    {
                        "name": "",
                        "oid": "2.20.2.2",
                        "critical": True,
                        "data_format": "hex",
                        "value": pubkey_np_ext.hex()
                    },
                    {
                        "name": "",
                        "oid": "2.20.2.4",
                        "critical": True,
                        "data_format": "hex",
                        "value": cert_body_ext.hex()
                    }
                ]
            }
        )
        pss = padding.PSS(
            mgf=padding.MGF1(hashes.SHA256()),
            salt_length=hashes.SHA256().digest_size
        )
        certificate = self._generator.generate(signing_key, rsa_padding=pss)
        self.certificate = self.postprocess(certificate.tbs_certificate_bytes,
                                            signing_key)
        self.certificate += self.cert_trailer
        return self.certificate

    def postprocess(self, tbs_certificate_bytes, signing_key):
        """Post-processes the generated certificate.
        For successful certificate verification, it is necessary to remove
        NULL elements in the AlgorithmIdentifier sequences
        @param tbs_certificate_bytes: TBS certificate bytes
        @param signing_key: Private key used to sign the certificate
        @return: Content certificate bytes
        """
        gen_header_size = 82
        images_data_size = 0x2C * self.tbl.image_count
        sig_alg_bytes = bytes.fromhex(
            '303D06092A864886F70D01010A3030A00D300B0609608648016503040201A11'
            'A301806092A864886F70D010108300B0609608648016503040201A203020120'
        )

        no_image_cert_size = 0x0458
        cert_size = no_image_cert_size + images_data_size
        cert_size_bytes = bytes.fromhex('3082') + struct.pack('>H', cert_size)

        no_image_der_header_size = 0x0290
        der_header_size = no_image_der_header_size + images_data_size
        serial_number = randrange(0, 0x7FFFFFFF).to_bytes(4, byteorder='big')
        der_header_bytes = (
                bytes.fromhex('3082') +
                struct.pack('>H', der_header_size) +
                bytes.fromhex('A0030201020204') +
                serial_number +
                sig_alg_bytes
        )

        der_footer_bytes = sig_alg_bytes
        tbs_bytes = der_header_bytes + tbs_certificate_bytes[gen_header_size:]
        signature_size_bytes = bytes.fromhex('0382018100')

        signature_bytes = signing_key.sign(
            tbs_bytes,
            padding.PSS(
                mgf=padding.MGF1(hashes.SHA256()),
                salt_length=hashes.SHA256.digest_size
            ),
            hashes.SHA256()
        )
        return (cert_size_bytes + tbs_bytes + der_footer_bytes +
                signature_size_bytes + signature_bytes)

    def pubkey_np_extension_data(self):
        """Gets the RSA public key Np value"""
        key = self.config_parser.cert_keypair(ret_value=True)
        pubkey = key.public_key()
        np = RSAHandler.rsa_np(pubkey)
        return np.to_bytes(20, 'big')

    def cert_body_extension_data(self):
        """Gets the key certificate body"""
        is_encrypted = False
        image_data = []
        for img in self.tbl.images:
            img_hash_bytes = self.image_hash(img.image_path)
            load_addr_bytes = struct.pack('<I', img.load_addr)
            flash_addr = struct.pack('<I', img.flash_addr)
            img_max_size_bytes = struct.pack('<I', img.image_max_size)
            is_encrypted_bytes = struct.pack('<I', img.is_encrypted)
            if img.is_encrypted:
                is_encrypted = True
            image_data.append(img_hash_bytes + load_addr_bytes +
                              img_max_size_bytes + is_encrypted_bytes)
            self.cert_trailer += flash_addr + img_max_size_bytes
        nv_counter_bytes = struct.pack('<I', self.config_parser.nv_counter())
        nonce_bytes = os.urandom(8) if is_encrypted else bytes(8)
        return nv_counter_bytes + nonce_bytes + b''.join(image_data)

    @staticmethod
    def image_hash(image_path):
        """Gets the image hash
        @param image_path: Path to the image file
        @return: Image hash
        """
        with open(image_path, 'rb') as f:
            image = f.read()
        img_hash = hashlib.sha256()
        img_hash.update(image)
        return img_hash.digest()

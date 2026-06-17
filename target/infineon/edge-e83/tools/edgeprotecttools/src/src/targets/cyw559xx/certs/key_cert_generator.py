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
from random import randrange

from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import padding

from .cert_header import CertificateHeader
from .key_cert_config_parser import KeyCertConfigParser
from ....core.key_handlers.rsa_handler import RSAHandler
from ....execute.x509 import X509CertificateGenerator


class KeyCertificateGenerator:
    """Class to generate key certificates from a JSON configuration file"""

    def __init__(self, cert_config):
        self._generator = None
        self.certificate = None
        self.config_parser = KeyCertConfigParser(cert_config)

    def generate(self):
        """Generates a key certificate"""
        header = CertificateHeader(self.config_parser)
        header_ext = header.header_bytes()
        pubkey_np_ext = self.pubkey_np_extension_data()
        cert_body_ext = self.cert_body_extension_data()
        signing_key = self.config_parser.cert_keypair(ret_value=True)

        self._generator = X509CertificateGenerator(
            {
                "serial_number": "1000000000",
                "issuer": {
                    "common_name": "ARM"
                },
                "subject": {
                    "common_name": "KeyCert"
                },
                "subject_public_key": signing_key.public_key(),
                "validity": {
                    "not_before": "",
                    "not_after": "2160-09-21T21:48:50"
                },
                "extensions": [
                    {
                        "name": "",
                        "oid": "2.20.1.1",
                        "critical": True,
                        "data_format": "hex",
                        "value": header_ext.hex()
                    },
                    {
                        "name": "",
                        "oid": "2.20.1.2",
                        "critical": True,
                        "data_format": "hex",
                        "value": pubkey_np_ext.hex()
                    },
                    {
                        "name": "",
                        "oid": "2.20.1.3",
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
        return self.certificate

    @staticmethod
    def postprocess(tbs_certificate_bytes, signing_key):
        """Post-processes the generated certificate.
        For successful certificate verification, it is necessary to remove
        NULL elements in the AlgorithmIdentifier sequences
        @param tbs_certificate_bytes: TBS certificate bytes
        @param signing_key: Private key used to sign the certificate
        @return: Key certificate bytes
        """
        gen_header_size = 82
        sig_alg_bytes = bytes.fromhex(
            '303D06092A864886F70D01010A3030A00D300B0609608648016503040201A11A'
            '301806092A864886F70D010108300B0609608648016503040201A203020120')
        cert_size_bytes = bytes.fromhex('3082046E')
        signature_size_bytes = bytes.fromhex('0382018100')
        serial_number = randrange(0, 0x7FFFFFFF).to_bytes(4, byteorder='big')
        der_header_bytes = bytes.fromhex(
            '308202A6A0030201020204') + serial_number + sig_alg_bytes
        der_footer_bytes = sig_alg_bytes

        tbs_bytes = der_header_bytes + tbs_certificate_bytes[gen_header_size:]

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
        nv_counter = self.config_parser.nv_counter()
        pubkey = self.config_parser.next_cert_pubkey(ret_value=True)
        if pubkey.key_size != 3072:
            raise ValueError(
                'Next certificate public key size must be 3072 bits')
        n = pubkey.public_numbers().n.to_bytes(pubkey.key_size // 8, 'big')
        np = RSAHandler.rsa_np(pubkey).to_bytes(20, 'big')
        sha256_hash = hashlib.sha256()
        sha256_hash.update(n + np)
        digest = sha256_hash.digest()
        return nv_counter.to_bytes(4, byteorder='little') + digest

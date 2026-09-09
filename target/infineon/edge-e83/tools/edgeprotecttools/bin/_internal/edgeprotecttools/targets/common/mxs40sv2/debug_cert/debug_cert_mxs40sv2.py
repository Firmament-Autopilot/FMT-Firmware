"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.asymmetric import rsa

from .debug_cert_parser_mxs40sv2 import DebugCertificateParserMXS40Sv2
from .....core import key_handlers
from .....core.enums import ValidationStatus
from .....core.key_handlers.ec_handler import ECHandler
from .....core.key_handlers.rsa_handler import RSAHandler

logger = logging.getLogger(__name__)


class DebugCertificateMXS40Sv2:
    """Create: debug, transit to RMA certificates"""

    def __init__(self, template_validator=None):
        self.key = None
        self.template_validator = template_validator

    def create(self, template, key, output, sign, **_):
        """
        Creates debug or RMA certificate binary from the
        certificate in JSON format
        :param template:
            Path to the certificate template in JSON format
        :param key:
            This key will be used to add public key to the certificate.
            If "non_signed" option was not specified this key will be also
            used to sign the certificate
        :param output:
            The certificate binary output file
        :param sign:
            Indicates that debug certificate will be signed
        """
        cert_parser = DebugCertificateParserMXS40Sv2(template)

        if self.template_validator:
            self.template_validator.parser = cert_parser
            if self.template_validator.validate('debug') != ValidationStatus.OK:
                return None

        self.key = key_handlers.load_key(key)
        cert_fields = [
            'version',
            'device_id',
            'control_word',
            'die_id_min',
            'die_id_max',
            'public_key'
        ]
        json_cert = cert_parser.parse_template()
        json_cert = self.add_pub_key(json_cert, key)
        payload = b''.join([json_cert[field] for field in cert_fields])
        if sign:
            cert = self.sign_cert(payload)
        else:
            cert = payload
        if output:
            self.save_cert(output, cert)
        return cert

    def add_pub_key(self, json_cert, key_path):
        """Adds public to the certificate"""
        if isinstance(self.key, (rsa.RSAPrivateKey, rsa.RSAPublicKey)):
            key = RSAHandler.convert_to_mbedtls(key_path)
            json_cert['public_key'] = bytearray.fromhex(key)
        elif isinstance(self.key, (ec.EllipticCurvePrivateKey,
                                   ec.EllipticCurvePublicKey)):
            key = ECHandler.raw_format(self.key)
            json_cert['public_key'] = key + b'\x00\x00\x00'
        else:
            raise ValueError('Unsupported key type')
        return json_cert

    def sign_cert(self, payload):
        """Signs the certificate"""
        cert = payload
        if isinstance(self.key, rsa.RSAPrivateKey):
            signature = RSAHandler.sign(self.key, payload)
            cert = payload + signature
        elif isinstance(self.key, ec.EllipticCurvePrivateKey):
            signature = ECHandler.sign(self.key, payload)
            cert = payload + signature[0] + signature[1]
        return cert

    def add_signature(self, cert_file, signature_file, output):
        """Adds existing signature to the certificate.
        Applicable to CYW20829 only
        """
        with open(cert_file, 'rb') as f:
            payload = f.read()
        with open(signature_file, 'rb') as f:
            signature = f.read()
        signed_cert = payload + signature
        self.save_cert(output, signed_cert)
        logger.info('Debug certificate has been signed (%s)', output)
        return signed_cert

    @staticmethod
    def save_cert(path, cert):
        """Saves the certificate to a file"""
        with open(path, 'wb') as f:
            f.write(cert)

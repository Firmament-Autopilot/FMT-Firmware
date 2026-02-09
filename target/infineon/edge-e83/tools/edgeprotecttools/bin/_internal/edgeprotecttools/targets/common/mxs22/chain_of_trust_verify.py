"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
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

from cbor import cbor, Tag
from cwt import COSE, COSEKey, VerifyError

from . import CertificateStrategyMXS22
from ....core.key_handlers.ec_handler import ECHandler


logger = logging.getLogger(__name__)


class ChainOfTrust:
    """Verifies the chain of trust"""

    def __init__(self, certs_chain):
        self.certs_chain = certs_chain

    def verify(self):
        """Verifies the chain of trust and returns True if the chain is valid"""
        if not self.certs_chain:
            logger.error('Empty chain of trust')
            return False

        root_cert = self.certs_chain[0]
        verify_key = self.cert_pubkey(root_cert)
        for i, cert in enumerate(self.certs_chain):
            cert_tag = self.cose_decode(cert)
            cert_dict = self.cose_decode(cert_tag)
            cert_type = cert_dict.get('TEMPLATE_TYPE')

            if self.cose_verify(cert, verify_key):
                logger.info('Certificate %s: %s', i, cert_type or cert_dict)
                if cert != self.certs_chain[-1]:
                    verify_key = self.cert_pubkey(cert)
            else:
                logger.error('Certificate %s: %s', i, cert_type or cert_dict)
                return False
        return True

    def cert_pubkey(self, cert):
        """Returns the public key from the certificate"""
        cert_data = self.cose_decode(cert)
        cert_json = self.cose_decode(cert_data)

        pub_key_data = cert_json.get('PUBLIC_KEY_0')
        if not pub_key_data:
            logger.debug('PUBLIC_KEY_0 not found in the certificate')
            logger.debug('Getting DICE_DEVICE_ID_PUBLIC_KEY')
            pub_key_data = cert_json.get('DICE_DEVICE_ID_PUBLIC_KEY')

        return CertificateStrategyMXS22.populate_public_key(pub_key_data)

    @staticmethod
    def cose_verify(cose_packet, pub_key):
        """Verifies COSE data"""
        ctx = COSE.new()
        json_key = ECHandler.public_jwk(pub_key, None)
        cose_key = COSEKey.from_jwk(json_key)
        try:
            ctx.decode(cose_packet, cose_key)
            return True
        except VerifyError:
            return False

    @staticmethod
    def cose_decode(cose_packet):
        """Decodes COSE data"""
        try:
            if isinstance(cose_packet, Tag):
                return cbor.loads(cose_packet.value[2])
            return cbor.loads(cose_packet)
        except (ValueError, TypeError) as e:
            raise ValueError('Invalid COSE format') from e

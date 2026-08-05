"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from .debug_token_parser import DebugTokenParserPsocC3
from ...common.mxs40sv2.debug_cert.debug_cert_mxs40sv2 import (
    DebugCertificateMXS40Sv2)
from ....core import key_handlers
from ....core.enums import ValidationStatus


logger = logging.getLogger(__name__)


class DebugTokenPsocC3(DebugCertificateMXS40Sv2):
    """Create: debug, transit to RMA certificates"""

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
        token_parser = DebugTokenParserPsocC3(template)

        if self.template_validator:
            self.template_validator.parser = token_parser
            if self.template_validator.validate('debug') != ValidationStatus.OK:
                return None

        self.key = key_handlers.load_key(key)
        cert_fields = [
            'version',
            'silicon_id',
            'family_id',
            'si_revision_id',
            'control_word',
            'die_id_min',
            'die_id_max',
            'public_key'
        ]
        json_cert = token_parser.parse_template()
        json_cert = self.add_pub_key(json_cert, key)
        payload = b''.join([json_cert[field] for field in cert_fields])
        if sign:
            cert = self.sign_cert(payload)
        else:
            cert = payload
        if output:
            self.save_cert(output, cert)
        return cert


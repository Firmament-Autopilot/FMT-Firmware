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
import os

from .token_template_parser_mxs22 import TokenTemplateParserMXS22
from .token_validator import TokenJsonValidator
from .....core.cose import Cose
from .....core.enums import ValidationStatus
from .....core.key_handlers.ec_handler import ECHandler

logger = logging.getLogger(__name__)


class TokenMXS22:
    """Create: debug, transit to RMA and open RMA token"""

    def create(self, template, key, kid=None, output=None, **kwargs):
        """
        Creates signed custom binary or COSE token from the template
        @param template: Path to the token template in JSON format
        @param key: Private key to sign the token
        @param kid: Key ID
        @param output: The token binary output file
        """
        token_type = kwargs.get('token_type')
        cert_parser = TokenTemplateParserMXS22(template)
        json_validator = TokenJsonValidator(cert_parser)
        validation_status = json_validator.validate(token_type)
        if validation_status != ValidationStatus.OK:
            return False
        token_fields = cert_parser.parse_template(token_type)
        if token_type == 'revoke':
            token = Cose.cose_sign1(token_fields, key, kid=kid)
        else:
            payload = b''.join(v for v in token_fields.values())
            token = self.sign_token(payload, key) if key else payload
        if output:
            self.save_token(token, token_type, output)
        return token

    @staticmethod
    def save_token(cert, token_type, path):
        """Saves token to a file"""
        token_types = {
            'debug_token': 'Debug',
            'transit_to_rma': 'Transition to RMA',
            'open_rma': 'Open RMA',
            'revoke': 'Revoke'
        }
        dir_name = os.path.dirname(path)
        if dir_name:
            os.makedirs(dir_name, exist_ok=True)
        path = os.path.abspath(path)
        with open(path, 'wb') as f:
            f.write(cert)
        logger.info(
            '%s token created (%s)', token_types[token_type], path)

    @staticmethod
    def sign_token(token, priv_key):
        """Signs token with a private key"""
        r, s = ECHandler.sign(priv_key, token)
        return token + r + s

    def add_signature(self, token_file, signature_file, output, **kwargs):
        """Add signature to unsigned token"""
        token_type = kwargs.get('token_type')
        with open(token_file, 'rb') as f:
            payload = f.read()
        with open(signature_file, 'rb') as f:
            signature = f.read()
        signed_token = payload + signature
        self.save_token(signed_token, token_type, output)
        logger.info('Token has been signed (%s)', output)
        return signed_token

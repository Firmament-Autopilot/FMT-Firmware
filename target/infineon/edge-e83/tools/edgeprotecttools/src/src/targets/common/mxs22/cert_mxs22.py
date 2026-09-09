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

import jsonschema

from .cert_validator_mxs22 import CertTemplateValidatorMXS22
from .key_validator_mxs22 import KeyValidatorMXS22
from ....core.certificate_strategy.cert_v1 import CertificateStrategyV1

logger = logging.getLogger(__name__)


class CertificateStrategyMXS22(CertificateStrategyV1):
    """Create certificates for MXS22 platform"""

    def __init__(self):
        super().__init__()
        self.template_dir = os.path.join(
            os.path.dirname(__file__), 'base_cert_template')
        self.base_templates = [
            f for f in os.listdir(self.template_dir)
            if os.path.isfile(os.path.join(self.template_dir, f))
        ]
        self.key_validator = KeyValidatorMXS22()
        self.template_validator = CertTemplateValidatorMXS22()

    def validate_integrity_cert(self, template):
        """Validates integrity_exam certificate against JSON schema"""
        schema_path = os.path.join(
            os.path.dirname(__file__),
            'schemas', 'integrity_exam_cert_template.json_schema')
        schema = self.load_json(schema_path)
        try:
            jsonschema.validate(template, schema)
            logger.debug('Validation against schema succeed')
        except (jsonschema.exceptions.ValidationError,
                jsonschema.exceptions.SchemaError) as exc:
            logger.error('Validation against schema failed')
            logger.error(exc.message)
            logger.debug(exc)

    @staticmethod
    def _get_device_info_from_template(template):
        """Extracts device information from the template"""
        device_info = template.get('device', {})
        si = int(str(device_info.get('si', 0)), 0)
        family = int(str(device_info.get('family', 0)), 0)
        rev = int(str(device_info.get('rev', 0)), 0)
        return {
            'si': si.to_bytes(2, 'little'),
            'family': family.to_bytes(2, 'little'),
            'rev': rev.to_bytes(1, 'little')
        }

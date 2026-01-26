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

from ....core.certificate_strategy import CertificateTemplateValidatorV1

logger = logging.getLogger(__name__)


class CertTemplateValidatorMXS22(CertificateTemplateValidatorV1):
    """Validates cert template fields via the base certificate template"""
    def __init__(self):
        super().__init__()
        self.template_dir = os.path.join(
            os.path.dirname(__file__), 'base_cert_template'
        )
        self.base_templates = [
            f for f in os.listdir(self.template_dir)
            if os.path.isfile(os.path.join(self.template_dir, f))
        ]
        self.schemas_dir = os.path.join(os.path.dirname(__file__), 'schemas')
        self.cert_schemas = [
            f for f in os.listdir(self.schemas_dir)
            if os.path.isfile(os.path.join(self.schemas_dir, f))
        ]

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
from .content_cert_config_parser import ContentCertConfigParser
from .content_cert_generator import ContentCertificateGenerator
from .key_cert_config_parser import KeyCertConfigParser
from .key_cert_generator import KeyCertificateGenerator

def get_cert_config_parser(cert_type, config):
    """Factory method to create certificate parser object"""
    if cert_type == 'KEY_CERT':
        return KeyCertConfigParser(config)
    if cert_type == 'CONTENT_CERT':
        return ContentCertConfigParser(config)
    return None

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
import os

from .....core.json_validator import JsonValidator


class TokenJsonValidator(JsonValidator):
    """Json validator for Debug, RMA, Open RMA, IFX key revocation tokens"""
    schema_dir = os.path.join(os.path.dirname(__file__), 'schemas')

    schemas = {
        'debug_token': os.path.join(schema_dir, 'debug_token_schema.json'),
        'transit_to_rma': os.path.join(schema_dir, 'rma_token_schema.json'),
        'open_rma': os.path.join(schema_dir, 'open_rma_token_schema.json'),
        'revoke': os.path.join(schema_dir, 'ifx_key_revoke_token_schema.json')
    }

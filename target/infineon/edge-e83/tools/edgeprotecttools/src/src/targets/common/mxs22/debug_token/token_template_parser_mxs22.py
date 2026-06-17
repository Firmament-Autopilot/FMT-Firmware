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
import json
import struct
import logging

from ..asset_enums import (
    ApPermissionDebugToken, IfxKeyRevocation, ApPermissionOpenRMAToken)

logger = logging.getLogger(__name__)


class TokenTemplateParserMXS22:
    """Parse debug token, transition to RMA token, open RMA token"""

    def __init__(self, template_path):
        with open(template_path, 'r', encoding='utf-8') as f:
            self.template = json.loads(f.read())

    def field(self, *keys):
        """Gets a field from the policy as is"""
        value = self.template
        try:
            for key in keys:
                value = value[key]
        except KeyError:
            value = None
        return value

    def hex_field(self, *keys):
        """Gets a hex string field"""
        value = self.field(*keys)
        if value:
            value = int(value, 16)
        else:
            value = None
        return value

    def parse_template(self, token_type):
        """Parses token template"""
        if token_type == 'transit_to_rma':
            token = self.parse_rma_token()
        elif token_type == 'open_rma':
            token = self.parse_open_rma_token()
        elif token_type == 'debug_token':
            token = self.parse_debug_token()
        elif token_type == 'revoke':
            token = self.parse_revoke()
        else:
            raise ValueError(f"Invalid token type '{token_type}'")
        return token

    def parse_rma_token(self):
        """Generates RMA token"""
        token = {
            'version': self.parse_version(),
            'device_id': self.parse_device_id(),
            'silicon_id': self.parse_silicon_id(),
            'reserved': bytes(3),
            'die_id_min': self.parse_die_id('min'),
            'die_id_max': self.parse_die_id('max'),
            'num_of_sections': self.parse_sections_num()
        }
        return token

    def parse_open_rma_token(self):
        """Generates Open RMA token"""
        token = {
            'version': self.parse_version(),
            'device_id': self.parse_device_id(),
            'silicon_id': self.parse_silicon_id(),
            'reserved_3': bytes(3),
            'control_word': self.open_rma_token_control_word(),
            'reserved_4': bytes(4),
            'die_id_min': self.parse_die_id('min'),
            'die_id_max': self.parse_die_id('max')
        }
        return token

    def parse_debug_token(self):
        """Generates debug token"""
        token = {
            'version': self.parse_version(),
            'device_id': self.parse_device_id(),
            'silicon_id': self.parse_silicon_id(),
            'reserved_3': bytes(3),
            'control_word': self.debug_token_control_word(),
            'reserved_4': bytes(4),
            'die_id_min': self.parse_die_id('min'),
            'die_id_max': self.parse_die_id('max')
        }
        return token

    def parse_revoke(self):
        """Generates token word"""
        revoke = 0
        revoke_data = self.field('revoke')
        if not revoke_data:
            raise ValueError('Revoke data is not provided')
        for item, value in IfxKeyRevocation.items():
            if revoke_data.get(item):
                revoke |= value
        if revoke == 0:
            logger.warning('Revocation data has no significant value')
        return struct.pack('<L', revoke)

    def parse_version(self):
        """Parse version field"""
        version = [int(item) for item in self.field('version').split('.')]
        version = version[:4]
        version.reverse()
        return struct.pack('<BBBB', *version)

    def parse_device_id(self):
        """Parsing device_id consists of the family_id and si_revision_id"""
        family_id = self.hex_field('device_id', 'family_id')
        si_revision_id = self.hex_field('device_id', 'si_revision_id')
        return struct.pack('<HB', family_id, si_revision_id)

    def parse_silicon_id(self):
        """Parse silicon_id"""
        silicon_id = self.hex_field('silicon_id')
        return struct.pack('<H', silicon_id)

    def ctrl_word_permission_field(self, *args):
        """Get value of specified control_word field"""
        value = self.field('control_word', *args)
        return ApPermissionDebugToken[str(value)]

    def open_rma_token_ctrl_word_permission_field(self, *args):
        """Get value of specified control_word field"""
        value = self.field('control_word', *args)
        return ApPermissionOpenRMAToken[value]

    def ctrl_word_bool_field(self, *args):
        """Get boolean value of specified field"""
        return int(bool(self.field('control_word', *args)))

    def debug_token_control_word(self):
        """Generates control_word data for debug token"""
        sys_ap = self.ctrl_word_permission_field('system', 'ap').value
        cm33_0_ap = self.ctrl_word_permission_field('cm33_0', 'ap').value
        cm33_0_dbg = self.ctrl_word_bool_field('cm33_0', 'dbgen')
        cm33_0_nid = self.ctrl_word_bool_field('cm33_0', 'niden')
        cm33_0_spid = self.ctrl_word_bool_field('cm33_0', 'spiden')
        cm33_0_spnid = self.ctrl_word_bool_field('cm33_0', 'spniden')
        cm33_0_secure = self.ctrl_word_bool_field('cm33_0', 'secure')

        control_word_cm33 = (
                sys_ap << 14 |
                cm33_0_secure << 12 |
                cm33_0_spnid << 7 |
                cm33_0_spid << 6 |
                cm33_0_nid << 5 |
                cm33_0_dbg << 4 |
                sys_ap << 2 |
                cm33_0_ap
        )

        return struct.pack('<I', control_word_cm33)

    def open_rma_token_control_word(self):
        """Generates control_word data for open RMA token"""
        m0seccpuss = self.open_rma_token_ctrl_word_permission_field(
            'cm0p', 'm0seccpuss').value
        return struct.pack('<I', m0seccpuss)

    def parse_die_id(self, limit):
        """Parse die_id data from template"""
        lot = struct.pack('<L', self.field('die_id', limit, 'lot'))
        die_id = lot[:3]
        die_id += struct.pack('<BBBB',
                              self.field('die_id', limit, 'wafer'),
                              self.field('die_id', limit, 'xpos'),
                              self.field('die_id', limit, 'ypos'),
                              self.field('die_id', limit, 'sort')
                              )
        die_id += struct.pack('<BBB',
                              self.field('die_id', limit, 'day'),
                              self.field('die_id', limit, 'month'),
                              self.field('die_id', limit, 'year')
                              )
        return die_id

    def parse_sections_num(self):
        """Parse number of items that need to be destroyed
        in rram memory,they start address and size and
        create byte array for transit to RMA token
        """
        rram_sections = self.field('rram_sections')
        num_sections = struct.pack('<L', len(rram_sections))
        sections_data = b''

        for section in rram_sections:
            address = int(section['address'], 16)
            size = int(section['size'], 16)
            sections_data += struct.pack('<LL', address, size)

        return num_sections + sections_data

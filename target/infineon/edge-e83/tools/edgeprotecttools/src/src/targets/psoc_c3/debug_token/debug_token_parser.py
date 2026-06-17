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
import json
import struct


class DebugTokenParserPsocC3:
    """Implements PSoC C3 debug/RMA token parser"""

    def __init__(self, template_path):
        with open(template_path, 'r', encoding='utf-8') as f:
            self.template = json.loads(f.read())

    def parse_template(self):
        """Parses the loaded template"""
        json_cert = {
            'version': self.parse_version(),
            'silicon_id': self.parse_silicon_id(),
            'family_id': self.parse_family_id(),
            'si_revision_id': self.parse_si_revision_id(),
            'control_word': self.parse_control_word(),
            'die_id_min': self.parse_die_id('min'),
            'die_id_max': self.parse_die_id('max')
        }
        return json_cert

    def get_version(self):
        """Gets template version"""
        return self.template['version']

    def parse_version(self):
        """Parses template version"""
        version = [int(i) for i in self.template['version'].split('.')]
        version = version[:4]
        version.reverse()
        return struct.pack('<BBBB', *version)

    def parse_silicon_id(self):
        """Parses silicon ID value specified in the template"""
        silicon_id = int(self.template['silicon_id'], 16)
        return struct.pack('<H', silicon_id)

    def parse_family_id(self):
        """Parses family ID value specified in the template"""
        family_id = int(self.template['family_id'], 16)
        return struct.pack('<H', family_id)

    def parse_si_revision_id(self):
        """Parses silicon revision ID value specified in the template"""
        si_revision_id = int(self.template['si_revision_id'], 16)
        return struct.pack('<L', si_revision_id)

    def ctl_word_field(self, field):
        """Parses control word field value specified in the template"""
        return int(self.template['control_word'][field] == 'Enable')

    def parse_control_word(self):
        """Parses control word value specified in the template"""
        cm33_ap = self.ctl_word_field('cm33_ap')
        sys_ap = self.ctl_word_field('sys_ap')
        cm33_dbg = self.ctl_word_field('cm33_dbg')
        cm33_nid = self.ctl_word_field('cm33_nid')
        cm33_spid = self.ctl_word_field('cm33_spid')
        cm33_spnid = self.ctl_word_field('cm33_spnid')
        cm33_secure = self.ctl_word_field('cm33_secure')
        sys_secure = self.ctl_word_field('sys_secure')
        rma = self.ctl_word_field('rma')
        control_word = (rma << 31) | (sys_secure << 14) | \
                       (cm33_secure << 12) | (cm33_spnid << 7) | \
                       (cm33_spid << 6) | (cm33_nid << 5) | \
                       (cm33_dbg << 4) | (sys_ap << 2) | (cm33_ap << 0)
        return struct.pack('<I', control_word)

    def parse_die_id(self, limit):
        """Parses die ID value specified in the template"""
        lot = struct.pack('>L', self.template['die_id'][limit]['lot'])
        die_id = lot[1:4]
        die_id += struct.pack('<BBBBBBBBB',
                              self.template['die_id'][limit]['wafer'],
                              self.template['die_id'][limit]['xpos'],
                              self.template['die_id'][limit]['ypos'],
                              self.template['die_id'][limit]['sort'],
                              self.template['die_id'][limit]['minor'],
                              self.template['die_id'][limit]['day'],
                              self.template['die_id'][limit]['month'],
                              self.template['die_id'][limit]['year'],
                              0)
        return die_id

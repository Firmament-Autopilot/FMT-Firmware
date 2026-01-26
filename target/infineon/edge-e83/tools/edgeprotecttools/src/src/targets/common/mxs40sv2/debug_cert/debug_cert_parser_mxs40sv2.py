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
import json
import struct
from enum import Enum


class DebugCertificateParserMXS40Sv2:

    ControlWordBit = Enum(
        value='ControlWord',
        names=[
            ('Disable', 0),
            ('Enable', 1)
        ]
    )

    def __init__(self, template):
        self.template = self.load_template(template)

    def parse_template(self):
        json_cert = {
            'version': self.parse_version(),
            'device_id': self.parse_device_id(),
            'control_word': self.parse_control_word(),
            'die_id_min': self.parse_die_id('min'),
            'die_id_max': self.parse_die_id('max')
        }
        return json_cert

    def get_version(self):
        return self.template['version']

    def get_silicon_id(self):
        return self.template['device_id']['silicon_id']

    def get_family_id(self):
        return self.template['device_id']['family_id']

    def get_revision_id(self):
        return self.template['device_id']['revision_id']

    def get_cm33_ap_permission(self):
        try:
            value = self.template['control_word']['cm33_ap']
            return self.ControlWordBit[value]
        except KeyError:
            return self.ControlWordBit['Disable']

    def get_sys_ap_permission(self):
        try:
            value = self.template['control_word']['sys_ap']
            return self.ControlWordBit[value]
        except KeyError:
            return self.ControlWordBit['Disable']

    def get_rma_permission(self):
        try:
            value = self.template['control_word']['rma']
            return self.ControlWordBit[value]
        except KeyError:
            return self.ControlWordBit['Disable']

    def get_cm33_dbg_permission(self):
        try:
            value = self.template["control_word"]["cm33_dbg"]
            return self.ControlWordBit[value]
        except KeyError:
            return self.ControlWordBit['Disable']

    def get_cm33_nid_permission(self):
        try:
            value = self.template["control_word"]["cm33_nid"]
            return self.ControlWordBit[value]
        except KeyError:
            return self.ControlWordBit['Disable']

    @staticmethod
    def load_template(path):
        with open(path, 'r', encoding='utf-8') as f:
            template = json.loads(f.read())
        return template

    def parse_version(self):
        version = [int(i) for i in self.template['version'].split('.')]
        version = version[:4]
        version.reverse()
        return struct.pack('<BBBB', *version)

    def parse_device_id(self):
        silicon_id = int(self.template['device_id']['silicon_id'], 16)
        family_id = int(self.template['device_id']['family_id'], 16)
        revision_id = int(self.template['device_id']['revision_id'], 16)
        silicon_id = family_id << 16 | silicon_id
        return struct.pack('<LL', silicon_id, revision_id)

    def parse_control_word(self):
        cm33_ap = self.get_cm33_ap_permission().value
        sys_ap = self.get_sys_ap_permission().value
        rma = self.get_rma_permission().value
        cm33_dbg = self.get_cm33_dbg_permission().value
        cm33_nid = self.get_cm33_nid_permission().value
        control_word = (rma << 31) | (sys_ap << 2) | (cm33_ap << 0) | \
                       (cm33_dbg << 3) | (cm33_nid << 4)
        return struct.pack('<I', control_word)

    def parse_die_id(self, limit):
        die_id = struct.pack('<BBB',
                             self.template['die_id'][limit]['year'],
                             self.template['die_id'][limit]['month'],
                             self.template['die_id'][limit]['day'])

        lot = struct.pack('>L', self.template['die_id'][limit]['lot'])
        die_id += lot[1:4]

        die_id += struct.pack('<BBBB',
                              self.template['die_id'][limit]['wafer'],
                              self.template['die_id'][limit]['ypos'],
                              self.template['die_id'][limit]['xpos'],
                              self.template['die_id'][limit]['sort'])
        return die_id

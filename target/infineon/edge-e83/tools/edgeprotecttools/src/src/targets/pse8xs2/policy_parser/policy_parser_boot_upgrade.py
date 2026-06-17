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


class PolicyParserBootUpgrade:
    """Provides functionality for searching data in the policy file"""

    def __init__(self, json):
        """Provides access to the main policy parser class members"""
        self.json = json

    def boot_upgrade_bootloader_address(self):
        """Gets a value of boot_upgrade.bootloader.address property"""
        try:
            value = self.json['boot_upgrade']['bootloader']['address']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_bootloader_size(self):
        """Gets a value of boot_upgrade.bootloader.size property"""
        try:
            value = self.json['boot_upgrade']['bootloader']['size']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_bootloader_scratch_address(self):
        """Gets a value of boot_upgrade.bootloader.scratch_address property"""
        try:
            value = self.json['boot_upgrade']['bootloader']['scratch_address']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_bootloader_scratch_size(self):
        """Gets a value of boot_upgrade.bootloader.scratch_size property"""
        try:
            value = self.json['boot_upgrade']['bootloader']['scratch_size']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_address(self):
        """Gets a value of boot_upgrade.application_1.address property"""
        try:
            value = self.json['boot_upgrade']['application_1']['address']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_size(self):
        """Gets a value of boot_upgrade.application_1.size
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['size']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_upgrade_address(self):
        """Gets a value of boot_upgrade.application_1.upgrade_address property"""
        try:
            value = self.json['boot_upgrade']['application_1']['upgrade_address']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_upgrade_size(self):
        """Gets a value of boot_upgrade.application_1.upgrade_size
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['upgrade_size']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_status_address(self):
        """Gets a value of boot_upgrade.application_1.status_address
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['status_address']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_status_size(self):
        """Gets a value of boot_upgrade.application_1.status_size
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['status_size']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_upgrade_enable(self):
        """Gets a value of boot_upgrade.application_1.upgrade_enable
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['upgrade_enable']['value']
        except KeyError:
            value = True
        return value

    def boot_upgrade_application_1_authentication_key(self):
        """Gets a value of boot_upgrade.application_1.authentication_key
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['authentication_key']['value']
        except KeyError:
            value = None
        return value

    def boot_upgrade_application_1_encryption_enable(self):
        """Gets a value of boot_upgrade.application_1.encryption_enable
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['encryption_enable']['value']
        except KeyError:
            value = False
        return value

    def boot_upgrade_application_1_encryption_key(self):
        """Gets a value of boot_upgrade.application_1.encryption_key
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['encryption_key']['value']
        except KeyError:
            value = 1
        return value

    def boot_upgrade_application_1_security_counter(self):
        """Gets a value of boot_upgrade.application_1.security_counter
        property
        """
        try:
            value = self.json['boot_upgrade']['application_1']['security_counter']['value']
        except KeyError:
            value = 1
        return value

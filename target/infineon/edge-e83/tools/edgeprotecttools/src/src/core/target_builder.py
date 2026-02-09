"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from abc import ABC, abstractmethod


class TargetBuilder(ABC):
    """
    An abstract class necessary for implementation by
    concrete target builder classes
    """

    def __init__(self, target_name, rev=None):
        self._target_name = target_name
        self._rev = rev
        self._target_dir = None

    @property
    def target_name(self):
        """ Target name """
        return self._target_name

    @property
    def rev(self):
        """ Target revision """
        return self._rev

    @property
    def target_dir(self):
        """ Target files location """
        return self._target_dir

    @target_dir.setter
    def target_dir(self, target_dir):
        self._target_dir = target_dir

    @abstractmethod
    def get_ocds(self):
        """ Gets a list of supported On-Chip Debuggers """

    @abstractmethod
    def get_ocd_config(self):
        """ Gets a dictionary of On-Chip Debuggers configuration """

    @abstractmethod
    def get_default_policy(self):
        """ Gets default policy file """

    @abstractmethod
    def get_memory_map(self):
        """ Gets memory map object """

    @abstractmethod
    def get_register_map(self):
        """ Gets register map object """

    @abstractmethod
    def get_policy_parser(self, policy):
        """ Gets policy parser object """

    @abstractmethod
    def get_policy_validator(self, policy_parser, memory_map):
        """ Gets policy validator object """

    @abstractmethod
    def get_policy_filter(self, policy_parser):
        """ Gets policy filter object """

    @abstractmethod
    def get_provisioning_strategy(self):
        """ Gets an object containing provisioning implementation """

    @abstractmethod
    def get_provisioning_packet_strategy(self, policy_parser):
        """
        Gets an object containing implementation of
        provisioning packet generator
        """

    @abstractmethod
    def get_entrance_exam(self):
        """ Gets a class containing entrance exam implementation """

    @abstractmethod
    def get_voltage_tool(self):
        """
        Gets a class containing implementation of device
        voltage measurement
        """

    @abstractmethod
    def get_key_reader(self):
        """
        Gets a class containing implementation of reading
        crypto keys from a device
        """

    @abstractmethod
    def get_project_initializer(self):
        """
        Gets a class containing implementation of project creator
        """

    @abstractmethod
    def get_silicon_data_reader(self):
        """
        Gets a class containing implementation of device data reader
        """

    @abstractmethod
    def get_key_algorithms(self):
        """ Gets a list of supported crypto key algorithms """

    @abstractmethod
    def get_sign_tool(self):
        """ Gets a class containing image signing implementation """

    @abstractmethod
    def get_key_source(self, **kwargs):
        """ Gets an object containing key source implementation """

    @abstractmethod
    def get_bootloader_provider(self):
        """
        Gets a class containing implementation of bootloader
        data provider
        """

    @abstractmethod
    def get_version_provider(self):
        """
        Gets a class containing implementation of firmware
        version reader
        """

    @abstractmethod
    def get_debug_certificate(self):
        """
        Gets an object containing implementation of debug certificate
        generator
        """

    @abstractmethod
    def get_policy_generator(self, policy_parser):
        """
        Gets an object containing implementation of provisioning
        packet to policy generator
        """

    @abstractmethod
    def get_test_packages(self):
        """
        Gets a dictionary with Python packages containing content for
        testing purpose
        """

    @abstractmethod
    def get_certificate_strategy(self):
        """
        Gets an object containing implementation of certificate x509
        generator
        """

    @abstractmethod
    def get_app_loader(self):
        """
        Gets an object containing implementation of RAM application loading
        """

    @abstractmethod
    def get_silicon_id(self):
        """
        Gets the target silicon ID
        """

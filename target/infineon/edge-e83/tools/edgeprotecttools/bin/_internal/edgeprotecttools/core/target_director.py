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
import os
import inspect
from abc import ABCMeta
from collections import namedtuple

from .target_builder import TargetBuilder


class TargetDirector:
    """
    The Director is only responsible for executing the building steps
    in a particular sequence. It is helpful when producing products
    according to a specific order or configuration.
    """
    def __init__(self):
        self._builder = None
        self._target_dir = None

    @property
    def builder(self):
        return self._builder

    @builder.setter
    def builder(self, builder: TargetBuilder):
        """
        The Director works with any builder instance that the client
        code passes to it. This way, the client code may alter the
        final type of the newly assembled product.
        """
        self._builder = builder
        self._builder.target_dir = os.path.dirname(os.path.realpath(
            inspect.getfile(builder.__class__)))

    def get_target(self, policy, cwd):
        target = Target()

        # Target directory
        target.name = self._builder.target_name
        target.rev = self._builder.rev
        target.cwd = cwd
        target.target_dir = self._builder.target_dir

        target.ocds = self._builder.get_ocds()
        target.ocd_config = self._builder.get_ocd_config()

        # Memory map
        memory_map = self._builder.get_memory_map()
        target.memory_map = memory_map

        # Register map
        register_map = self._builder.get_register_map()
        target.register_map = register_map

        # Policy parser
        target.default_policy = self._builder.get_default_policy()
        if policy is None:
            target.policy = target.default_policy
            target.is_default_policy = target.policy is not None
        else:
            target.policy = policy
            target.is_default_policy = False
        policy_parser = self._builder.get_policy_parser(target.policy)
        target.policy_parser = policy_parser

        # Policy validator
        policy_validator = self._builder.get_policy_validator(policy_parser,
                                                              memory_map)
        target.policy_validator = policy_validator

        # Policy filter
        policy_filter = self._builder.get_policy_filter(policy_parser)
        target.policy_filter = policy_filter

        # Provisioning strategy
        target.provisioning_strategy = \
            self._builder.get_provisioning_strategy()

        # Provisioning packet strategy
        target.provisioning_packet_strategy = \
            self._builder.get_provisioning_packet_strategy(policy_parser)

        # Entrance exam
        target.entrance_exam = self._builder.get_entrance_exam()

        # Voltage tool
        target.voltage_tool = self._builder.get_voltage_tool()

        # Key reader
        target.key_reader = self._builder.get_key_reader()

        # Project initializer
        target.project_initializer = self._builder.get_project_initializer()

        # Silicon data reader
        target.silicon_data_reader = self._builder.get_silicon_data_reader()

        # Key algorithms
        target.key_algorithms = self._builder.get_key_algorithms()

        # Sign tool
        target.sign_tool = self._builder.get_sign_tool()

        # Key source
        target.key_source = self._builder.get_key_source(
            policy_parser=policy_parser)

        # Bootloader provider
        target.bootloader_provider = self._builder.get_bootloader_provider()

        # Version provider
        target.version_provider = self._builder.get_version_provider()

        # Debug certificate
        target.debug_certificate = self._builder.get_debug_certificate()

        # Policy generator
        target.policy_generator = self._builder.get_policy_generator(
            policy_parser)

        # Python package name containing content for testing purpose
        target.test_packages = self._builder.get_test_packages()

        # Certificate strategy
        target.certificate_strategy = self._builder.get_certificate_strategy()

        # Application loader
        target.app_loader = self._builder.get_app_loader()

        # Target silicon ID
        target.silicon_id = self._builder.get_silicon_id()

        self._instantiate_types(target)

        return target

    @staticmethod
    def _instantiate_types(target):
        """
        Instantiates properties of a class type.
        Some target parts use the target as an input parameter
        and must be instantiated when the target contains all parts
        """
        TypeObject = namedtuple('TypeObject', ['type', 'name'])
        for t in [TypeObject(getattr(target, m), m) for m in dir(target) if
                  not m.startswith('_')]:
            if isinstance(t.type, ABCMeta) or isinstance(t.type, type):
                setattr(target, t.name, t.type(target))


class Target:
    def __init__(self):
        self._name = None
        self._rev = None
        self._policy = None
        self._default_policy = None
        self._ocds = None
        self._ocd_config = None
        self._is_default_policy = None
        self._memory_map = None
        self._register_map = None
        self._policy_validator = None
        self._policy_parser = None
        self._policy_filter = None
        self._target_dir = None
        self._provisioning_strategy = None
        self._provisioning_packet_strategy = None
        self._entrance_exam = None
        self._voltage_tool = None
        self._key_reader = None
        self._project_initializer = None
        self._cwd = None
        self._silicon_data_reader = None
        self._key_algorithms = None
        self._sign_tool = None
        self._key_source = None
        self._bootloader_provider = None
        self._version_provider = None
        self._debug_certificate = None
        self._policy_generator = None
        self._test_packages = None
        self._certificate_strategy = None
        self._app_loader = None
        self._silicon_id = None
        self._context = {}

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, name):
        self._name = name

    @property
    def rev(self):
        return self._rev

    @rev.setter
    def rev(self, rev):
        self._rev = rev

    @property
    def policy(self):
        return self._policy

    @policy.setter
    def policy(self, policy):
        self._policy = policy

    @property
    def default_policy(self):
        return self._default_policy

    @default_policy.setter
    def default_policy(self, policy):
        self._default_policy = policy

    @property
    def ocds(self):
        return self._ocds

    @ocds.setter
    def ocds(self, ocds):
        self._ocds = ocds

    @property
    def ocd_config(self):
        return self._ocd_config

    @ocd_config.setter
    def ocd_config(self, ocd_config):
        self._ocd_config = ocd_config

    @property
    def is_default_policy(self):
        return self._is_default_policy

    @is_default_policy.setter
    def is_default_policy(self, value):
        self._is_default_policy = value

    @property
    def memory_map(self):
        return self._memory_map

    @memory_map.setter
    def memory_map(self, memory_map):
        self._memory_map = memory_map

    @property
    def register_map(self):
        return self._register_map

    @register_map.setter
    def register_map(self, register_map):
        self._register_map = register_map

    @property
    def policy_parser(self):
        return self._policy_parser

    @policy_parser.setter
    def policy_parser(self, policy_parser):
        self._policy_parser = policy_parser

    @property
    def policy_validator(self):
        return self._policy_validator

    @policy_validator.setter
    def policy_validator(self, policy_validator):
        self._policy_validator = policy_validator

    @property
    def policy_filter(self):
        return self._policy_filter

    @policy_filter.setter
    def policy_filter(self, policy_filter):
        self._policy_filter = policy_filter

    @property
    def target_dir(self):
        return self._target_dir

    @target_dir.setter
    def target_dir(self, target_dir):
        self._target_dir = target_dir

    @property
    def provisioning_strategy(self):
        return self._provisioning_strategy

    @provisioning_strategy.setter
    def provisioning_strategy(self, strategy):
        self._provisioning_strategy = strategy

    @property
    def provisioning_packet_strategy(self):
        return self._provisioning_packet_strategy

    @provisioning_packet_strategy.setter
    def provisioning_packet_strategy(self, strategy):
        self._provisioning_packet_strategy = strategy

    @property
    def entrance_exam(self):
        return self._entrance_exam

    @entrance_exam.setter
    def entrance_exam(self, obj_type):
        self._entrance_exam = obj_type

    @property
    def voltage_tool(self):
        return self._voltage_tool

    @voltage_tool.setter
    def voltage_tool(self, tool_type):
        self._voltage_tool = tool_type

    @property
    def key_reader(self):
        return self._key_reader

    @key_reader.setter
    def key_reader(self, reader_type):
        self._key_reader = reader_type

    @property
    def project_initializer(self):
        return self._project_initializer

    @project_initializer.setter
    def project_initializer(self, initializer_type):
        self._project_initializer = initializer_type

    @property
    def cwd(self):
        return self._cwd

    @cwd.setter
    def cwd(self, cwd):
        self._cwd = cwd

    @property
    def silicon_data_reader(self):
        return self._silicon_data_reader

    @silicon_data_reader.setter
    def silicon_data_reader(self, reader):
        self._silicon_data_reader = reader

    @property
    def key_algorithms(self):
        return self._key_algorithms

    @key_algorithms.setter
    def key_algorithms(self, algorithms):
        self._key_algorithms = algorithms

    @property
    def sign_tool(self):
        return self._sign_tool

    @sign_tool.setter
    def sign_tool(self, tool):
        self._sign_tool = tool

    @property
    def key_source(self):
        return self._key_source

    @key_source.setter
    def key_source(self, source):
        self._key_source = source

    @property
    def bootloader_provider(self):
        return self._bootloader_provider

    @bootloader_provider.setter
    def bootloader_provider(self, provider):
        self._bootloader_provider = provider

    @property
    def version_provider(self):
        return self._version_provider

    @version_provider.setter
    def version_provider(self, provider):
        self._version_provider = provider

    @property
    def debug_certificate(self):
        return self._debug_certificate

    @debug_certificate.setter
    def debug_certificate(self, debug_certificate):
        self._debug_certificate = debug_certificate

    @property
    def policy_generator(self):
        return self._policy_generator

    @policy_generator.setter
    def policy_generator(self, policy_generator):
        self._policy_generator = policy_generator

    @property
    def test_packages(self):
        return self._test_packages

    @test_packages.setter
    def test_packages(self, packages):
        self._test_packages = packages

    @property
    def certificate_strategy(self):
        return self._certificate_strategy

    @certificate_strategy.setter
    def certificate_strategy(self, certificate_strategy):
        self._certificate_strategy = certificate_strategy

    @property
    def app_loader(self):
        return self._app_loader

    @app_loader.setter
    def app_loader(self, app_loader):
        self._app_loader = app_loader

    @property
    def silicon_id(self):
        return self._silicon_id

    @silicon_id.setter
    def silicon_id(self, silicon_id):
        self._silicon_id = silicon_id

    @property
    def context(self):
        return self._context

    @context.setter
    def context(self, context):
        self._context = context

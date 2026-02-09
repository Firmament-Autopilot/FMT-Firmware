"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import posixpath
import json
import logging

from ....core import jsonpath
from ....core.project_base import ProjectInitializerBase

logger = logging.getLogger(__name__)


# The sufficient list of files to initialize the
# project. The policy directory is copied entirely
project_files = {
    'packets': {
        'control_dap_cert.json',
        'ec_key_tmpl.json',
        'cy_auth_1m_b0_sample.jwt',
        'cy_auth_2m_b0_sample.jwt',
        'cy_auth_2m_s0_sample.jwt',
        'cy_auth_512k_b0_sample.jwt',
        'entrance_exam.jwt',
    },
    'keys': {
        'cy_pub_key.json',
        'hsm_state.json',
        'oem_state.json'
    }
}


class ProjectInitializerMXS40V1(ProjectInitializerBase):
    """Project creation implementation for the MXS40v1 platform"""

    def __init__(self, target):
        super().__init__(target)
        self.common_prebuilt_dir_name = '../common/mxs40v1/prebuilt'
        self.default_policy_file_name = os.path.basename(os.path.normpath(
            target.policy))
        self.common_keys_src = os.path.abspath(os.path.join(
            self.target_dir, self.common_prebuilt_dir_name))
        self.target_keys_src = os.path.abspath(os.path.join(
            self.target_dir, self.keys_dirname))
        self.prebuilt_src = os.path.join(
            self.target_dir, self.prebuilt_dirname)

    @property
    def _packets_src(self):
        packets_dir_name = os.path.basename(os.path.normpath(
            self.policy_parser.get_provisioning_packet_dir()))
        return os.path.join(self.target_dir, packets_dir_name)

    def init(self, cwd=None, overwrite=None):
        """
        Initializes new project
        :param cwd: Current working directory
        :param overwrite: Indicates whether to overwrite project files
               if already exist. If the value is None, an interactive prompt
               will ask whether to overwrite existing files
        """
        if cwd:
            self.cwd = cwd
        exist = []

        keys_dst = os.path.join(self.cwd, self.keys_dirname)
        packets_dst = os.path.join(self.cwd, os.path.basename(
            os.path.normpath(self._packets_src)))

        if overwrite is None:
            # Check packets existence
            exist.extend(self.get_existent(
                packets_dst, project_files['packets']))

            # Check policies existence
            policy_dst = os.path.join(self.cwd, self.policy_dirname)
            files = self.get_policy_src_files(self.policy_src)
            exist.extend(self.get_existent(policy_dst, files))

            # Check prebuilt existence
            src_files = self.get_prebuilt_files(self.prebuilt_src)
            prebuilt_dst = os.path.join(self.cwd, self.prebuilt_dirname)
            dst_files = self.get_prebuilt_files(prebuilt_dst)
            try:
                for item in dst_files:
                    if item in src_files:
                        exist.extend([os.path.join(prebuilt_dst, item)])
            except FileNotFoundError:
                pass

            # Check keys existence
            exist.extend(self.get_existent(keys_dst, project_files['keys']))

            # Create a project
            if exist:
                for file in exist:
                    print(file)
                answer = input(f'{len(exist)} files exist and will be '
                               f'overwritten. Continue? (y/n): ')
                if answer.strip() == 'y':
                    self.create_project(packets_dst, keys_dst)
                else:
                    logger.info('Skip project creation')
            else:
                self.create_project(packets_dst, keys_dst)
        elif overwrite is True:
            self.create_project(packets_dst, keys_dst)
        else:
            logger.info('Skip project creation')

    def create_project(self, packets_dst, keys_dst):
        """
        Creates project in cwd
        :param packets_dst: Packets destination directory
        :param keys_dst: Keys destination directory
        """
        self.copy_files(self._packets_src, packets_dst,
                        project_files['packets'], warn=False)
        self.copy_files(self.common_keys_src, keys_dst, project_files['keys'],
                        warn=False)
        self.copy_files(self.target_keys_src, keys_dst, project_files['keys'],
                        warn=False)
        self.copy_policies()
        self.copy_prebuilt()
        self.update_policies()
        self.create_config_file()

    @staticmethod
    def get_prebuilt_files(directory):
        """
        Gets names of the prebuilt files in the specified directory
        """
        files = [os.path.join(dp, f) for dp, dn, fn in
                 os.walk(directory) for f in fn
                 if f.endswith('hex') or f.endswith('jwt')]

        files = [os.path.relpath(f, directory) for f in files]
        return files

    def copy_policies(self):
        """
        Copies policy files from the package directory to the
        project directory
        """
        src = self.policy_src
        dst = os.path.join(self.cwd, self.policy_dirname)
        files = self.get_policy_src_files(self.policy_src)
        self.copy_files(src, dst, files)

    def copy_prebuilt(self):
        """
        Copies prebuilt files from the package directory to the
        project directory
        """
        src = self.prebuilt_src
        dst = os.path.join(self.cwd, self.prebuilt_dirname)
        files = self.get_prebuilt_files(src)
        self.copy_files(src, dst, files)

    def create_config_file(self):
        """Creates a project configuration file"""
        rel_path = os.path.relpath(self.target.default_policy, self.target_dir)
        self.create_config(os.path.relpath(rel_path))

    def update_policies(self):
        """
        Updates paths pointing to the package to the paths
        pointing to the project in policy destination files.
        """
        policy_files = self.get_policy_src_files(self.policy_src)
        for policy in policy_files:
            policy_path = os.path.join(self.cwd, self.policy_dirname, policy)
            with open(policy_path, encoding='utf-8') as f:
                json_str = f.read()
                policy = json.loads(json_str)

            self._update_bootloader_keys_section(policy)
            self._update_pre_build_section(policy)

            with open(policy_path, 'w', encoding='utf-8') as f:
                json.dump(policy, f, indent=4)

    def _update_pre_build_section(self, policy):
        update_nodes = ['oem_public_key', 'oem_private_key', 'hsm_public_key',
                        'hsm_private_key']
        for k, v in policy['pre_build'].items():
            if k in update_nodes:
                filename = os.path.basename(os.path.normpath(v))
                new_path = posixpath.join('../', self.keys_dirname, filename)
                policy['pre_build'][k] = new_path

    def _update_bootloader_keys_section(self, policy):
        path = 'boot_upgrade.firmware.0.bootloader_keys.0.key'
        old_value = jsonpath.get_node_value(policy, path)
        filename = os.path.basename(os.path.normpath(old_value))
        new_value = posixpath.join('../', self.keys_dirname, filename)
        jsonpath.set_node_value(policy, path, new_value)

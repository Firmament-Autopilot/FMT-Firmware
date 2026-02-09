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
import logging

from packaging import version

from .image_cert import ImageCertificate
from ....core.project_base import ProjectInitializerBase
from ....execute.silicon_data_reader import si_rev_name
from ....core.version_provider import VersionProvider
from ....pkg_globals import PkgData

logger = logging.getLogger(__name__)


class VersionProviderMXS40v1(VersionProvider):
    """
    Helper class that encapsulates the routine for getting a version
    of different parts of the package
    """

    CST_2_1_0_SFB_VER = '4.0.1.1267'

    def package_bootloader_version(self):
        """
        Gets a bootloader version bundled with the package
        :return: Version of the cybootloader bundled with the package
        """
        jwt_path = self.target.bootloader_provider.jwt_path(
            build_mode='release', from_project=False)

        ver = 'unknown'
        if not os.path.isfile(jwt_path):
            logger.error('File %s not found', jwt_path)
        else:
            try:
                ver = ImageCertificate.get_version(jwt_path)
                logger.debug('Package bootloader version: %s', ver)
            except KeyError as e:
                logger.error("Cannot find field '%s' in '%s'", e, jwt_path)
        return ver

    def project_bootloader_version(self):
        """
        Gets a bootloader version in the project dir
        :return: Version of the cybootloader from the project if it was
                 initialized, otherwise None
        """
        jwt_path = self.target.bootloader_provider.jwt_path(
            build_mode='release', from_project=True)

        if ProjectInitializerBase.is_project():
            ver = 'unknown'
            if not os.path.isfile(jwt_path):
                logger.error('File %s not found', jwt_path)
            else:
                try:
                    ver = ImageCertificate.get_version(jwt_path)
                    logger.debug('Project bootloader version: %s', ver)
                except KeyError as e:
                    logger.error("Cannot find field '%s' in '%s'", e, jwt_path)
        else:
            ver = None
        return ver

    def device_sfb_version(self, tool):
        """
        Reads Secure Flash Boot version from device
        """
        return self.target.entrance_exam.read_sfb_version(tool)

    def device_bootloader_version(self, tool):
        """
        Reads CyBootloader version from device
        """
        bootloader_version = 'unknown'
        cert = ImageCertificate.read_image_certificate(tool, self.target)
        if cert:
            try:
                bootloader_version = ImageCertificate.get_version(cert)
            except KeyError:
                pass
        return bootloader_version

    def print_fw_version(self, tool):
        """
        Prints Secure Flash Boot and CyBootloader versions from the device
        """
        bootloader_ver = self.device_bootloader_version(tool)
        sfb_ver = self.device_sfb_version(tool)
        print('\tDevice:')
        print(f'\t\tCyBootloader: {bootloader_ver}')
        print(f'\t\tSecure Flash Boot: {sfb_ver}')

    def print_version(self,  **_):
        """
        Prints the package version and CyBootloader version bundled with
        the package for the specified targets. Find installation source
        and build version information in verbose mode [-v] [--verbose]
        """
        package_ver = self.package_bootloader_version()
        print(f'\n{PkgData.pkg_name()}: {PkgData.pkg_version()}')
        print('\tPackage:')
        print(f'\t\tCyBootloader: {package_ver}')
        if ProjectInitializerBase.is_project():
            project_ver = self.project_bootloader_version()
            print('\tProject:')
            print(f'\t\tCyBootloader: {project_ver}')

        dist_source = self.dist_source()

        if dist_source:
            logger.debug('URL: %s', dist_source.get('url'))
            vcs_info = dist_source.get('vcs_info')
            if vcs_info is not None:
                revision = vcs_info.get('requested_revision')
                commit = vcs_info.get('commit_id')
                if revision is not None:
                    logger.debug('Branch/tag: %s', revision)
                if commit is not None:
                    logger.debug('Commit: %s', commit)
        else:
            logger.debug('Not able to find installation source details')

    def log_version(self, tool):
        """
        Logs SFB and CyBootloader versions
        """
        sfb_version = self.device_sfb_version(tool)
        logger.info('Secure Flash Boot version: %s', sfb_version)

        dev_bootloader_ver = self.device_bootloader_version(tool)
        logger.info('Device CyBootloader version: %s', dev_bootloader_ver)

        pkg_bootloader_ver = self.package_bootloader_version()
        logger.info('Package CyBootloader version: %s', pkg_bootloader_ver)

        self.target.entrance_exam.log_protection_state(tool)

    def check_compatibility(self, tool, **kwargs):
        """Checks HW compatibility
        @param tool: OCD tool used for communication
        @param check_si_rev: Indicates whether to check silicon revision
        @return True if compatible, otherwise False
        """
        if 'check_si_rev' in kwargs:
            check_si_rev = kwargs.get('check_si_rev')
        else:
            check_si_rev = True
        result = self._verify_fw_version(tool)
        dev_info = self.target.silicon_data_reader.read_device_info(tool)
        result &= self._verify_silicon_family(dev_info.family_id)
        if result and check_si_rev:
            result &= self._verify_silicon_revision(dev_info.silicon_rev)
        return result

    def _verify_fw_version(self, tool):
        """Verifies Secure Flash Boot version compatibility"""
        sfb_version = self.device_sfb_version(tool)
        result = True
        if version.parse(sfb_version) <= version.parse(self.CST_2_1_0_SFB_VER):
            result = False
            logger.error("Early Production Units detected, please get earlier "
                         "version of tools by running 'pip install --upgrade "
                         "--force-reinstall cysecuretools==2.1.0'")
        return result

    def _verify_silicon_family(self, family_id):
        """Checks whether the connected silicon family is compatible
        with the target
        """
        if self.target.silicon_id:
            if family_id != self.target.silicon_id['family']:
                logger.error(
                    "Incompatible device detected. The selected target family "
                    "ID = %s, the connected device family ID = %s",
                    hex(self.target.silicon_id['family']),
                    hex(family_id))
                return False
        return True

    def _verify_silicon_revision(self, rev):
        """Checks whether the connected silicon revision is compatible
        with the target
        """
        if self.target.silicon_id:
            revisions = self.target.silicon_id.get('rev')
            if revisions and rev not in revisions:
                cmp = ', '.join(f'{si_rev_name(r)} ({r:#x})' for r in revisions)
                rev_name = si_rev_name(rev)
                logger.error(
                    "Incompatible device revision detected: %s (%s). The "
                    "selected target is compatible with the following "
                    "revision(s): %s. For the connected device, specify "
                    "'--rev %s' option", rev_name, hex(rev), cmp, rev_name)
                return False
        return True

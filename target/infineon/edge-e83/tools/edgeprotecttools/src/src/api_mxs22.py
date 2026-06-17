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
import logging
import os

from cryptography.hazmat.primitives.asymmetric.ec import EllipticCurvePublicKey

from .api_common import CommonAPI
from .core.connect_helper import ConnectHelper
from .core.enums import ProvisioningStatus, EntranceExamStatus
from .core.strategy_context import (
    CertificateContext, ProvisioningPacketCtx, ProvisioningContext)
from .execute.keygens import ec_keygen
from .targets.common.mxs22 import CertificateStrategyMXS22
from .targets.common.mxs22 import ImageVerificationMXS22
from .targets.common.mxs22.enums import LifecycleStage
from .targets.common.mxs22.multi_image_packet import MultiImageMXS22

logger = logging.getLogger(__name__)


class Mxs22API(CommonAPI):
    """A class containing API for MXS22 platform"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def ifx_device_cert(self, output, **kwargs):
        """Creates IFX Device certificate
        @param output: Path where to save the created CBOR certificate
        @param kwargs:
            :csr: Path where to save the certificate
            :date: The date of the OEM certificate creation
            :key_path: Private key path to sign certificate
            :cert_id: A unique S/N for this certificate
            :signer_id: Signer unique ID
        @return: Certificate object
        """
        context = CertificateContext(self.target.certificate_strategy)
        return context.create_certificate(output, None, None, dev_cert='device',
                                          **kwargs)

    @staticmethod
    def pubkey_from_cert(cert, kid, **kwargs) -> EllipticCurvePublicKey:
        """Retrieve public key from OEM certificate. Optionally save
        the key to a file.
        @param cert: The path to the OEM certificate.
        @param kid: Key ID in the certificate.
        @param kwargs:
            :fmt: Output key format.
            :output: The path where to save the key.
        @return: Key object.
        """
        pubkey = CertificateStrategyMXS22().pubkey_from_cert(cert, kid)

        output = os.path.abspath(kwargs.get('output')) if kwargs.get(
            'output') else None
        if output:
            ec_keygen.save_key(pubkey, output, kwargs.get('fmt'), kid=int(kid))
            logger.info("Public key saved to '%s'", output)

        return pubkey

    def integrity_cert(self, output, **kwargs):
        """Creates IFX Device Integrity certificate
        @param output: Path where to save the created CBOR certificate
        @param kwargs:
            :template: Path to the Device Integrity template
            :key_path: Private key path to sign certificate
        @return: Certificate object
        """
        context = CertificateContext(self.target.certificate_strategy)
        return context.create_certificate(output, None, None,
                                          dev_cert='device_integrity', **kwargs)

    def integrity_exam(self, custom_regions, probe_id=None, **kwargs):
        """Runs Device Integrity check app
        @param custom_regions: The path to the custom region template
        @param probe_id: Probe serial number
        @param kwargs:
            :param cert: The path to integrity certificate
            :param cert_template: The path to integrity cert template
        @return: True if success, otherwise False
        """
        result = EntranceExamStatus.FAIL
        cert_path = kwargs.get('cert')
        template_path = kwargs.get('cert_template')
        for file_path in (cert_path, template_path):
            if file_path:
                file_path = os.path.abspath(file_path)
                if not os.path.isfile(file_path):
                    logger.error('File does not exists: %s', file_path)
                    return False

        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap='sysap'):
            self.target.version_provider.log_version(self.tool)

            apps_type = kwargs.get('testapps')
            cert, template = self.target.entrance_exam.cert_filename(
                self.tool, cert_path, template_path, apps_type)
            if not kwargs.get('existing_packet'):
                ctx = ProvisioningPacketCtx(
                    self.target.provisioning_packet_strategy)
                ctx.create(self.target, flow_name='device_integrity_exam',
                           integrity_cert=cert, **kwargs)
                ctx.create_package(
                    self.target, flow_name='device_integrity_exam', **kwargs)
            try:
                result = self.target.entrance_exam.execute(
                    self.tool, custom_regions=custom_regions,
                    template_path=template, **kwargs)
            except Exception as e:  # pylint: disable=broad-except
                logger.error(e)
            finally:
                ConnectHelper.disconnect(self.tool)
        else:
            logger.error('Lost connection to the device AP')

        return result == EntranceExamStatus.OK

    def verify_integrity_response(self, cert, in_params, response, **kwargs):
        """Integrity exam app response verification"""
        template_path = kwargs.get('cert_template')
        cert, template = self.target.entrance_exam.cert_filename(
            None, cert, template_path, None)
        result = self.target.entrance_exam.execute(None,
                                                   in_params=in_params,
                                                   response=response,
                                                   template_path=template,
                                                   display_ifx=True,
                                                   display_oem=True,
                                                   **kwargs)
        return result == EntranceExamStatus.OK

    def integrity_exam_hashes(self, cert, response, output, **kwargs):
        """Fill integrity template with hashes"""

        result = self.target.entrance_exam.fill_template(
            cert, response, output, **kwargs
        )

        return result == EntranceExamStatus.OK

    def debug_token(self, template, output, key=None, **kwargs):
        """Creates debug or RMA token binary from the token template
        @param template:
            Path to the token template in JSON format
        @param output:
            The token binary output file
        @param key:
            Path to the private key file used to sign the certificate
        @param kwargs:
            signature - Path to the signature to be added to the
                        existing certificate
            unsigned_cert - Path to the unsigned certificate
        """
        signature = kwargs.get('signature')
        if signature:
            unsigned_cert = kwargs.get('unsigned_cert')
            self.target.debug_certificate.add_signature(
                unsigned_cert, signature, output, **kwargs)
        else:
            self.target.debug_certificate.create(template, key, kid=None,
                                                 output=output, **kwargs)
        return True

    def cose_token(self, template, key, kid=None, output=None, **kwargs):
        """Creates COSE token from the template
        @param template: Path to the JSON template
        @param key: Path to the private key
        @param kid: Key ID
        @param output: Save path
        @param kwargs: Token type
        """
        return self.target.debug_certificate.create(template, key, kid=kid,
                                                    output=output, **kwargs)

    def verify_image(self, image, **kwargs):
        """Verifies image with a key or IFX OEM certificate
        @param image: Image path
        @param kwargs:
            :cert: IFX OEM certificate
            :key: Verification key
            :kid: Key ID to select the key from the certificate
        @return: True if success, otherwise False
        """
        return ImageVerificationMXS22.verify_image(
            image, kwargs.get('cert'), kwargs.get('key'), kwargs.get('kid'))

    def verify_packet(self, packet, **kwargs):
        """Verifies provisioning packet with a key
        @param packet: Provisioning packet path
        @param kwargs:
            :key: Verification key
            :kid: Key ID
        @return: True if success, otherwise False
        """
        ctx = ProvisioningPacketCtx(self.target.provisioning_packet_strategy)
        return ctx.verify(self.target, packet=packet, **kwargs)

    def provision_device(self, probe_id=None, ap='sysap', **kwargs):
        """Executes device provisioning
        @param probe_id: Probe serial number
        @param ap: The access port used for provisioning
        @return: True if success, otherwise False
        """
        acquire = kwargs.get('acquire', True)
        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap=ap, acquire=acquire):
            lcs = self.target.version_provider.get_lifecycle_stage(self.tool)
            if lcs == LifecycleStage.SECURE.name:
                logger.error(
                    'Provisioning is only available in the DEVELOPMENT LCS')
                return False
            return super().provision_device(probe_id=probe_id, ap=ap, **kwargs)
        logger.error('Error occurred while provisioning device')
        return False

    def load_and_run_app(self, config, probe_id=None, ap='sysap', acquire=True):
        """Loads and runs RAM application
        @param config: Path to the application configuration file
        @param probe_id: Probe serial number
        @param ap: The access port used to load the application
        @return: True if application loaded successfully, otherwise False
        """
        if config is None:
            raise ValueError('Config file is not specified')
        if not os.path.isfile(config):
            raise FileNotFoundError(f'File \'{config}\' not found')

        context = ProvisioningContext(self.target.provisioning_strategy)

        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap=ap, acquire=acquire):
            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)
            status = context.provision(
                self.tool, self.target, config=config, existing_packet=True)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('An error occurred while loading the application')

        return True

    @staticmethod
    def multi_image_cose(input_path, output, key, **kwargs):
        """Creates a multiple images COSE packet
        @param input_path: The path to the hex image
        @param output: Path to save
        @param key: Key path
        @param kwargs:
            :param template: Additional image data template
        @return: COSE multiple images packet
        """
        packet = MultiImageMXS22(input_path, output, key=key, **kwargs).create()

        return packet

    def se_rt_services_update(self, **kwargs):
        """Executes se_rt_services update application
        @return: True if success, otherwise False
        """
        if not kwargs.get('existing_packet'):
            ctx = ProvisioningPacketCtx(
                self.target.provisioning_packet_strategy)
            ctx.create_package(
                self.target, input_params=kwargs.get('image'),
                flow_name='se_rt_services_update', **kwargs)
        if ConnectHelper.connect(
                self.tool, self.target, probe_id=kwargs.get('probe_id'),
                ap='sysap'):
            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)
            logger.info('Running the SE_RT_SERVICES update application')
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.provision(self.tool, self.target,
                                       flow_name='se_rt_services_update',
                                       **kwargs)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('An error occurred while loading the application')

        return status == ProvisioningStatus.OK

    def factory_reset(self, probe_id, **kwargs):
        """Executes factory reset to restore device factory state
        @param probe_id: Probe serial number
        @return: True if success, otherwise False
        """
        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap='sysap'):
            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)
            logger.info('Running the factory reset')
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.provision(self.tool, self.target,
                                       flow_name='factory_reset',
                                       existing_packet=True,
                                       **kwargs)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('An error occurred while loading the application')

        return status == ProvisioningStatus.OK

    def image_update(self, **kwargs):
        """Executes image update application
        @return: True if success, otherwise False
        """
        if not kwargs.get('existing_packet'):
            ctx = ProvisioningPacketCtx(
                self.target.provisioning_packet_strategy)
            ctx.create_package(
                self.target, input_params=kwargs.get('image'),
                flow_name='image_update', **kwargs)
        if ConnectHelper.connect(
                self.tool, self.target, probe_id=kwargs.get('probe_id'),
                ap='sysap'):
            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)
            logger.info('Running the image update application')
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.provision(self.tool, self.target,
                                       flow_name='image_update',
                                       **kwargs)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('An error occurred while loading the application')

        return status == ProvisioningStatus.OK

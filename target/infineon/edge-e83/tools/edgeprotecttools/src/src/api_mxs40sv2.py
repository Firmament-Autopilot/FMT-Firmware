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
import logging

from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import ec

from .api_common import CommonAPI
from .core.enums import KeyAlgorithm, ProvisioningStatus, EntranceExamStatus
from .core.connect_helper import ConnectHelper
from .core.key_handlers.ec_handler import ECHandler
from .core.strategy_context import (ProvisioningContext, ProvisioningPacketCtx,
                                    CertificateContext)
from .execute.keygens import rsa_keygen, aes_keygen
from .targets import is_cywxx829
from .targets.common.mxs40sv2.enums import LifecycleStage
from .targets.common.mxs40sv2.image_signing import EncryptorMXS40Sv2

logger = logging.getLogger(__name__)


class Mxs40sv2API(CommonAPI):
    """A class containing API for MXS40sv2 platform"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def create_keys(self, overwrite=None, out=None, kid=None, # pylint: disable=arguments-renamed
                    user_key_alg=KeyAlgorithm.RSA, **kwargs):
        """Creates keys either specified in policy file or
        in the output argument
        @param overwrite: Indicates whether overwrite keys in the
               output directory if they already exist. If the value
               is None, a prompt will ask whether to overwrite
               existing keys
        @param out: Output filenames for the private and public keys
        @param kid: Key ID to create keys in the paths specified in policy
        @param user_key_alg: User key algorithm
        @return: True if key(s) created successfully, otherwise False.
        """
        if not self.validate_policy(['pre_build', 'dap_disabling']):
            return False

        # Define key algorithm
        if user_key_alg is None:
            user_key_alg = self.target.key_algorithms[0]
        else:
            if user_key_alg not in self.target.key_algorithms:
                valid_algorithms = ",".join(self.target.key_algorithms)
                logger.error(
                    "Invalid key algorithm '%s'. Supported key algorithms for "
                    "the selected target: %s", user_key_alg, valid_algorithms)
                return False

        # Find key paths that have to be generated
        keys = self.target.key_source.get_keys(key_path=out, key_id=kid,
                                               key_alg=user_key_alg)

        # Check whether keys exist
        if not overwrite:
            keys_exist = False
            for pair in keys:
                if pair.private is not None:
                    keys_exist = keys_exist | os.path.isfile(pair.private)
                if pair.public is not None:
                    keys_exist = keys_exist | os.path.isfile(pair.public)
            if keys_exist:
                if overwrite is None:
                    if self.skip_prompts:
                        logger.info('Keys already exist. Skip creating keys')
                        return True

                    answer = input('Keys directory is not empty. '
                                   'Overwrite? (y/n): ')
                    while answer.lower() != 'y' and answer.lower() != 'n':
                        answer = input("Please use 'y' or 'n'")
                    if answer.lower() != 'y':
                        logger.info('Terminated by user')
                        return True
                elif overwrite is False:
                    logger.info('Keys already exist. Skip creating keys')
                    return True

        # Generate keys
        for pair in keys:
            if user_key_alg == KeyAlgorithm.RSA:
                private_key, public_key = rsa_keygen.generate_key(
                    2048, template=kwargs.get('template'))
                if pair.private:
                    rsa_keygen.save_key(private_key, pair.private, 'PEM',
                                        kid=kwargs.get('kid'))
                    logger.info("Created a key '%s'",
                                os.path.abspath(pair.private))
                if pair.public:
                    rsa_keygen.save_key(public_key, pair.public, 'PEM',
                                        kid=kwargs.get('kid'))
                    logger.info("Created a key '%s'",
                                os.path.abspath(pair.public))
                    if kwargs.get('hash_path'):
                        rsa_keygen.create_pubkey_hash(pair.public,
                                                      kwargs.get('hash_path'))
            elif user_key_alg == KeyAlgorithm.AES:
                aes_keygen.generate_key(output=pair.private, add_iv=False)
        return True

    def extend_image(self, image, **kwargs):
        """Extends firmware image with the TLVs
        @param image: User application file
        @return: Extended (and encrypted if applicable) file path
        """
        if not is_cywxx829(self.target_name):
            raise NotImplementedError('Not supported by the selected target')
        return self.target.sign_tool.extend_image(image, **kwargs)

    def prov_packets_to_policy(self, packets, output):
        """Reverse conversion of the provisioning packet to the policy file
        @param packets: List of the binary packets paths
        @param output: The file where to save the policy
        @return: True if packet converted successfully, otherwise False
        """
        if not is_cywxx829(self.target_name):
            raise NotImplementedError('Not supported by the selected target')
        ctx = ProvisioningPacketCtx(self.target.provisioning_packet_strategy)
        return ctx.reverse_conversion(self.target, packets, output)

    def load_and_run_app(self, config, probe_id=None, ap='sysap'):
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
                                 ap=ap):
            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)
            status = context.provision(self.tool, self.target,
                                       skip_prompts=self.skip_prompts,
                                       config=config)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('An error occurred while loading the application')

        return status == ProvisioningStatus.OK

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
                                          dev_cert='device_integrity',
                                          target=self.target, **kwargs)

    def integrity_exam(self, probe_id=None, **kwargs):
        """Runs Device Integrity Exam
        @param probe_id: Probe serial number
        @return: True if success, otherwise False
        """
        result = EntranceExamStatus.FAIL

        if not kwargs.get('integrity_cert'):
            raise ValueError('Certificate must be specified')

        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id):
            self.target.version_provider.log_version(self.tool)

            lcs = self.target.version_provider.get_lifecycle_stage(self.tool)
            if lcs not in (LifecycleStage.NORMAL_PROVISIONED.name,
                           LifecycleStage.SECURE.name):
                logger.error('Unable to execute Device Integrity Check in the '
                             'current LCS. Expected LCS is %s, %s',
                             LifecycleStage.NORMAL_PROVISIONED.name,
                             LifecycleStage.SECURE.name)
                ConnectHelper.disconnect(self.tool)
                return False

            if not kwargs.get('existing_packet'):
                ctx = ProvisioningPacketCtx(
                    self.target.provisioning_packet_strategy)
                ctx.create(
                    self.target, flow_name='device_integrity_exam', **kwargs)
                ctx.create_package(
                    self.target, flow_name='device_integrity_exam', **kwargs)
            try:
                result = self.target.entrance_exam.execute(self.tool, **kwargs)
            except Exception as e:  # pylint: disable=broad-except
                logger.error(e)
            finally:
                ConnectHelper.disconnect(self.tool)
        else:
            result = EntranceExamStatus.FAIL
            logger.error('Lost connection')

        return result == EntranceExamStatus.OK

    def integrity_verify_response(self, cert, in_params, out_results, **kwargs):
        """Integrity exam app response verification"""

        if not all((cert, in_params, out_results)):
            raise ValueError(
                'Certificate, in_params and out_results must be specified'
            )

        result = self.target.entrance_exam.execute(None,
                                                   in_params=in_params,
                                                   out_results=out_results,
                                                   integrity_cert=cert,
                                                   **kwargs)
        return result == EntranceExamStatus.OK
    
    @staticmethod
    def encrypt(input_file, enckey, **kwargs):
        """Encrypts input file data
        @param input_file: Binary file to encrypt
        @param enckey: Encryption key
        @return: True if success, otherwise False
        """
        encryptor = EncryptorMXS40Sv2(enckey)
        result, _, nonce_output = encryptor.encrypt_image(
            input_file,
            initial_counter=kwargs.get('iv'),
            output=kwargs.get('output'),
            nonce=kwargs.get('nonce'),
            nonce_output=kwargs.get('nonce_output'))

        if result:
            logger.info('Encryption successful')
            logger.info('Encrypted file path: %s',
                        os.path.abspath(kwargs.get('output')))
            logger.info('Nonce path: %s',
                        os.path.abspath(nonce_output))
        return result

    @staticmethod
    def extract_iak(infile, output):
        """Extracts IAK from the results of prov_oem application"""

        app_completion_status = b'\x01\x00\xa0\xf2'
        packet_size = 144

        with open(infile, 'rb') as f:
            data = f.read()

        assert len(data) >= packet_size
        assert data[0:4] == app_completion_status

        curve = None
        key_bytes = None
        key_data = None

        if data[4:8] == b'\x00\x00\x00\x00':
            logger.info("No IAK found in '%s'", os.path.abspath(infile))
            return False
        elif data[4:8] == b'\x0c\x00\x00\xf3':
            logger.info("AES-256 key found in '%s'", os.path.abspath(infile))
            key_data = data[8:8+32]
            curve = None
        elif data[4:8] == b'\x3a\x00\x00\xc5':
            logger.info("ECDSA-P256 key found in '%s'", os.path.abspath(infile))
            key_bytes = data[8:8+65]
            curve = ec.SECP256R1()
        elif data[4:8] == b'\x59\x00\x00\xa6':
            logger.info("ECDSA-P384 key found in '%s'", os.path.abspath(infile))
            key_bytes = data[8:8+97]
            curve = ec.SECP384R1()
        elif data[4:8] == b'\x6f\x00\x00\x90':
            logger.info("ECDSA-P521 key found in '%s'", os.path.abspath(infile))
            key_bytes = data[8:8+133]
            curve = ec.SECP521R1()
        else:
            logger.error('Invalid input file format')
            return False

        if curve:
            try:
                public_key = ECHandler.populate_public_key(key_bytes,
                                                           curve=curve)
            except ValueError as e:
                logger.error('Failed to create public key: %s', e)
                return False
            key_data = public_key.public_bytes(
                encoding=serialization.Encoding.PEM,
                format=serialization.PublicFormat.SubjectPublicKeyInfo
            )

        if output:
            with open(output, 'wb') as f:
                f.write(key_data)
            logger.info('Key saved to %s', os.path.abspath(output))

        return True

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
import json
import logging

from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import serialization

from .api_common import CommonAPI
from .core.connect_helper import ConnectHelper
from .core.strategy_context import CertificateContext
from .core.strategy_context import ProvisioningContext
from .core.strategy_context import EncryptedProgrammingContext
from .core.enums import (
    EntranceExamStatus, ProvisioningStatus, ImageType, KeyType)
from .execute import jwt
from .execute.keygens import ec_keygen, aes_keygen
from .targets.common.mxs40v1.image_cert import ImageCertificate
from .targets.common.mxs40v1.encrypted_programming import AesHeaderStrategy

logger = logging.getLogger(__name__)


class Mxs40v1API(CommonAPI):
    """A class containing API for MXS40v1 platform"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def create_keys(self, overwrite=None, out=None, kid=None, # pylint: disable=arguments-renamed
                    _user_key_alg=None, **kwargs):
        """Creates keys specified in policy file
        @param overwrite: Indicates whether overwrite keys in the
               output directory if they already exist. If the value
               is None, a prompt will ask whether to overwrite
               existing keys.
        @param out: Output directory for generated keys. By default,
               keys location is as specified in the policy file.
        @param kid: Key ID. Specified to generate the key with
               specific ID only.
        @param _user_key_alg: Not used. Keep for BWC
        @return: True if key(s) created successfully, otherwise False.
        """
        if not self.validate_policy(['pre_build', 'dap_disabling']):
            return False

        # Find key paths that have to be generated
        keys = self.target.key_source.get_keys(key_path=out)

        # Check whether keys exist
        if not overwrite:
            keys_exist = False
            for pair in keys:
                if pair.key_type is KeyType.user:
                    if pair.image_type == ImageType.BOOTLOADER:
                        continue
                    if pair.json_key is not None:
                        keys_exist = keys_exist | os.path.isfile(pair.json_key)
                    if pair.pem_key is not None:
                        keys_exist = keys_exist | os.path.isfile(pair.pem_key)
                    if pair.pem_key_pub is not None:
                        keys_exist = keys_exist | os.path.isfile(pair.pem_key_pub)
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
        seen = []
        for pair in keys:
            if pair.image_type == ImageType.BOOTLOADER:
                continue
            if pair.key_type is KeyType.user:
                if {pair.key_id, pair.json_key} in seen or \
                        (kid is not None and pair.key_id != kid):
                    continue

                if pair.key_id is not None and pair.json_key is not None:
                    seen.append({pair.key_id, pair.json_key})

                if kwargs.get('template'):
                    _, public_key = ec_keygen.generate_key(
                        ec.SECP256R1(), template=kwargs.get('template'))
                    ec_keygen.save_key(public_key, pair.json_key, 'JWK',
                                       kid=pair.key_id)
                    logger.info("Created a key '%s'",
                                os.path.abspath(pair.json_key))
                    ec_keygen.save_key(public_key, pair.pem_key, 'PEM',
                                       kid=pair.key_id)
                    logger.info("Created a key '%s'",
                                os.path.abspath(pair.pem_key))
                else:
                    private_key, _ = ec_keygen.generate_key(ec.SECP256R1())
                    ec_keygen.save_key(private_key, pair.json_key, 'JWK',
                                       kid=pair.key_id)
                    logger.info("Created a key '%s'",
                                os.path.abspath(pair.json_key))
                    ec_keygen.save_key(private_key, pair.pem_key, 'PEM',
                                       kid=pair.key_id)
                    logger.info("Created a key '%s'",
                                os.path.abspath(pair.pem_key))
            else:
                continue

        return True

    def create_x509_certificate(self, cert_name='psoc_cert.pem',
                                cert_encoding=serialization.Encoding.PEM,
                                probe_id=None, **kwargs):
        """Creates certificate in X.509 format
        @param cert_name: Filename
        @param cert_encoding: Certificate encoding
        @param probe_id: The probe ID. Used for default certificate generation
        @param kwargs: Dictionary with the certificate fields
        @return The certificate object
        """
        context = CertificateContext(self.target.certificate_strategy)

        expected_fields = ['subject_name', 'country', 'state', 'organization',
                           'issuer_name', 'private_key']
        all_fields_present = all(
            k in kwargs and kwargs[k] is not None for k in expected_fields)
        serial = kwargs.get('serial_number')
        public_key = kwargs.get('public_key')

        if not all_fields_present or not serial or not public_key:
            if not self.validate_policy(['pre_build', 'dap_disabling']):
                return None
            logger.info('Get default certificate data')

            default = context.default_certificate_data(self.tool, self.target,
                                                       probe_id)
            if not default:
                logger.error('Failed to get data for the certificate')
                return None

            for field in expected_fields:
                if field not in kwargs or kwargs[field] is None:
                    kwargs[field] = default[field]

            if not serial:
                kwargs['serial_number'] = default['serial_number']
            if not public_key:
                kwargs['public_key'] = default['public_key']

        logger.info('Start creating certificate')
        overwrite = True if self.skip_prompts else None
        return context.create_certificate(cert_name, cert_encoding,
                                          overwrite=overwrite, **kwargs)

    def entrance_exam(self, probe_id=None, ap='sysap', erase_flash=False):
        """Checks device life-cycle, Flashboot firmware and Flash state
        @param probe_id: Probe serial number
        @param ap: The access port used for entrance exam
        @param erase_flash: Indicates whether to erase flash before the
               entrance exam
        @return True if the device is ready for provisioning,
                otherwise False
        """
        if not self.validate_policy(['pre_build', 'dap_disabling']):
            return False

        status = False
        if ConnectHelper.connect(self.tool, self.target,
                                 probe_id=probe_id, ap=ap):

            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)

            context = ProvisioningContext(self.target.provisioning_strategy)
            status = self.target.entrance_exam.execute(self.tool,
                                                       erase_flash=erase_flash)
            if status == EntranceExamStatus.FLASH_NOT_EMPTY:
                if self.skip_prompts:
                    logger.error('Entrance exam failed. '
                                 'User firmware running on chip detected')
                    return ProvisioningStatus.FAIL

                answer = input(
                    'Erase user firmware running on chip? (y/n): ')
                if answer.lower() == 'y':
                    context.erase_flash(self.tool, self.target)
            ConnectHelper.disconnect(self.tool)
        return status == EntranceExamStatus.OK

    def flash_map(self, image_id=1, image_type=ImageType.BOOT.name):
        """Extracts information about slots from given policy
        @param image_id: The ID of the firmware in policy file
        @param image_type: The image type - BOOT or UPGRADE
        @return: Address for specified image, size for specified image
        """
        address, size = None, None

        if not self.validate_policy(['pre_build', 'dap_disabling']):
            return address, size

        # Find keys that have to be generated
        data = self.policy_parser.get_image_data(image_type.upper(), image_id)
        if len(data) > 0:
            address, size = data[0]
        else:
            logger.error("Cannot find image with id %s and type '%s' in "
                         "the policy file", image_id, image_type)
        return address, size

    def create_image_certificate(self, image, key, output, version, image_id=0,
                                 exp_date_str='Jan 1 2031'):
        """Creates Bootloader image certificate
        @param image: Image path
        @param key: Key path
        @param output: Output certificate file path
        @param version: Image version
        @param image_id: Image ID
        @param exp_date_str: Certificate expiration date
        @return: True if certificate created successfully, otherwise False
        """
        if key is None:
            if not self.validate_policy(['pre_build', 'dap_disabling']):
                return False
            policy_keys = self.policy_parser.get_keys(
                image_type=ImageType.BOOTLOADER)
            if not policy_keys:
                logger.error('Failed to create image certificate. Key not '
                             'specified neither in policy nor as an argument')
                return False
            key = os.path.abspath(policy_keys[0].json_key)

        if not os.path.isfile(key):
            logger.error("Cannot find the key '%s'", key)
            return False

        image = os.path.abspath(image)
        output = os.path.abspath(output)
        image_cert = ImageCertificate(image, key, output, version, image_id,
                                      exp_date_str)
        image_cert.create()
        logger.info('Image certificate was created successfully')
        logger.info('Image version: %s', version)
        logger.info('Certificate: %s', output)
        return True

    def encrypt_image(self,
                      image,
                      host_key_id,
                      dev_key_id,
                      key_length=16,
                      encrypted_image='encrypted_image.txt',
                      padding_value=0,
                      probe_id=None):
        """Creates encrypted image for encrypted programming
        @param image: The image to encrypt
        @param host_key_id: Host private key ID (4 - HSM, 5 - OEM)
        @param dev_key_id: Device public key ID (1 - device, 12 - group)
        @param key_length: Derived key length
        @param encrypted_image: Output file of encrypted image for
               encrypted programming
        @param padding_value: Value for image padding
        @param probe_id: Probe serial number
               Used to read device public key from device
        """
        if not self.validate_policy(['dap_disabling']):
            return False

        # Get host private key
        logger.debug('Host key id = %d', host_key_id)
        try:
            _, host_key_pem = self.policy_parser.get_private_key(host_key_id)
        except ValueError as ex:
            logger.error(ex)
            return False

        # Get public key
        pub_key_pem = None
        logger.debug('Device key id = %d', dev_key_id)

        connected = ConnectHelper.connect(self.tool, self.target, ap='sysap',
                                          probe_id=probe_id)
        if connected:
            if not self.target.version_provider.check_compatibility(
                    self.tool, check_si_rev=False):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)

            logger.info('Read device public key from device')
            pub_key_pem = self.target.key_reader.read_public_key(
                self.tool, dev_key_id, 'pem')
            ConnectHelper.disconnect(self.tool)

        if not connected or not pub_key_pem:
            logger.info('Read public key %d from file', dev_key_id)
            try:
                _, pub_key_pem = self.policy_parser.get_public_key(
                    dev_key_id, pre_build=True)
            except ValueError as ex:
                logger.error(ex)
                return False

        # Create AES key
        key_to_encrypt = aes_keygen.generate_key(key_size=key_length, fmt='hex')

        # Create encrypted image
        context = EncryptedProgrammingContext(AesHeaderStrategy)
        aes_header = context.create_header(
            host_key_pem, pub_key_pem, key_to_encrypt, key_length)
        context.create_encrypted_image(
            image, key_to_encrypt, aes_header, host_key_id, dev_key_id,
            encrypted_image, padding_value)
        return True

    def encrypted_programming(self, encrypted_image, probe_id=None):
        """Programs encrypted image
        @param encrypted_image: The encrypted image to program
        @param probe_id: Probe serial number
        @return: True if the image programmed successfully, otherwise False
        """
        result = False
        context = EncryptedProgrammingContext(AesHeaderStrategy)
        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap='sysap'):
            if self.target.version_provider.check_compatibility(self.tool):
                self.target.version_provider.log_version(self.tool)
                result = context.program(self.tool, self.target, encrypted_image)
            ConnectHelper.disconnect(self.tool)
        return result

    def read_public_key(self, key_id, key_fmt, out_file=None, probe_id=None):
        """Reads public key from device and saves it to the file
        @param key_id: Key ID to read
        @param key_fmt: Key format (jwk or pem)
        @param out_file: Filename where to save the key
        @param probe_id: Probe serial number
        @return: Key if it read successfully, otherwise None
        """
        key = None
        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap='sysap'):

            if not self.target.version_provider.check_compatibility(
                    self.tool, check_si_rev=False):
                ConnectHelper.disconnect(self.tool)
                return key
            self.target.version_provider.log_version(self.tool)

            try:
                key = self.target.key_reader.read_public_key(
                    self.tool, key_id, key_fmt)
                if key is None:
                    logger.error('Cannot read public key (key_id=%d)', key_id)
                elif out_file:
                    out_file = os.path.abspath(out_file)
                    with open(out_file, 'w', encoding='utf-8') as fp:
                        if key_fmt == 'jwk':
                            json.dump(key, fp, indent=4)
                        elif key_fmt == 'pem':
                            fp.write(key.decode('utf-8'))
                        else:
                            fp.write(str(key))
                    logger.info('Key saved: %s', out_file)
                ConnectHelper.disconnect(self.tool)
            except (ValueError, FileNotFoundError) as e:
                logger.error(e)
        return key

    def sign_json(self, json_file, priv_key_id, output_file):
        """Signs JSON file with the private key
        @param json_file: JSON file to be signed
        @param priv_key_id: Private Key ID to sign the file
               with (1 - DEVICE, 4 - HSM, 5 - OEM, 12 - GROUP
        @param output_file: Filename where to save the JWT. If not
               specified, the input file name with "jwt" extension
               will be used
        @return: The JWT
        """
        logger.info('Signing file %s', os.path.abspath(json_file))
        if not self.validate_policy(['dap_disabling']):
            return False

        logger.debug('Private key id = %d', priv_key_id)
        try:
            jwk, _ = self.policy_parser.get_private_key(priv_key_id)
        except ValueError as ex:
            logger.error(ex)
            return None

        if not output_file:
            output_file = f'{os.path.splitext(json_file)[0]}.jwt'
        output_file = os.path.abspath(output_file)
        jwt_text = jwt.json_to_jwt(json_file, jwk, output_file)
        logger.info('Created file %s', output_file)
        return jwt_text

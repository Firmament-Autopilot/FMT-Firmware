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
import logging
import os.path

from .api_common import CommonAPI
from .core.connect_helper import ConnectHelper
from .core.enums import ProvisioningStatus, ValidationStatus
from .core.strategy_context import ProvisioningContext
from .execute.encryption import EncryptorAES
from .execute.ihex2hcd import hex2hcd
from .targets.cyw559xx.certs import (
    KeyCertificateGenerator, ContentCertificateGenerator, get_cert_config_parser
)
from .targets.cyw559xx.certs.validators import (
    CertConfigValidator, CertConfigAdvancedValidator
)
from .targets.cyw559xx.device_data import DeviceData
from .targets.cyw559xx.dl_image.image import DlImage
from .targets.cyw559xx.sign_tool import SignToolCYW559xx

logger = logging.getLogger(__name__)


class CYW559xxAPI(CommonAPI):
    """A class containing API for CYW559xx target"""

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def provision_device(self, probe_id=None, ap=None, **kwargs):
        """Executes device provisioning
        @param probe_id: N/A
        @param ap: N/A
        @return: True if success, otherwise False
        """
        status = ProvisioningStatus.FAIL
        if ConnectHelper.connect(self.tool, self.target):
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.provision(self.tool, self.target)
        return status == ProvisioningStatus.OK

    def load_and_run_app(self, config):
        """Loads and runs application"""
        status = ProvisioningStatus.FAIL
        if ConnectHelper.connect(self.tool, self.target):
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.provision(
                self.tool, self.target, config=config, existing_packet=True)
        return status == ProvisioningStatus.OK

    @staticmethod
    def secure_cert(config, output=None):
        """Generates secure Key or Content certificate
        @param config: Certificate configuration file
        @param output: Certificate output file
        @return: Certificate bytes
        """
        with open(config, 'r', encoding='utf-8') as file:
            try:
                cert_type = json.load(file)['certificate']['type']
            except (json.JSONDecodeError, KeyError) as e:
                logger.error("Invalid certificate configuration file '%s'",
                             os.path.abspath(config))
                logger.error(e.args[0])
                return None

        config_parser = get_cert_config_parser(cert_type, config)
        validator = CertConfigValidator(
            parser=config_parser,
            advanced_validator=CertConfigAdvancedValidator)
        is_config_valid = validator.validate(cert_type)
        if is_config_valid != ValidationStatus.OK:
            return None

        if cert_type == 'KEY_CERT':
            generator = KeyCertificateGenerator(config)
            cert_name = 'Key'
        elif cert_type == 'CONTENT_CERT':
            generator = ContentCertificateGenerator(config)
            cert_name = 'Content'
        else:
            logger.error("Invalid certificate type '%s'", cert_type)
            return None

        certificate = generator.generate()
        if output:
            with open(output, 'wb') as file:
                file.write(certificate)
            logger.info(f"{cert_name} certificate saved to '%s'",
                        os.path.abspath(output))
        return certificate

    @staticmethod
    def secure_image(image, certs, **kwargs):
        """Merges application image with the key and content certificates
        @param image: Image to merge with the certificates
        @param certs: List of certificate paths in DER format
        @return: Merged image object
        """
        if not certs:
            logger.error('No certificates specified')
            return None

        if len(certs) != 3:
            logger.error('3 certificates are required in the following order: '
                         'first key certificate, second key certificate, '
                         'content certificate')
            return None

        signed = SignToolCYW559xx.sign(image, certs, **kwargs)

        if signed:
            if kwargs.get('output'):
                logger.info("Saved image to '%s'",
                            os.path.abspath(kwargs.get('output')))
            if kwargs.get('hcd'):
                if kwargs.get('ota'):
                    raise ValueError('HCD is NA for OTA images')
                try:
                    hex2hcd(kwargs.get('output'), kwargs.get('hcd'))
                except (FileNotFoundError, RuntimeError) as e:
                    logger.error(e)
                    return None
                logger.info("Saved HCD file to '%s'",
                            os.path.abspath(kwargs.get('hcd')))
        return signed

    @staticmethod
    def ota_image(image, output=None):
        """Creates OTA image
        @param image: Application HEX file
        @param output: OTA image output path
        """
        dl_img = DlImage()
        dl_img.load(image)
        ds_size = dl_img.ds.header.ds_size
        ds_address = dl_img.ds.header.ds_address

        logger.info('DS size: %d (0x%x)', ds_size, ds_size)
        logger.info('Certificate chain address: 0x%08X', dl_img.cert_address)

        # Calculate new DS size
        ds_append_num = 16 - (ds_size % 16) if ds_size % 16 else 0
        ds_append_num += 16 + 1
        new_ds_size = ds_size + ds_append_num
        logger.info('New DS size: %d (0x%x)', new_ds_size, new_ds_size)
        dl_img.ds.header.ds_size = new_ds_size

        # Calculate new certificate address
        new_cert_addr = (ds_address + new_ds_size + 16 + 256)
        if new_cert_addr % 256:
            new_cert_addr += 256 - (new_cert_addr % 256)
        if new_cert_addr > dl_img.cert_address:
            logger.info('New certificate chain address: 0x%08X', new_cert_addr)
            dl_img.cert_address = new_cert_addr
        elif new_cert_addr == dl_img.cert_address:
            logger.info('Certificate chain address unchanged: 0x%08X',
                        new_cert_addr)

        ota_image_bytes = (dl_img.mdh.mdh_bytes + dl_img.ds.ds_bytes +
                           dl_img.ds.padding + dl_img.cert_bytes)
        if output:
            with open(output, 'wb') as f:
                f.write(ota_image_bytes)
            logger.info("OTA image saved to '%s'", os.path.abspath(output))
        return ota_image_bytes

    @staticmethod
    def encrypt(image, key, iv, output=None):
        """Encrypts the image with AES cipher
        @param image: Image HEX file, generated by MTB
        @param key: Encryption key path
        @param iv: Initialization vector (16 bytes)
        @param output: Encrypted image output path
        @return: Encrypted image IntelHex object
        """
        if os.path.isfile(key):
            with open(key, 'rb') as f:
                key = f.read()
        else:
            try:
                key = bytes.fromhex(key)
                if len(key) != 16:
                    raise ValueError
            except ValueError:
                logger.error("Invalid key. It must be a 16-byte binary file "
                             "or a hex string")
                return None

        if os.path.isfile(iv):
            with open(key, 'rb') as f:
                iv = f.read()
        else:
            try:
                iv = bytes.fromhex(iv)
                if len(iv) != 16:
                    raise ValueError
                logger.info('IV: %s', iv.hex())
            except ValueError:
                logger.error("Invalid IV. It must be a 16-byte binary file "
                             "or a hex string")
                return None

        # IV is stored as another MDH section and cannot contain zeros at
        # the end because this will be considered as a zero address of the
        # section, and the header fails to parse
        if b'\x00\x00\x00' in iv:
            logger.error('The IV must not contain three consecutive zero bytes')
            return None

        dl_img = DlImage()
        dl_img.load(image)
        dl_img.mdh.sub_ds_app.encrypted = True
        dl_img.mdh.iv = iv
        app = bytes(dl_img.sub_ds_app.tobinarray())
        enc = EncryptorAES.encrypt(app, key, iv, 'CTR', pad=False)
        dl_img.sub_ds_app = enc

        if output:
            dl_img.save_hex(output)
            logger.info("Encrypted image saved to '%s'",
                        os.path.abspath(output))
        return dl_img.data

    def get_csr(self, output, csr_id='0'):
        """Gets CSR data from the device"""
        if ConnectHelper.connect(self.tool, self.target):
            info = DeviceData(self.tool)
            return info.create_csr(output, csr_id)
        return False

    def read_soc_id(self, output):
        """Gets SOC ID"""
        if ConnectHelper.connect(self.tool, self.target):
            info = DeviceData(self.tool)
            return info.read_soc_id(output)
        return False

    def erase_flash(self) -> bool:
        """Erases flash memory of the device"""
        status = False
        if ConnectHelper.connect(self.tool, self.target):
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.erase_flash(self.tool, self.target)
        return status

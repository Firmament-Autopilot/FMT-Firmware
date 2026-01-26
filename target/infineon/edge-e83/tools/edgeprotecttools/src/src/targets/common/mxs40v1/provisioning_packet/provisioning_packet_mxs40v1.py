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

from .lib.cyprov_hsm import HsmEntity
from .lib.cyprov_oem import OemEntity
from .lib.cyprov_dev import DeviceEntity
from .lib.cyprov_crypto import Crypto
from .....core.enums import ImageType
from .....core.strategy_context import ProvisioningPacketStrategy


# Default output values and paths
PROV_IDENTITY_JWT = 'prov_identity.jwt'
PROV_REQ_JWT = 'prov_req.jwt'
ROT_AUTH_JWT = 'rot_auth.jwt'
PROV_CMD_JWT = 'prov_cmd.jwt'
PROV_PRIV_KEY_JWT = 'prov_priv_key.jwt'
DEVICE_RESPONSE_JWT = 'device_response.jwt'
DEFAULT_IMAGE_CERT_PATH = \
    '../prebuilt/CyBootloader_WithLogs/CypressBootloader_CM0p.jwt'

CUSTOMER_KEY_N = 5
PROD_NAME = 'my_thing'
DEV_NAME = "my_device"
logger = logging.getLogger(__name__)


class ProvisioningPacketMXS40v1(ProvisioningPacketStrategy):
    """Provisioning packet generator for MXS40v1 platform"""

    def __init__(self, policy_parser):
        self.policy_parser = policy_parser

    def create(self, target, **kwargs):
        """
        Generates provisioning JWT packet.
        :param target: The target object
        :param kwargs: Dictionary with the following fields:
               - filtered_policy_path: Path to the filtered policy file
               - image_cert: Cypress Bootloader image certificate.
               - dev_cert: Chain of trust certificate(s). (Optional)
        :return: True if packet created successfully, otherwise False.
        """
        filtered_policy = target.policy_filter.filter_policy()
        image_cert = self._get_image_certificate(target)
        dev_cert = self._get_user_certificates()

        # Provisioning packet output directory
        output_path = self.policy_parser.get_provisioning_packet_dir()
        if not os.path.exists(output_path):
            os.makedirs(output_path)

        # OEM key
        oem_pub_key, _ = self.policy_parser.oem_public_key()
        oem_priv_key, _ = self.policy_parser.oem_private_key()
        if not oem_pub_key:
            logger.error('Invalid OEM public key')
            return False
        if not oem_priv_key:
            logger.error('Invalid OEM private key')
            return False

        # HSM key
        hsm_pub_key, _ = self.policy_parser.hsm_public_key()
        hsm_priv_key, _ = self.policy_parser.hsm_private_key()
        if not hsm_pub_key:
            logger.error('Invalid HSM public key')
            return False
        if not hsm_priv_key:
            logger.error('Invalid HSM private key')
            return False

        oem = OemEntity(oem_priv_key=oem_priv_key, oem_pub_key=oem_pub_key)
        hsm = HsmEntity(hsm_priv_key=hsm_priv_key, hsm_pub_key=hsm_pub_key)
        dev = DeviceEntity()

        # Group private key
        use_key = self.policy_parser.provision_group_private_key_state()
        if use_key:
            grp_priv_key, _ = self.policy_parser.group_private_key()
            grp_priv_key_packet = oem.group_priv_key_packet(grp_priv_key)
            grp_priv_key_path = os.path.join(output_path, PROV_PRIV_KEY_JWT)
            Crypto.dump_jwt(grp_priv_key_packet, grp_priv_key_path)
        else:
            grp_priv_key = None

        # Device private key
        use_key = self.policy_parser.provision_device_private_key_state()
        if use_key:
            dev_priv_key, _ = self.policy_parser.device_private_key()
        else:
            dev_priv_key = None

        # Provisioning authorization certificate
        cy_auth_path = self.policy_parser.get_cy_auth()
        cy_auth = Crypto.read_jwt(cy_auth_path)

        # Image certificate
        if not image_cert:
            image_cert = self._abs_path(DEFAULT_IMAGE_CERT_PATH)
            logger.debug('Bootloader certificate not specified. Using default')
        logger.debug("Bootloader image certificate = '%s'", image_cert)
        with open(image_cert, encoding='utf-8') as f:
            image_cert_jwt = f.read()

        # Customer keys
        cust_key_path = self._get_custom_keys()
        if cust_key_path is None:
            logger.error("No customer keys found")
            return False
        if len(cust_key_path) > CUSTOMER_KEY_N:
            logger.error(
                'Maximum number of customer keys must be %d', CUSTOMER_KEY_N)

        prod_id = PROD_NAME

        prov_identity_jwt_path = os.path.join(output_path, PROV_IDENTITY_JWT)
        prov_req_jwt_path = os.path.join(output_path, PROV_REQ_JWT)
        rot_auth_jwt_path = os.path.join(output_path, ROT_AUTH_JWT)
        prov_jwt_path = os.path.join(output_path, PROV_CMD_JWT)

        blob = filtered_policy
        blob['prod_id'] = prod_id
        blob['custom_pub_key'] = []
        for key_path in cust_key_path:
            cust_pub_key, _ = self.policy_parser.public_key(key_path)
            blob['custom_pub_key'].append(cust_pub_key)

        logger.debug('Create provisioning request (prov_req) packet')
        prov_req = oem.create_provision_request(blob)
        Crypto.dump_jwt(prov_req, prov_req_jwt_path)

        logger.debug('Create root-of-trust (prov_rot) packet')
        rot_auth_pkg = oem.pack_rot_auth(prod_id, hsm_pub_key)
        Crypto.dump_jwt(rot_auth_pkg, rot_auth_jwt_path)

        logger.debug('Create device identity packet')

        _, identity_jwt = dev.create_device_identity(
            cy_auth, rot_auth_pkg, prod_id, grp_priv_key, dev_priv_key,
            hsm_priv_key)
        Crypto.dump_jwt(identity_jwt, prov_identity_jwt_path)

        try:
            prov_cmd = hsm.pack_provision_cmd(
                cy_auth=cy_auth,
                image_cert=image_cert_jwt,
                prov_req=prov_req,
                chain_of_trust=dev_cert,
                complete=True)
        except ValueError as e:
            logger.error(e)
            return False

        Crypto.dump_jwt(prov_cmd, prov_jwt_path)

        logger.info('#' * 70)
        logger.info('Provisioning packet is created')
        logger.info('#' * 70)
        return True

    def verify(self, target, **kwargs):
        """N/A for the MXS40v1 platform"""
        raise NotImplementedError

    def create_package(self, target, **kwargs):
        """N/A for MXS40v1 platform"""
        raise NotImplementedError

    def reverse_conversion(self, target, packets, output):
        raise NotImplementedError

    def _abs_path(self, path):
        """
        Converts policy related path to the absolute.
        """
        if os.path.isabs(path):
            return path
        rel_path = os.path.join(self.policy_parser.policy_dir, path)
        return os.path.abspath(rel_path)

    def _get_custom_keys(self):
        json_key_paths = []
        for image_type in [ImageType.BOOT,
                           ImageType.UPGRADE,
                           ImageType.BOOTLOADER]:
            keys = self.policy_parser.get_keys(image_type=image_type)
            for key in keys:
                json_key_path = key.json_key
                if not os.path.isfile(json_key_path):
                    logger.error("Cannot find the key '%s'", json_key_path)
                    return None
                if json_key_path not in json_key_paths:
                    json_key_paths.append(json_key_path)
        return json_key_paths

    @staticmethod
    def _get_image_certificate(target):
        """ Gets bootloader image certificate """
        image_cert = target.bootloader_provider.jwt_path()
        if not os.path.isfile(image_cert):
            raise FileNotFoundError(f'Bootloader certificate not found ('
                                    f'{image_cert})')
        return image_cert

    def _get_user_certificates(self):
        """ Gets user certificates (chain of trust) """
        certs = self.policy_parser.get_chain_of_trust()
        dev_certs = ()
        for cert in certs:
            dev_certs = dev_certs + (cert,)
        return dev_certs

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
import os
import logging
from cbor import cbor

from ....execute.image_signing.image import Image
from ....core.signtool_base import SignToolBase
from ....core.key_handlers.ec_handler import ECHandler

logger = logging.getLogger(__name__)


class ImageVerificationMXS22:
    """Image signing and manipulations with its data"""

    @staticmethod
    def verify_image(image_path, cert=None, key=None, kid=None):
        """Verifies the image with a key or a certificate
        @param image_path: The file to verify
        @param cert: IFX OEM certificate
        @param key: Verification key
        @param kid: Key ID to select the key from the certificate
        @return: True is success, otherwise False
        """
        if cert is None and key is None:
            raise ValueError('Either a key or a certificate must be specified')
        if cert and key:
            raise ValueError('Certificate and key are mutually exclusive')

        image_path = os.path.abspath(image_path)
        image = Image(image_path)
        if not image.is_signed:
            raise ValueError(f"Image is not signed '{image_path}'")

        if cert:
            cert = os.path.abspath(cert)
            try:
                pubkeys = ImageVerificationMXS22.oem_public_keys(cert)
            except (AttributeError, UnicodeDecodeError) as e:
                raise ValueError(f"Invalid IFX OEM certificate '{cert}'") from e
            if kid is not None:
                pubkeys = (pubkeys[int(kid)],)
        else:
            pubkeys = (SignToolBase.load_public_key(key),)

        result = False
        for pubkey in pubkeys:
            logger.info("Verifying '%s' with key '%s'", image_path, key)
            result = image.verify(pubkey)
            if result:
                break
        if result:
            logger.info('Image verified successfully')
        else:
            logger.error('Invalid image signature')

        return result

    @staticmethod
    def oem_public_keys(filename):
        """Gets public keys from the certificate or CSR
        @param filename: A path to the certificate or CSR
        @return: Keys tuple
        """
        with open(filename, 'rb') as file:
            file_data = file.read()
        cbor_info = cbor.loads(file_data)
        cert_info = cbor.loads(cbor_info.value[2])
        pub_key0 = cert_info.get('public_key_0', cert_info.get('PUBLIC_KEY_0'))
        pub_key1 = cert_info.get('public_key_1', cert_info.get('PUBLIC_KEY_1'))
        pubkey0 = ECHandler.populate_public_key(pub_key0)
        pubkey1 = ECHandler.populate_public_key(pub_key1) if pub_key1 else None
        return pubkey0, pubkey1

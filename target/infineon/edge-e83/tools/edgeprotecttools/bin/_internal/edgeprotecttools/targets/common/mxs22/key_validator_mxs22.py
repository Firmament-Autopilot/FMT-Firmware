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
from ....core.key_validator import KeyValidator
from ....core.enums import KeyAlgorithm


class KeyValidatorMXS22(KeyValidator):
    """Key validator for MXS22 platform"""

    image_types_ec_only = ('bootrom_ram_app', 'bootrom_next_app', 'se_rts_img')

    key_algorithms = (
        KeyAlgorithm.ECDSA_P256, KeyAlgorithm.ECDSA_P384,
        KeyAlgorithm.RSA2048, KeyAlgorithm.RSA4096,
        KeyAlgorithm.AES128, KeyAlgorithm.AES256
    )

    def validate(self, key, **kwargs):
        if super().validate(key, **kwargs):
            return self.custom_validate(key, **kwargs)
        return False

    def custom_validate(self, key, **kwargs):
        """
        Checks whether the key has a valid format and
        matches one of the supported keys for image type
        @param key: Key or path to the key
        @param kwargs:
            image_type - Image type
        @raise ValueError: If the key has an invalid format or does not
        match any of the supported key types
        """
        img_type = kwargs.get('image_type')
        alg = self.algorithm_by_key(key)
        if img_type in self.image_types_ec_only:
            if alg in (
                    KeyAlgorithm.RSA2048,
                    KeyAlgorithm.RSA3072,
                    KeyAlgorithm.RSA4096
            ):
                raise ValueError('Unsupported key type. Supported types: '
                                 'ECDSA-P256, ECDSA-P384')
        return True

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
import os
from typing import Union

from .cert_config_parser_base import CertConfigParserBase
from .cert_enums import AesCeId, LoadVerifyScheme, CryptoType


class ContentCertConfigParser(CertConfigParserBase):
    """Searching data in the content certificate configuration file"""

    @staticmethod
    def hbk_id() -> int:
        """Gets a value of hbk_id. Only one value is supported"""
        return 0x0F

    def load_verify_scheme(self, ret_value=False) -> Union[
        LoadVerifyScheme, int]:
        """Gets a value of load_verify_scheme.value property"""
        value = self.enum_field(LoadVerifyScheme, ret_value,
                                'load_verify_scheme', 'value')
        if value is None:
            default = LoadVerifyScheme.RAM_VERIFY
            return default.value if ret_value else default
        return value

    def encrypted(self, ret_value=False) -> Union[bool, int]:
        """Gets a value of encrypted.value property"""
        encrypted = self.field('encrypted', 'value')
        if ret_value:
            return AesCeId.KCE.value if encrypted else AesCeId.NONE.value
        return encrypted

    def crypto_type(self, ret_value=False) -> Union[CryptoType, int]:
        """Gets a value of crypto_type.value property"""
        value = self.enum_field(CryptoType, ret_value, 'crypto_type', 'value')
        if value is None:
            default = CryptoType.PLAIN_IMAGE_HASH
            return default.value if ret_value else default
        return value

    def image_table(self) -> Union[str, None]:
        """Gets a value of image_table.value property"""
        tbl_file = self.field('image_table', 'value')
        if not tbl_file:
            return None
        if not os.path.isabs(tbl_file):
            tbl_file = os.path.join(self.cert_config_dir, tbl_file)
        return tbl_file

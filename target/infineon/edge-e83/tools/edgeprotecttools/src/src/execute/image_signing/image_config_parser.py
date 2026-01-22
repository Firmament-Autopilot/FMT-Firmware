"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
from ...core.json_helper import read_json


class ImageConfigParser:
    """Class for parsing image config JSON,
    used to add TLVs to RAM app images
    """

    @staticmethod
    def get_image_tlvs(config_file):
        """
        Gets tag-value pairs that will be added to the protected TLV area
        :param config_file: Path to the image config file
        """
        config = read_json(config_file)
        tlv_list = {}
        for tlv in config['tlv']:
            tlv_value = '0x'
            if isinstance(tlv['value'], list):
                for v in tlv['value']:
                    int_value = int(v['value'], 0)
                    byte_value = int_value.to_bytes(v['length'],
                                                    byteorder='little')
                    hex_value = byte_value.hex()
                    tlv_value += hex_value
            else:
                tlv_value = tlv['value']

            tlv_list[tlv['tag']] = tlv_value
        return tlv_list

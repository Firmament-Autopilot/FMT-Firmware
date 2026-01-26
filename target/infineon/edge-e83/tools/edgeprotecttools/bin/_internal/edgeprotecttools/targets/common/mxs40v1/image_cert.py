"""
Copyright 2018-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import hashlib
from datetime import datetime

from click import BadParameter
from intelhex import IntelHex

from .provisioning import sys_call
from ....execute import jwt
from ....execute.key_reader import load_key
from ....core.json_helper import dump_json


class ImageCertificate:
    def __init__(self, image, key, output, version, image_id, exp_date_str):
        self.image = image
        self.key = key
        self.output = output
        self.version = version
        self.image_id = image_id
        self.exp_date = self.str_to_date(exp_date_str)
        self.priv_key, self.pub_key = load_key(self.key)

    @staticmethod
    def validate_version(_ctx, _param, version_string):
        """
        Returns input string if it has a valid format.
        Otherwise raises ValueError exception.
        """
        if version_string is None:
            version_string = '0.0.0.0'

        version_list = version_string.split('.')
        version_format = 'MAJOR.MINOR.REVISION.BUILD'

        try:
            if len(version_list) != len(version_format.split('.')):
                raise ValueError(
                    f'Version string must be in format {version_format}')

            for item in version_list:
                int(item)

        except ValueError as error:
            raise BadParameter("{}".format(error)) from error

        return version_string

    @staticmethod
    def validate_date(_ctx, _param, date_str):
        """
        Returns input string if it has a valid format.
        Otherwise raises ValueError exception.
        """
        try:
            ImageCertificate.str_to_date(date_str)
        except ValueError as e:
            raise BadParameter(
                f"'{date_str}' does not match format 'Jan 1 2031'") from e
        return date_str

    @staticmethod
    def str_to_date(date_str):
        return datetime.strptime(date_str, '%b %d %Y')

    def _process_image(self):
        """
        Read image address and size and calculate image hash
        """
        ih = IntelHex(self.image)
        ih.padding = 0x00

        image_addr = ih.minaddr()
        image_size = ih.maxaddr() - ih.minaddr() + 1

        sha256 = hashlib.sha256()
        sha256.update(ih.tobinarray(start=image_addr, size=image_size))

        image_hash = sha256.digest()

        image_attr = dict()
        image_attr['image_hash'] = image_hash
        image_attr['image_addr'] = image_addr
        image_attr['image_size'] = image_size
        image_attr['image_id'] = self.image_id
        image_attr['version'] = self.version

        return image_attr

    def _create_cert_payload(self, image_attr):
        """
        Create payload for the image certificate
        """
        payload = dict()
        payload['image_id'] = image_attr['image_id']
        payload['image_hash'] = list(image_attr['image_hash'])
        payload['image_file'] = os.path.basename(self.image)
        payload['image_address'] = image_attr['image_addr']
        payload['image_size'] = image_attr['image_size']
        payload['image_version'] = image_attr['version']
        payload['policy_template'] = ''
        payload['iat'] = int(datetime.now().timestamp())
        payload['exp'] = int(self.exp_date.timestamp())

        return payload

    def _create_certificate(self, payload):
        """
        Create JWT certificate
        """
        dump_json(payload, os.path.splitext(self.output)[0] + '.json')
        jwt.create_jwt(payload, self.priv_key, self.output, 'ES256')

    def create(self):
        """
        Generates JWT certificate for Cypress Bootloader.
        """
        image_attr = self._process_image()
        payload = self._create_cert_payload(image_attr)
        self._create_certificate(payload)

    @staticmethod
    def get_version(cert):
        readable = jwt.readable_jwt(cert)
        payload = readable['payload']
        version = payload['image_version']
        return version

    @staticmethod
    def read_image_certificate(tool, target):
        """
        Reads image certificate provisioned into device
        :param tool: Programming/debugging tool
        :param target: The target object
        :return: The certificate if exists, otherwise None
        """
        _, data = sys_call.get_prov_details(tool, target.register_map,
                                            sys_call.FB_POLICY_IMG_CERTIFICATE)
        return data

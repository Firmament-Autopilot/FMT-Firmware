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
import os.path

from ....execute.imgtool.main import get_dependencies
from ...image_signing.sign_tool import SignTool
from .command import Command

logger = logging.getLogger(__name__)


class CommandSign(Command):
    """
    Implements a command for signing hex file.
    """

    in_args_map = {
        'cmd_name': 'command',
        'image': 'file',
        'key_path': 'signing-key',
        'header_size': 'header-size',
        'slot_size': 'slot-size',
        'erased_val': 'fill-value',
        'min_erase_size': 'min-erase-size',
        'image_version': 'image-version',
        'security_counter': 'security-counter',
        'align': 'align',
        'public_key_format': 'pubkey-format',
        'pubkey_encoding': 'pubkey-encoding',
        'signature_encoding': 'signature-encoding',
        'pad': 'pad',
        'confirm': 'confirm',
        'overwrite_only': 'overwrite-only',
        'boot_record': 'boot-record',
        'hex_addr': 'hex-address',
        'load_addr': 'load-address',
        'rom_fixed': 'rom-fixed',
        'max_sectors': 'max-sectors',
        'save_enctlv': 'save-enctlv',
        'dependencies': 'dependencies',
        'encrypt': 'encryption-public-key',
        'enckey': 'encryption-secret-key',
        'enckey_role': 'encryption-key-role',
        'encrypt_addr': 'encryption-address',
        'remove_tlv': 'remove-tlv',
        'kdf': 'kdf',
        'prot_tlv': 'protected-tlv',
        'tlv': 'tlv'
    }

    out_args_map = {
        'output': 'file',
        'output_format': 'format',
        'decrypted': 'unencrypted',
        'nonce_output': 'nonce-output'
    }

    schema = 'sign_schema.json'

    def __init__(self, **kwargs):
        inputs = kwargs.get('inputs')[0]
        outputs = kwargs.get('outputs')

        self._cmd_name = self.get_arg(kwargs, 'cmd_name')
        self._image = self.get_arg(inputs, 'image')

        self._in_args = {}
        self._in_args.update(inputs)

        self._out_args = {}
        for dic in outputs:
            self._out_args.update(dic)

        self._translate_in_args()
        self._translate_out_args()

    @property
    def image(self):
        return self._image

    @property
    def in_args(self):
        return self._in_args

    @property
    def out_args(self):
        return self._out_args

    def get_arg(self, kwargs, name, default=None):
        """Get argument of args_map
        @param kwargs: dict where JSON value is taken from
        @param name: key of args_map to get according value
        @param default: default value if key is not found
        """
        if name in self.out_args_map:
            return kwargs.get(self.out_args_map.get(name))

        return kwargs.get(self.in_args_map.get(name))

    def _translate_in_args(self):
        """Transform JSON input fields to args_map keys"""
        new_ins = {}

        if self.in_args.get('description'):
            self.in_args.pop('description')

        for map_k, map_v in self.in_args_map.items():
            if map_v in self._in_args:
                in_v = self._in_args.pop(map_v)
                new_ins.update({map_k: in_v})

        if 'dependencies' in new_ins:
            new_ins.update({
                'dependencies': get_dependencies(
                    None, None, new_ins['dependencies']
                )
            })

        if 'tlv' in new_ins:
            new_ins.update({'tlv': self._parse_tlv(new_ins['tlv'])})

        if 'prot_tlv' in new_ins:
            new_ins.update({'prot_tlv': self._parse_tlv(new_ins['prot_tlv'])})

        self._in_args = new_ins

    def _translate_out_args(self):
        """Transform JSON output fields to args_map keys"""
        new_outs = {}

        if self._out_args.get('description'):
            self._out_args.pop('description')

        for map_k, map_v in self.out_args_map.items():
            if map_v in self._out_args:
                out_v = self._out_args.pop(map_v)
                new_outs.update({map_k: out_v})

        self._out_args = new_outs

    @staticmethod
    def _parse_tlv(tlv: list):
        return list((x.get("tag"), x.get("value")) for x in tlv)

    def validate_args(self) -> bool:
        """Validates the sign command parameters"""

        if not self.image:
            logger.error('Field "%s" is required',
                         self.in_args_map.get("image"))
            return False

        if not os.path.exists(self.image):
            logger.error('File not found: "%s"', os.path.abspath(self.image))
            return False

        sign_keys = self.in_args.get("key_path")
        if sign_keys and not os.path.exists(sign_keys):
            logger.error('File not found: "%s"', os.path.abspath(sign_keys))
            return False

        required_in_args = ('image', 'header_size', 'slot_size')

        for arg in required_in_args:
            if arg not in self.in_args:
                logger.error('Input field "%s" is required', arg)
                return False

        required_out_args = ('output', 'output_format')

        for arg in required_out_args:
            if arg not in self.out_args:
                logger.error('Output field "%s" is required', arg)
                return False

        if 'encrypt' in self.in_args:
            if 'key_path' in self.in_args:
                if 'decrypted' in self.out_args:
                    logger.error("Argument 'decrypted' and 'signing-key' "
                                 "are mutually exclusive")
                    return False
            else:
                if not ('output' in self.out_args
                        and 'decrypted' in self.out_args):
                    logger.error("Arguments 'output' and 'decrypted' must be "
                                 "initialized together")
                    return False

        if not self.format_validation(self.out_args.get('output_format'),
                                      self.out_args.get('output')):
            return False

        return True

    def execute(self) -> bool:
        """Executes the sign command"""

        sign_tool = SignTool()

        self._in_args.pop('image')

        try:
            if self.in_args.get('key_path'):
                sign_tool.sign_image(
                    self.image, **self.in_args, **self.out_args
                )
            else:
                sign_tool.add_metadata(
                    self.image, **self.in_args, **self.out_args
                )
        except (OSError, ValueError) as e:
            logger.error(e)
            return False

        return True

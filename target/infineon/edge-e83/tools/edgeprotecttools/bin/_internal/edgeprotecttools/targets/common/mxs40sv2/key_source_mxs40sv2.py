"""
Copyright 2020-2025 Cypress Semiconductor Corporation (an Infineon company)
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

from ....core.enums import KeyPair, KeyAlgorithm


class KeySourceMXS40Sv2:

    def __init__(self, policy_parser):
        self.policy_parser = policy_parser

    def get_keys(self, **kwargs):
        """
        Gets list of KeyData objects
        :param kwargs:
            key_id - the ID of the key in the policy. Uses key path
                     specified in the policy
            key_path - list of tuples with a private-public key pairs
            key_aes - flag which indicates that only AES key will be generated
        """
        key_id = kwargs.get('key_id')
        key_path = kwargs.get('key_path')
        key_alg = kwargs.get('key_alg')

        keys = []
        if key_alg == KeyAlgorithm.AES:
            if key_path:
                aes_key_path = key_path
            else:
                aes_key_path = self.get_aes_key()
            if aes_key_path is None:
                raise KeyError('The encryption key is not specified')

            keys.append(KeyPair(os.path.abspath(aes_key_path), None))
        else:
            if key_id is None and not key_path:
                raise KeyError('Either key ID or key path must be specified')
            if key_path:
                if isinstance(key_path, str):
                    keys.append(KeyPair(None, os.path.abspath(key_path)))
                elif isinstance(key_path, (tuple, list)):
                    for pair in key_path:
                        keys.append(KeyPair(os.path.abspath(pair[0]),
                                            os.path.abspath(pair[1])))
                else:
                    raise TypeError("Expected types are 'str' or 'tuple'")
            else:
                if key_id == 0:
                    pub_key = self.policy_parser.get_pub_key_0_path()
                    priv_key = self.policy_parser.get_priv_key_0_path()
                elif key_id == 1:
                    pub_key = self.policy_parser.get_pub_key_1_path()
                    priv_key = self.policy_parser.get_priv_key_1_path()
                else:
                    raise ValueError(f'Invalid key ID {key_id}')

                if pub_key is None:
                    raise KeyError(f'OEM public key {key_id} not specified '
                                   f'({self.policy_parser.policy_file})')
                if priv_key is None:
                    raise KeyError(f'OEM private key {key_id} not specified '
                                   f'({self.policy_parser.policy_file})')

                keys.append(KeyPair(os.path.abspath(priv_key),
                                    os.path.abspath(pub_key)))

        return keys

    def get_key(self, key_id, key_type):
        """
        Gets a key based on specified ID and type
        :param key_id: The ID of the key in the policy.
                       Uses key path specified in the policy
        :param key_type: The type of key - 'private' or 'public'
        :return: Key path
        """
        if key_type in ['private', 'public']:
            if key_id == 0:
                if 'private' == key_type:
                    key = self.policy_parser.get_priv_key_0_path()
                else:
                    key = self.policy_parser.get_pub_key_0_path()
            elif key_id == 1:
                if 'private' == key_type:
                    key = self.policy_parser.get_priv_key_1_path()
                else:
                    key = self.policy_parser.get_pub_key_1_path()
            else:
                raise ValueError(f'Invalid key ID {key_id}')

            if key is None:
                raise KeyError(f'OEM key {key_id} not specified '
                               f'({self.policy_parser.policy_file})')
            return key
        else:
            raise ValueError(f'Invalid key type {key_type}. '
                             'Possible types "private" or "public"')

    def get_aes_key(self):
        """
        Gets path to the AES key from the policy
        """
        aes_key_path = self.policy_parser.get_encrypt_key_path()

        if aes_key_path is None:
            raise KeyError(f'Encryption key is not specified '
                           f'({self.policy_parser.policy_file})')

        return aes_key_path

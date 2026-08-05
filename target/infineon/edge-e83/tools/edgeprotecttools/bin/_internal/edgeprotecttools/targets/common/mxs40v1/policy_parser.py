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
from pathlib import Path

from .enums import KeyId
from ....core import MemoryArea, KeyData
from ....core.enums import KeyType, ImageType
from ....execute import key_reader
from ....core import key_helper


class PolicyParser:
    """Provides functionality for searching data in a policy files"""

    def __init__(self, policy):
        """
        Creates instance of policy parser.
        :param policy: Either path to policy file or policy dictionary
        """
        self.json = None
        self.policy_dir = None
        if policy is not None:
            self.initialize(policy)

    def initialize(self, policy):
        """Initializes parser"""
        if os.path.isfile(str(policy)):
            self.json = self.get_json(policy)
            self.policy_dir = os.path.dirname(Path(policy).absolute())
        elif type(policy) is dict:
            self.json = policy
            self.policy_dir = None
        else:
            self.policy_dir = 'policy'

    @staticmethod
    def get_json(filename):
        """
        Gets JSON file as a dictionary.
        :param filename: The JSON file.
        :return: JSON file as a dictionary.
        """
        with open(filename, encoding='utf-8') as f:
            file_content = f.read()
            try:
                data = json.loads(file_content)
            except json.decoder.JSONDecodeError as e:
                msg = f"Failed to parse policy '{filename}': {e.args[0]}"
                raise json.decoder.JSONDecodeError(msg, e.doc, e.pos)
        return data

    def get_keys(self, out=None, image_type=None, key_type=None):
        """
        Gets keys id and filename specified in the policy file.
        :return: List of pairs id-filename.
        """
        keys = []
        keys_dir = self.policy_dir if out is None else out
        for node in self.json['boot_upgrade']['firmware']:
            # Look for bootloader keys
            if 'bootloader_keys' in node:
                for item in node['bootloader_keys']:
                    key = KeyData(item['kid'], item['key'], KeyType.user,
                                  ImageType.BOOTLOADER, image_id=node['id'],
                                  keys_dir=keys_dir)
                    if key.key_id and key.json_key:
                        keys.append(key)

            # Look for boot keys
            if 'boot_keys' in node:
                for item in node['boot_keys']:
                    key = KeyData(item['kid'], item['key'], KeyType.user,
                                  ImageType.BOOT, image_id=node['id'],
                                  keys_dir=keys_dir)
                    if key.key_id and key.json_key:
                        keys.append(key)

            # Look for device public key
            if 'encrypt_peer' in node:
                pub_key = KeyData(key_type=KeyType.device_public,
                                  pem_key=node['encrypt_peer'],
                                  image_id=node['id'], keys_dir=keys_dir)
                pub_key.json_key = "{0}.json".format(*os.path.splitext(
                    pub_key.pem_key))
                keys.append(pub_key)

        # Resolve keys path
        for pair in keys:
            if out:
                if pair.json_key is not None:
                    pair.json_key = os.path.basename(pair.json_key)
                if pair.pem_key is not None:
                    pair.pem_key = os.path.basename(pair.pem_key)

            if pair.json_key and not os.path.isabs(pair.json_key):
                pair.json_key = os.path.join(keys_dir, pair.json_key)
                pair.json_key = os.path.abspath(pair.json_key)
            if pair.pem_key and not os.path.isabs(pair.pem_key):
                pair.pem_key = os.path.join(keys_dir, pair.pem_key)
                pair.pem_key = os.path.abspath(pair.pem_key)

        if image_type is not None:
            keys = [x for x in keys if x.image_type == image_type]
        if key_type is not None:
            keys = [x for x in keys if x.key_type == key_type]

        return keys

    def get_image_data(self, slot_type, image_id=None):
        """
        Gets image(s) address and size.
        :param slot_type: The slot type.
        :param image_id: The image ID. If not specified, data for all
                         images of specified type will be returned.
        :return: Array of (address, size) tuples.
        """
        result = []
        for slot in self.json["boot_upgrade"]["firmware"]:
            if image_id is None or slot['id'] == image_id:
                for res in slot['resources']:
                    if res['type'] == slot_type:
                        address = res['address']
                        size = res['size']
                        result.append((address, size))
        return result

    def get_slot(self, slot_id):
        """
        Gets a slot with specified id.
        :param slot_id: The slot ID.
        :return: Dictionary, which represents the slot data.
        """
        for slot in self.json["boot_upgrade"]["firmware"]:
            if slot['id'] == slot_id:
                return slot

    def get_upgrade_mode(self):
        """
        Gets upgrade mode specified in the policy file
        """
        for slot in self.json["boot_upgrade"]["firmware"]:
            if 'upgrade_mode' in slot:
                return slot['upgrade_mode']
        return None

    def get_cybootloader_mode(self):
        """
        Gets mode of CyBootloader specified in the policy file.
        :return: release or debug
        """
        return self.json['cy_bootloader']['mode']

    def get_cybootloader_hex(self):
        """
        Gets hex-file of CyBootloader specified in the policy file.
        :return: release or debug
        """
        path = self.json['cy_bootloader']['hex_path']
        if not os.path.isabs(path):
            path = os.path.abspath(os.path.join(self.policy_dir, path))
        return path

    def get_cybootloader_jwt(self):
        """
        Gets jwt-file of CyBootloader specified in the policy file.
        :return: release or debug
        """
        path = self.json['cy_bootloader']['jwt_path']
        if not os.path.isabs(path):
            path = os.path.abspath(os.path.join(self.policy_dir, path))
        return path

    def is_encrypted_bootloader(self):
        try:
            encrypted = self.json['cy_bootloader']['encrypted']
        except KeyError:
            encrypted = False
        return encrypted

    def is_custom_bootloader(self):
        try:
            custom = self.json['cy_bootloader']['mode'] == 'custom'
        except KeyError:
            custom = False
        return custom

    def get_provisioning_packet_dir(self):
        """
        Gets path of the provisioning packet specified in the policy file.
        :return: File path.
        """
        if self.json:
            packet_dir = self.json['provisioning']['packet_dir']
        else:
            packet_dir = os.path.join('..', 'packets')
        if not os.path.isabs(packet_dir):
            packet_dir = os.path.abspath(os.path.join(
                self.policy_dir, packet_dir))
        return packet_dir

    def get_cy_auth(self):
        """
        Gets cy_auth path
        :return: File path
        """
        cy_auth = self.json['pre_build']['cy_auth']
        if not os.path.isabs(cy_auth):
            cy_auth = os.path.abspath(os.path.join(self.policy_dir, cy_auth))
        return cy_auth

    def get_chain_of_trust(self):
        """
        Gets certificates paths specified in the policy file.
        :return: List of certificate paths.
        """
        try:
            certs = self.json['provisioning']['chain_of_trust']
            certs = [os.path.abspath(os.path.join(self.policy_dir, path))
                     if not os.path.isabs(path) else path for path in certs]
        except KeyError:
            certs = []
        return certs

    def get_user_apps(self):
        """
        Gets list of user applications, which should be programmed
        during provisioning
        :return: Tuple where the first value indicates whether app is
                 encrypted, the second - path to the program file
        """
        try:
            user_apps = self.json['pre_build']['user_apps']
            return [(x['encrypted'], x['app']) for x in user_apps]
        except KeyError:
            return []

    def is_cmx_ap_enabled(self, is_reprovision):
        ap = self.json["debug"]["m0p" if is_reprovision else "m4"]
        return ap["permission"] == "enabled"

    def is_sys_ap_enabled(self):
        return self.json["debug"]["system"]["permission"] == "enabled"

    def is_ap_disabled(self, ap):
        return self.json["debug"][ap]["permission"] == "disabled"

    def get_smif_resources(self):
        smif_resources = []
        items = self.json['boot_upgrade']['firmware']
        for item in items:
            if item['id'] != 0 and item['smif_id'] != 0 and item['upgrade']:
                for res in item['resources']:
                    if 'UPGRADE' in res['type']:
                        smif_resources.append([res['address'], res['size']])
        return smif_resources

    def upgrade_mode(self):
        for item in self.json['boot_upgrade']['firmware']:
            if item['id'] == 0 and 'upgrade_mode' in item:
                return item['upgrade_mode']
        return None

    def status_partition(self) -> MemoryArea:
        """
        Gets status partition memory area
        """
        for slot in self.json['boot_upgrade']['firmware']:
            if slot['id'] == 0:
                for item in slot['resources']:
                    if item['type'] == 'STATUS_PARTITION':
                        return MemoryArea(item['address'], item['size'])
        return None

    def scratch_area(self) -> MemoryArea:
        """
        Get scratch area location
        """
        for slot in self.json['boot_upgrade']['firmware']:
            if slot['id'] == 0:
                for item in slot['resources']:
                    if item['type'] == 'SCRATCH':
                        return MemoryArea(item['address'], item['size'])
        return None

    def device_public_key_path(self):
        """
        Gets device public key path.
        :return: Tuple with device public key (json, pem).
        """
        pub_key = self.get_keys(key_type=KeyType.device_public)
        if not pub_key:
            raise KeyError('Device public key path not found')
        return pub_key[0].json_key, pub_key[0].pem_key

    def hsm_public_key_path(self):
        key_path = self.json['pre_build']['hsm_public_key']
        return os.path.abspath(os.path.join(self.policy_dir, key_path))

    def hsm_private_key_path(self):
        key_path = self.json['pre_build']['hsm_private_key']
        return os.path.abspath(os.path.join(self.policy_dir, key_path))

    def oem_public_key_path(self):
        key_path = self.json['pre_build']['oem_public_key']
        return os.path.abspath(os.path.join(self.policy_dir, key_path))

    def oem_private_key_path(self):
        key_path = self.json['pre_build']['oem_private_key']
        return os.path.abspath(os.path.join(self.policy_dir, key_path))

    def device_public_key(self, pre_build=False):
        if pre_build:
            json_key_path = self.json['pre_build']['device_public_key']
        else:
            json_key_path, _ = self.device_public_key_path()
        return self.public_key(json_key_path)

    def hsm_public_key(self):
        return self.public_key(self.json['pre_build']['hsm_public_key'])

    def hsm_private_key(self):
        return self.private_key(self.json['pre_build']['hsm_private_key'])

    def oem_public_key(self):
        return self.public_key(self.json['pre_build']['oem_public_key'])

    def oem_private_key(self):
        return self.private_key(self.json['pre_build']['oem_private_key'])

    def group_private_key(self):
        return self.private_key(self.json['pre_build']['group_private_key'])

    def device_private_key(self):
        return self.private_key(self.json['pre_build']['device_private_key'])

    def get_public_key(self, key_id, **kwargs):
        if key_id == KeyId.DEVICE:
            try:
                pre_build = kwargs['pre_build']
            except KeyError:
                pre_build = False
            return self.device_public_key(pre_build=pre_build)
        elif key_id == KeyId.HSM:
            return self.hsm_public_key()
        elif key_id == KeyId.OEM:
            return self.oem_public_key()
        else:
            raise ValueError(f'No public key with ID {key_id} in the policy')

    def get_private_key(self, key_id):
        if key_id == KeyId.DEVICE:
            return self.device_private_key()
        elif key_id == KeyId.GROUP:
            return self.group_private_key()
        elif key_id == KeyId.HSM:
            return self.hsm_private_key()
        elif key_id == KeyId.OEM:
            return self.oem_private_key()
        else:
            raise ValueError(f'No private key with ID {key_id} in the policy')

    def provision_group_private_key_state(self):
        try:
            use_key = self.json['pre_build']['provision_group_private_key']
        except KeyError:
            use_key = False
        return use_key

    def provision_device_private_key_state(self):
        try:
            use_key = self.json['pre_build']['provision_device_private_key']
        except KeyError:
            use_key = False
        return use_key

    def private_key(self, key_path):
        if not os.path.isabs(key_path):
            key_path = os.path.abspath(os.path.join(self.policy_dir, key_path))
        try:
            private_jwk, _ = key_reader.load_key(key_path)
            private_pem = key_helper.jwk_to_pem(private_jwk, private_key=True)
        except (FileNotFoundError, AttributeError):
            private_jwk, private_pem = None, None
        return private_jwk, private_pem

    def public_key(self, key_path):
        if not os.path.isabs(key_path):
            key_path = os.path.abspath(os.path.join(self.policy_dir, key_path))
        try:
            _, public_jwk = key_reader.load_key(key_path)
            public_pem = key_helper.jwk_to_pem(public_jwk)
        except FileNotFoundError:
            public_jwk, public_pem = None, None
        return public_jwk, public_pem

    def abs_policy_path(self, path):
        """ Converts policy relative path to the absolute """
        if not os.path.isabs(path):
            return os.path.abspath(os.path.join(self.policy_dir, path))
        return path

    def encryption_enabled(self, image_id):
        """
        Indicates whether encryption is enabled for the
        specified image ID
        """
        slot = self.get_slot(image_id)
        return slot.get('encrypt', False)

    def encrypt_key(self, image_id):
        """ Gets encrypt peer for the specified image ID """
        slot = self.get_slot(image_id)
        if slot.get('encrypt_peer', False):
            return self.abs_policy_path(slot['encrypt_peer'])
        else:
            return None

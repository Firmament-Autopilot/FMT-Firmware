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


class KeyData:
    """
    Represents structure for key data.
    """
    def __init__(self, key_id=None, json_key=None, key_type=None,
                 image_type=None, pem_key=None, image_id=None,
                 pem_key_pub=None, keys_dir=None):
        self.key_id = key_id
        self.image_id = image_id
        self.key_type = key_type
        self.image_type = image_type
        self.pem_key_pub = pem_key_pub
        self.json_key = json_key

        if pem_key is None and self.json_key is not None:
            self.json_key = self._resolve_path(self.json_key, keys_dir)
            # Old behavior for the test keys support
            test_key = self._resolve_path(
                '{0}_PRIV.pem'.format(*os.path.splitext(json_key)), keys_dir)
            if os.path.isfile(test_key):
                self.pem_key = test_key
            else:
                self.pem_key = '{0}.pem'.format(*os.path.splitext(json_key))
        else:
            self.pem_key = pem_key

        if self.pem_key is not None:
            self.pem_key = self._resolve_path(self.pem_key, keys_dir)
        else:
            self.pem_key = pem_key

    @staticmethod
    def _resolve_path(key_policy_path, keys_dir=None):
        key_path = key_policy_path
        if not os.path.isabs(key_policy_path):
            if keys_dir is not None:
                key_path = os.path.abspath(
                    os.path.join(keys_dir, key_policy_path))
            else:
                key_path = os.path.abspath(key_policy_path)
        return key_path

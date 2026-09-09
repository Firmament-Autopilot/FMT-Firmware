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
import json
import logging

import jose
from jose.backends import ECKey, RSAKey
from jose.constants import ALGORITHMS

logger = logging.getLogger(__name__)


class PemKey:
    """A class representing a key in a PEM format"""

    def __init__(self, jwk_file=None, item=None):
        if jwk_file is not None:
            if isinstance(jwk_file, dict):
                self.jwk = jwk_file
            else:
                with open(jwk_file, encoding='utf-8') as f:
                    jwk_str = f.read()
                    self.jwk = json.loads(jwk_str)

        if item is not None:
            self.jwk = self._pretty_search(self.jwk, item,
                                           search_first_only=True)

    def save(self, file=None, private_key=False):
        """Saves a key to a file"""
        pem_str = self.to_str(private_key)
        if file is not None:
            with open(file, 'wb') as f:
                f.write(pem_str)
        else:
            logger.info(pem_str)

    def to_str(self, private_key=False):
        """Converts EC or RSA key to string"""
        try:
            key = ECKey(self.jwk, ALGORITHMS.ES256)
        except jose.exceptions.JWKError:
            key = RSAKey(self.jwk, ALGORITHMS.RS256)
        if private_key:
            pem_str = key.to_pem().strip()
        else:
            pem_str = key.public_key().to_pem().strip()
        return pem_str

    def load(self, jwk):
        """Loads JWK"""
        self.jwk = jwk

    def load_str(self, jwk_str):
        """Loads JWK string"""
        self.jwk = json.loads(jwk_str)

    @staticmethod
    def _pretty_search(dict_or_list, key_to_search, search_first_only=False):
        """Give it a dict or a list of dicts and a dict key (to get values of),
        it will search through it and all containing dicts and arrays
        for all values of dict key you gave, and will return you set of them
        unless you want to specify search_first_only=True
        """
        search_result = set()
        if isinstance(dict_or_list, dict):
            for key in dict_or_list:
                key_value = dict_or_list[key]
                if key == key_to_search:
                    if search_first_only:
                        return key_value
                    search_result.add(key_value)
                if isinstance(key_value, (dict, list, set)):
                    _search_result = PemKey._pretty_search(
                        key_value, key_to_search, search_first_only)
                    if _search_result and search_first_only:
                        return _search_result
                    if _search_result:
                        for result in _search_result:
                            search_result.add(result)
        elif isinstance(dict_or_list, (list, set)):
            for element in dict_or_list:
                if isinstance(element, (list, set, dict)):
                    _search_result = PemKey._pretty_search(
                        element, key_to_search, search_result)
                    if _search_result and search_first_only:
                        return _search_result
                    if _search_result:
                        for result in _search_result:
                            search_result.add(result)
        return search_result if search_result else None

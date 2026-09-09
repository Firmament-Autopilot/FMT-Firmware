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
import json
import logging

from .provisioning.sys_call import get_prov_details
from ....core.key_helper import jwk_to_pem
from ....execute import jwt

logger = logging.getLogger(__name__)


class KeyReaderMXS40V1:
    def __init__(self, target):
        self.target = target
        self.policy_parser = target.policy_parser
        self.policy_dir = self.policy_parser.policy_dir

    def read_public_key(self, tool, key_id, key_format='jwk'):
        passed, key = get_prov_details(tool, self.target.register_map, key_id)
        if passed:
            logger.debug('Public key (key_id=%s) read successfully', key_id)
            logger.debug(key)
            pub_key = json.loads(key)

            if key_format == 'jwk':
                return pub_key
            elif key_format == 'pem':
                return jwk_to_pem(pub_key)
            else:
                raise ValueError(f'Invalid key format \'{key_format}\'')
        else:
            return None

    def get_cypress_public_key(self):
        """
        Gets Cypress public key from cy_auth JWT packet.
        :return: Cypress public key (JWK).
        """
        jwt_text = jwt.read_jwt(self.policy_parser.get_cy_auth())
        json_data = jwt.readable_jwt(jwt_text)
        return json_data["payload"]['cy_pub_key']

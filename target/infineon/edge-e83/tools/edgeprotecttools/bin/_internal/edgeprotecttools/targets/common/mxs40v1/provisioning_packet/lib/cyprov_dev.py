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

from .cyprov_types import Types
from .cyprov_entity import Entity
from .cyprov_crypto import Crypto


class DeviceEntity(Entity):
    STAGE_VIRGIN = "VIRGIN"
    STAGE_NORMAL = "NORMAL"
    STAGE_SECURE = "SECURE"

    def __init__(self, state_name='', audit_name=''):
        Entity.__init__(self, state_name, audit_name)

    def create_entity(self):
        """
            Creates a virgin device
        """
        self.state["life_cycle_stage"] = self.STAGE_VIRGIN

    def create_device_identity(self, cy_auth, rot_auth, prod_id, grp_priv_key,
                               dev_priv_key, hsm_priv_key):
        """
        Creates prov_identity JWT packet
        :param cy_auth: cy_auth packet
        :param rot_auth: Root of trust authentication packet
        :param prod_id: Product ID
        :param grp_priv_key: Group private key
        :param dev_priv_key: Device private key
        :param hsm_priv_key: HSM private key for JWT creation
        :return: Tuple with readable prov_identity and prov_identity JWT
        """
        # Create device keys if not exist
        if dev_priv_key:
            if isinstance(dev_priv_key, dict):
                self.state['dev_priv_key'] = dev_priv_key
            else:
                if os.path.isfile(dev_priv_key):
                    self.state['dev_priv_key'] = Crypto.read_json(dev_priv_key)
                else:
                    self.state['dev_priv_key'], self.state['dev_pub_key'] = Crypto.create_jwk()
                    Crypto.dump_json(self.state['dev_priv_key'], dev_priv_key)

        # Create group keys if not exist
        if grp_priv_key:
            if isinstance(grp_priv_key, dict):
                self.state['grp_priv_key'] = grp_priv_key
            else:
                if os.path.isfile(grp_priv_key):
                    self.state['grp_priv_key'] = Crypto.read_json(grp_priv_key)
                else:
                    self.state['grp_priv_key'], self.state['grp_pub_key'] = Crypto.create_jwk()
                    Crypto.dump_json(self.state['grp_priv_key'], grp_priv_key)

        # Create prov_identity JWT
        payload = dict()
        payload['create_identity'] = True
        if 'dev_priv_key' in self.state:
            payload['dev_priv_key'] = self.state['dev_priv_key']
        if 'grp_priv_key' in self.state:
            payload['grp_priv_key'] = self.state['grp_priv_key']
        payload['cy_auth'] = cy_auth
        payload['rot_auth'] = rot_auth
        payload['prod_id'] = self.state['prod_id'] = prod_id

        self.state['create_identity'] = payload['create_identity']
        self.state['cy_auth'] = cy_auth
        payload['type'] = Types.HSM_PROV_CMD

        prov_identity = Crypto.create_jwt(payload, hsm_priv_key)
        return payload, prov_identity

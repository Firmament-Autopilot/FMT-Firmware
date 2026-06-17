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
from datetime import datetime

from .cyprov_types import Types
from .cyprov_entity import Entity
from .cyprov_crypto import Crypto


class OemEntity(Entity):
    def __init__(self, state_name='', audit_name='',
                 oem_priv_key=None, oem_pub_key=None):
        Entity.__init__(self, state_name, audit_name)
        if oem_priv_key and oem_pub_key:
            self.create_entity(oem_priv_key=oem_priv_key,
                               oem_pub_key=oem_pub_key)
        
    def create_entity(self, chain_of_trust=None,
                      oem_priv_key=None, oem_pub_key=None):
        """
        Creates the Oem entity.
        Creates the Oem main key-pair and returns nothing.
        """
        if chain_of_trust is None:
            chain_of_trust = []
        if not oem_priv_key and not oem_pub_key:
            oem_priv_key, oem_pub_key = Crypto.create_jwk()
        self.state["oem_priv_key"] = oem_priv_key
        self.state["oem_pub_key"] = oem_pub_key
        self.state["oem_chain_of_trust"] = chain_of_trust

    def create_provision_request(self, blob):
        """
        The OEM can create a request for provisioning by signing a
        keys & policies blob with its private key
        Note that blob must contain at least the prod_id field
        """
        # create the request
        oem_priv_key = self.state["oem_priv_key"]
        prov_req = Crypto.create_jwt(blob, oem_priv_key)
        
        # create audit record
        record = dict()
        record["type"] = Types.OEM_PROV_REQ
        record["iat"] = datetime.now().isoformat(' ')
        record["prod_id"] = blob["prod_id"]
        record["prov_req"] = Crypto.readable_jwt(prov_req)
        
        return prov_req
    
    def pack_rot_auth(self, prod_id, hsm_pub_key):
        oem_pub_key = self.state["oem_pub_key"]
        oem_priv_key = self.state["oem_priv_key"]
        
        payload = dict()
        payload["type"] = Types.OEM_ROT_AUTH
        payload["oem_pub_key"] = oem_pub_key
        payload["hsm_pub_key"] = hsm_pub_key
        payload["prod_id"] = prod_id
        rot_auth = Crypto.create_jwt(payload, oem_priv_key)
        
        return rot_auth

    def group_priv_key_packet(self, grp_priv_key):
        payload = {
            'grp_priv_key': grp_priv_key,
            'type': 'OEM_GRP_PRIV_KEY'
        }
        jwt = Crypto.create_jwt(payload, self.state["oem_priv_key"])
        return jwt

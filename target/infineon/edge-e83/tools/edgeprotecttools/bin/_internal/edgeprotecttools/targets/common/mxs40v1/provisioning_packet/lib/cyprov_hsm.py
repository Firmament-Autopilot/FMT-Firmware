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
import logging
import base64

from cryptography import x509
from cryptography.hazmat.backends import default_backend

from .cyprov_types import Types
from .cyprov_entity import Entity
from .cyprov_crypto import Crypto

logger = logging.getLogger(__name__)


class HsmEntity(Entity):
    def __init__(self, state_name='', audit_name='',
                 hsm_priv_key=None, hsm_pub_key=None):
        Entity.__init__(self, state_name, audit_name)
        if hsm_priv_key and hsm_pub_key:
            self.create_entity(hsm_priv_key, hsm_pub_key)

    def create_entity(self, hsm_priv_key=None, hsm_pub_key=None):
        """
        Creates the HSM entity.
        Creates the hsm_priv_key,hsm_pub_key key-pair.
        """
        if not hsm_priv_key and not hsm_pub_key:
            hsm_priv_key, hsm_pub_key = Crypto.create_jwk()
        self.state["hsm_priv_key"] = hsm_priv_key
        self.state["hsm_pub_key"] = hsm_pub_key

    def pack_provision_cmd(self, **kwargs):
        payload = {}
        if kwargs is not None:
            for k, v in kwargs.items():
                if type(v) is tuple:
                    sequence = []
                    for cert_file in v:
                        try:
                            with open(cert_file, encoding='utf-8') as cert:
                                sequence.append(cert.read())
                            barr = bytearray(sequence[0], encoding='utf-8')
                            try:
                                x509.load_pem_x509_certificate(bytes(barr), default_backend())
                            except ValueError as e:
                                raise ValueError(f'{e} Invalid certificate \'{cert_file}\'') from e
                        except UnicodeDecodeError:
                            sequence.append(self.der_to_pem(cert_file))
                    payload[k] = sequence
                else:
                    if isinstance(v, str) and os.path.isfile(v):
                        payload[k] = Crypto.read_jwt(v)
                    else:
                        payload[k] = v

        payload['type'] = Types.HSM_PROV_CMD

        hsm_priv_key = self.state['hsm_priv_key']
        prov_cmd = Crypto.create_jwt(payload, hsm_priv_key)

        return prov_cmd

    @staticmethod
    def der_to_pem(cert_file):
        with open(cert_file, "rb") as f:
            sequence = f.read()
        try:
            x509.load_der_x509_certificate(sequence, default_backend())
        except ValueError as e:
            raise ValueError(f'Unable to load certificate \'{cert_file}\'') from e
        sequence = base64.b64encode(sequence)
        return f'-----BEGIN CERTIFICATE-----\n{sequence.decode()}\n-----END CERTIFICATE-----'

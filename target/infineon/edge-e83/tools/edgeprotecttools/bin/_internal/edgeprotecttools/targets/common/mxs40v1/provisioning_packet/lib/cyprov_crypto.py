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
from datetime import datetime

from jose import jws, jwt
from jose.constants import ALGORITHMS
from jose.utils import long_to_base64
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import ec

logger = logging.getLogger(__name__)


class Crypto:
    @staticmethod
    def create_jwk():
        private_key = ec.generate_private_key(ec.SECP256R1(), default_backend())
        public_key = private_key.public_key()

        pub_key = {
            'alg': 'ES256',
            'kty': 'EC',
            'crv': 'P-256',
            'use': 'sig',
            'x': long_to_base64(
                    public_key.public_numbers().x,
                    size=32
                ).decode('utf-8'),
            'y': long_to_base64(
                    public_key.public_numbers().y,
                    size=32
                ).decode('utf-8'),
            }
        priv_key = dict(pub_key)
        priv_key['d'] = long_to_base64(
                            private_key.private_numbers().private_value,
                            size=32
                        ).decode('utf-8')

        logger.debug('create_jwk()= %s', json.dumps(pub_key, indent=4))
        return priv_key, pub_key

    @staticmethod
    def create_jwt(payload, ec_private_key):
        txt = jws.sign(payload, ec_private_key, algorithm=ALGORITHMS.ES256)

        logger.debug('create_jwt()= %s', txt)
        return txt

    @staticmethod
    def readable_jwt(txt):
        """
        Convert a JWT token in base64url into a readable dictionary object
        with decoded payload and header for printing and logging
        """
        signing_input, _ = txt.rsplit('.', 1)

        if len(signing_input.rsplit('.', 1)) == 1:
            readable = Crypto._load_unsigned_jwt(txt)
        else:
            readable = Crypto._load_signed_jwt(txt)

        # create readable timestamps for exp/iat claims
        payload = readable["payload"]
        if "iat" in payload:
            t = payload["iat"]
            if isinstance(t, int):
                t = datetime.fromtimestamp(t).isoformat(' ')
                payload["iat"] = t
        if "exp" in payload:
            t = payload["exp"]
            if isinstance(t, int):
                t = datetime.fromtimestamp(t).isoformat(' ')
                payload["exp"] = t

        return readable

    @staticmethod
    def _load_unsigned_jwt(txt):
        _, payload = txt.rsplit('.', 1)
        payload = payload.encode('utf-8')
        payload = jws.base64url_decode(payload)
        readable = {
            'protected': {},
            'payload': json.loads(payload.decode('utf-8')),
            'signature': ''
        }
        return readable

    @staticmethod
    def _load_signed_jwt(txt):
        _, crypto_segment = txt.rsplit('.', 1)
        header, claims, _, _ = jws._load(txt)  # pylint: disable=protected-access
        readable = {
            'protected': header,
            'payload': json.loads(claims.decode('utf-8')),
            'signature': crypto_segment
        }
        return readable

    @staticmethod
    def dump_jwt(txt, file_name):
        """
        Dumps a JWT dictionary object into a text file
        """
        with open(file_name, 'w', encoding='utf-8') as f:
            f.write(txt)
            f.close()

    @staticmethod
    def read_jwt(file_name):
        """
        Reads a JWT dictionary object from a text file
        """
        with open(file_name, 'r', encoding='utf-8') as f:
            txt = f.read()
            f.close()
        return txt

    @staticmethod
    def jwt_payload(txt):
        """
        Returns the payload of a JWT without validating it's signature.
        Sometimes used for tokens that contain a public key in its payload,
        where the signature proves possession of the corresponding private key.
        In that case, the payload is needed to obtain the public key
        with which to then validate the JWT.
        """
        return jwt.get_unverified_claims(txt)

    @staticmethod
    def validate_jwt(txt, ec_public_key):
        """
        Validates a signed JWT
        """
        try:
            jws.verify(txt, ec_public_key, ALGORITHMS.ES256, verify=True)
            return True
        except jws.JWSError:
            return False

    @staticmethod
    def read_json(filename):
        """
        Reads dictionary object from a JSON file
        """
        with open(filename, encoding='utf-8') as f:
            json_str = f.read()
            d = json.loads(json_str)
        return d

    @staticmethod
    def dump_json(data, filename):
        """
        Saves dictionary object to a JSON file
        """
        with open(filename, 'w', encoding='utf-8') as f:
            json.dump(data, f)

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
import json
import logging
from datetime import datetime

from jose import jws
from jose.constants import ALGORITHMS

logger = logging.getLogger(__name__)


def json_to_jwt(json_file, priv_key, output_file=None, alg='ES256'):
    """
    Create JWT from JSON file
    :param json_file: The JSON file to be signed
    :param priv_key: The private key to sign JSON
    :param output_file: The output file to save the certificate
    :param alg: The signing algorithm
    :return: JWT token
    """
    try:
        with open(json_file, encoding='utf-8') as f:
            file_content = f.read()
            json_data = json.loads(file_content)
    except FileNotFoundError as e:
        logger.error(e)
        return None

    return create_jwt(json_data, priv_key, output_file, alg)


def create_jwt(payload, priv_key, output_file=None, alg='ES256'):
    """
    Create JWT from JSON object
    :param payload: The JSON to be signed
    :param priv_key: The private key to sign JSON
    :param output_file: The output file to save the certificate
    :param alg: The signing algorithm
    :return: JWT token
    """
    if alg == 'ES256':
        headers = {'alg': 'ES256'}
        algorithm = ALGORITHMS.ES256
    else:
        raise ValueError(f'Unsupported algorithm {alg}')

    token = jws.sign(payload, priv_key, headers=headers, algorithm=algorithm)
    logger.debug('Created JWT token: %s', token)

    if output_file:
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(token)
        logger.debug('Saved JWT token to a file: %s', output_file)
    return token


def read_jwt(file_name):
    """
    Reads a JWT dictionary object from a text file
    """
    with open(file_name, 'r', encoding='utf-8') as f:
        txt = f.read()
        f.close()
    return txt


def validate_jwt(txt, ec_public_key):
    """
    Validates a signed JWT
    """
    try:
        jws.verify(txt, ec_public_key, ALGORITHMS.ES256, verify=True)
        return True
    except jws.JWSError:
        return False


def readable_jwt(jwt):
    """
    Convert a JWT token in base64url into a readable dictionary object
    with decoded payload and header for printing and logging
    :param jwt: JWT or filename containing JWT
    :return: Readable dictionary
    """
    txt = read_jwt(jwt) if os.path.isfile(jwt) else jwt

    signing_input, _ = txt.rsplit('.', 1)

    if len(signing_input.rsplit('.', 1)) == 1:
        readable = _load_unsigned_jwt(txt)
    else:
        readable = _load_signed_jwt(txt)

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


def _load_signed_jwt(txt):
    _, crypto_segment = txt.rsplit('.', 1)
    header, claims, _, _ = jws._load(txt)  # pylint: disable=protected-access
    readable = {
        'protected': header,
        'payload': json.loads(claims.decode('utf-8')),
        'signature': crypto_segment
    }
    return readable

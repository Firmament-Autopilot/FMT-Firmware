"""
Copyright 2023-2025 Cypress Semiconductor Corporation (an Infineon company)
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

import cwt
from cbor import cbor
from cryptography.hazmat.primitives.asymmetric import ec, rsa
from cwt.utils import to_cose_header

from .bitops import number_size
from .key_handlers import load_private_key, load_public_key
from .key_handlers.ec_handler import ECHandler
from .key_handlers.rsa_handler import RSAHandler


class Cose:
    """CBOR object encryption and signing"""

    @staticmethod
    def cose_sign1(payload, key_path, kid=None):
        """Converts to COSE Single Signer Data
        @param payload: Data for signing
        @param key_path: Key path to signing
        @param kid: Key ID
        @return: Encoded and signed COSE single signer data
        """
        if not isinstance(kid, (int, str, type(None))):
            raise TypeError(
                f"'kid' is of type '{type(kid).__name__}', "
                f"'int', 'str' is expected")

        key = Cose._cose_key(key_path, kid=kid)
        ctx = cwt.COSE.new()
        encoded = ctx.encode_and_sign(
            payload,
            key=key,
            protected={1: key.alg},
            unprotected={'kid': key.kid} if kid is not None else {})
        return encoded

    @staticmethod
    def cose_sign(payload, keys, kids=None):
        """Converts binary data to COSE Signed Data Object
        @param payload: Data to be signed
        @param keys: Signing keys paths
        @param kids: Key IDs
        @return: Encoded and signed COSE signed data object
        """
        ctx = cwt.COSE.new()
        signers = []
        if not kids:
            kids = (None, None)
        for key, kid in zip(keys, kids):
            if not isinstance(kid, (int, str, type(None))):
                raise TypeError(
                    f"'kid' is of type '{type(kid).__name__}', "
                    f"'int', 'str' is expected")

            kid = str(kid) if kid else None
            sign_key = Cose._cose_key(key, kid=kid)
            protected = {1: sign_key.alg}
            unprotected = {'kid': sign_key.kid} if kid is not None else {}
            signers.append(cwt.Signer.new(
                sign_key,
                protected=protected,
                unprotected=unprotected
            ))
        encoded = ctx.encode_and_sign(
            payload=payload,
            signers=signers
        )
        return encoded

    @staticmethod
    def add_signature1(payload, signature, algorithm, kid=None):
        """Adds signature to CBOR and serializes
        @param payload: Data to be signed
        @param signature: Signature bytes.
        @param kid: Key ID
        @param algorithm: Signature algorithm
        @return: COSE Single Signer Data Object
        """
        if not isinstance(kid, (int, str, type(None))):
            raise TypeError(
                f"'kid' is of type '{type(kid).__name__}', "
                f"'int', 'str' is expected")

        kid_encoded = Cose._cose_kid(kid)
        kid = {4: kid_encoded} if kid is not None else {}
        protected = cbor.dumps(to_cose_header({'alg': algorithm.upper()}))
        payload = cbor.loads(payload)
        res = cbor.Tag(18, [protected, kid, payload[3], signature])
        data = cbor.dumps(res)
        return data

    @staticmethod
    def add_signature(payload, signature, algorithm, kid=None):
        """Adds signature to CBOR and serializes
        @param payload: Data to be signed
        @param signature: A tuple of multiple signatures
        @param kid: A tuple of key IDs
        @param algorithm: A tuple of signature algorithms
        @return: COSE Signed Data Object
        """
        signers = []
        b_protected = b""
        if not kid:
            kids = (None, None)
        else:
            kids = kid
        for sig, alg, kid in zip(signature, algorithm, kids):
            if not isinstance(kid, (int, str, type(None))):
                raise TypeError(
                    f"'kid' is of type '{type(kid).__name__}', "
                    f"'int', 'str' is expected")
            kid_encoded = Cose._cose_kid(kid)
            kid = {4: kid_encoded} if kid is not None else {}
            protected = cbor.dumps(to_cose_header({'alg': alg.upper()}))
            signers.append([protected, kid, sig])
        payload = cbor.loads(payload)
        res = cbor.Tag(98, [b_protected, {}, payload[4], signers])
        data = cbor.dumps(res)
        return data

    @staticmethod
    def prepare_hsm_sign1(payload, algorithm):
        """Prepares COSE_Sign1 data for HSM signature"""
        alg = cbor.dumps(to_cose_header({'alg': algorithm.upper()}))
        sig_structure = ['Signature1', alg, b'', payload]
        return cbor.dumps(sig_structure)

    @staticmethod
    def prepare_hsm_sign(payload, algorithms):
        """Prepares COSE_Sign data for HSM signature"""
        structs_to_sign = []
        for alg in algorithms:
            alg = cbor.dumps(to_cose_header({'alg': alg}))
            sig_structure = ['Signature', b'', alg, b'', payload]
            structs_to_sign.append(cbor.dumps(sig_structure))
        return structs_to_sign

    @staticmethod
    def verify(data, key_path, kid=None):
        """Verifies COSE_Sign1 signature
        @param data: COSE_Sign1 data
        @param key_path: Verification key path
        @param kid: Key ID
        @return: True if verified, otherwise False
        """
        ctx = cwt.COSE.new()
        key = Cose._cose_key(key_path, kid=kid)
        try:
            ctx.decode(data, key)
        except cwt.exceptions.VerifyError:
            return False
        return True

    @staticmethod
    def _cose_key(key_path, kid=None):
        """Gets a COSE key based on JWK, PEM, or DER"""
        kid_encoded = Cose._cose_kid(kid)
        try:
            key = load_private_key(key_path)
        except ValueError:
            key = load_public_key(key_path)
        if isinstance(key, (rsa.RSAPrivateKey, rsa.RSAPublicKey)):
            alg = RSAHandler.alg(key)
            if RSAHandler.is_private_key(key):
                key = RSAHandler.private_pem(key)
            else:
                key = RSAHandler.public_pem(key)
        elif isinstance(
                key, (ec.EllipticCurvePrivateKey, ec.EllipticCurvePublicKey)):
            alg = ECHandler.alg(key)
            if ECHandler.is_private_key(key):
                key = ECHandler.private_pem(key)
            else:
                key = ECHandler.public_pem(key)
        else:
            raise ValueError(f"Unsupported key type {type(key)}")
        return cwt.COSEKey.from_pem(key, kid=kid_encoded, alg=alg)

    @staticmethod
    def _cose_kid(kid=None):
        if kid:
            if isinstance(kid, str):
                if kid.startswith('0x'):
                    kid_raw = int(kid, 16)
                    kid_encoded = kid_raw.to_bytes(number_size(kid_raw),
                                                   byteorder='little')
                else:
                    kid_encoded = kid.encode('utf-8')
            elif isinstance(kid, int):
                kid_encoded = kid.to_bytes(number_size(kid), byteorder='little')
            elif isinstance(kid, bytes):
                kid_encoded = kid
            else:
                raise ValueError(f"Unsupported 'kid' type {type(kid)}")
        else:
            kid_encoded = None
        return kid_encoded

    @staticmethod
    def dump(payload, output):
        """Dump data to a file
        @payload: CBOR data to save
        @output: Path to save file
        """
        dir_name = os.path.dirname(output)
        if dir_name:
            os.makedirs(dir_name, exist_ok=True)
        output = os.path.abspath(output)
        with open(output, 'wb') as fp:
            fp.write(payload)

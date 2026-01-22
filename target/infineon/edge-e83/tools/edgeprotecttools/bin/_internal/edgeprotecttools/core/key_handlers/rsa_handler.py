"""
Copyright 2021-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import hashlib
from collections import namedtuple

from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.hashes import SHA256
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import utils
from cryptography.hazmat.primitives.asymmetric import rsa
from jose.utils import long_to_base64

from ...core import strops
from . import load_private_key, load_public_key


class RSAHandler:
    """RSA signature and key operations"""

    @staticmethod
    def is_private_key(key):
        """ Gets a value indicating whether the key is a private key """
        if isinstance(key, str):
            try:
                p_key = load_private_key(key)
            except ValueError:
                p_key = load_public_key(key)
        else:
            p_key = key

        if not isinstance(p_key, (rsa.RSAPrivateKey, rsa.RSAPublicKey)):
            raise ValueError("Using RSA with key of another type")

        return isinstance(p_key, rsa.RSAPrivateKey)

    @staticmethod
    def public_numbers(key):
        """ Gets modulus, exponent, length of the RSA key """
        if isinstance(key, str):
            try:
                p_key = load_private_key(key)
            except ValueError:
                p_key = load_public_key(key)
        else:
            p_key = key

        try:
            pn = p_key.private_numbers().public_numbers
        except (AttributeError, ValueError):
            pn = p_key.public_numbers()

        PublicNumbers = namedtuple('PublicNumbers', 'modulus exponent length')

        return PublicNumbers(pn.n, pn.e, p_key.key_size)

    @staticmethod
    def sign(key, message):
        """Signs a message with a key
        @param key: The key object or key path
        @param message: The message to sign
        @return: Signature
        """
        if not isinstance(key, rsa.RSAPrivateKey):
            key = load_private_key(key)

        digest = hashlib.sha256(message).digest()
        sig = key.sign(digest,
                       padding.PSS(mgf=padding.MGF1(SHA256()),
                                   salt_length=padding.PSS.MAX_LENGTH),
                       utils.Prehashed(SHA256()))
        return sig

    @staticmethod
    def populate_public_key(exponent, modulus):
        """ Generates an RSA public key from the modulus and exponent """
        exponent = int(exponent, 16)
        modulus = int(modulus, 16)
        pubkey = rsa.RSAPublicNumbers(exponent, modulus).public_key(
            default_backend())
        return pubkey

    @staticmethod
    def convert_to_mbedtls(key_path, big_endian=True):
        """
        Extracts modulus and additional coefficients from RSA public key
        and converts to mbedtls format
        :param key_path: RSA key path (public or private)
        :param big_endian: Indicates whether to use big endian
        :return: RSA key in mbedtls format
        """
        public_numbers = RSAHandler.public_numbers(key_path)

        key_len = public_numbers.length
        modulus = hex(public_numbers.modulus).replace('0x', '')
        modulus_list = strops.split_by_n(modulus, 2)

        if not key_len:
            raise ValueError('Key length was not gotten by parsing')

        if len(modulus_list) != (key_len // 8):
            raise ValueError(f'The length of modulus ({key_len}) is not equal '
                             f'to the key length ({len(modulus_list) * 8})')

        coef = RSAHandler._calculate_additional_rsa_key_coefs(modulus)
        coef_list = RSAHandler._convert_hexstr_to_list(coef, not big_endian)
        coef_list = RSAHandler._align_byte_list(coef_list, 4, big_endian)
        lst = [('%02X' % x) for x in coef_list]
        result = '00000000' + modulus + ''.join(lst)

        return result

    @staticmethod
    def public_bytes(pubkey):
        """Encoding public key in DER format and return as byte sequence"""
        return pubkey.public_bytes(
            encoding=serialization.Encoding.DER,
            format=serialization.PublicFormat.PKCS1
        )

    @staticmethod
    def key_hash(pubkey):
        """Encoding public key and return as byte sequence"""
        pub = RSAHandler.public_bytes(pubkey)
        sha = hashlib.sha256()
        sha.update(pub)
        key_hash = sha.digest()
        return key_hash

    @staticmethod
    def _align_byte_list(lst, alignment, is_be):
        list_len = len(lst)
        if list_len % alignment != 0:
            pad = [0] * (alignment - (list_len % alignment))
            if is_be:
                lst = pad + lst
            else:
                lst = lst + pad

        return lst

    @staticmethod
    def _calculate_additional_rsa_key_coefs(modulo):
        """
        Calculates Barrett coefficient for modulo value of RSA key:
           Equation is: barretCoef = floor((2 << (2 * k)) / n);
           Main article: https://en.wikipedia.org/wiki/Barrett_reduction
        :param modulo: Part of RSA key
        :return: Barrett coefficient
        """
        if isinstance(modulo, str):
            modulo = int(modulo, 16)
        if modulo <= 0:
            raise ValueError('Modulus must be positive')
        if modulo & (modulo - 1) == 0:
            raise ValueError('Modulus must not be a power of 2')

        modulo_len = modulo.bit_length()
        barret_coef2 = (1 << (modulo_len * 2)) % modulo

        return barret_coef2

    @staticmethod
    def _validate_modulo(modulo):
        """Converts modulo to int if necessary and validates its value"""
        modulo = int(str(modulo), 16)
        if modulo <= 0:
            raise ValueError('Modulus must be positive')
        if modulo & (modulo - 1) == 0:
            raise ValueError('Modulus must not be a power of 2')

        return modulo

    @staticmethod
    def _calculate_barrett_coef(modulo):
        """
        Calculates Barrett coefficient.
            Equation is: barretCoef = floor((2 << (2 * k)) / n);
            Main article: https://en.wikipedia.org/wiki/Barrett_reduction
        """
        modulo = RSAHandler._validate_modulo(modulo)
        modulo_len = modulo.bit_length()
        barret_coef = (1 << (modulo_len * 2)) // modulo

        return barret_coef

    @staticmethod
    def _calculate_r_bar(modulo):
        """
        Calculates r_bar - pre-calculated value.
            Equation is: r_bar = (1 << k) mod n;
        """
        modulo = RSAHandler._validate_modulo(modulo)
        modulo_len = modulo.bit_length()
        r_bar = (1 << modulo_len) % modulo

        return r_bar

    @staticmethod
    def _calculate_inverse_modulo(modulo):
        """
        Calculates inverse modulo coefficient.
            It satisfies  rr' - nn' = 1, where r = 1 << k;
            Main article is here:
            https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
        """
        modulo = RSAHandler._validate_modulo(modulo)
        _, n_inv = RSAHandler._extended_euclid(modulo)

        return n_inv

    @staticmethod
    def _convert_hexstr_to_list(s, reverse=False):
        """
        Converts a string likes '0001aaff...' to list [0, 1, 170, 255].
        Also an input parameter can be an integer, in this case it will be
        converted to a hex string
        :param s: String to convert
        :param reverse: A returned list have to be reversed
        :return: A list of an integer values
        """
        if isinstance(s, (int,)):
            s = hex(s)
        s = s[2 if s.lower().startswith('0x') else 0: -1 if s.upper().endswith('L') else len(s)]
        if len(s) % 2 != 0:
            s = '0' + s
        lst = [int('0x%s' % s[i:i + 2], 16) for i in range(0, len(s), 2)]
        if reverse:
            lst.reverse()

        return lst

    @staticmethod
    def _list_to_c_array(inp_list):
        """
        Converts a list to a C-style array of hexadecimal numbers string
        :param inp_list: List to convert
        :return: A C-style array string
        """
        c_array = ''
        for i, element in enumerate(inp_list):
            if i % 8 == 0:
                c_array += '\n    ' if i > 0 else '    '
            c_array += f'0x{int(hex(element), 16):02X}u'
            if i < len(inp_list) - 1:
                c_array += ', '

        return c_array

    @staticmethod
    def _extended_euclid(modulo):
        """
        Calculate greatest common divisor (GCD) of two values.
        Link: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
            formula to calculate: ax + by - gcd(a,b)
        parameters:
            a, b - two values witch is calculated GCD for.
        return:
            absolute values of x and y coefficients

        NOTE: pseudo-code of operation:
            x, last_X = 0, 1
            y, last_Y = 1, 0
            while (b != 0):
                q = a // b
                a, b = b, a % b
                x, last_X = last_X - q * x, x
                y, last_Y = last_Y - q * y, y
            return (abs(last_X), abs(last_Y))
        """

        r_inv = 1
        n_inv = 0
        modulo_bit_size = modulo.bit_length()

        for _ in range(modulo_bit_size):
            if not r_inv % 2:
                r_inv = r_inv // 2
                n_inv = n_inv // 2
            else:
                r_inv = r_inv + modulo
                r_inv = r_inv // 2
                n_inv = n_inv // 2
                n_inv = n_inv + (1 << (modulo_bit_size - 1))
        return r_inv, n_inv

    @staticmethod
    def private_jwk(priv_key, kid=None):
        """ Gets RSA private key is JSON format """
        key_json = {
            'kty': 'RSA',
            'n': long_to_base64(
                priv_key.public_key().public_numbers().n
            ).decode('utf-8'),
            'e': long_to_base64(
                priv_key.public_key().public_numbers().e
            ).decode('utf-8'),
            'd': long_to_base64(
                priv_key.private_numbers().d
            ).decode('utf-8'),
            'p': long_to_base64(
                priv_key.private_numbers().p
            ).decode('utf-8'),
            'q': long_to_base64(
                priv_key.private_numbers().q
            ).decode('utf-8'),
            'dp': long_to_base64(
                priv_key.private_numbers().dmp1
            ).decode('utf-8'),
            'dq': long_to_base64(
                priv_key.private_numbers().dmq1
            ).decode('utf-8'),
            'qi': long_to_base64(
                priv_key.private_numbers().iqmp
            ).decode('utf-8'),
            'alg': RSAHandler.alg(priv_key)
        }
        if kid:
            key_json['kid'] = str(kid)
        return key_json

    @staticmethod
    def private_pem(priv_key: rsa.RSAPrivateKey):
        """Converts private key to PEM format"""
        return priv_key.private_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PrivateFormat.PKCS8,
            encryption_algorithm=serialization.NoEncryption()
        )

    @staticmethod
    def public_jwk(pubkey, kid=None):
        """ Gets EC public key is JSON format """
        key_json = {
            'kty': 'RSA',
            'n': long_to_base64(
                pubkey.public_numbers().n
            ).decode('utf-8'),
            'e': long_to_base64(
                pubkey.public_numbers().e
            ).decode('utf-8'),
            'alg': RSAHandler.alg(pubkey)
        }
        if kid:
            key_json['kid'] = str(kid)
        return key_json

    @staticmethod
    def public_pem(pub_key: rsa.RSAPublicKey):
        """Converts public key to PEM format"""
        return pub_key.public_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PublicFormat.SubjectPublicKeyInfo
        )

    @staticmethod
    def rsa2secureboot(key, is_reverse=True):
        """
        Generates RSA public key modulus, exponent, and additional coefficients
        and formats it as Secure boot RSA public key format
        """
        if not isinstance(key, rsa.RSAPublicKey):
            raise ValueError('The expected key type is RSA public')

        header_lines = [
            '#include "cmsis_compiler.h"',
            '#include "cy_crypto_common.h"',
            '#include "cy_si_config.h"',
            '#include "cy_si_keystorage.h"',
            '#include "cy_syslib.h"',
            '',
            '/** Publickey in SFlash */',
            'CY_SECTION(".cy_sflash_public_key") __USED '
            'const cy_si_stc_public_key_t cy_publicKey =',
            '{',
            '    .objSize = sizeof(cy_si_stc_public_key_t),',
            '    .signatureScheme = 0UL,',
            '    .publicKeyStruct =',
            '    {',
            '        .moduloAddr         = CY_SI_PUBLIC_KEY '
            '+ offsetof(cy_si_stc_public_key_t, moduloData),',
            '        .moduloSize         = '
            'CY_SI_PUBLIC_KEY_SIZEOF_BYTE * CY_SI_PUBLIC_KEY_MODULOLENGTH,',
            '        .expAddr            = CY_SI_PUBLIC_KEY '
            '+ offsetof(cy_si_stc_public_key_t, expData),',
            '        .expSize            = '
            'CY_SI_PUBLIC_KEY_SIZEOF_BYTE * CY_SI_PUBLIC_KEY_EXPLENGTH,',
            '        .barrettAddr        = CY_SI_PUBLIC_KEY '
            '+ offsetof(cy_si_stc_public_key_t, barrettData),',
            '        .inverseModuloAddr  = CY_SI_PUBLIC_KEY '
            '+ offsetof(cy_si_stc_public_key_t, inverseModuloData),',
            '        .rBarAddr           = CY_SI_PUBLIC_KEY '
            '+ offsetof(cy_si_stc_public_key_t, rBarData)',
            '    },'
        ]

        modulus_list = list(
            int.to_bytes(key.public_numbers().n,
                         byteorder='big',
                         length=key.key_size // 8)
        )

        modulus_hex_str = f'{key.public_numbers().n:x}'
        exp_hex_str = f'{key.public_numbers().e:x}'

        barret = RSAHandler._calculate_barrett_coef(modulus_hex_str)
        inv_modulo = RSAHandler._calculate_inverse_modulo(modulus_hex_str)
        r_bar = RSAHandler._calculate_r_bar(modulus_hex_str)

        barret_list = RSAHandler._convert_hexstr_to_list(barret, is_reverse)

        barret_list = ([0] * 3 + barret_list) if not is_reverse else (
                    barret_list + [0] * 3)

        barret_str = RSAHandler._list_to_c_array(barret_list)
        barret_str = f'.barrettData =\n{{\n{barret_str}\n}},'

        inv_modulo_list = RSAHandler._convert_hexstr_to_list(f'{inv_modulo:x}',
                                                             is_reverse)
        inv_modulo_str = RSAHandler._list_to_c_array(inv_modulo_list)
        inv_modulo_str = f'.inverseModuloData =\n{{\n{inv_modulo_str}\n}},'

        r_bar_list = RSAHandler._convert_hexstr_to_list(f'{r_bar:x}',
                                                        is_reverse)
        r_bar_str = RSAHandler._list_to_c_array(r_bar_list)
        r_bar_str = f'.rBarData =\n{{\n{r_bar_str}\n}}'

        exp_list = RSAHandler._convert_hexstr_to_list(exp_hex_str, is_reverse)
        exp_list_len = len(exp_list)

        if is_reverse:
            exp_list = exp_list + [0] * (4 - (exp_list_len % 4))
        else:
            exp_list = [0] * (4 - (exp_list_len % 4)) + exp_list

        exp_str = RSAHandler._list_to_c_array(exp_list)
        exp_str = f'.expData =\n{{\n{exp_str}\n}},'

        if is_reverse:
            modulus_list.reverse()
        modulus_str = RSAHandler._list_to_c_array(modulus_list)
        modulus_str = f'.moduloData =\n{{\n{modulus_str}\n}},'

        header = '\n'.join(header_lines) + '\n'

        content = '\n'.join(
            (modulus_str, exp_str, barret_str, inv_modulo_str, r_bar_str)
        )
        content = '    ' + content.replace('\n', '\n    ') + '\n'

        footer = '};\n'

        return header + content + footer

    @staticmethod
    def rsa_np(key):
        """Calculates Np from RSA key"""
        if isinstance(key, rsa.RSAPublicKey):
            pubkey = key
        elif isinstance(key, rsa.RSAPrivateKey):
            pubkey = key.public_key()
        elif isinstance(key, str):
            pubkey = load_public_key(key)
        else:
            raise ValueError('Unsupported key type')

        new_pka_word_size = 64
        new_pka_additional = 8
        snp = pubkey.key_size + new_pka_word_size + new_pka_additional - 1
        modulus = pubkey.public_numbers().n
        r = pow(2, snp)
        np = r // modulus

        return np

    @staticmethod
    def alg(priv_key):
        if priv_key.key_size == 2048:
            alg = 'RS256'
        elif priv_key.key_size == 3072:
            alg = 'RS384'
        elif priv_key.key_size == 4096:
            alg = 'RS512'
        else:
            raise ValueError(f'Unsupported key size {priv_key.key_size}')
        return alg

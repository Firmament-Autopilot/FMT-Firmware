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
import os
import re
import logging
import hashlib
import shutil
import sys

from cryptography.hazmat.primitives.asymmetric import ec, rsa, x25519
from intelhex import IntelHex, HexRecordError

from .core.certificate_strategy import CertAdapterV1
from .core.connect_helper import ConnectHelper
from .core.cose import Cose
from .core.deprecated import deprecated
from .core.exceptions import ValidationError
from .core.key_handlers.ec_handler import ECHandler
from .core.key_handlers.rsa_handler import RSAHandler
from .core.target_director import TargetDirector
from .core.ocd_settings import OcdSettings
from .core.project_base import ProjectInitializerBase
from .core.logging_configurator import LoggingConfigurator
from .core.signtool_base import SignToolBase
from .core.strategy_context import (
    ProvisioningPacketCtx, ProvisioningContext, CertificateContext
)
from .core.enums import (
    ValidationStatus, ProvisioningStatus, KeyAlgorithm, KeyPair
)
from .core.key_handlers import (
    emit_c, key_encoding_and_format, load_public_key, load_private_key)
from .execute.combine_sign_tool import (CommandJsonValidator,
                                        CommandProcessor,
                                        CommandGroupParser)
from .execute.ihex2hcd import hex2hcd
from .execute.image_signing import MergeTool, SplitTool, SignTool, MultiImage
from .execute.keygens import (ec_keygen, rsa_keygen, aes_keygen,
                              x25519_keygen, lms_keygen)
from .execute.programmer.dfuht_wrapper import Dfuht
from .execute.programmer.programmer import ProgrammingTool
from .execute.encryption import EncryptorAES, XipEncryptor
from .execute.cbor_parser import CborParser
from .execute import dump
from .execute.x509 import X509CertificateGenerator
from .execute.combine_sign_tool.symbol_adapter import SymbolAdapter
from .execute.combine_sign_tool.symbol_file_finder import SymbolFileFinder
from .execute.hex_relocator import HexRelocator
from .pkg_globals import PkgData
from .targets import get_target_builder, print_targets, is_mxs40v1, is_mxs40sv2

LoggingConfigurator.initialize_console_logger()
logger = logging.getLogger(__name__)


class CommonAPI:
    """A class containing common API for all targets"""

    def __init__(self, target=None, policy=None, log_file=True,
                 skip_prompts=False, skip_validation=False, rev=None,
                 alt_user_dir=None, timestamps=False):

        self._policy = None
        self.skip_validation = skip_validation
        self.skip_prompts = skip_prompts

        if timestamps:
            LoggingConfigurator.console_handler.formatter.enable_timestamps()

        PkgData.alt_pkg_user_data_dir = alt_user_dir

        if log_file:
            LoggingConfigurator.initialize_file_logger()
            logger.debug(sys.argv)

        self.inited = True
        if not target:
            self.inited = False
            self.target = None
            if ProjectInitializerBase.is_project():
                settings = OcdSettings()
                self.tool = ProgrammingTool.create(settings.ocd_name, settings)
            else:
                self.tool = None
            return

        if not os.path.isfile(PkgData.pkg_settings()):
            os.makedirs(PkgData.pkg_user_data_dir(), exist_ok=True)
            shutil.copyfile(
                os.path.join(PkgData.pkg_data_dir(), 'global_settings.json'),
                PkgData.pkg_settings())

        self.target_name = target.lower().strip()

        if policy is not None:
            self._policy = os.path.abspath(policy)
        if ProjectInitializerBase.is_project():
            if policy is None:
                self._policy = ProjectInitializerBase.get_default_policy()

        self.target = self._get_target(
            self.target_name, self._policy, os.getcwd(), rev=rev)
        self.tool = self._init_ocd()
        self._policy = self.target.policy
        self.policy_parser = self.target.policy_parser
        self.version_provider = self.target.version_provider

        ConnectHelper.re_init()

    @property
    def policy(self):
        return self._policy

    @policy.setter
    def policy(self, policy):
        self._policy = policy
        self.target.policy = policy
        self.target.policy_parser.initialize(policy)

    def build_ramapp_package(self, app, output, key=None,
                             hex_addr=None, slot_size=None, **kwargs):
        """Builds RAM application package
        @param app: Path to a RAM application
        @param output: Output file where to save the package
        @param key: Key to sign the package
        @param hex_addr: Address in hex format
        @param slot_size: Slot size
        """
        if not self.target or not self.target.provisioning_packet_strategy:
            logger.error('Building RAM application packages is not supported '
                         'for the selected target')
            return False

        if not hex_addr:
            hex_addr = self.target.memory_map.DLM_BASE_ADDR
            logger.info('Default hex address = %s', hex(hex_addr))

        if not slot_size:
            slot_size = self.target.memory_map.DLM_SLOT_SIZE

        ctx = ProvisioningPacketCtx(self.target.provisioning_packet_strategy)
        try:
            return ctx.create_package(self.target, app=app, output=output,
                                      key=key, hex_addr=hex_addr,
                                      slot_size=slot_size, **kwargs)
        except NotImplementedError:
            logger.error('Building RAM application packages is not supported '
                         'for the selected target')
            return False

    def create_cert(self, output, **kwargs):
        """Creates certificate from JSON template
        @param output: Path where to save the created CBOR certificate
        @param kwargs:
            :template: Certificate template path
            :csr: Path where to save the certificate
            :key_path: Private key path to sign certificate
            :json_cert: Path where to save JSON certificate
        @return: Certificate object
        """
        if not self.target or not self.target.certificate_strategy:
            logger.error('Creating certificates is not supported '
                         'for the selected target')
            return False

        context = CertificateContext(self.target.certificate_strategy)
        return context.create_certificate(output, None, None, dev_cert='cert',
                                          **kwargs)

    def oem_csr(self, output, key_path, **kwargs):
        """Creates certificate signing request
        @param output: Path where to save the created OEM CSR
        @param key_path: The key path tuple with the private key_0, key_1 paths
        @param kwargs:
            :certificate_name: The name of the certificate
            :oem: The OEM name
            :project: The OEM project name
            :project_number: The OEM project number
            :issuer: The issuer name
            :signer_id: Signer unique ID
            :pub_key_0: Public key 0 path or HEX value
            :pub_key_1: Public key 1 path or HEX value
            :date: The date of the OEM certificate creation (auto-generated if not provided)
            :cert_type: Defines the "LCS" of the project development or production
            :cert_id: A unique S/N for this certificate (b0 applicable)
            :rev: Device revision value
            :algorithm: Key algorithm. Applicable values: ES256, ES384, ES512
            :use_adapter: Use the certificate adapter to convert CLI arguments to dictionary
        @return CSR object
        """
        if not self.target or not self.target.certificate_strategy:
            logger.error('Creating certificates is not supported '
                         'for the selected target')
            return False

        template = None
        if kwargs.get('use_adapter'):
            create = CertAdapterV1()
            template = create.oem_csr(key_path=key_path, **kwargs)
        context = CertificateContext(self.target.certificate_strategy)
        return context.create_csr(output, key_path, template=template, **kwargs)

    def ifx_oem_cert(self, output, **kwargs):
        """Creates certificate
        @param output: Path where to save the created IFX OEM certificate
        @param kwargs:
            :certificate_name: The name of the certificate
            :csr: Path where to save the certificate
            :issuer: The issuer name
            :signer_id: Signer unique ID
            :date: The date of the OEM certificate creation
            (auto-generated if not provided)
            :cert_id: A unique S/N for this certificate
            :rev: Device revision value
            :algorithm: Key algorithm. Applicable values: ES256, ES384, ES512
            :key_path: Private key path to sign certificate
            :signer_id: Signer unique ID
            :use_adapter: Use the certificate adapter to convert CLI arguments to dictionary
        @return: Certificate object
        """
        if not self.target or not self.target.certificate_strategy:
            logger.error('Creating certificates is not supported '
                         'for the selected target')
            return False

        template = None
        if kwargs.get('use_adapter'):
            create = CertAdapterV1()
            template = create.oem_cert(**kwargs)
        context = CertificateContext(self.target.certificate_strategy)
        return context.create_certificate(output, None, None, dev_cert='oem',
                                          template=template, **kwargs)

    def run_config(self, infile, variable=None, symbol=None, symbol_search=None):
        """
        Executes commands specified in a JSON file with variable
        interpolation.

        Parameters:
            infile (str): Path to the JSON file containing commands.
            variable (tuple, optional): Tuple of (name, value) pairs
                for variable interpolation.
            symbol (str, list, optional): Path(s) to symbol file(s)
                providing additional variables for interpolation.
            symbol_search (str, list, optional): Path(s) to a directory
                to search for symbol files.

        Variable sources (variable, symbol, symbol_search) are merged for
        interpolation. Variable names must be unique across all sources;
        duplicates will raise an error.

        Returns:
            bool: True if all commands executed successfully, False
                otherwise.
        """
        if variable is None:
            variable = ()

        symbols = []
        symbols.extend(SymbolFileFinder.discover_symbol_files(symbol))
        symbols.extend(SymbolFileFinder.discover_symbol_files(symbol_search))
        if symbols:
            adapted = SymbolAdapter.adapt(symbols)
            variable = SymbolAdapter.merge(variable, adapted)

        command_group_parser = CommandGroupParser(infile)
        json_validator = CommandJsonValidator(command_group_parser)

        validation_status = json_validator.validate_by_schema('root')
        if validation_status != ValidationStatus.OK:
            return False
        
        command_group_parser.interpolate(self.__create_interpolation_map(variable))
        cmd_groups = command_group_parser.parse()
        
        if not cmd_groups:
            logger.error('%s: Parser returned an empty list of groups',
                         __name__)
            return False

        for grp in cmd_groups:
            for cmd_data in grp.command_data:
                validation_status = json_validator.validate_command(cmd_data)
                if validation_status != ValidationStatus.OK:
                    return False

        cmd_processor = CommandProcessor(cmd_groups)
        res = cmd_processor.execute_all()
        return res

    def power_on(self, voltage=2500, probe_id=None):
        """Turns on the power and sets voltage
        @param voltage: Voltage level
        @param probe_id: Probe serial number
        @return: True if the target powering was successful,
        otherwise False
        """
        return ConnectHelper.power_on(self.tool, self.target, voltage,
                                      probe_id=probe_id)

    def power_off(self, probe_id=None):
        """Turns on the target and sets voltage
        @param probe_id: Probe serial number
        @return: True if the target was successfully powered off,
        otherwise False
        """
        return ConnectHelper.power_off(self.tool, self.target,
                                       probe_id=probe_id)

    @staticmethod
    def hash(path, alg, output=None):
        """Calculates payload digest
        @param path: Input data path
        @param alg: Hash algorithm
        @param output: Binary (.bin) or text file to save the hash
        @return: Digest in bytes format
        """

        if alg.lower() == 'sha1':
            h = hashlib.sha1()
        elif alg.lower() == 'sha224':
            h = hashlib.sha224()
        elif alg.lower() == 'sha256':
            h = hashlib.sha256()
        elif alg.lower() == 'sha384':
            h = hashlib.sha384()
        elif alg.lower() == 'sha512':
            h = hashlib.sha512()
        elif alg.lower() == 'md5':
            h = hashlib.md5()
        else:
            raise ValueError(f'Hash algorithm is not supported: {alg}')

        with open(path, 'rb') as f:
            payload = f.read()

        h.update(payload)
        digest = h.digest()

        if not output:
            logger.info(digest.hex())
        elif output.endswith('.bin'):
            with open(output, 'wb') as f:
                f.write(digest)
        else:
            with open(output, 'w', encoding='utf-8') as f:
                f.write(digest.hex())

        return digest

    @staticmethod
    def bin2hex(image, output, offset=0):
        """Converts bin to hex
        @param image: Input binary file
        @param output: Output hex file
        @param offset: Starting address offset for loading bin
        """
        result = SignToolBase.bin2hex(image, output, offset=offset)
        if result:
            logger.info("Saved converted file to '%s'", output)
        return result

    @staticmethod
    def hex2bin(image, output, start=None, end=None, size=None, pad=None):
        """Converts hex to bin
        @param image: Input hex file
        @param output: Output binary file
        @param start: Start of address range
        @param end: End of address range
        @param size: Size of resulting file (in bytes)
        @param pad: Padding byte
        @return: True if success
        """
        result = SignToolBase.hex2bin(image, output, start=start, end=end,
                                      size=size, pad=pad)
        if result:
            logger.info("Saved converted file to '%s'", output)
        return result

    @staticmethod
    def hex2hcd(infile, outfile):
        """Converts Intel HEX to Infineon HCD format
        @param infile: Input Intel HEX file
        @param outfile: Output HCD file
        @return: True if success, otherwise False
        """
        try:
            hex2hcd(infile, outfile)
        except (FileNotFoundError, RuntimeError) as e:
            logger.error(e)
            return False
        logger.info("Saved converted file to '%s'", os.path.abspath(outfile))
        return True

    @staticmethod
    def cbor2json(image, output=None, indent=2, **kwargs):
        """Converts CBOR to JSON
        @param image: Input binary file
        @param output: Output file
        @param indent: JSON file indent
        """
        offset = kwargs.get('offset', 0)
        d = CborParser.convert(image, offset)

        serialized = json.dumps(d, indent=indent)

        p = re.compile(r'"h\'[0-9a-fA-F]*\'"|"0x[0-9a-fA-F]+"|"TAG\(\d+\)"')
        serialized = p.sub(lambda x: x.group().strip('"'), serialized)

        if output:
            with open(output, 'w', encoding='utf-8') as f:
                f.write(serialized)
            logger.info("Saved to '%s'", output)
        else:
            logger.info('\n%s', serialized)

        return serialized

    @staticmethod
    def cose_sign(input_path, output, **kwargs):
        """A COSE signed message
        @param input_path: The payload path to sign
        @param output: Path to save
        @param kwargs:
            :param key: Key path or a tuple of primary and secondary key paths
            :param kid: Key ID or a tuple of key IDs
            :param signature: Signature path or a tuple of primary and secondary
                              signature paths
            :param algorithm: Signature algorithm or tuple of algorithms
        @return: COSE multiple signers data object
        """
        try:
            ihex = IntelHex(os.path.abspath(input_path))
            payload = ihex.tobinarray().tobytes()
        except (UnicodeDecodeError, TypeError, HexRecordError):
            with open(os.path.abspath(input_path), 'rb') as f:
                payload = f.read()
        key = kwargs.get('key')
        kid = kwargs.get('kid')
        signature = kwargs.get('signature')
        cose_signed = None
        if isinstance(key, tuple) and all(key):
            cose_signed = Cose.cose_sign(payload, key, kid)
        elif not isinstance(key, (tuple, type(None))):
            cose_signed = Cose.cose_sign1(payload, key, kid)
        else:
            alg = kwargs.get('algorithm')
            if isinstance(signature, tuple) and all(signature):
                sigs = []
                for sig in signature:
                    with open(sig, 'rb') as f:
                        sigs.append(f.read())
                cose_signed = Cose.add_signature(payload, tuple(sigs), alg, kid)
            elif not isinstance(signature, (tuple, type(None))):
                with open(signature, 'rb') as f:
                    sig = f.read()
                cose_signed = Cose.add_signature1(payload, sig, alg, kid)
            elif isinstance(alg, tuple) and all(alg):
                if alg[0] != alg[1]:
                    raise ValueError('Different algorithms are not allowed')
                cose_signed = Cose.prepare_hsm_sign(payload, alg)
                cose_signed = cose_signed[0]
            elif not isinstance(alg, (tuple, type(None))):
                cose_signed = Cose.prepare_hsm_sign1(payload, alg)

        if not cose_signed:
            raise ValueError("Either key(s), algorithm(s) "
                             "or signature(s) is expected")

        Cose.dump(cose_signed, output)
        logger.info("COSE signed message created '%s'", os.path.abspath(output))
        return cose_signed

    @staticmethod
    def cose_verify(input_path, key, kid=None):
        """A COSE message verification
        @param input_path: The payload path to sign
        @param key: Public key path
        @param kid: Key ID
        @return: True if verification pass
        """
        with open(os.path.abspath(input_path), 'rb') as f:
            payload = f.read()
        status = Cose.verify(payload, key, kid=kid)
        if not status:
            logger.error('COSE sign verification failed')
        else:
            logger.info('COSE sign verification success')
        return status

    def create_keys(self, alg, output, fmt=None, **kwargs):
        """Creates ECDSA, RSA, AES keys
        @param alg: User key type
        @param output: Output directory for the generated keys
        @param fmt: Output key format (PEM, DER, JWK)
        @param kwargs:
          :template: JSON template path
          :kid: Key ID
        @return: True if key(s) created successfully, otherwise False.
        """
        key_algorithms = [
            'ECDSA-P256', 'ECDSA-P384', 'ECDSA-P521', 'X25519',
            'RSA2048', 'RSA3072', 'RSA4096', 'AES128', 'AES256'
        ]

        if alg.upper() not in key_algorithms:
            valid_types = ",".join(key_algorithms)
            raise ValueError(
                f"Invalid key type '{alg}'. "
                f"Supported key types: '{valid_types}'")

        if fmt is None and alg.upper() not in ('AES128', 'AES256'):
            raise ValueError('Output key format must be specified')

        key_param = self.__key_param(alg)

        if isinstance(output, str):
            output = (output,)
        if len(output) == 2:
            keys = KeyPair(output[0], output[1])
            if keys.private == keys.public:
                raise ValueError('Same path for private and public keys')
        elif kwargs.get('template'):
            keys = KeyPair(output[0], output[0])
        elif alg != KeyAlgorithm.AES:
            keys = KeyPair(None, output[0])
        else:
            keys = None

        keys_exist = False
        for key_path in output:
            keys_exist = os.path.isfile(key_path)
            if keys_exist:
                logger.warning("Key already exists '%s'",
                               os.path.abspath(key_path))
        if keys_exist:
            if not self.skip_prompts:
                answer = input('Overwrite? (y/n): ')
                if answer.lower() != 'y':
                    logger.info('Terminated by user')
                    return True

        # Generate keys
        if alg in (KeyAlgorithm.ECDSA_P256, KeyAlgorithm.ECDSA_P384,
                   KeyAlgorithm.ECDSA_P521):
            private_key, public_key = ec_keygen.generate_key(
                key_param, template=kwargs.get('template'),
                byteorder=kwargs.get('byteorder', 'big')
            )
            if keys.private and private_key:
                ec_keygen.save_key(
                    private_key, keys.private, fmt, kid=kwargs.get('kid'),
                    password=kwargs.get('password')
                )
                logger.info("Created a key '%s'", os.path.abspath(keys.private))
            if keys.public and public_key:
                ec_keygen.save_key(public_key, keys.public, fmt,
                                   kid=kwargs.get('kid'))
                logger.info("Created a key '%s'", os.path.abspath(keys.public))
        elif alg in (KeyAlgorithm.RSA2048,
                     KeyAlgorithm.RSA3072,
                     KeyAlgorithm.RSA4096):
            private_key, public_key = rsa_keygen.generate_key(
                key_param, template=kwargs.get('template'))
            if keys.private and private_key:
                rsa_keygen.save_key(
                    private_key, keys.private, fmt, kid=kwargs.get('kid'),
                    password=kwargs.get('password')
                )
                logger.info("Created a key '%s'", os.path.abspath(keys.private))
            if keys.public and public_key:
                rsa_keygen.save_key(public_key, keys.public, fmt,
                                    kid=kwargs.get('kid'))
                logger.info("Created a key '%s'", os.path.abspath(keys.public))
        elif alg in (KeyAlgorithm.AES128, KeyAlgorithm.AES256):
            aes_keygen.generate_key(
                key_size=key_param, add_iv=False, output=output[0])
        elif alg == KeyAlgorithm.X25519:
            if not keys.private:
                raise ValueError('Private key path is not specified')
            if not keys.public or keys.public == keys.private:
                raise ValueError('Public key path is not specified')
            private, public = x25519_keygen.generate_key()
            x25519_keygen.save_key(private, keys.private, fmt,
                                   password=kwargs.get('password'))
            logger.info("Created a key '%s'", os.path.abspath(keys.private))
            x25519_keygen.save_key(public, keys.public, fmt)
            logger.info("Created a key '%s'", os.path.abspath(keys.public))
        return True

    def create_keys_lms(self, lms_type, lmots_type, output):
        """Creates LMS key pair
        @param lms_type: LMS key type
        @param lmots_type: LM-OTS key type
        @param output: Tuple or list with private and public key paths"""
        if not isinstance(output, (tuple, list)):
            raise ValueError('Incorrect output path data format')
        if len(output) != 2:
            raise ValueError('No path for private or public keys')

        keys_exist = False
        for key_path in output:
            keys_exist = os.path.isfile(key_path)
            if keys_exist:
                logger.warning("Key already exists '%s'",
                               os.path.abspath(key_path))
        if keys_exist and (not self.skip_prompts):
            answer = input('Overwrite ? (y/n): ')
            if answer.lower() != 'y':
                logger.info('Terminated by user')
                return True

        private_path, public_path = output

        if private_path == public_path:
            raise ValueError('Same path for private and public keys')

        try:
            private, public = lms_keygen.generate_key(lms_type, lmots_type)
        except ValueError as e:
            raise ValueError(f'Failed to create LMS key: {e}') from e

        if private and public:
            try:
                lms_keygen.save_key(private, private_path)
                lms_keygen.save_key(public, public_path)
            except (ValueError, OSError) as e:
                raise ValueError(f"Unable to save keys: {e}") from e

            logger.info("Created an LMS private key '%s'",
                        os.path.abspath(private_path))
            logger.info("Created an LMS public key '%s'",
                        os.path.abspath(public_path))
        else:
            raise ValueError('Missing data for key generation')

        return True

    @staticmethod
    def convert_key(key, enc_fmt, **kwargs):
        """Converts key to other formats
        @param key: Key cryptography object
        @param enc_fmt: Output key file encoding and format separated by a dash
        @param kwargs:
            endian - Indicates byte order
            output - Path to output file
        """
        password = kwargs.get('password')
        var_name = kwargs.get("var_name")
        output = kwargs.get('output')
        if output is None:
            raise ValueError('Output path is not specified')

        if isinstance(key, str):
            key = SignTool.load_key(key, password=password)

        key_encoding, key_format = key_encoding_and_format(enc_fmt)

        if key_encoding == 'C_ARRAY':
            if isinstance(key, (
                    ec.EllipticCurvePrivateKey, ec.EllipticCurvePublicKey,
                    rsa.RSAPrivateKey, rsa.RSAPublicKey,
                    x25519.X25519PrivateKey, x25519.X25519PublicKey)):
                result = emit_c(
                    key, key_format, password=password, var_name=var_name
                )
            else:
                raise ValueError('The expected key types are: '
                                 'RSA, ECDSA, or X25519')

            with open(output, 'w', encoding='utf-8') as f:
                f.write(result)
            logger.info("Created a file '%s'", os.path.abspath(output))

        elif key_encoding == 'SECURE_BOOT':
            result = RSAHandler.rsa2secureboot(
                key, kwargs.get('endian') == 'little'
            )
            with open(output, 'w', encoding='utf-8') as f:
                f.write(result)
            logger.info("Created a file '%s'", os.path.abspath(output))

        elif key_encoding == 'X962':
            if not isinstance(key, ec.EllipticCurvePublicKey):
                raise ValueError('The expected key type is ECDSA public')

            public_bytes = ECHandler.raw_format(key)

            with open(output, 'wb') as f:
                f.write(public_bytes)
            logger.info("Created a file '%s'", os.path.abspath(output))

        elif key_encoding in ('PEM', 'DER', 'JWK'):
            if isinstance(key, (rsa.RSAPrivateKey, rsa.RSAPublicKey)):
                rsa_keygen.save_key(key, output, key_encoding, fmt=key_format,
                                    password=password)
                logger.info("Created a key '%s'", os.path.abspath(output))
            elif isinstance(key, (ec.EllipticCurvePrivateKey,
                                  ec.EllipticCurvePublicKey)):
                ec_keygen.save_key(key, output, key_encoding, fmt=key_format,
                                   password=password)
                logger.info("Created a key '%s'", os.path.abspath(output))
            elif isinstance(key, (x25519.X25519PrivateKey,
                                  x25519.X25519PublicKey)):
                x25519_keygen.save_key(key, output, key_encoding,
                                       fmt=key_format, password=password)
                logger.info("Created a key '%s'", os.path.abspath(output))
            else:
                raise TypeError('Unexpected key type')

        else:
            raise ValueError('Unknown conversion format')

    @staticmethod
    def export_public_key(key, fmt, **kwargs):
        """ Exports public key from the private one
        @param key: Key object or key path
        @param fmt: Output key file format
        @param kwargs:
            output - Path to output file
        """

        output = kwargs.get('output')

        if isinstance(key, str):
            key = SignTool.load_key(key)

        if fmt.lower() in ['pem', 'der', 'der-pkcs8', 'jwk']:
            if isinstance(key, rsa.RSAPrivateKey):
                if fmt.lower() not in ('pem', 'der', 'jwk'):
                    raise ValueError('The expected format is one of: '
                                     'PEM, DER, JWK')
                if output:
                    rsa_keygen.save_key(key.public_key(), output, fmt)
                    logger.info("Created a key '%s'", os.path.abspath(output))
            elif isinstance(key, ec.EllipticCurvePrivateKey):
                if output:
                    ec_keygen.save_key(key.public_key(), output, fmt)
                    logger.info("Created a key '%s'", os.path.abspath(output))
            else:
                raise ValueError('Unexpected key type')

            return key.public_key()

        else:
            raise ValueError('Unknown conversion format')

    @staticmethod
    def encrypt_aes(image, output, key, iv, add_iv, iv_output,
                    cipher_mode, nonce=None):
        """Encrypts file with AES
        @param image: User file
        @param output: Output file
        @param key: Path to key
        @param iv: Input vector or nonce (auto, path or hex)
        @param add_iv: Adds IV to the start of the encrypted file
        @param iv_output: Saves IV to bin file
        @param cipher_mode: Cipher mode (ECB, CBC or CTR)
        @param nonce: Nonce value (for ECB mode only)
        @return: None
        """

        if iv.lower() == 'auto':
            iv = os.urandom(16)
        elif iv.lower().startswith('0x'):
            if cipher_mode == 'ECB':
                iv = int(str(iv), 0)
            else:
                iv = bytes.fromhex(iv[2:])
        else:
            with open(iv, 'rb') as f:
                iv = f.read()

        with open(image, 'rb') as f:
            payload = f.read()

        with open(key, 'rb') as f:
            key = f.read()

        if cipher_mode == 'ECB':
            encryptor = XipEncryptor(
                initial_counter=iv, nonce=nonce, plainkey=key
            )
            encrypted = encryptor.encrypt(payload)
        else:
            encrypted = EncryptorAES.encrypt(payload, key, iv, cipher_mode)
        del key

        with open(output, 'wb') as f:
            f.write(iv + encrypted if add_iv else encrypted)

        logger.info("Saved encrypted file to '%s'", os.path.abspath(output))

        if iv_output:
            with open(iv_output, 'wb') as f:
                f.write(iv)
            logger.info("Saved IV to '%s'", os.path.abspath(iv_output))

    def sign_image(self, image, image_id=None, **kwargs):
        """Signs firmware image
        @param image: User application file
        @param image_id: The ID of the image in the policy file
        @return: A path to the signed (optionally encrypted) image
        """
        if self.target:
            if self.validate_policy(['pre_build', 'dap_disabling']):
                return self.target.sign_tool.sign_image(
                    image, image_id=image_id, **kwargs)
            return None
        return SignTool().sign_image(image, **kwargs)

    def image_metadata(self, image, **kwargs):
        """Creates a complete MCUboot format image
        @param image: User application file
        @return: Extended (and encrypted if applicable) file path
        """
        if self.target:
            return self.target.sign_tool.add_metadata(image, **kwargs)
        return SignTool().add_metadata(image, **kwargs)

    def extract_payload(self, image, output):
        """Extracts from the image a part that has to be signed
        @param image: User application file
        @param output: A file where to save the payload
        @return: Path to the image with the payload
        """
        if self.target:
            self.target.sign_tool.extract_payload(image, output)
        else:
            SignTool.extract_payload(image, output=output)

    def add_signature(self, image, signature, output, alg=None):
        """Adds signature to MCUboot format image
        @param image: User application file
        @param signature: Path to the binary file containing signature
        @param output: Path where to save the signed image
        @param alg: Signature algorithm
        @return: Path to the output image
        """
        if self.target:
            self.target.sign_tool.add_signature(image, signature, output=output)
        else:
            SignTool.add_signature(image, signature, alg, output=output)

    def verify_image(self, image, **kwargs):
        """Verifies image with a key
        @param image: Image path
        @param kwargs:
            :key: Verification key
        @return: True if success, otherwise False
        """
        return SignTool.verify_image(image, kwargs.get('key'))

    @staticmethod
    def merge_hex(images, output, **kwargs):
        """Merges two different hex files into one
        @param images: Input files
        @param output: Output file
        @param kwargs:
            :overlap: Action on overlap of data or starting address
        """
        MergeTool.merge_hex(images, output=output, **kwargs)
        logger.info("Saved merged file to '%s'", os.path.abspath(output))

    @staticmethod
    def merge_bin(images, output):
        """Merges two different hex files into one
        @param images: Input files
        @param output: Output file
        """
        MergeTool.merge_bin(images, output=output)
        logger.info("Saved merged file to '%s'", os.path.abspath(output))

    @staticmethod
    def hex_dump(image, output, address, size, erased_val=0):
        """Extracts data from the specified address
        @param image: Hex file path
        @param address: Data start address
        @param size: Data size
        @param output: Bin file path where to save the data
        @param erased_val: Value to fill the spaces between the segments
        """
        return dump.hex_dump(image, int(str(address), 0), int(str(size), 0),
                             output=output, padding=erased_val)

    @staticmethod
    def bin_dump(data, output):
        """Converts a hex string to bytes and saves to a binary file
        @param data: Hex string to dump
        @param output: Output file
        @return: True if success, otherwise False
        """
        if 'random' in data:
            data = os.urandom(int(data.replace('random', ''), 0))

        if len(data) % 2 != 0:
            logger.error(
                'The hex string must contain an even number of characters')
            return False

        try:
            dump.bin_dump(data, output)
        except ValueError:
            logger.error('Non-hexadecimal number specified')
            return False

        logger.info("Data saved to '%s'", os.path.abspath(output))
        return True

    @staticmethod
    def hex_segment(image, addr, output):
        """Merges two different hex files into one
        @param image: Input files
        @param addr: Address of the segment
        @param output: Output file
        """
        if SplitTool.get_segment(image, addr, output=output):
            logger.info("Saved segment with address 0x%08X to '%s'",
                        int(str(addr), 0), os.path.abspath(output))
            return True
        logger.error('Segment with address 0x%08X not found', int(str(addr), 0))
        return False

    @staticmethod
    def hex_relocate(input_file, output_file, regions):
        """
        Relocate segments in a hex file to new address regions.
        :param input_file: Path to input HEX file.
        :param output_file: Path to output HEX file.
        :param regions: List of (start, size, dest) tuples.
        :return: Value returned by relocate_file (usually None).
        """
        result = HexRelocator.relocate_file(input_file, output_file, regions)
        if result:
            logger.info("Saved file to '%s'", output_file)
        return result

    @staticmethod
    def multi_image_cbor(input_path, output, key, **kwargs):
        """Creates a multi-image COSE packet
        @param input_path: The path to the hex image
        @param output: Path to save
        @param key: Key path
        @param kwargs:
            :erased_val: Value to fill the spaces between the segments
            :segment: Pairs of segment start address and size to include
            :signature: Signature to add
            :algorithm: Signature algorithm to prepare packet
                        for signing on HSM
        @return: COSE multi-image packet
        """

        packet = MultiImage(input_path, output, key=key, **kwargs).create()

        return packet

    def create_provisioning_packet(self, **kwargs):
        """Creates a packet for device provisioning
        @return: True if packet created successfully, otherwise False
        """
        if not self.validate_policy(**kwargs):
            return False
        ctx = ProvisioningPacketCtx(self.target.provisioning_packet_strategy)
        return ctx.create(self.target, **kwargs)

    def provision_device(self, probe_id=None, ap='cm4', **kwargs):
        """Executes device provisioning - the process of creating device
        identity, attaching policy and bootloader
        @param probe_id: Probe serial number
        @param ap: The access port used for provisioning
        @return: Provisioning result. True if success, otherwise False
        """
        if not kwargs.get('existing_packet') and not self.validate_policy():
            return False

        # Get bootloader program file
        if self.target.bootloader_provider is None:
            bootloader = None
        else:
            bootloader = self.target.bootloader_provider.hex_path()
            if not os.path.isfile(bootloader):
                logger.error("Cannot find bootloader file '%s'", bootloader)
                return False

        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap=ap):
            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)

            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.provision(
                self.tool, self.target, bootloader=bootloader,
                probe_id=self.tool.probe_id, ap=ap,
                skip_prompts=self.skip_prompts, **kwargs)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('Error occurred while provisioning device')

        return status == ProvisioningStatus.OK

    def re_provision_device(self, probe_id=None, ap='sysap', **kwargs):
        """Executes device re-provisioning
        @param probe_id: Probe serial number
        @param ap: The access port used for re-provisioning
        @return: Re-provisioning result. True if success, otherwise False
        """
        if not kwargs.get('existing_packet') and not self.validate_policy():
            return False

        # Get bootloader program file
        bootloader = None
        if not kwargs.get('skip_bootloader', False):
            if self.target.bootloader_provider is not None:
                bootloader = self.target.bootloader_provider.hex_path()
                if not os.path.isfile(bootloader):
                    logger.error(
                        "Cannot find bootloader file '%s'", bootloader)
                    return False

        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap=ap):

            if not self.target.version_provider.check_compatibility(self.tool):
                ConnectHelper.disconnect(self.tool)
                return False
            self.target.version_provider.log_version(self.tool)

            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.re_provision(
                self.tool, self.target, bootloader=bootloader,
                probe_id=self.tool.probe_id, **kwargs)
            ConnectHelper.disconnect(self.tool)
        else:
            status = ProvisioningStatus.FAIL

        if status == ProvisioningStatus.FAIL:
            logger.error('Error occurred while reprovisioning device')

        return status == ProvisioningStatus.OK

    def init(self, **kwargs):
        """Initializes new project"""
        cwd = os.getcwd()
        overwrite = True if self.skip_prompts else None
        self.target.project_initializer.init(cwd, overwrite, **kwargs)

    def print_version(self, probe_id=None, ap='sysap', acquire=True, **kwargs):
        """Outputs firmware version bundled with the package
        @param probe_id: Probe serial number
        @param ap: The access port used to read data from device
        """
        connected = False
        try:
            connected = ConnectHelper.connect(
                self.tool, self.target, ap=ap, probe_id=probe_id,
                acquire=acquire)
        except ValueError as e:
            logger.error(e)
        self.target.version_provider.print_version(**kwargs)
        if connected:
            if self.target.version_provider.check_compatibility(
                    self.tool, check_si_rev=False):
                self.target.version_provider.print_fw_version(self.tool)
            ConnectHelper.disconnect(self.tool)

    def read_die_id(self, probe_id=None, ap='sysap', acquire=True):
        """Reads die ID
        @param probe_id: Probe serial number
        @param ap: The access port used to read the data
        @param acquire: Enable acquire device
        @return: Die ID if success, otherwise None
        """
        die_id = None
        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id,
                                 ap=ap, acquire=acquire):
            if self.target.version_provider.check_compatibility(
                    self.tool, check_si_rev=False):
                self.target.version_provider.log_version(self.tool)
                die_id = self.target.silicon_data_reader.read_die_id(self.tool)
            ConnectHelper.disconnect(self.tool)
        return die_id

    def get_device_info(self, probe_id=None, ap='sysap', acquire=True):
        """Gets silicon ID, silicon revision, family ID
        @param probe_id: Probe serial number
        @param ap: The access port used to read the data
        @param acquire: Enable acquiring device
        @return: Device info if success, otherwise None
        """
        connected = ConnectHelper.connect(self.tool, self.target,
                                          probe_id=probe_id, ap=ap,
                                          acquire=acquire)
        info = None
        if connected:
            info = self.target.silicon_data_reader.read_device_info(self.tool)
            ConnectHelper.disconnect(self.tool)
        return info

    def get_device_lifecycle(self, probe_id=None, ap='sysap', alt_name=False):
        """Reads device lifecycle stage
        @param probe_id: Probe serial number
        @param ap: The access port used to read the data
        @param alt_name: Indicates whether to use LCS alternative name
        @return: Lifecycle stage name if success, otherwise None
        """
        if is_mxs40v1(self.target_name):
            raise NotImplementedError('Not supported by the selected target')
        lifecycle = None
        if ConnectHelper.connect(
                self.tool, self.target, probe_id=probe_id, ap=ap):
            lifecycle = self.target.version_provider.get_lifecycle_stage(
                self.tool, alt_name=alt_name)
            ConnectHelper.disconnect(self.tool)
        return lifecycle

    def get_probe_list(self):
        """Gets list of all connected probes"""
        return self.tool.get_probe_list()

    def debug_certificate(self, template, output, key_id=0, key_path=None,
                          **kwargs):
        """Creates debug or RMA certificate binary from the
        certificate template
        @param template:
            Path to the certificate template in JSON format
        @param output:
            The certificate binary output file
        @param key_id:
            The key ID to sign the certificate. Uses key path from the policy.
        @param key_path:
            Path to the private key file used to sign the certificate.
            Overrides key_id argument
        @param kwargs:
            non_signed - Indicates that debug certificate will not be signed
            signature - Path to the signature which will be used to sign
                        an existing certificate
            unsigned_cert - Path to the unsigned certificate which was
                            generated with 'non_signed' option
        """
        sign_cert = not kwargs.get('non_signed')
        signature = kwargs.get('signature')
        if signature:
            unsigned_cert = kwargs.get('unsigned_cert')
            cert = self.target.debug_certificate.add_signature(unsigned_cert,
                                                               signature,
                                                               output)
        else:
            key = None
            if key_path is not None:
                key = key_path
            elif sign_cert:
                if key_id is not None:
                    key = self.target.key_source.get_key(key_id, 'private')
            else:
                if key_id is not None:
                    key = self.target.key_source.get_key(key_id, 'public')

            cert = self.target.debug_certificate.create(template, key, output,
                                                        sign_cert, **kwargs)
        return cert

    def get_extended_boot_info(self, probe_id=None, ap='sysap', acquire=True):
        """Get extended boot info
        @param probe_id: Probe serial number
        @param ap: The access port used to read the data
        @param acquire: Enable acquire device
        @return: Int. data of the extended boot mode and status.
        """
        connected = ConnectHelper.connect(self.tool, self.target,
                                          probe_id=probe_id, ap=ap,
                                          acquire=acquire)
        mode = None
        status = None
        if connected and not isinstance(self.tool, Dfuht):
            mode, status = self.target.silicon_data_reader.read_extended_boot_info(self.tool)
        ConnectHelper.disconnect(self.tool)
        return mode, status

    @staticmethod
    def device_list():
        """Prints a list of supported devices"""
        print_targets()
        return True

    @deprecated('convert_to_rma() is deprecated. Use transit_to_rma() instead.')
    def convert_to_rma(self, probe_id=None, ap='sysap', **kwargs):
        """DEPRECATED: use transit_to_rma instead"""
        return self.transit_to_rma(probe_id=probe_id, ap=ap, **kwargs)

    def transit_to_rma(self, probe_id=None, ap='sysap', **kwargs):
        """
        Transits device to the RMA lifecycle stage
        @param probe_id: Probe serial number
        @param ap: The access port used for communication
        @param kwargs:
               :cert: Transit to RMA certificate
        @return: True if success, otherwise False
        """
        status = ProvisioningStatus.FAIL
        cert = kwargs.get('cert')
        del kwargs['cert']
        if ConnectHelper.connect(self.tool, self.target,
                                 probe_id=probe_id, ap=ap):
            self.version_provider.log_version(self.tool)
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.transit_to_rma(self.tool, self.target, cert,
                                            **kwargs)
            ConnectHelper.disconnect(self.tool)
        return status == ProvisioningStatus.OK

    def open_rma(self, cert, probe_id=None):
        """
        Enables full access to device in RMA lifecycle stage
        @param cert: Open RMA certificate
        @param probe_id: Probe serial number
        @return: True if success, otherwise False
        """
        if is_mxs40sv2(self.target_name):
            raise NotImplementedError('Not supported by the selected target')
        status = ProvisioningStatus.FAIL
        if ConnectHelper.connect(self.tool, self.target, probe_id=probe_id):
            context = ProvisioningContext(self.target.provisioning_strategy)
            status = context.open_rma(self.tool, self.target, cert)
            ConnectHelper.disconnect(self.tool)
        return status == ProvisioningStatus.OK

    @staticmethod
    def x509_certificate(**kwargs):
        """Creates X.509 certificate
        @param kwargs:
            :config: The path to the certificate configuration file
            :key_path: The path to the certificate signing key
            :output: Path to the output certificate
            :encoding: Certificate encoding format (PEM, DER)
            :output: Path to the output certificate file
        @return: Certificate object
        """
        generator = X509CertificateGenerator(
            kwargs.get('config'),
            csr=kwargs.get('csr'),
            ca_cert=kwargs.get('ca_cert'),
            self_signed=kwargs.get('self_signed')
        )

        if generator.csr and not generator.verify_csr():
            raise ValueError('CSR verification failed')

        certificate = generator.generate(kwargs.get('signing_key'),
                                         password=kwargs.get('password'))
        output = kwargs.get('output')
        if output:
            output = os.path.abspath(output)
            generator.save_certificate(output, encoding=kwargs.get('encoding'))
            logger.info("Certificate saved to '%s'", output)
        return certificate

    @staticmethod
    def verify_x509_certificate(certificate, verifier):
        """Verifies X.509 certificate.
        @param certificate: Certificate to verify
        @param verifier: Key, CA certificate, or CSR
        @return: True if success, otherwise False
        """
        if isinstance(certificate, str):
            try:
                certificate = X509CertificateGenerator.load_cert(certificate)
            except ValueError:
                logger.error('Invalid file format: %s',
                             os.path.abspath(certificate))
                return False

        if isinstance(verifier, str):
            verifier = os.path.abspath(verifier)
            try:
                pubkey = load_public_key(verifier)
                logger.info('Verifying with public key: %s', verifier)
            except ValueError:
                try:
                    key = load_private_key(verifier)
                    pubkey = key.public_key()
                    logger.info('Verifying with public key: %s', verifier)
                except ValueError:
                    try:
                        cert = X509CertificateGenerator.load_cert(verifier)
                        pubkey = cert.public_key()
                        logger.info('Verifying with certificate: %s', verifier)
                    except ValueError:
                        try:
                            csr = X509CertificateGenerator.load_csr(verifier)
                            pubkey = csr.public_key()
                            logger.info('Verifying with CSR: %s', verifier)
                        except ValueError:
                            logger.error('Invalid file format: %s', verifier)
                            return False
        else:
            pubkey = verifier

        try:
            X509CertificateGenerator.verify_cert(certificate, pubkey)
            logger.info('Certificate verification success')
            return True
        except ValidationError as e:
            logger.error(e)
            logger.error('Certificate verification failed')
            return False

    def _init_ocd(self):
        settings = OcdSettings()
        try:
            tool = ProgrammingTool.create(settings.ocd_name, settings)
        except KeyError as e:
            error = f'Unsupported On-Chip debugger {e}'
            if ProjectInitializerBase.is_project():
                default_ocd = self.target.ocds[0]
                logger.warning(error)
                if self.skip_prompts:
                    logger.info('Skip user interactive prompts option enabled')
                    answer = 'y'
                else:
                    answer = input(f"Change to '{default_ocd}'? (y/n): ")
                if answer.lower() == 'y':
                    path = ProjectInitializerBase.get_ocd_data().path
                    config = ProjectInitializerBase.get_ocd_data().config
                    if not path and not self.skip_prompts:
                        path = input(f"Path to '{default_ocd}' root directory: ")
                    ProjectInitializerBase.set_ocd_data(
                        default_ocd, path, config)
                    logger.info("Changed active OCD to '%s'", default_ocd)
                    settings = OcdSettings()
                    tool = ProgrammingTool.create(settings.ocd_name, settings)
                else:
                    raise ValueError(error) from e
            else:
                raise ValueError(error) from e
        return tool

    def validate_policy(self, skip_list=None, **kwargs):
        """Validates policy if specified and policy validator
        for the target is defined"""
        if self.policy and not os.path.isfile(self.policy):
            raise ValueError(f"Cannot find policy file '{self.policy}'")
        if self.target.policy_validator is None:
            return True
        if self.target.is_default_policy:
            logger.warning('The policy is not specified. The default policy '
                           'will be used (%s)', self.target.policy)
        self.target.policy_validator.skip_validation = self.skip_validation
        validation_state = self.target.policy_validator.validate(
            skip=skip_list,
            skip_prompts=self.skip_prompts, **kwargs)
        return validation_state not in [ValidationStatus.ERROR,
                                        ValidationStatus.TERMINATED]

    def _get_target(self, target_name, policy, cwd, rev=None):
        director = TargetDirector()
        self.target_builder = get_target_builder(director, target_name, rev=rev)
        return director.get_target(policy, cwd)

    @staticmethod
    def __key_param(key_type):
        if key_type == 'ECDSA-P256':
            param = ec.SECP256R1()
        elif key_type == 'ECDSA-P384':
            param = ec.SECP384R1()
        elif key_type == 'ECDSA-P521':
            param = ec.SECP521R1()
        elif key_type == 'RSA2048':
            param = 2048
        elif key_type == 'RSA3072':
            param = 3072
        elif key_type == 'RSA4096':
            param = 4096
        elif key_type == 'AES128':
            param = 16
        elif key_type == 'AES256':
            param = 32
        elif key_type == 'X25519':
            param = None
        else:
            raise ValueError(f"Invalid key type '{key_type}'")
        return param

    @staticmethod
    def __create_interpolation_map(variable):
        interpolation_map = {}
        for k, v in variable:
            if not re.fullmatch(r'\w+', k):
                raise SyntaxError(f"Invalid variable name '{k}'. "
                                  f"Only alphanumeric and underscore "
                                  f"are allowed")
            if k in interpolation_map:
                logger.warning('Overwriting variable: %s', k)
            interpolation_map[k] = v
        return interpolation_map


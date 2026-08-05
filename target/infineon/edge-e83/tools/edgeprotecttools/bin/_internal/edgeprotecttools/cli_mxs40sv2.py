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
import os
import sys
import json
import logging
import binascii
import click

from .core.connect_helper import ConnectHelper
from .core.enums import KeyAlgorithm
from .cli import main, process_handler
from .execute.imgtool.main import get_dependencies

logger = logging.getLogger(__name__)


@main.command('create-key', help='Creates private and public key pair')
@click.option('-k', '--key-id', type=click.Choice(['0', '1']),
              help='OEM key ID')
@click.option('--overwrite/--no-overwrite', 'overwrite', is_flag=True,
              default=None,
              help='Indicates whether overwrite a key if it already exists')
@click.option('--aes', is_flag=True, default=False,
              help='Specify to generate an AES key')
@click.option('--key-path', type=click.Path(),
              help='Specify to generate a key into a specific path')
@click.option('-o', '--output', type=click.Path(), multiple=True, nargs=2,
              metavar='[private] [public]',
              help='Key pair output files. Provide private and public key '
                   'paths. Specify the option multiple times to create '
                   'multiple key pairs. Overrides --key-id option')
@click.option('--template', type=click.Path(),
              help='A JSON file containing public key modulus and exponent')
@click.option('--hash-path', type=click.Path(),
              help='A path where to save the public key hash')
@click.pass_context
def cmd_create_key(ctx, key_id, overwrite, aes, key_path, output, template,
                   hash_path):
    @process_handler()
    def process():
        validate_key_source_args()
        if 'TOOL' not in ctx.obj:
            return False
        user_key_alg = KeyAlgorithm.AES if aes else KeyAlgorithm.RSA
        result = ctx.obj['TOOL'].create_keys(
            overwrite=overwrite, out=output if output else key_path,
            kid=None if output or key_id is None else int(key_id),
            user_key_alg=user_key_alg, template=template,
            hash_path=os.path.abspath(hash_path) if hash_path else None)
        return result

    def validate_key_source_args():
        errors = list()
        info = None
        app = os.path.basename(sys.argv[0])

        e1 = 'Usage example:\n# To create an encryption key in the path ' \
             'specified in the policy file\n' \
             f'{app} -t <TARGET> -p <POLICY> create-key --aes\n' \
             '# To create an encryption key in the custom path\n' \
             f'{app} -t <TARGET> -p <POLICY> create-key --aes --key-path ' \
             f'<KEY_PATH>'

        e2 = 'Usage example:\n# To create a private/public key pair in the ' \
             'path specified in the policy file\n' \
             f'{app} -t <TARGET> -p <POLICY> create-key --key-id 0\n' \
             '# To create a private/public key pair in the custom path\n' \
             f'{app} -t <TARGET> -p <POLICY> create-key -o <PRIV_KEY_PATH> ' \
             f'<PUB_KEY_PATH>'

        if all(not v for v in [key_id, aes, output, template]):
            errors.append(
                "Missing required options. One of the following options must "
                "be specified: '--key-id', '--aes', '--output', '--template'.")
        elif aes:
            if output or key_id or hash_path:
                errors.append("The '--aes' option is applicable with the "
                              "following options only: '--key-path'.")
            if errors:
                info = e1
        elif key_id:
            if output or key_path:
                errors.append("The '--key-id' option cannot be used with "
                              "the options '--output' and '--key-path'. There "
                              "must be a single source of the key path - "
                              "either a policy or a command line.")
                info = e2
        elif output:
            if key_path:
                errors.append("The '--key-path' and '--output' options are "
                              "mutually exclusive.")
        if template:
            if output or key_id or aes:
                errors.append("The '--template' option is applicable with the "
                              "following options only: '--key-path'.")
            if not key_path:
                errors.append("Missing '--key-path' option.")

        if errors:
            for e in errors:
                sys.stderr.write(f'Error: {e}\n')
            if info:
                print(info)
            sys.exit(2)

    return process


@main.command('version', short_help='Show BootROM version')
@click.option('--probe-id', 'probe_id', type=click.STRING, default=None,
              help='Probe serial number')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_version(ctx, probe_id, testapps, testapps_si):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_testapps_args(testapps, testapps_si)
        ctx.obj['TOOL'].print_version(
            probe_id, testapps=test_pkg_type(testapps, testapps_si))
        return True

    return process


@main.command('create-provisioning-packet',
              help='Creates binary packet for device provisioning')
@click.option('-k', '--key-id', type=click.Choice(['0', '1']),
              help='OEM private key ID used to sign the reprovisioning packet')
@click.option('--key-path', type=click.Path(),
              help='The key used to sign the reprovisioning packet. '
                   'Overrides --key-id option')
@click.option('--signature', type=click.Path(),
              help='The name of the file containing the signature')
@click.option('--pubkey', type=click.Path(),
              help='The public key to be added to the reprovisioning packet')
@click.option('--non-signed', is_flag=True, default=None,
              help='The flag indicating that reprovisioning packet '
                   'will not be signed')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_create_provisioning_packet(ctx, key_id, key_path, signature, pubkey,
                                   non_signed, testapps, testapps_si):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_args()
        return ctx.obj['TOOL'].create_provisioning_packet(
            key_id=None if key_path or key_id is None else int(key_id),
            key_path=key_path, signature=signature, pubkey=pubkey,
            non_signed=non_signed,
            testapps=test_pkg_type(testapps, testapps_si))

    def validate_args():

        def print_error():
            if error:
                sys.stderr.write(f'Error: {error}\n')
                sys.exit(2)

        error = None
        from .targets.common.mxs40sv2.enums import PolicyType
        policy_type = ctx.obj['TOOL'].policy_parser.policy_type()

        if PolicyType.REPROVISIONING_SECURE == policy_type:
            if all(v is None for v in [key_id, key_path, signature,
                                       non_signed]):
                error = "One of the following options must be " \
                        "specified: '--key-id', '--key-path', " \
                        "'--signature', '--non-signed'."
        else:
            if any(v for v in [key_id, key_path, signature, non_signed, pubkey]):
                error = "The following options  are applicable to " \
                        "reprovisioning secure policy type only: " \
                        "'--key-id', '--key-path', '--signature', " \
                        "'--non-signed', '--pubkey'."

        print_error()

        if sum(x is not None for x in
               [key_id, key_path, signature, non_signed]) > 1:
            error = "The options '--key-id', '--key-path', " \
                    "'--signature', '--non-signed' are mutually exclusive."
        elif (key_id or key_path or signature) and pubkey:
            error = "The '--pubkey' option is applicable with the following " \
                    "options only: '--non-signed'."
        elif non_signed and not pubkey:
            error = "Missing required option '--pubkey'."

        print_error()

        validate_testapps_args(testapps, testapps_si)

    return process


@main.command('prov-packet-to-policy',
              help='Creates a policy file based on application input '
                   'parameters. The command is for debugging purpose',
              short_help='Creates a policy file based on application input '
                         'parameters. The command is for debugging purpose')
@click.option('--packet', type=click.Path(), required=True,
              help='Binary with input parameters')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The file where to save the policy')
@click.pass_context
def cmd_prov_packet_to_policy(ctx, packet, output):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].prov_packets_to_policy([packet], output)

    return process


@main.command('provision-device', help='Executes device provisioning')
@click.option('--probe-id', 'probe_id', type=click.STRING, default=None,
              help='Probe serial number')
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_provision_device(
        ctx, probe_id, existing_packet, testapps, testapps_si):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_args()
        if existing_packet:
            result = True
        else:
            policy_type = ctx.obj['TOOL'].policy_parser.policy_type()
            if 'reprovisioning' in policy_type:
                logger.error('Reprovisioning policy type specified for '
                             'the provisioning operation')
                return False
            result = ctx.obj['TOOL'].create_provisioning_packet(
                testapps=test_pkg_type(testapps, testapps_si))
        if result:
            result = ctx.obj['TOOL'].provision_device(
                probe_id=probe_id, ap='sysap',
                testapps=test_pkg_type(testapps, testapps_si))
        return result

    def validate_args():
        if not ctx.obj['TOOL'].policy:
            sys.stderr.write("Error: Missing option '--policy'.\n")
            sys.exit(2)
        validate_testapps_args(testapps, testapps_si)

    return process


@main.command('reprovision-device', help='Executes device reprovisioning')
@click.option('-k', '--key-id', type=click.Choice(['0', '1']),
              help='OEM private key ID used to sign the reprovisioning packet')
@click.option('--key-path', type=click.Path(),
              help='OEM private key used to sign the reprovisioning packet. '
                   'Overrides --key-id option')
@click.option('--signature', type=click.Path(),
              help='The name of the file containing the signature')
@click.option('--probe-id', type=click.STRING, required=False, default=None,
              help='Probe serial number')
@click.option('--existing-packet', is_flag=True,
              help='Skip reprovisioning packet creation and use the existing')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_re_provision_device(ctx, key_id, key_path, signature, probe_id,
                            existing_packet, testapps, testapps_si):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        validate_policy_type()
        validate_args()

        result = True
        if not existing_packet:
            result = ctx.obj['TOOL'].create_provisioning_packet(
                key_id=None if key_path or key_id is None else int(key_id),
                key_path=key_path, signature=signature,
                testapps=test_pkg_type(testapps, testapps_si))

        if result:
            result = ctx.obj['TOOL'].re_provision_device(
                probe_id, testapps=test_pkg_type(testapps, testapps_si))
        return result

    def validate_args():
        error = None
        from .targets.common.mxs40sv2.enums import PolicyType
        policy_type = ctx.obj['TOOL'].policy_parser.policy_type()

        if existing_packet:
            if any(v for v in [key_id, key_path, signature]):
                error = "The options '--key-id', '--key-path', " \
                        "'--signature' are not applicable when " \
                        "the existing packet is used."
        elif PolicyType.REPROVISIONING_SECURE == policy_type:
            if all(v is None for v in [key_id, key_path, signature]):
                error = "One of the following options must be " \
                        "specified to sign the reprovisioning packet: " \
                        "'--key-id', '--key-path', '--signature'."
            elif sum(x is not None for x in [key_id, key_path, signature]) > 1:
                error = "The options '--key-id', '--key-path', and " \
                        "'--signature' are mutually exclusive."

        if error:
            sys.stderr.write(f'Error: {error}\n')
            sys.exit(2)

        validate_testapps_args(testapps, testapps_si)

    def validate_policy_type():
        from .targets.common.mxs40sv2.enums import PolicyType
        policy_type = ctx.obj['TOOL'].policy_parser.policy_type()
        if policy_type not in [PolicyType.REPROVISIONING_SECURE,
                               PolicyType.REPROVISIONING_NO_SECURE]:
            sys.stderr.write('Error: Provisioning policy type specified for '
                             'the reprovisioning operation\n')
            sys.exit(2)

    return process


@main.command('device-info',
              help='Reads device information - silicon ID, family ID, silicon '
                   'revision',
              short_help='Reads device information - silicon ID, family ID, '
                         'silicon revision')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.pass_context
def cmd_device_info(ctx, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        status = True
        ConnectHelper.do_not_disconnect = True
        dev_info = ctx.obj['TOOL'].get_device_info(probe_id)
        ConnectHelper.do_not_disconnect = False
        lifecycle = ctx.obj['TOOL'].get_device_lifecycle(probe_id)

        logger.info('*' * 39)
        if dev_info:
            logger.info(
                'Silicon: 0x%x, Family: 0x%0x, Rev.: 0x%0x',
                dev_info.silicon_id, dev_info.family_id, dev_info.silicon_rev)
        else:
            logger.error('Failed to read Silicon ID, Family, Rev.')
            status = False

        if lifecycle:
            logger.info('Chip lifecycle stage: %s', lifecycle)
        else:
            logger.error('Failed to read chip lifecycle stage')
            status = False

        return status

    return process


@main.command('sign-image',
              short_help='Signs the user application with a key. Optionally '
                         'encrypts the signed application',
              help='Signs the user application with a key. Optionally '
                   'encrypts the signed application')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='User application file. The output file format is based on '
                   'the input file extension (bin or hex)')
@click.option('-k', '--key-id', type=click.Choice(['0', '1']),
              help='OEM private key ID used to sign the image')
@click.option('--key-path', type=click.Path(),
              help='The key used to sign the image. Overrides the --key-id '
                   'option')
@click.option('-R', '--erased-val',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value that is read back from erased flash')
@click.option('--image-config', type=click.Path(), hidden=True,
              help='Path to the image configuration file')
@click.option('-o', '--output', type=click.Path(),
              help='Signed image output file')
@click.option('--signature', type=click.Path(),
              help='The name of the file containing the signature')
@click.option('-H', '--header-size', help='Sets image header size')
@click.option('-S', '--slot-size', help='Sets maximum slot size')
@click.option('--encrypt', is_flag=True, help='Encrypt the output image')
@click.option('--enckey', type=click.Path(),
              help='The key used to encrypt the image')
@click.option('--app-addr',
              help='Base address of the application. Used for encryption')
@click.option('--hex-addr', help='Adjust address in hex output file')
@click.option('--update-key-id', type=click.Choice(['0', '1']),
              help='OEM private key ID used to sign the update data packet')
@click.option('--update-key-path', type=click.Path(),
              help='The key used to sign the update data packet. Overrides '
                   'the --update-key-id option')
@click.option('-f', '--image-format', type=click.Choice(
              ['bootrom_ram_app', 'bootrom_next_app', 'mcuboot_user_app']),
              default='mcuboot_user_app',
              help='Defines the image format. Values: bootrom_ram_app - RAM '
                   'application; bootrom_next_app - external memory '
                   'application started by BootROM; mcuboot_user_app - '
                   'application started by MCUBoot. Default: mcuboot_user_app')
@click.option('--pad', is_flag=True, help='Add padding to the image trailer')
@click.option('--confirm', is_flag=True, help='Add image OK status to trailer')
@click.option('--overwrite-only', is_flag=True, default=None,
              help='Use Overwrite mode instead of Swap')
@click.option('--min-erase-size', help='Sets minimum erase size')
@click.option('--align', type=click.Choice(['1', '2', '4', '8']), default='8',
              help='Flash alignment')
@click.option('-v', '--version',
              help='Sets image version in the image header')
@click.option('-d', '--dependencies', callback=get_dependencies,
              required=False, help='''Add dependence on another image, format:
              "(<image_ID>,<image_version>), ... "''')
@click.option('--image-id', type=click.INT, help='Image ID', default=0)
@click.option('--nonce',
              help='A hex string or a file containing nonce used for '
                   'encryption. If not provided, a random value will be '
                   'generated')
@click.option('--nonce-output', type=click.Path(),
              help='The path to a file where to save the nonce')
@click.pass_context
def cmd_sign_image(ctx, image, erased_val, key_id, key_path, image_config,
                   output, signature, header_size, slot_size, encrypt, enckey,
                   app_addr, hex_addr, update_key_id, update_key_path,
                   image_format, pad, confirm, overwrite_only, min_erase_size,
                   align, version, dependencies, image_id, nonce, nonce_output):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        if signature:
            with open(signature, 'rb') as f:
                s = binascii.hexlify(f.read()).decode(sys.stdout.encoding)
            from .execute.imgtool.image import TLV_VALUES
            tlv = [(str(TLV_VALUES['RSA2048']), f'0x{s}')]
            result = ctx.obj['TOOL'].extend_image(
                image, tlv=tlv, output=output, header_size=0)
        else:
            validate_key_args()
            result = ctx.obj['TOOL'].sign_image(
                image,
                key_id=None if key_path or key_id is None else int(key_id),
                key_path=key_path,
                erased_val=erased_val,
                image_config=image_config,
                output=output,
                header_size=header_size,
                slot_size=slot_size,
                encrypt=encrypt,
                enckey=enckey,
                app_addr=app_addr,
                hex_addr=hex_addr,
                update_key_id=
                None if update_key_path or update_key_id is None else int(
                    update_key_id),
                update_key_path=update_key_path,
                image_format=image_format,
                pad=pad,
                confirm=confirm,
                overwrite_only=overwrite_only,
                min_erase_size=min_erase_size,
                align=align,
                version=version,
                dependencies=dependencies,
                image_id=image_id,
                nonce=nonce,
                nonce_output=nonce_output
                )
        return result is not None

    def validate_key_args():
        if key_id is None and key_path is None:
            sys.stderr.write("Either '--key-id' or '--key-path' option must "
                             "be specified.\n")
            sys.exit(2)
        elif key_id and key_path:
            sys.stderr.write("The '--key-id' and '--key-path' options are "
                             "mutually exclusive.\n")
            sys.exit(2)

        from .targets.common.mxs40sv2.enums import PolicyType
        policy_type = ctx.obj['TOOL'].policy_parser.policy_type()
        if policy_type == PolicyType.REPROVISIONING_SECURE:
            validate_update_key(update_key_id, update_key_path)

    return process


@main.command('extend-image', help='Extends firmware image with the TLVs',
              short_help='Extends firmware image with the TLVs')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='User application file. The output file format is based on '
                   'the input file extension (bin or hex)')
@click.option('--pubkey', type=click.Path(),
              help='The public key to be added to the image')
@click.option('-R', '--erased-val',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value that is read back from erased flash')
@click.option('--image-config', type=click.Path(), hidden=True,
              help='Path to the image configuration file')
@click.option('-o', '--output', type=click.Path(),
              help='Extended image output file')
@click.option('--protected-tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='Custom TLV that will be placed into a protected area. '
                   'Add the "0x" prefix if the value should be interpreted '
                   'as an integer, otherwise it will be interpreted as a '
                   'string. Specify the option multiple times to add multiple '
                   'TLVs')
@click.option('-H', '--header-size', help='Sets image header size')
@click.option('-S', '--slot-size', help='Sets maximum slot size')
@click.option('--hex-addr', help='Adjust address in hex output file')
@click.option('-f', '--image-format', type=click.Choice(
              ['bootrom_ram_app', 'bootrom_next_app', 'mcuboot_user_app']),
              default='mcuboot_user_app',
              help='Defines the image format. Values: bootrom_ram_app - RAM '
                   'application; bootrom_next_app - external memory '
                   'application started by BootROM; mcuboot_user_app - '
                   'application started by MCUBoot. Default: mcuboot_user_app')
@click.option('--pad', is_flag=True, help='Add padding to the image trailer')
@click.option('--confirm', is_flag=True, help='Add image OK status to trailer')
@click.option('--overwrite-only', is_flag=True, default=None,
              help='Use Overwrite mode instead of Swap')
@click.option('--align', type=click.Choice(['1', '2', '4', '8']), default='8',
              help='Flash alignment')
@click.option('--update-key-id', type=click.Choice(['0', '1']),
              help='OEM private key ID used to sign the update data packet')
@click.option('--update-key-path', type=click.Path(),
              help='The key used to sign the update data packet. Overrides '
                   'the --update-key-id option')
@click.option('--image-id', type=click.INT, help='Image ID', default=0)
@click.pass_context
def cmd_extend_image(ctx, image, pubkey, erased_val, image_config, output,
                     protected_tlv, header_size, slot_size, hex_addr,
                     image_format, pad, confirm, overwrite_only, align,
                     update_key_id, update_key_path, image_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_args()
        result = ctx.obj['TOOL'].extend_image(
            image, pubkey=pubkey, erased_val=erased_val,
            image_config=image_config, output=output,
            protected_tlv=list(protected_tlv), slot_size=slot_size,
            header_size=header_size, skip_tlv_info=True,
            hex_addr=hex_addr, image_format=image_format, pad=pad,
            confirm=confirm, overwrite_only=overwrite_only,
            align=align,
            update_key_id=
            None if update_key_path or update_key_id is None else int(
                update_key_id),
            update_key_path=update_key_path, image_id=image_id
        )
        return result is not None

    def validate_args():
        if image_format == 'bootrom_next_app' and not pubkey:
            sys.stderr.write("Error: Missing option '--pubkey'.\n")
            sys.exit(2)

        from .targets.common.mxs40sv2.enums import PolicyType
        if ctx.obj['TOOL'].policy_parser.json:
            policy_type = ctx.obj['TOOL'].policy_parser.policy_type()
            if policy_type == PolicyType.REPROVISIONING_SECURE:
                validate_update_key(update_key_id, update_key_path)

    return process


@main.command('init', help='Initializes new project')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_init(ctx, testapps, testapps_si):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_testapps_args(testapps, testapps_si)
        ctx.obj['TOOL'].init(testapps=test_pkg_type(testapps, testapps_si))
        return True

    return process


@main.command('encrypt', short_help='Encrypts data')
@click.option('-i', '--input', 'input_file', type=click.Path(), required=True,
              help='The binary file to encrypt')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Signed image output file')
@click.option('--enckey', type=click.Path(), required=True,
              help='The key used to encrypt the image')
@click.option('--iv', required=True,
              help='Initialization vector. Decimal or hexadecimal value')
@click.option('--nonce', required=True, help='Nonce used for encryption')
@click.option('--nonce-output', type=click.Path(),
              help='The path to a file where to save the nonce')
@click.pass_context
def cmd_encrypt(ctx, input_file, output, enckey, iv, nonce, nonce_output):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].encrypt(input_file, enckey, iv=iv, nonce=nonce,
                                       output=output, nonce_output=nonce_output)
    return process


@main.command('load-and-run-app', hidden=True,
              help='Loads and runs RAM application')
@click.option('-c', '--config', type=click.Path(), required=True,
              help='Path to the application configuration file')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.pass_context
def cmd_load_and_run_app(ctx, config, probe_id):
    @process_handler(None)
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].load_and_run_app(config, probe_id)

    return process


@main.command('debug-certificate',
              help='Creates debug or RMA certificate binary based on template',
              short_help='Creates debug or RMA certificate binary based on '
                         'template')
@click.option('--non-signed', is_flag=True,
              help='The flag indicating that debug certificate '
                   'will not be signed')
@click.option('-t', '--template', type=click.Path(),
              help='Path to the certificate template in JSON format')
@click.option('-k', '--key-id', type=click.Choice(['0', '1']),
              help='OEM private key ID used to sign the certificate')
@click.option('--key-path', type=click.Path(),
              help='Either a private key path for signing the certificate '
                   'or a public key to be added to the certificate. '
                   'Overrides --key-id option')
@click.option('--sign', type=click.Path(), nargs=2,
              metavar='[cert] [signature]',
              help='The option for signing an existing certificate using '
                   'existing signature file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The file where to save the debug certificate')
@click.pass_context
def cmd_debug_certificate(ctx, non_signed, template, key_id, key_path, sign,
                          output):
    @process_handler()
    def process():
        validate_key_args()
        validate_template_arg()
        if 'TOOL' not in ctx.obj:
            return False
        unsigned_cert = sign[0] if sign else None
        signature = sign[1] if sign else None
        result = ctx.obj['TOOL'].debug_certificate(
            template, os.path.abspath(output),
            None if key_path or key_id is None else int(key_id), key_path,
            non_signed=non_signed, unsigned_cert=unsigned_cert,
            signature=signature)
        if result:
            logger.info('Debug certificate created (%s)', output)
        return result is not None

    def validate_template_arg():
        if template and sign:
            sys.stderr.write("The '--sign' and '--template' options are "
                             "mutually exclusive.\n")
            sys.exit(2)
        if template is None and not sign:
            sys.stderr.write("Missing required option '--template'.")
            sys.exit(2)

    def validate_key_args():
        if not sign:
            if key_id is None and key_path is None:
                sys.stderr.write(
                    "Either '--key-id' or '--key-path' option must "
                    "be specified.\n")
                sys.exit(2)
            elif key_id and key_path:
                sys.stderr.write("The '--key-id' and '--key-path' options are "
                                 "mutually exclusive.\n")
                sys.exit(2)
        else:
            if key_id or key_path:
                sys.stderr.write("The '--key-id' or '--key-path' and '--sign' "
                                 "options are mutually exclusive.\n")
                sys.exit(2)

    return process


@main.command('read-die-id', help='Reads die ID from device')
@click.option('-o', '--out-file', default=None,
              help='Filename where to save die ID')
@click.option('--probe-id', default=None,
              help='Probe serial number')
@click.pass_context
def cmd_read_die_id(ctx, out_file, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        data = ctx.obj['TOOL'].read_die_id(probe_id)
        if data:
            logger.info('die_id = %s', json.dumps(data, indent=4))
            if out_file:
                with open(out_file, 'w', encoding='utf-8') as f:
                    json.dump(data, f, indent=4)
            return True
        return False

    return process


@main.command('convert-to-rma', help='Transition device to RMA lifecycle stage')
@click.option('-c', '--cert', type=click.Path(),
              help='Path to debug certificate')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_convert_to_rma(ctx, cert, probe_id, testapps, testapps_si):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_testapps_args(testapps, testapps_si)
        return ctx.obj['TOOL'].transit_to_rma(
            cert=cert, probe_id=probe_id,
            testapps=test_pkg_type(testapps, testapps_si))
    return process


def validate_update_key(update_key_id, update_key_path):
    if update_key_id is None and update_key_path is None:
        sys.stderr.write(
            "Either '--update-key-id' or '--update-key-path' option "
            "must be specified to sign the update data packets.\n")
        sys.exit(2)
    elif update_key_id and update_key_path:
        sys.stderr.write(
            "The '--update-key-id' and '--update-key-path' options "
            "are mutually exclusive.\n")
        sys.exit(2)


def test_pkg_type(testapps=False, testapps_si=False):
    """ Gets test package type based on a specified testapps flag """
    if testapps:
        return 'testapps'
    if testapps_si:
        return 'testapps_si'
    return None


def validate_testapps_args(testapps, testapps_si):
    """ Validates testapps options """
    if testapps and testapps_si:
        sys.stderr.write("The '--testapps' and '--testapps-si' options "
                         "are mutually exclusive.")
        sys.exit(2)

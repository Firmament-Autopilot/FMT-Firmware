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
import sys
import json
import logging
from json.decoder import JSONDecodeError

import click
from intelhex import HexRecordError
from cryptography.hazmat.primitives import serialization

from .targets.common.mxs40v1.image_cert import ImageCertificate
from .core.enums import KeyAlgorithm
from .cli import main as main, process_handler

logger = logging.getLogger(__name__)
name = 'cli_mxs40v1'


@main.command('create-keys', help='Creates keys specified in policy file')
@click.option('--overwrite/--no-overwrite', 'overwrite', is_flag=True,
              default=None, required=False,
              help='Indicates whether overwrite keys in the output directory '
                   'if they already exist')
@click.option('-o', '--out', type=click.Path(), default=None, required=False,
              help='Output directory for generated keys. By default keys '
                   'location is as specified in the policy file')
@click.option('--kid', type=click.INT, default=None, required=False,
              help='The ID of the key to create. If not specified, all the '
                   'keys found in the policy will be generated')
@click.option('-a', '--algorithm', default=None, hidden=True,
              type=click.Choice([KeyAlgorithm.EC], case_sensitive=False),
              help='Key algorithm')
@click.option('--template', type=click.Path(),
              help='A JSON file containing public numbers')
@click.pass_context
def cmd_create_keys(ctx, overwrite, out, kid, algorithm, template):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].create_keys(
            overwrite, out, kid, algorithm, template=template)

    return process


@main.command('version',
              help='Show CyBootloader and Secure Flash Boot version',
              short_help='Show CyBootloader and Secure Flash Boot version')
@click.option('--probe-id', 'probe_id', help='Probe serial number')
@click.pass_context
def cmd_version(ctx, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].print_version(probe_id)
        return True

    return process


@main.command('image-metadata',
              help='Adds metadata to a firmware image (header and TLVs)',
              short_help='Adds metadata to a firmware image (header and TLVs)')
@click.option('--image', type=click.Path(), required=True,
              help='User application image (hex or bin)')
@click.option('-i', '--image-id', type=click.INT, default=1,
              help='The ID of the firmware image in the policy file')
@click.option('--image-type', default=None, required=True,
              type=click.Choice(['BOOT', 'UPGRADE'], case_sensitive=False),
              help='Indicates which type of image is signed - boot or '
                   'upgrade. If omitted, both types will be generated')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Binary (bin) file where to save the image with metadata')
@click.option('--decrypted', type=click.Path(),
              help='A path where to save decrypted image payload (bin)')
@click.option('--pubkey', type=click.Path(),
              help='Public key for the further image verification (PEM format)')
@click.option('-e', '--encrypt', 'encrypt_key', type=click.Path(),
              default=None, help='Public key PEM-file for the image encryption')
@click.option('-R', '--erased-val',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value that is read back from erased flash')
@click.option('--boot-record', metavar='sw_type', default='default',
              help='Create CBOR encoded boot record TLV. The sw_type '
                   'represents the role of the software component (e.g. CoFM '
                   'for coprocessor firmware). [max. 12 characters]')
@click.option('--upgrade-mode',
              type=click.Choice(['overwrite', 'swap'], case_sensitive=False),
              default='overwrite', help='Image upgrade mode')
@click.option('--align', type=click.Choice(['1', '2', '4', '8']), default='8',
              help='Flash alignment')
@click.option('--protected-tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='Custom TLV that will be placed into a protected area. '
                   'Add the "0x" prefix if the value should be interpreted '
                   'as an integer, otherwise it will be interpreted as a '
                   'string. Specify the option multiple times to add multiple '
                   'TLVs')
@click.option('--tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help='Custom TLV that will be placed into a non-protected area. '
                   'Add the "0x" prefix if the value should be interpreted '
                   'as an integer, otherwise it will be interpreted as a '
                   'string. Specify the option multiple times to add multiple '
                   'TLVs')
@click.pass_context
def cmd_image_metadata(ctx, image, image_id, image_type, output, pubkey,
                       encrypt_key, erased_val, boot_record, upgrade_mode,
                       align, protected_tlv, tlv, decrypted):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        result = ctx.obj['TOOL'].image_metadata(
            image, image_id=image_id, image_type=image_type, output=output,
            erased_val=erased_val, align=align, boot_record=boot_record,
            upgrade_mode=upgrade_mode, protected_tlv=protected_tlv, tlv=tlv,
            pubkey=pubkey, encrypt_key=encrypt_key, decrypted=decrypted)
        return result is not None

    return process


@main.command('extract-payload',
              help='Extracts a part of image that has to be signed',
              short_help='Extracts a part of image that has to be signed')
@click.option('--image', type=click.Path(), required=True,
              help='Image with MCUboot metadata ( bin)')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='A path where to save image that has to be signed (bin)')
@click.pass_context
def cmd_extract_payload(ctx, image, output):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].extract_payload(image, output)
        return True

    return process


@main.command('add-signature',
              help='Adds signature to existing MCUboot format image',
              short_help='Adds signature to existing MCUboot format image')
@click.option('--image', type=click.Path(), required=True,
              help='Image with MCUboot metadata (bin)')
@click.option('-s', '--signature', type=click.Path(), required=True,
              help='Binary file containing signature')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='A path where to save image with the signature (bin)')
@click.pass_context
def cmd_add_signature(ctx, image, signature, output):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].add_signature(image, signature, output)
        return True

    return process


@main.command('sign-image',
              help='Signs firmware image with the key specified in the '
                   'policy file',
              short_help='Signs firmware image with the key specified in the '
                         'policy file')
@click.option('-h', '--hex', '--image', 'image', type=click.Path(),
              required=True, help='User application hex file')
@click.option('-i', '--image-id', type=click.INT, default=1,
              help='The ID of the firmware image in the policy file')
@click.option('--image-type', default=None,
              type=click.Choice(['BOOT', 'UPGRADE'], case_sensitive=False),
              help='Indicates which type of image is signed - boot or '
                   'upgrade. If omitted, both types will be generated')
@click.option('-o', '--output', type=click.Path(),
              help='Signed image output file')
@click.option('-e', '--encrypt', 'encrypt_key', type=click.Path(),
              default=None,
              help='Public key PEM-file for the image encryption')
@click.option('-R', '--erased-val',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value that is read back from erased flash')
@click.option('--boot-record', metavar='sw_type', default='default',
              help='Create CBOR encoded boot record TLV. The sw_type '
                   'represents the role of the software component (e.g. CoFM '
                   'for coprocessor firmware). [max. 12 characters]')
@click.option('--upgrade-mode',
              type=click.Choice(['overwrite', 'swap'], case_sensitive=False),
              default='overwrite', help='Image upgrade mode')
@click.option('--align', type=click.Choice(['1', '2', '4', '8']), default='8',
              help='Flash alignment')
@click.option('--min-erase-size', help='Sets minimum erase size. '
                                       'Note that this parameter is only '
                                       'applicable for external memory')
@click.option('--protected-tlv', required=False, nargs=2, default=[],
              multiple=True, metavar='[tag] [value]',
              help="Applicable with '--signature' only. Custom TLV that will "
                   "be placed into a protected area. "
                   'Add the "0x" prefix if the value should be interpreted '
                   'as an integer, otherwise it will be interpreted as a '
                   'string. Specify the option multiple times to add multiple '
                   'TLVs')
@click.pass_context
def cmd_sign_image(ctx, image, image_id, image_type, output, encrypt_key,
                   erased_val, boot_record, upgrade_mode, align, min_erase_size,
                   protected_tlv):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_args()
        result = ctx.obj['TOOL'].sign_image(
            image,
            image_id=image_id,
            image_type=image_type,
            output=output,
            encrypt_key=encrypt_key,
            erased_val=erased_val,
            boot_record=boot_record,
            upgrade_mode=upgrade_mode,
            protected_tlv=protected_tlv,
            align=align,
            min_erase_size=min_erase_size)
        return result is not None

    def validate_args():
        if output is not None and image_type is None:
            sys.stderr.write("Error: The option '--output' should only be "
                             "used with '--image-type'.\n")
            sys.exit(2)
    return process


@main.command('create-provisioning-packet',
              help='Creates JWT packet for device provisioning')
@click.pass_context
def cmd_create_provisioning_packet(ctx):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].create_provisioning_packet()

    return process


@main.command('provision-device', help='Executes device provisioning')
@click.option('--probe-id', 'probe_id', type=click.STRING, default=None,
              help='Probe serial number')
@click.option('--existing-packet', 'use_existing_packet', is_flag=True,
              help='Skip provisioning packet creation and use existing one')
@click.pass_context
def cmd_provision_device(ctx, probe_id, use_existing_packet):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        if use_existing_packet:
            result = True
        else:
            result = ctx.obj['TOOL'].create_provisioning_packet()
        if result:
            result = ctx.obj['TOOL'].provision_device(probe_id)
        return result

    return process


@main.command('re-provision-device', help='Executes device re-provisioning')
@click.option('--probe-id', type=click.STRING, required=False, default=None,
              help='Probe serial number')
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing one')
@click.option('--erase-boot', is_flag=True,
              help='Indicates whether erase BOOT slot')
@click.option('--control-dap-cert', default=None,
              help='The certificate that provides the access to control DAP')
@click.option('--skip-bootloader', is_flag=True, hidden=True, default=False,
              help='Skips bootloader programming')
@click.pass_context
def cmd_re_provision_device(ctx, probe_id, existing_packet, erase_boot,
                            control_dap_cert, skip_bootloader):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        if existing_packet:
            result = True
        else:
            result = ctx.obj['TOOL'].create_provisioning_packet()
        if result:
            result = ctx.obj['TOOL'].re_provision_device(
                probe_id, erase_boot=erase_boot,
                control_dap_cert=control_dap_cert,
                skip_bootloader=skip_bootloader)
        return result

    return process


@main.command('create-certificate', help='Creates certificate in x509 format')
@click.option('-t', '--type', 'cert_type', default='x509', hidden=True,
              help='Certificate type (x509)')
@click.option('-n', '--name', 'cert_name', type=click.File(mode='wb'),
              default='psoc_cert.pem', help='Certificate filename')
@click.option('-e', '--encoding', default='PEM',
              help='Certificate encoding (PEM, DER)')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.option('--subject-name', default=None, help='Certificate subject name')
@click.option('--country', default=None, help='Certificate country code')
@click.option('--state', default=None, help='Certificate issuer state')
@click.option('--organization', default=None,
              help='Certificate issuer organization')
@click.option('--issuer-name', default=None, help='Certificate issuer name')
@click.option('--private-key', type=click.File(), default=None,
              help='Private key to sign the certificate')
@click.pass_context
def cmd_create_certificate(ctx, cert_type, cert_name, encoding, probe_id,
                           subject_name, country, state, organization,
                           issuer_name, private_key):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        if encoding.upper() == 'PEM':
            enc = serialization.Encoding.PEM
        elif encoding.upper() == 'DER':
            enc = serialization.Encoding.DER
        else:
            logger.error("Invalid certificate encoding '%s'", encoding)
            return False

        d = {
            'subject_name': subject_name,
            'country': country,
            'state': state,
            'organization': organization,
            'issuer_name': issuer_name,
            'private_key': private_key.name if private_key else None
        }

        result = False
        if cert_type == 'x509':
            cert = ctx.obj['TOOL'].create_x509_certificate(
                cert_name.name, enc, probe_id, **d)
            result = cert is not None
        else:
            logger.error("Invalid certificate type '%s'", cert_type)
        return result

    return process


@main.command('image-certificate', help='Creates Bootloader image certificate')
@click.option('-i', '--image', type=click.File('r'), required=True,
              help='Image in the Intel HEX format')
@click.option('-k', '--key', type=click.File('r'), default=None, required=True,
              help='Private key in the JWK format to sign certificate')
@click.option('-o', '--cert', type=click.File('w'),
              default='image_certificate.jwt',
              help='The output file - image certificate in the JWT format')
@click.option('-v', '--version', callback=ImageCertificate.validate_version,
              help='Image version')
@click.option('--image-id', type=click.INT, default=0, help='Image ID')
@click.option('-d', '--exp-date', default='Jan 1 2031',
              callback=ImageCertificate.validate_date,
              help='Certificate expiration date. Date format '
                   'is \'Jan 1 2031\'')
@click.pass_context
def cmd_image_certificate(ctx, image, key, cert, version, image_id,
                          exp_date):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        result = False
        try:
            key_path = key.name if key else None
            result = ctx.obj['TOOL'].create_image_certificate(
                image.name, key_path, cert.name, version, image_id, exp_date)
        except JSONDecodeError as e:
            logger.error('Invalid certificate signing key')
            logger.error(e)
        except HexRecordError as e:
            logger.error("Invalid image '%s'", image.name)
            logger.error(e)
        return result
    return process


@main.command('entrance-exam',
              help='Checks device life cycle, FlashBoot firmware '
                   'and Flash state',
              short_help='Checks device life cycle, FlashBoot firmware '
                         'and Flash state')
@click.option('--probe-id', type=click.STRING, required=False, default=None,
              help='Probe serial number')
@click.option('--erase-flash', hidden=True, is_flag=True,
              help='Erase flash before the command execution')
@click.pass_context
def cmd_entrance_exam(ctx, probe_id, erase_flash):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].entrance_exam(probe_id=probe_id,
                                             erase_flash=erase_flash)

    return process


@main.command('encrypt-image',
              help='Creates encrypted image for encrypted programming',
              short_help='Creates encrypted image for encrypted programming')
@click.option('-i', '--image', type=click.File('r'), required=True,
              help='The image to encrypt')
@click.option('-h', '--host-key-id', type=click.INT, required=True,
              help='Host private key ID (4 - HSM, 5 - OEM)')
@click.option('-d', '--device-key-id', type=click.INT, required=True,
              help='Device public key ID (1 - device, 12 - group)')
@click.option('--key-length', type=click.INT, default=16,
              help='Derived key length')
@click.option('-o', '--encrypted-image', required=True, type=click.File('w+'),
              help='Output file of encrypted image for encrypted programming')
@click.option('--padding-value', default=0, type=click.INT,
              help='Value for image padding')
@click.option('--probe-id', default=None,
              help='Probe serial number. '
                   'Used to read device public key from device.')
@click.pass_context
def cmd_encrypt_image(ctx, image, host_key_id, device_key_id,
                      key_length, encrypted_image, padding_value, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].encrypt_image(
            image.name, host_key_id, device_key_id, key_length,
            encrypted_image.name, padding_value, probe_id)

    return process


@main.command('encrypted-programming', help='Programs encrypted image')
# w+ is for -i option necessary if encryption and programming are run together
@click.option('-i', '--encrypted-image', type=click.File('w+'), required=True,
              help='The encrypted image to program')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.pass_context
def cmd_encrypted_programming(ctx, encrypted_image, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].encrypted_programming(
                encrypted_image.name, probe_id)

    return process


@main.command('slot-address', help='Gets slot address from given policy')
@click.option('-i', '--image-id', type=click.INT, required=True,
              help='Image ID')
@click.option('-t', '--image-type', default='BOOT',
              help='The image type - BOOT or UPGRADE')
@click.option('-h', 'display_hex', is_flag=True,
              help='Display result as hexadecimal')
@click.pass_context
def cmd_slot_address(ctx, image_id, image_type, display_hex):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        address, _ = ctx.obj['TOOL'].flash_map(image_id, image_type)
        if address:
            print(hex(address) if display_hex else address)
            return True
        return False

    return process


@main.command('slot-size', short_help='Gets slot size from given policy')
@click.option('-i', '--image-id', type=click.INT, required=True,
              help='Image ID')
@click.option('-t', '--image-type', default='BOOT',
              help='The image type - BOOT or UPGRADE')
@click.option('-h', 'display_hex', is_flag=True,
              help='Display result as hexadecimal')
@click.pass_context
def cmd_slot_size(ctx, image_id, image_type, display_hex):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        _, size = ctx.obj['TOOL'].flash_map(image_id, image_type)
        if size:
            print(hex(size) if display_hex else size)
            return True
        return False

    return process


@main.command('read-public-key', help='Reads public key from device')
@click.option('-k', '--key-id', type=click.INT, required=True,
              help='Key ID to read (1 - DEVICE, 4 - HSM, 5 - OEM, 12 - GROUP')
@click.option('-f', '--key-format', default='jwk',
              help='Key format (jwk or pem)')
@click.option('-o', '--out-file', default=None,
              help='Filename where to save the key')
@click.option('--probe-id', default=None,
              help='Probe serial number')
@click.pass_context
def cmd_read_public_key(ctx, key_id, key_format, out_file, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        key = ctx.obj['TOOL'].read_public_key(key_id, key_format, out_file,
                                              probe_id)
        if key:
            if type(key) is dict:
                logger.info(json.dumps(key, indent=4))
            elif type(key) is bytes:
                logger.info(key.decode("utf-8"))
            else:
                logger.info(key)
            return True
        return False

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


@main.command('sign-cert', help='Signs JSON certificate with the private key')
@click.option('-j', '--json-file', '--template', 'template', type=click.Path(),
              required=True, help='Certificate template')
@click.option('-k', '--key-id', type=click.INT, required=True,
              help='Private Key ID to sign the certificate with '
                   '(1 - DEVICE, 4 - HSM, 5 - OEM, 12 - GROUP')
@click.option('-o', '--out-file', '--output', 'output', type=click.Path(),
              help='Filename where to save the JWT. If not specified, the '
                   'input file name with "jwt" extension will be used')
@click.pass_context
def cmd_sign_cert(ctx, template, key_id, output):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        token = ctx.obj['TOOL'].sign_json(template, key_id, output)
        return True if token else False

    return process


@main.command('device-info', help='Reads silicon ID, family, and revision')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.pass_context
def cmd_device_info(ctx, probe_id):
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return
        dev_info = ctx.obj['TOOL'].get_device_info(probe_id)
        if dev_info:
            logger.info(
                'Silicon: 0x%x, Family: 0x%0x, Rev.: 0x%0x',
                dev_info.silicon_id, dev_info.family_id, dev_info.silicon_rev)
        return True

    return process


@main.command('init', help='Initializes new project')
@click.pass_context
@process_handler()
def cmd_init(ctx):
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].init()
        return True

    return process


@main.command('transit-to-rma',
              help='Transition device to RMA lifecycle stage')
@click.option('-c', '--cert', type=click.Path(), required=True,
              help='Path to debug certificate')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.pass_context
def cmd_transit_to_rma(ctx, cert, probe_id):
    """Transits device to RMA LCS"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].transit_to_rma(probe_id=probe_id, cert=cert)

    return process


@main.command('open-rma',
              help='Enables full access to device in RMA lifecycle stage',
              short_help='Enables full access to device in RMA lifecycle stage')
@click.option('-c', '--cert', type=click.Path(), required=True,
              help='Path to debug certificate')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.pass_context
def cmd_open_rma(ctx, cert, probe_id):
    """Enables full access to device in RMA LCS"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].open_rma(cert, probe_id=probe_id)

    return process

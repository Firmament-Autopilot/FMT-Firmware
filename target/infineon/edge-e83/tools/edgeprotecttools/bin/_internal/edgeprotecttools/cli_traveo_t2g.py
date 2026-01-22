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
import logging
import click
from .cli import main, process_handler
from .execute.imgtool.main import get_dependencies

logger = logging.getLogger(__name__)


@main.command('create-key', help='Creates private and public key pair')
@click.option('--key-type', type=click.Choice(
    ['RSA2048', 'RSA3072', 'RSA4096', 'ECDSA-P256'],
    case_sensitive=False), required=True, help='Key type')
@click.option('-o', '--output', type=click.Path(), nargs=2,
              metavar='[private] [public]', required=True,
              help='Key pair output files. Provide private key and public key '
                   'paths.')
@click.option('--format', 'fmt', type=click.Choice(
              ['PEM', 'DER', 'JWK'], case_sensitive=False),
              default='PEM', help='Key format')
@click.option('--overwrite/--no-overwrite', 'overwrite', is_flag=True,
              default=None,
              help='Indicates whether overwrite keys if they already exist')
@click.pass_context
def cmd_create_key(ctx, key_type, output, fmt, overwrite):
    """Creates private-public key pair"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].create_keys(output, key_type, fmt,
                                           overwrite=overwrite)

    return process


@main.command('sign-image',
              short_help='Signs the user application with a key.',
              help='Signs the user application with a key.')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='User application image (hex or bin).')
@click.option('--key-path', type=click.Path(), required=True,
              help='The key used to sign the image')
@click.option('-R', '--erased-val',
              type=click.Choice(['0', '0xff'], case_sensitive=False),
              help='The value that is read back from erased flash')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Signed image output file')
@click.option('-H', '--header-size', help='Sets image header size')
@click.option('-S', '--slot-size', help='Sets maximum slot size')
@click.option('--hex-addr', help='Adjust address in hex output file')
@click.option('--pad', is_flag=True, help='Add padding to the image trailer')
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
def cmd_sign_image(ctx, image, erased_val, key_path, output, header_size,
                   slot_size, hex_addr, pad, overwrite_only,
                   min_erase_size, align, version, dependencies,
                   protected_tlv, tlv):
    """Signs the user application"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        result = ctx.obj['TOOL'].sign_image(
            image,
            key_path=key_path,
            erased_val=erased_val,
            output=output,
            header_size=header_size,
            slot_size=slot_size,
            hex_addr=hex_addr,
            pad=pad,
            overwrite_only=overwrite_only,
            min_erase_size=min_erase_size,
            prot_tlv=protected_tlv,
            tlv=tlv,
            align=align,
            version=version,
            dependencies=dependencies
        )
        return result is not None

    return process


@main.command('sign-cysaf', help='Signs application in '
                                 'Infineon secure application format (CySAF)')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='User application image in CySAF format (elf file).')
@click.option('--key-path', type=click.Path(), required=True,
              help='The key used to sign the image')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Signed image output file')
@click.pass_context
def cmd_sign_cysaf(ctx, image, key_path, output):
    """Signs application image in CySAF format"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].sign_cysaf(image, key_path=key_path, output=output)
        return True

    return process

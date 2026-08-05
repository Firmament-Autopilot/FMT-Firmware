"""
Copyright 2022-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import sys
import logging

import click

from .core.connect_helper import ConnectHelper
from .cli import main, process_handler

logger = logging.getLogger(__name__)


@main.command('create-provisioning-packet',
              help='Creates binary packet for device provisioning')
@click.option('-p', '--policy', type=click.Path(), help='Provisioning policy')
@click.option('-k', '--key', '--key-path', 'key', type=click.Path(),
              help='The key used to sign the provisioning packet')
@click.option('--ifx-oem-cert', type=click.Path(),
              help='The path to OEM certificate')
@click.option('--signature', type=click.Path(),
              help='The signature to add to the provisioning packet')
@click.option('--kid', help='The ID of the key used to verify the packet')
@click.option('-o', '--output', type=click.Path(),
              help="The packet output file. Applicable with 'signature' only")
@click.option('--revoke', type=click.Path(),
              help="The path to key revocation token")
@click.option('--integrity-cert', type=click.Path(), hidden=True,
              help='The path to integrity exam certificate')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_create_provisioning_packet(ctx, key, policy, ifx_oem_cert, signature,
                                   kid, output, revoke, testapps, testapps_si,
                                   integrity_cert):
    """Creates device provisioning packet"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        if policy:
            ctx.obj['TOOL'].policy = policy
        validate_args()

        return ctx.obj['TOOL'].create_provisioning_packet(
            key_path=key, kid=kid, signature=signature, output=output,
            revoke=revoke, testapps=test_pkg_type(testapps, testapps_si),
            ifx_oem_cert=ifx_oem_cert, integrity_cert=integrity_cert)

    def validate_args():
        if not (ctx.obj['TOOL'].policy or integrity_cert):
            sys.stderr.write("Error: Missing option '--policy'.\n")
            sys.exit(2)
        if key and signature:
            sys.stderr.write("Error: The '--key-path' and '--signature' options"
                             " are mutually exclusive.\n")
            sys.exit(2)
        validate_testapps_args(testapps, testapps_si)

    return process


@main.command('verify-packet',
              help='Verifies provisioning packet with a key')
@click.option('--packet', type=click.Path(), required=True,
              help='Path to the packet')
@click.option('--key', '--key-path', 'key', type=click.Path(), required=True,
              help='The path to the public key')
@click.option('--kid', help='Key ID')
@click.pass_context
def cmd_verify_packet(ctx, packet, key, kid):
    """Verifies provisioning packet with a key"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].verify_packet(packet, key=key, kid=kid)

    return process


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
                         "are mutually exclusive.\n")
        sys.exit(2)


def get_output_nargs():
    """Based on key type defines number of output arguments"""
    if '--key-type' in sys.argv:
        if sys.argv[sys.argv.index('--key-type') + 1].upper() in \
                ['AES128', 'AES256'] \
                or '--template' in sys.argv:
            return 1
    return 2


@main.command('integrity-cert', hidden=True,
              help='Creates integrity certificate')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The certificate path')
@click.option('-t', '--template', type=click.Path(), required=True,
              help='The path to device integrity template')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The key to sign the certificate')
@click.option('--algorithm', type=click.Choice(
              ['ES256', 'ES384', 'RS256', 'RS384'],
              case_sensitive=False),
              help='The signature algorithm')
@click.option('--cert', type=click.Path(),
              help='The path to device integrity exam certificate')
@click.pass_context
def cmd_integrity_cert(ctx, output, template, key, algorithm, cert):
    """Creates Integrity certificate"""
    @process_handler()
    def process():
        validate()
        if 'TOOL' not in ctx.obj:
            return False

        result = ctx.obj['TOOL'].integrity_cert(
            output, template=template, key=key, algorithm=algorithm, cert=cert)
        return result

    def validate():
        if key and algorithm:
            sys.stderr.write("Error: The '--key' and '--algorithm' options "
                             "are mutually exclusive.\n")
            sys.exit(2)
        if cert and (key or algorithm):
            logger.warning("When using the '--cert' option, the '--key' and "
                           "'--algorithm' options are ignored")

    return process


@main.command('pubkey-from-cert',
              help='Retrieve public key from OEM certificate')
@click.option('--cert', type=click.Path(), required=True,
              help='The path to the OEM certificate')
@click.option('--kid', type=click.Choice(['0', '1']), required=True,
              help='Key ID in the certificate')
@click.option('-f', '--fmt', 'fmt',
              type=click.Choice(['pem', 'der', 'jwk'], case_sensitive=False),
              required=True, help='Output key format')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The path where to save the key')
@click.pass_context
def cmd_pubkey_from_cert(ctx, cert, kid, fmt, output):
    """Retrieve public key from OEM certificate"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].pubkey_from_cert(cert, kid, fmt=fmt,
                                                output=output)

    return process


@main.command('verify-image',
              help='Verifies image with a key or IFX OEM certificate')
@click.option('--image', type=click.Path(), required=True,
              help='Path to the image')
@click.option('--cert', type=click.Path(),
              help='The path to the IFX OEM certificate')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The path to the public key')
@click.option('--kid', type=click.Choice(['0', '1']),
              help='Key ID to select the key from the certificate')
@click.pass_context
def cmd_verify_image(ctx, image, cert, key, kid):
    """Verifies image with a key or IFX OEM certificate"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].verify_image(image, cert=cert, key=key, kid=kid)

    return process


@main.command('init', help='Initializes a new project')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_init(ctx, testapps, testapps_si):
    """Initializes a new project"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_testapps_args(testapps, testapps_si)
        ctx.obj['TOOL'].init(testapps=test_pkg_type(testapps, testapps_si))
        return True

    return process


@main.command('provision-device', help='Executes device provisioning')
@click.option('-p', '--policy', type=click.Path(), help='Provisioning policy')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The path to the private key')
@click.option('--ifx-oem-cert', type=click.Path(),
              help='The path to OEM certificate')
@click.option('--revoke', type=click.Path(),
              help="The path to key revocation token")
@click.option('--kid', help='Key ID')
@click.option('--probe-id', 'probe_id', help='Probe serial number')
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing')
@click.option('--ap', hidden=True, type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used for provisioning')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.option('--acquire/--no-acquire', 'acquire', is_flag=True, default=True,
              hidden=True, help='Device acquisition')
@click.pass_context
def cmd_provision_device(ctx, key, policy, ifx_oem_cert, revoke, kid, probe_id,
                         existing_packet, ap, testapps, testapps_si, acquire):
    """Executes device provisioning"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        if policy:
            ctx.obj['TOOL'].policy = policy
        validate_args()
        testapps_type = test_pkg_type(testapps, testapps_si)

        if not existing_packet:
            if not ctx.obj['TOOL'].create_provisioning_packet(
                    ifx_oem_cert=ifx_oem_cert, key_path=key, revoke=revoke,
                    kid=kid, testapps=testapps_type, command='provisioning'):
                return False
            ctx.obj['TOOL'].build_ramapp_package(
                None, None, key=key, testapps=testapps_type)

        return ctx.obj['TOOL'].provision_device(probe_id=probe_id, ap=ap,
                                                existing_packet=existing_packet,
                                                testapps=testapps_type,
                                                ifx_oem_cert=ifx_oem_cert,
                                                acquire=acquire)

    def validate_args():
        if not ctx.obj['TOOL'].policy:
            sys.stderr.write("Error: Missing option '--policy'.\n")
            sys.exit(2)
        validate_testapps_args(testapps, testapps_si)

    return process


@main.command('reprovision-device', help='Executes device reprovisioning')
@click.option('-p', '--policy', type=click.Path(), help='Reprovisioning policy')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The path to the private key')
@click.option('--kid', help='Key ID')
@click.option('--revoke', type=click.Path(),
              help="The path to key revocation token")
@click.option('--probe-id', 'probe_id', help='Probe serial number')
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing')
@click.option('--ap', hidden=True, type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used for reprovisioning')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_reprovision_device(ctx, key, policy, kid, probe_id, existing_packet, ap,
                           revoke, testapps, testapps_si):
    """Executes device reprovisioning"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        if policy:
            ctx.obj['TOOL'].policy = policy
        validate_args()
        testapps_type = test_pkg_type(testapps, testapps_si)

        if not existing_packet:
            if not ctx.obj['TOOL'].create_provisioning_packet(
                    key_path=key, kid=kid, testapps=testapps_type,
                    revoke=revoke, command='reprovisioning'):
                return False
            ctx.obj['TOOL'].build_ramapp_package(None, None, key=key,
                                                 testapps=testapps_type)

        return ctx.obj['TOOL'].re_provision_device(
            probe_id, ap, existing_packet=existing_packet,
            testapps=testapps_type)

    def validate_args():
        if not ctx.obj['TOOL'].policy:
            sys.stderr.write("Error: Missing option '--policy'.\n")
            sys.exit(2)
        validate_testapps_args(testapps, testapps_si)

    return process


@main.command('load-and-run-app', hidden=True,
              help='Loads and runs RAM application')
@click.option('-c', '--config', type=click.Path(), required=True,
              help='Path to the application configuration file')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.option('--ap', type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used to load application')
@click.option('--acquire/--no-acquire', 'acquire', is_flag=True, default=True,
              hidden=True, help='Device acquisition')
@click.pass_context
def cmd_load_and_run_app(ctx, config, probe_id, ap, acquire):
    """Loads and runs RAM application"""
    @process_handler(None)
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].load_and_run_app(
            config, probe_id, ap, acquire=acquire)

    return process


@main.command('device-info',
              help='Reads device information - silicon ID, family ID, silicon '
                   'revision',
              short_help='Reads device information - silicon ID, family ID, '
                         'silicon revision')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.option('--ap', type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used to read the data')
@click.pass_context
def cmd_device_info(ctx, probe_id, ap):
    """Outputs device info: family_id, silicon_id, silicon_rev, lcs"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        status = True
        ConnectHelper.do_not_disconnect = True
        dev_info = ctx.obj['TOOL'].get_device_info(probe_id, ap)
        ConnectHelper.do_not_disconnect = False
        lifecycle = ctx.obj['TOOL'].get_device_lifecycle(
            probe_id, ap, alt_name=True)

        if dev_info:
            logger.info('*' * 39)
            logger.info(
                'Family: %s, Silicon ID: %s, Rev.: %s',
                hex(dev_info.family_id) if dev_info.family_id else 'unknown',
                hex(dev_info.silicon_id) if dev_info.silicon_id else 'unknown',
                hex(dev_info.silicon_rev) if dev_info.silicon_rev else 'unknown')
        else:
            logger.error('Failed to read Family, Silicon ID, Rev.')
            status = False

        if lifecycle:
            logger.info('Chip lifecycle stage: %s', lifecycle)
        else:
            logger.error('Failed to read chip lifecycle stage')
            status = False

        return status

    return process


@main.command('read-die-id', help='Reads die ID from device')
@click.option('-o', '--out-file', default=None,
              help='Filename where to save die ID')
@click.option('--probe-id', default=None,
              help='Probe serial number')
@click.option('--ap', hidden=True, type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used to read the data')
@click.pass_context
def cmd_read_die_id(ctx, out_file, probe_id, ap):
    """Outputs device die ID"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        data = ctx.obj['TOOL'].read_die_id(probe_id, ap)
        if data:
            logger.info('die_id = %s', json.dumps(data, indent=4))
            if out_file:
                with open(out_file, 'w', encoding='utf-8') as f:
                    json.dump(data, f, indent=4)
            return True
        return False

    return process


@main.command('version', short_help='Shows FW version')
@click.option('--probe-id', 'probe_id', type=click.STRING, default=None,
              help='Probe serial number')
@click.option('--ap', hidden=True, type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used to read the data')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_version(ctx, probe_id, ap, testapps, testapps_si):
    """Outputs device FW version"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_testapps_args(testapps, testapps_si)
        ctx.obj['TOOL'].print_version(
            probe_id, ap, testapps=test_pkg_type(testapps, testapps_si))
        return True

    return process


@main.command('transit-to-rma', help='Transition device to RMA lifecycle stage')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.option('--token', type=click.Path(), required=True,
              help='Path to RMA token')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The key to sign DLM')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing')
@click.pass_context
def cmd_transit_to_rma(
        ctx, probe_id, token, key, testapps, testapps_si, existing_packet):
    """Transits device to RMA LCS"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        validate_testapps_args(testapps, testapps_si)
        return ctx.obj['TOOL'].transit_to_rma(
            cert=token, probe_id=probe_id, existing_packet=existing_packet,
            key=key, testapps=test_pkg_type(testapps, testapps_si))
    return process


@main.command('multi-image-cbor', hidden=True,
              help='Creates a COSE_Sign1 message with multiple images from hex')
@click.option('-i', '--input-path', type=click.Path(), required=True,
              help='Path to the hex image')
@click.option('--template', type=click.Path(),
              help='The path to the additional data template for images')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output path')
@click.option('--key', '--key-path', 'key', type=click.Path(), required=True,
              help='Private key path to sign message')
@click.option('--kid', help='Key ID')
@click.option('--add-size/--no-add-size', default=True)
@click.pass_context
def multi_image_cbor(ctx, output, input_path, key, template, kid, add_size):
    """Creates a multiple images COSE packet"""
    @process_handler()
    def process():
        return ctx.obj['TOOL'].multi_image_cose(
            input_path, output, key,
            template=template, kid=kid, add_size=add_size)

    return process


@main.command('multi-image-cbor-hsm', hidden=True,
              help='Creates a multiple image COSE_Sign1 packet from hex'
                   'for signing with HSM')
@click.option('-i', '--input-path', type=click.Path(), required=True,
              help='Path to the hex image')
@click.option('--template', type=click.Path(),
              help='The path to the additional data template for images')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output path')
@click.option('--algorithm', required=True, type=click.Choice(
              ['ES256', 'ES384', 'RS256', 'RS384'], case_sensitive=False),
              help='Signature algorithm')
@click.option('--signature', type=click.Path(),
              help='Signature path to add to the message')
@click.option('--kid', help='Key ID')
@click.option('--add-size/--no-add-size', default=True)
@click.pass_context
def multi_image_cbor_hsm(ctx, output, input_path, template, algorithm,
                         signature, kid, add_size):
    """Creates a multiple images COSE packet for signing with HSM or
    adds the signature to packet"""
    @process_handler()
    def process():
        return ctx.obj['TOOL'].multi_image_cose(
            input_path, output, None, template=template,
            algorithm=algorithm, signature=signature, kid=kid,
            add_size=add_size)

    return process

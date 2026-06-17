"""
Copyright 2024-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import logging

import click

from .cli import main, process_handler
from . import cli_mxs22
from .core.connect_helper import ConnectHelper
from .targets.common.mxs22.data.mxs22_extended_boot_mode_codes import \
    ExtendedBootMode
from .targets.common.mxs22.data.mxs22_extended_boot_status_codes import \
    ExtendedBootStatus

logger = logging.getLogger(__name__)


cmd_init = cli_mxs22.cmd_init
test_pkg_type = cli_mxs22.test_pkg_type


@main.command('debug-token',
              help='Creates debug token binary based on template',
              short_help='Creates debug token binary based on template')
@click.option('-t', '--template', type=click.Path(),
              help='Path to the token template in JSON format')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='Private key path for signing the token')
@click.option('--signature', type=click.Path(), nargs=2,
              metavar='[token] [signature]',
              help='The option for signing an existing token using '
                   'existing signature file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The file where to save the token')
@click.pass_context
def cmd_debug_token(ctx, template, key, signature, output):
    """CLI command to create debug token"""

    @process_handler()
    def process():
        validate_template_arg()
        if 'TOOL' not in ctx.obj:
            return False
        unsigned_token = signature[0] if signature else None
        signature_path = signature[1] if signature else None
        result = ctx.obj['TOOL'].debug_token(
            template, os.path.abspath(output), key,
            unsigned_cert=unsigned_token, signature=signature_path,
            token_type='debug_token')
        return result is not None

    def validate_template_arg():
        if template and signature:
            sys.stderr.write("The '--signature' and '--template' options are "
                             "mutually exclusive.\n")
            sys.exit(2)
        if template is None and not signature:
            sys.stderr.write("Missing required option '--template'.\n")
            sys.exit(2)

    return process


@main.command('rma-token',
              help='Creates "transit to RMA" or "open RMA" token binary based '
                   'on a template',
              short_help='Creates "transit to RMA" or "open RMA" token binary '
                         'based on a template')
@click.option('-t', '--template', type=click.Path(),
              help='Path to the token template in JSON format')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='Private key path for signing the token')
@click.option('--signature', type=click.Path(), nargs=2,
              metavar='[token] [signature]',
              help='The option for signing an existing token using '
                   'existing signature file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='The file where to save the token')
@click.option('--open-rma', is_flag=True)
@click.pass_context
def cmd_rma_token(ctx, template, key, signature, output, open_rma):
    """CLI command to create RMA token and open RMA token"""

    @process_handler()
    def process():
        validate_template_arg()
        if 'TOOL' not in ctx.obj:
            return False
        unsigned_token = signature[0] if signature else None
        signature_path = signature[1] if signature else None
        result = ctx.obj['TOOL'].debug_token(
            template, os.path.abspath(output), key,
            unsigned_cert=unsigned_token, signature=signature_path,
            token_type='open_rma' if open_rma else 'transit_to_rma')
        return result is not None

    def validate_template_arg():
        if template and signature:
            sys.stderr.write("The '--signature' and '--template' options are "
                             "mutually exclusive.\n")
            sys.exit(2)
        if template is None and not signature:
            sys.stderr.write("Missing required option '--template'.\n")
            sys.exit(2)

    return process


@main.command('ifx-device-cert', hidden=True,
              help='Creates IFX device certificate')
@click.option('--csr', type=click.Path(), required=True,
              help='Path to the results of the Create Identity app')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Certificate path')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The key to sign the certificate')
@click.option('--algorithm', type=click.Choice(
              ['ES256', 'ES384', 'RS256', 'RS384'],
              case_sensitive=False),
              help='Signature algorithm for signing with HSM')
@click.pass_context
def cmd_ifx_device_cert(ctx, csr, output, key, algorithm):
    """Creates IFX device certificate"""
    @process_handler()
    def process():
        validate()
        if 'TOOL' not in ctx.obj:
            return False
        result = ctx.obj['TOOL'].ifx_device_cert(
            csr=csr, output=output, key_path=key, algorithm=algorithm)
        return result

    def validate():
        if key and algorithm:
            sys.stderr.write("Error: The '--key' and '--algorithm' options "
                             "are mutually exclusive.\n")
            sys.exit(2)

    return process


@main.command('key-revocation-token', hidden=True,
              help='Creates IFX key revocation token')
@click.option('--template', type=click.Path(), required=True,
              help='Path to the key revocation template')
@click.option('--key', '--key-path', 'key', type=click.Path(), required=True,
              help='The path to the private key')
@click.option('--kid', help='Key ID')
@click.option('-o', '--output', 'output', type=click.Path(), required=True,
              help='Path to the key revocation token')
@click.pass_context
def cmd_ifx_key_revocation_token(ctx, template, key, kid, output):
    """Creates IFX key revocation token"""

    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        result = ctx.obj['TOOL'].cose_token(template, key, kid, output,
                                            token_type='revoke')
        return result is not None

    return process


@main.command('integrity-exam',
              help='Executes integrity exam app')
@click.option('--alias-cert', type=click.Path(),
              help='The path to save alias certificate')
@click.option('--device-cert', type=click.Path(),
              help='The path to save device certificate')
@click.option('--custom-regions', type=click.Path(),
              help='The path to integrity custom regions template')
@click.option('--chain-of-trust', type=click.Path(),
              help='The path to save IFX chain of trust')
@click.option('--probe-id', 'probe_id', help='Probe serial number')
@click.option('--cert', type=click.Path(), hidden=True,
              help='The path to integrity certificate')
@click.option('--cert-template', type=click.Path(), hidden=True,
              help='The path to integrity cert template')
@click.option('--key', '--key-path', 'key', type=click.Path(),
              help='The key to sign DLM')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.option('--existing-packet', is_flag=True, hidden=True,
              help='Skip provisioning packet creation and use existing')
# Not used, keep for BWC
@click.option('--display-ifx', '_display_ifx', is_flag=True, hidden=True)
@click.option('--display-oem', '_display_oem', is_flag=True, hidden=True)
@click.pass_context
def cmd_integrity_exam(ctx, alias_cert, device_cert, custom_regions,
                       chain_of_trust, probe_id, cert, cert_template, key,
                       testapps, testapps_si, existing_packet, _display_ifx,
                       _display_oem):
    """Executes Integrity Check application"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        apps_type = test_pkg_type(testapps, testapps_si)
        return ctx.obj['TOOL'].integrity_exam(custom_regions, probe_id,
                                              cert=cert, key=key,
                                              cert_template=cert_template,
                                              testapps=apps_type,
                                              device_cert=device_cert,
                                              alias_cert=alias_cert,
                                              chain_of_trust=chain_of_trust,
                                              existing_packet=existing_packet)

    return process


@main.command('verify-integrity-response', hidden=True,
              help='Verify integrity exam app response')
@click.option('--cert', type=click.Path(), required=True,
              help='The path to integrity certificate')
@click.option('--in-params', type=click.Path(), required=True,
              help='The path to integrity exam app in params data')
@click.option('--response', type=click.Path(), required=True,
              help='The path to integrity exam app response data')
@click.option('--custom-regions', type=click.Path(),
              help='The path to integrity custom regions template')
@click.option('--device-cert', type=click.Path(),
              help='The path to save device certificate')
@click.option('--alias-cert', type=click.Path(),
              help='The path to save alias certificate')
@click.option('--chain-of-trust', type=click.Path(),
              help='The path to save IFX chain of trust')
@click.option('--cert-template', type=click.Path(),
              help='The path to integrity cert template')
@click.pass_context
def cmd_verify_integrity_response(ctx, cert, in_params, response, custom_regions,
                                  device_cert, alias_cert, chain_of_trust,
                                  cert_template):
    """Integrity exam app response verification"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].verify_integrity_response(
            cert, in_params, response, custom_regions=custom_regions,
            cert_template=cert_template, device_cert=device_cert,
            alias_cert=alias_cert, chain_of_trust=chain_of_trust)

    return process


@main.command('integrity-exam-hashes',
              help='Update integrity template with new hashes '
                   'obtained from device or integrity response')
@click.option('--cert', type=click.Path(), required=True,
              help='The path to integrity exam certificate')
@click.option('--response', type=click.Path(), required=True,
              help='The path to integrity exam application response')
@click.option('--output', type=click.Path(), required=True,
              help='The path where to save the populated template.')
@click.pass_context
def cmd_integrity_exam_hashes(ctx, cert, response, output):
    """
    Populates the integrity exam template with the hashes
    from the application response
    """
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].integrity_exam_hashes(cert, response, output)

    return process


@main.command('se-rt-services-update',
              help='Executes se_rt_services update application')
@click.option('--image', type=click.Path(),
              help='The path to se_rt_services image')
@click.option('--key', type=click.Path(),
              help='The key to sign se_rt_services package')
@click.option('--probe-id', 'probe_id', help='Probe serial number')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing')
@click.pass_context
def cmd_update_services(
        ctx, image, key, probe_id, testapps, testapps_si, existing_packet):
    """Executes se_rt_services update application"""
    @process_handler()
    def process():
        validate()
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].se_rt_services_update(
            image=image,
            key=key,
            probe_id=probe_id,
            testapps=test_pkg_type(testapps, testapps_si),
            existing_packet=existing_packet)

    def validate():
        if not ((image and key) or existing_packet):
            sys.stderr.write("Error: Either both '--image' and '--key' options "
                             "or '--existing-packet' option "
                             "must be specified.\n")
            sys.exit(2)

        if (image or key) and existing_packet:
            sys.stderr.write("Error: Using '--existing-packet' option "
                             "along with '--image' or '--key' options "
                             "is not allowed.\n")
            sys.exit(2)

    return process


@main.command('factory-reset',
              help='Executes factory reset to restore device factory state')
@click.option('--probe-id', 'probe_id', help='Probe serial number')
@click.option('--testapps', is_flag=True, hidden=True)
@click.option('--testapps-si', is_flag=True, hidden=True)
@click.pass_context
def cmd_factory_reset(
        ctx, probe_id, testapps, testapps_si):
    """Executes factory reset to restore device factory state"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].factory_reset(
            probe_id, testapps=test_pkg_type(testapps, testapps_si))

    return process


@main.command('device-info',
              help='Reads device information - silicon ID, family ID, silicon '
                   'revision, extended boot mode, extended boot status',
              short_help='Reads device information - silicon ID, family ID, '
                         'silicon revision, extended boot info')
@click.option('--probe-id', default=None, help='Probe serial number')
@click.option('--ap', type=click.Choice(['cm33', 'sysap']),
              default='sysap', help='The access port used to read the data')
@click.pass_context
def cmd_device_info(ctx, probe_id, ap):
    """Outputs device info: family_id, silicon_id, silicon_rev, lcs,
    extended boot info"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        status = True
        ConnectHelper.do_not_disconnect = True
        lcs = ctx.obj['TOOL'].get_device_lifecycle(
            probe_id, ap, alt_name=True)
        ConnectHelper.do_not_disconnect = lcs in ('DEVELOPMENT', 'PRODUCTION')
        dev_info = ctx.obj['TOOL'].get_device_info(probe_id, ap)

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

        if lcs:
            logger.info('Chip lifecycle stage: %s', lcs)
        else:
            logger.error('Failed to read chip lifecycle stage')
            status = False

        if lcs in ('DEVELOPMENT', 'PRODUCTION'):
            ConnectHelper.do_not_disconnect = False
            ex_boot_mode, ex_boot_status = ctx.obj[
                'TOOL'].get_extended_boot_info(
                probe_id=probe_id)
            if ex_boot_mode:
                boot_mode = ExtendedBootMode()
                try:
                    key, msg = boot_mode.status_by_code(ex_boot_mode)
                    logger.info('Extended boot mode: (%s) - %s: %s',
                                hex(ex_boot_mode),
                                key, msg)
                except KeyError:
                    logger.error('Unknown extended boot mode: %s',
                                 hex(ex_boot_mode))
            if ex_boot_status:
                boot_status = ExtendedBootStatus()
                try:
                    key, msg = boot_status.status_by_code(ex_boot_status)
                    logger.info('Extended boot status: (%s) - %s: %s',
                                hex(ex_boot_status),
                                key, msg)
                except KeyError:
                    logger.error('Unknown extended boot status: %s',
                                 hex(ex_boot_status))

        return status

    return process

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
import click

from .cli import main, process_handler


@main.command('init', help='Initializes a new project')
@click.pass_context
def cmd_init(ctx):
    """Initializes a new project"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        ctx.obj['TOOL'].init()
        return True

    return process


@main.command('create-provisioning-packet',
              help='Creates binary packet for device provisioning')
@click.option('-p', '--policy', type=click.Path(), help='Provisioning policy',
              required=True)
@click.option('-o', '--output', help='The packet output path', required=True)
@click.pass_context
def cmd_create_provisioning_packet(ctx, policy, output):
    """
    Creates provisioning packet (an input parameters for RAM applications
    """
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        if policy:
            ctx.obj['TOOL'].policy = policy

        return ctx.obj['TOOL'].create_provisioning_packet(output=output)

    return process


@main.command('provision-device', help='Executes device provisioning')
@click.option('-p', '--policy', type=click.Path(), required=True,
              help='Provisioning policy')
@click.option('--existing-packet', is_flag=True,
              help='Skip provisioning packet creation and use existing')
@click.pass_context
def cmd_provision_device(ctx, policy, existing_packet):
    """Executes device provisioning"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False

        ctx.obj['TOOL'].policy = policy
        result = True
        if not existing_packet:
            result = ctx.obj['TOOL'].create_provisioning_packet()
            if result:
                result = ctx.obj['TOOL'].build_ramapp_package(None, None)
        if result:
            result = ctx.obj['TOOL'].provision_device()
        return result

    return process


@main.command('load-and-run-app',
              help='Executes factory reset to restore device factory state')
@click.option('-c', '--config', type=click.Path(), required=True,
              help='Mini driver load config')
@click.pass_context
def cmd_load_and_run_app(ctx, config):
    """Executes mini driver load"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].load_and_run_app(config)

    return process


@main.command('secure-cert', help='Generates a key or content certificate')
@click.option('-c', '--config', type=click.Path(), required=True,
              help='Certificate configuration file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Certificate output file')
@click.pass_context
def cmd_secure_cert(ctx, config, output):
    """Generates a key or content certificate"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        cert = ctx.obj['TOOL'].secure_cert(config, output=output)
        return cert is not None

    return process


@main.command('secure-image', help='Creates a secure image by merging key and '
                                   'content certificates to the application')
@click.option('--image', type=click.Path(), required=True,
              help='Application HEX file')
@click.option('--cert', 'certs', type=click.Path(), required=True,
              multiple=True, help='Certificate in DER format')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output HEX file')
@click.option('--hcd', type=click.Path(), help='Output HCD file')
@click.pass_context
def cmd_secure_image(ctx, image, certs, output, hcd):
    """Merges application image with the key and content certificates"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        signed = ctx.obj['TOOL'].secure_image(image, certs, output=output,
                                              hcd=hcd)
        return signed is not None

    return process


@main.command('ota-image', help='Creates OTA image')
@click.option('--image', type=click.Path(), required=True,
              help='Application HEX file')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Output BIN file')
@click.pass_context
def cmd_ota_image(ctx, image, output):
    """Creates OTA image"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        data = ctx.obj['TOOL'].ota_image(image, output=output)
        return data is not None

    return process


@main.command('encrypt', help='Encrypts the application')
@click.option('-i', '--image', type=click.Path(), required=True,
              help='Image HEX file')
@click.option('--key', '--key-path', 'key', required=True,
              help='The key used to encrypt the application')
@click.option('--iv', required=True, help='Initialization vector (16 bytes)')
@click.option('-o', '--output', type=click.Path(), required=True,
              help='Encrypted image output path')
@click.pass_context
def cmd_encrypt(ctx, image, key, iv, output):
    """Encrypts the application in the hex file generated by MTB"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].encrypt(image, key, iv, output=output)

    return process


@main.command('get-csr', help='Load the CSR from the device')
@click.option('-o', '--output', 'output', type=click.Path(), required=True,
              help='CSR output path')
@click.option('--csr-id', type=click.Choice(['0', '1', '2']), help='CSR ID',
              default='0', show_default=True)
@click.pass_context
def cmd_get_csr(ctx, output, csr_id):
    """Load device CSR"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].get_csr(output, csr_id=csr_id)

    return process


@main.command('read-soc-id', help='Load SOC ID from the device')
@click.option('-o', '--output', 'output', type=click.Path(), help='SOC ID path')
@click.pass_context
def cmd_read_soc_id(ctx, output):
    """Read device SOC ID"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].read_soc_id(output)

    return process

@main.command('erase-flash', help='Erase flash memory of the device')
@click.pass_context
def cmd_erase_flash(ctx):
    """Erase flash memory of the device"""
    @process_handler()
    def process():
        if 'TOOL' not in ctx.obj:
            return False
        return ctx.obj['TOOL'].erase_flash()

    return process

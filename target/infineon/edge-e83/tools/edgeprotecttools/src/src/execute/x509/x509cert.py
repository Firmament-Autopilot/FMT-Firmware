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
import json
import base64
import os.path
from datetime import datetime, timezone, timedelta

from cryptography import x509
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import rsa, ec
from cryptography.x509.oid import NameOID
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.exceptions import InvalidSignature

from ...core.exceptions import ValidationError
from ...core.key_handlers import load_public_key, load_private_key


class X509CertificateGenerator:
    """Class to generate X.509 certificates from a JSON configuration file"""

    def __init__(self, cert_config, csr=None, ca_cert=None, self_signed=False):
        """Initializes the X.509 certificate generator
        @param cert_config: Certificate configuration file or an object
        @param csr: Certificate Signing Request (CSR) path or an object
        @param ca_cert: CA certificate path or an object
        @param self_signed: True if the certificate is self-signed
        """
        if cert_config is None:
            raise ValueError('No certificate data provided')

        if ca_cert and self_signed:
            raise ValueError('Self-signed certificates cannot have a CA')

        self.certificate = None
        self.config, self.cert_dir = self.load_config(cert_config)
        self.csr = self.load_csr(csr) if isinstance(csr, str) else csr
        self.ca_cert = self.load_cert(
            ca_cert) if isinstance(ca_cert, str) else ca_cert
        self.self_signed = self_signed

    @staticmethod
    def load_config(cert_config):
        """Loads the certificate configuration
        @param cert_config: Path to the certificate configuration file
        @return: A tuple containing the certificate data and
        the config file directory path
        """
        if isinstance(cert_config, dict):
            data = cert_config
            cert_dir = None
        else:
            with open(cert_config, 'r', encoding='utf-8') as f:
                data = json.load(f)
            cert_dir = os.path.dirname(cert_config)
        return data, cert_dir

    @staticmethod
    def load_csr(csr_path) -> x509.CertificateSigningRequest:
        """Loads a Certificate Signing Request (CSR) from a file.
        @param csr_path: Path to the CSR file (PEM or DER format)
        @return: The CSR object
        """
        with open(csr_path, 'rb') as csr_file:
            csr_data = csr_file.read()
        try:
            csr = x509.load_pem_x509_csr(csr_data, default_backend())
        except ValueError:
            try:
                csr = x509.load_der_x509_csr(csr_data, default_backend())
            except ValueError as e:
                raise ValueError('Invalid CSR file format') from e
        return csr

    @staticmethod
    def load_cert(cert_path) -> x509.Certificate:
        """Loads a certificate from a file
        @param cert_path: Path to the certificate file (PEM or DER format)
        @return: The certificate object
        """
        with open(cert_path, 'rb') as csr_file:
            cert_data = csr_file.read()
        try:
            cert = x509.load_pem_x509_certificate(cert_data, default_backend())
        except ValueError:
            try:
                cert = x509.load_der_x509_certificate(cert_data,
                                                      default_backend())
            except ValueError as e:
                raise ValueError('Invalid certificate file format') from e
        return cert

    def verify_csr(self) -> bool:
        """Verifies the signature of a CSR object
        @return: True if the CSR is valid, False otherwise
        """
        if self.csr is None:
            raise ValueError('CSR not provided')

        pubkey = self.csr.public_key()

        try:
            if isinstance(pubkey, rsa.RSAPublicKey):
                pubkey.verify(
                    self.csr.signature,
                    self.csr.tbs_certrequest_bytes,
                    self.csr.signature_algorithm_parameters,
                    self.csr.signature_hash_algorithm
                )
            elif isinstance(pubkey, ec.EllipticCurvePublicKey):
                pubkey.verify(
                    self.csr.signature,
                    self.csr.tbs_certrequest_bytes,
                    self.csr.signature_algorithm_parameters
                )
            else:
                raise ValueError('Invalid public key type. RSA or EC expected')
        except InvalidSignature:
            return False
        return True

    @staticmethod
    def verify_cert(cert, pubkey):
        """Verifies the signature of a certificate object
        @param cert: The certificate to be verified
        @param pubkey: The public key used to verify the certificate
        """
        if pubkey is None or cert is None:
            raise ValueError('Verification entities not provided')

        try:
            if isinstance(pubkey, rsa.RSAPublicKey):
                pubkey.verify(
                    cert.signature,
                    cert.tbs_certificate_bytes,
                    cert.signature_algorithm_parameters,
                    cert.signature_hash_algorithm
                )
            elif isinstance(pubkey, ec.EllipticCurvePublicKey):
                pubkey.verify(
                    cert.signature,
                    cert.tbs_certificate_bytes,
                    cert.signature_algorithm_parameters
                )
            else:
                raise ValueError('Invalid public key type. RSA or EC expected')
        except InvalidSignature as e:
            raise ValidationError('Invalid certificate signature') from e

        now = datetime.now(timezone.utc)
        if not cert.not_valid_before_utc < now < cert.not_valid_after_utc:
            raise ValidationError('Invalid certificate validity period')

    def validate_cert_config(self):
        """Validates the certificate configuration file"""
        raise NotImplementedError

    def generate(
        self,
        signing_key,
        password=None,
        rsa_padding=None
    ) -> x509.Certificate:
        """Generates the X.509 certificate
        @param signing_key: Private key used to sign the certificate
        @param password: Password for the private key
        @param rsa_padding: Padding algorithm for RSA signature
        """
        if isinstance(signing_key, str):
            signing_key = load_private_key(signing_key, password=password)

        if self.config.get('serial_number'):
            serial_number = int(str(self.config['serial_number']))
        else:
            serial_number = x509.random_serial_number()

        if self.ca_cert:
            issuer = self.ca_cert.issuer
        else:
            issuer = self.distinguished_name(self.config.get('issuer'))

        if self.self_signed:
            subject = issuer
            pubkey = signing_key.public_key()
        else:
            subject = self.distinguished_name(self.config.get('subject'),
                                              self.csr)
            if self.config.get('subject_public_key'):
                pubkey = self.load_pubkey(self.config['subject_public_key'])
            else:
                pubkey = self.csr.public_key() if self.csr else None

        not_after, not_before = self.cert_validity_period(
            self.config.get('validity'))

        cert_builder = (x509.CertificateBuilder().serial_number(
            serial_number
        ).issuer_name(
            issuer
        ).subject_name(
            subject
        ).not_valid_before(
            not_before
        ).not_valid_after(
            not_after
        ).public_key(
            pubkey
        ))

        if self.config.get('extensions'):
            cert_builder = self.add_cert_extensions(self.config['extensions'],
                                                    cert_builder)

        if self.self_signed:
            cert_builder = cert_builder.add_extension(
                x509.BasicConstraints(ca=True, path_length=None), critical=True)

        self.certificate = cert_builder.sign(signing_key, hashes.SHA256(),
                                             rsa_padding=rsa_padding)
        return self.certificate

    @staticmethod
    def distinguished_name(
            dn_data: dict,
            csr: x509.CertificateSigningRequest = None
    ) -> x509.Name:
        """Creates a Distinguished Name (DN) object from the config
        file and CSR. Configuration file has a higher priority than CSR.
        @param dn_data: Dictionary with the DN data
        @param csr: Certificate Signing Request (CSR) object
        """
        attributes = []

        for oid, name in {
            NameOID.COUNTRY_NAME: 'country',
            NameOID.ORGANIZATION_NAME: 'organization',
            NameOID.ORGANIZATIONAL_UNIT_NAME: 'organizational_unit',
            NameOID.STATE_OR_PROVINCE_NAME: 'state_or_province',
            NameOID.LOCALITY_NAME: 'locality',
            NameOID.STREET_ADDRESS: 'street_address',
            NameOID.POSTAL_CODE: 'postal_code',
            NameOID.EMAIL_ADDRESS: 'email_address',
            NameOID.COMMON_NAME: 'common_name'
        }.items():
            attribute = dn_data.get(name)
            if attribute:
                attributes.append(x509.NameAttribute(oid, attribute))
            elif csr:
                attribute = csr.subject.get_attributes_for_oid(oid)
                if attribute:
                    attribute = attribute[0].value
                    attributes.append(x509.NameAttribute(oid, attribute))

        return x509.Name(attributes) if attributes else None

    @staticmethod
    def cert_validity_period(validity_period: dict) -> (datetime, datetime):
        """Creates a validity period object from the validity period data"""
        if validity_period.get('not_before') in (None, ''):
            not_before = datetime.now(timezone.utc) - timedelta(days=1)
        else:
            not_before = datetime.strptime(validity_period['not_before'],
                                           '%Y-%m-%dT%H:%M:%S')

        not_after = datetime.strptime(validity_period["not_after"],
                                      '%Y-%m-%dT%H:%M:%S')
        return not_after, not_before

    def load_pubkey(self, pubkey):
        """Creates a subject public key object from the key path"""
        if pubkey and isinstance(pubkey, str):
            if not os.path.isabs(pubkey):
                pubkey = os.path.abspath(os.path.join(self.cert_dir, pubkey))
            return load_public_key(pubkey)
        return pubkey or None

    def add_cert_extensions(
        self,
        extensions_data: list,
        cert_builder: x509.CertificateBuilder
    ) -> x509.CertificateBuilder:
        """Adds extensions to the certificate builder"""
        for data in extensions_data:
            oid = data['oid']
            data_format = data.get('data_format', 'hex')

            if data_format == 'hex':
                ext_val = bytes.fromhex(data['value'])
            elif data_format == 'binary_file':
                filename = data['value']
                if not os.path.isabs(filename):
                    filename = os.path.join(self.cert_dir, filename)
                with open(filename, 'rb') as file:
                    ext_val = file.read()
            elif data_format == 'base64':
                ext_val = base64.b64decode(data['value'])
            else:
                raise ValueError(f'Unknown data format: {data_format}')

            extension = x509.UnrecognizedExtension(x509.ObjectIdentifier(oid),
                                                   ext_val)
            cert_builder = cert_builder.add_extension(
                extension, critical=data.get('critical', False))
        return cert_builder

    def save_certificate(self, filename, encoding='pem'):
        """Saves the certificate to a file
        @param filename: Path to the file where the certificate will be saved
        @param encoding: Encoding format ('pem' or 'der')
        """
        if self.certificate is None:
            raise ValueError('Certificate not generated yet')

        if encoding.lower() == 'pem':
            encoding = serialization.Encoding.PEM
        elif encoding.lower() == 'der':
            encoding = serialization.Encoding.DER
        else:
            raise ValueError(f'Unknown encoding: {encoding}')

        with open(filename, 'wb') as f:
            f.write(self.certificate.public_bytes(encoding))

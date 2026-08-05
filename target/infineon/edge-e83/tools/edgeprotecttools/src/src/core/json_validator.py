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
import json
import logging
import os

import jsonschema

from .enums import ValidationStatus

logger = logging.getLogger(__name__)


class JsonValidator:
    """Implements JSON validation. There are three types of validation:
         - version verification
         - validation against JSON schema
         - advanced validation (when a property cannot be validated
         with a schema)
    """
    schemas = {}

    @property
    def parser(self):
        """JSON parser"""
        return self._parser

    @parser.setter
    def parser(self, value):
        self._parser = value
        if self.version_verifier:
            self.version_verifier.parser = value
        if self.advanced_validator:
            self.advanced_validator.parser = value

    def __init__(self, parser=None, version_verifier=None,
                 advanced_validator=None):
        """Creates an instance of the JSON validator
        @param parser: JSON parser
        @param version_verifier: A class which does version verification
        @param advanced_validator: A class that does advanced validation
        for the rules that cannot be checked by JSON schema
        """
        self._parser = parser
        self.version_verifier = version_verifier
        self.advanced_validator = advanced_validator

        if version_verifier:
            self.version_verifier = version_verifier(self.parser)

        if advanced_validator:
            self.advanced_validator = advanced_validator(self.parser)

    def validate(self, template_type) -> ValidationStatus:
        """Runs three-step JSON validation"""
        status = self.verify_version()

        if status == ValidationStatus.OK:
            status = self.validate_by_schema(template_type)

        if status == ValidationStatus.OK:
            status = self.validate_advanced()

        return status

    def verify_version(self) -> ValidationStatus:
        """Verifies template version"""
        if not self.version_verifier:
            return ValidationStatus.OK
        verified, message = self.version_verifier.verify()
        if verified:
            return ValidationStatus.OK
        logger.error(message)
        return ValidationStatus.ERROR

    def validate_by_schema(self, template_type, data=None) -> ValidationStatus:
        """Validates JSON template against schema"""
        try:
            schema_path = os.path.abspath(self.schemas[template_type])
        except KeyError as e:
            raise ValueError(f"Invalid schema type {e}") from e

        with open(schema_path, encoding='utf-8') as f:
            schema = json.loads(f.read())
        logger.debug("Validate JSON against schema '%s'", schema_path)

        data = data if data else self.parser.template
        try:
            jsonschema.validate(data, schema)
        except (jsonschema.exceptions.ValidationError,
                jsonschema.exceptions.SchemaError) as e:
            logger.error('Validation against schema failed')
            logger.error(e.message)
            logger.debug(e)
            return ValidationStatus.ERROR

        logger.debug('Validation against schema succeed')
        return ValidationStatus.OK

    def validate_advanced(self) -> ValidationStatus:
        """Runs custom validators"""
        if not self.advanced_validator:
            return ValidationStatus.OK
        is_valid, messages = self.advanced_validator.validate()
        for m in messages:
            if m.severity == 'error':
                logger.error(m.message)
            elif m.severity == 'warning':
                logger.warning(m.message)
            elif m.severity == 'info':
                logger.info(m.message)
            elif m.severity == 'debug':
                logger.debug(m.message)
        return ValidationStatus.OK if is_valid else ValidationStatus.ERROR

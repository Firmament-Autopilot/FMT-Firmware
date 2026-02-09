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
import json
import logging

import jsonschema

from ...core.enums import ValidationStatus
from ...core import PolicyValidatorBase


logger = logging.getLogger(__name__)


class PolicyValidator(PolicyValidatorBase):
    """Implements policy validation mechanism. It does two types of
    validation - validation against JSON schema, and validation of
    dependencies between policy properties
    """

    def __init__(self, policy_parser, version_validator,
                 schemas, dependencies_validator):
        self.policy_parser = policy_parser
        self.version_validator = version_validator
        self.schemas = schemas
        self.dependencies_validator = dependencies_validator

    def validate(self, skip=None, skip_prompts=False, **kwargs):
        """Policy JSON file validation
        @param skip: Validator names to be skipped
        @param skip_prompts: Indicates whether to skip interactive prompts
        @return Validation status
        """
        status = ValidationStatus.OK
        if self.skip_validation is True:
            return status

        if self.policy_parser.json is None:
            raise ValueError('No policy data')

        if self.version_validator:
            status = self.validate_version()

        schema = self._get_schema()

        if schema is not None and status == ValidationStatus.OK:
            status = self.validate_by_schema(schema, self.policy_parser.json)

            if status == ValidationStatus.OK:
                status = self.validate_dependencies(skip, **kwargs)

        if status == ValidationStatus.ERROR:
            logger.error('Policy validation error')
        return status

    @staticmethod
    def validate_by_schema(schema, data):
        """Validates policy against JSON schema"""
        status = ValidationStatus.OK
        with open(schema, encoding='utf-8') as f:
            file_content = f.read()
            json_schema = json.loads(file_content)

        logger.debug("Validate policy against schema '%s'", schema)

        try:
            jsonschema.validate(data, json_schema)
            logger.debug('Validation against schema succeed')
        except (jsonschema.exceptions.ValidationError,
                jsonschema.exceptions.SchemaError) as e:
            logger.error('Validation against schema failed')
            logger.error(e)
            status = ValidationStatus.ERROR
        return status

    def validate_dependencies(self, skip_list, **kwargs):
        """Validates policy properties that depend on each other"""
        is_valid, messages = self.dependencies_validator.validate(skip_list,
                                                                  **kwargs)
        PolicyValidator._parse_messages(messages)
        return ValidationStatus.OK if is_valid else ValidationStatus.ERROR

    def validate_version(self):
        """Validates policy version"""
        is_valid, message = self.version_validator.validate()
        if not is_valid:
            logger.error(message)
        return ValidationStatus.OK if is_valid else ValidationStatus.ERROR

    @staticmethod
    def _parse_messages(messages):
        for m in messages:
            if m.severity == 'error':
                logger.error(m.message)
            elif m.severity == 'warning':
                logger.warning(m.message)
            elif m.severity == 'info':
                logger.info(m.message)
            elif m.severity == 'debug':
                logger.debug(m.message)

    def _get_schema(self):
        """Gets path to schema based on policy type"""
        try:
            schema = self.schemas[self.policy_parser.policy_type()]
        except KeyError as e:
            raise ValueError(f"Invalid policy type {e}") from e
        return schema

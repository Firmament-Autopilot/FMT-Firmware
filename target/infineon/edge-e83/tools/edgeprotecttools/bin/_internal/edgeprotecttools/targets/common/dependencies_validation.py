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


class DependenciesValidatorRunner:
    """Runs over the dependency validators"""

    def __init__(self, parser, validators):
        self.parser = parser
        self.validators = validators

    def validate(self, skip_list=None, **kwargs):
        """ Validates dependencies and returns list of messages """
        is_valid = True
        messages = []
        for k, v in self.validators.items():
            if skip_list is not None and k in skip_list:
                continue
            for item in v:
                validator = item(self.parser)
                validator.validate(**kwargs)
                if not validator.is_valid:
                    is_valid = False
                if validator.messages:
                    messages.extend(validator.messages)
        return is_valid, messages

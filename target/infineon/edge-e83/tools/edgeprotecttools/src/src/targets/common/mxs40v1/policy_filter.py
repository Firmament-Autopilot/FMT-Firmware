"""
Copyright 2019-2025 Cypress Semiconductor Corporation (an Infineon company)
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
import json
import copy
import logging

from ....core import PolicyFilterBase

logger = logging.getLogger(__name__)


class PolicyFilter(PolicyFilterBase):
    def __init__(
            self, policy_parser, policy_template='json/policy_template.json'):
        """
        Creates instance of policy filter.
        :param policy_parser: Specific parser for the policy.
        :param policy_template: Specific template that represents
               output policy file.
        """
        self.json_data = policy_parser.json
        self.policy_template = policy_template

    def filter_policy(self):
        """
        From aggregated policy file and creates policy file that contains
        information for provisioning only.
        :return: Path to the filtered policy file.
        """
        sdk_path = os.path.dirname(os.path.realpath(__file__))

        if os.path.isabs(self.policy_template):
            policy_template = self.policy_template
        else:
            policy_template = os.path.join(sdk_path, self.policy_template)
        with open(policy_template, encoding='utf-8') as f:
            file_content = f.read()
            json_template = json.loads(file_content)

        self.parse_node(self.json_data, json_template)
        json_template = self.filter_extra_fields(self.json_data, json_template)

        custom_data_list = 'custom_data_sections'
        if custom_data_list in self.json_data:
            for field in self.json_data[custom_data_list]:
                json_template = self.add_custom_nodes(
                    self.json_data, json_template, field)

        return json_template

    def parse_node(self, data, template):
        """
        Recursive function that copies JSON data from the data dictionary
        to the template dictionary. Copies the fields only that exist in
        template.
        :param data: Dictionary that contains data to copy.
        :param template: Dictionary, which is template that contains
               placeholders where to copy the data.
        """
        for t_key, t_value in template.items():
            for d_key, d_value in data.items():
                if d_key == t_key:
                    if isinstance(d_value, list):                 # process list
                        d_i = 0
                        t_i = 0
                        for t_elem in t_value:
                            if len(d_value) > d_i:
                                d_elem = d_value[d_i]
                                if not isinstance(d_elem, dict):  # process values in the list
                                    if t_i == d_i:
                                        t_value[t_i] = d_elem
                                else:                             # process dictionary in the list
                                    self.parse_node(d_elem, t_elem)
                            else:
                                del t_value[t_i:]
                            d_i += 1
                            t_i += 1
                    elif not isinstance(d_value, dict):           # process values in the dictionary
                        template[t_key] = d_value
                        break
                    else:                                         # process dictionary
                        self.parse_node(d_value, t_value)

    @staticmethod
    def filter_extra_fields(data, template):
        """
        Filters fields that exist in template, but do not exist in policy.
        :param data: Policy data.
        :param template: Template data.
        :return: Filtered dictionary.
        """
        tc = copy.deepcopy(template)
        for i in range(len(data['boot_upgrade']['firmware'])):
            dslot = data['boot_upgrade']['firmware'][i]
            tslot = template['boot_upgrade']['firmware'][i]
            for t_i in tslot:
                if t_i not in dslot:
                    del tc['boot_upgrade']['firmware'][i][t_i]
        return tc

    @staticmethod
    def add_custom_nodes(data, template, obj):
        """
        Copies custom JSON data from the data dictionary to the
        template dictionary.
        :param data: Dictionary that contains data to copy.
        :param template: Dictionary, which is template that contains
               placeholders where to copy the data.
        :param obj: data key to copy
        :return: Updated dictionary.
        """

        tc = copy.deepcopy(template)
        for item in data:
            if item == obj:
                logger.debug(
                    "Copying custom section '%s': %s", item, data[item])
                tc[obj] = data[item]
        return tc

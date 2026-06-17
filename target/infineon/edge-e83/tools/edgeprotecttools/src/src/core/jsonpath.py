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


def get_node_value(data, path):
    """
    Gets node value
    :param data: The dictionary to search
    :param path: The path to search
           Example - root.node1.node2.0.node3
    :return: The value of the node specified in the path
    """
    node = data
    path_list = path.split('.')
    for element in path_list:
        if element.isdigit():
            item = int(element)
        else:
            item = element
        node = node[item]
    return node


def set_node_value(data, path, value):
    """
    Sets value to the node of the dictionary
    :param data: The dictionary to search
    :param path: The path to search
           Example - root.node1.node2.0.node3
    :param value: The value to set
    :return: The value of the node specified in the path
    """
    node = data
    path_list = path.split('.')
    for i in range(len(path_list) - 1):
        if path_list[i].isdigit():
            item = int(path_list[i])
        else:
            item = path_list[i]
        node = node[item]
    node[path_list[len(path_list) - 1]] = value
    return data

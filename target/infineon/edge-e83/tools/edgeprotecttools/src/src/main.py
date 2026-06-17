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
from .targets import (
    is_mxs40v1, is_mxs40sv2, is_mxs22, is_traveo_t2g, is_cyw559xx, is_psb3xxx)
from .api_common import CommonAPI


class ProvisioningPackage:
    """
    A class inherited from the class containing common API and a
    class containing target specific API
    """

    def __new__(cls, target=None, policy=None, log_file=True,
                skip_prompts=False, skip_validation=False, rev=None,
                alt_user_dir=None, timestamps=False):
        """Creates instance of the class inherited from the class containing
        common API and a class containing target specific API
        @param target: Device manufacturing part number
        @param policy: Provisioning policy file
        @param log_file: Indicates whether to write log into a file
        @param skip_prompts: Indicates whether to skip user interactive
               prompts
        @param skip_validation: Indicates whether to skip policy validation
        @param rev: Device revision
        @param alt_user_dir: Alternative package user data directory
        @param timestamps: Enable displaying timestamps in log messages
        """
        api_class = CommonAPI
        if target:
            try:
                # pylint: disable=import-outside-toplevel
                if is_mxs40v1(target):
                    from .api_mxs40v1 import Mxs40v1API
                    api_class = Mxs40v1API
                elif is_mxs40sv2(target):
                    from .api_mxs40sv2 import Mxs40sv2API
                    api_class = Mxs40sv2API
                elif is_psb3xxx(target):
                    from .api_psb3xxx import PSB3xxxAPI
                    api_class = PSB3xxxAPI
                elif is_mxs22(target):
                    from .api_mxs22 import Mxs22API
                    api_class = Mxs22API
                elif is_traveo_t2g(target):
                    from .api_traveo_t2g import TraveoT2GAPI
                    api_class = TraveoT2GAPI
                elif is_cyw559xx(target):
                    from .api_cyw559xx import CYW559xxAPI
                    api_class = CYW559xxAPI
            except KeyError as e:
                raise ValueError(f'Unknown target "{target}"') from e

        return api_class(target=target, policy=policy, log_file=log_file,
                         skip_prompts=skip_prompts,
                         skip_validation=skip_validation, rev=rev,
                         alt_user_dir=alt_user_dir, timestamps=timestamps)


class CySecureTools(ProvisioningPackage):
    """An alias to keep the backward compatibility"""

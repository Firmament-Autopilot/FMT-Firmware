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
from setuptools import setup


with open('README.md', 'r', encoding='utf-8') as f:
    readme = f.read()

with open('CHANGELOG.md', 'r', encoding='utf-8') as f:
    changelog = f.read()

about = {}
with open('src/__about__.py', 'r', encoding='utf-8') as f:
    exec(f.read(), about)  # pylint: disable=exec-used

version = about['__version__']
package_name = about['__pkg_name__'].lower()
github_url = about['__github_url__']

setup(
    name=package_name,
    version=version,
    packages=[package_name],
    package_dir={package_name: 'src'},
    install_requires=[
        'setuptools>=80.9.0,<81.0.0',
        'cryptography>=44.0.2',
        'click>=8.0.4',
        'intelhex>=2.3.0',
        'python-jose>=3.3.0',
        'jsonschema>=4.21.1',
        'cbor>=1.0.0',
        'cwt>=2.7.5',
        'packaging>=24.1',
        'pyelftools>=0.31',
        'pyserial>=3.5',
        'pyhsslms>=2.0.0,<3.0.0'
        ],
    description='Python tools for provisioning Cypress/Infineon MCUs',
    long_description=readme + '\n\n' + changelog,
    long_description_content_type='text/markdown',
    author='Cypress Semiconductor Corporation (an Infineon company)',
    url=github_url,
    license='Apache 2.0',
    python_requires='>=3.9',
    include_package_data=True,  # include files from MANIFEST.in
    classifiers=[
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Programming Language :: Python :: 3.12',
        'Programming Language :: Python :: 3.13',
        'Operating System :: OS Independent',
        'Topic :: Software Development :: Embedded Systems',
    ],
    entry_points={
        'console_scripts': [
            f'{package_name} = {package_name}.__main__:main',
            f'cysecuretools = {package_name}.__main__:main',
        ],
    },
    options={
        'bdist_wheel': {
            'python_tag': 'py3',
        }
    }
)

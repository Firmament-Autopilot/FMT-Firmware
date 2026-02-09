# Table of Contents
- [PSoC 64 HW/SW compatibility](#psoc-64-hwsw-compatibility)
- [Reference documents](#reference-documents)
- [Main features](#main-features)
- [Quick start](#quick-start)
- [Usage example](#usage-example)
- [Policy](#policy)
- [Keys](#keys)
- [Command-line interface](#command-line-interface)
    - [Tool help](#tool-help)
    - [Common options](#common-options)
    - [Create keys](#create-keys)
    - [Create provisioning packet](#create-provisioning-packet)
    - [Provision device](#provision-device)
    - [Reprovision device](#reprovision-device)
    - [Sign image](#sign-image)
    - [Convert bin to hex](#convert-bin-to-hex)
    - [Entrance exam](#entrance-exam)
    - [Create a certificate](#create-a-certificate)
    - [Create image certificate](#create-image-certificate)
    - [Encrypted programming](#encrypted-programming)
       - [Create encrypted image](#create-encrypted-image)
       - [Program encrypted image](#program-encrypted-image)
       - [Programming encrypted bootloader](#programming-encrypted-bootloader)
       - [Programming encrypted user application](#programming-encrypted-user-application)
    - [CyBootloader and Secure Flash Boot version](#cybootloader-and-secure-flash-boot-version)
    - [Sign DAP certificate](#sign-certificate)
    - [Transit to RMA](#transit-to-rma)
    - [Open RMA](#open-rma)
    - [Read public key from device](#read-public-key-from-device)
    - [Read die ID from device](#read-die-id-from-device)
    - [Commands to use with HSM](#commands-to-use-with-HSM)
        - [Add metadata to image](#add-metadata-to-image)
        - [Extract payload for signing](#extract-payload-for-signing)
        - [Add signature to image](#add-signature-to-image)
- [Using package together with HSM](#using-package-together-with-hsm)
    - [Converting key public numbers to JWK](#converting-key-public-numbers-to-jwk)
    - [Signing application with HSM](#signing-application-with-hsm)
- [Closing All Access Ports](#closing-all-access-ports)
- [Open CM0 Access Port](#open-cm0-access-port)
- [RMA](#rma)
- [CyBootloader](#cybootloader)
    - [Custom Bootloader](#custom-bootloader)
    - [Encrypted Bootloader](#encrypted-bootloader)

# PSoC 64 HW/SW compatibility
<table>
  <thead>
    <tr>
      <td>Target/Kit</td>
      <td>Silicon ID, Silicon Rev., Family ID</td>
      <td>Secure FlashBoot Version</td>
      <td>CyBootloader Version</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td colspan="6" style="text-align: center;">512K</td>
    </tr>
    <tr>
      <td>
        cyb06xx5<br>
        cy8cproto&#8209;064b0s3
      </td>
      <td>0xE70D, 0x12, 0x105</td>
      <td>4.0.2.1842</td>
      <td>2.0.1.6441</td>
    </tr>
    <tr>
      <td colspan="6" style="text-align: center;">2M</td>
    </tr>
    <tr>
      <td>
        cyb06xxa<br>
        cy8ckit&#8209;064b0s2&#8209;4343w
      </td>
      <td>0xE470, 0x12, 0x102</td>
      <td>4.0.3.2319</td>
      <td>2.0.2.8102</td>
    </tr>
    <tr>
      <td>
        cys06xxa<br>
        cy8ckit&#8209;064s0s2&#8209;4343w
      </td>
      <td>0xE4A0, 0x12, 0x02</td>
      <td>4.0.3.2319</td>
      <td>2.0.2.8102</td>
    </tr>
    <tr>
      <td colspan="6" style="text-align: center;">1M</td>
    </tr>
    <tr>
      <td>
        cyb06xx7<br>
        cy8cproto&#8209;064s1&#8209;sb<br>
        cy8cproto&#8209;064b0s1&#8209;ble<br>
        cy8cproto&#8209;064b0s1&#8209;ssa
      </td>
      <td>
        0xE262, 0x24, 0x100
        0xE261, 0x24, 0x100
      </td>
      <td>4.0.2.1842</td>
      <td>2.0.0.4041</td>
    </tr>
  </tbody>
</table>


# Reference documents
* [PSoC64 Secure MCU Secure Boot SDK User Guide](https://www.cypress.com/documentation/software-and-drivers/psoc-64-secure-mcu-secure-boot-sdk-user-guide)


# Main features
* [Create keys](#create-keys) - A key is a file used to authorize access to device data. There must be a common key pair between the secure device and user application. A device must be provisioned with a public key and the user application must be signed with a corresponding private key from the same pair.
* [Entrance exam](#entrance-exam) - Passing an entrance exam before provisioning a device is an option to ensure that the device has the valid state.
* [Provisioning a device](#provision-device) - Provisioning is the act of configuring a device with an authorized set of keys, certificates, and policies.
* [Sign a user application](#sign-image) - To run a user application on a secure device, the application must be signed with the key provisioned to the device earlier.
* [Create a certificate](#create-a-certificate) - Create a certificate in the X.509 format: with the device public key inside and signed with the private key. The certificate can be used when connecting to a cloud service.
* [Create image certificate](#create-image-certificate) - Based on an image, create a JWT that certifies the image's validity.
* [Output CyBootloader and Secure Flash Boot version](#cybootloader-and-secure-flash-boot-version) - Outputs CyBootloader and Secure Flash Boot version.


# Quick start
## 1. Set a path to the On-Chip debugger
```bash
$ edgeprotecttools set-ocd --name openocd --path <PATH_TO_OPENOCD_ROOT_DIRECTORY>
```
Make sure you provide the path to the root directory of OpenOCD (NOT _bin_ directory).
Specifying the path is not mandatory if you have ModusToolbox™ installed on your machine. OpenOCD from the ModusToolbox™ directory is used by default.

_Example:_
```bash
$ edgeprotecttools set-ocd --name openocd --path /Users/username/tools/openocd
```

## 2. Define a target
Run the following command and find the name of your target in the list of supported targets.
```bash
$ edgeprotecttools device-list
```
This target name will be used as a `-t` option value with each command.

_Example_:
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p <POLICY> <COMMAND> [OPTIONS]
```

## 3. Create a new project
This copies the list of files required to start using the tool to the current working directory.
```bash
$ edgeprotecttools -t <TARGET> init
```

## 4. Define the policy
Select the policy with which the device will be provisioned. All available policy files are located in the _policy_ directory of the project.

This policy file will be used as a `-p` option value with each command.

_Example:_:
```bash
$ edgeprotecttools -t <TARGET> -p policy/policy_single_CM0_CM4_swap.json <COMMAND> [OPTIONS]
```

## 5. Create keys
The public key is programmed during the provisioning for further image verification. The private key is used to sign the image with the user application. Create a private key. The public part of the key will be taken from the private during provisioning.
```bash
$ edgeprotecttools -t <TARGET> -p <POLICY> create-keys
```

## 6. Provision the device
```bash
$ edgeprotecttools -t <TARGET> -p <POLICY> provision-device
```

## 7. Sign the image
```bash
$ edgeprotecttools -t <TARGET> sign-image --image example-blinky.hex --output example-blinky-signed.hex --image-type BOOT
```


# Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W init
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json create-keys
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json provision-device
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json sign-image --image example-blinky.hex --output example-blinky-signed.hex --image-type BOOT
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json re-provision-device
```


# Policy
## Policy Types
The package contains the following policy types for the PSoC 64 target:
 - for single image bootloader with a Swap upgrade method - _policy_single_CM0_CM4_swap.json_
 - for single image bootloader with a Swap upgrade method and use of external memory - _policy_single_CM0_CM4_smif_swap.json_
 - for multi-image bootloader with a Swap upgrade method and use of external memory - _policy_multi_CM0_CM4_swap.json_
 - for multi-image bootloader with a Swap upgrade method and use of external memory - _policy_multi_CM0_CM4_smif_swap.json_
## Policy Location
After creating a project (by using the `init` command), the policy files can be found in the _policy_ directory of the project.
## Custom Data Sections
Policy file can contain optional list of sections, e.g.:
```json
{
    "custom_data_sections": ["abc", "xyz"],
    "abc":
    {
        ...
    },
    "xyz":
    {
        ...
    }
}
```
All listed sections content will be added to the provisioning JWT packet. These data sections are simply copied raw without validation or filtering.


# Keys
## Keys Location
After creating a project (by using the `init` command), the keys will be located in the _keys_ directory of the project. The keys location can be changed in the policy file. Either an absolute or relative path can be used. A relative path is related to the policy file location.

Example:
```json
{
    "boot_auth": [
        8
    ],
    "boot_keys": [
        { "kid": 8, "key": "../keys/USERAPP_CM4_KEY.json" }
    ],
    "id": 4,
    "monotonic": 0,
    "smif_id": 0,
    "upgrade": true,
    "version": "0.1",
    "rollback_counter": 0,
    "encrypt": true,
    "encrypt_key_id": 1,
    "encrypt_peer": "../keys/dev_pub_key.pem",
    "resources": [
        {
            "type": "BOOT",
            "address": 268435456,
            "size": 327680
        },
        {
            "type": "UPGRADE",
            "address": 268763136,
            "size": 327680
        }
    ]
}
```
## Key IDs
| ID | Description                                                                                                                                                                                                                                                       |
|----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1  | Device Private Key for key derivation                                                                                                                                                                                                                             |
| 2  | Device Private Key for signing (Unique per device. This is a copy of Key ID 1.)                                                                                                                                                                                   |
| 3  | Cypress Public Key                                                                                                                                                                                                                                                |
| 4  | HSM Public Key. In the context of the PSoC 64 "Secure Boot MCU", the HSM key is a key of a device programming engine placed in a physically secure facility. The HSM key bundled with the package has the example purpose only and must not be used in production |
| 5  | OEM Public Key                                                                                                                                                                                                                                                    |
| 6  | Custom Key 1                                                                                                                                                                                                                                                      |
| 7  | Custom Key 2                                                                                                                                                                                                                                                      |
| 8  | Custom Key 3                                                                                                                                                                                                                                                      |
| 9  | Custom Key 4                                                                                                                                                                                                                                                      |
| 10 | Custom Key 5                                                                                                                                                                                                                                                      |
| 11 | AES 256-bit Key derived from 128-bit UDS for key derivation (Reserved)                                                                                                                                                                                            |
| 12 | Group Encryption Key                                                                                                                                                                                                                                              |

ID:
* 1, 2, 3, 11 – These keys cannot be modified. They are reserved for other purposes.
* 4, 5, 6, 7, 8, 9, 10, 12 – The user keys whose entries can be modified. These keys can be loaded with keys provided by the OEM. Key ID 8 is the default user application key.


# Command-line interface
This section contains the main CLI commands. More commands can be found in the tool help.

## Tool help
To see the list of commands supported for a specific target:
```bash
$ edgeprotecttools -t <TARGET> --help
```
To see the list of options for a specific command:
```bash
$ edgeprotecttools -t <TARGET> <COMMAND> --help
```

## Common options
The interface provides common options. These options are common for all commands and must precede them:

| Name          | Description                                  |
|---------------|----------------------------------------------|
| -t, --target  | Device name or family.                       |
| -p, --policy  | Provisioning policy file.                    |
| -v, --verbose | Provides debug-level log.                    |
| -q, --quiet   | Quiet display option.                        |
| --logfile-off | Avoids logging into file.                    |
| --timestamps  | Enable displaying timestamps in log messages |


## Create keys
Creates keys specified in the policy file for the image signing.
### Command: `create-keys`
### Parameters
| Name                                                | Optional/Required | Description                                                                                                                                               |
|-----------------------------------------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| --overwrite / --no-overwrite                        |     optional      | Indicates whether overwrite the keys in the output directory if they already exist. If omitted, a prompt will ask whether to overwrite the existing keys. |
| -o, --out                                           |     optional      | The output directory for generated keys. By default, the keys location will be as specified in the policy file.                                           |
| --kid                                               |     optional      | The ID of the key to create. If not specified, all the keys found in the policy file will be generated.                                                   |
| -a, --algorithm [KeyAlgorithm.EC\|KeyAlgorithm.RSA] |     optional      | Sets algorithm for creating the keys.                                                                                                                     |
| --template                                          |     optional      | A path to a JSON file containing public numbers.                                                                                                          |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json create-keys --overwrite
```


## Create provisioning packet
Creates a JWT packet (a file to be programmed into the device during the provisioning procedure). In general, this is a policy, keys, and certificates in the JWT format.
### Command: `create-provisioning-packet`
### Parameters
No parameters required.
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json create-provisioning-packet
```


## Provision device
Starts a device provisioning process.

__WARNING:__ This operation can be done with the SECURE UNCLAIMED device only. SECURE UNCLAIMED means it was not provisioned before, so does not have an identity assigned. Once device was provisioned it is considered as a SECURE CLAIMED and further identity assigning is not possible. It can be re-provisioned with the `re-provision-device` command.

__NOTE:__ There is a `reprovision` field in the policy file, configuring the ability to reprovision a bootloader, keys, and policy. These values cannot be changed once provisioned to the device.

### Command: `provision-device`
### Parameters
| Name              | Optional/Required | Description                                                                                                 |
|-------------------|:-----------------:|-------------------------------------------------------------------------------------------------------------|
| --probe-id        |     optional      | The probe serial number. Can be used to specify a probe if more than one device is connected to a computer. |
| --existing-packet |     optional      | Skip the provisioning packet creation and use the existing packet.                                          |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json provision-device
```


## Reprovision device
Starts a device re-provisioning process.
### Command: `re-provision-device`
### Parameters
| Name               | Optional/Required | Description                                                                                                                           |
|--------------------|:-----------------:|---------------------------------------------------------------------------------------------------------------------------------------|
| --probe-id         |     optional      | The probe serial number. Can be used to specify a probe if more than one device is connected to a computer.                           |
| --existing-packet  |     optional      | Skip the provisioning packet creation and use the existing packet.                                                                    |
| --control-dap-cert |     optional      | The certificate that provides the access to control DAP. For more information refer to [Open CM0 Access Port](#open-cm0-access-port). |
| --erase-boot       |     optional      | Indicates whether to erase BOOT slot.                                                                                                 |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json re-provision-device
```


## Sign image
Signs the user application with a key.

The file specified in the `--image` option will be signed and saved to the file specified in the `--output` option. If the `--output` is not specified, a copy of the original file will be created with the `_unsigned` suffix and the input file will be signed.
### Command: `sign-image`
### Parameters
| Name                             | Optional/Required | Description                                                                                                                                                                                                                       |
|----------------------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| --image                          |     required      | User application image (hex or bin).                                                                                                                                                                                              |
| -i, --image-id                   |     optional      | The ID of the firmware image in the device. The default value is 1.                                                                                                                                                               |
| --image-type                     |     optional      | Indicates which type of an image is signed - boot or upgrade. If omitted, both types will be generated. Accepted only **BOOT** or **UPGRADE** values.                                                                             |
| -e, --encrypt                    |     optional      | Public key PEM-file for the image encryption.                                                                                                                                                                                     |
| -R, --erased-val                 |     optional      | The value that is read back from erased flash.                                                                                                                                                                                    |
| --boot-record                    |     optional      | Creates CBOR-encoded boot record TLV. Represents the role of the software component (e.g. CoFM for coprocessor firmware). Used for measured boot and data sharing. Maximum length is 12 characters.                               |
| -o, --output                     |     optional      | Signed image output file. The option should only be used with _--image-type_.                                                                                                                                                     |
| --protected-tlv                  |     optional      | Custom TLV that will be placed into a protected area. Add the "0x" prefix if the value should be interpreted as an integer, otherwise it will be interpreted as a string. Specify the option multiple times to add multiple TLVs. |
| --upgrade-mode [swap\|overwrite] |     optional      | Image upgrade mode. The default value is overwrite.                                                                                                                                                                               |
| --align [1\|2\|4\|8]             |     optional      | Sets flash alignment. The default value is 8.                                                                                                                                                                                     |
| --min-erase-size                 |     optional      | Sets minimum erase size. Note that this parameter is only applicable for external memory.                                                                                                                                         |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json sign-image --image example-blinky.hex --output example-blinky-signed.hex --image-type BOOT --image-id 1
```


## Convert bin to hex
Converts image of bin format to hex format.
### Command: `bin2hex`
### Parameters
| Name         | Optional/Required | Description                             |
|--------------|:-----------------:|-----------------------------------------|
| --image      |     required      | Input bin file                          |
| -o, --output |     required      | Output hex file                         |
| --offset     |     optional      | Starting address offset for loading bin |
### Usage example
```bash
$ edgeprotecttools bin2hex --image image.bin --output image.hex --offset 0x20000
```


## Entrance exam
Checks the device life-cycle, Flashboot firmware, and Flash memory state.
### Command: `entrance-exam`
### Parameters
| Name       | Optional/Required | Description                                                                                                 |
|------------|:-----------------:|-------------------------------------------------------------------------------------------------------------|
| --probe-id |     optional      | The probe serial number. Can be used to specify a probe if more than one device is connected to a computer. |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json entrance-exam
```


## Create a certificate
Creates a certificate in the X.509 format based on the device public key.
### Command: `create-certificate`
### Parameters
| Name            | Optional/Required | Description                                                             |
|-----------------|:-----------------:|-------------------------------------------------------------------------|
| -n, --name      |     optional      | The certificate filename. By default 'psoc_cert.pem'                    |
| -e , --encoding |     optional      | The certificate encoding (PEM, DER). By default 'PEM'                   |
| --probe-id      |     optional      | The probe serial number.                                                |
| --subject-name  |     optional      | The certificate subject name. By default 'Example Certificate'          |
| --country       |     optional      | The certificate country code. By default 'US'                           |
| --state         |     optional      | The certificate issuer state. By default 'San Jose'                     |
| --organization  |     optional      | The certificate issuer organization. By default 'Cypress Semiconductor' |
| --issuer-name   |     optional      | The certificate issuer name. By default 'Example Issuer Name'           |
| --private-key   |     optional      | The private key to sign the certificate. By default HSM private key     |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json create-certificate -e DER --private-key priv_key.json
```


## Create image certificate
Creates Bootloader image certificate.
### Command: `image-certificate`
### Parameters
| Name           | Optional/Required | Description                              |
|----------------|:-----------------:|------------------------------------------|
| -i, --image    |     required      | The bootloader image path.               |
| -k, --key      |     required      | The private key for certificate signing. |
| -o, --cert     |     optional      | The output certificate file path.        |
| -v, --version  |     optional      | The image version.                       |
| --image-id     |     optional      | The image ID.                            |
| -d, --exp-date |     optional      | The certificate expiration date.         |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json image-certificate -i CypressBootloader_CM0p.hex --key ../keys/key.json -o CypressBootloader_CM0p.jwt --version "1.0.0.200" --image-id 0 --exp-date "Jan 1 2031"
```


## Encrypted programming
The encrypted programming consists of two steps:
- Create encrypted image
- Program encrypted image

## Create encrypted image
Creates encrypted image for encrypted programming.
### Command: `encrypt-image`
### Parameters
| Name                  | Optional/Required | Description                                                      |
|-----------------------|:-----------------:|------------------------------------------------------------------|
| -i, --image           |     required      | The image to encrypt.                                            |
| -h, --host-key-id     |     required      | Host private key ID (4 - HSM, 5 - OEM).                          |
| -d, --device-key-id   |     required      | Device public key ID (1 - device, 12 - group).                   |
| --key-length          |     optional      | Derived key length.                                              |
| -o, --encrypted-image |     required      | Output file of encrypted image for encrypted programming.        |
| --padding-value       |     optional      | Value for image padding.                                         |
| --probe-id            |     optional      | Probe serial number. Used to read device public key from device. |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json encrypt-image -i BlinkyApp.hex -h 4 -d 1 -o encrypted_image.txt
```

## Program encrypted image
Programs encrypted image.
### Command: `encrypted-programming`
### Parameters
| Name                  | Optional/Required | Description                     |
|-----------------------|:-----------------:|---------------------------------|
| -i, --encrypted-image |     required      | The encrypted image to program. |
| --probe-id            |     optional      | Probe serial number.            |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json encrypted-programming -i encrypted_image.txt
```

### Programming encrypted bootloader
During device provisioning, the bootloader can be programmed in encrypted format.
This requires following steps:

1. Create image certificate for your custom bootloader application (refer [Create image certificate](#create-image-certificate)).
2. Encrypt bootloader application (refer [Create encrypted image](#create-encrypted-image)).
3. Update policy with the encrypted bootloader file:

   In the policy file, set the bootloader mode to _custom_ and provide bootloader program file (_hex_path_) and image certificate (_jwt_path_). To indicate that the image is encrypted, set _encrypted_ field to _true_. If custom bootloader is not encrypted, set _encrypted_ field to _false_ or do not specify it. Absolute or relative path can be used. Relative path is related to the policy file location.
   ```json
   "cy_bootloader":
    {
        "mode": "custom",
        "hex_path": "encrypted_image.txt",
        "jwt_path": "CypressBootloader_CM0p.jwt",
        "encrypted": true
    },
   ```

### Programming encrypted user application
This requires following steps:

1. Encrypt application (refer [Create encrypted image](#create-encrypted-image)).
2. Update policy with the encrypted bootloader file:

   In the policy file _pre_build_ field add _user_apps_ field as shown below. To indicate that the image is encrypted, set _encrypted__ field to _true_. If the application is not encrypted, set encrypted field to _false_. Absolute or relative path can be used. Relative path is related to the policy file location.
   ```json
   "pre_build": {
        ...
        "user_apps": [
            { "encrypted": true, "app": "encrypted_image.txt" },
            { "encrypted": true, "app": "encrypted_image.txt" }
   }
   ```

## CyBootloader and Secure Flash Boot version
Outputs CyBootloader version bundled with the package. Outputs CyBootloader and Secure Flash Boot version programmed into device.
### Command: `version`
### Parameters
| Name       | Optional/Required | Description          |
|------------|:-----------------:|----------------------|
| --probe-id |     optional      | Probe serial number. |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W version
```


## Sign certificate
Signs JSON certificate with the private key.
### Command: `sign-cert`
### Parameters
| Name         | Optional/Required | Description                                                                                              |
|--------------|:-----------------:|----------------------------------------------------------------------------------------------------------|
| --template   |     required      | Certificate template.                                                                                    |
| -k, --key-id |     required      | Private Key ID to sign the certificate with (1 - DEVICE, 4 - HSM, 5 - OEM, 12 - GROUP).                  |
| -o, --output |     optional      | Filename where to save the JWT. If not specified, the input file name with "jwt" extension will be used. |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json sign-cert --template packets/control_dap_cert.json --output packets/control_dap_cert.jwt --key-id 5
```


## Transit to RMA
Transits device to the RMA lifecycle stage using system AP. See the [RMA](#rma) section for the complete flow.

After each reset ROM boot code will wait on OpenRMA system call to open full access. See RMA usage instructions for the complete flow.
### Command `transit-to-rma`
### Parameters
| Name       | Optional/Required | Description                |
|------------|:-----------------:|----------------------------|
| -c, --cert |     required      | Path to debug certificate. |
| --probe-id |     optional      | Probe serial number.       |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W transit-to-rma --cert packets/control_dap_cert.jwk
```


## Open RMA
Enables full access to device in RMA lifecycle stage using system AP. See the [RMA](#rma) section for the complete flow.
### Command `open-to-rma`
### Parameters
| Name       | Optional/Required | Description                |
|------------|:-----------------:|----------------------------|
| -c, --cert |     required      | Path to debug certificate. |
| --probe-id |     optional      | Probe serial number.       |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W open-rma --cert packets/control_dap_cert.jwk
```


## Read public key from device
Reads public key from device.
### Command `read-public-key`
### Parameters
| Name             | Optional/Required | Description                                                                        |
|------------------|:-----------------:|------------------------------------------------------------------------------------|
| -k, --key-id     |     required      | Key ID to read (1 - DEVICE, 4 - HSM, 5 - OEM, 12 - GROUP).                         |
| -f, --key-format |     optional      | Key format (jwk or pem). Default is 'jwk'.                                         |
| -o, --out-file   |     optional      | Filename where to save the key. If not specified, the log file is used for output. |
| --probe-id       |     optional      | Probe serial number.                                                               |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W read-public-key --key-id 5 --out-file oem_pub.jwk
```
or
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W read-public-key --key-id 5 --key-format pem --out-file oem_pub.pem
```


## Read die ID from device
Reads die ID from device.
### Command: `read-die-id`
### Parameters
| Name           | Optional/Required | Description                                                                       |
|----------------|:-----------------:|-----------------------------------------------------------------------------------|
| -o, --out-file |     optional      | Filename where to save die ID. If not specified, the log file is used for output. |
| --probe-id     |     optional      | Probe serial number.                                                              |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W read-die-id -o die_id.json
```


## Commands to use with HSM
### Add metadata to image
Adds metadata to image (header, protected and unprotected TLVs) to convert it into [MCUboot format](https://github.com/mcu-tools/mcuboot/blob/master/docs/design.md#image-format).
#### Command: `image-metadata`
#### Parameters
| Name               | Optional/Required | Description                                                                                                                                                                                                                          |
|--------------------|:-----------------:|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| --image            |     required      | User application image (hex or bin).                                                                                                                                                                                                 |
| -i, --image-id     |     optional      | The ID of the firmware image in the device. The default value is 1.                                                                                                                                                                  |
| --image-type       |     required      | Indicates which type of an image is signed - boot or upgrade.                                                                                                                                                                        |
| -e, --encrypt      |     optional      | Public key PEM-file for the image encryption.                                                                                                                                                                                        |
| -R, --erased-val   |     optional      | The value that is read back from erased flash.                                                                                                                                                                                       |
| --upgrade-mode     |     optional      | Image upgrade mode (_overwrite_ or _swap_). The default value is _overwrite_.                                                                                                                                                        |
| --align            |     optional      | Flash alignment (1, 2, 4, 8). The default value is 8.                                                                                                                                                                                |
| --boot-record      |     optional      | Represents the role of the software component (e.g. CoFM for coprocessor firmware) [max. 12 characters]                                                                                                                              |
| --pubkey           |     optional      | Public key for the further image verification (PEM format). If not specified, user custom key from the policy will be used.                                                                                                          |           
| -o, --output       |     required      | Binary (bin) file where to save the image with metadata.                                                                                                                                                                             |
| --decrypted        |     optional      | A path where to save decrypted image payload (bin). Must be used for signing encrypted images.                                                                                                                                       |                                                                                                                                   
| --tlv              |     optional      | Custom TLV that will be placed into an unprotected area. Add the "0x" prefix if the value should be interpreted as an integer, otherwise it will be interpreted as a string. Specify the option multiple times to add multiple TLVs. |
| --protected-tlv    |     optional      | Custom TLV that will be placed into a protected area. Add the "0x" prefix if the value should be interpreted as an integer, otherwise it will be interpreted as a string. Specify the option multiple times to add multiple TLVs.    |
#### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json image-metadata --image BlinkyApp.hex --output BlinkyApp_meta.bin --pubkey keys/USERAPP_CM4_KEY.pem --image-type BOOT --image-id 1
```

### Extract payload for signing
Extract a part of the image that has to be signed.
#### Command: `extract-payload`
#### Parameters
| Name         | Optional/Required | Description                                             |
|--------------|:-----------------:|---------------------------------------------------------|
| --image      |     required      | Image with MCUboot metadata (bin).                      |
| -o, --output |     required      | A path where to save image that has to be signed (bin). |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W extract-payload --image BlinkyApp_meta.bin --output BlinkyApp_payload.bin
```

### Add signature to image
Adds signature saved to a binary file into existing MCUboot format image.
#### Command: `add-signature`
#### Parameters
| Name            | Optional/Required | Description                                          |
|-----------------|:-----------------:|------------------------------------------------------|
| --image         |     required      | Image with metadata (bin).                           |
| -s, --signature |     required      | Binary file containing signature.                    |
| -o, --output    |     required      | A path where to save image with the signature (bin). |
### Usage example
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W add-signature --image BlinkyApp_meta.bin --output BlinkyApp_signed.bin --signature ec_signature_asn.bin
```


# Using package together with HSM
To protect your private keys, the cryptographic operations can be delegated to a Hardware Security Module (HSM). The flow of using the package with an HSM is different from the standard flow because of the necessity to sign the image using different tool, provided by HSM vendor. HSM gets an image as an input, then signs it, and returns a signature without a payload. Then this signature has to be added to the payload in a specific format.

## Converting key public numbers to JWK
If the HSM provider exports public part of the key as a modulus and exponent, this data must be converted to the PEM format.

Example of the Utimaco CryptoServer public key format:
```ini
# ECC key
CURVE=secp256r1
PUB=0445415FFCCD599E39BE05D303F43BACE8E0CD25999D56F2A8D923195582ADAB8415E56C7B0488CD9BC95550B9B4CA3F524C2F8E1E4EE40E64E977D0F7F205619F
```
Copy the public numbers from the exported key to the _ec_key_tmpl.json_ file located in the _packets_ directory of your project and convert it to JWK:
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json create-keys --template packets/ec_key_tmpl.json
```

## Signing application with HSM
The flow:
1. Export the HSM public key to a file using tools provided by HSM vendor.
2. Convert the exported key to the JWK format.
3. Provision/reprovision device using generated public key.
4. Add metadata to the image (header, protected and unprotected TLVs) to convert it into [MCUboot format](https://github.com/mcu-tools/mcuboot/blob/master/docs/design.md#image-format).
5. Extract payload - extract a part of the image that has to be signed.
6. Sign the payload with HSM.
7. Add the signature returned by HSM to the image with metadata, created in the fourth step.

### Step 1
Using the tools provided by your HSM vendor, export the public key numbers to a file. The key will be added to the image for further verification.
### Step 2
If your HSM vendor allows exporting public keys directly to the JWK format, then this step can be skipped. However, if the HSM vendor exports the public part of the key as a numbers, this data must be converted to the JWK format (see [Converting key public numbers to JWK](#converting-key-public-numbers-to-jwk)).
### Step 3
For the further image verification the public key need to be provisioned/reprovisioned to the device.

Provisioning:
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json provision-device
```
Reprovisioning:
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json re-provision-device
```
### Step 4
Add metadata to the image - [mcuboot header](https://github.com/mcu-tools/mcuboot/blob/master/docs/design.md#image-format), protected TLV, and unprotected TLV.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json image-metadata --image BlinkyApp.hex --output BlinkyApp_meta.bin --pubkey keys/USERAPP_CM4_KEY.pem --image-type BOOT --image-id 1
```
__IMPORTANT:__ in case of using image encryption, provide output file for the decrypted payload. Image signature is calculated based on decrypted data.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json image-metadata --image BlinkyApp.hex --output BlinkyApp_meta.bin --pubkey keys/USERAPP_CM4_KEY.pem --image-type BOOT --image-id 1 --encrypt keys/dev_pub_key.pem --decrypted BlinkyApp_decrypted.bin
```
__NOTE:__ next steps manipulate with binary files.
### Step 5
The MCUboot format image consists of the part that has to be signed, and the part that has not to be signed. To calculate the signature correctly, from the image extract a part that has to be signed.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W extract-payload --image BlinkyApp_meta.bin --output BlinkyApp_payload.bin
```
__IMPORTANT:__ in case of using image encryption, make sure to specify the decrypted payload to HSM. Image signature is calculated based on decrypted data.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W extract-payload --image BlinkyApp_decrypted.bin --output BlinkyApp_payload.bin
```
### Step 6
Use the tools provided by your HSM vendor to sign the payload with the HSM. Save the signature returned by the HSM to a file. The format of the MCUboot signature is ASN.1 (binary decoded).
### Step 7
Run the _add-signature_ command and provide the signature file created by the HSM. As an input image use the image with metadata created in the step #4.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W add-signature --image BlinkyApp_meta.bin --output BlinkyApp_signed.bin --signature ec_signature_asn.bin
```


## Closing All Access Ports
Often it is necessary to close all access ports during provisioning. After closing the access ports, there will be no way to program application.
In this case, the application can be programmed during the provisioning process, when the access ports are open. Refer [Programming encrypted user application](#programming-encrypted-user-application).


## Open CM0 Access Port
_System AP must be enabled since it is used to open CM0 AP._

There is a way to close CM0 access port and allow to open it using a certificate. To close CM0 port with the ability of further opening, provision the device with the following configuration of _m0p_ in the policy file:
```json
"m0p" : {
    "permission" : "allowed",
    "control" : "certificate",
    "key" : 5
}
```
The above configuration means that the CM0 AP can be opened with certificate. The certificate must be signed with the key with ID 5.
The certificate can be found in the packets directory (look for control_dap_cert.json).

### Sign DAP certificate
Once device was provisioned with the above _m0p_ configuration, the AP can be opened with the certificate.

To sign the DAP certificate refer to [Sign certificate](#sign-certificate) section. The key ID used to sign the certificate must match the key ID specified in the policy file _m0p_ properties.

### Re-provision and open CM0 access port
Re-provision device using the certificate to open CM0 access port for programming bootloader program file.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json re-provision-device --control-dap-cert packets/control_dap_cert.jwt
```
_NOTE_: The access port opens for a short time to program bootloader during re-provisioning.


# RMA
Following is the flow for the transition device to the RMA lifecycle stage and open DAP.
## 1. Create a certificate
For the transition of the device into the RMA lifecycle stage you need to create a certificate, which contains the device DIE_ID and is signed with the key specified in the _rma_ section of the policy.
The certificate template is located in the _packets_ directory of the project. _control_dap_cert.json_ defines the DIE_ID of the devices the certificate can be applied to. The default template _min_ and _max_ values are applicable for all devices. Modify it for specific devices only if needed.
### Default Template
```json
{
  "auth": {
    "die_id": {
      "max": {
        "day": 255,
        "lot": 16777215,
        "month": 255,
        "wafer": 255,
        "xpos": 255,
        "year": 255,
        "ypos": 255
      },
      "min": {
        "day": 0,
        "lot": 0,
        "month": 0,
        "wafer": 0,
        "xpos": 0,
        "year": 0,
        "ypos": 0
      }
    }
  }
}
```
### Signing
Make sure you use the ID of the key specified in the _rma_ section of the policy the device has been provisioned with.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W -p policy/policy_single_CM0_CM4_swap.json sign-cert --template packets/control_dap_cert.json --output packets/control_dap_cert.jwt --key-id 5
```
## 2. Transition to RMA
Transition a part from the SECURE to the RMA lifecycle stage. Before the transitioning fuses and flash will be destroyed as specified in the `destroy_fuses` and `destroy_flash` sections of the device policy.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W transit-to-rma --cert packets/control_dap_cert.jwk
```
## 3. Open RMA
To open the DAP of the device in the RMA lifecycle stage use the same certificate as for the transition to RMA.
```bash
$ edgeprotecttools -t CY8CKIT-064B0S2-4343W open-rma --cert packets/control_dap_cert.jwk
```
After successful DAP opening, DO NOT reset the device and launch a debug session with a debugger.


# CyBootloader
By default, the tools use _release_ mode of CyBootloader. This does not output CyBootloader logs to the serial port, but it has a smaller size. The _debug_ mode of CyBootloader allows seeing its logs using the serial port with the baud rate 115200. To change CyBootloader mode, change the `cy_bootloader` field in the policy file:

for the _debug_ mode
```json
"cy_bootloader":
{
    "mode": "debug"
}
```
for the _release_ mode
```json
"cy_bootloader":
{
    "mode": "release"
}
```
## Custom Bootloader
To use a custom bootloader, specify value _custom_ in the _cy_bootloader_ _mode_ field. Also, it requires the specifying bootloader image (_hex_path_) and its certificate (_jwt_path_). A bootloader image certificate is a JWT file that confirms the image's validity. To create an image certificate, use the [image certificate creation](#create-image-certificate) command.
```json
"cy_bootloader":
{
    "mode": "custom",
    "hex_path": "../prebuilt/CyBootloader_WithLogs/CypressBootloader_CM0p.hex",
    "jwt_path": "../prebuilt/CyBootloader_WithLogs/CypressBootloader_CM0p.jwt"
}
```

## Encrypted Bootloader
Refer [Programming encrypted bootloader](#programming-encrypted-bootloader).

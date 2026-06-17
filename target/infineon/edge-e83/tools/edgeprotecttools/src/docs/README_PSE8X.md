# Table of Contents
- [Main features](#main-features)
- [Quick start](#quick-start)
- [Command-line interface](#command-line-interface)
    - [Tool help](#tool-help)
    - [Common options](#common-options)
    - [Create project](#create-project)
    - [Create CSR](#create-csr)
    - [Create IFX OEM Certificate](#create-ifx-oem-certificate)
    - [Create CSR or Certificate from template](#create-csr-or-certificate-from-template)
    - [Device Integrity Exam](#device-integrity-exam)
    - [Provision device](#provision-device)
    - [Reprovision device](#reprovision-device)
    - [Create provisioning packet](#create-provisioning-packet)
    - [Verify provisioning packet](#verify-provisioning-packet)
    - [Image verification](#image-verification)
    - [Create debug token](#create-debug-token)
    - [Read die ID](#read-die-id)
    - [Get firmware version](#get-firmware-version)
    - [Get device info](#get-device-info)
    - [RAM application package](#ram-application-package)
    - [SE_RT_SERVICES update](#se-rt-services-update)
- [Multiple provisioning and reprovisioning](#multiple-provisioning-and-reprovisioning)
- [Provisioning process](#provisioning-process)
- [Using package together with HSM](#using-package-together-with-hsm)
    - [Signing application with HSM](#signing-application-with-hsm)
    - [Signing provisioning packet with HSM](#signing-provisioning-packet-with-hsm)
    - [Signing RAM application package with HSM](#signing-ram-application-package-with-hsm)
    - [Provisioning with prebuilt data](#provisioning-with-prebuilt-data)
    - [Creation and signing a debug token with HSM](#creation-and-signing-a-debug-token-with-hsm)
    - [Creation and signing an RMA token with HSM](#creation-and-signing-an-rma-token-with-hsm)
- [Return Merchandise Authorization (RMA)](#return-merchandise-authorization-rma)
    - [RMA token](#rma-token)
    - [Transition to RMA](#transition-to-rma)


# Main features
* Keys creation - Creates a private-public key pair of the ECDSA/RSA/AES types.
* Integrity exam - Passing an integrity exam before provisioning a device is an option to ensure that the device is a genuine Infineon device and it is in a known state.
* Provisioning - Provisioning is the act of configuring a device with an authorized set of keys, policies, and optionally certificates. Supports SWD and serial interface.
* Signing user applications - Signs a user application with a private key locally or using a Hardware Security Module.
* Debug token - The debug token is used to enable CM33 and/or the system access port when it is temporarily disabled.


# Quick start
## 1. Set a path to the On-Chip debugger
```bash
$ edgeprotecttools set-ocd --name openocd --path <PATH_TO_OPENOCD_ROOT_DIRECTORY>
```
Ensure that you provide the path to the root directory of OpenOCD (NOT _bin_ directory).
Specifying the path is not mandatory if you have ModusToolbox™ installed on your machine. OpenOCD from the ModusToolbox™ directory is used by default.

_Example:_
```bash
$ edgeprotecttools set-ocd --name openocd --path /Users/username/tools/openocd
```

## 2. Define a target
There are two parts in this family, the EPC2 and the EPC4. Use pse8xs2 for the EPC2 device and pse8xs4 for the EPC4 device.

Run the following command and find the name of your target in the list of supported targets.
```bash
$ edgeprotecttools device-list
```
This target name will be used as a `-t` option value with each command.

_Example_:
```bash
$ edgeprotecttools -t pse8xs2 <COMMAND> [OPTIONS]
```

## 3. Create a new project
This copies the list of files required to start using the tool to the current working directory.
```bash
$ edgeprotecttools -t pse8xs2 init
```

## 5. Create keys
Create two private/public key pairs.
```bash
$ edgeprotecttools create-key --key-type ECDSA-P256 --output keys/private0.pem keys/public0.pem
$ edgeprotecttools create-key --key-type ECDSA-P256 --output keys/private1.pem keys/public1.pem
```

## 6. Get a development certificate
Create CSR with public keys and provide it to [Infineon Edge Protect Signing Service](https://osts.infineon.com/epss/home) to generate a certificate, which action authorizes the keys.
```bash
$ edgeprotecttools -t pse8xs2 oem-csr --public-key-0 keys/public0.pem --public-key-1 keys/public1.pem --sign-key-0 keys/private0.pem --sign-key-1 keys/private1.pem --oem "Company Name" --project "Project Name" --project-number 12345678 --cert-type development --output oem_csr.bin
```

## 7. Provision the device
In the `--ifx-oem-cert` CLI argument specify the path to the development certificate received from Infineon.

```bash
$ edgeprotecttools -t pse8xs2 provision-device -p policy/policy_oem_provisioning.json --key keys/private0.pem --ifx-oem-cert oem_cert.bin 
```

## 8. Sign the image
```bash
$ edgeprotecttools sign-image --image image.bin --output image_signed.bin --key keys/private0.pem
```


# Command-line interface
This section contains the main CLI commands. More commands can be found in the tool help.

## Tool help
To see the list of commands supported for PSoC Edge E84:
```bash
$ edgeprotecttools -t pse8xs2 --help
```
To see the list of options for a specific command:
```bash
$ edgeprotecttools -t pse8xs2 <COMMAND> --help
```

## Common options
The interface provides common options. These options are common for all commands and must precede them:

| Name          | Description                                  |
|---------------|----------------------------------------------|
| -t, --target  | Device name or family                        |
| -v, --verbose | Provides debug-level log                     |
| -q, --quiet   | Quiet display option                         |
| --logfile-off | Disabling logging to a file                  |
| --timestamps  | Enable displaying timestamps in log messages |


## Create project
Creates a new project for PSoC Edge E84.
### Command: `init`
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 init
```


## Create CSR
Creates a certificate-signing request (CSR). The CSR contains OEM data and public keys. The CSR is a request to Infineon to authorize the OEM keys.
### Command: `oem-csr`
### Parameters
| Name               | Optional/Required | Description                                                                                                                                                                                                                                                                 |
|--------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| --oem              |     required      | The OEM name.                                                                                                                                                                                                                                                               |
| --project          |     required      | The OEM project name.                                                                                                                                                                                                                                                       |
| --project-number   |     required      | The OEM project number.                                                                                                                                                                                                                                                     |
| --cert-type        |     required      | The type of the certificate - "development" or "production". Defines the lifecycle stage of the device after provisioning. The device stays in DEVELOPMENT LCS if a development certificate is applied. The production certificate advances a device to the PRODUCTION LCS. |
| --public-key-0     |     required      | The path to the primary public key.                                                                                                                                                                                                                                         |
| --public-key-1     |     required      | The path to the secondary public key.                                                                                                                                                                                                                                       |
| -o, --output       |     required      | The path where to save the CSR.                                                                                                                                                                                                                                             |
| --certificate-name |     optional      | The certificate name.                                                                                                                                                                                                                                                       |
| --date             |     optional      | The CSR creation date. The date-time string of the following format: YYYY-MM-DD HH:MM:SS. Example: 2025-03-12 15:59:23. If not provided, the system current date and time will be used.                                                                                     |
| --id               |     optional      | The certificate ID.                                                                                                                                                                                                                                                         |
| --issuer           |     optional      | The issuer name.                                                                                                                                                                                                                                                            |
| --signer-id        |     optional      | The signer ID.                                                                                                                                                                                                                                                              |
| --sign-key-0       |     optional      | The primary key used to sign the CSR. If the signing keys are not specified, an unsigned CSR is generated .                                                                                                                                                                 |
| --sign-key-1       |     optional      | The secondary key used to sign the CSR. If the signing keys are not specified, an unsigned CSR is generated .                                                                                                                                                               |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 oem-csr --public-key-0 oem_public_key_0.pem --public-key-1 oem_public_key_1.pem --sign-key-0 oem_private_key_0 --sign-key-1 oem_private_key_1 --oem "Company Name" --project "Project Name" --project-number 12345678 --cert-type development --output oem_csr.bin
```


## Create IFX OEM Certificate
Creates a IFX OEM certificate based on the provided OEM CSR. The certificate authorizes the OEM public keys.
### Command: `ifx-oem-cert`
### Parameters
| Name               | Optional/Required | Description                                                                                                                                                                                                                                                                 |
|--------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| --id               |     required      | The hexadecimal string containing a unique serial number for the certificate. Example: 045D.                                                                                                                                                                                |
| --signer-id        |     required      | The unique ID of the certificate that corresponds to the signing key.                                                                                                                                                                                                       |
| --csr              |     required      | The path to the OEM CSR.                                                                                                                                                                                                                                                    |
| -o, --output       |     required      | The certificate path.                                                                                                                                                                                                                                                       |
| --key, --key-path  |     optional      | The key to sign the certificate.                                                                                                                                                                                                                                            |
| --algorithm        |     optional      | The signature algorithm. Applicable one of the following values: "ES256", "ES384", "RS256", "RS384". Required only if the signing key is not provided. This is the type of signature that will be attached to this certificate in case of signing the certificate with HSM. |
| --certificate-name |     optional      | The certificate name.                                                                                                                                                                                                                                                       |
| --issuer           |     optional      | The issuer name.                                                                                                                                                                                                                                                            |
| --date             |     optional      | The date of the OEM certificate creation. The date-time string of the following format: YYYY-MM-DDTHH:MM:SS. Example: 2023-11-06T15:59:23. If not specified, the current system time is used.                                                                               |

### Usage example
```bash
$ edgeprotecttools -t pse8xs2 ifx-oem-cert --csr oem_csr.bin --key keys/ifx_private_key.pem --id 045D --signer-id 1 --output ifx_oem_cert.bin
```


## Create CSR or Certificate from template
Creates a CSR or certificate from a template. The template is a JSON file that contains the data required to create a CSR or certificate.
### Command: `create-cert`
### Parameters
| Name              | Optional/Required | Description                                          |
|-------------------|:-----------------:|------------------------------------------------------|
| --template        |     required      | The CSR or Certificate template path.                |
| --output          |     required      | The path where to save the CSR or Certificate.       |
| --json-cert       |     optional      | The path where to save CSR or certificate JSON data. |
| --csr             |     optional      | The CSR path.                                        |
| --key, --key-path |     optional      | The key to sign the certificate.                     |
| --sign-key-0      |     optional      | The primary key used to sign the CSR.                |
| --sign-key-1      |     optional      | The secondary key used to sign the CSR.              |
### Usage example
```bash
# Create a CSR
$ edgeprotecttools -t pse8xs2 create-cert --template packets/template_oem_csr.json --output oem_csr.bin --sign-key-0 keys/oem_private_key_0.pem --sign-key-1 keys/oem_private_key_1.pem
# Create a certificate
$ edgeprotecttools -t pse8xs2 create-cert --template packets/template_oem_cert.json --output oem_cert.bin --csr oem_csr.bin --key keys/ifx_private_key_0.pem 
```


## Device Integrity Exam
The device integrity exam ensures that this is a genuine Infineon device and it is in a known state.
The integrity exam is implemented as a combination of a RAM application collecting device measurements and a host component validating device measurements.
The tool gets the RAM application output and compares it with the device integrity certificate data. This acceptance test is recommended before the device OEM provisioning and determines that there are no modifications of fuses or flash bits.
### Command: `integrity-exam`
### Parameters
| Name              | Optional/Required | Description                                                                                               |
|-------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------|
| --custom-regions  |     optional      | The path to OEM custom regions template. The custom regions used to provide OEM alternative asset hashes. |
| --alias-cert      |     optional      | The path where to save the alias certificate.                                                             |
| --device-cert     |     optional      | The path where to save the device certificate.                                                            |
| --chain-of-trust  |     optional      | The path where to save the IFX chain of trust.                                                            |
| --key, --key-path |     optional      | The key to sign DLM.                                                                                      |
| --probe-id        |     optional      | Probe serial number.                                                                                      |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 integrity-exam --custom-regions packets/integrity_exam_custom_regions.json --alias-cert alias_cert.cbor --device-cert device_cert.cbor --chain-of-trust chain_of_trust_cert.cbor --key keys/oem_rot_private_key_0.pem --display-ifx --display-oem --probe-id 061003B803260400
```

## Integrity Exam Hashes
Fills device integrity exam template with new hashes.
The hashes are extracted from app response.
### Command: `integrity-exam-hashes`
### Parameters
| Name        | Optional/Required | Description                                    |
|-------------|:-----------------:|------------------------------------------------|
| --cert      |     required      | The path to integrity exam certificate.        |
| --response  |     required      | The path to integrity exam app response data.  |
| --output    |     required      | The path where to save the populated template. |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 integrity-exam-hashes --cert integrity_exam_custom_regions.json --response output.bin --output updated_hashes.json
```


## Provision device
Configuring a device with a set of keys and policies.
### Command: `provision-device`
### Parameters
| Name              | Optional/Required | Description                                                                                                                                                                                                                 |
|-------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -p, --policy      |     required      | The path to the provisioning policy.                                                                                                                                                                                        |
| --key, --key-path |     optional      | Path to the private key used to sign provisioning packet(s).                                                                                                                                                                |
| --kid             |     optional      | Key ID.                                                                                                                                                                                                                     |
| --probe-id        |     optional      | Probe serial number.                                                                                                                                                                                                        |
| --existing-packet |     optional      | Skip provisioning packet creation and use the existing packet. This may be useful when a packet with a RAM application package already exists and the tool does not have to generate it again.                              |
| --ifx-oem-cert    |     optional      | The path to OEM certificate.                                                                                                                                                                                                |
| --revoke          |     optional      | The path to key revocation token. Depending on the configuration of the token template, the token allows to revoke the following active keys: IFX_ROT_KEY, IFX_RMA_MASTER_KEY, IFX_FW_INTEGRITY_KEY, IFX_FW_ENCRYPTION_KEY. |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 provision-device -p policy/policy_oem_provisioning.json --key private.key -–ifx-oem-cert keys/ifx_oem_cert.bin
```


## Reprovision device
Reconfiguring a device with the updated policies.
### Command: `reprovision-device`
### Parameters
| Name              | Optional/Required | Description                                                                                                                                                                                                                 |
|-------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -p, --policy      |     required      | The path to the reprovisioning policy.                                                                                                                                                                                      |
| --key, --key-path |     optional      | Path to the private key used to sign provisioning packet(s).                                                                                                                                                                |                                                                                                                                                         
| --kid             |     optional      | Key ID.                                                                                                                                                                                                                     |
| --revoke          |     optional      | The path to key revocation token. Depending on the configuration of the token template, the token allows to revoke the following active keys: IFX_ROT_KEY, IFX_RMA_MASTER_KEY, IFX_FW_INTEGRITY_KEY, IFX_FW_ENCRYPTION_KEY. |
| --probe-id        |     optional      | Probe serial number.                                                                                                                                                                                                        |
| --existing-packet |     optional      | Skip provisioning packet creation and use the existing packet. This may be useful when a packet with a RAM application package already exists and the tool does not have to generate it again.                              |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 reprovision-device -p policy/policy_oem_provisioning.json --key private.key
```


## Create provisioning packet
Creates a provisioning/reprovisioning data packet without starting the device provisioning process.
### Command: `create-provisioning-packet`
### Parameters
| Name                  | Optional/Required | Description                                                                                                                                                                                                                 |
|-----------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -p, --policy          |     required      | The path to the provisioning policy.                                                                                                                                                                                        |
| -k, --key, --key-path |     optional      | The path to the key used to sign the provisioning packet. If not specified, an unsigned packet will be created, containing only the data required for signing (the protected part).                                         |
| --signature           |     optional      | The path to the file containing the signature to add to the provisioning packet. Used to sign the reprovisioning packet with HSM ([Signing provisioning packet with HSM](#signing-provisioning-packet-with-HSM)).           |
| --kid                 |     optional      | The ID of the key used to verify the packet.                                                                                                                                                                                |
| -o, --output          |     optional      | The path where to save the packet - applicable with the '--signature' option only.                                                                                                                                          |
| --revoke              |     optional      | The path to key revocation token. Depending on the configuration of the token template, the token allows to revoke the following active keys: IFX_ROT_KEY, IFX_RMA_MASTER_KEY, IFX_FW_INTEGRITY_KEY, IFX_FW_ENCRYPTION_KEY. |
| --ifx-oem-cert        |     optional      | The path to OEM certificate.                                                                                                                                                                                                |
### Usage example
#### Signed
```bash
# Signed
$ edgeprotecttools -t pse8xs2 create-provisioning-packet -p policy/policy_oem_provisioning.json --key keys/private0.pem
# Unsigned
$ edgeprotecttools -t pse8xs2 create-provisioning-packet -p policy/policy_oem_provisioning.json
# Using signature file
$ edgeprotecttools -t pse8xs2 create-provisioning-packet -p policy/policy_oem_provisioning.json --signature signature.bin
```


## Verify provisioning packet
Verifies the provisioning packet signature with a key.
### Command: `verify-packet`
### Parameters
| Name              | Optional/Required | Description         |
|-------------------|:-----------------:|---------------------|
| --packet          |     required      | Path to the packet. |
| --key, --key-path |     required      | Path to public key. |
| --kid             |     optional      | Key ID.             |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 verify-packet --packet in_params.bin --key keys/public0.pem
```


## Image verification
Verifies an image with a key or IFX OEM certificate.
### Command: `verify-image`
### Parameters
| Name               | Optional/Required  | Description                                                        |
|--------------------|:------------------:|--------------------------------------------------------------------|
| --image            |      required      | The path to the image.                                             |
| --cert             |      optional      | The path to the IFX OEM certificate. Can be used instead of a key. |
| --key, --key-path  |      optional      | The path to the public key.                                        |
| --kid              |      optional      | The key ID to select the key from the certificate (0 or 1).        |
### Usage example
```bash
# Using a key
$ edgeprotecttools -t pse8xs2 verify-image --image image.bin --key keys/public0.pem
# Using IFX_OEM_CERT
$ edgeprotecttools -t pse8xs2 verify-image --image image.bin --cert ifx_oem_cert.bin --kid 0
```


## Create debug token
The debug token is used to enable CM33 or the system access port when it is temporarily disabled. Note that the token cannot enable an access port that is permanently disabled by the access restrictions. Also, the debug token can be used to enable/disable invasive or non-invasive debugging for CM33-AP.

The command creates a signed debug token binary based on the template. By default, the template is configured to be applicable for any die ID. See the [Read die id](#read-die-id) section to the find die ID of your device. See the [Get device info](#get-device-info) section to find the silicon ID, family ID, and revision ID needed to create a certificate.
### Command: `debug-token`
### Parameters
| Name               | Optional/Required  | Description                                                                                                                                                     |
|--------------------|:------------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -t, --template     |      optional      | The path to the token template. The template can be found in the _packets_ directory of the project (_debug_token.json_).                                       |
| --key, --key-path  |      optional      | The path to the private key to sign the token. If the token to be signed by HSM, do not specify the option.                                                     |
| --signature        |      optional      | The option for signing an existing certificate using an existing signature file. Used to add a signature generated by HSM. The format is `[token] [signature]`. |
| -o, --output       |      required      | The file where to save the debug token.                                                                                                                         |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 debug-token --template packets/debug_token.json -o packets/debug_token.bin --key keys/private0.pem
```


## Read die ID
Reads the die ID from a device.
### Command: `read-die-id`
### Parameters
| Name           | Optional/Required | Description                                                                                                        |
|----------------|:-----------------:|--------------------------------------------------------------------------------------------------------------------|
| -o, --out-file |     optional      | The name of the file where to save the die ID. If not specified, the information will be displayed in the console. |
| --probe-id     |     optional      | Probe serial number.                                                                                               |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 read-die-id
```


## Get firmware version
Outputs version of ROM_BOOT, RRAM_SE_BOOT, BASE_SE_RT_SERVICES, SE_RT_SERVICES and CM33_L1_BOOT.
### Command: `version`
### Parameters
| Name       | Optional/Required | Description          |
|------------|:-----------------:|----------------------|
| --probe-id |     optional      | Probe serial number. |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 -p version
```


## Get device info
Gets device information - silicon ID, silicon revision, and family ID.
### Command: `device-info`
### Parameters
| Name       | Optional/Required | Description                                                                              |
|------------|:-----------------:|------------------------------------------------------------------------------------------|
| --probe-id |     optional      | Probe serial number.                                                                     |
| --ap       |     optional      | The access port used to read the data - "cm33" or "sysap". The default value is "sysap". |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 device-info
```


## RAM application package
Builds the RAM application and its input parameters into a single signed package.
### Command: `build-ramapp-package`
### Parameters
| Name              | Optional/Required | Description                                                                  |
|-------------------|:-----------------:|------------------------------------------------------------------------------|
| -a, --app         |     required      | The path to the RAM application binary.                                      |
| -o, --output      |     required      | The path where to save the RAM application package.                          |
| --inparams        |     optional      | The path to the application input parameters.                                |
| --key, --key-path |     optional      | The path to the ECDSA private key used to sign the package.                  |
| --hex-addr        |     optional      | Adjusts the address in the hex output file. The default value is 0x34000000. |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 build-ramapp-package --app packets/apps/prov_oem/cyapp_prov_oem_signed.bin --inparams packets/apps/prov_oem/in_params.bin --key keys/private0.pem --output packets/apps/prov_oem/cyapp_prov_oem_dlm.hex
```


## SE RT Services update
Updates SE_RT_SERVICES using the provided update image
### Command: `se-rt-services-update`
### Parameters
| Name              | Optional/Required | Description                                         |
|-------------------|:-----------------:|-----------------------------------------------------|
| --image           |     optional      | The path to se_rt_services image.                   |
| --key             |     optional      | The key to sign se_rt_services package.             |
| --probe-id        |     optional      | Probe serial number.                                |
| --existing-packet |     optional      | Skip provisioning packet creation and use existing. |
### Usage example
```bash
$ edgeprotecttools -t pse8xs4 se-rt-services-update --image packets/apps/se_rt_services_update/se_rt_services_update-1.1.0.2735.img --key keys/oem_rot_private_key_0.pem --probe-id 061003B803260400
```


# Multiple provisioning and reprovisioning
## Development flow
When the device is in the NORMAL_PROVISIONED LCS, its configuration can be replaced in whole as many times as needed. This is called multiple provisioning. To update the extended boot image a development certificate must be provided (`ifx_oem_cert` property in the policy).
## Production flow
Once the development is complete and you want to go to production, get a "production" type of certificate. Get the certificate by creating a new CSR for the "production" certificate.
To advance the device to the SECURE LCS, provide the production certificate. When the device is in the SECURE LCS, it can be reprovisioned, which means it is possible to change the configuration allowed by the `reprovisioning` section of the policy only.
Before reprovisioning, remove or keep empty the `ifx_oem_cert` section.


# Provisioning process
This section describes what happens when we run the `provision-device` command.
The provisioning process is done by the _prov_oem_ RAM application located in the _packets/apps_ directory of the project. However, before programming the RAM application into the device, we need to provide input parameters for the application. In the context of the RAM application, the input parameters are the data user provides in the policy file. Before starting the provisioning process, the tool generates input parameters binary based on the data in the policy file and signs it with the key specified in the `--key` argument.
The second step is creating a single image that contains the application and the input parameters. The input parameters binary and the RAM application binary are merged into a single file and signed with the same key specified in the `--key` argument.
When the RAM application package is ready, it is programmed into the device, and the provisioning process starts and configures the device according to the selected policy.


# Using package together with HSM
All the above examples describe the flow when the private keys are available locally on the computer. However, to protect your private keys, the cryptographic operations can be delegated to a Hardware Security Module (HSM). The flow of using the package with an HSM is different from the standard flow because the image must be signed using a different tool provided by the HSM vendor. Data in a few steps: generate unsigned data, provide the data to HSM, grab the signature, and merge the unsigned data with the signature. However, the data has different formats and must be processed by different flows.

## Signing application with HSM
Refer to the [Signing application with HSM](https://github.com/Infineon/edgeprotecttools/blob/master/docs/README_GENERAL.md#signing-application-with-HSM) section.

## Signing provisioning packet with HSM
The flow:
1. Generate a non-signed provisioning packet with data to be cryptographically protected.
2. Get the signature from HSM.
3. Generate a packet containing protected data, non-protected data, and the signature.

### Step 1
The packet contains protected and non-protected data. Get the protected data only. Create a provisioning packet without using the`--key` option, which will create the packet containing only data to be signed.
```bash
$ edgeprotecttools -t pse8xs2 create-provisioning-packet -p policy/policy_oem_provisioning.json --output packets/in_params.bin
```
### Step 2
Use the tools provided by your HSM provider to sign the data packet on the HSM machine. You can find the packet location in the previous step output. Save the signature returned by the HSM to a file.
### Step 3
Run the same command and provide the signature file created by the HSM. The tool will generate a new packet containing protected data, non-protected data, and the signature.
```bash
$ edgeprotecttools -t pse8xs2 create-provisioning-packet -p policy/policy_oem_provisioning.json --signature keys/hsm_signature.bin --output packets/in_params.bin
```
__IMPORTANT:__ Do not change the policy file content between steps 1 and 3.


## Signing RAM application package with HSM
The section [Provisioning process](#provisioning-process) describes what is the RAM application package and how to use it. To create such a package, we use the private key to sign input parameters and the entire package. However, if the key is stored in HSM, create a package in a few steps:
1. Follow the instructions from [Signing provisioning packet with HSM](#signing-provisioning-packet-with-hsm) to create input parameters for the RAM application.
2. Follow the instructions from [Signing application with HSM](#signing-application-with-hsm) to create the RAM app package.


## Provisioning with prebuilt data
When the keys are stored in HSM, the provisioning data is built and signed manually. Use the `provision-device` command with the `--existing-packet` option. The option indicates that the RAM application package will not be built and the tool will use the existing one. Follow the [Signing RAM application package with HSM](#signing-ram-application-package-with-hsm) instructions and run the provisioning:
```bash
$ edgeprotecttools -t pse8xs2 provision-device -p policy/policy_oem_provisioning.json --existing-packet
```


## Creation and signing a debug token with HSM
The flow:
1. Create a non-signed token.
2. Get the signature using HSM.
3. Add a signature returned by the HSM to the token.

### Step 1
Create a token but do not specify the `--key` option.
```bash
$ edgeprotecttools -t pse8xs2 debug-token --template packets/debug_token.json --output packets/debug_token_unsigned.bin
```
### Step 2
Use the tools provided by your HSM provider to sign the extended image on the HSM machine. Save the signature returned by the HSM to a file.
### Step 3
Run the _debug-token_ command and specify the `--signature` option as an unsigned token and the signature file created by the HSM.
```bash
$ edgeprotecttools -t pse8xs2 debug-token --signature packets/debug_token_unsigned.bin signature.bin --output packets/debug_token_signed.bin
```


## Creation and signing an RMA token with HSM
The flow:
1. Create a non-signed token.
2. Get the signature using HSM.
3. Add a signature returned by the HSM to the token.

### Step 1
Create a token but do not specify the `--key` option.
```bash
$ edgeprotecttools -t pse8xs2 rma-token --template packets/rma_token.json --output packets/rma_token_unsigned.bin
```
### Step 2
Use the tools provided by your HSM provider to sign the extended image on the HSM machine. Save the signature returned by the HSM to a file.
### Step 3
Run the _rma-token_ command and specify the `--signature` option as an unsigned token and the signature file created by the HSM.
```bash
$ edgeprotecttools -t pse8xs2 rma-token --signature packets/rma_token_unsigned.bin signature.bin --output packets/rma_token_signed.bin
```


# Return Merchandise Authorization (RMA)
The flow for the transition device to the RMA lifecycle stage and open DAP.
## RMA token
For the transition of the device into the RMA lifecycle stage you need to create a token, which contains the device DIE_ID and is signed with the OEM key.
The token template is located in the _packets_ directory of the project. _rma_token.json_ defines the DIE_ID of the devices the token can be applied to. The default template min and max values are applicable for all devices. Modify it for specific devices only if needed.
The command creates "Transit to RMA" or "Open RMA" token binary based on a template. The "Transit to RMA" token is used to transit the device to the RMA LCS. The "Open RMA" is used to debug the device which is in the RMA LCS.
### Command: `rma-token`
### Parameters
| Name               | Optional/Required | Description                                                                                                                                                     |
|--------------------|:-----------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -t, --template     |     optional      | The path to the token template. The template can be found in the _packets_ directory of the project (_rma_token.json_).                                         |
| --key, --key-path  |     optional      | The path to the private key used to sign the token. If the token has to be signed by HSM, do not specify the option.                                            |
| --signature        |     optional      | The option for signing an existing certificate using an existing signature file. Used to add a signature generated by HSM. The format is `[token] [signature]`. |
| -o, --output       |     required      | The file where to save the debug token.                                                                                                                         |
| --open-rma         |     optional      | Indicates whether to create "Open RMA" token. If the flag is not specified the "Transit to RMA" will be generated.                                              |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 rma-token --template packets/rma_token.json -o packets/rma_token.bin --key keys/private0.pem
```
## Transition to RMA
The command advances the device lifecycle stage to RMA. The certificate must be signed with the OEM key.
### Command: `transit-to-rma`
### Parameters
| Name       | Optional/Required | Description                         |
|------------|:-----------------:|-------------------------------------|
| --probe-id |     optional      | Probe serial number.                |
| --token    |     optional      | Path to the "Transit to RMA" token. |
### Usage example
```bash
$ edgeprotecttools -t pse8xs2 transit-to-rma --token packets/rma_token.bin
```
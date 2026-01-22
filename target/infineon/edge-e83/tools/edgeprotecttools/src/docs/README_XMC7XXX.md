# Table of Contents
- [Main features](#main-features)
- [Quick start](#quick-start)
- [Usage example](#usage-example)
- [Command-line interface](#command-line-interface)
    - [Tool help](#tool-help)
    - [Common options](#common-options)
    - [Create keys](#create-keys)
    - [Sign image](#sign-image)
    - [Convert bin to hex](#convert-bin-to-hex)

# Main features
* [Create keys](#create-keys) - A key is a file used to authorize access to device data. There must be a common key pair between the secure device and user application. A device must be provisioned with a public key and the user application must be signed with a corresponding private key from the same pair.
* [Sign a user application](#sign-image) - To run a user application on a secure device, the application must be signed with the key.

# Quick start

## 1. Define a target
Run the following command and find the name of your target in the list of supported targets.
```bash
$ edgeprotecttools device-list
```
This target name will be used as a `-t` option value with each command.

_Example_:
```bash
$ edgeprotecttools -t xmc7200 <COMMAND> [OPTIONS]
```

## 2. Create keys
The private key is used to sign the image with the user application. Create a private key.

```bash
$ edgeprotecttools -t <TARGET> create-key --key-type <KEY_TYPE> --output <PRIVATEKEY_PATH> <PUBLICKEY_PATH> [OPTIONS]
```

## 3. Sign the image
```bash
$ edgeprotecttools -t <TARGET> sign-image --image <IMAGE_PATH> --output <OUTPUT_PATH> --key-path <KEY_PATH> [OPTIONS]
```

# Usage example
```bash
# Generate a new RSA-2048 key pair in the PEM format
$ edgeprotecttools -t xmc7200 create-key --key-type rsa2048 --output private.pem public.pem --format PEM

# Sign the image
$ edgeprotecttools -t xmc7200 sign-image --key-path private.pem --image example-blinky.hex --output example-blinky-signed.hex 
```

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
| -v, --verbose | Provides debug-level log.                    |
| -q, --quiet   | Quiet display option.                        |
| --logfile-off | Avoids logging into file.                    |
| --timestamps  | Enable displaying timestamps in log messages |


## Create keys
Creates keys specified in the policy file for the image signing.
### Command: `create-key`

### Parameters
| Name                                                           | Optional/Required | Description                                              |
|----------------------------------------------------------------|:-----------------:|----------------------------------------------------------|
| --key-type [RSA2048&#124;RSA3072&#124;RSA4096&#124;ECDSA-P256] |     required      | Key type.                                                |
| -o, --output                                                   |     required      | The output paths for generated private and public key.   |
| --format [PEM&#124;DER&#124;JWK]                               |     optional      | Key format.                                              |

### Usage example
```bash
# Generate a new ECDSA-P256 key pair in the JSON Web Key format
$ edgeprotecttools -t xmc7100 create-key --key-type ecdsa-p256 --output private.jwk public.jwk --format JWK

# Generate a new RSA-4096 key pair in the PEM format
$ edgeprotecttools -t xmc7100 create-key --key-type rsa4096 --output private.jwk public.jwk --format PEM
```

## Sign image
Signs the user application with a key.

The file specified in the `--image` option will be signed and saved to the file specified in the `--output` option. 
### Command: `sign-image`
### Parameters
| Name                             | Optional/Required | Description                                                                                                                                                                                                                           |
|----------------------------------|:-----------------:|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| -i,--image                       |     required      | User application image (hex or bin).                                                                                                                                                                                                  |
| --key-path                       |     required      | The key used to sign the image.                                                                                                                                                                                                       |
| -R, --erased-val                 |     optional      | The value that is read back from erased flash.                                                                                                                                                                                        |
| -o, --output                     |     required      | Signed image output file.                                                                                                                                                                                                             |
| -H, --header-size                |     optional      | Sets image header size.                                                                                                                                                                                                               |
| -S, --slot-size                  |     optional      | Sets maximum slot size. The default value is 0x20000 (=128KB).                                                                                                                                                                        |
| --hex-addr                       |     optional      | Adjust address in hex output file.                                                                                                                                                                                                    |
| --pad                            |     optional      | Add padding to the image trailer.                                                                                                                                                                                                     |
| --overwrite-only                 |     optional      | Use Overwrite mode instead of Swap.                                                                                                                                                                                                   |
| -v, --version                    |     optional      | Sets image version in the image header.                                                                                                                                                                                               |
| -d, --dependencies               |     optional      | Add dependence on another image, format: "(<image_ID>,<image_version>), ... "                                                                                                                                                         |
| --align [1&#124;2&#124;4&#124;8] |     optional      | Sets flash alignment. The default value is 8.                                                                                                                                                                                         |
| --min-erase-size                 |     optional      | Sets minimum erase size of memory. The default value is 0x8000 (=32KB).                                                                                                                                                               |
| --protected-tlv                  |     optional      | Custom TLV that will be placed into a protected area. Add the "0x" prefix if the value should be interpreted as an integer, otherwise it will be interpreted as a string. Specify the option multiple times to add multiple TLVs      |
| --tlv                            |     optional      | Custom TLV that will be placed into a non-protected area. Add the "0x" prefix if the value should be interpreted as an integer, otherwise it will be interpreted as a string. Specify the option multiple times to add multiple TLVs. |

### Usage example
```bash
# Sign the image with the additional protected and non-protected TLVs
$ edgeprotecttools -t xmc7200 sign-image --key-path private.jwk --image example-blinky.hex --output example-blinky-signed.hex  --tlv 0xbb 0xdddddddd --tlv 0xaa 0xff --protected-tlv 0xee 0x12345678

# Sign the image and pad it with zeros up to the slot size
$ edgeprotecttools -t cyw20829 -p policy/policy_secure.json sign-image --image example-blinky.hex --output example-blinky-signed.hex --key-path private.pem --pad --overwrite-only --slot-size 0x10000 --header-size 0x400
```

## Signing the image in the CySAF format
Signs the application in Infineon secure application format (CySAF)

The ELF file specified in the `--image` option will be signed and saved to the ELF file specified in the `--output` option. 

Specify the following symbols and sections in ELF image file to be able to sign it. 

| Section/symbol name       | Description                                                                                                 |
|---------------------------|-------------------------------------------------------------------------------------------------------------|
| .cy_app_signature         | The section where the digital signature will be written.                                                    |
| __cy_app_verify_start     | The symbol, which defines the first address of the memory area whose digital signature is being calculated. |
| __cy_app_verify_length    | The symbol, which defines the length of the memory area whose digital signature is being calculated.        |

### Command: `sign-cysaf`
### Parameters
| Name                      | Optional/Required | Description                                        |
|---------------------------|:-----------------:|----------------------------------------------------|
| -i,--image                |     required      | User application image in CySAF format (ELF only). |
| --key-path                |     required      | The RSA key used to sign the image.                |
| -o, --output              |     required      | The signed image output file.                      |


### Usage example
```bash
$ edgeprotecttools -t xmc7100 sign-cysaf --image image.elf --output image_signed.elf --key-path private.pem 
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

## Convert key to other formats
Converts key to one of the following formats:
1. C-array: converts **RSA public** or **ECDSA public** key to C-array and its length
 
```c
const unsigned char rsa_pub_key[] = {
    ...
};

const unsigned int rsa_pub_key_len = ...;
```

or

```c
const unsigned char ecdsa_pub_key[] = {
    ...
};

const unsigned int ecdsa_pub_key_len = ...;
```

2. Secure boot RSA public key format defined in AN234802: converts **RSA public** key to file that can be included into application
```c
#include "cmsis_compiler.h"
#include "cy_crypto_common.h"
#include "cy_si_config.h"
#include "cy_si_keystorage.h"
#include "cy_syslib.h"

CY_SECTION(".cy_sflash_public_key") __USED const cy_si_stc_public_key_t cy_publicKey =
{
    .objSize = sizeof(cy_si_stc_public_key_t),
    .signatureScheme = 0UL,
    .publicKeyStruct =
    {
        .moduloAddr = CY_SI_PUBLIC_KEY + offsetof(cy_si_stc_public_key_t, moduloData),
        .moduloSize = CY_SI_PUBLIC_KEY_SIZEOF_BYTE * CY_SI_PUBLIC_KEY_MODULOLENGTH,
        .expAddr = CY_SI_PUBLIC_KEY + offsetof(cy_si_stc_public_key_t, expData),
        .expSize = CY_SI_PUBLIC_KEY_SIZEOF_BYTE * CY_SI_PUBLIC_KEY_EXPLENGTH,
        .barrettAddr = CY_SI_PUBLIC_KEY + offsetof(cy_si_stc_public_key_t, barrettData),
        .inverseModuloAddr = CY_SI_PUBLIC_KEY + offsetof(cy_si_stc_public_key_t, inverseModuloData),
        .rBarAddr = CY_SI_PUBLIC_KEY + offsetof(cy_si_stc_public_key_t, rBarData)
    },
    .moduloData =
    { 
        // N(Modulus)
    },
    .expData =
    { 
        // E(Exponent)
    },
    .barrettData =
    { 
        // K1
    },
    .inverseModuloData =
    { 
        // K2
    },
    .rBarData =
    { 
        // K3
    }
};
```
### Command: `convert-key`
### Parameters
| Name           | Optional/Required | Description                                                                        |
|----------------|:-----------------:|------------------------------------------------------------------------------------|
| -k, --key-path |     required      | Input key path (supports keys in PEM, DER, JWK formats)                            |
| -o, --output   |     required      | Output file                                                                        |
| -f, --fmt      |     required      | Output key format. Available values: "pem", "der", "jwk", "secure_boot", "c_array" |
| --endian       |     optional      | Byte order. Available values: "little", "big" (default: "little")                  |
### Usage example
```bash
# Convert key in JWK format to PEM format
$ edgeprotecttools convert-key --key-path private.json --output private.pem --fmt pem

# Represents a key as a C structure to include it into application
$ edgeprotecttools convert-key --key-path public.der --output secure_boot_key.c --fmt secure_boot

# Represents a key as a C array to include it into application
$ edgeprotecttools convert-key --key-path public.jwk --output array_key.c --fmt c_array
```

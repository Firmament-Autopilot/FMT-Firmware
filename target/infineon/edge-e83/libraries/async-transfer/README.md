# Async Transfer Utility Library

## Overview

Async Transfer Utility Library provides an implementation of data transfer functions in which the calling
application initiates the data transfer on the desired communication peripheral and then the data transfer
happens in the background without the application involvement.

## Features

* Both read and write transfers can be performed.
* Transfers can performed via either CPU copy or DMA.
* One transfer in each of direction (read and write) can be pending at the same time.
* A callback can be invoked on completion of a transfer.
* It is possible to query whether an async-transfer instance is available in a given direction.
* An in-progress transfer can be aborted.
* Repeated transfers can be performed without re-initializing.
* Multiple instances of the async transfer library can co-exist, managing different communications interfaces.
* Support data cache (DCACHE) handling if DMA is performed.

## Interface
This library does not have direct knowledge of the underlying communication peripheral being used
and the users of the library shall set up the necessary interface (`mtb_async_transfer_interface_t` )
needed to support the background transfer on the specific communication peripheral. The users can register for
callbacks to be invoked when the async transfer is complete using `mtb_async_transfer_register_callback`

## DCACHE Management
\anchor DCACHE_Management
The implementation of the cache management is based on the following cache policy and configuration:

* Write-back with read and write allocate: WB-RWA
* Cache line size of 32 bytes
* All memory in application is assumed to be cacheable

When working with DCACHE, cache coherency issues can be encountered when multiple bus masters access the same region of memory. There are two main scenarios to consider in the case where one of these is the CPU with DCACHE enabled, and the other is a peripheral such as a DMA. Suppose that both access the same memory region located in SRAM. Cache coherency issues can occur depending on the ordering in which the bus masters access that memory and which operations are performed on it.

1. CPU writes to SRAM, DMA reads the content: When the CPU writes to SRAM, only the cache is updated and not the actual memory. When the DMA reads, it reads the old value in the actual memory.
2. DMA writes to SRAM, CPU reads the content: When the DMA writes to SRAM, it is updated in the actual memory. When the CPU reads from that memory, it reads the old value in the cache.

To avoid running into these issues, This library must perform the following operations.

1. CPU writes to SRAM, DMA reads the content: Clean the cache (SCB_CleanDCache_by_Addr) after CPU write.
2. DMA writes to SRAM, CPU reads the content: Invalidate the cache (SCB_InvalidateDCache_by_Addr) before CPU read.

Cache clean and invalidate operations are performed at a granularity of the cache line size (i.e. 32 bytes). Therefore, all affected memory regions must also be aligned to 32 bytes and suitably padded to be a multiple of 32 bytes. Without proper alignment and padding, adjacent data will become corrupted during these operations.

This library cannot manage all the memory, such as data buffers passed in by the application. It is the responsibility of the application to properly align and pad the data. Refer to the individual driver API documentation on where these operations should be applied.

## More information

For more information, refer to the following documents:

* [ModusToolbox Middleware Template API Reference Guide](https://infineon.github.io/async-transfer/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software)
* [Infineon Technologies AG](https://www.infineon.com)

© 2022, Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation.

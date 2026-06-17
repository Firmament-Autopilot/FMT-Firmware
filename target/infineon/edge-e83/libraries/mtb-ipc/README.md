# MTB IPC Library

## Overview
The IPC driver allows communication between multiple CPUs or between multiple tasks
operating in different domains within a single CPU. It supports binary semaphores 
and message queues, similar to how they are used for task interactions in an RTOS envrionment.
It also supports unidirectional mailboxes, that provide a middle-ground between the communication of the other two constructs.
This allows multiple use cases related to sending and receiving data, with the MTB IPC ensuring shared memory regions are protected.

Use the MTB IPC library to communicate between processes and protect data stored in shared memory.

## Features
* Binary Semaphores for signaling and protection of data
* RTOS-like Queue with put and get commands to send protected data to other processes
* Scalable solutions for lower shared memory consumption.
* Mailboxes for one way communication across cores.

## Quick Start
Refer to the API Reference Quick Start section for step-by-step instruction how to enable the MTB IPC Middleware Library.

## More information
For more information, refer to the following documents:
* [MTB IPC Middleware API Reference Guide](https://infineon.github.io/mtb-ipc/html/group__group__mtb__ipc.html)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox�](https://www.cypress.com/products/modustoolbox-software-environment)

---
� Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2025.

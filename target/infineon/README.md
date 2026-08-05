Infineon Edgi-X Flight Controller
============================

Edgi-X is a professional, high-performance open-source autopilot hardware co-developed by the FMT and RT-Thread teams in collaboration with Infineon. This flight controller is equipped with the latest PSoC Edge E83 chip, featuring a dual-core architecture with M55 and M33 cores, enabling high performance and fine-grained power optimization.

The PSoC™ Edge E83 series Arm® Cortex®-M microcontrollers (MCUs) combine high performance with low power consumption and integrated security features, while also incorporating advanced machine learning (ML) acceleration capabilities for next-generation applications. This MCU series is based on the Arm Cortex-M55, supporting Helium DSP, and is paired with an Ethos-U55 NPU; it also includes a low-power Cortex-M33, together with Infineon's ultra-low-power NNLite hardware accelerator, designed to accelerate neural network computations in machine learning and AI applications.

In addition to standard external interfaces such as UART, SPI, I2C, PWM, and USB, Edgi-X also provides CAN bus and Ethernet interfaces, meeting the requirements of industrial scenarios and high-bandwidth network data transmission applications. Edgi-X features a compact and lightweight design, with dimensions of 56.0mm × 37.0mm × 13.0mm and a weight of only 40.5g.

Edgi-X is pre-installed with the FMT firmware and can be used in application fields such as drones, unmanned ground vehicles, unmanned surface vessels, and robotics. FMT is a next-generation open-source autonomous driving system that supports Model-Based Design (MBD). Using MATLAB/Simulink, algorithm models can be quickly built in a graphical manner, and with one-click automatic code generation, they can be easily deployed onto the flight controller hardware, greatly improving research and development efficiency. It serves as an ideal platform for advanced algorithm validation and secondary development.

<div align=center><img src="https://docs.sieon.net/edgi-x/figures/E83.png" width="50%"></div>

## Wiki

https://docs.sieon.net/edgi-x

## Port Mapping

| UART  | Device  | Port     |
| ----- | ------- | -------- |
| UART1 | serial0 | DEBUG    |
| UART6 | serial1 | TELEM1   |
| UART2 | serial2 | TELEM2   |
| UART3 | serial3 | GPS1     |
| UART4 | serial4 | GPS2     |

| SPI  | Device    | Port    |
| ---- | --------- | ------- |
| SPI2 | spi2_dev1 | SPI CS1 |
| SPI2 | spi2_dev2 | SPI CS2 |
| SPI2 | spi2_dev3 | SPI CS3 |

| I2C  | Device | Port     |
| ---- | ------ | -------- |
| I2C1 | i2c1   | GPS1     |
| I2C2 | i2c2   | GPS2     |
| I2C3 | i2c3   | UART/I2C |

| CAN  | Device | Port |
| ---- | ------ | ---- |
| CAN1 | can0   | CAN |

| PWM      | Device   | Port       |
| -------- | -------- | ---------- |
| MAIN OUT | main_out | M1-M8     |
| AUX OUT  | aux_out  | A1-A8     |

## Maintainer
RT-Thread team, https://www.rt-thread.org/

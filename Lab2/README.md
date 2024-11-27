# Custom Linux Kernel Module - `lkm`

This is a simple example of a Linux kernel module (LKM) that demonstrates how to load and unload a module while printing messages to the kernel log. The module prints "Hello, World!" when loaded and "Goodbye, World!" when unloaded.

## Module Information

- **Author**: AZZI Hadjer
- **License**: GPL
- **Description**: A basic example of a Linux kernel module for demonstration purposes.
- **Version**: 0.01

## Prerequisites

- A running Linux system with kernel headers installed.
- `build-essential` and `linux-headers-$(uname -r)` packages.

To install the necessary dependencies on a Debian-based system, run:
   ```bash
  sudo apt update
  sudo apt install build-essential linux-headers-$(uname -r)





# toy-kernel-i386
This repository is my first attempt to implement a toy kernel for IBM-PC compatible with x86_32bit architecture. The kernel is *NIX inspired.


## Current Stage:
Under Development, (early stage)

## Compile & Run
To compile and run this kernel image you need a multiboot compliant bootloader e.g. GRUB. If you are on a linux distro the chances are that GRUB is already installed on your system. To simplify the compilation process a make script now added!

You need to have the following modules installed to be able to run the kernel:
- assembler
- qemu
- xorisso
- grub-mkrescue
- gcc

To compile and run on a virtual machine:

Assuming you are on a Linux Distro:
Run the following commands  
```bash
git clone https://github.com/0xShad3/toy-kernel-i386.git
cd toy-kernel-i386/
chmod +x run.sh
./run.sh
```
### Disclaimers
Just like all software out there this on  will undoubtedly contain bugs also, this might running this on a real machine is dangerous and in extreme conditions may damage your system. **This is a personal project for demonstration purposes only**. If however choose to try this I highly suggest you to use an emulator, I personally use qemu. Further instructions on the Compile & Run section.

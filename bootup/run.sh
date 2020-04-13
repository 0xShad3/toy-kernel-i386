#assemble boot.s file  
as --32 masterboot.S -o ./runfiles/masterboot.o  
  
#compile kernel.c file  
gcc -m32 -c ../src/kernel.c -o ./runfiles/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  
  
#linking the kernel with kernel.o and boot.o files  
ld -m elf_i386 -T linker.ld ./runfiles/kernel.o ./runfiles/masterboot.o -o ./runfiles/Shad3OS.bin -nostdlib


grub-file --is-x86-multiboot ./runfiles/Shad3OS.bin  
  
#building the iso file  
mkdir -p isodir/boot/grub  
cp ./runfiles/Shad3OS.bin isodir/boot/Shad3OS.bin  
cp grub.cfg isodir/boot/grub/grub.cfg  
grub-mkrescue -o ./runfiles/Shad3OS.iso isodir  
  
#run it in qemu  
qemu-system-x86_64 -cdrom ./runfiles/Shad3OS.iso
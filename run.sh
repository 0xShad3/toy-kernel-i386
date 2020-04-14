make
grub-file --is-x86-multiboot Shad3OS.bin  
  
#building the iso file  
mkdir -p isodir/boot/grub  
cp Shad3OS.bin isodir/boot/Shad3OS.bin  
cp grub.cfg isodir/boot/grub/grub.cfg  
grub-mkrescue -o Shad3OS.iso isodir  
  
#run it in qemu  
qemu-system-i386 -cdrom Shad3OS.iso
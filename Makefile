CSRC = $(wildcard src/*.c) $(wildcard src/klibc/*.c)
ASRC = $(wildcard src/*.S) $(wildcard src/klibc/*.S)

OBJ = $(ASRC:.S=.o) $(CSRC:.c=.o)

CC = gcc

CFLAGS = -m32 -Wall -g -nostdinc -fno-builtin -Isrc -Isrc/klibc
ASFLAGS = -m32 -g -nostdinc -fno-builtin -Isrc -Isrc/klibc

BIN = Shad3OS.bin

$(BIN): $(OBJ)
	ld -m elf_i386 -o $@ -T linker.ld  $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) $(BIN)

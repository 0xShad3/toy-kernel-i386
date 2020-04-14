# mutliboot magic number
.set MAGIC, 0x1BADB002


# set flags
.set FLAGS, 0

# set checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# set multiboot enabled
.section .multiboot

# define type to long for the above data
.long MAGIC
.long FLAGS
.long CHECKSUM


# set the stack bottom

stackBottom:

# maximum size of the stack 512 bytes
.skip 512

# stack higher -> lower growth direction

stackTop:

.section .text
.global _start
.type _start, @function

_start:

# set current stack pointer to stackTop

	mov $stackTop, %esp
	call kmain
	cli
# halt loop sets the system in infinite loop
hltLoop:
	hlt
	jmp hltLoop
.size _start, . - _start


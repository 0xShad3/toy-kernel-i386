#include "kernel.h"

static UINT16 VGA_DefaultEntry(unsigned char char_out)
{
	return (UINT16)char_out | (UINT16)WHITE_COLOR << 8;
}


void KERNEL_MAIN()
{
	VGA_BUFFER = (UINT16*)VGA_ADDRESS;

	VGA_BUFFER[0] = VGA_DefaultEntry('H');
	VGA_BUFFER[1] = VGA_DefaultEntry('E');
	VGA_BUFFER[2] = VGA_DefaultEntry('L');
	VGA_BUFFER[3] = VGA_DefaultEntry('L');
	VGA_BUFFER[4] = VGA_DefaultEntry('O');
	VGA_BUFFER[5] = VGA_DefaultEntry('W');
	VGA_BUFFER[6] = VGA_DefaultEntry('O');
	VGA_BUFFER[7] = VGA_DefaultEntry('R');
	VGA_BUFFER[8] = VGA_DefaultEntry('L');
	VGA_BUFFER[9] = VGA_DefaultEntry('D');
	VGA_BUFFER[10] = VGA_DefaultEntry(' ');
	VGA_BUFFER[11] = VGA_DefaultEntry('B');
	VGA_BUFFER[12] = VGA_DefaultEntry('O');
	VGA_BUFFER[13] = VGA_DefaultEntry('O');
	VGA_BUFFER[14] = VGA_DefaultEntry('T');
	VGA_BUFFER[15] = VGA_DefaultEntry(' ');
	VGA_BUFFER[16] = VGA_DefaultEntry('0');
	VGA_BUFFER[17] = VGA_DefaultEntry('X');
	VGA_BUFFER[18] = VGA_DefaultEntry('B');
	VGA_BUFFER[19] = VGA_DefaultEntry('8');
	VGA_BUFFER[20] = VGA_DefaultEntry('0');
	VGA_BUFFER[21] = VGA_DefaultEntry('0');
	VGA_BUFFER[23] = VGA_DefaultEntry(' ');
	VGA_BUFFER[24] = VGA_DefaultEntry('S');
	VGA_BUFFER[25] = VGA_DefaultEntry('H');
	VGA_BUFFER[26] = VGA_DefaultEntry('A');
	VGA_BUFFER[27] = VGA_DefaultEntry('D');
	VGA_BUFFER[28] = VGA_DefaultEntry('3');
	VGA_BUFFER[29] = VGA_DefaultEntry('\'');
	VGA_BUFFER[30] = VGA_DefaultEntry('O');
	VGA_BUFFER[31] = VGA_DefaultEntry('S');
}
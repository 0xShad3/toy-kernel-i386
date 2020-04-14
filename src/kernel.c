#include "stdio.h"
#include "vid.h"
#include "asmops.h"


void kmain()
{
	clear_scr();
	puts("kernel starting up");

	set_front_color(YELLOW);
	puts("<initialization code goes here>");
	set_front_color(LTGRAY);
	puts("hello world!");
}
#include <string.h>
#include "vid.h"
#include "inttypes.h"
#include "asmops.h"

#define CLEAR_CHAR 0x720
/* Set the pointer to the next video memory */
static uint16_t *vmem = (uint16_t *)0xb8000;

uint16_t vmem_char(char c, int32_t fg, uint32_t bg)
{
    return ((uint16_t)(c) | (((uint16_t)(fg)&0xf) << 0x8) | (((uint16_t)(bg)&0xf) << 0xc));
}

void clear_scr(void)
{
    memset16(vmem, (int16_t)CLEAR_CHAR, WIDTH * HEIGHT);
}

void set_char(char c, int x, int y, int fg, int bg)
{
    /* Sets a char to a specific position of the 
        VGAout Buffer so it can be printed    
    */
    vmem[y * WIDTH + x] = vmem_char(c, fg, bg);
}
/* VGA cursor configuration for stdout */
void set_cursor(int x, int y)
{
    uint32_t loc; //bug
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
    {
        loc = 0xFFFF;
    }
    else
    {
        loc = y * WIDTH + x;
    }

    /* tell the vga where we want the cursor by writing to the
       cursor register of the CRTC
    */
    outb(CRTC_CURSOR_LOW, CRTC_ADDR);
    outb(loc, CRTC_DATA);
    outb(CRTC_CURSOR_HIGH, CRTC_DATA);
    outb(loc >> 8, CRTC_DATA);
}

void scroll_scr(void)
{
    memmove(vmem,vmem + WIDTH, WIDTH * (HEIGHT - 1) * 2);
    memset16(vmem + WIDTH * (HEIGHT - 1), CLEAR_CHAR, WIDTH);
}
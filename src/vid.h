#ifndef VID_H_
#define VID_H_

#include <inttypes.h>
/* letter's charachteristics */
#define WIDTH 80
#define HEIGHT 25
/* CRTC Ports */
#define CRTC_ADDR 0x3d4
#define CRTC_DATA 0x3d5
/* CRTC registers */
#define CRTC_CURSOR_HIGH 0xe
#define CRTC_CURSOR_LOW 0xf

/* Basic GCA colors 4bit representation */
enum {
    BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LTGRAY,
	GRAY,
	LTBLUE,
	LTGREEN,
	LTCYAN,
	LTRED,
	LTMAGENTA,
	YELLOW,
	WHITE
};


uint16_t vmem_char(char c, int32_t fg, uint32_t bg);
void clear_scr(void);
void set_char(char c, int x, int y, int fg, int bg);
void set_cursor(int x, int y);
void scroll_scr(void);

#endif
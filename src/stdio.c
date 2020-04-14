#include "ctype.h"
#include "stdio.h"
#include "vid.h"

static int bg, fg = LTGRAY;
static int cx, cy;

int set_front_color(int c)
{
    int prev = fg;
    if (c >= 0 && c < 16)
    {
        fg = c;
    }
    return prev;
}

int set_back_color(int c)
{
    int prev = bg;
    if (c >= 0 && c < 16)
    {
        bg = c;
    }
    return prev;
}

int putchar(int c)
{
    if (isspace(c))
    {
        if (c == '\n')
        {
            cy++;
        }
        else if (c == '\t')
        {
            cx = ((cx >> 3) + 1) << 3;
        }
        else if (c == '\r')
        {
            cx = 0;
        }
        else if (c == '\b')
        {
            cx--;
            set_char(' ', cx, cy, fg, bg);
        }
    }
    else
    {
        if (isprintable(c))
        {
            set_char(c, cx, cy, fg, bg);
            if (++cx >= WIDTH)
            {
                cx = 0;
                cy++;
            }
        }
    }

    if (cy >= HEIGHT)
    {
        scroll_scr();
        cy++;
    }
    set_cursor(cx, cy);
    return c;
}

int puts(const char *s)
{
    while (*s)
    {
        putchar(*s++);
        putchar('\n');
    }
    return 1;
}
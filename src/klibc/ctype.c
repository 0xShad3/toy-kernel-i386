#include "ctype.h"
#include <stdio.h>


int isupper(int chr)
{
    return chr >= 'A' && chr <= 'Z';
}

int islower(int chr)
{
    return chr >= 'a' && chr <= 'z';
}

int isalpha(int chr)
{
    return islower(chr) || isupper(chr);
}

int isalnum(int chr)
{
    return isalpha(chr) || isdigit(chr);
}

int isblank(int chr)
{
    return chr == ' ';
}

int isprintable(int chr)
{
    return chr >= ' ' && chr <= '}';
}

int isspace(int c)
{
	return isblank(c) || c == '\f' || c == '\n' || c == '\r' || c == '\v';
}

int isdigit(int chr)
{
    return chr >= '0' && chr <= '9';
}

int isascii(int chr)
{
    return chr <= 127;
}

int toupper(int chr)
{
    if (islower(chr))
        return chr - ('a' - 'A');
}

int tolower(int chr)
{
    if (isupper(chr))
        return chr + ('a' - 'A');
}



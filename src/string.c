#include "string.h"
#include "inttypes.h"
/*
    Both memsets fill a mem area with a specific value
    given as c
*/
void memset(void *s, int32_t c, size_t n)
{
    int8_t *p = s;
    while (n--)
    {
        *p++ = c;
    }
}

void memset16(void *s, int16_t c, size_t n)
{
    int16_t *p = s;
    while (n--)
    {
        *p++ = c;
    }
}

void *memcpy(void *dest, void *src, size_t n)
{
    // destination ptr
    char *dp = dest;
    // destination ptr
    const char *sp = src;
    while (n--)
    {
        *dp++ = *sp++;
    }
    return dest;
}

void *memmove(void *dest, void *src, size_t n)
{
    char *dp;
    const char *sp;
    if (dest <= src)
    {
        dp = dest;
        sp = src;
        while (n--)
        {
            *dp++ = *sp++;
        }
    }
    else
    {
        dp = dest + n;
        sp = src + n;
        while (n--)
        {
            *--dp = *--sp;
        }
    }
    return dest;
}

// string functions
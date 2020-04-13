#ifndef _STRING_H_
#define _STRING_H_

void memset(void *s, int32_t c, size_t n);
void memset16(void *s, int16_t c, size_t n);
void *memcpy(void *dest, void *src, size_t n);
void *memmove(void *dest, void *src, size_t n);

#endif
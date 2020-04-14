#ifndef ASMOPS_H_
#define ASMOPS_H_


/* 
    According to documentation setting asm blocks to volatile
   has no actual effect it is set by default to volatile
*/
#define inb(dest, port) asm ( \
	"inb %1, %0\n\t" \
	: "=a" ((unsigned char)(dest)) \
	: "dN" ((unsigned short)(port)))

#define ins(dest, port) asm ( \
	"ins %1, %0\n\t" \
	: "=a" ((unsigned short)(dest)) \
	: "dN" ((unsigned short)(port)))

#define inl(dest, port) asm ( \
	"inl %1, %0\n\t" \
	: "=a" ((unsigned long)(dest)) \
	: "dN" ((unsigned short)(port)))

#define outb(src, port) asm ( \
	"outb %0, %1\n\t" \
	:: "a" ((unsigned char)(src)), "dN" ((unsigned short)(port)))

#define outs(src, port) asm ( \
	"outs %0, %1\n\t" \
	:: "a" ((unsigned short)(src)), "dN" ((unsigned short)(port)))

#define outl(src, port) asm ( \
	"outl %0, %1\n\t" \
	:: "a" ((unsigned long)(src)), "dN" ((unsigned short)(port)))

#endif	/* ASMOPS_H_ */

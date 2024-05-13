#ifndef __SYSTEM_H
#define __SYSTEM_H 
#include "stdint.h"
extern void *memcpy(void *dest, const void *src, size_t count);
extern void *memset(void *dest, char val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val,size_t count);
extern size_t strlen(const char *str);
extern unsigned char inb (unsigned short _port);
extern void outb (unsigned short _port, unsigned char _data);
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
extern void idt_install();
struct regs
{
 unsigned int gs, fs, es, ds;
 unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
 unsigned int int_no, err_code;
 unsigned int eip, cs, eflags, useresp, ss;
};
/* ISRS.C */
extern void isrs_install();
/* IRQ.C */
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
extern void irq_uninstall_handler(int irq);
extern void irq_install();
#endif
